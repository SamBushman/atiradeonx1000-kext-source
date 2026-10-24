#include "decls.h"

/* arbEmitIlRcp @ 0x6c7c0 (1308 bytes) */
int arbEmitIlRcp(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
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

/* arbEmitIlRsq @ 0x6cd00 (1308 bytes) */
int arbEmitIlRsq(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
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

/* arbEmitIlExp @ 0x6d240 (1308 bytes) */
int arbEmitIlExp(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
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

/* arbEmitIlExn @ 0x6d780 (1308 bytes) */
int arbEmitIlExn(ctx, dstFile, dstIndex, dstMask, srcFile, srcIndex, srcSelect, srcNegate)
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

/* arbEmitIlPow @ 0x6dcc0 (1912 bytes) */
int arbEmitIlPow(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Select, src0Negate, src1File, src1Index, src1Select, src1Negate)
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

/* arbEmitIlMovMadMov @ 0x6ec10 (4312 bytes) */
int arbEmitIlMovMadMov(ctx, dstFile, dstIndex, dstMask, src0File, src0Index, src0Words, src0Flags, src1File, src1Index, src1Words, src1Flags, src2File, src2Index, src2Words, src2Flags)
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

/* evsTokenBufPush @ 0x6fd10 (180 bytes) */
int evsTokenBufPush(param_1, param_2, param_3)
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

/* evsAllocLocalConstantRegisters @ 0x6fdd0 (1812 bytes) */
int evsAllocLocalConstantRegisters(ctx, shader, programState, symbol)
  int ctx;
  int shader;
  int programState;
  int symbol;
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
  
  iVar4 = *(int *)(symbol + 0x28);
  if (iVar4 == 0x87c3) {
    *(int *)(shader + 0x60) = *(int *)(shader + 0x60) + 1;
    *(int *)(programState + 0x118) = *(int *)(programState + 0x118) + 1;
    *(undefined1 *)(symbol + 0x3d) = 1;
    iVar4 = *(int *)(symbol + 0x24);
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      loopIndex = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(programState + 0x4c) = *(int *)(programState + 0x4c) + 1;
      while (loopIndex < *(uint *)(programState + 0x48)) {
        if (!bVar1) goto LAB_000702bc;
        if (*(char *)(iVar4 + *(int *)(programState + 0x44) + 0x10) == '\0') {
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
      *(int *)(programState + 0x4c) = *(int *)(programState + 0x4c) + 4;
      while (loopIndex < *(int *)(programState + 0x48) - 3U) {
        if (!bVar1) goto LAB_000703cc;
        if (*(char *)(iVar4 + *(int *)(programState + 0x44) + 0x10) == '\0') {
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
        iVar4 = iVar8 + *(int *)(programState + 0x44);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = loopIndex + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(symbol + 0x10) = iVar2;
            symbol = symbol + 4;
            iVar2 = *(int *)(programState + 0x44) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return 0;
        }
      }
      *(undefined1 *)(shader + 0x10) = 0;
      iVar10 = *(int *)(programState + 0x48);
      uVar9 = (**(code **)(ctx + 0x10))(iVar10 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (uVar9,*(undefined4 *)(programState + 0x44),*(int *)(programState + 0x48) * 0x28);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x44));
      *(undefined4 *)(programState + 0x44) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(programState + 0x48) = *(int *)(programState + 0x48) + 0x40;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(symbol + 0x10) = iVar3;
        symbol = symbol + 4;
        iVar3 = *(int *)(programState + 0x44) + iVar4;
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
    *(int *)(programState + 0x4c) = *(int *)(programState + 0x4c) + 1;
    while (loopIndex < *(uint *)(programState + 0x48)) {
      if (!bVar1) goto LAB_000701ac;
      if (*(char *)(iVar4 + *(int *)(programState + 0x44) + 0x10) == '\0') {
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
    *(int *)(shader + 0x5c) = *(int *)(shader + 0x5c) + 1;
    if (*(char *)(symbol + 0x44) == '\0') {
      *(int *)(programState + 0x118) = *(int *)(programState + 0x118) + 1;
    }
    else {
      *(int *)(programState + 0x120) = *(int *)(programState + 0x120) + 1;
    }
    iVar4 = *(int *)(symbol + 0x24);
    *(undefined1 *)(symbol + 0x3d) = 1;
    if (iVar4 == 0x87bf) {
      uVar6 = 0;
      loopIndex = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(programState + 0x4c) = *(int *)(programState + 0x4c) + 1;
      while (loopIndex < *(uint *)(programState + 0x48)) {
        if (!bVar1) goto LAB_000702bc;
        if (*(char *)(iVar4 + *(int *)(programState + 0x44) + 0x10) == '\0') {
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
        *(uint *)(symbol + 4) = loopIndex;
        *(undefined1 *)(loopIndex * 0x28 + *(int *)(programState + 0x44) + 0x10) = 1;
        return 0;
      }
      *(undefined1 *)(shader + 0x10) = uVar6;
      iVar4 = *(int *)(programState + 0x48);
      uVar9 = (**(code **)(ctx + 0x10))(iVar4 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (uVar9,*(undefined4 *)(programState + 0x44),*(int *)(programState + 0x48) * 0x28);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x44));
      *(undefined4 *)(programState + 0x44) = uVar9;
      *(int *)(programState + 0x48) = *(int *)(programState + 0x48) + 0x40;
      goto LAB_00070350;
    }
    if (iVar4 == 0x87c0) {
      loopIndex = 0;
      iVar4 = 0;
      bVar1 = true;
      *(int *)(programState + 0x4c) = *(int *)(programState + 0x4c) + 4;
      while (loopIndex < *(int *)(programState + 0x48) - 3U) {
        if (!bVar1) goto LAB_0006ffbc;
        if (*(char *)(iVar4 + *(int *)(programState + 0x44) + 0x10) == '\0') {
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
        iVar4 = iVar8 + *(int *)(programState + 0x44);
        if (((*(char *)(iVar4 + 0x38) == '\0') && (*(char *)(iVar4 + 0x60) == '\0')) &&
           (*(char *)(iVar4 + 0x88) == '\0')) {
          iVar4 = 0;
          iVar10 = 4;
          do {
            iVar2 = loopIndex + iVar4;
            iVar4 = iVar4 + 1;
            *(int *)(symbol + 0x10) = iVar2;
            symbol = symbol + 4;
            iVar2 = *(int *)(programState + 0x44) + iVar8;
            iVar8 = iVar8 + 0x28;
            *(undefined1 *)(iVar2 + 0x10) = 1;
            iVar10 = iVar10 + -1;
          } while (iVar10 != 0);
          return 0;
        }
      }
      *(undefined1 *)(shader + 0x10) = 0;
      iVar10 = *(int *)(programState + 0x48);
      uVar9 = (**(code **)(ctx + 0x10))(iVar10 + 0x40,0x28);
      (**(code **)(((unsigned char *)0x00001344) + ctx))
                (uVar9,*(undefined4 *)(programState + 0x44),*(int *)(programState + 0x48) * 0x28);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x44));
      *(undefined4 *)(programState + 0x44) = uVar9;
      iVar4 = iVar10 * 0x28;
      iVar2 = 4;
      iVar8 = 0;
      *(int *)(programState + 0x48) = *(int *)(programState + 0x48) + 0x40;
      do {
        iVar3 = iVar10 + iVar8;
        iVar8 = iVar8 + 1;
        *(int *)(symbol + 0x10) = iVar3;
        symbol = symbol + 4;
        iVar3 = iVar4 + *(int *)(programState + 0x44);
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
    *(int *)(programState + 0x4c) = *(int *)(programState + 0x4c) + 1;
    while (loopIndex < *(uint *)(programState + 0x48)) {
      if (!bVar1) goto LAB_000701ac;
      if (*(char *)(iVar4 + *(int *)(programState + 0x44) + 0x10) == '\0') {
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
    *(uint *)(symbol + 4) = loopIndex;
    *(undefined4 *)(symbol + 8) = 0;
    *(undefined1 *)(loopIndex * 0x28 + *(int *)(programState + 0x44) + 0x10) = 1;
    return 0;
  }
  *(char *)(shader + 0x10) = (char)uVar9;
  iVar4 = *(int *)(programState + 0x48);
  uVar5 = (**(code **)(ctx + 0x10))(iVar4 + 0x40,0x28);
  (**(code **)(((unsigned char *)0x00001344) + ctx))
            (uVar5,*(undefined4 *)(programState + 0x44),*(int *)(programState + 0x48) * 0x28);
  (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x44));
  *(undefined4 *)(programState + 0x44) = uVar5;
  *(int *)(programState + 0x48) = *(int *)(programState + 0x48) + 0x40;
  *(undefined4 *)(symbol + 8) = uVar9;
LAB_00070350:
  *(int *)(symbol + 4) = iVar4;
  *(undefined1 *)(iVar4 * 0x28 + *(int *)(programState + 0x44) + 0x10) = 1;
  return 0;
}

/* evsAllocConstantsForOperand @ 0x70520 (252 bytes) */
int evsAllocConstantsForOperand(ctx, shader, programState, operand)
  undefined4 ctx;
  int shader;
  undefined4 programState;
  int *operand;
{
  int iVar1;
  int iVar2;
  uint loopIndex;
  int iVar4;
  
  if (*operand == 2) {
    iVar1 = *(int *)(shader + 0x20);
    iVar4 = operand[1] * 0x54;
    iVar2 = iVar4 + iVar1;
    if (*(char *)(iVar2 + 0x3d) == '\0') {
      if (*(int *)(iVar2 + 0x30) == 0) {
        if (*(uint *)(iVar2 + 0x34) < 2) {
          iVar1 = ((int (*)())evsAllocLocalConstantRegisters)(ctx,shader,programState,iVar2);
          if (iVar1 != 1) {
            return 0;
          }
          return 1;
        }
      }
      else {
        iVar4 = extvsSymbolListGetIndex(shader + 0x1c,*(int *)(iVar2 + 0x30));
        iVar1 = *(int *)(shader + 0x20);
        iVar4 = iVar4 * 0x54;
      }
      if (*(int *)(iVar4 + iVar1 + 0x34) != 0) {
        loopIndex = 0;
        iVar2 = iVar4;
        do {
          iVar1 = ((int (*)())evsAllocLocalConstantRegisters)(ctx,shader,programState,iVar1 + iVar2);
          if (iVar1 == 1) {
            return 1;
          }
          iVar1 = *(int *)(shader + 0x20);
          loopIndex = loopIndex + 1;
          iVar2 = iVar2 + 0x54;
        } while (loopIndex < *(uint *)(iVar1 + iVar4 + 0x34));
      }
    }
  }
  return 0;
}

/* evsAllocLocalRegisters @ 0x70630 (1412 bytes) */
int evsAllocLocalRegisters(ctx, shader, programState, operand)
  int ctx;
  int shader;
  int programState;
  int *operand;
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
  
  if (*operand == 2) {
    iVar10 = operand[1];
    iVar11 = iVar10 * 0x54 + *(int *)(shader + 0x20);
    if ((*(int *)(iVar11 + 0x28) == 0x87c4) && (*(char *)(iVar11 + 0x3d) == '\0')) {
      *(undefined1 *)(iVar11 + 0x3d) = 1;
      *(int *)(shader + 100) = *(int *)(shader + 100) + 1;
      iVar7 = *(int *)(iVar10 * 0x54 + *(int *)(shader + 0x20) + 0x24);
      if (iVar7 == 0x87bf) {
        uVar5 = 0;
        uVar6 = 0;
        bVar1 = true;
        while (uVar5 < *(uint *)(programState + 0x40)) {
          if (!bVar1) goto LAB_000708f8;
          if (*(char *)(uVar5 * 0x28 + *(int *)(programState + 0x3c) + 0x10) == '\0') {
            uVar6 = 1;
            bVar1 = false;
          }
          else {
            uVar5 = uVar5 + 1;
          }
        }
        if (bVar1) {
          *(undefined1 *)(shader + 0x10) = uVar6;
          uVar5 = *(uint *)(programState + 0x40);
          uVar4 = (**(code **)(ctx + 0x10))(uVar5 + 0x40,0x28);
          (**(code **)(((unsigned char *)0x00001344) + ctx))
                    (uVar4,*(undefined4 *)(programState + 0x3c),*(int *)(programState + 0x40) * 0x28);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x3c));
          *(undefined4 *)(programState + 0x3c) = uVar4;
          *(int *)(programState + 0x40) = *(int *)(programState + 0x40) + 0x40;
          *(uint *)(iVar11 + 4) = uVar5;
        }
        else {
LAB_000708f8:
          *(uint *)(iVar11 + 4) = uVar5;
        }
        iVar11 = uVar5 * 0x28;
        *(undefined1 *)(*(int *)(programState + 0x3c) + iVar11 + 0x10) = 1;
        *(undefined4 *)(iVar11 + *(int *)(programState + 0x3c) + 0x14) = 4;
        *(int *)(iVar11 + *(int *)(programState + 0x3c) + 0x18) = iVar10;
        *(int *)(iVar11 + *(int *)(programState + 0x3c) + 0x1c) = iVar10;
        *(int *)(iVar11 + *(int *)(programState + 0x3c) + 0x20) = iVar10;
        *(int *)(iVar11 + *(int *)(programState + 0x3c) + 0x24) = iVar10;
      }
      else if (iVar7 == 0x87c0) {
        loopIndex = 0;
        bVar1 = true;
        while (loopIndex < *(int *)(programState + 0x40) - 3U) {
          if (!bVar1) goto LAB_00070a18;
          if (*(char *)(loopIndex * 0x28 + *(int *)(programState + 0x3c) + 0x10) == '\0') {
            bVar1 = false;
          }
          else {
            loopIndex = loopIndex + 1;
          }
        }
        if (!bVar1) {
LAB_00070a18:
          iVar8 = loopIndex * 0x28;
          iVar7 = iVar8 + *(int *)(programState + 0x3c);
          if (((*(char *)(iVar7 + 0x38) == '\0') && (*(char *)(iVar7 + 0x60) == '\0')) &&
             (*(char *)(iVar7 + 0x88) == '\0')) {
            iVar7 = 0;
            iVar12 = 4;
            do {
              iVar2 = loopIndex + iVar7;
              iVar7 = iVar7 + 1;
              *(int *)(iVar11 + 0x10) = iVar2;
              iVar11 = iVar11 + 4;
              *(undefined1 *)(*(int *)(programState + 0x3c) + iVar8 + 0x10) = 1;
              *(undefined4 *)(*(int *)(programState + 0x3c) + iVar8 + 0x14) = 4;
              *(int *)(*(int *)(programState + 0x3c) + iVar8 + 0x18) = iVar10;
              *(int *)(*(int *)(programState + 0x3c) + iVar8 + 0x1c) = iVar10;
              *(int *)(*(int *)(programState + 0x3c) + iVar8 + 0x20) = iVar10;
              iVar2 = *(int *)(programState + 0x3c) + iVar8;
              iVar8 = iVar8 + 0x28;
              *(int *)(iVar2 + 0x24) = iVar10;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
            return;
          }
        }
        *(undefined1 *)(shader + 0x10) = 0;
        iVar12 = *(int *)(programState + 0x40);
        uVar4 = (**(code **)(ctx + 0x10))(iVar12 + 0x40,0x28);
        (**(code **)(((unsigned char *)0x00001344) + ctx))
                  (uVar4,*(undefined4 *)(programState + 0x3c),*(int *)(programState + 0x40) * 0x28);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x3c));
        *(undefined4 *)(programState + 0x3c) = uVar4;
        iVar8 = iVar12 * 0x28;
        iVar2 = 4;
        iVar7 = 0;
        *(int *)(programState + 0x40) = *(int *)(programState + 0x40) + 0x40;
        do {
          iVar3 = iVar12 + iVar7;
          iVar7 = iVar7 + 1;
          *(int *)(iVar11 + 0x10) = iVar3;
          iVar11 = iVar11 + 4;
          *(undefined1 *)(*(int *)(programState + 0x3c) + iVar8 + 0x10) = 1;
          *(undefined4 *)(*(int *)(programState + 0x3c) + iVar8 + 0x14) = 4;
          *(int *)(*(int *)(programState + 0x3c) + iVar8 + 0x18) = iVar10;
          *(int *)(*(int *)(programState + 0x3c) + iVar8 + 0x1c) = iVar10;
          *(int *)(*(int *)(programState + 0x3c) + iVar8 + 0x20) = iVar10;
          iVar3 = *(int *)(programState + 0x3c) + iVar8;
          iVar8 = iVar8 + 0x28;
          *(int *)(iVar3 + 0x24) = iVar10;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      else if (iVar7 == 0x87be) {
        uVar5 = *(uint *)(programState + 0x40);
        loopIndex2 = 0;
        bVar1 = false;
        iVar7 = 0;
        while (loopIndex2 < uVar5) {
          if (bVar1) goto LAB_0007075c;
          iVar8 = iVar7 + *(int *)(programState + 0x3c);
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
          *(undefined4 *)(iVar11 + 8) = *(undefined4 *)(*(int *)(programState + 0x3c) + iVar7 + 0x14);
          iVar11 = iVar7 + *(int *)(programState + 0x3c);
          *(int *)(*(int *)(iVar11 + 0x14) * 4 + iVar11 + 0x18) = iVar10;
          iVar7 = iVar7 + *(int *)(programState + 0x3c);
          *(int *)(iVar7 + 0x14) = *(int *)(iVar7 + 0x14) + 1;
        }
        else {
          if (uVar5 == 0) {
LAB_000707f4:
            *(undefined1 *)(shader + 0x10) = 0;
            uVar9 = *(uint *)(programState + 0x40);
            uVar4 = (**(code **)(ctx + 0x10))(uVar9 + 0x40,0x28);
            (**(code **)(((unsigned char *)0x00001344) + ctx))
                      (uVar4,*(undefined4 *)(programState + 0x3c),*(int *)(programState + 0x40) * 0x28);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(programState + 0x3c));
            *(undefined4 *)(programState + 0x3c) = uVar4;
            *(int *)(programState + 0x40) = *(int *)(programState + 0x40) + 0x40;
            *(undefined4 *)(iVar11 + 8) = 0;
            *(uint *)(iVar11 + 4) = uVar9;
          }
          else {
            uVar9 = 0;
            do {
              bVar1 = *(char *)(uVar9 * 0x28 + *(int *)(programState + 0x3c) + 0x10) != '\0';
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
          *(undefined1 *)(*(int *)(programState + 0x3c) + iVar11 + 0x10) = 1;
          *(undefined4 *)(iVar11 + *(int *)(programState + 0x3c) + 0x14) = 1;
          *(int *)(iVar11 + *(int *)(programState + 0x3c) + 0x18) = iVar10;
        }
      }
    }
  }
  return;
}

/* evsOperandUsesTempSlot @ 0x70bf0 (80 bytes) */
int evsOperandUsesTempSlot(param_1, param_2)
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

/* noop_70c50 @ 0x70c50 (4 bytes) */
int noop_70c50()
{
  return;
}

/* noop_70c60 @ 0x70c60 (4 bytes) */
int noop_70c60()
{
  return;
}

/* evsFindFreeOutputRegister @ 0x70c70 (84 bytes) */
int evsFindFreeOutputRegister(programState)
  int programState;
{
  uint candidate;
  uint regIndex;
  
  regIndex = 0;
  do {
    candidate = regIndex;
    if (*(int *)(regIndex * 4 + programState + 0x60) == -1) {
      return regIndex;
    }
    do {
      regIndex = candidate + 1;
      if (0x15 < regIndex) {
        return 0xffffffff;
      }
      candidate = regIndex;
    } while (((regIndex == 1) || (candidate = 0x12, regIndex == 0x12)) || (candidate = regIndex, regIndex == 0x13));
  } while( true );
}

/* evsAllocTempSlot @ 0x70cd0 (144 bytes) */
int evsAllocTempSlot(programState)
  int programState;
{
  char usedFlag;
  int nextSlotOffset;
  int slotsLeft;
  int slotIndex;
  int slotOffset;
  char *usedFlagCursor;
  int slots;
  int slotPtr;
  
  slotsLeft = *(int *)(programState + 0x40);
  if (slotsLeft == 0) {
    return -1;
  }
  slots = *(int *)(programState + 0x3c);
  if (*(char *)(slots + 0x10) == '\0') {
    slotIndex = 0;
    slotOffset = 0;
    slotPtr = slots;
  }
  else {
    usedFlagCursor = (char *)(slots + 0x38);
    slotIndex = 0;
    nextSlotOffset = 0x28;
    do {
      slotOffset = nextSlotOffset;
      slotIndex = slotIndex + 1;
      slotsLeft = slotsLeft + -1;
      if (slotsLeft == 0) {
        return -1;
      }
      usedFlag = *usedFlagCursor;
      slotPtr = slots + slotOffset;
      usedFlagCursor = usedFlagCursor + 0x28;
      nextSlotOffset = slotOffset + 0x28;
    } while (usedFlag != '\0');
  }
  *(undefined1 *)(slotPtr + 0x10) = 1;
  *(undefined4 *)(*(int *)(programState + 0x3c) + slotOffset + 0x14) = 4;
  return slotIndex;
}

/* evsEmitFogOutput @ 0x70d80 (3624 bytes) */
int evsEmitFogOutput(ctx, tokens, programState, mode)
  int ctx;
  int tokens;
  int programState;
  int mode;
{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined *puVar6;
  uint *puVar7;
  
  puVar7 = (uint *)(tokens + 4);
  iVar2 = *(int *)(*(int *)(ctx + 4) + 0x10);
  if (mode == 0) {
    if (*(uint *)(tokens + 8) <= *(uint *)(tokens + 4)) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*(int *)(tokens + 4) << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(undefined4 *)(*puVar7 * 4 + *(int *)(tokens + 0xc)) = 0x47;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(tokens + 8) <= uVar4) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(tokens + 0xc)) = 0x100000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + programState);
    if (*(uint *)(tokens + 8) <= uVar5) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(tokens + 0xc)) = uVar4 & 0xffff | 0x440000;
    puVar6 = (undefined *)0x0;
    uVar4 = *(uint *)(tokens + 8);
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    if (uVar4 <= uVar5) {
LAB_00071330:
      uVar3 = (**(code **)(ctx + 0xc))(uVar4 * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
LAB_00071390:
    *(undefined **)(uVar5 * 4 + *(int *)(tokens + 0xc)) = puVar6;
    *puVar7 = *puVar7 + 1;
  }
  else {
    *(undefined1 *)(tokens + 3) = 1;
    sVar1 = *(short *)(((unsigned char *)0x00002e04) + iVar2);
    if (sVar1 == 0x801) {
      if (*(uint *)(tokens + 8) <= *(uint *)(tokens + 4)) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
        if (*(int *)(tokens + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(tokens + 0xc),*(int *)(tokens + 4) << 2);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
        }
        *(undefined4 *)(tokens + 0xc) = uVar3;
        *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
      }
      *(undefined4 *)(*puVar7 * 4 + *(int *)(tokens + 0xc)) = 0x49;
      uVar5 = *puVar7 + 1;
      *puVar7 = uVar5;
      uVar4 = *(uint *)(((unsigned char *)0x000013c0) + programState);
      if (*(uint *)(tokens + 8) <= uVar5) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
        if (*(int *)(tokens + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
        }
        *(undefined4 *)(tokens + 0xc) = uVar3;
        uVar5 = *puVar7;
        *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
      }
      *(uint *)(uVar5 * 4 + *(int *)(tokens + 0xc)) = uVar4 & 0xffff | 0x40000;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
      uVar5 = *(uint *)(((unsigned char *)0x000013c0) + programState) & 0xffff | 0x40000;
      if (*(uint *)(tokens + 8) <= uVar4) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
        if (*(int *)(tokens + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
        }
        *(undefined4 *)(tokens + 0xc) = uVar3;
        uVar4 = *puVar7;
        *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
      }
      *(uint *)(uVar4 * 4 + *(int *)(tokens + 0xc)) = uVar5;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
      if (*(uint *)(tokens + 8) <= uVar4) {
        uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
        if (*(int *)(tokens + 0xc) != 0) {
          _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
        }
        *(undefined4 *)(tokens + 0xc) = uVar3;
        uVar4 = *puVar7;
        *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
      }
      *(uint *)(uVar4 * 4 + *(int *)(tokens + 0xc)) = uVar5;
      uVar4 = *puVar7 + 1;
      *puVar7 = uVar4;
    }
    else {
      if (sVar1 == 0x2601) {
        if (*(uint *)(tokens + 8) <= *(uint *)(tokens + 4)) {
          uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
          if (*(int *)(tokens + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(tokens + 0xc),*(int *)(tokens + 4) << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
          }
          *(undefined4 *)(tokens + 0xc) = uVar3;
          *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
        }
        *(undefined4 *)(*puVar7 * 4 + *(int *)(tokens + 0xc)) = 0x23;
        uVar4 = *puVar7 + 1;
        *puVar7 = uVar4;
        if (*(uint *)(tokens + 8) <= uVar4) {
          uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
          if (*(int *)(tokens + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
          }
          *(undefined4 *)(tokens + 0xc) = uVar3;
          uVar4 = *puVar7;
          *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
        }
        *(undefined4 *)(uVar4 * 4 + *(int *)(tokens + 0xc)) = 0x100000;
        uVar5 = *puVar7 + 1;
        *puVar7 = uVar5;
        uVar4 = *(uint *)(((unsigned char *)0x000013c0) + programState);
        if (*(uint *)(tokens + 8) <= uVar5) {
          uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
          if (*(int *)(tokens + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
          }
          *(undefined4 *)(tokens + 0xc) = uVar3;
          uVar5 = *puVar7;
          *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
        }
        *(uint *)(uVar5 * 4 + *(int *)(tokens + 0xc)) = uVar4 & 0xffff | 0x440000;
        uVar4 = *puVar7 + 1;
        *puVar7 = uVar4;
        if (*(uint *)(tokens + 8) <= uVar4) {
          uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
          if (*(int *)(tokens + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
          }
          *(undefined4 *)(tokens + 0xc) = uVar3;
          uVar4 = *puVar7;
          *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
        }
        *(undefined **)(uVar4 * 4 + *(int *)(tokens + 0xc)) = ((unsigned char *)0x00004054);
        uVar5 = *puVar7 + 1;
        *puVar7 = uVar5;
        uVar4 = *(uint *)(((unsigned char *)0x000013c4) + programState);
        if (*(uint *)(tokens + 8) <= uVar5) {
          uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
          if (*(int *)(tokens + 0xc) != 0) {
            _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
          }
          *(undefined4 *)(tokens + 0xc) = uVar3;
          uVar5 = *puVar7;
          *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
        }
        *(uint *)(uVar5 * 4 + *(int *)(tokens + 0xc)) = uVar4 & 0xffff | 0x410000;
        puVar6 = ((unsigned char *)0x00004214);
        uVar4 = *(uint *)(tokens + 8);
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
    if (*(uint *)(tokens + 8) <= uVar4) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(tokens + 0xc)) = 0x49;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + programState);
    if (*(uint *)(tokens + 8) <= uVar5) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(tokens + 0xc)) = uVar4 & 0xffff | 0x40000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + programState);
    if (*(uint *)(tokens + 8) <= uVar5) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(tokens + 0xc)) = uVar4 & 0xffff | 0x40000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c4) + programState);
    if (*(uint *)(tokens + 8) <= uVar5) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(tokens + 0xc)) = uVar4 & 0xffff | 0x410000;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(tokens + 8) <= uVar4) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(tokens + 0xc)) = 0x2222;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(tokens + 8) <= uVar4) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(tokens + 0xc)) = 0x2c;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(tokens + 8) <= uVar4) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(tokens + 0xc)) = 0x100000;
    uVar5 = *puVar7 + 1;
    *puVar7 = uVar5;
    uVar4 = *(uint *)(((unsigned char *)0x000013c0) + programState);
    if (*(uint *)(tokens + 8) <= uVar5) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar5 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(uint *)(uVar5 * 4 + *(int *)(tokens + 0xc)) = uVar4 & 0xffff | 0x440000;
    uVar4 = *puVar7 + 1;
    *puVar7 = uVar4;
    if (*(uint *)(tokens + 8) <= uVar4) {
      uVar3 = (**(code **)(ctx + 0xc))(*(uint *)(tokens + 8) * 4 + 0x200);
      if (*(int *)(tokens + 0xc) != 0) {
        _memcpy(uVar3,*(int *)(tokens + 0xc),*puVar7 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(tokens + 0xc));
      }
      *(undefined4 *)(tokens + 0xc) = uVar3;
      uVar4 = *puVar7;
      *(int *)(tokens + 8) = *(int *)(tokens + 8) + 0x80;
    }
    *(undefined4 *)(uVar4 * 4 + *(int *)(tokens + 0xc)) = 0;
    *puVar7 = *puVar7 + 1;
  }
  return;
}

