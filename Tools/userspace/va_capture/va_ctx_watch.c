/* va_ctx_watch.c - DYLD_INSERT_LIBRARIES shim (G5 / Tiger ppc): find who overwrites words of the VA driver's DVD context (default: every word in ctx+[0,0x100) except the ring cursor/mapping words 0x30..0x47; env VA_WATCH_LO / VA_WATCH_HI / VA_WATCH_USLEEP).
 *
 * Found by the final-eval Phase 4 bisect (rebuilt ATIRadeonX1000VADriver crashes DVD Player; the IOKit recorder showed ctx[5] (+0x14, the IOConnect handle) turning from 0xbe07 into 0x1500001
 * between two recorded calls, i.e. inside untested rebuilt VA code). The recorder cannot see inside that gap, so this shim watches the word itself:
 *   - interposes IOServiceOpen: a client of type 3 (DVD) is only opened by the VA driver's ava_create_context, whose out-pointer is &ctx[5], so ctx = (char*)out - 0x14;
 *   - a poller thread spins on *(ctx + VA_WATCH_OFF) (default 0x14); on a change it suspends every other thread, logs old/new value, 8 words of the context around the offset, and for each other thread
 *     pc, lr, r1 and a 10-frame back-chain, each address as <image>+<offset> (so a VA address reads ATIRadeonX1000VADriver+0xNNNN), then resumes them. At most VA_WATCH_MAX (8) reports.
 * Logging uses write() on a preformatted buffer only (a suspended thread may hold the malloc / stdio locks).
 * build (G5, gcc 4.0.1):  gcc -dynamiclib -o va_ctx_watch.dylib va_ctx_watch.c -framework IOKit
 * use:   VA_WATCH_LOG=$HOME/rung3/va_cap/ctxwatch.txt DYLD_INSERT_LIBRARIES=$HOME/rung3/va_cap/va_ctx_watch.dylib "<app>"       (passive: it only reads the context and the threads' registers) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
#include <dlfcn.h>
#include <mach/mach.h>
#include <mach-o/dyld.h>
#include <mach-o/loader.h>
#include <IOKit/IOKitLib.h>

static int g_fd = -1;
static volatile unsigned *g_watch = 0;     /* the watched word */
static unsigned char *g_ctx = 0;
static unsigned g_off = 0x14, g_max = 8, g_nrep = 0, g_lo = 0, g_hi = 0x100, g_usleep = 2;
static pthread_t g_poller; static int g_poller_started = 0;
static volatile int g_active = 0, g_in = 0;      /* g_active: a live context is being watched; g_in: the poller is inside a read (handshake so the context is never freed under it) */
static volatile unsigned g_gen = 0, g_conn = 0;     /* generation counter (bumped per new context), connect handle of the watched context */
static mach_port_t g_poller_thread = 0;

static void out(const char *s) { if (g_fd >= 0) write(g_fd, s, strlen(s)); }
static void outf(const char *fmt, unsigned a, unsigned b, unsigned c, unsigned d) { char buf[256]; snprintf(buf, sizeof buf, fmt, a, b, c, d); out(buf); }

/* <image>+<offset> for an address, via dyld's image list (no allocation) */
static void sym(unsigned a, char *buf, size_t n) {
    uint32_t i, cnt = _dyld_image_count();
    for (i = 0; i < cnt; i++) {
        const struct mach_header *mh = _dyld_get_image_header(i); unsigned long slide = _dyld_get_image_vmaddr_slide(i);
        const struct load_command *lc = (const struct load_command *)((const char *)mh + sizeof(struct mach_header)); uint32_t k;
        for (k = 0; k < mh->ncmds; k++, lc = (const struct load_command *)((const char *)lc + lc->cmdsize)) {
            if (lc->cmd == LC_SEGMENT) {
                const struct segment_command *sg = (const struct segment_command *)lc;
                unsigned lo = sg->vmaddr + slide, hi = lo + sg->vmsize;
                if (a >= lo && a < hi && strcmp(sg->segname, "__PAGEZERO") != 0) {
                    const char *nm = _dyld_get_image_name(i), *b = strrchr(nm, '/'); b = b ? b + 1 : nm;
                    snprintf(buf, n, "%s+0x%x", b, a - (unsigned)mh);
                    return;
                }
            }
        }
    }
    snprintf(buf, n, "?");
}
static int readable(unsigned a) { return a > 0x1000 && a < 0xbfff0000 && !(a & 3); }

