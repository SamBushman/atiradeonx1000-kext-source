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
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef unsigned char byte;
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
#define NAN __builtin_nanf("")
#define STACKARG(off) (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + (off)))
typedef unsigned long long uint64_t_g;
#define true 1
#define false 0
#define CONCAT44(a, b) ((((ulonglong)(unsigned int)(a)) << 32) | (unsigned int)(b))
#define CONCAT22(a, b) ((((unsigned int)(unsigned short)(a)) << 16) | (unsigned short)(b))
#define CONCAT31(a, b) ((((unsigned int)(a)) << 8) | (unsigned char)(b))
#define CONCAT13(a, b) ((((unsigned int)(unsigned char)(a)) << 24) | ((unsigned int)(b) & 0xffffff))
#define CONCAT12(a, b) ((((unsigned int)(unsigned char)(a)) << 16) | (unsigned short)(b))
#define CONCAT21(a, b) ((((unsigned int)(unsigned short)(a)) << 8) | (unsigned char)(b))
#define CONCAT11(a, b) ((((unsigned short)(unsigned char)(a)) << 8) | (unsigned char)(b))
#define CONCAT71(a, b) ((((ulonglong)(a)) << 8) | (unsigned char)(b))
#define CONCAT26(a, b) ((((ulonglong)(unsigned short)(a)) << 48) | ((ulonglong)(b) & 0xffffffffffffULL))
#define SUB41(x, n) ((unsigned char)((x) >> (8 * (n))))
#define SUB42(x, n) ((unsigned short)((x) >> (8 * (n))))
#define SUB84(x, n) ((unsigned int)((x) >> (8 * (n))))
#define SUB81(x, n) ((unsigned char)((x) >> (8 * (n))))
#define SUB21(x, n) ((unsigned char)((x) >> (8 * (n))))
#define ZEXT48(x) ((ulonglong)(unsigned int)(x))
#define ZEXT14(x) ((unsigned int)(unsigned char)(x))
#define ZEXT24(x) ((unsigned int)(unsigned short)(x))
#define ZEXT12(x) ((unsigned short)(unsigned char)(x))
#define ZEXT816(x) (x)
#define SEXT48(x) ((longlong)(int)(x))
#define sync(n) __asm__ __volatile__("sync" ::: "memory")
#define instructionSynchronize() __asm__ __volatile__("isync" ::: "memory")
#define dataCacheBlockFlush(a) __asm__ __volatile__("dcbf 0,%0" :: "r"(a) : "memory")
#define dataCacheBlockStore(a) __asm__ __volatile__("dcbst 0,%0" :: "r"(a) : "memory")
#define dataCacheBlockTouch(a) __asm__ __volatile__("dcbt 0,%0" :: "r"(a) : "memory")
#define enforceInOrderExecutionIO() __asm__ __volatile__("eieio" ::: "memory")
#define trap(x) __asm__ __volatile__("trap")
#define halt_baddata() __builtin_trap()
#endif
