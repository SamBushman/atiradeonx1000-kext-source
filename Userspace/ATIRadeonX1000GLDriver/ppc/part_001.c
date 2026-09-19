#include "decls.h"

/* _gldDestroyShared @ 0x6f40 (76 bytes) */
int _gldDestroyShared(param_1)
  pthread_mutex_t *param_1;
{
  undefined4 uVar1;
  
  uVar1 = 0x2714;
  if (param_1 != (pthread_mutex_t *)0x0) {
    FUN_00024fc0();
    _pthread_mutex_destroy(param_1);
    _free(param_1);
    uVar1 = 0;
  }
  return uVar1;
}

/* _gldReclaimContext @ 0x6f90 (128 bytes) */
int _gldReclaimContext(param_1)
  void *param_1;
{
  int iVar1;
  
  FUN_0002cc10();
  iVar1 = _io_connect_method_scalarI_structureI(*(undefined4 *)((int)param_1 + 4),0x11,0,0,0,0);
  if (iVar1 != 0) {
    _free(param_1);
    return;
  }
  *(undefined4 *)((int)param_1 + 0x204) = 0;
  *(undefined4 *)((int)param_1 + 0x1fc) = 0;
  *(undefined4 *)((int)param_1 + 0x200) = 0;
  *(undefined4 *)((int)param_1 + 500) = 0;
  *(undefined4 *)((int)param_1 + 0x1f8) = 0;
  return;
}

/* FUN_00007020 @ 0x7020 (164 bytes) */
int FUN_00007020(param_1)
  int *param_1;
{
  char cVar1;
  undefined *puVar2;
  
  if ((param_1[0x3e] != 0) &&
     (param_1[0x3e] = 0, puVar2 = PTR_DAT_001e88ac, (param_1[0xf] & 0x20U) == 0)) {
    cVar1 = PTR_DAT_001e88ac[*param_1 + 0x98];
    PTR_DAT_001e88ac[*param_1 + 0x98] = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      _IOServiceClose(*(undefined4 *)(puVar2 + *param_1 * 4 + 0x18));
      *(undefined4 *)(puVar2 + *param_1 * 4 + 0x18) = 0;
    }
  }
  return;
}

/* _gldAttachDrawable @ 0x70d0 (1804 bytes) */
int _gldAttachDrawable(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int *param_3;
  uint param_4;
{
  ushort uVar1;
  undefined *puVar2;
  code *pcVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  size_t sVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 local_68;
  int local_64 [3];
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  int local_40;
  int local_3c;
  
  if (param_1 == (int *)0x0) {
    return 0x271e;
  }
  uVar12 = param_4 >> 8 & 0xff;
  if ((param_2 == 0x50) || (param_2 == 0x5a)) {
    if (param_3 == (int *)0x0) {
      return 0x2715;
    }
    param_1[0xf] = param_1[0xf] | 0x20;
    piVar7 = param_3;
    if (param_2 != 0x5a) {
      piVar7 = (int *)0x0;
    }
    FUN_00017160(param_1,param_1 + 0xf,piVar7);
    local_64[0] = param_3[2];
    local_64[1] = 3;
    iVar4 = _io_connect_method_scalarI_scalarO(param_1[1],6,local_64,1,&local_48,local_64 + 1);
    if (iVar4 == 0) {
      uVar8 = param_1[0xf];
      if ((local_48 & 0xf) != (uVar8 & 0xf)) {
        if ((uVar8 & 0x33c0) != 0) {
          if (param_1[0x54] != 0) {
            return 0x2715;
          }
          param_1[0x55] = uVar8;
          return 0x2715;
        }
        uVar8 = local_48 & 0xf | uVar8 & 0xfffffff0;
        param_1[0xf] = uVar8;
        if (param_1[0x54] == 0) {
          param_1[0x55] = uVar8;
          FUN_00017260(param_1);
          uVar8 = param_1[0xf];
        }
      }
    }
    else {
      uVar8 = param_1[0xf];
    }
    if (param_2 != 0x5a) {
      iVar9 = *param_1;
      iVar4 = *param_3;
      iVar6 = param_3[1];
      pcVar3 = *(code **)(PTR_DAT_001e88ac + 0x14);
      iVar10 = *(int *)(PTR_DAT_001e88ac + 8);
    }
    else {
      iVar9 = *param_1;
      iVar4 = 0;
      iVar6 = 0;
      pcVar3 = *(code **)(PTR_DAT_001e88ac + 0x14);
      iVar10 = *(int *)(PTR_DAT_001e88ac + 8);
    }
    iVar4 = (*pcVar3)(iVar4,iVar6,param_3[2],uVar8 & 0x803f,*(undefined4 *)(iVar9 * 4 + iVar10));
    if (iVar4 == 0) {
      local_58 = param_3[2];
      local_54 = param_1[0xf] & 0xffff3fc0;
      local_50 = uVar12;
      local_4c = param_4 & 0xff;
      iVar4 = _io_connect_method_scalarI_structureI(param_1[1],0,&local_58,4,0,0);
      if ((iVar4 == 0) &&
         ((*(char *)((int)param_1 + 0x145) == '\0' ||
          (iVar4 = _io_connect_method_scalarI_structureI(param_1[1],0xe,param_1 + 0x4d,3,0,0),
          iVar4 == 0)))) {
        local_58 = (uint)*(byte *)((int)param_1 + 0x147);
        _io_connect_method_scalarI_structureI(param_1[1],0x10,&local_58,1,0,0);
LAB_00007320:
        local_68 = 4;
        uVar13 = 0x2715;
        iVar4 = _io_connect_method_scalarI_scalarO(param_1[1],5,0,0,&local_48,&local_68);
        if (iVar4 == 0) {
          local_68 = 3;
          uVar13 = 0x2715;
          iVar4 = _io_connect_method_scalarI_scalarO(param_1[1],3,0,0,param_1 + 9,&local_68);
          if (iVar4 == 0) {
            local_68 = 1;
            _io_connect_method_scalarI_scalarO(param_1[1],4,0,0,local_64 + 2,&local_68);
            if ((local_64[2] & 1U) == 0) {
              uVar13 = 0x2720;
              param_1[0x47] = local_40;
              param_1[0x48] = local_3c;
              param_1[0x41] = local_48;
              param_1[0x42] = local_44;
            }
            else if (param_3 == (int *)param_1[0x3e]) {
              if ((local_48 != param_1[0x41]) || (uVar13 = 0, local_44 != param_1[0x42])) {
                param_1[0x47] = local_40;
                param_1[0x48] = local_3c;
                uVar13 = 3;
                param_1[0x41] = local_48;
                param_1[0x42] = local_44;
              }
            }
            else {
              uVar13 = 2;
              param_1[0x47] = local_40;
              param_1[0x48] = local_3c;
              param_1[0x41] = local_48;
              param_1[0x42] = local_44;
            }
            if (*(char *)((int)param_1 + 0x141) != '\0') {
              iVar4 = 4;
              if (*(char *)((int)param_1 + 0x141) != '\x01') {
                iVar4 = 8;
              }
              sVar11 = iVar4 * (local_48 + 7 & 0xfffffff8) * local_44;
              if (sVar11 != param_1[0x53]) {
                if ((void *)param_1[0x52] != (void *)0x0) {
                  _free((void *)param_1[0x52]);
                }
                pvVar5 = _malloc(sVar11);
                param_1[0x53] = sVar11;
                param_1[0x52] = (int)pvVar5;
              }
            }
            ((int (*)())FUN_00007020)(param_1);
            param_1[0x3e] = (int)param_3;
            param_1[0x3f] = uVar12;
            param_1[0x40] = param_4 & 0xff;
            if (param_1[0x54] == 0) {
              param_1[0x55] = param_1[0xf];
              param_1[0x57] = param_1[0x41];
              param_1[0x58] = param_1[0x42];
              param_1[0x59] = param_1[0x43];
              param_1[0x5a] = param_1[0x44];
              param_1[0x5b] = param_1[0x45];
              param_1[0x5c] = param_1[0x46];
              return uVar13;
            }
            return uVar13;
          }
        }
        goto LAB_000077a0;
      }
      goto LAB_00007790;
    }
  }
  else {
    if (param_2 == 0x36) {
      if (param_3 == (int *)0x0) {
        return 0x2715;
      }
      uVar8 = param_1[0xf];
      param_1[0xf] = uVar8 & 0xffffffdf;
      if (((uVar8 & 0x400) != 0) || ((uVar8 & 0x10) != 0)) {
        param_1[0xf] = uVar8 & 0xffffffdf | 0x8000;
      }
      FUN_00017160(param_1,param_1 + 0xf,0);
      iVar6 = *param_1;
      iVar4 = iVar6 * 4;
      if (*(int *)(PTR_DAT_001e88ac + iVar4 + 0x18) == 0) {
        iVar4 = _IOServiceOpen(*(undefined4 *)(*(int *)(PTR_DAT_001e88ac + 8) + iVar4),
                               *(undefined4 *)PTR_001e88b4,0,PTR_DAT_001e88ac + iVar4 + 0x18);
        if (iVar4 != 0) goto LAB_00007780;
        iVar6 = *param_1;
      }
      puVar2 = PTR_DAT_001e88ac;
      iVar4 = *(int *)(PTR_DAT_001e88ac + 0xc);
      PTR_DAT_001e88ac[iVar6 + 0x98] = PTR_DAT_001e88ac[iVar6 + 0x98] + '\x01';
      local_58 = (uint)*(byte *)(iVar4 + *param_1);
      local_64[0] = 0;
      local_54 = param_1[0xf] & 0x803f;
      uVar8 = _io_connect_method_scalarI_scalarO
                        (*(undefined4 *)(puVar2 + *param_1 * 4 + 0x18),7,&local_58,2,0,local_64);
      if (uVar8 == 0) {
        local_58 = ~(uint)*(byte *)(*(int *)(puVar2 + 0xc) + *param_1);
        local_54 = param_1[0xf] & 0xffff3fc0;
        local_50 = uVar8;
        local_4c = uVar8;
        iVar4 = _io_connect_method_scalarI_structureI(param_1[1],0,&local_58,4,0,0);
        if (iVar4 == 0) goto LAB_00007320;
      }
LAB_00007790:
      uVar13 = 0x2715;
      goto LAB_000077a0;
    }
    if (param_2 != 0x35) {
      if (param_2 != 0) {
        if (param_2 == 0x5b) {
          if (param_3 != (int *)0x0) {
            param_1[0x55] = param_3[3];
            param_1[0x56] = param_3[2];
            param_1[0x57] = (uint)*(ushort *)(*param_3 + 0x9a);
            uVar1 = *(ushort *)(*param_3 + 0x9c);
            param_1[0x5c] = 0;
            param_1[0x59] = 0;
            param_1[0x5a] = 0;
            param_1[0x5b] = 0;
            param_1[0x58] = (uint)uVar1;
            _memcpy((void *)(param_1[5] + 0x24),param_3 + 4,0x3c);
            *(uint *)param_1[5] = *(uint *)param_1[5] & 0xfffffffd;
            return 0;
          }
          param_1[0x55] = param_1[0xf];
          param_1[0x56] = param_1[0xe];
          param_1[0x57] = param_1[0x41];
          param_1[0x58] = param_1[0x42];
          param_1[0x59] = param_1[0x43];
          param_1[0x5a] = param_1[0x44];
          param_1[0x5b] = param_1[0x45];
          param_1[0x5c] = param_1[0x46];
          _memcpy((void *)(param_1[5] + 0x24),param_1 + 0x10,0x3c);
          if (*(char *)((int)param_1 + 0x143) == '\0') {
            *(uint *)param_1[5] = *(uint *)param_1[5] & 0xfffffffd;
            return 0;
          }
          *(uint *)param_1[5] = *(uint *)param_1[5] | 2;
          return 0;
        }
        uVar13 = 0x271a;
        goto LAB_000077a0;
      }
      if (param_3 == (int *)0x0) {
        uVar13 = 1;
        goto LAB_000077a0;
      }
    }
  }
LAB_00007780:
  uVar13 = 0x2715;
LAB_000077a0:
  ((int (*)())FUN_00007020)(param_1);
  local_54 = 0;
  local_58 = 0;
  _io_connect_method_scalarI_structureI(param_1[1],0,&local_58,4,0,0);
  return uVar13;
}

/* FUN_00007810 @ 0x7810 (20 bytes) */
int FUN_00007810(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if (*(int *)(param_1 + 0x178) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x178) = param_2;
  return;
}

/* _gldGetError @ 0x7830 (20 bytes) */
int _gldGetError(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x178);
  *(undefined4 *)(param_1 + 0x178) = 0;
  return uVar1;
}

