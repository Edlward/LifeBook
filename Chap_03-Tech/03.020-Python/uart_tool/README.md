# sci_tool
使用python3.4 + Qt4 + Matplot + pyserial实现串口工具，
早期的串口工具基本上使用VB/VC++/C#等来实现的，感觉到
现在有些落伍了，正好最近对python有些兴趣，学了点基本
语法，就想利用他来实现一个自己的串口工具，而且python
以库多而出名，完全能去找各种库去实现一些有趣的东西，
像使用matplot来画图等

Python使用3.4版本
这个项目实现的主要库:pyqt4/matplot/pyserial/numpy
其他一些关联库，可以使用Pycharm直接搜索：
six/python-dateutil/pyqt-distutils

开发使用的IDE：PyCharm


//package.
1、使用下载安装的方式安装的Pyinstaller打包方式

将需要打包的文件放在解压得到的Pyinstaller文件夹中，打开cmd窗口，把路径切换到当前路径打开命令提示行，输入以下内容（最后的是文件名）：

        python pyinstaller.py -Fw myfile.py

2、使用pip方式安装的Pyinstaller打包方式

打开cmd窗口，把路径切换到文件所在路径(文件随便放在哪里都行)打开命令提示行，输入以下内容（最后的是文件名）：

        pyinstaller -F myfile.py

pyinstaller -F test.py

3、输入参数的含义

    -F 表示生成单个可执行文件
    -w 表示去掉控制台窗口，这在GUI界面时非常有用。不过如果是命令行程序的话那就把这个选项删除吧！
    -p 表示你自己自定义需要加载的类路径，一般情况下用不到
    -i 表示可执行文件的图标

