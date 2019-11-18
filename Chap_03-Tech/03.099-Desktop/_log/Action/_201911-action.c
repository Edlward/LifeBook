
//================================
1009-time log:
{
    [08:00-10:00] plan;     coding;
    [10:00-12:00] english;  code rationale;
    
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     code rationale;
    
    
    
    [08:00-10:00] 计划;     代码;
    [10:00-12:00] 英语;     设计;
    
    [13:00-15:00] 硬件;     调试;
    [15:00-17:00] 学习;     代码;
}

Carson: 2019.0615.












Plan, then no emergency.


//================================
1010-day log:
{
    bootloader,
    mbsSdk,
    datasheet,
    cubeMx,

    

    
//--------------------------------
2019.11.18 Monday
    [08:00-10:00] plan;     PID 1/s; cubeMx;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;  
    
    01. FreeRTOS,
    02. FOC, 
    03. MBS,
    04. project,
    
    
//--------------------------------
2019.11.15 Friday
    [08:00-10:00] plan;     PID 1/s; cubeMx;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;  
    
    01. 实习生，
    02. 小组负责研发项目，
    03. 下下周11.25 PDS-CEO来访， BLE demo.
    04. Slider PM change.
    
    SPL= 适配器:: 图纸，标签，料号，样品确认，计划，公司流程process，繁琐而计划，挑战，
    PowerBox= CP+CMs, 更改，供应商，BOM， checklist；
    FlatScan= 更换物件，连接板，cable，连接方式，描述文件-报告，问题-方法；
    挑-通；
    CAN通信， python QT界面， 
    认证，销售，销量，VAVE.
    

//--------------------------------
2019.11.13 Wednesday
    [08:00-10:00] plan;     PID 1/s; cubeMx;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;   
    
    HAL_TIM_Base_Start_IT( &htim3 );
    
    void HAL_TIM_PeriodElapsedCallback( TIM_HandleTypeDef *htim )
{
    if( htim->Instance == htim3.Instance )
    {
        HAL_GPIO_TogglePin( LED_STATUS_GPIO_Port, LED_STATUS_Pin );
    }
}


shell sh C:\mbs\SwingDoorPlatform\mbsSdk/tools/debug/openocd/bin/killOpenocdWin.sh
target extended | C:/mbs/SwingDoorPlatform/mbsSdk/tools/debug/openocd/bin/Cygwin/openocd -c 'gdb_port pipe' -l _openocd.log -s C:/mbs/SwingDoorPlatform/mbsSdk/tools/debug/openocd/scripts_mbs -s C:/mbs/SwingDoorPlatform/mbsSdk/tools/debug/openocd/scripts_mbs -s C:/mbs/SwingDoorPlatform/mbsSdk/tools/debug/openocd/scripts -f interface/mbs_stlink-v2.cfg -f mcu/stm32f1.cfg -f debug/gdb.cfg -d3 source C:/mbs/SwingDoorPlatform/mbsSdk/tools/debug/gdb/gdbInit
    
#52    00000 00:01:32.321    Info vUpdateMeasurement :Threshold 8, status=0.
#53    00000 00:01:32.325    Info vUpdateMeasurement :Threshold 8, status=1.
#54    00000 00:01:32.335    Info mbsStorageLogOpen open logs
#55    00000 00:01:32.339    Info vUpdateMeasurement :Threshold 7, status=1.
#56    00000 00:01:32.349    Info vUpdateMeasurement :Threshold 5, status=0.
#57    00000 00:01:33.321    Info vTimeOut :MonitorState = 4.
#58    00000 00:01:33.321    Info vTimeOut :DC=1, 1.
#59    00000 00:01:34.321    Info vTimeOut :MonitorState = 5.
#60    00000 00:01:34.321    Info vTimeOut :diffV=1.
#61    00000 00:01:39.321    Info mbsStorageLogOpen open logs
    ----------------------------
        
        #59    00000 00:01:01.321    Info vSetState :MonitorState=1.
#60    00000 00:01:01.327    Info mbsStorageLogOpen open logs
#61    00000 00:01:01.335    Info vUpdateMeasurement :Threshold 7, status=1.
#62    00000 00:01:01.345    Info vUpdateMeasurement :Threshold 5, status=0.
#63    00000 00:01:02.321    Info vTimeOut :MonitorState = 1.
#64    00000 00:01:02.321    Info vSetState :MonitorState=2.
#65    00000 00:01:03.321    Info vTimeOut :MonitorState = 2.
#66    00000 00:01:03.321    Info vTimeOut :DC=1, 1, 0; CtrlDC=0, 0.
#67    00000 00:01:03.329    Info vSetState :MonitorState=3.
#68    00000 00:01:08.321    Info vSetState :MonitorState=4.
=========================================
>>> Out of sequence or lost log record(s)
=========================================
#70    00000 00:01:08.329    Info vUpdateMeasurement :Threshold 5, status=1.
#71    00000 00:01:08.333    Info vUpdateMeasurement :Threshold 7, status=0.
=========================================
>>> Out of sequence or lost log record(s)
=========================================
#69    00000 00:01:08.327    Info mbsStorageLogOpen open logs
=========================================
>>> Out of sequence or lost log record(s)
=========================================
#72    00000 00:01:09.321    Info vTimeOut :MonitorState = 4.
#73    00000 00:01:09.321    Info vTimeOut :DC=1, 1.
#74    00000 00:01:09.321    Info vSetState :MonitorState=5.
#75    00000 00:01:10.323    Info vTimeOut :MonitorState = 5.
#76    00000 00:01:10.323    Info vTimeOut :diffV=0.
#77    00000 00:01:10.323    Info vSetState :MonitorState=6.
#78    00000 00:01:52.321    Info vSetState :MonitorState=1.
#79    00000 00:01:52.327    Info mbsStorageLogOpen open logs
#80    00000 00:01:52.336    Info vUpdateMeasurement :Threshold 7, status=1.
#81    00000 00:01:52.345    Info vUpdateMeasurement :Threshold 5, status=0.
#82    00000 00:01:53.321    Info vTimeOut :MonitorState = 1.
#83    00000 00:01:53.321    Info vSetState :MonitorState=2.
#84    00000 00:01:54.321    Info vTimeOut :MonitorState = 2.
#85    00000 00:01:54.321    Info vTimeOut :DC=1, 1, 0; CtrlDC=0, 0.
#86    00000 00:01:54.326    Info vSetState :MonitorState=3.
#87    00000 00:01:59.323    Info vSetState :MonitorState=4.
=========================================
>>> Out of sequence or lost log record(s)
=========================================
#89    00000 00:01:59.329    Info vUpdateMeasurement :Threshold 5, status=1.
#90    00000 00:01:59.333    Info vUpdateMeasurement :Threshold 7, status=0.
=========================================
>>> Out of sequence or lost log record(s)
=========================================
#88    00000 00:01:59.351    Info mbsStorageLogOpen open logs

## Assert failed at LR 0x802E437, task systemMonitor

===========================
MBS logging to UART started
#0     00000 00:00:00.000    Info ecLogResetStatus Last cause of reset: Pin reset
#1     00000 00:00:00.000    Info ecLogResetStatus Last cause of reset: Software reset
#2     00000 00:00:00.000    Info SYS_CTRL build-id Len:20 Data:0x4a8aa366f6593bc990184e67d0597fdf3935563e
#3     00000 00:00:00.000 Warning Error from previous run ## Assert failed at LR 0x802E437, task systemMonitor
#4     00000 00:00:00.004    Info initGlobals Globals initialized
#5     00000 00:00:00.004    Info initGlobals Product FW Version: 0.0.1-595a1919a9d5d286ae7680d878abf53e4166f810-dirty
#6     00000 00:00:00.052    Info readParameterDefinition Reading parameter 0 result: 0
#7     00000 00:00:00.057    Info readParameterDefinition Reading parameter 1 result: 0
#8     00000 00:00:00.062    Info readParameterDefinition Reading parameter 2 result: 0
#9     00000 00:00:00.067    Info readParameterDefinition Reading parameter 3 result: 0
#10    00000 00:00:00.072    Info readParameterDefinition Reading parameter 4 result: 0
#11    00000 00:00:00.077    Info readParameterDefinition Reading parameter 5 result: 0
#12    00000 00:00:00.082    Info readParameterDefinition Reading parameter 7 result: 0
#13    00000 00:00:00.087    Info readParameterDefinition Reading parameter 8 result: 0
#14    00000 00:00:00.100    Info readParameterDefinition Reading parameter 9 result: 0
#15    00000 00:00:00.104    Info readParameterDefinition Reading parameter 10 result: 0
#16    00000 00:00:00.109    Info readParameterDefinition Reading parameter 11 result: 0
#17    00000 00:00:00.114    Info readParameterDefinition Reading parameter 12 result: 0
#18    00000 00:00:00.119    Info readParameterDefinition Reading parameter 13 result: 0
#19    00000 00:00:00.124    Info readParameterDefinition Reading parameter 14 result: 0
#20    00000 00:00:00.129    Info readParameterDefinition Reading parameter 15 result: 0
#21    00000 00:00:00.134    Info readParameterDefinition Reading parameter 16 result: 0
#22    00000 00:00:00.139    Info readParameterDefinition Reading parameter 17 result: 0
#23    00000 00:00:00.152    Info readParameterDefinition Reading parameter 18 result: 0
#24    00000 00:00:00.157    Info readParameterDefinition Reading parameter 19 result: 0
#25    00000 00:00:00.162    Info readParameterDefinition Reading parameter 20 result: 0
#26    00000 00:00:00.167    Info readParameterDefinition Reading parameter 21 result: 0
#27    00000 00:00:00.171    Info readParameterDefinition Reading parameter 22 result: 0
#28    00000 00:00:00.176    Info readParameterDefinition Reading parameter 23 result: 0
#29    00000 00:00:00.181    Info readParameterDefinition Reading parameter 24 result: 0
#30    00000 00:00:00.186    Info readParameterDefinition Reading parameter 25 result: 0
#31    00000 00:00:00.191    Info readParameterDefinition Reading parameter 26 result: 0
#32    00000 00:00:00.199    Info readParameterDefinition Reading parameter 27 result: 0
#33    00000 00:00:00.202    Info mbsStorageBlockFlashInitContext Log limit: 100, erasable areas: 4
#34    00000 00:00:00.271    Info mbsStorageLogOpen open logs
#35    00000 00:00:00.275    Info configurationManagerApp doorControl task started
#36    00000 00:00:00.279    Info inputApp input task started
#37    00000 00:00:00.279    Info motionControlApp motionControl task started
#38    00000 00:00:00.280    Info systemMonitorApp systemMonitorApp task started
#39    00000 00:00:00.281    Info vSetState :MonitorState=1.
#40    00000 00:00:00.284    Info statisticsAndLogApp statisticsAndLog task started
MBS Console online, type help for a list of available commands

> #41    00000 00:00:02.282    Info vUpdateMeasurement :Threshold 2, status=1.
#42    00000 00:00:02.282    Info vUpdateMeasurement :Threshold 4, status=1.
#43    00000 00:00:02.285    Info vUpdateMeasurement :Threshold 7, status=1.
#44    00000 00:00:02.290    Info vUpdateMeasurement :Threshold 8, status=1.
#45    00000 00:00:03.278    Info vTimeOut :MonitorState = 1.
#46    00000 00:00:03.278    Info vSetState :MonitorState=2.
#47    00000 00:00:04.278    Info vTimeOut :MonitorState = 2.
#48    00000 00:00:04.278    Info vTimeOut :DC=1, 1, 0; CtrlDC=0, 0.
#49    00000 00:00:04.284    Info vSetState :MonitorState=3.
#50    00000 00:00:04.294    Info vSetState :MonitorState=4.
#51    00000 00:00:04.298    Info vUpdateMeasurement :Threshold 5, status=1.
#52    00000 00:00:04.300    Info vUpdateMeasurement :Threshold 7, status=0.
#53    00000 00:00:05.294    Info vTimeOut :MonitorState = 4.
#54    00000 00:00:05.294    Info vTimeOut :DC=1, 1.
#55    00000 00:00:05.294    Info vSetState :MonitorState=5.
#56    00000 00:00:06.294    Info vTimeOut :MonitorState = 5.
#57    00000 00:00:06.294    Info vTimeOut :diffV=0.
#58    00000 00:00:06.294    Info vSetState :MonitorState=6.
---------------------------
    
    #44    00000 00:00:03.278    Info vTimeOut :MonitorState = 1.
#45    00000 00:00:04.278    Info vTimeOut :MonitorState = 2.
#46    00000 00:00:04.282    Info vTimeOut :DC=1, 1, 0; CtrlDC=0, 0.
#47    00000 00:00:04.286    Info vSystemEvent :MonitorState=4.
#48    00000 00:00:04.294    Info vUpdateMeasurement :Threshold 5, status=1.
#49    00000 00:00:04.301    Info vUpdateMeasurement :Threshold 7, status=0.
#50    00000 00:00:05.286    Info vTimeOut :MonitorState = 4.
#51    00000 00:00:05.286    Info vTimeOut :DC=1, 1.
#52    00000 00:00:06.286    Info vTimeOut :MonitorState = 5.
#53    00000 00:00:06.286    Info vTimeOut :diffV=0.
#54    00000 00:00:46.324    Info vSystemEvent :MonitorState=1.
#55    00000 00:00:46.330    Info mbsStorageLogOpen open logs
#56    00000 00:00:46.338    Info vUpdateMeasurement :Threshold 7, status=1.
#57    00000 00:00:46.348    Info vUpdateMeasurement :Threshold 5, status=0.
#58    00000 00:00:47.324    Info vTimeOut :MonitorState = 1.
#59    00000 00:00:48.324    Info vTimeOut :MonitorState = 2.
#60    00000 00:00:48.324    Info vTimeOut :DC=1, 1, 0; CtrlDC=0, 0.
#61    00000 00:00:53.326    Info vSystemEvent :MonitorState=4.
#62    00000 00:00:53.332    Info vUpdateMeasurement :Threshold 5, status=1.
#63    00000 00:00:53.338    Info vUpdateMeasurement :Threshold 7, status=0.
#64    00000 00:00:53.346    Info mbsStorageLogOpen open logs
#65    00000 00:00:54.324    Info vTimeOut :MonitorState = 4.
#66    00000 00:00:54.324    Info vTimeOut :DC=1, 1.
#67    00000 00:00:55.324    Info vTimeOut :MonitorState = 5.
#68    00000 00:00:55.324    Info vTimeOut :diffV=0.
#69    00000 00:01:18.324    Info vSystemEvent :MonitorState=1.
#70    00000 00:01:18.330    Info mbsStorageLogOpen open logs
#71    00000 00:01:18.338    Info vUpdateMeasurement :Threshold 7, status=1.
#72    00000 00:01:18.348    Info vUpdateMeasurement :Threshold 5, status=0.
#73    00000 00:01:19.324    Info vTimeOut :MonitorState = 1.
#74    00000 00:01:20.324    Info vTimeOut :MonitorState = 2.
#75    00000 00:01:20.324    Info vTimeOut :DC=1, 1, 0; CtrlDC=0, 0.
#76    00000 00:01:25.326    Info vSystemEvent :MonitorState=4.
#77    00000 00:01:25.332    Info vUpdateMeasurement :Threshold 5, status=1.
#78    00000 00:01:25.338    Info vUpdateMeasurement :Threshold 7, status=0.
#79    00000 00:01:25.346    Info mbsStorageLogOpen open logs
#80    00000 00:01:26.324    Info vTimeOut :MonitorState = 4.
#81    00000 00:01:26.324    Info vTimeOut :DC=1, 1.
#82    00000 00:01:27.324    Info vTimeOut :MonitorState = 5.
#83    00000 00:01:27.324    Info vTimeOut :diffV=0.
#84    00000 00:01:45.324    Info vSystemEvent :MonitorState=1.
#85    00000 00:01:45.330    Info mbsStorageLogOpen open logs
#86    00000 00:01:45.338    Info vUpdateMeasurement :Threshold 7, status=1.
#87    00000 00:01:45.348    Info vUpdateMeasurement :Threshold 5, status=0.
#88    00000 00:01:46.324    Info vTimeOut :MonitorState = 1.
#89    00000 00:01:47.324    Info vTimeOut :MonitorState = 2.
#90    00000 00:01:47.324    Info vTimeOut :DC=1, 1, 0; CtrlDC=0, 0.
#91    00000 00:01:52.326    Info vSystemEvent :MonitorState=4.
=========================================
>>> Out of sequence or lost log record(s)
=========================================
#93    00000 00:01:52.332    Info vUpdateMeasurement :Threshold 5, status=1.
#94    00000 00:01:52.336    Info vUpdateMeasurement :Threshold 7, status=0.
=========================================
>>> Out of sequence or lost log record(s)
=========================================
#92    00000 00:01:52.352    Info mbsStorageLogOpen open logs
=========================================
>>> Out of sequence or lost log record(s)
=========================================
#95    00000 00:01:53.324    Info vTimeOut :MonitorState = 4.
#96    00000 00:01:53.324    Info vTimeOut :DC=1, 1.
#97    00000 00:01:54.324    Info vTimeOut :MonitorState = 5.
#98    00000 00:01:54.324    Info vTimeOut :diffV=0.
#99    00000 00:02:15.324    Info vSystemEvent :MonitorState=1.
#100   00000 00:02:15.330    Info mbsStorageLogOpen open logs
#101   00000 00:02:15.338    Info vUpdateMeasurement :Threshold 7, status=1.
#102   00000 00:02:15.348    Info vUpdateMeasurement :Threshold 5, status=0.
#103   00000 00:02:16.324    Info vTimeOut :MonitorState = 1.
#104   00000 00:02:17.324    Info vTimeOut :MonitorState = 2.
#105   00000 00:02:17.324    Info vTimeOut :DC=1, 1, 0; CtrlDC=0, 0.
#106   00000 00:02:23.326    Info vSystemEvent :MonitorState=4.
#107   00000 00:02:23.332    Info vUpdateMeasurement :Threshold 5, status=1.
#108   00000 00:02:23.338    Info vUpdateMeasurement :Threshold 7, status=0.
#109   00000 00:02:23.346    Info mbsStorageLogOpen open logs
#110   00000 00:02:23.370    Info vUpdateMeasurement :Threshold 8, status=0.
#111   00000 00:02:23.396    Info vUpdateMeasurement :Threshold 8, status=1.
#112   00000 00:02:24.324    Info vTimeOut :MonitorState = 4.
#113   00000 00:02:24.324    Info vTimeOut :DC=1, 1.
#114   00000 00:02:25.324    Info vTimeOut :MonitorState = 5.
#115   00000 00:02:25.324    Info vTimeOut :diffV=0.
#116   00000 00:02:52.324    Info vSystemEvent :MonitorState=1.
#117   00000 00:02:52.330    Info mbsStorageLogOpen open logs
#118   00000 00:02:52.339    Info vUpdateMeasurement :Threshold 7, status=1.
#119   00000 00:02:52.348    Info vUpdateMeasurement :Threshold 5, status=0.
#120   00000 00:02:53.324    Info vTimeOut :MonitorState = 1.
#121   00000 00:02:54.324    Info vTimeOut :MonitorState = 2.
#122   00000 00:02:54.324    Info vTimeOut :DC=1, 1, 0; CtrlDC=0, 0.
#123   00000 00:03:01.326    Info vSystemEvent :MonitorState=4.
#124   00000 00:03:01.352    Info mbsStorageLogOpen open logs
#125   00000 00:03:01.332    Info vUpdateMeasurement :Threshold 5, status=1.
#126   00000 00:03:01.334    Info vUpdateMeasurement :Threshold 7, status=0.
#127   00000 00:03:01.372    Info vUpdateMeasurement :Threshold 8, status=0.
#128   00000 00:03:01.384    Info vUpdateMeasurement :Threshold 8, status=1.
#129   00000 00:03:01.386    Info vUpdateMeasurement :Threshold 8, status=0.
#130   00000 00:03:01.388    Info vUpdateMeasurement :Threshold 8, status=1.
#131   00000 00:03:02.324    Info vTimeOut :MonitorState = 4.
#132   00000 00:03:02.324    Info vTimeOut :DC=1, 1.
#133   00000 00:03:03.324    Info vTimeOut :MonitorState = 5.
#134   00000 00:03:03.324    Info vTimeOut :diffV=0.

--------------------

    }    
    
