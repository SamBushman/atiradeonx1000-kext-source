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
  byte dirtyBitIndex;
  float paramValue;
  undefined4 glErrorCode;
  uint paramEnum;
  undefined2 colorControl;
  int dirtyWordAddress348;
  int glContextPtr5424;
  int dirtyWordAddress324;
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
        dirtyBitIndex = *(byte *)(*(int *)(glContext + 0x5420) + 0x324);
      }
      else {
        dirtyBitIndex = *(byte *)(*(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x358);
      }
      dirtyWordAddress324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
      glContextPtr5424 = *(int *)(glContext + 0x5424);
      *(uint *)(dirtyWordAddress324 + 0x324) = *(uint *)(dirtyWordAddress324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
      dirtyBitIndex = *(byte *)(glContextPtr5424 + 0x324);
      dirtyWordAddress348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
      *(uint *)(dirtyWordAddress348 + 0x348) = *(uint *)(dirtyWordAddress348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
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
      paramValue = *params;
      dVar8 = (double)paramValue;
      if (DOUBLE_00108d80 <= (double)dVar8) {
        paramEnum = (int)((double)dVar8 - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        paramEnum = (uint)(int)paramValue;
      }
      if (1 < paramEnum - 0x81f9) goto LAB_0006d214;
      if (DOUBLE_00108d80 <= (double)dVar8) {
        colorControl = (undefined2)(int)((double)dVar8 - DOUBLE_00108d80);
      }
      else {
        colorControl = (undefined2)(int)paramValue;
      }
      *(undefined2 *)(glContext + 0x30a8) = colorControl;
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
  int glContextPtr5424;
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
      glContextPtr5424 = *(int *)(glContext + 0x5424);
      *(uint *)(iVar5 + 0x324) = *(uint *)(iVar5 + 0x324) | 1 << (bVar1 & 0x1f);
      bVar1 = *(byte *)(glContextPtr5424 + 0x324);
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
  int *pointComponent0Ptr;
  int invUDeltaBits;
  int pointComponent1;
  int pointComponent2;
  int order;
  int *mapDataThenPointDest;
  int u2Bits;
  int remaining;
  
  mapDataThenPointDest = (int *)_gleGetMapData(glContext);
  order = *listRecord;
  u2Bits = listRecord[2];
  invUDeltaBits = listRecord[3];
  mapDataThenPointDest[1] = listRecord[1];
  mapDataThenPointDest[2] = u2Bits;
  mapDataThenPointDest[3] = invUDeltaBits;
  *mapDataThenPointDest = order;
  for (remaining = order; remaining != 0; remaining = remaining + -1) {
    pointComponent0Ptr = listRecord + 4;
    pointComponent1 = listRecord[5];
    pointComponent2 = listRecord[6];
    listRecord = listRecord + 3;
    mapDataThenPointDest[4] = *pointComponent0Ptr;
    mapDataThenPointDest[5] = pointComponent1;
    mapDataThenPointDest[6] = pointComponent2;
    mapDataThenPointDest = mapDataThenPointDest + 3;
  }
  return (10 - order) * -0xc + 0x88;
}

/* _glMap1Vertex4_ListExec @ 0x6da40 (156 bytes) */
int _glMap1Vertex4_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int invUDeltaBits;
  int pointComponent0;
  int pointComponent1;
  int pointComponent2;
  int order;
  int mapData;
  int iVar7;
  int u2Bits;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  order = *listRecord;
  u2Bits = listRecord[2];
  invUDeltaBits = listRecord[3];
  *(int *)(mapData + 0x8c) = listRecord[1];
  *(int *)(mapData + 0x90) = u2Bits;
  *(int *)(mapData + 0x94) = invUDeltaBits;
  *(int *)(mapData + 0x88) = order;
  iVar1 = 0;
  for (remaining = order; remaining != 0; remaining = remaining + -1) {
    iVar7 = iVar1 * 0x10 + mapData;
    pointComponent0 = listRecord[iVar1 * 4 + 4];
    pointComponent1 = listRecord[iVar1 * 4 + 5];
    pointComponent2 = listRecord[iVar1 * 4 + 6];
    *(int *)(iVar7 + 0xa4) = listRecord[iVar1 * 4 + 7];
    *(int *)(iVar7 + 0x98) = pointComponent0;
    *(int *)(iVar7 + 0x9c) = pointComponent1;
    *(int *)(iVar7 + 0xa0) = pointComponent2;
    iVar1 = iVar1 + 1;
  }
  return (10 - order) * -0x10 + 0xb0;
}

/* _glMap1Color_ListExec @ 0x6dadc (156 bytes) */
int _glMap1Color_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int invUDeltaBits;
  int pointComponent0;
  int pointComponent1;
  int pointComponent2;
  int order;
  int mapData;
  int iVar7;
  int u2Bits;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  order = *listRecord;
  u2Bits = listRecord[2];
  invUDeltaBits = listRecord[3];
  *(int *)(mapData + 0x1c4) = listRecord[1];
  *(int *)(mapData + 0x1c8) = u2Bits;
  *(int *)(mapData + 0x1cc) = invUDeltaBits;
  *(int *)(mapData + 0x1c0) = order;
  iVar1 = 0;
  for (remaining = order; remaining != 0; remaining = remaining + -1) {
    iVar7 = iVar1 * 0x10 + mapData;
    pointComponent0 = listRecord[iVar1 * 4 + 4];
    pointComponent1 = listRecord[iVar1 * 4 + 5];
    pointComponent2 = listRecord[iVar1 * 4 + 6];
    *(int *)(iVar7 + 0x1dc) = listRecord[iVar1 * 4 + 7];
    *(int *)(iVar7 + 0x1d0) = pointComponent0;
    *(int *)(iVar7 + 0x1d4) = pointComponent1;
    *(int *)(iVar7 + 0x1d8) = pointComponent2;
    iVar1 = iVar1 + 1;
  }
  return (10 - order) * -0x10 + 0xb0;
}

/* _glMap1Index_ListExec @ 0x6db78 (128 bytes) */
int _glMap1Index_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int pointValueBits;
  int invUDeltaBits;
  int order;
  int mapData;
  int *dstCursor;
  int *srcCursor;
  int u2Bits;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  order = *listRecord;
  u2Bits = listRecord[2];
  invUDeltaBits = listRecord[3];
  *(int *)(mapData + 0x274) = listRecord[1];
  *(int *)(mapData + 0x278) = u2Bits;
  *(int *)(mapData + 0x27c) = invUDeltaBits;
  *(int *)(mapData + 0x270) = order;
  if (order != 0) {
    dstCursor = (int *)(mapData + 0x280);
    srcCursor = listRecord + 4;
    remaining = order;
    do {
      pointValueBits = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = pointValueBits;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return (10 - order) * -4 + 0x38;
}

/* _glMap1Normal_ListExec @ 0x6dbf8 (140 bytes) */
int _glMap1Normal_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int invUDeltaBits;
  int pointComponent1;
  int pointComponent2;
  int order;
  int iVar5;
  int u2Bits;
  int remaining;
  
  iVar5 = _gleGetMapData(glContext);
  order = *listRecord;
  u2Bits = listRecord[2];
  invUDeltaBits = listRecord[3];
  *(int *)(iVar5 + 0x13c) = listRecord[1];
  *(int *)(iVar5 + 0x140) = u2Bits;
  *(int *)(iVar5 + 0x144) = invUDeltaBits;
  *(int *)(iVar5 + 0x138) = order;
  for (remaining = order; remaining != 0; remaining = remaining + -1) {
    piVar1 = listRecord + 4;
    pointComponent1 = listRecord[5];
    pointComponent2 = listRecord[6];
    listRecord = listRecord + 3;
    *(int *)(iVar5 + 0x148) = *piVar1;
    *(int *)(iVar5 + 0x14c) = pointComponent1;
    *(int *)(iVar5 + 0x150) = pointComponent2;
    iVar5 = iVar5 + 0xc;
  }
  return (10 - order) * -0xc + 0x88;
}

/* _glMap1Texture1_ListExec @ 0x6dc84 (128 bytes) */
int _glMap1Texture1_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int invUDeltaBits;
  int order;
  int mapData;
  int *dstCursor;
  int *srcCursor;
  int u2Bits;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  order = *listRecord;
  u2Bits = listRecord[2];
  invUDeltaBits = listRecord[3];
  *(int *)(mapData + 0x2ac) = listRecord[1];
  *(int *)(mapData + 0x2b0) = u2Bits;
  *(int *)(mapData + 0x2b4) = invUDeltaBits;
  *(int *)(mapData + 0x2a8) = order;
  if (order != 0) {
    dstCursor = (int *)(mapData + 0x2b8);
    srcCursor = listRecord + 4;
    remaining = order;
    do {
      iVar1 = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = iVar1;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return (10 - order) * -4 + 0x38;
}

/* _glMap1Texture2_ListExec @ 0x6dd04 (140 bytes) */
int _glMap1Texture2_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int invUDeltaBits;
  int pointComponent0;
  int order;
  int iVar4;
  int mapData;
  int u2Bits;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  order = *listRecord;
  u2Bits = listRecord[2];
  invUDeltaBits = listRecord[3];
  *(int *)(mapData + 0x2e4) = listRecord[1];
  *(int *)(mapData + 0x2e8) = u2Bits;
  *(int *)(mapData + 0x2ec) = invUDeltaBits;
  *(int *)(mapData + 0x2e0) = order;
  iVar1 = 0;
  for (remaining = order; remaining != 0; remaining = remaining + -1) {
    iVar4 = iVar1 * 8 + mapData;
    pointComponent0 = listRecord[iVar1 * 2 + 4];
    *(int *)(iVar4 + 0x2f4) = listRecord[iVar1 * 2 + 5];
    *(int *)(iVar4 + 0x2f0) = pointComponent0;
    iVar1 = iVar1 + 1;
  }
  return (10 - order) * -8 + 0x60;
}

/* _glMap1Texture3_ListExec @ 0x6dd90 (140 bytes) */
int _glMap1Texture3_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int invUDeltaBits;
  int pointComponent1;
  int pointComponent2;
  int order;
  int iVar5;
  int u2Bits;
  int remaining;
  
  iVar5 = _gleGetMapData(glContext);
  order = *listRecord;
  u2Bits = listRecord[2];
  invUDeltaBits = listRecord[3];
  *(int *)(iVar5 + 0x344) = listRecord[1];
  *(int *)(iVar5 + 0x348) = u2Bits;
  *(int *)(iVar5 + 0x34c) = invUDeltaBits;
  *(int *)(iVar5 + 0x340) = order;
  for (remaining = order; remaining != 0; remaining = remaining + -1) {
    piVar1 = listRecord + 4;
    pointComponent1 = listRecord[5];
    pointComponent2 = listRecord[6];
    listRecord = listRecord + 3;
    *(int *)(iVar5 + 0x350) = *piVar1;
    *(int *)(iVar5 + 0x354) = pointComponent1;
    *(int *)(iVar5 + 0x358) = pointComponent2;
    iVar5 = iVar5 + 0xc;
  }
  return (10 - order) * -0xc + 0x88;
}

