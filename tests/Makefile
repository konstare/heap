CC=gcc
CFLAGS=-Wall  -Wextra  -pedantic -Wformat-security -Wfloat-equal -Wshadow -Wwrite-strings
DEBUG= -O0 -g3 -ggdb -static-libasan   -fsanitize=address

VPATH=../

testsuite: heap.c testsuite.c
	$(CC)  -o $@ $^ $(CFLAGS) $(DEBUG)

.PHONY: clean test

test: testsuite
	./testsuite

clean:
	rm -f testsuite
