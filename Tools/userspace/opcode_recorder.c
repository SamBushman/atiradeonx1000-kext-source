/* opcode_recorder.c - issue #42 criterion 2: which command-stream opcodes do REAL clients emit?
 *
 * A DYLD_INSERT_LIBRARIES interposer (same mechanism as iokit_record.c) that tallies the opcodes in the command buffers a process hands to the stock (or rebuilt) ATIRadeonX1000 kext.
 *
 * How the kernel is told to process a buffer (static finding, 2026-10-02, Sources/IOATIR500{GL,DVD}Context_ClientMemoryForType.cpp, IOATIR5002DContext_ClientMemoryForType.cpp):
 * the client's IOConnectMapMemory() of the "flush" memory type IS the submit: the kext runs process_command_buffer over the client's current buffer, submits it, and returns a FRESH
 * command buffer through the mapping. Flush memory type per client type: GL (IOServiceOpen type 1) -> 1, 2D (type 2) -> 0, DVD (type 3) -> 1. So the buffer being submitted at
 * the Nth flush-map call is the one returned by the (N-1)th (the first call only returns the first buffer; the initial buffer is empty).
 *
 * Record format (read from the dispatchers, Sources/*_process_command_buffer_Port.cpp): the stream starts at buffer+0x1c; each record is one header word
 *   (opcode << 24) | n      n = length of the record in 32-bit words, header included
 * followed by its payload; the next record starts n words later; a record with n == 0 ends the stream. (Start offset and format are verified against real buffers, see OPCODE_DUMP.)
 *
 * The recorder is a passive observer: it forwards every call unchanged, reads the previous buffer with vm_read_overwrite on its own task (an invalid mapping returns an error instead
 * of faulting), and never calls into the kernel on its own. Build on the G5:  gcc -arch ppc -dynamiclib -o opcode_recorder.dylib opcode_recorder.c -framework IOKit -framework CoreFoundation
 * Use:   OPCODE_LOG=/path/log.tsv DYLD_INSERT_LIBRARIES=$PWD/opcode_recorder.dylib <program>
 *   env: OPCODE_START=0x1c (record stream offset)  OPCODE_DUMP=N (also hex-dump the first 0x80 bytes of the first N scanned buffers, to verify the offset/format)
 * Log (tab separated): FLUSH lines per scanned buffer, a CLOSE/EXIT summary with the sparse histogram "op:records:words" per connection, and ANOMALY lines (a record that overruns the
 * buffer, a buffer that never terminates): any anomaly means the format assumption is wrong for that buffer - do not trust the tallies without checking them.
 * Limitation: buffers the kernel processes by a path other than the flush-map (e.g. a swap or read selector that submits the pending buffer itself) are not counted.
 *
 * t_us field (added for issue #44's real-GL-application-frame-rate follow-up): each FLUSH line now also carries t_us=<microseconds since recorder init, mach_absolute_time-based>, a
 * purely additive field appended at the end of the existing tab-separated FLUSH format (nothing already parsing this format by field count/order from the front breaks). The interval
 * between consecutive FLUSH t_us values for the SAME connection is the real time between two command-buffer submissions for that context - for a GL connection whose client calls flush
 * once per rendered frame (the common case for a real app's main loop), that interval is a real per-frame time, i.e. real application frame rate, derived from an unmodified run of the
 * real app rather than a synthetic benchmark. Tools/frame_rate_from_log.py turns a captured log into per-connection frame-time statistics.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <pthread.h>
#include <mach/mach.h>
#include <mach/vm_map.h>
#include <mach/mach_time.h>
#include <IOKit/IOKitLib.h>

#define MAXCONN 64
typedef struct {
    int used; io_connect_t connect; unsigned type;           /* IOServiceOpen type: 0 surface, 1 GL, 2 2D, 3 DVD */
    unsigned flush_type; unsigned init_type; vm_address_t cur_addr; vm_size_t cur_size; int have_cur;
    unsigned long flushes, buffers_scanned, records, words, anomalies, empty_buffers, strays, tails;
    unsigned long hist_rec[256], hist_words[256];
} conn_t;
static conn_t g_conn[MAXCONN];
static unsigned long g_tot_rec[4][256], g_tot_words[4][256];       /* per client type 0..3 */
static unsigned long g_tot_flush[4], g_tot_anom[4];
static pthread_mutex_t g_mu = PTHREAD_MUTEX_INITIALIZER;
static FILE *g_log; static int g_pid; static unsigned g_start = 0x1c; static int g_dump = 0; static unsigned char *g_buf; static vm_size_t g_bufsz; static unsigned char *g_pre; static vm_size_t g_presz; static int g_post_pending; static vm_address_t g_post_addr; static vm_size_t g_post_size; static unsigned long g_post_off;
static const char *tname[4] = { "surface", "gl", "2d", "dvd" };
static double g_ticks_to_us; static double g_t0_us;
static double now_us_rel(void) { return (double)mach_absolute_time() * g_ticks_to_us - g_t0_us; }

