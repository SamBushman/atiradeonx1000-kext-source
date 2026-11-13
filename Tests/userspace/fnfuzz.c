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
#include <sys/ucontext.h>
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

typedef struct { int status; unsigned r3, r4; unsigned long long f1; unsigned digest; unsigned args[8]; double dargs[4]; unsigned ncalls, trace, mask[5]; unsigned fix_valid, fix_src, fix_disp, fix_arg, fault_pc, fault_ra; } result_t;   /* ncalls / trace / mask: import-interposer mode (FNFUZZ_INTERPOSE=1) */
static unsigned cur_args[8]; static double cur_dargs[4];
typedef struct { int id; char name[96]; unsigned stock_addr, reb_off; int size; char pc[24]; char rc; } cand_t;

static cand_t *g_cs; static int g_nc; static unsigned long g_ap[2]; static unsigned g_astock, g_areb;   /* the ledger and the image anchors: a pointer into an image's text is named by the function it points at */
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
/* FNFUZZ_NANMODE=1: half of the float arguments are special values (quiet NaN of both signs, +-Inf, -0, denormals, the largest float, +-1e300) and one arena word in 24 is a special float
   word: the plain values never reach the branch of a compare that only an unordered (NaN) operand takes (the stock's `cror eq,lt,eq; bne` against a decompiled `a < b`). */
static int nanmode;
static unsigned gs_rec_hash, gs_rec_n;
static int nancanon;   /* FNFUZZ_NANCANON: in the arena digest, the verbose dump and f1, every NaN bit pattern (either sign, any payload) counts as the same NaN: separates a difference in NaN sign/payload (which of two NaN operands an instruction passes on) from a difference in a value */
static inline unsigned nan_canon_w(unsigned v) { return (nancanon && (v & 0x7f800000u) == 0x7f800000u && (v & 0x7fffffu)) ? 0x7fc00000u : v; }
static const unsigned long long nan_dbl[] = { 0x7ff8000000000000ULL, 0xfff8000000000000ULL, 0x7ff0000000000000ULL, 0xfff0000000000000ULL, 0x8000000000000000ULL, 0x0000000000000001ULL, 0x000fffffffffffffULL, 0x47efffffe0000000ULL, 0x7e37e43c8800759cULL, 0xfe37e43c8800759cULL, 0x36a0000000000000ULL, 0x3810000000000000ULL };
static const unsigned nan_wrd[] = { 0x7fc00000u, 0xffc00000u, 0x7f800000u, 0xff800000u, 0x80000000u, 0x00000001u, 0x007fffffu, 0x7f7fffffu, 0xff7fffffu, 0x7fa00000u };
static double gen_double(int single) {
    unsigned k = rnd32() % 16; double v;
    if (nanmode && (rnd32() & 1)) { unsigned long long b = nan_dbl[rnd32() % (sizeof nan_dbl / sizeof *nan_dbl)]; memcpy(&v, &b, 8); return single ? (double)(float)v : v; }
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
static int gs_malloc;   /* FNFUZZ_GRAPHSPEC: malloc/calloc/realloc/free are stubbed onto an arena heap (deterministic, digested, a free of a graph node is a no-op) */
static unsigned gm_next;
#define GM_LO (ARENA_BASE + 0x16000u)
#define GM_HI (ARENA_BASE + 0x1f000u)
/* Imports that spawn, signal or wait for a PROCESS are always stubbed (answer 0 for popen, -1 for the rest: the "could not" path of the caller), whatever their name: a real `popen("ps -wwp %d")`
   (GLDriver gld_printApplicationPath) inside a fuzz child hung the child, the watchdog's kill(child, SIGKILL) in run_one then panicked the G5's Tiger kernel (`mapping_alloc - empty mapping
   block detected`, user PC = the harness's _kill stub, LR = the instruction after `bl _kill`; deterministic, 3 crashes, Nov 12). The call is still recorded in the trace, so both images are
   compared on it; the code behind a successful popen (the fgets/index/rindex parse of the `ps` line) is not run by the fuzz. */
static int spawn_import(const char *n) {
    static const char *sp[] = { "popen", "pclose", "system", "fork", "vfork", "execve", "execv", "execvp", "execl", "execlp", "execle", "posix_spawn", "posix_spawnp", "kill", "killpg", "wait", "wait3", "wait4", "waitpid", NULL };
    if (*n == '_') n++;
    for (int i = 0; sp[i]; i++) if (!strcmp(n, sp[i])) return 1;
    return 0;
}
static int stub_class(const char *n) {
    static const char *pre[] = { "Sh", "PP", "glg", "glp", "NS", "CF", "IO", "host_", "mach_", "sysctl", "scandir", "pthread_mutex_", NULL };
    if (*n == '_') n++;
    { size_t L = strlen(n); if (L && n[L - 1] == '_') return 0; }   /* mach_task_self_ is a DATA symbol (the stock binds its non-lazy slot to the variable; the rebuilt through an external relocation): never overwrite a data slot with a function */
    {   /* FNFUZZ_INTERPOSE_SKIP=NS,CF: name prefixes the interposer leaves real (the stock's own printf$LDBLStub binds through NSLookupAndBindSymbolWithHint; stubbed, it jumps to the stub's return value) */
        const char *sk = getenv("FNFUZZ_INTERPOSE_SKIP");
        while (sk && *sk) { size_t L = strcspn(sk, ","); if (L && !strncmp(n, sk, L)) return 0; sk += L + (sk[L] == ',' ? 1 : 0); }
    }
    /* The dyld runtime-linker calls (NSIsSymbolNameDefinedWithHint / NSLookupAndBindSymbolWithHint / NSAddressOfSymbol, which the stock's and the rebuilt's printf$LDBLStub use, NSLinkModule / NSLookupSymbolInModule in GLEngine) return a CODE ADDRESS that the
       caller jumps to. A PRNG answer sent the fuzz child into random data (`_retblk`), which it then executed as code: random system calls with random registers, a UNINF verdict for every row that prints, and (Nov 12) kernel memory
       corruption that took the G5 down 6 times. They are never stubbed: the real linker binds the real libc function for both images. */
    if (!strncmp(n, "NSIsSymbol", 10) || !strncmp(n, "NSLookup", 8) || !strncmp(n, "NSAddressOf", 11) || !strncmp(n, "NSModule", 8) || !strncmp(n, "NSLink", 6) || !strncmp(n, "NSUnLink", 8) || !strncmp(n, "NSCreateObjectFile", 18) || !strncmp(n, "NSDestroyObjectFile", 19)) return 0;
    if (spawn_import(n)) return 1;
    for (int i = 0; pre[i]; i++) if (!strncmp(n, pre[i], strlen(pre[i]))) return 1;
    if (gs_malloc && (!strcmp(n, "malloc") || !strcmp(n, "calloc") || !strcmp(n, "realloc") || !strcmp(n, "free"))) return 1;
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
                /* a symbol the image defines itself (the stock calls its own exported functions through lazy stubs, Apple gcc -fPIC; the rebuilt image calls them directly): stubbing it in the stock only
                   would compare the stock's stubbed result with the rebuilt's real call (glprog: 957 such slots in the stock, calls into PPStreamAddConstant, GetPPStreamTypeForGLType, ...). Not an import. */
                { int own = 0; for (unsigned y = 0; y < st->nsyms && !own; y++) if ((nl[y].n_type & N_TYPE) == N_SECT && (nl[y].n_type & N_EXT) && !strcmp(str + nl[y].n_un.n_strx, nm)) own = 1; if (own) continue; }
                slots[img][nslots[img]].slot = (unsigned *)(sc->addr + slide) + q; slots[img][nslots[img]].idx = stub_index(nm); nslots[img]++;
            }
        }
    }
}
static int gs_semantic(const char *nm, unsigned *a, unsigned *r);
/* FNFUZZ_STACKREC=IMPORT:ARG:WORDS[,...]: the import takes a record by pointer (glgProcessPixels(&record, ...)); when that argument points into the stack the WORDS words behind it enter the call trace
   (stack and image addresses normalised), so the words the function stored into its frame record are compared, not only the pointer. */
static struct { int idx, arg, words; } stackrec[16]; static int nstackrec;
static unsigned stub_common(int idx, unsigned *a) {   /* 32-bit return: an `unsigned long long` is returned in r3:r4 (high word in r3), so the callers read 0 from r3 */
    unsigned h = trace_c ? trace_c : 2166136261u; h = (h ^ (unsigned)idx) * 16777619u;
    ncalls_c++; mask_c[idx >> 5] |= 1u << (idx & 31);
    { static int dump = -1; if (dump < 0) dump = getenv("FNFUZZ_IMPDUMP") != NULL; if (dump) { fprintf(stderr, "  [%s call %u] %s(%x %x %x %x %x %x %x %x)\n", cur_img ? "rebuilt" : "stock", ncalls_c, stub_names[idx], a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7]); } }
    for (int i = 0; i < nargs_tab[idx]; i++) {
        unsigned v = a[i];
        if (v >= ARENA_BASE && v <= ARENA_BASE + ARENA_SIZE - 16) { h = (h ^ 0xA7E4A000u) * 16777619u; for (int k = 0; k < 16; k++) h = (h ^ ((unsigned char *)v)[k]) * 16777619u; }
        else { int sr = -1; for (int q = 0; q < nstackrec; q++) if (stackrec[q].idx == idx && stackrec[q].arg == i) sr = stackrec[q].words;
               if (sr > 0 && v >= 0xbf000000u && v < 0xbffffff0u && (v & 3) == 0) { h = (h ^ 0x57ACEC00u) * 16777619u; for (int k = 0; k < sr; k++) { unsigned w = ((unsigned *)v)[k]; if (in_image(w)) w = 0x1A6E0001; h = (h ^ w) * 16777619u; if (getenv("FNFUZZ_RECDUMP")) { if (k % 8 == 0) fprintf(stderr, "\n   %s rec+%02x:", cur_img ? "R" : "S", k * 4); fprintf(stderr, " %08x", w); } } }
               else { if (in_image(v)) v = 0x1A6E0001; else if (v >= 0xbf000000u && v < 0xc0000000u) v = 0x57AC0001;   /* a stack address differs with the frame layout of the two images */
               h = (h ^ v) * 16777619u; } }
    }
    trace_c = h;
    ret_state = ret_state * 6364136223846793005ULL + 1442695040888963407ULL + (unsigned)idx * 2654435761u + ncalls_c;
    unsigned k = (unsigned)(ret_state >> 40) % 20, r;
    if (k < 5) r = 0; else if (k < 7) r = 1; else if (k < 9) r = 2 + (unsigned)(ret_state >> 20) % 15; else if (k < 10) r = (unsigned)-1; else r = (unsigned)(uintptr_t)(retblk + (((unsigned)(ret_state >> 16) % 0x1000) & ~3u));
    if (strstr(stub_names[idx], "InfoLog")) r = (unsigned)(uintptr_t)(retblk + (((unsigned)(ret_state >> 16) % 0x1000) & ~3u));   /* a log string: callers strlen/strncpy it */
    int handled = gs_malloc && gs_semantic(stub_names[idx], a, &r);   /* graph-mode semantics: returned objects, list operations (declared with `ret` / `retpick` or built in) */
    int ctl = cur_img == 1 && imp_ctl && !strcmp(stub_names[idx], imp_ctl);
    { static int dump2 = -1; if (dump2 < 0) dump2 = getenv("FNFUZZ_IMPDUMP") != NULL; if (dump2) fprintf(stderr, "      -> %x\n", ctl ? ~r ^ 0x1234 : r); }   /* FNFUZZ_IMPDUMP: the answer the generic stub gives (a graph-mode semantic stub or a spawn_import answer may replace it) */
    if (spawn_import(stub_names[idx])) { r = !strcmp(stub_names[idx], "popen") ? 0 : (unsigned)-1; if (ctl) r = ~r ^ 0x1234; return r; }   /* never run: see spawn_import */
    if (ctl) r = ~r ^ 0x1234;
    if (handled) return r;   /* a modelled import writes exactly what its semantics say, no generic out-parameter words */
    /* out parameters: the library writes results through pointer arguments (ShGetUniformTypeInfo(.., &type, &size)); a caller that reads them must see defined values, not stack residue. Every argument that is a
       word-aligned stack address gets ONE word from the PRNG (a small value: types, counts, indexes), the same in both images; an arena pointer too (the arena digest compares what the function does with it) */
    /* behaviour the graph mocks need (the library's own semantics, identical for both images): PPStreamChunkListRemoveChunk(list, node) unlinks the node (list+0 first, node+8 next, list+8 count) instead of
       scribbling a random word over both, and a predicate (`...IsEqual`) writes nothing through its arguments */
    { const char *nm = stub_names[idx];
      if (gs_malloc && (!strcmp(nm, "malloc") || !strcmp(nm, "calloc") || !strcmp(nm, "realloc") || !strcmp(nm, "free"))) {
          if (!strcmp(nm, "free")) return 0;
          unsigned sz = !strcmp(nm, "calloc") ? a[0] * a[1] : !strcmp(nm, "realloc") ? a[1] : a[0], old = 0; unsigned char *op = NULL;
          if (!strcmp(nm, "realloc") && a[0] >= GM_LO + 16 && a[0] < GM_HI) { op = (unsigned char *)a[0]; old = *(unsigned *)(op - 16); }
          if (gm_next < GM_LO) gm_next = GM_LO;
          unsigned need = (sz + 15) & ~15u; if (sz > 0x4000 || gm_next + 16 + need > GM_HI) return 0;
          if (ctl) gm_next += 16;   /* mismatch control: the rebuilt side's blocks sit 16 bytes higher */
          unsigned char *b = (unsigned char *)gm_next + 16; gm_next += 16 + need; *(unsigned *)(b - 16) = sz;
          if (!strcmp(nm, "calloc")) memset(b, 0, sz); if (op) memcpy(b, op, old < sz ? old : sz);
          return (unsigned)(uintptr_t)b; } }
    { const char *nm = stub_names[idx]; size_t L = strlen(nm);
      if (!strcmp(nm, "PPStreamChunkListRemoveChunk") && a[0] >= ARENA_BASE && a[0] <= ARENA_BASE + ARENA_SIZE - 16 && a[1] >= ARENA_BASE && a[1] <= ARENA_BASE + ARENA_SIZE - 16) {
          unsigned *hd = (unsigned *)a[0], nx = *(unsigned *)(a[1] + 8);
          if (hd[0] == a[1]) hd[0] = nx; else { unsigned pp = hd[0]; for (int g = 0; g < 64 && pp >= ARENA_BASE && pp <= ARENA_BASE + ARENA_SIZE - 16; g++) { unsigned *pn = (unsigned *)(pp + 8); if (*pn == a[1]) { *pn = nx; break; } pp = *pn; } }
          if (hd[2]) hd[2]--;
          return r; }
      if (L >= 7 && !strcmp(nm + L - 7, "IsEqual")) return r; }
    for (int i = 0; i < nargs_tab[idx]; i++) {
        unsigned v = a[i];
        if ((v & 3) == 0 && ((v >= 0xbf000000u && v < 0xbffffff0u) || (v >= ARENA_BASE && v <= ARENA_BASE + ARENA_SIZE - 4))) {
            ret_state = ret_state * 6364136223846793005ULL + 1442695040888963407ULL; unsigned w = (unsigned)(ret_state >> 44) % 12; if (ctl) w = w * 7 + 5; *(unsigned *)v = w;
        }
    }
    return r;
}
/* A stub's frames sit exactly where the image's own callee frames will be built next, so a stack slot the code under test reads before writing (an out-parameter a callee leaves alone, e.g.
   _PPEmulatorProgramSetupHandlesFromPPStream's local_2c after _gleVPGetResultOffset returned without writing it) holds the stub's spilled argument registers - junk that depends on the frame
   distance of each image (stock 0x5851f42d.., rebuilt a saved return address). The stub therefore clears its argument copy and scrubs the stack below itself on the way out: an uninitialised slot
   reads the same zero in both images, whatever the frame layouts. */