/* _glMap1Texture4_ListExec @ 0x6de1c (156 bytes) */
int _glMap1Texture4_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int pointIndex;
  int invUDeltaBits;
  int pointComponent0;
  int pointComponent1;
  int pointComponent2;
  int order;
  int mapData;
  int pointRecord;
  int u2Bits;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  order = *listRecord;
  u2Bits = listRecord[2];
  invUDeltaBits = listRecord[3];
  *(int *)(mapData + 0x3cc) = listRecord[1];
  *(int *)(mapData + 0x3d0) = u2Bits;
  *(int *)(mapData + 0x3d4) = invUDeltaBits;
  *(int *)(mapData + 0x3c8) = order;
  pointIndex = 0;
  for (remaining = order; remaining != 0; remaining = remaining + -1) {
    pointRecord = pointIndex * 0x10 + mapData;
    pointComponent0 = listRecord[pointIndex * 4 + 4];
    pointComponent1 = listRecord[pointIndex * 4 + 5];
    pointComponent2 = listRecord[pointIndex * 4 + 6];
    *(int *)(pointRecord + 0x3e4) = listRecord[pointIndex * 4 + 7];
    *(int *)(pointRecord + 0x3d8) = pointComponent0;
    *(int *)(pointRecord + 0x3dc) = pointComponent1;
    *(int *)(pointRecord + 0x3e0) = pointComponent2;
    pointIndex = pointIndex + 1;
  }
  return (10 - order) * -0x10 + 0xb0;
}

/* _glMap1VertexAttrib1ARB_ListExec @ 0x6deb8 (164 bytes) */
int _glMap1VertexAttrib1ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *srcCursor;
  int u1Bits;
  int remaining;
  int mapData;
  int iVar3;
  int *dstCursor;
  int iVar5;
  int u2Bits;
  int attribIndex;
  int order;
  
  mapData = _gleGetMapData(glContext);
  attribIndex = *listRecord;
  order = listRecord[1];
  iVar3 = mapData + attribIndex * 0xb0;
  *(int *)(iVar3 + 0x2ca8) = order;
  ((unsigned char *)0x9da8)[attribIndex + mapData] = 0x1;
  u1Bits = listRecord[2];
  u2Bits = listRecord[3];
  *(int *)(iVar3 + 0x2cb4) = listRecord[4];
  *(int *)(iVar3 + 0x2cac) = u1Bits;
  *(int *)(iVar3 + 0x2cb0) = u2Bits;
  if (order != 0) {
    dstCursor = (int *)(iVar3 + 0x2cb8);
    srcCursor = listRecord + 5;
    remaining = order;
    do {
      iVar5 = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = iVar5;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return (10 - order) * -4 + 0x3c;
}

/* _glMap1VertexAttrib2ARB_ListExec @ 0x6df5c (164 bytes) */
int _glMap1VertexAttrib2ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int attribIndex;
  int u2Bits;
  int remaining;
  int iVar3;
  int invUDeltaBits;
  int mapData;
  int iVar4;
  int iVar5;
  int order;
  int *srcCursor;
  
  mapData = _gleGetMapData(glContext);
  attribIndex = *listRecord;
  order = listRecord[1];
  srcCursor = listRecord + 1;
  iVar4 = mapData + attribIndex * 0xb0;
  *(int *)(iVar4 + 0x2ca8) = order;
  iVar5 = iVar4 + 0x2ca8;
  ((unsigned char *)0x9da8)[attribIndex + mapData] = 0x2;
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[4];
  *(int *)(iVar4 + 0x2cac) = listRecord[2];
  *(int *)(iVar4 + 0x2cb0) = u2Bits;
  *(int *)(iVar4 + 0x2cb4) = invUDeltaBits;
  for (remaining = order; remaining != 0; remaining = remaining + -1) {
    piVar1 = srcCursor + 4;
    iVar3 = srcCursor[5];
    srcCursor = srcCursor + 2;
    *(int *)(iVar5 + 0x10) = *piVar1;
    *(int *)(iVar5 + 0x14) = iVar3;
    iVar5 = iVar5 + 8;
  }
  return (10 - order) * -8 + 100;
}

