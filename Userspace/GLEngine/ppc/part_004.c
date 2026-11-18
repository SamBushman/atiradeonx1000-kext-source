#include "decls.h"

/* _gleIsIndex @ 0x2f1ac (20 bytes) */
int _gleIsIndex(param_1)
  int param_1;
{
  return param_1 - 0x1900U < 2;
}

/* _gleExtractPixel_RGBA_Ubyte @ 0x2f1c0 (176 bytes) */
void _gleExtractPixel_RGBA_Ubyte(param_1, param_2)
  int param_1;
  byte *param_2;
{
  float fVar1;
  
  fVar1 = FLOAT_00108e78;
  *(float *)(param_1 + 4) = (GH_U2F((unsigned int)((*param_2 | 0x4b000000))) - 8388608.0) * FLOAT_00108e78;
  *(float *)(param_1 + 8) = (GH_U2F((unsigned int)((param_2[1] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0xc) = (GH_U2F((unsigned int)((param_2[2] | 0x4b000000))) - 8388608.0) * fVar1;
  *(float *)(param_1 + 0x10) = (GH_U2F((unsigned int)((param_2[3] | 0x4b000000))) - 8388608.0) * fVar1;
  return;
}

/* _gleUpdateLightRGBASums @ 0x2f270 (1740 bytes) */
double _gleUpdateLightRGBASums(glContext, material, faceIndex)
  int glContext;
  float *material;
  int faceIndex;
{
  float float10;
  uint loopIndex3;
  float *cursor3;
  float *cursor2;
  int remaining2;
  int remaining;
  int loopIndex;
  byte dirtyBitIndex;
  byte dirtyMask;
  float linkedMaterial;
  float sceneColorRed;
  float materialSpecularG;
  float materialDiffuseG;
  float materialAmbientG;
  float copiedTableEntry;
  float linkedShininessCache1;
  float powTableStartLoaded;
  float linkedSceneGreen;
  float *srcCursor;
  int iVar6;
  int linkedLightProducts;
  int glContextWord5424;
  undefined4 uVar7;
  uint loopIndex2;
  float sceneColorGreen;
  float lightSpecularB;
  float lightDiffuseG;
  float lightAmbientG;
  float linkedShininessCache2;
  float linkedAmbientSumBlue;
  float sceneColorBlue;
  float lightSpecularG;
  float lightDiffuseB;
  float lightAmbientB;
  float linkedShininessCache3;
  float linkedAmbientSumGreen;
  float linkedSceneBlue;
  float materialSpecularB;
  float materialDiffuseB;
  float materialAmbientB;
  float linkedShininessCache4;
  float *cursor;
  undefined4 uVar13;
  float linkedAmbientSumRed;
  float materialSpecularA;
  float materialDiffuseA;
  float materialAmbientA;
  int iVar15;
  int glContextWord54242;
  float linkedSceneAlpha;
  undefined4 uVar17;
  int iVar18;
  uint copyFromLinkedMask;
  uint glContextWord30a0;
  int iVar21;
  int iVar22;
  int userLightRecord;
  int glContextWord54243;
  double dVar23;
  double powSample;
  double powTableStartDouble;
  double powTableX;
  double powConstResult;
  float powTableStart;
  float shininess;
  float dVar27;
  
  linkedMaterial = material[0x8f];
  dirtyMask = *(byte *)((int)material + 0x235) | *(byte *)(material + 0x8d);
  if (linkedMaterial == 0.0) {
    copyFromLinkedMask = 0;
    linkedMaterial = 0.0;
  }
  else {
    copyFromLinkedMask = 0;
    if (*(char *)((int)GH_F2U(linkedMaterial) + 0x236) == '\0') {
      copyFromLinkedMask = ~(uint)(*(byte *)((int)material + 0x235) | *(byte *)((int)GH_F2U(linkedMaterial) + 0x234)) & 0xff;
    }
  }
  if ((dirtyMask & 0xe) != 0) {
    if ((copyFromLinkedMask & 0xe) == 0xe) {
      linkedSceneGreen = *(float *)((int)GH_F2U(linkedMaterial) + 0x1d4);
      linkedSceneBlue = *(float *)((int)GH_F2U(linkedMaterial) + 0x1d8);
      linkedSceneAlpha = *(float *)((int)GH_F2U(linkedMaterial) + 0x1dc);
      linkedAmbientSumRed = *(float *)((int)GH_F2U(linkedMaterial) + 0x1e8);
      linkedAmbientSumGreen = *(float *)((int)GH_F2U(linkedMaterial) + 0x1ec);
      linkedAmbientSumBlue = *(float *)((int)GH_F2U(linkedMaterial) + 0x1f0);
      material[0x74] = *(float *)((int)GH_F2U(linkedMaterial) + 0x1d0);
      material[0x75] = linkedSceneGreen;
      material[0x76] = linkedSceneBlue;
      material[0x77] = linkedSceneAlpha;
      material[0x7a] = linkedAmbientSumRed;
      material[0x7b] = linkedAmbientSumGreen;
      material[0x7c] = linkedAmbientSumBlue;
    }
    else {
      sceneColorRed = *(float *)(glContext + 0x2810) * *material + material[0xc];
      sceneColorGreen = *(float *)(glContext + 0x2814) * material[1] + material[0xd];
      sceneColorBlue = *(float *)(glContext + 0x2818) * material[2] + material[0xe];
      material[0x7a] = sceneColorRed;
      material[0x77] = material[7];
      material[0x7b] = sceneColorGreen;
      material[0x7c] = sceneColorBlue;
      material[0x74] = sceneColorRed;
      material[0x75] = sceneColorGreen;
      material[0x76] = sceneColorBlue;
      if (*(int *)(glContext + 0x5434) == 0) {
        dirtyBitIndex = *(byte *)(faceIndex * 6 + *(int *)(glContext + 0x5420) + 0x2c5);
      }
      else {
        dirtyBitIndex = *(byte *)(faceIndex * 6 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x2f9);
      }
      iVar21 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
      glContextWord54243 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar21 + 0x324) = *(uint *)(iVar21 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
      dirtyBitIndex = *(byte *)(faceIndex * 6 + glContextWord54243 + 0x2c5);
      iVar22 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
      *(uint *)(iVar22 + 0x348) = *(uint *)(iVar22 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
    }
  }
  shininess = (double)material[0x10];
  if (((dirtyMask & 1) != 0) && ((double)shininess != (double)material[0x7d])) {
    if ((copyFromLinkedMask & 1) == 0) {
      material[0x7d] = material[0x10];
      if ((double)FLOAT_00108e80 < (double)shininess) {
        dVar27 = (double)FLOAT_00108e54;
        loopIndex2 = 0;
        powTableStartDouble = _log(DOUBLE_00108dd8);
        float10 = FLOAT_00108f44;
        cursor2 = material + 0x82;
        powTableStartDouble = _exp(powTableStartDouble / (double)shininess);
        powTableStart = (double)(float)powTableStartDouble;
        dVar23 = (double)FLOAT_00108f40;
        material[0x7e] = (float)powTableStartDouble;
        powConstResult = DOUBLE_00108de0;
        material[0x80] = (float)(dVar23 / (double)powTableStart);
        material[0x7f] = float10 / (dVar27 - powTableStart);
        powConstResult = _pow(powConstResult,(double)shininess);
        powTableStartLoaded = material[0x7e];
        material[0x81] = (float)(powConstResult - DOUBLE_00108d68);
        powTableX = (double)powTableStartLoaded;
        do {
          loopIndex2 = loopIndex2 + 1;
          powSample = _pow(powTableX,(double)shininess);
          *cursor2 = (float)powSample;
          cursor2 = cursor2 + 1;
          powTableX = (double)(float)(powTableX + (double)((dVar27 - powTableStartLoaded) / float10));
        } while (loopIndex2 < 10);
        material[0x8c] = 1.0;
      }
      else {
        remaining = 0xb;
        material[0x81] = 1.0;
        material[0x7e] = 1.0;
        cursor3 = material + 0x82;
        material[0x7f] = 1.0;
        material[0x80] = 1.0;
        do {
          *cursor3 = 1.0;
          cursor3 = cursor3 + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
    }
    else {
      linkedShininessCache1 = *(float *)((int)GH_F2U(linkedMaterial) + 0x1f8);
      remaining2 = 0xb;
      linkedShininessCache2 = *(float *)((int)GH_F2U(linkedMaterial) + 0x1fc);
      cursor = material + 0x82;
      linkedShininessCache3 = *(float *)((int)GH_F2U(linkedMaterial) + 0x200);
      srcCursor = (float *)((int)GH_F2U(linkedMaterial) + 0x208);
      linkedShininessCache4 = *(float *)((int)GH_F2U(linkedMaterial) + 0x204);
      material[0x7d] = *(float *)((int)GH_F2U(linkedMaterial) + 500);
      material[0x7e] = linkedShininessCache1;
      material[0x7f] = linkedShininessCache2;
      material[0x80] = linkedShininessCache3;
      material[0x81] = linkedShininessCache4;
      do {
        copiedTableEntry = *srcCursor;
        srcCursor = srcCursor + 1;
        *cursor = copiedTableEntry;
        cursor = cursor + 1;
        remaining2 = remaining2 + -1;
      } while (remaining2 != 0);
    }
  }
  glContextWord30a0 = *(uint *)(glContext + 0x30a0);
  loopIndex3 = 0;
  loopIndex = 0;
  userLightRecord = glContext;
  do {
    if ((glContextWord30a0 & 1 << (loopIndex3 & 0x3f)) == 0) {
      if (glContextWord30a0 >> (loopIndex3 & 0x3f) == 0) {
        *(undefined1 *)(material + 0x8d) = 0;
        return;
      }
    }
    else {
      linkedLightProducts = (int)GH_F2U(linkedMaterial) + loopIndex;
      if ((dirtyMask >> 2 & 1) != 0) {
        if ((copyFromLinkedMask & 4) == 0) {
          materialAmbientG = material[1];
          lightAmbientG = *(float *)(userLightRecord + 0x2824);
          lightAmbientB = *(float *)(userLightRecord + 0x2828);
          materialAmbientB = material[2];
          materialAmbientA = material[3];
          *(float *)((int)material + loopIndex + 0x50) = *(float *)(userLightRecord + 0x2820) * *material;
          *(float *)((int)material + loopIndex + 0x54) = lightAmbientG * materialAmbientG;
          *(float *)((int)material + loopIndex + 0x5c) = materialAmbientA;
          *(float *)((int)material + loopIndex + 0x58) = lightAmbientB * materialAmbientB;
        }
        else {
          uVar13 = *(undefined4 *)(linkedLightProducts + 0x58);
          uVar7 = *(undefined4 *)(linkedLightProducts + 0x54);
          uVar17 = *(undefined4 *)(linkedLightProducts + 0x5c);
          *(undefined4 *)((int)material + loopIndex + 0x50) = *(undefined4 *)(linkedLightProducts + 0x50);
          *(undefined4 *)((int)material + loopIndex + 0x54) = uVar7;
          *(undefined4 *)((int)material + loopIndex + 0x58) = uVar13;
          *(undefined4 *)((int)material + loopIndex + 0x5c) = uVar17;
        }
        if (*(int *)(glContext + 0x5434) == 0) {
          dirtyBitIndex = *(byte *)(loopIndex3 * 6 + faceIndex * 3 + *(int *)(glContext + 0x5420) + 0x290);
        }
        else {
          dirtyBitIndex = *(byte *)(loopIndex3 * 6 + faceIndex * 3 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) +
                           0x2c4);
        }
        iVar18 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        glContextWord54242 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar18 + 0x324) = *(uint *)(iVar18 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        dirtyBitIndex = *(byte *)(loopIndex3 * 6 + faceIndex * 3 + glContextWord54242 + 0x290);
        iVar15 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(iVar15 + 0x348) = *(uint *)(iVar15 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
      }
      if (((dirtyMask & 0xe) != 0) && ((copyFromLinkedMask & 0xe) != 0xe)) {
        material[0x7a] = material[0x7a] + *(float *)((int)material + loopIndex + 0x50);
        material[0x7b] = material[0x7b] + *(float *)((int)material + loopIndex + 0x54);
        material[0x7c] = material[0x7c] + *(float *)((int)material + loopIndex + 0x58);
      }
      if ((dirtyMask >> 3 & 1) != 0) {
        if ((copyFromLinkedMask & 8) == 0) {
          materialDiffuseG = material[5];
          lightDiffuseG = *(float *)(userLightRecord + 0x2834);
          lightDiffuseB = *(float *)(userLightRecord + 0x2838);
          materialDiffuseB = material[6];
          materialDiffuseA = material[7];
          *(float *)((int)material + loopIndex + 0x60) = *(float *)(userLightRecord + 0x2830) * material[4];
          *(float *)((int)material + loopIndex + 100) = lightDiffuseG * materialDiffuseG;
          *(float *)((int)material + loopIndex + 0x6c) = materialDiffuseA;
          *(float *)((int)material + loopIndex + 0x68) = lightDiffuseB * materialDiffuseB;
        }
        else {
          uVar7 = *(undefined4 *)(linkedLightProducts + 100);
          uVar13 = *(undefined4 *)(linkedLightProducts + 0x68);
          uVar17 = *(undefined4 *)(linkedLightProducts + 0x6c);
          *(undefined4 *)((int)material + loopIndex + 0x60) = *(undefined4 *)(linkedLightProducts + 0x60);
          *(undefined4 *)((int)material + loopIndex + 100) = uVar7;
          *(undefined4 *)((int)material + loopIndex + 0x68) = uVar13;
          *(undefined4 *)((int)material + loopIndex + 0x6c) = uVar17;
        }
        if (*(int *)(glContext + 0x5434) == 0) {
          dirtyBitIndex = *(byte *)(loopIndex3 * 6 + faceIndex * 3 + *(int *)(glContext + 0x5420) + 0x291);
        }
        else {
          dirtyBitIndex = *(byte *)(loopIndex3 * 6 + faceIndex * 3 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) +
                           0x2c5);
        }
        iVar18 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        glContextWord54242 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar18 + 0x324) = *(uint *)(iVar18 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        dirtyBitIndex = *(byte *)(loopIndex3 * 6 + faceIndex * 3 + glContextWord54242 + 0x291);
        iVar15 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(iVar15 + 0x348) = *(uint *)(iVar15 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
      }
      if ((dirtyMask & 0x10) != 0) {
        if ((copyFromLinkedMask >> 4 & 1) == 0) {
          materialSpecularG = material[9];
          lightSpecularB = *(float *)(userLightRecord + 0x2848);
          lightSpecularG = *(float *)(userLightRecord + 0x2844);
          materialSpecularB = material[10];
          materialSpecularA = material[0xb];
          *(float *)((int)material + loopIndex + 0x70) = *(float *)(userLightRecord + 0x2840) * material[8];
          *(float *)((int)material + loopIndex + 0x7c) = materialSpecularA;
          *(float *)((int)material + loopIndex + 0x74) = lightSpecularG * materialSpecularG;
          *(float *)((int)material + loopIndex + 0x78) = lightSpecularB * materialSpecularB;
        }
        else {
          uVar7 = *(undefined4 *)(linkedLightProducts + 0x70);
          uVar13 = *(undefined4 *)(linkedLightProducts + 0x74);
          uVar17 = *(undefined4 *)(linkedLightProducts + 0x78);
          *(undefined4 *)((int)material + loopIndex + 0x7c) = *(undefined4 *)(linkedLightProducts + 0x7c);
          *(undefined4 *)((int)material + loopIndex + 0x70) = uVar7;
          *(undefined4 *)((int)material + loopIndex + 0x74) = uVar13;
          *(undefined4 *)((int)material + loopIndex + 0x78) = uVar17;
        }
        if (*(int *)(glContext + 0x5434) == 0) {
          dirtyBitIndex = *(byte *)(loopIndex3 * 6 + faceIndex * 3 + *(int *)(glContext + 0x5420) + 0x292);
        }
        else {
          dirtyBitIndex = *(byte *)(loopIndex3 * 6 + faceIndex * 3 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) +
                           0x2c6);
        }
        iVar15 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        glContextWord5424 = *(int *)(glContext + 0x5424);
        *(uint *)(iVar15 + 0x324) = *(uint *)(iVar15 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        dirtyBitIndex = *(byte *)(loopIndex3 * 6 + faceIndex * 3 + glContextWord5424 + 0x292);
        iVar6 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
      }
    }
    loopIndex3 = loopIndex3 + 1;
    userLightRecord = userLightRecord + 0x80;
    loopIndex = loopIndex + 0x30;
  } while( true );
}

/* _gliDestroyContext @ 0x2f93c (300 bytes) */
int _gliDestroyContext(glContext)
  int glContext;
{
  int loopIndex;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((glContext == 0) || (*(int *)(glContext + 0x467c) != 0x3463a223)) {
    return 0x2714;
  }
  iVar1 = ((int (*)())_gleTerminateContext)(glContext);
  iVar4 = glContext + 0x10000;
  iVar2 = ((int (*)())_gleReleaseSharedState)(glContext);
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      iVar3 = (**(code **)(*(int *)(iVar4 + -0x777c) + 0x130))(*(undefined4 *)(iVar4 + -0x7a54));
      if (iVar1 == 0) {
        iVar1 = iVar3;
      }
      loopIndex = loopIndex + 1;
      iVar4 = iVar4 + 0x2e0;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  if (iVar2 != 0) {
    ((void (*)())_gleDestroySharedState)(glContext);
  }
  iVar2 = _gl_list;
  iVar4 = 0;
  if (_gl_list != 0) {
    do {
      iVar5 = iVar2;
      if (iVar5 == glContext) break;
      iVar2 = *(int *)(iVar5 + 0x85a0);
      iVar4 = iVar5;
    } while (*(int *)(iVar5 + 0x85a0) != 0);
    if (iVar4 != 0) {
      *(undefined4 *)(iVar4 + 0x85a0) = *(undefined4 *)(glContext + 0x85a0);
      goto LAB_0002fa38;
    }
  }
  _gl_list = *(int *)(glContext + 0x85a0);
LAB_0002fa38:
  if (_gl_list == 0) {
    ((void (*)())_gleDestroyEnableHashTable)();
  }
  ((void (*)())_gleDCBFree)(glContext);
  return iVar1;
}

/* _gleTerminateContext @ 0x2fa68 (192 bytes) */
int _gleTerminateContext(glContext)
  int glContext;
{
  ((int (*)())_gleFreeOrphans)(glContext);
  ((void (*)())_gleFreeVertexMachine)(glContext);
  ((void (*)())_gleFreePixelMap)(glContext);
  ((void (*)())_gleFreeMaterials)(glContext);
  ((void (*)())_gleFreeAllAttrib)(glContext);
  ((void (*)())_gleFreeVertexArrays)(glContext);
  ((void (*)())_gleFreeFunctions)(glContext);
  ((void (*)())_gleFreeQueryMachine)(glContext);
  ((void (*)())_gleFreeFenceMachine)(glContext);
  ((void (*)())_gleFreeVertexArrayState)(glContext);
  ((void (*)())_glePPEmulatorTerminate)(glContext);
  ((void (*)())_gleFreeBufferState)(glContext);
  ((void (*)())_gleFreeShaderState)(glContext);
  ((void (*)())_gleFreePipelineProgramState)(glContext);
  ((void (*)())_gleReclaimDrawPixelResources)(glContext);
  _gleFreeFramebufferState(glContext);
  ((void (*)())_gleFreeMapData)(glContext);
  ((void (*)())_gleFreeTextureState)(glContext);
  _gleVecFree(*(undefined4 *)(glContext + 0x4678));
  return 0;
}

/* _gleFreeOrphans @ 0x2fb28 (264 bytes) */
int _gleFreeOrphans(glContext)
  int glContext;
{
  int *cursor;
  int loopIndex;
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int extraout_r3;
  int iVar4;
  int *glContextPtr7470;
  int *piVar6;
  int iVar7;
  
  iVar3 = glContext;
  if (*(int *)(glContext + 0x7484) != 0) {
    while( true ) {
      glContextPtr7470 = *(int **)(glContext + 0x7470);
      piVar6 = (int *)0x0;
      if (glContextPtr7470 != (int *)(glContext + 0x7468)) {
        iVar7 = glContextPtr7470[3];
        piVar6 = (int *)glContextPtr7470[1];
        iVar3 = glContextPtr7470[2];
        *piVar6 = *glContextPtr7470;
        *(int *)(iVar7 + 8) = iVar3;
        iVar3 = *glContextPtr7470;
        *(int *)(glContextPtr7470[2] + 0xc) = iVar7;
        *(int **)(iVar3 + 4) = piVar6;
        glContextPtr7470[2] = (int)glContextPtr7470;
        glContextPtr7470[3] = (int)glContextPtr7470;
        *glContextPtr7470 = (int)glContextPtr7470;
        glContextPtr7470[1] = (int)glContextPtr7470;
        piVar6 = glContextPtr7470;
      }
      if (piVar6 == (int *)0x0) break;
      iVar3 = glContext + 0x10000;
      loopIndex = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        cursor = piVar6 + 7;
        do {
          piVar1 = (int *)(iVar3 + -0x777c);
          loopIndex = loopIndex + 1;
          iVar4 = *cursor;
          cursor = cursor + 1;
          puVar2 = (undefined4 *)(iVar3 + -0x7a54);
          iVar3 = iVar3 + 0x2e0;
          (**(code **)(*piVar1 + 0x1f8))(*puVar2,iVar4);
        } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
      }
      _gleVecFree(piVar6);
    }
    _gleVecFree(*(undefined4 *)(glContext + 0x7484));
    *(undefined4 *)(glContext + 0x7484) = 0;
    iVar3 = 0;
    if (*(int *)(glContext + 0x7464) != 0) {
      _gleVecFree(*(int *)(glContext + 0x7464));
      *(undefined4 *)(glContext + 0x7464) = 0;
      iVar3 = extraout_r3;
    }
  }
  return iVar3;
}

/* _gleFreeVertexMachine @ 0x2fc30 (136 bytes) */
void _gleFreeVertexMachine(glContext)
  int glContext;
{
  if (*(int *)(glContext + 0x4854) != 0) {
    ((void (*)())_gleDCBFree)(*(int *)(glContext + 0x4854) + -0x200);
    *(undefined4 *)(glContext + 0x485c) = 0;
    *(undefined4 *)(glContext + 0x4854) = 0;
    *(undefined4 *)(glContext + 0x4860) = 0;
    *(undefined4 *)(glContext + 0x4864) = 0;
    *(undefined4 *)(glContext + 0x4870) = 0;
    *(undefined4 *)(glContext + 0x4874) = 0;
    *(undefined4 *)(glContext + 0x30b0) = 0;
    *(undefined4 *)(glContext + 0x4858) = 0;
  }
  if (*(int *)(glContext + 0x7588) != 0) {
    if (*(int *)(glContext + 0x758c) != 0) {
      _free(*(int *)(glContext + 0x758c));
    }
    *(undefined4 *)(glContext + 0x7588) = 0;
    *(undefined4 *)(glContext + 0x758c) = 0;
  }
  return;
}

/* _gleDCBFree @ 0x2fcb8 (12 bytes) */
void _gleDCBFree(glContext)
  int glContext;
{
  _free(glContext - (uint)*(byte *)(glContext + -1));
  return;
}

/* _gleFreePixelMap @ 0x2fcc4 (268 bytes) */
void _gleFreePixelMap(glContext)
  int glContext;
{
  undefined *puVar1;
  
  puVar1 = PTR__gle_default_pix_map_i_00112044;
  if (*(undefined **)(glContext + 0x3248) != PTR__gle_default_pix_map_i_00112044) {
    _free(*(undefined **)(glContext + 0x3248));
    *(undefined **)(glContext + 0x3248) = puVar1;
  }
  if (*(undefined **)(glContext + 0x326c) != puVar1) {
    _free(*(undefined **)(glContext + 0x326c));
    *(undefined **)(glContext + 0x326c) = puVar1;
  }
  puVar1 = PTR__gle_default_pix_map_f_00112040;
  if (*(undefined **)(glContext + 0x324c) != PTR__gle_default_pix_map_f_00112040) {
    _free(*(undefined **)(glContext + 0x324c));
    *(undefined **)(glContext + 0x324c) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3250) != puVar1) {
    _free(*(undefined **)(glContext + 0x3250));
    *(undefined **)(glContext + 0x3250) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3254) != puVar1) {
    _free(*(undefined **)(glContext + 0x3254));
    *(undefined **)(glContext + 0x3254) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3258) != puVar1) {
    _free(*(undefined **)(glContext + 0x3258));
    *(undefined **)(glContext + 0x3258) = puVar1;
  }
  if (*(undefined **)(glContext + 0x325c) != puVar1) {
    _free(*(undefined **)(glContext + 0x325c));
    *(undefined **)(glContext + 0x325c) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3260) != puVar1) {
    _free(*(undefined **)(glContext + 0x3260));
    *(undefined **)(glContext + 0x3260) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3264) != puVar1) {
    _free(*(undefined **)(glContext + 0x3264));
    *(undefined **)(glContext + 0x3264) = puVar1;
  }
  if (*(undefined **)(glContext + 0x3268) != puVar1) {
    _free(*(undefined **)(glContext + 0x3268));
    *(undefined **)(glContext + 0x3268) = puVar1;
  }
  return;
}