/* _gldCreateFence @ 0x7850 (408 bytes) */
int _gldCreateFence(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  piVar3 = _malloc(8);
  piVar3[1] = 0;
  *piVar3 = 0;
  puVar1 = PTR_001e88b4;
  do {
    uVar10 = *(uint *)(param_1 + 0x21c) >> 8;
    if (uVar10 != 0) {
      puVar6 = *(uint **)(param_1 + 0x220);
      uVar7 = *puVar6;
      if (uVar7 != 0xffffffff) {
        iVar2 = 0;
        iVar4 = 0;
LAB_00007950:
        iVar11 = 0x20;
        uVar10 = 0;
        break;
      }
      iVar2 = 0;
      puVar8 = puVar6;
      while( true ) {
        iVar2 = iVar2 + 1;
        puVar8 = puVar8 + 1;
        uVar10 = uVar10 - 1;
        if (uVar10 == 0) break;
        uVar7 = *puVar8;
        iVar4 = iVar2 * 4;
        if (uVar7 != 0xffffffff) goto LAB_00007950;
      }
    }
    iVar4 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 4),4,*(undefined4 *)puVar1,param_1 + 0x218
                                ,param_1 + 0x21c,1);
    if (iVar4 != 0) {
      _free(piVar3);
      *param_2 = 0;
      return 0x2720;
    }
    pvVar5 = _realloc(*(void **)(param_1 + 0x220),*(uint *)(param_1 + 0x21c) >> 5);
    *(void **)(param_1 + 0x220) = pvVar5;
    uVar10 = *(uint *)(param_1 + 0x21c) >> 6;
    _memset((void *)((int)pvVar5 + uVar10),0,uVar10);
  } while( true );
  while( true ) {
    uVar9 = uVar10 + 1;
    iVar11 = iVar11 + -1;
    uVar10 = uVar9;
    if (iVar11 == 0) break;
    uVar9 = uVar10;
    if ((uVar7 >> (uVar10 & 0x3f) & 1) == 0) goto LAB_0000797c;
  }
  uVar10 = 0x20;
LAB_0000797c:
  iVar2 = uVar9 + iVar2 * 0x20;
  *(uint *)((int)puVar6 + iVar4) = 1 << (uVar10 & 0x3f) | *(uint *)((int)puVar6 + iVar4);
  *piVar3 = iVar2;
  *(undefined4 *)(iVar2 * 8 + *(int *)(param_1 + 0x218)) =
       *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x18);
  *(undefined4 *)(*piVar3 * 8 + *(int *)(param_1 + 0x218) + 4) = 0;
  *param_2 = piVar3;
  *(undefined1 *)(piVar3 + 1) = 1;
  return 0;
}

/* _gldDestroyFence @ 0x79f0 (76 bytes) */
int _gldDestroyFence(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_2 >> 3 & 0x1ffffffc;
  uVar1 = *param_2 & 0x1f;
  *(uint *)(uVar2 + *(int *)(param_1 + 0x220)) =
       (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & *(uint *)(uVar2 + *(int *)(param_1 + 0x220));
  _free(param_2);
  return 0;
}

/* _gldTestObject @ 0x7a40 (232 bytes) */
int _gldTestObject(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  uint uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 1) {
    uVar1 = FUN_0000abf0(param_1,param_3);
  }
  else if (param_2 == 0) {
    bVar2 = *(byte *)(param_3 + 1);
    if (bVar2 == 0) {
      iVar3 = *param_3;
      iVar4 = *(int *)(param_1 + 0x218);
      if (*(int *)(iVar3 * 8 + iVar4 + 4) != 0) {
        _gldFlush();
        iVar3 = *param_3;
        iVar4 = *(int *)(param_1 + 0x218);
      }
      bVar2 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 * 8 + iVar4));
      *(byte *)(param_3 + 1) = bVar2;
    }
    uVar1 = (uint)bVar2;
  }
  else if (param_2 == 2) {
    uVar1 = FUN_0000b980(param_1,param_3);
  }
  else {
    uVar1 = 1;
    if (param_2 == 3) {
      uVar1 = FUN_00005eb0(param_1,param_3);
    }
  }
  return uVar1;
}

