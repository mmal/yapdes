#			#
#	Makefile	#
#			#


export SHELL = /bin/bash
export CC = cc
export WFLAGS = -ansi -pedantic -Wall \
       -Wshadow \
       -Wmissing-prototypes -Wstrict-prototypes \
       -Wpointer-arith -Wcast-qual -Wcast-align \
       -Wwrite-strings -Wnested-externs \
       -fshort-enums -fno-common -Dinline=


export CFLAGS = $(WFLAGS)
export OFLAGS = -O2 # left empty for debuggin reasons
export GDBFLAGS = -ggdb
export FLAGS = $(CFLAGS) $(OFLAGS) $(GDBFLAGS)
export LIBS = -lm -lgsl -lgslcblas # -lfftw3
export ARCHIVE = $(PWD)/libyapdes.a
export MAKEFILES = $(PWD)/Makefile.common
DIRS = $(patsubst %/,%,$(wildcard */))
export INCLUDES = $(patsubst %/, -I $(PWD)/%, $(wildcard */))

.PHONY : clean $(DIRS) projekty

project: CLEAR_AR $(DIRS)

test: project test.o $(DIRS)
	$(CC) $(FLAGS) $(LIBS) $(INCLUDES) test.o $(ARCHIVE) -o $@

test.o: test.c test.h
	$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<

test2: project test2.o $(DIRS)
	$(CC) $(FLAGS) $(LIBS) $(INCLUDES) test2.o $(ARCHIVE) -o $@

test2.o: test2.c test2.h
	$(CC) $(FLAGS) $(INCLUDES) -c -o $@ $<


CLEAR_AR:
	@rm -f libyapdes.a
	@ar rs libyapdes.a

$(DIRS):
	@echo -e "\033[1;36m$(CURDIR)/$@\033[0m"
	@$(MAKE) --no-print-directory -eC $@ project

clean:
	@rm -f *.o libyapdes.a
	@for d in $(DIRS); do $(MAKE) -eC "$${d}" $@; done

