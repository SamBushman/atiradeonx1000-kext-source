/*
 * ATIR500Surface_OverlayScaler.cpp
 *
 * RESOLVED (ledger pass): the overlay-scaler family of ATIR500Surface that had no body in the rebuild, transcribed
 * from the shipped kext (real addrs in parentheses). Most of it is dead code in the shipped driver (nothing in the
 * kext calls the overlay path any more, see ATIR500Surface_Overlay.cpp) but it is real code:
 *   setup_overlay_reg (0x391f0), set_gamma_coefficient (0x398d0), get_surface_info (0x398e0),
 *   query_BIOS_for_bandwidth_info (0x39f20), blast_key_color (0x3a6a0), debug_read_reg_dump (0x3a6b0),
 *   debug_reg_dump (0x3a6c0), move_overlay_xy (0x3a790): empty bodies
 *   filter_init (0x39200)  real_to_hex (0x393a0)  set_linear_transform (0x396b0)  filter_setup (0x398f0)
 *   calc_h_inc_step_by (0x39ab0)  get_surf_desc_regs (0x39f30)  calc_h_scaler_blank (0x3a410)  bad_panel (0x3a710)
 *
 * The floating-point code follows the shipped arithmetic: single-precision operations where the shipped code uses
 * fmuls/fdivs/fadds and double where it uses fmul/fdiv/fmadd, with the magic-number int/uint-to-double conversions
 * written as ordinary casts. Darwin PPC passes float arguments in FPRs but reserves their GPR slots, which is why
 * the integer parameters of filter_init/calc_h_scaler_blank sit in higher registers than the parameter list suggests.
 * float->integer conversions that the shipped code guards with a 2^31 compare are written with F2U.
 */

#include "../Headers/ATIR500Surface.h"
#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/ATIR500SurfaceOverlayTables.h"