/* _gldFinishObject @ 0x7b30 (300 bytes) */
int _gldFinishObject(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 1) {
    FUN_0000aaf0(param_1,param_3);
    uVar1 = 0;
  }
  else if (param_2 == 0) {
    if (*(char *)(param_3 + 1) == '\0') {
      iVar3 = *param_3;
      iVar2 = *(int *)(param_1 + 0x218);
      if (*(int *)(iVar3 * 8 + iVar2 + 4) != 0) {
        _gldFlush();
        iVar3 = *param_3;
        iVar2 = *(int *)(param_1 + 0x218);
      }
      iVar2 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 * 8 + iVar2));
      *(char *)(param_3 + 1) = (char)iVar2;
      if (iVar2 == 0) {
        _io_connect_method_scalarI_structureI
                  (*(undefined4 *)(param_1 + 4),9,*param_3 * 8 + *(int *)(param_1 + 0x218),1,0,0);
        *(undefined1 *)(param_3 + 1) = 1;
        return 0;
      }
    }
    uVar1 = 0;
  }
  else if (param_2 == 2) {
    FUN_0000b880(param_1,param_3);
    uVar1 = 0;
  }
  else {
    uVar1 = 0x271a;
    if (param_2 == 3) {
      FUN_00005db0(param_1,param_3);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* _gldCreateFramebuffer @ 0x7c70 (104 bytes) */
int _gldCreateFramebuffer(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = _calloc(1,200);
  *puVar2 = param_3;
  puVar2[1] = param_4;
  iVar3 = 6;
  puVar1 = puVar2;
  do {
    puVar1[0x13] = 0;
    puVar1 = puVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_2 = puVar2;
  return 0;
}

/* _gldReclaimFramebuffer @ 0x7ce0 (4 bytes) */
int _gldReclaimFramebuffer()
{
  return;
}

/* _gldDestroyFramebuffer @ 0x7cf0 (96 bytes) */
int _gldDestroyFramebuffer(param_1, param_2)
  int param_1;
  void *param_2;
{
  if (*(void **)(param_1 + 0x150) == param_2) {
    FUN_0001b4b0();
    *(undefined4 *)(param_1 + 0x150) = 0;
  }
  _free(param_2);
  return 0;
}

/* FUN_00007d50 @ 0x7d50 (368 bytes) */
int FUN_00007d50(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  char in_RESERVE;
  byte in_cr0;
  int iVar7;
  
  iVar4 = *(int *)(param_1 + 0x150);
  bVar1 = iVar4 != 0;
  piVar6 = *(int **)(*(int *)(param_1 + 0x18) + 0x1a0);
  if (bVar1) {
    iVar7 = 6;
    do {
      if (*(int *)(iVar4 + 0x4c) != 0) {
        piVar5 = (int *)(*(int *)(iVar4 + 0x4c) + 0x10);
        do {
          if (in_RESERVE != '\0') {
            iVar3 = storeWordConditionalIndexed(*piVar5 + -0x10000,0,piVar5);
            *piVar5 = iVar3;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
      }
      iVar4 = iVar4 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  bVar2 = piVar6 == (int *)0x0;
  if ((!bVar2) && (*(int *)(*piVar6 + 0xa0) == 0)) {
    if (*(int *)(piVar6[1] + 0x18) == 0) {
      if (*(int *)(piVar6[1] + 0x1c) == 0) goto LAB_00007e28;
    }
    else {
      iVar4 = FUN_0001b510(param_1,piVar6);
      if (iVar4 != 0) goto LAB_00007e28;
    }
  }
  piVar6 = (int *)0x0;
  bVar2 = true;
LAB_00007e28:
  *(int **)(param_1 + 0x150) = piVar6;
  if (!bVar2) {
    iVar4 = 6;
    do {
      if (piVar6[0x13] != 0) {
        piVar5 = (int *)(piVar6[0x13] + 0x10);
        do {
          if (in_RESERVE != '\0') {
            iVar7 = storeWordConditionalIndexed(*piVar5 + 0x10000,0,piVar5);
            *piVar5 = iVar7;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
      }
      piVar6 = piVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if ((*(int *)(*(int *)(param_1 + 0x18) + 0x1a0) == 0) && (bVar1)) {
    FUN_0001b4b0(param_1);
    return;
  }
  return;
}

/* FUN_00007ec0 @ 0x7ec0 (256 bytes) */
int FUN_00007ec0(param_1)
  uint param_1;
{
  if (0x7f < param_1) {
    return 0x10000;
  }
  if (0x5f < param_1) {
    return 0x18000;
  }
  if (0x3f < param_1) {
    return 0x1c000;
  }
  if (0x2f < param_1) {
    return 0x1e000;
  }
  if (0x1f < param_1) {
    return 0x1f000;
  }
  if (0x17 < param_1) {
    return 0x1f800;
  }
  if (0xf < param_1) {
    return 0x1fc00;
  }
  if (0xb < param_1) {
    return 0x1fe00;
  }
  if (9 < param_1) {
    return 0x1ff00;
  }
  if (7 < param_1) {
    return 0x1ff80;
  }
  if (5 < param_1) {
    return 0x1ffc0;
  }
  if (param_1 == 5) {
    return 0x1ffe0;
  }
  if (3 < param_1) {
    return 0x1fff0;
  }
  if (param_1 == 3) {
    return 0x1fff8;
  }
  if (1 < param_1) {
    return 0x1fffc;
  }
  return (param_1 == 0) + 0x1fffe;
}

/* FUN_00007fc0 @ 0x7fc0 (112 bytes) */
int FUN_00007fc0(param_1)
  uint param_1;
{
  if (0x100 < param_1) {
    return 0;
  }
  if (0x80 < param_1) {
    return 0x30000000;
  }
  if (0x40 < param_1) {
    return 0xc000000;
  }
  if (0x20 < param_1) {
    return 0x3ff00000;
  }
  if (0x10 < param_1) {
    return 0x3fffc000;
  }
  if (8 < param_1) {
    return 0x3fffffc0;
  }
  if (param_1 != 0) {
    return 0x3ffffffc;
  }
  return 0xbffffffc;
}

/* FUN_00008030 @ 0x8030 (128 bytes) */
int FUN_00008030(param_1)
  uint param_1;
{
  if (0x20 < param_1) {
    return 0;
  }
  if (0x10 < param_1) {
    return 0x8000000;
  }
  if (0xc < param_1) {
    return 0xa800000;
  }
  if (8 < param_1) {
    return 0xaa00000;
  }
  if (4 < param_1) {
    return 0xaa9a928;
  }
  if (2 < param_1) {
    return 0xaa9a9a8;
  }
  if (param_1 == 2) {
    return 0xaada9a8;
  }
  if (param_1 != 0) {
    return 0xaadada8;
  }
  return 0xbffffffc;
}

/* _gldChoosePixelFormat @ 0x80b0 (1980 bytes) */
int _gldChoosePixelFormat(param_1, param_2)
  undefined4 *param_1;
  uint *param_2;
{
  undefined4 *puVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  void *pvVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  void *pvVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  uint uVar26;
  void *pvVar27;
  undefined4 *puVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  undefined4 local_194;
  uint local_190;
  uint local_18c;
  uint local_188;
  uint local_184;
  uint local_180;
  uint local_17c;
  uint local_178;
  undefined2 local_174;
  undefined2 local_172;
  undefined2 local_170;
  undefined2 local_16e;
  undefined4 local_16c;
  undefined1 local_168;
  undefined1 local_167;
  undefined1 local_166;
  undefined1 local_165;
  uint local_164;
  uint local_88;
  uint local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 *local_60;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0x271e;
  }
  *param_1 = 0;
  pcVar5 = _getenv("GL_REJECT_HW");
  if (pcVar5 != (char *)0x0) {
    return 0;
  }
  uVar31 = 0xfffffc;
  uVar13 = 0;
  uVar19 = 0;
  uVar14 = 0;
  local_64 = 0;
  local_68 = 0;
  local_6c = 0;
  local_70 = 0;
  local_74 = 0;
  local_78 = 0;
  uVar29 = *(uint *)PTR_DAT_001e88ac;
  local_7c = 0;
  uVar15 = 0;
  local_80 = 0;
  uVar20 = 0;
  uVar21 = 0;
  uVar22 = 0;
  uVar23 = 0;
  uVar25 = 0;
  uVar26 = 0;
  uVar17 = 0;
  uVar12 = 0;
  uVar30 = 0x510;
  uVar4 = 0;
  puVar10 = param_2;
  do {
    if (*puVar10 == 0) {
      local_84 = ((int (*)())FUN_00007ec0)();
      local_84 = local_84 & 0x1ffff;
      local_88 = ((int (*)())FUN_00007ec0)(uVar19);
      local_88 = local_88 & 0x1ffff;
      uVar22 = uVar21 + uVar20 + uVar22;
      if ((int)uVar13 < (int)uVar22) {
        uVar13 = uVar22;
      }
      uVar4 = uVar23 + uVar25 + uVar26 + uVar17;
      if ((int)uVar14 < (int)uVar4) {
        uVar14 = uVar4;
      }
      if (((int)uVar13 < 0x21) && ((int)uVar15 < 9)) {
        uVar31 = uVar31 & 0xff0fffff;
      }
      uVar4 = ((int (*)())FUN_00007fc0)(uVar13);
      uVar13 = ((int (*)())FUN_00008030)(uVar15);
      uVar14 = ((int (*)())FUN_00007fc0)(uVar14);
      uVar15 = ((int (*)())FUN_00008030)(uVar17);
      puVar2 = PTR_DAT_001e88ac;
      if (CONCAT22((short)local_78,(short)local_74) == 0) {
        local_6c = 0;
        local_70 = 0;
      }
      if (((uVar30 & 2) == 0) && ((uVar30 & 4) == 0)) {
        uVar30 = uVar30 | 1;
      }
      uVar17 = *(uint *)(PTR_DAT_001e88ac + 4);
      pvVar16 = (void *)0x0;
      if (uVar17 != 0) {
        local_60 = &local_194;
        uVar19 = 0;
        iVar18 = 0;
        do {
          piVar9 = *(int **)(puVar2 + 8);
          iVar11 = piVar9[uVar19];
          pvVar6 = pvVar16;
          if (iVar11 != 0) {
            if (uVar19 == 0) {
LAB_00008798:
              uVar21 = uVar19 + 1;
              uVar20 = 1 << (uVar19 & 0x3f);
              if (uVar21 < uVar17) {
                iVar7 = uVar17 - uVar21;
                piVar9 = piVar9 + uVar21;
                do {
                  if (iVar11 == *piVar9) {
                    uVar20 = uVar20 | 1 << (uVar21 & 0x3f);
                  }
                  uVar21 = uVar21 + 1;
                  piVar9 = piVar9 + 1;
                  iVar7 = iVar7 + -1;
                } while (iVar7 != 0);
              }
              uVar20 = uVar20 & uVar29;
              if (uVar20 != 0) {
                local_165 = 0;
                local_166 = 0;
                local_167 = 0;
                local_190 = 0;
                local_194 = 0;
                local_168 = (undefined1)local_6c;
                local_16c = local_70;
                local_16e = (undefined2)local_74;
                local_170 = (undefined2)local_78;
                local_172 = (undefined2)local_7c;
                local_174 = (undefined2)local_80;
                local_178 = local_84;
                local_17c = local_88;
                local_18c = uVar30;
                if ((uVar20 & uVar20 - 1) != 0) {
                  local_18c = uVar30 | 0x200;
                }
                local_188 = uVar12;
                local_184 = uVar31 & uVar4 & uVar13;
                local_180 = uVar14 & 0xbffffffc & uVar15;
                local_164 = uVar20;
                local_190 = FUN_00017720(uVar19);
                local_190 = local_190 | uVar19 << 0x18;
                iVar11 = FUN_0001ae20(local_60,local_68,local_64);
                if (iVar11 != 0) {
                  iVar18 = iVar18 + iVar11;
                  pvVar6 = _malloc(iVar18 * 0x34);
                  if (pvVar6 == (void *)0x0) {
                    if (pvVar16 != (void *)0x0) {
                      _free(pvVar16);
                      return 0x2720;
                    }
                    return 0x2720;
                  }
                  iVar7 = iVar18 - iVar11;
                  if (iVar7 < 1) {
                    iVar7 = 0;
                  }
                  else {
                    iVar24 = 0;
                    pvVar27 = pvVar16;
                    puVar1 = pvVar6;
                    do {
                      iVar24 = iVar24 + 1;
                      _memcpy(puVar1,pvVar27,0x34);
                      *puVar1 = puVar1 + 0xd;
                      pvVar27 = (void *)((int)pvVar27 + 0x34);
                      puVar1 = puVar1 + 0xd;
                    } while (iVar7 != iVar24);
                  }
                  if (iVar7 < iVar18) {
                    iVar24 = 0;
                    puVar28 = local_60 + (iVar11 + (iVar7 - iVar18)) * 0xd;
                    puVar1 = (void *)((int)pvVar6 + iVar7 * 0x34);
                    do {
                      iVar24 = iVar24 + 1;
                      _memcpy(puVar1,puVar28,0x34);
                      *puVar1 = puVar1 + 0xd;
                      puVar28 = puVar28 + 0xd;
                      puVar1 = puVar1 + 0xd;
                    } while (iVar18 - iVar7 != iVar24);
                    iVar7 = iVar7 + iVar24;
                  }
                  *(undefined4 *)((int)pvVar6 + iVar7 * 0x34 + -0x34) = 0;
                  if (pvVar16 != (void *)0x0) {
                    _free(pvVar16);
                  }
                }
              }
            }
            else if (*piVar9 != iVar11) {
              iVar7 = 0;
              uVar20 = uVar19;
              do {
                iVar7 = iVar7 + 1;
                uVar20 = uVar20 - 1;
                if (uVar20 == 0) goto LAB_00008798;
              } while (piVar9[iVar7] != iVar11);
            }
          }
          uVar19 = uVar19 + 1;
          uVar17 = *(uint *)(puVar2 + 4);
          pvVar16 = pvVar6;
        } while (uVar19 < uVar17);
        if ((pvVar6 != (void *)0x0) && (iVar18 < 1)) {
          pvVar16 = (void *)0x0;
          _free(pvVar6);
        }
      }
      *param_1 = pvVar16;
      return 0;
    }
    puVar8 = puVar10 + 1;
    switch(*puVar10) {
    default:
      goto LAB_000089f0;
    case 2:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0;
      }
      break;
    case 3:
      local_80 = (int)*(short *)((int)puVar10 + 6);
      puVar8 = puVar10 + 2;
      break;
    case 4:
      break;
    case 5:
      uVar12 = uVar12 | 8;
      break;
    case 6:
      uVar12 = uVar12 | 2;
      break;
    case 7:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      local_7c = (int)(short)uVar3;
      break;
    case 8:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar13 < (int)uVar3) {
        uVar13 = uVar3;
      }
      break;
    case 0xb:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar15 < (int)uVar3) {
        uVar15 = uVar3;
      }
      break;
    case 0xc:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar19 < (int)uVar3) {
        uVar19 = uVar3;
      }
      break;
    case 0xd:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar4 < (int)uVar3) {
        uVar4 = uVar3;
      }
      break;
    case 0xe:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar14 < (int)uVar3) {
        uVar14 = uVar3;
      }
      break;
    case 0x14:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar20 < (int)uVar3) {
        uVar20 = uVar3;
      }
      break;
    case 0x15:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar21 < (int)uVar3) {
        uVar21 = uVar3;
      }
      break;
    case 0x16:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar22 < (int)uVar3) {
        uVar22 = uVar3;
      }
      break;
    case 0x17:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar23 < (int)uVar3) {
        uVar23 = uVar3;
      }
      break;
    case 0x18:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar25 < (int)uVar3) {
        uVar25 = uVar3;
      }
      break;
    case 0x19:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar26 < (int)uVar3) {
        uVar26 = uVar3;
      }
      break;
    case 0x1a:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      if ((int)uVar17 < (int)uVar3) {
        uVar17 = uVar3;
      }
      break;
    case 0x33:
      local_68 = 1;
      break;
    case 0x34:
      local_64 = 1;
      break;
    case 0x35:
      uVar30 = uVar30 | 4;
      break;
    case 0x36:
      uVar30 = uVar30 | 2;
      break;
    case 0x37:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      local_78 = (int)(short)uVar3;
      break;
    case 0x38:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      if ((int)uVar3 < 0) {
        return 0x2718;
      }
      local_74 = (int)(short)uVar3;
      break;
    case 0x39:
      uVar30 = uVar30 | 0x800;
      break;
    case 0x3a:
      uVar31 = 0x3f000000;
      break;
    case 0x3b:
      local_70 = 2;
      break;
    case 0x3c:
      local_70 = 1;
      break;
    case 0x3d:
      local_6c = 1;
      break;
    case 0x4c:
      uVar30 = uVar30 | 8;
      break;
    case 0x50:
      uVar30 = uVar30 | 1;
      break;
    case 0x54:
      uVar3 = *puVar8;
      puVar8 = puVar10 + 2;
      uVar29 = uVar29 & uVar3;
      break;
    case 0x5a:
      uVar30 = uVar30 | 0x2000;
    }
    puVar10 = puVar8;
  } while ((int)puVar8 - (int)param_2 < 0x94);
