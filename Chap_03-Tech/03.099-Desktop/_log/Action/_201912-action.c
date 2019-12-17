
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

    
    12/6 - team building; idea;
    Sweden colleague; PDS-CEO来访，


        
        
//--------------------------------
2019.12.17 Wednesday
    01. Swing Door Platform Code,
    02. English,
    03. Test,
    04. FOC, 
    05. Git use bc3,

        
//--------------------------------
2019.12.16 Monday 请假     
        

//--------------------------------
2019.12.12 Thursday
    [08:00-10:00] plan;      PID 1/s; cubeMx;  
    [10:00-12:00] english;   merge request; 
        
    [13:00-15:00] schematic; code rationale;
    [15:00-17:00] calc;      FOC code rationale;
        
    git config --global core.editor "'C:\mbs\programs\npp.7.6.2.bin\notepad++.exe' -multiInst -notabbar -nosession -noPlugin '$*'"
        
    git config --global difftool.bc3.cmd "'C:\mbs\programs\BCompare3\BCompare.exe' '$LOCAL' '$REMOTE'"

        
    Today I didn't do much. Checked the backlog, didn't find a proper one. 
    Read the updated code in develop branch. CM stack may need to be lower down. Now is 2thousand and 48.
    I also try to Set up git config, make it easy to compare code changes.
    
    
    
    
------    
一、对于逾期偿还按揭贷款月供，各家银行有不同的规定。但一般来说，在按期还款日未能及时偿还月供，都会有三天的宽限期。在宽限期内贷款人偿还月供是不属于违约的。 二：逾期偿还月供的影响： 1、罚息。如果购房按揭贷款人月供逾期    
    
    个人住房贷款还款时间的规定为：
由于我行存量个人住房贷款数量较多，系统扣款时间跨度较大，为避免影响客户信用记录，客户应按照《个人购房担保借款合同》的约定，于每期还款日17:00前存入足以偿还当期借款本息的款项，还款账户内资金不足以清偿当期借款本息的，原则上将作逾期处理,详询贷款行。
举例：如每月20日为合同上约定的还款日，那么客户应该在当月20日17:00之前将当期借款本息的款项存入还款账户中。（若客户在20日将当期借款本息的款项存入还款账户中，且还款时间较晚，则有可能会出现系统不扣款的情况。）
贷款还款后，系统自动在还款日扣款，一般情况下总行在晚上21：00之前关机，关机之后系统不再扣划。
如未能按照贷款合同及时还款，建议与贷款经办行联系确认相关信息。 

-----
农行房贷宽限期，一般是三到五天,最长不超过十天,具体看当地银行的规定了

------
以福建福州为例，农业银行还款是没有期限的。

假设还款日是10号，那么10号当天一到批量扣款时间，系统就会自动进行批量扣款。在扣款时账户余额不足就有可能导致扣款失败，使得房贷逾期。如果没有及时还款，就会出现逾期，很可能就是存款的时间超过银行扣款的时间，扣款账户余额不足导致的。

到了扣款日当天，银行通常采取批量扣款的方式来划转走这笔款项，但每家银行批量扣款的时间却并不一定相同，因此银行普遍建议持卡人在还款日之前，就把款项存入扣款账户。

以农业银行为例，在还款日前几天，银行会发一条短信给客户，提醒x月x日为最后还款日，需要在还款日当天17点前将房贷存入，保障账户余额可被划转。农业银行的房贷批量扣款时间在17:00左右。

如果长期处于逾期状态，银行一般会根据“连三累六”的标准来考核客户的信用记录。所谓“连三累六”，是指逾期还款“连续三个月，累计六次”。假设一个客户房贷连续三个月逾期或者累计逾期六次，如果再申请贷款，银行肯定就会比较慎重。
        
//--------------------------------
2019.12.12 Thursday
    [08:00-10:00] plan;      PID 1/s; cubeMx;  
    [10:00-12:00] english;   merge request; 
        
    [13:00-15:00] schematic; code rationale;
    [15:00-17:00] calc;      FOC code rationale;
    
    share topic,
    max door inertia,
    
    components/application/swingDoorGeneric/learnCalculator/inc/learnCalculator.hpp        
    
    virtual void vSetMaxAllowedDoorInertiaInHgSquareMeter(const int16_t csi16MaxDoorInertia);
    
    BLE test design mode,
    Requirements?, Sounds good,
    Door weight, close speed not OK,
    
    Fw upgrade, ISO-TP, CAN-8bytes. Softhouse ble-app check?
    UL come tomorrow for elect,
    
    First of all, thanks for "older" Michael's comments. I finished the limit of learned maximum door inertia today.
    And I am trying to find a new story in backlog. I'll find a new one.
    That's all.

