/* ctxfuzz.c - fnfuzz.c with a hand-built context: the differential for functions that CALL THROUGH POINTERS (GLEngine: the glX_Exec / state functions that jump through
 * ctx->dispatch slots, a renderer plugin's function table, ...). Same harness (forked children, seeded 256 KB arena, stock run twice, arena digest), plus:
 *   - the ledger (Tools/userspace/fnfuzz_gen.py with FNFUZZ_CTX=1) has an 8th column: the code pointers the stock loads from `*(param+off1)[+off2...]` and calls / jumps to,
 *     `param:off1[:off2]`, comma separated. The harness makes that parameter point at a fixed place of the arena (ctx), puts a RECORDING STUB at each slot (a deeper level
 *     points at a scratch block that holds the stub), and runs the function. A stub logs (id, r3..r10, f1..f4) and returns a seeded value (0, 1, -1 or an arena pointer) in
 *     r3 and 0.0 in f1; a tail `bctr` through the slot returns to the function's caller the same way.
 *   - the result carries the CALL LOG: how many stub calls, in which order (ids), and r3 of each (the context argument, which every call passes). Stock and rebuilt must make
 *     the same calls in the same order with the same r3 and leave the same arena. Registers r4..r10 / f1..f4 of a call can hold leftovers of the callee-side's own
 *     computation (a callee that takes one argument gets garbage there), so they are only compared as INFO (`argdiff`): the static check (argtriage.py) is the verdict on arguments.
 *   ctxfuzz LEDGER.tsv STOCK_IMAGE REBUILT_IMAGE [trials] [name-substring|@first,count]
 * --- original fnfuzz.c header follows ---
 * fnfuzz.c - pure-function differential test of a rebuilt userspace image against the stock one (issue #68, criterion 1).
 *
 *   fnfuzz LEDGER.tsv STOCK_IMAGE REBUILT_IMAGE [trials] [name-substring|@first,count]
 *
 * LEDGER.tsv comes from Tools/userspace/fnfuzz_gen.py (candidate functions: no indirect call, no hardware / atomic instruction, no import outside a
 * whitelist; addresses relative to an exported anchor present in both images). For every candidate and every trial the same arguments are built from a seed and
 * the function is called in a forked child of each image: pointer parameters (and a share of the unknown integer ones) point into a 128 KB scratch arena filled from
 * the seed, integers and floats are drawn from a mixed distribution (zero, small, powers of two, random, negative), the remaining argument registers get random values.
 * The child reports how it ended (normal / signal), r3 (integer results) or f1 (float results), and a digest of the whole arena after the call; words that
 * point into the image itself are replaced by a marker first (the two images have different layouts). The stock image is run twice per trial: a trial in which
 * the stock disagrees with itself (uninitialised stack, time, heap addresses) is dropped as nondeterministic.
 * Output: one line per function with a difference, a summary, RESULT. A function whose every trial ended in a signal in both images is reported as uninformative. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include <dlfcn.h>
#include <unistd.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <sys/select.h>
#include <fcntl.h>
#include <mach-o/loader.h>

#define ARENA_BASE 0x50000000u
#define ARENA_SIZE 0x40000u
#define CTX_BASE_STEP 0x12000u   /* parameter k with indirect slots points at arena + 0x1000 + k * CTX_BASE_STEP */
#define BLOCK_BASE 0x26000u      /* second-level scratch blocks (0x800 each) */
#define LOG_BASE 0x4ffe0000u     /* word 0 cursor, word 1 stub return value, double at +8 = 0.0, 72-byte entries from +0x10 */
#define STUB_BASE 0x4fff4000u    /* stub k at +32*k */
#define ARENA_PTR_LO 0x1000u

typedef unsigned long long (*fi_t)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, double, double, double, double, double, double, double, double, double, double, double, double, double);
typedef double (*fd_t)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, double, double, double, double, double, double, double, double, double, double, double, double, double);

typedef struct { int status; unsigned r3, r4; unsigned long long f1; unsigned digest; unsigned args[8]; double dargs[4]; unsigned logn, dig_ids, dig_soft; unsigned ent[8][18]; } result_t;
static unsigned cur_args[8]; static double cur_dargs[4];
typedef struct { int id; char name[96]; unsigned stock_addr, reb_off; int size; char pc[24]; char rc; int nind; struct { int p, n; unsigned off[3]; } ind[24]; } cand_t;


