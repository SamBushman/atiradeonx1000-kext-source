#include "decls.h"

/* FUN_0006c7c0 @ 0x6c7c0 (1308 bytes) */
int FUN_0006c7c0(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint tokenIndex;
  int dstMask2;
  uint srcSelect1;
  undefined4 newStorage;
  uint srcNegate3;
  uint srcNegate2;
  uint srcNegate1;
  int dstMask1;
  uint srcSelect3;
  uint srcSelectX;
  uint srcHeader;
  uint dstHeader;
  uint dstMaskWord;
  int iVar14;
  uint srcSwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  srcSwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar14 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_0006c8a0:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar14 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar14 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_0006c8a0;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar14 = dstMask[3];
      goto LAB_0006c8a0;
    }
    if (dstMask[3] == 0) {
      iVar14 = 0;
      goto LAB_0006c8a0;
    }
  }
  srcHeader = (srcFile & 0x3f) << 0x10 | srcIndex & 0xffff;
  if (*srcNegate == 0) {
    srcNegate1 = srcNegate[1];
    if (srcNegate1 == 0) {
      srcNegate2 = srcNegate[2];
      if (srcNegate2 == 0) {
        srcNegate3 = srcNegate[3];
        if (srcNegate3 == 0) {
          srcSelectX = *srcSelect;
          if (srcSelectX == 0) {
            srcSelect1 = srcSelect[1];
            if (srcSelect1 == 1) {
              tokenIndex = srcSelect[2];
              if (tokenIndex == 2) {
                srcSelect3 = srcSelect[3];
                if (srcSelect3 == 3) goto LAB_0006ca14;
              }
              else {
                srcSelect3 = srcSelect[3];
              }
            }
            else {
              srcSelect3 = srcSelect[3];
              tokenIndex = srcSelect[2];
            }
          }
          else {
            srcSelect3 = srcSelect[3];
            srcSelect1 = srcSelect[1];
            tokenIndex = srcSelect[2];
          }
        }
        else {
          srcSelect3 = srcSelect[3];
          srcSelectX = *srcSelect;
          srcSelect1 = srcSelect[1];
          tokenIndex = srcSelect[2];
        }
      }
      else {
        srcNegate3 = srcNegate[3];
        srcSelect3 = srcSelect[3];
        srcSelectX = *srcSelect;
        srcSelect1 = srcSelect[1];
        tokenIndex = srcSelect[2];
      }
    }
    else {
      srcNegate3 = srcNegate[3];
      srcSelect3 = srcSelect[3];
      srcNegate2 = srcNegate[2];
      srcSelectX = *srcSelect;
      srcSelect1 = srcSelect[1];
      tokenIndex = srcSelect[2];
    }
  }
  else {
    srcNegate3 = srcNegate[3];
    srcSelect3 = srcSelect[3];
    srcNegate1 = srcNegate[1];
    srcNegate2 = srcNegate[2];
    srcSelectX = *srcSelect;
    srcSelect1 = srcSelect[1];
    tokenIndex = srcSelect[2];
  }
  srcHeader = srcHeader | 0x400000;
  srcSwizzleWord = (srcNegate3 & 1) << 0xf |
           (srcSelect3 & 7) << 0xc |
           (srcNegate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 | (srcNegate1 & 1) << 7 | (srcSelect1 & 7) << 4 | (*srcNegate & 1) << 3 | srcSelectX & 7
  ;
LAB_0006ca14:
  tokenIndex = *tokenCount;
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x51;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar14 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = srcHeader;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((srcHeader & 0x400000) != 0) {
    iVar14 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = srcSwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* FUN_0006cd00 @ 0x6cd00 (1308 bytes) */
int FUN_0006cd00(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint tokenIndex;
  int dstMask2;
  uint srcSelect1;
  undefined4 newStorage;
  uint srcNegate3;
  uint srcNegate2;
  uint srcNegate1;
  int dstMask1;
  uint srcSelect3;
  uint srcSelectX;
  uint srcHeader;
  uint dstHeader;
  uint dstMaskWord;
  int iVar14;
  uint srcSwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  srcSwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar14 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_0006cde0:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar14 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar14 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_0006cde0;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar14 = dstMask[3];
      goto LAB_0006cde0;
    }
    if (dstMask[3] == 0) {
      iVar14 = 0;
      goto LAB_0006cde0;
    }
  }
  srcHeader = (srcFile & 0x3f) << 0x10 | srcIndex & 0xffff;
  if (*srcNegate == 0) {
    srcNegate1 = srcNegate[1];
    if (srcNegate1 == 0) {
      srcNegate2 = srcNegate[2];
      if (srcNegate2 == 0) {
        srcNegate3 = srcNegate[3];
        if (srcNegate3 == 0) {
          srcSelectX = *srcSelect;
          if (srcSelectX == 0) {
            srcSelect1 = srcSelect[1];
            if (srcSelect1 == 1) {
              tokenIndex = srcSelect[2];
              if (tokenIndex == 2) {
                srcSelect3 = srcSelect[3];
                if (srcSelect3 == 3) goto LAB_0006cf54;
              }
              else {
                srcSelect3 = srcSelect[3];
              }
            }
            else {
              srcSelect3 = srcSelect[3];
              tokenIndex = srcSelect[2];
            }
          }
          else {
            srcSelect3 = srcSelect[3];
            srcSelect1 = srcSelect[1];
            tokenIndex = srcSelect[2];
          }
        }
        else {
          srcSelect3 = srcSelect[3];
          srcSelectX = *srcSelect;
          srcSelect1 = srcSelect[1];
          tokenIndex = srcSelect[2];
        }
      }
      else {
        srcNegate3 = srcNegate[3];
        srcSelect3 = srcSelect[3];
        srcSelectX = *srcSelect;
        srcSelect1 = srcSelect[1];
        tokenIndex = srcSelect[2];
      }
    }
    else {
      srcNegate3 = srcNegate[3];
      srcSelect3 = srcSelect[3];
      srcNegate2 = srcNegate[2];
      srcSelectX = *srcSelect;
      srcSelect1 = srcSelect[1];
      tokenIndex = srcSelect[2];
    }
  }
  else {
    srcNegate3 = srcNegate[3];
    srcSelect3 = srcSelect[3];
    srcNegate1 = srcNegate[1];
    srcNegate2 = srcNegate[2];
    srcSelectX = *srcSelect;
    srcSelect1 = srcSelect[1];
    tokenIndex = srcSelect[2];
  }
  srcHeader = srcHeader | 0x400000;
  srcSwizzleWord = (srcNegate3 & 1) << 0xf |
           (srcSelect3 & 7) << 0xc |
           (srcNegate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 | (srcNegate1 & 1) << 7 | (srcSelect1 & 7) << 4 | (*srcNegate & 1) << 3 | srcSelectX & 7
  ;
LAB_0006cf54:
  tokenIndex = *tokenCount;
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x55;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar14 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = srcHeader;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((srcHeader & 0x400000) != 0) {
    iVar14 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = srcSwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* FUN_0006d240 @ 0x6d240 (1308 bytes) */
int FUN_0006d240(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint tokenIndex;
  int dstMask2;
  uint srcSelect1;
  undefined4 newStorage;
  uint srcNegate3;
  uint srcNegate2;
  uint srcNegate1;
  int dstMask1;
  uint srcSelect3;
  uint srcSelectX;
  uint srcHeader;
  uint dstHeader;
  uint dstMaskWord;
  int iVar14;
  uint srcSwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  srcSwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar14 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_0006d320:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar14 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar14 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_0006d320;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar14 = dstMask[3];
      goto LAB_0006d320;
    }
    if (dstMask[3] == 0) {
      iVar14 = 0;
      goto LAB_0006d320;
    }
  }
  srcHeader = (srcFile & 0x3f) << 0x10 | srcIndex & 0xffff;
  if (*srcNegate == 0) {
    srcNegate1 = srcNegate[1];
    if (srcNegate1 == 0) {
      srcNegate2 = srcNegate[2];
      if (srcNegate2 == 0) {
        srcNegate3 = srcNegate[3];
        if (srcNegate3 == 0) {
          srcSelectX = *srcSelect;
          if (srcSelectX == 0) {
            srcSelect1 = srcSelect[1];
            if (srcSelect1 == 1) {
              tokenIndex = srcSelect[2];
              if (tokenIndex == 2) {
                srcSelect3 = srcSelect[3];
                if (srcSelect3 == 3) goto LAB_0006d494;
              }
              else {
                srcSelect3 = srcSelect[3];
              }
            }
            else {
              srcSelect3 = srcSelect[3];
              tokenIndex = srcSelect[2];
            }
          }
          else {
            srcSelect3 = srcSelect[3];
            srcSelect1 = srcSelect[1];
            tokenIndex = srcSelect[2];
          }
        }
        else {
          srcSelect3 = srcSelect[3];
          srcSelectX = *srcSelect;
          srcSelect1 = srcSelect[1];
          tokenIndex = srcSelect[2];
        }
      }
      else {
        srcNegate3 = srcNegate[3];
        srcSelect3 = srcSelect[3];
        srcSelectX = *srcSelect;
        srcSelect1 = srcSelect[1];
        tokenIndex = srcSelect[2];
      }
    }
    else {
      srcNegate3 = srcNegate[3];
      srcSelect3 = srcSelect[3];
      srcNegate2 = srcNegate[2];
      srcSelectX = *srcSelect;
      srcSelect1 = srcSelect[1];
      tokenIndex = srcSelect[2];
    }
  }
  else {
    srcNegate3 = srcNegate[3];
    srcSelect3 = srcSelect[3];
    srcNegate1 = srcNegate[1];
    srcNegate2 = srcNegate[2];
    srcSelectX = *srcSelect;
    srcSelect1 = srcSelect[1];
    tokenIndex = srcSelect[2];
  }
  srcHeader = srcHeader | 0x400000;
  srcSwizzleWord = (srcNegate3 & 1) << 0xf |
           (srcSelect3 & 7) << 0xc |
           (srcNegate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 | (srcNegate1 & 1) << 7 | (srcSelect1 & 7) << 4 | (*srcNegate & 1) << 3 | srcSelectX & 7
  ;
LAB_0006d494:
  tokenIndex = *tokenCount;
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x2d;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar14 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = srcHeader;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((srcHeader & 0x400000) != 0) {
    iVar14 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = srcSwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* FUN_0006d780 @ 0x6d780 (1308 bytes) */
int FUN_0006d780(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint srcFile;
  uint srcIndex;
  uint *srcSelect;
  uint *srcNegate;
{
  uint tokenIndex;
  int dstMask2;
  uint srcSelect1;
  undefined4 newStorage;
  uint srcNegate3;
  uint srcNegate2;
  uint srcNegate1;
  int dstMask1;
  uint srcSelect3;
  uint srcSelectX;
  uint srcHeader;
  uint dstHeader;
  uint dstMaskWord;
  int iVar14;
  uint srcSwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  srcSwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar14 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_0006d860:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar14 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar14 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_0006d860;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar14 = dstMask[3];
      goto LAB_0006d860;
    }
    if (dstMask[3] == 0) {
      iVar14 = 0;
      goto LAB_0006d860;
    }
  }
  srcHeader = (srcFile & 0x3f) << 0x10 | srcIndex & 0xffff;
  if (*srcNegate == 0) {
    srcNegate1 = srcNegate[1];
    if (srcNegate1 == 0) {
      srcNegate2 = srcNegate[2];
      if (srcNegate2 == 0) {
        srcNegate3 = srcNegate[3];
        if (srcNegate3 == 0) {
          srcSelectX = *srcSelect;
          if (srcSelectX == 0) {
            srcSelect1 = srcSelect[1];
            if (srcSelect1 == 1) {
              tokenIndex = srcSelect[2];
              if (tokenIndex == 2) {
                srcSelect3 = srcSelect[3];
                if (srcSelect3 == 3) goto LAB_0006d9d4;
              }
              else {
                srcSelect3 = srcSelect[3];
              }
            }
            else {
              srcSelect3 = srcSelect[3];
              tokenIndex = srcSelect[2];
            }
          }
          else {
            srcSelect3 = srcSelect[3];
            srcSelect1 = srcSelect[1];
            tokenIndex = srcSelect[2];
          }
        }
        else {
          srcSelect3 = srcSelect[3];
          srcSelectX = *srcSelect;
          srcSelect1 = srcSelect[1];
          tokenIndex = srcSelect[2];
        }
      }
      else {
        srcNegate3 = srcNegate[3];
        srcSelect3 = srcSelect[3];
        srcSelectX = *srcSelect;
        srcSelect1 = srcSelect[1];
        tokenIndex = srcSelect[2];
      }
    }
    else {
      srcNegate3 = srcNegate[3];
      srcSelect3 = srcSelect[3];
      srcNegate2 = srcNegate[2];
      srcSelectX = *srcSelect;
      srcSelect1 = srcSelect[1];
      tokenIndex = srcSelect[2];
    }
  }
  else {
    srcNegate3 = srcNegate[3];
    srcSelect3 = srcSelect[3];
    srcNegate1 = srcNegate[1];
    srcNegate2 = srcNegate[2];
    srcSelectX = *srcSelect;
    srcSelect1 = srcSelect[1];
    tokenIndex = srcSelect[2];
  }
  srcHeader = srcHeader | 0x400000;
  srcSwizzleWord = (srcNegate3 & 1) << 0xf |
           (srcSelect3 & 7) << 0xc |
           (srcNegate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 | (srcNegate1 & 1) << 7 | (srcSelect1 & 7) << 4 | (*srcNegate & 1) << 3 | srcSelectX & 7
  ;
LAB_0006d9d4:
  tokenIndex = *tokenCount;
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x2c;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar14 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar14 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = srcHeader;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((srcHeader & 0x400000) != 0) {
    iVar14 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar14 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = srcSwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* FUN_0006dcc0 @ 0x6dcc0 (1912 bytes) */
int FUN_0006dcc0(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint src1Select3;
  uint src1Negate2;
  uint src1Negate3;
  uint src1Select1;
  uint src1Negate1;
  uint src1Header;
  int dstMask2;
  uint tokenIndex;
  undefined4 newStorage;
  uint src0Negate3;
  uint src0Negate2;
  uint src0Negate1;
  int dstMask1;
  uint src0Select3;
  uint src0SelectX;
  uint src1SelectX;
  uint src0Header;
  uint dstHeader;
  uint dstMaskWord;
  uint src1SwizzleWord;
  int iVar16;
  uint src0SwizzleWord;
  uint *tokenCount;
  
  dstHeader = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff;
  tokenCount = (uint *)(ctx + ARB_tokenCount);
  src1SwizzleWord = 0;
  src0SwizzleWord = 0;
  dstMaskWord = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = 0x55;
  }
  if (*dstMask == 0) {
    iVar16 = dstMask[3];
    dstMask1 = dstMask[1];
    dstMask2 = dstMask[2];
LAB_0006ddb0:
    dstHeader = dstHeader | 0x400000;
    dstMaskWord = (uint)(iVar16 != 0) * 0x40 |
             (uint)(dstMask2 != 0) * 0x10 | (uint)(dstMask1 != 0) * 4 | (uint)(*dstMask != 0);
  }
  else {
    dstMask1 = dstMask[1];
    if (dstMask1 == 0) {
      iVar16 = dstMask[3];
      dstMask2 = dstMask[2];
      goto LAB_0006ddb0;
    }
    dstMask2 = dstMask[2];
    if (dstMask2 == 0) {
      iVar16 = dstMask[3];
      goto LAB_0006ddb0;
    }
    if (dstMask[3] == 0) {
      iVar16 = 0;
      goto LAB_0006ddb0;
    }
  }
  src0Header = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Negate == 0) {
    src0Negate1 = src0Negate[1];
    if (src0Negate1 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0Negate2 = src0Negate[2];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006df00;
    }
    src0Negate2 = src0Negate[2];
    if (src0Negate2 != 0) {
      src0Negate3 = src0Negate[3];
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006df00;
    }
    src0Negate3 = src0Negate[3];
    if (src0Negate3 != 0) {
      src0Select3 = src0Select[3];
      src0SelectX = *src0Select;
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006df00;
    }
    src0SelectX = *src0Select;
    if (src0SelectX != 0) {
      src0Select3 = src0Select[3];
      tokenIndex = src0Select[1];
      src1Header = src0Select[2];
      goto LAB_0006df00;
    }
    tokenIndex = src0Select[1];
    if (tokenIndex != 1) {
      src0Select3 = src0Select[3];
      src1Header = src0Select[2];
      goto LAB_0006df00;
    }
    src1Header = src0Select[2];
    if (src1Header != 2) {
      src0Select3 = src0Select[3];
      goto LAB_0006df00;
    }
    src0Select3 = src0Select[3];
    if (src0Select3 != 3) goto LAB_0006df00;
  }
  else {
    src0Negate3 = src0Negate[3];
    src0Select3 = src0Select[3];
    src0Negate1 = src0Negate[1];
    src0Negate2 = src0Negate[2];
    src0SelectX = *src0Select;
    tokenIndex = src0Select[1];
    src1Header = src0Select[2];
LAB_0006df00:
    src0Header = src0Header | 0x400000;
    src0SwizzleWord = (src0Negate3 & 1) << 0xf |
             (src0Select3 & 7) << 0xc |
             (src0Negate2 & 1) << 0xb |
             (src1Header & 7) << 8 |
             (src0Negate1 & 1) << 7 | (tokenIndex & 7) << 4 | (*src0Negate & 1) << 3 | src0SelectX & 7;
  }
  src1Header = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Negate == 0) {
    src1Negate1 = src1Negate[1];
    if (src1Negate1 == 0) {
      src1Negate2 = src1Negate[2];
      if (src1Negate2 == 0) {
        src1Negate3 = src1Negate[3];
        if (src1Negate3 == 0) {
          src1SelectX = *src1Select;
          if (src1SelectX == 0) {
            src1Select1 = src1Select[1];
            if (src1Select1 == 1) {
              tokenIndex = src1Select[2];
              if (tokenIndex == 2) {
                src1Select3 = src1Select[3];
                if (src1Select3 == 3) goto LAB_0006e054;
              }
              else {
                src1Select3 = src1Select[3];
              }
            }
            else {
              src1Select3 = src1Select[3];
              tokenIndex = src1Select[2];
            }
          }
          else {
            src1Select3 = src1Select[3];
            src1Select1 = src1Select[1];
            tokenIndex = src1Select[2];
          }
        }
        else {
          src1Select3 = src1Select[3];
          src1SelectX = *src1Select;
          src1Select1 = src1Select[1];
          tokenIndex = src1Select[2];
        }
      }
      else {
        src1Negate3 = src1Negate[3];
        src1Select3 = src1Select[3];
        src1SelectX = *src1Select;
        src1Select1 = src1Select[1];
        tokenIndex = src1Select[2];
      }
    }
    else {
      src1Negate3 = src1Negate[3];
      src1Select3 = src1Select[3];
      src1Negate2 = src1Negate[2];
      src1SelectX = *src1Select;
      src1Select1 = src1Select[1];
      tokenIndex = src1Select[2];
    }
  }
  else {
    src1Negate3 = src1Negate[3];
    src1Select3 = src1Select[3];
    src1Negate1 = src1Negate[1];
    src1Negate2 = src1Negate[2];
    src1SelectX = *src1Select;
    src1Select1 = src1Select[1];
    tokenIndex = src1Select[2];
  }
  src1Header = src1Header | 0x400000;
  src1SwizzleWord = (src1Negate3 & 1) << 0xf |
           (src1Select3 & 7) << 0xc |
           (src1Negate2 & 1) << 0xb |
           (tokenIndex & 7) << 8 |
           (src1Negate1 & 1) << 7 | (src1Select1 & 7) << 4 | (*src1Negate & 1) << 3 | src1SelectX & 7;
LAB_0006e054:
  tokenIndex = *tokenCount;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x4e;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstHeader;
  tokenIndex = *tokenCount + 1;
  *tokenCount = tokenIndex;
  if ((dstHeader & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      tokenIndex = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = dstMaskWord;
    tokenIndex = *tokenCount + 1;
    *tokenCount = tokenIndex;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= tokenIndex) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    tokenIndex = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src0Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src0SwizzleWord;
    dstHeader = *tokenCount + 1;
    *tokenCount = dstHeader;
  }
  iVar16 = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
    newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
      (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
    dstHeader = *tokenCount;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1Header;
  dstHeader = *tokenCount + 1;
  *tokenCount = dstHeader;
  if ((src1Header & 0x400000) != 0) {
    iVar16 = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= dstHeader) {
      newStorage = (**(code **)(iVar16 + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newStorage,*(int *)(ctx + ARB_tokenBuffer),*tokenCount << 2);
        (**(code **)(iVar16 + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newStorage;
      dstHeader = *tokenCount;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(dstHeader * 4 + *(int *)(ctx + ARB_tokenBuffer)) = src1SwizzleWord;
    *tokenCount = *tokenCount + 1;
  }
  return;
}

/* FUN_0006e460 @ 0x6e460 (1928 bytes) */
int FUN_0006e460(param_1, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
  int param_1;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Select;
  uint *src0Negate;
  uint src1File;
  uint src1Index;
  uint *src1Select;
  uint *src1Negate;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint *puVar18;
  
  uVar16 = 0x101;
  uVar12 = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff | 0x400000;
  puVar18 = (uint *)(param_1 + 0x754);
  uVar13 = 0;
  uVar15 = 0;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    uVar12 = uVar12 | 0x400000;
    uVar16 = 1;
  }
  uVar17 = uVar16 | 0x54;
  if (*dstMask == 0) {
    iVar14 = dstMask[3];
    iVar8 = dstMask[1];
    iVar2 = dstMask[2];
LAB_0006e560:
    uVar12 = uVar12 | 0x400000;
    uVar17 = (uint)(iVar14 != 0) * 0x40 |
             (uint)(iVar2 != 0) * 0x10 |
             (uint)(iVar8 != 0) * 4 | (uint)(*dstMask != 0) | uVar16 & 0xffffff00;
  }
  else {
    iVar8 = dstMask[1];
    if (iVar8 == 0) {
      iVar14 = dstMask[3];
      iVar2 = dstMask[2];
      goto LAB_0006e560;
    }
    iVar2 = dstMask[2];
    if (iVar2 == 0) {
      iVar14 = dstMask[3];
      goto LAB_0006e560;
    }
    if (dstMask[3] == 0) {
      iVar14 = 0;
      goto LAB_0006e560;
    }
  }
  uVar16 = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Negate == 0) {
    uVar7 = src0Negate[1];
    if (uVar7 != 0) {
      uVar5 = src0Negate[3];
      uVar9 = src0Select[3];
      uVar6 = src0Negate[2];
      uVar10 = *src0Select;
      uVar3 = src0Select[1];
      uVar1 = src0Select[2];
      goto LAB_0006e6b0;
    }
    uVar6 = src0Negate[2];
    if (uVar6 != 0) {
      uVar5 = src0Negate[3];
      uVar9 = src0Select[3];
      uVar10 = *src0Select;
      uVar3 = src0Select[1];
      uVar1 = src0Select[2];
      goto LAB_0006e6b0;
    }
    uVar5 = src0Negate[3];
    if (uVar5 != 0) {
      uVar9 = src0Select[3];
      uVar10 = *src0Select;
      uVar3 = src0Select[1];
      uVar1 = src0Select[2];
      goto LAB_0006e6b0;
    }
    uVar10 = *src0Select;
    if (uVar10 != 0) {
      uVar9 = src0Select[3];
      uVar3 = src0Select[1];
      uVar1 = src0Select[2];
      goto LAB_0006e6b0;
    }
    uVar3 = src0Select[1];
    if (uVar3 != 1) {
      uVar9 = src0Select[3];
      uVar1 = src0Select[2];
      goto LAB_0006e6b0;
    }
    uVar1 = src0Select[2];
    if (uVar1 != 2) {
      uVar9 = src0Select[3];
      goto LAB_0006e6b0;
    }
    uVar9 = src0Select[3];
    if (uVar9 != 3) goto LAB_0006e6b0;
  }
  else {
    uVar5 = src0Negate[3];
    uVar9 = src0Select[3];
    uVar7 = src0Negate[1];
    uVar6 = src0Negate[2];
    uVar10 = *src0Select;
    uVar3 = src0Select[1];
    uVar1 = src0Select[2];
LAB_0006e6b0:
    uVar16 = uVar16 | 0x400000;
    uVar15 = (uVar5 & 1) << 0xf |
             (uVar9 & 7) << 0xc |
             (uVar6 & 1) << 0xb |
             (uVar1 & 7) << 8 |
             (uVar7 & 1) << 7 | (uVar3 & 7) << 4 | (*src0Negate & 1) << 3 | uVar10 & 7;
  }
  uVar1 = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Negate == 0) {
    uVar10 = src1Negate[1];
    if (uVar10 == 0) {
      uVar7 = src1Negate[2];
      if (uVar7 == 0) {
        uVar6 = src1Negate[3];
        if (uVar6 == 0) {
          uVar11 = *src1Select;
          if (uVar11 == 0) {
            uVar5 = src1Select[1];
            if (uVar5 == 1) {
              uVar3 = src1Select[2];
              if (uVar3 == 2) {
                uVar9 = src1Select[3];
                if (uVar9 == 3) goto LAB_0006e804;
              }
              else {
                uVar9 = src1Select[3];
              }
            }
            else {
              uVar9 = src1Select[3];
              uVar3 = src1Select[2];
            }
          }
          else {
            uVar9 = src1Select[3];
            uVar5 = src1Select[1];
            uVar3 = src1Select[2];
          }
        }
        else {
          uVar9 = src1Select[3];
          uVar11 = *src1Select;
          uVar5 = src1Select[1];
          uVar3 = src1Select[2];
        }
      }
      else {
        uVar6 = src1Negate[3];
        uVar9 = src1Select[3];
        uVar11 = *src1Select;
        uVar5 = src1Select[1];
        uVar3 = src1Select[2];
      }
    }
    else {
      uVar6 = src1Negate[3];
      uVar9 = src1Select[3];
      uVar7 = src1Negate[2];
      uVar11 = *src1Select;
      uVar5 = src1Select[1];
      uVar3 = src1Select[2];
    }
  }
  else {
    uVar6 = src1Negate[3];
    uVar9 = src1Select[3];
    uVar10 = src1Negate[1];
    uVar7 = src1Negate[2];
    uVar11 = *src1Select;
    uVar5 = src1Select[1];
    uVar3 = src1Select[2];
  }
  uVar1 = uVar1 | 0x400000;
  uVar13 = (uVar6 & 1) << 0xf |
           (uVar9 & 7) << 0xc |
           (uVar7 & 1) << 0xb |
           (uVar3 & 7) << 8 |
           (uVar10 & 1) << 7 | (uVar5 & 7) << 4 | (*src1Negate & 1) << 3 | uVar11 & 7;
LAB_0006e804:
  uVar3 = *puVar18;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(undefined4 *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = 0x4e;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar12;
  uVar3 = *puVar18 + 1;
  *puVar18 = uVar3;
  if ((uVar12 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar3) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar3 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar17;
    uVar3 = *puVar18 + 1;
    *puVar18 = uVar3;
  }
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar3) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar3 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar3 * 4 + *(int *)(param_1 + 0x75c)) = uVar16;
  uVar12 = *puVar18 + 1;
  *puVar18 = uVar12;
  if ((uVar16 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar12) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar12 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar12 * 4 + *(int *)(param_1 + 0x75c)) = uVar15;
    uVar12 = *puVar18 + 1;
    *puVar18 = uVar12;
  }
  iVar14 = *(int *)(param_1 + 0x3d4);
  if (*(uint *)(param_1 + 0x758) <= uVar12) {
    uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
    if (*(int *)(param_1 + 0x75c) != 0) {
      _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
      (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
    }
    *(undefined4 *)(param_1 + 0x75c) = uVar4;
    uVar12 = *puVar18;
    *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
  }
  *(uint *)(uVar12 * 4 + *(int *)(param_1 + 0x75c)) = uVar1;
  uVar16 = *puVar18 + 1;
  *puVar18 = uVar16;
  if ((uVar1 & 0x400000) != 0) {
    iVar14 = *(int *)(param_1 + 0x3d4);
    if (*(uint *)(param_1 + 0x758) <= uVar16) {
      uVar4 = (**(code **)(iVar14 + 0xc))(*(uint *)(param_1 + 0x758) * 4 + 0x200);
      if (*(int *)(param_1 + 0x75c) != 0) {
        _memcpy(uVar4,*(int *)(param_1 + 0x75c),*puVar18 << 2);
        (**(code **)(iVar14 + 0x18))(*(undefined4 *)(param_1 + 0x75c));
      }
      *(undefined4 *)(param_1 + 0x75c) = uVar4;
      uVar16 = *puVar18;
      *(int *)(param_1 + 0x758) = *(int *)(param_1 + 0x758) + 0x80;
    }
    *(uint *)(uVar16 * 4 + *(int *)(param_1 + 0x75c)) = uVar13;
    *puVar18 = *puVar18 + 1;
  }
  return;
}

/* FUN_0006ec10 @ 0x6ec10 (4312 bytes) */
int FUN_0006ec10(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Words, src0Flags, src1File, src1Index, src1Words, src1Flags, src2File, src2Index, src2Words, src2Flags)
  int ctx;
  uint dstFile;
  uint dstIndex;
  int *dstMask;
  uint src0File;
  uint src0Index;
  uint *src0Words;
  uint *src0Flags;
  uint src1File;
  uint src1Index;
  uint *src1Words;
  uint *src1Flags;
  uint src2File;
  uint src2Index;
  uint *src2Words;
  uint *src2Flags;
{
  uint src2Flags2;
  uint src0Flags1;
  uint src2Flags3;
  uint src0Flags2;
  uint src2Words1;
  uint src0Flags3;
  uint src2Words2;
  uint src0Words1;
  uint src0Words2;
  uint src1Words1;
  uint src2Words3;
  uint src2Flags1;
  uint src0Words3;
  uint instrCountPtrValue;
  uint src1Words2;
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 newBuffer;
  uint src1Flags3;
  uint src1Flags2;
  uint src1Words3;
  int iVar8;
  uint src1Flags1;
  uint instrWord;
  uint src1WordsValue;
  uint src0WordsValue;
  uint src2WordsValue;
  uint uVar14;
  int allocator;
  uint uVar16;
  uint *instrCountPtr;
  undefined1 auStack_88 [4];
  uint uStack_84;
  
  uVar16 = 0;
  (**(code **)(ctx + 0x748))(ctx,0,auStack_88,dstMask,src0File,src0Index,src0Words,src0Flags);
  instrCountPtr = (uint *)(ctx + ARB_tokenCount);
  instrWord = uStack_84 & 0xffff;
  uVar14 = (src1File & 0x3f) << 0x10 | src1Index & 0xffff;
  if (*src1Flags == 0) {
    src1Flags1 = src1Flags[1];
    if (src1Flags1 != 0) {
      src1Flags3 = src1Flags[3];
      src1Words3 = src1Words[3];
      src1Flags2 = src1Flags[2];
      src1WordsValue = *src1Words;
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto LAB_0006edc0;
    }
    src1Flags2 = src1Flags[2];
    if (src1Flags2 != 0) {
      src1Flags3 = src1Flags[3];
      src1Words3 = src1Words[3];
      src1WordsValue = *src1Words;
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto LAB_0006edc0;
    }
    src1Flags3 = src1Flags[3];
    if (src1Flags3 != 0) {
      src1Words3 = src1Words[3];
      src1WordsValue = *src1Words;
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto LAB_0006edc0;
    }
    src1WordsValue = *src1Words;
    if (src1WordsValue != 0) {
      src1Words3 = src1Words[3];
      src1Words1 = src1Words[1];
      src1Words2 = src1Words[2];
      goto LAB_0006edc0;
    }
    src1Words1 = src1Words[1];
    if (src1Words1 != 1) {
      src1Words3 = src1Words[3];
      src1Words2 = src1Words[2];
      goto LAB_0006edc0;
    }
    src1Words2 = src1Words[2];
    if (src1Words2 != 2) {
      src1Words3 = src1Words[3];
      goto LAB_0006edc0;
    }
    src1Words3 = src1Words[3];
    if (src1Words3 != 3) goto LAB_0006edc0;
  }
  else {
    src1Flags3 = src1Flags[3];
    src1Words3 = src1Words[3];
    src1Flags1 = src1Flags[1];
    src1Flags2 = src1Flags[2];
    src1WordsValue = *src1Words;
    src1Words1 = src1Words[1];
    src1Words2 = src1Words[2];
LAB_0006edc0:
    uVar14 = uVar14 | 0x400000;
    uVar16 = (src1Flags3 & 1) << 0xf |
             (src1Words3 & 7) << 0xc |
             (src1Flags2 & 1) << 0xb |
             (src1Words2 & 7) << 8 |
             (src1Flags1 & 1) << 7 | (src1Words1 & 7) << 4 | (*src1Flags & 1) << 3 | src1WordsValue & 7;
  }
  instrCountPtrValue = *instrCountPtr;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrCountPtrValue) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrCountPtrValue = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(instrCountPtrValue * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x47;
  uVar1 = *instrCountPtr + 1;
  *instrCountPtr = uVar1;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= uVar1) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    uVar1 = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(uVar1 * 4 + *(int *)(ctx + ARB_tokenBuffer)) = instrWord | 0x440000;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 1;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar14;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  if ((uVar14 & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
      newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
      instrWord = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar16;
    instrWord = *instrCountPtr + 1;
    *instrCountPtr = instrWord;
  }
  uVar1 = 0;
  uVar14 = uStack_84 & 0xffff;
  uVar16 = (src0File & 0x3f) << 0x10 | src0Index & 0xffff;
  if (*src0Flags == 0) {
    src0Flags1 = src0Flags[1];
    if (src0Flags1 != 0) {
      src0Flags3 = src0Flags[3];
      src0Words3 = src0Words[3];
      src0Flags2 = src0Flags[2];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_0006f1f0;
    }
    src0Flags2 = src0Flags[2];
    if (src0Flags2 != 0) {
      src0Flags3 = src0Flags[3];
      src0Words3 = src0Words[3];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_0006f1f0;
    }
    src0Flags3 = src0Flags[3];
    if (src0Flags3 != 0) {
      src0Words3 = src0Words[3];
      src0WordsValue = *src0Words;
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_0006f1f0;
    }
    src0WordsValue = *src0Words;
    if (src0WordsValue != 0) {
      src0Words3 = src0Words[3];
      src0Words1 = src0Words[1];
      src0Words2 = src0Words[2];
      goto LAB_0006f1f0;
    }
    src0Words1 = src0Words[1];
    if (src0Words1 != 1) {
      src0Words3 = src0Words[3];
      src0Words2 = src0Words[2];
      goto LAB_0006f1f0;
    }
    src0Words2 = src0Words[2];
    if (src0Words2 != 2) {
      src0Words3 = src0Words[3];
      goto LAB_0006f1f0;
    }
    src0Words3 = src0Words[3];
    if (src0Words3 != 3) goto LAB_0006f1f0;
  }
  else {
    src0Flags3 = src0Flags[3];
    src0Words3 = src0Words[3];
    src0Flags1 = src0Flags[1];
    src0Flags2 = src0Flags[2];
    src0WordsValue = *src0Words;
    src0Words1 = src0Words[1];
    src0Words2 = src0Words[2];
LAB_0006f1f0:
    uVar16 = uVar16 | 0x400000;
    uVar1 = (src0Flags3 & 1) << 0xf |
            (src0Words3 & 7) << 0xc |
            (src0Flags2 & 1) << 0xb |
            (src0Words2 & 7) << 8 |
            (src0Flags1 & 1) << 7 | (src0Words1 & 7) << 4 | (*src0Flags & 1) << 3 | src0WordsValue & 7;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x47;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar14 | 0x440000;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 4;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar16;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  if ((uVar16 & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
      newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
      instrWord = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar1;
    instrWord = *instrCountPtr + 1;
    *instrCountPtr = instrWord;
  }
  uVar2 = 0;
  uVar14 = uStack_84 & 0xffff;
  uVar16 = 0x40;
  uVar1 = (src2File & 0x3f) << 0x10 | src2Index & 0xffff;
  if (*src2Flags == 0) {
    src2Flags1 = src2Flags[1];
    if (src2Flags1 != 0) {
      src2Flags3 = src2Flags[3];
      src2Words3 = src2Words[3];
      src2Flags2 = src2Flags[2];
      src2WordsValue = *src2Words;
      src2Words1 = src2Words[1];
      src2Words2 = src2Words[2];
      goto LAB_0006f620;
    }
    src2Flags2 = src2Flags[2];
    if (src2Flags2 != 0) {
      src2Flags3 = src2Flags[3];
      src2Words3 = src2Words[3];
      src2WordsValue = *src2Words;
      src2Words1 = src2Words[1];
      src2Words2 = src2Words[2];
      goto LAB_0006f620;
    }
    src2Flags3 = src2Flags[3];
    if (src2Flags3 != 0) {
      src2Words3 = src2Words[3];
      src2WordsValue = *src2Words;
      src2Words1 = src2Words[1];
      src2Words2 = src2Words[2];
      goto LAB_0006f620;
    }
    src2WordsValue = *src2Words;
    if (src2WordsValue != 0) {
      src2Words3 = src2Words[3];
      src2Words1 = src2Words[1];
      src2Words2 = src2Words[2];
      goto LAB_0006f620;
    }
    src2Words1 = src2Words[1];
    if (src2Words1 != 1) {
      src2Words3 = src2Words[3];
      src2Words2 = src2Words[2];
      goto LAB_0006f620;
    }
    src2Words2 = src2Words[2];
    if (src2Words2 != 2) {
      src2Words3 = src2Words[3];
      goto LAB_0006f620;
    }
    src2Words3 = src2Words[3];
    if (src2Words3 != 3) goto LAB_0006f620;
  }
  else {
    src2Flags3 = src2Flags[3];
    src2Words3 = src2Words[3];
    src2Flags1 = src2Flags[1];
    src2Flags2 = src2Flags[2];
    src2WordsValue = *src2Words;
    src2Words1 = src2Words[1];
    src2Words2 = src2Words[2];
LAB_0006f620:
    uVar1 = uVar1 | 0x400000;
    uVar2 = (src2Flags3 & 1) << 0xf |
            (src2Words3 & 7) << 0xc |
            (src2Flags2 & 1) << 0xb |
            (src2Words2 & 7) << 8 |
            (src2Flags1 & 1) << 7 | (src2Words1 & 7) << 4 | (*src2Flags & 1) << 3 | src2WordsValue & 7;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x47;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar14 | 0x440000;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x40;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar1;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  if ((uVar1 & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
      newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
      instrWord = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar2;
    instrWord = *instrCountPtr + 1;
    *instrCountPtr = instrWord;
  }
  uVar14 = (dstFile & 0x3f) << 0x10 | dstIndex & 0xffff | 0x400000;
  if ((dstFile == 0x12) || (dstFile == 0x13)) {
    uVar14 = uVar14 | 0x400000;
    uVar16 = 0x55;
  }
  if (*dstMask == 0) {
    allocator = dstMask[3];
    iVar8 = dstMask[1];
    iVar3 = dstMask[2];
  }
  else {
    iVar8 = dstMask[1];
    if (iVar8 == 0) {
      allocator = dstMask[3];
      iVar3 = dstMask[2];
    }
    else {
      iVar3 = dstMask[2];
      if (iVar3 == 0) {
        allocator = dstMask[3];
      }
      else {
        if (dstMask[3] != 0) goto LAB_0006f9f0;
        allocator = 0;
      }
    }
  }
  uVar14 = uVar14 | 0x400000;
  uVar16 = (uint)(allocator != 0) * 0x40 |
           (uint)(iVar3 != 0) * 0x10 | (uint)(iVar8 != 0) * 4 | (uint)(*dstMask != 0);
LAB_0006f9f0:
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(undefined4 *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = 0x39;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar14;
  instrWord = *instrCountPtr + 1;
  *instrCountPtr = instrWord;
  if ((uVar14 & 0x400000) != 0) {
    allocator = *(int *)(ctx + ARB_allocator);
    if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
      newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
      if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
        _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
        (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
      }
      *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
      instrWord = *instrCountPtr;
      *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
    }
    *(uint *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uVar16;
    instrWord = *instrCountPtr + 1;
    *instrCountPtr = instrWord;
  }
  allocator = *(int *)(ctx + ARB_allocator);
  if (*(uint *)(ctx + ARB_tokenCapacity) <= instrWord) {
    newBuffer = (**(code **)(allocator + 0xc))(*(uint *)(ctx + ARB_tokenCapacity) * 4 + 0x200);
    if (*(int *)(ctx + ARB_tokenBuffer) != 0) {
      _memcpy(newBuffer,*(int *)(ctx + ARB_tokenBuffer),*instrCountPtr << 2);
      (**(code **)(allocator + 0x18))(*(undefined4 *)(ctx + ARB_tokenBuffer));
    }
    *(undefined4 *)(ctx + ARB_tokenBuffer) = newBuffer;
    instrWord = *instrCountPtr;
    *(int *)(ctx + ARB_tokenCapacity) = *(int *)(ctx + ARB_tokenCapacity) + 0x80;
  }
  *(uint *)(instrWord * 4 + *(int *)(ctx + ARB_tokenBuffer)) = uStack_84 & 0xffff | 0x40000;
  *instrCountPtr = *instrCountPtr + 1;
  (**(code **)(ctx + 0x74c))(ctx,auStack_88);
  return;
}

/* FUN_0006fd10 @ 0x6fd10 (180 bytes) */
int FUN_0006fd10(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  uint uVar1;
  
  uVar1 = *param_2;
  if (param_2[1] <= uVar1) {
    uVar1 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if (param_2[2] != 0) {
      _memcpy(uVar1,param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = uVar1;
    uVar1 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar1 * 4 + param_2[2]) = param_3;
  *param_2 = *param_2 + 1;
  return;
}

/* FUN_0006fdd0 @ 0x6fdd0 (1812 bytes) */
int FUN_0006fdd0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  uint loopIndex;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  
  iVar4 = *(int *)(param_4 + 0x28);
  if (iVar4 == 0x87c3) {
    *(int *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + 1;
    *(int *)(param_3 + 0x118) = *(int *)(param_3 + 0x118) + 1;
    *(undefined1 *)(param_4 + 0x3d) = 1;
    iVar4 = *(int *)(param_4 + 0x24);
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      loopIndex = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
      while (loopIndex < *(uint *)(param_3 + 0x48)) {
        if (!bVar1) goto LAB_000702bc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          loopIndex = loopIndex + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      goto LAB_000702b8;
    }
    if (iVar4 == 0x87c0) {
      loopIndex = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 4;
      while (loopIndex < *(int *)(param_3 + 0x48) - 3U) {
        if (!bVar1) goto LAB_000703cc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          loopIndex = loopIndex + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_000703cc:
        iVar8 = loopIndex * 0x28;
        iVar4 = iVar8 + *(int *)(param_3 + 0x44);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = loopIndex + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(param_4 + 0x10) = iVar2;
            param_4 = param_4 + 4;
            iVar2 = *(int *)(param_3 + 0x44) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return 0;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar10 = *(int *)(param_3 + 0x48);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar10 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
      *(undefined4 *)(param_3 + 0x44) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(param_4 + 0x10) = iVar3;
        param_4 = param_4 + 4;
        iVar3 = *(int *)(param_3 + 0x44) + iVar4;
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return 0;
    }
    if (iVar4 != 0x87be) {
      return 1;
    }
    uVar9 = 0;
    loopIndex = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
    while (loopIndex < *(uint *)(param_3 + 0x48)) {
      if (!bVar1) goto LAB_000701ac;
      if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        loopIndex = loopIndex + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  else {
    if (iVar4 == 0x87c4) {
      return 0;
    }
    if (iVar4 != 0x87c2) {
      return 1;
    }
    *(int *)(param_2 + 0x5c) = *(int *)(param_2 + 0x5c) + 1;
    if (*(char *)(param_4 + 0x44) == '\0') {
      *(int *)(param_3 + 0x118) = *(int *)(param_3 + 0x118) + 1;
    }
    else {
      *(int *)(param_3 + 0x120) = *(int *)(param_3 + 0x120) + 1;
    }
    iVar4 = *(int *)(param_4 + 0x24);
    *(undefined1 *)(param_4 + 0x3d) = 1;
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      loopIndex = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
      while (loopIndex < *(uint *)(param_3 + 0x48)) {
        if (!bVar1) goto LAB_000702bc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          uVar6 = 1;
          bVar1 = false;
        }
        else {
          loopIndex = loopIndex + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
LAB_000702b8:
      if (!bVar1) {
LAB_000702bc:
        *(uint *)(param_4 + 4) = loopIndex;
        *(undefined1 *)(loopIndex * 0x28 + *(int *)(param_3 + 0x44) + 0x10) = 1;
        return 0;
      }
      *(undefined1 *)(param_2 + 0x10) = uVar6;
      iVar4 = *(int *)(param_3 + 0x48);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar4 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
      *(undefined4 *)(param_3 + 0x44) = uVar9;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      goto LAB_00070350;
    }
    if (iVar4 == 0x87c0) {
      loopIndex = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 4;
      while (loopIndex < *(int *)(param_3 + 0x48) - 3U) {
        if (!bVar1) goto LAB_0006ffbc;
        if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
          bVar1 = false;
        }
        else {
          loopIndex = loopIndex + 1;
          iVar4 = iVar4 + 0x28;
        }
      }
      if (!bVar1) {
LAB_0006ffbc:
        iVar8 = loopIndex * 0x28;
        iVar4 = iVar8 + *(int *)(param_3 + 0x44);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = loopIndex + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(param_4 + 0x10) = iVar2;
            param_4 = param_4 + 4;
            iVar2 = *(int *)(param_3 + 0x44) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return 0;
        }
      }
      *(undefined1 *)(param_2 + 0x10) = 0;
      iVar10 = *(int *)(param_3 + 0x48);
      uVar9 = (**(code **)(param_1 + 0x10))(iVar10 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (uVar9,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
      (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
      *(undefined4 *)(param_3 + 0x44) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(param_4 + 0x10) = iVar3;
        param_4 = param_4 + 4;
        iVar3 = iVar4 + *(int *)(param_3 + 0x44);
        iVar4 = iVar4 + 0x28;
        *(undefined1 *)(iVar3 + 0x10) = 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return 0;
    }
    if (iVar4 != 0x87be) {
      return 1;
    }
    uVar9 = 0;
    loopIndex = 0;
    iVar4 = 0;
    bVar1 = true;
    *(int *)(param_3 + 0x4c) = *(int *)(param_3 + 0x4c) + 1;
    while (loopIndex < *(uint *)(param_3 + 0x48)) {
      if (!bVar1) goto LAB_000701ac;
      if (*(char *)(iVar4 + *(int *)(param_3 + 0x44) + 0x10) == '\0') {
        uVar9 = 1;
        bVar1 = false;
      }
      else {
        loopIndex = loopIndex + 1;
        iVar4 = iVar4 + 0x28;
      }
    }
  }
  if (!bVar1) {
LAB_000701ac:
    *(uint *)(param_4 + 4) = loopIndex;
    *(undefined4 *)(param_4 + 8) = 0;
    *(undefined1 *)(loopIndex * 0x28 + *(int *)(param_3 + 0x44) + 0x10) = 1;
    return 0;
  }
  *(char *)(param_2 + 0x10) = (char)uVar9;
  iVar4 = *(int *)(param_3 + 0x48);
  uVar5 = (**(code **)(param_1 + 0x10))(iVar4 + 0x40,0x28);
  (**(code **)(((unsigned char *)0x00001344) + param_1))
            (uVar5,*(undefined4 *)(param_3 + 0x44),*(int *)(param_3 + 0x48) * 0x28);
  (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x44));
  *(undefined4 *)(param_3 + 0x44) = uVar5;
  *(int *)(param_3 + 0x48) = *(int *)(param_3 + 0x48) + 0x40;
  *(undefined4 *)(param_4 + 8) = uVar9;
LAB_00070350:
  *(int *)(param_4 + 4) = iVar4;
  *(undefined1 *)(iVar4 * 0x28 + *(int *)(param_3 + 0x44) + 0x10) = 1;
  return 0;
}

/* FUN_00070520 @ 0x70520 (252 bytes) */
int FUN_00070520(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
{
  int iVar1;
  int iVar2;
  uint loopIndex;
  int iVar4;
  
  if (*param_4 == 2) {
    iVar1 = *(int *)(param_2 + 0x20);
    iVar4 = param_4[1] * 0x54;
    iVar2 = iVar4 + iVar1;
    if (*(char *)(iVar2 + 0x3d) == '\0') {
      if (*(int *)(iVar2 + 0x30) == 0) {
        if (*(uint *)(iVar2 + 0x34) < 2) {
          iVar1 = ((int (*)())FUN_0006fdd0)(param_1,param_2,param_3,iVar2);
          if (iVar1 != 1) {
            return 0;
          }
          return 1;
        }
      }
      else {
        iVar4 = FUN_00054da0(param_2 + 0x1c,*(int *)(iVar2 + 0x30));
        iVar1 = *(int *)(param_2 + 0x20);
        iVar4 = iVar4 * 0x54;
      }
      if (*(int *)(iVar4 + iVar1 + 0x34) != 0) {
        loopIndex = 0;
        iVar2 = iVar4;
        do {
          iVar1 = ((int (*)())FUN_0006fdd0)(param_1,param_2,param_3,iVar1 + iVar2);
          if (iVar1 == 1) {
            return 1;
          }
          iVar1 = *(int *)(param_2 + 0x20);
          loopIndex = loopIndex + 1;
          iVar2 = iVar2 + 0x54;
        } while (loopIndex < *(uint *)(iVar1 + iVar4 + 0x34));
      }
    }
  }
  return 0;
}

/* FUN_00070630 @ 0x70630 (1412 bytes) */
int FUN_00070630(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  uint loopIndex2;
  uint loopIndex;
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  if (*param_4 == 2) {
    iVar10 = param_4[1];
    iVar11 = iVar10 * 0x54 + *(int *)(param_2 + 0x20);
    if ((*(int *)(iVar11 + 0x28) == 0x87c4) && (*(char *)(iVar11 + 0x3d) == '\0')) {
      *(undefined1 *)(iVar11 + 0x3d) = 1;
      *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + 1;
      iVar7 = *(int *)(iVar10 * 0x54 + *(int *)(param_2 + 0x20) + 0x24);
      if (iVar7 == 0x87bf) {
        uVar5 = 0;
        uVar6 = 0;
        bVar1 = true;
        while (uVar5 < *(uint *)(param_3 + 0x40)) {
          if (!bVar1) goto LAB_000708f8;
          if (*(char *)(uVar5 * 0x28 + *(int *)(param_3 + 0x3c) + 0x10) == '\0') {
            uVar6 = 1;
            bVar1 = false;
          }
          else {
            uVar5 = uVar5 + 1;
          }
        }
        if (bVar1) {
          *(undefined1 *)(param_2 + 0x10) = uVar6;
          uVar5 = *(uint *)(param_3 + 0x40);
          uVar4 = (**(code **)(param_1 + 0x10))(uVar5 + 0x40,0x28);
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (uVar4,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
          *(undefined4 *)(param_3 + 0x3c) = uVar4;
          *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
          *(uint *)(iVar11 + 4) = uVar5;
        }
        else {
LAB_000708f8:
          *(uint *)(iVar11 + 4) = uVar5;
        }
        iVar11 = uVar5 * 0x28;
        *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar11 + 0x10) = 1;
        *(undefined4 *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x14) = 4;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x18) = iVar10;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x1c) = iVar10;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x20) = iVar10;
        *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x24) = iVar10;
      }
      else if (iVar7 == 0x87c0) {
        loopIndex = 0;
        bVar1 = true;
        while (loopIndex < *(int *)(param_3 + 0x40) - 3U) {
          if (!bVar1) goto LAB_00070a18;
          if (*(char *)(loopIndex * 0x28 + *(int *)(param_3 + 0x3c) + 0x10) == '\0') {
            bVar1 = false;
          }
          else {
            loopIndex = loopIndex + 1;
          }
        }
        if (!bVar1) {
LAB_00070a18:
          iVar8 = loopIndex * 0x28;
          iVar7 = iVar8 + *(int *)(param_3 + 0x3c);
          if (((*(char *)(iVar7 + 0x38) == '\0') && (*(char *)(iVar7 + 0x60) == '\0')) &&
             (*(char *)(iVar7 + 0x88) == '\0')) {
            iVar7 = 0;
            iVar12 = 4;
            do {
              iVar2 = loopIndex + iVar7;
              iVar7 = iVar7 + 1;
              *(int *)(iVar11 + 0x10) = iVar2;
              iVar11 = iVar11 + 4;
              *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x10) = 1;
              *(undefined4 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x14) = 4;
              *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x18) = iVar10;
              *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x1c) = iVar10;
              *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x20) = iVar10;
              iVar2 = *(int *)(param_3 + 0x3c) + iVar8;
              iVar8 = iVar8 + 0x28;
              *(int *)(iVar2 + 0x24) = iVar10;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
            return;
          }
        }
        *(undefined1 *)(param_2 + 0x10) = 0;
        iVar12 = *(int *)(param_3 + 0x40);
        uVar4 = (**(code **)(param_1 + 0x10))(iVar12 + 0x40,0x28);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar4,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
        *(undefined4 *)(param_3 + 0x3c) = uVar4;
        iVar8 = iVar12 * 0x28;
        iVar2 = 4;
        iVar7 = 0;
        *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
        do {
          iVar3 = iVar12 + iVar7;
          iVar7 = iVar7 + 1;
          *(int *)(iVar11 + 0x10) = iVar3;
          iVar11 = iVar11 + 4;
          *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x10) = 1;
          *(undefined4 *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x14) = 4;
          *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x18) = iVar10;
          *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x1c) = iVar10;
          *(int *)(*(int *)(param_3 + 0x3c) + iVar8 + 0x20) = iVar10;
          iVar3 = *(int *)(param_3 + 0x3c) + iVar8;
          iVar8 = iVar8 + 0x28;
          *(int *)(iVar3 + 0x24) = iVar10;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      else if (iVar7 == 0x87be) {
        uVar5 = *(uint *)(param_3 + 0x40);
        loopIndex2 = 0;
        bVar1 = false;
        iVar7 = 0;
        while (loopIndex2 < uVar5) {
          if (bVar1) goto LAB_0007075c;
          iVar8 = iVar7 + *(int *)(param_3 + 0x3c);
          if ((*(char *)(iVar8 + 0x10) == '\0') || (bVar1 = true, 3 < *(uint *)(iVar8 + 0x14))) {
            loopIndex2 = loopIndex2 + 1;
            iVar7 = iVar7 + 0x28;
            bVar1 = false;
          }
        }
        if (bVar1) {
LAB_0007075c:
          *(uint *)(iVar11 + 4) = loopIndex2;
          iVar7 = loopIndex2 * 0x28;
          *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(*(int *)(param_3 + 0x3c) + iVar7 + 0x14);
          iVar11 = iVar7 + *(int *)(param_3 + 0x3c);
          *(int *)(*(int *)(iVar11 + 0x14) * 4 + iVar11 + 0x18) = iVar10;
          iVar7 = iVar7 + *(int *)(param_3 + 0x3c);
          *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;
        }
        else {
          if (uVar5 == 0) {
LAB_000707f4:
            *(undefined1 *)(param_2 + 0x10) = 0;
            uVar9 = *(uint *)(param_3 + 0x40);
            uVar4 = (**(code **)(param_1 + 0x10))(uVar9 + 0x40,0x28);
            (**(code **)(((unsigned char *)0x00001344) + param_1))
                      (uVar4,*(undefined4 *)(param_3 + 0x3c),*(int *)(param_3 + 0x40) * 0x28);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_3 + 0x3c));
            *(undefined4 *)(param_3 + 0x3c) = uVar4;
            *(int *)(param_3 + 0x40) = *(int *)(param_3 + 0x40) + 0x40;
            *(undefined4 *)(iVar11 + 8) = 0;
            *(uint *)(iVar11 + 4) = uVar9;
          }
          else {
            uVar9 = 0;
            do {
              bVar1 = *(char *)(uVar9 * 0x28 + *(int *)(param_3 + 0x3c) + 0x10) != '\0';
              if (bVar1) {
                uVar9 = uVar9 + 1;
              }
              if (uVar5 <= uVar9) {
                if (bVar1) goto LAB_000707f4;
                break;
              }
            } while (bVar1);
            *(uint *)(iVar11 + 4) = uVar9;
            *(undefined4 *)(iVar11 + 8) = 0;
          }
          iVar11 = uVar9 * 0x28;
          *(undefined1 *)(*(int *)(param_3 + 0x3c) + iVar11 + 0x10) = 1;
          *(undefined4 *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x14) = 1;
          *(int *)(iVar11 + *(int *)(param_3 + 0x3c) + 0x18) = iVar10;
        }
      }
    }
  }
  return;
}

/* FUN_00070bf0 @ 0x70bf0 (80 bytes) */
int FUN_00070bf0(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  if ((*param_1 == 2) &&
     ((((iVar1 = param_1[1], iVar1 == *(int *)(param_2 + 0x18) ||
        (iVar1 == *(int *)(param_2 + 0x1c))) || (iVar1 == *(int *)(param_2 + 0x20))) ||
      (iVar1 == *(int *)(param_2 + 0x24))))) {
    return 1;
  }
  return 0;
}

/* FUN_00070c50 @ 0x70c50 (4 bytes) */
int FUN_00070c50()
{
  return;
}

/* FUN_00070c60 @ 0x70c60 (4 bytes) */
int FUN_00070c60()
{
  return;
}

/* FUN_00070c70 @ 0x70c70 (84 bytes) */
int FUN_00070c70(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = uVar2;
    if (*(int *)(uVar2 * 4 + param_1 + 0x60) == -1) {
      return uVar2;
    }
    do {
      uVar2 = uVar1 + 1;
      if (0x15 < uVar2) {
        return 0xffffffff;
      }
      uVar1 = uVar2;
    } while (((uVar2 == 1) || (uVar1 = 0x12, uVar2 == 0x12)) || (uVar1 = uVar2, uVar2 == 0x13));
  } while( true );
}

/* FUN_00070cd0 @ 0x70cd0 (144 bytes) */
int FUN_00070cd0(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  
  iVar3 = *(int *)(param_1 + 0x40);
  if (iVar3 == 0) {
    return -1;
  }
  iVar7 = *(int *)(param_1 + 0x3c);
  if (*(char *)(iVar7 + 0x10) == '\0') {
    iVar4 = 0;
    iVar5 = 0;
    iVar8 = iVar7;
  }
  else {
    pcVar6 = (char *)(iVar7 + 0x38);
    iVar4 = 0;
    iVar2 = 0x28;
    do {
      iVar5 = iVar2;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        return -1;
      }
      cVar1 = *pcVar6;
      iVar8 = iVar7 + iVar5;
      pcVar6 = pcVar6 + 0x28;
      iVar2 = iVar5 + 0x28;
    } while (cVar1 != '\0');
  }
  *(undefined1 *)(iVar8 + 0x10) = 1;
  *(undefined4 *)(*(int *)(param_1 + 0x3c) + iVar5 + 0x14) = 4;
  return iVar4;
}

/* FUN_00070d80 @ 0x70d80 (3624 bytes) */
int FUN_00070d80(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  uint *puVar7;
  
  puVar7 = (uint *)(param_2 + 4);
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (param_4 == 0) {
    if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*puVar7 * 4 + *(int *)(param_2 + 0xc)) = 0x47;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x100000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x440000;
    puVar6 = (undefined *)0x0;
    uVar4 = *(uint *)(param_2 + 8);
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    if (uVar4 <= uVar5) {
LAB_00071330:
      uVar3 = (**(code **)(param_1 + 0xc))(uVar4 * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
LAB_00071390:
    *(undefined **)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = puVar6;
    *puVar7 = *puVar7 + 1;
  }
  else {
    *(undefined1 *)(param_2 + 3) = 1;
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar2);
    if (sVar1 == 0x801) {
      if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(int *)(param_2 + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(undefined4 *)(param_2 + 0xc) = uVar3;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(undefined4 *)(*puVar7 * 4 + *(int *)(param_2 + 0xc)) = 0x49;
      uVar5 = *puVar7 + 1;
      *puVar7 = uVar5;
      uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
      if (*(uint *)(param_2 + 8) <= uVar5) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(int *)(param_2 + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(undefined4 *)(param_2 + 0xc) = uVar3;
        uVar5 = *puVar7;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x40000;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
      uVar5 = *(uint *)(((unsigned char *)0x000013c0) + param_3) & 0xffff | 0x40000;
      if (*(uint *)(param_2 + 8) <= uVar4) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(int *)(param_2 + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(undefined4 *)(param_2 + 0xc) = uVar3;
        uVar4 = *puVar7;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar5;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
      if (*(uint *)(param_2 + 8) <= uVar4) {
        uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
        if (*(int *)(param_2 + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
        }
        *(undefined4 *)(param_2 + 0xc) = uVar3;
        uVar4 = *puVar7;
        *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
      }
      *(uint *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = uVar5;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
    }
    else {
      if (sVar1 == 0x2601) {
        if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(int *)(param_2 + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0xc) = uVar3;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(*puVar7 * 4 + *(int *)(param_2 + 0xc)) = 0x23;
        uVar4 = *puVar7 + 1;
        *puVar7 = uVar4;
        if (*(uint *)(param_2 + 8) <= uVar4) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(int *)(param_2 + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0xc) = uVar3;
          uVar4 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x100000;
        uVar5 = *puVar7 + 1;
        *puVar7 = uVar5;
        uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
        if (*(uint *)(param_2 + 8) <= uVar5) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(int *)(param_2 + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0xc) = uVar3;
          uVar5 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x440000;
        uVar4 = *puVar7 + 1;
        *puVar7 = uVar4;
        if (*(uint *)(param_2 + 8) <= uVar4) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(int *)(param_2 + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0xc) = uVar3;
          uVar4 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(undefined **)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = ((unsigned char *)0x00004054);
        uVar5 = *puVar7 + 1;
        *puVar7 = uVar5;
        uVar4 = *(uint *)(((unsigned char *)0x000013c4) + param_3);
        if (*(uint *)(param_2 + 8) <= uVar5) {
          uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
          if (*(int *)(param_2 + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
            (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
          }
          *(undefined4 *)(param_2 + 0xc) = uVar3;
          uVar5 = *puVar7;
          *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
        }
        *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x410000;
        puVar6 = ((unsigned char *)0x00004214);
        uVar4 = *(uint *)(param_2 + 8);
        uVar5 = *puVar7 + 1;
        *puVar7 = uVar5;
        if (uVar4 <= uVar5) goto LAB_00071330;
        goto LAB_00071390;
      }
      if (sVar1 != 0x800) {
        return;
      }
      uVar4 = *puVar7;
    }
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x49;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x40000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x40000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c4) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x410000;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x2222;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x2c;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x100000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + param_3);
    if (*(uint *)(param_2 + 8) <= uVar5) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(param_2 + 0xc)) = uVar4 & 0xffff | 0x440000;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(param_2 + 8) <= uVar4) {
      uVar3 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(param_2 + 0xc),*puVar7 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(param_2 + 0xc)) = 0;
    *puVar7 = *puVar7 + 1;
  }
  return;
}

/* FUN_00071bc0 @ 0x71bc0 (7188 bytes) */
int FUN_00071bc0(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int in_r7;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  bool bVar25;
  int iVar26;
  uint uStack_58;
  
  iVar21 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar19 = iVar21 + 0x13c;
  *(undefined4 *)(((unsigned char *)0x0000137c) + iVar21) = 0;
  ((unsigned char *)0x000013d0)[iVar21] = 0;
  if ((param_2[6] == 0) || (param_2[5] == 0)) {
    param_2[0x19] = 0;
    param_2[0xc] = 0;
    param_2[0x15] = 0;
    param_2[0x16] = 0;
    param_2[0x17] = 0;
    param_2[0x18] = 0;
    return 1;
  }
  *(undefined1 *)(param_2 + 4) = 1;
  uVar12 = ((int (*)())FUN_00070cd0)(iVar21);
  *(undefined4 *)(((unsigned char *)0x000013c0) + iVar21) = uVar12;
  uVar12 = ((int (*)())FUN_00070cd0)(iVar21);
  *(undefined4 *)(((unsigned char *)0x000013cc) + iVar21) = uVar12;
  iVar26 = 0x16;
  iVar22 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar10 = iVar22;
  do {
    *(undefined4 *)(iVar10 + 0x60) = 0xffffffff;
    *(undefined4 *)(iVar10 + 0xb8) = 0xffffffff;
    iVar10 = iVar10 + 4;
    iVar26 = iVar26 + -1;
  } while (iVar26 != 0);
  iVar10 = 1;
  *(undefined4 *)(((unsigned char *)0x00001398) + iVar22) = 0;
  *(undefined4 *)(iVar22 + 0x110) = 0;
  if (param_2[5] != 0) {
    uVar13 = 0;
    do {
      iVar26 = uVar13 * 0x74;
      iVar18 = param_2[6];
      in_r7 = *(int *)(((unsigned char *)0x0000118c) + param_1);
      iVar16 = *param_2;
      iVar15 = **(int **)(in_r7 * 4 + iVar16);
      if (*(int *)(iVar26 + iVar18 + 0x20) == 2) {
        iVar17 = *(int *)(iVar26 + iVar18 + 0x24) * 0x54;
        iVar14 = iVar17 + param_2[8];
        if ((*(int *)(iVar14 + 0x28) == 0x87c1) && (*(char *)(iVar14 + 0x3d) == '\0')) {
          *(undefined4 *)(iVar17 + param_2[8]) = 0;
          *(undefined1 *)(iVar14 + 0x3d) = 1;
          param_2[0x16] = param_2[0x16] + 1;
          if ((*(char *)(iVar14 + 0x44) == '\0') || (*(int *)(iVar14 + 0x48) == 0x12)) {
            iVar16 = *(int *)(iVar14 + 0x24);
            if (iVar16 == 0x87bf) {
LAB_0007209c:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar14 + 4) = iVar10;
              iVar10 = iVar10 + 1;
            }
            else if (iVar16 == 0x87c0) {
              *(int *)(iVar14 + 0x1c) = iVar10;
              *(int *)(iVar14 + 0x10) = iVar10;
              *(int *)(iVar14 + 0x14) = iVar10;
              *(int *)(iVar14 + 0x18) = iVar10;
              iVar18 = iVar10 * 0x28;
              iVar10 = iVar10 + 4;
            }
            else {
              iVar18 = 0;
              if (iVar16 == 0x87be) goto LAB_0007209c;
            }
            iVar18 = *(int *)(iVar15 + 0x10) + iVar18;
          }
          else {
            iVar16 = iVar10;
            switch(*(int *)(iVar14 + 0x48)) {
            case 0:
              iVar16 = iVar10 + 1;
              iVar10 = 0;
              iVar18 = 0;
              *(undefined1 *)(iVar15 + 0x18) = 1;
              *(undefined4 *)(iVar15 + 0x60) = 1;
              *(undefined4 *)(iVar15 + 0xb8) = 0;
              break;
            case 1:
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 8;
              *(undefined4 *)(iVar15 + 100) = 1;
              *(int *)(((unsigned char *)0x0000139c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xbc) = iVar10;
              break;
            case 2:
              iVar17 = *(int *)(iVar14 + 0x4c);
              uVar24 = param_2[0xc];
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              *(undefined1 *)((int)param_2 + iVar17 + 0x34) = 1;
              param_2[0xc] = uVar24 | 4;
              *(int *)(((unsigned char *)0x000013a0) + iVar17 * 4 + iVar15) = iVar10;
              iVar17 = (iVar17 + 10) * 4 + iVar15;
              *(undefined4 *)(iVar17 + 0x60) = 1;
              *(int *)(iVar17 + 0xb8) = iVar10;
              break;
            case 3:
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 1;
              *(undefined4 *)(iVar15 + 0x68) = 1;
              *(int *)(((unsigned char *)0x00001388) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc0) = iVar10;
              break;
            case 4:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xc4) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x23) = 1;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              break;
            case 5:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 200) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x24) = 1;
              *(undefined4 *)(iVar15 + 0x70) = 1;
              break;
            case 6:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xcc) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x25) = 1;
              *(undefined4 *)(iVar15 + 0x74) = 1;
              break;
            case 7:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x22) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 8:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd4) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x27) = 1;
              *(undefined4 *)(iVar15 + 0x7c) = 1;
              break;
            case 9:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd8) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x28) = 1;
              *(undefined4 *)(iVar15 + 0x80) = 1;
              break;
            case 10:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xdc) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x29) = 1;
              *(undefined4 *)(iVar15 + 0x84) = 1;
              break;
            case 0xb:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x26) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 0xc:
              iVar17 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar16 = iVar10 + 1;
                iVar17 = iVar10;
              }
              iVar18 = iVar17 * 0x28;
              *(undefined4 *)(iVar14 + 8) = 2;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar17;
              iVar10 = iVar17;
              break;
            case 0xd:
              iVar17 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar16 = iVar10 + 1;
                iVar17 = iVar10;
              }
              iVar18 = iVar17 * 0x28;
              *(undefined4 *)(iVar14 + 8) = 3;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar17;
              iVar10 = iVar17;
              break;
            case 0xe:
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 2;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              *(int *)(((unsigned char *)0x0000138c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc4) = iVar10;
              break;
            case 0xf:
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x40;
              *(int *)(((unsigned char *)0x00001390U) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x100) = iVar10;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(undefined4 *)(iVar14 + 8) = 1;
              break;
            case 0x10:
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x80;
              *(undefined4 *)(iVar15 + 0xac) = 1;
              *(int *)(((unsigned char *)0x00001394) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x104) = iVar10;
              break;
            default:
              iVar18 = 0;
              iVar10 = 0;
            }
            *(int *)(iVar14 + 4) = iVar10;
            iVar18 = *(int *)(iVar15 + 0x10) + iVar18;
            iVar10 = iVar16;
          }
          *(undefined1 *)(iVar18 + 0x10) = 1;
          in_r7 = *(int *)(((unsigned char *)0x0000118c) + param_1);
          iVar16 = *param_2;
          iVar18 = param_2[6];
        }
      }
      iVar15 = **(int **)(in_r7 * 4 + iVar16);
      if (*(int *)(iVar26 + iVar18 + 0x3c) == 2) {
        iVar17 = *(int *)(iVar26 + iVar18 + 0x40) * 0x54;
        iVar14 = iVar17 + param_2[8];
        if ((*(int *)(iVar14 + 0x28) == 0x87c1) && (*(char *)(iVar14 + 0x3d) == '\0')) {
          *(undefined4 *)(iVar17 + param_2[8]) = 0;
          *(undefined1 *)(iVar14 + 0x3d) = 1;
          param_2[0x16] = param_2[0x16] + 1;
          if ((*(char *)(iVar14 + 0x44) == '\0') || (*(int *)(iVar14 + 0x48) == 0x12)) {
            iVar16 = *(int *)(iVar14 + 0x24);
            if (iVar16 == 0x87bf) {
LAB_000724bc:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar14 + 4) = iVar10;
              iVar10 = iVar10 + 1;
            }
            else if (iVar16 == 0x87c0) {
              *(int *)(iVar14 + 0x1c) = iVar10;
              *(int *)(iVar14 + 0x10) = iVar10;
              *(int *)(iVar14 + 0x14) = iVar10;
              *(int *)(iVar14 + 0x18) = iVar10;
              iVar18 = iVar10 * 0x28;
              iVar10 = iVar10 + 4;
            }
            else {
              iVar18 = 0;
              if (iVar16 == 0x87be) goto LAB_000724bc;
            }
            iVar18 = *(int *)(iVar15 + 0x10) + iVar18;
          }
          else {
            iVar16 = iVar10;
            switch(*(int *)(iVar14 + 0x48)) {
            case 0:
              iVar16 = iVar10 + 1;
              iVar10 = 0;
              iVar18 = 0;
              *(undefined1 *)(iVar15 + 0x18) = 1;
              *(undefined4 *)(iVar15 + 0x60) = 1;
              *(undefined4 *)(iVar15 + 0xb8) = 0;
              break;
            case 1:
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 8;
              *(undefined4 *)(iVar15 + 100) = 1;
              *(int *)(((unsigned char *)0x0000139c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xbc) = iVar10;
              break;
            case 2:
              iVar17 = *(int *)(iVar14 + 0x4c);
              uVar24 = param_2[0xc];
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              *(undefined1 *)((int)param_2 + iVar17 + 0x34) = 1;
              param_2[0xc] = uVar24 | 4;
              *(int *)(((unsigned char *)0x000013a0) + iVar17 * 4 + iVar15) = iVar10;
              iVar17 = (iVar17 + 10) * 4 + iVar15;
              *(undefined4 *)(iVar17 + 0x60) = 1;
              *(int *)(iVar17 + 0xb8) = iVar10;
              break;
            case 3:
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 1;
              *(undefined4 *)(iVar15 + 0x68) = 1;
              *(int *)(((unsigned char *)0x00001388) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc0) = iVar10;
              break;
            case 4:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xc4) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x23) = 1;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              break;
            case 5:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 200) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x24) = 1;
              *(undefined4 *)(iVar15 + 0x70) = 1;
              break;
            case 6:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xcc) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x25) = 1;
              *(undefined4 *)(iVar15 + 0x74) = 1;
              break;
            case 7:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x22) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 8:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd4) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x27) = 1;
              *(undefined4 *)(iVar15 + 0x7c) = 1;
              break;
            case 9:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd8) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x28) = 1;
              *(undefined4 *)(iVar15 + 0x80) = 1;
              break;
            case 10:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xdc) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x29) = 1;
              *(undefined4 *)(iVar15 + 0x84) = 1;
              break;
            case 0xb:
              iVar18 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar16 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x26) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 0xc:
              iVar17 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar16 = iVar10 + 1;
                iVar17 = iVar10;
              }
              iVar18 = iVar17 * 0x28;
              *(undefined4 *)(iVar14 + 8) = 2;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar17;
              iVar10 = iVar17;
              break;
            case 0xd:
              iVar17 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar16 = iVar10 + 1;
                iVar17 = iVar10;
              }
              iVar18 = iVar17 * 0x28;
              *(undefined4 *)(iVar14 + 8) = 3;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar17;
              iVar10 = iVar17;
              break;
            case 0xe:
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 2;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              *(int *)(((unsigned char *)0x0000138c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc4) = iVar10;
              break;
            case 0xf:
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x40;
              *(int *)(((unsigned char *)0x00001390U) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x100) = iVar10;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(undefined4 *)(iVar14 + 8) = 1;
              break;
            case 0x10:
              iVar18 = iVar10 * 0x28;
              iVar16 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x80;
              *(undefined4 *)(iVar15 + 0xac) = 1;
              *(int *)(((unsigned char *)0x00001394) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x104) = iVar10;
              break;
            default:
              iVar18 = 0;
              iVar10 = 0;
            }
            *(int *)(iVar14 + 4) = iVar10;
            iVar18 = *(int *)(iVar15 + 0x10) + iVar18;
            iVar10 = iVar16;
          }
          *(undefined1 *)(iVar18 + 0x10) = 1;
          in_r7 = *(int *)(((unsigned char *)0x0000118c) + param_1);
          iVar16 = *param_2;
          iVar18 = param_2[6];
        }
      }
      iVar15 = **(int **)(in_r7 * 4 + iVar16);
      if (*(int *)(iVar26 + iVar18 + 0x58) == 2) {
        iVar26 = *(int *)(iVar26 + iVar18 + 0x5c) * 0x54;
        in_r7 = iVar26 + param_2[8];
        if ((*(int *)(in_r7 + 0x28) == 0x87c1) && (*(char *)(in_r7 + 0x3d) == '\0')) {
          *(undefined4 *)(iVar26 + param_2[8]) = 0;
          *(undefined1 *)(in_r7 + 0x3d) = 1;
          param_2[0x16] = param_2[0x16] + 1;
          if ((*(char *)(in_r7 + 0x44) == '\0') || (*(int *)(in_r7 + 0x48) == 0x12)) {
            iVar26 = *(int *)(in_r7 + 0x24);
            if (iVar26 == 0x87bf) {
LAB_000728e4:
              iVar16 = iVar10 * 0x28;
              *(int *)(in_r7 + 4) = iVar10;
              iVar10 = iVar10 + 1;
            }
            else if (iVar26 == 0x87c0) {
              *(int *)(in_r7 + 0x1c) = iVar10;
              *(int *)(in_r7 + 0x10) = iVar10;
              *(int *)(in_r7 + 0x14) = iVar10;
              *(int *)(in_r7 + 0x18) = iVar10;
              iVar16 = iVar10 * 0x28;
              iVar10 = iVar10 + 4;
            }
            else {
              iVar16 = 0;
              if (iVar26 == 0x87be) goto LAB_000728e4;
            }
            *(undefined1 *)(*(int *)(iVar15 + 0x10) + iVar16 + 0x10) = 1;
          }
          else {
            iVar26 = iVar10;
            switch(*(int *)(in_r7 + 0x48)) {
            case 0:
              iVar26 = iVar10 + 1;
              iVar10 = 0;
              iVar16 = 0;
              *(undefined1 *)(iVar15 + 0x18) = 1;
              *(undefined4 *)(iVar15 + 0x60) = 1;
              *(undefined4 *)(iVar15 + 0xb8) = 0;
              break;
            case 1:
              iVar16 = iVar10 * 0x28;
              iVar26 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 8;
              *(undefined4 *)(iVar15 + 100) = 1;
              *(int *)(((unsigned char *)0x0000139c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xbc) = iVar10;
              break;
            case 2:
              iVar18 = *(int *)(in_r7 + 0x4c);
              uVar24 = param_2[0xc];
              iVar16 = iVar10 * 0x28;
              iVar26 = iVar10 + 1;
              *(undefined1 *)((int)param_2 + iVar18 + 0x34) = 1;
              param_2[0xc] = uVar24 | 4;
              *(int *)(((unsigned char *)0x000013a0) + iVar18 * 4 + iVar15) = iVar10;
              iVar18 = (iVar18 + 10) * 4 + iVar15;
              *(undefined4 *)(iVar18 + 0x60) = 1;
              *(int *)(iVar18 + 0xb8) = iVar10;
              break;
            case 3:
              iVar16 = iVar10 * 0x28;
              iVar26 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 1;
              *(undefined4 *)(iVar15 + 0x68) = 1;
              *(int *)(((unsigned char *)0x00001388) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc0) = iVar10;
              break;
            case 4:
              iVar16 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xc4) = iVar10;
              iVar26 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x23) = 1;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              break;
            case 5:
              iVar16 = iVar10 * 0x28;
              *(int *)(iVar15 + 200) = iVar10;
              iVar26 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x24) = 1;
              *(undefined4 *)(iVar15 + 0x70) = 1;
              break;
            case 6:
              iVar16 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xcc) = iVar10;
              iVar26 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x25) = 1;
              *(undefined4 *)(iVar15 + 0x74) = 1;
              break;
            case 7:
              iVar16 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar26 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x22) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 8:
              iVar16 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd4) = iVar10;
              iVar26 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x27) = 1;
              *(undefined4 *)(iVar15 + 0x7c) = 1;
              break;
            case 9:
              iVar16 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd8) = iVar10;
              iVar26 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x28) = 1;
              *(undefined4 *)(iVar15 + 0x80) = 1;
              break;
            case 10:
              iVar16 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xdc) = iVar10;
              iVar26 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x29) = 1;
              *(undefined4 *)(iVar15 + 0x84) = 1;
              break;
            case 0xb:
              iVar16 = iVar10 * 0x28;
              *(int *)(iVar15 + 0xd0) = iVar10;
              iVar26 = iVar10 + 1;
              *(undefined1 *)(iVar15 + 0x26) = 1;
              *(undefined4 *)(iVar15 + 0x78) = 1;
              break;
            case 0xc:
              iVar18 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar26 = iVar10 + 1;
                iVar18 = iVar10;
              }
              iVar16 = iVar18 * 0x28;
              *(undefined4 *)(in_r7 + 8) = 2;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar18;
              iVar10 = iVar18;
              break;
            case 0xd:
              iVar18 = *(int *)(((unsigned char *)0x00001398) + iVar15);
              if (*(int *)(((unsigned char *)0x00001398) + iVar15) == 0) {
                *(int *)(((unsigned char *)0x00001398) + iVar15) = iVar10;
                iVar26 = iVar10 + 1;
                iVar18 = iVar10;
              }
              iVar16 = iVar18 * 0x28;
              *(undefined4 *)(in_r7 + 8) = 3;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(int *)(iVar15 + 0x100) = iVar18;
              iVar10 = iVar18;
              break;
            case 0xe:
              iVar16 = iVar10 * 0x28;
              iVar26 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 2;
              *(undefined4 *)(iVar15 + 0x6c) = 1;
              *(int *)(((unsigned char *)0x0000138c) + iVar15) = iVar10;
              *(int *)(iVar15 + 0xc4) = iVar10;
              break;
            case 0xf:
              iVar16 = iVar10 * 0x28;
              iVar26 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x40;
              *(int *)(((unsigned char *)0x00001390U) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x100) = iVar10;
              *(undefined4 *)(iVar15 + 0xa8) = 1;
              *(undefined4 *)(in_r7 + 8) = 1;
              break;
            case 0x10:
              iVar16 = iVar10 * 0x28;
              iVar26 = iVar10 + 1;
              param_2[0xc] = param_2[0xc] | 0x80;
              *(undefined4 *)(iVar15 + 0xac) = 1;
              *(int *)(((unsigned char *)0x00001394) + iVar15) = iVar10;
              *(int *)(iVar15 + 0x104) = iVar10;
              break;
            default:
              iVar16 = 0;
              iVar10 = 0;
            }
            *(int *)(in_r7 + 4) = iVar10;
            *(undefined1 *)(*(int *)(iVar15 + 0x10) + iVar16 + 0x10) = 1;
            iVar10 = iVar26;
          }
        }
      }
      uVar13 = uVar13 + 1;
    } while (uVar13 < (uint)param_2[5]);
  }
  *(int *)(iVar22 + 0x130) = iVar10;
  if (param_2[5] != 0) {
    uVar13 = 0;
    iVar10 = 0;
    do {
      iVar16 = param_2[6];
      in_r7 = *(int *)(((unsigned char *)0x0000118c) + param_1);
      iVar15 = *param_2;
      iVar26 = **(int **)(in_r7 * 4 + iVar15);
      if (*(int *)(iVar10 + iVar16 + 0x20) == 2) {
        iVar18 = param_2[8];
        iVar17 = *(int *)(iVar10 + iVar16 + 0x24) * 0x54;
        iVar14 = iVar17 + iVar18;
        if ((*(int *)(iVar14 + 0x28) == 0x87c1) &&
           ((((*(char *)(iVar14 + 0x44) == '\0' || (*(int *)(iVar14 + 0x48) == 0x12)) &&
             (iVar14 != 0)) && (*(int *)(iVar17 + iVar18) == 0)))) {
          *(undefined1 *)(iVar14 + 0x3d) = 1;
          if (*(int *)(iVar14 + 0x24) == 0x87bf) {
            iVar15 = ((int (*)())FUN_00070c70)(iVar26);
            iVar26 = iVar15 * 4 + iVar26;
            *(undefined4 *)(iVar26 + 0xb8) = *(undefined4 *)(iVar14 + 4);
            *(undefined4 *)(iVar26 + 0x60) = 1;
            uVar12 = (**(code **)(((unsigned char *)0x000012a8) + param_1))(param_1,iVar15,4);
            *(undefined4 *)(iVar17 + iVar18) = uVar12;
            in_r7 = *(int *)(((unsigned char *)0x0000118c) + param_1);
            iVar15 = *param_2;
            iVar16 = param_2[6];
          }
          else {
            in_r7 = *(int *)(((unsigned char *)0x0000118c) + param_1);
            iVar15 = *param_2;
            iVar16 = param_2[6];
          }
        }
      }
      iVar26 = **(int **)(in_r7 * 4 + iVar15);
      if (*(int *)(iVar10 + iVar16 + 0x3c) == 2) {
        iVar18 = param_2[8];
        iVar17 = *(int *)(iVar10 + iVar16 + 0x40) * 0x54;
        iVar14 = iVar17 + iVar18;
        if ((((*(int *)(iVar14 + 0x28) == 0x87c1) &&
             ((*(char *)(iVar14 + 0x44) == '\0' || (*(int *)(iVar14 + 0x48) == 0x12)))) &&
            (iVar14 != 0)) && (*(int *)(iVar17 + iVar18) == 0)) {
          *(undefined1 *)(iVar14 + 0x3d) = 1;
          if (*(int *)(iVar14 + 0x24) == 0x87bf) {
            iVar15 = ((int (*)())FUN_00070c70)(iVar26);
            iVar26 = iVar15 * 4 + iVar26;
            *(undefined4 *)(iVar26 + 0xb8) = *(undefined4 *)(iVar14 + 4);
            *(undefined4 *)(iVar26 + 0x60) = 1;
            uVar12 = (**(code **)(((unsigned char *)0x000012a8) + param_1))(param_1,iVar15,4);
            *(undefined4 *)(iVar17 + iVar18) = uVar12;
            in_r7 = *(int *)(((unsigned char *)0x0000118c) + param_1);
            iVar15 = *param_2;
            iVar16 = param_2[6];
          }
          else {
            in_r7 = *(int *)(((unsigned char *)0x0000118c) + param_1);
            iVar15 = *param_2;
            iVar16 = param_2[6];
          }
        }
      }
      iVar26 = **(int **)(in_r7 * 4 + iVar15);
      if (*(int *)(iVar10 + iVar16 + 0x58) == 2) {
        iVar15 = param_2[8];
        iVar18 = *(int *)(iVar10 + iVar16 + 0x5c) * 0x54;
        iVar16 = iVar18 + iVar15;
        if (((*(int *)(iVar16 + 0x28) == 0x87c1) &&
            ((*(char *)(iVar16 + 0x44) == '\0' || (*(int *)(iVar16 + 0x48) == 0x12)))) &&
           ((iVar16 != 0 &&
            ((*(int *)(iVar18 + iVar15) == 0 &&
             (*(undefined1 *)(iVar16 + 0x3d) = 1, *(int *)(iVar16 + 0x24) == 0x87bf)))))) {
          iVar14 = ((int (*)())FUN_00070c70)(iVar26);
          iVar26 = iVar14 * 4 + iVar26;
          *(undefined4 *)(iVar26 + 0xb8) = *(undefined4 *)(iVar16 + 4);
          *(undefined4 *)(iVar26 + 0x60) = 1;
          uVar12 = (**(code **)(((unsigned char *)0x000012a8) + param_1))(param_1,iVar14,4);
          *(undefined4 *)(iVar18 + iVar15) = uVar12;
        }
      }
      uVar13 = uVar13 + 1;
      iVar10 = iVar10 + 0x74;
    } while (uVar13 < (uint)param_2[5]);
  }
  iVar26 = 0x16;
  iVar10 = iVar22;
  do {
    if (*(int *)(iVar10 + 0x60) != -1) {
      *(int *)(iVar22 + 0x110) = *(int *)(iVar22 + 0x110) + 1;
    }
    iVar10 = iVar10 + 4;
    iVar26 = iVar26 + -1;
  } while (iVar26 != 0);
  *(undefined4 *)(iVar21 + 0x118) = 0;
  *(undefined4 *)(iVar21 + 0x120) = 0;
  if (param_2[5] != 0) {
    uVar13 = 0;
    iVar10 = 0;
    do {
      iVar22 = ((int (*)())FUN_00070520)(param_1,param_2,iVar21,iVar10 + param_2[6] + 0x20);
      if (((iVar22 == 1) ||
          (iVar22 = ((int (*)())FUN_00070520)(param_1,param_2,iVar21,iVar10 + param_2[6] + 0x3c), iVar22 == 1))
         || (iVar22 = ((int (*)())FUN_00070520)(param_1,param_2,iVar21,iVar10 + param_2[6] + 0x58), iVar22 == 1))
      {
        param_2[0x19] = 0;
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        return 0;
      }
      uVar13 = uVar13 + 1;
      iVar10 = iVar10 + 0x74;
    } while (uVar13 < (uint)param_2[5]);
  }
  uVar24 = 0;
  iVar10 = iVar21 + 0x140;
  *(undefined4 *)(iVar21 + 4) = 0;
  ((int (*)())FUN_0006fd10)(param_1,iVar10,1);
  ((int (*)())FUN_0006fd10)(param_1,iVar10,0x200);
  uVar13 = 0;
  if (*(int *)(iVar21 + 0x130) != 0) {
    do {
      ((int (*)())FUN_0006fd10)(param_1,iVar10,(uVar24 & 0x3fff) << 0x10 | 0x1a);
      uVar13 = uVar24 & 0xffff;
      uVar24 = uVar24 + 1;
      ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 | 0x50000);
      uVar13 = *(uint *)(iVar21 + 0x130);
    } while (uVar24 < uVar13);
  }
  *(uint *)(((unsigned char *)0x00001178) + iVar21) = uVar13;
  uVar13 = param_2[7];
  if (uVar13 != 0) {
    uVar24 = 0;
    iVar22 = 0;
    do {
      iVar26 = iVar22 + param_2[8];
      if ((iVar26 != 0) && (*(int *)(iVar26 + 0x28) == 0x87c3)) {
        iVar15 = *(int *)(iVar26 + 0x24);
        if (iVar15 == 0x87bf) {
          uVar13 = *(uint *)(iVar26 + 4);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(iVar22 + param_2[8] + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar22 + param_2[8] + 0x38) + 4));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar22 + param_2[8] + 0x38) + 8));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar22 + param_2[8] + 0x38) + 0xc));
          uVar13 = param_2[7];
        }
        else if (iVar15 == 0x87c0) {
          uVar13 = *(uint *)(iVar26 + 0x10);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(param_2[8] + iVar22 + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar22 + 0x38) + 4));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar22 + 0x38) + 8));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar22 + 0x38) + 0xc));
          uVar13 = *(uint *)(iVar26 + 0x14);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar22 + 0x38) + 0x10));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar22 + 0x38) + 0x14));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar22 + 0x38) + 0x18));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar22 + 0x38) + 0x1c));
          uVar13 = *(uint *)(iVar26 + 0x18);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(param_2[8] + iVar22 + 0x38) + 0x20));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar22 + param_2[8] + 0x38) + 0x24));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar22 + param_2[8] + 0x38) + 0x28));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar22 + param_2[8] + 0x38) + 0x2c));
          uVar13 = *(uint *)(iVar26 + 0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar22 + param_2[8] + 0x38) + 0x30));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar22 + param_2[8] + 0x38) + 0x34));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar22 + param_2[8] + 0x38) + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,*(undefined4 *)(*(int *)(iVar22 + param_2[8] + 0x38) + 0x3c));
          uVar13 = param_2[7];
        }
        else if (iVar15 == 0x87be) {
          uVar13 = *(uint *)(iVar26 + 4);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,0x1c);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,uVar13 & 0xffff | 0x10000);
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(iVar22 + param_2[8] + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(iVar22 + param_2[8] + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(iVar22 + param_2[8] + 0x38));
          ((int (*)())FUN_0006fd10)(param_1,iVar10,**(undefined4 **)(iVar22 + param_2[8] + 0x38));
          uVar13 = param_2[7];
        }
      }
      uVar24 = uVar24 + 1;
      iVar22 = iVar22 + 0x54;
    } while (uVar24 < uVar13);
  }
  uStack_58 = 0;
  if (param_2[5] != 0) {
    uVar13 = 0;
    iVar22 = 0;
    do {
      if (0x20 < *(int *)(iVar22 + param_2[6]) - 0x8782U) {
        param_2[0x19] = 0;
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        return 0;
      }
      ((int (*)())FUN_00070630)(param_1,param_2,iVar21,iVar22 + param_2[6] + 4);
      ((int (*)())FUN_00070630)(param_1,param_2,iVar21,iVar22 + param_2[6] + 0x20);
      ((int (*)())FUN_00070630)(param_1,param_2,iVar21,iVar22 + param_2[6] + 0x3c);
      ((int (*)())FUN_00070630)(param_1,param_2,iVar21,iVar22 + param_2[6] + 0x58);
      if (uStack_58 < (uint)param_2[0x19]) {
        uStack_58 = param_2[0x19];
      }
      iVar26 = (**(code **)(&DAT_001b9d04 + *(int *)(iVar22 + param_2[6]) * 4))
                         (param_1,iVar19,param_2,iVar22 + param_2[6],in_r7,&PTR_FUN_001dbb0c);
      if (iVar26 < 0) {
        *(undefined1 *)(param_2 + 4) = 0;
        param_2[0xc] = 0;
        param_2[0x15] = 0;
        param_2[0x16] = 0;
        param_2[0x17] = 0;
        param_2[0x18] = 0;
        param_2[0x19] = 0;
        return 0;
      }
      *(int *)(iVar21 + 4) = iVar26 + *(int *)(iVar21 + 4);
      if (*(char *)((int)param_2 + 0x7b) == '\0') {
        iVar26 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
        uVar24 = *(uint *)(iVar26 + 0x40);
        if (uVar24 != 0) {
          uVar20 = 0;
          iVar15 = 0;
          do {
            iVar16 = iVar15 + *(int *)(iVar26 + 0x3c);
            if (*(char *)(iVar16 + 0x10) != '\0') {
              iVar18 = *(int *)(iVar16 + 0x18);
              if ((((iVar18 == 0) && (*(int *)(iVar16 + 0x1c) == 0)) &&
                  ((*(int *)(iVar16 + 0x20) == 0 && (*(int *)(iVar16 + 0x24) == 0)))) ||
                 (uVar11 = param_2[5], uVar11 <= uVar13 + 1)) {
                bVar1 = true;
              }
              else {
                bVar1 = true;
                iVar14 = iVar22 + 0x74 + param_2[6];
                bVar6 = 0;
                bVar7 = 0;
                bVar8 = 0;
                bVar9 = 0;
                uVar23 = uVar13 + 1;
                do {
                  iVar17 = ((int (*)())FUN_00070bf0)(iVar14 + 0x20,iVar16);
                  if (((iVar17 == 0) && (iVar17 = ((int (*)())FUN_00070bf0)(iVar14 + 0x3c,iVar16), iVar17 == 0))
                     && (iVar17 = ((int (*)())FUN_00070bf0)(iVar14 + 0x58,iVar16), iVar17 == 0)) {
                    iVar17 = ((int (*)())FUN_00070bf0)(iVar14 + 4,iVar16);
                    if (iVar17 != 0) {
                      iVar17 = *(int *)(iVar14 + 8);
                      if (*(int *)(iVar17 * 0x54 + param_2[8] + 0x24) == 0x87be) {
                        bVar2 = iVar18 == iVar17;
                        bVar3 = iVar17 == *(int *)(iVar16 + 0x1c);
                        bVar4 = iVar17 == *(int *)(iVar16 + 0x20);
                        bVar5 = iVar17 == *(int *)(iVar16 + 0x24);
                      }
                      else {
                        bVar2 = *(byte *)(iVar14 + 0xf);
                        bVar3 = *(byte *)(iVar14 + 0x13);
                        bVar4 = *(byte *)(iVar14 + 0x17);
                        bVar5 = *(byte *)(iVar14 + 0x1b);
                      }
                      bVar6 = bVar6 | bVar2;
                      bVar7 = bVar7 | bVar3;
                      bVar8 = bVar8 | bVar4;
                      bVar9 = bVar9 | bVar5;
                      if (((bVar6 != 0) && (bVar7 != 0)) && (bVar8 != 0)) {
                        bVar25 = bVar9 != 0;
                        goto LAB_000734d0;
                      }
                    }
                    bVar25 = false;
                  }
                  else {
                    bVar1 = false;
                    bVar25 = true;
                  }
LAB_000734d0:
                  uVar23 = uVar23 + 1;
                } while ((uVar11 != uVar23) && (iVar14 = iVar14 + 0x74, !bVar25));
              }
              if (uVar20 == *(uint *)(((unsigned char *)0x000013c0) + iVar26)) {
                bVar1 = false;
              }
              if ((uVar20 != *(uint *)(((unsigned char *)0x000013cc) + iVar26)) && (bVar1)) {
                *(undefined1 *)(iVar18 * 0x54 + param_2[8] + 0x3d) = 0;
                *(undefined1 *)
                 (*(int *)(*(int *)(iVar26 + 0x3c) + iVar15 + 0x1c) * 0x54 + param_2[8] + 0x3d) = 0;
                *(undefined1 *)
                 (*(int *)(*(int *)(iVar26 + 0x3c) + iVar15 + 0x20) * 0x54 + param_2[8] + 0x3d) = 0;
                *(undefined1 *)
                 (*(int *)(*(int *)(iVar26 + 0x3c) + iVar15 + 0x24) * 0x54 + param_2[8] + 0x3d) = 0;
                *(undefined1 *)(*(int *)(iVar26 + 0x3c) + iVar15 + 0x10) = 0;
                *(undefined4 *)(*(int *)(iVar26 + 0x3c) + iVar15 + 0x14) = 0;
                *(undefined4 *)(*(int *)(iVar26 + 0x3c) + iVar15 + 0x18) = 0;
                *(undefined4 *)(*(int *)(iVar26 + 0x3c) + iVar15 + 0x1c) = 0;
                *(undefined4 *)(*(int *)(iVar26 + 0x3c) + iVar15 + 0x20) = 0;
                *(undefined4 *)(*(int *)(iVar26 + 0x3c) + iVar15 + 0x24) = 0;
                param_2[0x19] = param_2[0x19] + -1;
                uVar24 = *(uint *)(iVar26 + 0x40);
              }
            }
            uVar20 = uVar20 + 1;
            iVar15 = iVar15 + 0x28;
          } while (uVar20 < uVar24);
        }
      }
      uVar13 = uVar13 + 1;
      iVar22 = iVar22 + 0x74;
    } while (uVar13 < (uint)param_2[5]);
  }
  if (*(char *)((int)param_2 + 0x7a) != '\0') {
    bVar1 = (*(uint *)(param_1 + 0x44) & 0x2800) != 0x2800;
    if (bVar1) {
      ((unsigned char *)0x000013c8)[iVar21] = 1;
    }
    else {
      ((unsigned char *)0x000013c9)[iVar21] = ((unsigned char *)0x000011d1)[param_1];
      *(byte *)((int)param_2 + (byte)((unsigned char *)0x000011d1)[param_1] + 0x71) =
           *(byte *)((int)param_2 + (byte)((unsigned char *)0x000011d1)[param_1] + 0x71) | 1;
      ((unsigned char *)0x000013c8)[iVar21] = 0;
    }
    if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
      uVar12 = 1;
    }
    else {
      uVar12 = 0;
      if (bVar1) goto LAB_000736b0;
    }
    iVar22 = *(int *)(iVar21 + 0x4c);
    *(int *)(((unsigned char *)0x000013c4) + iVar21) = iVar22;
    *(int *)(iVar21 + 0x4c) = iVar22 + 1;
    ((int (*)())FUN_00070d80)(param_1,iVar19,iVar21,uVar12);
  }
