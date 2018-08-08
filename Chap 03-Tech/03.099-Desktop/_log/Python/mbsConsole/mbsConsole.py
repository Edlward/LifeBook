#!/usr/bin/python

"""
Usage: mbsConsole.py [--port=<serialPort>] [--printBinaryToo]
       mbsConsole.py (-h, --help, --version)

This purpose of this tool is to simplify the use of the MBS Console. It 
communicates over the specified serial port and provides a command shell 
including command history and tab completion.

Options:
     --port=<serialPort>         Serial port to use (COM1, /dev/ttyS0 etc)
     --printBinaryToo            This option will cause binary characters to be printed as well (hex representation)
     -h --help                   Help
     --version                   Version
"""

import os
import sys, traceback


newpath = os.path.realpath(os.path.join( os.path.dirname( os.path.realpath(__file__)), "..","thirdParty"))
sys.path.append( newpath )
newpath = os.path.realpath(os.path.join( os.path.dirname( os.path.realpath(__file__)), "..","mbsTestLibrary"))
sys.path.append( newpath )
try:
    from docopt import docopt
except:
    print "Unable to import Python module \"docopt\". Please install it. More info on www.docopt.org."
    exit(1)
       
try:
    from retrieveSerialPortNumber import retrievePort
except:
    print "Unable to import from retrieveSerialPortNumber."
    exit(1)

from Tkinter import *
import tkMessageBox
import unittest
import serial
import re
import threading
import Queue


OPTION_PRINT_BINARY_CHARACTERS_TOO = False

def charIsPrintable(c):
    try:
        a = c.decode('ascii')
    except UnicodeDecodeError:
        return False
    except UnicodeEncodeError:
        return False
    else:
        return ord(c) > 31 or c == '\n' or c == '\t'
    
def filterOutNonPrintable(str):
    return ''.join([c for c in str if charIsPrintable(c)])

def allCharsArePrintable(str):    
    return all(charIsPrintable(c) for c in str)

def showErrorMessageDialog( self, *args ):
    """ Replacement-function of the global Tk show-exception-function that will show any 
        exceptions that occurs to the user using a pop-up-dialogue""" 
    err = traceback.format_exception(*args)
    tkMessageBox.showerror('Exception', err)

class ConsoleCommands():
    """Holds a list of command names, and their brief and detailed help desctiptions.
       It also provides methods to perform command completion, much like how it works 
       in regular command shells such as bash"""
    def __init__(self, cmds = ["help"]):
        self.commands = cmds
        self.briefDescriptions = {}
        self.detailedDescriptions = {}
    
    def parseHelpText(self, helpText ):    
        self.commands = []
        p = re.compile(r"^[ \t]+(\S+)[ \t\-]+(.*)$", re.MULTILINE )
        for m in p.finditer( helpText ):
            self.commands.append(m.group(1))
            self.briefDescriptions[m.group(1)] = m.group(2).strip()

    def numOfKnownCommands(self):
        return len( self.commands )

    def listCommands(self):
        return self.commands

    def getBriefDescription(self, cmd ):
        if ( cmd in self.briefDescriptions.keys()):
            return self.briefDescriptions[cmd]
        return ""
    
    def getDetailedDescription(self, cmd):
        if ( cmd in self.detailedDescriptions.keys()):
            return self.detailedDescriptions[cmd]
        return ""
    
    def purgeAllDetailedDescriptions(self):
        self.detailedDescriptions = {}
    
    def setDetailedDescription(self, cmd, detailedText):
        matchCr = re.compile('\r', re.MULTILINE)
        matchEmptyLines = re.compile('^[ \t]*\n', re.MULTILINE)
        matchSuccessLine = re.compile('^SUCCESS.*?\n', re.MULTILINE)
        matchEchoLine = re.compile('\w*  > .*?\n', re.MULTILINE)
        detailedText = re.sub( matchCr,'', detailedText, re.MULTILINE)
        detailedText = re.sub( matchSuccessLine,'', detailedText, re.MULTILINE)
        detailedText = re.sub( matchEchoLine,'', detailedText, re.MULTILINE)
        detailedText = re.sub( matchEmptyLines,'', detailedText, re.MULTILINE)
        detailedTextLines = detailedText.split('\n')
        first8Lines = '\n'.join(detailedTextLines[0:8])
        self.detailedDescriptions[cmd]= first8Lines.strip()
    
    def isKnownCommand(self, cmd):
        return cmd.strip() in self.commands
            
    def searchCommands(self, startingWith ):
        res = [ cmd for cmd in self.commands if cmd.upper().startswith( startingWith.upper()) ]
        return res

    def autoCompleteAsLongAsObvious(self, startingWith ):
        cmds = self.searchCommands(startingWith)
        numOfAlternatives = len( cmds )
        if ( numOfAlternatives == 1 ):
            return cmds[0] + " "
        elif ( numOfAlternatives == 0 ):
            return startingWith
        else :
            currentStart = startingWith
            i = len( currentStart )
            remaining = cmds
            nextCommon = startingWith
            while ( ( i < len( cmds[0]) ) and ( len ( remaining ) == numOfAlternatives) ):
                nextCommon += cmds[0][i]
                remaining = [ cmd for cmd in cmds if cmd.upper().startswith( nextCommon.upper()) ]
                if ( len (remaining ) == numOfAlternatives ):
                    currentStart = nextCommon
                i+=1
            return currentStart

        
