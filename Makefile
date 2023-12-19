
include libxputty/Build/Makefile.base

BLUE = "\033[1;34m"
RED =  "\033[1;31m"
NONE = "\033[0m"

NOGOAL := mod install all

SUBDIR := Xmonk

.PHONY: $(SUBDIR) libxputty  recurse

$(MAKECMDGOALS) recurse: $(SUBDIR)

check-and-reinit-submodules :
ifeq (,$(filter $(NOGOAL),$(MAKECMDGOALS)))
ifeq (,$(findstring clean,$(MAKECMDGOALS)))
	@if git submodule status 2>/dev/null | egrep -q '^[-]|^[+]' ; then \
		echo $(red)"INFO: Need to reinitialize git submodules"$(NONE); \
		git submodule update --init; \
		echo $(blue)"Done"$(NONE); \
	else echo $(blue)"Submodule up to date"$(NONE); \
	fi
endif
endif

libxputty: check-and-reinit-submodules
ifeq (,$(filter $(NOGOAL),$(MAKECMDGOALS)))
ifeq (,$(wildcard ./libxputty/xputty/resources/mandala.png))
	@cp ./Xmonk/gui/*.png ./libxputty/xputty/resources/
endif
	@exec $(MAKE) --no-print-directory -j 1 -C $@ $(MAKECMDGOALS)
endif

$(SUBDIR): libxputty
	@exec $(MAKE) --no-print-directory -j 1 -C $@ $(MAKECMDGOALS)

clean:
	@rm -f ./libxputty/xputty/resources/mandala.png
