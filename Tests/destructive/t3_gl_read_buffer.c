/* T3 test for #103 (GL read_buffer, sel 7), issue #100 / protocol #87. Input sIOGLContextReadBufferData = 7 dwords {x, y, w, h, sourceSelector, clientAddress, rowBytes} (0x1c bytes): the dword the
 * header calls destOffset (+0x14) is the USER ADDRESS (it is added to the clipped-rectangle byte offset and handed to IOMemoryDescriptor::withAddress, exactly like IOAccelSurfaceReadData's
 * client_addr in Surface surface_read), +0x18 the row bytes; sourceSelector 1 selects surface buffer slot 0 (the one the 2D lock below allocates). Traced (IOATIR500GLContext_read_buffer_Port.cpp,
 * shipped 0x8d10): the buffer is only used when this context's requirement mask (this+0x8c) covers the slot, which set_surface(1, mode 0) may or may not set: CannotLock 0xe00002cc is the
 * predicted reject (EXPECTED-REJECT, nothing written). The valid path wraps the user range and has the GPU copy the slot into it through surface vtable +0x5e8 (copy_buffer_using_DMA family).
 * Run 1 (mode 0) returned the predicted CannotLock; GL set_surface (shipped 0x87b0, source lines 93-117) sets this+0x8c |= 1 only when modeBits has 0x800 (0x400 -> 0x20000002), so run 2 binds with
 * modeBits 0x800 (the same bit 2D set_surface uses for the front buffer). Derived like t3_surface_read (#116, same DMA): the memory is created the proven way (2D bind + lock_memory + unlock_memory(0)), the destination is a page-aligned 64 KB pre-filled buffer. */
/* original header of t3_surface_read.c follows for the shared trace: Surface surface_read, IOAccelSurfaceReadData {x,y,w,h,client_addr,row_bytes}:
 * Traced (IOATIR500Surface_surface_read_Port.cpp, shipped 0x14a30): for an in-surface rectangle the body wraps [client_addr rounded to a page, length from
 * row_bytes * (h-1) + the surface pitch * w + offset] in an IOMemoryDescriptor (withAddress, the connection's task) and has the GPU copy the surface buffer into it through surface vtable
 * +0x5e8 (copy_buffer_using_DMA family), waiting for the stamp under the accelerator lock. It first needs the surface's backing memory (buffer+0x10): a bare Surface connection has none
 * (-> CannotLock 0xe00002cc, the predicted reject), so the memory is created the proven way: a 2D connection binds the surface and lock_memory/unlock_memory(0) allocates it
 * (t3_2d_lock_unlock passed). The destination is a page-aligned 64 KB user buffer pre-filled with 0xAA: only bytes inside rows 0..3 (row_bytes 64) may change; any change beyond the
 * first 4 * 64 bytes is a DIVERGENCE (the copy wrote outside its rectangle). */
#include "t3common.h"
#include <stdlib.h>
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, addr = -1, size = -1, tag = -1, changed_inside = 0, changed_outside = 0;
    IOByteCount osz, zero = 0; unsigned char out[0x30]; UInt32 in[7]; io_connect_t g = IO_OBJECT_NULL; unsigned char *buf = (unsigned char *)valloc(0x10000);
    if (!buf) return "DIVERGENCE";
    memset(buf, 0xAA, 0x10000);
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) { free(buf); return "DIVERGENCE"; }
    T3CALL(t, r, "open 2D connection", open_user_client(svc, CLIENT_TYPE_2D, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); free(buf); return "DIVERGENCE"; }
    osz = sizeof out;
    T3CALL(t, r, "2D set_surface(id 1, mode 0x800) binds", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 1, 0x800, out)); bad += t3_expect(t, "bind", r, 0);
    if (r == 0) {
        T3CALL(t, r, "2D lock_memory(0) allocates the surface memory", IOConnectMethodScalarIScalarO(d, 5, 1, 2, 0, &addr, &size)); bad += t3_expect(t, "lock", r, 0);
        if (r == 0) { T3CALL(t, r, "2D unlock_memory(0)", IOConnectMethodScalarIScalarO(d, 6, 1, 1, 0, &tag)); bad += t3_expect(t, "unlock", r, 0); }
        in[0] = 0; in[1] = 0; in[2] = 4; in[3] = 4; in[4] = 1; in[5] = (UInt32)buf; in[6] = 64;
        T3CALL(t, r, "open GL connection", open_user_client(svc, CLIENT_TYPE_GL, &g)); bad += t3_expect(t, "open GL", r, 0);
        T3CALL(t, r, "GL set_surface(1, modeBits 0x800, 0, 0) binds with the front-buffer requirement", IOConnectMethodScalarIStructureI(g, 0, 4, 0, 1, 0x800, 0, 0, NULL)); bad += t3_expect(t, "GL bind", r, 0);
        T3CALL(t, r, "GL read_buffer(sel7, rect {0,0,4,4}, selector 1, user buffer, row_bytes 64)", IOConnectMethodStructureIStructureO(g, 7, sizeof in, &zero, in, NULL));
        dtest_note(t, "read_buffer -> r=0x%08x (0 = copied; CannotLock 0xe00002cc = surface memory not usable: predicted reject)", (unsigned)r);
        if (r != 0 && r != TEST_kIOReturnCannotLock) bad++;
        for (i = 0; i < 0x10000; i++) if (buf[i] != 0xAA) { if (i < 4 * 64) changed_inside++; else changed_outside++; }
        dtest_note(t, "bytes changed inside rows 0..3: %d, outside: %d; first row: %02x %02x %02x %02x %02x %02x %02x %02x", changed_inside, changed_outside, buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
        if (changed_outside) bad++;
        T3CALL(t, r, "GL set_surface(0) detaches", IOConnectMethodScalarIStructureI(g, 0, 4, 0, 0, 0, 0, 0, NULL));
        IOServiceClose(g);
        T3CALL(t, r, "2D set_surface(0) detaches", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 0, 0x800, out));
    }
    IOServiceClose(d); IOServiceClose(s); free(buf);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_gl_read_buffer", 0, body); }
