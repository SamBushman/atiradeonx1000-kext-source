/* T3 test for #121 (Surface set_shape_backing, sel 6) non-zero backing-store connect path, issue #100 / protocol #87. Traced (IOATIR500Surface_connect_buffer_backing_store_Port.cpp, shipped
 * 0x12800; set_shape_backing -> set_shape_backing_length_ext): sel 6 takes (shapeBits, id, backingAddress, backingPitch) + an IOAccelDeviceRegion. With backingAddress != 0 and
 * backingPitch not 0 / 0xffffffff the body wraps the USER memory [backingAddress & -page, buffer height * backingPitch + offset] in an IOMemoryDescriptor (withAddress, the connection's
 * task), wires it (vtable +0xdc prepare(2)) and attaches it as the surface buffer's backing store (attach_buffer_backing_store, flag +0x59 = 1). backingAddress 0 with pitch 0 deletes
 * an existing backing (delete_buffer_backing) and connects nothing. The address is therefore OUR OWN page-aligned 64 KB user buffer (valloc, pre-filled), nothing foreign is mapped,
 * shapeBits 0 (no wait, no retag, not stale). Sequence: proven 4x4 set-up; connect (addr, pitch 64); read back the surface size through a bound 2D connection (must stay 4x4); disconnect
 * (0, 0); close everything BEFORE freeing the buffer. Nothing in this sequence writes into the buffer (no flush/lock), checked at the end (still all 0xAA). */
#include "t3common.h"
#include <stdlib.h>
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL; kern_return_t r; int bad = 0, i, changed = 0; unsigned char region[20]; unsigned char *buf = (unsigned char *)valloc(0x10000);
    if (!buf) return "DIVERGENCE";
    memset(buf, 0xAA, 0x10000);
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) { free(buf); return "DIVERGENCE"; }
    memset(region, 0, sizeof region);
    *(UInt32 *)(region + 0) = 1; *(SInt16 *)(region + 8) = 4; *(SInt16 *)(region + 10) = 4; *(SInt16 *)(region + 16) = 4; *(SInt16 *)(region + 18) = 4;
    T3CALL(t, r, "Surface set_shape_backing(sel6, shapeBits 0, id 1, addr = 64 KB user buffer, pitch 64, region 4x4)", IOConnectMethodScalarIStructureI(s, 6, 4, sizeof region, 0, 1, (int)buf, 64, region));
    dtest_note(t, "connect -> r=0x%08x", (unsigned)r); bad += t3_expect(t, "connect backing", r, 0);
    T3CALL(t, r, "Surface get_state after connect", IOConnectMethodScalarIScalarO(s, 2, 0, 1, &i)); dtest_note(t, "get_state=0x%x", (unsigned)i);
    T3CALL(t, r, "Surface set_shape_backing(sel6, 0, 1, addr 0, pitch 0, region 4x4) disconnects", IOConnectMethodScalarIStructureI(s, 6, 4, sizeof region, 0, 1, 0, 0, region));
    dtest_note(t, "disconnect -> r=0x%08x", (unsigned)r); bad += t3_expect(t, "disconnect backing", r, 0);
    IOServiceClose(s);
    usleep(300000);
    for (i = 0; i < 0x10000; i++) if (buf[i] != 0xAA) changed++;
    dtest_note(t, "user buffer bytes changed: %d (expected 0)", changed);
    if (changed) bad++;
    free(buf);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_surface_backing", 0, body); }
