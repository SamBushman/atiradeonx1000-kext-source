/* fnfuzz.c - pure-function differential test of a rebuilt userspace image against the stock one (issue #68, criterion 1).
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
#include <mach-o/nlist.h>

#define ARENA_BASE 0x50000000u
#define ARENA_SIZE 0x20000u
#define ARENA_PTR_LO 0x1000u

typedef unsigned long long (*fi_t)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, double, double, double, double, double, double, double, double, double, double, double, double, double);
typedef double (*fd_t)(unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned, double, double, double, double, double, double, double, double, double, double, double, double, double);

typedef struct { int status; unsigned r3, r4; unsigned long long f1; unsigned digest; unsigned args[8]; double dargs[4]; unsigned ncalls, trace, mask[5]; } result_t;   /* ncalls / trace / mask: import-interposer mode (FNFUZZ_INTERPOSE=1) */
static unsigned cur_args[8]; static double cur_dargs[4];
typedef struct { int id; char name[96]; unsigned stock_addr, reb_off; int size; char pc[24]; char rc; } cand_t;

static unsigned long long rng_state;
static unsigned rnd32(void) { rng_state = rng_state * 6364136223846793005ULL + 1442695040888963407ULL; return (unsigned)(rng_state >> 32); }
static unsigned arena_ptr(void) { return ARENA_BASE + ARENA_PTR_LO + ((rnd32() % (ARENA_SIZE - 2 * ARENA_PTR_LO)) & ~3u); }

