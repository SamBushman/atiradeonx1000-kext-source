/* const_scratch_test.c - state of the interpreter's constants/scratch block (0xd80 bytes, PPCConstantsAndScratchCreate), stock vs rebuilt.
 *
 *   const_scratch_test STOCK.dylib REBUILT.dylib
 *
 * The block is filled by _PPCConstantsAndScratchInitialise (float constants stored with `stfs`, integer masks, log2 tables, the noise generator's tables from
 * random(), seeded identically in the two forked children). The parent compares the two 0xd80-byte images word for word and lists every difference.
 * Found by the -Wall audit: a Ghidra float literal assigned to an integer lvalue (`param_1[0x1c] = 0.003921569;`) is a value conversion in C (0), the stock stores the bits. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <sys/wait.h>

static void run(const char *lib, const char *out) {
    alarm(60);
    void *L = dlopen(lib, RTLD_NOW | RTLD_LOCAL); if (!L) _exit(3);
    void *(*create)(void) = dlsym(L, "PPCConstantsAndScratchCreate"); if (!create) _exit(4);
    srandom(20260926);
    unsigned char *p = create(); if (!p) _exit(5);
    FILE *f = fopen(out, "wb"); if (!f) _exit(2);
    fwrite(p, 1, 0xd80, f); fclose(f); _exit(0);
}

int main(int argc, char **argv) {
    if (argc < 3) { fprintf(stderr, "usage: const_scratch_test STOCK REBUILT\n"); return 2; }
    const char *tag[2] = { "/tmp/cs_stock.bin", "/tmp/cs_rebuilt.bin" }; int st[2];
    for (int k = 0; k < 2; k++) { pid_t p = fork(); if (p == 0) run(argv[1 + k], tag[k]); waitpid(p, &st[k], 0); if (!WIFEXITED(st[k]) || WEXITSTATUS(st[k])) { printf("%s child failed (%d)\n", k ? "rebuilt" : "stock", st[k]); return 1; } }
    unsigned a[0x360], b[0x360]; FILE *fa = fopen(tag[0], "rb"), *fb = fopen(tag[1], "rb");
    if (!fa || !fb || fread(a, 4, 0x360, fa) != 0x360 || fread(b, 4, 0x360, fb) != 0x360) { printf("short read\nRESULT: FAIL\n"); return 1; }
    int diff = 0; for (int i = 0; i < 0x360; i++) if (a[i] != b[i]) { diff++; if (diff <= 40) printf("word %#x: stock %08x rebuilt %08x\n", i * 4, a[i], b[i]); }
    printf("constants/scratch block: %d of %d words differ\nRESULT: %s\n", diff, 0x360, diff ? "FAIL" : "PASS");
    return diff != 0;
}
