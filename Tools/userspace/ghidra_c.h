/* ghidra_c.h - the type/intrinsic vocabulary of Ghidra's C decompiler output, so the userspace corpus compiles as plain C
 * (gcc 4.0.1, -w). Function names, offsets and control flow are exactly as decompiled; nothing is re-interpreted. */
#ifndef GHIDRA_C_H
#define GHIDRA_C_H
typedef unsigned char undefined;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined3;
typedef unsigned int undefined4;
typedef unsigned long long undefined8;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned int vm_size_t;
typedef unsigned int vm_map_t;
typedef unsigned int ipc_space_t;   /* = mach_port_t; GLEngine _gliGetVersion mach_port_deallocate(mach_task_self(), host): without this ghidra2c turned `*(ipc_space_t *)` into a BYTE load of the task port */
typedef unsigned int mach_port_t;
typedef unsigned int mach_msg_type_number_t;
typedef int kern_return_t;
typedef int integer_t;
typedef unsigned int vm_address_t;   /* Mach VM address (GLEngine _gleOptimizedListFreeFunc casts to it for vm_deallocate); same width as a PPC32 pointer */
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef unsigned char byte;
typedef signed char sbyte;
typedef unsigned short word;
typedef unsigned char bool;
typedef long long longlong;
typedef unsigned long long ulonglong;
typedef int code();
typedef unsigned long size_t;
typedef int int3;
typedef unsigned int uint3;
typedef int pid_t;
typedef unsigned int dword;
typedef unsigned int uid_t;
typedef unsigned int gid_t;
typedef long time_t;
typedef long off_t;
typedef unsigned short mode_t;
typedef void BADSPACEBASE;
typedef struct { long __sig; char __opaque[40]; } pthread_mutex_t;
typedef struct { long __sig; char __opaque[24]; } pthread_cond_t;
typedef struct _opaque_pthread_t { long __sig; void *__cleanup_stack; char __opaque[596]; } *pthread_t;
typedef unsigned long pthread_key_t;
typedef struct { long __sig; char __opaque[4]; } pthread_once_t;
typedef struct { unsigned char opaque[8]; } pthread_mutexattr_t;
typedef struct { unsigned int magic, cputype, cpusubtype, filetype, ncmds, sizeofcmds, flags; } MACH_HEADER_t;
#define NAN(x) __builtin_isnan(x)
typedef long double longdouble;
typedef char *va_list;
typedef struct { unsigned char opaque[88]; } FILE;
typedef struct { char sectname[16]; char segname[16]; unsigned int addr, size, offset, align, reloff, nreloc, flags, reserved1, reserved2; } GhidraMachOSection;
typedef GhidraMachOSection section;
typedef struct { unsigned int cmd, cmdsize; char segname[16]; unsigned int vmaddr, vmsize, fileoff, filesize, maxprot, initprot, nsects, flags; } GhidraMachOCommand;
typedef GhidraMachOCommand segment_command;
typedef GhidraMachOCommand load_command;
typedef struct { unsigned int offset; } lc_str;
typedef struct { lc_str name; unsigned int timestamp, current_version, compatibility_version; } dylib;   /* Ghidra fits Mach-O types to stack records of the same size */
#define CARRY4(a, b) (((unsigned int)(a) + (unsigned int)(b)) < (unsigned int)(a))
#define CARRY2(a, b) (((unsigned short)((a) + (b))) < (unsigned short)(a))
#define CARRY1(a, b) (((unsigned char)((a) + (b))) < (unsigned char)(a))
#define SCARRY4(a, b) ((((int)(a) >= 0) == ((int)(b) >= 0)) && (((int)(a) >= 0) != (((int)(a) + (int)(b)) >= 0)))
#define SCARRY2(a, b) 0
#define SCARRY1(a, b) 0
#define SBORROW4(a, b) ((((int)(a) >= 0) != ((int)(b) >= 0)) && (((int)(a) >= 0) != (((int)(a) - (int)(b)) >= 0)))
#define SBORROW2(a, b) 0
#define SBORROW1(a, b) 0
#define LOCK() ((void)0)
#define UNLOCK() ((void)0)
#define ROUND(x) ((int)((x) + 0.5))
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define INT2FLOAT(x) ((double)(x))
#define FLOAT2FLOAT(x) ((double)(x))
#define TRUNC(x) ((int)(x))
#define POPCOUNT(x) __builtin_popcount(x)
#define LZCOUNT(x) ({ unsigned int lz_in__ = (unsigned int)(x), lz_out__; __asm__("cntlzw %0,%1" : "=r"(lz_out__) : "r"(lz_in__)); lz_out__; })   /* cntlzw: 32 for 0 (GLEngine: 17 sites; undefined, the call became an unresolved external) */
#define BREAK() __builtin_trap()
#define STACKARG(off) (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + (off)))
typedef unsigned long long uint64_t_g;
#define true 1
#define false 0
/* a float-typed piece of a CONCAT44 is the WORD holding the float (a 64-bit store of two floats: FUN_0009f0b0's `*(ulonglong *)p = CONCAT44(f0, f1)`): its bits, not its value */
#define GH_FLT_T(x) __builtin_types_compatible_p(__typeof__(x), float)
#define GH_W4(x) __builtin_choose_expr(GH_FLT_T(x), GH_F2U(__builtin_choose_expr(GH_FLT_T(x), (x), 0.0f)), (unsigned int)(x))
#define CONCAT44(a, b) ((((ulonglong)GH_W4(a)) << 32) | GH_W4(b))
#define CONCAT22(a, b) ((((unsigned int)(unsigned short)(a)) << 16) | (unsigned short)(b))
#define CONCAT31(a, b) ((((unsigned int)(a)) << 8) | (unsigned char)(b))
#define CONCAT13(a, b) ((((unsigned int)(unsigned char)(a)) << 24) | ((unsigned int)(b) & 0xffffff))
#define CONCAT12(a, b) ((((unsigned int)(unsigned char)(a)) << 16) | (unsigned short)(b))
#define CONCAT21(a, b) ((((unsigned int)(unsigned short)(a)) << 8) | (unsigned char)(b))
#define CONCAT11(a, b) ((((unsigned short)(unsigned char)(a)) << 8) | (unsigned char)(b))
#define CONCAT71(a, b) ((((ulonglong)(a)) << 8) | (unsigned char)(b))
#define CONCAT42(a, b) ((((ulonglong)(unsigned int)(a)) << 16) | (unsigned short)(b))
#define CONCAT62(a, b) ((((ulonglong)(a)) << 16) | (unsigned short)(b))
#define CONCAT26(a, b) ((((ulonglong)(unsigned short)(a)) << 48) | ((ulonglong)(b) & 0xffffffffffffULL))
#define GBITS(x) __builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), float), ({ __typeof__(x) _gv = (x); *(unsigned int *)&_gv; }), (x))
#define SUB41(x, n) ((unsigned char)(((unsigned long)GBITS(x)) >> (8 * (n))))
#define SUB42(x, n) ((unsigned short)(((unsigned long)GBITS(x)) >> (8 * (n))))
#define GBITS8(x) __builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), double), ({ __typeof__(x) _gd = (x); *(unsigned long long *)&_gd; }), (x))
#define SUB84(x, n) ((unsigned int)((GBITS8(x)) >> (8 * (n))))   /* a double operand is taken by its bit pattern (GLEngine _glClearDepth_Exec stores its parameter with stfd) */
#define SUB81(x, n) ((unsigned char)((x) >> (8 * (n))))
#define SUB21(x, n) ((unsigned char)((x) >> (8 * (n))))
#define ZEXT48(x) ((ulonglong)(unsigned int)(x))
#define ZEXT14(x) ((unsigned int)(unsigned char)(x))
#define ZEXT24(x) ((unsigned int)(unsigned short)(x))
#define ZEXT12(x) ((unsigned short)(unsigned char)(x))
/* libgcc/libstdc++ unwinder types Ghidra's own type archive supplies (layouts derived from the disassembly: sizeof(_Unwind_Exception)==32,
   `param[-2].reserved[2]` is __cxa_exception::terminateHandler) */
