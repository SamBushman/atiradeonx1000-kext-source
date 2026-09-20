/*
 * ATIRadeonX1000_Vers.cpp - the two version records the shipped kext carries in __cstring (Apple's generated vers.c):
 * `_ATIRadeonX1000_VERS_NUM` ("4.1.9") and `_ATIRadeonX1000_VERS_STRING`, the `what`(1) string. Byte-identical to the stock strings.
 */
extern "C" const char ATIRadeonX1000_VERS_NUM[] asm("_ATIRadeonX1000_VERS_NUM") = "4.1.9";
extern "C" const char ATIRadeonX1000_VERS_STRING[] asm("_ATIRadeonX1000_VERS_STRING") = "@(#)PROGRAM:ATIRadeonX1000  PROJECT:GraphicsDrivers  DEVELOPER:ATI  BUILT:Sep 14 2006 00:00:16\n";
