/* ava_drive.c - issue #140 rung 2: drive Apple's real DVD-decode entry points in AppleVA.framework (which load and call the real ATIRadeonX1000VADriver) with the
 * pictures from ava_vectors.h, UNDER iokit_guard_va.dylib (default-deny: doIDCT and every command-buffer submission are swallowed and logged, nothing reaches the engine).
 * Must run inside the console (Aqua) session: it needs a WindowServer connection to create the window + surface the ATI renderer binds (CGSBindSurface).
 *
 *   gcc -o ava_drive ava_drive.c -F/System/Library/PrivateFrameworks -framework AppleVA -framework ApplicationServices
 *   GUARD_LOG=/tmp/va_guard.tsv DYLD_INSERT_LIBRARIES=/tmp/va_cap/iokit_guard_va.dylib ./ava_drive
 *
 * Safety: refuses to decode unless the guard reports it saw the DVD connection open; SIGALRM watchdog kills the process after WATCHDOG_S (default 90 s);
 * everything printed is also in the guard log. No doIDCT, no command buffer, no register write can reach the kernel from this process. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <dlfcn.h>
#include <mach/mach.h>
#include <IOKit/IOKitLib.h>
#include <IOKit/iokitmig_c.h>
#include <ApplicationServices/ApplicationServices.h>
#include "ava_vectors.h"

typedef int CGSConnectionID, CGSWindowID, CGSSurfaceID;
typedef void *CGSRegionRef;
extern CGSConnectionID CGSMainConnectionID(void);
extern CGError CGSNewRegionWithRect(const CGRect *rect, CGSRegionRef *region);
extern CGError CGSNewWindow(CGSConnectionID cid, int backingType, float left, float top, CGSRegionRef region, CGSWindowID *wid);
extern CGError CGSAddSurface(CGSConnectionID cid, CGSWindowID wid, CGSSurfaceID *sid);
extern CGError CGSOrderWindow(CGSConnectionID cid, CGSWindowID wid, int place, CGSWindowID relativeTo);
extern CGError CGSRemoveSurface(CGSConnectionID cid, CGSWindowID wid, CGSSurfaceID sid);
extern CGError CGSReleaseWindow(CGSConnectionID cid, CGSWindowID wid);
extern CGError CGSReleaseRegion(CGSRegionRef region);

/* AppleVA.framework exports (signatures read from the decompile, ppc ABI: args 9 and 10 are on the stack) */
extern int DVDDriverOpenDeviceImpl(void **dev, unsigned *sizes /*[2] out*/, unsigned display, int cid, int wid, int sid, unsigned *flags /*out*/, short *rect /*top,left,bottom,right*/, short *out9, short *out10);
extern void DVDDriverDecodeImpl(void *dev, unsigned char *picture, short *rect);
extern void DVDDriverCloseDeviceImpl(void *dev);

static io_connect_t rb_gl = 0, rb_2d = 0; static unsigned char *rb_buf = NULL;
/* read-back through the proven GL read_buffer path (Tests/destructive/t3_gl_read_buffer.c): GL user client bound to the same surface, sourceSelector 1 = surface buffer slot 0 */
static int rb_setup(int sid) {
    io_service_t svc = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("ATIRadeonX1000")); kern_return_t r;
    if (!svc) return -1;
    { /* the proven way to give the surface backing memory (t3_gl_read_buffer.c): 2D client binds the surface, lock_memory(0) allocates, unlock_memory(0) */
        io_connect_t d2 = 0; unsigned char o30[0x30]; IOByteCount osz = sizeof o30; int addr = -1, size = -1, tag = -1;
        r = IOServiceOpen(svc, mach_task_self(), 2, &d2); printf("readback: open 2D client rc=0x%x\n", (unsigned)r);
        if (!r) {
            r = IOConnectMethodScalarIStructureO(d2, 0, 2, &osz, sid, 0x800, o30); printf("readback: 2D set_surface(sid, 0x800) rc=0x%x\n", (unsigned)r);
            if (!r) { r = IOConnectMethodScalarIScalarO(d2, 5, 1, 2, 0, &addr, &size); printf("readback: 2D lock_memory(0) rc=0x%x addr=0x%x size=0x%x\n", (unsigned)r, addr, size);
                      if (!r) { r = IOConnectMethodScalarIScalarO(d2, 6, 1, 1, 0, &tag); printf("readback: 2D unlock_memory(0) rc=0x%x\n", (unsigned)r); } }
            rb_2d = d2;
        }
    }
    r = IOServiceOpen(svc, mach_task_self(), 1, &rb_gl); printf("readback: open GL client rc=0x%x\n", (unsigned)r); if (r) return -2;
    r = IOConnectMethodScalarIStructureI(rb_gl, 0, 4, 0, sid, 0x800, 0, 0, NULL); printf("readback: GL set_surface(sid, 0x800) rc=0x%x\n", (unsigned)r);
    rb_buf = (unsigned char *)valloc(0x10000); return r ? -3 : 0;
}
static int rb_read(const char *label, int w, int h) {
    unsigned in[7]; IOByteCount zero = 0; kern_return_t r; int y, x;
    memset(rb_buf, 0xAA, 0x10000);
    in[0] = 0; in[1] = 0; in[2] = w; in[3] = h; in[4] = 1; in[5] = (unsigned)rb_buf; in[6] = 64;
    r = IOConnectMethodStructureIStructureO(rb_gl, 7, sizeof in, &zero, in, NULL);
    printf("readback[%s]: GL read_buffer rc=0x%08x (0 = copied; 0xe00002cc = surface memory not usable)\n", label, (unsigned)r);
    if (r == 0) for (y = 0; y < h; y++) { printf("  row %2d:", y); for (x = 0; x < w * 4; x++) printf(" %02x", rb_buf[y * 64 + x]); printf("\n"); }
    fflush(stdout); return (int)r;
}
static long (*guard_stat)(int);
static int (*guard_dvd_connect)(void);
static void on_alarm(int s) { fprintf(stderr, "WATCHDOG: no completion in time (decode stuck?) - exiting\n"); fflush(stderr); _exit(3); }
static void stats(const char *when) { if (guard_stat) printf("  [guard %s] fwd=%ld swallow=%ld dvd_opens=%ld doIDCT(sel18)=%ld remaps=%ld\n", when, guard_stat(0), guard_stat(1), guard_stat(2), guard_stat(3), guard_stat(4)); fflush(stdout); }