/* _gleFreeMaterials @ 0x2fdd0 (140 bytes) */
void _gleFreeMaterials(glContext)
  int glContext;
{
  int remaining;
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(glContext + 0x4dd0);
  remaining = 1;
  do {
    iVar4 = *piVar3;
    for (iVar1 = *(int *)(*piVar3 + 0x23c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x23c)) {
      _gleVecFree(iVar4);
      iVar4 = iVar1;
    }
    remaining = remaining + -1;
    *piVar3 = iVar4;
    piVar3 = piVar3 + 1;
  } while (-1 < remaining);
  iVar2 = *(int *)(glContext + 0x4dd8);
  while (iVar2 != 0) {
    iVar4 = *(int *)(iVar2 + 0x23c);
    _gleVecFree(iVar2);
    iVar2 = iVar4;
  }
  *(undefined4 *)(glContext + 0x4dd8) = 0;
  return;
}

/* _gleFreeAllAttrib @ 0x2fe5c (228 bytes) */
void _gleFreeAllAttrib(glContext)
  int glContext;
{
  int loopIndex2;
  int iVar1;
  int glContextWord5144;
  int glContextWord50fc;
  int iVar2;
  int loopIndex;
  int *piVar4;
  
  loopIndex = 0;
  glContextWord50fc = *(int *)(glContext + 0x50fc);
  if (0 < glContextWord50fc) {
    piVar4 = (int *)(glContext + 0x50b8);
    do {
      iVar2 = *piVar4;
      if (*piVar4 != 0) {
        do {
          iVar1 = *(int *)(iVar2 + 0x2c44);
          _free(iVar2);
          iVar2 = iVar1;
        } while (iVar1 != 0);
        glContextWord50fc = *(int *)(glContext + 0x50fc);
      }
      loopIndex = loopIndex + 1;
      *piVar4 = 0;
      piVar4 = piVar4 + 1;
    } while (loopIndex < glContextWord50fc);
  }
  glContextWord5144 = *(int *)(glContext + 0x5144);
  loopIndex2 = 0;
  if (0 < glContextWord5144) {
    piVar4 = (int *)(glContext + 0x5100);
    do {
      iVar2 = *piVar4;
      if (*piVar4 != 0) {
        do {
          iVar1 = *(int *)(iVar2 + 700);
          _free(iVar2);
          iVar2 = iVar1;
        } while (iVar1 != 0);
        glContextWord5144 = *(int *)(glContext + 0x5144);
      }
      loopIndex2 = loopIndex2 + 1;
      *piVar4 = 0;
      piVar4 = piVar4 + 1;
    } while (loopIndex2 < glContextWord5144);
  }
  *(int *)(glContext + 0x5140) = glContext + 0x5100;
  *(int *)(glContext + 0x50f8) = glContext + 0x50b8;
  *(undefined4 *)(glContext + 0x5144) = 0;
  *(undefined4 *)(glContext + 0x50fc) = 0;
  return;
}

