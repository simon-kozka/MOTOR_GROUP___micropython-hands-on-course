#
# model
# 
# File created : 2026-02-21
#

CC               = gcc
CFLAGS           += -O3 -Wall -lm -Wno-unused-function  -Wno-restrict
PROJECTNAME      = model
CLEANFILES       =
EXTRA_RUNNER_OPT = 

all:

clean: 
	rm -f $(CLEANFILES)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: all clean test unittest pydist

$(PROJECTNAME).dll: $(PROJECTNAME).c
	x86_64-w64-mingw32-gcc -o $@ $< $(CFLAGS) -shared

pydist: $(PROJECTNAME).dll $(PROJECTNAME).py
	mkdir -p pydist
	touch pydist/__init__.py
	cp $(PROJECTNAME).dll $(PROJECTNAME).py pydist/
	

all: $(PROJECTNAME).dll pydist

CLEANFILES += $(PROJECTNAME).dll

