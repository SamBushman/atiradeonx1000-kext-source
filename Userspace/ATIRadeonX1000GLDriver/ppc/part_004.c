#include "decls.h"

/* gldPrimWrapperTriangleFan_23a24 @ 0x243f0 (112 bytes) */
void gldPrimWrapperTriangleFan_23a24(int ctx,undefined4 extraVertexAttribs,int vertexAttribs,undefined4 elementCount,undefined4 extraArg4,undefined4 staleArgR8,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint vertexCount;
  undefined4 staleArgR9;
  
  vertexCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,6,elementCount,extraArg4,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (vertexCount != 0) {
    return gld_emitPrimitiveVertices(ctx + 0x240,5,extraVertexAttribs,vertexAttribs,vertexCount,extraArg4);
  }
  return;
}

/* gldPrimWrapperQuads_23a24 @ 0x24470 (112 bytes) */
void gldPrimWrapperQuads_23a24(int ctx,int vertexAttribs,undefined4 elementCount,undefined4 extraArg,undefined4 extraArg4,undefined4 staleArgR8,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint vertexCount;
  undefined4 staleArgR9;
  
  vertexCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,7,elementCount,extraArg4,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (vertexCount != 0) {
    return gld_emitPrimitiveVertices(ctx + 0x240,13,0,vertexAttribs,vertexCount,extraArg);
  }
  return;
}

/* gldPrimWrapperQuadStrip_23a24 @ 0x244f0 (112 bytes) */
void gldPrimWrapperQuadStrip_23a24(int ctx,int vertexAttribs,undefined4 elementCount,undefined4 extraArg,undefined4 extraArg4,undefined4 staleArgR8,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint vertexCount;
  undefined4 staleArgR9;
  
  vertexCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,8,elementCount,extraArg4,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (vertexCount != 0) {
    return gld_emitPrimitiveVertices(ctx + 0x240,14,0,vertexAttribs,vertexCount,extraArg);
  }
  return;
}

/* gldPrimWrapperPolygon_23a24 @ 0x24570 (112 bytes) */
void gldPrimWrapperPolygon_23a24(int ctx,int vertexAttribs,undefined4 elementCount,undefined4 extraArg,undefined4 extraArg4,undefined4 staleArgR8,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint vertexCount;
  undefined4 staleArgR9;
  
  vertexCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,9,elementCount,extraArg4,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (vertexCount != 0) {
    return gld_emitPrimitiveVertices(ctx + 0x240,15,0,vertexAttribs,vertexCount,extraArg);
  }
  return;
}

/* gldPrimWrapperPolygon_24190 @ 0x245f0 (108 bytes) */
void gldPrimWrapperPolygon_24190(int ctx,undefined4 *vertexData,undefined4 elementCount,undefined4 extraArg,undefined4 extraArg4,undefined4 staleArgR8,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint vertexCount;
  undefined4 staleArgR9;
  
  vertexCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,9,elementCount,extraArg4,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (vertexCount != 0) {
    return gld_emitImmediateVertexList(ctx + 0x240,15,vertexData,vertexCount,extraArg);
  }
  return;
}

/* gldPrimWrapperPoints_23a24 @ 0x24670 (108 bytes) */
void gldPrimWrapperPoints_23a24(int ctx,int vertexAttribs,undefined4 elementCount,undefined4 staleArgR6,undefined4 extraArg4,undefined4 staleArgR8,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint vertexCount;
  undefined4 staleArgR9;
  
  vertexCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,0,elementCount,extraArg4,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (vertexCount != 0) {
    return gld_emitPrimitiveVertices(ctx + 0x240,1,0,vertexAttribs,vertexCount,0);
  }
  return;
}

/* gldPrimWrapperPoints_24190 @ 0x246f0 (104 bytes) */
void gldPrimWrapperPoints_24190(int ctx,undefined4 *vertexData,undefined4 elementCount,undefined4 staleArgR6,undefined4 extraArg4,undefined4 staleArgR8,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint vertexCount;
  undefined4 staleArgR9;
  
  vertexCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,0,elementCount,extraArg4,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (vertexCount != 0) {
    return gld_emitImmediateVertexList(ctx + 0x240,1,vertexData,vertexCount,0);
  }
  return;
}

/* gldPrimWrapperLines_23a24 @ 0x24770 (108 bytes) */
void gldPrimWrapperLines_23a24(int ctx,int vertexAttribs,undefined4 elementCount,undefined4 staleArgR6,undefined4 extraArg4,undefined4 staleArgR8,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint vertexCount;
  undefined4 staleArgR9;
  
  vertexCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,1,elementCount,extraArg4,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (vertexCount != 0) {
    return gld_emitPrimitiveVertices(ctx + 0x240,2,0,vertexAttribs,vertexCount,0);
  }
  return;
}

/* gldPrimWrapperLines_24190 @ 0x247f0 (104 bytes) */
void gldPrimWrapperLines_24190(int ctx,undefined4 *vertexData,undefined4 elementCount,undefined4 staleArgR6,undefined4 extraArg4,undefined4 staleArgR8,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint vertexCount;
  undefined4 staleArgR9;
  
  vertexCount = ((uint (*)())gld_prepareDrawCount)(ctx,0,1,elementCount,extraArg4,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (vertexCount != 0) {
    return gld_emitImmediateVertexList(ctx + 0x240,2,vertexData,vertexCount,0);
  }
  return;
}

/* gldPrimWrapperLineLoop_23a24 @ 0x24870 (112 bytes) */
void gldPrimWrapperLineLoop_23a24(int ctx,int vertexAttribs,undefined4 elementCount,undefined4 closeFlag,undefined4 extraArg4,undefined4 staleArgR8,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint vertexCount;
  undefined4 staleArgR9;
  
  vertexCount = ((uint (*)())gld_prepareDrawCount)(ctx,closeFlag,2,elementCount,extraArg4,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (vertexCount != 0) {
    return gld_emitPrimitiveVertices(ctx + 0x240,12,0,vertexAttribs,vertexCount,closeFlag);
  }
  return;
}

/* gldPrimWrapperLineStrip_23a24 @ 0x248f0 (112 bytes) */
void gldPrimWrapperLineStrip_23a24(int ctx,int vertexAttribs,undefined4 elementCount,undefined4 closeFlag,undefined4 extraArg4,undefined4 staleArgR8,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint vertexCount;
  undefined4 staleArgR9;
  
  vertexCount = ((uint (*)())gld_prepareDrawCount)(ctx,closeFlag,3,elementCount,extraArg4,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleFprArg9);
  if (vertexCount != 0) {
    return gld_emitPrimitiveVertices(ctx + 0x240,3,0,vertexAttribs,vertexCount,closeFlag);
  }
  return;
}

/* gld_drawElementsImmediate @ 0x24970 (1588 bytes) */
void gld_drawElementsImmediate(int ctx,int glStateBlock,int primitiveMode,int indexBias,undefined4 indexCount,undefined *indexType,uint *indices,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  int blockCount;
  uint lastIndex;
  uint primitiveFlags;
  uint *indexCursor;
  uint *lastHeader;
  uint *packetAlloc;
  undefined4 vap_vte_cntl;
  uint *scratchPtr1;
  undefined4 *packetBody;
  int trimmedCount;
  undefined4 *packetTail;
  undefined4 registerValue;
  uint *scratchPtr7;
  int indexDwords;
  int scratchInt9;
  uint scratchUint10;
  uint scratchUint11;
  uint cacheLineSize;
  undefined4 staleArgR9;
  double staleStackArg_ffffff88;

  cacheLineSize = (uint)*(byte *)(ctx + 8);
  dataCacheBlockTouch(*(undefined4 *)(ctx + 0x1d8));
  trimmedCount = ((uint (*)())gld_prepareDrawCount)(ctx,1,primitiveMode,indexCount,indexCount,indexType,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4
                       ,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffff88);
  if (trimmedCount != 0) {
    scratchInt9 = 5;
    *(undefined4 *)(glStateBlock + -0x68) = *(undefined4 *)(*(int *)(ctx + 0x244) + 0x23c);
    if (cacheLineSize != 0x20) {
      scratchInt9 = 7;
    }
    indexDwords = trimmedCount + 1 >> 1;
    scratchUint10 = indexDwords + 0x1f;
    scratchUint11 = scratchUint10 >> scratchInt9;
    packetAlloc = (uint *)(**(code **)(ctx + 0x2998))(ctx + 0x240,scratchUint10);
    *(uint **)(ctx + 0x298c) = packetAlloc;
    if (1 < scratchUint11) {
      scratchInt9 = scratchUint11 - 1;
      scratchUint10 = cacheLineSize;
      do {
        dataCacheBlockClearToZero((int)packetAlloc + scratchUint10);
        scratchUint10 = scratchUint10 + cacheLineSize;
        scratchInt9 = scratchInt9 + -1;
      } while (scratchInt9 != 0);
    }
    packetBody = (undefined4 *)((uint)(packetAlloc + 0xb) & 0xffffffe0);
    *packetAlloc = (((int)packetBody - (int)packetAlloc) + -8) * 0x4000 | 0xc0001000;
    packetBody[-1] = (int)packetBody - (int)packetAlloc;
    packetTail = packetBody + 0xc;
    lastHeader = *(uint **)(ctx + 0x1d8);
    scratchInt9 = *(int *)(glStateBlock + -0x74) * 0x14;
    *lastHeader = (int)packetBody - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x1d8) = packetBody;
    *packetBody = 0x26000000;
    registerValue = **(undefined4 **)(glStateBlock + -100);
    packetBody[2] = 0x20830;
    packetBody[3] = 0x21;
    packetBody[1] = registerValue;
    registerValue = *(undefined4 *)(scratchInt9 + 0x1d975c);
    packetBody[6] = 0x10854;
    packetBody[5] = 0;
    packetBody[4] = registerValue;
    packetBody[7] = *(undefined4 *)(scratchInt9 + 0x1d9760);
    registerValue = *(undefined4 *)(scratchInt9 + 0x1d9764);
    packetBody[9] = 0x10878;
    packetBody[8] = registerValue;
    packetBody[10] = *(undefined4 *)(scratchInt9 + 0x1d9768);
    packetBody[0xb] = *(undefined4 *)(scratchInt9 + 0x1d976c);
    if (*(char *)(ctx + 0x2a42) != '\0') {
      packetTail = packetBody + 0xe;
      packetBody[0xc] = 0x5c8;
      packetBody[0xd] = 0x10000000;
      *(undefined1 *)(ctx + 0x2a42) = 0;
    }
    indexCursor = packetTail + 4;
    primitiveFlags = *(uint *)(primitiveMode * 4 + 0x1d97e8);
    *packetTail = 0x82c;
    vap_vte_cntl = *(undefined4 *)(0x00001dc4 + ctx);
    packetTail[2] = indexDwords << 0x10 | 0xc0003600;
    packetTail[1] = vap_vte_cntl;
    packetTail[3] = trimmedCount << 0x10 | primitiveFlags & 0xf | 0x10;
    lastIndex = trimmedCount - 1;
    if (indexType == ((unsigned char *)0x00001403)) {
      scratchUint10 = 0;
      scratchPtr7 = indices;
      if (lastIndex != 0) {
        do {
          scratchUint10 = scratchUint10 + 2;
          *indexCursor = (uint)*(ushort *)scratchPtr7 - indexBias & 0xffff |
                    ((uint)(ushort)*scratchPtr7 - indexBias) * 0x10000;
          indexCursor = indexCursor + 1;
          scratchPtr7 = scratchPtr7 + 1;
        } while (scratchUint10 < lastIndex);
      }
      if ((lastIndex & 1) == 0) {
        *indexCursor = (uint)*(ushort *)(scratchUint10 * 2 + (int)indices) - indexBias & 0xffff;
        indexCursor = indexCursor + 1;
      }
    }
    else if (indexType == ((unsigned char *)0x00001405)) {
      blockCount = (int)lastIndex >> 4;
      if (indexBias == 0) {
        if (blockCount != 0) {
          if (blockCount == 0) {
            blockCount = 1;
          }
          do {
            scratchUint10 = indices[1];
            scratchUint11 = *indices;
            indexCursor[1] = indices[2] | indices[3] << 0x10;
            *indexCursor = scratchUint10 << 0x10 | scratchUint11;
            scratchUint10 = indices[5];
            scratchUint11 = indices[4];
            indexCursor[3] = indices[6] | indices[7] << 0x10;
            indexCursor[2] = scratchUint10 << 0x10 | scratchUint11;
            scratchUint10 = indices[9];
            scratchUint11 = indices[8];
            indexCursor[5] = indices[10] | indices[0xb] << 0x10;
            indexCursor[4] = scratchUint10 << 0x10 | scratchUint11;
            scratchPtr7 = indices + 0xd;
            scratchUint10 = indices[0xf];
            scratchPtr1 = indices + 0xc;
            scratchUint11 = indices[0xe];
            indices = indices + 0x10;
            indexCursor[6] = *scratchPtr1 | *scratchPtr7 << 0x10;
            indexCursor[7] = scratchUint11 | scratchUint10 << 0x10;
            indexCursor = indexCursor + 8;
            blockCount = blockCount + -1;
          } while (blockCount != 0);
        }
        if ((lastIndex & 0xf) != 0) {
          scratchUint10 = 0;
          do {
            scratchPtr7 = indices + 1;
            scratchUint10 = scratchUint10 + 2;
            scratchUint11 = *indices;
            indices = indices + 2;
            *indexCursor = scratchUint11 | *scratchPtr7 << 0x10;
            indexCursor = indexCursor + 1;
          } while (scratchUint10 < (lastIndex & 0xf));
        }
        if ((lastIndex & 1) == 0) {
          *indexCursor = (uint)(ushort)*indices;
          indexCursor = indexCursor + 1;
        }
      }
      else {
        if (blockCount != 0) {
          if (blockCount == 0) {
            blockCount = 1;
          }
          do {
            scratchUint10 = indices[1];
            scratchUint11 = *indices;
            indexCursor[1] = indices[2] - indexBias | (indices[3] - indexBias) * 0x10000;
            *indexCursor = scratchUint11 - indexBias | (scratchUint10 - indexBias) * 0x10000;
            scratchUint10 = indices[5];
            scratchUint11 = indices[4];
            indexCursor[3] = (indices[7] - indexBias) * 0x10000 | indices[6] - indexBias & 0xffff;
            indexCursor[2] = (scratchUint10 - indexBias) * 0x10000 | scratchUint11 - indexBias & 0xffff;
            scratchUint10 = indices[9];
            scratchUint11 = indices[8];
            indexCursor[5] = (indices[0xb] - indexBias) * 0x10000 | indices[10] - indexBias & 0xffff;
            indexCursor[4] = (scratchUint10 - indexBias) * 0x10000 | scratchUint11 - indexBias & 0xffff;
            scratchPtr7 = indices + 0xc;
            scratchPtr1 = indices + 0xd;
            scratchUint11 = indices[0xe];
            scratchUint10 = indices[0xf];
            indices = indices + 0x10;
            indexCursor[6] = (*scratchPtr1 - indexBias) * 0x10000 | *scratchPtr7 - indexBias & 0xffff;
            indexCursor[7] = (scratchUint10 - indexBias) * 0x10000 | scratchUint11 - indexBias & 0xffff;
            indexCursor = indexCursor + 8;
            blockCount = blockCount + -1;
          } while (blockCount != 0);
        }
        if ((lastIndex & 0xf) != 0) {
          scratchUint10 = 0;
          do {
            scratchUint11 = *indices;
            scratchPtr7 = indices + 1;
            scratchUint10 = scratchUint10 + 2;
            indices = indices + 2;
            *indexCursor = (*scratchPtr7 - indexBias) * 0x10000 | scratchUint11 - indexBias & 0xffff;
            indexCursor = indexCursor + 1;
          } while (scratchUint10 < (lastIndex & 0xf));
        }
        if ((lastIndex & 1) == 0) {
          *indexCursor = *indices - indexBias & 0xffff;
          indexCursor = indexCursor + 1;
        }
      }
    }
    else if (indexType == ((unsigned char *)0x00001401)) {
      scratchUint10 = 0;
      scratchPtr7 = indices;
      if (lastIndex != 0) {
        do {
          scratchUint10 = scratchUint10 + 2;
          *indexCursor = (uint)*(byte *)scratchPtr7 - indexBias & 0xffff |
                    ((uint)*(byte *)((int)scratchPtr7 + 1) - indexBias) * 0x10000;
          indexCursor = indexCursor + 1;
          scratchPtr7 = (uint *)((int)scratchPtr7 + 2);
        } while (scratchUint10 < lastIndex);
      }
      if ((lastIndex & 1) == 0) {
        *indexCursor = (uint)*(byte *)((int)indices + scratchUint10) - indexBias & 0xffff;
        indexCursor = indexCursor + 1;
      }
    }
    indexCursor[1] = 0;
    *indexCursor = (uint)((unsigned char *)0x00001393U);
    *(uint **)(ctx + 0x298c) = indexCursor + 2;
    (**(code **)(ctx + 0x299c))(ctx + 0x240,indexCursor + 2);
    *(undefined4 *)(ctx + 0x26d4) = 0;
    *(undefined1 *)(ctx + 0x2a5e) = 1;
    *(int *)(ctx + 0x2680) = ctx + 0x26dc;
    *(int *)(ctx + 0x2684) = ctx + 0x26fc;
    ((unsigned char *)0x000027d0)[ctx + 5] = 1;
  }
  return;
}

/* gld_initListHead @ 0x24fb0 (16 bytes) */
int gld_initListHead(listOwner)
  int listOwner;
{
  *(int *)(listOwner + 0x30) = listOwner + 0x2c;
  *(int *)(listOwner + 0x2c) = listOwner + 0x2c;
  return;
}

/* noop_24fc0 @ 0x24fc0 (4 bytes) */
int noop_24fc0()
{
  return;
}

/* noop_24fd0 @ 0x24fd0 (4 bytes) */
int noop_24fd0()
{
  return;
}

/* gld_gatherProgramConstants @ 0x24fe0 (2908 bytes) */
double gld_gatherProgramConstants(int ctx,int maxCount,float *outConstants,double staleFprArg1)
{
  int stateBlockB;
  int stateRowPtr;
  int engineStateB;
  float *vecPtr;
  uint operandFile;
  uint operandWord;
  int operandsLeft;
  int programDataB;
  int engineState;
  bool useDefaultProgram;
  float scratchFloat2;
  float scratchFloat3;
  float vecZPlusOne;
  double i2dMagic;
  float scratchFloat6;
  int paramBase;
  undefined *stateRecord;
  dword *srcZPtr;
  int scratchInt10;
  int scratchInt11;
  int stateBlockA;
  int materialRecord;
  int programData;
  uint programFlags;
  float *constantSrc;
  dword *srcWPtr;
  int lightRecord;
  int programHeader;
  uint scratchUint20;
  dword *srcYPtr;
  uint operandByte;
  int scratchInt23;
  int literalPool;
  int operandIndex;
  int *programObject;
  uint *operandPtr;
  float vecX;
  float vecY;
  float vecZ;
  float vecW [3];
  undefined4 negXI2dHi;
  float negXI2dLo;
  undefined4 negYI2dHi;
  float negYI2dLo;
  undefined4 negZI2dHi;
  float negZI2dLo;
  undefined4 negWI2dHi;
  float negWI2dLo;
  
  programObject = *(int **)(*(int *)(ctx + GLD_engineObjects) + 0x19c);
  useDefaultProgram = programObject == (int *)0x0;
  if (useDefaultProgram) {
    programObject = *(int **)(*(int *)(ctx + GLD_engineObjects) + 400);
  }
  programData = programObject[0xd];
  if (((programData == 0) && (programData = programObject[0xc], programData == 0)) &&
     (programData = programObject[0xb], programData == 0)) {
    programHeader = *programObject;
    programData = *(int *)(programHeader + 4);
  }
  else {
    programHeader = *programObject;
  }
  paramBase = *(int *)(programData + 0x6c);
  literalPool = *(int *)(programHeader + 0x18);
  operandPtr = (uint *)(programData + *(int *)(programData + 0x2c) * 8);
  operandsLeft = *(int *)(programData + 0x28);
  if (maxCount < *(int *)(programData + 0x28)) {
    operandsLeft = maxCount;
  }
  if (operandsLeft < 1) {
loopSetScratchFloat3:
    scratchFloat3 = FLOAT_001aa13c;
    scratchFloat2 = FLOAT_001aa138;
    scratchFloat6 = FLOAT_001aa134;
    programDataB = programObject[0xe];
    if (programDataB != 0) {
      programFlags = *(uint *)(programDataB + 0x20);
      if ((programFlags & 0x4000000) != 0) {
        *outConstants = FLOAT_001aa130;
        outConstants[1] = scratchFloat6;
        outConstants[2] = scratchFloat2;
        outConstants[3] = scratchFloat3;
        outConstants = outConstants + 4;
        programFlags = *(uint *)(programDataB + 0x20);
      }
      if ((programFlags & 0x2000000) != 0) {
        *outConstants = *(float *)(((unsigned char *)0x00002de0) + *(int *)(ctx + GLD_engineState));
        outConstants[1] = *(float *)(((unsigned char *)0x00002de4) + *(int *)(ctx + GLD_engineState));
        outConstants[2] = *(float *)(((unsigned char *)0x00002de8) + *(int *)(ctx + GLD_engineState));
        outConstants[4] = -*(float *)(((unsigned char *)0x00002dfc) + *(int *)(ctx + GLD_engineState));
        scratchFloat6 = FLOAT_001aa140;
        outConstants[5] = *(float *)(((unsigned char *)0x00002df8) + *(int *)(ctx + GLD_engineState)) *
                     *(float *)(((unsigned char *)0x00002dfc) + *(int *)(ctx + GLD_engineState));
        scratchFloat2 = FLOAT_001aa144;
        outConstants[6] = *(float *)(((unsigned char *)0x00002df0) + *(int *)(ctx + GLD_engineState)) * scratchFloat6;
        outConstants[7] = *(float *)(((unsigned char *)0x00002df0) + *(int *)(ctx + GLD_engineState)) * scratchFloat2;
      }
    }
    return staleFprArg1;
  }
  operandIndex = 0;
loopSetI2dMagic:
  i2dMagic = DOUBLE_001aa1e0;
  scratchFloat6 = FLOAT_001aa0e8;
  operandWord = *operandPtr;
  operandFile = operandWord & 0x1f0000;
  if (operandFile == 0) goto setOperandIndex;
  if (operandFile == 0x110000) {
    constantSrc = (float *)(programData + paramBase * 8 + (uint)(ushort)*operandPtr * 0x10);
loopCheckUseDefaultProgram:
    if ((useDefaultProgram) || ((operandWord & 0x1c000000) == 0x4000000)) {
      *outConstants = *constantSrc;
      outConstants[1] = constantSrc[1];
      outConstants[2] = constantSrc[2];
      outConstants[3] = constantSrc[3];
    }
    else if ((operandWord & 0x1c000000) == 0xc000000) {
      negXI2dHi = 0x43300000;
      negXI2dLo = -*constantSrc;
      *outConstants = (float)((double)CONCAT44(0x43300000,-*constantSrc) - DOUBLE_001aa1e0);
      negYI2dHi = 0x43300000;
      negYI2dLo = -constantSrc[1];
      outConstants[1] = (float)((double)CONCAT44(0x43300000,-constantSrc[1]) - i2dMagic);
      negZI2dHi = 0x43300000;
      negZI2dLo = -constantSrc[2];
      outConstants[2] = (float)((double)CONCAT44(0x43300000,-constantSrc[2]) - i2dMagic);
      negWI2dHi = 0x43300000;
      negWI2dLo = -constantSrc[3];
      outConstants[3] = (float)((double)CONCAT44(0x43300000,-constantSrc[3]) - i2dMagic);
    }
    else {
      if (*constantSrc == 0.0) {
        scratchFloat6 = 0.0;
      }
      else {
        scratchFloat6 = 1.0;
      }
      *outConstants = scratchFloat6;
      if (constantSrc[1] == 0.0) {
        scratchFloat6 = 0.0;
      }
      else {
        scratchFloat6 = 1.0;
      }
      outConstants[1] = scratchFloat6;
      if (constantSrc[2] == 0.0) {
        scratchFloat6 = 0.0;
      }
      else {
        scratchFloat6 = 1.0;
      }
      outConstants[2] = scratchFloat6;
      if (constantSrc[3] == 0.0) {
        scratchFloat6 = 0.0;
      }
      else {
        scratchFloat6 = 1.0;
      }
      outConstants[3] = scratchFloat6;
    }
    goto setOperandIndex;
  }
  if (operandFile == 0x10000) {
    constantSrc = (float *)(literalPool + (uint)(ushort)*operandPtr * 0x10);
    goto loopCheckUseDefaultProgram;
  }
  if (operandFile == 0x20000) {
    scratchInt23 = (uint)(ushort)*operandPtr * 0x10;
    scratchInt10 = scratchInt23 + *(int *)(((unsigned char *)0x00004310) + *(int *)(ctx + GLD_engineState));
    *outConstants = *(float *)(scratchInt23 + *(int *)(((unsigned char *)0x00004310) + *(int *)(ctx + GLD_engineState)));
    outConstants[1] = *(float *)(scratchInt10 + 4);
    outConstants[2] = *(float *)(scratchInt10 + 8);
    outConstants[3] = *(float *)(scratchInt10 + 0xc);
    goto setOperandIndex;
  }
  if (operandFile == 0x100000) {
    scratchUint20 = operandWord >> 0xc & 3;
    operandByte = operandWord & 0xff;
    switch(operandWord >> 8 & 7) {
    default:
      scratchInt23 = 0;
      break;
    case 1:
      scratchInt23 = 0xc0;
      break;
    case 2:
      scratchInt23 = 0x80;
      break;
    case 3:
      scratchInt23 = (operandByte + 4) * 0x40;
      break;
    case 4:
      scratchInt23 = (operandByte + 0x10) * 0x40;
      break;
    case 5:
      scratchInt23 = (operandByte + 8) * 0x40;
    }
    operandWord = operandWord >> 0xe & 3;
    scratchInt10 = *(int *)(ctx + GLD_engineState) + 0x1860 + scratchInt23;
    if ((1 < operandWord) && (scratchInt10 = scratchInt23 + *(int *)(ctx + GLD_engineState) + 0x1e60, 3 < operandWord)) {
      scratchInt10 = 0;
    }
    if (operandWord < 3) {
      if (operandWord == 0) {
loopSetScratchInt23:
        scratchInt23 = scratchUint20 * 4;
        scratchInt11 = scratchInt10 + scratchInt23;
        vecX = *(float *)(scratchInt10 + scratchInt23);
        vecY = *(float *)(scratchInt11 + 0x10);
        vecZ = *(float *)(scratchInt11 + 0x20);
        vecW[0] = *(float *)(scratchInt11 + 0x30);
      }
      else {
        scratchInt23 = scratchUint20 * 0x10;
        scratchInt11 = scratchInt10 + scratchInt23;
        vecX = *(float *)(scratchInt10 + scratchInt23);
        vecY = *(float *)(scratchInt11 + 4);
        vecZ = *(float *)(scratchInt11 + 8);
        vecW[0] = *(float *)(scratchInt11 + 0xc);
      }
    }
    else if (operandWord == 3) goto loopSetScratchInt23;
    goto storeOutConstants;
  }
  switch(operandWord >> 0x10 & 0x1f) {
  case 0:
    srcYPtr = (dword *)&vecY;
    srcZPtr = (dword *)&vecZ;
    srcWPtr = (dword *)vecW;
    vecPtr = &vecX;
    break;
  default:
    goto switchD_00025774_caseD_1;
  case 2:
    vecPtr = (float *)((operandWord & 0xffff) * 0x10 +
                       *(int *)(((unsigned char *)0x00004308) + *(int *)(ctx + GLD_engineState)));
    srcYPtr = (dword *)(vecPtr + 1);
    srcZPtr = (dword *)(vecPtr + 2);
    srcWPtr = (dword *)(vecPtr + 3);
    break;
  case 3:
    scratchUint20 = operandWord & 0xff;
    switch(operandWord >> 8 & 0xf) {
    case 0:
      vecPtr = (float *)(scratchUint20 * 0x80 + 0x24c0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 1:
      vecPtr = (float *)(scratchUint20 * 0x80 + 0x24d0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 2:
      vecPtr = (float *)(scratchUint20 * 0x80 + 0x24e0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 3:
      vecPtr = (float *)(scratchUint20 * 0x80 + 0x24f0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 4:
      vecPtr = (float *)(scratchUint20 * 0x80 + 0x2500 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 5:
      vecPtr = (float *)(scratchUint20 * 0x80 + 0x2510 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 6:
      scratchInt23 = scratchUint20 * 0x80 + *(int *)(ctx + GLD_engineState);
      scratchFloat2 = *(float *)(scratchInt23 + 0x24f4);
      scratchFloat3 = *(float *)(scratchInt23 + 0x24f0);
      vecZPlusOne = *(float *)(scratchInt23 + 0x24f8) + FLOAT_001aa0e8;
      staleFprArg1 = _sqrt((double)(vecZPlusOne * vecZPlusOne + scratchFloat3 * scratchFloat3 + scratchFloat2 * scratchFloat2));
      vecW[0] = scratchFloat6;
      scratchFloat6 = (float)(DOUBLE_001aa200 / staleFprArg1);
      vecZ = vecZPlusOne * scratchFloat6;
      vecX = scratchFloat3 * scratchFloat6;
      vecY = scratchFloat2 * scratchFloat6;
      goto storeOutConstants;
    case 7:
      vecPtr = (float *)(scratchUint20 * 0x80 + 0x2530 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    default:
      goto switchD_00025774_caseD_1;
    }
    break;
  case 4:
    scratchUint20 = operandWord >> 9 & 3;
    stateBlockA = *(int *)(ctx + GLD_engineState) + 0x24c0;
    scratchInt23 = (operandWord & 0xff) * 0x80;
    scratchInt10 = (operandWord >> 8 & 1) * 0x240;
    stateBlockB = *(int *)(ctx + GLD_engineState) + 0x28c0;
    lightRecord = stateBlockA + scratchInt23;
    materialRecord = stateBlockB + scratchInt10;
    if (scratchUint20 == 1) {
      vecX = *(float *)(lightRecord + 0x10) * *(float *)(materialRecord + 0x10);
      vecY = *(float *)(lightRecord + 0x14) * *(float *)(materialRecord + 0x14);
      vecZ = *(float *)(lightRecord + 0x18) * *(float *)(materialRecord + 0x18);
      vecW[0] = *(float *)(materialRecord + 0x1c);
    }
    else if (scratchUint20 == 2) {
      vecX = *(float *)(lightRecord + 0x20) * *(float *)(materialRecord + 0x20);
      vecY = *(float *)(lightRecord + 0x24) * *(float *)(materialRecord + 0x24);
      vecZ = *(float *)(lightRecord + 0x28) * *(float *)(materialRecord + 0x28);
      vecW[0] = *(float *)(materialRecord + 0x2c);
    }
    else {
      if (scratchUint20 != 0) goto switchD_00025774_caseD_1;
      vecX = *(float *)(stateBlockA + scratchInt23) * *(float *)(stateBlockB + scratchInt10);
      vecY = *(float *)(lightRecord + 4) * *(float *)(materialRecord + 4);
      vecZ = *(float *)(lightRecord + 8) * *(float *)(materialRecord + 8);
      vecW[0] = *(float *)(materialRecord + 0xc);
    }
    goto storeOutConstants;
  case 5:
    scratchUint20 = operandWord & 1;
    switch(operandWord >> 1 & 7) {
    case 0:
      vecPtr = (float *)(scratchUint20 * 0x240 + 0x28c0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 1:
      vecPtr = (float *)(scratchUint20 * 0x240 + 0x28d0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 2:
      vecPtr = (float *)(scratchUint20 * 0x240 + 0x28e0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 3:
      vecPtr = (float *)(scratchUint20 * 0x240 + 0x28f0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 4:
      vecPtr = (float *)(scratchUint20 * 0x240 + 0x2900 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 5:
      engineStateB = *(int *)(ctx + GLD_engineState);
      scratchInt10 = engineStateB + 0x28c0 + scratchUint20 * 0x240;
      vecX = *(float *)(engineStateB + 0x24b0) * *(float *)(engineStateB + 0x28c0 + scratchUint20 * 0x240) +
                 *(float *)(scratchInt10 + 0x30);
      vecY = *(float *)(engineStateB + 0x24b4) * *(float *)(scratchInt10 + 4) + *(float *)(scratchInt10 + 0x34);
      vecZ = *(float *)(engineStateB + 0x24b8) * *(float *)(scratchInt10 + 8) + *(float *)(scratchInt10 + 0x38);
      vecW[0] = *(float *)(scratchInt10 + 0x1c);
      goto storeOutConstants;
    default:
      goto switchD_00025774_caseD_1;
    }
    break;
  case 6:
    engineState = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(engineState + 0x24bc);
    vecPtr = (float *)(engineState + 0x24b0);
    srcYPtr = (dword *)(engineState + 0x24b4);
    srcZPtr = (dword *)(engineState + 0x24b8);
    break;
  case 7:
    scratchUint20 = operandWord >> 5 & 7;
    operandWord = operandWord & 0x1f;
    if (scratchUint20 == 1) {
      engineState = *(int *)(ctx + GLD_engineState);
      stateRecord = ((unsigned char *)0x000039a0) + operandWord * 0x94;
loopSetSrcWPtr:
      srcWPtr = (dword *)(stateRecord + engineState + 0x1c);
      vecPtr = (float *)(stateRecord + engineState + 0x10);
      srcYPtr = (dword *)(stateRecord + engineState + 0x14);
      srcZPtr = (dword *)(stateRecord + engineState + 0x18);
    }
    else {
      if (scratchUint20 < 2) {
        if (scratchUint20 == 0) {
          engineState = *(int *)(ctx + GLD_engineState);
          stateRecord = ((unsigned char *)0x00003980) + operandWord * 0x94;
          goto setSrcWPtr;
        }
        goto switchD_00025774_caseD_1;
      }
      if (scratchUint20 == 2) {
        engineState = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039c0) + operandWord * 0x94;
loopSetSrcWPtr2:
        srcWPtr = (dword *)(stateRecord + engineState + 0x20);
        vecPtr = (float *)(stateRecord + engineState + 0x14);
        srcYPtr = (dword *)(stateRecord + engineState + 0x18);
        srcZPtr = (dword *)(stateRecord + engineState + 0x1c);
      }
      else {
        if (scratchUint20 != 3) goto switchD_00025774_caseD_1;
        engineState = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039e0) + operandWord * 0x94;
loopSetSrcWPtr3:
        srcWPtr = (dword *)(stateRecord + engineState + 0x24);
        vecPtr = (float *)(stateRecord + engineState + 0x18);
        srcYPtr = (dword *)(stateRecord + engineState + 0x1c);
        srcZPtr = (dword *)(stateRecord + engineState + 0x20);
      }
    }
    break;
  case 8:
    scratchUint20 = operandWord >> 5 & 7;
    operandWord = operandWord & 0x1f;
    if (scratchUint20 == 1) {
      engineState = *(int *)(ctx + GLD_engineState);
      stateRecord = ((unsigned char *)0x000039b0) + operandWord * 0x94;
      goto loopSetSrcWPtr;
    }
    if (scratchUint20 < 2) {
      if (scratchUint20 == 0) {
        engineState = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x00003990) + operandWord * 0x94;
        goto setSrcWPtr;
      }
    }
    else {
      if (scratchUint20 == 2) {
        engineState = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039d0) + operandWord * 0x94;
        goto loopSetSrcWPtr2;
      }
      if (scratchUint20 == 3) {
        engineState = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039f0) + operandWord * 0x94;
        goto loopSetSrcWPtr3;
      }
    }
    goto switchD_00025774_caseD_1;
  case 9:
    stateRowPtr = *(int *)(ctx + GLD_engineState) + (operandWord & 0x1f) * 0x7c;
    vecPtr = (float *)(((unsigned char *)0x000031c0) + stateRowPtr + 4);
    srcWPtr = (dword *)(((unsigned char *)0x000031c0) + stateRowPtr + 0x10);
    srcZPtr = (dword *)(((unsigned char *)0x000031c0) + stateRowPtr + 0xc);
    srcYPtr = (dword *)(((unsigned char *)0x000031c0) + stateRowPtr + 8);
    break;
  case 10:
    engineState = *(int *)(ctx + GLD_engineState);
    stateRecord = ((unsigned char *)0x00003e20) + (operandWord & 0xff) * 0x10;
setSrcWPtr:
    srcWPtr = (dword *)(stateRecord + engineState + 0x18);
    vecPtr = (float *)(stateRecord + engineState + 0xc);
    srcYPtr = (dword *)(stateRecord + engineState + 0x10);
    srcZPtr = (dword *)(stateRecord + engineState + 0x14);
    break;
  case 0xb:
    engineState = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x00002dec) + engineState);
    vecPtr = (float *)(((unsigned char *)0x00002de0) + engineState);
    srcYPtr = (dword *)(((unsigned char *)0x00002de4) + engineState);
    srcZPtr = (dword *)(((unsigned char *)0x00002de8) + engineState);
    break;
  case 0xc:
    engineState = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x00002dfc) + engineState);
    vecPtr = (float *)(((unsigned char *)0x00002df0) + engineState);
    srcYPtr = (dword *)(((unsigned char *)0x00002df4) + engineState);
    srcZPtr = (dword *)(((unsigned char *)0x00002df8) + engineState);
    break;
  case 0xd:
    engineState = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x000030c8) + engineState);
    vecPtr = (float *)(((unsigned char *)0x000030bc) + engineState);
    srcYPtr = (dword *)(((unsigned char *)0x000030c0) + engineState);
    srcZPtr = (dword *)(((unsigned char *)0x000030c4) + engineState);
    break;
  case 0xe:
    engineState = *(int *)(ctx + GLD_engineState);
    srcWPtr = (dword *)(((unsigned char *)0x000030d8) + engineState);
    vecPtr = (float *)(((unsigned char *)0x000030cc) + engineState);
    srcYPtr = (dword *)(((unsigned char *)0x000030d0) + engineState);
    srcZPtr = (dword *)(((unsigned char *)0x000030d4) + engineState);
    break;
  case 0xf:
    engineStateB = *(int *)(ctx + GLD_engineState);
    vecX = (float)*(double *)(0x00001830 + engineStateB);
    vecY = (float)*(double *)(engineStateB + 0x1838);
    vecW[0] = 1.0;
    vecZ = (float)(*(double *)(engineStateB + 0x1838) - *(double *)(0x00001830 + engineStateB));
    goto storeOutConstants;
  case 0x12:
    vecW[0] = *(float *)(*(int *)(ctx + GLD_engineState) + 0x24a4);
    vecX = vecW[0];
    vecY = vecW[0];
    vecZ = vecW[0];
    goto storeOutConstants;
  }
loopSetVecX:
  vecX = *vecPtr;
  vecY = (float)*srcYPtr;
  vecZ = (float)*srcZPtr;
  vecW[0] = (float)*srcWPtr;
storeOutConstants:
  outConstants[1] = vecY;
  outConstants[2] = vecZ;
  *outConstants = vecX;
  outConstants[3] = vecW[0];
setOperandIndex:
  operandIndex = operandIndex + 1;
  operandPtr = operandPtr + 2;
  outConstants = outConstants + 4;
  if (operandsLeft == operandIndex) goto loopSetScratchFloat3;
  goto loopSetI2dMagic;
switchD_00025774_caseD_1:
  vecPtr = (float *)0x0;
  srcYPtr = ((unsigned char *)0x4);
  srcZPtr = ((unsigned char *)0x8);
  srcWPtr = ((unsigned char *)0xc);
  goto loopSetVecX;
}

/* gld_releaseProgramObject @ 0x25bf0 (408 bytes) */
int gld_releaseProgramObject(ctx, program)
  int ctx;
  int program;
{
  int kind;
  int *listNode;
  int *nextNode;
  int *savedNext;
  
  if (*(int *)(program + 0x1c) != 0) {
    _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
    if (*(int *)(program + 0x2c) != 0) {
      _glpFreePPShaderLinearize(*(int *)(program + 0x2c));
      *(undefined4 *)(program + 0x2c) = 0;
    }
    if (*(int *)(program + 0x30) != 0) {
      _glpFreePPShaderToProgram(*(int *)(program + 0x30));
      *(undefined4 *)(program + 0x30) = 0;
    }
    if (*(int *)(program + 0x34) != 0) {
      *(undefined4 *)(program + 0x34) = 0;
    }
    freeIfNonNull(*(undefined4 *)(program + 0x38));
    *(undefined4 *)(program + 0x38) = 0;
    listNode = *(int **)(program + 0x24);
    while (listNode != (int *)(program + 0x20)) {
      kind = *(int *)(program + 0x1c);
      savedNext = (int *)listNode[1];
      if (kind == 2) {
        glDeleteProgramsARB_impl(listNode[2] + 0x240,1,listNode + 5);
        nextNode = (int *)listNode[1];
      }
      else if (kind == 3) {
        gldDeleteFragmentShaderObject(listNode[2] + 0x240,listNode + 5);
        nextNode = (int *)listNode[1];
      }
      else {
        nextNode = savedNext;
        if (kind == 1) {
          gldDeleteVertexShaderObject(listNode[2] + 0x240,listNode + 5);
          nextNode = (int *)listNode[1];
        }
      }
      kind = *listNode;
      listNode[2] = 0;
      *(int **)(kind + 4) = nextNode;
      *(int *)listNode[1] = kind;
      _free(listNode);
      listNode = savedNext;
    }
    kind = *(int *)(program + 0xc);
    if (kind != 0) {
      *(undefined4 *)(kind + 4) = *(undefined4 *)(program + 0x10);
      listNode = *(int **)(program + 0x10);
      *(undefined4 *)(program + 0x10) = 0;
      *listNode = kind;
      *(undefined4 *)(program + 0xc) = 0;
    }
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    return;
  }
  return;
}

/* gld_deleteContextProgramObjects @ 0x25da0 (264 bytes) */
int gld_deleteContextProgramObjects(ctx)
  int ctx;
{
  int recordPrev;
  int objectKind;
  int sharedState;
  int recordOwner;
  int objectEntry;
  int *contextRecord;
  
  _pthread_mutex_lock(*(undefined4 *)(ctx + 0xc));
  sharedState = *(int *)(ctx + 0xc);
  objectEntry = *(int *)(sharedState + 0x30);
  if (sharedState + 0x2c != objectEntry) {
    do {
      for (contextRecord = *(int **)(objectEntry + 0x18); contextRecord != (int *)(objectEntry + 0x14);
          contextRecord = (int *)contextRecord[1]) {
        recordOwner = contextRecord[2];
        if (ctx == recordOwner) {
          objectKind = *(int *)(objectEntry + 0x10);
          if (objectKind == 2) {
            glDeleteProgramsARB_impl(recordOwner + 0x240,1,contextRecord + 5);
          }
          else if (objectKind == 3) {
            gldDeleteFragmentShaderObject(recordOwner + 0x240,contextRecord + 5);
          }
          else if (objectKind == 1) {
            gldDeleteVertexShaderObject(recordOwner + 0x240,contextRecord + 5);
          }
          recordPrev = *contextRecord;
          contextRecord[2] = 0;
          *(int *)(recordPrev + 4) = contextRecord[1];
          *(int *)contextRecord[1] = recordPrev;
          _free(contextRecord);
          break;
        }
      }
      objectEntry = *(int *)(objectEntry + 4);
    } while (sharedState + 0x2c != objectEntry);
    sharedState = *(int *)(ctx + 0xc);
  }
  _pthread_mutex_unlock(sharedState);
  return;
}

/* gld_bindFragmentProgramRecord @ 0x25ec0 (1372 bytes) */
int gld_bindFragmentProgramRecord(ctx, programObject)
  int ctx;
  int *programObject;
{
  undefined4 length;
  byte *useIndexPtr;
  byte *useValuePtr;
  bool scratchFlag3;
  bool translateOk;
  uint scratchUint5;
  int *contextRecord;
  int *translator;
  undefined4 bindResult;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  int literalPool;
  int rowsMinusOne;
  int scratchInt9;
  int scratchInt10;
  uint programFlags;
  int scratchInt12;
  byte *constantUseCursor;
  int *recordProgramId;
  int *commandStream;
  
  commandStream = (int *)(ctx + 0x240);
  for (contextRecord = (int *)programObject[9]; contextRecord != programObject + 8; contextRecord = (int *)contextRecord[1]) {
    if (ctx == contextRecord[2]) goto setScratchInt9;
  }
  contextRecord = (int *)_calloc(1,*(int *)(&DAT_001aa4c4 + programObject[7] * 4) + 0x14);
  contextRecord[3] = programObject[5] + -1;
  scratchInt9 = programObject[6];
  contextRecord[2] = ctx;
  contextRecord[1] = (int)(programObject + 8);
  rowsMinusOne = scratchInt9 + -1;
  contextRecord[4] = rowsMinusOne;
  *contextRecord = programObject[8];
  programObject[8] = (int)contextRecord;
  *(int **)(*contextRecord + 4) = contextRecord;
setScratchInt9:
  scratchInt9 = contextRecord[5];
  recordProgramId = contextRecord + 5;
  if (scratchInt9 == 0) {
    glGenProgramsARB_impl(commandStream,1,recordProgramId);
    scratchInt9 = contextRecord[5];
    if (scratchInt9 != 0) goto callGlBindProgramARBImpl;
loopSetBindResult:
    bindResult = 0;
  }
  else {
callGlBindProgramARBImpl:
    glBindProgramARB_impl(commandStream,0x8804,scratchInt9,staleArgR6,staleArgR7,literalPool,rowsMinusOne);
    if (contextRecord[3] == programObject[5]) {
      constantUseCursor = (byte *)programObject[0xe];
      if (constantUseCursor != (byte *)0x0) {
        programFlags = *(uint *)(constantUseCursor + 0x20);
        scratchUint5 = programFlags >> 0x1b;
        literalPool = *(int *)(*programObject + 0x18);
        if (scratchUint5 == 0) {
loopSetScratchFlag3:
          scratchFlag3 = false;
        }
        else {
          if ((uint)constantUseCursor[1] == *(uint *)(literalPool + (uint)*constantUseCursor * 0x10)) {
            do {
              scratchUint5 = scratchUint5 - 1;
              if (scratchUint5 == 0) goto loopSetScratchFlag3;
              useIndexPtr = constantUseCursor + 2;
              useValuePtr = constantUseCursor + 3;
              constantUseCursor = constantUseCursor + 2;
            } while ((uint)*useValuePtr == *(uint *)(literalPool + (uint)*useIndexPtr * 0x10));
          }
          scratchFlag3 = true;
        }
        if (((((programFlags & 0x1000000) != 0) &&
             ((programFlags >> 0x17 & 1) != (uint)(byte)((unsigned char *)0x00002b7c)[ctx])) ||
            (((programFlags & 0x400000) == 0 &&
             ((programFlags >> 0x12 & 0xf) != (*(uint *)(ctx + 0x1ae4) >> 6 & 0xffff))))) || (scratchFlag3))
        {
          scratchUint5 = programObject[0xf];
          programObject[0xf] = scratchUint5 | 1;
          programObject[5] = programObject[5] + 1;
          if ((scratchUint5 & 2) != 0) {
            programObject[6] = programObject[6] + 1;
          }
          programObject[0xf] = 0;
          scratchFlag3 = contextRecord[3] != programObject[5];
          if (scratchFlag3) {
            contextRecord[3] = programObject[5];
          }
          goto checkScratchFlag3;
        }
      }
loopCheckProgramObject:
      if (*(char *)(programObject + 10) != '\0') goto loopSetBindResult;
    }
    else {
      contextRecord[3] = programObject[5];
      scratchFlag3 = true;
checkScratchFlag3:
      if (!scratchFlag3) goto loopCheckProgramObject;
      *(undefined1 *)(programObject + 10) = 0;
      if (programObject[0xb] != 0) {
        _glpFreePPShaderLinearize(programObject[0xb]);
        programObject[0xb] = 0;
      }
      if (programObject[0xc] != 0) {
        _glpFreePPShaderToProgram(programObject[0xc]);
        programObject[0xc] = 0;
      }
      if (programObject[0xd] != 0) {
        programObject[0xd] = 0;
      }
      scratchFlag3 = false;
      scratchUint5 = 0x1f9;
      freeIfNonNull(programObject[0xe]);
      programObject[0xe] = 0;
      while( true ) {
        if (*(short *)*programObject == -0x74d0) {
          scratchInt9 = _glpPPShaderLinearize(*(undefined4 *)((short *)*programObject + 2),scratchUint5);
          programObject[0xb] = scratchInt9;
        }
        translator = (int *)fpilCreateTranslator();
        scratchInt9 = programObject[0xd];
        if (((scratchInt9 == 0) && (scratchInt9 = programObject[0xc], scratchInt9 == 0)) &&
           (scratchInt9 = programObject[0xb], scratchInt9 == 0)) {
          scratchInt9 = *(int *)(*programObject + 4);
        }
        *translator = scratchInt9;
        scratchInt12 = *(int *)(*programObject + 0xc);
        translator[1] = *(int *)(*programObject + 8);
        translator[2] = scratchInt12;
        translator[3] = *(int *)(*programObject + 0x18);
        *(uint *)(translator[0xd] + 0x20) =
             ((byte)((unsigned char *)0x00002b7c)[ctx] & 1) << 0x17 |
             *(uint *)(translator[0xd] + 0x20) & 0xff7fffff;
        scratchInt10 = translator[0xd];
        *(uint *)(scratchInt10 + 0x20) =
             (*(uint *)(ctx + 0x1ae4) & 0x3c0) << 0xc | *(uint *)(scratchInt10 + 0x20) & 0xffc3ffff;
        scratchInt9 = fragmentProgramToIL(translator);
        if (scratchInt9 == 0) {
          *commandStream = 0;
          arbfpProgramStringIL(commandStream,0,translator[0xb],translator[10]);
          scratchFlag3 = *commandStream == 0;
          translateOk = !scratchFlag3;
          if (!translateOk) {
            scratchInt9 = translator[0xd];
            translator[0xd] = *commandStream;
            programObject[0xe] = scratchInt9;
            goto callFpilDestroyTranslator;
          }
        }
        else {
          translateOk = !scratchFlag3;
          if (!translateOk) goto callFpilDestroyTranslator;
        }
        if ((*(short *)*programObject != -0x74d0) || ((scratchUint5 & 6) == 6)) break;
        if ((scratchUint5 & 4) == 0) {
          scratchUint5 = scratchUint5 | 4;
        }
        else if ((scratchUint5 & 2) == 0) {
          scratchUint5 = scratchUint5 & 0xfffffffb | 2;
        }
        if (programObject[0xb] != 0) {
          _glpFreePPShaderLinearize(programObject[0xb]);
          programObject[0xb] = 0;
        }
        if (programObject[0xc] != 0) {
          _glpFreePPShaderToProgram(programObject[0xc]);
          programObject[0xc] = 0;
        }
        if (programObject[0xd] != 0) {
          programObject[0xd] = 0;
        }
        freeIfNonNull(programObject[0xe]);
        programObject[0xe] = 0;
        fpilDestroyTranslator(translator);
      }
      if (translateOk) {
        if (*(short *)*programObject == -0x74d0) {
          translateOk = true;
        }
        else {
          *commandStream = 0;
          scratchInt9 = programObject[0xd];
          if (((scratchInt9 == 0) && (scratchInt9 = programObject[0xc], scratchInt9 == 0)) &&
             (scratchInt9 = programObject[0xb], scratchInt9 == 0)) {
            scratchInt9 = *(int *)(*programObject + 4);
          }
          scratchInt9 = arbProgramIrToText(scratchInt9);
          if (scratchInt9 == 0) {
            glDeleteProgramsARB_impl(commandStream,1,recordProgramId);
            *recordProgramId = 0;
            return 0;
          }
          length = _strlen(scratchInt9);
          glProgramStringARB_impl(commandStream,0x8804,0x8875,length,scratchInt9,literalPool,scratchInt10,scratchInt12);
          _free(scratchInt9);
          translateOk = *commandStream != 0;
        }
      }
      else {
        translateOk = false;
      }
callFpilDestroyTranslator:
      fpilDestroyTranslator(translator);
      if (translateOk) {
        *(undefined1 *)(programObject + 10) = 1;
        return 0;
      }
    }
    bindResult = 1;
    *(int **)(ctx + 0x29ec) = contextRecord;
  }
  return bindResult;
}

/* gld_bindProgramRecord @ 0x26440 (500 bytes) */
int gld_bindProgramRecord(ctx, programObject)
  int ctx;
  int *programObject;
{
  int *contextRecord;
  int scratchInt2;
  int commandStream;
  
  for (contextRecord = (int *)programObject[9]; contextRecord != programObject + 8; contextRecord = (int *)contextRecord[1]) {
    if (ctx == contextRecord[2]) goto setCommandStream;
  }
  contextRecord = (int *)_calloc(1,*(int *)(&DAT_001aa4c4 + programObject[7] * 4) + 0x14);
  contextRecord[3] = programObject[5] + -1;
  scratchInt2 = programObject[6];
  contextRecord[2] = ctx;
  contextRecord[1] = (int)(programObject + 8);
  contextRecord[4] = scratchInt2 + -1;
  *contextRecord = programObject[8];
  programObject[8] = (int)contextRecord;
  *(int **)(*contextRecord + 4) = contextRecord;
setCommandStream:
  commandStream = ctx + 0x240;
  scratchInt2 = gld_bindVertexShaderSlot(commandStream,contextRecord + 5);
  if (scratchInt2 != 0) {
    if (contextRecord[3] == programObject[5]) {
      scratchInt2 = extvsConstantsDirty(commandStream);
    }
    else {
      contextRecord[3] = programObject[5];
      if (programObject[0xb] != 0) {
        _glpFreePPShaderLinearize(programObject[0xb]);
        programObject[0xb] = 0;
      }
      if (programObject[0xc] != 0) {
        _glpFreePPShaderToProgram(programObject[0xc]);
        programObject[0xc] = 0;
      }
      if (programObject[0xd] != 0) {
        programObject[0xd] = 0;
      }
      freeIfNonNull(programObject[0xe]);
      programObject[0xe] = 0;
      if (*(short *)*programObject == -0x74cf) {
        scratchInt2 = _glpPPShaderLinearize(*(undefined4 *)((short *)*programObject + 2),0xff);
        programObject[0xb] = scratchInt2;
        if (scratchInt2 != 0) {
          scratchInt2 = _glpPPShaderToProgram(scratchInt2,*(undefined4 *)(*programObject + 0x18),0);
          programObject[0xc] = scratchInt2;
        }
      }
      scratchInt2 = programObject[0xd];
      if (((scratchInt2 == 0) && (scratchInt2 = programObject[0xc], scratchInt2 == 0)) && (scratchInt2 = programObject[0xb], scratchInt2 == 0)
         ) {
        scratchInt2 = *(int *)(*programObject + 4);
      }
      scratchInt2 = extvsTranslateShaderObject(commandStream,scratchInt2,contextRecord + 5);
    }
    if (scratchInt2 != 0) {
      *(int **)(ctx + 0x29e8) = contextRecord;
      return 1;
    }
  }
  return 0;
}

/* gld_bindProgramObject @ 0x26650 (792 bytes) */
int gld_bindProgramObject(ctx, programObject)
  int ctx;
  int *programObject;
{
  uint bindResult;
  short programKind;
  uint pendingGenerationBits;
  short *programHeader;
  int scratchInt4;
  int *contextRecord;
  int sharedState;
  int *recordListHead;
  
  if (programObject[7] != 0) goto setPendingGenerationBits;
  programHeader = (short *)*programObject;
  if (programHeader[1] == 0) {
    if ((*programHeader == -0x79e0) || (*programHeader == -0x74cf)) {
      scratchInt4 = 1;
      goto storeProgramObject;
    }
loopSetScratchInt4:
    scratchInt4 = 0;
  }
  else {
    if (programHeader[1] != 1) goto loopSetScratchInt4;
    programKind = *programHeader;
    if ((programKind == -0x77fc) || (programKind == -0x74d0)) {
      scratchInt4 = 2;
    }
    else {
      scratchInt4 = 3;
      if (programKind != -0x7e00) goto loopSetScratchInt4;
    }
  }
storeProgramObject:
  programObject[7] = scratchInt4;
  if (scratchInt4 == 0) {
    return 0;
  }
  programObject[8] = (int)(programObject + 8);
  programObject[9] = (int)(programObject + 8);
  sharedState = *(int *)(ctx + 0xc);
  scratchInt4 = *(int *)(sharedState + 0x2c);
  programObject[4] = sharedState + 0x2c;
  programObject[3] = scratchInt4;
  *(int **)(sharedState + 0x2c) = programObject + 3;
  *(int **)(programObject[3] + 4) = programObject + 3;
setPendingGenerationBits:
  pendingGenerationBits = programObject[0xf];
  if (pendingGenerationBits != 0) {
    if ((pendingGenerationBits & 1) != 0) {
      programObject[5] = programObject[5] + 1;
    }
    if ((pendingGenerationBits & 2) != 0) {
      programObject[6] = programObject[6] + 1;
    }
    programObject[0xf] = 0;
  }
  programHeader = (short *)*programObject;
  if (programHeader[1] == 0) {
    if (*programHeader == -0x79e0) {
      bindResult = ((int (*)())gld_bindProgramRecord)(ctx,programObject);
      return bindResult;
    }
    if (*programHeader == -0x74cf) {
      bindResult = ((int (*)())gld_bindProgramRecord)(ctx,programObject);
      return bindResult & 0xff;
    }
  }
  else if (programHeader[1] == 1) {
    programKind = *programHeader;
    if (programKind == -0x77fc) {
      bindResult = ((int (*)())gld_bindFragmentProgramRecord)(ctx,programObject);
      return bindResult;
    }
    if (programKind == -0x74d0) {
      bindResult = ((int (*)())gld_bindFragmentProgramRecord)(ctx,programObject);
      return bindResult & 0xff;
    }
    if (programKind == -0x7e00) {
      contextRecord = (int *)programObject[9];
      recordListHead = programObject + 8;
      if (contextRecord == recordListHead) {
loopSetContextRecord:
        contextRecord = (int *)_calloc(1,*(int *)(&DAT_001aa4c4 + programObject[7] * 4) + 0x14);
        contextRecord[3] = programObject[5] + -1;
        scratchInt4 = programObject[6];
        contextRecord[2] = ctx;
        contextRecord[1] = (int)recordListHead;
        contextRecord[4] = scratchInt4 + -1;
        *contextRecord = programObject[8];
        programObject[8] = (int)contextRecord;
        *(int **)(*contextRecord + 4) = contextRecord;
      }
      else {
        scratchInt4 = contextRecord[2];
        while (scratchInt4 != ctx) {
          contextRecord = (int *)contextRecord[1];
          if (recordListHead == contextRecord) goto loopSetContextRecord;
          scratchInt4 = contextRecord[2];
        }
      }
      scratchInt4 = gld_bindFragmentShaderSlot(ctx + 0x240,contextRecord + 5);
      if (scratchInt4 != 0) {
        if (contextRecord[3] != programObject[5]) {
          contextRecord[3] = programObject[5];
          scratchInt4 = atifsReplayProgram(ctx + 0x240,*(undefined4 *)(*programObject + 4),contextRecord + 5);
          if (scratchInt4 == 0) {
            return 0;
          }
        }
        *(int **)(ctx + 0x29ec) = contextRecord;
        return 1;
      }
    }
  }
  return 0;
}

/* gld_getProgramParameter @ 0x269a0 (516 bytes) */
int gld_getProgramParameter(ctx, programObject, pname, params)
  int ctx;
  int *programObject;
  undefined4 pname;
  int *params;
{
  int *contextRecord;
  int *paramsCopy;
  short *programHeader;
  undefined4 pnameCopy;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int programField6;
  
  pnameCopy = pname;
  paramsCopy = params;
  _pthread_mutex_lock(*(undefined4 *)(ctx + 0xc));
  if (((programObject != (int *)0x0) && (*programObject != 0)) && (*(int *)(*programObject + 4) != 0)) {
    gld_resolveBoundTextures(ctx,0xffff,pnameCopy,paramsCopy,staleArgR7,staleArgR8);
    gld_updateTextureUnitState(ctx,0xffff);
    ((int (*)())gld_bindProgramObject)(ctx,programObject);
    programHeader = (short *)*programObject;
    if (programHeader[1] == 0) {
      if (*programHeader == -0x79e0) {
        for (contextRecord = (int *)programObject[9]; contextRecord != programObject + 8; contextRecord = (int *)contextRecord[1]) {
          if (ctx == contextRecord[2]) goto switchPname;
        }
        contextRecord = (int *)_calloc(1,*(int *)(&DAT_001aa4c4 + programObject[7] * 4) + 0x14);
        contextRecord[3] = programObject[5] + -1;
        programField6 = programObject[6];
        contextRecord[2] = ctx;
        contextRecord[1] = (int)(programObject + 8);
        contextRecord[4] = programField6 + -1;
        *contextRecord = programObject[8];
        programObject[8] = (int)contextRecord;
        *(int **)(*contextRecord + 4) = contextRecord;
switchPname:
        switch(pname) {
        case 0x88a2:
          *params = contextRecord[0x23];
          break;
        case 0x88a6:
          *params = contextRecord[0x25];
          break;
        case 0x88aa:
          *params = contextRecord[0x24];
          break;
        case 0x88ae:
          *params = contextRecord[0x26];
          break;
        case 0x88b2:
          *params = contextRecord[0x27];
        }
      }
    }
    else if (((programHeader[1] == 1) && (*programHeader != -0x7e00)) && (*programHeader == -0x77fc)) {
      glGetProgramivARB_impl(ctx + 0x240,0x8804,pname,params);
    }
  }
  _pthread_mutex_unlock(*(undefined4 *)(ctx + 0xc));
  return;
}

/* gld_drawArraysDirect @ 0x26bf0 (876 bytes) */
int gld_drawArraysDirect(ctx, staleArgR4, primitiveMode, vertexCount, staleArgR7)
  int ctx;
  undefined4 staleArgR4;
  int primitiveMode;
  int vertexCount;
  undefined4 staleArgR7;
{
  uint streamCountField;
  byte vertexStrideWords;
  int streamRecordExt;
  uint *lastHeader;
  int streamRecord;
  int trimmedCount;
  undefined4 *ringCursor;
  int scratchInt7;
  undefined4 *packetEnd;
  uint primFlagsIndirect;
  undefined4 vapVteCntl;
  uint primFlags;
  int scratchInt12;
  
  if (vertexCount < 4) {
    trimmedCount = ((int (*)())gldTrimVertexCountToPrimitiveMin)(ctx,primitiveMode,vertexCount);
  }
  else {
    trimmedCount = ((int (*)())gldTrimVertexCountToPrimitive)(ctx,primitiveMode,vertexCount);
  }
  if (trimmedCount == 0) {
    return;
  }
  if ((*(uint *)(ctx + 0x27d8) & 6) == 0) {
    if (*(char *)(ctx + 0x27d4) == '\0') {
      vertexStrideWords = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + ctx) + 2);
    }
    else {
      vertexStrideWords = *(byte *)(*(int *)(0x000027d0 + ctx) + 2);
    }
    ringCursor = *(undefined4 **)(ctx + 0x1dc);
    *(undefined4 **)(ctx + 0x298c) = ringCursor;
    if (*(char *)(ctx + 0x27d4) == '\0') {
      scratchInt7 = ctx + 0x2840;
      if (*(int *)(ctx + 0x2680) != scratchInt7) {
        vapVteCntl = *(undefined4 *)(ctx + 0x28e0);
        scratchInt12 = ctx + 0x2860;
        goto storeCtx;
      }
    }
    else {
      scratchInt7 = ctx + 0x28e4;
      if (*(int *)(ctx + 0x2680) != scratchInt7) {
        vapVteCntl = *(undefined4 *)(ctx + 0x2984);
        scratchInt12 = ctx + 0x2904;
storeCtx:
        *(int *)(ctx + 0x2680) = scratchInt7;
        *(int *)(ctx + 0x2684) = scratchInt12;
        *(undefined4 *)(0x000026c8 + ctx + 4) = vapVteCntl;
        ringCursor = (undefined4 *)((int (*)())gld_emitVapStreamControl)(ctx,ringCursor);
      }
    }
    if (*(char *)(ctx + 0x2a42) == '\0') {
      *ringCursor = 0x5c8;
      ringCursor[1] = 0x10000000;
      ringCursor = ringCursor + 2;
      *(undefined1 *)(ctx + 0x2a42) = 1;
    }
    scratchInt7 = (uint)vertexStrideWords * trimmedCount;
    *ringCursor = 0x82c;
    ringCursor[1] = *(undefined4 *)(0x00001dc4 + ctx);
    primFlags = *(uint *)(&DAT_001d9888 + primitiveMode * 4);
    ringCursor[2] = scratchInt7 * 0x10000 | 0xc0003500;
    ringCursor[3] = trimmedCount << 0x10 | primFlags & 0xf | 0x30;
    ringCursor[scratchInt7 + 4] = ((unsigned char *)0x00001393U);
    ringCursor[scratchInt7 + 5] = 0;
    *(undefined4 **)(ctx + 0x298c) = ringCursor + scratchInt7 + 6;
    *(undefined4 **)(ctx + 0x1dc) = ringCursor + scratchInt7 + 6;
    goto storeCtx3;
  }
  streamCountField = *(uint *)(ctx + 0x283c) & 0x1f;
  if (*(char *)(ctx + 0x27d4) == '\0') {
    vertexStrideWords = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + ctx) + 2);
  }
  else {
    vertexStrideWords = *(byte *)(*(int *)(0x000027d0 + ctx) + 2);
  }
  scratchInt12 = *(int *)(ctx + 0x1ec);
  ringCursor = *(undefined4 **)(ctx + 0x1dc);
  scratchInt7 = (uint)vertexStrideWords * trimmedCount * 4;
  *(int *)(ctx + 0x1ec) = scratchInt12 + scratchInt7;
  *(undefined4 **)(ctx + 0x298c) = ringCursor;
  lastHeader = *(uint **)(ctx + 0x1d8);
  *lastHeader = (int)ringCursor - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x1d8) = ringCursor;
  ringCursor[1] = streamCountField;
  ringCursor[2] = scratchInt12 - (int)ringCursor >> 2;
  *ringCursor = 0x38000000;
  ringCursor[3] = 0;
  if (*(char *)(ctx + 0x27d4) == '\0') {
    *(int *)(ctx + 0x26d4) = ctx + 0x2880;
    *(int *)(ctx + 0x26d8) = ctx + 0x28a0;
    *(undefined4 *)(ctx + 0x26d0) = *(undefined4 *)(ctx + 0x283c);
    ringCursor = (undefined4 *)((int (*)())gld_emitStreamAddressRegisters)(ctx,ringCursor + 4);
    streamRecord = ctx + 0x2840;
    if (*(int *)(ctx + 0x2680) != streamRecord) {
      streamRecordExt = ctx + 0x2860;
      goto storeCtx2;
    }
  }
  else {
    *(int *)(ctx + 0x26d4) = ctx + 0x2924;
    *(int *)(ctx + 0x26d8) = ctx + 0x2944;
    *(undefined4 *)(ctx + 0x26d0) = *(undefined4 *)(ctx + 0x283c);
    ringCursor = (undefined4 *)((int (*)())gld_emitStreamAddressRegisters)(ctx,ringCursor + 4);
    streamRecord = ctx + 0x28e4;
    if (*(int *)(ctx + 0x2680) != streamRecord) {
      streamRecordExt = ctx + 0x2904;
storeCtx2:
      *(int *)(ctx + 0x2680) = streamRecord;
      *(int *)(ctx + 0x2684) = streamRecordExt;
      ringCursor = (undefined4 *)((int (*)())gld_emitVapStreamControl)(ctx,ringCursor);
    }
  }
  if (*(char *)(ctx + 0x2a42) != '\0') {
    *ringCursor = 0x5c8;
    ringCursor[1] = 0x10000000;
    ringCursor = ringCursor + 2;
    *(undefined1 *)(ctx + 0x2a42) = 0;
  }
  packetEnd = ringCursor + 6;
  primFlagsIndirect = *(uint *)(&DAT_001d9888 + primitiveMode * 4);
  *ringCursor = 0x82c;
  vapVteCntl = *(undefined4 *)(0x00001dc4 + ctx);
  ringCursor[4] = ((unsigned char *)0x00001393U);
  ringCursor[2] = 0xc0003400;
  ringCursor[5] = 0;
  ringCursor[1] = vapVteCntl;
  ringCursor[3] = trimmedCount << 0x10 | primFlagsIndirect & 0xf | 0x820;
  *(undefined4 **)(ctx + 0x298c) = packetEnd;
  *(undefined4 **)(ctx + 0x1dc) = packetEnd;
  if (((*(uint *)(ctx + 0x27d8) & 2) != 0) && ((*(uint *)(ctx + 0x24) & 2) != 0)) {
    gldFlushDataCacheRange(ctx,scratchInt12,scratchInt7,vertexCount,staleArgR7,streamCountField,0xc0003400,packetEnd);
  }