static int tiny, graph;   /* graph: the arena is mostly pointers to itself (a linked structure a function can walk two or three levels deep) */
static int narrow;   /* FNFUZZ_PROFILE=narrow: small integers only (no wild indexes into tables), so a difference in behaviour is a difference in the code, not in an out-of-range read */
static unsigned gen_int(void) {
    unsigned k = rnd32() % 20;
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

/* ---- import interposer (FNFUZZ_INTERPOSE=1) -------------------------------------------------------------------------------------------------------------------------------
   The ledger of fnfuzz_gen.py FNFUZZ_IMPORTS=1 lists the functions the plain ledger had to leave out because they call an import. Here the library imports (Sh*, PP*, glg*, glp*, NS*, CF*, IO*, host_*,
   mach_*, sysctl, scandir, pthread_mutex_*) are replaced, in the child that runs the function, by recording stubs: every call is folded into a trace hash (import identity, the eight register
   arguments with image / stack addresses normalised, 16 bytes behind every argument that points into the arena) and answered with a value drawn from a per-trial PRNG that depends only on
   (seed, import, call number) - 0, a small integer, -1 or a pointer into a patterned 8 KB block outside the arena - so both images are fed the SAME answers as long as they make the same calls. What
   is compared on top of the plain result: the number of calls, the trace, the set of imports reached, and the block (a library structure the function may write to). Libc functions that are
   deterministic (malloc, free, memcpy, str*, ...) stay real. FNFUZZ_IMPORT_CTL=name makes the rebuilt side's stub for that import answer differently (a mismatch control: every function that
   calls it and uses the answer must then be reported). The slot tables come from the images' own indirect symbol tables: every lazy / non-lazy pointer whose symbol is in the stub class is overwritten. */
#define MAXSTUB 160
static int interpose, cur_img; static const char *imp_ctl;
static char stub_names[MAXSTUB][48]; static int nstub;
typedef struct { unsigned *slot; int idx; } slot_t;
static slot_t slots[2][512]; static int nslots[2];
static unsigned char retblk[0x2000];
static int nargs_tab[MAXSTUB];   /* FNFUZZ_IMPORT_NARGS=file (name<TAB>count, Tools/userspace/import_nargs.py): the argument registers a stub hashes; default 8 (r3..r10), which includes dead registers the images do not set alike */
static unsigned ncalls_c, trace_c, mask_c[5]; static unsigned long long ret_state;
static int stub_class(const char *n) {
    static const char *pre[] = { "Sh", "PP", "glg", "glp", "NS", "CF", "IO", "host_", "mach_", "sysctl", "scandir", "pthread_mutex_", NULL };
    if (*n == '_') n++;
    { size_t L = strlen(n); if (L && n[L - 1] == '_') return 0; }   /* mach_task_self_ is a DATA symbol (the stock binds its non-lazy slot to the variable; the rebuilt through an external relocation): never overwrite a data slot with a function */
    for (int i = 0; pre[i]; i++) if (!strncmp(n, pre[i], strlen(pre[i]))) return 1;
    return 0;
}
static int stub_index(const char *n) {
    if (*n == '_') n++;
    for (int i = 0; i < nstub; i++) if (!strcmp(stub_names[i], n)) return i;
    if (nstub >= MAXSTUB) { fprintf(stderr, "too many imports\n"); exit(2); }
    snprintf(stub_names[nstub], sizeof stub_names[0], "%s", n); return nstub++;
}
static void collect_slots(int img, const struct mach_header *mh) {
    const struct load_command *lc = (const struct load_command *)(mh + 1); unsigned tv = 0; int haveT = 0;
    const struct symtab_command *st = NULL; const struct dysymtab_command *dy = NULL; const struct segment_command *le = NULL;
    for (unsigned i = 0; i < mh->ncmds; i++, lc = (const struct load_command *)((const char *)lc + lc->cmdsize)) {
        if (lc->cmd == LC_SEGMENT) { const struct segment_command *sg = (const struct segment_command *)lc; if (!strcmp(sg->segname, "__TEXT")) { tv = sg->vmaddr; haveT = 1; } if (!strcmp(sg->segname, "__LINKEDIT")) le = sg; }
        if (lc->cmd == LC_SYMTAB) st = (const struct symtab_command *)lc;
        if (lc->cmd == LC_DYSYMTAB) dy = (const struct dysymtab_command *)lc;
    }
    if (!st || !dy || !le) { fprintf(stderr, "no symtab in image %d\n", img); exit(2); }
    unsigned slide = (unsigned)mh - (haveT ? tv : 0), lebase = le->vmaddr + slide - le->fileoff;
    const struct nlist *nl = (const struct nlist *)(lebase + st->symoff); const char *str = (const char *)(lebase + st->stroff); const unsigned *ind = (const unsigned *)(lebase + dy->indirectsymoff);
    lc = (const struct load_command *)(mh + 1);
    for (unsigned i = 0; i < mh->ncmds; i++, lc = (const struct load_command *)((const char *)lc + lc->cmdsize)) {
        if (lc->cmd != LC_SEGMENT) continue;
        const struct segment_command *sg = (const struct segment_command *)lc; const struct section *sc = (const struct section *)(sg + 1);
        for (unsigned k = 0; k < sg->nsects; k++, sc++) {
            unsigned ty = sc->flags & 0xff; if (ty != 6 && ty != 7) continue;
            for (unsigned q = 0; q < sc->size / 4; q++) {
                unsigned is = ind[sc->reserved1 + q]; if (is & 0xc0000000u) continue;
                const char *nm = str + nl[is].n_un.n_strx; if (!stub_class(nm) || nslots[img] >= 512) continue;
                slots[img][nslots[img]].slot = (unsigned *)(sc->addr + slide) + q; slots[img][nslots[img]].idx = stub_index(nm); nslots[img]++;
            }
        }
    }
}
static unsigned long long stub_common(int idx, unsigned *a) {
    unsigned h = trace_c ? trace_c : 2166136261u; h = (h ^ (unsigned)idx) * 16777619u;
    ncalls_c++; mask_c[idx >> 5] |= 1u << (idx & 31);
    { static int dump = -1; if (dump < 0) dump = getenv("FNFUZZ_IMPDUMP") != NULL; if (dump) { fprintf(stderr, "  [%s call %u] %s(%x %x %x %x %x %x %x %x)\n", cur_img ? "rebuilt" : "stock", ncalls_c, stub_names[idx], a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]); } }
    for (int i = 0; i < nargs_tab[idx]; i++) {
        unsigned v = a[i];
        if (v >= ARENA_BASE && v <= ARENA_BASE + ARENA_SIZE - 16) { h = (h ^ 0xA7E4A000u) * 16777619u; for (int k = 0; k < 16; k++) h = (h ^ ((unsigned char *)v)[k]) * 16777619u; }
        else { if (in_image(v)) v = 0x1A6E0001; h = (h ^ v) * 16777619u; }
    }
    trace_c = h;
    ret_state = ret_state * 6364136223846793005ULL + 1442695040888963407ULL + (unsigned)idx * 2654435761u + ncalls_c;
    unsigned k = (unsigned)(ret_state >> 40) % 20, r;
    if (k < 5) r = 0; else if (k < 7) r = 1; else if (k < 9) r = 2 + (unsigned)(ret_state >> 20) % 15; else if (k < 10) r = (unsigned)-1; else r = (unsigned)(uintptr_t)(retblk + (((unsigned)(ret_state >> 16) % 0x1000) & ~3u));
    int ctl = cur_img == 1 && imp_ctl && !strcmp(stub_names[idx], imp_ctl);
    if (ctl) r = ~r ^ 0x1234;
    /* out parameters: the library writes results through pointer arguments (ShGetUniformTypeInfo(.., &type, &size)); a caller that reads them must see defined values, not stack residue. Every argument that is a
       word-aligned stack address gets ONE word from the PRNG (a small value: types, counts, indexes), the same in both images; an arena pointer too (the arena digest compares what the function does with it) */
    for (int i = 0; i < nargs_tab[idx]; i++) {
        unsigned v = a[i];
        if ((v & 3) == 0 && ((v >= 0xbf000000u && v < 0xbffffff0u) || (v >= ARENA_BASE && v <= ARENA_BASE + ARENA_SIZE - 4))) {
            ret_state = ret_state * 6364136223846793005ULL + 1442695040888963407ULL; unsigned w = (unsigned)(ret_state >> 44) % 12; if (ctl) w = w * 7 + 5; *(unsigned *)v = w;
        }
    }
    return r;
}
#define S1(n) static unsigned long long stb##n(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g, unsigned h) { unsigned v[8] = { a, b, c, d, e, f, g, h }; return stub_common(n, v); }
#define R10(p) S1(p##0) S1(p##1) S1(p##2) S1(p##3) S1(p##4) S1(p##5) S1(p##6) S1(p##7) S1(p##8) S1(p##9)
S1(0) S1(1) S1(2) S1(3) S1(4) S1(5) S1(6) S1(7) S1(8) S1(9) R10(1) R10(2) R10(3) R10(4) R10(5) R10(6) R10(7) R10(8) R10(9) R10(10) R10(11) R10(12) R10(13) R10(14) R10(15)
#define T1(n) (void *)stb##n,
#define T10(p) T1(p##0) T1(p##1) T1(p##2) T1(p##3) T1(p##4) T1(p##5) T1(p##6) T1(p##7) T1(p##8) T1(p##9)
static void *stub_fns[MAXSTUB] = { T1(0) T1(1) T1(2) T1(3) T1(4) T1(5) T1(6) T1(7) T1(8) T1(9) T10(1) T10(2) T10(3) T10(4) T10(5) T10(6) T10(7) T10(8) T10(9) T10(10) T10(11) T10(12) T10(13) T10(14) T10(15) };
static void install_stubs(int img) { for (int i = 0; i < nslots[img]; i++) *slots[img][i].slot = (unsigned)(uintptr_t)stub_fns[slots[img][i].idx]; }
static void load_nargs(void) {
    for (int i = 0; i < MAXSTUB; i++) nargs_tab[i] = 8;
    const char *fn = getenv("FNFUZZ_IMPORT_NARGS"); if (!fn) return; FILE *f = fopen(fn, "r"); if (!f) { perror(fn); exit(2); }
    char l[160], n[96]; int k, got = 0;
    while (fgets(l, sizeof l, f)) if (sscanf(l, "%95s %d", n, &k) == 2) for (int i = 0; i < nstub; i++) if (!strcmp(stub_names[i], n)) { nargs_tab[i] = k > 8 ? 8 : k; got++; }
    fclose(f); fprintf(stderr, "interposer: argument counts for %d of %d imports\n", got, nstub);
}
static void init_retblk(void) { unsigned *w = (unsigned *)retblk; unsigned long long x = 88172645463325252ULL; for (unsigned i = 0; i < sizeof retblk / 4; i++) { x ^= x << 13; x ^= x >> 7; x ^= x << 17; unsigned k = (unsigned)(x >> 32) % 8; w[i] = k < 2 ? 0 : k < 6 ? (unsigned)(x >> 40) % 64 : (unsigned)(uintptr_t)(retblk + (((unsigned)(x >> 36) % 0x1ff0) & ~3u)); } }