static void ensure_log(void) {
    char b[256]; const char *p;
    if (g_log) return;
    { mach_timebase_info_data_t tb; mach_timebase_info(&tb); g_ticks_to_us = (double)tb.numer / tb.denom / 1000.0; g_t0_us = (double)mach_absolute_time() * g_ticks_to_us; }
    p = getenv("OPCODE_LOG"); g_pid = (int)getpid();
    if (!p) { snprintf(b, sizeof b, "/tmp/opcode_recorder.%d.tsv", g_pid); p = b; }
    g_log = fopen(p, "a"); if (!g_log) g_log = stderr;
    setvbuf(g_log, NULL, _IOLBF, 0);
    if (getenv("OPCODE_START")) g_start = (unsigned)strtoul(getenv("OPCODE_START"), NULL, 0);
    if (getenv("OPCODE_DUMP")) g_dump = atoi(getenv("OPCODE_DUMP"));
    fprintf(g_log, "# opcode_recorder start pid=%d start_offset=0x%x dump=%d\n", g_pid, g_start, g_dump);
}
static void *g_iokit;
static void *resolve_real(const char *name) {
    void *p = dlsym(RTLD_NEXT, name);
    if (p) return p;
    if (!g_iokit) g_iokit = dlopen("/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit", RTLD_NOW | RTLD_GLOBAL);
    if (g_iokit) p = dlsym(g_iokit, name);
    if (!p) { fprintf(stderr, "opcode_recorder: FATAL cannot resolve %s\n", name); abort(); }
    return p;
}
static kern_return_t (*real_open)(io_service_t, task_port_t, uint32_t, io_connect_t *);
static kern_return_t (*real_close)(io_connect_t);
static kern_return_t (*real_map)(io_connect_t, uint32_t, task_port_t, vm_address_t *, vm_size_t *, IOOptionBits);

static void emit_totals(void);
static conn_t *find(io_connect_t c) { int i; for (i = 0; i < MAXCONN; i++) if (g_conn[i].used && g_conn[i].connect == c) return &g_conn[i]; return NULL; }

