### learn makefile from "GNU make file manual-liu haibing translated."
include include.mk
target:
	@echo "first test."
#	@ls
	@echo "===chap3.4 MAKEFILES is: $(MAKEFILES)"
	@echo "===chap3.5 MAKEFILE_LIST is: $(MAKEFILE_LIST)"
	@echo "VAR is" $(VAR)
	@echo "===chap4.5.1 VPATH is: $(VPATH)"
	@echo "$$ ^ is ($^)"
	@echo "$$ @ is ($@)"
	@echo "===chap5.6 MAKE is: $(MAKE)"
	@echo "SHELL is: $(SHELL)"
	@echo "MAKEFLAGS is: $(MAKEFLAGS)"
	@echo "VARIABLES is: $(VARIABLES)"
	@echo "===chap6.0 $$ < is: ($<)"
	@echo "$$ ? is: ($?)"
	@echo "$$ * is: ($*)"
	
	@echo $(two-lines)
override define two-lines
	echo foo
	echo $(VAR)
endef
	

.PHONY:clean
clean:
	rm -rf *.o temp


###chap 6.9
HOSTNAME = server-http

.PHONY:debug
debug:
	@echo "hostname is : $(HOSTNAME)"
	@echo "shell is : $(SHELL)"
