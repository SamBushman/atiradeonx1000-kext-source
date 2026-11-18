#include "decls.h"

/* _glLightModelfv_Comp @ 0x6cee0 (188 bytes) */
int _glLightModelfv_Comp(glContext, pname, params)
  undefined4 glContext;
  uint pname;
  uint *params;
{
  uint *listRecord;
  
  listRecord = (uint *)_gleAddListItem(glContext,PTR__glLightModelfv_ListExec_00110150,0x14);
  if (listRecord != (uint *)0x0) {
    *listRecord = pname;
    if (pname == 0xb53) {
      listRecord[1] = *params;
      listRecord[2] = params[1];
      listRecord[3] = params[2];
      listRecord[4] = params[3];
    }
    else {
      if (pname < 0xb54) {
        if (pname < 0xb51) {
          return listRecord;
        }
      }
      else if ((pname != 0x81f8) && (pname != 0x85b0)) {
        return listRecord;
      }
      listRecord[1] = *params;
    }
  }
  return listRecord;
}

/* _glLightModelfv_Exec @ 0x6cf9c (696 bytes) */
void _glLightModelfv_Exec(glContext, pname, params)
  int glContext;
  uint pname;
  float *params;
{
  byte bVar1;
  float fVar2;
  undefined4 glErrorCode;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  float dVar8;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (pname == 0xb53) {
      *(float *)(glContext + 0x2810) = *params;
      *(float *)(glContext + 0x2814) = params[1];
      *(float *)(glContext + 0x2818) = params[2];
      *(float *)(glContext + 0x281c) = params[3];
      *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) =
           *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) | 0x1e;
      *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) =
           *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) | 0x1e;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x324);
      }
      else {
        bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x358);
      }
      iVar7 = (bVar1 >> 3 & 0x1c) + glContext;
      iVar6 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar7 + 0x324) = *(uint *)(iVar7 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(iVar6 + 0x324);
      iVar6 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar6 + 0x348) = *(uint *)(iVar6 + 0x348) | 1 << (bVar1 & 0x1f);
    }
    else if (pname < 0xb54) {
      if (pname == 0xb51) {
        *(bool *)(glContext + 0x30ad) = *params != FLOAT_00108e50;
      }
      else {
        if (pname != 0xb52) goto LAB_0006d214;
        *(bool *)(glContext + 0x30ac) = *params != FLOAT_00108e50;
        _gleUpdatePolyMode(glContext);
        _gleSelectVertexSubmitFunc(glContext);
        _gleSelectVertexAddMaterialFunc(glContext);
      }
    }
    else if (pname == 0x81f8) {
      fVar2 = *params;
      dVar8 = (double)fVar2;
      if (DOUBLE_00108d80 <= (double)dVar8) {
        uVar4 = (int)((double)dVar8 - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        uVar4 = (uint)(int)fVar2;
      }
      if (1 < uVar4 - 0x81f9) goto LAB_0006d214;
      if (DOUBLE_00108d80 <= (double)dVar8) {
        uVar5 = (undefined2)(int)((double)dVar8 - DOUBLE_00108d80);
      }
      else {
        uVar5 = (undefined2)(int)fVar2;
      }
      *(undefined2 *)(glContext + 0x30a8) = uVar5;
      if ((*(char *)(glContext + 0x30aa) != '\0') && (*(char *)(glContext + 0x4664) == '\0')) {
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
        *(bool *)(glContext + 0x316b) = *(short *)(glContext + 0x30a8) == -0x7e06;
      }
    }
    else {
      if (pname != 0x85b0) {
LAB_0006d214:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0006d224;
      }
      *(bool *)(glContext + 0x30ae) = *params != FLOAT_00108e50;
    }
    _gleUpdateLightModel(glContext);
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 1;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0006d224:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glLightModelfv_CompExec @ 0x6d254 (64 bytes) */
void _glLightModelfv_CompExec(glContext, pname, params)
  undefined4 glContext;
  undefined4 pname;
  undefined4 params;
{
  ((int (*)())_glLightModelfv_Comp)(glContext,pname,params);
  ((void (*)())_glLightModelfv_Exec)(glContext,pname,params);
  return;
}

/* _glLightModeli_ListExec @ 0x6d294 (44 bytes) */
int _glLightModeli_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glLightModeli_Exec(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glLightModeli_Comp @ 0x6d2c0 (84 bytes) */
int _glLightModeli_Comp(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glLightModeli_ListExec_0011014c,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = param;
    *listRecord = pname;
  }
  return listRecord;
}

/* _glLightModeli_CompExec @ 0x6d314 (64 bytes) */
void _glLightModeli_CompExec(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
{
  ((int (*)())_glLightModeli_Comp)(glContext,pname,param);
  _glLightModeli_Exec(glContext,pname,param);
  return;
}

/* _glLightModeliv_ListExec @ 0x6d354 (48 bytes) */
int _glLightModeliv_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glLightModeliv_Exec)(glContext,*listRecord,listRecord + 1);
  return 0x14;
}

/* _glLightModeliv_Comp @ 0x6d384 (188 bytes) */
int _glLightModeliv_Comp(glContext, pname, params)
  undefined4 glContext;
  uint pname;
  uint *params;
{
  uint *listRecord;
  
  listRecord = (uint *)_gleAddListItem(glContext,PTR__glLightModeliv_ListExec_00110148,0x14);
  if (listRecord != (uint *)0x0) {
    *listRecord = pname;
    if (pname == 0xb53) {
      listRecord[1] = *params;
      listRecord[2] = params[1];
      listRecord[3] = params[2];
      listRecord[4] = params[3];
    }
    else {
      if (pname < 0xb54) {
        if (pname < 0xb51) {
          return listRecord;
        }
      }
      else if ((pname != 0x81f8) && (pname != 0x85b0)) {
        return listRecord;
      }
      listRecord[1] = *params;
    }
  }
  return listRecord;
}

/* _glLightModeliv_Exec @ 0x6d440 (656 bytes) */
void _glLightModeliv_Exec(glContext, pname, params)
  int glContext;
  uint pname;
  uint *params;
{
  byte bVar1;
  double dVar2;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  
  dVar2 = DOUBLE_00108d58;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (pname == 0xb53) {
      *(float *)(glContext + 0x2810) =
           (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
      *(float *)(glContext + 0x2814) =
           (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - dVar2);
      *(float *)(glContext + 0x2818) =
           (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - dVar2);
      *(float *)(glContext + 0x281c) =
           (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - dVar2);
      *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) =
           *(byte *)(*(int *)(glContext + 0x4dd0) + 0x234) | 0x1e;
      *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) =
           *(byte *)(*(int *)(glContext + 0x4dd4) + 0x234) | 0x1e;
      if (*(int *)(glContext + 0x5434) == 0) {
        bVar1 = *(byte *)(*(int *)(glContext + 0x5420) + 0x324);
      }
      else {
        bVar1 = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x358);
      }
      iVar5 = (bVar1 >> 3 & 0x1c) + glContext;
      iVar4 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(iVar4 + 0x324);
      iVar4 = (bVar1 >> 3 & 0x1c) + glContext;
      *(uint *)(iVar4 + 0x348) = *(uint *)(iVar4 + 0x348) | 1 << (bVar1 & 0x1f);
    }
    else if (pname < 0xb54) {
      if (pname == 0xb51) {
        *(bool *)(glContext + 0x30ad) = *params != 0;
      }
      else {
        if (pname != 0xb52) goto LAB_0006d690;
        *(bool *)(glContext + 0x30ac) = *params != 0;
        _gleUpdatePolyMode(glContext);
        _gleSelectVertexSubmitFunc(glContext);
        _gleSelectVertexAddMaterialFunc(glContext);
      }
    }
    else if (pname == 0x81f8) {
      if (1 < *params - 0x81f9) goto LAB_0006d690;
      *(short *)(glContext + 0x30a8) = (short)*params;
      if ((*(char *)(glContext + 0x30aa) != '\0') && (*(char *)(glContext + 0x4664) == '\0')) {
        *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x800;
        *(bool *)(glContext + 0x316b) = *(short *)(glContext + 0x30a8) == -0x7e06;
      }
    }
    else {
      if (pname != 0x85b0) {
LAB_0006d690:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0006d6a0;
      }
      *(bool *)(glContext + 0x30ae) = *params != 0;
    }
    _gleUpdateLightModel(glContext);
    *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 1;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0006d6a0:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glLightModeliv_CompExec @ 0x6d6d0 (64 bytes) */
void _glLightModeliv_CompExec(glContext, pname, params)
  undefined4 glContext;
  undefined4 pname;
  undefined4 params;
{
  ((int (*)())_glLightModeliv_Comp)(glContext,pname,params);
  ((void (*)())_glLightModeliv_Exec)(glContext,pname,params);
  return;
}

/* _glLockArraysEXT_Exec @ 0x6d710 (352 bytes) */
void _glLockArraysEXT_Exec(glContext, first, count)
  int glContext;
  int first;
  int count;
{
  bool bVar1;
  undefined4 glErrorCode;
  int iVar3;
  int iVar4;
  
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4988) == 0)) {
    if ((-1 < first) && (0 < count)) {
      iVar4 = *(int *)(*(int *)(glContext + 0x468c) + 0x88);
      if (count < iVar4 + -0x12) {
        iVar3 = *(int *)(glContext + 0x49ac);
        bVar1 = iVar3 == 0;
        if (bVar1) {
          iVar3 = _malloc(iVar4 * 5 + 0x48);
          *(int *)(glContext + 0x49ac) = iVar3;
          *(int *)(glContext + 0x49a0) = iVar3 + iVar4;
          *(int *)(glContext + 0x499c) = iVar3 + iVar4 + iVar4 * 4;
          bVar1 = iVar3 == 0;
        }
        else if (first != *(int *)(glContext + 0x4984)) {
          *(int *)(glContext + 0x499c) = *(int *)(glContext + 0x49a0) + iVar4 * 4;
        }
        if (bVar1) {
          *(int *)(glContext + 0x499c) = iVar3;
          *(int *)(glContext + 0x49a0) = iVar3;
        }
        else {
          *(undefined4 *)(glContext + 0x497c) = 0x1f;
        }
      }
      else if (*(int *)(glContext + 0x49ac) != 0) {
        _free(*(int *)(glContext + 0x49ac));
        *(undefined4 *)(glContext + 0x499c) = 0;
        *(undefined4 *)(glContext + 0x49ac) = 0;
        *(undefined4 *)(glContext + 0x49a0) = 0;
      }
      *(int *)(glContext + 0x4984) = first;
      *(int *)(glContext + 0x4988) = count;
      if (count == 0) {
        return;
      }
      _gleUpdateDrawArraysFuncs(glContext);
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

/* _glUnlockArraysEXT_Exec @ 0x6d870 (64 bytes) */
void _glUnlockArraysEXT_Exec(glContext)
  int glContext;
{
  if ((*(short *)(glContext + 0x4a10) < 0) && (*(int *)(glContext + 0x4988) != 0)) {
    *(undefined4 *)(glContext + 0x4988) = 0;
    *(undefined4 *)(glContext + 0x4984) = 0;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glLogicOp_ListExec @ 0x6d8b0 (40 bytes) */
int _glLogicOp_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glLogicOp_Exec)(glContext,*listRecord);
  return 4;
}

/* _glLogicOp_Comp @ 0x6d8d8 (76 bytes) */
int _glLogicOp_Comp(glContext, opcode)
  undefined4 glContext;
  undefined4 opcode;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glLogicOp_ListExec_0011015c,4);
  if (listRecord != (undefined4 *)0x0) {
    *listRecord = opcode;
  }
  return listRecord;
}

