/* iokit_record.c - issue #64: DYLD_INSERT_LIBRARIES interpose shim that records every IOKit user-client
 * call a process makes (IOServiceOpen/Close, IOConnectAddClient, IOConnectMapMemory, and the three
 * io_connect_method_* MIG routines that ATIRadeonX1000GLDriver imports directly - see decls.h). Every
 * interposed call is forwarded unchanged to the real implementation (dlsym(RTLD_NEXT, ...), snapshotted
 * once) so the process behaves exactly as it would without this library; only a log record is added.
 *
 * This is a passive observer of real IOKit traffic a real caller (CGL, the stock or rebuilt GLDriver
 * bundle) generates on its own - it never invents, fuzzes, or synthesizes a call or an argument. See
 * issue #64 and the standing constraint against broad IOConnect* fuzzing.
 *
 * Build: gcc -dynamiclib -o iokit_record.dylib iokit_record.c
 * Use:   IOKIT_RECORD_LOG=/path/to/log.tsv DYLD_INSERT_LIBRARIES=/path/to/iokit_record.dylib <program>
 *        (log path defaults to /tmp/iokit_record.<pid>.tsv if the env var is unset)
 *
 * Log format: one line per call, tab-separated:
 *   seq \t pid \t us_since_first_call \t function \t connect \t selector \t inCnt \t outCnt \t result \t in-hex \t out-hex
 * in-hex/out-hex are the scalar words or struct bytes actually passed, exactly `*Cnt` of them (capped at
 * 4096 bytes/256 words per direction so one runaway call can't blow up the log) - self-describing, no
 * struct-layout knowledge needed to record or to later diff two logs byte-for-byte.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <unistd.h>
#include <sys/time.h>
#include <mach/mach_types.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/iokitmig_c.h>  /* declares io_connect_method_scalarI_scalarO etc. with the exact MIG-generated ABI */

static FILE *g_log = NULL;
static long g_seq = 0;
static struct timeval g_t0;
static int g_pid = 0;

static unsigned long g_cb_addr = 0, g_cb_size = 0, g_cb_bytes = 0x8000; static char g_logpath[300];
static void ensure_log(void) {
    if (g_log) return;
    const char *path = getenv("IOKIT_RECORD_LOG");
    char buf[256];
    if (!path) { snprintf(buf, sizeof buf, "/tmp/iokit_record.%d.tsv", (int)getpid()); path = buf; }
    snprintf(g_logpath, sizeof g_logpath, "%s", path);
    if (getenv("IOKIT_RECORD_CB_BYTES")) g_cb_bytes = strtoul(getenv("IOKIT_RECORD_CB_BYTES"), NULL, 0);
    g_log = fopen(path, "a");
    if (!g_log) g_log = stderr;
    setvbuf(g_log, NULL, _IOLBF, 0);
    gettimeofday(&g_t0, NULL);
    g_pid = (int)getpid();
    fprintf(g_log, "# iokit_record start pid=%d path=%s\n", g_pid, path);
}

static long usec_since_start(void) {
    struct timeval now; gettimeofday(&now, NULL);
    return (now.tv_sec - g_t0.tv_sec) * 1000000L + (now.tv_usec - g_t0.tv_usec);
}

static void hexdump(char *out, size_t outsz, const void *data, unsigned count, int is_words) {
    size_t n = 0; unsigned i;
    unsigned bytes = is_words ? count * 4 : count;
    if (bytes > 4096) bytes = 4096;
    const unsigned char *p = (const unsigned char *)data;
    if (!data) { snprintf(out, outsz, "NULL"); return; }
    for (i = 0; i < bytes && n + 2 < outsz; i++) { n += snprintf(out + n, outsz - n, "%02x", p[i]); }
    if (i < (is_words ? count * 4 : count)) snprintf(out + n, outsz - n, "...TRUNC");
}