/* evsAssignVertexInputs @ 0x71bc0 (7188 bytes) */
int evsAssignVertexInputs(ctx, shader)
  int ctx;
  int *shader;
{
  int usedListOffset;
  int emitResult;
  int symbolRecordC;
  int curProgramStateB;
  int nextInputRegCandidateB;
  int symbolDataTypeC;
  int instOffsetC;
  uint tempSlotCount;
  uint symbolIndex;
  uint tokenCounter;
  int fogOutputReg;
  int instOffsetB;
  int symbolOffsetC;
  int allocStatus;
  int slotComponentX;
  int symbolOffsetB;
  int symbolRecordsB;
  int sharedInputRegB;
  int stateIndexB;
  int inputRecOffsetB;
  int destSymbolIndex;
  int usesTempSlot;
  int sharedInputReg;
  int stateIndex;
  int tempSlotRecord;
  int symbolRecordB;
  int instArray;
  int inputRecOffset;
  int nextInputRegCandidate;
  int symbolDataTypeB;
  int tempSlotOffset;
  int symbolDataType;
  int symbolRecords;
  int freeOutputReg01;
  int programTable;
  int nextInst;
  int freeOutputReg2;
  uint hwRegisterRow3;
  uint hwRegisterRow2;
  uint hwRegisterRow1;
  uint hwRegisterRow0;
  uint hwRegister;
  uint symbolCount;
  uint inputIndex16;
  uint tokenValue;
  undefined4 vec4Table;
  undefined4 usedSymbolList;
  undefined4 fogWriteMode;
  undefined4 allocatedHandle;
  undefined4 tempSlotB;
  bool fogFlagsNotBothSet;
  int usedSymbolCount;
  int tokenBuffer;
  int slotCursor;
  int instOffset;
  int nextInputReg;
  bool slotReleasable;
  byte destCoversX;
  byte destCoversY;
  byte destCoversZ;
  byte destCoversW;
  byte coveredX;
  byte coveredY;
  byte coveredZ;
  byte coveredW;
  int inputSlotCursor;
  uint instCount;
  undefined4 tempSlotA;
  uint instIndex;
  int symbolRecord;
  int curProgramState;
  int activeProgramIndexOrSymbolRecord;
  int programTableB;
  int symbolOffset;
  int instArrayB;
  int emitState;
  uint tempSlotIndex;
  int programState;
  int programStateAlias;
  uint scanInstIndex;
  uint inputMask;
  bool scanDone;
  int slotCountdown;
  uint maxTempCount;
  
  programState = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  emitState = programState + 0x13c;
  *(undefined4 *)(((unsigned char *)0x0000137c) + programState) = 0;
  ((unsigned char *)0x000013d0)[programState] = 0;
  if ((shader[6] == 0) || (shader[5] == 0)) {
    shader[0x19] = 0;
    shader[0xc] = 0;
    shader[0x15] = 0;
    shader[0x16] = 0;
    shader[0x17] = 0;
    shader[0x18] = 0;
    return 1;
  }
  *(undefined1 *)(shader + 4) = 1;
  tempSlotA = ((int (*)())evsAllocTempSlot)(programState);
  *(undefined4 *)(((unsigned char *)0x000013c0) + programState) = tempSlotA;
  tempSlotB = ((int (*)())evsAllocTempSlot)(programState);
  *(undefined4 *)(((unsigned char *)0x000013cc) + programState) = tempSlotB;
  slotCountdown = 0x16;
  programStateAlias = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  inputSlotCursor = programStateAlias;
  do {
    *(undefined4 *)(inputSlotCursor + 0x60) = 0xffffffff;
    *(undefined4 *)(inputSlotCursor + 0xb8) = 0xffffffff;
    inputSlotCursor = inputSlotCursor + 4;
    slotCountdown = slotCountdown + -1;
  } while (slotCountdown != 0);
  nextInputReg = 1;
  *(undefined4 *)(((unsigned char *)0x00001398) + programStateAlias) = 0;
  *(undefined4 *)(programStateAlias + 0x110) = 0;
  if (shader[5] != 0) {
    instIndex = 0;
    do {
      instOffsetC = instIndex * 0x74;
      instArrayB = shader[6];
      activeProgramIndexOrSymbolRecord = *(int *)(((unsigned char *)0x0000118c) + ctx);
      programTableB = *shader;
      curProgramState = **(int **)(activeProgramIndexOrSymbolRecord * 4 + programTableB);
      if (*(int *)(instOffsetC + instArrayB + 0x20) == 2) {
        symbolOffset = *(int *)(instOffsetC + instArrayB + 0x24) * 0x54;
        symbolRecord = symbolOffset + shader[8];
        if ((*(int *)(symbolRecord + 0x28) == 0x87c1) && (*(char *)(symbolRecord + 0x3d) == '\0')) {
          *(undefined4 *)(symbolOffset + shader[8]) = 0;
          *(undefined1 *)(symbolRecord + 0x3d) = 1;
          shader[0x16] = shader[0x16] + 1;
          if ((*(char *)(symbolRecord + 0x44) == '\0') || (*(int *)(symbolRecord + 0x48) == 0x12)) {
            symbolDataTypeB = *(int *)(symbolRecord + 0x24);
            if (symbolDataTypeB == 0x87bf) {
LAB_0007209c:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(symbolRecord + 4) = nextInputReg;
              nextInputReg = nextInputReg + 1;
            }
            else if (symbolDataTypeB == 0x87c0) {
              *(int *)(symbolRecord + 0x1c) = nextInputReg;
              *(int *)(symbolRecord + 0x10) = nextInputReg;
              *(int *)(symbolRecord + 0x14) = nextInputReg;
              *(int *)(symbolRecord + 0x18) = nextInputReg;
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputReg = nextInputReg + 4;
            }
            else {
              inputRecOffsetB = 0;
              if (symbolDataTypeB == 0x87be) goto LAB_0007209c;
            }
            inputRecOffsetB = *(int *)(curProgramState + 0x10) + inputRecOffsetB;
          }
          else {
            nextInputRegCandidate = nextInputReg;
            switch(*(int *)(symbolRecord + 0x48)) {
            case 0:
              nextInputRegCandidate = nextInputReg + 1;
              nextInputReg = 0;
              inputRecOffsetB = 0;
              *(undefined1 *)(curProgramState + 0x18) = 1;
              *(undefined4 *)(curProgramState + 0x60) = 1;
              *(undefined4 *)(curProgramState + 0xb8) = 0;
              break;
            case 1:
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 8;
              *(undefined4 *)(curProgramState + 100) = 1;
              *(int *)(((unsigned char *)0x0000139c) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0xbc) = nextInputReg;
              break;
            case 2:
              stateIndex = *(int *)(symbolRecord + 0x4c);
              inputMask = shader[0xc];
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)((int)shader + stateIndex + 0x34) = 1;
              shader[0xc] = inputMask | 4;
              *(int *)(((unsigned char *)0x000013a0) + stateIndex * 4 + curProgramState) = nextInputReg;
              stateIndex = (stateIndex + 10) * 4 + curProgramState;
              *(undefined4 *)(stateIndex + 0x60) = 1;
              *(int *)(stateIndex + 0xb8) = nextInputReg;
              break;
            case 3:
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 1;
              *(undefined4 *)(curProgramState + 0x68) = 1;
              *(int *)(((unsigned char *)0x00001388) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0xc0) = nextInputReg;
              break;
            case 4:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xc4) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x23) = 1;
              *(undefined4 *)(curProgramState + 0x6c) = 1;
              break;
            case 5:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 200) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x24) = 1;
              *(undefined4 *)(curProgramState + 0x70) = 1;
              break;
            case 6:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xcc) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x25) = 1;
              *(undefined4 *)(curProgramState + 0x74) = 1;
              break;
            case 7:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd0) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x22) = 1;
              *(undefined4 *)(curProgramState + 0x78) = 1;
              break;
            case 8:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd4) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x27) = 1;
              *(undefined4 *)(curProgramState + 0x7c) = 1;
              break;
            case 9:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd8) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x28) = 1;
              *(undefined4 *)(curProgramState + 0x80) = 1;
              break;
            case 10:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xdc) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x29) = 1;
              *(undefined4 *)(curProgramState + 0x84) = 1;
              break;
            case 0xb:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd0) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x26) = 1;
              *(undefined4 *)(curProgramState + 0x78) = 1;
              break;
            case 0xc:
              sharedInputReg = *(int *)(((unsigned char *)0x00001398) + curProgramState);
              if (*(int *)(((unsigned char *)0x00001398) + curProgramState) == 0) {
                *(int *)(((unsigned char *)0x00001398) + curProgramState) = nextInputReg;
                nextInputRegCandidate = nextInputReg + 1;
                sharedInputReg = nextInputReg;
              }
              inputRecOffsetB = sharedInputReg * 0x28;
              *(undefined4 *)(symbolRecord + 8) = 2;
              *(undefined4 *)(curProgramState + 0xa8) = 1;
              *(int *)(curProgramState + 0x100) = sharedInputReg;
              nextInputReg = sharedInputReg;
              break;
            case 0xd:
              sharedInputReg = *(int *)(((unsigned char *)0x00001398) + curProgramState);
              if (*(int *)(((unsigned char *)0x00001398) + curProgramState) == 0) {
                *(int *)(((unsigned char *)0x00001398) + curProgramState) = nextInputReg;
                nextInputRegCandidate = nextInputReg + 1;
                sharedInputReg = nextInputReg;
              }
              inputRecOffsetB = sharedInputReg * 0x28;
              *(undefined4 *)(symbolRecord + 8) = 3;
              *(undefined4 *)(curProgramState + 0xa8) = 1;
              *(int *)(curProgramState + 0x100) = sharedInputReg;
              nextInputReg = sharedInputReg;
              break;
            case 0xe:
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 2;
              *(undefined4 *)(curProgramState + 0x6c) = 1;
              *(int *)(((unsigned char *)0x0000138c) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0xc4) = nextInputReg;
              break;
            case 0xf:
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 0x40;
              *(int *)(((unsigned char *)0x00001390U) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0x100) = nextInputReg;
              *(undefined4 *)(curProgramState + 0xa8) = 1;
              *(undefined4 *)(symbolRecord + 8) = 1;
              break;
            case 0x10:
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 0x80;
              *(undefined4 *)(curProgramState + 0xac) = 1;
              *(int *)(((unsigned char *)0x00001394) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0x104) = nextInputReg;
              break;
            default:
              inputRecOffsetB = 0;
              nextInputReg = 0;
            }
            *(int *)(symbolRecord + 4) = nextInputReg;
            inputRecOffsetB = *(int *)(curProgramState + 0x10) + inputRecOffsetB;
            nextInputReg = nextInputRegCandidate;
          }
          *(undefined1 *)(inputRecOffsetB + 0x10) = 1;
          activeProgramIndexOrSymbolRecord = *(int *)(((unsigned char *)0x0000118c) + ctx);
          programTableB = *shader;
          instArrayB = shader[6];
        }
      }
      curProgramState = **(int **)(activeProgramIndexOrSymbolRecord * 4 + programTableB);
      if (*(int *)(instOffsetC + instArrayB + 0x3c) == 2) {
        symbolOffset = *(int *)(instOffsetC + instArrayB + 0x40) * 0x54;
        symbolRecord = symbolOffset + shader[8];
        if ((*(int *)(symbolRecord + 0x28) == 0x87c1) && (*(char *)(symbolRecord + 0x3d) == '\0')) {
          *(undefined4 *)(symbolOffset + shader[8]) = 0;
          *(undefined1 *)(symbolRecord + 0x3d) = 1;
          shader[0x16] = shader[0x16] + 1;
          if ((*(char *)(symbolRecord + 0x44) == '\0') || (*(int *)(symbolRecord + 0x48) == 0x12)) {
            symbolDataTypeB = *(int *)(symbolRecord + 0x24);
            if (symbolDataTypeB == 0x87bf) {
LAB_000724bc:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(symbolRecord + 4) = nextInputReg;
              nextInputReg = nextInputReg + 1;
            }
            else if (symbolDataTypeB == 0x87c0) {
              *(int *)(symbolRecord + 0x1c) = nextInputReg;
              *(int *)(symbolRecord + 0x10) = nextInputReg;
              *(int *)(symbolRecord + 0x14) = nextInputReg;
              *(int *)(symbolRecord + 0x18) = nextInputReg;
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputReg = nextInputReg + 4;
            }
            else {
              inputRecOffsetB = 0;
              if (symbolDataTypeB == 0x87be) goto LAB_000724bc;
            }
            inputRecOffsetB = *(int *)(curProgramState + 0x10) + inputRecOffsetB;
          }
          else {
            nextInputRegCandidate = nextInputReg;
            switch(*(int *)(symbolRecord + 0x48)) {
            case 0:
              nextInputRegCandidate = nextInputReg + 1;
              nextInputReg = 0;
              inputRecOffsetB = 0;
              *(undefined1 *)(curProgramState + 0x18) = 1;
              *(undefined4 *)(curProgramState + 0x60) = 1;
              *(undefined4 *)(curProgramState + 0xb8) = 0;
              break;
            case 1:
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 8;
              *(undefined4 *)(curProgramState + 100) = 1;
              *(int *)(((unsigned char *)0x0000139c) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0xbc) = nextInputReg;
              break;
            case 2:
              stateIndex = *(int *)(symbolRecord + 0x4c);
              inputMask = shader[0xc];
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)((int)shader + stateIndex + 0x34) = 1;
              shader[0xc] = inputMask | 4;
              *(int *)(((unsigned char *)0x000013a0) + stateIndex * 4 + curProgramState) = nextInputReg;
              stateIndex = (stateIndex + 10) * 4 + curProgramState;
              *(undefined4 *)(stateIndex + 0x60) = 1;
              *(int *)(stateIndex + 0xb8) = nextInputReg;
              break;
            case 3:
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 1;
              *(undefined4 *)(curProgramState + 0x68) = 1;
              *(int *)(((unsigned char *)0x00001388) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0xc0) = nextInputReg;
              break;
            case 4:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xc4) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x23) = 1;
              *(undefined4 *)(curProgramState + 0x6c) = 1;
              break;
            case 5:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 200) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x24) = 1;
              *(undefined4 *)(curProgramState + 0x70) = 1;
              break;
            case 6:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xcc) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x25) = 1;
              *(undefined4 *)(curProgramState + 0x74) = 1;
              break;
            case 7:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd0) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x22) = 1;
              *(undefined4 *)(curProgramState + 0x78) = 1;
              break;
            case 8:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd4) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x27) = 1;
              *(undefined4 *)(curProgramState + 0x7c) = 1;
              break;
            case 9:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd8) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x28) = 1;
              *(undefined4 *)(curProgramState + 0x80) = 1;
              break;
            case 10:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xdc) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x29) = 1;
              *(undefined4 *)(curProgramState + 0x84) = 1;
              break;
            case 0xb:
              inputRecOffsetB = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd0) = nextInputReg;
              nextInputRegCandidate = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x26) = 1;
              *(undefined4 *)(curProgramState + 0x78) = 1;
              break;
            case 0xc:
              sharedInputReg = *(int *)(((unsigned char *)0x00001398) + curProgramState);
              if (*(int *)(((unsigned char *)0x00001398) + curProgramState) == 0) {
                *(int *)(((unsigned char *)0x00001398) + curProgramState) = nextInputReg;
                nextInputRegCandidate = nextInputReg + 1;
                sharedInputReg = nextInputReg;
              }
              inputRecOffsetB = sharedInputReg * 0x28;
              *(undefined4 *)(symbolRecord + 8) = 2;
              *(undefined4 *)(curProgramState + 0xa8) = 1;
              *(int *)(curProgramState + 0x100) = sharedInputReg;
              nextInputReg = sharedInputReg;
              break;
            case 0xd:
              sharedInputReg = *(int *)(((unsigned char *)0x00001398) + curProgramState);
              if (*(int *)(((unsigned char *)0x00001398) + curProgramState) == 0) {
                *(int *)(((unsigned char *)0x00001398) + curProgramState) = nextInputReg;
                nextInputRegCandidate = nextInputReg + 1;
                sharedInputReg = nextInputReg;
              }
              inputRecOffsetB = sharedInputReg * 0x28;
              *(undefined4 *)(symbolRecord + 8) = 3;
              *(undefined4 *)(curProgramState + 0xa8) = 1;
              *(int *)(curProgramState + 0x100) = sharedInputReg;
              nextInputReg = sharedInputReg;
              break;
            case 0xe:
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 2;
              *(undefined4 *)(curProgramState + 0x6c) = 1;
              *(int *)(((unsigned char *)0x0000138c) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0xc4) = nextInputReg;
              break;
            case 0xf:
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 0x40;
              *(int *)(((unsigned char *)0x00001390U) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0x100) = nextInputReg;
              *(undefined4 *)(curProgramState + 0xa8) = 1;
              *(undefined4 *)(symbolRecord + 8) = 1;
              break;
            case 0x10:
              inputRecOffsetB = nextInputReg * 0x28;
              nextInputRegCandidate = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 0x80;
              *(undefined4 *)(curProgramState + 0xac) = 1;
              *(int *)(((unsigned char *)0x00001394) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0x104) = nextInputReg;
              break;
            default:
              inputRecOffsetB = 0;
              nextInputReg = 0;
            }
            *(int *)(symbolRecord + 4) = nextInputReg;
            inputRecOffsetB = *(int *)(curProgramState + 0x10) + inputRecOffsetB;
            nextInputReg = nextInputRegCandidate;
          }
          *(undefined1 *)(inputRecOffsetB + 0x10) = 1;
          activeProgramIndexOrSymbolRecord = *(int *)(((unsigned char *)0x0000118c) + ctx);
          programTableB = *shader;
          instArrayB = shader[6];
        }
      }
      curProgramState = **(int **)(activeProgramIndexOrSymbolRecord * 4 + programTableB);
      if (*(int *)(instOffsetC + instArrayB + 0x58) == 2) {
        instOffsetC = *(int *)(instOffsetC + instArrayB + 0x5c) * 0x54;
        activeProgramIndexOrSymbolRecord = instOffsetC + shader[8];
        if ((*(int *)(activeProgramIndexOrSymbolRecord + 0x28) == 0x87c1) && (*(char *)(activeProgramIndexOrSymbolRecord + 0x3d) == '\0')) {
          *(undefined4 *)(instOffsetC + shader[8]) = 0;
          *(undefined1 *)(activeProgramIndexOrSymbolRecord + 0x3d) = 1;
          shader[0x16] = shader[0x16] + 1;
          if ((*(char *)(activeProgramIndexOrSymbolRecord + 0x44) == '\0') || (*(int *)(activeProgramIndexOrSymbolRecord + 0x48) == 0x12)) {
            symbolDataTypeC = *(int *)(activeProgramIndexOrSymbolRecord + 0x24);
            if (symbolDataTypeC == 0x87bf) {
LAB_000728e4:
              inputRecOffset = nextInputReg * 0x28;
              *(int *)(activeProgramIndexOrSymbolRecord + 4) = nextInputReg;
              nextInputReg = nextInputReg + 1;
            }
            else if (symbolDataTypeC == 0x87c0) {
              *(int *)(activeProgramIndexOrSymbolRecord + 0x1c) = nextInputReg;
              *(int *)(activeProgramIndexOrSymbolRecord + 0x10) = nextInputReg;
              *(int *)(activeProgramIndexOrSymbolRecord + 0x14) = nextInputReg;
              *(int *)(activeProgramIndexOrSymbolRecord + 0x18) = nextInputReg;
              inputRecOffset = nextInputReg * 0x28;
              nextInputReg = nextInputReg + 4;
            }
            else {
              inputRecOffset = 0;
              if (symbolDataTypeC == 0x87be) goto LAB_000728e4;
            }
            *(undefined1 *)(*(int *)(curProgramState + 0x10) + inputRecOffset + 0x10) = 1;
          }
          else {
            nextInputRegCandidateB = nextInputReg;
            switch(*(int *)(activeProgramIndexOrSymbolRecord + 0x48)) {
            case 0:
              nextInputRegCandidateB = nextInputReg + 1;
              nextInputReg = 0;
              inputRecOffset = 0;
              *(undefined1 *)(curProgramState + 0x18) = 1;
              *(undefined4 *)(curProgramState + 0x60) = 1;
              *(undefined4 *)(curProgramState + 0xb8) = 0;
              break;
            case 1:
              inputRecOffset = nextInputReg * 0x28;
              nextInputRegCandidateB = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 8;
              *(undefined4 *)(curProgramState + 100) = 1;
              *(int *)(((unsigned char *)0x0000139c) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0xbc) = nextInputReg;
              break;
            case 2:
              stateIndexB = *(int *)(activeProgramIndexOrSymbolRecord + 0x4c);
              inputMask = shader[0xc];
              inputRecOffset = nextInputReg * 0x28;
              nextInputRegCandidateB = nextInputReg + 1;
              *(undefined1 *)((int)shader + stateIndexB + 0x34) = 1;
              shader[0xc] = inputMask | 4;
              *(int *)(((unsigned char *)0x000013a0) + stateIndexB * 4 + curProgramState) = nextInputReg;
              stateIndexB = (stateIndexB + 10) * 4 + curProgramState;
              *(undefined4 *)(stateIndexB + 0x60) = 1;
              *(int *)(stateIndexB + 0xb8) = nextInputReg;
              break;
            case 3:
              inputRecOffset = nextInputReg * 0x28;
              nextInputRegCandidateB = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 1;
              *(undefined4 *)(curProgramState + 0x68) = 1;
              *(int *)(((unsigned char *)0x00001388) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0xc0) = nextInputReg;
              break;
            case 4:
              inputRecOffset = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xc4) = nextInputReg;
              nextInputRegCandidateB = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x23) = 1;
              *(undefined4 *)(curProgramState + 0x6c) = 1;
              break;
            case 5:
              inputRecOffset = nextInputReg * 0x28;
              *(int *)(curProgramState + 200) = nextInputReg;
              nextInputRegCandidateB = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x24) = 1;
              *(undefined4 *)(curProgramState + 0x70) = 1;
              break;
            case 6:
              inputRecOffset = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xcc) = nextInputReg;
              nextInputRegCandidateB = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x25) = 1;
              *(undefined4 *)(curProgramState + 0x74) = 1;
              break;
            case 7:
              inputRecOffset = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd0) = nextInputReg;
              nextInputRegCandidateB = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x22) = 1;
              *(undefined4 *)(curProgramState + 0x78) = 1;
              break;
            case 8:
              inputRecOffset = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd4) = nextInputReg;
              nextInputRegCandidateB = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x27) = 1;
              *(undefined4 *)(curProgramState + 0x7c) = 1;
              break;
            case 9:
              inputRecOffset = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd8) = nextInputReg;
              nextInputRegCandidateB = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x28) = 1;
              *(undefined4 *)(curProgramState + 0x80) = 1;
              break;
            case 10:
              inputRecOffset = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xdc) = nextInputReg;
              nextInputRegCandidateB = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x29) = 1;
              *(undefined4 *)(curProgramState + 0x84) = 1;
              break;
            case 0xb:
              inputRecOffset = nextInputReg * 0x28;
              *(int *)(curProgramState + 0xd0) = nextInputReg;
              nextInputRegCandidateB = nextInputReg + 1;
              *(undefined1 *)(curProgramState + 0x26) = 1;
              *(undefined4 *)(curProgramState + 0x78) = 1;
              break;
            case 0xc:
              sharedInputRegB = *(int *)(((unsigned char *)0x00001398) + curProgramState);
              if (*(int *)(((unsigned char *)0x00001398) + curProgramState) == 0) {
                *(int *)(((unsigned char *)0x00001398) + curProgramState) = nextInputReg;
                nextInputRegCandidateB = nextInputReg + 1;
                sharedInputRegB = nextInputReg;
              }
              inputRecOffset = sharedInputRegB * 0x28;
              *(undefined4 *)(activeProgramIndexOrSymbolRecord + 8) = 2;
              *(undefined4 *)(curProgramState + 0xa8) = 1;
              *(int *)(curProgramState + 0x100) = sharedInputRegB;
              nextInputReg = sharedInputRegB;
              break;
            case 0xd:
              sharedInputRegB = *(int *)(((unsigned char *)0x00001398) + curProgramState);
              if (*(int *)(((unsigned char *)0x00001398) + curProgramState) == 0) {
                *(int *)(((unsigned char *)0x00001398) + curProgramState) = nextInputReg;
                nextInputRegCandidateB = nextInputReg + 1;
                sharedInputRegB = nextInputReg;
              }
              inputRecOffset = sharedInputRegB * 0x28;
              *(undefined4 *)(activeProgramIndexOrSymbolRecord + 8) = 3;
              *(undefined4 *)(curProgramState + 0xa8) = 1;
              *(int *)(curProgramState + 0x100) = sharedInputRegB;
              nextInputReg = sharedInputRegB;
              break;
            case 0xe:
              inputRecOffset = nextInputReg * 0x28;
              nextInputRegCandidateB = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 2;
              *(undefined4 *)(curProgramState + 0x6c) = 1;
              *(int *)(((unsigned char *)0x0000138c) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0xc4) = nextInputReg;
              break;
            case 0xf:
              inputRecOffset = nextInputReg * 0x28;
              nextInputRegCandidateB = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 0x40;
              *(int *)(((unsigned char *)0x00001390U) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0x100) = nextInputReg;
              *(undefined4 *)(curProgramState + 0xa8) = 1;
              *(undefined4 *)(activeProgramIndexOrSymbolRecord + 8) = 1;
              break;
            case 0x10:
              inputRecOffset = nextInputReg * 0x28;
              nextInputRegCandidateB = nextInputReg + 1;
              shader[0xc] = shader[0xc] | 0x80;
              *(undefined4 *)(curProgramState + 0xac) = 1;
              *(int *)(((unsigned char *)0x00001394) + curProgramState) = nextInputReg;
              *(int *)(curProgramState + 0x104) = nextInputReg;
              break;
            default:
              inputRecOffset = 0;
              nextInputReg = 0;
            }
            *(int *)(activeProgramIndexOrSymbolRecord + 4) = nextInputReg;
            *(undefined1 *)(*(int *)(curProgramState + 0x10) + inputRecOffset + 0x10) = 1;
            nextInputReg = nextInputRegCandidateB;
          }
        }
      }
      instIndex = instIndex + 1;
    } while (instIndex < (uint)shader[5]);
  }
  *(int *)(programStateAlias + 0x130) = nextInputReg;
  if (shader[5] != 0) {
    instIndex = 0;
    instOffset = 0;
    do {
      instArray = shader[6];
      activeProgramIndexOrSymbolRecord = *(int *)(((unsigned char *)0x0000118c) + ctx);
      programTable = *shader;
      curProgramStateB = **(int **)(activeProgramIndexOrSymbolRecord * 4 + programTable);
      if (*(int *)(instOffset + instArray + 0x20) == 2) {
        symbolRecordsB = shader[8];
        symbolOffset = *(int *)(instOffset + instArray + 0x24) * 0x54;
        symbolRecord = symbolOffset + symbolRecordsB;
        if ((*(int *)(symbolRecord + 0x28) == 0x87c1) &&
           ((((*(char *)(symbolRecord + 0x44) == '\0' || (*(int *)(symbolRecord + 0x48) == 0x12)) &&
             (symbolRecord != 0)) && (*(int *)(symbolOffset + symbolRecordsB) == 0)))) {
          *(undefined1 *)(symbolRecord + 0x3d) = 1;
          if (*(int *)(symbolRecord + 0x24) == 0x87bf) {
            freeOutputReg01 = ((int (*)())evsFindFreeOutputRegister)(curProgramStateB);
            curProgramStateB = freeOutputReg01 * 4 + curProgramStateB;
            *(undefined4 *)(curProgramStateB + 0xb8) = *(undefined4 *)(symbolRecord + 4);
            *(undefined4 *)(curProgramStateB + 0x60) = 1;
            allocatedHandle = (**(code **)(((unsigned char *)0x000012a8) + ctx))(ctx,freeOutputReg01,4);
            *(undefined4 *)(symbolOffset + symbolRecordsB) = allocatedHandle;
            activeProgramIndexOrSymbolRecord = *(int *)(((unsigned char *)0x0000118c) + ctx);
            programTable = *shader;
            instArray = shader[6];
          }
          else {
            activeProgramIndexOrSymbolRecord = *(int *)(((unsigned char *)0x0000118c) + ctx);
            programTable = *shader;
            instArray = shader[6];
          }
        }
      }
      curProgramStateB = **(int **)(activeProgramIndexOrSymbolRecord * 4 + programTable);
      if (*(int *)(instOffset + instArray + 0x3c) == 2) {
        symbolRecordsB = shader[8];
        symbolOffset = *(int *)(instOffset + instArray + 0x40) * 0x54;
        symbolRecord = symbolOffset + symbolRecordsB;
        if ((((*(int *)(symbolRecord + 0x28) == 0x87c1) &&
             ((*(char *)(symbolRecord + 0x44) == '\0' || (*(int *)(symbolRecord + 0x48) == 0x12)))) &&
            (symbolRecord != 0)) && (*(int *)(symbolOffset + symbolRecordsB) == 0)) {
          *(undefined1 *)(symbolRecord + 0x3d) = 1;
          if (*(int *)(symbolRecord + 0x24) == 0x87bf) {
            freeOutputReg01 = ((int (*)())evsFindFreeOutputRegister)(curProgramStateB);
            curProgramStateB = freeOutputReg01 * 4 + curProgramStateB;
            *(undefined4 *)(curProgramStateB + 0xb8) = *(undefined4 *)(symbolRecord + 4);
            *(undefined4 *)(curProgramStateB + 0x60) = 1;
            allocatedHandle = (**(code **)(((unsigned char *)0x000012a8) + ctx))(ctx,freeOutputReg01,4);
            *(undefined4 *)(symbolOffset + symbolRecordsB) = allocatedHandle;
            activeProgramIndexOrSymbolRecord = *(int *)(((unsigned char *)0x0000118c) + ctx);
            programTable = *shader;
            instArray = shader[6];
          }
          else {
            activeProgramIndexOrSymbolRecord = *(int *)(((unsigned char *)0x0000118c) + ctx);
            programTable = *shader;
            instArray = shader[6];
          }
        }
      }
      curProgramStateB = **(int **)(activeProgramIndexOrSymbolRecord * 4 + programTable);
      if (*(int *)(instOffset + instArray + 0x58) == 2) {
        symbolRecords = shader[8];
        symbolOffsetB = *(int *)(instOffset + instArray + 0x5c) * 0x54;
        symbolRecordB = symbolOffsetB + symbolRecords;
        if (((*(int *)(symbolRecordB + 0x28) == 0x87c1) &&
            ((*(char *)(symbolRecordB + 0x44) == '\0' || (*(int *)(symbolRecordB + 0x48) == 0x12)))) &&
           ((symbolRecordB != 0 &&
            ((*(int *)(symbolOffsetB + symbolRecords) == 0 &&
             (*(undefined1 *)(symbolRecordB + 0x3d) = 1, *(int *)(symbolRecordB + 0x24) == 0x87bf)))))) {
          freeOutputReg2 = ((int (*)())evsFindFreeOutputRegister)(curProgramStateB);
          curProgramStateB = freeOutputReg2 * 4 + curProgramStateB;
          *(undefined4 *)(curProgramStateB + 0xb8) = *(undefined4 *)(symbolRecordB + 4);
          *(undefined4 *)(curProgramStateB + 0x60) = 1;
          allocatedHandle = (**(code **)(((unsigned char *)0x000012a8) + ctx))(ctx,freeOutputReg2,4);
          *(undefined4 *)(symbolOffsetB + symbolRecords) = allocatedHandle;
        }
      }
      instIndex = instIndex + 1;
      instOffset = instOffset + 0x74;
    } while (instIndex < (uint)shader[5]);
  }
  slotCountdown = 0x16;
  slotCursor = programStateAlias;
  do {
    if (*(int *)(slotCursor + 0x60) != -1) {
      *(int *)(programStateAlias + 0x110) = *(int *)(programStateAlias + 0x110) + 1;
    }
    slotCursor = slotCursor + 4;
    slotCountdown = slotCountdown + -1;
  } while (slotCountdown != 0);
  *(undefined4 *)(programState + 0x118) = 0;
  *(undefined4 *)(programState + 0x120) = 0;
  if (shader[5] != 0) {
    instIndex = 0;
    instOffset = 0;
    do {
      allocStatus = ((int (*)())evsAllocConstantsForOperand)(ctx,shader,programState,instOffset + shader[6] + 0x20);
      if (((allocStatus == 1) ||
          (allocStatus = ((int (*)())evsAllocConstantsForOperand)(ctx,shader,programState,instOffset + shader[6] + 0x3c), allocStatus == 1))
         || (allocStatus = ((int (*)())evsAllocConstantsForOperand)(ctx,shader,programState,instOffset + shader[6] + 0x58), allocStatus == 1))
      {
        shader[0x19] = 0;
        shader[0xc] = 0;
        shader[0x15] = 0;
        shader[0x16] = 0;
        shader[0x17] = 0;
        shader[0x18] = 0;
        return 0;
      }
      instIndex = instIndex + 1;
      instOffset = instOffset + 0x74;
    } while (instIndex < (uint)shader[5]);
  }
  tokenCounter = 0;
  tokenBuffer = programState + 0x140;
  *(undefined4 *)(programState + 4) = 0;
  ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,1);
  ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,0x200);
  tokenValue = 0;
  if (*(int *)(programState + 0x130) != 0) {
    do {
      ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,(tokenCounter & 0x3fff) << 0x10 | 0x1a);
      inputIndex16 = tokenCounter & 0xffff;
      tokenCounter = tokenCounter + 1;
      ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,inputIndex16 | 0x50000);
      tokenValue = *(uint *)(programState + 0x130);
    } while (tokenCounter < tokenValue);
  }
  *(uint *)(((unsigned char *)0x00001178) + programState) = tokenValue;
  symbolCount = shader[7];
  if (symbolCount != 0) {
    symbolIndex = 0;
    symbolOffsetC = 0;
    do {
      symbolRecordC = symbolOffsetC + shader[8];
      if ((symbolRecordC != 0) && (*(int *)(symbolRecordC + 0x28) == 0x87c3)) {
        symbolDataType = *(int *)(symbolRecordC + 0x24);
        if (symbolDataType == 0x87bf) {
          hwRegister = *(uint *)(symbolRecordC + 4);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,0x1c);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,hwRegister & 0xffff | 0x10000);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,**(undefined4 **)(symbolOffsetC + shader[8] + 0x38));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(symbolOffsetC + shader[8] + 0x38) + 4));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(symbolOffsetC + shader[8] + 0x38) + 8));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(symbolOffsetC + shader[8] + 0x38) + 0xc));
          symbolCount = shader[7];
        }
        else if (symbolDataType == 0x87c0) {
          hwRegisterRow0 = *(uint *)(symbolRecordC + 0x10);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,0x1c);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,hwRegisterRow0 & 0xffff | 0x10000);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,**(undefined4 **)(shader[8] + symbolOffsetC + 0x38));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(shader[8] + symbolOffsetC + 0x38) + 4));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(shader[8] + symbolOffsetC + 0x38) + 8));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(shader[8] + symbolOffsetC + 0x38) + 0xc));
          hwRegisterRow1 = *(uint *)(symbolRecordC + 0x14);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,0x1c);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,hwRegisterRow1 & 0xffff | 0x10000);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(shader[8] + symbolOffsetC + 0x38) + 0x10));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(shader[8] + symbolOffsetC + 0x38) + 0x14));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(shader[8] + symbolOffsetC + 0x38) + 0x18));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(shader[8] + symbolOffsetC + 0x38) + 0x1c));
          hwRegisterRow2 = *(uint *)(symbolRecordC + 0x18);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,0x1c);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,hwRegisterRow2 & 0xffff | 0x10000);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(shader[8] + symbolOffsetC + 0x38) + 0x20));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(symbolOffsetC + shader[8] + 0x38) + 0x24));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(symbolOffsetC + shader[8] + 0x38) + 0x28));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(symbolOffsetC + shader[8] + 0x38) + 0x2c));
          hwRegisterRow3 = *(uint *)(symbolRecordC + 0x1c);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,0x1c);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,hwRegisterRow3 & 0xffff | 0x10000);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(symbolOffsetC + shader[8] + 0x38) + 0x30));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(symbolOffsetC + shader[8] + 0x38) + 0x34));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(symbolOffsetC + shader[8] + 0x38) + 0x38));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,*(undefined4 *)(*(int *)(symbolOffsetC + shader[8] + 0x38) + 0x3c));
          symbolCount = shader[7];
        }
        else if (symbolDataType == 0x87be) {
          hwRegister = *(uint *)(symbolRecordC + 4);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,0x1c);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,hwRegister & 0xffff | 0x10000);
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,**(undefined4 **)(symbolOffsetC + shader[8] + 0x38));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,**(undefined4 **)(symbolOffsetC + shader[8] + 0x38));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,**(undefined4 **)(symbolOffsetC + shader[8] + 0x38));
          ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,**(undefined4 **)(symbolOffsetC + shader[8] + 0x38));
          symbolCount = shader[7];
        }
      }
      symbolIndex = symbolIndex + 1;
      symbolOffsetC = symbolOffsetC + 0x54;
    } while (symbolIndex < symbolCount);
  }
  maxTempCount = 0;
  if (shader[5] != 0) {
    instIndex = 0;
    instOffsetB = 0;
    do {
      if (0x20 < *(int *)(instOffsetB + shader[6]) - 0x8782U) {
        shader[0x19] = 0;
        shader[0xc] = 0;
        shader[0x15] = 0;
        shader[0x16] = 0;
        shader[0x17] = 0;
        shader[0x18] = 0;
        return 0;
      }
      ((int (*)())evsAllocLocalRegisters)(ctx,shader,programState,instOffsetB + shader[6] + 4);
      ((int (*)())evsAllocLocalRegisters)(ctx,shader,programState,instOffsetB + shader[6] + 0x20);
      ((int (*)())evsAllocLocalRegisters)(ctx,shader,programState,instOffsetB + shader[6] + 0x3c);
      ((int (*)())evsAllocLocalRegisters)(ctx,shader,programState,instOffsetB + shader[6] + 0x58);
      if (maxTempCount < (uint)shader[0x19]) {
        maxTempCount = shader[0x19];
      }
      emitResult = (**(code **)(&DAT_001b9d04 + *(int *)(instOffsetB + shader[6]) * 4))
                         (ctx,emitState,shader,instOffsetB + shader[6],activeProgramIndexOrSymbolRecord,&PTR_FUN_001dbb0c);
      if (emitResult < 0) {
        *(undefined1 *)(shader + 4) = 0;
        shader[0xc] = 0;
        shader[0x15] = 0;
        shader[0x16] = 0;
        shader[0x17] = 0;
        shader[0x18] = 0;
        shader[0x19] = 0;
        return 0;
      }
      *(int *)(programState + 4) = emitResult + *(int *)(programState + 4);
      if (*(char *)((int)shader + 0x7b) == '\0') {
        curProgramStateB = **(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
        tempSlotCount = *(uint *)(curProgramStateB + 0x40);
        if (tempSlotCount != 0) {
          tempSlotIndex = 0;
          tempSlotOffset = 0;
          do {
            tempSlotRecord = tempSlotOffset + *(int *)(curProgramStateB + 0x3c);
            if (*(char *)(tempSlotRecord + 0x10) != '\0') {
              slotComponentX = *(int *)(tempSlotRecord + 0x18);
              if ((((slotComponentX == 0) && (*(int *)(tempSlotRecord + 0x1c) == 0)) &&
                  ((*(int *)(tempSlotRecord + 0x20) == 0 && (*(int *)(tempSlotRecord + 0x24) == 0)))) ||
                 (instCount = shader[5], instCount <= instIndex + 1)) {
                slotReleasable = true;
              }
              else {
                slotReleasable = true;
                nextInst = instOffsetB + 0x74 + shader[6];
                coveredX = 0;
                coveredY = 0;
                coveredZ = 0;
                coveredW = 0;
                scanInstIndex = instIndex + 1;
                do {
                  usesTempSlot = ((int (*)())evsOperandUsesTempSlot)(nextInst + 0x20,tempSlotRecord);
                  if (((usesTempSlot == 0) && (usesTempSlot = ((int (*)())evsOperandUsesTempSlot)(nextInst + 0x3c,tempSlotRecord), usesTempSlot == 0))
                     && (usesTempSlot = ((int (*)())evsOperandUsesTempSlot)(nextInst + 0x58,tempSlotRecord), usesTempSlot == 0)) {
                    usesTempSlot = ((int (*)())evsOperandUsesTempSlot)(nextInst + 4,tempSlotRecord);
                    if (usesTempSlot != 0) {
                      destSymbolIndex = *(int *)(nextInst + 8);
                      if (*(int *)(destSymbolIndex * 0x54 + shader[8] + 0x24) == 0x87be) {
                        destCoversX = slotComponentX == destSymbolIndex;
                        destCoversY = destSymbolIndex == *(int *)(tempSlotRecord + 0x1c);
                        destCoversZ = destSymbolIndex == *(int *)(tempSlotRecord + 0x20);
                        destCoversW = destSymbolIndex == *(int *)(tempSlotRecord + 0x24);
                      }
                      else {
                        destCoversX = *(byte *)(nextInst + 0xf);
                        destCoversY = *(byte *)(nextInst + 0x13);
                        destCoversZ = *(byte *)(nextInst + 0x17);
                        destCoversW = *(byte *)(nextInst + 0x1b);
                      }
                      coveredX = coveredX | destCoversX;
                      coveredY = coveredY | destCoversY;
                      coveredZ = coveredZ | destCoversZ;
                      coveredW = coveredW | destCoversW;
                      if (((coveredX != 0) && (coveredY != 0)) && (coveredZ != 0)) {
                        scanDone = coveredW != 0;
                        goto LAB_000734d0;
                      }
                    }
                    scanDone = false;
                  }
                  else {
                    slotReleasable = false;
                    scanDone = true;
                  }
LAB_000734d0:
                  scanInstIndex = scanInstIndex + 1;
                } while ((instCount != scanInstIndex) && (nextInst = nextInst + 0x74, !scanDone));
              }
              if (tempSlotIndex == *(uint *)(((unsigned char *)0x000013c0) + curProgramStateB)) {
                slotReleasable = false;
              }
              if ((tempSlotIndex != *(uint *)(((unsigned char *)0x000013cc) + curProgramStateB)) && (slotReleasable)) {
                *(undefined1 *)(slotComponentX * 0x54 + shader[8] + 0x3d) = 0;
                *(undefined1 *)
                 (*(int *)(*(int *)(curProgramStateB + 0x3c) + tempSlotOffset + 0x1c) * 0x54 + shader[8] + 0x3d) = 0;
                *(undefined1 *)
                 (*(int *)(*(int *)(curProgramStateB + 0x3c) + tempSlotOffset + 0x20) * 0x54 + shader[8] + 0x3d) = 0;
                *(undefined1 *)
                 (*(int *)(*(int *)(curProgramStateB + 0x3c) + tempSlotOffset + 0x24) * 0x54 + shader[8] + 0x3d) = 0;
                *(undefined1 *)(*(int *)(curProgramStateB + 0x3c) + tempSlotOffset + 0x10) = 0;
                *(undefined4 *)(*(int *)(curProgramStateB + 0x3c) + tempSlotOffset + 0x14) = 0;
                *(undefined4 *)(*(int *)(curProgramStateB + 0x3c) + tempSlotOffset + 0x18) = 0;
                *(undefined4 *)(*(int *)(curProgramStateB + 0x3c) + tempSlotOffset + 0x1c) = 0;
                *(undefined4 *)(*(int *)(curProgramStateB + 0x3c) + tempSlotOffset + 0x20) = 0;
                *(undefined4 *)(*(int *)(curProgramStateB + 0x3c) + tempSlotOffset + 0x24) = 0;
                shader[0x19] = shader[0x19] + -1;
                tempSlotCount = *(uint *)(curProgramStateB + 0x40);
              }
            }
            tempSlotIndex = tempSlotIndex + 1;
            tempSlotOffset = tempSlotOffset + 0x28;
          } while (tempSlotIndex < tempSlotCount);
        }
      }
      instIndex = instIndex + 1;
      instOffsetB = instOffsetB + 0x74;
    } while (instIndex < (uint)shader[5]);
  }
  if (*(char *)((int)shader + 0x7a) != '\0') {
    fogFlagsNotBothSet = (*(uint *)(ctx + 0x44) & 0x2800) != 0x2800;
    if (fogFlagsNotBothSet) {
      ((unsigned char *)0x000013c8)[programState] = 1;
    }
    else {
      ((unsigned char *)0x000013c9)[programState] = ((unsigned char *)0x000011d1)[ctx];
      *(byte *)((int)shader + (byte)((unsigned char *)0x000011d1)[ctx] + 0x71) =
           *(byte *)((int)shader + (byte)((unsigned char *)0x000011d1)[ctx] + 0x71) | 1;
      ((unsigned char *)0x000013c8)[programState] = 0;
    }
    if ((*(uint *)(ctx + 0x44) & 0x2000) == 0) {
      fogWriteMode = 1;
    }
    else {
      fogWriteMode = 0;
      if (fogFlagsNotBothSet) goto LAB_000736b0;
    }
    fogOutputReg = *(int *)(programState + 0x4c);
    *(int *)(((unsigned char *)0x000013c4) + programState) = fogOutputReg;
    *(int *)(programState + 0x4c) = fogOutputReg + 1;
    ((int (*)())evsEmitFogOutput)(ctx,emitState,programState,fogWriteMode);
  }
LAB_000736b0:
  ((int (*)())evsTokenBufPush)(ctx,tokenBuffer,0x28);
  shader[0x15] = *(int *)(programState + 4);
  shader[0x19] = maxTempCount;
  if (*(int *)(programState + 0x118) != 0) {
    usedSymbolList = (**(code **)(ctx + 0xc))(*(int *)(programState + 0x118) << 2);
    *(undefined4 *)(programState + 0x114) = usedSymbolList;
    symbolCount = shader[7];
    if (symbolCount != 0) {
      symbolIndex = 0;
      usedSymbolCount = 0;
      symbolOffsetC = 0;
      do {
        symbolRecordC = symbolOffsetC + shader[8];
        if (*(char *)(symbolRecordC + 0x3d) != '\0') {
          if (*(int *)(symbolRecordC + 0x28) == 0x87c2) {
            if (*(char *)(symbolRecordC + 0x44) == '\0') {
LAB_00073754:
              usedListOffset = usedSymbolCount * 4;
              usedSymbolCount = usedSymbolCount + 1;
              *(uint *)(usedListOffset + *(int *)(programState + 0x114)) = symbolIndex;
              symbolCount = shader[7];
            }
          }
          else if (*(int *)(symbolRecordC + 0x28) == 0x87c3) goto LAB_00073754;
        }
        symbolIndex = symbolIndex + 1;
        symbolOffsetC = symbolOffsetC + 0x54;
      } while (symbolIndex < symbolCount);
    }
  }
  if (*(int *)(programState + 0x4c) != 0) {
    vec4Table = (**(code **)(ctx + 0xc))(*(int *)(programState + 0x4c) * 0x10 + 0x10);
    *(undefined4 *)(programState + 0x124) = vec4Table;
    *(undefined4 *)(((unsigned char *)0x00001174) + programState) = *(undefined4 *)(programState + 0x4c);
  }
  *(undefined1 *)(programState + 0x36) = *(undefined1 *)((int)shader + 0x79);
  emitState = (**(code **)(((unsigned char *)0x0000128c) + ctx))(ctx,emitState);
  if (emitState != 0) {
    *(undefined1 *)(shader + 4) = 0;
  }
  (**(code **)(((unsigned char *)0x000012b8) + ctx))(ctx,shader);
  *(undefined1 *)(ctx + 0x29) = 1;
  ((int (*)())vpStateCacheInsert)(ctx,shader);
  *(undefined1 *)(shader[1] + *(int *)(((unsigned char *)0x0000118c) + ctx)) = 0;
  if (*(int *)(((unsigned char *)0x000013d8) + programState) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(((unsigned char *)0x000013d8) + programState));
    *(undefined4 *)(((unsigned char *)0x000013d8) + programState) = 0;
  }
  return *(undefined1 *)(shader + 4);
}