/* tally one submitted buffer; returns nothing, logs one FLUSH line */
static void scan(conn_t *c, vm_address_t addr, vm_size_t size) {
    vm_size_t got = 0; kern_return_t kr; unsigned char *p, *end; unsigned long nrec = 0, nwords = 0; int term = 0, anom = 0; unsigned t = c->type & 3;
    if (size > g_bufsz) { free(g_buf); g_bufsz = size; g_buf = malloc(g_bufsz); }
    kr = vm_read_overwrite(mach_task_self(), addr, size, (vm_address_t)g_buf, &got);
    if (kr != KERN_SUCCESS || got < g_start + 4) {
        fprintf(g_log, "ANOMALY\tconn=0x%x\ttype=%s\taddr=0x%lx\tsize=0x%lx\tvm_read_overwrite kr=%d got=%lu\n", (unsigned)c->connect, tname[t], (unsigned long)addr, (unsigned long)size, kr, (unsigned long)got);
        c->anomalies++; g_tot_anom[t]++; return;
    }
    if (g_dump > 0) {
        int i; g_dump--;
        fprintf(g_log, "DUMP\tconn=0x%x\ttype=%s\taddr=0x%lx\tsize=0x%lx\t", (unsigned)c->connect, tname[t], (unsigned long)addr, (unsigned long)size);
        for (i = 0; i < 0x80 && (vm_size_t)i < got; i++) fprintf(g_log, "%02x%s", g_buf[i], (i & 3) == 3 ? " " : "");
        fprintf(g_log, "\n");
    }
    p = g_buf + g_start; end = g_buf + got;
    { unsigned lo[16], ln[16], lf[16]; int nl = 0, k;                  /* trace of the last 16 records, printed with any anomaly */
    while (p + 4 <= end) {
        unsigned w = *(unsigned *)p, n = w & 0xffffff, op = w >> 24;
        if (n == 0) {
            /* the driver back-patches each record's length when the NEXT record is appended (*prev |= (next - prev) >> 2), so the LAST record of a buffer keeps length 0: a non-zero header word
             * with length 0 is that final record (count its opcode, length unknown); an all-zero word is the plain terminator */
            if (w != 0) { c->hist_rec[op]++; c->hist_words[op] += 1; g_tot_rec[t][op]++; g_tot_words[t][op] += 1; nrec++; nwords++; c->tails++; fprintf(g_log, "TAIL\tconn=0x%x\ttype=%s\tfinal record op=0x%02x header=0x%08x at +0x%lx\n", (unsigned)c->connect, tname[t], op, w, (unsigned long)(p - g_buf)); }
            term = 1; break;
        }
        if (p + (unsigned long)n * 4 > end && p + 8 <= end && *(unsigned *)(p + 4) == 0) {
            /* one stray word between the end of the previous record and a zero terminator (seen once, after a 2825-word 0x25 record from a 900-vertex glBegin/glEnd; the kernel's in-place rewrite stops at
               that record, see the POST lines): logged as STRAY, not as an anomaly, because the stream is otherwise consistent and terminates one word later */
            fprintf(g_log, "STRAY\tconn=0x%x\ttype=%s\tone stray word 0x%08x at +0x%lx before the terminator\n", (unsigned)c->connect, tname[t], w, (unsigned long)(p - g_buf));
            c->strays++; term = 1; break;
        }
        if (p + (unsigned long)n * 4 > end) {
            anom = 1; fprintf(g_log, "ANOMALY\tconn=0x%x\ttype=%s\trecord at +0x%lx op=0x%02x n=%u overruns the buffer (size 0x%lx)\n", (unsigned)c->connect, tname[t], (unsigned long)(p - g_buf), op, n, (unsigned long)got);
            for (k = (nl > 16 ? 16 : nl); k > 0; k--) { int j = (nl - k) & 15; fprintf(g_log, "  prev\t+0x%x\top=0x%02x\tn=%u\n", lf[j], lo[j], ln[j]); }
            { unsigned long a0 = (unsigned long)(p - g_buf); int i; a0 = a0 > 0x20 ? a0 - 0x20 : 0; fprintf(g_log, "  bytes from +0x%lx:", a0); for (i = 0; i < 0x60 && a0 + i < got; i++) fprintf(g_log, "%s%02x", (i & 3) == 0 ? " " : "", g_buf[a0 + i]); fprintf(g_log, "\n"); }
            if (!g_post_pending) { if (got > g_presz) { free(g_pre); g_presz = got; g_pre = malloc(g_presz); } memcpy(g_pre, g_buf, got); g_post_pending = 1; g_post_addr = addr; g_post_size = got; g_post_off = (unsigned long)(p - g_buf); }
            break;
        }
        lo[nl & 15] = op; ln[nl & 15] = n; lf[nl & 15] = (unsigned)(p - g_buf); nl++;
        c->hist_rec[op]++; c->hist_words[op] += n; g_tot_rec[t][op]++; g_tot_words[t][op] += n; nrec++; nwords += n;
        p += (unsigned long)n * 4;
    } }
    if (!term && !anom) { anom = 1; fprintf(g_log, "ANOMALY\tconn=0x%x\ttype=%s\tbuffer never terminates (no record with n == 0) after %lu records\n", (unsigned)c->connect, tname[t], nrec); }
    if (anom) { c->anomalies++; g_tot_anom[t]++; }
    if (nrec == 0 && term) c->empty_buffers++;
    c->buffers_scanned++; c->records += nrec; c->words += nwords;
    fprintf(g_log, "FLUSH\tconn=0x%x\ttype=%s\tn=%lu\taddr=0x%lx\tsize=0x%lx\trecords=%lu\twords=%lu\tterminated=%d\tt_us=%.2f\n", (unsigned)c->connect, tname[t], c->flushes, (unsigned long)addr, (unsigned long)size, nrec, nwords, term, now_us_rel());
}
static void summary(const char *what, conn_t *c) {
    int i; fprintf(g_log, "%s\tconn=0x%x\ttype=%s\tflushes=%lu\tbuffers=%lu\tempty=%lu\trecords=%lu\twords=%lu\tanomalies=%lu\tstrays=%lu\ttails=%lu\tHIST", what, (unsigned)c->connect, tname[c->type & 3], c->flushes, c->buffers_scanned, c->empty_buffers, c->records, c->words, c->anomalies, c->strays, c->tails);
    for (i = 0; i < 256; i++) if (c->hist_rec[i]) fprintf(g_log, " %02x:%lu:%lu", i, c->hist_rec[i], c->hist_words[i]);
    fprintf(g_log, "\n");
}