static void report(unsigned woff, unsigned oldv, unsigned newv) {
    thread_act_array_t th; mach_msg_type_number_t n, i; char s[160]; unsigned k;
    if (g_nrep >= g_max) return; g_nrep++;
    if (task_threads(mach_task_self(), &th, &n) != KERN_SUCCESS) return;
    for (i = 0; i < n; i++) if (th[i] != g_poller_thread) thread_suspend(th[i]);
    outf("=== CHANGE ctx+0x%x: 0x%x -> 0x%x   (ctx=0x%x)\n", woff, oldv, newv, (unsigned)g_ctx);
    for (k = 0; k < 8; k++) { unsigned o = (woff & ~3u) - 8 + 4 * k; outf("  ctx+0x%x = 0x%x\n", o, *(unsigned *)(g_ctx + o), 0, 0); }
    outf("  ring words: +0x30=0x%x +0x34=0x%x +0x38=0x%x +0x40=0x%x\n", *(unsigned *)(g_ctx + 0x30), *(unsigned *)(g_ctx + 0x34), *(unsigned *)(g_ctx + 0x38), *(unsigned *)(g_ctx + 0x40));
    for (i = 0; i < n; i++) {
        ppc_thread_state_t st; mach_msg_type_number_t cnt = PPC_THREAD_STATE_COUNT; unsigned p, nx; int f;
        if (th[i] == g_poller_thread) continue;
        if (thread_get_state(th[i], PPC_THREAD_STATE, (thread_state_t)&st, &cnt) != KERN_SUCCESS) continue;
        sym(st.srr0, s, sizeof s); outf("  thread %u: pc=0x%x ", (unsigned)th[i], st.srr0, 0, 0); out(s);
        sym(st.lr, s, sizeof s); outf("  lr=0x%x ", st.lr, 0, 0, 0); out(s);
        outf("  r1=0x%x r3=0x%x r30=0x%x\n", st.r1, st.r3, st.r30, 0);
        p = st.r1;
        for (f = 0; f < 10 && readable(p); f++) {
            nx = *(unsigned *)p; if (!readable(nx) || nx <= p || nx - p > 0x100000) break;
            { unsigned ra = *(unsigned *)(nx + 8); sym(ra, s, sizeof s); outf("      frame %u: ra=0x%x ", f, ra, 0, 0); out(s); out("\n"); }
            p = nx;
        }
    }
    out("=== end\n");
    for (i = 0; i < n; i++) if (th[i] != g_poller_thread) thread_resume(th[i]);
}

static void *poller(void *arg) {
    unsigned snap[0x400], i, n, gen = 0; (void)arg;
    g_poller_thread = mach_thread_self();
    for (;;) {
        if (!g_active) { gen = 0; usleep(200); continue; }
        g_in = 1;
        if (!g_active) { g_in = 0; continue; }
        n = (g_hi - g_lo) / 4;
        if (gen != g_gen) {                                              /* a new context: take the baseline */
            gen = g_gen; for (i = 0; i < n; i++) snap[i] = *(volatile unsigned *)(g_ctx + g_lo + 4 * i);
        }
        for (i = 0; i < n && g_active; i++) {
            unsigned o = g_lo + 4 * i, cur;
            if (o >= 0x30 && o < 0x48) continue;                        /* ring cursor / mapping words change all the time */
            cur = *(volatile unsigned *)(g_ctx + o);
            if (cur != snap[i]) { unsigned old = snap[i]; snap[i] = cur; g_in = 0; report(o, old, cur); g_in = 1; }
        }
        g_in = 0;
        if (g_usleep) usleep(g_usleep);
    }
    return 0;
}

static kern_return_t my_IOServiceClose(io_connect_t c) {
    if (g_active && (unsigned)c == g_conn) {                           /* the VA driver closes the connection and frees the context right after: stop reading it first */
        g_active = 0; { unsigned spin = 0; while (g_in && spin++ < 100000000) ; }
        outf("context 0x%x closed (connect 0x%x): watch stopped\n", (unsigned)g_ctx, (unsigned)c, 0, 0);
    }
    return IOServiceClose(c);
}

static kern_return_t my_IOServiceOpen(io_service_t svc, task_port_t task, uint32_t type, io_connect_t *conn) {
    kern_return_t r = IOServiceOpen(svc, task, type, conn);      /* interposing: inside the dylib this resolves to the real one */
    if (r == 0 && type == 3 && conn) {
        if (g_fd < 0) {
            const char *lp = getenv("VA_WATCH_LOG"), *o = getenv("VA_WATCH_OFF"), *m = getenv("VA_WATCH_MAX");
            const char *lo = getenv("VA_WATCH_LO"), *hi = getenv("VA_WATCH_HI"), *us = getenv("VA_WATCH_USLEEP");
            if (o) g_off = (unsigned)strtoul(o, 0, 0); if (m) g_max = (unsigned)strtoul(m, 0, 0);
            if (lo) g_lo = (unsigned)strtoul(lo, 0, 0); if (hi) g_hi = (unsigned)strtoul(hi, 0, 0); if (us) g_usleep = (unsigned)strtoul(us, 0, 0);
            if (g_hi - g_lo > 0x1000) g_hi = g_lo + 0x1000;
            g_fd = open(lp ? lp : "/tmp/va_ctx_watch.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        }
        g_active = 0; { unsigned spin = 0; while (g_in && spin++ < 100000000) ; }
        g_ctx = (unsigned char *)conn - 0x14; g_conn = (unsigned)*conn;
        outf("watching ctx=0x%x (from &ctx[5]=0x%x) connect 0x%x, region from +0x%x\n", (unsigned)g_ctx, (unsigned)conn, g_conn, g_lo);
        g_gen++; g_nrep = 0; g_active = 1;
        if (!g_poller_started) { g_poller_started = 1; pthread_create(&g_poller, 0, poller, 0); }
    }
    return r;
}

typedef struct { void *replacement; void *replacee; } interpose_t;
__attribute__((used))
static const interpose_t interposers[] __attribute__((section("__DATA,__interpose"))) = {
    { (void *)my_IOServiceOpen, (void *)IOServiceOpen },
    { (void *)my_IOServiceClose, (void *)IOServiceClose },
};
