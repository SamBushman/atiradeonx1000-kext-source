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
extern int DVDDriverGetFrameImpl(void *dev, int frame, void *buf, int rowbytes, int mode);   /* AppleVA 0x97d8241c: mode 2 'yuvs', 8 'yuv2', 16 'argb', 32 'rgba', 64 'ar15' (renderer table +0x54 converts the decoded frame into buf) */

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
static int rb_sel = 1;
static int rb_read(const char *label, int w, int h) {
    unsigned in[7]; IOByteCount zero = 0; kern_return_t r; int y, x, nz = 0, shown = 0; int rowbytes = 256;
    memset(rb_buf, 0xAA, 0x10000);
    in[0] = 0; in[1] = 0; in[2] = w; in[3] = h; in[4] = rb_sel; in[5] = (unsigned)rb_buf; in[6] = rowbytes;
    r = IOConnectMethodStructureIStructureO(rb_gl, 7, sizeof in, &zero, in, NULL);
    printf("readback[%s] sel %d: GL read_buffer %dx%d rc=0x%08x (0 = copied; 0xe00002cc = surface memory not usable)\n", label, rb_sel, w, h, (unsigned)r);
    if (r == 0) {
        for (y = 0; y < h; y++) for (x = 0; x < w * 4; x++) if (rb_buf[y * rowbytes + x] != 0) { nz++; if (shown < 24) { printf("  nonzero: row %d byte %d = %02x\n", y, x, rb_buf[y * rowbytes + x]); shown++; } }
        printf("  %d non-zero bytes in the %dx%d read (0xAA fill is gone where the copy wrote)\n", nz, w, h);
        for (y = 0; y < 18; y++) { printf("  row %2d:", y); for (x = 0; x < 24; x++) printf(" %02x", rb_buf[y * rowbytes + x]); printf("\n"); }
    }
    if (r == 0 && getenv("RB_DUMP")) { char fn[300]; FILE *fp; snprintf(fn, sizeof fn, "%s_%s_s%d.bin", getenv("RB_DUMP"), label, rb_sel); fp = fopen(fn, "wb"); if (fp) { for (y = 0; y < h; y++) fwrite(rb_buf + y * rowbytes, 1, w * 4, fp); fclose(fp); printf("  dumped %s (%d bytes)\n", fn, w * 4 * h); } }
    fflush(stdout); return (int)r;
}
static long (*guard_stat)(int);
static int (*guard_dvd_connect)(void);
static void (*guard_mark)(const char *); static int (*guard_dump_images)(const char *); static int (*guard_nimages)(void);
#define MARK(s) do { if (guard_mark) guard_mark(s); } while (0)
static void on_alarm(int s) { fprintf(stderr, "WATCHDOG: no completion in time (decode stuck?) - exiting\n"); fflush(stderr); _exit(3); }
static void stats(const char *when) { if (guard_stat) printf("  [guard %s] fwd=%ld swallow=%ld dvd_opens=%ld doIDCT(sel18)=%ld remaps=%ld\n", when, guard_stat(0), guard_stat(1), guard_stat(2), guard_stat(3), guard_stat(4)); fflush(stdout); }