storeCtx3:
  *(undefined1 *)(ctx + 0x2a5e) = 1;
  return;
}

/* gld_reserveVertexBufferSpace @ 0x26f80 (460 bytes) */
void gld_reserveVertexBufferSpace(int ctx,uint *primitiveInfo,uint *vertexLimitPtr,undefined4 passThroughArg4,undefined4 passThroughArg5,undefined4 passThroughArg6,undefined4 passThroughArg7,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint refillCount;
  uint fittingVertices;
  uint vertexCapacity;
  uint dataLimit;
  uint updateFlags;
  byte vertexStrideWords;
  undefined4 dataBufferId;
  uint alignedCursor;
  uint *activeCountPtr;
  int dataCursor;
  double staleStackArg_ffffff98;
  undefined4 outputCount;
  int bufferBase;
  uint bufferSize;
  
  activeCountPtr = vertexLimitPtr;
  if (((unsigned char *)0x00002b80)[ctx] != '\0') {
    activeCountPtr = primitiveInfo;
    staleFprArg1 = (double)((int (*)())gld_forwardToStream)(ctx,1,primitiveInfo,passThroughArg4,passThroughArg5,passThroughArg6,passThroughArg7);
  }
  if (*(int *)(ctx + 0x1b68) != 0) {
    ((void (*)())gld_revalidateStreamProgram)(ctx + 0x240,primitiveInfo,activeCountPtr,passThroughArg4,passThroughArg5,passThroughArg6,passThroughArg7,staleFprArg1,staleFprArg2,
                 staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffff98);
  }
  if ((*vertexLimitPtr == 0) || (*(int *)(*(int *)(ctx + 0x14) + 0x120) == 0)) {
    vertexStrideWords = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + ctx) + 2);
    *(undefined1 *)(ctx + 0x27d4) = 0;
  }
  else {
    vertexStrideWords = *(byte *)(*(int *)(0x000027d0 + ctx) + 2);
    *(undefined1 *)(ctx + 0x27d4) = 1;
  }
  dataCursor = *(int *)(ctx + 500);
  dataLimit = *(uint *)(ctx + 0x1f8);
  if (dataLimit <= (uint)vertexStrideWords * 0x90 + dataCursor + 0x80) {
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
    _io_connect_method_scalarI_scalarO(*(undefined4 *)(ctx + 4),0x12,0,0,&bufferBase,&outputCount);
    updateFlags = *(uint *)(0x000026c8 + ctx);
    *(int *)(ctx + 0x1fc) = bufferBase;
    dataLimit = bufferBase + (bufferSize & 0xfffffffc);
    *(int *)(ctx + 500) = bufferBase;
    *(uint *)(ctx + 0x1f8) = dataLimit;
    dataBufferId = *(undefined4 *)(*(int *)(ctx + 0x208) + 8);
    *(uint *)(0x000026c8 + ctx) = updateFlags | 1;
    *(undefined4 *)(ctx + 0x200) = dataBufferId;
    dataCursor = bufferBase;
  }
  alignedCursor = dataCursor + 0x7fU & 0xffffff80;
  *(uint *)(ctx + 500) = alignedCursor;
  fittingVertices = (((uint)((int)(dataLimit - alignedCursor) >> 2) / (uint)vertexStrideWords) / 0xc) * 0xc;
  vertexCapacity = 0xfffc;
  if (fittingVertices < 0x10000) {
    vertexCapacity = fittingVertices;
  }
  *vertexLimitPtr = vertexCapacity;
  return;
}

/* gld_drawArraysStream @ 0x27150 (564 bytes) */
int gld_drawArraysStream(ctx, staleArgR4, primitiveMode, vertexCount)
  int ctx;
  undefined4 staleArgR4;
  int primitiveMode;
  int vertexCount;
{
  uint primFlags;
  byte vertexStrideWords;
  uint streamCountWord;
  uint *lastHeader;
  undefined4 scratchUint4;
  int trimmedCount;
  undefined4 *packetBody;
  undefined4 *scratchPtr7;
  int dataBase;
  int streamExtArray;
  int dataCursorBefore;
  int streamAddrArray;
  
  if (vertexCount < 4) {
    trimmedCount = ((int (*)())gldTrimVertexCountToPrimitiveMin)(ctx,primitiveMode,vertexCount);
  }
  else {
    trimmedCount = ((int (*)())gldTrimVertexCountToPrimitive)(ctx,primitiveMode,vertexCount);
  }
  if (trimmedCount != 0) {
    streamCountWord = *(uint *)(ctx + 0x283c);
    if (*(char *)(ctx + 0x27d4) == '\0') {
      vertexStrideWords = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + ctx) + 2);
    }
    else {
      vertexStrideWords = *(byte *)(*(int *)(0x000027d0 + ctx) + 2);
    }
    scratchPtr7 = *(undefined4 **)(ctx + 0x1dc);
    dataCursorBefore = *(int *)(ctx + 500);
    dataBase = *(int *)(ctx + 0x1fc);
    *(uint *)(ctx + 500) = dataCursorBefore + (uint)vertexStrideWords * trimmedCount * 4;
    if (*(undefined4 **)(ctx + 0x1e0) <= scratchPtr7 + 0x53) {
      gld_submitRing(ctx,0x1000000);
      scratchPtr7 = *(undefined4 **)(ctx + 0x1dc);
    }
    packetBody = scratchPtr7;
    if (*(char *)(ctx + 0x2a42) != '\0') {
      packetBody = scratchPtr7 + 2;
      *scratchPtr7 = 0x5c8;
      scratchPtr7[1] = 0x10000000;
      *(undefined1 *)(ctx + 0x2a42) = 0;
    }
    if (*(char *)(ctx + 0x27d4) == '\0') {
      if (*(int *)(ctx + 0x2680) != ctx + 0x2840) {
        *(int *)(ctx + 0x2680) = ctx + 0x2840;
        *(int *)(ctx + 0x2684) = ctx + 0x2860;
        packetBody = (undefined4 *)((int (*)())gld_emitVapStreamControl)(ctx,packetBody);
      }
      lastHeader = *(uint **)(ctx + 0x1d8);
      streamAddrArray = ctx + 0x2880;
      streamExtArray = ctx + 0x28a0;
    }
    else {
      if (*(int *)(ctx + 0x2680) != ctx + 0x28e4) {
        *(int *)(ctx + 0x2680) = ctx + 0x28e4;
        *(int *)(ctx + 0x2684) = ctx + 0x2904;
        packetBody = (undefined4 *)((int (*)())gld_emitVapStreamControl)(ctx,packetBody);
      }
      lastHeader = *(uint **)(ctx + 0x1d8);
      streamAddrArray = ctx + 0x2924;
      streamExtArray = ctx + 0x2944;
    }
    *lastHeader = (int)packetBody - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x1d8) = packetBody;
    *packetBody = 0x36000000;
    scratchUint4 = *(undefined4 *)(ctx + 0x200);
    packetBody[2] = streamCountWord & 0x1f;
    packetBody[3] = dataCursorBefore - dataBase;
    packetBody[1] = scratchUint4;
    *(int *)(ctx + 0x26d4) = streamAddrArray;
    *(int *)(ctx + 0x26d8) = streamExtArray;
    *(undefined4 *)(ctx + 0x26d0) = *(undefined4 *)(ctx + 0x283c);
    scratchPtr7 = (undefined4 *)((int (*)())gld_emitStreamAddressRegisters)(ctx,packetBody + 4);
    primFlags = *(uint *)(&DAT_001d9888 + primitiveMode * 4);
    *scratchPtr7 = 0x82c;
    scratchUint4 = *(undefined4 *)(0x00001dc4 + ctx);
    scratchPtr7[4] = ((unsigned char *)0x00001393U);
    scratchPtr7[2] = 0xc0003400;
    scratchPtr7[5] = 0;
    scratchPtr7[1] = scratchUint4;
    scratchPtr7[3] = trimmedCount << 0x10 | primFlags & 0xf | 0x820;
    *(undefined4 **)(ctx + 0x1dc) = scratchPtr7 + 6;
  }
  return;
}