typedef struct _Unwind_Exception { unsigned long long exception_class; void (*exception_cleanup)(); unsigned long private_1, private_2; unsigned long reserved[3]; } __attribute__((aligned(16))) _Unwind_Exception;
typedef struct dwarf_eh_bases { void *tbase, *dbase, *func; } dwarf_eh_bases;
typedef struct { unsigned char v[16]; } vec16;   /* AltiVec 128-bit register */
extern vec16 vectorPermute(), vectorConditionalSelect();
#define ZEXT816(x) (x)
#define SEXT48(x) ((longlong)(int)(x))
#define sync(n) __asm__ __volatile__("sync" ::: "memory")
#define instructionSynchronize() __asm__ __volatile__("isync" ::: "memory")
#define dataCacheBlockFlush(a) __asm__ __volatile__("dcbf 0,%0" :: "r"(a) : "memory")
#define dataCacheBlockStore(a) __asm__ __volatile__("dcbst 0,%0" :: "r"(a) : "memory")
#define dataCacheBlockTouch(a) __asm__ __volatile__("dcbt 0,%0" :: "r"(a) : "memory")
/* lwarx/stwcx. atomic add: Ghidra shows the inline `lwarx rD,0,rP; add rT,rD,rK; stwcx. rT,0,rP; bne- retry` loop as a call to the pseudo-function
 * storeWordConditionalIndexed plus an unwritten `reservation` flag and a hand-made retry loop (`if (reservation != 0) {...; crBits = 2;}`), which compiled as a call to a
 * symbol that exists nowhere and read uninitialized variables. atomicAddWord(p, d) adds d to the word at p
 * atomically and yields the word's OLD value (the lwarx result), exactly what the stock loop leaves in rD. */