static void report(int status, unsigned r3, unsigned r4, unsigned long long f1) {
    unsigned *w = (unsigned *)ARENA_BASE; unsigned long long h = 1469598103934665603ULL;
    for (unsigned i = 0; i < ARENA_SIZE / 4; i++) { unsigned v = w[i]; if (in_image(v)) v = 0x1A6E0001; h = fnv((unsigned char *)&v, 4, h); }
    if (interpose) for (unsigned i = 0; i < sizeof retblk / 4; i++) { unsigned v = ((unsigned *)retblk)[i]; if (v >= (unsigned)(uintptr_t)retblk && v < (unsigned)(uintptr_t)retblk + sizeof retblk) v = 0x1A6E0003; h = fnv((unsigned char *)&v, 4, h); }
    result_t r; memset(&r, 0, sizeof r); r.ncalls = ncalls_c; r.trace = trace_c; memcpy(r.mask, mask_c, sizeof r.mask); r.status = status; r.r3 = in_image(r3) ? 0x1A6E0002 : r3; r.r4 = r4; r.f1 = f1; r.digest = (unsigned)(h ^ (h >> 32)); memcpy(r.args, cur_args, sizeof r.args); memcpy(r.dargs, cur_dargs, sizeof r.dargs);
    (void)!write(wfd, &r, sizeof r);
    if (getenv("FNFUZZ_VERBOSE")) { for (unsigned i = 0; i < ARENA_SIZE / 4; i++) { unsigned v = w[i]; if (in_image(v)) v = 0x1A6E0001; (void)!write(wfd, &v, 4); } }
    _exit(0);
}
static void on_sig(int s) { report(s, 0, 0, 0); }

