/* *** RESULT 2026-10-05 (#144) *** 0xb and 0xd completed cleanly (live-verified, register writes matched the static derivation below exactly). The
 * REAL crash was NOT 0x18 - it was the bind step itself (0x1c, the first flush in this file's history to carry a real, registered image id instead
 * of the 0/no-op every prior test used) - the G5 hard-hung with no panic/crash dump, needing a manual power cycle. 0x18 itself was never reached.
 * See Tests/pm4_opcode_gaps.md's 2026-10-05 section for the full writeup; filed as #144. Original rationale, still accurate for what was INTENDED: */
/* T3 test for #42 criterion 2 (DVD process_command_buffer opcodes) - the last open DVD opcode-coverage gap after idct_engine_findings.md 9x resolved
 * 0x14/0x3d/0x3e/0x46 statically. Exercises 0xb, 0xd, and 0x18 with a REAL bound texture, not the no-op path every prior live test of the bind-family
 * opcodes (0x19-0x24) actually took.
 *
 * Static trace (Sources/ATIR500DVDContext_process_command_buffer_Port.cpp) established, before this test was written:
 *   - 0xb (line 247), 0xd (line 116): each has a 2-way branch on word[2] (0=touch the self+0x104 texture array, nonzero=use context fields only).
 *     BOTH real VA-driver emitters (Userspace/.../part_001.c:4266 and :1032/:1142) always pass word[2]=1 (nonzero) - real software never takes the
 *     texture-array branch for these two opcodes. This test matches real usage exactly: word[2]=1, so the texture array is never touched - included
 *     here for completeness/coverage, not because it was previously unsafe.
 *   - 0x18 (line 879): unconditionally dereferences self+0x104 at TWO slots, word[1] and word[2], via the same map_transfer_to_GART linked-list
 *     pattern 0x12's composite uses for its own transfer buffer - then (line 920 onward) writes the SAME 0x1150/0x1393=10/0x138a register family
 *     as the #142 composite group. Unlike 0x14/0x3d/0x3e/0x46 (idct_engine_findings.md 9x), this is NOT one of #142's MC-prediction siblings - it's
 *     reached from a structurally separate part of the dispatcher (texture-array family, not the MC-composite cluster at lines 337-1729), and its
 *     real emitter (part_001.c:4991, only call site part_001.c:1104) is invoked for texture/surface conversion, not motion-compensation. Real args:
 *     word[1] = (char)*mb_byte + 4 (a small per-call slot, 4-7 by the observed +4 bias), word[2] = 3 (a fixed constant slot). Genuinely unexercised,
 *     not proven safe OR unsafe by any prior static or live work - this is the one real open question this test answers.
 *   - 0x43/0x44 (lines 1444/1639, shared tail at joined_r0x000381c4): same register family as 0x18, but ALREADY proven safe live - 0x43 completed
 *     cleanly via the real GetFrame flow (idct_engine_findings.md 9l, Tools/userspace/va_capture/ava_drive.c --getframe 2). 0x44 is its RGB-format
 *     sibling (same emitter shape, word[2] always the fixed constant 0x11/slot 17, selected instead of 0x43 purely by requested pixel fourcc - see
 *     ava_drive.c's mode comment) - best exercised by re-running that SAME proven flow with --getframe 16/32/64 instead of a synthetic injection
 *     here (higher fidelity: real client code path, not hand-assembled words). Left to a separate ava_drive run, not duplicated in this file.
 *
 * Preconditions for 0x18: binds two fresh declare_image'd textures into slots 3 and 4 using the ALREADY-PROVEN bind mechanism (opcodes 0x19-0x24,
 * LAB_00037620 in the source - slot = opcode - 0x19) - but with the REAL imgId from declare_image, not 0. Every prior live test of this opcode
 * family (t3_dvd_inject.c, t3_dvd_probe_1d.c) used a generic zero-filled record, so word[1] (the image id to bind) was always 0 - not a registered
 * id, so the bind silently no-op'd every previous time this family was "tested". This is the first live test that performs a REAL bind.
 * Issue #100 protocol #87: crashes are an acceptable, expected cost of this investigation (standing instruction) - proceed. */