class CommandHistory():
    """Responsible for holding a record of the last executed commands and a way to recall 
       previous commands. Much like regular command shells e.g. bash"""
    def __init__(self):
        self.history = []
        self.currentIndex = 0
    
    def saveCommand(self, cmd):
        if ( len( self.history ) == 0 or ( cmd != self.history[-1] ) ):
            self.history.append(cmd)
        self.currentIndex = len( self.history )
    
    def getPrevious(self):
        if ( len( self.history ) > 0 ):
            if ( self.currentIndex >= 1 ) :
                self.currentIndex -= 1
            cmd = self.history[self.currentIndex]
            return cmd 
        return ""

    def getNext(self):
        if ( len( self.history ) > 0 ):
            if ( self.currentIndex + 1 <= len( self.history ) ):
                self.currentIndex += 1
                if ( self.currentIndex < len( self.history)):
                    return self.history[self.currentIndex]
        return ""

class CustomText(Text):
    '''A text widget with a new method, HighlightPattern 

    example:

    text = CustomText()
    text.tag_configure("red",foreground="#ff0000")
    text.HighlightPattern("this should be red", "red")

    The HighlightPattern method is a simplified python 
    version of the tcl code at http://wiki.tcl.tk/3246
    '''
    def __init__(self, *args, **kwargs):
        Text.__init__(self, *args, **kwargs)

    def HighlightPattern(self, pattern, tag, start="1.0", end="end"):
        '''Apply the given tag to all text that matches the given pattern'''

        start = self.index(start)
        end = self.index(end)
        self.mark_set("matchStart",start)
        self.mark_set("matchEnd",start)
        self.mark_set("searchLimit", end)

        count = IntVar()
        while True:
            index = self.search(pattern, "matchEnd","searchLimit",count=count, regexp=True)
            if index == "": break
            self.mark_set("matchStart", index)
            self.mark_set("matchEnd", "%s+%sc" % (index,count.get()))
            self.tag_add(tag, "matchStart","matchEnd")
            
