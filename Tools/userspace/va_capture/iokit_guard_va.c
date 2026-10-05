/* iokit_guard_va.c - issue #140 rung 2: a DEFAULT-DENY IOKit interposer for driving the real ATIRadeonX1000VADriver without letting the kernel see anything unproven.
 * (iokit_record_va.c is a passive recorder that forwards every call; this one forwards ONLY an explicit allowlist and answers everything else itself.)
 *
 * Policy, for connections opened with IOServiceOpen type 3 (the DVD user client); every other connection (WindowServer-side, GL, ...) is forwarded untouched:
 *   IOServiceOpen / IOServiceClose / IOConnectAddClient      forward (logged)
 *   IOConnectMapMemory   the FIRST map of each type in {1,2,4,5} per connection: forward.  Any later map (that is how the driver submits command buffers and ping-pongs the
 *                        IDCT stream buffers) and any other type: SWALLOW - return success with the mapping we already hold, log it and snapshot the mapped bytes to the .mem file.
 *   scalar/struct selectors on a DVD connection:
 *     forward  : 1 get_config, 2 get_status, 0 set_surface, 21 setup_buffers   (proven live on the stock kext; GUARD_FORWARD env adds more, comma separated)
 *     doIDCT 18: SWALLOW (unless GUARD_FORWARD includes 18: then write-ahead-logged and FORWARDED - rung 3 only): return 0, zero the output, log the 0x38-byte parameter block and snapshot the type 4/5 buffers (first GUARD_DUMP_BYTES bytes) to the .mem file
 *     19 wait_for_stamps / 20 check_stamps: SWALLOW with synthetic "done" (a forwarded wait could block forever: nothing is ever submitted)
 *     8 declare_image: SWALLOW with a private calloc'd block as the returned handle (the driver dereferences it; a zero crashed the first run)
 *     everything else (write_regs, set_macrovision, overlay, deint, lock/declare/delete, write_buffer, ...): SWALLOW, return 0, outputs zeroed, logged
 * Each logged line says FWD or SWALLOW.  Exported counters (guard_stats) let the harness refuse to continue if it cannot confirm the shim saw the DVD open.
 *
 * Build: gcc -dynamiclib -o iokit_guard_va.dylib iokit_guard_va.c -framework IOKit -framework CoreFoundation
 * Use:   GUARD_LOG=/path/log.tsv DYLD_INSERT_LIBRARIES=/path/iokit_guard_va.dylib <program>        (GUARD_SELFTEST=1: log only, nothing special) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <mach/mach_types.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/iokitmig_c.h>

static FILE *g_log = NULL, *g_mem = NULL;
static long g_seq = 0; static struct timeval g_t0; static int g_pid = 0;
#define MAXC 32
#define MAXM 128
static struct { io_connect_t c; int type; } g_conn[MAXC]; static int g_nconn = 0;
static struct { io_connect_t c; unsigned type; unsigned long addr, size; } g_maps[MAXM]; static int g_nmaps = 0;
static int g_fwd_extra[64]; static int g_nfwd_extra = 0;
static struct { long fwd, swallow, dvd_opens, dvd_sel18, dvd_remaps; } g_stats;

static struct { unsigned addr, size; } g_img[64]; static int g_nimg = 0;   /* declare_image(8) buffers actually handed to the kernel (user-memory frames the GPU may write: #141) */
static unsigned g_last_stamp = 0;   /* timestamp of the last FORWARDED type-1 submit (word +0x18 of the new command-buffer mapping = DVD context's this+0x7c, init_command_buffer_header) */
/* exported for the harness */
int guard_dump_images(const char *prefix) {
    int i, n = 0; char fn[400]; FILE *fp;
    for (i = 0; i < g_nimg; i++) { snprintf(fn, sizeof fn, "%s_img%02d_%08x.bin", prefix, i, g_img[i].addr); fp = fopen(fn, "wb"); if (!fp) continue; fwrite((void *)(unsigned long)g_img[i].addr, 1, g_img[i].size, fp); fclose(fp); n++; }
    return n;
}
int guard_nimages(void) { return g_nimg; }
int guard_dvd_connect(void) { int i; for (i = 0; i < g_nconn; i++) if (g_conn[i].type == 3) return (int)g_conn[i].c; return 0; }
long guard_stat(int which) { switch (which) { case 0: return g_stats.fwd; case 1: return g_stats.swallow; case 2: return g_stats.dvd_opens; case 3: return g_stats.dvd_sel18; case 4: return g_stats.dvd_remaps; } return -1; }