LAB_000736b0:
  ((int (*)())FUN_0006fd10)(param_1,iVar10,0x28);
  param_2[0x15] = *(int *)(iVar21 + 4);
  param_2[0x19] = uStack_58;
  if (*(int *)(iVar21 + 0x118) != 0) {
    uVar12 = (**(code **)(param_1 + 0xc))(*(int *)(iVar21 + 0x118) << 2);
    *(undefined4 *)(iVar21 + 0x114) = uVar12;
    uVar13 = param_2[7];
    if (uVar13 != 0) {
      uVar24 = 0;
      iVar10 = 0;
      iVar22 = 0;
      do {
        iVar26 = iVar22 + param_2[8];
        if (*(char *)(iVar26 + 0x3d) != '\0') {
          if (*(int *)(iVar26 + 0x28) == 0x87c2) {
            if (*(char *)(iVar26 + 0x44) == '\0') {
LAB_00073754:
              iVar26 = iVar10 * 4;
              iVar10 = iVar10 + 1;
              *(uint *)(iVar26 + *(int *)(iVar21 + 0x114)) = uVar24;
              uVar13 = param_2[7];
            }
          }
          else if (*(int *)(iVar26 + 0x28) == 0x87c3) goto LAB_00073754;
        }
        uVar24 = uVar24 + 1;
        iVar22 = iVar22 + 0x54;
      } while (uVar24 < uVar13);
    }
  }
  if (*(int *)(iVar21 + 0x4c) != 0) {
    uVar12 = (**(code **)(param_1 + 0xc))(*(int *)(iVar21 + 0x4c) * 0x10 + 0x10);
    *(undefined4 *)(iVar21 + 0x124) = uVar12;
    *(undefined4 *)(((unsigned char *)0x00001174) + iVar21) = *(undefined4 *)(iVar21 + 0x4c);
  }
  *(undefined1 *)(iVar21 + 0x36) = *(undefined1 *)((int)param_2 + 0x79);
  iVar19 = (**(code **)(((unsigned char *)0x0000128c) + param_1))(param_1,iVar19);
  if (iVar19 != 0) {
    *(undefined1 *)(param_2 + 4) = 0;
  }
  (**(code **)(((unsigned char *)0x000012b8) + param_1))(param_1,param_2);
  *(undefined1 *)(param_1 + 0x29) = 1;
  ((int (*)())FUN_00076b80)(param_1,param_2);
  *(undefined1 *)(param_2[1] + *(int *)(((unsigned char *)0x0000118c) + param_1)) = 0;
  if (*(int *)(((unsigned char *)0x000013d8) + iVar21) != 0) {
    (**(code **)(param_1 + 0x18))(*(int *)(((unsigned char *)0x000013d8) + iVar21));
    *(undefined4 *)(((unsigned char *)0x000013d8) + iVar21) = 0;
  }
  return *(undefined1 *)(param_2 + 4);
}

