# Tests/Makefile
#
# Builds the issue #42 feature-parity test harness as a plain userspace
# Tiger binary (NOT a kext - no -fapple-kext, no kernel headers). Uses
# the stock Apple gcc (4.0.1) since this is a small, C89-shaped program
# with no need for a modern toolchain. Links against this system's own
# IOKit/CoreFoundation frameworks so it exercises the real live driver.
#
# Usage (on the G5, from Tests/):
#   make
#   ./parity_test_harness

CC = gcc
CFLAGS = -Wall -Wno-four-char-constants
LDFLAGS = -framework IOKit -framework CoreFoundation

SRCS = main.c test_gl_context.c test_2d_context.c test_dvd_context.c test_surface_context.c
OBJS = $(SRCS:.c=.o)
TARGET = parity_test_harness

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c common.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