int main(int argc, char **argv) {
    int i, rc; CGSConnectionID cid; CGSWindowID wid = 0; CGSSurfaceID sid = 0; CGSRegionRef reg = NULL; CGRect r = CGRectMake(0, 0, VEC_W, VEC_H);
    void *dev = NULL; unsigned sizes[2] = {0, 0}, flags = 0; short rect[4] = {0, 0, VEC_H, VEC_W}, o9 = 0, o10 = 0; unsigned display = (unsigned)(unsigned long)CGMainDisplayID();
    const char *ws = getenv("WATCHDOG_S"); int skipdecode = 0, hold_before = 0, hold_after = 0, k, repeat = 1, dst_override = 1000, lockbuf = 0, readback = 0; unsigned picmask = ~0u;
    for (k = 1; k < argc; k++) {
        if (!strcmp(argv[k], "--open-only")) skipdecode = 1;
        else if (!strcmp(argv[k], "--hold-before") && k + 1 < argc) hold_before = atoi(argv[++k]);
        else if (!strcmp(argv[k], "--hold-after") && k + 1 < argc) hold_after = atoi(argv[++k]);
        else if (!strcmp(argv[k], "--lock-buffers")) lockbuf = 1;
        else if (!strcmp(argv[k], "--readback")) readback = 1;
        else if (!strcmp(argv[k], "--repeat") && k + 1 < argc) repeat = atoi(argv[++k]);
        else if (!strcmp(argv[k], "--dst") && k + 1 < argc) dst_override = atoi(argv[++k]);
        else if (!strcmp(argv[k], "--pictures") && k + 1 < argc) { char *t, *v = strdup(argv[++k]); picmask = 0; for (t = strtok(v, ","); t; t = strtok(NULL, ",")) picmask |= 1u << atoi(t); }
    }
    signal(SIGALRM, on_alarm); alarm(ws ? atoi(ws) : 90);
    guard_stat = (long (*)(int))dlsym(RTLD_DEFAULT, "guard_stat");
    guard_dvd_connect = (int (*)(void))dlsym(RTLD_DEFAULT, "guard_dvd_connect");
    printf("ava_drive: display 0x%x, guard %s\n", display, guard_stat ? "LOADED" : "NOT LOADED (refusing to continue)"); fflush(stdout);
    if (!guard_stat) return 2;
    cid = CGSMainConnectionID();
    rc = CGSNewRegionWithRect(&r, &reg); printf("CGSNewRegionWithRect rc=%d\n", rc);
    { const char *wx = getenv("WIN_X"), *wy = getenv("WIN_Y"); rc = CGSNewWindow(cid, 2, wx ? atof(wx) : 300, wy ? atof(wy) : 300, reg, &wid); } printf("CGSNewWindow cid=%d -> wid=%d rc=%d\n", cid, wid, rc);
    rc = CGSAddSurface(cid, wid, &sid); printf("CGSAddSurface -> sid=%d rc=%d\n", sid, rc);
    rc = CGSOrderWindow(cid, wid, 1, 0); printf("CGSOrderWindow rc=%d\n", rc); fflush(stdout);
    if (!wid || !sid) { printf("no window/surface: stop\n"); return 2; }
    stats("before open");
    rc = DVDDriverOpenDeviceImpl(&dev, sizes, display, cid, wid, sid, &flags, rect, &o9, &o10);
    printf("DVDDriverOpenDeviceImpl rc=0x%x dev=%p sizes=%u,%u flags=0x%x out9=%d out10=%d\n", (unsigned)rc, dev, sizes[0], sizes[1], flags, o9, o10);
    stats("after open");
    if (rc != 0 || !dev) { printf("open failed (the host renderer fallback may have been used): stop\n"); goto out; }
    if (guard_stat(2) < 1) { printf("the guard did not see a DVD (type 3) connection open: the renderer in use is not the ATI one, or interposition missed it. Refusing to decode.\n"); goto out; }
    if (lockbuf) {   /* what the driver's own set-parameter tail does after setup_buffers + set_surface: selector 4 lock_all_buffers (allocates slots 10..22, returns 13 {address,pitch} pairs) */
        int conn = guard_dvd_connect ? guard_dvd_connect() : 0, in[1] = {0}; unsigned out[64]; mach_msg_type_number_t oc = sizeof out; kern_return_t kr; int q;
        memset(out, 0, sizeof out);
        printf("lock_all_buffers: connect=0x%x (forwarded only if GUARD_FORWARD includes 4)\n", conn); fflush(stdout);
        kr = io_connect_method_scalarI_structureO(conn, 4, in, 1, (char *)out, &oc);
        printf("lock_all_buffers -> rc=0x%08x outSize=%u\n", (unsigned)kr, (unsigned)oc);
        for (q = 0; q < 13; q++) printf("  slot %d: address=0x%08x pitch=0x%x\n", 10 + q, out[q * 2], out[q * 2 + 1]);
        fflush(stdout);
    }
    if (skipdecode) { if (hold_before) { printf("HOLD-BEFORE %d s (open-only: DVD context is open, XDCT engine started)\n", hold_before); fflush(stdout); sleep(hold_before); } printf("--open-only: stop after open\n"); goto out; }
    if (hold_before) { printf("HOLD-BEFORE %d s (window is up; take the 'before' screenshot now)\n", hold_before); fflush(stdout); sleep(hold_before); }
    if (readback) { if (rb_setup(sid) == 0) rb_read("before", 8, 20); else readback = 0; }
    for (i = 0; i < VEC_NPIC; i++) {
        if (!(picmask & (1u << i))) continue;
        { int rep; for (rep = 0; rep < repeat; rep++) {
        unsigned char desc[0x20]; size_t nrec = VEC_NMB * 0x1c; unsigned char *recs = malloc(nrec); unsigned *coefs = malloc((vec_pics[i].ncoefs + 1) * 4);
        memcpy(recs, vec_pics[i].recs, nrec); memcpy(coefs, vec_pics[i].coefs, vec_pics[i].ncoefs * 4);
        memset(desc, 0, sizeof desc);
        desc[0] = vec_pics[i].ptype; desc[2] = 3 /* frame */; desc[4] = vec_pics[i].alt; desc[6] = dst_override != 1000 ? (unsigned char)dst_override : vec_pics[i].dst; desc[7] = vec_pics[i].fwd; desc[8] = 0;
        *(unsigned char **)(desc + 0x0c) = recs; *(unsigned **)(desc + 0x10) = coefs;
        printf("picture %d '%s': type %d alt %d dst %d fwd %d, %d coefficient dwords\n", i, vec_pics[i].name, vec_pics[i].ptype, vec_pics[i].alt, vec_pics[i].dst, vec_pics[i].fwd, vec_pics[i].ncoefs); fflush(stdout);
        DVDDriverDecodeImpl(dev, desc, rect);
        printf("  decode returned (repeat %d)\n", rep); stats("after decode");
        } }
    }
    if (readback) rb_read("after", 8, 20);
    if (hold_after) { printf("HOLD-AFTER %d s (take the 'after' screenshot now)\n", hold_after); fflush(stdout); sleep(hold_after); }
out:
    if (dev) DVDDriverCloseDeviceImpl(dev);
    stats("after close");
    CGSRemoveSurface(cid, wid, sid); CGSReleaseWindow(cid, wid); if (reg) CGSReleaseRegion(reg);
    printf("ava_drive: done\n"); return 0;
}