/* _gleFreeVertexArrays @ 0x2ff40 (68 bytes) */
void _gleFreeVertexArrays(glContext)
  int glContext;
{
  if (*(int *)(glContext + 0x49ac) != 0) {
    _free(*(int *)(glContext + 0x49ac));
  }
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x49b4));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x49b8));
  return;
}

/* _gleFreeFuncCache @ 0x2ff84 (68 bytes) */
void _gleFreeFuncCache(param_1)
  int *param_1;
{
  int *piVar1;
  int *piVar2;
  
  piVar1 = param_1;
  if (param_1 != (int *)0x0) {
    do {
      piVar2 = (int *)*piVar1;
      ((void (*)())_gleDCBFree)(piVar1);
      piVar1 = piVar2;
    } while (piVar2 != param_1);
  }
  return;
}

/* _gleFreeFunctions @ 0x2ffc8 (116 bytes) */
void _gleFreeFunctions(glContext)
  int glContext;
{
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x5088));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x5094));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x50a0));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x49d0));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x49d8));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x48a0));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x48a8));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x48c0));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x48b0));
  ((void (*)())_gleFreeFuncCache)(*(undefined4 *)(glContext + 0x48b8));
  return;
}

/* _gleFreeQueryMachine @ 0x3003c (136 bytes) */
void _gleFreeQueryMachine(glContext)
  int glContext;
{
  int remaining;
  int iVar1;
  int *piVar2;
  int *srcCursor;
  int *piVar3;
  int iVar4;
  
  srcCursor = (int *)(glContext + 0x6440);
  remaining = 0x3ff;
  do {
    piVar3 = (int *)*srcCursor;
    srcCursor = srcCursor + 1;
    while (piVar3 != (int *)0x0) {
      iVar4 = *piVar3;
      (*(code *)piVar3[3])(glContext,piVar3);
      piVar3 = (int *)iVar4;
    }
    remaining = remaining + -1;
  } while (-1 < remaining);
  piVar2 = (int *)*(int *)(glContext + 0x7440);
  while (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    _free(piVar2);
    piVar2 = (int *)iVar1;
  }
  return;
}

/* _gleFreeFenceMachine @ 0x300c4 (136 bytes) */
void _gleFreeFenceMachine(glContext)
  int glContext;
{
  int remaining;
  int iVar1;
  int *piVar2;
  int *srcCursor;
  int *piVar3;
  int iVar4;
  
  srcCursor = (int *)(glContext + 0x543c);
  remaining = 0x3ff;
  do {
    piVar3 = (int *)*srcCursor;
    srcCursor = srcCursor + 1;
    while (piVar3 != (int *)0x0) {
      iVar4 = *piVar3;
      (*(code *)piVar3[3])(glContext,piVar3);
      piVar3 = (int *)iVar4;
    }
    remaining = remaining + -1;
  } while (-1 < remaining);
  piVar2 = (int *)*(int *)(glContext + 0x643c);
  while (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    _free(piVar2);
    piVar2 = (int *)iVar1;
  }
  return;
}