//--------------------------------
2019.11.11 Wednesday
    [08:00-10:00] plan;     PID 1/s; cubeMx;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale; 
    
    
    ErrorMessage impulse signal,
    FreeRTOS,
    Motor,
    mbsSdk,
    PLC, stm32, cubeMx,
    
    Stock,
   
    
    
//--------------------------------
2019.11.07 Thursday
    [08:00-10:00] plan;     PID 1/s; cubeMx;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;
    
  The state machine of main voltage difference error is described as below

  @startuml{mainVoltageDiffErrorState.png} "mainVoltageDiffErrorState"
  state mainVoltageAbsDiffAboveLimit {
    [*] --> sDURING: belowGeneratorLimit
    state "DURING_GENERATOR_/\nMODE_TIMING" as sDURING
    state "WAIT_GENERATOR_/\nMODE_TIME_OUT" as sWAIT
    state "AFTER_GENERATOR_/\nMODE_TIME_OUT" as sAFTER
    state "WAIT_DIFF_ERROR_/\nTIME_OUT" as sERROR
    sWAIT: request diff \n error timer
    sERROR: send diff \n error message
    sDURING--> sAFTER: generator \n mode \n timeout
    sDURING--> sWAIT: mainVoltage\n AbsDiff \n AboveLimit
    sWAIT--> sERROR: diff error \n timeout
    sAFTER--> sERROR: mainVoltage \nAbsDiffAboveLimit, \nrequest error timer,\n\n diff error timeout
  }
  mainVoltageAbsDiffAboveLimit--> NO_LARGE_DIFF : mainVoltageAbsDiff\nBelowLimit
  NO_LARGE_DIFF --> [*]
  sERROR--> [*]
  @enduml
  
