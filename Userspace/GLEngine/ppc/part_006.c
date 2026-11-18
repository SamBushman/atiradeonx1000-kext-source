#include "decls.h"

/* _glNormal3f_Comp @ 0x3a8cc (116 bytes) */
float * _glNormal3f_Comp(undefined4 glContext,float nx,float ny,float nz)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glNormal_ListExec_00110224,0xc);
  if (listRecord != (float *)0x0) {
    listRecord[2] = (float)nz;
    *listRecord = (float)nx;
    listRecord[1] = (float)ny;
  }
  return listRecord;
}

/* _glNormal3f_Exec @ 0x3a940 (16 bytes) */
void _glNormal3f_Exec(int glContext,float nx,float ny,float nz)
{
  *(float *)(glContext + 0x2b0) = (float)nx;
  *(float *)(glContext + 0x2b4) = (float)ny;
  *(float *)(glContext + 0x2b8) = (float)nz;
  return;
}

/* _glVertex3f_CompExec @ 0x3a950 (96 bytes) */
void _glVertex3f_CompExec(undefined4 glContext,float x,float y,float z)
{
  ((float * (*)())_glVertex3f_Comp)(glContext,x,y,z);
  ((void (*)())_glVertex3f_Exec)(glContext,x,y,z);
  return;
}

/* _glVertex3f_Comp @ 0x3a9b0 (116 bytes) */
float * _glVertex3f_Comp(undefined4 glContext,float x,float y,float z)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glVertex3_ListExec_00110414,0xc);
  if (listRecord != (float *)0x0) {
    listRecord[2] = (float)z;
    *listRecord = (float)x;
    listRecord[1] = (float)y;
  }
  return listRecord;
}

/* _glVertex3f_Exec @ 0x3aa24 (40 bytes) */
void _glVertex3f_Exec(int glContext,double x,double y,double z)
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContext,x,y,z,(double)*(float *)(glContext + 0x24));
  return;
}

/* _glPushMatrix_CompExec @ 0x3aa74 (48 bytes) */
void _glPushMatrix_CompExec(glContext)
  undefined4 glContext;
{
  ((int (*)())_glPushMatrix_Comp)(glContext);
  _glPushMatrix_Exec(glContext);
  return;
}

/* _glPushMatrix_Comp @ 0x3aaa4 (32 bytes) */
int _glPushMatrix_Comp(glContext)
  undefined4 glContext;
{
  undefined4 listRecord;
  
  listRecord = _gleAddListItem(glContext,PTR__glPushMatrix_ListExec_001101f4,0);
  return listRecord;
}

/* _glScalef_CompExec @ 0x3aac4 (96 bytes) */
void _glScalef_CompExec(undefined4 glContext,float x,float y,float z)
{
  ((float * (*)())_glScalef_Comp)(glContext,x,y,z);
  ((void (*)())_glScale_Exec)(glContext,x,y,z);
  return;
}

/* _glScalef_Comp @ 0x3ab24 (116 bytes) */
float * _glScalef_Comp(undefined4 glContext,float x,float y,float z)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glScale_ListExec_0011029c,0xc);
  if (listRecord != (float *)0x0) {
    listRecord[2] = (float)z;
    *listRecord = (float)x;
    listRecord[1] = (float)y;
  }
  return listRecord;
}

/* _glPopMatrix_CompExec @ 0x3ab98 (48 bytes) */
void _glPopMatrix_CompExec(glContext)
  undefined4 glContext;
{
  ((int (*)())_glPopMatrix_Comp)(glContext);
  _glPopMatrix_Exec(glContext);
  return;
}

/* _glPopMatrix_Comp @ 0x3abc8 (32 bytes) */
int _glPopMatrix_Comp(glContext)
  undefined4 glContext;
{
  undefined4 listRecord;
  
  listRecord = _gleAddListItem(glContext,PTR__glPopMatrix_ListExec_001101f8,0);
  return listRecord;
}

/* _glTranslatef_CompExec @ 0x3abe8 (96 bytes) */
void _glTranslatef_CompExec(undefined4 glContext,float x,float y,float z)
{
  ((float * (*)())_glTranslatef_Comp)(glContext,x,y,z);
  ((void (*)())_glTranslate_Exec)(glContext,x,y,z);
  return;
}

/* _glTranslatef_Comp @ 0x3ac48 (116 bytes) */
float * _glTranslatef_Comp(undefined4 glContext,float x,float y,float z)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTranslate_ListExec_0011040c,0xc);
  if (listRecord != (float *)0x0) {
    listRecord[2] = (float)z;
    *listRecord = (float)x;
    listRecord[1] = (float)y;
  }
  return listRecord;
}

/* _gleBeginLineLoopRenderTCL @ 0x3acbc (60 bytes) */
void _gleBeginLineLoopRenderTCL(glContext)
  int glContext;
{
  undefined *puVar1;
  undefined *puVar2;
  
  *(undefined1 *)(glContext + 0x4a18) = 0;
  puVar2 = PTR__gleFlushLineLoopTCLFunc_001121d8;
  puVar1 = PTR__gleRenderLineLoopTCLFunc_001121d4;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = puVar2;
  *(undefined **)(glContext + 0x4a08) = puVar1;
  return;
}

/* _gleRenderLineLoopTCLFunc @ 0x3acf8 (180 bytes) */
void _gleRenderLineLoopTCLFunc(glContext)
  int glContext;
{
  int iVar1;
  int remaining;
  undefined4 glContextWord4688;
  int glContextWord4854;
  uint uVar5;
  undefined4 uVar6;
  int loopIndex;
  short glContextShort487c;
  int iVar9;
  int glContextWord4858;
  code *UNRECOVERED_JUMPTABLE;
  
  glContextWord4854 = *(int *)(glContext + 0x4854);
  glContextWord4858 = *(int *)(glContext + 0x4858);
  glContextShort487c = *(short *)(glContext + 0x487c);
  uVar5 = (uint)(glContextWord4858 - glContextWord4854) / (uint)(int)glContextShort487c;
  if (*(char *)(glContext + 0x4a18) == '\0') {
    if (*(short *)(glContext + 0x4a10) < 0) {
      UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46bc);
    }
    else {
      UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
    }
    glContextWord4688 = *(undefined4 *)(glContext + 0x4688);
    uVar6 = 1;
  }
  else {
    if (*(short *)(glContext + 0x4a10) < 0) {
      remaining = (int)glContextShort487c >> 3;
      loopIndex = 0;
      iVar9 = glContextWord4854;
      if (0 < remaining) {
        while( true ) {
          iVar1 = loopIndex * 8;
          loopIndex = loopIndex + 1;
          *(undefined8 *)(iVar1 + glContextWord4858) = *(undefined8 *)(iVar1 + iVar9 + -0x100);
          remaining = remaining + -1;
          if (remaining == 0) break;
          iVar9 = *(int *)(glContext + 0x4854);
        }
        glContextShort487c = *(short *)(glContext + 0x487c);
      }
      uVar5 = uVar5 + 1;
      *(int *)(glContext + 0x4858) = glContextWord4858 + glContextShort487c;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x46b8);
    uVar6 = 0;
    glContextWord4688 = *(undefined4 *)(glContext + 0x4688);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContextWord4688,glContextWord4854,uVar5,uVar6);
  return;
}

/* _glEndList_Exec @ 0x3adac (40 bytes) */
void _glEndList_Exec(glContext)
  int glContext;
{
  if (*(int *)(glContext + 0x5408) != 0) {
    ((void (*)())_gleEndList)(glContext);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _gleEndList @ 0x3add4 (380 bytes) */
void _gleEndList(glContext)
  int glContext;
{
  int reallocatedBlock;
  int iVar1;
  int iVar2;
  int sharedState;
  undefined4 glContextWord53e8;
  int iVar4;
  int glContextPtr53e8;
  uint glContextWord5400;
  int glContextPtr53e82;
  
  glContextWord5400 = *(uint *)(glContext + 0x5400);
  *(undefined4 *)(glContext + 0x5408) = 0;
  if (glContextWord5400 < *(uint *)(glContext + 0x53fc) - (*(uint *)(glContext + 0x53fc) >> 4)) {
    glContextWord53e8 = *(undefined4 *)(glContext + 0x53e8);
    reallocatedBlock = _realloc(glContextWord53e8,glContextWord5400);
    *(int *)(glContext + 0x53e8) = reallocatedBlock;
    if (reallocatedBlock == 0) {
      _free(glContextWord53e8);
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x505;
      }
      return;
    }
    *(uint *)(glContext + 0x53fc) = glContextWord5400;
  }
  sharedState = *(int *)(glContext + 0x5148);
  iVar4 = sharedState + 0x300c;
  if (*(char *)(sharedState + 0x8024) != '\0') {
    _pthread_mutex_lock(sharedState + 0x8028);
  }
  glContextPtr53e82 = *(int *)(glContext + 0x53e8);
  iVar2 = ((int (*)())_gleIsHashName)(iVar4,*(undefined4 *)(glContextPtr53e82 + 4));
  if (iVar2 == 0) {
    _gleAddHashNameAndObject(glContext,iVar4,glContextPtr53e82);
  }
  else {
    iVar2 = _gleRemoveHashObject(iVar4,*(undefined4 *)(glContextPtr53e82 + 4));
    if ((iVar2 != 0) && (iVar1 = *(int *)(iVar2 + 8) + -1, *(int *)(iVar2 + 8) = iVar1, iVar1 == 0))
    {
      ((void (*)())_gleFreeDisplayListObject)(glContext,iVar2);
    }
    _gleAddHashObject(iVar4,glContextPtr53e82);
  }
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
  }
  if (*(char *)(glContext + 0x5410) != '\0') {
    ((void (*)())_gleOptimizeDisplayList)(glContext,*(undefined4 *)(glContextPtr53e82 + 4));
  }
  glContextPtr53e8 = *(int *)(glContext + 0x53e8);
  iVar2 = *(int *)(glContextPtr53e8 + 0x14);
  if (iVar2 != 0) {
    _free(iVar2);
    *(undefined4 *)(glContextPtr53e8 + 0x14) = 0;
  }
  _gliExecDispatchTable(glContext);
  return;
}

/* _gleIsHashName @ 0x3af50 (68 bytes) */
int _gleIsHashName(param_1, param_2)
  int param_1;
  uint param_2;
{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x1000);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if (param_2 < (uint)piVar1[1]) break;
    if (param_2 < (uint)(piVar1[1] + piVar1[2])) {
      return 1;
    }
    piVar1 = (int *)*piVar1;
  }
  return 0;
}