/* FNFUZZ_STACKFILL=<hex word>: write that word over the 32 KB of stack below the harness's frame right before the call. A function that reads a stack slot it never wrote
   (a descriptor struct with fields it leaves alone, a callee that reads more than its caller sets) sees residue of the harness's earlier calls, which differs between the images' frame
   layouts; filling makes the residue a known value in both, so only a difference in what the function itself writes or reads is left. */
static int stackfill_set; static unsigned stackfill_word;
static void __attribute__((noinline)) fill_stack(void) { volatile unsigned buf[8192]; for (int i = 0; i < 8192; i++) buf[i] = stackfill_word; }
static unsigned alarm_us = 300000;
static int nohandlers;
static void child(void *fn, const cand_t *c, unsigned seed, int mode) {
    if (!nohandlers) {
        ualarm(alarm_us, 0);   /* a pure function finishes in microseconds; anything longer is a hang (both images are treated alike) */
        signal(SIGSEGV, on_sig); signal(SIGBUS, on_sig); signal(SIGILL, on_sig); signal(SIGFPE, on_sig); signal(SIGTRAP, on_sig); signal(SIGABRT, on_sig); signal(SIGALRM, on_sig); signal(SIGSYS, on_sig);
    }
    void *m = mmap((void *)ARENA_BASE, ARENA_SIZE, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANON | MAP_PRIVATE, -1, 0);
    if (m != (void *)ARENA_BASE) _exit(9);
    rng_state = (unsigned long long)seed * 2862933555777941757ULL + c->id;
    if (interpose) { ncalls_c = 0; trace_c = 0; memset(mask_c, 0, sizeof mask_c); ret_state = (unsigned long long)seed * 0x9E3779B97F4A7C15ULL + c->id; install_stubs(cur_img); }
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
        case 'd': if (j < 13) da[j] = gen_double(getenv("FNFUZZ_FLOATARGS") != NULL); j++; k += 2; break;   /* FNFUZZ_FLOATARGS=1: only float-valued doubles (an ABI-valid argument of a float parameter the corpus declares double) */
        }
    }
    for (int q = (k < 8 ? k : 8); q < 8; q++) ia[q] = gen_int();
    for (int q = (j < 13 ? j : 13); q < 13; q++) da[q] = gen_double(0);
    /* the 9th..12th integer words of the call are the caller-stack words at SP+0x38..0x44 (Darwin PPC); a function with more than 8 integer parameters (or reading its caller's frame) must see defined values, not the harness's stack residue, which differs between the images */
    unsigned sa[16]; for (int q = 0; q < 16; q++) { unsigned k4 = rnd32() % 4; sa[q] = k4 == 0 ? 0 : k4 < 3 ? arena_ptr() : gen_int(); }
    memcpy(cur_args, ia, sizeof cur_args); memcpy(cur_dargs, da, sizeof cur_dargs);
    if (getenv("FNFUZZ_LISTCTX")) {
        /* FNFUZZ_LISTCTX=1: parameter 0 is a valid display-list context (the shape gleng_mock_listitem.c builds): a zeroed 0x8000-byte ctx at arena+0x1000 whose +0x53e8 points at a list block H
           (+0x10 item count, +0x14 table of item sizes, +0x18 table capacity) with room for ~100 items, ctx+0x5400 = 0x1c bytes used, ctx+0x53fc = the buffer capacity. The _Comp functions
           (glList compilers: _gleAddListItem, then stores of the arguments) then run on a context they can use instead of garbage, where _gleAddListItem's realloc is the divergence. */
        unsigned char *ctx = (unsigned char *)ARENA_BASE + 0x1000, *H = (unsigned char *)ARENA_BASE + 0xa000; unsigned *T = (unsigned *)(ARENA_BASE + 0x12000);
        memset(ctx, 0, 0x8000); memset(H, 0, 0x8000); memset(T, 0, 0x1000);
        *(unsigned char **)(ctx + 0x53e8) = H; *(unsigned *)(ctx + 0x53fc) = 0x8000; *(unsigned *)(ctx + 0x5400) = 0x1c;
        *(unsigned *)(H + 0x10) = 0; *(unsigned **)(H + 0x14) = T; *(unsigned *)(H + 0x18) = 0x400;
        ia[0] = (unsigned)ctx;
    }
    { const char *sf = getenv("FNFUZZ_STACKFILL"); if (sf) { stackfill_word = (unsigned)strtoul(sf, NULL, 16); fill_stack(); } }
    if (mode == 0) { unsigned long long r = ((fi_t)fn)(ia[0], ia[1], ia[2], ia[3], ia[4], ia[5], ia[6], ia[7], sa[0], sa[1], sa[2], sa[3], sa[4], sa[5], sa[6], sa[7], sa[8], sa[9], sa[10], sa[11], sa[12], sa[13], sa[14], sa[15], da[0], da[1], da[2], da[3], da[4], da[5], da[6], da[7], da[8], da[9], da[10], da[11], da[12]); report(0, (unsigned)(r >> 32), (unsigned)r, 0); }
    else { double r = ((fd_t)fn)(ia[0], ia[1], ia[2], ia[3], ia[4], ia[5], ia[6], ia[7], sa[0], sa[1], sa[2], sa[3], sa[4], sa[5], sa[6], sa[7], sa[8], sa[9], sa[10], sa[11], sa[12], sa[13], sa[14], sa[15], da[0], da[1], da[2], da[3], da[4], da[5], da[6], da[7], da[8], da[9], da[10], da[11], da[12]); unsigned long long b; memcpy(&b, &r, 8); report(0, 0, 0, b); }
}