/* gld_reserveDrawSpace @ 0x273a0 (1484 bytes) */
uint gld_reserveDrawSpace(int ctx,uint *altCountPtr,uint *countInOut,undefined4 staleArgR6,undefined4 staleArgR7,undefined4 staleArgR8,undefined4 staleArgR9,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  byte vertexStrideWords;
  bool usesSecondRecord;
  undefined1 recordSelector;
  undefined4 *alignedRingEnd;
  uint scratchUint5;
  uint reserveSplit;
  uint *activeCountPtr;
  uint scratchUint8;
  uint modeBit;
  uint fittingCount;
  int scratchInt11;
  int scratchInt12;
  uint ringWriteCursor;
  undefined4 *ringCursor;
  uint newModeWord;
  uint vertexStride;
  uint scratchUint17;
  uint scratchUint18;
  double staleStackArg_ffffff98;
  
  activeCountPtr = countInOut;
  if (((unsigned char *)0x00002b80)[ctx] != '\0') {
    activeCountPtr = altCountPtr;
    staleFprArg1 = (double)((int (*)())gld_forwardToStream)(ctx,1,altCountPtr,staleArgR6,staleArgR7,staleArgR8,staleArgR9);
  }
  if (*(int *)(ctx + 0x1b68) != 0) {
    ((void (*)())gld_revalidateStreamProgram)(ctx + 0x240,altCountPtr,activeCountPtr,staleArgR6,staleArgR7,staleArgR8,staleArgR9,staleFprArg1,staleFprArg2,
                 staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffff98);
  }
  if ((*countInOut == 0) || (*(int *)(*(int *)(ctx + 0x14) + 0x120) == 0)) {
    usesSecondRecord = false;
    recordSelector = 0;
    vertexStrideWords = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + ctx) + 2);
  }
  else {
    usesSecondRecord = true;
    recordSelector = 1;
    vertexStrideWords = *(byte *)(*(int *)(0x000027d0 + ctx) + 2);
  }
  vertexStride = (uint)vertexStrideWords;
  *(undefined1 *)(ctx + 0x27d4) = recordSelector;
  scratchUint5 = *(uint *)(ctx + 0x27d8);
  if (!usesSecondRecord) {
    if ((scratchUint5 & 0x10) != 0) goto setModeBit;
loopSetModeBit:
    modeBit = 1;
  }
  else {
    if ((scratchUint5 & 8) == 0) goto loopSetModeBit;
setModeBit:
    modeBit = 2;
  }
  newModeWord = modeBit | scratchUint5 & 0x18;
  if (scratchUint5 != newModeWord) {
    *(int *)(ctx + 0x2680) = ctx + 0x26dc;
  }
  if ((modeBit & 2) == 0) {
    if (*(char *)(ctx + 0x27d4) == '\0') {
      if (*(int *)(ctx + 0x2680) != ctx + 0x2840) goto setScratchUint5;
loopSetScratchInt12:
      scratchInt12 = 2;
      scratchInt11 = 4;
    }
    else {
      if (*(int *)(ctx + 0x2680) == ctx + 0x28e4) goto loopSetScratchInt12;
setScratchUint5:
      scratchUint5 = *(int *)(ctx + 0x267c) + 1U & 0xfffffffe;
      scratchInt11 = scratchUint5 + 8;
      scratchInt12 = scratchUint5 + 6;
    }
    if (*(char *)(ctx + 0x2a42) == '\0') {
      scratchInt11 = scratchInt12 + 4;
    }
    if ((int)*countInOut < 0xc) {
      scratchUint5 = vertexStride * 0xc;
      fittingCount = 0xc;
    }
    else {
      fittingCount = ((int)*countInOut / 0xc) * 0xc;
      scratchUint5 = vertexStride * fittingCount;
      if (0x3fff < scratchUint5) {
        fittingCount = ((0x3fff / vertexStride) / 0xc) * 0xc;
        scratchUint5 = vertexStride * fittingCount;
      }
    }
    ringCursor = *(undefined4 **)(ctx + 0x1dc);
    if (*(undefined4 **)(ctx + 0x1e0) <=
        ringCursor + scratchUint5 + scratchInt11 + 2 + (uint)(*(byte *)(ctx + 8) >> 1) + 4) {
      gld_submitRing(ctx,0x1000000);
      ringCursor = *(undefined4 **)(ctx + 0x1dc);
    }
    scratchUint5 = (int)ringCursor + scratchInt11 * 4 + 0xf & 0xfffffff0;
    alignedRingEnd = (undefined4 *)(scratchUint5 + scratchInt11 * -4);
    *(undefined4 **)(ctx + 0x1dc) = alignedRingEnd;
    for (; ringCursor < alignedRingEnd; ringCursor = ringCursor + 1) {
      *ringCursor = 0x80000000;
    }
    if (*countInOut != 0) goto storeCountInOut;
    scratchUint8 = (((*(int *)(ctx + 0x1e0) - *(int *)(ctx + 0x1dc) >> 2) + -1) -
            (uint)(*(byte *)(ctx + 8) >> 1)) - (scratchInt11 + 2);
    if (0x600 < scratchUint8) {
      scratchUint8 = 0x600;
    }
  }
  else {
    scratchUint5 = *countInOut;
    fittingCount = 0x8b;
    if ((scratchUint5 != 0) && (fittingCount = 0x1000a, scratchUint5 < 0x10000)) {
      fittingCount = scratchUint5 + 0xb;
    }
    scratchUint8 = (uint)*(byte *)(ctx + 8);
    scratchInt12 = 0xc;
    fittingCount = (fittingCount / 0xc) * 0xc;
    scratchUint17 = vertexStride * fittingCount + (uint)(*(byte *)(ctx + 8) >> 1) + 0x20;
    if (*(char *)(ctx + 0x2a42) == '\0') {
      scratchInt12 = 10;
    }
    scratchUint18 = scratchInt12 + ((*(uint *)(ctx + 0x283c) & 0x1f) + 1 >> 1) * 3 + 3;
    if (!usesSecondRecord) {
      if (*(int *)(ctx + 0x2680) != ctx + 0x2840) goto setScratchUint18;
    }
    else if (*(int *)(ctx + 0x2680) != ctx + 0x28e4) {
setScratchUint18:
      scratchUint18 = scratchUint18 + (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 4;
    }
    scratchUint5 = *(uint *)(ctx + 0x1ec);
    if (scratchUint5 == 0) {
      ringWriteCursor = *(uint *)(ctx + 0x1dc);
      scratchInt11 = *(int *)(ctx + 0x1e0);
      scratchUint5 = ((int)(scratchInt11 - ringWriteCursor) >> 2) - 1;
      if (scratchUint5 < scratchUint18 + scratchUint17) {
        if (*(int *)(ctx + 0x1e4) + 0x28U < ringWriteCursor) {
          gld_submitRing(ctx,0x1000000);
          scratchUint8 = (uint)*(byte *)(ctx + 8);
          ringWriteCursor = *(uint *)(ctx + 0x1dc);
          scratchInt11 = *(int *)(ctx + 0x1e0);
        }
        scratchInt12 = scratchInt11 - ringWriteCursor;
loopSetScratchUint5:
        scratchUint5 = (scratchInt12 >> 2) - 1;
        if (scratchUint5 < scratchUint18 + scratchUint17) {
          scratchUint17 = scratchUint5 - scratchUint18;
        }
      }
      reserveSplit = scratchUint5 >> 2;
      if (scratchUint5 >> 2 < scratchUint17) {
        reserveSplit = scratchUint17;
      }
      scratchUint17 = scratchUint5 - reserveSplit;
      if (scratchUint5 - reserveSplit < scratchUint18) {
        scratchUint17 = scratchUint18;
      }
      scratchInt12 = scratchInt11 + 0x94;
      *(int *)(ctx + 0x1f0) = scratchInt12;
      scratchUint5 = ringWriteCursor + scratchUint17 * 4 + 0x9f & 0xfffffff8;
      *(uint *)(ctx + 0x1e0) = scratchUint5;
      scratchUint5 = scratchUint5 + 0x7f & 0xffffff80;
      *(uint *)(ctx + 0x1ec) = scratchUint5;
    }
    else {
      ringWriteCursor = *(uint *)(ctx + 0x1dc);
      scratchInt11 = *(int *)(ctx + 0x1e0);
      scratchInt12 = *(int *)(ctx + 0x1f0);
      if ((((int)(scratchInt11 - ringWriteCursor) >> 2) - 1U < scratchUint18) ||
         ((uint)((int)(scratchInt12 - scratchUint5) >> 2) < scratchUint17)) {
        if (*(int *)(ctx + 0x1e4) + 0x28U < ringWriteCursor) {
          gld_submitRing(ctx,0x1000000);
          scratchUint8 = (uint)*(byte *)(ctx + 8);
          ringWriteCursor = *(uint *)(ctx + 0x1dc);
          scratchInt11 = *(int *)(ctx + 0x1e0);
        }
        scratchInt12 = scratchInt11 - ringWriteCursor;
        goto loopSetScratchUint5;
      }
    }
    scratchUint8 = ((int)(scratchInt12 - scratchUint5) >> 2) - (scratchUint8 >> 1);
    if (vertexStride * fittingCount <= scratchUint8) goto storeCountInOut;
  }
  fittingCount = ((scratchUint8 / vertexStride) / 0xc) * 0xc;
storeCountInOut:
  *countInOut = fittingCount;
  scratchUint8 = (uint)*(byte *)(ctx + 8);
  if (scratchUint8 != 0x20) {
    if ((*(uint *)(ctx + 0x27d8) & 1) == 0) {
      scratchUint17 = *(uint *)(ctx + 0x2838);
    }
    else {
      scratchUint17 = *(uint *)(ctx + 0x2834);
    }
    scratchUint18 = scratchUint17;
    if (scratchUint17 <= scratchUint5) {
      scratchUint18 = (scratchUint5 + scratchUint8) - 1 & -scratchUint8;
    }
    vertexStride = scratchUint5 + vertexStride * fittingCount * 4;
    if (scratchUint17 <= vertexStride) {
      scratchUint17 = (vertexStride + scratchUint8) - 1 & -scratchUint8;
    }
    if (scratchUint18 < scratchUint17) {
      fittingCount = scratchUint17 - scratchUint18;
      for (vertexStride = fittingCount >> 9; vertexStride != 0; vertexStride = vertexStride - 1) {
        dataCacheBlockClearToZero(scratchUint18);
        dataCacheBlockClearToZero(scratchUint18 + scratchUint8);
        dataCacheBlockClearToZero(scratchUint18 + scratchUint8 * 2);
        dataCacheBlockClearToZero(scratchUint18 + scratchUint8 * 3);
        scratchUint18 = scratchUint18 + 0x200;
      }
      for (vertexStride = fittingCount >> 7 & 3; vertexStride != 0; vertexStride = vertexStride - 1) {
        dataCacheBlockClearToZero(scratchUint18);
        scratchUint18 = scratchUint18 + 0x80;
      }
      if ((modeBit & 1) == 0) {
        *(uint *)(ctx + 0x2838) = scratchUint17;
      }
      else {
        *(uint *)(ctx + 0x2834) = scratchUint17;
      }
    }
  }
  *(uint *)(ctx + 0x27d8) = newModeWord;
  return scratchUint5;
}

/* gld_buildVertexStreamCache @ 0x27990 (2360 bytes) */
int gld_buildVertexStreamCache(stream)
  int stream;
{
  uint loopIndex2;
  uint loopIndex3;
  bool scratchFlag1;
  bool scratchFlag2;
  ushort arrayTypeWord;
  int typeRowOffset;
  int typeSizeOffset;
  ushort dataTypeBits;
  int arrayDesc;
  uint pairIndexOrFormatIndex;
  uint swizzleSelectX;
  int scratchInt10;
  uint swizzleSelectY;
  uint hwAttrId;
  uint swizzleSelectZ;
  int scratchInt14;
  uint extWordBits;
  int scratchInt16;
  uint *scratchPtr17;
  uint scratchUint18;
  ushort streamDescHalf;
  uint scratchUint20;
  undefined1 *streamBlockB;
  undefined1 *streamBlockA;
  int wordOffset;
  uint descriptorWord;
  int streamByteOffset;
  int attrByteOffset;
  int programRecord;
  uint swizzleSelectW;
  uint streamCount;
  uint loopIndex;
  int engineObjects;
  int attrsLeft;
  uint scratchUint33;
  int slotCounter;
  uint totalWords;
  int fetchBase;
  int programVertexInfo;
  int inputMap;
  
  *(int *)(stream + 0x2440) = stream + 0x249c;
  *(int *)(stream + 0x2444) = stream + 0x24bc;
  *(undefined4 *)(stream + 0x2494) = 0;
  engineObjects = *(int *)(stream + 4);
  streamCount = *(uint *)(stream + 0x243c);
  if ((((*(char *)(engineObjects + 0x20) == '\0') ||
       (*(int *)(((unsigned char *)0x00003170) + *(int *)(engineObjects + 0x10)) != 0x1b021b02)) || (streamCount < 2)) ||
     (0x10 < streamCount)) {
    if ((*(int *)(*(int *)(engineObjects + 0x14) + 0x11c) == 0) &&
       (*(int *)(*(int *)(engineObjects + 0x14) + 0x120) == 0)) {
      return;
    }
switchD_00027e30_default:
    *(uint *)(stream + 0x2488) = *(uint *)(stream + 0x2488) | 2;
    *(undefined4 *)(*(int *)(engineObjects + 0x14) + 0x11c) = 0;
    *(undefined4 *)(*(int *)(engineObjects + 0x14) + 0x120) = 0;
    return;
  }
  if (*(int **)(engineObjects + 0x1cc) == (int *)0x0) {
    programRecord = 0;
    fetchBase = 0;
    programVertexInfo = 0;
    inputMap = 0;
  }
  else {
    programVertexInfo = *(int *)(**(int **)(engineObjects + 0x1cc) + 4);
    programRecord = *(int *)(engineObjects + 0x29e8) + 0x14;
    inputMap = *(int *)(*(int *)(engineObjects + 0x29e8) + 0x34);
    fetchBase = *(int *)(programVertexInfo + 0x24);
  }
  streamBlockA = *(undefined1 **)(stream + 0x258c);
  arrayDesc = **(int **)(*(int *)(engineObjects + 0x18) + 0x194);
  *(undefined1 **)(*(int *)(engineObjects + 0x14) + 0x11c) = streamBlockA;
  streamBlockB = *(undefined1 **)(stream + 0x2590);
  *(undefined1 **)(*(int *)(engineObjects + 0x14) + 0x120) = streamBlockB;
  if (*(char *)(stream + 0x2595) != '\0') {
    *(undefined4 *)(*(int *)(engineObjects + 0x14) + 0x120) = 0;
  }
  *(uint *)(stream + 0x2488) = *(uint *)(stream + 0x2488) | 2;
  scratchInt14 = stream;
  for (scratchUint33 = streamCount + 1 >> 1; scratchUint33 != 0; scratchUint33 = scratchUint33 - 1) {
    *(undefined4 *)(scratchInt14 + 0x26a4) = *(undefined4 *)(scratchInt14 + 0x1be4);
    *(undefined4 *)(scratchInt14 + 0x26c4) = *(undefined4 *)(scratchInt14 + 0x1c04);
    *(undefined4 *)(scratchInt14 + 0x2600) = *(undefined4 *)(scratchInt14 + 0x1be4);
    *(undefined4 *)(scratchInt14 + 0x2620) = *(undefined4 *)(scratchInt14 + 0x1c04);
    scratchInt14 = scratchInt14 + 4;
  }
  *(undefined4 *)(stream + 0x26a0) = *(undefined4 *)(stream + 0x1ca4);
  *(uint *)(stream + 0x25fc) = streamCount & 0x1f | 0x20;
  if (*(int *)(engineObjects + 0x1cc) == 0) {
    scratchInt14 = *(int *)(stream + 4);
  }
  else {
    scratchInt14 = *(int *)(stream + 4);
    loopIndex2 = 0;
    scratchInt16 = 0;
    scratchInt10 = 0x16;
    scratchFlag1 = *(int *)(scratchInt14 + 0x1cc) == 0;
    do {
      if (scratchFlag1) {
        if ((1 << (loopIndex2 & 0x3f) & *(uint *)(stream + 0x1ca0)) != 0) goto checkScratchFlag1;
      }
      else if ((*(int *)(scratchInt16 + *(int *)(programRecord + 0x20)) != 0x80) ||
              (*(uint *)(programRecord + 0x1c) <= loopIndex2)) {
checkScratchFlag1:
        if (scratchFlag1) {
          attrsLeft = *(int *)(scratchInt16 + 0x1d9e58);
        }
        else {
          if (*(uint *)(programRecord + 0x1c) <= loopIndex2) goto switchD_00027c3c_default;
          attrsLeft = (fetchBase + *(int *)(inputMap + scratchInt16)) * 8;
          descriptorWord = *(uint *)(programVertexInfo + attrsLeft);
          scratchPtr17 = (uint *)(programVertexInfo + attrsLeft);
          attrsLeft = *(int *)(&DAT_001d9eb0 + (descriptorWord >> 0xe & 0x3c));
          if (attrsLeft == 8) {
            attrsLeft = (descriptorWord & 0x1f) + 8;
          }
          else if (attrsLeft == 0x10) {
            attrsLeft = (descriptorWord & 0x1f) + 0x10;
          }
          else if (attrsLeft == 0x2f) {
            switch(descriptorWord >> 0xc & 0xf) {
            case 0:
              attrsLeft = (*scratchPtr17 & 1) + 0x20;
              break;
            case 1:
              attrsLeft = (*scratchPtr17 & 1) + 0x22;
              break;
            case 2:
              attrsLeft = (*scratchPtr17 & 1) + 0x24;
              break;
            case 3:
              attrsLeft = (*scratchPtr17 & 1) + 0x26;
              break;
            case 4:
              attrsLeft = (*scratchPtr17 & 1) + 0x28;
              break;
            default:
              goto switchD_00027c3c_default;
            }
          }
        }
        if ((attrsLeft == 0) || (attrsLeft == 0x10)) {
          scratchFlag1 = true;
          goto setStreamByteOffset;
        }
      }
switchD_00027c3c_default:
      scratchInt10 = scratchInt10 + -1;
      loopIndex2 = loopIndex2 + 1;
      scratchInt16 = scratchInt16 + 4;
    } while (scratchInt10 != 0);
  }
  scratchFlag1 = false;
setStreamByteOffset:
  streamByteOffset = 0;
  totalWords = 0;
  scratchUint33 = 0;
  wordOffset = 0;
  slotCounter = 1;
  attrsLeft = 0x16;
  loopIndex3 = 0;
  scratchInt10 = 0;
  loopIndex = 0;
  attrByteOffset = 0;
  scratchInt16 = stream;
loopSetScratchFlag2:
  scratchFlag2 = *(int *)(scratchInt14 + 0x1cc) == 0;
  if (scratchFlag2) {
    if ((1 << (loopIndex3 & 0x3f) & *(uint *)(stream + 0x1ca0)) != 0) goto checkScratchFlag2;
    goto checkLoopIndex;
  }
  if ((*(int *)(attrByteOffset + *(int *)(programRecord + 0x20)) == 0x80) && (loopIndex3 < *(uint *)(programRecord + 0x1c)))
  goto checkLoopIndex;
checkScratchFlag2:
  if (scratchFlag2) {
    hwAttrId = *(uint *)(attrByteOffset + 0x1d9e58);
loopCheckHwAttrId:
    if (hwAttrId == 0x30) goto switchD_00027e30_default;
    scratchUint20 = hwAttrId & 0xffff;
  }
  else {
    if (loopIndex3 < *(uint *)(programRecord + 0x1c)) {
      scratchInt14 = (fetchBase + *(int *)(inputMap + attrByteOffset)) * 8;
      scratchUint20 = *(uint *)(programVertexInfo + scratchInt14);
      scratchPtr17 = (uint *)(programVertexInfo + scratchInt14);
      hwAttrId = *(uint *)(&DAT_001d9eb0 + (scratchUint20 >> 0xe & 0x3c));
      if (hwAttrId == 8) {
        hwAttrId = (scratchUint20 & 0x1f) + 8;
      }
      else if (hwAttrId == 0x10) {
        hwAttrId = (scratchUint20 & 0x1f) + 0x10;
      }
      else if (hwAttrId == 0x2f) {
        switch(scratchUint20 >> 0xc & 0xf) {
        case 0:
          hwAttrId = (*scratchPtr17 & 1) + 0x20;
          break;
        case 1:
          hwAttrId = (*scratchPtr17 & 1) + 0x22;
          break;
        case 2:
          hwAttrId = (*scratchPtr17 & 1) + 0x24;
          break;
        case 3:
          hwAttrId = (*scratchPtr17 & 1) + 0x26;
          break;
        case 4:
          hwAttrId = (*scratchPtr17 & 1) + 0x28;
          break;
        default:
          goto switchD_00027e30_default;
        }
      }
      goto loopCheckHwAttrId;
    }
    hwAttrId = 2;
    scratchUint20 = 2;
  }
  if ((scratchFlag1) && ((hwAttrId == 0 || (scratchInt10 = slotCounter, hwAttrId == 0x10)))) {
    scratchInt10 = 0;
  }
  pairIndexOrFormatIndex = loopIndex >> 1;
  if (scratchFlag2) {
    scratchUint18 = *(uint *)(attrByteOffset + 0x1d9edc) & 0xffff;
  }
  else {
    scratchUint18 = 3;
  }
  scratchFlag2 = (loopIndex & 1) == 0;
  if (scratchFlag2) {
    scratchInt14 = pairIndexOrFormatIndex * 4 + stream;
    *(uint *)(scratchInt14 + 0x2640) = (streamCount & 0x1f) << 10 | *(uint *)(scratchInt14 + 0x2640) & 0xffff8080 | 4
    ;
  }
  else {
    scratchInt14 = pairIndexOrFormatIndex * 4 + stream;
    *(uint *)(scratchInt14 + 0x2640) =
         (streamCount & 0x1f) << 0x1a | *(uint *)(scratchInt14 + 0x2640) & 0x8080ffff | 0x40000;
  }
  scratchInt14 = pairIndexOrFormatIndex * 4;
  dataTypeBits = (ushort)(scratchUint20 << 10);
  streamDescHalf = (ushort)(scratchUint18 << 8) | dataTypeBits;
  *(int *)(loopIndex * 4 + stream + 0x2660) = streamByteOffset;
  *(ushort *)(streamBlockA + scratchInt10 * 2 + 4) = streamDescHalf | (ushort)streamByteOffset;
  if (*(char *)(stream + 0x2595) == '\0') {
    arrayTypeWord = *(ushort *)(hwAttrId * 0x18 + arrayDesc + 8);
    if (hwAttrId < 0x10) {
      scratchUint33 = *(uint *)(arrayDesc + 0x304);
    }
    else {
      scratchUint33 = *(uint *)(arrayDesc + 0x300);
    }
    if ((scratchUint33 & *(uint *)(&DAT_001d9dd8 + hwAttrId * 4)) == 0) {
      scratchUint33 = 4;
      extWordBits = 4;
      scratchUint20 = 3;
      scratchUint18 = 0;
      hwAttrId = 0;
      swizzleSelectX = 0;
      swizzleSelectY = 1;
      swizzleSelectZ = 2;
      swizzleSelectW = 3;
      pairIndexOrFormatIndex = 0;
    }
    else {
      typeRowOffset = ((arrayTypeWord & 0xffff7fff) - 0x1400) * 4;
      typeSizeOffset = (typeRowOffset + *(short *)(hwAttrId * 0x18 + arrayDesc + 10) + -1) * 4;
      scratchUint33 = *(uint *)(&DAT_001d9c4c + typeSizeOffset);
      streamDescHalf = (ushort)(*(int *)(&DAT_001d9cfc + typeSizeOffset) << 8) | dataTypeBits;
      hwAttrId = (uint)(arrayTypeWord >> 0xf);
      scratchUint20 = *(uint *)(&DAT_001d9b9c + typeSizeOffset) & 0xff;
      pairIndexOrFormatIndex = *(uint *)(&DAT_001d9dac + typeRowOffset) & 0xffff;
      scratchUint18 = *(uint *)(&DAT_001d9b70 + typeRowOffset) & 0xff;
      swizzleSelectX = *(uint *)(&DAT_001d9ac0 + typeSizeOffset) & 0xff;
      extWordBits = scratchUint33 & 0xff;
      swizzleSelectY = *(uint *)(&DAT_001d9a10 + typeSizeOffset) & 0xff;
      swizzleSelectZ = *(uint *)(&DAT_001d9960 + typeSizeOffset) & 0xff;
      swizzleSelectW = *(uint *)(&DAT_001d98b0 + typeSizeOffset) & 0xff;
    }
    if (scratchFlag2) {
      *(uint *)(scratchInt14 + stream + 0x26e4) =
           extWordBits & 0x7f | *(uint *)(scratchInt14 + stream + 0x26e4) & 0xffffff80;
    }
    else {
      *(uint *)(scratchInt14 + stream + 0x26e4) =
           (extWordBits & 0x7f) << 0x10 | *(uint *)(scratchInt14 + stream + 0x26e4) & 0xff80ffff;
    }
    *(int *)(loopIndex * 4 + stream + 0x2704) = wordOffset;
    if (scratchFlag2) {
      scratchInt14 = scratchInt14 + stream;
      *(uint *)(scratchInt14 + 0x26a4) =
           hwAttrId << 0xf |
           (scratchUint18 & 1) << 0xe | scratchUint20 & 0xf | *(uint *)(scratchInt14 + 0x26a4) & 0xffff3ff0;
      *(uint *)(scratchInt14 + 0x26c4) =
           (swizzleSelectW & 7) << 9 |
           (swizzleSelectZ & 7) << 6 |
           (swizzleSelectY & 7) << 3 | swizzleSelectX & 7 | *(uint *)(scratchInt14 + 0x26c4) & 0xfffff000;
    }
    else {
      scratchInt14 = scratchInt14 + stream;
      *(uint *)(scratchInt14 + 0x26a4) =
           hwAttrId << 0x1f |
           (scratchUint18 & 1) << 0x1e | (scratchUint20 & 0xf) << 0x10 | *(uint *)(scratchInt14 + 0x26a4) & 0x3ff0ffff;
      *(uint *)(scratchInt14 + 0x26c4) =
           (swizzleSelectW & 7) << 0x19 |
           (swizzleSelectZ & 7) << 0x16 |
           (swizzleSelectY & 7) << 0x13 | (swizzleSelectX & 7) << 0x10 | *(uint *)(scratchInt14 + 0x26c4) & 0xf000ffff;
    }
    *(ushort *)(streamBlockB + scratchInt10 * 2 + 4) = streamDescHalf | (ushort)(pairIndexOrFormatIndex << 6) | (ushort)wordOffset;
  }
  *(uint *)(scratchInt16 + 0x259c) = loopIndex;
  streamByteOffset = streamByteOffset + 4;
  wordOffset = wordOffset + scratchUint33;
  loopIndex = loopIndex + 1;
  totalWords = totalWords + scratchUint33;
  if (!scratchFlag1) {
    scratchInt10 = scratchInt10 + 1;
  }
  else if (scratchInt10 != 0) {
    slotCounter = slotCounter + 1;
  }
checkLoopIndex:
  if (loopIndex == streamCount) {
loopCheckStream:
    if (*(char *)(stream + 0x2595) == '\0') {
      descriptorWord = 0;
      scratchFlag1 = false;
      *(uint *)(stream + 0x2744) = totalWords & 0x7f | *(uint *)(stream + 0x2744) & 0xffffff80;
      scratchUint33 = streamCount;
      do {
        if (scratchFlag1) {
          programRecord = (descriptorWord & 0x7ffffffe) * 2 + stream;
          *(uint *)(programRecord + 0x26e4) =
               (totalWords & 0x7f) << 0x18 | *(uint *)(programRecord + 0x26e4) & 0x80ffffff;
        }
        else {
          programRecord = (descriptorWord & 0x7ffffffe) * 2 + stream;
          *(uint *)(programRecord + 0x26e4) =
               (totalWords & 0x7f) << 8 | *(uint *)(programRecord + 0x26e4) & 0xffff80ff;
        }
        descriptorWord = descriptorWord + 1;
        scratchFlag1 = (bool)(scratchFlag1 ^ 1);
        scratchUint33 = scratchUint33 - 1;
      } while (scratchUint33 != 0);
    }
    *streamBlockA = (char)streamCount;
    *streamBlockB = (char)streamCount;
    streamBlockA[1] = 0;
    streamBlockB[1] = 0;
    streamBlockA[2] = (char)(streamCount << 2);
    streamBlockB[2] = (char)totalWords;
    if (*(char *)(engineObjects + 8) == ' ') {
      scratchUint33 = 0x20;
      if (7 < streamCount << 2) {
        streamBlockA[1] = streamBlockA[1] | 0x40;
        scratchUint33 = (uint)*(byte *)(engineObjects + 8);
      }
      if (scratchUint33 >> 2 <= totalWords) {
        streamBlockB[1] = streamBlockB[1] | 0x40;
      }
    }
    *(uint *)(stream + 0x2598) = *(uint *)(stream + 0x2598) & 0xffffffe7;
    return;
  }
  loopIndex3 = loopIndex3 + 1;
  attrByteOffset = attrByteOffset + 4;
  scratchInt16 = scratchInt16 + 4;
  attrsLeft = attrsLeft + -1;
  if (attrsLeft == 0) goto loopCheckStream;
  scratchInt14 = *(int *)(stream + 4);
  goto loopSetScratchFlag2;
}