"Since" the Quasar project is in the sprint phase this year, "There is a lot of" work on this project, and I am embarrassed to "propose" a marriage leave. "According to company regulations", my marriage leave is about to "expire at the end of" December this year. I hereby propose to apply for a one-year extension to the end of 2020. I am looking forward to your approval.

//--------------------------------
2019.12.11 Wednesday
    [08:00-10:00] plan;      PID 1/s; cubeMx;  
    [10:00-12:00] english;   merge request; 
        
    [13:00-15:00] schematic; code rationale;
    [15:00-17:00] calc;      FOC code rationale;
    
    share topic,
    unit tests,
    vocation, //!!!//
    
    Updated unit tests for sps-393-door inertia limit.
    Pushed new commit, and the pipeline passed. Could Miachal take a review when you have time?
        
    
        int32_t si32Offset = 0;
        messagesInternal::MessageHelper::vSetValue(pData, static_cast<int16_t>(ui32ParameterId), si32Offset);
        messagesInternal::MessageHelper::vSetValue(pData, si32Value, si32Offset);
        messagesInternal::MessageHelper::vSetValue(pData, ui8ErrorCode, si32Offset);   
        
        
    int32_t si32Offset = 0;
    messagesInternal::MessageHelper::vSetValue(ui8MessageData, static_cast<int16_t>(si32Id), si32Offset);
    messagesInternal::MessageHelper::vSetValue(ui8MessageData, si32Value, si32Offset);
    messagesInternal::MessageHelper::vSetValue(ui8MessageData, static_cast<int8_t>(0)/*errorCode*/, si32Offset);

    uint8_t* pMessageData = pGetParameterUpdatedMessage(si32Id, si32Value, 0/*errorCode*/);
    delete[] pMessageData;

//--------------------------------
2019.12.10 Tuesday
    [08:00-10:00] plan;      PID 1/s; cubeMx;  
    [10:00-12:00] english;   merge request; 
        
    [13:00-15:00] schematic; code rationale;
    [15:00-17:00] calc;      FOC code rationale;
    
    SPS-393 max door inertia limit, finished the code. Added a interface in learnCommamd. Unit tests not updated. Keep working on it. //revert added parameter change.
    One more thing is I changed door inertia maximum value to 400, the motor board memory need to be erased once.

//--------------------------------
2019.12.09 Monday
    [08:00-10:00] plan;      PID 1/s; cubeMx;  
    [10:00-12:00] english;   merge request; 
        
    [13:00-15:00] schematic; code rationale;
    [15:00-17:00] calc;      FOC code rationale;
    
    //My turn. 
    Today I am still working on sps-400, pushing learn button issue for BLE pairing.
    Updated the merge request comments. Could Michael take a review again?
    
    In the afternoon, I prepared some program flow pictures for UL.
    
    Talk about sps-393-door inertia limit/ation. I would like to do the code 
    to call PARAMETER_GET_DATA with DEFINITION type as Daniel said in email tomorrow.
    
    
    RAM TEST FOR UL, just part of them. My suggestion is. systemMonitor. 
    class B aera, DMA, safety aera,
    How about...
    
    
  @startuml{TorqueLimiterDiagram.png} "TorqueLimiterDiagram"
    (*) -->[every 2ms] "Update Max/Min allowed torque limit" as MaxMinAllowed
    MaxMinAllowed --> "Update low energy torque limit" as LowEnergyTorque
    if "Torque Mode" then
    -->[auto] "Calculate auto \nmode torque limit" as AUTO
    else
    -->[manual] "Calculate manual \nmode torque limit" as MANUAL
    else
    -->[max\npower\nassist] "Calculate max power \nassist torque limit" as MAX_POW
    else
    -->[power\nassist] "Calculate power \nassist torque limit" as POW
    else
    -->[free\nswing] "Calculate free  \nswing torque limit" as FREE
    else
    -->[braking] "Calculate braking  \n torque limit" as BRAKE
    endif
    
    AUTO --> "Request torque compares to Max/Min allowed torque limit,\nGet smaller one as request torque" as SELECT
    MANUAL --> SELECT
    MAX_POW --> SELECT
    POW --> SELECT
    FREE --> SELECT
    BRAKE --> SELECT
    SELECT --> "Request torque compares to low energy torque limit,\nGet smaller one as request torque" as LOW_ENERGY_SELECT
    LOW_ENERGY_SELECT --> "ramp up/down torque limit" as RAMP
    RAMP --> (*)
  @enduml
 
  
  @startuml{ClosingTrajectoryBreakpoints.png} "ClosingTrajectoryBreakpoints"
    (*) --> "Set door open angle"
    --> "Calculate close breakpoints(BP0~6)"
    --> "Check BP3 with minimal latch check time"
    --> [every 2ms] "Update shaft angle" as ShaftAngle

    if "Check shaft Angle" then
    --> [above BP6] "Set door speed above BP6" as ABOVE_BP6
    else
        -right-> [false] if "" then
        --> [above BP5] "Set door speed above BP5" as BP6
        else 
            
            -right-> [false] if "" then
            --> [above BP4] "Set door speed above BP4" as BP5
            else
                -right-> [false] if "" then
                --> [above BP3] "Set door speed above BP3" as BP4
                else
                    -right-> [false] if "" then
                    --> [above BP2] "Set door speed above BP2" as BP3
                    else
                        -right-> [false] if "" then
                        --> [above BP1] "Set door speed above BP1" as BP2
                        else
                            -right-> [false] "Set door speed to zero" as BP1
                        endif
                    endif
                endif
            endif
        endif
    endif
    ABOVE_BP6 --> "Set closing speed" as CLOSE_SPEED
    BP6 --> CLOSE_SPEED
    BP5 --> CLOSE_SPEED
    BP4 --> CLOSE_SPEED
    BP3 --> CLOSE_SPEED
    BP2 --> CLOSE_SPEED
    BP1 --> CLOSE_SPEED
    CLOSE_SPEED --> (*)
  @enduml  
  
    
    //外置光驱借出-Willis；
    
        