//--------------------------------
2019.11.06 Wednesday
    [08:00-10:00] plan;     PID 1/s; cubeMx;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;
    
    bootloader,
    mbsSdk,
    datasheet,
    cubeMx,
    
#124   00000 00:00:01.928    Info tCheckCrc32 Flash test failed, expected 0xa5a5a5a5, but got 0x50f132d1
#125   00000 00:00:01.948    Info tCheckCrc32 Flash test failed, expected 0xa5a5a5a5, but got 0x50f132d1
#126   00000 00:00:01.968    Info tCheckCrc32 Flash test failed, expected 0xa5a5a5a5, but got 0x50f132d1
    
//--------------------------------
2019.11.04 Thursday
    [08:00-10:00] plan;     PID 1/s; cubeMx;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;
    
    sps-generator mode  pass pipeline;
    test error report,
    test state machine,
    
#39    00000 00:00:24.298    Info inputApp MainV=30381
#40    00000 00:00:24.298    Info inputApp Volt1=15958
#41    00000 00:00:24.299    Info inputApp Volt2=13105
#42    00000 00:00:24.299    Info inputApp Amp-1=912
#43    00000 00:00:24.299    Info inputApp Power=-2601

#44    00000 00:00:24.318    Info inputApp MainV=30992
#45    00000 00:00:24.318    Info inputApp Volt1=16501
#46    00000 00:00:24.319    Info inputApp Volt2=13255
#47    00000 00:00:24.319    Info inputApp Amp-1=796
#48    00000 00:00:24.319    Info inputApp Power=-2583