/* Durable + mirrored log (#141): a kernel panic loses everything the drive had not written. fsync() on Mac OS X does NOT flush the drive cache; fcntl(F_FULLFSYNC) does. In addition GUARD_MIRROR=ip:port sends every
 * log line as a UDP datagram (g_log is a funopen() stream whose write hook writes the file AND the datagram), so the last line before a panic is on the dev machine even if the disk lost it. */
static int g_fd = -1, g_sock = -1; static struct sockaddr_in g_mir;
static void fullsync(int fd) { if (fd < 0) return; if (fcntl(fd, F_FULLFSYNC, 0) != 0) fsync(fd); }
static int g_wr(void *ck, const char *b, int n) { if (g_fd >= 0) { if (write(g_fd, b, n) < 0) {} } if (g_sock >= 0) sendto(g_sock, b, n, 0, (struct sockaddr *)&g_mir, sizeof g_mir); return n; }
static void open_log(const char *path) {
    const char *m = getenv("GUARD_MIRROR");
    g_fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (m && strchr(m, ':')) { char ip[64]; int port = atoi(strchr(m, ':') + 1); size_t l = (size_t)(strchr(m, ':') - m); if (l < sizeof ip) { memcpy(ip, m, l); ip[l] = 0; memset(&g_mir, 0, sizeof g_mir); g_mir.sin_family = AF_INET; g_mir.sin_port = htons((unsigned short)port); if (inet_pton(AF_INET, ip, &g_mir.sin_addr) == 1) g_sock = socket(AF_INET, SOCK_DGRAM, 0); } }
    g_log = (g_fd >= 0) ? funopen(NULL, NULL, g_wr, NULL, NULL) : NULL;
}
static void ensure(void) {
    if (g_log) return;
    const char *p = getenv("GUARD_LOG"); char b[256];
    if (!p) { snprintf(b, sizeof b, "/tmp/iokit_guard.%d.tsv", (int)getpid()); p = b; }
    open_log(p); if (!g_log) g_log = fopen(p, "a"); if (!g_log) g_log = stderr;
    setvbuf(g_log, NULL, _IOLBF, 0); gettimeofday(&g_t0, NULL); g_pid = (int)getpid();
    fprintf(g_log, "# iokit_guard start pid=%d\n", g_pid);
    const char *e = getenv("GUARD_FORWARD");
    if (e) { char *s = strdup(e), *t; for (t = strtok(s, ","); t && g_nfwd_extra < 64; t = strtok(NULL, ",")) g_fwd_extra[g_nfwd_extra++] = atoi(t); }
}
static long us(void) { struct timeval n; gettimeofday(&n, NULL); return (n.tv_sec - g_t0.tv_sec) * 1000000L + (n.tv_usec - g_t0.tv_usec); }
static void hexs(FILE *f, const void *d, unsigned n) { unsigned i; if (n > 4096) n = 4096; if (!d) { fprintf(f, "NULL"); return; } for (i = 0; i < n; i++) fprintf(f, "%02x", ((const unsigned char *)d)[i]); }

static void *g_ik = NULL;
static void *real(const char *name) {
    void *p = dlsym(RTLD_NEXT, name);
    if (p) return p;
    if (!g_ik) { g_ik = dlopen("/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit", RTLD_NOW | RTLD_GLOBAL); if (!g_ik) g_ik = dlopen("/System/Library/Frameworks/IOKit.framework/IOKit", RTLD_NOW | RTLD_GLOBAL); }
    if (g_ik) p = dlsym(g_ik, name);
    if (!p) { fprintf(stderr, "iokit_guard: FATAL cannot resolve %s: %s\n", name, dlerror()); abort(); }
    return p;
}
static kern_return_t (*r_open)(io_service_t, task_port_t, uint32_t, io_connect_t *);
static kern_return_t (*r_close)(io_connect_t);
static kern_return_t (*r_addc)(io_connect_t, io_connect_t);
static kern_return_t (*r_map)(io_connect_t, uint32_t, task_port_t, vm_address_t *, vm_size_t *, IOOptionBits);
static kern_return_t (*r_sisO)(mach_port_t, int, int *, mach_msg_type_number_t, int *, mach_msg_type_number_t *);
static kern_return_t (*r_sisto)(mach_port_t, int, int *, mach_msg_type_number_t, char *, mach_msg_type_number_t *);
static kern_return_t (*r_sisti)(mach_port_t, int, int *, mach_msg_type_number_t, char *, mach_msg_type_number_t);
static kern_return_t (*r_stto)(mach_port_t, int, char *, mach_msg_type_number_t, char *, mach_msg_type_number_t *);
#define RES(v, n) if (!v) v = (void *)real(n)