/* PRIMING (added 2026-10-07, see kext-source#152): several 2D process_command_buffer opcodes (0x03/0x04/0x07/0x08/0x10/0x13) unconditionally dereference the context's self+0x88 pointer as part of
 * their own bounds check, before the id they're given is even looked at - traced (Sources/IOATIR5002DContext_declare_image_Port.cpp) to a pointer that stays NULL until declare_image (external method
 * selector 8) is called at least once on that connection. A connection fresh off WindowServer's own restart has never called it (ordinary desktop compositing never does - confirmed by this project's
 * own observation capture), so injecting any of those six opcodes into an unprimed connection panics the kernel - confirmed live twice, real precondition, not a timing fluke. OPCODE_PRIME_IMAGE=1 calls
 * declare_image for real (IOConnectMethodScalarIScalarO, the exact real calling convention from Tests/destructive/t3_2d_declare_image.c: selector 8, 3 scalar in/1 scalar out, p2=0 lets the kernel
 * allocate) on a newly-opened 2D connection before any injection can run against it, so self+0x88 is genuinely populated the real way before these opcodes are ever exercised. */
static int g_prime_image = -1;
static void prime_declare_image(io_connect_t c) {
    unsigned h = 0; kern_return_t r;
    unsigned char *buf = (unsigned char *)valloc(0x10000);   /* real page-aligned buffer - declare_image forbids param_2==0 ("let the kernel allocate"), needs a genuine user address, per
                                                                  Tests/destructive/t3_2d_declare_image.c's own already-proven-safe call shape */
    if (!buf) { fprintf(g_log, "PRIME\tconn=0x%x\tskipped: valloc failed\n", (unsigned)c); return; }
    memset(buf, 0xAA, 0x10000);
    r = IOConnectMethodScalarIScalarO(c, 8, 3, 1, 0, (int)buf, 0x1000, &h);
    fprintf(g_log, "PRIME\tconn=0x%x\tdeclare_image(sel8,0,buf,0x1000) -> r=0x%08x id=0x%x\n", (unsigned)c, (unsigned)r, h);
    fflush(g_log);
    /* buf deliberately leaked, same as the T3 test: "the buffer is freed only after the connection is closed" - it's wrapped live in an IOMemoryDescriptor */
}
static kern_return_t my_open(io_service_t s, task_port_t task, uint32_t type, io_connect_t *conn) {
    kern_return_t r; ensure_log(); if (!real_open) real_open = resolve_real("IOServiceOpen");
    if (g_prime_image < 0) g_prime_image = getenv("OPCODE_PRIME_IMAGE") ? atoi(getenv("OPCODE_PRIME_IMAGE")) : 0;
    r = real_open(s, task, type, conn);
    if (r == KERN_SUCCESS && conn) fprintf(g_log, "OPEN\ttype=%u\tconnect=0x%x\n", type, (unsigned)*conn);
    if (r == KERN_SUCCESS && conn && type == 2 && g_prime_image) prime_declare_image(*conn);
    if (r == KERN_SUCCESS && conn && type <= 3) {
        int i; pthread_mutex_lock(&g_mu);
        for (i = 0; i < MAXCONN; i++) if (!g_conn[i].used) {
            memset(&g_conn[i], 0, sizeof g_conn[i]); g_conn[i].used = 1; g_conn[i].connect = *conn; g_conn[i].type = type;
            g_conn[i].flush_type = (type == 1) ? 1 : (type == 2) ? 0 : (type == 3) ? 1 : 0xffffffff;   /* surface connections carry no command buffer */
            g_conn[i].init_type = (type == 2) ? 1 : (type == 3) ? 2 : 0xffffffff;                          /* 2D: the first buffer comes from memory type 1, DVD: type 2 (GL: the first flush-type map returns it) */
            break;
        }
        pthread_mutex_unlock(&g_mu);
    }
    return r;
}
static kern_return_t my_close(io_connect_t c) {
    conn_t *k; ensure_log(); if (!real_close) real_close = resolve_real("IOServiceClose");
    pthread_mutex_lock(&g_mu); k = find(c); if (k) { if (k->type) summary("CLOSE", k); k->used = 0; } pthread_mutex_unlock(&g_mu);
    return real_close(c);
}