LAB_000089f0:
  return 10000;
}

/* _gldDestroyPixelFormat @ 0x8a10 (52 bytes) */
int _gldDestroyPixelFormat(param_1)
  void *param_1;
{
  undefined4 uVar1;
  
  uVar1 = 0x271e;
  if (param_1 != (void *)0x0) {
    _free(param_1);
    uVar1 = 0;
  }
  return uVar1;
}

/* _gldGetRendererInfo @ 0x8a50 (500 bytes) */
int _gldGetRendererInfo(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  undefined4 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  if (((*(uint *)PTR_DAT_001e88ac & param_2) == 0) || ((param_2 & ~*(uint *)PTR_DAT_001e88ac) != 0))
  {
    uVar1 = 0x2719;
  }
  else {
    iVar4 = *(int *)(PTR_DAT_001e88ac + 4);
    if ((iVar4 == 0) || ((param_2 & 1) != 0)) {
      iVar6 = 0;
    }
    else {
      uVar2 = 0;
      iVar6 = iVar4;
      do {
        uVar2 = uVar2 + 1;
        iVar6 = iVar6 + -1;
        if (iVar6 == 0) {
          iVar6 = iVar4 << 2;
          goto LAB_00008ad4;
        }
      } while ((param_2 & 1 << (uVar2 & 0x3f)) == 0);
      iVar6 = uVar2 * 4;
    }
LAB_00008ad4:
    piVar3 = *(int **)(PTR_DAT_001e88ac + 8);
    iVar6 = *(int *)((int)piVar3 + iVar6);
    if ((iVar4 == 0) || (iVar6 == *piVar3)) {
      iVar5 = 0;
    }
    else {
      iVar5 = 0;
      do {
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) break;
      } while (iVar6 != piVar3[iVar5]);
    }
    iVar4 = _IOServiceOpen(iVar6,*(undefined4 *)PTR_001e88b4,1,&local_34);
    uVar1 = 0x271f;
    if (iVar4 == 0) {
      local_38 = 3;
      iVar4 = _io_connect_method_scalarI_scalarO(local_34,3,0,0,&local_30,&local_38);
      if (iVar4 == 0) {
        *param_1 = 0;
        uVar2 = FUN_00017720(iVar5);
        *(undefined2 *)(param_1 + 8) = 0;
        *(undefined2 *)((int)param_1 + 0x22) = 0;
        *(undefined2 *)(param_1 + 9) = 0;
        *(undefined2 *)((int)param_1 + 0x26) = 0;
        *(undefined2 *)(param_1 + 10) = 0;
        param_1[0xb] = 0;
        param_1[0xc] = local_28;
        param_1[0xd] = local_2c;
        param_1[3] = 0xd;
        param_1[2] = 0xa513;
        param_1[1] = uVar2 | iVar5 << 0x18;
        param_1[6] = 0x1c01;
        param_1[4] = 0x8400;
        param_1[5] = 0x808000;
        *(undefined1 *)((int)param_1 + 0x2a) = 0;
        param_1[7] = 0x80;
        FUN_0001b150(param_1,local_30);
        _IOServiceClose(local_34);
        uVar1 = 0;
      }
      else {
        _IOServiceClose(local_34);
        uVar1 = 0x271f;
      }
    }
  }
  return uVar1;
}