static int conn_type(io_connect_t c) { int i; for (i = 0; i < g_nconn; i++) if (g_conn[i].c == c) return g_conn[i].type; return -1; }
static int is_dvd(io_connect_t c) { return conn_type(c) == 3; }
static int extra_fwd(int sel) { int i; for (i = 0; i < g_nfwd_extra; i++) if (g_fwd_extra[i] == sel) return 1; return 0; }
static int fwd_selector(int sel) { return sel == 0 || sel == 1 || sel == 2 || sel == 21 || extra_fwd(sel); }

static void snapshot(io_connect_t c, const char *why, unsigned seq) {
    const char *bs = getenv("GUARD_DUMP_BYTES"); unsigned long nbytes = bs ? strtoul(bs, NULL, 0) : 4096, n, k; int i;
    if (!g_mem) { char p[300]; const char *lp = getenv("GUARD_LOG"); snprintf(p, sizeof p, "%s.mem", lp ? lp : "/tmp/iokit_guard"); g_mem = fopen(p, "a"); if (!g_mem) return; setvbuf(g_mem, NULL, _IOLBF, 0); }
    fprintf(g_mem, "SNAP seq=%u why=%s connect=0x%x\n", seq, why, (unsigned)c);
    for (i = 0; i < g_nmaps; i++) {
        if (g_maps[i].c != c) continue;
        n = g_maps[i].size < nbytes ? g_maps[i].size : nbytes;
        fprintf(g_mem, "MAP type=%u addr=0x%lx size=0x%lx dumped=%lu ", g_maps[i].type, g_maps[i].addr, g_maps[i].size, n);
        for (k = 0; k < n; k++) fprintf(g_mem, "%02x", ((unsigned char *)g_maps[i].addr)[k]);
        fprintf(g_mem, "\n");
    }
}
static int fsync_all(void) { static int v = -1; if (v < 0) v = getenv("GUARD_FSYNC_ALL") ? 1 : 0; return v; }
static void line(const char *fn, io_connect_t c, const char *verdict, int sel, const char *extra, long r) {
    fprintf(g_log, "%ld\t%d\t%ld\t%s\tconnect=0x%x\tctype=%d\tsel=%d\t%s\t%s\t%ld\n", ++g_seq, g_pid, us(), fn, (unsigned)c, conn_type(c), sel, verdict, extra, r);
    if (fsync_all()) { fflush(g_log); fullsync(g_fd); }
}
/* GUARD_FSYNC_ALL=1: write-ahead line (on disk before the kernel sees the call) for EVERY forwarded call, so a panic leaves the exact last call in the log */
static void wal(const char *fn, io_connect_t c, int sel, const char *extra) { if (fsync_all()) line(fn, c, "ABOUT-TO-CALL(forward)", sel, extra, -1); }
void guard_mark(const char *m) { ensure(); line("mark", 0, "MARK", -1, m, 0); fflush(g_log); fullsync(g_fd); }   /* exported: progress marks from the harness, durable + mirrored */

static kern_return_t my_open(io_service_t s, task_port_t t, uint32_t type, io_connect_t *c) {
    ensure(); RES(r_open, "IOServiceOpen");
    kern_return_t r = r_open(s, t, type, c);
    if (r == 0 && c && g_nconn < MAXC) { g_conn[g_nconn].c = *c; g_conn[g_nconn].type = (int)type; g_nconn++; if (type == 3) g_stats.dvd_opens++; }
    char x[64]; snprintf(x, sizeof x, "type=%u out=0x%x", type, c ? (unsigned)*c : 0); line("IOServiceOpen", c ? *c : 0, "FWD", -1, x, r); g_stats.fwd++;
    return r;
}
static int sync_gpu(io_connect_t c, const char *why);
static kern_return_t my_close(io_connect_t c) { ensure(); RES(r_close, "IOServiceClose"); if (is_dvd(c)) sync_gpu(c, "before DVD close"); wal("IOServiceClose", c, -1, "-"); kern_return_t r = r_close(c); line("IOServiceClose", c, "FWD", -1, "-", r); g_stats.fwd++; return r; }
static kern_return_t my_addc(io_connect_t c, io_connect_t d) { ensure(); RES(r_addc, "IOConnectAddClient"); kern_return_t r = r_addc(c, d); line("IOConnectAddClient", c, "FWD", -1, "-", r); g_stats.fwd++; return r; }

