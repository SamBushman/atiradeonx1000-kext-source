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
    return FUN_00024190(ctx + 0x240,15,vertexData,vertexCount,extraArg);
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
    return FUN_00024190(ctx + 0x240,1,vertexData,vertexCount,0);
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
    return FUN_00024190(ctx + 0x240,2,vertexData,vertexCount,0);
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
  uint *puVar1;
  undefined4 *packetBody;
  int trimmedCount;
  undefined4 *packetTail;
  undefined4 registerValue;
  uint *puVar7;
  int indexDwords;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint cacheLineSize;
  undefined4 staleArgR9;
  double staleStackArg_ffffff88;

  cacheLineSize = (uint)*(byte *)(ctx + 8);
  dataCacheBlockTouch(*(undefined4 *)(ctx + 0x1d8));
  trimmedCount = ((uint (*)())gld_prepareDrawCount)(ctx,1,primitiveMode,indexCount,indexCount,indexType,staleArgR9,staleFprArg1,staleFprArg2,staleFprArg3,staleFprArg4
                       ,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffff88);
  if (trimmedCount != 0) {
    iVar9 = 5;
    *(undefined4 *)(glStateBlock + -0x68) = *(undefined4 *)(*(int *)(ctx + 0x244) + 0x23c);
    if (cacheLineSize != 0x20) {
      iVar9 = 7;
    }
    indexDwords = trimmedCount + 1 >> 1;
    uVar10 = indexDwords + 0x1f;
    uVar11 = uVar10 >> iVar9;
    packetAlloc = (uint *)(**(code **)(ctx + 0x2998))(ctx + 0x240,uVar10);
    *(uint **)(ctx + 0x298c) = packetAlloc;
    if (1 < uVar11) {
      iVar9 = uVar11 - 1;
      uVar10 = cacheLineSize;
      do {
        dataCacheBlockClearToZero((int)packetAlloc + uVar10);
        uVar10 = uVar10 + cacheLineSize;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    packetBody = (undefined4 *)((uint)(packetAlloc + 0xb) & 0xffffffe0);
    *packetAlloc = (((int)packetBody - (int)packetAlloc) + -8) * 0x4000 | 0xc0001000;
    packetBody[-1] = (int)packetBody - (int)packetAlloc;
    packetTail = packetBody + 0xc;
    lastHeader = *(uint **)(ctx + 0x1d8);
    iVar9 = *(int *)(glStateBlock + -0x74) * 0x14;
    *lastHeader = (int)packetBody - (int)lastHeader >> 2 | *lastHeader;
    *(undefined4 **)(ctx + 0x1d8) = packetBody;
    *packetBody = 0x26000000;
    registerValue = **(undefined4 **)(glStateBlock + -100);
    packetBody[2] = 0x20830;
    packetBody[3] = 0x21;
    packetBody[1] = registerValue;
    registerValue = *(undefined4 *)(iVar9 + 0x1d975c);
    packetBody[6] = 0x10854;
    packetBody[5] = 0;
    packetBody[4] = registerValue;
    packetBody[7] = *(undefined4 *)(iVar9 + 0x1d9760);
    registerValue = *(undefined4 *)(iVar9 + 0x1d9764);
    packetBody[9] = 0x10878;
    packetBody[8] = registerValue;
    packetBody[10] = *(undefined4 *)(iVar9 + 0x1d9768);
    packetBody[0xb] = *(undefined4 *)(iVar9 + 0x1d976c);
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
      uVar10 = 0;
      puVar7 = indices;
      if (lastIndex != 0) {
        do {
          uVar10 = uVar10 + 2;
          *indexCursor = (uint)*(ushort *)puVar7 - indexBias & 0xffff |
                    ((uint)(ushort)*puVar7 - indexBias) * 0x10000;
          indexCursor = indexCursor + 1;
          puVar7 = puVar7 + 1;
        } while (uVar10 < lastIndex);
      }
      if ((lastIndex & 1) == 0) {
        *indexCursor = (uint)*(ushort *)(uVar10 * 2 + (int)indices) - indexBias & 0xffff;
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
            uVar10 = indices[1];
            uVar11 = *indices;
            indexCursor[1] = indices[2] | indices[3] << 0x10;
            *indexCursor = uVar10 << 0x10 | uVar11;
            uVar10 = indices[5];
            uVar11 = indices[4];
            indexCursor[3] = indices[6] | indices[7] << 0x10;
            indexCursor[2] = uVar10 << 0x10 | uVar11;
            uVar10 = indices[9];
            uVar11 = indices[8];
            indexCursor[5] = indices[10] | indices[0xb] << 0x10;
            indexCursor[4] = uVar10 << 0x10 | uVar11;
            puVar7 = indices + 0xd;
            uVar10 = indices[0xf];
            puVar1 = indices + 0xc;
            uVar11 = indices[0xe];
            indices = indices + 0x10;
            indexCursor[6] = *puVar1 | *puVar7 << 0x10;
            indexCursor[7] = uVar11 | uVar10 << 0x10;
            indexCursor = indexCursor + 8;
            blockCount = blockCount + -1;
          } while (blockCount != 0);
        }
        if ((lastIndex & 0xf) != 0) {
          uVar10 = 0;
          do {
            puVar7 = indices + 1;
            uVar10 = uVar10 + 2;
            uVar11 = *indices;
            indices = indices + 2;
            *indexCursor = uVar11 | *puVar7 << 0x10;
            indexCursor = indexCursor + 1;
          } while (uVar10 < (lastIndex & 0xf));
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
            uVar10 = indices[1];
            uVar11 = *indices;
            indexCursor[1] = indices[2] - indexBias | (indices[3] - indexBias) * 0x10000;
            *indexCursor = uVar11 - indexBias | (uVar10 - indexBias) * 0x10000;
            uVar10 = indices[5];
            uVar11 = indices[4];
            indexCursor[3] = (indices[7] - indexBias) * 0x10000 | indices[6] - indexBias & 0xffff;
            indexCursor[2] = (uVar10 - indexBias) * 0x10000 | uVar11 - indexBias & 0xffff;
            uVar10 = indices[9];
            uVar11 = indices[8];
            indexCursor[5] = (indices[0xb] - indexBias) * 0x10000 | indices[10] - indexBias & 0xffff;
            indexCursor[4] = (uVar10 - indexBias) * 0x10000 | uVar11 - indexBias & 0xffff;
            puVar7 = indices + 0xc;
            puVar1 = indices + 0xd;
            uVar11 = indices[0xe];
            uVar10 = indices[0xf];
            indices = indices + 0x10;
            indexCursor[6] = (*puVar1 - indexBias) * 0x10000 | *puVar7 - indexBias & 0xffff;
            indexCursor[7] = (uVar10 - indexBias) * 0x10000 | uVar11 - indexBias & 0xffff;
            indexCursor = indexCursor + 8;
            blockCount = blockCount + -1;
          } while (blockCount != 0);
        }
        if ((lastIndex & 0xf) != 0) {
          uVar10 = 0;
          do {
            uVar11 = *indices;
            puVar7 = indices + 1;
            uVar10 = uVar10 + 2;
            indices = indices + 2;
            *indexCursor = (*puVar7 - indexBias) * 0x10000 | uVar11 - indexBias & 0xffff;
            indexCursor = indexCursor + 1;
          } while (uVar10 < (lastIndex & 0xf));
        }
        if ((lastIndex & 1) == 0) {
          *indexCursor = *indices - indexBias & 0xffff;
          indexCursor = indexCursor + 1;
        }
      }
    }
    else if (indexType == ((unsigned char *)0x00001401)) {
      uVar10 = 0;
      puVar7 = indices;
      if (lastIndex != 0) {
        do {
          uVar10 = uVar10 + 2;
          *indexCursor = (uint)*(byte *)puVar7 - indexBias & 0xffff |
                    ((uint)*(byte *)((int)puVar7 + 1) - indexBias) * 0x10000;
          indexCursor = indexCursor + 1;
          puVar7 = (uint *)((int)puVar7 + 2);
        } while (uVar10 < lastIndex);
      }
      if ((lastIndex & 1) == 0) {
        *indexCursor = (uint)*(byte *)((int)indices + uVar10) - indexBias & 0xffff;
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

/* FUN_00024fb0 @ 0x24fb0 (16 bytes) */
int FUN_00024fb0(list)
  int list;
{
  *(int *)(list + 0x30) = list + 0x2c;
  *(int *)(list + 0x2c) = list + 0x2c;
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

/* FUN_00024fe0 @ 0x24fe0 (2908 bytes) */
double FUN_00024fe0(int ctx,int maxCount,float *outConstants,double staleFprArg1)
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
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  float fVar6;
  int paramBase;
  undefined *stateRecord;
  dword *srcZPtr;
  int iVar10;
  int iVar11;
  int stateBlockA;
  int iVar13;
  int programData;
  uint programFlags;
  float *constantSrc;
  dword *srcWPtr;
  int iVar18;
  int programHeader;
  uint uVar20;
  dword *srcYPtr;
  uint uVar22;
  int iVar23;
  int literalPool;
  int operandIndex;
  int *programObject;
  uint *operandPtr;
  float vecX;
  float vecY;
  float vecZ;
  float vecW [3];
  undefined4 local_78;
  float fStack_74;
  undefined4 local_70;
  float fStack_6c;
  undefined4 local_68;
  float fStack_64;
  undefined4 local_60;
  float fStack_5c;
  
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
LAB_00025b04:
    fVar3 = FLOAT_001aa13c;
    fVar2 = FLOAT_001aa138;
    fVar6 = FLOAT_001aa134;
    programDataB = programObject[0xe];
    if (programDataB != 0) {
      programFlags = *(uint *)(programDataB + 0x20);
      if ((programFlags & 0x4000000) != 0) {
        *outConstants = FLOAT_001aa130;
        outConstants[1] = fVar6;
        outConstants[2] = fVar2;
        outConstants[3] = fVar3;
        outConstants = outConstants + 4;
        programFlags = *(uint *)(programDataB + 0x20);
      }
      if ((programFlags & 0x2000000) != 0) {
        *outConstants = *(float *)(((unsigned char *)0x00002de0) + *(int *)(ctx + GLD_engineState));
        outConstants[1] = *(float *)(((unsigned char *)0x00002de4) + *(int *)(ctx + GLD_engineState));
        outConstants[2] = *(float *)(((unsigned char *)0x00002de8) + *(int *)(ctx + GLD_engineState));
        outConstants[4] = -*(float *)(((unsigned char *)0x00002dfc) + *(int *)(ctx + GLD_engineState));
        fVar6 = FLOAT_001aa140;
        outConstants[5] = *(float *)(((unsigned char *)0x00002df8) + *(int *)(ctx + GLD_engineState)) *
                     *(float *)(((unsigned char *)0x00002dfc) + *(int *)(ctx + GLD_engineState));
        fVar2 = FLOAT_001aa144;
        outConstants[6] = *(float *)(((unsigned char *)0x00002df0) + *(int *)(ctx + GLD_engineState)) * fVar6;
        outConstants[7] = *(float *)(((unsigned char *)0x00002df0) + *(int *)(ctx + GLD_engineState)) * fVar2;
      }
    }
    return staleFprArg1;
  }
  operandIndex = 0;
LAB_00025090:
  dVar5 = DOUBLE_001aa1e0;
  fVar6 = FLOAT_001aa0e8;
  operandWord = *operandPtr;
  operandFile = operandWord & 0x1f0000;
  if (operandFile == 0) goto LAB_00025af0;
  if (operandFile == 0x110000) {
    constantSrc = (float *)(programData + paramBase * 8 + (uint)(ushort)*operandPtr * 0x10);
LAB_0002546c:
    if ((useDefaultProgram) || ((operandWord & 0x1c000000) == 0x4000000)) {
      *outConstants = *constantSrc;
      outConstants[1] = constantSrc[1];
      outConstants[2] = constantSrc[2];
      outConstants[3] = constantSrc[3];
    }
    else if ((operandWord & 0x1c000000) == 0xc000000) {
      local_78 = 0x43300000;
      fStack_74 = -*constantSrc;
      *outConstants = (float)((double)CONCAT44(0x43300000,-*constantSrc) - DOUBLE_001aa1e0);
      local_70 = 0x43300000;
      fStack_6c = -constantSrc[1];
      outConstants[1] = (float)((double)CONCAT44(0x43300000,-constantSrc[1]) - dVar5);
      local_68 = 0x43300000;
      fStack_64 = -constantSrc[2];
      outConstants[2] = (float)((double)CONCAT44(0x43300000,-constantSrc[2]) - dVar5);
      local_60 = 0x43300000;
      fStack_5c = -constantSrc[3];
      outConstants[3] = (float)((double)CONCAT44(0x43300000,-constantSrc[3]) - dVar5);
    }
    else {
      if (*constantSrc == 0.0) {
        fVar6 = 0.0;
      }
      else {
        fVar6 = 1.0;
      }
      *outConstants = fVar6;
      if (constantSrc[1] == 0.0) {
        fVar6 = 0.0;
      }
      else {
        fVar6 = 1.0;
      }
      outConstants[1] = fVar6;
      if (constantSrc[2] == 0.0) {
        fVar6 = 0.0;
      }
      else {
        fVar6 = 1.0;
      }
      outConstants[2] = fVar6;
      if (constantSrc[3] == 0.0) {
        fVar6 = 0.0;
      }
      else {
        fVar6 = 1.0;
      }
      outConstants[3] = fVar6;
    }
    goto LAB_00025af0;
  }
  if (operandFile == 0x10000) {
    constantSrc = (float *)(literalPool + (uint)(ushort)*operandPtr * 0x10);
    goto LAB_0002546c;
  }
  if (operandFile == 0x20000) {
    iVar23 = (uint)(ushort)*operandPtr * 0x10;
    iVar10 = iVar23 + *(int *)(((unsigned char *)0x00004310) + *(int *)(ctx + GLD_engineState));
    *outConstants = *(float *)(iVar23 + *(int *)(((unsigned char *)0x00004310) + *(int *)(ctx + GLD_engineState)));
    outConstants[1] = *(float *)(iVar10 + 4);
    outConstants[2] = *(float *)(iVar10 + 8);
    outConstants[3] = *(float *)(iVar10 + 0xc);
    goto LAB_00025af0;
  }
  if (operandFile == 0x100000) {
    uVar20 = operandWord >> 0xc & 3;
    uVar22 = operandWord & 0xff;
    switch(operandWord >> 8 & 7) {
    default:
      iVar23 = 0;
      break;
    case 1:
      iVar23 = 0xc0;
      break;
    case 2:
      iVar23 = 0x80;
      break;
    case 3:
      iVar23 = (uVar22 + 4) * 0x40;
      break;
    case 4:
      iVar23 = (uVar22 + 0x10) * 0x40;
      break;
    case 5:
      iVar23 = (uVar22 + 8) * 0x40;
    }
    operandWord = operandWord >> 0xe & 3;
    iVar10 = *(int *)(ctx + GLD_engineState) + 0x1860 + iVar23;
    if ((1 < operandWord) && (iVar10 = iVar23 + *(int *)(ctx + GLD_engineState) + 0x1e60, 3 < operandWord)) {
      iVar10 = 0;
    }
    if (operandWord < 3) {
      if (operandWord == 0) {
LAB_000256f4:
        iVar23 = uVar20 * 4;
        iVar11 = iVar10 + iVar23;
        vecX = *(float *)(iVar10 + iVar23);
        vecY = *(float *)(iVar11 + 0x10);
        vecZ = *(float *)(iVar11 + 0x20);
        vecW[0] = *(float *)(iVar11 + 0x30);
      }
      else {
        iVar23 = uVar20 * 0x10;
        iVar11 = iVar10 + iVar23;
        vecX = *(float *)(iVar10 + iVar23);
        vecY = *(float *)(iVar11 + 4);
        vecZ = *(float *)(iVar11 + 8);
        vecW[0] = *(float *)(iVar11 + 0xc);
      }
    }
    else if (operandWord == 3) goto LAB_000256f4;
    goto LAB_00025ac8;
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
    uVar20 = operandWord & 0xff;
    switch(operandWord >> 8 & 0xf) {
    case 0:
      vecPtr = (float *)(uVar20 * 0x80 + 0x24c0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 1:
      vecPtr = (float *)(uVar20 * 0x80 + 0x24d0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 2:
      vecPtr = (float *)(uVar20 * 0x80 + 0x24e0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 3:
      vecPtr = (float *)(uVar20 * 0x80 + 0x24f0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 4:
      vecPtr = (float *)(uVar20 * 0x80 + 0x2500 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 5:
      vecPtr = (float *)(uVar20 * 0x80 + 0x2510 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 6:
      iVar23 = uVar20 * 0x80 + *(int *)(ctx + GLD_engineState);
      fVar2 = *(float *)(iVar23 + 0x24f4);
      fVar3 = *(float *)(iVar23 + 0x24f0);
      fVar4 = *(float *)(iVar23 + 0x24f8) + FLOAT_001aa0e8;
      staleFprArg1 = _sqrt((double)(fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2));
      vecW[0] = fVar6;
      fVar6 = (float)(DOUBLE_001aa200 / staleFprArg1);
      vecZ = fVar4 * fVar6;
      vecX = fVar3 * fVar6;
      vecY = fVar2 * fVar6;
      goto LAB_00025ac8;
    case 7:
      vecPtr = (float *)(uVar20 * 0x80 + 0x2530 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    default:
      goto switchD_00025774_caseD_1;
    }
    break;
  case 4:
    uVar20 = operandWord >> 9 & 3;
    stateBlockA = *(int *)(ctx + GLD_engineState) + 0x24c0;
    iVar23 = (operandWord & 0xff) * 0x80;
    iVar10 = (operandWord >> 8 & 1) * 0x240;
    stateBlockB = *(int *)(ctx + GLD_engineState) + 0x28c0;
    iVar18 = stateBlockA + iVar23;
    iVar13 = stateBlockB + iVar10;
    if (uVar20 == 1) {
      vecX = *(float *)(iVar18 + 0x10) * *(float *)(iVar13 + 0x10);
      vecY = *(float *)(iVar18 + 0x14) * *(float *)(iVar13 + 0x14);
      vecZ = *(float *)(iVar18 + 0x18) * *(float *)(iVar13 + 0x18);
      vecW[0] = *(float *)(iVar13 + 0x1c);
    }
    else if (uVar20 == 2) {
      vecX = *(float *)(iVar18 + 0x20) * *(float *)(iVar13 + 0x20);
      vecY = *(float *)(iVar18 + 0x24) * *(float *)(iVar13 + 0x24);
      vecZ = *(float *)(iVar18 + 0x28) * *(float *)(iVar13 + 0x28);
      vecW[0] = *(float *)(iVar13 + 0x2c);
    }
    else {
      if (uVar20 != 0) goto switchD_00025774_caseD_1;
      vecX = *(float *)(stateBlockA + iVar23) * *(float *)(stateBlockB + iVar10);
      vecY = *(float *)(iVar18 + 4) * *(float *)(iVar13 + 4);
      vecZ = *(float *)(iVar18 + 8) * *(float *)(iVar13 + 8);
      vecW[0] = *(float *)(iVar13 + 0xc);
    }
    goto LAB_00025ac8;
  case 5:
    uVar20 = operandWord & 1;
    switch(operandWord >> 1 & 7) {
    case 0:
      vecPtr = (float *)(uVar20 * 0x240 + 0x28c0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 1:
      vecPtr = (float *)(uVar20 * 0x240 + 0x28d0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 2:
      vecPtr = (float *)(uVar20 * 0x240 + 0x28e0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 3:
      vecPtr = (float *)(uVar20 * 0x240 + 0x28f0 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 4:
      vecPtr = (float *)(uVar20 * 0x240 + 0x2900 + *(int *)(ctx + GLD_engineState));
      srcYPtr = (dword *)(vecPtr + 1);
      srcZPtr = (dword *)(vecPtr + 2);
      srcWPtr = (dword *)(vecPtr + 3);
      break;
    case 5:
      engineStateB = *(int *)(ctx + GLD_engineState);
      iVar10 = engineStateB + 0x28c0 + uVar20 * 0x240;
      vecX = *(float *)(engineStateB + 0x24b0) * *(float *)(engineStateB + 0x28c0 + uVar20 * 0x240) +
                 *(float *)(iVar10 + 0x30);
      vecY = *(float *)(engineStateB + 0x24b4) * *(float *)(iVar10 + 4) + *(float *)(iVar10 + 0x34);
      vecZ = *(float *)(engineStateB + 0x24b8) * *(float *)(iVar10 + 8) + *(float *)(iVar10 + 0x38);
      vecW[0] = *(float *)(iVar10 + 0x1c);
      goto LAB_00025ac8;
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
    uVar20 = operandWord >> 5 & 7;
    operandWord = operandWord & 0x1f;
    if (uVar20 == 1) {
      engineState = *(int *)(ctx + GLD_engineState);
      stateRecord = ((unsigned char *)0x000039a0) + operandWord * 0x94;
LAB_00025180:
      srcWPtr = (dword *)(stateRecord + engineState + 0x1c);
      vecPtr = (float *)(stateRecord + engineState + 0x10);
      srcYPtr = (dword *)(stateRecord + engineState + 0x14);
      srcZPtr = (dword *)(stateRecord + engineState + 0x18);
    }
    else {
      if (uVar20 < 2) {
        if (uVar20 == 0) {
          engineState = *(int *)(ctx + GLD_engineState);
          stateRecord = ((unsigned char *)0x00003980) + operandWord * 0x94;
          goto LAB_0002515c;
        }
        goto switchD_00025774_caseD_1;
      }
      if (uVar20 == 2) {
        engineState = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039c0) + operandWord * 0x94;
LAB_000251a4:
        srcWPtr = (dword *)(stateRecord + engineState + 0x20);
        vecPtr = (float *)(stateRecord + engineState + 0x14);
        srcYPtr = (dword *)(stateRecord + engineState + 0x18);
        srcZPtr = (dword *)(stateRecord + engineState + 0x1c);
      }
      else {
        if (uVar20 != 3) goto switchD_00025774_caseD_1;
        engineState = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039e0) + operandWord * 0x94;
LAB_000251c8:
        srcWPtr = (dword *)(stateRecord + engineState + 0x24);
        vecPtr = (float *)(stateRecord + engineState + 0x18);
        srcYPtr = (dword *)(stateRecord + engineState + 0x1c);
        srcZPtr = (dword *)(stateRecord + engineState + 0x20);
      }
    }
    break;
  case 8:
    uVar20 = operandWord >> 5 & 7;
    operandWord = operandWord & 0x1f;
    if (uVar20 == 1) {
      engineState = *(int *)(ctx + GLD_engineState);
      stateRecord = ((unsigned char *)0x000039b0) + operandWord * 0x94;
      goto LAB_00025180;
    }
    if (uVar20 < 2) {
      if (uVar20 == 0) {
        engineState = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x00003990) + operandWord * 0x94;
        goto LAB_0002515c;
      }
    }
    else {
      if (uVar20 == 2) {
        engineState = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039d0) + operandWord * 0x94;
        goto LAB_000251a4;
      }
      if (uVar20 == 3) {
        engineState = *(int *)(ctx + GLD_engineState);
        stateRecord = ((unsigned char *)0x000039f0) + operandWord * 0x94;
        goto LAB_000251c8;
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
LAB_0002515c:
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
    goto LAB_00025ac8;
  case 0x12:
    vecW[0] = *(float *)(*(int *)(ctx + GLD_engineState) + 0x24a4);
    vecX = vecW[0];
    vecY = vecW[0];
    vecZ = vecW[0];
    goto LAB_00025ac8;
  }
LAB_00025aa8:
  vecX = *vecPtr;
  vecY = (float)*srcYPtr;
  vecZ = (float)*srcZPtr;
  vecW[0] = (float)*srcWPtr;
LAB_00025ac8:
  outConstants[1] = vecY;
  outConstants[2] = vecZ;
  *outConstants = vecX;
  outConstants[3] = vecW[0];
LAB_00025af0:
  operandIndex = operandIndex + 1;
  operandPtr = operandPtr + 2;
  outConstants = outConstants + 4;
  if (operandsLeft == operandIndex) goto LAB_00025b04;
  goto LAB_00025090;
switchD_00025774_caseD_1:
  vecPtr = (float *)0x0;
  srcYPtr = ((unsigned char *)0x4);
  srcZPtr = ((unsigned char *)0x8);
  srcWPtr = ((unsigned char *)0xc);
  goto LAB_00025aa8;
}

/* FUN_00025bf0 @ 0x25bf0 (408 bytes) */
int FUN_00025bf0(ctx, program)
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

/* FUN_00025ec0 @ 0x25ec0 (1372 bytes) */
int FUN_00025ec0(param_1, param_2)
  int param_1;
  int *param_2;
{
  undefined4 length;
  byte *pbVar1;
  byte *pbVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  int literalPool;
  int rowsMinusOne;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  int *piVar14;
  int *piVar15;
  
  piVar15 = (int *)(param_1 + 0x240);
  for (piVar6 = (int *)param_2[9]; piVar6 != param_2 + 8; piVar6 = (int *)piVar6[1]) {
    if (param_1 == piVar6[2]) goto LAB_00025f80;
  }
  piVar6 = (int *)_calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
  piVar6[3] = param_2[5] + -1;
  iVar9 = param_2[6];
  piVar6[2] = param_1;
  piVar6[1] = (int)(param_2 + 8);
  rowsMinusOne = iVar9 + -1;
  piVar6[4] = rowsMinusOne;
  *piVar6 = param_2[8];
  param_2[8] = (int)piVar6;
  *(int **)(*piVar6 + 4) = piVar6;
LAB_00025f80:
  iVar9 = piVar6[5];
  piVar14 = piVar6 + 5;
  if (iVar9 == 0) {
    glGenProgramsARB_impl(piVar15,1,piVar14);
    iVar9 = piVar6[5];
    if (iVar9 != 0) goto LAB_00025fac;
LAB_000263d8:
    uVar8 = 0;
  }
  else {
LAB_00025fac:
    glBindProgramARB_impl(piVar15,0x8804,iVar9,staleArgR6,staleArgR7,literalPool,rowsMinusOne);
    if (piVar6[3] == param_2[5]) {
      pbVar13 = (byte *)param_2[0xe];
      if (pbVar13 != (byte *)0x0) {
        uVar11 = *(uint *)(pbVar13 + 0x20);
        uVar5 = uVar11 >> 0x1b;
        literalPool = *(int *)(*param_2 + 0x18);
        if (uVar5 == 0) {
LAB_00026008:
          bVar3 = false;
        }
        else {
          if ((uint)pbVar13[1] == *(uint *)(literalPool + (uint)*pbVar13 * 0x10)) {
            do {
              uVar5 = uVar5 - 1;
              if (uVar5 == 0) goto LAB_00026008;
              pbVar1 = pbVar13 + 2;
              pbVar2 = pbVar13 + 3;
              pbVar13 = pbVar13 + 2;
            } while ((uint)*pbVar2 == *(uint *)(literalPool + (uint)*pbVar1 * 0x10));
          }
          bVar3 = true;
        }
        if (((((uVar11 & 0x1000000) != 0) &&
             ((uVar11 >> 0x17 & 1) != (uint)(byte)((unsigned char *)0x00002b7c)[param_1])) ||
            (((uVar11 & 0x400000) == 0 &&
             ((uVar11 >> 0x12 & 0xf) != (*(uint *)(param_1 + 0x1ae4) >> 6 & 0xffff))))) || (bVar3))
        {
          uVar5 = param_2[0xf];
          param_2[0xf] = uVar5 | 1;
          param_2[5] = param_2[5] + 1;
          if ((uVar5 & 2) != 0) {
            param_2[6] = param_2[6] + 1;
          }
          param_2[0xf] = 0;
          bVar3 = piVar6[3] != param_2[5];
          if (bVar3) {
            piVar6[3] = param_2[5];
          }
          goto LAB_000260dc;
        }
      }
LAB_000263c0:
      if (*(char *)(param_2 + 10) != '\0') goto LAB_000263d8;
    }
    else {
      piVar6[3] = param_2[5];
      bVar3 = true;
LAB_000260dc:
      if (!bVar3) goto LAB_000263c0;
      *(undefined1 *)(param_2 + 10) = 0;
      if (param_2[0xb] != 0) {
        _glpFreePPShaderLinearize(param_2[0xb]);
        param_2[0xb] = 0;
      }
      if (param_2[0xc] != 0) {
        _glpFreePPShaderToProgram(param_2[0xc]);
        param_2[0xc] = 0;
      }
      if (param_2[0xd] != 0) {
        param_2[0xd] = 0;
      }
      bVar3 = false;
      uVar5 = 0x1f9;
      freeIfNonNull(param_2[0xe]);
      param_2[0xe] = 0;
      while( true ) {
        if (*(short *)*param_2 == -0x74d0) {
          iVar9 = _glpPPShaderLinearize(*(undefined4 *)((short *)*param_2 + 2),uVar5);
          param_2[0xb] = iVar9;
        }
        piVar7 = (int *)fpilCreateTranslator();
        iVar9 = param_2[0xd];
        if (((iVar9 == 0) && (iVar9 = param_2[0xc], iVar9 == 0)) &&
           (iVar9 = param_2[0xb], iVar9 == 0)) {
          iVar9 = *(int *)(*param_2 + 4);
        }
        *piVar7 = iVar9;
        iVar12 = *(int *)(*param_2 + 0xc);
        piVar7[1] = *(int *)(*param_2 + 8);
        piVar7[2] = iVar12;
        piVar7[3] = *(int *)(*param_2 + 0x18);
        *(uint *)(piVar7[0xd] + 0x20) =
             ((byte)((unsigned char *)0x00002b7c)[param_1] & 1) << 0x17 |
             *(uint *)(piVar7[0xd] + 0x20) & 0xff7fffff;
        iVar10 = piVar7[0xd];
        *(uint *)(iVar10 + 0x20) =
             (*(uint *)(param_1 + 0x1ae4) & 0x3c0) << 0xc | *(uint *)(iVar10 + 0x20) & 0xffc3ffff;
        iVar9 = fragmentProgramToIL(piVar7);
        if (iVar9 == 0) {
          *piVar15 = 0;
          arbfpProgramStringIL(piVar15,0,piVar7[0xb],piVar7[10]);
          bVar3 = *piVar15 == 0;
          bVar4 = !bVar3;
          if (!bVar4) {
            iVar9 = piVar7[0xd];
            piVar7[0xd] = *piVar15;
            param_2[0xe] = iVar9;
            goto LAB_0002639c;
          }
        }
        else {
          bVar4 = !bVar3;
          if (!bVar4) goto LAB_0002639c;
        }
        if ((*(short *)*param_2 != -0x74d0) || ((uVar5 & 6) == 6)) break;
        if ((uVar5 & 4) == 0) {
          uVar5 = uVar5 | 4;
        }
        else if ((uVar5 & 2) == 0) {
          uVar5 = uVar5 & 0xfffffffb | 2;
        }
        if (param_2[0xb] != 0) {
          _glpFreePPShaderLinearize(param_2[0xb]);
          param_2[0xb] = 0;
        }
        if (param_2[0xc] != 0) {
          _glpFreePPShaderToProgram(param_2[0xc]);
          param_2[0xc] = 0;
        }
        if (param_2[0xd] != 0) {
          param_2[0xd] = 0;
        }
        freeIfNonNull(param_2[0xe]);
        param_2[0xe] = 0;
        fpilDestroyTranslator(piVar7);
      }
      if (bVar4) {
        if (*(short *)*param_2 == -0x74d0) {
          bVar4 = true;
        }
        else {
          *piVar15 = 0;
          iVar9 = param_2[0xd];
          if (((iVar9 == 0) && (iVar9 = param_2[0xc], iVar9 == 0)) &&
             (iVar9 = param_2[0xb], iVar9 == 0)) {
            iVar9 = *(int *)(*param_2 + 4);
          }
          iVar9 = arbProgramIrToText(iVar9);
          if (iVar9 == 0) {
            glDeleteProgramsARB_impl(piVar15,1,piVar14);
            *piVar14 = 0;
            return 0;
          }
          length = _strlen(iVar9);
          glProgramStringARB_impl(piVar15,0x8804,0x8875,length,iVar9,literalPool,iVar10,iVar12);
          _free(iVar9);
          bVar4 = *piVar15 != 0;
        }
      }
      else {
        bVar4 = false;
      }
LAB_0002639c:
      fpilDestroyTranslator(piVar7);
      if (bVar4) {
        *(undefined1 *)(param_2 + 10) = 1;
        return 0;
      }
    }
    uVar8 = 1;
    *(int **)(param_1 + 0x29ec) = piVar6;
  }
  return uVar8;
}

/* gld_bindProgramRecord @ 0x26440 (500 bytes) */
int gld_bindProgramRecord(ctx, programObject)
  int ctx;
  int *programObject;
{
  int *contextRecord;
  int iVar2;
  int commandStream;
  
  for (contextRecord = (int *)programObject[9]; contextRecord != programObject + 8; contextRecord = (int *)contextRecord[1]) {
    if (ctx == contextRecord[2]) goto LAB_000264f0;
  }
  contextRecord = (int *)_calloc(1,*(int *)(&DAT_001aa4c4 + programObject[7] * 4) + 0x14);
  contextRecord[3] = programObject[5] + -1;
  iVar2 = programObject[6];
  contextRecord[2] = ctx;
  contextRecord[1] = (int)(programObject + 8);
  contextRecord[4] = iVar2 + -1;
  *contextRecord = programObject[8];
  programObject[8] = (int)contextRecord;
  *(int **)(*contextRecord + 4) = contextRecord;
LAB_000264f0:
  commandStream = ctx + 0x240;
  iVar2 = FUN_0003b5b0(commandStream,contextRecord + 5);
  if (iVar2 != 0) {
    if (contextRecord[3] == programObject[5]) {
      iVar2 = extvsConstantsDirty(commandStream);
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
        iVar2 = _glpPPShaderLinearize(*(undefined4 *)((short *)*programObject + 2),0xff);
        programObject[0xb] = iVar2;
        if (iVar2 != 0) {
          iVar2 = _glpPPShaderToProgram(iVar2,*(undefined4 *)(*programObject + 0x18),0);
          programObject[0xc] = iVar2;
        }
      }
      iVar2 = programObject[0xd];
      if (((iVar2 == 0) && (iVar2 = programObject[0xc], iVar2 == 0)) && (iVar2 = programObject[0xb], iVar2 == 0)
         ) {
        iVar2 = *(int *)(*programObject + 4);
      }
      iVar2 = FUN_0003c400(commandStream,iVar2,contextRecord + 5);
    }
    if (iVar2 != 0) {
      *(int **)(ctx + 0x29e8) = contextRecord;
      return 1;
    }
  }
  return 0;
}

/* FUN_00026650 @ 0x26650 (792 bytes) */
int FUN_00026650(param_1, param_2)
  int param_1;
  int *param_2;
{
  short sVar1;
  uint uVar2;
  short *psVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  if (param_2[7] != 0) goto LAB_00026758;
  psVar3 = (short *)*param_2;
  if (psVar3[1] == 0) {
    if ((*psVar3 == -0x79e0) || (*psVar3 == -0x74cf)) {
      iVar4 = 1;
      goto LAB_00026698;
    }
LAB_00026694:
    iVar4 = 0;
  }
  else {
    if (psVar3[1] != 1) goto LAB_00026694;
    sVar1 = *psVar3;
    if ((sVar1 == -0x77fc) || (sVar1 == -0x74d0)) {
      iVar4 = 2;
    }
    else {
      iVar4 = 3;
      if (sVar1 != -0x7e00) goto LAB_00026694;
    }
  }
LAB_00026698:
  param_2[7] = iVar4;
  if (iVar4 == 0) {
    return 0;
  }
  param_2[8] = (int)(param_2 + 8);
  param_2[9] = (int)(param_2 + 8);
  iVar6 = *(int *)(param_1 + 0xc);
  iVar4 = *(int *)(iVar6 + 0x2c);
  param_2[4] = iVar6 + 0x2c;
  param_2[3] = iVar4;
  *(int **)(iVar6 + 0x2c) = param_2 + 3;
  *(int **)(param_2[3] + 4) = param_2 + 3;
LAB_00026758:
  uVar2 = param_2[0xf];
  if (uVar2 != 0) {
    if ((uVar2 & 1) != 0) {
      param_2[5] = param_2[5] + 1;
    }
    if ((uVar2 & 2) != 0) {
      param_2[6] = param_2[6] + 1;
    }
    param_2[0xf] = 0;
  }
  psVar3 = (short *)*param_2;
  if (psVar3[1] == 0) {
    if (*psVar3 == -0x79e0) {
      uVar2 = ((int (*)())gld_bindProgramRecord)(param_1,param_2);
      return uVar2;
    }
    if (*psVar3 == -0x74cf) {
      uVar2 = ((int (*)())gld_bindProgramRecord)(param_1,param_2);
      return uVar2 & 0xff;
    }
  }
  else if (psVar3[1] == 1) {
    sVar1 = *psVar3;
    if (sVar1 == -0x77fc) {
      uVar2 = ((int (*)())FUN_00025ec0)(param_1,param_2);
      return uVar2;
    }
    if (sVar1 == -0x74d0) {
      uVar2 = ((int (*)())FUN_00025ec0)(param_1,param_2);
      return uVar2 & 0xff;
    }
    if (sVar1 == -0x7e00) {
      piVar5 = (int *)param_2[9];
      piVar7 = param_2 + 8;
      if (piVar5 == piVar7) {
LAB_0002687c:
        piVar5 = (int *)_calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
        piVar5[3] = param_2[5] + -1;
        iVar4 = param_2[6];
        piVar5[2] = param_1;
        piVar5[1] = (int)piVar7;
        piVar5[4] = iVar4 + -1;
        *piVar5 = param_2[8];
        param_2[8] = (int)piVar5;
        *(int **)(*piVar5 + 4) = piVar5;
      }
      else {
        iVar4 = piVar5[2];
        while (iVar4 != param_1) {
          piVar5 = (int *)piVar5[1];
          if (piVar7 == piVar5) goto LAB_0002687c;
          iVar4 = piVar5[2];
        }
      }
      iVar4 = FUN_0003e3a0(param_1 + 0x240,piVar5 + 5);
      if (iVar4 != 0) {
        if (piVar5[3] != param_2[5]) {
          piVar5[3] = param_2[5];
          iVar4 = atifsReplayProgram(param_1 + 0x240,*(undefined4 *)(*param_2 + 4),piVar5 + 5);
          if (iVar4 == 0) {
            return 0;
          }
        }
        *(int **)(param_1 + 0x29ec) = piVar5;
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
    FUN_000a7ee0(ctx,0xffff);
    ((int (*)())FUN_00026650)(ctx,programObject);
    programHeader = (short *)*programObject;
    if (programHeader[1] == 0) {
      if (*programHeader == -0x79e0) {
        for (contextRecord = (int *)programObject[9]; contextRecord != programObject + 8; contextRecord = (int *)contextRecord[1]) {
          if (ctx == contextRecord[2]) goto LAB_00026ae0;
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
LAB_00026ae0:
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
  int iVar7;
  undefined4 *packetEnd;
  uint primFlagsIndirect;
  undefined4 vapVteCntl;
  uint primFlags;
  int iVar12;
  
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
      iVar7 = ctx + 0x2840;
      if (*(int *)(ctx + 0x2680) != iVar7) {
        vapVteCntl = *(undefined4 *)(ctx + 0x28e0);
        iVar12 = ctx + 0x2860;
        goto LAB_00026ea8;
      }
    }
    else {
      iVar7 = ctx + 0x28e4;
      if (*(int *)(ctx + 0x2680) != iVar7) {
        vapVteCntl = *(undefined4 *)(ctx + 0x2984);
        iVar12 = ctx + 0x2904;
LAB_00026ea8:
        *(int *)(ctx + 0x2680) = iVar7;
        *(int *)(ctx + 0x2684) = iVar12;
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
    iVar7 = (uint)vertexStrideWords * trimmedCount;
    *ringCursor = 0x82c;
    ringCursor[1] = *(undefined4 *)(0x00001dc4 + ctx);
    primFlags = *(uint *)(&DAT_001d9888 + primitiveMode * 4);
    ringCursor[2] = iVar7 * 0x10000 | 0xc0003500;
    ringCursor[3] = trimmedCount << 0x10 | primFlags & 0xf | 0x30;
    ringCursor[iVar7 + 4] = ((unsigned char *)0x00001393U);
    ringCursor[iVar7 + 5] = 0;
    *(undefined4 **)(ctx + 0x298c) = ringCursor + iVar7 + 6;
    *(undefined4 **)(ctx + 0x1dc) = ringCursor + iVar7 + 6;
    goto LAB_00026f60;
  }
  streamCountField = *(uint *)(ctx + 0x283c) & 0x1f;
  if (*(char *)(ctx + 0x27d4) == '\0') {
    vertexStrideWords = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + ctx) + 2);
  }
  else {
    vertexStrideWords = *(byte *)(*(int *)(0x000027d0 + ctx) + 2);
  }
  iVar12 = *(int *)(ctx + 0x1ec);
  ringCursor = *(undefined4 **)(ctx + 0x1dc);
  iVar7 = (uint)vertexStrideWords * trimmedCount * 4;
  *(int *)(ctx + 0x1ec) = iVar12 + iVar7;
  *(undefined4 **)(ctx + 0x298c) = ringCursor;
  lastHeader = *(uint **)(ctx + 0x1d8);
  *lastHeader = (int)ringCursor - (int)lastHeader >> 2 | *lastHeader;
  *(undefined4 **)(ctx + 0x1d8) = ringCursor;
  ringCursor[1] = streamCountField;
  ringCursor[2] = iVar12 - (int)ringCursor >> 2;
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
      goto LAB_00026d64;
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
LAB_00026d64:
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
    gldFlushDataCacheRange(ctx,iVar12,iVar7,vertexCount,staleArgR7,streamCountField,0xc0003400,packetEnd);
  }
LAB_00026f60:
  *(undefined1 *)(ctx + 0x2a5e) = 1;
  return;
}

/* FUN_00026f80 @ 0x26f80 (460 bytes) */
void FUN_00026f80(int ctx,uint *param_2,uint *param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
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
  
  activeCountPtr = param_3;
  if (((unsigned char *)0x00002b80)[ctx] != '\0') {
    activeCountPtr = param_2;
    staleFprArg1 = (double)((int (*)())FUN_0002be90)(ctx,1,param_2,param_4,param_5,param_6,param_7);
  }
  if (*(int *)(ctx + 0x1b68) != 0) {
    ((void (*)())gld_revalidateStreamProgram)(ctx + 0x240,param_2,activeCountPtr,param_4,param_5,param_6,param_7,staleFprArg1,staleFprArg2,
                 staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffff98);
  }
  if ((*param_3 == 0) || (*(int *)(*(int *)(ctx + 0x14) + 0x120) == 0)) {
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
  *param_3 = vertexCapacity;
  return;
}

/* FUN_00027150 @ 0x27150 (564 bytes) */
int FUN_00027150(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  if (param_4 < 4) {
    iVar5 = ((int (*)())gldTrimVertexCountToPrimitiveMin)(param_1,param_3,param_4);
  }
  else {
    iVar5 = ((int (*)())gldTrimVertexCountToPrimitive)(param_1,param_3,param_4);
  }
  if (iVar5 != 0) {
    uVar2 = *(uint *)(param_1 + 0x283c);
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      bVar1 = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + param_1) + 2);
    }
    else {
      bVar1 = *(byte *)(*(int *)(0x000027d0 + param_1) + 2);
    }
    puVar7 = *(undefined4 **)(param_1 + 0x1dc);
    iVar10 = *(int *)(param_1 + 500);
    iVar8 = *(int *)(param_1 + 0x1fc);
    *(uint *)(param_1 + 500) = iVar10 + (uint)bVar1 * iVar5 * 4;
    if (*(undefined4 **)(param_1 + 0x1e0) <= puVar7 + 0x53) {
      gld_submitRing(param_1,0x1000000);
      puVar7 = *(undefined4 **)(param_1 + 0x1dc);
    }
    puVar6 = puVar7;
    if (*(char *)(param_1 + 0x2a42) != '\0') {
      puVar6 = puVar7 + 2;
      *puVar7 = 0x5c8;
      puVar7[1] = 0x10000000;
      *(undefined1 *)(param_1 + 0x2a42) = 0;
    }
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x2840) {
        *(int *)(param_1 + 0x2680) = param_1 + 0x2840;
        *(int *)(param_1 + 0x2684) = param_1 + 0x2860;
        puVar6 = (undefined4 *)((int (*)())gld_emitVapStreamControl)(param_1,puVar6);
      }
      puVar3 = *(uint **)(param_1 + 0x1d8);
      iVar11 = param_1 + 0x2880;
      iVar9 = param_1 + 0x28a0;
    }
    else {
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x28e4) {
        *(int *)(param_1 + 0x2680) = param_1 + 0x28e4;
        *(int *)(param_1 + 0x2684) = param_1 + 0x2904;
        puVar6 = (undefined4 *)((int (*)())gld_emitVapStreamControl)(param_1,puVar6);
      }
      puVar3 = *(uint **)(param_1 + 0x1d8);
      iVar11 = param_1 + 0x2924;
      iVar9 = param_1 + 0x2944;
    }
    *puVar3 = (int)puVar6 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x1d8) = puVar6;
    *puVar6 = 0x36000000;
    uVar4 = *(undefined4 *)(param_1 + 0x200);
    puVar6[2] = uVar2 & 0x1f;
    puVar6[3] = iVar10 - iVar8;
    puVar6[1] = uVar4;
    *(int *)(param_1 + 0x26d4) = iVar11;
    *(int *)(param_1 + 0x26d8) = iVar9;
    *(undefined4 *)(param_1 + 0x26d0) = *(undefined4 *)(param_1 + 0x283c);
    puVar7 = (undefined4 *)((int (*)())gld_emitStreamAddressRegisters)(param_1,puVar6 + 4);
    uVar2 = *(uint *)(&DAT_001d9888 + param_3 * 4);
    *puVar7 = 0x82c;
    uVar4 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar7[4] = ((unsigned char *)0x00001393U);
    puVar7[2] = 0xc0003400;
    puVar7[5] = 0;
    puVar7[1] = uVar4;
    puVar7[3] = iVar5 << 0x10 | uVar2 & 0xf | 0x820;
    *(undefined4 **)(param_1 + 0x1dc) = puVar7 + 6;
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
  uint uVar5;
  uint uVar6;
  uint *activeCountPtr;
  uint uVar8;
  uint modeBit;
  uint fittingCount;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined4 *ringCursor;
  uint newModeWord;
  uint vertexStride;
  uint uVar17;
  uint uVar18;
  double staleStackArg_ffffff98;
  
  activeCountPtr = countInOut;
  if (((unsigned char *)0x00002b80)[ctx] != '\0') {
    activeCountPtr = altCountPtr;
    staleFprArg1 = (double)((int (*)())FUN_0002be90)(ctx,1,altCountPtr,staleArgR6,staleArgR7,staleArgR8,staleArgR9);
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
  uVar5 = *(uint *)(ctx + 0x27d8);
  if (!usesSecondRecord) {
    if ((uVar5 & 0x10) != 0) goto LAB_00027478;
LAB_00027458:
    modeBit = 1;
  }
  else {
    if ((uVar5 & 8) == 0) goto LAB_00027458;
LAB_00027478:
    modeBit = 2;
  }
  newModeWord = modeBit | uVar5 & 0x18;
  if (uVar5 != newModeWord) {
    *(int *)(ctx + 0x2680) = ctx + 0x26dc;
  }
  if ((modeBit & 2) == 0) {
    if (*(char *)(ctx + 0x27d4) == '\0') {
      if (*(int *)(ctx + 0x2680) != ctx + 0x2840) goto LAB_000276e0;
LAB_000276f8:
      iVar12 = 2;
      iVar11 = 4;
    }
    else {
      if (*(int *)(ctx + 0x2680) == ctx + 0x28e4) goto LAB_000276f8;
LAB_000276e0:
      uVar5 = *(int *)(ctx + 0x267c) + 1U & 0xfffffffe;
      iVar11 = uVar5 + 8;
      iVar12 = uVar5 + 6;
    }
    if (*(char *)(ctx + 0x2a42) == '\0') {
      iVar11 = iVar12 + 4;
    }
    if ((int)*countInOut < 0xc) {
      uVar5 = vertexStride * 0xc;
      fittingCount = 0xc;
    }
    else {
      fittingCount = ((int)*countInOut / 0xc) * 0xc;
      uVar5 = vertexStride * fittingCount;
      if (0x3fff < uVar5) {
        fittingCount = ((0x3fff / vertexStride) / 0xc) * 0xc;
        uVar5 = vertexStride * fittingCount;
      }
    }
    ringCursor = *(undefined4 **)(ctx + 0x1dc);
    if (*(undefined4 **)(ctx + 0x1e0) <=
        ringCursor + uVar5 + iVar11 + 2 + (uint)(*(byte *)(ctx + 8) >> 1) + 4) {
      gld_submitRing(ctx,0x1000000);
      ringCursor = *(undefined4 **)(ctx + 0x1dc);
    }
    uVar5 = (int)ringCursor + iVar11 * 4 + 0xf & 0xfffffff0;
    alignedRingEnd = (undefined4 *)(uVar5 + iVar11 * -4);
    *(undefined4 **)(ctx + 0x1dc) = alignedRingEnd;
    for (; ringCursor < alignedRingEnd; ringCursor = ringCursor + 1) {
      *ringCursor = 0x80000000;
    }
    if (*countInOut != 0) goto LAB_00027854;
    uVar8 = (((*(int *)(ctx + 0x1e0) - *(int *)(ctx + 0x1dc) >> 2) + -1) -
            (uint)(*(byte *)(ctx + 8) >> 1)) - (iVar11 + 2);
    if (0x600 < uVar8) {
      uVar8 = 0x600;
    }
  }
  else {
    uVar5 = *countInOut;
    fittingCount = 0x8b;
    if ((uVar5 != 0) && (fittingCount = 0x1000a, uVar5 < 0x10000)) {
      fittingCount = uVar5 + 0xb;
    }
    uVar8 = (uint)*(byte *)(ctx + 8);
    iVar12 = 0xc;
    fittingCount = (fittingCount / 0xc) * 0xc;
    uVar17 = vertexStride * fittingCount + (uint)(*(byte *)(ctx + 8) >> 1) + 0x20;
    if (*(char *)(ctx + 0x2a42) == '\0') {
      iVar12 = 10;
    }
    uVar18 = iVar12 + ((*(uint *)(ctx + 0x283c) & 0x1f) + 1 >> 1) * 3 + 3;
    if (!usesSecondRecord) {
      if (*(int *)(ctx + 0x2680) != ctx + 0x2840) goto LAB_00027540;
    }
    else if (*(int *)(ctx + 0x2680) != ctx + 0x28e4) {
LAB_00027540:
      uVar18 = uVar18 + (*(int *)(ctx + 0x267c) + 1U & 0xfffffffe) + 4;
    }
    uVar5 = *(uint *)(ctx + 0x1ec);
    if (uVar5 == 0) {
      uVar13 = *(uint *)(ctx + 0x1dc);
      iVar11 = *(int *)(ctx + 0x1e0);
      uVar5 = ((int)(iVar11 - uVar13) >> 2) - 1;
      if (uVar5 < uVar18 + uVar17) {
        if (*(int *)(ctx + 0x1e4) + 0x28U < uVar13) {
          gld_submitRing(ctx,0x1000000);
          uVar8 = (uint)*(byte *)(ctx + 8);
          uVar13 = *(uint *)(ctx + 0x1dc);
          iVar11 = *(int *)(ctx + 0x1e0);
        }
        iVar12 = iVar11 - uVar13;
LAB_00027630:
        uVar5 = (iVar12 >> 2) - 1;
        if (uVar5 < uVar18 + uVar17) {
          uVar17 = uVar5 - uVar18;
        }
      }
      uVar6 = uVar5 >> 2;
      if (uVar5 >> 2 < uVar17) {
        uVar6 = uVar17;
      }
      uVar17 = uVar5 - uVar6;
      if (uVar5 - uVar6 < uVar18) {
        uVar17 = uVar18;
      }
      iVar12 = iVar11 + 0x94;
      *(int *)(ctx + 0x1f0) = iVar12;
      uVar5 = uVar13 + uVar17 * 4 + 0x9f & 0xfffffff8;
      *(uint *)(ctx + 0x1e0) = uVar5;
      uVar5 = uVar5 + 0x7f & 0xffffff80;
      *(uint *)(ctx + 0x1ec) = uVar5;
    }
    else {
      uVar13 = *(uint *)(ctx + 0x1dc);
      iVar11 = *(int *)(ctx + 0x1e0);
      iVar12 = *(int *)(ctx + 0x1f0);
      if ((((int)(iVar11 - uVar13) >> 2) - 1U < uVar18) ||
         ((uint)((int)(iVar12 - uVar5) >> 2) < uVar17)) {
        if (*(int *)(ctx + 0x1e4) + 0x28U < uVar13) {
          gld_submitRing(ctx,0x1000000);
          uVar8 = (uint)*(byte *)(ctx + 8);
          uVar13 = *(uint *)(ctx + 0x1dc);
          iVar11 = *(int *)(ctx + 0x1e0);
        }
        iVar12 = iVar11 - uVar13;
        goto LAB_00027630;
      }
    }
    uVar8 = ((int)(iVar12 - uVar5) >> 2) - (uVar8 >> 1);
    if (vertexStride * fittingCount <= uVar8) goto LAB_00027854;
  }
  fittingCount = ((uVar8 / vertexStride) / 0xc) * 0xc;
LAB_00027854:
  *countInOut = fittingCount;
  uVar8 = (uint)*(byte *)(ctx + 8);
  if (uVar8 != 0x20) {
    if ((*(uint *)(ctx + 0x27d8) & 1) == 0) {
      uVar17 = *(uint *)(ctx + 0x2838);
    }
    else {
      uVar17 = *(uint *)(ctx + 0x2834);
    }
    uVar18 = uVar17;
    if (uVar17 <= uVar5) {
      uVar18 = (uVar5 + uVar8) - 1 & -uVar8;
    }
    vertexStride = uVar5 + vertexStride * fittingCount * 4;
    if (uVar17 <= vertexStride) {
      uVar17 = (vertexStride + uVar8) - 1 & -uVar8;
    }
    if (uVar18 < uVar17) {
      fittingCount = uVar17 - uVar18;
      for (vertexStride = fittingCount >> 9; vertexStride != 0; vertexStride = vertexStride - 1) {
        dataCacheBlockClearToZero(uVar18);
        dataCacheBlockClearToZero(uVar18 + uVar8);
        dataCacheBlockClearToZero(uVar18 + uVar8 * 2);
        dataCacheBlockClearToZero(uVar18 + uVar8 * 3);
        uVar18 = uVar18 + 0x200;
      }
      for (vertexStride = fittingCount >> 7 & 3; vertexStride != 0; vertexStride = vertexStride - 1) {
        dataCacheBlockClearToZero(uVar18);
        uVar18 = uVar18 + 0x80;
      }
      if ((modeBit & 1) == 0) {
        *(uint *)(ctx + 0x2838) = uVar17;
      }
      else {
        *(uint *)(ctx + 0x2834) = uVar17;
      }
    }
  }
  *(uint *)(ctx + 0x27d8) = newModeWord;
  return uVar5;
}

/* FUN_00027990 @ 0x27990 (2360 bytes) */
int FUN_00027990(param_1)
  int param_1;
{
  uint loopIndex2;
  uint loopIndex3;
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint *puVar17;
  uint uVar18;
  ushort uVar19;
  uint uVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  uint loopIndex;
  int iVar31;
  int iVar32;
  uint uVar33;
  int local_74;
  uint local_70;
  int local_68;
  int local_64;
  int local_60;
  
  *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
  *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
  *(undefined4 *)(param_1 + 0x2494) = 0;
  iVar31 = *(int *)(param_1 + 4);
  uVar29 = *(uint *)(param_1 + 0x243c);
  if ((((*(char *)(iVar31 + 0x20) == '\0') ||
       (*(int *)(((unsigned char *)0x00003170) + *(int *)(iVar31 + 0x10)) != 0x1b021b02)) || (uVar29 < 2)) ||
     (0x10 < uVar29)) {
    if ((*(int *)(*(int *)(iVar31 + 0x14) + 0x11c) == 0) &&
       (*(int *)(*(int *)(iVar31 + 0x14) + 0x120) == 0)) {
      return;
    }
switchD_00027e30_default:
    *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 2;
    *(undefined4 *)(*(int *)(iVar31 + 0x14) + 0x11c) = 0;
    *(undefined4 *)(*(int *)(iVar31 + 0x14) + 0x120) = 0;
    return;
  }
  if (*(int **)(iVar31 + 0x1cc) == (int *)0x0) {
    iVar27 = 0;
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
  }
  else {
    local_64 = *(int *)(**(int **)(iVar31 + 0x1cc) + 4);
    iVar27 = *(int *)(iVar31 + 0x29e8) + 0x14;
    local_60 = *(int *)(*(int *)(iVar31 + 0x29e8) + 0x34);
    local_68 = *(int *)(local_64 + 0x24);
  }
  puVar22 = *(undefined1 **)(param_1 + 0x258c);
  iVar7 = **(int **)(*(int *)(iVar31 + 0x18) + 0x194);
  *(undefined1 **)(*(int *)(iVar31 + 0x14) + 0x11c) = puVar22;
  puVar21 = *(undefined1 **)(param_1 + 0x2590);
  *(undefined1 **)(*(int *)(iVar31 + 0x14) + 0x120) = puVar21;
  if (*(char *)(param_1 + 0x2595) != '\0') {
    *(undefined4 *)(*(int *)(iVar31 + 0x14) + 0x120) = 0;
  }
  *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 2;
  iVar14 = param_1;
  for (uVar33 = uVar29 + 1 >> 1; uVar33 != 0; uVar33 = uVar33 - 1) {
    *(undefined4 *)(iVar14 + 0x26a4) = *(undefined4 *)(iVar14 + 0x1be4);
    *(undefined4 *)(iVar14 + 0x26c4) = *(undefined4 *)(iVar14 + 0x1c04);
    *(undefined4 *)(iVar14 + 0x2600) = *(undefined4 *)(iVar14 + 0x1be4);
    *(undefined4 *)(iVar14 + 0x2620) = *(undefined4 *)(iVar14 + 0x1c04);
    iVar14 = iVar14 + 4;
  }
  *(undefined4 *)(param_1 + 0x26a0) = *(undefined4 *)(param_1 + 0x1ca4);
  *(uint *)(param_1 + 0x25fc) = uVar29 & 0x1f | 0x20;
  if (*(int *)(iVar31 + 0x1cc) == 0) {
    iVar14 = *(int *)(param_1 + 4);
  }
  else {
    iVar14 = *(int *)(param_1 + 4);
    loopIndex2 = 0;
    iVar16 = 0;
    iVar10 = 0x16;
    bVar1 = *(int *)(iVar14 + 0x1cc) == 0;
    do {
      if (bVar1) {
        if ((1 << (loopIndex2 & 0x3f) & *(uint *)(param_1 + 0x1ca0)) != 0) goto LAB_00027b90;
      }
      else if ((*(int *)(iVar16 + *(int *)(iVar27 + 0x20)) != 0x80) ||
              (*(uint *)(iVar27 + 0x1c) <= loopIndex2)) {
LAB_00027b90:
        if (bVar1) {
          iVar32 = *(int *)(iVar16 + 0x1d9e58);
        }
        else {
          if (*(uint *)(iVar27 + 0x1c) <= loopIndex2) goto switchD_00027c3c_default;
          iVar32 = (local_68 + *(int *)(local_60 + iVar16)) * 8;
          uVar24 = *(uint *)(local_64 + iVar32);
          puVar17 = (uint *)(local_64 + iVar32);
          iVar32 = *(int *)(&DAT_001d9eb0 + (uVar24 >> 0xe & 0x3c));
          if (iVar32 == 8) {
            iVar32 = (uVar24 & 0x1f) + 8;
          }
          else if (iVar32 == 0x10) {
            iVar32 = (uVar24 & 0x1f) + 0x10;
          }
          else if (iVar32 == 0x2f) {
            switch(uVar24 >> 0xc & 0xf) {
            case 0:
              iVar32 = (*puVar17 & 1) + 0x20;
              break;
            case 1:
              iVar32 = (*puVar17 & 1) + 0x22;
              break;
            case 2:
              iVar32 = (*puVar17 & 1) + 0x24;
              break;
            case 3:
              iVar32 = (*puVar17 & 1) + 0x26;
              break;
            case 4:
              iVar32 = (*puVar17 & 1) + 0x28;
              break;
            default:
              goto switchD_00027c3c_default;
            }
          }
        }
        if ((iVar32 == 0) || (iVar32 == 0x10)) {
          bVar1 = true;
          goto LAB_00027d04;
        }
      }
switchD_00027c3c_default:
      iVar10 = iVar10 + -1;
      loopIndex2 = loopIndex2 + 1;
      iVar16 = iVar16 + 4;
    } while (iVar10 != 0);
  }
  bVar1 = false;
LAB_00027d04:
  iVar25 = 0;
  local_70 = 0;
  uVar33 = 0;
  iVar23 = 0;
  local_74 = 1;
  iVar32 = 0x16;
  loopIndex3 = 0;
  iVar10 = 0;
  loopIndex = 0;
  iVar26 = 0;
  iVar16 = param_1;
LAB_00027d44:
  bVar2 = *(int *)(iVar14 + 0x1cc) == 0;
  if (bVar2) {
    if ((1 << (loopIndex3 & 0x3f) & *(uint *)(param_1 + 0x1ca0)) != 0) goto LAB_00027d90;
    goto LAB_00028214;
  }
  if ((*(int *)(iVar26 + *(int *)(iVar27 + 0x20)) == 0x80) && (loopIndex3 < *(uint *)(iVar27 + 0x1c)))
  goto LAB_00028214;
LAB_00027d90:
  if (bVar2) {
    uVar12 = *(uint *)(iVar26 + 0x1d9e58);
LAB_00027eac:
    if (uVar12 == 0x30) goto switchD_00027e30_default;
    uVar20 = uVar12 & 0xffff;
  }
  else {
    if (loopIndex3 < *(uint *)(iVar27 + 0x1c)) {
      iVar14 = (local_68 + *(int *)(local_60 + iVar26)) * 8;
      uVar20 = *(uint *)(local_64 + iVar14);
      puVar17 = (uint *)(local_64 + iVar14);
      uVar12 = *(uint *)(&DAT_001d9eb0 + (uVar20 >> 0xe & 0x3c));
      if (uVar12 == 8) {
        uVar12 = (uVar20 & 0x1f) + 8;
      }
      else if (uVar12 == 0x10) {
        uVar12 = (uVar20 & 0x1f) + 0x10;
      }
      else if (uVar12 == 0x2f) {
        switch(uVar20 >> 0xc & 0xf) {
        case 0:
          uVar12 = (*puVar17 & 1) + 0x20;
          break;
        case 1:
          uVar12 = (*puVar17 & 1) + 0x22;
          break;
        case 2:
          uVar12 = (*puVar17 & 1) + 0x24;
          break;
        case 3:
          uVar12 = (*puVar17 & 1) + 0x26;
          break;
        case 4:
          uVar12 = (*puVar17 & 1) + 0x28;
          break;
        default:
          goto switchD_00027e30_default;
        }
      }
      goto LAB_00027eac;
    }
    uVar12 = 2;
    uVar20 = 2;
  }
  if ((bVar1) && ((uVar12 == 0 || (iVar10 = local_74, uVar12 == 0x10)))) {
    iVar10 = 0;
  }
  uVar8 = loopIndex >> 1;
  if (bVar2) {
    uVar18 = *(uint *)(iVar26 + 0x1d9edc) & 0xffff;
  }
  else {
    uVar18 = 3;
  }
  bVar2 = (loopIndex & 1) == 0;
  if (bVar2) {
    iVar14 = uVar8 * 4 + param_1;
    *(uint *)(iVar14 + 0x2640) = (uVar29 & 0x1f) << 10 | *(uint *)(iVar14 + 0x2640) & 0xffff8080 | 4
    ;
  }
  else {
    iVar14 = uVar8 * 4 + param_1;
    *(uint *)(iVar14 + 0x2640) =
         (uVar29 & 0x1f) << 0x1a | *(uint *)(iVar14 + 0x2640) & 0x8080ffff | 0x40000;
  }
  iVar14 = uVar8 * 4;
  uVar6 = (ushort)(uVar20 << 10);
  uVar19 = (ushort)(uVar18 << 8) | uVar6;
  *(int *)(loopIndex * 4 + param_1 + 0x2660) = iVar25;
  *(ushort *)(puVar22 + iVar10 * 2 + 4) = uVar19 | (ushort)iVar25;
  if (*(char *)(param_1 + 0x2595) == '\0') {
    uVar3 = *(ushort *)(uVar12 * 0x18 + iVar7 + 8);
    if (uVar12 < 0x10) {
      uVar33 = *(uint *)(iVar7 + 0x304);
    }
    else {
      uVar33 = *(uint *)(iVar7 + 0x300);
    }
    if ((uVar33 & *(uint *)(&DAT_001d9dd8 + uVar12 * 4)) == 0) {
      uVar33 = 4;
      uVar15 = 4;
      uVar20 = 3;
      uVar18 = 0;
      uVar12 = 0;
      uVar9 = 0;
      uVar11 = 1;
      uVar13 = 2;
      uVar28 = 3;
      uVar8 = 0;
    }
    else {
      iVar4 = ((uVar3 & 0xffff7fff) - 0x1400) * 4;
      iVar5 = (iVar4 + *(short *)(uVar12 * 0x18 + iVar7 + 10) + -1) * 4;
      uVar33 = *(uint *)(&DAT_001d9c4c + iVar5);
      uVar19 = (ushort)(*(int *)(&DAT_001d9cfc + iVar5) << 8) | uVar6;
      uVar12 = (uint)(uVar3 >> 0xf);
      uVar20 = *(uint *)(&DAT_001d9b9c + iVar5) & 0xff;
      uVar8 = *(uint *)(&DAT_001d9dac + iVar4) & 0xffff;
      uVar18 = *(uint *)(&DAT_001d9b70 + iVar4) & 0xff;
      uVar9 = *(uint *)(&DAT_001d9ac0 + iVar5) & 0xff;
      uVar15 = uVar33 & 0xff;
      uVar11 = *(uint *)(&DAT_001d9a10 + iVar5) & 0xff;
      uVar13 = *(uint *)(&DAT_001d9960 + iVar5) & 0xff;
      uVar28 = *(uint *)(&DAT_001d98b0 + iVar5) & 0xff;
    }
    if (bVar2) {
      *(uint *)(iVar14 + param_1 + 0x26e4) =
           uVar15 & 0x7f | *(uint *)(iVar14 + param_1 + 0x26e4) & 0xffffff80;
    }
    else {
      *(uint *)(iVar14 + param_1 + 0x26e4) =
           (uVar15 & 0x7f) << 0x10 | *(uint *)(iVar14 + param_1 + 0x26e4) & 0xff80ffff;
    }
    *(int *)(loopIndex * 4 + param_1 + 0x2704) = iVar23;
    if (bVar2) {
      iVar14 = iVar14 + param_1;
      *(uint *)(iVar14 + 0x26a4) =
           uVar12 << 0xf |
           (uVar18 & 1) << 0xe | uVar20 & 0xf | *(uint *)(iVar14 + 0x26a4) & 0xffff3ff0;
      *(uint *)(iVar14 + 0x26c4) =
           (uVar28 & 7) << 9 |
           (uVar13 & 7) << 6 |
           (uVar11 & 7) << 3 | uVar9 & 7 | *(uint *)(iVar14 + 0x26c4) & 0xfffff000;
    }
    else {
      iVar14 = iVar14 + param_1;
      *(uint *)(iVar14 + 0x26a4) =
           uVar12 << 0x1f |
           (uVar18 & 1) << 0x1e | (uVar20 & 0xf) << 0x10 | *(uint *)(iVar14 + 0x26a4) & 0x3ff0ffff;
      *(uint *)(iVar14 + 0x26c4) =
           (uVar28 & 7) << 0x19 |
           (uVar13 & 7) << 0x16 |
           (uVar11 & 7) << 0x13 | (uVar9 & 7) << 0x10 | *(uint *)(iVar14 + 0x26c4) & 0xf000ffff;
    }
    *(ushort *)(puVar21 + iVar10 * 2 + 4) = uVar19 | (ushort)(uVar8 << 6) | (ushort)iVar23;
  }
  *(uint *)(iVar16 + 0x259c) = loopIndex;
  iVar25 = iVar25 + 4;
  iVar23 = iVar23 + uVar33;
  loopIndex = loopIndex + 1;
  local_70 = local_70 + uVar33;
  if (!bVar1) {
    iVar10 = iVar10 + 1;
  }
  else if (iVar10 != 0) {
    local_74 = local_74 + 1;
  }
LAB_00028214:
  if (loopIndex == uVar29) {
LAB_00028238:
    if (*(char *)(param_1 + 0x2595) == '\0') {
      uVar24 = 0;
      bVar1 = false;
      *(uint *)(param_1 + 0x2744) = local_70 & 0x7f | *(uint *)(param_1 + 0x2744) & 0xffffff80;
      uVar33 = uVar29;
      do {
        if (bVar1) {
          iVar27 = (uVar24 & 0x7ffffffe) * 2 + param_1;
          *(uint *)(iVar27 + 0x26e4) =
               (local_70 & 0x7f) << 0x18 | *(uint *)(iVar27 + 0x26e4) & 0x80ffffff;
        }
        else {
          iVar27 = (uVar24 & 0x7ffffffe) * 2 + param_1;
          *(uint *)(iVar27 + 0x26e4) =
               (local_70 & 0x7f) << 8 | *(uint *)(iVar27 + 0x26e4) & 0xffff80ff;
        }
        uVar24 = uVar24 + 1;
        bVar1 = (bool)(bVar1 ^ 1);
        uVar33 = uVar33 - 1;
      } while (uVar33 != 0);
    }
    *puVar22 = (char)uVar29;
    *puVar21 = (char)uVar29;
    puVar22[1] = 0;
    puVar21[1] = 0;
    puVar22[2] = (char)(uVar29 << 2);
    puVar21[2] = (char)local_70;
    if (*(char *)(iVar31 + 8) == ' ') {
      uVar33 = 0x20;
      if (7 < uVar29 << 2) {
        puVar22[1] = puVar22[1] | 0x40;
        uVar33 = (uint)*(byte *)(iVar31 + 8);
      }
      if (uVar33 >> 2 <= local_70) {
        puVar21[1] = puVar21[1] | 0x40;
      }
    }
    *(uint *)(param_1 + 0x2598) = *(uint *)(param_1 + 0x2598) & 0xffffffe7;
    return;
  }
  loopIndex3 = loopIndex3 + 1;
  iVar26 = iVar26 + 4;
  iVar16 = iVar16 + 4;
  iVar32 = iVar32 + -1;
  if (iVar32 == 0) goto LAB_00028238;
  iVar14 = *(int *)(param_1 + 4);
  goto LAB_00027d44;
}

/* gld_readPixelsViaBlit @ 0x28350 (3820 bytes) */
int gld_readPixelsViaBlit(ctx, rectX, rectY, width, height, format, pixelType, pixels, param_9, surfaceInfo)
  int ctx;
  uint rectX;
  uint rectY;
  uint width;
  uint height;
  uint format;
  undefined *pixelType;
  int pixels;
  undefined4 param_9;
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
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  double i2dMagic;
  undefined *formatTable;
  uint uVar21;
  uint *lastHeader;
  int *surfaceRefPtr;
  int iVar24;
  uint *packetRaw;
  undefined4 *packet;
  uint uVar27;
  int unitObject;
  uint uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 *surfaceObject;
  uint uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  uint clampedWidth;
  uint clampedHeight;
  uint uVar38;
  int unitIndex;
  int ring;
  int hwFormat;
  char reservation;
  byte bVar42;
  int targetsLeft;
  uint rowBytes;
  undefined1 auStack_104 [4];
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
      goto LAB_000284b0;
      hwFormat = 0;
      if (pixelType == ((unsigned char *)0x00001403)) {
        hwFormat = 0x19;
        goto LAB_000284b0;
      }
    }
  }
  else if (format < 0x190a) {
    if (format == 0x1907) {
      hwFormat = 5;
      if ((pixelType != (undefined *)0x8363) && (hwFormat = 0x28, pixelType != (undefined *)0x8032)) {
        return 0;
      }
      goto LAB_000284b0;
    }
    if (format < 0x1908) {
      if (format != 0x1906) {
        return 0;
      }
      hwFormat = 2;
      if (pixelType != ((unsigned char *)0x00001401)) {
        hwFormat = 0x14;
        if ((pixelType == ((unsigned char *)0x00001406)) || (hwFormat = 0x20, pixelType == ((unsigned char *)0x0000140b)))
        goto LAB_000284b0;
        hwFormat = 0;
        if (pixelType == ((unsigned char *)0x00001403)) {
          hwFormat = 0x1a;
          goto LAB_000284b0;
        }
      }
      goto LAB_000283c0;
    }
    hwFormat = 0x12;
    if (pixelType == ((unsigned char *)0x00001406)) {
LAB_00028524:
      if (pixelType != (undefined *)0x8367) {
        if (pixelType == ((unsigned char *)0x00001401)) {
          hwFormat = 9;
          goto LAB_000284b0;
        }
        goto LAB_00028510;
      }
      hwFormat = 10;
    }
    else {
      hwFormat = 0x1e;
      if (pixelType != ((unsigned char *)0x0000140b)) {
        hwFormat = 0;
        if (pixelType != (undefined *)0x8035) goto LAB_00028524;
        hwFormat = 9;
      }
LAB_00028510:
      if (pixelType == (undefined *)0x8368) {
        hwFormat = 0x23;
        goto LAB_000284b0;
      }
    }
    if (pixelType == ((unsigned char *)0x00001403)) {
      hwFormat = 0x18;
      goto LAB_000284b0;
    }
  }
  else {
    if (format != 0x80e1) {
      if (format == 0x85b9) {
        hwFormat = 0x27;
        if ((pixelType != (undefined *)0x85ba) && (hwFormat = 0x26, pixelType != (undefined *)0x85bb)) {
          return 0;
        }
        goto LAB_000284b0;
      }
      if (format != 0x190a) {
        return 0;
      }
      hwFormat = 4;
      if (pixelType != ((unsigned char *)0x00001401)) {
        if (pixelType == ((unsigned char *)0x00001406)) {
          hwFormat = 0x16;
          goto LAB_000284b0;
        }
        hwFormat = 0x22;
        if (pixelType == ((unsigned char *)0x0000140b)) goto LAB_000284b0;
        hwFormat = 0;
        if (pixelType == ((unsigned char *)0x00001403)) {
          hwFormat = 0x1c;
          goto LAB_000284b0;
        }
      }
      goto LAB_000283c0;
    }
    hwFormat = 7;
    if (pixelType == (undefined *)0x8366) {
LAB_00028460:
      if (pixelType != (undefined *)0x8035) {
LAB_00028428:
        if (pixelType == ((unsigned char *)0x00001401)) {
          hwFormat = 8;
          goto LAB_000283c0;
        }
        goto LAB_0002844c;
      }
      hwFormat = 8;
LAB_00028474:
      if (pixelType == ((unsigned char *)0x00001406)) {
        hwFormat = 0x11;
        goto LAB_000284b0;
      }
      if (pixelType == ((unsigned char *)0x0000140b)) {
        hwFormat = 0x1d;
        goto LAB_000284b0;
      }
    }
    else {
      if (pixelType == (undefined *)0x8365) {
        hwFormat = 6;
        goto LAB_00028428;
      }
      hwFormat = 0;
      if (pixelType != (undefined *)0x8367) goto LAB_00028460;
      hwFormat = 0xb;
LAB_0002844c:
      if (pixelType != (undefined *)0x8368) goto LAB_00028474;
      hwFormat = 0x24;
    }
    if (pixelType == ((unsigned char *)0x00001403)) {
      hwFormat = 0x17;
      goto LAB_000284b0;
    }
  }
LAB_000283c0:
  if (hwFormat == 0) {
    return 0;
  }
LAB_000284b0:
  if ((((0x1000 < (int)width) || (0x1000 < (int)height)) || (0x1000 < *(int *)(ctx + GLD_renderWidth)))
     || (0x1000 < *(int *)(ctx + GLD_renderHeight))) {
    return 0;
  }
  _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
  lastHeader = &rowBytes;
  widthArg = width;
  heightArg = height;
  gld_computePixelStoreLayout(ctx,format,pixelType,width,height,lastHeader,auStack_104,packOffsets,
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
  uVar34 = 0x43300000;
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
  fVar9 = heightF - (float)((double)CONCAT44(0x43300000,rectBottomI2dLo) - DOUBLE_001aa1e0);
  rectRightF = (float)((double)CONCAT44(0x43300000,rectRightI2dLo) - DOUBLE_001aa1e0) + FLOAT_001aa0d4;
  fVar14 = rectXF;
  if (rectXF < 0.0) {
    fVar14 = FLOAT_001aa0d4;
  }
  negRectXF = (float)((double)CONCAT44(0x43300000,negRectXI2dLo) - DOUBLE_001aa1e0);
  flippedYF = (float)((double)CONCAT44(0x43300000,flippedYI2dLo) - DOUBLE_001aa1e0);
  fVar5 = (float)((double)CONCAT44(0x43300000,renderWidthI2dLo) - DOUBLE_001aa1e0);
  fVar6 = (float)((double)CONCAT44(0x43300000,renderHeightI2dLo) - DOUBLE_001aa1e0);
  fVar16 = FLOAT_001aa0d4;
  if (-rectXF < 0.0) {
    fVar16 = fVar14;
  }
  fVar12 = heightF - (float)((double)CONCAT44(0x43300000,rectYI2dLo) - DOUBLE_001aa1e0);
  fVar14 = FLOAT_001aa0d4;
  fVar18 = FLOAT_001aa148;
  if (FLOAT_001aa0d4 < fVar9) {
    fVar14 = fVar9;
    fVar18 = -fVar9;
  }
  fVar8 = fVar5 - rectRightF;
  fVar9 = fVar6 - fVar12;
  fVar18 = flippedYF + fVar18;
  fVar17 = fVar16 + negRectXF;
  if (fVar8 < 0.0) {
    rectRightF = fVar5;
  }
  if (fVar9 < 0.0) {
    fVar12 = fVar6;
  }
  fVar13 = fVar18 - heightF;
  fVar10 = fVar17;
  if (fVar17 < 0.0) {
    fVar10 = FLOAT_001aa0d4;
  }
  fVar15 = fVar5;
  if (-fVar8 < 0.0) {
    fVar15 = rectRightF;
  }
  fVar11 = heightF;
  if (fVar13 < 0.0) {
    fVar11 = fVar18;
  }
  fVar18 = fVar6;
  if (-fVar9 < 0.0) {
    fVar18 = fVar12;
  }
  fVar9 = FLOAT_001aa0d4;
  if (-fVar17 < 0.0) {
    fVar9 = fVar10;
  }
  negRectXF = fVar15 + negRectXF;
  if (-fVar13 < 0.0) {
    fVar11 = heightF;
  }
  flippedYF = flippedYF - fVar18;
  fVar2 = negRectXF - widthF;
  fVar12 = flippedYF;
  if (flippedYF < 0.0) {
    fVar12 = FLOAT_001aa0d4;
  }
  fVar8 = widthF;
  if (fVar2 < 0.0) {
    fVar8 = negRectXF;
  }
  fVar3 = FLOAT_001aa0d4;
  if (-flippedYF < 0.0) {
    fVar3 = fVar12;
  }
  if (-fVar2 < 0.0) {
    fVar8 = widthF;
  }
  if ((fVar8 <= fVar9) || (fVar11 <= fVar3)) {
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
    gldFlushDataCacheRangeSync(ctx,surfaceBase,clampedHeight * rowBytes,widthArg,heightArg,lastHeader,0,uVar34);
  }
  ring = ctx + GLD_commandStream;
  unitIndex = 0xf;
  streamPtr = (**(code **)(ctx + GLD_streamAllocate))(ring,0x343);
  *(undefined4 *)(ctx + GLD_streamCurrent) = streamPtr;
  iVar24 = ctx;
  do {
    if (*(int *)(iVar24 + 0x1c8) != 0) {
      streamPtr = ((int (*)())gld_emitUnitObjectPacket)(ctx,0,unitIndex,streamPtr);
    }
    unitIndex = unitIndex + -1;
    bVar42 = (unitIndex == 0) << 1;
    iVar24 = iVar24 + -4;
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
  uVar21 = packet[0x8f];
  packet[0xa1] =
       width & 0x3ffe | *(uint *)(formatTable + hwFormat * 0x24 + 0x18) >> 0xb & 0x180000 |
       (*(uint *)(formatTable + hwFormat * 0x24 + 0x18) & 0x3c00) << 0xb;
  uVar33 = *(uint *)(formatTable + hwFormat * 0x24 + 0x18) >> 5 & 0x1f;
  packet[0x8f] = uVar33 | uVar21 & 0xffffffe0;
  uVar29 = (*(uint *)(formatTable + hwFormat * 0x24 + 0x18) & 0x18) << 5;
  packet[0x8f] = uVar29 | uVar33 | uVar21 & 0xfffffce0;
  uVar38 = (*(uint *)(formatTable + hwFormat * 0x24 + 0x18) & 6) << 9;
  packet[0x8f] = uVar38 | uVar29 | uVar33 | uVar21 & 0xfffff0e0;
  uVar27 = *(uint *)(formatTable + hwFormat * 0x24 + 0x1c) >> 0x12 & 0x3000;
  packet[0x8f] = uVar27 | uVar38 | uVar29 | uVar33 | uVar21 & 0xffffc0e0;
  packet[0x8f] =
       *(uint *)(formatTable + hwFormat * 0x24 + 0x1c) >> 0xe & 0xc000 |
       uVar27 | uVar38 | uVar29 | uVar33 | uVar21 & 0xffff00e0;
  if ((*(uint *)(formatTable + hwFormat * 0x24 + 0x14) & 0xfc000000) == 0) {
    packet[0x5b] = packet[0x5b] & 0xfffe3fff | 0x18000;
  }
  heightI2dLo2 = height ^ 0x80000000;
  packet[0xb8] = clampedWidth - 1 & 0x1fff | (clampedHeight - 1) * 0x2000 & 0x3ffe000;
  i2dMagic = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa12c;
  fVar12 = FLOAT_001aa10c;
  heightI2dHi2 = 0x43300000;
  packetEnd = packet + 0xce;
  fVar5 = FLOAT_001aa0e8 / fVar5;
  fVar2 = FLOAT_001aa0e8 / fVar6;
  packet[0xc2] = 0x31080;
  packet[199] = ((unsigned char *)0x00001087U);
  fVar7 = (float)((double)CONCAT44(0x43300000,heightI2dLo2) - i2dMagic);
  packet[0xc5] = fVar15 * fVar5;
  packet[0xc3] = fVar16 * fVar5;
  packet[0xc6] = fVar2 * (fVar6 - fVar14);
  fVar3 = fVar7 - fVar3;
  packet[0xc4] = fVar2 * (fVar6 - fVar18);
  fVar7 = fVar7 - fVar11;
  hwFormat = (int)((fVar8 - fVar9) * fVar4);
  fctiwzScratch0 = (longlong)hwFormat;
  uVar33 = (uint)(int)((fVar3 - fVar7) * fVar4);
  fctiwzScratch1 = (longlong)(int)uVar33;
  packet[0xc9] = 0xc0033500;
  packet[0xca] = 0x10031;
  packet[0xcb] = (fVar9 + fVar8) * fVar12;
  packet[0xcc] = (fVar7 + fVar3) * fVar12;
  packet[0xcd] = 0;
  packet[200] = hwFormat << 0x10 | uVar33;
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
  uVar34 = *(undefined4 *)(GLD_vap_vte_cntl + ctx);
  packet[0xeb] = ((unsigned char *)0x000010aeU);
  packet[0x18c] = uVar34;
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
  uVar34 = *(undefined4 *)(0x000026c8 + ctx + GLD_connect);
  packet[0xf9] = 0x854;
  packet[0xf8] = uVar34;
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
  uVar33 = *(uint *)(ctx + GLD_rb3d_blendcntl);
  packet[0x106] = uVar33;
  if ((*(uint *)(formatTable + (uint)(byte)((unsigned char *)GLD_colorFormatIndex)[ctx] * 0x24 + 0x18) & 0x4000) == 0) {
    packet[0x106] = uVar33 & 0xfffffffc;
  }
  packet[0x107] = ((unsigned char *)0x0000109eU);
  uVar35 = 0xc0221000;
  uVar31 = 0xaaaa;
  uVar30 = 0x110f8;
  unitIndex = 0;
  unitOffset = 0;
  uVar34 = *(undefined4 *)(ctx + 0x1d6c);
  packet[0x109] = ((unsigned char *)0x00001096U);
  packet[0x108] = uVar34;
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
  FUN_0004c100(packet + 0xd0,ring);
  packet = packet + 0x18d;
  hwFormat = ctx;
  do {
    unitObject = *(int *)(hwFormat + 0x18c);
    if (unitObject != 0) {
      targetsLeft = 5;
      targetSlot = (int *)(unitOffset + *(int *)(ctx + GLD_engineObjects));
      do {
        if (unitObject == *targetSlot) {
          if (*(int *)(unitObject + 0x34) != 0) goto LAB_0002918c;
          break;
        }
        targetSlot = targetSlot + 1;
        targetsLeft = targetsLeft + -1;
      } while (targetsLeft != 0);
      unitObject = 0;
    }
LAB_0002918c:
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
        gldFlushDataCacheRangeSync(ctx,*(int *)*surfaceInfo,clampedHeight * rowBytes,packet,uVar30,uVar31,surfaceInfo,
                     uVar35);
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
  int iVar6;
  int iVar7;
  undefined4 result;
  void *scratchBuffer;
  undefined4 *ropPacket;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint *puVar13;
  int iVar14;
  uint surfaceType;
  int iVar16;
  int iVar17;
  uint transferMode8;
  int *boundFramebuffer;
  int *piVar20;
  uint uStack_e8;
  int iStack_e4;
  int aiStack_e0 [3];
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
  undefined1 auStack_a4 [4];
  undefined1 auStack_a0 [4];
  undefined4 uStack_9c;
  uint procFlags;
  undefined *procMask;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  uint uStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  uint uStack_70;
  uint uStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined1 uStack_50;
  
  commandStream = ctx + GLD_commandStream;
  uStack_84 = 0;
  aiStack_e0[1] = 0;
  uStack_88 = 0;
  transferMode8 = transferMode & 0xff;
  engineState = *(int *)(ctx + GLD_engineState);
  readSurfaceCode = gld_textureVariantClass((uint)*(ushort *)(((unsigned char *)0x00002db8) + engineState),*(undefined4 *)(ctx + GLD_renderFlags));
  if (((((*(uint *)(((unsigned char *)0x000030b0) + engineState) & 0x1ff) == 0) &&
       ((*(uint *)(((unsigned char *)0x000030b4) + engineState) & 0xff0000) == 0)) || (format - 0x1901U < 2)) ||
     (transferMode8 == 2)) {
    iVar6 = 0;
    sendAttachments = false;
  }
  else if ((*(uint *)(((unsigned char *)0x000030b0) + engineState) & 2) == 0) {
    if (((*(uint *)(((unsigned char *)0x000030b0) + engineState) & 4) == 0) ||
       (*(short *)(((unsigned char *)0x00002fe8) + engineState) != -0x7fea)) goto LAB_000293b0;
    sendAttachments = true;
    iVar6 = *(int *)(((unsigned char *)0x00002ff0) + engineState) + -1;
  }
  else if (*(short *)(((unsigned char *)0x00002fa8) + engineState) == -0x7fea) {
    sendAttachments = true;
    iVar6 = *(int *)(((unsigned char *)0x00002fb0) + engineState) + -1;
  }
  else {
LAB_000293b0:
    iVar6 = 0;
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
    puVar13 = &uStack_e8;
    piVar20 = &iStack_e4;
    iVar17 = height;
    gld_computePixelStoreLayout(ctx,format,pixelType,width - iVar6,height,puVar13,piVar20,aiStack_e0,packStateArg);
    dstAddress = pixels + aiStack_e0[0];
    if (rectY < 0) {
      height = height + rectY;
      yOffsetBytes0 = rectY * uStack_e8;
      rectY = 0;
      dstAddress = dstAddress - yOffsetBytes0;
    }
    if (rectX < 0) {
      width = width + rectX;
      iStack_e4 = rectX * iStack_e4;
      rectX = 0;
      dstAddress = dstAddress - iStack_e4;
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
      uStack_50 = 0;
      uStack_9c = 2;
      puVar11 = auStack_a4;
      puVar12 = auStack_a0;
      srcRowBytes = uStack_e8;
      iStack_90 = width;
      iStack_8c = height;
      _glgConvertType(format,pixelType,puVar11,puVar12);
      boundFramebuffer = *(int **)(ctx + GLD_boundFramebuffer);
      if (boundFramebuffer == (int *)0x0) {
        aiStack_e0[2] = rectX;
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
LAB_000298a4:
              requestFormat = 4;
            }
            else {
LAB_00029878:
              if (readSurfaceCode == 7) {
                requestFormat = 10;
              }
              else {
                if (readSurfaceCode != 8) goto LAB_000298a4;
                requestFormat = 0xb;
              }
            }
LAB_000299f8:
            if ((sendAttachments) ||
               ((((convertPixels && (((*(uint *)(((unsigned char *)0x000030b4) + engineState) & 0xff1) != 0 ||
                             ((*(uint *)(((unsigned char *)0x00002e68U) + engineState) & 0xffff0000) != 0)))) ||
                 (format - 0x1901U < 2)) ||
                ((((srcRowBytes & 0x3f) != 0 || (0x1fff < (int)srcRowBytes)) ||
                 ((dstAddress & 0x1f) != 0)))))) {
LAB_00029a74:
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
              if (requestAddress == 0) goto LAB_00029bd0;
              directCopy = false;
            }
            else {
              if ((renderFlags & 0xf) == 4) {
                if ((format != 0x80e1) || (pixelType != 0x8367)) goto LAB_00029a74;
              }
              else if ((((renderFlags & 0xf) != 3) || (format != 0x80e1)) || (pixelType != 0x8366))
              goto LAB_00029a74;
              directCopy = true;
              requestPitch = srcRowBytes;
              requestAddress = dstAddress;
            }
            procPixels = requestAddress;
            if (sendAttachments) {
              engineObjects = *(int *)(ctx + GLD_engineObjects);
              iVar7 = *(int *)(*(int *)(engineObjects + 0x140) + 0x30);
              uStack_80 = (uint)*(ushort *)(iVar7 + 0x98);
              uStack_7c = (uint)*(ushort *)(iVar7 + 0x9a);
              uStack_78 = (uint)*(ushort *)(iVar7 + 0x8c);
              uStack_74 = *(undefined4 *)(iVar7 + 0x9c);
              iVar7 = *(int *)(*(int *)(engineObjects + 0x148) + 0x30);
              uStack_70 = (uint)*(ushort *)(iVar7 + 0x98);
              uStack_6c = (uint)*(ushort *)(iVar7 + 0x9a);
              uStack_68 = (uint)*(ushort *)(iVar7 + 0x8c);
              uStack_64 = *(undefined4 *)(iVar7 + 0x9c);
              iVar7 = *(int *)(*(int *)(engineObjects + 0x144) + 0x30);
              uStack_60 = (uint)*(ushort *)(iVar7 + 0x98);
              uStack_5c = (uint)*(ushort *)(iVar7 + 0x9a);
              uStack_58 = (uint)*(ushort *)(iVar7 + 0x8c);
              uStack_54 = *(undefined4 *)(iVar7 + 0x9c);
            }
            status = _io_connect_method_structureI_structureO
                              (*(undefined4 *)(ctx + GLD_connect),7,aiStack_e0 + 2,0x1c,0,aiStack_e0 + 1);
            if (status != 0) goto LAB_00029bd0;
            if (!directCopy) {
              _glgProcessPixels(packState,&procPixels);
              return 1;
            }
          }
        }
        else {
          if (format != 0x1902) {
            prepareResult = FUN_0001a010(ctx,readSurfaceCode,puVar11,puVar12,iVar17,puVar13,piVar20);
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
            goto LAB_000299f8;
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
            if ((renderFlags & 0x2000) != 0) goto LAB_00029878;
            goto LAB_000298a4;
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
            iVar16 = *(int *)(ctx + GLD_engineObjects);
            iVar14 = *(int *)(*(int *)(iVar16 + 0x140) + 0x30);
            uStack_80 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_7c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_78 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_74 = *(undefined4 *)(iVar14 + 0x9c);
            iVar14 = *(int *)(*(int *)(iVar16 + 0x148) + 0x30);
            uStack_70 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_6c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_68 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_64 = *(undefined4 *)(iVar14 + 0x9c);
            iVar14 = *(int *)(*(int *)(iVar16 + 0x144) + 0x30);
            uStack_60 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_5c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_58 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_54 = *(undefined4 *)(iVar14 + 0x9c);
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
          FUN_00031340(ctx,attachObject,attachFace,attachLevel,surfaceFormat,surfaceType,levelBuffer,procPitch);
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
LAB_00029bd0:
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
  int iVar6;
  dword *readSurfaceCode;
  undefined4 scratchBuffer;
  int savedHeight;
  undefined4 *ropPacket;
  dword *a2;
  undefined1 *a3;
  undefined4 uVar11;
  uint *a5;
  undefined4 *a1;
  uint uVar12;
  uint uVar13;
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
  int *piVar24;
  uint uStack_e8;
  int iStack_e4;
  int aiStack_e0 [3];
  int requestY;
  int requestWidth;
  int requestHeight;
  dword *pdStack_c8;
  uint requestAddress;
  uint requestPitch;
  uint uStack_bc;
  uint procPitch;
  uint uStack_b4;
  uint uStack_b0;
  uint dstAddress;
  uint srcRowBytes;
  dword dStack_a4;
  undefined1 auStack_a0 [4];
  undefined4 uStack_9c;
  uint procFlags;
  undefined *puStack_94;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  uint uStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  uint uStack_70;
  uint uStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined1 uStack_50;
  
  ring = ctx + GLD_commandStream;
  uStack_84 = 0;
  aiStack_e0[1] = 0;
  uStack_88 = 0;
  flags = transferMode & 0xff;
  ctxState = *(int *)(ctx + GLD_engineState);
  readSurfaceCode = (dword *)gld_textureVariantClass((uint)*(ushort *)(((unsigned char *)0x00002db8) + ctxState),
                                 *(undefined4 *)(ctx + GLD_renderFlags));
  if (((((*(uint *)(((unsigned char *)0x000030b0) + ctxState) & 0x1ff) == 0) &&
       ((*(uint *)(((unsigned char *)0x000030b4) + ctxState) & 0xff0000) == 0)) || (format - 0x1901U < 2)) ||
     (flags == 2)) {
    iVar6 = 0;
    sendAttachments = false;
  }
  else if ((*(uint *)(((unsigned char *)0x000030b0) + ctxState) & 2) == 0) {
    if (((*(uint *)(((unsigned char *)0x000030b0) + ctxState) & 4) == 0) ||
       (*(short *)(((unsigned char *)0x00002fe8) + ctxState) != -0x7fea)) goto LAB_000293b0;
    sendAttachments = true;
    iVar6 = *(int *)(((unsigned char *)0x00002ff0) + ctxState) + -1;
  }
  else if (*(short *)(((unsigned char *)0x00002fa8) + ctxState) == -0x7fea) {
    sendAttachments = true;
    iVar6 = *(int *)(((unsigned char *)0x00002fb0) + ctxState) + -1;
  }
  else {
LAB_000293b0:
    iVar6 = 0;
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
    a5 = &uStack_e8;
    piVar24 = &iStack_e4;
    savedHeight = height;
    gld_computePixelStoreLayout(ctx,format,pixelType,width - iVar6,height,a5,piVar24,aiStack_e0,packStateArg);
    dstOffsetAddress = pixels + aiStack_e0[0];
    if (rectY < 0) {
      height = height + rectY;
      yOffsetBytes0 = rectY * uStack_e8;
      rectY = 0;
      dstOffsetAddress = dstOffsetAddress - yOffsetBytes0;
    }
    if (rectX < 0) {
      width = width + rectX;
      iStack_e4 = rectX * iStack_e4;
      rectX = 0;
      dstOffsetAddress = dstOffsetAddress - iStack_e4;
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
        puStack_94 = ((unsigned char *)0x0007efffU);
        if (((unsigned char *)0x00002e68)[ctxState] != '\0') {
          procFlags = procFlags | 2;
        }
        if (((unsigned char *)0x00002e69)[ctxState] != '\0') {
          procFlags = procFlags | 8;
        }
      }
      else {
        packState = (undefined *)0x0;
        puStack_94 = (undefined *)0x0;
        procFlags = 0;
      }
      uStack_50 = 0;
      uStack_9c = 2;
      a2 = &dStack_a4;
      a3 = auStack_a0;
      srcRowBytes = uStack_e8;
      dstAddress = dstOffsetAddress;
      iStack_90 = width;
      iStack_8c = height;
      _glgConvertType(format,pixelType,a2,a3,savedHeight,a5,piVar24,dstOffsetAddress);
      boundFramebuffer = *(int **)(ctx + GLD_boundFramebuffer);
      if (boundFramebuffer == (int *)0x0) {
        aiStack_e0[2] = rectX;
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
            uStack_b0 = 0x14;
            uStack_b4 = 0xf;
            if ((flags & 0x2000) == 0) {
LAB_000298a4:
              pdStack_c8 = ((unsigned char *)0x4);
            }
            else {
LAB_00029878:
              if (readSurfaceCode == (dword *)((int)((unsigned char *)0x4) + 3)) {
                pdStack_c8 = (dword *)((int)((unsigned char *)0x8) + 2);
              }
              else {
                if (readSurfaceCode != ((unsigned char *)0x8)) goto LAB_000298a4;
                pdStack_c8 = (dword *)((int)((unsigned char *)0x8) + 3);
              }
            }
LAB_000299f8:
            uVar12 = flags & 0xf;
            if ((sendAttachments) ||
               ((((convertPixels && (((*(uint *)(((unsigned char *)0x000030b4) + ctxState) & 0xff1) != 0 ||
                             ((*(uint *)(((unsigned char *)0x00002e68U) + ctxState) & 0xffff0000) != 0)))) ||
                 (format - 0x1901U < 2)) ||
                ((((srcRowBytes & 0x3f) != 0 || (0x1fff < (int)srcRowBytes)) ||
                 ((dstAddress & 0x1f) != 0)))))) {
LAB_00029a74:
              uVar12 = *(uint *)(((unsigned char *)GLD_readScratchSize) + ctx);
              requestPitch = procPitch;
              scratchBytes = height * procPitch + 0xfff & 0xfffff000;
              if (uVar12 < scratchBytes) {
                if (*(int *)(((unsigned char *)GLD_readScratchBuffer) + ctx) != 0) {
                  _vfree(*(int *)(((unsigned char *)GLD_readScratchBuffer) + ctx));
                }
                scratchBuffer = _valloc(scratchBytes);
                *(uint *)(((unsigned char *)GLD_readScratchSize) + ctx) = scratchBytes;
                *(undefined4 *)(((unsigned char *)GLD_readScratchBuffer) + ctx) = scratchBuffer;
              }
              requestAddress = *(uint *)(((unsigned char *)GLD_readScratchBuffer) + ctx);
              if (requestAddress == 0) goto LAB_00029bd0;
              directCopy = false;
            }
            else {
              if (uVar12 == 4) {
                if ((format != 0x80e1) || (pixelType != 0x8367)) goto LAB_00029a74;
              }
              else if (((uVar12 != 3) || (format != 0x80e1)) || (pixelType != 0x8366))
              goto LAB_00029a74;
              directCopy = true;
              requestPitch = srcRowBytes;
              requestAddress = dstAddress;
            }
            uStack_bc = requestAddress;
            if (sendAttachments) {
              flags = *(uint *)(ctx + GLD_engineObjects);
              ring = *(int *)(*(int *)(flags + 0x140) + 0x30);
              uStack_80 = (uint)*(ushort *)(ring + 0x98);
              uStack_7c = (uint)*(ushort *)(ring + 0x9a);
              uStack_78 = (uint)*(ushort *)(ring + 0x8c);
              uStack_74 = *(undefined4 *)(ring + 0x9c);
              ring = *(int *)(*(int *)(flags + 0x148) + 0x30);
              uStack_70 = (uint)*(ushort *)(ring + 0x98);
              uStack_6c = (uint)*(ushort *)(ring + 0x9a);
              uStack_68 = (uint)*(ushort *)(ring + 0x8c);
              uStack_64 = *(undefined4 *)(ring + 0x9c);
              uVar12 = *(uint *)(flags + 0x144);
              ring = *(int *)(uVar12 + 0x30);
              uStack_60 = (uint)*(ushort *)(ring + 0x98);
              uStack_5c = (uint)*(ushort *)(ring + 0x9a);
              uStack_58 = (uint)*(ushort *)(ring + 0x8c);
              uStack_54 = *(undefined4 *)(ring + 0x9c);
            }
            requestPtr = aiStack_e0 + 2;
            requestBytes = 0x1c;
            uVar11 = 0;
            replySizePtr = aiStack_e0 + 1;
            ring = _io_connect_method_structureI_structureO
                               (*(undefined4 *)(ctx + GLD_connect),7,requestPtr,0x1c,0,replySizePtr);
            if (ring != 0) goto LAB_00029bd0;
            if (!directCopy) {
              _glgProcessPixels(packState,&uStack_bc,requestPtr,requestBytes,uVar11,replySizePtr,uVar12,flags);
              return 1;
            }
          }
        }
        else {
          if (format != 0x1902) {
            prepareResult = FUN_0001a010(ctx,readSurfaceCode,a2,a3,savedHeight,a5,piVar24);
            if (prepareResult != 0) {
              a3 = (undefined1 *)0x0;
              savedHeight = 0;
              a5 = (uint *)0x0;
              a2 = readSurfaceCode;
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
              a1 = ropPacket + 2;
              *ropPacket = ((unsigned char *)0x00001386U);
              ropPacket[1] = *(undefined4 *)(ctx + GLD_rb3d_ropcntl);
              *(undefined4 **)(ctx + GLD_streamCurrent) = a1;
              (**(code **)(ctx + GLD_streamSetCurrent))(ring,a1,a2,a3,savedHeight,a5,a1);
            }
            formatIndex = ((unsigned char *)GLD_colorFormatIndex)[ctx];
            flags = *(uint *)(ctx + GLD_renderFlags);
            procPitch = (width << (*(uint *)(PTR_DAT_001e88c8 + (uint)formatIndex * 0x24 + 0x14) & 7)) +
                        0x1fU & 0xffffffe0;
            uStack_b0 = *(uint *)(PTR_DAT_001e88c8 + (uint)formatIndex * 0x24 + 0x10) >> 0x16 & 0x1f;
            uStack_b4 = *(uint *)(PTR_DAT_001e88c8 + (uint)formatIndex * 0x24 + 0x10) >> 0x1b;
            pdStack_c8 = readSurfaceCode;
            goto LAB_000299f8;
          }
          flags = *(uint *)(ctx + GLD_renderFlags);
          if ((flags & 0x30000) != 0) {
            if (*(int *)(ctx + GLD_ringMap) + 0x28U < *(uint *)(ctx + GLD_writeCursor)) {
              gld_submitRing(ctx,0x1000000);
              flags = *(uint *)(ctx + GLD_renderFlags);
            }
            if ((flags & 0x20000) == 0) {
              uStack_b0 = 2;
              procPitch = (width + 0x1f) * 2 & 0xffffffc0;
              uStack_b4 = 0xd;
            }
            else {
              procPitch = (width + 0xf) * 4 & 0xffffffc0;
              if ((flags & 0x30000) == 0x30000) {
                uStack_b4 = 0xf;
                uStack_b0 = 0x14;
              }
              else {
                uStack_b4 = 0xd;
                uStack_b0 = 4;
              }
            }
            if ((flags & 0x2000) != 0) goto LAB_00029878;
            goto LAB_000298a4;
          }
        }
      }
      else {
        ring = 5;
        if ((format != 0x1901) && (ring = 4, format != 0x1902)) {
          procFlags = procFlags | 0x60000;
          puStack_94 = (undefined *)((uint)puStack_94 | 0x68002);
          ring = *(ushort *)(*boundFramebuffer + 0x98) - 0x8ce0;
          if ((convertPixels) &&
             (((*(uint *)(packState + 0x268) & 0x1ff) != 0 ||
              ((*(uint *)(packState + 0x26c) & 0xff0000) != 0)))) {
            dstOffsetAddress = *(uint *)(ctx + GLD_engineObjects);
            ctxState = *(int *)(*(int *)(dstOffsetAddress + 0x140) + 0x30);
            uStack_80 = (uint)*(ushort *)(ctxState + 0x98);
            uStack_7c = (uint)*(ushort *)(ctxState + 0x9a);
            uStack_78 = (uint)*(ushort *)(ctxState + 0x8c);
            uStack_74 = *(undefined4 *)(ctxState + 0x9c);
            ctxState = *(int *)(*(int *)(dstOffsetAddress + 0x148) + 0x30);
            uStack_70 = (uint)*(ushort *)(ctxState + 0x98);
            uStack_6c = (uint)*(ushort *)(ctxState + 0x9a);
            uStack_68 = (uint)*(ushort *)(ctxState + 0x8c);
            uStack_64 = *(undefined4 *)(ctxState + 0x9c);
            ctxState = *(int *)(*(int *)(dstOffsetAddress + 0x144) + 0x30);
            uStack_60 = (uint)*(ushort *)(ctxState + 0x98);
            uStack_5c = (uint)*(ushort *)(ctxState + 0x9a);
            uStack_58 = (uint)*(ushort *)(ctxState + 0x8c);
            uStack_54 = *(undefined4 *)(ctxState + 0x9c);
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
          _glgConvertType(surfaceFormat,surfaceType,&uStack_b4,&uStack_b0,savedHeight,ring,*attachObject,dstOffsetAddress);
          ctxState = *(int *)(ctx + GLD_renderWidth);
          ring = gldPixelUnitBytes(surfaceFormat,surfaceType);
          procPitch = ctxState * ring;
          renderHeight = procPitch * *(int *)(ctx + GLD_renderHeight);
          levelBuffer = _valloc((uint)sliceCount * renderHeight);
          flags = surfaceFormat;
          uVar12 = surfaceType;
          ring = levelBuffer;
          uVar13 = procPitch;
          FUN_00031340(ctx,attachObject,attachFace,attachLevel,surfaceFormat,surfaceType,levelBuffer,procPitch);
          ctxState = rectY * procPitch;
          bytesPerPixel = gldPixelUnitBytes(surfaceFormat,surfaceType);
          uStack_bc = levelBuffer + attachZOffset * renderHeight + ctxState + rectX * bytesPerPixel;
          _glgProcessPixels(packState,&uStack_bc,attachFace,attachLevel,flags,uVar12,ring,uVar13);
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
LAB_00029bd0:
    result = 0;
  }
  return result;
}

/* FUN_00029c00 @ 0x29c00 (1624 bytes) */
int FUN_00029c00(ctx, param_2, procWidth, procHeight, srcRowBytes, bytesPerPixel, param_7, param_8, pfStack0000001c, format, transferMode8)
  int ctx;
  float *param_2;
  int procWidth;
  int procHeight;
  float *srcRowBytes;
  int bytesPerPixel;
  uint param_7;
  uint param_8;
  int pfStack0000001c;
  int format;
  undefined4 transferMode8;
{
  int loopIndex;
  uint uVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  double dVar7;
  float fVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 r4AfterCall;
  float *pfVar13;
  float *pfVar14;
  float *pfVar15;
  float *pfVar16;
  float *pfVar17;
  float fVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  float local_168;
  float local_164;
  float local_160;
  float local_15c;
  undefined4 local_158;
  float local_154;
  float local_150;
  float local_14c;
  float afStack_148 [36];
  undefined4 local_b8;
  undefined4 uStack_b4;
  longlong local_b0;
  undefined4 local_a8;
  float *pfStack_a4;
  undefined4 i2dHi2;
  uint i2dLo2;
  undefined4 local_98;
  undefined4 uStack_94;
  longlong local_90;
  undefined4 i2dHi1;
  uint i2dLo1;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  float *pfStack_74;
  undefined4 local_70;
  uint uStack_6c;
  undefined4 local_68;
  uint uStack_64;
  
  iVar21 = ctx + 0x240;
  iVar20 = procWidth * procHeight;
  uVar19 = *(undefined4 *)(ctx + 0x248);
  iVar9 = *(int *)(*(int *)(ctx + 0x244) + 0x10);
  fVar4 = FLOAT_001aa0e8;
  if (*(float *)(((unsigned char *)0x00002e4c) + iVar9) < 0.0) {
    fVar4 = FLOAT_001aa114;
  }
  fVar3 = FLOAT_001aa0e8;
  if (*(float *)(((unsigned char *)0x00002e48) + iVar9) < 0.0) {
    fVar3 = FLOAT_001aa114;
  }
  if (-*(float *)(((unsigned char *)0x00002e4c) + iVar9) < 0.0) {
    fVar4 = FLOAT_001aa0e8;
  }
  if (-*(float *)(((unsigned char *)0x00002e48) + iVar9) < 0.0) {
    fVar3 = FLOAT_001aa0e8;
  }
  if (format != 0x1901) {
    if ((char)transferMode8 == '\0') {
      pfVar13 = afStack_148;
      iVar9 = procHeight;
      pfVar14 = srcRowBytes;
      FUN_000a6140(iVar21,(*(uint *)(ctx + 0x1cf8) ^ 1) & 1 | (uint)(format == 0x1902) << 0xc,
                   pfVar13);
      FUN_0004b480(iVar21,*(uint *)(ctx + 0x1ae4) >> 6 & 0xffff);
      *(uint *)(ctx + 0x216c) = *(uint *)(ctx + 0x216c) & 0xfffff800 | 0x80;
    }
    else {
      pfVar14 = afStack_148;
      pfVar13 = (float *)0x0;
      iVar9 = 0;
      FUN_00086ba0(iVar21,1,0,0,pfVar14);
    }
    iVar12 = iVar20 * 8 + 0x1b;
  }
  else {
    pfVar14 = afStack_148;
    pfVar13 = (float *)0x0;
    iVar9 = 1;
    FUN_00086ba0(iVar21,0,0,1,pfVar14);
    iVar12 = iVar20 * 0x10 + 0x19;
  }
  if (*(char *)(ctx + 0x2a42) == '\0') {
    iVar12 = iVar12 + 2;
  }
  puVar10 = (undefined4 *)(**(code **)(ctx + 0x2998))(iVar21,iVar12);
  *(undefined4 **)(ctx + 0x298c) = puVar10;
  puVar11 = puVar10;
  if (*(char *)(ctx + 0x2a42) == '\0') {
    puVar11 = puVar10 + 2;
    *puVar10 = 0x5c8;
    puVar10[1] = 0x10000000;
    *(undefined1 *)(ctx + 0x2a42) = 1;
  }
  *puVar11 = ((unsigned char *)0x000010c0U);
  puVar11[1] = *(undefined4 *)(ctx + 0x216c);
  puVar11 = (undefined4 *)FUN_00083c90(iVar21,puVar11 + 2);
  dVar6 = DOUBLE_001aa1e0;
  fVar5 = FLOAT_001aa10c;
  pfStack_a4 = (float *)(param_8 ^ 0x80000000);
  local_b8 = 0x43300000;
  pfVar15 = (float *)(puVar11 + 2);
  uVar1 = (uint)(((double)CONCAT44(0x43300000,uVar19) - DOUBLE_001aa250) * DOUBLE_001aa240);
  local_b0 = (longlong)(int)uVar1;
  *puVar11 = ((unsigned char *)0x00001087U);
  puVar11[1] = uVar1 << 0x10 | uVar1 & 0xffff;
  local_158 = 0x3f800000;
  local_a8 = 0x43300000;
  local_160 = fVar5 / *(float *)(ctx + 0x2a58) +
              (float)((double)CONCAT44(0x43300000,pfStack_a4) - dVar6);
  if (format != 0x1901) {
    pfVar16 = (float *)0xc0003500;
    pfVar15 = (float *)(puVar11 + 4);
    puVar11[2] = iVar20 * 0x80000 | 0xc0003500;
    puVar11[3] = iVar20 * 0x10000 | 0x31;
    if (procHeight != 0) {
      i2dLo1 = param_7 ^ 0x80000000;
      i2dHi1 = 0x43300000;
      iVar9 = 0;
      pfVar13 = &local_168;
      fVar5 = (float)((double)CONCAT44(0x43300000,i2dLo1) - dVar6) + fVar5;
      do {
        dVar6 = DOUBLE_001aa250;
        fVar18 = FLOAT_001aa0f0;
        local_164 = fVar5;
        if (procWidth != 0) {
          pfVar14 = (float *)0x43300000;
          pfVar17 = param_2;
          iVar20 = procWidth;
          do {
            if (format == 0x1902) {
              local_15c = *pfVar17;
              local_154 = *(float *)(pfStack0000001c + 0x30);
              local_150 = *(float *)(pfStack0000001c + 0x34);
              local_14c = *(float *)(pfStack0000001c + 0x38);
              local_168 = *(float *)(pfStack0000001c + 0x3c);
            }
            else {
              local_15c = *(float *)(pfStack0000001c + 8);
              fVar8 = *pfVar17;
              local_80 = 0x43300000;
              local_78 = 0x43300000;
              local_70 = 0x43300000;
              local_68 = 0x43300000;
              uStack_64 = (uint)(int)fVar8 & 0xff;
              uStack_7c = (uint)(int)fVar8 >> 0x18;
              pfVar16 = (float *)((uint)(int)fVar8 >> 0x10 & 0xff);
              uStack_6c = (uint)(int)fVar8 >> 8 & 0xff;
              local_168 = (float)((double)CONCAT44(0x43300000,uStack_7c) - dVar6) / fVar18;
              local_14c = (float)((double)CONCAT44(0x43300000,uStack_64) - dVar6) / fVar18;
              local_154 = (float)((double)CONCAT44(0x43300000,pfVar16) - dVar6) / fVar18;
              local_150 = (float)((double)CONCAT44(0x43300000,uStack_6c) - dVar6) / fVar18;
              pfStack_74 = pfVar16;
            }
            pfVar17 = (float *)((int)pfVar17 + bytesPerPixel);
            *pfVar15 = local_164;
            pfVar15[1] = local_160;
            pfVar15[2] = local_15c;
            pfVar15[3] = 1.0;
            pfVar15[4] = local_154;
            pfVar15[5] = local_150;
            pfVar15[6] = local_14c;
            pfVar15[7] = local_168;
            pfVar15 = pfVar15 + 8;
            local_164 = fVar3 + local_164;
            iVar20 = iVar20 + -1;
          } while (iVar20 != 0);
        }
        iVar9 = iVar9 + 1;
        param_2 = (float *)((int)param_2 + (int)srcRowBytes);
        local_160 = fVar4 + local_160;
      } while (iVar9 != procHeight);
    }
  }
  else {
    fVar18 = GH_U2F((unsigned int)((*(uint *)(ctx + 0x1ce8) & 0xffff00ff | 0xff00)));
    pfVar16 = pfStack_a4;
    if (procHeight != 0) {
      i2dLo2 = param_7 ^ 0x80000000;
      i2dHi2 = 0x43300000;
      loopIndex = 0;
      fVar5 = fVar5 / *(float *)(ctx + 0x2a54) +
              (float)((double)CONCAT44(0x43300000,i2dLo2) - dVar6);
      do {
        dVar7 = DOUBLE_001aa250;
        dVar6 = DOUBLE_001aa240;
        local_164 = fVar5;
        if (procWidth != 0) {
          iVar9 = 1;
          pfVar14 = (float *)((unsigned char *)0x00001087U);
          pfVar13 = (float *)0x3f800000;
          pfVar16 = param_2;
          iVar12 = procWidth;
          do {
            local_15c = *(float *)(pfStack0000001c + 8);
            local_154 = *(float *)(pfStack0000001c + 0x30);
            local_150 = *(float *)(pfStack0000001c + 0x34);
            local_14c = *(float *)(pfStack0000001c + 0x38);
            local_168 = *(float *)(pfStack0000001c + 0x3c);
            bVar2 = *(byte *)pfVar16;
            *pfVar15 = GH_U2F((unsigned int)(((unsigned char *)0x000013c2U)));
            pfVar16 = (float *)((int)pfVar16 + bytesPerPixel);
            fVar18 = GH_U2F((unsigned int)(((uint)bVar2 | (uint)(int)fVar18 & 0xffffff00)));
            pfVar15[1] = fVar18;
            uStack_94 = *(undefined4 *)(ctx + 0x248);
            local_98 = 0x43300000;
            uVar1 = (uint)(((double)CONCAT44(0x43300000,uStack_94) - dVar7) * dVar6);
            local_90 = (longlong)(int)uVar1;
            pfVar15[5] = 9.19042e-41;
            pfVar15[6] = local_164;
            pfVar15[7] = local_160;
            pfVar15[8] = local_15c;
            pfVar15[2] = GH_U2F((unsigned int)(((unsigned char *)0x00001087U)));
            pfVar15[4] = -2.1282349;
            pfVar15[3] = GH_U2F((unsigned int)((uVar1 << 0x10 | uVar1 & 0xffff)));
            pfVar15[9] = 1.0;
            pfVar15[10] = local_154;
            pfVar15[0xb] = local_150;
            pfVar15[0xc] = local_14c;
            pfVar15[0xd] = local_168;
            pfVar15[0xe] = GH_U2F((unsigned int)(((unsigned char *)0x00001087U)));
            pfVar15[0xf] = *(float *)(ctx + 0x1f0c);
            pfVar15 = pfVar15 + 0x10;
            local_164 = fVar3 + local_164;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        loopIndex = loopIndex + 1;
        param_2 = (float *)((int)param_2 + (int)srcRowBytes);
        local_160 = fVar4 + local_160;
      } while (procHeight != loopIndex);
    }
  }
  *pfVar15 = GH_U2F((unsigned int)(((unsigned char *)0x00001087U)));
  pfVar15[1] = *(float *)(ctx + 0x1f0c);
  *(float **)(ctx + 0x298c) = pfVar15 + 2;
  uStack_b4 = uVar19;
  (**(code **)(ctx + 0x299c))(iVar21,pfVar15 + 2);
  FUN_0009d3b0(iVar21,r4AfterCall,pfVar13,iVar9,pfVar14,pfVar15,pfVar16);
  return FUN_000872e0(iVar21,afStack_148);
}

/* FUN_0002a260 @ 0x2a260 (356 bytes) */
int FUN_0002a260(ring, param_2)
  int ring;
  undefined4 param_2;
{
  uint uVar1;
  double dVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  uVar5 = *(undefined4 *)(ring + 8);
  FUN_000a6140(ring,(*(uint *)(ring + 0x1ab8) ^ 1) & 1,param_2);
  FUN_0004b480(ring,*(uint *)(ring + 0x18a4) >> 6 & 0xffff);
  uVar3 = (**(code **)(ring + 0x2758))(ring,0x1f);
  *(undefined4 *)(0x00002748 + ring + 4) = uVar3;
  puVar4 = (undefined4 *)FUN_00083c90(ring,uVar3);
  *puVar4 = ((unsigned char *)0x000010c0U);
  dVar2 = DOUBLE_001aa250;
  puVar4[1] = 0x80;
  uVar1 = (uint)(((double)CONCAT44(0x43300000,uVar5) - dVar2) * DOUBLE_001aa240);
  puVar4[2] = ((unsigned char *)0x00001087U);
  puVar4[4] = ((unsigned char *)0x000012f0U);
  puVar4[5] = 0;
  puVar4[3] = uVar1 << 0x10 | uVar1 & 0xffff;
  *(undefined4 *)(ring + 0x1b84) = 5;
  *(undefined4 *)(ring + 0x1c8c) = *(undefined4 *)(ring + 0x2814);
  *(undefined4 *)(ring + 0x1c94) = *(undefined4 *)(ring + 0x2818);
  puVar4[6] = 0x82c;
  uVar3 = *(undefined4 *)(ring + 0x1b84);
  puVar4[8] = 0x766;
  puVar4[7] = uVar3;
  uVar3 = *(undefined4 *)(ring + 0x1c8c);
  puVar4[10] = 0x768;
  puVar4[9] = uVar3;
  puVar4[0xb] = *(undefined4 *)(ring + 0x1c94);
  *(undefined4 **)(0x00002748 + ring + 4) = puVar4 + 0xc;
                    
                    
  (**(code **)(ring + 0x275c))(ring,puVar4 + 0xc);
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
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  double dVar15;
  undefined *hwContextTemplate;
  uint uVar17;
  undefined *unpackState;
  uint *lastHeader;
  uint uVar20;
  int *surfaceRefPtr;
  int iVar22;
  uint *packetRaw;
  undefined4 *packet;
  undefined4 uVar25;
  int iVar26;
  uint renderWidthClamped;
  uint uVar28;
  uint renderHeightClamped;
  undefined4 *surfaceObject;
  uint dstAddress;
  int hwFormat;
  int ring;
  int iVar34;
  char reservation;
  byte bVar35;
  int targetsLeft;
  double dVar37;
  double dVar38;
  double dVar39;
  double dVar40;
  double dVar41;
  uint local_108;
  undefined1 auStack_104 [4];
  int local_100 [2];
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
  longlong local_d0;
  longlong local_c8;
  longlong local_c0;
  longlong local_b8;
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  
  if (format == 0x1909) {
    hwFormat = 1;
    if (pixelType != ((unsigned char *)0x00001401)) {
      hwFormat = 0x13;
      if ((pixelType != ((unsigned char *)0x00001406)) && (hwFormat = 0x1f, pixelType != ((unsigned char *)0x0000140b))) {
        hwFormat = 0;
        if (pixelType != ((unsigned char *)0x00001403)) goto LAB_0002a440;
        hwFormat = 0x19;
      }
      goto LAB_0002a520;
    }
LAB_0002a440:
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
      if (pixelType == ((unsigned char *)0x00001401)) goto LAB_0002a440;
      hwFormat = 0x14;
      if ((pixelType != ((unsigned char *)0x00001406)) && (hwFormat = 0x20, pixelType != ((unsigned char *)0x0000140b))) {
        hwFormat = 0;
        if (pixelType != ((unsigned char *)0x00001403)) goto LAB_0002a440;
        hwFormat = 0x1a;
      }
    }
    else {
      hwFormat = 0x12;
      if (pixelType == ((unsigned char *)0x00001406)) {
LAB_0002a570:
        if (pixelType == (undefined *)0x8368) {
          hwFormat = 0x23;
          goto LAB_0002a520;
        }
      }
      else {
        if (pixelType == (undefined *)0x8035) {
          hwFormat = 9;
          goto LAB_0002a570;
        }
        if (pixelType != (undefined *)0x8367) {
          hwFormat = 0;
          if (pixelType == ((unsigned char *)0x00001401)) {
            hwFormat = 9;
            goto LAB_0002a520;
          }
          goto LAB_0002a570;
        }
        hwFormat = 10;
      }
      if (pixelType != ((unsigned char *)0x00001403)) goto LAB_0002a440;
      hwFormat = 0x18;
    }
  }
  else if (format == 0x80e1) {
    hwFormat = 7;
    if (pixelType == (undefined *)0x8366) {
LAB_0002a4e0:
      if (pixelType == (undefined *)0x8035) {
        hwFormat = 8;
        goto LAB_0002a4f4;
      }
LAB_0002a4a8:
      if (pixelType != (undefined *)0x8368) goto LAB_0002a4d4;
      hwFormat = 0x24;
LAB_0002a504:
      if (pixelType != ((unsigned char *)0x00001403)) goto LAB_0002a440;
      hwFormat = 0x17;
    }
    else {
      if (pixelType == (undefined *)0x8365) {
        hwFormat = 6;
        goto LAB_0002a4a8;
      }
      hwFormat = 0;
      if (pixelType != (undefined *)0x8367) goto LAB_0002a4e0;
      hwFormat = 0xb;
LAB_0002a4d4:
      if (pixelType == ((unsigned char *)0x00001406)) {
        hwFormat = 0x11;
      }
      else {
LAB_0002a4f4:
        if (pixelType != ((unsigned char *)0x0000140b)) goto LAB_0002a504;
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
    if (pixelType == ((unsigned char *)0x00001401)) goto LAB_0002a440;
    if (pixelType == ((unsigned char *)0x00001406)) {
      hwFormat = 0x16;
    }
    else {
      hwFormat = 0x22;
      if (pixelType != ((unsigned char *)0x0000140b)) {
        hwFormat = 0;
        if (pixelType != ((unsigned char *)0x00001403)) goto LAB_0002a440;
        hwFormat = 0x1c;
      }
    }
  }
LAB_0002a520:
  _pthread_mutex_lock(*(undefined4 *)(ctx + GLD_mutex));
  if (rawTransfer == 0) {
    unpackState = ((unsigned char *)0x00002e6c) + *(int *)(ctx + GLD_engineState);
  }
  else {
    unpackState = (undefined *)0x0;
  }
  gld_computePixelStoreLayout(ctx,format,pixelType,width,height,&local_108,auStack_104,local_100,unpackState);
  surfaceBase = *(int *)*surfaceInfo;
  dstAddress = pixels + local_100[0];
  if (((((int)local_108 < 0x1001) && ((int)height < 0x1001)) &&
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
    fVar8 = rasterX + FLOAT_001aa0d4 + FLOAT_001aa0d4;
    fVar2 = renderHeightF - (rasterY + FLOAT_001aa0d4);
    fVar13 = renderHeightF - ((float)((double)CONCAT44(0x43300000,heightI2dLo) - DOUBLE_001aa1e0) + rasterY);
    fVar11 = (float)((double)CONCAT44(0x43300000,widthI2dLo) - DOUBLE_001aa1e0) + rasterX +
             FLOAT_001aa0d4;
    fVar10 = FLOAT_001aa0d4;
    fVar12 = FLOAT_001aa0d4;
    if (FLOAT_001aa0d4 < fVar8) {
      fVar10 = fVar8;
      fVar12 = fVar8 + FLOAT_001aa0d4;
    }
    negRenderHeightI2dLo = negRenderHeightI2dLo ^ 0x80000000;
    fVar8 = fVar11 - renderWidthF;
    fVar14 = fVar2 - renderHeightF;
    negRenderHeightI2dHi = 0x43300000;
    fVar9 = renderWidthF;
    if (fVar8 < 0.0) {
      fVar9 = fVar11;
    }
    fVar11 = renderHeightF;
    if (fVar14 < 0.0) {
      fVar11 = fVar2;
    }
    fVar2 = fVar13;
    if (fVar13 < 0.0) {
      fVar2 = FLOAT_001aa0d4;
    }
    if (-fVar8 < 0.0) {
      fVar9 = renderWidthF;
    }
    if (-fVar14 < 0.0) {
      fVar11 = renderHeightF;
    }
    fVar3 = FLOAT_001aa0d4;
    if (-fVar13 < 0.0) {
      fVar3 = fVar2;
    }
    fVar8 = -rasterX + fVar12 + FLOAT_001aa0d4;
    fVar12 = -rasterX + fVar9 + FLOAT_001aa0d4 + FLOAT_001aa0d4;
    fVar4 = (float)((double)CONCAT44(0x43300000,negRenderHeightI2dLo) - DOUBLE_001aa1e0);
    fVar5 = -rasterY + (FLOAT_001aa0d4 - (fVar11 + fVar4));
    fVar4 = -rasterY + (FLOAT_001aa0d4 - (fVar3 + fVar4));
    if ((fVar10 < fVar9) && (fVar3 < fVar11)) {
      if (((((*(int *)surfaceInfo[1] != 0) && (prepareResult = gld_prepareBufferBacking(ctx,surfaceInfo,1), prepareResult == 0))
           || ((formatTable = PTR_DAT_001e88c8, (int *)surfaceInfo[2] == (int *)0x0 ||
               (prepareResult = *(int *)surfaceInfo[2], prepareResult == 0)))) ||
          ((*(char *)(prepareResult + 0x16) != '\x06' &&
           ((format != 0x1908 || ((pixelType != ((unsigned char *)0x00001406) && (pixelType != (undefined *)0x8366)))))
           ))) || (((dstAddress | local_108) & 0x1f) != 0)) goto LAB_0002a9a0;
      ring = ctx + GLD_commandStream;
      unitIndex = 0xf;
      uVar25 = (**(code **)(ctx + GLD_streamAllocate))(ring,0x343);
      *(undefined4 *)(ctx + GLD_streamCurrent) = uVar25;
      unitSlotPtr = ctx;
      do {
        if (*(int *)(unitSlotPtr + 0x1c8) != 0) {
          uVar25 = ((int (*)())gld_emitUnitObjectPacket)(ctx,0,unitIndex,uVar25);
        }
        unitIndex = unitIndex + -1;
        bVar35 = (unitIndex == 0) << 1;
        unitSlotPtr = unitSlotPtr + -4;
      } while (unitIndex != 0);
      packetRaw = (uint *)((int (*)())gld_emitUnitObjectPacket)(ctx,0,0,uVar25);
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
          bVar35 = 2;
        }
        hwContextTemplate = PTR_DAT_001e88d0;
      } while (!(bool)(bVar35 >> 1 & 1));
      packet[2] = *surfaceObject;
      packet[3] = dstAddress - *(int *)*surfaceInfo;
      _memcpy(packet + 4,hwContextTemplate,0x2f4);
      fVar6 = fVar12 - fVar8;
      dVar40 = (double)fVar6;
      fVar2 = fVar4 - fVar5;
      dVar41 = (double)fVar2;
      dVar37 = (double)FLOAT_001aa0e8;
      packet[0x22] = 0;
      dVar39 = DOUBLE_001aa1e8;
      dVar38 = (double)(float)(dVar40 - dVar37);
      bVar1 = DOUBLE_001aa1e8 <= dVar38;
      packet[0xa4] = *(uint *)(formatTable + hwFormat * 0x24 + 0x18) >> 0x1e | packet[0xa4] & 0xfffffffc
      ;
      dVar15 = DOUBLE_001aa1e8;
      if (bVar1) {
        iVar22 = (int)(dVar38 - dVar39);
        local_c8 = (longlong)iVar22;
        uVar20 = iVar22 + 0x80000000;
      }
      else {
        uVar20 = (uint)(int)(dVar40 - dVar37);
        local_d0 = (longlong)(int)uVar20;
      }
      dVar39 = (double)(float)(dVar41 - (double)FLOAT_001aa0e8);
      if (DOUBLE_001aa1e8 <= dVar39) {
        iVar22 = (int)(dVar39 - DOUBLE_001aa1e8);
        local_b8 = (longlong)iVar22;
        uVar28 = iVar22 + 0x80000000;
      }
      else {
        uVar28 = (uint)(int)(dVar41 - (double)FLOAT_001aa0e8);
        local_c0 = (longlong)(int)uVar28;
      }
      packet[0xaa] = uVar20 & 0x7ff | (uVar28 & 0x7ff) << 0xb | 0x80000000;
      uVar20 = *(uint *)(formatTable + hwFormat * 0x24 + 0x1c);
      uVar28 = *(uint *)(formatTable + hwFormat * 0x24 + 0x20);
      packet[0xac] =
           uVar20 >> 7 & 0x1f | uVar28 >> 3 & 0x400000 | (uVar20 & 0x70) << 5 |
           (uVar20 & 0xe) << 0xb | uVar28 >> 0xe & 0x38000 | uVar28 >> 8 & 0x1c0000;
      formatTableB = PTR_DAT_001e88c8;
      if (dVar15 <= dVar40) {
        iVar22 = (int)(dVar40 - dVar15);
        local_a8 = (longlong)iVar22;
        iVar22 = iVar22 + -0x80000000;
      }
      else {
        iVar22 = (int)fVar6;
        local_b0 = (longlong)iVar22;
      }
      if (DOUBLE_001aa1e8 <= dVar41) {
        local_98 = (longlong)(int)(dVar41 - DOUBLE_001aa1e8);
        iVar34 = (int)(dVar41 - DOUBLE_001aa1e8) + -0x80000000;
      }
      else {
        iVar34 = (int)fVar2;
        local_a0 = (longlong)iVar34;
      }
      uVar17 = packet[0x8e];
      packet[0xae] =
           ((int)local_108 >> (*(uint *)(formatTable + hwFormat * 0x24 + 0x14) & 7)) - 1U & 0x3fff |
           (iVar22 + -1) * 0x10 & 0xffff8000U | (iVar34 + -1) * 0x20 & 0xffff0000U;
      packet[0xa4] = (dstAddress - surfaceBase) * 0x20 | packet[0xa4] & 0x1f;
      formatIndex = ((unsigned char *)GLD_colorFormatIndex)[ctx];
      dstAddress = (*(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x18) & 0x18) << 5;
      packet[0x8e] = dstAddress | uVar17 & 0xfffffcff;
      uVar20 = (*(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x18) & 6) << 9;
      packet[0x8e] = uVar20 | dstAddress | uVar17 & 0xfffff0ff;
      uVar28 = *(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x1c) >> 0x12 & 0x3000;
      packet[0x8e] = uVar28 | uVar20 | dstAddress | uVar17 & 0xffffc0ff;
      uVar7 = *(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x1c) >> 0xe & 0xc000;
      packet[0x8e] = uVar7 | uVar28 | uVar20 | dstAddress | uVar17 & 0xffff00ff;
      packet[0x8e] =
           *(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x18) >> 5 & 0x1f |
           uVar7 | uVar28 | uVar20 | dstAddress | uVar17 & 0xffff00e0;
      if ((*(uint *)(formatTableB + (uint)formatIndex * 0x24 + 0x14) & 0xfc000000) == 0) {
        packet[0x5a] = packet[0x5a] & 0xfffe3fff | 0x18000;
      }
      fVar14 = FLOAT_001aa12c;
      fVar13 = FLOAT_001aa10c;
      packetEnd = packet + 0xcd;
      fVar6 = (float)((double)FLOAT_001aa0e8 / dVar41);
      fVar2 = (float)((double)FLOAT_001aa0e8 / dVar40);
      packet[0xb7] = renderWidthClamped - 1 & 0x1fff | (renderHeightClamped - 1) * 0x2000 & 0x3ffe000;
      packet[0xc1] = 0x31080;
      packet[0xc6] = ((unsigned char *)0x00001087U);
      packet[0xc5] = fVar4 * fVar6;
      hwFormat = (int)((fVar9 - fVar10) * fVar14);
      local_90 = (longlong)hwFormat;
      packet[0xc4] = fVar12 * fVar2;
      packet[0xc2] = fVar8 * fVar2;
      packet[0xc3] = fVar5 * fVar6;
      dstAddress = (uint)(int)((fVar11 - fVar3) * fVar14);
      local_88 = (longlong)(int)dstAddress;
      packet[0xc9] = 0x10031;
      packet[200] = 0xc0033500;
      packet[0xca] = (fVar10 + fVar9) * fVar13;
      packet[0xcb] = (fVar3 + fVar11) * fVar13;
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
      uVar25 = *(undefined4 *)(0x000026c8 + ctx + GLD_connect);
      packet[0xf8] = 0x854;
      packet[0xf7] = uVar25;
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
      iVar26 = 0;
      uVar25 = *(undefined4 *)(ctx + 0x1d6c);
      packet[0x108] = ((unsigned char *)0x00001096U);
      packet[0x107] = uVar25;
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
      FUN_0004c100(packet + 0xcf,ring);
      packet = packet + 0x18c;
      hwFormat = ctx;
      do {
        unitObject = *(int *)(hwFormat + 0x18c);
        if (unitObject != 0) {
          targetsLeft = 5;
          targetSlot = (int *)(iVar26 + *(int *)(ctx + GLD_engineObjects));
          do {
            if (unitObject == *targetSlot) {
              if (*(int *)(unitObject + 0x34) != 0) goto LAB_0002b2fc;
              break;
            }
            targetSlot = targetSlot + 1;
            targetsLeft = targetsLeft + -1;
          } while (targetsLeft != 0);
          unitObject = 0;
        }
LAB_0002b2fc:
        if ((unitOffset == 0) || (unitObject != 0)) {
          packet = (undefined4 *)((int (*)())gld_emitUnitObjectPacket)(ctx,unitObject,unitOffset,packet);
        }
        lastUnit = unitOffset != 0xf;
        iVar26 = iVar26 + 0x14;
        hwFormat = hwFormat + 4;
        unitOffset = unitOffset + 1;
      } while (lastUnit);
      *(undefined4 **)(ctx + GLD_streamCurrent) = packet;
      (**(code **)(ctx + GLD_streamSetCurrent))(ring,packet);
    }
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    uVar25 = 1;
  }
  else {
LAB_0002a9a0:
    _pthread_mutex_unlock(*(undefined4 *)(ctx + GLD_mutex));
    uVar25 = 0;
  }
  return uVar25;
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

/* FUN_0002b740 @ 0x2b740 (172 bytes) */
void FUN_0002b740(int ctx,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  int iVar1;
  int *r4AfterCall;
  int iVar2;
  undefined4 *puVar3;
  int queryPool;
  undefined4 in_LR;
  
  queryPool = *(int *)(ctx + 0x224);
  iVar2 = queryPool + 0x210;
  iVar1 = iVar2 + *param_2 * 0x20;
  *(undefined4 *)(iVar2 + *param_2 * 0x20) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0xc) = 0xffffffff;
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
  *(undefined4 *)(iVar1 + 8) = 0xffffffff;
  *(int *)(queryPool + 8) = *param_2;
  puVar3 = *(undefined4 **)(ctx + 0x1dc);
  if (*(undefined4 **)(ctx + 0x1e0) <= puVar3 + 2) {
    staleFprArg1 = (double)gld_submitRing(ctx,0x1000000);
    puVar3 = *(undefined4 **)(ctx + 0x1dc);
    param_2 = r4AfterCall;
  }
  *(undefined4 **)(ctx + 0x1dc) = puVar3 + 2;
  puVar3[1] = 0;
  *puVar3 = ((unsigned char *)0x000013d6U);
  ((unsigned char *)0x00002b7e)[ctx] = 1;
  ((void (*)())gldValidateState)(ctx + 0x240,param_2,param_3,param_4,param_5,param_6,puVar3,staleFprArg1,staleFprArg2,
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
  uint uVar2;
  int *piVar3;
  uint *lastHeader;
  undefined4 uVar5;
  uint uVar6;
  uint counterCount;
  int *queryPool;
  undefined4 *packetBody;
  undefined4 *packetCursor;
  uint uVar11;
  undefined4 queryValue;
  undefined4 *queryRecordWord;
  int slotIndex;
  bool bVar15;
  char reservation;
  byte crField0;
  int iVar16;
  
  queryPool = *(int **)(ctx + 0x224);
  queryValue = *(undefined4 *)(ctx + 0x1cf8);
  counterCount = *(uint *)(ctx + 0x2610);
  queryRecordWord = (undefined4 *)**(undefined4 **)(ctx + 0x234);
  uVar6 = *(uint *)(ctx + 0x154) & 0x30000;
  if ((queryPool != (int *)0x0) && (((unsigned char *)0x00002b7e)[ctx] != '\0')) {
    zpassOnly = *(int *)(ctx + 0x261c) != 2;
    if ((counterCount == 1) && (!zpassOnly)) {
      counterCount = 2;
    }
    if (*queryPool == 0) {
      iVar16 = 0x10;
      piVar3 = queryPool;
      do {
        piVar3[4] = 0;
        piVar3[8] = 0;
        piVar3[6] = 0;
        piVar3[7] = 0;
        piVar3 = piVar3 + 8;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      slotIndex = 0;
      iVar16 = 0;
      queryPool[1] = 1;
    }
    else {
      slotIndex = queryPool[1];
      queryPool[1] = slotIndex + 1U & 0xf;
      uVar11 = queryPool[queryPool[2] * 8 + 0x85];
      if (uVar6 == 0x10000) {
        uVar2 = queryPool[slotIndex * 8 + 4] << 0x10 | (uint)queryPool[slotIndex * 8 + 4] >> 0x10;
      }
      else {
        uVar2 = queryPool[slotIndex * 8 + 4];
      }
      iVar16 = slotIndex * 0x20;
      if ((uVar2 != 0) && (bVar15 = CARRY4(uVar11,uVar2), uVar11 = uVar11 + uVar2, bVar15)) {
        uVar11 = 0xffffffff;
      }
      if (1 < counterCount) {
        if (uVar6 == 0x10000) {
          uVar2 = queryPool[slotIndex * 8 + 8] << 0x10 | (uint)queryPool[slotIndex * 8 + 8] >> 0x10;
        }
        else {
          uVar2 = queryPool[slotIndex * 8 + 8];
        }
        if ((uVar2 != 0) && (bVar15 = CARRY4(uVar11,uVar2), uVar11 = uVar11 + uVar2, bVar15)) {
          uVar11 = 0xffffffff;
        }
      }
      if (2 < counterCount) {
        if (uVar6 == 0x10000) {
          uVar2 = queryPool[slotIndex * 8 + 6] << 0x10 | (uint)queryPool[slotIndex * 8 + 6] >> 0x10;
        }
        else {
          uVar2 = queryPool[slotIndex * 8 + 6];
        }
        if ((uVar2 != 0) && (bVar15 = CARRY4(uVar11,uVar2), uVar11 = uVar11 + uVar2, bVar15)) {
          uVar11 = 0xffffffff;
        }
      }
      uVar2 = uVar11;
      if (3 < counterCount) {
        if (uVar6 == 0x10000) {
          uVar6 = queryPool[slotIndex * 8 + 7] << 0x10 | (uint)queryPool[slotIndex * 8 + 7] >> 0x10;
        }
        else {
          uVar6 = queryPool[slotIndex * 8 + 7];
        }
        if (uVar6 != 0) {
          uVar2 = 0xffffffff;
          if (!CARRY4(uVar6,uVar11)) {
            uVar2 = uVar6 + uVar11;
          }
        }
      }
      queryPool[queryPool[2] * 8 + 0x85] = uVar2;
    }
    piVar3 = queryRecordWord + 4;
    *(undefined4 *)((int)queryPool + iVar16 + 0x1c) = 0;
    *(undefined4 *)((int)queryPool + iVar16 + 0x10) = 0;
    *(undefined4 *)((int)queryPool + iVar16 + 0x20) = 0;
    *(undefined4 *)((int)queryPool + iVar16 + 0x18) = 0;
    do {
      if (reservation != '\0') {
        iVar16 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
        *piVar3 = iVar16;
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
    uVar5 = *queryRecordWord;
    packetBody[2] = 1;
    packetBody[3] = slotIndex;
    packetBody[1] = uVar5;
    if (zpassOnly) {
      if (counterCount != 0) {
        uVar6 = 0;
        do {
          *packetCursor = ((unsigned char *)0x000010b2U);
          packetCursor[2] = ((unsigned char *)0x000013d7U);
          packetCursor[3] = 0;
          packetCursor[1] = 1 << (uVar6 & 0x3f);
          uVar6 = uVar6 + 1;
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
      uVar6 = 0;
      iVar16 = 2;
      queryRecordWord = packetBody + 6;
      do {
        packetBody = queryRecordWord;
        *packetBody = ((unsigned char *)0x000012faU);
        packetBody[2] = ((unsigned char *)0x000013d7U);
        packetBody[3] = 0;
        packetBody[1] = 1 << (uVar6 & 0x3f);
        uVar6 = uVar6 + 1;
        iVar16 = iVar16 + -1;
        queryRecordWord = packetBody + 4;
      } while (iVar16 != 0);
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

/* FUN_0002bbc4 @ 0x2bbc4 (564 bytes) */
void FUN_0002bbc4(int ctx,undefined4 *param_2,undefined4 param_3,undefined4 param_4,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *r4AfterCall;
  undefined4 *puVar7;
  undefined *puVar8;
  uint *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  char reservation;
  byte crField0;
  undefined4 in_LR;
  
  iVar16 = *(int *)(ctx + 0x2610);
  iVar15 = *(int *)(ctx + 0x261c);
  uVar13 = *(undefined4 *)(ctx + 0x1cf8);
  puVar14 = (undefined4 *)**(undefined4 **)(ctx + 0x234);
  if (iVar16 == 1) {
    if (iVar15 == 2) {
      iVar16 = 2;
      iVar10 = 8;
    }
    else {
      iVar10 = 4;
    }
  }
  else {
    iVar10 = iVar16 << 2;
  }
  piVar3 = puVar14 + 4;
  do {
    if (reservation != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
      *piVar3 = iVar1;
      crField0 = 2;
    }
  } while (!(bool)(crField0 >> 1 & 1));
  puVar9 = *(uint **)(ctx + 0x1dc);
  puVar7 = param_2;
  if (*(uint **)(ctx + 0x1e0) <= puVar9 + iVar10 + 0x15) {
    staleFprArg1 = (double)gld_submitRing(ctx,0x1000000);
    puVar9 = *(uint **)(ctx + 0x1dc);
    puVar7 = r4AfterCall;
  }
  puVar8 = (undefined *)0x0;
  puVar2 = (undefined4 *)((uint)(puVar9 + 0xb) & 0xffffffe0);
  puVar12 = puVar2 + 4;
  *puVar9 = (((int)puVar2 - (int)puVar9) + -8) * 0x4000 | 0xc0001000;
  puVar2[-1] = (int)puVar2 - (int)puVar9;
  puVar4 = *(uint **)(ctx + 0x1d8);
  puVar11 = (undefined4 *)*puVar4;
  *puVar4 = (int)puVar2 - (int)puVar4 >> 2 | (uint)puVar11;
  *(undefined4 **)(ctx + 0x1d8) = puVar2;
  *puVar2 = 0x3b000000;
  uVar5 = *puVar14;
  puVar2[2] = 0;
  puVar2[1] = uVar5;
  puVar2[3] = *param_2;
  if (iVar15 == 2) {
    puVar2[5] = 0;
    puVar2[4] = ((unsigned char *)0x000013c5U);
    uVar6 = 0;
    puVar8 = ((unsigned char *)0x000012faU);
    puVar9 = (uint *)((int)((unsigned char *)0x0) + 1);
    iVar15 = 2;
    puVar11 = puVar2 + 6;
    do {
      puVar14 = puVar11;
      *puVar14 = ((unsigned char *)0x000012faU);
      puVar14[2] = ((unsigned char *)0x000013d7U);
      puVar14[3] = 0;
      puVar14[1] = 1 << (uVar6 & 0x3f);
      uVar6 = uVar6 + 1;
      puVar11 = puVar14 + 4;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    *puVar11 = ((unsigned char *)0x000012faU);
    puVar14[7] = uVar13;
    puVar12 = puVar14 + 8;
    puVar14[5] = 3;
    puVar14[6] = ((unsigned char *)0x000013c5U);
  }
  else {
    if (iVar16 != 0) {
      uVar6 = 0;
      puVar8 = ((unsigned char *)0x000010b2U);
      puVar9 = (uint *)((int)((unsigned char *)0x0) + 1);
      puVar11 = (undefined4 *)0x0;
      do {
        *puVar12 = ((unsigned char *)0x000010b2U);
        puVar12[2] = ((unsigned char *)0x000013d7U);
        puVar12[3] = 0;
        puVar12[1] = 1 << (uVar6 & 0x3f);
        uVar6 = uVar6 + 1;
        puVar12 = puVar12 + 4;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
    }
    *puVar12 = ((unsigned char *)0x000010b2U);
    puVar12[1] = 0xf;
    puVar12 = puVar12 + 2;
  }
  *(undefined4 **)(ctx + 0x1dc) = puVar12;
  ((unsigned char *)0x00002b7e)[ctx] = 0;
  ((void (*)())gldValidateState)(ctx + 0x240,puVar7,param_3,param_4,puVar8,puVar9,puVar11,staleFprArg1,staleFprArg2,
               staleFprArg3,staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,
               (double)CONCAT44(in_LR,(*(unsigned int *)((unsigned char *)&(staleFprArg9) + 4))));
  return;
}

/* FUN_0002be00 @ 0x2be00 (88 bytes) */
int FUN_0002be00(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = *(int *)(iVar2 + 0x1dc);
  if (*(uint *)(iVar2 + 0x1e0) <= (uint)(param_2 * 4 + iVar1)) {
    gld_submitRing(iVar2,0x1000000);
    iVar1 = *(int *)(iVar2 + 0x1dc);
  }
  return iVar1;
}

/* FUN_0002be60 @ 0x2be60 (12 bytes) */
int FUN_0002be60(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc) = param_2;
  return;
}

/* FUN_0002be70 @ 0x2be70 (8 bytes) */
int FUN_0002be70(param_1)
  int param_1;
{
  return *(undefined4 *)(0x00002748 + param_1 + 4);
}

/* noop_2be80 @ 0x2be80 (4 bytes) */
int noop_2be80()
{
  return;
}

/* FUN_0002be90 @ 0x2be90 (12 bytes) */
int FUN_0002be90(ctx, param_2, param_3, param_4, param_5, param_6, param_7)
  int ctx;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  return FUN_000a3be0(ctx + 0x240,param_3,param_3,param_4,param_5,param_6,param_7);
}

/* gldTrimVertexCountToPrimitive @ 0x2bea0 (116 bytes) */
int gldTrimVertexCountToPrimitive(ctx, mode, count)
  undefined4 ctx;
  uint mode;
  uint count;
{
  int iVar1;
  
  iVar1 = (mode >> 3 & 1) + (mode >> 2 & 1) + (mode >> 1 & 1) + (mode & 1);
  if (iVar1 == 2) {
    return count;
  }
  if (iVar1 == 0) {
    return count;
  }
  if (mode == 2) {
    return count;
  }
  if (iVar1 == 3) {
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
  uint uVar1;
  
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
    uVar1 = ((int)count / 3) * 3;
    if (2 < (int)uVar1) {
      return uVar1;
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
void gld_revalidateStreamProgram(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,uint param_7,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9)
{
  uint uVar1;
  int iVar2;
  double staleStackArg_ffffffb8;
  
  uVar1 = *(uint *)(param_1 + 0x1874);
  *(uint *)(param_1 + 0x1874) = uVar1 & 0x3fffffff;
  if ((param_2 == 0) && (param_7 = *(uint *)(param_1 + 0x1928) & 2, param_7 != 0)) {
    iVar2 = 1;
    *(uint *)(param_1 + 0x1874) = uVar1 & 0x3fffffff | 0x80000000;
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 != *(int *)(param_1 + 0x192c)) {
    ((void (*)())ffvpValidateProgramForced)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,staleFprArg1,staleFprArg2,staleFprArg3,
                 staleFprArg4,staleFprArg5,staleFprArg6,staleFprArg7,staleFprArg8,staleStackArg_ffffffb8);
    FUN_00090960(param_1);
    *(int *)(param_1 + 0x192c) = iVar2;
  }
  *(uint *)(param_1 + 0x1928) = *(uint *)(param_1 + 0x1928) & 0xfffffffe;
  return;
}

/* gld_emitVapStreamControl @ 0x2c0c0 (180 bytes) */
int gld_emitVapStreamControl(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  
  puVar3 = param_2 + 1;
  uVar7 = *(int *)(param_1 + 0x267c) + 1U >> 1;
  uVar1 = (uVar7 - 1) * 0x10000;
  *param_2 = uVar1 | 0x854;
  if (uVar7 != 0) {
    iVar4 = 0;
    uVar6 = uVar7;
    do {
      iVar2 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      *puVar3 = *(uint *)(iVar2 + *(int *)(param_1 + 0x2680));
      puVar3 = puVar3 + 1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  puVar5 = puVar3 + 1;
  *puVar3 = uVar1 | 0x878;
  if (uVar7 != 0) {
    iVar4 = 0;
    do {
      iVar2 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      *puVar5 = *(uint *)(iVar2 + *(int *)(param_1 + 0x2684));
      puVar5 = puVar5 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  *puVar5 = 0x82d;
  puVar5[1] = *(uint *)(0x000026c8 + param_1 + 4);
  return puVar5 + 2;
}

/* gld_emitStreamAddressRegisters @ 0x2c180 (164 bytes) */
int gld_emitStreamAddressRegisters(ctx, packetPtr)
  int ctx;
  uint *packetPtr;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  puVar5 = packetPtr + 1;
  iVar3 = (int)((*(uint *)(ctx + 0x26d0) & 0x1f) + 1) >> 1;
  *packetPtr = (iVar3 * 3 + -1) * 0x10000 | 0x831;
  if (iVar3 != 0) {
    iVar2 = 0;
    iVar4 = 0;
    if (iVar3 == 0) {
      iVar3 = 1;
    }
    do {
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *puVar5 = *(uint *)(iVar1 + *(int *)(ctx + 0x26d4));
      puVar5[1] = *(uint *)(*(int *)(ctx + 0x26d8) + iVar4);
      iVar1 = *(int *)(ctx + 0x26d8) + iVar4;
      iVar4 = iVar4 + 8;
      puVar5[2] = *(uint *)(iVar1 + 4);
      puVar5 = puVar5 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *puVar5 = 0x830;
  puVar5[1] = *(uint *)(ctx + 0x26d0);
  return puVar5 + 2;
}

/* FUN_0002c230 @ 0x2c230 (1144 bytes) */
int FUN_0002c230(param_1, dirtyBits)
  int param_1;
  uint *dirtyBits;
{
  undefined4 gld_bufferEnumToIndexResult;
  ushort *puVar1;
  bool bVar2;
  code *pcVar3;
  uint *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *scalarBlockPtr;
  undefined4 scalarCount;
  undefined4 structOutPtr;
  undefined4 structOutSize;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  uVar8 = dirtyBits[3];
  iVar10 = *(int *)(param_1 + 4);
  uVar7 = (uint)((uVar8 & 0x10000000) != *(uint *)(param_1 + 0x2780));
  if ((((*dirtyBits == 0) && (dirtyBits[1] == 0)) && (dirtyBits[2] == 0)) &&
     ((((uVar8 & 0xffefffff) == 0 && (dirtyBits[4] == 0)) && (uVar7 == 0)))) {
LAB_0002c610:
    uVar7 = *(uint *)(param_1 + 0x2488);
  }
  else {
    if ((((dirtyBits[2] & 0x3f000008) != 0) || ((uVar8 & 0x4c00003) != 0)) ||
       ((*(char *)(iVar10 + 0x2a43) != '\0' || (uVar7 != 0)))) {
      FUN_00090990(param_1,dirtyBits);
      FUN_00090840(param_1);
    }
    if (*(char *)(iVar10 + 0x20) == '\0') {
      FUN_000a7d10(param_1);
    }
    FUN_00065370(param_1);
    FUN_00090960(param_1);
    uVar8 = *dirtyBits;
    if (((uVar8 & 0x20000000) != 0) || (*(char *)(iVar10 + 0x2a43) != '\0')) {
      FUN_00022eb0(iVar10,0);
      uVar8 = *dirtyBits;
    }
    if ((((uVar8 & 0x180) != 0) || (*(char *)(iVar10 + 0x2a43) != '\0')) &&
       (*(int *)(iVar10 + 0x150) == 0)) {
      iVar9 = *(int *)(param_1 + 4);
      iVar11 = 0;
      iVar13 = *(int *)(iVar9 + 0x10);
      iVar12 = param_1;
      do {
        puVar1 = (ushort *)(((unsigned char *)0x00002dba) + iVar13);
        iVar13 = iVar13 + 2;
        gld_bufferEnumToIndexResult = gld_bufferEnumToIndex((uint)*puVar1,*(undefined4 *)(iVar9 + 0x154));
        bVar2 = iVar11 != 3;
        iVar11 = iVar11 + 1;
        *(undefined4 *)(iVar12 + 0x2460) = gld_bufferEnumToIndexResult;
        iVar12 = iVar12 + 4;
      } while (bVar2);
      puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x22d);
      iVar12 = *(int *)(param_1 + 0x2460);
      *(undefined4 **)(0x00002748 + param_1 + 4) = puVar6;
      if (((iVar12 == 1) && (uVar8 = *(uint *)(iVar9 + 0x154), (uVar8 & 0x800) == 0)) &&
         (((uVar8 & 0x20) != 0 && ((uVar8 & 0x400) != 0)))) {
        (**(code **)(param_1 + 0x275c))(param_1,puVar6);
        if (*(int *)(iVar9 + 0x1e4) + 0x28U < *(uint *)(iVar9 + 0x1dc)) {
          gld_submitRing(iVar9,0x1000000);
        }
        scalarBlockPtr = &local_48;
        scalarCount = 4;
        uVar7 = 0xffff3fc0;
        structOutPtr = 0;
        structOutSize = 0;
        uVar8 = *(uint *)(iVar9 + 0x3c) | 0x800;
        *(uint *)(iVar9 + 0x154) = uVar8;
        *(uint *)(iVar9 + 0x3c) = uVar8;
        local_48 = *(undefined4 *)(*(int *)(iVar9 + 0xf8) + 8);
        local_44 = *(uint *)(iVar9 + 0x3c) & 0xffff3fc0;
        local_40 = *(undefined4 *)(iVar9 + 0xfc);
        local_3c = *(undefined4 *)(iVar9 + 0x100);
        _io_connect_method_scalarI_structureI(*(undefined4 *)(iVar9 + 4),0,scalarBlockPtr,4,0,0);
        puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x22d);
        iVar12 = *(int *)(param_1 + 0x2460);
        *(undefined4 **)(0x00002748 + param_1 + 4) = puVar6;
      }
      iVar12 = FUN_0001a010(iVar9,iVar12,scalarBlockPtr,scalarCount,structOutPtr,structOutSize,uVar7);
      if (iVar12 == 0) {
        puVar4 = *(uint **)(iVar9 + 0x1d8);
        *puVar4 = (int)puVar6 - (int)puVar4 >> 2 | *puVar4;
        *(undefined4 **)(iVar9 + 0x1d8) = puVar6;
        *puVar6 = 0x29000000;
        puVar6[1] = *(undefined4 *)(param_1 + 0x2460);
        puVar6[2] = *(undefined4 *)(param_1 + 0x2464);
        puVar6[3] = *(undefined4 *)(param_1 + 0x2468);
        uVar5 = *(undefined4 *)(param_1 + 0x246c);
        puVar6[5] = 0x11;
        puVar6[4] = uVar5;
        puVar6[6] = *(undefined4 *)(param_1 + 0x1ae0);
        puVar6[7] = *(undefined4 *)(param_1 + 0x1ab0);
      }
      else {
        puVar4 = *(uint **)(iVar9 + 0x1d8);
        *puVar4 = (int)puVar6 - (int)puVar4 >> 2 | *puVar4;
        *(undefined4 **)(iVar9 + 0x1d8) = puVar6;
        *puVar6 = 0x29000000;
        uVar5 = *(undefined4 *)(param_1 + 0x2460);
        puVar6[4] = 0x11;
        puVar6[5] = 0x10;
        puVar6[2] = 0x11;
        puVar6[3] = 0x11;
        puVar6[1] = uVar5;
        puVar6[6] = *(undefined4 *)(param_1 + 0x1ae0);
        puVar6[7] = *(undefined4 *)(param_1 + 0x1ab0);
      }
      pcVar3 = *(code **)(param_1 + 0x275c);
      *(undefined4 **)(0x00002748 + param_1 + 4) = puVar6 + 0x39;
      /* issue #64 live-repro (crash #10, the long-running "iVar5+0x1dc=1" hunt): this indirect
       * dispatch through the per-instance table at 0x275c supplied only 1 of 2 real arguments -
       * a dropped-call-args bug matching the same class already fixed for arbEmitRecord2Src_op01's own
       * dispatch calls. The line right above sets up *(0x2748+param_1+4) - the exact "current
       * write pointer" value the real target expects as its 2nd argument - but never actually
       * passes it; a sibling call site to this SAME dispatch slot (FUN_00082c50, part_011.c:8826)
       * shows the correct, complete shape: `(*fn)(param_1, *(int*)(0x2748+param_1+4));`. Live-
       * verified via a hardware watchpoint installed from the moment CGLCreateContext returns
       * (tracking the target field through ~15 legitimate updates via FUN_0002be60): on real
       * hardware, this exact call resolves to FUN_0002be60(param_1, dirtyBits) - a simple setter,
       * `*(*(param_1+4)+0x1dc) = dirtyBits;` - and with no 2nd argument ever pushed by the caller,
       * dirtyBits read whatever was left in r4 by earlier, unrelated code: the literal integer 1.
       * That single wild write is what every downstream consumer (FUN_0002be00, gld_emitUnitObjectPacket)
       * was tripping over. Fixed by passing the value the call site had already prepared. */
      (*pcVar3)(param_1,*(undefined4 *)(0x00002748 + param_1 + 4));
    }
    if (*(short *)((int)dirtyBits + 6) != 0) {
      ((int (*)())FUN_0002ce40)(param_1,dirtyBits);
    }
    if (*(char *)(param_1 + 0x2435) == '\0') goto LAB_0002c610;
    *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
    *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
    *(undefined4 *)(param_1 + 0x2494) = 0;
    uVar7 = *(uint *)(param_1 + 0x2488) | 4;
    *(uint *)(param_1 + 0x2488) = uVar7;
  }
  if (((uVar7 & 4) == 0) && (*(char *)(param_1 + 0x247d) == '\0')) {
    if (*(char *)(param_1 + 0x2595) == '\0') {
      uVar7 = dirtyBits[3] & 0x100000;
    }
    else {
      uVar7 = *(uint *)(*(int *)(iVar10 + 0x14) + 0x120);
    }
    if ((uVar7 == 0) && ((*dirtyBits & 0x800000) == 0)) goto LAB_0002c67c;
  }
  ((int (*)())FUN_00027990)(param_1);
LAB_0002c67c:
  if ((((dirtyBits[3] & 0x100000) != 0) || ((*(uint *)(param_1 + 0x2488) & 4) != 0)) ||
     (*(char *)(param_1 + 0x247d) != '\0')) {
    gld_buildVertexStreamLayout(param_1);
  }
  return;
}

/* FUN_0002c6c0 @ 0x2c6c0 (184 bytes) */
int FUN_0002c6c0(ctx)
  int ctx;
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(ctx + 0x208);
  puVar1[7] = puVar1[7] | 1;
  *(code **)(ctx + 0x2998) = FUN_0002be70;
  *(code **)(ctx + 0x299c) = noop_2be80;
  *(undefined4 **)(ctx + 0x298c) = puVar1 + 8;
  gldEmitHardwareState(ctx + 0x240);
  *puVar1 = *(undefined4 *)(ctx + 0x1d20);
  puVar1[1] = *(undefined4 *)(ctx + 0x1cf0);
  puVar1[5] = *(int *)(ctx + 0x298c) - (int)(puVar1 + 8) >> 2;
  *(code **)(ctx + 0x299c) = FUN_0002be60;
  *(code **)(ctx + 0x2998) = FUN_0002be00;
  if ((uint)puVar1[4] < (uint)puVar1[5]) {
                    
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
  int *piVar1;
  undefined *puVar2;
  uint uVar3;
  int *piVar4;
  undefined1 window_mode_to_ati_formatResult;
  undefined4 uVar5;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
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
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  iVar10 = ctx + 0x240;
  _memset(iVar10,0,0x2950);
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
  FUN_00020b00(ctx);
  *(undefined4 *)(ctx + 0x2a64) = *(undefined4 *)(pixelFormat + 0x30);
  if (*(char *)(ctx + 0x2a6a) == '\0') {
    gld_postDisplayNotification(ctx);
  }
  *(undefined1 *)(ctx + 0x2a43) = 1;
  *(undefined1 *)(ctx + 0x2a5e) = 1;
  gld_updateSampleConfig(ctx);
  *(undefined4 *)(ctx + 0x261c) = 1;
  *(undefined4 *)(ctx + 0x2610) = 1;
  uVar5 = 0;
  *(undefined4 *)(ctx + 0x29d8) = 0xfff0;
  local_38 = DAT_001aa504;
  local_40 = DAT_001aa4fc;
  local_58 = 5;
  local_3c = DAT_001aa500;
  local_34 = DAT_001aa508;
  local_30 = DAT_001aa50c;
  _io_connect_method_scalarI_scalarO(*(undefined4 *)(ctx + 4),0x14,0,0,&local_40,&local_58);
  *(undefined4 *)(ctx + 0x2614) = local_3c;
  *(undefined4 *)(ctx + 0x2618) = local_38;
  *(undefined4 *)(ctx + 0x261c) = local_34;
  *(undefined4 *)(ctx + 0x2610) = local_40;
  iVar8 = *(int *)(ctx + 0x1e4);
  *(int *)(ctx + 0x1dc) = iVar8 + 0x20;
  *(int *)(ctx + 0x1d8) = iVar8 + 0x1c;
  *(int *)(ctx + 0x1e0) = iVar8 + 0x20 + *(int *)(iVar8 + 0x10) * 4 + -0x94;
  *(undefined4 *)(iVar8 + 0x1c) = 0;
  *(undefined4 *)(ctx + 0x1ec) = 0;
  *(undefined4 *)(ctx + 0x1f0) = 0;
  FUN_000a7050(ctx);
  FUN_000a0f90(iVar10);
  staleFprArg1 = (double)FUN_00052cc0(iVar10);
  *(undefined4 *)(((unsigned char *)0x00002b74) + ctx) = 0;
  *(undefined4 *)(ctx + 0x26a0) = 0;
  *(undefined4 *)(ctx + 0x26b0) = 0;
  *(undefined4 *)(((unsigned char *)0x00002b78) + ctx) = 0;
  iVar11 = 0x10;
  iVar8 = iVar10;
  do {
    *(undefined1 *)(iVar8 + 0x2784) = 0;
    iVar8 = iVar8 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  ((unsigned char *)0x00002b82)[ctx] = 0;
  puVar2 = PTR_DAT_001e8994;
  *(undefined4 *)(0x000026c8 + ctx) = 7;
  uVar7 = 0;
  *(undefined1 *)(ctx + 0x2a43) = 1;
  *(undefined1 *)(ctx + 0x26bd) = 1;
  iVar8 = 0x10;
  piVar1 = (int *)((uint)(puVar2 + 0xc) & 0xfffffff3);
  *(int **)PTR_DAT_001e88cc = piVar1;
  piVar4 = piVar1;
  do {
    uVar3 = uVar7 << 8 | uVar7;
    uVar7 = uVar7 + 1;
    uVar3 = uVar3 | uVar3 << 0x10;
    *piVar4 = uVar3 + 0x2030001;
    piVar4[3] = uVar3 + 0xe0f0c0d;
    piVar4[1] = uVar3 + 0x6070405;
    piVar4[2] = uVar3 + 0xa0b0809;
    piVar4 = piVar4 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  uVar3 = 0xffffffff;
  uVar9 = 0xffffffa0;
  iVar11 = 0x10;
  loopIndex = 0;
  piVar4 = piVar1;
  while( true ) {
    piVar4[0x40] = uVar3;
    uVar3 = 0xffffffff;
    if ((4 < loopIndex) && (uVar3 = 0, loopIndex < 8)) {
      uVar3 = 0xffffffff >> (uVar9 + 0x40 & 0x3f);
    }
    piVar4[0x41] = uVar3;
    uVar3 = 0xffffffff;
    if ((8 < loopIndex) && (uVar3 = 0, loopIndex < 0xc)) {
      uVar3 = 0xffffffff >> (uVar9 + 0x20 & 0x3f);
    }
    piVar4[0x42] = uVar3;
    uVar3 = 0xffffffff;
    if (0xc < loopIndex) {
      uVar3 = 0xffffffff >> (uVar9 & 0x3f);
    }
    piVar4[0x43] = uVar3;
    loopIndex = loopIndex + 1;
    piVar4 = piVar4 + 4;
    uVar9 = uVar9 + 8;
    iVar11 = iVar11 + -1;
    if (iVar11 == 0) break;
    uVar3 = 0xffffffff;
    if ((0 < loopIndex) && (uVar3 = 0, loopIndex < 4)) {
      uVar3 = 0xffffffff >> (loopIndex * 8 & 0x38U);
    }
  }
  ((unsigned char *)0x00002b88)[ctx] = 1;
  local_54 = DAT_001aa4e8;
  local_50 = DAT_001aa4ec;
  local_44 = DAT_001aa4f8;
  local_4c = DAT_001aa4f0;
  local_48 = DAT_001aa4f4;
  ((void (*)())FUN_000a9ac0)(iVar10,&local_54,uVar5,piVar1,uVar7,DAT_001aa4f8,DAT_001aa4e8,DAT_001aa4f4,staleFprArg1,
               staleFpr2,staleFpr3,staleFpr4,staleFpr5,staleFpr6,staleFpr7,staleFpr8,staleStackArg_ffffff78,staleStackArg_ffffff80,
               staleStackArg_ffffff88,staleStackArg_ffffff90,staleStackArg_ffffff98);
  ((int (*)())FUN_0002c6c0)(ctx);
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

/* FUN_0002cc10 @ 0x2cc10 (28 bytes) */
int FUN_0002cc10(ctx)
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
    if (((primitiveClassBits == 2) || (primitiveClassBits == 0)) || (primitiveMode == 2)) goto LAB_0002cce8;
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
LAB_0002cce8:
  if (((unsigned char *)0x00002b80)[ctx] != '\0') {
    staleFprArg1 = (double)FUN_000a3be0(ctx + GLD_commandStream,primitiveMode,modeForward,vertexCountForward,extraArg4,extraArg5,drawFlagsOrModeBit);
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
  int iVar1;
  int *piVar2;
  bool bVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  char reservation;
  
  if (unitObject == 0) {
    puVar5 = *(uint **)(ctx + 0x1d8);
    *puVar5 = (int)packetCursor - (int)puVar5 >> 2 | *puVar5;
    *(uint **)(ctx + 0x1d8) = packetCursor;
    *packetCursor = opcodeCount * 0x1000000 + 0x16000000;
    return packetCursor + 1;
  }
  piVar2 = (int *)((uint)(packetCursor + 0xb) & 0xffffffe0);
  *packetCursor = (((int)piVar2 - (int)packetCursor) + -8) * 0x4000 | 0xc0001000;
  piVar2[-1] = (int)piVar2 - (int)packetCursor;
  puVar5 = *(uint **)(ctx + 0x1d8);
  *puVar5 = (int)piVar2 - (int)puVar5 >> 2 | *puVar5;
  *(int **)(ctx + 0x1d8) = piVar2;
  *piVar2 = opcodeCount * 0x1000000 + 0x6000000;
  piVar2[1] = **(int **)(unitObject + 0x34);
  piVar6 = (int *)(*(int *)(unitObject + 0x34) + 0x10);
  bVar3 = false;
  do {
    if (reservation != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar6 + 0x10000,0,piVar6);
      *piVar6 = iVar1;
      bVar3 = true;
    }
  } while (!bVar3);
  uVar4 = *(uint *)(unitObject + 200);
  piVar2[2] = *(int *)(unitObject + 0x40);
  if ((uVar4 & 0xc00000) == 0) {
    return (uint *)(piVar2 + 3);
  }
  piVar2[3] = *(uint *)(unitObject + 0xcc) >> 2 | (uint)*(byte *)(unitObject + 0x38) << 0x18;
  return (uint *)(piVar2 + 4);
}

/* FUN_0002ce40 @ 0x2ce40 (492 bytes) */
int FUN_0002ce40(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 staleArgR5;
  undefined4 staleArgR6;
  undefined4 *a1;
  int iVar4;
  uint a6;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar5 = *(int *)(param_1 + 4);
  iVar6 = iVar5;
  for (uVar7 = (uint)*(ushort *)(param_2 + 6); uVar7 != 0; uVar7 = uVar7 >> 1) {
    if (((((uVar7 & 1) != 0) && (iVar4 = *(int *)(iVar6 + 0x18c), iVar4 != 0)) &&
        (*(short *)(*(int *)(iVar4 + 0x30) + 2) == 0x1902)) && (*(char *)(iVar4 + 200) == '\x01')) {
      puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x3fa);
      *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2;
      a1 = puVar2 + 0x3f8;
      puVar1 = *(uint **)(iVar5 + 0x1d8);
      *puVar1 = (int)puVar2 - (int)puVar1 >> 2 | *puVar1;
      *(undefined4 **)(iVar5 + 0x1d8) = puVar2;
      *puVar2 = 0x45000000;
      puVar2[1] = 0x3ed;
      puVar2[2] = 0xd;
      puVar2[3] = **(undefined4 **)(*(int *)(iVar6 + 0x18c) + 0x34);
      a6 = (uint)*(byte *)(*(int *)(iVar6 + 0x18c) + 0x38);
      puVar2[0x3ed] = ((unsigned char *)0x000013c4U);
      puVar2[4] = a6;
      puVar2[0x3f6] = ((unsigned char *)0x000013caU);
      puVar2[0x3f4] = ((unsigned char *)0x000013ccU);
      puVar2[0x3ef] = 0x113c8;
      puVar2[0x3f2] = ((unsigned char *)0x000013cdU);
      *(undefined4 **)(0x00002748 + param_1 + 4) = a1;
      (**(code **)(param_1 + 0x275c))(param_1,a1,staleArgR5,staleArgR6,a1,0x113c8,a6,puVar2 + 0x3ed);
      if (*(int *)(iVar5 + 0x1e4) + 0x28U < *(uint *)(iVar5 + 0x1dc)) {
        gld_submitRing(iVar5,0x1000000);
      }
      *(undefined1 *)(*(int *)(iVar6 + 0x18c) + 200) = 0;
    }
    iVar6 = iVar6 + 4;
  }
  uVar7 = (uint)*(ushort *)(param_2 + 6);
  uVar3 = (**(code **)(param_1 + 0x2758))(param_1,0x96);
  *(undefined4 *)(0x00002748 + param_1 + 4) = uVar3;
  if (uVar7 != 0) {
    iVar4 = 0;
    iVar6 = iVar5;
    do {
      if ((uVar7 & 1) != 0) {
        uVar3 = ((int (*)())gld_emitUnitObjectPacket)(iVar5,*(undefined4 *)(iVar6 + 0x18c),iVar4,uVar3);
      }
      uVar7 = uVar7 >> 1;
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar7 != 0);
  }
  *(undefined4 *)(0x00002748 + param_1 + 4) = uVar3;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,uVar3);
  return;
}

/* FUN_0002d030 @ 0x2d030 (456 bytes) */
int FUN_0002d030(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  uVar2 = *(uint *)(param_1 + 0x18) & 0xfff07fff;
  *(uint *)(param_1 + 0x18) = uVar2;
  if ((uVar1 & 0xe00000) == 0) {
    *(uint *)(param_1 + 0x18) = uVar2;
    if (param_2 == 0x2700) {
      uVar2 = uVar1 & 0xffff87ff | 0x2800;
      *(uint *)(param_1 + 0x14) = uVar2;
    }
    else {
      uVar2 = uVar1;
      if (param_2 < 0x2701) {
        if (param_2 == 0x2600) {
          uVar2 = uVar1 & 0xffff87ff | 0x800;
          *(uint *)(param_1 + 0x14) = uVar2;
        }
        else if (param_2 == 0x2601) {
          uVar2 = uVar1 & 0xffff87ff | 0x1000;
          *(uint *)(param_1 + 0x14) = uVar2;
        }
      }
      else if (param_2 == 0x2702) {
        uVar2 = uVar1 & 0xffff87ff | 0x4800;
        *(uint *)(param_1 + 0x14) = uVar2;
      }
      else if (param_2 < 0x2702) {
        uVar2 = uVar1 & 0xffff87ff | 0x3000;
        *(uint *)(param_1 + 0x14) = uVar2;
      }
      else if (param_2 == 0x2703) {
        uVar2 = uVar1 & 0xffff87ff | 0x5000;
        *(uint *)(param_1 + 0x14) = uVar2;
      }
    }
    goto LAB_0002d190;
  }
  uVar2 = uVar1 & 0xffffe7ff | 0x1800;
  *(uint *)(param_1 + 0x14) = uVar2;
  if (param_2 == 0x2700) {
LAB_0002d0a0:
    uVar2 = uVar1 & 0xffff87ff | 0x3800;
    *(uint *)(param_1 + 0x14) = uVar2;
  }
  else {
    if (param_2 < 0x2701) {
      if (param_2 - 0x2600 < 2) {
        uVar2 = uVar1 & 0xffff87ff | 0x1800;
        *(uint *)(param_1 + 0x14) = uVar2;
      }
      goto LAB_0002d190;
    }
    if (param_2 != 0x2702) {
      if (param_2 < 0x2702) goto LAB_0002d0a0;
      if (param_2 != 0x2703) goto LAB_0002d190;
    }
    uVar2 = uVar1 & 0xffff87ff | 0x5800;
    *(uint *)(param_1 + 0x14) = uVar2;
  }
LAB_0002d190:
  if (*(char *)(param_1 + 0x35) != '\0') {
    uVar1 = *(uint *)(param_1 + 0x18);
    *(uint *)(param_1 + 0x18) = uVar1 & 0xfff1ffff;
    if (1 < (uVar2 >> 0xb & 3)) {
      uVar2 = uVar2 & 0xffffe7ff | 0x800;
      *(uint *)(param_1 + 0x14) = uVar2;
    }
    if ((uVar2 & 0x6000) == 0x4000) {
      uVar2 = uVar2 & 0xffff9fff | 0x2000;
      *(uint *)(param_1 + 0x14) = uVar2;
      *(uint *)(param_1 + 0x18) = uVar1 & 0xfff07fff;
    }
  }
  *(bool *)(param_1 + 0x36) = (uVar2 & 0x1e00) == 0xa00;
  return;
}

/* FUN_0002d210 @ 0x2d210 (140 bytes) */
int FUN_0002d210(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if ((uVar1 & 0xe00000) == 0) {
    if (param_2 == 0x2600) {
      uVar1 = uVar1 & 0xfffff9ff | 0x200;
      *(uint *)(param_1 + 0x14) = uVar1;
    }
    else if (param_2 == 0x2601) {
      uVar1 = uVar1 & 0xfffff9ff | 0x400;
      *(uint *)(param_1 + 0x14) = uVar1;
    }
  }
  else {
    uVar1 = uVar1 & 0xfffff9ff | 0x600;
    *(uint *)(param_1 + 0x14) = uVar1;
  }
  if ((*(char *)(param_1 + 0x35) != '\0') && (1 < (uVar1 >> 9 & 3))) {
    uVar1 = uVar1 & 0xfffff9ff | 0x200;
    *(uint *)(param_1 + 0x14) = uVar1;
  }
  *(bool *)(param_1 + 0x36) = (uVar1 & 0x1e00) == 0xa00;
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
    goto LAB_0002d9d4;
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
    goto LAB_0002d9d0;
  case '\x1a':
    alphaScaled = alphaClamped * (double)FLOAT_001aa14c + (double)FLOAT_001aa10c;
    roundedD = (double)(float)alphaScaled;
    if (DOUBLE_001aa1e8 <= roundedD) {
      channelInt = (int)(roundedD - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      channelInt = (uint)(int)alphaScaled;
    }
LAB_0002d9d0:
    channelInt = channelInt & 0xffff;
LAB_0002d9d4:
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
    goto LAB_0002dcb4;
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
LAB_0002dcb4:
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
asm(".globl FUN_00026bf0");
asm(".set FUN_00026bf0, _gld_drawArraysDirect");
asm(".globl FUN_00026f80");
asm(".set FUN_00026f80, _FUN_00026f80");
asm(".globl FUN_00027150");
asm(".set FUN_00027150, _FUN_00027150");
asm(".globl FUN_000273a0");
asm(".set FUN_000273a0, _gld_reserveDrawSpace");
asm(".globl glReadPixels_entry");
asm(".set glReadPixels_entry, _glReadPixels_entry");
asm(".globl FUN_0002b740");
asm(".set FUN_0002b740, _FUN_0002b740");
asm(".globl FUN_0002bbc4");
asm(".set FUN_0002bbc4, _FUN_0002bbc4");
asm(".globl FUN_0002be00");
asm(".set FUN_0002be00, _FUN_0002be00");
asm(".globl FUN_0002be60");
asm(".set FUN_0002be60, _FUN_0002be60");