/* gld_readPixelsViaBlit @ 0x28350 (3820 bytes) */
int gld_readPixelsViaBlit(ctx, rectX, rectY, width, height, format, pixelType, pixels, transferMode, surfaceInfo)
  int ctx;
  uint rectX;
  uint rectY;
  uint width;
  uint height;
  uint format;
  undefined *pixelType;
  int pixels;
  undefined4 transferMode;
  undefined4 *surfaceInfo;
{
  float flippedYF;
  float negRectXF;
  float rectRightF;
  float rectXF;
  float heightF;
  float widthF;
  undefined4 readSurfaceCode;
  undefined4 streamPtr;
  uint widthArg;
  uint heightArg;
  uint surfaceBase;
  uint dstAddress;
  undefined4 *packetEnd;
  int *targetSlot;
  int unitOffset;
  int storeResult;
  int prepareResult;
  undefined4 ga_point_size;
  undefined4 sc_scissor1;
  undefined4 rb3d_ropcntl;
  undefined4 rb3d_color_channel_mask;
  undefined4 tx_format2;
  undefined4 tx_format1;
  undefined4 tx_format0;
  undefined4 tx_filter0;
  undefined4 rs_ip_0;
  undefined4 rs_count;
  undefined4 us_out_fmt_3;
  undefined4 us_out_fmt_2;
  undefined4 us_out_fmt_1;
  undefined4 us_out_fmt_0;
  undefined4 gb_ps3_enable;
  undefined4 tx_enable;
  undefined4 ga_color_control;
  undefined4 ga_poly_mode;
  undefined4 zb_cntl;
  undefined4 vap_prog_stream_cntl_ext_0_ptr;
  undefined4 vap_prog_stream_cntl_0_ptr;
  undefined4 vap_out_vtx_fmt_1;
  undefined4 vap_out_vtx_fmt_0;
  undefined4 gb_enable;
  undefined4 rb3d_dither_ctl;
  undefined4 su_cull_mode;
  undefined4 vap_clip_cntl;
  undefined4 vap_cntl_status;
  undefined4 zb_zstencilcntl;
  undefined4 zb_bw_cntl;
  undefined4 sc_hyperz_en;
  undefined4 gb_aa_config;
  undefined4 gb_mspos1;
  undefined4 sc_screendoor;
  undefined4 sc_edgerule;
  uint fg_alpha_func;
  uint fg_fog_blend;
  bool lastUnit;
  float scratchFloat2;
  float scratchFloat3;
  float scratchFloat4;
  float renderWidthOrInverse;
  float renderHeightOrInverse;
  float scratchFloat7;
  float scratchFloat8;
  float scratchFloat9;
  float readLeft;
  float scratchFloat11;
  float scratchFloat12;
  float readTopOverflow;
  float scratchFloat14;
  float quadRight;
  float quadLeft;
  float quadLeftMinusRectX;
  float scratchFloat18;
  double i2dMagic;
  undefined *formatTable;
  uint oldColorFormatWord;
  uint *lastHeader;
  int *surfaceRefPtr;
  int scratchInt24;
  uint *packetRaw;
  undefined4 *packet;
  uint scratchUint27;
  int unitObject;
  uint scratchUint29;
  undefined4 packetConst110f8;
  undefined4 packetConstAaaa;
  undefined4 *surfaceObject;
  uint scratchUint33;
  undefined4 scratchUint34;
  undefined4 packetHeaderC0221000;
  uint clampedWidth;
  uint clampedHeight;
  uint scratchUint38;
  int unitIndex;
  int ring;
  int hwFormat;
  char reservation;
  byte bVar42;
  int targetsLeft;
  uint rowBytes;
  undefined1 layoutOut [4];
  int packOffsets [2];
  undefined4 widthI2dHi;
  uint widthI2dLo;
  undefined4 heightI2dHi;
  uint heightI2dLo;
  undefined4 rectXI2dHi;
  uint rectXI2dLo;
  undefined4 rectRightI2dHi;
  uint rectRightI2dLo;
  undefined4 renderWidthI2dHi;
  uint renderWidthI2dLo;
  undefined4 renderHeightI2dHi;
  uint renderHeightI2dLo;
  undefined4 negRectXI2dHi;
  uint negRectXI2dLo;
  undefined4 flippedYI2dHi;
  uint flippedYI2dLo;
  undefined4 rectYI2dHi;
  uint rectYI2dLo;
  undefined4 rectBottomI2dHi;
  uint rectBottomI2dLo;
  undefined4 heightI2dHi2;
  uint heightI2dLo2;
  longlong fctiwzScratch0;
  longlong fctiwzScratch1;
  
  if (format == 0x1909) {
    hwFormat = 1;
    if (pixelType != ((unsigned char *)0x00001401)) {
      hwFormat = 0x13;
      if ((pixelType == ((unsigned char *)0x00001406)) || (hwFormat = 0x1f, pixelType == ((unsigned char *)0x0000140b)))
      goto checkX1000;
      hwFormat = 0;
      if (pixelType == ((unsigned char *)0x00001403)) {
        hwFormat = 0x19;
        goto checkX1000;
      }
    }
  }
  else if (format < 0x190a) {
    if (format == 0x1907) {
      hwFormat = 5;
      if ((pixelType != (undefined *)0x8363) && (hwFormat = 0x28, pixelType != (undefined *)0x8032)) {
        return 0;
      }
      goto checkX1000;
    }
    if (format < 0x1908) {
      if (format != 0x1906) {
        return 0;
      }
      hwFormat = 2;
      if (pixelType != ((unsigned char *)0x00001401)) {
        hwFormat = 0x14;
        if ((pixelType == ((unsigned char *)0x00001406)) || (hwFormat = 0x20, pixelType == ((unsigned char *)0x0000140b)))
        goto checkX1000;
        hwFormat = 0;
        if (pixelType == ((unsigned char *)0x00001403)) {
          hwFormat = 0x1a;
          goto checkX1000;
        }
      }
      goto checkHwFormat;
    }
    hwFormat = 0x12;
    if (pixelType == ((unsigned char *)0x00001406)) {
loopCheckPixelType:
      if (pixelType != (undefined *)0x8367) {
        if (pixelType == ((unsigned char *)0x00001401)) {
          hwFormat = 9;
          goto checkX1000;
        }
        goto checkPixelType;
      }
      hwFormat = 10;
    }
    else {
      hwFormat = 0x1e;
      if (pixelType != ((unsigned char *)0x0000140b)) {
        hwFormat = 0;
        if (pixelType != (undefined *)0x8035) goto loopCheckPixelType;
        hwFormat = 9;
      }
checkPixelType:
      if (pixelType == (undefined *)0x8368) {
        hwFormat = 0x23;
        goto checkX1000;
      }
    }
    if (pixelType == ((unsigned char *)0x00001403)) {
      hwFormat = 0x18;
      goto checkX1000;
    }
  }
  else {
    if (format != 0x80e1) {
      if (format == 0x85b9) {
        hwFormat = 0x27;
        if ((pixelType != (undefined *)0x85ba) && (hwFormat = 0x26, pixelType != (undefined *)0x85bb)) {
          return 0;
        }
        goto checkX1000;
      }
      if (format != 0x190a) {
        return 0;
      }
      hwFormat = 4;
      if (pixelType != ((unsigned char *)0x00001401)) {
        if (pixelType == ((unsigned char *)0x00001406)) {
          hwFormat = 0x16;
          goto checkX1000;
        }
        hwFormat = 0x22;
        if (pixelType == ((unsigned char *)0x0000140b)) goto checkX1000;
        hwFormat = 0;
        if (pixelType == ((unsigned char *)0x00001403)) {
          hwFormat = 0x1c;
          goto checkX1000;
        }
      }
      goto checkHwFormat;
    }
    hwFormat = 7;
    if (pixelType == (undefined *)0x8366) {
loopCheckPixelType2:
      if (pixelType != (undefined *)0x8035) {
loopCheckPixelType3:
        if (pixelType == ((unsigned char *)0x00001401)) {
          hwFormat = 8;
          goto checkHwFormat;
        }
        goto checkPixelType2;
      }
      hwFormat = 8;
loopCheckPixelType4:
      if (pixelType == ((unsigned char *)0x00001406)) {
        hwFormat = 0x11;
        goto checkX1000;
      }
      if (pixelType == ((unsigned char *)0x0000140b)) {
        hwFormat = 0x1d;
        goto checkX1000;
      }
    }
    else {
      if (pixelType == (undefined *)0x8365) {
        hwFormat = 6;
        goto loopCheckPixelType3;
      }
      hwFormat = 0;
      if (pixelType != (undefined *)0x8367) goto loopCheckPixelType2;
      hwFormat = 0xb;
checkPixelType2:
      if (pixelType != (undefined *)0x8368) goto loopCheckPixelType4;
      hwFormat = 0x24;
    }
    if (pixelType == ((unsigned char *)0x00001403)) {
      hwFormat = 0x17;
      goto checkX1000;
    }
  }
checkHwFormat:
  if (hwFormat == 0) {
    return 0;
  }
checkX1000:
  if ((((0x1000 < (int)width) || (0x1000 < (int)height)) || (0x1000 < *(int *)(ctx + GLD_renderWidth)))
     || (0x1000 < *(int *)(ctx + GLD_renderHeight))) {
    return 0;
  }
  _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
  lastHeader = &rowBytes;
  widthArg = width;
  heightArg = height;
  gld_computePixelStoreLayout(ctx,format,pixelType,width,height,lastHeader,layoutOut,packOffsets,
               ((unsigned char *)0x00002e50) + *(int *)(ctx + GLD_engineState));
  dstAddress = pixels + packOffsets[0];
  if ((int)width < 1) {
    clampedWidth = 1;
    widthF = FLOAT_001aa0e8;
  }
  else {
    widthI2dLo = width ^ 0x80000000;
    widthI2dHi = 0x43300000;
    widthF = (float)((double)CONCAT44(0x43300000,widthI2dLo) - DOUBLE_001aa1e0);
    clampedWidth = width;
  }
  if ((int)height < 1) {
    clampedHeight = 1;
    heightF = FLOAT_001aa0e8;
  }
  else {
    heightI2dLo = height ^ 0x80000000;
    heightI2dHi = 0x43300000;
    heightF = (float)((double)CONCAT44(0x43300000,heightI2dLo) - DOUBLE_001aa1e0);
    clampedHeight = height;
  }
  rectXI2dLo = rectX ^ 0x80000000;
  scratchUint34 = 0x43300000;
  rectBottomI2dLo = height + rectY ^ 0x80000000;
  rectYI2dLo = rectY ^ 0x80000000;
  rectBottomI2dHi = 0x43300000;
  rectXI2dHi = 0x43300000;
  rectRightI2dHi = 0x43300000;
  rectYI2dHi = 0x43300000;
  negRectXI2dLo = -rectX ^ 0x80000000;
  flippedYI2dLo = clampedHeight - rectY ^ 0x80000000;
  rectRightI2dLo = width + rectX ^ 0x80000000;
  renderWidthI2dHi = 0x43300000;
  renderHeightI2dHi = 0x43300000;
  negRectXI2dHi = 0x43300000;
  flippedYI2dHi = 0x43300000;
  renderWidthI2dLo = *(uint *)(ctx + GLD_renderWidth) ^ 0x80000000;
  renderHeightI2dLo = *(uint *)(ctx + GLD_renderHeight) ^ 0x80000000;
  rectXF = (float)((double)CONCAT44(0x43300000,rectXI2dLo) - DOUBLE_001aa1e0) + FLOAT_001aa0d4;
  scratchFloat9 = heightF - (float)((double)CONCAT44(0x43300000,rectBottomI2dLo) - DOUBLE_001aa1e0);
  rectRightF = (float)((double)CONCAT44(0x43300000,rectRightI2dLo) - DOUBLE_001aa1e0) + FLOAT_001aa0d4;
  scratchFloat14 = rectXF;
  if (rectXF < 0.0) {
    scratchFloat14 = FLOAT_001aa0d4;
  }
  negRectXF = (float)((double)CONCAT44(0x43300000,negRectXI2dLo) - DOUBLE_001aa1e0);
  flippedYF = (float)((double)CONCAT44(0x43300000,flippedYI2dLo) - DOUBLE_001aa1e0);
  renderWidthOrInverse = (float)((double)CONCAT44(0x43300000,renderWidthI2dLo) - DOUBLE_001aa1e0);
  renderHeightOrInverse = (float)((double)CONCAT44(0x43300000,renderHeightI2dLo) - DOUBLE_001aa1e0);
  quadLeft = FLOAT_001aa0d4;
  if (-rectXF < 0.0) {
    quadLeft = scratchFloat14;
  }
  scratchFloat12 = heightF - (float)((double)CONCAT44(0x43300000,rectYI2dLo) - DOUBLE_001aa1e0);
  scratchFloat14 = FLOAT_001aa0d4;
  scratchFloat18 = FLOAT_001aa148;
  if (FLOAT_001aa0d4 < scratchFloat9) {
    scratchFloat14 = scratchFloat9;
    scratchFloat18 = -scratchFloat9;
  }
  scratchFloat8 = renderWidthOrInverse - rectRightF;
  scratchFloat9 = renderHeightOrInverse - scratchFloat12;
  scratchFloat18 = flippedYF + scratchFloat18;
  quadLeftMinusRectX = quadLeft + negRectXF;
  if (scratchFloat8 < 0.0) {
    rectRightF = renderWidthOrInverse;
  }
  if (scratchFloat9 < 0.0) {
    scratchFloat12 = renderHeightOrInverse;
  }
  readTopOverflow = scratchFloat18 - heightF;
  readLeft = quadLeftMinusRectX;
  if (quadLeftMinusRectX < 0.0) {
    readLeft = FLOAT_001aa0d4;
  }
  quadRight = renderWidthOrInverse;
  if (-scratchFloat8 < 0.0) {
    quadRight = rectRightF;
  }
  scratchFloat11 = heightF;
  if (readTopOverflow < 0.0) {
    scratchFloat11 = scratchFloat18;
  }
  scratchFloat18 = renderHeightOrInverse;
  if (-scratchFloat9 < 0.0) {
    scratchFloat18 = scratchFloat12;
  }
  scratchFloat9 = FLOAT_001aa0d4;
  if (-quadLeftMinusRectX < 0.0) {
    scratchFloat9 = readLeft;
  }
  negRectXF = quadRight + negRectXF;
  if (-readTopOverflow < 0.0) {
    scratchFloat11 = heightF;
  }
  flippedYF = flippedYF - scratchFloat18;
  scratchFloat2 = negRectXF - widthF;
  scratchFloat12 = flippedYF;
  if (flippedYF < 0.0) {
    scratchFloat12 = FLOAT_001aa0d4;
  }
  scratchFloat8 = widthF;
  if (scratchFloat2 < 0.0) {
    scratchFloat8 = negRectXF;
  }
  scratchFloat3 = FLOAT_001aa0d4;
  if (-flippedYF < 0.0) {
    scratchFloat3 = scratchFloat12;
  }
  if (-scratchFloat2 < 0.0) {
    scratchFloat8 = widthF;
  }
  if ((scratchFloat8 <= scratchFloat9) || (scratchFloat11 <= scratchFloat3)) {
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    return 1;
  }
  if (((((*(int *)surfaceInfo[1] != 0) && (prepareResult = gld_prepareBufferBacking(ctx,surfaceInfo,1), prepareResult == 0)) ||
       ((formatTable = PTR_DAT_001e88c8, (int *)surfaceInfo[2] == (int *)0x0 ||
        ((prepareResult = *(int *)surfaceInfo[2], prepareResult == 0 ||
         (surfaceBase = *(uint *)*surfaceInfo, dstAddress != surfaceBase)))))) ||
      ((*(char *)(prepareResult + 0x16) != '\x06' && ((format != 0x1908 || (pixelType != ((unsigned char *)0x00001406)))))))
     || (((dstAddress | rowBytes) & 0x1f) != 0)) {
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    return 0;
  }
  if (surfaceBase != 0) {
    gldFlushDataCacheRangeSync(ctx,surfaceBase,clampedHeight * rowBytes,widthArg,heightArg,lastHeader,0,scratchUint34);
  }
  ring = ctx + GLD_commandStream;
  unitIndex = 0xf;
  streamPtr = (**(code **)(ctx + GLD_streamAllocate))(ring,0x343);
  *(undefined4 *)(ctx + GLD_streamCurrent) = streamPtr;
  scratchInt24 = ctx;
  do {
    if (*(int *)(scratchInt24 + 0x1c8) != 0) {
      streamPtr = ((int (*)())gld_emitUnitObjectPacket)(ctx,0,unitIndex,streamPtr);
    }
    unitIndex = unitIndex + -1;
    bVar42 = (unitIndex == 0) << 1;
    scratchInt24 = scratchInt24 + -4;
  } while (unitIndex != 0);
  packetRaw = (uint *)((int (*)())gld_emitUnitObjectPacket)(ctx,0,0,streamPtr);
  packet = (undefined4 *)((uint)(packetRaw + 0xb) & 0xffffffe0);
  *packetRaw = (((int)packet - (int)packetRaw) + -8) * 0x4000 | 0xc0001000;
  packet[-1] = (int)packet - (int)packetRaw;
  lastHeader = *(uint **)(ctx + GLD_lastHeader);
  *lastHeader = (int)packet - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + GLD_lastHeader) = packet;
  *packet = 0x40000000;
  surfaceObject = *(undefined4 **)surfaceInfo[2];
  surfaceRefPtr = surfaceObject + 4;
  do {
    if (reservation != '\0') {
      storeResult = storeWordConditionalIndexed(*surfaceRefPtr + 0x10000,0,surfaceRefPtr);
      *surfaceRefPtr = storeResult;
      bVar42 = 2;
    }
  } while (!(bool)(bVar42 >> 1 & 1));
  packet[2] = *surfaceObject;
  packet[3] = dstAddress - *(int *)*surfaceInfo;
  readSurfaceCode = gld_textureVariantClass((uint)*(ushort *)(((unsigned char *)0x00002db8) + *(int *)(ctx + GLD_engineState)),
                        *(undefined4 *)(ctx + GLD_renderFlags));
  packet[4] = readSurfaceCode;
  _memcpy(packet + 5,PTR_DAT_001e88d0,0x2f4);
  packet[0x23] = 0;
  packet[0x9f] = 0;
  oldColorFormatWord = packet[0x8f];
  packet[0xa1] =
       width & 0x3ffe | *(uint *)(formatTable + hwFormat * 0x24 + 0x18) >> 0xb & 0x180000 |
       (*(uint *)(formatTable + hwFormat * 0x24 + 0x18) & 0x3c00) << 0xb;
  scratchUint33 = *(uint *)(formatTable + hwFormat * 0x24 + 0x18) >> 5 & 0x1f;
  packet[0x8f] = scratchUint33 | oldColorFormatWord & 0xffffffe0;
  scratchUint29 = (*(uint *)(formatTable + hwFormat * 0x24 + 0x18) & 0x18) << 5;
  packet[0x8f] = scratchUint29 | scratchUint33 | oldColorFormatWord & 0xfffffce0;
  scratchUint38 = (*(uint *)(formatTable + hwFormat * 0x24 + 0x18) & 6) << 9;
  packet[0x8f] = scratchUint38 | scratchUint29 | scratchUint33 | oldColorFormatWord & 0xfffff0e0;
  scratchUint27 = *(uint *)(formatTable + hwFormat * 0x24 + 0x1c) >> 0x12 & 0x3000;
  packet[0x8f] = scratchUint27 | scratchUint38 | scratchUint29 | scratchUint33 | oldColorFormatWord & 0xffffc0e0;
  packet[0x8f] =
       *(uint *)(formatTable + hwFormat * 0x24 + 0x1c) >> 0xe & 0xc000 |
       scratchUint27 | scratchUint38 | scratchUint29 | scratchUint33 | oldColorFormatWord & 0xffff00e0;
  if ((*(uint *)(formatTable + hwFormat * 0x24 + 0x14) & 0xfc000000) == 0) {
    packet[0x5b] = packet[0x5b] & 0xfffe3fff | 0x18000;
  }
  heightI2dLo2 = height ^ 0x80000000;
  packet[0xb8] = clampedWidth - 1 & 0x1fff | (clampedHeight - 1) * 0x2000 & 0x3ffe000;
  i2dMagic = DOUBLE_001aa1e0;
  scratchFloat4 = FLOAT_001aa12c;
  scratchFloat12 = FLOAT_001aa10c;
  heightI2dHi2 = 0x43300000;
  packetEnd = packet + 0xce;
  renderWidthOrInverse = FLOAT_001aa0e8 / renderWidthOrInverse;
  scratchFloat2 = FLOAT_001aa0e8 / renderHeightOrInverse;
  packet[0xc2] = 0x31080;
  packet[199] = ((unsigned char *)0x00001087U);
  scratchFloat7 = (float)((double)CONCAT44(0x43300000,heightI2dLo2) - i2dMagic);
  packet[0xc5] = quadRight * renderWidthOrInverse;
  packet[0xc3] = quadLeft * renderWidthOrInverse;
  packet[0xc6] = scratchFloat2 * (renderHeightOrInverse - scratchFloat14);
  scratchFloat3 = scratchFloat7 - scratchFloat3;
  packet[0xc4] = scratchFloat2 * (renderHeightOrInverse - scratchFloat18);
  scratchFloat7 = scratchFloat7 - scratchFloat11;
  hwFormat = (int)((scratchFloat8 - scratchFloat9) * scratchFloat4);
  fctiwzScratch0 = (longlong)hwFormat;
  scratchUint33 = (uint)(int)((scratchFloat3 - scratchFloat7) * scratchFloat4);
  fctiwzScratch1 = (longlong)(int)scratchUint33;
  packet[0xc9] = 0xc0033500;
  packet[0xca] = 0x10031;
  packet[0xcb] = (scratchFloat9 + scratchFloat8) * scratchFloat12;
  packet[0xcc] = (scratchFloat7 + scratchFloat3) * scratchFloat12;
  packet[0xcd] = 0;
  packet[200] = hwFormat << 0x10 | scratchUint33;
  packet[1] = (int)packetEnd - (int)packetRaw >> 2;
  lastHeader = *(uint **)(ctx + GLD_lastHeader);
  *lastHeader = (int)packetEnd - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + GLD_lastHeader) = packetEnd;
  packet[0xce] = 0x33000000;
  packet[0xcf] = 0;
  packet[0xd1] = 10;
  packet[0xd0] = ((unsigned char *)0x00001393U);
  packet[0xd2] = ((unsigned char *)0x000013c6U);
  packet[0xd3] = 3;
  packet[0xd4] = 0x5c8;
  packet[0xd5] = 0x20000;
  packet[0xd6] = ((unsigned char *)0x000010eaU);
  sc_edgerule = *(undefined4 *)(ctx + GLD_sc_edgerule);
  packet[0xd8] = ((unsigned char *)0x000010faU);
  packet[0xd7] = sc_edgerule;
  sc_screendoor = *(undefined4 *)(ctx + GLD_sc_screendoor);
  packet[0xda] = 0xc0001000;
  packet[0xdc] = 0x11004;
  packet[0xd9] = sc_screendoor;
  packet[0xdd] = *(undefined4 *)(ctx + GLD_gb_mspos0);
  gb_mspos1 = *(undefined4 *)(ctx + GLD_gb_mspos1);
  packet[0xdf] = ((unsigned char *)0x00001008U);
  packet[0xde] = gb_mspos1;
  gb_aa_config = *(undefined4 *)(ctx + GLD_gb_aa_config);
  packet[0xe1] = ((unsigned char *)0x000010e9U);
  packet[0xe0] = gb_aa_config;
  sc_hyperz_en = *(undefined4 *)(ctx + GLD_sc_hyperz_en);
  packet[0xe3] = ((unsigned char *)0x000013c7U);
  packet[0xe2] = sc_hyperz_en;
  zb_bw_cntl = *(undefined4 *)(ctx + GLD_zb_bw_cntl);
  packet[0xe5] = ((unsigned char *)0x000013c1U);
  packet[0xe4] = zb_bw_cntl;
  zb_zstencilcntl = *(undefined4 *)(ctx + GLD_zb_zstencilcntl);
  packet[0xe7] = 0x850;
  packet[0xe6] = zb_zstencilcntl;
  vap_cntl_status = *(undefined4 *)(ctx + GLD_vap_cntl_status);
  packet[0xe9] = 0x887;
  packet[0xe8] = vap_cntl_status;
  vap_clip_cntl = *(undefined4 *)(ctx + GLD_vap_clip_cntl);
  packet[0x18b] = 0x82c;
  packet[0xea] = vap_clip_cntl;
  scratchUint34 = *(undefined4 *)(GLD_vap_vte_cntl + ctx);
  packet[0xeb] = ((unsigned char *)0x000010aeU);
  packet[0x18c] = scratchUint34;
  su_cull_mode = *(undefined4 *)(ctx + GLD_su_cull_mode);
  packet[0xed] = ((unsigned char *)0x00001394U);
  packet[0xec] = su_cull_mode;
  rb3d_dither_ctl = *(undefined4 *)(ctx + GLD_rb3d_dither_ctl);
  packet[0xef] = ((unsigned char *)0x00001380U);
  packet[0xf1] = ((unsigned char *)0x00001002U);
  packet[0xf0] = 0;
  packet[0xee] = rb3d_dither_ctl;
  packet[0xf2] = *(undefined4 *)(ctx + GLD_gb_enable);
  gb_enable = *(undefined4 *)(ctx + GLD_gb_enable);
  packet[0xf3] = 0x824;
  packet[0xf2] = gb_enable;
  vap_out_vtx_fmt_0 = *(undefined4 *)(ctx + GLD_vap_out_vtx_fmt_0);
  packet[0xf5] = 0x825;
  packet[0xf4] = vap_out_vtx_fmt_0;
  vap_out_vtx_fmt_1 = *(undefined4 *)(ctx + GLD_vap_out_vtx_fmt_1);
  packet[0xf7] = 0x82d;
  packet[0xf6] = vap_out_vtx_fmt_1;
  scratchUint34 = *(undefined4 *)(0x000026c8 + ctx + GLD_connect);
  packet[0xf9] = 0x854;
  packet[0xf8] = scratchUint34;
  vap_prog_stream_cntl_0_ptr = **(undefined4 **)(ctx + GLD_vap_prog_stream_cntl_0_ptr);
  packet[0xfb] = 0x878;
  packet[0xfa] = vap_prog_stream_cntl_0_ptr;
  vap_prog_stream_cntl_ext_0_ptr = **(undefined4 **)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr);
  packet[0xfd] = ((unsigned char *)0x000013c0U);
  packet[0xfc] = vap_prog_stream_cntl_ext_0_ptr;
  zb_cntl = *(undefined4 *)(ctx + GLD_zb_cntl);
  packet[0xff] = ((unsigned char *)0x000012f0U);
  formatTable = PTR_DAT_001e88c8;
  packet[0xfe] = zb_cntl;
  fg_fog_blend = *(uint *)(ctx + GLD_fg_fog_blend);
  packet[0x100] = fg_fog_blend;
  if ((*(uint *)(formatTable + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18) & 0x8000) == 0) {
    packet[0x100] = fg_fog_blend & 0xfffffffe;
  }
  packet[0x101] = ((unsigned char *)0x000012f5U);
  fg_alpha_func = *(uint *)(ctx + GLD_fg_alpha_func);
  packet[0x102] = fg_alpha_func;
  if ((*(uint *)(formatTable + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18) & 0x8000) == 0) {
    packet[0x102] = fg_alpha_func & 0xfffff7ff;
  }
  packet[0x103] = ((unsigned char *)0x000010a2U);
  ga_poly_mode = *(undefined4 *)(ctx + GLD_ga_poly_mode);
  packet[0x105] = ((unsigned char *)0x00001381U);
  packet[0x104] = ga_poly_mode;
  scratchUint33 = *(uint *)(ctx + GLD_rb3d_blendcntl);
  packet[0x106] = scratchUint33;
  if ((*(uint *)(formatTable + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18) & 0x4000) == 0) {
    packet[0x106] = scratchUint33 & 0xfffffffc;
  }
  packet[0x107] = ((unsigned char *)0x0000109eU);
  packetHeaderC0221000 = 0xc0221000;
  packetConstAaaa = 0xaaaa;
  packetConst110f8 = 0x110f8;
  unitIndex = 0;
  unitOffset = 0;
  scratchUint34 = *(undefined4 *)(ctx + 0x1d6c);
  packet[0x109] = ((unsigned char *)0x00001096U);
  packet[0x108] = scratchUint34;
  ga_color_control = *(undefined4 *)(ctx + GLD_ga_color_control);
  packet[0x10b] = ((unsigned char *)0x00001041U);
  packet[0x108] = ga_color_control;
  tx_enable = *(undefined4 *)(ctx + GLD_tx_enable);
  packet[0x10d] = ((unsigned char *)0x00001046U);
  packet[0x10c] = tx_enable;
  gb_ps3_enable = *(undefined4 *)(ctx + GLD_gb_ps3_enable);
  packet[0x10f] = ((unsigned char *)0x00001094U);
  packet[0x127] = ((unsigned char *)0x00001095U);
  packet[0x111] = ((unsigned char *)0x00001095U);
  packet[0x14d] = ((unsigned char *)0x00001180U);
  packet[0x113] = ((unsigned char *)0x00001095U);
  packet[0x115] = ((unsigned char *)0x00001095U);
  packet[0x117] = ((unsigned char *)0x00001095U);
  packet[0x10e] = gb_ps3_enable;
  packet[0x119] = ((unsigned char *)0x00001095U);
  packet[0x11b] = ((unsigned char *)0x00001095U);
  packet[0x11d] = ((unsigned char *)0x00001095U);
  packet[0x11f] = ((unsigned char *)0x00001095U);
  packet[0x121] = ((unsigned char *)0x00001095U);
  packet[0x123] = ((unsigned char *)0x00001095U);
  packet[0x125] = ((unsigned char *)0x00001095U);
  packet[0x129] = 0xc0221000;
  packet[0x110] = 0;
  packet[0x14e] = 2;
  packet[0x14f] = ((unsigned char *)0x00001189U);
  packet[0x151] = ((unsigned char *)0x00001181U);
  packet[0x153] = ((unsigned char *)0x0000118dU);
  packet[0x155] = ((unsigned char *)0x0000118eU);
  packet[0x157] = ((unsigned char *)0x0000118cU);
  packet[0x159] = ((unsigned char *)0x000011a9U);
  us_out_fmt_0 = *(undefined4 *)(ctx + GLD_us_out_fmt_0);
  packet[0x15b] = ((unsigned char *)0x000011aaU);
  packet[0x15a] = us_out_fmt_0;
  us_out_fmt_1 = *(undefined4 *)(ctx + GLD_us_out_fmt_1);
  packet[0x15d] = ((unsigned char *)0x000011abU);
  packet[0x15c] = us_out_fmt_1;
  us_out_fmt_2 = *(undefined4 *)(ctx + GLD_us_out_fmt_2);
  packet[0x15f] = ((unsigned char *)0x000011acU);
  packet[0x15e] = us_out_fmt_2;
  us_out_fmt_3 = *(undefined4 *)(ctx + GLD_us_out_fmt_3);
  packet[0x161] = ((unsigned char *)0x000010c0U);
  packet[0x160] = us_out_fmt_3;
  rs_count = *(undefined4 *)(ctx + GLD_rs_count);
  packet[0x163] = ((unsigned char *)0x000010c1U);
  packet[0x165] = ((unsigned char *)0x000010c8U);
  packet[0x167] = ((unsigned char *)0x0000101dU);
  packet[0x162] = rs_count;
  rs_ip_0 = *(undefined4 *)(ctx + GLD_rs_ip_0);
  packet[0x169] = ((unsigned char *)0x0000138aU);
  packet[0x16b] = ((unsigned char *)0x0000138eU);
  packet[0x170] = 0;
  packet[0x16d] = ((unsigned char *)0x00001040U);
  packet[0x16a] = 0;
  packet[0x16c] = 0;
  packet[0x16e] = 0;
  packet[0x168] = rs_ip_0;
  packet[0x16f] = ((unsigned char *)0x00001150U);
  packet[0x171] = ((unsigned char *)0x00001100U);
  tx_filter0 = *(undefined4 *)(ctx + GLD_tx_filter0);
  packet[0x173] = ((unsigned char *)0x00001110U);
  packet[0x172] = tx_filter0;
  packet[0x174] = *(undefined4 *)(ctx + GLD_tx_filter1);
  packet[0x175] = ((unsigned char *)0x00001120U);
  tx_format0 = *(undefined4 *)(ctx + GLD_tx_format0);
  packet[0x177] = ((unsigned char *)0x00001130U);
  packet[0x176] = tx_format0;
  tx_format1 = *(undefined4 *)(ctx + GLD_tx_format1);
  packet[0x179] = ((unsigned char *)0x00001140U);
  packet[0x178] = tx_format1;
  tx_format2 = *(undefined4 *)(ctx + GLD_tx_format2);
  packet[0x17b] = ((unsigned char *)0x000010f4U);
  packet[0x17c] = 0xaaaa;
  packet[0x17d] = ((unsigned char *)0x00001383U);
  packet[0x17a] = tx_format2;
  rb3d_color_channel_mask = *(undefined4 *)(ctx + GLD_rb3d_color_channel_mask);
  packet[0x17f] = ((unsigned char *)0x00001386U);
  packet[0x17e] = rb3d_color_channel_mask;
  rb3d_ropcntl = *(undefined4 *)(ctx + GLD_rb3d_ropcntl);
  packet[0x181] = 0x110f8;
  packet[0x180] = rb3d_ropcntl;
  packet[0x182] = *(undefined4 *)(ctx + GLD_sc_scissor0);
  sc_scissor1 = *(undefined4 *)(ctx + GLD_sc_scissor1);
  packet[0x184] = ((unsigned char *)0x00001087U);
  packet[0x183] = sc_scissor1;
  ga_point_size = *(undefined4 *)(ctx + GLD_ga_point_size);
  packet[0x186] = 0x31080;
  packet[0x185] = ga_point_size;
  packet[0x187] = *(undefined4 *)(ctx + GLD_ga_point_s0);
  packet[0x188] = *(undefined4 *)(ctx + GLD_ga_point_t0);
  packet[0x189] = *(undefined4 *)(ctx + GLD_ga_point_s1);
  packet[0x18a] = *(undefined4 *)(ctx + GLD_ga_point_t1);
  gldCopyProgramStreamState(packet + 0xd0,ring);
  packet = packet + 0x18d;
  hwFormat = ctx;
  do {
    unitObject = *(int *)(hwFormat + 0x18c);
    if (unitObject != 0) {
      targetsLeft = 5;
      targetSlot = (int *)(unitOffset + *(int *)(ctx + GLD_engineObjects));
      do {
        if (unitObject == *targetSlot) {
          if (*(int *)(unitObject + 0x34) != 0) goto checkUnitIndex;
          break;
        }
        targetSlot = targetSlot + 1;
        targetsLeft = targetsLeft + -1;
      } while (targetsLeft != 0);
      unitObject = 0;
    }
checkUnitIndex:
    if ((unitIndex == 0) || (unitObject != 0)) {
      packet = (undefined4 *)((int (*)())gld_emitUnitObjectPacket)(ctx,unitObject,unitIndex,packet);
    }
    lastUnit = unitIndex == 0xf;
    unitOffset = unitOffset + 0x14;
    hwFormat = hwFormat + 4;
    unitIndex = unitIndex + 1;
    if (lastUnit) {
      *(undefined4 **)(ctx + GLD_streamCurrent) = packet;
      (**(code **)(ctx + GLD_streamSetCurrent))(ring,packet);
      _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
      if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
        gld_submitRing(ctx,0x1000000);
      }
      if (*(int *)*surfaceInfo != 0) {
        gldFlushDataCacheRangeSync(ctx,*(int *)*surfaceInfo,clampedHeight * rowBytes,packet,packetConst110f8,packetConstAaaa,surfaceInfo,
                     packetHeaderC0221000);
        return 1;
      }
      return 1;
    }
  } while( true );
}

/* glReadPixels_entry @ 0x29290 (4 bytes) */
int glReadPixels_entry(ctx, rectX, rectY, width, height, format, pixelType, pixels, transferMode, surfaceInfo)
  int ctx;
  int rectX;
  int rectY;
  int width;
  int height;
  int format;
  int pixelType;
  int pixels;
  uint transferMode;
  int surfaceInfo;
{
  undefined *packState;
  int *attachObject;
  bool directCopy;
  undefined4 fallbackResult;
  void *levelBuffer;
  int prepareResult;
  int yOffsetBytes0;
  int attachZOffset;
  int attachFace;
  int bytesPerPixel2;
  int attachLevel;
  int commandStream;
  int yOffsetBytes;
  int bytesPerPixel;
  int levelRecord;
  int attachmentIndex;
  int status;
  int readSurfaceCode;
  uint surfaceFormat;
  uint scratchBytes;
  uint renderFlags;
  int renderHeight;
  int renderWidth;
  int engineState;
  int engineObjects;
  bool convertPixels;
  byte formatIndex;
  ushort sliceCount;
  bool sendAttachments;
  undefined *packStateArg;
  int scratchInt6;
  int scratchInt7;
  undefined4 result;
  void *scratchBuffer;
  undefined4 *ropPacket;
  undefined1 *convertOutAPtr;
  undefined1 *convertOutBPtr;
  uint *layoutRowBytesPtr;
  int scratchInt14;
  uint surfaceType;
  int scratchInt16;
  int scratchInt17;
  uint transferMode8;
  int *boundFramebuffer;
  int *scratchPtr20;
  uint layoutRowBytes;
  int layoutPixelBytes;
  int layoutSkipBytes [3];
  int requestY;
  int requestWidth;
  int requestHeight;
  int requestFormat;
  uint requestAddress;
  uint requestPitch;
  uint procPixels;
  uint procPitch;
  uint procChannelFormat;
  uint procChannelSize;
  uint dstAddress;
  uint srcRowBytes;
  undefined1 convertOutA [4];
  undefined1 convertOutB [4];
  undefined4 procMode;
  uint procFlags;
  undefined *procMask;
  int procWidth;
  int procHeight;
  undefined4 procZero88;
  undefined4 procZero84;
  uint scratchStack80;
  uint scratchStack7c;
  uint scratchStack78;
  undefined4 scratchStack74;
  uint scratchStack70;
  uint scratchStack6c;
  uint scratchStack68;
  undefined4 scratchStack64;
  uint scratchStack60;
  uint scratchStack5c;
  uint scratchStack58;
  undefined4 scratchStack54;
  undefined1 procEnd;
  
  commandStream = ctx + GLD_commandStream;
  procZero84 = 0;
  layoutSkipBytes[1] = 0;
  procZero88 = 0;
  transferMode8 = transferMode & 0xff;
  engineState = *(int *)(ctx + GLD_engineState);
  readSurfaceCode = gld_textureVariantClass((uint)*(ushort *)(((unsigned char *)0x00002db8) + engineState),*(undefined4 *)(ctx + GLD_renderFlags));
  if (((((*(uint *)(((unsigned char *)0x000030b0) + engineState) & 0x1ff) == 0) &&
       ((*(uint *)(((unsigned char *)0x000030b4) + engineState) & 0xff0000) == 0)) || (format - 0x1901U < 2)) ||
     (transferMode8 == 2)) {
    scratchInt6 = 0;
    sendAttachments = false;
  }
  else if ((*(uint *)(((unsigned char *)0x000030b0) + engineState) & 2) == 0) {
    if (((*(uint *)(((unsigned char *)0x000030b0) + engineState) & 4) == 0) ||
       (*(short *)(((unsigned char *)0x00002fe8) + engineState) != -0x7fea)) goto setScratchInt6;
    sendAttachments = true;
    scratchInt6 = *(int *)(((unsigned char *)0x00002ff0) + engineState) + -1;
  }
  else if (*(short *)(((unsigned char *)0x00002fa8) + engineState) == -0x7fea) {
    sendAttachments = true;
    scratchInt6 = *(int *)(((unsigned char *)0x00002fb0) + engineState) + -1;
  }
  else {
setScratchInt6:
    scratchInt6 = 0;
    sendAttachments = true;
  }
  if (surfaceInfo == 0) {
    convertPixels = transferMode8 != 2;
    if (convertPixels) {
      packStateArg = ((unsigned char *)0x00002e50) + engineState;
    }
    else {
      packStateArg = (undefined *)0x0;
    }
    layoutRowBytesPtr = &layoutRowBytes;
    scratchPtr20 = &layoutPixelBytes;
    scratchInt17 = height;
    gld_computePixelStoreLayout(ctx,format,pixelType,width - scratchInt6,height,layoutRowBytesPtr,scratchPtr20,layoutSkipBytes,packStateArg);
    dstAddress = pixels + layoutSkipBytes[0];
    if (rectY < 0) {
      height = height + rectY;
      yOffsetBytes0 = rectY * layoutRowBytes;
      rectY = 0;
      dstAddress = dstAddress - yOffsetBytes0;
    }
    if (rectX < 0) {
      width = width + rectX;
      layoutPixelBytes = rectX * layoutPixelBytes;
      rectX = 0;
      dstAddress = dstAddress - layoutPixelBytes;
    }
    if (*(int *)(ctx + GLD_renderHeight) < rectY + height) {
      height = *(int *)(ctx + GLD_renderHeight) - rectY;
    }
    if (*(int *)(ctx + GLD_renderWidth) < rectX + width) {
      width = *(int *)(ctx + GLD_renderWidth) - rectX;
    }
    if ((0 < width) && (0 < height)) {
      if (convertPixels) {
        if (transferMode8 == 0) {
          procFlags = 0x20000;
        }
        else {
          procFlags = 0;
        }
        packState = ((unsigned char *)0x00002e48) + engineState;
        procMask = ((unsigned char *)0x0007efff);
        if (((unsigned char *)0x00002e68)[engineState] != '\0') {
          procFlags = procFlags | 2;
        }
        if (((unsigned char *)0x00002e69)[engineState] != '\0') {
          procFlags = procFlags | 8;
        }
      }
      else {
        packState = (undefined *)0x0;
        procMask = (undefined *)0x0;
        procFlags = 0;
      }
      procEnd = 0;
      procMode = 2;
      convertOutAPtr = convertOutA;
      convertOutBPtr = convertOutB;
      srcRowBytes = layoutRowBytes;
      procWidth = width;
      procHeight = height;
      _glgConvertType(format,pixelType,convertOutAPtr,convertOutBPtr);
      boundFramebuffer = *(int **)(ctx + GLD_boundFramebuffer);
      if (boundFramebuffer == (int *)0x0) {
        layoutSkipBytes[2] = rectX;
        requestY = rectY;
        requestWidth = width;
        requestHeight = height;
        if (format == 0x1901) {
          renderFlags = *(uint *)(ctx + GLD_renderFlags);
          if ((renderFlags & 0x30000) == 0x30000) {
            if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
              gld_submitRing(ctx,0x1000000);
              renderFlags = *(uint *)(ctx + GLD_renderFlags);
            }
            procPitch = (width + 0xf) * 4 & 0xffffffc0;
            procChannelSize = 0x14;
            procChannelFormat = 0xf;
            if ((renderFlags & 0x2000) == 0) {
loopSetRequestFormat:
              requestFormat = 4;
            }
            else {
loopCheckReadSurfaceCode:
              if (readSurfaceCode == 7) {
                requestFormat = 10;
              }
              else {
                if (readSurfaceCode != 8) goto loopSetRequestFormat;
                requestFormat = 0xb;
              }
            }
loopCheckSendAttachments:
            if ((sendAttachments) ||
               ((((convertPixels && (((*(uint *)(((unsigned char *)0x000030b4) + engineState) & 0xff1) != 0 ||
                             ((*(uint *)(((unsigned char *)0x00002e68U) + engineState) & 0xffff0000) != 0)))) ||
                 (format - 0x1901U < 2)) ||
                ((((srcRowBytes & 0x3f) != 0 || (0x1fff < (int)srcRowBytes)) ||
                 ((dstAddress & 0x1f) != 0)))))) {
loopSetRequestPitch:
              requestPitch = procPitch;
              scratchBytes = height * procPitch + 0xfff & 0xfffff000;
              if (*(uint *)(((unsigned char *)GLD_readScratchSize) + ctx) < scratchBytes) {
                if (*(int *)(((unsigned char *)GLD_readScratchBuffer) + ctx) != 0) {
                  _vfree(*(int *)(((unsigned char *)GLD_readScratchBuffer) + ctx));
                }
                scratchBuffer = _valloc(scratchBytes);
                *(uint *)(((unsigned char *)GLD_readScratchSize) + ctx) = scratchBytes;
                *(void **)(((unsigned char *)GLD_readScratchBuffer) + ctx) = scratchBuffer;
              }
              requestAddress = *(uint *)(((unsigned char *)GLD_readScratchBuffer) + ctx);
              if (requestAddress == 0) goto setResult;
              directCopy = false;
            }
            else {
              if ((renderFlags & 0xf) == 4) {
                if ((format != 0x80e1) || (pixelType != 0x8367)) goto loopSetRequestPitch;
              }
              else if ((((renderFlags & 0xf) != 3) || (format != 0x80e1)) || (pixelType != 0x8366))
              goto loopSetRequestPitch;
              directCopy = true;
              requestPitch = srcRowBytes;
              requestAddress = dstAddress;
            }
            procPixels = requestAddress;
            if (sendAttachments) {
              engineObjects = *(int *)(ctx + GLD_engineObjects);
              scratchInt7 = *(int *)(*(int *)(engineObjects + 0x140) + 0x30);
              scratchStack80 = (uint)*(ushort *)(scratchInt7 + 0x98);
              scratchStack7c = (uint)*(ushort *)(scratchInt7 + 0x9a);
              scratchStack78 = (uint)*(ushort *)(scratchInt7 + 0x8c);
              scratchStack74 = *(undefined4 *)(scratchInt7 + 0x9c);
              scratchInt7 = *(int *)(*(int *)(engineObjects + 0x148) + 0x30);
              scratchStack70 = (uint)*(ushort *)(scratchInt7 + 0x98);
              scratchStack6c = (uint)*(ushort *)(scratchInt7 + 0x9a);
              scratchStack68 = (uint)*(ushort *)(scratchInt7 + 0x8c);
              scratchStack64 = *(undefined4 *)(scratchInt7 + 0x9c);
              scratchInt7 = *(int *)(*(int *)(engineObjects + 0x144) + 0x30);
              scratchStack60 = (uint)*(ushort *)(scratchInt7 + 0x98);
              scratchStack5c = (uint)*(ushort *)(scratchInt7 + 0x9a);
              scratchStack58 = (uint)*(ushort *)(scratchInt7 + 0x8c);
              scratchStack54 = *(undefined4 *)(scratchInt7 + 0x9c);
            }
            status = _io_connect_method_structureI_structureO
                              (*(undefined4 *)(ctx + GLD_connect),7,layoutSkipBytes + 2,0x1c,0,layoutSkipBytes + 1);
            if (status != 0) goto setResult;
            if (!directCopy) {
              _glgProcessPixels(packState,&procPixels);
              return 1;
            }
          }
        }
        else {
          if (format != 0x1902) {
            prepareResult = gld_needsMultisampleResolve(ctx,readSurfaceCode,convertOutAPtr,convertOutBPtr,scratchInt17,layoutRowBytesPtr,scratchPtr20);
            if (prepareResult != 0) {
              gld_emitSurfaceCopyPacket(ctx,0,readSurfaceCode,0,0,0,*(undefined4 *)(ctx + GLD_renderWidth),
                           *(undefined4 *)(ctx + GLD_renderHeight));
            }
            if (*(int *)(ctx + GLD_rb3d_ropcntl) != 0) {
              ropPacket = (undefined4 *)(**(code **)(ctx + GLD_streamAllocate))(commandStream,2);
              ropPacket[1] = 0;
              *ropPacket = ((unsigned char *)0x00001386);
              *(undefined4 **)(ctx + GLD_streamCurrent) = ropPacket + 2;
              (**(code **)(ctx + GLD_streamSetCurrent))(commandStream,ropPacket + 2);
            }
            if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
              gld_submitRing(ctx,0x1000000);
            }
            if (*(int *)(ctx + GLD_rb3d_ropcntl) != 0) {
              ropPacket = (undefined4 *)(**(code **)(ctx + GLD_streamAllocate))(commandStream,2);
              *ropPacket = ((unsigned char *)0x00001386);
              ropPacket[1] = *(undefined4 *)(ctx + GLD_rb3d_ropcntl);
              *(undefined4 **)(ctx + GLD_streamCurrent) = ropPacket + 2;
              (**(code **)(ctx + GLD_streamSetCurrent))(commandStream,ropPacket + 2);
            }
            formatIndex = ((unsigned char *)GLD_colorFormatIndex)[ctx];
            renderFlags = *(uint *)(ctx + GLD_renderFlags);
            procPitch = (width << (*(uint *)(PTR_DAT_001e88c8 + (uint)formatIndex * 0x24 + 0x14) & 7)) +
                        0x1fU & 0xffffffe0;
            procChannelSize = *(uint *)(PTR_DAT_001e88c8 + (uint)formatIndex * 0x24 + 0x10) >> 0x16 & 0x1f;
            procChannelFormat = *(uint *)(PTR_DAT_001e88c8 + (uint)formatIndex * 0x24 + 0x10) >> 0x1b;
            requestFormat = readSurfaceCode;
            goto loopCheckSendAttachments;
          }
          renderFlags = *(uint *)(ctx + GLD_renderFlags);
          if ((renderFlags & 0x30000) != 0) {
            if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
              gld_submitRing(ctx,0x1000000);
              renderFlags = *(uint *)(ctx + GLD_renderFlags);
            }
            if ((renderFlags & 0x20000) == 0) {
              procChannelSize = 2;
              procPitch = (width + 0x1f) * 2 & 0xffffffc0;
              procChannelFormat = 0xd;
            }
            else {
              procPitch = (width + 0xf) * 4 & 0xffffffc0;
              if ((renderFlags & 0x30000) == 0x30000) {
                procChannelFormat = 0xf;
                procChannelSize = 0x14;
              }
              else {
                procChannelFormat = 0xd;
                procChannelSize = 4;
              }
            }
            if ((renderFlags & 0x2000) != 0) goto loopCheckReadSurfaceCode;
            goto loopSetRequestFormat;
          }
        }
      }
      else {
        attachmentIndex = 5;
        if ((format != 0x1901) && (attachmentIndex = 4, format != 0x1902)) {
          procFlags = procFlags | 0x60000;
          procMask = (undefined *)((uint)procMask | 0x68002);
          attachmentIndex = *(ushort *)(*boundFramebuffer + 0x98) - 0x8ce0;
          if ((convertPixels) &&
             (((*(uint *)(packState + 0x268) & 0x1ff) != 0 ||
              ((*(uint *)(packState + 0x26c) & 0xff0000) != 0)))) {
            scratchInt16 = *(int *)(ctx + GLD_engineObjects);
            scratchInt14 = *(int *)(*(int *)(scratchInt16 + 0x140) + 0x30);
            scratchStack80 = (uint)*(ushort *)(scratchInt14 + 0x98);
            scratchStack7c = (uint)*(ushort *)(scratchInt14 + 0x9a);
            scratchStack78 = (uint)*(ushort *)(scratchInt14 + 0x8c);
            scratchStack74 = *(undefined4 *)(scratchInt14 + 0x9c);
            scratchInt14 = *(int *)(*(int *)(scratchInt16 + 0x148) + 0x30);
            scratchStack70 = (uint)*(ushort *)(scratchInt14 + 0x98);
            scratchStack6c = (uint)*(ushort *)(scratchInt14 + 0x9a);
            scratchStack68 = (uint)*(ushort *)(scratchInt14 + 0x8c);
            scratchStack64 = *(undefined4 *)(scratchInt14 + 0x9c);
            scratchInt14 = *(int *)(*(int *)(scratchInt16 + 0x144) + 0x30);
            scratchStack60 = (uint)*(ushort *)(scratchInt14 + 0x98);
            scratchStack5c = (uint)*(ushort *)(scratchInt14 + 0x9a);
            scratchStack58 = (uint)*(ushort *)(scratchInt14 + 0x8c);
            scratchStack54 = *(undefined4 *)(scratchInt14 + 0x9c);
          }
        }
        attachObject = *(int **)(boundFramebuffer[1] + attachmentIndex * 4);
        if (attachObject != (int *)0x0) {
          attachmentIndex = attachmentIndex * 0x18 + *boundFramebuffer;
          sliceCount = *(ushort *)(*attachObject + 0x18);
          attachFace = *(int *)(attachmentIndex + 4);
          attachLevel = *(int *)(attachmentIndex + 8);
          attachZOffset = *(int *)(attachmentIndex + 0xc);
          levelRecord = attachLevel * 0x18 + attachFace * 0x168 + attachObject[0xc];
          surfaceType = (uint)*(ushort *)(levelRecord + 0xb2);
          surfaceFormat = (uint)*(ushort *)(levelRecord + 0xb0);
          _glgConvertType(surfaceFormat,surfaceType,&procChannelFormat,&procChannelSize);
          renderWidth = *(int *)(ctx + GLD_renderWidth);
          bytesPerPixel = gldPixelUnitBytes(surfaceFormat,surfaceType);
          procPitch = renderWidth * bytesPerPixel;
          renderHeight = procPitch * *(int *)(ctx + GLD_renderHeight);
          levelBuffer = _valloc((uint)sliceCount * renderHeight);
          gld_readbackTextureLevel(ctx,attachObject,attachFace,attachLevel,surfaceFormat,surfaceType,levelBuffer,procPitch);
          yOffsetBytes = rectY * procPitch;
          bytesPerPixel2 = gldPixelUnitBytes(surfaceFormat,surfaceType);
          procPixels = (int)levelBuffer + rectX * bytesPerPixel2 + attachZOffset * renderHeight + yOffsetBytes;
          _glgProcessPixels(packState,&procPixels);
          _vfree(levelBuffer);
          return 1;
        }
      }
    }
    result = 1;
  }
  else {
    if (!sendAttachments) {
      fallbackResult = ((int (*)())gld_readPixelsViaBlit)(ctx,rectX,rectY,width,height,format,pixelType,pixels,transferMode8,
                           surfaceInfo);
      return fallbackResult;
    }
setResult:
    result = 0;
  }
  return result;
}