static void __attribute__((noinline)) scrub_below(void) { volatile unsigned buf[640]; for (int i = 0; i < 640; i++) buf[i] = 0; }
#define S1(n) static unsigned stb##n(unsigned a, unsigned b, unsigned c, unsigned d, unsigned e, unsigned f, unsigned g, unsigned h) { volatile unsigned v[8] = { a, b, c, d, e, f, g, h }; unsigned r = stub_common(n, (unsigned *)v); for (int i = 0; i < 8; i++) v[i] = 0; scrub_below(); return r; }
#define R10(p) S1(p##0) S1(p##1) S1(p##2) S1(p##3) S1(p##4) S1(p##5) S1(p##6) S1(p##7) S1(p##8) S1(p##9)
S1(0) S1(1) S1(2) S1(3) S1(4) S1(5) S1(6) S1(7) S1(8) S1(9) R10(1) R10(2) R10(3) R10(4) R10(5) R10(6) R10(7) R10(8) R10(9) R10(10) R10(11) R10(12) R10(13) R10(14) R10(15)
#define T1(n) (void *)stb##n,
#define T10(p) T1(p##0) T1(p##1) T1(p##2) T1(p##3) T1(p##4) T1(p##5) T1(p##6) T1(p##7) T1(p##8) T1(p##9)
static void *stub_fns[MAXSTUB] = { T1(0) T1(1) T1(2) T1(3) T1(4) T1(5) T1(6) T1(7) T1(8) T1(9) T10(1) T10(2) T10(3) T10(4) T10(5) T10(6) T10(7) T10(8) T10(9) T10(10) T10(11) T10(12) T10(13) T10(14) T10(15) };
static void install_stubs(int img) { for (int i = 0; i < nslots[img]; i++) *slots[img][i].slot = (unsigned)(uintptr_t)stub_fns[slots[img][i].idx]; }
static void load_stackrec(void) {
    const char *e = getenv("FNFUZZ_STACKREC"); if (!e) return; char buf[512]; snprintf(buf, sizeof buf, "%s", e);
    for (char *s = strtok(buf, ","); s && nstackrec < 16; s = strtok(NULL, ",")) { char nm[96]; int ar, wd; if (sscanf(s, "%95[^:]:%d:%d", nm, &ar, &wd) != 3) continue;
        for (int i = 0; i < nstub; i++) if (!strcmp(stub_names[i], nm)) { stackrec[nstackrec].idx = i; stackrec[nstackrec].arg = ar; stackrec[nstackrec].words = wd; nstackrec++; } }
}
static void load_nargs(void) {
    for (int i = 0; i < MAXSTUB; i++) nargs_tab[i] = 8;
    const char *fn = getenv("FNFUZZ_IMPORT_NARGS"); if (!fn) return; FILE *f = fopen(fn, "r"); if (!f) { perror(fn); exit(2); }
    char l[160], n[96]; int k, got = 0;
    while (fgets(l, sizeof l, f)) if (sscanf(l, "%95s %d", n, &k) == 2) for (int i = 0; i < nstub; i++) if (!strcmp(stub_names[i], n)) { nargs_tab[i] = k > 8 ? 8 : k; got++; }
    fclose(f);
    for (int i = 0; i < nstub; i++) { const char *nm = stub_names[i]; if (!strcmp(nm, "malloc") || !strcmp(nm, "free")) nargs_tab[i] = 1; else if (!strcmp(nm, "calloc") || !strcmp(nm, "realloc")) nargs_tab[i] = 2; }
    fprintf(stderr, "interposer: argument counts for %d of %d imports\n", got, nstub);
}
static void init_retblk(void) { unsigned *w = (unsigned *)retblk; unsigned long long x = 88172645463325252ULL; for (unsigned i = 0; i < sizeof retblk / 4; i++) { x ^= x << 13; x ^= x >> 7; x ^= x << 17; unsigned k = (unsigned)(x >> 32) % 8; w[i] = k < 2 ? 0 : k < 6 ? (unsigned)(x >> 40) % 64 : (unsigned)(uintptr_t)(retblk + (((unsigned)(x >> 36) % 0x1ff0) & ~3u)); } }

/* ---- image globals (FNFUZZ_DATA=file, spec directives gcopy/gptr/gset/gwatch) ---------------------------------------------------------------------------------------------------
   Some functions read and write the image's own variables (`_gle_io_data`, `_glep_plugin_head`): file lines `name<TAB>stock_addr<TAB>rebuilt_addr` (hex; Tools/userspace/gleng_data_addrs.py: stock from the
   Ghidra symbol map, rebuilt from nm). Both images sit at their own slide, so an address is anchor + (address - anchor address) as for functions. After the call every watched word is folded into the
   digest; a word that points into the image's text is replaced by the id of the function it points at (the two images lay their functions out differently, but the slot must name the same function). */
static struct { char name[48]; unsigned st, rb; } gdat[32]; static int ngdat;
static struct { unsigned *p; int words; } cur_watch[8]; static int ncur_watch;
static unsigned *gaddr(const char *name) { for (int i = 0; i < ngdat; i++) if (!strcmp(gdat[i].name, name)) return (unsigned *)(g_ap[cur_img] + (cur_img ? gdat[i].rb - g_areb : gdat[i].st - g_astock)); fprintf(stderr, "no data symbol %s in FNFUZZ_DATA\n", name); _exit(9); }
static unsigned fn_token(unsigned v) {
    if (!in_image(v)) return v;
    for (int i = 0; i < ngdat; i++) if ((unsigned)(g_ap[cur_img] + (cur_img ? gdat[i].rb - g_areb : gdat[i].st - g_astock)) == v) return 0x4D000000u + (unsigned)i;   /* a global or function named in FNFUZZ_DATA */
    for (int i = 0; i < g_nc; i++) { unsigned a = (unsigned)(g_ap[cur_img] + (cur_img ? g_cs[i].reb_off - g_areb : g_cs[i].stock_addr - g_astock)); if (a == v) return 0x4E000000u + (unsigned)g_cs[i].id; }
    return 0x1A6E0001;
}
/* FNFUZZ_REPAIR=1 (fault-driven pointer repair): a random arena makes most functions fault on the first NULL / wild pointer field they dereference, in both images alike (an `uninformative` function: it was never
   run past its first loads). When the stock faults on a D-form load/store `op rt,D(ra)`, the handler looks back in the code for the `lwz ra,D2(rb)` that produced the base register, works out the arena word
   it came from (rb + D2) and reports it; the parent then patches that word to a valid arena pointer (a value that keeps rb+D inside the arena) and runs again, up to 16 patches per trial. The final patch list
   is applied to the arena before the call in all three runs of the trial (stock twice, rebuilt), so the stock decides which fields must be pointers and the images are compared on a path that runs. */
