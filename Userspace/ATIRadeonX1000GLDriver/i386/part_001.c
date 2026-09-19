#include "decls.h"

/* _gldDeleteTexture @ 0x84d8 (41 bytes) */
int _gldDeleteTexture(param_1, param_2)
  undefined4 param_1;
  void *param_2;
{
  _gldReclaimTexture(param_1,param_2);
  _free(param_2);
  return 0;
}

/* _gldCreatePipelineProgram @ 0x8504 (47 bytes) */
int _gldCreatePipelineProgram(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = _calloc(1,0x40);
  puVar1[0xf] = 3;
  *puVar1 = param_3;
  *param_2 = puVar1;
  return 0;
}

/* _gldModifyPipelineProgram @ 0x8533 (34 bytes) */
int _gldModifyPipelineProgram(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  uint param_3;
{
  *(uint *)(param_2 + 0x3c) = *(uint *)(param_2 + 0x3c) | param_3;
  FUN_000229c6(param_1,param_2);
  return 0;
}

/* _gldRelatePipelineProgram @ 0x8555 (71 bytes) */
int _gldRelatePipelineProgram(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 *param_3;
  int param_4;
{
  if (*(short *)*param_3 == -0x74d0) {
    if (param_4 == '\0') {
      param_3 = (undefined4 *)0x0;
    }
    *(undefined4 **)(param_2 + 8) = param_3;
    return 0;
  }
  if (*(short *)*param_3 != -0x74cf) {
    return 0;
  }
  if (param_4 == '\0') {
    param_3 = (undefined4 *)0x0;
  }
  *(undefined4 **)(param_2 + 4) = param_3;
  return 0;
}

/* _gldGetPipelineProgramInfo @ 0x859c (42 bytes) */
int _gldGetPipelineProgramInfo(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  FUN_000242a5(param_1,param_2,param_3,param_4);
  return 0;
}

/* _gldDestroyPipelineProgram @ 0x85c6 (76 bytes) */
int _gldDestroyPipelineProgram(param_1, param_2)
  int param_1;
  void *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 2;
  iVar1 = param_1;
  do {
    if (param_2 == *(void **)(iVar1 + 0x1cc)) {
      *(undefined4 *)(iVar1 + 0x1cc) = 0;
    }
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_0002366c(param_1,param_2);
  _free(param_2);
  return 0;
}

/* FUN_00008612 @ 0x8612 (132 bytes) */
int FUN_00008612(param_1)
  int param_1;
{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_10;
  
  local_10 = 0;
  iVar3 = param_1;
  do {
    piVar2 = *(int **)(*(int *)(param_1 + 0x18) + 0x198 + local_10 * 4);
    if (piVar2 == (int *)0x0) {
      if (*(char *)(*(int *)(param_1 + 0x10) + 0x4304 + local_10 * 8) != '\0') {
        piVar2 = *(int **)(*(int *)(param_1 + 0x18) + 0x18c + local_10 * 4);
        goto LAB_00008638;
      }
LAB_00008681:
      *(undefined4 *)(iVar3 + 0x1cc) = 0;
    }
    else {
LAB_00008638:
      if (*(int *)(*piVar2 + 4) == 0) goto LAB_00008681;
      cVar1 = FUN_00024063(param_1,piVar2);
      if (cVar1 == '\0') goto LAB_00008681;
      *(int **)(iVar3 + 0x1cc) = piVar2;
    }
    local_10 = local_10 + 1;
    iVar3 = iVar3 + 4;
    if (local_10 == 2) {
      return;
    }
  } while( true );
}

/* FUN_00008696 @ 0x8696 (1166 bytes) */
int FUN_00008696(param_1, param_2, param_3, param_4)
  uint param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  *param_4 = 4;
  switch(param_1 >> 0xb & 0x1f) {
  case 2:
    *param_3 = (param_1 >> 0x10) * 0x10 + 0x10;
    return;
  case 3:
    uVar4 = param_1 >> 0x18;
    switch(param_1 >> 0x14 & 0xf) {
    case 0:
      *param_3 = uVar4 * 0x80 + 0x24c0;
      return;
    case 1:
      *param_3 = uVar4 * 0x80 + 0x24d0;
      return;
    case 2:
      *param_3 = uVar4 * 0x80 + 0x24e0;
      return;
    case 3:
      *param_3 = uVar4 * 0x80 + 0x24f0;
      return;
    case 4:
      *param_3 = uVar4 * 0x80 + 0x2500;
      return;
    case 5:
      *param_3 = uVar4 * 0x80 + 0x2510;
      return;
    case 6:
      *param_3 = uVar4 * 0x80 + 0x2520;
      return;
    }
    break;
  case 4:
    uVar1 = param_1 >> 0x18;
    uVar3 = param_1 >> 0x17 & 1;
    uVar4 = param_1 >> 0x15 & 3;
    if (uVar4 == 1) {
      *param_3 = uVar3 * 0x240 + 0x2920 + uVar1 * 0x30;
      return;
    }
    if (uVar4 == 2) {
      *param_3 = uVar3 * 0x240 + 0x2930 + uVar1 * 0x30;
      return;
    }
    if (uVar4 == 0) {
      *param_3 = uVar3 * 0x240 + 0x2910 + uVar1 * 0x30;
      return;
    }
    break;
  case 5:
    iVar2 = (int)param_1 >> 0x1f;
    switch(param_1 >> 0x1c & 7) {
    case 0:
      *param_3 = iVar2 * -0x240 + 0x28c0;
      return;
    case 1:
      *param_3 = iVar2 * -0x240 + 0x28d0;
      return;
    case 2:
      *param_3 = iVar2 * -0x240 + 0x28e0;
      return;
    case 3:
      *param_3 = iVar2 * -0x240 + 0x28f0;
      return;
    case 4:
      *param_3 = iVar2 * -0x240 + 0x2900;
      return;
    case 5:
      *param_3 = iVar2 * -0x240 + 0x2a90;
      return;
    }
    break;
  case 6:
    *param_3 = 0x24b0;
    return;
  case 7:
    uVar1 = param_1 >> 0x1b;
    uVar4 = param_1 >> 0x18 & 7;
    if (uVar4 == 1) {
      *param_3 = uVar1 * 0x94 + 0x39b0;
      return;
    }
    if (uVar4 < 2) {
      if (uVar4 == 0) {
        *param_3 = uVar1 * 0x94 + 0x398c;
        return;
      }
    }
    else {
      if (uVar4 == 2) {
        *param_3 = uVar1 * 0x94 + 0x39d4;
        return;
      }
      if (uVar4 == 3) {
        *param_3 = uVar1 * 0x94 + 0x39f8;
        return;
      }
    }
    break;
  case 8:
    uVar1 = param_1 >> 0x1b;
    uVar4 = param_1 >> 0x18 & 7;
    if (uVar4 == 1) {
      *param_3 = uVar1 * 0x94 + 0x39c0;
      return;
    }
    if (uVar4 < 2) {
      if (uVar4 == 0) {
        *param_3 = uVar1 * 0x94 + 0x399c;
        return;
      }
    }
    else {
      if (uVar4 == 2) {
        *param_3 = uVar1 * 0x94 + 0x39e4;
        return;
      }
      if (uVar4 == 3) {
        *param_3 = uVar1 * 0x94 + 0x3a08;
        return;
      }
    }
    break;
  case 10:
    *param_3 = (param_1 >> 0x18) * 0x10 + 0x3e2c;
    return;
  case 0xb:
    *param_3 = 0x2de0;
    return;
  case 0xc:
    *param_3 = 0x2df0;
    return;
  case 0xd:
    *param_3 = 0x30bc;
    return;
  case 0xe:
    *param_3 = 0x30cc;
    return;
  case 0x10:
    uVar4 = param_1 >> 0x18;
    switch(param_1 >> 0x15 & 7) {
    case 0:
      iVar2 = 0;
      break;
    case 1:
      iVar2 = 0xc0;
      break;
    case 2:
      iVar2 = 0x80;
      break;
    case 3:
      iVar2 = (uVar4 + 4) * 0x40;
      break;
    case 4:
      iVar2 = (uVar4 + 0x10) * 0x40;
      break;
    case 5:
      iVar2 = (uVar4 + 8) * 0x40;
      break;
    default:
      iVar2 = uVar4 << 6;
    }
    uVar4 = param_1 >> 0x10 & 3;
    if (uVar4 < 2) {
      *param_3 = iVar2 + 0x1860;
    }
    else {
      *param_3 = iVar2 + 0x1e60;
    }
    uVar1 = param_1 >> 0x12 & 3;
    if (uVar4 < 3) {
      if (uVar4 == 0) {
LAB_00008aac:
        *param_3 = *param_3 + uVar1 * 4;
        *param_4 = 0x10;
        return;
      }
      *param_3 = *param_3 + uVar1 * 0x10;
    }
    else if (uVar4 == 3) goto LAB_00008aac;
  }
  return;
}

/* FUN_00008bbb @ 0x8bbb (47 bytes) */
int FUN_00008bbb(param_1)
  int param_1;
{
  void *pvVar1;
  
  pvVar1 = _calloc(1,0x18);
  *(void **)(param_1 + 0x234) = pvVar1;
  return -(uint)(pvVar1 == (void *)0x0) & 0x2720;
}

/* FUN_00008bea @ 0x8bea (129 bytes) */
int FUN_00008bea(param_1)
  int param_1;
{
  int iVar1;
  char cVar2;
  
  iVar1 = **(int **)(param_1 + 0x234);
  if (iVar1 != 0) {
    if ((0x1ffff < *(int *)(iVar1 + 0x10)) || ((short)*(int *)(iVar1 + 0x10) != 0)) {
      _gldFlush(param_1);
    }
    cVar2 = FUN_00017c5b(param_1,*(undefined4 *)(iVar1 + 8));
    if (cVar2 == '\0') {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar1 + 8,1,0,0);
      return;
    }
  }
  return;
}

/* _gldDestroyQuery @ 0x8c6b (57 bytes) */
int _gldDestroyQuery(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint *puVar1;
  byte bVar2;
  
  bVar2 = (byte)*param_2 & 0x1f;
  puVar1 = (uint *)(*(int *)(param_1 + 0x22c) + (*param_2 >> 5) * 4);
  *puVar1 = *puVar1 & (-2 << bVar2 | 0xfffffffeU >> 0x20 - bVar2);
  _free(param_2);
  return 0;
}

/* FUN_00008ca4 @ 0x8ca4 (128 bytes) */
int FUN_00008ca4(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = **(int **)(param_1 + 0x234);
  if (iVar1 != 0) {
    ((int (*)())FUN_00008bea)(param_1);
    iVar2 = *(int *)(iVar1 + 0x10);
    *(int *)(iVar1 + 0x10) = iVar2 + -0x10000;
    if (iVar2 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar1,1,0,0);
      **(undefined4 **)(param_1 + 0x234) = 0;
      return 0;
    }
  }
  return 0;
}

/* FUN_00008d24 @ 0x8d24 (233 bytes) */
int FUN_00008d24(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_10;
  
  iVar1 = *param_2;
  *param_2 = 0;
  param_2[1] = 6;
  param_2[2] = param_3;
  param_2[3] = param_4;
  param_2[4] = param_5;
  local_10 = 8;
  iVar2 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,local_18,&local_10);
  if (iVar2 == 0) {
    *param_2 = local_14;
    *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + 0x10000;
    *(undefined1 *)(local_14 + 0x14) = 1;
  }
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x10);
    *(int *)(iVar1 + 0x10) = iVar2 + -0x10000;
    if (iVar2 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar1,1,0,0);
      return 1;
    }
  }
  return 1;
}

/* _gldCreateQuery @ 0x8e0d (621 bytes) */
int _gldCreateQuery(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  uint *puVar1;
  char cVar2;
  int *piVar3;
  uint uVar4;
  size_t sVar5;
  void *pvVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int local_20;
  
  piVar3 = _malloc(4);
  *piVar3 = 0;
  do {
    uVar4 = *(uint *)(param_1 + 0x230) >> 5;
    if (uVar4 != 0) {
      puVar1 = *(uint **)(param_1 + 0x22c);
      uVar9 = *puVar1;
      if (uVar9 != 0xffffffff) {
        uVar8 = 0;
LAB_00008e4e:
        local_20 = 0;
        do {
          if ((uVar9 >> ((byte)local_20 & 0x1f) & 1) == 0) {
            puVar1[uVar8] = puVar1[uVar8] | 1 << ((byte)local_20 & 0x1f);
            *piVar3 = local_20 + uVar8 * 0x20;
            *param_2 = piVar3;
            return 0;
          }
          local_20 = local_20 + 1;
        } while (local_20 != 0x20);
        puVar1[uVar8] = puVar1[uVar8] | 1;
        *piVar3 = uVar8 * 0x20 + 0x20;
        *param_2 = piVar3;
        return 0;
      }
      uVar8 = 0;
      while (uVar8 = uVar8 + 1, uVar4 != uVar8) {
        uVar9 = puVar1[uVar8];
        if (uVar9 != 0xffffffff) goto LAB_00008e4e;
      }
    }
    if ((*(int *)(param_1 + 0x234) == 0) && (iVar7 = ((int (*)())FUN_00008bbb)(param_1), iVar7 == 0x2720)) {
LAB_00008f39:
      _free(piVar3);
      *param_2 = 0;
      return 0x2720;
    }
    if (*(int *)(param_1 + 0x228) == 0) {
      *(undefined4 *)(param_1 + 0x230) = 0x20;
      *(undefined4 *)(param_1 + 0x228) = 0x610;
      pvVar6 = _malloc(0x610);
      *(void **)(param_1 + 0x224) = pvVar6;
      _memset(pvVar6,0,*(size_t *)(param_1 + 0x228));
    }
    else {
      if (**(int **)(param_1 + 0x234) != 0) {
        ((int (*)())FUN_00008ca4)(param_1);
      }
      iVar7 = *(int *)(param_1 + 0x230);
      *(int *)(param_1 + 0x230) = iVar7 * 2;
      sVar5 = iVar7 * 0x40 + 0x210;
      *(size_t *)(param_1 + 0x228) = sVar5;
      pvVar6 = _realloc(*(void **)(param_1 + 0x224),sVar5);
      *(void **)(param_1 + 0x224) = pvVar6;
      if (pvVar6 == (void *)0x0) goto LAB_00008f39;
    }
    cVar2 = ((int (*)())FUN_00008d24)(param_1,*(undefined4 *)(param_1 + 0x234),*(undefined4 *)(param_1 + 0x224),
                         *(undefined4 *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x228));
    if (cVar2 != '\x01') goto LAB_00008f39;
    FUN_000296ab(param_1);
    uVar4 = *(uint *)(param_1 + 0x230);
    uVar9 = uVar4 >> 3;
    if (*(void **)(param_1 + 0x22c) == (void *)0x0) {
      pvVar6 = _malloc(uVar9);
      *(void **)(param_1 + 0x22c) = pvVar6;
      _memset(pvVar6,0,uVar9);
    }
    else {
      pvVar6 = _realloc(*(void **)(param_1 + 0x22c),uVar9);
      *(void **)(param_1 + 0x22c) = pvVar6;
      uVar4 = uVar4 >> 4;
      _memset((void *)((int)pvVar6 + uVar4),0,uVar4);
    }
  } while( true );
}

/* FUN_0000907a @ 0x907a (78 bytes) */
int FUN_0000907a(param_1)
  uint param_1;
{
  if ((param_1 & 0x3c) != 0) {
    return 8;
  }
  if ((param_1 & 0x3fc0) != 0) {
    return 0x10;
  }
  if ((param_1 & 0xfc000) != 0) {
    return 0x20;
  }
  if ((param_1 & 0x3f00000) == 0) {
    return ~-((param_1 & 0xc000000) == 0) & 0x80;
  }
  return 0x40;
}

/* FUN_000090c8 @ 0x90c8 (55 bytes) */
int FUN_000090c8(param_1)
  uint param_1;
{
  if ((param_1 & 0x1000) != 0) {
    return 0x20;
  }
  if ((param_1 & 0x800) == 0) {
    if ((param_1 & 0x400) == 0) {
      return ~-((param_1 & 0x80) == 0) & 8;
    }
    return 0x10;
  }
  return 0x18;
}

/* FUN_000090ff @ 0x90ff (102 bytes) */
int FUN_000090ff(param_1)
  uint param_1;
{
  if ((param_1 & 0x400) != 0) {
    return 1;
  }
  if ((param_1 & 0x40000) != 0) {
    return 2;
  }
  if ((char)param_1 < '\0') {
    return 4;
  }
  if ((param_1 & 0x9a928) == 0) {
    if ((param_1 & 0x200000) != 0) {
      return 0xc;
    }
    if ((param_1 & 0x2800000) == 0) {
      return ~-((param_1 & 0x8000000) == 0) & 0x20;
    }
    return 0x10;
  }
  return 8;
}

/* FUN_00009165 @ 0x9165 (312 bytes) */
int FUN_00009165(param_1, param_2)
  uint param_1;
  undefined2 *param_2;
{
  undefined2 uVar1;
  
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  if ((param_1 & 0x3c) == 0) {
    if ((param_1 & 0x1c0) == 0) {
      if ((param_1 & 0xe00) == 0) {
        if ((param_1 & 0x3000) == 0) {
          if ((param_1 & 0x1c000) == 0) {
            if ((param_1 & 0xe0000) == 0) {
              if ((param_1 & 0x300000) == 0) {
                if ((param_1 & 0x2c00000) == 0) {
                  if ((param_1 & 0x8000000) == 0) {
                    return 0;
                  }
                  *param_2 = 0x20;
                  param_2[1] = 0x20;
                  param_2[2] = 0x20;
                }
                else {
                  *param_2 = 0x10;
                  param_2[1] = 0x10;
                  param_2[2] = 0x10;
                }
              }
              else {
                *param_2 = 0xc;
                param_2[1] = 0xc;
                param_2[2] = 0xc;
              }
            }
            else {
              *param_2 = 10;
              param_2[1] = 10;
              param_2[2] = 10;
            }
          }
          else {
            *param_2 = 8;
            param_2[1] = 8;
            param_2[2] = 8;
          }
        }
        else {
          *param_2 = 5;
          param_2[1] = 6;
          param_2[2] = 5;
        }
      }
      else {
        *param_2 = 5;
        param_2[1] = 5;
        param_2[2] = 5;
      }
    }
    else {
      *param_2 = 4;
      param_2[1] = 4;
      param_2[2] = 4;
    }
  }
  else {
    *param_2 = 3;
    param_2[1] = 3;
    param_2[2] = 2;
  }
  uVar1 = ((int (*)())FUN_000090ff)(param_1);
  param_2[3] = uVar1;
  return 1;
}

/* FUN_000092a0 @ 0x92a0 (153 bytes) */
int FUN_000092a0(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  switch(param_1) {
  case 0x400:
  case 0x404:
  case 0x406:
    goto switchD_000092be_caseD_400;
  case 0x401:
  case 0x407:
    if ((param_2 & 0x10) == 0) {
      return 1;
    }
    return 3;
  case 0x403:
    if ((param_2 & 0x400) == 0) {
      return 1;
    }
    if ((param_2 & 0x10) == 0) {
      return 0;
    }
    return 2;
  case 0x409:
    if (0xff < (param_2 & 0x300)) {
      return 7;
    }
    break;
  case 0x40a:
    if (0x1ff < (param_2 & 0x300)) {
      return 8;
    }
    break;
  case 0x40b:
    if (0x2ff < (param_2 & 0x300)) {
      return 9;
    }
  }
  if ((param_2 & 0x400) != 0) {
    return 0;
  }
switchD_000092be_caseD_400:
  return 1;
}

/* FUN_00009369 @ 0x9369 (549 bytes) */
int FUN_00009369(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (param_2 == 0x1a00) {
    return 1;
  }
  if (param_2 < 0x1a01) {
    if (param_2 < 0x1404) {
      if (param_2 < 0x1402) {
        if (param_2 == 0) {
          return (-(uint)(param_1 - 0x83f0 < 2) & 0xfffffff8) + 0x10;
        }
        if (param_2 < 0x1400) {
          return 4;
        }
        if (param_1 == 0x1909) {
          return 1;
        }
        if (param_1 < 0x190a) {
          if (param_1 < 0x1900) {
            return 4;
          }
          if (0x1906 < param_1) {
            if (param_1 != 0x1907) {
              return 4;
            }
            return 3;
          }
          return 1;
        }
        if (param_1 == 0x8049) {
          return 1;
        }
        if (param_1 < 0x804a) {
          if (param_1 != 0x190a) {
            return 4;
          }
          return 2;
        }
        if (param_1 == 0x80e0) {
          return 3;
        }
        if (param_1 != 0x85b9) {
          return 4;
        }
        return 2;
      }
    }
    else {
      if (param_2 < 0x1407) {
        if (param_1 == 0x1909) {
          return 4;
        }
        if (param_1 < 0x190a) {
          if (0x18ff < param_1) {
            if (param_1 < 0x1907) {
              return 4;
            }
            if (param_1 == 0x1907) {
              return 0xc;
            }
          }
          return 0x10;
        }
        if (param_1 == 0x8049) {
          return 4;
        }
        if (param_1 < 0x804a) {
          if (param_1 == 0x190a) {
            return 8;
          }
          return 0x10;
        }
        if (param_1 == 0x80e0) {
          return 0xc;
        }
        if (param_1 == 0x85b9) {
          return 8;
        }
        return 0x10;
      }
      if (param_2 != 0x140b) {
        return 4;
      }
    }
    if (param_1 != 0x1909) {
      if (param_1 < 0x190a) {
        if (0x18ff < param_1) {
          if (param_1 < 0x1907) {
            return 2;
          }
          if (param_1 == 0x1907) {
            return 6;
          }
        }
        return 8;
      }
      if (param_1 != 0x8049) {
        if (param_1 < 0x804a) {
          if (param_1 != 0x190a) {
            return 8;
          }
        }
        else {
          if (param_1 == 0x80e0) {
            return 6;
          }
          if (param_1 != 0x85b9) {
            return 8;
          }
        }
        return 4;
      }
    }
  }
  else {
    if (param_2 == 0x8362) {
      return 1;
    }
    if (param_2 < 0x8363) {
      if (param_2 == 0x8032) {
        return 1;
      }
      if (param_2 < 0x8032) {
        return 4;
      }
      if (0x8034 < param_2) {
        return 4;
      }
      return 2;
    }
    if ((0x8366 < param_2) && (1 < param_2 - 0x85ba)) {
      return 4;
    }
  }
  return 2;
}

/* FUN_0000958e @ 0x958e (98 bytes) */
int FUN_0000958e(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = ((int (*)())FUN_00009369)(param_1,0);
    return iVar1 * (param_3 + 3 >> 2) >> 2;
  }
  if (param_2 != 0x1a00) {
    iVar1 = ((int (*)())FUN_00009369)(param_1,param_2);
    return iVar1 * param_3;
  }
  return param_3 + 7 >> 3;
}

/* FUN_000095f0 @ 0x95f0 (264 bytes) */
int FUN_000095f0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  uint *param_6;
  int *param_7;
  int *param_8;
  int *param_9;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = ((int (*)())FUN_00009369)(param_2,param_3);
  *param_7 = iVar1;
  if (param_9 != (int *)0x0) {
    iVar2 = *param_9;
    if (iVar2 < 1) {
      uVar3 = ((int (*)())FUN_0000958e)(param_2,param_3,param_4);
    }
    else if (param_3 == 0x1a00) {
      uVar3 = iVar2 + 7 >> 3;
    }
    else {
      uVar3 = iVar1 * iVar2;
    }
    uVar4 = uVar3 % (uint)param_9[5];
    if (uVar4 == 0) {
      *param_6 = uVar3;
      iVar2 = param_9[1];
      if (param_9[1] < 1) {
        iVar2 = param_5;
      }
      iVar2 = iVar2 * uVar3;
    }
    else {
      uVar3 = uVar3 + (param_9[5] - uVar4);
      *param_6 = uVar3;
      iVar2 = param_9[1];
      if (param_9[1] < 1) {
        iVar2 = param_5;
      }
      iVar2 = iVar2 * uVar3;
    }
    if (param_3 == 0x1a00) {
      iVar1 = param_9[3] >> 3;
    }
    else {
      iVar1 = iVar1 * param_9[3];
    }
    *param_8 = iVar1 + uVar3 * param_9[2] + iVar2 * param_9[4];
    return;
  }
  *param_8 = 0;
  uVar3 = ((int (*)())FUN_0000958e)(param_2,param_3,param_4);
  *param_6 = uVar3;
  return;
}

/* FUN_000096f8 @ 0x96f8 (355 bytes) */
int FUN_000096f8(param_1, param_2)
  int param_1;
  uint param_2;
{
  int *piVar1;
  byte bVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  int local_2c;
  int local_28;
  uint local_24;
  uint local_20;
  int local_10;
  
  iVar8 = *(int *)(param_1 + 0x18);
  piVar1 = *(int **)(iVar8 + 0x19c);
  if ((piVar1 == (int *)0x0) &&
     (((*(char *)(*(int *)(param_1 + 0x10) + 0x430c) == '\0' ||
       (*(undefined4 **)(iVar8 + 400) == (undefined4 *)0x0)) ||
      (*(short *)**(undefined4 **)(iVar8 + 400) != -0x77fc)))) {
    bVar3 = false;
    local_24 = 0;
    local_20 = 0;
  }
  else {
    bVar3 = true;
    if (piVar1 == (int *)0x0) {
      local_24 = *(uint *)(**(int **)(iVar8 + 400) + 8);
      local_20 = *(uint *)(**(int **)(iVar8 + 400) + 0xc);
      param_2 = 0xffffffff;
    }
    else {
      local_24 = *(uint *)(*piVar1 + 8);
      local_20 = *(uint *)(*piVar1 + 0xc);
      param_2 = 0xffffffff;
    }
  }
  local_28 = 0;
  local_10 = 0;
  local_2c = 0;
  iVar8 = param_1;
  do {
    if ((param_2 & 1) != 0) {
      if (bVar3) {
        bVar6 = (byte)(local_28 << 2);
        bVar2 = bVar6 & 0x1f;
        uVar7 = local_24 >> bVar2 | local_20 << 0x20 - bVar2;
        if ((local_28 << 2 & 0x20U) != 0) {
          uVar7 = local_20 >> (bVar6 & 0x1f);
        }
        uVar7 = uVar7 & 0xf;
        if (4 < uVar7) goto LAB_0000978e;
LAB_000097d0:
        iVar5 = *(int *)(local_10 + *(int *)(param_1 + 0x18) + uVar7 * 4);
        if ((*(short *)(*(int *)(iVar5 + 0x30) + 0x5c) == 0) ||
           (((*(byte *)(iVar5 + 0x39) & 0x87) != 0 &&
            (cVar4 = FUN_0002fdb4(param_1,iVar5), cVar4 == '\0')))) goto LAB_0000978e;
      }
      else {
        uVar7 = 0;
        do {
          if ((*(uint *)(local_2c + *(int *)(param_1 + 0x10) + 0x31d4) & 1 << ((byte)uVar7 & 0x1f))
              != 0) goto LAB_000097d0;
          uVar7 = uVar7 + 1;
        } while (uVar7 != 5);
LAB_0000978e:
        iVar5 = 0;
      }
      *(int *)(iVar8 + 0x18c) = iVar5;
    }
    local_28 = local_28 + 1;
    local_2c = local_2c + 0x7c;
    param_2 = param_2 >> 1;
    iVar8 = iVar8 + 4;
    local_10 = local_10 + 0x14;
    if (local_28 == 0x10) {
      return;
    }
  } while( true );
}

/* FUN_0000985b @ 0x985b (232 bytes) */
int FUN_0000985b(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_10;
  
  iVar1 = *(int *)(param_2 + 0x30);
  uVar2 = (uint)*(byte *)(iVar1 + 0xaa);
  uVar4 = (uint)*(ushort *)(iVar1 + 0xa4) + uVar2 * -2;
  uVar5 = (uint)*(ushort *)(iVar1 + 0xa6) - *(byte *)(iVar1 + 0x6e) * uVar2;
  uVar2 = (uint)*(ushort *)(iVar1 + 0xa8) - uVar2 * *(byte *)(iVar1 + 0x6f);
  iVar3 = uVar2 * uVar4 * uVar5;
  local_10 = 1;
  do {
    if ((((uVar4 == 1) && (uVar5 == 1)) && (uVar2 == 1)) || (*(ushort *)(iVar1 + 0x5c) < 0x2602))
    break;
    uVar4 = uVar4 >> 1;
    if (uVar4 == 0) {
      uVar4 = 1;
    }
    uVar5 = uVar5 >> 1;
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    uVar2 = uVar2 >> 1;
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    iVar3 = iVar3 + uVar4 * uVar5 * uVar2;
    local_10 = local_10 + 1;
  } while (local_10 != 0xd);
  uVar2 = (uint)*(byte *)(iVar1 + 0x6c) * iVar3;
  iVar1 = FUN_0002e8e5(param_1,param_2);
  if (-1 < iVar1) {
    return iVar1 * uVar2;
  }
  return uVar2 / (uint)-iVar1;
}

/* FUN_00009943 @ 0x9943 (5 bytes) */
int FUN_00009943()
{
  return;
}

/* FUN_00009948 @ 0x9948 (5 bytes) */
int FUN_00009948()
{
  return;
}

