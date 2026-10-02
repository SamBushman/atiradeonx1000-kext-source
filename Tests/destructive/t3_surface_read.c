/* T3 test for #116 (Surface surface_read, sel 5, in-surface rectangle) with the IOAccelSurfaceReadData layout of Headers/IOAccelWireLayouts.h (24 bytes {x,y,w,h,client_addr,row_bytes}),
 * issue #100 / protocol #87. Traced (IOATIR500Surface_surface_read_Port.cpp, shipped 0x14a30): for an in-surface rectangle the body wraps [client_addr rounded to a page, length from
 * row_bytes * (h-1) + the surface pitch * w + offset] in an IOMemoryDescriptor (withAddress, the connection's task) and has the GPU copy the surface buffer into it through surface vtable
 * +0x5e8 (copy_buffer_using_DMA family), waiting for the stamp under the accelerator lock. It first needs the surface's backing memory (buffer+0x10): a bare Surface connection has none
 * (-> CannotLock 0xe00002cc, the predicted reject), so the memory is created the proven way: a 2D connection binds the surface and lock_memory/unlock_memory(0) allocates it
 * (t3_2d_lock_unlock passed). The destination is a page-aligned 64 KB user buffer pre-filled with 0xAA: only bytes inside rows 0..3 (row_bytes 64) may change; any change beyond the
 * first 4 * 64 bytes is a DIVERGENCE (the copy wrote outside its rectangle). */
#include "t3common.h"
#include <stdlib.h>
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, addr = -1, size = -1, tag = -1, changed_inside = 0, changed_outside = 0;
    IOByteCount osz, zero = 0; unsigned char out[0x30]; UInt32 in[6]; unsigned char *buf = (unsigned char *)valloc(0x10000);
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
        in[0] = 0; in[1] = 0; in[2] = 4; in[3] = 4; in[4] = (UInt32)buf; in[5] = 64;
        T3CALL(t, r, "Surface surface_read(sel5, rect {0,0,4,4}, client_addr = 64 KB user buffer, row_bytes 64)", IOConnectMethodStructureIStructureO(s, 5, sizeof in, &zero, in, NULL));
        dtest_note(t, "surface_read -> r=0x%08x (0 = copied; CannotLock 0xe00002cc = surface memory not usable: predicted reject)", (unsigned)r);
        if (r != 0 && r != TEST_kIOReturnCannotLock) bad++;
        for (i = 0; i < 0x10000; i++) if (buf[i] != 0xAA) { if (i < 4 * 64) changed_inside++; else changed_outside++; }
        dtest_note(t, "bytes changed inside rows 0..3: %d, outside: %d; first row: %02x %02x %02x %02x %02x %02x %02x %02x", changed_inside, changed_outside, buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], buf[6], buf[7]);
        if (changed_outside) bad++;
        T3CALL(t, r, "2D set_surface(0) detaches", IOConnectMethodScalarIStructureO(d, 0, 2, &osz, 0, 0x800, out));
    }
    IOServiceClose(d); IOServiceClose(s); free(buf);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_surface_read", 0, body); }