static unsigned g_fix_valid, g_fix_src, g_fix_disp, g_fix_arg, g_fault_pc, g_fault_ra;
static void report(int status, unsigned r3, unsigned r4, unsigned long long f1);
static void on_sig_info(int s, siginfo_t *si, void *ucv) {
    (void)si;
    if (s == SIGSEGV || s == SIGBUS) {
        ucontext_t *u = (ucontext_t *)ucv; unsigned *R = (unsigned *)&u->uc_mcontext->ss.r0; unsigned pc = u->uc_mcontext->ss.srr0;
        unsigned w = *(unsigned *)pc, op = w >> 26, ra = (w >> 16) & 31; int D = (short)(w & 0xffff); g_fault_pc = pc; g_fault_ra = R[ra];
        if (((op >= 32 && op <= 47) || (op >= 48 && op <= 55)) && ra != 0) {
            for (int k = 1; k <= 64; k++) { unsigned pw = ((unsigned *)pc)[-k]; if (pw == 0x4e800020u) break;
                if ((pw >> 26) == 32 && ((pw >> 21) & 31) == ra) { unsigned rb = (pw >> 16) & 31; int D2 = (short)(pw & 0xffff);
                    if (rb != 0) { unsigned src = R[rb] + D2; if (src >= ARENA_BASE && src < ARENA_BASE + ARENA_SIZE - 3 && !(src & 3)) { g_fix_valid = 1; g_fix_src = src; g_fix_disp = (unsigned)D; }
                        else for (int k2 = 0; k2 < 8; k2++) { unsigned delta = R[rb] - cur_args[k2]; if (delta < 0x20000u) { g_fix_valid = 1; g_fix_arg = (unsigned)k2 + 1; g_fix_disp = delta + (unsigned)D2; break; } } }   /* the loaded-from address is not in the arena but is an argument plus a constant (`addi r29,r3,0x4dd0`): the argument must be a pointer */
                    break; }
                if ((pw >> 26) == 14 && ((pw >> 21) & 31) == ra) break;   /* `addi ra,..`: a computed base, not a loaded one */ }
            if (!g_fix_valid) for (int k = 0; k < 8; k++) { unsigned delta = R[ra] - cur_args[k]; if (delta < 0x20000u) { g_fix_valid = 1; g_fix_arg = (unsigned)k + 1; g_fix_disp = delta + (unsigned)D; break; } }   /* the base is an incoming argument itself */ } }
    report(s, 0, 0, 0);
}
static void report(int status, unsigned r3, unsigned r4, unsigned long long f1) {
    unsigned *w = (unsigned *)ARENA_BASE; unsigned long long h = 1469598103934665603ULL;
    for (unsigned i = 0; i < ARENA_SIZE / 4; i++) { unsigned v = w[i]; if (in_image(v)) v = 0x1A6E0001; v = nan_canon_w(v); h = fnv((unsigned char *)&v, 4, h); }
    for (int q = 0; q < ncur_watch; q++) for (int k = 0; k < cur_watch[q].words; k++) { unsigned v = fn_token(cur_watch[q].p[k]); if (getenv("FNFUZZ_WATCHDUMP")) fprintf(stderr, "  [%s watch%d+%d raw %08x -> %08x]\n", cur_img ? "R" : "S", q, k, cur_watch[q].p[k], v); h = fnv((unsigned char *)&v, 4, h); }
    if (gs_rec_n && getenv("FNFUZZ_RECDUMP")) fprintf(stderr, "  [%s rec n=%u hash=%08x]\n", cur_img ? "R" : "S", gs_rec_n, gs_rec_hash);
    if (gs_rec_n) { h = fnv((unsigned char *)&gs_rec_hash, 4, h); h = fnv((unsigned char *)&gs_rec_n, 4, h); }
    if (interpose) for (unsigned i = 0; i < sizeof retblk / 4; i++) { unsigned v = ((unsigned *)retblk)[i]; if (v >= (unsigned)(uintptr_t)retblk && v < (unsigned)(uintptr_t)retblk + sizeof retblk) v = 0x1A6E0003; h = fnv((unsigned char *)&v, 4, h); }
    result_t r; memset(&r, 0, sizeof r); r.ncalls = ncalls_c; r.trace = trace_c; memcpy(r.mask, mask_c, sizeof r.mask); r.fix_valid = g_fix_valid; r.fix_src = g_fix_src; r.fix_disp = g_fix_disp; r.fix_arg = g_fix_arg; r.fault_pc = g_fault_pc; r.fault_ra = g_fault_ra; r.status = status; r.r3 = in_image(r3) ? 0x1A6E0002 : r3; r.r4 = r4; if (nancanon && (f1 & 0x7ff0000000000000ULL) == 0x7ff0000000000000ULL && (f1 & 0xfffffffffffffULL)) f1 = 0x7ff8000000000000ULL; r.f1 = f1; r.digest = (unsigned)(h ^ (h >> 32)); memcpy(r.args, cur_args, sizeof r.args); memcpy(r.dargs, cur_dargs, sizeof r.dargs);
    (void)!write(wfd, &r, sizeof r);
    if (getenv("FNFUZZ_VERBOSE")) { for (unsigned i = 0; i < ARENA_SIZE / 4; i++) { unsigned v = w[i]; if (in_image(v)) v = 0x1A6E0001; v = nan_canon_w(v); (void)!write(wfd, &v, 4); } }
    _exit(0);
}
static void on_sig(int s) { report(s, 0, 0, 0); }

/* FNFUZZ_STACKFILL=<hex word>: write that word over the 32 KB of stack below the harness's frame right before the call. A function that reads a stack slot it never wrote
   (a descriptor struct with fields it leaves alone, a callee that reads more than its caller sets) sees residue of the harness's earlier calls, which differs between the images' frame
   layouts; filling makes the residue a known value in both, so only a difference in what the function itself writes or reads is left. */
static int stackfill_set, use_fill2; static unsigned stackfill_word;   /* FNFUZZ_STACKFILL2=<hex>: the second stock run of every trial uses this fill word instead of FNFUZZ_STACKFILL: a trial whose stock result changes with it reads uninitialised stack (reported as `nondeterministic in the stock`) */ 
static void __attribute__((noinline)) fill_stack(void) { volatile unsigned buf[8192]; for (int i = 0; i < 8192; i++) buf[i] = stackfill_word; }

/* FNFUZZ_GRAPHSPEC=<file>: structured object graphs for the functions the random arena cannot reach (a PPStream, a shader/program object, a hash table of machine objects). The spec declares node
   types and per-function roots; for a function it names, child() builds the graph in the arena (zeroed, deterministic from the trial seed, so both images see the same bytes at the same addresses)
   and the declared arguments are replaced by pointers into it. Lines (`#` comments, blank lines ignored):
     type NAME SIZE                       start a node type (SIZE bytes, zero-filled; every field not listed stays 0)
       ptr OFF TYPE [PCT]                 +OFF = pointer to a fresh TYPE node (non-NULL in PCT percent of the nodes, default 100)
       rlist OFF MIN MAX                  +OFF = first of MIN..MAX free-name range nodes {+0 next, +4 first name, +8 length}, ascending, gaps 0..3 (the lists _gleGenHashNames / _gleAddHashName / _gleRemoveHashName keep)
       list OFF TYPE MIN MAX NEXTOFF      +OFF = first of a chain of MIN..MAX fresh TYPE nodes linked through their +NEXTOFF word (NULL-terminated; 0 nodes -> NULL)
       u8|u16|u32 OFF LO HI               +OFF = random value in LO..HI
       rand OFF                           +OFF = random 32-bit word
       set OFF VALUE                      +OFF = VALUE
       pick OFF V1 V2 ...                 +OFF = one of the values
       bits OFF MASK                      +OFF = random word & MASK
       str OFF TEXT                       +OFF = pointer to a NUL-terminated copy of TEXT (one of the `|`-separated alternatives)
       hash OFF TYPE MIN MAX NAMEOFF MASK  +OFF = inline bucket array of MASK+1 words; MIN..MAX fresh TYPE nodes, each given a distinct name (1..) at +NAMEOFF and pushed on the front of bucket
                                          (name & MASK) through its +0 word (the machine-object hash table `_gleLookupHashObject` walks); the names are recorded for `arg N name`
       (`ret`/`retpick` after a `func` line apply to that function only, before any `func` line to all) ret IMPORT TYPE          the stubbed import returns a fresh TYPE graph on every call (parser/stream/list objects: PPParserCreate, PPStreamCreate, ...)
       (top level) retpick IMPORT V1 V2 ..  the stubbed import returns one of the values (an error code, a count)
       dptr OFF NAME                      +OFF = the address of FNFUZZ_DATA symbol NAME in the image under test (a class vtable)
       fnq OFF IDX V1 [V2..]              +OFF = callback IDX (0..15), records r3, returns one of the values (a virtual method returning a qualifier / basic type / count)
       fnqp OFF IDX TYPE [PCT]            same, returns a pointer to a fresh TYPE node (a virtual method returning a child or a type object)
       dval OFF NAME [DELTA]              +OFF = the word held at FNFUZZ_DATA symbol NAME in the image under test, plus DELTA (a class vtable address from a PTR_vtable_* cell)
       fn OFF                             +OFF = the address of a harmless harness function (a callback slot the code under test calls: same address in both images)
       fnd OFF                            same, for a callback that takes (int, double) and returns the double
       fnrecv OFF                         same, for a slot called as (int, int, double, double, double, double): records r3, r4 and f1..f4 (the vertex dispatchers pass the float registers through)
       fnrecw OFF                         same, for a slot called as (int, double x4): records r3 and f1..f4 (no integer argument besides the context)
       fnrec1 OFF                         same, for a slot called as (int): records r3 only
       fnrecp OFF                         same, for a slot called as (int, int): records r3 and r4 (the ColorMat colour entries: ctx, pointer)
       fnrec OFF                          same, for a callback that RECORDS its four integer arguments (folded into the arena digest: a tail call through a slot is compared by what it passes on)
       randfill OFF LEN [MOD]             LEN bytes at +OFF = random words below MOD (default 4096): fields the code only reads (a context's state words)
       (retpick values may be `fn` / `fnd`: the stubbed import returns the address of the harmless function)
       (`out IMPORT ARG V1 V2 ..` after a `func` line: the word the import's ARG-th argument points to is set to one of the values after the call; give the import a `retpick` too)
       parr OFF TYPE COUNTOFF MIN MAX     +OFF = pointer to an array of N (MIN..MAX) pointers to fresh TYPE nodes, N stored at +COUNTOFF
     func NAME                            start a function
       arg N rel M val|deref D1 [D2 ..]   (after the line of argument M) the value of argument M, or the word it points to, plus one of the deltas: a pointer into an object another argument holds
       arg N ptr TYPE [PCT] | arg N int LO HI | arg N pick V1 V2 ... | arg N rand | arg N null | arg N str TEXT (a NUL-terminated copy of one of the `|`-separated alternatives) | arg N name [PCT]   (name: one of the recorded hash names, else a random small one)
   Numbers are decimal or 0x hex. */
typedef struct { unsigned off; int kind; unsigned a, b, c; int n; unsigned v[8]; char tname[32]; char text[96]; } gfield_t;
typedef struct { char name[32]; unsigned size; int nf; gfield_t f[96]; } gtype_t;
typedef struct { int n; int kind; unsigned a, b; int pct; unsigned v[64]; int nv; char tname[32]; char text[96]; } garg_t;
typedef struct { char name[96]; int na; garg_t a[16]; } gfunc_t;
enum { GF_PTR = 1, GF_LIST, GF_U8, GF_U16, GF_U32, GF_RAND, GF_SET, GF_PICK, GF_BITS, GF_STR, GF_HASH, GF_PARR, GF_FN, GF_RANDFILL, GF_FND, GF_ISTR, GF_WARR, GF_RLIST, GF_FNREC, GF_FNRECV, GF_FNRECW, GF_FNRECP, GF_FNREC1, GF_FNREC3, GF_PADD, GF_FNREC3A, GF_FNRECA, GF_FFILL, GF_DPTR, GF_FNQ, GF_FNQP, GF_DVAL };
enum { GA_PTR = 1, GA_INT, GA_PICK, GA_RAND, GA_NULL, GA_NAME, GA_STR, GA_REL };
static unsigned g_names[64]; static int g_nnames;
typedef struct { char name[48]; char tname[32]; unsigned v[8]; int nv; char func[96]; int pct; } gret_t;
typedef struct { char name[48]; char func[96]; int arg; unsigned v[8]; int nv; } gout_t; static gout_t gouts[160]; static int ngouts;   /* `out IMPORT ARG V1 V2 ..`: after the stubbed import the word its ARG-th argument points to holds one of the values (an out-parameter the library fills: a type enum) */
static char gs_curfunc[96]; static unsigned gs_first_cnt, gs_lg_n = 0xffffffffu, gs_lg_c, gs_lg_o;
typedef struct { char func[96]; int kind; char name[48]; char tname[32]; unsigned a, pct; char text[96]; } gglob_t; static gglob_t gglobs[64]; static int nglobs;   /* gcopy NAME TYPE | gptr NAME TYPE PCT | gset NAME VAL | gwatch NAME WORDS | env NAME a|b|- | scandirout a|b MAXN | retcfstr IMPORT a|b|- (all function-scoped) */
enum { GG_COPY = 1, GG_PTR, GG_SET, GG_WATCH, GG_ENV, GG_SCANDIR, GG_CFSTR };
static char cfstr_pool[32][96]; static int ncfstr;   /* CF string stand-ins: a CFStringRef is a pointer to the characters here */
static gret_t grets[160]; static int ngrets;
static gtype_t gtypes[160]; static int ngtypes; static gfunc_t gfuncs[320]; static int ngfuncs; static unsigned gb_next;
static int gs_nop(int a);
static unsigned gs_rec_hash, gs_rec_n;   /* `fnrec`: a callback slot that records its four integer arguments; the record is part of the arena digest (what a tail call through a slot hands on is the whole behaviour of such a function) */
static int gs_recv(int a, int b, double c, double d, double e, double f) { unsigned long long u[4]; memcpy(&u[0], &c, 8); memcpy(&u[1], &d, 8); memcpy(&u[2], &e, 8); memcpy(&u[3], &f, 8); gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)a; gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)b; for (int i = 0; i < 4; i++) { if ((u[i] & 0x7ff0000000000000ULL) == 0x7ff0000000000000ULL && (u[i] & 0xfffffffffffffULL) && nancanon) u[i] = 0x7ff8000000000000ULL; gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)(u[i] >> 32); gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)u[i]; } if (getenv("FNFUZZ_RECDUMP")) fprintf(stderr, "  [%s recv r3=%08x r4=%08x f1=%016llx f2=%016llx f3=%016llx f4=%016llx]\n", cur_img ? "R" : "S", (unsigned)a, (unsigned)b, u[0], u[1], u[2], u[3]); gs_rec_n++; return 0; }   /* `fnrecv`: a slot called as (int, int, double x4): the two integer and the four double argument registers */
static int gs_recw(int a, double c, double d, double e, double f) { return gs_recv(a, 0, c, d, e, f); }   /* `fnrecw`: a slot called as (int, double x4): r3 and f1..f4 */
static int gs_recp(int a, int b) { gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)a; gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)b; if (getenv("FNFUZZ_RECDUMP")) fprintf(stderr, "  [%s recp r3=%08x r4=%08x]\n", cur_img ? "R" : "S", (unsigned)a, (unsigned)b); gs_rec_n++; return 0; }   /* `fnrecp`: a slot called as (int, int): r3 and r4 */
static int gs_rec1(int a) { return gs_recp(a, 0); }   /* `fnrec1`: a slot called as (int): r3 only */
static unsigned gs_qv[16];   /* return values of the `fnq` / `fnqp` callbacks (set while the graph is built) */
#define GS_Q(N) static int gs_q##N(int a) { return gs_recp(a, 0) + (int)gs_qv[N]; }
GS_Q(0) GS_Q(1) GS_Q(2) GS_Q(3) GS_Q(4) GS_Q(5) GS_Q(6) GS_Q(7) GS_Q(8) GS_Q(9) GS_Q(10) GS_Q(11) GS_Q(12) GS_Q(13) GS_Q(14) GS_Q(15)
static int (*const gs_qtab[16])(int) = { gs_q0, gs_q1, gs_q2, gs_q3, gs_q4, gs_q5, gs_q6, gs_q7, gs_q8, gs_q9, gs_q10, gs_q11, gs_q12, gs_q13, gs_q14, gs_q15 };
static int gs_rec3(int a, int b, int c) { gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)a; gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)b; gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)c; gs_rec_n++; return 0; }   /* fnrec3: r3, r4, r5 */
static int gs_rec3a(int a, int b, int c) { gs_rec3(a, b, c); return a; }   /* fnrec3a: r3, r4, r5 recorded, r3 returned (a slot whose result the function tests: r3 is a field the spec controls) */
static int gs_rec(int a, int b, int c, int d) { gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)a; gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)b; gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)c; gs_rec_hash = (gs_rec_hash * 1000003u) ^ (unsigned)d; gs_rec_n++; return 0; }
/* FNFUZZ_VT=1 (with FNFUZZ_PROFILE=graph): generic virtual-call support for functions that call through `**(obj + K)` on objects of a pointer-dense arena. A read-only page at VT_BASE holds VT_WORDS
   words, each the address of gs_vtcb; about one in four of the pointer words the arena is filled with points into that page, so `*obj` is a "vtable" whose every slot is the callback. gs_vtcb records its object
   argument (r3) into the arena digest (what a function hands to a virtual method is part of its behaviour) and answers from the child's PRNG (0, a small count, or an arena pointer): the answers are the same
   in both images as long as both make the same calls in the same order, so a different call sequence shows up as a different digest/answer stream. The page is outside the arena (the function cannot overwrite a slot). */