/* FUN_0000994d @ 0x994d (218 bytes) */
int FUN_0000994d(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x34);
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush(param_1);
      }
      cVar1 = FUN_00017c5b(param_1,*(undefined4 *)(iVar2 + 8));
      if (cVar1 == '\0') {
        iVar2 = iVar2 + 8;
LAB_000099ea:
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar2,1,0,0);
        return;
      }
    }
    else if (*(char *)(iVar2 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush(param_1);
      }
      cVar1 = FUN_00017c5b(param_1,*(undefined4 *)(iVar2 + 0xc));
      if (cVar1 == '\0') {
        iVar2 = iVar2 + 0xc;
        goto LAB_000099ea;
      }
    }
  }
  return;
}

/* FUN_00009a27 @ 0x9a27 (119 bytes) */
int FUN_00009a27(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_2 + 0x34);
  if (iVar1 == 0) {
    return 1;
  }
  if (*(char *)(iVar1 + 0x16) == '\x06') {
    if (0x1ffff < *(int *)(iVar1 + 0x10)) {
      _gldFlush(param_1);
    }
    uVar3 = *(undefined4 *)(iVar1 + 8);
  }
  else {
    if (*(char *)(iVar1 + 0x16) != '\a') {
      return 1;
    }
    if (*(int *)(iVar1 + 0x10) < 0x20000) {
      uVar3 = *(undefined4 *)(iVar1 + 0xc);
    }
    else {
      _gldFlush(param_1);
      uVar3 = *(undefined4 *)(iVar1 + 0xc);
    }
  }
  uVar2 = FUN_00017c5b(param_1,uVar3);
  return uVar2;
}

/* FUN_00009a9e @ 0x9a9e (517 bytes) */
int FUN_00009a9e(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  iVar3 = param_2[0xd];
  if ((((iVar3 == 0) || (*(char *)(iVar3 + 0x16) != '\x03')) || (param_3 != param_2[2])) ||
     (param_4 != param_2[3])) {
LAB_00009aba:
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    if (iVar3 != 0) {
      iVar1 = *(int *)(iVar3 + 0x10);
      *(int *)(iVar3 + 0x10) = iVar1 + -0x10000;
      if (iVar1 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar3,1,0,0);
      }
      param_2[0xd] = 0;
    }
    param_2[1] = 3;
    param_2[2] = param_3;
    param_2[3] = param_4;
    local_10 = 8;
    iVar3 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,&local_18,&local_10);
    if (iVar3 != 0) {
      return 0;
    }
    param_2[0xd] = local_14;
    *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + 0x10000;
    *param_2 = local_18;
    *(undefined1 *)(local_14 + 0x14) = 1;
  }
  else {
    iVar1 = param_2[0xc];
    if (0x1ffff < *(int *)(iVar3 + 0x10)) {
      _gldFlush(param_1);
    }
    if (*(byte *)(iVar1 + 0x6c) == 0) {
LAB_00009c3e:
      cVar2 = FUN_00017c5b(param_1,*(undefined4 *)(iVar3 + 0xc));
      if (cVar2 == '\0') goto LAB_00009aba;
    }
    else {
      if ((ushort)(~*(ushort *)(iVar1 + 0x7c) &
                  (*(ushort *)(iVar3 + 0x1c) | *(ushort *)(iVar3 + 0x28))) == 0) {
        uVar4 = 0;
        do {
          uVar4 = uVar4 + 1;
          if (*(byte *)(iVar1 + 0x6c) <= uVar4) goto LAB_00009c3e;
        } while ((ushort)((*(ushort *)(iVar3 + 0x1c + uVar4 * 2) |
                          *(ushort *)(iVar3 + 0x28 + uVar4 * 2)) &
                         ~*(ushort *)(iVar1 + 0x7c + uVar4 * 2)) == 0);
      }
      cVar2 = FUN_00017c5b(param_1,*(undefined4 *)(iVar3 + 0xc));
      if (cVar2 == '\0') {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar3 + 0xc,1,0,0);
      }
    }
    *(undefined1 *)(iVar3 + 0x14) = 1;
  }
  return 1;
}

/* FUN_00009ca3 @ 0x9ca3 (535 bytes) */
int FUN_00009ca3(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  iVar3 = param_2[0xd];
  if ((((iVar3 == 0) || (*(char *)(iVar3 + 0x16) != '\x06')) || (param_2[2] != 0)) ||
     ((param_2[3] != 0 || (param_3 != param_2[4])))) {
LAB_00009cbf:
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    if (iVar3 != 0) {
      iVar1 = *(int *)(iVar3 + 0x10);
      *(int *)(iVar3 + 0x10) = iVar1 + -0x10000;
      if (iVar1 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar3,1,0,0);
      }
      param_2[0xd] = 0;
    }
    param_2[1] = 6;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = param_3;
    local_10 = 8;
    iVar3 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,&local_18,&local_10);
    if (iVar3 != 0) {
      return 0;
    }
    param_2[0xd] = local_14;
    *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + 0x10000;
    *param_2 = local_18;
    *(undefined1 *)(local_14 + 0x14) = 1;
  }
  else {
    iVar1 = param_2[0xc];
    if (0x1ffff < *(int *)(iVar3 + 0x10)) {
      _gldFlush(param_1);
    }
    if (*(byte *)(iVar1 + 0x6c) == 0) {
LAB_00009e55:
      cVar2 = FUN_00017c5b(param_1,*(undefined4 *)(iVar3 + 8));
      if (cVar2 == '\0') goto LAB_00009cbf;
    }
    else {
      if ((ushort)(~*(ushort *)(iVar1 + 0x7c) &
                  (*(ushort *)(iVar3 + 0x1c) | *(ushort *)(iVar3 + 0x28))) == 0) {
        uVar4 = 0;
        do {
          uVar4 = uVar4 + 1;
          if (*(byte *)(iVar1 + 0x6c) <= uVar4) goto LAB_00009e55;
        } while ((ushort)((*(ushort *)(iVar3 + 0x1c + uVar4 * 2) |
                          *(ushort *)(iVar3 + 0x28 + uVar4 * 2)) &
                         ~*(ushort *)(iVar1 + 0x7c + uVar4 * 2)) == 0);
      }
      cVar2 = FUN_00017c5b(param_1,*(undefined4 *)(iVar3 + 8));
      if (cVar2 == '\0') {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar3 + 8,1,0,0);
      }
    }
    *(undefined1 *)(iVar3 + 0x14) = 1;
  }
  return 1;
}

/* FUN_00009eba @ 0x9eba (254 bytes) */
int FUN_00009eba(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_10;
  
  iVar1 = param_2[0xd];
  param_2[0xd] = 0;
  *param_2 = 0;
  param_2[1] = 6;
  param_2[2] = param_3;
  param_2[3] = param_4;
  param_2[4] = param_5;
  local_10 = 8;
  iVar2 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,local_18,&local_10);
  if (iVar2 == 0) {
    param_2[0xd] = local_14;
    *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + 0x10000;
    *(undefined1 *)(local_14 + 0x14) = 1;
    if (iVar1 != local_14) {
      *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x10);
    *(int *)(iVar1 + 0x10) = iVar2 + -0x10000;
    if (iVar2 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar1,1,0,0);
      return uVar3;
    }
  }
  return uVar3;
}

/* FUN_00009fb8 @ 0x9fb8 (266 bytes) */
int FUN_00009fb8(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  iVar1 = param_2[0xd];
  param_2[0xd] = 0;
  *param_2 = 0;
  param_2[1] = 7;
  param_2[2] = param_3;
  param_2[3] = param_4;
  param_2[4] = param_5;
  param_2[5] = param_6;
  local_10 = 8;
  iVar2 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,&local_18,&local_10);
  if (iVar2 == 0) {
    param_2[0xd] = local_14;
    *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + 0x10000;
    *(byte *)(local_14 + 0x14) = *(byte *)(local_14 + 0x14) | 1;
    *param_2 = local_18;
    if (iVar1 != local_14) {
      *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x10);
    *(int *)(iVar1 + 0x10) = iVar2 + -0x10000;
    if (iVar2 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar1,1,0,0);
      return uVar3;
    }
  }
  return uVar3;
}

/* FUN_0000a0c2 @ 0xa0c2 (288 bytes) */
int FUN_0000a0c2(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_10;
  
  iVar2 = param_2[0xd];
  if ((((iVar2 == 0) || (*(char *)(iVar2 + 0x16) != '\0')) || (param_3 != param_2[2])) ||
     ((param_4 != param_2[3] || (param_5 != param_2[4])))) {
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x10);
      *(int *)(iVar2 + 0x10) = iVar1 + -0x10000;
      if (iVar1 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar2,1,0,0);
      }
      param_2[0xd] = 0;
    }
    param_2[1] = 0;
    param_2[2] = param_3;
    param_2[3] = param_4;
    param_2[4] = param_5;
    local_10 = 8;
    iVar2 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,local_18,&local_10);
    if (iVar2 != 0) {
      return 0;
    }
    param_2[0xd] = local_14;
    *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + 0x10000;
    *param_2 = 0;
  }
  return 1;
}

/* FUN_0000a1e2 @ 0xa1e2 (252 bytes) */
int FUN_0000a1e2(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_10;
  
  iVar2 = param_2[0xd];
  if (((iVar2 == 0) || (*(char *)(iVar2 + 0x16) != '\x01')) || (param_3 != param_2[2])) {
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    if (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x10);
      *(int *)(iVar2 + 0x10) = iVar1 + -0x10000;
      if (iVar1 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar2,1,0,0);
      }
      param_2[0xd] = 0;
    }
    param_2[1] = 1;
    param_2[2] = param_3;
    local_10 = 8;
    iVar2 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,local_18,&local_10);
    if (iVar2 != 0) {
      return 0;
    }
    param_2[0xd] = local_14;
    *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + 0x10000;
    *param_2 = 0;
  }
  return 1;
}

/* _gldCreateVertexArray @ 0xa2de (46 bytes) */
int _gldCreateVertexArray(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = _calloc(1,0x244);
  *puVar1 = param_3;
  puVar1[1] = param_4;
  *param_2 = puVar1;
  return 0;
}

/* _gldFlushVertexArray @ 0xa30c (48 bytes) */
int _gldFlushVertexArray(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  if (param_5 == '\0') {
    return 0;
  }
  ((int (*)())FUN_00009943)(param_1,param_4,param_3);
  return 1;
}

/* FUN_0000a33c @ 0xa33c (268 bytes) */
int FUN_0000a33c(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  char cVar3;
  int *local_14;
  
  local_14 = *(int **)(*(int *)(param_1 + 0x18) + 0x194);
  iVar1 = *local_14;
  iVar2 = *(int *)(param_1 + 0x1d4);
  if ((*(uint *)(iVar1 + 0x30c) & *(uint *)(iVar1 + 0x304)) == 0 &&
      (*(uint *)(iVar1 + 0x308) & *(uint *)(iVar1 + 0x300)) == 0) {
    if (*(char *)(*(int *)(param_1 + 0x10) + 0x42fc) != '\0') {
      if (*(int *)(local_14[1] + 0x88) == 0 && *(int *)(local_14[1] + 0x84) == 0) goto LAB_0000a39d;
LAB_0000a3e2:
      cVar3 = FUN_0001bbbf(param_1,local_14);
      goto joined_r0x0000a3f3;
    }
    if (*(short *)(iVar1 + 0x312) != -0x7a4c) {
      if (*(int *)(local_14[1] + 0x88) == 0 && *(int *)(local_14[1] + 0x84) == 0) goto LAB_0000a39d;
      goto LAB_0000a3e2;
    }
  }
  else {
    if (*(int *)(local_14[1] + 0x88) == 0 && *(int *)(local_14[1] + 0x84) == 0) goto LAB_0000a39d;
    cVar3 = FUN_0001c6c5(param_1,local_14);
joined_r0x0000a3f3:
    if (cVar3 != '\0') goto LAB_0000a39d;
  }
  local_14 = (int *)0x0;
LAB_0000a39d:
  *(int **)(param_1 + 0x1d4) = local_14;
  if ((iVar2 != 0) && (local_14 == (int *)0x0)) {
    FUN_0001bfe2();
    return;
  }
  return;
}

/* FUN_0000a448 @ 0xa448 (221 bytes) */
int FUN_0000a448(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x228);
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush(param_1);
      }
      cVar1 = FUN_00017c5b(param_1,*(undefined4 *)(iVar2 + 8));
      if (cVar1 == '\0') {
        iVar2 = iVar2 + 8;
LAB_0000a4e8:
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar2,1,0,0);
        return;
      }
    }
    else if (*(char *)(iVar2 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush(param_1);
      }
      cVar1 = FUN_00017c5b(param_1,*(undefined4 *)(iVar2 + 0xc));
      if (cVar1 == '\0') {
        iVar2 = iVar2 + 0xc;
        goto LAB_0000a4e8;
      }
    }
  }
  return;
}

/* FUN_0000a525 @ 0xa525 (122 bytes) */
int FUN_0000a525(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_2 + 0x228);
  if (iVar1 == 0) {
    return 1;
  }
  if (*(char *)(iVar1 + 0x16) == '\x06') {
    if (0x1ffff < *(int *)(iVar1 + 0x10)) {
      _gldFlush(param_1);
    }
    uVar3 = *(undefined4 *)(iVar1 + 8);
  }
  else {
    if (*(char *)(iVar1 + 0x16) != '\a') {
      return 1;
    }
    if (*(int *)(iVar1 + 0x10) < 0x20000) {
      uVar3 = *(undefined4 *)(iVar1 + 0xc);
    }
    else {
      _gldFlush(param_1);
      uVar3 = *(undefined4 *)(iVar1 + 0xc);
    }
  }
  uVar2 = FUN_00017c5b(param_1,uVar3);
  return uVar2;
}

/* _gldModifyVertexArray @ 0xa59f (218 bytes) */
int _gldModifyVertexArray(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  iVar1 = param_2[0x8a];
  if (iVar1 != 0) {
    if (((*(uint *)(param_2[1] + 0x84) ^ 1) & 1) == 0) {
      iVar2 = *(int *)(iVar1 + 0x10);
      *(int *)(iVar1 + 0x10) = iVar2 + -0x10000;
    }
    else {
      if (*(short *)(*param_2 + 0x312) == -0x7a42) {
        bVar3 = param_2[0x8c] == 7;
      }
      else {
        bVar3 = param_2[0x8c] == 6;
      }
      if (bVar3) goto LAB_0000a5f2;
      iVar2 = *(int *)(iVar1 + 0x10);
      *(int *)(iVar1 + 0x10) = iVar2 + -0x10000;
    }
    if (iVar2 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar1,1,0,0);
    }
    param_2[0x8a] = 0;
  }
LAB_0000a5f2:
  _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  return 0;
}

/* _gldReclaimVertexArray @ 0xa679 (189 bytes) */
int _gldReclaimVertexArray(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x1d4) == param_2) {
    *(undefined4 *)(param_1 + 0x1d4) = 0;
    FUN_0001bfe2(param_1);
  }
  iVar1 = *(int *)(param_2 + 0x228);
  if (iVar1 != 0) {
    if ((0x1ffff < *(int *)(iVar1 + 0x10)) || ((short)*(int *)(iVar1 + 0x10) != 0)) {
      _gldFlush(param_1);
    }
    ((int (*)())FUN_0000a448)(param_1,param_2);
    iVar2 = *(int *)(iVar1 + 0x10);
    *(int *)(iVar1 + 0x10) = iVar2 + -0x10000;
    if (iVar2 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar1,1,0,0);
    }
    *(undefined4 *)(param_2 + 0x228) = 0;
  }
  return;
}

/* _gldDestroyVertexArray @ 0xa736 (41 bytes) */
int _gldDestroyVertexArray(param_1, param_2)
  undefined4 param_1;
  void *param_2;
{
  ((int (*)())_gldReclaimVertexArray)(param_1,param_2);
  _free(param_2);
  return 0;
}

/* FUN_0000a75f @ 0xa75f (273 bytes) */
int FUN_0000a75f(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_10;
  
  iVar1 = *(int *)(param_2 + 0x228);
  *(undefined4 *)(param_2 + 0x228) = 0;
  *(undefined4 *)(param_2 + 0x22c) = 0;
  *(undefined4 *)(param_2 + 0x230) = 6;
  *(undefined4 *)(param_2 + 0x234) = param_3;
  *(undefined4 *)(param_2 + 0x238) = param_4;
  *(undefined4 *)(param_2 + 0x23c) = param_5;
  local_10 = 8;
  iVar2 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 0x230,0x14,local_18,&local_10);
  bVar3 = iVar2 == 0;
  if (bVar3) {
    *(int *)(param_2 + 0x228) = local_14;
    *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + 0x10000;
    *(undefined1 *)(local_14 + 0x14) = 1;
  }
  if ((iVar1 != 0) &&
     (iVar2 = *(int *)(iVar1 + 0x10), *(int *)(iVar1 + 0x10) = iVar2 + -0x10000, iVar2 == 0x10000))
  {
    _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar1,1,0,0);
    return bVar3;
  }
  return bVar3;
}

/* FUN_0000a870 @ 0xa870 (292 bytes) */
int FUN_0000a870(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  iVar1 = *(int *)(param_2 + 0x228);
  *(undefined4 *)(param_2 + 0x228) = 0;
  *(undefined4 *)(param_2 + 0x22c) = 0;
  *(undefined4 *)(param_2 + 0x230) = 7;
  *(undefined4 *)(param_2 + 0x234) = param_3;
  *(undefined4 *)(param_2 + 0x238) = param_4;
  *(undefined4 *)(param_2 + 0x23c) = param_5;
  *(undefined4 *)(param_2 + 0x240) = param_6;
  local_10 = 8;
  iVar2 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 0x230,0x14,&local_18,&local_10);
  bVar3 = iVar2 == 0;
  if (bVar3) {
    *(int *)(param_2 + 0x228) = local_14;
    *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + 0x10000;
    *(undefined1 *)(local_14 + 0x14) = 1;
    *(undefined4 *)(param_2 + 0x22c) = local_18;
  }
  if ((iVar1 != 0) &&
     (iVar2 = *(int *)(iVar1 + 0x10), *(int *)(iVar1 + 0x10) = iVar2 + -0x10000, iVar2 == 0x10000))
  {
    _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar1,1,0,0);
    return bVar3;
  }
  return bVar3;
}

/* FUN_0000a994 @ 0xa994 (150 bytes) */
int FUN_0000a994(param_1)
  int param_1;
{
  if (param_1 < 1) {
    if (param_1 < 0) {
      for (; param_1 < -0x20; param_1 = param_1 + 0x20) {
      }
      return;
    }
    return;
  }
  if (param_1 < 0x21) {
    return;
  }
  do {
    param_1 = param_1 + -0x20;
  } while (0x20 < param_1);
  return;
}

/* FUN_0000aa2a @ 0xaa2a (1258 bytes) */
char * FUN_0000aa2a(double param_1,char *param_2,uint param_3,double param_4)

{
  char *pcVar1;
  char cVar2;
  double dVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  longdouble lVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  char *local_7c;
  double local_6c;
  double local_64;
  char *local_58;
  char *local_50;
  char *local_38;
  uint local_20 [4];
  
  local_64 = param_1;
  local_6c = param_4;
  pcVar1 = param_2 + param_3;
  if (param_4 <= 0.0) {
    local_6c = DOUBLE_001cf348;
  }
  if (param_3 < 2) {
    return (char *)0x0;
  }
  if (param_1 < 0.0) {
    *param_2 = '-';
    local_58 = param_2 + 1;
    local_64 = -param_1;
  }
  else {
    local_58 = param_2;
  }
  dVar11 = local_64;
  if (local_64 <= 0.0) {
    local_20[0] = 0;
    dVar15 = local_6c * DOUBLE_001cf368;
  }
  else {
    if ((local_64 < DOUBLE_001cf350) || (DOUBLE_001cf358 < local_64)) {
      _frexp(local_64,local_20);
      dVar11 = (double)(int)local_20[0] * DOUBLE_001cf360;
      lVar10 = (longdouble)_round(dVar11);
      local_20[0] = (uint)lVar10;
      ((int (*)())FUN_0000a994)();
      dVar14 = local_6c * dVar11;
      ((int (*)())FUN_0000a994)();
      dVar11 = local_64 * dVar11;
    }
    else {
      local_20[0] = 0;
      dVar14 = local_6c;
    }
    dVar15 = local_6c * DOUBLE_001cf368;
    for (; dVar12 = dVar15 + dVar11, DOUBLE_001cf370 <= dVar12; dVar11 = dVar11 * DOUBLE_001cf378) {
      local_20[0] = local_20[0] + 1;
      dVar14 = dVar14 * DOUBLE_001cf370;
    }
    while (dVar12 < DOUBLE_001cf330) {
      local_20[0] = local_20[0] - 1;
      dVar11 = dVar11 * DOUBLE_001cf370;
      dVar14 = dVar14 * DOUBLE_001cf378;
      dVar12 = dVar15 + dVar11;
    }
    uVar4 = local_20[0];
    if (0x7fffffff < local_20[0]) {
      uVar4 = -local_20[0];
    }
    if ((int)uVar4 < 4) {
      local_20[0] = 0;
      dVar15 = DOUBLE_001cf368 * dVar14;
      local_6c = dVar14;
      dVar11 = local_64;
    }
  }
  local_64 = dVar11;
  lVar10 = (longdouble)_floor(dVar15 + local_64);
  dVar3 = DOUBLE_001cf378;
  dVar12 = DOUBLE_001cf370;
  dVar11 = (double)lVar10;
  pcVar9 = local_58;
  dVar14 = dVar11;
  if (local_6c < dVar11) {
    do {
      if (pcVar9 == pcVar1) {
        return (char *)0x0;
      }
      dVar13 = dVar14 * dVar3;
      lVar10 = (longdouble)_floor(dVar13);
      dVar14 = (double)lVar10;
      *pcVar9 = (char)(int)((dVar13 - dVar14) * dVar12) + '0';
      pcVar9 = pcVar9 + 1;
    } while (local_6c < dVar14);
    if (pcVar9 <= local_58) goto LAB_0000abb6;
    pcVar5 = pcVar9 + -(int)local_58;
    pcVar8 = pcVar9;
    local_50 = pcVar5;
    pcVar6 = local_58;
    pcVar7 = pcVar5;
    while (1 < (int)pcVar7) {
      local_50 = local_50 + -2;
      cVar2 = pcVar8[-1];
      pcVar8[-1] = *pcVar6;
      *pcVar6 = cVar2;
      pcVar6 = pcVar6 + 1;
      pcVar8 = pcVar8 + -1;
      pcVar7 = local_58 + (int)(local_50 + ((int)pcVar5 - (int)pcVar9));
    }
  }
  else {
LAB_0000abb6:
    local_58 = pcVar9;
    *local_58 = '0';
    pcVar9 = local_58 + 1;
  }
  dVar11 = (dVar15 + local_64) - dVar11;
  if (local_6c < dVar11) {
    if (pcVar9 == pcVar1) {
      return (char *)0x0;
    }
    *pcVar9 = '.';
    dVar15 = DOUBLE_001cf370;
    pcVar9 = pcVar9 + 1;
    do {
      if (pcVar1 == pcVar9) {
        return (char *)0x0;
      }
      dVar11 = dVar11 * dVar15;
      lVar10 = (longdouble)_floor(dVar11);
      *pcVar9 = (char)(int)lVar10 + '0';
      pcVar9 = pcVar9 + 1;
      dVar11 = dVar11 - (double)lVar10;
      local_6c = local_6c * dVar15;
    } while (local_6c < dVar11);
LAB_0000adec:
    if (local_20[0] == 0) goto LAB_0000ac09;
  }
  else if (local_20[0] == 0) {
    if ((int)pcVar1 - (int)pcVar9 < 2) {
      return (char *)0x0;
    }
    *pcVar9 = '.';
    pcVar9[1] = '0';
    pcVar9 = pcVar9 + 2;
    goto LAB_0000adec;
  }
  if ((int)pcVar1 - (int)pcVar9 < 3) {
    return (char *)0x0;
  }
  *pcVar9 = 'e';
  local_38 = pcVar9 + 1;
  if ((int)local_20[0] < 0) {
    pcVar9[1] = '-';
    local_38 = pcVar9 + 2;
    local_20[0] = -local_20[0];
  }
  pcVar9 = local_38;
  if (0 < (int)local_20[0]) {
    do {
      if (pcVar9 == pcVar1) {
        return (char *)0x0;
      }
      *pcVar9 = (char)local_20[0] + (char)((int)local_20[0] / 10) * -10 + '0';
      pcVar9 = pcVar9 + 1;
      local_20[0] = (int)local_20[0] / 10;
    } while (0 < (int)local_20[0]);
    if (1 < (int)pcVar9 - (int)local_38) {
      local_7c = local_38 + (((int)pcVar9 - (int)local_38) * 2 - (int)pcVar9);
      pcVar7 = pcVar9;
      do {
        cVar2 = pcVar7[-1];
        pcVar7[-1] = *local_38;
        *local_38 = cVar2;
        local_38 = local_38 + 1;
        pcVar7 = pcVar7 + -1;
        local_7c = local_7c + -2;
      } while (1 < (int)local_7c);
    }
  }
LAB_0000ac09:
  if (pcVar9 == pcVar1) {
    return (char *)0x0;
  }
  *pcVar9 = '\0';
  return pcVar9;
}

/* FUN_0000af14 @ 0xaf14 (664 bytes) */
int FUN_0000af14(param_1, param_2)
  char *param_1;
  undefined4 *param_2;
{
  bool bVar1;
  bool bVar2;
  char *pcVar3;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  double in_XMM0_Qa;
  double dVar7;
  double dVar8;
  
  cVar4 = *param_1;
  if (cVar4 == '+') {
    param_1 = param_1 + 1;
    bVar1 = false;
    cVar4 = *param_1;
  }
  else if (cVar4 == '-') {
    param_1 = param_1 + 1;
    bVar1 = true;
    cVar4 = *param_1;
  }
  else {
    bVar1 = false;
  }
  pcVar6 = param_1;
  if (cVar4 == '\0') {
    dVar8 = 0.0;
    bVar2 = false;
    cVar4 = '\0';
LAB_0000af56:
    if (!bVar2) goto LAB_0000af60;
  }
  else {
    if (cVar4 == '.') {
      dVar8 = 0.0;
      cVar4 = param_1[1];
    }
    else {
      if ((cVar4 == 'e') || (cVar4 == 'E')) {
        dVar8 = 0.0;
        goto LAB_0000af60;
      }
      while ((byte)(cVar4 - 0x30U) < 10) {
        cVar4 = pcVar6[1];
        pcVar6 = pcVar6 + 1;
      }
      pcVar5 = pcVar6 + -1;
      if (pcVar5 < param_1) {
        dVar8 = 0.0;
      }
      else {
        dVar8 = 0.0;
        dVar7 = DOUBLE_001cf330;
        do {
          in_XMM0_Qa = (double)(*pcVar5 + -0x30) * dVar7;
          dVar8 = dVar8 + in_XMM0_Qa;
          dVar7 = dVar7 * DOUBLE_001cf370;
          pcVar5 = pcVar5 + -1;
        } while (param_1 <= pcVar5);
      }
      cVar4 = *pcVar6;
      bVar2 = true;
      if (cVar4 != '.') goto LAB_0000af56;
      cVar4 = pcVar6[1];
      param_1 = pcVar6;
    }
    param_1 = param_1 + 1;
    pcVar6 = param_1;
    if ((byte)(cVar4 - 0x30U) < 10) {
      do {
        pcVar5 = pcVar6;
        pcVar6 = pcVar5 + 1;
      } while ((byte)(*pcVar6 - 0x30U) < 10);
      if (pcVar5 < param_1) goto LAB_0000b130;
LAB_0000b029:
      in_XMM0_Qa = 0.0;
      do {
        in_XMM0_Qa = in_XMM0_Qa * DOUBLE_001cf378 + (double)(*pcVar5 + -0x30);
        pcVar5 = pcVar5 + -1;
      } while (param_1 <= pcVar5);
      in_XMM0_Qa = DOUBLE_001cf378 * in_XMM0_Qa;
    }
    else {
      pcVar5 = param_1 + -1;
      if (param_1 <= pcVar5) goto LAB_0000b029;
LAB_0000b130:
      in_XMM0_Qa = 0.0;
    }
    dVar8 = dVar8 + in_XMM0_Qa;
    cVar4 = *pcVar6;
  }
  if ((cVar4 == 'e') || (cVar4 == 'E')) {
    pcVar5 = pcVar6 + 1;
    if (pcVar6[1] == '+') {
      pcVar5 = pcVar6 + 2;
    }
    else if (pcVar6[1] == '-') {
      pcVar5 = pcVar6 + 2;
    }
    cVar4 = *pcVar5;
    pcVar6 = pcVar5;
    while (dVar7 = DOUBLE_001cf330, pcVar3 = pcVar6, (byte)(cVar4 - 0x30U) < 10) {
      pcVar6 = pcVar6 + 1;
      cVar4 = *pcVar6;
    }
    while (pcVar3 = pcVar3 + -1, pcVar5 <= pcVar3) {
      in_XMM0_Qa = (double)(*pcVar3 + -0x30) * dVar7;
      dVar7 = dVar7 * DOUBLE_001cf370;
    }
    ((int (*)())FUN_0000a994)();
    dVar8 = dVar8 * in_XMM0_Qa;
  }
LAB_0000af60:
  if (bVar1) {
    dVar8 = (double)((ulonglong)dVar8 ^ _DAT_001c5ec0);
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = pcVar6;
  }
  return (longdouble)dVar8;
}

