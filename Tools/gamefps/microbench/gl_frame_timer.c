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
#define NSLOT 160
#define MAXF 4000
typedef unsigned long W;
static void *real[NSLOT]; static char *names[NSLOT]; static int nslots = 0;
static unsigned long cnt[MAXF][NSLOT]; static double us_[MAXF][NSLOT];
static double swap_us[MAXF]; static double wall_us[MAXF]; static int frame = 0; static double tick_us = 0;
typedef W (*fn_t)(W,W,W,W,W,W,W,W,W,W,W,W,double,double,double,double,double,double,double,double,double,double,double,double,double);
#define ARGS W a0,W a1,W a2,W a3,W a4,W a5,W a6,W a7,W a8,W a9,W a10,W a11,double d1,double d2,double d3,double d4,double d5,double d6,double d7,double d8,double d9,double d10,double d11,double d12,double d13
static inline W go(int k, ARGS) {
    uint64_t t0 = mach_absolute_time();
    W r = ((fn_t)real[k])(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,d12,d13);
    uint64_t t1 = mach_absolute_time();
    if (frame < MAXF) { cnt[frame][k]++; us_[frame][k] += (double)(t1 - t0) * tick_us; }
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
static void *wr[NSLOT] = {(void*)w0,(void*)w1,(void*)w2,(void*)w3,(void*)w4,(void*)w5,(void*)w6,(void*)w7,(void*)w8,(void*)w9,(void*)w10,(void*)w11,(void*)w12,(void*)w13,(void*)w14,(void*)w15,(void*)w16,(void*)w17,(void*)w18,(void*)w19,(void*)w20,(void*)w21,(void*)w22,(void*)w23,(void*)w24,(void*)w25,(void*)w26,(void*)w27,(void*)w28,(void*)w29,(void*)w30,(void*)w31,(void*)w32,(void*)w33,(void*)w34,(void*)w35,(void*)w36,(void*)w37,(void*)w38,(void*)w39,(void*)w40,(void*)w41,(void*)w42,(void*)w43,(void*)w44,(void*)w45,(void*)w46,(void*)w47,(void*)w48,(void*)w49,(void*)w50,(void*)w51,(void*)w52,(void*)w53,(void*)w54,(void*)w55,(void*)w56,(void*)w57,(void*)w58,(void*)w59,(void*)w60,(void*)w61,(void*)w62,(void*)w63,(void*)w64,(void*)w65,(void*)w66,(void*)w67,(void*)w68,(void*)w69,(void*)w70,(void*)w71,(void*)w72,(void*)w73,(void*)w74,(void*)w75,(void*)w76,(void*)w77,(void*)w78,(void*)w79,(void*)w80,(void*)w81,(void*)w82,(void*)w83,(void*)w84,(void*)w85,(void*)w86,(void*)w87,(void*)w88,(void*)w89,(void*)w90,(void*)w91,(void*)w92,(void*)w93,(void*)w94,(void*)w95,(void*)w96,(void*)w97,(void*)w98,(void*)w99,(void*)w100,(void*)w101,(void*)w102,(void*)w103,(void*)w104,(void*)w105,(void*)w106,(void*)w107,(void*)w108,(void*)w109,(void*)w110,(void*)w111,(void*)w112,(void*)w113,(void*)w114,(void*)w115,(void*)w116,(void*)w117,(void*)w118,(void*)w119,(void*)w120,(void*)w121,(void*)w122,(void*)w123,(void*)w124,(void*)w125,(void*)w126,(void*)w127,(void*)w128,(void*)w129,(void*)w130,(void*)w131,(void*)w132,(void*)w133,(void*)w134,(void*)w135,(void*)w136,(void*)w137,(void*)w138,(void*)w139,(void*)w140,(void*)w141,(void*)w142,(void*)w143,(void*)w144,(void*)w145,(void*)w146,(void*)w147,(void*)w148,(void*)w149,(void*)w150,(void*)w151,(void*)w152,(void*)w153,(void*)w154,(void*)w155,(void*)w156,(void*)w157,(void*)w158,(void*)w159};

static void dump(void) {
    const char *o = getenv("GLT_OUT"); FILE *f = o ? fopen(o, "w") : NULL; int fr, k; if (!f) return;
    for (k = 0; k < nslots; k++) fprintf(f, "N\t%d\t%s\n", k, names[k]);
    for (fr = 0; fr < MAXF && fr <= frame; fr++) for (k = 0; k < nslots; k++) if (cnt[fr][k]) fprintf(f, "F\t%d\t%d\t%lu\t%.2f\n", fr, k, cnt[fr][k], us_[fr][k]);
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
