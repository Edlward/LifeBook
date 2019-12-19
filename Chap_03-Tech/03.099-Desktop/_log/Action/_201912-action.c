
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
2019.12.19 Thursday
    01. Swing Door Platform Code,
    02. English,
    03. Test,
    04. FOC, 
    05. Git use bc3,  
    
    Today I am still working on SPS-4-19 parameter value class.
    The design of parameter value class has been merged.
    Next step is implement.
    
转发：
我们部门要招一个测试工程师，偏向于软件，系统测试的。
有没有什么资源，看看周围朋友谁愿意来的

Common Duties and Responsibilities 岗位职责:
	Design the system test specification and system test plan
制定系统测试说明书，系统测试计划
	Executing test cases, detect bug issues, reporting and verifying.
执行测试用例，进行Bug 报告和验证。
	Developing and making automated testing systems and  test equipment based on specifications.
基于测试要求开发制作自动化测试系统和测试设备。
	Follow established procedures and guidelines to perform routine laboratory procedures to test the quality or function of raw materials, in- process products, and finished products. 
按照实验室既定程序和测试要求进行原材料，半成品和成品进行质量或功能测试。
	Perform daily administration and routine maintenance and safety checks on laboratory equipment to ensure it is in good working order. 
执行实验室设备的日常管理，例行维护和安全检查，确保设备工作正常。
	Provide technical support to production 。
为生产供技术支持。
Competency 任职要求:
	5 years of experience in Software Testing or similar role.
5年以上软件测试或相关的工作经验
	Excellent knowledge in testing skills (design test plan and test strategy, writing test cases, executing test cases, opening bugs, verifying bugs)
丰富的测试知识和技能，包括制定测试计划，测试策略，编写测试用例，执行测试用例，Bug 确认和报告。
	Be able to use English fluently as working language
能流利地使用英语作为工作语言
	Be able to operate lab instruments
熟练操作实验室仪器
	Knowledge of industry safety standards
具备工业安全标准知识
	Knowledge of programming systems like LabView or similar；Be able to write test program.
有编程的知识，如LabView或类似的；能编写测试程序
	Knowledge of communication interfaces with National boards or similar
具有和主板通信接口的知识
	Normally Reports To: Lab leader
汇报对象：实验室组长
	Minimum Qualifications: Bachelor (Degree)
本科或以上学历
	Graduation in computer science or  electronic engineering
计算机或电子工程专业

    
        
//--------------------------------
2019.12.18 Wednesday
    01. Swing Door Platform Code,
    02. English,
    03. Test,
    04. FOC, 
    05. Git use bc3,
    
    Today I am still working on parameter va`lid立得体ity(SPS-4-19). 
    Updated some interfaces according Daniel/s comments. 
    And I wrote my questions down in merge request comments to Daniel.
    I hope the questions are good for parameter va'lidity design.
    
    //softhouse,
    //mbs,
    //Do you know the length of the door panel you test. Rebca. Willis is caring about the real ine呢rtia.
       
    //+++
    It should hold the parameter value also. Add interface for that.
    Then all "int32_t"'s used in Apps in the system can be replaced with this class.
    "Two more questions: 1-Does this mean that each parameter has one "ParameterVaule" object?  In that case, the code will create lots of "ParameterVaule" objects.
    2-When the parameter value should be hold by this class? If it is in PARAMETER_UPDATED call, the code may call si32GetParameterValue immediately after vSetParameterValue."

    //class ParameterProxy
    Actually, I'm not sure about the name anymore. I named it "Proxy" when it was supposed to be a complete proxy for the actual parameter. I'm thinking that a better name is "ParameterValue", maybe?
        
    "Changed the name in new commit. I suggest to use "ParameterValueValidity" to avoid confusion."
    
    //virtual bool boGetParameterValidStatus () volatile = 0;    
    This name is ambiguous. Call it "boIsParameterValid" instead.
        
    //virtual void vSetParameterValidStatus () volatile = 0;
    I don't think this is necessary. The validity of the value should be set when the "vSetParameterValue" function is called. So the value is invalid until it is actively set, from a "PARAMETER_UPDATED" call.
        
//--------------------------------
2019.12.17 Tuesday
    01. Swing Door Platform Code,
    02. English,
    03. Test,
    04. FOC, 
    05. Git use bc3,

    Today I started to work on parameterProxy(SPS-419). 
    I created a class with two interfaces. They are get & set parameter valid status methods.
    Pushed a new branch.
    And now, I want to make sure the design is correct. (What value is a proper value?)
    (Next sps-420.)
    
    firmware update... time
    BLE byte...

Today, there is no handling of startup order or race-conditions in parameter handling between the boards.
The motor board is where the parameters are stored and right now it boots up much faster than the Basic I/O board does, so there is no problem in accessing parameters from there. However, if that dynamic should change for whatever reason, there is no internal logic handling that error case.

One solution:
The configuration manager could wait for the other board to start broadcasting its presence. Once that connection is confirmed, it could send out a "Parameters Available" message, prompting each application to request the parameters that they need.

Downside to this solution is that all applications are requesting their parameters at the exact same time (possibly) overloading the bus and timing out the responses. Also, applications are running without being fully configured until the parameters values are returned, leavning them unconfigured for longer.

Another solution:
Each application must keep track of whether they have received a response from the configuration manager. If they have not done that within a certain timeout, they resend their request and keep doing so until the system has booted up completely.

This has the advantage of requiring no changes to ConfigurationManager and also being agnostic to knowing where in the system you are (whether or not your app is on the same board as the parameter storage).

        
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