#define VT_BASE 0x4f000000u
#define VT_TR 0x4f100000u
#define VT_WORDS 0x800u
static int vtmode;
static int gs_vtcb(int a, int b, int c, int d) { (void)b; (void)c; (void)d; gs_rec(a, 0, 0, 0);   /* r3 only: a virtual method that takes just `this` is called with whatever the registers held (the stock reloads only r3 on a second call), recording r4..r6 would compare dead registers */ unsigned k = rnd32() % 8; return k < 3 ? 0 : k < 5 ? (int)(rnd32() % 16) : (int)arena_ptr(); }
static unsigned vt_ptr(void) { return VT_BASE + 4 * (rnd32() % VT_WORDS); }
static int gs_reca(int a, int b, int c, int d) { gs_rec(a, b, c, d); return a; }   /* fnreca: r3..r6 recorded, r3 returned */
static double gs_nopd(int a, double x) { (void)a; return x; }   /* a callback slot that returns a double: the argument back */
static unsigned gnum(const char *s) { if (!strcmp(s, "fn")) return (unsigned)(uintptr_t)gs_nop; if (!strcmp(s, "fnd")) return (unsigned)(uintptr_t)gs_nopd; if (!strcmp(s, "fnrec")) return (unsigned)(uintptr_t)gs_rec; if (!strcmp(s, "fnrecv")) return (unsigned)(uintptr_t)gs_recv; if (!strcmp(s, "fnrecw")) return (unsigned)(uintptr_t)gs_recw; if (!strcmp(s, "fnrecp")) return (unsigned)(uintptr_t)gs_recp; if (!strcmp(s, "fnrec1")) return (unsigned)(uintptr_t)gs_rec1; if (!strcmp(s, "fnrec3")) return (unsigned)(uintptr_t)gs_rec3; if (!strcmp(s, "fnrec3a")) return (unsigned)(uintptr_t)gs_rec3a; if (!strcmp(s, "fnreca")) return (unsigned)(uintptr_t)gs_reca; return (unsigned)strtoul(s, NULL, 0); }   /* `fn` / `fnd`: the address of the harmless harness function (the same in both images) */
static void load_graphspec(const char *path) {
    FILE *f = fopen(path, "r"); if (!f) { perror(path); exit(2); }
    char line[1024]; gtype_t *ct = NULL; gfunc_t *cf = NULL;
    while (fgets(line, sizeof line, f)) {
        char *tok[80]; int nt = 0; char *h = strchr(line, '#'); if (h) *h = 0;
        for (char *p = strtok(line, " \t\r\n"); p && nt < 80; p = strtok(NULL, " \t\r\n")) tok[nt++] = p;
        if (!nt) continue;
        if (!strcmp(tok[0], "type") && nt >= 3) { if (ngtypes >= (int)(sizeof gtypes / sizeof *gtypes)) { fprintf(stderr, "graph spec: too many types\n"); exit(2); } ct = &gtypes[ngtypes++]; memset(ct, 0, sizeof *ct); snprintf(ct->name, sizeof ct->name, "%s", tok[1]); ct->size = gnum(tok[2]); cf = NULL; continue; }
        if (!strcmp(tok[0], "ret") && nt >= 3 && ngrets < 160) { gret_t *g = &grets[ngrets++]; memset(g, 0, sizeof *g); snprintf(g->name, sizeof g->name, "%s", tok[1]); snprintf(g->tname, sizeof g->tname, "%s", tok[2]); g->pct = nt >= 4 ? atoi(tok[3]) : 100; if (cf) snprintf(g->func, sizeof g->func, "%s", cf->name); ct = NULL; continue; }
        if (!strcmp(tok[0], "retpick") && nt >= 3 && ngrets < 160) { gret_t *g = &grets[ngrets++]; memset(g, 0, sizeof *g); snprintf(g->name, sizeof g->name, "%s", tok[1]); for (int i = 2; i < nt && g->nv < 8; i++) g->v[g->nv++] = gnum(tok[i]); if (cf) snprintf(g->func, sizeof g->func, "%s", cf->name); ct = NULL; continue; }
        if (!strcmp(tok[0], "out") && nt >= 4 && ngouts < 160) { gout_t *g = &gouts[ngouts++]; memset(g, 0, sizeof *g); snprintf(g->name, sizeof g->name, "%s", tok[1]); g->arg = atoi(tok[2]); for (int i = 3; i < nt && g->nv < 8; i++) g->v[g->nv++] = gnum(tok[i]); if (cf) snprintf(g->func, sizeof g->func, "%s", cf->name); ct = NULL; continue; }
        { int gk = !strcmp(tok[0], "gcopy") ? GG_COPY : !strcmp(tok[0], "gptr") ? GG_PTR : !strcmp(tok[0], "gset") ? GG_SET : !strcmp(tok[0], "gwatch") ? GG_WATCH : !strcmp(tok[0], "env") ? GG_ENV : !strcmp(tok[0], "scandirout") ? GG_SCANDIR : !strcmp(tok[0], "retcfstr") ? GG_CFSTR : 0;
          if (gk && cf && nt >= 2 && nglobs < 64) { gglob_t *g = &gglobs[nglobs++]; memset(g, 0, sizeof *g); g->kind = gk; g->pct = 100; snprintf(g->func, sizeof g->func, "%s", cf->name);
              if (gk == GG_SCANDIR) { snprintf(g->text, sizeof g->text, "%s", tok[1]); g->a = nt >= 3 ? gnum(tok[2]) : 3; }
              else if (gk == GG_CFSTR) { snprintf(g->name, sizeof g->name, "%s", tok[1]); snprintf(g->text, sizeof g->text, "%s", nt >= 3 ? tok[2] : "-"); }
              else { snprintf(g->name, sizeof g->name, "%s", tok[1]);
                  if (gk == GG_COPY && nt >= 3) snprintf(g->tname, sizeof g->tname, "%s", tok[2]);
                  if (gk == GG_PTR && nt >= 3) { snprintf(g->tname, sizeof g->tname, "%s", tok[2]); if (nt >= 4) g->pct = (unsigned)atoi(tok[3]); }
                  if (gk == GG_SET && nt >= 3) g->a = gnum(tok[2]);
                  if (gk == GG_WATCH && nt >= 3) g->a = gnum(tok[2]);
                  if (gk == GG_ENV && nt >= 3) snprintf(g->text, sizeof g->text, "%s", tok[2]); }
              ct = NULL; continue; } }
        if (!strcmp(tok[0], "func") && nt >= 2) { if (ngfuncs >= (int)(sizeof gfuncs / sizeof *gfuncs)) { fprintf(stderr, "graph spec: too many funcs\n"); exit(2); } cf = &gfuncs[ngfuncs++]; memset(cf, 0, sizeof *cf); snprintf(cf->name, sizeof cf->name, "%s", tok[1]); ct = NULL; continue; }
        if (cf && !strcmp(tok[0], "arg") && nt >= 3) {
            garg_t *a = &cf->a[cf->na++]; memset(a, 0, sizeof *a); a->n = atoi(tok[1]); a->pct = 100;
            if (!strcmp(tok[2], "ptr") && nt >= 4) { a->kind = GA_PTR; snprintf(a->tname, sizeof a->tname, "%s", tok[3]); if (nt >= 5) a->pct = atoi(tok[4]); }
            else if (!strcmp(tok[2], "int") && nt >= 5) { a->kind = GA_INT; a->a = gnum(tok[3]); a->b = gnum(tok[4]); }
            else if (!strcmp(tok[2], "pick")) { a->kind = GA_PICK; for (int i = 3; i < nt && a->nv < 64; i++) a->v[a->nv++] = gnum(tok[i]); }
            else if (!strcmp(tok[2], "rand")) a->kind = GA_RAND; else if (!strcmp(tok[2], "null")) a->kind = GA_NULL;
            else if (!strcmp(tok[2], "str") && nt >= 4) { a->kind = GA_STR; snprintf(a->text, sizeof a->text, "%s", tok[3]); }
            else if (!strcmp(tok[2], "rel") && nt >= 6) { a->kind = GA_REL; a->b = (unsigned)atoi(tok[3]); a->a = !strcmp(tok[4], "deref"); for (int i = 5; i < nt && a->nv < 64; i++) a->v[a->nv++] = gnum(tok[i]); }   /* arg N rel M val|deref D1 [D2..]: the value of argument M (val) or the word it points to (deref) plus one of the deltas (an iterator / pointer into an object another argument holds); M must be an earlier line */
            else if (!strcmp(tok[2], "name")) { a->kind = GA_NAME; if (nt >= 4) a->pct = atoi(tok[3]); }
            continue;
        }
        if (ct && nt >= 2 && ct->nf < 96) {
            gfield_t *g = &ct->f[ct->nf]; memset(g, 0, sizeof *g); g->off = gnum(tok[1]); g->a = 0; g->b = 0; g->c = 100;
            if (!strcmp(tok[0], "ptr") && nt >= 3) { g->kind = GF_PTR; snprintf(g->tname, sizeof g->tname, "%s", tok[2]); if (nt >= 4) g->c = gnum(tok[3]); }
            else if (!strcmp(tok[0], "rlist") && nt >= 4) { g->kind = GF_RLIST; g->a = gnum(tok[2]); g->b = gnum(tok[3]); }
            else if (!strcmp(tok[0], "list") && nt >= 6) { g->kind = GF_LIST; snprintf(g->tname, sizeof g->tname, "%s", tok[2]); g->a = gnum(tok[3]); g->b = gnum(tok[4]); g->c = gnum(tok[5]); }
            else if ((!strcmp(tok[0], "u8") || !strcmp(tok[0], "u16") || !strcmp(tok[0], "u32")) && nt >= 4) { g->kind = tok[0][1] == '8' ? GF_U8 : tok[0][1] == '1' ? GF_U16 : GF_U32; g->a = gnum(tok[2]); g->b = gnum(tok[3]); }
            else if (!strcmp(tok[0], "rand")) g->kind = GF_RAND;
            else if (!strcmp(tok[0], "set") && nt >= 3) { g->kind = GF_SET; g->a = gnum(tok[2]); }
            else if (!strcmp(tok[0], "padd") && nt >= 4) { g->kind = GF_PADD; g->a = gnum(tok[2]); for (int i = 3; i < nt && g->n < 8; i++) g->v[g->n++] = gnum(tok[i]); }   /* padd DST SRC D1 [D2..]: word at DST = word at SRC + one of the deltas (a pointer into the same buffer, e.g. an end pointer a whole number of records past the start) */
            else if (!strcmp(tok[0], "pick")) { g->kind = GF_PICK; for (int i = 2; i < nt && g->n < 8; i++) g->v[g->n++] = gnum(tok[i]); }
            else if (!strcmp(tok[0], "hash") && nt >= 7) { g->kind = GF_HASH; snprintf(g->tname, sizeof g->tname, "%s", tok[2]); g->a = gnum(tok[3]); g->b = gnum(tok[4]); g->c = gnum(tok[5]); g->n = (int)gnum(tok[6]); }
            else if (!strcmp(tok[0], "parr") && nt >= 6) { g->kind = GF_PARR; snprintf(g->tname, sizeof g->tname, "%s", tok[2]); g->c = gnum(tok[3]); g->a = gnum(tok[4]); g->b = gnum(tok[5]); }
            else if (!strcmp(tok[0], "dptr") && nt >= 3) { g->kind = GF_DPTR; snprintf(g->tname, sizeof g->tname, "%s", tok[2]); }   /* dptr OFF NAME: +OFF = the address of the FNFUZZ_DATA symbol NAME in the image under test (a vtable pointer: the object's class vtable lives in the image data, at a different address in each image) */
            else if (!strcmp(tok[0], "fn")) g->kind = GF_FN;
            else if (!strcmp(tok[0], "fnd")) g->kind = GF_FND;
            else if (!strcmp(tok[0], "fnrec")) g->kind = GF_FNREC;
            else if (!strcmp(tok[0], "fnrecv")) g->kind = GF_FNRECV;
            else if (!strcmp(tok[0], "fnrecw")) g->kind = GF_FNRECW;
            else if (!strcmp(tok[0], "fnrecp")) g->kind = GF_FNRECP;
            else if (!strcmp(tok[0], "fnrec1")) g->kind = GF_FNREC1;
            else if (!strcmp(tok[0], "dval") && nt >= 3) { g->kind = GF_DVAL; snprintf(g->tname, sizeof g->tname, "%s", tok[2]); g->a = nt >= 4 ? gnum(tok[3]) : 0; }   /* dval OFF NAME [DELTA]: +OFF = the word stored at the FNFUZZ_DATA symbol NAME of the image under test, plus DELTA (the class vtable address a `PTR_vtable_*` cell holds; an object's +0 is that + 8) */
            else if (!strcmp(tok[0], "fnq") && nt >= 4) { g->kind = GF_FNQ; g->c = gnum(tok[2]); for (int i = 3; i < nt && g->n < 8; i++) g->v[g->n++] = gnum(tok[i]); }   /* fnq OFF IDX V1 [V2..]: +OFF = callback number IDX (0..15; records r3, returns one of the values: a virtual method that returns a qualifier, a basic type, a count) */
            else if (!strcmp(tok[0], "fnqp") && nt >= 4) { g->kind = GF_FNQP; g->c = gnum(tok[2]); snprintf(g->tname, sizeof g->tname, "%s", tok[3]); g->a = nt >= 5 ? gnum(tok[4]) : 100; }   /* fnqp OFF IDX TYPE [PCT]: same, the callback returns a pointer to a fresh TYPE node (a virtual method that returns a child / a type object), NULL in 100-PCT percent */
            else if (!strcmp(tok[0], "fnrec3")) g->kind = GF_FNREC3;
            else if (!strcmp(tok[0], "fnrec3a")) g->kind = GF_FNREC3A;
            else if (!strcmp(tok[0], "fnreca")) g->kind = GF_FNRECA;
            else if (!strcmp(tok[0], "ffill") && nt >= 5) { g->kind = GF_FFILL; g->a = gnum(tok[2]); float lo = (float)atof(tok[3]), hi = (float)atof(tok[4]); memcpy(&g->v[0], &lo, 4); memcpy(&g->v[1], &hi, 4); }   /* ffill OFF LEN LO HI: LEN bytes of random floats in LO..HI (1 in 16 is NaN / +-inf / -0) */
            else if (!strcmp(tok[0], "randfill") && nt >= 3) { g->kind = GF_RANDFILL; g->a = gnum(tok[2]); g->b = nt >= 4 ? gnum(tok[3]) : 4096; }
            else if (!strcmp(tok[0], "istr") && nt >= 3) { g->kind = GF_ISTR; snprintf(g->text, sizeof g->text, "%s", tok[2]); }   /* the characters inline at OFF (one of a|b|c) */
            else if (!strcmp(tok[0], "warr") && nt >= 6) { g->kind = GF_WARR; g->c = gnum(tok[2]); g->a = gnum(tok[3]); g->b = gnum(tok[4]); for (int i = 5; i < nt && g->n < 8; i++) g->v[g->n++] = gnum(tok[i]); }   /* warr OFF COUNTOFF MIN MAX v..: OFF = pointer to an array of count words drawn from v, COUNTOFF = the count word */
            else if (!strcmp(tok[0], "bits") && nt >= 3) { g->kind = GF_BITS; g->a = gnum(tok[2]); }
            else if (!strcmp(tok[0], "str") && nt >= 3) { g->kind = GF_STR; snprintf(g->text, sizeof g->text, "%s", tok[2]); }
            else continue;
            ct->nf++;
        }
    }
    fclose(f);
}
static gtype_t *gfind_type(const char *n) { for (int i = 0; i < ngtypes; i++) if (!strcmp(gtypes[i].name, n)) return &gtypes[i]; fprintf(stderr, "graphspec: no type %s\n", n); exit(2); }
static unsigned gb_build(gtype_t *t, int depth);
static int gs_nop(int a) { return a; }
static unsigned gb_alloc(unsigned size) { unsigned a = gb_next; gb_next += (size + 15) & ~15u; if (gb_next > GM_LO) _exit(9); memset((void *)a, 0, size); return a; }
static unsigned grange(unsigned lo, unsigned hi) { return hi <= lo ? lo : lo + rnd32() % (hi - lo + 1); }
static unsigned gb_build(gtype_t *t, int depth) {
    unsigned a = gb_alloc(t->size); unsigned char *b = (unsigned char *)a;
    static int maxdepth = -1; if (maxdepth < 0) { const char *e = getenv("FNFUZZ_GDEPTH"); maxdepth = e ? atoi(e) : 6; }   /* FNFUZZ_GDEPTH: nesting limit of the graph builder (default 6; a node deeper than that stays zero-filled) */
    if (depth > maxdepth) return a;
    for (int i = 0; i < t->nf; i++) {
        gfield_t *g = &t->f[i];
        switch (g->kind) {
        case GF_PTR: if (rnd32() % 100 < g->c) *(unsigned *)(b + g->off) = gb_build(gfind_type(g->tname), depth + 1); break;
        case GF_RLIST: { unsigned n = grange(g->a, g->b), prev = 0, pos = 1 + rnd32() % 3; for (unsigned k = 0; k < n; k++) { unsigned e = gb_alloc(12), len = 1 + rnd32() % 4; *(unsigned *)(e + 4) = pos; *(unsigned *)(e + 8) = len; pos += len + rnd32() % 4;
                if (prev) *(unsigned *)prev = e; else *(unsigned *)(b + g->off) = e; prev = e; } break; }
        case GF_LIST: { unsigned n = grange(g->a, g->b), prev = 0; for (unsigned k = 0; k < n; k++) { unsigned e = gb_build(gfind_type(g->tname), depth + 1); if (prev) *(unsigned *)((unsigned char *)prev + g->c) = e; else *(unsigned *)(b + g->off) = e; prev = e; } break; }
        case GF_HASH: { unsigned nn = grange(g->a, g->b); unsigned nameoff = g->c; unsigned mask = (unsigned)g->n; unsigned *bk = (unsigned *)(b + g->off);
            for (unsigned k = 0; k < nn; k++) { unsigned e = gb_build(gfind_type(g->tname), depth + 1); unsigned nm = 1 + k * 3 + rnd32() % 3;
                *(unsigned *)(e + nameoff) = nm; *(unsigned *)e = bk[nm & mask]; bk[nm & mask] = e; if (g_nnames < 64) g_names[g_nnames++] = nm; }
            break; }
        case GF_PARR: { unsigned nn = grange(g->a, g->b); unsigned arr = gb_alloc(nn * 4 + 4);
            for (unsigned k = 0; k < nn; k++) *(unsigned *)(arr + k * 4) = gb_build(gfind_type(g->tname), depth + 1);
            *(unsigned *)(b + g->off) = arr; *(unsigned *)(b + g->c) = nn; break; }
        case GF_ISTR: { char txt[96]; snprintf(txt, sizeof txt, "%s", g->text); int na = 1; for (char *q = txt; *q; q++) if (*q == '|') na++;
            int pick = rnd32() % na; char *s0 = txt; for (int k = 0; k < pick; k++) s0 = strchr(s0, '|') + 1; char *e = strchr(s0, '|'); if (e) *e = 0; memcpy(b + g->off, s0, strlen(s0) + 1); break; }
        case GF_WARR: { unsigned nn = grange(g->a, g->b); unsigned arr = gb_alloc(nn * 4 + 4); for (unsigned k = 0; k < nn; k++) *(unsigned *)(arr + k * 4) = g->v[rnd32() % g->n];
            *(unsigned *)(b + g->off) = arr; if (g->c != 0xffffffffu) *(unsigned *)(b + g->c) = nn; break; }
        case GF_FN: *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_nop; break;
        case GF_DPTR: *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gaddr(g->tname); break;
        case GF_FND: *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_nopd; break;
        case GF_FNREC: *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_rec; break;
        case GF_FNRECV: *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_recv; break;
        case GF_FNRECW: *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_recw; break;
        case GF_FNRECP: *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_recp; break;
        case GF_FNREC1: *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_rec1; break;
        case GF_DVAL: *(unsigned *)(b + g->off) = *gaddr(g->tname) + g->a; break;
        case GF_FNQ: if (g->c < 16) { gs_qv[g->c] = g->v[rnd32() % g->n]; *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_qtab[g->c]; } break;
        case GF_FNQP: if (g->c < 16) { gs_qv[g->c] = (rnd32() % 100 < g->a) ? gb_build(gfind_type(g->tname), depth + 1) : 0; *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_qtab[g->c]; } break;
        case GF_FFILL: { float lo, hi; memcpy(&lo, &g->v[0], 4); memcpy(&hi, &g->v[1], 4); for (unsigned k = 0; k + 4 <= g->a; k += 4) { unsigned r = rnd32(), w; if ((r & 15) == 0) { static const unsigned sp[4] = { 0x7fc00000u, 0x7f800000u, 0xff800000u, 0x80000000u }; w = sp[(r >> 4) & 3]; } else { float f = lo + (hi - lo) * ((float)(rnd32() >> 8) / 16777216.0f); memcpy(&w, &f, 4); } *(unsigned *)(b + g->off + k) = w; } break; }
        case GF_RANDFILL: for (unsigned k = 0; k + 4 <= g->a; k += 4) *(unsigned *)(b + g->off + k) = rnd32() % g->b; break;   /* LEN bytes of small random words: a block of fields the code only reads */
        case GF_U8: b[g->off] = (unsigned char)grange(g->a, g->b); break;
        case GF_U16: *(unsigned short *)(b + g->off) = (unsigned short)grange(g->a, g->b); break;
        case GF_U32: *(unsigned *)(b + g->off) = grange(g->a, g->b); break;
        case GF_RAND: *(unsigned *)(b + g->off) = rnd32(); break;
        case GF_SET: *(unsigned *)(b + g->off) = g->a; break;
        case GF_PICK: *(unsigned *)(b + g->off) = g->v[rnd32() % g->n]; break;
        case GF_PADD: *(unsigned *)(b + g->off) = *(unsigned *)(b + g->a) + g->v[rnd32() % g->n]; break;
        case GF_FNREC3: *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_rec3; break;
        case GF_FNREC3A: *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_rec3a; break;
        case GF_FNRECA: *(unsigned *)(b + g->off) = (unsigned)(uintptr_t)gs_reca; break;
        case GF_BITS: *(unsigned *)(b + g->off) = rnd32() & g->a; break;
        case GF_STR: { char txt[96]; snprintf(txt, sizeof txt, "%s", g->text); int na = 1; for (char *q = txt; *q; q++) if (*q == '|') na++;
            int pick = rnd32() % na; char *s0 = txt; for (int k = 0; k < pick; k++) { s0 = strchr(s0, '|') + 1; } char *e = strchr(s0, '|'); if (e) *e = 0;
            { char *w = s0; for (char *r = s0; *r; r++) { if (r[0] == '\\' && r[1] == 'r') { *w++ = '\r'; r++; } else if (r[0] == '\\' && r[1] == 'n') { *w++ = '\n'; r++; } else *w++ = *r; } *w = 0; }   /* \r and \n in the text are the control characters */
            unsigned sa = gb_alloc((unsigned)strlen(s0) + 1); memcpy((void *)sa, s0, strlen(s0) + 1); *(unsigned *)(b + g->off) = sa; break; }
        }
    }
    return a;
}
/* build the graph for function `name` and store the declared arguments into ia[]; returns 1 when the function has a spec */
static int apply_graph(const char *name, unsigned *ia, unsigned *sa) {   /* `arg N` with N = 8..15 sets the caller-stack word N-8 (the 9th.. integer parameter) */
    int nalt = 0, alt[16]; for (int i = 0; i < ngfuncs && nalt < 16; i++) if (!strcmp(gfuncs[i].name, name)) alt[nalt++] = i;   /* several `func` blocks of one name are alternatives, one is drawn per trial */
    snprintf(gs_curfunc, sizeof gs_curfunc, "%s", name);
    if (nalt) { int i = alt[nalt > 1 ? rnd32() % nalt : 0];
        gfunc_t *f = &gfuncs[i]; gb_next = ARENA_BASE + 0x1000; g_nnames = 0; gm_next = GM_LO; gs_first_cnt = 0xffffffffu; gs_lg_n = 0xffffffffu;
        for (int k = 0; k < f->na; k++) { garg_t *a = &f->a[k]; if (a->n < 0 || a->n >= 16) continue; unsigned *slot = a->n < 8 ? &ia[a->n] : &sa[a->n - 8];
            switch (a->kind) {
            case GA_PTR: *slot = (rnd32() % 100 < (unsigned)a->pct) ? gb_build(gfind_type(a->tname), 0) : 0; break;
            case GA_INT: *slot = grange(a->a, a->b); break;
            case GA_PICK: *slot = a->v[rnd32() % a->nv]; break;
            case GA_RAND: *slot = rnd32(); break;
            case GA_NULL: *slot = 0; break;
            case GA_STR: { char txt[96]; snprintf(txt, sizeof txt, "%s", a->text); int na = 1; for (char *q = txt; *q; q++) if (*q == '|') na++;
                int pick = rnd32() % na; char *s0 = txt; for (int q = 0; q < pick; q++) s0 = strchr(s0, '|') + 1; char *e = strchr(s0, '|'); if (e) *e = 0;
                unsigned sa = gb_alloc((unsigned)strlen(s0) + 1); memcpy((void *)sa, s0, strlen(s0) + 1); *slot = sa; break; }
            case GA_REL: { unsigned *ms = a->b < 8 ? &ia[a->b] : &sa[a->b - 8]; unsigned base = a->a ? *(unsigned *)(uintptr_t)*ms : *ms; *slot = base + a->v[rnd32() % a->nv]; break; }
            case GA_NAME: *slot = (g_nnames && rnd32() % 100 < (unsigned)a->pct) ? g_names[rnd32() % g_nnames] : 1 + rnd32() % 40; break;
            } }
        ncur_watch = 0; ncfstr = 0;
        for (int q = 0; q < nglobs; q++) { gglob_t *g = &gglobs[q]; if (strcmp(g->func, name)) continue;
            switch (g->kind) {
            case GG_COPY: { gtype_t *t = gfind_type(g->tname); unsigned src = gb_build(t, 0); memcpy(gaddr(g->name), (void *)src, t->size); break; }
            case GG_PTR: *gaddr(g->name) = (rnd32() % 100 < g->pct) ? gb_build(gfind_type(g->tname), 0) : 0; break;
            case GG_SET: *gaddr(g->name) = g->a; break;
            case GG_WATCH: if (ncur_watch < 8) { cur_watch[ncur_watch].p = gaddr(g->name); cur_watch[ncur_watch].words = (int)g->a; ncur_watch++; } break;
            case GG_ENV: { char txt[96]; snprintf(txt, sizeof txt, "%s", g->text); int na = 1; for (char *c2 = txt; *c2; c2++) if (*c2 == '|') na++;
                int pick = rnd32() % na; char *s0 = txt; for (int k = 0; k < pick; k++) s0 = strchr(s0, '|') + 1; char *e = strchr(s0, '|'); if (e) *e = 0;
                if (!strcmp(s0, "-")) unsetenv(g->name); else setenv(g->name, s0, 1); break; }
            default: break; } }
        return 1;
    }
    return 0;
}

