# Tests/destructive/Makefile (issue #87): one binary per destructive test, NEVER linked into the parity suite (../Makefile does not know this directory).
#   make destructive-<name>      builds ./<name> from <name>.c + dtest.c  (e.g. make destructive-selftest_get_state)
# The stock gcc 4.0.1 on the Tiger G5; links IOKit.
CC = gcc
CFLAGS = -Wall -Wno-four-char-constants -I..
LDFLAGS = -framework IOKit -framework CoreFoundation

destructive-%: %.c dtest.c dtest.h ../common.h
	$(CC) $(CFLAGS) -o $* $*.c dtest.c $(LDFLAGS)

clean:
	rm -f selftest_get_state regsnap

.PHONY: clean