/* the recording stub every slot points at (through a per-slot trampoline that sets r0 = id): volatile registers only (r0, r11, r12), no stack */
__asm__(".text\n.align 2\n.globl _ctxstub_common\n_ctxstub_common:\n"
 "lis r11,0x4ffe\n lwz r12,0(r11)\n andis. r11,r12,1\n bne- 1f\n"
 "stw r0,0(r12)\n stw r3,4(r12)\n stw r4,8(r12)\n stw r5,12(r12)\n stw r6,16(r12)\n stw r7,20(r12)\n stw r8,24(r12)\n stw r9,28(r12)\n stw r10,32(r12)\n"
 "stfd f1,40(r12)\n stfd f2,48(r12)\n stfd f3,56(r12)\n stfd f4,64(r12)\n addi r12,r12,72\n lis r11,0x4ffe\n stw r12,0(r11)\n"
 "1: lis r11,0x4ffe\n lwz r3,4(r11)\n lis r12,0x4fff\n lwz r4,0(r12)\n lfd f1,8(r12)\n blr\n");   /* r3 = log word 1, r4 / f1 from the unused tail of the log region (LOG_BASE + 0x10000: word 0 = r4, double at +8 = f1) */
extern void ctxstub_common(void);
static void setup_stubs(void) {
    unsigned char *lg = mmap((void *)LOG_BASE, 0x12000, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANON | MAP_PRIVATE, -1, 0);
    unsigned *st = mmap((void *)STUB_BASE, 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_FIXED | MAP_ANON | MAP_PRIVATE, -1, 0);
    if (lg != (void *)LOG_BASE || st != (void *)STUB_BASE) { fprintf(stderr, "stub mmap failed\n"); exit(2); }
    unsigned c = (unsigned)ctxstub_common;
    for (unsigned k = 0; k < 64; k++) {
        unsigned *p = st + 8 * k;
        p[0] = 0x38000000u | (k + 1);                       /* li r0,k+1 */
        p[1] = 0x3d600000u | (c >> 16);                     /* lis r11,hi */
        p[2] = 0x616b0000u | (c & 0xffff);                  /* ori r11,r11,lo */
        p[3] = 0x7d6903a6u;                                 /* mtctr r11 */
        p[4] = 0x4e800420u;                                 /* bctr */
    }
    for (char *q = (char *)st; q < (char *)st + 0x1000; q += 32) __asm__ __volatile__("dcbf 0,%0" :: "r"(q) : "memory");
    __asm__ __volatile__("sync" ::: "memory");
    for (char *q = (char *)st; q < (char *)st + 0x1000; q += 32) __asm__ __volatile__("icbi 0,%0" :: "r"(q) : "memory");
    __asm__ __volatile__("sync\n\tisync" ::: "memory");
}

static unsigned long long rng_state;
static unsigned rnd32(void) { rng_state = rng_state * 6364136223846793005ULL + 1442695040888963407ULL; return (unsigned)(rng_state >> 32); }
static unsigned arena_ptr(void) { return ARENA_BASE + ARENA_PTR_LO + ((rnd32() % (ARENA_SIZE - 2 * ARENA_PTR_LO)) & ~3u); }

static int tiny, graph;   /* graph: the arena is mostly pointers to itself (a linked structure a function can walk two or three levels deep) */
static int narrow;   /* FNFUZZ_PROFILE=narrow: small integers only (no wild indexes into tables), so a difference in behaviour is a difference in the code, not in an out-of-range read */
/* GL enumerants / small values the state functions switch on: a random integer almost never selects a real case, so a share of the integer parameters is drawn from this pool */
static const unsigned gl_enums[] = { 0,1,2,3,4,5,6,7,8,9,10,0x1f00,0x1f01,0x1f02,0x1f03,0x8b8c,0x0de1,0x806f,0x8513,0x84f5,0x1700,0x1701,0x1702,0x1800,0x1801,0x1900,0x1901,0x1902,0x1903,0x1904,0x1905,0x1906,0x1907,0x1908,
    0x1400,0x1401,0x1402,0x1403,0x1404,0x1405,0x1406,0x8892,0x8893,0x8b30,0x8b31,0x84c0,0x84c1,0x84c2,0x84c3,0x84df,0x0404,0x0405,0x0408,0x0200,0x0201,0x0204,0x0207,0x0300,0x0301,0x0302,0x0303,0x0304,0x0305,0x0306,
    0x0be2,0x0b71,0x0b44,0x0b50,0x0b57,0x0bd0,0x0c11,0x0ba2,0x0cf5,0x0d05,0x0d33,0x0d50,0x2300,0x2301,0x2200,0x2201,0x2800,0x2801,0x2802,0x2803,0x812f,0x8370,0x2901,0x2900,0x1e00,0x1e01,0x1e02,0x2100,0x2101,0x2102,0x2103,
    0x8e8c,0x8d40,0x8d41,0x8d00,0x8ce0,0x8c40,0x8c41,0x80e1,0x80e0,0x84e8,0x851a,0x8519,0x0c01,0x0c02,0x0c03,0x0c08,0x0c10,0x8078,0x8079,0x807a,0x807b,0x8074,0x8075,0x8076,0x8077,0x0b90,0x0b91,0x0b92,0x1d00,0x1d01,
    0x8620,0x8800,0x8804,0x8bc0,0x864b,0xffffffffu };