static kern_return_t my_map(io_connect_t c, uint32_t type, task_port_t t, vm_address_t *a, vm_size_t *sz, IOOptionBits o) {
    ensure(); RES(r_map, "IOConnectMapMemory");
    char x[96]; int i;
    if (is_dvd(c)) {
        for (i = 0; i < g_nmaps; i++) if (g_maps[i].c == c && g_maps[i].type == type) break;
        if (i < g_nmaps && type == 1 && getenv("GUARD_FWD_REMAP")) {
            /* #141 composite run: forward the type-1 re-map = a real DVD command-buffer submit (process_command_buffer runs, the kernel swaps the ping-pong buffer and returns the new one).
             * Write-ahead first: a snapshot of the buffer being submitted is on disk (fsync) before the kernel sees it (issue #87 criterion 2). Only for deliberate experiments. */
            snapshot(c, "type1-remap-FORWARDED(write-ahead)", (unsigned)g_seq + 1);
            snprintf(x, sizeof x, "memType=1 old_addr=0x%lx", g_maps[i].addr);
            fprintf(g_log, "%ld\t%d\t%ld\tIOConnectMapMemory\tconnect=0x%x\tctype=3\tsel=-1\tABOUT-TO-CALL(type1 remap FORWARDED)\t%s\t-\n", ++g_seq, g_pid, us(), (unsigned)c, x);
            fflush(g_log); fullsync(g_fd); if (g_mem) { fflush(g_mem); fullsync(fileno(g_mem)); }
            struct timeval ta, tb; gettimeofday(&ta, NULL);
            kern_return_t rr = r_map(c, type, t, a, sz, o);
            gettimeofday(&tb, NULL);
            if (rr == 0 && a && sz) { g_maps[i].addr = *a; g_maps[i].size = *sz; g_last_stamp = *(volatile unsigned *)(g_maps[i].addr + 0x18); }
            snprintf(x, sizeof x, "memType=1 addr=0x%lx size=0x%lx us=%ld", a ? (unsigned long)*a : 0, sz ? (unsigned long)*sz : 0, (long)((tb.tv_sec - ta.tv_sec) * 1000000L + (tb.tv_usec - ta.tv_usec)));
            line("IOConnectMapMemory", c, "FWD(type1 remap FORWARDED)", -1, x, rr); fflush(g_log); fullsync(g_fd); g_stats.fwd++; g_stats.dvd_remaps++;
            return rr;
        }
        if (i < g_nmaps || !(type == 1 || type == 2 || type == 4 || type == 5)) {
            if (i < g_nmaps && a && sz) { *a = g_maps[i].addr; *sz = g_maps[i].size; }
            snapshot(c, type == 1 ? "type1-remap(submit)" : "map-swallowed", (unsigned)g_seq + 1);
            snprintf(x, sizeof x, "memType=%u addr=0x%lx size=0x%lx", type, a ? (unsigned long)*a : 0, sz ? (unsigned long)*sz : 0);
            line("IOConnectMapMemory", c, i < g_nmaps ? "SWALLOW(remap)" : "SWALLOW(type)", -1, x, i < g_nmaps ? 0 : 0); g_stats.swallow++; g_stats.dvd_remaps++;
            return i < g_nmaps ? 0 : kIOReturnUnsupported;
        }
    }
    kern_return_t r = r_map(c, type, t, a, sz, o);
    if (r == 0 && a && sz && g_nmaps < MAXM) { g_maps[g_nmaps].c = c; g_maps[g_nmaps].type = type; g_maps[g_nmaps].addr = *a; g_maps[g_nmaps].size = *sz; g_nmaps++; }
    snprintf(x, sizeof x, "memType=%u addr=0x%lx size=0x%lx", type, a ? (unsigned long)*a : 0, sz ? (unsigned long)*sz : 0); line("IOConnectMapMemory", c, "FWD", -1, x, r); g_stats.fwd++;
    return r;
}