class MbsConsoleWindow():
    ''' The main application window that holds a number of different widgets. 
    '''
    def __init__(self, master, cs, pollReadCommand=None, writeCommand=None ):
        self.pollReadCommand=pollReadCommand
        self.writeCommand=writeCommand
        self.cs = cs
        self.history = CommandHistory()
        self.master = master
        self.frame = Frame( master )
        self.scrollbar = Scrollbar( master )
        self.mainText = CustomText( master, wrap=CHAR, bd=0, width=128, height=50, takefocus=0,background="white",yscrollcommand=self.scrollbar.set, state=DISABLED)
        self.scrollbar.config(command=self.mainText.yview)
        self.commandLine = Entry(master, width=80 )
        self.statusLineContent = StringVar()
        self.statusLine = Label( master, textvariable=self.statusLineContent, width=100, relief=SUNKEN, background="grey" )
        self.updateHelpButton = Button( master, text="Refresh knowledge of existing console commands", command=self._updateHelp )
        self.cleanBufferButton = Button( master, text="Clean buffer", command=self._cleanBuffer )
        
        self.frame.pack()
        self.statusLine.pack( fill=X,  side=BOTTOM)
        self.commandLine.pack( fill=X, side=BOTTOM)
        self.updateHelpButton.pack( )
        self.cleanBufferButton.pack( )
        self.scrollbar.pack( fill=Y,  side=RIGHT)
        self.mainText.pack( fill=BOTH, expand=1, side=TOP)
        
        self.commandLine.focus_set()

        # Define 'tags' that can be used to highlight different text
        self.mainText.tag_config("sent",    foreground="grey")
        self.mainText.tag_config("recv",    foreground="black")
        self.mainText.tag_config("alert",   foreground="red")
        self.mainText.tag_config("error",   foreground="red")
        self.mainText.tag_config("assert",  foreground="red")
        self.mainText.tag_config("success", foreground="green")
        self.mainText.tag_config("fail",    foreground="red")
        self.mainText.tag_config("error",   foreground="red")
        self.mainText.tag_config("warning", foreground="orange" )
        self.mainText.tag_config("notice",  foreground="magenta2")
        self.mainText.tag_config("info",    foreground="blue")
        self.mainText.tag_config("debug",   foreground="dodger blue")
        self.mainText.tag_config("binary",  foreground="royal blue")

        self.saveCopyOfInputTextUntilSuccess = 0
        self.saveCopyOfInputTextForCmd = ""
        self._updateTextPeriodically()
        self._displayAllCommandsOnStatusBar()
    
        self.commandLine.bind_all( "<KeyPress-Tab>", self._tryCompleteCommand )
        self.commandLine.bind_all( "<KeyPress-Return>", self._executeCommand )
        self.commandLine.bind_all( "<Control-KeyPress-space>", self._tryCompleteCommand )
        self.commandLine.bind_all( "<KeyPress-Up>", self._onKeypressUp)
        self.commandLine.bind_all( "<KeyPress-Down>", self._onKeypressDown)
        self.commandLine.bind_all( "<KeyPress-space>", self._onKeypressSpace)
        self.commandLine.bind_all('<Control-c>', self._copy)
        self.commandLine.bind_all('<Control-v>', self._paste)

        self._updateHelp()

    def _copy(self, event=None):
        self.mainText.clipboard_clear()
        text = self.mainText.get("sel.first", "sel.last")
        self.mainText.clipboard_append(text)
    
    def _paste(self, event):
        text = self.mainText.selection_get(selection='CLIPBOARD')
        self.__setCommandLine( text )

    def _updateDetailedHelp(self, cmd):
        self.newHelpResponse = ""
        self.saveCopyOfInputTextForCmd = cmd
        if ( self.writeCommand != None ):
            self.writeCommand( "help %s\n" % cmd )
            
    def _continueUpdateDetailedHelp(self, newText):
        if (self.saveCopyOfInputTextForCmd):
            self.newHelpResponse += newText
            if ( "SUCCESS" in self.newHelpResponse ):
                self.cs.setDetailedDescription(self.saveCopyOfInputTextForCmd, self.newHelpResponse)
                self.saveCopyOfInputTextForCmd = ""
                self._lookUpCommandDescriptionAndPrintToStatusLine()

    def _updateHelp(self, cmd="help\n"):
        self.newHelpResponse = ""
        self.saveCopyOfInputTextUntilSuccess = 1
        self._printTextToMainWindow("Executed \"help\"\n", "sent")
        if ( self.writeCommand != None ):
            self.writeCommand( cmd )
        
    def _cleanBuffer(self ):
        self.mainText.config(state=NORMAL)
        self.mainText.delete(1.0,END)
        self.mainText.config(state=DISABLED)

    def _continueUpdateHelp(self, newText):
        if (self.saveCopyOfInputTextUntilSuccess):
            self.newHelpResponse += newText
            if ( "SUCCESS" in self.newHelpResponse ):
                self.cs.purgeAllDetailedDescriptions()
                self.saveCopyOfInputTextUntilSuccess = 0
                self.cs.parseHelpText(self.newHelpResponse)
                self.statusLineContent.set( "Found %d commands from help\n%s" % ( self.cs.numOfKnownCommands(), str(self.cs.listCommands()) ))

    def _displayAllCommandsOnStatusBar(self):
        self.statusLineContent.set( self.cs.listCommands() )
        
    def _printTextToMainWindow(self, text, category):
        self.mainText.config(state=NORMAL)
        i = self.mainText.index(CURRENT)
        for c in text:
            if ( charIsPrintable(c) ):
                self.mainText.insert(END, c, category)
            elif ( OPTION_PRINT_BINARY_CHARACTERS_TOO ):
                self.mainText.insert(END, "<0x%02x>" % ord(c), "binary")
        self.mainText.see(END)
        self.mainText.HighlightPattern("^ *>? *SUCCESS", "success", start=i)
        self.mainText.HighlightPattern("## Assert.*", "assert", start=i)
        self.mainText.HighlightPattern("^ *>? *FAIL.*", "fail", start=i)
        self.mainText.HighlightPattern("^ *>? *ERROR.*", "error", start=i)
        self.mainText.HighlightPattern("^ *>? *#[ 0-9:\.]*Alert.*",   "alert",   start=i )
        self.mainText.HighlightPattern("^ *>? *#[ 0-9:\.]*Error.*",   "error",   start=i )
        self.mainText.HighlightPattern("^ *>? *#[ 0-9:\.]*Warning.*", "warning",start=i )
        self.mainText.HighlightPattern("^ *>? *#[ 0-9:\.]*Notice.*",  "notice",  start=i )
        self.mainText.HighlightPattern("^ *>? *#[ 0-9:\.]*Info.*",    "info",  start=i )
        self.mainText.HighlightPattern("^ *>? *#[ 0-9:\.]*Debug.*",   "debug",  start=i ) 
        self.mainText.config(state=DISABLED)

    def _updateTextPeriodically(self):
        if ( self.pollReadCommand != None ):
            newText = self.pollReadCommand()
            while newText:
                self._printTextToMainWindow(newText, "recv")
                self._continueUpdateHelp(newText)
                self._continueUpdateDetailedHelp(newText)
                newText = self.pollReadCommand()
        self.mainText.after(300, self._updateTextPeriodically)

    def _executeCommand(self, event):
        cmd = self.commandLine.get()
        if ( not allCharsArePrintable(cmd) ):
            self.statusLineContent.set( "ERROR in command, Not ASCII: " + cmd )
            self._printTextToMainWindow( "ERROR in command, Not ASCII \n", 'sent')            
        else:
            self.statusLineContent.set( "Execute " + cmd )
            if cmd:
                self.history.saveCommand( cmd )
            self._printTextToMainWindow("Executed \""+cmd+"\""+"\n", "sent")
            if ( self.writeCommand != None ):
                self.writeCommand( self.commandLine.get() + '\n')
        self.commandLine.delete(0,END)
        
    def _onKeypressUp(self, event):
        self.__setCommandLine(self.history.getPrevious())
        
    def _onKeypressDown(self, event):
        self.__setCommandLine(self.history.getNext())

    def _getFirstWordOnCommandLine(self):
        s = self.commandLine.get()
        words = s.split()
        if ( len( words ) > 0 ):
            return words[0]
        return ""

    def _lookUpCommandDescriptionAndPrintToStatusLine(self):
        firstWord = self._getFirstWordOnCommandLine()
        detailedHelpText = self.cs.getDetailedDescription(firstWord)
        isKnownCmd = self.cs.isKnownCommand(firstWord)
        if ( isKnownCmd and not detailedHelpText ):
            self._updateDetailedHelp(firstWord)
        cmdHelp = "%s\n%s" % (self.cs.getBriefDescription(firstWord), detailedHelpText )
        self.statusLineContent.set(cmdHelp)

    def _onKeypressSpace(self, event):
        self._lookUpCommandDescriptionAndPrintToStatusLine()

    def _tryCompleteCommand(self, event):
        s = self.commandLine.get()
        autoComplete = self.cs.autoCompleteAsLongAsObvious(s)
        self.__setCommandLine(autoComplete)

        matches = self.cs.searchCommands(s.strip())
        if ( len( matches ) == 1 ):
            self._lookUpCommandDescriptionAndPrintToStatusLine()
        else:
           self.statusLineContent.set( matches )

    def __setCommandLine(self, text):        
        self.commandLine.delete(0,END)
        self.commandLine.insert(0,text)

