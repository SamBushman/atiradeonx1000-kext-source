/* string_char_test.c - libGLProgrammability's std::string character searches, stock vs rebuilt (issue #255).
 *
 *   string_char_test IMAGE DELTA_find DELTA_rfind DELTA_first_not_of DELTA_last_not_of
 *
 * The four functions are the char overloads  string::find(char, pos), rfind(char, pos), find_first_not_of(char, pos), find_last_not_of(char, pos)  (stock 0x97c159e0, 0x97c15b28,
 * 0x97c15e2c, 0x97c15f4c). A `char` argument arrives in a register whose upper 24 bits are whatever the caller left there; the stock compares the sign-extended LOW BYTE, the old
 * rebuilt code compared the whole register. Each DELTA is (function address - ShInitialize address) in the image under test (signed hex); the load address comes from
 * dlsym("ShInitialize"). The string is built by hand: a data pointer with the length at data-12. For every character value (a byte present in the string, a byte absent from
 * it, each also with garbage in the upper bits, and bytes >= 0x80) and several start positions, every function's result is printed, so the output of the stock and of the
 * rebuilt image can be compared with cmp. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

typedef long (*chfn)(void *, int, unsigned long);

int main(int argc, char **argv) {
    void *L, *a;
    char *base, *buf, *data;
    chfn fn[4];
    static const char *names[4] = { "find", "rfind", "find_first_not_of", "find_last_not_of" };
    static const unsigned char text[] = { 'h', 'e', 'l', 'l', 'o', 0xff, 'w', 0x80, 'o', 'r', 'l', 'd', 'a', 'a' };
    static const unsigned int chars[] = { 'o', 'z', 0xff, 0x80, 'a', 0x16f, 0x1ff, 0xffffff6f, 0xffffffff, 0x12345680, 0x7fff0061, 0, 'h', 'd' };
    static const unsigned long poss[] = { 0, 1, 5, 8, 13, 14, 100, 0xffffffffUL };
    int f, c, p, bad = 0;
    if (argc < 6) { fprintf(stderr, "usage: string_char_test IMAGE DELTA_find DELTA_rfind DELTA_first_not_of DELTA_last_not_of\n"); return 2; }
    setvbuf(stdout, NULL, _IONBF, 0);
    L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    if (!L) { fprintf(stderr, "dlopen: %s\n", dlerror()); return 2; }
    a = dlsym(L, "ShInitialize");
    if (!a) a = dlsym(L, "_ShInitialize");
    if (!a) { fprintf(stderr, "no ShInitialize\n"); return 2; }
    base = (char *)a;
    for (f = 0; f < 4; f++) fn[f] = (chfn)(base + (long)strtol(argv[2 + f], 0, 16));
    buf = (char *)malloc(64);
    memset(buf, 0, 64);
    data = buf + 12;
    memcpy(data, text, sizeof text);
    *(int *)(data - 12) = (int)sizeof text;
    for (f = 0; f < 4; f++)
        for (c = 0; c < (int)(sizeof chars / sizeof chars[0]); c++)
            for (p = 0; p < (int)(sizeof poss / sizeof poss[0]); p++) {
                long r = fn[f](&data, (int)chars[c], poss[p]);
                printf("%-18s c=%08x pos=%08lx -> %ld\n", names[f], chars[c], poss[p], r);
            }
    return bad;
}