/* _gleFreeVertexArrayState @ 0x3014c (180 bytes) */
void _gleFreeVertexArrayState(glContext)
  int glContext;
{
  int iVar1;
  int clientState;
  
  clientState = *(int *)(glContext + 0x4a60);
  if (clientState != 0) {
    if (*(int *)(clientState + 4) != 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      iVar1 = *(int *)(clientState + 8) + -1;
      *(int *)(clientState + 8) = iVar1;
      if (iVar1 == 0) {
        ((int (*)())_gleFreeVertexArrayObject)(glContext,clientState);
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
    }
    ((int (*)())_gleFreeVertexArrayObject)(glContext,*(undefined4 *)(glContext + 0x4a64));
    return;
  }
  return;
}

/* _gleFreeVertexArrayObject @ 0x30200 (196 bytes) */
int _gleFreeVertexArrayObject(glContext, param_2)
  undefined4 glContext;
  int param_2;
{
  int remaining;
  int iVar1;
  int iVar2;
  int iVar3;
  int *srcCursor;
  
  ((void (*)())_gleDestroyPluginVertexArray)(glContext,param_2 + 0x10);
  iVar3 = *(int *)(param_2 + 0x358);
  if ((iVar3 != 0) && (iVar1 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(glContext,iVar3);
  }
  iVar3 = *(int *)(param_2 + 0x35c);
  if ((iVar3 != 0) && (iVar1 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(glContext,iVar3);
  }
  srcCursor = (int *)(param_2 + 0x360);
  remaining = 0x1f;
  do {
    iVar1 = *srcCursor;
    srcCursor = srcCursor + 1;
    if ((iVar1 != 0) && (iVar2 = *(int *)(iVar1 + 8) + -1, *(int *)(iVar1 + 8) = iVar2, iVar2 == 0))
    {
      _gleFreeBufferObject(glContext,iVar1);
    }
    remaining = remaining + -1;
  } while (-1 < remaining);
  _gleVecFree(param_2);
  return;
}

/* _gleDestroyPluginVertexArray @ 0x302c4 (120 bytes) */
void _gleDestroyPluginVertexArray(glContext, param_2)
  int glContext;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int loopIndex;
  
  iVar4 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar4 + -0x777c);
      iVar3 = loopIndex * 4;
      puVar2 = (undefined4 *)(iVar4 + -0x7a54);
      iVar4 = iVar4 + 0x2e0;
      loopIndex = loopIndex + 1;
      (**(code **)(*piVar1 + 0x1b0))(*puVar2,*(undefined4 *)(iVar3 + param_2));
      *(undefined4 *)(iVar3 + param_2) = 0;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _glePPEmulatorTerminate @ 0x30340 (8 bytes) */
void _glePPEmulatorTerminate(glContext)
  int glContext;
{
  _PPEmulatorFree(*(undefined4 *)(glContext + 0x4a5c));
  return;
}

/* _gleFreeBufferState @ 0x30348 (180 bytes) */
void _gleFreeBufferState(glContext)
  int glContext;
{
  int iVar1;
  int glContextPtr48f4;
  int pixelUnpackBuffer;
  int pixelPackBuffer;
  
  glContextPtr48f4 = *(int *)(glContext + 0x48f4);
  if (glContextPtr48f4 != 0) {
    iVar1 = *(int *)(glContextPtr48f4 + 8) + -1;
    *(int *)(glContextPtr48f4 + 8) = iVar1;
    if (iVar1 == 0) {
      _gleFreeBufferObject(glContext,glContextPtr48f4);
    }
    *(undefined4 *)(glContext + 0x48f4) = 0;
  }
  pixelPackBuffer = *(int *)(glContext + 0x4a68);
  if ((pixelPackBuffer != 0) && (iVar1 = *(int *)(pixelPackBuffer + 8) + -1, *(int *)(pixelPackBuffer + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(glContext,pixelPackBuffer);
  }
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  *(undefined4 *)(glContext + 0x4a68) = 0;
  if ((pixelUnpackBuffer != 0) && (iVar1 = *(int *)(pixelUnpackBuffer + 8) + -1, *(int *)(pixelUnpackBuffer + 8) = iVar1, iVar1 == 0)) {
    _gleFreeBufferObject(glContext,pixelUnpackBuffer);
  }
  *(undefined4 *)(glContext + 0x4a6c) = 0;
  return;
}

/* _gleFreeShaderState @ 0x303fc (156 bytes) */
void _gleFreeShaderState(glContext)
  int glContext;
{
  int iVar1;
  int currentProgram;
  
  currentProgram = *(int *)(glContext + 0x5430);
  if (currentProgram != 0) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    iVar1 = *(int *)(currentProgram + 8) + -1;
    *(int *)(currentProgram + 8) = iVar1;
    if (iVar1 == 1) {
      ((int (*)())_gleDeleteHashNameAndObject)(glContext,*(int *)(glContext + 0x5148) + 0x6018,*(undefined4 *)(currentProgram + 4));
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    *(undefined4 *)(glContext + 0x5430) = 0;
  }
  return;
}

/* _gleFreePipelineProgramState @ 0x30498 (208 bytes) */
void _gleFreePipelineProgramState(glContext)
  int glContext;
{
  int iVar1;
  int remaining;
  undefined4 *srcCursor;
  int iVar4;
  
  if (*(int *)(glContext + 0x5418) != 0) {
    _free(*(int *)(glContext + 0x5418));
    *(undefined4 *)(glContext + 0x5418) = 0;
  }
  srcCursor = (undefined4 *)(glContext + 0x5428);
  remaining = 1;
  do {
    iVar4 = srcCursor[-2];
    if (iVar4 != 0) {
      if (*(int *)(iVar4 + 4) != 0) {
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
        }
        iVar1 = *(int *)(iVar4 + 8) + -1;
        *(int *)(iVar4 + 8) = iVar1;
        if (iVar1 == 0) {
          ((void (*)())_gleFreePipelineProgramObject)(glContext,iVar4);
        }
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        }
      }
      ((void (*)())_gleFreePipelineProgramObject)(glContext,*srcCursor);
    }
    remaining = remaining + -1;
    srcCursor = srcCursor + 1;
  } while (-1 < remaining);
  return;
}

/* _gleFreePipelineProgramObject @ 0x30568 (72 bytes) */
void _gleFreePipelineProgramObject(glContext, param_2)
  undefined4 glContext;
  int param_2;
{
  ((void (*)())_gleClearPipelineProgram)(glContext,param_2 + 0x10);
  ((void (*)())_gleDestroyPluginPipelineProgram)(glContext,param_2 + 0x10);
  _gleVecFree(param_2);
  return;
}

/* _gleClearPipelineProgram @ 0x305b0 (364 bytes) */
void _gleClearPipelineProgram(glContext, param_2)
  undefined4 glContext;
  int *param_2;
{
  int iVar1;
  int iVar2;
  int loopIndex;
  int iVar4;
  int remaining;
  
  iVar4 = param_2[0x12f];
  if (param_2[1] != 0) {
    _free(param_2[1]);
    param_2[1] = 0;
  }
  param_2[2] = 0;
  param_2[3] = 0;
  *(undefined2 *)(param_2 + 0x10) = 0;
  *(undefined2 *)((int)param_2 + 0x42) = 0;
  *(undefined2 *)(param_2 + 0x11) = 0;
  *(undefined2 *)((int)param_2 + 0x46) = 0;
  *(undefined2 *)((int)param_2 + 0x3e) = 0;
  if (*param_2 != 0) {
    _PPStreamFree(*param_2);
    *param_2 = 0;
  }
  if (*(short *)((int)param_2 + 0x4ba) == 0) {
    if (param_2[0x135] != 0) {
      _PPEmulatorProgramFree(param_2[0x135]);
      param_2[0x135] = 0;
    }
    remaining = 0x100;
  }
  else if (*(short *)((int)param_2 + 0x4ba) == 1) {
    if (param_2[0x135] != 0) {
      _LFSStreamFree(param_2[0x135]);
      param_2[0x135] = 0;
    }
    *(undefined2 *)(param_2 + 0x138) = 0;
    *(undefined2 *)(param_2 + 0x137) = 0;
    *(undefined2 *)((int)param_2 + 0x4de) = 0;
    remaining = 0x80;
  }
  else {
    remaining = 0;
  }
  if (iVar4 != 0) {
    if (*(short *)(param_2 + 0x12e) != -0x7e00) {
      ((void (*)())_glePPUnlogParameters)(glContext,param_2,*(undefined4 *)(iVar4 + 0x28),iVar4 + *(int *)(iVar4 + 0x2c) * 8);
    }
    _gleVecFree(iVar4);
    param_2[0x12f] = 0;
  }
  iVar4 = param_2[0x134];
  if (iVar4 != 0) {
    loopIndex = 0;
    for (; remaining != 0; remaining = remaining + -1) {
      iVar1 = loopIndex * 0x10;
      loopIndex = loopIndex + 1;
      iVar2 = iVar1 + iVar4;
      *(undefined4 *)(iVar4 + iVar1) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0x3f800000;
      *(undefined4 *)(iVar2 + 4) = 0;
      *(undefined4 *)(iVar2 + 8) = 0;
    }
  }
  return;
}

/* _gleDestroyPluginPipelineProgram @ 0x3071c (120 bytes) */
void _gleDestroyPluginPipelineProgram(glContext, param_2)
  int glContext;
  int param_2;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int loopIndex;
  
  iVar3 = glContext + 0x10000;
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar3 + -0x777c);
      loopIndex = loopIndex + 1;
      puVar2 = (undefined4 *)(iVar3 + -0x7a54);
      iVar3 = iVar3 + 0x2e0;
      (**(code **)(*piVar1 + 0x1a0))(*puVar2,*(undefined4 *)(param_2 + 0x498));
      *(undefined4 *)(param_2 + 0x498) = 0;
      param_2 = param_2 + 4;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleReclaimDrawPixelResources @ 0x30794 (184 bytes) */
void _gleReclaimDrawPixelResources(glContext)
  int glContext;
{
  undefined4 *glContextPtr74a0;
  uint loopIndex;
  
  glContextPtr74a0 = *(undefined4 **)(glContext + 0x74a0);
  if (glContextPtr74a0 != (undefined4 *)0x0) {
    loopIndex = 0;
    if (*(int *)(glContext + 0x7490) != 0) {
      while( true ) {
        _gleDeletePluginTexture(glContext,glContextPtr74a0[loopIndex]);
        if (*(uint *)(glContext + 0x7490) <= loopIndex + 1) break;
        glContextPtr74a0 = *(undefined4 **)(glContext + 0x74a0);
        loopIndex = loopIndex + 1;
      }
      glContextPtr74a0 = *(undefined4 **)(glContext + 0x74a0);
    }
    _gleVecFree(*glContextPtr74a0);
    _gleVecFree(*(undefined4 *)(glContext + 0x74a0));
  }
  if (*(int *)(0x74a4 + glContext) != 0) {
    _gleVecFree(*(int *)(0x74a4 + glContext));
  }
  *(undefined4 *)(0x74a4 + glContext) = 0;
  *(undefined4 *)(glContext + 0x7488) = 0;
  *(undefined4 *)(glContext + 0x7494) = 0;
  *(undefined4 *)(glContext + 0x748c) = 0;
  *(undefined4 *)(glContext + 0x7490) = 0;
  *(undefined4 *)(glContext + 0x7498) = 0;
  *(undefined4 *)(glContext + 0x749c) = 0;
  *(undefined4 *)(glContext + 0x74a0) = 0;
  return;
}

/* _gleFreeMapData @ 0x3084c (16 bytes) */
void _gleFreeMapData(glContext)
  int glContext;
{
  if (*(int *)(glContext + 0x7450) == 0) {
    return;
  }
  _free(*(int *)(glContext + 0x7450));
  return;
}

/* _gleFreeTextureState @ 0x3085c (376 bytes) */
void _gleFreeTextureState(glContext)
  int glContext;
{
  int remaining2;
  int remaining;
  int loopIndex;
  int refCount;
  int iVar2;
  int iVar3;
  int remaining3;
  int *srcCursor;
  int textureObject;
  
  loopIndex = 0;
  iVar3 = glContext;
  do {
    srcCursor = (int *)(iVar3 + 0x5154);
    remaining3 = 4;
    do {
      textureObject = *srcCursor;
      srcCursor = srcCursor + 1;
      if ((textureObject != 0) && (*(int *)(textureObject + 4) != 0)) {
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
        }
        refCount = *(int *)(textureObject + 8) + -1;
        *(int *)(textureObject + 8) = refCount;
        if (refCount == 0) {
          _gleFreeTextureObject(glContext,textureObject);
        }
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        }
      }
      remaining3 = remaining3 + -1;
    } while (-1 < remaining3);
    loopIndex = loopIndex + 1;
    iVar3 = iVar3 + 0x14;
  } while (loopIndex < 0x10);
  srcCursor = (int *)(glContext + 0x52d4);
  remaining = 0xf;
  do {
    iVar2 = *srcCursor;
    srcCursor = srcCursor + 1;
    if (iVar2 != 0) {
      _gleFreeTextureObject(glContext,iVar2);
    }
    remaining = remaining + -1;
  } while (-1 < remaining);
  iVar2 = glContext + 0x52b0;
  remaining2 = 2;
  do {
    if (*(int *)(iVar2 + 0xc) != 0) {
      _gleFreeTextureObject(glContext,*(int *)(iVar2 + 0xc));
    }
    if (*(int *)(iVar2 + 0x18) != 0) {
      _gleFreeTextureObject(glContext,*(int *)(iVar2 + 0x18));
    }
    remaining2 = remaining2 + -1;
    iVar2 = iVar2 + 4;
  } while (-1 < remaining2);
  iVar3 = glContext;
  do {
    if (*(int *)(iVar3 + 0x5294) != 0) {
      _gleFreeTextureObject(glContext,*(int *)(iVar3 + 0x5294));
    }
    if (*(int *)(iVar3 + 0x52a8) != 0) {
      _gleFreeTextureObject(glContext,*(int *)(iVar3 + 0x52a8));
    }
    iVar3 = iVar3 + 4;
  } while (iVar3 <= glContext + 0x10);
  return;
}

/* _gleReleaseSharedState @ 0x309d4 (288 bytes) */
int _gleReleaseSharedState(glContext)
  int glContext;
{
  int remaining;
  int loopIndex;
  undefined4 releasedLastReference;
  undefined *tableCursor;
  int referenceCountBefore;
  undefined *sharedStateThenRecordCursor;
  int bucketOffset;
  int *objectOrRangeNode;
  int *nextObjectOrRangeNode;
  int remaining2;
  
  sharedStateThenRecordCursor = *(undefined **)(glContext + 0x5148);
  _pthread_mutex_lock(sharedStateThenRecordCursor + 0x8028);
  referenceCountBefore = *(int *)(sharedStateThenRecordCursor + 0x8020);
  *(int *)(sharedStateThenRecordCursor + 0x8020) = referenceCountBefore + -1;
  _pthread_mutex_unlock(sharedStateThenRecordCursor + 0x8028);
  releasedLastReference = 0;
  if (referenceCountBefore < 2) {
    loopIndex = 0;
    ((void (*)())_gleDetachShaderObjects)(glContext);
    tableCursor = sharedStateThenRecordCursor;
    do {
      remaining2 = 0x3ff;
      bucketOffset = loopIndex * 0x1004;
      do {
        objectOrRangeNode = *(int **)(sharedStateThenRecordCursor + bucketOffset);
        if (objectOrRangeNode != (int *)0x0) {
          *(undefined4 *)(sharedStateThenRecordCursor + bucketOffset) = 0;
          do {
            nextObjectOrRangeNode = (int *)*objectOrRangeNode;
            (*(code *)objectOrRangeNode[3])(glContext,objectOrRangeNode);
            objectOrRangeNode = nextObjectOrRangeNode;
          } while (nextObjectOrRangeNode != (int *)0x0);
        }
        remaining2 = remaining2 + -1;
        bucketOffset = bucketOffset + 4;
      } while (-1 < remaining2);
      objectOrRangeNode = *(int **)(tableCursor + 0x1000);
      if (objectOrRangeNode != (int *)0x0) {
        *(undefined4 *)(tableCursor + 0x1000) = 0;
        do {
          nextObjectOrRangeNode = (int *)*objectOrRangeNode;
          _free(objectOrRangeNode);
          objectOrRangeNode = nextObjectOrRangeNode;
        } while (nextObjectOrRangeNode != (int *)0x0);
      }
      loopIndex = loopIndex + 1;
      tableCursor = ((unsigned char *)0x00001004) + (int)tableCursor;
    } while (loopIndex < 8);
    sharedStateThenRecordCursor = sharedStateThenRecordCursor + 0x10000;
    remaining = 1;
    do {
      if (*(int *)(sharedStateThenRecordCursor + -0x7560) != 0) {
        _free(*(int *)(sharedStateThenRecordCursor + -0x7560));
      }
      remaining = remaining + -1;
      *(undefined4 *)(sharedStateThenRecordCursor + -0x7560) = 0;
      sharedStateThenRecordCursor = sharedStateThenRecordCursor + 0xa30;
    } while (-1 < remaining);
    releasedLastReference = 1;
  }
  return releasedLastReference;
}

/* _gleDetachShaderObjects @ 0x30af4 (144 bytes) */
void _gleDetachShaderObjects(glContext)
  int glContext;
{
  undefined *puVar1;
  int sharedState;
  int *piVar3;
  int *piVar4;
  
  puVar1 = PTR__gleDetachShaderObjectIterFunc_001113e8;
  sharedState = *(int *)(glContext + 0x5148);
  piVar4 = (int *)(sharedState + 0x6018);
  do {
    piVar3 = piVar4 + 1;
    for (piVar4 = (int *)*piVar4; piVar4 != (int *)0x0; piVar4 = (int *)*piVar4) {
      (*(code *)puVar1)(glContext,piVar4);
    }
    piVar4 = piVar3;
  } while ((int)piVar3 <= sharedState + 0x7014);
  return;
}

