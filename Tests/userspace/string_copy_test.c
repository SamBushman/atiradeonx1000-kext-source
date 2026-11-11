/* string_copy_test.c - libGLProgrammability's std::string copy constructor and std::length_error(const string&), stock vs rebuilt (issue #256).
 *
 *   string_copy_test IMAGE DELTA_string_copy DELTA_length_error     (DELTA = function address - ShInitialize address in the image under test, signed hex)
 *
 * Hand-built source strings (a data pointer with the COW representation in front: length at data-12, capacity at data-8, refcount at data-4): shared (refcount 0, 1, 5), leaked
 * (refcount -1, the copy must clone), empty, long. For each, the copy constructor (`string(const string &)`: this[0] = data pointer) and the length_error constructor (this[0] = vtable,
 * this[1] = string data pointer) are called; the output lists what a caller can see: whether the copy shares the source's data pointer, the copy's length / content / refcount, the
 * source's refcount afterwards, and whether the vtable word is set. The output of the stock and the rebuilt image can be compared with cmp. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
typedef void *(*cfn)(void *, void *);
static void show(const char *tag, char *srcdata, char *copydata, int vt) {
    printf("%-24s shared=%d", tag, copydata == srcdata);
    printf(" copylen=%d copyrc=%d srcrc=%d", *(int *)(copydata - 12), *(int *)(copydata - 4), *(int *)(srcdata - 4));
    printf(" same_content=%d vt=%d\n", !memcmp(copydata, srcdata, *(int *)(srcdata - 12) + 1), vt);
}
int main(int argc, char **argv) {
    void *L, *a; char *base; cfn copy, lerr;
    static const int rcs[] = { 0, 1, 5, -1, -7 }; static const int lens[] = { 0, 1, 5, 40, 300 };
    if (argc < 4) { fprintf(stderr, "usage: string_copy_test IMAGE DELTA_string_copy DELTA_length_error\n"); return 2; }
    setvbuf(stdout, NULL, _IONBF, 0);
    L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL); if (!L) { fprintf(stderr, "dlopen: %s\n", dlerror()); return 2; }
    a = dlsym(L, "ShInitialize"); if (!a) a = dlsym(L, "_ShInitialize"); if (!a) { fprintf(stderr, "no ShInitialize\n"); return 2; }
    base = (char *)a; copy = (cfn)(base + (long)strtol(argv[2], 0, 16)); lerr = (cfn)(base + (long)strtol(argv[3], 0, 16));
    for (int r = 0; r < 5; r++) for (int l = 0; l < 5; l++) {
        char tag[64]; char *buf = malloc(12 + lens[l] + 16); char *data = buf + 12; unsigned *obj = calloc(4, 4); void *srcstr = &data;
        memset(buf, 0, 12 + lens[l] + 16); for (int i = 0; i < lens[l]; i++) data[i] = 'a' + i % 26;
        *(int *)(data - 12) = lens[l]; *(int *)(data - 8) = lens[l]; *(int *)(data - 4) = rcs[r];
        snprintf(tag, sizeof tag, "string(const string&) rc=%d len=%d", rcs[r], lens[l]);
        copy(obj, srcstr); show(tag, data, (char *)obj[0], 0);
        *(int *)(data - 4) = rcs[r]; obj[0] = obj[1] = 0;
        snprintf(tag, sizeof tag, "length_error rc=%d len=%d", rcs[r], lens[l]);
        lerr(obj, srcstr); show(tag, data, (char *)obj[1], obj[0] != 0);
    }
    return 0;
}