/* semantics of the library imports the graph mocks model (the same for both images): the return objects declared by `ret`/`retpick`, and the list/stream operations whose effect on the arena the
   functions under test read back (PPParserAttachStream, PPStreamChunkListAddChunk, ...CreateFromChunkList, ...CreateFromChunk, ...GetStream). List head: +0 first, +8 count; node: +8 next, 0x40 bytes. */
static int gs_semantic(const char *nm, unsigned *a, unsigned *r) {
    #define INARENA(v) ((v) >= ARENA_BASE + 0x1000 && (v) <= ARENA_BASE + ARENA_SIZE - 0x50)
    int outdone = 0;
    for (int i = 0; i < ngouts; i++) if (!strcmp(gouts[i].name, nm) && (!gouts[i].func[0] || !strcmp(gouts[i].func, gs_curfunc))) { unsigned p = a[gouts[i].arg];
        if ((p & 3) == 0 && ((p >= 0xbf000000u && p < 0xbffffff0u) || INARENA(p))) *(unsigned *)p = gouts[i].v[rnd32() % gouts[i].nv]; outdone = 1; }
    for (int i = 0; i < ngrets; i++) if (!strcmp(grets[i].name, nm) && (!grets[i].func[0] || !strcmp(grets[i].func, gs_curfunc))) {
        if (grets[i].nv) { *r = grets[i].v[rnd32() % grets[i].nv]; return 1; }
        if (gb_next + 0x800 > GM_LO) return 0;
        if (grets[i].pct > 0 && grets[i].pct < 100 && rnd32() % 100 >= (unsigned)grets[i].pct) { *r = 0; return 1; }   /* `ret IMPORT TYPE PCT`: the object only PCT percent of the calls, else NULL */
        *r = gb_build(gfind_type(grets[i].tname), 0); return 1; }
    if (outdone) return 1;
    for (int q = 0; q < nglobs; q++) { gglob_t *g = &gglobs[q]; if (strcmp(g->func, gs_curfunc)) continue;
        if (g->kind == GG_CFSTR && !strcmp(g->name, nm)) {   /* a CF property whose value is a string: a pointer to the characters in a harness pool (or NULL) */
            char txt[96]; snprintf(txt, sizeof txt, "%s", g->text); int na = 1; for (char *c2 = txt; *c2; c2++) if (*c2 == '|') na++;
            int pick = rnd32() % na; char *s0 = txt; for (int k = 0; k < pick; k++) s0 = strchr(s0, '|') + 1; char *e = strchr(s0, '|'); if (e) *e = 0;
            if (!strcmp(s0, "-") || ncfstr >= 32) { *r = 0; return 1; }
            snprintf(cfstr_pool[ncfstr], sizeof cfstr_pool[0], "%s", s0); *r = (unsigned)(uintptr_t)cfstr_pool[ncfstr++]; return 1; }
        if (g->kind == GG_SCANDIR && !strcmp(nm, "scandir")) {   /* scandir(dir, &list, ...): n entries (struct dirent: d_name at +8), the array and the entries allocated on the heap the code frees */
            char txt[96]; snprintf(txt, sizeof txt, "%s", g->text); char *nmz[16]; int nn = 0; for (char *p2 = strtok(txt, "|"); p2 && nn < 16; p2 = strtok(NULL, "|")) nmz[nn++] = p2;
            int n = (int)(rnd32() % (g->a + 1)); unsigned *lp = (unsigned *)a[1];
            if (gm_next < GM_LO) gm_next = GM_LO; if (!n || gm_next + 16 + 0x10 * 4 + (unsigned)n * 0x120 > GM_HI) { if (INARENA((unsigned)lp)) *lp = 0; *r = 0; return 1; }
            unsigned arr = gm_next + 16; gm_next += 16 + ((unsigned)n * 4 + 15 & ~15u); *(unsigned *)(arr - 16) = (unsigned)n * 4;
            for (int k = 0; k < n; k++) { unsigned d = gm_next + 16; gm_next += 16 + 0x110; *(unsigned *)(d - 16) = 0x108; memset((void *)d, 0, 0x108); const char *nn2 = nmz[rnd32() % nn]; memcpy((char *)d + 8, nn2, strlen(nn2) + 1); ((unsigned *)arr)[k] = d; }
            if ((((unsigned)lp & 3) == 0) && (((unsigned)lp >= 0xbf000000u && (unsigned)lp < 0xbffffff0u) || INARENA((unsigned)lp))) *lp = arr; *r = (unsigned)n; return 1; } }
    if (!strcmp(nm, "CFStringGetLength") && (const char *)a[0] >= cfstr_pool[0] && (const char *)a[0] <= cfstr_pool[31]) { *r = (unsigned)strlen((const char *)a[0]); return 1; }
    if (!strcmp(nm, "CFStringGetCStringPtr") && (const char *)a[0] >= cfstr_pool[0] && (const char *)a[0] <= cfstr_pool[31]) { *r = (rnd32() % 2) ? a[0] : 0; return 1; }
    if (!strcmp(nm, "CFStringGetCString") && (const char *)a[0] >= cfstr_pool[0] && (const char *)a[0] <= cfstr_pool[31]) { size_t L = strlen((const char *)a[0]); if (a[2] > L && a[1] && rnd32() % 5) { memcpy((void *)a[1], (const void *)a[0], L + 1); *r = 1; } else *r = 0; return 1; }
    if (!strcmp(nm, "CFRelease")) { *r = 0; return 1; }
    if (!strcmp(nm, "PPStreamGetStream")) {   /* (manager, buf, &count): the stream as pairs of words; count pairs (0, or 6..11), pair 5 = (number of entries c, first entry index), entries (type<<16 | small index, word) from pair 6 on: what _gleShaderDataUpdateParams walks */
        if (gs_lg_n == 0xffffffffu) { gs_lg_n = 6 + rnd32() % 6; gs_lg_c = rnd32() % 4; if (gs_lg_n - gs_lg_c < 6) gs_lg_c = 0; gs_lg_o = 6 + rnd32() % (gs_lg_n - gs_lg_c - 6 + 1); }   /* never 0: with an empty stream the code (stock too) hands _gleShaderDataUpdateParams a NULL buffer and faults at +0x28, which would hide everything after it */
        unsigned n = gs_lg_n; if (cur_img == 1 && imp_ctl && !strcmp(imp_ctl, "PPStreamGetStream")) n++;
        unsigned *cp = (unsigned *)a[2]; if (((unsigned)cp & 3) == 0 && (((unsigned)cp >= 0xbf000000u && (unsigned)cp < 0xbffffff0u) || INARENA((unsigned)cp))) *cp = n;
        if (a[1] >= GM_LO && n && a[1] < GM_HI - 8 * n) { unsigned *bf = (unsigned *)a[1]; bf[10] = gs_lg_c; bf[11] = gs_lg_o;
            for (unsigned k = 6; k < n; k++) { bf[2 * k] = (1 + rnd32() % 12) << 16 | rnd32() % 8; bf[2 * k + 1] = rnd32() % 4; } }
        *r = 0; return 1; }
    if (!strcmp(nm, "PPStreamAttachOperationsChunkList")) { if (INARENA(a[0])) *(unsigned *)(a[0] + 0x20) = a[1]; return 1; }
    if (!strcmp(nm, "PPStreamAttachParamBindingsChunkList")) { if (INARENA(a[0])) *(unsigned *)(a[0] + 0x10) = a[1]; return 1; }
    if (!strcmp(nm, "PPStreamAttachParamBindingArraysChunkList")) { if (INARENA(a[0])) *(unsigned *)(a[0] + 0x14) = a[1]; return 1; }
    if (!strcmp(nm, "PPStreamChunkListSort") || !strcmp(nm, "PPStreamAddOperation") || !strcmp(nm, "PPStreamAddParamBinding") || !strcmp(nm, "PPStreamAddOutputBinding") || !strcmp(nm, "PPStreamAddTempUsage")) return 1;   /* records are only handed over: no write through the arguments */
    if (!strcmp(nm, "PPParserAttachStream")) { if (INARENA(a[0])) *(unsigned *)(a[0] + 0x1c) = a[1]; return 1; }
    if (!strcmp(nm, "PPStreamChunkListAddChunk")) { if (INARENA(a[0]) && INARENA(a[1])) { unsigned *hd = (unsigned *)a[0]; *(unsigned *)(a[1] + 8) = 0;
            if (!hd[0]) hd[0] = a[1]; else { unsigned pp = hd[0]; for (int g = 0; g < 64 && INARENA(pp) && *(unsigned *)(pp + 8); g++) pp = *(unsigned *)(pp + 8); if (INARENA(pp)) *(unsigned *)(pp + 8) = a[1]; }
            hd[2]++; } return 1; }
    if (!strcmp(nm, "PPStreamChunkCreateFromChunk")) { if (INARENA(a[0]) && gb_next + 0x100 < GM_LO) { unsigned n = gb_alloc(0x40); memcpy((void *)n, (void *)a[0], 0x40); *(unsigned *)(n + 8) = 0; *r = n; } return 1; }
    if (!strcmp(nm, "PPStreamChunkListCreateFromChunkList")) { if (INARENA(a[0]) && gb_next + 0x1000 < GM_LO) { unsigned h = gb_alloc(0x10); memcpy((void *)h, (void *)a[0], 0x10); unsigned prev = 0, src = *(unsigned *)a[0]; *(unsigned *)h = 0;
            for (int g = 0; g < 16 && INARENA(src); g++, src = *(unsigned *)(src + 8)) { unsigned n = gb_alloc(0x40); memcpy((void *)n, (void *)src, 0x40); *(unsigned *)(n + 8) = 0; if (prev) *(unsigned *)(prev + 8) = n; else *(unsigned *)h = n; prev = n; }
            *r = h; } return 1; }
    if (!strcmp(nm, "PPStreamChunkListGetStream")) {   /* (list, buf, &count, stream): count = nodes in the list; buf (when non-NULL) gets count (first, last) index pairs, each below the first list's count (the params list; the param-array list refers to ranges of it) */
        unsigned n = 0, src = INARENA(a[0]) ? *(unsigned *)a[0] : 0; for (int g = 0; g < 16 && INARENA(src); g++, src = *(unsigned *)(src + 8)) n++;
        if (gs_first_cnt == 0xffffffffu) gs_first_cnt = n;
        if (((a[2] & 3) == 0) && ((a[2] >= 0xbf000000u && a[2] < 0xbffffff0u) || INARENA(a[2]))) *(unsigned *)a[2] = n;   /* the count goes to a stack local or an arena word */
        if (a[1] >= GM_LO && n && a[1] < GM_HI - 8 * n) { unsigned lim = gs_first_cnt ? gs_first_cnt : 1;
            for (unsigned k = 0; k < n; k++) { unsigned lo = k % lim, hi = lo + (rnd32() % 2 && lo + 1 < lim); ((unsigned *)a[1])[2 * k] = lo; ((unsigned *)a[1])[2 * k + 1] = hi; } }
        *r = 0; return 1; }
    #undef INARENA
    return 0;
}
static unsigned alarm_us = 300000;
static struct { unsigned addr, val; } cur_patch[16]; static int ncur_patch; static unsigned cur_apatch[8];   /* FNFUZZ_REPAIR: arena words the repair loop found must be pointers */
static int nohandlers;
static void child(void *fn, const cand_t *c, unsigned seed, int mode) {
    if (!nohandlers) {
        ualarm(alarm_us, 0);   /* a pure function finishes in microseconds; anything longer is a hang (both images are treated alike) */
        if (getenv("FNFUZZ_REPAIR")) { struct sigaction sa; memset(&sa, 0, sizeof sa); sa.sa_sigaction = on_sig_info; sa.sa_flags = SA_SIGINFO; sigemptyset(&sa.sa_mask); sigaction(SIGSEGV, &sa, NULL); sigaction(SIGBUS, &sa, NULL); } else { signal(SIGSEGV, on_sig); signal(SIGBUS, on_sig); } signal(SIGILL, on_sig); signal(SIGFPE, on_sig); signal(SIGTRAP, on_sig); signal(SIGABRT, on_sig); signal(SIGALRM, on_sig); signal(SIGSYS, on_sig);
    }
    void *m = mmap((void *)ARENA_BASE, ARENA_SIZE, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANON | MAP_PRIVATE, -1, 0);
    if (m != (void *)ARENA_BASE) _exit(9);
    /* guard regions: a read or write just past the arena (a loop that walks 0x48-byte records until a count the fuzz made huge) must fault the same way in both images. Without them the outcome depended on where libc/dyld
       happened to place a block after the arena in that child (psnDumpPixelShader: stock SIGSEGV, rebuilt a normal return with the identical arena digest, Nov 12). */
    mmap((void *)(ARENA_BASE + ARENA_SIZE), 0x10000, PROT_NONE, MAP_FIXED | MAP_ANON | MAP_PRIVATE, -1, 0);
    mmap((void *)(ARENA_BASE - 0x10000), 0x10000, PROT_NONE, MAP_FIXED | MAP_ANON | MAP_PRIVATE, -1, 0);
    rng_state = (unsigned long long)seed * 2862933555777941757ULL + c->id;
    if (vtmode) {
        /* the callback is reached through a trampoline whose leading words are data that is harmless if a stray double dereference reads them as a pointer or a function address: word 0 = `b +0x40`
           (0x48000040: unmapped), words 1..15 = 0 (NULL), the code starts at +0x40 (lis/ori/mtctr/bctr to gs_vtcb: the words 0x3d80xxxx, 0x618cxxxx, 0x7d8903a6, 0x4e800420 are unmapped addresses too).
           Without it a vtable-page pointer used as an OBJECT made `*(*obj + 4)` read the callback's own code bytes (`stw r0,8(r1)` = 0x90010008, an address inside libc) and call real libc code (Nov 12, Block__dtor). */
        unsigned *tr = mmap((void *)VT_TR, 0x1000, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_FIXED | MAP_ANON | MAP_PRIVATE, -1, 0); if (tr != (unsigned *)VT_TR) _exit(9);
        unsigned fa = (unsigned)(uintptr_t)gs_vtcb; memset(tr, 0, 0x1000); tr[0] = 0x48000040u; tr[16] = 0x3d800000u | (fa >> 16); tr[17] = 0x618c0000u | (fa & 0xffff); tr[18] = 0x7d8903a6u; tr[19] = 0x4e800420u;
        for (unsigned o = 0; o < 0x100; o += 16) __asm__ volatile("dcbst 0,%0\n\tsync\n\ticbi 0,%0\n\tsync\n\tisync" : : "r"((char *)tr + o) : "memory");   /* the page was written as data: flush it to the instruction cache */
        unsigned *vp = mmap((void *)VT_BASE, VT_WORDS * 4, PROT_READ | PROT_WRITE, MAP_FIXED | MAP_ANON | MAP_PRIVATE, -1, 0); if (vp != (unsigned *)VT_BASE) _exit(9); for (unsigned i = 0; i < VT_WORDS; i++) vp[i] = VT_TR; mprotect(vp, VT_WORDS * 4, PROT_READ);
    }
    if (interpose) { ncalls_c = 0; trace_c = 0; memset(mask_c, 0, sizeof mask_c); ret_state = (unsigned long long)seed * 0x9E3779B97F4A7C15ULL + c->id; install_stubs(cur_img); }
    unsigned *w = (unsigned *)ARENA_BASE;
    for (unsigned i = 0; i < ARENA_SIZE / 4; i++) { unsigned k = rnd32() % 10; w[i] = graph ? (k < 2 ? 0 : k < 4 ? rnd32() % 64 : (vtmode && rnd32() % 4 == 0) ? vt_ptr() : arena_ptr()) : tiny ? (k < 6 ? 0 : k < 9 ? rnd32() % 16 : arena_ptr()) : (k < 3 ? 0 : k < 6 ? rnd32() % 64 : k < 7 ? (narrow ? rnd32() % 256 : rnd32()) : arena_ptr()); }
    if (nanmode) for (unsigned i = 0; i < ARENA_SIZE / 4; i++) if (rnd32() % 24 == 0) w[i] = nan_wrd[rnd32() % (sizeof nan_wrd / sizeof *nan_wrd)];
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
    if (ngfuncs) apply_graph(c->name, ia, sa);
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
    for (int q = 0; q < ncur_patch; q++) *(unsigned *)cur_patch[q].addr = cur_patch[q].val;
    for (int q = 0; q < 8; q++) if (cur_apatch[q]) { ia[q] = cur_apatch[q]; cur_args[q] = ia[q]; }
    { const char *sf = getenv("FNFUZZ_STACKFILL"); if (use_fill2 && getenv("FNFUZZ_STACKFILL2")) sf = getenv("FNFUZZ_STACKFILL2"); if (sf) { stackfill_word = (unsigned)strtoul(sf, NULL, 16); fill_stack(); } }
    if (mode == 0) { unsigned long long r = ((fi_t)fn)(ia[0], ia[1], ia[2], ia[3], ia[4], ia[5], ia[6], ia[7], sa[0], sa[1], sa[2], sa[3], sa[4], sa[5], sa[6], sa[7], sa[8], sa[9], sa[10], sa[11], sa[12], sa[13], sa[14], sa[15], da[0], da[1], da[2], da[3], da[4], da[5], da[6], da[7], da[8], da[9], da[10], da[11], da[12]); report(0, (unsigned)(r >> 32), (unsigned)r, 0); }
    else { double r = ((fd_t)fn)(ia[0], ia[1], ia[2], ia[3], ia[4], ia[5], ia[6], ia[7], sa[0], sa[1], sa[2], sa[3], sa[4], sa[5], sa[6], sa[7], sa[8], sa[9], sa[10], sa[11], sa[12], sa[13], sa[14], sa[15], da[0], da[1], da[2], da[3], da[4], da[5], da[6], da[7], da[8], da[9], da[10], da[11], da[12]); unsigned long long b; memcpy(&b, &r, 8); report(0, 0, 0, b); }
}