/* evsEncodeSource @ 0x738c0 (2852 bytes) */
int evsEncodeSource(compiler, instructionArray, compileState, operand, isScalarSource, swizzleOverride)
  int compiler;
  uint *instructionArray;
  int compileState;
  int *operand;
  int isScalarSource;
  uint *swizzleOverride;
{
  uint uVar1;
  uint registerWord;
  undefined4 uVar3;
  int symbol;
  uint uVar5;
  uint uVar6;
  int dataType;
  undefined *swizzleWord;
  uint uVar9;
  undefined *puVar10;
  
  swizzleWord = ((unsigned char *)0x00003210);
  switch(operand[2]) {
  case 0x87d9:
    swizzleWord = ((unsigned char *)0x00003218);
  case 0x87d5:
    break;
  case 0x87da:
    swizzleWord = ((unsigned char *)0x00003218);
  case 0x87d6:
    swizzleWord = (undefined *)((uint)swizzleWord | 1);
    break;
  case 0x87db:
    swizzleWord = ((unsigned char *)0x00003218);
  case 0x87d7:
    swizzleWord = (undefined *)((uint)swizzleWord | 2);
    break;
  case 0x87dc:
    swizzleWord = ((unsigned char *)0x00003218);
  case 0x87d8:
    swizzleWord = (undefined *)((uint)swizzleWord | 3);
    break;
  case 0x87dd:
    swizzleWord = ((unsigned char *)0x00003214);
    break;
  case 0x87de:
    swizzleWord = ((unsigned char *)0x00003215);
  }
  switch(operand[3]) {
  case 0x87d9:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x80);
  case 0x87d5:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffffff8f);
    break;
  case 0x87da:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x80);
  case 0x87d6:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffffff8f | 0x10);
    break;
  case 0x87db:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x80);
  case 0x87d7:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffffff8f | 0x20);
    break;
  case 0x87dc:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x80);
  case 0x87d8:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffffff8f | 0x30);
    break;
  case 0x87dd:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffffff8f | 0x40);
    break;
  case 0x87de:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffffff8f | 0x50);
  }
  switch(operand[4]) {
  case 0x87d9:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x800);
  case 0x87d5:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xfffff8ff);
    break;
  case 0x87da:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x800);
  case 0x87d6:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xfffff8ff | 0x100);
    break;
  case 0x87db:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x800);
  case 0x87d7:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xfffff8ff | 0x200);
    break;
  case 0x87dc:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x800);
  case 0x87d8:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xfffff8ff | 0x300);
    break;
  case 0x87dd:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xfffff8ff | 0x400);
    break;
  case 0x87de:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xfffff8ff | 0x500);
  }
  switch(operand[5]) {
  case 0x87d9:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x8000);
  case 0x87d5:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffff8fff);
    break;
  case 0x87da:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x8000);
  case 0x87d6:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffff8fff | 0x1000);
    break;
  case 0x87db:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x8000);
  case 0x87d7:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffff8fff | 0x2000);
    break;
  case 0x87dc:
    swizzleWord = (undefined *)((uint)swizzleWord | 0x8000);
  case 0x87d8:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffff8fff | 0x3000);
    break;
  case 0x87dd:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffff8fff | 0x4000);
    break;
  case 0x87de:
    swizzleWord = (undefined *)((uint)swizzleWord & 0xffff8fff | 0x5000);
  }
  if (swizzleOverride != (uint *)0x0) {
    uVar9 = *swizzleOverride;
    registerWord = uVar9 & 3;
    if (registerWord == 2) {
      swizzleWord = (undefined *)((uint)swizzleWord >> 8 & 7 | (uint)swizzleWord & 0xfffffff8);
    }
    else if (registerWord == 3) {
      swizzleWord = (undefined *)((uint)swizzleWord >> 0xc & 7 | (uint)swizzleWord & 0xfffffff8);
    }
    else if (registerWord == 1) {
      swizzleWord = (undefined *)((uint)swizzleWord >> 4 & 7 | (uint)swizzleWord & 0xfffffff8);
    }
    uVar6 = swizzleOverride[1];
    registerWord = uVar6 & 3;
    if (registerWord != 1) {
      if (registerWord == 0) {
        swizzleWord = (undefined *)(((uint)swizzleWord & 7) << 4 | (uint)swizzleWord & 0xffffff8f);
      }
      else if (registerWord == 2) {
        swizzleWord = (undefined *)((uint)swizzleWord >> 4 & 0x70 | (uint)swizzleWord & 0xffffff8f);
      }
      else if (registerWord == 3) {
        swizzleWord = (undefined *)((uint)swizzleWord >> 8 & 0x70 | (uint)swizzleWord & 0xffffff8f);
      }
    }
    uVar1 = swizzleOverride[2];
    registerWord = uVar1 & 3;
    if (registerWord == 1) {
      swizzleWord = (undefined *)(((uint)swizzleWord & 0x70) << 4 | (uint)swizzleWord & 0xfffff8ff);
    }
    else if (registerWord == 0) {
      swizzleWord = (undefined *)(((uint)swizzleWord & 7) << 8 | (uint)swizzleWord & 0xfffff8ff);
    }
    else if ((registerWord != 2) && (registerWord == 3)) {
      swizzleWord = (undefined *)((uint)swizzleWord >> 4 & 0x700 | (uint)swizzleWord & 0xfffff8ff);
    }
    uVar5 = swizzleOverride[3];
    registerWord = uVar5 & 3;
    if (registerWord == 1) {
      swizzleWord = (undefined *)(((uint)swizzleWord & 0x70) << 8 | (uint)swizzleWord & 0xffff8fff);
    }
    else if (registerWord == 0) {
      swizzleWord = (undefined *)(((uint)swizzleWord & 7) << 0xc | (uint)swizzleWord & 0xffff8fff);
    }
    else if (registerWord == 2) {
      swizzleWord = (undefined *)(((uint)swizzleWord & 0x700) << 4 | (uint)swizzleWord & 0xffff8fff);
    }
    if ((uVar9 & 4) != 0) {
      swizzleWord = (undefined *)(((uint)swizzleWord ^ 8) & 8 | (uint)swizzleWord & 0xfffffff7);
    }
    if ((uVar6 & 4) != 0) {
      swizzleWord = (undefined *)(((uint)swizzleWord ^ 0x80) & 0x80 | (uint)swizzleWord & 0xffffff7f);
    }
    if ((uVar1 & 4) != 0) {
      swizzleWord = (undefined *)(((uint)swizzleWord ^ 0x800) & 0x800 | (uint)swizzleWord & 0xfffff7ff);
    }
    if ((uVar5 & 4) != 0) {
      swizzleWord = (undefined *)(((uint)swizzleWord ^ 0x8000) & 0x8000 | (uint)swizzleWord & 0xffff7fff);
    }
    if ((uVar9 & 8) != 0) {
      swizzleWord = (undefined *)((uint)swizzleWord & 0xffff7777 | 0x100000);
    }
    if ((uVar6 & 8) != 0) {
      swizzleWord = (undefined *)((uint)swizzleWord & 0xffff7777 | 0x100000);
    }
    if ((uVar1 & 8) != 0) {
      swizzleWord = (undefined *)((uint)swizzleWord & 0xffff7777 | 0x100000);
    }
    if ((uVar5 & 8) != 0) {
      swizzleWord = (undefined *)((uint)swizzleWord & 0xffff7777 | 0x100000);
    }
  }
  puVar10 = swizzleWord;
  if (*operand != 2) {
    if (*operand != 0) {
      return 0;
    }
    registerWord = 0x40000;
    goto LAB_00074014;
  }
  symbol = operand[1] * 0x54 + *(int *)(compileState + 0x20);
  registerWord = *(uint *)(symbol + 0x28);
  dataType = *(int *)(symbol + 0x24);
  if (registerWord < 0x87c4) {
    if (registerWord < 0x87c2) {
      if (registerWord != 0x87c1) {
        return 0;
      }
      if (dataType == 0x87bf) {
        registerWord = *(uint *)(symbol + 4) & 0xffff | 0x50000;
        if ((*(char *)(symbol + 0x44) != '\0') && (*(int *)(symbol + 0x48) == 1)) {
          puVar10 = (undefined *)((uint)swizzleWord & 0xffff8fff | 0x4000);
        }
      }
      else if (dataType == 0x87c0) {
        registerWord = *(uint *)(symbol + 0x10) & 0xffff | 0x50000;
      }
      else {
        if (dataType != 0x87be) {
          return 0;
        }
        uVar9 = *(uint *)(symbol + 8);
        registerWord = *(uint *)(symbol + 4) & 0xffff | 0x50000;
        puVar10 = (undefined *)
                  ((uVar9 & 7) << 0xc |
                  (uVar9 & 7) << 8 | (uVar9 & 7) << 4 | uVar9 & 7 | (uint)swizzleWord & 0xffff8888);
        if ((*(char *)(symbol + 0x44) != '\0') && (*(int *)(symbol + 0x48) == 0xf)) {
          puVar10 = (undefined *)((uint)swizzleWord & 0xffff8888 | 0x5441);
        }
      }
      goto LAB_00074014;
    }
    if (dataType == 0x87bf) {
      registerWord = *(uint *)(symbol + 4) & 0xffff | 0x10000;
      goto LAB_00074014;
    }
    if (dataType == 0x87c0) {
      registerWord = *(uint *)(symbol + 0x10) & 0xffff | 0x10000;
      goto LAB_00074014;
    }
    if (dataType != 0x87be) {
      return 0;
    }
    uVar9 = *(uint *)(symbol + 8);
    registerWord = *(uint *)(symbol + 4);
    symbol = 1;
  }
  else {
    if (registerWord != 0x87c4) {
      return 0;
    }
    if (dataType == 0x87bf) {
      registerWord = *(uint *)(symbol + 4) & 0xffff | 0x40000;
      goto LAB_00074014;
    }
    if (dataType == 0x87c0) {
      registerWord = *(uint *)(symbol + 0x10) & 0xffff | 0x40000;
      goto LAB_00074014;
    }
    if (dataType != 0x87be) {
      return 0;
    }
    uVar9 = *(uint *)(symbol + 8);
    registerWord = *(uint *)(symbol + 4);
    symbol = 4;
  }
  registerWord = registerWord & 0xffff | symbol << 0x10;
  puVar10 = (undefined *)
            ((uVar9 & 7) << 0xc |
            (uVar9 & 7) << 8 | (uVar9 & 7) << 4 | uVar9 & 7 | (uint)swizzleWord & 0xffff8888);