/* _gleOptimizeDisplayList @ 0x3af94 (9884 bytes) */
void _gleOptimizeDisplayList(glContext, list)
  int glContext;
  undefined4 list;
{
  undefined4 *cursor;
  int remaining;
  bool bVar1;
  bool bVar2;
  char cVar3;
  int *piVar4;
  uint *puVar5;
  float fVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  int iVar12;
  int sharedState;
  int hashObject;
  uint uVar13;
  int iVar14;
  int listRecord;
  int *piVar15;
  int *srcCursor2;
  int *listRecord2;
  undefined *puVar16;
  uint *puVar17;
  undefined4 *puVar18;
  undefined4 *dstCursor;
  byte *srcCursor;
  uint uVar20;
  uint uVar21;
  uint *puVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  uint loopIndex;
  int iVar27;
  int glContextPtr53e8;
  int iVar28;
  uint *puVar29;
  uint uVar30;
  uint uVar31;
  byte in_xer_so = 0;
  byte in_cr1;
  byte bVar32;
  byte unaff_cr3;
  byte unaff_cr4;
  byte in_cr5;
  byte in_cr6;
  byte bVar33;
  undefined4 local_2f0;
  undefined4 local_2ec;
  undefined4 local_2e8;
  undefined4 local_2e4;
  undefined4 local_2e0;
  undefined4 local_2dc;
  undefined4 local_2d8;
  undefined1 local_2d4 [4];
  undefined4 local_2d0;
  undefined4 local_2cc;
  uint local_2c8;
  int local_2c0;
  int local_2bc [7];
  int local_2a0 [8];
  int aiStack_280 [15];
  int local_244;
  uint local_240;
  uint local_23c;
  uint local_238;
  uint local_234;
  uint local_230;
  uint local_22c;
  uint local_228;
  uint local_224;
  uint local_220;
  uint local_21c;
  uint local_218;
  uint local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  float local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  uint uStack_1ec;
  float local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  uint local_1d0;
  float local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  float local_1c0;
  float local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  float local_1b0;
  float local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  float local_1a0;
  float local_19c;
  float local_198;
  undefined4 local_194;
  float local_190;
  float local_18c;
  float local_188;
  undefined4 local_184;
  float local_180;
  float local_17c;
  float local_178;
  undefined4 local_174;
  float local_170;
  float local_16c;
  float local_168;
  float local_164;
  undefined4 local_160;
  undefined4 local_15c;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  int local_80;
  uint *local_7c;
  uint *local_78;
  int local_74;
  int local_70;
  uint local_6c;
  float local_60;
  
  hashObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x300c,list);
  if (hashObject != 0) {
    uVar23 = *(uint *)(hashObject + 0x10);
    if (uVar23 < 0x10) {
      _gleQuickOptimizeDisplayList(glContext,list,hashObject);
    }
    else {
      puVar22 = (uint *)0x0;
      puVar29 = (uint *)(hashObject + 0x2c);
      iVar24 = *(int *)(hashObject + 0x14);
      _gleNewList(glContext,list,((unsigned char *)0x00001300U));
      local_74 = 0;
      local_78 = (uint *)0x0;
      iVar12 = 0;
      loopIndex = 0;
      puVar5 = puVar22;
      if (uVar23 != 0) {
        do {
          puVar16 = (undefined *)*puVar29;
          iVar27 = 0;
          iVar11 = *(int *)(((uint)puVar16 & 0x7c) + _gleDisplayListFunctionHash);
          while ((iVar11 != 0 && (iVar27 = iVar11, puVar16 != *(undefined **)(iVar11 + 4)))) {
            iVar27 = *(int *)(iVar11 + 0xc);
            iVar11 = iVar27;
          }
          puVar22 = puVar5;
          if (puVar16 == PTR__glBegin_ListExec_00112150) {
            uVar21 = puVar29[1];
            local_2c8 = 0;
            local_2f0 = 0;
            local_2ec = 0;
            local_2e8 = 0;
            local_2e4 = 0;
            local_2e0 = 0;
            local_2dc = 0;
            local_2d8 = 0;
            *(unsigned int *)local_2d4 = (unsigned int)0x0;
            local_2d0 = 0;
            local_2cc = 0;
            uVar13 = ((int (*)())_EstablishVertexFormat)(&local_2f0,puVar29,uVar23,loopIndex,iVar24,&local_80,&local_7c);
            if (((int)uVar13 < 0x1a) || (9 < uVar21)) {
              uVar13 = *(int *)(loopIndex * 4 + iVar24) - 4;
              listRecord = _gleAddListItem(glContext,*puVar29,uVar13);
              iVar11 = 0;
              for (uVar13 = uVar13 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
                *(uint *)(listRecord + iVar11 * 4) = puVar29[iVar11 + 1];
                iVar11 = iVar11 + 1;
              }
LAB_0003d534:
              if (iVar27 != 0) {
                bVar1 = *(undefined **)(iVar27 + 4) == PTR__glWeightARB_ListExec_0011214c;
LAB_0003d5ac:
                if (bVar1) goto LAB_0003d5b0;
              }
LAB_0003d5c4:
              puVar29 = (uint *)((int)puVar29 + *(int *)(loopIndex * 4 + iVar24));
              goto LAB_0003d5cc;
            }
            bVar1 = uVar21 == 4;
            bVar32 = ((int)uVar21 < 4) << 3 | (4 < (int)uVar21) << 2 | bVar1 << 1 | in_xer_so & 1;
            iVar27 = 0;
            local_70 = 0;
            if ((((bVar1) || (uVar21 == 1)) || (uVar21 == 0)) || (uVar21 == 7)) {
              bVar2 = false;
              uVar31 = loopIndex + local_80 + 1;
              if (bVar1) {
                if (uVar13 == ((int)uVar13 / 3) * 3) goto LAB_0003b1c4;
LAB_0003b1c0:
                bVar2 = true;
              }
              else if (uVar21 < 5) {
                if (uVar21 == 1) {
                  uVar7 = uVar13 & 1;
LAB_0003b1bc:
                  if (uVar7 != 0) goto LAB_0003b1c0;
                }
              }
              else if (uVar21 == 7) {
                uVar7 = uVar13 & 3;
                goto LAB_0003b1bc;
              }
LAB_0003b1c4:
              unaff_cr4 = bVar2 << 2 | !bVar2 << 1 | in_xer_so & 1;
              if ((!bVar2) && (uVar31 < uVar23)) {
                do {
                  if (PTR__glEnd_ListExec_00110a3c == PTR__glWeightARB_ListExec_0011214c) {
                    local_7c = local_7c + local_7c[1] + 2;
                  }
                  else {
                    local_7c = (uint *)((int)local_7c + *(int *)(iVar24 + (loopIndex + local_80) * 4));
                  }
                  puVar5 = *(uint **)((*local_7c & 0x7c) + _gleDisplayListFunctionHash);
                  if (puVar5 == (uint *)0x0) {
LAB_0003b2e8:
                    unaff_cr4 = in_xer_so & 1 | 4;
                  }
                  else {
                    do {
                      if (*local_7c == puVar5[1]) break;
                      puVar5 = (uint *)puVar5[3];
                    } while (puVar5 != (uint *)0x0);
                    if (((puVar5 == (uint *)0x0) || (uVar7 = *puVar5, uVar7 != 0)) ||
                       ((uVar21 != local_7c[1] ||
                        (local_240 = uVar7, local_23c = uVar7, local_238 = uVar7, local_234 = uVar7,
                        local_230 = uVar7, local_22c = uVar7, local_228 = uVar7, local_224 = uVar7,
                        local_220 = uVar7, local_21c = uVar7, local_218 = uVar7,
                        uVar7 = ((int (*)())_EstablishVertexFormat)(&local_240,local_7c,uVar23,loopIndex + local_80 + 1,iVar24,
                                           &local_80,&local_7c), uVar7 == 0)))) goto LAB_0003b2e8;
                    if (bVar1) {
                      if (uVar7 != (uVar7 / 3) * 3) {
LAB_0003b350:
                        unaff_cr4 = in_xer_so & 1 | 4;
                      }
                    }
                    else if (uVar21 < 5) {
                      if ((uVar21 == 1) && ((uVar7 & 1) != 0)) {
                        unaff_cr4 = in_xer_so & 1 | 4;
                      }
                    }
                    else if ((uVar21 == 7) && ((uVar7 & 3) != 0)) goto LAB_0003b350;
                    if (!(bool)(unaff_cr4 >> 1 & 1)) break;
                    puVar18 = &local_2f0;
                    while( true ) {
                      if (*(char *)(puVar18 + 3) != *(char *)(puVar18 + 0x2f)) {
                        unaff_cr4 = in_xer_so & 1 | 4;
                      }
                      puVar18 = (undefined4 *)((int)puVar18 + 1);
                      if (local_2d4 + 3 < puVar18) break;
                      if (!(bool)(unaff_cr4 >> 1 & 1)) goto LAB_0003b3b0;
                    }
                    if (!(bool)(unaff_cr4 >> 1 & 1)) break;
                    uVar13 = uVar13 + uVar7;
                    uVar31 = uVar31 + local_80 + 1;
                  }
                  if ((!(bool)(unaff_cr4 >> 1 & 1)) || (uVar23 <= uVar31)) break;
                } while( true );
              }
            }
LAB_0003b3b0:
            _memset(&local_2c0,0,0x80);
            remaining = 0x1e;
            cursor = &local_2ec;
            srcCursor = (byte *)((int)&local_2e4 + 1);
            do {
              bVar33 = *srcCursor;
              srcCursor = srcCursor + 1;
              cursor[0xd] = cursor[0xc] + (uint)bVar33;
              cursor = cursor + 1;
              remaining = remaining + -1;
            } while (remaining != 0);
            bVar2 = uVar13 == 0;
            local_6c = (uint)(byte)((local_70 < 0) << 3 | (0 < local_70) << 2 | (local_70 == 0) << 1
                                   | in_xer_so & 1) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 |
                       (uint)bVar32 << 0x14 | (uint)(unaff_cr3 & 0xf) << 0x10 |
                       (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
                       (uint)(in_cr6 & 0xf) << 4 |
                       (uint)(byte)(((int)uVar13 < 0) << 3 | (0 < (int)uVar13) << 2 | bVar2 << 1 |
                                   in_xer_so & 1);
            local_2c0 = local_244 + (local_2c8 & 0xff);
            while (!bVar2) {
              uVar31 = 0;
              uVar7 = uVar13;
              if (0xffff < uVar13) {
                if (uVar21 == 1) {
                  uVar7 = 0xfffe;
                }
                else if ((uVar21 == 0) || (bVar1)) {
                  uVar7 = 0xffff;
                }
                else if (uVar21 == 7) {
                  uVar7 = 0xfffc;
                }
              }
              uVar13 = uVar13 - uVar7;
              iVar14 = 0x2c;
              iVar28 = uVar7 * (local_2c0 + (local_2e4 >> 0x18));
              iVar11 = iVar28 + 0x2c;
              bVar33 = (iVar11 < local_74) << 3 | (local_74 < iVar11) << 2 |
                       (iVar11 == local_74) << 1 | in_xer_so & 1;
              if (local_74 < iVar11) {
                iVar14 = 0x40;
                if (local_78 != (uint *)0x0) {
                  ((void (*)())_CloseCurrentVAR)(glContext,iVar12,puVar22,&local_78,&local_74);
                }
                piVar15 = (int *)((int (*)())_gleAddListItemWithFree)(glContext,
                                            PTR__gleSetupAndDrawArraysOrElementsOutOfLine_ListExec_00112140
                                            ,0x10,PTR__gleOptimizedListFreeFunc_00110ccc,4);
                local_74 = iVar28 + 0x40;
                bVar33 = (local_74 < 0x100000) << 3 | (0x100000 < local_74) << 2 |
                         (local_74 == 0x100000) << 1 | in_xer_so & 1;
                iVar12 = (int)piVar15 - *(int *)(glContext + 0x53e8);
                if (0x100000 < local_74) {
                  uVar30 = (uint)(((unsigned char *)0x0000103f) + iVar28) & 0xfffff000;
                }
                else {
                  local_74 = 0x100000;
                  uVar30 = 0x100000;
                }
                _vm_allocate(*(vm_map_t *)PTR_00112034,(vm_address_t *)&local_78,uVar30,1);
                *piVar15 = (int)local_78;
                local_78[3] = uVar30;
                *(undefined4 *)*piVar15 = 4;
                *(uint *)*piVar15 = *(uint *)*piVar15 | 2;
                puVar22 = local_78;
                puVar5 = (uint *)(*piVar15 + 0x14);
              }
              else {
                listRecord2 = (int *)_gleAddListItem(glContext,
                                                 PTR__gleDrawArraysOrElementsOutOfLine_ListExec_0011213c
                                                 ,8);
                *listRecord2 = (int)listRecord2 + (-iVar12 - *(int *)(glContext + 0x53e8));
                listRecord2[1] = (int)puVar22 - (int)local_78;
                puVar5 = puVar22;
              }
              if ((bool)((byte)(local_6c >> 0x1d) & 1)) {
                unaff_cr3 = ((int)uVar13 < 0) << 3 | (0 < (int)uVar13) << 2 | (uVar13 == 0) << 1 |
                            in_xer_so & 1;
                if (uVar13 != 0) {
                  local_70 = _malloc(local_2c0 + (local_2e4 >> 0x18));
                  local_6c = (uint)(byte)((local_70 < 0) << 3 | (0 < local_70) << 2 |
                                          (local_70 == 0) << 1 | in_xer_so & 1) << 0x1c |
                             (uint)(in_cr1 & 0xf) << 0x18 | (uint)bVar32 << 0x14 |
                             (uint)unaff_cr3 << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc |
                             (uint)(in_cr5 & 0xf) << 8 | (uint)(in_cr6 & 0xf) << 4 |
                             (uint)(bVar33 & 0xf);
                }
              }
              else {
                iVar27 = (int)puVar22 + iVar14;
                unaff_cr3 = ((int)uVar13 < 0) << 3 | (0 < (int)uVar13) << 2 | (uVar13 == 0) << 1 |
                            in_xer_so & 1;
                _memcpy(iVar27,local_70,local_2c0);
              }
              local_74 = local_74 - (iVar28 + iVar14);
              puVar22 = (uint *)((int)puVar22 + iVar28 + iVar14);
              unaff_cr4 = (0 < (int)uVar7) << 3 | ((int)uVar7 < 0) << 2 | (uVar7 == 0) << 1 |
                          in_xer_so & 1;
              _memcpy(puVar5,&local_2f0,0x2c);
              *puVar5 = uVar21;
              puVar5[1] = uVar7;
              uVar30 = local_2e4 >> 0x18;
              puVar5[2] = local_2c0 + uVar30;
              if (0 < (int)uVar7) {
                do {
                  piVar15 = (int *)0x0;
                  piVar4 = *(int **)((*puVar29 & 0x7c) + _gleDisplayListFunctionHash);
                  while ((piVar4 != (int *)0x0 && (piVar15 = piVar4, *puVar29 != piVar4[1]))) {
                    piVar15 = (int *)piVar4[3];
                    piVar4 = piVar15;
                  }
                  puVar17 = puVar29 + 1;
                  iVar11 = *piVar15;
                  iVar27 = (int)puVar5 + uVar31 * (local_2c0 + uVar30) + 0x2c;
                  uVar25 = uVar31;
                  switch(iVar11) {
                  default:
                    goto switchD_0003b6b4_caseD_0;
                  case 2:
                  case 3:
                  case 4:
                    if (iVar11 == 2) {
                      uVar30 = *puVar17;
                      *(uint *)(iVar27 + local_2c0 + 4) = puVar29[2];
                      *(uint *)(iVar27 + local_2c0) = uVar30;
                      if (0xb < (*(unsigned char *)((unsigned char *)&(local_2e4) + 0))) {
                        *(undefined4 *)(iVar27 + local_2c0 + 8) = 0;
                      }
LAB_0003b7c0:
                      if (0xf < (*(unsigned char *)((unsigned char *)&(local_2e4) + 0))) {
                        *(undefined4 *)(iVar27 + local_2c0 + 0xc) = 0x3f800000;
                      }
                    }
                    else {
                      if (iVar11 == 3) {
                        uVar30 = puVar29[3];
                        uVar25 = puVar29[2];
                        *(uint *)(iVar27 + local_2c0) = *puVar17;
                        *(uint *)(iVar27 + local_2c0 + 4) = uVar25;
                        *(uint *)(iVar27 + local_2c0 + 8) = uVar30;
                        goto LAB_0003b7c0;
                      }
                      uVar30 = puVar29[4];
                      uVar25 = puVar29[2];
                      uVar20 = puVar29[3];
                      *(uint *)(iVar27 + local_2c0) = *puVar17;
                      *(uint *)(iVar27 + local_2c0 + 0xc) = uVar30;
                      *(uint *)(iVar27 + local_2c0 + 4) = uVar25;
                      *(uint *)(iVar27 + local_2c0 + 8) = uVar20;
                    }
                    uVar25 = uVar31 + 1;
                    unaff_cr4 = ((int)uVar25 < (int)uVar7) << 3 | ((int)uVar7 < (int)uVar25) << 2 |
                                (uVar25 == uVar7) << 1 | in_xer_so & 1;
                    if ((int)uVar25 >= (int)uVar7) goto switchD_0003b6b4_caseD_0;
                    goto LAB_0003d09c;
                  case 5:
                    uVar31 = puVar29[3];
                    uVar30 = puVar29[2];
                    *(uint *)(iVar27 + local_2bc[1]) = *puVar17;
                    *(uint *)(iVar27 + local_2bc[1] + 8) = uVar31;
                    *(uint *)(iVar27 + local_2bc[1] + 4) = uVar30;
                    if ((*(unsigned char *)((unsigned char *)&(local_2e4) + 2)) == '\x10') {
                      puVar29[4] = 0x3f800000;
                    }
                    goto switchD_0003b6b4_caseD_0;
                  case 6:
                    uVar31 = puVar29[4];
                    uVar20 = puVar29[2];
                    uVar30 = puVar29[3];
                    *(uint *)(iVar27 + local_2bc[1]) = *puVar17;
                    *(uint *)(iVar27 + local_2bc[1] + 0xc) = uVar31;
                    *(uint *)(iVar27 + local_2bc[1] + 4) = uVar20;
                    *(uint *)(iVar27 + local_2bc[1] + 8) = uVar30;
                    goto switchD_0003b6b4_caseD_0;
                  case 7:
                    iVar11 = local_2bc[0];
                    goto LAB_0003d134;
                  case 8:
                  case 9:
                  case 10:
                  case 0xb:
                    local_238 = 0;
                    local_234 = 0x3f800000;
                    local_23c = 0;
                    local_240 = *puVar17;
                    iVar11 = *piVar15;
                    if (8 < iVar11) {
                      local_23c = puVar29[2];
                      iVar11 = *piVar15;
                    }
                    if (9 < iVar11) {
                      local_238 = puVar29[3];
                      iVar11 = *piVar15;
                    }
                    if (10 < iVar11) {
                      local_234 = puVar29[4];
                    }
                    if ((*(unsigned char *)((unsigned char *)&(local_2dc) + 0)) == '\x04') {
                      *(uint *)(iVar27 + local_2a0[0]) = local_240;
                    }
                    else if ((*(unsigned char *)((unsigned char *)&(local_2dc) + 0)) == '\b') {
                      *(uint *)(iVar27 + local_2a0[0]) = local_240;
                      *(uint *)(iVar27 + local_2a0[0] + 4) = local_23c;
                    }
                    else if ((*(unsigned char *)((unsigned char *)&(local_2dc) + 0)) == '\f') {
                      *(uint *)(iVar27 + local_2a0[0]) = local_240;
                      *(uint *)(iVar27 + local_2a0[0] + 8) = local_238;
                      *(uint *)(iVar27 + local_2a0[0] + 4) = local_23c;
                    }
                    else if ((*(unsigned char *)((unsigned char *)&(local_2dc) + 0)) == '\x10') {
                      *(uint *)(iVar27 + local_2a0[0]) = local_240;
                      *(uint *)(iVar27 + local_2a0[0] + 0xc) = local_234;
                      *(uint *)(iVar27 + local_2a0[0] + 4) = local_23c;
                      *(uint *)(iVar27 + local_2a0[0] + 8) = local_238;
                    }
                    goto switchD_0003b6b4_caseD_0;
                  case 0xc:
                  case 0xd:
                  case 0xe:
                    local_228 = 0;
                    local_224 = 0x3f800000;
                    local_230 = puVar29[2];
                    local_22c = puVar29[3];
                    iVar14 = *piVar15;
                    iVar11 = local_2a0[*puVar17];
                    if (0xc < iVar14) {
                      local_228 = puVar29[4];
                      iVar14 = *piVar15;
                    }
                    if (0xd < iVar14) {
                      local_224 = puVar29[5];
                    }
                    cVar3 = *(char *)((int)&local_2dc + *puVar17);
                    if (cVar3 == '\b') {
                      *(uint *)(iVar27 + iVar11) = local_230;
                      *(uint *)(iVar27 + iVar11 + 4) = local_22c;
                    }
                    else if (cVar3 == '\f') {
                      *(uint *)(iVar27 + iVar11) = local_230;
                      *(uint *)(iVar27 + iVar11 + 8) = local_228;
                      *(uint *)(iVar27 + iVar11 + 4) = local_22c;
                    }
                    else if (cVar3 == '\x10') {
                      *(uint *)(iVar27 + iVar11) = local_230;
                      *(uint *)(iVar27 + iVar11 + 0xc) = local_224;
                      *(uint *)(iVar27 + iVar11 + 4) = local_22c;
                      *(uint *)(iVar27 + iVar11 + 8) = local_228;
                    }
                    goto switchD_0003b6b4_caseD_0;
                  case 0xf:
                    local_210 = 0;
                    local_204 = 0x3f800000;
                    local_20c = 0;
                    local_208 = 0;
                    uVar30 = *puVar17;
                    local_210 = puVar29[2];
                    cVar3 = local_2d4[uVar30];
                    iVar11 = aiStack_280[uVar30];
                    if (cVar3 == '\x04') {
                      *(uint *)(iVar27 + iVar11) = local_210;
                    }
                    else {
                      if (cVar3 == '\b') {
                        *(uint *)(iVar27 + iVar11) = local_210;
                      }
                      else {
                        if (cVar3 == '\f') {
                          *(uint *)(iVar27 + iVar11) = local_210;
                        }
                        else {
                          if (cVar3 != '\x10') break;
                          *(uint *)(iVar27 + iVar11) = local_210;
                          *(undefined4 *)(iVar27 + iVar11 + 0xc) = 0x3f800000;
                        }
                        *(undefined4 *)(iVar27 + iVar11 + 8) = 0;
                      }
                      *(undefined4 *)(iVar27 + iVar11 + 4) = 0;
                    }
                    break;
                  case 0x10:
                    local_1f4 = 0x3f800000;
                    local_200 = 0.0;
                    local_1fc = 0;
                    local_1f8 = 0;
                    uVar30 = *puVar17;
                    iVar11 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    uStack_1ec = (int)*(short *)(puVar29 + 2) ^ 0x80000000U;
                    local_1f0 = 0x43300000;
                    fVar6 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)(puVar29 + 2) ^ 0x80000000U) -
                                   DOUBLE_00108d58);
                    local_200 = fVar6;
                    if (cVar3 == '\x04') {
LAB_0003ccbc:
                      *(float *)(iVar27 + iVar11) = fVar6;
                    }
                    else {
                      if (cVar3 == '\b') {
                        *(float *)(iVar27 + iVar11) = fVar6;
                      }
                      else {
                        if (cVar3 == '\f') {
                          *(float *)(iVar27 + iVar11) = fVar6;
                        }
                        else {
                          if (cVar3 != '\x10') break;
                          *(float *)(iVar27 + iVar11) = fVar6;
                          *(undefined4 *)(iVar27 + iVar11 + 0xc) = 0x3f800000;
                        }
                        *(undefined4 *)(iVar27 + iVar11 + 8) = 0;
                      }
                      *(undefined4 *)(iVar27 + iVar11 + 4) = 0;
                    }
                    break;
                  case 0x11:
                    local_1d4 = 0x3f800000;
                    local_1e0 = 0.0;
                    local_1dc = 0;
                    local_1d8 = 0;
                    uVar30 = *puVar17;
                    cVar3 = local_2d4[uVar30];
                    local_1e0 = (float)*(double *)(puVar29 + 2);
                    iVar11 = aiStack_280[uVar30];
                    if (cVar3 == '\x04') {
                      *(float *)(iVar27 + iVar11) = local_1e0;
                    }
                    else {
                      if (cVar3 == '\b') {
                        *(float *)(iVar27 + iVar11) = local_1e0;
                      }
                      else {
                        if (cVar3 == '\f') {
                          *(float *)(iVar27 + iVar11) = local_1e0;
                        }
                        else {
                          if (cVar3 != '\x10') goto LAB_0003cf8c;
                          *(float *)(iVar27 + iVar11) = local_1e0;
                          *(undefined4 *)(iVar27 + iVar11 + 0xc) = 0x3f800000;
                        }
                        *(undefined4 *)(iVar27 + iVar11 + 8) = 0;
                      }
                      *(undefined4 *)(iVar27 + iVar11 + 4) = 0;
                    }
                    goto LAB_0003cf8c;
                  case 0x12:
                    local_1c4 = 0x3f800000;
                    local_1d0 = 0;
                    local_1cc = 0.0;
                    local_1c8 = 0;
                    uVar30 = *puVar17;
                    local_1d0 = puVar29[2];
                    cVar3 = local_2d4[uVar30];
                    iVar11 = aiStack_280[uVar30];
                    fVar6 = GH_U2F((unsigned int)(puVar29[3]));
                    iVar14 = iVar27 + iVar11;
                    local_1cc = fVar6;
                    if (cVar3 == '\x04') {
                      *(uint *)(iVar27 + iVar11) = local_1d0;
                    }
                    else {
                      if (cVar3 == '\b') {
                        *(uint *)(iVar27 + iVar11) = local_1d0;
                      }
                      else {
                        if (cVar3 != '\f') {
                          if (cVar3 == '\x10') {
                            *(uint *)(iVar27 + iVar11) = local_1d0;
                            *(undefined4 *)(iVar14 + 0xc) = 0x3f800000;
                            *(float *)(iVar14 + 4) = fVar6;
                            *(undefined4 *)(iVar14 + 8) = 0;
                          }
                          goto LAB_0003ce40;
                        }
                        *(uint *)(iVar27 + iVar11) = local_1d0;
                        *(undefined4 *)(iVar14 + 8) = 0;
                      }
LAB_0003bcd0:
                      *(float *)(iVar14 + 4) = fVar6;
                    }
                    goto LAB_0003ce40;
                  case 0x13:
                    local_1c0 = 0.0;
                    local_1bc = 0.0;
                    local_1b4 = 0x3f800000;
                    local_1b8 = 0;
                    uVar30 = *puVar17;
                    iVar14 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    local_1f0 = 0x43300000;
                    fVar8 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)(puVar29 + 2) ^ 0x80000000) -
                                   DOUBLE_00108d58);
                    local_1c0 = fVar8;
                    uStack_1ec = (int)*(short *)((int)puVar29 + 10) ^ 0x80000000;
                    local_1bc = (float)((double)CONCAT44(0x43300000,uStack_1ec) - DOUBLE_00108d58);
                    if (cVar3 == '\x04') {
LAB_0003c004:
                      local_1f0 = 0x43300000;
                      *(float *)(iVar27 + iVar14) = fVar8;
                    }
                    else {
                      if (cVar3 == '\b') {
                        *(float *)(iVar27 + iVar14) = fVar8;
                      }
                      else {
                        if (cVar3 != '\f') {
                          if (cVar3 == '\x10') {
                            *(float *)(iVar27 + iVar14) = fVar8;
                            *(undefined4 *)(iVar27 + iVar14 + 0xc) = 0x3f800000;
                            *(float *)(iVar27 + iVar14 + 4) = local_1bc;
                            *(undefined4 *)(iVar27 + iVar14 + 8) = 0;
                          }
                          goto LAB_0003cf8c;
                        }
                        *(float *)(iVar27 + iVar14) = fVar8;
                        *(undefined4 *)(iVar27 + iVar14 + 8) = 0;
                      }
                      *(float *)(iVar27 + iVar14 + 4) = local_1bc;
                    }
                    goto LAB_0003cf8c;
                  case 0x14:
                    local_1a4 = 0x3f800000;
                    local_1b0 = 0.0;
                    local_1ac = 0.0;
                    local_1a8 = 0;
                    uVar30 = *puVar17;
                    local_1b0 = (float)*(double *)(puVar29 + 2);
                    cVar3 = local_2d4[uVar30];
                    iVar11 = aiStack_280[uVar30];
                    local_1ac = (float)*(double *)(puVar29 + 4);
                    if (cVar3 == '\x04') {
                      *(float *)(iVar27 + iVar11) = local_1b0;
                    }
                    else {
                      if (cVar3 == '\b') {
                        *(float *)(iVar27 + iVar11) = local_1b0;
                      }
                      else {
                        if (cVar3 != '\f') {
                          if (cVar3 == '\x10') {
                            *(float *)(iVar27 + iVar11) = local_1b0;
                            *(undefined4 *)(iVar27 + iVar11 + 0xc) = 0x3f800000;
                            *(float *)(iVar27 + iVar11 + 4) = local_1ac;
                            *(undefined4 *)(iVar27 + iVar11 + 8) = 0;
                          }
                          goto LAB_0003cf8c;
                        }
                        *(float *)(iVar27 + iVar11) = local_1b0;
                        *(undefined4 *)(iVar27 + iVar11 + 8) = 0;
                      }
                      *(float *)(iVar27 + iVar11 + 4) = local_1ac;
                    }
                    goto LAB_0003cf8c;
                  case 0x15:
                    local_198 = 0.0;
                    local_19c = 0.0;
                    local_194 = 0x3f800000;
                    uVar30 = *puVar17;
                    fVar8 = GH_U2F((unsigned int)(puVar29[2]));
                    local_1a0 = fVar8;
                    cVar3 = local_2d4[uVar30];
                    fVar6 = GH_U2F((unsigned int)(puVar29[3]));
                    iVar14 = aiStack_280[uVar30];
                    local_19c = fVar6;
                    fVar9 = GH_U2F((unsigned int)(puVar29[4]));
                    iVar11 = iVar27 + iVar14;
                    local_198 = fVar9;
                    if (cVar3 == '\x04') {
                      *(float *)(iVar27 + iVar14) = fVar8;
                    }
                    else if (cVar3 == '\b') {
LAB_0003c01c:
                      *(float *)(iVar27 + iVar14) = fVar8;
LAB_0003cf38:
                      *(float *)(iVar11 + 4) = fVar6;
                    }
                    else {
                      if (cVar3 == '\f') goto LAB_0003c038;
joined_r0x0003c044:
                      if (cVar3 == '\x10') {
                        fVar10 = 1.0;
                        *(float *)(iVar27 + iVar14) = fVar8;
LAB_0003cf80:
                        *(float *)(iVar11 + 0xc) = fVar10;
                        *(float *)(iVar11 + 4) = fVar6;
                        *(float *)(iVar11 + 8) = fVar9;
                      }
                    }
                    goto LAB_0003cf8c;
                  case 0x16:
                    local_188 = 0.0;
                    local_190 = 0.0;
                    local_18c = 0.0;
                    local_184 = 0x3f800000;
                    uVar30 = *puVar17;
                    iVar14 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    local_1f0 = 0x43300000;
                    iVar11 = iVar27 + iVar14;
                    fVar8 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)(puVar29 + 2) ^ 0x80000000) -
                                   DOUBLE_00108d58);
                    local_190 = fVar8;
                    fVar6 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)((int)puVar29 + 10) ^ 0x80000000
                                                    ) - DOUBLE_00108d58);
                    local_18c = fVar6;
                    uStack_1ec = (int)*(short *)(puVar29 + 3) ^ 0x80000000U;
                    fVar9 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)(puVar29 + 3) ^ 0x80000000U) -
                                   DOUBLE_00108d58);
                    local_188 = fVar9;
                    if (cVar3 == '\x04') goto LAB_0003c004;
                    if (cVar3 == '\b') goto LAB_0003c01c;
                    if (cVar3 != '\f') goto joined_r0x0003c044;
LAB_0003c038:
                    *(float *)(iVar27 + iVar14) = fVar8;
LAB_0003cf58:
                    *(float *)(iVar11 + 8) = fVar9;
                    *(float *)(iVar11 + 4) = fVar6;
                    goto LAB_0003cf8c;
                  case 0x17:
                    local_178 = 0.0;
                    local_180 = 0.0;
                    local_17c = 0.0;
                    local_174 = 0x3f800000;
                    uVar30 = *puVar17;
                    fVar6 = (float)*(double *)(puVar29 + 2);
                    cVar3 = local_2d4[uVar30];
                    local_180 = fVar6;
                    iVar11 = aiStack_280[uVar30];
                    fVar9 = (float)*(double *)(puVar29 + 4);
                    iVar14 = iVar27 + iVar11;
                    local_17c = fVar9;
                    fVar10 = (float)*(double *)(puVar29 + 6);
                    local_178 = fVar10;
                    if (cVar3 == '\x04') {
LAB_0003d00c:
                      *(float *)(iVar27 + iVar11) = fVar6;
                    }
                    else if (cVar3 == '\b') {
LAB_0003d024:
                      *(float *)(iVar27 + iVar11) = fVar6;
LAB_0003d028:
                      *(float *)(iVar14 + 4) = fVar9;
                    }
                    else {
                      if (cVar3 == '\f') goto LAB_0003d044;
                      if (cVar3 == '\x10') {
                        fVar8 = 1.0;
LAB_0003d06c:
                        *(float *)(iVar27 + iVar11) = fVar6;
LAB_0003d070:
                        *(float *)(iVar14 + 0xc) = fVar8;
                        *(float *)(iVar14 + 4) = fVar9;
                        *(float *)(iVar14 + 8) = fVar10;
                      }
                    }
                    break;
                  case 0x18:
                    local_168 = 0.0;
                    local_164 = 1.0;
                    local_170 = 0.0;
                    local_16c = 0.0;
                    uVar30 = *puVar17;
                    iVar11 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    iVar14 = iVar27 + iVar11;
                    local_160 = 0x4b000000;
                    local_15c = 0x4b000000;
                    fVar6 = GH_U2F((unsigned int)((*(byte *)(puVar29 + 2) | 0x4b000000))) - 8388608.0;
                    local_170 = fVar6;
                    fVar9 = GH_U2F((unsigned int)((*(byte *)((int)puVar29 + 9) | 0x4b000000))) - 8388608.0;
                    local_16c = fVar9;
                    fVar10 = GH_U2F((unsigned int)((*(byte *)((int)puVar29 + 10) | 0x4b000000))) - 8388608.0;
                    local_168 = fVar10;
                    local_60 = GH_U2F((unsigned int)((*(byte *)((int)puVar29 + 0xb) | 0x4b000000)));
                    fVar8 = local_60 - 8388608.0;
                    local_164 = fVar8;
                    if (cVar3 == '\x04') goto LAB_0003c8b8;
                    if (cVar3 == '\b') {
LAB_0003c9f0:
                      local_15c = 0x4b000000;
                      local_160 = 0x4b000000;
                      *(float *)(iVar27 + iVar11) = fVar6;
                      *(float *)(iVar14 + 4) = fVar9;
                    }
                    else {
                      if (cVar3 != '\f') goto joined_r0x0003ca24;
LAB_0003ca10:
                      local_15c = 0x4b000000;
                      local_160 = 0x4b000000;
                      *(float *)(iVar27 + iVar11) = fVar6;
                      *(float *)(iVar14 + 8) = fVar10;
                      *(float *)(iVar14 + 4) = fVar9;
                    }
                    break;
                  case 0x19:
                    local_148 = 0.0;
                    local_144 = 1.0;
                    local_150 = 0.0;
                    local_14c = 0.0;
                    uVar30 = *puVar17;
                    iVar11 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    local_160 = 0x4b000000;
                    local_15c = 0x4b000000;
                    fVar6 = (GH_U2F((unsigned int)((*(byte *)(puVar29 + 2) | 0x4b000000))) - 8388608.0) *
                            FLOAT_00108e78;
                    local_150 = fVar6;
                    fVar9 = (GH_U2F((unsigned int)((*(byte *)((int)puVar29 + 9) | 0x4b000000))) - 8388608.0) *
                            FLOAT_00108e78;
                    local_14c = fVar9;
                    fVar10 = (GH_U2F((unsigned int)((*(byte *)((int)puVar29 + 10) | 0x4b000000))) - 8388608.0) *
                             FLOAT_00108e78;
                    local_148 = fVar10;
                    local_60 = GH_U2F((unsigned int)((*(byte *)((int)puVar29 + 0xb) | 0x4b000000)));
                    fVar8 = (local_60 - 8388608.0) * FLOAT_00108e78;
                    local_144 = fVar8;
                    if (cVar3 == '\x04') goto LAB_0003c9d8;