/* _gleDestroySharedState @ 0x30b84 (132 bytes) */
void _gleDestroySharedState(glContext)
  int glContext;
{
  int iVar1;
  undefined4 uVar2;
  int sharedState;
  int loopIndex;
  undefined4 *srcCursor2;
  int *srcCursor;
  
  loopIndex = 0;
  sharedState = *(int *)(glContext + 0x5148);
  if (*(char *)(glContext + 0x85a4) != '\0') {
    srcCursor = (int *)(glContext + 0x8884);
    srcCursor2 = (undefined4 *)(sharedState + 0x8054);
    do {
      iVar1 = *srcCursor;
      srcCursor = srcCursor + 0xb8;
      uVar2 = *srcCursor2;
      loopIndex = loopIndex + 1;
      srcCursor2 = srcCursor2 + 1;
      (**(code **)(iVar1 + 0x128))(uVar2);
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  _pthread_mutex_destroy(sharedState + 0x8028);
  _free(sharedState);
  return;
}

/* _glTexCoord2fv_Exec @ 0x30c08 (36 bytes) */
void _glTexCoord2fv_Exec(glContext, v)
  int glContext;
  undefined4 *v;
{
  undefined4 uVar1;
  
  uVar1 = v[1];
  *(undefined4 *)(glContext + 0x120) = *v;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(undefined4 *)(glContext + 0x124) = uVar1;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  return;
}

/* _glVertex2i_Exec @ 0x30c2c (144 bytes) */
void _glVertex2i_Exec(glContext, x, y)
  int glContext;
  uint x;
  uint y;
{
  code *vertexFunc;
  
  vertexFunc = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    vertexFunc = *(code **)(glContext + 0x28);
  }
  (*vertexFunc)(glContext,(double)(float)((double)CONCAT44(0x43300000,x ^ 0x80000000) -
                                   DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,y ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(glContext + 0x20),(double)*(float *)(glContext + 0x24));
  return;
}

/* _glGetBooleanv_Exec @ 0x30cbc (272 bytes) */
void _glGetBooleanv_Exec(glContext, pname, params)
  int glContext;
  undefined4 pname;
  int params;
{
  int loopIndex2;
  double doubleZero;
  undefined4 glErrorCode;
  int iVar3;
  int remaining;
  double *cursor;
  int loopIndex;
  double dVar7;
  undefined1 auStack_b0 [16];
  double local_a0 [16];
  int valueType [4];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    cursor = local_a0;
    remaining = _gleGetState(glContext,pname,cursor,valueType,auStack_b0);
    doubleZero = DOUBLE_00108d60;
    if (remaining == 0) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
      goto LAB_00030d30;
    }
    if (remaining != -1) {
      if (valueType[0] != 0x1404) {
        loopIndex = 0;
        if (remaining < 1) {
          return;
        }
        do {
          dVar7 = *cursor;
          cursor = cursor + 1;
          *(bool *)(params + loopIndex) = dVar7 != doubleZero;
          loopIndex = loopIndex + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
        return;
      }
      loopIndex2 = 0;
      if (remaining < 1) {
        return;
      }
      do {
        iVar3 = *(int *)cursor;
        cursor = cursor + 1;
        *(char *)(params + loopIndex2) = '\x01' - (iVar3 == 0);
        loopIndex2 = loopIndex2 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      return;
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_00030d30:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDeleteProgramsARB_Exec @ 0x30dcc (300 bytes) */
void _glDeleteProgramsARB_Exec(glContext, n, programs)
  int glContext;
  int n;
  int *programs;
{
  undefined4 glErrorCode;
  int iVar2;
  uint loopIndex;
  int iVar4;
  int *srcCursor;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (0 < n) {
        do {
          iVar4 = *programs;
          programs = programs + 1;
          if (iVar4 != 0) {
            loopIndex = 0;
            srcCursor = (int *)(glContext + 0x5420);
            do {
              iVar2 = *srcCursor;
              srcCursor = srcCursor + 1;
              if (iVar4 == *(int *)(iVar2 + 4)) {
                _gleBindPipelineProgram(glContext,loopIndex,0);
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex < 2);
            ((int (*)())_gleDeleteHashNameAndObject)(glContext,*(int *)(glContext + 0x5148) + 0x4010,iVar4);
          }
          n = n + -1;
        } while (n != 0);
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _gleDeleteHashNameAndObject @ 0x30ef8 (136 bytes) */
int _gleDeleteHashNameAndObject(glContext, forwardedArg2, forwardedArg3)
  undefined4 glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = ((int (*)())_gleRemoveHashName)(forwardedArg2,forwardedArg3);
  uVar3 = 0;
  if (iVar2 != 0) {
    iVar2 = _gleRemoveHashObject(forwardedArg2,forwardedArg3);
    if ((iVar2 != 0) && (iVar1 = *(int *)(iVar2 + 8) + -1, *(int *)(iVar2 + 8) = iVar1, iVar1 == 0))
    {
      (**(code **)(iVar2 + 0xc))(glContext);
    }
    uVar3 = 1;
  }
  return uVar3;
}

/* _gleRemoveHashName @ 0x30f80 (228 bytes) */
int _gleRemoveHashName(nameTable, name)
  int nameTable;
  uint name;
{
  undefined4 savedNextLink;
  uint nameAfter;
  undefined4 *previousLink;
  undefined4 *allocatedBlock;
  uint rangeStart;
  uint rangeEnd;
  undefined4 *currentNode;
  undefined4 *nextNode;
  
  if (*(undefined4 **)(nameTable + 0x1000) != (undefined4 *)0x0) {
    nameAfter = name + 1;
    previousLink = (undefined4 *)(nameTable + 0x1000);
    currentNode = *(undefined4 **)(nameTable + 0x1000);
    do {
      rangeStart = currentNode[1];
      rangeEnd = rangeStart + currentNode[2];
      if (name < rangeStart) {
        return 0;
      }
      if (name < rangeEnd) {
        if (rangeStart < name) {
          currentNode[2] = name - rangeStart;
          if (nameAfter < rangeEnd) {
            allocatedBlock = (undefined4 *)_malloc(0xc);
            savedNextLink = *currentNode;
            allocatedBlock[1] = nameAfter;
            *allocatedBlock = savedNextLink;
            allocatedBlock[2] = (rangeEnd - name) + -1;
            *currentNode = allocatedBlock;
          }
        }
        else if (nameAfter < rangeEnd) {
          currentNode[1] = rangeStart + 1;
          currentNode[2] = (rangeEnd - rangeStart) + -1;
        }
        else {
          *previousLink = *currentNode;
          _free(currentNode);
        }
        return 1;
      }
      nextNode = (undefined4 *)*currentNode;
      previousLink = currentNode;
      currentNode = nextNode;
    } while (nextNode != (undefined4 *)0x0);
  }
  return 0;
}

/* _glePPUnlogParameters @ 0x31064 (248 bytes) */
void _glePPUnlogParameters(param_1, program, paramCount, paramEntries)
  int param_1;
  int program;
  int paramCount;
  int paramEntries;
{
  ushort slotPriority;
  uint slotIndex;
  uint bankIndex;
  int iVar4;
  int slotRecord;
  int sharedState;
  int loopIndex;
  uint paramWord2;
  int slotBitmapWord;
  
  loopIndex = 0;
  bankIndex = (uint)*(ushort *)(program + 0x4ba);
  sharedState = *(int *)(param_1 + 0x5148);
  iVar4 = bankIndex * 0xa30 + sharedState;
  *(int *)(iVar4 + 0x8a98) = *(int *)(iVar4 + 0x8a98) + 1;
  if (paramCount != 0) {
    do {
      paramWord2 = *(uint *)(loopIndex * 8 + paramEntries + 4);
      if ((*(uint *)(loopIndex * 8 + paramEntries) & 0x1f0000) != 0) {
        slotIndex = paramWord2 & 0xffff;
        iVar4 = (bankIndex * 0x518 + slotIndex) * 2 + sharedState;
        slotPriority = *(ushort *)(iVar4 + 0x8874);
        if (slotPriority == 1) {
          slotRecord = (bankIndex * 0x146 + slotIndex) * 8 + sharedState;
          slotBitmapWord = (bankIndex * 0x28c + (slotIndex >> 5)) * 4 + sharedState;
          *(undefined2 *)(iVar4 + 0x8874) = 0;
          *(undefined4 *)(slotRecord + 0x8074) = 0;
          *(undefined4 *)(slotRecord + 0x8078) = 0;
          *(uint *)(slotBitmapWord + 0x8a74) = *(uint *)(slotBitmapWord + 0x8a74) | 1 << (paramWord2 & 0x1f);
        }
        else if (1 < slotPriority) {
          *(ushort *)(iVar4 + 0x8874) = slotPriority - 1;
        }
      }
      loopIndex = loopIndex + 1;
      paramCount = paramCount + -1;
    } while (paramCount != 0);
  }
  return;
}

/* _gleDestroyEnableHashTable @ 0x3115c (104 bytes) */
void _gleDestroyEnableHashTable()
{
  int iVar1;
  int iVar2;
  int remaining;
  int *srcCursor;
  
  iVar1 = _gle_enable_hash_table;
  remaining = 0x3ff;
  srcCursor = (int *)(_gle_enable_hash_table + 8);
  do {
    iVar2 = *srcCursor;
    srcCursor = srcCursor + 4;
    if (iVar2 != 0) {
      ((void (*)())_gleFreeEnableHashObject)(iVar2);
    }
    remaining = remaining + -1;
  } while (-1 < remaining);
  _free(iVar1);
  _gle_enable_hash_table = 0;
  return;
}

/* _gleFreeEnableHashObject @ 0x311c4 (60 bytes) */
void _gleFreeEnableHashObject(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 8) != 0) {
    ((void (*)())_gleFreeEnableHashObject)(*(int *)(param_1 + 8));
  }
  _free(param_1);
  return;
}

/* _glVertex4f_Exec @ 0x31200 (32 bytes) */
void _glVertex4f_Exec(glContext)
  int glContext;
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*((int (*)(int))UNRECOVERED_JUMPTABLE))(glContext);
  return;
}

/* _glFrustum_Exec @ 0x31220 (660 bytes) */
void _glFrustum_Exec(int glContext,double left,double right,double bottom,double top,float zNear,double zFar,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float frustumB;
  float absExtent;
  float frustumA;
  float frustumC;
  float column2X;
  float column2Y;
  float column2Z;
  float column2W;
  undefined4 glErrorCode;
  float *currentMatrix;
  float twoNear;
  
  currentMatrix = *(float **)(glContext + 0x4fec);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    if ((!(zNear <= DOUBLE_00108d60)) && (!(zFar <= DOUBLE_00108d60))) {
      fVar1 = (float)(right - left);
      fVar2 = (float)(top - bottom);
      fVar3 = (float)(zNear - zFar);
      absExtent = fVar1;
      if (!(0.0 <= fVar1)) {
        absExtent = -fVar1;
      }
      if (!(absExtent < FLOAT_00108e80)) {
        absExtent = fVar2;
        if (!(FLOAT_00108e50 <= fVar2)) {
          absExtent = -fVar2;
        }
        if (!(absExtent < FLOAT_00108e80)) {
          absExtent = fVar3;
          if (!(FLOAT_00108e50 <= fVar3)) {
            absExtent = -fVar3;
          }
          if (!(absExtent < FLOAT_00108e80)) {
            column2X = currentMatrix[8];
            column2Y = currentMatrix[9];
            column2Z = currentMatrix[10];
            column2W = currentMatrix[0xb];
            frustumB = (float)((top + bottom) * (double)(1.0 / fVar2));
            frustumA = (float)((right + left) * (double)(1.0 / fVar1));
            frustumC = (float)((zFar + zNear) * (double)(1.0 / fVar3));
            twoNear = (double)(zNear + zNear);
            fVar1 = (float)((double)twoNear * (double)(1.0 / fVar1));
            currentMatrix[8] = (column2X * frustumC + (*currentMatrix * frustumA + currentMatrix[4] * frustumB)) - currentMatrix[0xc];
            fVar3 = (float)(zFar * (double)twoNear * (double)(1.0 / fVar3));
            fVar2 = (float)((double)twoNear * (double)(1.0 / fVar2));
            currentMatrix[9] = (column2Y * frustumC + (currentMatrix[1] * frustumA + currentMatrix[5] * frustumB)) - currentMatrix[0xd];
            currentMatrix[10] = (column2Z * frustumC + (currentMatrix[2] * frustumA + currentMatrix[6] * frustumB)) - currentMatrix[0xe];
            currentMatrix[0xb] = (column2W * frustumC + (currentMatrix[3] * frustumA + currentMatrix[7] * frustumB)) - currentMatrix[0xf]
            ;
            currentMatrix[3] = currentMatrix[3] * fVar1;
            currentMatrix[4] = currentMatrix[4] * fVar2;
            *currentMatrix = *currentMatrix * fVar1;
            currentMatrix[5] = currentMatrix[5] * fVar2;
            currentMatrix[1] = currentMatrix[1] * fVar1;
            currentMatrix[6] = currentMatrix[6] * fVar2;
            currentMatrix[2] = currentMatrix[2] * fVar1;
            currentMatrix[0xf] = column2W * fVar3;
            currentMatrix[0xc] = column2X * fVar3;
            currentMatrix[0xd] = column2Y * fVar3;
            currentMatrix[0xe] = column2Z * fVar3;
            currentMatrix[7] = currentMatrix[7] * fVar2;
            *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | *(uint *)(glContext + 0x50a8);
            *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | *(uint *)(glContext + 0x50a8);
            return;
          }
        }
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glShadeModel_Exec @ 0x314b4 (160 bytes) */
void _glShadeModel_Exec(glContext, mode)
  int glContext;
  int mode;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (mode - 0x1d00U < 2) {
      *(int *)(glContext + 0x34f4) = mode;
      _gleUpdatePrimitiveData(glContext);
      puVar2 = PTR__gleSetEyeInterpFunc_0011203c;
      puVar1 = PTR__gleSetClipInterpFunc_00112038;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x8000000;
      *(undefined **)(glContext + 0x49c8) = puVar2;
      *(undefined **)(glContext + 0x49cc) = puVar1;
      return;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glClearDepth_Exec @ 0x31554 (140 bytes) */
void _glClearDepth_Exec(int glContext,double depth)
{
  uint uVar1;
  bool bVar2;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
      return;
    }
    return;
  }
  bVar2 = depth < DOUBLE_00108d60;
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x10;
  if (bVar2) {
    uVar1 = 0;
  }
  else {
    if (!(DOUBLE_00108d68 < depth)) goto LAB_000315d4;
    uVar1 = 0x3ff00000;
  }
  depth = GH_U2D((unsigned long long)uVar1 << 0x20);
LAB_000315d4:
  *(double *)(glContext + 0x30e8) = depth;
  return;
}

/* _glDepthFunc_Exec @ 0x315e0 (88 bytes) */
void _glDepthFunc_Exec(glContext, func)
  int glContext;
  int func;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((7 < func - 0x200U) && (*(int *)(glContext + 0x7574) == 0)) {
      *(undefined4 *)(glContext + 0x7574) = 0x500;
    }
    *(short *)(glContext + 0x3124) = (short)func;
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _gleSetEnable_LINE_SMOOTH @ 0x31638 (32 bytes) */
void _gleSetEnable_LINE_SMOOTH(param_1, unusedArg2, param_3)
  int param_1;
  undefined4 unusedArg2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x318d) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x318d) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x4000;
  return;
}

/* _glLightfv_Exec @ 0x31658 (1460 bytes) */
void _glLightfv_Exec(int glContext,int light,undefined4 pname,float *params,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  byte dirtyBitIndex;
  float positionY;
  float positionZ;
  float positionW;
  float positionX;
  float spotCutoffValue;
  float spotExponentValue;
  undefined4 glErrorCode;
  int lightRecord;
  int dirtyWord348Ptr;
  int glContextWord5424;
  uint dirtyBitIndex2;
  int dirtyWord324Ptr;
  uint lightIndex;
  double cosValue;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00031c00;
  }
  lightIndex = light - 0x4000;
  if (7 < lightIndex) {
switchD_000316d0_default:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_00031c00;
  }
  lightRecord = glContext + lightIndex * 0x80;
  switch(pname) {
  case 0x1200:
    *(float *)(lightRecord + 0x2820) = *params;
    *(float *)(lightRecord + 0x2824) = params[1];
    *(float *)(lightRecord + 0x2828) = params[2];
    *(float *)(lightRecord + 0x282c) = params[3];
    *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 600);
    }
    else {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x28c);
    }
    dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
    dirtyBitIndex2 = (uint)*(byte *)(lightIndex * 7 + glContextWord5424 + 600);
    break;
  case 0x1201:
    *(float *)(lightRecord + 0x2830) = *params;
    *(float *)(lightRecord + 0x2834) = params[1];
    *(float *)(lightRecord + 0x2838) = params[2];
    *(float *)(lightRecord + 0x283c) = params[3];
    *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 0x259);
    }
    else {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x28d);
    }
    dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
    dirtyBitIndex2 = (uint)*(byte *)(lightIndex * 7 + glContextWord5424 + 0x259);
    break;
  case 0x1202:
    *(float *)(lightRecord + 0x2840) = *params;
    *(float *)(lightRecord + 0x2844) = params[1];
    *(float *)(lightRecord + 0x2848) = params[2];
    *(float *)(lightRecord + 0x284c) = params[3];
    *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) | 0x1e;
    *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) =
         *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) | 0x1e;
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 0x25a);
    }
    else {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x28e);
    }
    dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
    dirtyBitIndex2 = (uint)*(byte *)(lightIndex * 7 + glContextWord5424 + 0x25a);
    break;
  case 0x1203:
    positionX = *params;
    *(float *)(lightRecord + 0x2850) = positionX;
    positionY = params[1];
    *(float *)(lightRecord + 0x2854) = positionY;
    positionZ = params[2];
    *(float *)(lightRecord + 0x2858) = positionZ;
    positionW = params[3];
    *(float *)(lightRecord + 0x285c) = positionW;
    *(float *)(lightRecord + 0x2850) =
         positionW * *(float *)(glContext + 0x1cf0) +
         (positionZ * *(float *)(glContext + 0x1ce0) +
         (positionX * *(float *)(glContext + 0x1cc0) + positionY * *(float *)(glContext + 0x1cd0)));
    *(float *)(lightRecord + 0x2854) =
         positionW * *(float *)(glContext + 0x1cf4) +
         (positionZ * *(float *)(glContext + 0x1ce4) +
         (positionX * *(float *)(glContext + 0x1cc4) + positionY * *(float *)(glContext + 0x1cd4)));
    *(float *)(lightRecord + 0x2858) =
         positionW * *(float *)(glContext + 0x1cf8) +
         (positionZ * *(float *)(glContext + 0x1ce8) +
         (positionX * *(float *)(0x1cc8 + glContext) + positionY * *(float *)(glContext + 0x1cd8)));
    *(float *)(lightRecord + 0x285c) =
         positionW * *(float *)(glContext + 0x1cfc) +
         (positionZ * *(float *)(glContext + 0x1cec) +
         (positionX * *(float *)(glContext + 0x1ccc) + positionY * *(float *)(glContext + 0x1cdc)));
    ((double (*)())_gleUpdateLightPosition)(glContext,lightIndex,forwardedFloatArg1);
    goto LAB_00031c08;
  case 0x1204:
    *(float *)(lightRecord + 0x2860) = *params;
    *(float *)(lightRecord + 0x2864) = params[1];
    *(float *)(lightRecord + 0x2868) = params[2];
    ((void (*)())_gleTransformLightDirection)(glContext,lightIndex,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
               forwardedFloatArg8,incomingStack_ffffffa8,incomingStack_ffffffb0);
    goto LAB_00031c08;
  case 0x1205:
    spotExponentValue = *params;
    if ((spotExponentValue < FLOAT_00108e50) ||
       ((float)((double)CONCAT44(0x43300000,
                                 *(uint *)(*(int *)(glContext + 0x468c) + 0xa4) ^ 0x80000000) -
               DOUBLE_00108d58) < spotExponentValue)) goto LAB_00031bc8;
    *(float *)(lightRecord + 0x287c) = spotExponentValue;
    _gleUpdateLightExponents(glContext,lightIndex);
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 0x25d);
    }
    else {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x291);
    }
    dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
    dirtyBitIndex2 = (uint)*(byte *)(lightIndex * 7 + glContextWord5424 + 0x25d);
    break;
  case 0x1206:
    spotCutoffValue = *params;
    if ((FLOAT_00108e50 <= spotCutoffValue) && (spotCutoffValue <= FLOAT_00108e88)) {
      *(float *)(lightRecord + 0x2890) = spotCutoffValue;
      cosValue = _cos((double)(*params * FLOAT_00108e84));
      *(float *)(lightRecord + 0x286c) = (float)cosValue;
    }
    else {
      if (spotCutoffValue != FLOAT_00108e8c) goto LAB_00031bc8;
      *(undefined4 *)(lightRecord + 0x2890) = 0;
      *(undefined4 *)(lightRecord + 0x286c) = 0xbf800000;
    }
    _gleUpdateLightExponents(glContext,lightIndex);
    if (*(int *)(glContext + 0x5434) == 0) {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(glContext + 0x5420) + 0x25c);
    }
    else {
      dirtyBitIndex = *(byte *)(lightIndex * 7 + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x290);
    }
    dirtyWord324Ptr = (dirtyBitIndex >> 3 & 0x1c) + glContext;
    glContextWord5424 = *(int *)(glContext + 0x5424);
    *(uint *)(dirtyWord324Ptr + 0x324) = *(uint *)(dirtyWord324Ptr + 0x324) | 1 << (dirtyBitIndex & 0x1f);
    dirtyBitIndex2 = (uint)*(byte *)(lightIndex * 7 + glContextWord5424 + 0x25c);
    break;
  case 0x1207:
    if (!(*params < FLOAT_00108e50)) {
      *(float *)(lightRecord + 0x2870) = *params;
LAB_00031be0:
      _gleUpdateLightAttenuation(glContext,lightIndex);
      goto LAB_00031c08;
    }
    goto LAB_00031bc8;
  case 0x1208:
    if (!(*params < FLOAT_00108e50)) {
      *(float *)(lightRecord + 0x2874) = *params;
      goto LAB_00031be0;
    }
    goto LAB_00031bc8;
  case 0x1209:
    if (!(*params < FLOAT_00108e50)) {
      *(float *)(lightRecord + 0x2878) = *params;
      goto LAB_00031be0;
    }
