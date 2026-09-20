/* ATIR500SurfaceOverlayTables.h - data tables read by the overlay-scaler code; content in Sources/ATIR500Surface_OverlayTables.cpp */
#ifndef ATIR500SURFACEOVERLAYTABLES_H
#define ATIR500SURFACEOVERLAYTABLES_H
#include "ATIRadeonX1000Types.h"

extern const UInt32 kMode1314Table[63] asm("_Mode1314Table");
extern const UInt32 kMode1112Table[56] asm("_Mode1112Table");
extern const UInt32 kMode10Table[84] asm("_Mode10Table");
extern const UInt32 kMode9Table[84] asm("_Mode9Table");
extern const UInt32 kMode6Table[56] asm("_Mode6Table");
extern const UInt32 kMode34Table[35] asm("_Mode34Table");
extern const UInt32 kFilterSetupArrayOfSets[608] asm("_FilterSetupArrayOfSets");
extern "C" const double CO[14];

#endif