joined_r0x0003c9e4:
                    iVar14 = iVar27 + iVar11;
                    if (cVar3 == '\b') goto LAB_0003c9f0;
                    if (cVar3 == '\f') goto LAB_0003ca10;
joined_r0x0003ca24:
                    local_15c = 0x4b000000;
                    local_160 = 0x4b000000;
                    if (cVar3 == '\x10') {
                      local_15c = 0x4b000000;
                      local_160 = 0x4b000000;
                      *(float *)(iVar27 + iVar11) = fVar6;
                      *(float *)(iVar14 + 0xc) = fVar8;
                      *(float *)(iVar14 + 4) = fVar9;
                      *(float *)(iVar14 + 8) = fVar10;
                    }
                    break;
                  case 0x1a:
                    local_138 = 0.0;
                    local_140 = 0.0;
                    local_13c = 0.0;
                    local_134 = 1.0;
                    uVar30 = *puVar17;
                    iVar11 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    local_1f0 = 0x43300000;
                    iVar14 = iVar27 + iVar11;
                    fVar8 = (float)((double)CONCAT44(0x43300000,puVar29[2] ^ 0x80000000) -
                                   DOUBLE_00108d58);
                    local_140 = fVar8;
                    fVar6 = (float)((double)CONCAT44(0x43300000,puVar29[3] ^ 0x80000000) -
                                   DOUBLE_00108d58);
                    local_13c = fVar6;
                    fVar9 = (float)((double)CONCAT44(0x43300000,puVar29[4] ^ 0x80000000) -
                                   DOUBLE_00108d58);
                    local_138 = fVar9;
                    uStack_1ec = puVar29[5] ^ 0x80000000;
                    fVar10 = (float)((double)CONCAT44(0x43300000,puVar29[5] ^ 0x80000000) -
                                    DOUBLE_00108d58);
                    local_134 = fVar10;
                    if (cVar3 == '\x04') goto LAB_0003cdd0;
                    if (cVar3 == '\b') goto LAB_0003cde8;
                    if (cVar3 == '\f') goto LAB_0003ce08;
                    goto joined_r0x0003ce1c;
                  case 0x1b:
                    local_128 = 0.0;
                    local_130 = 0.0;
                    local_12c = 0.0;
                    local_124 = 1.0;
                    uVar30 = *puVar17;
                    iVar11 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    local_1f0 = 0x43300000;
                    iVar14 = iVar27 + iVar11;
                    local_130 = (float)((double)CONCAT44(0x43300000,puVar29[2] ^ 0x80000000) -
                                       DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c;
                    local_12c = (float)((double)CONCAT44(0x43300000,puVar29[3] ^ 0x80000000) -
                                       DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c;
                    local_128 = (float)((double)CONCAT44(0x43300000,puVar29[4] ^ 0x80000000) -
                                       DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c;
                    uStack_1ec = puVar29[5] ^ 0x80000000;
                    local_124 = (float)((double)CONCAT44(0x43300000,puVar29[5] ^ 0x80000000) -
                                       DOUBLE_00108d58) * FLOAT_00108e68 + FLOAT_00108e6c;
                    if (cVar3 == '\x04') {
                      *(float *)(iVar27 + iVar11) = local_130;
                    }
                    else {
                      if (cVar3 == '\b') {
                        *(float *)(iVar27 + iVar11) = local_130;
                        fVar6 = local_12c;
                        goto LAB_0003bcd0;
                      }
                      if (cVar3 == '\f') {
                        *(float *)(iVar27 + iVar11) = local_130;
                        *(float *)(iVar14 + 8) = local_128;
                        *(float *)(iVar14 + 4) = local_12c;
                      }
                      else if (cVar3 == '\x10') {
                        *(float *)(iVar27 + iVar11) = local_130;
                        *(float *)(iVar14 + 0xc) = local_124;
                        *(float *)(iVar14 + 4) = local_12c;
                        *(float *)(iVar14 + 8) = local_128;
                      }
                    }
                    goto LAB_0003ce40;
                  case 0x1c:
                    local_118 = 0.0;
                    local_120 = 0.0;
                    local_11c = 0.0;
                    local_114 = 1.0;
                    uVar30 = *puVar17;
                    iVar11 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    local_1f0 = 0x43300000;
                    fVar8 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(char *)(puVar29 + 2) ^ 0x80000000) -
                                   DOUBLE_00108d58);
                    local_120 = fVar8;
                    fVar6 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(char *)((int)puVar29 + 9) ^ 0x80000000)
                                   - DOUBLE_00108d58);
                    local_11c = fVar6;
                    fVar9 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(char *)((int)puVar29 + 10) ^ 0x80000000)
                                   - DOUBLE_00108d58);
                    local_118 = fVar9;
                    uStack_1ec = (int)*(char *)((int)puVar29 + 0xb) ^ 0x80000000;
                    fVar10 = (float)((double)CONCAT44(0x43300000,uStack_1ec) - DOUBLE_00108d58);
                    local_114 = fVar10;
                    if (cVar3 == '\x04') goto LAB_0003cdd0;
                    goto joined_r0x0003cddc;
                  case 0x1d:
                    local_108 = 0.0;
                    local_110 = 0.0;
                    local_10c = 0.0;
                    local_104 = 1.0;
                    uVar30 = *puVar17;
                    iVar11 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    local_1f0 = 0x43300000;
                    iVar14 = iVar27 + iVar11;
                    local_110 = (float)((double)CONCAT44(0x43300000,
                                                         (int)*(char *)(puVar29 + 2) ^ 0x80000000) -
                                       DOUBLE_00108d58) * FLOAT_00108e60 + FLOAT_00108e64;
                    fVar9 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(char *)((int)puVar29 + 9) ^ 0x80000000)
                                   - DOUBLE_00108d58) * FLOAT_00108e60 + FLOAT_00108e64;
                    local_10c = fVar9;
                    fVar10 = (float)((double)CONCAT44(0x43300000,
                                                      (int)*(char *)((int)puVar29 + 10) ^ 0x80000000
                                                     ) - DOUBLE_00108d58) * FLOAT_00108e60 +
                             FLOAT_00108e64;
                    local_108 = fVar10;
                    uStack_1ec = (int)*(char *)((int)puVar29 + 0xb) ^ 0x80000000;
                    fVar8 = (float)((double)CONCAT44(0x43300000,uStack_1ec) - DOUBLE_00108d58) *
                            FLOAT_00108e60 + FLOAT_00108e64;
                    local_104 = fVar8;
                    if (cVar3 == '\x04') {
                      *(float *)(iVar27 + iVar11) = local_110;
                    }
                    else {
                      if (cVar3 == '\b') {
                        *(float *)(iVar27 + iVar11) = local_110;
                        goto LAB_0003d028;
                      }
                      if (cVar3 == '\f') {
                        *(float *)(iVar27 + iVar11) = local_110;
                        goto LAB_0003d048;
                      }
                      if (cVar3 == '\x10') {
                        *(float *)(iVar27 + iVar11) = local_110;
                        goto LAB_0003d070;
                      }
                    }
                    break;
                  case 0x1e:
                    local_f8 = 0.0;
                    local_f4 = 1.0;
                    local_100 = 0.0;
                    local_fc = 0.0;
                    uVar30 = *puVar17;
                    iVar11 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    local_160 = 0x4b000000;
                    local_15c = 0x4b000000;
                    fVar6 = GH_U2F((unsigned int)((*(ushort *)(puVar29 + 2) | 0x4b000000))) - 8388608.0;
                    local_100 = fVar6;
                    fVar9 = GH_U2F((unsigned int)((*(ushort *)((int)puVar29 + 10) | 0x4b000000))) - 8388608.0;
                    local_fc = fVar9;
                    fVar10 = GH_U2F((unsigned int)((*(ushort *)(puVar29 + 3) | 0x4b000000))) - 8388608.0;
                    local_f8 = fVar10;
                    local_60 = GH_U2F((unsigned int)((*(ushort *)((int)puVar29 + 0xe) | 0x4b000000)));
                    fVar8 = local_60 - 8388608.0;
                    local_f4 = fVar8;
                    if (cVar3 != '\x04') goto joined_r0x0003c9e4;
LAB_0003c8b8:
                    local_15c = 0x4b000000;
                    local_160 = 0x4b000000;
                    *(float *)(iVar27 + iVar11) = fVar6;
                    break;
                  case 0x1f:
                    local_e8 = 0.0;
                    local_e4 = 1.0;
                    local_f0 = 0.0;
                    local_ec = 0.0;
                    uVar30 = *puVar17;
                    iVar11 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    local_160 = 0x4b000000;
                    local_15c = 0x4b000000;
                    fVar6 = (GH_U2F((unsigned int)((*(ushort *)(puVar29 + 2) | 0x4b000000))) - 8388608.0) *
                            FLOAT_00108e74;
                    local_f0 = fVar6;
                    fVar9 = (GH_U2F((unsigned int)((*(ushort *)((int)puVar29 + 10) | 0x4b000000))) - 8388608.0) *
                            FLOAT_00108e74;
                    local_ec = fVar9;
                    fVar10 = (GH_U2F((unsigned int)((*(ushort *)(puVar29 + 3) | 0x4b000000))) - 8388608.0) *
                             FLOAT_00108e74;
                    local_e8 = fVar10;
                    local_60 = GH_U2F((unsigned int)((*(ushort *)((int)puVar29 + 0xe) | 0x4b000000)));
                    local_e4 = (local_60 - 8388608.0) * FLOAT_00108e74;
                    fVar8 = local_e4;
                    if (cVar3 != '\x04') goto joined_r0x0003c9e4;
LAB_0003c9d8:
                    local_15c = 0x4b000000;
                    local_160 = 0x4b000000;
                    *(float *)(iVar27 + iVar11) = fVar6;
                    break;
                  case 0x20:
                    local_d8 = 0.0;
                    local_e0 = 0.0;
                    local_dc = 0.0;
                    local_d4 = 1.0;
                    uVar30 = *puVar17;
                    cVar3 = local_2d4[uVar30];
                    iVar11 = aiStack_280[uVar30];
                    local_1f0 = 0x43300000;
                    fVar8 = (float)((double)CONCAT44(0x43300000,puVar29[2]) - DOUBLE_00108d70);
                    local_e0 = fVar8;
                    fVar6 = (float)((double)CONCAT44(0x43300000,puVar29[3]) - DOUBLE_00108d70);
                    local_dc = fVar6;
                    fVar9 = (float)((double)CONCAT44(0x43300000,puVar29[4]) - DOUBLE_00108d70);
                    local_d8 = fVar9;
                    uStack_1ec = puVar29[5];
                    fVar10 = (float)((double)CONCAT44(0x43300000,puVar29[5]) - DOUBLE_00108d70);
                    local_d4 = fVar10;
                    goto joined_r0x0003cdcc;
                  case 0x21:
                    local_c8 = 0.0;
                    local_d0 = 0.0;
                    local_cc = 0.0;
                    local_c4 = 1.0;
                    uVar30 = *puVar17;
                    cVar3 = local_2d4[uVar30];
                    iVar11 = aiStack_280[uVar30];
                    local_1f0 = 0x43300000;
                    fVar8 = (float)((double)CONCAT44(0x43300000,puVar29[2]) - DOUBLE_00108d70) *
                            FLOAT_00108e6c;
                    local_d0 = fVar8;
                    fVar6 = (float)((double)CONCAT44(0x43300000,puVar29[3]) - DOUBLE_00108d70) *
                            FLOAT_00108e6c;
                    local_cc = fVar6;
                    fVar9 = (float)((double)CONCAT44(0x43300000,puVar29[4]) - DOUBLE_00108d70) *
                            FLOAT_00108e6c;
                    local_c8 = fVar9;
                    uStack_1ec = puVar29[5];
                    fVar10 = (float)((double)CONCAT44(0x43300000,puVar29[5]) - DOUBLE_00108d70) *
                             FLOAT_00108e6c;
                    local_c4 = fVar10;
                    if (cVar3 != '\x04') goto joined_r0x0003cddc;
                    *(float *)(iVar27 + iVar11) = fVar8;
                    goto LAB_0003ce40;
                  case 0x22:
                    local_b8 = 0.0;
                    local_b4 = 1.0;
                    local_bc = 0.0;
                    fVar6 = GH_U2F((unsigned int)(puVar29[2]));
                    uVar30 = *puVar17;
                    local_c0 = fVar6;
                    fVar9 = GH_U2F((unsigned int)(puVar29[3]));
                    cVar3 = local_2d4[uVar30];
                    local_bc = fVar9;
                    fVar10 = GH_U2F((unsigned int)(puVar29[4]));
                    iVar11 = aiStack_280[uVar30];
                    local_b8 = fVar10;
                    fVar8 = GH_U2F((unsigned int)(puVar29[5]));
                    iVar14 = iVar27 + iVar11;
                    local_b4 = fVar8;
                    if (cVar3 == '\x04') goto LAB_0003ccbc;
                    if (cVar3 == '\b') goto LAB_0003d024;
                    if (cVar3 == '\f') goto LAB_0003d044;
joined_r0x0003d058:
                    if (cVar3 == '\x10') goto LAB_0003d06c;
                    break;
                  case 0x23:
                    local_a8 = 0.0;
                    local_b0 = 0.0;
                    local_ac = 0.0;
                    local_a4 = 1.0;
                    uVar30 = *puVar17;
                    iVar11 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    local_1f0 = 0x43300000;
                    fVar8 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)(puVar29 + 2) ^ 0x80000000) -
                                   DOUBLE_00108d58);
                    local_b0 = fVar8;
                    fVar6 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)((int)puVar29 + 10) ^ 0x80000000
                                                    ) - DOUBLE_00108d58);
                    local_ac = fVar6;
                    fVar9 = (float)((double)CONCAT44(0x43300000,
                                                     (int)*(short *)(puVar29 + 3) ^ 0x80000000) -
                                   DOUBLE_00108d58);
                    local_a8 = fVar9;
                    uStack_1ec = (int)*(short *)((int)puVar29 + 0xe) ^ 0x80000000;
                    fVar10 = (float)((double)CONCAT44(0x43300000,uStack_1ec) - DOUBLE_00108d58);
                    local_a4 = fVar10;
joined_r0x0003cdcc:
                    if (cVar3 == '\x04') {
LAB_0003cdd0:
                      local_1f0 = 0x43300000;
                      *(float *)(iVar27 + iVar11) = fVar8;
                    }
                    else {
joined_r0x0003cddc:
                      iVar14 = iVar27 + iVar11;
                      if (cVar3 == '\b') {
LAB_0003cde8:
                        local_1f0 = 0x43300000;
                        *(float *)(iVar27 + iVar11) = fVar8;
                        *(float *)(iVar14 + 4) = fVar6;
                      }
                      else if (cVar3 == '\f') {
LAB_0003ce08:
                        local_1f0 = 0x43300000;
                        *(float *)(iVar27 + iVar11) = fVar8;
                        *(float *)(iVar14 + 8) = fVar9;
                        *(float *)(iVar14 + 4) = fVar6;
                      }
                      else {
joined_r0x0003ce1c:
                        local_1f0 = 0x43300000;
                        if (cVar3 == '\x10') {
                          local_1f0 = 0x43300000;
                          *(float *)(iVar27 + iVar11) = fVar8;
                          *(float *)(iVar14 + 0xc) = fVar10;
                          *(float *)(iVar14 + 4) = fVar6;
                          *(float *)(iVar14 + 8) = fVar9;
                        }
                      }
                    }
LAB_0003ce40:
                    bVar2 = uVar30 == 0;
                    goto LAB_0003d080;
                  case 0x24:
                    local_98 = 0.0;
                    local_a0 = 0.0;
                    local_9c = 0.0;
                    local_94 = 1.0;
                    uVar30 = *puVar17;
                    iVar14 = aiStack_280[uVar30];
                    cVar3 = local_2d4[uVar30];
                    local_1f0 = 0x43300000;
                    iVar11 = iVar27 + iVar14;
                    local_a0 = (float)((double)CONCAT44(0x43300000,puVar29[2]) - DOUBLE_00108d70) *
                               FLOAT_00108e70 + FLOAT_00108e74;
                    fVar6 = (float)((double)CONCAT44(0x43300000,puVar29[3]) - DOUBLE_00108d70) *
                            FLOAT_00108e70 + FLOAT_00108e74;
                    local_9c = fVar6;
                    fVar9 = (float)((double)CONCAT44(0x43300000,puVar29[4]) - DOUBLE_00108d70) *
                            FLOAT_00108e70 + FLOAT_00108e74;
                    local_98 = fVar9;
                    uStack_1ec = puVar29[5];
                    fVar10 = (float)((double)CONCAT44(0x43300000,puVar29[5]) - DOUBLE_00108d70) *
                             FLOAT_00108e70 + FLOAT_00108e74;
                    local_94 = fVar10;
                    if (cVar3 == '\x04') {
                      *(float *)(iVar27 + iVar14) = local_a0;
                    }
                    else {
                      if (cVar3 == '\b') {
                        *(float *)(iVar27 + iVar14) = local_a0;
                        goto LAB_0003cf38;
                      }
                      if (cVar3 == '\f') {
                        *(float *)(iVar27 + iVar14) = local_a0;
                        goto LAB_0003cf58;
                      }
                      if (cVar3 == '\x10') {
                        *(float *)(iVar27 + iVar14) = local_a0;
                        goto LAB_0003cf80;
                      }
                    }
LAB_0003cf8c:
                    bVar2 = uVar30 == 0;
                    goto LAB_0003d080;
                  case 0x25:
                    local_88 = 0.0;
                    local_84 = 1.0;
                    local_90 = 0.0;
                    local_8c = 0.0;
                    uVar30 = *puVar17;
                    fVar6 = (float)*(double *)(puVar29 + 2);
                    cVar3 = local_2d4[uVar30];
                    local_90 = fVar6;
                    iVar11 = aiStack_280[uVar30];
                    fVar9 = (float)*(double *)(puVar29 + 4);
                    iVar14 = iVar27 + iVar11;
                    local_8c = fVar9;
                    fVar10 = (float)*(double *)(puVar29 + 6);
                    local_88 = fVar10;
                    fVar8 = (float)*(double *)(puVar29 + 8);
                    local_84 = fVar8;
                    if (cVar3 == '\x04') goto LAB_0003d00c;
                    if (cVar3 == '\b') goto LAB_0003d024;
                    if (cVar3 != '\f') goto joined_r0x0003d058;
LAB_0003d044:
                    *(float *)(iVar27 + iVar11) = fVar6;
LAB_0003d048:
                    *(float *)(iVar14 + 8) = fVar10;
                    *(float *)(iVar14 + 4) = fVar9;
                    break;
                  case 0x26:
                    uVar31 = *puVar17;
                    iVar11 = 0;
                    if (0 < (int)uVar31) {
                      do {
                        iVar14 = iVar11 + 1;
                        *(uint *)(iVar27 + iVar11 * 4 + local_2bc[4]) = puVar29[iVar11 + 2];
                        uVar31 = *puVar17;
                        iVar11 = iVar14;
                      } while (iVar14 < (int)uVar31);
                    }
                    if ((int)uVar31 < (int)(uint)(local_2d4[0] >> 2)) {
                      dstCursor = (undefined4 *)(iVar27 + uVar31 * 4 + local_2bc[4]);
                      do {
                        *dstCursor = 0;
                        uVar31 = uVar31 + 1;
                        dstCursor = dstCursor + 1;
                      } while ((int)uVar31 < (int)(uint)(local_2d4[0] >> 2));
                    }
                    goto switchD_0003b6b4_caseD_0;
                  case 0x27:
                    *(uint *)(iVar27 + local_2bc[2]) = *puVar17;
                    goto switchD_0003b6b4_caseD_0;
                  case 0x28:
                    iVar11 = local_2bc[3];
LAB_0003d134:
                    uVar31 = puVar29[3];
                    uVar30 = puVar29[2];
                    *(uint *)(iVar27 + iVar11) = *puVar17;
                    *(uint *)(iVar27 + iVar11 + 8) = uVar31;
                    *(uint *)(iVar27 + iVar11 + 4) = uVar30;
                    goto switchD_0003b6b4_caseD_0;
                  }
                  bVar2 = uVar30 == 0;
LAB_0003d080:
                  if (bVar2) {
                    uVar30 = uVar31 + 1;
                    unaff_cr4 = ((int)uVar30 < (int)uVar7) << 3 | ((int)uVar7 < (int)uVar30) << 2 |
                                (uVar30 == uVar7) << 1 | in_xer_so & 1;
LAB_0003d09c:
                    _memcpy(iVar27 + local_2c0 + (uint)(*(unsigned char *)((unsigned char *)&(local_2e4) + 0)),iVar27,local_2c0);
                    uVar25 = uVar31 + 1;
                  }
