#" -*- coding: utf-8 -*-"
__author__ = 'jerry.hua'
__name__ = '__main__'

### imports.
from PyQt4 import QtCore, QtGui
from matplotlib.figure import *
from matplotlib.backends.backend_qt4agg import FigureCanvasQTAgg as FigureCanvas
import numpy as np
import re

import sys, struct, sci_tool, serial, time, threading

### defines.
#数据位
SERIAL_DATABIT_ARRAY = (serial.EIGHTBITS, serial.SEVENBITS, serial.SIXBITS, serial.FIVEBITS)
#停止位
SERIAL_STOPBIT_ARRAY = (serial.STOPBITS_ONE, serial.STOPBITS_ONE_POINT_FIVE, serial.STOPBITS_TWO)
#校验位
SERIAL_CHECKBIT_ARRAY = (serial.PARITY_NONE, serial.PARITY_EVEN, serial.PARITY_ODD , serial.PARITY_MARK, serial.PARITY_SPACE)

### matplot class.
class MplCanvas(FigureCanvas):
    def __init__(self):
        self.fig = Figure()
        self.ax = self.fig.add_subplot(111)
        self.fig.subplots_adjust(left=0.06, right=0.99, top=0.9, bottom=0.1)
        #self.fig.subplots_adjust(left=0.01, right=0.99, top=0.99, bottom=0.01) #0.01 = 1%
        #self.fig.subplots_adjust(left=0.002, right=0.998, top=0.998, bottom=0.002) #0.01 = 1%
        FigureCanvas.__init__(self, self.fig)
        FigureCanvas.setSizePolicy(self, QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Expanding)
        FigureCanvas.updateGeometry(self)
        self.databuflimit = 50000
        self.line1, = self.ax.plot([], [], color='blue')
        self.plotdatabuf = []
        self.ax.grid()
        self.ax.hold(False)

    def matplot_updatabuf(self, newdata):
        if len(self.plotdatabuf) >= self.databuflimit:
            del self.plotdatabuf[0]
            try:
                self.plotdatabuf[self.databuflimit] = newdata
            except:
                self.plotdatabuf.append(newdata)
        else:
            self.plotdatabuf.append(newdata)