#49    00000 00:00:24.338    Info inputApp MainV=31820
#50    00000 00:00:24.338    Info inputApp Volt1=16664
#51    00000 00:00:24.339    Info inputApp Volt2=13812
#52    00000 00:00:24.339    Info inputApp Amp-1=845
#53    00000 00:00:24.339    Info inputApp Power=-2409

#54    00000 00:00:24.358    Info inputApp MainV=32676
#55    00000 00:00:24.358    Info inputApp Volt1=16596
#56    00000 00:00:24.359    Info inputApp Volt2=14572
#57    00000 00:00:24.359    Info inputApp Amp-1=894
#58    00000 00:00:24.359    Info inputApp Power=-1809

#59    00000 00:00:24.378    Info inputApp MainV=33342
#60    00000 00:00:24.378    Info inputApp Volt1=17234
#61    00000 00:00:24.379    Info inputApp Volt2=14613
#62    00000 00:00:24.379    Info inputApp Amp-1=747
#63    00000 00:00:24.379    Info inputApp Power=-1957

#64    00000 00:00:24.398    Info inputApp MainV=33953
#65    00000 00:00:24.398    Info inputApp Volt1=17750
#66    00000 00:00:24.399    Info inputApp Volt2=14722
#67    00000 00:00:24.399    Info inputApp Amp-1=741
#68    00000 00:00:24.399    Info inputApp Power=-2243