namespace {
inline UInt32 &U32At(void *base, int offset) { return *reinterpret_cast<UInt32 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt16 &U16At(void *base, int offset) { return *reinterpret_cast<UInt16 *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline float  &F32At(void *base, int offset) { return *reinterpret_cast<float *>(reinterpret_cast<UInt8 *>(base) + offset); }
inline UInt8   B(const UInt32 *table, int byteOffset) { return reinterpret_cast<const UInt8 *>(table)[byteOffset]; }
inline float   F(const UInt32 *table, int wordIndex) { return reinterpret_cast<const float *>(table)[wordIndex]; }
inline double  UD(UInt32 v) { return static_cast<double>(v); }
inline double  SD(SInt32 v) { return static_cast<double>(v); }

/* the shipped float->unsigned idiom: values >= 2^31 are converted after subtracting 2^31 */
inline UInt32 F2U(double v) {
    if (v >= 2147483648.0) {
        return static_cast<UInt32>(static_cast<SInt32>(v - 2147483648.0)) + 0x80000000u;
    }
    return static_cast<UInt32>(static_cast<SInt32>(v));
}
} // namespace

void ATIR500Surface::setup_overlay_reg(OverlaySurfaceInfo *, OverlayBandwidthInfo *, OverlayRegisters *) {}
void ATIR500Surface::set_gamma_coefficient(OverlayRegisters *) {}
void ATIR500Surface::get_surface_info(UInt32, OverlaySurfaceInfo *, OverlayBandwidthInfo *) {}
void ATIR500Surface::query_BIOS_for_bandwidth_info(OverlayBandwidthInfo *) {}
void ATIR500Surface::blast_key_color(IOAccelBounds *, UInt32) {}
void ATIR500Surface::debug_read_reg_dump(void) {}
void ATIR500Surface::debug_reg_dump(OverlayRegisters *) {}
void ATIR500Surface::move_overlay_xy(void) {}

/* Resolves the tap position of scaler output `n`: outIndex = m + (i - m/2 (+1 for even m)) - divisor * floor(a / divisor),
 * outFraction = the fractional part of the sample position (with a half-pixel offset unless flag is set). */
void ATIR500Surface::filter_init(float a, float b, UInt32 divisor, UInt32 flag, UInt32 taps, UInt32 *outIndex, float *outFraction) {
    float quotient = a / static_cast<float>(divisor);
    UInt32 whole = F2U(static_cast<double>(quotient));
    UInt32 product = divisor * whole;
    float t;
    if (flag == 0) {
        t = static_cast<float>((static_cast<double>(b) * 0.5 + static_cast<double>(a)) - 0.5);
    } else {
        t = static_cast<float>(static_cast<double>(b) * 0.5 + static_cast<double>(a));
    }
    t = t + 0.015625f;
    SInt32 floorT = (t < 0.0f) ? static_cast<SInt32>(t - 1.0f) : static_cast<SInt32>(t);
    *outFraction = t - static_cast<float>(floorT);
    SInt32 base;
    if ((taps & 1) == 0) {
        base = floorT - static_cast<SInt32>(taps >> 1) + 1;
    } else {
        base = floorT - static_cast<SInt32>(taps >> 1);
    }
    *outIndex = taps + (static_cast<UInt32>(base) - product);
}

/* Packs `value` into the fixed-point register format selected by `mode` (0: 4.11 signed with 3 integer bits scaled
 * by 2048/10000, 1: 2.1 with a 1-bit fraction). */
UInt32 ATIR500Surface::real_to_hex(UInt32 mode, float value) {
    UInt32 signBit = 0;
    float addend = 0.0f, mask = 0.0f;
    SInt32 signShift = 0, intShift = 0;
    if (mode == 0) {
        signShift = 3 + 0xb;
        intShift = 0xb;
        addend = 8.0f;
        mask = 2048.0f;
        if (value < 0.0f) {
            signBit = 1u << signShift;
            value = value + addend;
        }
    } else if (mode == 1) {
        signShift = 0xb + 1;
        intShift = 1;
        addend = 2048.0f;
        mask = 2.0f;
        if (value < 0.0f) {
            signBit = 1u << signShift;
            value = value + addend;
        }
    }
    SInt32 whole = static_cast<SInt32>(F2U(static_cast<double>(value)));
    float scaledFraction = static_cast<float>(static_cast<double>(value) - SD(whole)) * 10000.0f;
    UInt32 fraction;
    if (mode == 0) {
        double rounded = static_cast<double>(scaledFraction) + 0.5;
        SInt32 units = static_cast<SInt32>(F2U(rounded));
        fraction = F2U((UD(static_cast<UInt32>(units)) * 2048.0) / 10000.0);
    } else {
        fraction = 0;
        if (mode == 1) {
            double rounded = static_cast<double>(scaledFraction) + 0.5;
            fraction = F2U(rounded);
            SInt32 limit = static_cast<SInt32>(F2U(static_cast<double>(mask)));
            fraction = fraction & static_cast<UInt32>(limit - 1);
        }
    }
    return fraction | signBit | (static_cast<UInt32>(whole) << intShift);
}

void ATIR500Surface::set_linear_transform(int matrixIndex, OverlayPictureControl *control, OverlayRegisters *regs) {
    const double *co = &CO[matrixIndex];
    double c0 = co[0];
    double gain = static_cast<double>(F32At(control, 0));
    double f31 = static_cast<double>(F32At(control, 4));
    double f13 = static_cast<double>(F32At(control, 0xc));
    double zero = 0.0;
    double base = gain * c0;                              /* f29 */
    double t1 = c0 - co[4] * zero;                        /* fnmsub f28 */
    double t2 = co[6] * zero + co[8];                     /* fmadd  f26 */
    double t3 = co[10] * zero + co[12];                   /* fmadd  f25 */
    double t4 = c0 * zero + co[4];                        /* fmadd  f27 */
    double t5 = co[6] - co[8] * zero;                     /* fnmsub f30 */
    double t6 = co[10] - co[12] * zero;                   /* fnmsub f11 */
    double f13m = (base * f13) * 1023.0;
    float fBase = static_cast<float>(base);
    float a28 = static_cast<float>(f31 * t1);
    float a26 = static_cast<float>(f31 * t2);
    float a27 = static_cast<float>(f31 * t4);
    float a25 = static_cast<float>(f31 * t3);
    float a13 = static_cast<float>(f13m);
    float a30 = static_cast<float>(f31 * t5);
    float a31 = static_cast<float>(f31 * t6);
    float bias = fBase * -64.0f + a13;                    /* fmadds f24 */
    float sum28 = a28 + a27;

    UInt8 *r = reinterpret_cast<UInt8 *>(regs);
    U32At(r, 0x1b0) = real_to_hex(0, a28);
    UInt32 shared = real_to_hex(0, fBase);
    U32At(r, 0x1b4) = shared;
    U32At(r, 0x1b8) = real_to_hex(1, sum28 * -512.0f + bias);
    U32At(r, 0x1bc) = real_to_hex(0, a27);
    float sum30 = a30 + a26;
    U32At(r, 0x1c0) = real_to_hex(0, a30);
    U32At(r, 0x1c4) = shared;
    U32At(r, 0x1c8) = real_to_hex(1, sum30 * -512.0f + bias);
    U32At(r, 0x1cc) = real_to_hex(0, a26);
    float sum31 = a31 + a25;
    U32At(r, 0x1d0) = real_to_hex(0, a31);
    U32At(r, 0x1d4) = shared;
    U32At(r, 0x1d8) = real_to_hex(1, sum31 * -512.0f + bias);
    U32At(r, 0x1dc) = real_to_hex(0, a25);
}

/* Fills the 15 scaler-tap register words at regs+0x114.. from the coefficient set selected by 4096/scale. */
void ATIR500Surface::filter_setup(UInt32 scale, OverlayRegisters *regs) {
    UInt8 *r = reinterpret_cast<UInt8 *>(regs);
    double d = static_cast<double>(4096.0f / static_cast<float>(UD(scale)));
    double v = 0.25;
    if (0.25 <= d) {
        v = d;
        if (1.0 < d) {
            v = 1.0;
        }
    }
    int entry = static_cast<int>((v - 0.25) * 100.0) * 0x20;
    const UInt8 *set = reinterpret_cast<const UInt8 *>(kFilterSetupArrayOfSets) + 8 + entry;
    U32At(r, 0x114) = set[0] & 0xf;
    U32At(r, 0x118) = set[1] & 0x7f;
    U32At(r, 0x11c) = set[2] & 0x7f;
    U32At(r, 0x120) = set[3] & 0xf;
    U32At(r, 0x124) = set[4] & 0xf;
    U32At(r, 0x128) = set[5] & 0x7f;
    U32At(r, 300) = set[6] & 0x7f;
    U32At(r, 0x130) = set[7] & 0xf;
    U32At(r, 0x134) = set[8] & 0xf;
    U32At(r, 0x138) = set[9] & 0x7f;
    U32At(r, 0x13c) = set[10] & 0x7f;
    U32At(r, 0x140) = set[11] & 0xf;
    U32At(r, 0x144) = set[12] & 0xf;
    U32At(r, 0x148) = set[13] & 0x7f;
    U32At(r, 0x14c) = set[14] & 0x7f;
    U32At(r, 0x150) = set[15] & 0xf;
    U32At(r, 0x160) = set[19] & 0xf;
    U32At(r, 0x154) = set[16] & 0xf;
    U32At(r, 0x158) = set[17] & 0x7f;
    U32At(r, 0x15c) = set[18] & 0x7f;
}

/* Looks up the horizontal-scaler step entry for `mode` whose 3-tap sum fits the scale; writes the chosen entry's
 * fields through the nine output pointers and returns the first computed increment (or `this` for an unknown mode). */
UInt32 ATIR500Surface::calc_h_inc_step_by(int mode, float scale, int p3, int p4, int p5, UInt32 *o6, UInt32 *o7,
                                          UInt32 *o8, UInt32 *o9, UInt32 *o10, UInt32 *o11, UInt32 *o12,
                                          UInt32 *o13, UInt32 *o14) {
    float fVar1 = static_cast<float>(1.0 / static_cast<double>(scale));
    float fVar2 = fVar1;
    const UInt32 *table;
    int last;
    switch (mode) {
    case 3:
    case 4:
        last = 4;
        table = kMode34Table;
        break;
    default:
        return reinterpret_cast<UInt32>(this);
    case 6:
        last = 7;
        table = kMode6Table;
        break;
    case 9:
        last = 0xb;
        table = kMode9Table;
        fVar2 = fVar1 * 4.0f;
        break;
    case 10:
        last = 0xb;
        table = kMode10Table;
        fVar2 = fVar1 + fVar1;
        break;
    case 0xb:
    case 0xc:
        last = 7;
        table = kMode1112Table;
        fVar2 = fVar1 + fVar1;
        break;
    case 0xd:
    case 0xe:
        last = 8;
        table = kMode1314Table;
        fVar2 = fVar1 + fVar1;
        break;
    }
    UInt32 first = reinterpret_cast<UInt32>(this);
    int remaining = last + 1;
    int index = 0;
    do {
        float fVar3 = (F(table, 0) + F(table, 1) + F(table, 2)) * 0.0625f;
        double inc = (1.0 / static_cast<double>(fVar1 * static_cast<float>(UD(B(table, 0x14))))) * 4096.0;
        first = F2U(inc);
        inc = (1.0 / static_cast<double>(static_cast<float>(UD(B(table, 0x16))) * fVar2)) * 4096.0;
        UInt32 second = F2U(inc);
        bool okA = (B(table, 0x0c) == static_cast<UInt32>(p3)) || B(table, 0x0e) != 0;
        bool okB = (B(table, 0x0d) == static_cast<UInt32>(p4)) || B(table, 0x0f) != 0;
        bool fits = (fVar3 <= fVar1) && okA && okB;
        if (fits || (last - index < 1)) {
            *o6 = B(table, 0x1a);
            *o7 = B(table, 0x10 + p5);
            *o8 = B(table, 0x12 + p5);
            *o9 = B(table, 0x14 + p5);
            *o10 = B(table, 0x16 + p5);
            if (p5 == 1) {
                *o11 = B(table, 0x18);
                *o12 = B(table, 0x19);
            } else {
                *o11 = 0;
                *o12 = 0;
            }
            if (!fits) {
                double a = (1.0 / static_cast<double>(static_cast<float>(UD(B(table, 0x14))) * fVar3)) * 4096.0;
                *o13 = F2U(a);
                double b = (1.0 / static_cast<double>(static_cast<float>(UD(B(table, 0x16))) * fVar3)) * 4096.0;
                *o14 = F2U(b);
                return first;
            }
            *o13 = first;
            *o14 = second;
            return first;
        }
        table += 7;
        ++index;
        --remaining;
    } while (remaining != 0);
    return first;
}

/* Builds the six surface-descriptor register words (one per overlay plane): bits 1.. plane selector, bit-field
 * from info+0x88.., base address >> 4 in bits 4.., and a high bit-field from the per-plane state. */
void ATIR500Surface::get_surf_desc_regs(OverlaySurfaceInfo *infoIn, UInt32 *out) {
    UInt8 *self = reinterpret_cast<UInt8 *>(this);
    UInt8 *info = reinterpret_cast<UInt8 *>(infoIn);
    SInt32 e8[6];
    SInt32 d0[6];
    UInt32 b8[6] = { 0, 0, 0, 0, 0, 0 };   /* words 3-5 stay unwritten (stack garbage) on the iVar17 != 0 video path */

    if (U32At(info, 0x3c) - 9u < 2) {
        UInt32 v40 = U32At(info, 0x40);
        SInt32 mode = static_cast<SInt32>(U32At(info, 0xe0));
        for (int k = 0; k < 6; ++k) {
            UInt32 base = U32At(self, U32At(self, 0xd90) * 0x78 + 0x560);
            U32At(info, 0x70 + k * 4) = v40;
            U32At(info, 0x88 + k * 4) = 0;
            U32At(info, 0x58 + k * 4) = base;
            e8[k] = mode;
            d0[k] = 0;
        }
        SInt32 a = static_cast<SInt32>(U32At(info, 0xd4));
        SInt32 b = static_cast<SInt32>(U32At(info, 0xd8));
        SInt32 c = static_cast<SInt32>(U32At(info, 0xdc));
        b8[0] = static_cast<UInt32>(a / 16);
        b8[1] = static_cast<UInt32>(b / 16);
        b8[2] = static_cast<UInt32>(c / 16);
        if (mode == 0) {
            b8[3] = b8[0];
            b8[4] = b8[1];
            b8[5] = b8[2];
        }
        U32At(info, 0x90) = 1;
        U32At(info, 0x98) = 1;
        U32At(info, 0x8c) = 1;
        U32At(info, 0x9c) = 1;
    } else {
        SInt32 v10 = static_cast<SInt32>(U32At(info, 0x10));
        SInt32 v14 = static_cast<SInt32>(U32At(info, 0x14));
        float f30 = F32At(info, 0x30);
        float f34 = F32At(info, 0x34);
        SInt32 mode = static_cast<SInt32>(U32At(info, 0xe0));
        UInt32 v40 = U32At(info, 0x40);
        UInt32 bits = U32At(info, 0x54);
        SInt32 t1 = (v10 < 0) ? -v10 : 0;
        SInt32 t2 = (v14 < 0) ? -v14 : 0;
        UInt32 q3 = static_cast<UInt32>(v10) / U32At(info, 0x50);
        UInt32 q4 = static_cast<UInt32>(v14) / U32At(info, 0x4c);
        SInt32 t3 = (static_cast<SInt32>(q3) < 0) ? -static_cast<SInt32>(q3) : 0;
        SInt32 t4 = (static_cast<SInt32>(q4) < 0) ? -static_cast<SInt32>(q4) : 0;
        float fVar2 = static_cast<float>(SD(t1)) * f34;
        float fVar3 = static_cast<float>(SD(t3)) * f34;
        float fA = static_cast<float>(SD(t2)) * f30;
        float fB = static_cast<float>(SD(t4)) * f30;
        for (UInt32 k = 0; k < 6; ++k) {
            e8[k] = mode;
            UInt32 base = U32At(self, 0x128);
            U32At(info, 0x70 + k * 4) = v40;
            U32At(info, 0x88 + k * 4) = 0;
            U32At(info, 0xa0 + k * 4) = 0;
            U32At(info, 0xb8 + k * 4) = 0;
            U32At(info, 0x58 + k * 4) = base;
            SInt32 iVar16, iVar14;
            if (((bits >> (k & 0x3f)) & 1) == 0) {
                float fVar4 = fA * static_cast<float>(UD(U32At(info, 0x44)));
                iVar16 = static_cast<SInt32>(F2U(static_cast<double>(fVar4))) + static_cast<SInt32>(U32At(info, 0xa0 + k * 4));
                iVar14 = static_cast<SInt32>(F2U(static_cast<double>(fVar2)));
            } else {
                float fVar4 = fB * static_cast<float>(UD(U32At(info, 0x48)));
                iVar16 = static_cast<SInt32>(F2U(static_cast<double>(fVar4))) + static_cast<SInt32>(U32At(info, 0xa0 + k * 4));
                iVar14 = static_cast<SInt32>(F2U(static_cast<double>(fVar3)));
            }
            SInt32 stride = static_cast<SInt32>(U32At(info, 0x70 + k * 4));
            SInt32 origin = static_cast<SInt32>(U32At(info, 0x58 + k * 4));
            d0[k] = 0;
            SInt32 offset = iVar14 * stride + origin;
            b8[k] = static_cast<UInt32>(iVar16 + offset) >> 4;
        }
    }
    for (int k = 0; k < 6; ++k) {
        out[k] = (static_cast<UInt32>(e8[k]) << 1) | U32At(info, 0x88 + k * 4) | (b8[k] << 4) |
                 (static_cast<UInt32>(d0[k]) << 0x1b);
    }
}

/* Computes the horizontal scaler blanking window for the overlay's output line (outputs 7/8/9). */
void ATIR500Surface::calc_h_scaler_blank(OverlaySurfaceInfo *infoIn, OverlayBandwidthInfo *bandwidth, UInt32 p3, UInt32 p4,
                                         float f5, float f6, UInt32 *o7, UInt32 *o8, UInt32 *o9) {
    UInt8 *info = reinterpret_cast<UInt8 *>(infoIn);
    UInt8 *bw = reinterpret_cast<UInt8 *>(bandwidth);
    SInt32 lineWidth = static_cast<SInt32>(U32At(info, 0x18));
    float fVar1;
    switch (U32At(info, 0x3c)) {
    case 3:
    case 4:
    case 0xb:
    case 0xc:
        fVar1 = static_cast<float>(UD(p3 >> 3));
        break;
    case 6:
        fVar1 = static_cast<float>(UD(p3 >> 2));
        break;
    case 9:
    case 10:
        fVar1 = static_cast<float>(UD(p4 >> 4));
        break;
    case 0xd:
    case 0xe:
        fVar1 = static_cast<float>(UD(p3 >> 4));
        break;
    default:
        fVar1 = 0.0f;
        break;
    }
    SInt32 latency = 0xc;
    UInt32 mode = U32At(bw, 0x2c);
    fVar1 = static_cast<float>(static_cast<double>(static_cast<float>(static_cast<double>(f6) * static_cast<double>(fVar1))) /
                               static_cast<double>(f5));
    double span = SD(lineWidth - static_cast<SInt32>(U32At(info, 0x14)));
    if (mode != 2) {
        if (mode < 3) {
            latency = 0x18;
            if (mode != 1) {
                latency = 3;
            }
        } else {
            latency = 6;
            if (mode >= 5) {
                latency = 3;
            }
        }
    }
    SInt32 adjust, window;
    if (U32At(bw, 0x38) == 1) {
        adjust = 0x26;
        window = 0x20;
    } else if (U32At(bw, 0x38) == 2) {
        adjust = 0x4c;
        window = 0x40;
    } else {
        adjust = 0x13;
        window = 0x10;
    }
    UInt32 blank = static_cast<UInt32>((latency - adjust) + 4);
    *o9 = blank;
    if (static_cast<float>(span) <= fVar1) {
        *o7 = static_cast<UInt32>(lineWidth) + blank;
    } else {
        float rest = static_cast<float>(UD(static_cast<UInt32>(lineWidth))) - fVar1;
        *o7 = blank + F2U(static_cast<double>(rest));
    }
    *o8 = ((U32At(bw, 0x24) * 8 + U32At(info, 0x14)) - static_cast<UInt32>(window)) + *o9 + 8;
}

/* Real: true when the framebuffer's registry "display-family" property reads 8 in its low nibble: the framebuffer
 * (this+0xd50) has a provider at +0x74; its vtable +0x188 (getProperty(const char *)) returns an OSData whose
 * bytes (vtable +0x100, getBytesNoCopy) start with the property word. */
UInt32 ATIR500Surface::bad_panel(void) {
    typedef void *(*GetPropertyFn)(void *, const char *);
    typedef UInt32 *(*GetBytesFn)(void *);
    void *provider = reinterpret_cast<void *>(U32At(reinterpret_cast<void *>(U32At(this, 0xd50)), 0x74));
    void *property = (*reinterpret_cast<GetPropertyFn *>(*reinterpret_cast<UInt8 **>(provider) + 0x188))(provider, "display-family");
    if (property != nullptr) {
        UInt32 *bytes = (*reinterpret_cast<GetBytesFn *>(*reinterpret_cast<UInt8 **>(property) + 0x100))(property);
        if ((*bytes & 0xf) == 8) {
            return 1;
        }
    }
    return 0;
}