/* INJECTION (issue #42, opcodes no real consumer emits): OPCODE_INJECT_WORDS="0x2b000001,..." are spliced in at the START of the stream (+g_start) of the Nth flush (OPCODE_INJECT_FLUSH, default 3) of
 * the Nth connection whose IOServiceOpen type matches OPCODE_INJECT_TYPE (default 1 = GL, unchanged; 2 = 2D, 3 = DVD), the existing stream shifted up by the same number of words, so the real driver's
 * context/surface/register state around it stays valid. CRITICAL (2026-10-03 postmortem, Tests/pm4_opcode_gaps.md): this only works safely because it splices into the REAL buffer a REAL client's own
 * flush-map call already returned (k->cur_addr/cur_size) - never attempt an equivalent injection through a hand-built/synthetic client or buffer address; that hung the G5 once (the guard never ran
 * because the wrong buffer was targeted). Done once per process. The tail is moved up to 256 words past the first n==0 header; if that does not fit in the buffer the injection is skipped and logged.
 *
 * OPCODE_INJECT_SCHEDULE (2026-10-07, added for #42's remaining "terminator-family" 2D opcodes - each one that takes an invalid-id safe-exit path ends that flush's whole buffer early, so two of them
 * can never share one flush): "flush:word[,word...];flush:word[,word...];..." schedules MULTIPLE independent single-shot injections across different flush numbers of the SAME matched connection,
 * instead of the single OPCODE_INJECT_WORDS/FLUSH shot above (both can be set; SCHEDULE entries are checked in addition to the single shot). Each entry fires once, independently, the first time its
 * own flush count is reached - letting several otherwise-mutually-exclusive (stream-terminating) opcodes each get their own flush in one process lifetime, avoiding a separate kill+relaunch per opcode. */