/* _glMap1VertexAttrib3ARB_ListExec @ 0x6e000 (172 bytes) */
int _glMap1VertexAttrib3ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *pointComponent0Ptr;
  int attribIndex;
  int u2Bits;
  int remaining;
  int pointComponent1;
  int invUDeltaBits;
  int mapData;
  int attribMapThenPointComponent2;
  int controlPointDest;
  int order;
  int *srcCursor;
  
  mapData = _gleGetMapData(glContext);
  attribIndex = *listRecord;
  order = listRecord[1];
  srcCursor = listRecord + 1;
  attribMapThenPointComponent2 = mapData + attribIndex * 0xb0;
  *(int *)(attribMapThenPointComponent2 + 0x2ca8) = order;
  controlPointDest = attribMapThenPointComponent2 + 0x2ca8;
  ((unsigned char *)0x9da8)[attribIndex + mapData] = 0x3;
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[4];
  *(int *)(attribMapThenPointComponent2 + 0x2cac) = listRecord[2];
  *(int *)(attribMapThenPointComponent2 + 0x2cb0) = u2Bits;
  *(int *)(attribMapThenPointComponent2 + 0x2cb4) = invUDeltaBits;
  for (remaining = order; remaining != 0; remaining = remaining + -1) {
    pointComponent0Ptr = srcCursor + 4;
    pointComponent1 = srcCursor[5];
    attribMapThenPointComponent2 = srcCursor[6];
    srcCursor = srcCursor + 3;
    *(int *)(controlPointDest + 0x10) = *pointComponent0Ptr;
    *(int *)(controlPointDest + 0x14) = pointComponent1;
    *(int *)(controlPointDest + 0x18) = attribMapThenPointComponent2;
    controlPointDest = controlPointDest + 0xc;
  }
  return (10 - order) * -0xc + 0x8c;
}

