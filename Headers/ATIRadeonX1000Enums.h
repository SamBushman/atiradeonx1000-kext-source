/*
 * ATIRadeonX1000Enums.h
 *
 * The nine enum types that appear in the shipped kext's mangled method signatures. They must be real enum
 * types with exactly these names, because the C++ ABI encodes a parameter's enum name in the mangled symbol
 * (`...20eIOGLContextModeBits...`): declaring them as plain integers produces a different symbol, a different
 * overload, and (for virtual methods) a different vtable entry name than the stock driver's.
 *
 * The enumerators' real values were never recovered (the driver only ever tests raw bit masks on them), so each
 * enum carries a single placeholder enumerator; every use converts to and from an integer with a cast.
 * Discovered by demangling every symbol in the stock kext (Ledger/kext_ppc_ledger.tsv).
 */
#ifndef ATIRADEONX1000ENUMS_H
#define ATIRADEONX1000ENUMS_H

enum eDoSwap                  { eDoSwap_unused = 0 };
enum eIOAccelSurfaceShapeBits { eIOAccelSurfaceShapeBits_unused = 0 };
enum eIOAccelSurfaceStateBits { eIOAccelSurfaceStateBits_unused = 0 };
enum eIOContextModeBits       { eIOContextModeBits_unused = 0 };
enum eIODVDContextModeBits    { eIODVDContextModeBits_unused = 0 };
enum eIOGLContextModeBits     { eIOGLContextModeBits_unused = 0 };
enum eIOSurfaceModeBits       { eIOSurfaceModeBits_unused = 0 };
enum eLockType                { eLockType_unused = 0 };
enum eSurfaceVolatileState    { eSurfaceVolatileState_unused = 0 };

#endif /* ATIRADEONX1000ENUMS_H */