switchD_0003b6b4_caseD_0:
                  if ((undefined *)piVar15[1] == PTR__glWeightARB_ListExec_0011214c) {
                    puVar29 = puVar29 + puVar29[1] + 2;
                  }
                  else {
                    puVar29 = (uint *)((int)puVar29 + *(int *)(iVar24 + loopIndex * 4));
                  }
                  loopIndex = loopIndex + 1;
                  if (!(bool)(unaff_cr4 >> 3)) break;
                  uVar30 = local_2e4 >> 0x18;
                  uVar31 = uVar25;
                } while( true );
              }
              if (!(bool)((byte)(local_6c >> 0x1d) & 1)) {
                _memcpy(local_70,iVar27,local_2c0);
              }
              bVar2 = (bool)((unaff_cr3 & 2) >> 1);
            }
            puVar16 = (undefined *)*puVar29;
            iVar27 = 0;
            iVar11 = *(int *)(((uint)puVar16 & 0x7c) + _gleDisplayListFunctionHash);
            while ((iVar11 != 0 && (iVar27 = iVar11, puVar16 != *(undefined **)(iVar11 + 4)))) {
              iVar27 = *(int *)(iVar11 + 0xc);
              iVar11 = iVar27;
            }
            if ((puVar16 != PTR__glEnd_ListExec_0011212c) && (loopIndex < uVar23)) {
              srcCursor2 = (int *)(loopIndex * 4 + iVar24);
              do {
                if ((iVar27 == 0) ||
                   (*(undefined **)(iVar27 + 4) != PTR__glWeightARB_ListExec_0011214c)) {
                  puVar29 = (uint *)((int)puVar29 + *srcCursor2);
                }
                else {
                  puVar29 = puVar29 + puVar29[1] + 2;
                }
                puVar16 = (undefined *)*puVar29;
                iVar27 = 0;
                iVar11 = *(int *)(((uint)puVar16 & 0x7c) + _gleDisplayListFunctionHash);
                while ((iVar11 != 0 && (iVar27 = iVar11, puVar16 != *(undefined **)(iVar11 + 4)))) {
                  iVar27 = *(int *)(iVar11 + 0xc);
                  iVar11 = iVar27;
                }
                loopIndex = loopIndex + 1;
                srcCursor2 = srcCursor2 + 1;
              } while ((puVar16 != PTR__glEnd_ListExec_0011212c) && (loopIndex < uVar23));
            }
            if ((puVar16 == PTR__glEnd_ListExec_0011212c) && (loopIndex < uVar23)) {
              if ((iVar27 == 0) ||
                 (*(undefined **)(iVar27 + 4) != PTR__glWeightARB_ListExec_0011214c)) {
                puVar29 = (uint *)((int)puVar29 + *(int *)(iVar24 + loopIndex * 4));
              }
              else {
                puVar29 = puVar29 + puVar29[1] + 2;
              }
              loopIndex = loopIndex + 1;
            }
            if (!(bool)((byte)(local_6c >> 0x1d) & 1)) {
              _free(local_70);
            }
          }
          else {
            if (puVar16 != PTR__glDrawArraysOrElements_ListExec_00112144) {
              if (((puVar16 == PTR__glCallList_ListExec_00112138) ||
                  (puVar16 == PTR__glBindVertexArrayEXT_ListExec_00112134)) ||
                 (puVar16 == PTR__glVertexArrayParameteriEXT_ListExec_00112130)) {
                if (local_78 != (uint *)0x0) {
                  ((void (*)())_CloseCurrentVAR)(glContext,iVar12,puVar5,&local_78,&local_74);
                  puVar16 = (undefined *)*puVar29;
                }
                uVar13 = *(int *)(loopIndex * 4 + iVar24) - 4;
                listRecord = _gleAddListItem(glContext,puVar16,uVar13);
                iVar11 = 0;
                for (uVar13 = uVar13 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
                  *(uint *)(listRecord + iVar11 * 4) = puVar29[iVar11 + 1];
                  iVar11 = iVar11 + 1;
                }
                goto LAB_0003d534;
              }
              uVar13 = *(int *)(loopIndex * 4 + iVar24) - 4;
              listRecord = _gleAddListItem(glContext,puVar16,uVar13);
              iVar11 = 0;
              for (uVar13 = uVar13 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
                *(uint *)(listRecord + iVar11 * 4) = puVar29[iVar11 + 1];
                iVar11 = iVar11 + 1;
              }
              if (iVar27 != 0) {
                bVar1 = *(undefined **)(iVar27 + 4) == PTR__glWeightARB_ListExec_0011214c;
                goto LAB_0003d5ac;
              }
              goto LAB_0003d5c4;
            }
            iVar11 = 0x2c;
            iVar14 = puVar29[7] * puVar29[8];
            if (local_74 < iVar14 + 0x2c) {
              iVar11 = 0x40;
              if (local_78 != (uint *)0x0) {
                ((void (*)())_CloseCurrentVAR)(glContext,iVar12,puVar5,&local_78,&local_74);
              }
              piVar15 = (int *)((int (*)())_gleAddListItemWithFree)(glContext,
                                          PTR__gleSetupAndDrawArraysOrElementsOutOfLine_ListExec_00112140
                                          ,0x10,PTR__gleOptimizedListFreeFunc_00110ccc,4);
              local_74 = iVar14 + 0x40;
              iVar12 = (int)piVar15 - *(int *)(glContext + 0x53e8);
              if (local_74 < 0x100001) {
                local_74 = 0x100000;
                uVar13 = 0x100000;
              }
              else {
                uVar13 = (uint)(((unsigned char *)0x0000103f) + iVar14) & 0xfffff000;
              }
              _vm_allocate(*(vm_map_t *)PTR_00112034,(vm_address_t *)&local_78,uVar13,1);
              *piVar15 = (int)local_78;
              local_78[3] = uVar13;
              *(undefined4 *)*piVar15 = 4;
              *(uint *)*piVar15 = *(uint *)*piVar15 | 2;
              puVar5 = (uint *)(*piVar15 + 0x14);
              puVar22 = local_78;
            }
            else {
              listRecord2 = (int *)_gleAddListItem(glContext,
                                               PTR__gleDrawArraysOrElementsOutOfLine_ListExec_0011213c
                                               ,8);
              *listRecord2 = (int)listRecord2 + (-iVar12 - *(int *)(glContext + 0x53e8));
              listRecord2[1] = (int)puVar5 - (int)local_78;
            }
            local_74 = local_74 - (iVar14 + iVar11);
            puVar22 = (uint *)((int)puVar22 + iVar14 + iVar11);
            _memcpy(puVar5,puVar29 + 6,iVar14 + 0x2c);
            if ((iVar27 == 0) || (*(undefined **)(iVar27 + 4) != PTR__glWeightARB_ListExec_0011214c)
               ) {
              puVar29 = (uint *)((int)puVar29 + *(int *)(iVar24 + loopIndex * 4));
            }
            else {
LAB_0003d5b0:
              puVar29 = puVar29 + puVar29[1] + 2;
            }
LAB_0003d5cc:
            loopIndex = loopIndex + 1;
          }
          puVar5 = puVar22;
        } while (loopIndex < uVar23);
      }
      if (local_78 != (uint *)0x0) {
        ((void (*)())_CloseCurrentVAR)(glContext,iVar12,puVar22,&local_78,&local_74);
      }
      sharedState = *(int *)(glContext + 0x5148);
      *(undefined4 *)(glContext + 0x5408) = 0;
      iVar24 = sharedState + 0x300c;
      if (*(char *)(sharedState + 0x8024) != '\0') {
        _pthread_mutex_lock(sharedState + 0x8028);
      }
      glContextPtr53e8 = *(int *)(glContext + 0x53e8);
      iVar12 = ((int (*)())_gleIsHashName)(iVar24,*(undefined4 *)(glContextPtr53e8 + 4));
      if (iVar12 == 0) {
        _gleAddHashNameAndObject(glContext,iVar24,glContextPtr53e8);
      }
      else {
        iVar12 = _gleRemoveHashObject(iVar24,*(undefined4 *)(glContextPtr53e8 + 4));
        if ((iVar12 != 0) &&
           (iVar11 = *(int *)(iVar12 + 8) + -1, *(int *)(iVar12 + 8) = iVar11, iVar11 == 0)) {
          if (*(int *)(iVar12 + 0x14) != 0) {
            _free(*(int *)(iVar12 + 0x14));
          }
          _free(iVar12);
        }
        _gleAddHashObject(iVar24,glContextPtr53e8);
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
    }
  }
  return;
}