LAB_00074014:
  if ((isScalarSource == 0) && (puVar10 == ((unsigned char *)0x00003210))) {
    if (*(char *)(operand + 6) == '\0') {
      uVar9 = *instructionArray;
      if (instructionArray[1] <= uVar9) {
        uVar9 = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
        if (instructionArray[2] != 0) {
          _memcpy(uVar9,instructionArray[2],*instructionArray << 2);
          (**(code **)(compiler + 0x18))(instructionArray[2]);
        }
        instructionArray[2] = uVar9;
        uVar9 = *instructionArray;
        instructionArray[1] = instructionArray[1] + 0x80;
      }
      uVar3 = 1;
      *(uint *)(uVar9 * 4 + instructionArray[2]) = registerWord;
      *instructionArray = *instructionArray + 1;
    }
    else {
      uVar9 = *instructionArray;
      if (instructionArray[1] <= uVar9) {
        uVar9 = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
        if (instructionArray[2] != 0) {
          _memcpy(uVar9,instructionArray[2],*instructionArray << 2);
          (**(code **)(compiler + 0x18))(instructionArray[2]);
        }
        instructionArray[2] = uVar9;
        uVar9 = *instructionArray;
        instructionArray[1] = instructionArray[1] + 0x80;
      }
      *(uint *)(uVar9 * 4 + instructionArray[2]) = registerWord | 0x800000;
      registerWord = *instructionArray + 1;
      *instructionArray = registerWord;
      if (instructionArray[1] <= registerWord) {
        registerWord = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
        if (instructionArray[2] != 0) {
          _memcpy(registerWord,instructionArray[2],*instructionArray << 2);
          (**(code **)(compiler + 0x18))(instructionArray[2]);
        }
        instructionArray[2] = registerWord;
        registerWord = *instructionArray;
        instructionArray[1] = instructionArray[1] + 0x80;
      }
      uVar3 = 2;
      *(undefined4 *)(registerWord * 4 + instructionArray[2]) = 0;
      *instructionArray = *instructionArray + 1;
    }
  }
  else if (*(char *)(operand + 6) == '\0') {
    uVar9 = *instructionArray;
    if (instructionArray[1] <= uVar9) {
      uVar9 = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
      if (instructionArray[2] != 0) {
        _memcpy(uVar9,instructionArray[2],*instructionArray << 2);
        (**(code **)(compiler + 0x18))(instructionArray[2]);
      }
      instructionArray[2] = uVar9;
      uVar9 = *instructionArray;
      instructionArray[1] = instructionArray[1] + 0x80;
    }
    *(uint *)(uVar9 * 4 + instructionArray[2]) = registerWord | 0x400000;
    registerWord = *instructionArray + 1;
    *instructionArray = registerWord;
    if (instructionArray[1] <= registerWord) {
      registerWord = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
      if (instructionArray[2] != 0) {
        _memcpy(registerWord,instructionArray[2],*instructionArray << 2);
        (**(code **)(compiler + 0x18))(instructionArray[2]);
      }
      instructionArray[2] = registerWord;
      registerWord = *instructionArray;
      instructionArray[1] = instructionArray[1] + 0x80;
    }
    uVar3 = 2;
    *(undefined **)(registerWord * 4 + instructionArray[2]) = puVar10;
    *instructionArray = *instructionArray + 1;
  }
  else {
    uVar9 = *instructionArray;
    if (instructionArray[1] <= uVar9) {
      uVar9 = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
      if (instructionArray[2] != 0) {
        _memcpy(uVar9,instructionArray[2],*instructionArray << 2);
        (**(code **)(compiler + 0x18))(instructionArray[2]);
      }
      instructionArray[2] = uVar9;
      uVar9 = *instructionArray;
      instructionArray[1] = instructionArray[1] + 0x80;
    }
    *(uint *)(uVar9 * 4 + instructionArray[2]) = registerWord | 0xc00000;
    registerWord = *instructionArray + 1;
    *instructionArray = registerWord;
    if (instructionArray[1] <= registerWord) {
      registerWord = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
      if (instructionArray[2] != 0) {
        _memcpy(registerWord,instructionArray[2],*instructionArray << 2);
        (**(code **)(compiler + 0x18))(instructionArray[2]);
      }
      instructionArray[2] = registerWord;
      registerWord = *instructionArray;
      instructionArray[1] = instructionArray[1] + 0x80;
    }
    *(undefined **)(registerWord * 4 + instructionArray[2]) = puVar10;
    registerWord = *instructionArray + 1;
    *instructionArray = registerWord;
    if (instructionArray[1] <= registerWord) {
      registerWord = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
      if (instructionArray[2] != 0) {
        _memcpy(registerWord,instructionArray[2],*instructionArray << 2);
        (**(code **)(compiler + 0x18))(instructionArray[2]);
      }
      instructionArray[2] = registerWord;
      registerWord = *instructionArray;
      instructionArray[1] = instructionArray[1] + 0x80;
    }
    uVar3 = 3;
    *(undefined4 *)(registerWord * 4 + instructionArray[2]) = 0;
    *instructionArray = *instructionArray + 1;
  }
  return uVar3;
}

