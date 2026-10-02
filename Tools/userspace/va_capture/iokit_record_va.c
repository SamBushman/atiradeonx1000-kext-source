/* iokit_record_va.c - issue #93 (DVD doIDCT): a superset of iokit_record.c for capturing what the VA driver (ATIRadeonX1000VADriver.bundle, loaded by DVD Player / QuickTime) sends to the
 * kext. Additions over iokit_record.c: (1) it also hooks io_connect_method_scalarI_structureO (the VA bundle imports all four MIG routines); (2) it remembers every IOConnectMapMemory region (the mapped
 * command / transfer buffers the IDCT stream is written into) and, for every structureI_structureO call with selector 18 and an input struct of at least 0x34 bytes (the shape of DVD doIDCT), writes the
 * first VA_DUMP_BYTES (default 4096) of each mapped region, BEFORE the call, to the .mem file next to the log (VA_DUMP_MAX calls, default 64). Still a passive observer: every call is forwarded
 * unchanged, nothing is invented, no call is ever made that the player did not make. Build/use: see Tools/userspace/va_capture/README.md.
 * ---- original header of iokit_record.c follows ----
 * iokit_record.c - issue #64: DYLD_INSERT_LIBRARIES interpose shim that records every IOKit user-client
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
static FILE *g_mem = NULL;
#define MAXMAP 64
static struct { io_connect_t connect; unsigned type; unsigned long addr, size; } g_maps[MAXMAP];
static int g_nmaps = 0, g_dumps = 0;
static long g_seq = 0;
static struct timeval g_t0;
static int g_pid = 0;

static void ensure_log(void) {
    if (g_log) return;
    const char *path = getenv("IOKIT_RECORD_LOG");
    char buf[256];
    if (!path) { snprintf(buf, sizeof buf, "/tmp/iokit_record.%d.tsv", (int)getpid()); path = buf; }
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

#define HEXBUF_SZ 8300
static char g_inhex[HEXBUF_SZ], g_outhex[HEXBUF_SZ];

/* ---- real function pointers, resolved lazily via RTLD_NEXT ---- */
static kern_return_t (*real_IOServiceOpen)(io_service_t, task_port_t, uint32_t, io_connect_t *);
static kern_return_t (*real_IOServiceClose)(io_connect_t);
static kern_return_t (*real_IOConnectAddClient)(io_connect_t, io_connect_t);
static kern_return_t (*real_IOConnectMapMemory)(io_connect_t, uint32_t, task_port_t, vm_address_t *, vm_size_t *, IOOptionBits);
static kern_return_t (*real_scalarI_scalarO)(mach_port_t, int, int *, mach_msg_type_number_t, int *, mach_msg_type_number_t *);
static kern_return_t (*real_scalarI_structureO)(mach_port_t, int, int *, mach_msg_type_number_t, char *, mach_msg_type_number_t *);
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


/* write the mapped regions of the connection to the .mem file before a doIDCT-shaped call (one block per region: header line + hex) */
static void dump_maps(io_connect_t connect, const char *input, unsigned inputCnt) {
    const char *mx = getenv("VA_DUMP_MAX"), *bs = getenv("VA_DUMP_BYTES");
    int maxcalls = mx ? atoi(mx) : 64; unsigned long nbytes = bs ? strtoul(bs, NULL, 0) : 4096; int i; unsigned long k, n;
    if (g_dumps >= maxcalls) return;
    if (!g_mem) { char p[300]; const char *lp = getenv("IOKIT_RECORD_LOG"); snprintf(p, sizeof p, "%s.mem", lp ? lp : "/tmp/iokit_record_va"); g_mem = fopen(p, "a"); if (!g_mem) return; setvbuf(g_mem, NULL, _IOLBF, 0); }
    g_dumps++;
    fprintf(g_mem, "CALL seq=%ld connect=0x%x params=", g_seq + 1, (unsigned)connect);
    for (k = 0; k < inputCnt && k < 256; k++) fprintf(g_mem, "%02x", (unsigned char)input[k]);
    fprintf(g_mem, "\n");
    for (i = 0; i < g_nmaps; i++) {
        if (g_maps[i].connect != connect) continue;
        n = g_maps[i].size < nbytes ? g_maps[i].size : nbytes;
        fprintf(g_mem, "MAP type=%u addr=0x%lx size=0x%lx dumped=%lu ", g_maps[i].type, g_maps[i].addr, g_maps[i].size, n);
        for (k = 0; k < n; k++) fprintf(g_mem, "%02x", ((unsigned char *)g_maps[i].addr)[k]);
        fprintf(g_mem, "\n");
    }
}

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
    kern_return_t r = real_IOConnectMapMemory(connect, memoryType, intoTask, atAddress, ofSize, options);
    if (r == 0 && atAddress && ofSize && g_nmaps < MAXMAP) { g_maps[g_nmaps].connect = connect; g_maps[g_nmaps].type = memoryType; g_maps[g_nmaps].addr = (unsigned long)*atAddress; g_maps[g_nmaps].size = (unsigned long)*ofSize; g_nmaps++; }
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
    kern_return_t r = real_scalarI_structureI(connect, selector, input, inputCnt, inputStruct, inputStructCnt);
    fprintf(g_log, "%ld\t%d\t%ld\tscalarI_structureI\tconnect=0x%x\tsel=%d\t%u\tstruct=%u\t%d\t%s\t%s\n",
            ++g_seq, g_pid, usec_since_start(), (unsigned)connect, selector, inputCnt, inputStructCnt, r, g_inhex, g_outhex);
    return r;
}
static kern_return_t my_scalarI_structureO(mach_port_t connect, int selector, int *input, mach_msg_type_number_t inputCnt,
                                            char *output, mach_msg_type_number_t *outputCnt) {
    ensure_log(); RESOLVE_AS(scalarI_structureO, "io_connect_method_scalarI_structureO");
    mach_msg_type_number_t outCntBefore = outputCnt ? *outputCnt : 0;
    hexdump(g_inhex, sizeof g_inhex, input, inputCnt, 1);
    kern_return_t r = real_scalarI_structureO(connect, selector, input, inputCnt, output, outputCnt);
    hexdump(g_outhex, sizeof g_outhex, output, outputCnt ? *outputCnt : 0, 0);
    fprintf(g_log, "%ld\t%d\t%ld\tscalarI_structureO\tconnect=0x%x\tsel=%d\t%u\t%u->%u\t%d\t%s\t%s\n",
            ++g_seq, g_pid, usec_since_start(), (unsigned)connect, selector, inputCnt, outCntBefore,
            outputCnt ? *outputCnt : 0, r, g_inhex, g_outhex);
    return r;
}
static kern_return_t my_structureI_structureO(mach_port_t connect, int selector, char *input, mach_msg_type_number_t inputCnt,
                                               char *output, mach_msg_type_number_t *outputCnt) {
    ensure_log(); RESOLVE_AS(structureI_structureO, "io_connect_method_structureI_structureO");
    mach_msg_type_number_t outCntBefore = outputCnt ? *outputCnt : 0;
    hexdump(g_inhex, sizeof g_inhex, input, inputCnt, 0);
    if (selector == 18 && inputCnt >= 0x34) dump_maps(connect, input, inputCnt);
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
    { (void*)my_scalarI_structureO,       (void*)io_connect_method_scalarI_structureO },
};
