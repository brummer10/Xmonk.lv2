
SUBDIR := Xmonk

.PHONY: $(SUBDIR) libxputty  recurse

$(MAKECMDGOALS) recurse: $(SUBDIR)

clean:
	@rm -f ./libxputty/xputty/resources/mandala.png

libxputty:
ifeq (,$(wildcard ./libxputty/xputty/resources/mandala.png))
	cp ./Xmonk/gui/*.png ./libxputty/xputty/resources/
endif
	@exec $(MAKE) -j 1 -C $@ $(MAKECMDGOALS)

$(SUBDIR): libxputty
	@exec $(MAKE) -j 1 -C $@ $(MAKECMDGOALS)