static unsigned gen_int(void) {
    unsigned k = rnd32() % 20;
    if (getenv("CTXFUZZ_NOENUMS") == NULL && rnd32() % 100 < 38) return gl_enums[rnd32() % (sizeof gl_enums / sizeof gl_enums[0])];
    if (tiny) { if (k < 5) return 0; if (k < 14) return 1 + rnd32() % 15; if (k < 17) return arena_ptr(); return (unsigned)-(int)(1 + rnd32() % 3); }
    if (narrow) { if (k < 5) return 0; if (k < 10) return 1 + rnd32() % 16; if (k < 12) return 1u << (rnd32() % 16); if (k < 14) return (1u << (rnd32() % 16)) - 1; if (k < 17) return arena_ptr(); if (k < 19) return (unsigned)-(int)(1 + rnd32() % 8); return rnd32() % 256; }
    if (k < 5) return 0;
    if (k < 9) return 1 + rnd32() % 16;
    if (k < 11) return 1u << (rnd32() % 32);
    if (k < 12) return (1u << (rnd32() % 32)) - 1;
    if (k < 15) return rnd32();
    if (k < 17) return arena_ptr();
    if (k < 19) return (unsigned)-(int)(1 + rnd32() % 16);
    return rnd32() % 4096;
}
static double gen_double(int single) {
    unsigned k = rnd32() % 16; double v;
    if (k < 3) v = 0; else if (k < 5) v = 1; else if (k < 6) v = -1; else if (k < 9) v = ((int)(rnd32() % 2001) - 1000) / 64.0;
    else if (k < 11) v = ((int)(rnd32() % 200001) - 100000) / 7.0; else if (k < 13) v = 0.5; else if (k < 14) v = 1e-6 * (rnd32() % 1000); else v = ((int)(rnd32() % 65) - 32) * 0.25;
    return single ? (double)(float)v : v;
}

static unsigned long long fnv(const unsigned char *p, size_t n, unsigned long long h) { while (n--) { h ^= *p++; h *= 1099511628211ULL; } return h; }

static int wfd; static const struct mach_header *img_hdr[2];
static unsigned rng_lo[16], rng_hi[16]; static int nrng;
static int in_image(unsigned v) { if (v >= 0xbf000000u && v < 0xc0000000u) return 1;   /* stack addresses differ between the images' frame layouts */
    for (int i = 0; i < nrng; i++) if (v >= rng_lo[i] && v < rng_hi[i]) return 1; return 0; }
