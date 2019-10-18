 /**/
#define MBS_CONSOLE_REGISTER_CMD( _name, _command, _parameter, _argumentCount, _argumentsRequired, _briefDescription, _usageDescription )                   \
    MbsConsoleCommandResult _command ( MbsConsoleCommandHandle * handle, void * parameter, uint8_t argc, char * argv[] ); \
    MbsConsoleCommandRecord mbsCmdList_ ## _name                                             \
                    __attribute__ ((section (".mbsConsoleCmdList")))                         \
                    = {                                                                      \
                        .command      = (_command),                                          \
                        .parameter    = (_parameter),                                        \
                        .name         = #_name,                                              \
                        .description  = { .brief      = _briefDescription,                   \
                                          .verbose    = _usageDescription },                 \
                        .arguments    = { .totalCount = _argumentCount,                      \
                                          .required   = _argumentsRequired },                \
                        .modeMask     = MBS_CONSOLE_MODE_DEFAULT                             \
                    };                                                                       \
    MbsConsoleCommandResult _command ( MbsConsoleCommandHandle * handle, void * parameter, uint8_t argc, char * argv[] )

    
MBS_CONSOLE_REGISTER_CMD( sysCtrlGetBuildId

MBS_CONSOLE_REGISTER_CMD_WITH_MODE( help, consoleCmd_help
    /SwingDoorPlatform/mbsSdk/components/application/mbsConsole/src/mbsConsoleCommandList.c