#69    00000 00:00:24.418    Info inputApp MainV=34754
#70    00000 00:00:24.418    Info inputApp Volt1=18239
#71    00000 00:00:24.419    Info inputApp Volt2=14953
#72    00000 00:00:24.419    Info inputApp Amp-1=833
#73    00000 00:00:24.419    Info inputApp Power=-2737

#74    00000 00:00:24.438    Info inputApp MainV=35596
#75    00000 00:00:24.438    Info inputApp Volt1=18782
#76    00000 00:00:24.439    Info inputApp Volt2=15251
#77    00000 00:00:24.439    Info inputApp Amp-1=796
#78    00000 00:00:24.439    Info inputApp Power=-2810

#79    00000 00:00:24.458    Info inputApp MainV=36397
#80    00000 00:00:24.458    Info inputApp Volt1=18837
#81    00000 00:00:24.459    Info inputApp Volt2=15917
#82    00000 00:00:24.459    Info inputApp Amp-1=888
#83    00000 00:00:24.459    Info inputApp Power=-2592

#84    00000 00:00:24.478    Info inputApp MainV=36995
#85    00000 00:00:24.478    Info inputApp Volt1=19285
#86    00000 00:00:24.479    Info inputApp Volt2=16148
#87    00000 00:00:24.479    Info inputApp Amp-1=656
#88    00000 00:00:24.479    Info inputApp Power=-2057

