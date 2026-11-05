/* *** 2026-11-05 (#144 root cause) *** declare_image's scalar args are (unused, ADDRESS, LENGTH), not (width, height): this test declared two images at user address 4, and it passed the returned
 * "image id" (the user address of the client-shared record, 0xc000/0xc040 = chunk base + handle*0x40) as the bind handle, but the 0x19..0x24 bind opcodes take the table HANDLE (the word stored
 * at that address; handle < sharedAllocator->count). The bind was therefore rejected (endStream, flush returns 0, record left unchanged), slots 3/4 stayed NULL and 0x18 dereferenced NULL+4 (DAR 4):
 * a kernel PANIC, not a lockup (Tiger waits on the panic screen; system.log goes quiet). Reproduced live on the rebuilt kext 2026-11-05 (panic PC in process_command_buffer 0x18, see #144).
 * Fixed here: real page-aligned buffers are declared and the handle is derived from the returned address ((id & 0xfff) >> 6, valid for the first chunk). The kernel now ends such a stream instead. */
/* *** RESULT 2026-10-05 (#144), 3 live attempts *** 0xb and 0xd completed cleanly every time (live-verified, register writes matched the static
 * derivation below exactly). Attempt 1: the bind step (0x1c) hung, 0x18 never reached. Attempts 2 and 3 (after the declare_image fix carried no
 * change - same args each time): 0x1c AND 0x1d both completed cleanly, and the hang moved to 0x18 instead - reproduced 2-for-2. 0x18 is the real,
 * repeatable trigger; attempt 1's 0x1c death did not reproduce and is unexplained (possibly a one-off). GAProbe (idct_engine_findings.md 9z) caught
 * attempt 3 live: NOT a partial GPU wedge like #142 - a TOTAL kernel lockup, system.log completely silent (even GAProbe's own independent timer)
 * from the moment of the hang until the next boot, 41 minutes later. No further register-level diagnosis possible via this method - see 9z for the
 * only remaining escalation path (physical NMI break-in, not attempted). See Tests/pm4_opcode_gaps.md's 2026-10-05 section for the full writeup;
 * filed as #144. Original rationale, still accurate for what was INTENDED: */
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
static int g_rec_unchanged;   /* set by flush_and_log: the kernel left the injected record untouched (a bind that did not land leaves its record as written) */
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
    g_rec_unchanged = (((volatile unsigned *)(oldaddr + 0x1c))[0] == ((op << 24) | 16));
    if (nsz) *size = nsz;
    return r;
}
static const char *body(dtest_t *t, io_service_t svc) {
    io_connect_t s = IO_OBJECT_NULL, d = IO_OBJECT_NULL; kern_return_t r; int bad = 0;
    vm_address_t addr = 0; vm_size_t size = 0;
    unsigned imgSlot3 = 0xffffffff, imgSlot4 = 0xffffffff; vm_address_t img3 = 0, img4 = 0;
    int forced = getenv("FORCE_UNBOUND_0x18") != NULL;   /* #144 negative check: pass the declare_image ids as bind handles (the original test mistake) so the binds are rejected and 0x18 names empty slots: the fixed kernel must end the stream, the unfixed one panics */
    int prep = getenv("PREP_BUFFERS") != NULL;   /* #144 differential: give the context real VRAM for slot 16 (the 0x18 render target) the way the proven GetFrame flow does */
    const char *stop = getenv("STOP_AFTER");   /* bisection knob (#150/#151 wedge check): prep | maps | 0xb | 0xb0xd | bind | 0x18 | slot17 | 0x43 | 0x44 - end the injected sequence after that step, then detach and close as usual */
#define STOP_IF(name) if (stop && !strcmp(stop, name)) { dtest_note(t, "STOP_AFTER=%s: ending the sequence here", name); goto out; }
    if (t3_surface(t, svc, &s, prep ? 64 : 4, prep ? 48 : 4) != KERN_SUCCESS) return "DIVERGENCE";
    T3CALL(t, r, "open DVD connection", open_user_client(svc, CLIENT_TYPE_DVD, &d));
    if (r != KERN_SUCCESS) { IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD set_surface(1,0,0) binds", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 1, 0, 0, NULL)); bad += t3_expect(t, "bind", r, 0);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    if (prep) {
        IOByteCount osz = 0; UInt32 out[64];
        T3CALL(t, r, "DVD setup_buffers(0,64,48,0,0x27c00)", IOConnectMethodScalarIScalarO(d, 21, 5, 0, 0, 64, 48, 0, 0x27c00)); bad += t3_expect(t, "setup_buffers #1", r, 0);
        if (r == 0) { T3CALL(t, r, "DVD setup_buffers(0,64,48,0,0x37c00)", IOConnectMethodScalarIScalarO(d, 21, 5, 0, 0, 64, 48, 0, 0x37c00)); bad += t3_expect(t, "setup_buffers #2", r, 0); }
        if (r == 0) { osz = sizeof out; memset(out, 0, sizeof out); T3CALL(t, r, "DVD lock_all_buffers(0)", IOConnectMethodScalarIStructureO(d, 4, 1, &osz, 0, out)); dtest_note(t, "lock_all_buffers -> r=0x%08x outSize=%u", (unsigned)r, (unsigned)osz); }
        if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
        STOP_IF("prep")
    }
    T3CALL(t, r, "DVD declare_image(4,4) #1 (for slot 3)", (vm_allocate(mach_task_self(), &img3, 0x10000, TRUE), memset((void *)img3, 0x40, 0x10000), IOConnectMethodScalarIScalarO(d, 8, 3, 1, 0, img3, 0x10000, &imgSlot3)));
    bad += t3_expect(t, "declare_image #1", r, 0);
    dtest_note(t, "declare_image #1 -> r=0x%08x imgId=0x%x", (unsigned)r, imgSlot3);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "DVD declare_image(4,4) #2 (for slot 4)", (vm_allocate(mach_task_self(), &img4, 0x10000, TRUE), memset((void *)img4, 0x40, 0x10000), IOConnectMethodScalarIScalarO(d, 8, 3, 1, 0, img4, 0x10000, &imgSlot4)));
    bad += t3_expect(t, "declare_image #2", r, 0);
    dtest_note(t, "declare_image #2 -> r=0x%08x imgId=0x%x", (unsigned)r, imgSlot4);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }
    T3CALL(t, r, "map the initial/flush command buffer (DVD memType 1)", IOConnectMapMemory(d, 1, mach_task_self(), &addr, &size, kIOMapAnywhere));
    bad += t3_expect(t, "map buffer", r, 0);
    if (r != 0) { IOServiceClose(d); IOServiceClose(s); return "DIVERGENCE"; }

    STOP_IF("maps")
    /* 0xb, 0xd first: real-usage pattern (word[2]=1 -> safe branch), zero bind precondition needed */
    r = flush_and_log(t, d, &addr, &size, 0x0b, 2, 1, 0, 0, 0); if (r != 0) { bad++; dtest_note(t, "0xb failed, stopping"); goto out; }
    STOP_IF("0xb")
    r = flush_and_log(t, d, &addr, &size, 0x0d, 2, 1, 1, 1, 1); if (r != 0) { bad++; dtest_note(t, "0xd failed, stopping"); goto out; }
    STOP_IF("0xb0xd")

    /* real bind: opcode 0x19+N binds word[1]'s image id into slot N (self+0x104+N*4). 0x1c -> slot 3, 0x1d -> slot 4. */
    r = flush_and_log(t, d, &addr, &size, 0x1c, forced ? imgSlot3 : (imgSlot3 & 0xfff) >> 6, 0, 0, 0, 0); if (r == 0 && g_rec_unchanged && !forced) { bad++; dtest_note(t, "0x1c bind did NOT land (record unchanged): stopping before 0x18 (it would dereference the empty slot)"); goto out; } if (r != 0) { bad++; dtest_note(t, "0x1c (bind slot 3) failed, stopping"); goto out; }
    r = flush_and_log(t, d, &addr, &size, 0x1d, forced ? imgSlot4 : (imgSlot4 & 0xfff) >> 6, 0, 0, 0, 0); if (r == 0 && g_rec_unchanged && !forced) { bad++; dtest_note(t, "0x1d bind did NOT land (record unchanged): stopping before 0x18"); goto out; } if (r != 0) { bad++; dtest_note(t, "0x1d (bind slot 4) failed, stopping"); goto out; }
    STOP_IF("bind")

    /* the real open question: 0x18 with both slots genuinely bound, matching the real emitter's word[1]=slot4, word[2]=slot3(constant) shape */
    r = flush_and_log(t, d, &addr, &size, 0x18, 4, 3, 0, 0, 0); if (r != 0) { bad++; dtest_note(t, "0x18 failed"); goto out; }
    STOP_IF("0x18")
    /* #150/#151: the real emitters (VA driver ava_render_convert_frame / _yuv2, part_001.c:3697 and :3838) write word[1] = frame buffer index, word[2] = 0x11 (texture slot 17, bound with opcode 0x19+17 = 0x2a),
     * word[3] = (frame buffer attached ? 1 : 0), word[4] = a context flags word. Bind a third real buffer into slot 17, then run 0x43 and 0x44 with both word[3] values; each only emits a register-write record. */
    {   vm_address_t img17 = 0; unsigned id17 = 0xffffffff; int f;
        T3CALL(t, r, "DVD declare_image(real 64 KiB buffer) #3 (for slot 17)", (vm_allocate(mach_task_self(), &img17, 0x10000, TRUE), memset((void *)img17, 0x40, 0x10000), IOConnectMethodScalarIScalarO(d, 8, 3, 1, 0, img17, 0x10000, &id17)));
        bad += t3_expect(t, "declare_image #3", r, 0); if (r != 0) goto out;
        r = flush_and_log(t, d, &addr, &size, 0x2a, forced ? id17 : (id17 & 0xfff) >> 6, 0, 0, 0, 0); if (r == 0 && g_rec_unchanged) { bad++; dtest_note(t, "0x2a bind did NOT land: stopping"); goto out; } if (r != 0) { bad++; goto out; }
        STOP_IF("slot17")
        for (f = 0; f < 2; f++) {
            r = flush_and_log(t, d, &addr, &size, 0x43, 0, 0x11, f, 0, 0); if (r != 0) { bad++; dtest_note(t, "0x43 failed"); goto out; }
            STOP_IF("0x43")
            r = flush_and_log(t, d, &addr, &size, 0x44, 0, 0x11, f, 0, 0); if (r != 0) { bad++; dtest_note(t, "0x44 failed"); goto out; }
            STOP_IF("0x44")
        }
    }
    if (getenv("NEG_BUFIDX")) {   /* #219 negative check (rebuilt kext only: stock reads kernel memory at index*0x78): an out-of-range buffer index must end the stream, record untouched */
        r = flush_and_log(t, d, &addr, &size, 0x43, 0x7fffffff, 0x11, 0, 0, 0); if (r != 0) { bad++; dtest_note(t, "0x43 with buffer index 0x7fffffff failed"); goto out; }
        dtest_note(t, "0x43 with out-of-range buffer index: record %s", g_rec_unchanged ? "unchanged (stream ended, as designed)" : "was rewritten (UNEXPECTED)"); if (!g_rec_unchanged) bad++;
    }
out:
    T3CALL(t, r, "DVD set_surface(0) detaches", IOConnectMethodScalarIStructureI(d, 0, 3, 0, 0, 0, 0, NULL));
    IOServiceClose(d); IOServiceClose(s);
    return bad ? "DIVERGENCE" : "PASS";
}
int main(int argc, char **argv) { return dtest_main(argc, argv, "t3_dvd_bind_and_use", 0, body); }