static void synth_out(int sel, int *out, mach_msg_type_number_t *oc, char *so, mach_msg_type_number_t *soc) {
    if (out && oc) { mach_msg_type_number_t i; for (i = 0; i < *oc; i++) out[i] = 0; if (sel == 20 && *oc >= 1) out[0] = 1; }   /* check_stamps: 1 = complete */
    if (so && soc) memset(so, 0, *soc);
}
/* GUARD_SYNC_STAMPS=1 (#141): block until the GPU has retired the last forwarded submit - poll check_stamps (sel 20, scalarI_scalarO {0, stamp} -> out[0]==1 when complete; both calls are proven live on stock) every ms
 * up to GUARD_SYNC_TIMEOUT_MS (default 5000). Returns 1 if complete (or nothing pending), 0 on timeout. Write-ahead logged: the line is on disk before the first poll. */
static int sync_gpu(io_connect_t c, const char *why) {
    char y[160]; long t0, waited = 0, tmo = getenv("GUARD_SYNC_TIMEOUT_MS") ? atol(getenv("GUARD_SYNC_TIMEOUT_MS")) : 5000; int in[2], out[1]; mach_msg_type_number_t oc; kern_return_t r = 0;
    if (!getenv("GUARD_SYNC_STAMPS") || !g_last_stamp) return 1;
    RES(r_sisO, "io_connect_method_scalarI_scalarO");
    snprintf(y, sizeof y, "%s: waiting for stamp 0x%x (timeout %ld ms)", why, g_last_stamp, tmo); line("sync", c, "SYNC-BEGIN", 20, y, 0); fflush(g_log); fullsync(g_fd); t0 = us();
    for (;;) {
        in[0] = 0; in[1] = (int)g_last_stamp; out[0] = 0; oc = 1; r = r_sisO(c, 20, in, 2, out, &oc);
        if (r == 0 && out[0] == 1) break;
        waited = (us() - t0) / 1000; if (waited >= tmo || r != 0) break; usleep(1000);
    }
    snprintf(y, sizeof y, "%s: stamp 0x%x %s after %ld ms (rc=0x%x out=%d)", why, g_last_stamp, (r == 0 && out[0] == 1) ? "COMPLETE" : "NOT COMPLETE", waited, (unsigned)r, out[0]);
    line("sync", c, (r == 0 && out[0] == 1) ? "SYNC-DONE" : "SYNC-TIMEOUT", 20, y, r); fflush(g_log); fullsync(g_fd);
    return r == 0 && out[0] == 1;
}
static kern_return_t my_sisO(mach_port_t c, int sel, int *in, mach_msg_type_number_t ic, int *out, mach_msg_type_number_t *oc) {
    ensure(); RES(r_sisO, "io_connect_method_scalarI_scalarO"); char x[200]; unsigned i; int n = 0;
    for (i = 0; i < ic && i < 8; i++) n += snprintf(x + n, sizeof x - n, "%08x ", (unsigned)in[i]);
    if (is_dvd(c) && sel == 8 && out && oc && *oc >= 1 && !extra_fwd(8)) {
        /* declare_image: the kernel's out[0] is a pointer into the shared type-2 mapping which the driver dereferences (image header) and atomically increments (refcount at +0x10);
         * a zero here crashed the harness (SIGBUS in FUN_00003cd0, run "open"). Hand back a private zeroed block instead: same layout use, no kernel involvement. */
        void *blk = calloc(1, 256); out[0] = (int)blk; *oc = 1;
        char y[96]; snprintf(y, sizeof y, "%s fake_handle=%p", x, blk); line("scalarI_scalarO", c, "SWALLOW(fake image handle)", sel, y, 0); g_stats.swallow++; return 0;
    }
    if (is_dvd(c) && !fwd_selector(sel)) { synth_out(sel, out, oc, NULL, NULL); line("scalarI_scalarO", c, "SWALLOW", sel, x, 0); g_stats.swallow++; return 0; }
    wal("scalarI_scalarO", c, sel, x); kern_return_t r = r_sisO(c, sel, in, ic, out, oc); line("scalarI_scalarO", c, "FWD", sel, x, r); g_stats.fwd++;
    if (is_dvd(c) && sel == 8 && r == 0 && ic >= 3 && g_nimg < 64) { g_img[g_nimg].addr = (unsigned)in[1]; g_img[g_nimg].size = (unsigned)in[2]; g_nimg++; }
    return r;
}
static kern_return_t my_sisti(mach_port_t c, int sel, int *in, mach_msg_type_number_t ic, char *s, mach_msg_type_number_t sc) {
    ensure(); RES(r_sisti, "io_connect_method_scalarI_structureI"); char x[200]; unsigned i; int n = 0;
    for (i = 0; i < ic && i < 8; i++) n += snprintf(x + n, sizeof x - n, "%08x ", (unsigned)in[i]);
    if (is_dvd(c) && !fwd_selector(sel)) { line("scalarI_structureI", c, "SWALLOW", sel, x, 0); g_stats.swallow++; return 0; }
    if (is_dvd(c) && sel == 9 && getenv("GUARD_DELAY_DELETE_MS")) {
        /* #141: GetFrame submits a GPU pass writing into a freshly declared image, calls wait_for_stamps(0,0) (a no-op) and deletes the image at once; the g2 run panicked with a DART out-of-bounds GPU write.
         * Hypothesis: the image's GART mapping is torn down while the GPU is still writing. This knob waits before forwarding delete_image so the pass can finish. Write-ahead logged. */
        long ms = atol(getenv("GUARD_DELAY_DELETE_MS")); char y[120]; snprintf(y, sizeof y, "%s delay %ld ms before forwarding", x, ms);
        line("scalarI_structureI", c, "DELAY(delete_image)", sel, y, 0); fflush(g_log); fullsync(g_fd); usleep((useconds_t)(ms * 1000));
    }
    if (is_dvd(c) && sel == 9 && !sync_gpu(c, "before delete_image")) { line("scalarI_structureI", c, "SWALLOW(delete_image: GPU job not retired)", sel, x, 0); g_stats.swallow++; return 0; }
    wal("scalarI_structureI", c, sel, x); kern_return_t r = r_sisti(c, sel, in, ic, s, sc); line("scalarI_structureI", c, "FWD", sel, x, r); g_stats.fwd++; return r;
}
static kern_return_t my_sisto(mach_port_t c, int sel, int *in, mach_msg_type_number_t ic, char *o, mach_msg_type_number_t *oc) {
    ensure(); RES(r_sisto, "io_connect_method_scalarI_structureO"); char x[200]; unsigned i; int n = 0;
    for (i = 0; i < ic && i < 8; i++) n += snprintf(x + n, sizeof x - n, "%08x ", (unsigned)in[i]);
    if (is_dvd(c) && !fwd_selector(sel)) { synth_out(sel, NULL, NULL, o, oc); line("scalarI_structureO", c, "SWALLOW", sel, x, 0); g_stats.swallow++; return 0; }
    wal("scalarI_structureO", c, sel, x); kern_return_t r = r_sisto(c, sel, in, ic, o, oc); line("scalarI_structureO", c, "FWD", sel, x, r); g_stats.fwd++; return r;
}
static kern_return_t my_stto(mach_port_t c, int sel, char *in, mach_msg_type_number_t ic, char *out, mach_msg_type_number_t *oc) {
    ensure(); RES(r_stto, "io_connect_method_structureI_structureO");
    if (is_dvd(c) && sel == 18 && !extra_fwd(18)) {
        fprintf(g_log, "%ld\t%d\t%ld\tstructureI_structureO\tconnect=0x%x\tctype=3\tsel=18\tSWALLOW(doIDCT)\tin=%u\tparams=", ++g_seq, g_pid, us(), (unsigned)c, ic);
        hexs(g_log, in, ic); fprintf(g_log, "\t0\n");
        snapshot(c, "doIDCT", (unsigned)g_seq);
        if (out && oc) memset(out, 0, *oc);
        g_stats.swallow++; g_stats.dvd_sel18++; return 0;
    }
    if (is_dvd(c) && sel == 18 && extra_fwd(18)) {
        /* RUNG 3 probes (issue #140): GUARD_FLAG_CLEAR=<hex mask> clears bits of the control word (params+0x14, the value written to IDCT_CONTROL 0x1fbc) and GUARD_CLEAR_LAST=1 clears bit 0 of every
         * dword of the stream (the last-coefficient flags). Only for deliberate experiments; both are logged in the write-ahead line. Clearing is used instead of setting so no reset/flush bit is ever added. */
        char modnote[160]; modnote[0] = 0;
        if (ic >= 0x38) {
            unsigned *pw = (unsigned *)in; const char *fc = getenv("GUARD_FLAG_CLEAR"), *cl = getenv("GUARD_CLEAR_LAST");
            if (fc) { unsigned m = (unsigned)strtoul(fc, NULL, 16), old = pw[5]; pw[5] = old & ~m; snprintf(modnote + strlen(modnote), sizeof modnote - strlen(modnote), "FLAG %08x->%08x ", old, pw[5]); }
            if (cl && atoi(cl)) {
                int i; unsigned n = pw[4], cleared = 0;
                for (i = 0; i < g_nmaps; i++) if (g_maps[i].c == c && g_maps[i].type == (pw[3] == 0 ? 4u : 5u)) {
                    unsigned *sp = (unsigned *)(g_maps[i].addr + 0x20), k; for (k = 0; k < n; k++) if (sp[k] & 1) { sp[k] &= ~1u; cleared++; } break; }
                snprintf(modnote + strlen(modnote), sizeof modnote - strlen(modnote), "LASTBITS_CLEARED=%u ", cleared);
            }
        }
        if (modnote[0]) { fprintf(g_log, "%ld\t%d\t%ld\tstructureI_structureO\tconnect=0x%x\tctype=3\tsel=18\tMODIFIED(doIDCT)\t%s\t-\n", ++g_seq, g_pid, us(), (unsigned)c, modnote); }
        /* RUNG 3: a real doIDCT. Write-ahead: the parameter block and the snapshot are on disk (fsync) BEFORE the kernel sees the call (issue #87 criterion 2). */
        fprintf(g_log, "%ld\t%d\t%ld\tstructureI_structureO\tconnect=0x%x\tctype=3\tsel=18\tABOUT-TO-CALL(doIDCT FORWARDED)\tin=%u\tparams=", ++g_seq, g_pid, us(), (unsigned)c, ic);
        hexs(g_log, in, ic); fprintf(g_log, "\t-\n"); snapshot(c, "doIDCT-forwarded", (unsigned)g_seq);
        fflush(g_log); fullsync(g_fd); if (g_mem) { fflush(g_mem); fullsync(fileno(g_mem)); }
        struct timeval ta, tb; gettimeofday(&ta, NULL);
        kern_return_t r18 = r_stto(c, sel, in, ic, out, oc);
        gettimeofday(&tb, NULL); long dt = (tb.tv_sec - ta.tv_sec) * 1000000L + (tb.tv_usec - ta.tv_usec);
        fprintf(g_log, "%ld\t%d\t%ld\tstructureI_structureO\tconnect=0x%x\tctype=3\tsel=18\tRESULT(doIDCT FORWARDED)\trc=0x%08x\tkernel_call_us=%ld\tout=%u\n", ++g_seq, g_pid, us(), (unsigned)c, (unsigned)r18, dt, oc ? *oc : 0);
        fflush(g_log); fullsync(g_fd); g_stats.fwd++; g_stats.dvd_sel18++; return r18;
    }
    if (is_dvd(c) && !fwd_selector(sel)) { if (out && oc) memset(out, 0, *oc); line("structureI_structureO", c, "SWALLOW", sel, "-", 0); g_stats.swallow++; return 0; }
    wal("structureI_structureO", c, sel, "-"); kern_return_t r = r_stto(c, sel, in, ic, out, oc); line("structureI_structureO", c, "FWD", sel, "-", r); g_stats.fwd++; return r;
}

typedef struct { void *replacement; void *replacee; } interpose_t;
__attribute__((used)) static const interpose_t interposers[] __attribute__((section("__DATA,__interpose"))) = {
    { (void*)my_open, (void*)IOServiceOpen }, { (void*)my_close, (void*)IOServiceClose }, { (void*)my_addc, (void*)IOConnectAddClient },
    { (void*)my_map, (void*)IOConnectMapMemory },
    { (void*)my_sisO, (void*)io_connect_method_scalarI_scalarO }, { (void*)my_sisti, (void*)io_connect_method_scalarI_structureI },
    { (void*)my_stto, (void*)io_connect_method_structureI_structureO }, { (void*)my_sisto, (void*)io_connect_method_scalarI_structureO },
};