/* _glMap1VertexAttrib4ARB_ListExec @ 0x6e0ac (200 bytes) */
int _glMap1VertexAttrib4ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int attribIndex;
  int u2Bits;
  int remaining;
  int iVar2;
  int invUDeltaBits;
  int mapData;
  int iVar3;
  int order;
  int pointComponent2;
  int pointComponent1;
  int pointComponent3;
  int iVar8;
  
  mapData = _gleGetMapData(glContext);
  attribIndex = *listRecord;
  order = listRecord[1];
  iVar3 = mapData + attribIndex * 0xb0;
  *(int *)(iVar3 + 0x2ca8) = order;
  ((unsigned char *)0x9da8)[attribIndex + mapData] = 0x4;
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[4];
  *(int *)(iVar3 + 0x2cac) = listRecord[2];
  *(int *)(iVar3 + 0x2cb0) = u2Bits;
  *(int *)(iVar3 + 0x2cb4) = invUDeltaBits;
  iVar2 = 0;
  for (remaining = order; remaining != 0; remaining = remaining + -1) {
    iVar8 = iVar2 * 0x10 + iVar3 + 0x2ca8;
    pointComponent3 = listRecord[iVar2 * 4 + 8];
    pointComponent1 = listRecord[iVar2 * 4 + 6];
    pointComponent2 = listRecord[iVar2 * 4 + 7];
    *(int *)(iVar8 + 0x10) = listRecord[iVar2 * 4 + 5];
    *(int *)(iVar8 + 0x1c) = pointComponent3;
    *(int *)(iVar8 + 0x14) = pointComponent1;
    *(int *)(iVar8 + 0x18) = pointComponent2;
    iVar2 = iVar2 + 1;
  }
  return (10 - order) * -0x10 + 0xb4;
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
  int recordSize;
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
          recordSize = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Color_ListExec_00110188,recordSize);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1ColordLoad)(glContext,extraout_r4_01,recordSize,u1ShadowLo,u2ShadowHi,stride,order,points,
                             listRecord,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,
                             incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd91:
        if (0 < stride) {
          recordSize = (10 - order) * -4 + 0x38;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Index_ListExec_00110184,recordSize);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1IndexdLoad)(glContext,extraout_r4_02,recordSize,u1ShadowLo,u2ShadowHi,stride,order,points,
                             listRecord,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,
                             incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd92:
        if (2 < stride) {
          recordSize = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Normal_ListExec_00110180,recordSize);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1NormaldLoad)(glContext,extraout_r4_03,recordSize,u1ShadowLo,u2ShadowHi,stride,order,points,
                              listRecord,u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,
                              incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd93:
        if (0 < stride) {
          recordSize = (10 - order) * -4 + 0x38;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture1_ListExec_0011017c,recordSize);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Texture1dLoad)(glContext,extraout_r4_04,recordSize,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd94:
        if (1 < stride) {
          recordSize = (10 - order) * -8 + 0x60;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture2_ListExec_00110178,recordSize);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Texture2dLoad)(glContext,extraout_r4_05,recordSize,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd95:
        if (2 < stride) {
          recordSize = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture3_ListExec_00110174,recordSize);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Texture3dLoad)(glContext,extraout_r4_06,recordSize,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd96:
        if (3 < stride) {
          recordSize = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture4_ListExec_00110170,recordSize);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Texture4dLoad)(glContext,extraout_r4_07,recordSize,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd97:
        if (2 < stride) {
          recordSize = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Vertex3_ListExec_00110190,recordSize);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Vertex3dLoad)(glContext,extraout_r4,recordSize,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                     incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 0xd98:
        if (3 < stride) {
          recordSize = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Vertex4_ListExec_0011018c,recordSize);
          if (listRecord == 0) {
            return;
          }
          ((void (*)())_gleMap1Vertex4dLoad)(glContext,extraout_r4_00,recordSize,u1ShadowLo,u2ShadowHi,stride,order,points,listRecord,
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
  int recordSize;
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
          recordSize = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Color_ListExec_00110188,recordSize);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1ColorfLoad)(glContext,extraout_r4_01,recordSize,stride,order,points,listRecord,
                                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd91:
        if (0 < stride) {
          recordSize = (10 - order) * -4 + 0x38;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Index_ListExec_00110184,recordSize);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1IndexfLoad)(glContext,extraout_r4_02,recordSize,stride,order,points,listRecord,
                                     u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                     (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd92:
        if (2 < stride) {
          recordSize = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Normal_ListExec_00110180,recordSize);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1NormalfLoad)(glContext,extraout_r4_03,recordSize,stride,order,points,listRecord,
                                      u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                                      (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                                      (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd93:
        if (0 < stride) {
          recordSize = (10 - order) * -4 + 0x38;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture1_ListExec_0011017c,recordSize);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture1fLoad)(glContext,extraout_r4_04,recordSize,stride,order,points,listRecord,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd94:
        if (1 < stride) {
          recordSize = (10 - order) * -8 + 0x60;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture2_ListExec_00110178,recordSize);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture2fLoad)(glContext,extraout_r4_05,recordSize,stride,order,points,listRecord,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd95:
        if (2 < stride) {
          recordSize = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture3_ListExec_00110174,recordSize);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture3fLoad)(glContext,extraout_r4_06,recordSize,stride,order,points,listRecord,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd96:
        if (3 < stride) {
          recordSize = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Texture4_ListExec_00110170,recordSize);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Texture4fLoad)(glContext,extraout_r4_07,recordSize,stride,order,points,listRecord,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd97:
        if (2 < stride) {
          recordSize = (10 - order) * -0xc + 0x88;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Vertex3_ListExec_00110190,recordSize);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Vertex3fLoad)(glContext,extraout_r4,recordSize,stride,order,points,listRecord,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return uVar1;
        }
        break;
      case 0xd98:
        if (3 < stride) {
          recordSize = (10 - order) * -0x10 + 0xb0;
          listRecord = _gleAddListItem(glContext,PTR__glMap1Vertex4_ListExec_0011018c,recordSize);
          if (listRecord == 0) {
            return 0;
          }
          uVar1 = ((int (*)())_gleMap1Vertex4fLoad)(glContext,extraout_r4_00,recordSize,stride,order,points,listRecord,u1,
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
  int mapTypeIndex;
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
      mapTypeIndex = target + -0xd90;
      switch(mapTypeIndex) {
      case 0:
        if (3 < stride) {
          ((int (*)())_gleMap1ColorfLoad)(glContext,mapTypeIndex,u1Shadow,stride,order,points,mapData + 0x1c0,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 1:
        if (0 < stride) {
          ((int (*)())_gleMap1IndexfLoad)(glContext,mapTypeIndex,u1Shadow,stride,order,points,mapData + 0x270,u1,
                             u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                             (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 2:
        if (2 < stride) {
          ((int (*)())_gleMap1NormalfLoad)(glContext,mapTypeIndex,u1Shadow,stride,order,points,mapData + 0x138,u1,
                              u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                              (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                              (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 3:
        if (0 < stride) {
          ((int (*)())_gleMap1Texture1fLoad)(glContext,mapTypeIndex,u1Shadow,stride,order,points,mapData + 0x2a8,u1,u2,
                     incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 4:
        if (1 < stride) {
          ((int (*)())_gleMap1Texture2fLoad)(glContext,mapTypeIndex,u1Shadow,stride,order,points,mapData + 0x2e0,u1,u2,
                     incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 5:
        if (2 < stride) {
          ((int (*)())_gleMap1Texture3fLoad)(glContext,mapTypeIndex,u1Shadow,stride,order,points,mapData + 0x340,u1,u2,
                     incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 6:
        if (3 < stride) {
          ((int (*)())_gleMap1Texture4fLoad)(glContext,mapTypeIndex,u1Shadow,stride,order,points,mapData + 0x3c8,u1,u2,
                     incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 7:
        if (2 < stride) {
          ((int (*)())_gleMap1Vertex3fLoad)(glContext,mapTypeIndex,u1Shadow,stride,order,points,mapData,u1,u2,incomingFpr3,
                     incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,(double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),
                     (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
          return;
        }
        break;
      case 8:
        if (3 < stride) {
          ((int (*)())_gleMap1Vertex4fLoad)(glContext,mapTypeIndex,u1Shadow,stride,order,points,mapData + 0x88,u1,u2,
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
  int recordSize;
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
    recordSize = (10 - order) * -8 + 100;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib2ARB_ListExec_00110168,recordSize);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib2fLoad)(glContext,extraout_r4_00,recordSize,stride,order,points,listRecord + 1,u1,u2,
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
    recordSize = (10 - order) * -4 + 0x3c;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib1ARB_ListExec_0011016c,recordSize);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib1fLoad)(glContext,extraout_r4,recordSize,stride,order,points,listRecord + 1,u1,u2,incomingFpr3,
               incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff98,incomingStack_ffffffa0,incomingStack_ffffffa8,
               incomingStack_ffffffb0,incomingStack_ffffffb8);
  }
  else if (size == 3) {
    recordSize = (10 - order) * -0xc + 0x8c;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib3ARB_ListExec_00110164,recordSize);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib3fLoad)(glContext,extraout_r4_01,recordSize,stride,order,points,listRecord + 1,u1,u2,
               incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingStack_ffffff98,incomingStack_ffffffa0,
               incomingStack_ffffffa8,incomingStack_ffffffb0,incomingStack_ffffffb8);
  }
  else {
    if (size != 4) goto LAB_0006f31c;
    recordSize = (10 - order) * -0x10 + 0xb4;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib4ARB_ListExec_00110160,recordSize);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib4fLoad)(glContext,extraout_r4_02,recordSize,stride,order,points,listRecord + 1,u1,u2,
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
  int recordSize;
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
    recordSize = (10 - order) * -8 + 100;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib2ARB_ListExec_00110168,recordSize);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib2dLoad)(glContext,extraout_r4_00,recordSize,u1ShadowHi,u1ShadowLo,stride,order,points,listRecord + 1,
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
    recordSize = (10 - order) * -4 + 0x3c;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib1ARB_ListExec_0011016c,recordSize);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib1dLoad)(glContext,extraout_r4,recordSize,u1ShadowHi,u1ShadowLo,stride,order,points,listRecord + 1,
               u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,
               incomingFpr13);
  }
  else if (size == 3) {
    recordSize = (10 - order) * -0xc + 0x8c;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib3ARB_ListExec_00110164,recordSize);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib3dLoad)(glContext,extraout_r4_01,recordSize,u1ShadowHi,u1ShadowLo,stride,order,points,listRecord + 1,
               u1,u2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,
               incomingFpr13);
  }
  else {
    if (size != 4) goto LAB_0006f710;
    recordSize = (10 - order) * -0x10 + 0xb4;
    listRecord = (undefined4 *)
             _gleAddListItem(glContext,PTR__glMap1VertexAttrib4ARB_ListExec_00110160,recordSize);
    if (listRecord == (undefined4 *)0x0) {
      return;
    }
    ((void (*)())_gleMap1VertexAttrib4dLoad)(glContext,extraout_r4_02,recordSize,u1ShadowHi,u1ShadowLo,stride,order,points,listRecord + 1,
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
  int invUDeltaBits;
  int pointComponent1;
  int v1Bits;
  int pointComponent2;
  int v2Bits;
  int invVDeltaBits;
  int vorder;
  int vorder2;
  int u2Bits;
  int remaining;
  int iVar8;
  int uorder;
  
  iVar8 = _gleGetMapData(glContext);
  vorder2 = listRecord[1];
  *(int *)(iVar8 + 0x478) = *listRecord;
  *(int *)(iVar8 + 0x47c) = vorder2;
  uorder = *listRecord;
  vorder = listRecord[1];
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[6];
  v1Bits = listRecord[4];
  v2Bits = listRecord[5];
  invVDeltaBits = listRecord[7];
  *(int *)(iVar8 + 0x480) = listRecord[2];
  *(int *)(iVar8 + 0x484) = u2Bits;
  *(int *)(iVar8 + 0x490) = invUDeltaBits;
  *(int *)(iVar8 + 0x488) = v1Bits;
  *(int *)(iVar8 + 0x48c) = v2Bits;
  *(int *)(iVar8 + 0x494) = invVDeltaBits;
  for (remaining = uorder * vorder; remaining != 0; remaining = remaining + -1) {
    piVar1 = listRecord + 8;
    pointComponent1 = listRecord[9];
    pointComponent2 = listRecord[10];
    listRecord = listRecord + 3;
    *(int *)(iVar8 + 0x498) = *piVar1;
    *(int *)(iVar8 + 0x49c) = pointComponent1;
    *(int *)(iVar8 + 0x4a0) = pointComponent2;
    iVar8 = iVar8 + 0xc;
  }
  return (100 - uorder * vorder) * -0xc + 0x4d0;
}

/* _glMap2Vertex4_ListExec @ 0x6fa40 (200 bytes) */
int _glMap2Vertex4_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int v1Bits;
  int pointComponent0;
  int v2Bits;
  int pointComponent1;
  int invVDeltaBits;
  int pointComponent2;
  int vorder;
  int iVar5;
  int u2Bits;
  int vorder2;
  int mapData;
  int uorder;
  int iVar8;
  int invUDeltaBits;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  vorder2 = listRecord[1];
  *(int *)(mapData + 0x948) = *listRecord;
  *(int *)(mapData + 0x94c) = vorder2;
  uorder = *listRecord;
  vorder = listRecord[1];
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[6];
  v1Bits = listRecord[4];
  v2Bits = listRecord[5];
  invVDeltaBits = listRecord[7];
  *(int *)(mapData + 0x950) = listRecord[2];
  *(int *)(mapData + 0x954) = u2Bits;
  *(int *)(mapData + 0x960) = invUDeltaBits;
  *(int *)(mapData + 0x958) = v1Bits;
  *(int *)(mapData + 0x95c) = v2Bits;
  *(int *)(mapData + 0x964) = invVDeltaBits;
  iVar5 = 0;
  for (remaining = uorder * vorder; remaining != 0; remaining = remaining + -1) {
    iVar8 = iVar5 * 0x10 + mapData;
    pointComponent0 = listRecord[iVar5 * 4 + 8];
    pointComponent1 = listRecord[iVar5 * 4 + 9];
    pointComponent2 = listRecord[iVar5 * 4 + 10];
    *(int *)(iVar8 + 0x974) = listRecord[iVar5 * 4 + 0xb];
    *(int *)(iVar8 + 0x968) = pointComponent0;
    *(int *)(iVar8 + 0x96c) = pointComponent1;
    *(int *)(iVar8 + 0x970) = pointComponent2;
    iVar5 = iVar5 + 1;
  }
  return (100 - uorder * vorder) * -0x10 + 0x660;
}

/* _glMap2Color_ListExec @ 0x6fb08 (200 bytes) */
int _glMap2Color_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int v1Bits;
  int pointComponent0;
  int v2Bits;
  int pointComponent1;
  int invVDeltaBits;
  int pointComponent2;
  int vorder;
  int iVar5;
  int u2Bits;
  int vorder2;
  int mapData;
  int uorder;
  int iVar8;
  int invUDeltaBits;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  vorder2 = listRecord[1];
  *(int *)(mapData + 0x1478) = *listRecord;
  *(int *)(mapData + 0x147c) = vorder2;
  uorder = *listRecord;
  vorder = listRecord[1];
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[6];
  v1Bits = listRecord[4];
  v2Bits = listRecord[5];
  invVDeltaBits = listRecord[7];
  *(int *)(mapData + 0x1480) = listRecord[2];
  *(int *)(mapData + 0x1484) = u2Bits;
  *(int *)(mapData + 0x1490) = invUDeltaBits;
  *(int *)(mapData + 0x1488) = v1Bits;
  *(int *)(mapData + 0x148c) = v2Bits;
  *(int *)(mapData + 0x1494) = invVDeltaBits;
  iVar5 = 0;
  for (remaining = uorder * vorder; remaining != 0; remaining = remaining + -1) {
    iVar8 = iVar5 * 0x10 + mapData;
    pointComponent0 = listRecord[iVar5 * 4 + 8];
    pointComponent1 = listRecord[iVar5 * 4 + 9];
    pointComponent2 = listRecord[iVar5 * 4 + 10];
    *(int *)(iVar8 + 0x14a4) = listRecord[iVar5 * 4 + 0xb];
    *(int *)(iVar8 + 0x1498) = pointComponent0;
    *(int *)(iVar8 + 0x149c) = pointComponent1;
    *(int *)(iVar8 + 0x14a0) = pointComponent2;
    iVar5 = iVar5 + 1;
  }
  return (100 - uorder * vorder) * -0x10 + 0x660;
}

/* _glMap2Index_ListExec @ 0x6fbd0 (168 bytes) */
int _glMap2Index_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int pointValueBits;
  int invUDeltaBits;
  int v1Bits;
  int v2Bits;
  int invVDeltaBits;
  int vorder;
  int u2Bits;
  int remaining;
  int mapData;
  int *dstCursor;
  int *srcCursor;
  int pointCount;
  
  mapData = _gleGetMapData(glContext);
  vorder = listRecord[1];
  *(int *)(mapData + 0x1ad8) = *listRecord;
  *(int *)(mapData + 0x1adc) = vorder;
  pointCount = *listRecord * listRecord[1];
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[6];
  v1Bits = listRecord[4];
  v2Bits = listRecord[5];
  invVDeltaBits = listRecord[7];
  *(int *)(mapData + 0x1ae0) = listRecord[2];
  *(int *)(mapData + 0x1ae4) = u2Bits;
  *(int *)(mapData + 0x1af0) = invUDeltaBits;
  *(int *)(mapData + 0x1ae8) = v1Bits;
  *(int *)(mapData + 0x1aec) = v2Bits;
  *(int *)(mapData + 0x1af4) = invVDeltaBits;
  if (pointCount != 0) {
    dstCursor = (int *)(mapData + 0x1af8);
    srcCursor = listRecord + 8;
    remaining = pointCount;
    do {
      pointValueBits = *srcCursor;
      srcCursor = srcCursor + 1;
      *dstCursor = pointValueBits;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  return (100 - pointCount) * -4 + 0x1b0;
}

/* _glMap2Normal_ListExec @ 0x6fc78 (180 bytes) */
int _glMap2Normal_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *pointComponent0Ptr;
  int invUDeltaBits;
  int pointComponent1;
  int v1Bits;
  int pointComponent2;
  int v2Bits;
  int invVDeltaBits;
  int vorder;
  int vorder2;
  int u2Bits;
  int remaining;
  int mapDataThenPointDest;
  int uorder;
  
  mapDataThenPointDest = _gleGetMapData(glContext);
  vorder2 = listRecord[1];
  *(int *)(mapDataThenPointDest + 0xfa8) = *listRecord;
  *(int *)(mapDataThenPointDest + 0xfac) = vorder2;
  uorder = *listRecord;
  vorder = listRecord[1];
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[6];
  v1Bits = listRecord[4];
  v2Bits = listRecord[5];
  invVDeltaBits = listRecord[7];
  *(int *)(mapDataThenPointDest + 0xfb0) = listRecord[2];
  *(int *)(mapDataThenPointDest + 0xfb4) = u2Bits;
  *(int *)(mapDataThenPointDest + 0xfc0) = invUDeltaBits;
  *(int *)(mapDataThenPointDest + 0xfb8) = v1Bits;
  *(int *)(mapDataThenPointDest + 0xfbc) = v2Bits;
  *(int *)(mapDataThenPointDest + 0xfc4) = invVDeltaBits;
  for (remaining = uorder * vorder; remaining != 0; remaining = remaining + -1) {
    pointComponent0Ptr = listRecord + 8;
    pointComponent1 = listRecord[9];
    pointComponent2 = listRecord[10];
    listRecord = listRecord + 3;
    *(int *)(mapDataThenPointDest + 0xfc8) = *pointComponent0Ptr;
    *(int *)(mapDataThenPointDest + 0xfcc) = pointComponent1;
    *(int *)(mapDataThenPointDest + 0xfd0) = pointComponent2;
    mapDataThenPointDest = mapDataThenPointDest + 0xc;
  }
  return (100 - uorder * vorder) * -0xc + 0x4d0;
}

/* _glMap2Texture1_ListExec @ 0x6fd2c (168 bytes) */
int _glMap2Texture1_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int invUDeltaBits;
  int v1Bits;
  int v2Bits;
  int invVDeltaBits;
  int vorder;
  int u2Bits;
  int remaining;
  int mapData;
  int *dstCursor;
  int *srcCursor;
  int iVar9;
  
  mapData = _gleGetMapData(glContext);
  vorder = listRecord[1];
  *(int *)(mapData + 0x1c88) = *listRecord;
  *(int *)(mapData + 0x1c8c) = vorder;
  iVar9 = *listRecord * listRecord[1];
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[6];
  v1Bits = listRecord[4];
  v2Bits = listRecord[5];
  invVDeltaBits = listRecord[7];
  *(int *)(mapData + 0x1c90) = listRecord[2];
  *(int *)(mapData + 0x1c94) = u2Bits;
  *(int *)(mapData + 0x1ca0) = invUDeltaBits;
  *(int *)(mapData + 0x1c98) = v1Bits;
  *(int *)(mapData + 0x1c9c) = v2Bits;
  *(int *)(mapData + 0x1ca4) = invVDeltaBits;
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
  int v1Bits;
  int pointComponent0;
  int invVDeltaBits;
  int vorder;
  int pointIndex;
  int u2Bits;
  int vorder2;
  int pointRecord;
  int v2Bits;
  int mapData;
  int uorder;
  int invUDeltaBits;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  vorder2 = listRecord[1];
  *(int *)(mapData + 0x1e38) = *listRecord;
  *(int *)(mapData + 0x1e3c) = vorder2;
  uorder = *listRecord;
  vorder = listRecord[1];
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[6];
  v1Bits = listRecord[4];
  v2Bits = listRecord[5];
  invVDeltaBits = listRecord[7];
  *(int *)(mapData + 0x1e40) = listRecord[2];
  *(int *)(mapData + 0x1e44) = u2Bits;
  *(int *)(mapData + 0x1e50) = invUDeltaBits;
  *(int *)(mapData + 0x1e48) = v1Bits;
  *(int *)(mapData + 0x1e4c) = v2Bits;
  *(int *)(mapData + 0x1e54) = invVDeltaBits;
  pointIndex = 0;
  for (remaining = uorder * vorder; remaining != 0; remaining = remaining + -1) {
    pointRecord = pointIndex * 8 + mapData;
    pointComponent0 = listRecord[pointIndex * 2 + 8];
    *(int *)(pointRecord + 0x1e5c) = listRecord[pointIndex * 2 + 9];
    *(int *)(pointRecord + 0x1e58) = pointComponent0;
    pointIndex = pointIndex + 1;
  }
  return (100 - uorder * vorder) * -8 + 0x340;
}

/* _glMap2Texture3_ListExec @ 0x6fe8c (180 bytes) */
int _glMap2Texture3_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int *piVar1;
  int invUDeltaBits;
  int pointComponent1;
  int v1Bits;
  int pointComponent2;
  int v2Bits;
  int invVDeltaBits;
  int vorder;
  int vorder2;
  int u2Bits;
  int remaining;
  int iVar8;
  int uorder;
  
  iVar8 = _gleGetMapData(glContext);
  vorder2 = listRecord[1];
  *(int *)(iVar8 + 0x2178) = *listRecord;
  *(int *)(iVar8 + 0x217c) = vorder2;
  uorder = *listRecord;
  vorder = listRecord[1];
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[6];
  v1Bits = listRecord[4];
  v2Bits = listRecord[5];
  invVDeltaBits = listRecord[7];
  *(int *)(iVar8 + 0x2180) = listRecord[2];
  *(int *)(iVar8 + 0x2184) = u2Bits;
  *(int *)(iVar8 + 0x2190) = invUDeltaBits;
  *(int *)(iVar8 + 0x2188) = v1Bits;
  *(int *)(iVar8 + 0x218c) = v2Bits;
  *(int *)(iVar8 + 0x2194) = invVDeltaBits;
  for (remaining = uorder * vorder; remaining != 0; remaining = remaining + -1) {
    piVar1 = listRecord + 8;
    pointComponent1 = listRecord[9];
    pointComponent2 = listRecord[10];
    listRecord = listRecord + 3;
    *(int *)(iVar8 + 0x2198) = *piVar1;
    *(int *)(iVar8 + 0x219c) = pointComponent1;
    *(int *)(iVar8 + 0x21a0) = pointComponent2;
    iVar8 = iVar8 + 0xc;
  }
  return (100 - uorder * vorder) * -0xc + 0x4d0;
}

/* _glMap2Texture4_ListExec @ 0x6ff40 (200 bytes) */
int _glMap2Texture4_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int v1Bits;
  int pointComponent0;
  int v2Bits;
  int pointComponent1;
  int invVDeltaBits;
  int pointComponent2;
  int vorder;
  int pointIndex;
  int u2Bits;
  int vorder2;
  int mapData;
  int uorder;
  int pointRecord;
  int invUDeltaBits;
  int remaining;
  
  mapData = _gleGetMapData(glContext);
  vorder2 = listRecord[1];
  *(int *)(mapData + 0x2648) = *listRecord;
  *(int *)(mapData + 0x264c) = vorder2;
  uorder = *listRecord;
  vorder = listRecord[1];
  u2Bits = listRecord[3];
  invUDeltaBits = listRecord[6];
  v1Bits = listRecord[4];
  v2Bits = listRecord[5];
  invVDeltaBits = listRecord[7];
  *(int *)(mapData + 0x2650) = listRecord[2];
  *(int *)(mapData + 0x2654) = u2Bits;
  *(int *)(mapData + 0x2660) = invUDeltaBits;
  *(int *)(mapData + 0x2658) = v1Bits;
  *(int *)(mapData + 0x265c) = v2Bits;
  *(int *)(mapData + 0x2664) = invVDeltaBits;
  pointIndex = 0;
  for (remaining = uorder * vorder; remaining != 0; remaining = remaining + -1) {
    pointRecord = pointIndex * 0x10 + mapData;
    pointComponent0 = listRecord[pointIndex * 4 + 8];
    pointComponent1 = listRecord[pointIndex * 4 + 9];
    pointComponent2 = listRecord[pointIndex * 4 + 10];
    *(int *)(pointRecord + 0x2674) = listRecord[pointIndex * 4 + 0xb];
    *(int *)(pointRecord + 0x2668) = pointComponent0;
    *(int *)(pointRecord + 0x266c) = pointComponent1;
    *(int *)(pointRecord + 0x2670) = pointComponent2;
    pointIndex = pointIndex + 1;
  }
  return (100 - uorder * vorder) * -0x10 + 0x660;
}

/* _glMap2VertexAttrib1ARB_ListExec @ 0x70008 (200 bytes) */
int _glMap2VertexAttrib1ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int v1Bits;
  int v2Bits;
  int *srcCursor;
  int u1Bits;
  int remaining;
  int mapData;
  int *dstCursor;
  int iVar6;
  int iVar7;
  int iVar8;
  int u2Bits;
  int uorder;
  int attribIndex;
  int invUDeltaBits;
  
  mapData = _gleGetMapData(glContext);
  attribIndex = *listRecord;
  uorder = listRecord[1];
  iVar7 = listRecord[2];
  iVar6 = mapData + attribIndex * 0x660;
  *(int *)(iVar6 + 0x37a8) = uorder;
  *(int *)(iVar6 + 0x37ac) = iVar7;
  iVar7 = iVar7 * uorder;
  *(undefined1 *)(attribIndex + mapData + 0x9db8) = 1;
  u1Bits = listRecord[3];
  u2Bits = listRecord[4];
  invUDeltaBits = listRecord[7];
  v1Bits = listRecord[5];
  v2Bits = listRecord[6];
  *(int *)(iVar6 + 0x37c4) = listRecord[8];
  *(int *)(iVar6 + 0x37b0) = u1Bits;
  *(int *)(iVar6 + 0x37b4) = u2Bits;
  *(int *)(iVar6 + 0x37c0) = invUDeltaBits;
  *(int *)(iVar6 + 0x37b8) = v1Bits;
  *(int *)(iVar6 + 0x37bc) = v2Bits;
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
  int v1Bits;
  int v2Bits;
  int invVDeltaBits;
  int attribIndex;
  int u2Bits;
  int remaining;
  int iVar6;
  int invUDeltaBits;
  int mapData;
  int iVar7;
  int *srcCursor;
  int iVar9;
  int iVar10;
  int uorder;
  
  mapData = _gleGetMapData(glContext);
  attribIndex = *listRecord;
  srcCursor = listRecord + 1;
  uorder = listRecord[1];
  iVar7 = listRecord[2];
  iVar9 = mapData + attribIndex * 0x660;
  iVar10 = iVar9 + 0x37a8;
  *(int *)(iVar9 + 0x37a8) = uorder;
  *(int *)(iVar9 + 0x37ac) = iVar7;
  *(undefined1 *)(attribIndex + mapData + 0x9db8) = 2;
  u2Bits = listRecord[4];
  invUDeltaBits = listRecord[7];
  v1Bits = listRecord[5];
  v2Bits = listRecord[6];
  invVDeltaBits = listRecord[8];
  *(int *)(iVar9 + 0x37b0) = listRecord[3];
  *(int *)(iVar9 + 0x37b4) = u2Bits;
  *(int *)(iVar9 + 0x37c0) = invUDeltaBits;
  *(int *)(iVar9 + 0x37b8) = v1Bits;
  *(int *)(iVar9 + 0x37bc) = v2Bits;
  *(int *)(iVar9 + 0x37c4) = invVDeltaBits;
  iVar7 = iVar7 * uorder;
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
  int *pointComponent0Ptr;
  int v2Bits;
  int invVDeltaBits;
  int attribIndex;
  int u2Bits;
  int remaining;
  int pointComponent1;
  int invUDeltaBits;
  int mapData;
  int vorderThenPointCount;
  int *srcCursor;
  int attribMap;
  int pointComponent2;
  int v1Bits;
  int controlPointDest;
  int uorder;
  
  mapData = _gleGetMapData(glContext);
  attribIndex = *listRecord;
  srcCursor = listRecord + 1;
  uorder = listRecord[1];
  vorderThenPointCount = listRecord[2];
  attribMap = mapData + attribIndex * 0x660;
  controlPointDest = attribMap + 0x37a8;
  *(int *)(attribMap + 0x37a8) = uorder;
  *(int *)(attribMap + 0x37ac) = vorderThenPointCount;
  *(undefined1 *)(attribIndex + mapData + 0x9db8) = 3;
  u2Bits = listRecord[4];
  invUDeltaBits = listRecord[7];
  v1Bits = listRecord[5];
  v2Bits = listRecord[6];
  invVDeltaBits = listRecord[8];
  *(int *)(attribMap + 0x37b0) = listRecord[3];
  *(int *)(attribMap + 0x37b4) = u2Bits;
  *(int *)(attribMap + 0x37c0) = invUDeltaBits;
  *(int *)(attribMap + 0x37b8) = v1Bits;
  *(int *)(attribMap + 0x37bc) = v2Bits;
  *(int *)(attribMap + 0x37c4) = invVDeltaBits;
  vorderThenPointCount = vorderThenPointCount * uorder;
  for (remaining = vorderThenPointCount; remaining != 0; remaining = remaining + -1) {
    pointComponent0Ptr = srcCursor + 8;
    pointComponent1 = srcCursor[9];
    pointComponent2 = srcCursor[10];
    srcCursor = srcCursor + 3;
    *(int *)(controlPointDest + 0x20) = *pointComponent0Ptr;
    *(int *)(controlPointDest + 0x24) = pointComponent1;
    *(int *)(controlPointDest + 0x28) = pointComponent2;
    controlPointDest = controlPointDest + 0xc;
  }
  return (100 - vorderThenPointCount) * -0xc + 0x4d4;
}

/* _glMap2VertexAttrib4ARB_ListExec @ 0x70278 (236 bytes) */
int _glMap2VertexAttrib4ARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  int *listRecord;
{
  int iVar1;
  int u2Bits;
  int remaining;
  int mapData;
  int iVar3;
  int iVar4;
  int uorder;
  int v1Bits;
  int pointComponent2;
  int iVar6;
  int invUDeltaBits;
  int attribIndex;
  int v2Bits;
  int pointComponent1;
  int invVDeltaBits;
  int pointComponent3;
  
  mapData = _gleGetMapData(glContext);
  attribIndex = *listRecord;
  uorder = listRecord[1];
  iVar3 = listRecord[2];
  iVar1 = mapData + attribIndex * 0x660;
  *(int *)(iVar1 + 0x37a8) = uorder;
  *(int *)(iVar1 + 0x37ac) = iVar3;
  *(undefined1 *)(attribIndex + mapData + 0x9db8) = 4;
  u2Bits = listRecord[4];
  invUDeltaBits = listRecord[7];
  v1Bits = listRecord[5];
  v2Bits = listRecord[6];
  invVDeltaBits = listRecord[8];
  *(int *)(iVar1 + 0x37b0) = listRecord[3];
  *(int *)(iVar1 + 0x37b4) = u2Bits;
  *(int *)(iVar1 + 0x37c0) = invUDeltaBits;
  *(int *)(iVar1 + 0x37b8) = v1Bits;
  *(int *)(iVar1 + 0x37bc) = v2Bits;
  *(int *)(iVar1 + 0x37c4) = invVDeltaBits;
  iVar3 = iVar3 * uorder;
  iVar6 = 0;
  for (remaining = iVar3; remaining != 0; remaining = remaining + -1) {
    iVar4 = iVar6 * 0x10 + iVar1 + 0x37a8;
    pointComponent3 = listRecord[iVar6 * 4 + 0xc];
    pointComponent1 = listRecord[iVar6 * 4 + 10];
    pointComponent2 = listRecord[iVar6 * 4 + 0xb];
    *(int *)(iVar4 + 0x20) = listRecord[iVar6 * 4 + 9];
    *(int *)(iVar4 + 0x2c) = pointComponent3;
    *(int *)(iVar4 + 0x24) = pointComponent1;
    *(int *)(iVar4 + 0x28) = pointComponent2;
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
  int recordSize;
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
          recordSize = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Color_ListExec_001101bc,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2ColordLoad)(glContext,extraout_r4_01,recordSize,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,
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
          recordSize = (100 - uorder * vorder) * -4 + 0x1b0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Index_ListExec_001101b8,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2IndexdLoad)(glContext,extraout_r4_02,recordSize,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,
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
          recordSize = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Normal_ListExec_001101b4,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2NormaldLoad)(glContext,extraout_r4_03,recordSize,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,
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
          recordSize = (100 - uorder * vorder) * -4 + 0x1b0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture1_ListExec_001101b0,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture1dLoad)(glContext,extraout_r4_04,recordSize,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                       v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,u2,v1
                       ,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb4:
        if ((1 < ustride) && (1 < vstride)) {
          recordSize = (100 - uorder * vorder) * -8 + 0x340;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture2_ListExec_001101ac,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture2dLoad)(glContext,extraout_r4_05,recordSize,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                       v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,u2,v1
                       ,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb5:
        if ((2 < ustride) && (2 < vstride)) {
          recordSize = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture3_ListExec_001101a8,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture3dLoad)(glContext,extraout_r4_06,recordSize,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                       v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,u2,v1
                       ,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb6:
        if ((3 < ustride) && (3 < vstride)) {
          recordSize = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture4_ListExec_001101a4,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture4dLoad)(glContext,extraout_r4_07,recordSize,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                       v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,u2,v1
                       ,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb7:
        if ((2 < ustride) && (2 < vstride)) {
          recordSize = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Vertex3_ListExec_001101c4,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Vertex3dLoad)(glContext,extraout_r4,recordSize,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
                       v1ShadowLo,v2ShadowHi,vstride,vorder,points,listRecord,u1,u2,v1
                       ,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_00070908;
        }
        break;
      case 0xdb8:
        if ((3 < ustride) && (3 < vstride)) {
          recordSize = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Vertex4_ListExec_001101c0,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Vertex4dLoad)(glContext,extraout_r4_00,recordSize,u1ShadowLo,u2ShadowHi,ustride,uorder,iVar4,v1ShadowHi,
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
  int mapTypeIndex;
  int uorderCopy;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  uorderCopy = uorder;
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((u1 != u2) && (v1 != v2)) && (uorder - 1U < 10)) &&
       ((0 < vorder && (vorder < 0xb)))) {
      mapTypeIndex = target + -0xdb0;
      switch(mapTypeIndex) {
      case 0:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2ColordLoad)(glContext,mapTypeIndex,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,uorderCopy,v1ShadowHi,
                             v1ShadowLo,v2ShadowHi,vstride,vorder,points,mapData + 0x1478,u1,
                             u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                             incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 1:
        if ((0 < ustride) && (0 < vstride)) {
          ((void (*)())_gleMap2IndexdLoad)(glContext,mapTypeIndex,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,uorderCopy,v1ShadowHi,
                             v1ShadowLo,v2ShadowHi,vstride,vorder,points,mapData + 0x1ad8,u1,
                             u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,
                             incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 2:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2NormaldLoad)(glContext,mapTypeIndex,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,uorderCopy,v1ShadowHi,
                              v1ShadowLo,v2ShadowHi,vstride,vorder,points,mapData + 0xfa8,u1,
                              u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11
                              ,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 3:
        if ((0 < ustride) && (0 < vstride)) {
          ((void (*)())_gleMap2Texture1dLoad)(glContext,mapTypeIndex,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,uorderCopy,v1ShadowHi,v1ShadowLo,
                     v2ShadowHi,vstride,vorder,points,mapData + 0x1c88,u1,u2,v1,
                     v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 4:
        if ((1 < ustride) && (1 < vstride)) {
          ((void (*)())_gleMap2Texture2dLoad)(glContext,mapTypeIndex,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,uorderCopy,v1ShadowHi,v1ShadowLo,
                     v2ShadowHi,vstride,vorder,points,mapData + 0x1e38,u1,u2,v1,
                     v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 5:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2Texture3dLoad)(glContext,mapTypeIndex,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,uorderCopy,v1ShadowHi,v1ShadowLo,
                     v2ShadowHi,vstride,vorder,points,mapData + 0x2178,u1,u2,v1,
                     v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 6:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2Texture4dLoad)(glContext,mapTypeIndex,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,uorderCopy,v1ShadowHi,v1ShadowLo,
                     v2ShadowHi,vstride,vorder,points,mapData + 0x2648,u1,u2,v1,
                     v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 7:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2Vertex3dLoad)(glContext,mapTypeIndex,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,uorderCopy,v1ShadowHi,v1ShadowLo,
                     v2ShadowHi,vstride,vorder,points,mapData + 0x478,u1,u2,v1,
                     v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 8:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2Vertex4dLoad)(glContext,mapTypeIndex,u1ShadowHi,u1ShadowLo,u2ShadowHi,ustride,uorder,uorderCopy,v1ShadowHi,v1ShadowLo,
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
  int recordSize;
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
          recordSize = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Color_ListExec_001101bc,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2ColorfLoad)(glContext,extraout_r4_01,recordSize,ustride,uorder,iVar4,iVar5,vstride,
                               vorder,points,listRecord,u1,u2,v1,v2,incomingFpr5,
                               incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb1:
        if ((0 < ustride) && (0 < vstride)) {
          recordSize = (100 - uorder * vorder) * -4 + 0x1b0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Index_ListExec_001101b8,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2IndexfLoad)(glContext,extraout_r4_02,recordSize,ustride,uorder,iVar4,iVar5,vstride,
                               vorder,points,listRecord,u1,u2,v1,v2,incomingFpr5,
                               incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb2:
        if ((2 < ustride) && (2 < vstride)) {
          recordSize = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Normal_ListExec_001101b4,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2NormalfLoad)(glContext,extraout_r4_03,recordSize,ustride,uorder,iVar4,iVar5,vstride,
                                vorder,points,listRecord,u1,u2,v1,v2,incomingFpr5,
                                incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb3:
        if ((0 < ustride) && (0 < vstride)) {
          recordSize = (100 - uorder * vorder) * -4 + 0x1b0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture1_ListExec_001101b0,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture1fLoad)(glContext,extraout_r4_04,recordSize,ustride,uorder,iVar4,iVar5,vstride,vorder,
                       points,listRecord,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                       incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb4:
        if ((1 < ustride) && (1 < vstride)) {
          recordSize = (100 - uorder * vorder) * -8 + 0x340;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture2_ListExec_001101ac,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture2fLoad)(glContext,extraout_r4_05,recordSize,ustride,uorder,iVar4,iVar5,vstride,vorder,
                       points,listRecord,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                       incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb5:
        if ((2 < ustride) && (2 < vstride)) {
          recordSize = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture3_ListExec_001101a8,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture3fLoad)(glContext,extraout_r4_06,recordSize,ustride,uorder,iVar4,iVar5,vstride,vorder,
                       points,listRecord,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                       incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb6:
        if ((3 < ustride) && (3 < vstride)) {
          recordSize = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Texture4_ListExec_001101a4,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Texture4fLoad)(glContext,extraout_r4_07,recordSize,ustride,uorder,iVar4,iVar5,vstride,vorder,
                       points,listRecord,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                       incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb7:
        if ((2 < ustride) && (2 < vstride)) {
          recordSize = (100 - uorder * vorder) * -0xc + 0x4d0;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Vertex3_ListExec_001101c4,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Vertex3fLoad)(glContext,extraout_r4,recordSize,ustride,uorder,iVar4,iVar5,vstride,vorder,
                       points,listRecord,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                       incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
            return;
          }
          goto LAB_000713ec;
        }
        break;
      case 0xdb8:
        if ((3 < ustride) && (3 < vstride)) {
          recordSize = (100 - uorder * vorder) * -0x10 + 0x660;
          iVar4 = uorder;
          listRecord = _gleAddListItem(glContext,PTR__glMap2Vertex4_ListExec_001101c0,recordSize);
          if (listRecord != 0) {
            ((void (*)())_gleMap2Vertex4fLoad)(glContext,extraout_r4_00,recordSize,ustride,uorder,iVar4,iVar5,vstride,vorder,
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
  int mapTypeIndexTimes4;
  undefined4 glErrorCode;
  int mapData;
  uint mapTypeIndex;
  int uorderCopy;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  double incomingFpr9;
  double incomingFpr10;
  double incomingFpr11;
  double incomingFpr12;
  double incomingFpr13;
  
  uorderCopy = uorder;
  mapData = _gleGetMapData(glContext);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((((u1 != u2) && (v1 != v2)) && (uorder - 1U < 10)) &&
       ((0 < vorder && (vorder < 0xb)))) {
      mapTypeIndex = target - 0xdb0;
      if (8 < mapTypeIndex) {
        if (*(int *)(glContext + 0x7574) != 0) goto LAB_00071884;
        glErrorCode = 0x500;
        goto LAB_00071880;
      }
      mapTypeIndexTimes4 = mapTypeIndex * 4;
      switch(mapTypeIndex) {
      case 0:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2ColorfLoad)(glContext,mapTypeIndex,u1Shadow,ustride,uorder,uorderCopy,mapTypeIndexTimes4,vstride,vorder,
                             points,mapData + 0x1478,u1,u2,v1,v2,incomingFpr5,incomingFpr6
                             ,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 1:
        if ((0 < ustride) && (0 < vstride)) {
          ((void (*)())_gleMap2IndexfLoad)(glContext,mapTypeIndex,u1Shadow,ustride,uorder,uorderCopy,mapTypeIndexTimes4,vstride,vorder,
                             points,mapData + 0x1ad8,u1,u2,v1,v2,incomingFpr5,incomingFpr6
                             ,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 2:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2NormalfLoad)(glContext,mapTypeIndex,u1Shadow,ustride,uorder,uorderCopy,mapTypeIndexTimes4,vstride,vorder,
                              points,mapData + 0xfa8,u1,u2,v1,v2,incomingFpr5,incomingFpr6
                              ,incomingFpr7,incomingFpr8,incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 3:
        if ((0 < ustride) && (0 < vstride)) {
          ((void (*)())_gleMap2Texture1fLoad)(glContext,mapTypeIndex,u1Shadow,ustride,uorder,uorderCopy,mapTypeIndexTimes4,vstride,vorder,points,
                     mapData + 0x1c88,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                     incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 4:
        if ((1 < ustride) && (1 < vstride)) {
          ((void (*)())_gleMap2Texture2fLoad)(glContext,mapTypeIndex,u1Shadow,ustride,uorder,uorderCopy,mapTypeIndexTimes4,vstride,vorder,points,
                     mapData + 0x1e38,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                     incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 5:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2Texture3fLoad)(glContext,mapTypeIndex,u1Shadow,ustride,uorder,uorderCopy,mapTypeIndexTimes4,vstride,vorder,points,
                     mapData + 0x2178,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                     incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 6:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2Texture4fLoad)(glContext,mapTypeIndex,u1Shadow,ustride,uorder,uorderCopy,mapTypeIndexTimes4,vstride,vorder,points,
                     mapData + 0x2648,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
                     incomingFpr9,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 7:
        if ((2 < ustride) && (2 < vstride)) {
          ((void (*)())_gleMap2Vertex3fLoad)(glContext,mapTypeIndex,u1Shadow,ustride,uorder,uorderCopy,mapTypeIndexTimes4,vstride,vorder,points,
                     mapData + 0x478,u1,u2,v1,v2,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,incomingFpr9
                     ,incomingFpr10,incomingFpr11,incomingFpr12,incomingFpr13);
          return;
        }
        break;
      case 8:
        if ((3 < ustride) && (3 < vstride)) {
          ((void (*)())_gleMap2Vertex4fLoad)(glContext,mapTypeIndex,u1Shadow,ustride,uorder,uorderCopy,mapTypeIndexTimes4,vstride,vorder,points,
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

