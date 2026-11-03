/* gl_frame_timer.c - per-frame, per-GL-call CPU time for an application that fetches its GL entry points with SDL_GL_GetProcAddress (UT2004 on the Tiger G5).
 * DYLD interposer (issue #209 hitch analysis): replaces SDL_GL_GetProcAddress (returns a timing wrapper for every gl* name asked for) and SDL_GL_SwapBuffers (frame counter).
 * Every wrapper forwards 12 integer words + 13 FPRs unchanged (Darwin PPC32 ABI: arguments live in r3-r10 / f1-f13 / the first stack words), so any GL prototype of up to 12 argument words works.
 * Output (GLT_OUT=/path.tsv, written at exit): "F <frame> <slot> <count> <usec>" lines, "N <slot> <name>" lines, "SWAPS <n>". Frame 0 = first swap seen; align with the game's stats.csv by total swap count.
 * Build on the G5: gcc -arch ppc -dynamiclib -o gl_frame_timer.dylib gl_frame_timer.c   Use: DYLD_INSERT_LIBRARIES=.../gl_frame_timer.dylib GLT_OUT=... ./ut2004-bin ... */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <mach/mach_time.h>
#define NSLOT 400
#define MAXF 4000
typedef unsigned long W;
static void *real[NSLOT]; static char *names[NSLOT]; static int nslots = 0;
static unsigned long cnt[MAXF][NSLOT]; static double us_[MAXF][NSLOT];
static float maxus[MAXF][NSLOT]; static double swap_us[MAXF]; static double wall_us[MAXF]; static int frame = 0; static double tick_us = 0;
typedef W (*fn_t)(W,W,W,W,W,W,W,W,W,W,W,W,double,double,double,double,double,double,double,double,double,double,double,double,double);
#define ARGS W a0,W a1,W a2,W a3,W a4,W a5,W a6,W a7,W a8,W a9,W a10,W a11,double d1,double d2,double d3,double d4,double d5,double d6,double d7,double d8,double d9,double d10,double d11,double d12,double d13
static inline W go(int k, ARGS) {
    uint64_t t0 = mach_absolute_time();
    W r = ((fn_t)real[k])(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13);
    uint64_t t1 = mach_absolute_time();
    if (frame < MAXF) { double u = (double)(t1 - t0) * tick_us; cnt[frame][k]++; us_[frame][k] += u; if (u > maxus[frame][k]) maxus[frame][k] = (float)u; }
    return r;
}
static W w0(ARGS) { return go(0,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w1(ARGS) { return go(1,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w2(ARGS) { return go(2,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w3(ARGS) { return go(3,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w4(ARGS) { return go(4,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w5(ARGS) { return go(5,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w6(ARGS) { return go(6,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w7(ARGS) { return go(7,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w8(ARGS) { return go(8,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w9(ARGS) { return go(9,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w10(ARGS) { return go(10,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w11(ARGS) { return go(11,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w12(ARGS) { return go(12,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w13(ARGS) { return go(13,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w14(ARGS) { return go(14,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w15(ARGS) { return go(15,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w16(ARGS) { return go(16,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w17(ARGS) { return go(17,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w18(ARGS) { return go(18,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w19(ARGS) { return go(19,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w20(ARGS) { return go(20,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w21(ARGS) { return go(21,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w22(ARGS) { return go(22,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w23(ARGS) { return go(23,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w24(ARGS) { return go(24,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w25(ARGS) { return go(25,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w26(ARGS) { return go(26,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w27(ARGS) { return go(27,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w28(ARGS) { return go(28,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w29(ARGS) { return go(29,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w30(ARGS) { return go(30,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w31(ARGS) { return go(31,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w32(ARGS) { return go(32,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w33(ARGS) { return go(33,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w34(ARGS) { return go(34,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w35(ARGS) { return go(35,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w36(ARGS) { return go(36,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w37(ARGS) { return go(37,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w38(ARGS) { return go(38,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w39(ARGS) { return go(39,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w40(ARGS) { return go(40,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w41(ARGS) { return go(41,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w42(ARGS) { return go(42,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w43(ARGS) { return go(43,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w44(ARGS) { return go(44,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w45(ARGS) { return go(45,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w46(ARGS) { return go(46,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w47(ARGS) { return go(47,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w48(ARGS) { return go(48,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w49(ARGS) { return go(49,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w50(ARGS) { return go(50,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w51(ARGS) { return go(51,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w52(ARGS) { return go(52,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w53(ARGS) { return go(53,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w54(ARGS) { return go(54,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w55(ARGS) { return go(55,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w56(ARGS) { return go(56,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w57(ARGS) { return go(57,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w58(ARGS) { return go(58,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w59(ARGS) { return go(59,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w60(ARGS) { return go(60,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w61(ARGS) { return go(61,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w62(ARGS) { return go(62,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w63(ARGS) { return go(63,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w64(ARGS) { return go(64,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w65(ARGS) { return go(65,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w66(ARGS) { return go(66,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w67(ARGS) { return go(67,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w68(ARGS) { return go(68,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w69(ARGS) { return go(69,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w70(ARGS) { return go(70,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w71(ARGS) { return go(71,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w72(ARGS) { return go(72,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w73(ARGS) { return go(73,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w74(ARGS) { return go(74,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w75(ARGS) { return go(75,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w76(ARGS) { return go(76,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w77(ARGS) { return go(77,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w78(ARGS) { return go(78,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w79(ARGS) { return go(79,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w80(ARGS) { return go(80,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w81(ARGS) { return go(81,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w82(ARGS) { return go(82,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w83(ARGS) { return go(83,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w84(ARGS) { return go(84,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w85(ARGS) { return go(85,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w86(ARGS) { return go(86,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w87(ARGS) { return go(87,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w88(ARGS) { return go(88,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w89(ARGS) { return go(89,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w90(ARGS) { return go(90,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w91(ARGS) { return go(91,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w92(ARGS) { return go(92,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w93(ARGS) { return go(93,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w94(ARGS) { return go(94,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w95(ARGS) { return go(95,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w96(ARGS) { return go(96,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w97(ARGS) { return go(97,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w98(ARGS) { return go(98,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w99(ARGS) { return go(99,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w100(ARGS) { return go(100,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w101(ARGS) { return go(101,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w102(ARGS) { return go(102,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w103(ARGS) { return go(103,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w104(ARGS) { return go(104,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w105(ARGS) { return go(105,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w106(ARGS) { return go(106,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w107(ARGS) { return go(107,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w108(ARGS) { return go(108,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w109(ARGS) { return go(109,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w110(ARGS) { return go(110,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w111(ARGS) { return go(111,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w112(ARGS) { return go(112,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w113(ARGS) { return go(113,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w114(ARGS) { return go(114,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w115(ARGS) { return go(115,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w116(ARGS) { return go(116,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w117(ARGS) { return go(117,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w118(ARGS) { return go(118,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w119(ARGS) { return go(119,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w120(ARGS) { return go(120,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w121(ARGS) { return go(121,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w122(ARGS) { return go(122,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w123(ARGS) { return go(123,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w124(ARGS) { return go(124,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w125(ARGS) { return go(125,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w126(ARGS) { return go(126,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w127(ARGS) { return go(127,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w128(ARGS) { return go(128,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w129(ARGS) { return go(129,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w130(ARGS) { return go(130,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w131(ARGS) { return go(131,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w132(ARGS) { return go(132,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w133(ARGS) { return go(133,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w134(ARGS) { return go(134,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w135(ARGS) { return go(135,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w136(ARGS) { return go(136,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w137(ARGS) { return go(137,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w138(ARGS) { return go(138,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w139(ARGS) { return go(139,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w140(ARGS) { return go(140,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w141(ARGS) { return go(141,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w142(ARGS) { return go(142,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w143(ARGS) { return go(143,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w144(ARGS) { return go(144,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w145(ARGS) { return go(145,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w146(ARGS) { return go(146,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w147(ARGS) { return go(147,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w148(ARGS) { return go(148,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w149(ARGS) { return go(149,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w150(ARGS) { return go(150,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w151(ARGS) { return go(151,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w152(ARGS) { return go(152,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w153(ARGS) { return go(153,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w154(ARGS) { return go(154,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w155(ARGS) { return go(155,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w156(ARGS) { return go(156,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w157(ARGS) { return go(157,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w158(ARGS) { return go(158,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w159(ARGS) { return go(159,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w160(ARGS) { return go(160,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w161(ARGS) { return go(161,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w162(ARGS) { return go(162,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w163(ARGS) { return go(163,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w164(ARGS) { return go(164,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w165(ARGS) { return go(165,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w166(ARGS) { return go(166,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w167(ARGS) { return go(167,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w168(ARGS) { return go(168,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w169(ARGS) { return go(169,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w170(ARGS) { return go(170,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w171(ARGS) { return go(171,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w172(ARGS) { return go(172,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w173(ARGS) { return go(173,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w174(ARGS) { return go(174,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w175(ARGS) { return go(175,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w176(ARGS) { return go(176,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w177(ARGS) { return go(177,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w178(ARGS) { return go(178,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w179(ARGS) { return go(179,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w180(ARGS) { return go(180,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w181(ARGS) { return go(181,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w182(ARGS) { return go(182,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w183(ARGS) { return go(183,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w184(ARGS) { return go(184,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w185(ARGS) { return go(185,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w186(ARGS) { return go(186,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w187(ARGS) { return go(187,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w188(ARGS) { return go(188,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w189(ARGS) { return go(189,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w190(ARGS) { return go(190,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w191(ARGS) { return go(191,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w192(ARGS) { return go(192,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w193(ARGS) { return go(193,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w194(ARGS) { return go(194,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w195(ARGS) { return go(195,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w196(ARGS) { return go(196,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w197(ARGS) { return go(197,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w198(ARGS) { return go(198,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w199(ARGS) { return go(199,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w200(ARGS) { return go(200,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w201(ARGS) { return go(201,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w202(ARGS) { return go(202,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w203(ARGS) { return go(203,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w204(ARGS) { return go(204,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w205(ARGS) { return go(205,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w206(ARGS) { return go(206,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w207(ARGS) { return go(207,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w208(ARGS) { return go(208,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w209(ARGS) { return go(209,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w210(ARGS) { return go(210,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w211(ARGS) { return go(211,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w212(ARGS) { return go(212,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w213(ARGS) { return go(213,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w214(ARGS) { return go(214,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w215(ARGS) { return go(215,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w216(ARGS) { return go(216,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w217(ARGS) { return go(217,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w218(ARGS) { return go(218,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w219(ARGS) { return go(219,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w220(ARGS) { return go(220,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w221(ARGS) { return go(221,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w222(ARGS) { return go(222,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w223(ARGS) { return go(223,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w224(ARGS) { return go(224,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w225(ARGS) { return go(225,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w226(ARGS) { return go(226,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w227(ARGS) { return go(227,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w228(ARGS) { return go(228,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w229(ARGS) { return go(229,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w230(ARGS) { return go(230,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w231(ARGS) { return go(231,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w232(ARGS) { return go(232,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w233(ARGS) { return go(233,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w234(ARGS) { return go(234,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w235(ARGS) { return go(235,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w236(ARGS) { return go(236,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w237(ARGS) { return go(237,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w238(ARGS) { return go(238,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w239(ARGS) { return go(239,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w240(ARGS) { return go(240,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w241(ARGS) { return go(241,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w242(ARGS) { return go(242,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w243(ARGS) { return go(243,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w244(ARGS) { return go(244,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w245(ARGS) { return go(245,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w246(ARGS) { return go(246,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w247(ARGS) { return go(247,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w248(ARGS) { return go(248,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w249(ARGS) { return go(249,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w250(ARGS) { return go(250,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w251(ARGS) { return go(251,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w252(ARGS) { return go(252,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w253(ARGS) { return go(253,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w254(ARGS) { return go(254,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w255(ARGS) { return go(255,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w256(ARGS) { return go(256,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w257(ARGS) { return go(257,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w258(ARGS) { return go(258,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w259(ARGS) { return go(259,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w260(ARGS) { return go(260,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w261(ARGS) { return go(261,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w262(ARGS) { return go(262,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w263(ARGS) { return go(263,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w264(ARGS) { return go(264,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w265(ARGS) { return go(265,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w266(ARGS) { return go(266,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w267(ARGS) { return go(267,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w268(ARGS) { return go(268,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w269(ARGS) { return go(269,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w270(ARGS) { return go(270,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w271(ARGS) { return go(271,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w272(ARGS) { return go(272,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w273(ARGS) { return go(273,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w274(ARGS) { return go(274,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w275(ARGS) { return go(275,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w276(ARGS) { return go(276,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w277(ARGS) { return go(277,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w278(ARGS) { return go(278,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w279(ARGS) { return go(279,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w280(ARGS) { return go(280,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w281(ARGS) { return go(281,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w282(ARGS) { return go(282,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w283(ARGS) { return go(283,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w284(ARGS) { return go(284,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w285(ARGS) { return go(285,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w286(ARGS) { return go(286,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w287(ARGS) { return go(287,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w288(ARGS) { return go(288,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w289(ARGS) { return go(289,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w290(ARGS) { return go(290,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w291(ARGS) { return go(291,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w292(ARGS) { return go(292,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w293(ARGS) { return go(293,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w294(ARGS) { return go(294,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w295(ARGS) { return go(295,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w296(ARGS) { return go(296,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w297(ARGS) { return go(297,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w298(ARGS) { return go(298,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w299(ARGS) { return go(299,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w300(ARGS) { return go(300,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w301(ARGS) { return go(301,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w302(ARGS) { return go(302,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w303(ARGS) { return go(303,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w304(ARGS) { return go(304,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w305(ARGS) { return go(305,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w306(ARGS) { return go(306,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w307(ARGS) { return go(307,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w308(ARGS) { return go(308,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w309(ARGS) { return go(309,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w310(ARGS) { return go(310,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w311(ARGS) { return go(311,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w312(ARGS) { return go(312,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w313(ARGS) { return go(313,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w314(ARGS) { return go(314,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w315(ARGS) { return go(315,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w316(ARGS) { return go(316,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w317(ARGS) { return go(317,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w318(ARGS) { return go(318,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w319(ARGS) { return go(319,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w320(ARGS) { return go(320,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w321(ARGS) { return go(321,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w322(ARGS) { return go(322,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w323(ARGS) { return go(323,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w324(ARGS) { return go(324,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w325(ARGS) { return go(325,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w326(ARGS) { return go(326,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w327(ARGS) { return go(327,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w328(ARGS) { return go(328,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w329(ARGS) { return go(329,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w330(ARGS) { return go(330,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w331(ARGS) { return go(331,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w332(ARGS) { return go(332,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w333(ARGS) { return go(333,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w334(ARGS) { return go(334,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w335(ARGS) { return go(335,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w336(ARGS) { return go(336,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w337(ARGS) { return go(337,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w338(ARGS) { return go(338,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w339(ARGS) { return go(339,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w340(ARGS) { return go(340,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w341(ARGS) { return go(341,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w342(ARGS) { return go(342,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w343(ARGS) { return go(343,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w344(ARGS) { return go(344,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w345(ARGS) { return go(345,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w346(ARGS) { return go(346,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w347(ARGS) { return go(347,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w348(ARGS) { return go(348,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w349(ARGS) { return go(349,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w350(ARGS) { return go(350,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w351(ARGS) { return go(351,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w352(ARGS) { return go(352,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w353(ARGS) { return go(353,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w354(ARGS) { return go(354,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w355(ARGS) { return go(355,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w356(ARGS) { return go(356,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w357(ARGS) { return go(357,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w358(ARGS) { return go(358,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w359(ARGS) { return go(359,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w360(ARGS) { return go(360,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w361(ARGS) { return go(361,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w362(ARGS) { return go(362,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w363(ARGS) { return go(363,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w364(ARGS) { return go(364,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w365(ARGS) { return go(365,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w366(ARGS) { return go(366,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w367(ARGS) { return go(367,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w368(ARGS) { return go(368,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w369(ARGS) { return go(369,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w370(ARGS) { return go(370,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w371(ARGS) { return go(371,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w372(ARGS) { return go(372,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w373(ARGS) { return go(373,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w374(ARGS) { return go(374,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w375(ARGS) { return go(375,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w376(ARGS) { return go(376,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w377(ARGS) { return go(377,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w378(ARGS) { return go(378,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w379(ARGS) { return go(379,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w380(ARGS) { return go(380,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w381(ARGS) { return go(381,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w382(ARGS) { return go(382,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w383(ARGS) { return go(383,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w384(ARGS) { return go(384,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w385(ARGS) { return go(385,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w386(ARGS) { return go(386,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w387(ARGS) { return go(387,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w388(ARGS) { return go(388,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w389(ARGS) { return go(389,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w390(ARGS) { return go(390,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w391(ARGS) { return go(391,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w392(ARGS) { return go(392,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w393(ARGS) { return go(393,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w394(ARGS) { return go(394,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w395(ARGS) { return go(395,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w396(ARGS) { return go(396,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w397(ARGS) { return go(397,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w398(ARGS) { return go(398,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static W w399(ARGS) { return go(399,a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13); }
static void *wr[NSLOT] = {(void*)w0,(void*)w1,(void*)w2,(void*)w3,(void*)w4,(void*)w5,(void*)w6,(void*)w7,(void*)w8,(void*)w9,(void*)w10,(void*)w11,(void*)w12,(void*)w13,(void*)w14,(void*)w15,(void*)w16,(void*)w17,(void*)w18,(void*)w19,(void*)w20,(void*)w21,(void*)w22,(void*)w23,(void*)w24,(void*)w25,(void*)w26,(void*)w27,(void*)w28,(void*)w29,(void*)w30,(void*)w31,(void*)w32,(void*)w33,(void*)w34,(void*)w35,(void*)w36,(void*)w37,(void*)w38,(void*)w39,(void*)w40,(void*)w41,(void*)w42,(void*)w43,(void*)w44,(void*)w45,(void*)w46,(void*)w47,(void*)w48,(void*)w49,(void*)w50,(void*)w51,(void*)w52,(void*)w53,(void*)w54,(void*)w55,(void*)w56,(void*)w57,(void*)w58,(void*)w59,(void*)w60,(void*)w61,(void*)w62,(void*)w63,(void*)w64,(void*)w65,(void*)w66,(void*)w67,(void*)w68,(void*)w69,(void*)w70,(void*)w71,(void*)w72,(void*)w73,(void*)w74,(void*)w75,(void*)w76,(void*)w77,(void*)w78,(void*)w79,(void*)w80,(void*)w81,(void*)w82,(void*)w83,(void*)w84,(void*)w85,(void*)w86,(void*)w87,(void*)w88,(void*)w89,(void*)w90,(void*)w91,(void*)w92,(void*)w93,(void*)w94,(void*)w95,(void*)w96,(void*)w97,(void*)w98,(void*)w99,(void*)w100,(void*)w101,(void*)w102,(void*)w103,(void*)w104,(void*)w105,(void*)w106,(void*)w107,(void*)w108,(void*)w109,(void*)w110,(void*)w111,(void*)w112,(void*)w113,(void*)w114,(void*)w115,(void*)w116,(void*)w117,(void*)w118,(void*)w119,(void*)w120,(void*)w121,(void*)w122,(void*)w123,(void*)w124,(void*)w125,(void*)w126,(void*)w127,(void*)w128,(void*)w129,(void*)w130,(void*)w131,(void*)w132,(void*)w133,(void*)w134,(void*)w135,(void*)w136,(void*)w137,(void*)w138,(void*)w139,(void*)w140,(void*)w141,(void*)w142,(void*)w143,(void*)w144,(void*)w145,(void*)w146,(void*)w147,(void*)w148,(void*)w149,(void*)w150,(void*)w151,(void*)w152,(void*)w153,(void*)w154,(void*)w155,(void*)w156,(void*)w157,(void*)w158,(void*)w159,(void*)w160,(void*)w161,(void*)w162,(void*)w163,(void*)w164,(void*)w165,(void*)w166,(void*)w167,(void*)w168,(void*)w169,(void*)w170,(void*)w171,(void*)w172,(void*)w173,(void*)w174,(void*)w175,(void*)w176,(void*)w177,(void*)w178,(void*)w179,(void*)w180,(void*)w181,(void*)w182,(void*)w183,(void*)w184,(void*)w185,(void*)w186,(void*)w187,(void*)w188,(void*)w189,(void*)w190,(void*)w191,(void*)w192,(void*)w193,(void*)w194,(void*)w195,(void*)w196,(void*)w197,(void*)w198,(void*)w199,(void*)w200,(void*)w201,(void*)w202,(void*)w203,(void*)w204,(void*)w205,(void*)w206,(void*)w207,(void*)w208,(void*)w209,(void*)w210,(void*)w211,(void*)w212,(void*)w213,(void*)w214,(void*)w215,(void*)w216,(void*)w217,(void*)w218,(void*)w219,(void*)w220,(void*)w221,(void*)w222,(void*)w223,(void*)w224,(void*)w225,(void*)w226,(void*)w227,(void*)w228,(void*)w229,(void*)w230,(void*)w231,(void*)w232,(void*)w233,(void*)w234,(void*)w235,(void*)w236,(void*)w237,(void*)w238,(void*)w239,(void*)w240,(void*)w241,(void*)w242,(void*)w243,(void*)w244,(void*)w245,(void*)w246,(void*)w247,(void*)w248,(void*)w249,(void*)w250,(void*)w251,(void*)w252,(void*)w253,(void*)w254,(void*)w255,(void*)w256,(void*)w257,(void*)w258,(void*)w259,(void*)w260,(void*)w261,(void*)w262,(void*)w263,(void*)w264,(void*)w265,(void*)w266,(void*)w267,(void*)w268,(void*)w269,(void*)w270,(void*)w271,(void*)w272,(void*)w273,(void*)w274,(void*)w275,(void*)w276,(void*)w277,(void*)w278,(void*)w279,(void*)w280,(void*)w281,(void*)w282,(void*)w283,(void*)w284,(void*)w285,(void*)w286,(void*)w287,(void*)w288,(void*)w289,(void*)w290,(void*)w291,(void*)w292,(void*)w293,(void*)w294,(void*)w295,(void*)w296,(void*)w297,(void*)w298,(void*)w299,(void*)w300,(void*)w301,(void*)w302,(void*)w303,(void*)w304,(void*)w305,(void*)w306,(void*)w307,(void*)w308,(void*)w309,(void*)w310,(void*)w311,(void*)w312,(void*)w313,(void*)w314,(void*)w315,(void*)w316,(void*)w317,(void*)w318,(void*)w319,(void*)w320,(void*)w321,(void*)w322,(void*)w323,(void*)w324,(void*)w325,(void*)w326,(void*)w327,(void*)w328,(void*)w329,(void*)w330,(void*)w331,(void*)w332,(void*)w333,(void*)w334,(void*)w335,(void*)w336,(void*)w337,(void*)w338,(void*)w339,(void*)w340,(void*)w341,(void*)w342,(void*)w343,(void*)w344,(void*)w345,(void*)w346,(void*)w347,(void*)w348,(void*)w349,(void*)w350,(void*)w351,(void*)w352,(void*)w353,(void*)w354,(void*)w355,(void*)w356,(void*)w357,(void*)w358,(void*)w359,(void*)w360,(void*)w361,(void*)w362,(void*)w363,(void*)w364,(void*)w365,(void*)w366,(void*)w367,(void*)w368,(void*)w369,(void*)w370,(void*)w371,(void*)w372,(void*)w373,(void*)w374,(void*)w375,(void*)w376,(void*)w377,(void*)w378,(void*)w379,(void*)w380,(void*)w381,(void*)w382,(void*)w383,(void*)w384,(void*)w385,(void*)w386,(void*)w387,(void*)w388,(void*)w389,(void*)w390,(void*)w391,(void*)w392,(void*)w393,(void*)w394,(void*)w395,(void*)w396,(void*)w397,(void*)w398,(void*)w399};

static void dump(void) {
    const char *o = getenv("GLT_OUT"); FILE *f = o ? fopen(o, "w") : NULL; int fr, k; if (!f) return;
    for (k = 0; k < nslots; k++) fprintf(f, "N\t%d\t%s\n", k, names[k]);
    for (fr = 0; fr < MAXF && fr <= frame; fr++) for (k = 0; k < nslots; k++) if (cnt[fr][k]) fprintf(f, "F\t%d\t%d\t%lu\t%.2f\n", fr, k, cnt[fr][k], us_[fr][k]);
    for (fr = 0; fr < MAXF && fr <= frame; fr++) for (k = 0; k < nslots; k++) if (maxus[fr][k] > 500.0f) fprintf(f, "M\t%d\t%d\t%.0f\n", fr, k, maxus[fr][k]);
    for (fr = 0; fr < MAXF && fr < frame; fr++) fprintf(f, "S\t%d\t%.2f\t%.2f\n", fr, swap_us[fr], wall_us[fr]);
    fprintf(f, "SWAPS\t%d\n", frame); fclose(f);
}
static void *(*real_gpa)(const char *) = NULL;
static void *my_gpa(const char *name) {
    if (!real_gpa) real_gpa = (void *(*)(const char *))dlsym(RTLD_NEXT, "SDL_GL_GetProcAddress");
    void *p = real_gpa(name);
    if (!p || strncmp(name, "gl", 2) || nslots >= NSLOT) return p;
    int k; for (k = 0; k < nslots; k++) if (!strcmp(names[k], name)) return wr[k];
    if (!tick_us) { mach_timebase_info_data_t tb; mach_timebase_info(&tb); tick_us = (double)tb.numer / tb.denom / 1000.0; atexit(dump); }
    real[nslots] = p; names[nslots] = strdup(name); return wr[nslots++];
}
static void (*real_swap)(void) = NULL;
static void my_swap(void) {
    if (!real_swap) real_swap = (void (*)(void))dlsym(RTLD_NEXT, "SDL_GL_SwapBuffers");
    uint64_t t0 = mach_absolute_time(); real_swap(); uint64_t t1 = mach_absolute_time();
    if (frame < MAXF) { swap_us[frame] = (double)(t1 - t0) * tick_us; wall_us[frame] = (double)t1 * tick_us; }
    frame++; if (frame % 200 == 0) dump();
}
extern void *SDL_GL_GetProcAddress(const char *); extern void SDL_GL_SwapBuffers(void);
typedef struct { void *replacement; void *replacee; } interpose_t;
__attribute__((used)) static const interpose_t interposers[] __attribute__((section("__DATA,__interpose"))) = {
    { (void*)my_gpa, (void*)SDL_GL_GetProcAddress }, { (void*)my_swap, (void*)SDL_GL_SwapBuffers },
};