static unsigned *last_arena[3];
static int run_one(void *fn, const cand_t *c, unsigned seed, int mode, int img, result_t *out) {
    int fd[2]; if (pipe(fd)) return -1;
    fflush(stdout);   /* a child that calls exit() would flush the parent's pending lines a second time */
    pid_t p = fork();
    if (p == 0) { close(fd[0]); wfd = fd[1]; cur_img = img; nrng = 0; image_ranges(img_hdr[0]); image_ranges(img_hdr[1]); child(fn, c, seed, mode); _exit(8); }
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
    if (interpose && (a->ncalls != b->ncalls || a->trace != b->trace || memcmp(a->mask, b->mask, sizeof a->mask))) return 0;
    if (a->digest != b->digest) return 0;
    if (rc == 'i') return a->r3 == b->r3;
    if (rc == 'd') { double x, y; memcpy(&x, &a->f1, 8); memcpy(&y, &b->f1, 8); return a->f1 == b->f1 || (x != x && y != y) || fabs(x - y) <= 1e-5 * fmax(1.0, fmax(fabs(x), fabs(y))); }
    return 1;
}

int main(int argc, char **argv) {
    if (argc < 4) { fprintf(stderr, "usage: fnfuzz LEDGER.tsv STOCK REBUILT [trials] [filter|@first,count]\n"); return 2; }
    narrow = getenv("FNFUZZ_PROFILE") && (!strcmp(getenv("FNFUZZ_PROFILE"), "narrow") || !strcmp(getenv("FNFUZZ_PROFILE"), "tiny")); tiny = getenv("FNFUZZ_PROFILE") && !strcmp(getenv("FNFUZZ_PROFILE"), "tiny"); graph = getenv("FNFUZZ_PROFILE") && !strcmp(getenv("FNFUZZ_PROFILE"), "graph");
    int trials = argc > 4 ? atoi(argv[4]) : 12; const char *flt = argc > 5 ? argv[5] : NULL;
    FILE *f = fopen(argv[1], "r"); if (!f) { perror(argv[1]); return 2; }
    char line[512], anchor[96]; unsigned a_stock = 0, a_reb = 0;
    cand_t *cs = calloc(8192, sizeof *cs); int nc = 0;
    while (fgets(line, sizeof line, f)) {
        if (line[0] == '#') { sscanf(line, "#anchor\t%95s\t%x\t%x", anchor, &a_stock, &a_reb); continue; }
        cand_t *c = &cs[nc]; char rc[4]; int id;
        if (sscanf(line, "%d\t%95s\t%x\t%x\t%d\t%23s\t%3s", &id, c->name, &c->stock_addr, &c->reb_off, &c->size, c->pc, rc) == 7) { c->id = id; c->rc = rc[0]; nc++; }
    }
    fclose(f);
    void *L[2] = { dlopen(argv[2], RTLD_NOW | RTLD_LOCAL), dlopen(argv[3], RTLD_NOW | RTLD_LOCAL) };
    if (!L[0] || !L[1]) { fprintf(stderr, "dlopen: %s\n", dlerror()); return 2; }
    const char *an = anchor[0] == '_' ? anchor + 1 : anchor;
    unsigned long ap[2] = { (unsigned long)dlsym(L[0], an), (unsigned long)dlsym(L[1], an) };
    if (!ap[0] || !ap[1]) { fprintf(stderr, "anchor %s not found\n", an); return 2; }
    Dl_info di; dladdr((void *)ap[0], &di); img_hdr[0] = (const struct mach_header *)di.dli_fbase; dladdr((void *)ap[1], &di); img_hdr[1] = (const struct mach_header *)di.dli_fbase;
    interpose = getenv("FNFUZZ_INTERPOSE") != NULL; imp_ctl = getenv("FNFUZZ_IMPORT_CTL");
    if (interpose) { init_retblk(); collect_slots(0, img_hdr[0]); collect_slots(1, img_hdr[1]); load_nargs(); fprintf(stderr, "interposer: %d stock slots, %d rebuilt slots, %d distinct imports\n", nslots[0], nslots[1], nstub); }
    int first = 0, count = nc; if (flt && flt[0] == '@') sscanf(flt + 1, "%d,%d", &first, &count);
    if (getenv("FNFUZZ_ONE")) {   /* FNFUZZ_ONE=S|R:trial - run the first matching function in THIS process (no handlers): for gdb. e.g. FNFUZZ_ONE=R:3 gdb --args fnfuzz ... name */
        int img = getenv("FNFUZZ_ONE")[0] == 'R', t = atoi(getenv("FNFUZZ_ONE") + 2);
        for (int i = first; i < nc; i++) { cand_t *c = &cs[i]; if (flt && flt[0] != '@' && !strstr(c->name, flt)) continue;
            void *fnp = (void *)(ap[img] + ((img ? c->reb_off : c->stock_addr) - (img ? a_reb : a_stock)));
            cur_img = img; nrng = 0; image_ranges(img_hdr[0]); image_ranges(img_hdr[1]); nohandlers = 1; wfd = open("/dev/null", 1);
            printf("%s %s at %p trial %d\n", img ? "rebuilt" : "stock", c->name, fnp, t); fflush(stdout);
            child(fnp, c, 0x9e3779b1u * (t + 1) + c->id * 7919u, c->rc == 'd'); return 0; }
    }
    int nlive = 0, ncomp = 0, ndiff = 0, nuninf = 0, nnondet = 0, ntrials = 0, nboth_crash = 0;
    for (int i = first; i < nc && i < first + count; i++) {
        cand_t *c = &cs[i]; if (flt && flt[0] != '@' && !strstr(c->name, flt)) continue;
        void *fn[2] = { (void *)(ap[0] + (c->stock_addr - a_stock)), (void *)(ap[1] + (c->reb_off - a_reb)) };
        int diffs = 0, good = 0, crash2 = 0, nd = 0, live = 0; unsigned lmask[5] = { 0, 0, 0, 0, 0 }, lcalls = 0; char why[360] = "";
        for (int t = 0; t < trials; t++) {
            unsigned seed = 0x9e3779b1u * (t + 1) + c->id * 7919u;
            result_t a, a2, b;
            for (int mode = 0; mode < (c->rc == 'd' ? 2 : 1); mode++) {
                if (c->rc == 'd' && mode == 0) { /* the digest is checked in the integer-return run, f1 in the second */ }
                run_one(fn[0], c, seed, mode, 0, &a);
                run_one(fn[0], c, seed, mode, 0, &a2);
                run_one(fn[1], c, seed, mode, 1, &b);
                ntrials++;
                if (!same(&a, &a2, c->rc)) { nd++; continue; }
                if ((a.status == 14) != (b.status == 14)) {   /* a hang on one side only: the -O0 rebuild is several times slower than the -O2 stock on a long loop (`_pow_10(0x5000ec80)`), and machine load adds to it - rerun both with a 6 s limit before blaming the code */
                    alarm_us = 6000000; run_one(fn[0], c, seed, mode, 0, &a); run_one(fn[1], c, seed, mode, 1, &b); alarm_us = 300000;
                }
                if (a.status && b.status && a.status == b.status) crash2++;
                if (interpose && !a.status && !b.status && a.ncalls) { live++; lcalls += a.ncalls; for (int q = 0; q < 5; q++) lmask[q] |= a.mask[q]; }
                if (same(&a, &b, mode ? 'd' : (c->rc == 'd' ? 'v' : c->rc))) good++;
                else { diffs++;
                    if (getenv("FNFUZZ_VERBOSE") && last_arena[0] && last_arena[1] && diffs <= 2) { int nd2 = 0; for (unsigned q = 0; q < ARENA_SIZE / 4 && nd2 < 10; q++) if (last_arena[0][q] != last_arena[1][q]) { printf("   arena+%05x: stock %08x rebuilt %08x\n", q * 4, last_arena[0][q], last_arena[1][q]); nd2++; if (getenv("FNFUZZ_CONTEXT")) for (int c = (q >= 6 ? -6 : -(int)q); c < 7; c++) printf("      +%d: stock %08x rebuilt %08x\n", c * 4, last_arena[0][q + c], last_arena[1][q + c]); } }
                    if (!why[0]) snprintf(why, sizeof why, "trial %d mode %d: stock st=%d r3=%08x f1=%016llx dg=%08x | rebuilt st=%d r3=%08x f1=%016llx dg=%08x | args %x %x %x %x %x | dargs %016llx %016llx %016llx %016llx | calls %u/%u trace %08x/%08x mask %08x%08x/%08x%08x", t, mode, a.status, a.r3, a.f1, a.digest, b.status, b.r3, b.f1, b.digest, a.args[0], a.args[1], a.args[2], a.args[3], a.args[4], *(unsigned long long *)&a.dargs[0], *(unsigned long long *)&a.dargs[1], *(unsigned long long *)&a.dargs[2], *(unsigned long long *)&a.dargs[3], a.ncalls, b.ncalls, a.trace, b.trace, a.mask[1], a.mask[0], b.mask[1], b.mask[0]); }
            }
        }
        ncomp++;
        if (interpose) { char nm[1200] = ""; for (int q = 0; q < nstub; q++) if (lmask[q >> 5] & (1u << (q & 31))) { if (strlen(nm) + 60 < sizeof nm) { strcat(nm, " "); strcat(nm, stub_names[q]); } }
            printf("IMP %-40s live %d/%d trials, %u calls, imports:%s\n", c->name, live, trials, lcalls, nm[0] ? nm : " -"); if (live) nlive++; }
        if (nd == trials * (c->rc == 'd' ? 2 : 1)) { nnondet++; continue; }
        if (diffs) { ndiff++; printf("DIFF %-40s %x (%s->%c, %d trials: %d differ, %d agree) %s\n", c->name, c->stock_addr, c->pc, c->rc, trials, diffs, good, why); }
        else if (crash2 && good == crash2) { nuninf++; }
        nboth_crash += crash2;
    }
    if (interpose) printf("interposer: %d of %d functions reached at least one stubbed import in a trial that ended normally in both images\n", nlive, ncomp);
    printf("fnfuzz: %d functions, %d trials (each: stock twice + rebuilt); %d differ, %d uninformative (always the same signal), %d nondeterministic in the stock\nRESULT: %s\n",
           ncomp, ntrials, ndiff, nuninf, nnondet, ndiff == 0 ? "PASS" : "FAIL");
    return 0;
}