/* _gldInitializeLibrary @ 0x8c60 (156 bytes) */
int _gldInitializeLibrary(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  puVar1 = PTR_DAT_001e88ac;
  uVar3 = 0;
  *(undefined4 *)(PTR_DAT_001e88ac + 0xc) = param_2;
  *(undefined4 *)(puVar1 + 8) = param_1;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(uint *)puVar1 = param_3;
  puVar4 = (undefined4 *)(puVar1 + 0x18);
  do {
    *puVar4 = 0;
    puVar1[uVar3 + 0x98] = 0;
    if ((1 << (uVar3 & 0x3f) & param_3) != 0) {
      *(uint *)(puVar1 + 4) = uVar3 + 1;
    }
    puVar2 = PTR_DAT_001e88ac;
    puVar4 = puVar4 + 1;
    uVar3 = uVar3 + 1;
  } while ((int)uVar3 < 0x20);
  *(undefined4 *)(PTR_DAT_001e88ac + 0x14) = param_5;
  *(undefined4 *)(puVar2 + 0x10) = param_4;
  return;
}

/* _gldTerminateLibrary @ 0x8d10 (56 bytes) */
int _gldTerminateLibrary()
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e88ac;
  *(undefined4 *)(PTR_DAT_001e88ac + 0x14) = 0;
  *(undefined4 *)(puVar1 + 8) = 0;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined4 *)puVar1 = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 0x10) = 0;
  return;
}

/* _gldIsTextureResident @ 0x8d50 (16 bytes) */
int _gldIsTextureResident(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(int *)(param_2 + 0x34) != 0;
}

/* _gldCreateTexture @ 0x8d60 (164 bytes) */
int _gldCreateTexture(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = _calloc(1,0xd8);
  *param_2 = puVar1;
  puVar1[0xc] = param_3;
  puVar1[0xd] = 0;
  *puVar1 = 0;
  puVar1[1] = 3;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[8] = puVar1 + 6;
  puVar1[7] = 0;
  *(undefined1 *)((int)puVar1 + 0x39) = 3;
  *(undefined2 *)((int)puVar1 + 0x2e) = 0;
  *(undefined1 *)(puVar1 + 0xe) = 0;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  *(undefined2 *)(puVar1 + 10) = 0;
  *(undefined2 *)((int)puVar1 + 0x2a) = 0;
  *(undefined2 *)(puVar1 + 0xb) = 0;
  puVar1[6] = puVar1 + 7;
  return 0;
}

/* _gldCreateTextureLevel @ 0x8e10 (76 bytes) */
int _gldCreateTextureLevel(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  *(byte *)(param_2 + 0x39) = param_3 | *(byte *)(param_2 + 0x39);
  if ((param_3 & 1) != 0) {
    *(undefined1 *)(param_2 + 0x38) = 0;
  }
  if ((param_3 & 7) != 0) {
    param_2 = param_4 * 2 + param_2;
    *(ushort *)(param_2 + 0x24) = (ushort)(1 << (param_5 & 0x3f)) | *(ushort *)(param_2 + 0x24);
  }
  return 0;
}

/* _gldModifyTexture @ 0x8e60 (20 bytes) */
int _gldModifyTexture(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  *(byte *)(param_2 + 0x39) = param_3 | *(byte *)(param_2 + 0x39);
  return 0;
}

/* _gldModifyTextureLevel @ 0x8e80 (204 bytes) */
int _gldModifyTextureLevel(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x34);
  if (param_4 == 0xffffffff) {
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 0x40;
  }
  else {
    iVar2 = param_3 * 2 + param_2;
    uVar1 = *(ushort *)(iVar2 + 0x24);
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 4;
    *(ushort *)(iVar2 + 0x24) = (ushort)(1 << (param_4 & 0x3f)) | uVar1;
  }
  if ((iVar3 != 0) && ((byte)(*(char *)(iVar3 + 0x16) - 6U) < 2)) {
    if (0x1ffff < *(int *)(iVar3 + 0x10)) {
      _gldFlush(param_1);
    }
    FUN_0000aaf0(param_1,param_2);
  }
  return 0;
}

/* _gldGetTextureLevelInfo @ 0x8f60 (520 bytes) */
int _gldGetTextureLevelInfo(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined *param_5;
  uint *param_6;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  byte local_34;
  
  FUN_00030f60();
  if ((**(ushort **)(param_2 + 0x30) & 0x100) != 0) {
    uVar1 = FUN_0000a9f0(param_1,param_2);
    iVar3 = param_1;
    do {
      if (*(int *)(iVar3 + 0x18c) != 0) {
        iVar2 = FUN_0000a9f0(param_1);
        uVar1 = uVar1 + iVar2;
      }
      iVar3 = iVar3 + 4;
    } while (param_1 + 0x40 != iVar3);
    if (*(uint *)(param_1 + 0x28) < uVar1) {
      *param_6 = 0;
      return 0x2720;
    }
  }
  if (param_5 == (undefined *)0x805f) {
    *param_6 = local_48;
    return 0;
  }
  if (param_5 < (undefined *)0x8060) {
    if (param_5 == (undefined *)0x805c) {
      *param_6 = local_54;
      return 0;
    }
    if (param_5 < (undefined *)0x805d) {
      if (param_5 == ((unsigned char *)0x00001003)) {
        *param_6 = local_58;
        return 0;
      }
    }
    else {
      if (param_5 == (undefined *)0x805d) {
        *param_6 = local_50;
        return 0;
      }
      if (param_5 == (undefined *)0x805e) {
        *param_6 = local_4c;
        return 0;
      }
    }
  }
  else {
    if (param_5 == (undefined *)0x86a0) {
      *param_6 = local_38;
      return 0;
    }
    if (param_5 < (undefined *)0x86a1) {
      if (param_5 == (undefined *)0x8060) {
        *param_6 = local_44;
        return 0;
      }
      if (param_5 == (undefined *)0x8061) {
        *param_6 = local_40;
        return 0;
      }
    }
    else {
      if (param_5 == (undefined *)0x86a1) {
        *param_6 = (uint)local_34;
        return 0;
      }
      if (param_5 == (undefined *)0x884a) {
        *param_6 = local_3c;
        return 0;
      }
    }
  }
  return 0;
}