static void image_ranges(const struct mach_header *mh) {   /* every segment of an image (slid): text AND data, whatever their distance; called for BOTH images, so a word that looks like an address of either is normalised the same way in both runs */
    const struct load_command *lc = (const struct load_command *)(mh + 1); unsigned tv = 0; int haveT = 0;
    for (unsigned i = 0; i < mh->ncmds; i++, lc = (const struct load_command *)((const char *)lc + lc->cmdsize))
        if (lc->cmd == LC_SEGMENT) { const struct segment_command *sg = (const struct segment_command *)lc; if (!strcmp(sg->segname, "__TEXT")) { tv = sg->vmaddr; haveT = 1; } }
    unsigned slide = (unsigned)mh - (haveT ? tv : 0); lc = (const struct load_command *)(mh + 1);
    for (unsigned i = 0; i < mh->ncmds && nrng < 16; i++, lc = (const struct load_command *)((const char *)lc + lc->cmdsize))
        if (lc->cmd == LC_SEGMENT) { const struct segment_command *sg = (const struct segment_command *)lc; if (sg->vmsize && strcmp(sg->segname, "__PAGEZERO")) { rng_lo[nrng] = sg->vmaddr + slide; rng_hi[nrng] = sg->vmaddr + slide + sg->vmsize; nrng++; } }
}
static void report(int status, unsigned r3, unsigned r4, unsigned long long f1) {
    unsigned *w = (unsigned *)ARENA_BASE; unsigned long long h = 1469598103934665603ULL;
    for (unsigned i = 0; i < ARENA_SIZE / 4; i++) { unsigned v = w[i]; if (in_image(v)) v = 0x1A6E0001; h = fnv((unsigned char *)&v, 4, h); }
    result_t r; memset(&r, 0, sizeof r);
    { unsigned *lg = (unsigned *)LOG_BASE; unsigned cur = lg[0]; unsigned n = cur >= LOG_BASE + 16 ? (cur - LOG_BASE - 16) / 72 : 0; unsigned long long h1 = 1469598103934665603ULL, h2 = h1;
      r.logn = n; if (n > 900) n = 900;
      for (unsigned e = 0; e < n; e++) { unsigned *en = lg + 4 + e * 18; unsigned id = en[0], r3v = in_image(en[1]) ? 0x1A6E0002 : en[1];
          h1 = fnv((unsigned char *)&id, 4, h1); h1 = fnv((unsigned char *)&r3v, 4, h1);
          for (int q = 2; q < 18; q++) { unsigned v = in_image(en[q]) ? 0x1A6E0003 : en[q]; if (q >= 10) v = en[q]; h2 = fnv((unsigned char *)&v, 4, h2); }
          if (e < 8) { r.ent[e][0] = id; r.ent[e][1] = r3v; for (int q = 2; q < 18; q++) r.ent[e][q] = in_image(en[q]) ? 0x1A6E0003 : en[q]; } }
      r.dig_ids = (unsigned)(h1 ^ (h1 >> 32)); r.dig_soft = (unsigned)(h2 ^ (h2 >> 32)); }
    r.status = status; r.r3 = in_image(r3) ? 0x1A6E0002 : r3; r.r4 = r4; r.f1 = f1; r.digest = (unsigned)(h ^ (h >> 32)); memcpy(r.args, cur_args, sizeof r.args); memcpy(r.dargs, cur_dargs, sizeof r.dargs);
    (void)!write(wfd, &r, sizeof r);
    if (getenv("FNFUZZ_VERBOSE")) { for (unsigned i = 0; i < ARENA_SIZE / 4; i++) { unsigned v = w[i]; if (in_image(v)) v = 0x1A6E0001; (void)!write(wfd, &v, 4); } }
    _exit(0);
}
static void on_sig(int s) { report(s, 0, 0, 0); }

static unsigned alarm_us = 300000;
static int nohandlers;
/* FNFUZZ_STACKFILL=<hex word>: write that word over the 32 KB of stack below the harness's frame right before the call. A function that reads a stack slot it never wrote
   (a descriptor struct with fields it leaves alone, a callee that reads more than its caller sets) sees residue of the harness's earlier calls, which differs between the images' frame
   layouts; filling makes the residue a known value in both, so only a difference in what the function itself writes or reads is left. */