LAB_00031bc8:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
LAB_00031c00:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  default:
    goto switchD_000316d0_default;
  }
  dirtyWord348Ptr = (dirtyBitIndex2 >> 3 & 0x1c) + glContext;
  *(uint *)(dirtyWord348Ptr + 0x348) = *(uint *)(dirtyWord348Ptr + 0x348) | 1 << (dirtyBitIndex2 & 0x1f);
LAB_00031c08:
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 4 << (lightIndex * 2 & 0x3e);
  return;
}

/* _gleSetEnable_LIGHT @ 0x31c34 (144 bytes) */
void _gleSetEnable_LIGHT(glContext, param_2, param_3)
  int glContext;
  int param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 - 0x4000;
  uVar1 = *(uint *)(glContext + 0x30a0) &
          (-2 << (uVar2 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar2 & 0x1f)) | param_3 << (uVar2 & 0x3f);
  if (*(uint *)(glContext + 0x30a0) != uVar1) {
    *(uint *)(glContext + 0x30a0) = uVar1;
    *(undefined1 *)(*(int *)(glContext + 0x4dd0) + 0x234) = 0x1f;
    *(undefined1 *)(*(int *)(glContext + 0x4dd4) + 0x234) = 0x1f;
    _gleUpdateLightFast(glContext,uVar2);
    _gleUpdateLightModelFunc(glContext);
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 8 << (uVar2 * 2 & 0x3e);
  }
  return;
}

/* _gleSetEnable_LIGHTING @ 0x31cc4 (220 bytes) */
void _gleSetEnable_LIGHTING(glContext, unusedArg2, param_3)
  int glContext;
  undefined4 unusedArg2;
  uint param_3;
{
  undefined *puVar1;
  undefined1 uVar2;
  
  if (*(byte *)(glContext + 0x30aa) != param_3) {
    *(char *)(glContext + 0x30aa) = (char)param_3;
    if (*(char *)(glContext + 0x4664) == '\0') {
      if (param_3 == 0) {
        uVar2 = *(undefined1 *)(glContext + 0x4fea);
      }
      else {
        uVar2 = *(short *)(glContext + 0x30a8) == -0x7e06;
      }
      *(undefined1 *)(glContext + 0x316b) = uVar2;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
    }
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 2;
    _gleUpdateInverseNeeds(glContext);
    _gleSelectVertexSubmitFunc(glContext);
    _gleSelectVertexAddMaterialFunc(glContext);
    puVar1 = PTR__gleSetClipInterpFunc_00112038;
    *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
    *(undefined **)(glContext + 0x49cc) = puVar1;
    _gleUpdatePolyMode(glContext);
    return;
  }
  return;
}

/* _gleSetEnable_RESCALE_NORMAL_EXT @ 0x31da0 (44 bytes) */
void _gleSetEnable_RESCALE_NORMAL_EXT(glContext, unusedArg2, param_3)
  int glContext;
  undefined4 unusedArg2;
  uint param_3;
{
  if (*(byte *)(glContext + 0x280e) == param_3) {
    return;
  }
  *(char *)(glContext + 0x280e) = (char)param_3;
  *(uint *)(glContext + 0x50b0) = *(uint *)(glContext + 0x50b0) | 0x10;
  *(uint *)(glContext + 0x318) = *(uint *)(glContext + 0x318) | 0x80000000;
  return;
}

