    
/SwingDoorPlatform/products/Makefile        ::             include ../Makefile

/SwingDoorPlatform/Makefile                 ::             include mbsSdk/tools/ABS/abs.mk

/SwingDoorPlatform/mbsSdk/tools/ABS/abs.mk  ::             ifeq,
                                                           origin
                                                           error
                                                           foreach
                                                           realpath
                                                           lastword
                                                           filter
                                                           define
                                                           subst
                                                           shell
                                                           eval
                                                           dir
                                                           info
                                                           $(or $(wildcard
                                                           
                                                           .PHONY
                                                           help
                                                           build-all
                                                           clean-all
                                                           
                                                           include $(ABS_SYS_DIR)build.mk
                                                           
/SwingDoorPlatform/mbsSdk/tools/ABS/build.mk ::            MBS_CC_TOOLCHAIN