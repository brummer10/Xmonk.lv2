	
	STRIP ?= strip
	# check if user is root
	user = $(shell whoami)
	ifeq ($(user),root)
	INSTALL_DIR = /usr/lib/lv2
	else 
	INSTALL_DIR = ~/.lv2
	endif

	# check CPU and supported optimization flags
	ifneq ($(shell cat /proc/cpuinfo | grep sse3 ) , )
		SSE_CFLAGS = -msse3 -mfpmath=sse -mfxsr
	else ifneq ($(shell cat /proc/cpuinfo | grep sse2 ) , )
		SSE_CFLAGS = -msse2 -mfpmath=sse -mfxsr
	else ifneq ($(shell cat /proc/cpuinfo | grep sse ) , )
		SSE_CFLAGS = -msse -mfpmath=sse -mfxsr
		else ifneq ($(shell cat /proc/cpuinfo | grep ARM ) , )
		ifneq ($(shell cat /proc/cpuinfo | grep ARMv7 ) , )
			ifneq ($(shell cat /proc/cpuinfo | grep vfpd32 ) , )
				SSE_CFLAGS = -march=armv7-a -mfpu=vfpv3 
			else ifneq ($(shell cat /proc/cpuinfo | grep vfpv3 ) , )
				SSE_CFLAGS = -march=armv7-a -mfpu=vfpv3
			endif
		else
			ARMCPU = "YES"
		endif
	else
		SSE_CFLAGS =
	endif

	# set bundle name
	NAME = Xmonk
	BUNDLE = $(NAME).lv2
	VER = 0.4

	LIB_DIR := ../libxputty/libxputty/
	HEADER_DIR := $(LIB_DIR)include/

	# invoke build files
	OBJECTS = plugin/$(NAME).cpp 
	GUI_OBJECTS = gui/$(NAME)_x11ui.c

	# set compile flags
ifeq ($(TARGET), Linux)
	CXXFLAGS += -D_FORTIFY_SOURCE=2 -I. -I./dsp -I./plugin -fPIC -DPIC -O2 -Wall -funroll-loops \
	-fstack-protector -ffast-math -fomit-frame-pointer -fstrength-reduce \
	-fdata-sections -Wl,--gc-sections -Wl,-z,relro,-z,now -Wl,--exclude-libs,ALL $(SSE_CFLAGS)

	LDFLAGS += -I. -shared -lm -Wl,-z,noexecstack -fvisibility=hidden

	GUI_LDFLAGS += -I./gui -I./plugin -I$(HEADER_DIR) -Wl,-z,noexecstack -fvisibility=hidden \
	-L. $(LIB_DIR)libxputty.a -shared `pkg-config --cflags --libs cairo x11` -lm -Wl,-z,nodelete 
else ifeq ($(TARGET), Windows)
	CXXFLAGS += -D_FORTIFY_SOURCE=2 -I. -I./dsp -I./plugin -fPIC -DPIC -O2 -Wall -funroll-loops \
	-fstack-protector -ffast-math -fomit-frame-pointer -fstrength-reduce \
	-fdata-sections -Wl,--gc-sections -Wl,--exclude-libs,ALL $(SSE_CFLAGS)

	LDFLAGS += -I. -shared -lm $(PAWPAW_LFLAGS)

	GUI_LDFLAGS += -I./gui -I./plugin -I$(HEADER_DIR) -static-libgcc -static-libstdc++ \
	`$(PKGCONFIG) $(PKGCONFIG_FLAGS) --cflags --libs cairo ` \
	-L. $(LIB_DIR)libxputty.$(STATIC_LIB_EXT) -shared  -lm $(PAWPAW_LFLAGS)

	TTLUPDATE = sed -i '/lv2:binary/ s/\.so/\.dll/ ' ../bin/$(BUNDLE)/manifest.ttl
	TTLUPDATEGUI = sed -i '/a guiext:X11UI/ s/X11UI/WindowsUI/ ; /guiext:binary/ s/\.so/\.dll/ ' ../bin/$(BUNDLE)/$(NAME).ttl