/* evsEncodeDestination @ 0x744d0 (1412 bytes) */
int evsEncodeDestination(compiler, instructionArray, compileState, destination, asSource)
  int compiler;
  uint *instructionArray;
  int *compileState;
  int *destination;
  int asSource;
{
  undefined4 uVar1;
  int iVar2;
  uint symbolKind;
  int stateBlock;
  uint maskBits;
  uint registerWord;
  
  maskBits = 0x55;
  stateBlock = **(int **)(*(int *)(((unsigned char *)0x0000118c) + compiler) * 4 + *compileState);
  if (destination[2] == 0) {
    maskBits = 0x54;
  }
  iVar2 = destination[3];
  if (iVar2 == 0) {
    maskBits = maskBits & 0xfffffff3;
  }
  if (destination[4] == 0) {
    maskBits = maskBits & 0xffffffcf;
  }
  if (destination[5] == 0) {
    maskBits = maskBits & 0xffffff3f;
  }
  if (*destination == 1) {
    symbolKind = destination[1];
    if (symbolKind == 0x879b) {
      maskBits = maskBits | 0x100;
      *(undefined1 *)((int)compileState + 0x6d) = 1;
      registerWord = 0x120000;
    }
    else if (symbolKind < 0x879c) {
      if (symbolKind == 0x610f) {
        maskBits = maskBits | 0x100;
        *(undefined1 *)((int)compileState + 0x6f) = 1;
        registerWord = 0x120001;
      }
      else if (symbolKind < 0x6110) {
        if (symbolKind != 0x610e) {
          return 0;
        }
        *(undefined1 *)((int)compileState + 0x79) = 1;
        registerWord = 0xd0000;
        maskBits = maskBits & 0xffffff03;
      }
      else if (symbolKind == 0x6110) {
        maskBits = maskBits | 0x100;
        *(undefined1 *)(compileState + 0x1c) = 1;
        registerWord = 0x130001;
      }
      else {
        if (symbolKind != 0x879a) {
          return 0;
        }
        registerWord = 0xe0000;
      }
    }
    else if (symbolKind < 0x87a5) {
      if (symbolKind < 0x879d) {
        maskBits = maskBits | 0x100;
        *(undefined1 *)((int)compileState + 0x6e) = 1;
        registerWord = 0x130000;
      }
      else {
        registerWord = symbolKind + 0x7863 & 0xffff | 0x110000;
        if (destination[2] == 1) {
          *(byte *)((int)compileState + (symbolKind - 0x872c)) =
               *(byte *)((int)compileState + (symbolKind - 0x872c)) | 1;
          iVar2 = destination[3];
        }
        if (iVar2 == 1) {
          *(byte *)((int)compileState + destination[1] + -0x872c) =
               *(byte *)((int)compileState + destination[1] + -0x872c) | 2;
        }
        if (destination[4] == 1) {
          *(byte *)((int)compileState + destination[1] + -0x872c) =
               *(byte *)((int)compileState + destination[1] + -0x872c) | 4;
        }
        if (destination[5] == 1) {
          *(byte *)((int)compileState + destination[1] + -0x872c) =
               *(byte *)((int)compileState + destination[1] + -0x872c) | 8;
        }
      }
    }
    else {
      if (symbolKind != 0x87bd) {
        return 0;
      }
      symbolKind = *(uint *)(((unsigned char *)0x000013c0) + stateBlock);
      *(undefined1 *)((int)compileState + 0x7a) = 1;
      *(undefined1 *)(stateBlock + 0x33) = 1;
      registerWord = symbolKind & 0xffff | 0x40000;
      maskBits = maskBits & 0xffffff03;
    }
  }
  else {
    if (*destination != 2) {
      return 0;
    }
    stateBlock = destination[1] * 0x54 + compileState[8];
    iVar2 = *(int *)(stateBlock + 0x24);
    if (*(int *)(stateBlock + 0x28) == 0x87c4) {
      if (iVar2 == 0x87bf) {
        registerWord = *(uint *)(stateBlock + 4) & 0xffff | 0x40000;
      }
      else if (iVar2 == 0x87c0) {
        registerWord = *(uint *)(stateBlock + 0x10) & 0xffff | 0x40000;
      }
      else {
        if (iVar2 != 0x87be) {
          return 0;
        }
        iVar2 = *(int *)(stateBlock + 8);
        registerWord = *(uint *)(stateBlock + 4) & 0xffff | 0x40000;
        if (iVar2 == 1) {
          maskBits = maskBits & 0xffffff0c;
        }
        else if (iVar2 == 0) {
          maskBits = maskBits & 0xffffff03;
        }
        else if (iVar2 == 2) {
          maskBits = maskBits & 0xffffff30;
        }
        else {
          if (iVar2 != 3) {
            return 0;
          }
          maskBits = maskBits & 0xffffffc0;
        }
      }
    }
    else {
      if (*(int *)(stateBlock + 0x28) != -1) {
        return 0;
      }
      registerWord = 0x30000;
    }
  }
  if ((asSource == 0) && (maskBits == 0x55)) {
    maskBits = *instructionArray;
    if (instructionArray[1] <= maskBits) {
      maskBits = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
      if (instructionArray[2] != 0) {
        _memcpy(maskBits,instructionArray[2],*instructionArray << 2);
        (**(code **)(compiler + 0x18))(instructionArray[2]);
      }
      instructionArray[2] = maskBits;
      maskBits = *instructionArray;
      instructionArray[1] = instructionArray[1] + 0x80;
    }
    uVar1 = 1;
    *(uint *)(maskBits * 4 + instructionArray[2]) = registerWord;
    *instructionArray = *instructionArray + 1;
  }
  else {
    symbolKind = *instructionArray;
    if (instructionArray[1] <= symbolKind) {
      symbolKind = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
      if (instructionArray[2] != 0) {
        _memcpy(symbolKind,instructionArray[2],*instructionArray << 2);
        (**(code **)(compiler + 0x18))(instructionArray[2]);
      }
      instructionArray[2] = symbolKind;
      symbolKind = *instructionArray;
      instructionArray[1] = instructionArray[1] + 0x80;
    }
    *(uint *)(symbolKind * 4 + instructionArray[2]) = registerWord | 0x400000;
    symbolKind = *instructionArray + 1;
    *instructionArray = symbolKind;
    if (instructionArray[1] <= symbolKind) {
      symbolKind = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
      if (instructionArray[2] != 0) {
        _memcpy(symbolKind,instructionArray[2],*instructionArray << 2);
        (**(code **)(compiler + 0x18))(instructionArray[2]);
      }
      instructionArray[2] = symbolKind;
      symbolKind = *instructionArray;
      instructionArray[1] = instructionArray[1] + 0x80;
    }
    uVar1 = 2;
    *(uint *)(symbolKind * 4 + instructionArray[2]) = maskBits;
    *instructionArray = *instructionArray + 1;
  }
  return uVar1;
}