#89    00000 00:00:24.498    Info inputApp MainV=37796
#90    00000 00:00:24.498    Info inputApp Volt1=19733
#91    00000 00:00:24.499    Info inputApp Volt2=16433
#92    00000 00:00:24.499    Info inputApp Amp-1=766
#93    00000 00:00:24.499    Info inputApp Power=-2527

#94    00000 00:00:24.518    Info inputApp MainV=38652
#95    00000 00:00:24.518    Info inputApp Volt1=19815
#96    00000 00:00:24.519    Info inputApp Volt2=17071
#97    00000 00:00:24.519    Info inputApp Amp-1=869
#98    00000 00:00:24.519    Info inputApp Power=-2384

#99    00000 00:00:24.538    Info inputApp MainV=38543
#100   00000 00:00:24.538    Info inputApp Volt1=20181
#101   00000 00:00:24.539    Info inputApp Volt2=16677
#102   00000 00:00:24.539    Info inputApp Amp-1=747
#103   00000 00:00:24.539    Info inputApp Power=-2617

#104   00000 00:00:24.558    Info inputApp MainV=38530
#105   00000 00:00:24.558    Info inputApp Volt1=20195
#106   00000 00:00:24.559    Info inputApp Volt2=16691
#107   00000 00:00:24.559    Info inputApp Amp-1=845
#108   00000 00:00:24.559    Info inputApp Power=-2960