/* glReadPixels_impl @ 0x29294 (2376 bytes) */
int glReadPixels_impl(ctx, rectX, rectY, width, height, format, pixelType, pixels, transferMode, surfaceInfo)
  int ctx;
  int rectX;
  int rectY;
  int width;
  int height;
  int format;
  int pixelType;
  int pixels;
  uint transferMode;
  int surfaceInfo;
{
  undefined4 fallbackResult;
  undefined4 result;
  undefined4 requestBytes;
  uint scratchBytes;
  uint dstOffsetAddress;
  undefined *packState;
  int *attachObject;
  int *requestPtr;
  int bytesPerPixel;
  int levelBuffer;
  int prepareResult;
  int yOffsetBytes0;
  bool directCopy;
  int *boundFramebuffer;
  bool convertPixels;
  byte formatIndex;
  ushort sliceCount;
  bool sendAttachments;
  undefined *packStateArg;
  int scratchInt6;
  dword *readSurfaceCode;
  undefined4 scratchBuffer;
  int savedHeight;
  undefined4 *ropPacket;
  dword *convertOutAPtr;
  undefined1 *convertOutBPtr;
  undefined4 staleArgR10;
  uint *layoutRowBytesPtr;
  undefined4 *ropPacketEnd;
  uint scratchUint12;
  uint scratchUint13;
  int attachLevel;
  int attachFace;
  int ring;
  uint surfaceFormat;
  uint surfaceType;
  int renderHeight;
  int ctxState;
  int attachZOffset;
  uint flags;
  int *replySizePtr;
  int *layoutPixelBytesPtr;
  uint layoutRowBytes;
  int layoutPixelBytes;
  int layoutSkipBytes [3];
  int requestY;
  int requestWidth;
  int requestHeight;
  dword *requestSurfaceCode;
  uint requestAddress;
  uint requestPitch;
  uint procSrcAddress;
  uint procPitch;
  uint targetFormatA;
  uint targetFormatB;
  uint dstAddress;
  uint srcRowBytes;
  dword convertOutA;
  undefined1 convertOutB [4];
  undefined4 procMode;
  uint procFlags;
  undefined *procMask;
  int procWidth;
  int procHeight;
  undefined4 procZero88;
  undefined4 procZero84;
  uint scratchStack80;
  uint scratchStack7c;
  uint scratchStack78;
  undefined4 scratchStack74;
  uint scratchStack70;
  uint scratchStack6c;
  uint scratchStack68;
  undefined4 scratchStack64;
  uint scratchStack60;
  uint scratchStack5c;
  uint scratchStack58;
  undefined4 scratchStack54;
  undefined1 procEnd;
  
  ring = ctx + GLD_commandStream;
  procZero84 = 0;
  layoutSkipBytes[1] = 0;
  procZero88 = 0;
  flags = transferMode & 0xff;
  ctxState = *(int *)(ctx + GLD_engineState);
  readSurfaceCode = (dword *)gld_textureVariantClass((uint)*(ushort *)(((unsigned char *)0x00002db8) + ctxState),
                                 *(undefined4 *)(ctx + GLD_renderFlags));
  if (((((*(uint *)(((unsigned char *)0x000030b0) + ctxState) & 0x1ff) == 0) &&
       ((*(uint *)(((unsigned char *)0x000030b4) + ctxState) & 0xff0000) == 0)) || (format - 0x1901U < 2)) ||
     (flags == 2)) {
    scratchInt6 = 0;
    sendAttachments = false;
  }
  else if ((*(uint *)(((unsigned char *)0x000030b0) + ctxState) & 2) == 0) {
    if (((*(uint *)(((unsigned char *)0x000030b0) + ctxState) & 4) == 0) ||
       (*(short *)(((unsigned char *)0x00002fe8) + ctxState) != -0x7fea)) goto setScratchInt6;
    sendAttachments = true;
    scratchInt6 = *(int *)(((unsigned char *)0x00002ff0) + ctxState) + -1;
  }
  else if (*(short *)(((unsigned char *)0x00002fa8) + ctxState) == -0x7fea) {
    sendAttachments = true;
    scratchInt6 = *(int *)(((unsigned char *)0x00002fb0) + ctxState) + -1;
  }
  else {
setScratchInt6:
    scratchInt6 = 0;
    sendAttachments = true;
  }
  if (surfaceInfo == 0) {
    convertPixels = flags != 2;
    if (convertPixels) {
      packStateArg = ((unsigned char *)0x00002e50) + ctxState;
    }
    else {
      packStateArg = (undefined *)0x0;
    }
    layoutRowBytesPtr = &layoutRowBytes;
    layoutPixelBytesPtr = &layoutPixelBytes;
    savedHeight = height;
    gld_computePixelStoreLayout(ctx,format,pixelType,width - scratchInt6,height,layoutRowBytesPtr,layoutPixelBytesPtr,layoutSkipBytes,packStateArg);
    dstOffsetAddress = pixels + layoutSkipBytes[0];
    if (rectY < 0) {
      height = height + rectY;
      yOffsetBytes0 = rectY * layoutRowBytes;
      rectY = 0;
      dstOffsetAddress = dstOffsetAddress - yOffsetBytes0;
    }
    if (rectX < 0) {
      width = width + rectX;
      layoutPixelBytes = rectX * layoutPixelBytes;
      rectX = 0;
      dstOffsetAddress = dstOffsetAddress - layoutPixelBytes;
    }
    if (*(int *)(ctx + GLD_renderHeight) < rectY + height) {
      height = *(int *)(ctx + GLD_renderHeight) - rectY;
    }
    if (*(int *)(ctx + GLD_renderWidth) < rectX + width) {
      width = *(int *)(ctx + GLD_renderWidth) - rectX;
    }
    if ((0 < width) && (0 < height)) {
      if (convertPixels) {
        if (flags == 0) {
          procFlags = 0x20000;
        }
        else {
          procFlags = 0;
        }
        packState = ((unsigned char *)0x00002e48) + ctxState;
        procMask = ((unsigned char *)0x0007efffU);
        if (((unsigned char *)0x00002e68)[ctxState] != '\0') {
          procFlags = procFlags | 2;
        }
        if (((unsigned char *)0x00002e69)[ctxState] != '\0') {
          procFlags = procFlags | 8;
        }
      }
      else {
        packState = (undefined *)0x0;
        procMask = (undefined *)0x0;
        procFlags = 0;
      }
      procEnd = 0;
      procMode = 2;
      convertOutAPtr = &convertOutA;
      convertOutBPtr = convertOutB;
      srcRowBytes = layoutRowBytes;
      dstAddress = dstOffsetAddress;
      procWidth = width;
      procHeight = height;
      _glgConvertType(format,pixelType,convertOutAPtr,convertOutBPtr,savedHeight,layoutRowBytesPtr,layoutPixelBytesPtr,dstOffsetAddress);
      boundFramebuffer = *(int **)(ctx + GLD_boundFramebuffer);
      if (boundFramebuffer == (int *)0x0) {
        layoutSkipBytes[2] = rectX;
        requestY = rectY;
        requestWidth = width;
        requestHeight = height;
        if (format == 0x1901) {
          flags = *(uint *)(ctx + GLD_renderFlags);
          if ((flags & 0x30000) == 0x30000) {
            if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
              gld_submitRing(ctx,0x1000000);
              flags = *(uint *)(ctx + GLD_renderFlags);
            }
            procPitch = (width + 0xf) * 4 & 0xffffffc0;
            targetFormatB = 0x14;
            targetFormatA = 0xf;
            if ((flags & 0x2000) == 0) {
loopSetRequestSurfaceCode:
              requestSurfaceCode = ((unsigned char *)0x4);
            }
            else {
loopCheckReadSurfaceCode:
              if (readSurfaceCode == (dword *)((int)((unsigned char *)0x4) + 3)) {
                requestSurfaceCode = (dword *)((int)((unsigned char *)0x8) + 2);
              }
              else {
                if (readSurfaceCode != ((unsigned char *)0x8)) goto loopSetRequestSurfaceCode;
                requestSurfaceCode = (dword *)((int)((unsigned char *)0x8) + 3);
              }
            }
loopSetScratchUint12:
            scratchUint12 = flags & 0xf;
            if ((sendAttachments) ||
               ((((convertPixels && (((*(uint *)(((unsigned char *)0x000030b4) + ctxState) & 0xff1) != 0 ||
                             ((*(uint *)(((unsigned char *)0x00002e68U) + ctxState) & 0xffff0000) != 0)))) ||
                 (format - 0x1901U < 2)) ||
                ((((srcRowBytes & 0x3f) != 0 || (0x1fff < (int)srcRowBytes)) ||
                 ((dstAddress & 0x1f) != 0)))))) {
loopSetScratchUint122:
              scratchUint12 = *(uint *)(((unsigned char *)GLD_readScratchSize) + ctx);
              requestPitch = procPitch;
              scratchBytes = height * procPitch + 0xfff & 0xfffff000;
              if (scratchUint12 < scratchBytes) {
                if (*(int *)(((unsigned char *)GLD_readScratchBuffer) + ctx) != 0) {
                  _vfree(*(int *)(((unsigned char *)GLD_readScratchBuffer) + ctx));
                }
                scratchBuffer = _valloc(scratchBytes);
                *(uint *)(((unsigned char *)GLD_readScratchSize) + ctx) = scratchBytes;
                *(undefined4 *)(((unsigned char *)GLD_readScratchBuffer) + ctx) = scratchBuffer;
              }
              requestAddress = *(uint *)(((unsigned char *)GLD_readScratchBuffer) + ctx);
              if (requestAddress == 0) goto setResult;
              directCopy = false;
            }
            else {
              if (scratchUint12 == 4) {
                if ((format != 0x80e1) || (pixelType != 0x8367)) goto loopSetScratchUint122;
              }
              else if (((scratchUint12 != 3) || (format != 0x80e1)) || (pixelType != 0x8366))
              goto loopSetScratchUint122;
              directCopy = true;
              requestPitch = srcRowBytes;
              requestAddress = dstAddress;
            }
            procSrcAddress = requestAddress;
            if (sendAttachments) {
              flags = *(uint *)(ctx + GLD_engineObjects);
              ring = *(int *)(*(int *)(flags + 0x140) + 0x30);
              scratchStack80 = (uint)*(ushort *)(ring + 0x98);
              scratchStack7c = (uint)*(ushort *)(ring + 0x9a);
              scratchStack78 = (uint)*(ushort *)(ring + 0x8c);
              scratchStack74 = *(undefined4 *)(ring + 0x9c);
              ring = *(int *)(*(int *)(flags + 0x148) + 0x30);
              scratchStack70 = (uint)*(ushort *)(ring + 0x98);
              scratchStack6c = (uint)*(ushort *)(ring + 0x9a);
              scratchStack68 = (uint)*(ushort *)(ring + 0x8c);
              scratchStack64 = *(undefined4 *)(ring + 0x9c);
              scratchUint12 = *(uint *)(flags + 0x144);
              ring = *(int *)(scratchUint12 + 0x30);
              scratchStack60 = (uint)*(ushort *)(ring + 0x98);
              scratchStack5c = (uint)*(ushort *)(ring + 0x9a);
              scratchStack58 = (uint)*(ushort *)(ring + 0x8c);
              scratchStack54 = *(undefined4 *)(ring + 0x9c);
            }
            requestPtr = layoutSkipBytes + 2;
            requestBytes = 0x1c;
            staleArgR10 = 0;
            replySizePtr = layoutSkipBytes + 1;
            ring = _io_connect_method_structureI_structureO
                               (*(undefined4 *)(ctx + GLD_connect),7,requestPtr,0x1c,0,replySizePtr);
            if (ring != 0) goto setResult;
            if (!directCopy) {
              _glgProcessPixels(packState,&procSrcAddress,requestPtr,requestBytes,staleArgR10,replySizePtr,scratchUint12,flags);
              return 1;
            }
          }
        }
        else {
          if (format != 0x1902) {
            prepareResult = gld_needsMultisampleResolve(ctx,readSurfaceCode,convertOutAPtr,convertOutBPtr,savedHeight,layoutRowBytesPtr,layoutPixelBytesPtr);
            if (prepareResult != 0) {
              convertOutBPtr = (undefined1 *)0x0;
              savedHeight = 0;
              layoutRowBytesPtr = (uint *)0x0;
              convertOutAPtr = readSurfaceCode;
              gld_emitSurfaceCopyPacket(ctx,0,readSurfaceCode,0,0,0,*(undefined4 *)(ctx + GLD_renderWidth),
                           *(undefined4 *)(ctx + GLD_renderHeight));
            }
            if (*(int *)(ctx + GLD_rb3d_ropcntl) != 0) {
              ropPacket = (undefined4 *)(**(code **)(ctx + GLD_streamAllocate))(ring,2);
              ropPacket[1] = 0;
              *ropPacket = ((unsigned char *)0x00001386U);
              *(undefined4 **)(ctx + GLD_streamCurrent) = ropPacket + 2;
              (**(code **)(ctx + GLD_streamSetCurrent))(ring,ropPacket + 2);
            }
            if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
              gld_submitRing(ctx,0x1000000);
            }
            if (*(int *)(ctx + GLD_rb3d_ropcntl) != 0) {
              ropPacket = (undefined4 *)(**(code **)(ctx + GLD_streamAllocate))(ring,2);
              ropPacketEnd = ropPacket + 2;
              *ropPacket = ((unsigned char *)0x00001386U);
              ropPacket[1] = *(undefined4 *)(ctx + GLD_rb3d_ropcntl);
              *(undefined4 **)(ctx + GLD_streamCurrent) = ropPacketEnd;
              (**(code **)(ctx + GLD_streamSetCurrent))(ring,ropPacketEnd,convertOutAPtr,convertOutBPtr,savedHeight,layoutRowBytesPtr,ropPacketEnd);
            }
            formatIndex = ((unsigned char *)GLD_colorFormatIndex)[ctx];
            flags = *(uint *)(ctx + GLD_renderFlags);
            procPitch = (width << (*(uint *)(PTR_DAT_001e88c8 + (uint)formatIndex * 0x24 + 0x14) & 7)) +
                        0x1fU & 0xffffffe0;
            targetFormatB = *(uint *)(PTR_DAT_001e88c8 + (uint)formatIndex * 0x24 + 0x10) >> 0x16 & 0x1f;
            targetFormatA = *(uint *)(PTR_DAT_001e88c8 + (uint)formatIndex * 0x24 + 0x10) >> 0x1b;
            requestSurfaceCode = readSurfaceCode;
            goto loopSetScratchUint12;
          }
          flags = *(uint *)(ctx + GLD_renderFlags);
          if ((flags & 0x30000) != 0) {
            if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
              gld_submitRing(ctx,0x1000000);
              flags = *(uint *)(ctx + GLD_renderFlags);
            }
            if ((flags & 0x20000) == 0) {
              targetFormatB = 2;
              procPitch = (width + 0x1f) * 2 & 0xffffffc0;
              targetFormatA = 0xd;
            }
            else {
              procPitch = (width + 0xf) * 4 & 0xffffffc0;
              if ((flags & 0x30000) == 0x30000) {
                targetFormatA = 0xf;
                targetFormatB = 0x14;
              }
              else {
                targetFormatA = 0xd;
                targetFormatB = 4;
              }
            }
            if ((flags & 0x2000) != 0) goto loopCheckReadSurfaceCode;
            goto loopSetRequestSurfaceCode;
          }
        }
      }
      else {
        ring = 5;
        if ((format != 0x1901) && (ring = 4, format != 0x1902)) {
          procFlags = procFlags | 0x60000;
          procMask = (undefined *)((uint)procMask | 0x68002);
          ring = *(ushort *)(*boundFramebuffer + 0x98) - 0x8ce0;
          if ((convertPixels) &&
             (((*(uint *)(packState + 0x268) & 0x1ff) != 0 ||
              ((*(uint *)(packState + 0x26c) & 0xff0000) != 0)))) {
            dstOffsetAddress = *(uint *)(ctx + GLD_engineObjects);
            ctxState = *(int *)(*(int *)(dstOffsetAddress + 0x140) + 0x30);
            scratchStack80 = (uint)*(ushort *)(ctxState + 0x98);
            scratchStack7c = (uint)*(ushort *)(ctxState + 0x9a);
            scratchStack78 = (uint)*(ushort *)(ctxState + 0x8c);
            scratchStack74 = *(undefined4 *)(ctxState + 0x9c);
            ctxState = *(int *)(*(int *)(dstOffsetAddress + 0x148) + 0x30);
            scratchStack70 = (uint)*(ushort *)(ctxState + 0x98);
            scratchStack6c = (uint)*(ushort *)(ctxState + 0x9a);
            scratchStack68 = (uint)*(ushort *)(ctxState + 0x8c);
            scratchStack64 = *(undefined4 *)(ctxState + 0x9c);
            ctxState = *(int *)(*(int *)(dstOffsetAddress + 0x144) + 0x30);
            scratchStack60 = (uint)*(ushort *)(ctxState + 0x98);
            scratchStack5c = (uint)*(ushort *)(ctxState + 0x9a);
            scratchStack58 = (uint)*(ushort *)(ctxState + 0x8c);
            scratchStack54 = *(undefined4 *)(ctxState + 0x9c);
          }
        }
        attachObject = *(int **)(boundFramebuffer[1] + ring * 4);
        if (attachObject != (int *)0x0) {
          ctxState = ring * 0x18 + *boundFramebuffer;
          sliceCount = *(ushort *)(*attachObject + 0x18);
          attachFace = *(int *)(ctxState + 4);
          attachLevel = *(int *)(ctxState + 8);
          attachZOffset = *(int *)(ctxState + 0xc);
          ctxState = attachLevel * 0x18 + attachFace * 0x168 + attachObject[0xc];
          surfaceType = (uint)*(ushort *)(ctxState + 0xb2);
          surfaceFormat = (uint)*(ushort *)(ctxState + 0xb0);
          _glgConvertType(surfaceFormat,surfaceType,&targetFormatA,&targetFormatB,savedHeight,ring,*attachObject,dstOffsetAddress);
          ctxState = *(int *)(ctx + GLD_renderWidth);
          ring = gldPixelUnitBytes(surfaceFormat,surfaceType);
          procPitch = ctxState * ring;
          renderHeight = procPitch * *(int *)(ctx + GLD_renderHeight);
          levelBuffer = _valloc((uint)sliceCount * renderHeight);
          flags = surfaceFormat;
          scratchUint12 = surfaceType;
          ring = levelBuffer;
          scratchUint13 = procPitch;
          gld_readbackTextureLevel(ctx,attachObject,attachFace,attachLevel,surfaceFormat,surfaceType,levelBuffer,procPitch);
          ctxState = rectY * procPitch;
          bytesPerPixel = gldPixelUnitBytes(surfaceFormat,surfaceType);
          procSrcAddress = levelBuffer + attachZOffset * renderHeight + ctxState + rectX * bytesPerPixel;
          _glgProcessPixels(packState,&procSrcAddress,attachFace,attachLevel,flags,scratchUint12,ring,scratchUint13);
          _vfree(levelBuffer);
          return 1;
        }
      }
    }
    result = 1;
  }
  else {
    if (!sendAttachments) {
      fallbackResult = ((int (*)())gld_readPixelsViaBlit)(ctx,rectX,rectY,width,height,format,pixelType,pixels,flags,
                           surfaceInfo);
      return fallbackResult;
    }
setResult:
    result = 0;
  }
  return result;
}

/* gld_drawPixelsAsPoints @ 0x29c00 (1624 bytes) */
int gld_drawPixelsAsPoints(ctx, srcPixels, procWidth, procHeight, srcRowBytes, bytesPerPixel, rasterX, rasterY, rasterPosRecord, format, transferMode8)
  int ctx;
  float *srcPixels;
  int procWidth;
  int procHeight;
  float *srcRowBytes;
  int bytesPerPixel;
  uint rasterX;
  uint rasterY;
  int rasterPosRecord;
  int format;
  undefined4 transferMode8;
{
  int loopIndex;
  uint scratchUint1;
  byte alphaByte;
  float stepX;
  float stepY;
  float windowXStart;
  double scratchDouble6;
  double uintBiasD;
  float pixelValueF;
  int scratchInt9;
  undefined4 *packetAlloc;
  undefined4 *packetCursor;
  int scratchInt12;
  undefined4 r4AfterCall;
  float *scratchPtr13;
  float *scratchPtr14;
  float *vertexCursor;
  float *scratchPtr16;
  float *srcCursor;
  float scratchFloat18;
  undefined4 pointSizeWord;
  int scratchInt20;
  int commandStream;
  float colorA;
  float windowX;
  float windowY;
  float depthZ;
  undefined4 oneBits;
  float colorR;
  float colorG;
  float colorB;
  float internalDrawStateSave [36];
  undefined4 pointSizeI2dHi;
  undefined4 pointSizeI2dLo;
  longlong fctiwzSlot0;
  undefined4 rasterYI2dHi;
  float *rasterYI2dLo;
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 pointSizeI2dHi2;
  undefined4 pointSizeI2dLo2;
  longlong fctiwzSlot1;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 alphaI2dHi;
  uint alphaI2dLo;
  undefined4 redI2dHi;
  float *redI2dLo;
  undefined4 greenI2dHi;
  uint greenI2dLo;
  undefined4 blueI2dHi;
  uint blueI2dLo;
  
  commandStream = ctx + 0x240;
  scratchInt20 = procWidth * procHeight;
  pointSizeWord = *(undefined4 *)(ctx + 0x248);
  scratchInt9 = *(int *)(*(int *)(ctx + 0x244) + 0x10);
  stepY = FLOAT_001aa0e8;
  if (*(float *)(((unsigned char *)0x00002e4c) + scratchInt9) < 0.0) {
    stepY = FLOAT_001aa114;
  }
  stepX = FLOAT_001aa0e8;
  if (*(float *)(((unsigned char *)0x00002e48) + scratchInt9) < 0.0) {
    stepX = FLOAT_001aa114;
  }
  if (-*(float *)(((unsigned char *)0x00002e4c) + scratchInt9) < 0.0) {
    stepY = FLOAT_001aa0e8;
  }
  if (-*(float *)(((unsigned char *)0x00002e48) + scratchInt9) < 0.0) {
    stepX = FLOAT_001aa0e8;
  }
  if (format != 0x1901) {
    if ((char)transferMode8 == '\0') {
      scratchPtr13 = internalDrawStateSave;
      scratchInt9 = procHeight;
      scratchPtr14 = srcRowBytes;
      gld_resetRasterStateForInternalDraw(commandStream,(*(uint *)(ctx + 0x1cf8) ^ 1) & 1 | (uint)(format == 0x1902) << 0xc,
                   scratchPtr13);
      gldClearBoundSlot(commandStream,*(uint *)(ctx + 0x1ae4) >> 6 & 0xffff);
      *(uint *)(ctx + 0x216c) = *(uint *)(ctx + 0x216c) & 0xfffff800 | 0x80;
    }
    else {
      scratchPtr14 = internalDrawStateSave;
      scratchPtr13 = (float *)0x0;
      scratchInt9 = 0;
      gldEnterInternalDrawState(commandStream,1,0,0,scratchPtr14);
    }
    scratchInt12 = scratchInt20 * 8 + 0x1b;
  }
  else {
    scratchPtr14 = internalDrawStateSave;
    scratchPtr13 = (float *)0x0;
    scratchInt9 = 1;
    gldEnterInternalDrawState(commandStream,0,0,1,scratchPtr14);
    scratchInt12 = scratchInt20 * 0x10 + 0x19;
  }
  if (*(char *)(ctx + 0x2a42) == '\0') {
    scratchInt12 = scratchInt12 + 2;
  }
  packetAlloc = (undefined4 *)(**(code **)(ctx + 0x2998))(commandStream,scratchInt12);
  *(undefined4 **)(ctx + 0x298c) = packetAlloc;
  packetCursor = packetAlloc;
  if (*(char *)(ctx + 0x2a42) == '\0') {
    packetCursor = packetAlloc + 2;
    *packetAlloc = 0x5c8;
    packetAlloc[1] = 0x10000000;
    *(undefined1 *)(ctx + 0x2a42) = 1;
  }
  *packetCursor = ((unsigned char *)0x000010c0U);
  packetCursor[1] = *(undefined4 *)(ctx + 0x216c);
  packetCursor = (undefined4 *)gldEmitInternalDrawSetupPackets(commandStream,packetCursor + 2);
  scratchDouble6 = DOUBLE_001aa1e0;
  windowXStart = FLOAT_001aa10c;
  rasterYI2dLo = (float *)(rasterY ^ 0x80000000);
  pointSizeI2dHi = 0x43300000;
  vertexCursor = (float *)(packetCursor + 2);
  scratchUint1 = (uint)(((double)CONCAT44(0x43300000,pointSizeWord) - DOUBLE_001aa250) * DOUBLE_001aa240);
  fctiwzSlot0 = (longlong)(int)scratchUint1;
  *packetCursor = ((unsigned char *)0x00001087U);
  packetCursor[1] = scratchUint1 << 0x10 | scratchUint1 & 0xffff;
  oneBits = 0x3f800000;
  rasterYI2dHi = 0x43300000;
  windowY = windowXStart / *(float *)(ctx + 0x2a58) +
              (float)((double)CONCAT44(0x43300000,rasterYI2dLo) - scratchDouble6);
  if (format != 0x1901) {
    scratchPtr16 = (float *)0xc0003500;
    vertexCursor = (float *)(packetCursor + 4);
    packetCursor[2] = scratchInt20 * 0x80000 | 0xc0003500;
    packetCursor[3] = scratchInt20 * 0x10000 | 0x31;
    if (procHeight != 0) {
      i2dLo1 = rasterX ^ 0x80000000;
      i2dHi1 = 0x43300000;
      scratchInt9 = 0;
      scratchPtr13 = &colorA;
      windowXStart = (float)((double)CONCAT44(0x43300000,i2dLo1) - scratchDouble6) + windowXStart;
      do {
        scratchDouble6 = DOUBLE_001aa250;
        scratchFloat18 = FLOAT_001aa0f0;
        windowX = windowXStart;
        if (procWidth != 0) {
          scratchPtr14 = (float *)0x43300000;
          srcCursor = srcPixels;
          scratchInt20 = procWidth;
          do {
            if (format == 0x1902) {
              depthZ = *srcCursor;
              colorR = *(float *)(rasterPosRecord + 0x30);
              colorG = *(float *)(rasterPosRecord + 0x34);
              colorB = *(float *)(rasterPosRecord + 0x38);
              colorA = *(float *)(rasterPosRecord + 0x3c);
            }
            else {
              depthZ = *(float *)(rasterPosRecord + 8);
              pixelValueF = *srcCursor;
              alphaI2dHi = 0x43300000;
              redI2dHi = 0x43300000;
              greenI2dHi = 0x43300000;
              blueI2dHi = 0x43300000;
              blueI2dLo = (uint)(int)pixelValueF & 0xff;
              alphaI2dLo = (uint)(int)pixelValueF >> 0x18;
              scratchPtr16 = (float *)((uint)(int)pixelValueF >> 0x10 & 0xff);
              greenI2dLo = (uint)(int)pixelValueF >> 8 & 0xff;
              colorA = (float)((double)CONCAT44(0x43300000,alphaI2dLo) - scratchDouble6) / scratchFloat18;
              colorB = (float)((double)CONCAT44(0x43300000,blueI2dLo) - scratchDouble6) / scratchFloat18;
              colorR = (float)((double)CONCAT44(0x43300000,scratchPtr16) - scratchDouble6) / scratchFloat18;
              colorG = (float)((double)CONCAT44(0x43300000,greenI2dLo) - scratchDouble6) / scratchFloat18;
              redI2dLo = scratchPtr16;
            }
            srcCursor = (float *)((int)srcCursor + bytesPerPixel);
            *vertexCursor = windowX;
            vertexCursor[1] = windowY;
            vertexCursor[2] = depthZ;
            vertexCursor[3] = 1.0;
            vertexCursor[4] = colorR;
            vertexCursor[5] = colorG;
            vertexCursor[6] = colorB;
            vertexCursor[7] = colorA;
            vertexCursor = vertexCursor + 8;
            windowX = stepX + windowX;
            scratchInt20 = scratchInt20 + -1;
          } while (scratchInt20 != 0);
        }
        scratchInt9 = scratchInt9 + 1;
        srcPixels = (float *)((int)srcPixels + (int)srcRowBytes);
        windowY = stepY + windowY;
      } while (scratchInt9 != procHeight);
    }
  }
  else {
    scratchFloat18 = GH_U2F((unsigned int)((*(uint *)(ctx + 0x1ce8) & 0xffff00ff | 0xff00)));
    scratchPtr16 = rasterYI2dLo;
    if (procHeight != 0) {
      i2dLo2 = rasterX ^ 0x80000000;
      i2dHi2 = 0x43300000;
      loopIndex = 0;
      windowXStart = windowXStart / *(float *)(ctx + 0x2a54) +
              (float)((double)CONCAT44(0x43300000,i2dLo2) - scratchDouble6);
      do {
        uintBiasD = DOUBLE_001aa250;
        scratchDouble6 = DOUBLE_001aa240;
        windowX = windowXStart;
        if (procWidth != 0) {
          scratchInt9 = 1;
          scratchPtr14 = (float *)((unsigned char *)0x00001087U);
          scratchPtr13 = (float *)0x3f800000;
          scratchPtr16 = srcPixels;
          scratchInt12 = procWidth;
          do {
            depthZ = *(float *)(rasterPosRecord + 8);
            colorR = *(float *)(rasterPosRecord + 0x30);
            colorG = *(float *)(rasterPosRecord + 0x34);
            colorB = *(float *)(rasterPosRecord + 0x38);
            colorA = *(float *)(rasterPosRecord + 0x3c);
            alphaByte = *(byte *)scratchPtr16;
            *vertexCursor = GH_U2F((unsigned int)(((unsigned char *)0x000013c2U)));
            scratchPtr16 = (float *)((int)scratchPtr16 + bytesPerPixel);
            scratchFloat18 = GH_U2F((unsigned int)(((uint)alphaByte | (uint)(int)scratchFloat18 & 0xffffff00)));
            vertexCursor[1] = scratchFloat18;
            pointSizeI2dLo2 = *(undefined4 *)(ctx + 0x248);
            pointSizeI2dHi2 = 0x43300000;
            scratchUint1 = (uint)(((double)CONCAT44(0x43300000,pointSizeI2dLo2) - uintBiasD) * scratchDouble6);
            fctiwzSlot1 = (longlong)(int)scratchUint1;
            vertexCursor[5] = 9.19042e-41;
            vertexCursor[6] = windowX;
            vertexCursor[7] = windowY;
            vertexCursor[8] = depthZ;
            vertexCursor[2] = GH_U2F((unsigned int)(((unsigned char *)0x00001087U)));
            vertexCursor[4] = -2.1282349;
            vertexCursor[3] = GH_U2F((unsigned int)((scratchUint1 << 0x10 | scratchUint1 & 0xffff)));
            vertexCursor[9] = 1.0;
            vertexCursor[10] = colorR;
            vertexCursor[0xb] = colorG;
            vertexCursor[0xc] = colorB;
            vertexCursor[0xd] = colorA;
            vertexCursor[0xe] = GH_U2F((unsigned int)(((unsigned char *)0x00001087U)));
            vertexCursor[0xf] = *(float *)(ctx + 0x1f0c);
            vertexCursor = vertexCursor + 0x10;
            windowX = stepX + windowX;
            scratchInt12 = scratchInt12 + -1;
          } while (scratchInt12 != 0);
        }
        loopIndex = loopIndex + 1;
        srcPixels = (float *)((int)srcPixels + (int)srcRowBytes);
        windowY = stepY + windowY;
      } while (procHeight != loopIndex);
    }
  }
  *vertexCursor = GH_U2F((unsigned int)(((unsigned char *)0x00001087U)));
  vertexCursor[1] = *(float *)(ctx + 0x1f0c);
  *(float **)(ctx + 0x298c) = vertexCursor + 2;
  pointSizeI2dLo = pointSizeWord;
  (**(code **)(ctx + 0x299c))(commandStream,vertexCursor + 2);
  gldValidateVertexProgramState(commandStream,r4AfterCall,scratchPtr13,scratchInt9,scratchPtr14,vertexCursor,scratchPtr16);
  return gldLeaveInternalDrawState(commandStream,internalDrawStateSave);
}

