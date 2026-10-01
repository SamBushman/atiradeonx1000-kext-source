/*
 * Tests/test_deep_t1.c - T1 deep paths of issue #100 (read-only, no allocation, nothing to undo): the first assertions on outputs that the
 * issue-#42 harness only RECORDED. Run with `./parity_test_harness --deep`; the oracle is baseline/stock_4.1.9_g5_tiger_deep.txt (two identical runs).
 *
 * Every call here was classified T1 from the shipped body (Tests/deep_paths.md: the callees are locks and reads; no allocator, no hardware write,
 * no sleep on a normally active device) and is a call the #42 harness has already made live without incident - the only NEW kind of call is a real
 * register READ through ATIR5002DContext::read_regs / ATIR500DVDContext::read_regs (offset & 0x1ffc into the MMIO window, assembled byte by byte,
 * nothing written; the driver itself reads RBBM_STATUS 0x0e40 in dump_registers). Registers read: CONFIG_MEMSIZE 0x00f8 (the VRAM size - cross-checked
 * against the get_config output) and RBBM_STATUS 0x0e40 (recorded, bit 31 = GUI active, not asserted).
 *
 * Assertions are INVARIANTS and values taken from the stock driver on the hardware (R580 X1900, 256 MB), not from the rebuild: a value that
 * legitimately varies is recorded ([REC]) instead.
 */
#include "common.h"
#include <stdarg.h>

extern int g_testsRun, g_testsUnexpected, g_testsRecorded;

static void check(const char *name, int cond, const char *fmt, ...) {
    char msg[200]; va_list ap; msg[0] = 0;
    if (fmt) { va_start(ap, fmt); vsnprintf(msg, sizeof msg, fmt, ap); va_end(ap); }
    g_testsRun++;
    printf("[%s] %s%s%s\n", cond ? "OK" : "UNEXPECTED", name, msg[0] ? " " : "", msg);
    if (!cond) g_testsUnexpected++;
}
static void rec(const char *name, const char *fmt, ...) {
    char msg[200]; va_list ap; va_start(ap, fmt); vsnprintf(msg, sizeof msg, fmt, ap); va_end(ap);
    g_testsRun++; g_testsRecorded++; printf("[REC] %s %s\n", name, msg);
}
static int is_pow2(UInt32 v) { return v != 0 && (v & (v - 1)) == 0; }

static io_connect_t open_or_fail(io_service_t service, UInt32 type, const char *what) {
    io_connect_t c = IO_OBJECT_NULL; kern_return_t kr = open_user_client(service, type, &c);
    if (kr != TEST_kIOReturnSuccess) { printf("[FAIL] could not open %s user client: 0x%08x\n", what, (unsigned int)kr); g_testsUnexpected++; return IO_OBJECT_NULL; }
    return c;
}

/* real register reads through the 2D (sel 16) or DVD (sel 13) context: offsets in, values out, same byte count */
static kern_return_t read_regs(io_connect_t c, int sel, const UInt32 *offs, UInt32 *vals, int n) {
    IOByteCount outSize = n * 4;
    return IOConnectMethodStructureIStructureO(c, sel, n * 4, &outSize, (void *)offs, vals);
}

static int g_vram = -1, g_cfg0 = -1;