/* _glLogicOp_Exec @ 0x6d924 (88 bytes) */
void _glLogicOp_Exec(glContext, opcode)
  int glContext;
  int opcode;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (opcode - 0x1500U < 0x10) {
      *(short *)(glContext + 0x3190) = (short)opcode;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x20000;
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

/* _glLogicOp_CompExec @ 0x6d97c (56 bytes) */
void _glLogicOp_CompExec(glContext, opcode)
  undefined4 glContext;
  undefined4 opcode;
{
  ((int (*)())_glLogicOp_Comp)(glContext,opcode);
  ((void (*)())_glLogicOp_Exec)(glContext,opcode);
  return;
}

/* _glMap1Vertex3_ListExec @ 0x6d9b4 (140 bytes) */
int _glMap1Vertex3_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int remaining;
  
  piVar5 = (int *)_gleGetMapData(glContext);
  iVar4 = *listRecord;
  iVar6 = listRecord[2];
  iVar2 = listRecord[3];
  piVar5[1] = listRecord[1];
  piVar5[2] = iVar6;
  piVar5[3] = iVar2;
  *piVar5 = iVar4;
  for (remaining = iVar4; remaining != 0; remaining = remaining + -1) {
    piVar1 = listRecord + 4;
    iVar2 = listRecord[5];
    iVar3 = listRecord[6];
    listRecord = listRecord + 3;
    piVar5[4] = *piVar1;
    piVar5[5] = iVar2;
    piVar5[6] = iVar3;
    piVar5 = piVar5 + 3;
  }
  return (10 - iVar4) * -0xc + 0x88;
}

/* _glMap1Vertex4_ListExec @ 0x6da40 (156 bytes) */
int _glMap1Vertex4_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int mapData;
  int iVar7;
  int iVar8;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  iVar5 = *listRecord;
  iVar8 = listRecord[2];
  iVar1 = listRecord[3];
  *(int *)(mapData + 0x8c) = listRecord[1];
  *(int *)(mapData + 0x90) = iVar8;
  *(int *)(mapData + 0x94) = iVar1;
  *(int *)(mapData + 0x88) = iVar5;
  iVar1 = 0;
  for (remaining = iVar5; remaining != 0; remaining = remaining + -1) {
    iVar7 = iVar1 * 0x10 + mapData;
    iVar2 = listRecord[iVar1 * 4 + 4];
    iVar3 = listRecord[iVar1 * 4 + 5];
    iVar4 = listRecord[iVar1 * 4 + 6];
    *(int *)(iVar7 + 0xa4) = listRecord[iVar1 * 4 + 7];
    *(int *)(iVar7 + 0x98) = iVar2;
    *(int *)(iVar7 + 0x9c) = iVar3;
    *(int *)(iVar7 + 0xa0) = iVar4;
    iVar1 = iVar1 + 1;
  }
  return (10 - iVar5) * -0x10 + 0xb0;
}

/* _glMap1Color_ListExec @ 0x6dadc (156 bytes) */
int _glMap1Color_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int mapData;
  int iVar7;
  int iVar8;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  iVar5 = *listRecord;
  iVar8 = listRecord[2];
  iVar1 = listRecord[3];
  *(int *)(mapData + 0x1c4) = listRecord[1];
  *(int *)(mapData + 0x1c8) = iVar8;
  *(int *)(mapData + 0x1cc) = iVar1;
  *(int *)(mapData + 0x1c0) = iVar5;
  iVar1 = 0;
  for (remaining = iVar5; remaining != 0; remaining = remaining + -1) {
    iVar7 = iVar1 * 0x10 + mapData;
    iVar2 = listRecord[iVar1 * 4 + 4];
    iVar3 = listRecord[iVar1 * 4 + 5];
    iVar4 = listRecord[iVar1 * 4 + 6];
    *(int *)(iVar7 + 0x1dc) = listRecord[iVar1 * 4 + 7];
    *(int *)(iVar7 + 0x1d0) = iVar2;
    *(int *)(iVar7 + 0x1d4) = iVar3;
    *(int *)(iVar7 + 0x1d8) = iVar4;
    iVar1 = iVar1 + 1;
  }
  return (10 - iVar5) * -0x10 + 0xb0;
}

/* _glMap1Index_ListExec @ 0x6db78 (128 bytes) */
int _glMap1Index_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int mapData;
  int *dstCursor;
  int *srcCursor;
  int iVar6;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  iVar2 = *listRecord;
  iVar6 = listRecord[2];
  iVar1 = listRecord[3];
  *(int *)(mapData + 0x274) = listRecord[1];
  *(int *)(mapData + 0x278) = iVar6;
  *(int *)(mapData + 0x27c) = iVar1;
  *(int *)(mapData + 0x270) = iVar2;
  if (iVar2 != 0) {
    dstCursor = (int *)(mapData + 0x280);
    srcCursor = listRecord + 4;
    remaining = iVar2;
    do {
      iVar1 = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = iVar1;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return (10 - iVar2) * -4 + 0x38;
}

/* _glMap1Normal_ListExec @ 0x6dbf8 (140 bytes) */
int _glMap1Normal_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int remaining;
  
  iVar5 = _gleGetMapData(glContext);
  iVar4 = *listRecord;
  iVar6 = listRecord[2];
  iVar2 = listRecord[3];
  *(int *)(iVar5 + 0x13c) = listRecord[1];
  *(int *)(iVar5 + 0x140) = iVar6;
  *(int *)(iVar5 + 0x144) = iVar2;
  *(int *)(iVar5 + 0x138) = iVar4;
  for (remaining = iVar4; remaining != 0; remaining = remaining + -1) {
    piVar1 = listRecord + 4;
    iVar2 = listRecord[5];
    iVar3 = listRecord[6];
    listRecord = listRecord + 3;
    *(int *)(iVar5 + 0x148) = *piVar1;
    *(int *)(iVar5 + 0x14c) = iVar2;
    *(int *)(iVar5 + 0x150) = iVar3;
    iVar5 = iVar5 + 0xc;
  }
  return (10 - iVar4) * -0xc + 0x88;
}

/* _glMap1Texture1_ListExec @ 0x6dc84 (128 bytes) */
int _glMap1Texture1_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int mapData;
  int *dstCursor;
  int *srcCursor;
  int iVar6;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  iVar2 = *listRecord;
  iVar6 = listRecord[2];
  iVar1 = listRecord[3];
  *(int *)(mapData + 0x2ac) = listRecord[1];
  *(int *)(mapData + 0x2b0) = iVar6;
  *(int *)(mapData + 0x2b4) = iVar1;
  *(int *)(mapData + 0x2a8) = iVar2;
  if (iVar2 != 0) {
    dstCursor = (int *)(mapData + 0x2b8);
    srcCursor = listRecord + 4;
    remaining = iVar2;
    do {
      iVar1 = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = iVar1;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return (10 - iVar2) * -4 + 0x38;
}

/* _glMap1Texture2_ListExec @ 0x6dd04 (140 bytes) */
int _glMap1Texture2_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int mapData;
  int iVar6;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  iVar3 = *listRecord;
  iVar6 = listRecord[2];
  iVar1 = listRecord[3];
  *(int *)(mapData + 0x2e4) = listRecord[1];
  *(int *)(mapData + 0x2e8) = iVar6;
  *(int *)(mapData + 0x2ec) = iVar1;
  *(int *)(mapData + 0x2e0) = iVar3;
  iVar1 = 0;
  for (remaining = iVar3; remaining != 0; remaining = remaining + -1) {
    iVar4 = iVar1 * 8 + mapData;
    iVar2 = listRecord[iVar1 * 2 + 4];
    *(int *)(iVar4 + 0x2f4) = listRecord[iVar1 * 2 + 5];
    *(int *)(iVar4 + 0x2f0) = iVar2;
    iVar1 = iVar1 + 1;
  }
  return (10 - iVar3) * -8 + 0x60;
}

/* _glMap1Texture3_ListExec @ 0x6dd90 (140 bytes) */
int _glMap1Texture3_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int remaining;
  
  iVar5 = _gleGetMapData(glContext);
  iVar4 = *listRecord;
  iVar6 = listRecord[2];
  iVar2 = listRecord[3];
  *(int *)(iVar5 + 0x344) = listRecord[1];
  *(int *)(iVar5 + 0x348) = iVar6;
  *(int *)(iVar5 + 0x34c) = iVar2;
  *(int *)(iVar5 + 0x340) = iVar4;
  for (remaining = iVar4; remaining != 0; remaining = remaining + -1) {
    piVar1 = listRecord + 4;
    iVar2 = listRecord[5];
    iVar3 = listRecord[6];
    listRecord = listRecord + 3;
    *(int *)(iVar5 + 0x350) = *piVar1;
    *(int *)(iVar5 + 0x354) = iVar2;
    *(int *)(iVar5 + 0x358) = iVar3;
    iVar5 = iVar5 + 0xc;
  }
  return (10 - iVar4) * -0xc + 0x88;
}

