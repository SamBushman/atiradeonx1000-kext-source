/*
 * GhidraCompat.h - helpers for the mechanically ported (Tools/ghidra2cpp.py) function bodies.
 *
 * M<T>(addr)       typed memory access at a byte address (`*(T *)addr` in the decompile)
 * VCALL(vt, off)   raw C++ vtable dispatch `(**(code **)(vt + off))` - a variadic UInt32-returning function pointer
 * CONCAT44d(a, b)  the double whose IEEE bits are a:b - the shipped int/uint -> double conversion idiom
 * FBITS(f)         the 32 bits of a float (Ghidra shows a float stored into an `undefined4` slot as `= (float)x`)
 * SUB41m(x, n)     low byte of a wider value
 */
#ifndef GHIDRACOMPAT_H
#define GHIDRACOMPAT_H

#include "ATIRadeonX1000Types.h"

template <class T, class A> inline T &M(A address) { return *reinterpret_cast<T *>(static_cast<UInt32>(reinterpret_cast<unsigned long>(address))); }
template <class T> inline T &M(int address) { return *reinterpret_cast<T *>(address); }
template <class T> inline T &M(unsigned int address) { return *reinterpret_cast<T *>(address); }
template <class T> inline T &M(long address) { return *reinterpret_cast<T *>(address); }
template <class T> inline T &M(unsigned long address) { return *reinterpret_cast<T *>(address); }

typedef UInt32 (*GhidraVFn)(...);
typedef UInt32 code(...);   /* Ghidra's `code` (a function of unknown signature): `code *p` is a pointer to a variadic function */
#define VCALL(vt, off) ((GhidraVFn)(*reinterpret_cast<UInt32 *>(static_cast<UInt32>((vt)) + (off))))

inline double CONCAT44d(UInt32 hi, UInt32 lo) {
    union { UInt32 w[2]; double d; } u;
    u.w[0] = hi;
    u.w[1] = lo;
    return u.d;
}
inline UInt32 FBITS(float f) {
    union { float f; UInt32 w; } u;
    u.f = f;
    return u.w;
}
extern "C" void *memcpy(void *, const void *, unsigned long);
/* the shipped code's _memcpy stub: the destination is a raw address or a pointer */
template <class T> inline void GCopy(T dst, const void *src, UInt32 n) { memcpy((void *)(dst), src, n); }
inline UInt16 CONCAT11(UInt8 hi, UInt8 lo) { return static_cast<UInt16>((static_cast<UInt16>(hi) << 8) | lo); }
inline UInt32 CONCAT22(UInt16 hi, UInt16 lo) { return (static_cast<UInt32>(hi) << 16) | lo; }
#define SUB41m(x, n) (static_cast<UInt8>((x) >> (8 * (n))))

#endif