/* FUN_0000b1ac @ 0xb1ac (93 bytes) */
int FUN_0000b1ac(param_1, param_2, param_3)
  size_t *param_1;
  int *param_2;
  int *param_3;
{
  size_t sVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  iVar2 = *param_3;
  iVar3 = *param_2;
  if ((int)(*param_1 - (iVar2 - iVar3)) < 0x100) {
    sVar1 = *param_1 + 0x800;
    *param_1 = sVar1;
    pvVar4 = _realloc((void *)*param_2,sVar1);
    *param_3 = (int)pvVar4;
    if (pvVar4 == (void *)0x0) {
      return 0;
    }
    *param_2 = (int)pvVar4;
    *param_3 = (int)pvVar4 + (iVar2 - iVar3);
  }
  return 1;
}

/* FUN_0000b209 @ 0xb209 (172 bytes) */
int FUN_0000b209(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  char *pcVar2;
  char cVar3;
  
  if (param_2 != 0) {
    if (s_C_001b71f0[0] == '\0') {
      iVar1 = 0;
    }
    else {
      iVar1 = 0;
      pcVar2 = "C";
      cVar3 = s_C_001b71f0[0];
      do {
        *(char *)(param_1 + iVar1) = cVar3;
        iVar1 = iVar1 + 1;
        cVar3 = pcVar2[1];
        pcVar2 = pcVar2 + 1;
      } while (cVar3 != '\0');
    }
    param_1 = param_1 + iVar1;
    if ((0 < param_3) && (s_1_001b71f4[0] != '\0')) {
      iVar1 = 0;
      pcVar2 = "1";
      cVar3 = s_1_001b71f4[0];
      do {
        *(char *)(param_1 + iVar1) = cVar3;
        iVar1 = iVar1 + 1;
        cVar3 = pcVar2[1];
        pcVar2 = pcVar2 + 1;
      } while (cVar3 != '\0');
      param_1 = param_1 + iVar1;
    }
  }
  if ((param_4 != 0) && (s__SAT_001b71f8[0] != '\0')) {
    iVar1 = 0;
    pcVar2 = "_SAT";
    cVar3 = s__SAT_001b71f8[0];
    do {
      *(char *)(param_1 + iVar1) = cVar3;
      iVar1 = iVar1 + 1;
      cVar3 = pcVar2[1];
      pcVar2 = pcVar2 + 1;
    } while (cVar3 != '\0');
    param_1 = param_1 + iVar1;
  }
  return param_1;
}

/* FUN_0000b2b5 @ 0xb2b5 (165 bytes) */
int FUN_0000b2b5(param_1, param_2)
  int param_1;
  int param_2;
{
  char *pcVar1;
  int iVar2;
  char cVar3;
  
  if (param_2 == 2) {
    if (s_H_001b7204[0] != '\0') {
      iVar2 = 0;
      pcVar1 = "H";
      cVar3 = s_H_001b7204[0];
      do {
        *(char *)(param_1 + iVar2) = cVar3;
        iVar2 = iVar2 + 1;
        cVar3 = pcVar1[1];
        pcVar1 = pcVar1 + 1;
      } while (cVar3 != '\0');
      param_1 = param_1 + iVar2;
    }
  }
  else if (param_2 == 3) {
    if (s_X_001b7208[0] != '\0') {
      iVar2 = 0;
      pcVar1 = "X";
      cVar3 = s_X_001b7208[0];
      do {
        *(char *)(param_1 + iVar2) = cVar3;
        iVar2 = iVar2 + 1;
        cVar3 = pcVar1[1];
        pcVar1 = pcVar1 + 1;
      } while (cVar3 != '\0');
      param_1 = param_1 + iVar2;
    }
  }
  else {
    if (param_2 != 1) {
      return param_1;
    }
    if (s_R_001b7200[0] != '\0') {
      iVar2 = 0;
      pcVar1 = "R";
      cVar3 = s_R_001b7200[0];
      do {
        *(char *)(param_1 + iVar2) = cVar3;
        iVar2 = iVar2 + 1;
        cVar3 = pcVar1[1];
        pcVar1 = pcVar1 + 1;
      } while (cVar3 != '\0');
      param_1 = param_1 + iVar2;
    }
  }
  return param_1;
}

/* FUN_0000b35a @ 0xb35a (542 bytes) */
int FUN_0000b35a(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined1 local_30;
  undefined1 local_24;
  undefined1 local_20;
  undefined1 local_1c;
  undefined1 local_18;
  undefined1 local_14;
  
  iVar2 = param_2 / 10;
  local_30 = (char)param_2;
  if (iVar2 != 0) {
    iVar1 = iVar2 / 10;
    if (iVar1 == 0) {
      pcVar5 = (char *)*param_1;
    }
    else {
      iVar3 = iVar1 / 10;
      if (iVar3 == 0) {
        pcVar5 = (char *)*param_1;
      }
      else {
        iVar4 = iVar3 / 10;
        local_24 = (char)iVar4;
        if (iVar4 == 0) {
          pcVar5 = (char *)*param_1;
        }
        else {
          iVar4 = iVar4 / 10;
          local_20 = (char)iVar4;
          if (iVar4 == 0) {
            pcVar5 = (char *)*param_1;
          }
          else {
            iVar4 = iVar4 / 10;
            local_1c = (char)iVar4;
            if (iVar4 == 0) {
              pcVar5 = (char *)*param_1;
            }
            else {
              iVar4 = iVar4 / 10;
              local_18 = (char)iVar4;
              if (iVar4 == 0) {
                pcVar5 = (char *)*param_1;
              }
              else {
                iVar4 = iVar4 / 10;
                local_14 = (char)iVar4;
                if (iVar4 == 0) {
                  pcVar5 = (char *)*param_1;
                }
                else {
                  if (iVar4 / 10 != 0) {
                    ((int (*)())FUN_0000b35a)();
                  }
                  *(char *)*param_1 = local_14 + (char)(iVar4 / 10) * -10 + '0';
                  pcVar5 = (char *)(*param_1 + 1);
                  *param_1 = (int)pcVar5;
                }
                *pcVar5 = local_18 + local_14 * -10 + '0';
                pcVar5 = (char *)(*param_1 + 1);
                *param_1 = (int)pcVar5;
              }
              *pcVar5 = local_1c + local_18 * -10 + '0';
              pcVar5 = (char *)(*param_1 + 1);
              *param_1 = (int)pcVar5;
            }
            *pcVar5 = local_20 + local_1c * -10 + '0';
            pcVar5 = (char *)(*param_1 + 1);
            *param_1 = (int)pcVar5;
          }
          *pcVar5 = local_24 + local_20 * -10 + '0';
          pcVar5 = (char *)(*param_1 + 1);
          *param_1 = (int)pcVar5;
        }
        *pcVar5 = (char)iVar3 + local_24 * -10 + '0';
        pcVar5 = (char *)(*param_1 + 1);
        *param_1 = (int)pcVar5;
      }
      *pcVar5 = (char)iVar1 + (char)iVar3 * -10 + '0';
      pcVar5 = (char *)(*param_1 + 1);
      *param_1 = (int)pcVar5;
    }
    *pcVar5 = (char)iVar2 + (char)iVar1 * -10 + '0';
    iVar1 = *param_1;
    *param_1 = iVar1 + 1;
    *(char *)(iVar1 + 1) = local_30 + (char)iVar2 * -10 + '0';
    *param_1 = *param_1 + 1;
    return;
  }
  *(char *)*param_1 = local_30 + '0';
  *param_1 = *param_1 + 1;
  return;
}

/* FUN_0000b578 @ 0xb578 (103 bytes) */
int FUN_0000b578(param_1, param_2)
  char *param_1;
  int param_2;
{
  char *local_10;
  
  local_10 = param_1;
  if (param_2 < 0) {
    *param_1 = '-';
    local_10 = param_1 + 1;
    param_2 = -param_2;
  }
  if (param_2 / 10 != 0) {
    ((int (*)())FUN_0000b35a)();
  }
  *local_10 = (char)param_2 + (char)(param_2 / 10) * -10 + '0';
  return local_10 + (1 - (int)param_1);
}