/* _gldDeleteTextureLevel @ 0x9180 (264 bytes) */
int _gldDeleteTextureLevel(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  
  if (param_4 == 0xffffffff) {
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 0x43;
  }
  else {
    iVar5 = param_3 * 2 + param_2;
    uVar1 = *(ushort *)(iVar5 + 0x24);
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 7;
    *(ushort *)(iVar5 + 0x24) = (ushort)(1 << (param_4 & 0x3f)) | uVar1;
  }
  iVar5 = *(int *)(param_2 + 0x34);
  if ((iVar5 != 0) && ((byte)(*(char *)(iVar5 + 0x16) - 6U) < 2)) {
    if (0x1ffff < *(int *)(iVar5 + 0x10)) {
      _gldFlush(param_1);
    }
    piVar3 = (int *)(iVar5 + 0x10);
    do {
      iVar4 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar4 + -0x10000,0,piVar3);
        *piVar3 = iVar2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar4 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
    *(undefined4 *)(param_2 + 0x34) = 0;
  }
  return 0;
}

/* _gldReclaimTexture @ 0x9290 (396 bytes) */
int _gldReclaimTexture(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char in_RESERVE;
  byte in_cr0;
  
  iVar5 = 0;
  iVar6 = param_1;
  do {
    if (param_2 == *(int *)(iVar6 + 0x18c)) {
      *(undefined4 *)(iVar6 + 0x18c) = 0;
      FUN_000307a0(param_1,iVar5);
    }
    bVar1 = iVar5 != 0xf;
    iVar6 = iVar6 + 4;
    iVar5 = iVar5 + 1;
  } while (bVar1);
  iVar6 = *(int *)(param_2 + 0x34);
  if (iVar6 != 0) {
    if ((0x1ffff < (int)*(uint *)(iVar6 + 0x10)) || ((*(uint *)(iVar6 + 0x10) & 0xffff) != 0)) {
      _gldFlush(param_1);
    }
    FUN_0000aaf0(param_1,param_2);
    piVar3 = (int *)(iVar6 + 0x10);
    do {
      iVar5 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar5 + -0x10000,0,piVar3);
        *piVar3 = iVar2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar5 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar6,1,0,0);
    }
    *(undefined4 *)(param_2 + 0x34) = 0;
  }
  while( true ) {
    piVar3 = *(int **)(param_2 + 0x18);
    if (*piVar3 == 0) break;
    piVar4 = (int *)piVar3[1];
    *piVar4 = *piVar3;
    iVar6 = *piVar3;
    *piVar3 = 0;
    *(int **)(iVar6 + 4) = piVar4;
    piVar3[1] = 0;
    if (piVar3 == (int *)0x0) break;
    iVar6 = piVar3[4];
    piVar4 = (int *)(iVar6 + 0x10);
    do {
      iVar5 = *piVar4;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar5 + -0x10000,0,piVar4);
        *piVar4 = iVar2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar5 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar6,1,0,0);
    }
    piVar3[4] = 0;
    _free(piVar3);
  }
  *(undefined1 *)(param_2 + 0x39) = 0x23;
  return;
}

/* _gldDeleteTexture @ 0x9420 (56 bytes) */
int _gldDeleteTexture(param_1, param_2)
  undefined4 param_1;
  void *param_2;
{
  ((int (*)())_gldReclaimTexture)();
  _free(param_2);
  return 0;
}

/* _gldCreatePipelineProgram @ 0x9460 (80 bytes) */
int _gldCreatePipelineProgram(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = _calloc(1,0x40);
  *param_2 = puVar1;
  *puVar1 = param_3;
  puVar1[0xf] = 3;
  return 0;
}