class MbsConsoleConnection(threading.Thread):
    ''' This class defines a connection to the console over a serial line. 
        It uses a thread to read from the serial port, and
        the write() and readLine() commands can be used e.g. by the
        MbsConsoleWindow.
    '''
    def __init__(self, port=0):
        self.requestedPort = port
        threading.Thread.__init__(self)
        self.deamon = True
        self._openConnection(port)
        self.readLineResult = ""
    
    def _openConnection(self, port=0):
        self.ser = serial.Serial(port, 115200, timeout=2 )
        self.queue = Queue.Queue()
        self.running = 1
        self.start()
        
    def closeConnection(self):
        self.running = 0
        self.join()
        self.ser.close()
        
    def write(self, msg):       
        self.ser.write( msg )

    def readLine(self):
        foundLineEnd = False
        while self.queue.qsize() and not foundLineEnd:
            try:
                char = self.queue.get(block=False)
                self.readLineResult += char
                foundLineEnd = char == '\n'
            except Queue.Empty:
                pass
        if foundLineEnd:
            line = self.readLineResult
            self.readLineResult = ""
            return line
        else:
            return ""
    
    def getPortName(self):
        s = ""
        try :
            s = self.ser.name
        except :
            s = self.requestedPort
        return s
        
    def run(self):
        # Thread body executed afer start() is called when obj initiated
        while self.running:
            s = self.ser.read()
            if s :
                self.queue.put( s )

if __name__ == "__main__":
    args = docopt( __doc__, version = '0.2.1' )
    if ( args['--printBinaryToo']):
        OPTION_PRINT_BINARY_CHARACTERS_TOO = True
    try:
        root = Tk()
        Tk.report_callback_exception = showErrorMessageDialog;

        port = retrievePort()
        if (0 == port):
            print ("Could not retrieve port number automatically")
            if ( args[ '--port' ]):
			    connection = MbsConsoleConnection( args[ '--port' ] )
            else:
                tkMessageBox.showerror("Error", "Give the serial port number as argument when opening the console" )
        else:
            print ("Opening retrieved port number", port)
            connection = MbsConsoleConnection( port )
        cs = ConsoleCommands()
        root.title("MBS - Console : " + connection.getPortName())
        m = MbsConsoleWindow(root, cs, connection.readLine, connection.write)
        root.mainloop()
        connection.closeConnection()
    except serial.SerialException:
        tkMessageBox.showerror("Unable to open serial port", args[ '--port' ] )
        exit(1)