endif

.PHONY : $(HEADER_DIR)*.h mod all clean install uninstall 

all : check $(NAME)
	$(QUIET)mkdir -p ../bin/$(BUNDLE)
	$(QUIET)cp ./plugin/*.ttl ../bin/$(BUNDLE)
	$(QUIET)$(TTLUPDATE)
	$(QUIET)$(TTLUPDATEGUI)
	$(QUIET)mv ./*.$(LIB_EXT) ../bin/$(BUNDLE)
	$(QUIET)if [ -f ../bin/$(BUNDLE)/$(NAME).$(LIB_EXT) ]; then \
		$(B_ECHO) "build finish, . . . $(reset)"; \
	else \
		$(R_ECHO) "sorry, build failed$(reset)"; \
	fi
	@$(B_ECHO) "=================== DONE =======================$(reset)"

mod : 
	@$(R_ECHO) "Not implemented for Xmonk$(reset)"

check :
ifdef ARMCPU
	@$(R_ECHO) "ARM CPU DETECTED, please check the optimisation flags$(reset)"
endif

clean :
	$(QUIET)rm -f *.a *.o *.$(LIB_EXT) 
	$(QUIET)rm -f $(NAME).$(LIB_EXT)
	$(QUIET)rm -rf ../bin
ifndef EXTRAQUIET
	@$(ECHO) ". ., clean up$(reset)"
endif

dist-clean :
	$(QUIET)rm -f $(NAME).$(LIB_EXT)
	$(QUIET)rm -rf ../bin
ifndef EXTRAQUIET
	@$(ECHO) ". ., clean up$(reset)"
endif

install :
ifeq ($(TARGET), Linux)
ifneq ("$(wildcard ../bin/$(BUNDLE))","")
	@$(ECHO) "Install Xmonc.lv2$(reset)"
	$(QUIET)mkdir -p $(DESTDIR)$(INSTALL_DIR)/$(BUNDLE)
	$(QUIET)cp -r ../bin/$(BUNDLE)/* $(DESTDIR)$(INSTALL_DIR)/$(BUNDLE)
	$(QUIET)$(B_ECHO) ". . , done$(reset)"
else
	$(QUIET)$(R_ECHO) ". . , you must build first$(reset)"
endif
else
	$(QUIET)$(R_ECHO) "Install is not implemented for windows, please copy the folder $(NAME).lv2 to Program Files/Common Files/LV2$(reset)"
endif

uninstall :
ifeq ($(TARGET), Linux)
	@$(ECHO) "Uninstall Xmonc.lv2$(reset)"
	$(QUIET)rm -rf $(INSTALL_DIR)/Xmonc.lv2
	$(QUIET)rm -rf $(INSTALL_DIR)/$(BUNDLE)
	$(QUIET)$(B_ECHO) ". . , done$(reset)"
else
	$(QUIET)$(R_ECHO) "Uninstall is not implemented for windows, please remove the folder $(NAME).lv2 from Program Files/Common Files/LV2$(reset)"
endif

$(NAME) :
	@$(B_ECHO) "Compiling $@.lv2 $(reset)"
	$(QUIET)$(CXX) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME).$(LIB_EXT)
	$(QUIET)$(CC) $(CFLAGS) $(GUI_OBJECTS) $(GUI_LDFLAGS) -o $(NAME)_ui.$(LIB_EXT)
	$(QUIET)$(STRIP) -s -x -X -R .comment -R .note.ABI-tag $(NAME).$(LIB_EXT)
	$(QUIET)$(STRIP) -s -x -X -R .comment -R .note.ABI-tag $(NAME)_ui.$(LIB_EXT)

nogui :
	@$(B_ECHO) "Compiling $(NAME) $(reset)"
	$(QUIET)$(CXX) $(CXXFLAGS) $(OBJECTS) $(LDFLAGS) -o $(NAME).$(LIB_EXT)
	$(QUIET)$(STRIP) -s -x -X -R .comment -R .note.ABI-tag $(NAME).$(LIB_EXT)

doc:
	#pass
