/*
 * IOAccelWireLayouts.h - byte layouts of the structures that cross the user/kernel boundary in the external methods (issue #100 criterion 6).
 *
 * EVIDENCE, two independent sources that agree:
 *  (a) Apple's own PUBLIC headers shipped with Tiger (G5: /System/Library/Frameworks/IOKit.framework/Versions/A/Headers/graphics/IOAccelTypes.h,
 *      IOAccelSurfaceConnect.h; also in /Developer/SDKs/MacOSX10.3.9.sdk): IOAccelBounds, IOAccelSize, IOAccelSurfaceReadData, IOAccelSurfaceScaling,
 *      IOAccelDeviceRegion, eIOAccelSurfaceShapeBits, eIOAccelSurfaceModeBits, the kIOAccelSurface* method indices.
 *  (b) the offsets the SHIPPED kext's own bodies read (cited per struct below), so each layout is checked against the binary, not only against the header.
 * The names carry a `_Wire` suffix so this header can be included next to Apple's own (the kext already includes <IOKit/graphics/IOAccelTypes.h>).
 * Sizes are for 32-bit PowerPC (long == 4). The compile-time checks at the bottom fail the build if a layout drifts.
 *
 * NOT public (no Apple header): sIOGLNewTextureData / sIOGLNewTextureReturnData / sIOGLContextReadBufferData / IOAccelSurfaceData - their layouts stay the
 * kernel-evidence ones in ATIRadeonX1000Types.h (leading fields only), listed in the #100 notes.
 */
#ifndef IOACCEL_WIRE_LAYOUTS_H
#define IOACCEL_WIRE_LAYOUTS_H

typedef struct { short x, y, w, h; } IOAccelBounds_Wire;                      /* 8 bytes */
typedef struct { short w, h; } IOAccelSize_Wire;                              /* 4 bytes */

/* IOAccelSurfaceReadData (Apple): `long x, y, w, h; void *client_addr; unsigned long client_row_bytes;` = 24 bytes.
 * Kernel evidence: IOATIR500Surface::surface_read (0x14a30) loads +0,+4,+8,+0xc (x,y,w,h), +0x10 (client address, passed to IOMemoryDescriptor::withAddress)
 * and +0x14 (row bytes, the `iVar10` multiplier). */
typedef struct { int x, y, w, h; unsigned int client_addr; unsigned int client_row_bytes; } IOAccelSurfaceReadData_Wire;

/* IOAccelSurfaceScaling (Apple): { IOAccelBounds buffer; IOAccelSize source; UInt32 reserved[8]; } = 0x2c bytes, the size set_scale requires
 * (IOATIR500Surface::set_scale rejects any structure size other than 0 or 0x2c).
 * Kernel evidence: IOATIR500Surface::set_scaling (copies +0,+2 -> +0xbdc,+0xbde; +4,+6 -> +0xbd4,+0xbd6; +8,+0xa -> +0xbe0,+0xbe2: buffer.x/y, buffer.w/h, source.w/h),
 * and IOATIR500GLContext::scale_surface (0x9230) builds it on the stack from three scalars: buffer = {0, 0, p2, p3}, source = {p2, p3}
 * (so GL scale_surface(flags, w, h) with w, h equal to the surface size is an identity scale). */
typedef struct { IOAccelBounds_Wire buffer; IOAccelSize_Wire source; unsigned int reserved[8]; } IOAccelSurfaceScaling_Wire;

/* IOAccelDeviceRegion (Apple): { UInt32 num_rects; IOAccelBounds bounds; IOAccelBounds rect[]; }, size = 12 + 8 * num_rects.
 * Kernel evidence: set_shape_backing_length_ext (0x152d0) requires `structSize == num_rects * 8 + 0xc` (or 0 = compute it), reads bounds.w/h at +8/+0xa (SInt16, a
 * negative value -> Error 0xe00002bc, zero -> replaced by 1), and copies rect[i].w/h from +0x10/+0x12 + 8*i. The 20-byte region used by every live test is
 * num_rects = 1, bounds = {0,0,W,H}, rect[0] = {0,0,W,H}. */
typedef struct { unsigned int num_rects; IOAccelBounds_Wire bounds; } IOAccelDeviceRegionHead_Wire;   /* + num_rects * IOAccelBounds_Wire */
#define IOACCEL_WIRE_SIZEOF_DEVICE_REGION(n) (sizeof(IOAccelDeviceRegionHead_Wire) + (n) * sizeof(IOAccelBounds_Wire))

/* eIOAccelSurfaceShapeBits (Apple), with the shipped-kext behaviour of each bit seen in set_shape_backing_length_ext:
 *  0x01 NonBlocking (self+0xbef), 0x02 NonSimple, 0x04 IdentityScale (clears the +0xbec "scaled" flag), 0x08 FrameSync, 0x10 BeamSync (sets +0xbed),
 *  0x20 StaleBacking (the backing stamp is stored as stamp-1), 0x40 Assembly, 0x80 WaitEnabled (IOLockSleep until the accelerator is up: +0x80 != 0). */

/* eIOAccelSurfaceModeBits: 0x20 = Windowed: the fast set_id_mode path (no per-id record re-allocation) that every live Surface set-up uses. */

#define IOACCEL_WIRE_ASSERT(name, cond) typedef char ioaccel_wire_assert_##name[(cond) ? 1 : -1]
IOACCEL_WIRE_ASSERT(bounds_size, sizeof(IOAccelBounds_Wire) == 8);
IOACCEL_WIRE_ASSERT(size_size, sizeof(IOAccelSize_Wire) == 4);
IOACCEL_WIRE_ASSERT(readdata_size, sizeof(IOAccelSurfaceReadData_Wire) == 0x18);
IOACCEL_WIRE_ASSERT(scaling_size, sizeof(IOAccelSurfaceScaling_Wire) == 0x2c);
IOACCEL_WIRE_ASSERT(region_head_size, sizeof(IOAccelDeviceRegionHead_Wire) == 12);
IOACCEL_WIRE_ASSERT(region_one_rect, IOACCEL_WIRE_SIZEOF_DEVICE_REGION(1) == 20);
#endif