/* #214: a call that never returns (the Doom 3 glBufferSubData wedge) would never reach the post-call log line, so every method call is first logged
 * as "ENTER" (flushed) with its selector and input words; the matching result line follows only if the call returns. */
#define WRITE_AHEAD(fn, conn, sel, cnt, inhex) do { fprintf(g_log, "%ld\t%d\t%ld\tENTER %s\tconnect=0x%x\tsel=%d\t%u\t-\t-\t%s\t-\n", g_seq + 1, g_pid, usec_since_start(), fn, (unsigned)(conn), (int)(sel), (unsigned)(cnt), inhex); fflush(g_log); } while (0)
#define HEXBUF_SZ 8300
static char g_inhex[HEXBUF_SZ], g_outhex[HEXBUF_SZ];

/* ---- real function pointers, resolved lazily via RTLD_NEXT ---- */
static kern_return_t (*real_IOServiceOpen)(io_service_t, task_port_t, uint32_t, io_connect_t *);
static kern_return_t (*real_IOServiceClose)(io_connect_t);
static kern_return_t (*real_IOConnectAddClient)(io_connect_t, io_connect_t);
static kern_return_t (*real_IOConnectMapMemory)(io_connect_t, uint32_t, task_port_t, vm_address_t *, vm_size_t *, IOOptionBits);
static kern_return_t (*real_scalarI_scalarO)(mach_port_t, int, int *, mach_msg_type_number_t, int *, mach_msg_type_number_t *);
static kern_return_t (*real_scalarI_structureI)(mach_port_t, int, int *, mach_msg_type_number_t, char *, mach_msg_type_number_t);
static kern_return_t (*real_structureI_structureO)(mach_port_t, int, char *, mach_msg_type_number_t, char *, mach_msg_type_number_t *);

/* RTLD_NEXT can fail to resolve a symbol that a call originates from *inside* a dlopen'd bundle
 * (confirmed live: it returned NULL for io_connect_method_scalarI_scalarO called from within
 * ATIRadeonX1000GLDriver.bundle, and the resulting call-through-NULL crashed the process with SIGBUS -
 * see the #64 work log). Fall back to an explicit dlopen of IOKit.framework by path, which is
 * unambiguous regardless of RTLD_NEXT's search-order scoping. Abort loudly rather than call through a
 * NULL pointer if both fail - a silent NULL call is exactly what crashed this the first time.
 */
static void *g_iokit_handle = NULL;
static void *resolve_real(const char *name) {
    void *p = dlsym(RTLD_NEXT, name);
    if (p) return p;
    if (!g_iokit_handle) {
        g_iokit_handle = dlopen("/System/Library/Frameworks/IOKit.framework/Versions/A/IOKit", RTLD_NOW | RTLD_GLOBAL);
        if (!g_iokit_handle) g_iokit_handle = dlopen("/System/Library/Frameworks/IOKit.framework/IOKit", RTLD_NOW | RTLD_GLOBAL);
    }
    if (g_iokit_handle) p = dlsym(g_iokit_handle, name);
    if (!p) {
        fprintf(stderr, "iokit_record: FATAL could not resolve real %s (RTLD_NEXT and dlopen both failed): %s\n", name, dlerror());
        abort();
    }
    return p;
}
#define RESOLVE(sym) if (!real_##sym) real_##sym = (void*)resolve_real(#sym)
#define RESOLVE_AS(sym, realname) if (!real_##sym) real_##sym = (void*)resolve_real(realname)

