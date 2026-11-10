#include "decls.h"
#include <altivec.h>

/* Hand transcription of the one GLEngine function Ghidra's decompiler cannot handle (AltiVec). Compiled with -maltivec because this file mentions vec16 (build.sh: `grep -qw vec16`).
 * _gleInvertMatrix_AltiVec @ 0x335c0 (624 bytes), selected by _gleSetupInvertMatrix when the processor flags have bit 4 set (PTR__gleInvertMatrix_AltiVec_00110e84).
 * Inverts the 4x4 float matrix at ctx + idx*64 + 0x1bc0 (loaded unaligned: lvsl/vperm) into ctx + idx*64 + 0x21c0 (stored unaligned: lvsr/vperm + stvebx/stvehx/stvewx/stvx, exactly 64 bytes):
 * Gauss-Jordan elimination with a pivot search by the largest |element| (vcmpgefp / vsel over the lane indices of v14 = lvsr(0,0)), the reciprocal from vrefp + two Newton steps
 * (r = r + r*(1 - x*r): vnmsubfp / vmaddfp), every product written as vmaddfp(x, y, -0.0f) (AltiVec has no vmulfp), the row permutation recorded in v17 and applied at the end, then a 4x4 transpose
 * (vmrghw / vmrglw) and the final lane permutation v2. One instruction per intrinsic, in the stock's order (stock register in the comment: vN). Returns nothing (r3 is left as a scratch pointer). */
typedef __vector float VF;
typedef __vector unsigned int VU;
typedef __vector unsigned short VS;
typedef __vector unsigned char VB;