/* FUN_000738c0 @ 0x738c0 (2852 bytes) */
int FUN_000738c0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint *param_2;
  int param_3;
  int *param_4;
  int param_5;
  uint *param_6;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined *puVar8;
  uint uVar9;
  undefined *puVar10;
  
  puVar8 = ((unsigned char *)0x00003210);
  switch(param_4[2]) {
  case 0x87d9:
    puVar8 = ((unsigned char *)0x00003218);
  case 0x87d5:
    break;
  case 0x87da:
    puVar8 = ((unsigned char *)0x00003218);
  case 0x87d6:
    puVar8 = (undefined *)((uint)puVar8 | 1);
    break;
  case 0x87db:
    puVar8 = ((unsigned char *)0x00003218);
  case 0x87d7:
    puVar8 = (undefined *)((uint)puVar8 | 2);
    break;
  case 0x87dc:
    puVar8 = ((unsigned char *)0x00003218);
  case 0x87d8:
    puVar8 = (undefined *)((uint)puVar8 | 3);
    break;
  case 0x87dd:
    puVar8 = ((unsigned char *)0x00003214);
    break;
  case 0x87de:
    puVar8 = ((unsigned char *)0x00003215);
  }
  switch(param_4[3]) {
  case 0x87d9:
    puVar8 = (undefined *)((uint)puVar8 | 0x80);
  case 0x87d5:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f);
    break;
  case 0x87da:
    puVar8 = (undefined *)((uint)puVar8 | 0x80);
  case 0x87d6:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f | 0x10);
    break;
  case 0x87db:
    puVar8 = (undefined *)((uint)puVar8 | 0x80);
  case 0x87d7:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f | 0x20);
    break;
  case 0x87dc:
    puVar8 = (undefined *)((uint)puVar8 | 0x80);
  case 0x87d8:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f | 0x30);
    break;
  case 0x87dd:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f | 0x40);
    break;
  case 0x87de:
    puVar8 = (undefined *)((uint)puVar8 & 0xffffff8f | 0x50);
  }
  switch(param_4[4]) {
  case 0x87d9:
    puVar8 = (undefined *)((uint)puVar8 | 0x800);
  case 0x87d5:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff);
    break;
  case 0x87da:
    puVar8 = (undefined *)((uint)puVar8 | 0x800);
  case 0x87d6:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff | 0x100);
    break;
  case 0x87db:
    puVar8 = (undefined *)((uint)puVar8 | 0x800);
  case 0x87d7:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff | 0x200);
    break;
  case 0x87dc:
    puVar8 = (undefined *)((uint)puVar8 | 0x800);
  case 0x87d8:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff | 0x300);
    break;
  case 0x87dd:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff | 0x400);
    break;
  case 0x87de:
    puVar8 = (undefined *)((uint)puVar8 & 0xfffff8ff | 0x500);
  }
  switch(param_4[5]) {
  case 0x87d9:
    puVar8 = (undefined *)((uint)puVar8 | 0x8000);
  case 0x87d5:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff);
    break;
  case 0x87da:
    puVar8 = (undefined *)((uint)puVar8 | 0x8000);
  case 0x87d6:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x1000);
    break;
  case 0x87db:
    puVar8 = (undefined *)((uint)puVar8 | 0x8000);
  case 0x87d7:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x2000);
    break;
  case 0x87dc:
    puVar8 = (undefined *)((uint)puVar8 | 0x8000);
  case 0x87d8:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x3000);
    break;
  case 0x87dd:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x4000);
    break;
  case 0x87de:
    puVar8 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x5000);
  }
  if (param_6 != (uint *)0x0) {
    uVar9 = *param_6;
    uVar2 = uVar9 & 3;
    if (uVar2 == 2) {
      puVar8 = (undefined *)((uint)puVar8 >> 8 & 7 | (uint)puVar8 & 0xfffffff8);
    }
    else if (uVar2 == 3) {
      puVar8 = (undefined *)((uint)puVar8 >> 0xc & 7 | (uint)puVar8 & 0xfffffff8);
    }
    else if (uVar2 == 1) {
      puVar8 = (undefined *)((uint)puVar8 >> 4 & 7 | (uint)puVar8 & 0xfffffff8);
    }
    uVar6 = param_6[1];
    uVar2 = uVar6 & 3;
    if (uVar2 != 1) {
      if (uVar2 == 0) {
        puVar8 = (undefined *)(((uint)puVar8 & 7) << 4 | (uint)puVar8 & 0xffffff8f);
      }
      else if (uVar2 == 2) {
        puVar8 = (undefined *)((uint)puVar8 >> 4 & 0x70 | (uint)puVar8 & 0xffffff8f);
      }
      else if (uVar2 == 3) {
        puVar8 = (undefined *)((uint)puVar8 >> 8 & 0x70 | (uint)puVar8 & 0xffffff8f);
      }
    }
    uVar1 = param_6[2];
    uVar2 = uVar1 & 3;
    if (uVar2 == 1) {
      puVar8 = (undefined *)(((uint)puVar8 & 0x70) << 4 | (uint)puVar8 & 0xfffff8ff);
    }
    else if (uVar2 == 0) {
      puVar8 = (undefined *)(((uint)puVar8 & 7) << 8 | (uint)puVar8 & 0xfffff8ff);
    }
    else if ((uVar2 != 2) && (uVar2 == 3)) {
      puVar8 = (undefined *)((uint)puVar8 >> 4 & 0x700 | (uint)puVar8 & 0xfffff8ff);
    }
    uVar5 = param_6[3];
    uVar2 = uVar5 & 3;
    if (uVar2 == 1) {
      puVar8 = (undefined *)(((uint)puVar8 & 0x70) << 8 | (uint)puVar8 & 0xffff8fff);
    }
    else if (uVar2 == 0) {
      puVar8 = (undefined *)(((uint)puVar8 & 7) << 0xc | (uint)puVar8 & 0xffff8fff);
    }
    else if (uVar2 == 2) {
      puVar8 = (undefined *)(((uint)puVar8 & 0x700) << 4 | (uint)puVar8 & 0xffff8fff);
    }
    if ((uVar9 & 4) != 0) {
      puVar8 = (undefined *)(((uint)puVar8 ^ 8) & 8 | (uint)puVar8 & 0xfffffff7);
    }
    if ((uVar6 & 4) != 0) {
      puVar8 = (undefined *)(((uint)puVar8 ^ 0x80) & 0x80 | (uint)puVar8 & 0xffffff7f);
    }
    if ((uVar1 & 4) != 0) {
      puVar8 = (undefined *)(((uint)puVar8 ^ 0x800) & 0x800 | (uint)puVar8 & 0xfffff7ff);
    }
    if ((uVar5 & 4) != 0) {
      puVar8 = (undefined *)(((uint)puVar8 ^ 0x8000) & 0x8000 | (uint)puVar8 & 0xffff7fff);
    }
    if ((uVar9 & 8) != 0) {
      puVar8 = (undefined *)((uint)puVar8 & 0xffff7777 | 0x100000);
    }
    if ((uVar6 & 8) != 0) {
      puVar8 = (undefined *)((uint)puVar8 & 0xffff7777 | 0x100000);
    }
    if ((uVar1 & 8) != 0) {
      puVar8 = (undefined *)((uint)puVar8 & 0xffff7777 | 0x100000);
    }
    if ((uVar5 & 8) != 0) {
      puVar8 = (undefined *)((uint)puVar8 & 0xffff7777 | 0x100000);
    }
  }
  puVar10 = puVar8;
  if (*param_4 != 2) {
    if (*param_4 != 0) {
      return 0;
    }
    uVar2 = 0x40000;
    goto LAB_00074014;
  }
  iVar4 = param_4[1] * 0x54 + *(int *)(param_3 + 0x20);
  uVar2 = *(uint *)(iVar4 + 0x28);
  iVar7 = *(int *)(iVar4 + 0x24);
  if (uVar2 < 0x87c4) {
    if (uVar2 < 0x87c2) {
      if (uVar2 != 0x87c1) {
        return 0;
      }
      if (iVar7 == 0x87bf) {
        uVar2 = *(uint *)(iVar4 + 4) & 0xffff | 0x50000;
        if ((*(char *)(iVar4 + 0x44) != '\0') && (*(int *)(iVar4 + 0x48) == 1)) {
          puVar10 = (undefined *)((uint)puVar8 & 0xffff8fff | 0x4000);
        }
      }
      else if (iVar7 == 0x87c0) {
        uVar2 = *(uint *)(iVar4 + 0x10) & 0xffff | 0x50000;
      }
      else {
        if (iVar7 != 0x87be) {
          return 0;
        }
        uVar9 = *(uint *)(iVar4 + 8);
        uVar2 = *(uint *)(iVar4 + 4) & 0xffff | 0x50000;
        puVar10 = (undefined *)
                  ((uVar9 & 7) << 0xc |
                  (uVar9 & 7) << 8 | (uVar9 & 7) << 4 | uVar9 & 7 | (uint)puVar8 & 0xffff8888);
        if ((*(char *)(iVar4 + 0x44) != '\0') && (*(int *)(iVar4 + 0x48) == 0xf)) {
          puVar10 = (undefined *)((uint)puVar8 & 0xffff8888 | 0x5441);
        }
      }
      goto LAB_00074014;
    }
    if (iVar7 == 0x87bf) {
      uVar2 = *(uint *)(iVar4 + 4) & 0xffff | 0x10000;
      goto LAB_00074014;
    }
    if (iVar7 == 0x87c0) {
      uVar2 = *(uint *)(iVar4 + 0x10) & 0xffff | 0x10000;
      goto LAB_00074014;
    }
    if (iVar7 != 0x87be) {
      return 0;
    }
    uVar9 = *(uint *)(iVar4 + 8);
    uVar2 = *(uint *)(iVar4 + 4);
    iVar4 = 1;
  }
  else {
    if (uVar2 != 0x87c4) {
      return 0;
    }
    if (iVar7 == 0x87bf) {
      uVar2 = *(uint *)(iVar4 + 4) & 0xffff | 0x40000;
      goto LAB_00074014;
    }
    if (iVar7 == 0x87c0) {
      uVar2 = *(uint *)(iVar4 + 0x10) & 0xffff | 0x40000;
      goto LAB_00074014;
    }
    if (iVar7 != 0x87be) {
      return 0;
    }
    uVar9 = *(uint *)(iVar4 + 8);
    uVar2 = *(uint *)(iVar4 + 4);
    iVar4 = 4;
  }
  uVar2 = uVar2 & 0xffff | iVar4 << 0x10;
  puVar10 = (undefined *)
            ((uVar9 & 7) << 0xc |
            (uVar9 & 7) << 8 | (uVar9 & 7) << 4 | uVar9 & 7 | (uint)puVar8 & 0xffff8888);