#109   00000 00:00:24.578    Info inputApp MainV=38611
#110   00000 00:00:24.578    Info inputApp Volt1=20426
#111   00000 00:00:24.579    Info inputApp Volt2=16514
#112   00000 00:00:24.579    Info inputApp Amp-1=717
#113   00000 00:00:24.579    Info inputApp Power=-2804

#114   00000 00:00:24.598    Info inputApp MainV=38611
#115   00000 00:00:24.598    Info inputApp Volt1=20426
#116   00000 00:00:24.599    Info inputApp Volt2=16582
#117   00000 00:00:24.599    Info inputApp Amp-1=729
#118   00000 00:00:24.599    Info inputApp Power=-2802

#119   00000 00:00:24.618    Info inputApp MainV=38856
#120   00000 00:00:24.618    Info inputApp Volt1=20276
#121   00000 00:00:24.619    Info inputApp Volt2=16854
#122   00000 00:00:24.619    Info inputApp Amp-1=863
#123   00000 00:00:24.619    Info inputApp Power=-2953



#117   00000 00:02:57.028    Info vCheckGeneratorMode Generator thre=1
#118   00000 00:02:57.028    Info vCheckGeneratorMode Power=-9511

#119   00000 00:02:57.034    Info vCheckGeneratorMode Generator thre=0
#120   00000 00:02:57.034    Info vCheckGeneratorMode Power=-13371