#define atomicAddWord(p, d) ({ int *aaw_p__ = (int *)(p); int aaw_old__, aaw_new__; \
  __asm__ __volatile__("1: lwarx %0,0,%2\n\tadd %1,%0,%3\n\tstwcx. %1,0,%2\n\tbne- 1b" : "=&r"(aaw_old__), "=&r"(aaw_new__) : "r"(aaw_p__), "r"((int)(d)) : "cr0", "memory"); \
  aaw_old__; })
#define enforceInOrderExecutionIO() __asm__ __volatile__("eieio" ::: "memory")
#define trap(x) __asm__ __volatile__("trap")
#define halt_baddata() __builtin_trap()
#endif
/* bit reinterpretation between a float and a 32-bit word (ghidra2c fix_float_int: casts that are only Ghidra's typing of a union word or a
   pointer held in a float-typed variable) */
static inline unsigned int GH_F2U(float f) { union { float f; unsigned int u; } x; x.f = f; return x.u; }
static inline float GH_U2F(unsigned int u) { union { unsigned int u; float f; } x; x.u = u; return x.f; }

/* glAccum_impl (16-bit accumulation store: 15-bit magnitude, 32767 == 1.0): saturating helpers. GH_SAT16 clamps an int to the signed 16-bit range (accumulation
 * is a saturating fixed-point store, not a wrapping one); GH_SAT16D is the same for a double (truncates toward zero like a C cast, clamps first so an
 * out-of-range double is never converted); GH_FIX16 converts a GL accumulation operand to the store's fixed-point scale, rounding to nearest and
 * bounding |x| to 2.0 (65536) so that operand * 15-bit sample cannot overflow an int. */
static inline int GH_SAT16(int x) { if (x > 32767) return 32767; if (x < -32768) return -32768; return x; }
static inline int GH_SAT16D(double d) { if (d >= 32767.0) return 32767; if (d <= -32768.0) return -32768; return (int)d; }
static inline int GH_FIX16(double d) { if (d >= 65536.0) return 65536; if (d <= -65536.0) return -65536; return (int)(d < 0.0 ? d - 0.5 : d + 0.5); }