static void gl_t1(io_service_t service) {
    io_connect_t c = open_or_fail(service, CLIENT_TYPE_GL, "GL"); int a0 = -1, a1 = -1, a2 = -1, b0 = -1, b1 = -1, b2 = -1; int st = -1; int hw[5] = {-1, -1, -1, -1, -1}; int hw2[5];
    kern_return_t r; int i, same;
    if (c == IO_OBJECT_NULL) return;
    printf("-- GL T1 --\n");
    r = IOConnectMethodScalarIScalarO(c, 3, 0, 3, &a0, &a1, &a2);
    check("GL get_config(sel 3) succeeds", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 3, 0, 3, &b0, &b1, &b2);
    check("GL get_config(sel 3) is repeatable", r == TEST_kIOReturnSuccess && a0 == b0 && a1 == b1 && a2 == b2, "{%d,%d,%d} vs {%d,%d,%d}", a0, a1, a2, b0, b1, b2);
    check("GL get_config out[2] (VRAM bytes) is a power of two >= 64 MB", is_pow2((UInt32)a2) && (UInt32)a2 >= 0x4000000, "out[2]=0x%x", (unsigned int)a2);
    check("GL get_config out[1] (usable VRAM) is within out[2] and >= half of it", (UInt32)a1 <= (UInt32)a2 && (UInt32)a1 >= (UInt32)a2 / 2, "out[1]=0x%x out[2]=0x%x", (unsigned int)a1, (unsigned int)a2);
    g_vram = a2; g_cfg0 = a0;
    r = IOConnectMethodScalarIScalarO(c, 4, 0, 1, &st);
    check("GL get_status(sel 4) succeeds", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    check("GL get_status(sel 4) == 0 on an idle device (stock baseline)", st == 0, "status=0x%x", (unsigned int)st);
    r = IOConnectMethodScalarIScalarO(c, 20, 0, 5, &hw[0], &hw[1], &hw[2], &hw[3], &hw[4]);
    check("GL get_hw_info(sel 20) succeeds", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    check("GL get_hw_info chip id == 0x7240 (R580, the stock value on this X1900)", hw[1] == 0x7240, "hw={0x%x,0x%x,0x%x,0x%x,0x%x}", hw[0], hw[1], hw[2], hw[3], hw[4]);
    check("GL get_hw_info pipe counts are plausible (1..16, z pipes >= 1)", hw[0] >= 1 && hw[0] <= 16 && hw[2] >= 1 && hw[2] <= 16 && hw[3] >= 1, "numPipes-ish=%d,%d zPipes-ish=%d", hw[0], hw[2], hw[3]);
    r = IOConnectMethodScalarIScalarO(c, 20, 0, 5, &hw2[0], &hw2[1], &hw2[2], &hw2[3], &hw2[4]);
    for (same = 1, i = 0; i < 5; i++) if (hw2[i] != hw[i]) same = 0;
    check("GL get_hw_info(sel 20) is repeatable", r == TEST_kIOReturnSuccess && same, NULL);
    IOServiceClose(c);
}

static void twod_t1(io_service_t service) {
    io_connect_t c = open_or_fail(service, CLIENT_TYPE_2D, "2D"); int o0 = -1, o1 = -1; kern_return_t r;
    UInt32 offs[2] = { 0x00f8, 0x0e40 }, v1[2] = {0, 0}, v2[2] = {0, 0};
    unsigned char info[0x30], info2[0x30]; IOByteCount sz;
    if (c == IO_OBJECT_NULL) return;
    printf("-- 2D T1 --\n");
    r = IOConnectMethodScalarIScalarO(c, 1, 0, 2, &o0, &o1);
    check("2D get_config(sel 1) succeeds", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    check("2D get_config == GL get_config {out[0], out[2]}", o0 == g_cfg0 && o1 == g_vram, "2D={%d,%d} GL out0=%d out2=%d", o0, o1, g_cfg0, g_vram);
    memset(info, 0xAA, sizeof info); sz = sizeof info;
    r = IOConnectMethodScalarIStructureO(c, 2, 2, &sz, 0, 0, info);
    check("2D get_surface_info(panel 0) succeeds, 0x30 bytes", r == TEST_kIOReturnSuccess && sz == 0x30, "r=0x%08x outSize=%u", (unsigned int)r, (unsigned int)sz);
    { UInt32 *d = (UInt32 *)info;
      check("2D get_surface_info packs width/height consistently (d[1] == d[2]<<16 | d[3]) and a real mode (>= 640x480)", d[1] == ((d[2] << 16) | d[3]) && d[2] >= 640 && d[3] >= 480, "d[1]=0x%x w=%u h=%u", (unsigned int)d[1], (unsigned int)d[2], (unsigned int)d[3]); }
    memset(info2, 0x55, sizeof info2); sz = sizeof info2;
    r = IOConnectMethodScalarIStructureO(c, 2, 2, &sz, 0, 0, info2);
    check("2D get_surface_info(panel 0) is repeatable", r == TEST_kIOReturnSuccess && memcmp(info, info2, sizeof info) == 0, NULL);
    r = read_regs(c, 16, offs, v1, 2);
    check("2D read_regs(sel 16) of CONFIG_MEMSIZE 0x00f8 + RBBM_STATUS 0x0e40 succeeds", r == TEST_kIOReturnSuccess, "r=0x%08x", (unsigned int)r);
    check("2D read_regs CONFIG_MEMSIZE == the VRAM size reported by get_config", (int)v1[0] == g_vram, "reg=0x%x vram=0x%x", (unsigned int)v1[0], (unsigned int)g_vram);
    rec("2D read_regs RBBM_STATUS(0x0e40) (bit 31 = GUI active; varies)", "= 0x%08x", (unsigned int)v1[1]);
    r = read_regs(c, 16, offs, v2, 1);
    check("2D read_regs one register: CONFIG_MEMSIZE is repeatable", r == TEST_kIOReturnSuccess && v2[0] == v1[0], "0x%x vs 0x%x", (unsigned int)v2[0], (unsigned int)v1[0]);
    IOServiceClose(c);
}

static void dvd_t1(io_service_t service) {
    io_connect_t c = open_or_fail(service, CLIENT_TYPE_DVD, "DVD"); int o0 = -1, o1 = -1, s0 = -1, both = -1; kern_return_t r;
    UInt32 offs[1] = { 0x00f8 }, v[1] = {0};
    if (c == IO_OBJECT_NULL) return;
    printf("-- DVD T1 --\n");
    r = IOConnectMethodScalarIScalarO(c, 1, 0, 2, &o0, &o1);
    check("DVD get_config(sel 1) == 2D get_config", r == TEST_kIOReturnSuccess && o0 == g_cfg0 && o1 == g_vram, "DVD={%d,%d}", o0, o1);
    r = IOConnectMethodScalarIScalarO(c, 2, 0, 1, &s0);
    check("DVD get_status(sel 2) == 0 with nothing bound (stock baseline)", r == TEST_kIOReturnSuccess && s0 == 0, "r=0x%08x out0=%d", (unsigned int)r, s0);
    r = read_regs(c, 13, offs, v, 1);
    check("DVD read_regs(sel 13) CONFIG_MEMSIZE == the VRAM size reported by get_config", r == TEST_kIOReturnSuccess && (int)v[0] == g_vram, "r=0x%08x reg=0x%x", (unsigned int)r, (unsigned int)v[0]);
    r = IOConnectMethodScalarIScalarO(c, 20, 2, 1, 0, 0, &both);
    check("DVD check_stamps(sel 20, 0, 0): both done", r == TEST_kIOReturnSuccess && both == 1, "r=0x%08x both=%d", (unsigned int)r, both);
    IOServiceClose(c);
}

static void surface_t1(io_service_t service) {
    io_connect_t c = open_or_fail(service, CLIENT_TYPE_SURFACE, "Surface"); int st = -1, st2 = -1; kern_return_t r;
    if (c == IO_OBJECT_NULL) return;
    printf("-- Surface T1 --\n");
    r = IOConnectMethodScalarIScalarO(c, 2, 0, 1, &st);
    check("Surface get_state(sel 2) == 1 (stock baseline)", r == TEST_kIOReturnSuccess && st == 1, "r=0x%08x state=%d", (unsigned int)r, st);
    r = IOConnectMethodScalarIScalarO(c, 11, 0, 0);
    check("Surface surface_query_lock(sel 11) with no lock held -> CannotLock", r == TEST_kIOReturnCannotLock, "r=0x%08x", (unsigned int)r);
    r = IOConnectMethodScalarIScalarO(c, 2, 0, 1, &st2);
    check("Surface get_state(sel 2) unchanged after the query", r == TEST_kIOReturnSuccess && st2 == st, "state=%d", st2);
    IOServiceClose(c);
}

void run_deep_t1_tests(io_service_t service) {
    gl_t1(service); twod_t1(service); dvd_t1(service); surface_t1(service);
}