static int stackfill_set; static unsigned stackfill_word;
static void __attribute__((noinline)) fill_stack(void) { volatile unsigned buf[8192]; for (int i = 0; i < 8192; i++) buf[i] = stackfill_word; }
static void child(void *fn, const cand_t *c, unsigned seed, int mode) {
    if (!nohandlers) {
        ualarm(alarm_us, 0);   /* a pure function finishes in microseconds; anything longer is a hang (both images are treated alike) */
        signal(SIGSEGV, on_sig); signal(SIGBUS, on_sig); signal(SIGILL, on_sig); signal(SIGFPE, on_sig); signal(SIGTRAP, on_sig); signal(SIGABRT, on_sig); signal(SIGALRM, on_sig); signal(SIGSYS, on_sig);
    }
    void *m = mmap((void *)ARENA_BASE, ARENA_SIZE, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANON | MAP_PRIVATE, -1, 0);
    if (m != (void *)ARENA_BASE) _exit(9);
    rng_state = (unsigned long long)seed * 2862933555777941757ULL + c->id;
    unsigned *w = (unsigned *)ARENA_BASE;
    for (unsigned i = 0; i < ARENA_SIZE / 4; i++) { unsigned k = rnd32() % 10; w[i] = graph ? (k < 2 ? 0 : k < 4 ? rnd32() % 64 : arena_ptr()) : tiny ? (k < 6 ? 0 : k < 9 ? rnd32() % 16 : arena_ptr()) : (k < 3 ? 0 : k < 6 ? rnd32() % 64 : k < 7 ? (narrow ? rnd32() % 256 : rnd32()) : arena_ptr()); }
    unsigned ia[8]; double da[13]; int k = 0, j = 0;
    for (const char *p = c->pc; *p && *p != '-'; p++) {
        switch (*p) {
        case 'p': if (k < 8) ia[k] = arena_ptr(); k++; break;
        case 'i': if (k < 8) ia[k] = (k == 0 && rnd32() % 3 == 0) ? arena_ptr() : gen_int(); k++; break;
        case 'n': if (k < 8) { unsigned v; do v = gen_int(); while (v >= ARENA_BASE && v < ARENA_BASE + ARENA_SIZE); ia[k] = v; } k++; break;   /* a definite integer: no arena pointers (a table index made of an address reads wherever the image's layout puts it) */
        case 'L': if (k < 8) ia[k] = gen_int(); if (k + 1 < 8) ia[k + 1] = gen_int(); k += 2; break;
        case 'f': if (j < 13) da[j] = gen_double(1); j++; k += 1; break;
        case 'd': if (j < 13) da[j] = gen_double(getenv("FNFUZZ_FLOATARGS") != NULL); j++; k += 2; break;   /* FNFUZZ_FLOATARGS=1: only float-valued doubles (see fnfuzz.c) */
        }
    }
    for (int q = (k < 8 ? k : 8); q < 8; q++) ia[q] = gen_int();
    for (int q = (j < 13 ? j : 13); q < 13; q++) da[q] = gen_double(0);
    {   /* hand-built context: the slots */
        unsigned *lg = (unsigned *)LOG_BASE; lg[0] = LOG_BASE + 16; { unsigned rv[4] = { 0, 1, 0xffffffffu, ARENA_BASE + 0x3000 }; unsigned rr = rnd32(); lg[1] = rv[(rr >> 3) & 3];
          /* what a callee leaves in r4 and f1 besides r3 (a 64-bit result, a float result, or a register the caller reads after the call): seeded, distinctive values, so that a rebuilt function reading a call's r4 / f1 from an uninitialised local differs from the stock (CTXFUZZ_PLAINRET=1: the old constants 0 / 0.0) */
          unsigned rv4[4] = { 0, 1, 0xffffffffu, ARENA_BASE + 0x2000 }; double fv[4] = { 0.0, 1.0, -2.5, 123456.75 }; int plain = getenv("CTXFUZZ_PLAINRET") != NULL;
          unsigned *xr = (unsigned *)(LOG_BASE + 0x10000); xr[0] = plain ? 0 : rv4[(rr >> 7) & 3]; { double dv = plain ? 0.0 : fv[(rr >> 11) & 3]; memcpy(xr + 2, &dv, 8); } }
        int nblk = 0; unsigned blk_of[64][2]; int nblkmap = 0;
        for (int i = 0; i < c->nind; i++) {
            int p = c->ind[i].p; if (p < 0 || p > 1) continue;
            unsigned base = ARENA_BASE + 0x1000 + p * CTX_BASE_STEP; ia[p] = base;
            unsigned at = base + c->ind[i].off[0];
            for (int d = 1; d < c->ind[i].n; d++) {
                if (at + 4 > ARENA_BASE + ARENA_SIZE || at < ARENA_BASE) { at = 0; break; }
                unsigned *slot = (unsigned *)at, bp = 0;
                for (int q = 0; q < nblkmap; q++) if (blk_of[q][0] == at) bp = blk_of[q][1];
                if (!bp) { if (nblk >= 24) { at = 0; break; } bp = ARENA_BASE + BLOCK_BASE + 0x800 * nblk++; blk_of[nblkmap][0] = at; blk_of[nblkmap][1] = bp; nblkmap++; *slot = bp; }
                else *slot = bp;
                if (c->ind[i].off[d] >= 0x800) { at = 0; break; }
                at = bp + c->ind[i].off[d];
            }
            if (at && at + 4 <= ARENA_BASE + ARENA_SIZE) *(unsigned *)at = STUB_BASE + 32 * (i < 63 ? i : 63);
        }
    }
    /* the 9th..12th integer words of the call are the caller-stack words at SP+0x38..0x44 (Darwin PPC); a function with more than 8 integer parameters (or reading its caller's frame) must see defined values, not the harness's stack residue, which differs between the images */
    unsigned sa[16]; for (int q = 0; q < 16; q++) { unsigned k4 = rnd32() % 4; sa[q] = k4 == 0 ? 0 : k4 < 3 ? arena_ptr() : gen_int(); }
    memcpy(cur_args, ia, sizeof cur_args); memcpy(cur_dargs, da, sizeof cur_dargs);
    { const char *sf = getenv("FNFUZZ_STACKFILL"); if (sf) { stackfill_word = (unsigned)strtoul(sf, NULL, 16); fill_stack(); } }
    if (mode == 0) { unsigned long long r = ((fi_t)fn)(ia[0], ia[1], ia[2], ia[3], ia[4], ia[5], ia[6], ia[7], sa[0], sa[1], sa[2], sa[3], sa[4], sa[5], sa[6], sa[7], sa[8], sa[9], sa[10], sa[11], sa[12], sa[13], sa[14], sa[15], da[0], da[1], da[2], da[3], da[4], da[5], da[6], da[7], da[8], da[9], da[10], da[11], da[12]); report(0, (unsigned)(r >> 32), (unsigned)r, 0); }
    else { double r = ((fd_t)fn)(ia[0], ia[1], ia[2], ia[3], ia[4], ia[5], ia[6], ia[7], sa[0], sa[1], sa[2], sa[3], sa[4], sa[5], sa[6], sa[7], sa[8], sa[9], sa[10], sa[11], sa[12], sa[13], sa[14], sa[15], da[0], da[1], da[2], da[3], da[4], da[5], da[6], da[7], da[8], da[9], da[10], da[11], da[12]); unsigned long long b; memcpy(&b, &r, 8); report(0, 0, 0, b); }
}

