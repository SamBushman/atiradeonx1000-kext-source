/* Test for #92 (DVD write_buffer, sel 6), issue #87 protocol. Struct sIODVDContextWriteBufferData = 7 dwords {x, y, width, height, bufferSelect, userSourceAddress, sourceStride} (0x1c bytes), flags 3
 * (struct in, no struct out). Traced (IOATIR500DVDContext_write_buffer_Port.cpp, shipped 0xff..-0x10160): the body dereferences boundSurface+0xb70+off BEFORE the NULL check, so the unbound call is a
 * kernel NULL dereference (panic) and is NEVER made here. Bound: the buffer slot is surface buffers[15] (bufferSelect 0, offset 0x3c) or [16] (bufferSelect != 0, offset 0x40), usable only if its bit is in
 * this+0x88 (set by setup_buffers: param5 bits 15/16 -> 0xffffc00 covers 10..27). With the bit set and the slot's bit still pending in surface+0xbf8 the body needs buffer+0x24 (the backing record): when it is
 * 0 (what t3_dvd_lock_buffers observed: no buffer memory for this minimal surface) the body returns 0 WITHOUT any DMA (the LAB_00010160 exit); only with a backing record does it wrap the user source
 * [userSourceAddress, ...] and have the GPU copy it in through surface vtable +0x5ec. The source is OUR page-aligned 64 KB buffer (0x55 filled) and must be unchanged afterwards (it is read-only input).
 * Sequence: 4x4 surface, bind, setup_buffers(0,0,16,16,0x7ffc00), write_buffer(bufferSelect 0), write_buffer(bufferSelect 1), detach. Codes recorded; 0 or CannotLock expected. */
#include "t3common.h"
#include <stdlib.h>
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, changed = 0, sel; IOByteCount zero = 0; UInt32 in[7];
    unsigned char *buf = (unsigned char *)valloc(0x10000);
    if (!buf) return "DIVERGENCE";
    memset(buf, 0x55, 0x10000);
    if (t3_surface(t, svc, &s, 4, 4) != 0) { free(buf); return "DIVERGENCE"; }
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != 0) { IOServiceClose(s); free(buf); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD set_surface(1,0,0) binds", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
    if (r == 0) {
        T3CALL(t, r, "DVD setup_buffers(0,0,16,16, 0x7ffc00)", IOConnectMethodScalarIScalarO(d, 21, 5, 0, 0, 0, 16, 16, 0x7ffc00)); bad += t3_expect(t, "setup_buffers", r, 0);
        for (sel = 0; sel < 2 && r == 0; sel++) {
            in[0] = 0; in[1] = 0; in[2] = 4; in[3] = 4; in[4] = sel; in[5] = (UInt32)buf; in[6] = 64;
            T3CALL(t, r, sel ? "DVD write_buffer(sel6, rect 0,0,4,4, bufferSelect 1)" : "DVD write_buffer(sel6, rect 0,0,4,4, bufferSelect 0)", IOConnectMethodStructureIStructureO(d, 6, sizeof in, &zero, in, NULL));
            dtest_note(t, "write_buffer bufferSelect %d -> 0x%08x (0 = done or no-op; CannotLock = slot not enabled/usable)", sel, (unsigned)r);
            if (r != 0 && r != TEST_kIOReturnCannotLock) bad++;
            r = 0;
        }
        T3CALL(t, r, "DVD set_surface(0) detaches", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 0, 0, 0, NULL));
    }
    IOServiceClose(d); IOServiceClose(s);
    usleep(300000);
    for (i = 0; i < 0x10000; i++) if (buf[i] != 0x55) changed++;
    dtest_note(t, "source buffer bytes changed: %d (expected 0)", changed);
    if (changed) bad++;
    free(buf);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_write_buffer", 0, body); }
