
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



















//================================
1010-day log:
{
    

//--------------------------------
2019.11.04 Thursday
    [08:00-10:00] plan;     PID 1/s; cubeMx;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;    
    
//--------------------------------
2019.10.31 Thursday
    [08:00-10:00] plan;     PID 1/s; cubeMx;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;
    
    Updated to newer version of mbsSdk that allows building
    //Support ACS71240 current sensor
        
                //update power status
                //BELOW THRESHOLD -> GENERATOR_MODE
                //ABOVE THRESHOLD -> MOTOR_MODE
                if ( boPowerShresholdTrig )
                {
                    if(powerStatus != thresholdStatus)
                    {
                        powerStatus = thresholdStatus;
                        if (eMonitorState == GENERATOR_MODE)
                        {
                            ; // do nothing, already in generator mode and timeout shall not be extended
                        }
                        else if(bCheckGeneratorMode(powerStatus))
                        {
                            eventTimer->vRequestTimeout(cui32GeneratorTimeOut);
                            vSetState(GENERATOR_MODE);
                        }
                        else
                        {
                            eventTimer->vRequestTimeout(cui32SettleTimeOut);
                            vSetState(WAIT_SETTLE_RELAY_ENERGIZE);
                            boPowerShresholdTrig = false;
                            mbsLogInfo("PowStatus=%d\r", static_cast<int>( powerStatus ));
                        }
                    }
                }
                
    bool MainVoltageMonitorImp::bCheckGeneratorMode(const uint8_t thresholdStatus) const volatile
    {
        bool retval;

        if((eMonitorState == WAIT_SETTLE_RELAY_ENERGIZE) ||
            (messages::SYS_MON_THRES_STATUS_ABOVE_THRESHOLD == thresholdStatus))
        {
            //In Motor mode
            retval = false;
        }
        else
        {
            //In Generator mode
            retval = true;
        }
        return retval;
    }
    
    
    void vEnterEnergizedMode(MainVoltageMonitorImp* mainVoltageMonitor)
    {
        //enter energized mode
        mock().disable();
        mainVoltageMonitor->vSystemEvent(messages::SYSTEM_MONITOR_STATUS_RELAY_ENERGIZED);
        mainVoltageMonitor->vMeasurementEvent(messages::SYS_MON_THRES_ID_MAIN_VOL_THRESHOLD_ID, 1);
        mainVoltageMonitor->vMeasurementEvent(messages::SYS_MON_THRES_ID_MAIN_VOL_UNDERVOL_THRESHOLD_ID, 1);
        mainVoltageMonitor->vMeasurementEvent(messages::SYS_MON_THRES_ID_MAIN_VOL_DIFF_THRESHOLD_ID, 1);
        mainVoltageMonitor->vTimeOut();
        mainVoltageMonitor->vTimeOut();
        //set generator mode
        mainVoltageMonitor->vMeasurementEvent(messages::SYS_MON_THRES_ID_GENERATOR_MODE_THRESHOLD_ID, 0);
        mainVoltageMonitor->vMeasurementEvent(messages::SYS_MON_THRES_ID_GENERATOR_MODE_THRESHOLD_ID, 1);
        mock().enable();
    }
        
//--------------------------------
2019.10.28 Monday
    [08:00-10:00] plan;     PID 1/s; cubeMx;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;
    
shell sh mbsSdk/tools/debug/openocd/bin/killOpenocdWin.sh
target extended | mbsSdk/tools/debug/openocd/bin/Cygwin/openocd -c 'gdb_port pipe' -l _openocd.log -s mbsSdk/tools/debug/openocd/scripts_mbs -s mbsSdk/tools/debug/openocd/scripts_mbs -s mbsSdk/tools/debug/openocd/scripts -f interface/mbs_stlink-v2.cfg -f mcu/stm32f1.cfg -f debug/gdb.cfg -d3
monitor reset init
monitor poll on
source mbsSdk/tools/debug/gdb/gdbInit


根据调研，大部分同事选择 从树山穿越至大阳山森林公园这个线路，并且倾向于周日去。

计划本周日（11月3日）去树山。说明如下：
•	欢迎带家属带孩子 （但最好不要太小的孩子，还是有一定强度的，怕大人搞不定）
•	9：30    树山生态村集合    （导航至 “月敏农家” 树山店，有停车位）
•	9:30 ~ 11:30  栈道漫步 + 爬山  至大阳山森林公园
•	11：30  -  ？？  大阳山野餐  及 游玩
•	游玩后原路返回

活动组将提供矿泉水 （人均2瓶）、野餐食物、餐巾纸、垃圾袋等必要用品。
欢迎大家自带食物分享（自己拿手的菜，或者自家附近好吃的食物）。

请编辑以下link 以便统计，后期有变动没关系。 （统计食物是为了不造成过多浪费）
G:\R&D\2019\Eric Qian\20191103 秋游报名表.xlsx




//--------------------------------
2019.10.23   
    [08:00-10:00] plan;     CAN code; crc;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;

    workflow in JIRA, be-careful!
              
#63    00000 00:00:10.258    Info inputApp inputApp task stack left =28
#64    00000 00:00:10.259    Info inputApp commApp task stack left =69
#65    00000 00:00:10.259    Info inputApp CM-app task stack left =263
#66    00000 00:00:10.260    Info inputApp motionCtrl task stack left =264
#67    00000 00:00:10.261    Info inputApp statistics task stack left =289
#68    00000 00:00:10.261    Info inputApp systemMonitor task stack left =43

#326   00000 00:01:26.258    Info inputApp inputApp task stack left =28
#327   00000 00:01:26.259    Info inputApp commApp task stack left =64
#328   00000 00:01:26.259    Info inputApp CM-app task stack left =216
#329   00000 00:01:26.260    Info inputApp motionCtrl task stack left =264
#330   00000 00:01:26.261    Info inputApp statistics task stack left =289
#331   00000 00:01:26.261    Info inputApp systemMonitor task stack left =43
    
//--------------------------------
2019.10.22   
    [08:00-10:00] plan;     CAN code; crc;  
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;
    
    
    
//--------------------------------
2019.10.21   
    [08:00-10:00] plan;     CAN code; crc;  
    自动化，
    FOC, 
    $ git rebase -i c231c67d --onto sps-314-ioLED 
    $ git reset --hard origin/sps-314-ioLED 
    
    [‎10/‎21/‎2019 4:35 PM] Shmulevich, Michael: 
There are just two isses remain in the review:
- Unit test multiplies pause time (o) by 4
- I can't see where do we fast flash when BLE pairing is ongoing

    
    [10:00-12:00] english;  merge request; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;
    
//--------------------------------
2019.10.18   
    [08:00-10:00] plan;     CAN code; crc;  
    // /SwingDoorPlatform/mbsSdk/components/common/utilities/src/crc8.c 
    // /SwingDoorPlatform/mbsSdk/components/halFunc/can/generic/inc/canDefs.h
    // /SwingDoorPlatform/components/application/aaesGeneric/isoTp/inc/layerIsoTpIfc.h

    [10:00-12:00] english;  code rationale; 
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;
    
    
//--------------------------------
2019.10.17   
    [08:00-10:00] plan;     coding;
    [10:00-12:00] english;  code rationale; 当作拿不回来，心态就很稳定了。
        
    [13:00-15:00] schmaic;  code rationale;
    [15:00-17:00] calc;     FOC code rationale;
}