static unsigned *last_arena[3];
static int run_one(void *fn, const cand_t *c, unsigned seed, int mode, int img, result_t *out) {
    int fd[2]; if (pipe(fd)) return -1;
    fflush(stdout);   /* a child that calls exit() would flush the parent's pending lines a second time */
    pid_t p = fork();
    if (p == 0) { close(fd[0]); wfd = fd[1]; nrng = 0; image_ranges(img_hdr[0]); image_ranges(img_hdr[1]); child(fn, c, seed, mode); _exit(8); }
    close(fd[1]);
    int st = 0; ssize_t n;
    {   /* watchdog: a child stuck where signals cannot reach it (a mutex the random arena left locked) is killed and counted as a hang */
        fd_set rs; FD_ZERO(&rs); FD_SET(fd[0], &rs); struct timeval tv = { 1 + alarm_us / 1000000, 0 };
        if (select(fd[0] + 1, &rs, NULL, NULL, &tv) <= 0) { kill(p, SIGKILL); waitpid(p, &st, 0); close(fd[0]); memset(out, 0, sizeof *out); out->status = 14; return 0; }
    }
    n = read(fd[0], out, sizeof *out);
    if (getenv("FNFUZZ_VERBOSE") && n == (ssize_t)sizeof *out) { static unsigned buf[3][ARENA_SIZE / 4]; unsigned *dst = buf[img]; size_t got = 0; ssize_t k; while (got < ARENA_SIZE && (k = read(fd[0], (char *)dst + got, ARENA_SIZE - got)) > 0) got += k; last_arena[img] = dst; }
    close(fd[0]); waitpid(p, &st, 0);
    if (n != (ssize_t)sizeof *out) { memset(out, 0, sizeof *out); out->status = WIFSIGNALED(st) ? WTERMSIG(st) : 99; }
    return 0;
}

static int same(const result_t *a, const result_t *b, char rc) {
    if ((a->status != 0) != (b->status != 0)) return 0;
    if (a->status) return 1;                       /* both died (SIGBUS vs SIGSEGV is only the kind of wild address) */
    if (a->digest != b->digest) return 0;
    if (a->logn != b->logn || a->dig_ids != b->dig_ids) return 0;
    if (rc == 'i') return a->r3 == b->r3;
    if (rc == 'd') { double x, y; memcpy(&x, &a->f1, 8); memcpy(&y, &b->f1, 8); return a->f1 == b->f1 || (x != x && y != y) || fabs(x - y) <= 1e-5 * fmax(1.0, fmax(fabs(x), fabs(y))); }
    return 1;
}