/* _gldModifyPipelineProgram @ 0x94b0 (48 bytes) */
int _gldModifyPipelineProgram(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  uint param_3;
{
  *(uint *)(param_2 + 0x3c) = param_3 | *(uint *)(param_2 + 0x3c);
  FUN_00024fd0();
  return 0;
}

/* _gldRelatePipelineProgram @ 0x94e0 (84 bytes) */
int _gldRelatePipelineProgram(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 *param_3;
  int param_4;
{
  if (*(short *)*param_3 == -0x74d0) {
    if (param_4 == 0) {
      param_3 = (undefined4 *)0x0;
    }
    *(undefined4 **)(param_2 + 8) = param_3;
  }
  else if (*(short *)*param_3 == -0x74cf) {
    if (param_4 == 0) {
      param_3 = (undefined4 *)0x0;
    }
    *(undefined4 **)(param_2 + 4) = param_3;
  }
  return 0;
}

/* _gldGetPipelineProgramInfo @ 0x9540 (36 bytes) */
int _gldGetPipelineProgramInfo()
{
  FUN_000269a0();
  return 0;
}

/* _gldDestroyPipelineProgram @ 0x9570 (104 bytes) */
int _gldDestroyPipelineProgram(param_1, param_2)
  int param_1;
  void *param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = param_1;
  do {
    if (param_2 == *(void **)(iVar2 + 0x1cc)) {
      *(undefined4 *)(iVar2 + 0x1cc) = 0;
    }
    bVar1 = iVar3 != 1;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  FUN_00025bf0(param_1,param_2);
  _free(param_2);
  return 0;
}

/* FUN_000095e0 @ 0x95e0 (192 bytes) */
int FUN_000095e0(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar3 = 0;
  iVar4 = param_1;
  do {
    iVar2 = iVar3 * 4 + *(int *)(param_1 + 0x18);
    piVar5 = *(int **)(iVar2 + 0x198);
    if (piVar5 == (int *)0x0) {
      if (((unsigned char *)0x00004304)[iVar3 * 8 + *(int *)(param_1 + 0x10)] != '\0') {
        piVar5 = *(int **)(iVar2 + 0x18c);
        goto LAB_00009640;
      }
      *(undefined4 *)(iVar4 + 0x1cc) = 0;
    }
    else {
LAB_00009640:
      if ((*(int *)(*piVar5 + 4) == 0) || (iVar2 = FUN_00026650(param_1,piVar5), iVar2 == 0)) {
        *(undefined4 *)(iVar4 + 0x1cc) = 0;
      }
      else {
        *(int **)(iVar4 + 0x1cc) = piVar5;
      }
    }
    bVar1 = iVar3 == 1;
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_000096b0 @ 0x96b0 (72 bytes) */
int FUN_000096b0(param_1, param_2, param_3, param_4)
  uint param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 *param_4;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  *param_4 = 4;
  switch(param_1 >> 0x10 & 0x1f) {
  case 0:
  case 1:
  case 9:
  case 0xf:
    return;
  case 2:
    *param_3 = (param_1 & 0xffff) * 0x10 + 0x10;
    return;
  case 3:
    uVar2 = param_1 & 0xff;
    switch(param_1 >> 8 & 0xf) {
    case 0:
      *param_3 = uVar2 * 0x80 + 0x24c0;
      return;
    case 1:
      *param_3 = uVar2 * 0x80 + 0x24d0;
      return;
    case 2:
      *param_3 = uVar2 * 0x80 + 0x24e0;
      return;
    case 3:
      *param_3 = uVar2 * 0x80 + 0x24f0;
      return;
    case 4:
      *param_3 = uVar2 * 0x80 + 0x2500;
      return;
    case 5:
      *param_3 = uVar2 * 0x80 + 0x2510;
      return;
    case 6:
      *param_3 = uVar2 * 0x80 + 0x2520;
      return;
    default:
      return;
    }
  case 4:
    uVar3 = param_1 & 0xff;
    uVar1 = param_1 >> 9 & 3;
    uVar2 = param_1 >> 8 & 1;
    if (uVar1 == 1) {
      *param_3 = uVar2 * 0x240 + uVar3 * 0x30 + 0x2920;
      return;
    }
    if (uVar1 == 2) {
      *param_3 = uVar2 * 0x240 + uVar3 * 0x30 + 0x2930;
      return;
    }
    if (uVar1 == 0) {
      *param_3 = uVar2 * 0x240 + uVar3 * 0x30 + 0x2910;
      return;
    }
    return;
  case 5:
    uVar2 = param_1 & 1;
    switch(param_1 >> 1 & 7) {
    case 0:
      *param_3 = uVar2 * 0x240 + 0x28c0;
      return;
    case 1:
      *param_3 = uVar2 * 0x240 + 0x28d0;
      return;
    case 2:
      *param_3 = uVar2 * 0x240 + 0x28e0;
      return;
    case 3:
      *param_3 = uVar2 * 0x240 + 0x28f0;
      return;
    case 4:
      *param_3 = uVar2 * 0x240 + 0x2900;
      return;
    case 5:
      *param_3 = uVar2 * 0x240 + 0x2a90;
      return;
    default:
      return;
    }
  case 6:
    *param_3 = 0x24b0;
    return;
  case 7:
    break;
  case 8:
    uVar2 = param_1 >> 5 & 7;
    param_1 = param_1 & 0x1f;
    if (uVar2 == 1) {
      *param_3 = (int)(((unsigned char *)0x000039c0) + param_1 * 0x94);
      return;
    }
    if (uVar2 < 2) {
      if (uVar2 == 0) {
        *param_3 = (int)(((unsigned char *)0x0000399c) + param_1 * 0x94);
        return;
      }
      return;
    }
    if (uVar2 == 2) {
      *param_3 = (int)(((unsigned char *)0x000039e4) + param_1 * 0x94);
      return;
    }
    if (uVar2 == 3) {
      *param_3 = (int)(((unsigned char *)0x00003a08) + param_1 * 0x94);
      return;
    }
    return;
  case 10:
    *param_3 = (int)(((unsigned char *)0x00003e2c) + (param_1 & 0xff) * 0x10);
    return;
  case 0xb:
    *param_3 = (int)((unsigned char *)0x00002de0);
    return;
  case 0xc:
    *param_3 = (int)((unsigned char *)0x00002df0);
    return;
  case 0xd:
    *param_3 = (int)((unsigned char *)0x000030bc);
    return;
  case 0xe:
    *param_3 = (int)((unsigned char *)0x000030cc);
    return;
  case 0x10:
    uVar2 = param_1 & 0xff;
    iVar4 = uVar2 << 6;
    switch(param_1 >> 8 & 7) {
    case 0:
      iVar4 = 0;
      break;
    case 1:
      iVar4 = 0xc0;
      break;
    case 2:
      iVar4 = 0x80;
      break;
    case 3:
      iVar4 = (uVar2 + 4) * 0x40;
      break;
    case 4:
      iVar4 = (uVar2 + 0x10) * 0x40;
      break;
    case 5:
      iVar4 = (uVar2 + 8) * 0x40;
    }
    uVar2 = param_1 >> 0xe & 3;
    if (uVar2 < 2) {
      *param_3 = iVar4 + 0x1860;
    }
    else {
      *param_3 = iVar4 + 0x1e60;
    }
    uVar1 = param_1 >> 0xc & 3;
    if (uVar2 < 3) {
      if (uVar2 != 0) {
        *param_3 = uVar1 * 0x10 + *param_3;
        return;
      }
    }
    else if (uVar2 != 3) {
      return;
    }
    *param_3 = uVar1 * 4 + *param_3;
    *param_4 = 0x10;
    return;
  default:
    return;
  }
  uVar2 = param_1 >> 5 & 7;
  param_1 = param_1 & 0x1f;
  if (uVar2 == 1) {
    *param_3 = (int)(((unsigned char *)0x000039b0) + param_1 * 0x94);
    return;
  }
  if (uVar2 < 2) {
    if (uVar2 == 0) {
      *param_3 = (int)(((unsigned char *)0x0000398c) + param_1 * 0x94);
      return;
    }
    return;
  }
  if (uVar2 == 2) {
    *param_3 = (int)(((unsigned char *)0x000039d4) + param_1 * 0x94);
    return;
  }
  if (uVar2 == 3) {
    *param_3 = (int)(((unsigned char *)0x000039f8) + param_1 * 0x94);
    return;
  }
  return;
}

/* FUN_0000973c @ 0x973c (20 bytes) */
int FUN_0000973c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  undefined2 uStack_16;
  
  *param_3 = (uint)uStack_16 * 0x10 + 0x10;
  return;
}

/* FUN_00009750 @ 0x9750 (48 bytes) */
int FUN_00009750(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  uint uVar1;
  uint uVar2;
  undefined4 uStack_18;
  
  uVar2 = uStack_18 & 0xff;
  uVar1 = uStack_18 >> 8 & 0xf;
  if (6 < uVar1) {
    return;
  }
                    
  switch(*(int *)(uVar1 * 4 + param_6 + 0xbc) + param_6 + 0xbc) {
  case 0x979c:
    *param_3 = uVar2 * 0x80 + 0x24c0;
    return;
  case 0x97ac:
    *param_3 = uVar2 * 0x80 + 0x24d0;
    return;
  case 0x97bc:
    *param_3 = uVar2 * 0x80 + 0x24e0;
    return;
  case 0x97cc:
    *param_3 = uVar2 * 0x80 + 0x24f0;
    return;
  case 0x97dc:
    *param_3 = uVar2 * 0x80 + 0x2500;
    return;
  case 0x97ec:
    *param_3 = uVar2 * 0x80 + 0x2510;
    return;
  case 0x97fc:
    *param_3 = uVar2 * 0x80 + 0x2520;
    return;
  }
}

/* FUN_0000979c @ 0x979c (16 bytes) */
int FUN_0000979c(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x80 + 0x24c0;
  return;
}

/* FUN_000097ac @ 0x97ac (16 bytes) */
int FUN_000097ac(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x80 + 0x24d0;
  return;
}

/* FUN_000097bc @ 0x97bc (16 bytes) */
int FUN_000097bc(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x80 + 0x24e0;
  return;
}

/* FUN_000097cc @ 0x97cc (16 bytes) */
int FUN_000097cc(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x80 + 0x24f0;
  return;
}

/* FUN_000097dc @ 0x97dc (16 bytes) */
int FUN_000097dc(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x80 + 0x2500;
  return;
}

/* FUN_000097ec @ 0x97ec (16 bytes) */
int FUN_000097ec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x80 + 0x2510;
  return;
}

/* FUN_000097fc @ 0x97fc (16 bytes) */
int FUN_000097fc(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x80 + 0x2520;
  return;
}

/* FUN_00009810 @ 0x9810 (112 bytes) */
int FUN_00009810(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uStack_18;
  
  uVar3 = uStack_18 & 0xff;
  uVar2 = uStack_18 >> 9 & 3;
  uVar1 = uStack_18 >> 8 & 1;
  if (uVar2 == 1) {
    *param_3 = uVar1 * 0x240 + uVar3 * 0x30 + 0x2920;
    return;
  }
  if (uVar2 != 2) {
    if (uVar2 != 0) {
      return;
    }
    *param_3 = uVar1 * 0x240 + uVar3 * 0x30 + 0x2910;
    return;
  }
  *param_3 = uVar1 * 0x240 + uVar3 * 0x30 + 0x2930;
  return;
}

/* FUN_00009880 @ 0x9880 (48 bytes) */
int FUN_00009880(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  uint uVar1;
  uint uVar2;
  undefined4 uStack_18;
  
  uVar2 = uStack_18 >> 1 & 7;
  uVar1 = uStack_18 & 1;
  if (5 < uVar2) {
    return;
  }
                    
  switch(*(int *)(uVar2 * 4 + param_6 + 0x1ec) + param_6 + 0x1ec) {
  case 0x98c8:
    *param_3 = uVar1 * 0x240 + 0x28c0;
    return;
  case 0x98d8:
    *param_3 = uVar1 * 0x240 + 0x28d0;
    return;
  case 0x98e8:
    *param_3 = uVar1 * 0x240 + 0x28e0;
    return;
  case 0x98f8:
    *param_3 = uVar1 * 0x240 + 0x28f0;
    return;
  case 0x9908:
    *param_3 = uVar1 * 0x240 + 0x2900;
    return;
  case 0x9918:
    *param_3 = uVar1 * 0x240 + 0x2a90;
    return;
  }
}

/* FUN_000098c8 @ 0x98c8 (16 bytes) */
int FUN_000098c8(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int *param_3;
{
  int in_r11;
  
  *param_3 = in_r11 * 0x240 + 0x28c0;
  return;
}

/* FUN_00009b70 @ 0x9b70 (88 bytes) */
int FUN_00009b70(param_1)
  int param_1;
{
  undefined4 uVar1;
  void *pvVar2;
  
  pvVar2 = _calloc(1,0x18);
  uVar1 = 0x2720;
  *(void **)(param_1 + 0x234) = pvVar2;
  if (pvVar2 != (void *)0x0) {
    uVar1 = 0;
  }
  return uVar1;
}

/* FUN_00009bd0 @ 0x9bd0 (164 bytes) */
int FUN_00009bd0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = **(int **)(param_1 + 0x234);
  if (iVar2 != 0) {
    if ((0x1ffff < (int)*(uint *)(iVar2 + 0x10)) || ((*(uint *)(iVar2 + 0x10) & 0xffff) != 0)) {
      _gldFlush();
    }
    iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 8));
    if (iVar1 == 0) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar2 + 8,1,0,0);
      return;
    }
  }
  return;
}

