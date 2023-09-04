CC=gcc
CFLAGS=-Wall  -Wextra  -pedantic -Wformat-security -Wfloat-equal -Wshadow -Wwrite-strings #-Wconversion
OPTIMISATIONS= -O3  -march=native
LDLIBS=
DEBUG_BASIC= -O0 -g3 -ggdb
DEBUG_GPROF =$(DEBUG_BASIC) -pg
DEBUG_VALGRIND= $(DEBUG_BASIC) -static-libasan
DEBUG= $(DEBUG_VALGRIND) -fsanitize=address
OBJECTS = heap.c example.c

OPTIONS=$(OPTIMISATIONS)

.PHONY : test

example: $(OBJECTS)
	$(CC)  -o $@ $^ $(CFLAGS) $(LDLIBS) $(OPTIONS)

debug: OPTIONS=$(DEBUG)
debug: example

valgrind: OPTIONS=$(DEBUG_VALGRIND)
valgrind: example

test:
	$(MAKE) -C tests test

clean:
	rm example
	$(MAKE) -C tests clean	
