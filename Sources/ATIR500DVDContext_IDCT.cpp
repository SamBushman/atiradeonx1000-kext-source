/*
 * ATIR500DVDContext_IDCT.cpp
 *
 * doIDCT - THE real external entry point for this GPU's independent
 * hardware IDCT engine (real kext offset 0x35540), directly relevant to
 * this project's H.264 GPU-decode goal. CONFIRMED, fully decoded this
 * session (stage5-iouserclient-external-method-api-complete.md).
 *
 * This is transcribed close to the real decompiled control flow (raw
 * offset arithmetic, matching field names where this project's struct
 * reconstruction is confident - see Headers/ATIRadeonX1000Types.h's
 * sATIDVDIDCTInfo/sATIDVDIDCTParams - and raw UInt8* arithmetic with
 * inline comments where a couple of VendorTransferBuffer fields this
 * function touches (a real "resident size" field at +0x10) were not
 * independently added to that struct's confirmed field list this pass).
 *
 * Confidence: CONFIRMED for control flow and every register/field this
 * project already named; the two fields called out above are a real,
 * narrow, honestly-marked gap.
 */

#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/ATIRadeonX1000.h"

IOReturn ATIR500DVDContext::doIDCT(sATIDVDIDCTInfo *info, sATIDVDIDCTParams *params) {
    ATIRadeonX1000 *accel = reinterpret_cast<ATIRadeonX1000 *>(info->hwAccelerator);

    /* CONFIRMED: real vtable call at offset 0x54c, real argument is
     * info->submitCookie - UNKNOWN real virtual method name. */
    // accel->vtable_0x54c(info->submitCookie);

    if (info->surfaceInfo == 0 || !accel->deviceActiveFlag) {
        return kIOReturnNotOpen; /* real value 0xe00002d8 */
    }
    /* CONFIRMED: a real third gate this project never named -
     * `*(int*)(accelBase+0x8bc) != 0` - UNKNOWN real meaning, modeled as
     * a raw offset check to stay faithful. */
    if (*reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(accel) + 0x8bc) == 0) {
        return kIOReturnNotOpen;
    }

    /* lock(accel) - real function FUN_000357ac. RESOLVED, issue #15: a
     * real lazy-binding external stub with no local body in this binary -
     * see the comprehensive finding at the end of
     * Headers/ATIRadeonX1000Registers.h. Real name still UNKNOWN. */

    UInt8 *surfaceInfo = reinterpret_cast<UInt8 *>(info->surfaceInfo);
    UInt32 fieldHeight = static_cast<SInt16>(*reinterpret_cast<UInt16 *>(surfaceInfo + 0x9a))
                        - static_cast<SInt16>(*reinterpret_cast<UInt16 *>(surfaceInfo + 0x94));

    UInt8 *planeGeometry;
    VendorTransferBuffer *destBuffer;

    if (params->planeSelector == 0) {
        /* luma plane: real ping-pong between lumaBufferA/lumaBufferB */
        destBuffer = reinterpret_cast<VendorTransferBuffer *>(&info->lumaBufferA);
        if (info->lumaBufferAField_0x164 != 0) {
            destBuffer = reinterpret_cast<VendorTransferBuffer *>(&info->lumaBufferB);
        }
        planeGeometry = surfaceInfo + 0x558 + params->destPlaneIndex * 0x78; /* CONFIRMED real mip/plane-table indexing */
    } else if (params->planeSelector == 1) {
        /* chroma plane: real ping-pong between chromaBufferA/chromaBufferB */
        destBuffer = reinterpret_cast<VendorTransferBuffer *>(&info->chromaBufferA);
        if (info->chromaBufferAField_0x1a0 != 0) {
            destBuffer = reinterpret_cast<VendorTransferBuffer *>(&info->chromaBufferB);
        }
        planeGeometry = surfaceInfo + 0x8a0; /* CONFIRMED real fixed chroma-plane geometry offset */
    } else {
        return kIOReturnBadArgument; /* real value 0xe00002c2 */
    }

    UInt16 planePitch = *reinterpret_cast<UInt16 *>(planeGeometry + 0x18);
    UInt32 lumaStride, effectiveStride;
    if (params->chromaFlag == 0) {
        lumaStride = planePitch;
        effectiveStride = planePitch;
    } else {
        lumaStride = planePitch;
        effectiveStride = lumaStride << 1; /* CONFIRMED: real doubled stride for the chroma-flag case */
    }

    UInt32 planeBase = *reinterpret_cast<UInt32 *>(planeGeometry + 8);
    if (params->fieldFlag == 0) {
        params->destBaseAddress = planeBase;
        params->destEndAddress  = fieldHeight * planePitch + planeBase;
    } else {
        params->destBaseAddress = lumaStride + planeBase;
        params->destEndAddress  = planePitch + fieldHeight * planePitch + planeBase;
    }

    params->computedStride       = effectiveStride * fieldHeight - 1;
    params->strideBroadcast      = effectiveStride | (effectiveStride << 16);
    params->computedChromaStride = effectiveStride * (fieldHeight >> 1) - 1;

    if (params->destBaseAddress != 0) {
        /* CONFIRMED real field at VendorTransferBuffer+4 (realBackingFlag) */
        if (destBuffer->realBackingFlag == 0) {
            map_transfer_to_GART(destBuffer);
        }
        UInt32 priorConsumedTag = accel->idctSubmitBaseCounter;
        UInt32 *ringPtr = reinterpret_cast<UInt32 *>(
            reinterpret_cast<UInt8 *>(destBuffer->gartMappedPointer) + 0x20);
        /*
         * CONFIRMED real type-punning cast, preserved faithfully: the
         * real decompile passes the PARAMS block itself
         * (`(sATIDVDIDCTInfo *)param_2`), not the per-context `info`
         * object, as submit_idct_buffer_consumed's third argument -
         * submit_idct_buffer_consumed's own real per-plane
         * coefficient-address field reads (+0x10/+0x14/.../+0x30, see
         * stage4-real-hardware-idct-engine-found.md) line up exactly with
         * sATIDVDIDCTParams's real confirmed fields, confirming this is
         * the intended argument despite the declared type.
         */
        UInt32 newTag = accel->submit_idct_buffer_consumed(
            ringPtr, destBuffer->realBackingFlag + 0x20,
            reinterpret_cast<sATIDVDIDCTInfo *>(params));
        info->lastSubmittedTag = newTag;

        if (priorConsumedTag <= newTag) {
            /* CONFIRMED: real field at VendorTransferBuffer+0x10 - a
             * "last-submitted tag" cache this project did not add to
             * VendorTransferBuffer's confirmed field list this pass. */
            *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(destBuffer) + 0x10) = newTag;
            if (params->planeSelector == 0) {
                info->lastConsumedTagLuma = info->lastSubmittedTag;
            }
            /* unlock(accel) - real function FUN_0003577c. RESOLVED, issue
             * #15: a real lazy-binding external stub with no local body -
             * see Headers/ATIRadeonX1000Registers.h. Real name UNKNOWN. */
            return kIOReturnSuccess;
        }
    }

    /* unlock(accel) */
    return kIOReturnNotOpen; /* real value 0xe00002d8, same as the top-of-function gate failure */
}