LAB_00074014:
  if ((param_5 == 0) && (puVar10 == ((unsigned char *)0x00003210))) {
    if (*(char *)(param_4 + 6) == '\0') {
      uVar9 = *param_2;
      if (param_2[1] <= uVar9) {
        uVar9 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if (param_2[2] != 0) {
          _memcpy(uVar9,param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = uVar9;
        uVar9 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      uVar3 = 1;
      *(uint *)(uVar9 * 4 + param_2[2]) = uVar2;
      *param_2 = *param_2 + 1;
    }
    else {
      uVar9 = *param_2;
      if (param_2[1] <= uVar9) {
        uVar9 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if (param_2[2] != 0) {
          _memcpy(uVar9,param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = uVar9;
        uVar9 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(uint *)(uVar9 * 4 + param_2[2]) = uVar2 | 0x800000;
      uVar2 = *param_2 + 1;
      *param_2 = uVar2;
      if (param_2[1] <= uVar2) {
        uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if (param_2[2] != 0) {
          _memcpy(uVar2,param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = uVar2;
        uVar2 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      uVar3 = 2;
      *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0;
      *param_2 = *param_2 + 1;
    }
  }
  else if (*(char *)(param_4 + 6) == '\0') {
    uVar9 = *param_2;
    if (param_2[1] <= uVar9) {
      uVar9 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar9,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar9;
      uVar9 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(uVar9 * 4 + param_2[2]) = uVar2 | 0x400000;
    uVar2 = *param_2 + 1;
    *param_2 = uVar2;
    if (param_2[1] <= uVar2) {
      uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar2,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar2;
      uVar2 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar3 = 2;
    *(undefined **)(uVar2 * 4 + param_2[2]) = puVar10;
    *param_2 = *param_2 + 1;
  }
  else {
    uVar9 = *param_2;
    if (param_2[1] <= uVar9) {
      uVar9 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar9,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar9;
      uVar9 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(uVar9 * 4 + param_2[2]) = uVar2 | 0xc00000;
    uVar2 = *param_2 + 1;
    *param_2 = uVar2;
    if (param_2[1] <= uVar2) {
      uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar2,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar2;
      uVar2 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(undefined **)(uVar2 * 4 + param_2[2]) = puVar10;
    uVar2 = *param_2 + 1;
    *param_2 = uVar2;
    if (param_2[1] <= uVar2) {
      uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar2,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar2;
      uVar2 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar3 = 3;
    *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0;
    *param_2 = *param_2 + 1;
  }
  return uVar3;
}

/* FUN_000744d0 @ 0x744d0 (1412 bytes) */
int FUN_000744d0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  int *param_3;
  int *param_4;
  int param_5;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0x55;
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_3);
  if (param_4[2] == 0) {
    uVar5 = 0x54;
  }
  iVar2 = param_4[3];
  if (iVar2 == 0) {
    uVar5 = uVar5 & 0xfffffff3;
  }
  if (param_4[4] == 0) {
    uVar5 = uVar5 & 0xffffffcf;
  }
  if (param_4[5] == 0) {
    uVar5 = uVar5 & 0xffffff3f;
  }
  if (*param_4 == 1) {
    uVar3 = param_4[1];
    if (uVar3 == 0x879b) {
      uVar5 = uVar5 | 0x100;
      *(undefined1 *)((int)param_3 + 0x6d) = 1;
      uVar6 = 0x120000;
    }
    else if (uVar3 < 0x879c) {
      if (uVar3 == 0x610f) {
        uVar5 = uVar5 | 0x100;
        *(undefined1 *)((int)param_3 + 0x6f) = 1;
        uVar6 = 0x120001;
      }
      else if (uVar3 < 0x6110) {
        if (uVar3 != 0x610e) {
          return 0;
        }
        *(undefined1 *)((int)param_3 + 0x79) = 1;
        uVar6 = 0xd0000;
        uVar5 = uVar5 & 0xffffff03;
      }
      else if (uVar3 == 0x6110) {
        uVar5 = uVar5 | 0x100;
        *(undefined1 *)(param_3 + 0x1c) = 1;
        uVar6 = 0x130001;
      }
      else {
        if (uVar3 != 0x879a) {
          return 0;
        }
        uVar6 = 0xe0000;
      }
    }
    else if (uVar3 < 0x87a5) {
      if (uVar3 < 0x879d) {
        uVar5 = uVar5 | 0x100;
        *(undefined1 *)((int)param_3 + 0x6e) = 1;
        uVar6 = 0x130000;
      }
      else {
        uVar6 = uVar3 + 0x7863 & 0xffff | 0x110000;
        if (param_4[2] == 1) {
          *(byte *)((int)param_3 + (uVar3 - 0x872c)) =
               *(byte *)((int)param_3 + (uVar3 - 0x872c)) | 1;
          iVar2 = param_4[3];
        }
        if (iVar2 == 1) {
          *(byte *)((int)param_3 + param_4[1] + -0x872c) =
               *(byte *)((int)param_3 + param_4[1] + -0x872c) | 2;
        }
        if (param_4[4] == 1) {
          *(byte *)((int)param_3 + param_4[1] + -0x872c) =
               *(byte *)((int)param_3 + param_4[1] + -0x872c) | 4;
        }
        if (param_4[5] == 1) {
          *(byte *)((int)param_3 + param_4[1] + -0x872c) =
               *(byte *)((int)param_3 + param_4[1] + -0x872c) | 8;
        }
      }
    }
    else {
      if (uVar3 != 0x87bd) {
        return 0;
      }
      uVar3 = *(uint *)(((unsigned char *)0x000013c0) + iVar4);
      *(undefined1 *)((int)param_3 + 0x7a) = 1;
      *(undefined1 *)(iVar4 + 0x33) = 1;
      uVar6 = uVar3 & 0xffff | 0x40000;
      uVar5 = uVar5 & 0xffffff03;
    }
  }
  else {
    if (*param_4 != 2) {
      return 0;
    }
    iVar4 = param_4[1] * 0x54 + param_3[8];
    iVar2 = *(int *)(iVar4 + 0x24);
    if (*(int *)(iVar4 + 0x28) == 0x87c4) {
      if (iVar2 == 0x87bf) {
        uVar6 = *(uint *)(iVar4 + 4) & 0xffff | 0x40000;
      }
      else if (iVar2 == 0x87c0) {
        uVar6 = *(uint *)(iVar4 + 0x10) & 0xffff | 0x40000;
      }
      else {
        if (iVar2 != 0x87be) {
          return 0;
        }
        iVar2 = *(int *)(iVar4 + 8);
        uVar6 = *(uint *)(iVar4 + 4) & 0xffff | 0x40000;
        if (iVar2 == 1) {
          uVar5 = uVar5 & 0xffffff0c;
        }
        else if (iVar2 == 0) {
          uVar5 = uVar5 & 0xffffff03;
        }
        else if (iVar2 == 2) {
          uVar5 = uVar5 & 0xffffff30;
        }
        else {
          if (iVar2 != 3) {
            return 0;
          }
          uVar5 = uVar5 & 0xffffffc0;
        }
      }
    }
    else {
      if (*(int *)(iVar4 + 0x28) != -1) {
        return 0;
      }
      uVar6 = 0x30000;
    }
  }
  if ((param_5 == 0) && (uVar5 == 0x55)) {
    uVar5 = *param_2;
    if (param_2[1] <= uVar5) {
      uVar5 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar5,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar5;
      uVar5 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar1 = 1;
    *(uint *)(uVar5 * 4 + param_2[2]) = uVar6;
    *param_2 = *param_2 + 1;
  }
  else {
    uVar3 = *param_2;
    if (param_2[1] <= uVar3) {
      uVar3 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar3,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar3;
      uVar3 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    *(uint *)(uVar3 * 4 + param_2[2]) = uVar6 | 0x400000;
    uVar3 = *param_2 + 1;
    *param_2 = uVar3;
    if (param_2[1] <= uVar3) {
      uVar3 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
      if (param_2[2] != 0) {
        _memcpy(uVar3,param_2[2],*param_2 << 2);
        (**(code **)(param_1 + 0x18))(param_2[2]);
      }
      param_2[2] = uVar3;
      uVar3 = *param_2;
      param_2[1] = param_2[1] + 0x80;
    }
    uVar1 = 2;
    *(uint *)(uVar3 * 4 + param_2[2]) = uVar5;
    *param_2 = *param_2 + 1;
  }
  return uVar1;
}

/* FUN_00074a70 @ 0x74a70 (192 bytes) */
int FUN_00074a70(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  uint param_3;
  uint param_4;
{
  uint uVar1;
  
  uVar1 = *param_2;
  if (param_2[1] <= uVar1) {
    uVar1 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if (param_2[2] != 0) {
      _memcpy(uVar1,param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = uVar1;
    uVar1 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar1 * 4 + param_2[2]) = (param_4 & 0x3fff) << 0x10 | param_3 & 0xffff;
  *param_2 = *param_2 + 1;
  return 1;
}

/* FUN_00074b30 @ 0x74b30 (204 bytes) */
int FUN_00074b30(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x48,0);
  if (iVar1 != 0) {
    local_48 = *(undefined4 *)(param_4 + 4);
    local_44 = *(undefined4 *)(param_4 + 8);
    local_30 = *(undefined4 *)(param_4 + 0x1c);
    local_34 = 0;
    local_3c = 0;
    local_38 = 0;
    local_40 = 1;
    iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,&local_48,1);
    if ((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)
       ) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* FUN_00074c00 @ 0x74c00 (188 bytes) */
int FUN_00074c00(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x3d,0);
  if ((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) {
    uStack_2c = 4;
    uStack_34 = 4;
    uStack_30 = 4;
    uStack_38 = 0xc;
    iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,1,&uStack_38);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* FUN_00074cc0 @ 0x74cc0 (156 bytes) */
int FUN_00074cc0(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x2e,0);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,1,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00074d60 @ 0x74d60 (204 bytes) */
int FUN_00074d60(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x24,0);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00074e30 @ 0x74e30 (156 bytes) */
int FUN_00074e30(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x39,0);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00074ed0 @ 0x74ed0 (392 bytes) */
int FUN_00074ed0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  iVar1 = FUN_000550e0(param_3 + 0x1c,param_4 + 4);
  uVar4 = *(uint *)(param_4 + 0x40);
  if (3 < uVar4) {
    return 0xffffffff;
  }
  iVar3 = param_2 + 4;
  iVar2 = ((int (*)())FUN_00074a70)(param_1,iVar3,0x47,0);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  iVar2 = ((int (*)())FUN_000744d0)(param_1,iVar3,param_3,param_4 + 4,0);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  uStack_30 = *(undefined4 *)(param_4 + 0x38);
  uStack_48 = *(undefined4 *)(param_4 + 0x20);
  iStack_44 = *(int *)(param_4 + 0x24);
  uStack_3c = *(undefined4 *)(param_4 + 0x2c);
  uStack_38 = *(undefined4 *)(param_4 + 0x30);
  uStack_34 = *(undefined4 *)(param_4 + 0x34);
  uStack_40 = *(undefined4 *)(param_4 + 0x28);
  if (iVar1 != 0x87be) {
    iStack_44 = uVar4 + iStack_44;
    iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar3,param_3,&uStack_48,1,0);
    goto LAB_00075028;
  }
  if (uVar4 == 1) {
LAB_00074fd4:
    uStack_58 = uVar4;
    uStack_54 = uVar4;
    uStack_50 = uVar4;
    uStack_4c = uVar4;
  }
  else if (uVar4 == 0) {
    uStack_4c = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    uStack_50 = 0;
  }
  else if ((uVar4 == 2) || (uVar4 == 3)) goto LAB_00074fd4;
  iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar3,param_3,&uStack_48,1,&uStack_58);
LAB_00075028:
  if (iVar1 == 0) {
    return 0xffffffff;
  }
  return 1;
}

/* FUN_00075060 @ 0x75060 (584 bytes) */
int FUN_00075060(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  iVar1 = FUN_000550e0(param_3 + 0x1c,param_4 + 4);
  uVar4 = *(uint *)(param_4 + 0x40);
  if (3 < uVar4) {
    return 0xffffffff;
  }
  iVar3 = param_2 + 4;
  iVar2 = ((int (*)())FUN_00074a70)(param_1,iVar3,0x47,0);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (iVar1 == 0x87bf) {
    uStack_48 = *(uint *)(param_4 + 4);
    uStack_44 = *(uint *)(param_4 + 8);
    uStack_40 = *(uint *)(param_4 + 0xc);
    uStack_3c = *(uint *)(param_4 + 0x10);
    uStack_38 = *(undefined4 *)(param_4 + 0x14);
    uStack_34 = *(undefined4 *)(param_4 + 0x18);
    uStack_30 = *(undefined4 *)(param_4 + 0x1c);
    if (uVar4 == 1) {
      uStack_34 = 0;
      uStack_40 = 0;
      uStack_38 = 0;
    }
    else if (uVar4 == 0) {
      uStack_34 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
    }
    else if (uVar4 == 2) {
      uStack_34 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
    }
    else if (uVar4 == 3) {
      uStack_38 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
    }
    iVar2 = ((int (*)())FUN_000744d0)(param_1,iVar3,param_3,&uStack_48,1);
  }
  else {
    uStack_48 = *(uint *)(param_4 + 4);
    uStack_40 = *(uint *)(param_4 + 0xc);
    uStack_3c = *(uint *)(param_4 + 0x10);
    uStack_38 = *(undefined4 *)(param_4 + 0x14);
    uStack_34 = *(undefined4 *)(param_4 + 0x18);
    uStack_30 = *(undefined4 *)(param_4 + 0x1c);
    uStack_44 = uVar4 + *(int *)(param_4 + 8);
    iVar2 = ((int (*)())FUN_000744d0)(param_1,iVar3,param_3,&uStack_48,1);
  }
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (iVar1 != 0x87bf) {
    ((int (*)())FUN_000738c0)(param_1,iVar3,param_3,param_4 + 0x20,1,0);
    return 1;
  }
  if (uVar4 != 1) {
    if (uVar4 == 0) {
      uStack_3c = 0;
      uStack_48 = 0;
      uStack_44 = 0;
      uStack_40 = 0;
      goto LAB_00075258;
    }
    if ((uVar4 != 2) && (uVar4 != 3)) goto LAB_00075258;
  }
  uStack_48 = uVar4;
  uStack_44 = uVar4;
  uStack_40 = uVar4;
  uStack_3c = uVar4;
LAB_00075258:
  ((int (*)())FUN_000738c0)(param_1,iVar3,param_3,param_4 + 0x20,1,&uStack_48);
  return 1;
}

/* FUN_000752c0 @ 0x752c0 (156 bytes) */
int FUN_000752c0(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x47,0);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,1), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075360 @ 0x75360 (156 bytes) */
int FUN_00075360(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x47,0);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075400 @ 0x75400 (156 bytes) */
int FUN_00075400(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x47,0);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000754a0 @ 0x754a0 (204 bytes) */
int FUN_000754a0(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x45,0);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075570 @ 0x75570 (204 bytes) */
int FUN_00075570(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x13,0);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075640 @ 0x75640 (204 bytes) */
int FUN_00075640(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x5b,0);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075710 @ 0x75710 (156 bytes) */
int FUN_00075710(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x55,3);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000757b0 @ 0x757b0 (156 bytes) */
int FUN_000757b0(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x51,3);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075850 @ 0x75850 (204 bytes) */
int FUN_00075850(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x4e,0);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075920 @ 0x75920 (156 bytes) */
int FUN_00075920(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x3c,0);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000759c0 @ 0x759c0 (156 bytes) */
int FUN_000759c0(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x2d,0);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075a60 @ 0x75a60 (156 bytes) */
int FUN_00075a60(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x54,0);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075b00 @ 0x75b00 (156 bytes) */
int FUN_00075b00(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x30,0);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075ba0 @ 0x75ba0 (236 bytes) */
int FUN_00075ba0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,10,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     ((iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0 &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x58,0,0), iVar1 != 0)))) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075c90 @ 0x75c90 (204 bytes) */
int FUN_00075c90(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x56,5);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075d60 @ 0x75d60 (204 bytes) */
int FUN_00075d60(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x56,2);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075e30 @ 0x75e30 (204 bytes) */
int FUN_00075e30(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x44,0);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075f00 @ 0x75f00 (204 bytes) */
int FUN_00075f00(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x41,0);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00075fd0 @ 0x75fd0 (156 bytes) */
int FUN_00075fd0(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x31,0);
  if (((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00076070 @ 0x76070 (236 bytes) */
int FUN_00076070(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x40,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     ((iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0 &&
      (iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x58,0,0), iVar1 != 0)))) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00076160 @ 0x76160 (204 bytes) */
int FUN_00076160(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,3,0);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00076230 @ 0x76230 (204 bytes) */
int FUN_00076230(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x49,0);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_00076300 @ 0x76300 (204 bytes) */
int FUN_00076300(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x23,0);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000763d0 @ 0x763d0 (204 bytes) */
int FUN_000763d0(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())FUN_00074a70)(compiler,code,0x22,0);
  if ((((emitted != 0) && (emitted = ((int (*)())FUN_000744d0)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())FUN_000738c0)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* FUN_000764a0 @ 0x764a0 (188 bytes) */
int FUN_000764a0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())FUN_00074a70)(param_1,iVar2,0x47,0);
  if ((iVar1 != 0) && (iVar1 = ((int (*)())FUN_000744d0)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) {
    uStack_38 = 4;
    uStack_34 = 5;
    uStack_30 = 6;
    uStack_2c = 7;
    iVar1 = ((int (*)())FUN_000738c0)(param_1,iVar2,param_3,param_4 + 0x20,1,&uStack_38);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* FUN_00076560 @ 0x76560 (524 bytes) */
int FUN_00076560(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)(param_2 + 4);
  iVar1 = ((int (*)())FUN_00074a70)(param_1,puVar4,0x48,0);
  if (iVar1 != 0) {
    if (*(uint *)(param_2 + 8) <= *(uint *)(param_2 + 4)) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar2,*(int *)(param_2 + 0xc),*(int *)(param_2 + 4) << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar2;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(*puVar4 * 4 + *(int *)(param_2 + 0xc)) = 0x430000;
    uVar3 = *puVar4 + 1;
    *puVar4 = uVar3;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      uVar2 = (**(code **)(param_1 + 0xc))(*(uint *)(param_2 + 8) * 4 + 0x200);
      if (*(int *)(param_2 + 0xc) != 0) {
        _memcpy(uVar2,*(int *)(param_2 + 0xc),*puVar4 << 2);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(param_2 + 0xc));
      }
      *(undefined4 *)(param_2 + 0xc) = uVar2;
      uVar3 = *puVar4;
      *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 0x80;
    }
    *(undefined4 *)(uVar3 * 4 + *(int *)(param_2 + 0xc)) = 1;
    *puVar4 = *puVar4 + 1;
    iVar1 = ((int (*)())FUN_000738c0)(param_1,puVar4,param_3,param_4 + 0x20,0,0);
    if (iVar1 != 0) {
      ((int (*)())FUN_00074a70)(param_1,puVar4,0x47,0);
      iVar1 = ((int (*)())FUN_000744d0)(param_1,puVar4,param_3,param_4 + 4,0);
      if (iVar1 != 0) {
        *(undefined1 *)(param_4 + 0x54) = 1;
        iVar1 = ((int (*)())FUN_000738c0)(param_1,puVar4,param_3,param_4 + 0x3c,0,0);
        if (iVar1 != 0) {
          return 1;
        }
      }
    }
  }
  return 0xffffffff;
}

/* FUN_00076770 @ 0x76770 (352 bytes) */
int FUN_00076770(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int *param_3;
{
  short sVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_3);
  if (*(int *)(iVar4 + 0x4c) == 0) {
    return;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(char *)((int)param_3 + 0x7a) != '\0') && (((unsigned char *)0x00002e0a)[iVar3] != '\0')) {
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar3);
    iVar6 = *(int *)(((unsigned char *)0x000013c4) + iVar4);
    if (sVar1 == 0x801) {
      fVar5 = 0.0;
      fVar2 = -(*(float *)(((unsigned char *)0x00002df0) + iVar3) * *(float *)(((unsigned char *)0x00002df0) + iVar3));
    }
    else if (sVar1 == 0x2601) {
      fVar5 = *(float *)(((unsigned char *)0x00002dfc) + iVar3) * *(float *)(((unsigned char *)0x00002df8) + iVar3);
      fVar2 = -*(float *)(((unsigned char *)0x00002dfc) + iVar3);
    }
    else {
      fVar5 = FLOAT_001aa0d4;
      fVar2 = FLOAT_001aa0d4;
      if (sVar1 == 0x800) {
        fVar5 = 0.0;
        fVar2 = -*(float *)(((unsigned char *)0x00002df0) + iVar3);
      }
    }
    iVar3 = iVar6 * 0x10;
    iVar7 = iVar3 + iVar4;
    *(undefined4 *)(*(int *)(iVar4 + 0x124) + iVar3) = 0;
    *(float *)(iVar3 + *(int *)(iVar4 + 0x124) + 4) = fVar5;
    *(float *)(iVar3 + *(int *)(iVar4 + 0x124) + 8) = fVar2;
    *(undefined4 *)(iVar3 + *(int *)(iVar4 + 0x124) + 0xc) = 0;
    *(undefined4 *)(iVar7 + 0x160) = 0;
    *(float *)(iVar7 + 0x158) = fVar5;
    *(float *)(iVar7 + 0x15c) = fVar2;
    *(undefined4 *)(iVar7 + 0x154) = 0;
    if (*(int *)(((unsigned char *)0x0000137c) + iVar4) < iVar6) {
      *(int *)(((unsigned char *)0x0000137c) + iVar4) = iVar6;
    }
  }
                    
                    
  (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1,iVar4 + 0x13c);
  return;
}

/* FUN_000768e0 @ 0x768e0 (384 bytes) */
int FUN_000768e0(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  uint uVar2;
  uint loopIndex;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  
  if (*param_2 != 0) {
    iVar9 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
    if ((*(char *)(param_2 + 4) != '\0') && ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0)) {
      iVar8 = iVar9 + 0x13c;
      if (iVar8 == *(int *)(((unsigned char *)0x0000148c) + param_1)) {
        (**(code **)((int)((unsigned char *)0x000012a0) + param_1))(param_1,iVar8);
      }
      else {
        (**(code **)((int)((unsigned char *)0x00001294) + param_1))(param_1,iVar8,*(undefined4 *)(iVar9 + 0x130));
      }
      (**(code **)(((unsigned char *)0x000012b4) + param_1))(param_1);
      if (*(int *)(iVar9 + 0x4c) != 0) {
        iVar4 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
        uVar2 = *(uint *)(iVar4 + 0x118);
        if (uVar2 != 0) {
          loopIndex = 0;
          do {
            iVar6 = *(int *)(((unsigned char *)0x0000137c) + iVar9);
            iVar1 = *(int *)(loopIndex * 4 + *(int *)(iVar4 + 0x114)) * 0x54 + param_2[8];
            puVar7 = *(undefined4 **)(iVar1 + 0x38);
            iVar1 = *(int *)(iVar1 + 4);
            iVar5 = iVar1 * 0x10 + iVar4;
            *(undefined4 *)(iVar5 + 0x154) = *puVar7;
            *(undefined4 *)(iVar5 + 0x158) = puVar7[1];
            *(undefined4 *)(iVar5 + 0x15c) = puVar7[2];
            *(undefined4 *)(iVar5 + 0x160) = puVar7[3];
            if (iVar6 < iVar1) {
              *(int *)(((unsigned char *)0x0000137c) + iVar9) = iVar1;
              uVar2 = *(uint *)(iVar4 + 0x118);
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < uVar2);
        }
        ((int (*)())FUN_00076770)(param_1,iVar8,param_2);
      }
      *(undefined4 *)(((unsigned char *)0x00001354) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x0000134c) + param_1) = 0;
      *(code **)(((unsigned char *)0x00001350) + param_1) = FUN_00077430;
    }
  }
  return;
}

/* FUN_00076ac0 @ 0x76ac0 (188 bytes) */
int FUN_00076ac0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x44);
  uVar1 = (uint)*(byte *)(param_2 + 0x36) & uVar2 >> 7 & 1 |
          ((uint)*(byte *)(param_2 + 0x37) & uVar2 >> 6 & 1) << 1;
  if (*(char *)(param_2 + 0x33) != '\0') {
    if (*(char *)(param_2 + 0x30) != '\0') {
      uVar1 = uVar1 | uVar2 >> 10 & 4;
    }
    if ((uVar2 & 0x800) != 0) {
      uVar1 = (uint)(byte)((unsigned char *)0x000011d1)[param_1] << 7 | uVar1 | 8;
    }
  }
  if (*(char *)(param_2 + 0x2e) == '\0') {
    uVar2 = *(uint *)(param_1 + 0x44);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x44);
    if ((uVar2 & 0x400) != 0) {
      uVar1 = uVar1 | (uint)(byte)((unsigned char *)0x000011d2)[param_1] << 0x14 | 0x10;
    }
  }
  if ((uVar2 & 0x2000) != 0) {
    uVar1 = uVar1 | 0x20;
  }
  return uVar1 | (uint)(byte)((unsigned char *)0x00002e0a)[*(int *)(*(int *)(param_1 + 4) + 0x10)] << 6;
}

/* FUN_00076b80 @ 0x76b80 (116 bytes) */
int FUN_00076b80(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + *param_2);
  iVar3 = *piVar2;
  uVar1 = ((int (*)())FUN_00076ac0)(param_1,iVar3);
  *(uint *)(iVar3 + 0x38) = uVar1;
  *(int *)(iVar3 + 0x138) = piVar2[(uVar1 & 0x1f) + 1];
  piVar2[(uVar1 & 0x1f) + 1] = iVar3;
  *(undefined1 *)(iVar3 + 0x134) = 1;
  piVar2[0x21] = piVar2[0x21] + 1;
  return;
}

/* FUN_00076c00 @ 0x76c00 (4 bytes) */
int FUN_00076c00()
{
  return;
}

/* FUN_00076c10 @ 0x76c10 (72 bytes) */
int FUN_00076c10(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = *(int *)((param_2 & 0x1f) * 4 + param_1 + 4);
  if (iVar1 != 0) {
    if (param_2 == *(uint *)(iVar1 + 0x38)) {
      return iVar1;
    }
    while (iVar1 = *(int *)(iVar1 + 0x138), iVar1 != 0) {
      if (param_2 == *(uint *)(iVar1 + 0x38)) {
        return iVar1;
      }
    }
  }
  return 0;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0006c7c0");
asm(".set FUN_0006c7c0, _FUN_0006c7c0");
asm(".globl FUN_0006cd00");
asm(".set FUN_0006cd00, _FUN_0006cd00");
asm(".globl FUN_0006d240");
asm(".set FUN_0006d240, _FUN_0006d240");
asm(".globl FUN_0006d780");
asm(".set FUN_0006d780, _FUN_0006d780");
asm(".globl FUN_0006dcc0");
asm(".set FUN_0006dcc0, _FUN_0006dcc0");
asm(".globl FUN_0006e460");
asm(".set FUN_0006e460, _FUN_0006e460");
asm(".globl FUN_0006ec10");
asm(".set FUN_0006ec10, _FUN_0006ec10");
asm(".globl FUN_00070c50");
asm(".set FUN_00070c50, _FUN_00070c50");
asm(".globl FUN_00070c60");
asm(".set FUN_00070c60, _FUN_00070c60");
asm(".globl FUN_00071bc0");
asm(".set FUN_00071bc0, _FUN_00071bc0");
asm(".globl FUN_00074b30");
asm(".set FUN_00074b30, _FUN_00074b30");
asm(".globl FUN_00074c00");
asm(".set FUN_00074c00, _FUN_00074c00");
asm(".globl FUN_00074cc0");
asm(".set FUN_00074cc0, _FUN_00074cc0");
asm(".globl FUN_00074d60");
asm(".set FUN_00074d60, _FUN_00074d60");
asm(".globl FUN_00074e30");
asm(".set FUN_00074e30, _FUN_00074e30");
asm(".globl FUN_00074ed0");
asm(".set FUN_00074ed0, _FUN_00074ed0");
asm(".globl FUN_00075060");
asm(".set FUN_00075060, _FUN_00075060");
asm(".globl FUN_000752c0");
asm(".set FUN_000752c0, _FUN_000752c0");
asm(".globl FUN_00075360");
asm(".set FUN_00075360, _FUN_00075360");
asm(".globl FUN_00075400");
asm(".set FUN_00075400, _FUN_00075400");
asm(".globl FUN_000754a0");
asm(".set FUN_000754a0, _FUN_000754a0");
asm(".globl FUN_00075570");
asm(".set FUN_00075570, _FUN_00075570");
asm(".globl FUN_00075640");
asm(".set FUN_00075640, _FUN_00075640");
asm(".globl FUN_00075710");
asm(".set FUN_00075710, _FUN_00075710");
asm(".globl FUN_000757b0");
asm(".set FUN_000757b0, _FUN_000757b0");
asm(".globl FUN_00075850");
asm(".set FUN_00075850, _FUN_00075850");
asm(".globl FUN_00075920");
asm(".set FUN_00075920, _FUN_00075920");
asm(".globl FUN_000759c0");
asm(".set FUN_000759c0, _FUN_000759c0");
asm(".globl FUN_00075a60");
asm(".set FUN_00075a60, _FUN_00075a60");
asm(".globl FUN_00075b00");
asm(".set FUN_00075b00, _FUN_00075b00");
asm(".globl FUN_00075ba0");
asm(".set FUN_00075ba0, _FUN_00075ba0");
asm(".globl FUN_00075c90");
asm(".set FUN_00075c90, _FUN_00075c90");
asm(".globl FUN_00075d60");
asm(".set FUN_00075d60, _FUN_00075d60");
asm(".globl FUN_00075e30");
asm(".set FUN_00075e30, _FUN_00075e30");
asm(".globl FUN_00075f00");
asm(".set FUN_00075f00, _FUN_00075f00");
asm(".globl FUN_00075fd0");
asm(".set FUN_00075fd0, _FUN_00075fd0");
asm(".globl FUN_00076070");
asm(".set FUN_00076070, _FUN_00076070");
asm(".globl FUN_00076160");
asm(".set FUN_00076160, _FUN_00076160");
asm(".globl FUN_00076230");
asm(".set FUN_00076230, _FUN_00076230");
asm(".globl FUN_00076300");
asm(".set FUN_00076300, _FUN_00076300");
asm(".globl FUN_000763d0");
asm(".set FUN_000763d0, _FUN_000763d0");
asm(".globl FUN_000764a0");
asm(".set FUN_000764a0, _FUN_000764a0");
asm(".globl FUN_00076560");
asm(".set FUN_00076560, _FUN_00076560");
asm(".globl FUN_000768e0");
asm(".set FUN_000768e0, _FUN_000768e0");