//--------------------------------
2019.12.06 Friday
    [08:00-10:00] plan;      PID 1/s; cubeMx;  
    [10:00-12:00] english;   merge request; 
        
    [13:00-15:00] schematic; code rationale;
    [15:00-17:00] calc;      FOC code rationale;
    
    Test order, Send for approve,
    
    Plan-target
    
    Mech+test,
    
    EN16005 seneor test,
    PSPE, ESPE, 
    
    My turn. 
    Today I am still working on sps-400, pushing learn button issue for BLE pairing.
    I updated the unit tests. 
    And pushed a new branch for merge request,
    The pipeline has past.
    
    sps-393 Michael comments, work on it next week.
    That's all from me.
    
    Parameter definations, values, 
    erase, factory reset, 
        

//--------------------------------
2019.12.05 Thursday
    [08:00-10:00] plan;      PID 1/s; cubeMx;  
    [10:00-12:00] english;   merge request; 
        
    [13:00-15:00] schematic; code rationale;
    [15:00-17:00] calc;      FOC code rationale;  
    
    Guarate Low energy.
    
    sps393-disable motor after learned heavyDoorInertia. //message help for transmit message, //payload for just get data.
    
    My turn. First of all, It's about learned heavy door inertia.
    Created a new merge request. Could Michael take a review?
    
    And today, I am working on pushing learn button for BLE pairing issue.(sps-400) 
    Added a new message to send learn command start status in learn mode. It works well for learn.
    Unit tests are still not updated. I'll keep working on it. 
        
        
    FOC, 
    SPS-400,
    公司放假文件，
    提出顺延婚假；
        
//--------------------------------
2019.12.04 Wednesday
    [08:00-10:00] plan;      PID 1/s; cubeMx;  
    [10:00-12:00] english;   merge request; 
        
    [13:00-15:00] schematic; code rationale;
    [15:00-17:00] calc;      FOC code rationale;  
    
    sps393-disable motor after learned heavyDoorInertia. //message help for transmit message, //payload for just get data.
    Updated unit tests, Tested function on real door in lib.
    push new branch, the pipeline failed at ci flash.
    Add new parameter, memory erase.
    
    FOC, 
        
//--------------------------------
2019.12.03 Tuesday
    [08:00-10:00] plan;      PID 1/s; cubeMx;  
    [10:00-12:00] english;   merge request; 
        
    [13:00-15:00] schematic; code rationale;
    [15:00-17:00] calc;      FOC code rationale;  
    
    00. SPS, 
    01. FreeRTOS, oral, 
    02. FOC, 
    03. MBS, 
    04. project,
    
    pc-lint,
    cygwin-python3,
    Ansi 156.19
    
    My turn. First of all, I already set up python3 in cygwin. Copy native execute file-s into cygwin bin folder.
    
    Today I am working on sps-393-, disable motor when learned heavy door inertia.
    I added another paramter to store heavy door inertia limitation.
    Documention and code has been updated. Unit test-s and real door running test are not finished. I'll keep working on it.
    
    //Parameter_6_ID kept, param not used.
   

    
    
//--------------------------------
2019.12.02 Monday
    [08:00-10:00] plan;      PID 1/s; cubeMx;  
    [10:00-12:00] english;   merge request; 
        
    [13:00-15:00] schematic; code rationale;
    [15:00-17:00] calc;      FOC code rationale;  
    
    00. SPS, 
    01. FreeRTOS, oral, 
    02. FOC, 
    03. MBS, 
    04. project,
    
    My turn. I am Updating before learn thing according to comments. 
    //Today is a little strange. I should finish it.
    Today I took some work on prapering unit test pictures for UL. 
    And just finish my branch code. I still need more tests, then push a new commit.
    
    How to set up python3, manual.

}