int main(int argc, char **argv) {
    if (argc < 4) { fprintf(stderr, "usage: fnfuzz LEDGER.tsv STOCK REBUILT [trials] [filter|@first,count]\n"); return 2; }
    narrow = getenv("FNFUZZ_PROFILE") && (!strcmp(getenv("FNFUZZ_PROFILE"), "narrow") || !strcmp(getenv("FNFUZZ_PROFILE"), "tiny")); tiny = getenv("FNFUZZ_PROFILE") && !strcmp(getenv("FNFUZZ_PROFILE"), "tiny"); graph = getenv("FNFUZZ_PROFILE") && !strcmp(getenv("FNFUZZ_PROFILE"), "graph");
    int trials = argc > 4 ? atoi(argv[4]) : 12; const char *flt = argc > 5 ? argv[5] : NULL;
    FILE *f = fopen(argv[1], "r"); if (!f) { perror(argv[1]); return 2; }
    char line[1024], anchor[96]; unsigned a_stock = 0, a_reb = 0;
    cand_t *cs = calloc(8192, sizeof *cs); int nc = 0;
    while (fgets(line, sizeof line, f)) {
        if (line[0] == '#') { sscanf(line, "#anchor\t%95s\t%x\t%x", anchor, &a_stock, &a_reb); continue; }
        cand_t *c = &cs[nc]; char rc[4]; int id;
        char indcol[600] = "-";
        if (sscanf(line, "%d\t%95s\t%x\t%x\t%d\t%23s\t%3s\t%599s", &id, c->name, &c->stock_addr, &c->reb_off, &c->size, c->pc, rc, indcol) >= 7) { c->id = id; c->rc = rc[0];
            for (char *tok = strtok(indcol, ","); tok && c->nind < 24; tok = strtok(NULL, ",")) { if (tok[0] == '-') break;
                int p = 0, n = 0; unsigned o[3] = { 0, 0, 0 }; char *q = tok; p = strtol(q, &q, 10); while (*q == ':' && n < 3) { o[n++] = strtoul(q + 1, &q, 16); }
                if (n) { c->ind[c->nind].p = p; c->ind[c->nind].n = n; memcpy(c->ind[c->nind].off, o, sizeof o); c->nind++; } }
            nc++; }
    }
    fclose(f);
    void *L[2] = { dlopen(argv[2], RTLD_NOW | RTLD_LOCAL), dlopen(argv[3], RTLD_NOW | RTLD_LOCAL) };
    if (!L[0] || !L[1]) { fprintf(stderr, "dlopen: %s\n", dlerror()); return 2; }
    const char *an = anchor[0] == '_' ? anchor + 1 : anchor;
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    if (!ap[0] || !ap[1]) { fprintf(stderr, "anchor %s not found\n", an); return 2; }
    setup_stubs();
    Dl_info di; dladdr((void *)ap[0], &di); img_hdr[0] = (const struct mach_header *)di.dli_fbase; dladdr((void *)ap[1], &di); img_hdr[1] = (const struct mach_header *)di.dli_fbase;
    int first = 0, count = nc; if (flt && flt[0] == '@') sscanf(flt + 1, "%d,%d", &first, &count);
    if (getenv("FNFUZZ_ONE")) {   /* FNFUZZ_ONE=S|R:trial - run the first matching function in THIS process (no handlers): for gdb. e.g. FNFUZZ_ONE=R:3 gdb --args fnfuzz ... name */
        int img = getenv("FNFUZZ_ONE")[0] == 'R', t = atoi(getenv("FNFUZZ_ONE") + 2);
        for (int i = first; i < nc; i++) { cand_t *c = &cs[i]; if (flt && flt[0] != '@' && !strstr(c->name, flt)) continue;
            void *fnp = (void *)(ap[img] + ((img ? c->reb_off : c->stock_addr) - (img ? a_reb : a_stock)));
            nrng = 0; image_ranges(img_hdr[0]); image_ranges(img_hdr[1]); nohandlers = 1; wfd = open("/dev/null", 1);
            printf("%s %s at %p trial %d\n", img ? "rebuilt" : "stock", c->name, fnp, t); fflush(stdout);
            child(fnp, c, 0x9e3779b1u * (t + 1) + c->id * 7919u, c->rc == 'd'); return 0; }
    }
    int ncomp = 0, ndiff = 0, nuninf = 0, nnondet = 0, ntrials = 0, nboth_crash = 0;
    for (int i = first; i < nc && i < first + count; i++) {
        cand_t *c = &cs[i]; if (flt && flt[0] != '@' && !strstr(c->name, flt)) continue;
        void *fn[2] = { (void *)(ap[0] + (c->stock_addr - a_stock)), (void *)(ap[1] + (c->reb_off - a_reb)) };
        int diffs = 0, good = 0, crash2 = 0, nd = 0; char why[700] = ""; int nargdiff = 0, nstub = 0;
        for (int t = 0; t < trials; t++) {
            unsigned seed = 0x9e3779b1u * (t + 1) + c->id * 7919u;
            result_t a, a2, b;
            for (int mode = 0; mode < (c->rc == 'd' ? 2 : 1); mode++) {
                if (c->rc == 'd' && mode == 0) { /* the digest is checked in the integer-return run, f1 in the second */ }
                run_one(fn[0], c, seed, mode, 0, &a);
                run_one(fn[0], c, seed, mode, 0, &a2);
                run_one(fn[1], c, seed, mode, 1, &b);
                ntrials++; if (mode == 0 && a.logn) nstub++;
                if (!same(&a, &a2, c->rc)) { nd++; continue; }
                if ((a.status == 14) != (b.status == 14)) {   /* a hang on one side only: the -O0 rebuild is several times slower than the -O2 stock on a long loop (`_pow_10(0x5000ec80)`), and machine load adds to it - rerun both with a 6 s limit before blaming the code */
                    alarm_us = 6000000; run_one(fn[0], c, seed, mode, 0, &a); run_one(fn[1], c, seed, mode, 1, &b); alarm_us = 300000;
                }
                if (a.status && b.status && a.status == b.status) crash2++;
                if (same(&a, &b, mode ? 'd' : (c->rc == 'd' ? 'v' : c->rc))) { good++; if (a.status == 0 && a.dig_soft != b.dig_soft && a.logn) nargdiff++; }
                else { diffs++;
                    if (getenv("FNFUZZ_VERBOSE") && last_arena[0] && last_arena[1] && diffs <= 2) { int nd2 = 0; for (unsigned q = 0; q < ARENA_SIZE / 4 && nd2 < 10; q++) if (last_arena[0][q] != last_arena[1][q]) { printf("   arena+%05x: stock %08x rebuilt %08x\n", q * 4, last_arena[0][q], last_arena[1][q]); nd2++; } }
                    if (!why[0]) snprintf(why, sizeof why, "trial %d mode %d: stock st=%d r3=%08x f1=%016llx dg=%08x | rebuilt st=%d r3=%08x f1=%016llx dg=%08x | args %x %x %x %x %x", t, mode, a.status, a.r3, a.f1, a.digest, b.status, b.r3, b.f1, b.digest, a.args[0], a.args[1], a.args[2], a.args[3], a.args[4]);
                    if (why[0] && !strstr(why, " calls ")) { size_t wl = strlen(why); int kk;
                        snprintf(why + wl, sizeof why - wl, " | calls stock %u rebuilt %u ids S:", a.logn, b.logn);
                        for (kk = 0; kk < 8 && kk < (int)a.logn; kk++) { wl = strlen(why); snprintf(why + wl, sizeof why - wl, "%u/%x ", a.ent[kk][0], a.ent[kk][1]); }
                        wl = strlen(why); snprintf(why + wl, sizeof why - wl, "R:");
                        for (kk = 0; kk < 8 && kk < (int)b.logn; kk++) { wl = strlen(why); snprintf(why + wl, sizeof why - wl, "%u/%x ", b.ent[kk][0], b.ent[kk][1]); } }
                }
            }
        }
        ncomp++;
        if (getenv("CTXFUZZ_STATS")) printf("STAT %-40s slots %d, trials reaching a stub %d of %d\n", c->name, c->nind, nstub, trials);
        if (nd == trials * (c->rc == 'd' ? 2 : 1)) { nnondet++; continue; }
        if (diffs) { ndiff++; printf("DIFF %-40s %x (%s->%c, %d trials: %d differ, %d agree) %s\n", c->name, c->stock_addr, c->pc, c->rc, trials, diffs, good, why); }
        else if (crash2 && good == crash2) { nuninf++; if (getenv("FNFUZZ_LISTUNINF")) printf("UNINF %-40s %x (%s->%c) every one of %d trials ended in a signal in both images\n", c->name, c->stock_addr, c->pc, c->rc, trials); }
        if (!diffs && nargdiff && getenv("CTXFUZZ_ARGINFO")) printf("INFO %-40s %x: register values passed to the stubs differ in %d of %d agreeing trials (leftovers or a missing argument: see argtriage)\n", c->name, c->stock_addr, nargdiff, good);
        nboth_crash += crash2;
    }
    printf("fnfuzz: %d functions, %d trials (each: stock twice + rebuilt); %d differ, %d uninformative (always the same signal), %d nondeterministic in the stock\nRESULT: %s\n",
           ncomp, ntrials, ndiff, nuninf, nnondet, ndiff == 0 ? "PASS" : "FAIL");
    return 0;
}