/* _gliCompDispatchTable @ 0x3d6d4 (22328 bytes) */
int _gliCompDispatchTable(glContext)
  int glContext;
{
  uint emptySlotMask;
  
  emptySlotMask = -(uint)(**(int **)(glContext + 0x4684) == 0);
  *(undefined **)(*(uint *)(glContext + 0x4680) & emptySlotMask | (uint)*(int **)(glContext + 0x4684) & ~emptySlotMask)
       = PTR__glAccum_Comp_001133cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 4) == 0);
  *(undefined **)((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 4)
       = PTR__glAlphaFunc_Comp_001133c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xc) =
       PTR__glArrayElement_Comp_001133c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x10) =
       PTR__glBegin_Comp_001122e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x14) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x14) =
       PTR__glBindTexture_Comp_001133c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x18) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x18) =
       PTR__glBitmap_Comp_001133bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x1c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x1c) =
       PTR__glBlendFunc_Comp_001133b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x20) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x20) =
       PTR__glCallList_Comp_001133b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x24) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x24) =
       PTR__glCallLists_Comp_001133b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x28) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x28) =
       PTR__glClear_Comp_001133ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2c) =
       PTR__glClearAccum_Comp_001133a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x30) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x30) =
       PTR__glClearColor_Comp_001133a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x34) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x34) =
       PTR__glClearDepth_Comp_001133a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x38) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x38) =
       PTR__glClearIndex_Comp_0011339c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c) =
       PTR__glClearStencil_Comp_00113398;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x40) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x40) =
       PTR__glClipPlane_Comp_00113394;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x44) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x44) =
       PTR__glColor3b_Comp_00113390;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x48) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x48) =
       PTR__glColor3bv_Comp_0011338c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c) =
       PTR__glColor3d_Comp_00113388;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x50) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x50) =
       PTR__glColor3dv_Comp_00113384;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x54) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x54) =
       PTR__glColor3f_Comp_00113380;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x58) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x58) =
       PTR__glColor3fv_Comp_0011337c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c) =
       PTR__glColor3i_Comp_00113378;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x60) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x60) =
       PTR__glColor3iv_Comp_00113374;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 100) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 100) =
       PTR__glColor3s_Comp_00113370;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x68) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x68) =
       PTR__glColor3sv_Comp_0011336c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6c) =
       PTR__glColor3ub_Comp_00113368;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x70) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x70) =
       PTR__glColor3ubv_Comp_00113364;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x74) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x74) =
       PTR__glColor3ui_Comp_00113360;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x78) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x78) =
       PTR__glColor3uiv_Comp_0011335c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c) =
       PTR__glColor3us_Comp_00113358;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x80) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x80) =
       PTR__glColor3usv_Comp_00113354;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x84) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x84) =
       PTR__glColor4b_Comp_00113350;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x88) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x88) =
       PTR__glColor4bv_Comp_0011334c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c) =
       PTR__glColor4d_Comp_00113348;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x90) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x90) =
       PTR__glColor4dv_Comp_00113344;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x94) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x94) =
       PTR__glColor4f_Comp_00113340;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x98) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x98) =
       PTR__glColor4fv_Comp_0011333c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9c) =
       PTR__glColor4i_Comp_00113338;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa0) =
       PTR__glColor4iv_Comp_00113334;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa4) =
       PTR__glColor4s_Comp_00113330;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa8) =
       PTR__glColor4sv_Comp_0011332c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xac) =
       PTR__glColor4ub_Comp_00113328;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xb0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xb0) =
       PTR__glColor4ubv_Comp_00113324;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xb4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xb4) =
       PTR__glColor4ui_Comp_00113320;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xb8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xb8) =
       PTR__glColor4uiv_Comp_0011331c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xbc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xbc) =
       PTR__glColor4us_Comp_00113318;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xc0) =
       PTR__glColor4usv_Comp_00113314;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xc4) =
       PTR__glColorMask_Comp_00113310;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 200) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 200) =
       PTR__glColorMaterial_Comp_0011330c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xd0) =
       PTR__glCopyPixels_Comp_00113308;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xd4) =
       PTR__glCopyTexImage1D_Comp_00113304;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xd8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xd8) =
       PTR__glCopyTexImage2D_Comp_00113300;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xdc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xdc) =
       PTR__glCopyTexSubImage1D_Comp_001132fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xe0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xe0) =
       PTR__glCopyTexSubImage2D_Comp_001132f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xe4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xe4) =
       PTR__glCullFace_Comp_001132f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xf0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xf0) =
       PTR__glDepthFunc_Comp_001132f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xf4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xf4) =
       PTR__glDepthMask_Comp_001132ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xf8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xf8) =
       PTR__glDepthRange_Comp_001132e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xfc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xfc) =
       PTR__glDisable_Comp_001132e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x104) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x104) =
       PTR__glDrawArrays_Comp_001132e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x108) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x108) =
       PTR__glDrawBuffer_Comp_001132dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x10c) =
       PTR__glDrawElements_Comp_001132d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x110) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x110) =
       PTR__glDrawPixels_Comp_001132d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x114) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x114) =
       PTR__glEdgeFlag_Comp_001132d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x11c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x11c) =
       PTR__glEdgeFlagv_Comp_001132cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x120) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x120) =
       PTR__glEnable_Comp_001132c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x128) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x128) =
       PTR__glEnd_Comp_00112388;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x130) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x130) =
       PTR__glEvalCoord1d_Comp_001132c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x134) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x134) =
       PTR__glEvalCoord1dv_Comp_001132c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x138) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x138) =
       PTR__glEvalCoord1f_Comp_001132bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x13c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x13c) =
       PTR__glEvalCoord1fv_Comp_001132b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x140) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x140) =
       PTR__glEvalCoord2d_Comp_001132b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x144) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x144) =
       PTR__glEvalCoord2dv_Comp_001132b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x148) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x148) =
       PTR__glEvalCoord2f_Comp_001132ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x14c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x14c) =
       PTR__glEvalCoord2fv_Comp_001132a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x150) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x150) =
       PTR__glEvalMesh1_Comp_001132a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x154) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x154) =
       PTR__glEvalMesh2_Comp_001132a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x158) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x158) =
       PTR__glEvalPoint1_Comp_0011329c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x15c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x15c) =
       PTR__glEvalPoint2_Comp_00113298;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x16c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x16c) =
       PTR__glFogf_Comp_00113294;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x170) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x170) =
       PTR__glFogfv_Comp_00113290;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x174) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x174) =
       PTR__glFogi_Comp_0011328c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x178) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x178) =
       PTR__glFogiv_Comp_00113288;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x17c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x17c) =
       PTR__glFrontFace_Comp_00113284;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x180) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x180) =
       PTR__glFrustum_Comp_00113280;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x200) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x200) =
       PTR__glHint_Comp_0011327c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x204) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x204) =
       PTR__glIndexMask_Comp_00113278;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x20c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x20c) =
       PTR__glIndexd_Comp_00113274;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x210) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x210) =
       PTR__glIndexdv_Comp_00113270;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x214) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x214) =
       PTR__glIndexf_Comp_0011326c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x218) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x218) =
       PTR__glIndexfv_Comp_00113268;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x21c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x21c) =
       PTR__glIndexi_Comp_00113264;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x220) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x220) =
       PTR__glIndexiv_Comp_00113260;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x224) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x224) =
       PTR__glIndexs_Comp_0011325c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x228) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x228) =
       PTR__glIndexsv_Comp_00113258;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x22c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x22c) =
       PTR__glIndexub_Comp_00113254;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x230) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x230) =
       PTR__glIndexubv_Comp_00113250;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x234) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x234) =
       PTR__glInitNames_Comp_0011324c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x248) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x248) =
       PTR__glLightModelf_Comp_00113248;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x24c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x24c) =
       PTR__glLightModelfv_Comp_00113244;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x250) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x250) =
       PTR__glLightModeli_Comp_00113240;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x254) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x254) =
       PTR__glLightModeliv_Comp_0011323c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 600) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 600) =
       PTR__glLightf_Comp_00113238;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x25c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x25c) =
       PTR__glLightfv_Comp_00113234;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x260) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x260) =
       PTR__glLighti_Comp_00113230;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x264) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x264) =
       PTR__glLightiv_Comp_0011322c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x268) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x268) =
       PTR__glLineStipple_Comp_00113228;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x26c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x26c) =
       PTR__glLineWidth_Comp_00113224;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x270) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x270) =
       PTR__glListBase_Comp_00113220;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x274) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x274) =
       PTR__glLoadIdentity_Comp_0011321c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x278) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x278) =
       PTR__glLoadMatrixd_Comp_00113218;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x27c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x27c) =
       PTR__glLoadMatrixf_Comp_00113214;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x280) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x280) =
       PTR__glLoadName_Comp_00113210;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x284) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x284) =
       PTR__glLogicOp_Comp_0011320c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x288) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x288) =
       PTR__glMap1d_Comp_00113208;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x28c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x28c) =
       PTR__glMap1f_Comp_00113204;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x290) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x290) =
       PTR__glMap2d_Comp_00113200;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x294) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x294) =
       PTR__glMap2f_Comp_001131fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x298) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x298) =
       PTR__glMapGrid1d_Comp_001131f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x29c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x29c) =
       PTR__glMapGrid1f_Comp_001131f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2a0) =
       PTR__glMapGrid2d_Comp_001131f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2a4) =
       PTR__glMapGrid2f_Comp_001131ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2a8) =
       PTR__glMaterialf_Comp_001131e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2ac) =
       PTR__glMaterialfv_Comp_001131e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2b0) =
       PTR__glMateriali_Comp_001131e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2b4) =
       PTR__glMaterialiv_Comp_001131dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2b8) =
       PTR__glMatrixMode_Comp_001131d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 700) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 700) =
       PTR__glMultMatrixd_Comp_001131d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2c0) =
       PTR__glMultMatrixf_Comp_001131d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2c8) =
       PTR__glNormal3b_Comp_001131cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2cc) =
       PTR__glNormal3bv_Comp_001131c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2d0) =
       PTR__glNormal3d_Comp_001131c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2d4) =
       PTR__glNormal3dv_Comp_001131c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2d8) =
       PTR__glNormal3f_Comp_001131bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2dc) =
       PTR__glNormal3fv_Comp_001131b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2e0) =
       PTR__glNormal3i_Comp_001131b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2e4) =
       PTR__glNormal3iv_Comp_001131b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2e8) =
       PTR__glNormal3s_Comp_001131ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2ec) =
       PTR__glNormal3sv_Comp_001131a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2f4) =
       PTR__glOrtho_Comp_001131a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2f8) =
       PTR__glPassThrough_Comp_001131a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x2fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x2fc) =
       PTR__glPixelMapfv_Comp_0011319c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x300) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x300) =
       PTR__glPixelMapuiv_Comp_00113198;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x304) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x304) =
       PTR__glPixelMapusv_Comp_00113194;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x310) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x310) =
       PTR__glPixelTransferf_Comp_00113190;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x314) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x314) =
       PTR__glPixelTransferi_Comp_0011318c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x318) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x318) =
       PTR__glPixelZoom_Comp_00113188;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x31c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x31c) =
       PTR__glPointSize_Comp_00113184;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 800) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 800) =
       PTR__glPolygonMode_Comp_00113180;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x324) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x324) =
       PTR__glPolygonOffset_Comp_0011317c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x328) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x328) =
       PTR__glPolygonStipple_Comp_00113178;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x32c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x32c) =
       PTR__glPopAttrib_Comp_00113174;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x334) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x334) =
       PTR__glPopMatrix_Comp_00113170;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x338) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x338) =
       PTR__glPopName_Comp_0011316c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x33c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x33c) =
       PTR__glPrioritizeTextures_Comp_00113168;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x340) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x340) =
       PTR__glPushAttrib_Comp_00113164;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x348) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x348) =
       PTR__glPushMatrix_Comp_00113160;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x34c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x34c) =
       PTR__glPushName_Comp_0011315c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x350) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x350) =
       PTR__glRasterPos2d_Comp_00113158;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x354) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x354) =
       PTR__glRasterPos2dv_Comp_00113154;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x358) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x358) =
       PTR__glRasterPos2f_Comp_00113150;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x35c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x35c) =
       PTR__glRasterPos2fv_Comp_0011314c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x360) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x360) =
       PTR__glRasterPos2i_Comp_00113148;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x364) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x364) =
       PTR__glRasterPos2iv_Comp_00113144;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x368) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x368) =
       PTR__glRasterPos2s_Comp_00113140;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x36c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x36c) =
       PTR__glRasterPos2sv_Comp_0011313c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x370) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x370) =
       PTR__glRasterPos3d_Comp_00113138;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x374) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x374) =
       PTR__glRasterPos3dv_Comp_00113134;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x378) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x378) =
       PTR__glRasterPos3f_Comp_00113130;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x37c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x37c) =
       PTR__glRasterPos3fv_Comp_0011312c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x380) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x380) =
       PTR__glRasterPos3i_Comp_00113128;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 900) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 900) =
       PTR__glRasterPos3iv_Comp_00113124;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x388) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x388) =
       PTR__glRasterPos3s_Comp_00113120;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x38c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x38c) =
       PTR__glRasterPos3sv_Comp_0011311c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x390) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x390) =
       PTR__glRasterPos4d_Comp_00113118;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x394) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x394) =
       PTR__glRasterPos4dv_Comp_00113114;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x398) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x398) =
       PTR__glRasterPos4f_Comp_00113110;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x39c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x39c) =
       PTR__glRasterPos4fv_Comp_0011310c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3a0) =
       PTR__glRasterPos4i_Comp_00113108;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3a4) =
       PTR__glRasterPos4iv_Comp_00113104;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3a8) =
       PTR__glRasterPos4s_Comp_00113100;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3ac) =
       PTR__glRasterPos4sv_Comp_001130fc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3b0) =
       PTR__glReadBuffer_Comp_001130f8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3b8) =
       PTR__glRectd_Comp_001130f4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3bc) =
       PTR__glRectdv_Comp_001130f0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c0) =
       PTR__glRectf_Comp_001130ec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c4) =
       PTR__glRectfv_Comp_001130e8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3c8) =
       PTR__glRecti_Comp_001130e4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3cc) =
       PTR__glRectiv_Comp_001130e0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3d0) =
       PTR__glRects_Comp_001130dc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3d4) =
       PTR__glRectsv_Comp_001130d8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3dc) =
       PTR__glRotated_Comp_001130d4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3e0) =
       PTR__glRotatef_Comp_001130d0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3e4) =
       PTR__glScaled_Comp_001130cc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 1000) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 1000) =
       PTR__glScalef_Comp_001130c8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3ec) =
       PTR__glScissor_Comp_001130c4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3f4) =
       PTR__glShadeModel_Comp_001130c0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3f8) =
       PTR__glStencilFunc_Comp_001130bc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x3fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x3fc) =
       PTR__glStencilMask_Comp_001130b8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x400) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x400) =
       PTR__glStencilOp_Comp_001130b4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x404) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x404) =
       PTR__glTexCoord1d_Comp_001130b0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x408) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x408) =
       PTR__glTexCoord1dv_Comp_001130ac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x40c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x40c) =
       PTR__glTexCoord1f_Comp_001130a8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x410) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x410) =
       PTR__glTexCoord1fv_Comp_001130a4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x414) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x414) =
       PTR__glTexCoord1i_Comp_001130a0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x418) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x418) =
       PTR__glTexCoord1iv_Comp_0011309c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x41c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x41c) =
       PTR__glTexCoord1s_Comp_00113098;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x420) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x420) =
       PTR__glTexCoord1sv_Comp_00113094;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x424) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x424) =
       PTR__glTexCoord2d_Comp_00113090;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x428) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x428) =
       PTR__glTexCoord2dv_Comp_0011308c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x42c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x42c) =
       PTR__glTexCoord2f_Comp_00113088;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x430) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x430) =
       PTR__glTexCoord2fv_Comp_00113084;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x434) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x434) =
       PTR__glTexCoord2i_Comp_00113080;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x438) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x438) =
       PTR__glTexCoord2iv_Comp_0011307c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x43c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x43c) =
       PTR__glTexCoord2s_Comp_00113078;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x440) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x440) =
       PTR__glTexCoord2sv_Comp_00113074;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x444) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x444) =
       PTR__glTexCoord3d_Comp_00113070;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x448) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x448) =
       PTR__glTexCoord3dv_Comp_0011306c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x44c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x44c) =
       PTR__glTexCoord3f_Comp_00113068;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x450) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x450) =
       PTR__glTexCoord3fv_Comp_00113064;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x454) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x454) =
       PTR__glTexCoord3i_Comp_00113060;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x458) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x458) =
       PTR__glTexCoord3iv_Comp_0011305c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x45c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x45c) =
       PTR__glTexCoord3s_Comp_00113058;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x460) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x460) =
       PTR__glTexCoord3sv_Comp_00113054;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x464) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x464) =
       PTR__glTexCoord4d_Comp_00113050;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x468) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x468) =
       PTR__glTexCoord4dv_Comp_0011304c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x46c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x46c) =
       PTR__glTexCoord4f_Comp_00113048;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x470) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x470) =
       PTR__glTexCoord4fv_Comp_00113044;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x474) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x474) =
       PTR__glTexCoord4i_Comp_00113040;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x478) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x478) =
       PTR__glTexCoord4iv_Comp_0011303c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x47c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x47c) =
       PTR__glTexCoord4s_Comp_00113038;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x480) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x480) =
       PTR__glTexCoord4sv_Comp_00113034;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x488) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x488) =
       PTR__glTexEnvf_Comp_00113030;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x48c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x48c) =
       PTR__glTexEnvfv_Comp_0011302c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x490) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x490) =
       PTR__glTexEnvi_Comp_00113028;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x494) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x494) =
       PTR__glTexEnviv_Comp_00113024;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x498) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x498) =
       PTR__glTexGend_Comp_00113020;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x49c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x49c) =
       PTR__glTexGendv_Comp_0011301c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4a0) =
       PTR__glTexGenf_Comp_00113018;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4a4) =
       PTR__glTexGenfv_Comp_00113014;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4a8) =
       PTR__glTexGeni_Comp_00113010;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4ac) =
       PTR__glTexGeniv_Comp_0011300c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4b0) =
       PTR__glTexImage1D_Comp_00113008;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4b4) =
       PTR__glTexImage2D_Comp_00113004;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4b8) =
       PTR__glTexParameterf_Comp_00113000;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4bc) =
       PTR__glTexParameterfv_Comp_00112ffc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c0) =
       PTR__glTexParameteri_Comp_00112ff8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c4) =
       PTR__glTexParameteriv_Comp_00112ff4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4c8) =
       PTR__glTexSubImage1D_Comp_00112ff0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4cc) =
       PTR__glTexSubImage2D_Comp_00112fec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4d0) =
       PTR__glTranslated_Comp_00112fe8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4d4) =
       PTR__glTranslatef_Comp_00112fe4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4d8) =
       PTR__glVertex2d_Comp_00112fe0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4dc) =
       PTR__glVertex2dv_Comp_00112fdc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4e0) =
       PTR__glVertex2f_Comp_00112fd8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4e4) =
       PTR__glVertex2fv_Comp_00112fd4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4e8) =
       PTR__glVertex2i_Comp_00112fd0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4ec) =
       PTR__glVertex2iv_Comp_00112fcc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4f0) =
       PTR__glVertex2s_Comp_00112fc8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4f4) =
       PTR__glVertex2sv_Comp_00112fc4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4f8) =
       PTR__glVertex3d_Comp_00112fc0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x4fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x4fc) =
       PTR__glVertex3dv_Comp_00112fbc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x500) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x500) =
       PTR__glVertex3f_Comp_00112fb8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x504) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x504) =
       PTR__glVertex3fv_Comp_00112fb4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x508) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x508) =
       PTR__glVertex3i_Comp_00112fb0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x50c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x50c) =
       PTR__glVertex3iv_Comp_00112fac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x510) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x510) =
       PTR__glVertex3s_Comp_00112fa8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x514) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x514) =
       PTR__glVertex3sv_Comp_00112fa4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x518) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x518) =
       PTR__glVertex4d_Comp_00112fa0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x51c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x51c) =
       PTR__glVertex4dv_Comp_00112f9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x520) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x520) =
       PTR__glVertex4f_Comp_00112f98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x524) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x524) =
       PTR__glVertex4fv_Comp_00112f94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x528) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x528) =
       PTR__glVertex4i_Comp_00112f90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x52c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x52c) =
       PTR__glVertex4iv_Comp_00112f8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x530) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x530) =
       PTR__glVertex4s_Comp_00112f88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x534) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x534) =
       PTR__glVertex4sv_Comp_00112f84;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x53c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x53c) =
       PTR__glViewport_Comp_00112f80;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x544) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x544) =
       PTR__glBlendColor_Comp_00112f7c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x548) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x548) =
       PTR__glBlendEquation_Comp_00112f78;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x558) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x558) =
       PTR__glActiveTexture_Comp_00112f74;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x55c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x55c) =
       PTR__glMultiTexCoord1d_Comp_00112f70;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x560) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x560) =
       PTR__glMultiTexCoord1dv_Comp_00112f6c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x564) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x564) =
       PTR__glMultiTexCoord1f_Comp_00112f68;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x568) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x568) =
       PTR__glMultiTexCoord1fv_Comp_00112f64;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x56c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x56c) =
       PTR__glMultiTexCoord1i_Comp_00112f60;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x570) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x570) =
       PTR__glMultiTexCoord1iv_Comp_00112f5c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x574) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x574) =
       PTR__glMultiTexCoord1s_Comp_00112f58;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x578) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x578) =
       PTR__glMultiTexCoord1sv_Comp_00112f54;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x57c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x57c) =
       PTR__glMultiTexCoord2d_Comp_00112f50;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x580) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x580) =
       PTR__glMultiTexCoord2dv_Comp_00112f4c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x584) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x584) =
       PTR__glMultiTexCoord2f_Comp_00112f48;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x588) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x588) =
       PTR__glMultiTexCoord2fv_Comp_00112f44;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x58c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x58c) =
       PTR__glMultiTexCoord2i_Comp_00112f40;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x590) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x590) =
       PTR__glMultiTexCoord2iv_Comp_00112f3c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x594) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x594) =
       PTR__glMultiTexCoord2s_Comp_00112f38;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x598) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x598) =
       PTR__glMultiTexCoord2sv_Comp_00112f34;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x59c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x59c) =
       PTR__glMultiTexCoord3d_Comp_00112f30;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5a0) =
       PTR__glMultiTexCoord3dv_Comp_00112f2c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5a4) =
       PTR__glMultiTexCoord3f_Comp_00112f28;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5a8) =
       PTR__glMultiTexCoord3fv_Comp_00112f24;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5ac) =
       PTR__glMultiTexCoord3i_Comp_00112f20;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5b0) =
       PTR__glMultiTexCoord3iv_Comp_00112f1c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5b4) =
       PTR__glMultiTexCoord3s_Comp_00112f18;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5b8) =
       PTR__glMultiTexCoord3sv_Comp_00112f14;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5bc) =
       PTR__glMultiTexCoord4d_Comp_00112f10;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c0) =
       PTR__glMultiTexCoord4dv_Comp_00112f0c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c4) =
       PTR__glMultiTexCoord4f_Comp_00112f08;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5c8) =
       PTR__glMultiTexCoord4fv_Comp_00112f04;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5cc) =
       PTR__glMultiTexCoord4i_Comp_00112f00;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5d0) =
       PTR__glMultiTexCoord4iv_Comp_00112efc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5d4) =
       PTR__glMultiTexCoord4s_Comp_00112ef8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5d8) =
       PTR__glMultiTexCoord4sv_Comp_00112ef4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5dc) =
       PTR__glLoadTransposeMatrixd_Comp_00112ef0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5e0) =
       PTR__glLoadTransposeMatrixf_Comp_00112eec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5e4) =
       PTR__glMultTransposeMatrixd_Comp_00112ee8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5e8) =
       PTR__glMultTransposeMatrixf_Comp_00112ee4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x654) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x654) =
       PTR__glDrawRangeElements_Comp_00112ee0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6d8) =
       PTR__glTexImage3D_Comp_00112edc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6dc) =
       PTR__glTexSubImage3D_Comp_00112ed8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6e0) =
       PTR__glCopyTexSubImage3D_Comp_00112ed4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x658) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x658) =
       PTR__glColorTable_Comp_00112ed0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x65c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x65c) =
       PTR__glColorTableParameterfv_Comp_00112ecc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x660) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x660) =
       PTR__glColorTableParameteriv_Comp_00112ec8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x664) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x664) =
       PTR__glCopyColorTable_Comp_00112ec4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x674) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x674) =
       PTR__glColorSubTable_Comp_00112ec0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x678) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x678) =
       PTR__glCopyColorSubTable_Comp_00112ebc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x67c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x67c) =
       PTR__glConvolutionFilter1D_Comp_00112eb8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x680) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x680) =
       PTR__glConvolutionFilter2D_Comp_00112eb4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x684) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x684) =
       PTR__glConvolutionParameterf_Comp_00112eb0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x688) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x688) =
       PTR__glConvolutionParameterfv_Comp_00112eac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x68c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x68c) =
       PTR__glConvolutionParameteri_Comp_00112ea8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x690) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x690) =
       PTR__glConvolutionParameteriv_Comp_00112ea4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x694) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x694) =
       PTR__glCopyConvolutionFilter1D_Comp_00112ea0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x698) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x698) =
       PTR__glCopyConvolutionFilter2D_Comp_00112e9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6ac) =
       PTR__glSeparableFilter2D_Comp_00112e98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6c8) =
       PTR__glHistogram_Comp_00112e94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6cc) =
       PTR__glMinmax_Comp_00112e90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6d0) =
       PTR__glResetHistogram_Comp_00112e8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6d4) =
       PTR__glResetMinmax_Comp_00112e88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5ec) =
       PTR__glCompressedTexImage3D_Comp_00112e84;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5f0) =
       PTR__glCompressedTexImage2D_Comp_00112e80;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5f4) =
       PTR__glCompressedTexImage1D_Comp_00112e7c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5f8) =
       PTR__glCompressedTexSubImage3D_Comp_00112e78;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x5fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x5fc) =
       PTR__glCompressedTexSubImage2D_Comp_00112e74;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x600) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x600) =
       PTR__glCompressedTexSubImage1D_Comp_00112e70;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x608) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x608) =
       PTR__glSecondaryColor3b_Comp_00112e6c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x60c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x60c) =
       PTR__glSecondaryColor3bv_Comp_00112e68;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x610) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x610) =
       PTR__glSecondaryColor3d_Comp_00112e64;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x614) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x614) =
       PTR__glSecondaryColor3dv_Comp_00112e60;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x618) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x618) =
       PTR__glSecondaryColor3f_Comp_00112e5c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x61c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x61c) =
       PTR__glSecondaryColor3fv_Comp_00112e58;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x620) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x620) =
       PTR__glSecondaryColor3i_Comp_00112e54;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x624) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x624) =
       PTR__glSecondaryColor3iv_Comp_00112e50;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x628) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x628) =
       PTR__glSecondaryColor3s_Comp_00112e4c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x62c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x62c) =
       PTR__glSecondaryColor3sv_Comp_00112e48;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x630) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x630) =
       PTR__glSecondaryColor3ub_Comp_00112e44;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x634) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x634) =
       PTR__glSecondaryColor3ubv_Comp_00112e40;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x638) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x638) =
       PTR__glSecondaryColor3ui_Comp_00112e3c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x63c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x63c) =
       PTR__glSecondaryColor3uiv_Comp_00112e38;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x640) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x640) =
       PTR__glSecondaryColor3us_Comp_00112e34;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x644) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x644) =
       PTR__glSecondaryColor3usv_Comp_00112e30;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x72c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x72c) =
       PTR__glSampleCoverage_Comp_00112e2c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x730) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x730) =
       PTR__glSamplePass_Comp_00112e28;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8e4) =
       PTR__glWindowPos2d_Comp_00112e24;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8e8) =
       PTR__glWindowPos2dv_Comp_00112e20;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8ec) =
       PTR__glWindowPos2f_Comp_00112e1c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8f0) =
       PTR__glWindowPos2fv_Comp_00112e18;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8f4) =
       PTR__glWindowPos2i_Comp_00112e14;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8f8) =
       PTR__glWindowPos2iv_Comp_00112e10;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8fc) =
       PTR__glWindowPos2s_Comp_00112e0c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x900) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x900) =
       PTR__glWindowPos2sv_Comp_00112e08;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x904) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x904) =
       PTR__glWindowPos3d_Comp_00112e04;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x908) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x908) =
       PTR__glWindowPos3dv_Comp_00112e00;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x90c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x90c) =
       PTR__glWindowPos3f_Comp_00112dfc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x910) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x910) =
       PTR__glWindowPos3fv_Comp_00112df8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x914) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x914) =
       PTR__glWindowPos3i_Comp_00112df4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x918) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x918) =
       PTR__glWindowPos3iv_Comp_00112df0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x91c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x91c) =
       PTR__glWindowPos3s_Comp_00112dec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x920) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x920) =
       PTR__glWindowPos3sv_Comp_00112de8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x894) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x894) =
       PTR__glVertexArrayParameteriEXT_Comp_00112de4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6e4) =
       PTR__glCombinerParameterfvNV_Comp_00112de0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6e8) =
       PTR__glCombinerParameterfNV_Comp_00112ddc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6ec) =
       PTR__glCombinerParameterivNV_Comp_00112dd8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6f0) =
       PTR__glCombinerParameteriNV_Comp_00112dd4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6f4) =
       PTR__glCombinerInputNV_Comp_00112dd0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6f8) =
       PTR__glCombinerOutputNV_Comp_00112dcc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x6fc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x6fc) =
       PTR__glFinalCombinerInputNV_Comp_00112dc8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x718) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x718) =
       PTR__glCombinerStageParameterfvNV_Comp_00112dc4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x738) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x738) =
       PTR__glPNTrianglesfATIX_Comp_00112dc0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x734) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x734) =
       PTR__glPNTrianglesiATIX_Comp_00112dbc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x75c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x75c) =
       PTR__glBindProgramARB_Comp_00112db8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x76c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x76c) =
       PTR__glVertexAttrib1sARB_Comp_00112db4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x770) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x770) =
       PTR__glVertexAttrib1fARB_Comp_00112db0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x774) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x774) =
       PTR__glVertexAttrib1dARB_Comp_00112dac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x778) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x778) =
       PTR__glVertexAttrib2sARB_Comp_00112da8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x77c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x77c) =
       PTR__glVertexAttrib2fARB_Comp_00112da4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x780) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x780) =
       PTR__glVertexAttrib2dARB_Comp_00112da0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x784) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x784) =
       PTR__glVertexAttrib3sARB_Comp_00112d9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x788) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x788) =
       PTR__glVertexAttrib3fARB_Comp_00112d98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x78c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x78c) =
       PTR__glVertexAttrib3dARB_Comp_00112d94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x790) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x790) =
       PTR__glVertexAttrib4sARB_Comp_00112d90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x794) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x794) =
       PTR__glVertexAttrib4fARB_Comp_00112d8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x798) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x798) =
       PTR__glVertexAttrib4dARB_Comp_00112d88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x79c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x79c) =
       PTR__glVertexAttrib4NubARB_Comp_00112d84;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7a0) =
       PTR__glVertexAttrib1svARB_Comp_00112d80;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7a4) =
       PTR__glVertexAttrib1fvARB_Comp_00112d7c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7a8) =
       PTR__glVertexAttrib1dvARB_Comp_00112d78;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7ac) =
       PTR__glVertexAttrib2svARB_Comp_00112d74;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7b0) =
       PTR__glVertexAttrib2fvARB_Comp_00112d70;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7b4) =
       PTR__glVertexAttrib2dvARB_Comp_00112d6c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7b8) =
       PTR__glVertexAttrib3svARB_Comp_00112d68;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7bc) =
       PTR__glVertexAttrib3fvARB_Comp_00112d64;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c0) =
       PTR__glVertexAttrib3dvARB_Comp_00112d60;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c4) =
       PTR__glVertexAttrib4bvARB_Comp_00112d5c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7c8) =
       PTR__glVertexAttrib4svARB_Comp_00112d58;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7cc) =
       PTR__glVertexAttrib4ivARB_Comp_00112d54;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 2000) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 2000) =
       PTR__glVertexAttrib4ubvARB_Comp_00112d50;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7d4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7d4) =
       PTR__glVertexAttrib4usvARB_Comp_00112d4c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7d8) =
       PTR__glVertexAttrib4uivARB_Comp_00112d48;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7dc) =
       PTR__glVertexAttrib4fvARB_Comp_00112d44;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7e0) =
       PTR__glVertexAttrib4dvARB_Comp_00112d40;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7e4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7e4) =
       PTR__glVertexAttrib4NbvARB_Comp_00112d3c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7e8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7e8) =
       PTR__glVertexAttrib4NsvARB_Comp_00112d38;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7ec) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7ec) =
       PTR__glVertexAttrib4NivARB_Comp_00112d34;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7f0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7f0) =
       PTR__glVertexAttrib4NubvARB_Comp_00112d30;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7f4) =
       PTR__glVertexAttrib4NusvARB_Comp_00112d2c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x7f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x7f8) =
       PTR__glVertexAttrib4NuivARB_Comp_00112d28;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x818) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x818) =
       PTR__glProgramEnvParameter4dARB_Comp_00112d24;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x81c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x81c) =
       PTR__glProgramEnvParameter4dvARB_Comp_00112d20;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x820) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x820) =
       PTR__glProgramEnvParameter4fARB_Comp_00112d1c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x824) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x824) =
       PTR__glProgramEnvParameter4fvARB_Comp_00112d18;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x828) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x828) =
       PTR__glProgramLocalParameter4dARB_Comp_00112d14;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x82c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x82c) =
       PTR__glProgramLocalParameter4dvARB_Comp_00112d10;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x830) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x830) =
       PTR__glProgramLocalParameter4fARB_Comp_00112d0c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x834) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x834) =
       PTR__glProgramLocalParameter4fvARB_Comp_00112d08;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x848) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x848) =
       PTR__glProgramStringARB_Comp_00112d04;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x854) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x854) =
       PTR__glEnableVertexAttribARB_Comp_00112d00;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x858) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x858) =
       PTR__glDisableVertexAttribARB_Comp_00112cfc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x860) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x860) =
       PTR__glMapVertexAttrib1dARB_Comp_00112cf8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x864) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x864) =
       PTR__glMapVertexAttrib1fARB_Comp_00112cf4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x868) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x868) =
       PTR__glMapVertexAttrib2dARB_Comp_00112cf0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x86c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x86c) =
       PTR__glMapVertexAttrib2fARB_Comp_00112cec;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x744) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x744) =
       PTR__glSetFenceAPPLE_Comp_00112ce8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x750) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x750) =
       PTR__glFinishFenceAPPLE_Comp_00112ce4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x758) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x758) =
       PTR__glFinishObjectAPPLE_Comp_00112ce0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x870) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x870) =
       PTR__glPointParameterf_Comp_00112cdc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x874) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x874) =
       PTR__glPointParameterfv_Comp_00112cd8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x878) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x878) =
       PTR__glPointParameteriARB_Comp_00112cd4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x87c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x87c) =
       PTR__glPointParameterivARB_Comp_00112cd0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x880) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x880) =
       PTR__glFogCoordf_Comp_00112ccc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x884) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x884) =
       PTR__glFogCoordfv_Comp_00112cc8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x888) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x888) =
       PTR__glFogCoordd_Comp_00112cc4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x88c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x88c) =
       PTR__glFogCoorddv_Comp_00112cc0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x898) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x898) =
       PTR__glBindVertexArrayEXT_Comp_00112cbc;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8ac) =
       PTR__glDrawElementArrayAPPLE_Comp_00112cb8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8b0) =
       PTR__glDrawRangeElementArrayAPPLE_Comp_00112cb4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa60) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa60) =
       PTR__glMultiDrawRangeElementArrayAPPLE_Comp_00112cb0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa5c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa5c) =
       PTR__glMultiDrawElementArrayAPPLE_Comp_00112cac;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x540) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x540) =
       PTR__glBlendFuncSeparate_Comp_00112ca8;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x728) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x728) =
       PTR__glBlendEquationSeparateEXT_Comp_00112ca4;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8dc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8dc) =
       PTR__glMultiDrawArrays_Comp_00112ca0;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8e0) =
       PTR__glMultiDrawElements_Comp_00112c9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8b4) =
       PTR__glWeightbvARB_Comp_00112c98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8b8) =
       PTR__glWeightsvARB_Comp_00112c94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8bc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8bc) =
       PTR__glWeightivARB_Comp_00112c90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c0) =
       PTR__glWeightfvARB_Comp_00112c8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c4) =
       PTR__glWeightdvARB_Comp_00112c88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8c8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8c8) =
       PTR__glWeightubvARB_Comp_00112c84;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8cc) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8cc) =
       PTR__glWeightusvARB_Comp_00112c80;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8d0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8d0) =
       PTR__glWeightuivARB_Comp_00112c7c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8d8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x8d8) =
       PTR__glVertexBlendARB_Comp_00112c78;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x924) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x924) =
       PTR__glActiveStencilFace_Comp_00112c74;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x928) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x928) =
       PTR__glStencilOpSeparateATI_Comp_00112c70;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x92c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x92c) =
       PTR__glStencilFuncSeparateATI_Comp_00112c6c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x960) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x960) =
       PTR__glUseProgramObjectARB_Comp_00112c68;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x968) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x968) =
       PTR__glUniform1fARB_Comp_00112c64;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x96c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x96c) =
       PTR__glUniform2fARB_Comp_00112c60;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x970) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x970) =
       PTR__glUniform3fARB_Comp_00112c5c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x974) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x974) =
       PTR__glUniform4fARB_Comp_00112c58;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x978) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x978) =
       PTR__glUniform1iARB_Comp_00112c54;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x97c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x97c) =
       PTR__glUniform2iARB_Comp_00112c50;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x980) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x980) =
       PTR__glUniform3iARB_Comp_00112c4c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x984) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x984) =
       PTR__glUniform4iARB_Comp_00112c48;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x988) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x988) =
       PTR__glUniform1fvARB_Comp_00112c44;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x98c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x98c) =
       PTR__glUniform2fvARB_Comp_00112c40;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x990) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x990) =
       PTR__glUniform3fvARB_Comp_00112c3c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x994) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x994) =
       PTR__glUniform4fvARB_Comp_00112c38;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x998) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x998) =
       PTR__glUniform1ivARB_Comp_00112c34;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x99c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x99c) =
       PTR__glUniform2ivARB_Comp_00112c30;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9a0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9a0) =
       PTR__glUniform3ivARB_Comp_00112c2c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9a4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9a4) =
       PTR__glUniform4ivARB_Comp_00112c28;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9a8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9a8) =
       PTR__glUniformMatrix2fvARB_Comp_00112c24;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9ac) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9ac) =
       PTR__glUniformMatrix3fvARB_Comp_00112c20;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9b0) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9b0) =
       PTR__glUniformMatrix4fvARB_Comp_00112c1c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9f4) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9f4) =
       PTR__glBeginQuery_Comp_00112c18;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x9f8) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0x9f8) =
       PTR__glEndQuery_Comp_00112c14;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa34) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa34) =
       PTR__glDepthBoundsEXT_Comp_00112c10;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa38) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa38) =
       PTR__glDrawBuffersARB_Comp_00112c0c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa3c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa3c) =
       PTR__glIsShader_Exec_00113b9c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa40) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa40) =
       PTR__glIsProgram_Exec_00113b98;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa44) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa44) =
       PTR__glGetShaderiv_Exec_00113b94;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa48) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa48) =
       PTR__glGetProgramiv_Exec_00113b90;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa4c) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa4c) =
       PTR__glGetShaderInfoLog_Exec_00113b8c;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa50) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa50) =
       PTR__glGetProgramInfoLog_Exec_00113b88;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa54) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa54) =
       PTR__glStencilFuncSeparate_Comp_00112c08;
  emptySlotMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa58) == 0);
  *(undefined **)
   ((*(uint *)(glContext + 0x4680) & emptySlotMask | *(uint *)(glContext + 0x4684) & ~emptySlotMask) + 0xa58) =
       PTR__glStencilMaskSeparate_Comp_00112c04;
  return;
}