/* _gldDestroyQuery @ 0x9c80 (76 bytes) */
int _gldDestroyQuery(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_2 >> 3 & 0x1ffffffc;
  uVar1 = *param_2 & 0x1f;
  *(uint *)(uVar2 + *(int *)(param_1 + 0x22c)) =
       (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & *(uint *)(uVar2 + *(int *)(param_1 + 0x22c));
  _free(param_2);
  return 0;
}

/* FUN_00009cd0 @ 0x9cd0 (152 bytes) */
int FUN_00009cd0(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = **(int **)(param_1 + 0x234);
  if (iVar4 != 0) {
    ((int (*)())FUN_00009bd0)();
    piVar2 = (int *)(iVar4 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
      **(undefined4 **)(param_1 + 0x234) = 0;
    }
  }
  return 0;
}

/* FUN_00009d70 @ 0x9d70 (248 bytes) */
int FUN_00009d70(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  int local_20;
  
  param_2[2] = param_3;
  param_2[3] = param_4;
  param_2[1] = 6;
  param_2[4] = param_5;
  iVar4 = *param_2;
  *param_2 = 0;
  local_28 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,auStack_24,&local_28);
  if (iVar3 == 0) {
    *param_2 = local_20;
    piVar2 = (int *)(local_20 + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    *(undefined1 *)(local_20 + 0x14) = 1;
  }
  if (iVar4 != 0) {
    piVar2 = (int *)(iVar4 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
    }
  }
  return 1;
}

/* _gldCreateQuery @ 0x9e70 (532 bytes) */
int _gldCreateQuery(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  size_t sVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  piVar2 = _malloc(4);
  *piVar2 = 0;
  do {
    uVar10 = *(uint *)(param_1 + 0x230) >> 5;
    if (uVar10 != 0) {
      puVar6 = *(uint **)(param_1 + 0x22c);
      uVar7 = *puVar6;
      if (uVar7 != 0xffffffff) {
        iVar1 = 0;
        iVar3 = 0;
LAB_0000a030:
        iVar11 = 0x20;
        uVar10 = 0;
        break;
      }
      iVar1 = 0;
      puVar8 = puVar6;
      while( true ) {
        iVar1 = iVar1 + 1;
        puVar8 = puVar8 + 1;
        uVar10 = uVar10 - 1;
        if (uVar10 == 0) break;
        uVar7 = *puVar8;
        iVar3 = iVar1 * 4;
        if (uVar7 != 0xffffffff) goto LAB_0000a030;
      }
    }
    if ((*(int *)(param_1 + 0x234) == 0) && (iVar3 = ((int (*)())FUN_00009b70)(param_1), iVar3 == 0x2720)) {
LAB_0000a010:
      _free(piVar2);
      *param_2 = 0;
      return 0x2720;
    }
    if (*(int *)(param_1 + 0x228) == 0) {
      *(undefined4 *)(param_1 + 0x230) = 0x20;
      *(undefined4 *)(param_1 + 0x228) = 0x610;
      pvVar4 = _malloc(0x610);
      *(void **)(param_1 + 0x224) = pvVar4;
      _memset(pvVar4,0,*(size_t *)(param_1 + 0x228));
    }
    else {
      if (**(int **)(param_1 + 0x234) != 0) {
        ((int (*)())FUN_00009cd0)(param_1);
      }
      sVar5 = *(int *)(param_1 + 0x230) * 0x40 + 0x210;
      *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) << 1;
      *(size_t *)(param_1 + 0x228) = sVar5;
      pvVar4 = _realloc(*(void **)(param_1 + 0x224),sVar5);
      *(void **)(param_1 + 0x224) = pvVar4;
      if (pvVar4 == (void *)0x0) goto LAB_0000a010;
    }
    iVar3 = ((int (*)())FUN_00009d70)(param_1,*(undefined4 *)(param_1 + 0x234),*(undefined4 *)(param_1 + 0x224),
                         *(undefined4 *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x228));
    if (iVar3 != 1) goto LAB_0000a010;
    FUN_0002b3b0(param_1);
    uVar7 = *(uint *)(param_1 + 0x230);
    uVar10 = uVar7 >> 3;
    if (*(void **)(param_1 + 0x22c) == (void *)0x0) {
      pvVar4 = _malloc(uVar10);
      *(void **)(param_1 + 0x22c) = pvVar4;
      _memset(pvVar4,0,uVar10);
    }
    else {
      pvVar4 = _realloc(*(void **)(param_1 + 0x22c),uVar10);
      uVar7 = uVar7 >> 4;
      *(void **)(param_1 + 0x22c) = pvVar4;
      _memset((void *)((int)pvVar4 + uVar7),0,uVar7);
    }
  } while( true );
  while( true ) {
    uVar9 = uVar10 + 1;
    iVar11 = iVar11 + -1;
    uVar10 = uVar9;
    if (iVar11 == 0) break;
    uVar9 = uVar10;
    if ((uVar7 >> (uVar10 & 0x3f) & 1) == 0) goto LAB_0000a05c;
  }
  uVar10 = 0x20;
LAB_0000a05c:
  *(uint *)((int)puVar6 + iVar3) = 1 << (uVar10 & 0x3f) | *(uint *)((int)puVar6 + iVar3);
  *param_2 = piVar2;
  *piVar2 = uVar9 + iVar1 * 0x20;
  return 0;
}

/* FUN_0000a0a0 @ 0xa0a0 (68 bytes) */
int FUN_0000a0a0(param_1)
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
  if ((param_1 & 0x3f00000) != 0) {
    return 0x40;
  }
  return -(param_1 & 0xc000000) >> 0x18 & 0x80;
}

/* FUN_0000a0f0 @ 0xa0f0 (48 bytes) */
int FUN_0000a0f0(param_1)
  uint param_1;
{
  if ((param_1 & 0x1000) != 0) {
    return 0x20;
  }
  if ((param_1 & 0x800) != 0) {
    return 0x18;
  }
  if ((param_1 & 0x400) != 0) {
    return 0x10;
  }
  return param_1 >> 4 & 8;
}

/* FUN_0000a120 @ 0xa120 (92 bytes) */
int FUN_0000a120(param_1)
  uint param_1;
{
  if ((param_1 & 0x400) != 0) {
    return 1;
  }
  if ((param_1 & 0x40000) != 0) {
    return 2;
  }
  if ((param_1 & 0x80) != 0) {
    return 4;
  }
  if ((param_1 & 0x9a928) != 0) {
    return 8;
  }
  if ((param_1 & 0x200000) != 0) {
    return 0xc;
  }
  if ((param_1 & 0x2800000) != 0) {
    return 0x10;
  }
  return param_1 >> 0x16 & 0x20;
}

/* FUN_0000a180 @ 0xa180 (344 bytes) */
int FUN_0000a180(param_1, param_2)
  uint param_1;
  undefined2 *param_2;
{
  undefined2 uVar1;
  
  *param_2 = 0;
  param_2[4] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
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
                  param_2[2] = 0x20;
                  *param_2 = 0x20;
                  param_2[1] = 0x20;
                }
                else {
                  param_2[2] = 0x10;
                  *param_2 = 0x10;
                  param_2[1] = 0x10;
                }
              }
              else {
                param_2[2] = 0xc;
                *param_2 = 0xc;
                param_2[1] = 0xc;
              }
            }
            else {
              param_2[2] = 10;
              *param_2 = 10;
              param_2[1] = 10;
            }
          }
          else {
            param_2[2] = 8;
            *param_2 = 8;
            param_2[1] = 8;
          }
        }
        else {
          param_2[2] = 5;
          param_2[1] = 6;
          *param_2 = 5;
        }
      }
      else {
        param_2[2] = 5;
        *param_2 = 5;
        param_2[1] = 5;
      }
    }
    else {
      param_2[2] = 4;
      *param_2 = 4;
      param_2[1] = 4;
    }
  }
  else {
    param_2[1] = 3;
    param_2[2] = 2;
    *param_2 = 3;
  }
  uVar1 = ((int (*)())FUN_0000a120)();
  param_2[3] = uVar1;
  return 1;
}