#include "t3common.h"
#include <mach/mach.h>
static kern_return_t flush_and_log(dtest_t *t, io_connect_t d, vm_address_t *addr, vm_size_t *size, unsigned op, unsigned w1, unsigned w2, unsigned w3, unsigned w4, unsigned w5) {
    volatile unsigned *p = (volatile unsigned *)(*addr + 0x1c); vm_address_t oldaddr = *addr; vm_size_t nsz = 0; unsigned j; kern_return_t r;
    unsigned words[16] = {0}; words[0] = w1; words[1] = w2; words[2] = w3; words[3] = w4; words[4] = w5;
    p[0] = (op << 24) | 16;
    for (j = 0; j < 15; j++) p[j + 1] = words[j];
    p[16] = 0;
    dtest_about(t, "inject 0x%02x (w1=0x%x w2=0x%x w3=0x%x w4=0x%x w5=0x%x) then flush", op, w1, w2, w3, w4, w5);
    *addr = 0; r = IOConnectMapMemory(d, 1, mach_task_self(), addr, &nsz, kIOMapAnywhere);
    dtest_result(t, r, "flush after injecting 0x%02x", op);
    { char line[300]; int k, o = 0;
      for (k = 0; k < 17 && o < 280; k++) o += snprintf(line + o, sizeof line - o, " %08x", ((volatile unsigned *)(oldaddr + 0x1c))[k]);
      dtest_note(t, "0x%02x: flush r=0x%08x; words after the kernel ran the buffer:%s", op, (unsigned)r, line); }
    if (nsz) *size = nsz;
    return r;
}
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0;
    vm_address_t addr = 0; vm_size_t size = 0;
    unsigned imgSlot3 = 0xffffffff, imgSlot4 = 0xffffffff;
    if (t3_surface(t, svc, &s, 4, 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD set_surface(1,0,0) binds", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD declare_image(4,4) #1 (for slot 3)", IOConnectMethodScalarIScalarO(d, 8, 3, 1, 0, 4, 4, &imgSlot3));
    bad += t3_expect(t, "declare_image #1", r, 0);
    dtest_note(t, "declare_image #1 -> r=0x%08x imgId=0x%x", (unsigned)r, imgSlot3);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD declare_image(4,4) #2 (for slot 4)", IOConnectMethodScalarIScalarO(d, 8, 3, 1, 0, 4, 4, &imgSlot4));
    bad += t3_expect(t, "declare_image #2", r, 0);
    dtest_note(t, "declare_image #2 -> r=0x%08x imgId=0x%x", (unsigned)r, imgSlot4);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "map the initial/flush command buffer (DVD memType 1)", IOConnectMapMemory(d, 1, mach_task_self(), &addr, &size, kIOMapAnywhere));
    bad += t3_expect(t, "map buffer", r, 0);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }

    /* 0xb, 0xd first: real-usage pattern (word[2]=1 -> safe branch), zero bind precondition needed */
    r = flush_and_log(t, d, &addr, &size, 0x0b, 2, 1, 0, 0, 0); if (r != 0) { bad++; dtest_note(t, "0xb failed, stopping"); goto out; }
    r = flush_and_log(t, d, &addr, &size, 0x0d, 2, 1, 1, 1, 1); if (r != 0) { bad++; dtest_note(t, "0xd failed, stopping"); goto out; }

    /* real bind: opcode 0x19+N binds word[1]'s image id into slot N (self+0x104+N*4). 0x1c -> slot 3, 0x1d -> slot 4. */
    r = flush_and_log(t, d, &addr, &size, 0x1c, imgSlot3, 0, 0, 0, 0); if (r != 0) { bad++; dtest_note(t, "0x1c (bind slot 3) failed, stopping"); goto out; }
    r = flush_and_log(t, d, &addr, &size, 0x1d, imgSlot4, 0, 0, 0, 0); if (r != 0) { bad++; dtest_note(t, "0x1d (bind slot 4) failed, stopping"); goto out; }

    /* the real open question: 0x18 with both slots genuinely bound, matching the real emitter's word[1]=slot4, word[2]=slot3(constant) shape */
    r = flush_and_log(t, d, &addr, &size, 0x18, 4, 3, 0, 0, 0); if (r != 0) { bad++; dtest_note(t, "0x18 failed"); goto out; }
out:
    T3CALL(t, r, "DVD set_surface(0) detaches", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 0, 0, 0, NULL));
    IOServiceClose(d); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_bind_and_use", 0, body); }