static kern_return_t my_IOServiceOpen(io_service_t service, task_port_t owningTask, uint32_t type, io_connect_t *connect) {
    ensure_log(); RESOLVE(IOServiceOpen);
    kern_return_t r = real_IOServiceOpen(service, owningTask, type, connect);
    fprintf(g_log, "%ld\t%d\t%ld\tIOServiceOpen\tservice=0x%x\ttype=%u\t-\t-\t%d\tconnect_out=0x%x\t-\n",
            ++g_seq, g_pid, usec_since_start(), (unsigned)service, type, r, connect ? (unsigned)*connect : 0);
    return r;
}
static kern_return_t my_IOServiceClose(io_connect_t connect) {
    ensure_log(); RESOLVE(IOServiceClose);
    kern_return_t r = real_IOServiceClose(connect);
    fprintf(g_log, "%ld\t%d\t%ld\tIOServiceClose\tconnect=0x%x\t-\t-\t-\t%d\t-\t-\n",
            ++g_seq, g_pid, usec_since_start(), (unsigned)connect, r);
    return r;
}
static kern_return_t my_IOConnectAddClient(io_connect_t connect, io_connect_t client) {
    ensure_log(); RESOLVE(IOConnectAddClient);
    kern_return_t r = real_IOConnectAddClient(connect, client);
    fprintf(g_log, "%ld\t%d\t%ld\tIOConnectAddClient\tconnect=0x%x\tclient=0x%x\t-\t-\t%d\t-\t-\n",
            ++g_seq, g_pid, usec_since_start(), (unsigned)connect, (unsigned)client, r);
    return r;
}
static kern_return_t my_IOConnectMapMemory(io_connect_t connect, uint32_t memoryType, task_port_t intoTask,
                                            vm_address_t *atAddress, vm_size_t *ofSize, IOOptionBits options) {
    ensure_log(); RESOLVE(IOConnectMapMemory);
    /* #214: a type-1 re-map is how the GL driver SUBMITS a command buffer (the old mapping holds the commands about to be executed). Snapshot the first
     * IOKIT_RECORD_CB_BYTES (default 0x8000) of it, write-ahead and flushed, into <log>.cb<seq mod 8>.bin so the buffer that wedges the CP survives the hang. */
    if (memoryType == 1 && g_cb_addr) {
        char fn[400]; FILE *f; size_t n = g_cb_size < g_cb_bytes ? g_cb_size : g_cb_bytes;
        snprintf(fn, sizeof fn, "%s.cb%ld.bin", g_logpath, (g_seq + 1) % 8);
        f = fopen(fn, "wb"); if (f) { fwrite((void *)g_cb_addr, 1, n, f); fflush(f); fclose(f); }
        fprintf(g_log, "%ld\t%d\t%ld\tSNAPSHOT cb\tconnect=0x%x\taddr=0x%lx\tbytes=0x%lx\t-\t-\t%s\t-\n", g_seq + 1, g_pid, usec_since_start(), (unsigned)connect, (unsigned long)g_cb_addr, (unsigned long)n, fn); fflush(g_log);
    }
    kern_return_t r = real_IOConnectMapMemory(connect, memoryType, intoTask, atAddress, ofSize, options);
    if (memoryType == 1 && r == 0 && atAddress && ofSize) { g_cb_addr = *atAddress; g_cb_size = *ofSize; }
    fprintf(g_log, "%ld\t%d\t%ld\tIOConnectMapMemory\tconnect=0x%x\tmemType=%u\toptions=0x%x\t-\t%d\taddr=0x%lx\tsize=0x%lx\n",
            ++g_seq, g_pid, usec_since_start(), (unsigned)connect, memoryType, (unsigned)options, r,
            atAddress ? (unsigned long)*atAddress : 0, ofSize ? (unsigned long)*ofSize : 0);
    return r;
}
static kern_return_t my_scalarI_scalarO(mach_port_t connect, int selector, int *input, mach_msg_type_number_t inputCnt,
                                         int *output, mach_msg_type_number_t *outputCnt) {
    ensure_log(); RESOLVE_AS(scalarI_scalarO, "io_connect_method_scalarI_scalarO");
    mach_msg_type_number_t outCntBefore = outputCnt ? *outputCnt : 0;
    hexdump(g_inhex, sizeof g_inhex, input, inputCnt, 1);
    WRITE_AHEAD("scalarI_scalarO", connect, selector, inputCnt, g_inhex);
    kern_return_t r = real_scalarI_scalarO(connect, selector, input, inputCnt, output, outputCnt);
    hexdump(g_outhex, sizeof g_outhex, output, outputCnt ? *outputCnt : 0, 1);
    fprintf(g_log, "%ld\t%d\t%ld\tscalarI_scalarO\tconnect=0x%x\tsel=%d\t%u\t%u->%u\t%d\t%s\t%s\n",
            ++g_seq, g_pid, usec_since_start(), (unsigned)connect, selector, inputCnt, outCntBefore,
            outputCnt ? *outputCnt : 0, r, g_inhex, g_outhex);
    return r;
}
static kern_return_t my_scalarI_structureI(mach_port_t connect, int selector, int *input, mach_msg_type_number_t inputCnt,
                                            char *inputStruct, mach_msg_type_number_t inputStructCnt) {
    ensure_log(); RESOLVE_AS(scalarI_structureI, "io_connect_method_scalarI_structureI");
    hexdump(g_inhex, sizeof g_inhex, input, inputCnt, 1);
    hexdump(g_outhex, sizeof g_outhex, inputStruct, inputStructCnt, 0);
    WRITE_AHEAD("scalarI_structureI", connect, selector, inputCnt, g_inhex);
    kern_return_t r = real_scalarI_structureI(connect, selector, input, inputCnt, inputStruct, inputStructCnt);
    fprintf(g_log, "%ld\t%d\t%ld\tscalarI_structureI\tconnect=0x%x\tsel=%d\t%u\tstruct=%u\t%d\t%s\t%s\n",
            ++g_seq, g_pid, usec_since_start(), (unsigned)connect, selector, inputCnt, inputStructCnt, r, g_inhex, g_outhex);
    return r;
}
static kern_return_t my_structureI_structureO(mach_port_t connect, int selector, char *input, mach_msg_type_number_t inputCnt,
                                               char *output, mach_msg_type_number_t *outputCnt) {
    ensure_log(); RESOLVE_AS(structureI_structureO, "io_connect_method_structureI_structureO");
    mach_msg_type_number_t outCntBefore = outputCnt ? *outputCnt : 0;
    hexdump(g_inhex, sizeof g_inhex, input, inputCnt, 0);
    WRITE_AHEAD("structureI_structureO", connect, selector, inputCnt, g_inhex);
    kern_return_t r = real_structureI_structureO(connect, selector, input, inputCnt, output, outputCnt);
    hexdump(g_outhex, sizeof g_outhex, output, outputCnt ? *outputCnt : 0, 0);
    fprintf(g_log, "%ld\t%d\t%ld\tstructureI_structureO\tconnect=0x%x\tsel=%d\tin=%u\t%u->%u\t%d\t%s\t%s\n",
            ++g_seq, g_pid, usec_since_start(), (unsigned)connect, selector, inputCnt, outCntBefore,
            outputCnt ? *outputCnt : 0, r, g_inhex, g_outhex);
    return r;
}

typedef struct { void *replacement; void *replacee; } interpose_t;
__attribute__((used))
static const interpose_t interposers[] __attribute__((section("__DATA,__interpose"))) = {
    { (void*)my_IOServiceOpen,            (void*)IOServiceOpen },
    { (void*)my_IOServiceClose,           (void*)IOServiceClose },
    { (void*)my_IOConnectAddClient,       (void*)IOConnectAddClient },
    { (void*)my_IOConnectMapMemory,       (void*)IOConnectMapMemory },
    { (void*)my_scalarI_scalarO,          (void*)io_connect_method_scalarI_scalarO },
    { (void*)my_scalarI_structureI,       (void*)io_connect_method_scalarI_structureI },
    { (void*)my_structureI_structureO,    (void*)io_connect_method_structureI_structureO },
};