/* _gleInvertMatrix_AltiVec @ 0x335c0 (624 bytes) */
/* the corpus decls.h has no prototype for it (not a decompiled function), so give it the assembler label data.s (PTR__gleInvertMatrix_AltiVec_00110e84) refers to */
void _gleInvertMatrix_AltiVec(unsigned char *ctx, unsigned int idx) __asm__("_gleInvertMatrix_AltiVec");
void _gleInvertMatrix_AltiVec(unsigned char *ctx, unsigned int idx)
{
    unsigned char *p = ctx + (idx << 6);
    unsigned char *src = p + 0x1bc0;                    /* r0 */
    unsigned char *dst = p + 0x21c0;                    /* r3 */
    VU zero = (VU)vec_splat_s32(0);                     /* v18 */
    VF one = vec_ctf((VU)vec_splat_s32(1), 0);          /* v15 = 1.0f */
    VB lsl = vec_lvsl(0, src);                          /* v1 */
    VB l12 = vec_ld(0, src), l11 = vec_ld(0x10, src), l13 = vec_ld(0x20, src), l10 = vec_ld(0x30, src), l9 = vec_ld(0x3f, src);
    VU mone = (VU)vec_splat_s32(-1);                    /* v0 */
    VB ix = vec_lvsr(0, (unsigned char *)0);            /* v14 = 0x10..0x1f */
    VF a = (VF)vec_perm(l12, l11, lsl);                 /* v12 -> v8: row 0 */
    VF b = (VF)vec_perm(l11, l13, lsl);                 /* v11 -> v6: row 1 */
    VF c = (VF)vec_perm(l13, l10, lsl);                 /* v13 -> v7: row 2 */
    VF d = (VF)vec_perm(l10, l9, lsl);                  /* v5: row 3 */
    VU sign = vec_sl(mone, mone);                       /* v19 = 0x80000000 */
    VB four = vec_splat_u8(4);                          /* v31 */
    VU idxw = vec_splat((VU)ix, 0);                     /* v16 */
    VU lane = (VU)vec_sld((VB)mone, (VB)zero, 12);      /* v3: word 0 */
    VU pidx = zero;                                     /* v2 */
    VU pv = zero;                                       /* v17 */
    VF negz = (VF)sign;                                 /* v4 = -0.0f */
    int it;
    for (it = 0; it < 4; it++) {                        /* ctr = 4 */
        VF rcp = vec_re(a);                             /* v13 */
        VF mag = vec_andc(a, (VF)sign);                 /* v0 */
        VF mg1 = vec_sld(mag, mag, 8);                  /* v12 */
        VU ix1 = vec_sld((VU)ix, (VU)ix, 8);            /* v11 */
        VF err = vec_nmsub(a, rcp, one);                /* v10 */
        VU m1 = (VU)vec_cmpge(mag, mg1);                /* v9 */
        VU sel;
        VU is;
        VF e12, e11, e10, e1, a0;
        mag = vec_sel(mg1, mag, (VU)m1);                /* v0 */
        sel = vec_sel(ix1, (VU)ix, m1);                 /* v1 */
        rcp = vec_madd(err, rcp, rcp);                  /* v13 */
        mg1 = vec_sld(mag, mag, 4);                     /* v12 */
        ix1 = vec_sld(sel, sel, 4);                     /* v11 */
        m1 = (VU)vec_cmpge(mag, mg1);                   /* v9 */
        err = vec_nmsub(a, rcp, one);                   /* v10 */
        sel = vec_sel(ix1, sel, m1);                    /* v1 */
        sel = vec_splat(sel, 0);                        /* v1 */
        rcp = vec_madd(err, rcp, rcp);                  /* v13 */
        is = (VU)vec_cmpeq(sel, (VU)ix);                /* v9 */
        pv = vec_sel(pv, sel, lane);                    /* v17 */
        sel = vec_andc(sel, is);                        /* v1 */
        rcp = vec_sel(one, rcp, is);                    /* v13 */
        b = vec_madd(b, rcp, negz);                     /* v6 */
        c = vec_madd(c, rcp, negz);                     /* v7 */
        d = vec_madd(d, rcp, negz);                     /* v5 */
        a = vec_madd(a, rcp, negz);                     /* v8 */
        rcp = vec_sel((VF)zero, rcp, is);               /* v13 */
        e12 = (VF)vec_perm((VB)zero, (VB)b, (VB)sel);   /* v12 */
        e11 = (VF)vec_perm((VB)zero, (VB)c, (VB)sel);   /* v11 */
        e10 = (VF)vec_perm((VB)zero, (VB)rcp, (VB)sel); /* v10 */
        e1 = (VF)vec_perm((VB)zero, (VB)d, (VB)sel);    /* v1 */
        a0 = a;                                         /* v0 */
        pidx = vec_sel(pidx, idxw, is);                 /* v2 */
        a = vec_nmsub(a, e12, b);                       /* v8 */
        sign = vec_or(sign, is);                        /* v19 */
        b = vec_nmsub(a0, e11, c);                      /* v6 */
        lane = vec_sld(lane, lane, 12);                 /* v3 */
        c = vec_nmsub(a0, e1, d);                       /* v7 */
        idxw = (VU)vec_add((VB)idxw, four);             /* v16 */
        d = vec_nmsub(a0, e10, rcp);                    /* v5 */
    }
    {
        VF t13, t1, t9, t0, o10, o11, o12, o13;
        d = vec_perm(d, d, (VB)pv);                     /* v5 */
        a = vec_perm(a, a, (VB)pv);                     /* v8 */
        b = vec_perm(b, b, (VB)pv);                     /* v6 */
        c = vec_perm(c, c, (VB)pv);                     /* v7 */
        t13 = vec_mergel(b, d);                         /* v13 */
        t1 = vec_mergel(a, c);                          /* v1 */
        t9 = vec_mergeh(a, c);                          /* v9 */
        t0 = vec_mergeh(b, d);                          /* v0 */
        o10 = vec_mergel(t1, t13);                      /* v10 */
        o11 = vec_mergel(t9, t0);                       /* v11 */
        o12 = vec_mergeh(t9, t0);                       /* v12 */
        o13 = vec_mergeh(t1, t13);                      /* v13 */
        o10 = vec_perm(o10, o10, (VB)pidx);
        o12 = vec_perm(o12, o12, (VB)pidx);
        o11 = vec_perm(o11, o11, (VB)pidx);
        o13 = vec_perm(o13, o13, (VB)pidx);
        if (((unsigned int)dst & 0xf) == 0) {           /* aligned: four stvx, rows in the order v12 v11 v13 v10 */
            vec_st(o12, 0, (float *)dst);
            vec_st(o11, 16, (float *)dst);
            vec_st(o13, 32, (float *)dst);
            vec_st(o10, 48, (float *)dst);
        } else {                                        /* unaligned: rotate the four rows by lvsr(dst) and store the 64 bytes with element stores at both ends */
            VB sh = vec_lvsr(0, dst);                   /* v0 */
            VB s9 = vec_perm((VB)o10, (VB)o10, sh);
            VB s10 = vec_perm((VB)o13, (VB)o10, sh);
            VB s13 = vec_perm((VB)o11, (VB)o13, sh);
            VB s11 = vec_perm((VB)o12, (VB)o11, sh);
            VB s12 = vec_perm((VB)o12, (VB)o12, sh);
            unsigned int rem = 0x10;                    /* r2 */
            if ((unsigned int)dst & 1) { vec_ste(s12, 0, dst); rem = 0xf; dst += 1; }
            if ((unsigned int)dst & 2) { vec_ste((VS)s12, 0, (unsigned short *)dst); rem -= 2; dst += 2; }
            if ((unsigned int)dst & 0xc) {
                do { unsigned char *t = dst; dst += 4; vec_ste((VU)s12, 0, (unsigned int *)t); rem -= 4; } while ((unsigned int)dst & 0xc);
            }
            vec_st(s11, 0, dst); dst += 16;
            vec_st(s13, 0, dst); dst += 16;
            vec_st(s10, 0, dst); dst += 16;
            if (rem & 0xc) {
                do { rem -= 4; vec_ste((VU)s9, 0, (unsigned int *)dst); dst += 4; } while (rem & 0xc);
            }
            if (rem & 2) { vec_ste((VS)s9, 0, (unsigned short *)dst); dst += 2; }
            if (rem & 1) vec_ste(s9, 0, dst);
        }
    }
}
