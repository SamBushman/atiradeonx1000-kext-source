/* T3 test for #42 (GL opcode 0x36 - the one opcode left unexercised after the Oct 3 injection pass, Tests/pm4_opcode_gaps.md), issue #100 protocol #87.
 * 0x36's handler (Sources/ATIR500GLContext_process_command_buffer_Port.cpp) treats record word 1 as a kernel VendorTransferBuffer* and maps it to the GART
 * (map_transfer_to_GART / IOATIR500Accelerator::freeTransferToAllocGART) - confirmed via Tools/userspace/emu/kemu.py that this does REAL GART-pool bookkeeping,
 * unlike the other 8 injected opcodes (pure PM4-local rewrites): a fake/garbage pointer is not safe to try here, only a REAL kernel handle is. That handle is
 * exactly what get_data_buffer (external method selector 18, 0 scalar in / 2 scalar out) returns (traced: ctx+0x200, the record's word-1 source, is written
 * only by this method). This test: bind a GL surface, call get_data_buffer for a real handle, inject ONE 0x36 record using it, followed by the discard guard
 * (0x43 with an out-of-range texture id, the same guard already proven live for the other 8 opcodes) and a terminator, flush (GL memType 1 - both the initial
 * buffer and the flush for GL, unlike 2D's split: IOATIR500GLContext_ClientMemoryForType.cpp "type 1: the real ... submit/swap logic"), and read back. */
#include "t3common.h"
#include <mach/mach.h>
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, g = IO_OBJECT_NULL; kern_return_t r; int bad = 0;
    unsigned handle = 0xffffffff, addrOut = 0xffffffff;
    vm_address_t addr = 0; vm_size_t size = 0;
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "open GL connection", open_user_client(svc, CLIENT_TYPE_GL, &g));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "GL set_surface(1, modeBits 0x800) binds", IOConnectMethodScalarIStructureI(g, 0, 4, 0, 1, 0x800, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
    if (r != 0) { IOServiceClose(g); IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "GL get_data_buffer (sel 18) - a real kernel VendorTransferBuffer handle", IOConnectMethodScalarIScalarO(g, 18, 0, 2, &handle, &addrOut));
    bad += t3_expect(t, "get_data_buffer", r, 0);
    dtest_note(t, "get_data_buffer -> r=0x%08x handle=0x%x addr=0x%x", (unsigned)r, handle, addrOut);
    if (r != 0) { IOServiceClose(g); IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "map the initial/flush command buffer (GL memType 1)", IOConnectMapMemory(g, 1, mach_task_self(), &addr, &size, kIOMapAnywhere));
    bad += t3_expect(t, "map buffer", r, 0);
    if (r != 0) { IOServiceClose(g); IOServiceClose(s); return "DIVERGENCE"; }
    {
        volatile unsigned *p = (volatile unsigned *)(addr + 0x1c); vm_address_t oldaddr = addr; vm_size_t nsz = 0;
        p[0] = 0x36000004; p[1] = handle; p[2] = 0; p[3] = 0;   /* 0x36, 4 words: header + the real handle + 2 reserved */
        p[4] = 0x43000004; p[5] = 0xdead; p[6] = 0; p[7] = 0;   /* discard guard: 0x43 with an out-of-range texture id (already proven live) */
        p[8] = 0;                                                /* terminator */
        dtest_about(t, "inject 0x36 (real handle 0x%x) then flush (GL memType 1)", handle);
        addr = 0; r = IOConnectMapMemory(g, 1, mach_task_self(), &addr, &nsz, kIOMapAnywhere);
        dtest_result(t, r, "flush after injecting 0x36");
        dtest_note(t, "flush r=0x%08x; words after the kernel ran the buffer: %08x %08x %08x %08x %08x %08x %08x %08x %08x", (unsigned)r,
                   ((volatile unsigned *)(oldaddr + 0x1c))[0], ((volatile unsigned *)(oldaddr + 0x1c))[1], ((volatile unsigned *)(oldaddr + 0x1c))[2],
                   ((volatile unsigned *)(oldaddr + 0x1c))[3], ((volatile unsigned *)(oldaddr + 0x1c))[4], ((volatile unsigned *)(oldaddr + 0x1c))[5],
                   ((volatile unsigned *)(oldaddr + 0x1c))[6], ((volatile unsigned *)(oldaddr + 0x1c))[7], ((volatile unsigned *)(oldaddr + 0x1c))[8]);
        if (r != 0) bad++;
    }
    T3CALL(t, r, "GL set_surface(0) detaches", IOConnectMethodScalarIStructureI(g, 0, 4, 0, 0, 0, 0, 0, NULL));
    IOServiceClose(g); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_gl_inject", 0, body); }
