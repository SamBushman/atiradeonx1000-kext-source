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
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <pthread.h>
#include <mach/mach.h>
#include <mach/vm_map.h>
#include <IOKit/IOKitLib.h>

#define MAXCONN 64
typedef struct {
    int used; io_connect_t connect; unsigned type;           /* IOServiceOpen type: 0 surface, 1 GL, 2 2D, 3 DVD */
    unsigned flush_type; vm_address_t cur_addr; vm_size_t cur_size; int have_cur;
    unsigned long flushes, buffers_scanned, records, words, anomalies, empty_buffers;
    unsigned long hist_rec[256], hist_words[256];
} conn_t;
static conn_t g_conn[MAXCONN];
static unsigned long g_tot_rec[4][256], g_tot_words[4][256];       /* per client type 0..3 */
static unsigned long g_tot_flush[4], g_tot_anom[4];
static pthread_mutex_t g_mu = PTHREAD_MUTEX_INITIALIZER;
static FILE *g_log; static int g_pid; static unsigned g_start = 0x1c; static int g_dump = 0; static unsigned char *g_buf; static vm_size_t g_bufsz;
static const char *tname[4] = { "surface", "gl", "2d", "dvd" };

static void ensure_log(void) {
    char b[256]; const char *p;
    if (g_log) return;
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
    while (p + 4 <= end) {
        unsigned w = *(unsigned *)p, n = w & 0xffffff, op = w >> 24;
        if (n == 0) { term = 1; break; }
        if (p + (unsigned long)n * 4 > end) { anom = 1; fprintf(g_log, "ANOMALY\tconn=0x%x\ttype=%s\trecord at +0x%lx op=0x%02x n=%u overruns the buffer (size 0x%lx)\n", (unsigned)c->connect, tname[t], (unsigned long)(p - g_buf), op, n, (unsigned long)got); break; }
        c->hist_rec[op]++; c->hist_words[op] += n; g_tot_rec[t][op]++; g_tot_words[t][op] += n; nrec++; nwords += n;
        p += (unsigned long)n * 4;
    }
    if (!term && !anom) { anom = 1; fprintf(g_log, "ANOMALY\tconn=0x%x\ttype=%s\tbuffer never terminates (no record with n == 0) after %lu records\n", (unsigned)c->connect, tname[t], nrec); }
    if (anom) { c->anomalies++; g_tot_anom[t]++; }
    if (nrec == 0 && term) c->empty_buffers++;
    c->buffers_scanned++; c->records += nrec; c->words += nwords;
    fprintf(g_log, "FLUSH\tconn=0x%x\ttype=%s\tn=%lu\taddr=0x%lx\tsize=0x%lx\trecords=%lu\twords=%lu\tterminated=%d\n", (unsigned)c->connect, tname[t], c->flushes, (unsigned long)addr, (unsigned long)size, nrec, nwords, term);
}
static void summary(const char *what, conn_t *c) {
    int i; fprintf(g_log, "%s\tconn=0x%x\ttype=%s\tflushes=%lu\tbuffers=%lu\tempty=%lu\trecords=%lu\twords=%lu\tanomalies=%lu\tHIST", what, (unsigned)c->connect, tname[c->type & 3], c->flushes, c->buffers_scanned, c->empty_buffers, c->records, c->words, c->anomalies);
    for (i = 0; i < 256; i++) if (c->hist_rec[i]) fprintf(g_log, " %02x:%lu:%lu", i, c->hist_rec[i], c->hist_words[i]);
    fprintf(g_log, "\n");
}

static kern_return_t my_open(io_service_t s, task_port_t task, uint32_t type, io_connect_t *conn) {
    kern_return_t r; ensure_log(); if (!real_open) real_open = resolve_real("IOServiceOpen");
    r = real_open(s, task, type, conn);
    if (r == KERN_SUCCESS && conn && type <= 3) {
        int i; pthread_mutex_lock(&g_mu);
        for (i = 0; i < MAXCONN; i++) if (!g_conn[i].used) {
            memset(&g_conn[i], 0, sizeof g_conn[i]); g_conn[i].used = 1; g_conn[i].connect = *conn; g_conn[i].type = type;
            g_conn[i].flush_type = (type == 1) ? 1 : (type == 2) ? 0 : (type == 3) ? 1 : 0xffffffff;   /* surface connections carry no command buffer */
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
static kern_return_t my_map(io_connect_t c, uint32_t mt, task_port_t task, vm_address_t *at, vm_size_t *sz, IOOptionBits opt) {
    conn_t *k; kern_return_t r; ensure_log(); if (!real_map) real_map = resolve_real("IOConnectMapMemory");
    pthread_mutex_lock(&g_mu); k = find(c);
    if (k && k->type && mt == k->flush_type) {
        k->flushes++; g_tot_flush[k->type & 3]++;
        if (k->have_cur) scan(k, k->cur_addr, k->cur_size);          /* the buffer being submitted: the one the previous flush-map returned */
        if ((g_tot_flush[k->type & 3] & 15) == 0) emit_totals();      /* snapshot every 16 flushes */
    }
    pthread_mutex_unlock(&g_mu);
    r = real_map(c, mt, task, at, sz, opt);                           /* forwarded unchanged */
    pthread_mutex_lock(&g_mu); k = find(c);
    if (k && k->type && mt == k->flush_type && r == KERN_SUCCESS && at && sz) { k->cur_addr = *at; k->cur_size = *sz; k->have_cur = 1; }
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