/* gld_enterPointDrawState @ 0x2a260 (356 bytes) */
int gld_enterPointDrawState(ring, drawStateSave)
  int ring;
  undefined4 drawStateSave;
{
  uint pointSizeFixed;
  double i2dBias;
  undefined4 scratchUint3;
  undefined4 *packet;
  undefined4 pointSizeWord;
  
  pointSizeWord = *(undefined4 *)(ring + 8);
  gld_resetRasterStateForInternalDraw(ring,(*(uint *)(ring + 0x1ab8) ^ 1) & 1,drawStateSave);
  gldClearBoundSlot(ring,*(uint *)(ring + 0x18a4) >> 6 & 0xffff);
  scratchUint3 = (**(code **)(ring + 0x2758))(ring,0x1f);
  *(undefined4 *)(0x00002748 + ring + 4) = scratchUint3;
  packet = (undefined4 *)gldEmitInternalDrawSetupPackets(ring,scratchUint3);
  *packet = ((unsigned char *)0x000010c0U);
  i2dBias = DOUBLE_001aa250;
  packet[1] = 0x80;
  pointSizeFixed = (uint)(((double)CONCAT44(0x43300000,pointSizeWord) - i2dBias) * DOUBLE_001aa240);
  packet[2] = ((unsigned char *)0x00001087U);
  packet[4] = ((unsigned char *)0x000012f0U);
  packet[5] = 0;
  packet[3] = pointSizeFixed << 0x10 | pointSizeFixed & 0xffff;
  *(undefined4 *)(ring + 0x1b84) = 5;
  *(undefined4 *)(ring + 0x1c8c) = *(undefined4 *)(ring + 0x2814);
  *(undefined4 *)(ring + 0x1c94) = *(undefined4 *)(ring + 0x2818);
  packet[6] = 0x82c;
  scratchUint3 = *(undefined4 *)(ring + 0x1b84);
  packet[8] = 0x766;
  packet[7] = scratchUint3;
  scratchUint3 = *(undefined4 *)(ring + 0x1c8c);
  packet[10] = 0x768;
  packet[9] = scratchUint3;
  packet[0xb] = *(undefined4 *)(ring + 0x1c94);
  *(undefined4 **)(0x00002748 + ring + 4) = packet + 0xc;
                    
                    
  (**(code **)(ring + 0x275c))(ring,packet + 0xc);
  return;
}

/* gld_drawPixelsFromClientSurface @ 0x2a3d0 (3968 bytes) */
int gld_drawPixelsFromClientSurface(ctx, rasterPosition, width, height, format, pixelType, pixels, rawTransfer, surfaceInfo)
  int ctx;
  int rasterPosition;
  uint width;
  uint height;
  uint format;
  undefined *pixelType;
  int pixels;
  int rawTransfer;
  undefined4 *surfaceInfo;
{
  undefined4 vap_vte_cntl;
  bool lastUnit;
  float renderHeightF;
  float renderWidthF;
  float rasterY;
  float rasterX;
  int surfaceBase;
  undefined4 *packetEnd;
  int *targetSlot;
  int unitObject;
  int unitIndex;
  int unitOffset;
  int storeResult;
  int unitSlotPtr;
  int prepareResult;
  byte formatIndex;
  undefined *formatTableB;
  undefined *formatTable;
  uint fg_alpha_func;
  uint fg_fog_blend;
  undefined4 ga_point_size;
  undefined4 sc_scissor1;
  undefined4 rb3d_ropcntl;
  undefined4 rb3d_color_channel_mask;
  undefined4 tx_format2;
  undefined4 tx_format1;
  undefined4 tx_format0;
  undefined4 tx_filter0;
  undefined4 rs_ip_0;
  undefined4 rs_count;
  undefined4 us_out_fmt_3;
  undefined4 us_out_fmt_2;
  undefined4 us_out_fmt_1;
  undefined4 us_out_fmt_0;
  undefined4 gb_ps3_enable;
  undefined4 tx_enable;
  undefined4 ga_color_control;
  undefined4 ga_poly_mode;
  undefined4 zb_cntl;
  undefined4 vap_prog_stream_cntl_ext_0_ptr;
  undefined4 vap_prog_stream_cntl_0_ptr;
  undefined4 vap_out_vtx_fmt_1;
  undefined4 vap_out_vtx_fmt_0;
  undefined4 gb_enable;
  undefined4 rb3d_dither_ctl;
  undefined4 su_cull_mode;
  undefined4 vap_clip_cntl;
  undefined4 vap_cntl_status;
  undefined4 zb_zstencilcntl;
  undefined4 zb_bw_cntl;
  undefined4 sc_hyperz_en;
  undefined4 gb_aa_config;
  undefined4 gb_mspos1;
  undefined4 sc_screendoor;
  undefined4 sc_edgerule;
  bool scratchFlag1;
  float scratchFloat2;
  float scratchFloat3;
  float scratchFloat4;
  float scratchFloat5;
  float scratchFloat6;
  uint colorFormatBits;
  float scratchFloat8;
  float clipRight;
  float clipLeft;
  float scratchFloat11;
  float scratchFloat12;
  float scratchFloat13;
  float scratchFloat14;
  double unsignedConvBias;
  undefined *hwContextTemplate;
  uint oldRb3dWord;
  undefined *unpackState;
  uint *lastHeader;
  uint scratchUint20;
  int *surfaceRefPtr;
  int scratchInt22;
  uint *packetRaw;
  undefined4 *packet;
  undefined4 scratchUint25;
  int scratchInt26;
  uint renderWidthClamped;
  uint scratchUint28;
  uint renderHeightClamped;
  undefined4 *surfaceObject;
  uint dstAddress;
  int hwFormat;
  int ring;
  int scratchInt34;
  char reservation;
  byte scratchFlag35;
  int targetsLeft;
  double oneD;
  double quadWidthMinusOne;
  double scratchDouble39;
  double quadWidthD;
  double quadHeightD;
  uint srcRowBytes;
  undefined1 layoutOut [4];
  int srcSkipBytes [2];
  undefined4 renderWidthI2dHi;
  uint renderWidthI2dLo;
  undefined4 renderHeightI2dHi;
  uint renderHeightI2dLo;
  undefined4 widthI2dHi;
  uint widthI2dLo;
  undefined4 heightI2dHi;
  uint heightI2dLo;
  undefined4 negRenderHeightI2dHi;
  uint negRenderHeightI2dLo;
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
  
  if (format == 0x1909) {
    hwFormat = 1;
    if (pixelType != ((unsigned char *)0x00001401)) {
      hwFormat = 0x13;
      if ((pixelType != ((unsigned char *)0x00001406)) && (hwFormat = 0x1f, pixelType != ((unsigned char *)0x0000140b))) {
        hwFormat = 0;
        if (pixelType != ((unsigned char *)0x00001403)) goto loopCheckHwFormat;
        hwFormat = 0x19;
      }
      goto callPthreadMutexLock;
    }
loopCheckHwFormat:
    if (hwFormat == 0) {
      return 0;
    }
  }
  else if (format < 0x190a) {
    if (format == 0x1907) {
      hwFormat = 5;
      if ((pixelType != (undefined *)0x8363) && (hwFormat = 0x28, pixelType != (undefined *)0x8032)) {
        return 0;
      }
    }
    else if (format < 0x1908) {
      if (format != 0x1906) {
        return 0;
      }
      hwFormat = 2;
      if (pixelType == ((unsigned char *)0x00001401)) goto loopCheckHwFormat;
      hwFormat = 0x14;
      if ((pixelType != ((unsigned char *)0x00001406)) && (hwFormat = 0x20, pixelType != ((unsigned char *)0x0000140b))) {
        hwFormat = 0;
        if (pixelType != ((unsigned char *)0x00001403)) goto loopCheckHwFormat;
        hwFormat = 0x1a;
      }
    }
    else {
      hwFormat = 0x12;
      if (pixelType == ((unsigned char *)0x00001406)) {
loopCheckPixelType:
        if (pixelType == (undefined *)0x8368) {
          hwFormat = 0x23;
          goto callPthreadMutexLock;
        }
      }
      else {
        if (pixelType == (undefined *)0x8035) {
          hwFormat = 9;
          goto loopCheckPixelType;
        }
        if (pixelType != (undefined *)0x8367) {
          hwFormat = 0;
          if (pixelType == ((unsigned char *)0x00001401)) {
            hwFormat = 9;
            goto callPthreadMutexLock;
          }
          goto loopCheckPixelType;
        }
        hwFormat = 10;
      }
      if (pixelType != ((unsigned char *)0x00001403)) goto loopCheckHwFormat;
      hwFormat = 0x18;
    }
  }
  else if (format == 0x80e1) {
    hwFormat = 7;
    if (pixelType == (undefined *)0x8366) {
loopCheckPixelType2:
      if (pixelType == (undefined *)0x8035) {
        hwFormat = 8;
        goto checkPixelType2;
      }
loopCheckPixelType3:
      if (pixelType != (undefined *)0x8368) goto checkPixelType;
      hwFormat = 0x24;
loopCheckPixelType4:
      if (pixelType != ((unsigned char *)0x00001403)) goto loopCheckHwFormat;
      hwFormat = 0x17;
    }
    else {
      if (pixelType == (undefined *)0x8365) {
        hwFormat = 6;
        goto loopCheckPixelType3;
      }
      hwFormat = 0;
      if (pixelType != (undefined *)0x8367) goto loopCheckPixelType2;
      hwFormat = 0xb;
checkPixelType:
      if (pixelType == ((unsigned char *)0x00001406)) {
        hwFormat = 0x11;
      }
      else {
checkPixelType2:
        if (pixelType != ((unsigned char *)0x0000140b)) goto loopCheckPixelType4;
        hwFormat = 0x1d;
      }
    }
  }
  else if (format == 0x85b9) {
    hwFormat = 0x27;
    if ((pixelType != (undefined *)0x85ba) && (hwFormat = 0x26, pixelType != (undefined *)0x85bb)) {
      return 0;
    }
  }
  else {
    if (format != 0x190a) {
      return 0;
    }
    hwFormat = 4;
    if (pixelType == ((unsigned char *)0x00001401)) goto loopCheckHwFormat;
    if (pixelType == ((unsigned char *)0x00001406)) {
      hwFormat = 0x16;
    }
    else {
      hwFormat = 0x22;
      if (pixelType != ((unsigned char *)0x0000140b)) {
        hwFormat = 0;
        if (pixelType != ((unsigned char *)0x00001403)) goto loopCheckHwFormat;
        hwFormat = 0x1c;
      }
    }
  }
callPthreadMutexLock:
  _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
  if (rawTransfer == 0) {
    unpackState = ((unsigned char *)0x00002e6c) + *(int *)(ctx + GLD_engineState);
  }
  else {
    unpackState = (undefined *)0x0;
  }
  gld_computePixelStoreLayout(ctx,format,pixelType,width,height,&srcRowBytes,layoutOut,srcSkipBytes,unpackState);
  surfaceBase = *(int *)*surfaceInfo;
  dstAddress = pixels + srcSkipBytes[0];
  if (((((int)srcRowBytes < 0x1001) && ((int)height < 0x1001)) &&
      (renderWidthClamped = *(uint *)(ctx + GLD_renderWidth), (int)renderWidthClamped < 0x1001)) &&
     (renderHeightClamped = *(uint *)(ctx + GLD_renderHeight), (int)renderHeightClamped < 0x1001)) {
    if ((int)renderWidthClamped < 1) {
      renderWidthClamped = 1;
      renderWidthF = FLOAT_001aa0e8;
    }
    else {
      renderWidthI2dLo = renderWidthClamped ^ 0x80000000;
      renderWidthI2dHi = 0x43300000;
      renderWidthF = (float)((double)CONCAT44(0x43300000,renderWidthI2dLo) - DOUBLE_001aa1e0);
    }
    if ((int)renderHeightClamped < 1) {
      renderHeightClamped = 1;
      negRenderHeightI2dLo = 0xffffffff;
      renderHeightF = FLOAT_001aa0e8;
    }
    else {
      renderHeightI2dLo = renderHeightClamped ^ 0x80000000;
      negRenderHeightI2dLo = -renderHeightClamped;
      renderHeightI2dHi = 0x43300000;
      renderHeightF = (float)((double)CONCAT44(0x43300000,renderHeightI2dLo) - DOUBLE_001aa1e0);
    }
    widthI2dLo = width ^ 0x80000000;
    heightI2dLo = height ^ 0x80000000;
    heightI2dHi = 0x43300000;
    widthI2dHi = 0x43300000;
    rasterX = *(float *)(rasterPosition + 0x20);
    rasterY = *(float *)(rasterPosition + 0x24);
    scratchFloat8 = rasterX + FLOAT_001aa0d4 + FLOAT_001aa0d4;
    scratchFloat2 = renderHeightF - (rasterY + FLOAT_001aa0d4);
    scratchFloat13 = renderHeightF - ((float)((double)CONCAT44(0x43300000,heightI2dLo) - DOUBLE_001aa1e0) + rasterY);
    scratchFloat11 = (float)((double)CONCAT44(0x43300000,widthI2dLo) - DOUBLE_001aa1e0) + rasterX +
             FLOAT_001aa0d4;
    clipLeft = FLOAT_001aa0d4;
    scratchFloat12 = FLOAT_001aa0d4;
    if (FLOAT_001aa0d4 < scratchFloat8) {
      clipLeft = scratchFloat8;
      scratchFloat12 = scratchFloat8 + FLOAT_001aa0d4;
    }
    negRenderHeightI2dLo = negRenderHeightI2dLo ^ 0x80000000;
    scratchFloat8 = scratchFloat11 - renderWidthF;
    scratchFloat14 = scratchFloat2 - renderHeightF;
    negRenderHeightI2dHi = 0x43300000;
    clipRight = renderWidthF;
    if (scratchFloat8 < 0.0) {
      clipRight = scratchFloat11;
    }
    scratchFloat11 = renderHeightF;
    if (scratchFloat14 < 0.0) {
      scratchFloat11 = scratchFloat2;
    }
    scratchFloat2 = scratchFloat13;
    if (scratchFloat13 < 0.0) {
      scratchFloat2 = FLOAT_001aa0d4;
    }
    if (-scratchFloat8 < 0.0) {
      clipRight = renderWidthF;
    }
    if (-scratchFloat14 < 0.0) {
      scratchFloat11 = renderHeightF;
    }
    scratchFloat3 = FLOAT_001aa0d4;
    if (-scratchFloat13 < 0.0) {
      scratchFloat3 = scratchFloat2;
    }
    scratchFloat8 = -rasterX + scratchFloat12 + FLOAT_001aa0d4;
    scratchFloat12 = -rasterX + clipRight + FLOAT_001aa0d4 + FLOAT_001aa0d4;
    scratchFloat4 = (float)((double)CONCAT44(0x43300000,negRenderHeightI2dLo) - DOUBLE_001aa1e0);
    scratchFloat5 = -rasterY + (FLOAT_001aa0d4 - (scratchFloat11 + scratchFloat4));
    scratchFloat4 = -rasterY + (FLOAT_001aa0d4 - (scratchFloat3 + scratchFloat4));
    if ((clipLeft < clipRight) && (scratchFloat3 < scratchFloat11)) {
      if (((((*(int *)surfaceInfo[1] != 0) && (prepareResult = gld_prepareBufferBacking(ctx,surfaceInfo,1), prepareResult == 0))
           || ((formatTable = PTR_DAT_001e88c8, (int *)surfaceInfo[2] == (int *)0x0 ||
               (prepareResult = *(int *)surfaceInfo[2], prepareResult == 0)))) ||
          ((*(char *)(prepareResult + 0x16) != '\x06' &&
           ((format != 0x1908 || ((pixelType != ((unsigned char *)0x00001406) && (pixelType != (undefined *)0x8366)))))
           ))) || (((dstAddress | srcRowBytes) & 0x1f) != 0)) goto callPthreadMutexUnlock;
      ring = ctx + GLD_commandStream;
      unitIndex = 0xf;
      scratchUint25 = (**(code **)(ctx + GLD_streamAllocate))(ring,0x343);
      *(undefined4 *)(ctx + GLD_streamCurrent) = scratchUint25;
      unitSlotPtr = ctx;
      do {
        if (*(int *)(unitSlotPtr + 0x1c8) != 0) {
          scratchUint25 = ((int (*)())gld_emitUnitObjectPacket)(ctx,0,unitIndex,scratchUint25);
        }
        unitIndex = unitIndex + -1;
        scratchFlag35 = (unitIndex == 0) << 1;
        unitSlotPtr = unitSlotPtr + -4;
      } while (unitIndex != 0);
      packetRaw = (uint *)((int (*)())gld_emitUnitObjectPacket)(ctx,0,0,scratchUint25);
      packet = (undefined4 *)((uint)(packetRaw + 0xb) & 0xffffffe0);
      *packetRaw = (((int)packet - (int)packetRaw) + -8) * 0x4000 | 0xc0001000;
      packet[-1] = (int)packet - (int)packetRaw;
      lastHeader = *(uint **)(ctx + GLD_lastHeader);
      *lastHeader = (int)packet - (int)lastHeader >> 2 | *lastHeader;
      *(undefined4 **)(ctx + GLD_lastHeader) = packet;
      *packet = 0x3f000000;
      surfaceObject = *(undefined4 **)surfaceInfo[2];
      surfaceRefPtr = surfaceObject + 4;
      do {
        if (reservation != '\0') {
          storeResult = storeWordConditionalIndexed(*surfaceRefPtr + 0x10000,0,surfaceRefPtr);
          *surfaceRefPtr = storeResult;
          scratchFlag35 = 2;
        }
        hwContextTemplate = PTR_DAT_001e88d0;
      } while (!(bool)(scratchFlag35 >> 1 & 1));
      packet[2] = *surfaceObject;
      packet[3] = dstAddress - *(int *)*surfaceInfo;
      _memcpy(packet + 4,hwContextTemplate,0x2f4);
      scratchFloat6 = scratchFloat12 - scratchFloat8;
      quadWidthD = (double)scratchFloat6;
      scratchFloat2 = scratchFloat4 - scratchFloat5;
      quadHeightD = (double)scratchFloat2;
      oneD = (double)FLOAT_001aa0e8;
      packet[0x22] = 0;
      scratchDouble39 = DOUBLE_001aa1e8;
      quadWidthMinusOne = (double)(float)(quadWidthD - oneD);
      scratchFlag1 = DOUBLE_001aa1e8 <= quadWidthMinusOne;
      packet[0xa4] = *(uint *)(formatTable + hwFormat * 0x24 + 0x18) >> 0x1e | packet[0xa4] & 0xfffffffc
      ;
      unsignedConvBias = DOUBLE_001aa1e8;
      if (scratchFlag1) {
        scratchInt22 = (int)(quadWidthMinusOne - scratchDouble39);
        fctiwzSlot1 = (longlong)scratchInt22;
        scratchUint20 = scratchInt22 + 0x80000000;
      }
      else {
        scratchUint20 = (uint)(int)(quadWidthD - oneD);
        fctiwzSlot0 = (longlong)(int)scratchUint20;
      }
      scratchDouble39 = (double)(float)(quadHeightD - (double)FLOAT_001aa0e8);
      if (DOUBLE_001aa1e8 <= scratchDouble39) {
        scratchInt22 = (int)(scratchDouble39 - DOUBLE_001aa1e8);
        fctiwzSlot3 = (longlong)scratchInt22;
        scratchUint28 = scratchInt22 + 0x80000000;
      }
      else {
        scratchUint28 = (uint)(int)(quadHeightD - (double)FLOAT_001aa0e8);
        fctiwzSlot2 = (longlong)(int)scratchUint28;
      }
      packet[0xaa] = scratchUint20 & 0x7ff | (scratchUint28 & 0x7ff) << 0xb | 0x80000000;
      scratchUint20 = *(uint *)(formatTable + hwFormat * 0x24 + 0x1c);
      scratchUint28 = *(uint *)(formatTable + hwFormat * 0x24 + 0x20);
      packet[0xac] =
           scratchUint20 >> 7 & 0x1f | scratchUint28 >> 3 & 0x400000 | (scratchUint20 & 0x70) << 5 |
           (scratchUint20 & 0xe) << 0xb | scratchUint28 >> 0xe & 0x38000 | scratchUint28 >> 8 & 0x1c0000;
      formatTableB = PTR_DAT_001e88c8;
      if (unsignedConvBias <= quadWidthD) {
        scratchInt22 = (int)(quadWidthD - unsignedConvBias);
        fctiwzSlot5 = (longlong)scratchInt22;
        scratchInt22 = scratchInt22 + -0x80000000;
      }
      else {
        scratchInt22 = (int)scratchFloat6;
        fctiwzSlot4 = (longlong)scratchInt22;
      }
      if (DOUBLE_001aa1e8 <= quadHeightD) {
        fctiwzSlot7 = (longlong)(int)(quadHeightD - DOUBLE_001aa1e8);
        scratchInt34 = (int)(quadHeightD - DOUBLE_001aa1e8) + -0x80000000;
      }
      else {
        scratchInt34 = (int)scratchFloat2;
        fctiwzSlot6 = (longlong)scratchInt34;
      }
      oldRb3dWord = packet[0x8e];
      packet[0xae] =
           ((int)srcRowBytes >> (*(uint *)(formatTable + hwFormat * 0x24 + 0x14) & 7)) - 1U & 0x3fff |
           (scratchInt22 + -1) * 0x10 & 0xffff8000U | (scratchInt34 + -1) * 0x20 & 0xffff0000U;
      packet[0xa4] = (dstAddress - surfaceBase) * 0x20 | packet[0xa4] & 0x1f;
      formatIndex = ((unsigned char *)GLD_colorFormatIndex)[ctx];
      dstAddress = (*(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x18) & 0x18) << 5;
      packet[0x8e] = dstAddress | oldRb3dWord & 0xfffffcff;
      scratchUint20 = (*(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x18) & 6) << 9;
      packet[0x8e] = scratchUint20 | dstAddress | oldRb3dWord & 0xfffff0ff;
      scratchUint28 = *(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x1c) >> 0x12 & 0x3000;
      packet[0x8e] = scratchUint28 | scratchUint20 | dstAddress | oldRb3dWord & 0xffffc0ff;
      colorFormatBits = *(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x1c) >> 0xe & 0xc000;
      packet[0x8e] = colorFormatBits | scratchUint28 | scratchUint20 | dstAddress | oldRb3dWord & 0xffff00ff;
      packet[0x8e] =
           *(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x18) >> 5 & 0x1f |
           colorFormatBits | scratchUint28 | scratchUint20 | dstAddress | oldRb3dWord & 0xffff00e0;
      if ((*(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x14) & 0xfc000000) == 0) {
        packet[0x5a] = packet[0x5a] & 0xfffe3fff | 0x18000;
      }
      scratchFloat14 = FLOAT_001aa12c;
      scratchFloat13 = FLOAT_001aa10c;
      packetEnd = packet + 0xcd;
      scratchFloat6 = (float)((double)FLOAT_001aa0e8 / quadHeightD);
      scratchFloat2 = (float)((double)FLOAT_001aa0e8 / quadWidthD);
      packet[0xb7] = renderWidthClamped - 1 & 0x1fff | (renderHeightClamped - 1) * 0x2000 & 0x3ffe000;
      packet[0xc1] = 0x31080;
      packet[0xc6] = ((unsigned char *)0x00001087U);
      packet[0xc5] = scratchFloat4 * scratchFloat6;
      hwFormat = (int)((clipRight - clipLeft) * scratchFloat14);
      fctiwzSlot8 = (longlong)hwFormat;
      packet[0xc4] = scratchFloat12 * scratchFloat2;
      packet[0xc2] = scratchFloat8 * scratchFloat2;
      packet[0xc3] = scratchFloat5 * scratchFloat6;
      dstAddress = (uint)(int)((scratchFloat11 - scratchFloat3) * scratchFloat14);
      fctiwzSlot9 = (longlong)(int)dstAddress;
      packet[0xc9] = 0x10031;
      packet[200] = 0xc0033500;
      packet[0xca] = (clipLeft + clipRight) * scratchFloat13;
      packet[0xcb] = (scratchFloat3 + scratchFloat11) * scratchFloat13;
      packet[0xcc] = 0;
      packet[199] = hwFormat << 0x10 | dstAddress;
      packet[1] = (int)packetEnd - (int)packetRaw >> 2;
      lastHeader = *(uint **)(ctx + GLD_lastHeader);
      *lastHeader = (int)packetEnd - (int)lastHeader >> 2 | *lastHeader;
      *(undefined4 **)(ctx + GLD_lastHeader) = packetEnd;
      packet[0xce] = 0;
      packet[0xcd] = 0x33000000;
      packet[0xcf] = ((unsigned char *)0x00001393U);
      packet[0xd0] = 10;
      packet[0xd1] = ((unsigned char *)0x000013c6U);
      packet[0xd2] = 3;
      packet[0xd3] = 0x5c8;
      packet[0xd4] = 0x20000;
      packet[0xd5] = ((unsigned char *)0x000010eaU);
      sc_edgerule = *(undefined4 *)(ctx + GLD_sc_edgerule);
      packet[0xd7] = ((unsigned char *)0x000010faU);
      packet[0xd6] = sc_edgerule;
      sc_screendoor = *(undefined4 *)(ctx + GLD_sc_screendoor);
      packet[0xd9] = 0xc0001000;
      packet[0xdb] = 0x11004;
      packet[0xd8] = sc_screendoor;
      packet[0xdc] = *(undefined4 *)(ctx + GLD_gb_mspos0);
      gb_mspos1 = *(undefined4 *)(ctx + GLD_gb_mspos1);
      packet[0xde] = ((unsigned char *)0x00001008U);
      packet[0xdd] = gb_mspos1;
      gb_aa_config = *(undefined4 *)(ctx + GLD_gb_aa_config);
      packet[0xe0] = ((unsigned char *)0x000010e9U);
      packet[0xdf] = gb_aa_config;
      sc_hyperz_en = *(undefined4 *)(ctx + GLD_sc_hyperz_en);
      packet[0xe2] = ((unsigned char *)0x000013c7U);
      packet[0xe1] = sc_hyperz_en;
      zb_bw_cntl = *(undefined4 *)(ctx + GLD_zb_bw_cntl);
      packet[0xe4] = ((unsigned char *)0x000013c1U);
      packet[0xe3] = zb_bw_cntl;
      zb_zstencilcntl = *(undefined4 *)(ctx + GLD_zb_zstencilcntl);
      packet[0xe6] = 0x850;
      packet[0xe5] = zb_zstencilcntl;
      vap_cntl_status = *(undefined4 *)(ctx + GLD_vap_cntl_status);
      packet[0xe8] = 0x887;
      packet[0xe7] = vap_cntl_status;
      vap_clip_cntl = *(undefined4 *)(ctx + GLD_vap_clip_cntl);
      packet[0x18a] = 0x82c;
      packet[0xe9] = vap_clip_cntl;
      vap_vte_cntl = *(undefined4 *)(GLD_vap_vte_cntl + ctx);
      packet[0xea] = ((unsigned char *)0x000010aeU);
      packet[0x18b] = vap_vte_cntl;
      su_cull_mode = *(undefined4 *)(ctx + GLD_su_cull_mode);
      packet[0xec] = ((unsigned char *)0x00001394U);
      packet[0xeb] = su_cull_mode;
      rb3d_dither_ctl = *(undefined4 *)(ctx + GLD_rb3d_dither_ctl);
      packet[0xee] = ((unsigned char *)0x00001380U);
      packet[0xf0] = ((unsigned char *)0x00001002U);
      packet[0xef] = 0;
      packet[0xed] = rb3d_dither_ctl;
      packet[0xf1] = *(undefined4 *)(ctx + GLD_gb_enable);
      gb_enable = *(undefined4 *)(ctx + GLD_gb_enable);
      packet[0xf2] = 0x824;
      packet[0xf1] = gb_enable;
      vap_out_vtx_fmt_0 = *(undefined4 *)(ctx + GLD_vap_out_vtx_fmt_0);
      packet[0xf4] = 0x825;
      packet[0xf3] = vap_out_vtx_fmt_0;
      vap_out_vtx_fmt_1 = *(undefined4 *)(ctx + GLD_vap_out_vtx_fmt_1);
      packet[0xf6] = 0x82d;
      packet[0xf5] = vap_out_vtx_fmt_1;
      scratchUint25 = *(undefined4 *)(0x000026c8 + ctx + GLD_connect);
      packet[0xf8] = 0x854;
      packet[0xf7] = scratchUint25;
      vap_prog_stream_cntl_0_ptr = **(undefined4 **)(ctx + GLD_vap_prog_stream_cntl_0_ptr);
      packet[0xfa] = 0x878;
      packet[0xf9] = vap_prog_stream_cntl_0_ptr;
      vap_prog_stream_cntl_ext_0_ptr = **(undefined4 **)(ctx + GLD_vap_prog_stream_cntl_ext_0_ptr);
      packet[0xfc] = ((unsigned char *)0x000013c0U);
      packet[0xfb] = vap_prog_stream_cntl_ext_0_ptr;
      zb_cntl = *(undefined4 *)(ctx + GLD_zb_cntl);
      packet[0xfe] = ((unsigned char *)0x000012f0U);
      packet[0xfd] = zb_cntl;
      fg_fog_blend = *(uint *)(ctx + GLD_fg_fog_blend);
      packet[0xff] = fg_fog_blend;
      if ((*(uint *)(formatTableB + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18) & 0x8000) == 0) {
        packet[0xff] = fg_fog_blend & 0xfffffffe;
      }
      packet[0x100] = ((unsigned char *)0x000012f5U);
      fg_alpha_func = *(uint *)(ctx + GLD_fg_alpha_func);
      packet[0x101] = fg_alpha_func;
      if ((*(uint *)(formatTableB + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18) & 0x8000) == 0) {
        packet[0x101] = fg_alpha_func & 0xfffff7ff;
      }
      packet[0x102] = ((unsigned char *)0x000010a2U);
      ga_poly_mode = *(undefined4 *)(ctx + GLD_ga_poly_mode);
      packet[0x104] = ((unsigned char *)0x00001381U);
      packet[0x103] = ga_poly_mode;
      dstAddress = *(uint *)(ctx + GLD_rb3d_blendcntl);
      packet[0x105] = dstAddress;
      if ((*(uint *)(formatTableB + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18) & 0x4000) == 0) {
        packet[0x105] = dstAddress & 0xfffffffc;
      }
      packet[0x106] = ((unsigned char *)0x0000109eU);
      unitOffset = 0;
      scratchInt26 = 0;
      scratchUint25 = *(undefined4 *)(ctx + 0x1d6c);
      packet[0x108] = ((unsigned char *)0x00001096U);
      packet[0x107] = scratchUint25;
      ga_color_control = *(undefined4 *)(ctx + GLD_ga_color_control);
      packet[0x10a] = ((unsigned char *)0x00001041U);
      packet[0x107] = ga_color_control;
      tx_enable = *(undefined4 *)(ctx + GLD_tx_enable);
      packet[0x10c] = ((unsigned char *)0x00001046U);
      packet[0x10b] = tx_enable;
      gb_ps3_enable = *(undefined4 *)(ctx + GLD_gb_ps3_enable);
      packet[0x10e] = ((unsigned char *)0x00001094U);
      packet[0x126] = ((unsigned char *)0x00001095U);
      packet[0x110] = ((unsigned char *)0x00001095U);
      packet[0x14c] = ((unsigned char *)0x00001180U);
      packet[0x112] = ((unsigned char *)0x00001095U);
      packet[0x114] = ((unsigned char *)0x00001095U);
      packet[0x116] = ((unsigned char *)0x00001095U);
      packet[0x10d] = gb_ps3_enable;
      packet[0x118] = ((unsigned char *)0x00001095U);
      packet[0x11a] = ((unsigned char *)0x00001095U);
      packet[0x11c] = ((unsigned char *)0x00001095U);
      packet[0x11e] = ((unsigned char *)0x00001095U);
      packet[0x120] = ((unsigned char *)0x00001095U);
      packet[0x122] = ((unsigned char *)0x00001095U);
      packet[0x124] = ((unsigned char *)0x00001095U);
      packet[0x128] = 0xc0221000;
      packet[0x10f] = 0;
      packet[0x14d] = 2;
      packet[0x14e] = ((unsigned char *)0x00001189U);
      packet[0x150] = ((unsigned char *)0x00001181U);
      packet[0x152] = ((unsigned char *)0x0000118dU);
      packet[0x154] = ((unsigned char *)0x0000118eU);
      packet[0x156] = ((unsigned char *)0x0000118cU);
      packet[0x158] = ((unsigned char *)0x000011a9U);
      us_out_fmt_0 = *(undefined4 *)(ctx + GLD_us_out_fmt_0);
      packet[0x15a] = ((unsigned char *)0x000011aaU);
      packet[0x159] = us_out_fmt_0;
      us_out_fmt_1 = *(undefined4 *)(ctx + GLD_us_out_fmt_1);
      packet[0x15c] = ((unsigned char *)0x000011abU);
      packet[0x15b] = us_out_fmt_1;
      us_out_fmt_2 = *(undefined4 *)(ctx + GLD_us_out_fmt_2);
      packet[0x15e] = ((unsigned char *)0x000011acU);
      packet[0x15d] = us_out_fmt_2;
      us_out_fmt_3 = *(undefined4 *)(ctx + GLD_us_out_fmt_3);
      packet[0x160] = ((unsigned char *)0x000010c0U);
      packet[0x15f] = us_out_fmt_3;
      rs_count = *(undefined4 *)(ctx + GLD_rs_count);
      packet[0x162] = ((unsigned char *)0x000010c1U);
      packet[0x164] = ((unsigned char *)0x000010c8U);
      packet[0x166] = ((unsigned char *)0x0000101dU);
      packet[0x161] = rs_count;
      rs_ip_0 = *(undefined4 *)(ctx + GLD_rs_ip_0);
      packet[0x168] = ((unsigned char *)0x0000138aU);
      packet[0x16a] = ((unsigned char *)0x0000138eU);
      packet[0x16f] = 0;
      packet[0x16c] = ((unsigned char *)0x00001040U);
      packet[0x169] = 0;
      packet[0x16b] = 0;
      packet[0x16d] = 0;
      packet[0x167] = rs_ip_0;
      packet[0x16e] = ((unsigned char *)0x00001150U);
      packet[0x170] = ((unsigned char *)0x00001100U);
      tx_filter0 = *(undefined4 *)(ctx + GLD_tx_filter0);
      packet[0x172] = ((unsigned char *)0x00001110U);
      packet[0x171] = tx_filter0;
      packet[0x173] = *(undefined4 *)(ctx + GLD_tx_filter1);
      packet[0x174] = ((unsigned char *)0x00001120U);
      tx_format0 = *(undefined4 *)(ctx + GLD_tx_format0);
      packet[0x176] = ((unsigned char *)0x00001130U);
      packet[0x175] = tx_format0;
      tx_format1 = *(undefined4 *)(ctx + GLD_tx_format1);
      packet[0x178] = ((unsigned char *)0x00001140U);
      packet[0x177] = tx_format1;
      tx_format2 = *(undefined4 *)(ctx + GLD_tx_format2);
      packet[0x17a] = ((unsigned char *)0x000010f4U);
      packet[0x17b] = 0xaaaa;
      packet[0x17c] = ((unsigned char *)0x00001383U);
      packet[0x179] = tx_format2;
      rb3d_color_channel_mask = *(undefined4 *)(ctx + GLD_rb3d_color_channel_mask);
      packet[0x17e] = ((unsigned char *)0x00001386U);
      packet[0x17d] = rb3d_color_channel_mask;
      rb3d_ropcntl = *(undefined4 *)(ctx + GLD_rb3d_ropcntl);
      packet[0x180] = 0x110f8;
      packet[0x17f] = rb3d_ropcntl;
      packet[0x181] = *(undefined4 *)(ctx + GLD_sc_scissor0);
      sc_scissor1 = *(undefined4 *)(ctx + GLD_sc_scissor1);
      packet[0x183] = ((unsigned char *)0x00001087U);
      packet[0x182] = sc_scissor1;
      ga_point_size = *(undefined4 *)(ctx + GLD_ga_point_size);
      packet[0x185] = 0x31080;
      packet[0x184] = ga_point_size;
      packet[0x186] = *(undefined4 *)(ctx + GLD_ga_point_s0);
      packet[0x187] = *(undefined4 *)(ctx + GLD_ga_point_t0);
      packet[0x188] = *(undefined4 *)(ctx + GLD_ga_point_s1);
      packet[0x189] = *(undefined4 *)(ctx + GLD_ga_point_t1);
      gldCopyProgramStreamState(packet + 0xcf,ring);
      packet = packet + 0x18c;
      hwFormat = ctx;
      do {
        unitObject = *(int *)(hwFormat + 0x18c);
        if (unitObject != 0) {
          targetsLeft = 5;
          targetSlot = (int *)(scratchInt26 + *(int *)(ctx + GLD_engineObjects));
          do {
            if (unitObject == *targetSlot) {
              if (*(int *)(unitObject + 0x34) != 0) goto checkUnitOffset;
              break;
            }
            targetSlot = targetSlot + 1;
            targetsLeft = targetsLeft + -1;
          } while (targetsLeft != 0);
          unitObject = 0;
        }
checkUnitOffset:
        if ((unitOffset == 0) || (unitObject != 0)) {
          packet = (undefined4 *)((int (*)())gld_emitUnitObjectPacket)(ctx,unitObject,unitOffset,packet);
        }
        lastUnit = unitOffset != 0xf;
        scratchInt26 = scratchInt26 + 0x14;
        hwFormat = hwFormat + 4;
        unitOffset = unitOffset + 1;
      } while (lastUnit);
      *(undefined4 **)(ctx + GLD_streamCurrent) = packet;
      (**(code **)(ctx + GLD_streamSetCurrent))(ring,packet);
    }
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    scratchUint25 = 1;
  }
  else {
callPthreadMutexUnlock:
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    scratchUint25 = 0;
  }
  return scratchUint25;
}

/* noop_2b3b0 @ 0x2b3b0 (4 bytes) */
int noop_2b3b0(value)
  undefined4 value;
{
  /* hidden-argument defect (hidden_params.py) - real body is a single `blr`: an identity function
   * on r3, and its one real caller (part_001.c) does supply a real value. */
  return value;
}