/* FUN_0000b5df @ 0xb5df (615 bytes) */
int FUN_0000b5df(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
{
  char cVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  char cVar7;
  
  cVar7 = s___001b720c[0];
  pcVar5 = ":";
  if (s___001b720c[0] == '\0') {
    iVar2 = ((int (*)())FUN_0000b578)();
    param_1 = param_1 + iVar2;
  }
  else {
    iVar2 = 0;
    pcVar6 = pcVar5;
    cVar4 = s___001b720c[0];
    do {
      *(char *)(param_1 + iVar2) = cVar4;
      iVar2 = iVar2 + 1;
      cVar4 = pcVar6[1];
      pcVar6 = pcVar6 + 1;
    } while (cVar4 != '\0');
    iVar3 = ((int (*)())FUN_0000b578)();
    param_1 = param_1 + iVar2 + iVar3;
  }
  if (param_3 == 1) {
    if (cVar7 == '\0') {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      do {
        *(char *)(param_1 + iVar2) = cVar7;
        iVar2 = iVar2 + 1;
        cVar7 = pcVar5[1];
        pcVar5 = pcVar5 + 1;
      } while (cVar7 != '\0');
    }
    iVar3 = ((int (*)())FUN_0000b578)();
    param_1 = param_1 + iVar2 + iVar3;
  }
  if (param_4 == 2) {
    if (s_X_001b7208[0] == '\0') goto LAB_0000b787;
    iVar2 = 0;
    pcVar5 = "X";
    cVar7 = s_X_001b7208[0];
    do {
      *(char *)(param_1 + iVar2) = cVar7;
      iVar2 = iVar2 + 1;
      cVar7 = pcVar5[1];
      pcVar5 = pcVar5 + 1;
    } while (cVar7 != '\0');
  }
  else {
    cVar1 = s_32_001b721c[0];
    cVar7 = s_16_001b7220[0];
    cVar4 = s_12_001b7224[0];
    if (param_4 < 3) {
      if (param_4 != 1) goto joined_r0x0000b718;
      if (s_F_001b7210[0] == '\0') goto LAB_0000b787;
      iVar2 = 0;
      pcVar5 = "F";
      cVar7 = s_F_001b7210[0];
      do {
        *(char *)(param_1 + iVar2) = cVar7;
        iVar2 = iVar2 + 1;
        cVar7 = pcVar5[1];
        pcVar5 = pcVar5 + 1;
      } while (cVar7 != '\0');
    }
    else if (param_4 == 3) {
      if (s_I_001b7214[0] == '\0') {
LAB_0000b787:
        iVar2 = 0;
      }
      else {
        iVar2 = 0;
        pcVar5 = "I";
        cVar7 = s_I_001b7214[0];
        do {
          *(char *)(param_1 + iVar2) = cVar7;
          iVar2 = iVar2 + 1;
          cVar7 = pcVar5[1];
          pcVar5 = pcVar5 + 1;
        } while (cVar7 != '\0');
      }
    }
    else {
      if (param_4 != 4) goto joined_r0x0000b718;
      if (s_B_001b7218[0] == '\0') goto LAB_0000b787;
      iVar2 = 0;
      pcVar5 = "B";
      cVar7 = s_B_001b7218[0];
      do {
        *(char *)(param_1 + iVar2) = cVar7;
        iVar2 = iVar2 + 1;
        cVar7 = pcVar5[1];
        pcVar5 = pcVar5 + 1;
      } while (cVar7 != '\0');
    }
  }
  param_1 = param_1 + iVar2;
  cVar1 = s_32_001b721c[0];
  cVar7 = s_16_001b7220[0];
  cVar4 = s_12_001b7224[0];
joined_r0x0000b718:
  s_32_001b721c[0] = cVar1;
  s_16_001b7220[0] = cVar7;
  s_12_001b7224[0] = cVar4;
  if (param_5 == 2) {
    if (cVar7 == '\0') {
      return param_1;
    }
    iVar2 = 0;
    pcVar5 = "16";
    do {
      *(char *)(param_1 + iVar2) = cVar7;
      iVar2 = iVar2 + 1;
      cVar7 = pcVar5[1];
      pcVar5 = pcVar5 + 1;
    } while (cVar7 != '\0');
  }
  else if (param_5 == 3) {
    if (cVar4 == '\0') {
      s_32_001b721c[0] = cVar1;
      s_16_001b7220[0] = cVar7;
      s_12_001b7224[0] = cVar4;
      return param_1;
    }
    iVar2 = 0;
    pcVar5 = "12";
    do {
      *(char *)(param_1 + iVar2) = cVar4;
      iVar2 = iVar2 + 1;
      cVar4 = pcVar5[1];
      pcVar5 = pcVar5 + 1;
    } while (cVar4 != '\0');
  }
  else {
    if (param_5 != 1) {
      return param_1;
    }
    if (cVar1 == '\0') {
      s_32_001b721c[0] = cVar1;
      s_16_001b7220[0] = cVar7;
      s_12_001b7224[0] = cVar4;
      return param_1;
    }
    iVar2 = 0;
    pcVar5 = "32";
    do {
      *(char *)(param_1 + iVar2) = cVar1;
      iVar2 = iVar2 + 1;
      cVar1 = pcVar5[1];
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
  }
  return param_1 + iVar2;
}

/* FUN_0000b846 @ 0xb846 (220 bytes) */
int FUN_0000b846(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  char *pcVar5;
  char *pcVar6;
  char local_1d;
  
  cVar1 = s___001b720c[0];
  if ((param_2 == 3) && (param_3 != 1)) {
    return param_1;
  }
  pcVar5 = ":";
  local_1d = s___001b720c[0];
  if (s___001b720c[0] == '\0') {
    iVar2 = ((int (*)())FUN_0000b578)();
    param_1 = param_1 + iVar2;
  }
  else {
    iVar2 = 0;
    pcVar6 = pcVar5;
    cVar4 = s___001b720c[0];
    do {
      *(char *)(param_1 + iVar2) = cVar4;
      iVar2 = iVar2 + 1;
      cVar4 = pcVar6[1];
      pcVar6 = pcVar6 + 1;
    } while (cVar4 != '\0');
    iVar3 = ((int (*)())FUN_0000b578)();
    param_1 = param_1 + iVar2 + iVar3;
  }
  if (param_3 == 1) {
    if (cVar1 == '\0') {
      iVar2 = 0;
    }
    else {
      iVar2 = 0;
      do {
        *(char *)(param_1 + iVar2) = local_1d;
        iVar2 = iVar2 + 1;
        local_1d = pcVar5[1];
        pcVar5 = pcVar5 + 1;
      } while (local_1d != '\0');
    }
    iVar3 = ((int (*)())FUN_0000b578)();
    return param_1 + iVar2 + iVar3;
  }
  return param_1;
}

/* FUN_0000b922 @ 0xb922 (2151 bytes) */
int FUN_0000b922(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined1 *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  char *pcVar8;
  char *pcVar9;
  
  puVar1 = (uint *)(param_1 + param_5 * 8);
  bVar2 = *(byte *)((int)puVar1 + 1) >> 4 & 7;
  if (bVar2 == 1) {
    if (s_tmp_001b7228[0] == '\0') {
      iVar4 = 0;
    }
    else {
      iVar4 = 0;
      pcVar8 = "tmp";
      cVar7 = s_tmp_001b7228[0];
      do {
        param_2[iVar4] = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = pcVar8[1];
        pcVar8 = pcVar8 + 1;
      } while (cVar7 != '\0');
    }
    if ((param_6 == 0) || (param_3 == 0)) {
      iVar5 = ((int (*)())FUN_0000b578)();
      param_2 = param_2 + iVar5 + iVar4;
      goto LAB_0000b959;
    }
    iVar5 = ((int (*)())FUN_0000b578)();
    param_2 = param_2 + iVar5 + iVar4;
    if (param_4 == 0) {
      bVar2 = (byte)puVar1[1];
      goto LAB_0000b96b;
    }
    bVar2 = (byte)puVar1[1];
    if ((bVar2 & 1) == 0) {
      if (*(int *)(param_4 + (uint)*(ushort *)((int)puVar1 + 6) * 4) != -1) {
        if (s___001b722c[0] == '\0') {
          iVar4 = 0;
        }
        else {
          iVar4 = 0;
          pcVar8 = "[";
          cVar7 = s___001b722c[0];
          do {
            param_2[iVar4] = cVar7;
            iVar4 = iVar4 + 1;
            cVar7 = pcVar8[1];
            pcVar8 = pcVar8 + 1;
          } while (cVar7 != '\0');
        }
        iVar5 = ((int (*)())FUN_0000b578)();
        if (s___001b7230[0] == '\0') {
          iVar6 = 0;
        }
        else {
          iVar6 = 0;
          pcVar8 = "]";
          cVar7 = s___001b7230[0];
          do {
            param_2[iVar6 + iVar5 + iVar4] = cVar7;
            iVar6 = iVar6 + 1;
            cVar7 = pcVar8[1];
            pcVar8 = pcVar8 + 1;
          } while (cVar7 != '\0');
        }
        param_2 = param_2 + iVar6 + iVar5 + iVar4;
        bVar2 = (byte)puVar1[1];
      }
      goto LAB_0000b96b;
    }
LAB_0000b974:
    if (s__adr_001b7238[0] == '\0') {
      iVar4 = 0;
    }
    else {
      iVar4 = 0;
      pcVar8 = "[adr";
      cVar7 = s__adr_001b7238[0];
      do {
        param_2[iVar4] = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = pcVar8[1];
        pcVar8 = pcVar8 + 1;
      } while (cVar7 != '\0');
    }
    iVar5 = ((int (*)())FUN_0000b578)();
    param_2 = param_2 + iVar5 + iVar4;
    bVar2 = (byte)puVar1[1] >> 2;
    bVar3 = bVar2 & 3;
    if (bVar3 == 1) {
      if (s__y_001b7244[0] != '\0') {
        iVar4 = 0;
        pcVar8 = ".y";
        cVar7 = s__y_001b7244[0];
        do {
          param_2[iVar4] = cVar7;
          iVar4 = iVar4 + 1;
          cVar7 = pcVar8[1];
          pcVar8 = pcVar8 + 1;
        } while (cVar7 != '\0');
        goto LAB_0000bec7;
      }
    }
    else if ((bVar2 & 3) == 0) {
      if (((bVar2 & 3) == 0) && (s__x_001b7240[0] != '\0')) {
        iVar4 = 0;
        pcVar8 = ".x";
        cVar7 = s__x_001b7240[0];
        do {
          param_2[iVar4] = cVar7;
          iVar4 = iVar4 + 1;
          cVar7 = pcVar8[1];
          pcVar8 = pcVar8 + 1;
        } while (cVar7 != '\0');
        goto LAB_0000bec7;
      }
    }
    else if (bVar3 == 2) {
      if (s__z_001b7248[0] != '\0') {
        iVar4 = 0;
        pcVar8 = ".z";
        cVar7 = s__z_001b7248[0];
        do {
          param_2[iVar4] = cVar7;
          iVar4 = iVar4 + 1;
          cVar7 = pcVar8[1];
          pcVar8 = pcVar8 + 1;
        } while (cVar7 != '\0');
        goto LAB_0000bec7;
      }
    }
    else if ((bVar3 == 3) && (s__w_001b724c[0] != '\0')) {
      iVar4 = 0;
      pcVar8 = ".w";
      cVar7 = s__w_001b724c[0];
      do {
        param_2[iVar4] = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = pcVar8[1];
        pcVar8 = pcVar8 + 1;
      } while (cVar7 != '\0');
LAB_0000bec7:
      param_2 = param_2 + iVar4;
    }
    if ((((*puVar1 & 0x7000) != 0x1000) || (param_4 == 0)) ||
       (iVar4 = *(int *)(param_4 + (uint)*(ushort *)((int)puVar1 + 6) * 4), iVar4 == -1)) {
      iVar4 = 0;
    }
    iVar4 = iVar4 + (char)((ushort)puVar1[1] >> 4);
    if (iVar4 != 0) {
      if (0 < iVar4) {
        if (s___001b7250[0] == '\0') {
          iVar4 = 0;
        }
        else {
          iVar4 = 0;
          pcVar8 = "+";
          cVar7 = s___001b7250[0];
          do {
            param_2[iVar4] = cVar7;
            iVar4 = iVar4 + 1;
            cVar7 = pcVar8[1];
            pcVar8 = pcVar8 + 1;
          } while (cVar7 != '\0');
        }
        param_2 = param_2 + iVar4;
      }
      iVar4 = ((int (*)())FUN_0000b578)();
      param_2 = param_2 + iVar4;
    }
    if (s___001b7230[0] != '\0') {
      iVar4 = 0;
      pcVar8 = "]";
      cVar7 = s___001b7230[0];
      do {
        param_2[iVar4] = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = pcVar8[1];
        pcVar8 = pcVar8 + 1;
      } while (cVar7 != '\0');
      param_2 = param_2 + iVar4;
    }
LAB_0000ba1b:
    if (s___001b7254[0] == '\0') {
      iVar4 = 0;
    }
    else {
      iVar4 = 0;
      pcVar8 = ".";
      cVar7 = s___001b7254[0];
      do {
        param_2[iVar4] = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = pcVar8[1];
        pcVar8 = pcVar8 + 1;
      } while (cVar7 != '\0');
    }
    pcVar8 = param_2 + iVar4;
    if ((*(byte *)((int)puVar1 + 2) & 4) == 0) {
      *pcVar8 = '_';
    }
    else {
      *pcVar8 = ((*(byte *)((int)puVar1 + 2) >> 6) + 1 & 3) + 0x77;
    }
    pcVar9 = pcVar8 + 1;
    bVar2 = *(byte *)((int)puVar1 + 2);
    if ((bVar2 & 0x30) != 0) {
      if ((bVar2 & 2) == 0) {
        *pcVar9 = '_';
        pcVar9 = pcVar8 + 2;
        bVar2 = *(byte *)((int)puVar1 + 2);
      }
      else {
        *pcVar9 = (*(byte *)((int)puVar1 + 3) + 1 & 3) + 0x77;
        pcVar9 = pcVar8 + 2;
        bVar2 = *(byte *)((int)puVar1 + 2);
      }
    }
    if (1 < (bVar2 >> 4 & 3)) {
      if ((bVar2 & 1) == 0) {
        *pcVar9 = '_';
        pcVar9 = pcVar9 + 1;
        bVar2 = *(byte *)((int)puVar1 + 2);
      }
      else {
        *pcVar9 = ((*(byte *)((int)puVar1 + 3) >> 2) + 1 & 3) + 0x77;
        pcVar9 = pcVar9 + 1;
        bVar2 = *(byte *)((int)puVar1 + 2);
      }
    }
    if (2 < (bVar2 >> 4 & 3)) {
      if ((char)*(byte *)((int)puVar1 + 1) < '\0') {
        *pcVar9 = ((*(byte *)((int)puVar1 + 3) >> 4) + 1 & 3) + 0x77;
        param_2 = (undefined1 *)((int (*)())FUN_0000b846)();
        goto LAB_0000bae6;
      }
      *pcVar9 = '_';
    }
    param_2 = (undefined1 *)((int (*)())FUN_0000b846)();
LAB_0000bae6:
    bVar2 = (byte)*puVar1;
  }
  else {
    if (bVar2 == 3) {
      if (s_res_001b7234[0] == '\0') {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        pcVar8 = "res";
        cVar7 = s_res_001b7234[0];
        do {
          param_2[iVar4] = cVar7;
          iVar4 = iVar4 + 1;
          cVar7 = pcVar8[1];
          pcVar8 = pcVar8 + 1;
        } while (cVar7 != '\0');
      }
      iVar5 = ((int (*)())FUN_0000b578)();
      param_2 = param_2 + iVar5 + iVar4;
    }
LAB_0000b959:
    if (param_6 != 0) {
      bVar2 = (byte)puVar1[1];
LAB_0000b96b:
      if ((bVar2 & 1) != 0) goto LAB_0000b974;
      goto LAB_0000ba1b;
    }
    if ((*puVar1 & 0x78000) == 0x78000) goto LAB_0000bae6;
    if (s___001b7254[0] == '\0') {
      iVar4 = 0;
    }
    else {
      iVar4 = 0;
      pcVar8 = ".";
      cVar7 = s___001b7254[0];
      do {
        param_2[iVar4] = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = pcVar8[1];
        pcVar8 = pcVar8 + 1;
      } while (cVar7 != '\0');
    }
    param_2 = param_2 + iVar4;
    bVar2 = *(byte *)((int)puVar1 + 2);
    if ((bVar2 & 4) != 0) {
      if (s_x_001b7258[0] == '\0') {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        pcVar8 = "x";
        cVar7 = s_x_001b7258[0];
        do {
          param_2[iVar4] = cVar7;
          iVar4 = iVar4 + 1;
          cVar7 = pcVar8[1];
          pcVar8 = pcVar8 + 1;
        } while (cVar7 != '\0');
        bVar2 = *(byte *)((int)puVar1 + 2);
      }
      param_2 = param_2 + iVar4;
    }
    if ((bVar2 & 2) != 0) {
      if (s_y_001b725c[0] == '\0') {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        pcVar8 = "y";
        cVar7 = s_y_001b725c[0];
        do {
          param_2[iVar4] = cVar7;
          iVar4 = iVar4 + 1;
          cVar7 = pcVar8[1];
          pcVar8 = pcVar8 + 1;
        } while (cVar7 != '\0');
        bVar2 = *(byte *)((int)puVar1 + 2);
      }
      param_2 = param_2 + iVar4;
    }
    if ((bVar2 & 1) != 0) {
      if (s_z_001b7260[0] == '\0') {
        iVar4 = 0;
      }
      else {
        iVar4 = 0;
        pcVar8 = "z";
        cVar7 = s_z_001b7260[0];
        do {
          param_2[iVar4] = cVar7;
          iVar4 = iVar4 + 1;
          cVar7 = pcVar8[1];
          pcVar8 = pcVar8 + 1;
        } while (cVar7 != '\0');
      }
      param_2 = param_2 + iVar4;
    }
    if (-1 < (char)*(byte *)((int)puVar1 + 1)) goto LAB_0000bae6;
    if (s_w_001b7264[0] != '\0') {
      iVar4 = 0;
      pcVar8 = "w";
      cVar7 = s_w_001b7264[0];
      do {
        param_2[iVar4] = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = pcVar8[1];
        pcVar8 = pcVar8 + 1;
      } while (cVar7 != '\0');
      param_2 = param_2 + iVar4;
    }
    bVar2 = (byte)*puVar1;
  }
  if ((bVar2 & 0xe) == 0) {
    return param_2;
  }
  switch(bVar2 >> 1 & 7) {
  case 0:
    if (s__TR_001b7268[0] == '\0') goto switchD_0000bb0e_default;
    iVar4 = 0;
    pcVar8 = " (TR";
    cVar7 = s__TR_001b7268[0];
    do {
      param_2[iVar4] = cVar7;
      iVar4 = iVar4 + 1;
      cVar7 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar7 != '\0');
    break;
  case 1:
    if (s__EQ_001b7270[0] == '\0') goto switchD_0000bb0e_default;
    iVar4 = 0;
    pcVar8 = " (EQ";
    cVar7 = s__EQ_001b7270[0];
    do {
      param_2[iVar4] = cVar7;
      iVar4 = iVar4 + 1;
      cVar7 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar7 != '\0');
    break;
  case 2:
    if (s__GE_001b7278[0] == '\0') goto switchD_0000bb0e_default;
    iVar4 = 0;
    pcVar8 = " (GE";
    cVar7 = s__GE_001b7278[0];
    do {
      param_2[iVar4] = cVar7;
      iVar4 = iVar4 + 1;
      cVar7 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar7 != '\0');
    break;
  case 3:
    if (s__GT_001b7280[0] == '\0') goto switchD_0000bb0e_default;
    iVar4 = 0;
    pcVar8 = " (GT";
    cVar7 = s__GT_001b7280[0];
    do {
      param_2[iVar4] = cVar7;
      iVar4 = iVar4 + 1;
      cVar7 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar7 != '\0');
    break;
  case 4:
    if (s__LE_001b7288[0] == '\0') goto switchD_0000bb0e_default;
    iVar4 = 0;
    pcVar8 = " (LE";
    cVar7 = s__LE_001b7288[0];
    do {
      param_2[iVar4] = cVar7;
      iVar4 = iVar4 + 1;
      cVar7 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar7 != '\0');
    break;
  case 5:
    if (s__LT_001b7290[0] == '\0') goto switchD_0000bb0e_default;
    iVar4 = 0;
    pcVar8 = " (LT";
    cVar7 = s__LT_001b7290[0];
    do {
      param_2[iVar4] = cVar7;
      iVar4 = iVar4 + 1;
      cVar7 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar7 != '\0');
    break;
  case 6:
    if (s__NE_001b7298[0] == '\0') goto switchD_0000bb0e_default;
    iVar4 = 0;
    pcVar8 = " (NE";
    cVar7 = s__NE_001b7298[0];
    do {
      param_2[iVar4] = cVar7;
      iVar4 = iVar4 + 1;
      cVar7 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar7 != '\0');
    break;
  case 7:
    if (s__FL_001b72a0[0] == '\0') goto switchD_0000bb0e_default;
    iVar4 = 0;
    pcVar8 = " (FL";
    cVar7 = s__FL_001b72a0[0];
    do {
      param_2[iVar4] = cVar7;
      iVar4 = iVar4 + 1;
      cVar7 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar7 != '\0');
    break;
  default:
    goto switchD_0000bb0e_default;
  }
  bVar2 = (byte)*puVar1;
  param_2 = param_2 + iVar4;
switchD_0000bb0e_default:
  if ((bVar2 & 1) != 0) {
    *param_2 = 0x31;
    param_2 = param_2 + 1;
  }
  *param_2 = 0x2e;
  param_2[1] = (((byte)*puVar1 >> 4) + 1 & 3) + 0x77;
  param_2[2] = (((byte)*puVar1 >> 6) + 1 & 3) + 0x77;
  param_2[3] = (*(byte *)((int)puVar1 + 1) + 1 & 3) + 0x77;
  param_2[4] = ((*(byte *)((int)puVar1 + 1) >> 2) + 1 & 3) + 0x77;
  param_2[5] = 0x29;
  return param_2 + 6;
}

/* FUN_0000c1a9 @ 0xc1a9 (424 bytes) */
int FUN_0000c1a9(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  char cVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  char *pcVar8;
  char *pcVar9;
  char cVar10;
  
  cVar10 = s___001b720c[0];
  pcVar8 = ":";
  if (s___001b720c[0] == '\0') {
    iVar4 = 0;
  }
  else {
    iVar4 = 0;
    pcVar9 = pcVar8;
    cVar7 = s___001b720c[0];
    do {
      *(char *)(param_1 + iVar4) = cVar7;
      iVar4 = iVar4 + 1;
      cVar7 = pcVar9[1];
      pcVar9 = pcVar9 + 1;
    } while (cVar7 != '\0');
  }
  iVar5 = ((int (*)())FUN_0000b578)();
  iVar5 = param_1 + iVar4 + iVar5;
  cVar1 = s_X_001b7208[0];
  cVar3 = s_F_001b7210[0];
  cVar2 = s_I_001b7214[0];
  cVar7 = s_B_001b7218[0];
  if (param_3 != 0) {
    if (cVar10 == '\0') {
      iVar4 = ((int (*)())FUN_0000b578)();
      iVar5 = iVar5 + iVar4;
      cVar1 = s_X_001b7208[0];
      cVar3 = s_F_001b7210[0];
      cVar2 = s_I_001b7214[0];
      cVar7 = s_B_001b7218[0];
    }
    else {
      iVar4 = 0;
      do {
        *(char *)(iVar5 + iVar4) = cVar10;
        iVar4 = iVar4 + 1;
        cVar10 = pcVar8[1];
        pcVar8 = pcVar8 + 1;
      } while (cVar10 != '\0');
      iVar6 = ((int (*)())FUN_0000b578)();
      iVar5 = iVar5 + iVar4 + iVar6;
      cVar1 = s_X_001b7208[0];
      cVar3 = s_F_001b7210[0];
      cVar2 = s_I_001b7214[0];
      cVar7 = s_B_001b7218[0];
    }
  }
  s_X_001b7208[0] = cVar1;
  s_F_001b7210[0] = cVar3;
  s_I_001b7214[0] = cVar2;
  s_B_001b7218[0] = cVar7;
  if (param_4 == 2) {
    if (cVar1 == '\0') {
      return iVar5;
    }
    iVar4 = 0;
    pcVar8 = "X";
    do {
      *(char *)(iVar5 + iVar4) = cVar1;
      iVar4 = iVar4 + 1;
      cVar1 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
  }
  else if (param_4 < 3) {
    if (param_4 != 1) {
      return iVar5;
    }
    if (cVar3 == '\0') {
      s_X_001b7208[0] = cVar1;
      s_F_001b7210[0] = cVar3;
      s_I_001b7214[0] = cVar2;
      s_B_001b7218[0] = cVar7;
      return iVar5;
    }
    iVar4 = 0;
    pcVar8 = "F";
    do {
      *(char *)(iVar5 + iVar4) = cVar3;
      iVar4 = iVar4 + 1;
      cVar3 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar3 != '\0');
  }
  else if (param_4 == 3) {
    if (cVar2 == '\0') {
      s_X_001b7208[0] = cVar1;
      s_F_001b7210[0] = cVar3;
      s_I_001b7214[0] = cVar2;
      s_B_001b7218[0] = cVar7;
      return iVar5;
    }
    iVar4 = 0;
    pcVar8 = "I";
    do {
      *(char *)(iVar5 + iVar4) = cVar2;
      iVar4 = iVar4 + 1;
      cVar2 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
  }
  else {
    if (param_4 != 4) {
      s_X_001b7208[0] = cVar1;
      s_F_001b7210[0] = cVar3;
      s_I_001b7214[0] = cVar2;
      s_B_001b7218[0] = cVar7;
      return iVar5;
    }
    if (cVar7 == '\0') {
      s_X_001b7208[0] = cVar1;
      s_F_001b7210[0] = cVar3;
      s_I_001b7214[0] = cVar2;
      s_B_001b7218[0] = cVar7;
      return iVar5;
    }
    iVar4 = 0;
    pcVar8 = "B";
    do {
      *(char *)(iVar5 + iVar4) = cVar7;
      iVar4 = iVar4 + 1;
      cVar7 = pcVar8[1];
      pcVar8 = pcVar8 + 1;
    } while (cVar7 != '\0');
  }
  return iVar5 + iVar4;
}

/* FUN_0000c351 @ 0xc351 (2970 bytes) */
int FUN_0000c351(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  char *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  uint *puVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  char *pcVar10;
  
  puVar1 = (uint *)(param_1 + param_6 * 8);
  bVar2 = (byte)*puVar1;
  if (((bVar2 & 0x10) != 0) && (s___001b72a8[0] != '\0')) {
    iVar6 = 0;
    pcVar10 = "-";
    cVar5 = s___001b72a8[0];
    do {
      param_2[iVar6] = cVar5;
      iVar6 = iVar6 + 1;
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
    bVar2 = (byte)*puVar1;
    param_2 = param_2 + iVar6;
  }
  if (((bVar2 & 0x20) != 0) && (s___001b72ac[0] != '\0')) {
    iVar6 = 0;
    pcVar10 = "|";
    cVar5 = s___001b72ac[0];
    do {
      param_2[iVar6] = cVar5;
      iVar6 = iVar6 + 1;
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
    param_2 = param_2 + iVar6;
  }
  switch((ushort)*puVar1 >> 6 & 7) {
  case 0:
    if (s_att_001b72b0[0] == '\0') {
LAB_0000cd1a:
      iVar6 = 0;
    }
    else {
      iVar6 = 0;
      pcVar10 = "att";
      cVar5 = s_att_001b72b0[0];
      do {
        param_2[iVar6] = cVar5;
        iVar6 = iVar6 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
    }
    break;
  case 1:
    if (s_tmp_001b7228[0] == '\0') {
      iVar6 = 0;
    }
    else {
      iVar6 = 0;
      pcVar10 = "tmp";
      cVar5 = s_tmp_001b7228[0];
      do {
        param_2[iVar6] = cVar5;
        iVar6 = iVar6 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
    }
    if (param_4 == 0) {
      iVar7 = ((int (*)())FUN_0000b578)();
    }
    else {
      iVar7 = ((int (*)())FUN_0000b578)();
    }
    param_2 = param_2 + iVar7 + iVar6;
    if (param_5 == 0) {
      bVar2 = (byte)*puVar1;
    }
    else {
      bVar2 = (byte)*puVar1;
      if ((bVar2 & 1) != 0) goto LAB_0000c526;
      if (*(int *)(param_5 + (uint)*(ushort *)((int)puVar1 + 6) * 4) != -1) {
        if (s___001b722c[0] == '\0') {
          iVar6 = 0;
        }
        else {
          iVar6 = 0;
          pcVar10 = "[";
          cVar5 = s___001b722c[0];
          do {
            param_2[iVar6] = cVar5;
            iVar6 = iVar6 + 1;
            cVar5 = pcVar10[1];
            pcVar10 = pcVar10 + 1;
          } while (cVar5 != '\0');
        }
        iVar7 = ((int (*)())FUN_0000b578)();
        param_2 = param_2 + iVar7 + iVar6;
        if (s___001b7230[0] == '\0') goto LAB_0000ce7e;
        iVar6 = 0;
        pcVar10 = "]";
        cVar5 = s___001b7230[0];
        do {
          param_2[iVar6] = cVar5;
          iVar6 = iVar6 + 1;
          cVar5 = pcVar10[1];
          pcVar10 = pcVar10 + 1;
        } while (cVar5 != '\0');
        goto LAB_0000ce80;
      }
    }
    goto LAB_0000c41a;
  case 2:
    if (s_prm_001b72b4[0] == '\0') {
      iVar6 = 0;
    }
    else {
      iVar6 = 0;
      pcVar10 = "prm";
      cVar5 = s_prm_001b72b4[0];
      do {
        param_2[iVar6] = cVar5;
        iVar6 = iVar6 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
    }
    iVar7 = ((int (*)())FUN_0000b578)();
    param_2 = param_2 + iVar7 + iVar6;
    bVar2 = (byte)*puVar1;
    if ((bVar2 & 1) == 0) {
      if (*(int *)(param_3 + (uint)*(ushort *)((int)puVar1 + 6) * 4) != -1) {
        if (s___001b722c[0] == '\0') {
          iVar6 = 0;
        }
        else {
          iVar6 = 0;
          pcVar10 = "[";
          cVar5 = s___001b722c[0];
          do {
            param_2[iVar6] = cVar5;
            iVar6 = iVar6 + 1;
            cVar5 = pcVar10[1];
            pcVar10 = pcVar10 + 1;
          } while (cVar5 != '\0');
        }
        iVar7 = ((int (*)())FUN_0000b578)();
        param_2 = param_2 + iVar7 + iVar6;
        if (s___001b7230[0] == '\0') {
LAB_0000ce7e:
          iVar6 = 0;
        }
        else {
          iVar6 = 0;
          pcVar10 = "]";
          cVar5 = s___001b7230[0];
          do {
            param_2[iVar6] = cVar5;
            iVar6 = iVar6 + 1;
            cVar5 = pcVar10[1];
            pcVar10 = pcVar10 + 1;
          } while (cVar5 != '\0');
        }
LAB_0000ce80:
        param_2 = param_2 + iVar6;
        bVar2 = (byte)*puVar1;
      }
      goto LAB_0000c41a;
    }
    goto LAB_0000c526;
  case 3:
    if (s_res_001b7234[0] == '\0') goto LAB_0000cd1a;
    iVar6 = 0;
    pcVar10 = "res";
    cVar5 = s_res_001b7234[0];
    do {
      param_2[iVar6] = cVar5;
      iVar6 = iVar6 + 1;
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
    break;
  case 4:
    if (s_adr_001b72b8[0] == '\0') goto LAB_0000cd1a;
    iVar6 = 0;
    pcVar10 = "adr";
    cVar5 = s_adr_001b72b8[0];
    do {
      param_2[iVar6] = cVar5;
      iVar6 = iVar6 + 1;
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
    break;
  default:
    bVar2 = (byte)*puVar1;
    goto LAB_0000c41a;
  }
  iVar7 = ((int (*)())FUN_0000b578)();
  param_2 = param_2 + iVar7 + iVar6;
  bVar2 = (byte)*puVar1;
LAB_0000c41a:
  if ((bVar2 & 1) == 0) {
    uVar3 = (ushort)*puVar1;
    cVar5 = s___001b7254[0];
    goto joined_r0x0000c431;
  }
LAB_0000c526:
  if (s__adr_001b7238[0] == '\0') {
    iVar6 = ((int (*)())FUN_0000b578)();
    param_2 = param_2 + iVar6;
    uVar4 = (byte)((byte)*puVar1 >> 2) & 3;
    iVar6 = uVar4 - 1;
    if (uVar4 == 1) goto LAB_0000c9d0;
LAB_0000c55d:
    if (SBORROW4(uVar4,1) == iVar6 < 0) {
      if (uVar4 == 2) {
        if (s__z_001b7248[0] != '\0') {
          iVar6 = 0;
          pcVar10 = ".z";
          cVar5 = s__z_001b7248[0];
          do {
            param_2[iVar6] = cVar5;
            iVar6 = iVar6 + 1;
            cVar5 = pcVar10[1];
            pcVar10 = pcVar10 + 1;
          } while (cVar5 != '\0');
LAB_0000c9fa:
          param_2 = param_2 + iVar6;
        }
      }
      else {
        if (uVar4 != 3) goto LAB_0000c575;
        if (s__w_001b724c[0] != '\0') {
          iVar6 = 0;
          pcVar10 = ".w";
          cVar5 = s__w_001b724c[0];
          do {
            param_2[iVar6] = cVar5;
            iVar6 = iVar6 + 1;
            cVar5 = pcVar10[1];
            pcVar10 = pcVar10 + 1;
          } while (cVar5 != '\0');
          goto LAB_0000c9fa;
        }
      }
      goto LAB_0000c9fc;
    }
    if (uVar4 == 0) {
      if (s__x_001b7240[0] != '\0') {
        iVar6 = 0;
        pcVar10 = ".x";
        cVar5 = s__x_001b7240[0];
        do {
          param_2[iVar6] = cVar5;
          iVar6 = iVar6 + 1;
          cVar5 = pcVar10[1];
          pcVar10 = pcVar10 + 1;
        } while (cVar5 != '\0');
        goto LAB_0000c9fa;
      }
      goto LAB_0000c9fc;
    }
LAB_0000c575:
    uVar3 = (ushort)*puVar1 & 0x1c0;
    if (uVar3 == 0x40) goto LAB_0000ca10;
LAB_0000c589:
    if ((uVar3 != 0x80) || (param_3 == 0)) goto LAB_0000c593;
    iVar6 = *(int *)(param_3 + (uint)*(ushort *)((int)puVar1 + 6) * 4);
joined_r0x0000cbbc:
    if (iVar6 == -1) goto LAB_0000c593;
  }
  else {
    iVar6 = 0;
    pcVar10 = "[adr";
    cVar5 = s__adr_001b7238[0];
    do {
      param_2[iVar6] = cVar5;
      iVar6 = iVar6 + 1;
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
    iVar7 = ((int (*)())FUN_0000b578)();
    param_2 = param_2 + iVar7 + iVar6;
    uVar4 = (byte)((byte)*puVar1 >> 2) & 3;
    iVar6 = uVar4 - 1;
    if (iVar6 != 0) goto LAB_0000c55d;
LAB_0000c9d0:
    if (s__y_001b7244[0] != '\0') {
      iVar6 = 0;
      pcVar10 = ".y";
      cVar5 = s__y_001b7244[0];
      do {
        param_2[iVar6] = cVar5;
        iVar6 = iVar6 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      goto LAB_0000c9fa;
    }
LAB_0000c9fc:
    uVar3 = (ushort)*puVar1 & 0x1c0;
    if (uVar3 != 0x40) goto LAB_0000c589;
LAB_0000ca10:
    if (param_5 != 0) {
      iVar6 = *(int *)(param_5 + (uint)*(ushort *)((int)puVar1 + 6) * 4);
      goto joined_r0x0000cbbc;
    }
LAB_0000c593:
    iVar6 = 0;
  }
  iVar6 = iVar6 + (char)*(byte *)((int)puVar1 + 3);
  if (iVar6 != 0) {
    if ((0 < iVar6) && (s___001b7250[0] != '\0')) {
      iVar6 = 0;
      pcVar10 = "+";
      cVar5 = s___001b7250[0];
      do {
        param_2[iVar6] = cVar5;
        iVar6 = iVar6 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      param_2 = param_2 + iVar6;
    }
    iVar6 = ((int (*)())FUN_0000b578)();
    param_2 = param_2 + iVar6;
  }
  if (s___001b7230[0] != '\0') {
    iVar6 = 0;
    pcVar10 = "]";
    cVar5 = s___001b7230[0];
    do {
      param_2[iVar6] = cVar5;
      iVar6 = iVar6 + 1;
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
    param_2 = param_2 + iVar6;
  }
  uVar3 = (ushort)*puVar1;
  cVar5 = s___001b7254[0];
joined_r0x0000c431:
  s___001b7254[0] = cVar5;
  if ((uVar3 & 0x1c0) == 0x100) {
LAB_0000c604:
    if (param_7 != 0) {
LAB_0000c6f6:
      param_2 = (char *)((int (*)())FUN_0000b846)();
    }
LAB_0000c60f:
    if (((*puVar1 & 0x20) != 0) && (s___001b72ac[0] != '\0')) {
      iVar6 = 0;
      pcVar10 = "|";
      cVar5 = s___001b72ac[0];
      do {
        param_2[iVar6] = cVar5;
        iVar6 = iVar6 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      param_2 = param_2 + iVar6;
    }
    return param_2;
  }
  if (param_8 != 0) {
    iVar6 = param_1 + 8 + param_6 * 8;
    bVar2 = *(byte *)(iVar6 + 2) & 0xf;
    if (s___001b72bc[0] == '\0') goto LAB_0000caf1;
LAB_0000c476:
    iVar7 = 0;
    pcVar10 = ", ";
    cVar5 = s___001b72bc[0];
    do {
      param_2[iVar7] = cVar5;
      iVar7 = iVar7 + 1;
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
LAB_0000c48e:
    param_2 = param_2 + iVar7;
    iVar7 = 0;
LAB_0000c492:
    switch(bVar2) {
    case 0:
      if (s_x_001b7258[0] == '\0') {
LAB_0000ca46:
        iVar8 = 0;
      }
      else {
        iVar8 = 0;
        pcVar10 = "x";
        cVar5 = s_x_001b7258[0];
        do {
          param_2[iVar8] = cVar5;
          iVar8 = iVar8 + 1;
          cVar5 = pcVar10[1];
          pcVar10 = pcVar10 + 1;
        } while (cVar5 != '\0');
      }
      break;
    case 1:
      if (s_y_001b725c[0] == '\0') goto LAB_0000ca46;
      iVar8 = 0;
      pcVar10 = "y";
      cVar5 = s_y_001b725c[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      break;
    case 2:
      if (s_z_001b7260[0] == '\0') goto LAB_0000ca46;
      iVar8 = 0;
      pcVar10 = "z";
      cVar5 = s_z_001b7260[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      break;
    case 3:
      if (s_w_001b7264[0] == '\0') goto LAB_0000ca46;
      iVar8 = 0;
      pcVar10 = "w";
      cVar5 = s_w_001b7264[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      break;
    case 4:
      if (s__x_001b72c4[0] == '\0') goto LAB_0000ca46;
      iVar8 = 0;
      pcVar10 = "-x";
      cVar5 = s__x_001b72c4[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      break;
    case 5:
      if (s__y_001b72c8[0] == '\0') goto LAB_0000ca46;
      iVar8 = 0;
      pcVar10 = "-y";
      cVar5 = s__y_001b72c8[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      break;
    case 6:
      if (s__z_001b72cc[0] == '\0') goto LAB_0000ca46;
      iVar8 = 0;
      pcVar10 = "-z";
      cVar5 = s__z_001b72cc[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      break;
    case 7:
      if (s__w_001b72d0[0] == '\0') goto LAB_0000ca46;
      iVar8 = 0;
      pcVar10 = "-w";
      cVar5 = s__w_001b72d0[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      break;
    case 8:
      if (s_1_001b71f4[0] == '\0') goto LAB_0000ca46;
      iVar8 = 0;
      pcVar10 = "1";
      cVar5 = s_1_001b71f4[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      break;
    case 9:
      if (s_0_001b72d4[0] == '\0') goto LAB_0000ca46;
      iVar8 = 0;
      pcVar10 = "0";
      cVar5 = s_0_001b72d4[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      break;
    case 10:
      if (s__1_001b72d8[0] == '\0') goto LAB_0000ca46;
      iVar8 = 0;
      pcVar10 = "-1";
      cVar5 = s__1_001b72d8[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
      break;
    default:
      goto switchD_0000c4a8_default;
    }
    param_2 = param_2 + iVar8;
switchD_0000c4a8_default:
    iVar7 = iVar7 + 1;
    if (iVar7 == 4) goto LAB_0000c604;
    if (iVar7 == 1) {
      bVar2 = *(byte *)(iVar6 + 2) >> 4;
      if (s___001b72c0[0] == '\0') goto LAB_0000c492;
      iVar8 = 0;
      pcVar10 = ",";
      cVar5 = s___001b72c0[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
    }
    else {
      if (iVar7 < 2) {
        if (iVar7 == 0) goto code_r0x0000cad3;
        goto LAB_0000c492;
      }
      if (iVar7 != 2) {
        if ((iVar7 == 3) && (bVar2 = *(byte *)(iVar6 + 3) >> 4, s___001b72c0[0] != '\0')) {
          iVar8 = 0;
          pcVar10 = ",";
          cVar5 = s___001b72c0[0];
          do {
            param_2[iVar8] = cVar5;
            iVar8 = iVar8 + 1;
            cVar5 = pcVar10[1];
            pcVar10 = pcVar10 + 1;
          } while (cVar5 != '\0');
          goto LAB_0000c7ac;
        }
        goto LAB_0000c492;
      }
      bVar2 = *(byte *)(iVar6 + 3) & 0xf;
      if (s___001b72c0[0] == '\0') goto LAB_0000c492;
      iVar8 = 0;
      pcVar10 = ",";
      cVar5 = s___001b72c0[0];
      do {
        param_2[iVar8] = cVar5;
        iVar8 = iVar8 + 1;
        cVar5 = pcVar10[1];
        pcVar10 = pcVar10 + 1;
      } while (cVar5 != '\0');
    }
LAB_0000c7ac:
    param_2 = param_2 + iVar8;
    goto LAB_0000c492;
  }
  if (param_7 == 0) {
    if ((*puVar1 & 0x1fe00) != 0x1c800) {
      if (cVar5 == '\0') {
        iVar6 = 0;
      }
      else {
        iVar6 = 0;
        pcVar10 = ".";
        do {
          param_2[iVar6] = cVar5;
          iVar6 = iVar6 + 1;
          cVar5 = pcVar10[1];
          pcVar10 = pcVar10 + 1;
        } while (cVar5 != '\0');
      }
      param_2 = param_2 + iVar6;
      bVar2 = *(byte *)((int)puVar1 + 1);
      bVar9 = bVar2 >> 1 & 3;
      if (((bVar9 == (bVar2 >> 3 & 3)) && (bVar9 == (bVar2 >> 5 & 3))) &&
         (bVar9 == ((byte)(*puVar1 >> 0xf) & 3))) {
        *param_2 = (bVar9 + 1 & 3) + 0x77;
        param_2 = param_2 + 1;
      }
      else {
        *param_2 = (bVar9 + 1 & 3) + 0x77;
        param_2[1] = ((*(byte *)((int)puVar1 + 1) >> 3) + 1 & 3) + 0x77;
        param_2[2] = ((*(byte *)((int)puVar1 + 1) >> 5) + 1 & 3) + 0x77;
        param_2[3] = ((char)(*puVar1 >> 0xf) + 1U & 3) + 0x77;
        param_2 = param_2 + 4;
      }
    }
    goto LAB_0000c60f;
  }
  if (cVar5 == '\0') {
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    pcVar10 = ".";
    do {
      param_2[iVar6] = cVar5;
      iVar6 = iVar6 + 1;
      cVar5 = pcVar10[1];
      pcVar10 = pcVar10 + 1;
    } while (cVar5 != '\0');
  }
  param_2 = param_2 + iVar6;
  *param_2 = ((*(byte *)((int)puVar1 + 1) >> 1) + 1 & 3) + 0x77;
  pcVar10 = param_2 + 1;
  bVar2 = *(byte *)((int)puVar1 + 2);
  if ((bVar2 & 0xc) != 0) {
    param_2[1] = ((*(byte *)((int)puVar1 + 1) >> 3) + 1 & 3) + 0x77;
    pcVar10 = param_2 + 2;
    bVar2 = *(byte *)((int)puVar1 + 2);
  }
  if (1 < (bVar2 >> 2 & 3)) {
    *pcVar10 = ((*(byte *)((int)puVar1 + 1) >> 5) + 1 & 3) + 0x77;
    pcVar10 = pcVar10 + 1;
    bVar2 = *(byte *)((int)puVar1 + 2);
  }
  if (2 < (bVar2 >> 2 & 3)) {
    *pcVar10 = ((char)(*puVar1 >> 0xf) + 1U & 3) + 0x77;
  }
  goto LAB_0000c6f6;
code_r0x0000cad3:
  bVar2 = *(byte *)(iVar6 + 2) & 0xf;
  if (s___001b72bc[0] != '\0') goto LAB_0000c476;
LAB_0000caf1:
  iVar7 = 0;
  goto LAB_0000c48e;
}

/* FUN_0000cf2d @ 0xcf2d (628 bytes) */
int FUN_0000cf2d(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  
  if (s_texture__001b72dc[0] == '\0') {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    pcVar3 = "texture[";
    cVar4 = s_texture__001b72dc[0];
    do {
      *(char *)(param_2 + iVar1) = cVar4;
      iVar1 = iVar1 + 1;
      cVar4 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (cVar4 != '\0');
  }
  if (param_7 == 0) {
    iVar2 = ((int (*)())FUN_0000b578)();
    iVar2 = param_2 + iVar1 + iVar2;
  }
  else {
    iVar2 = ((int (*)())FUN_0000c351)(param_3,param_4,param_5,param_6,1,0);
    param_6 = param_6 + 1;
  }
  if (s____001b72e8[0] == '\0') {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    pcVar3 = "], ";
    cVar4 = s____001b72e8[0];
    do {
      *(char *)(iVar2 + iVar1) = cVar4;
      iVar1 = iVar1 + 1;
      cVar4 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (cVar4 != '\0');
  }
  iVar2 = iVar2 + iVar1;
  switch(*(byte *)(param_1 + 3 + param_6 * 8) & 7) {
  case 0:
    if (s_CUBE_001b72f8[0] == '\0') {
      return iVar2;
    }
    iVar1 = 0;
    pcVar3 = "CUBE";
    cVar4 = s_CUBE_001b72f8[0];
    do {
      *(char *)(iVar2 + iVar1) = cVar4;
      iVar1 = iVar1 + 1;
      cVar4 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (cVar4 != '\0');
    break;
  case 1:
    if (s_3D_001b72f4[0] == '\0') {
      return iVar2;
    }
    iVar1 = 0;
    pcVar3 = "3D";
    cVar4 = s_3D_001b72f4[0];
    do {
      *(char *)(iVar2 + iVar1) = cVar4;
      iVar1 = iVar1 + 1;
      cVar4 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (cVar4 != '\0');
    break;
  case 2:
    if (s_RECT_001b7300[0] == '\0') {
      return iVar2;
    }
    iVar1 = 0;
    pcVar3 = "RECT";
    cVar4 = s_RECT_001b7300[0];
    do {
      *(char *)(iVar1 + iVar2) = cVar4;
      iVar1 = iVar1 + 1;
      cVar4 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (cVar4 != '\0');
    break;
  case 3:
    if (s_2D_001b72f0[0] == '\0') {
      return iVar2;
    }
    iVar1 = 0;
    pcVar3 = "2D";
    cVar4 = s_2D_001b72f0[0];
    do {
      *(char *)(iVar2 + iVar1) = cVar4;
      iVar1 = iVar1 + 1;
      cVar4 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (cVar4 != '\0');
    break;
  case 4:
    if (s_1D_001b72ec[0] == '\0') {
      return iVar2;
    }
    iVar1 = 0;
    pcVar3 = "1D";
    cVar4 = s_1D_001b72ec[0];
    do {
      *(char *)(iVar2 + iVar1) = cVar4;
      iVar1 = iVar1 + 1;
      cVar4 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (cVar4 != '\0');
    break;
  case 5:
    if (s_SHADOWRECT_001b7308[0] == '\0') {
      return iVar2;
    }
    iVar1 = 0;
    pcVar3 = "SHADOWRECT";
    cVar4 = s_SHADOWRECT_001b7308[0];
    do {
      *(char *)(iVar2 + iVar1) = cVar4;
      iVar1 = iVar1 + 1;
      cVar4 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (cVar4 != '\0');
    break;
  case 6:
    if (s_SHADOW2D_001b7314[0] == '\0') {
      return iVar2;
    }
    iVar1 = 0;
    pcVar3 = "SHADOW2D";
    cVar4 = s_SHADOW2D_001b7314[0];
    do {
      *(char *)(iVar2 + iVar1) = cVar4;
      iVar1 = iVar1 + 1;
      cVar4 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (cVar4 != '\0');
    break;
  case 7:
    if (s_SHADOW1D_001b7320[0] == '\0') {
      return iVar2;
    }
    iVar1 = 0;
    pcVar3 = "SHADOW1D";
    cVar4 = s_SHADOW1D_001b7320[0];
    do {
      *(char *)(iVar2 + iVar1) = cVar4;
      iVar1 = iVar1 + 1;
      cVar4 = pcVar3[1];
      pcVar3 = pcVar3 + 1;
    } while (cVar4 != '\0');
    break;
  default:
    goto switchD_0000cfc9_default;
  }
  iVar2 = iVar2 + iVar1;
switchD_0000cfc9_default:
  return iVar2;
}

/* FUN_0000d1c2 @ 0xd1c2 (11074 bytes) */
int FUN_0000d1c2(param_1)
  uint *param_1;
{
  float *pfVar1;
  size_t sVar2;
  char acVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  byte bVar8;
  byte bVar9;
  ushort uVar10;
  void *pvVar11;
  int iVar12;
  int iVar13;
  uint *puVar14;
  uint *puVar15;
  int iVar16;
  int iVar17;
  uint *puVar18;
  char *pcVar19;
  char cVar20;
  char cVar21;
  char *pcVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  uint local_1cc;
  char *local_1c8;
  char *local_1b0;
  uint *local_180;
  uint local_16c;
  int local_168;
  void *local_164;
  void *local_160;
  void *local_15c;
  void *local_158;
  void *local_154;
  uint *local_150;
  void *local_14c;
  size_t local_148;
  int local_144;
  int local_134;
  uint local_130;
  uint local_12c;
  uint *local_124;
  int local_120;
  uint local_11c;
  uint local_118;
  uint local_114;
  uint *local_10c;
  int local_104;
  int local_100;
  uint *local_b8;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  int local_9c;
  uint local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  uint local_74;
  uint local_70;
  int local_54;
  int local_50;
  char cStack_32;
  char cStack_31;
  void *local_30;
  char *local_24;
  void *local_20;
  
  pvVar11 = _malloc(0x800);
  if (pvVar11 == (void *)0x0) {
    return (void *)0x0;
  }
  uVar4 = *param_1;
  bVar6 = uVar4 - 0x8b30 < 2;
  if (uVar4 == 0x8804) {
    if (s___ARBfp1_0_001b734c[0] == '\0') goto LAB_0000d255;
    iVar12 = 0;
    pcVar22 = "!!ARBfp1.0\n";
    cVar21 = s___ARBfp1_0_001b734c[0];
    do {
      *(char *)((int)pvVar11 + iVar12) = cVar21;
      iVar12 = iVar12 + 1;
      cVar21 = pcVar22[1];
      pcVar22 = pcVar22 + 1;
    } while (cVar21 != '\0');
  }
  else if (uVar4 < 0x8805) {
    if (uVar4 == 0x8620) {
      if (s___ARBvp1_0_001b732c[0] == '\0') goto LAB_0000d255;
      pcVar22 = "!!ARBvp1.0\n";
      iVar13 = 0;
      cVar21 = s___ARBvp1_0_001b732c[0];
      do {
        *(char *)((int)pvVar11 + iVar13) = cVar21;
        iVar12 = iVar13 + 1;
        if (pcVar22[1] == '\0') break;
        *(char *)((int)pvVar11 + iVar12) = pcVar22[1];
        iVar12 = iVar13 + 2;
        cVar21 = pcVar22[2];
        pcVar22 = pcVar22 + 2;
        iVar13 = iVar12;
      } while (cVar21 != '\0');
    }
    else {
LAB_0000d378:
      if (s_Unkown_Target__error__001b7370[0] == '\0') {
LAB_0000d255:
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        pcVar22 = "Unkown Target (error)\n";
        cVar21 = s_Unkown_Target__error__001b7370[0];
        do {
          *(char *)((int)pvVar11 + iVar12) = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
      }
    }
  }
  else if (uVar4 == 0x8b30) {
    if (s___ARBfragmentshader_001b7358[0] == '\0') goto LAB_0000d255;
    pcVar22 = "!!ARBfragmentshader\n";
    iVar13 = 0;
    cVar21 = s___ARBfragmentshader_001b7358[0];
    do {
      *(char *)((int)pvVar11 + iVar13) = cVar21;
      iVar12 = iVar13 + 1;
      if (pcVar22[1] == '\0') break;
      *(char *)((int)pvVar11 + iVar12) = pcVar22[1];
      iVar12 = iVar13 + 2;
      cVar21 = pcVar22[2];
      pcVar22 = pcVar22 + 2;
      iVar13 = iVar12;
    } while (cVar21 != '\0');
  }
  else {
    if (uVar4 != 0x8b31) goto LAB_0000d378;
    if (s___ARBvertexshader_001b7338[0] == '\0') goto LAB_0000d255;
    iVar12 = 0;
    pcVar22 = "!!ARBvertexshader\n";
    cVar21 = s___ARBvertexshader_001b7338[0];
    do {
      *(char *)((int)pvVar11 + iVar12) = cVar21;
      iVar12 = iVar12 + 1;
      cVar21 = pcVar22[1];
      pcVar22 = pcVar22 + 1;
    } while (cVar21 != '\0');
  }
  local_24 = (char *)(iVar12 + (int)pvVar11);
  if (bVar6) {
    pcVar22 = "\n";
    if (s__001b7388[0] == '\0') {
      iVar12 = 0;
    }
    else {
      iVar12 = 0;
      cVar21 = s__001b7388[0];
      do {
        local_24[iVar12] = cVar21;
        iVar12 = iVar12 + 1;
        cVar21 = pcVar22[1];
        pcVar22 = pcVar22 + 1;
      } while (cVar21 != '\0');
    }
    local_24 = local_24 + iVar12;
  }
  uVar5 = param_1[0x12];
  puVar18 = param_1 + param_1[0x13] * 2;
  if (0 < (int)uVar5) {
    local_16c = 0;
    local_1b0 = local_24;
    if (s_OPTION_001b738c[0] != '\0') goto LAB_0000d458;
LAB_0000d303:
    iVar12 = 0;
    do {
      local_24 = local_1b0 + iVar12;
      switch(*(undefined1 *)((int)puVar18 + 3)) {
      case 0:
        if (s_ARB_position_invariant_001b7394[0] == '\0') {
code_r0x0000f01b:
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "ARB_position_invariant";
          cVar21 = s_ARB_position_invariant_001b7394[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        break;
      case 1:
        if (s_ARB_fog_exp_001b73ac[0] == '\0') {
code_r0x0000f014:
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "ARB_fog_exp";
          cVar21 = s_ARB_fog_exp_001b73ac[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        goto code_r0x0000d3da;
      case 2:
        if (s_ARB_fog_exp2_001b73b8[0] == '\0') goto code_r0x0000f01b;
        iVar12 = 0;
        pcVar22 = "ARB_fog_exp2";
        cVar21 = s_ARB_fog_exp2_001b73b8[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        break;
      case 3:
        if (s_ARB_fog_linear_001b73c8[0] == '\0') goto code_r0x0000f014;
        iVar12 = 0;
        pcVar22 = "ARB_fog_linear";
        cVar21 = s_ARB_fog_linear_001b73c8[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        goto code_r0x0000d3da;
      case 4:
        if (s_ARB_precision_hint_fastest_001b73d8[0] == '\0') goto code_r0x0000f01b;
        iVar12 = 0;
        pcVar22 = "ARB_precision_hint_fastest";
        cVar21 = s_ARB_precision_hint_fastest_001b73d8[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        break;
      case 5:
        if (s_ARB_precision_hint_nicest_001b73f4[0] == '\0') goto code_r0x0000f014;
        iVar12 = 0;
        pcVar22 = "ARB_precision_hint_nicest";
        cVar21 = s_ARB_precision_hint_nicest_001b73f4[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        goto code_r0x0000d3da;
      case 6:
        if (s_APPLE_no_runtime_compile_001b7410[0] == '\0') goto code_r0x0000f01b;
        iVar12 = 0;
        pcVar22 = "APPLE_no_runtime_compile";
        cVar21 = s_APPLE_no_runtime_compile_001b7410[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        break;
      case 7:
        if (s_APPLE_no_altivec_001b742c[0] == '\0') goto code_r0x0000f014;
        iVar12 = 0;
        pcVar22 = "APPLE_no_altivec";
        cVar21 = s_APPLE_no_altivec_001b742c[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        goto code_r0x0000d3da;
      case 8:
        if (s_NV_fragment_program_001b7440[0] == '\0') goto code_r0x0000f01b;
        iVar12 = 0;
        pcVar22 = "NV_fragment_program";
        cVar21 = s_NV_fragment_program_001b7440[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        break;
      case 9:
        if (s_NV_fragment_program2_001b7454[0] == '\0') goto code_r0x0000f014;
        iVar12 = 0;
        pcVar22 = "NV_fragment_program2";
        cVar21 = s_NV_fragment_program2_001b7454[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        goto code_r0x0000d3da;
      case 10:
        if (s_NV_vertex_program2_001b7488[0] == '\0') goto code_r0x0000f014;
        iVar12 = 0;
        pcVar22 = "NV_vertex_program2";
        cVar21 = s_NV_vertex_program2_001b7488[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        goto code_r0x0000d3da;
      case 0xb:
        if (s_NV_vertex_program3_001b749c[0] == '\0') goto code_r0x0000f01b;
        iVar12 = 0;
        pcVar22 = "NV_vertex_program3";
        cVar21 = s_NV_vertex_program3_001b749c[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        break;
      case 0xc:
        if (s_ARB_draw_buffers_001b74b0[0] == '\0') goto code_r0x0000f014;
        iVar12 = 0;
        pcVar22 = "ARB_draw_buffers";
        cVar21 = s_ARB_draw_buffers_001b74b0[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
code_r0x0000d3da:
        local_24 = local_24 + iVar12;
        goto LAB_0000d3e9;
      case 0xd:
        if (s_ARB_fragment_program_shadow_001b746c[0] == '\0') goto code_r0x0000f01b;
        iVar12 = 0;
        pcVar22 = "ARB_fragment_program_shadow";
        cVar21 = s_ARB_fragment_program_shadow_001b746c[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        break;
      default:
        goto LAB_0000d3e9;
      }
      local_24 = local_24 + iVar12;
LAB_0000d3e9:
      local_1b0 = local_24;
      if (s___001b74c4[0] == '\0') {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        pcVar22 = ";\n";
        cVar21 = s___001b74c4[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
      }
      local_1b0 = local_1b0 + iVar12;
      iVar12 = ((int (*)())FUN_0000b1ac)();
      if (iVar12 == 0) {
        _free(pvVar11);
        return (void *)0x0;
      }
      local_16c = local_16c + 1;
      puVar18 = puVar18 + 2;
      local_24 = local_1b0;
      if (uVar5 == local_16c) break;
      if (s_OPTION_001b738c[0] == '\0') goto LAB_0000d303;
LAB_0000d458:
      iVar12 = 0;
      pcVar22 = "OPTION ";
      cVar21 = s_OPTION_001b738c[0];
      do {
        local_24[iVar12] = cVar21;
        iVar12 = iVar12 + 1;
        cVar21 = pcVar22[1];
        pcVar22 = pcVar22 + 1;
      } while (cVar21 != '\0');
      local_1b0 = local_24;
    } while( true );
  }
  if ((uVar5 != 0) && (bVar6)) {
    pcVar22 = "\n";
    if (s__001b7388[0] == '\0') {
      iVar12 = 0;
    }
    else {
      iVar12 = 0;
      cVar21 = s__001b7388[0];
      do {
        local_24[iVar12] = cVar21;
        iVar12 = iVar12 + 1;
        cVar21 = pcVar22[1];
        pcVar22 = pcVar22 + 1;
      } while (cVar21 != '\0');
    }
    local_24 = local_24 + iVar12;
  }
  uVar5 = param_1[6];
  if (uVar5 != 0) {
    if (s_ADDRESS_adr0_001b74c8[0] == '\0') {
      iVar12 = 0;
    }
    else {
      iVar12 = 0;
      pcVar22 = "ADDRESS adr0";
      cVar21 = s_ADDRESS_adr0_001b74c8[0];
      do {
        local_24[iVar12] = cVar21;
        iVar12 = iVar12 + 1;
        cVar21 = pcVar22[1];
        pcVar22 = pcVar22 + 1;
      } while (cVar21 != '\0');
    }
    local_24 = local_24 + iVar12;
    if (1 < (int)uVar5) {
      uVar24 = 1;
      do {
        local_1b0 = local_24;
        if (s___adr_001b74d8[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = ", adr";
          cVar21 = s___adr_001b74d8[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_24 = local_1b0 + iVar13 + iVar12;
        uVar24 = uVar24 + 1;
      } while (uVar5 != uVar24);
    }
    local_1b0 = local_24;
    if (s___001b74c4[0] == '\0') {
      iVar12 = 0;
    }
    else {
      iVar12 = 0;
      pcVar22 = ";\n";
      cVar21 = s___001b74c4[0];
      do {
        local_24[iVar12] = cVar21;
        iVar12 = iVar12 + 1;
        cVar21 = pcVar22[1];
        pcVar22 = pcVar22 + 1;
      } while (cVar21 != '\0');
    }
    local_24 = local_1b0 + iVar12;
    iVar12 = ((int (*)())FUN_0000b1ac)();
    if (iVar12 == 0) goto LAB_0000f848;
    if (bVar6) {
      pcVar22 = "\n";
      if (s__001b7388[0] == '\0') {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        cVar21 = s__001b7388[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
      }
      local_24 = local_24 + iVar12;
    }
  }
  uVar5 = param_1[4];
  puVar18 = param_1 + param_1[5] * 2;
  if (bVar6) {
    if ((int)uVar5 < 1) {
LAB_0000e7e9:
      local_15c = (void *)0x0;
      local_158 = (void *)0x0;
      uVar24 = param_1[0x10];
      if (uVar24 == 0) goto LAB_0000e31a;
LAB_0000e817:
      local_154 = _malloc(uVar24 << 2);
    }
    else {
      uVar23 = 0;
      uVar24 = 0xffffffff;
      puVar14 = puVar18;
      do {
        if ((int)uVar24 < (int)(uint)*(ushort *)((int)puVar14 + 6)) {
          uVar24 = (uint)*(ushort *)((int)puVar14 + 6);
        }
        uVar23 = uVar23 + 1;
        puVar14 = puVar14 + 2;
      } while (uVar5 != uVar23);
      if (uVar24 == 0xffffffff) goto LAB_0000e7e9;
      sVar2 = uVar24 * 4 + 4;
      local_15c = _malloc(sVar2);
      local_158 = _malloc(sVar2);
      if (local_15c == (void *)0x0) {
LAB_0001107c:
        if (local_158 != (void *)0x0) {
          _free(local_158);
        }
        goto LAB_0000f848;
      }
      if (local_158 == (void *)0x0) {
        _free(local_15c);
        goto LAB_0000f848;
      }
      uVar24 = param_1[0x10];
      if (uVar24 != 0) goto LAB_0000e817;
LAB_0000e31a:
      local_154 = (void *)0x0;
    }
    if (0 < (int)uVar5) {
      local_180 = param_1 + 0x10;
      local_88 = 0;
      local_9c = 0;
      local_134 = -1;
      local_12c = 0xffffffff;
      do {
        uVar24 = (uint)*(ushort *)((int)puVar18 + local_9c * 8 + 6);
        *(uint *)((int)local_15c + uVar24 * 4) = uVar24;
        local_130 = (uint)*(ushort *)((int)puVar18 + local_9c * 8 + 6);
        uVar24 = *local_180;
        puVar14 = param_1 + param_1[0x11] * 2;
        if ((uVar24 == 0) || ((int)uVar24 < 1)) {
LAB_0000e8b0:
          *(int *)((int)local_158 + local_130 * 4) = local_134;
          local_130 = 0xffffffff;
          if (*(ushort *)((int)puVar18 + local_9c * 8 + 6) == local_12c) {
LAB_000106b1:
            *(int *)((int)local_154 + local_88 * 4) = local_134;
            local_88 = local_88 + 1;
            local_134 = -1;
            local_130 = 0xffffffff;
            local_12c = 0xffffffff;
          }
        }
        else {
          local_124 = puVar14;
          if (local_130 != *(ushort *)((int)puVar14 + 2)) {
            uVar23 = 0;
            iVar12 = 8;
            do {
              uVar23 = uVar23 + 1;
              if (uVar24 == uVar23) goto LAB_0000e8b0;
              local_124 = (uint *)((int)puVar14 + iVar12);
              iVar12 = iVar12 + 8;
            } while (local_130 != *(ushort *)((int)local_124 + 2));
          }
          local_12c = (uint)*(ushort *)((int)local_124 + 6);
          *(undefined4 *)((int)local_158 + local_130 * 4) = 0;
          local_134 = 1;
          if (*(ushort *)((int)puVar18 + local_9c * 8 + 6) == local_12c) goto LAB_000106b1;
        }
        puVar14 = puVar18 + local_9c * 2 + 2;
        while( true ) {
          local_9c = local_9c + 1;
          if ((int)uVar5 <= local_9c) goto LAB_0000e967;
          if (local_130 == 0xffffffff) break;
          if ((int)(uint)*(ushort *)((int)puVar14 + 6) <= (int)local_12c) {
            *(uint *)((int)local_15c + (uint)*(ushort *)((int)puVar14 + 6) * 4) = local_130;
            *(int *)((int)local_158 + (uint)*(ushort *)((int)puVar14 + 6) * 4) = local_134;
            local_134 = local_134 + 1;
            if (*(ushort *)((int)puVar14 + 6) == local_12c) {
              *(int *)((int)local_154 + local_88 * 4) = local_134;
              local_88 = local_88 + 1;
              local_134 = -1;
              local_130 = 0xffffffff;
              local_12c = 0xffffffff;
            }
          }
          puVar14 = puVar14 + 2;
        }
      } while( true );
    }
    local_90 = -1;
LAB_0000e339:
    if (local_154 != (void *)0x0) {
      _free(local_154);
    }
  }
  else {
    if (0 < (int)uVar5) {
      local_15c = (void *)0x0;
      local_158 = (void *)0x0;
      local_154 = (void *)0x0;
LAB_0000e967:
      local_84 = 0;
      local_98 = 0;
      local_90 = -1;
LAB_0000e99d:
      puVar14 = puVar18 + local_98 * 2;
      bVar9 = (byte)*puVar14;
      if ((bVar9 & 7) == 1) {
        if (s_LONG_TEMP_001b74e8[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "LONG TEMP ";
          cVar21 = s_LONG_TEMP_001b74e8[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto LAB_0000e9fe;
        }
LAB_00010750:
        iVar12 = 0;
      }
      else {
        if ((bVar9 & 7) == 2) {
          if (s_SHORT_TEMP_001b74f4[0] == '\0') goto LAB_00010750;
          iVar12 = 0;
          pcVar22 = "SHORT TEMP ";
          cVar21 = s_SHORT_TEMP_001b74f4[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        else {
          if ((bVar9 & 7) != 0) goto LAB_0000ea1b;
          if (s_TEMP_001b74e0[0] == '\0') goto LAB_00010750;
          iVar12 = 0;
          pcVar22 = "TEMP ";
          cVar21 = s_TEMP_001b74e0[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
LAB_0000e9fe:
        bVar9 = (byte)*puVar14;
      }
      local_24 = local_24 + iVar12;
LAB_0000ea1b:
      if (bVar6) goto LAB_0000eb0b;
LAB_0000ea35:
      if (s_tmp_001b7228[0] == '\0') {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        pcVar22 = "tmp";
        cVar21 = s_tmp_001b7228[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
      }
      iVar13 = ((int (*)())FUN_0000b578)();
      local_24 = local_24 + iVar13 + iVar12;
LAB_0000ea6c:
      do {
        local_98 = local_98 + 1;
        if (uVar5 == local_98) goto LAB_0000ec34;
LAB_0000ea82:
        if (((byte)puVar14[2] & 7) == (bVar9 & 7)) {
          if (local_90 != -1) goto LAB_0000ec85;
          local_1b0 = local_24;
          if (s___001b72bc[0] == '\0') goto LAB_0001079c;
          iVar12 = 0;
          pcVar22 = ", ";
          cVar21 = s___001b72bc[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
            if (cVar21 == '\0') goto LAB_0000ec6b;
          } while( true );
        }
        if (s___001b74c4[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = ";\n";
          cVar21 = s___001b74c4[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = local_24 + iVar12;
        bVar7 = true;
        while( true ) {
          iVar12 = ((int (*)())FUN_0000b1ac)();
          if (iVar12 == 0) {
            if (local_15c != (void *)0x0) {
              _free(local_15c);
            }
            goto LAB_0001107c;
          }
          if ((int)uVar5 <= (int)local_98) goto LAB_0000e339;
          puVar14 = puVar14 + 2;
          if (bVar7) goto LAB_0000e99d;
          if (!bVar6) goto LAB_0000ea35;
LAB_0000eb0b:
          iVar12 = *(int *)((int)local_158 + (uint)*(ushort *)((int)puVar14 + 6) * 4);
          if (iVar12 == -1) break;
          if (iVar12 == 0) {
            if (s_tmp_001b7228[0] == '\0') {
              iVar12 = 0;
            }
            else {
              iVar12 = 0;
              pcVar22 = "tmp";
              cVar21 = s_tmp_001b7228[0];
              do {
                local_24[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
            }
            iVar13 = ((int (*)())FUN_0000b578)();
            if (s___001b722c[0] == '\0') {
              iVar16 = 0;
            }
            else {
              iVar16 = 0;
              pcVar22 = "[";
              cVar21 = s___001b722c[0];
              do {
                local_24[iVar16 + iVar13 + iVar12] = cVar21;
                iVar16 = iVar16 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
            }
            iVar17 = ((int (*)())FUN_0000b578)();
            if (s___001b7230[0] != '\0') {
              iVar25 = 0;
              pcVar22 = "]";
              cVar21 = s___001b7230[0];
              do {
                local_24[iVar25 + iVar17 + iVar16 + iVar13 + iVar12] = cVar21;
                iVar25 = iVar25 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
            }
            local_24 = (char *)((int (*)())FUN_0000b5df)((byte)*puVar14 >> 3 & 7);
            iVar12 = 0;
            if (*(int *)((int)local_154 + local_84 * 4) == 1) {
LAB_000107d5:
              local_84 = local_84 + 1;
              local_90 = -1;
              goto LAB_0000ea6c;
            }
          }
          else {
            iVar12 = local_90 + 1;
            if (local_90 + 2 == *(int *)((int)local_154 + local_84 * 4)) goto LAB_000107d5;
          }
          local_98 = local_98 + 1;
          local_90 = iVar12;
          if (uVar5 != local_98) goto LAB_0000ea82;
LAB_0000ec34:
          local_1b0 = local_24;
          if (s___001b74c4[0] == '\0') {
LAB_0001079c:
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = ";\n";
            cVar21 = s___001b74c4[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
LAB_0000ec6b:
            local_1b0 = local_24;
          }
          local_24 = local_1b0 + iVar12;
LAB_0000ec85:
          bVar7 = false;
        }
        if (s_tmp_001b7228[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "tmp";
          cVar21 = s_tmp_001b7228[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        ((int (*)())FUN_0000b578)();
        local_24 = (char *)((int (*)())FUN_0000b5df)((byte)*puVar14 >> 3 & 7);
      } while( true );
    }
    local_90 = -1;
    local_158 = (void *)0x0;
    local_15c = (void *)0x0;
  }
  if ((uVar5 != 0) && (bVar6)) {
    pcVar22 = "\n";
    if (s__001b7388[0] == '\0') {
      iVar12 = 0;
    }
    else {
      iVar12 = 0;
      cVar21 = s__001b7388[0];
      do {
        local_24[iVar12] = cVar21;
        iVar12 = iVar12 + 1;
        cVar21 = pcVar22[1];
        pcVar22 = pcVar22 + 1;
      } while (cVar21 != '\0');
    }
    local_24 = local_24 + iVar12;
  }
  uVar5 = param_1[8];
  puVar18 = param_1 + param_1[9] * 2;
  if (0 < (int)uVar5) {
    local_b0 = 0;
    do {
      bVar9 = *(byte *)((int)puVar18 + 1);
      if (bVar9 >> 4 == 0) goto LAB_0000d80a;
      if (s_ATTRIB_att_001b7500[0] == '\0') {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        pcVar22 = "ATTRIB att";
        cVar21 = s_ATTRIB_att_001b7500[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
      }
      iVar13 = ((int (*)())FUN_0000b578)();
      local_24 = local_24 + iVar13 + iVar12;
      if (bVar6) {
        local_24 = (char *)((int (*)())FUN_0000b5df)((byte)*puVar18 >> 3 & 7);
      }
      local_1b0 = local_24;
      if (uVar4 == 0x8804) {
LAB_0000e02d:
        if (s___fragment__001b7518[0] == '\0') {
LAB_0000e08f:
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = " = fragment.";
          cVar21 = s___fragment__001b7518[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
LAB_0000e091:
        local_24 = local_1b0 + iVar12;
      }
      else if (uVar4 < 0x8805) {
        if (uVar4 == 0x8620) {
LAB_0000e080:
          if (s___vertex__001b750c[0] == '\0') goto LAB_0000e08f;
          iVar12 = 0;
          pcVar22 = " = vertex.";
          cVar21 = s___vertex__001b750c[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto LAB_0000e091;
        }
      }
      else {
        if (uVar4 == 0x8b30) goto LAB_0000e02d;
        if (uVar4 == 0x8b31) goto LAB_0000e080;
      }
      local_1b0 = local_24;
      switch(bVar9 >> 4) {
      default:
        goto LAB_0000d7c4;
      case 1:
        if (s_position_001b7528[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "position";
          cVar21 = s_position_001b7528[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x0000ffc2;
        }
        break;
      case 2:
        if (s_color_primary_001b7534[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "color.primary";
          cVar21 = s_color_primary_001b7534[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x0000ffc2;
        }
        break;
      case 3:
        if (s_color_secondary_001b7544[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "color.secondary";
          cVar21 = s_color_secondary_001b7544[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x0000ffc2;
        }
        break;
      case 4:
        if (s_normal_001b7554[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "normal";
          cVar21 = s_normal_001b7554[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x0000ffc2;
        }
        break;
      case 5:
        if (s_fogcoord_001b755c[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "fogcoord";
          cVar21 = s_fogcoord_001b755c[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x0000ffc2;
        }
        break;
      case 6:
        if (s_weight__001b7580[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "weight[";
          cVar21 = s_weight__001b7580[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_1b0 = local_1b0 + iVar13 + iVar12;
        if (s___001b7230[0] == '\0') break;
        iVar12 = 0;
        pcVar22 = "]";
        cVar21 = s___001b7230[0];
        do {
          local_1b0[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
          local_24 = local_1b0;
        } while (cVar21 != '\0');
code_r0x00010067:
        local_1b0 = local_24;
        goto code_r0x0000d7b5;
      case 7:
        if (s_texcoord__001b7574[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "texcoord[";
          cVar21 = s_texcoord__001b7574[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_1b0 = local_1b0 + iVar13 + iVar12;
        if (s___001b7230[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "]";
          cVar21 = s___001b7230[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
            local_24 = local_1b0;
          } while (cVar21 != '\0');
          goto code_r0x00010067;
        }
        break;
      case 8:
        if (s_matrixindex__001b7588[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "matrixindex[";
          cVar21 = s_matrixindex__001b7588[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_1b0 = local_1b0 + iVar13 + iVar12;
        if (s___001b7230[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "]";
          cVar21 = s___001b7230[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
            local_24 = local_1b0;
          } while (cVar21 != '\0');
          goto code_r0x00010067;
        }
        break;
      case 9:
        if (s_attrib__001b7598[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "attrib[";
          cVar21 = s_attrib__001b7598[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_1b0 = local_1b0 + iVar13 + iVar12;
        if (s___001b7230[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "]";
          cVar21 = s___001b7230[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
            local_24 = local_1b0;
          } while (cVar21 != '\0');
          goto code_r0x00010067;
        }
        break;
      case 10:
        if (s_material__001b75a0[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "material.";
          cVar21 = s_material__001b75a0[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = local_1b0 + iVar12;
        if ((char)*(byte *)((int)puVar18 + 3) < '\0') {
          if ((char)*(byte *)((int)puVar18 + 3) < '\0') {
            if (s_back__001b75b4[0] == '\0') {
              iVar12 = 0;
            }
            else {
              iVar12 = 0;
              pcVar22 = "back.";
              cVar21 = s_back__001b75b4[0];
              do {
                local_24[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
            }
            local_24 = local_24 + iVar12;
          }
        }
        else {
          if (s_front__001b75ac[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "front.";
            cVar21 = s_front__001b75ac[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          local_24 = local_24 + iVar12;
        }
        local_1b0 = local_24;
        switch(*(byte *)((int)puVar18 + 2) & 0xf) {
        case 0:
          if (s_ambient_001b75bc[0] == '\0') goto code_r0x0000d7b3;
          iVar12 = 0;
          pcVar22 = "ambient";
          cVar21 = s_ambient_001b75bc[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        case 1:
          if (s_diffuse_001b75c4[0] == '\0') goto code_r0x0000d7b3;
          iVar12 = 0;
          pcVar22 = "diffuse";
          cVar21 = s_diffuse_001b75c4[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        case 2:
          if (s_specular_001b75cc[0] == '\0') goto code_r0x0000d7b3;
          iVar12 = 0;
          pcVar22 = "specular";
          cVar21 = s_specular_001b75cc[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        case 3:
          if (s_emission_001b75d8[0] == '\0') goto code_r0x0000d7b3;
          iVar12 = 0;
          pcVar22 = "emission";
          cVar21 = s_emission_001b75d8[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        case 4:
          if (s_shininess_001b75e4[0] == '\0') goto code_r0x0000d7b3;
          iVar12 = 0;
          pcVar22 = "shininess";
          cVar21 = s_shininess_001b75e4[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        default:
          goto LAB_0000d7c4;
        }
code_r0x0000ffc2:
        local_1b0 = local_24;
        goto code_r0x0000d7b5;
      case 0xb:
        if (s_frontfacing_001b7568[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "frontfacing";
          cVar21 = s_frontfacing_001b7568[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x0000ffc2;
        }
      }
code_r0x0000d7b3:
      iVar12 = 0;
code_r0x0000d7b5:
      local_24 = local_1b0 + iVar12;
LAB_0000d7c4:
      local_1b0 = local_24;
      if (s___001b74c4[0] == '\0') {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        pcVar22 = ";\n";
        cVar21 = s___001b74c4[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
      }
      local_24 = local_1b0 + iVar12;
      iVar12 = ((int (*)())FUN_0000b1ac)();
      if (iVar12 == 0) {
        if (local_15c != (void *)0x0) {
          _free(local_15c);
        }
        if (local_158 != (void *)0x0) {
          _free(local_158);
        }
        goto LAB_0000f848;
      }
LAB_0000d80a:
      local_b0 = local_b0 + 1;
      puVar18 = puVar18 + 2;
    } while (uVar5 != local_b0);
  }
  if ((uVar5 != 0) && (bVar6)) {
    pcVar22 = "\n";
    if (s__001b7388[0] == '\0') {
      iVar12 = 0;
    }
    else {
      iVar12 = 0;
      cVar21 = s__001b7388[0];
      do {
        local_24[iVar12] = cVar21;
        iVar12 = iVar12 + 1;
        cVar21 = pcVar22[1];
        pcVar22 = pcVar22 + 1;
      } while (cVar21 != '\0');
    }
    local_24 = local_24 + iVar12;
  }
  uVar5 = param_1[10];
  local_b8 = param_1 + param_1[0xb] * 2;
  if (uVar5 == 0) {
    local_164 = (void *)0x0;
    local_160 = (void *)0x0;
    goto LAB_0000d86f;
  }
  if ((int)uVar5 < 1) {
LAB_0000ed45:
    local_164 = (void *)0x0;
    local_160 = (void *)0x0;
  }
  else {
    uVar23 = 0;
    uVar24 = 0xffffffff;
    puVar18 = local_b8;
    do {
      if ((int)uVar24 < (int)(uint)*(ushort *)((int)puVar18 + 6)) {
        uVar24 = (uint)*(ushort *)((int)puVar18 + 6);
      }
      uVar23 = uVar23 + 1;
      puVar18 = puVar18 + 2;
    } while (uVar5 != uVar23);
    if (uVar24 == 0xffffffff) goto LAB_0000ed45;
    sVar2 = uVar24 * 4 + 4;
    local_164 = _malloc(sVar2);
    local_160 = _malloc(sVar2);
    if (local_164 == (void *)0x0) {
      if (local_160 != (void *)0x0) {
        _free(local_160);
      }
LAB_00012e8d:
      if (local_15c != (void *)0x0) {
        _free(local_15c);
      }
      if (local_158 != (void *)0x0) {
        _free(local_158);
      }
LAB_0000f848:
      _free(pvVar11);
      return (void *)0x0;
    }
    if (local_160 == (void *)0x0) {
      _free(local_164);
      goto LAB_00012e8d;
    }
  }
  if (param_1[0xe] == 0) {
    local_30 = (void *)0x0;
  }
  else {
    local_30 = _malloc(param_1[0xe] << 2);
  }
  if (0 < (int)uVar5) {
    local_168 = 0;
    uVar24 = 0;
    local_120 = -1;
    local_11c = 0xffffffff;
    local_118 = 0xffffffff;
    puVar18 = local_b8;
    do {
      if ((*puVar18 & 0xf800) != 0) {
        if (local_11c == 0xffffffff) {
          *(uint *)((int)local_164 + (uint)*(ushort *)((int)puVar18 + 6) * 4) =
               (uint)*(ushort *)((int)puVar18 + 6);
          local_11c = (uint)*(ushort *)((int)puVar18 + 6);
          uVar23 = param_1[0xe];
          puVar14 = param_1 + param_1[0xf] * 2;
          if ((uVar23 == 0) || ((int)uVar23 < 1)) {
LAB_0000e653:
            *(int *)((int)local_160 + local_11c * 4) = local_120;
            local_11c = 0xffffffff;
          }
          else {
            local_10c = puVar14;
            if (local_11c != *(ushort *)((int)puVar14 + 2)) {
              local_114 = 0;
              iVar12 = 8;
              do {
                local_114 = local_114 + 1;
                if (uVar23 == local_114) goto LAB_0000e653;
                local_10c = (uint *)((int)puVar14 + iVar12);
                iVar12 = iVar12 + 8;
              } while (local_11c != *(ushort *)((int)local_10c + 2));
            }
            local_118 = (uint)*(ushort *)((int)local_10c + 6);
            *(undefined4 *)((int)local_160 + local_11c * 4) = 0;
            local_120 = 1;
          }
          if (*(ushort *)((int)puVar18 + 6) == local_118) {
            *(int *)((int)local_30 + local_168 * 4) = local_120;
            local_168 = local_168 + 1;
            local_120 = -1;
            local_11c = 0xffffffff;
            local_118 = 0xffffffff;
          }
        }
        else if ((int)(uint)*(ushort *)((int)puVar18 + 6) <= (int)local_118) {
          *(uint *)((int)local_164 + (uint)*(ushort *)((int)puVar18 + 6) * 4) = local_11c;
          *(int *)((int)local_160 + (uint)*(ushort *)((int)puVar18 + 6) * 4) = local_120;
          local_120 = local_120 + 1;
          if (*(ushort *)((int)puVar18 + 6) == local_118) {
            *(int *)((int)local_30 + local_168 * 4) = local_120;
            local_168 = local_168 + 1;
            local_120 = -1;
            local_11c = 0xffffffff;
            local_118 = 0xffffffff;
          }
        }
      }
      uVar24 = uVar24 + 1;
      puVar18 = puVar18 + 2;
    } while (uVar5 != uVar24);
    local_8c = 0;
    local_ac = 0;
    do {
      bVar9 = *(byte *)((int)local_b8 + 1) >> 3;
      if (*(byte *)((int)local_b8 + 1) >> 3 == 0) goto LAB_0001052c;
      iVar12 = *(int *)((int)local_160 + (uint)*(ushort *)((int)local_b8 + 6) * 4);
      if (iVar12 == -1) {
        if (s_PARAM_prm_001b75f0[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "PARAM prm";
          cVar21 = s_PARAM_prm_001b75f0[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_24 = local_24 + iVar13 + iVar12;
        if (bVar6) {
          local_24 = (char *)((int (*)())FUN_0000b5df)((byte)*local_b8 >> 3 & 7);
        }
        local_1b0 = local_24;
        if (s___001b75fc[0] != '\0') {
          iVar12 = 0;
          pcVar22 = " = ";
          cVar21 = s___001b75fc[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto LAB_00010ca4;
        }
LAB_00010cb1:
        iVar12 = 0;
LAB_00010cb3:
        local_24 = local_1b0 + iVar12;
      }
      else {
        if (iVar12 != 0) {
          local_90 = local_90 + 1;
          local_1b0 = local_24;
          if (s__001b760c[0] == '\0') goto LAB_00010cb1;
          iVar12 = 0;
          pcVar22 = "    ";
          cVar21 = s__001b760c[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
LAB_00010ca4:
          local_1b0 = local_24;
          goto LAB_00010cb3;
        }
        if (s_PARAM_prm_001b75f0[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "PARAM prm";
          cVar21 = s_PARAM_prm_001b75f0[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        if (s___001b722c[0] == '\0') {
          iVar16 = 0;
        }
        else {
          iVar16 = 0;
          pcVar22 = "[";
          cVar21 = s___001b722c[0];
          do {
            local_24[iVar16 + iVar13 + iVar12] = cVar21;
            iVar16 = iVar16 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar17 = ((int (*)())FUN_0000b578)();
        iVar17 = iVar17 + iVar16 + iVar13 + iVar12;
        if (s___001b7230[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "]";
          cVar21 = s___001b7230[0];
          do {
            local_24[iVar12 + iVar17] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = local_24 + iVar12 + iVar17;
        if (bVar6) {
          local_24 = (char *)((int (*)())FUN_0000b5df)((byte)*local_b8 >> 3 & 7);
        }
        local_1b0 = local_24;
        if (s_____001b7600[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = " = {\n    ";
          cVar21 = s_____001b7600[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = local_1b0 + iVar12;
        local_90 = 0;
      }
      local_1b0 = local_24;
      if (bVar9 != 0) {
        if (bVar9 < 3) {
          if (s_program__001b7614[0] == '\0') goto LAB_00010c34;
          iVar12 = 0;
          pcVar22 = "program.";
          cVar21 = s_program__001b7614[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto LAB_00010af5;
        }
        if (bVar9 != 0x11) goto LAB_00010ac7;
        if (s__001b7620[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "";
          acVar3 = s__001b7620[0];
          do {
            local_24[iVar12] = acVar3;
            iVar12 = iVar12 + 1;
            acVar3 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (acVar3 != '\0');
        }
        local_24 = local_1b0 + iVar12;
code_r0x00010be7:
        pfVar1 = (float *)(param_1 + param_1[0x1b] * 2 + (uint)*(ushort *)((int)local_b8 + 2) * 4);
        local_1b0 = local_24;
        switch((byte)*local_b8 >> 3 & 7) {
        case 0:
        case 1:
          if (s___001b77a8[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "{";
            cVar21 = s___001b77a8[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          iVar12 = ((char * (*)())FUN_0000aa2a)((double)*pfVar1,local_1b0 + iVar12,
                                (int)pvVar11 + (0x800 - (int)(local_1b0 + iVar12)),0x9abcaf48,
                                0x3e7ad7f2);
          cVar21 = s___001b72bc[0];
          pcVar22 = ", ";
          if (s___001b72bc[0] == '\0') {
            iVar13 = 0;
          }
          else {
            iVar13 = 0;
            pcVar19 = pcVar22;
            cVar20 = s___001b72bc[0];
            do {
              *(char *)(iVar12 + iVar13) = cVar20;
              iVar13 = iVar13 + 1;
              cVar20 = pcVar19[1];
              pcVar19 = pcVar19 + 1;
            } while (cVar20 != '\0');
          }
          iVar12 = ((char * (*)())FUN_0000aa2a)((double)pfVar1[1],iVar13 + iVar12,
                                (int)pvVar11 + (0x800 - (iVar13 + iVar12)),0x9abcaf48,0x3e7ad7f2);
          if (cVar21 == '\0') {
            iVar13 = 0;
          }
          else {
            iVar13 = 0;
            pcVar19 = pcVar22;
            cVar20 = cVar21;
            do {
              *(char *)(iVar12 + iVar13) = cVar20;
              iVar13 = iVar13 + 1;
              cVar20 = pcVar19[1];
              pcVar19 = pcVar19 + 1;
            } while (cVar20 != '\0');
          }
          iVar12 = ((char * (*)())FUN_0000aa2a)((double)pfVar1[2],iVar13 + iVar12,
                                (int)pvVar11 + (0x800 - (iVar13 + iVar12)),0x9abcaf48,0x3e7ad7f2);
          if (cVar21 == '\0') {
            iVar13 = 0;
          }
          else {
            iVar13 = 0;
            do {
              *(char *)(iVar12 + iVar13) = cVar21;
              iVar13 = iVar13 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          iVar12 = ((char * (*)())FUN_0000aa2a)((double)pfVar1[3],iVar13 + iVar12,
                                (int)pvVar11 + (0x800 - (iVar13 + iVar12)),0x9abcaf48,0x3e7ad7f2);
          if (s___001b77ac[0] == '\0') {
            iVar13 = 0;
          }
          else {
            iVar13 = 0;
            pcVar22 = "}";
            cVar21 = s___001b77ac[0];
            do {
              *(char *)(iVar12 + iVar13) = cVar21;
              iVar13 = iVar13 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          local_24 = (char *)(iVar13 + iVar12);
          break;
        case 2:
          if (s_____Fixed_constant_data_not_curr_001b77b0[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "{-- Fixed constant data not currently supported --}";
            cVar21 = s_____Fixed_constant_data_not_curr_001b77b0[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x00011df9;
          }
          goto code_r0x0001253f;
        case 3:
        case 4:
          if (s___001b77a8[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "{";
            cVar21 = s___001b77a8[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          iVar13 = ((int (*)())FUN_0000b578)();
          cVar21 = s___001b72bc[0];
          pcVar22 = ", ";
          if (s___001b72bc[0] == '\0') {
            iVar16 = 0;
          }
          else {
            iVar16 = 0;
            pcVar19 = pcVar22;
            cVar20 = s___001b72bc[0];
            do {
              local_1b0[iVar16 + iVar13 + iVar12] = cVar20;
              iVar16 = iVar16 + 1;
              cVar20 = pcVar19[1];
              pcVar19 = pcVar19 + 1;
            } while (cVar20 != '\0');
          }
          iVar17 = ((int (*)())FUN_0000b578)();
          iVar17 = iVar17 + iVar16 + iVar13 + iVar12;
          if (cVar21 == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar19 = pcVar22;
            cVar20 = cVar21;
            do {
              local_1b0[iVar12 + iVar17] = cVar20;
              iVar12 = iVar12 + 1;
              cVar20 = pcVar19[1];
              pcVar19 = pcVar19 + 1;
            } while (cVar20 != '\0');
          }
          iVar13 = ((int (*)())FUN_0000b578)();
          iVar13 = iVar13 + iVar12 + iVar17;
          if (cVar21 == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            do {
              local_1b0[iVar12 + iVar13] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          iVar16 = ((int (*)())FUN_0000b578)();
          iVar16 = iVar16 + iVar12 + iVar13;
          if (s___001b77ac[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "}";
            cVar21 = s___001b77ac[0];
            do {
              local_1b0[iVar12 + iVar16] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          local_24 = local_1b0 + iVar12 + iVar16;
        }
        goto LAB_000104b1;
      }
LAB_00010ac7:
      if (s_state__001b7624[0] == '\0') {
LAB_00010c34:
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        pcVar22 = "state.";
        cVar21 = s_state__001b7624[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
LAB_00010af5: ;
      }
      local_1b0 = local_1b0 + iVar12;
      local_24 = local_1b0;
      switch(bVar9) {
      default:
        goto LAB_000104b1;
      case 1:
        if (s_local__001b762c[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "local[";
          cVar21 = s_local__001b762c[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_1b0 = local_1b0 + iVar13 + iVar12;
        if (s___001b7230[0] == '\0') break;
        iVar12 = 0;
        pcVar22 = "]";
        cVar21 = s___001b7230[0];
        do {
          local_1b0[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
          local_24 = local_1b0;
        } while (cVar21 != '\0');
        goto code_r0x00011e7b;
      case 2:
        if (s_env__001b7634[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "env[";
          cVar21 = s_env__001b7634[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_1b0 = local_1b0 + iVar13 + iVar12;
        if (s___001b7230[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "]";
          cVar21 = s___001b7230[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
            local_24 = local_1b0;
          } while (cVar21 != '\0');
          goto code_r0x00011e7b;
        }
        break;
      case 3:
        if (s_light__001b763c[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "light[";
          cVar21 = s_light__001b763c[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        if (s____001b7644[0] == '\0') {
          iVar16 = 0;
        }
        else {
          iVar16 = 0;
          pcVar22 = "].";
          cVar21 = s____001b7644[0];
          do {
            local_1b0[iVar16 + iVar13 + iVar12] = cVar21;
            iVar16 = iVar16 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_1b0 = local_1b0 + iVar16 + iVar13 + iVar12;
        local_24 = local_1b0;
        switch(*(byte *)((int)local_b8 + 2) >> 4) {
        case 0:
          if (s_ambient_001b75bc[0] == '\0') break;
          iVar12 = 0;
          pcVar22 = "ambient";
          cVar21 = s_ambient_001b75bc[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
code_r0x00011df9:
          local_1b0 = local_24;
          goto code_r0x00011e04;
        case 1:
          if (s_diffuse_001b75c4[0] == '\0') goto code_r0x00013044;
          iVar12 = 0;
          pcVar22 = "diffuse";
          cVar21 = s_diffuse_001b75c4[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
code_r0x00012221:
          local_1b0 = local_24;
          goto code_r0x0001222c;
        case 2:
          if (s_specular_001b75cc[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "specular";
            cVar21 = s_specular_001b75cc[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x00011df9;
          }
          break;
        case 3:
          if (s_position_001b7528[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "position";
            cVar21 = s_position_001b7528[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x00012221;
          }
          goto code_r0x00013044;
        case 4:
          if (s_spot_direction_001b7648[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "spot.direction";
            cVar21 = s_spot_direction_001b7648[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x00011df9;
          }
          break;
        case 5:
          if (s_attenuation_001b7658[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "attenuation";
            cVar21 = s_attenuation_001b7658[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x00012221;
          }
          goto code_r0x00013044;
        case 6:
          if (s_half_001b7664[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "half";
            cVar21 = s_half_001b7664[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x00011df9;
          }
          break;
        case 7:
          if (s_spotcutoff_001b766c[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "spotcutoff";
            cVar21 = s_spotcutoff_001b766c[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x00012221;
          }
code_r0x00013044:
          iVar12 = 0;
code_r0x0001222c:
          local_24 = local_1b0 + iVar12;
        default:
          goto LAB_000104b1;
        }
code_r0x0001253f:
        iVar12 = 0;
code_r0x00011e04:
        local_24 = local_1b0 + iVar12;
        goto LAB_000104b1;
      case 4:
        if (s_lightprod__001b7678[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "lightprod[";
          cVar21 = s_lightprod__001b7678[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        if (s____001b7644[0] == '\0') {
          iVar16 = 0;
        }
        else {
          iVar16 = 0;
          pcVar22 = "].";
          cVar21 = s____001b7644[0];
          do {
            local_1b0[iVar16 + iVar13 + iVar12] = cVar21;
            iVar16 = iVar16 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = local_1b0 + iVar16 + iVar13 + iVar12;
        bVar9 = *(byte *)((int)local_b8 + 2);
        if ((char)bVar9 < '\0') {
          if ((char)bVar9 < '\0') {
            if (s_back__001b75b4[0] == '\0') goto code_r0x0001369c;
            iVar12 = 0;
            pcVar22 = "back.";
            cVar21 = s_back__001b75b4[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            bVar9 = *(byte *)((int)local_b8 + 2);
            goto code_r0x000133f4;
          }
        }
        else {
          if (s_front__001b75ac[0] == '\0') {
code_r0x0001369c:
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "front.";
            cVar21 = s_front__001b75ac[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            bVar9 = *(byte *)((int)local_b8 + 2);
          }
code_r0x000133f4:
          local_24 = local_24 + iVar12;
        }
        bVar8 = bVar9 >> 5 & 3;
        local_1b0 = local_24;
        if (bVar8 != 1) {
          if (bVar8 == 2) {
            if (s_specular_001b75cc[0] != '\0') {
              iVar12 = 0;
              pcVar22 = "specular";
              cVar21 = s_specular_001b75cc[0];
              do {
                local_24[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
              goto code_r0x000120e6;
            }
            break;
          }
          if ((bVar9 >> 5 & 3) == 0) {
            if (s_ambient_001b75bc[0] != '\0') {
              iVar12 = 0;
              pcVar22 = "ambient";
              cVar21 = s_ambient_001b75bc[0];
              do {
                local_24[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
              goto code_r0x00011df9;
            }
            goto code_r0x0001253f;
          }
          goto LAB_000104b1;
        }
        if (s_diffuse_001b75c4[0] == '\0') break;
        iVar12 = 0;
        pcVar22 = "diffuse";
        cVar21 = s_diffuse_001b75c4[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
code_r0x000120e6:
        local_1b0 = local_24;
        goto code_r0x000120f1;
      case 5:
        bVar9 = *(byte *)((int)local_b8 + 3);
        if ((bVar9 >> 4 & 7) == 5) {
          if (s_lightmodel__001b7698[0] == '\0') goto code_r0x00011ff0;
          iVar12 = 0;
          pcVar22 = "lightmodel.";
          cVar21 = s_lightmodel__001b7698[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          bVar9 = *(byte *)((int)local_b8 + 3);
        }
        else if (s_material__001b75a0[0] == '\0') {
code_r0x00011ff0:
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "material.";
          cVar21 = s_material__001b75a0[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          bVar9 = *(byte *)((int)local_b8 + 3);
        }
        local_24 = local_1b0 + iVar12;
        if ((char)bVar9 < '\0') {
          if ((char)bVar9 < '\0') {
            if (s_back__001b75b4[0] == '\0') goto code_r0x00013871;
            iVar12 = 0;
            pcVar22 = "back.";
            cVar21 = s_back__001b75b4[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
code_r0x00013158:
            bVar9 = *(byte *)((int)local_b8 + 3);
            goto code_r0x0001316d;
          }
        }
        else {
          if (s_front__001b75ac[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "front.";
            cVar21 = s_front__001b75ac[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x00013158;
          }
code_r0x00013871:
          iVar12 = 0;
code_r0x0001316d:
          local_24 = local_24 + iVar12;
        }
        local_1b0 = local_24;
        switch(bVar9 >> 4 & 7) {
        case 0:
          if (s_ambient_001b75bc[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "ambient";
            cVar21 = s_ambient_001b75bc[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x00011df9;
          }
          goto code_r0x0001253f;
        case 1:
          if (s_diffuse_001b75c4[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "diffuse";
            cVar21 = s_diffuse_001b75c4[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000120e6;
          }
          break;
        case 2:
          if (s_specular_001b75cc[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "specular";
            cVar21 = s_specular_001b75cc[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000120e6;
          }
          break;
        case 3:
          if (s_emission_001b75d8[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "emission";
            cVar21 = s_emission_001b75d8[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000120e6;
          }
          break;
        case 4:
          if (s_shininess_001b75e4[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "shininess";
            cVar21 = s_shininess_001b75e4[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000120e6;
          }
          break;
        case 5:
          if (s_scenecolor_001b76a4[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "scenecolor";
            cVar21 = s_scenecolor_001b76a4[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000120e6;
          }
          break;
        default:
          goto LAB_000104b1;
        }
        break;
      case 6:
        if (s_lightmodel_ambient_001b7684[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "lightmodel.ambient";
          cVar21 = s_lightmodel_ambient_001b7684[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x000120e6;
        }
        break;
      case 7:
        if (s_texgen__001b76b0[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "texgen[";
          cVar21 = s_texgen__001b76b0[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        if (s___eye__001b76b8[0] == '\0') {
          iVar16 = 0;
        }
        else {
          iVar16 = 0;
          pcVar22 = "].eye.";
          cVar21 = s___eye__001b76b8[0];
          do {
            local_1b0[iVar16 + iVar13 + iVar12] = cVar21;
            iVar16 = iVar16 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_1b0 = local_1b0 + iVar16 + iVar13 + iVar12;
        bVar9 = *(byte *)((int)local_b8 + 3) & 7;
        local_24 = local_1b0;
        if (bVar9 == 1) {
          if (s_t_001b76c4[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "t";
            cVar21 = s_t_001b76c4[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x00012221;
          }
          goto code_r0x00013044;
        }
        if (bVar9 < 2) {
          if (bVar9 == 0) {
            if (s_s_001b76c0[0] != '\0') {
              iVar12 = 0;
              pcVar22 = "s";
              cVar21 = s_s_001b76c0[0];
              do {
                local_1b0[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
              goto code_r0x00011df9;
            }
            goto code_r0x0001253f;
          }
        }
        else {
          if (bVar9 == 2) {
            if (s_r_001b76c8[0] != '\0') {
              iVar12 = 0;
              pcVar22 = "r";
              cVar21 = s_r_001b76c8[0];
              do {
                local_1b0[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
              goto code_r0x00011df9;
            }
            goto code_r0x0001253f;
          }
          if (bVar9 == 3) {
            if (s_q_001b76cc[0] != '\0') {
              iVar12 = 0;
              pcVar22 = "q";
              cVar21 = s_q_001b76cc[0];
              do {
                local_1b0[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
              goto code_r0x00012221;
            }
            goto code_r0x00013044;
          }
        }
        goto LAB_000104b1;
      case 8:
        if (s_texgen__001b76b0[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "texgen[";
          cVar21 = s_texgen__001b76b0[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        if (s___object__001b76d0[0] == '\0') {
          iVar16 = 0;
        }
        else {
          iVar16 = 0;
          pcVar22 = "].object.";
          cVar21 = s___object__001b76d0[0];
          do {
            local_1b0[iVar16 + iVar13 + iVar12] = cVar21;
            iVar16 = iVar16 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_1b0 = local_1b0 + iVar16 + iVar13 + iVar12;
        bVar9 = *(byte *)((int)local_b8 + 3) & 7;
        local_24 = local_1b0;
        if (bVar9 == 1) {
          if (s_t_001b76c4[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "t";
            cVar21 = s_t_001b76c4[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x00012221;
          }
          goto code_r0x00013044;
        }
        if (bVar9 < 2) {
          if (bVar9 == 0) {
            if (s_s_001b76c0[0] != '\0') {
              iVar12 = 0;
              pcVar22 = "s";
              cVar21 = s_s_001b76c0[0];
              do {
                local_1b0[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
              goto code_r0x00011df9;
            }
            goto code_r0x0001253f;
          }
        }
        else {
          if (bVar9 == 2) {
            if (s_r_001b76c8[0] != '\0') {
              iVar12 = 0;
              pcVar22 = "r";
              cVar21 = s_r_001b76c8[0];
              do {
                local_1b0[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
              goto code_r0x00011df9;
            }
            goto code_r0x0001253f;
          }
          if (bVar9 == 3) {
            if (s_q_001b76cc[0] != '\0') {
              iVar12 = 0;
              pcVar22 = "q";
              cVar21 = s_q_001b76cc[0];
              do {
                local_1b0[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
              goto code_r0x00012221;
            }
            goto code_r0x00013044;
          }
        }
        goto LAB_000104b1;
      case 9:
        if (s_texenv__001b76dc[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "texenv[";
          cVar21 = s_texenv__001b76dc[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_1b0 = local_1b0 + iVar13 + iVar12;
        if (s___color_001b76e4[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "].color";
          cVar21 = s___color_001b76e4[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
            local_24 = local_1b0;
          } while (cVar21 != '\0');
          goto code_r0x00011e7b;
        }
        break;
      case 10:
        if (s_clip__001b76ec[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "clip[";
          cVar21 = s_clip__001b76ec[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_1b0 = local_1b0 + iVar13 + iVar12;
        if (s___plane_001b76f4[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "].plane";
          cVar21 = s___plane_001b76f4[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
            local_24 = local_1b0;
          } while (cVar21 != '\0');
          goto code_r0x00011e7b;
        }
        break;
      case 0xb:
        if (s_fog_color_001b76fc[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "fog.color";
          cVar21 = s_fog_color_001b76fc[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x000120e6;
        }
        break;
      case 0xc:
        if (s_fog_params_001b7708[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "fog.params";
          cVar21 = s_fog_params_001b7708[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x000120e6;
        }
        break;
      case 0xd:
        if (s_point_size_001b7720[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "point.size";
          cVar21 = s_point_size_001b7720[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x000120e6;
        }
        break;
      case 0xe:
        if (s_point_attenuation_001b772c[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "point.attenuation";
          cVar21 = s_point_attenuation_001b772c[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x000120e6;
        }
        break;
      case 0xf:
        if (s_depth_range_001b7714[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "depth.range";
          cVar21 = s_depth_range_001b7714[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x000120e6;
        }
        break;
      case 0x10:
        if (s_matrix__001b7740[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "matrix.";
          cVar21 = s_matrix__001b7740[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = local_1b0 + iVar12;
        bVar9 = *(byte *)((int)local_b8 + 2);
        switch(bVar9 >> 5) {
        case 0:
          if (s_mvp__001b7754[0] == '\0') {
code_r0x00013af2:
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "mvp.";
            cVar21 = s_mvp__001b7754[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            bVar9 = *(byte *)((int)local_b8 + 2);
          }
          goto code_r0x00013af4;
        case 1:
          if (s_projection__001b7748[0] == '\0') goto code_r0x00013af2;
          iVar12 = 0;
          pcVar22 = "projection.";
          cVar21 = s_projection__001b7748[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          bVar9 = *(byte *)((int)local_b8 + 2);
code_r0x00013af4:
          local_24 = local_24 + iVar12;
          break;
        case 2:
          if (s_color__001b775c[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "color[";
            cVar21 = s_color__001b775c[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          iVar13 = ((int (*)())FUN_0000b578)();
          local_1b0 = local_24 + iVar13 + iVar12;
          if (s____001b7644[0] == '\0') goto code_r0x00013cb2;
          iVar12 = 0;
          pcVar22 = "].";
          cVar21 = s____001b7644[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
            local_24 = local_1b0;
          } while (cVar21 != '\0');
code_r0x00013bd6:
          local_1b0 = local_24;
          goto code_r0x00013be1;
        case 3:
          if (s_modelview__001b7764[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "modelview[";
            cVar21 = s_modelview__001b7764[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          iVar13 = ((int (*)())FUN_0000b578)();
          if (s____001b7644[0] == '\0') {
            iVar16 = 0;
          }
          else {
            iVar16 = 0;
            pcVar22 = "].";
            cVar21 = s____001b7644[0];
            do {
              local_24[iVar16 + iVar13 + iVar12] = cVar21;
              iVar16 = iVar16 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          local_24 = local_24 + iVar16 + iVar13 + iVar12;
          bVar9 = *(byte *)((int)local_b8 + 2);
          break;
        case 4:
          if (s_texture__001b72dc[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "texture[";
            cVar21 = s_texture__001b72dc[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          iVar13 = ((int (*)())FUN_0000b578)();
          if (s____001b7644[0] == '\0') {
            iVar16 = 0;
          }
          else {
            iVar16 = 0;
            pcVar22 = "].";
            cVar21 = s____001b7644[0];
            do {
              local_24[iVar16 + iVar13 + iVar12] = cVar21;
              iVar16 = iVar16 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          local_24 = local_24 + iVar16 + iVar13 + iVar12;
          bVar9 = *(byte *)((int)local_b8 + 2);
          break;
        case 5:
          if (s_program__001b7770[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "program[";
            cVar21 = s_program__001b7770[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          iVar13 = ((int (*)())FUN_0000b578)();
          local_1b0 = local_24 + iVar13 + iVar12;
          if (s____001b7644[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "].";
            cVar21 = s____001b7644[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
              local_24 = local_1b0;
            } while (cVar21 != '\0');
            goto code_r0x00013bd6;
          }
code_r0x00013cb2:
          iVar12 = 0;
code_r0x00013be1:
          local_24 = local_1b0 + iVar12;
          bVar9 = *(byte *)((int)local_b8 + 2);
        }
        bVar9 = bVar9 & 3;
        if (bVar9 == 2) {
          if (s_inverse__001b7788[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "inverse.";
            cVar21 = s_inverse__001b7788[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000136cd;
          }
code_r0x00013706:
          iVar12 = 0;
          local_1b0 = local_24;
code_r0x00013708:
          local_24 = local_1b0 + iVar12;
        }
        else {
          if (bVar9 == 3) {
            if (s_invtrans__001b7794[0] == '\0') goto code_r0x00013706;
            iVar12 = 0;
            pcVar22 = "invtrans.";
            cVar21 = s_invtrans__001b7794[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
code_r0x000136cd:
            local_1b0 = local_24;
            goto code_r0x00013708;
          }
          if (bVar9 == 1) {
            if (s_transpose__001b777c[0] == '\0') goto code_r0x00013706;
            iVar12 = 0;
            pcVar22 = "transpose.";
            cVar21 = s_transpose__001b777c[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000136cd;
          }
        }
        local_1b0 = local_24;
        if (s_row__001b77a0[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "row[";
          cVar21 = s_row__001b77a0[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_1b0 = local_1b0 + iVar13 + iVar12;
        if (s___001b7230[0] == '\0') break;
        iVar12 = 0;
        pcVar22 = "]";
        cVar21 = s___001b7230[0];
        do {
          local_1b0[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
          local_24 = local_1b0;
        } while (cVar21 != '\0');
code_r0x00011e7b:
        local_1b0 = local_24;
        goto code_r0x000120f1;
      case 0x11:
        goto code_r0x00010be7;
      case 0x12:
        if (s_normalscale_001b77e4[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "normalscale";
          cVar21 = s_normalscale_001b77e4[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x00011df9;
        }
        goto code_r0x0001253f;
      }
      iVar12 = 0;
code_r0x000120f1:
      local_24 = local_1b0 + iVar12;
LAB_000104b1:
      local_1b0 = local_24;
      if (*(int *)((int)local_160 + (uint)*(ushort *)((int)local_b8 + 6) * 4) == -1) {
        if (s___001b74c4[0] == '\0') goto LAB_000104f5;
        iVar12 = 0;
        pcVar22 = ";\n";
        cVar21 = s___001b74c4[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
LAB_00010b8f: ;
      }
      else {
        if (local_90 + 1 == *(int *)((int)local_30 + local_8c * 4)) {
          local_8c = local_8c + 1;
          if (s____001b77f0[0] == '\0') goto LAB_000104f5;
          iVar12 = 0;
          pcVar22 = "\n};\n";
          cVar21 = s____001b77f0[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto LAB_00010b8f;
        }
        if (s___001b77f8[0] != '\0') {
          iVar12 = 0;
          pcVar22 = ",\n";
          cVar21 = s___001b77f8[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto LAB_00010b8f;
        }
LAB_000104f5:
        iVar12 = 0;
      }
      local_24 = local_1b0 + iVar12;
      iVar12 = ((int (*)())FUN_0000b1ac)();
      if (iVar12 == 0) {
        if (local_164 != (void *)0x0) {
          _free(local_164);
        }
        if (local_160 != (void *)0x0) {
          _free(local_160);
        }
        if (local_15c != (void *)0x0) {
          _free(local_15c);
        }
        if (local_158 != (void *)0x0) {
          _free(local_158);
        }
        goto LAB_0000f848;
      }
LAB_0001052c:
      local_ac = local_ac + 1;
      local_b8 = local_b8 + 2;
    } while (uVar5 != local_ac);
  }
  if (local_30 != (void *)0x0) {
    _free(local_30);
  }
  pcVar22 = "\n";
  if (s__001b7388[0] == '\0') {
    iVar12 = 0;
  }
  else {
    iVar12 = 0;
    cVar21 = s__001b7388[0];
    do {
      local_24[iVar12] = cVar21;
      iVar12 = iVar12 + 1;
      cVar21 = pcVar22[1];
      pcVar22 = pcVar22 + 1;
    } while (cVar21 != '\0');
  }
  local_24 = local_24 + iVar12;
LAB_0000d86f:
  uVar5 = param_1[0xc];
  puVar18 = param_1 + param_1[0xd] * 2;
  if (0 < (int)uVar5) {
    local_a8 = 0;
    do {
      bVar9 = *(byte *)((int)puVar18 + 1);
      if (bVar9 >> 4 == 0) goto LAB_0000d991;
      bVar8 = (byte)*puVar18 & 7;
      if (bVar8 == 1) {
        if (s_LONG_OUTPUT_res_001b7808[0] == '\0') {
LAB_0000e3aa:
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "LONG OUTPUT res";
          cVar21 = s_LONG_OUTPUT_res_001b7808[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
LAB_0000e3ac:
        local_24 = local_24 + iVar12;
      }
      else {
        if (bVar8 == 2) {
          if (s_SHORT_OUTPUT_res_001b7818[0] == '\0') goto LAB_0000e3aa;
          iVar12 = 0;
          pcVar22 = "SHORT OUTPUT res";
          cVar21 = s_SHORT_OUTPUT_res_001b7818[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto LAB_0000e3ac;
        }
        if (bVar8 == 0) {
          if (s_OUTPUT_res_001b77fc[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            local_1c8 = "OUTPUT res";
            cVar21 = s_OUTPUT_res_001b77fc[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = local_1c8[1];
              local_1c8 = local_1c8 + 1;
            } while (cVar21 != '\0');
          }
          local_24 = local_24 + iVar12;
        }
      }
      iVar12 = ((int (*)())FUN_0000b578)();
      local_24 = local_24 + iVar12;
      if (bVar6) {
        local_24 = (char *)((int (*)())FUN_0000b5df)((byte)*puVar18 >> 3 & 7);
      }
      local_1b0 = local_24;
      if (s___001b75fc[0] == '\0') {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        pcVar22 = " = ";
        cVar21 = s___001b75fc[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
      }
      local_1b0 = local_1b0 + iVar12;
      local_24 = local_1b0;
      switch(bVar9 >> 4) {
      case 1:
        if (s_result_position_001b782c[0] == '\0') {
code_r0x0000d93a:
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "result.position";
          cVar21 = s_result_position_001b782c[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        goto code_r0x0000d93c;
      case 2:
        if (s_result_fogcoord_001b783c[0] == '\0') goto code_r0x00011990;
        iVar12 = 0;
        pcVar22 = "result.fogcoord";
        cVar21 = s_result_fogcoord_001b783c[0];
        do {
          local_1b0[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
code_r0x00011419:
        local_1b0 = local_24;
        goto code_r0x00011992;
      case 3:
        if (s_result_pointsize_001b784c[0] == '\0') goto code_r0x0000d93a;
        iVar12 = 0;
        pcVar22 = "result.pointsize";
        cVar21 = s_result_pointsize_001b784c[0];
        do {
          local_1b0[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
        goto code_r0x0000d93c;
      case 4:
        if (s_result_color_001b7860[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "result.color";
          cVar21 = s_result_color_001b7860[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_1b0 = local_1b0 + iVar12;
        local_24 = local_1b0;
        if ((uVar4 == 0x8620) || (uVar4 == 0x8b31)) {
          if (-1 < (char)*(byte *)((int)puVar18 + 3)) {
            if (s__front_primary_001b7870[0] == '\0') goto code_r0x00011990;
            iVar12 = 0;
            pcVar22 = ".front.primary";
            cVar21 = s__front_primary_001b7870[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
code_r0x000115da:
            local_1b0 = local_24;
            goto code_r0x00011992;
          }
          if ((char)*(byte *)((int)puVar18 + 3) < '\0') {
            if (s__back_primary_001b7880[0] != '\0') {
              iVar12 = 0;
              pcVar22 = ".back.primary";
              cVar21 = s__back_primary_001b7880[0];
              do {
                local_1b0[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
              goto code_r0x00012bd2;
            }
            goto code_r0x0000d93a;
          }
        }
        else if (((uVar4 == 0x8804) || (uVar4 == 0x8b30)) &&
                (1 < (*(byte *)((int)puVar18 + 3) >> 4 & 7))) {
          if (s___001b722c[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "[";
            cVar21 = s___001b722c[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          iVar13 = ((int (*)())FUN_0000b578)();
          local_1b0 = local_1b0 + iVar13 + iVar12;
          if (s___001b7230[0] != '\0') {
            iVar12 = 0;
            pcVar22 = "]";
            cVar21 = s___001b7230[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
              local_24 = local_1b0;
            } while (cVar21 != '\0');
            goto code_r0x00011419;
          }
          goto code_r0x00011990;
        }
        break;
      case 5:
        if (s_result_color_001b7860[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "result.color";
          cVar21 = s_result_color_001b7860[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_1b0 = local_1b0 + iVar12;
        local_24 = local_1b0;
        if ((uVar4 == 0x8620) || (uVar4 == 0x8b31)) {
          if (-1 < (char)*(byte *)((int)puVar18 + 3)) {
            if (s__front_secondary_001b7890[0] == '\0') goto code_r0x0000d93a;
            iVar12 = 0;
            pcVar22 = ".front.secondary";
            cVar21 = s__front_secondary_001b7890[0];
            do {
              local_1b0[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
code_r0x00012bd2:
            local_1b0 = local_24;
            goto code_r0x0000d93c;
          }
          if ((char)*(byte *)((int)puVar18 + 3) < '\0') {
            if (s__back_secondary_001b78a4[0] != '\0') {
              iVar12 = 0;
              pcVar22 = ".back.secondary";
              cVar21 = s__back_secondary_001b78a4[0];
              do {
                local_1b0[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
              goto code_r0x000115da;
            }
            goto code_r0x00011990;
          }
        }
        break;
      case 6:
        if (s_result_texcoord__001b78b4[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "result.texcoord[";
          cVar21 = s_result_texcoord__001b78b4[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_1b0 = local_1b0 + iVar13 + iVar12;
        if (s___001b7230[0] == '\0') goto code_r0x000119a6;
        iVar12 = 0;
        pcVar22 = "]";
        cVar21 = s___001b7230[0];
        do {
          local_1b0[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
          local_24 = local_1b0;
        } while (cVar21 != '\0');
code_r0x00011548:
        local_1b0 = local_24;
        goto code_r0x000119a8;
      case 7:
        if (s_result_depth_001b78c8[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "result.depth";
          cVar21 = s_result_depth_001b78c8[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x00011419;
        }
        goto code_r0x00011990;
      case 8:
        if (s_result_eyePosition_001b78e8[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "result.eyePosition";
          cVar21 = s_result_eyePosition_001b78e8[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          goto code_r0x00011419;
        }
code_r0x00011990:
        iVar12 = 0;
code_r0x00011992:
        local_24 = local_1b0 + iVar12;
        break;
      case 9:
        if (s_result_clipVertex_001b78fc[0] == '\0') goto code_r0x0000d93a;
        iVar12 = 0;
        pcVar22 = "result.clipVertex";
        cVar21 = s_result_clipVertex_001b78fc[0];
        do {
          local_1b0[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
code_r0x0000d93c:
        local_24 = local_1b0 + iVar12;
        break;
      case 10:
        if (s_result_attrib__001b78d8[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "result.attrib[";
          cVar21 = s_result_attrib__001b78d8[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        local_1b0 = local_1b0 + iVar13 + iVar12;
        if (s___001b7230[0] != '\0') {
          iVar12 = 0;
          pcVar22 = "]";
          cVar21 = s___001b7230[0];
          do {
            local_1b0[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
            local_24 = local_1b0;
          } while (cVar21 != '\0');
          goto code_r0x00011548;
        }
code_r0x000119a6:
        iVar12 = 0;
code_r0x000119a8:
        local_24 = local_1b0 + iVar12;
      }
      local_1b0 = local_24;
      if (s___001b74c4[0] == '\0') {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        pcVar22 = ";\n";
        cVar21 = s___001b74c4[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
      }
      local_24 = local_1b0 + iVar12;
      iVar12 = ((int (*)())FUN_0000b1ac)();
      if (iVar12 == 0) {
        if (local_164 != (void *)0x0) {
          _free(local_164);
        }
        if (local_160 != (void *)0x0) {
          _free(local_160);
        }
        if (local_15c != (void *)0x0) {
          _free(local_15c);
        }
        if (local_158 != (void *)0x0) {
          _free(local_158);
        }
        goto LAB_0000f848;
      }
LAB_0000d991:
      local_a8 = local_a8 + 1;
      puVar18 = puVar18 + 2;
    } while (uVar5 != local_a8);
  }
  if ((uVar5 != 0) || (!bVar6)) {
    pcVar22 = "\n";
    if (s__001b7388[0] == '\0') {
      iVar12 = 0;
    }
    else {
      iVar12 = 0;
      cVar21 = s__001b7388[0];
      do {
        local_24[iVar12] = cVar21;
        iVar12 = iVar12 + 1;
        cVar21 = pcVar22[1];
        pcVar22 = pcVar22 + 1;
      } while (cVar21 != '\0');
    }
    local_24 = local_24 + iVar12;
  }
  uVar4 = param_1[0x14];
  uVar5 = param_1[0x15];
  if (0 < (int)uVar4) {
    uVar24 = 0;
    iVar12 = 0;
    local_148 = 0;
    do {
      local_148 = local_148 +
                  ((byte)((char)((ushort)param_1[uVar5 * 2 + iVar12 * 2] >> 6) + 0xb5U) < 2);
      iVar12 = iVar12 + 2 + (uint)((byte)param_1[uVar5 * 2 + iVar12 * 2] & 7);
      uVar24 = uVar24 + 1;
    } while (uVar4 != uVar24);
    if (local_148 == 0) {
      local_150 = (uint *)0x0;
      local_14c = (void *)0x0;
      local_148 = 0;
    }
    else {
      local_150 = _malloc(local_148 * 4);
      _memset(local_150,0,local_148);
      local_14c = _malloc(local_148 * 4);
      _memset(local_14c,0,local_148);
      local_148 = 0;
      local_a4 = 0;
      local_54 = 0;
      do {
        puVar18 = param_1 + uVar5 * 2 + local_54 * 2;
        if ((byte)((char)((ushort)*puVar18 >> 6) + 0xb5U) < 2) {
          uVar24 = *puVar18;
          uVar23 = puVar18[1] >> 0xe;
          if ((int)local_148 < 1) {
            if (local_148 == 0) {
LAB_0001037f:
              local_150[local_148] = uVar23;
              *(uint *)((int)local_14c + local_148 * 4) = uVar24 >> 0xe;
              local_148 = local_148 + 1;
              goto LAB_0000dbd6;
            }
            local_104 = 0;
          }
          else if ((int)*local_150 < (int)uVar23) {
            local_104 = 0;
            do {
              local_104 = local_104 + 1;
              if (local_148 == local_104) goto LAB_0001037f;
            } while ((int)local_150[local_104] < (int)uVar23);
          }
          else {
            local_104 = 0;
          }
          local_70 = local_150[local_104];
          if (uVar23 != local_70) {
            local_150[local_104] = uVar23;
            puVar14 = (uint *)((int)local_14c + local_104 * 4);
            local_74 = *puVar14;
            *puVar14 = uVar24 >> 0xe;
            local_104 = local_104 + 1;
            if (local_104 < (int)local_148) {
              puVar14 = local_150 + local_104;
              puVar15 = (uint *)(local_104 * 4 + (int)local_14c);
              iVar12 = 0;
              uVar24 = local_70;
              local_1cc = local_74;
              do {
                local_70 = *puVar14;
                *puVar14 = uVar24;
                local_74 = *puVar15;
                *puVar15 = local_1cc;
                iVar12 = iVar12 + 1;
                puVar14 = puVar14 + 1;
                puVar15 = puVar15 + 1;
                uVar24 = local_70;
                local_1cc = local_74;
              } while (local_148 - local_104 != iVar12);
              local_104 = local_104 + iVar12;
            }
            local_150[local_104] = local_70;
            *(uint *)((int)local_14c + local_104 * 4) = local_74;
            local_148 = local_148 + 1;
          }
        }
LAB_0000dbd6:
        local_54 = local_54 + 2 + (uint)((byte)*puVar18 & 7);
        local_a4 = local_a4 + 1;
      } while (uVar4 != local_a4);
    }
    local_50 = 0;
    local_144 = 0;
    local_a0 = 0;
    local_94 = 1;
    do {
      puVar18 = param_1 + uVar5 * 2 + local_50 * 2;
      if (((*puVar18 & 0xffffc000) == 0) && (bVar6)) {
        if (s_main__001b7910[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "main:\n";
          cVar21 = s_main__001b7910[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = local_24 + iVar12;
      }
      if (((local_148 != 0) && (local_144 < (int)local_148)) &&
         (*puVar18 >> 0xe == local_150[local_144])) {
        if (0 < local_94 + -1) {
          iVar12 = 0;
          do {
            local_1b0 = local_24;
            if (s__001b7918[0] == '\0') {
              iVar13 = 0;
            }
            else {
              iVar13 = 0;
              pcVar22 = "  ";
              cVar21 = s__001b7918[0];
              do {
                local_24[iVar13] = cVar21;
                iVar13 = iVar13 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
            }
            local_24 = local_1b0 + iVar13;
            iVar12 = iVar12 + 1;
          } while (local_94 + -1 != iVar12);
        }
        local_1b0 = local_24;
        if (s_label__001b791c[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "label_";
          cVar21 = s_label__001b791c[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_144 = local_144 + 1;
        iVar13 = ((int (*)())FUN_0000b578)();
        if (s___001b7924[0] == '\0') {
          iVar16 = 0;
        }
        else {
          iVar16 = 0;
          pcVar22 = ":\n";
          cVar21 = s___001b7924[0];
          do {
            local_1b0[iVar16 + iVar13 + iVar12] = cVar21;
            iVar16 = iVar16 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = local_1b0 + iVar16 + iVar13 + iVar12;
      }
      uVar10 = (ushort)*puVar18 & 0x3fc0;
      if (((uVar10 == 0x1ac0) || (uVar10 == 0x1600)) ||
         ((uVar10 == 0x1640 || ((uVar10 == 0x1680 || (uVar10 == 0x16c0)))))) {
        local_94 = local_94 + -1;
      }
      bVar9 = (byte)((ushort)*puVar18 >> 6);
      uVar23 = *puVar18;
      uVar24 = puVar18[1];
      if (0 < local_94) {
        iVar12 = 0;
        do {
          if (s__001b7918[0] == '\0') {
            iVar13 = 0;
          }
          else {
            iVar13 = 0;
            pcVar22 = "  ";
            cVar21 = s__001b7918[0];
            do {
              local_24[iVar13] = cVar21;
              iVar13 = iVar13 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          local_24 = local_24 + iVar13;
          iVar12 = iVar12 + 1;
        } while (iVar12 != local_94);
      }
      pcVar22 = (PTR_s_MOV_001ec020)[bVar9];
      cVar21 = *pcVar22;
      if (cVar21 == '\0') {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[iVar12];
        } while (cVar21 != '\0');
      }
      local_24 = local_24 + iVar12;
      cVar21 = s___001b7958[0];
      switch(bVar9) {
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
        ((int (*)())FUN_0000b2b5)();
        iVar12 = ((int (*)())FUN_0000b209)(*(byte *)((int)puVar18 + 5) >> 3 & 1);
        if (bVar6) {
          iVar12 = ((int (*)())FUN_0000c1a9)((ushort)puVar18[1] >> 6 & 7);
        }
        if (s__001b7928[0] != '\0') {
          iVar13 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000b922)(local_158,1,bVar6);
        cVar21 = s___001b72bc[0];
        pcVar22 = ", ";
        cStack_31 = s___001b72bc[0];
        if (s___001b72bc[0] != '\0') {
          iVar13 = 0;
          pcVar19 = pcVar22;
          cVar20 = s___001b72bc[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar20;
            iVar13 = iVar13 + 1;
            cVar20 = pcVar19[1];
            pcVar19 = pcVar19 + 1;
          } while (cVar20 != '\0');
        }
        local_24 = (char *)((int (*)())FUN_0000c351)(local_160,local_15c,local_158,2,bVar6,0);
        if ((uVar23 & 7) == 2) {
          if (cVar21 != '\0') {
            iVar12 = 0;
            do {
              local_24[iVar12] = cStack_31;
              iVar12 = iVar12 + 1;
              cStack_31 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cStack_31 != '\0');
          }
          uVar27 = 0;
          uVar26 = 3;
          goto code_r0x0000f79c;
        }
        goto code_r0x0000fa7c;
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
        ((int (*)())FUN_0000b2b5)();
        iVar12 = ((int (*)())FUN_0000b209)(*(byte *)((int)puVar18 + 5) >> 3 & 1);
        if (bVar6) {
          iVar12 = ((int (*)())FUN_0000c1a9)((ushort)puVar18[1] >> 6 & 7);
        }
        if (s__001b7928[0] != '\0') {
          iVar13 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000b922)(local_158,1,bVar6);
        cVar21 = s___001b72bc[0];
        pcVar22 = ", ";
        if (s___001b72bc[0] != '\0') {
          iVar13 = 0;
          pcVar19 = pcVar22;
          cVar20 = s___001b72bc[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar20;
            iVar13 = iVar13 + 1;
            cVar20 = pcVar19[1];
            pcVar19 = pcVar19 + 1;
          } while (cVar20 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000c351)(local_160,local_15c,local_158,2,bVar6,0);
        if (cVar21 != '\0') {
          iVar13 = 0;
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        uVar27 = 0;
        uVar26 = 3;
        goto code_r0x0000f79c;
      case 0x3b:
      case 0x3c:
      case 0x3d:
      case 0x3e:
      case 0x3f:
      case 0x40:
      case 0x53:
      case 0x67:
      case 0x68:
        ((int (*)())FUN_0000b2b5)();
        iVar12 = ((int (*)())FUN_0000b209)(*(byte *)((int)puVar18 + 5) >> 3 & 1);
        if (bVar6) {
          iVar12 = ((int (*)())FUN_0000c1a9)((ushort)puVar18[1] >> 6 & 7);
        }
        if (s__001b7928[0] != '\0') {
          iVar13 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000b922)(local_158,1,bVar6);
        cVar21 = s___001b72bc[0];
        pcVar22 = ", ";
        if (s___001b72bc[0] != '\0') {
          iVar13 = 0;
          pcVar19 = pcVar22;
          cVar20 = s___001b72bc[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar20;
            iVar13 = iVar13 + 1;
            cVar20 = pcVar19[1];
            pcVar19 = pcVar19 + 1;
          } while (cVar20 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000c351)(local_160,local_15c,local_158,2,bVar6,0);
        if (cVar21 != '\0') {
          iVar13 = 0;
          pcVar19 = pcVar22;
          cVar20 = cVar21;
          do {
            *(char *)(iVar12 + iVar13) = cVar20;
            iVar13 = iVar13 + 1;
            cVar20 = pcVar19[1];
            pcVar19 = pcVar19 + 1;
          } while (cVar20 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000c351)(local_160,local_15c,local_158,3,bVar6,0);
        if (cVar21 != '\0') {
          iVar13 = 0;
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = (char *)((int (*)())FUN_0000c351)(local_160,local_15c,local_158,4,bVar6,0);
        local_100 = 4;
        cVar21 = s___001b7958[0];
        break;
      case 0x41:
        iVar12 = ((int (*)())FUN_0000b209)(*(byte *)((int)puVar18 + 5) >> 3 & 1);
        if (bVar6) {
          iVar12 = ((int (*)())FUN_0000c1a9)((ushort)puVar18[1] >> 6 & 7);
        }
        if (s__001b7928[0] != '\0') {
          iVar13 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000b922)(local_158,1,bVar6);
        if (s___001b72bc[0] != '\0') {
          iVar13 = 0;
          pcVar22 = ", ";
          cVar21 = s___001b72bc[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        uVar27 = 1;
        uVar26 = 2;
code_r0x0000f79c:
        local_24 = (char *)((int (*)())FUN_0000c351)(CONCAT44(local_15c,local_160),local_158,uVar26,bVar6,uVar27)
        ;
        local_100 = 3;
        cVar21 = s___001b7958[0];
        break;
      case 0x42:
      case 0x43:
        iVar12 = ((int (*)())FUN_0000b209)(*(byte *)((int)puVar18 + 5) >> 3 & 1);
        if (bVar6) {
          iVar12 = ((int (*)())FUN_0000c1a9)((ushort)puVar18[1] >> 6 & 7);
        }
        if (s__001b7928[0] != '\0') {
          iVar13 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000b922)(local_158,1,bVar6);
        cVar21 = s___001b72bc[0];
        pcVar22 = ", ";
        if (s___001b72bc[0] != '\0') {
          iVar13 = 0;
          pcVar19 = pcVar22;
          cVar20 = s___001b72bc[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar20;
            iVar13 = iVar13 + 1;
            cVar20 = pcVar19[1];
            pcVar19 = pcVar19 + 1;
          } while (cVar20 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000c351)(local_160,local_15c,local_158,2,bVar6,0);
        if (cVar21 != '\0') {
          iVar13 = 0;
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = (char *)((int (*)())FUN_0000cf2d)(local_160,local_15c,local_158,3,bVar6);
        local_100 = bVar6 + 3;
        cVar21 = s___001b7958[0];
        break;
      case 0x44:
      case 0x45:
      case 0x46:
      case 0x47:
        iVar12 = ((int (*)())FUN_0000b209)(*(byte *)((int)puVar18 + 5) >> 3 & 1);
        if (bVar6) {
          iVar12 = ((int (*)())FUN_0000c1a9)((ushort)puVar18[1] >> 6 & 7);
        }
        if (s__001b7928[0] != '\0') {
          iVar13 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000b922)(local_158,1,bVar6);
        cVar20 = s___001b72bc[0];
        pcVar22 = ", ";
        cStack_32 = s___001b72bc[0];
        if (s___001b72bc[0] != '\0') {
          iVar13 = 0;
          pcVar19 = pcVar22;
          cVar21 = s___001b72bc[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar19[1];
            pcVar19 = pcVar19 + 1;
          } while (cVar21 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000c351)(local_160,local_15c,local_158,2,bVar6,0);
        if (cVar20 != '\0') {
          iVar13 = 0;
          pcVar19 = pcVar22;
          cVar21 = cVar20;
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar19[1];
            pcVar19 = pcVar19 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = (char *)((int (*)())FUN_0000cf2d)(local_160,local_15c,local_158,3,bVar6);
        local_100 = bVar6 + 3;
        cVar21 = s___001b7958[0];
        if (bVar6) {
          if (cVar20 != '\0') {
            iVar12 = 0;
            do {
              local_24[iVar12] = cStack_32;
              iVar12 = iVar12 + 1;
              cStack_32 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cStack_32 != '\0');
          }
          local_100 = 5;
          local_24 = (char *)((int (*)())FUN_0000c351)(local_160,local_15c,local_158,5,1,0);
          cVar21 = s___001b7958[0];
        }
        break;
      case 0x48:
      case 0x49:
      case 0x4a:
        if (bVar6) {
          local_24 = (char *)((int (*)())FUN_0000c1a9)((ushort)puVar18[1] >> 6 & 7);
        }
        if (s__001b7928[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = local_24 + iVar12;
        if ((*(byte *)((int)puVar18 + 9) & 0x70) == 0x40) {
          if (s_adr_001b72b8[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = "adr";
            cVar21 = s_adr_001b72b8[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          iVar13 = ((int (*)())FUN_0000b578)();
          local_24 = local_24 + iVar13 + iVar12;
        }
        if ((puVar18[2] & 0x78000) != 0x78000) {
          if (s___001b7254[0] == '\0') {
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = ".";
            cVar21 = s___001b7254[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          local_24 = local_24 + iVar12;
          if (bVar6) {
            bVar8 = *(byte *)((int)puVar18 + 10);
            if ((bVar8 & 4) != 0) {
              if (s_x_001b7258[0] == '\0') {
                iVar12 = 0;
              }
              else {
                iVar12 = 0;
                pcVar22 = "x";
                cVar21 = s_x_001b7258[0];
                do {
                  local_24[iVar12] = cVar21;
                  iVar12 = iVar12 + 1;
                  cVar21 = pcVar22[1];
                  pcVar22 = pcVar22 + 1;
                } while (cVar21 != '\0');
                bVar8 = *(byte *)((int)puVar18 + 10);
              }
              local_24 = local_24 + iVar12;
            }
            if (((bVar8 & 0x30) != 0) && ((bVar8 & 2) != 0)) {
              if (s_y_001b725c[0] == '\0') {
                iVar12 = 0;
              }
              else {
                iVar12 = 0;
                pcVar22 = "y";
                cVar21 = s_y_001b725c[0];
                do {
                  local_24[iVar12] = cVar21;
                  iVar12 = iVar12 + 1;
                  cVar21 = pcVar22[1];
                  pcVar22 = pcVar22 + 1;
                } while (cVar21 != '\0');
                bVar8 = *(byte *)((int)puVar18 + 10);
              }
              local_24 = local_24 + iVar12;
            }
            if ((1 < (bVar8 >> 4 & 3)) && ((bVar8 & 1) != 0)) {
              if (s_z_001b7260[0] == '\0') {
                iVar12 = 0;
              }
              else {
                iVar12 = 0;
                pcVar22 = "z";
                cVar21 = s_z_001b7260[0];
                do {
                  local_24[iVar12] = cVar21;
                  iVar12 = iVar12 + 1;
                  cVar21 = pcVar22[1];
                  pcVar22 = pcVar22 + 1;
                } while (cVar21 != '\0');
                bVar8 = *(byte *)((int)puVar18 + 10);
              }
              local_24 = local_24 + iVar12;
            }
            if ((2 < (bVar8 >> 4 & 3)) && ((char)*(byte *)((int)puVar18 + 9) < '\0')) {
              if (s_w_001b7264[0] == '\0') {
code_r0x00012c98:
                iVar12 = 0;
              }
              else {
                iVar12 = 0;
                pcVar22 = "w";
                cVar21 = s_w_001b7264[0];
                do {
                  local_24[iVar12] = cVar21;
                  iVar12 = iVar12 + 1;
                  cVar21 = pcVar22[1];
                  pcVar22 = pcVar22 + 1;
                } while (cVar21 != '\0');
              }
code_r0x0000f4f7:
              local_24 = local_24 + iVar12;
            }
          }
          else {
            bVar8 = *(byte *)((int)puVar18 + 10);
            if ((bVar8 & 4) != 0) {
              if (s_x_001b7258[0] == '\0') {
                iVar12 = 0;
              }
              else {
                iVar12 = 0;
                pcVar22 = "x";
                cVar21 = s_x_001b7258[0];
                do {
                  local_24[iVar12] = cVar21;
                  iVar12 = iVar12 + 1;
                  cVar21 = pcVar22[1];
                  pcVar22 = pcVar22 + 1;
                } while (cVar21 != '\0');
                bVar8 = *(byte *)((int)puVar18 + 10);
              }
              local_24 = local_24 + iVar12;
            }
            if ((bVar8 & 2) != 0) {
              if (s_y_001b725c[0] == '\0') {
                iVar12 = 0;
              }
              else {
                iVar12 = 0;
                pcVar22 = "y";
                cVar21 = s_y_001b725c[0];
                do {
                  local_24[iVar12] = cVar21;
                  iVar12 = iVar12 + 1;
                  cVar21 = pcVar22[1];
                  pcVar22 = pcVar22 + 1;
                } while (cVar21 != '\0');
                bVar8 = *(byte *)((int)puVar18 + 10);
              }
              local_24 = local_24 + iVar12;
            }
            if ((bVar8 & 1) != 0) {
              if (s_z_001b7260[0] == '\0') {
                iVar12 = 0;
              }
              else {
                iVar12 = 0;
                pcVar22 = "z";
                cVar21 = s_z_001b7260[0];
                do {
                  local_24[iVar12] = cVar21;
                  iVar12 = iVar12 + 1;
                  cVar21 = pcVar22[1];
                  pcVar22 = pcVar22 + 1;
                } while (cVar21 != '\0');
              }
              local_24 = local_24 + iVar12;
            }
            if ((char)*(byte *)((int)puVar18 + 9) < '\0') {
              if (s_w_001b7264[0] == '\0') goto code_r0x00012c98;
              iVar12 = 0;
              pcVar22 = "w";
              cVar21 = s_w_001b7264[0];
              do {
                local_24[iVar12] = cVar21;
                iVar12 = iVar12 + 1;
                cVar21 = pcVar22[1];
                pcVar22 = pcVar22 + 1;
              } while (cVar21 != '\0');
              goto code_r0x0000f4f7;
            }
          }
        }
        if (s___001b72bc[0] != '\0') {
          iVar12 = 0;
          pcVar22 = ", ";
          cVar21 = s___001b72bc[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        goto code_r0x0000fa69;
      case 0x4b:
      case 0x4c:
        if (s__001b7928[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        if (local_150 == (uint *)0x0) {
          iVar13 = -1;
        }
        else if (puVar18[1] >> 0xe == *local_150) {
          iVar13 = 0;
        }
        else {
          iVar13 = 0;
          do {
            iVar13 = iVar13 + 1;
          } while (puVar18[1] >> 0xe != local_150[iVar13]);
        }
        iVar13 = _sprintf(local_24 + iVar12,"label_%i",iVar13);
        local_24 = local_24 + iVar12 + iVar13;
        if (bVar9 != 0x4b) goto code_r0x0000f022;
        puVar14 = puVar18 + 2;
        switch((byte)puVar18[2] >> 1 & 7) {
        case 0:
          if (s__TR_001b7268[0] == '\0') {
code_r0x000139ba:
            iVar12 = 0;
          }
          else {
            iVar12 = 0;
            pcVar22 = " (TR";
            cVar21 = s__TR_001b7268[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          break;
        case 1:
          if (s__EQ_001b7270[0] == '\0') goto code_r0x000139ba;
          iVar12 = 0;
          pcVar22 = " (EQ";
          cVar21 = s__EQ_001b7270[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        case 2:
          if (s__GE_001b7278[0] == '\0') goto code_r0x000139ba;
          iVar12 = 0;
          pcVar22 = " (GE";
          cVar21 = s__GE_001b7278[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        case 3:
          if (s__GT_001b7280[0] == '\0') goto code_r0x000139ba;
          iVar12 = 0;
          pcVar22 = " (GT";
          cVar21 = s__GT_001b7280[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        case 4:
          if (s__LE_001b7288[0] == '\0') goto code_r0x000139ba;
          iVar12 = 0;
          pcVar22 = " (LE";
          cVar21 = s__LE_001b7288[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        case 5:
          if (s__LT_001b7290[0] == '\0') goto code_r0x000139ba;
          iVar12 = 0;
          pcVar22 = " (LT";
          cVar21 = s__LT_001b7290[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        case 6:
          if (s__NE_001b7298[0] == '\0') goto code_r0x000139ba;
          iVar12 = 0;
          pcVar22 = " (NE";
          cVar21 = s__NE_001b7298[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        case 7:
          if (s__FL_001b72a0[0] == '\0') goto code_r0x000139ba;
          iVar12 = 0;
          pcVar22 = " (FL";
          cVar21 = s__FL_001b72a0[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
          break;
        default:
          goto code_r0x00012d2b;
        }
        local_24 = local_24 + iVar12;
code_r0x00012d2b:
        if ((*puVar14 & 1) != 0) {
          *local_24 = '1';
          local_24 = local_24 + 1;
        }
        *local_24 = '.';
        local_24[1] = (((byte)*puVar14 >> 4) + 1 & 3) + 0x77;
        local_24[2] = (((byte)*puVar14 >> 6) + 1 & 3) + 0x77;
        local_24[3] = (*(byte *)((int)puVar18 + 9) + 1 & 3) + 0x77;
        local_24[4] = ((*(byte *)((int)puVar18 + 9) >> 2) + 1 & 3) + 0x77;
        local_24[5] = ')';
        local_24 = local_24 + 6;
        local_100 = 1;
        cVar21 = s___001b7958[0];
        break;
      case 0x4d:
      case 0x54:
      case 0x59:
      case 0x5a:
      case 0x5b:
      case 0x69:
      case 0x6b:
      case 0x6e:
code_r0x0000f022:
        local_100 = 1;
        cVar21 = s___001b7958[0];
        break;
      case 0x4f:
        if (s__001b7928[0] != '\0') {
          iVar12 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        goto code_r0x0000fa69;
      case 0x55:
        local_94 = local_94 + 1;
        if (bVar6) {
          iVar12 = ((int (*)())FUN_0000c1a9)((ushort)puVar18[1] >> 6 & 7);
          if (s__001b7928[0] != '\0') {
            iVar13 = 0;
            pcVar22 = " ";
            cVar21 = s__001b7928[0];
            do {
              *(char *)(iVar12 + iVar13) = cVar21;
              iVar13 = iVar13 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
          }
          goto code_r0x0000fa69;
        }
        puVar14 = puVar18 + 2;
        switch((byte)puVar18[2] >> 1 & 7) {
        case 0:
          if (s_TR_001b792c[0] != '\0') {
            iVar12 = 0;
            pcVar22 = " TR";
            cVar21 = s_TR_001b792c[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
code_r0x000126a6:
            local_24 = local_24 + iVar12;
          }
          break;
        case 1:
          if (s_EQ_001b7930[0] != '\0') {
            iVar12 = 0;
            pcVar22 = " EQ";
            cVar21 = s_EQ_001b7930[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000126a6;
          }
          break;
        case 2:
          if (s_GE_001b7934[0] != '\0') {
            iVar12 = 0;
            pcVar22 = " GE";
            cVar21 = s_GE_001b7934[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000126a6;
          }
          break;
        case 3:
          if (s_GT_001b7938[0] != '\0') {
            iVar12 = 0;
            pcVar22 = " GT";
            cVar21 = s_GT_001b7938[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000126a6;
          }
          break;
        case 4:
          if (s_LE_001b793c[0] != '\0') {
            iVar12 = 0;
            pcVar22 = " LE";
            cVar21 = s_LE_001b793c[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000126a6;
          }
          break;
        case 5:
          if (s_LT_001b7940[0] != '\0') {
            iVar12 = 0;
            pcVar22 = " LT";
            cVar21 = s_LT_001b7940[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000126a6;
          }
          break;
        case 6:
          if (s_NE_001b7944[0] != '\0') {
            iVar12 = 0;
            pcVar22 = " NE";
            cVar21 = s_NE_001b7944[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000126a6;
          }
          break;
        case 7:
          if (s_FL_001b7948[0] != '\0') {
            iVar12 = 0;
            pcVar22 = " FL";
            cVar21 = s_FL_001b7948[0];
            do {
              local_24[iVar12] = cVar21;
              iVar12 = iVar12 + 1;
              cVar21 = pcVar22[1];
              pcVar22 = pcVar22 + 1;
            } while (cVar21 != '\0');
            goto code_r0x000126a6;
          }
        }
        if ((*puVar14 & 1) != 0) {
          *local_24 = '1';
          local_24 = local_24 + 1;
        }
        *local_24 = '.';
        local_24[1] = (((byte)*puVar14 >> 4) + 1 & 3) + 0x77;
        local_24[2] = (((byte)*puVar14 >> 6) + 1 & 3) + 0x77;
        local_24[3] = (*(byte *)((int)puVar18 + 9) + 1 & 3) + 0x77;
        local_24[4] = ((*(byte *)((int)puVar18 + 9) >> 2) + 1 & 3) + 0x77;
        local_24 = local_24 + 5;
        local_100 = 1;
        cVar21 = s___001b7958[0];
        break;
      case 0x56:
      case 0x57:
        local_94 = local_94 + 1;
        if (s__001b7928[0] != '\0') {
          iVar12 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        goto code_r0x0000fa69;
      case 0x58:
      case 0x6a:
        local_94 = local_94 + 1;
        local_100 = 1;
        break;
      case 0x60:
      case 0x61:
        if (s__001b7928[0] != '\0') {
          iVar12 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
code_r0x0000fa69:
        local_24 = (char *)((int (*)())FUN_0000c351)(CONCAT44(local_15c,local_160),local_158,2,bVar6,0);
code_r0x0000fa7c:
        local_100 = 2;
        cVar21 = s___001b7958[0];
        break;
      case 0x62:
        iVar12 = ((int (*)())FUN_0000b209)(*(byte *)((int)puVar18 + 5) >> 3 & 1);
        if (bVar6) {
          iVar12 = ((int (*)())FUN_0000c1a9)((ushort)puVar18[1] >> 6 & 7);
        }
        if (s__001b7928[0] != '\0') {
          iVar13 = 0;
          pcVar22 = " ";
          cVar21 = s__001b7928[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000b922)(local_158,1,bVar6);
        cVar21 = s___001b72bc[0];
        pcVar22 = ", ";
        if (s___001b72bc[0] != '\0') {
          iVar13 = 0;
          pcVar19 = pcVar22;
          cVar20 = s___001b72bc[0];
          do {
            *(char *)(iVar12 + iVar13) = cVar20;
            iVar13 = iVar13 + 1;
            cVar20 = pcVar19[1];
            pcVar19 = pcVar19 + 1;
          } while (cVar20 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000c351)(local_160,local_15c,local_158,2,bVar6,0);
        if (cVar21 != '\0') {
          iVar13 = 0;
          pcVar19 = pcVar22;
          cVar20 = cVar21;
          do {
            *(char *)(iVar12 + iVar13) = cVar20;
            iVar13 = iVar13 + 1;
            cVar20 = pcVar19[1];
            pcVar19 = pcVar19 + 1;
          } while (cVar20 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000c351)(local_160,local_15c,local_158,3,bVar6,0);
        if (cVar21 != '\0') {
          iVar13 = 0;
          pcVar19 = pcVar22;
          cVar20 = cVar21;
          do {
            *(char *)(iVar12 + iVar13) = cVar20;
            iVar13 = iVar13 + 1;
            cVar20 = pcVar19[1];
            pcVar19 = pcVar19 + 1;
          } while (cVar20 != '\0');
        }
        iVar12 = ((int (*)())FUN_0000c351)(local_160,local_15c,local_158,4,bVar6,0);
        if (cVar21 != '\0') {
          iVar13 = 0;
          do {
            *(char *)(iVar12 + iVar13) = cVar21;
            iVar13 = iVar13 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = (char *)((int (*)())FUN_0000cf2d)(local_160,local_15c,local_158,5,bVar6);
        local_100 = bVar6 + 5;
        cVar21 = s___001b7958[0];
        break;
      default:
        local_100 = 0;
      }
      s___001b7958[0] = cVar21;
      if (cVar21 == '\0') {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        pcVar22 = ";";
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
      }
      local_24 = local_24 + iVar12;
      if (bVar6) {
        switch(bVar9) {
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
          iVar12 = _sprintf(local_24,"    # Target: %d",uVar24 >> 0xe);
          local_24 = local_24 + iVar12;
        }
      }
      if (s__001b7388[0] == '\0') {
        iVar12 = 0;
      }
      else {
        iVar12 = 0;
        pcVar22 = "\n";
        cVar21 = s__001b7388[0];
        do {
          local_24[iVar12] = cVar21;
          iVar12 = iVar12 + 1;
          cVar21 = pcVar22[1];
          pcVar22 = pcVar22 + 1;
        } while (cVar21 != '\0');
      }
      local_24 = local_24 + iVar12;
      iVar12 = ((int (*)())FUN_0000b1ac)();
      if (iVar12 == 0) {
        if (local_164 != (void *)0x0) {
          _free(local_164);
        }
        if (local_160 != (void *)0x0) {
          _free(local_160);
        }
        if (local_15c != (void *)0x0) {
          _free(local_15c);
        }
        if (local_158 != (void *)0x0) {
          _free(local_158);
        }
        if (local_148 != 0) {
          _free(local_150);
          _free(local_14c);
        }
        goto LAB_0000f848;
      }
      local_a0 = local_a0 + 1;
      local_50 = local_50 + local_100 + 1;
    } while (uVar4 != local_a0);
    if (local_148 != 0) {
      if ((local_144 < (int)local_148) && (uVar4 + 1 == local_150[local_144])) {
        if (s_label__001b7970[0] == '\0') {
          iVar12 = 0;
        }
        else {
          iVar12 = 0;
          pcVar22 = "  label_";
          cVar21 = s_label__001b7970[0];
          do {
            local_24[iVar12] = cVar21;
            iVar12 = iVar12 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        iVar13 = ((int (*)())FUN_0000b578)();
        if (s___001b7924[0] == '\0') {
          iVar16 = 0;
        }
        else {
          iVar16 = 0;
          pcVar22 = ":\n";
          cVar21 = s___001b7924[0];
          do {
            local_24[iVar16 + iVar13 + iVar12] = cVar21;
            iVar16 = iVar16 + 1;
            cVar21 = pcVar22[1];
            pcVar22 = pcVar22 + 1;
          } while (cVar21 != '\0');
        }
        local_24 = local_24 + iVar16 + iVar13 + iVar12;
      }
      _free(local_150);
      _free(local_14c);
    }
  }
  if (s_END_001b797c[0] == '\0') {
    iVar12 = 0;
  }
  else {
    iVar12 = 0;
    pcVar22 = "END\n";
    cVar21 = s_END_001b797c[0];
    do {
      local_24[iVar12] = cVar21;
      iVar12 = iVar12 + 1;
      cVar21 = pcVar22[1];
      pcVar22 = pcVar22 + 1;
    } while (cVar21 != '\0');
  }
  local_24 = local_24 + iVar12;
  *local_24 = '\0';
  if (local_164 != (void *)0x0) {
    _free(local_164);
  }
  if (local_160 != (void *)0x0) {
    _free(local_160);
  }
  if (local_15c != (void *)0x0) {
    _free(local_15c);
  }
  if (local_158 != (void *)0x0) {
    _free(local_158);
  }
  if ((int)(local_24 + (1 - (int)pvVar11)) < 1) {
    _free(pvVar11);
    local_20 = (void *)0x0;
  }
  else {
    local_20 = _realloc(pvVar11,(size_t)(local_24 + (1 - (int)pvVar11)));
  }
  return local_20;
}

/* FUN_0001405a @ 0x1405a (2871 bytes) */
void FUN_0001405a(int param_1,float *param_2,int param_3,int param_4,float param_5,float param_6,
                 int param_7,char param_8)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  sbyte sVar10;
  int iVar11;
  float *pfVar12;
  int iVar13;
  uint uVar14;
  float *pfVar15;
  longdouble lVar16;
  longdouble lVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  double dVar21;
  uint local_130;
  uint local_12c;
  uint local_128;
  int local_124;
  uint local_120;
  uint local_11c;
  uint local_118;
  uint local_114;
  uint local_110;
  int local_10c;
  int local_108;
  int local_104;
  float local_100;
  float local_fc;
  float local_e0;
  float local_dc;
  uint local_d8;
  uint local_d4;
  int local_d0;
  int local_cc;
  uint local_c8;
  undefined1 local_b8 [140];
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  
  iVar8 = param_1 + 0x240;
  fVar3 = param_2[2];
  local_24 = param_2[0xc];
  local_28 = param_2[0xd];
  local_2c = param_2[0xe];
  local_20 = param_2[0xf];
  iVar9 = *(int *)(param_1 + 0x10);
  if (*(char *)(iVar9 + 0x2e0a) != '\0') {
    fVar2 = param_2[0x13];
    dVar21 = DOUBLE_001cf330 - (double)fVar2;
    local_24 = (float)((double)(fVar2 * local_24) + (double)*(float *)(iVar9 + 0x2de0) * dVar21);
    local_28 = (float)((double)(fVar2 * local_28) + (double)*(float *)(iVar9 + 0x2de4) * dVar21);
    local_2c = (float)((double)(fVar2 * local_2c) + (double)*(float *)(iVar9 + 0x2de8) * dVar21);
    local_20 = (float)((double)(fVar2 * local_20) + dVar21 * (double)*(float *)(iVar9 + 0x2dec));
  }
  fVar7 = local_20;
  fVar6 = local_24;
  fVar5 = local_28;
  fVar2 = local_2c;
  local_dc = FLOAT_001c5bd4;
  iVar9 = (int)(*(float *)(param_1 + 0x2a54) + FLOAT_001c5bd4);
  iVar13 = (int)(*(float *)(param_1 + 0x2a58) + FLOAT_001c5bd4);
  iVar11 = iVar9 * iVar13;
  local_e0 = local_dc;
  if (iVar9 == 2) {
    local_e0 = FLOAT_001c5bd8;
  }
  if (iVar13 == 2) {
    local_dc = FLOAT_001c5bd8;
  }
  if (param_3 < 1) {
    return;
  }
  if (param_4 < 1) {
    return;
  }
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  FUN_000282b1(iVar8,local_b8);
  lVar16 = (longdouble)_floorf(*param_2 - param_5);
  if (*(char *)(param_1 + 0x2b7c) == '\0') {
    lVar17 = (longdouble)_floorf(param_2[1] - param_6);
    local_100 = (float)lVar17;
    local_fc = FLOAT_001c5ba4;
    if (param_8 != '\0') goto LAB_00014271;
LAB_0001448a:
    iVar9 = *(int *)(param_1 + 0x10);
    uVar14 = *(int *)(iVar9 + 0x2e80) - 1;
    iVar13 = *(int *)(iVar9 + 0x2e6c);
    if (*(int *)(iVar9 + 0x2e6c) == 0) {
      iVar13 = param_3;
    }
    local_118 = uVar14 + (iVar13 + 7 >> 3) & ~uVar14;
    param_7 = param_7 + local_118 * *(int *)(iVar9 + 0x2e74) + ((int)*(uint *)(iVar9 + 0x2e78) >> 3)
    ;
    local_110 = *(uint *)(iVar9 + 0x2e78) & 7;
    local_114 = (int)(param_3 + 7 + local_110) >> 3;
    sVar10 = (sbyte)local_110;
    if (*(char *)(iVar9 + 0x2e85) == '\0') {
      local_d8 = 1 << sVar10;
      local_c8 = 0x80 >> sVar10;
      local_130 = 0xffffffff;
      goto LAB_000142b8;
    }
    local_d8 = 1 << sVar10;
    local_130 = 0;
    local_d4 = 0xffffffff;
    local_c8 = 0;
    iVar9 = iVar11 * param_3 * param_4;
    if (0x7ff < iVar9) goto LAB_000142da;
LAB_0001454c:
    iVar13 = iVar9 << 5;
    pfVar12 = *(float **)(param_1 + 0x1dc);
    if (pfVar12 + 2 < *(float **)(param_1 + 0x1e0)) goto LAB_000142fc;
  }
  else {
    lVar17 = (longdouble)_ceilf((param_6 + param_2[1]) - FLOAT_001c5ba4);
    local_100 = (float)lVar17;
    local_fc = FLOAT_001c5bdc;
    if (param_8 == '\0') goto LAB_0001448a;
LAB_00014271:
    local_118 = param_3 + 7 >> 3;
    local_110 = 0;
    local_130 = 0xff;
    local_d8 = 1;
    local_c8 = 0x80;
    local_114 = local_118;
LAB_000142b8:
    local_d4 = 0;
    iVar9 = iVar11 * param_3 * param_4;
    if (iVar9 < 0x800) goto LAB_0001454c;
LAB_000142da:
    iVar9 = 0x7ff;
    iVar13 = 0xffe0;
    pfVar12 = *(float **)(param_1 + 0x1dc);
    if (pfVar12 + 2 < *(float **)(param_1 + 0x1e0)) goto LAB_000142fc;
  }
  FUN_00017c77(param_1,0x1000000);
  pfVar12 = *(float **)(param_1 + 0x1dc);
LAB_000142fc:
  local_104 = param_3 * param_4;
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    *pfVar12 = 2.07392e-42;
    pfVar12[1] = 2.524355e-29;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
    pfVar12 = *(float **)(param_1 + 0x1dc);
  }
  if (*(uint *)(param_1 + 0x1e0) <= (uint)((int)pfVar12 + iVar13 + 0x10)) {
    FUN_00017c77(param_1,0x1000000);
    pfVar12 = *(float **)(param_1 + 0x1dc);
  }
  pfVar15 = pfVar12 + 4;
  local_124 = 0;
  local_108 = iVar9;
  do {
    if (0 < (int)local_114) {
      fVar20 = (float)lVar16;
      if (local_110 < 8) {
        local_cc = param_3;
        local_12c = local_c8;
        local_11c = local_110;
        local_120 = 0;
        local_128 = local_d8 & local_d4;
        goto LAB_00014609;
      }
      local_10c = param_3;
      local_120 = 0;
      while( true ) {
        local_12c = local_130 & 0x80;
        local_120 = local_120 + 1;
        if (local_114 == local_120) break;
        if (local_10c != 0) {
          local_cc = local_10c;
          local_11c = 0;
          local_128 = local_d4 & 1;
LAB_00014609:
          local_10c = local_cc;
          do {
            if (((uint)*(byte *)(param_7 + local_120) & (local_128 | local_12c)) != 0) {
              if (local_108 < iVar11) {
                *pfVar12 = 2.93152e-42;
                pfVar12[1] = *(float *)(param_1 + 0x1dc4);
                pfVar12[2] = (float)((iVar9 - local_108) * 0x80000 | 0xc0003500);
                pfVar12[3] = (float)((uint)(ushort)((short)iVar9 - (short)local_108) << 0x10 | 0x31)
                ;
                *(float **)(param_1 + 0x1dc) = pfVar15;
                iVar9 = iVar11 * local_104;
                if (iVar9 < 0x800) {
                  local_d0 = iVar9 * 0x20;
                  pfVar12 = *(float **)(param_1 + 0x1dc);
                  if (*(float **)(param_1 + 0x1e0) <= pfVar12 + iVar9 * 8 + 4) goto LAB_0001497d;
                }
                else {
                  iVar9 = 0x7ff;
                  local_d0 = 0xffe0;
                  pfVar12 = *(float **)(param_1 + 0x1dc);
                  if (*(float **)(param_1 + 0x1e0) <= pfVar12 + 0x3ffc) {
LAB_0001497d:
                    FUN_00017c77(param_1,0x1000000);
                    pfVar12 = *(float **)(param_1 + 0x1dc);
                  }
                }
                if ((pfVar15 != pfVar12) &&
                   (*(uint *)(param_1 + 0x1e0) <= (uint)(local_d0 + 0x10 + (int)pfVar12))) {
                  FUN_00017c77(param_1,0x1000000);
                  pfVar12 = *(float **)(param_1 + 0x1dc);
                }
                pfVar15 = pfVar12 + 4;
                local_108 = iVar9;
              }
              if (iVar11 == 1) {
                *pfVar15 = local_e0 + fVar20;
                pfVar15[1] = local_dc + local_100;
                pfVar15[2] = fVar3;
                pfVar15[3] = 1.0;
                pfVar15[4] = fVar6;
                pfVar15[5] = fVar5;
                pfVar1 = pfVar15 + 7;
                pfVar15[6] = fVar2;
                pfVar15 = pfVar15 + 8;
                *pfVar1 = fVar7;
              }
              else if (iVar11 == 2) {
                *pfVar15 = local_e0 + fVar20;
                pfVar15[1] = local_dc + local_100;
                pfVar15[2] = fVar3;
                pfVar15[3] = 1.0;
                pfVar15[4] = fVar6;
                pfVar15[5] = fVar5;
                pfVar15[6] = fVar2;
                pfVar15[7] = fVar7;
                local_100 = local_100 + FLOAT_001c5bd4;
                pfVar15[8] = local_e0 + fVar20;
                pfVar15[9] = local_dc + local_100;
                pfVar15[10] = fVar3;
                pfVar15[0xb] = 1.0;
                pfVar15[0xc] = fVar6;
                pfVar15[0xd] = fVar5;
                pfVar1 = pfVar15 + 0xf;
                pfVar15[0xe] = fVar2;
                pfVar15 = pfVar15 + 0x10;
                *pfVar1 = fVar7;
                local_100 = local_100 - FLOAT_001c5bd4;
              }
              else {
                *pfVar15 = local_e0 + fVar20;
                pfVar15[1] = local_dc + local_100;
                pfVar15[2] = fVar3;
                pfVar15[3] = 1.0;
                pfVar15[4] = fVar6;
                pfVar15[5] = fVar5;
                pfVar15[6] = fVar2;
                pfVar15[7] = fVar7;
                local_100 = local_100 + FLOAT_001c5bd4;
                fVar18 = local_dc + local_100;
                pfVar15[8] = local_e0 + fVar20;
                pfVar15[9] = fVar18;
                pfVar15[10] = fVar3;
                pfVar15[0xb] = 1.0;
                pfVar15[0xc] = fVar6;
                pfVar15[0xd] = fVar5;
                pfVar15[0xe] = fVar2;
                pfVar15[0xf] = fVar7;
                fVar20 = fVar20 + FLOAT_001c5bd4;
                fVar19 = local_e0 + fVar20;
                pfVar15[0x10] = fVar19;
                pfVar15[0x11] = fVar18;
                pfVar15[0x12] = fVar3;
                pfVar15[0x13] = 1.0;
                pfVar15[0x14] = fVar6;
                pfVar15[0x15] = fVar5;
                pfVar15[0x16] = fVar2;
                pfVar15[0x17] = fVar7;
                local_100 = local_100 - FLOAT_001c5bd4;
                pfVar15[0x18] = fVar19;
                pfVar15[0x19] = local_dc + local_100;
                pfVar15[0x1a] = fVar3;
                pfVar15[0x1b] = 1.0;
                pfVar15[0x1c] = fVar6;
                pfVar15[0x1d] = fVar5;
                pfVar1 = pfVar15 + 0x1f;
                pfVar15[0x1e] = fVar2;
                pfVar15 = pfVar15 + 0x20;
                *pfVar1 = fVar7;
                fVar20 = fVar20 - FLOAT_001c5bd4;
              }
              local_108 = local_108 - iVar11;
            }
            fVar20 = fVar20 + FLOAT_001c5ba4;
            local_104 = local_104 + -1;
            local_11c = local_11c + 1;
            local_128 = local_128 << 1;
            local_12c = local_12c >> 1;
            local_10c = local_10c + -1;
          } while ((local_11c != 8) && (local_10c != 0));
        }
      }
    }
    local_100 = local_100 + local_fc;
    param_7 = param_7 + local_118;
    local_124 = local_124 + 1;
    if (param_4 == local_124) {
      iVar9 = iVar9 - local_108;
      if (iVar9 == 0) {
        pfVar15 = pfVar15 + -4;
      }
      else {
        *pfVar12 = 2.93152e-42;
        pfVar12[1] = *(float *)(param_1 + 0x1dc4);
        pfVar12[2] = (float)(iVar9 * 0x80000 | 0xc0003500);
        pfVar12[3] = (float)(iVar9 * 0x10000 | 0x31);
      }
      *(float **)(param_1 + 0x1dc) = pfVar15;
      if (*(float **)(param_1 + 0x1e0) <= pfVar15 + 2) {
        FUN_00017c77(param_1,0x1000000);
      }
      puVar4 = *(undefined4 **)(param_1 + 0x1dc);
      *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 2;
      *puVar4 = 0x1087;
      puVar4[1] = *(undefined4 *)(param_1 + 0x1f0c);
      FUN_0009b2d9(iVar8);
      FUN_00082e73(iVar8,local_b8);
      return;
    }
  } while( true );
}

