/* dxt_test.c - GLDriver's software DXT compressor dxtCompressImage(width, height, sourceFormat, compressionCode, srcPixels, dstBlocks), stock vs rebuilt.
 *
 *   dxt_test IMAGE EXPORT OFF_EXPORT OFF_FUNC
 *
 * fnfuzz only reaches it with random (mostly negative or enormous) sizes. This test feeds it what the driver feeds it: block-aligned sizes (4..64), the source
 * formats it decodes (GL_RGB 0x1907, GL_RGBA 0x1908, GL_BGR 0x80e0, GL_BGRA 0x80e1) and every compression code 0..0xf, with seeded random pixels (and a smooth
 * gradient, which DXT encoders treat differently). The destination is pre-filled with 0xAA and one sentinel word is checked after it, so a store outside the
 * blocks is seen too. One line per case with an FNV digest of the destination (DXT_HEX=1 adds the first 32 bytes); run on both images and `cmp` the outputs. Every case runs in a forked child
 * (codes the function does not know may fault - that must then happen in both images). The function is not exported: its address is the nm offset rebased on
 * dlsym(EXPORT). Build: gcc -arch ppc -o dxt_test dxt_test.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

typedef int (*dxt_t)(int, int, int, int, const unsigned char *, unsigned char *);

static unsigned long long fnv(const unsigned char *p, size_t n) {
    unsigned long long h = 1469598103934665603ULL;
    while (n--) { h ^= *p++; h *= 1099511628211ULL; }
    return h;
}

int main(int argc, char **argv) {
    static const int dims[][2] = { {4, 4}, {8, 4}, {4, 16}, {16, 16}, {32, 8}, {64, 64} };
    static const int fmts[] = { 0x1907, 0x1908, 0x80e0, 0x80e1 };
    unsigned char *src, *dst;
    dxt_t f;
    unsigned d, k, code, pattern;
    if (argc < 5) { fprintf(stderr, "usage: dxt_test IMAGE EXPORT OFF_EXPORT OFF_FUNC\n"); return 2; }
    void *L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    if (!L) { printf("dlopen failed: %s\n", dlerror()); return 2; }
    char *e = (char *)dlsym(L, argv[2]);
    if (!e) { printf("no %s\n", argv[2]); return 2; }
    f = (dxt_t)(e - strtoul(argv[3], 0, 16) + strtoul(argv[4], 0, 16));
    setvbuf(stdout, NULL, _IONBF, 0);
    src = malloc(64 * 64 * 4); dst = malloc(64 * 64 + 64);
    for (d = 0; d < sizeof dims / sizeof dims[0]; d++)
        for (k = 0; k < sizeof fmts / sizeof fmts[0]; k++)
            for (code = 0; code < 16; code++)
                for (pattern = 0; pattern < 2; pattern++) {
                    int w = dims[d][0], h = dims[d][1], i, st;
                    size_t blocks = (size_t)(w / 4) * (h / 4), dstsize = blocks * 16;
                    pid_t pid;
                    srand(1000 + d * 97 + k * 31 + code * 7 + pattern);
                    for (i = 0; i < w * h * 4; i++)
                        src[i] = pattern ? (unsigned char)((i / 4) * 255 / (w * h) + (i & 3) * 16) : (unsigned char)(rand() >> 7);
                    memset(dst, 0xAA, dstsize + 16);
                    fflush(stdout);
                    pid = fork();
                    if (pid == 0) {
                        f(w, h, fmts[k], code, src, dst);
                        printf("%2dx%-2d fmt %04x code %2x %s: dst %016llx tail %s\n", w, h, fmts[k], code, pattern ? "gradient" : "random  ", fnv(dst, dstsize),
                               memcmp(dst + dstsize, "\xAA\xAA\xAA\xAA\xAA\xAA\xAA\xAA", 8) == 0 ? "intact" : "OVERWRITTEN");
                        if (getenv("DXT_HEX")) { int b; printf("   first bytes:"); for (b = 0; b < 32 && b < (int)dstsize; b++) printf(" %02x", dst[b]); printf("\n"); }
                        _exit(0);
                    }
                    waitpid(pid, &st, 0);
                    if (WIFSIGNALED(st)) printf("%2dx%-2d fmt %04x code %2x %s: signal %d\n", w, h, fmts[k], code, pattern ? "gradient" : "random  ", WTERMSIG(st));
                }
    return 0;
}