/* gld_sumQueryCounters @ 0x2b3c0 (464 bytes) */
int gld_sumQueryCounters(ctx, queryHandle)
  int ctx;
  int *queryHandle;
{
  uint entryLane2;
  uint entryLane1;
  uint entryLane0;
  uint entrySumLow;
  uint *poolEntryCursor;
  uint endianBits;
  uint lane2;
  uint lane3;
  uint sumHigh;
  uint sumLow;
  int entrySumHigh;
  uint pipeCount;
  uint lane1;
  uint extraCount;
  uint *resultSlot;
  uint entryLane3;
  int *queryPool;
  bool carry;
  int entriesLeft;
  
  pipeCount = *(uint *)(ctx + 0x2610);
  queryPool = *(int **)(ctx + 0x224);
  endianBits = *(uint *)(ctx + 0x154) & 0x30000;
  resultSlot = (uint *)(queryPool + *queryHandle * 8 + 0x84);
  if ((pipeCount == 1) && (*(int *)(ctx + 0x261c) == 2)) {
    pipeCount = 2;
  }
  if (endianBits == 0x10000) {
    sumLow = *resultSlot << 0x10 | *resultSlot >> 0x10;
    lane1 = resultSlot[4] << 0x10 | resultSlot[4] >> 0x10;
    lane2 = resultSlot[2] << 0x10 | resultSlot[2] >> 0x10;
    lane3 = resultSlot[3] << 0x10 | resultSlot[3] >> 0x10;
  }
  else {
    sumLow = *resultSlot;
    lane1 = resultSlot[4];
    lane2 = resultSlot[2];
    lane3 = resultSlot[3];
  }
  extraCount = resultSlot[1];
  sumHigh = 0;
  if (1 < pipeCount) {
    carry = CARRY4(sumLow,lane1);
    sumLow = sumLow + lane1;
    sumHigh = (uint)carry;
  }
  if (2 < pipeCount) {
    carry = CARRY4(sumLow,lane2);
    sumLow = sumLow + lane2;
    sumHigh = sumHigh + carry;
  }
  if (3 < pipeCount) {
    carry = CARRY4(sumLow,lane3);
    sumLow = sumLow + lane3;
    sumHigh = sumHigh + carry;
  }
  if (extraCount != 0) {
    carry = CARRY4(sumLow,extraCount);
    sumLow = sumLow + extraCount;
    sumHigh = sumHigh + carry;
  }
  if (*queryPool != 0) {
    poolEntryCursor = (uint *)(queryPool + 4);
    entrySumHigh = 0;
    entriesLeft = 0x10;
    entrySumLow = 0;
    do {
      if (endianBits == 0x10000) {
        entryLane0 = *poolEntryCursor << 0x10 | *poolEntryCursor >> 0x10;
        entryLane1 = poolEntryCursor[4] << 0x10 | poolEntryCursor[4] >> 0x10;
        entryLane2 = poolEntryCursor[2] << 0x10 | poolEntryCursor[2] >> 0x10;
        entryLane3 = poolEntryCursor[3] << 0x10 | poolEntryCursor[3] >> 0x10;
      }
      else {
        entryLane0 = *poolEntryCursor;
        entryLane1 = poolEntryCursor[4];
        entryLane2 = poolEntryCursor[2];
        entryLane3 = poolEntryCursor[3];
      }
      carry = CARRY4(entrySumLow,entryLane0);
      entrySumLow = entrySumLow + entryLane0;
      entrySumHigh = entrySumHigh + (uint)carry;
      if (1 < pipeCount) {
        carry = CARRY4(entrySumLow,entryLane1);
        entrySumLow = entrySumLow + entryLane1;
        entrySumHigh = entrySumHigh + (uint)carry;
      }
      if (2 < pipeCount) {
        carry = CARRY4(entrySumLow,entryLane2);
        entrySumLow = entrySumLow + entryLane2;
        entrySumHigh = entrySumHigh + (uint)carry;
      }
      if (3 < pipeCount) {
        carry = CARRY4(entrySumLow,entryLane3);
        entrySumLow = entrySumLow + entryLane3;
        entrySumHigh = entrySumHigh + (uint)carry;
      }
      poolEntryCursor = poolEntryCursor + 8;
      entriesLeft = entriesLeft + -1;
    } while (entriesLeft != 0);
    carry = CARRY4(sumLow,entrySumLow);
    sumLow = sumLow + entrySumLow;
    sumHigh = sumHigh + entrySumHigh + (uint)carry;
  }
  *queryPool = 0;
  if (sumHigh != 0) {
    return 0xffffffff;
  }
  return sumLow;
}

/* _gldGetQueryInfo @ 0x2b5a0 (404 bytes) */
int _gldGetQueryInfo(ctx, query, pname, valueOut)
  int ctx;
  int *query;
  int pname;
  int *valueOut;
{
  bool slot0Pending;
  int available;
  int result3;
  int result2;
  uint resultCount;
  int result1;
  int *queryEntry;
  
  resultCount = *(uint *)(ctx + 0x2610);
  available = *(int *)(ctx + GLD_queryPool) + 0x210;
  queryEntry = (int *)(available + *query * 0x20);
  result1 = queryEntry[2];
  result3 = queryEntry[4];
  result2 = queryEntry[3];
  if ((resultCount == 1) && (*(int *)(ctx + 0x261c) == 2)) {
    resultCount = 2;
  }
  slot0Pending = *(int *)(available + *query * 0x20) == -1;
  if ((((slot0Pending) || ((1 < resultCount && (result3 == -1)))) || ((2 < resultCount && (result1 == -1)))) ||
     ((3 < resultCount && (result2 == -1)))) {
    available = 0;
  }
  else {
    available = 1;
  }
  if (pname == 0x8866) {
    available = 0;
    while ((((slot0Pending || ((1 < resultCount && (result3 == -1)))) ||
            (((2 < resultCount && (result1 == -1)) || ((3 < resultCount && (result2 == -1)))))) &&
           (slot0Pending = available != 10000, available = available + 1, slot0Pending))) {
      gld_waitQueryStamp(ctx);
      _usleep(100);
      result3 = queryEntry[4];
      result1 = queryEntry[2];
      result2 = queryEntry[3];
      slot0Pending = *queryEntry == -1;
    }
    available = ((int (*)())gld_sumQueryCounters)(ctx,query);
    *valueOut = available;
  }
  else if (pname == 0x8867) {
    if (available == 0) {
      _gldFlush(ctx);
    }
    *valueOut = available;
  }
  return 0;
}

/* gld_beginQuerySlot @ 0x2b740 (172 bytes) */
void gld_beginQuerySlot(int ctx,int *queryIdPtr,undefined4 passThroughArg3,undefined4 passThroughArg4,undefined4 passThroughArg5,undefined4 passThroughArg6,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  int queryEntry;
  int *r4AfterCall;
  int queryEntries;
  undefined4 *packetCursor;
  int queryPool;
  undefined4 in_LR;
  
  queryPool = *(int *)(ctx + 0x224);
  queryEntries = queryPool + 0x210;
  queryEntry = queryEntries + *queryIdPtr * 0x20;
  *(undefined4 *)(queryEntries + *queryIdPtr * 0x20) = 0xffffffff;
  *(undefined4 *)(queryEntry + 0xc) = 0xffffffff;
  *(undefined4 *)(queryEntry + 4) = 0;
  *(undefined4 *)(queryEntry + 0x10) = 0xffffffff;
  *(undefined4 *)(queryEntry + 8) = 0xffffffff;
  *(int *)(queryPool + 8) = *queryIdPtr;
  packetCursor = *(undefined4 **)(ctx + 0x1dc);
  if (*(undefined4 **)(ctx + 0x1e0) <= packetCursor + 2) {
    staleFprArg1 = (double)gld_submitRing(ctx,0x1000000);
    packetCursor = *(undefined4 **)(ctx + 0x1dc);
    queryIdPtr = r4AfterCall;
  }
  *(undefined4 **)(ctx + 0x1dc) = packetCursor + 2;
  packetCursor[1] = 0;
  *packetCursor = ((unsigned char *)0x000013d6U);
  ((unsigned char *)0x00002b7e)[ctx] = 1;
  ((void (*)())gldValidateState)(ctx + 0x240,queryIdPtr,passThroughArg3,passThroughArg4,passThroughArg5,passThroughArg6,packetCursor,staleFprArg1,staleFprArg2,
               staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,
               (double)CONCAT44(in_LR,(*(unsigned int *)((unsigned char *)&(staleFprArg9) + 4))));
  return;
}

/* gld_emitQueryBeginPacket @ 0x2b7f0 (968 bytes) */
int gld_emitQueryBeginPacket(ctx, writeCursor)
  int ctx;
  uint *writeCursor;
{
  bool zpassOnly;
  uint scratchUint2;
  int *scratchPtr3;
  uint *lastHeader;
  undefined4 stampValue;
  uint scratchUint6;
  uint counterCount;
  int *queryPool;
  undefined4 *packetBody;
  undefined4 *packetCursor;
  uint accumulatedCount;
  undefined4 queryValue;
  undefined4 *queryRecordWord;
  int slotIndex;
  bool carry;
  char reservation;
  byte crField0;
  int scratchInt16;
  
  queryPool = *(int **)(ctx + 0x224);
  queryValue = *(undefined4 *)(ctx + 0x1cf8);
  counterCount = *(uint *)(ctx + 0x2610);
  queryRecordWord = (undefined4 *)**(undefined4 **)(ctx + 0x234);
  scratchUint6 = *(uint *)(ctx + 0x154) & 0x30000;
  if ((queryPool != (int *)0x0) && (((unsigned char *)0x00002b7e)[ctx] != '\0')) {
    zpassOnly = *(int *)(ctx + 0x261c) != 2;
    if ((counterCount == 1) && (!zpassOnly)) {
      counterCount = 2;
    }
    if (*queryPool == 0) {
      scratchInt16 = 0x10;
      scratchPtr3 = queryPool;
      do {
        scratchPtr3[4] = 0;
        scratchPtr3[8] = 0;
        scratchPtr3[6] = 0;
        scratchPtr3[7] = 0;
        scratchPtr3 = scratchPtr3 + 8;
        scratchInt16 = scratchInt16 + -1;
      } while (scratchInt16 != 0);
      slotIndex = 0;
      scratchInt16 = 0;
      queryPool[1] = 1;
    }
    else {
      slotIndex = queryPool[1];
      queryPool[1] = slotIndex + 1U & 0xf;
      accumulatedCount = queryPool[queryPool[2] * 8 + 0x85];
      if (scratchUint6 == 0x10000) {
        scratchUint2 = queryPool[slotIndex * 8 + 4] << 0x10 | (uint)queryPool[slotIndex * 8 + 4] >> 0x10;
      }
      else {
        scratchUint2 = queryPool[slotIndex * 8 + 4];
      }
      scratchInt16 = slotIndex * 0x20;
      if ((scratchUint2 != 0) && (carry = CARRY4(accumulatedCount,scratchUint2), accumulatedCount = accumulatedCount + scratchUint2, carry)) {
        accumulatedCount = 0xffffffff;
      }
      if (1 < counterCount) {
        if (scratchUint6 == 0x10000) {
          scratchUint2 = queryPool[slotIndex * 8 + 8] << 0x10 | (uint)queryPool[slotIndex * 8 + 8] >> 0x10;
        }
        else {
          scratchUint2 = queryPool[slotIndex * 8 + 8];
        }
        if ((scratchUint2 != 0) && (carry = CARRY4(accumulatedCount,scratchUint2), accumulatedCount = accumulatedCount + scratchUint2, carry)) {
          accumulatedCount = 0xffffffff;
        }
      }
      if (2 < counterCount) {
        if (scratchUint6 == 0x10000) {
          scratchUint2 = queryPool[slotIndex * 8 + 6] << 0x10 | (uint)queryPool[slotIndex * 8 + 6] >> 0x10;
        }
        else {
          scratchUint2 = queryPool[slotIndex * 8 + 6];
        }
        if ((scratchUint2 != 0) && (carry = CARRY4(accumulatedCount,scratchUint2), accumulatedCount = accumulatedCount + scratchUint2, carry)) {
          accumulatedCount = 0xffffffff;
        }
      }
      scratchUint2 = accumulatedCount;
      if (3 < counterCount) {
        if (scratchUint6 == 0x10000) {
          scratchUint6 = queryPool[slotIndex * 8 + 7] << 0x10 | (uint)queryPool[slotIndex * 8 + 7] >> 0x10;
        }
        else {
          scratchUint6 = queryPool[slotIndex * 8 + 7];
        }
        if (scratchUint6 != 0) {
          scratchUint2 = 0xffffffff;
          if (!CARRY4(scratchUint6,accumulatedCount)) {
            scratchUint2 = scratchUint6 + accumulatedCount;
          }
        }
      }
      queryPool[queryPool[2] * 8 + 0x85] = scratchUint2;
    }
    scratchPtr3 = queryRecordWord + 4;
    *(undefined4 *)((int)queryPool + scratchInt16 + 0x1c) = 0;
    *(undefined4 *)((int)queryPool + scratchInt16 + 0x10) = 0;
    *(undefined4 *)((int)queryPool + scratchInt16 + 0x20) = 0;
    *(undefined4 *)((int)queryPool + scratchInt16 + 0x18) = 0;
    do {
      if (reservation != '\0') {
        scratchInt16 = storeWordConditionalIndexed(*scratchPtr3 + 0x10000,0,scratchPtr3);
        *scratchPtr3 = scratchInt16;
        crField0 = 2;
      }
    } while (!(bool)(crField0 >> 1 & 1));
    packetBody = (undefined4 *)((uint)(writeCursor + 0xb) & 0xffffffe0);
    packetCursor = packetBody + 4;
    *writeCursor = (((int)packetBody - (int)writeCursor) + -8) * 0x4000 | 0xc0001000;
    packetBody[-1] = (int)packetBody - (int)writeCursor;
    lastHeader = *(uint **)(ctx + 0x1d8);
    *lastHeader = (int)packetBody - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x1d8) = packetBody;
    *packetBody = 0x3b000000;
    stampValue = *queryRecordWord;
    packetBody[2] = 1;
    packetBody[3] = slotIndex;
    packetBody[1] = stampValue;
    if (zpassOnly) {
      if (counterCount != 0) {
        scratchUint6 = 0;
        do {
          *packetCursor = ((unsigned char *)0x000010b2U);
          packetCursor[2] = ((unsigned char *)0x000013d7U);
          packetCursor[3] = 0;
          packetCursor[1] = 1 << (scratchUint6 & 0x3f);
          scratchUint6 = scratchUint6 + 1;
          packetCursor = packetCursor + 4;
          counterCount = counterCount - 1;
        } while (counterCount != 0);
      }
      writeCursor = packetCursor + 2;
      *packetCursor = ((unsigned char *)0x000010b2U);
      packetCursor[1] = 0xf;
    }
    else {
      packetBody[5] = 0;
      packetBody[4] = ((unsigned char *)0x000013c5U);
      scratchUint6 = 0;
      scratchInt16 = 2;
      queryRecordWord = packetBody + 6;
      do {
        packetBody = queryRecordWord;
        *packetBody = ((unsigned char *)0x000012faU);
        packetBody[2] = ((unsigned char *)0x000013d7U);
        packetBody[3] = 0;
        packetBody[1] = 1 << (scratchUint6 & 0x3f);
        scratchUint6 = scratchUint6 + 1;
        scratchInt16 = scratchInt16 + -1;
        queryRecordWord = packetBody + 4;
      } while (scratchInt16 != 0);
      packetBody[4] = ((unsigned char *)0x000012faU);
      packetBody[7] = queryValue;
      writeCursor = packetBody + 8;
      packetBody[5] = 3;
      packetBody[6] = ((unsigned char *)0x000013c5U);
    }
    *queryPool = 1;
  }
  return writeCursor;
}

/* gld_emitStampFencePacket @ 0x2bbc4 (564 bytes) */
void gld_emitStampFencePacket(int ctx,undefined4 *stampSource,undefined4 passThroughArg3,undefined4 passThroughArg4,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  int fenceUpdated;
  undefined4 *packet;
  int *fenceWord;
  uint *ringTailLink;
  undefined4 stampValue;
  uint scratchUint6;
  undefined4 *r4AfterCall;
  undefined4 *param2AfterFlush;
  undefined *staleArgR7;
  uint *staleArgR8;
  int entryWords;
  undefined4 *scratchPtr11;
  undefined4 *writeCursor;
  undefined4 ctxWord1cf8;
  undefined4 *scratchPtr14;
  int scratchInt15;
  int entryCount;
  char reservation;
  byte crField0;
  undefined4 in_LR;
  
  entryCount = *(int *)(ctx + 0x2610);
  scratchInt15 = *(int *)(ctx + 0x261c);
  ctxWord1cf8 = *(undefined4 *)(ctx + 0x1cf8);
  scratchPtr14 = (undefined4 *)**(undefined4 **)(ctx + 0x234);
  if (entryCount == 1) {
    if (scratchInt15 == 2) {
      entryCount = 2;
      entryWords = 8;
    }
    else {
      entryWords = 4;
    }
  }
  else {
    entryWords = entryCount << 2;
  }
  fenceWord = scratchPtr14 + 4;
  do {
    if (reservation != '\0') {
      fenceUpdated = storeWordConditionalIndexed(*fenceWord + 0x10000,0,fenceWord);
      *fenceWord = fenceUpdated;
      crField0 = 2;
    }
  } while (!(bool)(crField0 >> 1 & 1));
  staleArgR8 = *(uint **)(ctx + 0x1dc);
  param2AfterFlush = stampSource;
  if (*(uint **)(ctx + 0x1e0) <= staleArgR8 + entryWords + 0x15) {
    staleFprArg1 = (double)gld_submitRing(ctx,0x1000000);
    staleArgR8 = *(uint **)(ctx + 0x1dc);
    param2AfterFlush = r4AfterCall;
  }
  staleArgR7 = (undefined *)0x0;
  packet = (undefined4 *)((uint)(staleArgR8 + 0xb) & 0xffffffe0);
  writeCursor = packet + 4;
  *staleArgR8 = (((int)packet - (int)staleArgR8) + -8) * 0x4000 | 0xc0001000;
  packet[-1] = (int)packet - (int)staleArgR8;
  ringTailLink = *(uint **)(ctx + 0x1d8);
  scratchPtr11 = (undefined4 *)*ringTailLink;
  *ringTailLink = (int)packet - (int)ringTailLink >> 2 | (uint)scratchPtr11;
  *(undefined4 **)(ctx + 0x1d8) = packet;
  *packet = 0x3b000000;
  stampValue = *scratchPtr14;
  packet[2] = 0;
  packet[1] = stampValue;
  packet[3] = *stampSource;
  if (scratchInt15 == 2) {
    packet[5] = 0;
    packet[4] = ((unsigned char *)0x000013c5U);
    scratchUint6 = 0;
    staleArgR7 = ((unsigned char *)0x000012faU);
    staleArgR8 = (uint *)((int)((unsigned char *)0x0) + 1);
    scratchInt15 = 2;
    scratchPtr11 = packet + 6;
    do {
      scratchPtr14 = scratchPtr11;
      *scratchPtr14 = ((unsigned char *)0x000012faU);
      scratchPtr14[2] = ((unsigned char *)0x000013d7U);
      scratchPtr14[3] = 0;
      scratchPtr14[1] = 1 << (scratchUint6 & 0x3f);
      scratchUint6 = scratchUint6 + 1;
      scratchPtr11 = scratchPtr14 + 4;
      scratchInt15 = scratchInt15 + -1;
    } while (scratchInt15 != 0);
    *scratchPtr11 = ((unsigned char *)0x000012faU);
    scratchPtr14[7] = ctxWord1cf8;
    writeCursor = scratchPtr14 + 8;
    scratchPtr14[5] = 3;
    scratchPtr14[6] = ((unsigned char *)0x000013c5U);
  }
  else {
    if (entryCount != 0) {
      scratchUint6 = 0;
      staleArgR7 = ((unsigned char *)0x000010b2U);
      staleArgR8 = (uint *)((int)((unsigned char *)0x0) + 1);
      scratchPtr11 = (undefined4 *)0x0;
      do {
        *writeCursor = ((unsigned char *)0x000010b2U);
        writeCursor[2] = ((unsigned char *)0x000013d7U);
        writeCursor[3] = 0;
        writeCursor[1] = 1 << (scratchUint6 & 0x3f);
        scratchUint6 = scratchUint6 + 1;
        writeCursor = writeCursor + 4;
        entryCount = entryCount + -1;
      } while (entryCount != 0);
    }
    *writeCursor = ((unsigned char *)0x000010b2U);
    writeCursor[1] = 0xf;
    writeCursor = writeCursor + 2;
  }
  *(undefined4 **)(ctx + 0x1dc) = writeCursor;
  ((unsigned char *)0x00002b7e)[ctx] = 0;
  ((void (*)())gldValidateState)(ctx + 0x240,param2AfterFlush,passThroughArg3,passThroughArg4,staleArgR7,staleArgR8,scratchPtr11,staleFprArg1,staleFprArg2,
               staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,
               (double)CONCAT44(in_LR,(*(unsigned int *)((unsigned char *)&(staleFprArg9) + 4))));
  return;
}

/* gld_ensureRingSpace @ 0x2be00 (88 bytes) */
int gld_ensureRingSpace(stream, wordCount)
  int stream;
  int wordCount;
{
  int writeCursor;
  int glContext;
  
  glContext = *(int *)(stream + 4);
  writeCursor = *(int *)(glContext + 0x1dc);
  if (*(uint *)(glContext + 0x1e0) <= (uint)(wordCount * 4 + writeCursor)) {
    gld_submitRing(glContext,0x1000000);
    writeCursor = *(int *)(glContext + 0x1dc);
  }
  return writeCursor;
}

/* gld_setStreamCursor @ 0x2be60 (12 bytes) */
int gld_setStreamCursor(stream, cursor)
  int stream;
  undefined4 cursor;
{
  *(undefined4 *)(*(int *)(stream + 4) + 0x1dc) = cursor;
  return;
}

/* gld_getStreamCurrent @ 0x2be70 (8 bytes) */
int gld_getStreamCurrent(stream)
  int stream;
{
  return *(undefined4 *)(0x00002748 + stream + 4);
}

/* noop_2be80 @ 0x2be80 (4 bytes) */
int noop_2be80()
{
  return;
}

/* gld_forwardToStream @ 0x2be90 (12 bytes) */
int gld_forwardToStream(ctx, unusedArg2, passThroughArg3, passThroughArg4, passThroughArg5, passThroughArg6, passThroughArg7)
  int ctx;
  undefined4 unusedArg2;
  undefined4 passThroughArg3;
  undefined4 passThroughArg4;
  undefined4 passThroughArg5;
  undefined4 passThroughArg6;
  undefined4 passThroughArg7;
{
  return gld_setPrimitiveInputRegisters(ctx + 0x240,passThroughArg3,passThroughArg3,passThroughArg4,passThroughArg5,passThroughArg6,passThroughArg7);
}

/* gldTrimVertexCountToPrimitive @ 0x2bea0 (116 bytes) */
int gldTrimVertexCountToPrimitive(ctx, mode, count)
  undefined4 ctx;
  uint mode;
  uint count;
{
  int modeBitCount;
  
  modeBitCount = (mode >> 3 & 1) + (mode >> 2 & 1) + (mode >> 1 & 1) + (mode & 1);
  if (modeBitCount == 2) {
    return count;
  }
  if (modeBitCount == 0) {
    return count;
  }
  if (mode == 2) {
    return count;
  }
  if (modeBitCount == 3) {
    return count & 0xfffffffc;
  }
  if (mode == 4) {
    return ((int)count / 3) * 3;
  }
  return count & 0xfffffffe;
}

/* gldTrimVertexCountToPrimitiveMin @ 0x2bf30 (180 bytes) */
int gldTrimVertexCountToPrimitiveMin(ctx, mode, count)
  undefined4 ctx;
  undefined4 mode;
  uint count;
{
  uint wholeTriangleVertices;
  
  switch(mode) {
  case 0:
    if (count != 0) {
      return count;
    }
    break;
  case 1:
    if (1 < (int)(count & 0xfffffffe)) {
      return count & 0xfffffffe;
    }
    break;
  case 2:
  case 3:
    if (1 < (int)count) {
      return count;
    }
    break;
  case 4:
    wholeTriangleVertices = ((int)count / 3) * 3;
    if (2 < (int)wholeTriangleVertices) {
      return wholeTriangleVertices;
    }
    break;
  case 5:
  case 6:
  case 9:
    if (2 < (int)count) {
      return count;
    }
    break;
  case 7:
    if (3 < (int)(count & 0xfffffffc)) {
      return count & 0xfffffffc;
    }
    break;
  case 8:
    if (3 < (int)(count & 0xfffffffe)) {
      return count & 0xfffffffe;
    }
  }
  return 0;
}

/* gld_revalidateStreamProgram @ 0x2c020 (148 bytes) */
void gld_revalidateStreamProgram(int stream,int streamFlag,undefined4 passThroughArg3,undefined4 passThroughArg4,undefined4 passThroughArg5,undefined4 passThroughArg6,uint scratchUint7,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint oldProgramFlags;
  int forcedState;
  double staleStackArg_ffffffb8;
  
  oldProgramFlags = *(uint *)(stream + 0x1874);
  *(uint *)(stream + 0x1874) = oldProgramFlags & 0x3fffffff;
  if ((streamFlag == 0) && (scratchUint7 = *(uint *)(stream + 0x1928) & 2, scratchUint7 != 0)) {
    forcedState = 1;
    *(uint *)(stream + 0x1874) = oldProgramFlags & 0x3fffffff | 0x80000000;
  }
  else {
    forcedState = 0;
  }
  if (forcedState != *(int *)(stream + 0x192c)) {
    ((void (*)())ffvpValidateProgramForced)(stream,streamFlag,passThroughArg3,passThroughArg4,passThroughArg5,passThroughArg6,scratchUint7,staleFprArg1,staleFprArg2,staleFprArg3,
                 staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffb8);
    gldClearHwTclFlag(stream);
    *(int *)(stream + 0x192c) = forcedState;
  }
  *(uint *)(stream + 0x1928) = *(uint *)(stream + 0x1928) & 0xfffffffe;
  return;
}

/* gld_emitVapStreamControl @ 0x2c0c0 (180 bytes) */
int gld_emitVapStreamControl(ctx, cmd)
  int ctx;
  uint *cmd;
{
  uint headerCountBits;
  int scratchInt2;
  uint *cursorA;
  int scratchInt4;
  uint *cursorB;
  uint pairsLeft;
  uint pairCount;
  
  cursorA = cmd + 1;
  pairCount = *(int *)(ctx + 0x267c) + 1U >> 1;
  headerCountBits = (pairCount - 1) * 0x10000;
  *cmd = headerCountBits | 0x854;
  if (pairCount != 0) {
    scratchInt4 = 0;
    pairsLeft = pairCount;
    do {
      scratchInt2 = scratchInt4 * 4;
      scratchInt4 = scratchInt4 + 1;
      *cursorA = *(uint *)(scratchInt2 + *(int *)(ctx + 0x2680));
      cursorA = cursorA + 1;
      pairsLeft = pairsLeft - 1;
    } while (pairsLeft != 0);
  }
  cursorB = cursorA + 1;
  *cursorA = headerCountBits | 0x878;
  if (pairCount != 0) {
    scratchInt4 = 0;
    do {
      scratchInt2 = scratchInt4 * 4;
      scratchInt4 = scratchInt4 + 1;
      *cursorB = *(uint *)(scratchInt2 + *(int *)(ctx + 0x2684));
      cursorB = cursorB + 1;
      pairCount = pairCount - 1;
    } while (pairCount != 0);
  }
  *cursorB = 0x82d;
  cursorB[1] = *(uint *)(0x000026c8 + ctx + 4);
  return cursorB + 2;
}

/* gld_emitStreamAddressRegisters @ 0x2c180 (164 bytes) */
int gld_emitStreamAddressRegisters(ctx, packetPtr)
  int ctx;
  uint *packetPtr;
{
  int scratchInt1;
  int addrPairIndex;
  int pairCount;
  int addrByteOffset;
  uint *cursor;
  
  cursor = packetPtr + 1;
  pairCount = (int)((*(uint *)(ctx + 0x26d0) & 0x1f) + 1) >> 1;
  *packetPtr = (pairCount * 3 + -1) * 0x10000 | 0x831;
  if (pairCount != 0) {
    addrPairIndex = 0;
    addrByteOffset = 0;
    if (pairCount == 0) {
      pairCount = 1;
    }
    do {
      scratchInt1 = addrPairIndex * 4;
      addrPairIndex = addrPairIndex + 1;
      *cursor = *(uint *)(scratchInt1 + *(int *)(ctx + 0x26d4));
      cursor[1] = *(uint *)(*(int *)(ctx + 0x26d8) + addrByteOffset);
      scratchInt1 = *(int *)(ctx + 0x26d8) + addrByteOffset;
      addrByteOffset = addrByteOffset + 8;
      cursor[2] = *(uint *)(scratchInt1 + 4);
      cursor = cursor + 3;
      pairCount = pairCount + -1;
    } while (pairCount != 0);
  }
  *cursor = 0x830;
  cursor[1] = *(uint *)(ctx + 0x26d0);
  return cursor + 2;
}

/* gld_validateStreamState @ 0x2c230 (1144 bytes) */
int gld_validateStreamState(stream, dirtyBits)
  int stream;
  uint *dirtyBits;
{
  undefined4 gld_bufferEnumToIndexResult;
  ushort *bufferEnumPtr;
  bool moreBuffers;
  code *setCurrentFn;
  uint *lastHeader;
  undefined4 scratchUint5;
  undefined4 *statePacket;
  undefined4 *scalarBlockPtr;
  undefined4 scalarCount;
  undefined4 structOutPtr;
  undefined4 structOutSize;
  uint scratchUint7;
  uint scratchUint8;
  int engineObjectsAlias;
  int engineObjects;
  int bufferSlot;
  int scratchInt12;
  int bufferEnumOffset;
  undefined4 scalarIn0;
  uint scalarIn1;
  undefined4 scalarIn2;
  undefined4 scalarIn3;
  
  scratchUint8 = dirtyBits[3];
  engineObjects = *(int *)(stream + 4);
  scratchUint7 = (uint)((scratchUint8 & 0x10000000) != *(uint *)(stream + 0x2780));
  if ((((*dirtyBits == 0) && (dirtyBits[1] == 0)) && (dirtyBits[2] == 0)) &&
     ((((scratchUint8 & 0xffefffff) == 0 && (dirtyBits[4] == 0)) && (scratchUint7 == 0)))) {
loopSetScratchUint7:
    scratchUint7 = *(uint *)(stream + 0x2488);
  }
  else {
    if ((((dirtyBits[2] & 0x3f000008) != 0) || ((scratchUint8 & 0x4c00003) != 0)) ||
       ((*(char *)(engineObjects + 0x2a43) != '\0' || (scratchUint7 != 0)))) {
      gldUpdateHwTclState(stream,dirtyBits);
      gldEmitTclModeRegs(stream);
    }
    if (*(char *)(engineObjects + 0x20) == '\0') {
      gld_buildActiveUnitList(stream);
    }
    ffvpSelectLitProgramVariant(stream);
    gldClearHwTclFlag(stream);
    scratchUint8 = *dirtyBits;
    if (((scratchUint8 & 0x20000000) != 0) || (*(char *)(engineObjects + 0x2a43) != '\0')) {
      gld_emitDirtyStatePackets(engineObjects,0);
      scratchUint8 = *dirtyBits;
    }
    if ((((scratchUint8 & 0x180) != 0) || (*(char *)(engineObjects + 0x2a43) != '\0')) &&
       (*(int *)(engineObjects + 0x150) == 0)) {
      engineObjectsAlias = *(int *)(stream + 4);
      bufferSlot = 0;
      bufferEnumOffset = *(int *)(engineObjectsAlias + 0x10);
      scratchInt12 = stream;
      do {
        bufferEnumPtr = (ushort *)(((unsigned char *)0x00002dba) + bufferEnumOffset);
        bufferEnumOffset = bufferEnumOffset + 2;
        gld_bufferEnumToIndexResult = gld_bufferEnumToIndex((uint)*bufferEnumPtr,*(undefined4 *)(engineObjectsAlias + 0x154));
        moreBuffers = bufferSlot != 3;
        bufferSlot = bufferSlot + 1;
        *(undefined4 *)(scratchInt12 + 0x2460) = gld_bufferEnumToIndexResult;
        scratchInt12 = scratchInt12 + 4;
      } while (moreBuffers);
      statePacket = (undefined4 *)(**(code **)(stream + 0x2758))(stream,0x22d);
      scratchInt12 = *(int *)(stream + 0x2460);
      *(undefined4 **)(0x00002748 + stream + 4) = statePacket;
      if (((scratchInt12 == 1) && (scratchUint8 = *(uint *)(engineObjectsAlias + 0x154), (scratchUint8 & 0x800) == 0)) &&
         (((scratchUint8 & 0x20) != 0 && ((scratchUint8 & 0x400) != 0)))) {
        (**(code **)(stream + 0x275c))(stream,statePacket);
        if (*(int *)(engineObjectsAlias + 0x1e4) + 0x28U < *(uint *)(engineObjectsAlias + 0x1dc)) {
          gld_submitRing(engineObjectsAlias,0x1000000);
        }
        scalarBlockPtr = &scalarIn0;
        scalarCount = 4;
        scratchUint7 = 0xffff3fc0;
        structOutPtr = 0;
        structOutSize = 0;
        scratchUint8 = *(uint *)(engineObjectsAlias + 0x3c) | 0x800;
        *(uint *)(engineObjectsAlias + 0x154) = scratchUint8;
        *(uint *)(engineObjectsAlias + 0x3c) = scratchUint8;
        scalarIn0 = *(undefined4 *)(*(int *)(engineObjectsAlias + 0xf8) + 8);
        scalarIn1 = *(uint *)(engineObjectsAlias + 0x3c) & 0xffff3fc0;
        scalarIn2 = *(undefined4 *)(engineObjectsAlias + 0xfc);
        scalarIn3 = *(undefined4 *)(engineObjectsAlias + 0x100);
        _io_connect_method_scalarI_structureI(*(undefined4 *)(engineObjectsAlias + 4),0,scalarBlockPtr,4,0,0);
        statePacket = (undefined4 *)(**(code **)(stream + 0x2758))(stream,0x22d);
        scratchInt12 = *(int *)(stream + 0x2460);
        *(undefined4 **)(0x00002748 + stream + 4) = statePacket;
      }
      scratchInt12 = gld_needsMultisampleResolve(engineObjectsAlias,scratchInt12,scalarBlockPtr,scalarCount,structOutPtr,structOutSize,scratchUint7);
      if (scratchInt12 == 0) {
        lastHeader = *(uint **)(engineObjectsAlias + 0x1d8);
        *lastHeader = (int)statePacket - (int)lastHeader >> 2 | *lastHeader;
        *(undefined4 **)(engineObjectsAlias + 0x1d8) = statePacket;
        *statePacket = 0x29000000;
        statePacket[1] = *(undefined4 *)(stream + 0x2460);
        statePacket[2] = *(undefined4 *)(stream + 0x2464);
        statePacket[3] = *(undefined4 *)(stream + 0x2468);
        scratchUint5 = *(undefined4 *)(stream + 0x246c);
        statePacket[5] = 0x11;
        statePacket[4] = scratchUint5;
        statePacket[6] = *(undefined4 *)(stream + 0x1ae0);
        statePacket[7] = *(undefined4 *)(stream + 0x1ab0);
      }
      else {
        lastHeader = *(uint **)(engineObjectsAlias + 0x1d8);
        *lastHeader = (int)statePacket - (int)lastHeader >> 2 | *lastHeader;
        *(undefined4 **)(engineObjectsAlias + 0x1d8) = statePacket;
        *statePacket = 0x29000000;
        scratchUint5 = *(undefined4 *)(stream + 0x2460);
        statePacket[4] = 0x11;
        statePacket[5] = 0x10;
        statePacket[2] = 0x11;
        statePacket[3] = 0x11;
        statePacket[1] = scratchUint5;
        statePacket[6] = *(undefined4 *)(stream + 0x1ae0);
        statePacket[7] = *(undefined4 *)(stream + 0x1ab0);
      }
      setCurrentFn = *(code **)(stream + 0x275c);
      *(undefined4 **)(0x00002748 + stream + 4) = statePacket + 0x39;
      /* issue #64 live-repro (crash #10, the long-running "iVar5+0x1dc=1" hunt): this indirect
       * dispatch through the per-instance table at 0x275c supplied only 1 of 2 real arguments -
       * a dropped-call-args bug matching the same class already fixed for arbEmitRecord2Src_op01's own
       * dispatch calls. The line right above sets up *(0x2748+stream+4) - the exact "current
       * write pointer" value the real target expects as its 2nd argument - but never actually
       * passes it; a sibling call site to this SAME dispatch slot (gldEmitProgramConstants, part_011.c:8826)
       * shows the correct, complete shape: `(*fn)(stream, *(int*)(0x2748+stream+4));`. Live-
       * verified via a hardware watchpoint installed from the moment CGLCreateContext returns
       * (tracking the target field through ~15 legitimate updates via gld_setStreamCursor): on real
       * hardware, this exact call resolves to gld_setStreamCursor(stream, dirtyBits) - a simple setter,
       * `*(*(stream+4)+0x1dc) = dirtyBits;` - and with no 2nd argument ever pushed by the caller,
       * dirtyBits read whatever was left in r4 by earlier, unrelated code: the literal integer 1.
       * That single wild write is what every downstream consumer (gld_ensureRingSpace, gld_emitUnitObjectPacket)
       * was tripping over. Fixed by passing the value the call site had already prepared. */
      (*setCurrentFn)(stream,*(undefined4 *)(0x00002748 + stream + 4));
    }
    if (*(short *)((int)dirtyBits + 6) != 0) {
      ((int (*)())gld_emitUnitObjectPackets)(stream,dirtyBits);
    }
    if (*(char *)(stream + 0x2435) == '\0') goto loopSetScratchUint7;
    *(int *)(stream + 0x2440) = stream + 0x249c;
    *(int *)(stream + 0x2444) = stream + 0x24bc;
    *(undefined4 *)(stream + 0x2494) = 0;
    scratchUint7 = *(uint *)(stream + 0x2488) | 4;
    *(uint *)(stream + 0x2488) = scratchUint7;
  }
  if (((scratchUint7 & 4) == 0) && (*(char *)(stream + 0x247d) == '\0')) {
    if (*(char *)(stream + 0x2595) == '\0') {
      scratchUint7 = dirtyBits[3] & 0x100000;
    }
    else {
      scratchUint7 = *(uint *)(*(int *)(engineObjects + 0x14) + 0x120);
    }
    if ((scratchUint7 == 0) && ((*dirtyBits & 0x800000) == 0)) goto checkDirtyBits;
  }
  ((int (*)())gld_buildVertexStreamCache)(stream);
checkDirtyBits:
  if ((((dirtyBits[3] & 0x100000) != 0) || ((*(uint *)(stream + 0x2488) & 4) != 0)) ||
     (*(char *)(stream + 0x247d) != '\0')) {
    gld_buildVertexStreamLayout(stream);
  }
  return;
}

