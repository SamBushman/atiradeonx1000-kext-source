/*
 * ATIRadeonX1000.h
 *
 * The base hardware-access class. Every context class (GL/2D/DVD/Surface)
 * holds a pointer to a shared instance of this class and reaches all real
 * MMIO/ring-buffer/fence machinery through it. Real class name confirmed
 * via decompiled method signatures throughout the project
 * (`ATIRadeonX1000::submit_buffer`, `ATIRadeonX1000::submit_idct_buffer_consumed`,
 * `ATIRadeonX1000::waitForRetiredTimeStamp`, etc.)
 *
 * Confidence: CONFIRMED unless marked otherwise. See ../README.md.
 */

#ifndef ATIRADEONX1000_H
#define ATIRADEONX1000_H

#include <IOKit/IOService.h>
#include "ATIRadeonX1000Types.h"

class IOWorkLoop;
class IOMemoryDescriptor;

class ATIRadeonX1000 {
public:
    /*
     * Real, confirmed field offsets (from this base pointer, as reached
     * via each context class's own "this+N" accelerator pointer - e.g.
     * ATIR500GLContext at +200/0xc8, ATIR5002DContext at +0x94,
     * ATIR500DVDContext at +0x8c). This project never independently
     * decompiled ATIRadeonX1000's own constructor/init to get a from-zero
     * field list - every offset below was learned indirectly, through a
     * context class dereferencing it. Gaps are real (not every byte in
     * between was ever touched by decompiled code this project read).
     */
    UInt8   _pad_before_lock[0x840];
    void *  commandLock;              /* +0x840, CONFIRMED: passed to lock/unlock helper pairs (FUN_xxxx(this+0x840)) bracketing nearly every external method body across all four context classes - a real recursive/simple mutex */
    UInt8   _pad_0x844[0x854 - 0x844];
    UInt32  idctSubmitBaseCounter;    /* +0x854, CONFIRMED: read at the top of doIDCT, compared against submit_idct_buffer_consumed's return value */
    UInt8   _pad_0x858[0x860 - 0x858];
    void *  mmioBase;                 /* +0x860, CONFIRMED: the real MMIO base pointer used by read_regs/write_regs (masked with REGISTER_ACCESS_WINDOW_MASK before use) */
    UInt8   _pad_0x864[0x80 - 0];     /* placeholder spacer - see note below */
    /*
     * NOTE on field ordering: +0x80 (device-active flag) is CONFIRMED to
     * exist and be checked before nearly every hardware operation in every
     * context class (`*(char*)(accelBase+0x80) == '\0'` => kIOReturnNotOpen-
     * style error), but this project never established whether +0x80 comes
     * before or after +0x840/+0x854/+0x860 in the real struct - the offsets
     * were each learned independently from different call sites, not from
     * one single field-by-field decompile of this class's layout. Modeled
     * honestly below as a separately-named field rather than silently
     * picking an order the analysis never actually confirmed.
     */
    UInt8   _unordered_placeholder[0x8b0];
    UInt8   deviceActiveFlag;         /* CONFIRMED to exist as a byte gate at real offset +0x80 from this object's base - see note above about ordering uncertainty relative to the fields already listed */
    UInt8   _pad_after_active[0x8b7];
    void *  clientMemoryDescriptorType0; /* +0x8d8, CONFIRMED: the real IOMemoryDescriptor returned by every context's clientMemoryForType(0, ...) */
    UInt8   _pad_0x8dc[0x918 - 0x8dc];
    UInt32  mainRingCursor;           /* +0x918, INFERRED offset (this project confirmed the field's existence and role - the real write-cursor submit_ring_data advances - via the same +0x1600-relative-to-userspace reasoning as the client-side cursor fields, not from a from-zero decompile of this exact byte) */
    UInt32  idctRingCursor;           /* +0x930, CONFIRMED distinct from mainRingCursor: submit_idct_buffer_consumed writes IDCT_RING_WPTR using a value derived from this field, not this+0x918 */
    UInt8   _pad_0x934[0x5a4 - 0x934]; /* UNKNOWN: large unverified gap */