static unsigned *last_arena[3];
static void trial_log(const cand_t *c, unsigned seed, int mode, int img) {
    /* FNFUZZ_TRIALLOG=file: append (and flush to disk) one line BEFORE each child is forked, so a kernel panic that takes the machine down leaves the trial, image and seed that was running as the last line */
    static int lfd = -2; static unsigned long nrun;
    if (lfd == -2) { const char *f = getenv("FNFUZZ_TRIALLOG"); lfd = f ? open(f, O_WRONLY | O_CREAT | O_APPEND, 0644) : -1; }
    if (lfd < 0) return;
    char b[160]; int n = snprintf(b, sizeof b, "RUN %lu id %d seed %u mode %d img %c fill2 %d alarm %u\n", ++nrun, c->id, seed, mode, img ? 'R' : 'S', use_fill2, alarm_us);
    (void)!write(lfd, b, n);
#ifdef F_FULLFSYNC
    if (getenv("FNFUZZ_TRIALLOG_FULL")) fcntl(lfd, F_FULLFSYNC, 0);   /* the default is plain fsync: cheap, and the line still reaches the disk before the fork */
#endif
    fsync(lfd);
}
static int run_one(void *fn, const cand_t *c, unsigned seed, int mode, int img, result_t *out) {
    trial_log(c, seed, mode, img);
    int fd[2]; if (pipe(fd)) return -1;
    fflush(stdout);   /* a child that calls exit() would flush the parent's pending lines a second time */
    pid_t p = fork();
    if (p == 0) { close(fd[0]); wfd = fd[1]; cur_img = img; nrng = 0; image_ranges(img_hdr[0]); image_ranges(img_hdr[1]); if (getenv("FNFUZZ_RANGES")) { for (int q = 0; q < nrng; q++) fprintf(stderr, "range %08x-%08x\n", rng_lo[q], rng_hi[q]); } child(fn, c, seed, mode); _exit(8); }
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

/* FNFUZZ_ADDRDEP=name[,name...]: functions whose arena result is a hash of CODE addresses (_gleOptimizeDisplayListCreateHashTable: bucket = function pointer & 0x7c); the two images' functions
   cannot share low address bits, so the bucket layout differs by construction. For these the arena digest is left out of the comparison: status, call count, call trace (sizes of every
   malloc/calloc, the same imports in the same order) and the return value still have to agree. */
static int cur_addrdep;
static int same(const result_t *a, const result_t *b, char rc) {
    if ((a->status != 0) != (b->status != 0)) return 0;
    if (a->status) return 1;                       /* both died (SIGBUS vs SIGSEGV is only the kind of wild address) */
    if (interpose && (a->ncalls != b->ncalls || a->trace != b->trace || memcmp(a->mask, b->mask, sizeof a->mask))) return 0;
    if (a->digest != b->digest && !cur_addrdep) return 0;
    if (rc == 'i') return a->r3 == b->r3;
    if (rc == 'd') { double x, y; memcpy(&x, &a->f1, 8); memcpy(&y, &b->f1, 8); return a->f1 == b->f1 || (x != x && y != y) || fabs(x - y) <= 1e-5 * fmax(1.0, fmax(fabs(x), fabs(y))); }
    return 1;
}

int main(int argc, char **argv) {
    if (argc < 4) { fprintf(stderr, "usage: fnfuzz LEDGER.tsv STOCK REBUILT [trials] [filter|@first,count]\n"); return 2; }
    nanmode = getenv("FNFUZZ_NANMODE") != NULL; nancanon = getenv("FNFUZZ_NANCANON") != NULL;
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
    g_cs = cs; g_nc = nc; g_ap[0] = ap[0]; g_ap[1] = ap[1]; g_astock = a_stock; g_areb = a_reb;
    if (getenv("FNFUZZ_DATA")) { FILE *df = fopen(getenv("FNFUZZ_DATA"), "r"); if (!df) { perror("FNFUZZ_DATA"); return 2; } char dl[256]; while (fgets(dl, sizeof dl, df) && ngdat < 32) { if (sscanf(dl, "%47s\t%x\t%x", gdat[ngdat].name, &gdat[ngdat].st, &gdat[ngdat].rb) == 3) ngdat++; } fclose(df); }
    if (getenv("FNFUZZ_GRAPHSPEC")) { gs_malloc = 1; load_graphspec(getenv("FNFUZZ_GRAPHSPEC")); }
    vtmode = getenv("FNFUZZ_VT") != NULL; interpose = getenv("FNFUZZ_INTERPOSE") != NULL; imp_ctl = getenv("FNFUZZ_IMPORT_CTL");
    if (interpose) { init_retblk(); collect_slots(0, img_hdr[0]); collect_slots(1, img_hdr[1]); load_nargs(); load_stackrec(); fprintf(stderr, "interposer: %d stock slots, %d rebuilt slots, %d distinct imports\n", nslots[0], nslots[1], nstub); }
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
        cur_addrdep = 0; { const char *ad = getenv("FNFUZZ_ADDRDEP"); if (ad) { char bb[512]; snprintf(bb, sizeof bb, ",%s,", ad); char nn[160]; snprintf(nn, sizeof nn, ",%s,", c->name); cur_addrdep = strstr(bb, nn) != NULL; } }
        int diffs = 0, good = 0, crash2 = 0, nd = 0, live = 0, nrun_ok = 0, npatched = 0; unsigned lmask[5] = { 0, 0, 0, 0, 0 }, lcalls = 0; char why[360] = "";
        for (int t = 0; t < trials; t++) {
            unsigned seed = 0x9e3779b1u * (t + 1) + c->id * 7919u;
            result_t a, a2, b;
            for (int mode = 0; mode < (c->rc == 'd' ? 2 : 1); mode++) {
                if (c->rc == 'd' && mode == 0) { /* the digest is checked in the integer-return run, f1 in the second */ }
                ncur_patch = 0; memset(cur_apatch, 0, sizeof cur_apatch); unsigned last_pc = 0, last_ra = 0;
                if (getenv("FNFUZZ_REPAIR")) for (int it = 0; it < 16; it++) { result_t r0; run_one(fn[0], c, seed, mode, 0, &r0);
                    if (getenv("FNFUZZ_REPAIR_DEBUG")) printf("  repair %s trial %d it %d: st=%d fix=%u src=%08x arg=%u disp=%d args %x %x pc %08x word %08x ra-value %08x\n", c->name, t, it, r0.status, r0.fix_valid, r0.fix_src, r0.fix_arg, (int)r0.fix_disp, r0.args[0], r0.args[1], r0.fault_pc, r0.fault_pc ? 0u : 0u, r0.fault_ra);
                    if ((r0.status != 11 && r0.status != 10) || !r0.fix_valid) break;
                    if (r0.fault_pc == last_pc && r0.fault_ra == last_ra) break;   /* the patch did not move the fault: the base is not what the backward scan found */
                    last_pc = r0.fault_pc; last_ra = r0.fault_ra;
                    int disp = (int)r0.fix_disp; unsigned lo = ARENA_BASE + 0x1000 + (disp < 0 ? -disp : 0), hi = ARENA_BASE + ARENA_SIZE - 0x1000 - (disp > 0 ? disp : 0) - 0x80;
                    if (hi <= lo) break;
                    unsigned h = (seed ^ 0x5bd1e995u) * (unsigned)(it * 2 + 3); h ^= h >> 15; h *= 0x2c1b3c6du; h ^= h >> 12;
                    unsigned val = (lo + h % (hi - lo)) & ~15u; if (val < lo) val += 16;
                    if (r0.fix_arg) { cur_apatch[r0.fix_arg - 1] = val; continue; }
                    int q = 0; while (q < ncur_patch && cur_patch[q].addr != r0.fix_src) q++;
                    if (q == ncur_patch) { if (ncur_patch >= 16) break; ncur_patch++; }
                    cur_patch[q].addr = r0.fix_src; cur_patch[q].val = val; }
                run_one(fn[0], c, seed, mode, 0, &a);
                use_fill2 = 1; run_one(fn[0], c, seed, mode, 0, &a2); use_fill2 = 0;
                run_one(fn[1], c, seed, mode, 1, &b);
                ntrials++; if (!a.status && !b.status) nrun_ok++; if (ncur_patch || cur_apatch[0] || cur_apatch[1] || cur_apatch[2] || cur_apatch[3]) npatched++;
                if (!same(&a, &a2, c->rc)) { nd++; continue; }
                if ((a.status == 14) != (b.status == 14)) {   /* a hang on one side only: the -O0 rebuild is several times slower than the -O2 stock on a long loop (`_pow_10(0x5000ec80)`), and machine load adds to it - rerun both with a 6 s limit before blaming the code */
                    alarm_us = 6000000; run_one(fn[0], c, seed, mode, 0, &a); run_one(fn[1], c, seed, mode, 1, &b); alarm_us = 300000;
                }
                if (a.status && b.status && a.status == b.status) crash2++;
                if (interpose && !a.status && !b.status && a.ncalls) { live++; lcalls += a.ncalls; for (int q = 0; q < 5; q++) lmask[q] |= a.mask[q]; }
                if (same(&a, &b, mode ? 'd' : (c->rc == 'd' ? 'v' : c->rc))) good++;
                else { diffs++;
                    /* FNFUZZ_DUMPARENA=prefix (with FNFUZZ_VERBOSE): the whole arena of the FIRST differing trial of each function, as prefix.S / prefix.R (ARENA_BASE-relative, 0x20000 bytes) - the
                       inputs are in it too (the function only changes what it writes), so the differing computation can be replayed by hand / in a script */
                    if (getenv("FNFUZZ_DUMPARENA") && getenv("FNFUZZ_VERBOSE") && last_arena[0] && last_arena[1] && diffs == 1) {
                        char fnm[300]; for (int im = 0; im < 2; im++) { snprintf(fnm, sizeof fnm, "%s.%c", getenv("FNFUZZ_DUMPARENA"), im ? 'R' : 'S'); FILE *df = fopen(fnm, "wb"); if (df) { fwrite(last_arena[im], 1, ARENA_SIZE, df); fclose(df); } }
                        fprintf(stderr, "arena of trial %d written to %s.S / .R\n", t, getenv("FNFUZZ_DUMPARENA")); }
                    if (getenv("FNFUZZ_VERBOSE") && last_arena[0] && last_arena[1] && diffs <= 2) { int nd2 = 0; for (unsigned q = 0; q < ARENA_SIZE / 4 && nd2 < 10; q++) if (last_arena[0][q] != last_arena[1][q]) { printf("   arena+%05x: stock %08x rebuilt %08x\n", q * 4, last_arena[0][q], last_arena[1][q]); nd2++; if (getenv("FNFUZZ_CONTEXT")) for (int c = (q >= 6 ? -6 : -(int)q); c < 7; c++) printf("      +%d: stock %08x rebuilt %08x\n", c * 4, last_arena[0][q + c], last_arena[1][q + c]); } }
                    if (!why[0]) snprintf(why, sizeof why, "trial %d mode %d: stock st=%d r3=%08x f1=%016llx dg=%08x | rebuilt st=%d r3=%08x f1=%016llx dg=%08x | args %x %x %x %x %x | dargs %016llx %016llx %016llx %016llx | calls %u/%u trace %08x/%08x mask %08x%08x/%08x%08x", t, mode, a.status, a.r3, a.f1, a.digest, b.status, b.r3, b.f1, b.digest, a.args[0], a.args[1], a.args[2], a.args[3], a.args[4], *(unsigned long long *)&a.dargs[0], *(unsigned long long *)&a.dargs[1], *(unsigned long long *)&a.dargs[2], *(unsigned long long *)&a.dargs[3], a.ncalls, b.ncalls, a.trace, b.trace, a.mask[1], a.mask[0], b.mask[1], b.mask[0]); }
            }
        }
        ncomp++;
        if (getenv("FNFUZZ_REPAIR") && getenv("FNFUZZ_LISTUNINF")) printf("RUN %-40s %d/%d trials ran to the end in both images (%d trials needed patches)\n", c->name, nrun_ok, trials * (c->rc == 'd' ? 2 : 1), npatched);
        if (interpose) { char nm[1200] = ""; for (int q = 0; q < nstub; q++) if (lmask[q >> 5] & (1u << (q & 31))) { if (strlen(nm) + 60 < sizeof nm) { strcat(nm, " "); strcat(nm, stub_names[q]); } }
            printf("IMP %-40s live %d/%d trials (%d ended in a fault in both images), %u calls, imports:%s\n", c->name, live, trials, crash2, lcalls, nm[0] ? nm : " -"); if (live) nlive++; }
        if (nd == trials * (c->rc == 'd' ? 2 : 1)) { nnondet++; continue; }
        if (diffs) { ndiff++; printf("DIFF %-40s %x (%s->%c, %d trials: %d differ, %d agree) %s\n", c->name, c->stock_addr, c->pc, c->rc, trials, diffs, good, why); }
        else if (crash2 && good == crash2) { nuninf++; if (getenv("FNFUZZ_LISTUNINF")) printf("UNINF %-40s %x (%s->%c) every one of %d trials ended in a signal in both images\n", c->name, c->stock_addr, c->pc, c->rc, trials); }
        nboth_crash += crash2;
    }
    if (interpose) printf("interposer: %d of %d functions reached at least one stubbed import in a trial that ended normally in both images\n", nlive, ncomp);
    printf("fnfuzz: %d functions, %d trials (each: stock twice + rebuilt); %d differ, %d uninformative (always the same signal), %d nondeterministic in the stock\nRESULT: %s\n",
           ncomp, ntrials, ndiff, nuninf, nnondet, ndiff == 0 ? "PASS" : "FAIL");
    return 0;
}
