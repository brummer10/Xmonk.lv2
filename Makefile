
SUBDIR := Xmonk

.PHONY: $(SUBDIR) Xputty  recurse

$(MAKECMDGOALS) recurse: $(SUBDIR)

Xputty:
	@exec $(MAKE) -j 1 -C $@ $(MAKECMDGOALS)

$(SUBDIR): Xputty
	@exec $(MAKE) -j 1 -C $@ $(MAKECMDGOALS)

