

include mbsSdk/tools/ABS/abs.mk
{
    ##//1 // // products variables.
    PRODUCTS:=products/
    TEST_PRODUCTS:=test/
    include $(MBS_SDK_DIR)tools/ABS/global.mk
    {   EMTPY:=
    }
    TEST_PRODUCTS:=test/
    ABS_PYTHON_BUILD_DIR := $(MBS_SDK_DIR)tools/python/build/
    
    ##//2 // // define functions.
    define abs-warning
        
    ##//3 // // make target.
    ifeq (help,$(ABS_GOAL))
    else ifeq (clean-all,$(ABS_GOAL))
    
    ##//4 // // include build.mk
    include $(ABS_SYS_DIR)build.mk
    {
        MBS_CC_TOOLCHAIN ?= gcc-arm-none-eabi-6-2017-q2
        define abs-lookup-item
        define abs-get-generator
    }
    
    ##//5 // // include product.mk
    include $(ABS_SYS_DIR)targets/product.mk
    {
        _ABS_CMDS := build program clean rebuild
        
        ##// // // include debug tool.
        include $(ABS_SYS_DIR)openocd.mk
        {
            _ABS_OPENOCD_DIR           := $(MBS_SDK)tools/debug/openocd/
            define abs-openocd-hw-from-board
            define abs-tool-program
        }
        
        ##// // // include post build
        include $(ABS_SYS_DIR)postBuild.mk
        {
            _ABS_POST_BUILD_RUNNER := $(ABS_PYTHON_BUILD_DIR)postBuild.py
            {
                postBuild.py --elfFile=<elf_file> --fwiType=<fwi_type>
                def run_mfw_gen(elf_file, fwi_type, encrypted=False):
            }
            define abs-platform-specific-post-build
        }
        define abs-find-product
            $(strip $(or $(wildcard $(ABS_TOP_DIR)products/$1/abs-binary.mk),
        define abs-build !!!
            $$(info Compiling...)
        define abs-module
        define abs-component
    }
}