    /*
     * GART/data-buffer pool bookkeeping - CONFIRMED from
     * IOATIR500Accelerator's own freeToAllocGART/freeWaitToAllocGART and
     * every context's get_data_buffer/reclaim_resources (they all reach
     * these same fields through their own accelerator pointer).
     */
    UInt32  cachedBufferSizeThreshold;   /* +0x5c8, CONFIRMED: reclaim_resources sets this to 0x20000 on cleanup */
    UInt32  cachedBufferSizeThresholdB;  /* +0x5d8, CONFIRMED: reclaim_resources sets a second threshold to 0x10000; get_data_buffer compares/ratchets this one up */
    void *  freeBufferListHead;          /* +0x5cc, CONFIRMED: real singly-linked free-list head, walked by freeToAllocGART's transfer-buffer ring sweep */
    void *  freeBufferListTail;          /* +0x5d0, CONFIRMED */
    UInt32  freeBufferListCount;         /* +0x5d4, CONFIRMED: compared against a real cap of 16 entries in reclaim_resources */
    UInt8   _pad_0x5dc[0x600 - 0x5dc];
    void *  dirtyTextureListHead;        /* +0x600, CONFIRMED: real doubly-linked list head for "textures with a pending dirty flush" (get_data_buffer/purge_texture insert here) */
    UInt8   _pad_0x604[0x69c - 0x604];
    void *  secondDirtyListHead;         /* +0x69c, CONFIRMED: a second, distinct doubly-linked list head with the identical insert pattern - real purpose (a second dirty class, e.g. read-vs-write) not established */
    UInt8   _pad_0x6a0[0x70c - 0x6a0];
    UInt32  dataBufferByteAccumulator;   /* +0x70c, CONFIRMED: real running total accumulated in get_data_buffer, used to decide when to grow the cache threshold */

    /*
     * The two real, software-only IOInterruptEventSource callbacks this
     * kext registers - CONFIRMED to be pure deferred-work triggers, not
     * hardware interrupt handlers (see stage9-gl-remaining-methods-...md).
     * Declared here as real static method pointers matching their
     * confirmed signature.
     */
    static void garbage_collector(OSObject *owner, class IOInterruptEventSource *source, int count);
    static void gart_collector(OSObject *owner, class IOInterruptEventSource *source, int count);

    /* ---- Real, confirmed methods ---- */

    /*
     * submit_ring_data - CONFIRMED. Advances CP_RB_WPTR using the real
     * bit-packing formula this project found and re-confirmed identically
     * in submit_idct_buffer_consumed:
     *     mmio[CP_RB_WPTR] = (wptr << 24) | ((wptr & 0x700) << 8);
     * Exact parameter list not re-derived for this reconstruction (the
     * original decompile was read for its MMIO-write shape, not transcribed
     * argument-by-argument) - modeled with a plausible signature.
     */
    void submit_ring_data(UInt32 wptr);

    /*
     * submit_buffer / submit_buffer_retired - CONFIRMED to exist and to be
     * the real indirect-buffer submission path every context's deferred/
     * "flush if nearly full" logic calls (distinct from submit_ring_data's
     * direct-ring path). Exact signature INFERRED from the many real call
     * sites this project read (e.g. ATIR5002DContext::process_command_buffer's
     * `ATIRadeonX1000::submit_buffer(accel, ptr1, ptr2, count)` shape).
     */
    IOReturn submit_buffer(UInt32 *bufferStart, UInt32 bufferOffsetOrEnd, UInt32 dwordCount);

    /*
     * submit_idct_buffer_consumed - CONFIRMED real name and behavior
     * (stage5-iouserclient-external-method-api-complete.md's doIDCT trace).
     * Writes the 8 real (register,value) coefficient-address pairs plus
     * six IDCT_TRIGGER_PULSE strobes directly into the main ring, then
     * advances IDCT_RING_WPTR via idctRingCursor. Returns the new
     * completion tag.
     */
    UInt32 submit_idct_buffer_consumed(UInt32 *ringPtr, UInt32 ringOffset, sATIDVDIDCTInfo *info);

    /*
     * waitForRetiredTimeStamp / waitForTimeStampNoLock - CONFIRMED to be
     * the real kernel-side fence-wait pair every context's wait_for_stamp/
     * wait_image/wait_for_stamps external method ultimately calls.
     * waitForConsumedIDCTTimeStamp - CONFIRMED distinct IDCT-specific
     * counterpart (stage4-real-hardware-idct-engine-found.md).
     */
    IOReturn waitForRetiredTimeStamp(UInt32 tag);
    IOReturn waitForTimeStampNoLock(UInt32 tag);
    IOReturn waitForConsumedIDCTTimeStamp(UInt32 tag);

    /*
     * External-method selector 9 on the GL context, CONFIRMED to be
     * exactly wait_for_stamp - see ATIR500GLContext.h.
     */
};

#endif /* ATIRADEONX1000_H */
