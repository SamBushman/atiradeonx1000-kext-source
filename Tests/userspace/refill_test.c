/* refill_test.c - libGLProgrammability's SGI allocator refill (std::__default_alloc_template<true,0>::_S_refill), stock vs rebuilt (issue #225).
 *
 *   refill_test IMAGE OFF_ShInitialize OFF_S_refill OFF_S_free_list [oob | bench COUNT]
 *
 * _S_refill(n) takes a chunk for objects of size n (a multiple of 8, 8..128) and links the spare objects into free_list[(n+7)/8-1]. The OFF_ arguments are nm
 * values (of _ShInitialize, __ZNSt24__default_alloc_templateILb1ELi0EE9_S_refillEm, ...12_S_free_listE); the load address comes from dlsym("ShInitialize").
 * For every n in 8..128 step 8 (twice, so the second call runs against the first one's leftover pool) the program prints whether the chunk is non-null, how many
 * objects the free list holds afterwards, that every link is n bytes further on and that the chain ends in 0 - nothing that depends on addresses - so the output
 * of the stock and of the rebuilt image can be compared with cmp. With the argument `oob` it also calls the REBUILT image with the out-of-contract sizes 0, 7+128+1
 * and 0x3fff (stock indexes the table with them without a check and writes outside it): the rebuilt one must return 0 and leave the table alone (#225). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <sys/time.h>

typedef char *(*refill_t)(unsigned long);

int main(int argc, char **argv) {
    void *L;
    char *base;
    refill_t refill;
    char **list;
    int n, round, bad = 0;
    if (argc < 5) { fprintf(stderr, "usage: refill_test IMAGE OFF_ShInitialize OFF_S_refill OFF_S_free_list [oob]\n"); return 2; }
    setvbuf(stdout, NULL, _IONBF, 0);
    L = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL);
    if (!L) { fprintf(stderr, "dlopen: %s\n", dlerror()); return 2; }
    {
        void *a = dlsym(L, "ShInitialize");
        if (!a) a = dlsym(L, "_ShInitialize");
        if (!a) { fprintf(stderr, "no ShInitialize\n"); return 2; }
        base = (char *)a - strtoul(argv[2], 0, 16);
    }
    refill = (refill_t)(base + strtoul(argv[3], 0, 16));
    list = (char **)(base + strtoul(argv[4], 0, 16));
    if (argc > 6 && strcmp(argv[5], "bench") == 0) {      /* cost of the call itself (the guard of #225 sits on this path): COUNT calls of refill(8), ns per call */
        long i, cnt = atol(argv[6]);
        struct timeval t0, t1;
        gettimeofday(&t0, 0);
        for (i = 0; i < cnt; i++) refill(8);
        gettimeofday(&t1, 0);
        printf("%.1f ns per refill(8) call (%ld calls)\n", ((t1.tv_sec - t0.tv_sec) * 1e6 + (t1.tv_usec - t0.tv_usec)) * 1000.0 / cnt, cnt);
        return 0;
    }
    for (round = 0; round < 2; round++)
        for (n = 8; n <= 128; n += 8) {
            char *chunk = refill(n), *p;
            int count = 0, stride_ok = 1, end_ok = 0;
            if (chunk) {
                p = list[n / 8 - 1];
                while (p && count < 100) {
                    char *next = *(char **)p;
                    count++;
                    if (next && next != p + n) stride_ok = 0;
                    if (!next) end_ok = 1;
                    p = next;
                }
            }
            printf("n=%3d round %d: chunk %s, %d spare objects, stride %s, chain %s\n", n, round, chunk ? "ok" : "NULL", count, stride_ok ? "ok" : "BAD",
                   end_ok ? "terminated" : "UNTERMINATED");
            if (!chunk || !stride_ok || !end_ok) bad = 1;
        }
    if (argc > 5 && strcmp(argv[5], "oob") == 0) {
        static const unsigned long oob[] = { 0, 136, 0x3fff, 0x7ffffff8 };
        char *snapshot[16];
        int i;
        memcpy(snapshot, list, sizeof snapshot);
        for (i = 0; i < 4; i++) {
            char *r = refill(oob[i]);
            int same = memcmp(snapshot, list, sizeof snapshot) == 0;
            printf("out-of-contract n=%#lx: returns %s, free-list table %s\n", oob[i], r ? "NON-NULL" : "NULL", same ? "untouched" : "MODIFIED");
            if (r || !same) bad = 1;
        }
    }
    printf("RESULT: %s\n", bad ? "FAIL" : "PASS");
    return bad;
}