static unsigned g_inj_words[64]; static int g_inj_n = -1, g_inj_done; static unsigned char *g_inj_base; static unsigned long g_inj_flush = 3; static unsigned g_inj_type = 1;
#define MAXSCHED 16
static struct { unsigned long flush; unsigned words[16]; int n; int done; } g_sched[MAXSCHED];
static int g_sched_n = 0;
static void inject_init(void) {
    const char *e = getenv("OPCODE_INJECT_WORDS"); char *q; const char *se;
    if (g_inj_n >= 0) return; g_inj_n = 0;
    if (getenv("OPCODE_INJECT_FLUSH")) g_inj_flush = strtoul(getenv("OPCODE_INJECT_FLUSH"), NULL, 0);
    if (getenv("OPCODE_INJECT_TYPE")) g_inj_type = (unsigned)strtoul(getenv("OPCODE_INJECT_TYPE"), NULL, 0);   /* IOServiceOpen type to target: 1 GL (default, unchanged), 2 2D, 3 DVD */
    if (e) while (*e && g_inj_n < 64) { g_inj_words[g_inj_n++] = (unsigned)strtoul(e, &q, 0); if (q == e) { g_inj_n--; break; } e = q; while (*e == ',' || *e == ' ') e++; }
    se = getenv("OPCODE_INJECT_SCHEDULE");
    if (se) while (*se && g_sched_n < MAXSCHED) {
        g_sched[g_sched_n].flush = strtoul(se, &q, 0); if (q == se) break; se = q; if (*se == ':') se++;
        g_sched[g_sched_n].n = 0;
        while (*se && *se != ';' && g_sched[g_sched_n].n < 16) { g_sched[g_sched_n].words[g_sched[g_sched_n].n++] = (unsigned)strtoul(se, &q, 0); if (q == se) break; se = q; while (*se == ',' || *se == ' ') se++; }
        g_sched_n++; while (*se == ';' || *se == ' ') se++;
    }
}
static unsigned g_last_words[16]; static int g_last_n;
static void inject_words_at(conn_t *c, unsigned *words, int n) {
    unsigned char *base = (unsigned char *)c->cur_addr; unsigned long off = g_start, end, k = (unsigned long)n * 4; unsigned long size = c->cur_size, i;
    for (;;) { unsigned w; if (off + 4 > size) { fprintf(g_log, "INJECT\tskipped: no terminator\n"); return; } w = *(unsigned *)(base + off); if ((w & 0xffffff) == 0) break; off += (unsigned long)(w & 0xffffff) * 4; }
    end = off + 4 + 256 * 4; if (end > size) end = size;
    if (end + k > size) { fprintf(g_log, "INJECT\tskipped: buffer too full (end=+0x%lx k=0x%lx size=0x%lx)\n", end, k, size); return; }
    memmove(base + g_start + k, base + g_start, end - g_start);
    for (i = 0; i < (unsigned long)n; i++) *(unsigned *)(base + g_start + i * 4) = words[i];
    fprintf(g_log, "INJECT\tconn=0x%x\tflush=%lu\twords=%d first=0x%08x tail_header_was_at=+0x%lx\n", (unsigned)c->connect, c->flushes, n, words[0], off);
    fflush(g_log); g_inj_base = base;
    for (i = 0; i < (unsigned long)n && i < 16; i++) g_last_words[i] = words[i]; g_last_n = n < 16 ? n : 16;
}
static void inject_into(conn_t *c) { inject_words_at(c, g_inj_words, g_inj_n); g_inj_done = 1; }
static void inject_scheduled(conn_t *c) {
    int i; for (i = 0; i < g_sched_n; i++) if (!g_sched[i].done && c->flushes == g_sched[i].flush) { inject_words_at(c, g_sched[i].words, g_sched[i].n); g_sched[i].done = 1; return; }
}
static kern_return_t my_map(io_connect_t c, uint32_t mt, task_port_t task, vm_address_t *at, vm_size_t *sz, IOOptionBits opt) {
    conn_t *k; kern_return_t r; ensure_log(); if (!real_map) real_map = resolve_real("IOConnectMapMemory");
    pthread_mutex_lock(&g_mu); k = find(c);
    if (k && k->type && mt == k->flush_type) {
        k->flushes++; g_tot_flush[k->type & 3]++;
        inject_init();
        if (k->have_cur && (k->type & 3) == g_inj_type) {
            if (!g_inj_done && g_inj_n > 0 && k->flushes == g_inj_flush) inject_into(k);
            else if (g_sched_n > 0) inject_scheduled(k);
        }
        if (k->have_cur) scan(k, k->cur_addr, k->cur_size);          /* the buffer being submitted: the one the previous flush-map returned */
        if ((g_tot_flush[k->type & 3] & 15) == 0) emit_totals();      /* snapshot every 16 flushes */
    }
    pthread_mutex_unlock(&g_mu);
    r = real_map(c, mt, task, at, sz, opt);                           /* forwarded unchanged */
    if (g_inj_base) { int i; fprintf(g_log, "INJECT-POST\tflush returned %d; first words after the kernel processed the buffer:", (int)r); for (i = 0; i < g_last_n && i < 8; i++) fprintf(g_log, " %08x->%08x", g_last_words[i], *(unsigned *)(g_inj_base + g_start + i * 4)); fprintf(g_log, "\n"); fflush(g_log); g_inj_base = NULL; }
    if (g_post_pending) {                                              /* the kernel has processed (and rewritten in place) the buffer that gave an anomaly: show where */
        vm_size_t got2 = 0; unsigned long i, first = (unsigned long)-1, last = 0, nchg = 0; unsigned long lo = g_post_off > 0x40 ? g_post_off - 0x40 : 0;
        if (g_post_size > g_bufsz) { free(g_buf); g_bufsz = g_post_size; g_buf = malloc(g_bufsz); }
        if (vm_read_overwrite(mach_task_self(), g_post_addr, g_post_size, (vm_address_t)g_buf, &got2) == KERN_SUCCESS) {
            for (i = 0; i + 4 <= got2 && i + 4 <= g_post_size; i += 4) if (*(unsigned *)(g_buf + i) != *(unsigned *)(g_pre + i)) { nchg++; if (first == (unsigned long)-1) first = i; last = i; }
            fprintf(g_log, "POST\taddr=0x%lx\twords_changed_by_kernel=%lu\tfirst=+0x%lx\tlast=+0x%lx\tanomaly_at=+0x%lx\n", (unsigned long)g_post_addr, nchg, first, last, g_post_off);
            fprintf(g_log, "  pre  from +0x%lx:", lo); for (i = 0; i < 0x80 && lo + i < got2; i += 4) fprintf(g_log, " %08x", *(unsigned *)(g_pre + lo + i)); fprintf(g_log, "\n");
            fprintf(g_log, "  post from +0x%lx:", lo); for (i = 0; i < 0x80 && lo + i < got2; i += 4) fprintf(g_log, " %08x", *(unsigned *)(g_buf + lo + i)); fprintf(g_log, "\n");
        } else fprintf(g_log, "POST\tcould not re-read the buffer after the flush\n");
        g_post_pending = 0;
    }
    pthread_mutex_lock(&g_mu); k = find(c);
    if (k && k->type && r == KERN_SUCCESS && at && sz && (mt == k->flush_type || (mt == k->init_type && !k->have_cur))) { k->cur_addr = *at; k->cur_size = *sz; k->have_cur = 1; }
    pthread_mutex_unlock(&g_mu);
    return r;
}

