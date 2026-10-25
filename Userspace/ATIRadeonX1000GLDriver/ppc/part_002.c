#include "decls.h"

/* gld_textureVariantClass @ 0xa2f0 (184 bytes) */
int gld_textureVariantClass(variantCode, variantFlags)
  undefined4 variantCode;
  uint variantFlags;
{
  switch(variantCode) {
  case 0x400:
  case 0x404:
  case 0x406:
    goto switchD_0000a324_caseD_400;
  case 0x401:
  case 0x407:
    if ((variantFlags & 0x10) == 0) {
      return 1;
    }
    return 3;
  case 0x403:
    if ((variantFlags & 0x400) == 0) {
      return 1;
    }
    if ((variantFlags & 0x10) == 0) {
      return 0;
    }
    return 2;
  case 0x409:
    if (0xff < (variantFlags & 0x300)) {
      return 7;
    }
    break;
  case 0x40a:
    if (0x1ff < (variantFlags & 0x300)) {
      return 8;
    }
    break;
  case 0x40b:
    if (0x2ff < (variantFlags & 0x300)) {
      return 9;
    }
  }
  if ((variantFlags & 0x400) != 0) {
    return 0;
  }
switchD_0000a324_caseD_400:
  return 1;
}

/* gldPixelUnitBytes @ 0xa3f0 (592 bytes) */
int gldPixelUnitBytes(format, pixelType)
  uint format;
  undefined *pixelType;
{
  if (pixelType == (undefined *)0x1a00) {
    return 1;
  }
  if (pixelType < (undefined *)0x1a01) {
    if (((unsigned char *)0x00001403) < pixelType) {
      if (pixelType < ((unsigned char *)0x00001407)) {
        if (format == 0x1909) {
          return 4;
        }
        if (format < 0x190a) {
          if (0x18ff < format) {
            if (format < 0x1907) {
              return 4;
            }
            if (format == 0x1907) {
              return 0xc;
            }
          }
          return 0x10;
        }
        if (format == 0x8049) {
          return 4;
        }
        if (format < 0x804a) {
          if (format == 0x190a) {
            return 8;
          }
          return 0x10;
        }
        if (format == 0x80e0) {
          return 0xc;
        }
        if (format == 0x85b9) {
          return 8;
        }
        return 0x10;
      }
      if (pixelType != ((unsigned char *)0x0000140b)) {
        return 4;
      }
    }
    else if (pixelType < ((unsigned char *)0x00001402)) {
      if (pixelType == (undefined *)0x0) {
        if (1 < format - 0x83f0) {
          return 0x10;
        }
        return 8;
      }
      if (pixelType <= ((unsigned char *)0x000013ff)) {
        return 4;
      }
      if (format == 0x1909) {
        return 1;
      }
      if (format < 0x190a) {
        if (format < 0x1900) {
          return 4;
        }
        if (0x1906 < format) {
          if (format != 0x1907) {
            return 4;
          }
          return 3;
        }
        return 1;
      }
      if (format == 0x8049) {
        return 1;
      }
      if (format < 0x804a) {
        if (format == 0x190a) {
          return 2;
        }
        return 4;
      }
      if (format == 0x80e0) {
        return 3;
      }
      if (format == 0x85b9) {
        return 2;
      }
      return 4;
    }
    if (format != 0x1909) {
      if (format < 0x190a) {
        if (0x18ff < format) {
          if (format < 0x1907) {
            return 2;
          }
          if (format == 0x1907) {
            return 6;
          }
        }
        return 8;
      }
      if (format != 0x8049) {
        if (format < 0x804a) {
          if (format != 0x190a) {
            return 8;
          }
        }
        else {
          if (format == 0x80e0) {
            return 6;
          }
          if (format != 0x85b9) {
            return 8;
          }
        }
        return 4;
      }
    }
  }
  else {
    if (pixelType == (undefined *)0x8362) {
      return 1;
    }
    if (pixelType < (undefined *)0x8363) {
      if (pixelType == (undefined *)0x8032) {
        return 1;
      }
      if (pixelType < (undefined *)0x8032) {
        return 4;
      }
      if ((undefined *)0x8034 < pixelType) {
        return 4;
      }
    }
    else if (((undefined *)0x8366 < pixelType) && ((undefined *)0x1 < pixelType + -0x85ba)) {
      return 4;
    }
  }
  return 2;
}

/* gldPixelRowBytes @ 0xa670 (100 bytes) */
int gldPixelRowBytes(format, pixelType, width)
  undefined4 format;
  int pixelType;
  int width;
{
  int iVar1;
  
  if (pixelType == 0) {
    iVar1 = ((int (*)())gldPixelUnitBytes)(format,0);
    iVar1 = iVar1 * (width + 3 >> 2) >> 2;
  }
  else if (pixelType == 0x1a00) {
    iVar1 = width + 7 >> 3;
  }
  else {
    iVar1 = ((int (*)())gldPixelUnitBytes)(format,pixelType);
    iVar1 = iVar1 * width;
  }
  return iVar1;
}

/* gld_computePixelStoreLayout @ 0xa6e0 (292 bytes) */
int gld_computePixelStoreLayout(ctx, format, pixelType, width, height, rowBytesOut, unitBytesOut, packOffsets, pixelStore)
  undefined4 ctx;
  undefined4 format;
  int pixelType;
  undefined4 width;
  int height;
  uint *rowBytesOut;
  int *unitBytesOut;
  int *packOffsets;
  int *pixelStore;
{
  int imageHeight;
  int alignRemainder;
  uint alignment;
  int unitBytes;
  uint rowBytes;
  int rowLength;
  
  unitBytes = ((int (*)())gldPixelUnitBytes)(format,pixelType);
  *unitBytesOut = unitBytes;
  if (pixelStore == (int *)0x0) {
    *packOffsets = 0;
    rowBytes = ((int (*)())gldPixelRowBytes)(format,pixelType,width);
    *rowBytesOut = rowBytes;
  }
  else {
    rowLength = *pixelStore;
    if (rowLength < 1) {
      rowBytes = ((int (*)())gldPixelRowBytes)(format,pixelType,width);
    }
    else if (pixelType == 0x1a00) {
      rowBytes = rowLength + 7 >> 3;
    }
    else {
      rowBytes = unitBytes * rowLength;
    }
    alignment = pixelStore[5];
    alignRemainder = rowBytes - (rowBytes / alignment) * alignment;
    if (alignRemainder != 0) {
      rowBytes = rowBytes + (alignment - alignRemainder);
    }
    *rowBytesOut = rowBytes;
    imageHeight = pixelStore[1];
    if (pixelStore[1] < 1) {
      imageHeight = height;
    }
    if (pixelType == 0x1a00) {
      unitBytes = pixelStore[3] >> 3;
    }
    else {
      unitBytes = unitBytes * pixelStore[3];
    }
    *packOffsets = unitBytes + rowBytes * pixelStore[2] + rowBytes * imageHeight * pixelStore[4];
  }
  return;
}

/* gld_resolveBoundTextures @ 0xa820 (452 bytes) */
int gld_resolveBoundTextures(ctx, unitMask, staleArgR5, staleArgR6, staleArgR7, staleArgR8)
  int ctx;
  uint unitMask;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
{
  int texture;
  int unitObjectCursor;
  int engineObjects;
  bool isLastUnit;
  bool noProgramMasks;
  uint targetSlot;
  int makeResidentResult;
  int *currentProgram;
  uint programMaskHigh;
  uint programMaskLow;
  int unitObjectOffset;
  int unitStateOffset;
  int unitIndex;
  int targetsLeft;
  
  engineObjects = *(int *)(ctx + 0x18);
  currentProgram = *(int **)(engineObjects + 0x19c);
  if ((currentProgram == (int *)0x0) &&
     (((((unsigned char *)0x0000430c)[*(int *)(ctx + 0x10)] == '\0' ||
       (*(undefined4 **)(engineObjects + 400) == (undefined4 *)0x0)) ||
      (*(short *)**(undefined4 **)(engineObjects + 400) != -0x77fc)))) {
    programMaskHigh = 0;
    programMaskLow = 0;
    noProgramMasks = true;
  }
  else {
    noProgramMasks = false;
    if (currentProgram == (int *)0x0) {
      unitMask = 0xffffffff;
      programMaskHigh = *(uint *)(**(int **)(engineObjects + 400) + 8);
      programMaskLow = *(uint *)(**(int **)(engineObjects + 400) + 0xc);
    }
    else {
      unitMask = 0xffffffff;
      programMaskHigh = *(uint *)(*currentProgram + 8);
      programMaskLow = *(uint *)(*currentProgram + 0xc);
    }
  }
  unitIndex = 0;
  unitObjectOffset = 0;
  unitStateOffset = 0;
  unitObjectCursor = ctx;
  do {
    if ((unitMask & 1) != 0) {
      if (noProgramMasks) {
        targetSlot = 0;
        targetsLeft = 5;
        do {
          if ((*(uint *)(((unsigned char *)0x000031d4) + unitStateOffset + *(int *)(ctx + 0x10)) & 1 << (targetSlot & 0x3f))
              != 0) goto LAB_0000a96c;
          targetSlot = targetSlot + 1;
          targetsLeft = targetsLeft + -1;
        } while (targetsLeft != 0);
LAB_0000a924:
        texture = 0;
      }
      else {
        targetSlot = unitIndex * 4 - 0x20;
        if ((int)targetSlot < 0) {
          targetSlot = (programMaskHigh << 1) << (unitIndex * -4 + 0x1fU & 0x3f) | programMaskLow >> (unitIndex * 4 & 0x3cU);
        }
        else {
          targetSlot = programMaskHigh >> (targetSlot & 0x3f);
        }
        targetSlot = targetSlot & 0xf;
        if (4 < targetSlot) goto LAB_0000a924;
LAB_0000a96c:
        texture = *(int *)(unitObjectOffset + *(int *)(ctx + 0x18) + targetSlot * 4);
        if ((*(short *)(*(int *)(texture + 0x30) + 0x5c) == 0) ||
           (((*(byte *)(texture + 0x39) & 0x87) != 0 &&
            (makeResidentResult = gldTextureMakeResident(ctx,texture,staleArgR5,staleArgR6,staleArgR7,staleArgR8), makeResidentResult == 0))))
        goto LAB_0000a924;
      }
      *(int *)(unitObjectCursor + 0x18c) = texture;
    }
    isLastUnit = unitIndex == 0xf;
    unitStateOffset = unitStateOffset + 0x7c;
    unitObjectOffset = unitObjectOffset + 0x14;
    unitMask = unitMask >> 1;
    unitObjectCursor = unitObjectCursor + 4;
    unitIndex = unitIndex + 1;
    if (isLastUnit) {
      return;
    }
  } while( true );
}

/* gld_textureMemoryBytes @ 0xa9f0 (244 bytes) */
int gld_textureMemoryBytes(ctx, texture)
  undefined4 ctx;
  int texture;
{
  uint depth;
  int bytesScale;
  int totalTexels;
  uint totalBytes;
  uint border;
  int baseLevel;
  uint height;
  uint width;
  int levelsLeft;
  
  baseLevel = *(int *)(texture + 0x30);
  levelsLeft = 0xc;
  border = (uint)*(byte *)(baseLevel + 0xaa);
  width = (uint)*(ushort *)(baseLevel + 0xa4) + border * -2;
  height = (uint)*(ushort *)(baseLevel + 0xa6) - border * *(byte *)(baseLevel + 0x6e);
  depth = (uint)*(ushort *)(baseLevel + 0xa8) - border * *(byte *)(baseLevel + 0x6f);
  totalTexels = depth * width * height;
  do {
    if ((((width == 1) && (height == 1)) && (depth == 1)) || (*(ushort *)(baseLevel + 0x5c) < 0x2602))
    break;
    width = width >> 1;
    if (width == 0) {
      width = 1;
    }
    height = height >> 1;
    if (height == 0) {
      height = 1;
    }
    depth = depth >> 1;
    if (depth == 0) {
      depth = 1;
    }
    totalTexels = totalTexels + depth * width * height;
    levelsLeft = levelsLeft + -1;
  } while (levelsLeft != 0);
  totalBytes = (uint)*(byte *)(baseLevel + 0x6c) * totalTexels;
  bytesScale = FUN_00030f00(ctx,texture);
  if (bytesScale < 0) {
    totalBytes = totalBytes / (uint)-bytesScale;
  }
  else {
    totalBytes = totalBytes * bytesScale;
  }
  return totalBytes;
}

/* gld_waitTextureStamp @ 0xaaf0 (244 bytes) */
int gld_waitTextureStamp(ctx, texture)
  int ctx;
  int texture;
{
  int retired;
  undefined4 connection;
  int resident;
  
  resident = *(int *)(texture + 0x34);
  if (resident != 0) {
    if (*(char *)(resident + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(resident + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(resident + 8));
      if (retired == 0) {
        connection = *(undefined4 *)(ctx + GLD_connect);
        resident = resident + 8;
LAB_0000abac:
        _io_connect_method_scalarI_structureI(connection,9,resident,1,0,0);
        return;
      }
    }
    else if (*(char *)(resident + 0x16) == '\a') {
      if (0x1ffff < *(int *)(resident + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(resident + 0xc));
      if (retired == 0) {
        connection = *(undefined4 *)(ctx + GLD_connect);
        resident = resident + 0xc;
        goto LAB_0000abac;
      }
    }
  }
  return;
}

/* FUN_0000abf0 @ 0xabf0 (184 bytes) */
int FUN_0000abf0(ctx, texture)
  undefined4 ctx;
  int texture;
{
  undefined4 retired;
  int resident;
  
  resident = *(int *)(texture + 0x34);
  if (resident != 0) {
    if (*(char *)(resident + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(resident + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(resident + 8));
      return retired;
    }
    if (*(char *)(resident + 0x16) == '\a') {
      if (0x1ffff < *(int *)(resident + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(resident + 0xc));
      return retired;
    }
  }
  return 1;
}

/* gld_ensureTextureBackingSized2 @ 0xacb0 (568 bytes) */
int gld_ensureTextureBackingSized2(ctx, texture, requestArg0, requestArg1)
  int ctx;
  undefined4 *texture;
  int requestArg0;
  int requestArg1;
{
  int *newRefCountPtr;
  int newRefCountStored;
  int status;
  int backingCursor;
  int texImages;
  int gld_isStampRetiredResult;
  bool masksCovered;
  ushort *backingMaskPtrB;
  ushort *backingMaskPtrA;
  ushort *texImagesMaskPtr;
  int *oldRefCountPtr;
  uint maskCount;
  int oldRefCountStored;
  undefined4 succeeded;
  int oldRefCountValue;
  int currentBacking;
  char reservation;
  byte cr0Bits;
  undefined4 outSize;
  undefined4 outHandle;
  int newBacking;
  
  currentBacking = texture[0xd];
  if ((((currentBacking == 0) || (*(char *)(currentBacking + 0x16) != '\x03')) || (requestArg0 != texture[2])) ||
     (requestArg1 != texture[3])) {
LAB_0000adc0:
    *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) | 1;
    if (currentBacking != 0) {
      oldRefCountPtr = (int *)(currentBacking + 0x10);
      do {
        oldRefCountValue = *oldRefCountPtr;
        if (reservation != '\0') {
          oldRefCountStored = storeWordConditionalIndexed(oldRefCountValue + -0x10000,0,oldRefCountPtr);
          *oldRefCountPtr = oldRefCountStored;
          cr0Bits = 2;
        }
      } while (!(bool)(cr0Bits >> 1 & 1));
      if (oldRefCountValue == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),0xb,currentBacking,1,0,0);
      }
      texture[0xd] = 0;
    }
    texture[2] = requestArg0;
    texture[3] = requestArg1;
    texture[1] = 3;
    outSize = 8;
    status = _io_connect_method_structureI_structureO
                       (*(undefined4 *)(ctx + 4),10,texture + 1,0x14,&outHandle,&outSize);
    succeeded = 0;
    if (status == 0) {
      texture[0xd] = newBacking;
      newRefCountPtr = (int *)(newBacking + 0x10);
      do {
        if (reservation != '\0') {
          newRefCountStored = storeWordConditionalIndexed(*newRefCountPtr + 0x10000,0,newRefCountPtr);
          *newRefCountPtr = newRefCountStored;
          cr0Bits = 2;
        }
      } while (!(bool)(cr0Bits >> 1 & 1));
      succeeded = 1;
      *texture = outHandle;
      *(undefined1 *)(newBacking + 0x14) = 1;
    }
  }
  else {
    texImages = texture[0xc];
    if (0x1ffff < *(int *)(currentBacking + 0x10)) {
      _gldFlush(ctx);
    }
    maskCount = (uint)*(byte *)(texImages + 0x6c);
    if (maskCount == 0) {
LAB_0000ad38:
      gld_isStampRetiredResult = gld_isStampRetired(ctx,*(undefined4 *)(currentBacking + 0xc));
      if (gld_isStampRetiredResult == 0) goto LAB_0000adc0;
    }
    else {
      if ((ushort)((*(ushort *)(currentBacking + 0x1c) | *(ushort *)(currentBacking + 0x28)) &
                  ~*(ushort *)(texImages + 0x7c)) == 0) {
        cr0Bits = 2;
        backingCursor = currentBacking;
        if (maskCount == 0) {
          maskCount = 1;
        }
        do {
          maskCount = maskCount - 1;
          if (maskCount == 0) goto LAB_0000ad38;
          backingMaskPtrB = (ushort *)(backingCursor + 0x2a);
          backingMaskPtrA = (ushort *)(backingCursor + 0x1e);
          backingCursor = backingCursor + 2;
          texImagesMaskPtr = (ushort *)(texImages + 0x7e);
          texImages = texImages + 2;
          masksCovered = (ushort)((*backingMaskPtrA | *backingMaskPtrB) & ~*texImagesMaskPtr) == 0;
          cr0Bits = masksCovered << 1;
        } while (masksCovered);
      }
      gld_isStampRetiredResult = gld_isStampRetired(ctx,*(undefined4 *)(currentBacking + 0xc));
      if (gld_isStampRetiredResult == 0) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),9,currentBacking + 0xc,1,0,0);
      }
    }
    succeeded = 1;
    *(undefined1 *)(currentBacking + 0x14) = 1;
  }
  return succeeded;
}

/* gld_ensureTextureAgpRefBacking @ 0xaef4 (580 bytes) */
int gld_ensureTextureAgpRefBacking(ctx, texture, requestArg2)
  int ctx;
  undefined4 *texture;
  int requestArg2;
{
  int *newRefCountPtr;
  int newRefCountStored;
  int status;
  int backingCursor;
  int texImages;
  int gld_isStampRetiredResult;
  bool masksCovered;
  ushort *backingMaskPtrB;
  ushort *backingMaskPtrA;
  ushort *texImagesMaskPtr;
  int *oldRefCountPtr;
  uint maskCount;
  int oldRefCountStored;
  undefined4 succeeded;
  int oldRefCountValue;
  int currentBacking;
  char reservation;
  byte cr0Bits;
  undefined4 outSize;
  undefined4 outHandle;
  int newBacking;
  
  currentBacking = texture[0xd];
  if ((((currentBacking == 0) || (*(char *)(currentBacking + 0x16) != '\x06')) || (texture[2] != 0)) ||
     ((texture[3] != 0 || (requestArg2 != texture[4])))) {
LAB_0000b010:
    *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) | 1;
    if (currentBacking != 0) {
      oldRefCountPtr = (int *)(currentBacking + 0x10);
      do {
        oldRefCountValue = *oldRefCountPtr;
        if (reservation != '\0') {
          oldRefCountStored = storeWordConditionalIndexed(oldRefCountValue + -0x10000,0,oldRefCountPtr);
          *oldRefCountPtr = oldRefCountStored;
          cr0Bits = 2;
        }
      } while (!(bool)(cr0Bits >> 1 & 1));
      if (oldRefCountValue == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),0xb,currentBacking,1,0,0);
      }
      texture[0xd] = 0;
    }
    texture[4] = requestArg2;
    texture[1] = 6;
    texture[3] = 0;
    texture[2] = 0;
    outSize = 8;
    status = _io_connect_method_structureI_structureO
                       (*(undefined4 *)(ctx + 4),10,texture + 1,0x14,&outHandle,&outSize);
    succeeded = 0;
    if (status == 0) {
      texture[0xd] = newBacking;
      newRefCountPtr = (int *)(newBacking + 0x10);
      do {
        if (reservation != '\0') {
          newRefCountStored = storeWordConditionalIndexed(*newRefCountPtr + 0x10000,0,newRefCountPtr);
          *newRefCountPtr = newRefCountStored;
          cr0Bits = 2;
        }
      } while (!(bool)(cr0Bits >> 1 & 1));
      succeeded = 1;
      *texture = outHandle;
      *(undefined1 *)(newBacking + 0x14) = 1;
    }
  }
  else {
    texImages = texture[0xc];
    if (0x1ffff < *(int *)(currentBacking + 0x10)) {
      _gldFlush(ctx);
    }
    maskCount = (uint)*(byte *)(texImages + 0x6c);
    if (maskCount == 0) {
LAB_0000af80:
      gld_isStampRetiredResult = gld_isStampRetired(ctx,*(undefined4 *)(currentBacking + 8));
      if (gld_isStampRetiredResult == 0) goto LAB_0000b010;
    }
    else {
      if ((ushort)((*(ushort *)(currentBacking + 0x1c) | *(ushort *)(currentBacking + 0x28)) &
                  ~*(ushort *)(texImages + 0x7c)) == 0) {
        cr0Bits = 2;
        backingCursor = currentBacking;
        if (maskCount == 0) {
          maskCount = 1;
        }
        do {
          maskCount = maskCount - 1;
          if (maskCount == 0) goto LAB_0000af80;
          backingMaskPtrB = (ushort *)(backingCursor + 0x2a);
          backingMaskPtrA = (ushort *)(backingCursor + 0x1e);
          backingCursor = backingCursor + 2;
          texImagesMaskPtr = (ushort *)(texImages + 0x7e);
          texImages = texImages + 2;
          masksCovered = (ushort)((*backingMaskPtrA | *backingMaskPtrB) & ~*texImagesMaskPtr) == 0;
          cr0Bits = masksCovered << 1;
        } while (masksCovered);
      }
      gld_isStampRetiredResult = gld_isStampRetired(ctx,*(undefined4 *)(currentBacking + 8));
      if (gld_isStampRetiredResult == 0) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),9,currentBacking + 8,1,0,0);
      }
    }
    succeeded = 1;
    *(undefined1 *)(currentBacking + 0x14) = 1;
  }
  return succeeded;
}

/* gld_setTextureAgpRefBacking @ 0xb150 (280 bytes) */
int gld_setTextureAgpRefBacking(ctx, texture, requestArg0, requestArg1, requestArg2)
  int ctx;
  undefined4 *texture;
  undefined4 requestArg0;
  undefined4 requestArg1;
  undefined4 requestArg2;
{
  int *oldRefCountPtr;
  int oldRefCountValue;
  int newRefCountStored;
  int oldRefCountStored;
  int *newRefCountPtr;
  int status;
  undefined4 succeeded;
  int oldBacking;
  char reservation;
  byte cr0Bits;
  undefined4 outSize;
  undefined1 outHandleUnused [4];
  int newBacking;
  
  succeeded = 0;
  texture[2] = requestArg0;
  texture[3] = requestArg1;
  texture[1] = 6;
  texture[4] = requestArg2;
  *texture = 0;
  oldBacking = texture[0xd];
  texture[0xd] = 0;
  outSize = 8;
  status = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(ctx + 4),10,texture + 1,0x14,outHandleUnused,&outSize);
  if (status == 0) {
    texture[0xd] = newBacking;
    newRefCountPtr = (int *)(newBacking + 0x10);
    do {
      if (reservation != '\0') {
        newRefCountStored = storeWordConditionalIndexed(*newRefCountPtr + 0x10000,0,newRefCountPtr);
        *newRefCountPtr = newRefCountStored;
        cr0Bits = 2;
      }
    } while (!(bool)(cr0Bits >> 1 & 1));
    succeeded = 1;
    *(undefined1 *)(newBacking + 0x14) = 1;
    if (oldBacking != newBacking) {
      *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) | 1;
    }
  }
  if (oldBacking != 0) {
    oldRefCountPtr = (int *)(oldBacking + 0x10);
    do {
      oldRefCountValue = *oldRefCountPtr;
      if (reservation != '\0') {
        oldRefCountStored = storeWordConditionalIndexed(oldRefCountValue + -0x10000,0,oldRefCountPtr);
        *oldRefCountPtr = oldRefCountStored;
        cr0Bits = 2;
      }
    } while (!(bool)(cr0Bits >> 1 & 1));
    if (oldRefCountValue == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),0xb,oldBacking,1,0,0);
    }
  }
  return succeeded;
}

/* gld_setTextureNewTextureBacking @ 0xb270 (296 bytes) */
int gld_setTextureNewTextureBacking(ctx, texture, requestArg0, requestArg1, requestArg2, requestArg3)
  int ctx;
  undefined4 *texture;
  undefined4 requestArg0;
  undefined4 requestArg1;
  undefined4 requestArg2;
  undefined4 requestArg3;
{
  int *oldRefCountPtr;
  int oldRefCountValue;
  int newRefCountStored;
  int oldRefCountStored;
  int *newRefCountPtr;
  int status;
  undefined4 succeeded;
  int oldBacking;
  char reservation;
  byte cr0Bits;
  undefined4 outSize;
  undefined4 outHandle;
  int newBacking;
  
  succeeded = 0;
  texture[2] = requestArg0;
  texture[3] = requestArg1;
  texture[1] = 7;
  texture[4] = requestArg2;
  texture[5] = requestArg3;
  *texture = 0;
  oldBacking = texture[0xd];
  texture[0xd] = 0;
  outSize = 8;
  status = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(ctx + 4),10,texture + 1,0x14,&outHandle,&outSize);
  if (status == 0) {
    texture[0xd] = newBacking;
    newRefCountPtr = (int *)(newBacking + 0x10);
    do {
      if (reservation != '\0') {
        newRefCountStored = storeWordConditionalIndexed(*newRefCountPtr + 0x10000,0,newRefCountPtr);
        *newRefCountPtr = newRefCountStored;
        cr0Bits = 2;
      }
    } while (!(bool)(cr0Bits >> 1 & 1));
    succeeded = 1;
    *(byte *)(newBacking + 0x14) = *(byte *)(newBacking + 0x14) | 1;
    *texture = outHandle;
    if (oldBacking != newBacking) {
      *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) | 1;
    }
  }
  if (oldBacking != 0) {
    oldRefCountPtr = (int *)(oldBacking + 0x10);
    do {
      oldRefCountValue = *oldRefCountPtr;
      if (reservation != '\0') {
        oldRefCountStored = storeWordConditionalIndexed(oldRefCountValue + -0x10000,0,oldRefCountPtr);
        *oldRefCountPtr = oldRefCountStored;
        cr0Bits = 2;
      }
    } while (!(bool)(cr0Bits >> 1 & 1));
    if (oldRefCountValue == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),0xb,oldBacking,1,0,0);
    }
  }
  return succeeded;
}

/* gld_ensureTextureSurfaceBacking @ 0xb3a0 (332 bytes) */
int gld_ensureTextureSurfaceBacking(ctx, texture, requestArg0, requestArg1, requestArg2)
  int ctx;
  undefined4 *texture;
  int requestArg0;
  int requestArg1;
  int requestArg2;
{
  int *newRefCountPtr;
  int newRefCountStored;
  int status;
  int oldRefCountStored;
  undefined4 backingStillValid;
  int *oldRefCountPtr;
  int currentBacking;
  int oldRefCountValue;
  char reservation;
  byte cr0Bits;
  undefined4 outSize;
  undefined1 outHandleUnused [4];
  int newBacking;
  
  currentBacking = texture[0xd];
  if ((((currentBacking == 0) || (*(char *)(currentBacking + 0x16) != '\0')) || (requestArg0 != texture[2])) ||
     ((requestArg1 != texture[3] || (backingStillValid = 1, requestArg2 != texture[4])))) {
    *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) | 1;
    if (currentBacking != 0) {
      oldRefCountPtr = (int *)(currentBacking + 0x10);
      do {
        oldRefCountValue = *oldRefCountPtr;
        if (reservation != '\0') {
          oldRefCountStored = storeWordConditionalIndexed(oldRefCountValue + -0x10000,0,oldRefCountPtr);
          *oldRefCountPtr = oldRefCountStored;
          cr0Bits = 2;
        }
      } while (!(bool)(cr0Bits >> 1 & 1));
      if (oldRefCountValue == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),0xb,currentBacking,1,0,0);
      }
      texture[0xd] = 0;
    }
    texture[2] = requestArg0;
    texture[3] = requestArg1;
    texture[4] = requestArg2;
    texture[1] = 0;
    outSize = 8;
    status = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(ctx + 4),10,texture + 1,0x14,outHandleUnused,&outSize);
    backingStillValid = 0;
    if (status == 0) {
      texture[0xd] = newBacking;
      newRefCountPtr = (int *)(newBacking + 0x10);
      if (reservation != '\0') {
        newRefCountStored = storeWordConditionalIndexed(*newRefCountPtr + 0x10000,0,newRefCountPtr);
        *newRefCountPtr = newRefCountStored;
      }
      *texture = 0;
      backingStillValid = 1;
    }
  }
  return backingStillValid;
}

/* gld_ensureTextureGlobalBacking @ 0xb4f0 (292 bytes) */
int gld_ensureTextureGlobalBacking(ctx, texture, requestArg0)
  int ctx;
  undefined4 *texture;
  int requestArg0;
{
  int *newRefCountPtr;
  int newRefCountStored;
  int status;
  int oldRefCountStored;
  undefined4 backingStillValid;
  int *oldRefCountPtr;
  int currentBacking;
  int oldRefCountValue;
  char reservation;
  byte cr0Bits;
  undefined4 outSize;
  undefined1 outHandleUnused [4];
  int newBacking;
  
  currentBacking = texture[0xd];
  if (((currentBacking == 0) || (*(char *)(currentBacking + 0x16) != '\x01')) || (backingStillValid = 1, requestArg0 != texture[2])) {
    *(byte *)((int)texture + 0x39) = *(byte *)((int)texture + 0x39) | 1;
    if (currentBacking != 0) {
      oldRefCountPtr = (int *)(currentBacking + 0x10);
      do {
        oldRefCountValue = *oldRefCountPtr;
        if (reservation != '\0') {
          oldRefCountStored = storeWordConditionalIndexed(oldRefCountValue + -0x10000,0,oldRefCountPtr);
          *oldRefCountPtr = oldRefCountStored;
          cr0Bits = 2;
        }
      } while (!(bool)(cr0Bits >> 1 & 1));
      if (oldRefCountValue == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),0xb,currentBacking,1,0,0);
      }
      texture[0xd] = 0;
    }
    texture[2] = requestArg0;
    texture[1] = 1;
    outSize = 8;
    status = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(ctx + 4),10,texture + 1,0x14,outHandleUnused,&outSize);
    backingStillValid = 0;
    if (status == 0) {
      texture[0xd] = newBacking;
      newRefCountPtr = (int *)(newBacking + 0x10);
      if (reservation != '\0') {
        newRefCountStored = storeWordConditionalIndexed(*newRefCountPtr + 0x10000,0,newRefCountPtr);
        *newRefCountPtr = newRefCountStored;
      }
      *texture = 0;
      backingStillValid = 1;
    }
  }
  return backingStillValid;
}

/* gldFlushDataCacheRange @ 0xb620 (72 bytes) */
int gldFlushDataCacheRange(ctx, address, length, unused4, unused5, unused6, unused7, unused8)
  int ctx;
  uint address;
  int length;
  undefined4 unused4;
  undefined4 unused5;
  undefined4 unused6;
  undefined4 unused7;
  undefined4 unused8;
{
  int offset;
  int span;
  uint cacheBlockSize;
  
  cacheBlockSize = (uint)*(byte *)(ctx + GLD_cacheLineSize);
  offset = 0;
  span = (address & cacheBlockSize - 1) + (length - cacheBlockSize);
  if (0 < span) {
    do {
      dataCacheBlockStore((-cacheBlockSize & address) + offset);
      offset = offset + cacheBlockSize;
    } while (offset < span);
  }
  dataCacheBlockFlush((-cacheBlockSize & address) + offset);
  return;
}

/* gldFlushDataCacheRangeSync @ 0xb670 (80 bytes) */
int gldFlushDataCacheRangeSync(ctx, surfaceBase, byteCount, param_4, param_5, lastHeader, param_7, a7)
  int ctx;
  uint surfaceBase;
  int byteCount;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 lastHeader;
  undefined4 param_7;
  undefined4 a7;
{
  int lineOffset;
  int lastLineLimit;
  uint cacheLineSize;
  
  cacheLineSize = (uint)*(byte *)(ctx + 8);
  lineOffset = 0;
  lastLineLimit = ((surfaceBase & cacheLineSize - 1) + byteCount) - cacheLineSize;
  if (0 < lastLineLimit) {
    do {
      dataCacheBlockFlush((-cacheLineSize & surfaceBase) + lineOffset);
      lineOffset = lineOffset + cacheLineSize;
    } while (lineOffset < lastLineLimit);
  }
  dataCacheBlockFlush((-cacheLineSize & surfaceBase) + lineOffset);
  sync(0);
  instructionSynchronize();
  return;
}

/* _gldCreateVertexArray @ 0xb6c0 (80 bytes) */
int _gldCreateVertexArray(ctx, vertexArrayOut, initialWord0, initialWord1)
  undefined4 ctx;
  int *vertexArrayOut;
  undefined4 initialWord0;
  undefined4 initialWord1;
{
  undefined4 *vertexArray;
  
  vertexArray = (undefined4 *)_calloc(1,0x244);
  *vertexArrayOut = (int)vertexArray;
  *vertexArray = initialWord0;
  vertexArray[1] = initialWord1;
  return 0;
}

/* _gldFlushVertexArray @ 0xb710 (56 bytes) */
int _gldFlushVertexArray(ctx, unused2, flushArg2, flushArg3, doFlush, flushArg5, flushArg6, flushArg7)
  undefined4 ctx;
  undefined4 unused2;
  undefined4 flushArg2;
  undefined4 flushArg3;
  int doFlush;
  undefined4 flushArg5;
  undefined4 flushArg6;
  undefined4 flushArg7;
{
  if (doFlush != 0) {
    ((int (*)())gldFlushDataCacheRange)(ctx,flushArg3,flushArg2,flushArg3,doFlush,flushArg5,flushArg6,flushArg7);
  }
  return doFlush != 0;
}

/* FUN_0000b750 @ 0xb750 (276 bytes) */
int FUN_0000b750(ctx)
  int ctx;
{
  int arrayState;
  int previousArray;
  int *vertexArray;
  
  previousArray = *(int *)(ctx + GLD_currentVertexArray);
  vertexArray = *(int **)(*(int *)(ctx + GLD_engineObjects) + 0x194);
  arrayState = *vertexArray;
  if ((*(uint *)(arrayState + 0x308) & *(uint *)(arrayState + 0x300)) == 0 &&
      (*(uint *)(arrayState + 0x30c) & *(uint *)(arrayState + 0x304)) == 0) {
    if ((((unsigned char *)0x000042fc)[*(int *)(ctx + GLD_engineState)] != '\0') ||
       (*(short *)(arrayState + 0x312) != -0x7a4c)) {
      if (*(int *)(vertexArray[1] + 0x84) == 0 && *(int *)(vertexArray[1] + 0x88) == 0) goto LAB_0000b830;
      arrayState = gld_prepareVertexArrayBacking(ctx,vertexArray);
      goto joined_r0x0000b814;
    }
  }
  else {
    if (*(int *)(vertexArray[1] + 0x84) == 0 && *(int *)(vertexArray[1] + 0x88) == 0) goto LAB_0000b830;
    arrayState = gld_prepareVertexArrayBuffers(ctx,vertexArray);
joined_r0x0000b814:
    if (arrayState != 0) goto LAB_0000b830;
  }
  vertexArray = (int *)0x0;
LAB_0000b830:
  *(int **)(ctx + GLD_currentVertexArray) = vertexArray;
  if ((previousArray != 0) && (vertexArray == (int *)0x0)) {
    gld_startPacket(ctx);
    return;
  }
  return;
}

/* gld_waitVertexArrayStamp @ 0xb880 (244 bytes) */
int gld_waitVertexArrayStamp(ctx, vertexArray)
  int ctx;
  int vertexArray;
{
  int retired;
  undefined4 connection;
  int backing;
  
  backing = *(int *)(vertexArray + 0x228);
  if (backing != 0) {
    if (*(char *)(backing + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(backing + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(backing + 8));
      if (retired == 0) {
        connection = *(undefined4 *)(ctx + GLD_connect);
        backing = backing + 8;
LAB_0000b93c:
        _io_connect_method_scalarI_structureI(connection,9,backing,1,0,0);
        return;
      }
    }
    else if (*(char *)(backing + 0x16) == '\a') {
      if (0x1ffff < *(int *)(backing + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(backing + 0xc));
      if (retired == 0) {
        connection = *(undefined4 *)(ctx + GLD_connect);
        backing = backing + 0xc;
        goto LAB_0000b93c;
      }
    }
  }
  return;
}

/* FUN_0000b980 @ 0xb980 (184 bytes) */
int FUN_0000b980(ctx, vertexArray)
  undefined4 ctx;
  int vertexArray;
{
  undefined4 retired;
  int backing;
  
  backing = *(int *)(vertexArray + 0x228);
  if (backing != 0) {
    if (*(char *)(backing + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(backing + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(backing + 8));
      return retired;
    }
    if (*(char *)(backing + 0x16) == '\a') {
      if (0x1ffff < *(int *)(backing + 0x10)) {
        _gldFlush(ctx);
      }
      retired = gld_isStampRetired(ctx,*(undefined4 *)(backing + 0xc));
      return retired;
    }
  }
  return 1;
}

/* _gldModifyVertexArray @ 0xba40 (248 bytes) */
int _gldModifyVertexArray(ctx, vertexArray)
  int ctx;
  int *vertexArray;
{
  bool retired;
  int updatedRefCount;
  uint stateMismatch;
  int *refCountSlot;
  int backing;
  int oldRefCount;
  char reservation;
  
  _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
  backing = vertexArray[0x8a];
  if (backing != 0) {
    retired = ((*(uint *)(vertexArray[1] + 0x88) ^ 1) & 1) == 0;
    if (!retired) {
      if (*(short *)(*vertexArray + 0x312) == -0x7a42) {
        stateMismatch = vertexArray[0x8c] ^ 7;
      }
      else {
        stateMismatch = vertexArray[0x8c] ^ 6;
      }
      if (stateMismatch == 0) goto LAB_0000bb18;
    }
    refCountSlot = (int *)(backing + 0x10);
    do {
      oldRefCount = *refCountSlot;
      if (reservation != '\0') {
        updatedRefCount = storeWordConditionalIndexed(oldRefCount + -0x10000,0,refCountSlot);
        *refCountSlot = updatedRefCount;
        retired = true;
      }
    } while (!retired);
    if (oldRefCount == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0xb,backing,1,0,0);
    }
    vertexArray[0x8a] = 0;
  }
LAB_0000bb18:
  _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
  return 0;
}

/* _gldReclaimVertexArray @ 0xbb40 (220 bytes) */
int _gldReclaimVertexArray(ctx, vertexArray)
  int ctx;
  int vertexArray;
{
  int updatedRefCount;
  int *refCountSlot;
  int oldRefCount;
  int backing;
  char reservation;
  byte crBits;
  
  if (*(int *)(ctx + GLD_currentVertexArray) == vertexArray) {
    *(undefined4 *)(ctx + GLD_currentVertexArray) = 0;
    gld_startPacket(ctx);
  }
  backing = *(int *)(vertexArray + 0x228);
  if (backing != 0) {
    if ((0x1ffff < (int)*(uint *)(backing + 0x10)) || ((*(uint *)(backing + 0x10) & 0xffff) != 0)) {
      _gldFlush(ctx);
    }
    ((int (*)())gld_waitVertexArrayStamp)(ctx,vertexArray);
    refCountSlot = (int *)(backing + 0x10);
    do {
      oldRefCount = *refCountSlot;
      if (reservation != '\0') {
        updatedRefCount = storeWordConditionalIndexed(oldRefCount + -0x10000,0,refCountSlot);
        *refCountSlot = updatedRefCount;
        crBits = 2;
      }
    } while (!(bool)(crBits >> 1 & 1));
    if (oldRefCount == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + GLD_connect),0xb,backing,1,0,0);
    }
    *(undefined4 *)(vertexArray + 0x228) = 0;
  }
  return;
}

/* _gldDestroyVertexArray @ 0xbc20 (56 bytes) */
int _gldDestroyVertexArray(ctx, vertexArray)
  undefined4 ctx;
  undefined4 vertexArray;
{
  ((int (*)())_gldReclaimVertexArray)(ctx,vertexArray);
  _free(vertexArray);
  return 0;
}

/* gld_setVertexArrayAgpRefBacking @ 0xbc60 (248 bytes) */
int gld_setVertexArrayAgpRefBacking(ctx, vertexArray, requestArg0, requestArg1, requestArg2)
  int ctx;
  int vertexArray;
  undefined4 requestArg0;
  undefined4 requestArg1;
  undefined4 requestArg2;
{
  int *oldRefCountPtr;
  int oldRefCountValue;
  int newRefCountStored;
  int oldRefCountStored;
  int *newRefCountPtr;
  int status;
  undefined4 succeeded;
  int oldBacking;
  char reservation;
  byte cr0Bits;
  undefined4 outSize;
  undefined1 outHandleUnused [4];
  int newBacking;
  
  succeeded = 0;
  *(undefined4 *)(vertexArray + 0x234) = requestArg0;
  *(undefined4 *)(vertexArray + 0x238) = requestArg1;
  *(undefined4 *)(vertexArray + 0x230) = 6;
  *(undefined4 *)(vertexArray + 0x23c) = requestArg2;
  *(undefined4 *)(vertexArray + 0x22c) = 0;
  oldBacking = *(int *)(vertexArray + 0x228);
  *(undefined4 *)(vertexArray + 0x228) = 0;
  outSize = 8;
  status = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(ctx + 4),10,vertexArray + 0x230,0x14,outHandleUnused,&outSize);
  if (status == 0) {
    *(int *)(vertexArray + 0x228) = newBacking;
    newRefCountPtr = (int *)(newBacking + 0x10);
    do {
      if (reservation != '\0') {
        newRefCountStored = storeWordConditionalIndexed(*newRefCountPtr + 0x10000,0,newRefCountPtr);
        *newRefCountPtr = newRefCountStored;
        cr0Bits = 2;
      }
    } while (!(bool)(cr0Bits >> 1 & 1));
    succeeded = 1;
    *(undefined1 *)(newBacking + 0x14) = 1;
  }
  if (oldBacking != 0) {
    oldRefCountPtr = (int *)(oldBacking + 0x10);
    do {
      oldRefCountValue = *oldRefCountPtr;
      if (reservation != '\0') {
        oldRefCountStored = storeWordConditionalIndexed(oldRefCountValue + -0x10000,0,oldRefCountPtr);
        *oldRefCountPtr = oldRefCountStored;
        cr0Bits = 2;
      }
    } while (!(bool)(cr0Bits >> 1 & 1));
    if (oldRefCountValue == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),0xb,oldBacking,1,0,0);
    }
  }
  return succeeded;
}

/* gld_setVertexArrayNewTextureBacking @ 0xbd60 (264 bytes) */
int gld_setVertexArrayNewTextureBacking(ctx, vertexArray, requestArg0, requestArg1, requestArg2, requestArg3)
  int ctx;
  int vertexArray;
  undefined4 requestArg0;
  undefined4 requestArg1;
  undefined4 requestArg2;
  undefined4 requestArg3;
{
  int *oldRefCountPtr;
  int oldRefCountValue;
  int newRefCountStored;
  int oldRefCountStored;
  int *newRefCountPtr;
  int status;
  undefined4 succeeded;
  int oldBacking;
  char reservation;
  byte cr0Bits;
  undefined4 outSize;
  undefined4 outHandle;
  int newBacking;
  
  succeeded = 0;
  *(undefined4 *)(vertexArray + 0x234) = requestArg0;
  *(undefined4 *)(vertexArray + 0x238) = requestArg1;
  *(undefined4 *)(vertexArray + 0x230) = 7;
  *(undefined4 *)(vertexArray + 0x23c) = requestArg2;
  *(undefined4 *)(vertexArray + 0x240) = requestArg3;
  *(undefined4 *)(vertexArray + 0x22c) = 0;
  oldBacking = *(int *)(vertexArray + 0x228);
  *(undefined4 *)(vertexArray + 0x228) = 0;
  outSize = 8;
  status = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(ctx + 4),10,vertexArray + 0x230,0x14,&outHandle,&outSize);
  if (status == 0) {
    *(int *)(vertexArray + 0x228) = newBacking;
    newRefCountPtr = (int *)(newBacking + 0x10);
    do {
      if (reservation != '\0') {
        newRefCountStored = storeWordConditionalIndexed(*newRefCountPtr + 0x10000,0,newRefCountPtr);
        *newRefCountPtr = newRefCountStored;
        cr0Bits = 2;
      }
    } while (!(bool)(cr0Bits >> 1 & 1));
    succeeded = 1;
    *(undefined1 *)(newBacking + 0x14) = 1;
    *(undefined4 *)(vertexArray + 0x22c) = outHandle;
  }
  if (oldBacking != 0) {
    oldRefCountPtr = (int *)(oldBacking + 0x10);
    do {
      oldRefCountValue = *oldRefCountPtr;
      if (reservation != '\0') {
        oldRefCountStored = storeWordConditionalIndexed(oldRefCountValue + -0x10000,0,oldRefCountPtr);
        *oldRefCountPtr = oldRefCountStored;
        cr0Bits = 2;
      }
    } while (!(bool)(cr0Bits >> 1 & 1));
    if (oldRefCountValue == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(ctx + 4),0xb,oldBacking,1,0,0);
    }
  }
  return succeeded;
}

/* powerOfTenDouble @ 0xbe70 (272 bytes) */
double powerOfTenDouble(int exponent,undefined4 param_2,undefined4 exponentPtr,undefined4 outCapacity,undefined4 argReg7,undefined4 argReg8,undefined4 pow10Table)
{
  int blocks;
  double result;
  
  if (0 < exponent) {
    result = DOUBLE_001aa200;
    if (0x20 < exponent) {
      blocks = (exponent - 0x21U >> 5) + 1;
      if (exponent + -0x20 < 1) {
        blocks = 1;
      }
      do {
        result = result * DOUBLE_001aa1f8;
        exponent = exponent + -0x20;
        blocks = blocks + -1;
      } while (blocks != 0);
    }
    return result * *(double *)(&DAT_001aa3a8 + exponent * 8);
  }
  if (-1 < exponent) {
    return DOUBLE_001aa200;
  }
  result = DOUBLE_001aa200;
  if (exponent < -0x20) {
    blocks = (~(exponent + 0x20U) >> 5) + 1;
    if (-1 < (int)(exponent + 0x20U)) {
      blocks = 1;
    }
    do {
      result = result * DOUBLE_001aa1f0;
      exponent = exponent + 0x20;
      blocks = blocks + -1;
    } while (blocks != 0);
  }
  return result * (DOUBLE_001aa2a8)[-exponent];
}

/* textPrintDoubleShortest @ 0xbfa0 (1332 bytes) */
char * textPrintDoubleShortest(undefined4 unusedArg1,undefined4 unusedArg2,char *outBuffer,uint outCapacity,double value,double tolerance)
{
  int reversalSwaps;
  int capacityLeft;
  int digitRunLength;
  double integerPartRemaining;
  double fractionDigit;
  double pow10Exponent;
  double digitBase;
  double negPow10;
  double roundedExponent;
  char swapChar;
  int swapsLeft;
  int integerDigit;
  undefined4 r4AfterCall;
  undefined4 r4AfterCall2;
  uint *exponentPtr;
  undefined4 argReg7;
  undefined4 argReg8;
  undefined *pow10Table;
  char *reverseTail;
  char *outEnd;
  char *runStart;
  char *outPos;
  double scaledSum;
  double scaledValue;
  double halfTolerance;
  double scaledTolerance;
  double integerQuotient;
  uint decimalExponent [4];
  undefined4 i2dHi1;
  uint i2dLo1;
  longlong fixConvScratch1;
  longlong fixConvScratch2;
  longlong fixConvScratch3;
  
  outEnd = outBuffer + outCapacity;
  if (tolerance <= DOUBLE_001aa228) {
    tolerance = DOUBLE_001aa208;
  }
  if (outCapacity < 2) {
    return (char *)0x0;
  }
  runStart = outBuffer;
  if (value < DOUBLE_001aa228) {
    value = -value;
    runStart = outBuffer + 1;
    *outBuffer = '-';
  }
  pow10Table = &DAT_001abfb4;
  scaledValue = value;
  if (value <= DOUBLE_001aa228) {
    decimalExponent[0] = 0;
    halfTolerance = tolerance * DOUBLE_001aa240;
  }
  else {
    if ((value < DOUBLE_001aa210) || (DOUBLE_001aa230 < value)) {
      exponentPtr = decimalExponent;
      _frexp(value,exponentPtr);
      i2dHi1 = 0x43300000;
      i2dLo1 = decimalExponent[0] ^ 0x80000000;
      roundedExponent = _round(((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_001aa1e0) * DOUBLE_001aa218);
      decimalExponent[0] = (uint)(int)roundedExponent;
      fixConvScratch1 = (longlong)(int)decimalExponent[0];
      pow10Exponent = (double)((double (*)())powerOfTenDouble)(decimalExponent[0],r4AfterCall,exponentPtr,outCapacity,argReg7,argReg8,pow10Table);
      negPow10 = (double)((double (*)())powerOfTenDouble)(-decimalExponent[0],r4AfterCall2,exponentPtr,outCapacity,argReg7,argReg8,pow10Table);
      scaledValue = value * negPow10;
      scaledTolerance = tolerance * pow10Exponent;
    }
    else {
      decimalExponent[0] = 0;
      scaledTolerance = tolerance;
    }
    halfTolerance = tolerance * DOUBLE_001aa240;
    for (; scaledSum = halfTolerance + scaledValue, DOUBLE_001aa238 <= scaledSum; scaledValue = scaledValue * DOUBLE_001aa220) {
      decimalExponent[0] = decimalExponent[0] + 1;
      scaledTolerance = scaledTolerance * DOUBLE_001aa238;
    }
    while (scaledSum < DOUBLE_001aa200) {
      scaledValue = scaledValue * DOUBLE_001aa238;
      decimalExponent[0] = decimalExponent[0] - 1;
      scaledTolerance = scaledTolerance * DOUBLE_001aa220;
      scaledSum = halfTolerance + scaledValue;
    }
    if ((int)(((int)decimalExponent[0] >> 0x1f ^ decimalExponent[0]) - ((int)decimalExponent[0] >> 0x1f)) < 4) {
      decimalExponent[0] = 0;
      halfTolerance = scaledTolerance * DOUBLE_001aa240;
      tolerance = scaledTolerance;
      scaledValue = value;
    }
  }
  scaledSum = _floor(scaledValue + halfTolerance);
  outPos = runStart;
  integerPartRemaining = scaledSum;
  if (scaledSum <= tolerance) {
LAB_0000c240:
    *outPos = '0';
    outPos = outPos + 1;
  }
  else {
    do {
      if (outPos == outEnd) {
        return (char *)0x0;
      }
      integerQuotient = integerPartRemaining * DOUBLE_001aa220;
      integerPartRemaining = _floor(integerQuotient);
      integerDigit = (int)((integerQuotient - integerPartRemaining) * DOUBLE_001aa238);
      fixConvScratch2 = (longlong)integerDigit;
      *outPos = (char)integerDigit + '0';
      outPos = outPos + 1;
    } while (tolerance < integerPartRemaining);
    if (outPos <= runStart) goto LAB_0000c240;
    digitRunLength = (int)outPos - (int)runStart;
    if (1 < digitRunLength) {
      swapsLeft = ((uint)(runStart + (digitRunLength * 2 - (int)outPos) + -2) >> 1) + 1;
      reverseTail = outPos;
      if ((int)(runStart + (digitRunLength * 2 - (int)outPos) + -2) < 0) {
        swapsLeft = 1;
      }
      do {
        reverseTail = reverseTail + -1;
        swapChar = *reverseTail;
        *reverseTail = *runStart;
        *runStart = swapChar;
        runStart = runStart + 1;
        swapsLeft = swapsLeft + -1;
      } while (swapsLeft != 0);
    }
  }
  scaledSum = (scaledValue + halfTolerance) - scaledSum;
  if (scaledSum <= tolerance) {
    if (decimalExponent[0] == 0) {
      if ((int)outEnd - (int)outPos < 2) {
        return (char *)0x0;
      }
      *outPos = '.';
      outPos[1] = '0';
      outPos = outPos + 2;
      goto LAB_0000c31c;
    }
  }
  else {
    if (outPos == outEnd) {
      return (char *)0x0;
    }
    *outPos = '.';
    digitBase = DOUBLE_001aa238;
    outPos = outPos + 1;
    do {
      if (outEnd == outPos) {
        return (char *)0x0;
      }
      scaledSum = scaledSum * digitBase;
      tolerance = tolerance * digitBase;
      fractionDigit = _floor(scaledSum);
      fixConvScratch3 = (longlong)(int)fractionDigit;
      scaledSum = scaledSum - fractionDigit;
      *outPos = (char)(int)fractionDigit + '0';
      outPos = outPos + 1;
    } while (tolerance < scaledSum);
LAB_0000c31c:
    if (decimalExponent[0] == 0) goto LAB_0000c440;
  }
  if ((int)outEnd - (int)outPos < 3) {
    return (char *)0x0;
  }
  runStart = outPos + 1;
  *outPos = 'e';
  if ((int)decimalExponent[0] < 0) {
    runStart = outPos + 2;
    outPos[1] = '-';
    decimalExponent[0] = -decimalExponent[0];
  }
  outPos = runStart;
  if (0 < (int)decimalExponent[0]) {
    if (runStart == outEnd) {
      return (char *)0x0;
    }
    capacityLeft = (int)outEnd - (int)runStart;
    while( true ) {
      *outPos = (char)decimalExponent[0] + (char)((int)decimalExponent[0] / 10) * -10 + '0';
      outPos = outPos + 1;
      decimalExponent[0] = (int)decimalExponent[0] / 10;
      if ((int)decimalExponent[0] < 1) break;
      capacityLeft = capacityLeft + -1;
      if (capacityLeft == 0) {
        return (char *)0x0;
      }
    }
    if (1 < (int)outPos - (int)runStart) {
      reversalSwaps = ((uint)(runStart + (((int)outPos - (int)runStart) * 2 - (int)outPos) + -2) >> 1) + 1;
      reverseTail = outPos;
      if ((int)(runStart + (((int)outPos - (int)runStart) * 2 - (int)outPos) + -2) < 0) {
        reversalSwaps = 1;
      }
      do {
        reverseTail = reverseTail + -1;
        swapChar = *reverseTail;
        *reverseTail = *runStart;
        *runStart = swapChar;
        runStart = runStart + 1;
        reversalSwaps = reversalSwaps + -1;
      } while (reversalSwaps != 0);
    }
  }
LAB_0000c440:
  if (outPos == outEnd) {
    return (char *)0x0;
  }
  *outPos = '\0';
  return outPos;
}

/* parseDecimalDouble @ 0xc500 (892 bytes) */
double parseDecimalDouble(char *cursor,undefined4 *endPtr,undefined4 staleArgR5,undefined4 staleArgR6,undefined4 staleArgR7,undefined4 staleArgR8)
{
  char *exponentStart;
  char *integerScan;
  char *fractionStart;
  double powerOfTen;
  double exponent;
  double placeValue;
  double fraction;
  bool negative;
  bool exponentNegative;
  double exponentPlace;
  char ch;
  int chCode;
  char *fractionDigitCursor;
  char *digitRunEnd;
  double value;
  
  ch = *cursor;
  if (ch == '+') {
    cursor = cursor + 1;
    ch = *cursor;
    negative = false;
  }
  else {
    negative = false;
    if (ch == '-') {
      cursor = cursor + 1;
      ch = *cursor;
      negative = true;
    }
  }
  chCode = (int)ch;
  value = DOUBLE_001aa228;
  if (chCode == 0) goto LAB_0000c5a8;
  if (chCode == 0x2e) {
LAB_0000c670:
    fractionStart = cursor + 1;
    ch = cursor[1];
    digitRunEnd = fractionStart;
    while ((byte)(ch - 0x30U) < 10) {
      digitRunEnd = digitRunEnd + 1;
      ch = *digitRunEnd;
    }
    fractionDigitCursor = digitRunEnd + -1;
    fraction = DOUBLE_001aa228;
    if (fractionStart <= fractionDigitCursor) {
      do {
        ch = *fractionDigitCursor;
        fractionDigitCursor = fractionDigitCursor + -1;
        fraction = fraction * DOUBLE_001aa220 +
                ((double)CONCAT44(0x43300000,(int)ch - 0x30U ^ 0x80000000) - DOUBLE_001aa1e0);
      } while (fractionStart <= fractionDigitCursor);
      fraction = fraction * DOUBLE_001aa220;
    }
    ch = *digitRunEnd;
    value = value + fraction;
  }
  else {
    if ((chCode == 0x65) || (chCode == 0x45)) goto LAB_0000c5a8;
    integerScan = cursor;
    placeValue = DOUBLE_001aa200;
    digitRunEnd = cursor;
    if ((chCode - 0x30U & 0xff) < 10) {
      do {
        integerScan = integerScan + 1;
        digitRunEnd = integerScan;
      } while ((byte)(*integerScan - 0x30U) < 10);
    }
    while (integerScan = integerScan + -1, cursor <= integerScan) {
      value = placeValue * ((double)CONCAT44(0x43300000,(int)*integerScan - 0x30U ^ 0x80000000) -
                       DOUBLE_001aa1e0) + value;
      placeValue = placeValue * DOUBLE_001aa238;
    }
    ch = *digitRunEnd;
    cursor = digitRunEnd;
    if (ch == '.') goto LAB_0000c670;
  }
  if ((ch == 'e') || (cursor = digitRunEnd, ch == 'E')) {
    exponentStart = digitRunEnd + 1;
    if (digitRunEnd[1] == '+') {
      exponentStart = digitRunEnd + 2;
      exponentNegative = false;
    }
    else {
      exponentNegative = false;
      if (digitRunEnd[1] == '-') {
        exponentStart = digitRunEnd + 2;
        exponentNegative = true;
      }
    }
    ch = *exponentStart;
    cursor = exponentStart;
    while (exponent = DOUBLE_001aa228, exponentPlace = DOUBLE_001aa200, digitRunEnd = cursor,
          (byte)(ch - 0x30U) < 10) {
      cursor = cursor + 1;
      ch = *cursor;
    }
    while (digitRunEnd = digitRunEnd + -1, exponentStart <= digitRunEnd) {
      exponent = exponentPlace * ((double)CONCAT44(0x43300000,(int)*digitRunEnd - 0x30U ^ 0x80000000) -
                      DOUBLE_001aa1e0) + exponent;
      exponentPlace = exponentPlace * DOUBLE_001aa238;
    }
    if (exponentNegative) {
      exponent = -exponent;
    }
    powerOfTen = (double)((double (*)())powerOfTenDouble)((int)exponent,endPtr,staleArgR5,staleArgR6,staleArgR7,staleArgR8,digitRunEnd);
    value = value * powerOfTen;
  }
LAB_0000c5a8:
  if (negative) {
    value = -value;
  }
  if (endPtr != (undefined4 *)0x0) {
    *endPtr = cursor;
  }
  return value;
}

/* textBufferEnsureRoom @ 0xc8a0 (136 bytes) */
int textBufferEnsureRoom(capacityPtr, bufferPtr, cursorPtr)
  int *capacityPtr;
  int *bufferPtr;
  int *cursorPtr;
{
  int allocation;
  int oldBuffer;
  int newCapacity;
  int oldCursor;
  undefined4 ok;
  
  oldCursor = *cursorPtr;
  ok = 1;
  oldBuffer = *bufferPtr;
  if (*capacityPtr - (oldCursor - oldBuffer) < 0x100) {
    newCapacity = *capacityPtr + 0x800;
    *capacityPtr = newCapacity;
    allocation = _realloc(*bufferPtr,newCapacity);
    ok = 0;
    *cursorPtr = allocation;
    if (allocation != 0) {
      *bufferPtr = allocation;
      ok = 1;
      *cursorPtr = allocation + (oldCursor - oldBuffer);
    }
  }
  return ok;
}

/* arbIrPrintCcAndSaturateSuffix @ 0xc930 (284 bytes) */
int arbIrPrintCcAndSaturateSuffix(cursor, updatesCC, ccRegisterIndex, saturate)
  int cursor;
  int updatesCC;
  int ccRegisterIndex;
  int saturate;
{
  char copyChar;
  char *copySrc;
  int emitLength;
  
  if (updatesCC != 0) {
    emitLength = 0;
    if (s_C_001a4428[0] != '\0') {
      copySrc = "C";
      emitLength = 0;
      copyChar = s_C_001a4428[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(cursor + emitLength) = copyChar;
        emitLength = emitLength + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
    cursor = cursor + emitLength;
    if (0 < ccRegisterIndex) {
      emitLength = 0;
      if (s_1_001a442c[0] != '\0') {
        copySrc = "1";
        copyChar = s_1_001a442c[0];
        do {
          copySrc = copySrc + 1;
          *(char *)(cursor + emitLength) = copyChar;
          emitLength = emitLength + 1;
          copyChar = *copySrc;
        } while (copyChar != '\0');
      }
      cursor = cursor + emitLength;
    }
  }
  if (saturate != 0) {
    emitLength = 0;
    if (s__SAT_001a4430[0] != '\0') {
      copySrc = "_SAT";
      copyChar = s__SAT_001a4430[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(cursor + emitLength) = copyChar;
        emitLength = emitLength + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
    return cursor + emitLength;
  }
  return cursor;
}

/* arbIrPrintPrecisionSuffix @ 0xca50 (312 bytes) */
int arbIrPrintPrecisionSuffix(cursor, precisionCode)
  int cursor;
  int precisionCode;
{
  char copyChar;
  char *copySrc;
  int emitLength;
  
  if (precisionCode == 2) {
    emitLength = 0;
    if (s_H_001a443c[0] != '\0') {
      copySrc = "H";
      emitLength = 0;
      copyChar = s_H_001a443c[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(cursor + emitLength) = copyChar;
        emitLength = emitLength + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
  }
  else {
    if (precisionCode == 3) {
      emitLength = 0;
      if (s_X_001a4440[0] != '\0') {
        copySrc = "X";
        emitLength = 0;
        copyChar = s_X_001a4440[0];
        do {
          copySrc = copySrc + 1;
          *(char *)(cursor + emitLength) = copyChar;
          emitLength = emitLength + 1;
          copyChar = *copySrc;
        } while (copyChar != '\0');
      }
      return cursor + emitLength;
    }
    if (precisionCode != 1) {
      return cursor;
    }
    emitLength = 0;
    if (s_R_001a4438[0] != '\0') {
      copySrc = "R";
      emitLength = 0;
      copyChar = s_R_001a4438[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(cursor + emitLength) = copyChar;
        emitLength = emitLength + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
  }
  return cursor + emitLength;
}

/* textPrintDecimalDigits @ 0xcb90 (572 bytes) */
int textPrintDecimalDigits(cursorPtr, value)
  int *cursorPtr;
  int value;
{
  int valueDiv10;
  int valueDiv100;
  int valueDiv1e3;
  int valueDiv1e4;
  int valueDiv1e5;
  int valueDiv1e6;
  int valueDiv1e7;
  int valueDiv1e8;
  int valueDiv1e9;
  char *digitCursor;
  
  valueDiv10 = value / 10;
  if (valueDiv10 == 0) {
    digitCursor = (char *)*cursorPtr;
  }
  else {
    valueDiv100 = valueDiv10 / 10;
    if (valueDiv100 == 0) {
      digitCursor = (char *)*cursorPtr;
    }
    else {
      valueDiv1e3 = valueDiv100 / 10;
      if (valueDiv1e3 == 0) {
        digitCursor = (char *)*cursorPtr;
      }
      else {
        valueDiv1e4 = valueDiv1e3 / 10;
        if (valueDiv1e4 == 0) {
          digitCursor = (char *)*cursorPtr;
        }
        else {
          valueDiv1e5 = valueDiv1e4 / 10;
          if (valueDiv1e5 == 0) {
            digitCursor = (char *)*cursorPtr;
          }
          else {
            valueDiv1e6 = valueDiv1e5 / 10;
            if (valueDiv1e6 == 0) {
              digitCursor = (char *)*cursorPtr;
            }
            else {
              valueDiv1e7 = valueDiv1e6 / 10;
              if (valueDiv1e7 == 0) {
                digitCursor = (char *)*cursorPtr;
              }
              else {
                valueDiv1e8 = valueDiv1e7 / 10;
                if (valueDiv1e8 == 0) {
                  digitCursor = (char *)*cursorPtr;
                }
                else {
                  valueDiv1e9 = valueDiv1e8 / 10;
                  if (valueDiv1e9 != 0) {
                    ((int (*)())textPrintDecimalDigits)(cursorPtr,valueDiv1e9);
                  }
                  *(char *)*cursorPtr = (char)valueDiv1e8 + (char)valueDiv1e9 * -10 + '0';
                  digitCursor = (char *)(*cursorPtr + 1);
                  *cursorPtr = (int)digitCursor;
                }
                *digitCursor = (char)valueDiv1e7 + (char)valueDiv1e8 * -10 + '0';
                digitCursor = (char *)(*cursorPtr + 1);
                *cursorPtr = (int)digitCursor;
              }
              *digitCursor = (char)valueDiv1e6 + (char)valueDiv1e7 * -10 + '0';
              digitCursor = (char *)(*cursorPtr + 1);
              *cursorPtr = (int)digitCursor;
            }
            *digitCursor = (char)valueDiv1e5 + (char)valueDiv1e6 * -10 + '0';
            digitCursor = (char *)(*cursorPtr + 1);
            *cursorPtr = (int)digitCursor;
          }
          *digitCursor = (char)valueDiv1e4 + (char)valueDiv1e5 * -10 + '0';
          digitCursor = (char *)(*cursorPtr + 1);
          *cursorPtr = (int)digitCursor;
        }
        *digitCursor = (char)valueDiv1e3 + (char)valueDiv1e4 * -10 + '0';
        digitCursor = (char *)(*cursorPtr + 1);
        *cursorPtr = (int)digitCursor;
      }
      *digitCursor = (char)valueDiv100 + (char)valueDiv1e3 * -10 + '0';
      digitCursor = (char *)(*cursorPtr + 1);
      *cursorPtr = (int)digitCursor;
    }
    *digitCursor = (char)valueDiv10 + (char)valueDiv100 * -10 + '0';
    digitCursor = (char *)(*cursorPtr + 1);
    *cursorPtr = (int)digitCursor;
  }
  *digitCursor = (char)value + (char)valueDiv10 * -10 + '0';
  *cursorPtr = *cursorPtr + 1;
  return;
}

/* textPrintSignedDecimal @ 0xcdf0 (156 bytes) */
int textPrintSignedDecimal(outCursor, value)
  char *outCursor;
  int value;
{
  int valueDiv10;
  char *cursorBox [6];
  
  cursorBox[0] = outCursor;
  if (value < 0) {
    cursorBox[0] = outCursor + 1;
    value = -value;
    *outCursor = '-';
  }
  valueDiv10 = value / 10;
  if (valueDiv10 != 0) {
    ((int (*)())textPrintDecimalDigits)(cursorBox,valueDiv10);
  }
  *cursorBox[0] = (char)value + (char)valueDiv10 * -10 + '0';
  return cursorBox[0] + (1 - (int)outCursor);
}

/* arbIrPrintDeclSizeSuffix @ 0xce90 (924 bytes) */
int arbIrPrintDeclSizeSuffix(cursor, vectorWidthMinus1, hasSecondWidth, elementType, bitWidthCode)
  int cursor;
  int vectorWidthMinus1;
  int hasSecondWidth;
  int elementType;
  int bitWidthCode;
{
  bool colonNotEmpty;
  char copyChar;
  char *copySrc;
  int emitLength;
  int suffixCursor;
  int secondNumberLength;
  char copyChar2;
  
  copyChar2 = s___001a4444[0];
  colonNotEmpty = s___001a4444[0] != '\0';
  if (colonNotEmpty) {
    copySrc = ":";
    emitLength = 0;
    copyChar = s___001a4444[0];
    do {
      copySrc = copySrc + 1;
      *(char *)(cursor + emitLength) = copyChar;
      emitLength = emitLength + 1;
      copyChar = *copySrc;
    } while (copyChar != '\0');
  }
  else {
    emitLength = 0;
  }
  suffixCursor = ((int (*)())textPrintSignedDecimal)(cursor + emitLength,vectorWidthMinus1 + 1);
  suffixCursor = cursor + emitLength + suffixCursor;
  if (hasSecondWidth == 1) {
    if (colonNotEmpty) {
      copySrc = ":";
      emitLength = 0;
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
    else {
      emitLength = 0;
    }
    secondNumberLength = ((int (*)())textPrintSignedDecimal)(suffixCursor + emitLength,vectorWidthMinus1 + 1);
    suffixCursor = suffixCursor + emitLength + secondNumberLength;
  }
  if (elementType == 2) {
    emitLength = 0;
    if (s_X_001a4440[0] != '\0') {
      copySrc = "X";
      copyChar2 = s_X_001a4440[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
  }
  else if (elementType < 3) {
    if (elementType != 1) goto LAB_0000d0e4;
    emitLength = 0;
    if (s_F_001a4448[0] != '\0') {
      copySrc = "F";
      copyChar2 = s_F_001a4448[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
  }
  else if (elementType == 3) {
    emitLength = 0;
    if (s_I_001a444c[0] != '\0') {
      copySrc = "I";
      copyChar2 = s_I_001a444c[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
  }
  else {
    if (elementType != 4) goto LAB_0000d0e4;
    emitLength = 0;
    if (s_B_001a4450[0] != '\0') {
      copySrc = "B";
      copyChar2 = s_B_001a4450[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
  }
  suffixCursor = suffixCursor + emitLength;
LAB_0000d0e4:
  if (bitWidthCode == 2) {
    emitLength = 0;
    if (s_16_001a4458[0] != '\0') {
      copySrc = "16";
      copyChar2 = s_16_001a4458[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
  }
  else if (bitWidthCode == 3) {
    emitLength = 0;
    if (s_12_001a445c[0] != '\0') {
      copySrc = "12";
      copyChar2 = s_12_001a445c[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
  }
  else {
    if (bitWidthCode != 1) {
      return suffixCursor;
    }
    emitLength = 0;
    if (s_32_001a4454[0] != '\0') {
      copySrc = "32";
      copyChar2 = s_32_001a4454[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
  }
  return suffixCursor + emitLength;
}

/* arbIrPrintSourceSizeSuffix @ 0xd240 (308 bytes) */
int arbIrPrintSourceSizeSuffix(cursor, sizeMinus1, hasSecondSize)
  int cursor;
  int sizeMinus1;
  int hasSecondSize;
{
  bool colonNotEmpty;
  char copyChar;
  char *copySrc;
  int emitLength;
  int numberLength;
  char copyChar2;
  
  copyChar2 = s___001a4444[0];
  if ((sizeMinus1 != 3) || (hasSecondSize == 1)) {
    colonNotEmpty = s___001a4444[0] != '\0';
    if (colonNotEmpty) {
      copySrc = ":";
      emitLength = 0;
      copyChar = s___001a4444[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(cursor + emitLength) = copyChar;
        emitLength = emitLength + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
    else {
      emitLength = 0;
    }
    numberLength = ((int (*)())textPrintSignedDecimal)(cursor + emitLength,sizeMinus1 + 1);
    cursor = cursor + emitLength + numberLength;
    if (hasSecondSize == 1) {
      if (colonNotEmpty) {
        copySrc = ":";
        emitLength = 0;
        do {
          copySrc = copySrc + 1;
          *(char *)(cursor + emitLength) = copyChar2;
          emitLength = emitLength + 1;
          copyChar2 = *copySrc;
        } while (copyChar2 != '\0');
      }
      else {
        emitLength = 0;
      }
      numberLength = ((int (*)())textPrintSignedDecimal)(cursor + emitLength,sizeMinus1 + 1);
      cursor = cursor + emitLength + numberLength;
    }
  }
  return cursor;
}

/* arbIrPrintDestinationOperand @ 0xd380 (2976 bytes) */
int arbIrPrintDestinationOperand(instrTable, outCursor, nameTable3, nameTable4, instrIndex, useNames)
  int instrTable;
  undefined1 *outCursor;
  int nameTable3;
  int nameTable4;
  int instrIndex;
  int useNames;
{
  uint registerId;
  uint registerFile;
  char curChar;
  char *srcCursor;
  int emitLength;
  uint operandWord1;
  int written;
  undefined1 *afterPrefix;
  uint *operandEntry;
  
  operandEntry = (uint *)(instrIndex * 8 + instrTable);
  registerFile = *(uint *)(instrIndex * 8 + instrTable) >> 0x11 & 7;
  if (registerFile == 1) {
    written = 0;
    if (s_tmp_001a4460[0] != '\0') {
      srcCursor = "tmp";
      written = 0;
      curChar = s_tmp_001a4460[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    afterPrefix = outCursor + written;
    if ((useNames == 0) || (nameTable3 == 0)) {
      written = ((int (*)())textPrintSignedDecimal)(afterPrefix,(uint)*(ushort *)((int)operandEntry + 6));
      outCursor = afterPrefix + written;
      goto LAB_0000d5c0;
    }
    written = ((int (*)())textPrintSignedDecimal)(afterPrefix,*(undefined4 *)(nameTable3 + (uint)*(ushort *)((int)operandEntry + 6) * 4));
    outCursor = afterPrefix + written;
    if (nameTable4 == 0) goto LAB_0000d5c4;
    registerFile = operandEntry[1];
    if (-1 < (int)registerFile) {
      registerId = (uint)*(ushort *)((int)operandEntry + 6);
      if (*(int *)(nameTable4 + registerId * 4) != -1) {
        written = 0;
        if (s___001a4464[0] != '\0') {
          srcCursor = "[";
          written = 0;
          curChar = s___001a4464[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[written] = curChar;
            written = written + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
          registerId = (uint)*(ushort *)((int)operandEntry + 6);
        }
        afterPrefix = outCursor + written;
        written = ((int (*)())textPrintSignedDecimal)(afterPrefix,*(undefined4 *)(nameTable4 + registerId * 4));
        emitLength = 0;
        if (s___001a4468[0] != '\0') {
          srcCursor = "]";
          emitLength = 0;
          curChar = s___001a4468[0];
          do {
            srcCursor = srcCursor + 1;
            afterPrefix[emitLength + written] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        registerFile = operandEntry[1];
        outCursor = afterPrefix + emitLength + written;
      }
      goto LAB_0000d5c8;
    }
LAB_0000d5d0:
    written = 0;
    if (s__adr_001a4470[0] != '\0') {
      srcCursor = "[adr";
      written = 0;
      curChar = s__adr_001a4470[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
      registerFile = operandEntry[1];
    }
    emitLength = ((int (*)())textPrintSignedDecimal)(outCursor + written,registerFile >> 0x1e & 1);
    operandWord1 = operandEntry[1];
    afterPrefix = outCursor + written + emitLength;
    registerFile = operandWord1 >> 0x1c & 3;
    if (registerFile == 1) {
      written = 0;
      if (s__y_001a447c[0] != '\0') {
        srcCursor = ".y";
        curChar = s__y_001a447c[0];
        do {
          srcCursor = srcCursor + 1;
          afterPrefix[written] = curChar;
          written = written + 1;
          curChar = *srcCursor;
        } while (curChar != '\0');
        goto LAB_0000d794;
      }
LAB_0000d798:
      afterPrefix = afterPrefix + written;
    }
    else {
      if (1 < registerFile) {
        if (registerFile == 2) {
          written = 0;
          if (s__z_001a4480[0] != '\0') {
            srcCursor = ".z";
            curChar = s__z_001a4480[0];
            do {
              srcCursor = srcCursor + 1;
              afterPrefix[written] = curChar;
              written = written + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
LAB_0000d794:
            operandWord1 = operandEntry[1];
          }
        }
        else {
          if (registerFile != 3) goto LAB_0000d79c;
          written = 0;
          if (s__w_001a4484[0] != '\0') {
            srcCursor = ".w";
            curChar = s__w_001a4484[0];
            do {
              srcCursor = srcCursor + 1;
              afterPrefix[written] = curChar;
              written = written + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
            goto LAB_0000d794;
          }
        }
        goto LAB_0000d798;
      }
      if (registerFile == 0) {
        written = 0;
        if (s__x_001a4478[0] != '\0') {
          srcCursor = ".x";
          curChar = s__x_001a4478[0];
          do {
            srcCursor = srcCursor + 1;
            afterPrefix[written] = curChar;
            written = written + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
          goto LAB_0000d794;
        }
        goto LAB_0000d798;
      }
    }
LAB_0000d79c:
    if ((((*operandEntry & 0xe0000) != 0x20000) || (nameTable4 == 0)) ||
       (written = *(int *)(nameTable4 + (uint)*(ushort *)((int)operandEntry + 6) * 4), written == -1)) {
      written = 0;
    }
    written = written + ((int)(operandWord1 << 4 | operandWord1 >> 0x1c) >> 0x18);
    if (written != 0) {
      if (0 < written) {
        emitLength = 0;
        if (s___001a4488[0] != '\0') {
          srcCursor = "+";
          curChar = s___001a4488[0];
          do {
            srcCursor = srcCursor + 1;
            afterPrefix[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        afterPrefix = afterPrefix + emitLength;
      }
      written = ((int (*)())textPrintSignedDecimal)(afterPrefix,written);
      afterPrefix = afterPrefix + written;
    }
    written = 0;
    if (s___001a4468[0] != '\0') {
      srcCursor = "]";
      written = 0;
      curChar = s___001a4468[0];
      do {
        srcCursor = srcCursor + 1;
        afterPrefix[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    outCursor = afterPrefix + written;
LAB_0000d89c:
    written = 0;
    if (s___001a448c[0] != '\0') {
      srcCursor = ".";
      written = 0;
      curChar = s___001a448c[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    if ((*operandEntry & 0x2000) == 0) {
      outCursor[written] = 0x5f;
    }
    else {
      outCursor[written] = (((byte)(*operandEntry >> 8) & 3) + 1 & 3) + 0x77;
    }
    srcCursor = outCursor + written + 1;
    registerFile = *operandEntry;
    if ((registerFile & 0xc00) != 0) {
      if ((registerFile & 0x4000) == 0) {
        *srcCursor = '_';
        srcCursor = outCursor + written + 2;
        registerFile = *operandEntry;
      }
      else {
        *srcCursor = (((byte)(registerFile >> 6) & 3) + 1 & 3) + 0x77;
        srcCursor = outCursor + written + 2;
        registerFile = *operandEntry;
      }
    }
    if (1 < (registerFile >> 10 & 3)) {
      if ((registerFile & 0x8000) == 0) {
        *srcCursor = '_';
        srcCursor = srcCursor + 1;
        registerFile = *operandEntry;
      }
      else {
        *srcCursor = (((byte)(registerFile >> 4) & 3) + 1 & 3) + 0x77;
        srcCursor = srcCursor + 1;
        registerFile = *operandEntry;
      }
    }
    if (2 < (registerFile >> 10 & 3)) {
      if ((registerFile & 0x10000) == 0) {
        *srcCursor = '_';
        srcCursor = srcCursor + 1;
        registerFile = *operandEntry;
      }
      else {
        *srcCursor = (((byte)(registerFile >> 2) & 3) + 1 & 3) + 0x77;
        srcCursor = srcCursor + 1;
        registerFile = *operandEntry;
      }
    }
    outCursor = (undefined1 *)((int (*)())arbIrPrintSourceSizeSuffix)(srcCursor,registerFile >> 10 & 3,registerFile >> 0xc & 1);
    registerFile = *operandEntry;
  }
  else {
    if (registerFile == 3) {
      written = 0;
      if (s_res_001a446c[0] != '\0') {
        srcCursor = "res";
        written = 0;
        curChar = s_res_001a446c[0];
        do {
          srcCursor = srcCursor + 1;
          outCursor[written] = curChar;
          written = written + 1;
          curChar = *srcCursor;
        } while (curChar != '\0');
      }
      emitLength = ((int (*)())textPrintSignedDecimal)(outCursor + written,(uint)*(ushort *)((int)operandEntry + 6));
      outCursor = outCursor + written + emitLength;
    }
LAB_0000d5c0:
    if (useNames != 0) {
LAB_0000d5c4:
      registerFile = operandEntry[1];
LAB_0000d5c8:
      if ((int)registerFile < 0) goto LAB_0000d5d0;
      goto LAB_0000d89c;
    }
    registerFile = *operandEntry;
    if ((registerFile & 0x1e000) != 0x1e000) {
      written = 0;
      if (s___001a448c[0] != '\0') {
        srcCursor = ".";
        curChar = s___001a448c[0];
        do {
          srcCursor = srcCursor + 1;
          outCursor[written] = curChar;
          written = written + 1;
          curChar = *srcCursor;
        } while (curChar != '\0');
        registerFile = *operandEntry;
      }
      outCursor = outCursor + written;
      if ((registerFile & 0x2000) != 0) {
        written = 0;
        if (s_x_001a4490[0] != '\0') {
          srcCursor = "x";
          curChar = s_x_001a4490[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[written] = curChar;
            written = written + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
          registerFile = *operandEntry;
        }
        outCursor = outCursor + written;
      }
      if ((registerFile & 0x4000) != 0) {
        written = 0;
        if (s_y_001a4494[0] != '\0') {
          srcCursor = "y";
          curChar = s_y_001a4494[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[written] = curChar;
            written = written + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
          registerFile = *operandEntry;
        }
        outCursor = outCursor + written;
      }
      if ((registerFile & 0x8000) != 0) {
        written = 0;
        if (s_z_001a4498[0] != '\0') {
          srcCursor = "z";
          curChar = s_z_001a4498[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[written] = curChar;
            written = written + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
          registerFile = *operandEntry;
        }
        outCursor = outCursor + written;
      }
      if ((registerFile & 0x10000) != 0) {
        written = 0;
        if (s_w_001a449c[0] != '\0') {
          srcCursor = "w";
          curChar = s_w_001a449c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[written] = curChar;
            written = written + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
          registerFile = *operandEntry;
        }
        outCursor = outCursor + written;
      }
    }
  }
  if ((registerFile & 0x70000000) == 0) {
    return outCursor;
  }
  switch(registerFile >> 0x1c & 7) {
  case 0:
    written = 0;
    if (s__TR_001a44a0[0] != '\0') {
      srcCursor = " (TR";
      curChar = s__TR_001a44a0[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
LAB_0000de9c:
      registerFile = *operandEntry;
    }
    break;
  case 1:
    written = 0;
    if (s__EQ_001a44a8[0] != '\0') {
      srcCursor = " (EQ";
      curChar = s__EQ_001a44a8[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 2:
    written = 0;
    if (s__GE_001a44b0[0] != '\0') {
      srcCursor = " (GE";
      curChar = s__GE_001a44b0[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 3:
    written = 0;
    if (s__GT_001a44b8[0] != '\0') {
      srcCursor = " (GT";
      curChar = s__GT_001a44b8[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 4:
    written = 0;
    if (s__LE_001a44c0[0] != '\0') {
      srcCursor = " (LE";
      curChar = s__LE_001a44c0[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 5:
    written = 0;
    if (s__LT_001a44c8[0] != '\0') {
      srcCursor = " (LT";
      curChar = s__LT_001a44c8[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 6:
    written = 0;
    if (s__NE_001a44d0[0] != '\0') {
      srcCursor = " (NE";
      curChar = s__NE_001a44d0[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 7:
    written = 0;
    if (s__FL_001a44d8[0] != '\0') {
      srcCursor = " (FL";
      curChar = s__FL_001a44d8[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
      goto LAB_0000de9c;
    }
    break;
  default:
    goto switchD_0000dc3c_default;
  }
  outCursor = outCursor + written;
switchD_0000dc3c_default:
  if ((int)registerFile < 0) {
    *outCursor = 0x31;
    outCursor = outCursor + 1;
  }
  *outCursor = 0x2e;
  outCursor[1] = (((byte)(*operandEntry >> 0x1a) & 3) + 1 & 3) + 0x77;
  outCursor[2] = (*(char *)operandEntry + 1U & 3) + 0x77;
  outCursor[3] = (((byte)(*operandEntry >> 0x16) & 3) + 1 & 3) + 0x77;
  registerFile = *operandEntry;
  outCursor[5] = 0x29;
  outCursor[4] = (((byte)(registerFile >> 0x14) & 3) + 1 & 3) + 0x77;
  return outCursor + 6;
}

/* arbIrPrintSizeTypeSuffix @ 0xdf50 (648 bytes) */
int arbIrPrintSizeTypeSuffix(cursor, vectorWidthMinus1, hasSecondWidth, elementType)
  int cursor;
  int vectorWidthMinus1;
  int hasSecondWidth;
  int elementType;
{
  bool colonNotEmpty;
  char copyChar;
  char *copySrc;
  int emitLength;
  int suffixCursor;
  int secondNumberLength;
  char copyChar2;
  
  copyChar2 = s___001a4444[0];
  colonNotEmpty = s___001a4444[0] != '\0';
  if (colonNotEmpty) {
    copySrc = ":";
    emitLength = 0;
    copyChar = s___001a4444[0];
    do {
      copySrc = copySrc + 1;
      *(char *)(cursor + emitLength) = copyChar;
      emitLength = emitLength + 1;
      copyChar = *copySrc;
    } while (copyChar != '\0');
  }
  else {
    emitLength = 0;
  }
  suffixCursor = ((int (*)())textPrintSignedDecimal)(cursor + emitLength,vectorWidthMinus1 + 1);
  suffixCursor = cursor + emitLength + suffixCursor;
  if (hasSecondWidth != 0) {
    if (colonNotEmpty) {
      copySrc = ":";
      emitLength = 0;
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
    else {
      emitLength = 0;
    }
    secondNumberLength = ((int (*)())textPrintSignedDecimal)(suffixCursor + emitLength,vectorWidthMinus1 + 1);
    suffixCursor = suffixCursor + emitLength + secondNumberLength;
  }
  if (elementType == 2) {
    emitLength = 0;
    if (s_X_001a4440[0] != '\0') {
      copySrc = "X";
      copyChar2 = s_X_001a4440[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
  }
  else if (elementType < 3) {
    if (elementType != 1) {
      return suffixCursor;
    }
    emitLength = 0;
    if (s_F_001a4448[0] != '\0') {
      copySrc = "F";
      copyChar2 = s_F_001a4448[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
  }
  else if (elementType == 3) {
    emitLength = 0;
    if (s_I_001a444c[0] != '\0') {
      copySrc = "I";
      copyChar2 = s_I_001a444c[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
  }
  else {
    if (elementType != 4) {
      return suffixCursor;
    }
    emitLength = 0;
    if (s_B_001a4450[0] != '\0') {
      copySrc = "B";
      copyChar2 = s_B_001a4450[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(suffixCursor + emitLength) = copyChar2;
        emitLength = emitLength + 1;
        copyChar2 = *copySrc;
      } while (copyChar2 != '\0');
    }
  }
  return suffixCursor + emitLength;
}

/* arbIrPrintSourceOperand @ 0xe1f0 (4068 bytes) */
int arbIrPrintSourceOperand(instrTable, outCursor, nameTable3, nameTable4, nameTable5, nameTable6, instrIndex, useNames, isSwizzleOperand)
  int instrTable;
  char *outCursor;
  int nameTable3;
  int nameTable4;
  int nameTable5;
  int nameTable6;
  int instrIndex;
  int useNames;
  int isSwizzleOperand;
{
  bool lastComponent;
  char curChar;
  char *srcCursor;
  char *srcCursor2;
  int written;
  int nameLength;
  uint operandWord;
  uint nameIndex;
  uint *swizzleEntry;
  uint *operandEntry;
  
  operandEntry = (uint *)(instrIndex * 8 + instrTable);
  if ((*(uint *)(instrTable + instrIndex * 8) & 0x8000000) != 0) {
    written = 0;
    if (s___001a44e0[0] != '\0') {
      srcCursor = "-";
      written = 0;
      curChar = s___001a44e0[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    outCursor = outCursor + written;
  }
  operandWord = *operandEntry;
  if ((operandWord & 0x4000000) != 0) {
    written = 0;
    if (s___001a44e4[0] != '\0') {
      srcCursor = "|";
      curChar = s___001a44e4[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
      operandWord = *operandEntry;
    }
    outCursor = outCursor + written;
  }
  switch(operandWord >> 0x17 & 7) {
  case 0:
    written = 0;
    if (s_att_001a44e8[0] != '\0') {
      srcCursor = "att";
      written = 0;
      curChar = s_att_001a44e8[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    break;
  case 1:
    written = 0;
    if (s_tmp_001a4460[0] != '\0') {
      srcCursor = "tmp";
      written = 0;
      curChar = s_tmp_001a4460[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    srcCursor = outCursor + written;
    if (nameTable5 == 0) {
      written = ((int (*)())textPrintSignedDecimal)(srcCursor,(uint)*(ushort *)((int)operandEntry + 6));
    }
    else {
      written = ((int (*)())textPrintSignedDecimal)(srcCursor,*(undefined4 *)(nameTable5 + (uint)*(ushort *)((int)operandEntry + 6) * 4)
                          );
    }
    outCursor = srcCursor + written;
    if (nameTable6 == 0) {
      operandWord = *operandEntry;
    }
    else {
      operandWord = *operandEntry;
      if ((int)operandWord < 0) goto LAB_0000e6e8;
      nameIndex = (uint)*(ushort *)((int)operandEntry + 6);
      if (*(int *)(nameTable6 + nameIndex * 4) != -1) {
        written = 0;
        if (s___001a4464[0] != '\0') {
          srcCursor = "[";
          written = 0;
          curChar = s___001a4464[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[written] = curChar;
            written = written + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
          nameIndex = (uint)*(ushort *)((int)operandEntry + 6);
        }
        nameLength = ((int (*)())textPrintSignedDecimal)(outCursor + written,*(undefined4 *)(nameTable6 + nameIndex * 4));
        srcCursor = outCursor + written + nameLength;
        written = 0;
        if (s___001a4468[0] != '\0') {
          srcCursor2 = "]";
          written = 0;
          curChar = s___001a4468[0];
          do {
            srcCursor2 = srcCursor2 + 1;
            srcCursor[written] = curChar;
            written = written + 1;
            curChar = *srcCursor2;
          } while (curChar != '\0');
        }
        goto LAB_0000e610;
      }
    }
    goto switchD_0000e310_default;
  case 2:
    written = 0;
    if (s_prm_001a44ec[0] != '\0') {
      srcCursor = "prm";
      written = 0;
      curChar = s_prm_001a44ec[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    nameLength = ((int (*)())textPrintSignedDecimal)(outCursor + written,
                         *(undefined4 *)(nameTable3 + (uint)*(ushort *)((int)operandEntry + 6) * 4));
    operandWord = *operandEntry;
    outCursor = outCursor + written + nameLength;
    if (-1 < (int)operandWord) {
      nameIndex = (uint)*(ushort *)((int)operandEntry + 6);
      if (*(int *)(nameTable4 + nameIndex * 4) != -1) {
        written = 0;
        if (s___001a4464[0] != '\0') {
          srcCursor = "[";
          written = 0;
          curChar = s___001a4464[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[written] = curChar;
            written = written + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
          nameIndex = (uint)*(ushort *)((int)operandEntry + 6);
        }
        nameLength = ((int (*)())textPrintSignedDecimal)(outCursor + written,*(undefined4 *)(nameTable4 + nameIndex * 4));
        srcCursor = outCursor + written + nameLength;
        written = 0;
        if (s___001a4468[0] != '\0') {
          srcCursor2 = "]";
          written = 0;
          curChar = s___001a4468[0];
          do {
            srcCursor2 = srcCursor2 + 1;
            srcCursor[written] = curChar;
            written = written + 1;
            curChar = *srcCursor2;
          } while (curChar != '\0');
        }
LAB_0000e610:
        operandWord = *operandEntry;
        outCursor = srcCursor + written;
      }
      goto switchD_0000e310_default;
    }
    goto LAB_0000e6e8;
  case 3:
    written = 0;
    if (s_res_001a446c[0] != '\0') {
      srcCursor = "res";
      written = 0;
      curChar = s_res_001a446c[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    break;
  case 4:
    written = 0;
    if (s_adr_001a44f0[0] != '\0') {
      srcCursor = "adr";
      written = 0;
      curChar = s_adr_001a44f0[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    break;
  default:
    goto switchD_0000e310_default;
  }
  nameLength = ((int (*)())textPrintSignedDecimal)(outCursor + written,(uint)*(ushort *)((int)operandEntry + 6));
  operandWord = *operandEntry;
  outCursor = outCursor + written + nameLength;
switchD_0000e310_default:
  if ((int)operandWord < 0) {
LAB_0000e6e8:
    written = 0;
    if (s__adr_001a4470[0] != '\0') {
      srcCursor = "[adr";
      curChar = s__adr_001a4470[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
      operandWord = *operandEntry;
    }
    nameLength = ((int (*)())textPrintSignedDecimal)(outCursor + written,operandWord >> 0x1e & 1);
    nameIndex = *operandEntry;
    srcCursor = outCursor + written + nameLength;
    operandWord = nameIndex >> 0x1c & 3;
    if (operandWord == 1) {
      written = 0;
      if (s__y_001a447c[0] != '\0') {
        srcCursor2 = ".y";
        curChar = s__y_001a447c[0];
        do {
          srcCursor2 = srcCursor2 + 1;
          srcCursor[written] = curChar;
          written = written + 1;
          curChar = *srcCursor2;
        } while (curChar != '\0');
        goto LAB_0000e89c;
      }
LAB_0000e8a0:
      srcCursor = srcCursor + written;
    }
    else {
      if (1 < operandWord) {
        if (operandWord == 2) {
          written = 0;
          if (s__z_001a4480[0] != '\0') {
            srcCursor2 = ".z";
            curChar = s__z_001a4480[0];
            do {
              srcCursor2 = srcCursor2 + 1;
              srcCursor[written] = curChar;
              written = written + 1;
              curChar = *srcCursor2;
            } while (curChar != '\0');
LAB_0000e89c:
            nameIndex = *operandEntry;
          }
        }
        else {
          if (operandWord != 3) goto LAB_0000e8a4;
          written = 0;
          if (s__w_001a4484[0] != '\0') {
            srcCursor2 = ".w";
            curChar = s__w_001a4484[0];
            do {
              srcCursor2 = srcCursor2 + 1;
              srcCursor[written] = curChar;
              written = written + 1;
              curChar = *srcCursor2;
            } while (curChar != '\0');
            goto LAB_0000e89c;
          }
        }
        goto LAB_0000e8a0;
      }
      if (operandWord == 0) {
        written = 0;
        if (s__x_001a4478[0] != '\0') {
          srcCursor2 = ".x";
          curChar = s__x_001a4478[0];
          do {
            srcCursor2 = srcCursor2 + 1;
            srcCursor[written] = curChar;
            written = written + 1;
            curChar = *srcCursor2;
          } while (curChar != '\0');
          goto LAB_0000e89c;
        }
        goto LAB_0000e8a0;
      }
    }
LAB_0000e8a4:
    if ((nameIndex & 0x3800000) == 0x800000) {
      if (nameTable6 == 0) goto LAB_0000e908;
      written = *(int *)(nameTable6 + (uint)*(ushort *)((int)operandEntry + 6) * 4);
joined_r0x0000e904:
      if (written == -1) goto LAB_0000e908;
    }
    else {
      if (((nameIndex & 0x3800000) == 0x1000000) && (nameTable4 != 0)) {
        written = *(int *)(nameTable4 + (uint)*(ushort *)((int)operandEntry + 6) * 4);
        goto joined_r0x0000e904;
      }
LAB_0000e908:
      written = 0;
    }
    written = written + (char)*operandEntry;
    if (written != 0) {
      if (0 < written) {
        nameLength = 0;
        if (s___001a4488[0] != '\0') {
          srcCursor2 = "+";
          curChar = s___001a4488[0];
          do {
            srcCursor2 = srcCursor2 + 1;
            srcCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor2;
          } while (curChar != '\0');
        }
        srcCursor = srcCursor + nameLength;
      }
      written = ((int (*)())textPrintSignedDecimal)(srcCursor,written);
      srcCursor = srcCursor + written;
    }
    written = 0;
    if (s___001a4468[0] != '\0') {
      srcCursor2 = "]";
      written = 0;
      curChar = s___001a4468[0];
      do {
        srcCursor2 = srcCursor2 + 1;
        srcCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor2;
      } while (curChar != '\0');
    }
    operandWord = *operandEntry;
    outCursor = srcCursor + written;
  }
  if ((operandWord & 0x3800000) == 0x2000000) {
LAB_0000efb4:
    if (useNames == 0) goto LAB_0000f0bc;
  }
  else {
    if (isSwizzleOperand != 0) {
      swizzleEntry = (uint *)(instrTable + (instrIndex + 1) * 8);
LAB_0000e9fc:
      operandWord = *swizzleEntry >> 0xc & 0xf;
      if (s___001a44f4[0] == '\0') {
        written = 0;
      }
      else {
        srcCursor = ", ";
        written = 0;
        curChar = s___001a44f4[0];
        do {
          srcCursor = srcCursor + 1;
          outCursor[written] = curChar;
          written = written + 1;
          curChar = *srcCursor;
        } while (curChar != '\0');
      }
      outCursor = outCursor + written;
      written = 0;
LAB_0000ebd8:
      switch(operandWord) {
      case 0:
        nameLength = 0;
        if (s_x_001a4490[0] != '\0') {
          srcCursor = "x";
          curChar = s_x_001a4490[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 1:
        nameLength = 0;
        if (s_y_001a4494[0] != '\0') {
          srcCursor = "y";
          curChar = s_y_001a4494[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 2:
        nameLength = 0;
        if (s_z_001a4498[0] != '\0') {
          srcCursor = "z";
          curChar = s_z_001a4498[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 3:
        nameLength = 0;
        if (s_w_001a449c[0] != '\0') {
          srcCursor = "w";
          curChar = s_w_001a449c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 4:
        nameLength = 0;
        if (s__x_001a44fc[0] != '\0') {
          srcCursor = "-x";
          curChar = s__x_001a44fc[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 5:
        nameLength = 0;
        if (s__y_001a4500[0] != '\0') {
          srcCursor = "-y";
          curChar = s__y_001a4500[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 6:
        nameLength = 0;
        if (s__z_001a4504[0] != '\0') {
          srcCursor = "-z";
          curChar = s__z_001a4504[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 7:
        nameLength = 0;
        if (s__w_001a4508[0] != '\0') {
          srcCursor = "-w";
          curChar = s__w_001a4508[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 8:
        nameLength = 0;
        if (s_1_001a442c[0] != '\0') {
          srcCursor = "1";
          curChar = s_1_001a442c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 9:
        nameLength = 0;
        if (s_0_001a450c[0] != '\0') {
          srcCursor = "0";
          curChar = s_0_001a450c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 10:
        nameLength = 0;
        if (s__1_001a4510[0] != '\0') {
          srcCursor = "-1";
          curChar = s__1_001a4510[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      default:
        goto switchD_0000ebf8_default;
      }
      outCursor = outCursor + nameLength;
switchD_0000ebf8_default:
      lastComponent = written == 3;
      written = written + 1;
      if (lastComponent) {
        operandWord = *operandEntry;
        goto LAB_0000efb4;
      }
      if (written == 1) {
        nameLength = 0;
        operandWord = *swizzleEntry >> 8 & 0xf;
        if (s___001a44f8[0] != '\0') {
          srcCursor = ",";
          nameLength = 0;
          curChar = s___001a44f8[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
      }
      else {
        if (written < 2) {
          if (written == 0) goto LAB_0000e9fc;
          goto LAB_0000ebd8;
        }
        if (written == 2) {
          nameLength = 0;
          operandWord = *swizzleEntry >> 4 & 0xf;
          if (s___001a44f8[0] != '\0') {
            srcCursor = ",";
            nameLength = 0;
            curChar = s___001a44f8[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[nameLength] = curChar;
              nameLength = nameLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          goto LAB_0000ebd4;
        }
        if (written != 3) goto LAB_0000ebd8;
        nameLength = 0;
        operandWord = *swizzleEntry & 0xf;
        if (s___001a44f8[0] != '\0') {
          srcCursor = ",";
          nameLength = 0;
          curChar = s___001a44f8[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[nameLength] = curChar;
            nameLength = nameLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
      }
LAB_0000ebd4:
      outCursor = outCursor + nameLength;
      goto LAB_0000ebd8;
    }
    if (useNames == 0) {
      if ((operandWord & 0x7f8000) != 0xd8000) {
        written = 0;
        if (s___001a448c[0] != '\0') {
          srcCursor = ".";
          written = 0;
          curChar = s___001a448c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[written] = curChar;
            written = written + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
          operandWord = *operandEntry;
        }
        nameIndex = operandWord >> 0x15 & 3;
        srcCursor = outCursor + written;
        if (((nameIndex == (operandWord >> 0x13 & 3)) && (nameIndex == (operandWord >> 0x11 & 3))) &&
           (nameIndex == (operandWord >> 0xf & 3))) {
          outCursor[written] = ((char)nameIndex + 1U & 3) + 0x77;
          outCursor = srcCursor + 1;
          operandWord = *operandEntry;
        }
        else {
          outCursor = srcCursor + 4;
          *srcCursor = ((char)nameIndex + 1U & 3) + 0x77;
          srcCursor[1] = (((byte)(*operandEntry >> 0x13) & 3) + 1 & 3) + 0x77;
          srcCursor[2] = (((byte)(*operandEntry >> 0x11) & 3) + 1 & 3) + 0x77;
          srcCursor[3] = (((byte)(*operandEntry >> 0xf) & 3) + 1 & 3) + 0x77;
          operandWord = *operandEntry;
        }
      }
      goto LAB_0000f0bc;
    }
    written = 0;
    if (s___001a448c[0] != '\0') {
      srcCursor = ".";
      written = 0;
      curChar = s___001a448c[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
      operandWord = *operandEntry;
    }
    outCursor[written] = (((byte)(operandWord >> 0x15) & 3) + 1 & 3) + 0x77;
    nameLength = written + 1;
    operandWord = *operandEntry;
    if ((operandWord & 0x3000) != 0) {
      nameLength = written + 2;
      outCursor[written + 1] = (((byte)(operandWord >> 0x13) & 3) + 1 & 3) + 0x77;
      operandWord = *operandEntry;
    }
    outCursor = outCursor + nameLength;
    if (1 < (operandWord >> 0xc & 3)) {
      *outCursor = (((byte)(operandWord >> 0x11) & 3) + 1 & 3) + 0x77;
      outCursor = outCursor + 1;
      operandWord = *operandEntry;
    }
    if (2 < (operandWord >> 0xc & 3)) {
      *outCursor = (((byte)(operandWord >> 0xf) & 3) + 1 & 3) + 0x77;
      outCursor = outCursor + 1;
      operandWord = *operandEntry;
    }
  }
  outCursor = (char *)((int (*)())arbIrPrintSourceSizeSuffix)(outCursor,operandWord >> 0xc & 3,operandWord >> 0xe & 1);
  operandWord = *operandEntry;
LAB_0000f0bc:
  if ((operandWord & 0x4000000) != 0) {
    written = 0;
    if (s___001a44e4[0] != '\0') {
      srcCursor = "|";
      curChar = s___001a44e4[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[written] = curChar;
        written = written + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    outCursor = outCursor + written;
  }
  return outCursor;
}

/* arbIrPrintTextureOperand @ 0xf250 (932 bytes) */
int arbIrPrintTextureOperand(instrTable, outCursor, nameTable3, nameTable4, nameTable5, nameTable6, instrIndex, unitIsOperand)
  int instrTable;
  int outCursor;
  undefined4 nameTable3;
  undefined4 nameTable4;
  undefined4 nameTable5;
  undefined4 nameTable6;
  int instrIndex;
  int unitIsOperand;
{
  char copyChar;
  char *copySrc;
  int cursor;
  int emitLength;
  int targetEntryOffset;
  
  cursor = 0;
  if (s_texture__001a4514[0] != '\0') {
    copySrc = "texture[";
    cursor = 0;
    copyChar = s_texture__001a4514[0];
    do {
      copySrc = copySrc + 1;
      *(char *)(outCursor + cursor) = copyChar;
      cursor = cursor + 1;
      copyChar = *copySrc;
    } while (copyChar != '\0');
  }
  cursor = outCursor + cursor;
  if (unitIsOperand == 0) {
    targetEntryOffset = instrIndex * 8;
    emitLength = ((int (*)())textPrintSignedDecimal)(cursor,*(uint *)(targetEntryOffset + instrTable) & 0x1f);
    cursor = cursor + emitLength;
  }
  else {
    targetEntryOffset = (instrIndex + 1) * 8;
    cursor = ((int (*)())arbIrPrintSourceOperand)(instrTable,cursor,nameTable3,nameTable4,nameTable5,nameTable6,instrIndex,1,0);
  }
  emitLength = 0;
  if (s____001a4520[0] != '\0') {
    copySrc = "], ";
    emitLength = 0;
    copyChar = s____001a4520[0];
    do {
      copySrc = copySrc + 1;
      *(char *)(cursor + emitLength) = copyChar;
      emitLength = emitLength + 1;
      copyChar = *copySrc;
    } while (copyChar != '\0');
  }
  cursor = cursor + emitLength;
  switch(*(uint *)(targetEntryOffset + instrTable) >> 5 & 7) {
  case 0:
    targetEntryOffset = 0;
    if (s_CUBE_001a4530[0] != '\0') {
      copySrc = "CUBE";
      copyChar = s_CUBE_001a4530[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(cursor + targetEntryOffset) = copyChar;
        targetEntryOffset = targetEntryOffset + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
    break;
  case 1:
    targetEntryOffset = 0;
    if (s_3D_001a452c[0] != '\0') {
      copySrc = "3D";
      copyChar = s_3D_001a452c[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(cursor + targetEntryOffset) = copyChar;
        targetEntryOffset = targetEntryOffset + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
    break;
  case 2:
    targetEntryOffset = 0;
    if (s_RECT_001a4538[0] != '\0') {
      copySrc = "RECT";
      copyChar = s_RECT_001a4538[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(targetEntryOffset + cursor) = copyChar;
        targetEntryOffset = targetEntryOffset + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
    break;
  case 3:
    targetEntryOffset = 0;
    if (s_2D_001a4528[0] != '\0') {
      copySrc = "2D";
      copyChar = s_2D_001a4528[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(targetEntryOffset + cursor) = copyChar;
        targetEntryOffset = targetEntryOffset + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
    break;
  case 4:
    targetEntryOffset = 0;
    if (s_1D_001a4524[0] != '\0') {
      copySrc = "1D";
      copyChar = s_1D_001a4524[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(cursor + targetEntryOffset) = copyChar;
        targetEntryOffset = targetEntryOffset + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
    break;
  case 5:
    targetEntryOffset = 0;
    if (s_SHADOWRECT_001a4540[0] != '\0') {
      copySrc = "SHADOWRECT";
      copyChar = s_SHADOWRECT_001a4540[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(cursor + targetEntryOffset) = copyChar;
        targetEntryOffset = targetEntryOffset + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
    break;
  case 6:
    targetEntryOffset = 0;
    if (s_SHADOW2D_001a454c[0] != '\0') {
      copySrc = "SHADOW2D";
      copyChar = s_SHADOW2D_001a454c[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(cursor + targetEntryOffset) = copyChar;
        targetEntryOffset = targetEntryOffset + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
    break;
  case 7:
    targetEntryOffset = 0;
    if (s_SHADOW1D_001a4558[0] != '\0') {
      copySrc = "SHADOW1D";
      copyChar = s_SHADOW1D_001a4558[0];
      do {
        copySrc = copySrc + 1;
        *(char *)(cursor + targetEntryOffset) = copyChar;
        targetEntryOffset = targetEntryOffset + 1;
        copyChar = *copySrc;
      } while (copyChar != '\0');
    }
    break;
  default:
    goto switchD_0000f394_default;
  }
  cursor = cursor + targetEntryOffset;
switchD_0000f394_default:
  return cursor;
}

/* arbProgramIrToText @ 0xf620 (27520 bytes) */
int arbProgramIrToText(program)
  uint *program;
{
  uint *labelsRemaining;
  int ensureOk;
  int emitLength7;
  uint maxTempId;
  uint tmpRegisterNumbers;
  uint *tempScanEntry;
  char *labelTarget;
  bool moreLabels;
  bool groupEnded;
  uint paramWord2;
  uint paramArraysLeft;
  uint tempArrayEndId;
  uint entriesRemaining;
  uint matrixModifier;
  uint texgenComponent;
  uint lightColorKind;
  uint lightFace;
  uint paramWord;
  uint paramRegisterId;
  uint branchWord;
  uint opcodeBits;
  uint swapSource;
  uint outputPrecision;
  uint tempArraysLeft;
  int floatTextCursor;
  int entriesLeft;
  int emitLength6;
  int labelNumberLength;
  int labelIndex;
  int scanEntryIndex;
  int paramArrayIndex;
  int descriptorByteOffset;
  int idTableBytes;
  int tmpArrayLengths;
  int labelSearchIndex;
  int indentIndex;
  int descriptorOffset;
  int groupIndex;
  int nestingDepth;
  int branchTargetCount;
  int groupIndexCounter;
  int groupElementIndex;
  int registerNumberLength;
  int reallocOk;
  uint loopIndex;
  uint *labelInsertCursor;
  uint *arrayLengthCursor;
  uint *paramRemaining;
  uint *firstOperand;
  uint *swapTemp;
  uint *branchTarget;
  uint *paramArrayLengths;
  uint *paramScanEntry;
  uint *labelCount;
  uint *outputEntry;
  uint *paramCount;
  uint *attribEntry;
  uint *tempEntry;
  uint *optionEntry;
  uint *labelCountNext;
  uint *paramEntry;
  uint *nextTempEntry;
  uint *tempArrayTable;
  uint *labelSourceCursor;
  int emitLength3;
  int emitLength5;
  int emitLength4;
  int emitLength2;
  int emitLength;
  uint *isShaderObject;
  bool separatorNotEmpty;
  bool isAssemblyProgram;
  bool noLabels;
  ushort entryHalfword;
  undefined1 *lineStart;
  int bufferOk;
  uint entryWord;
  char copyChar;
  char nextChar;
  char *srcCursor;
  char *separatorSrc;
  undefined1 *lineCursor;
  char *indentLength;
  undefined4 cursorAfterPrecision;
  uint modifierWord;
  uint *argReg6;
  uint declWord;
  uint argReg7;
  uint *argReg8;
  uint *paramArrayTable;
  char curChar;
  int groupByteOffset;
  int elementsSoFar;
  int *branchTargetCursor;
  uint *paramScanCursor;
  char *argReg10;
  int labelsToShift;
  undefined1 *entryIndex;
  uint *tmpGroupState;
  int tmpArrayByteOffset;
  uint *currentTempEntry;
  uint opcode;
  uint *instructionRecord;
  uint *arrayDescriptor;
  uint paramArrayEndId;
  float *constantVector;
  uint addressRegIndex;
  dword *operandEntriesUsed;
  uint loopCounter;
  ushort paramKind;
  uint *paramLoopCursor;
  ulonglong printResult;
  undefined8 floatPrintResult;
  int outBuffer;
  undefined1 *outCursor;
  uint programTarget;
  uint instructionOffset;
  uint optionCount;
  uint addressRegCount;
  uint tempCount;
  uint attribCount;
  uint outputCount;
  uint instructionCount;
  int outCapacity [2];
  uint *branchSources;
  int *branchTargets;
  uint *paramGroupState;
  int paramRegisterNumbers;
  int semicolonBase;
  char *mnemonicTableBase;
  int commaSeparatorBase;
  undefined1 **outCursorPtr;
  int *outCapacityPtr;
  int newlineBase;
  
  outCapacity[0] = 0x800;
  outBuffer = _malloc(0x800);
  if (outBuffer == 0) {
    return 0;
  }
  programTarget = *program;
  isShaderObject = (uint *)(uint)(programTarget - 0x8b30 < 2);
  if (programTarget == 0x8804) {
    emitLength = 0;
    if (s___ARBfp1_0_001a4584[0] != '\0') {
      srcCursor = "!!ARBfp1.0\n";
      curChar = s___ARBfp1_0_001a4584[0];
      do {
        srcCursor = srcCursor + 1;
        nextChar = *srcCursor;
        *(char *)(outBuffer + emitLength) = curChar;
        emitLength = emitLength + 1;
        curChar = nextChar;
      } while (nextChar != '\0');
    }
  }
  else if (programTarget < 0x8805) {
    if (programTarget == 0x8620) {
      emitLength = 0;
      if (s___ARBvp1_0_001a4564[0] != '\0') {
        srcCursor = "!!ARBvp1.0\n";
        curChar = s___ARBvp1_0_001a4564[0];
        do {
          srcCursor = srcCursor + 1;
          nextChar = *srcCursor;
          *(char *)(outBuffer + emitLength) = curChar;
          emitLength = emitLength + 1;
          curChar = nextChar;
        } while (nextChar != '\0');
      }
    }
    else {
LAB_0000f6a4:
      if (s_Unkown_Target__error__001a45a8[0] == '\0') {
        emitLength = 0;
      }
      else {
        srcCursor = "Unkown Target (error)\n";
        emitLength = 0;
        curChar = s_Unkown_Target__error__001a45a8[0];
        do {
          srcCursor = srcCursor + 1;
          nextChar = *srcCursor;
          *(char *)(outBuffer + emitLength) = curChar;
          emitLength = emitLength + 1;
          curChar = nextChar;
        } while (nextChar != '\0');
      }
    }
  }
  else if (programTarget == 0x8b30) {
    emitLength = 0;
    if (s___ARBfragmentshader_001a4590[0] != '\0') {
      srcCursor = "!!ARBfragmentshader\n";
      curChar = s___ARBfragmentshader_001a4590[0];
      do {
        srcCursor = srcCursor + 1;
        nextChar = *srcCursor;
        *(char *)(outBuffer + emitLength) = curChar;
        emitLength = emitLength + 1;
        curChar = nextChar;
      } while (nextChar != '\0');
    }
  }
  else {
    if (programTarget != 0x8b31) goto LAB_0000f6a4;
    emitLength = 0;
    if (s___ARBvertexshader_001a4570[0] != '\0') {
      srcCursor = "!!ARBvertexshader\n";
      curChar = s___ARBvertexshader_001a4570[0];
      do {
        srcCursor = srcCursor + 1;
        nextChar = *srcCursor;
        *(char *)(outBuffer + emitLength) = curChar;
        emitLength = emitLength + 1;
        curChar = nextChar;
      } while (nextChar != '\0');
    }
  }
  outCursor = (undefined1 *)(emitLength + outBuffer);
  isAssemblyProgram = isShaderObject == (uint *)0x0;
  if (!isAssemblyProgram) {
    newlineBase = 0x19f634;
    emitLength = 0;
    if (s__001a45c0[0] != '\0') {
      srcCursor = "\n";
      emitLength = 0;
      curChar = s__001a45c0[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[emitLength] = curChar;
        emitLength = emitLength + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    outCursor = outCursor + emitLength;
  }
  optionCount = program[0x12];
  optionEntry = program + program[0x13] * 2;
  if (0 < (int)optionCount) {
    outCursorPtr = &outCursor;
    outCapacityPtr = outCapacity;
    loopIndex = 0;
    do {
      emitLength = 0;
      if (s_OPTION_001a45c4[0] != '\0') {
        srcCursor = "OPTION ";
        emitLength = 0;
        curChar = s_OPTION_001a45c4[0];
        do {
          srcCursor = srcCursor + 1;
          outCursor[emitLength] = curChar;
          emitLength = emitLength + 1;
          curChar = *srcCursor;
        } while (curChar != '\0');
      }
      outCursor = outCursor + emitLength;
      switch((char)*optionEntry) {
      case '\0':
        emitLength = 0;
        if (s_ARB_position_invariant_001a45cc[0] != '\0') {
          srcCursor = "ARB_position_invariant";
          curChar = s_ARB_position_invariant_001a45cc[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\x01':
        emitLength = 0;
        if (s_ARB_fog_exp_001a45e4[0] != '\0') {
          srcCursor = "ARB_fog_exp";
          curChar = s_ARB_fog_exp_001a45e4[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\x02':
        emitLength = 0;
        if (s_ARB_fog_exp2_001a45f0[0] != '\0') {
          srcCursor = "ARB_fog_exp2";
          curChar = s_ARB_fog_exp2_001a45f0[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\x03':
        emitLength = 0;
        if (s_ARB_fog_linear_001a4600[0] != '\0') {
          srcCursor = "ARB_fog_linear";
          curChar = s_ARB_fog_linear_001a4600[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\x04':
        emitLength = 0;
        if (s_ARB_precision_hint_fastest_001a4610[0] != '\0') {
          srcCursor = "ARB_precision_hint_fastest";
          curChar = s_ARB_precision_hint_fastest_001a4610[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\x05':
        emitLength = 0;
        if (s_ARB_precision_hint_nicest_001a462c[0] != '\0') {
          srcCursor = "ARB_precision_hint_nicest";
          curChar = s_ARB_precision_hint_nicest_001a462c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\x06':
        emitLength = 0;
        if (s_APPLE_no_runtime_compile_001a4648[0] != '\0') {
          srcCursor = "APPLE_no_runtime_compile";
          curChar = s_APPLE_no_runtime_compile_001a4648[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\a':
        emitLength = 0;
        if (s_APPLE_no_altivec_001a4664[0] != '\0') {
          srcCursor = "APPLE_no_altivec";
          curChar = s_APPLE_no_altivec_001a4664[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\b':
        emitLength = 0;
        if (s_NV_fragment_program_001a4678[0] != '\0') {
          srcCursor = "NV_fragment_program";
          curChar = s_NV_fragment_program_001a4678[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\t':
        emitLength = 0;
        if (s_NV_fragment_program2_001a468c[0] != '\0') {
          srcCursor = "NV_fragment_program2";
          curChar = s_NV_fragment_program2_001a468c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\n':
        emitLength = 0;
        if (s_NV_vertex_program2_001a46c0[0] != '\0') {
          srcCursor = "NV_vertex_program2";
          curChar = s_NV_vertex_program2_001a46c0[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\v':
        emitLength = 0;
        if (s_NV_vertex_program3_001a46d4[0] != '\0') {
          srcCursor = "NV_vertex_program3";
          curChar = s_NV_vertex_program3_001a46d4[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\f':
        emitLength = 0;
        if (s_ARB_draw_buffers_001a46e8[0] != '\0') {
          srcCursor = "ARB_draw_buffers";
          curChar = s_ARB_draw_buffers_001a46e8[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case '\r':
        emitLength = 0;
        if (s_ARB_fragment_program_shadow_001a46a4[0] != '\0') {
          srcCursor = "ARB_fragment_program_shadow";
          curChar = s_ARB_fragment_program_shadow_001a46a4[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      default:
        goto switchD_0000f958_default;
      }
      outCursor = outCursor + emitLength;
switchD_0000f958_default:
      emitLength = 0;
      if (s___001a46fc[0] != '\0') {
        srcCursor = ";\n";
        emitLength = 0;
        curChar = s___001a46fc[0];
        do {
          srcCursor = srcCursor + 1;
          outCursor[emitLength] = curChar;
          emitLength = emitLength + 1;
          curChar = *srcCursor;
        } while (curChar != '\0');
      }
      outCursor = outCursor + emitLength;
      bufferOk = ((int (*)())textBufferEnsureRoom)(outCapacityPtr,&outBuffer,outCursorPtr);
      if (bufferOk == 0) goto LAB_00016630;
      loopIndex = loopIndex + 1;
      optionEntry = optionEntry + 2;
    } while (optionCount != loopIndex);
  }
  if ((optionCount != 0) && (!isAssemblyProgram)) {
    emitLength = 0;
    if (s__001a45c0[0] != '\0') {
      srcCursor = "\n";
      emitLength = 0;
      curChar = s__001a45c0[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[emitLength] = curChar;
        emitLength = emitLength + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    outCursor = outCursor + emitLength;
  }
  addressRegCount = program[6];
  if (addressRegCount != 0) {
    emitLength = 0;
    if (s_ADDRESS_adr0_001a4700[0] != '\0') {
      srcCursor = "ADDRESS adr0";
      curChar = s_ADDRESS_adr0_001a4700[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[emitLength] = curChar;
        emitLength = emitLength + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    outCursor = outCursor + emitLength;
    if (1 < (int)addressRegCount) {
      addressRegIndex = 1;
      do {
        emitLength = 0;
        if (s___adr_001a4710[0] != '\0') {
          srcCursor = ", adr";
          emitLength = 0;
          curChar = s___adr_001a4710[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength;
        loopCounter = addressRegIndex + 1;
        emitLength = ((int (*)())textPrintSignedDecimal)(outCursor,addressRegIndex);
        outCursor = outCursor + emitLength;
        addressRegIndex = loopCounter;
      } while (addressRegCount != loopCounter);
    }
    emitLength = 0;
    if (s___001a46fc[0] != '\0') {
      srcCursor = ";\n";
      curChar = s___001a46fc[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[emitLength] = curChar;
        emitLength = emitLength + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    outCursor = outCursor + emitLength;
    bufferOk = ((int (*)())textBufferEnsureRoom)(outCapacity,&outBuffer,&outCursor);
    if (bufferOk == 0) goto LAB_00016630;
    if (!isAssemblyProgram) {
      emitLength = 0;
      if (s__001a45c0[0] != '\0') {
        srcCursor = "\n";
        emitLength = 0;
        curChar = s__001a45c0[0];
        do {
          srcCursor = srcCursor + 1;
          outCursor[emitLength] = curChar;
          emitLength = emitLength + 1;
          curChar = *srcCursor;
        } while (curChar != '\0');
      }
      outCursor = outCursor + emitLength;
    }
  }
  tempCount = program[4];
  tempEntry = program + program[5] * 2;
  if (isAssemblyProgram) {
    if (0 < (int)tempCount) {
      tmpRegisterNumbers = 0;
      tmpGroupState = (uint *)0x0;
      tmpArrayLengths = 0;
LAB_0001025c:
      outCapacityPtr = outCapacity;
      outCursorPtr = &outCursor;
      groupIndex = 0;
      loopCounter = 0;
      groupElementIndex = -1;
      do {
        argReg6 = tempEntry + loopCounter * 2;
        entryWord = tempEntry[loopCounter * 2] >> 0x1d;
        if (entryWord == 1) {
          emitLength2 = 0;
          if (s_LONG_TEMP_001a4720[0] != '\0') {
            srcCursor = "LONG TEMP ";
            curChar = s_LONG_TEMP_001a4720[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength2] = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
LAB_00010394:
          outCursor = outCursor + emitLength2;
        }
        else {
          if (entryWord == 2) {
            emitLength2 = 0;
            if (s_SHORT_TEMP_001a472c[0] != '\0') {
              srcCursor = "SHORT TEMP ";
              curChar = s_SHORT_TEMP_001a472c[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength2] = curChar;
                emitLength2 = emitLength2 + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            goto LAB_00010394;
          }
          if (entryWord == 0) {
            emitLength2 = 0;
            if (s_TEMP_001a4718[0] != '\0') {
              srcCursor = "TEMP ";
              curChar = s_TEMP_001a4718[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength2] = curChar;
                emitLength2 = emitLength2 + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            goto LAB_00010394;
          }
        }
        entryWord = *argReg6;
        currentTempEntry = argReg6;
        do {
          if (isAssemblyProgram) {
            emitLength2 = 0;
            if (s_tmp_001a4460[0] != '\0') {
              srcCursor = "tmp";
              curChar = s_tmp_001a4460[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength2] = curChar;
                emitLength2 = emitLength2 + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            outCursor = outCursor + emitLength2;
            emitLength2 = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)*(ushort *)((int)currentTempEntry + 6));
            outCursor = outCursor + emitLength2;
          }
          else if (tmpGroupState[*(ushort *)((int)currentTempEntry + 6)] == 0xffffffff) {
            emitLength2 = 0;
            if (s_tmp_001a4460[0] != '\0') {
              srcCursor = "tmp";
              curChar = s_tmp_001a4460[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength2] = curChar;
                emitLength2 = emitLength2 + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            outCursor = outCursor + emitLength2;
            emitLength2 = ((int (*)())textPrintSignedDecimal)(outCursor,*(undefined4 *)
                                            (tmpRegisterNumbers + (uint)*(ushort *)((int)currentTempEntry + 6) * 4));
            outCursor = outCursor + emitLength2;
            declWord = *currentTempEntry;
            argReg7 = declWord >> 0x1d;
            argReg6 = (uint *)(declWord >> 0x1a & 7);
            outCursor = (undefined1 *)((int (*)())arbIrPrintDeclSizeSuffix)(outCursor,declWord >> 0x18 & 3,0,argReg6,argReg7);
          }
          else {
            if (tmpGroupState[*(ushort *)((int)currentTempEntry + 6)] == 0) {
              emitLength5 = 0;
              if (s_tmp_001a4460[0] != '\0') {
                srcCursor = "tmp";
                curChar = s_tmp_001a4460[0];
                do {
                  srcCursor = srcCursor + 1;
                  outCursor[emitLength5] = curChar;
                  emitLength5 = emitLength5 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
              }
              outCursor = outCursor + emitLength5;
              emitLength6 = ((int (*)())textPrintSignedDecimal)(outCursor,*(undefined4 *)
                                              (tmpRegisterNumbers + (uint)*(ushort *)((int)currentTempEntry + 6) * 4));
              emitLength2 = 0;
              if (s___001a4464[0] != '\0') {
                srcCursor = "[";
                curChar = s___001a4464[0];
                do {
                  srcCursor = srcCursor + 1;
                  outCursor[emitLength2 + emitLength6] = curChar;
                  emitLength2 = emitLength2 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
              }
              outCursor = outCursor + emitLength2 + emitLength6;
              groupByteOffset = groupIndex * 4;
              emitLength6 = ((int (*)())textPrintSignedDecimal)(outCursor,*(undefined4 *)(tmpArrayLengths + groupByteOffset));
              emitLength4 = 0;
              if (s___001a4468[0] != '\0') {
                srcCursor = "]";
                curChar = s___001a4468[0];
                do {
                  srcCursor = srcCursor + 1;
                  outCursor[emitLength4 + emitLength6] = curChar;
                  emitLength4 = emitLength4 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
              }
              outCursor = outCursor + emitLength4 + emitLength6;
              declWord = *currentTempEntry;
              argReg7 = declWord >> 0x1d;
              argReg6 = (uint *)(declWord >> 0x1a & 7);
              outCursor = (undefined1 *)((int (*)())arbIrPrintDeclSizeSuffix)(outCursor,declWord >> 0x18 & 3,0,argReg6,argReg7);
              groupElementIndex = 0;
              elementsSoFar = 1;
            }
            else {
              groupByteOffset = groupIndex << 2;
              elementsSoFar = groupElementIndex + 2;
              groupElementIndex = groupElementIndex + 1;
            }
            if (elementsSoFar == *(int *)(tmpArrayLengths + groupByteOffset)) {
              groupIndex = groupIndex + 1;
              groupElementIndex = -1;
            }
          }
          loopCounter = loopCounter + 1;
          if (tempCount == loopCounter) {
            emitLength2 = 0;
            if (s___001a46fc[0] != '\0') {
              srcCursor = ";\n";
              curChar = s___001a46fc[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength2] = curChar;
                emitLength2 = emitLength2 + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
LAB_00010780:
            outCursor = outCursor + emitLength2;
            groupEnded = false;
          }
          else if (currentTempEntry[2] >> 0x1d == entryWord >> 0x1d) {
            groupEnded = false;
            if (groupElementIndex == -1) {
              emitLength2 = 0;
              if (s___001a44f4[0] != '\0') {
                srcCursor = ", ";
                curChar = s___001a44f4[0];
                do {
                  srcCursor = srcCursor + 1;
                  outCursor[emitLength2] = curChar;
                  emitLength2 = emitLength2 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
              }
              goto LAB_00010780;
            }
          }
          else {
            emitLength2 = 0;
            if (s___001a46fc[0] != '\0') {
              srcCursor = ";\n";
              curChar = s___001a46fc[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength2] = curChar;
                emitLength2 = emitLength2 + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            outCursor = outCursor + emitLength2;
            groupEnded = true;
          }
          reallocOk = ((int (*)())textBufferEnsureRoom)(outCapacityPtr,&outBuffer,outCursorPtr);
          if (reallocOk == 0) goto LAB_00014070;
          if ((int)tempCount <= (int)loopCounter) goto LAB_000107a8;
          currentTempEntry = currentTempEntry + 2;
        } while (!groupEnded);
      } while( true );
    }
    groupElementIndex = -1;
    tmpGroupState = (uint *)0x0;
    tmpRegisterNumbers = 0;
  }
  else {
    if (0 < (int)tempCount) {
      maxTempId = 0xffffffff;
      tempScanEntry = tempEntry;
      entriesRemaining = tempCount;
      do {
        if ((int)maxTempId < (int)(uint)*(ushort *)((int)tempScanEntry + 6)) {
          maxTempId = (uint)*(ushort *)((int)tempScanEntry + 6);
        }
        tempScanEntry = tempScanEntry + 2;
        entriesRemaining = entriesRemaining - 1;
      } while (entriesRemaining != 0);
      if (maxTempId == 0xffffffff) goto LAB_000100c0;
      idTableBytes = maxTempId * 4 + 4;
      tmpRegisterNumbers = _malloc(idTableBytes);
      tmpGroupState = (uint *)_malloc(idTableBytes);
      if (tmpRegisterNumbers == 0) {
        if (tmpGroupState != (uint *)0x0) {
LAB_000163f0:
          _free(tmpGroupState);
        }
        goto LAB_00016630;
      }
      if (tmpGroupState == (uint *)0x0) {
        _free(tmpRegisterNumbers);
        goto LAB_00016630;
      }
    }
    else {
LAB_000100c0:
      tmpRegisterNumbers = 0;
      tmpGroupState = (uint *)0x0;
    }
    tmpArrayLengths = 0;
    if (program[0x10] != 0) {
      tmpArrayLengths = _malloc(program[0x10] << 2);
    }
    if (0 < (int)tempCount) {
      groupIndexCounter = 0;
      argReg8 = (uint *)0x0;
      argReg7 = 0xffffffff;
      tempArrayEndId = 0xffffffff;
      do {
        argReg10 = (char *)(tempEntry + (int)argReg8 * 2);
        *(uint *)((uint)*(ushort *)((int)argReg10 + 6) * 4 + tmpRegisterNumbers) =
             (uint)*(ushort *)((int)argReg10 + 6);
        tempArraysLeft = program[0x10];
        entryWord = (uint)*(ushort *)((int)argReg10 + 6);
        tempArrayTable = program + program[0x11] * 2;
        if ((tempArraysLeft == 0) || ((int)tempArraysLeft < 1)) {
LAB_00010194:
          tmpGroupState[entryWord] = argReg7;
          entryWord = 0xffffffff;
        }
        else {
          arrayDescriptor = tempArrayTable;
          if (entryWord != (ushort)*tempArrayTable) {
            descriptorOffset = 8;
            do {
              tempArraysLeft = tempArraysLeft - 1;
              if (tempArraysLeft == 0) goto LAB_00010194;
              arrayDescriptor = (uint *)((int)tempArrayTable + descriptorOffset);
              descriptorOffset = descriptorOffset + 8;
            } while (entryWord != (ushort)*arrayDescriptor);
          }
          tempArrayEndId = (uint)*(ushort *)((int)arrayDescriptor + 6);
          argReg7 = 1;
          tmpGroupState[entryWord] = 0;
        }
        if (*(ushort *)((int)argReg10 + 6) == tempArrayEndId) {
          tmpArrayByteOffset = groupIndexCounter * 4;
          entryWord = 0xffffffff;
          groupIndexCounter = groupIndexCounter + 1;
          tempArrayEndId = 0xffffffff;
          *(uint *)(tmpArrayLengths + tmpArrayByteOffset) = argReg7;
          argReg7 = 0xffffffff;
        }
        entriesLeft = tempCount - (int)argReg8;
        nextTempEntry = tempEntry + (int)argReg8 * 2 + 2;
        if (((int)tempCount < (int)argReg8 + 1) || (tempCount == 0x80000000)) {
          entriesLeft = 1;
        }
        while( true ) {
          argReg8 = (uint *)((int)argReg8 + 1);
          entriesLeft = entriesLeft + -1;
          if (entriesLeft == 0) goto LAB_0001025c;
          if (entryWord == 0xffffffff) break;
          if ((int)(uint)*(ushort *)((int)nextTempEntry + 6) <= (int)tempArrayEndId) {
            *(uint *)((uint)*(ushort *)((int)nextTempEntry + 6) * 4 + tmpRegisterNumbers) = entryWord;
            tmpGroupState[*(ushort *)((int)nextTempEntry + 6)] = argReg7;
            argReg7 = argReg7 + 1;
            if (*(ushort *)((int)nextTempEntry + 6) == tempArrayEndId) {
              groupByteOffset = groupIndexCounter * 4;
              entryWord = 0xffffffff;
              groupIndexCounter = groupIndexCounter + 1;
              tempArrayEndId = 0xffffffff;
              *(uint *)(tmpArrayLengths + groupByteOffset) = argReg7;
              argReg7 = 0xffffffff;
            }
          }
          nextTempEntry = nextTempEntry + 2;
        }
      } while( true );
    }
    groupElementIndex = -1;
LAB_000107a8:
    if (tmpArrayLengths != 0) {
      _free(tmpArrayLengths);
    }
  }
  if ((tempCount != 0) && (!isAssemblyProgram)) {
    emitLength = 0;
    if (s__001a45c0[0] != '\0') {
      srcCursor = "\n";
      emitLength = 0;
      curChar = s__001a45c0[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[emitLength] = curChar;
        emitLength = emitLength + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    outCursor = outCursor + emitLength;
  }
  attribCount = program[8];
  attribEntry = program + program[9] * 2;
  if (0 < (int)attribCount) {
    loopCounter = 0;
    do {
      entryHalfword = *(ushort *)attribEntry;
      if ((entryHalfword & 0xf) != 0) {
        emitLength = 0;
        if (s_ATTRIB_att_001a4738[0] != '\0') {
          srcCursor = "ATTRIB att";
          curChar = s_ATTRIB_att_001a4738[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength;
        emitLength = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)*(ushort *)((int)attribEntry + 6));
        outCursor = outCursor + emitLength;
        if (!isAssemblyProgram) {
          entryWord = *attribEntry;
          argReg7 = entryWord >> 0x1d;
          argReg6 = (uint *)(entryWord >> 0x1a & 7);
          outCursor = (undefined1 *)((int (*)())arbIrPrintDeclSizeSuffix)(outCursor,entryWord >> 0x18 & 3,0,argReg6,argReg7);
        }
        if (programTarget == 0x8804) {
LAB_00010974:
          emitLength = 0;
          if (s___fragment__001a4750[0] != '\0') {
            srcCursor = " = fragment.";
            curChar = s___fragment__001a4750[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
LAB_000109bc:
          outCursor = outCursor + emitLength;
        }
        else if (programTarget < 0x8805) {
          if (programTarget == 0x8620) {
LAB_0001092c:
            emitLength = 0;
            if (s___vertex__001a4744[0] != '\0') {
              srcCursor = " = vertex.";
              curChar = s___vertex__001a4744[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength] = curChar;
                emitLength = emitLength + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            goto LAB_000109bc;
          }
        }
        else {
          if (programTarget == 0x8b30) goto LAB_00010974;
          if (programTarget == 0x8b31) goto LAB_0001092c;
        }
        switch(entryHalfword & 0xf) {
        default:
          goto switchD_000109e4_caseD_0;
        case 1:
          emitLength = 0;
          if (s_position_001a4760[0] != '\0') {
            srcCursor = "position";
            curChar = s_position_001a4760[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 2:
          emitLength = 0;
          if (s_color_primary_001a476c[0] != '\0') {
            srcCursor = "color.primary";
            curChar = s_color_primary_001a476c[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 3:
          emitLength = 0;
          if (s_color_secondary_001a477c[0] != '\0') {
            srcCursor = "color.secondary";
            curChar = s_color_secondary_001a477c[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 4:
          emitLength = 0;
          if (s_normal_001a478c[0] != '\0') {
            srcCursor = "normal";
            curChar = s_normal_001a478c[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 5:
          emitLength = 0;
          if (s_fogcoord_001a4794[0] != '\0') {
            srcCursor = "fogcoord";
            curChar = s_fogcoord_001a4794[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 6:
          emitLength = 0;
          if (s_weight__001a47b8[0] != '\0') {
            srcCursor = "weight[";
            curChar = s_weight__001a47b8[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength;
          emitLength3 = ((int (*)())textPrintSignedDecimal)(outCursor,*attribEntry & 0x1f);
          emitLength = 0;
          outCursor = outCursor + emitLength3;
          if (s___001a4468[0] != '\0') {
            srcCursor = "]";
            curChar = s___001a4468[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 7:
          emitLength = 0;
          if (s_texcoord__001a47ac[0] != '\0') {
            srcCursor = "texcoord[";
            curChar = s_texcoord__001a47ac[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength;
          emitLength3 = ((int (*)())textPrintSignedDecimal)(outCursor,*attribEntry & 0x1f);
          emitLength = 0;
          outCursor = outCursor + emitLength3;
          if (s___001a4468[0] != '\0') {
            srcCursor = "]";
            curChar = s___001a4468[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 8:
          emitLength = 0;
          if (s_matrixindex__001a47c0[0] != '\0') {
            srcCursor = "matrixindex[";
            curChar = s_matrixindex__001a47c0[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength;
          emitLength3 = ((int (*)())textPrintSignedDecimal)(outCursor,*attribEntry & 0x1f);
          emitLength = 0;
          outCursor = outCursor + emitLength3;
          if (s___001a4468[0] != '\0') {
            srcCursor = "]";
            curChar = s___001a4468[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 9:
          emitLength = 0;
          if (s_attrib__001a47d0[0] != '\0') {
            srcCursor = "attrib[";
            curChar = s_attrib__001a47d0[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength;
          emitLength3 = ((int (*)())textPrintSignedDecimal)(outCursor,*attribEntry & 0x1f);
          emitLength = 0;
          outCursor = outCursor + emitLength3;
          if (s___001a4468[0] != '\0') {
            srcCursor = "]";
            curChar = s___001a4468[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 10:
          emitLength = 0;
          if (s_material__001a47d8[0] != '\0') {
            srcCursor = "material.";
            emitLength = 0;
            curChar = s_material__001a47d8[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          entryWord = *attribEntry;
          outCursor = outCursor + emitLength;
          if ((entryWord & 1) == 0) {
            emitLength = 0;
            if (s_front__001a47e4[0] != '\0') {
              srcCursor = "front.";
              curChar = s_front__001a47e4[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength] = curChar;
                emitLength = emitLength + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
LAB_00010f94:
              entryWord = *attribEntry;
            }
LAB_00010f9c:
            outCursor = outCursor + emitLength;
          }
          else if ((entryWord & 1) == 1) {
            emitLength = 0;
            if (s_back__001a47ec[0] != '\0') {
              srcCursor = "back.";
              curChar = s_back__001a47ec[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength] = curChar;
                emitLength = emitLength + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
              goto LAB_00010f94;
            }
            goto LAB_00010f9c;
          }
          switch(entryWord >> 0xc & 0xf) {
          case 0:
            emitLength = 0;
            if (s_ambient_001a47f4[0] != '\0') {
              srcCursor = "ambient";
              curChar = s_ambient_001a47f4[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength] = curChar;
                emitLength = emitLength + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            break;
          case 1:
            emitLength = 0;
            if (s_diffuse_001a47fc[0] != '\0') {
              srcCursor = "diffuse";
              curChar = s_diffuse_001a47fc[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength] = curChar;
                emitLength = emitLength + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            break;
          case 2:
            emitLength = 0;
            if (s_specular_001a4804[0] != '\0') {
              srcCursor = "specular";
              curChar = s_specular_001a4804[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength] = curChar;
                emitLength = emitLength + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            break;
          case 3:
            emitLength = 0;
            if (s_emission_001a4810[0] != '\0') {
              srcCursor = "emission";
              curChar = s_emission_001a4810[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength] = curChar;
                emitLength = emitLength + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            break;
          case 4:
            emitLength = 0;
            if (s_shininess_001a481c[0] != '\0') {
              srcCursor = "shininess";
              curChar = s_shininess_001a481c[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength] = curChar;
                emitLength = emitLength + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            break;
          default:
            goto switchD_000109e4_caseD_0;
          }
          break;
        case 0xb:
          emitLength = 0;
          if (s_frontfacing_001a47a0[0] != '\0') {
            srcCursor = "frontfacing";
            curChar = s_frontfacing_001a47a0[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        outCursor = outCursor + emitLength;
switchD_000109e4_caseD_0:
        emitLength = 0;
        if (s___001a46fc[0] != '\0') {
          srcCursor = ";\n";
          curChar = s___001a46fc[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength;
        bufferOk = ((int (*)())textBufferEnsureRoom)(outCapacity,&outBuffer,&outCursor);
        if (bufferOk == 0) goto LAB_00014070;
      }
      loopCounter = loopCounter + 1;
      attribEntry = attribEntry + 2;
    } while (attribCount != loopCounter);
  }
  if ((attribCount != 0) && (!isAssemblyProgram)) {
    emitLength = 0;
    if (s__001a45c0[0] != '\0') {
      srcCursor = "\n";
      emitLength = 0;
      curChar = s__001a45c0[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[emitLength] = curChar;
        emitLength = emitLength + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    outCursor = outCursor + emitLength;
  }
  paramCount = (uint *)program[10];
  paramEntry = program + program[0xb] * 2;
  if (paramCount == (uint *)0x0) {
    paramRegisterNumbers = 0;
    paramGroupState = (uint *)0x0;
    goto LAB_0001376c;
  }
  if ((int)paramCount < 1) {
LAB_000112d0:
    paramRegisterNumbers = 0;
    paramGroupState = (uint *)0x0;
  }
  else {
    paramArrayEndId = 0xffffffff;
    paramScanEntry = paramEntry;
    paramRemaining = paramCount;
    do {
      if ((int)paramArrayEndId < (int)(uint)*(ushort *)((int)paramScanEntry + 6)) {
        paramArrayEndId = (uint)*(ushort *)((int)paramScanEntry + 6);
      }
      paramScanEntry = paramScanEntry + 2;
      paramRemaining = (uint *)((int)paramRemaining - 1);
    } while (paramRemaining != (uint *)0x0);
    if (paramArrayEndId == 0xffffffff) goto LAB_000112d0;
    idTableBytes = paramArrayEndId * 4 + 4;
    paramRegisterNumbers = _malloc(idTableBytes);
    paramGroupState = (uint *)_malloc(idTableBytes);
    if (paramRegisterNumbers == 0) goto joined_r0x000112bc;
    if (paramGroupState == (uint *)0x0) {
      _free(paramRegisterNumbers);
      goto LAB_00014070;
    }
  }
  paramArrayLengths = (uint *)0x0;
  if (program[0xe] != 0) {
    paramArrayLengths = (uint *)_malloc(program[0xe] << 2);
  }
  if ((int)paramCount >= 1) {
    argReg10 = (char *)0x0;
    argReg7 = 0xffffffff;
    argReg6 = (uint *)0xffffffff;
    paramArrayEndId = 0xffffffff;
    arrayLengthCursor = paramArrayLengths;
    paramScanCursor = paramEntry;
    do {
      if ((*paramScanCursor & 0x1f0000) != 0) {
        if (argReg6 == (uint *)0xffffffff) {
          *(uint *)((uint)*(ushort *)((int)paramScanCursor + 6) * 4 + paramRegisterNumbers) =
               (uint)*(ushort *)((int)paramScanCursor + 6);
          paramArraysLeft = program[0xe];
          argReg6 = (uint *)(uint)*(ushort *)((int)paramScanCursor + 6);
          paramArrayTable = program + program[0xf] * 2;
          if ((paramArraysLeft == 0) || ((int)paramArraysLeft < 1)) {
LAB_000113ac:
            paramGroupState[(int)argReg6] = argReg7;
            argReg6 = (uint *)0xffffffff;
            argReg8 = paramArrayTable;
          }
          else {
            argReg8 = paramArrayTable;
            if (argReg6 != (uint *)(uint)(ushort)*paramArrayTable) {
              descriptorByteOffset = 8;
              do {
                paramArraysLeft = paramArraysLeft - 1;
                if (paramArraysLeft == 0) goto LAB_000113ac;
                argReg8 = (uint *)((int)paramArrayTable + descriptorByteOffset);
                descriptorByteOffset = descriptorByteOffset + 8;
              } while (argReg6 != (uint *)(uint)(ushort)*argReg8);
            }
            paramArrayEndId = (uint)*(ushort *)((int)argReg8 + 6);
            argReg7 = 1;
            paramGroupState[(int)argReg6] = 0;
          }
          if (*(ushort *)((int)paramScanCursor + 6) == paramArrayEndId) {
LAB_00011410:
            *arrayLengthCursor = argReg7;
            argReg6 = (uint *)0xffffffff;
            arrayLengthCursor = arrayLengthCursor + 1;
            argReg7 = 0xffffffff;
            paramArrayEndId = 0xffffffff;
          }
        }
        else if ((int)(uint)*(ushort *)((int)paramScanCursor + 6) <= (int)paramArrayEndId) {
          *(uint **)((uint)*(ushort *)((int)paramScanCursor + 6) * 4 + paramRegisterNumbers) = argReg6;
          paramGroupState[*(ushort *)((int)paramScanCursor + 6)] = argReg7;
          argReg7 = argReg7 + 1;
          if (*(ushort *)((int)paramScanCursor + 6) == paramArrayEndId) goto LAB_00011410;
        }
      }
      printResult = (ulonglong)paramArrayEndId;
      argReg10 = (char *)((int)argReg10 + 1);
      paramScanCursor = paramScanCursor + 2;
    } while (paramCount != (uint *)argReg10);
    paramArrayIndex = 0;
    paramLoopCursor = (uint *)0x0;
    do {
      entryHalfword = *(ushort *)paramEntry;
      paramKind = entryHalfword & 0x1f;
      if ((entryHalfword & 0x1f) == 0) goto LAB_000136f0;
      paramRegisterId = (uint)*(ushort *)((int)paramEntry + 6);
      if (paramGroupState[paramRegisterId] == 0xffffffff) {
        emitLength3 = 0;
        if (s_PARAM_prm_001a4828[0] != '\0') {
          srcCursor = "PARAM prm";
          curChar = s_PARAM_prm_001a4828[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
          paramRegisterId = (uint)*(ushort *)((int)paramEntry + 6);
        }
        outCursor = outCursor + emitLength3;
        printResult = ((int (*)())textPrintSignedDecimal)(outCursor,*(undefined4 *)(paramRegisterNumbers + paramRegisterId * 4));
        outCursor = outCursor + (int)(printResult >> 0x20);
        if (!isAssemblyProgram) {
          paramWord = *paramEntry;
          argReg7 = paramWord >> 0x1d;
          argReg6 = (uint *)(paramWord >> 0x1a & 7);
          printResult = ((int (*)())arbIrPrintDeclSizeSuffix)(outCursor,paramWord >> 0x18 & 3,0,argReg6,argReg7);
          outCursor = (undefined1 *)(printResult >> 0x20);
        }
        emitLength3 = 0;
        if (s___001a4834[0] != '\0') {
          srcCursor = " = ";
          curChar = s___001a4834[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
LAB_00011758:
        outCursor = outCursor + emitLength3;
      }
      else {
        if (paramGroupState[paramRegisterId] != 0) {
          groupElementIndex = groupElementIndex + 1;
          emitLength3 = 0;
          if (s__001a4844[0] != '\0') {
            srcCursor = "    ";
            curChar = s__001a4844[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          goto LAB_00011758;
        }
        emitLength5 = 0;
        if (s_PARAM_prm_001a4828[0] != '\0') {
          srcCursor = "PARAM prm";
          curChar = s_PARAM_prm_001a4828[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength5] = curChar;
            emitLength5 = emitLength5 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
          paramRegisterId = (uint)*(ushort *)((int)paramEntry + 6);
        }
        outCursor = outCursor + emitLength5;
        emitLength6 = ((int (*)())textPrintSignedDecimal)(outCursor,*(undefined4 *)(paramRegisterNumbers + paramRegisterId * 4));
        emitLength3 = 0;
        if (s___001a4464[0] != '\0') {
          srcCursor = "[";
          curChar = s___001a4464[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3 + emitLength6] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3 + emitLength6;
        printResult = ((int (*)())textPrintSignedDecimal)(outCursor,paramArrayLengths[paramArrayIndex]);
        emitLength6 = (int)(printResult >> 0x20);
        emitLength3 = 0;
        if (s___001a4468[0] != '\0') {
          srcCursor = "]";
          curChar = s___001a4468[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3 + emitLength6] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3 + emitLength6;
        if (!isAssemblyProgram) {
          paramWord = *paramEntry;
          argReg7 = paramWord >> 0x1d;
          argReg6 = (uint *)(paramWord >> 0x1a & 7);
          printResult = ((int (*)())arbIrPrintDeclSizeSuffix)(outCursor,paramWord >> 0x18 & 3,0,argReg6,argReg7);
          outCursor = (undefined1 *)(printResult >> 0x20);
        }
        emitLength5 = 0;
        if (s_____001a4838[0] != '\0') {
          srcCursor = " = {\n    ";
          curChar = s_____001a4838[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength5] = curChar;
            emitLength5 = emitLength5 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength5;
        groupElementIndex = 0;
      }
      if ((entryHalfword & 0x1f) != 0) {
        if (paramKind < 3) {
          emitLength3 = 0;
          if (s_program__001a484c[0] != '\0') {
            srcCursor = "program.";
            curChar = s_program__001a484c[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          goto LAB_000118a8;
        }
        if (paramKind != 0x11) goto LAB_00011778;
        emitLength3 = 0;
        if (s__001a4134[0] != '\0') {
          srcCursor = "";
          copyChar = s__001a4134[0];
          do {
            outCursor[emitLength3] = copyChar;
            emitLength3 = emitLength3 + 1;
            copyChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (copyChar != '\0');
        }
        outCursor = outCursor + emitLength3;
switchD_000118c8_caseD_11:
        constantVector = (float *)(program + program[0x1b] * 2 + (uint)(ushort)*paramEntry * 4);
        switch(*paramEntry >> 0x1a & 7) {
        case 0:
        case 1:
          emitLength3 = 0;
          if (s___001a49dc[0] != '\0') {
            srcCursor = "{";
            curChar = s___001a49dc[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength3;
          commaSeparatorBase = 0x19f634;
          floatPrintResult = ((char * (*)())textPrintDoubleShortest)((int)(printResult >> 0x20),(int)printResult,outCursor,
                                (outBuffer + outCapacity[0]) - (int)outCursor,(double)*constantVector,
                                DOUBLE_001aa248);
          floatTextCursor = (int)((ulonglong)floatPrintResult >> 0x20);
          curChar = ((unsigned char *)0x00004ec0)[commaSeparatorBase];
          separatorNotEmpty = curChar != '\0';
          if (separatorNotEmpty) {
            srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
            emitLength2 = 0;
            nextChar = curChar;
            do {
              *(char *)(floatTextCursor + emitLength2) = nextChar;
              emitLength2 = emitLength2 + 1;
              nextChar = *srcCursor;
              srcCursor = srcCursor + 1;
            } while (nextChar != '\0');
          }
          else {
            emitLength2 = 0;
          }
          outCursor = (undefined1 *)(emitLength2 + floatTextCursor);
          floatPrintResult = ((char * (*)())textPrintDoubleShortest)(floatTextCursor,(int)floatPrintResult,outCursor,(outBuffer + outCapacity[0]) - (int)outCursor
                                ,(double)constantVector[1],DOUBLE_001aa248);
          floatTextCursor = (int)((ulonglong)floatPrintResult >> 0x20);
          if (separatorNotEmpty) {
            emitLength2 = 0;
            srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
            nextChar = curChar;
            do {
              *(char *)(floatTextCursor + emitLength2) = nextChar;
              emitLength2 = emitLength2 + 1;
              nextChar = *srcCursor;
              srcCursor = srcCursor + 1;
            } while (nextChar != '\0');
          }
          else {
            emitLength2 = 0;
          }
          outCursor = (undefined1 *)(emitLength2 + floatTextCursor);
          floatPrintResult = ((char * (*)())textPrintDoubleShortest)(floatTextCursor,(int)floatPrintResult,outCursor,(outBuffer + outCapacity[0]) - (int)outCursor
                                ,(double)constantVector[2],DOUBLE_001aa248);
          floatTextCursor = (int)((ulonglong)floatPrintResult >> 0x20);
          if (separatorNotEmpty) {
            emitLength2 = 0;
            srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
            do {
              *(char *)(floatTextCursor + emitLength2) = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
              srcCursor = srcCursor + 1;
            } while (curChar != '\0');
          }
          else {
            emitLength2 = 0;
          }
          outCursor = (undefined1 *)(emitLength2 + floatTextCursor);
          argReg6 = (uint *)((outBuffer + outCapacity[0]) - (int)outCursor);
          floatTextCursor = ((char * (*)())textPrintDoubleShortest)(floatTextCursor,(int)floatPrintResult,outCursor,argReg6,(double)constantVector[3],DOUBLE_001aa248
                               );
          emitLength2 = 0;
          if (s___001a49e0[0] != '\0') {
            srcCursor = "}";
            curChar = s___001a49e0[0];
            do {
              srcCursor = srcCursor + 1;
              *(char *)(floatTextCursor + emitLength2) = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = (undefined1 *)(emitLength2 + floatTextCursor);
          break;
        case 2:
          emitLength3 = 0;
          if (s_____Fixed_constant_data_not_curr_001a49e4[0] != '\0') {
            srcCursor = "{-- Fixed constant data not currently supported --}";
            curChar = s_____Fixed_constant_data_not_curr_001a49e4[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          goto LAB_000135c0;
        case 3:
        case 4:
          emitLength3 = 0;
          if (s___001a49dc[0] != '\0') {
            srcCursor = "{";
            curChar = s___001a49dc[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength3;
          commaSeparatorBase = 0x19f634;
          emitLength7 = ((int (*)())textPrintSignedDecimal)(outCursor, *(unsigned int *)constantVector);
          curChar = ((unsigned char *)0x00004ec0)[commaSeparatorBase];
          separatorNotEmpty = curChar != '\0';
          if (separatorNotEmpty) {
            srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
            emitLength2 = 0;
            nextChar = curChar;
            do {
              outCursor[emitLength2 + emitLength7] = nextChar;
              emitLength2 = emitLength2 + 1;
              nextChar = *srcCursor;
              srcCursor = srcCursor + 1;
            } while (nextChar != '\0');
          }
          else {
            emitLength2 = 0;
          }
          outCursor = outCursor + emitLength2 + emitLength7;
          emitLength7 = ((int (*)())textPrintSignedDecimal)(outCursor, ((unsigned int *)constantVector)[1]);
          if (separatorNotEmpty) {
            emitLength2 = 0;
            srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
            nextChar = curChar;
            do {
              outCursor[emitLength2 + emitLength7] = nextChar;
              emitLength2 = emitLength2 + 1;
              nextChar = *srcCursor;
              srcCursor = srcCursor + 1;
            } while (nextChar != '\0');
          }
          else {
            emitLength2 = 0;
          }
          outCursor = outCursor + emitLength2 + emitLength7;
          emitLength7 = ((int (*)())textPrintSignedDecimal)(outCursor, ((unsigned int *)constantVector)[2]);
          if (separatorNotEmpty) {
            emitLength2 = 0;
            srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
            do {
              outCursor[emitLength2 + emitLength7] = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
              srcCursor = srcCursor + 1;
            } while (curChar != '\0');
          }
          else {
            emitLength2 = 0;
          }
          outCursor = outCursor + emitLength2 + emitLength7;
          emitLength2 = ((int (*)())textPrintSignedDecimal)(outCursor, ((unsigned int *)constantVector)[3]);
          emitLength3 = 0;
          outCursor = outCursor + emitLength2;
          if (s___001a49e0[0] != '\0') {
            srcCursor = "}";
            curChar = s___001a49e0[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          goto LAB_000135c0;
        }
        goto switchD_000118c8_caseD_0;
      }
LAB_00011778:
      if (s_state__001a4858[0] == '\0') {
        emitLength3 = 0;
      }
      else {
        srcCursor = "state.";
        emitLength3 = 0;
        curChar = s_state__001a4858[0];
        do {
          srcCursor = srcCursor + 1;
          outCursor[emitLength3] = curChar;
          emitLength3 = emitLength3 + 1;
          curChar = *srcCursor;
        } while (curChar != '\0');
      }
LAB_000118a8:
      outCursor = outCursor + emitLength3;
      switch(paramKind) {
      default:
        goto switchD_000118c8_caseD_0;
      case 1:
        emitLength3 = 0;
        if (s_local__001a4860[0] != '\0') {
          srcCursor = "local[";
          curChar = s_local__001a4860[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3;
        emitLength2 = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)(ushort)*paramEntry);
        emitLength3 = 0;
        outCursor = outCursor + emitLength2;
        if (s___001a4468[0] != '\0') {
          srcCursor = "]";
          curChar = s___001a4468[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 2:
        emitLength3 = 0;
        if (s_env__001a4868[0] != '\0') {
          srcCursor = "env[";
          curChar = s_env__001a4868[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3;
        emitLength2 = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)(ushort)*paramEntry);
        emitLength3 = 0;
        outCursor = outCursor + emitLength2;
        if (s___001a4468[0] != '\0') {
          srcCursor = "]";
          curChar = s___001a4468[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 3:
        emitLength3 = 0;
        if (s_light__001a4870[0] != '\0') {
          srcCursor = "light[";
          curChar = s_light__001a4870[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3;
        emitLength3 = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)(byte)*paramEntry);
        emitLength2 = 0;
        if (s____001a4878[0] != '\0') {
          srcCursor = "].";
          curChar = s____001a4878[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength2 + emitLength3] = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength2 + emitLength3;
        switch(*paramEntry >> 8 & 0xf) {
        case 0:
          emitLength3 = 0;
          if (s_ambient_001a47f4[0] != '\0') {
            srcCursor = "ambient";
            curChar = s_ambient_001a47f4[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 1:
          emitLength3 = 0;
          if (s_diffuse_001a47fc[0] != '\0') {
            srcCursor = "diffuse";
            curChar = s_diffuse_001a47fc[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 2:
          emitLength3 = 0;
          if (s_specular_001a4804[0] != '\0') {
            srcCursor = "specular";
            curChar = s_specular_001a4804[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 3:
          emitLength3 = 0;
          if (s_position_001a4760[0] != '\0') {
            srcCursor = "position";
            curChar = s_position_001a4760[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 4:
          emitLength3 = 0;
          if (s_spot_direction_001a487c[0] != '\0') {
            srcCursor = "spot.direction";
            curChar = s_spot_direction_001a487c[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 5:
          emitLength3 = 0;
          if (s_attenuation_001a488c[0] != '\0') {
            srcCursor = "attenuation";
            curChar = s_attenuation_001a488c[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 6:
          emitLength3 = 0;
          if (s_half_001a4898[0] != '\0') {
            srcCursor = "half";
            curChar = s_half_001a4898[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 7:
          emitLength3 = 0;
          if (s_spotcutoff_001a48a0[0] != '\0') {
            srcCursor = "spotcutoff";
            curChar = s_spotcutoff_001a48a0[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        default:
          goto switchD_000118c8_caseD_0;
        }
        break;
      case 4:
        emitLength3 = 0;
        if (s_lightprod__001a48ac[0] != '\0') {
          srcCursor = "lightprod[";
          curChar = s_lightprod__001a48ac[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3;
        emitLength7 = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)(byte)*paramEntry);
        emitLength2 = 0;
        if (s____001a4878[0] != '\0') {
          srcCursor = "].";
          curChar = s____001a4878[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength2 + emitLength7] = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        paramWord2 = *paramEntry;
        outCursor = outCursor + emitLength2 + emitLength7;
        lightFace = paramWord2 >> 8 & 1;
        if (lightFace == 0) {
          emitLength3 = 0;
          if (s_front__001a47e4[0] != '\0') {
            srcCursor = "front.";
            curChar = s_front__001a47e4[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
LAB_00011f20:
            paramWord2 = *paramEntry;
          }
LAB_00011f28:
          outCursor = outCursor + emitLength3;
        }
        else if (lightFace == 1) {
          emitLength3 = 0;
          if (s_back__001a47ec[0] != '\0') {
            srcCursor = "back.";
            curChar = s_back__001a47ec[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
            goto LAB_00011f20;
          }
          goto LAB_00011f28;
        }
        lightColorKind = paramWord2 >> 9 & 3;
        if (lightColorKind == 1) {
          emitLength3 = 0;
          if (s_diffuse_001a47fc[0] != '\0') {
            srcCursor = "diffuse";
            curChar = s_diffuse_001a47fc[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        else if (lightColorKind == 2) {
          emitLength3 = 0;
          if (s_specular_001a4804[0] != '\0') {
            srcCursor = "specular";
            curChar = s_specular_001a4804[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        else {
          if (lightColorKind != 0) goto switchD_000118c8_caseD_0;
          emitLength3 = 0;
          if (s_ambient_001a47f4[0] != '\0') {
            srcCursor = "ambient";
            curChar = s_ambient_001a47f4[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        break;
      case 5:
        paramWord = *paramEntry;
        if ((paramWord >> 1 & 7) == 5) {
          emitLength3 = 0;
          if (s_lightmodel__001a48cc[0] != '\0') {
            srcCursor = "lightmodel.";
            curChar = s_lightmodel__001a48cc[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
LAB_00012114:
            paramWord = *paramEntry;
          }
        }
        else {
          emitLength3 = 0;
          if (s_material__001a47d8[0] != '\0') {
            srcCursor = "material.";
            curChar = s_material__001a47d8[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
            goto LAB_00012114;
          }
        }
        outCursor = outCursor + emitLength3;
        if ((paramWord & 1) == 0) {
          emitLength3 = 0;
          if (s_front__001a47e4[0] != '\0') {
            srcCursor = "front.";
            curChar = s_front__001a47e4[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
LAB_000121c4:
            paramWord = *paramEntry;
          }
LAB_000121cc:
          outCursor = outCursor + emitLength3;
        }
        else if ((paramWord & 1) == 1) {
          emitLength3 = 0;
          if (s_back__001a47ec[0] != '\0') {
            srcCursor = "back.";
            curChar = s_back__001a47ec[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
            goto LAB_000121c4;
          }
          goto LAB_000121cc;
        }
        switch(paramWord >> 1 & 7) {
        case 0:
          emitLength3 = 0;
          if (s_ambient_001a47f4[0] != '\0') {
            srcCursor = "ambient";
            curChar = s_ambient_001a47f4[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 1:
          emitLength3 = 0;
          if (s_diffuse_001a47fc[0] != '\0') {
            srcCursor = "diffuse";
            curChar = s_diffuse_001a47fc[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 2:
          emitLength3 = 0;
          if (s_specular_001a4804[0] != '\0') {
            srcCursor = "specular";
            curChar = s_specular_001a4804[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 3:
          emitLength3 = 0;
          if (s_emission_001a4810[0] != '\0') {
            srcCursor = "emission";
            curChar = s_emission_001a4810[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 4:
          emitLength3 = 0;
          if (s_shininess_001a481c[0] != '\0') {
            srcCursor = "shininess";
            curChar = s_shininess_001a481c[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 5:
          emitLength3 = 0;
          if (s_scenecolor_001a48d8[0] != '\0') {
            srcCursor = "scenecolor";
            curChar = s_scenecolor_001a48d8[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        default:
          goto switchD_000118c8_caseD_0;
        }
        break;
      case 6:
        emitLength3 = 0;
        if (s_lightmodel_ambient_001a48b8[0] != '\0') {
          srcCursor = "lightmodel.ambient";
          curChar = s_lightmodel_ambient_001a48b8[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 7:
        emitLength3 = 0;
        if (s_texgen__001a48e4[0] != '\0') {
          srcCursor = "texgen[";
          curChar = s_texgen__001a48e4[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3;
        emitLength7 = ((int (*)())textPrintSignedDecimal)(outCursor,*paramEntry & 0x1f);
        emitLength2 = 0;
        if (s___eye__001a48ec[0] != '\0') {
          srcCursor = "].eye.";
          curChar = s___eye__001a48ec[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength2 + emitLength7] = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength2 + emitLength7;
        texgenComponent = *paramEntry >> 5 & 7;
        if (texgenComponent == 1) {
          emitLength3 = 0;
          if (s_t_001a48f8[0] != '\0') {
            srcCursor = "t";
            curChar = s_t_001a48f8[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        else if (texgenComponent < 2) {
          if (texgenComponent != 0) goto switchD_000118c8_caseD_0;
          emitLength3 = 0;
          if (s_s_001a48f4[0] != '\0') {
            srcCursor = "s";
            curChar = s_s_001a48f4[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        else if (texgenComponent == 2) {
          emitLength3 = 0;
          if (s_r_001a48fc[0] != '\0') {
            srcCursor = "r";
            curChar = s_r_001a48fc[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        else {
          if (texgenComponent != 3) goto switchD_000118c8_caseD_0;
          emitLength3 = 0;
          if (s_q_001a4900[0] != '\0') {
            srcCursor = "q";
            curChar = s_q_001a4900[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        break;
      case 8:
        emitLength3 = 0;
        if (s_texgen__001a48e4[0] != '\0') {
          srcCursor = "texgen[";
          curChar = s_texgen__001a48e4[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3;
        emitLength7 = ((int (*)())textPrintSignedDecimal)(outCursor,*paramEntry & 0x1f);
        emitLength2 = 0;
        if (s___object__001a4904[0] != '\0') {
          srcCursor = "].object.";
          curChar = s___object__001a4904[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength2 + emitLength7] = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength2 + emitLength7;
        texgenComponent = *paramEntry >> 5 & 7;
        if (texgenComponent == 1) {
          emitLength3 = 0;
          if (s_t_001a48f8[0] != '\0') {
            srcCursor = "t";
            curChar = s_t_001a48f8[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        else if (texgenComponent < 2) {
          if (texgenComponent != 0) goto switchD_000118c8_caseD_0;
          emitLength3 = 0;
          if (s_s_001a48f4[0] != '\0') {
            srcCursor = "s";
            curChar = s_s_001a48f4[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        else if (texgenComponent == 2) {
          emitLength3 = 0;
          if (s_r_001a48fc[0] != '\0') {
            srcCursor = "r";
            curChar = s_r_001a48fc[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        else {
          if (texgenComponent != 3) goto switchD_000118c8_caseD_0;
          emitLength3 = 0;
          if (s_q_001a4900[0] != '\0') {
            srcCursor = "q";
            curChar = s_q_001a4900[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        break;
      case 9:
        emitLength3 = 0;
        if (s_texenv__001a4910[0] != '\0') {
          srcCursor = "texenv[";
          curChar = s_texenv__001a4910[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3;
        emitLength2 = ((int (*)())textPrintSignedDecimal)(outCursor,*paramEntry & 0x1f);
        emitLength3 = 0;
        outCursor = outCursor + emitLength2;
        if (s___color_001a4918[0] != '\0') {
          srcCursor = "].color";
          curChar = s___color_001a4918[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 10:
        emitLength3 = 0;
        if (s_clip__001a4920[0] != '\0') {
          srcCursor = "clip[";
          curChar = s_clip__001a4920[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3;
        emitLength2 = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)(byte)*paramEntry);
        emitLength3 = 0;
        outCursor = outCursor + emitLength2;
        if (s___plane_001a4928[0] != '\0') {
          srcCursor = "].plane";
          curChar = s___plane_001a4928[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 0xb:
        emitLength3 = 0;
        if (s_fog_color_001a4930[0] != '\0') {
          srcCursor = "fog.color";
          curChar = s_fog_color_001a4930[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 0xc:
        emitLength3 = 0;
        if (s_fog_params_001a493c[0] != '\0') {
          srcCursor = "fog.params";
          curChar = s_fog_params_001a493c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 0xd:
        emitLength3 = 0;
        if (s_point_size_001a4954[0] != '\0') {
          srcCursor = "point.size";
          curChar = s_point_size_001a4954[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 0xe:
        emitLength3 = 0;
        if (s_point_attenuation_001a4960[0] != '\0') {
          srcCursor = "point.attenuation";
          curChar = s_point_attenuation_001a4960[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 0xf:
        emitLength3 = 0;
        if (s_depth_range_001a4948[0] != '\0') {
          srcCursor = "depth.range";
          curChar = s_depth_range_001a4948[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 0x10:
        emitLength3 = 0;
        if (s_matrix__001a4974[0] != '\0') {
          srcCursor = "matrix.";
          curChar = s_matrix__001a4974[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        paramWord = *paramEntry;
        outCursor = outCursor + emitLength3;
        switch(paramWord >> 8 & 7) {
        case 0:
          emitLength2 = 0;
          if (s_mvp__001a4988[0] != '\0') {
            srcCursor = "mvp.";
            curChar = s_mvp__001a4988[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength2] = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
LAB_00012bfc:
            paramWord = *paramEntry;
          }
          goto LAB_00012e2c;
        case 1:
          emitLength2 = 0;
          if (s_projection__001a497c[0] != '\0') {
            srcCursor = "projection.";
            curChar = s_projection__001a497c[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength2] = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
            goto LAB_00012bfc;
          }
          goto LAB_00012e2c;
        case 2:
          emitLength3 = 0;
          if (s_color__001a4990[0] != '\0') {
            srcCursor = "color[";
            curChar = s_color__001a4990[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength3;
          emitLength3 = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)(byte)*paramEntry);
          emitLength2 = 0;
          outCursor = outCursor + emitLength3;
          if (s____001a4878[0] != '\0') {
            srcCursor = "].";
            curChar = s____001a4878[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength2] = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          goto LAB_00012d68;
        case 3:
          emitLength3 = 0;
          if (s_modelview__001a4998[0] != '\0') {
            srcCursor = "modelview[";
            curChar = s_modelview__001a4998[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength3;
          emitLength3 = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)(byte)*paramEntry);
          emitLength2 = 0;
          outCursor = outCursor + emitLength3;
          if (s____001a4878[0] != '\0') {
            srcCursor = "].";
            curChar = s____001a4878[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength2] = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
LAB_00012d68:
          paramWord = *paramEntry;
          outCursor = outCursor + emitLength2;
          break;
        case 4:
          emitLength3 = 0;
          if (s_texture__001a4514[0] != '\0') {
            srcCursor = "texture[";
            curChar = s_texture__001a4514[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength3;
          emitLength3 = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)(byte)*paramEntry);
          emitLength2 = 0;
          outCursor = outCursor + emitLength3;
          if (s____001a4878[0] != '\0') {
            srcCursor = "].";
            curChar = s____001a4878[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength2] = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          paramWord = *paramEntry;
LAB_00012e2c:
          outCursor = outCursor + emitLength2;
          break;
        case 5:
          emitLength3 = 0;
          if (s_program__001a49a4[0] != '\0') {
            srcCursor = "program[";
            curChar = s_program__001a49a4[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength3;
          emitLength7 = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)(byte)*paramEntry);
          emitLength2 = 0;
          if (s____001a4878[0] != '\0') {
            srcCursor = "].";
            curChar = s____001a4878[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength2 + emitLength7] = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength2 + emitLength7;
          paramWord = *paramEntry;
        }
        matrixModifier = paramWord >> 0xe & 3;
        if (matrixModifier == 2) {
          emitLength3 = 0;
          if (s_inverse__001a49bc[0] != '\0') {
            srcCursor = "inverse.";
            curChar = s_inverse__001a49bc[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
LAB_00012ff0:
          outCursor = outCursor + emitLength3;
        }
        else {
          if (matrixModifier == 3) {
            emitLength3 = 0;
            if (s_invtrans__001a49c8[0] != '\0') {
              srcCursor = "invtrans.";
              curChar = s_invtrans__001a49c8[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength3] = curChar;
                emitLength3 = emitLength3 + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            goto LAB_00012ff0;
          }
          if (matrixModifier == 1) {
            emitLength3 = 0;
            if (s_transpose__001a49b0[0] != '\0') {
              srcCursor = "transpose.";
              curChar = s_transpose__001a49b0[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[emitLength3] = curChar;
                emitLength3 = emitLength3 + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
            goto LAB_00012ff0;
          }
        }
        emitLength3 = 0;
        if (s_row__001a49d4[0] != '\0') {
          srcCursor = "row[";
          curChar = s_row__001a49d4[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3;
        emitLength2 = ((int (*)())textPrintSignedDecimal)(outCursor,*paramEntry >> 0xc & 3);
        emitLength3 = 0;
        outCursor = outCursor + emitLength2;
        if (s___001a4468[0] != '\0') {
          srcCursor = "]";
          curChar = s___001a4468[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 0x11:
        goto switchD_000118c8_caseD_11;
      case 0x12:
        emitLength3 = 0;
        if (s_normalscale_001a4a18[0] != '\0') {
          srcCursor = "normalscale";
          curChar = s_normalscale_001a4a18[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
      }
LAB_000135c0:
      outCursor = outCursor + emitLength3;
switchD_000118c8_caseD_0:
      if (paramGroupState[*(ushort *)((int)paramEntry + 6)] == 0xffffffff) {
        emitLength3 = 0;
        if (s___001a46fc[0] != '\0') {
          srcCursor = ";\n";
          curChar = s___001a46fc[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
      }
      else if (groupElementIndex + 1U == paramArrayLengths[paramArrayIndex]) {
        paramArrayIndex = paramArrayIndex + 1;
        emitLength3 = 0;
        if (s____001a4a24[0] != '\0') {
          srcCursor = "\n};\n";
          curChar = s____001a4a24[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
      }
      else {
        emitLength3 = 0;
        if (s___001a4a2c[0] != '\0') {
          srcCursor = ",\n";
          curChar = s___001a4a2c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
      }
      outCursor = outCursor + emitLength3;
      printResult = ((int (*)())textBufferEnsureRoom)(outCapacity,&outBuffer,&outCursor);
      if ((int)(printResult >> 0x20) == 0) goto LAB_00014048;
LAB_000136f0:
      paramLoopCursor = (uint *)((int)paramLoopCursor + 1);
      paramEntry = paramEntry + 2;
    } while (paramCount != paramLoopCursor);
  }
  if (paramArrayLengths != (uint *)0x0) {
    _free(paramArrayLengths);
  }
  emitLength = 0;
  if (s__001a45c0[0] != '\0') {
    srcCursor = "\n";
    emitLength = 0;
    curChar = s__001a45c0[0];
    do {
      srcCursor = srcCursor + 1;
      outCursor[emitLength] = curChar;
      emitLength = emitLength + 1;
      curChar = *srcCursor;
    } while (curChar != '\0');
  }
  outCursor = outCursor + emitLength;
LAB_0001376c:
  outputCount = program[0xc];
  outputEntry = program + program[0xd] * 2;
  if (0 < (int)outputCount) {
    loopCounter = 0;
    do {
      entryWord = *outputEntry >> 0x10 & 0xf;
      if (entryWord == 0) goto LAB_000140a0;
      outputPrecision = *outputEntry >> 0x1d;
      if (outputPrecision == 1) {
        emitLength = 0;
        if (s_LONG_OUTPUT_res_001a4a3c[0] != '\0') {
          srcCursor = "LONG OUTPUT res";
          curChar = s_LONG_OUTPUT_res_001a4a3c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
LAB_0001389c:
        outCursor = outCursor + emitLength;
      }
      else {
        if (outputPrecision == 2) {
          emitLength = 0;
          if (s_SHORT_OUTPUT_res_001a4a4c[0] != '\0') {
            srcCursor = "SHORT OUTPUT res";
            curChar = s_SHORT_OUTPUT_res_001a4a4c[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          goto LAB_0001389c;
        }
        if (outputPrecision == 0) {
          emitLength = 0;
          if (s_OUTPUT_res_001a4a30[0] != '\0') {
            srcCursor = "OUTPUT res";
            curChar = s_OUTPUT_res_001a4a30[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          goto LAB_0001389c;
        }
      }
      emitLength = ((int (*)())textPrintSignedDecimal)(outCursor,(uint)*(ushort *)((int)outputEntry + 6));
      outCursor = outCursor + emitLength;
      if (!isAssemblyProgram) {
        declWord = *outputEntry;
        argReg7 = declWord >> 0x1d;
        argReg6 = (uint *)(declWord >> 0x1a & 7);
        outCursor = (undefined1 *)((int (*)())arbIrPrintDeclSizeSuffix)(outCursor,declWord >> 0x18 & 3,0,argReg6,argReg7);
      }
      emitLength = 0;
      if (s___001a4834[0] != '\0') {
        srcCursor = " = ";
        curChar = s___001a4834[0];
        do {
          srcCursor = srcCursor + 1;
          outCursor[emitLength] = curChar;
          emitLength = emitLength + 1;
          curChar = *srcCursor;
        } while (curChar != '\0');
      }
      outCursor = outCursor + emitLength;
      switch(entryWord) {
      default:
        goto switchD_00013960_caseD_0;
      case 1:
        groupElementIndex = 0;
        if (s_result_position_001a4a60[0] != '\0') {
          srcCursor = "result.position";
          curChar = s_result_position_001a4a60[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[groupElementIndex] = curChar;
            groupElementIndex = groupElementIndex + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 2:
        groupElementIndex = 0;
        if (s_result_fogcoord_001a4a70[0] != '\0') {
          srcCursor = "result.fogcoord";
          curChar = s_result_fogcoord_001a4a70[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[groupElementIndex] = curChar;
            groupElementIndex = groupElementIndex + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 3:
        groupElementIndex = 0;
        if (s_result_pointsize_001a4a80[0] != '\0') {
          srcCursor = "result.pointsize";
          curChar = s_result_pointsize_001a4a80[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[groupElementIndex] = curChar;
            groupElementIndex = groupElementIndex + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 4:
        emitLength = 0;
        if (s_result_color_001a4a94[0] != '\0') {
          srcCursor = "result.color";
          curChar = s_result_color_001a4a94[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength;
        if ((programTarget == 0x8620) || (programTarget == 0x8b31)) {
          if ((*outputEntry & 1) == 0) {
            groupElementIndex = 0;
            if (s__front_primary_001a4aa4[0] != '\0') {
              srcCursor = ".front.primary";
              curChar = s__front_primary_001a4aa4[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[groupElementIndex] = curChar;
                groupElementIndex = groupElementIndex + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
          }
          else {
            if ((*outputEntry & 1) != 1) goto switchD_00013960_caseD_0;
            groupElementIndex = 0;
            if (s__back_primary_001a4ab4[0] != '\0') {
              srcCursor = ".back.primary";
              curChar = s__back_primary_001a4ab4[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[groupElementIndex] = curChar;
                groupElementIndex = groupElementIndex + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
          }
        }
        else {
          if (((programTarget != 0x8804) && (programTarget != 0x8b30)) || (entryWord = *outputEntry, (entryWord >> 1 & 7) < 2)
             ) goto switchD_00013960_caseD_0;
          emitLength = 0;
          if (s___001a4464[0] != '\0') {
            srcCursor = "[";
            curChar = s___001a4464[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength] = curChar;
              emitLength = emitLength + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
            entryWord = *outputEntry;
          }
          outCursor = outCursor + emitLength;
          emitLength = ((int (*)())textPrintSignedDecimal)(outCursor,entryWord >> 1 & 7);
          groupElementIndex = 0;
          outCursor = outCursor + emitLength;
          if (s___001a4468[0] != '\0') {
            srcCursor = "]";
            curChar = s___001a4468[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[groupElementIndex] = curChar;
              groupElementIndex = groupElementIndex + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
        }
        break;
      case 5:
        emitLength = 0;
        if (s_result_color_001a4a94[0] != '\0') {
          srcCursor = "result.color";
          curChar = s_result_color_001a4a94[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength;
        if ((programTarget == 0x8620) || (programTarget == 0x8b31)) {
          if ((*outputEntry & 1) == 0) {
            groupElementIndex = 0;
            if (s__front_secondary_001a4ac4[0] != '\0') {
              srcCursor = ".front.secondary";
              curChar = s__front_secondary_001a4ac4[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[groupElementIndex] = curChar;
                groupElementIndex = groupElementIndex + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
          }
          else {
            if ((*outputEntry & 1) != 1) goto switchD_00013960_caseD_0;
            groupElementIndex = 0;
            if (s__back_secondary_001a4ad8[0] != '\0') {
              srcCursor = ".back.secondary";
              curChar = s__back_secondary_001a4ad8[0];
              do {
                srcCursor = srcCursor + 1;
                outCursor[groupElementIndex] = curChar;
                groupElementIndex = groupElementIndex + 1;
                curChar = *srcCursor;
              } while (curChar != '\0');
            }
          }
          break;
        }
        goto switchD_00013960_caseD_0;
      case 6:
        emitLength = 0;
        if (s_result_texcoord__001a4ae8[0] != '\0') {
          srcCursor = "result.texcoord[";
          curChar = s_result_texcoord__001a4ae8[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength;
        emitLength = ((int (*)())textPrintSignedDecimal)(outCursor,*outputEntry & 0x1f);
        groupElementIndex = 0;
        outCursor = outCursor + emitLength;
        if (s___001a4468[0] != '\0') {
          srcCursor = "]";
          curChar = s___001a4468[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[groupElementIndex] = curChar;
            groupElementIndex = groupElementIndex + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 7:
        groupElementIndex = 0;
        if (s_result_depth_001a4afc[0] != '\0') {
          srcCursor = "result.depth";
          curChar = s_result_depth_001a4afc[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[groupElementIndex] = curChar;
            groupElementIndex = groupElementIndex + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 8:
        groupElementIndex = 0;
        if (s_result_eyePosition_001a4b1c[0] != '\0') {
          srcCursor = "result.eyePosition";
          curChar = s_result_eyePosition_001a4b1c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[groupElementIndex] = curChar;
            groupElementIndex = groupElementIndex + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 9:
        groupElementIndex = 0;
        if (s_result_clipVertex_001a4b30[0] != '\0') {
          srcCursor = "result.clipVertex";
          curChar = s_result_clipVertex_001a4b30[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[groupElementIndex] = curChar;
            groupElementIndex = groupElementIndex + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        break;
      case 10:
        emitLength = 0;
        if (s_result_attrib__001a4b0c[0] != '\0') {
          srcCursor = "result.attrib[";
          curChar = s_result_attrib__001a4b0c[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength] = curChar;
            emitLength = emitLength + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength;
        emitLength = ((int (*)())textPrintSignedDecimal)(outCursor,*outputEntry & 0x1f);
        groupElementIndex = 0;
        outCursor = outCursor + emitLength;
        if (s___001a4468[0] != '\0') {
          srcCursor = "]";
          curChar = s___001a4468[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[groupElementIndex] = curChar;
            groupElementIndex = groupElementIndex + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
      }
      outCursor = outCursor + groupElementIndex;
switchD_00013960_caseD_0:
      emitLength = 0;
      if (s___001a46fc[0] != '\0') {
        srcCursor = ";\n";
        curChar = s___001a46fc[0];
        do {
          srcCursor = srcCursor + 1;
          outCursor[emitLength] = curChar;
          emitLength = emitLength + 1;
          curChar = *srcCursor;
        } while (curChar != '\0');
      }
      outCursor = outCursor + emitLength;
      bufferOk = ((int (*)())textBufferEnsureRoom)(outCapacity,&outBuffer,&outCursor);
      if (bufferOk == 0) goto LAB_00014048;
LAB_000140a0:
      loopCounter = loopCounter + 1;
      outputEntry = outputEntry + 2;
    } while (outputCount != loopCounter);
  }
  if ((outputCount != 0) || (isAssemblyProgram)) {
    emitLength = 0;
    if (s__001a45c0[0] != '\0') {
      srcCursor = "\n";
      emitLength = 0;
      curChar = s__001a45c0[0];
      do {
        srcCursor = srcCursor + 1;
        outCursor[emitLength] = curChar;
        emitLength = emitLength + 1;
        curChar = *srcCursor;
      } while (curChar != '\0');
    }
    outCursor = outCursor + emitLength;
  }
  instructionCount = program[0x14];
  instructionOffset = program[0x15];
  if (0 < (int)instructionCount) {
    scanEntryIndex = 0;
    branchTargetCount = 0;
    entriesRemaining = instructionCount;
    do {
      if ((program[instructionOffset * 2 + scanEntryIndex * 2] >> 0x12 & 0xff) - 0x4b < 2) {
        branchTargetCount = branchTargetCount + 1;
      }
      scanEntryIndex = scanEntryIndex + (program[instructionOffset * 2 + scanEntryIndex * 2] >> 0x1d) + 2;
      entriesRemaining = entriesRemaining - 1;
    } while (entriesRemaining != 0);
    if (branchTargetCount == 0) {
      branchTargets = (int *)0x0;
      branchSources = (uint *)0x0;
      labelCountNext = (uint *)0x0;
      noLabels = true;
    }
    else {
      branchTargets = (int *)_malloc(branchTargetCount << 2);
      _memset(branchTargets,0,branchTargetCount);
      branchSources = (uint *)_malloc(branchTargetCount << 2);
      moreLabels = false;
      noLabels = true;
      _memset(branchSources,0,branchTargetCount);
      loopCounter = 0;
      scanEntryIndex = 0;
      labelCount = (uint *)0x0;
      do {
        labelCountNext = labelCount;
        if ((program[instructionOffset * 2 + scanEntryIndex * 2] >> 0x12 & 0xff) - 0x4b < 2) {
          entryWord = program[instructionOffset * 2 + scanEntryIndex * 2] & 0x3ffff;
          branchTarget = (uint *)((program + instructionOffset * 2 + scanEntryIndex * 2)[1] & 0x3ffff);
          if (moreLabels) {
            if (*branchTargets < (int)branchTarget) {
              argReg8 = (uint *)0x0;
              branchTargetCursor = branchTargets;
              labelsRemaining = labelCount;
              do {
                argReg8 = (uint *)((int)argReg8 + 1);
                labelsRemaining = (uint *)((int)labelsRemaining + -1);
                if (labelsRemaining == (uint *)0x0) goto LAB_00014230;
                branchTargetCursor = branchTargetCursor + 1;
              } while (*branchTargetCursor < (int)branchTarget);
            }
            else {
              argReg8 = (uint *)0x0;
            }
          }
          else {
            if (noLabels) {
LAB_00014230:
              labelCountNext = (uint *)((int)labelCount + 1);
              moreLabels = 0 < (int)labelCountNext;
              noLabels = labelCountNext == (uint *)0x0;
              branchTargets[(int)labelCount] = (int)branchTarget;
              branchSources[(int)labelCount] = entryWord;
              goto LAB_00014300;
            }
            argReg8 = (uint *)0x0;
          }
          argReg10 = (char *)branchTargets[(int)argReg8];
          if (branchTarget != (uint *)argReg10) {
            branchTargets[(int)argReg8] = (int)branchTarget;
            labelCountNext = (uint *)((int)labelCount + 1);
            argReg6 = (uint *)((int)argReg8 + 1);
            swapSource = branchSources[(int)argReg8];
            branchSources[(int)argReg8] = entryWord;
            if ((int)argReg6 < (int)labelCount) {
              labelsToShift = (int)labelCount - (int)argReg6;
              labelCount = (uint *)0x0;
              labelSourceCursor = branchSources + (int)argReg6;
              labelInsertCursor = (uint *)(branchTargets + (int)argReg6);
              swapTemp = (uint *)argReg10;
              do {
                argReg7 = swapSource;
                argReg10 = (char *)*labelInsertCursor;
                *labelInsertCursor = (uint)swapTemp;
                labelCount = (uint *)((int)labelCount + 1);
                labelInsertCursor = labelInsertCursor + 1;
                swapSource = *labelSourceCursor;
                *labelSourceCursor = argReg7;
                labelSourceCursor = labelSourceCursor + 1;
                labelsToShift = labelsToShift + -1;
                swapTemp = (uint *)argReg10;
              } while (labelsToShift != 0);
              argReg6 = (uint *)((int)argReg6 + (int)labelCount);
            }
            moreLabels = 0 < (int)labelCountNext;
            noLabels = labelCountNext == (uint *)0x0;
            branchTargets[(int)argReg6] = (int)argReg10;
            branchSources[(int)argReg6] = swapSource;
            argReg8 = labelCount;
          }
        }
LAB_00014300:
        loopCounter = loopCounter + 1;
        scanEntryIndex = scanEntryIndex + (program[instructionOffset * 2 + scanEntryIndex * 2] >> 0x1d) + 2;
        labelCount = labelCountNext;
      } while (instructionCount != loopCounter);
    }
    outCapacityPtr = outCapacity;
    outCursorPtr = &outCursor;
    newlineBase = 0x19f634;
    entryIndex = (undefined1 *)0x0;
    mnemonicTableBase = s_MUL_V_001df634;
    semicolonBase = 0x19f634;
    labelIndex = 0;
    loopCounter = 0;
    nestingDepth = 1;
    do {
      instructionRecord = program + instructionOffset * 2 + (int)entryIndex * 2;
      if (((program[instructionOffset * 2 + (int)entryIndex * 2] & 0x3ffff) == 0) && (!isAssemblyProgram)) {
        emitLength3 = 0;
        if (s_main__001a4b44[0] != '\0') {
          srcCursor = "main:\n";
          emitLength3 = 0;
          curChar = s_main__001a4b44[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength3;
      }
      if ((noLabels) || ((int)labelCountNext <= labelIndex)) {
        entryWord = *instructionRecord;
      }
      else {
        entryWord = *instructionRecord;
        if ((entryWord & 0x3ffff) == branchTargets[labelIndex]) {
          if (0 < nestingDepth + -1) {
            argReg8 = (uint *)0x19f634;
            indentIndex = 0;
            argReg10 = "  ";
            do {
              emitLength2 = 0;
              if (s__001a4b4c[0] != '\0') {
                srcCursor = "  ";
                emitLength2 = 0;
                curChar = s__001a4b4c[0];
                do {
                  srcCursor = srcCursor + 1;
                  outCursor[emitLength2] = curChar;
                  emitLength2 = emitLength2 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
              }
              indentIndex = indentIndex + 1;
              outCursor = outCursor + emitLength2;
            } while (nestingDepth + -1 != indentIndex);
          }
          emitLength3 = 0;
          if (s_label__001a4b50[0] != '\0') {
            srcCursor = "label_";
            curChar = s_label__001a4b50[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          outCursor = outCursor + emitLength3;
          emitLength7 = ((int (*)())textPrintSignedDecimal)(outCursor,labelIndex);
          labelIndex = labelIndex + 1;
          emitLength2 = 0;
          if (s___001a4b58[0] != '\0') {
            srcCursor = ":\n";
            curChar = s___001a4b58[0];
            do {
              srcCursor = srcCursor + 1;
              outCursor[emitLength2 + emitLength7] = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          entryWord = *instructionRecord;
          outCursor = outCursor + emitLength2 + emitLength7;
        }
      }
      lineStart = outCursor;
      opcodeBits = entryWord & 0x3fc0000;
      if ((((opcodeBits == 0x1ac0000) || (opcodeBits == 0x1600000)) || (opcodeBits == 0x1640000)) ||
         ((opcodeBits == 0x1680000 || (opcodeBits == 0x16c0000)))) {
        nestingDepth = nestingDepth + -1;
      }
      branchWord = instructionRecord[1];
      opcode = entryWord >> 0x12 & 0xff;
      lineCursor = outCursor;
      if (0 < nestingDepth) {
        argReg8 = (uint *)0x19f634;
        indentIndex = 0;
        argReg10 = "  ";
        do {
          emitLength2 = 0;
          if (s__001a4b4c[0] != '\0') {
            srcCursor = "  ";
            curChar = s__001a4b4c[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength2] = curChar;
              emitLength2 = emitLength2 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          indentIndex = indentIndex + 1;
          lineCursor = lineCursor + emitLength2;
        } while (indentIndex != nestingDepth);
      }
      emitLength3 = 0;
      srcCursor = *(char **)(mnemonicTableBase + opcode * 4 + -0x6630);
      curChar = *srcCursor;
      if (curChar != '\0') {
        emitLength3 = 0;
        do {
          lineCursor[emitLength3] = curChar;
          emitLength3 = emitLength3 + 1;
          curChar = srcCursor[emitLength3];
        } while (curChar != '\0');
      }
      lineCursor = lineCursor + emitLength3;
      operandEntriesUsed = (dword *)0x0;
      switch(opcode) {
      case 0:
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xc:
      case 0xd:
      case 0xe:
      case 0xf:
      case 0x10:
      case 0x11:
      case 0x12:
      case 0x13:
      case 0x14:
      case 0x15:
      case 0x16:
      case 0x17:
      case 0x18:
      case 0x19:
      case 0x1a:
      case 0x1b:
      case 0x1c:
      case 0x1d:
      case 0x1e:
      case 0x50:
      case 0x51:
      case 0x5c:
      case 0x5d:
      case 0x5e:
      case 0x5f:
      case 99:
      case 100:
      case 0x65:
      case 0x66:
      case 0x6c:
      case 0x6f:
      case 0x70:
        cursorAfterPrecision = ((int (*)())arbIrPrintPrecisionSuffix)(lineCursor,instructionRecord[1] >> 0x12 & 3);
        modifierWord = instructionRecord[1];
        emitLength3 = ((int (*)())arbIrPrintCcAndSaturateSuffix)(cursorAfterPrecision,modifierWord >> 0x16 & 1,modifierWord >> 0x15 & 1,modifierWord >> 0x14 & 1);
        if (!isAssemblyProgram) {
          modifierWord = instructionRecord[1];
          emitLength3 = ((int (*)())arbIrPrintSizeTypeSuffix)(emitLength3,modifierWord >> 0x1a & 3,modifierWord >> 0x1c & 1,modifierWord >> 0x17 & 7);
        }
        emitLength2 = 0;
        if (s__001a4b5c[0] != '\0') {
          srcCursor = " ";
          curChar = s__001a4b5c[0];
          do {
            srcCursor = srcCursor + 1;
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        commaSeparatorBase = 0x19f634;
        emitLength3 = ((int (*)())arbIrPrintDestinationOperand)(instructionRecord,emitLength3 + emitLength2,tmpRegisterNumbers,tmpGroupState,1,isShaderObject);
        curChar = ((unsigned char *)0x00004ec0)[commaSeparatorBase];
        if (curChar != '\0') {
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          emitLength2 = 0;
          nextChar = curChar;
          do {
            *(char *)(emitLength3 + emitLength2) = nextChar;
            emitLength2 = emitLength2 + 1;
            nextChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (nextChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        operandEntriesUsed = (dword *)((int)((unsigned char *)0x0) + 2);
        argReg6 = paramGroupState;
        argReg7 = tmpRegisterNumbers;
        argReg8 = tmpGroupState;
        argReg10 = (char *)isShaderObject;
        lineCursor = (undefined1 *)
                  ((int (*)())arbIrPrintSourceOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,2,isShaderObject,0);
        if (entryWord >> 0x1d == 2) {
          if (curChar != '\0') {
            emitLength3 = 0;
            srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
            do {
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
              srcCursor = srcCursor + 1;
            } while (curChar != '\0');
          }
          else {
            emitLength3 = 0;
          }
          lineCursor = lineCursor + emitLength3;
          goto LAB_000154ec;
        }
        break;
      case 0x1f:
      case 0x20:
      case 0x21:
      case 0x22:
      case 0x23:
      case 0x24:
      case 0x25:
      case 0x26:
      case 0x27:
      case 0x28:
      case 0x29:
      case 0x2a:
      case 0x2b:
      case 0x2c:
      case 0x2d:
      case 0x2e:
      case 0x2f:
      case 0x30:
      case 0x31:
      case 0x32:
      case 0x33:
      case 0x34:
      case 0x35:
      case 0x36:
      case 0x37:
      case 0x38:
      case 0x39:
      case 0x3a:
      case 0x4e:
      case 0x52:
      case 0x6d:
        cursorAfterPrecision = ((int (*)())arbIrPrintPrecisionSuffix)(lineCursor,instructionRecord[1] >> 0x12 & 3);
        entryWord = instructionRecord[1];
        emitLength3 = ((int (*)())arbIrPrintCcAndSaturateSuffix)(cursorAfterPrecision,entryWord >> 0x16 & 1,entryWord >> 0x15 & 1,entryWord >> 0x14 & 1);
        if (!isAssemblyProgram) {
          entryWord = instructionRecord[1];
          emitLength3 = ((int (*)())arbIrPrintSizeTypeSuffix)(emitLength3,entryWord >> 0x1a & 3,entryWord >> 0x1c & 1,entryWord >> 0x17 & 7);
        }
        emitLength2 = 0;
        if (s__001a4b5c[0] != '\0') {
          srcCursor = " ";
          curChar = s__001a4b5c[0];
          do {
            srcCursor = srcCursor + 1;
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        commaSeparatorBase = 0x19f634;
        emitLength3 = ((int (*)())arbIrPrintDestinationOperand)(instructionRecord,emitLength3 + emitLength2,tmpRegisterNumbers,tmpGroupState,1,isShaderObject);
        curChar = ((unsigned char *)0x00004ec0)[commaSeparatorBase];
        if (curChar != '\0') {
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          emitLength2 = 0;
          nextChar = curChar;
          do {
            *(char *)(emitLength3 + emitLength2) = nextChar;
            emitLength2 = emitLength2 + 1;
            nextChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (nextChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        emitLength3 = ((int (*)())arbIrPrintSourceOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,2,isShaderObject,0);
        if (curChar != '\0') {
          emitLength2 = 0;
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          do {
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (curChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        lineCursor = (undefined1 *)(emitLength3 + emitLength2);
LAB_000154ec:
        operandEntriesUsed = (dword *)((int)((unsigned char *)0x0) + 3);
        argReg6 = paramGroupState;
        argReg7 = tmpRegisterNumbers;
        argReg8 = tmpGroupState;
        argReg10 = (char *)isShaderObject;
        lineCursor = (undefined1 *)
                  ((int (*)())arbIrPrintSourceOperand)(instructionRecord,lineCursor,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,3,isShaderObject,0);
        break;
      case 0x3b:
      case 0x3c:
      case 0x3d:
      case 0x3e:
      case 0x3f:
      case 0x40:
      case 0x53:
      case 0x67:
      case 0x68:
        cursorAfterPrecision = ((int (*)())arbIrPrintPrecisionSuffix)(lineCursor,instructionRecord[1] >> 0x12 & 3);
        entryWord = instructionRecord[1];
        emitLength3 = ((int (*)())arbIrPrintCcAndSaturateSuffix)(cursorAfterPrecision,entryWord >> 0x16 & 1,entryWord >> 0x15 & 1,entryWord >> 0x14 & 1);
        if (!isAssemblyProgram) {
          entryWord = instructionRecord[1];
          emitLength3 = ((int (*)())arbIrPrintSizeTypeSuffix)(emitLength3,entryWord >> 0x1a & 3,entryWord >> 0x1c & 1,entryWord >> 0x17 & 7);
        }
        emitLength2 = 0;
        if (s__001a4b5c[0] != '\0') {
          srcCursor = " ";
          curChar = s__001a4b5c[0];
          do {
            srcCursor = srcCursor + 1;
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        commaSeparatorBase = 0x19f634;
        emitLength3 = ((int (*)())arbIrPrintDestinationOperand)(instructionRecord,emitLength3 + emitLength2,tmpRegisterNumbers,tmpGroupState,1,isShaderObject);
        curChar = ((unsigned char *)0x00004ec0)[commaSeparatorBase];
        separatorNotEmpty = curChar != '\0';
        if (separatorNotEmpty) {
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          emitLength2 = 0;
          nextChar = curChar;
          do {
            *(char *)(emitLength3 + emitLength2) = nextChar;
            emitLength2 = emitLength2 + 1;
            nextChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (nextChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        emitLength3 = ((int (*)())arbIrPrintSourceOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,2,isShaderObject,0);
        if (separatorNotEmpty) {
          emitLength2 = 0;
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          nextChar = curChar;
          do {
            *(char *)(emitLength3 + emitLength2) = nextChar;
            emitLength2 = emitLength2 + 1;
            nextChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (nextChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        emitLength3 = ((int (*)())arbIrPrintSourceOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,3,isShaderObject,0);
        if (separatorNotEmpty) {
          emitLength2 = 0;
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          do {
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (curChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        operandEntriesUsed = ((unsigned char *)0x4);
        argReg6 = paramGroupState;
        argReg7 = tmpRegisterNumbers;
        argReg8 = tmpGroupState;
        argReg10 = (char *)isShaderObject;
        lineCursor = (undefined1 *)
                  ((int (*)())arbIrPrintSourceOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,4,isShaderObject,0);
        break;
      case 0x41:
        entryWord = instructionRecord[1];
        emitLength3 = ((int (*)())arbIrPrintCcAndSaturateSuffix)(lineCursor,entryWord >> 0x16 & 1,entryWord >> 0x15 & 1,entryWord >> 0x14 & 1);
        if (!isAssemblyProgram) {
          entryWord = instructionRecord[1];
          emitLength3 = ((int (*)())arbIrPrintSizeTypeSuffix)(emitLength3,entryWord >> 0x1a & 3,entryWord >> 0x1c & 1,entryWord >> 0x17 & 7);
        }
        emitLength2 = 0;
        if (s__001a4b5c[0] != '\0') {
          srcCursor = " ";
          curChar = s__001a4b5c[0];
          do {
            srcCursor = srcCursor + 1;
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        emitLength3 = ((int (*)())arbIrPrintDestinationOperand)(instructionRecord,emitLength3 + emitLength2,tmpRegisterNumbers,tmpGroupState,1,isShaderObject);
        emitLength2 = 0;
        if (s___001a44f4[0] != '\0') {
          srcCursor = ", ";
          curChar = s___001a44f4[0];
          do {
            srcCursor = srcCursor + 1;
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        operandEntriesUsed = (dword *)((int)((unsigned char *)0x0) + 3);
        argReg6 = paramGroupState;
        argReg7 = tmpRegisterNumbers;
        argReg8 = tmpGroupState;
        argReg10 = (char *)isShaderObject;
        lineCursor = (undefined1 *)
                  ((int (*)())arbIrPrintSourceOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,2,isShaderObject,1);
        break;
      case 0x42:
      case 0x43:
        entryWord = instructionRecord[1];
        emitLength3 = ((int (*)())arbIrPrintCcAndSaturateSuffix)(lineCursor,entryWord >> 0x16 & 1,entryWord >> 0x15 & 1,entryWord >> 0x14 & 1);
        if (!isAssemblyProgram) {
          entryWord = instructionRecord[1];
          emitLength3 = ((int (*)())arbIrPrintSizeTypeSuffix)(emitLength3,entryWord >> 0x1a & 3,entryWord >> 0x1c & 1,entryWord >> 0x17 & 7);
        }
        emitLength2 = 0;
        if (s__001a4b5c[0] != '\0') {
          srcCursor = " ";
          curChar = s__001a4b5c[0];
          do {
            srcCursor = srcCursor + 1;
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        commaSeparatorBase = 0x19f634;
        emitLength3 = ((int (*)())arbIrPrintDestinationOperand)(instructionRecord,emitLength3 + emitLength2,tmpRegisterNumbers,tmpGroupState,1,isShaderObject);
        curChar = ((unsigned char *)0x00004ec0)[commaSeparatorBase];
        if (curChar != '\0') {
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          emitLength2 = 0;
          nextChar = curChar;
          do {
            *(char *)(emitLength3 + emitLength2) = nextChar;
            emitLength2 = emitLength2 + 1;
            nextChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (nextChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        emitLength3 = ((int (*)())arbIrPrintSourceOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,2,isShaderObject,0);
        if (curChar != '\0') {
          emitLength2 = 0;
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          do {
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (curChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        operandEntriesUsed = (dword *)((int)isShaderObject + 3);
        argReg6 = paramGroupState;
        argReg7 = tmpRegisterNumbers;
        argReg8 = tmpGroupState;
        argReg10 = (char *)isShaderObject;
        lineCursor = (undefined1 *)
                  ((int (*)())arbIrPrintTextureOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,3,isShaderObject);
        break;
      case 0x44:
      case 0x45:
      case 0x46:
      case 0x47:
        entryWord = instructionRecord[1];
        emitLength3 = ((int (*)())arbIrPrintCcAndSaturateSuffix)(lineCursor,entryWord >> 0x16 & 1,entryWord >> 0x15 & 1,entryWord >> 0x14 & 1);
        if (!isAssemblyProgram) {
          entryWord = instructionRecord[1];
          emitLength3 = ((int (*)())arbIrPrintSizeTypeSuffix)(emitLength3,entryWord >> 0x1a & 3,entryWord >> 0x1c & 1,entryWord >> 0x17 & 7);
        }
        emitLength2 = 0;
        if (s__001a4b5c[0] != '\0') {
          srcCursor = " ";
          curChar = s__001a4b5c[0];
          do {
            srcCursor = srcCursor + 1;
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        commaSeparatorBase = 0x19f634;
        emitLength3 = ((int (*)())arbIrPrintDestinationOperand)(instructionRecord,emitLength3 + emitLength2,tmpRegisterNumbers,tmpGroupState,1,isShaderObject);
        curChar = ((unsigned char *)0x00004ec0)[commaSeparatorBase];
        separatorNotEmpty = curChar != '\0';
        if (separatorNotEmpty) {
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          emitLength2 = 0;
          nextChar = curChar;
          do {
            *(char *)(emitLength3 + emitLength2) = nextChar;
            emitLength2 = emitLength2 + 1;
            nextChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (nextChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        emitLength3 = ((int (*)())arbIrPrintSourceOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,2,isShaderObject,0);
        if (separatorNotEmpty) {
          emitLength2 = 0;
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          nextChar = curChar;
          do {
            *(char *)(emitLength3 + emitLength2) = nextChar;
            emitLength2 = emitLength2 + 1;
            nextChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (nextChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        argReg6 = paramGroupState;
        argReg7 = tmpRegisterNumbers;
        argReg8 = tmpGroupState;
        argReg10 = (char *)isShaderObject;
        lineCursor = (undefined1 *)
                  ((int (*)())arbIrPrintTextureOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,3,isShaderObject);
        if (isAssemblyProgram) {
          operandEntriesUsed = (dword *)((int)((unsigned char *)0x0) + 3);
        }
        else {
          if (separatorNotEmpty) {
            emitLength3 = 0;
            srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
            do {
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
              srcCursor = srcCursor + 1;
            } while (curChar != '\0');
          }
          else {
            emitLength3 = 0;
          }
          operandEntriesUsed = isShaderObject + 1;
          argReg6 = paramGroupState;
          argReg7 = tmpRegisterNumbers;
          argReg8 = tmpGroupState;
          argReg10 = (char *)isShaderObject;
          lineCursor = (undefined1 *)
                    ((int (*)())arbIrPrintSourceOperand)(instructionRecord,lineCursor + emitLength3,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,operandEntriesUsed,
                                 isShaderObject,0);
        }
        break;
      case 0x48:
      case 0x49:
      case 0x4a:
        if (!isAssemblyProgram) {
          entryWord = instructionRecord[1];
          lineCursor = (undefined1 *)
                    ((int (*)())arbIrPrintSizeTypeSuffix)(lineCursor,entryWord >> 0x1a & 3,entryWord >> 0x1c & 1,entryWord >> 0x17 & 7);
        }
        emitLength3 = 0;
        if (s__001a4b5c[0] != '\0') {
          srcCursor = " ";
          emitLength3 = 0;
          curChar = s__001a4b5c[0];
          do {
            srcCursor = srcCursor + 1;
            lineCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        lineCursor = lineCursor + emitLength3;
        firstOperand = instructionRecord + 2;
        if ((instructionRecord[2] & 0xe0000) == 0x80000) {
          emitLength3 = 0;
          if (s_adr_001a44f0[0] != '\0') {
            srcCursor = "adr";
            emitLength3 = 0;
            curChar = s_adr_001a44f0[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          registerNumberLength = ((int (*)())textPrintSignedDecimal)(lineCursor + emitLength3,(uint)*(ushort *)((int)instructionRecord + 0xe));
          lineCursor = lineCursor + emitLength3 + registerNumberLength;
        }
        entryWord = *firstOperand;
        if ((entryWord & 0x1e000) != 0x1e000) {
          emitLength3 = 0;
          if (s___001a448c[0] != '\0') {
            srcCursor = ".";
            curChar = s___001a448c[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
            entryWord = *firstOperand;
          }
          lineCursor = lineCursor + emitLength3;
          if (isAssemblyProgram) {
            if ((entryWord & 0x2000) != 0) {
              emitLength3 = 0;
              if (s_x_001a4490[0] != '\0') {
                srcCursor = "x";
                curChar = s_x_001a4490[0];
                do {
                  srcCursor = srcCursor + 1;
                  lineCursor[emitLength3] = curChar;
                  emitLength3 = emitLength3 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
                entryWord = *firstOperand;
              }
              lineCursor = lineCursor + emitLength3;
            }
            if ((entryWord & 0x4000) != 0) {
              emitLength3 = 0;
              if (s_y_001a4494[0] != '\0') {
                srcCursor = "y";
                curChar = s_y_001a4494[0];
                do {
                  srcCursor = srcCursor + 1;
                  lineCursor[emitLength3] = curChar;
                  emitLength3 = emitLength3 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
                entryWord = *firstOperand;
              }
              lineCursor = lineCursor + emitLength3;
            }
            if ((entryWord & 0x8000) != 0) {
              emitLength3 = 0;
              if (s_z_001a4498[0] != '\0') {
                srcCursor = "z";
                curChar = s_z_001a4498[0];
                do {
                  srcCursor = srcCursor + 1;
                  lineCursor[emitLength3] = curChar;
                  emitLength3 = emitLength3 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
                entryWord = *firstOperand;
              }
              lineCursor = lineCursor + emitLength3;
            }
            if ((entryWord & 0x10000) != 0) {
              emitLength3 = 0;
              if (s_w_001a449c[0] != '\0') {
                srcCursor = "w";
                curChar = s_w_001a449c[0];
                do {
                  srcCursor = srcCursor + 1;
                  lineCursor[emitLength3] = curChar;
                  emitLength3 = emitLength3 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
              }
              goto LAB_00016158;
            }
          }
          else {
            if ((entryWord & 0x2000) != 0) {
              emitLength3 = 0;
              if (s_x_001a4490[0] != '\0') {
                srcCursor = "x";
                curChar = s_x_001a4490[0];
                do {
                  srcCursor = srcCursor + 1;
                  lineCursor[emitLength3] = curChar;
                  emitLength3 = emitLength3 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
                entryWord = *firstOperand;
              }
              lineCursor = lineCursor + emitLength3;
            }
            if (((entryWord & 0xc00) != 0) && ((entryWord & 0x4000) != 0)) {
              emitLength3 = 0;
              if (s_y_001a4494[0] != '\0') {
                srcCursor = "y";
                curChar = s_y_001a4494[0];
                do {
                  srcCursor = srcCursor + 1;
                  lineCursor[emitLength3] = curChar;
                  emitLength3 = emitLength3 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
                entryWord = *firstOperand;
              }
              lineCursor = lineCursor + emitLength3;
            }
            if ((1 < (entryWord >> 10 & 3)) && ((entryWord & 0x8000) != 0)) {
              emitLength3 = 0;
              if (s_z_001a4498[0] != '\0') {
                srcCursor = "z";
                curChar = s_z_001a4498[0];
                do {
                  srcCursor = srcCursor + 1;
                  lineCursor[emitLength3] = curChar;
                  emitLength3 = emitLength3 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
                entryWord = *firstOperand;
              }
              lineCursor = lineCursor + emitLength3;
            }
            if ((2 < (entryWord >> 10 & 3)) && ((entryWord & 0x10000) != 0)) {
              emitLength3 = 0;
              if (s_w_001a449c[0] != '\0') {
                srcCursor = "w";
                curChar = s_w_001a449c[0];
                do {
                  srcCursor = srcCursor + 1;
                  lineCursor[emitLength3] = curChar;
                  emitLength3 = emitLength3 + 1;
                  curChar = *srcCursor;
                } while (curChar != '\0');
              }
LAB_00016158:
              lineCursor = lineCursor + emitLength3;
            }
          }
        }
        emitLength3 = 0;
        if (s___001a44f4[0] != '\0') {
          srcCursor = ", ";
          curChar = s___001a44f4[0];
          do {
            srcCursor = srcCursor + 1;
            lineCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
LAB_000161a0:
        lineCursor = lineCursor + emitLength3;
        goto LAB_00014cb8;
      case 0x4b:
      case 0x4c:
        indentLength = (char *)0x0;
        if (s__001a4b5c[0] != '\0') {
          separatorSrc = " ";
          indentLength = (char *)0x0;
          curChar = s__001a4b5c[0];
          do {
            separatorSrc = separatorSrc + 1;
            lineCursor[(int)indentLength] = curChar;
            indentLength = indentLength + 1;
            curChar = *separatorSrc;
            srcCursor = indentLength;
          } while (curChar != '\0');
        }
        labelSearchIndex = -1;
        if (branchTargets != (int *)0x0) {
          labelSearchIndex = 0;
          srcCursor = (char *)(instructionRecord[1] & 0x3ffff);
          labelTarget = (char *)*branchTargets;
          while (srcCursor != labelTarget) {
            labelSearchIndex = labelSearchIndex + 1;
            labelTarget = (char *)branchTargets[labelSearchIndex];
          }
        }
        emitLength3 = printf_LDBLStub_1a32d0(lineCursor + (int)indentLength,"label_%i",labelSearchIndex,argReg6,argReg7,argReg8,srcCursor,
                              argReg10);
        lineCursor = lineCursor + (int)indentLength + emitLength3;
        if (opcode != 0x4b) goto switchD_000146d8_caseD_4d;
        firstOperand = instructionRecord + 2;
        switch(instructionRecord[2] >> 0x1c & 7) {
        case 0:
          emitLength3 = 0;
          if (s__TR_001a44a0[0] != '\0') {
            srcCursor = " (TR";
            curChar = s__TR_001a44a0[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 1:
          emitLength3 = 0;
          if (s__EQ_001a44a8[0] != '\0') {
            srcCursor = " (EQ";
            curChar = s__EQ_001a44a8[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 2:
          emitLength3 = 0;
          if (s__GE_001a44b0[0] != '\0') {
            srcCursor = " (GE";
            curChar = s__GE_001a44b0[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 3:
          emitLength3 = 0;
          if (s__GT_001a44b8[0] != '\0') {
            srcCursor = " (GT";
            curChar = s__GT_001a44b8[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 4:
          emitLength3 = 0;
          if (s__LE_001a44c0[0] != '\0') {
            srcCursor = " (LE";
            curChar = s__LE_001a44c0[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 5:
          emitLength3 = 0;
          if (s__LT_001a44c8[0] != '\0') {
            srcCursor = " (LT";
            curChar = s__LT_001a44c8[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 6:
          emitLength3 = 0;
          if (s__NE_001a44d0[0] != '\0') {
            srcCursor = " (NE";
            curChar = s__NE_001a44d0[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 7:
          emitLength3 = 0;
          if (s__FL_001a44d8[0] != '\0') {
            srcCursor = " (FL";
            curChar = s__FL_001a44d8[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        default:
          goto switchD_00014df8_default;
        }
        lineCursor = lineCursor + emitLength3;
switchD_00014df8_default:
        if ((int)*firstOperand < 0) {
          *lineCursor = 0x31;
          lineCursor = lineCursor + 1;
        }
        operandEntriesUsed = (dword *)((int)((unsigned char *)0x0) + 1);
        *lineCursor = 0x2e;
        lineCursor[1] = (((byte)(*firstOperand >> 0x1a) & 3) + 1 & 3) + 0x77;
        lineCursor[2] = (*(char *)firstOperand + 1U & 3) + 0x77;
        lineCursor[3] = (((byte)(*firstOperand >> 0x16) & 3) + 1 & 3) + 0x77;
        entryWord = *firstOperand;
        lineCursor[5] = 0x29;
        lineCursor[4] = (((byte)(entryWord >> 0x14) & 3) + 1 & 3) + 0x77;
        lineCursor = lineCursor + 6;
        break;
      case 0x4d:
      case 0x54:
      case 0x59:
      case 0x5a:
      case 0x5b:
      case 0x69:
      case 0x6b:
      case 0x6e:
switchD_000146d8_caseD_4d:
        operandEntriesUsed = (dword *)((int)((unsigned char *)0x0) + 1);
        break;
      case 0x4f:
        emitLength3 = 0;
        if (s__001a4b5c[0] != '\0') {
          srcCursor = " ";
          curChar = s__001a4b5c[0];
          do {
            srcCursor = srcCursor + 1;
            lineCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        goto LAB_00014cb4;
      case 0x55:
        nestingDepth = nestingDepth + 1;
        if (!isAssemblyProgram) {
          entryWord = instructionRecord[1];
          lineCursor = (undefined1 *)
                    ((int (*)())arbIrPrintSizeTypeSuffix)(lineCursor,entryWord >> 0x1a & 3,entryWord >> 0x1c & 1,entryWord >> 0x17 & 7);
          emitLength3 = 0;
          if (s__001a4b5c[0] != '\0') {
            srcCursor = " ";
            curChar = s__001a4b5c[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          goto LAB_000161a0;
        }
        firstOperand = instructionRecord + 2;
        switch(instructionRecord[2] >> 0x1c & 7) {
        case 0:
          emitLength3 = 0;
          if (s_TR_001a4b60[0] != '\0') {
            srcCursor = " TR";
            curChar = s_TR_001a4b60[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 1:
          emitLength3 = 0;
          if (s_EQ_001a4b64[0] != '\0') {
            srcCursor = " EQ";
            curChar = s_EQ_001a4b64[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 2:
          emitLength3 = 0;
          if (s_GE_001a4b68[0] != '\0') {
            srcCursor = " GE";
            curChar = s_GE_001a4b68[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 3:
          emitLength3 = 0;
          if (s_GT_001a4b6c[0] != '\0') {
            srcCursor = " GT";
            curChar = s_GT_001a4b6c[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 4:
          emitLength3 = 0;
          if (s_LE_001a4b70[0] != '\0') {
            srcCursor = " LE";
            curChar = s_LE_001a4b70[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 5:
          emitLength3 = 0;
          if (s_LT_001a4b74[0] != '\0') {
            srcCursor = " LT";
            curChar = s_LT_001a4b74[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 6:
          emitLength3 = 0;
          if (s_NE_001a4b78[0] != '\0') {
            srcCursor = " NE";
            curChar = s_NE_001a4b78[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        case 7:
          emitLength3 = 0;
          if (s_FL_001a4b7c[0] != '\0') {
            srcCursor = " FL";
            curChar = s_FL_001a4b7c[0];
            do {
              srcCursor = srcCursor + 1;
              lineCursor[emitLength3] = curChar;
              emitLength3 = emitLength3 + 1;
              curChar = *srcCursor;
            } while (curChar != '\0');
          }
          break;
        default:
          goto switchD_00014940_default;
        }
        lineCursor = lineCursor + emitLength3;
switchD_00014940_default:
        if ((int)*firstOperand < 0) {
          *lineCursor = 0x31;
          lineCursor = lineCursor + 1;
        }
        operandEntriesUsed = (dword *)((int)((unsigned char *)0x0) + 1);
        *lineCursor = 0x2e;
        lineCursor[1] = (((byte)(*firstOperand >> 0x1a) & 3) + 1 & 3) + 0x77;
        lineCursor[2] = (*(char *)firstOperand + 1U & 3) + 0x77;
        lineCursor[3] = (((byte)(*firstOperand >> 0x16) & 3) + 1 & 3) + 0x77;
        lineCursor[4] = (((byte)(*firstOperand >> 0x14) & 3) + 1 & 3) + 0x77;
        lineCursor = lineCursor + 5;
        break;
      case 0x56:
      case 0x57:
        nestingDepth = nestingDepth + 1;
        emitLength3 = 0;
        if (s__001a4b5c[0] != '\0') {
          srcCursor = " ";
          curChar = s__001a4b5c[0];
          do {
            srcCursor = srcCursor + 1;
            lineCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        goto LAB_00014cb4;
      case 0x58:
      case 0x6a:
        nestingDepth = nestingDepth + 1;
        operandEntriesUsed = (dword *)((int)((unsigned char *)0x0) + 1);
        break;
      case 0x60:
      case 0x61:
        emitLength3 = 0;
        if (s__001a4b5c[0] != '\0') {
          srcCursor = " ";
          curChar = s__001a4b5c[0];
          do {
            srcCursor = srcCursor + 1;
            lineCursor[emitLength3] = curChar;
            emitLength3 = emitLength3 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
LAB_00014cb4:
        lineCursor = lineCursor + emitLength3;
LAB_00014cb8:
        operandEntriesUsed = (dword *)((int)((unsigned char *)0x0) + 2);
        argReg6 = paramGroupState;
        argReg7 = tmpRegisterNumbers;
        argReg8 = tmpGroupState;
        argReg10 = (char *)isShaderObject;
        lineCursor = (undefined1 *)
                  ((int (*)())arbIrPrintSourceOperand)(instructionRecord,lineCursor,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,2,isShaderObject,0);
        break;
      case 0x62:
        entryWord = instructionRecord[1];
        emitLength3 = ((int (*)())arbIrPrintCcAndSaturateSuffix)(lineCursor,entryWord >> 0x16 & 1,entryWord >> 0x15 & 1,entryWord >> 0x14 & 1);
        if (!isAssemblyProgram) {
          entryWord = instructionRecord[1];
          emitLength3 = ((int (*)())arbIrPrintSizeTypeSuffix)(emitLength3,entryWord >> 0x1a & 3,entryWord >> 0x1c & 1,entryWord >> 0x17 & 7);
        }
        emitLength2 = 0;
        if (s__001a4b5c[0] != '\0') {
          srcCursor = " ";
          curChar = s__001a4b5c[0];
          do {
            srcCursor = srcCursor + 1;
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        commaSeparatorBase = 0x19f634;
        emitLength3 = ((int (*)())arbIrPrintDestinationOperand)(instructionRecord,emitLength3 + emitLength2,tmpRegisterNumbers,tmpGroupState,1,isShaderObject);
        curChar = ((unsigned char *)0x00004ec0)[commaSeparatorBase];
        separatorNotEmpty = curChar != '\0';
        if (separatorNotEmpty) {
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          emitLength2 = 0;
          nextChar = curChar;
          do {
            *(char *)(emitLength3 + emitLength2) = nextChar;
            emitLength2 = emitLength2 + 1;
            nextChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (nextChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        emitLength3 = ((int (*)())arbIrPrintSourceOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,2,isShaderObject,0);
        if (separatorNotEmpty) {
          emitLength2 = 0;
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          nextChar = curChar;
          do {
            *(char *)(emitLength3 + emitLength2) = nextChar;
            emitLength2 = emitLength2 + 1;
            nextChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (nextChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        emitLength3 = ((int (*)())arbIrPrintSourceOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,3,isShaderObject,0);
        if (separatorNotEmpty) {
          emitLength2 = 0;
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          nextChar = curChar;
          do {
            *(char *)(emitLength3 + emitLength2) = nextChar;
            emitLength2 = emitLength2 + 1;
            nextChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (nextChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        emitLength3 = ((int (*)())arbIrPrintSourceOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,4,isShaderObject,0);
        if (separatorNotEmpty) {
          emitLength2 = 0;
          srcCursor = ((unsigned char *)0x00004ec1) + commaSeparatorBase;
          do {
            *(char *)(emitLength3 + emitLength2) = curChar;
            emitLength2 = emitLength2 + 1;
            curChar = *srcCursor;
            srcCursor = srcCursor + 1;
          } while (curChar != '\0');
        }
        else {
          emitLength2 = 0;
        }
        operandEntriesUsed = (dword *)((int)isShaderObject + 5);
        argReg6 = paramGroupState;
        argReg7 = tmpRegisterNumbers;
        argReg8 = tmpGroupState;
        argReg10 = (char *)isShaderObject;
        lineCursor = (undefined1 *)
                  ((int (*)())arbIrPrintTextureOperand)(instructionRecord,emitLength3 + emitLength2,paramRegisterNumbers,paramGroupState,tmpRegisterNumbers,tmpGroupState,5,isShaderObject);
      }
      emitLength3 = 0;
      curChar = ((unsigned char *)0x00005558)[semicolonBase];
      if (curChar != '\0') {
        srcCursor = ((unsigned char *)0x00005559) + semicolonBase;
        emitLength3 = 0;
        do {
          lineCursor[emitLength3] = curChar;
          emitLength3 = emitLength3 + 1;
          curChar = *srcCursor;
          srcCursor = srcCursor + 1;
        } while (curChar != '\0');
      }
      lineCursor = lineCursor + emitLength3;
      if ((!isAssemblyProgram) && (opcode - 0x4b < 0x21)) {
        switch(opcode) {
        case 0x4b:
        case 0x4c:
        case 0x54:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
        case 0x5a:
        case 0x5b:
        case 0x69:
        case 0x6a:
        case 0x6b:
          emitLength3 = printf_LDBLStub_1a32d0(lineCursor,"    # Target: %d",branchWord & 0x3ffff,argReg6,argReg7,argReg8,
                                (opcode - 0x4b) * 4,argReg10);
          lineCursor = lineCursor + emitLength3;
        }
      }
      emitLength3 = 0;
      curChar = ((unsigned char *)0x00004f8c)[newlineBase];
      if (curChar != '\0') {
        srcCursor = ((unsigned char *)0x00004f8d) + newlineBase;
        emitLength3 = 0;
        do {
          lineCursor[emitLength3] = curChar;
          emitLength3 = emitLength3 + 1;
          curChar = *srcCursor;
          srcCursor = srcCursor + 1;
        } while (curChar != '\0');
      }
      outCursor = lineCursor + (int)(outCursor + (emitLength3 - (int)lineStart));
      ensureOk = ((int (*)())textBufferEnsureRoom)(outCapacityPtr,&outBuffer,outCursorPtr);
      if (ensureOk == 0) {
        if (paramRegisterNumbers != 0) {
          _free(paramRegisterNumbers);
        }
        if (paramGroupState != (uint *)0x0) {
          _free(paramGroupState);
        }
        if (tmpRegisterNumbers != 0) {
          _free(tmpRegisterNumbers);
        }
        if (tmpGroupState != (uint *)0x0) {
          _free(tmpGroupState);
        }
        if (noLabels) goto LAB_00016630;
        _free(branchTargets);
        tmpGroupState = branchSources;
        goto LAB_000163f0;
      }
      loopCounter = loopCounter + 1;
      entryIndex = (undefined1 *)((int)operandEntriesUsed + (int)(entryIndex + 1));
    } while (instructionCount != loopCounter);
    if (!noLabels) {
      if ((labelIndex < (int)labelCountNext) && (instructionCount + 1 == branchTargets[labelIndex])) {
        emitLength5 = 0;
        if (s_label__001a4ba4[0] != '\0') {
          srcCursor = "  label_";
          curChar = s_label__001a4ba4[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength5] = curChar;
            emitLength5 = emitLength5 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength5;
        labelNumberLength = ((int (*)())textPrintSignedDecimal)(outCursor,labelIndex);
        emitLength5 = 0;
        if (s___001a4b58[0] != '\0') {
          srcCursor = ":\n";
          curChar = s___001a4b58[0];
          do {
            srcCursor = srcCursor + 1;
            outCursor[emitLength5 + labelNumberLength] = curChar;
            emitLength5 = emitLength5 + 1;
            curChar = *srcCursor;
          } while (curChar != '\0');
        }
        outCursor = outCursor + emitLength5 + labelNumberLength;
      }
      _free(branchTargets);
      _free(branchSources);
    }
  }
  emitLength = 0;
  if (s_END_001a4bb0[0] != '\0') {
    srcCursor = "END\n";
    emitLength = 0;
    curChar = s_END_001a4bb0[0];
    do {
      srcCursor = srcCursor + 1;
      outCursor[emitLength] = curChar;
      emitLength = emitLength + 1;
      curChar = *srcCursor;
    } while (curChar != '\0');
  }
  outCursor[emitLength] = 0;
  outCursor = outCursor + emitLength + 1;
  if (paramRegisterNumbers != 0) {
    _free(paramRegisterNumbers);
  }
  if (paramGroupState != (uint *)0x0) {
    _free(paramGroupState);
  }
  if (tmpRegisterNumbers != 0) {
    _free(tmpRegisterNumbers);
  }
  if (tmpGroupState != (uint *)0x0) {
    _free(tmpGroupState);
  }
  if ((int)outCursor - outBuffer < 1) {
    _free(outBuffer);
    outBuffer = 0;
  }
  else {
    outBuffer = _realloc(outBuffer,(int)outCursor - outBuffer);
  }
  return outBuffer;
LAB_00014048:
  if (paramRegisterNumbers != 0) {
    _free(paramRegisterNumbers);
  }
joined_r0x000112bc:
  if (paramGroupState != (uint *)0x0) {
    _free(paramGroupState);
  }
LAB_00014070:
  if (tmpRegisterNumbers != 0) {
    _free(tmpRegisterNumbers);
  }
  if (tmpGroupState != (uint *)0x0) {
    _free(tmpGroupState);
  }
LAB_00016630:
  _free(outBuffer);
  return 0;
}

/* glBitmap_impl @ 0x16670 (2312 bytes) */
void glBitmap_impl(int ctx,float *vertex,int width,int height,undefined4 staleArgR7,undefined4 staleArgR8,int bitmap,int tightlyPacked,double xOrigin,double yOrigin)
{
  uint lsbBit;
  int rowBytesLeft;
  int trailerOffset;
  int packetBytesTotal;
  int packetBytes;
  int vertexBudget;
  int rowLength;
  int zoomY;
  float invertedRowStep;
  double startY;
  double startX;
  int writeCursor;
  int engineState;
  bool rowHasBytes;
  bool moreBitsInByte;
  float centerOffsetX;
  float cornerCoord;
  float pixelX;
  float centerOffsetY;
  float rowStep;
  float pixelY;
  float pixelStep;
  int zoomX;
  undefined4 r4AfterCall;
  undefined4 r4AfterCall2;
  undefined4 r4AfterCall3;
  undefined4 r4AfterCall4;
  undefined4 r4AfterCall5;
  undefined4 r4AfterCall6;
  undefined4 staleArgR4Forward;
  undefined4 r4AfterCall7;
  float *packetStart;
  int packetVertexCount;
  float *alphaSlot;
  undefined4 gaPointSizeValue;
  int pointsPerPixel;
  uint bitIndex;
  int bitInByte;
  int pixelsLeft;
  float rasterZ;
  int engineStateAtRow;
  int bitsLeft;
  uint msbBit;
  uint lsbBitStart;
  float *vertexCursor;
  double fogFactor;
  double oneMinusFogFactor;
  int columns;
  int rows;
  int rowPtr;
  float colorA;
  float colorR;
  float colorG;
  float colorB;
  undefined1 auStack_178 [144];
  longlong zoomXWide;
  longlong zoomYWide;
  uint lsbStartBit;
  uint msbStartBit;
  uint lsbFirstMask;
  int byteBits;
  uint skipBits;
  uint rowBytesUsed;
  uint rowStride;
  int byteColumn;
  int rowIndex;
  uint msbFirstMask;
  int ring;
  undefined1 *puStack_ac;
  uint lsbNextByteBit;
  uint msbNextByteBit;
  int savedTrailerOffset;
  
  colorG = vertex[0xd];
  colorB = vertex[0xe];
  colorA = vertex[0xf];
  colorR = vertex[0xc];
  engineState = *(int *)(ctx + GLD_engineState);
  ring = ctx + GLD_commandStream;
  rasterZ = vertex[2];
  if (((unsigned char *)0x00002e0a)[engineState] != '\0') {
    fogFactor = (double)vertex[0x13];
    oneMinusFogFactor = DOUBLE_001aa200 - fogFactor;
    colorR = (float)(oneMinusFogFactor * (double)*(float *)(((unsigned char *)0x00002de0) + engineState) +
                        (double)(float)((double)colorR * fogFactor));
    colorG = (float)(oneMinusFogFactor * (double)*(float *)(((unsigned char *)0x00002de4) + engineState) +
                        (double)(float)((double)colorG * fogFactor));
    colorB = (float)(oneMinusFogFactor * (double)*(float *)(((unsigned char *)0x00002de8) + engineState) +
                        (double)(float)((double)colorB * fogFactor));
    colorA = (float)(oneMinusFogFactor * (double)*(float *)(((unsigned char *)0x00002dec) + engineState) +
                        (double)(float)((double)colorA * fogFactor));
  }
  zoomX = (int)(*(float *)(ctx + GLD_rasterScaleX) + FLOAT_001aa10c);
  zoomXWide = (longlong)zoomX;
  zoomY = (int)(*(float *)(ctx + GLD_rasterScaleY) + FLOAT_001aa10c);
  zoomYWide = (longlong)zoomY;
  pointsPerPixel = zoomX * zoomY;
  centerOffsetX = FLOAT_001aa10c;
  if (zoomX == 2) {
    centerOffsetX = FLOAT_001aa110;
  }
  centerOffsetY = FLOAT_001aa10c;
  if (zoomY == 2) {
    centerOffsetY = FLOAT_001aa110;
  }
  if ((0 < width) && (0 < height)) {
    puStack_ac = auStack_178;
    *(undefined1 *)(ctx + GLD_inDrawPixels) = 1;
    columns = width;
    rows = height;
    rowPtr = bitmap;
    FUN_0002a260(ring,puStack_ac);
    startX = _floor((double)(float)((double)*vertex - xOrigin));
    invertedRowStep = FLOAT_001aa114;
    rowStep = FLOAT_001aa0e8;
    if (((unsigned char *)GLD_yInverted)[ctx] == '\0') {
      startY = _floor((double)(float)((double)vertex[1] - yOrigin));
      staleArgR4Forward = r4AfterCall2;
    }
    else {
      startY = _ceil((double)((float)(yOrigin + (double)vertex[1]) - FLOAT_001aa0e8));
      staleArgR4Forward = r4AfterCall;
      rowStep = invertedRowStep;
    }
    pixelY = (float)startY;
    if (tightlyPacked == 0) {
      engineStateAtRow = *(int *)(ctx + GLD_engineState);
      rowLength = *(int *)(((unsigned char *)0x00002e6c) + engineStateAtRow);
      if (*(int *)(((unsigned char *)0x00002e6c) + engineStateAtRow) == 0) {
        rowLength = columns;
      }
      skipBits = *(uint *)(((unsigned char *)0x00002e78) + engineStateAtRow) & 7;
      rowStride = (*(int *)(((unsigned char *)0x00002e80) + engineStateAtRow) - 1U) + (rowLength + 7 >> 3) &
                  ~(*(int *)(((unsigned char *)0x00002e80) + engineStateAtRow) - 1U);
      rowPtr =
           rowPtr +
           rowStride * *(int *)(((unsigned char *)0x00002e74) + engineStateAtRow) +
           ((int)*(uint *)(((unsigned char *)0x00002e78) + engineStateAtRow) >> 3);
      rowBytesUsed = (int)(columns + skipBits + 7) >> 3;
      if (((unsigned char *)0x00002e85)[engineStateAtRow] == '\0') {
        msbFirstMask = 0xffffffff;
        lsbBitStart = 1 << skipBits;
        msbStartBit = 0x80 >> skipBits;
        lsbFirstMask = 0;
      }
      else {
        msbFirstMask = 0;
        lsbFirstMask = 0xffffffff;
        msbStartBit = 0;
        lsbBitStart = 1 << skipBits;
      }
    }
    else {
      lsbBitStart = 1;
      skipBits = 0;
      msbFirstMask = 0xff;
      lsbFirstMask = 0xffffff00;
      rowBytesUsed = columns + 7 >> 3;
      msbStartBit = 0x80;
      rowStride = rowBytesUsed;
    }
    pixelsLeft = columns * rows;
    vertexBudget = pointsPerPixel * pixelsLeft;
    packetBytesTotal = vertexBudget * 0x20;
    if (0x7ff < vertexBudget) {
      vertexBudget = 0x7ff;
      packetBytesTotal = 0xffe0;
    }
    packetStart = *(float **)(ctx + GLD_writeCursor);
    if (*(float **)(ctx + GLD_ringLimit) <= packetStart + 2) {
      gld_submitRing(ctx,0x1000000);
      packetStart = *(float **)(ctx + GLD_writeCursor);
      staleArgR4Forward = r4AfterCall3;
    }
    if (*(char *)(ring + 0x2802) == '\0') {
      packetStart[1] = 2.524355e-29;
      *packetStart = 2.07392e-42;
      *(undefined1 *)(ring + 0x2802) = 1;
      packetStart = *(float **)(ctx + GLD_writeCursor);
    }
    if (*(uint *)(ctx + GLD_ringLimit) <= (uint)((int)packetStart + packetBytesTotal + 0x10)) {
      gld_submitRing(ctx,0x1000000);
      packetStart = *(float **)(ctx + GLD_writeCursor);
      staleArgR4Forward = r4AfterCall4;
    }
    vertexCursor = packetStart + 4;
    trailerOffset = 0;
    rowIndex = 0;
    lsbStartBit = lsbBitStart & lsbFirstMask;
    rowHasBytes = 0 < (int)rowBytesUsed;
    packetVertexCount = vertexBudget;
    do {
      if (rowHasBytes) {
        pixelX = (float)startX;
        if (7 < (int)skipBits) {
          byteColumn = 0;
          lsbNextByteBit = lsbFirstMask & 1;
          msbNextByteBit = msbFirstMask & 0x80;
          bitsLeft = columns;
          goto LAB_00016e40;
        }
        byteColumn = 0;
        lsbNextByteBit = lsbFirstMask & 1;
        msbNextByteBit = msbFirstMask & 0x80;
        bitIndex = skipBits;
        msbBit = msbStartBit;
        lsbBit = lsbStartBit;
        byteBits = columns;
        do {
          pixelStep = FLOAT_001aa10c;
          bitInByte = 0;
          bitsLeft = byteBits;
          do {
            if (((uint)*(byte *)(rowPtr + byteColumn) & (lsbBit | msbBit)) != 0) {
              if (vertexBudget < pointsPerPixel) {
                *packetStart = 2.93152e-42;
                packetStart[1] = *(float *)(ring + 0x1b84);
                packetStart[2] = GH_U2F((unsigned int)(((packetVertexCount - vertexBudget) * 0x80000 | 0xc0003500)));
                packetStart[3] = GH_U2F((unsigned int)(((packetVertexCount - vertexBudget) * 0x10000 | 0x31)));
                vertexBudget = pointsPerPixel * pixelsLeft;
                *(float **)(ctx + GLD_writeCursor) = vertexCursor;
                packetBytes = vertexBudget * 0x20;
                if (0x7ff < vertexBudget) {
                  vertexBudget = 0x7ff;
                  packetBytes = 0xffe0;
                }
                if (*(uint *)(ctx + GLD_ringLimit) <= (uint)((int)vertexCursor + packetBytes + 0x10)) {
                  savedTrailerOffset = trailerOffset;
                  gld_submitRing(ctx,0x1000000);
                  staleArgR4Forward = r4AfterCall5;
                  trailerOffset = savedTrailerOffset;
                }
                packetStart = *(float **)(ctx + GLD_writeCursor);
                if ((vertexCursor != packetStart) &&
                   (*(uint *)(ctx + GLD_ringLimit) <= (uint)((int)packetStart + packetBytes + 0x10))) {
                  savedTrailerOffset = trailerOffset;
                  gld_submitRing(ctx,0x1000000);
                  packetStart = *(float **)(ctx + GLD_writeCursor);
                  staleArgR4Forward = r4AfterCall6;
                  trailerOffset = savedTrailerOffset;
                }
                vertexCursor = packetStart + 4;
                packetVertexCount = vertexBudget;
              }
              if (pointsPerPixel == 1) {
                *vertexCursor = centerOffsetX + pixelX;
                vertexCursor[1] = centerOffsetY + pixelY;
                vertexCursor[2] = rasterZ;
                vertexCursor[3] = 1.0;
                vertexCursor[4] = colorR;
                vertexCursor[5] = colorG;
                alphaSlot = vertexCursor + 7;
                vertexCursor[6] = colorB;
                vertexCursor = vertexCursor + 8;
                *alphaSlot = colorA;
              }
              else if (pointsPerPixel == 2) {
                *vertexCursor = centerOffsetX + pixelX;
                vertexCursor[1] = centerOffsetY + pixelY;
                vertexCursor[2] = rasterZ;
                vertexCursor[3] = 1.0;
                vertexCursor[4] = colorR;
                vertexCursor[5] = colorG;
                vertexCursor[6] = colorB;
                vertexCursor[7] = colorA;
                vertexCursor[8] = centerOffsetX + pixelX;
                vertexCursor[9] = centerOffsetY + pixelY + pixelStep;
                vertexCursor[10] = rasterZ;
                vertexCursor[0xb] = 1.0;
                vertexCursor[0xc] = colorR;
                vertexCursor[0xd] = colorG;
                alphaSlot = vertexCursor + 0xf;
                vertexCursor[0xe] = colorB;
                vertexCursor = vertexCursor + 0x10;
                *alphaSlot = colorA;
                pixelY = (pixelY + pixelStep) - pixelStep;
              }
              else {
                *vertexCursor = centerOffsetX + pixelX;
                vertexCursor[1] = centerOffsetY + pixelY;
                vertexCursor[2] = rasterZ;
                vertexCursor[3] = 1.0;
                vertexCursor[4] = colorR;
                vertexCursor[5] = colorG;
                vertexCursor[6] = colorB;
                vertexCursor[7] = colorA;
                vertexCursor[8] = centerOffsetX + pixelX;
                cornerCoord = centerOffsetY + pixelY + pixelStep;
                vertexCursor[9] = cornerCoord;
                vertexCursor[10] = rasterZ;
                vertexCursor[0xb] = 1.0;
                vertexCursor[0xc] = colorR;
                vertexCursor[0xd] = colorG;
                vertexCursor[0xe] = colorB;
                vertexCursor[0xf] = colorA;
                vertexCursor[0x11] = cornerCoord;
                cornerCoord = centerOffsetX + pixelX + pixelStep;
                vertexCursor[0x10] = cornerCoord;
                vertexCursor[0x12] = rasterZ;
                vertexCursor[0x13] = 1.0;
                vertexCursor[0x14] = colorR;
                vertexCursor[0x15] = colorG;
                vertexCursor[0x16] = colorB;
                vertexCursor[0x17] = colorA;
                pixelY = (pixelY + pixelStep) - pixelStep;
                vertexCursor[0x18] = cornerCoord;
                vertexCursor[0x19] = centerOffsetY + pixelY;
                vertexCursor[0x1a] = rasterZ;
                vertexCursor[0x1b] = 1.0;
                vertexCursor[0x1c] = colorR;
                vertexCursor[0x1d] = colorG;
                alphaSlot = vertexCursor + 0x1f;
                vertexCursor[0x1e] = colorB;
                vertexCursor = vertexCursor + 0x20;
                *alphaSlot = colorA;
                pixelX = (pixelX + pixelStep) - pixelStep;
              }
              vertexBudget = vertexBudget - pointsPerPixel;
            }
            moreBitsInByte = bitIndex != 7;
            pixelsLeft = pixelsLeft + -1;
            lsbBit = lsbBit << 1;
            msbBit = msbBit >> 1;
            bitsLeft = bitsLeft + -1;
            bitIndex = bitIndex + 1;
            pixelX = pixelX + FLOAT_001aa0e8;
          } while ((moreBitsInByte) && (bitInByte = bitInByte + 1, byteBits != bitInByte));
LAB_00016e40:
          rowBytesLeft = rowBytesUsed - byteColumn;
          do {
            byteColumn = byteColumn + 1;
            rowBytesLeft = rowBytesLeft + -1;
            if (rowBytesLeft == 0) goto LAB_00016a6c;
          } while (bitsLeft == 0);
          bitIndex = 0;
          msbBit = msbNextByteBit;
          lsbBit = lsbNextByteBit;
          byteBits = bitsLeft;
        } while( true );
      }
LAB_00016a6c:
      pixelY = pixelY + rowStep;
      rowIndex = rowIndex + 1;
      rowPtr = rowPtr + rowStride;
    } while (rows != rowIndex);
    packetVertexCount = packetVertexCount - vertexBudget;
    if (packetVertexCount == 0) {
      vertexCursor = vertexCursor + -4;
    }
    else {
      *(undefined4 *)((int)packetStart + trailerOffset) = 0x82c;
      *(undefined4 *)((int)packetStart + trailerOffset + 4) = *(undefined4 *)(ring + 0x1b84);
      *(uint *)((int)packetStart + trailerOffset + 8) = packetVertexCount * 0x80000 | 0xc0003500;
      *(uint *)((int)packetStart + trailerOffset + 0xc) = packetVertexCount * 0x10000 | 0x31;
    }
    *(float **)(ctx + GLD_writeCursor) = vertexCursor;
    if (*(float **)(ctx + GLD_ringLimit) <= vertexCursor + 2) {
      savedTrailerOffset = trailerOffset;
      gld_submitRing(ctx,0x1000000);
      staleArgR4Forward = r4AfterCall7;
      trailerOffset = savedTrailerOffset;
    }
    writeCursor = *(int *)(ctx + GLD_writeCursor);
    *(int *)(ctx + GLD_writeCursor) = writeCursor + 8;
    *(undefined **)(writeCursor + trailerOffset) = ((unsigned char *)0x00001087U);
    gaPointSizeValue = *(undefined4 *)(ring + 0x1ccc);
    *(undefined4 *)(writeCursor + 4 + trailerOffset) = gaPointSizeValue;
    FUN_0009d3b0(ring,staleArgR4Forward,width,trailerOffset,packetStart,packetVertexCount,gaPointSizeValue);
    FUN_000872e0(ring,puStack_ac);
  }
  return;
}

/* gld_bufferEnumToIndex @ 0x16fc0 (272 bytes) */
int gld_bufferEnumToIndex(bufferEnum, drawableFlags)
  uint bufferEnum;
  uint drawableFlags;
{
  if (bufferEnum != 0x405) {
    if (bufferEnum < 0x406) {
      if (bufferEnum == 0x401) {
LAB_00017070:
        if ((drawableFlags & 0x10) == 0) {
          return 1;
        }
        return 3;
      }
      if (bufferEnum < 0x402) {
        if (bufferEnum == 0) {
          return 0x11;
        }
        if (bufferEnum == 0x400) {
          return 1;
        }
      }
      else {
        if (bufferEnum == 0x403) {
          if ((drawableFlags & 0x400) == 0) {
            return 1;
          }
          if ((drawableFlags & 0x10) == 0) {
            return 0;
          }
          return 2;
        }
        if (0x403 < bufferEnum) {
          return 1;
        }
      }
    }
    else {
      if (bufferEnum == 0x408) {
        return 1;
      }
      if (bufferEnum < 0x409) {
        if (bufferEnum == 0x406) {
          return 1;
        }
        if (bufferEnum == 0x407) goto LAB_00017070;
      }
      else if (bufferEnum == 0x40a) {
        if (0x1ff < (drawableFlags & 0x300)) {
          return 8;
        }
      }
      else if (bufferEnum < 0x40a) {
        if (0xff < (drawableFlags & 0x300)) {
          return 7;
        }
      }
      else if ((bufferEnum == 0x40b) && (0x2ff < (drawableFlags & 0x300))) {
        return 9;
      }
    }
  }
  if ((drawableFlags & 0x400) == 0) {
    return 1;
  }
  return 0;
}

/* FUN_00017100 @ 0x17100 (84 bytes) */
int FUN_00017100(ctx, pname, values)
  int ctx;
  int pname;
  undefined4 *values;
{
  if (pname == 0xcb) {
    if (*(char *)(ctx + 0x2a80) != '\0') {
      *(char *)(ctx + GLD_swapIntervalDenominator) = (char)*values;
      return 1;
    }
  }
  else if ((pname == 0xde) && (*(char *)(ctx + 0x2a80) != '\0')) {
    *(char *)(ctx + GLD_swapIntervalNumerator) = (char)*values;
    return 1;
  }
  return 0;
}

/* FUN_00017160 @ 0x17160 (236 bytes) */
int FUN_00017160(ctx, flagsInOut, pbuffer)
  int ctx;
  uint *flagsInOut;
  int pbuffer;
{
  uint levelBits;
  uint flags;
  int target;
  
  flags = *flagsInOut & 0x80ffffff;
  *flagsInOut = flags;
  if (pbuffer == 0) {
    *(undefined1 *)(ctx + 0x143) = 1;
  }
  else {
    target = *(int *)(pbuffer + 0xc);
    if (target - 0xde0U < 2) {
      flags = flags | 0x10000000;
      *flagsInOut = flags;
    }
    else if (target == 0x84f5) {
      flags = flags | 0x20000000;
      *flagsInOut = flags;
    }
    else if (target == 0x8513) {
      flags = flags | 0x30000000;
      *flagsInOut = flags;
    }
    levelBits = 0xc000000;
    if (*(int *)(pbuffer + 0x14) < 0xd) {
      levelBits = *(int *)(pbuffer + 0x14) << 0x18;
    }
    *flagsInOut = levelBits & 0xf000000 | flags;
    *(undefined1 *)(ctx + 0x143) = 0;
  }
  if (*(int *)(ctx + GLD_boundFramebuffer) == 0) {
    if (pbuffer == 0) {
      **(uint **)(ctx + GLD_capsBlock) = **(uint **)(ctx + GLD_capsBlock) | 2;
      ((unsigned char *)GLD_yInverted)[ctx] = 1;
    }
    else {
      **(uint **)(ctx + GLD_capsBlock) = **(uint **)(ctx + GLD_capsBlock) & 0xfffffffd;
      ((unsigned char *)GLD_yInverted)[ctx] = 0;
    }
  }
  FUN_000a7a60(ctx);
  return;
}

/* FUN_00017260 @ 0x17260 (168 bytes) */
int FUN_00017260(ctx)
  int ctx;
{
  int attachment;
  undefined1 formatByte;
  int *framebuffer;
  int attachPoint;
  int attachLeft;
  
  framebuffer = *(int **)(ctx + GLD_boundFramebuffer);
  if (framebuffer == (int *)0x0) {
    formatByte = window_mode_to_ati_format(*(undefined4 *)(ctx + GLD_renderFlags));
    ((unsigned char *)GLD_colorFormatIndex)[ctx] = formatByte;
  }
  else {
    attachLeft = 4;
    ((unsigned char *)GLD_colorFormatIndex)[ctx] = 0x2f;
    attachPoint = *framebuffer;
    do {
      if ((*(ushort *)(attachPoint + 0x90) != 0) &&
         (attachment = *(int *)((*(ushort *)(attachPoint + 0x90) - 0x8ce0) * 4 + framebuffer[1]), attachment != 0)) {
        ((unsigned char *)GLD_colorFormatIndex)[ctx] = *(undefined1 *)(attachment + 0x38);
        break;
      }
      attachPoint = attachPoint + 2;
      attachLeft = attachLeft + -1;
    } while (attachLeft != 0);
  }
  return FUN_000a7a60(ctx);
}

/* gld_setIntegerEngineParam @ 0x17310 (1008 bytes) */
int gld_setIntegerEngineParam(ctx, pname, values)
  int ctx;
  uint pname;
  undefined4 *values;
{
  uint refillCount;
  uint updateFlags2;
  undefined4 returnCode;
  uint updateFlags;
  uint dataLimit;
  undefined4 *writeCursor;
  int dataCursor;
  uint *lastHeader;
  undefined4 outputCount;
  int bufferBase;
  uint bufferSize;
  
  returnCode = 0x271e;
  if (values != (undefined4 *)0x0) {
    if (pname == 0x132) {
      writeCursor = *(undefined4 **)(ctx + 0x1dc);
      if (*(undefined4 **)(ctx + 0x1e0) <= writeCursor + 4) {
        gld_submitRing(ctx,0x1000000);
        writeCursor = *(undefined4 **)(ctx + 0x1dc);
      }
      lastHeader = *(uint **)(ctx + 0x1d8);
      *(undefined4 **)(ctx + 0x1dc) = writeCursor + 4;
      *lastHeader = (int)writeCursor - (int)lastHeader >> 2 | *lastHeader;
      *(undefined4 **)(ctx + 0x1d8) = writeCursor;
      *writeCursor = 0x3d000000;
      writeCursor[1] = 0x132;
      writeCursor[2] = *values;
      writeCursor[3] = 0;
      returnCode = 0;
    }
    else {
      if (pname < 0x133) {
        if (pname == 300) {
          writeCursor = *(undefined4 **)(ctx + 0x1dc);
          if (*(undefined4 **)(ctx + 0x1e0) <= writeCursor + 6) {
            gld_submitRing(ctx,0x1000000);
            writeCursor = *(undefined4 **)(ctx + 0x1dc);
          }
          *(undefined4 **)(ctx + 0x1dc) = writeCursor + 6;
          *writeCursor = ((unsigned char *)0x00001040U);
          writeCursor[1] = 0;
          writeCursor[2] = ((unsigned char *)0x00001393U);
          writeCursor[3] = 10;
          writeCursor[4] = 0x5c8;
          writeCursor[5] = 0x20000;
          return 0;
        }
      }
      else {
        if (pname == 0x1fe) {
          if ((*(int *)(ctx + 0xf8) != 0) && (*(int *)(ctx + 0x2a84) == 0)) {
            returnCode = FUN_00019db0(ctx,*values,1);
            return returnCode;
          }
          return 0;
        }
        if (pname == 0x29b) {
          if (*(uint *)(ctx + 0x1e0) <= *(int *)(ctx + 0x1dc) + 0x60U) {
            gld_submitRing(ctx,0x1000000);
          }
          dataCursor = *(int *)(ctx + 500);
          dataLimit = *(uint *)(ctx + 0x1f8);
          if (dataLimit <= dataCursor + 0x800U) {
            outputCount = 2;
            refillCount = *(int *)(ctx + 0x204) + 1;
            *(uint *)(ctx + 0x204) = refillCount;
            if (2 < refillCount) {
              if (*(int *)(ctx + 0x1e4) + 0x28U < *(uint *)(ctx + 0x1dc)) {
                gld_submitRing(ctx,0x1000000);
                dataCursor = *(int *)(ctx + 500);
              }
              *(undefined4 *)(ctx + 0x204) = 1;
            }
            *(int *)(*(int *)(ctx + 0x208) + 0xc) = dataCursor - *(int *)(ctx + 0x1fc) >> 2;
            _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(ctx + 4),0x12,0,0,&bufferBase,&outputCount);
            updateFlags = *(uint *)(0x000026c8 + ctx);
            *(int *)(ctx + 0x1fc) = bufferBase;
            dataLimit = bufferBase + (bufferSize & 0xfffffffc);
            *(int *)(ctx + 500) = bufferBase;
            *(uint *)(ctx + 0x1f8) = dataLimit;
            returnCode = *(undefined4 *)(*(int *)(ctx + 0x208) + 8);
            *(uint *)(0x000026c8 + ctx) = updateFlags | 1;
            *(undefined4 *)(ctx + 0x200) = returnCode;
            dataCursor = bufferBase;
          }
          if (dataLimit <= dataCursor + 800U) {
            outputCount = 2;
            refillCount = *(int *)(ctx + 0x204) + 1;
            *(uint *)(ctx + 0x204) = refillCount;
            if (2 < refillCount) {
              if (*(int *)(ctx + 0x1e4) + 0x28U < *(uint *)(ctx + 0x1dc)) {
                gld_submitRing(ctx,0x1000000);
                dataCursor = *(int *)(ctx + 500);
              }
              *(undefined4 *)(ctx + 0x204) = 1;
            }
            *(int *)(*(int *)(ctx + 0x208) + 0xc) = dataCursor - *(int *)(ctx + 0x1fc) >> 2;
            _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(ctx + 4),0x12,0,0,&bufferBase,&outputCount);
            updateFlags2 = *(uint *)(0x000026c8 + ctx);
            *(int *)(ctx + 0x1fc) = bufferBase;
            *(int *)(ctx + 500) = bufferBase;
            *(uint *)(ctx + 0x1f8) = bufferBase + (bufferSize & 0xfffffffc);
            returnCode = *(undefined4 *)(*(int *)(ctx + 0x208) + 8);
            *(uint *)(0x000026c8 + ctx) = updateFlags2 | 1;
            *(undefined4 *)(ctx + 0x200) = returnCode;
            dataCursor = bufferBase;
          }
          dataCursor = dataCursor + 800;
          *(int *)(ctx + 500) = dataCursor;
          outputCount = 2;
          refillCount = *(int *)(ctx + 0x204) + 1;
          *(uint *)(ctx + 0x204) = refillCount;
          if (2 < refillCount) {
            if (*(int *)(ctx + 0x1e4) + 0x28U < *(uint *)(ctx + 0x1dc)) {
              gld_submitRing(ctx,0x1000000);
              dataCursor = *(int *)(ctx + 500);
            }
            *(undefined4 *)(ctx + 0x204) = 1;
          }
          *(int *)(*(int *)(ctx + 0x208) + 0xc) = dataCursor - *(int *)(ctx + 0x1fc) >> 2;
          _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(ctx + 4),0x12,0,0,&bufferBase,&outputCount);
          updateFlags2 = *(uint *)(0x000026c8 + ctx);
          *(int *)(ctx + 0x1fc) = bufferBase;
          *(int *)(ctx + 500) = bufferBase;
          *(uint *)(ctx + 0x1f8) = bufferBase + (bufferSize & 0xfffffffc);
          returnCode = *(undefined4 *)(*(int *)(ctx + 0x208) + 8);
          *(uint *)(0x000026c8 + ctx) = updateFlags2 | 1;
          *(undefined4 *)(ctx + 0x200) = returnCode;
          return 0;
        }
      }
      returnCode = 0x271a;
    }
  }
  return returnCode;
}

/* FUN_00017720 @ 0x17720 (36 bytes) */
int FUN_00017720(rendererIndex)
  undefined4 rendererIndex;
{
  uint gld_testRendererAvailableResult;
  
  gld_testRendererAvailableResult = gld_testRendererAvailable(rendererIndex);
  return gld_testRendererAvailableResult | 0x1900;
}

/* gld_fillCapsBlock @ 0x17750 (748 bytes) */
int gld_fillCapsBlock(ctx, stateBlock, pixelFormat)
  undefined4 ctx;
  undefined4 *stateBlock;
  int pixelFormat;
{
  short sampleCount;
  undefined4 depthStencilBitsValue;
  int pixelFormatHome;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  uint pixelFormatFlag1;
  short channelBits0;
  short channelBits1;
  short channelBits2;
  short channelBits3;
  short channelBits4;
  
  stateBlock[0x29] = 0x80;
  *stateBlock = 10;
  *(undefined1 *)((int)stateBlock + 0x7b) = 1;
  *(undefined1 *)(stateBlock + 0x1e) = 1;
  *(undefined1 *)((int)stateBlock + 0x79) = 1;
  *(undefined1 *)((int)stateBlock + 0x7a) = 1;
  stateBlock[3] = 0x1000;
  stateBlock[4] = 0x1000;
  stateBlock[5] = 4;
  stateBlock[6] = 4;
  stateBlock[7] = 0x20;
  stateBlock[8] = 0x20;
  stateBlock[0x1b] = 0x3f800000;
  stateBlock[0x1c] = 0x42800000;
  stateBlock[0x1d] = 0x3e000000;
  stateBlock[1] = 0x3f800000;
  stateBlock[2] = 3;
  stateBlock[0x28] = 0x80;
  stateBlock[0x2a] = 0x20;
  stateBlock[0x18] = 0x3f800000;
  stateBlock[0x19] = 0x42800000;
  stateBlock[0x1a] = 0x3e000000;
  *(byte *)(stateBlock + 9) = (byte)(-(uint)(*(uint *)(pixelFormat + 0x10) & 0x3ffffffc) >> 0x1f);
  *(byte *)((int)stateBlock + 0x25) = (byte)(*(uint *)(pixelFormat + 0xc) >> 3) & 1;
  pixelFormatFlag1 = *(uint *)(pixelFormat + 0xc) >> 1 & 1;
  *(char *)((int)stateBlock + 0x26) = (char)pixelFormatFlag1;
  *(byte *)((int)stateBlock + 0x27) = (byte)(-(uint)(*(uint *)(pixelFormat + 0x10) & 0x3f000000) >> 0x1f);
  pixelFormatHome = pixelFormat;
  gld_channelBitsForFormat(*(undefined4 *)(pixelFormat + 0x10),&channelBits0,pixelFormat,staleArgR6,staleArgR7,staleArgR8,pixelFormatFlag1);
  stateBlock[10] = (int)channelBits4;
  stateBlock[0xb] = (int)channelBits0;
  stateBlock[0xc] = (int)channelBits1;
  stateBlock[0xd] = (int)channelBits2;
  stateBlock[0xe] = (int)channelBits3;
  gld_channelBitsForFormat(*(undefined4 *)(pixelFormat + 0x14),&channelBits0,pixelFormatHome,staleArgR6,staleArgR7,staleArgR8,(int)channelBits2);
  stateBlock[0x11] = (int)channelBits0;
  stateBlock[0x12] = (int)channelBits1;
  stateBlock[0x13] = (int)channelBits2;
  stateBlock[0x14] = (int)channelBits3;
  depthStencilBitsValue = FUN_0000a0f0(*(undefined4 *)(pixelFormat + 0x18));
  stateBlock[0xf] = depthStencilBitsValue;
  depthStencilBitsValue = FUN_0000a0f0(*(undefined4 *)(pixelFormat + 0x1c));
  stateBlock[0x10] = depthStencilBitsValue;
  stateBlock[0x15] = (int)*(short *)(pixelFormat + 0x22);
  stateBlock[0x16] = (int)*(short *)(pixelFormat + 0x24);
  sampleCount = *(short *)(pixelFormat + 0x26);
  *(undefined2 *)((int)stateBlock + 0x7e) = 2;
  *(undefined2 *)((int)stateBlock + 0x82) = 6;
  *(undefined2 *)(stateBlock + 0x1f) = 3;
  stateBlock[0x22] = 0x800;
  stateBlock[0x25] = stateBlock[0x25] | 4;
  stateBlock[0x23] = 0xffff;
  *(undefined2 *)((int)stateBlock + 0xba) = 8;
  stateBlock[0x2c] = 0x41800000;
  stateBlock[0x17] = (int)sampleCount;
  *(undefined2 *)((int)stateBlock + 0xc2) = 0x1000;
  *(undefined2 *)(stateBlock + 0x20) = 1;
  *(undefined2 *)(stateBlock + 0x21) = 5;
  *(undefined2 *)((int)stateBlock + 0x86) = 4;
  stateBlock[0x47] = 0;
  stateBlock[0x48] = 0;
  stateBlock[0x26] = 0;
  stateBlock[0x24] = 4;
  *(undefined2 *)(stateBlock + 0x2d) = 8;
  *(undefined2 *)(stateBlock + 0x2e) = 0;
  stateBlock[0x2b] = 0x41800000;
  *(undefined2 *)(stateBlock + 0x2f) = 0x1000;
  *(undefined2 *)((int)stateBlock + 0xbe) = 0x200;
  stateBlock[0x3a] = 0x1000;
  *(undefined2 *)(stateBlock + 0x30) = 0x1000;
  *(undefined1 *)((int)stateBlock + 199) = 1;
  *(undefined2 *)((int)stateBlock + 0xb6) = 0x10;
  stateBlock[0x32] = 0x83f0;
  *(undefined1 *)((int)stateBlock + 0xc6) = 5;
  *(undefined2 *)(stateBlock + 0x3c) = 0x100;
  *(undefined2 *)((int)stateBlock + 0xf2) = 0x20;
  *(undefined2 *)(stateBlock + 0x46) = 1;
  *(undefined2 *)((int)stateBlock + 0x102) = 0x40;
  *(undefined2 *)((int)stateBlock + 0x10e) = 0x200;
  *(undefined2 *)((int)stateBlock + 0xfe) = 10;
  *(undefined2 *)(stateBlock + 0x44) = 4;
  *(undefined2 *)((int)stateBlock + 0x116) = 0;
  *(undefined2 *)(stateBlock + 0x3b) = 0x100;
  *(undefined2 *)(stateBlock + 0x3d) = 0;
  *(undefined2 *)((int)stateBlock + 0xf6) = 0;
  *(undefined2 *)(stateBlock + 0x40) = 0x40;
  *(undefined2 *)(stateBlock + 0x43) = 0x200;
  *(undefined2 *)(stateBlock + 0x41) = 0;
  *(undefined2 *)((int)stateBlock + 0x106) = 0;
  *(undefined2 *)((int)stateBlock + 0x112) = 0;
  *(undefined2 *)(stateBlock + 0x45) = 0;
  stateBlock[0x33] = 0x83f1;
  stateBlock[0x34] = 0x83f2;
  stateBlock[0x35] = 0x83f3;
  stateBlock[0x36] = 0x8837;
  stateBlock[0x3e] = 0;
  stateBlock[0x42] = 0;
  stateBlock[0x49] = stateBlock[0x49] | 0xffb7ffff;
  stateBlock[0x4b] = stateBlock[0x4b] | 0x74fc;
  *(undefined2 *)((int)stateBlock + 0xee) = 0x12;
  stateBlock[0x4a] = stateBlock[0x4a] | 0x447f9e7;
  *(undefined2 *)(stateBlock + 0x3f) = 0x400;
  return;
}

/* FUN_00017a40 @ 0x17a40 (200 bytes) */
int FUN_00017a40(flagsInOut, pixelFormat, unused3, unused4, unused5, unused6, unused7)
  uint *flagsInOut;
  int pixelFormat;
  undefined4 unused3;
  undefined4 unused4;
  undefined4 unused5;
  undefined4 unused6;
  undefined4 unused7;
{
  int depthMask;
  uint flags;
  
  depthMask = *(int *)(pixelFormat + 0x18);
  flags = *flagsInOut;
  if (depthMask != 1) {
    if (depthMask == 0x400) {
      flags = flags | 0x10000;
    }
    else if (depthMask == 0x800) {
      flags = flags | 0x30000;
    }
    else {
      flags = flags | 0x20000;
    }
  }
  if ((*(uint *)(pixelFormat + 8) & 8) != 0) {
    flags = flags | 0x80000000;
  }
  if (*(short *)(pixelFormat + 0x24) != 0) {
    if (((flags & 0xf) == 4) && (*(int *)(pixelFormat + 0x28) != 1)) {
      if (*(short *)(pixelFormat + 0x26) == 6) {
        flags = flags | 0x400000;
      }
      else if (*(short *)(pixelFormat + 0x26) == 4) {
        flags = flags | 0x200000;
      }
      else {
        flags = flags | 0x100000;
      }
    }
    else if ((*(short *)(pixelFormat + 0x26) == 4) || (*(short *)(pixelFormat + 0x26) == 6)) {
      flags = flags | 0x80000;
    }
    else {
      flags = flags | 0x40000;
    }
  }
  *flagsInOut = flags;
  return;
}

/* gld_postDisplayNotification @ 0x17b20 (740 bytes) */
int gld_postDisplayNotification(ctx)
  int ctx;
{
  int distributedCenter;
  undefined4 pid;
  int displaysNotificationName;
  int displaysNotificationObject;
  int pidKey;
  int displayMaskKey;
  int driverNotificationName;
  int driverNotificationObject;
  int userInfo;
  /* local_48/local_44 and local_40/local_3c are each used as a 2-element array (&local_48 /
   * &local_40 passed to _CFDictionaryCreate with count=2) - classic Ghidra stack-split: at -O0
   * these landed non-adjacent (confirmed live: &local_48+4 == &local_40, not &local_44), so
   * CFDictionaryCreate read local_40's CFNumber as the 2nd dictionary key instead of local_44's
   * CFString, corrupting the notification dictionary and crashing inside CFStringCreateCopy.
   * Merged into real contiguous arrays to match the actual usage (issue #64). */
  int local_48_arr[2];
  int local_40_arr[2];
#define local_48 local_48_arr[0]
#define local_44 local_48_arr[1]
#define local_40 local_40_arr[0]
#define local_3c local_40_arr[1]

  distributedCenter = _CFNotificationCenterGetDistributedCenter();
  pid = _getpid();
  *(undefined4 *)(ctx + 0x2a60) = pid;
  if (distributedCenter == 0) {
    return;
  }
  displaysNotificationName = _CFStringCreateWithCString(0,"ATI Displays",0x600);
  displaysNotificationObject = _CFStringCreateWithCString(0,"com.ati.ati_displays",0x600);
  pidKey = _CFStringCreateWithCString(0,"pid",0x600);
  displayMaskKey = _CFStringCreateWithCString(0,"gldisplaymask",0x600);
  driverNotificationName = _CFStringCreateWithCString(0,"ATI GL Driver",0x600);
  driverNotificationObject = _CFStringCreateWithCString(0,"com.ati.ati_gl_driver",0x600);
  if (displaysNotificationName == 0) goto LAB_00017d90;
  if ((((displaysNotificationObject != 0) && (pidKey != 0)) && (displayMaskKey != 0)) && ((driverNotificationName != 0 && (driverNotificationObject != 0)))) {
    _CFNotificationCenterAddObserver(distributedCenter,ctx,PTR_FUN_001e88c4,displaysNotificationName,displaysNotificationObject,2);
    local_48 = pidKey;
    local_40 = _CFNumberCreate(0,3,ctx + 0x2a60);
    local_44 = displayMaskKey;
    local_3c = _CFNumberCreate(0,3,ctx + 0x2a64);
    if (local_40 != 0) {
      if (local_3c != 0) {
        userInfo = _CFDictionaryCreate(*(undefined4 *)PTR_001e88c0,&local_48,&local_40,2,PTR_001e88b8,
                                    PTR_001e88bc);
        if (userInfo != 0) {
          _CFNotificationCenterPostNotification(distributedCenter,driverNotificationName,driverNotificationObject,userInfo,1);
          _CFRelease(userInfo);
        }
        if (local_40 == 0) goto LAB_00017cfc;
      }
      _CFRelease(local_40);
    }
LAB_00017cfc:
    if (local_3c != 0) {
      _CFRelease(local_3c);
    }
  }
  _CFRelease(displaysNotificationName);
LAB_00017d90:
  if (displaysNotificationObject != 0) {
    _CFRelease(displaysNotificationObject);
  }
  if (pidKey != 0) {
    _CFRelease(pidKey);
  }
  if (displayMaskKey != 0) {
    _CFRelease(displayMaskKey);
  }
  if (driverNotificationName != 0) {
    _CFRelease(driverNotificationName);
  }
  if (driverNotificationObject != 0) {
    _CFRelease(driverNotificationObject);
  }
  return;
}

/* gldRemoveDisplayNotificationObserver @ 0x17e10 (204 bytes) */
int gldRemoveDisplayNotificationObserver(ctx)
  undefined4 ctx;
{
  int distributedCenter;
  int notificationName;
  int notificationObject;
  
  distributedCenter = _CFNotificationCenterGetDistributedCenter();
  if (distributedCenter != 0) {
    notificationName = _CFStringCreateWithCString(0,"ATI Displays",0x600);
    notificationObject = _CFStringCreateWithCString(0,"com.ati.ati_displays",0x600);
    if (notificationName != 0) {
      if (notificationObject != 0) {
        _CFNotificationCenterRemoveObserver(distributedCenter,ctx,notificationName,notificationObject);
      }
      _CFRelease(notificationName);
    }
    if (notificationObject != 0) {
      _CFRelease(notificationObject);
      return;
    }
  }
  return;
}

/* gld_printApplicationPath @ 0x17ee0 (432 bytes) */
int gld_printApplicationPath()
{
  undefined1 *scanPtr;
  undefined4 pid;
  int psPipe;
  int allocation;
  int allocation2;
  undefined1 *pathStart;
  int pathLength;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int scanIndex;
  undefined4 staleArgR10;
  int scanLeft;
  undefined1 commandLine [52];
  
  pid = _getpid();
  printf_LDBLStub_1a32d0(commandLine,"ps -wwp %d\n",pid,staleArgR6,staleArgR7,staleArgR8,scanIndex,staleArgR10);
  psPipe = _popen(commandLine,"r");
  if (psPipe == 0) {
    _puts("  failed to compute application path");
  }
  else {
    allocation = _malloc(0x200);
    allocation2 = _malloc(0x100);
    if ((allocation == 0) || (allocation2 == 0)) {
      _puts("  failed to compute application path");
    }
    else {
      _fgets(allocation,0x32,psPipe);
      _fgets(allocation,0x200,psPipe);
      pathStart = (undefined1 *)_index(allocation,0x2f);
      pathLength = _rindex(allocation,0x2d);
      if (pathLength == 0) {
        pathLength = _strchr(allocation,0);
      }
      pathLength = pathLength - (int)pathStart;
      if (0 < pathLength) {
        scanIndex = 0;
        scanPtr = pathStart;
        scanLeft = pathLength;
        do {
          if ((pathStart[scanIndex] == ' ') && (scanPtr[1] == '/')) {
            *scanPtr = 0;
            break;
          }
          scanIndex = scanIndex + 1;
          scanPtr = scanPtr + 1;
          scanLeft = scanLeft + -1;
        } while (scanLeft != 0);
      }
      _strlcpy(allocation2,pathStart,pathLength);
      printf_LDBLStub_1a337c("  application path | %s\n",pathStart,pathLength,staleArgR6,staleArgR7,staleArgR8,scanIndex,staleArgR10);
    }
    _pclose(psPipe);
    if (allocation != 0) {
      _free(allocation);
    }
    if (allocation2 != 0) {
      _free(allocation2);
    }
  }
  return;
}

/* FUN_00018090 @ 0x18090 (100 bytes) */
int FUN_00018090(variantCode, variantFlags)
  uint variantCode;
  uint variantFlags;
{
  if ((variantFlags & 0x2000) == 0) {
    return 0;
  }
  if (variantCode != 8) {
    if (variantCode < 9) {
      if (variantCode != 7) {
        return 0;
      }
      goto LAB_000180e4;
    }
    if (variantCode == 10) goto LAB_000180e4;
    if (variantCode != 0xb) {
      return 0;
    }
  }
  if (0x1ff < (variantFlags & 0x300)) {
    return 2;
  }
LAB_000180e4:
  if ((variantFlags & 0x300) < 0x100) {
    return 0;
  }
  return 1;
}

/* glCopyPixels_impl @ 0x18120 (6016 bytes) */
int glCopyPixels_impl(ctx, rasterPos, srcX, srcY, width, height, copyType)
  int ctx;
  float *rasterPos;
  int srcX;
  int srcY;
  int width;
  int height;
  int copyType;
{
  uint surfaceHeight;
  uint surfaceWidth;
  uint writeMaskNibble;
  uint *packetCursor;
  uint ga_point_size;
  uint sc_scissor1;
  uint rb3d_ropcntl;
  uint rb3d_color_channel_mask;
  uint tx_format2;
  uint tx_format1;
  uint tx_format0;
  uint tx_filter0;
  uint rs_ip_0;
  uint rs_count;
  uint us_out_fmt_3;
  uint us_out_fmt_2;
  uint us_out_fmt_1;
  uint us_out_fmt_0;
  uint gb_ps3_enable;
  uint tx_enable;
  uint ga_color_control;
  uint rb3d_blendcntl;
  uint ga_poly_mode;
  uint fg_alpha_func;
  uint zb_cntl;
  uint vap_out_vtx_fmt_1;
  uint vap_out_vtx_fmt_0;
  uint gb_enable;
  uint rb3d_dither_ctl;
  uint su_cull_mode;
  uint vap_vte_cntl;
  uint vap_clip_cntl;
  uint vap_cntl_status;
  uint zb_zstencilcntl;
  uint sc_hyperz_en;
  uint gb_aa_config;
  uint gb_mspos1;
  uint sc_screendoor;
  uint sc_edgerule;
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  ushort bufferWidth16;
  ushort bufferHeight16;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  bool srcDstOverlap;
  double doubleBias;
  int iVar24;
  uint uVar26;
  int iVar27;
  uint writeMaskByte;
  int iVar29;
  uint *previousHeader;
  uint *lastHeader;
  undefined4 uVar32;
  int iVar33;
  int iVar34;
  undefined4 *packetAlloc;
  uint uVar36;
  uint uVar37;
  int iVar38;
  uint uVar39;
  int iVar40;
  uint uVar41;
  undefined *puVar42;
  uint uVar43;
  int destEndY;
  uint uVar44;
  uint uVar45;
  uint uVar46;
  uint uVar47;
  uint uVar48;
  uint uVar49;
  int engineState;
  undefined4 *packetBase;
  uint uVar52;
  
  engineState = *(int *)(ctx + 0x10);
  iVar34 = srcX;
  iVar29 = srcY;
  iVar38 = width;
  iVar40 = height;
  uVar32 = ((int (*)())gld_textureVariantClass)((uint)*(ushort *)(((unsigned char *)0x00002db8) + engineState),*(undefined4 *)(ctx + 0x154));
  if ((((unsigned char *)0x00002d84)[engineState] == '\0') ||
     ((((((*(int *)(((unsigned char *)0x00002d68) + engineState) == 0x10000 &&
          (*(int *)(((unsigned char *)0x00002d6c) + engineState) == 0x10000)) &&
         (*(short *)(((unsigned char *)0x00002d80) + engineState) != -0x7ff5)) &&
        ((*(short *)(((unsigned char *)0x00002d80) + engineState) != -0x7ff9 &&
         (*(short *)(((unsigned char *)0x00002d82) + engineState) != -0x7ff5)))) &&
       (*(short *)(((unsigned char *)0x00002d82) + engineState) != -0x7ff9)) || (((unsigned char *)0x00002e33)[engineState] != '\0')))) {
    uVar41 = *(uint *)(ctx + 0x26b0) & 0xfffffffd;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  else {
    uVar41 = *(uint *)(ctx + 0x26b0) | 2;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  if (((unsigned char *)0x00002d66)[engineState] == '\0') {
    uVar41 = uVar41 & 0xfffffffe;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  else {
    uVar41 = uVar41 | 1;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  if ((*(uint *)(((unsigned char *)0x000030b4) + engineState) & 0xcff1) == 0) {
    uVar41 = uVar41 & 0xfffff7ff;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  else {
    uVar41 = uVar41 | 0x800;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  if ((((unsigned char *)0x00002ddc)[engineState] == '\0') || ((*(uint *)(ctx + 0x154) & 0xf) != 3)) {
    uVar41 = uVar41 & 0xffffffdf;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  else {
    uVar41 = uVar41 | 0x20;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  if ((((*(uint *)(((unsigned char *)0x000031c0) + engineState) & 1) == 0) || ((*(uint *)(ctx + 0x154) & 0x80) == 0))
     || ((*(short *)(((unsigned char *)0x000031a0) + engineState) == 0x207 &&
         (*(int *)(((unsigned char *)0x000031a4) + engineState) == 0x1e001e00)))) {
    uVar41 = uVar41 & 0xfffeffff;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  else {
    uVar41 = uVar41 | 0x10000;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  if ((((unsigned char *)0x00002dc8)[engineState] == '\0') || ((*(uint *)(ctx + 0x154) & 0x40) == 0)) {
    uVar41 = uVar41 & 0xffffffef;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  else {
    uVar41 = uVar41 | 0x10;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  if (((unsigned char *)0x00002e0a)[engineState] == '\0') {
    *(uint *)(ctx + 0x26b0) = uVar41 & 0xffffffbf;
  }
  else {
    *(uint *)(ctx + 0x26b0) = uVar41 | 0x40;
  }
  if (((((((*(int *)(ctx + 0x18c) == 0) || (iVar33 = FUN_000a4760(ctx), iVar33 == 0)) &&
         ((*(int *)(ctx + 400) == 0 || (iVar33 = FUN_000a4760(ctx), iVar33 == 1)))) &&
        ((*(int *)(ctx + 0x194) == 0 || (iVar33 = FUN_000a4760(ctx), iVar33 == 2)))) &&
       ((*(int *)(ctx + 0x198) == 0 || (iVar33 = FUN_000a4760(ctx), iVar33 == 3)))) &&
      ((((*(int *)(ctx + 0x19c) == 0 || (iVar33 = FUN_000a4760(ctx), iVar33 == 4)) &&
        ((*(int *)(ctx + 0x1a0) == 0 || (iVar33 = FUN_000a4760(ctx), iVar33 == 5)))) &&
       ((*(int *)(ctx + 0x1a4) == 0 || (iVar33 = FUN_000a4760(ctx), iVar33 == 6)))))) &&
     ((*(int *)(ctx + 0x1a8) == 0 || (iVar33 = FUN_000a4760(ctx), iVar33 == 7)))) {
    uVar41 = *(uint *)(ctx + 0x26b0) & 0xfffdffff;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  else {
    uVar41 = *(uint *)(ctx + 0x26b0) | 0x20000;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  if (((unsigned char *)0x00002e33)[engineState] == '\0') {
    uVar41 = uVar41 & 0xfffffdff;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  else {
    uVar41 = uVar41 | 0x200;
    *(uint *)(ctx + 0x26b0) = uVar41;
  }
  if ((((((unsigned char *)0x00002e43)[engineState] == '\0') || (((unsigned char *)0x00002e40)[engineState] == '\0')) ||
      (((unsigned char *)0x00002e41)[engineState] == '\0')) || (((unsigned char *)0x00002e42)[engineState] == '\0')) {
    puVar42 = (undefined *)(uVar41 | 0x400);
    *(undefined **)(ctx + 0x26b0) = puVar42;
  }
  else {
    puVar42 = (undefined *)(uVar41 & 0xfffffbff);
    *(undefined **)(ctx + 0x26b0) = puVar42;
  }
  if (*(short *)(((unsigned char *)0x00002dba) + engineState) == *(short *)(((unsigned char *)0x00002db8) + engineState)) {
    iVar40 = srcX + width;
    iVar38 = srcY + height;
    iVar33 = (int)*rasterPos;
    if (((unsigned char *)0x00002b7c)[ctx] == '\0') {
      fVar1 = rasterPos[1];
    }
    else {
      fVar1 = (float)((double)CONCAT44(0x43300000,*(uint *)(ctx + 0x160) ^ 0x80000000) -
                     DOUBLE_001aa1e0) - (rasterPos[1] + FLOAT_001aa0e8);
    }
    iVar24 = (int)fVar1;
    iVar27 = width + iVar33;
    destEndY = iVar24 + height;
    if (((((iVar33 < srcX) || (iVar40 < iVar33)) && ((iVar27 < srcX || (iVar40 < iVar27)))) ||
        ((iVar24 < srcY || (iVar38 < iVar24)))) &&
       (((iVar33 < srcX || (((iVar40 < iVar33 || (destEndY < srcY)) || (iVar38 < destEndY)))) &&
        (((iVar27 < srcX || (iVar40 < iVar27)) || ((destEndY < srcY || (iVar38 < destEndY))))))))
    goto LAB_000185c0;
    srcDstOverlap = true;
  }
  else {
LAB_000185c0:
    srcDstOverlap = false;
  }
  if (((copyType == 0x1801) && ((*(uint *)(ctx + 0x154) & 0x30000) != 0)) &&
     ((iVar33 = *(int *)(ctx + 0x10), *(int *)(((unsigned char *)0x00002e40U) + iVar33) == 0 &&
      ((((((unsigned char *)0x00002e44)[iVar33] != '\0' && (((uint)puVar42 & 0x10001) == 0)) &&
        (((uint)puVar42 & 0x10) != 0)) && (*(short *)(((unsigned char *)0x00002dc4) + iVar33) == 0x207)))))) {
    iVar33 = FUN_0001a010(ctx,4,iVar34,iVar29,iVar38,iVar40,puVar42);
    if (iVar33 == 0) {
      iVar33 = 3;
      goto LAB_00018700;
    }
    puVar42 = *(undefined **)(ctx + 0x26b0);
  }
  if ((((((uint)puVar42 & 0x20800) != 0) || (copyType - 0x1801U < 2)) ||
      (((*(uint *)(((unsigned char *)0x000030b0) + *(int *)(ctx + 0x10)) & 0x1ff) != 0 ||
       ((*(uint *)(((unsigned char *)0x000030b4) + *(int *)(ctx + 0x10)) & 0xff0000) != 0)))) ||
     (((((uint)puVar42 & 0x10073) == 0 &&
       (puVar42 = PTR_DAT_001e88c8 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24,
       (*(uint *)(puVar42 + 0x14) & 7) < 3)) &&
      ((srcDstOverlap && ((*(uint *)(ctx + 0x154) & 0x20) != 0)))))) {
    iVar33 = 0;
  }
  else {
    iVar33 = 2;
  }
LAB_00018700:
  if ((*(int *)(*(int *)(ctx + 0x18) + 0x1a0) != 0) ||
     (1 < (*(uint *)(ctx + 0x1ae4) >> 6 & 0xffff))) {
    iVar33 = 0;
  }
  if ((srcDstOverlap) && (iVar33 - 2U < 2)) {
    iVar33 = 0;
  }
  iVar24 = FUN_0001a010(ctx,uVar32,iVar34,iVar29,iVar38,iVar40,puVar42);
  if (((iVar24 == 0) &&
      (iVar34 = FUN_0001a010(ctx,*(undefined4 *)(ctx + 0x26a0),iVar34,iVar29,iVar38,iVar40,
                             puVar42), iVar34 == 0)) && (iVar33 != 0)) {
    fVar1 = *rasterPos + FLOAT_001aa10c;
    if (fVar1 < FLOAT_001aa0d4) {
      fVar1 = fVar1 - FLOAT_001aa118;
    }
    uVar41 = (uint)fVar1;
    fVar1 = rasterPos[1] + FLOAT_001aa10c;
    if (fVar1 < FLOAT_001aa0d4) {
      fVar1 = fVar1 - FLOAT_001aa118;
    }
    uVar43 = (uint)fVar1;
    if (((unsigned char *)0x00002b7c)[ctx] != '\0') {
      uVar43 = uVar43 - height;
      srcY = (*(int *)(ctx + 0x160) - srcY) - height;
    }
    if (iVar33 == 1) {
      if (((unsigned char *)0x00002e33)[engineState] == '\0') {
        writeMaskNibble = 0xc;
        writeMaskByte = 0xc0;
      }
      else {
        writeMaskNibble = *(uint *)(ctx + 0x1d38) >> 8 & 0xf;
        writeMaskByte = writeMaskNibble << 4;
      }
      FUN_00020b30(ctx,srcX,srcY,width,height,uVar41,uVar43,uVar32,writeMaskNibble | writeMaskByte);
    }
    else {
      if (iVar33 == 3) {
        iVar34 = ctx + 0x240;
        bufferWidth16 = *(ushort *)(ctx + 0x11e);
        surfaceWidth = (uint)bufferWidth16;
        bufferHeight16 = *(ushort *)(ctx + 0x122);
        surfaceHeight = (uint)bufferHeight16;
        fVar1 = (float)((double)CONCAT44(0x43300000,srcY - uVar43 ^ 0x80000000) - DOUBLE_001aa1e0
                       );
        fVar2 = (float)((double)CONCAT44(0x43300000,uVar41 ^ 0x80000000) - DOUBLE_001aa1e0);
        fVar3 = (float)((double)CONCAT44(0x43300000,uVar43 ^ 0x80000000) - DOUBLE_001aa1e0);
        fVar4 = (float)((double)CONCAT44(0x43300000,uVar41 + width ^ 0x80000000) - DOUBLE_001aa1e0
                       );
        fVar5 = (float)((double)CONCAT44(0x43300000,uVar43 + height ^ 0x80000000) - DOUBLE_001aa1e0
                       );
        fVar6 = (float)((double)CONCAT44(0x43300000,srcX - uVar41 ^ 0x80000000) - DOUBLE_001aa1e0
                       );
        if ((surfaceWidth < 0x1001) && (surfaceHeight < 0x1001)) {
          uVar41 = 0;
          uVar47 = 0;
          uVar48 = 0;
          uVar43 = 0;
          uVar46 = 0;
          iVar29 = 0xc;
          fVar15 = FLOAT_001aa0d4;
          fVar10 = FLOAT_001aa0d4;
          fVar16 = FLOAT_001aa0d4;
          fVar11 = FLOAT_001aa0d4;
        }
        else {
          fVar10 = fVar3 + fVar1;
          fVar11 = fVar5 + fVar1;
          fVar7 = fVar2 + fVar6;
          fVar16 = fVar4 + fVar6;
          fVar15 = fVar11;
          if (fVar11 < fVar10) {
            fVar15 = fVar10;
            fVar10 = fVar11;
          }
          fVar11 = fVar7;
          if (fVar16 < fVar7) {
            fVar11 = fVar16;
            fVar16 = fVar7;
          }
          uVar41 = (int)fVar11 - 1;
          uVar41 = (((int)uVar41 >> 9) + (uint)((int)uVar41 < 0 && (uVar41 & 0x1ff) != 0)) * 0x200;
          uVar43 = 0;
          if ((-1 < (int)uVar41) && (uVar43 = bufferWidth16 & 0xfe00, (int)uVar41 <= (int)(bufferWidth16 & 0xfe00)))
          {
            uVar43 = uVar41 & 0xfe00;
          }
          uVar41 = 0x40;
          if ((0x40 < surfaceHeight) && (uVar41 = bufferHeight16 & 0xffc0, (int)(surfaceHeight - uVar41) < 0x40)) {
            uVar41 = uVar41 - 0x40;
          }
          uVar46 = 0;
          uVar47 = (int)fVar10 - 1;
          uVar47 = (((int)uVar47 >> 6) + (uint)((int)uVar47 < 0 && (uVar47 & 0x3f) != 0)) * 0x40;
          if ((-1 < (int)uVar47) && (uVar46 = uVar41 & 0xffff, (int)uVar47 <= (int)uVar41)) {
            uVar46 = uVar47 & 0xffc0;
          }
          uVar41 = 0x200;
          if (0x1ff < uVar43) {
            uVar41 = uVar43;
          }
          uVar47 = surfaceWidth - 1;
          uVar48 = (((int)uVar47 >> 9) + (uint)((int)uVar47 < 0 && (uVar47 & 0x1ff) != 0)) * 0x200;
          uVar47 = (uint)fVar16;
          if ((FLOAT_001aa0d4 < fVar16) &&
             ((float)((double)CONCAT44(0x43300000,uVar47 ^ 0x80000000) - DOUBLE_001aa1e0) < fVar16))
          {
            uVar47 = uVar47 + 1;
          }
          if ((int)uVar47 <= (int)uVar48) {
            uVar48 = uVar47;
          }
          uVar47 = 1;
          if ((int)uVar41 < (int)uVar48) {
            uVar47 = (int)((uVar48 - uVar41) + 0xbff) / 0xc00 & 0xff;
          }
          uVar41 = 0x40;
          if (0x3f < uVar46) {
            uVar41 = uVar46;
          }
          uVar48 = surfaceHeight - 1;
          uVar36 = (((int)uVar48 >> 6) + (uint)((int)uVar48 < 0 && (uVar48 & 0x3f) != 0)) * 0x40;
          uVar48 = (uint)(int)fVar15;
          if ((FLOAT_001aa0d4 < fVar15) &&
             ((float)((double)CONCAT44(0x43300000,uVar48 ^ 0x80000000) - DOUBLE_001aa1e0) < fVar15))
          {
            uVar48 = uVar48 + 1;
          }
          if ((int)uVar48 <= (int)uVar36) {
            uVar36 = uVar48;
          }
          uVar48 = 1;
          if ((int)uVar41 < (int)uVar36) {
            uVar48 = (int)((uVar36 - uVar41) + 0xf7f) / 0xf80 & 0xff;
          }
          uVar41 = uVar47 * uVar48 & 0xff;
          iVar29 = uVar41 << 4;
        }
        iVar38 = iVar29 + 0x56f;
        *(undefined1 *)(ctx + 0x2a5e) = 1;
        if (*(char *)(ctx + 0x2a42) == '\0') {
          iVar38 = iVar29 + 0x571;
        }
        packetAlloc = (undefined4 *)(**(code **)(ctx + 0x2998))(iVar34,iVar38);
        *(undefined4 **)(ctx + 0x298c) = packetAlloc;
        packetBase = packetAlloc;
        if (*(char *)(ctx + 0x2a42) == '\0') {
          packetBase = packetAlloc + 2;
          *packetAlloc = 0x5c8;
          packetAlloc[1] = 0x10000000;
          *(undefined1 *)(ctx + 0x2a42) = 1;
        }
        puVar42 = PTR_DAT_001e88d0;
        previousHeader = *(uint **)(ctx + 0x1d8);
        *previousHeader = (int)packetBase - (int)previousHeader >> 2 | *previousHeader;
        *(undefined4 **)(ctx + 0x1d8) = packetBase;
        packetBase[2] = uVar32;
        packetBase[1] = 1000;
        *packetBase = 0x31000000;
        packetBase[3] = uVar41;
        packetBase[4] = CONCAT22(bufferHeight16,bufferWidth16);
        _memcpy(packetBase + 1000,puVar42,0x2f4);
        packetCursor = packetBase + 0x4a5;
        packetBase[0x496] = 0xe - ((int)-(*(uint *)(ctx + 0x154) & 0x30000 ^ 0x30000) >> 0x1f);
        fVar7 = FLOAT_001aa12c;
        if (uVar41 == 0) {
          fVar10 = FLOAT_001aa0d4;
          if (surfaceWidth != 0) {
            fVar10 = FLOAT_001aa0e8 /
                     (float)((double)CONCAT44(0x43300000,surfaceWidth ^ 0x80000000) - DOUBLE_001aa1e0);
          }
          fVar11 = FLOAT_001aa0d4;
          if (surfaceHeight != 0) {
            fVar11 = FLOAT_001aa0e8 /
                     (float)((double)CONCAT44(0x43300000,surfaceHeight ^ 0x80000000) - DOUBLE_001aa1e0);
          }
          *packetCursor = 0x31080;
          packetBase[0x4aa] = ((unsigned char *)0x00001087U);
          packetBase[0x4a6] = fVar10 * (fVar2 + fVar6);
          packetBase[0x4a8] = fVar10 * (fVar4 + fVar6);
          packetBase[0x4a7] = fVar11 * (fVar5 + fVar1);
          packetBase[0x4a9] = fVar11 * (fVar3 + fVar1);
          fVar1 = (fVar2 + fVar4) * FLOAT_001aa10c;
          fVar6 = (fVar3 + fVar5) * FLOAT_001aa10c;
          packetBase[0x4ac] = 0xc0033500;
          packetBase[0x4ad] = 0x10031;
          packetBase[0x4ae] = fVar1;
          packetBase[0x4af] = fVar6;
          packetBase[0x4ab] = (int)((fVar4 - fVar2) * fVar7) << 0x10 | (int)((fVar5 - fVar3) * fVar7);
          packetBase[0x4b0] = 0;
          packetCursor = packetBase + 0x4b1;
        }
        else if (uVar48 != 0) {
          uVar36 = surfaceHeight - uVar46;
          uVar49 = 0;
          iVar29 = 0;
          uVar41 = uVar46;
          do {
            if (uVar47 != 0) {
              uVar37 = iVar29 + uVar46;
              uVar39 = surfaceWidth - uVar43;
              iVar38 = 0;
              fVar2 = (float)((double)CONCAT44(0x43300000,uVar37 ^ 0x80000000) - DOUBLE_001aa1e0);
              uVar44 = uVar43;
              uVar52 = uVar47;
              do {
                *packetCursor = uVar44;
                packetCursor[1] = uVar41;
                uVar26 = uVar39;
                if ((int)(uVar44 + 0x1000) <= (int)surfaceWidth) {
                  uVar26 = 0x1000;
                }
                uVar45 = uVar36;
                if ((int)(uVar37 + 0x1000) <= (int)surfaceHeight) {
                  uVar45 = 0x1000;
                }
                packetCursor[2] = uVar26;
                packetCursor[3] = uVar45;
                doubleBias = DOUBLE_001aa1e0;
                fVar3 = fVar11;
                if (iVar38 != 0) {
                  fVar3 = (float)((double)CONCAT44(0x43300000,uVar44 + 0x200 ^ 0x80000000) -
                                 DOUBLE_001aa1e0);
                }
                fVar4 = fVar10;
                if (uVar49 != 0) {
                  fVar4 = (float)((double)CONCAT44(0x43300000,uVar37 + 0x40 ^ 0x80000000) -
                                 DOUBLE_001aa1e0);
                }
                fVar5 = fVar16;
                if (iVar38 != uVar47 - 1) {
                  fVar5 = (float)((double)CONCAT44(0x43300000,uVar44 + 0xe00 ^ 0x80000000) -
                                 DOUBLE_001aa1e0);
                }
                fVar7 = fVar15;
                if (uVar49 != uVar48 - 1) {
                  fVar7 = (float)((double)CONCAT44(0x43300000,uVar37 + 0xfc0 ^ 0x80000000) -
                                 DOUBLE_001aa1e0);
                }
                fVar12 = fVar10;
                if (fVar10 - fVar4 < 0.0) {
                  fVar12 = fVar4;
                }
                fVar13 = fVar15;
                if (fVar7 - fVar15 < 0.0) {
                  fVar13 = fVar7;
                }
                fVar14 = fVar16;
                if (fVar5 - fVar16 < 0.0) {
                  fVar14 = fVar5;
                }
                fVar17 = fVar11;
                if (fVar11 - fVar3 < 0.0) {
                  fVar17 = fVar3;
                }
                if (-(fVar10 - fVar4) < 0.0) {
                  fVar4 = fVar12;
                }
                if (-(fVar7 - fVar15) < 0.0) {
                  fVar7 = fVar13;
                }
                if (-(fVar11 - fVar3) < 0.0) {
                  fVar3 = fVar17;
                }
                if (-(fVar5 - fVar16) < 0.0) {
                  fVar5 = fVar14;
                }
                fVar12 = fVar7 + -fVar1;
                fVar13 = fVar4 + -fVar1;
                fVar18 = fVar3 + -fVar6;
                fVar17 = fVar5 + -fVar6;
                fVar14 = fVar4;
                fVar19 = fVar12;
                if (fVar12 < fVar13) {
                  fVar14 = fVar7;
                  fVar7 = fVar4;
                  fVar19 = fVar13;
                  fVar13 = fVar12;
                }
                fVar4 = fVar5;
                fVar12 = fVar18;
                if (fVar17 < fVar18) {
                  fVar4 = fVar3;
                  fVar3 = fVar5;
                  fVar12 = fVar17;
                  fVar17 = fVar18;
                }
                fVar5 = FLOAT_001aa0d4;
                if (uVar26 != 0) {
                  fVar5 = FLOAT_001aa0e8 /
                          (float)((double)CONCAT44(0x43300000,uVar26 ^ 0x80000000) - DOUBLE_001aa1e0
                                 );
                }
                fVar18 = FLOAT_001aa0d4;
                if (uVar45 != 0) {
                  fVar18 = FLOAT_001aa0e8 /
                           (float)((double)CONCAT44(0x43300000,uVar45 ^ 0x80000000) -
                                  DOUBLE_001aa1e0);
                }
                uVar26 = uVar44 ^ 0x80000000;
                iVar38 = iVar38 + 1;
                uVar44 = uVar44 + 0xc00;
                uVar39 = uVar39 - 0xc00;
                fVar20 = (fVar17 - fVar12) * FLOAT_001aa12c;
                fVar21 = (fVar19 - fVar13) * FLOAT_001aa12c;
                fVar12 = (fVar17 + fVar12) * FLOAT_001aa10c;
                fVar13 = (fVar19 + fVar13) * FLOAT_001aa10c;
                packetCursor[4] = 0x31080;
                packetCursor[6] = (uint)GH_F2U((float)((fVar18 * (fVar7 - fVar2))));
                packetCursor[8] = (uint)GH_F2U((float)((fVar18 * (fVar14 - fVar2))));
                packetCursor[9] = (uint)((unsigned char *)0x00001087U);
                fVar7 = (float)((double)CONCAT44(0x43300000,uVar26) - doubleBias);
                packetCursor[7] = (uint)GH_F2U((float)((fVar5 * (fVar4 - fVar7))));
                packetCursor[5] = (uint)GH_F2U((float)((fVar5 * (fVar3 - fVar7))));
                packetCursor[0xb] = 0xc0033500;
                packetCursor[0xc] = 0x10031;
                packetCursor[0xd] = (uint)GH_F2U((float)(fVar12));
                packetCursor[0xe] = (uint)GH_F2U((float)(fVar13));
                packetCursor[10] = (int)fVar20 << 0x10 | (int)fVar21;
                packetCursor[0xf] = 0;
                packetCursor = packetCursor + 0x10;
                uVar52 = uVar52 - 1;
              } while (uVar52 != 0);
            }
            uVar49 = uVar49 + 1;
            iVar29 = iVar29 + 0xf80;
            uVar36 = uVar36 - 0xf80;
            uVar41 = uVar41 + 0xf80;
          } while (uVar49 != uVar48);
        }
        lastHeader = *(uint **)(ctx + 0x1d8);
        *lastHeader = (int)packetCursor - (int)lastHeader >> 2 | *lastHeader;
        *(uint **)(ctx + 0x1d8) = packetCursor;
        packetCursor[2] = (uint)((unsigned char *)0x00001393U);
        *packetCursor = 0x33000000;
        packetCursor[1] = 2;
        packetCursor[3] = 10;
        packetCursor[4] = (uint)((unsigned char *)0x000013c6U);
        packetCursor[5] = 3;
        packetCursor[6] = 0x5c8;
        packetCursor[7] = 0x20000;
        packetCursor[8] = (uint)((unsigned char *)0x000010eaU);
        sc_edgerule = *(uint *)(ctx + 0x1cfc);
        packetCursor[10] = (uint)((unsigned char *)0x000010faU);
        packetCursor[9] = sc_edgerule;
        sc_screendoor = *(uint *)(ctx + 0x1da0);
        packetCursor[0xc] = 0xc0001000;
        packetCursor[0xe] = 0x11004;
        packetCursor[0xb] = sc_screendoor;
        packetCursor[0xf] = *(uint *)(ctx + 0x1ca8);
        gb_mspos1 = *(uint *)(ctx + 0x1cac);
        packetCursor[0x11] = (uint)((unsigned char *)0x00001008U);
        packetCursor[0x10] = gb_mspos1;
        gb_aa_config = *(uint *)(ctx + 0x1ca0);
        packetCursor[0x13] = (uint)((unsigned char *)0x000010e9U);
        packetCursor[0x12] = gb_aa_config;
        sc_hyperz_en = *(uint *)(ctx + 0x1d20);
        packetCursor[0x15] = (uint)((unsigned char *)0x000013c7U);
        packetCursor[0x14] = sc_hyperz_en;
        packetCursor[0x16] = *(uint *)(ctx + 0x1cf0);
        packetCursor[0x17] = (uint)((unsigned char *)0x000013c1U);
        zb_zstencilcntl = *(uint *)(ctx + 0x1ce4);
        packetCursor[0x19] = 0x850;
        packetCursor[0x18] = zb_zstencilcntl;
        vap_cntl_status = *(uint *)(ctx + 0x1dc0);
        packetCursor[0x1b] = 0x887;
        packetCursor[0x1a] = vap_cntl_status;
        vap_clip_cntl = *(uint *)(ctx + 0x1db4);
        packetCursor[0xbd] = 0x82c;
        packetCursor[0x1c] = vap_clip_cntl;
        vap_vte_cntl = *(uint *)(0x00001dc4 + ctx);
        packetCursor[0x1d] = (uint)((unsigned char *)0x000010aeU);
        packetCursor[0xbe] = vap_vte_cntl;
        su_cull_mode = *(uint *)(ctx + 0x1d70);
        packetCursor[0x1f] = (uint)((unsigned char *)0x00001394U);
        packetCursor[0x1e] = su_cull_mode;
        rb3d_dither_ctl = *(uint *)(ctx + 0x1d30);
        packetCursor[0x21] = (uint)((unsigned char *)0x00001380U);
        packetCursor[0x22] = 0;
        packetCursor[0x23] = (uint)((unsigned char *)0x00001002U);
        packetCursor[0x20] = rb3d_dither_ctl;
        packetCursor[0x24] = *(uint *)(ctx + 0x1d90);
        gb_enable = *(uint *)(ctx + 0x1d90);
        packetCursor[0x25] = 0x824;
        packetCursor[0x24] = gb_enable;
        vap_out_vtx_fmt_0 = *(uint *)(ctx + 0x1ddc);
        packetCursor[0x27] = 0x825;
        packetCursor[0x26] = vap_out_vtx_fmt_0;
        vap_out_vtx_fmt_1 = *(uint *)(ctx + 0x1de0);
        packetCursor[0x29] = 0x82d;
        packetCursor[0x28] = vap_out_vtx_fmt_1;
        packetCursor[0x2a] = *(uint *)(0x000026c8 + ctx + 4);
        packetCursor[0x2b] = 0x854;
        puVar42 = PTR_DAT_001e88c8;
        uVar41 = **(uint **)(ctx + 0x2680);
        packetCursor[0x2d] = 0x878;
        packetCursor[0x2c] = uVar41;
        uVar41 = **(uint **)(ctx + 0x2684);
        packetCursor[0x2f] = (uint)((unsigned char *)0x000013c0U);
        packetCursor[0x2e] = uVar41;
        zb_cntl = *(uint *)(ctx + 0x1ce0);
        packetCursor[0x31] = (uint)((unsigned char *)0x000012f0U);
        packetCursor[0x30] = zb_cntl;
        packetCursor[0x32] = *(uint *)(ctx + 0x1d2c);
        if ((*(uint *)(puVar42 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x18) & 0x8000) == 0)
        {
          packetCursor[0x32] = packetCursor[0x32] & 0xfffffffe;
        }
        puVar42 = PTR_DAT_001e88c8;
        packetCursor[0x33] = (uint)((unsigned char *)0x000012f5U);
        fg_alpha_func = *(uint *)(ctx + 0x1c8c);
        packetCursor[0x34] = fg_alpha_func;
        if ((*(uint *)(puVar42 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x18) & 0x8000) == 0)
        {
          packetCursor[0x34] = fg_alpha_func & 0xfffff7ff;
        }
        packetCursor[0x35] = (uint)((unsigned char *)0x000010a2U);
        ga_poly_mode = *(uint *)(ctx + 0x1d7c);
        packetCursor[0x37] = (uint)((unsigned char *)0x00001381U);
        packetCursor[0x36] = ga_poly_mode;
        rb3d_blendcntl = *(uint *)(ctx + 0x1cc0);
        packetCursor[0x38] = rb3d_blendcntl;
        if ((*(uint *)(puVar42 + (uint)(byte)((unsigned char *)0x00002b7f)[ctx] * 0x24 + 0x18) & 0x4000) == 0)
        {
          packetCursor[0x38] = rb3d_blendcntl & 0xfffffffc;
        }
        packetCursor[0x39] = (uint)((unsigned char *)0x0000109eU);
        uVar41 = *(uint *)(ctx + 0x1d6c);
        packetCursor[0x3b] = (uint)((unsigned char *)0x00001096U);
        packetCursor[0x3a] = uVar41;
        ga_color_control = *(uint *)(ctx + 0x1df8);
        packetCursor[0x3d] = (uint)((unsigned char *)0x00001041U);
        packetCursor[0x3a] = ga_color_control;
        tx_enable = *(uint *)(ctx + 0x29f0);
        packetCursor[0x3f] = (uint)((unsigned char *)0x00001046U);
        packetCursor[0x3e] = tx_enable;
        gb_ps3_enable = *(uint *)(ctx + 0x1dfc);
        packetCursor[0x41] = (uint)((unsigned char *)0x00001094U);
        packetCursor[0x59] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x5b] = 0xc0221000;
        packetCursor[0x7f] = (uint)((unsigned char *)0x00001180U);
        packetCursor[0x42] = 0;
        packetCursor[0x43] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x45] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x40] = gb_ps3_enable;
        packetCursor[0x47] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x49] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x4b] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x4d] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x4f] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x51] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x53] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x55] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x57] = (uint)((unsigned char *)0x00001095U);
        packetCursor[0x80] = 2;
        packetCursor[0x81] = (uint)((unsigned char *)0x00001189U);
        packetCursor[0x83] = (uint)((unsigned char *)0x00001181U);
        packetCursor[0x85] = (uint)((unsigned char *)0x0000118dU);
        packetCursor[0x87] = (uint)((unsigned char *)0x0000118eU);
        packetCursor[0x89] = (uint)((unsigned char *)0x0000118cU);
        packetCursor[0x8b] = (uint)((unsigned char *)0x000011a9U);
        us_out_fmt_0 = *(uint *)(ctx + 0x257c);
        packetCursor[0x8d] = (uint)((unsigned char *)0x000011aaU);
        packetCursor[0x8c] = us_out_fmt_0;
        us_out_fmt_1 = *(uint *)(ctx + 0x2580);
        packetCursor[0x8f] = (uint)((unsigned char *)0x000011abU);
        packetCursor[0x8e] = us_out_fmt_1;
        us_out_fmt_2 = *(uint *)(ctx + 0x2584);
        packetCursor[0x91] = (uint)((unsigned char *)0x000011acU);
        packetCursor[0x90] = us_out_fmt_2;
        us_out_fmt_3 = *(uint *)(ctx + 0x2588);
        packetCursor[0x93] = (uint)((unsigned char *)0x000010c0U);
        packetCursor[0x92] = us_out_fmt_3;
        rs_count = *(uint *)(ctx + 0x216c);
        packetCursor[0x95] = (uint)((unsigned char *)0x000010c1U);
        packetCursor[0x97] = (uint)((unsigned char *)0x000010c8U);
        packetCursor[0x99] = (uint)((unsigned char *)0x0000101dU);
        packetCursor[0x94] = rs_count;
        rs_ip_0 = *(uint *)(ctx + 0x2128);
        packetCursor[0x9b] = (uint)((unsigned char *)0x0000138aU);
        packetCursor[0xa2] = 0;
        packetCursor[0x9c] = 0;
        packetCursor[0x9f] = (uint)((unsigned char *)0x00001040U);
        packetCursor[0x9e] = 0;
        packetCursor[0xa0] = 0;
        packetCursor[0x9d] = (uint)((unsigned char *)0x0000138eU);
        packetCursor[0x9a] = rs_ip_0;
        packetCursor[0xa1] = (uint)((unsigned char *)0x00001150U);
        packetCursor[0xa3] = (uint)((unsigned char *)0x00001100U);
        tx_filter0 = *(uint *)(ctx + 0x1f1c);
        packetCursor[0xa5] = (uint)((unsigned char *)0x00001110U);
        packetCursor[0xa4] = tx_filter0;
        packetCursor[0xa6] = *(uint *)(ctx + 0x1f5c);
        packetCursor[0xa7] = (uint)((unsigned char *)0x00001120U);
        tx_format0 = *(uint *)(ctx + 0x1f9c);
        packetCursor[0xa9] = (uint)((unsigned char *)0x00001130U);
        packetCursor[0xa8] = tx_format0;
        tx_format1 = *(uint *)(ctx + 0x1fdc);
        packetCursor[0xab] = (uint)((unsigned char *)0x00001140U);
        packetCursor[0xaa] = tx_format1;
        tx_format2 = *(uint *)(ctx + 0x201c);
        packetCursor[0xad] = (uint)((unsigned char *)0x000010f4U);
        packetCursor[0xae] = 0xaaaa;
        packetCursor[0xaf] = (uint)((unsigned char *)0x00001383U);
        packetCursor[0xac] = tx_format2;
        rb3d_color_channel_mask = *(uint *)(ctx + 0x1d34);
        packetCursor[0xb1] = (uint)((unsigned char *)0x00001386U);
        packetCursor[0xb0] = rb3d_color_channel_mask;
        rb3d_ropcntl = *(uint *)(ctx + 0x1d38);
        packetCursor[0xb3] = 0x110f8;
        packetCursor[0xb2] = rb3d_ropcntl;
        packetCursor[0xb4] = *(uint *)(ctx + 0x1d98);
        sc_scissor1 = *(uint *)(ctx + 0x1d50);
        packetCursor[0xb6] = (uint)((unsigned char *)0x00001087U);
        packetCursor[0xb5] = sc_scissor1;
        ga_point_size = *(uint *)(ctx + 0x1f0c);
        packetCursor[0xb8] = 0x31080;
        packetCursor[0xb7] = ga_point_size;
        packetCursor[0xb9] = *(uint *)(ctx + 0x1efc);
        packetCursor[0xba] = *(uint *)(ctx + 0x1f04);
        packetCursor[0xbb] = *(uint *)(ctx + 0x1f00);
        packetCursor[0xbc] = *(uint *)(ctx + 0x1f08);
        FUN_0004c100(packetCursor + 2,iVar34);
        packetCursor[0xbf] = (uint)((unsigned char *)0x000013c4U);
        packetCursor[200] = (uint)((unsigned char *)0x000013caU);
        packetCursor[0xc4] = (uint)((unsigned char *)0x000013cdU);
        packetCursor[0xc6] = (uint)((unsigned char *)0x000013ccU);
        packetCursor[0xc1] = 0x113c8;
        *(uint **)(ctx + 0x298c) = packetCursor + 0xca;
        /* dropped 2nd arg, same defect class as gld_startPacket (issue #64). */
        (**(code **)(ctx + 0x299c))(iVar34,packetCursor + 0xca);
        return;
      }
      FUN_00021c70(ctx,srcX,srcY,width,height,uVar41,uVar43,destEndY,uVar32);
    }
  }
  else {
    if (copyType == 0x1801) {
      if ((*(uint *)(ctx + 0x154) & 0x30000) == 0) {
        return;
      }
      if ((*(uint *)(ctx + 0x154) & 0x20000) == 0) {
        iVar34 = width << 1;
        puVar42 = ((unsigned char *)0x00001403U);
        uVar32 = 0x1902;
      }
      else {
        iVar34 = width << 2;
        puVar42 = ((unsigned char *)0x00001405U);
        uVar32 = 0x1902;
      }
    }
    else if (copyType == 0x1802) {
      if ((*(uint *)(ctx + 0x154) & 0x30000) != 0x30000) {
        return;
      }
      puVar42 = ((unsigned char *)0x00001401U);
      uVar32 = 0x1901;
      iVar34 = width;
    }
    else {
      if (copyType != 0x1800) {
        return;
      }
      puVar42 = ((unsigned char *)0x00001401U);
      uVar32 = 0x1908;
      iVar34 = width << 2;
    }
    iVar34 = _malloc(iVar34 * height);
    if (iVar34 != 0) {
      glReadPixels_entry(ctx,srcX,srcY,width,height,uVar32,puVar42,iVar34,2,0);
      ((int (*)())gld_drawPixelsDispatch)(ctx,rasterPos,width,height,uVar32,puVar42,iVar34,1,0);
                    
                    
      (*(code *)PTR_FUN_001e8754)(iVar34);
      return;
    }
  }
  return;
}

/* glDrawPixels_impl @ 0x18a40 (3636 bytes) */
int glDrawPixels_impl(ctx, rasterPos, width, height, format, pixelType, pixels, rawTransfer, transferMode)
  int ctx;
  float *rasterPos;
  uint width;
  uint height;
  int format;
  undefined4 pixelType;
  int pixels;
  int rawTransfer;
  uint transferMode;
{
  uint tileRow;
  uint tileRows;
  uint tileHeight;
  undefined4 stateBytes;
  undefined4 convResult;
  float zoomYScaledB;
  float zoomXScaled;
  float zoomXScaledB;
  int tileX;
  int xDir;
  int tileRowOffset;
  int bytesPerPixel;
  uint windowY;
  uint scaledHeight;
  uint tileWidth;
  uint heightCopy;
  uint widthCopy;
  int engineState;
  bool skipPixelStore;
  bool notStencil;
  float fVar3;
  float rasterXScaled;
  float fVar5;
  float rasterXRounded;
  float zoomYScaled;
  undefined *unpackState;
  uint zoomXFlag;
  int iVar10;
  int iVar11;
  undefined4 typeArg;
  uint scaledWidth;
  int convBuffer;
  undefined4 r4AfterCall;
  undefined4 r4AfterCall2;
  int tileRowStart;
  undefined1 *puVar16;
  undefined1 *puVar17;
  int *piVar18;
  uint pathFlags;
  uint pathFlagsB;
  undefined1 *puVar21;
  char *scratchR9;
  int iVar23;
  uint fullColumns;
  int *piVar25;
  char *scratchR10;
  uint fullRows;
  int formatArg;
  uint heightArg;
  uint tileColumns;
  int convRowBytes;
  uint tileColumn;
  int ctxState;
  float *pfStack0000001c;
  undefined1 auStack_428 [4];
  int srcSkipBytes;
  int local_420;
  int srcRowBytes;
  undefined1 auStack_418 [4];
  undefined1 auStack_414 [4];
  int procPixels;
  int procPitch;
  undefined4 procChannelFormat;
  undefined4 procChannelSize;
  undefined4 procMode;
  uint procFlags;
  undefined4 procMask;
  uint procWidth;
  uint procHeight;
  float local_3ec;
  float local_3e8;
  uint local_3e4;
  uint local_3e0;
  uint local_3dc;
  undefined4 local_3d8;
  uint local_3d4;
  uint local_3d0;
  uint local_3cc;
  undefined4 local_3c8;
  uint local_3c4;
  uint local_3c0;
  uint local_3bc;
  undefined4 local_3b8;
  undefined1 local_3b4;
  float procZoomX;
  float procZoomY;
  uint procZoomFlags;
  longlong fctiwzSlot0;
  longlong fctiwzSlot1;
  longlong fctiwzSlot2;
  longlong fctiwzSlot3;
  longlong fctiwzSlot4;
  longlong fctiwzSlot5;
  longlong fctiwzSlot6;
  longlong fctiwzSlot7;
  longlong fctiwzSlot8;
  longlong fctiwzSlot9;
  longlong fctiwzSlot10;
  longlong fctiwzSlot11;
  undefined4 windowYI2dHiB;
  uint windowYI2dLoB;
  longlong fctiwzSlot12;
  longlong fctiwzSlot13;
  undefined4 windowYI2dHi;
  uint windowYI2dLo;
  longlong fctiwzSlot14;
  longlong fctiwzSlot15;
  longlong fctiwzSlot16;
  longlong fctiwzSlot17;
  longlong fctiwzSlot18;
  undefined4 rasterXTruncI2dHi;
  uint rasterXTruncI2dLo;
  longlong fctiwzSlot19;
  undefined4 rasterYTruncI2dHi;
  uint rasterYTruncI2dLo;
  undefined4 widthI2dHi;
  uint widthI2dLo;
  undefined4 heightI2dHi;
  uint heightI2dLo;
  int yDir;
  uint transferMode8;
  
  *(undefined1 *)(ctx + GLD_inDrawPixels) = 1;
  ctxState = *(int *)(ctx + GLD_engineState);
  transferMode8 = transferMode & 0xff;
  if ((((unsigned char *)0x00002d84)[ctxState] == '\0') ||
     (((((*(int *)(((unsigned char *)0x00002d68) + ctxState) == 0x10000 &&
         (*(int *)(((unsigned char *)0x00002d6c) + ctxState) == 0x10000)) &&
        (*(short *)(((unsigned char *)0x00002d80) + ctxState) != -0x7ff5)) &&
       (((*(short *)(((unsigned char *)0x00002d80) + ctxState) != -0x7ff9 &&
         (*(short *)(((unsigned char *)0x00002d82) + ctxState) != -0x7ff5)) &&
        (*(short *)(((unsigned char *)0x00002d82) + ctxState) != -0x7ff9)))) || (((unsigned char *)0x00002e33)[ctxState] != '\0')))) {
    pathFlags = *(uint *)(ctx + GLD_drawPixelsFlags) & 0xfffffffd;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  else {
    pathFlags = *(uint *)(ctx + GLD_drawPixelsFlags) | 2;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  if (((unsigned char *)0x00002d66)[ctxState] == '\0') {
    pathFlags = pathFlags & 0xfffffffe;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  else {
    pathFlags = pathFlags | 1;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  if ((*(uint *)(((unsigned char *)0x000030b4) + ctxState) & 0xcff1) == 0) {
    pathFlags = pathFlags & 0xfffff7ff;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  else {
    pathFlags = pathFlags | 0x800;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  if ((((unsigned char *)0x00002ddc)[ctxState] == '\0') || ((*(uint *)(ctx + GLD_renderFlags) & 0xf) != 3)) {
    pathFlags = pathFlags & 0xffffffdf;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  else {
    pathFlags = pathFlags | 0x20;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  if ((((*(uint *)(((unsigned char *)0x000031c0) + ctxState) & 1) == 0) || ((*(uint *)(ctx + GLD_renderFlags) & 0x80) == 0))
     || ((*(short *)(((unsigned char *)0x000031a0) + ctxState) == 0x207 &&
         (*(int *)(((unsigned char *)0x000031a4) + ctxState) == 0x1e001e00)))) {
    pathFlags = pathFlags & 0xfffeffff;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  else {
    pathFlags = pathFlags | 0x10000;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  if ((((unsigned char *)0x00002dc8)[ctxState] == '\0') || ((*(uint *)(ctx + GLD_renderFlags) & 0x40) == 0)) {
    pathFlags = pathFlags & 0xffffffef;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  else {
    pathFlags = pathFlags | 0x10;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags;
  }
  if (((unsigned char *)0x00002e0a)[ctxState] == '\0') {
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags & 0xffffffbf;
  }
  else {
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlags | 0x40;
  }
  widthCopy = width;
  heightArg = height;
  formatArg = format;
  typeArg = pixelType;
  pfStack0000001c = rasterPos;
  if (((((((*(int *)(ctx + GLD_unitObject0) == 0) || (iVar11 = FUN_000a4760(ctx), iVar11 == 0)) &&
         ((*(int *)(ctx + GLD_unitObject1) == 0 || (iVar11 = FUN_000a4760(ctx), iVar11 == 1)))) &&
        ((*(int *)(ctx + GLD_unitObject2) == 0 || (iVar11 = FUN_000a4760(ctx), iVar11 == 2)))) &&
       ((*(int *)(ctx + GLD_unitObject3) == 0 || (iVar11 = FUN_000a4760(ctx), iVar11 == 3)))) &&
      (((*(int *)(ctx + GLD_unitObject4) == 0 || (iVar11 = FUN_000a4760(ctx), iVar11 == 4)) &&
       ((*(int *)(ctx + GLD_unitObject5) == 0 || (iVar11 = FUN_000a4760(ctx), iVar11 == 5)))))) &&
     (((*(int *)(ctx + GLD_unitObject6) == 0 || (iVar11 = FUN_000a4760(ctx), iVar11 == 6)) &&
      ((*(int *)(ctx + GLD_unitObject7) == 0 || (iVar11 = FUN_000a4760(ctx), iVar11 == 7)))))) {
    pathFlagsB = *(uint *)(ctx + GLD_drawPixelsFlags) & 0xfffdffff;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlagsB;
  }
  else {
    pathFlagsB = *(uint *)(ctx + GLD_drawPixelsFlags) | 0x20000;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlagsB;
  }
  if (((unsigned char *)0x00002e33)[ctxState] == '\0') {
    pathFlagsB = pathFlagsB & 0xfffffdff;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlagsB;
  }
  else {
    pathFlagsB = pathFlagsB | 0x200;
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlagsB;
  }
  if ((((((unsigned char *)0x00002e43)[ctxState] == '\0') || (((unsigned char *)0x00002e40)[ctxState] == '\0')) ||
      (((unsigned char *)0x00002e41)[ctxState] == '\0')) || (((unsigned char *)0x00002e42)[ctxState] == '\0')) {
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlagsB | 0x400;
  }
  else {
    *(uint *)(ctx + GLD_drawPixelsFlags) = pathFlagsB & 0xfffffbff;
  }
  if (width == 0) {
    return;
  }
  if (height == 0) {
    return;
  }
  ctxState = *(int *)(ctx + GLD_engineState);
  if (((unsigned char *)0x00003190)[ctxState] != '\0') {
    if (*(int *)(((unsigned char *)0x00003188) + ctxState) == 0) {
      return;
    }
    if (*(int *)(((unsigned char *)0x0000318c) + ctxState) == 0) {
      return;
    }
    if (*(int *)(ctx + GLD_renderWidth) <= *(int *)(((unsigned char *)0x00003180) + ctxState)) {
      return;
    }
    if (*(int *)(((unsigned char *)0x00003188) + ctxState) + *(int *)(((unsigned char *)0x00003180) + ctxState) < 1) {
      return;
    }
    if (*(int *)(ctx + GLD_renderHeight) <= *(int *)(((unsigned char *)0x00003184) + ctxState)) {
      return;
    }
    if (*(int *)(((unsigned char *)0x0000318c) + ctxState) + *(int *)(((unsigned char *)0x00003184) + ctxState) < 1) {
      return;
    }
  }
  skipPixelStore = transferMode8 != 0;
  if (((!skipPixelStore) && ((*(uint *)(ctx + GLD_drawPixelsFlags) & 0x30e73) == 0)) &&
     ((1 < format - 0x1901U &&
      (((*(uint *)(((unsigned char *)0x000030b0) + ctxState) & 0x1ff) == 0 &&
       ((*(uint *)(((unsigned char *)0x000030b4) + ctxState) & 0xff0000) == 0)))))) {
    FUN_0001a010(ctx,*(undefined4 *)(ctx + 0x26a0),widthCopy,heightArg,formatArg,typeArg,ctxState);
  }
  local_3e8 = 0.0;
  procFlags = 0;
  procMask = 0x7ffff;
  local_3ec = 0.0;
  unpackState = (undefined *)0x0;
  if (rawTransfer == 0) {
    ctxState = *(int *)(ctx + GLD_engineState);
    unpackState = ((unsigned char *)0x00002e6c) + ctxState;
    procFlags = (uint)(((unsigned char *)0x00002e84)[ctxState] != '\0');
    if (((unsigned char *)0x00002e85)[ctxState] != '\0') {
      procFlags = procFlags | 4;
    }
  }
  piVar18 = &srcRowBytes;
  puVar21 = auStack_428;
  piVar25 = &srcSkipBytes;
  notStencil = format != 0x1901;
  heightCopy = height;
  ((int (*)())gld_computePixelStoreLayout)(ctx,format,pixelType,width,height,piVar18,puVar21,piVar25,unpackState);
  ((int (*)())gldPixelUnitBytes)(format,pixelType);
  puVar16 = auStack_418;
  puVar17 = auStack_414;
  convResult = _glgConvertType(format,pixelType,puVar16,puVar17,heightCopy,piVar18,puVar21,piVar25);
  if (notStencil) {
    if (format == 0x1902) {
      procChannelFormat = 0xd;
      procChannelSize = 7;
    }
    else {
      procChannelFormat = 6;
      procChannelSize = 0x11;
    }
  }
  else {
    procChannelFormat = 0xe;
    procChannelSize = 0;
  }
  local_3ec = *pfStack0000001c;
  procMode = 2;
  rasterXScaled = local_3ec * *(float *)(ctx + GLD_rasterScaleX);
  rasterXRounded = rasterXScaled + 0.5;
  if (0.0 <= rasterXRounded) {
    ctxState = (int)rasterXRounded;
    fctiwzSlot1 = (longlong)ctxState;
  }
  else {
    ctxState = (int)(rasterXRounded - 0.999975);
    fctiwzSlot0 = (longlong)ctxState;
  }
  if (((unsigned char *)GLD_yInverted)[ctx] == '\0') {
    fVar3 = *(float *)(ctx + GLD_rasterScaleY);
    local_3e8 = pfStack0000001c[1];
    fVar5 = local_3e8 * fVar3 + 0.5;
    scratchR10 = (char *)pfStack0000001c;
    if (0.0 <= fVar5) {
      windowY = (uint)(int)fVar5;
      fctiwzSlot5 = (longlong)(int)windowY;
    }
    else {
      windowY = (uint)(int)(fVar5 - 0.999975);
      fctiwzSlot4 = (longlong)(int)windowY;
    }
  }
  else {
    fVar3 = *(float *)(ctx + GLD_rasterScaleY);
    local_3e8 = pfStack0000001c[1];
    fVar5 = local_3e8 * fVar3 - 0.5;
    scratchR10 = "ret_logicalnz ";
    if (0.0 <= fVar5) {
      windowY = (uint)(int)fVar5;
      fctiwzSlot3 = (longlong)(int)windowY;
    }
    else {
      windowY = (uint)(int)(fVar5 + 0.999975);
      fctiwzSlot2 = (longlong)(int)windowY;
    }
  }
  zoomYScaled = fVar3 * *(float *)(((unsigned char *)0x00002e4c) + *(int *)(ctx + GLD_engineState));
  zoomXScaled = *(float *)(ctx + GLD_rasterScaleX) * *(float *)(((unsigned char *)0x00002e48) + *(int *)(ctx + GLD_engineState));
  if (notStencil) {
    bytesPerPixel = 4;
  }
  else {
    bytesPerPixel = 1;
  }
  scratchR9 = "ret_logicalnz ";
  if ((zoomXScaled == 1.0) && (zoomYScaled == 1.0)) {
    convRowBytes = bytesPerPixel * width;
    local_3e8 = 0.0;
    local_3ec = 0.0;
    convBuffer = height * convRowBytes;
    xDir = 1;
    yDir = 1;
    scaledWidth = width;
    scaledHeight = height;
    goto LAB_000194f4;
  }
  scratchR10 = "ret_logicalnz ";
  fVar3 = fVar3 * local_3e8;
  if (zoomXScaled < 0.0) {
    rasterXScaled = rasterXScaled - 0.5;
    if (0.0 <= rasterXScaled) {
      ctxState = (int)rasterXScaled;
      fctiwzSlot9 = (longlong)ctxState;
      xDir = -1;
    }
    else {
      xDir = -1;
      ctxState = (int)(rasterXScaled + 0.999975);
      fctiwzSlot8 = (longlong)ctxState;
    }
  }
  else if (0.0 <= rasterXRounded) {
    ctxState = (int)rasterXRounded;
    fctiwzSlot7 = (longlong)ctxState;
    xDir = 1;
  }
  else {
    xDir = 1;
    ctxState = (int)(rasterXRounded + 0.999975);
    fctiwzSlot6 = (longlong)ctxState;
  }
  if (((unsigned char *)GLD_yInverted)[ctx] == '\0') {
    scratchR9 = "ret_logicalnz ";
    if (zoomYScaled < 0.0) {
      fVar3 = fVar3 - 0.5;
      if (0.0 <= fVar3) {
        windowY = (uint)(int)fVar3;
        fctiwzSlot17 = (longlong)(int)windowY;
        scratchR10 = (char *)((int)((unsigned char *)0x0) + 1);
        xDir = -1;
        yDir = 1;
      }
      else {
        scratchR9 = (char *)0x1;
        xDir = -1;
        yDir = 1;
        windowY = (uint)(int)(fVar3 + 0.999975);
        fctiwzSlot16 = (longlong)(int)windowY;
      }
    }
    else {
      scratchR10 = "ret_logicalnz ";
      fVar3 = fVar3 + 0.5;
      if (0.0 <= fVar3) {
        windowY = (uint)(int)fVar3;
        fctiwzSlot15 = (longlong)(int)windowY;
        yDir = 1;
      }
      else {
        yDir = 1;
        windowY = (uint)(int)(fVar3 + 0.999975);
        fctiwzSlot14 = (longlong)(int)windowY;
      }
    }
  }
  else if (zoomYScaled < 0.0) {
    scratchR9 = "ret_logicalnz ";
    fVar3 = fVar3 + 0.5;
    if (0.0 <= fVar3) {
      windowY = (uint)(int)fVar3;
      fctiwzSlot13 = (longlong)(int)windowY;
    }
    else {
      windowY = (uint)(int)(fVar3 + 0.999975);
      fctiwzSlot12 = (longlong)(int)windowY;
    }
    windowYI2dLo = windowY ^ 0x80000000;
    scratchR10 = (char *)0xffffffff;
    windowYI2dHi = 0x43300000;
    yDir = -1;
    if (fVar3 - (float)((double)CONCAT44(0x43300000,windowYI2dLo) - 4503601774854144.0) == 0.0)
    goto LAB_0001931c;
  }
  else {
    scratchR9 = "ret_logicalnz ";
    fVar3 = fVar3 - 0.5;
    if (0.0 <= fVar3) {
      windowY = (uint)(int)fVar3;
      fctiwzSlot11 = (longlong)(int)windowY;
    }
    else {
      windowY = (uint)(int)(fVar3 + 0.999975);
      fctiwzSlot10 = (longlong)(int)windowY;
    }
    windowYI2dLoB = windowY ^ 0x80000000;
    scratchR10 = "ret_logicalnz ";
    windowYI2dHiB = 0x43300000;
    yDir = 1;
    if (((float)((double)CONCAT44(0x43300000,windowYI2dLoB) - 4503601774854144.0) - fVar3) + 1.0 == 1.0)
    {
LAB_0001931c:
      scratchR9 = "ret_logicalnz ";
      windowY = windowY - 1;
    }
  }
  fctiwzSlot18 = (longlong)(int)local_3ec;
  fctiwzSlot19 = (longlong)(int)local_3e8;
  widthI2dLo = width ^ 0x80000000;
  rasterXTruncI2dHi = 0x43300000;
  widthI2dHi = 0x43300000;
  rasterYTruncI2dHi = 0x43300000;
  rasterXTruncI2dLo = (int)local_3ec ^ 0x80000000;
  rasterYTruncI2dLo = (int)local_3e8 ^ 0x80000000;
  local_3ec = local_3ec - (float)((double)CONCAT44(0x43300000,rasterXTruncI2dLo) - 4503601774854144.0);
  local_3e8 = local_3e8 - (float)((double)CONCAT44(0x43300000,rasterYTruncI2dLo) - 4503601774854144.0);
  scaledWidth = _glgPixelCenters(convResult,r4AfterCall,puVar16,puVar17,heightCopy,piVar18,scratchR9,scratchR10);
  heightI2dLo = height ^ 0x80000000;
  heightI2dHi = 0x43300000;
  convRowBytes = bytesPerPixel * scaledWidth;
  scaledHeight = _glgPixelCenters(scaledWidth,r4AfterCall2,puVar16,puVar17,heightCopy,piVar18,scratchR9,scratchR10);
  convBuffer = scaledHeight * convRowBytes;
LAB_000194f4:
  convBuffer = _malloc(convBuffer);
  if (convBuffer != 0) {
    local_3b4 = 1;
    procHeight = height;
    procWidth = width;
    local_420 = pixels + srcSkipBytes;
    procPixels = convBuffer;
    procPitch = convRowBytes;
    if (skipPixelStore) {
      _glgProcessPixels(0,&local_420,puVar16,puVar17,heightCopy,piVar18,scratchR9,scratchR10);
    }
    else {
      engineState = *(int *)(ctx + GLD_engineState);
      if (((((*(uint *)(((unsigned char *)0x000030b0) + engineState) & 0x1ff) != 0) ||
           ((*(uint *)(((unsigned char *)0x000030b4) + engineState) & 0xff0000) != 0)) && (notStencil)) && (format != 0x1902)
         ) {
        if ((*(uint *)(((unsigned char *)0x000030b0) + engineState) & 2) == 0) {
          if (((*(uint *)(((unsigned char *)0x000030b0) + engineState) & 4) != 0) &&
             (*(short *)(((unsigned char *)0x00002fe8) + engineState) == -0x7fea)) {
            scaledHeight = (scaledHeight - *(int *)(((unsigned char *)0x00002ff4) + engineState)) + 1;
            scaledWidth = (scaledWidth - *(int *)(((unsigned char *)0x00002ff0) + engineState)) + 1;
          }
        }
        else if (*(short *)(((unsigned char *)0x00002fa8) + engineState) == -0x7fea) {
          scaledHeight = (scaledHeight - *(int *)(((unsigned char *)0x00002fb4) + engineState)) + 1;
          scaledWidth = (scaledWidth - *(int *)(((unsigned char *)0x00002fb0) + engineState)) + 1;
        }
        scratchR10 = *(char **)(ctx + GLD_engineObjects);
        iVar23 = *(int *)((int)*(float *)((int)scratchR10 + 0x140) + 0x30);
        local_3e4 = (uint)*(ushort *)(iVar23 + 0x98);
        local_3e0 = (uint)*(ushort *)(iVar23 + 0x9a);
        local_3dc = (uint)*(ushort *)(iVar23 + 0x8c);
        local_3d8 = *(undefined4 *)(iVar23 + 0x9c);
        iVar23 = *(int *)((int)*(float *)((int)scratchR10 + 0x148) + 0x30);
        local_3d4 = (uint)*(ushort *)(iVar23 + 0x98);
        local_3d0 = (uint)*(ushort *)(iVar23 + 0x9a);
        local_3cc = (uint)*(ushort *)(iVar23 + 0x8c);
        local_3c8 = *(undefined4 *)(iVar23 + 0x9c);
        iVar23 = *(int *)((int)*(float *)((int)scratchR10 + 0x144) + 0x30);
        local_3c4 = (uint)*(ushort *)(iVar23 + 0x98);
        local_3c0 = (uint)*(ushort *)(iVar23 + 0x9a);
        local_3bc = (uint)*(ushort *)(iVar23 + 0x8c);
        local_3b8 = *(undefined4 *)(iVar23 + 0x9c);
      }
      stateBytes = 0x274;
      zoomXScaledB = *(float *)(((unsigned char *)0x00002e48) + engineState) * *(float *)(ctx + GLD_rasterScaleX);
      zoomYScaledB = *(float *)(((unsigned char *)0x00002e4c) + engineState) * *(float *)(ctx + GLD_rasterScaleY);
      _memcpy(&procZoomX,((unsigned char *)0x00002e48) + engineState,0x274);
      zoomXFlag = 0x4000;
      if (zoomXScaledB == 1.0) {
        zoomXFlag = 0;
      }
      procZoomFlags = (uint)(zoomYScaledB != 1.0) << 0xf | zoomXFlag | procZoomFlags & 0xffff3fff;
      procZoomX = zoomXScaledB;
      procZoomY = zoomYScaledB;
      _glgProcessPixels(&procZoomX,&local_420,stateBytes,puVar17,heightCopy,piVar18,"ret_logicalnz ",scratchR10
                       );
    }
    srcRowBytes = convRowBytes;
    if (((unsigned char *)GLD_yInverted)[ctx] != '\0') {
      srcRowBytes = -convRowBytes;
    }
    tileWidth = scaledWidth;
    if (0x7fe < scaledWidth) {
      tileWidth = 0x7fe;
    }
    tileHeight = 0x7fe / tileWidth;
    if (scaledHeight < 0x7fe / tileWidth) {
      tileHeight = scaledHeight;
    }
    fullColumns = scaledWidth / tileWidth;
    fullRows = scaledHeight / tileHeight;
    scaledWidth = scaledWidth - fullColumns * tileWidth;
    scaledHeight = scaledHeight - fullRows * tileHeight;
    tileColumns = fullColumns + 1;
    if (scaledWidth == 0) {
      scaledWidth = tileWidth;
      tileColumns = fullColumns;
    }
    tileRows = fullRows + 1;
    if (scaledHeight == 0) {
      scaledHeight = tileHeight;
      tileRows = fullRows;
    }
    if (tileRows != 0) {
      tileRow = 0;
      do {
        if (tileColumns != 0) {
          tileRowStart = tileHeight * tileRow;
          tileColumn = 0;
          tileRowOffset = yDir * tileRowStart;
          do {
            procHeight = tileHeight;
            if (tileRow == tileRows - 1) {
              procHeight = scaledHeight;
            }
            procWidth = scaledWidth;
            if (tileColumn != tileColumns - 1) {
              procWidth = tileWidth;
            }
            tileX = tileColumn * tileWidth;
            if (((unsigned char *)GLD_yInverted)[ctx] == '\0') {
              local_420 = tileRowStart * srcRowBytes + bytesPerPixel * tileX;
              iVar10 = tileRowOffset;
            }
            else {
              iVar10 = tileRowStart + procHeight + -1;
              local_420 = bytesPerPixel * tileX - srcRowBytes * iVar10;
              iVar10 = -(yDir * iVar10);
            }
            local_420 = local_420 + convBuffer;
            tileColumn = tileColumn + 1;
            FUN_00029c00(ctx,local_420,procWidth,procHeight,srcRowBytes,bytesPerPixel,
                         ctxState + xDir * tileX,windowY + iVar10,pfStack0000001c,format,transferMode8);
          } while (tileColumns != tileColumn);
        }
        tileRow = tileRow + 1;
      } while (tileRows != tileRow);
    }
    _free(convBuffer);
  }
  return;
}

/* gld_drawPixelsAtRasterPos @ 0x198b0 (228 bytes) */
int gld_drawPixelsAtRasterPos(ctx, rasterX, rasterY, imageWidth, imageHeight, pixelType, pixels)
  int ctx;
  uint rasterX;
  uint rasterY;
  undefined4 imageWidth;
  undefined4 imageHeight;
  undefined4 pixelType;
  undefined4 pixels;
{
  uint rasterYBits;
  float rasterPosX;
  float rasterPosY;
  undefined4 rasterPosZ;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 yHiFlipped;
  uint yBitsFlipped;
  undefined4 yHiDirect;
  uint yBitsDirect;
  
  i2dLo1 = rasterX ^ 0x80000000;
  i2dHi1 = 0x43300000;
  rasterPosX = (float)((double)CONCAT44(0x43300000,i2dLo1) - DOUBLE_001aa1e0);
  if (((unsigned char *)0x00002b7c)[ctx] == '\0') {
    yBitsDirect = rasterY ^ 0x80000000;
    yHiDirect = 0x43300000;
    rasterYBits = yBitsDirect;
  }
  else {
    yHiFlipped = 0x43300000;
    yBitsFlipped = *(int *)(ctx + 0x160) - rasterY ^ 0x80000000;
    rasterYBits = yBitsFlipped;
  }
  rasterPosY = (float)((double)CONCAT44(0x43300000,rasterYBits) - DOUBLE_001aa1e0);
  rasterPosZ = 0;
  ((int (*)())glDrawPixels_impl)(ctx,&rasterPosX,imageWidth,imageHeight,0x80e1,pixelType,pixels,1,1);
  return;
}

/* gld_drawPixelsDispatch @ 0x199a0 (68 bytes) */
int gld_drawPixelsDispatch(ctx, rasterPos, width, height, param_5, param_6, param_7, param_8, param_9)
  undefined4 ctx;
  undefined4 rasterPos;
  undefined4 width;
  undefined4 height;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  int param_9;
{
  undefined4 uVar1;
  
  if (param_9 == 0) {
    ((int (*)())glDrawPixels_impl)(ctx,rasterPos,width,height,param_5,param_6,param_7,param_8,0);
    uVar1 = 1;
  }
  else {
    uVar1 = gld_drawPixelsFromClientSurface(ctx,rasterPos,width,height,param_5,param_6,param_7,param_8,param_9);
  }
  return uVar1;
}

/* FUN_000199f0 @ 0x199f0 (212 bytes) */
int FUN_000199f0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int gld_bufferEnumToIndexResult;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    gld_bufferEnumToIndexResult = ((int (*)())gld_bufferEnumToIndex)((uint)*(ushort *)(((unsigned char *)0x00002dba) + *(int *)(param_1 + 0x10)),
                         *(undefined4 *)(param_1 + 0x154));
    uVar1 = *(uint *)(param_1 + 0x154);
    if (((((uVar1 & 0x20) == 0) && (((uVar1 & 0x10) != 0 || ((uVar1 & 0x400) == 0)))) ||
        ((gld_bufferEnumToIndexResult != 0 && ((gld_bufferEnumToIndexResult != 1 || ((uVar1 & 0x400) != 0)))))) ||
       (((uVar1 & 0x70000000) != 0 ||
        (((uVar3 = 6, param_2 < 6 && (uVar3 = 4, param_2 < 4)) && (uVar3 = 2, param_2 < 2)))))) {
      uVar3 = 1;
    }
    *(undefined4 *)(param_1 + 0x2a50) = uVar3;
    *(undefined1 *)(param_1 + 0x2a5d) = 1;
    *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x2a5c) = 1;
  }
  return;
}

/* FUN_00019ad0 @ 0x19ad0 (360 bytes) */
int FUN_00019ad0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int gld_bufferEnumToIndexResult;
  
  if (param_1 == 0) {
    return;
  }
  gld_bufferEnumToIndexResult = ((int (*)())gld_bufferEnumToIndex)((uint)*(ushort *)(((unsigned char *)0x00002dba) + *(int *)(param_1 + 0x10)),
                       *(undefined4 *)(param_1 + 0x154));
  uVar1 = *(uint *)(param_1 + 0x154);
  if (((((uVar1 & 0x20) == 0) && (((uVar1 & 0x10) != 0 || ((uVar1 & 0x400) == 0)))) ||
      ((gld_bufferEnumToIndexResult != 0 && ((gld_bufferEnumToIndexResult != 1 || ((uVar1 & 0x400) != 0)))))) || ((uVar1 & 0x70000000) != 0)) {
LAB_00019b60:
    *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x2a5d) = 1;
    *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x2a5c) = 1;
  }
  else {
    if (param_2 < 4) {
      if (param_2 < 2) goto LAB_00019b60;
      *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
      *(undefined1 *)(param_1 + 0x2a5c) = 1;
      if (0x1000 < *(int *)(param_1 + 0x160) << 1) {
        *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5d) = 1;
        goto LAB_00019be0;
      }
    }
    else {
      if (*(int *)(param_1 + 0x15c) << 1 < 0x1001) {
        *(undefined4 *)(param_1 + 0x2a54) = 0x40000000;
        *(undefined1 *)(param_1 + 0x2a5c) = 2;
      }
      else {
        *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5c) = 1;
      }
      if (0x1000 < *(int *)(param_1 + 0x160) << 1) {
        *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5d) = 1;
        goto LAB_00019be0;
      }
    }
    *(undefined4 *)(param_1 + 0x2a58) = 0x40000000;
    *(undefined1 *)(param_1 + 0x2a5d) = 2;
  }
LAB_00019be0:
  *(undefined4 *)(param_1 + 0x2a50) = 1;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl glBitmap_impl");
asm(".set glBitmap_impl, _glBitmap_impl");
asm(".globl glCopyPixels_impl");
asm(".set glCopyPixels_impl, _glCopyPixels_impl");
asm(".globl gld_drawPixelsDispatch");
asm(".set gld_drawPixelsDispatch, _gld_drawPixelsDispatch");