#121   00000 00:02:57.050    Info vCheckGeneratorMode Generator thre=1
#122   00000 00:02:57.050    Info vCheckGeneratorMode Power=-9483

#123   00000 00:02:57.064    Info vCheckGeneratorMode Generator thre=0
#124   00000 00:02:57.064    Info vCheckGeneratorMode Power=-10973

#125   00000 00:02:57.066    Info vCheckGeneratorMode Generator thre=1
#126   00000 00:02:57.066    Info vCheckGeneratorMode Power=-8727

#127   00000 00:02:57.070    Info vCheckGeneratorMode Generator thre=0
#128   00000 00:02:57.070    Info vCheckGeneratorMode Power=-10147

#129   00000 00:02:57.084    Info vCheckGeneratorMode Generator thre=1
#130   00000 00:02:57.088    Info vCheckGeneratorMode Power=-12228

#131   00000 00:02:57.088    Info vCheckGeneratorMode Generator thre=0
#132   00000 00:02:57.088    Info vCheckGeneratorMode Power=-11128

#133   00000 00:02:57.092    Info vCheckGeneratorMode Generator thre=1
#134   00000 00:02:57.092    Info vCheckGeneratorMode Power=-9011

#135   00000 00:02:57.094    Info vCheckGeneratorMode Generator thre=0
#136   00000 00:02:57.094    Info vCheckGeneratorMode Power=-11201

#137   00000 00:02:57.114    Info vCheckGeneratorMode Generator thre=1
#138   00000 00:02:57.114    Info vCheckGeneratorMode Power=-9506




}