/* evsAppendInstruction @ 0x74a70 (192 bytes) */
int evsAppendInstruction(compiler, instructionArray, opcode, modifier)
  int compiler;
  uint *instructionArray;
  uint opcode;
  uint modifier;
{
  uint count;
  
  count = *instructionArray;
  if (instructionArray[1] <= count) {
    count = (**(code **)(compiler + 0xc))(instructionArray[1] * 4 + 0x200);
    if (instructionArray[2] != 0) {
      _memcpy(count,instructionArray[2],*instructionArray << 2);
      (**(code **)(compiler + 0x18))(instructionArray[2]);
    }
    instructionArray[2] = count;
    count = *instructionArray;
    instructionArray[1] = instructionArray[1] + 0x80;
  }
  *(uint *)(count * 4 + instructionArray[2]) = (modifier & 0x3fff) << 0x10 | opcode & 0xffff;
  *instructionArray = *instructionArray + 1;
  return 1;
}

/* evsEmitMova @ 0x74b30 (204 bytes) */
int evsEmitMova(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int evsAppendInstructionResult;
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
  evsAppendInstructionResult = ((int (*)())evsAppendInstruction)(param_1,iVar2,0x48,0);
  if (evsAppendInstructionResult != 0) {
    local_48 = *(undefined4 *)(param_4 + 4);
    local_44 = *(undefined4 *)(param_4 + 8);
    local_30 = *(undefined4 *)(param_4 + 0x1c);
    local_34 = 0;
    local_3c = 0;
    local_38 = 0;
    local_40 = 1;
    iVar1 = ((int (*)())evsEncodeDestination)(param_1,iVar2,param_3,&local_48,1);
    if ((iVar1 != 0) && (iVar1 = ((int (*)())evsEncodeSource)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)
       ) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* evsEmitLogp @ 0x74c00 (188 bytes) */
int evsEmitLogp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int evsEncodeSourceResult;
  int iVar1;
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())evsAppendInstruction)(param_1,iVar2,0x3d,0);
  if ((iVar1 != 0) && (iVar1 = ((int (*)())evsEncodeDestination)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) {
    uStack_2c = 4;
    uStack_34 = 4;
    uStack_30 = 4;
    uStack_38 = 0xc;
    evsEncodeSourceResult = ((int (*)())evsEncodeSource)(param_1,iVar2,param_3,param_4 + 0x20,1,&uStack_38);
    if (evsEncodeSourceResult != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* evsEmitExpp @ 0x74cc0 (156 bytes) */
int evsEmitExpp(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x2e,0);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,1,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitDst @ 0x74d60 (204 bytes) */
int evsEmitDst(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x24,0);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitLit @ 0x74e30 (156 bytes) */
int evsEmitLit(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x39,0);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitOp879d @ 0x74ed0 (392 bytes) */
int evsEmitOp879d(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int evsEncodeDestinationResult;
  int evsEncodeSourceResult;
  int extvsOperandDataTypeResult;
  int evsAppendInstructionResult;
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
  
  extvsOperandDataTypeResult = extvsOperandDataType(param_3 + 0x1c,param_4 + 4);
  uVar4 = *(uint *)(param_4 + 0x40);
  if (3 < uVar4) {
    return 0xffffffff;
  }
  iVar3 = param_2 + 4;
  evsAppendInstructionResult = ((int (*)())evsAppendInstruction)(param_1,iVar3,0x47,0);
  if (evsAppendInstructionResult == 0) {
    return 0xffffffff;
  }
  evsEncodeDestinationResult = ((int (*)())evsEncodeDestination)(param_1,iVar3,param_3,param_4 + 4,0);
  if (evsEncodeDestinationResult == 0) {
    return 0xffffffff;
  }
  uStack_30 = *(undefined4 *)(param_4 + 0x38);
  uStack_48 = *(undefined4 *)(param_4 + 0x20);
  iStack_44 = *(int *)(param_4 + 0x24);
  uStack_3c = *(undefined4 *)(param_4 + 0x2c);
  uStack_38 = *(undefined4 *)(param_4 + 0x30);
  uStack_34 = *(undefined4 *)(param_4 + 0x34);
  uStack_40 = *(undefined4 *)(param_4 + 0x28);
  if (extvsOperandDataTypeResult != 0x87be) {
    iStack_44 = uVar4 + iStack_44;
    evsEncodeSourceResult = ((int (*)())evsEncodeSource)(param_1,iVar3,param_3,&uStack_48,1,0);
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
  evsEncodeSourceResult = ((int (*)())evsEncodeSource)(param_1,iVar3,param_3,&uStack_48,1,&uStack_58);
LAB_00075028:
  if (evsEncodeSourceResult == 0) {
    return 0xffffffff;
  }
  return 1;
}

/* evsEmitOp879c @ 0x75060 (584 bytes) */
int evsEmitOp879c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int evsEncodeDestinationResult;
  int extvsOperandDataTypeResult;
  int evsAppendInstructionResult;
  int iVar3;
  uint uVar4;
  uint uStack_48;
  uint uStack_44;
  uint uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  
  extvsOperandDataTypeResult = extvsOperandDataType(param_3 + 0x1c,param_4 + 4);
  uVar4 = *(uint *)(param_4 + 0x40);
  if (3 < uVar4) {
    return 0xffffffff;
  }
  iVar3 = param_2 + 4;
  evsAppendInstructionResult = ((int (*)())evsAppendInstruction)(param_1,iVar3,0x47,0);
  if (evsAppendInstructionResult == 0) {
    return 0xffffffff;
  }
  if (extvsOperandDataTypeResult == 0x87bf) {
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
    evsEncodeDestinationResult = ((int (*)())evsEncodeDestination)(param_1,iVar3,param_3,&uStack_48,1);
  }
  else {
    uStack_48 = *(uint *)(param_4 + 4);
    uStack_40 = *(uint *)(param_4 + 0xc);
    uStack_3c = *(uint *)(param_4 + 0x10);
    uStack_38 = *(undefined4 *)(param_4 + 0x14);
    uStack_34 = *(undefined4 *)(param_4 + 0x18);
    uStack_30 = *(undefined4 *)(param_4 + 0x1c);
    uStack_44 = uVar4 + *(int *)(param_4 + 8);
    evsEncodeDestinationResult = ((int (*)())evsEncodeDestination)(param_1,iVar3,param_3,&uStack_48,1);
  }
  if (evsEncodeDestinationResult == 0) {
    return 0xffffffff;
  }
  if (extvsOperandDataTypeResult != 0x87bf) {
    ((int (*)())evsEncodeSource)(param_1,iVar3,param_3,param_4 + 0x20,1,0);
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
  ((int (*)())evsEncodeSource)(param_1,iVar3,param_3,param_4 + 0x20,1,&uStack_48);
  return 1;
}

/* evsEmitOp879b @ 0x752c0 (156 bytes) */
int evsEmitOp879b(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x47,0);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,1), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitOp879a @ 0x75360 (156 bytes) */
int evsEmitOp879a(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x47,0);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitMovOp8799 @ 0x75400 (156 bytes) */
int evsEmitMovOp8799(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x47,0);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitMmul @ 0x754a0 (204 bytes) */
int evsEmitMmul(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x45,0);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitCrs @ 0x75570 (204 bytes) */
int evsEmitCrs(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x13,0);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitSub @ 0x75640 (204 bytes) */
int evsEmitSub(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x5b,0);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitRsq @ 0x75710 (156 bytes) */
int evsEmitRsq(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x55,3);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitRcp @ 0x757b0 (156 bytes) */
int evsEmitRcp(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x51,3);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitPow @ 0x75850 (204 bytes) */
int evsEmitPow(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x4e,0);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitLog @ 0x75920 (156 bytes) */
int evsEmitLog(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x3c,0);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitExp @ 0x759c0 (156 bytes) */
int evsEmitExp(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x2d,0);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitRnd @ 0x75a60 (156 bytes) */
int evsEmitRnd(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x54,0);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitFlr @ 0x75b00 (156 bytes) */
int evsEmitFlr(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x30,0);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitClamp @ 0x75ba0 (236 bytes) */
int evsEmitClamp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())evsAppendInstruction)(param_1,iVar2,10,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())evsEncodeDestination)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())evsEncodeSource)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     ((iVar1 = ((int (*)())evsEncodeSource)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0 &&
      (iVar1 = ((int (*)())evsEncodeSource)(param_1,iVar2,param_3,param_4 + 0x58,0,0), iVar1 != 0)))) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitSetCompare5 @ 0x75c90 (204 bytes) */