/* _glClear_Exec @ 0x31dcc (704 bytes) */
void _glClear_Exec(int glContext,uint mask,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  bool noStateChangePending;
  char rendererInfoByte79;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixChangeBits;
  uint dispatchFlags;
  uint changeWord3;
  int *changeWordCursor;
  double extraout_f1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00032028;
  }
  if ((mask & 0xffffb8ff) != 0) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_00032028;
  }
  if (*(int *)(glContext + 0x4e1c) != 0x1c00) {
    return;
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_00032054;
  framebufferObject = *(int *)(glContext + 0x744c);
  changeWordCursor = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00031f2c:
    changeWord3 = *(uint *)(glContext + 0x31c);
  }
  else {
    loopIndex = 0;
    srcCursor = (int *)(glContext + 0x324);
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      if (iVar5 != 0) {
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 9);
    changeWord3 = *(uint *)(glContext + 0x31c);
    if ((changeWord3 & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        ((double (*)())_gleUpdateLightRGBASums)(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        ((double (*)())_gleUpdateLightRGBASums)(glContext,glContext + 0x2e60,1);
      }
      goto LAB_00031f2c;
    }
  }
  bVar1 = rendererInfoByte79 == '\0';
  if (bVar1) {
    changeWord3 = changeWord3 & 0x17000000;
  }
  else {
    changeWord3 = changeWord3 & 0x17ffffff;
  }
  if (bVar1) {
    noStateChangePending = ((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) && changeWord3 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    noStateChangePending = (((*changeWordCursor == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && changeWord3 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!noStateChangePending) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      dispatchFlags = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,changeWordCursor);
      if ((((dispatchFlags & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((dispatchFlags & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((dispatchFlags & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((dispatchFlags & 4) == 0) {
          dispatchFlags = dispatchFlags & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,dispatchFlags);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_00032028:
          *(undefined4 *)(glContext + 0x7574) = glErrorCode;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(glContext);
    }
    remaining = 0x13;
    do {
      *changeWordCursor = 0;
      changeWordCursor = changeWordCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_00032054:
                    
                    
  (**(code **)(glContext + 0x469c))(*(undefined4 *)(glContext + 0x4688),mask);
  return;
}

/* _gliDispatchNoop @ 0x3208c (8 bytes) */
int _gliDispatchNoop()
{
  return 0;
}

/* _glTranslate_Exec @ 0x32098 (448 bytes) */
void _glTranslate_Exec(int glContext,float x,float y,float z)
{
  float *currentMatrix;
  float *currentInverseMatrix;
  uint glContextWord50b0;
  uint uVar3;
  float dVar4;
  float dVar5;
  float dVar6;
  float dVar7;
  
  currentMatrix = *(float **)(glContext + 0x4fec);
  uVar3 = *(uint *)(glContext + 0x50a8);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    currentMatrix[0xc] = currentMatrix[0xc] +
                  (currentMatrix[8] * z + (*currentMatrix * x + (currentMatrix[4] * y)));
    currentMatrix[0xd] = currentMatrix[0xd] +
                  (currentMatrix[9] * z + (currentMatrix[1] * x + (currentMatrix[5] * y)));
    currentMatrix[0xe] = currentMatrix[0xe] +
                  (currentMatrix[10] * z + (currentMatrix[2] * x + (currentMatrix[6] * y)));
    currentMatrix[0xf] = currentMatrix[0xf] +
                  (currentMatrix[0xb] * z + (currentMatrix[3] * x + (currentMatrix[7] * y)));
    glContextWord50b0 = *(uint *)(glContext + 0x50b0);
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | uVar3;
    if ((uVar3 & ~glContextWord50b0 & *(uint *)(glContext + 0x505c) & 0xfffffc) != 0) {
      currentInverseMatrix = *(float **)(glContext + 0x4ff0);
      uVar3 = uVar3 & 0xff000003;
      dVar4 = (double)currentInverseMatrix[0xc];
      dVar5 = (double)currentInverseMatrix[0xd];
      dVar6 = (double)currentInverseMatrix[0xe];
      dVar7 = (double)currentInverseMatrix[0xf];
      *currentInverseMatrix = -(x * dVar4 - *currentInverseMatrix);
      currentInverseMatrix[4] = -(y * dVar4 - currentInverseMatrix[4]);
      currentInverseMatrix[8] = -(z * dVar4 - currentInverseMatrix[8]);
      currentInverseMatrix[1] = -(x * dVar5 - currentInverseMatrix[1]);
      currentInverseMatrix[5] = -(y * dVar5 - currentInverseMatrix[5]);
      currentInverseMatrix[0xb] = -(z * dVar7 - currentInverseMatrix[0xb]);
      currentInverseMatrix[9] = -(z * dVar5 - currentInverseMatrix[9]);
      currentInverseMatrix[2] = -(x * dVar6 - currentInverseMatrix[2]);
      currentInverseMatrix[6] = -(y * dVar6 - currentInverseMatrix[6]);
      currentInverseMatrix[10] = -(z * dVar6 - currentInverseMatrix[10]);
      currentInverseMatrix[3] = -(x * dVar7 - currentInverseMatrix[3]);
      currentInverseMatrix[7] = -(y * dVar7 - currentInverseMatrix[7]);
      glContextWord50b0 = *(uint *)(glContext + 0x50b0);
    }
    *(uint *)(glContext + 0x50b0) = glContextWord50b0 | uVar3;
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glPolygonMode_Exec @ 0x32258 (216 bytes) */
void _glPolygonMode_Exec(glContext, face, mode)
  int glContext;
  uint face;
  int mode;
{
  undefined4 glErrorCode;
  undefined2 uVar2;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_000322a8:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  if (2 < mode - 0x1b00U) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_000322a8;
  }
  uVar2 = (undefined2)mode;
  if (face == 0x405) {
    *(undefined2 *)(glContext + 0x34d2) = uVar2;
    goto LAB_000322fc;
  }
  if (face < 0x406) {
    if (face == 0x404) {
LAB_000322d8:
      *(undefined2 *)(glContext + 0x34d0) = uVar2;
      goto LAB_000322fc;
    }
  }
  else if (face == 0x408) {
    *(undefined2 *)(glContext + 0x34d2) = uVar2;
    goto LAB_000322d8;
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x500;
  }
LAB_000322fc:
  _gleUpdatePolyMode(glContext);
  _gleSelectVertexSubmitFunc(glContext);
  return;
}

/* _glRotatef_Exec @ 0x32330 (404 bytes) */
void _glRotatef_Exec(int glContext,double angle,double x,double y,double z)
{
  float fVar1;
  undefined4 in_LR;
  double sinValue;
  double cosValue;
  double fparam_3_00;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  fparam_3_00 = (double)*(float *)(glContext + 0x20);
  if ((y == fparam_3_00) && (z == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (x < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    sinValue = _sin((double)(float)(angle * (double)fVar1));
    cosValue = _cos((double)(float)(angle * (double)fVar1));
    ((void (*)())_glRotateX_Exec)(glContext,(double)(float)sinValue,(double)(float)cosValue,fparam_3_00,z,incomingFpr5,
                    incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((x == fparam_3_00) && (z == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (y < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    sinValue = _sin((double)(float)(angle * (double)fVar1));
    cosValue = _cos((double)(float)(angle * (double)fVar1));
    ((void (*)())_glRotateY_Exec)(glContext,(double)(float)sinValue,(double)(float)cosValue,fparam_3_00,z,incomingFpr5,
                    incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((x == fparam_3_00) && (y == fparam_3_00)) {
    fVar1 = FLOAT_00108e84;
    if (z < fparam_3_00) {
      fVar1 = FLOAT_00108eb0;
    }
    sinValue = _sin((double)(float)(angle * (double)fVar1));
    cosValue = _cos((double)(float)(angle * (double)fVar1));
    ((void (*)())_glRotateZ_Exec)(glContext,(double)(float)sinValue,(double)(float)cosValue,fparam_3_00,z,incomingFpr5,
                    incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  ((void (*)())_glRotateXYZ_Exec)(glContext,angle,x,y,z);
  return;
}

/* _glRotateZ_Exec @ 0x324c4 (372 bytes) */
void _glRotateZ_Exec(int glContext,float sinAngle,float cosAngle,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float savedElement4;
  float savedElement6;
  float savedElement1;
  float savedElement3;
  float *currentMatrix;
  float *currentInverseMatrix;
  uint glContextWord50b0;
  uint currentMatrixDirtyBits;
  
  currentMatrixDirtyBits = *(uint *)(glContext + 0x50a8);
  currentMatrix = *(float **)(glContext + 0x4fec);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    savedElement4 = currentMatrix[4];
    savedElement1 = currentMatrix[1];
    currentMatrix[4] = (savedElement4 * cosAngle - (*currentMatrix * sinAngle));
    *currentMatrix = (*currentMatrix * cosAngle + (savedElement4 * sinAngle));
    savedElement6 = currentMatrix[6];
    currentMatrix[1] = (savedElement1 * cosAngle + (currentMatrix[5] * sinAngle));
    currentMatrix[5] = (currentMatrix[5] * cosAngle - (savedElement1 * sinAngle));
    savedElement3 = currentMatrix[3];
    currentMatrix[6] = (savedElement6 * cosAngle - (currentMatrix[2] * sinAngle));
    currentMatrix[2] = (currentMatrix[2] * cosAngle + (savedElement6 * sinAngle));
    currentMatrix[3] = (savedElement3 * cosAngle + (currentMatrix[7] * sinAngle));
    currentMatrix[7] = (currentMatrix[7] * cosAngle - (savedElement3 * sinAngle));
    glContextWord50b0 = *(uint *)(glContext + 0x50b0);
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | currentMatrixDirtyBits;
    if ((currentMatrixDirtyBits & ~glContextWord50b0 & *(uint *)(glContext + 0x505c) & 0xfffffc) != 0) {
      currentInverseMatrix = *(float **)(glContext + 0x4ff0);
      currentMatrixDirtyBits = currentMatrixDirtyBits & 0xff000003;
      savedElement4 = currentInverseMatrix[4];
      savedElement1 = currentInverseMatrix[1];
      currentInverseMatrix[4] = (savedElement4 * cosAngle - (*currentInverseMatrix * sinAngle));
      *currentInverseMatrix = (*currentInverseMatrix * cosAngle + (savedElement4 * sinAngle));
      savedElement6 = currentInverseMatrix[6];
      currentInverseMatrix[1] = (savedElement1 * cosAngle + (currentInverseMatrix[5] * sinAngle));
      currentInverseMatrix[5] = (currentInverseMatrix[5] * cosAngle - (savedElement1 * sinAngle));
      savedElement3 = currentInverseMatrix[3];
      currentInverseMatrix[6] = (savedElement6 * cosAngle - (currentInverseMatrix[2] * sinAngle));
      currentInverseMatrix[2] = (currentInverseMatrix[2] * cosAngle + (savedElement6 * sinAngle));
      currentInverseMatrix[3] = (savedElement3 * cosAngle + (currentInverseMatrix[7] * sinAngle));
      currentInverseMatrix[7] = (currentInverseMatrix[7] * cosAngle - (savedElement3 * sinAngle));
      glContextWord50b0 = *(uint *)(glContext + 0x50b0);
    }
    *(uint *)(glContext + 0x50b0) = glContextWord50b0 | currentMatrixDirtyBits;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glRotateY_Exec @ 0x32638 (372 bytes) */
void _glRotateY_Exec(int glContext,float fparam_1,float fparam_2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float savedElement8;
  float savedElement10;
  float savedElement1;
  float savedElement3;
  float *currentMatrix;
  float *currentInverseMatrix;
  uint glContextWord50b0;
  uint matrixDirtyBits;
  
  matrixDirtyBits = *(uint *)(glContext + 0x50a8);
  currentMatrix = *(float **)(glContext + 0x4fec);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    savedElement8 = currentMatrix[8];
    savedElement1 = currentMatrix[1];
    currentMatrix[8] = (savedElement8 * fparam_2 + (*currentMatrix * fparam_1));
    *currentMatrix = (*currentMatrix * fparam_2 - (savedElement8 * fparam_1));
    savedElement10 = currentMatrix[10];
    currentMatrix[1] = (savedElement1 * fparam_2 - (currentMatrix[9] * fparam_1));
    currentMatrix[9] = (currentMatrix[9] * fparam_2 + (savedElement1 * fparam_1));
    savedElement3 = currentMatrix[3];
    currentMatrix[10] = (savedElement10 * fparam_2 + (currentMatrix[2] * fparam_1));
    currentMatrix[2] = (currentMatrix[2] * fparam_2 - (savedElement10 * fparam_1));
    currentMatrix[3] = (savedElement3 * fparam_2 - (currentMatrix[0xb] * fparam_1));
    currentMatrix[0xb] = (currentMatrix[0xb] * fparam_2 + (savedElement3 * fparam_1));
    glContextWord50b0 = *(uint *)(glContext + 0x50b0);
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | matrixDirtyBits;
    if ((matrixDirtyBits & ~glContextWord50b0 & *(uint *)(glContext + 0x505c) & 0xfffffc) != 0) {
      currentInverseMatrix = *(float **)(glContext + 0x4ff0);
      matrixDirtyBits = matrixDirtyBits & 0xff000003;
      savedElement8 = currentInverseMatrix[8];
      savedElement1 = currentInverseMatrix[1];
      currentInverseMatrix[8] = (savedElement8 * fparam_2 + (*currentInverseMatrix * fparam_1));
      *currentInverseMatrix = (*currentInverseMatrix * fparam_2 - (savedElement8 * fparam_1));
      savedElement10 = currentInverseMatrix[10];
      currentInverseMatrix[1] = (savedElement1 * fparam_2 - (currentInverseMatrix[9] * fparam_1));
      currentInverseMatrix[9] = (currentInverseMatrix[9] * fparam_2 + (savedElement1 * fparam_1));
      savedElement3 = currentInverseMatrix[3];
      currentInverseMatrix[10] = (savedElement10 * fparam_2 + (currentInverseMatrix[2] * fparam_1))
      ;
      currentInverseMatrix[2] = (currentInverseMatrix[2] * fparam_2 - (savedElement10 * fparam_1));
      currentInverseMatrix[3] = (savedElement3 * fparam_2 - (currentInverseMatrix[0xb] * fparam_1));
      currentInverseMatrix[0xb] = (currentInverseMatrix[0xb] * fparam_2 + (savedElement3 * fparam_1));
      glContextWord50b0 = *(uint *)(glContext + 0x50b0);
    }
    *(uint *)(glContext + 0x50b0) = glContextWord50b0 | matrixDirtyBits;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glScale_Exec @ 0x327b0 (684 bytes) */
void _glScale_Exec(int glContext,float x,float y,float z)
{
  float reciprocalLimit;
  float reciprocalScale;
  float scaleMagnitude;
  float *currentMatrix;
  float *currentInverseMatrix;
  uint glContextWord50b0;
  uint matrixDirtyBits;
  float zeroForCompare;
  float zeroValue;
  float oneValue;
  float minScaleMagnitude;
  
  currentMatrix = *(float **)(glContext + 0x4fec);
  matrixDirtyBits = *(uint *)(glContext + 0x50a8);
  if ((-1 < *(short *)(glContext + 0x4a10)) || (0x17 < *(int *)(glContext + 0x4ff4))) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  *currentMatrix = (*currentMatrix * x);
  currentMatrix[4] = (currentMatrix[4] * y);
  currentMatrix[8] = (currentMatrix[8] * z);
  currentMatrix[1] = (currentMatrix[1] * x);
  currentMatrix[0xb] = (currentMatrix[0xb] * z);
  currentMatrix[5] = (currentMatrix[5] * y);
  currentMatrix[9] = (currentMatrix[9] * z);
  currentMatrix[2] = (currentMatrix[2] * x);
  currentMatrix[6] = (currentMatrix[6] * y);
  currentMatrix[10] = (currentMatrix[10] * z);
  currentMatrix[3] = (currentMatrix[3] * x);
  currentMatrix[7] = (currentMatrix[7] * y);
  *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | matrixDirtyBits;
  reciprocalLimit = FLOAT_00108eb4;
  if (*(char *)(glContext + 0x280e) == '\0') {
    glContextWord50b0 = *(uint *)(glContext + 0x50b0);
    if ((matrixDirtyBits & ~glContextWord50b0 & *(uint *)(glContext + 0x505c) & 0xfffffc) == 0) goto LAB_00032a4c;
    zeroValue = (double)FLOAT_00108e50;
    minScaleMagnitude = (double)FLOAT_00108e80;
    oneValue = (double)FLOAT_00108e54;
    currentInverseMatrix = *(float **)(glContext + 0x4ff0);
    scaleMagnitude = x;
    if (!((double)zeroValue <= x)) {
      scaleMagnitude = -x;
    }
    if ((double)minScaleMagnitude <= (double)scaleMagnitude) {
      reciprocalScale = (oneValue / x);
    }
    else {
      reciprocalScale = FLOAT_00108eb4;
      if (!((double)zeroValue <= x)) {
        reciprocalScale = -FLOAT_00108eb4;
      }
    }
    zeroForCompare = (double)FLOAT_00108e50;
    *currentInverseMatrix = *currentInverseMatrix * reciprocalScale;
    currentInverseMatrix[2] = currentInverseMatrix[2] * reciprocalScale;
    currentInverseMatrix[3] = currentInverseMatrix[3] * reciprocalScale;
    currentInverseMatrix[1] = currentInverseMatrix[1] * reciprocalScale;
    scaleMagnitude = y;
    if (!((double)zeroForCompare <= y)) {
      scaleMagnitude = -y;
    }
    if ((double)minScaleMagnitude <= (double)scaleMagnitude) {
      reciprocalScale = (oneValue / y);
    }
    else {
      reciprocalScale = reciprocalLimit;
      if (!((double)zeroValue <= y)) {
        reciprocalScale = -reciprocalLimit;
      }
    }
    zeroForCompare = (double)FLOAT_00108e50;
    currentInverseMatrix[4] = currentInverseMatrix[4] * reciprocalScale;
    currentInverseMatrix[6] = currentInverseMatrix[6] * reciprocalScale;
    currentInverseMatrix[7] = currentInverseMatrix[7] * reciprocalScale;
    currentInverseMatrix[5] = currentInverseMatrix[5] * reciprocalScale;
    scaleMagnitude = z;
    if (!((double)zeroForCompare <= z)) {
      scaleMagnitude = -z;
    }
    if ((double)minScaleMagnitude <= (double)scaleMagnitude) {
      reciprocalLimit = (oneValue / z);
    }
    else if (!((double)zeroValue <= z)) {
      reciprocalLimit = -reciprocalLimit;
    }
    matrixDirtyBits = matrixDirtyBits & 0xff000003;
    currentInverseMatrix[8] = currentInverseMatrix[8] * reciprocalLimit;
    currentInverseMatrix[9] = currentInverseMatrix[9] * reciprocalLimit;
    currentInverseMatrix[10] = currentInverseMatrix[10] * reciprocalLimit;
    currentInverseMatrix[0xb] = currentInverseMatrix[0xb] * reciprocalLimit;
  }
  glContextWord50b0 = *(uint *)(glContext + 0x50b0);
LAB_00032a4c:
  *(uint *)(glContext + 0x50b0) = glContextWord50b0 | matrixDirtyBits;
  return;
}

/* _glMaterialfv_Exec @ 0x32a5c (1184 bytes) */
void _glMaterialfv_Exec(int glContext,uint face,undefined *pname,float *params,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  float colorIndexSpecular;
  float colorIndexAmbient;
  float colorIndexDiffuse;
  int remaining;
  undefined4 glErrorCode;
  uint firstFaceSlot;
  int materialSlot;
  uint lastFaceSlot;
  double shininess;
  float colorRed;
  float colorGreen;
  float colorBlue;
  float colorAlpha;
  undefined4 intToDoubleHigh;
  uint maxShininessBiased;
  
  if (((*(char *)(glContext + 0x7580) != '\0') && (-1 < *(short *)(glContext + 0x4a10))) &&
     (*(char *)(glContext + 0x4664) == '\0')) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  }
  if (pname == (undefined *)0x1600) {
    colorAlpha = params[3];
    colorRed = *params;
    colorGreen = params[1];
    colorBlue = params[2];
    if (face == 0x405) {
      _gleLightMaterialRGBAChange_B_E(glContext,&colorRed);
      goto LAB_00032eb8;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        _gleLightMaterialRGBAChange_F_E(glContext,&colorRed);
        goto LAB_00032eb8;
      }
    }
    else if (face == 0x408) {
      _gleLightMaterialRGBAChange_FB_E(glContext,&colorRed);
      goto LAB_00032eb8;
    }
  }
  else if (pname < (undefined *)0x1601) {
    if (pname == ((unsigned char *)0x00001201)) {
      colorAlpha = params[3];
      colorRed = *params;
      colorGreen = params[1];
      colorBlue = params[2];
      if (face == 0x405) {
        _gleLightMaterialRGBAChange_B_D(glContext,&colorRed);
        goto LAB_00032eb8;
      }
      if (face < 0x406) {
        if (face == 0x404) {
          _gleLightMaterialRGBAChange_F_D(glContext,&colorRed);
          goto LAB_00032eb8;
        }
      }
      else if (face == 0x408) {
        _gleLightMaterialRGBAChange_FB_D(glContext,&colorRed);
        goto LAB_00032eb8;
      }
    }
    else if (((unsigned char *)0x00001201) < pname) {
      if (pname == ((unsigned char *)0x00001202)) {
        colorAlpha = params[3];
        colorRed = *params;
        colorGreen = params[1];
        colorBlue = params[2];
        if (face == 0x405) {
          _gleLightMaterialRGBAChange_B_S(glContext,&colorRed);
          goto LAB_00032eb8;
        }
        if (face < 0x406) {
          if (face == 0x404) {
            _gleLightMaterialRGBAChange_F_S(glContext,&colorRed);
            goto LAB_00032eb8;
          }
        }
        else if (face == 0x408) {
          _gleLightMaterialRGBAChange_FB_S(glContext,&colorRed);
          goto LAB_00032eb8;
        }
      }
    }
    else if (pname == ((unsigned char *)0x00001200)) {
      colorAlpha = params[3];
      colorRed = *params;
      colorGreen = params[1];
      colorBlue = params[2];
      if (face == 0x405) {
        _gleLightMaterialRGBAChange_B_A(glContext,&colorRed);
        goto LAB_00032eb8;
      }
      if (face < 0x406) {
        if (face == 0x404) {
          _gleLightMaterialRGBAChange_F_A(glContext,&colorRed);
          goto LAB_00032eb8;
        }
      }
      else if (face == 0x408) {
        _gleLightMaterialRGBAChange_FB_A(glContext,&colorRed);
        goto LAB_00032eb8;
      }
    }
  }
  else if (pname == (undefined *)0x1602) {
    colorAlpha = params[3];
    colorRed = *params;
    colorGreen = params[1];
    colorBlue = params[2];
    if (face == 0x405) {
      _gleLightMaterialRGBAChange_B_AD(glContext,&colorRed);
      goto LAB_00032eb8;
    }
    if (face < 0x406) {
      if (face == 0x404) {
        _gleLightMaterialRGBAChange_F_AD(glContext,&colorRed);
        goto LAB_00032eb8;
      }
    }
    else if (face == 0x408) {
      _gleLightMaterialRGBAChange_FB_AD(glContext,&colorRed);
      goto LAB_00032eb8;
    }
  }
  else {
    if (pname < (undefined *)0x1602) {
      shininess = (double)*params;
      if (!(shininess < (double)FLOAT_00108e50)) {
        intToDoubleHigh = 0x43300000;
        maxShininessBiased = *(uint *)(*(int *)(glContext + 0x468c) + 0xa0) ^ 0x80000000;
        if (!((double)(float)((double)CONCAT44(0x43300000,maxShininessBiased) - DOUBLE_00108d58) <
             shininess)) {
          if (face == 0x405) {
            ((void (*)())_gleLightMaterialShineChange_B)(glContext,shininess);
            goto LAB_00032eb8;
          }
          if (face < 0x406) {
            if (face == 0x404) {
              ((void (*)())_gleLightMaterialShineChange_F)(glContext,shininess);
              goto LAB_00032eb8;
            }
          }
          else if (face == 0x408) {
            ((void (*)())_gleLightMaterialShineChange_FB)(glContext,shininess);
            goto LAB_00032eb8;
          }
          goto LAB_00032ea0;
        }
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_00032eb0;
    }
    if (pname == (undefined *)0x1603) {
      colorIndexSpecular = params[2] * FLOAT_00108e5c;
      colorIndexAmbient = *params * FLOAT_00108e5c;
      colorIndexDiffuse = params[1] * FLOAT_00108e5c;
      if (face == 0x405) {
        lastFaceSlot = 1;
        firstFaceSlot = 1;
LAB_00032e68:
        if (firstFaceSlot <= lastFaceSlot) {
          remaining = (lastFaceSlot + 1) - firstFaceSlot;
          materialSlot = firstFaceSlot * 0x10 + glContext;
          do {
            *(float *)(materialSlot + 0x2f0) = colorIndexAmbient;
            *(float *)(materialSlot + 0x2f4) = colorIndexDiffuse;
            *(float *)(materialSlot + 0x2f8) = colorIndexSpecular;
            materialSlot = materialSlot + 0x10;
            remaining = remaining + -1;
          } while (remaining != 0);
        }
LAB_00032eb8:
        if (((*(char *)(glContext + 0x4df8) != '\0') && (pname != (undefined *)0x1601)) &&
           (pname != (undefined *)0x1603)) {
          (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
        }
        return;
      }
      if (face < 0x406) {
        if (face == 0x404) {
          lastFaceSlot = 0;
          firstFaceSlot = 0;
          goto LAB_00032e68;
        }
      }
      else if (face == 0x408) {
        firstFaceSlot = 0;
        lastFaceSlot = 1;
        goto LAB_00032e68;
      }
    }
  }
LAB_00032ea0:
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_00032eb0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

