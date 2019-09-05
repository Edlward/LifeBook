--------------------------------------------
open bash or cmd,
copy generate_msg_code.py to C:\mbs\SwingDoorPlatform\ from C:\mbs\SwingDoorPlatform\tools\python\build\

$cp C:\mbs\SwingDoorPlatform\tools\python\build\generate_msg_code.py    C:\mbs\SwingDoorPlatform\generate_msg_code.py
$python generate_msg_code.py
$rm generate_msg_code.py

**components/messages/sw200/inc/messageIds.h


--------------------------------------------
结构体数组初始化：sorry, unimplemented: non-trivial designated initializers not supported!

需要保持数组的下标顺序一致；

在不改变Python script 的情况下，手动检出checkout 这两个文件：
git checkout components/messages/sw200/inc/messageIds.h
git checkout components/messages/sw200/src/messages.cpp

并增加在MessageRouterImp::arRoutingTable[]表中增加新的消息初始化。
/SwingDoorPlatform/modules/messageRouter/motorBoard/mbs_st_m64_core_v10/config/src/messageRoutingTable.cpp