int evsEmitSetCompare5(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x56,5);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitSetCompare2 @ 0x75d60 (204 bytes) */
int evsEmitSetCompare2(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x56,2);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitMin @ 0x75e30 (204 bytes) */
int evsEmitMin(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x44,0);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitMax @ 0x75f00 (204 bytes) */
int evsEmitMax(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x41,0);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitFrc @ 0x75fd0 (156 bytes) */
int evsEmitFrc(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x31,0);
  if (((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitMad @ 0x76070 (236 bytes) */
int evsEmitMad(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())evsAppendInstruction)(param_1,iVar2,0x40,0);
  if ((((iVar1 != 0) && (iVar1 = ((int (*)())evsEncodeDestination)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) &&
      (iVar1 = ((int (*)())evsEncodeSource)(param_1,iVar2,param_3,param_4 + 0x20,0,0), iVar1 != 0)) &&
     ((iVar1 = ((int (*)())evsEncodeSource)(param_1,iVar2,param_3,param_4 + 0x3c,0,0), iVar1 != 0 &&
      (iVar1 = ((int (*)())evsEncodeSource)(param_1,iVar2,param_3,param_4 + 0x58,0,0), iVar1 != 0)))) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitAdd @ 0x76160 (204 bytes) */
int evsEmitAdd(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,3,0);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitMul @ 0x76230 (204 bytes) */
int evsEmitMul(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x49,0);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitDp4 @ 0x76300 (204 bytes) */
int evsEmitDp4(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x23,0);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitDp3 @ 0x763d0 (204 bytes) */
int evsEmitDp3(compiler, program, compileState, irInstruction)
  undefined4 compiler;
  int program;
  undefined4 compileState;
  int irInstruction;
{
  int emitted;
  int code;
  
  code = program + 4;
  emitted = ((int (*)())evsAppendInstruction)(compiler,code,0x22,0);
  if ((((emitted != 0) && (emitted = ((int (*)())evsEncodeDestination)(compiler,code,compileState,irInstruction + 4,0), emitted != 0)) &&
      (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x20,0,0), emitted != 0)) &&
     (emitted = ((int (*)())evsEncodeSource)(compiler,code,compileState,irInstruction + 0x3c,0,0), emitted != 0)) {
    return 1;
  }
  return 0xffffffff;
}

/* evsEmitMov @ 0x764a0 (188 bytes) */
int evsEmitMov(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int evsEncodeSourceResult;
  int iVar1;
  int iVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  iVar2 = param_2 + 4;
  iVar1 = ((int (*)())evsAppendInstruction)(param_1,iVar2,0x47,0);
  if ((iVar1 != 0) && (iVar1 = ((int (*)())evsEncodeDestination)(param_1,iVar2,param_3,param_4 + 4,0), iVar1 != 0)) {
    uStack_38 = 4;
    uStack_34 = 5;
    uStack_30 = 6;
    uStack_2c = 7;
    evsEncodeSourceResult = ((int (*)())evsEncodeSource)(param_1,iVar2,param_3,param_4 + 0x20,1,&uStack_38);
    if (evsEncodeSourceResult != 0) {
      return 1;
    }
  }
  return 0xffffffff;
}

/* evsEmitIndexOrMove @ 0x76560 (524 bytes) */
int evsEmitIndexOrMove(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int evsEncodeDestinationResult;
  int evsEncodeSourceResult;
  int evsAppendInstructionResult;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = (uint *)(param_2 + 4);
  evsAppendInstructionResult = ((int (*)())evsAppendInstruction)(param_1,puVar4,0x48,0);
  if (evsAppendInstructionResult != 0) {
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
    evsEncodeSourceResult = ((int (*)())evsEncodeSource)(param_1,puVar4,param_3,param_4 + 0x20,0,0);
    if (evsEncodeSourceResult != 0) {
      ((int (*)())evsAppendInstruction)(param_1,puVar4,0x47,0);
      evsEncodeDestinationResult = ((int (*)())evsEncodeDestination)(param_1,puVar4,param_3,param_4 + 4,0);
      if (evsEncodeDestinationResult != 0) {
        *(undefined1 *)(param_4 + 0x54) = 1;
        evsEncodeSourceResult = ((int (*)())evsEncodeSource)(param_1,puVar4,param_3,param_4 + 0x3c,0,0);
        if (evsEncodeSourceResult != 0) {
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
      *(code **)(((unsigned char *)0x00001350) + param_1) = vpStateSetConstantVector;
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

/* vpStateCacheInsert @ 0x76b80 (116 bytes) */
int vpStateCacheInsert(ctx, shader)
  int ctx;
  int *shader;
{
  uint stateKey;
  int *stateTable;
  int state;
  
  stateTable = *(int **)(*(int *)(((unsigned char *)0x0000118c) + ctx) * 4 + *shader);
  state = *stateTable;
  stateKey = ((int (*)())FUN_00076ac0)(ctx,state);
  *(uint *)(state + 0x38) = stateKey;
  *(int *)(state + 0x138) = stateTable[(stateKey & 0x1f) + 1];
  stateTable[(stateKey & 0x1f) + 1] = state;
  *(undefined1 *)(state + 0x134) = 1;
  stateTable[0x21] = stateTable[0x21] + 1;
  return;
}

/* noop_76c00 @ 0x76c00 (4 bytes) */
int noop_76c00()
{
  return;
}

/* vpStateCacheLookup @ 0x76c10 (72 bytes) */
int vpStateCacheLookup(stateTable, stateId)
  int stateTable;
  uint stateId;
{
  int state;
  
  state = *(int *)((stateId & 0x1f) * 4 + stateTable + 4);
  if (state != 0) {
    if (stateId == *(uint *)(state + 0x38)) {
      return state;
    }
    while (state = *(int *)(state + 0x138), state != 0) {
      if (stateId == *(uint *)(state + 0x38)) {
        return state;
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
asm(".globl arbEmitIlRcp");
asm(".set arbEmitIlRcp, _arbEmitIlRcp");
asm(".globl arbEmitIlRsq");
asm(".set arbEmitIlRsq, _arbEmitIlRsq");
asm(".globl arbEmitIlExp");
asm(".set arbEmitIlExp, _arbEmitIlExp");
asm(".globl arbEmitIlExn");
asm(".set arbEmitIlExn, _arbEmitIlExn");
asm(".globl arbEmitIlPow");
asm(".set arbEmitIlPow, _arbEmitIlPow");
asm(".globl FUN_0006e460");
asm(".set FUN_0006e460, _FUN_0006e460");
asm(".globl arbEmitIlMovMadMov");
asm(".set arbEmitIlMovMadMov, _arbEmitIlMovMadMov");
asm(".globl noop_70c50");
asm(".set noop_70c50, _noop_70c50");
asm(".globl noop_70c60");
asm(".set noop_70c60, _noop_70c60");
asm(".globl evsAssignVertexInputs");
asm(".set evsAssignVertexInputs, _evsAssignVertexInputs");
asm(".globl evsEmitMova");
asm(".set evsEmitMova, _evsEmitMova");
asm(".globl evsEmitLogp");
asm(".set evsEmitLogp, _evsEmitLogp");
asm(".globl evsEmitExpp");
asm(".set evsEmitExpp, _evsEmitExpp");
asm(".globl evsEmitDst");
asm(".set evsEmitDst, _evsEmitDst");
asm(".globl evsEmitLit");
asm(".set evsEmitLit, _evsEmitLit");
asm(".globl evsEmitOp879d");
asm(".set evsEmitOp879d, _evsEmitOp879d");
asm(".globl evsEmitOp879c");
asm(".set evsEmitOp879c, _evsEmitOp879c");
asm(".globl evsEmitOp879b");
asm(".set evsEmitOp879b, _evsEmitOp879b");
asm(".globl evsEmitOp879a");
asm(".set evsEmitOp879a, _evsEmitOp879a");
asm(".globl evsEmitMovOp8799");
asm(".set evsEmitMovOp8799, _evsEmitMovOp8799");
asm(".globl evsEmitMmul");
asm(".set evsEmitMmul, _evsEmitMmul");
asm(".globl evsEmitCrs");
asm(".set evsEmitCrs, _evsEmitCrs");
asm(".globl evsEmitSub");
asm(".set evsEmitSub, _evsEmitSub");
asm(".globl evsEmitRsq");
asm(".set evsEmitRsq, _evsEmitRsq");
asm(".globl evsEmitRcp");
asm(".set evsEmitRcp, _evsEmitRcp");
asm(".globl evsEmitPow");
asm(".set evsEmitPow, _evsEmitPow");
asm(".globl evsEmitLog");
asm(".set evsEmitLog, _evsEmitLog");
asm(".globl evsEmitExp");
asm(".set evsEmitExp, _evsEmitExp");
asm(".globl evsEmitRnd");
asm(".set evsEmitRnd, _evsEmitRnd");
asm(".globl evsEmitFlr");
asm(".set evsEmitFlr, _evsEmitFlr");
asm(".globl evsEmitClamp");
asm(".set evsEmitClamp, _evsEmitClamp");
asm(".globl evsEmitSetCompare5");
asm(".set evsEmitSetCompare5, _evsEmitSetCompare5");
asm(".globl evsEmitSetCompare2");
asm(".set evsEmitSetCompare2, _evsEmitSetCompare2");
asm(".globl evsEmitMin");
asm(".set evsEmitMin, _evsEmitMin");
asm(".globl evsEmitMax");
asm(".set evsEmitMax, _evsEmitMax");
asm(".globl evsEmitFrc");
asm(".set evsEmitFrc, _evsEmitFrc");
asm(".globl evsEmitMad");
asm(".set evsEmitMad, _evsEmitMad");
asm(".globl evsEmitAdd");
asm(".set evsEmitAdd, _evsEmitAdd");
asm(".globl evsEmitMul");
asm(".set evsEmitMul, _evsEmitMul");
asm(".globl evsEmitDp4");
asm(".set evsEmitDp4, _evsEmitDp4");
asm(".globl evsEmitDp3");
asm(".set evsEmitDp3, _evsEmitDp3");
asm(".globl evsEmitMov");
asm(".set evsEmitMov, _evsEmitMov");
asm(".globl evsEmitIndexOrMove");
asm(".set evsEmitIndexOrMove, _evsEmitIndexOrMove");
asm(".globl FUN_000768e0");
asm(".set FUN_000768e0, _FUN_000768e0");