int main(int argc, char **argv) {
    int i, rc; CGSConnectionID cid; CGSWindowID wid = 0; CGSSurfaceID sid = 0; CGSRegionRef reg = NULL; CGRect r = CGRectMake(0, 0, VEC_W, VEC_H);
    void *dev = NULL; unsigned sizes[2] = {0, 0}, flags = 0; short rect[4] = {0, 0, VEC_H, VEC_W}, o9 = 0, o10 = 0; unsigned display = (unsigned)(unsigned long)CGMainDisplayID();
    const char *ws = getenv("WATCHDOG_S"); int readall = 0, height_arg = 0, skipdecode = 0, hold_before = 0, hold_after = 0, k, repeat = 1, dst_override = 1000, lockbuf = 0, setupbuf = 0, readback = 0, dumpimg = 0, getframe = 0, pstruct_override = -1, writebuf_sel = -1, prelock_delay_ms = 0; unsigned picmask = ~0u;
    for (k = 1; k < argc; k++) {
        if (!strcmp(argv[k], "--open-only")) skipdecode = 1;
        else if (!strcmp(argv[k], "--hold-before") && k + 1 < argc) hold_before = atoi(argv[++k]);
        else if (!strcmp(argv[k], "--hold-after") && k + 1 < argc) hold_after = atoi(argv[++k]);
        else if (!strcmp(argv[k], "--lock-buffers")) lockbuf = 1;
        else if (!strcmp(argv[k], "--setup-buffers")) setupbuf = 1;   /* #92: real setup_buffers (sel 21) calls - ATIR500DVDContext_setup_buffers_Port.cpp:40 sets this+0x88 = param5&0xfffffc00|0x20000002, the real source of lock_all_buffers' request mask; without this, self+0x88 keeps start()'s 0x20000402 default which never overlaps surface+0xbf8 - proven-real two-call sequence from Tests/destructive/t3_dvd_lock_buffers.c (masks 0x27c00 then 0x37c00, 64x48) */
        else if (!strcmp(argv[k], "--pre-lock-delay-ms") && k + 1 < argc) prelock_delay_ms = atoi(argv[++k]);   /* #92: test whether lock_all_buffers' own "available & requested == 0 -> skip allocation" fast path (real code, IOATIR500DVDContext_lock_all_buffers_Port.cpp:49) is being hit because *(surface+0xbf8) hasn't been populated yet by the time we call it - this test skips setup_buffers/set_surface entirely, unlike the real driver */
        else if (!strcmp(argv[k], "--write-buffer") && k + 1 < argc) writebuf_sel = atoi(argv[++k]);   /* #92: real DVD write_buffer (sel 6) after --lock-buffers establishes real backing */
        else if (!strcmp(argv[k], "--readback")) readback = 1;
        else if (!strcmp(argv[k], "--getframe") && k + 1 < argc) getframe = atoi(argv[++k]);   /* #141: after each decode call DVDDriverGetFrameImpl(dev, dst, buf, rowbytes, MODE) and dump buf */
        else if (!strcmp(argv[k], "--dump-images")) dumpimg = 1;   /* #141: dump every declare_image buffer (GPU-visible user memory) before the first picture and after each decode (+1 s settle) */
        else if (!strcmp(argv[k], "--readall")) { readback = 1; readall = 1; }
        else if (!strcmp(argv[k], "--height") && k + 1 < argc) height_arg = atoi(argv[++k]);
        else if (!strcmp(argv[k], "--repeat") && k + 1 < argc) repeat = atoi(argv[++k]);
        else if (!strcmp(argv[k], "--dst") && k + 1 < argc) dst_override = atoi(argv[++k]);
        else if (!strcmp(argv[k], "--pstruct") && k + 1 < argc) pstruct_override = atoi(argv[++k]);   /* #141 criterion 4: desc[2] picture_structure (1 top field, 2 bottom field, 3 frame - the hardcoded default) */
        else if (!strcmp(argv[k], "--pictures") && k + 1 < argc) { char *t, *v = strdup(argv[++k]); picmask = 0; for (t = strtok(v, ","); t; t = strtok(NULL, ",")) picmask |= 1u << atoi(t); }
    }
    if (height_arg) rect[2] = (short)height_arg;   /* open/decode rectangle height (default VEC_H) */
    signal(SIGALRM, on_alarm); alarm(ws ? atoi(ws) : 90);
    guard_stat = (long (*)(int))dlsym(RTLD_DEFAULT, "guard_stat");
    guard_dvd_connect = (int (*)(void))dlsym(RTLD_DEFAULT, "guard_dvd_connect");
    guard_mark = (void (*)(const char *))dlsym(RTLD_DEFAULT, "guard_mark"); guard_dump_images = (int (*)(const char *))dlsym(RTLD_DEFAULT, "guard_dump_images"); guard_nimages = (int (*)(void))dlsym(RTLD_DEFAULT, "guard_nimages");
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
    if (setupbuf) {   /* #92: real setup_buffers (sel 21) - sets this+0x88, the source of lock_all_buffers' request mask (see ATIR500DVDContext_setup_buffers_Port.cpp:40). Two-call sequence proven real in Tests/destructive/t3_dvd_lock_buffers.c (section 9b/9c/9d of idct_engine_findings.md). */
        int conn = guard_dvd_connect ? guard_dvd_connect() : 0; kern_return_t kr;
        printf("setup_buffers: connect=0x%x (forwarded only if GUARD_FORWARD includes 21)\n", conn); fflush(stdout);
        kr = IOConnectMethodScalarIScalarO(conn, 21, 5, 0, 0, 64, 48, 0, 0x27c00);
        printf("setup_buffers #1(0,64,48,0,0x27c00) -> rc=0x%08x\n", (unsigned)kr); fflush(stdout);
        if (kr == 0) {
            kr = IOConnectMethodScalarIScalarO(conn, 21, 5, 0, 0, 64, 48, 0, 0x37c00);
            printf("setup_buffers #2(0,64,48,0,0x37c00) -> rc=0x%08x\n", (unsigned)kr); fflush(stdout);
        }
    }
    if (prelock_delay_ms > 0) { printf("pre-lock delay: %d ms\n", prelock_delay_ms); fflush(stdout); usleep(prelock_delay_ms * 1000); }
    if (lockbuf) {   /* what the driver's own set-parameter tail does after setup_buffers + set_surface: selector 4 lock_all_buffers (allocates slots 10..22, returns 13 {address,pitch} pairs) */
        int conn = guard_dvd_connect ? guard_dvd_connect() : 0, in[1] = {0}; unsigned out[64]; mach_msg_type_number_t oc = sizeof out; kern_return_t kr; int q;
        memset(out, 0, sizeof out);
        printf("lock_all_buffers: connect=0x%x (forwarded only if GUARD_FORWARD includes 4)\n", conn); fflush(stdout);
        kr = io_connect_method_scalarI_structureO(conn, 4, in, 1, (char *)out, &oc);
        printf("lock_all_buffers -> rc=0x%08x outSize=%u\n", (unsigned)kr, (unsigned)oc);
        for (q = 0; q < 13; q++) printf("  slot %d: address=0x%08x pitch=0x%x\n", 10 + q, out[q * 2], out[q * 2 + 1]);
        fflush(stdout);
    }
    if (writebuf_sel >= 0) {   /* #92: real write_buffer (sel 6) - only takes the real DMA path (vs. the documented no-op) if --lock-buffers already gave the target slot a backing record */
        int conn = guard_dvd_connect ? guard_dvd_connect() : 0; kern_return_t kr;
        static unsigned char wbuf[0x10000]; int in[7]; mach_msg_type_number_t oc = 0;
        unsigned rin, rout; mach_msg_type_number_t rsz; UInt32 rptr0 = 0xffffffff, wptr0 = 0xffffffff, rptr1 = 0xffffffff, wptr1 = 0xffffffff;
        memset(wbuf, 0x55, sizeof wbuf);
        in[0] = 0; in[1] = 0; in[2] = 4; in[3] = 4; in[4] = writebuf_sel; in[5] = (int)wbuf; in[6] = 64;
        /* bracket the call tightly with CP_RB_RPTR/WPTR (0x710/0x714) reads - a real GPU blit dispatch (vtable +0x5ec) submits to this ring; the documented no-op exit never touches it */
        rin = 0x710; rsz = sizeof rout; io_connect_method_structureI_structureO(conn, 13, (char *)&rin, sizeof rin, (char *)&rout, &rsz); rptr0 = rout;
        rin = 0x714; rsz = sizeof rout; io_connect_method_structureI_structureO(conn, 13, (char *)&rin, sizeof rin, (char *)&rout, &rsz); wptr0 = rout;
        printf("write_buffer: connect=0x%x bufferSelect=%d (forwarded only if GUARD_FORWARD includes 6); CP_RB_RPTR=0x%08x CP_RB_WPTR=0x%08x (before)\n", conn, writebuf_sel, rptr0, wptr0); fflush(stdout);
        kr = io_connect_method_structureI_structureO(conn, 6, (char *)in, sizeof in, NULL, &oc);
        rin = 0x710; rsz = sizeof rout; io_connect_method_structureI_structureO(conn, 13, (char *)&rin, sizeof rin, (char *)&rout, &rsz); rptr1 = rout;
        rin = 0x714; rsz = sizeof rout; io_connect_method_structureI_structureO(conn, 13, (char *)&rin, sizeof rin, (char *)&rout, &rsz); wptr1 = rout;
        printf("write_buffer -> rc=0x%08x; CP_RB_RPTR=0x%08x CP_RB_WPTR=0x%08x (after) - %s\n", (unsigned)kr, rptr1, wptr1,
               (rptr1 != rptr0 || wptr1 != wptr0) ? "RING MOVED: real GPU submission happened" : "ring unchanged: consistent with the documented no-op (no backing record / no real DMA)");
        fflush(stdout);
    }
    if (skipdecode) { if (hold_before) { printf("HOLD-BEFORE %d s (open-only: DVD context is open, XDCT engine started)\n", hold_before); fflush(stdout); sleep(hold_before); } printf("--open-only: stop after open\n"); goto out; }
    if (hold_before) { printf("HOLD-BEFORE %d s (window is up; take the 'before' screenshot now)\n", hold_before); fflush(stdout); sleep(hold_before); }
    if (readback) { if (rb_setup(sid) == 0) { static const int sels[] = {1, 0, 7, 8, 2, 3, 4, 10, 11}; int q; for (q = 0; q < (readall ? 9 : 1); q++) { rb_sel = sels[q]; rb_read("before", 64, 48); } } else readback = 0; }
    if (dumpimg && guard_dump_images && getenv("RB_DUMP")) { char pf[300]; snprintf(pf, sizeof pf, "%s_before", getenv("RB_DUMP")); printf("dump-images: %d images declared, wrote %d (before)\n", guard_nimages(), guard_dump_images(pf)); fflush(stdout); }
    for (i = 0; i < VEC_NPIC; i++) {
        if (!(picmask & (1u << i))) continue;
        { int rep; for (rep = 0; rep < repeat; rep++) {
        unsigned char desc[0x20]; size_t nrec = VEC_NMB * 0x1c; unsigned char *recs = malloc(nrec); unsigned *coefs = malloc((vec_pics[i].ncoefs + 1) * 4);
        memcpy(recs, vec_pics[i].recs, nrec); memcpy(coefs, vec_pics[i].coefs, vec_pics[i].ncoefs * 4);
        memset(desc, 0, sizeof desc);
        desc[0] = vec_pics[i].ptype; desc[2] = pstruct_override >= 0 ? (unsigned char)pstruct_override : 3 /* frame */; desc[4] = vec_pics[i].alt; desc[6] = dst_override != 1000 ? (unsigned char)dst_override : vec_pics[i].dst; desc[7] = vec_pics[i].fwd; desc[8] = 0;
        *(unsigned char **)(desc + 0x0c) = recs; *(unsigned **)(desc + 0x10) = coefs;
        printf("picture %d '%s': type %d alt %d dst %d fwd %d, %d coefficient dwords, pstruct %d\n", i, vec_pics[i].name, vec_pics[i].ptype, vec_pics[i].alt, vec_pics[i].dst, vec_pics[i].fwd, vec_pics[i].ncoefs, (int)desc[2]); fflush(stdout);
        MARK("decode: calling DVDDriverDecodeImpl"); DVDDriverDecodeImpl(dev, desc, rect); MARK("decode: DVDDriverDecodeImpl returned");
        printf("  decode returned (repeat %d)\n", rep); stats("after decode");
        if (getframe) {
            int grow = 128; size_t gsz = 4u << 20; unsigned char *gb = (unsigned char *)valloc(gsz); int grc, gy; long gnz = 0, gfirst = -1, glast = -1; size_t gq;
            MARK("getframe: buffer allocated"); memset(gb, 0xAA, gsz); MARK("getframe: buffer filled"); sleep(1); MARK("getframe: settle sleep done, calling DVDDriverGetFrameImpl");
            { int bpp = (getframe == 16 || getframe == 32) ? 4 : 2; grow = rect[3] * bpp;   /* MUST equal width*bytes-per-pixel: GetFrame declares the destination image as height*width*bpp and programs the render pitch from this argument; a larger value (2048 in runs g2-g6) makes the GPU write far past the mapped image -> DART out-of-bounds panic */
              printf("  GetFrame(dev, frame %d, buf %p, rowbytes %d, mode %d) ...\n", vec_pics[i].dst, (void *)gb, grow, getframe); fflush(stdout); }
            grc = DVDDriverGetFrameImpl(dev, dst_override != 1000 ? dst_override : vec_pics[i].dst, gb, grow, getframe);
            MARK("getframe: DVDDriverGetFrameImpl returned");
            for (gq = 0; gq < gsz; gq++) if (gb[gq] != 0xAA) { gnz++; if (gfirst < 0) gfirst = (long)gq; glast = (long)gq; }
            printf("  GetFrame rc=%d: %ld bytes changed from the 0xAA fill (first 0x%lx, last 0x%lx)\n", grc, gnz, gfirst, glast);
            for (gy = 0; gy < 6; gy++) { int gx; printf("  row %d:", gy); for (gx = 0; gx < 32; gx++) printf(" %02x", gb[gy * grow + gx]); printf("\n"); }
            if (getenv("RB_DUMP")) { char gf[300]; FILE *gfp; snprintf(gf, sizeof gf, "%s_gf_p%d_m%d.bin", getenv("RB_DUMP"), i, getframe); gfp = fopen(gf, "wb"); if (gfp) { fwrite(gb, 1, glast >= 0 ? (size_t)glast + 1 : 0, gfp); fclose(gfp); printf("  dumped %s\n", gf); } }
            fflush(stdout); free(gb);
        }
        if (dumpimg && guard_dump_images && getenv("RB_DUMP")) { char pf[300]; sleep(1); snprintf(pf, sizeof pf, "%s_after_p%d", getenv("RB_DUMP"), i); printf("dump-images: wrote %d (after picture %d)\n", guard_dump_images(pf), i); fflush(stdout); }
        } }
    }
    if (readback) { static const int sels[] = {1, 0, 7, 8, 2, 3, 4, 10, 11}; int q; for (q = 0; q < (readall ? 9 : 1); q++) { rb_sel = sels[q]; rb_read("after", 64, 48); } if (!readall) { sleep(3); rb_read("after+3s", 64, 48); } }
    if (hold_after) { printf("HOLD-AFTER %d s (take the 'after' screenshot now)\n", hold_after); fflush(stdout); sleep(hold_after); }
out:
    if (dev) DVDDriverCloseDeviceImpl(dev);
    stats("after close");
    CGSRemoveSurface(cid, wid, sid); CGSReleaseWindow(cid, wid); if (reg) CGSReleaseRegion(reg);
    printf("ava_drive: done\n"); return 0;
}