/* _EstablishVertexFormat @ 0x42e0c (1196 bytes) */
int _EstablishVertexFormat(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
  int param_5;
  int *param_6;
  int *param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int loopIndex;
  int iVar6;
  uint uVar7;
  undefined1 uVar8;
  int loopIndex2;
  
  puVar1 = (undefined *)*param_2;
  loopIndex = 0;
  loopIndex2 = 0;
  iVar4 = *(int *)(((uint)puVar1 & 0x7c) + _gleDisplayListFunctionHash);
  iVar6 = 0;
  while ((iVar4 != 0 && (iVar6 = iVar4, puVar1 != *(undefined **)(iVar4 + 4)))) {
    iVar4 = *(int *)(iVar4 + 0xc);
    iVar6 = iVar4;
  }
  if (puVar1 == PTR__glBegin_ListExec_00112150) {
    if ((iVar6 == 0) || (*(undefined **)(iVar6 + 4) != PTR__glWeightARB_ListExec_0011214c)) {
      param_2 = (uint *)((int)param_2 + *(int *)(param_5 + param_4 * 4));
    }
    else {
      param_2 = param_2 + param_2[1] + 2;
    }
    loopIndex2 = 1;
  }
  for (; loopIndex2 < param_3; loopIndex2 = loopIndex2 + 1) {
    puVar2 = *(undefined4 **)((*param_2 & 0x7c) + _gleDisplayListFunctionHash);
    if (puVar2 == (undefined4 *)0x0) break;
    do {
      if (*param_2 == puVar2[1]) break;
      puVar2 = (undefined4 *)puVar2[3];
    } while (puVar2 != (undefined4 *)0x0);
    if (puVar2 == (undefined4 *)0x0) break;
    uVar7 = puVar2[2];
    uVar8 = (undefined1)uVar7;
    switch(*puVar2) {
    case 0:
      goto switchD_00042f34_caseD_0;
    case 1:
      *param_6 = loopIndex2;
      *param_7 = (int)param_2;
      return loopIndex;
    case 2:
    case 3:
    case 4:
      if ((*(byte *)(param_1 + 0xc) == 0) && (*(char *)(param_1 + 0x1c) != '\0')) {
        return 0;
      }
      if (*(byte *)(param_1 + 0xc) < uVar7) {
        *(undefined1 *)(param_1 + 0xc) = uVar8;
      }
      goto LAB_0004325c;
    case 5:
    case 6:
      if ((*(char *)(param_1 + 0xc) == '\0') && (*(char *)(param_1 + 0x1c) == '\0')) {
        uVar3 = (uint)*(byte *)(param_1 + 0xe);
      }
      else {
        uVar3 = (uint)*(byte *)(param_1 + 0xe);
        if (uVar3 == 0) {
          return 0;
        }
      }
      if (uVar3 < uVar7) {
        *(undefined1 *)(param_1 + 0xe) = uVar8;
      }
      break;
    case 7:
      if (((*(char *)(param_1 + 0xc) != '\0') || (*(char *)(param_1 + 0x1c) != '\0')) &&
         (*(char *)(param_1 + 0xd) == '\0')) {
        return 0;
      }
      *(undefined1 *)(param_1 + 0xd) = uVar8;
      break;
    case 8:
    case 9:
    case 10:
    case 0xb:
      if ((*(char *)(param_1 + 0xc) == '\0') && (*(char *)(param_1 + 0x1c) == '\0')) {
        uVar3 = (uint)*(byte *)(param_1 + 0x14);
      }
      else {
        uVar3 = (uint)*(byte *)(param_1 + 0x14);
        if (uVar3 == 0) {
          return 0;
        }
      }
      if (uVar3 < uVar7) {
        *(undefined1 *)(param_1 + 0x14) = uVar8;
      }
      break;
    case 0xc:
    case 0xd:
    case 0xe:
      if (((*(char *)(param_1 + 0xc) != '\0') || (*(char *)(param_1 + 0x1c) != '\0')) &&
         (*(char *)(param_2[1] + param_1 + 0x14) == '\0')) {
        return 0;
      }
      iVar4 = param_2[1] + param_1;
      if (*(byte *)(iVar4 + 0x14) < uVar7) {
        *(undefined1 *)(iVar4 + 0x14) = uVar8;
      }
      break;
    case 0xf:
    case 0x10:
    case 0x11:
      if (((*(char *)(param_1 + 0xc) != '\0') || (*(char *)(param_1 + 0x1c) != '\0')) &&
         (*(char *)(param_2[1] + param_1 + 0x1c) == '\0')) {
        return 0;
      }
      uVar7 = param_2[1];
      iVar4 = uVar7 + param_1;
      if (*(byte *)(iVar4 + 0x1c) < 4) {
        uVar8 = 4;
LAB_0004324c:
        *(undefined1 *)(iVar4 + 0x1c) = uVar8;
        uVar7 = param_2[1];
      }
      goto LAB_00043254;
    case 0x12:
    case 0x13:
    case 0x14:
      if (((*(char *)(param_1 + 0xc) != '\0') || (*(char *)(param_1 + 0x1c) != '\0')) &&
         (*(char *)(param_2[1] + param_1 + 0x1c) == '\0')) {
        return 0;
      }
      uVar7 = param_2[1];
      iVar4 = uVar7 + param_1;
      if (*(byte *)(iVar4 + 0x1c) < 8) {
        uVar8 = 8;
        goto LAB_0004324c;
      }
      goto LAB_00043254;
    case 0x15:
    case 0x16:
    case 0x17:
      if (((*(char *)(param_1 + 0xc) != '\0') || (*(char *)(param_1 + 0x1c) != '\0')) &&
         (*(char *)(param_2[1] + param_1 + 0x1c) == '\0')) {
        return 0;
      }
      uVar7 = param_2[1];
      iVar4 = uVar7 + param_1;
      if (*(byte *)(iVar4 + 0x1c) < 0xc) {
        uVar8 = 0xc;
        goto LAB_0004324c;
      }
      goto LAB_00043254;
    case 0x18:
    case 0x19:
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
      if (((*(char *)(param_1 + 0xc) != '\0') || (*(char *)(param_1 + 0x1c) != '\0')) &&
         (*(char *)(param_2[1] + param_1 + 0x1c) == '\0')) {
        return 0;
      }
      uVar7 = param_2[1];
      iVar4 = uVar7 + param_1;
      if (*(byte *)(iVar4 + 0x1c) < 0x10) {
        uVar8 = 0x10;
        goto LAB_0004324c;
      }
LAB_00043254:
      if (uVar7 == 0) {
LAB_0004325c:
        loopIndex = loopIndex + 1;
      }
      break;
    case 0x26:
      if (*(char *)(param_1 + 0xc) == '\0') {
        uVar7 = (uint)*(byte *)(param_1 + 0x1c);
        if (uVar7 != 0) goto LAB_00043288;
      }
      else {
        uVar7 = (uint)*(byte *)(param_1 + 0x1c);
LAB_00043288:
        if (uVar7 == 0) {
          return 0;
        }
      }
      if (uVar7 < param_2[1] << 2) {
        *(char *)(param_1 + 0x1c) = (char)(param_2[1] << 2);
      }
      break;
    case 0x27:
      if (((*(char *)(param_1 + 0xc) != '\0') || (*(char *)(param_1 + 0x1c) != '\0')) &&
         (*(char *)(param_1 + 0xf) == '\0')) {
        return 0;
      }
      *(undefined1 *)(param_1 + 0xf) = uVar8;
      break;
    case 0x28:
      if (((*(char *)(param_1 + 0xc) != '\0') || (*(char *)(param_1 + 0x1c) != '\0')) &&
         (*(char *)(param_1 + 0x10) == '\0')) {
        return 0;
      }
      *(undefined1 *)(param_1 + 0x10) = uVar8;
      break;
    default:
      goto switchD_00042f34_default;
    }
    if ((undefined *)puVar2[1] == PTR__glWeightARB_ListExec_0011214c) {
      param_2 = param_2 + param_2[1] + 2;
    }
    else {
      param_2 = (uint *)((int)param_2 + *(int *)(param_5 + (param_4 + loopIndex2) * 4));
    }
  }
switchD_00042f34_caseD_0:
switchD_00042f34_default:
  return 0;
}