/* _glMap1Texture4_ListExec @ 0x6de1c (156 bytes) */
int _glMap1Texture4_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int mapData;
  int iVar7;
  int iVar8;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  iVar5 = *listRecord;
  iVar8 = listRecord[2];
  iVar1 = listRecord[3];
  *(int *)(mapData + 0x3cc) = listRecord[1];
  *(int *)(mapData + 0x3d0) = iVar8;
  *(int *)(mapData + 0x3d4) = iVar1;
  *(int *)(mapData + 0x3c8) = iVar5;
  iVar1 = 0;
  for (remaining = iVar5; remaining != 0; remaining = remaining + -1) {
    iVar7 = iVar1 * 0x10 + mapData;
    iVar2 = listRecord[iVar1 * 4 + 4];
    iVar3 = listRecord[iVar1 * 4 + 5];
    iVar4 = listRecord[iVar1 * 4 + 6];
    *(int *)(iVar7 + 0x3e4) = listRecord[iVar1 * 4 + 7];
    *(int *)(iVar7 + 0x3d8) = iVar2;
    *(int *)(iVar7 + 0x3dc) = iVar3;
    *(int *)(iVar7 + 0x3e0) = iVar4;
    iVar1 = iVar1 + 1;
  }
  return (10 - iVar5) * -0x10 + 0xb0;
}

/* _glMap1VertexAttrib1ARB_ListExec @ 0x6deb8 (164 bytes) */
int _glMap1VertexAttrib1ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *srcCursor;
  int iVar2;
  int remaining;
  int mapData;
  int iVar3;
  int *dstCursor;
  int iVar5;
  int iVar6;
  
  mapData = _gleGetMapData(glContext);
  iVar5 = *listRecord;
  iVar6 = listRecord[1];
  iVar3 = mapData + iVar5 * 0xb0;
  *(int *)(iVar3 + 0x2ca8) = iVar6;
  ((unsigned char *)0x9da8)[iVar5 + mapData] = 0x1;
  iVar2 = listRecord[2];
  iVar5 = listRecord[3];
  *(int *)(iVar3 + 0x2cb4) = listRecord[4];
  *(int *)(iVar3 + 0x2cac) = iVar2;
  *(int *)(iVar3 + 0x2cb0) = iVar5;
  if (iVar6 != 0) {
    dstCursor = (int *)(iVar3 + 0x2cb8);
    srcCursor = listRecord + 5;
    remaining = iVar6;
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = iVar5;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return (10 - iVar6) * -4 + 0x3c;
}

/* _glMap1VertexAttrib2ARB_ListExec @ 0x6df5c (164 bytes) */
int _glMap1VertexAttrib2ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int iVar2;
  int remaining;
  int iVar3;
  int mapData;
  int iVar4;
  int iVar5;
  int iVar6;
  int *srcCursor;
  
  mapData = _gleGetMapData(glContext);
  iVar2 = *listRecord;
  iVar6 = listRecord[1];
  srcCursor = listRecord + 1;
  iVar4 = mapData + iVar2 * 0xb0;
  *(int *)(iVar4 + 0x2ca8) = iVar6;
  iVar5 = iVar4 + 0x2ca8;
  ((unsigned char *)0x9da8)[iVar2 + mapData] = 0x2;
  iVar2 = listRecord[3];
  iVar3 = listRecord[4];
  *(int *)(iVar4 + 0x2cac) = listRecord[2];
  *(int *)(iVar4 + 0x2cb0) = iVar2;
  *(int *)(iVar4 + 0x2cb4) = iVar3;
  for (remaining = iVar6; remaining != 0; remaining = remaining + -1) {
    piVar1 = srcCursor + 4;
    iVar3 = srcCursor[5];
    srcCursor = srcCursor + 2;
    *(int *)(iVar5 + 0x10) = *piVar1;
    *(int *)(iVar5 + 0x14) = iVar3;
    iVar5 = iVar5 + 8;
  }
  return (10 - iVar6) * -8 + 100;
}

/* _glMap1VertexAttrib3ARB_ListExec @ 0x6e000 (172 bytes) */
int _glMap1VertexAttrib3ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int iVar2;
  int remaining;
  int iVar3;
  int mapData;
  int iVar4;
  int iVar5;
  int iVar6;
  int *srcCursor;
  
  mapData = _gleGetMapData(glContext);
  iVar2 = *listRecord;
  iVar6 = listRecord[1];
  srcCursor = listRecord + 1;
  iVar4 = mapData + iVar2 * 0xb0;
  *(int *)(iVar4 + 0x2ca8) = iVar6;
  iVar5 = iVar4 + 0x2ca8;
  ((unsigned char *)0x9da8)[iVar2 + mapData] = 0x3;
  iVar2 = listRecord[3];
  iVar3 = listRecord[4];
  *(int *)(iVar4 + 0x2cac) = listRecord[2];
  *(int *)(iVar4 + 0x2cb0) = iVar2;
  *(int *)(iVar4 + 0x2cb4) = iVar3;
  for (remaining = iVar6; remaining != 0; remaining = remaining + -1) {
    piVar1 = srcCursor + 4;
    iVar3 = srcCursor[5];
    iVar4 = srcCursor[6];
    srcCursor = srcCursor + 3;
    *(int *)(iVar5 + 0x10) = *piVar1;
    *(int *)(iVar5 + 0x14) = iVar3;
    *(int *)(iVar5 + 0x18) = iVar4;
    iVar5 = iVar5 + 0xc;
  }
  return (10 - iVar6) * -0xc + 0x8c;
}

/* _glMap1VertexAttrib4ARB_ListExec @ 0x6e0ac (200 bytes) */
int _glMap1VertexAttrib4ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int remaining;
  int iVar2;
  int mapData;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  mapData = _gleGetMapData(glContext);
  iVar1 = *listRecord;
  iVar4 = listRecord[1];
  iVar3 = mapData + iVar1 * 0xb0;
  *(int *)(iVar3 + 0x2ca8) = iVar4;
  ((unsigned char *)0x9da8)[iVar1 + mapData] = 0x4;
  iVar1 = listRecord[3];
  iVar2 = listRecord[4];
  *(int *)(iVar3 + 0x2cac) = listRecord[2];
  *(int *)(iVar3 + 0x2cb0) = iVar1;
  *(int *)(iVar3 + 0x2cb4) = iVar2;
  iVar2 = 0;
  for (remaining = iVar4; remaining != 0; remaining = remaining + -1) {
    iVar8 = iVar2 * 0x10 + iVar3 + 0x2ca8;
    iVar7 = listRecord[iVar2 * 4 + 8];
    iVar6 = listRecord[iVar2 * 4 + 6];
    iVar5 = listRecord[iVar2 * 4 + 7];
    *(int *)(iVar8 + 0x10) = listRecord[iVar2 * 4 + 5];
    *(int *)(iVar8 + 0x1c) = iVar7;
    *(int *)(iVar8 + 0x14) = iVar6;
    *(int *)(iVar8 + 0x18) = iVar5;
    iVar2 = iVar2 + 1;
  }
  return (10 - iVar4) * -0x10 + 0xb4;
}

