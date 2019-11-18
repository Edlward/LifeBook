/**
  \file taskHandler.hpp

  \par Copyright &copy; 2017 ASSA ABLOY ES Production AB
  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB

  \brief  Application interface for the input module.
  \author Jerry.Hua

*/
#ifndef _TASK_HANDLER_HPP_
#define _TASK_HANDLER_HPP_ //lint !e1960 MISRA C++, 17-0-2. Re-use is done to form a standard header guard in this case


extern "C" {
    #include <FreeRTOS.h>
    #include <task.h>
}

namespace input
{
    extern xTaskHandle inputAppHandler;
}

namespace comm
{
    extern xTaskHandle commAppTaskHandleTop;
}

namespace configurationManager
{
    extern xTaskHandle cManagerAppTaskHandleTop;
}

namespace motionControl
{
    extern xTaskHandle motionControlAppTaskHandleTop;
}

namespace statisticsAndLog
{
    extern xTaskHandle statisticsAndLogAppTaskHandleTop;
}

namespace systemMonitor
{
    extern xTaskHandle systemMonitorAppTaskHandleTop;
}

#endif /* _TASK_HANDLER_HPP_ */

/**
  \}
*/