/* _glSwap_Exec @ 0x4335c (652 bytes) */
void _glSwap_Exec(int glContext,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  int remaining;
  int loopIndex;
  bool bVar1;
  char cVar2;
  undefined4 glErrorCode;
  int *srcCursor;
  int iVar5;
  int framebufferObject;
  undefined4 incomingR5;
  undefined4 incomingR6;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int matrixChangeBits;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_00043588;
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_000435b4;
  framebufferObject = *(int *)(glContext + 0x744c);
  piVar8 = (int *)(glContext + 0x310);
  cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0004348c:
    uVar7 = *(uint *)(glContext + 0x31c);
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
    uVar7 = *(uint *)(glContext + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(glContext + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_0004348c;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar7 = uVar7 & 0x17000000;
  }
  else {
    uVar7 = uVar7 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(glContext + 0x314) == 0) &&
             (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(glContext + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
      uVar7 = (**(code **)(glContext + 0x4788))
                        (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(glContext,uVar7);
        if (*(char *)(glContext + 0x759d) == '\0') {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          glErrorCode = 0x506;
LAB_00043588:
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
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
LAB_000435b4:
                    
                    
  (**(code **)(glContext + 0x46f8))(*(undefined4 *)(glContext + 0x4688));
  return;
}

/* _glDeleteLists_Exec @ 0x435e8 (228 bytes) */
void _glDeleteLists_Exec(glContext, list, listRange)
  int glContext;
  undefined4 list;
  int listRange;
{
  undefined4 glErrorCode;
  int sharedState;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < listRange) {
      if (listRange == 0) {
        return;
      }
      sharedState = *(int *)(glContext + 0x5148);
      if (*(char *)(sharedState + 0x8024) != '\0') {
        _pthread_mutex_lock(sharedState + 0x8028);
        _gleDeleteHashNamesAndObjects(glContext,*(int *)(glContext + 0x5148) + 0x300c,list,listRange);
        _pthread_mutex_unlock(sharedState + 0x8028);
        return;
      }
      _gleDeleteHashNamesAndObjects(glContext,sharedState + 0x300c,list,listRange);
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

/* _gleFreeDisplayListObject @ 0x436cc (164 bytes) */
void _gleFreeDisplayListObject(glContext, param_2)
  undefined4 glContext;
  int param_2;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = *(int *)(param_2 + 0x24);
  puVar1 = (undefined4 *)(param_2 + 0x1c);
  while (iVar2 != 0) {
    puVar3 = (undefined4 *)(param_2 + iVar2);
    if ((code *)*puVar1 != (code *)0x0) {
      (*(code *)*puVar1)(glContext,param_2 + puVar1[1]);
    }
    puVar1 = puVar3;
    iVar2 = puVar3[2];
  }
  if ((code *)*puVar1 != (code *)0x0) {
    (*(code *)*puVar1)(glContext,param_2 + puVar1[1]);
  }
  if (*(int *)(param_2 + 0x14) != 0) {
    _free(*(int *)(param_2 + 0x14));
  }
  _free(param_2);
  return;
}

/* _glTranslated_CompExec @ 0x43770 (96 bytes) */
void _glTranslated_CompExec(undefined4 glContext,double x,double y,double z)
{
  ((float * (*)())_glTranslated_Comp)(glContext,x,y,z);
  ((void (*)())_glTranslate_Exec)(glContext,(double)(float)x,(double)(float)y,(double)(float)z)
  ;
  return;
}

/* _glTranslated_Comp @ 0x437d0 (128 bytes) */
float * _glTranslated_Comp(undefined4 glContext,double x,double y,double z)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glTranslate_ListExec_0011040c,0xc);
  if (listRecord != (float *)0x0) {
    *listRecord = (float)x;
    listRecord[1] = (float)y;
    listRecord[2] = (float)z;
  }
  return listRecord;
}

/* _glRotated_CompExec @ 0x43850 (540 bytes) */
void _glRotated_CompExec(int glContext,double angle,double x,double y,double z)
{
  double glContextFloat20;
  double sinValue;
  double dVar2;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  glContextFloat20 = (double)*(float *)(glContext + 0x20);
  if ((y == glContextFloat20) && (z == glContextFloat20)) {
    dVar2 = DOUBLE_00108db8;
    if (x < glContextFloat20) {
      dVar2 = DOUBLE_00108db0;
    }
    sinValue = _sin(angle * dVar2);
    dVar2 = _cos(angle * dVar2);
    ((void (*)())_glRotateX_Comp)(glContext,(double)(float)sinValue,(double)(float)dVar2);
    ((void (*)())_glRotateX_Exec)(glContext,(double)(float)sinValue,(double)(float)dVar2,y,z,incomingFpr5,incomingFpr6,
                    incomingFpr7,incomingFpr8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((x == glContextFloat20) && (z == glContextFloat20)) {
    dVar2 = DOUBLE_00108db8;
    if (y < glContextFloat20) {
      dVar2 = DOUBLE_00108db0;
    }
    sinValue = _sin(angle * dVar2);
    dVar2 = _cos(angle * dVar2);
    ((void (*)())_glRotateY_Comp)(glContext,(double)(float)sinValue,(double)(float)dVar2);
    ((void (*)())_glRotateY_Exec)(glContext,(double)(float)sinValue,(double)(float)dVar2,y,z,incomingFpr5,incomingFpr6,
                    incomingFpr7,incomingFpr8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  if ((x == glContextFloat20) && (y == glContextFloat20)) {
    dVar2 = DOUBLE_00108db8;
    if (z < glContextFloat20) {
      dVar2 = DOUBLE_00108db0;
    }
    sinValue = _sin(angle * dVar2);
    dVar2 = _cos(angle * dVar2);
    ((void (*)())_glRotateZ_Comp)(glContext,(double)(float)sinValue,(double)(float)dVar2);
    ((void (*)())_glRotateZ_Exec)(glContext,(double)(float)sinValue,(double)(float)dVar2,y,z,incomingFpr5,incomingFpr6,
                    incomingFpr7,incomingFpr8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
    return;
  }
  ((void (*)())_glRotateXYZ_Comp)(glContext,(double)(float)angle,(double)(float)x,(double)(float)y,
                    (double)(float)z);
  ((void (*)())_glRotateXYZ_Exec)(glContext,(double)(float)angle,(double)(float)x,(double)(float)y,
                    (double)(float)z);
  return;
}

/* _glRotateY_Comp @ 0x43a6c (100 bytes) */
void _glRotateY_Comp(undefined4 glContext,float fparam_1,float fparam_2)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glRotateY_ListExec_0011028c,8);
  if (listRecord != (float *)0x0) {
    listRecord[1] = (float)fparam_2;
    *listRecord = (float)fparam_1;
  }
  return;
}

/* _glRotateX_Comp @ 0x43ad0 (100 bytes) */
void _glRotateX_Comp(undefined4 glContext,float fparam_1,float fparam_2)
{
  float *listRecord;
  
  listRecord = (float *)_gleAddListItem(glContext,PTR__glRotateX_ListExec_00110290,8);
  if (listRecord != (float *)0x0) {
    listRecord[1] = (float)fparam_2;
    *listRecord = (float)fparam_1;
  }
  return;
}

/* _glRotateX_Exec @ 0x43b34 (372 bytes) */
void _glRotateX_Exec(int glContext,float fparam_1,float fparam_2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float fVar2;
  int currentMatrix;
  int currentInverseMatrix;
  uint glContextWord50b0;
  uint uVar5;
  
  uVar5 = *(uint *)(glContext + 0x50a8);
  currentMatrix = *(int *)(glContext + 0x4fec);
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4ff4) < 0x18)) {
    fVar1 = *(float *)(currentMatrix + 0x20);
    fVar2 = *(float *)(currentMatrix + 0x14);
    *(float *)(currentMatrix + 0x20) =
         (fVar1 * fparam_2 - (*(float *)(currentMatrix + 0x10) * fparam_1));
    *(float *)(currentMatrix + 0x10) =
         (*(float *)(currentMatrix + 0x10) * fparam_2 + (fVar1 * fparam_1));
    fVar1 = *(float *)(currentMatrix + 0x28);
    *(float *)(currentMatrix + 0x14) =
         (fVar2 * fparam_2 + (*(float *)(currentMatrix + 0x24) * fparam_1));
    *(float *)(currentMatrix + 0x24) =
         (*(float *)(currentMatrix + 0x24) * fparam_2 - (fVar2 * fparam_1));
    fVar2 = *(float *)(currentMatrix + 0x1c);
    *(float *)(currentMatrix + 0x28) =
         (fVar1 * fparam_2 - (*(float *)(currentMatrix + 0x18) * fparam_1));
    *(float *)(currentMatrix + 0x18) =
         (*(float *)(currentMatrix + 0x18) * fparam_2 + (fVar1 * fparam_1));
    *(float *)(currentMatrix + 0x1c) =
         (fVar2 * fparam_2 + (*(float *)(currentMatrix + 0x2c) * fparam_1));
    *(float *)(currentMatrix + 0x2c) =
         (*(float *)(currentMatrix + 0x2c) * fparam_2 - (fVar2 * fparam_1));
    glContextWord50b0 = *(uint *)(glContext + 0x50b0);
    *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | uVar5;
    if ((uVar5 & ~glContextWord50b0 & *(uint *)(glContext + 0x505c) & 0xfffffc) != 0) {
      currentInverseMatrix = *(int *)(glContext + 0x4ff0);
      uVar5 = uVar5 & 0xff000003;
      fVar1 = *(float *)(currentInverseMatrix + 0x20);
      fVar2 = *(float *)(currentInverseMatrix + 0x14);
      *(float *)(currentInverseMatrix + 0x20) =
           (fVar1 * fparam_2 - (*(float *)(currentInverseMatrix + 0x10) * fparam_1));
      *(float *)(currentInverseMatrix + 0x10) =
           (*(float *)(currentInverseMatrix + 0x10) * fparam_2 + (fVar1 * fparam_1));
      fVar1 = *(float *)(currentInverseMatrix + 0x28);
      *(float *)(currentInverseMatrix + 0x14) =
           (fVar2 * fparam_2 + (*(float *)(currentInverseMatrix + 0x24) * fparam_1));
      *(float *)(currentInverseMatrix + 0x24) =
           (*(float *)(currentInverseMatrix + 0x24) * fparam_2 - (fVar2 * fparam_1));
      fVar2 = *(float *)(currentInverseMatrix + 0x1c);
      *(float *)(currentInverseMatrix + 0x28) =
           (fVar1 * fparam_2 - (*(float *)(currentInverseMatrix + 0x18) * fparam_1));
      *(float *)(currentInverseMatrix + 0x18) =
           (*(float *)(currentInverseMatrix + 0x18) * fparam_2 + (fVar1 * fparam_1));
      *(float *)(currentInverseMatrix + 0x1c) =
           (fVar2 * fparam_2 + (*(float *)(currentInverseMatrix + 0x2c) * fparam_1));
      *(float *)(currentInverseMatrix + 0x2c) =
           (*(float *)(currentInverseMatrix + 0x2c) * fparam_2 - (fVar2 * fparam_1));
      glContextWord50b0 = *(uint *)(glContext + 0x50b0);
    }
    *(uint *)(glContext + 0x50b0) = glContextWord50b0 | uVar5;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _gleAddListItemWithFree @ 0x43ca8 (140 bytes) */
int _gleAddListItemWithFree(glContext, forwardedArg2, forwardedArg3, param_4, param_5)
  int glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  int listRecord;
  int iVar4;
  int glContextWord53e8;
  
  listRecord = _gleAddListItem(glContext,forwardedArg2,forwardedArg3);
  iVar1 = 0;
  if (listRecord != 0) {
    glContextWord53e8 = *(int *)(glContext + 0x53e8);
    iVar4 = listRecord + param_5;
    *(undefined4 *)(listRecord + param_5) = param_4;
    *(undefined4 *)(iVar4 + 8) = 0;
    *(int *)(iVar4 + 4) = listRecord - glContextWord53e8;
    iVar1 = *(int *)(*(int *)(glContext + 0x53e8) + 0x28);
    iVar2 = *(int *)(glContext + 0x53e8) + 0x1c;
    if (iVar1 != 0) {
      iVar2 = glContextWord53e8 + iVar1;
    }
    *(int *)(iVar2 + 8) = iVar4 - glContextWord53e8;
    *(int *)(*(int *)(glContext + 0x53e8) + 0x28) = iVar4 - glContextWord53e8;
    iVar1 = listRecord;
  }
  return iVar1;
}

/* _CloseCurrentVAR @ 0x43d34 (228 bytes) */
void _CloseCurrentVAR(glContext, param_2, param_3, param_4, param_5)
  int glContext;
  int param_2;
  int param_3;
  int *param_4;
  undefined4 *param_5;
{
  uint size;
  undefined4 *puVar1;
  uint size_00;
  int glContextPtr53e8;
  vm_address_t source_address;
  vm_map_t target_task;
  undefined4 uVar3;
  vm_address_t local_40 [6];
  
  glContextPtr53e8 = *(int *)(glContext + 0x53e8);
  source_address = *(vm_address_t *)(glContextPtr53e8 + param_2);
  size_00 = *(uint *)(source_address + 0xc);
  size = (param_3 - *param_4) + 0xfffU & 0xfffff000;
  *(int *)(source_address + 8) = (param_3 - *param_4) + -0x40;
  if (size < size_00) {
    target_task = *(vm_map_t *)PTR_00112034;
    *(uint *)(*(int *)(glContextPtr53e8 + param_2) + 0xc) = size;
    _vm_allocate(target_task,local_40,size,1);
    _vm_copy(target_task,source_address,size,local_40[0]);
    _vm_deallocate(target_task,source_address,size_00);
    *(vm_address_t *)(glContextPtr53e8 + param_2) = local_40[0];
  }
  uVar3 = *(undefined4 *)(glContextPtr53e8 + param_2);
  puVar1 = (undefined4 *)
           _gleAddListItem(glContext,PTR__gleEndDrawArraysOrElementsOutOfLine_ListExec_00112148,4);
  *puVar1 = uVar3;
  *param_4 = 0;
  *param_5 = 0;
  return;
}

/* _gleCallList @ 0x43e1c (184 bytes) */
void _gleCallList(glContext, forwardedArg2)
  int glContext;
  undefined4 forwardedArg2;
{
  int iVar1;
  int hashObject;
  undefined4 pixelPackBuffer;
  undefined4 pixelUnpackBuffer;
  uint uVar4;
  uint loopIndex;
  undefined4 *puVar6;
  
  if (*(int *)(glContext + 0x540c) < 0x40) {
    *(int *)(glContext + 0x540c) = *(int *)(glContext + 0x540c) + 1;
    hashObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x300c,forwardedArg2);
    if (hashObject != 0) {
      pixelPackBuffer = *(undefined4 *)(glContext + 0x4a68);
      pixelUnpackBuffer = *(undefined4 *)(glContext + 0x4a6c);
      loopIndex = 0;
      *(undefined4 *)(glContext + 0x4a68) = 0;
      puVar6 = (undefined4 *)(hashObject + 0x2c);
      *(undefined4 *)(glContext + 0x4a6c) = 0;
      uVar4 = *(uint *)(hashObject + 0x10);
      if (uVar4 != 0) {
        do {
          loopIndex = loopIndex + 1;
          iVar1 = (*(code *)*puVar6)(glContext,puVar6 + 1);
          puVar6 = (undefined4 *)((int)(puVar6 + 1) + iVar1);
        } while (loopIndex < uVar4);
      }
      *(undefined4 *)(glContext + 0x4a68) = pixelPackBuffer;
      *(undefined4 *)(glContext + 0x4a6c) = pixelUnpackBuffer;
    }
    *(int *)(glContext + 0x540c) = *(int *)(glContext + 0x540c) + -1;
  }
  return;
}

/* _glCullFace_ListExec @ 0x43ed4 (40 bytes) */
int _glCullFace_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glCullFace_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glEnable_ListExec @ 0x43efc (40 bytes) */
int _glEnable_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glEnable_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glLoadName_ListExec @ 0x43f24 (40 bytes) */
int _glLoadName_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glLoadName_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glMaterialfv_ListExec @ 0x43f4c (52 bytes) */
undefined4 _glMaterialfv_ListExec(undefined4 glContext,undefined4 *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((void (*)())_glMaterialfv_Exec)(glContext,*recordedArgs,recordedArgs[1],recordedArgs + 2,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                     forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  return 0x18;
}

/* _glDisable_ListExec @ 0x43f80 (40 bytes) */
int _glDisable_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  undefined4 *recordedArgs;
{
  _glDisable_Exec(glContext,*recordedArgs);
  return 4;
}

/* _glColor4_ListExec @ 0x43fa8 (92 bytes) */
int _glColor4_ListExec(glContext, recordedArgs)
  int glContext;
  undefined4 *recordedArgs;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = recordedArgs[3];
  uVar2 = recordedArgs[1];
  uVar3 = recordedArgs[2];
  *(undefined4 *)(glContext + 0x2a0) = *recordedArgs;
  *(undefined4 *)(glContext + 0x2a4) = uVar2;
  *(undefined4 *)(glContext + 0x2a8) = uVar3;
  *(undefined4 *)(glContext + 0x2ac) = uVar1;
  if (*(char *)(glContext + 0x4df8) != '\0') {
    (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  }
  return 0x10;
}

/* _glBegin_ListExec @ 0x44004 (76 bytes) */
undefined4 _glBegin_ListExec(int glContext,undefined4 *recordedArgs,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  if (*(char *)(glContext + 0x759c) == '\0') {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  else {
    ((void (*)())_glBegin_Exec)(glContext,*recordedArgs,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,
                  forwardedFloatArg8);
  }
  return 4;
}

/* _glVertex3_ListExec @ 0x44050 (84 bytes) */
int _glVertex3_ListExec(glContext, recordedArgs)
  int glContext;
  float *recordedArgs;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    pcVar1 = *(code **)(glContext + 0x28);
  }
  (*pcVar1)(glContext,(double)*recordedArgs,(double)recordedArgs[1],(double)recordedArgs[2],
            (double)*(float *)(glContext + 0x24));
  return 0xc;
}

/* _glEnd_ListExec @ 0x440a4 (36 bytes) */
undefined4 _glEnd_ListExec(undefined4 glContext,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  ((int (*)())_glEndRDirty_Exec)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8)
  ;
  return 0;
}

/* _glEndRDirty_Exec @ 0x440c8 (200 bytes) */
int _glEndRDirty_Exec(int glContext,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  undefined4 uVar1;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    return glContext;
  }
  if ((((*(char *)(glContext + 0x7580) != '\0') && ((*(uint *)(glContext + 0x486c) & 1) != 0)) &&
      (*(char *)(*(int *)(glContext + 0x468c) + 0x7a) == '\0')) &&
     ((*(char *)(glContext + 0x4664) == '\0' && (*(int *)(glContext + 0x5434) == 0)))) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(glContext,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
  }
  *(undefined2 *)(glContext + 0x4a10) = 0xffff;
  *(undefined4 *)(glContext + 0x4884) = *(undefined4 *)(glContext + 0xd8);
  (**(code **)(glContext + 0x4a08))(glContext);
  uVar1 = _glePopAndCopyMaterials(glContext);
  return uVar1;
}

/* _glPushMatrix_ListExec @ 0x44190 (36 bytes) */
int _glPushMatrix_ListExec(glContext)
  undefined4 glContext;
{
  _glPushMatrix_Exec(glContext);
  return 0;
}

/* _glTranslate_ListExec @ 0x441b4 (48 bytes) */
int _glTranslate_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  float *recordedArgs;
{
  ((void (*)())_glTranslate_Exec)(glContext,(double)*recordedArgs,(double)recordedArgs[1],(double)recordedArgs[2]);
  return 0xc;
}

/* _glRotateY_ListExec @ 0x441e4 (44 bytes) */
undefined4 _glRotateY_ListExec(undefined4 glContext,float *recordedArgs,double unusedFloatArg1,double unusedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  double incomingStack_ffffffd8;
  
  ((void (*)())_glRotateY_Exec)(glContext,(double)*recordedArgs,(double)recordedArgs[1],forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,
                  forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0,incomingStack_ffffffc8,
                  incomingStack_ffffffd0,incomingStack_ffffffd8);
  return 8;
}

/* _gleSetupAndDrawArraysOrElementsOutOfLine_ListExec @ 0x44210 (1568 bytes) */
int _gleSetupAndDrawArraysOrElementsOutOfLine_ListExec(glContext, recordedArgs)
  int glContext;
  undefined4 *recordedArgs;
{
  int remaining2;
  int loopIndex2;
  int remaining;
  int loopIndex;
  undefined4 glErrorCode;
  bool bVar1;
  char cVar2;
  uint uVar3;
  int *srcCursor;
  uint *puVar5;
  undefined4 uVar6;
  int iVar7;
  int framebufferObject;
  int *dstCursor;
  int *srcCursor2;
  undefined4 in_r6;
  uint in_r7;
  undefined4 in_r8;
  int iVar9;
  int matrixChangeBits;
  uint uVar10;
  uint loopIndex3;
  uint uVar12;
  int *piVar13;
  uint *puVar14;
  uint *puVar15;
  int *piVar16;
  int *pendingChangeWords;
  double fparam_1;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  puVar15 = (uint *)*recordedArgs;
  puVar14 = puVar15 + 5;
  piVar13 = (int *)puVar15[5];
  uVar12 = puVar15[6];
  if ((*puVar15 & 3) == 2) {
    ((double (*)())_gleCreateDrawArraysOrElementsVertexObject)(glContext,puVar15);
  }
  *(undefined4 *)(glContext + 0x5414) = *(undefined4 *)(glContext + 0x4a60);
  uVar6 = _gleGetEnabled(glContext,0x851d);
  *(char *)(glContext + 0x5411) = (char)uVar6;
  ((int (*)())_gleSetCurrentVertexObject)(glContext,puVar15[1]);
  dstCursor = (int *)((int)((unsigned char *)0x0) + 1);
  ((double (*)())_gleSetClientEnableFlag)(glContext,0x851d,1);
  if ((-1 < *(short *)(glContext + 0x4a10)) ||
     (((*(char *)(glContext + 0x4664) != '\0' && (*(int *)(*(int *)(glContext + 0x5420) + 0x4cc) == 0))
      || (*(char *)(glContext + 0x759c) == '\0')))) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0x10;
    }
    glErrorCode = 0x502;
    goto LAB_0004472c;
  }
  fparam_1 = (double)((double (*)())_gleSetupOutOfLineDrawPointers)(glContext,puVar14);
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    pendingChangeWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,dstCursor,in_r6,in_r7,in_r8,matrixChangeBits,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,
                 incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_000443dc:
      uVar10 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor = (int *)(glContext + 0x324);
      do {
        iVar7 = *srcCursor;
        srcCursor = srcCursor + 1;
        if (iVar7 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      uVar10 = *(uint *)(glContext + 0x31c);
      if ((uVar10 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          dstCursor = (int *)0x0;
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          dstCursor = (int *)((int)((unsigned char *)0x0) + 1);
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_000443dc;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar10 = uVar10 & 0x17000000;
    }
    else {
      uVar10 = uVar10 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) && uVar10 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (bVar1) goto LAB_000444f0;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_000444d4:
      remaining = 0x13;
      dstCursor = pendingChangeWords;
      do {
        *dstCursor = 0;
        dstCursor = dstCursor + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_000444f0;
    }
    uVar10 = (**(code **)(glContext + 0x4788))
                       (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,pendingChangeWords);
    if ((((uVar10 & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((uVar10 & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar10 & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_000444d4;
    if ((uVar10 & 4) == 0) {
      uVar10 = uVar10 & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,uVar10);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_000444d4;
LAB_0004471c:
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0x10;
    }
    glErrorCode = 0x506;
LAB_0004472c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return 0x10;
  }
LAB_000444f0:
  if (*(char *)(glContext + 0x7580) != '\0') {
    in_r6 = 0;
    in_r8 = 0x14ff;
    dstCursor = piVar13;
    in_r7 = uVar12;
    iVar9 = ((int (*)())_gleExecuteVertexArrayRange)(glContext,0,piVar13,0,uVar12,0x14ff,0);
    fparam_1 = extraout_f1_02;
    if (iVar9 != 0) {
      uVar12 = *puVar15;
      goto LAB_00044808;
    }
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1_03;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    piVar16 = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,dstCursor,in_r6,in_r7,in_r8,matrixChangeBits,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,
                 incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00044630:
      uVar10 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex2 = 0;
      srcCursor2 = (int *)(glContext + 0x324);
      do {
        iVar7 = *srcCursor2;
        srcCursor2 = srcCursor2 + 1;
        if (iVar7 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 < 9);
      uVar10 = *(uint *)(glContext + 0x31c);
      if ((uVar10 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_00044630;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar10 = uVar10 & 0x17000000;
    }
    else {
      uVar10 = uVar10 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar16 == 0 && *(int *)(glContext + 0x314) == 0) && uVar10 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*piVar16 == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar10 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        uVar10 = (**(code **)(glContext + 0x4788))
                           (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar16);
        if ((((uVar10 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((uVar10 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           ((uVar10 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
          if ((uVar10 & 4) == 0) {
            uVar10 = uVar10 & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          _gleUpdateDispatchCodeChange(glContext,uVar10);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_0004471c;
        }
      }
      else {
        _gleSwitchToNonRevertRenderer(glContext);
      }
      remaining2 = 0x13;
      do {
        *piVar16 = 0;
        piVar16 = piVar16 + 1;
        remaining2 = remaining2 + -1;
      } while (remaining2 != 0);
    }
  }
  uVar10 = 0;
  if (*(char *)(glContext + 0x7580) == '\0') {
    loopIndex3 = 0;
    puVar5 = puVar15 + 10;
    do {
      uVar3 = *(uint *)(glContext + 0x514c) >> (loopIndex3 & 0x3f);
      if ((uVar3 & 1) == 0) {
        if (uVar3 == 0) break;
      }
      else if (*(char *)puVar5 == '\x10') {
        uVar10 = 3;
      }
      else if (*(char *)puVar5 == '\f') {
        uVar10 = uVar10 | 1;
      }
      loopIndex3 = loopIndex3 + 1;
      puVar5 = (uint *)((int)puVar5 + 1);
    } while( true );
  }
  *(uint **)(glContext + 0x48ec) = puVar14;
  *(uint **)(glContext + 0x48f0) = puVar15 + 0x10;
  uVar6 = _gleGetVertexArrayFunc(glContext);
  _gleDrawArraysOrElements_Core
            (glContext,piVar13,0,uVar12,uVar10,-(uint)*(byte *)((int)puVar15 + 0x22) >> 0x1f,0,uVar6);
  *(undefined4 *)(glContext + 0x48ec) = 0;
  uVar12 = *puVar15;
LAB_00044808:
  if ((uVar12 & 4) == 0) {
    return 0x10;
  }
  ((void (*)())_gleDrawArraysSyncState)(glContext,puVar14);
  return 0x10;
}

/* _gleCreateDrawArraysOrElementsVertexObject @ 0x44830 (308 bytes) */
double _gleCreateDrawArraysOrElementsVertexObject(glContext, param_2)
  undefined4 glContext;
  uint *param_2;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  int loopIndex;
  int iVar9;
  longlong lVar10;
  
  uVar2 = _gleCreateVertexArrayObject(glContext,0xffffffff);
  iVar9 = uVar2 + 0x10;
  param_2[1] = uVar2;
  *(undefined2 *)(uVar2 + 0x342) = 0x85be;
  _gleCreatePluginVertexArray(glContext,iVar9);
  puVar4 = param_2 + 0x10;
  uVar5 = param_2[7];
  loopIndex = 1;
  puVar6 = puVar4;
  while( true ) {
    uVar7 = (uint)*(byte *)((int)param_2 + loopIndex + 0x20);
    if (uVar7 != 0) {
      lVar10 = ___ashldi3(0,1,loopIndex + 0x10);
      uVar3 = (uint)((ulonglong)lVar10 >> 0x20);
      iVar1 = loopIndex * 0x18 + iVar9;
      *(uint **)(iVar1 + 0x20) = puVar6;
      *(short *)(iVar1 + 0x2a) = (short)((int)uVar7 >> 2);
      puVar6 = (uint *)((int)puVar6 + uVar7);
      *(undefined2 *)(iVar1 + 0x28) = 0x1406;
      *(uint *)(iVar1 + 0x24) = uVar5;
      *(uint *)(uVar2 + 0x330) = *(uint *)(uVar2 + 0x330) | uVar3;
      *(uint *)(uVar2 + 0x334) = *(uint *)(uVar2 + 0x334) | (uint)lVar10;
      *(uint *)(uVar2 + 0x350) = *(uint *)(uVar2 + 0x350) | uVar3;
      *(uint *)(uVar2 + 0x354) = *(uint *)(uVar2 + 0x354) | (uint)lVar10;
    }
    if (loopIndex == 0) break;
    if (loopIndex < 0x1f) {
      loopIndex = loopIndex + 1;
    }
    else {
      loopIndex = 0;
    }
  }
  uVar5 = param_2[2];
  *param_2 = *param_2 | 1;
  *(uint *)(uVar2 + 0x348) = uVar5;
  *(uint **)(uVar2 + 0x344) = puVar4;
  *(undefined4 *)(uVar2 + 0x350) = *(undefined4 *)(uVar2 + 0x350);
  *(uint *)(uVar2 + 0x354) = *(uint *)(uVar2 + 0x354) | 3;
  ((void (*)())_gleFlushPluginVertexArray)(glContext,iVar9,uVar5,puVar4);
  return;
}

/* _gleFlushPluginVertexArray @ 0x44964 (212 bytes) */
void _gleFlushPluginVertexArray(glContext, param_2, forwardedArg3, forwardedArg4)
  int glContext;
  undefined4 *param_2;
  undefined4 forwardedArg3;
  undefined4 forwardedArg4;
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint loopIndex;
  uint uVar8;
  uint uVar9;
  undefined4 *cursor;
  
  iVar6 = glContext + 0x10000;
  uVar8 = param_2[0xd0];
  uVar9 = param_2[0xd1];
  param_2[0xd0] = 0;
  param_2[0xd1] = 0;
  uVar5 = 1;
  loopIndex = 0;
  cursor = param_2 + 0x114;
  while( true ) {
    cursor[1] = cursor[1] | uVar8;
    cursor[2] = cursor[2] | uVar9;
    cursor = cursor + 0x23;
    piVar1 = (int *)(iVar6 + -0x777c);
    loopIndex = loopIndex + 1;
    uVar4 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = (undefined4 *)(iVar6 + -0x7a54);
    iVar6 = iVar6 + 0x2e0;
    iVar3 = (**(code **)(*piVar1 + 0x1ac))(*puVar2,uVar4,forwardedArg3,forwardedArg4,uVar5);
    if (loopIndex == *(byte *)(glContext + 0x85a4)) break;
    if (iVar3 == 1) {
      uVar5 = 0;
    }
  }
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
  return;
}

/* _gleSetCurrentVertexObject @ 0x44a38 (152 bytes) */
int _gleSetCurrentVertexObject(glContext, param_2)
  int glContext;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *srcCursor;
  undefined4 *dstCursor;
  int loopIndex;
  
  if (param_2 != *(int *)(glContext + 0x4a60)) {
    _gleUpdateDrawArraysFuncs(glContext);
  }
  loopIndex = 0;
  *(int *)(glContext + 0x4a60) = param_2;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    srcCursor = (undefined4 *)(param_2 + 0x10);
    dstCursor = (undefined4 *)(glContext + 0x8874);
    do {
      uVar1 = *srcCursor;
      loopIndex = loopIndex + 1;
      srcCursor = srcCursor + 1;
      *dstCursor = uVar1;
      dstCursor = dstCursor + 0xb8;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  *(undefined4 *)(glContext + 0x488c) = 0;
  *(undefined4 *)(glContext + 0x4890) = 0;
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
  ((void (*)())_gleResetVACachePointers)(glContext);
  return;
}

/* _gleResetVACachePointers @ 0x44ad0 (72 bytes) */
void _gleResetVACachePointers(glContext)
  int glContext;
{
  int *srcCursor;
  int *dstCursor;
  int iVar3;
  int iVar4;
  int *srcCursor2;
  int remaining;
  
  remaining = 0x20;
  dstCursor = (int *)(glContext + 0x48f8);
  srcCursor2 = (int *)(*(int *)(glContext + 0x4a60) + 0x30);
  srcCursor = (int *)(*(int *)(glContext + 0x4a60) + 0x360);
  do {
    iVar4 = *srcCursor;
    srcCursor = srcCursor + 1;
    iVar3 = *srcCursor2;
    srcCursor2 = srcCursor2 + 6;
    if (iVar4 != 0) {
      iVar3 = iVar3 + *(int *)(iVar4 + 0x30);
    }
    *dstCursor = iVar3;
    dstCursor = dstCursor + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  return;
}

/* _gleSetClientEnableFlag @ 0x44b18 (684 bytes) */
double _gleSetClientEnableFlag(glContext, array, param_3)
  int glContext;
  uint array;
  uint param_3;
{
  int clientState;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  longlong lVar6;
  
  clientState = *(int *)(glContext + 0x4a60);
  if (array == 0x8079) {
    uVar5 = 0x400000;
  }
  else if (array < 0x807a) {
    if (array == 0x8076) {
      uVar5 = 0x40000;
      lVar6 = 2;
      goto LAB_00044cf0;
    }
    if (0x8076 < array) {
      if (array == 0x8077) {
        *(ushort *)(glContext + 0x48ea) = (ushort)(-param_3 >> 0x1f);
        return;
      }
      if (array != 0x8078) {
LAB_00044cd8:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        *(undefined4 *)(glContext + 0x7574) = 0x500;
        return;
      }
      lVar6 = ___ashldi3(0,0x1000000,*(undefined4 *)(glContext + 0x53d8));
      uVar5 = (uint)lVar6;
      goto LAB_00044cf0;
    }
    if (array == 0x8074) {
      uVar5 = 0x10000;
      lVar6 = 0x1d;
      goto LAB_00044cf0;
    }
    if (array != 0x8075) goto LAB_00044cd8;
    uVar5 = 0x20000;
  }
  else {
    if (array == 0x851d) {
      if (*(byte *)(glContext + 0x465c) == param_3) {
        return;
      }
      _gleUpdateDrawArraysFuncs(glContext);
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
      *(byte *)(glContext + 0x465c) = (byte)(-param_3 >> 0x1f);
      return;
    }
    if (array < 0x851e) {
      if (array == 0x8457) {
        uVar5 = 0x80000;
      }
      else {
        if (array != 0x845e) goto LAB_00044cd8;
        uVar5 = 0x100000;
      }
    }
    else if (array == 0x86ad) {
      uVar5 = 0x200000;
    }
    else {
      if (array != 0x8a0c) goto LAB_00044cd8;
      uVar5 = 0x800000;
    }
  }
  lVar6 = 0;
LAB_00044cf0:
  uVar4 = (uint)((ulonglong)lVar6 >> 0x20);
  if (param_3 == 0) {
    if ((*(uint *)(clientState + 0x330) == 0 && uVar4 == 0) &&
        (*(uint *)(clientState + 0x334) == 0 && uVar5 == 0)) {
      return;
    }
    uVar2 = *(uint *)(clientState + 0x330) & ~uVar4;
    uVar3 = *(uint *)(clientState + 0x334) & ~uVar5;
  }
  else {
    if ((*(uint *)(clientState + 0x330) & uVar4) != 0 || (*(uint *)(clientState + 0x334) & uVar5) != 0) {
      return;
    }
    uVar2 = *(uint *)(clientState + 0x330) | uVar4;
    uVar3 = *(uint *)(clientState + 0x334) | uVar5;
  }
  *(uint *)(clientState + 0x330) = uVar2;
  *(uint *)(clientState + 0x334) = uVar3;
  *(uint *)(clientState + 0x350) = *(uint *)(clientState + 0x350) | uVar4;
  *(uint *)(clientState + 0x354) = *(uint *)(clientState + 0x354) | uVar5;
  *(undefined4 *)(glContext + 0x488c) = 0;
  *(undefined4 *)(glContext + 0x4890) = 0;
  *(uint *)(glContext + 0x497c) = *(uint *)(glContext + 0x497c) | (uint)lVar6;
  *(undefined4 *)(glContext + 0x4894) = 0;
  if (((*(int *)(clientState + 0x344) != 0) || (*(int *)(clientState + 0x358) != 0)) ||
     (*(int *)(glContext + 0x49a0) != 0)) {
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
  }
  return;
}

/* _gleSetupOutOfLineDrawPointers @ 0x44dc4 (416 bytes) */
double _gleSetupOutOfLineDrawPointers(glContext, param_2)
  int glContext;
  int param_2;
{
  int loopIndex;
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int *dstCursor;
  int loopIndex2;
  longlong lVar17;
  
  iVar3 = *(int *)(glContext + 0x4a60);
  uVar9 = *(undefined4 *)(param_2 + 8);
  uVar11 = 0;
  iVar13 = iVar3 + 0x10;
  uVar12 = 0x10000;
  iVar10 = 0;
  loopIndex2 = 1;
  dstCursor = (int *)(glContext + 0x48fc);
  do {
    iVar14 = param_2 + loopIndex2;
    bVar1 = *(byte *)(iVar14 + 0xc) >> 2;
    if (bVar1 == 0) {
      *dstCursor = 0;
      *(undefined4 *)(loopIndex2 * 0x18 + iVar13 + 0x20) = 0;
    }
    else {
      iVar2 = param_2 + 0x2c + iVar10;
      *dstCursor = iVar2;
      iVar4 = loopIndex2 * 0x18 + iVar13;
      *(int *)(iVar4 + 0x20) = iVar2;
      *(ushort *)(iVar4 + 0x2a) = (ushort)bVar1;
      *(undefined2 *)(iVar4 + 0x28) = 0x1406;
      *(undefined4 *)(iVar4 + 0x24) = uVar9;
      lVar17 = ___ashldi3(0,0x10000,loopIndex2);
      uVar11 = uVar11 | (uint)((ulonglong)lVar17 >> 0x20);
      uVar12 = uVar12 | (uint)lVar17;
    }
    iVar2 = loopIndex2 * 0x18;
    loopIndex2 = loopIndex2 + 1;
    *(undefined4 *)(iVar2 + iVar13 + 0x34) = 0;
    dstCursor = dstCursor + 1;
    iVar10 = iVar10 + (uint)*(byte *)(iVar14 + 0xc);
  } while (loopIndex2 < 0x20);
  iVar10 = param_2 + 0x2c + iVar10;
  *(int *)(glContext + 0x48f8) = iVar10;
  *(int *)(iVar3 + 0x30) = iVar10;
  loopIndex = 0;
  *(undefined4 *)(iVar3 + 0x34) = uVar9;
  *(ushort *)(iVar3 + 0x3a) = (ushort)(*(byte *)(param_2 + 0xc) >> 2);
  *(undefined4 *)(glContext + 0x488c) = 0;
  *(undefined4 *)(glContext + 0x4890) = 0;
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
  uVar7 = *(uint *)(iVar3 + 0x330);
  uVar8 = *(uint *)(iVar3 + 0x334);
  uVar5 = *(uint *)(iVar3 + 0x350);
  uVar6 = *(uint *)(iVar3 + 0x354);
  *(uint *)(iVar3 + 0x330) = uVar11;
  *(uint *)(iVar3 + 0x334) = uVar12;
  *(undefined4 *)(iVar3 + 0x350) = 0;
  *(undefined4 *)(iVar3 + 0x354) = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    iVar3 = iVar3 + 0x460;
    do {
      loopIndex = loopIndex + 1;
      *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | uVar5 | uVar11 | uVar11 ^ uVar7;
      *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) | uVar6 | uVar12 | uVar12 ^ uVar8;
      iVar3 = iVar3 + 0x8c;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x100000;
  return;
}

/* _gleExecuteVertexArrayRange @ 0x44f64 (168 bytes) */
int _gleExecuteVertexArrayRange(glContext, forwardedArg2, forwardedArg3, forwardedArg4, forwardedArg5, forwardedArg6, forwardedArg7)
  int glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
  undefined4 forwardedArg4;
  undefined4 forwardedArg5;
  undefined4 forwardedArg6;
  undefined4 forwardedArg7;
{
  double f0;
  
  f0 = (double)FLOAT_00108e50;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  (**(code **)(glContext + 0x4888))
            (glContext,forwardedArg2,forwardedArg3,forwardedArg4,forwardedArg5,*(undefined4 *)(glContext + 0x4854),forwardedArg7,f0,f0
             ,f0,f0);
  return (**(code **)(glContext + 0x4708))
            (*(undefined4 *)(glContext + 0x4688),forwardedArg2,forwardedArg3,forwardedArg4,forwardedArg5,forwardedArg6,forwardedArg7,
             *(undefined4 *)(glContext + 0x4854));
}

/* _gleDrawArraysSyncState @ 0x4500c (736 bytes) */
void _gleDrawArraysSyncState(glContext, param_2)
  int glContext;
  int param_2;
{
  int loopIndex2;
  int remaining2;
  int loopIndex;
  undefined4 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  undefined4 glContextWord20;
  undefined4 glContextWord24;
  undefined4 uVar6;
  int iVar7;
  byte *srcCursor;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  int remaining;
  
  bVar2 = *(byte *)(param_2 + 0xd);
  glContextWord20 = *(undefined4 *)(glContext + 0x20);
  glContextWord24 = *(undefined4 *)(glContext + 0x24);
  puVar11 = (undefined4 *)(param_2 + 0x2c + *(int *)(param_2 + 8) * (*(int *)(param_2 + 4) + -1));
  if (bVar2 != 0) {
    *(undefined4 *)(glContext + 0x2b0) = *puVar11;
    *(undefined4 *)(glContext + 0x2b4) = puVar11[1];
    puVar1 = puVar11 + 2;
    puVar11 = (undefined4 *)((int)puVar11 + (uint)bVar2);
    *(undefined4 *)(glContext + 0x2b8) = *puVar1;
  }
  uVar9 = (uint)*(byte *)(param_2 + 0xe);
  if (uVar9 != 0) {
    *(undefined4 *)(glContext + 0x2a0) = *puVar11;
    *(undefined4 *)(glContext + 0x2a4) = puVar11[1];
    *(undefined4 *)(glContext + 0x2a8) = puVar11[2];
    uVar6 = glContextWord24;
    if (uVar9 == 0x10) {
      uVar6 = puVar11[3];
    }
    puVar11 = (undefined4 *)((int)puVar11 + uVar9);
    *(undefined4 *)(glContext + 0x2ac) = uVar6;
    if (*(char *)(glContext + 0x4df8) != '\0') {
      (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
    }
  }
  if (*(byte *)(param_2 + 0xf) != 0) {
    uVar6 = *puVar11;
    puVar11 = (undefined4 *)((int)puVar11 + (uint)*(byte *)(param_2 + 0xf));
    *(undefined4 *)(glContext + 0x2cc) = uVar6;
  }
  bVar2 = *(byte *)(param_2 + 0x10);
  if (bVar2 != 0) {
    *(undefined4 *)(glContext + 0x2c0) = *puVar11;
    *(undefined4 *)(glContext + 0x2c4) = puVar11[1];
    puVar1 = puVar11 + 2;
    puVar11 = (undefined4 *)((int)puVar11 + (uint)bVar2);
    *(undefined4 *)(glContext + 0x2c8) = *puVar1;
  }
  uVar9 = (uint)*(byte *)(param_2 + 0x11);
  if (uVar9 != 0) {
    *(undefined4 *)(glContext + 0x2d0) = *puVar11;
    uVar6 = glContextWord20;
    if (7 < uVar9) {
      uVar6 = puVar11[1];
    }
    *(undefined4 *)(glContext + 0x2d4) = uVar6;
    uVar6 = glContextWord20;
    if (0xb < uVar9) {
      uVar6 = puVar11[2];
    }
    *(undefined4 *)(glContext + 0x2d8) = uVar6;
    uVar6 = glContextWord20;
    if (uVar9 == 0x10) {
      uVar6 = puVar11[3];
    }
    *(undefined4 *)(glContext + 0x2dc) = uVar6;
    puVar11 = (undefined4 *)((int)puVar11 + uVar9);
  }
  if (*(byte *)(param_2 + 0x12) != 0) {
    uVar3 = *(undefined1 *)puVar11;
    puVar11 = (undefined4 *)((int)puVar11 + (uint)*(byte *)(param_2 + 0x12));
    *(undefined1 *)(glContext + 0x2ec) = uVar3;
  }
  remaining = 8;
  loopIndex2 = 0;
  srcCursor = (byte *)(param_2 + 0x14);
  iVar10 = glContext;
  do {
    uVar9 = (uint)*srcCursor;
    srcCursor = srcCursor + 1;
    if (uVar9 != 0) {
      *(undefined4 *)(iVar10 + 0x120) = *puVar11;
      if (uVar9 == 0x10) {
        *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 3;
        *(undefined4 *)(iVar10 + 0x124) = puVar11[1];
        *(undefined4 *)(iVar10 + 0x128) = puVar11[2];
        *(undefined4 *)(iVar10 + 300) = puVar11[3];
      }
      else if (uVar9 == 0xc) {
        *(uint *)(glContext + 0x486c) = *(uint *)(glContext + 0x486c) | 1;
        *(undefined4 *)(iVar10 + 0x124) = puVar11[1];
        uVar6 = puVar11[2];
        *(undefined4 *)(iVar10 + 300) = glContextWord24;
        *(undefined4 *)(iVar10 + 0x128) = uVar6;
      }
      else {
        uVar6 = glContextWord20;
        if (uVar9 == 8) {
          uVar6 = puVar11[1];
        }
        *(undefined4 *)(iVar10 + 0x124) = uVar6;
        *(undefined4 *)(loopIndex2 + glContext + 300) = glContextWord24;
        *(undefined4 *)(loopIndex2 + glContext + 0x128) = glContextWord20;
      }
    }
    puVar11 = (undefined4 *)((int)puVar11 + uVar9);
    loopIndex2 = loopIndex2 + 0x10;
    iVar10 = iVar10 + 0x10;
    remaining = remaining + -1;
  } while (remaining != 0);
  srcCursor = (byte *)(param_2 + 0x1d);
  remaining2 = 0xf;
  loopIndex = 0x11;
  iVar7 = glContext + 0x110;
  do {
    uVar9 = (uint)*srcCursor;
    srcCursor = srcCursor + 1;
    if (uVar9 != 0) {
      *(undefined4 *)(iVar7 + 0xa0) = *puVar11;
      uVar6 = glContextWord20;
      if (7 < uVar9) {
        uVar6 = puVar11[1];
      }
      *(undefined4 *)(iVar7 + 0xa4) = uVar6;
      uVar6 = glContextWord20;
      if (0xb < uVar9) {
        uVar6 = puVar11[2];
      }
      *(undefined4 *)(loopIndex * 0x10 + glContext + 0xa8) = uVar6;
      uVar6 = glContextWord24;
      if (uVar9 == 0x10) {
        uVar6 = puVar11[3];
      }
      *(undefined4 *)(loopIndex * 0x10 + glContext + 0xac) = uVar6;
    }
    puVar11 = (undefined4 *)((int)puVar11 + uVar9);
    loopIndex = loopIndex + 1;
    iVar7 = iVar7 + 0x10;
    remaining2 = remaining2 + -1;
  } while (remaining2 != 0);
  return;
}

/* _glRotateX_ListExec @ 0x452ec (44 bytes) */
undefined4 _glRotateX_ListExec(undefined4 glContext,float *recordedArgs,double unusedFloatArg1,double unusedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  double incomingStack_ffffffc8;
  double incomingStack_ffffffd0;
  double incomingStack_ffffffd8;
  
  ((void (*)())_glRotateX_Exec)(glContext,(double)*recordedArgs,(double)recordedArgs[1],forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,
                  forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0,incomingStack_ffffffc8,
                  incomingStack_ffffffd0,incomingStack_ffffffd8);
  return 8;
}

/* _glNormal_ListExec @ 0x45318 (32 bytes) */
int _glNormal_ListExec(glContext, recordedArgs)
  int glContext;
  undefined4 *recordedArgs;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = recordedArgs[1];
  uVar2 = recordedArgs[2];
  *(undefined4 *)(glContext + 0x2b0) = *recordedArgs;
  *(undefined4 *)(glContext + 0x2b4) = uVar1;
  *(undefined4 *)(glContext + 0x2b8) = uVar2;
  return 0xc;
}

/* _glPopMatrix_ListExec @ 0x45338 (36 bytes) */
int _glPopMatrix_ListExec(glContext)
  undefined4 glContext;
{
  _glPopMatrix_Exec(glContext);
  return 0;
}

/* _glLineWidth_ListExec @ 0x4535c (40 bytes) */
int _glLineWidth_ListExec(glContext, recordedArgs)
  undefined4 glContext;
  float *recordedArgs;
{
  ((void (*)())_glLineWidth_Exec)(glContext,(double)*recordedArgs);
  return 4;
}

/* _gleDrawArraysOrElementsOutOfLine_ListExec @ 0x45384 (1496 bytes) */
int _gleDrawArraysOrElementsOutOfLine_ListExec(glContext, recordedArgs)
  int glContext;
  int *recordedArgs;
{
  int remaining2;
  int loopIndex2;
  int remaining;
  int loopIndex;
  undefined4 glErrorCode;
  bool bVar1;
  char cVar2;
  uint uVar3;
  int *srcCursor2;
  char *srcCursor;
  undefined4 uVar6;
  int iVar7;
  int framebufferObject;
  int *in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar8;
  int matrixChangeBits;
  uint uVar9;
  uint loopIndex3;
  undefined4 uVar11;
  int *piVar12;
  uint *puVar13;
  int iVar14;
  int *piVar15;
  int *pendingChangeWords;
  double fparam_1;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  puVar13 = *(uint **)((int)recordedArgs - *recordedArgs);
  iVar14 = (int)puVar13 + recordedArgs[1];
  piVar12 = *(int **)((int)puVar13 + recordedArgs[1]);
  uVar11 = *(undefined4 *)(iVar14 + 4);
  if ((-1 < *(short *)(glContext + 0x4a10)) ||
     (((*(char *)(glContext + 0x4664) != '\0' && (*(int *)(*(int *)(glContext + 0x5420) + 0x4cc) == 0))
      || (*(char *)(glContext + 0x759c) == '\0')))) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 8;
    }
    glErrorCode = 0x502;
    goto LAB_00045858;
  }
  fparam_1 = (double)((double (*)())_gleSetupOutOfLineDrawPointers)(glContext,iVar14);
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    pendingChangeWords = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,in_r5,in_r6,in_r7,in_r8,matrixChangeBits,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5
                 ,incomingFpr6,incomingFpr7,incomingFpr8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_00045508:
      uVar9 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex = 0;
      srcCursor2 = (int *)(glContext + 0x324);
      do {
        iVar7 = *srcCursor2;
        srcCursor2 = srcCursor2 + 1;
        if (iVar7 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 9);
      uVar9 = *(uint *)(glContext + 0x31c);
      if ((uVar9 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          in_r5 = (int *)0x0;
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          in_r5 = (int *)((int)((unsigned char *)0x0) + 1);
          fparam_1 = (double)_gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_00045508;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar9 = uVar9 & 0x17000000;
    }
    else {
      uVar9 = uVar9 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) && uVar9 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*pendingChangeWords == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (bVar1) goto LAB_0004561c;
    if (*(char *)(glContext + 0x85a8) != *(char *)(glContext + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(glContext);
LAB_00045600:
      remaining = 0x13;
      in_r5 = pendingChangeWords;
      do {
        *in_r5 = 0;
        in_r5 = in_r5 + 1;
        remaining = remaining + -1;
      } while (remaining != 0);
      goto LAB_0004561c;
    }
    uVar9 = (**(code **)(glContext + 0x4788))
                      (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,pendingChangeWords);
    if ((((uVar9 & 3) == (uint)*(byte *)(glContext + 0x7580)) &&
        ((uVar9 & 4) == (uint)*(byte *)(glContext + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar9 & 8) == (uint)(*(char *)(glContext + 0x759d) == '\0')))
    goto LAB_00045600;
    if ((uVar9 & 4) == 0) {
      uVar9 = uVar9 & 0xfffffffe;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(glContext,uVar9);
    if (*(char *)(glContext + 0x759d) != '\0') goto LAB_00045600;
LAB_00045848:
    if (*(int *)(glContext + 0x7574) != 0) {
      return 8;
    }
    glErrorCode = 0x506;
LAB_00045858:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return 8;
  }
LAB_0004561c:
  if (*(char *)(glContext + 0x7580) != '\0') {
    in_r6 = 0;
    in_r8 = 0x14ff;
    in_r5 = piVar12;
    in_r7 = uVar11;
    iVar8 = ((int (*)())_gleExecuteVertexArrayRange)(glContext,0,piVar12,0,uVar11,0x14ff,0);
    fparam_1 = extraout_f1_02;
    if (iVar8 != 0) {
      uVar9 = *puVar13;
      goto LAB_00045934;
    }
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1_03;
  }
  if (*(char *)(glContext + 0x4691) != '\0') {
    framebufferObject = *(int *)(glContext + 0x744c);
    piVar15 = (int *)(glContext + 0x310);
    cVar2 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
    if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,in_r5,in_r6,in_r7,in_r8,matrixChangeBits,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5
                 ,incomingFpr6,incomingFpr7,incomingFpr8);
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
    }
    if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0004575c:
      uVar9 = *(uint *)(glContext + 0x31c);
    }
    else {
      loopIndex2 = 0;
      srcCursor2 = (int *)(glContext + 0x324);
      do {
        iVar7 = *srcCursor2;
        srcCursor2 = srcCursor2 + 1;
        if (iVar7 != 0) {
          *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x800000;
          break;
        }
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 < 9);
      uVar9 = *(uint *)(glContext + 0x31c);
      if ((uVar9 & 0x15555) != 0) {
        if (*(char *)(glContext + 0x2e54) != '\0') {
          _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
        }
        if (*(char *)(glContext + 0x3094) != '\0') {
          _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
        }
        goto LAB_0004575c;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar9 = uVar9 & 0x17000000;
    }
    else {
      uVar9 = uVar9 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar15 == 0 && *(int *)(glContext + 0x314) == 0) && uVar9 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    else {
      bVar1 = (((*piVar15 == 0 && *(int *)(glContext + 0x314) == 0) &&
               (*(uint *)(glContext + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
              *(int *)(glContext + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(glContext + 0x85a8) == *(char *)(glContext + 0x85a6)) {
        uVar9 = (**(code **)(glContext + 0x4788))
                          (*(undefined4 *)(glContext + 0x4688),glContext + 0x4698,piVar15);
        if ((((uVar9 & 3) != (uint)*(byte *)(glContext + 0x7580)) ||
            ((uVar9 & 4) != (uint)*(byte *)(glContext + 0x7581))) ||
           ((uVar9 & 8) != (uint)(*(char *)(glContext + 0x759d) == '\0'))) {
          if ((uVar9 & 4) == 0) {
            uVar9 = uVar9 & 0xfffffffe;
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x10000000;
          }
          _gleUpdateDispatchCodeChange(glContext,uVar9);
          if (*(char *)(glContext + 0x759d) == '\0') goto LAB_00045848;
        }
      }
      else {
        _gleSwitchToNonRevertRenderer(glContext);
      }
      remaining2 = 0x13;
      do {
        *piVar15 = 0;
        piVar15 = piVar15 + 1;
        remaining2 = remaining2 + -1;
      } while (remaining2 != 0);
    }
  }
  uVar9 = 0;
  if (*(char *)(glContext + 0x7580) == '\0') {
    loopIndex3 = 0;
    srcCursor = (char *)(iVar14 + 0x14);
    do {
      uVar3 = *(uint *)(glContext + 0x514c) >> (loopIndex3 & 0x3f);
      if ((uVar3 & 1) == 0) {
        if (uVar3 == 0) break;
      }
      else if (*srcCursor == '\x10') {
        uVar9 = 3;
      }
      else if (*srcCursor == '\f') {
        uVar9 = uVar9 | 1;
      }
      loopIndex3 = loopIndex3 + 1;
      srcCursor = srcCursor + 1;
    } while( true );
  }
  *(int *)(glContext + 0x48ec) = iVar14;
  *(int *)(glContext + 0x48f0) = iVar14 + 0x2c;
  uVar6 = _gleGetVertexArrayFunc(glContext);
  _gleDrawArraysOrElements_Core
            (glContext,piVar12,0,uVar11,uVar9,-(uint)*(byte *)(iVar14 + 0xe) >> 0x1f,0,uVar6);
  *(undefined4 *)(glContext + 0x48ec) = 0;
  uVar9 = *puVar13;
LAB_00045934:
  if ((uVar9 & 4) == 0) {
    return 8;
  }
  ((void (*)())_gleDrawArraysSyncState)(glContext,iVar14);
  return 8;
}