### ui class.
class Sci_UiCtl(sci_tool.Ui_MainWindow):
    def __init__(self, MainWindow):
        super(sci_tool.Ui_MainWindow, self).__init__()
        self.__index = 0
        self.setupUi(MainWindow)#display sci tool menu

        self.portstatus_flag = False#端口使能标志
        self._serial = serial.Serial()#init serial class

        #将按键单击操作和对应的函数关联起来，这个是Qt里的写法
        self.sciopenButton.connect(self.sciopenButton, QtCore.SIGNAL('clicked()'), self.SciOpenButton_Click)#connect button click func
        self.clrcontentbutton.connect(self.clrcontentbutton, QtCore.SIGNAL('clicked()'), self.ClrButtonProcess)
        self.mainsend_Button.connect(self.mainsend_Button, QtCore.SIGNAL('clicked()'), self.MainSendButtonProcess)
        self.sendclr_Button.connect(self.sendclr_Button, QtCore.SIGNAL('clicked()'), self.ClrSendButtonProcess)
        self.clrcntbutton.connect(self.clrcntbutton, QtCore.SIGNAL('clicked()'), self.ClrCntButtonProcess )
        self.cmd1sned_Button.connect(self.cmd1sned_Button, QtCore.SIGNAL('clicked()'), self.Cmd1SendButtonProcess)
        self.cmd2sned_Button.connect(self.cmd2sned_Button, QtCore.SIGNAL('clicked()'), self.Cmd2SendButtonProcess)
        self.cmd3sned_Button.connect(self.cmd3sned_Button, QtCore.SIGNAL('clicked()'), self.Cmd3SendButtonProcess)
        # self.cmd4sned_Button.connect(self.cmd4sned_Button, QtCore.SIGNAL('clicked()'), self.Cmd4SendButtonProcess)
        # self.cmd5sned_Button.connect(self.cmd5sned_Button, QtCore.SIGNAL('clicked()'), self.Cmd5SendButtonProcess)
        self.savecontentbutton.connect(self.savecontentbutton, QtCore.SIGNAL('clicked()'), self.SaveRecButtonProcess)
        self.x1save_button.connect(self.x1save_button, QtCore.SIGNAL('clicked()'), self.X1SaveButtonProcess)
        self.x1clr_button.connect(self.x1clr_button,  QtCore.SIGNAL('clicked()'), self.X1ClrButtonProcess)
        #self.x2save_button.connect(self.x2save_button, QtCore.SIGNAL('clicked()'), self.X2SaveButtonProcess)
        #self.x2clr_button.connect(self.x2clr_button,  QtCore.SIGNAL('clicked()'), self.X2ClrButtonProcess)
        #self.x3save_button.connect(self.x3save_button, QtCore.SIGNAL('clicked()'), self.X3SaveButtonProcess)
        #self.x3clr_button.connect(self.x3clr_button,  QtCore.SIGNAL('clicked()'), self.X3ClrButtonProcess)
        self.plotnum_Slider.valueChanged.connect(self.PlotNumValueChange)

        #用来实现波形的显示，画图
        self.matplot = MplCanvas()
        self.debug_matplot_layout.addWidget(self.matplot)
        self.matplot.databuflimit = self.plotnum_Slider.value()#得到plot的初始化最大值

        self.RecStr = str#串口接收字符串
        self.RecDataCnt = 0#数据接收计数
        self.SendDataCnt = 0#数据发送计数

        #用定时器每隔一定时间去扫描有没数据收到，只在打开串口才开始
        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.SciReadData)

    #打开串口操作
    def SciOpenButton_Click(self):
         clickstatus = self.sciopenButton.isChecked()
         if clickstatus:
            #得到串口的设置参数
            ComRead = int(self.portcomtext.text())-1
            BaudRate = int(self.baudratecombo.currentText())
            DataBit = SERIAL_DATABIT_ARRAY[self.databitcombo.currentIndex()]
            StopBit = SERIAL_STOPBIT_ARRAY[self.stopbitcombo.currentIndex()]
            CheckBit = SERIAL_CHECKBIT_ARRAY[self.checkbitcombo.currentIndex()]

            #打开串口
            try:
                self._serial = serial.Serial(ComRead)
                self._serial.baudrate = BaudRate
                self._serial.bytesize = DataBit
                self._serial.parity = CheckBit
                self._serial.StopBits = StopBit
            except (OSError, serial.SerialException):
                QtGui.QMessageBox.warning(None, 'warning', "port not exist", QtGui.QMessageBox.Ok)

            if self._serial.isOpen():#打开串口后失效一些可以设置的窗口
                self.timer.start(50)#30ms刷新一次界面
                self.sciopenButton.setText("Close")
                self.baudratecombo.setEnabled(False)
                self.checkbitcombo.setEnabled(False)
                self.databitcombo.setEnabled(False)
                self.stopbitcombo.setEnabled(False)
                self.portcomtext.setEnabled(False)
                self.portstatus_flag = True
                self.SciOpenDebugDataMenuDeal()
            else:
                self.sciopenButton.setChecked(False)
         else:#关闭串口
            self._serial.close()
            self.timer.stop()
            self.sciopenButton.setText("Open")
            self.baudratecombo.setEnabled(True)
            self.stopbitcombo.setEnabled(True)
            self.databitcombo.setEnabled(True)
            self.checkbitcombo.setEnabled(True)
            self.portcomtext.setEnabled(True)
            self.portstatus_flag = False
            self.SciCloseDebugDataMenuDeal()

    #对填写的数据做判断，看是否有问题
    def SciOpenDebugDataMenuDeal(self):
        if self.x1_checkBox.isChecked() == True:
            try:
                self.x1_low = float(self.x1_low_line.text())
                self.x1_high = float(self.x1_high_line.text())
                if self.x1_low > self.x1_high:
                     QtGui.QMessageBox.warning(None, '错误', "X1填写数据出错", QtGui.QMessageBox.Ok)
                     self.x1_checkBox.setChecked(False)
            except :
                 QtGui.QMessageBox.warning(None, '错误', "X1填写数据出错", QtGui.QMessageBox.Ok)
                 self.x1_checkBox.setChecked(False)

        self.x1_checkBox.setEnabled(False)
        self.x1_low_line.setEnabled(False)
        self.x1_high_line.setEnabled(False)
        #self.x2_checkBox.setEnabled(False)
        #self.x2_low_line.setEnabled(False)
        #self.x2_high_line.setEnabled(False)
        #self.x3_checkBox.setEnabled(False)
        #self.x3_low_line.setEnabled(False)
        #self.x3_high_line.setEnabled(False)

    def SciCloseDebugDataMenuDeal(self):
        self.x1_checkBox.setEnabled(True)
        self.x1_low_line.setEnabled(True)
        self.x1_high_line.setEnabled(True)
        #self.x2_checkBox.setEnabled(True)
        #self.x2_low_line.setEnabled(True)
        #self.x2_high_line.setEnabled(True)
        #self.x3_checkBox.setEnabled(True)
        #self.x3_low_line.setEnabled(True)
        #self.x3_high_line.setEnabled(True)

    def ClrButtonProcess(self):#接收窗口清数据
        if self.distext.currentIndex() == 0:
            self.dishex.clear()
        elif self.distext.currentIndex() == 1:
            self.distring.clear()
        else:
            self.disprotocol.clear()

    def ClrSendButtonProcess(self):#清除发送窗口数据
        self.mainsend_Edit.clear()
        self.cmd1_Edit.clear()
        self.cmd2_Edit.clear()
        self.cmd3_Edit.clear()

    def ClrCntButtonProcess(self):#清计算窗口
        self.SendDataCnt = 0
        self.RecDataCnt = 0
        self.sendnum_lineEdit.setText(str(self.SendDataCnt))
        self.RecNumLineEdit.setText(str(self.RecDataCnt))

    def HexShow(self,strargv):#转换陈十六进制格式显示
        restr = ''
        slen = len(strargv)
        for i in range(slen):
            restr = restr + hex(strargv[i]) + ' '
        return restr

    def SerialSend(self, sdata):
        try:
            self.SendDataCnt += self._serial.write(sdata)
        except:
             QtGui.QMessageBox.warning(None, 'Error', "数据格式错误", QtGui.QMessageBox.Ok)

        self.sendnum_lineEdit.setText(str(self.SendDataCnt))


    def MainSendButtonProcess(self):
        if self.portstatus_flag == True:
            if self.char_radioButton.isChecked():
                self.SerialSend(self.mainsend_Edit.toPlainText().encode())
            else:
                sendstr = self.mainsend_Edit.toPlainText()
                try:
                    self.SerialSend(bytearray.fromhex( sendstr.replace('0x', '')))
                except:
                    QtGui.QMessageBox.warning(None, 'Error', "数据格式错误", QtGui.QMessageBox.Ok)


    def Cmd1SendButtonProcess(self):
        if self.portstatus_flag == True:
            sendstr = self.cmd1_Edit.text()
            try:
                self.SerialSend(bytearray.fromhex( sendstr.replace('0x', '')))
            except:
                QtGui.QMessageBox.warning(None, 'Error', "数据格式错误", QtGui.QMessageBox.Ok)

    def Cmd2SendButtonProcess(self):
        if self.portstatus_flag == True:
            sendstr = self.cmd2_Edit.text()
            try:
                self.SerialSend(bytearray.fromhex( sendstr.replace('0x', '')))
            except:
                QtGui.QMessageBox.warning(None, 'Error', "数据格式错误", QtGui.QMessageBox.Ok)

    def Cmd3SendButtonProcess(self):
        if self.portstatus_flag == True:
            sendstr = self.cmd3_Edit.text()
            try:
                self.SerialSend(bytearray.fromhex( sendstr.replace('0x', '')))
            except:
                QtGui.QMessageBox.warning(None, 'Error', "数据格式错误", QtGui.QMessageBox.Ok)

    def SaveRecButtonProcess(self):
        filename = QtGui.QFileDialog.getSaveFileName(self.savecontentbutton, 'Save File', '.', "Text file(*.txt);;All file(*.*)")
        fname = open(filename, 'w')
        if self.distext.currentIndex() == 0:
            fname.write(self.dishex.toPlainText())
        elif self.distext.currentIndex() == 1:
            fname.write(self.distring.toPlainText())
        elif  self.distext.currentIndex() == 2:
             fname.write(self.disprotocol.toPlainText())

        fname.close()

    #数据的区分
    def DebugDataSelecDeal(self, p_str):
        rec_array = re.split('\n|,| |\r|\r\n', p_str)#将数据按各种符号去分隔，得到需要的数据
        datacount = 0
        lastdigital = 0
        for num in rec_array:
            try:
                #readdigital = float(num)
                readdigital = int(num)
            except:
                continue

            if self.x1_checkBox.isChecked() == True:
                if readdigital >= self.x1_low and readdigital < self.x1_high:
                    ## data.
                    if datacount == 0: #first data set to 0.
                        readdigital = 0
                    else: # count >= 1
                        if readdigital == 0:
                            #readdigital = lastdigital #update with last data.
                            readdigital = readdigital #not change data.
                        else: # data != 0
                            lastdigital = readdigital #update last data.

                    ## display.
                    if datacount == 0:
                        self.x1_plainTextEdit.appendPlainText(str(round(readdigital, 70)))
                        if self.x1selec_radio.isChecked() == True:
                            self.matplot.matplot_updatabuf(readdigital)
                    else:
                        if readdigital != 0:
                            self.x1_plainTextEdit.appendPlainText(str(round(readdigital, 70)))
                            if self.x1selec_radio.isChecked() == True:
                                self.matplot.matplot_updatabuf(readdigital)

                    if self.x1_plainTextEdit.toPlainText().__len__() > 50000:
                        self.x1_plainTextEdit.clear()
                    datacount = datacount + 1

        #判断是否刷新画图区域
        if self.x1selec_radio.isChecked() == True:
            self.Multiplot_Refresh()

    def X1ClrButtonProcess(self):
        self.x1_plainTextEdit.clear()

    def X1SaveButtonProcess(self):
        filename = QtGui.QFileDialog.getSaveFileName(self.x1save_button, 'Save File', '.', "Text file(*.txt);;All file(*.*)")
        fname = open(filename, 'w')
        fname.write(self.x1_plainTextEdit.toPlainText())
        fname.close()

    def X2ClrButtonProcess(self):
        self.x2_plainTextEdit.clear()

    def X2SaveButtonProcess(self):
        filename = QtGui.QFileDialog.getSaveFileName(self.x2save_button, 'Save File', '.', "Text file(*.txt);;All file(*.*)")
        fname = open(filename, 'w')
        fname.write(self.x2_plainTextEdit.toPlainText())
        fname.close()

    def X3ClrButtonProcess(self):
        self.x3_plainTextEdit.clear()

    def X3SaveButtonProcess(self):
        filename = QtGui.QFileDialog.getSaveFileName(self.x3save_button, 'Save File', '.', "Text file(*.txt);;All file(*.*)")
        fname = open(filename, 'w')
        fname.write(self.x3_plainTextEdit.toPlainText())
        fname.close()

    def HexMatplotDisplay(self,p_str):
        for num in p_str:
            self.matplot.matplot_updatabuf(num)
        self.Multiplot_Refresh()

    def Multiplot_Refresh(self):
        if len(self.matplot.plotdatabuf) < self.matplot.databuflimit:
            self.matplot.line1.set_xdata(np.arange(len(self.matplot.plotdatabuf)))
            self.matplot.line1.set_ydata(self.matplot.plotdatabuf)
        else:
            self.matplot.line1.set_xdata(np.arange(self.matplot.databuflimit))
            self.matplot.line1.set_ydata(self.matplot.plotdatabuf[:self.matplot.databuflimit])
        #更新数据后去刷新matplot界面
        self.matplot.ax.relim()
        self.matplot.ax.autoscale_view()
        self.matplot.draw()

    def PlotNumValueChange(self):
        self.plotnum_lineEdit.setText(str(self.plotnum_Slider.value()))
        self.matplot.databuflimit = self.plotnum_Slider.value()

    #comm port 数据接收
    def SciReadData(self):#deal sci data
        if self.portstatus_flag == True:
            try:
                bytesToRead = self._serial.inWaiting()#读取缓冲区有多少数据
            except:
                self.sciopenButton.setChecked(False)#出现异常，则关闭串口
                self.SciOpenButton_Click()
                bytesToRead = 0

            if bytesToRead > 0:#大于0 ，则取出数据
                self.RecStr = self._serial.read(bytesToRead)#读取串口数据
                self.RecDataCnt += bytesToRead
                self.RecNumLineEdit.setText(str(self.RecDataCnt))
                self.SciWinReFresh()#根据选择，来判断数据在那个窗口刷新

    def SciWinReFresh(self):
        if self.debugtab.currentIndex() == 1:
            self.dishex.appendPlainText(self.HexShow(self.RecStr)) #把数据按十六进制显示
            if self.hexselec_radio.isChecked() == True:
                self.HexMatplotDisplay(self.RecStr)
            if self.dishex.toPlainText().__len__() > 50000:
                self.dishex.clear()
        elif self.debugtab.currentIndex() == 0:
            self.distring.appendPlainText(self.RecStr.decode("utf-8")) #String display.
            if self.x1_checkBox.isChecked():
                self.DebugDataSelecDeal(self.RecStr.decode("utf-8"))
            if self.distring.toPlainText().__len__() > 50000:
                self.distring.clear()
        else:
            pass

### main app.
if __name__ == '__main__':
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Sci_UiCtl(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())