/* _glMap1d_Comp @ 0x6e174 (1080 bytes) */
void _glMap1d_Comp(int glContext,undefined4 target,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,int stride,int order,undefined4 points,double u1,double u2)
{
  undefined4 glErrorCode;
  int listRecord;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  int iVar3;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((u1 != u2) && (order - 1U < 10)) {
      switch(target) {
      case 0xd90:
        if (3 < stride) {
          iVar3 = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Color_ListExec_00110188,iVar3);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1ColordLoad)(glContext,extraout_r4_01,iVar3,u1ShadowLo,u2ShadowHi,stride,order,points,
                             listRecord,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,
                             incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd91:
        if (0 < stride) {
          iVar3 = (10 - order) * -4 + 0x38;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Index_ListExec_00110184,iVar3);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1IndexdLoad)(glContext,extraout_r4_02,iVar3,u1ShadowLo,u2ShadowHi,stride,order,points,
                             listRecord,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,
                             incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd92:
        if (2 < stride) {
          iVar3 = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Normal_ListExec_00110180,iVar3);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1NormaldLoad)(glContext,extraout_r4_03,iVar3,u1ShadowLo,u2ShadowHi,stride,order,points,
                              listRecord,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,
                              incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd93:
        if (0 < stride) {
          iVar3 = (10 - order) * -4 + 0x38;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture1_ListExec_0011017c,iVar3);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Texture1dLoad)(glContext,extraout_r4_04,iVar3,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd94:
        if (1 < stride) {
          iVar3 = (10 - order) * -8 + 0x60;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture2_ListExec_00110178,iVar3);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Texture2dLoad)(glContext,extraout_r4_05,iVar3,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd95:
        if (2 < stride) {
          iVar3 = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture3_ListExec_00110174,iVar3);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Texture3dLoad)(glContext,extraout_r4_06,iVar3,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd96:
        if (3 < stride) {
          iVar3 = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture4_ListExec_00110170,iVar3);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Texture4dLoad)(glContext,extraout_r4_07,iVar3,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd97:
        if (2 < stride) {
          iVar3 = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Vertex3_ListExec_00110190,iVar3);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Vertex3dLoad)(glContext,extraout_r4,iVar3,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd98:
        if (3 < stride) {
          iVar3 = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Vertex4_ListExec_0011018c,iVar3);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Vertex4dLoad)(glContext,extraout_r4_00,iVar3,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0006e5b0;
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
LAB_0006e5b0:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glMap1d_Exec @ 0x6e5d0 (836 bytes) */
void _glMap1d_Exec(int glContext,int target,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,int stride,int order,undefined4 points,double u1,double u2)
{
  undefined4 glErrorCode;
  int mapData;
  int iVar3;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((u1 != u2) && (order - 1U < 10)) {
      iVar3 = target + -0xd90;
      switch(iVar3) {
      case 0:
        if (3 < stride) {
          ((void (*)())_gleMap1ColordLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,stride,order,points,
                             mapData + 0x1c0,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 1:
        if (0 < stride) {
          ((void (*)())_gleMap1IndexdLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,stride,order,points,
                             mapData + 0x270,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 2:
        if (2 < stride) {
          ((void (*)())_gleMap1NormaldLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,stride,order,points,
                              mapData + 0x138,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                              incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 3:
        if (0 < stride) {
          ((void (*)())_gleMap1Texture1dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,stride,order,points,mapData + 0x2a8,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 4:
        if (1 < stride) {
          ((void (*)())_gleMap1Texture2dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,stride,order,points,mapData + 0x2e0,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 5:
        if (2 < stride) {
          ((void (*)())_gleMap1Texture3dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,stride,order,points,mapData + 0x340,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 6:
        if (3 < stride) {
          ((void (*)())_gleMap1Texture4dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,stride,order,points,mapData + 0x3c8,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 7:
        if (2 < stride) {
          ((void (*)())_gleMap1Vertex3dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,stride,order,points,mapData,u1,
                     u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13)
          ;
          return;
        }
        break;
      case 8:
        if (3 < stride) {
          ((void (*)())_gleMap1Vertex4dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,stride,order,points,mapData + 0x88,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0006e918;
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
LAB_0006e918:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glMap1d_CompExec @ 0x6e938 (116 bytes) */
void _glMap1d_CompExec(undefined4 glContext,undefined4 target,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,undefined4 stride,undefined4 order,undefined4 points,double u1,double u2)
{
  ((void (*)())_glMap1d_Comp)(glContext,target,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,stride,order,points,u1,
                u2);
  ((void (*)())_glMap1d_Exec)(glContext,target,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,stride,order,points,u1,
                u2);
  return;
}

/* _glMap1f_Comp @ 0x6e9ac (1044 bytes) */
int _glMap1f_Comp(int glContext,undefined4 target,undefined4 u1Shadow,undefined4 u2Shadow,int stride,int order,undefined4 points,float u1,float u2)
{
  undefined4 uVar1;
  undefined4 glErrorCode;
  int listRecord;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  int iVar3;
  undefined4 in_LR;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((u1 != u2) && (order - 1U < 10)) {
      switch(target) {
      case 0xd90:
        if (3 < stride) {
          iVar3 = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Color_ListExec_00110188,iVar3);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1ColorfLoad)(glContext,extraout_r4_01,iVar3,stride,order,points,listRecord,
                                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd91:
        if (0 < stride) {
          iVar3 = (10 - order) * -4 + 0x38;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Index_ListExec_00110184,iVar3);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1IndexfLoad)(glContext,extraout_r4_02,iVar3,stride,order,points,listRecord,
                                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd92:
        if (2 < stride) {
          iVar3 = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Normal_ListExec_00110180,iVar3);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1NormalfLoad)(glContext,extraout_r4_03,iVar3,stride,order,points,listRecord,
                                      u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                      (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                      (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd93:
        if (0 < stride) {
          iVar3 = (10 - order) * -4 + 0x38;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture1_ListExec_0011017c,iVar3);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture1fLoad)(glContext,extraout_r4_04,iVar3,stride,order,points,listRecord,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd94:
        if (1 < stride) {
          iVar3 = (10 - order) * -8 + 0x60;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture2_ListExec_00110178,iVar3);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture2fLoad)(glContext,extraout_r4_05,iVar3,stride,order,points,listRecord,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd95:
        if (2 < stride) {
          iVar3 = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture3_ListExec_00110174,iVar3);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture3fLoad)(glContext,extraout_r4_06,iVar3,stride,order,points,listRecord,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd96:
        if (3 < stride) {
          iVar3 = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture4_ListExec_00110170,iVar3);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture4fLoad)(glContext,extraout_r4_07,iVar3,stride,order,points,listRecord,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd97:
        if (2 < stride) {
          iVar3 = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Vertex3_ListExec_00110190,iVar3);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Vertex3fLoad)(glContext,extraout_r4,iVar3,stride,order,points,listRecord,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd98:
        if (3 < stride) {
          iVar3 = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Vertex4_ListExec_0011018c,iVar3);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Vertex4fLoad)(glContext,extraout_r4_00,iVar3,stride,order,points,listRecord,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) {
          return glContext;
        }
        glErrorCode = 0x500;
        goto LAB_0006edc4;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return glContext;
    }
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return glContext;
    }
    glErrorCode = 0x502;
  }
LAB_0006edc4:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return glContext;
}

/* _glMap1f_Exec @ 0x6ede4 (804 bytes) */
void _glMap1f_Exec(int glContext,int target,undefined4 u1Shadow,undefined4 u2Shadow,int stride,int order,undefined4 points,float u1,float u2)
{
  undefined4 glErrorCode;
  int mapData;
  int iVar3;
  undefined4 in_LR;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((u1 != u2) && (order - 1U < 10)) {
      iVar3 = target + -0xd90;
      switch(iVar3) {
      case 0:
        if (3 < stride) {
          ((int (*)())_gleMap1ColorfLoad)(glContext,iVar3,u1Shadow,stride,order,points,mapData + 0x1c0,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 1:
        if (0 < stride) {
          ((int (*)())_gleMap1IndexfLoad)(glContext,iVar3,u1Shadow,stride,order,points,mapData + 0x270,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 2:
        if (2 < stride) {
          ((int (*)())_gleMap1NormalfLoad)(glContext,iVar3,u1Shadow,stride,order,points,mapData + 0x138,u1,
                              u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                              (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                              (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 3:
        if (0 < stride) {
          ((int (*)())_gleMap1Texture1fLoad)(glContext,iVar3,u1Shadow,stride,order,points,mapData + 0x2a8,u1,u2,
                     incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 4:
        if (1 < stride) {
          ((int (*)())_gleMap1Texture2fLoad)(glContext,iVar3,u1Shadow,stride,order,points,mapData + 0x2e0,u1,u2,
                     incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 5:
        if (2 < stride) {
          ((int (*)())_gleMap1Texture3fLoad)(glContext,iVar3,u1Shadow,stride,order,points,mapData + 0x340,u1,u2,
                     incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 6:
        if (3 < stride) {
          ((int (*)())_gleMap1Texture4fLoad)(glContext,iVar3,u1Shadow,stride,order,points,mapData + 0x3c8,u1,u2,
                     incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 7:
        if (2 < stride) {
          ((int (*)())_gleMap1Vertex3fLoad)(glContext,iVar3,u1Shadow,stride,order,points,mapData,u1,u2,incomingFpr3,
                     incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 8:
        if (3 < stride) {
          ((int (*)())_gleMap1Vertex4fLoad)(glContext,iVar3,u1Shadow,stride,order,points,mapData + 0x88,u1,u2,
                     incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0006f10c;
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
LAB_0006f10c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glMap1f_CompExec @ 0x6f12c (112 bytes) */
void _glMap1f_CompExec(undefined4 glContext,undefined4 target,undefined4 u1Shadow,undefined4 u2Shadow,undefined4 stride,undefined4 order,undefined4 points,float u1,float u2)
{
  ((int (*)())_glMap1f_Comp)(glContext,target,u1Shadow,u2Shadow,stride,order,points,u1,u2);
  ((void (*)())_glMap1f_Exec)(glContext,target,u1Shadow,u2Shadow,stride,order,points,u1,u2);
  return;
}

/* _glMapVertexAttrib1fARB_Comp @ 0x6f19c (432 bytes) */
void _glMapVertexAttrib1fARB_Comp(int glContext,undefined4 index,uint size,undefined4 u1Shadow,undefined4 u2Shadow,undefined4 stride,int order,undefined4 points,float u1,float u2)
{
  undefined4 *listRecord;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  int iVar2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  double incomingStack_ffffffb8;
  
  if (size == 2) {
    iVar2 = (10 - order) * -8 + 100;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib2ARB_ListExec_00110168,iVar2);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib2fLoad)(glContext,extraout_r4_00,iVar2,stride,order,points,listRecord + 1,u1,u2,
               incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff98,incomingStack_ffffffa0,
               incomingStack_ffffffa8,incomingStack_ffffffb0,incomingStack_ffffffb8);
  }
  else if (size < 3) {
    if (size != 1) {
LAB_0006f31c:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x501;
      return;
    }
    iVar2 = (10 - order) * -4 + 0x3c;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib1ARB_ListExec_0011016c,iVar2);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib1fLoad)(glContext,extraout_r4,iVar2,stride,order,points,listRecord + 1,u1,u2,incomingFpr3,
               incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8,
               incomingStack_ffffffb0,incomingStack_ffffffb8);
  }
  else if (size == 3) {
    iVar2 = (10 - order) * -0xc + 0x8c;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib3ARB_ListExec_00110164,iVar2);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib3fLoad)(glContext,extraout_r4_01,iVar2,stride,order,points,listRecord + 1,u1,u2,
               incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff98,incomingStack_ffffffa0,
               incomingStack_ffffffa8,incomingStack_ffffffb0,incomingStack_ffffffb8);
  }
  else {
    if (size != 4) goto LAB_0006f31c;
    iVar2 = (10 - order) * -0x10 + 0xb4;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib4ARB_ListExec_00110160,iVar2);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib4fLoad)(glContext,extraout_r4_02,iVar2,stride,order,points,listRecord + 1,u1,u2,
               incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff98,incomingStack_ffffffa0,
               incomingStack_ffffffa8,incomingStack_ffffffb0,incomingStack_ffffffb8);
  }
  *listRecord = index;
  return;
}

/* _glMapVertexAttrib1fARB_Exec @ 0x6f34c (444 bytes) */
void _glMapVertexAttrib1fARB_Exec(int glContext,uint index,uint size,undefined4 u1Shadow,undefined4 u2Shadow,int stride,int order,undefined4 points,float u1,float u2)
{
  undefined4 glErrorCode;
  int mapData;
  undefined4 extraout_r4;
  uint uVar3;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingStack_ffffff98;
  double incomingStack_ffffffa0;
  double incomingStack_ffffffa8;
  double incomingStack_ffffffb0;
  double incomingStack_ffffffb8;
  
  uVar3 = size;
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((index < 0x10) && (u1 != u2)) && (0 < order)) && (order < 0xb)) {
      if (size == 2) {
        if (1 < stride) {
          ((void (*)())_gleMap1VertexAttrib2fLoad)(glContext,extraout_r4,uVar3,stride,order,points,
                     mapData + index * 0xb0 + 0x2ca8,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7
                     ,incomingFpr8,incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8,incomingStack_ffffffb0,
                     incomingStack_ffffffb8);
          goto LAB_0006f4c8;
        }
      }
      else if (size < 3) {
        if ((size == 1) && (0 < stride)) {
          ((void (*)())_gleMap1VertexAttrib1fLoad)(glContext,extraout_r4,uVar3,stride,order,points,
                     mapData + index * 0xb0 + 0x2ca8,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7
                     ,incomingFpr8,incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8,incomingStack_ffffffb0,
                     incomingStack_ffffffb8);
          goto LAB_0006f4c8;
        }
      }
      else if (size == 3) {
        if (2 < stride) {
          ((void (*)())_gleMap1VertexAttrib3fLoad)(glContext,extraout_r4,uVar3,stride,order,points,
                     mapData + index * 0xb0 + 0x2ca8,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7
                     ,incomingFpr8,incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8,incomingStack_ffffffb0,
                     incomingStack_ffffffb8);
          goto LAB_0006f4c8;
        }
      }
      else if ((size == 4) && (3 < stride)) {
        ((void (*)())_gleMap1VertexAttrib4fLoad)(glContext,extraout_r4,uVar3,stride,order,points,mapData + index * 0xb0 + 0x2ca8
                   ,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff98,
                   incomingStack_ffffffa0,incomingStack_ffffffa8,incomingStack_ffffffb0,incomingStack_ffffffb8);
LAB_0006f4c8:
        ((unsigned char *)0x9da8)[index + mapData]= SUB41(size,0);
        return;
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

/* _glMapVertexAttrib1fARB_CompExec @ 0x6f508 (120 bytes) */
void _glMapVertexAttrib1fARB_CompExec(undefined4 glContext,undefined4 index,undefined4 size,undefined4 u1Shadow,undefined4 u2Shadow,undefined4 stride,undefined4 order,undefined4 points,float u1,float u2)
{
  ((void (*)())_glMapVertexAttrib1fARB_Comp)(glContext,index,size,u1Shadow,u2Shadow,stride,order,points,u1,u2);
  ((void (*)())_glMapVertexAttrib1fARB_Exec)(glContext,index,size,u1Shadow,u2Shadow,stride,order,points,u1,u2);
  return;
}

/* _glMapVertexAttrib1dARB_Comp @ 0x6f580 (448 bytes) */
void _glMapVertexAttrib1dARB_Comp(int glContext,undefined4 index,uint size,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,undefined4 stride,int order,undefined4 points,double u1,double u2)
{
  undefined4 *listRecord;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  int iVar2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  if (size == 2) {
    iVar2 = (10 - order) * -8 + 100;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib2ARB_ListExec_00110168,iVar2);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib2dLoad)(glContext,extraout_r4_00,iVar2,u1ShadowHi,u1ShadowLo,stride,order,points,listRecord + 1,
               u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,
               incomingFpr13);
  }
  else if (size < 3) {
    if (size != 1) {
LAB_0006f710:
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      *(undefined4 *)(glContext + 0x7574) = 0x501;
      return;
    }
    iVar2 = (10 - order) * -4 + 0x3c;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib1ARB_ListExec_0011016c,iVar2);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib1dLoad)(glContext,extraout_r4,iVar2,u1ShadowHi,u1ShadowLo,stride,order,points,listRecord + 1,
               u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,
               incomingFpr13);
  }
  else if (size == 3) {
    iVar2 = (10 - order) * -0xc + 0x8c;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib3ARB_ListExec_00110164,iVar2);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib3dLoad)(glContext,extraout_r4_01,iVar2,u1ShadowHi,u1ShadowLo,stride,order,points,listRecord + 1,
               u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,
               incomingFpr13);
  }
  else {
    if (size != 4) goto LAB_0006f710;
    iVar2 = (10 - order) * -0x10 + 0xb4;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib4ARB_ListExec_00110160,iVar2);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib4dLoad)(glContext,extraout_r4_02,iVar2,u1ShadowHi,u1ShadowLo,stride,order,points,listRecord + 1,
               u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,
               incomingFpr13);
  }
  *listRecord = index;
  return;
}

/* _glMapVertexAttrib1dARB_Exec @ 0x6f740 (460 bytes) */
void _glMapVertexAttrib1dARB_Exec(int glContext,uint index,uint size,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,int stride,int order,undefined4 points,double u1,double u2)
{
  undefined4 glErrorCode;
  int mapData;
  undefined4 extraout_r4;
  uint uVar3;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  uVar3 = size;
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((index < 0x10) && (u1 != u2)) && (0 < order)) && (order < 0xb)) {
      if (size == 2) {
        if (1 < stride) {
          ((void (*)())_gleMap1VertexAttrib2dLoad)(glContext,extraout_r4,uVar3,u1ShadowHi,u1ShadowLo,stride,order,points,
                     mapData + index * 0xb0 + 0x2ca8,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7
                     ,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          goto LAB_0006f8cc;
        }
      }
      else if (size < 3) {
        if ((size == 1) && (0 < stride)) {
          ((void (*)())_gleMap1VertexAttrib1dLoad)(glContext,extraout_r4,uVar3,u1ShadowHi,u1ShadowLo,stride,order,points,
                     mapData + index * 0xb0 + 0x2ca8,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7
                     ,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          goto LAB_0006f8cc;
        }
      }
      else if (size == 3) {
        if (2 < stride) {
          ((void (*)())_gleMap1VertexAttrib3dLoad)(glContext,extraout_r4,uVar3,u1ShadowHi,u1ShadowLo,stride,order,points,
                     mapData + index * 0xb0 + 0x2ca8,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7
                     ,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          goto LAB_0006f8cc;
        }
      }
      else if ((size == 4) && (3 < stride)) {
        ((void (*)())_gleMap1VertexAttrib4dLoad)(glContext,extraout_r4,uVar3,u1ShadowHi,u1ShadowLo,stride,order,points,
                   mapData + index * 0xb0 + 0x2ca8,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                   incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
LAB_0006f8cc:
        ((unsigned char *)0x9da8)[index + mapData]= SUB41(size,0);
        return;
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

/* _glMapVertexAttrib1dARB_CompExec @ 0x6f90c (128 bytes) */
void _glMapVertexAttrib1dARB_CompExec(undefined4 glContext,undefined4 index,undefined4 size,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,undefined4 stride,undefined4 order,undefined4 points,double u1,double u2)
{
  ((void (*)())_glMapVertexAttrib1dARB_Comp)(glContext,index,size,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,stride,order,points,
             u1,u2);
  ((void (*)())_glMapVertexAttrib1dARB_Exec)(glContext,index,size,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,stride,order,points,
             u1,u2);
  return;
}

/* _glMap2Vertex3_ListExec @ 0x6f98c (180 bytes) */
int _glMap2Vertex3_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int remaining;
  int iVar8;
  int iVar9;
  
  iVar8 = _gleGetMapData(glContext);
  iVar7 = listRecord[1];
  *(int *)(iVar8 + 0x478) = *listRecord;
  *(int *)(iVar8 + 0x47c) = iVar7;
  iVar9 = *listRecord;
  iVar6 = listRecord[1];
  iVar7 = listRecord[3];
  iVar2 = listRecord[6];
  iVar3 = listRecord[4];
  iVar4 = listRecord[5];
  iVar5 = listRecord[7];
  *(int *)(iVar8 + 0x480) = listRecord[2];
  *(int *)(iVar8 + 0x484) = iVar7;
  *(int *)(iVar8 + 0x490) = iVar2;
  *(int *)(iVar8 + 0x488) = iVar3;
  *(int *)(iVar8 + 0x48c) = iVar4;
  *(int *)(iVar8 + 0x494) = iVar5;
  for (remaining = iVar9 * iVar6; remaining != 0; remaining = remaining + -1) {
    piVar1 = listRecord + 8;
    iVar2 = listRecord[9];
    iVar3 = listRecord[10];
    listRecord = listRecord + 3;
    *(int *)(iVar8 + 0x498) = *piVar1;
    *(int *)(iVar8 + 0x49c) = iVar2;
    *(int *)(iVar8 + 0x4a0) = iVar3;
    iVar8 = iVar8 + 0xc;
  }
  return (100 - iVar9 * iVar6) * -0xc + 0x4d0;
}

/* _glMap2Vertex4_ListExec @ 0x6fa40 (200 bytes) */
int _glMap2Vertex4_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int mapData;
  int iVar7;
  int iVar8;
  int iVar9;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  iVar5 = listRecord[1];
  *(int *)(mapData + 0x948) = *listRecord;
  *(int *)(mapData + 0x94c) = iVar5;
  iVar7 = *listRecord;
  iVar4 = listRecord[1];
  iVar5 = listRecord[3];
  iVar9 = listRecord[6];
  iVar1 = listRecord[4];
  iVar2 = listRecord[5];
  iVar3 = listRecord[7];
  *(int *)(mapData + 0x950) = listRecord[2];
  *(int *)(mapData + 0x954) = iVar5;
  *(int *)(mapData + 0x960) = iVar9;
  *(int *)(mapData + 0x958) = iVar1;
  *(int *)(mapData + 0x95c) = iVar2;
  *(int *)(mapData + 0x964) = iVar3;
  iVar5 = 0;
  for (remaining = iVar7 * iVar4; remaining != 0; remaining = remaining + -1) {
    iVar8 = iVar5 * 0x10 + mapData;
    iVar1 = listRecord[iVar5 * 4 + 8];
    iVar2 = listRecord[iVar5 * 4 + 9];
    iVar3 = listRecord[iVar5 * 4 + 10];
    *(int *)(iVar8 + 0x974) = listRecord[iVar5 * 4 + 0xb];
    *(int *)(iVar8 + 0x968) = iVar1;
    *(int *)(iVar8 + 0x96c) = iVar2;
    *(int *)(iVar8 + 0x970) = iVar3;
    iVar5 = iVar5 + 1;
  }
  return (100 - iVar7 * iVar4) * -0x10 + 0x660;
}

/* _glMap2Color_ListExec @ 0x6fb08 (200 bytes) */
int _glMap2Color_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int mapData;
  int iVar7;
  int iVar8;
  int iVar9;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  iVar5 = listRecord[1];
  *(int *)(mapData + 0x1478) = *listRecord;
  *(int *)(mapData + 0x147c) = iVar5;
  iVar7 = *listRecord;
  iVar4 = listRecord[1];
  iVar5 = listRecord[3];
  iVar9 = listRecord[6];
  iVar1 = listRecord[4];
  iVar2 = listRecord[5];
  iVar3 = listRecord[7];
  *(int *)(mapData + 0x1480) = listRecord[2];
  *(int *)(mapData + 0x1484) = iVar5;
  *(int *)(mapData + 0x1490) = iVar9;
  *(int *)(mapData + 0x1488) = iVar1;
  *(int *)(mapData + 0x148c) = iVar2;
  *(int *)(mapData + 0x1494) = iVar3;
  iVar5 = 0;
  for (remaining = iVar7 * iVar4; remaining != 0; remaining = remaining + -1) {
    iVar8 = iVar5 * 0x10 + mapData;
    iVar1 = listRecord[iVar5 * 4 + 8];
    iVar2 = listRecord[iVar5 * 4 + 9];
    iVar3 = listRecord[iVar5 * 4 + 10];
    *(int *)(iVar8 + 0x14a4) = listRecord[iVar5 * 4 + 0xb];
    *(int *)(iVar8 + 0x1498) = iVar1;
    *(int *)(iVar8 + 0x149c) = iVar2;
    *(int *)(iVar8 + 0x14a0) = iVar3;
    iVar5 = iVar5 + 1;
  }
  return (100 - iVar7 * iVar4) * -0x10 + 0x660;
}

/* _glMap2Index_ListExec @ 0x6fbd0 (168 bytes) */
int _glMap2Index_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int remaining;
  int mapData;
  int *dstCursor;
  int *srcCursor;
  int iVar9;
  
  mapData = _gleGetMapData(glContext);
  iVar5 = listRecord[1];
  *(int *)(mapData + 0x1ad8) = *listRecord;
  *(int *)(mapData + 0x1adc) = iVar5;
  iVar9 = *listRecord * listRecord[1];
  iVar5 = listRecord[3];
  iVar1 = listRecord[6];
  iVar2 = listRecord[4];
  iVar3 = listRecord[5];
  iVar4 = listRecord[7];
  *(int *)(mapData + 0x1ae0) = listRecord[2];
  *(int *)(mapData + 0x1ae4) = iVar5;
  *(int *)(mapData + 0x1af0) = iVar1;
  *(int *)(mapData + 0x1ae8) = iVar2;
  *(int *)(mapData + 0x1aec) = iVar3;
  *(int *)(mapData + 0x1af4) = iVar4;
  if (iVar9 != 0) {
    dstCursor = (int *)(mapData + 0x1af8);
    srcCursor = listRecord + 8;
    remaining = iVar9;
    do {
      iVar1 = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = iVar1;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return (100 - iVar9) * -4 + 0x1b0;
}

/* _glMap2Normal_ListExec @ 0x6fc78 (180 bytes) */
int _glMap2Normal_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int remaining;
  int iVar8;
  int iVar9;
  
  iVar8 = _gleGetMapData(glContext);
  iVar7 = listRecord[1];
  *(int *)(iVar8 + 0xfa8) = *listRecord;
  *(int *)(iVar8 + 0xfac) = iVar7;
  iVar9 = *listRecord;
  iVar6 = listRecord[1];
  iVar7 = listRecord[3];
  iVar2 = listRecord[6];
  iVar3 = listRecord[4];
  iVar4 = listRecord[5];
  iVar5 = listRecord[7];
  *(int *)(iVar8 + 0xfb0) = listRecord[2];
  *(int *)(iVar8 + 0xfb4) = iVar7;
  *(int *)(iVar8 + 0xfc0) = iVar2;
  *(int *)(iVar8 + 0xfb8) = iVar3;
  *(int *)(iVar8 + 0xfbc) = iVar4;
  *(int *)(iVar8 + 0xfc4) = iVar5;
  for (remaining = iVar9 * iVar6; remaining != 0; remaining = remaining + -1) {
    piVar1 = listRecord + 8;
    iVar2 = listRecord[9];
    iVar3 = listRecord[10];
    listRecord = listRecord + 3;
    *(int *)(iVar8 + 0xfc8) = *piVar1;
    *(int *)(iVar8 + 0xfcc) = iVar2;
    *(int *)(iVar8 + 0xfd0) = iVar3;
    iVar8 = iVar8 + 0xc;
  }
  return (100 - iVar9 * iVar6) * -0xc + 0x4d0;
}

/* _glMap2Texture1_ListExec @ 0x6fd2c (168 bytes) */
int _glMap2Texture1_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int remaining;
  int mapData;
  int *dstCursor;
  int *srcCursor;
  int iVar9;
  
  mapData = _gleGetMapData(glContext);
  iVar5 = listRecord[1];
  *(int *)(mapData + 0x1c88) = *listRecord;
  *(int *)(mapData + 0x1c8c) = iVar5;
  iVar9 = *listRecord * listRecord[1];
  iVar5 = listRecord[3];
  iVar1 = listRecord[6];
  iVar2 = listRecord[4];
  iVar3 = listRecord[5];
  iVar4 = listRecord[7];
  *(int *)(mapData + 0x1c90) = listRecord[2];
  *(int *)(mapData + 0x1c94) = iVar5;
  *(int *)(mapData + 0x1ca0) = iVar1;
  *(int *)(mapData + 0x1c98) = iVar2;
  *(int *)(mapData + 0x1c9c) = iVar3;
  *(int *)(mapData + 0x1ca4) = iVar4;
  if (iVar9 != 0) {
    dstCursor = (int *)(mapData + 0x1ca8);
    srcCursor = listRecord + 8;
    remaining = iVar9;
    do {
      iVar1 = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = iVar1;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return (100 - iVar9) * -4 + 0x1b0;
}

/* _glMap2Texture2_ListExec @ 0x6fdd4 (184 bytes) */
int _glMap2Texture2_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int mapData;
  int iVar7;
  int iVar8;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  iVar4 = listRecord[1];
  *(int *)(mapData + 0x1e38) = *listRecord;
  *(int *)(mapData + 0x1e3c) = iVar4;
  iVar7 = *listRecord;
  iVar3 = listRecord[1];
  iVar4 = listRecord[3];
  iVar8 = listRecord[6];
  iVar1 = listRecord[4];
  iVar5 = listRecord[5];
  iVar2 = listRecord[7];
  *(int *)(mapData + 0x1e40) = listRecord[2];
  *(int *)(mapData + 0x1e44) = iVar4;
  *(int *)(mapData + 0x1e50) = iVar8;
  *(int *)(mapData + 0x1e48) = iVar1;
  *(int *)(mapData + 0x1e4c) = iVar5;
  *(int *)(mapData + 0x1e54) = iVar2;
  iVar4 = 0;
  for (remaining = iVar7 * iVar3; remaining != 0; remaining = remaining + -1) {
    iVar5 = iVar4 * 8 + mapData;
    iVar1 = listRecord[iVar4 * 2 + 8];
    *(int *)(iVar5 + 0x1e5c) = listRecord[iVar4 * 2 + 9];
    *(int *)(iVar5 + 0x1e58) = iVar1;
    iVar4 = iVar4 + 1;
  }
  return (100 - iVar7 * iVar3) * -8 + 0x340;
}

/* _glMap2Texture3_ListExec @ 0x6fe8c (180 bytes) */
int _glMap2Texture3_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int remaining;
  int iVar8;
  int iVar9;
  
  iVar8 = _gleGetMapData(glContext);
  iVar7 = listRecord[1];
  *(int *)(iVar8 + 0x2178) = *listRecord;
  *(int *)(iVar8 + 0x217c) = iVar7;
  iVar9 = *listRecord;
  iVar6 = listRecord[1];
  iVar7 = listRecord[3];
  iVar2 = listRecord[6];
  iVar3 = listRecord[4];
  iVar4 = listRecord[5];
  iVar5 = listRecord[7];
  *(int *)(iVar8 + 0x2180) = listRecord[2];
  *(int *)(iVar8 + 0x2184) = iVar7;
  *(int *)(iVar8 + 0x2190) = iVar2;
  *(int *)(iVar8 + 0x2188) = iVar3;
  *(int *)(iVar8 + 0x218c) = iVar4;
  *(int *)(iVar8 + 0x2194) = iVar5;
  for (remaining = iVar9 * iVar6; remaining != 0; remaining = remaining + -1) {
    piVar1 = listRecord + 8;
    iVar2 = listRecord[9];
    iVar3 = listRecord[10];
    listRecord = listRecord + 3;
    *(int *)(iVar8 + 0x2198) = *piVar1;
    *(int *)(iVar8 + 0x219c) = iVar2;
    *(int *)(iVar8 + 0x21a0) = iVar3;
    iVar8 = iVar8 + 0xc;
  }
  return (100 - iVar9 * iVar6) * -0xc + 0x4d0;
}

/* _glMap2Texture4_ListExec @ 0x6ff40 (200 bytes) */
int _glMap2Texture4_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int mapData;
  int iVar7;
  int iVar8;
  int iVar9;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  iVar5 = listRecord[1];
  *(int *)(mapData + 0x2648) = *listRecord;
  *(int *)(mapData + 0x264c) = iVar5;
  iVar7 = *listRecord;
  iVar4 = listRecord[1];
  iVar5 = listRecord[3];
  iVar9 = listRecord[6];
  iVar1 = listRecord[4];
  iVar2 = listRecord[5];
  iVar3 = listRecord[7];
  *(int *)(mapData + 0x2650) = listRecord[2];
  *(int *)(mapData + 0x2654) = iVar5;
  *(int *)(mapData + 0x2660) = iVar9;
  *(int *)(mapData + 0x2658) = iVar1;
  *(int *)(mapData + 0x265c) = iVar2;
  *(int *)(mapData + 0x2664) = iVar3;
  iVar5 = 0;
  for (remaining = iVar7 * iVar4; remaining != 0; remaining = remaining + -1) {
    iVar8 = iVar5 * 0x10 + mapData;
    iVar1 = listRecord[iVar5 * 4 + 8];
    iVar2 = listRecord[iVar5 * 4 + 9];
    iVar3 = listRecord[iVar5 * 4 + 10];
    *(int *)(iVar8 + 0x2674) = listRecord[iVar5 * 4 + 0xb];
    *(int *)(iVar8 + 0x2668) = iVar1;
    *(int *)(iVar8 + 0x266c) = iVar2;
    *(int *)(iVar8 + 0x2670) = iVar3;
    iVar5 = iVar5 + 1;
  }
  return (100 - iVar7 * iVar4) * -0x10 + 0x660;
}

/* _glMap2VertexAttrib1ARB_ListExec @ 0x70008 (200 bytes) */
int _glMap2VertexAttrib1ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int *srcCursor;
  int iVar4;
  int remaining;
  int mapData;
  int *dstCursor;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  mapData = _gleGetMapData(glContext);
  iVar9 = *listRecord;
  iVar8 = listRecord[1];
  iVar7 = listRecord[2];
  iVar6 = mapData + iVar9 * 0x660;
  *(int *)(iVar6 + 0x37a8) = iVar8;
  *(int *)(iVar6 + 0x37ac) = iVar7;
  iVar7 = iVar7 * iVar8;
  *(undefined1 *)(iVar9 + mapData + 0x9db8) = 1;
  iVar4 = listRecord[3];
  iVar8 = listRecord[4];
  iVar9 = listRecord[7];
  iVar1 = listRecord[5];
  iVar2 = listRecord[6];
  *(int *)(iVar6 + 0x37c4) = listRecord[8];
  *(int *)(iVar6 + 0x37b0) = iVar4;
  *(int *)(iVar6 + 0x37b4) = iVar8;
  *(int *)(iVar6 + 0x37c0) = iVar9;
  *(int *)(iVar6 + 0x37b8) = iVar1;
  *(int *)(iVar6 + 0x37bc) = iVar2;
  if (iVar7 != 0) {
    dstCursor = (int *)(iVar6 + 0x37c8);
    srcCursor = listRecord + 9;
    remaining = iVar7;
    do {
      iVar8 = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = iVar8;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return (100 - iVar7) * -4 + 0x1b4;
}

/* _glMap2VertexAttrib2ARB_ListExec @ 0x700d0 (208 bytes) */
int _glMap2VertexAttrib2ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int remaining;
  int iVar6;
  int mapData;
  int iVar7;
  int *srcCursor;
  int iVar9;
  int iVar10;
  int iVar11;
  
  mapData = _gleGetMapData(glContext);
  iVar5 = *listRecord;
  srcCursor = listRecord + 1;
  iVar11 = listRecord[1];
  iVar7 = listRecord[2];
  iVar9 = mapData + iVar5 * 0x660;
  iVar10 = iVar9 + 0x37a8;
  *(int *)(iVar9 + 0x37a8) = iVar11;
  *(int *)(iVar9 + 0x37ac) = iVar7;
  *(undefined1 *)(iVar5 + mapData + 0x9db8) = 2;
  iVar5 = listRecord[4];
  iVar6 = listRecord[7];
  iVar2 = listRecord[5];
  iVar3 = listRecord[6];
  iVar4 = listRecord[8];
  *(int *)(iVar9 + 0x37b0) = listRecord[3];
  *(int *)(iVar9 + 0x37b4) = iVar5;
  *(int *)(iVar9 + 0x37c0) = iVar6;
  *(int *)(iVar9 + 0x37b8) = iVar2;
  *(int *)(iVar9 + 0x37bc) = iVar3;
  *(int *)(iVar9 + 0x37c4) = iVar4;
  iVar7 = iVar7 * iVar11;
  for (remaining = iVar7; remaining != 0; remaining = remaining + -1) {
    piVar1 = srcCursor + 8;
    iVar6 = srcCursor[9];
    srcCursor = srcCursor + 2;
    *(int *)(iVar10 + 0x20) = *piVar1;
    *(int *)(iVar10 + 0x24) = iVar6;
    iVar10 = iVar10 + 8;
  }
  return (100 - iVar7) * -8 + 0x344;
}

/* _glMap2VertexAttrib3ARB_ListExec @ 0x701a0 (216 bytes) */
int _glMap2VertexAttrib3ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int remaining;
  int iVar5;
  int mapData;
  int iVar6;
  int *srcCursor;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  mapData = _gleGetMapData(glContext);
  iVar4 = *listRecord;
  srcCursor = listRecord + 1;
  iVar11 = listRecord[1];
  iVar6 = listRecord[2];
  iVar8 = mapData + iVar4 * 0x660;
  iVar10 = iVar8 + 0x37a8;
  *(int *)(iVar8 + 0x37a8) = iVar11;
  *(int *)(iVar8 + 0x37ac) = iVar6;
  *(undefined1 *)(iVar4 + mapData + 0x9db8) = 3;
  iVar4 = listRecord[4];
  iVar5 = listRecord[7];
  iVar9 = listRecord[5];
  iVar2 = listRecord[6];
  iVar3 = listRecord[8];
  *(int *)(iVar8 + 0x37b0) = listRecord[3];
  *(int *)(iVar8 + 0x37b4) = iVar4;
  *(int *)(iVar8 + 0x37c0) = iVar5;
  *(int *)(iVar8 + 0x37b8) = iVar9;
  *(int *)(iVar8 + 0x37bc) = iVar2;
  *(int *)(iVar8 + 0x37c4) = iVar3;
  iVar6 = iVar6 * iVar11;
  for (remaining = iVar6; remaining != 0; remaining = remaining + -1) {
    piVar1 = srcCursor + 8;
    iVar5 = srcCursor[9];
    iVar9 = srcCursor[10];
    srcCursor = srcCursor + 3;
    *(int *)(iVar10 + 0x20) = *piVar1;
    *(int *)(iVar10 + 0x24) = iVar5;
    *(int *)(iVar10 + 0x28) = iVar9;
    iVar10 = iVar10 + 0xc;
  }
  return (100 - iVar6) * -0xc + 0x4d4;
}

/* _glMap2VertexAttrib4ARB_ListExec @ 0x70278 (236 bytes) */
int _glMap2VertexAttrib4ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int iVar2;
  int remaining;
  int mapData;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  mapData = _gleGetMapData(glContext);
  iVar6 = *listRecord;
  iVar4 = listRecord[1];
  iVar3 = listRecord[2];
  iVar1 = mapData + iVar6 * 0x660;
  *(int *)(iVar1 + 0x37a8) = iVar4;
  *(int *)(iVar1 + 0x37ac) = iVar3;
  *(undefined1 *)(iVar6 + mapData + 0x9db8) = 4;
  iVar2 = listRecord[4];
  iVar6 = listRecord[7];
  iVar5 = listRecord[5];
  iVar7 = listRecord[6];
  iVar8 = listRecord[8];
  *(int *)(iVar1 + 0x37b0) = listRecord[3];
  *(int *)(iVar1 + 0x37b4) = iVar2;
  *(int *)(iVar1 + 0x37c0) = iVar6;
  *(int *)(iVar1 + 0x37b8) = iVar5;
  *(int *)(iVar1 + 0x37bc) = iVar7;
  *(int *)(iVar1 + 0x37c4) = iVar8;
  iVar3 = iVar3 * iVar4;
  iVar6 = 0;
  for (remaining = iVar3; remaining != 0; remaining = remaining + -1) {
    iVar4 = iVar6 * 0x10 + iVar1 + 0x37a8;
    iVar8 = listRecord[iVar6 * 4 + 0xc];
    iVar7 = listRecord[iVar6 * 4 + 10];
    iVar5 = listRecord[iVar6 * 4 + 0xb];
    *(int *)(iVar4 + 0x20) = listRecord[iVar6 * 4 + 9];
    *(int *)(iVar4 + 0x2c) = iVar8;
    *(int *)(iVar4 + 0x24) = iVar7;
    *(int *)(iVar4 + 0x28) = iVar5;
    iVar6 = iVar6 + 1;
  }
  return (100 - iVar3) * -0x10 + 0x664;
}

/* _glMap2d_Comp @ 0x70364 (1420 bytes) */
void _glMap2d_Comp(int glContext,undefined4 target,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,int ustride,int uorder,undefined4 v1ShadowHi,undefined4 v1ShadowLo,undefined4 v2ShadowHi,undefined4 v2ShadowLo,int vstride,int vorder,undefined4 points,double u1,double u2,double v1,double v2)
{
  undefined4 glErrorCode;
  int listRecord;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  int iVar3;
  int iVar4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((u1 != u2) && (v1 != v2)) && (uorder - 1U < 10)) &&
       ((0 < vorder && (vorder < 0xb)))) {
      switch(target) {
      case 0xdb0:
        if ((3 < ustride) && (3 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Color_ListExec_001101bc,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2ColordLoad)(glContext,extraout_r4_01,iVar3,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,
                               v1ShadowHi,v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,
                               u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,
                               incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb1:
        if ((0 < ustride) && (0 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -4 + 0x1b0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Index_ListExec_001101b8,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2IndexdLoad)(glContext,extraout_r4_02,iVar3,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,
                               v1ShadowHi,v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,
                               u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,
                               incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb2:
        if ((2 < ustride) && (2 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Normal_ListExec_001101b4,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2NormaldLoad)(glContext,extraout_r4_03,iVar3,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,
                                v1ShadowHi,v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,
                                u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,
                                incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb3:
        if ((0 < ustride) && (0 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -4 + 0x1b0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture1_ListExec_001101b0,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture1dLoad)(glContext,extraout_r4_04,iVar3,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                       v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,u2,v1
                       ,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb4:
        if ((1 < ustride) && (1 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -8 + 0x340;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture2_ListExec_001101ac,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture2dLoad)(glContext,extraout_r4_05,iVar3,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                       v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,u2,v1
                       ,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb5:
        if ((2 < ustride) && (2 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture3_ListExec_001101a8,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture3dLoad)(glContext,extraout_r4_06,iVar3,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                       v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,u2,v1
                       ,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb6:
        if ((3 < ustride) && (3 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture4_ListExec_001101a4,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture4dLoad)(glContext,extraout_r4_07,iVar3,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                       v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,u2,v1
                       ,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb7:
        if ((2 < ustride) && (2 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Vertex3_ListExec_001101c4,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Vertex3dLoad)(glContext,extraout_r4,iVar3,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                       v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,u2,v1
                       ,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb8:
        if ((3 < ustride) && (3 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Vertex4_ListExec_001101c0,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Vertex4dLoad)(glContext,extraout_r4_00,iVar3,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                       v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,u2,v1
                       ,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) goto LAB_00070908;
        glErrorCode = 0x500;
        goto LAB_00070904;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00070908;
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00070908;
    glErrorCode = 0x502;
  }
LAB_00070904:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_00070908:
  return;
}

/* _glMap2d_Exec @ 0x70914 (1140 bytes) */
void _glMap2d_Exec(int glContext,int target,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,int ustride,int uorder,undefined4 v1ShadowHi,undefined4 v1ShadowLo,undefined4 v2ShadowHi,undefined4 v2ShadowLo,int vstride,int vorder,undefined4 points,double u1,double u2,double v1,double v2)
{
  undefined4 glErrorCode;
  int mapData;
  int iVar3;
  int iVar4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  iVar4 = uorder;
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((u1 != u2) && (v1 != v2)) && (uorder - 1U < 10)) &&
       ((0 < vorder && (vorder < 0xb)))) {
      iVar3 = target + -0xdb0;
      switch(iVar3) {
      case 0:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2ColordLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                             v1ShadowLo,v2ShadowHi,vstride,vorder,points,mapData + 0x1478,u1,
                             u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                             incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 1:
        if ((0 < ustride) && (0 < vstride)) {
          ((void (*)())_gleMap2IndexdLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                             v1ShadowLo,v2ShadowHi,vstride,vorder,points,mapData + 0x1ad8,u1,
                             u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                             incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 2:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2NormaldLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                              v1ShadowLo,v2ShadowHi,vstride,vorder,points,mapData + 0xfa8,u1,
                              u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11
                              ,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 3:
        if ((0 < ustride) && (0 < vstride)) {
          ((void (*)())_gleMap2Texture1dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,v1ShadowLo,
                     v2ShadowHi,vstride,vorder,points,mapData + 0x1c88,u1,u2,v1,
                     v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 4:
        if ((1 < ustride) && (1 < vstride)) {
          ((void (*)())_gleMap2Texture2dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,v1ShadowLo,
                     v2ShadowHi,vstride,vorder,points,mapData + 0x1e38,u1,u2,v1,
                     v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 5:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2Texture3dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,v1ShadowLo,
                     v2ShadowHi,vstride,vorder,points,mapData + 0x2178,u1,u2,v1,
                     v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 6:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2Texture4dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,v1ShadowLo,
                     v2ShadowHi,vstride,vorder,points,mapData + 0x2648,u1,u2,v1,
                     v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 7:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2Vertex3dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,v1ShadowLo,
                     v2ShadowHi,vstride,vorder,points,mapData + 0x478,u1,u2,v1,
                     v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 8:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2Vertex4dLoad)(glContext,iVar3,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,v1ShadowLo,
                     v2ShadowHi,vstride,vorder,points,mapData + 0x948,u1,u2,v1,
                     v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      default:
        if (*(int *)(glContext + 0x7574) != 0) goto LAB_00070da0;
        glErrorCode = 0x500;
        goto LAB_00070d9c;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00070da0;
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00070da0;
    glErrorCode = 0x502;
  }
LAB_00070d9c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_00070da0:
  return;
}

/* _glMap2d_CompExec @ 0x70dac (156 bytes) */
void _glMap2d_CompExec(undefined4 glContext,undefined4 target,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,undefined4 ustride,undefined4 uorder,undefined4 v1ShadowHi,undefined4 v1ShadowLo,undefined4 v2ShadowHi,undefined4 v2ShadowLo,undefined4 vstride,undefined4 vorder,undefined4 points,double u1,double u2,double v1,double v2)
{
  undefined4 incomingStack_ffffff88;
  undefined4 incomingStack_ffffff8c;
  undefined4 incomingStack_ffffff90;
  undefined4 incomingStack_ffffff94;
  
  ((void (*)())_glMap2d_Comp)(glContext,target,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,ustride,uorder,incomingStack_ffffff88,
                incomingStack_ffffff8c,incomingStack_ffffff90,incomingStack_ffffff94,vstride,vorder,points,
                u1,u2,v1,v2);
  ((void (*)())_glMap2d_Exec)(glContext,target,u1ShadowHi,u1ShadowLo,u2ShadowHi,u2ShadowLo,ustride,uorder,v1ShadowHi,v1ShadowLo,
                v2ShadowHi,v2ShadowLo,vstride,vorder,points,u1,u2,v1,v2);
  return;
}

/* _glMap2f_Comp @ 0x70e48 (1420 bytes) */
void _glMap2f_Comp(int glContext,int target,undefined4 u1Shadow,undefined4 u2Shadow,int ustride,int uorder,undefined4 v1Shadow,undefined4 v2Shadow,int vstride,int vorder,undefined4 points,float u1,float u2,float v1,float v2)
{
  undefined4 glErrorCode;
  int listRecord;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  int iVar3;
  int iVar4;
  int iVar5;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((u1 != u2) && (v1 != v2)) && (uorder - 1U < 10)) &&
       ((0 < vorder && (vorder < 0xb)))) {
      if (8 < target - 0xdb0U) {
        if (*(int *)(glContext + 0x7574) != 0) goto LAB_000713ec;
        glErrorCode = 0x500;
        goto LAB_000713e8;
      }
      iVar5 = (target - 0xdb0U) * 4;
      switch(target) {
      case 0xdb0:
        if ((3 < ustride) && (3 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Color_ListExec_001101bc,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2ColorfLoad)(glContext,extraout_r4_01,iVar3,ustride,uorder,iVar4,iVar5,vstride,
                               vorder,points,listRecord,u1,u2,v1,v2,incomingFpr5,
                               incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb1:
        if ((0 < ustride) && (0 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -4 + 0x1b0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Index_ListExec_001101b8,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2IndexfLoad)(glContext,extraout_r4_02,iVar3,ustride,uorder,iVar4,iVar5,vstride,
                               vorder,points,listRecord,u1,u2,v1,v2,incomingFpr5,
                               incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb2:
        if ((2 < ustride) && (2 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Normal_ListExec_001101b4,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2NormalfLoad)(glContext,extraout_r4_03,iVar3,ustride,uorder,iVar4,iVar5,vstride,
                                vorder,points,listRecord,u1,u2,v1,v2,incomingFpr5,
                                incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb3:
        if ((0 < ustride) && (0 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -4 + 0x1b0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture1_ListExec_001101b0,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture1fLoad)(glContext,extraout_r4_04,iVar3,ustride,uorder,iVar4,iVar5,vstride,vorder,
                       points,listRecord,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                       incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb4:
        if ((1 < ustride) && (1 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -8 + 0x340;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture2_ListExec_001101ac,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture2fLoad)(glContext,extraout_r4_05,iVar3,ustride,uorder,iVar4,iVar5,vstride,vorder,
                       points,listRecord,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                       incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb5:
        if ((2 < ustride) && (2 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture3_ListExec_001101a8,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture3fLoad)(glContext,extraout_r4_06,iVar3,ustride,uorder,iVar4,iVar5,vstride,vorder,
                       points,listRecord,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                       incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb6:
        if ((3 < ustride) && (3 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture4_ListExec_001101a4,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture4fLoad)(glContext,extraout_r4_07,iVar3,ustride,uorder,iVar4,iVar5,vstride,vorder,
                       points,listRecord,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                       incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb7:
        if ((2 < ustride) && (2 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Vertex3_ListExec_001101c4,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Vertex3fLoad)(glContext,extraout_r4,iVar3,ustride,uorder,iVar4,iVar5,vstride,vorder,
                       points,listRecord,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                       incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb8:
        if ((3 < ustride) && (3 < vstride)) {
          iVar3 = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Vertex4_ListExec_001101c0,iVar3);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Vertex4fLoad)(glContext,extraout_r4_00,iVar3,ustride,uorder,iVar4,iVar5,vstride,vorder,
                       points,listRecord,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                       incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_000713ec;
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_000713ec;
    glErrorCode = 0x502;
  }
LAB_000713e8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_000713ec:
  return;
}

/* _glMap2f_Exec @ 0x713f8 (1140 bytes) */
void _glMap2f_Exec(int glContext,int target,undefined4 u1Shadow,undefined4 u2Shadow,int ustride,int uorder,undefined4 v1Shadow,undefined4 v2Shadow,int vstride,int vorder,undefined4 points,float u1,float u2,float v1,float v2)
{
  int iVar1;
  undefined4 glErrorCode;
  int mapData;
  uint uVar4;
  int iVar5;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  iVar5 = uorder;
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((u1 != u2) && (v1 != v2)) && (uorder - 1U < 10)) &&
       ((0 < vorder && (vorder < 0xb)))) {
      uVar4 = target - 0xdb0;
      if (8 < uVar4) {
        if (*(int *)(glContext + 0x7574) != 0) goto LAB_00071884;
        glErrorCode = 0x500;
        goto LAB_00071880;
      }
      iVar1 = uVar4 * 4;
      switch(uVar4) {
      case 0:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2ColorfLoad)(glContext,uVar4,u1Shadow,ustride,uorder,iVar5,iVar1,vstride,vorder,
                             points,mapData + 0x1478,u1,u2,v1,v2,incomingFpr5,incomingFpr6
                             ,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 1:
        if ((0 < ustride) && (0 < vstride)) {
          ((void (*)())_gleMap2IndexfLoad)(glContext,uVar4,u1Shadow,ustride,uorder,iVar5,iVar1,vstride,vorder,
                             points,mapData + 0x1ad8,u1,u2,v1,v2,incomingFpr5,incomingFpr6
                             ,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 2:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2NormalfLoad)(glContext,uVar4,u1Shadow,ustride,uorder,iVar5,iVar1,vstride,vorder,
                              points,mapData + 0xfa8,u1,u2,v1,v2,incomingFpr5,incomingFpr6
                              ,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 3:
        if ((0 < ustride) && (0 < vstride)) {
          ((void (*)())_gleMap2Texture1fLoad)(glContext,uVar4,u1Shadow,ustride,uorder,iVar5,iVar1,vstride,vorder,points,
                     mapData + 0x1c88,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                     incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 4:
        if ((1 < ustride) && (1 < vstride)) {
          ((void (*)())_gleMap2Texture2fLoad)(glContext,uVar4,u1Shadow,ustride,uorder,iVar5,iVar1,vstride,vorder,points,
                     mapData + 0x1e38,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                     incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 5:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2Texture3fLoad)(glContext,uVar4,u1Shadow,ustride,uorder,iVar5,iVar1,vstride,vorder,points,
                     mapData + 0x2178,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                     incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 6:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2Texture4fLoad)(glContext,uVar4,u1Shadow,ustride,uorder,iVar5,iVar1,vstride,vorder,points,
                     mapData + 0x2648,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                     incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 7:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2Vertex3fLoad)(glContext,uVar4,u1Shadow,ustride,uorder,iVar5,iVar1,vstride,vorder,points,
                     mapData + 0x478,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9
                     ,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 8:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2Vertex4fLoad)(glContext,uVar4,u1Shadow,ustride,uorder,iVar5,iVar1,vstride,vorder,points,
                     mapData + 0x948,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9
                     ,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00071884;
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00071884;
    glErrorCode = 0x502;
  }
LAB_00071880:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_00071884:
  return;
}

/* _glMap2f_CompExec @ 0x71890 (156 bytes) */
void _glMap2f_CompExec(undefined4 glContext,undefined4 target,undefined4 u1Shadow,undefined4 u2Shadow,undefined4 ustride,undefined4 uorder,undefined4 v1Shadow,undefined4 v2Shadow,undefined4 vstride,undefined4 vorder,undefined4 points,float u1,float u2,float v1,float v2)
{
  ((void (*)())_glMap2f_Comp)(glContext,target,u1Shadow,u2Shadow,ustride,uorder,v1Shadow,v2Shadow,vstride,vorder,
                points,u1,u2,v1,v2);
  ((void (*)())_glMap2f_Exec)(glContext,target,u1Shadow,u2Shadow,ustride,uorder,v1Shadow,v2Shadow,vstride,vorder,
                points,u1,u2,v1,v2);
  return;
}