/* TOTAL lines carry the pid; a later TOTAL of the same (pid, type) supersedes an earlier one, so periodic snapshots mean a run that is killed (no destructor) still leaves its tally */
static void emit_totals(void) {
    int i, t;
    for (t = 1; t <= 3; t++) if (g_tot_flush[t]) {
        fprintf(g_log, "TOTAL\tpid=%d\ttype=%s\tflushes=%lu\tanomalies=%lu\tHIST", g_pid, tname[t], g_tot_flush[t], g_tot_anom[t]);
        for (i = 0; i < 256; i++) if (g_tot_rec[t][i]) fprintf(g_log, " %02x:%lu:%lu", i, g_tot_rec[t][i], g_tot_words[t][i]);
        fprintf(g_log, "\n");
    }
}
__attribute__((destructor)) static void at_exit(void) {
    int i;
    if (!g_log) return;
    pthread_mutex_lock(&g_mu);
    for (i = 0; i < MAXCONN; i++) if (g_conn[i].used && g_conn[i].type && g_conn[i].flushes) summary("EXIT", &g_conn[i]);
    emit_totals();
    pthread_mutex_unlock(&g_mu);
}

typedef struct { void *replacement; void *replacee; } interpose_t;
__attribute__((used)) static const interpose_t interposers[] __attribute__((section("__DATA,__interpose"))) = {
    { (void *)my_open,  (void *)IOServiceOpen },
    { (void *)my_close, (void *)IOServiceClose },
    { (void *)my_map,   (void *)IOConnectMapMemory },
};