/* gld_buildHardwareStateBuffer @ 0x2c6c0 (184 bytes) */
int gld_buildHardwareStateBuffer(ctx)
  int ctx;
{
  undefined4 *stateBuffer;
  
  stateBuffer = *(undefined4 **)(ctx + 0x208);
  stateBuffer[7] = stateBuffer[7] | 1;
  *(code **)(ctx + 0x2998) = gld_getStreamCurrent;
  *(code **)(ctx + 0x299c) = noop_2be80;
  *(undefined4 **)(ctx + 0x298c) = stateBuffer + 8;
  gldEmitHardwareState(ctx + 0x240);
  *stateBuffer = *(undefined4 *)(ctx + 0x1d20);
  stateBuffer[1] = *(undefined4 *)(ctx + 0x1cf0);
  stateBuffer[5] = *(int *)(ctx + 0x298c) - (int)(stateBuffer + 8) >> 2;
  *(code **)(ctx + 0x299c) = gld_setStreamCursor;
  *(code **)(ctx + 0x2998) = gld_ensureRingSpace;
  if ((uint)stateBuffer[4] < (uint)stateBuffer[5]) {
                    
    _exit(1);
  }
  return;
}

/* gld_initContextHardwareState @ 0x2c790 (932 bytes) */
int gld_initContextHardwareState(ctx, pixelFormat)
  int ctx;
  int pixelFormat;
{
  undefined4 allocation;
  int loopIndex;
  int *vectorConstTable;
  undefined *vectorConstArea;
  uint scratchUint3;
  int *scratchPtr4;
  undefined1 window_mode_to_ati_formatResult;
  undefined4 scratchUint5;
  uint permuteIndex;
  int scratchInt8;
  uint maskShiftBias;
  int engineBase;
  int scratchInt11;
  double staleFprArg1;
  double staleFpr2;
  double staleFpr3;
  double staleFpr4;
  double staleFpr5;
  double staleFpr6;
  double staleFpr7;
  double staleFpr8;
  double staleStackArg_ffffff78;
  double staleStackArg_ffffff80;
  double staleStackArg_ffffff88;
  double staleStackArg_ffffff90;
  double staleStackArg_ffffff98;
  undefined4 queryOutCount;
  undefined4 initParam0;
  undefined4 initParam1;
  undefined4 initParam2;
  undefined4 initParam3;
  undefined4 initParam4;
  undefined4 queryResult0;
  undefined4 queryResult1;
  undefined4 queryResult2;
  undefined4 queryResult3;
  undefined4 queryResult4;
  
  engineBase = ctx + 0x240;
  _memset(engineBase,0,0x2950);
  ((unsigned char *)0x00002b7d)[ctx] = 0;
  ((unsigned char *)0x00002b7c)[ctx] = 1;
  *(uint *)(ctx + 0x258c) = *(uint *)(ctx + 0x258c) & 0xfffffffc | 1;
  window_mode_to_ati_formatResult = window_mode_to_ati_format(*(undefined4 *)(ctx + 0x154));
  ((unsigned char *)0x00002b7f)[ctx] = window_mode_to_ati_formatResult;
  *(int *)(ctx + 0x2680) = ctx + 0x26dc;
  *(int *)(ctx + 0x2684) = ctx + 0x26fc;
  *(undefined4 *)(ctx + 0x1ec) = 0;
  *(undefined4 *)(ctx + 0x1f0) = 0;
  allocation = _malloc(0x44);
  *(undefined4 *)(((unsigned char *)0x000027cc) + ctx) = allocation;
  _memset(allocation,0,0x44);
  allocation = _malloc(0x44);
  *(undefined4 *)(0x000027d0 + ctx) = allocation;
  _memset(allocation,0,0x44);
  gld_resetNotificationSettings(ctx);
  *(undefined4 *)(ctx + 0x2a64) = *(undefined4 *)(pixelFormat + 0x30);
  if (*(char *)(ctx + 0x2a6a) == '\0') {
    gld_postDisplayNotification(ctx);
  }
  *(undefined1 *)(ctx + 0x2a43) = 1;
  *(undefined1 *)(ctx + 0x2a5e) = 1;
  gld_updateSampleConfig(ctx);
  *(undefined4 *)(ctx + 0x261c) = 1;
  *(undefined4 *)(ctx + 0x2610) = 1;
  scratchUint5 = 0;
  *(undefined4 *)(ctx + 0x29d8) = 0xfff0;
  queryResult2 = DAT_001aa504;
  queryResult0 = DAT_001aa4fc;
  queryOutCount = 5;
  queryResult1 = DAT_001aa500;
  queryResult3 = DAT_001aa508;
  queryResult4 = DAT_001aa50c;
  _io_connect_method_scalarI_scalarO(*(undefined4 *)(ctx + 4),0x14,0,0,&queryResult0,&queryOutCount);
  *(undefined4 *)(ctx + 0x2614) = queryResult1;
  *(undefined4 *)(ctx + 0x2618) = queryResult2;
  *(undefined4 *)(ctx + 0x261c) = queryResult3;
  *(undefined4 *)(ctx + 0x2610) = queryResult0;
  scratchInt8 = *(int *)(ctx + 0x1e4);
  *(int *)(ctx + 0x1dc) = scratchInt8 + 0x20;
  *(int *)(ctx + 0x1d8) = scratchInt8 + 0x1c;
  *(int *)(ctx + 0x1e0) = scratchInt8 + 0x20 + *(int *)(scratchInt8 + 0x10) * 4 + -0x94;
  *(undefined4 *)(scratchInt8 + 0x1c) = 0;
  *(undefined4 *)(ctx + 0x1ec) = 0;
  *(undefined4 *)(ctx + 0x1f0) = 0;
  gld_initContextDispatch(ctx);
  atifsInit(engineBase);
  staleFprArg1 = (double)extvsSelectHandlerTables(engineBase);
  *(undefined4 *)(((unsigned char *)0x00002b74) + ctx) = 0;
  *(undefined4 *)(ctx + 0x26a0) = 0;
  *(undefined4 *)(ctx + 0x26b0) = 0;
  *(undefined4 *)(((unsigned char *)0x00002b78) + ctx) = 0;
  scratchInt11 = 0x10;
  scratchInt8 = engineBase;
  do {
    *(undefined1 *)(scratchInt8 + 0x2784) = 0;
    scratchInt8 = scratchInt8 + 1;
    scratchInt11 = scratchInt11 + -1;
  } while (scratchInt11 != 0);
  ((unsigned char *)0x00002b82)[ctx] = 0;
  vectorConstArea = PTR_DAT_001e8994;
  *(undefined4 *)(0x000026c8 + ctx) = 7;
  permuteIndex = 0;
  *(undefined1 *)(ctx + 0x2a43) = 1;
  *(undefined1 *)(ctx + 0x26bd) = 1;
  scratchInt8 = 0x10;
  vectorConstTable = (int *)((uint)(vectorConstArea + 0xc) & 0xfffffff3);
  *(int **)PTR_DAT_001e88cc = vectorConstTable;
  scratchPtr4 = vectorConstTable;
  do {
    scratchUint3 = permuteIndex << 8 | permuteIndex;
    permuteIndex = permuteIndex + 1;
    scratchUint3 = scratchUint3 | scratchUint3 << 0x10;
    *scratchPtr4 = scratchUint3 + 0x2030001;
    scratchPtr4[3] = scratchUint3 + 0xe0f0c0d;
    scratchPtr4[1] = scratchUint3 + 0x6070405;
    scratchPtr4[2] = scratchUint3 + 0xa0b0809;
    scratchPtr4 = scratchPtr4 + 4;
    scratchInt8 = scratchInt8 + -1;
  } while (scratchInt8 != 0);
  scratchUint3 = 0xffffffff;
  maskShiftBias = 0xffffffa0;
  scratchInt11 = 0x10;
  loopIndex = 0;
  scratchPtr4 = vectorConstTable;
  while( true ) {
    scratchPtr4[0x40] = scratchUint3;
    scratchUint3 = 0xffffffff;
    if ((4 < loopIndex) && (scratchUint3 = 0, loopIndex < 8)) {
      scratchUint3 = 0xffffffff >> (maskShiftBias + 0x40 & 0x3f);
    }
    scratchPtr4[0x41] = scratchUint3;
    scratchUint3 = 0xffffffff;
    if ((8 < loopIndex) && (scratchUint3 = 0, loopIndex < 0xc)) {
      scratchUint3 = 0xffffffff >> (maskShiftBias + 0x20 & 0x3f);
    }
    scratchPtr4[0x42] = scratchUint3;
    scratchUint3 = 0xffffffff;
    if (0xc < loopIndex) {
      scratchUint3 = 0xffffffff >> (maskShiftBias & 0x3f);
    }
    scratchPtr4[0x43] = scratchUint3;
    loopIndex = loopIndex + 1;
    scratchPtr4 = scratchPtr4 + 4;
    maskShiftBias = maskShiftBias + 8;
    scratchInt11 = scratchInt11 + -1;
    if (scratchInt11 == 0) break;
    scratchUint3 = 0xffffffff;
    if ((0 < loopIndex) && (scratchUint3 = 0, loopIndex < 4)) {
      scratchUint3 = 0xffffffff >> (loopIndex * 8 & 0x38U);
    }
  }
  ((unsigned char *)0x00002b88)[ctx] = 1;
  initParam0 = DAT_001aa4e8;
  initParam1 = DAT_001aa4ec;
  initParam4 = DAT_001aa4f8;
  initParam2 = DAT_001aa4f0;
  initParam3 = DAT_001aa4f4;
  ((void (*)())gld_validateDirtyState)(engineBase,&initParam0,scratchUint5,vectorConstTable,permuteIndex,DAT_001aa4f8,DAT_001aa4e8,DAT_001aa4f4,staleFprArg1,
               staleFpr2,staleFpr3,staleFpr4,staleFpr5,staleFpr6,staleFpr7,staleFpr8,staleStackArg_ffffff78,staleStackArg_ffffff80,
               staleStackArg_ffffff88,staleStackArg_ffffff90,staleStackArg_ffffff98);
  ((int (*)())gld_buildHardwareStateBuffer)(ctx);
  return;
}

/* gldContextFreeResources @ 0x2cb40 (200 bytes) */
int gldContextFreeResources(ctx)
  int ctx;
{
  if (*(int *)(((unsigned char *)0x000027cc) + ctx) != 0) {
    _free(*(int *)(((unsigned char *)0x000027cc) + ctx));
  }
  if (*(int *)(0x000027d0 + ctx) != 0) {
    _free(*(int *)(0x000027d0 + ctx));
  }
  if (*(char *)(ctx + 0x2a6a) == '\0') {
    gldRemoveDisplayNotificationObserver(ctx);
  }
  ((int (*)())gld_deleteContextProgramObjects)(ctx);
  if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
    gld_submitRing(ctx,0x1000000);
  }
  thunk_FUN_00054a90(ctx + GLD_commandStream);
  thunk_FUN_000a2330(ctx + GLD_commandStream);
  gldFreeEngineState(ctx);
  if (*(int *)(((unsigned char *)GLD_readScratchBuffer) + ctx) != 0) {
    _vfree(*(int *)(((unsigned char *)GLD_readScratchBuffer) + ctx));
  }
  *(undefined4 *)(((unsigned char *)GLD_readScratchBuffer) + ctx) = 0;
  *(undefined4 *)(((unsigned char *)GLD_readScratchSize) + ctx) = 0;
  return;
}

/* gld_submitRingIfNeeded @ 0x2cc10 (28 bytes) */
int gld_submitRingIfNeeded(ctx)
  int ctx;
{
  if (*(uint *)(ctx + GLD_writeCursor) <= *(int *)(ctx + GLD_ringMap) + 0x28U) {
    return;
  }
  return gld_submitRing(ctx,0x1000000);
}

/* gld_prepareDrawCount: hidden-argument + read-before-write defect (found auditing #70): real stock r9 at entry is
 * a genuine 7th argument (param_7) - the `if (param_4 < 4)` path never touches r9 at all, so it reaches
 * the shared code below still holding whatever the caller passed; the `else` path recomputes it (`param_3
 * & 1`) for its own use before falling into the same shared code. The corpus previously modelled both as
 * the same local `in_r9`, uninitialised on the first path - a real read-before-write. Of the 25 real call
 * sites, only gld_drawVertexArray supplies a genuine non-zero value here (a real field read); every other
 * caller (including this file's own dispatch-wrapper family) passes 0, matching what real stock callers
 * themselves forward. */
/* gld_prepareDrawCount @ 0x2cc30 (276 bytes) */
uint gld_prepareDrawCount(int ctx,undefined4 closeFlag,uint primitiveMode,uint vertexCount,undefined4 extraArg4,undefined4 extraArg5,uint drawFlags,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  int primitiveClassBits;
  uint modeForward;
  uint vertexCountForward;
  uint drawFlagsOrModeBit;
  uint trimmedCount;
  double f1AfterCall;
  double staleStackArg_ffffffa8;

  drawFlagsOrModeBit = drawFlags;
  vertexCountForward = vertexCount;
  if ((int)vertexCount < 4) {
    trimmedCount = ((int (*)())gldTrimVertexCountToPrimitiveMin)(ctx,primitiveMode,vertexCount);
    modeForward = vertexCount;
    staleFprArg1 = f1AfterCall;
  }
  else {
    drawFlagsOrModeBit = primitiveMode & 1;
    primitiveClassBits = (primitiveMode >> 3 & 1) + (primitiveMode >> 2 & 1) + (primitiveMode >> 1 & 1) + drawFlagsOrModeBit;
    modeForward = primitiveMode;
    trimmedCount = vertexCount;
    if (((primitiveClassBits == 2) || (primitiveClassBits == 0)) || (primitiveMode == 2)) goto checkX00002b80;
    if (primitiveClassBits == 3) {
      trimmedCount = vertexCount & 0xfffffffc;
    }
    else if (primitiveMode == 4) {
      trimmedCount = ((int)vertexCount / 3) * 3;
    }
    else {
      trimmedCount = vertexCount & 0xfffffffe;
    }
  }
  if (trimmedCount == 0) {
    return 0;
  }
checkX00002b80:
  if (((unsigned char *)0x00002b80)[ctx] != '\0') {
    staleFprArg1 = (double)gld_setPrimitiveInputRegisters(ctx + GLD_commandStream,primitiveMode,modeForward,vertexCountForward,extraArg4,extraArg5,drawFlagsOrModeBit);
  }
  if (*(int *)(ctx + 0x1b68) != 0) {
    ((void (*)())gld_revalidateStreamProgram)(ctx + GLD_commandStream,primitiveMode,modeForward,vertexCountForward,extraArg4,extraArg5,drawFlagsOrModeBit,staleFprArg1,staleFprArg2,
                 staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffa8);
  }
  *(undefined1 *)(ctx + GLD_inDrawPixels) = 1;
  return trimmedCount;
}

/* gld_emitUnitObjectPacket @ 0x2cd50 (236 bytes) */
int gld_emitUnitObjectPacket(ctx, unitObject, opcodeCount, packetCursor)
  int ctx;
  int unitObject;
  int opcodeCount;
  uint *packetCursor;
{
  int storeResult;
  int *packet;
  bool fenceUpdated;
  uint unitFlags;
  uint *scratchPtr5;
  int *fenceWord;
  char reservation;
  
  if (unitObject == 0) {
    scratchPtr5 = *(uint **)(ctx + 0x1d8);
    *scratchPtr5 = (int)packetCursor - (int)scratchPtr5 >> 2 | *scratchPtr5;
    *(uint **)(ctx + 0x1d8) = packetCursor;
    *packetCursor = opcodeCount * 0x1000000 + 0x16000000;
    return packetCursor + 1;
  }
  packet = (int *)((uint)(packetCursor + 0xb) & 0xffffffe0);
  *packetCursor = (((int)packet - (int)packetCursor) + -8) * 0x4000 | 0xc0001000;
  packet[-1] = (int)packet - (int)packetCursor;
  scratchPtr5 = *(uint **)(ctx + 0x1d8);
  *scratchPtr5 = (int)packet - (int)scratchPtr5 >> 2 | *scratchPtr5;
  *(int **)(ctx + 0x1d8) = packet;
  *packet = opcodeCount * 0x1000000 + 0x6000000;
  packet[1] = **(int **)(unitObject + 0x34);
  fenceWord = (int *)(*(int *)(unitObject + 0x34) + 0x10);
  fenceUpdated = false;
  do {
    if (reservation != '\0') {
      storeResult = storeWordConditionalIndexed(*fenceWord + 0x10000,0,fenceWord);
      *fenceWord = storeResult;
      fenceUpdated = true;
    }
  } while (!fenceUpdated);
  unitFlags = *(uint *)(unitObject + 200);
  packet[2] = *(int *)(unitObject + 0x40);
  if ((unitFlags & 0xc00000) == 0) {
    return (uint *)(packet + 3);
  }
  packet[3] = *(uint *)(unitObject + 0xcc) >> 2 | (uint)*(byte *)(unitObject + 0x38) << 0x18;
  return (uint *)(packet + 4);
}

/* gld_emitUnitObjectPackets @ 0x2ce40 (492 bytes) */
int gld_emitUnitObjectPackets(stream, unitMaskRecord)
  int stream;
  int unitMaskRecord;
{
  uint *ringTailLink;
  undefined4 *packet;
  undefined4 streamCursor;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 *packetEnd;
  int scratchInt4;
  uint formatByte;
  int glContext;
  int scratchInt6;
  uint scratchUint7;
  
  glContext = *(int *)(stream + 4);
  scratchInt6 = glContext;
  for (scratchUint7 = (uint)*(ushort *)(unitMaskRecord + 6); scratchUint7 != 0; scratchUint7 = scratchUint7 >> 1) {
    if (((((scratchUint7 & 1) != 0) && (scratchInt4 = *(int *)(scratchInt6 + 0x18c), scratchInt4 != 0)) &&
        (*(short *)(*(int *)(scratchInt4 + 0x30) + 2) == 0x1902)) && (*(char *)(scratchInt4 + 200) == '\x01')) {
      packet = (undefined4 *)(**(code **)(stream + 0x2758))(stream,0x3fa);
      *(undefined4 **)(0x00002748 + stream + 4) = packet;
      packetEnd = packet + 0x3f8;
      ringTailLink = *(uint **)(glContext + 0x1d8);
      *ringTailLink = (int)packet - (int)ringTailLink >> 2 | *ringTailLink;
      *(undefined4 **)(glContext + 0x1d8) = packet;
      *packet = 0x45000000;
      packet[1] = 0x3ed;
      packet[2] = 0xd;
      packet[3] = **(undefined4 **)(*(int *)(scratchInt6 + 0x18c) + 0x34);
      formatByte = (uint)*(byte *)(*(int *)(scratchInt6 + 0x18c) + 0x38);
      packet[0x3ed] = ((unsigned char *)0x000013c4U);
      packet[4] = formatByte;
      packet[0x3f6] = ((unsigned char *)0x000013caU);
      packet[0x3f4] = ((unsigned char *)0x000013ccU);
      packet[0x3ef] = 0x113c8;
      packet[0x3f2] = ((unsigned char *)0x000013cdU);
      *(undefined4 **)(0x00002748 + stream + 4) = packetEnd;
      (**(code **)(stream + 0x275c))(stream,packetEnd,staleArgR5,staleArgR6,packetEnd,0x113c8,formatByte,packet + 0x3ed);
      if (*(int *)(glContext + 0x1e4) + 0x28U < *(uint *)(glContext + 0x1dc)) {
        gld_submitRing(glContext,0x1000000);
      }
      *(undefined1 *)(*(int *)(scratchInt6 + 0x18c) + 200) = 0;
    }
    scratchInt6 = scratchInt6 + 4;
  }
  scratchUint7 = (uint)*(ushort *)(unitMaskRecord + 6);
  streamCursor = (**(code **)(stream + 0x2758))(stream,0x96);
  *(undefined4 *)(0x00002748 + stream + 4) = streamCursor;
  if (scratchUint7 != 0) {
    scratchInt4 = 0;
    scratchInt6 = glContext;
    do {
      if ((scratchUint7 & 1) != 0) {
        streamCursor = ((int (*)())gld_emitUnitObjectPacket)(glContext,*(undefined4 *)(scratchInt6 + 0x18c),scratchInt4,streamCursor);
      }
      scratchUint7 = scratchUint7 >> 1;
      scratchInt4 = scratchInt4 + 1;
      scratchInt6 = scratchInt6 + 4;
    } while (scratchUint7 != 0);
  }
  *(undefined4 *)(0x00002748 + stream + 4) = streamCursor;
                    
                    
  (**(code **)(stream + 0x275c))(stream,streamCursor);
  return;
}

/* gld_setSamplerMinFilter @ 0x2d030 (456 bytes) */
int gld_setSamplerMinFilter(samplerState, minFilter)
  int samplerState;
  uint minFilter;
{
  uint scratchUint1;
  uint scratchUint2;
  
  scratchUint1 = *(uint *)(samplerState + 0x14);
  scratchUint2 = *(uint *)(samplerState + 0x18) & 0xfff07fff;
  *(uint *)(samplerState + 0x18) = scratchUint2;
  if ((scratchUint1 & 0xe00000) == 0) {
    *(uint *)(samplerState + 0x18) = scratchUint2;
    if (minFilter == 0x2700) {
      scratchUint2 = scratchUint1 & 0xffff87ff | 0x2800;
      *(uint *)(samplerState + 0x14) = scratchUint2;
    }
    else {
      scratchUint2 = scratchUint1;
      if (minFilter < 0x2701) {
        if (minFilter == 0x2600) {
          scratchUint2 = scratchUint1 & 0xffff87ff | 0x800;
          *(uint *)(samplerState + 0x14) = scratchUint2;
        }
        else if (minFilter == 0x2601) {
          scratchUint2 = scratchUint1 & 0xffff87ff | 0x1000;
          *(uint *)(samplerState + 0x14) = scratchUint2;
        }
      }
      else if (minFilter == 0x2702) {
        scratchUint2 = scratchUint1 & 0xffff87ff | 0x4800;
        *(uint *)(samplerState + 0x14) = scratchUint2;
      }
      else if (minFilter < 0x2702) {
        scratchUint2 = scratchUint1 & 0xffff87ff | 0x3000;
        *(uint *)(samplerState + 0x14) = scratchUint2;
      }
      else if (minFilter == 0x2703) {
        scratchUint2 = scratchUint1 & 0xffff87ff | 0x5000;
        *(uint *)(samplerState + 0x14) = scratchUint2;
      }
    }
    goto checkSamplerState;
  }
  scratchUint2 = scratchUint1 & 0xffffe7ff | 0x1800;
  *(uint *)(samplerState + 0x14) = scratchUint2;
  if (minFilter == 0x2700) {
loopSetScratchUint2:
    scratchUint2 = scratchUint1 & 0xffff87ff | 0x3800;
    *(uint *)(samplerState + 0x14) = scratchUint2;
  }
  else {
    if (minFilter < 0x2701) {
      if (minFilter - 0x2600 < 2) {
        scratchUint2 = scratchUint1 & 0xffff87ff | 0x1800;
        *(uint *)(samplerState + 0x14) = scratchUint2;
      }
      goto checkSamplerState;
    }
    if (minFilter != 0x2702) {
      if (minFilter < 0x2702) goto loopSetScratchUint2;
      if (minFilter != 0x2703) goto checkSamplerState;
    }
    scratchUint2 = scratchUint1 & 0xffff87ff | 0x5800;
    *(uint *)(samplerState + 0x14) = scratchUint2;
  }
checkSamplerState:
  if (*(char *)(samplerState + 0x35) != '\0') {
    scratchUint1 = *(uint *)(samplerState + 0x18);
    *(uint *)(samplerState + 0x18) = scratchUint1 & 0xfff1ffff;
    if (1 < (scratchUint2 >> 0xb & 3)) {
      scratchUint2 = scratchUint2 & 0xffffe7ff | 0x800;
      *(uint *)(samplerState + 0x14) = scratchUint2;
    }
    if ((scratchUint2 & 0x6000) == 0x4000) {
      scratchUint2 = scratchUint2 & 0xffff9fff | 0x2000;
      *(uint *)(samplerState + 0x14) = scratchUint2;
      *(uint *)(samplerState + 0x18) = scratchUint1 & 0xfff07fff;
    }
  }
  *(bool *)(samplerState + 0x36) = (scratchUint2 & 0x1e00) == 0xa00;
  return;
}

/* gld_setSamplerMagFilter @ 0x2d210 (140 bytes) */
int gld_setSamplerMagFilter(samplerState, magFilter)
  int samplerState;
  int magFilter;
{
  uint filterWord;
  
  filterWord = *(uint *)(samplerState + 0x14);
  if ((filterWord & 0xe00000) == 0) {
    if (magFilter == 0x2600) {
      filterWord = filterWord & 0xfffff9ff | 0x200;
      *(uint *)(samplerState + 0x14) = filterWord;
    }
    else if (magFilter == 0x2601) {
      filterWord = filterWord & 0xfffff9ff | 0x400;
      *(uint *)(samplerState + 0x14) = filterWord;
    }
  }
  else {
    filterWord = filterWord & 0xfffff9ff | 0x600;
    *(uint *)(samplerState + 0x14) = filterWord;
  }
  if ((*(char *)(samplerState + 0x35) != '\0') && (1 < (filterWord >> 9 & 3))) {
    filterWord = filterWord & 0xfffff9ff | 0x200;
    *(uint *)(samplerState + 0x14) = filterWord;
  }
  *(bool *)(samplerState + 0x36) = (filterWord & 0x1e00) == 0xa00;
  return;
}

/* gldPackColorForSurfaceFormat @ 0x2d2b0 (2388 bytes) */
void gldPackColorForSurfaceFormat(int surface,double red,double green,double blue,double alpha)
{
  float packedColor;
  double redScaled;
  int halfAlphaB;
  uint channelInt2;
  uint channelInt;
  uint halfAlpha;
  uint halfRed;
  double greenScaled;
  double blueScaled;
  double alphaScaled;
  double roundedAlphaD;
  double roundedBlueD;
  double alphaScaledD;
  double blueScaledD;
  double roundedD;
  int channelIntB;
  float redByteBits;
  uint greenByte;
  uint blueByte;
  uint channelInt3;
  double redClamped;
  double greenClamped;
  double blueClamped;
  double alphaClamped;
  double redChannelD;
  double greenChannelD;
  double blueChannelD;
  double alphaChannelD;
  double alphaD;
  float redF;
  float alphaF;
  
  alphaF = (float)alpha;
  redF = (float)red;
  if (*(char *)(surface + 0x37) == '\0') {
    return;
  }
  redClamped = (double)FLOAT_001aa0d4;
  redChannelD = DOUBLE_001aa228;
  if ((redClamped <= red) &&
     (redClamped = red, redChannelD = red, (double)FLOAT_001aa0e8 < red)) {
    redClamped = (double)FLOAT_001aa0e8;
    redChannelD = DOUBLE_001aa200;
  }
  greenClamped = (double)FLOAT_001aa0d4;
  greenChannelD = DOUBLE_001aa228;
  if ((greenClamped <= green) &&
     (greenClamped = green, greenChannelD = green, (double)FLOAT_001aa0e8 < green)) {
    greenClamped = (double)FLOAT_001aa0e8;
    greenChannelD = DOUBLE_001aa200;
  }
  blueClamped = (double)FLOAT_001aa0d4;
  blueChannelD = DOUBLE_001aa228;
  if ((blueClamped <= blue) &&
     (blueClamped = blue, blueChannelD = blue, (double)FLOAT_001aa0e8 < blue)) {
    blueClamped = (double)FLOAT_001aa0e8;
    blueChannelD = DOUBLE_001aa200;
  }
  alphaD = (double)alphaF;
  alphaClamped = (double)FLOAT_001aa0d4;
  alphaChannelD = DOUBLE_001aa228;
  if ((alphaClamped <= alphaD) &&
     (alphaClamped = alphaD, alphaChannelD = alphaD, (double)FLOAT_001aa0e8 < alphaD)) {
    alphaClamped = (double)FLOAT_001aa0e8;
    alphaChannelD = DOUBLE_001aa200;
  }
  redChannelD = redChannelD * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= redChannelD) {
    redByteBits = GH_U2F((unsigned int)(((int)(redChannelD - DOUBLE_001aa1e8) + -0x80000000)));
  }
  else {
    redByteBits = GH_U2F((unsigned int)((int)redChannelD));
  }
  greenChannelD = greenChannelD * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= greenChannelD) {
    greenByte = (int)(greenChannelD - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    greenByte = (uint)(int)greenChannelD;
  }
  blueChannelD = blueChannelD * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= blueChannelD) {
    blueByte = (int)(blueChannelD - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    blueByte = (uint)(int)blueChannelD;
  }
  alphaChannelD = alphaChannelD * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= alphaChannelD) {
    packedColor = GH_U2F((unsigned int)(((int)(alphaChannelD - DOUBLE_001aa1e8) + -0x80000000)));
  }
  else {
    packedColor = GH_U2F((unsigned int)((int)alphaChannelD));
  }
  switch(*(char *)(surface + 0x37)) {
  default:
    packedColor = 0.0;
    break;
  case '\x01':
  case '\x03':
    packedColor = redByteBits;
    break;
  case '\x02':
    break;
  case '\x04':
  case '\x0f':
  case '\x16':
    packedColor = GH_U2F((unsigned int)(((uint)(int)redByteBits | (int)packedColor << 8)));
    break;
  case '\x05':
    packedColor = GH_U2F((unsigned int)((((uint)(int)redByteBits & 0xf8) << 8 | (greenByte & 0xfc) << 3 | blueByte >> 3)));
    break;
  case '\x06':
    packedColor = GH_U2F((unsigned int)((((uint)(int)packedColor & 0xf0) << 8 | ((uint)(int)redByteBits & 0xf0) << 4 | greenByte & 0xf0 |
                   blueByte >> 4)));
    break;
  case '\a':
    packedColor = GH_U2F((unsigned int)((((uint)(int)packedColor & 0x80) << 8 | ((uint)(int)redByteBits & 0xf8) << 7 | (greenByte & 0xf8) << 2 |
                   blueByte >> 3)));
    break;
  case '\b':
  case '\v':
  case '\f':
  case '\r':
  case '\x0e':
  case '\x11':
  case '\x17':
  case '\x1d':
  case '&':
  case '\'':
    packedColor = (float)(blueByte | (int)GH_F2U(packedColor) << 0x18 | (int)GH_F2U(redByteBits) << 0x10 | greenByte << 8);
    break;
  case '\t':
  case '\n':
  case '\x12':
  case '\x18':
  case '\x1e':
    packedColor = GH_U2F((unsigned int)(((uint)(int)redByteBits | greenByte << 8 | (int)packedColor << 0x18 | blueByte << 0x10)));
    break;
  case '\x10':
    redScaled = redClamped * (double)FLOAT_001aa14c + (double)FLOAT_001aa10c;
    roundedD = (double)(float)redScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelInt = (int)(roundedD - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelInt = (uint)(int)redScaled;
    }
    goto setPackedColor;
  case '\x13':
  case '\x15':
    packedColor = redF;
    break;
  case '\x14':
    packedColor = alphaF;
    break;
  case '\x19':
  case '\x1b':
    redScaled = redClamped * (double)FLOAT_001aa14c + (double)FLOAT_001aa10c;
    roundedD = (double)(float)redScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelInt = (int)(roundedD - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelInt = (uint)(int)redScaled;
    }
    goto setChannelInt;
  case '\x1a':
    alphaScaled = alphaClamped * (double)FLOAT_001aa14c + (double)FLOAT_001aa10c;
    roundedD = (double)(float)alphaScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelInt = (int)(roundedD - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelInt = (uint)(int)alphaScaled;
    }
setChannelInt:
    channelInt = channelInt & 0xffff;
setPackedColor:
    packedColor = GH_U2F((unsigned int)((channelInt | channelInt << 0x10)));
    break;
  case '\x1c':
    redScaled = redClamped * (double)FLOAT_001aa14c + (double)FLOAT_001aa10c;
    roundedD = (double)(float)redScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelInt = (int)(roundedD - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelInt = (uint)(int)redScaled;
    }
    alphaScaled = alphaClamped * (double)FLOAT_001aa14c + (double)FLOAT_001aa10c;
    roundedD = (double)(float)alphaScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelIntB = (int)(roundedD - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      channelIntB = (int)alphaScaled;
    }
    packedColor = GH_U2F((unsigned int)((channelInt & 0xffff | channelIntB << 0x10)));
    break;
  case '\x1f':
  case '!':
    halfRed = ((uint (*)())floatToHalfBits)(red);
    packedColor = GH_U2F((unsigned int)((halfRed << 0x10 | halfRed)));
    break;
  case ' ':
    halfAlpha = ((uint (*)())floatToHalfBits)(alphaD);
    packedColor = GH_U2F((unsigned int)((halfAlpha << 0x10 | halfAlpha)));
    break;
  case '\"':
    halfRed = ((uint (*)())floatToHalfBits)(red);
    halfAlphaB = ((uint (*)())floatToHalfBits)((double)alphaF);
    packedColor = GH_U2F((unsigned int)((halfRed | halfAlphaB << 0x10)));
    break;
  case '#':
    redScaled = redClamped * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    roundedD = (double)(float)redScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelInt = (int)(roundedD - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelInt = (uint)(int)redScaled;
    }
    channelInt = channelInt & 0x3ff;
    alphaScaled = alphaClamped * (double)FLOAT_001aa158 + (double)FLOAT_001aa10c;
    roundedD = (double)(float)alphaScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelIntB = (int)(roundedD - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      channelIntB = (int)alphaScaled;
    }
    blueScaled = blueClamped * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    roundedD = (double)(float)blueScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelInt2 = (int)(roundedD - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelInt2 = (uint)(int)blueScaled;
    }
    channelInt2 = channelIntB << 0x1e | (channelInt2 & 0x3ff) << 0x14;
    greenScaled = greenClamped * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    roundedD = (double)(float)greenScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelInt3 = (int)(roundedD - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelInt3 = (uint)(int)greenScaled;
    }
    goto setPackedColor2;
  case '$':
    blueScaledD = blueClamped * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    roundedBlueD = (double)(float)blueScaledD;
    if (DOUBLE_001aa1e8 <= roundedBlueD) {
      channelInt = (int)(roundedBlueD - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelInt = (uint)(int)blueScaledD;
    }
    channelInt = channelInt & 0x3ff;
    alphaScaledD = alphaClamped * (double)FLOAT_001aa158 + (double)FLOAT_001aa10c;
    roundedAlphaD = (double)(float)alphaScaledD;
    if (DOUBLE_001aa1e8 <= roundedAlphaD) {
      channelIntB = (int)(roundedAlphaD - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      channelIntB = (int)alphaScaledD;
    }
    redScaled = redClamped * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    roundedD = (double)(float)redScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelInt2 = (int)(roundedD - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelInt2 = (uint)(int)redScaled;
    }
    channelInt2 = channelIntB << 0x1e | (channelInt2 & 0x3ff) << 0x14;
    greenScaled = greenClamped * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    roundedD = (double)(float)greenScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelInt3 = (int)(roundedD - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelInt3 = (uint)(int)greenScaled;
    }
setPackedColor2:
    packedColor = GH_U2F((unsigned int)((channelInt | channelInt2 | (channelInt3 & 0x3ff) << 10)));
    break;
  case '(':
    packedColor = GH_U2F((unsigned int)(((uint)(int)redByteBits & 0xe0 | greenByte >> 3 & 0x1c | blueByte >> 6)));
    break;
  case ')':
    redScaled = redClamped * (double)FLOAT_001aa150 + (double)FLOAT_001aa10c;
    roundedD = (double)(float)redScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelIntB = (int)(roundedD - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      channelIntB = (int)redScaled;
    }
    packedColor = GH_U2F((unsigned int)((channelIntB << 8)));
  }
  *(float *)(surface + 0x28) = packedColor;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl gldPrimWrapperTriangleFan_23a24");
asm(".set gldPrimWrapperTriangleFan_23a24, _gldPrimWrapperTriangleFan_23a24");
asm(".globl gldPrimWrapperQuads_23a24");
asm(".set gldPrimWrapperQuads_23a24, _gldPrimWrapperQuads_23a24");
asm(".globl gldPrimWrapperQuadStrip_23a24");
asm(".set gldPrimWrapperQuadStrip_23a24, _gldPrimWrapperQuadStrip_23a24");
asm(".globl gldPrimWrapperPolygon_23a24");
asm(".set gldPrimWrapperPolygon_23a24, _gldPrimWrapperPolygon_23a24");
asm(".globl gldPrimWrapperPolygon_24190");
asm(".set gldPrimWrapperPolygon_24190, _gldPrimWrapperPolygon_24190");
asm(".globl gldPrimWrapperPoints_23a24");
asm(".set gldPrimWrapperPoints_23a24, _gldPrimWrapperPoints_23a24");
asm(".globl gldPrimWrapperPoints_24190");
asm(".set gldPrimWrapperPoints_24190, _gldPrimWrapperPoints_24190");
asm(".globl gldPrimWrapperLines_23a24");
asm(".set gldPrimWrapperLines_23a24, _gldPrimWrapperLines_23a24");
asm(".globl gldPrimWrapperLines_24190");
asm(".set gldPrimWrapperLines_24190, _gldPrimWrapperLines_24190");
asm(".globl gldPrimWrapperLineLoop_23a24");
asm(".set gldPrimWrapperLineLoop_23a24, _gldPrimWrapperLineLoop_23a24");
asm(".globl gldPrimWrapperLineStrip_23a24");
asm(".set gldPrimWrapperLineStrip_23a24, _gldPrimWrapperLineStrip_23a24");
asm(".globl gld_drawElementsImmediate");
asm(".set gld_drawElementsImmediate, _gld_drawElementsImmediate");
asm(".globl gld_drawArraysDirect");
asm(".set gld_drawArraysDirect, _gld_drawArraysDirect");
asm(".globl gld_reserveVertexBufferSpace");
asm(".set gld_reserveVertexBufferSpace, _gld_reserveVertexBufferSpace");
asm(".globl gld_drawArraysStream");
asm(".set gld_drawArraysStream, _gld_drawArraysStream");
asm(".globl gld_reserveDrawSpace");
asm(".set gld_reserveDrawSpace, _gld_reserveDrawSpace");
asm(".globl glReadPixels_entry");
asm(".set glReadPixels_entry, _glReadPixels_entry");
asm(".globl gld_beginQuerySlot");
asm(".set gld_beginQuerySlot, _gld_beginQuerySlot");
asm(".globl gld_emitStampFencePacket");
asm(".set gld_emitStampFencePacket, _gld_emitStampFencePacket");
asm(".globl gld_ensureRingSpace");
asm(".set gld_ensureRingSpace, _gld_ensureRingSpace");
asm(".globl gld_setStreamCursor");
asm(".set gld_setStreamCursor, _gld_setStreamCursor");
