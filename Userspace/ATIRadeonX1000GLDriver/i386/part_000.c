#include "decls.h"

/* FUN_00000a6e @ 0xa6e (17 bytes) */
int FUN_00000a6e(param_1)
  undefined4 *param_1;
{
  *param_1 = 1;
  return;
}

/* FUN_00000a7f @ 0xa7f (68 bytes) */
int FUN_00000a7f(param_1)
  undefined4 *param_1;
{
  int iVar1;
  
  iVar1 = (*(code *)param_1[1])(0xa6e,param_1,param_1);
  if (iVar1 != 0) {
    *param_1 = 0xffffffff;
  }
  return;
}

/* FUN_00000ac3 @ 0xac3 (117 bytes) */
int FUN_00000ac3(param_1, param_2)
  code *param_1;
  code *param_2;
{
  int iVar1;
  int local_20;
  int local_14;
  code *local_10;
  
  local_14 = 0;
  local_10 = param_1;
  iVar1 = (*param_1)(0xa7f,&local_14,&local_14);
  if (iVar1 == 0) {
    (*param_2)(&local_14);
    if (local_14 == 0) {
      (*param_2)(&local_14);
      local_14 = 0;
    }
    local_20 = local_14;
  }
  else {
    local_20 = -1;
  }
  return local_20;
}

/* FUN_00000b38 @ 0xb38 (365 bytes) */
int FUN_00000b38()
{
  int iVar1;
  undefined4 uVar2;
  void *local_1c;
  void *local_18;
  int local_14;
  int local_10;
  
  iVar1 = __keymgr_get_and_lock_processwide_ptr_2(0xe,&local_1c);
  if (iVar1 != 0) {
    return (void *)0x0;
  }
  local_18 = local_1c;
  if ((local_1c == (void *)0x0) && (local_18 = _calloc(0x14,1), local_18 == (void *)0x0)) {
    return (void *)0x0;
  }
  if (*(char *)((int)local_18 + 3) != '\0') {
    return local_18;
  }
  local_14 = _dlopen("/usr/lib/libSystem.B.dylib",0x10);
  if (local_14 != 0) {
    uVar2 = _dlsym(local_14,"__cxa_atexit");
    *(undefined4 *)((int)local_18 + 8) = uVar2;
    uVar2 = _dlsym(local_14,"__cxa_finalize");
    *(undefined4 *)((int)local_18 + 0xc) = uVar2;
    if (((*(int *)((int)local_18 + 8) != 0) && (*(int *)((int)local_18 + 0xc) != 0)) &&
       (local_10 = ((int (*)())FUN_00000ac3)(*(undefined4 *)((int)local_18 + 8),
                                *(undefined4 *)((int)local_18 + 0xc)), local_10 != -1)) {
      if (local_10 == 0) {
        *(undefined1 *)((int)local_18 + 3) = 2;
      }
      else {
        uVar2 = _dlsym(local_14,"atexit");
        *(undefined4 *)((int)local_18 + 0x10) = uVar2;
        if (*(int *)((int)local_18 + 0x10) == 0) goto LAB_00000c82;
        *(undefined1 *)((int)local_18 + 3) = 0x10;
      }
      return local_18;
    }
  }
LAB_00000c82:
  __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  return (void *)0x0;
}

/* FUN_00000ca5 @ 0xca5 (153 bytes) */
int FUN_00000ca5(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  
  puVar1 = _malloc(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    local_24 = 0xffffffff;
  }
  else {
    puVar1[1] = *param_2;
    puVar1[2] = param_2[1];
    puVar1[3] = param_2[2];
    *puVar1 = *(undefined4 *)(param_1 + 4);
    *(undefined4 **)(param_1 + 4) = puVar1;
    iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    if (iVar2 == 0) {
      local_20 = 0;
    }
    else {
      local_20 = 0xffffffff;
    }
    local_24 = local_20;
  }
  return local_24;
}

/* FUN_00000d3e @ 0xd3e (188 bytes) */
int FUN_00000d3e(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  uint uVar2;
  byte local_20;
  
  while( true ) {
    puVar1 = *(undefined4 **)(param_1 + 4);
    if (puVar1 == (undefined4 *)0x0) {
      return param_1;
    }
    if (puVar1 == param_2) break;
    *(undefined4 *)(param_1 + 4) = *puVar1;
    __keymgr_set_and_unlock_processwide_ptr(0xe,param_1);
    if ((uint)puVar1[2] < 6) {
      local_20 = (byte)puVar1[2];
      uVar2 = 1 << (local_20 & 0x1f);
      if ((uVar2 & 0x15) == 0) {
        if ((uVar2 & 0x2a) != 0) {
          (*(code *)puVar1[1])(puVar1[3]);
        }
      }
      else {
        (*(code *)puVar1[1])();
      }
    }
    _free(puVar1);
    param_1 = __keymgr_get_and_lock_processwide_ptr(0xe);
    if (param_1 == 0) {
      return 0;
    }
  }
  return param_1;
}

/* FUN_00000dfa @ 0xdfa (209 bytes) */
int FUN_00000dfa(param_1)
  undefined4 *param_1;
{
  int local_18;
  undefined4 local_14;
  undefined1 local_d;
  
  local_14 = 0;
  local_d = 0;
  local_18 = __keymgr_get_and_lock_processwide_ptr(0xe);
  if (local_18 != 0) {
    local_d = *(undefined1 *)(local_18 + 2);
    *(undefined1 *)(local_18 + 2) = 1;
    local_14 = *(undefined4 *)(local_18 + 4);
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  }
  if (param_1[1] == 0) {
    (*(code *)*param_1)();
  }
  else {
    (*(code *)*param_1)(param_1[2]);
  }
  if (local_18 != 0) {
    local_18 = __keymgr_get_and_lock_processwide_ptr(0xe);
  }
  if (local_18 != 0) {
    local_18 = ((int (*)())FUN_00000d3e)(local_18,local_14);
  }
  if (local_18 != 0) {
    *(undefined1 *)(local_18 + 2) = local_d;
    __keymgr_set_and_unlock_processwide_ptr(0xe,local_18);
  }
  return;
}

/* FUN_00000ecb @ 0xecb (406 bytes) */
int FUN_00000ecb(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_30;
  
  iVar2 = ((int (*)())FUN_00000b38)();
  if (iVar2 == 0) {
    local_30 = 0xffffffff;
  }
  else if ((*(char *)(iVar2 + 2) == '\0') && (*(char *)(iVar2 + 3) != '\x01')) {
    if (*(byte *)(iVar2 + 3) < 0x10) {
      pcVar1 = *(code **)(iVar2 + 8);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        puVar3 = _malloc(0xc);
        if (puVar3 == (undefined4 *)0x0) {
          local_30 = 0xffffffff;
        }
        else {
          *puVar3 = *param_1;
          puVar3[1] = param_1[1];
          puVar3[2] = param_1[2];
          local_30 = (*pcVar1)(0xdfa,puVar3,param_2);
        }
      }
      else {
        local_30 = 0xffffffff;
      }
    }
    else if (param_1[1] == 0) {
      pcVar1 = *(code **)(iVar2 + 0x10);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        local_30 = (*pcVar1)(*param_1);
      }
      else {
        local_30 = 0xffffffff;
      }
    }
    else {
      pcVar1 = *(code **)(iVar2 + 8);
      iVar2 = __keymgr_set_and_unlock_processwide_ptr(0xe,iVar2);
      if (iVar2 == 0) {
        local_30 = (*pcVar1)(*param_1,param_1[2],param_2);
      }
      else {
        local_30 = 0xffffffff;
      }
    }
  }
  else {
    local_30 = ((int (*)())FUN_00000ca5)(iVar2,param_1);
  }
  return local_30;
}

/* FUN_00001061 @ 0x1061 (45 bytes) */
int FUN_00001061(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = param_1;
  local_14 = 1;
  local_10 = param_2;
  ((int (*)())FUN_00000ecb)(&local_18,param_3);
  return;
}

/* FUN_0000108e @ 0x108e (54 bytes) */
int FUN_0000108e(param_1)
  undefined4 param_1;
{
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = param_1;
  local_14 = 0;
  ((int (*)())FUN_00000ecb)(&local_18,PTR_002131a9);
  return;
}

/* FUN_000010c4 @ 0x10c4 (680 bytes) */
int FUN_000010c4(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined1 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int local_34;
  int local_30;
  int local_2c;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  
  if (*(char *)(param_2 + 0x3190) == '\0') {
    if ((((*(float *)(param_2 + 0x2d90) <= 0.0 && *(float *)(param_2 + 0x2d90) != 0.0) ||
         (*(float *)(param_2 + 0x2d94) <= 0.0 && *(float *)(param_2 + 0x2d94) != 0.0)) ||
        (*(float *)(param_2 + 0x2d98) <= 0.0 && *(float *)(param_2 + 0x2d98) != 0.0)) ||
       (*(float *)(param_2 + 0x2d9c) <= 0.0 && *(float *)(param_2 + 0x2d9c) != 0.0)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
    *(undefined1 *)(param_1 + 0x140) = uVar3;
    local_34 = *(int *)(param_1 + 0x15c);
    uVar8 = local_34 + 7U & 0xfffffff8;
    local_30 = *(int *)(param_1 + 0x160);
    iVar7 = 0;
    iVar6 = 0;
    local_2c = local_30;
  }
  else {
    *(undefined1 *)(param_1 + 0x140) = 1;
    iVar7 = *(int *)(param_2 + 0x3180);
    local_30 = *(int *)(param_1 + 0x160);
    iVar6 = local_30 - (*(int *)(param_2 + 0x318c) + *(int *)(param_2 + 0x3184));
    uVar8 = iVar7 + *(int *)(param_2 + 0x3188);
    local_2c = *(int *)(param_2 + 0x318c) + iVar6;
    if (iVar7 < 0) {
      iVar7 = 0;
    }
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    local_34 = *(int *)(param_1 + 0x15c);
    uVar4 = local_34 + 7U & 0xfffffff8;
    if ((int)uVar4 < (int)uVar8) {
      uVar8 = uVar4;
    }
    if (local_30 < local_2c) {
      local_2c = local_30;
    }
    uVar8 = uVar8 - iVar7;
    local_2c = local_2c - iVar6;
  }
  if ((0 < (int)uVar8) && (0 < local_2c)) {
    uVar4 = local_34 + 7U & 0xfffffff8;
    iVar7 = iVar7 + (local_30 - (iVar6 + local_2c)) * uVar4;
    if (*(char *)(param_1 + 0x141) == '\x01') {
      uVar1 = CONCAT13((char)(int)(FLOAT_001c5b94 * *(float *)(param_2 + 0x2d9c)),
                       CONCAT12((char)(int)(*(float *)(param_2 + 0x2d98) * FLOAT_001c5b94),
                                CONCAT11((char)(int)(*(float *)(param_2 + 0x2d94) * FLOAT_001c5b94),
                                         (char)(int)(*(float *)(param_2 + 0x2d90) * FLOAT_001c5b94))
                               ));
      iVar7 = *(int *)(param_1 + 0x148) + iVar7 * 4;
      if ((local_2c != 1) && (uVar8 != uVar4)) {
        iVar6 = 0;
        do {
          uVar5 = 0;
          do {
            *(undefined4 *)(iVar7 + uVar5 * 4) = uVar1;
            uVar5 = uVar5 + 1;
          } while (uVar8 != uVar5);
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + uVar4 * 4;
        } while (local_2c != iVar6);
        return;
      }
      if (0 < (int)(local_2c * uVar8)) {
        iVar6 = 0;
        do {
          *(undefined4 *)(iVar7 + iVar6 * 4) = uVar1;
          iVar6 = iVar6 + 1;
        } while (local_2c * uVar8 - iVar6 != 0);
      }
    }
    else if (*(char *)(param_1 + 0x141) == '\x02') {
      iVar6 = (int)(*(float *)(param_2 + 0x2d94) * FLOAT_001c5b98);
      uStack_1a = (undefined1)iVar6;
      uStack_19 = (undefined1)((uint)iVar6 >> 8);
      uVar2 = CONCAT26((short)(int)(FLOAT_001c5b98 * *(float *)(param_2 + 0x2d9c)),
                       CONCAT24((short)(int)(*(float *)(param_2 + 0x2d98) * FLOAT_001c5b98),
                                CONCAT13(uStack_19,
                                         CONCAT12(uStack_1a,
                                                  (short)(int)(*(float *)(param_2 + 0x2d90) *
                                                              FLOAT_001c5b98)))));
      iVar7 = *(int *)(param_1 + 0x148) + iVar7 * 8;
      if ((local_2c == 1) || (uVar8 == uVar4)) {
        if (0 < (int)(local_2c * uVar8)) {
          iVar6 = 0;
          do {
            *(undefined8 *)(iVar7 + iVar6 * 8) = uVar2;
            iVar6 = iVar6 + 1;
          } while (local_2c * uVar8 - iVar6 != 0);
        }
      }
      else {
        iVar6 = 0;
        do {
          uVar5 = 0;
          do {
            *(undefined8 *)(iVar7 + uVar5 * 8) = uVar2;
            uVar5 = uVar5 + 1;
          } while (uVar8 != uVar5);
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + uVar4 * 8;
        } while (local_2c != iVar6);
      }
    }
  }
  return;
}

/* FUN_0000136c @ 0x136c (13520 bytes) */
void FUN_0000136c(void *param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  byte bVar2;
  short *psVar3;
  void *pvVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  ushort *puVar9;
  ushort *puVar10;
  undefined2 *puVar11;
  char *pcVar12;
  sbyte sVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  byte *pbVar16;
  short *psVar17;
  char cVar18;
  byte bVar19;
  short sVar20;
  ushort uVar21;
  ushort uVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  uint *puVar27;
  ushort *puVar28;
  ushort uVar29;
  uint uVar30;
  int iVar31;
  undefined2 *puVar32;
  byte *pbVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  undefined4 uVar39;
  void *pvVar40;
  int local_470;
  int local_448;
  int local_444;
  uint local_2d8;
  int local_2cc;
  int local_2c8;
  int local_2c4;
  int local_2c0;
  uint local_294;
  int local_28c;
  int local_288;
  int local_284;
  int local_280;
  uint local_254;
  int local_248;
  int local_244;
  int local_240;
  int local_23c;
  uint local_218;
  int local_20c;
  int local_208;
  int local_204;
  int local_200;
  uint local_1e4;
  uint local_1e0;
  int local_1d4;
  uint local_1d0;
  int local_1c4;
  uint local_1b4;
  uint local_1ac;
  int local_1a8;
  uint local_1a4;
  int local_198;
  int local_190;
  int local_184;
  int local_178;
  int local_168;
  byte local_162;
  float local_15c;
  float local_14c;
  float local_13c;
  float local_12c;
  float local_11c;
  float local_10c;
  ushort local_f2;
  byte local_ec;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  
  if (*(int *)((int)param_1 + 0x148) == 0) {
    return;
  }
  switch(param_2) {
  case 0x100:
    if ((*(byte *)((int)param_1 + 0x154) & 3) == 0) {
      iVar6 = *(int *)((int)param_1 + 0x10);
      if (*(char *)(iVar6 + 0x3190) == '\0') {
        local_444 = *(int *)((int)param_1 + 0x15c);
        uVar5 = local_444 + 7U & 0xfffffff8;
        local_288 = *(int *)((int)param_1 + 0x160);
        local_28c = 0;
        local_294 = 0;
      }
      else {
        local_280 = *(int *)(iVar6 + 0x3180);
        iVar31 = *(int *)((int)param_1 + 0x160);
        local_294 = iVar31 - (*(int *)(iVar6 + 0x318c) + *(int *)(iVar6 + 0x3184));
        uVar7 = *(int *)(iVar6 + 0x3188) + local_280;
        local_288 = *(int *)(iVar6 + 0x318c) + local_294;
        if (local_280 < 0) {
          local_280 = 0;
        }
        if ((int)local_294 < 0) {
          local_294 = 0;
        }
        local_444 = *(int *)((int)param_1 + 0x15c);
        uVar5 = local_444 + 7U & 0xfffffff8;
        if ((int)uVar7 <= (int)uVar5) {
          uVar5 = uVar7;
        }
        if (iVar31 < local_288) {
          local_288 = iVar31;
        }
        uVar5 = uVar5 - local_280;
        local_288 = local_288 - local_294;
        local_28c = local_280;
      }
      if ((uVar5 != 0) && (local_288 != 0)) {
        pvVar4 = _malloc((local_444 + 7U & 0xfffffff8) * *(int *)((int)param_1 + 0x160) * 4);
        FUN_00026ee1(param_1,0,0,*(int *)((int)param_1 + 0x15c) + 7U & 0xfffffff8,
                     *(undefined4 *)((int)param_1 + 0x160),0x80e1,0x8367,pvVar4,2,0);
        uVar7 = local_294 + local_288;
        if ((param_3 < FLOAT_001c5b9c) && (!NAN(param_3) && !NAN(FLOAT_001c5b9c))) {
          *(undefined1 *)((int)param_1 + 0x140) = 1;
        }
        uVar30 = *(int *)((int)param_1 + 0x15c) + 7U & 0xfffffff8;
        local_284 = (~local_294 + *(int *)((int)param_1 + 0x160)) * uVar30 + local_28c;
        if (*(char *)((int)param_1 + 0x141) == '\x01') {
          iVar6 = (int)(short)(int)(param_3 * FLOAT_001c5ba0);
          if (local_294 < uVar7) {
            local_b8 = 0;
            do {
              pcVar8 = (char *)(*(int *)((int)param_1 + 0x148) + local_284 * 4);
              pcVar12 = pcVar8 + uVar5 * 4;
              puVar27 = (uint *)(local_284 * 4 + (int)pvVar4);
              for (; pcVar8 < pcVar12; pcVar8 = pcVar8 + 4) {
                uVar24 = *puVar27;
                puVar27 = puVar27 + 1;
                *pcVar8 = *pcVar8 + (char)((int)((uVar24 >> 9 & 0x7f80 | uVar24 >> 0x11 & 0x7f) *
                                                iVar6) >> 0x17);
                pcVar8[1] = pcVar8[1] +
                            (char)((int)((uVar24 >> 1 & 0x7f80 | uVar24 >> 9 & 0x7f) * iVar6) >>
                                  0x17);
                pcVar8[2] = pcVar8[2] +
                            (char)((int)(((uVar24 & 0xff) << 7 | uVar24 >> 1 & 0x7f) * iVar6) >>
                                  0x17);
                pcVar8[3] = pcVar8[3] +
                            (char)((int)((uVar24 >> 0x11 & 0x7f80 | uVar24 >> 0x19) * iVar6) >> 0x17
                                  );
              }
              local_284 = local_284 - uVar30;
              local_b8 = local_b8 + 1;
            } while (uVar7 - local_294 != local_b8);
          }
        }
        else {
          iVar6 = (int)(short)(int)(param_3 * FLOAT_001c5ba0);
          if (local_294 < uVar7) {
            local_b4 = 0;
            do {
              psVar17 = (short *)(*(int *)((int)param_1 + 0x148) + local_284 * 8);
              psVar3 = psVar17 + uVar5 * 4;
              puVar27 = (uint *)((int)pvVar4 + local_284 * 4);
              for (; psVar17 < psVar3; psVar17 = psVar17 + 4) {
                uVar24 = *puVar27;
                puVar27 = puVar27 + 1;
                *psVar17 = *psVar17 +
                           (short)((int)((uVar24 >> 9 & 0x7f80 | uVar24 >> 0x11 & 0x7f) * iVar6) >>
                                  0xf);
                psVar17[1] = psVar17[1] +
                             (short)((int)((uVar24 >> 1 & 0x7f80 | uVar24 >> 9 & 0x7f) * iVar6) >>
                                    0xf);
                psVar17[2] = psVar17[2] +
                             (short)((int)(((uVar24 & 0xff) << 7 | uVar24 >> 1 & 0x7f) * iVar6) >>
                                    0xf);
                psVar17[3] = psVar17[3] +
                             (short)((int)((uVar24 >> 0x11 & 0x7f80 | uVar24 >> 0x19) * iVar6) >>
                                    0xf);
              }
              local_284 = local_284 - uVar30;
              local_b4 = local_b4 + 1;
            } while (uVar7 - local_294 != local_b4);
          }
        }
        goto LAB_00001b76;
      }
    }
    else {
      iVar6 = *(int *)((int)param_1 + 0x10);
      if (*(char *)(iVar6 + 0x3190) == '\0') {
        local_444 = *(int *)((int)param_1 + 0x15c);
        uVar5 = local_444 + 7U & 0xfffffff8;
        local_2c8 = *(int *)((int)param_1 + 0x160);
        local_2cc = 0;
        local_2d8 = 0;
      }
      else {
        local_2c0 = *(int *)(iVar6 + 0x3180);
        iVar31 = *(int *)((int)param_1 + 0x160);
        local_2d8 = iVar31 - (*(int *)(iVar6 + 0x318c) + *(int *)(iVar6 + 0x3184));
        uVar7 = *(int *)(iVar6 + 0x3188) + local_2c0;
        local_2c8 = *(int *)(iVar6 + 0x318c) + local_2d8;
        if (local_2c0 < 0) {
          local_2c0 = 0;
        }
        if ((int)local_2d8 < 0) {
          local_2d8 = 0;
        }
        local_444 = *(int *)((int)param_1 + 0x15c);
        uVar5 = local_444 + 7U & 0xfffffff8;
        if ((int)uVar7 <= (int)uVar5) {
          uVar5 = uVar7;
        }
        if (iVar31 < local_2c8) {
          local_2c8 = iVar31;
        }
        uVar5 = uVar5 - local_2c0;
        local_2c8 = local_2c8 - local_2d8;
        local_2cc = local_2c0;
      }
      if ((uVar5 != 0) && (local_2c8 != 0)) {
        pvVar4 = _malloc((local_444 + 7U & 0xfffffff8) * *(int *)((int)param_1 + 0x160) * 2);
        FUN_00026ee1(param_1,0,0,*(int *)((int)param_1 + 0x15c) + 7U & 0xfffffff8,
                     *(undefined4 *)((int)param_1 + 0x160),0x80e1,0x8366,pvVar4,2,0);
        uVar7 = local_2d8 + local_2c8;
        if ((param_3 < FLOAT_001c5b9c) && (!NAN(param_3) && !NAN(FLOAT_001c5b9c))) {
          *(undefined1 *)((int)param_1 + 0x140) = 1;
        }
        uVar30 = *(int *)((int)param_1 + 0x15c) + 7U & 0xfffffff8;
        local_2c4 = (~local_2d8 + *(int *)((int)param_1 + 0x160)) * uVar30 + local_2cc;
        if (*(char *)((int)param_1 + 0x141) == '\x01') {
          iVar6 = (int)(short)(int)(param_3 * FLOAT_001c5ba0);
          if (local_2d8 < uVar7) {
            local_c0 = 0;
            do {
              pcVar8 = (char *)(*(int *)((int)param_1 + 0x148) + local_2c4 * 4);
              pcVar12 = pcVar8 + uVar5 * 4;
              puVar28 = (ushort *)((int)pvVar4 + local_2c4 * 2);
              for (; pcVar8 < pcVar12; pcVar8 = pcVar8 + 4) {
                uVar29 = *puVar28;
                puVar28 = puVar28 + 1;
                uVar24 = (uint)uVar29;
                *pcVar8 = *pcVar8 + (char)((int)((uVar24 & 0x7c00 | uVar29 >> 5 & 0x3e0 |
                                                 uVar29 >> 10 & 0x1f) * iVar6) >> 0x17);
                pcVar8[1] = pcVar8[1] +
                            (char)((int)((uVar24 << 5 & 0x7c00 | uVar24 & 0x3e0 | uVar29 >> 5 & 0x1f
                                         ) * iVar6) >> 0x17);
                pcVar8[2] = pcVar8[2] +
                            (char)((int)(((uVar24 & 0x1f) << 10 | uVar24 << 5 & 0x3e0 |
                                         uVar24 & 0x1f) * iVar6) >> 0x17);
                pcVar8[3] = pcVar8[3] +
                            (char)((int)((-(uint)(uVar29 >> 0xf) & 0x7fff) * iVar6) >> 0x17);
              }
              local_2c4 = local_2c4 - uVar30;
              local_c0 = local_c0 + 1;
            } while (uVar7 - local_2d8 != local_c0);
          }
        }
        else {
          iVar6 = (int)(short)(int)(param_3 * FLOAT_001c5ba0);
          if (local_2d8 < uVar7) {
            local_bc = 0;
            do {
              psVar17 = (short *)(*(int *)((int)param_1 + 0x148) + local_2c4 * 8);
              psVar3 = psVar17 + uVar5 * 4;
              puVar28 = (ushort *)((int)pvVar4 + local_2c4 * 2);
              for (; psVar17 < psVar3; psVar17 = psVar17 + 4) {
                uVar29 = *puVar28;
                puVar28 = puVar28 + 1;
                uVar24 = (uint)uVar29;
                *psVar17 = *psVar17 +
                           (short)((int)((uVar24 & 0x7c00 | uVar29 >> 5 & 0x3e0 |
                                         uVar29 >> 10 & 0x1f) * iVar6) >> 0xf);
                psVar17[1] = psVar17[1] +
                             (short)((int)((uVar24 << 5 & 0x7c00 | uVar24 & 0x3e0 |
                                           uVar29 >> 5 & 0x1f) * iVar6) >> 0xf);
                psVar17[2] = psVar17[2] +
                             (short)((int)(((uVar24 & 0x1f) << 10 | uVar24 << 5 & 0x3e0 |
                                           uVar24 & 0x1f) * iVar6) >> 0xf);
                psVar17[3] = psVar17[3] +
                             (short)((int)((-(uint)(uVar29 >> 0xf) & 0x7fff) * iVar6) >> 0xf);
              }
              local_2c4 = local_2c4 - uVar30;
              local_bc = local_bc + 1;
            } while (uVar7 - local_2d8 != local_bc);
          }
        }
        goto LAB_00001b76;
      }
    }
    break;
  case 0x101:
    if ((*(byte *)((int)param_1 + 0x154) & 3) == 0) {
      iVar6 = *(int *)((int)param_1 + 0x10);
      if (*(char *)(iVar6 + 0x3190) == '\0') {
        local_444 = *(int *)((int)param_1 + 0x15c);
        uVar5 = local_444 + 7U & 0xfffffff8;
        local_208 = *(int *)((int)param_1 + 0x160);
        local_20c = 0;
        local_218 = 0;
      }
      else {
        local_200 = *(int *)(iVar6 + 0x3180);
        iVar31 = *(int *)((int)param_1 + 0x160);
        local_218 = iVar31 - (*(int *)(iVar6 + 0x318c) + *(int *)(iVar6 + 0x3184));
        uVar7 = *(int *)(iVar6 + 0x3188) + local_200;
        local_208 = *(int *)(iVar6 + 0x318c) + local_218;
        if (local_200 < 0) {
          local_200 = 0;
        }
        if ((int)local_218 < 0) {
          local_218 = 0;
        }
        local_444 = *(int *)((int)param_1 + 0x15c);
        uVar5 = local_444 + 7U & 0xfffffff8;
        if ((int)uVar7 <= (int)uVar5) {
          uVar5 = uVar7;
        }
        if (iVar31 < local_208) {
          local_208 = iVar31;
        }
        uVar5 = uVar5 - local_200;
        local_208 = local_208 - local_218;
        local_20c = local_200;
      }
      if ((uVar5 != 0) && (local_208 != 0)) {
        pvVar4 = _malloc((local_444 + 7U & 0xfffffff8) * *(int *)((int)param_1 + 0x160) * 4);
        FUN_00026ee1(param_1,0,0,*(int *)((int)param_1 + 0x15c) + 7U & 0xfffffff8,
                     *(undefined4 *)((int)param_1 + 0x160),0x80e1,0x8367,pvVar4,2,0);
        uVar7 = local_218 + local_208;
        if ((param_3 < FLOAT_001c5b9c) && (!NAN(param_3) && !NAN(FLOAT_001c5b9c))) {
          *(undefined1 *)((int)param_1 + 0x140) = 1;
        }
        uVar30 = *(int *)((int)param_1 + 0x15c) + 7U & 0xfffffff8;
        local_204 = (~local_218 + *(int *)((int)param_1 + 0x160)) * uVar30 + local_20c;
        if (*(char *)((int)param_1 + 0x141) == '\x01') {
          if (param_3 == FLOAT_001c5ba4) {
            if (local_218 < uVar7) {
              local_a0 = 0;
              do {
                pbVar16 = (byte *)(local_204 * 4 + *(int *)((int)param_1 + 0x148));
                pbVar33 = pbVar16 + uVar5 * 4;
                puVar27 = (uint *)((int)pvVar4 + local_204 * 4);
                for (; pbVar16 < pbVar33; pbVar16 = pbVar16 + 4) {
                  uVar24 = *puVar27;
                  puVar27 = puVar27 + 1;
                  *pbVar16 = (byte)(uVar24 >> 0x11) & 0x7f;
                  pbVar16[1] = (byte)(uVar24 >> 9) & 0x7f;
                  pbVar16[2] = (byte)(uVar24 >> 1) & 0x7f;
                  pbVar16[3] = (byte)(uVar24 >> 0x19);
                }
                local_204 = local_204 - uVar30;
                local_a0 = local_a0 + 1;
              } while (uVar7 - local_218 != local_a0);
            }
          }
          else {
            iVar6 = (int)(short)(int)(param_3 * FLOAT_001c5ba0);
            if (local_218 < uVar7) {
              local_9c = 0;
              do {
                puVar14 = (undefined1 *)(*(int *)((int)param_1 + 0x148) + local_204 * 4);
                puVar15 = puVar14 + uVar5 * 4;
                puVar27 = (uint *)(local_204 * 4 + (int)pvVar4);
                for (; puVar14 < puVar15; puVar14 = puVar14 + 4) {
                  uVar24 = *puVar27;
                  puVar27 = puVar27 + 1;
                  *puVar14 = (char)((int)((uVar24 >> 9 & 0x7f80 | uVar24 >> 0x11 & 0x7f) * iVar6) >>
                                   0x17);
                  puVar14[1] = (char)((int)((uVar24 >> 1 & 0x7f80 | uVar24 >> 9 & 0x7f) * iVar6) >>
                                     0x17);
                  puVar14[2] = (char)((int)(((uVar24 & 0xff) << 7 | uVar24 >> 1 & 0x7f) * iVar6) >>
                                     0x17);
                  puVar14[3] = (char)((int)((uVar24 >> 0x11 & 0x7f80 | uVar24 >> 0x19) * iVar6) >>
                                     0x17);
                }
                local_204 = local_204 - uVar30;
                local_9c = local_9c + 1;
              } while (uVar7 - local_218 != local_9c);
            }
          }
        }
        else if (param_3 == FLOAT_001c5ba4) {
          if (local_218 < uVar7) {
            local_98 = 0;
            do {
              puVar28 = (ushort *)(*(int *)((int)param_1 + 0x148) + local_204 * 8);
              puVar9 = puVar28 + uVar5 * 4;
              puVar27 = (uint *)((int)pvVar4 + local_204 * 4);
              for (; puVar28 < puVar9; puVar28 = puVar28 + 4) {
                uVar24 = *puVar27;
                puVar27 = puVar27 + 1;
                uVar21 = (ushort)(uVar24 >> 9);
                uVar29 = (ushort)(uVar24 >> 0x10);
                *puVar28 = uVar21 & 0x7f80 | uVar29 >> 1 & 0x7f;
                uVar22 = (ushort)(uVar24 >> 1);
                puVar28[1] = uVar22 & 0x7f80 | uVar21 & 0x7f;
                puVar28[2] = (ushort)(uVar24 << 7) & 0x7f80 | uVar22 & 0x7f;
                puVar28[3] = uVar29 >> 1 & 0x7f80 | uVar29 >> 9;
              }
              local_204 = local_204 - uVar30;
              local_98 = local_98 + 1;
            } while (uVar7 - local_218 != local_98);
          }
        }
        else {
          iVar6 = (int)(short)(int)(param_3 * FLOAT_001c5ba0);
          if (local_218 < uVar7) {
            local_94 = 0;
            do {
              puVar32 = (undefined2 *)(*(int *)((int)param_1 + 0x148) + local_204 * 8);
              puVar11 = puVar32 + uVar5 * 4;
              puVar27 = (uint *)((int)pvVar4 + local_204 * 4);
              for (; puVar32 < puVar11; puVar32 = puVar32 + 4) {
                uVar24 = *puVar27;
                puVar27 = puVar27 + 1;
                *puVar32 = (short)((int)((uVar24 >> 9 & 0x7f80 | uVar24 >> 0x11 & 0x7f) * iVar6) >>
                                  0xf);
                puVar32[1] = (short)((int)((uVar24 >> 1 & 0x7f80 | uVar24 >> 9 & 0x7f) * iVar6) >>
                                    0xf);
                puVar32[2] = (short)((int)(((uVar24 & 0xff) << 7 | uVar24 >> 1 & 0x7f) * iVar6) >>
                                    0xf);
                puVar32[3] = (short)((int)((uVar24 >> 0x11 & 0x7f80 | uVar24 >> 0x19) * iVar6) >>
                                    0xf);
              }
              local_204 = local_204 - uVar30;
              local_94 = local_94 + 1;
            } while (uVar7 - local_218 != local_94);
          }
        }
        goto LAB_00001b76;
      }
    }
    else {
      iVar6 = *(int *)((int)param_1 + 0x10);
      if (*(char *)(iVar6 + 0x3190) == '\0') {
        local_444 = *(int *)((int)param_1 + 0x15c);
        uVar5 = local_444 + 7U & 0xfffffff8;
        local_244 = *(int *)((int)param_1 + 0x160);
        local_248 = 0;
        local_254 = 0;
      }
      else {
        local_23c = *(int *)(iVar6 + 0x3180);
        iVar31 = *(int *)((int)param_1 + 0x160);
        local_254 = iVar31 - (*(int *)(iVar6 + 0x318c) + *(int *)(iVar6 + 0x3184));
        uVar7 = *(int *)(iVar6 + 0x3188) + local_23c;
        local_244 = *(int *)(iVar6 + 0x318c) + local_254;
        if (local_23c < 0) {
          local_23c = 0;
        }
        if ((int)local_254 < 0) {
          local_254 = 0;
        }
        local_444 = *(int *)((int)param_1 + 0x15c);
        uVar5 = local_444 + 7U & 0xfffffff8;
        if ((int)uVar7 <= (int)uVar5) {
          uVar5 = uVar7;
        }
        if (iVar31 < local_244) {
          local_244 = iVar31;
        }
        uVar5 = uVar5 - local_23c;
        local_244 = local_244 - local_254;
        local_248 = local_23c;
      }
      if ((uVar5 != 0) && (local_244 != 0)) {
        pvVar4 = _malloc((local_444 + 7U & 0xfffffff8) * *(int *)((int)param_1 + 0x160) * 2);
        FUN_00026ee1(param_1,0,0,*(int *)((int)param_1 + 0x15c) + 7U & 0xfffffff8,
                     *(undefined4 *)((int)param_1 + 0x160),0x80e1,0x8366,pvVar4,2,0);
        uVar7 = local_254 + local_244;
        if ((param_3 < FLOAT_001c5b9c) && (!NAN(param_3) && !NAN(FLOAT_001c5b9c))) {
          *(undefined1 *)((int)param_1 + 0x140) = 1;
        }
        uVar30 = *(int *)((int)param_1 + 0x15c) + 7U & 0xfffffff8;
        local_240 = (~local_254 + *(int *)((int)param_1 + 0x160)) * uVar30 + local_248;
        if (*(char *)((int)param_1 + 0x141) == '\x01') {
          if (param_3 == FLOAT_001c5ba4) {
            if (local_254 < uVar7) {
              local_b0 = 0;
              do {
                pbVar33 = (byte *)(*(int *)((int)param_1 + 0x148) + local_240 * 4);
                pbVar16 = pbVar33 + uVar5 * 4;
                puVar28 = (ushort *)((int)pvVar4 + local_240 * 2);
                for (; pbVar33 < pbVar16; pbVar33 = pbVar33 + 4) {
                  uVar29 = *puVar28;
                  puVar28 = puVar28 + 1;
                  bVar19 = (byte)(uVar29 >> 8);
                  *pbVar33 = bVar19 & 0x7c | bVar19 >> 5 & 3;
                  bVar2 = (byte)(uVar29 >> 3);
                  pbVar33[1] = bVar2 & 0x7c | bVar19 & 3;
                  pbVar33[2] = (char)uVar29 * '\x04' & 0x7cU | bVar2 & 3;
                  pbVar33[3] = (char)bVar19 >> 7 & 0x7f;
                }
                local_240 = local_240 - uVar30;
                local_b0 = local_b0 + 1;
              } while (uVar7 - local_254 != local_b0);
            }
          }
          else {
            iVar6 = (int)(short)(int)(param_3 * FLOAT_001c5ba0);
            if (local_254 < uVar7) {
              local_ac = 0;
              do {
                puVar14 = (undefined1 *)(*(int *)((int)param_1 + 0x148) + local_240 * 4);
                puVar15 = puVar14 + uVar5 * 4;
                puVar28 = (ushort *)((int)pvVar4 + local_240 * 2);
                for (; puVar14 < puVar15; puVar14 = puVar14 + 4) {
                  uVar29 = *puVar28;
                  puVar28 = puVar28 + 1;
                  uVar24 = (uint)uVar29;
                  *puVar14 = (char)((int)((uVar24 & 0x7c00 | uVar29 >> 5 & 0x3e0 |
                                          uVar29 >> 10 & 0x1f) * iVar6) >> 0x17);
                  puVar14[1] = (char)((int)((uVar24 << 5 & 0x7c00 | uVar24 & 0x3e0 |
                                            uVar29 >> 5 & 0x1f) * iVar6) >> 0x17);
                  puVar14[2] = (char)((int)(((uVar24 & 0x1f) << 10 | uVar24 << 5 & 0x3e0 |
                                            uVar24 & 0x1f) * iVar6) >> 0x17);
                  puVar14[3] = (char)((int)((-(uint)(uVar29 >> 0xf) & 0x7fff) * iVar6) >> 0x17);
                }
                local_240 = local_240 - uVar30;
                local_ac = local_ac + 1;
              } while (uVar7 - local_254 != local_ac);
            }
          }
        }
        else if (param_3 == FLOAT_001c5ba4) {
          if (local_254 < uVar7) {
            local_a8 = 0;
            do {
              puVar28 = (ushort *)(*(int *)((int)param_1 + 0x148) + local_240 * 8);
              puVar10 = puVar28 + uVar5 * 4;
              puVar9 = (ushort *)((int)pvVar4 + local_240 * 2);
              for (; puVar28 < puVar10; puVar28 = puVar28 + 4) {
                uVar29 = *puVar9;
                puVar9 = puVar9 + 1;
                *puVar28 = uVar29 & 0x7c00 | uVar29 >> 5 & 0x3e0 | uVar29 >> 10 & 0x1f;
                puVar28[1] = uVar29 << 5 & 0x7c00 | uVar29 & 0x3e0 | uVar29 >> 5 & 0x1f;
                puVar28[2] = (uVar29 & 0x1f) << 10 | uVar29 << 5 & 0x3e0 | uVar29 & 0x1f;
                puVar28[3] = (short)uVar29 >> 0xf & 0x7fff;
              }
              local_240 = local_240 - uVar30;
              local_a8 = local_a8 + 1;
            } while (uVar7 - local_254 != local_a8);
          }
        }
        else {
          iVar6 = (int)(short)(int)(param_3 * FLOAT_001c5ba0);
          if (local_254 < uVar7) {
            local_a4 = 0;
            do {
              puVar32 = (undefined2 *)(*(int *)((int)param_1 + 0x148) + local_240 * 8);
              puVar11 = puVar32 + uVar5 * 4;
              puVar28 = (ushort *)((int)pvVar4 + local_240 * 2);
              for (; puVar32 < puVar11; puVar32 = puVar32 + 4) {
                uVar29 = *puVar28;
                puVar28 = puVar28 + 1;
                uVar24 = (uint)uVar29;
                *puVar32 = (short)((int)((uVar24 & 0x7c00 | uVar29 >> 5 & 0x3e0 |
                                         uVar29 >> 10 & 0x1f) * iVar6) >> 0xf);
                puVar32[1] = (short)((int)((uVar24 << 5 & 0x7c00 | uVar24 & 0x3e0 |
                                           uVar29 >> 5 & 0x1f) * iVar6) >> 0xf);
                puVar32[2] = (short)((int)(((uVar24 & 0x1f) << 10 | uVar24 << 5 & 0x3e0 |
                                           uVar24 & 0x1f) * iVar6) >> 0xf);
                puVar32[3] = (short)((int)((-(uint)(uVar29 >> 0xf) & 0x7fff) * iVar6) >> 0xf);
              }
              local_240 = local_240 - uVar30;
              local_a4 = local_a4 + 1;
            } while (uVar7 - local_254 != local_a4);
          }
        }
        goto LAB_00001b76;
      }
    }
    break;
  case 0x102:
    if ((*(byte *)((int)param_1 + 0x154) & 3) == 0) {
      iVar6 = *(int *)((int)param_1 + 0x10);
      if (*(int *)(iVar6 + 0x2e40) == 0) {
        return;
      }
      if (*(char *)(iVar6 + 0x3190) == '\0') {
        local_444 = *(int *)((int)param_1 + 0x15c);
        local_1a4 = local_444 + 7U & 0xfffffff8;
        local_1a8 = *(int *)((int)param_1 + 0x160);
        local_1ac = 0;
        local_1b4 = 0;
      }
      else {
        local_1ac = *(uint *)(iVar6 + 0x3180);
        iVar31 = *(int *)((int)param_1 + 0x160);
        local_1b4 = iVar31 - (*(int *)(iVar6 + 0x318c) + *(int *)(iVar6 + 0x3184));
        uVar5 = local_1ac + *(int *)(iVar6 + 0x3188);
        local_1a8 = *(int *)(iVar6 + 0x318c) + local_1b4;
        if ((int)local_1ac < 0) {
          local_1ac = 0;
        }
        if ((int)local_1b4 < 0) {
          local_1b4 = 0;
        }
        local_444 = *(int *)((int)param_1 + 0x15c);
        local_1a4 = local_444 + 7U & 0xfffffff8;
        if ((int)uVar5 <= (int)local_1a4) {
          local_1a4 = uVar5;
        }
        if (iVar31 < local_1a8) {
          local_1a8 = iVar31;
        }
        local_1a4 = local_1a4 - local_1ac;
        local_1a8 = local_1a8 - local_1b4;
      }
      if (local_1a4 == 0) {
        return;
      }
      if (local_1a8 == 0) {
        return;
      }
      pvVar4 = _malloc((local_444 + 7U & 0xfffffff8) * *(int *)((int)param_1 + 0x160) * 4);
      uVar7 = local_1b4 + local_1a8;
      iVar6 = *(int *)((int)param_1 + 0x15c);
      uVar5 = iVar6 + 7U & 0xfffffff8;
      iVar31 = *(int *)((int)param_1 + 0x160);
      local_198 = ((iVar31 - local_1b4) + -1) * uVar5 + local_1ac;
      cVar18 = *(char *)((int)param_1 + 0x140);
      if (*(char *)((int)param_1 + 0x141) == '\x01') {
        if (param_3 == FLOAT_001c5ba4) {
          if (local_1b4 < uVar7) {
            local_80 = 0;
            iVar23 = *(int *)((int)param_1 + 0x148);
            do {
              pcVar8 = (char *)(local_198 * 4 + iVar23);
              pcVar12 = pcVar8 + local_1a4 * 4;
              puVar27 = (uint *)(local_198 * 4 + (int)pvVar4);
              if (cVar18 == '\0') {
                for (; pcVar8 < pcVar12; pcVar8 = pcVar8 + 4) {
                  *puVar27 = (int)pcVar8[3] << 0x19 | ((int)*pcVar8 & 0x7fU) << 0x11 |
                             ((int)pcVar8[1] & 0x7fU) << 9 | pcVar8[2] * 2 & 0xfeU;
                  puVar27 = puVar27 + 1;
                }
              }
              else {
                for (; pcVar8 < pcVar12; pcVar8 = pcVar8 + 4) {
                  if (*pcVar8 < '\0') {
                    uVar30 = 0;
                  }
                  else {
                    uVar30 = (uint)*pcVar8;
                  }
                  if (pcVar8[1] < '\0') {
                    uVar24 = 0;
                  }
                  else {
                    uVar24 = (uint)pcVar8[1];
                  }
                  if (pcVar8[2] < '\0') {
                    iVar26 = 0;
                  }
                  else {
                    iVar26 = (int)pcVar8[2];
                  }
                  if (pcVar8[3] < '\0') {
                    iVar25 = 0;
                  }
                  else {
                    iVar25 = (int)pcVar8[3];
                  }
                  *puVar27 = iVar25 << 0x19 | (uVar30 & 0x7f) << 0x11 | (uVar24 & 0x7f) << 9 |
                             iVar26 * 2 & 0xfeU;
                  puVar27 = puVar27 + 1;
                }
              }
              local_198 = local_198 - uVar5;
              local_80 = local_80 + 1;
            } while (local_80 != uVar7 - local_1b4);
          }
        }
        else {
          param_3 = param_3 * FLOAT_001c5ba8;
          if (local_1b4 < uVar7) {
            local_7c = 0;
            iVar23 = *(int *)((int)param_1 + 0x148);
            do {
              fVar38 = _DAT_001c5cb0;
              fVar1 = _DAT_001c5ca0;
              fVar34 = FLOAT_001c5bb8;
              pcVar8 = (char *)(local_198 * 4 + iVar23);
              pcVar12 = pcVar8 + local_1a4 * 4;
              puVar27 = (uint *)((int)pvVar4 + local_198 * 4);
              for (; pcVar8 < pcVar12; pcVar8 = pcVar8 + 4) {
                if (0.0 <= (float)(int)*pcVar8 * param_3) {
                  local_12c = (float)(int)*pcVar8 * param_3 * fVar34;
                }
                else {
                  local_12c = 0.0;
                }
                if ((float)(int)pcVar8[1] * param_3 < 0.0) {
                  local_11c = 0.0;
                }
                else {
                  local_11c = (float)(int)pcVar8[1] * param_3 * fVar34;
                }
                if ((float)(int)pcVar8[2] * param_3 < 0.0) {
                  local_10c = 0.0;
                }
                else {
                  local_10c = (float)(int)pcVar8[2] * param_3 * fVar34;
                }
                if ((float)(int)pcVar8[3] * param_3 < 0.0) {
                  fVar37 = 0.0;
                }
                else {
                  fVar37 = (float)(int)pcVar8[3] * param_3 * fVar34;
                }
                if (fVar37 <= 0.0) {
                  fVar37 = 0.0;
                }
                if (local_12c <= 0.0) {
                  local_12c = 0.0;
                }
                if (local_11c <= 0.0) {
                  local_11c = 0.0;
                }
                if (local_10c <= 0.0) {
                  local_10c = 0.0;
                }
                *puVar27 = ((int)(fVar37 - (float)(-(uint)(fVar1 <= fVar37) & (uint)fVar1)) |
                           -(uint)(fVar38 <= fVar37)) << 0x18 |
                           ((int)(local_12c - (float)(-(uint)(fVar1 <= local_12c) & (uint)fVar1)) |
                           -(uint)(fVar38 <= local_12c)) << 0x10 |
                           ((int)(local_11c - (float)(-(uint)(fVar1 <= local_11c) & (uint)fVar1)) |
                           -(uint)(fVar38 <= local_11c)) << 8 |
                           (int)(local_10c - (float)(-(uint)(fVar1 <= local_10c) & (uint)fVar1)) +
                           (uint)(fVar1 <= local_10c) * -0x80000000 | -(uint)(fVar38 <= local_10c);
                puVar27 = puVar27 + 1;
              }
              local_198 = local_198 - uVar5;
              local_7c = local_7c + 1;
            } while (local_7c != uVar7 - local_1b4);
          }
        }
      }
      else if (param_3 == FLOAT_001c5ba4) {
        if (local_1b4 < uVar7) {
          local_78 = 0;
          iVar23 = *(int *)((int)param_1 + 0x148);
          do {
            psVar17 = (short *)(iVar23 + local_198 * 8);
            psVar3 = psVar17 + local_1a4 * 4;
            puVar27 = (uint *)((int)pvVar4 + local_198 * 4);
            if (cVar18 == '\0') {
              for (; psVar17 < psVar3; psVar17 = psVar17 + 4) {
                *puVar27 = ((int)psVar17[3] & 0x7f80U) << 0x11 | ((int)*psVar17 & 0x7f80U) << 9 |
                           psVar17[1] * 2 & 0xff00U | (uint)(byte)(psVar17[2] >> 7);
                puVar27 = puVar27 + 1;
              }
            }
            else {
              for (; psVar17 < psVar3; psVar17 = psVar17 + 4) {
                if (*psVar17 < 0) {
                  uVar30 = 0;
                }
                else {
                  uVar30 = (uint)*psVar17;
                }
                if (psVar17[1] < 0) {
                  local_168 = 0;
                }
                else {
                  local_168 = (int)psVar17[1];
                }
                if (psVar17[2] < 0) {
                  local_162 = 0;
                }
                else {
                  local_162 = (byte)(psVar17[2] >> 7);
                }
                if (psVar17[3] < 0) {
                  uVar24 = 0;
                }
                else {
                  uVar24 = (uint)psVar17[3];
                }
                *puVar27 = (uVar24 & 0x7f80) << 0x11 | (uVar30 & 0x7f80) << 9 |
                           local_168 * 2 & 0xff00U | (uint)local_162;
                puVar27 = puVar27 + 1;
              }
            }
            local_198 = local_198 - uVar5;
            local_78 = local_78 + 1;
          } while (local_78 != uVar7 - local_1b4);
        }
      }
      else {
        param_3 = param_3 * FLOAT_001c5bb4;
        if (local_1b4 < uVar7) {
          local_74 = 0;
          iVar23 = *(int *)((int)param_1 + 0x148);
          do {
            fVar38 = _DAT_001c5cb0;
            fVar1 = _DAT_001c5ca0;
            fVar34 = FLOAT_001c5bb8;
            psVar17 = (short *)(iVar23 + local_198 * 8);
            psVar3 = psVar17 + local_1a4 * 4;
            puVar27 = (uint *)((int)pvVar4 + local_198 * 4);
            for (; psVar17 < psVar3; psVar17 = psVar17 + 4) {
              if (0.0 <= (float)(int)*psVar17 * param_3) {
                local_15c = (float)(int)*psVar17 * param_3 * fVar34;
              }
              else {
                local_15c = 0.0;
              }
              if ((float)(int)psVar17[1] * param_3 < 0.0) {
                local_14c = 0.0;
              }
              else {
                local_14c = (float)(int)psVar17[1] * param_3 * fVar34;
              }
              if ((float)(int)psVar17[2] * param_3 < 0.0) {
                local_13c = 0.0;
              }
              else {
                local_13c = (float)(int)psVar17[2] * param_3 * fVar34;
              }
              if ((float)(int)psVar17[3] * param_3 < 0.0) {
                fVar37 = 0.0;
              }
              else {
                fVar37 = (float)(int)psVar17[3] * param_3 * fVar34;
              }
              if (fVar37 <= 0.0) {
                fVar37 = 0.0;
              }
              if (local_15c <= 0.0) {
                local_15c = 0.0;
              }
              if (local_14c <= 0.0) {
                local_14c = 0.0;
              }
              if (local_13c <= 0.0) {
                local_13c = 0.0;
              }
              *puVar27 = ((int)(fVar37 - (float)(-(uint)(fVar1 <= fVar37) & (uint)fVar1)) |
                         -(uint)(fVar38 <= fVar37)) << 0x18 |
                         ((int)(local_15c - (float)(-(uint)(fVar1 <= local_15c) & (uint)fVar1)) |
                         -(uint)(fVar38 <= local_15c)) << 0x10 |
                         ((int)(local_14c - (float)(-(uint)(fVar1 <= local_14c) & (uint)fVar1)) |
                         -(uint)(fVar38 <= local_14c)) << 8 |
                         (int)(local_13c - (float)(-(uint)(fVar1 <= local_13c) & (uint)fVar1)) +
                         (uint)(fVar1 <= local_13c) * -0x80000000 | -(uint)(fVar38 <= local_13c);
              puVar27 = puVar27 + 1;
            }
            local_198 = local_198 - uVar5;
            local_74 = local_74 + 1;
          } while (local_74 != uVar7 - local_1b4);
        }
      }
      uVar5 = iVar6 + 7U & 0xfffffff8;
      pvVar40 = (void *)((int)pvVar4 + (uVar5 * ((iVar31 - local_1b4) - local_1a8) + local_1ac) * 4)
      ;
      uVar39 = 0x8367;
      local_1e4 = local_1ac;
      local_1e0 = local_1b4;
      local_1d0 = local_1a4;
      local_1d4 = local_1a8;
    }
    else {
      iVar6 = *(int *)((int)param_1 + 0x10);
      if (*(int *)(iVar6 + 0x2e40) == 0) {
        return;
      }
      if (*(char *)(iVar6 + 0x3190) == '\0') {
        local_444 = *(int *)((int)param_1 + 0x15c);
        local_1d0 = local_444 + 7U & 0xfffffff8;
        local_1d4 = *(int *)((int)param_1 + 0x160);
        local_1e4 = 0;
        local_1e0 = 0;
      }
      else {
        local_1e4 = *(uint *)(iVar6 + 0x3180);
        iVar31 = *(int *)((int)param_1 + 0x160);
        local_1e0 = iVar31 - (*(int *)(iVar6 + 0x318c) + *(int *)(iVar6 + 0x3184));
        uVar5 = local_1e4 + *(int *)(iVar6 + 0x3188);
        local_1d4 = *(int *)(iVar6 + 0x318c) + local_1e0;
        if ((int)local_1e4 < 0) {
          local_1e4 = 0;
        }
        if ((int)local_1e0 < 0) {
          local_1e0 = 0;
        }
        local_444 = *(int *)((int)param_1 + 0x15c);
        local_1d0 = local_444 + 7U & 0xfffffff8;
        if ((int)uVar5 <= (int)local_1d0) {
          local_1d0 = uVar5;
        }
        if (iVar31 < local_1d4) {
          local_1d4 = iVar31;
        }
        local_1d0 = local_1d0 - local_1e4;
        local_1d4 = local_1d4 - local_1e0;
      }
      if (local_1d0 == 0) {
        return;
      }
      if (local_1d4 == 0) {
        return;
      }
      pvVar4 = _malloc((local_444 + 7U & 0xfffffff8) * *(int *)((int)param_1 + 0x160) * 2);
      uVar30 = local_1e4 + local_1d0;
      uVar5 = local_1e0 + local_1d4;
      iVar6 = *(int *)((int)param_1 + 0x15c);
      uVar7 = iVar6 + 7U & 0xfffffff8;
      iVar31 = *(int *)((int)param_1 + 0x160);
      local_1c4 = ((iVar31 - local_1e0) + -1) * uVar7 + local_1e4;
      cVar18 = *(char *)((int)param_1 + 0x140);
      if (*(char *)((int)param_1 + 0x141) == '\x01') {
        if (param_3 == FLOAT_001c5ba4) {
          if (local_1e0 < uVar5) {
            local_90 = 0;
            iVar23 = *(int *)((int)param_1 + 0x148);
            do {
              pcVar8 = (char *)(iVar23 + local_1c4 * 4);
              pcVar12 = pcVar8 + local_1d0 * 4;
              puVar28 = (ushort *)((int)pvVar4 + local_1c4 * 2);
              if (cVar18 == '\0') {
                for (; pcVar8 < pcVar12; pcVar8 = pcVar8 + 4) {
                  *puVar28 = ((short)pcVar8[3] & 0x40U) << 9 | ((short)*pcVar8 & 0x7cU) << 8 |
                             ((short)pcVar8[1] & 0x7cU) << 3 | (byte)(pcVar8[2] >> 2) & 0x1f;
                  puVar28 = puVar28 + 1;
                }
              }
              else {
                for (; pcVar8 < pcVar12; pcVar8 = pcVar8 + 4) {
                  if (*pcVar8 < '\0') {
                    uVar29 = 0;
                  }
                  else {
                    uVar29 = (ushort)*pcVar8;
                  }
                  if (pcVar8[1] < '\0') {
                    uVar21 = 0;
                  }
                  else {
                    uVar21 = (ushort)pcVar8[1];
                  }
                  if (pcVar8[2] < '\0') {
                    local_ec = 0;
                  }
                  else {
                    local_ec = pcVar8[2] >> 2;
                  }
                  if (pcVar8[3] < '\0') {
                    uVar22 = 0;
                  }
                  else {
                    uVar22 = (ushort)pcVar8[3];
                  }
                  *puVar28 = (uVar22 & 0x40) << 9 | (uVar29 & 0x7c) << 8 | (uVar21 & 0x7c) << 3 |
                             local_ec & 0x1f;
                  puVar28 = puVar28 + 1;
                }
              }
              local_1c4 = local_1c4 - uVar7;
              local_90 = local_90 + 1;
            } while (uVar5 - local_1e0 != local_90);
          }
        }
        else {
          param_3 = param_3 * FLOAT_001c5ba8;
          if (local_1e0 < uVar5) {
            local_8c = 0;
            iVar23 = *(int *)((int)param_1 + 0x148);
            do {
              fVar1 = FLOAT_001c5bb0;
              fVar34 = FLOAT_001c5bac;
              pcVar8 = (char *)(iVar23 + local_1c4 * 4);
              puVar28 = (ushort *)((int)pvVar4 + local_1c4 * 2);
              if (local_1e4 < uVar30) {
                iVar26 = 0;
                do {
                  fVar38 = 0.0;
                  if (0.0 <= (float)(int)*pcVar8 * param_3) {
                    fVar38 = (float)(int)*pcVar8 * param_3 * fVar34;
                  }
                  fVar37 = 0.0;
                  if (0.0 <= (float)(int)pcVar8[1] * param_3) {
                    fVar37 = (float)(int)pcVar8[1] * param_3 * fVar34;
                  }
                  fVar36 = 0.0;
                  if (0.0 <= (float)(int)pcVar8[2] * param_3) {
                    fVar36 = (float)(int)pcVar8[2] * param_3 * fVar34;
                  }
                  if (0.0 <= (float)(int)pcVar8[3] * param_3) {
                    fVar35 = (float)(int)pcVar8[3] * param_3 * fVar1;
                  }
                  else {
                    fVar35 = 0.0;
                  }
                  *puVar28 = (ushort)((int)fVar37 << 5) |
                             (ushort)((int)fVar38 << 10) | (ushort)((int)fVar35 << 0xf) |
                             (ushort)(int)fVar36;
                  puVar28 = puVar28 + 1;
                  pcVar8 = pcVar8 + 4;
                  iVar26 = iVar26 + 1;
                } while (uVar30 - local_1e4 != iVar26);
              }
              local_1c4 = local_1c4 - uVar7;
              local_8c = local_8c + 1;
            } while (uVar5 - local_1e0 != local_8c);
          }
        }
      }
      else if (param_3 == FLOAT_001c5ba4) {
        if (local_1e0 < uVar5) {
          local_88 = 0;
          iVar23 = *(int *)((int)param_1 + 0x148);
          do {
            puVar28 = (ushort *)(iVar23 + local_1c4 * 8);
            puVar10 = puVar28 + local_1d0 * 4;
            puVar9 = (ushort *)((int)pvVar4 + local_1c4 * 2);
            if (cVar18 == '\0') {
              for (; puVar28 < puVar10; puVar28 = puVar28 + 4) {
                *puVar9 = puVar28[3] * 2 & 0x8000 | *puVar28 & 0x7c00 |
                          (short)puVar28[1] >> 5 & 0x3e0U | (short)puVar28[2] >> 10 & 0x1fU;
                puVar9 = puVar9 + 1;
              }
            }
            else {
              for (; puVar28 < puVar10; puVar28 = puVar28 + 4) {
                if ((short)*puVar28 < 0) {
                  local_f2 = 0;
                }
                else {
                  local_f2 = *puVar28 & 0x7c00;
                }
                if ((short)puVar28[1] < 0) {
                  uVar29 = 0;
                }
                else {
                  uVar29 = (short)puVar28[1] >> 5;
                }
                if ((short)puVar28[2] < 0) {
                  uVar21 = 0;
                }
                else {
                  uVar21 = (short)puVar28[2] >> 10;
                }
                uVar22 = puVar28[3];
                if ((short)uVar22 < 0) {
                  uVar22 = 0;
                }
                *puVar9 = uVar22 * 2 & 0x8000 | local_f2 | uVar29 & 0x3e0 | uVar21 & 0x1f;
                puVar9 = puVar9 + 1;
              }
            }
            local_1c4 = local_1c4 - uVar7;
            local_88 = local_88 + 1;
          } while (uVar5 - local_1e0 != local_88);
        }
      }
      else {
        param_3 = param_3 * FLOAT_001c5bb4;
        if (local_1e0 < uVar5) {
          local_84 = 0;
          iVar23 = *(int *)((int)param_1 + 0x148);
          do {
            fVar1 = FLOAT_001c5bb0;
            fVar34 = FLOAT_001c5bac;
            psVar17 = (short *)(iVar23 + local_1c4 * 8);
            puVar28 = (ushort *)((int)pvVar4 + local_1c4 * 2);
            if (local_1e4 < uVar30) {
              iVar26 = 0;
              do {
                fVar38 = 0.0;
                if (0.0 <= (float)(int)*psVar17 * param_3) {
                  fVar38 = (float)(int)*psVar17 * param_3 * fVar34;
                }
                fVar37 = 0.0;
                if (0.0 <= (float)(int)psVar17[1] * param_3) {
                  fVar37 = (float)(int)psVar17[1] * param_3 * fVar34;
                }
                fVar36 = 0.0;
                if (0.0 <= (float)(int)psVar17[2] * param_3) {
                  fVar36 = (float)(int)psVar17[2] * param_3 * fVar34;
                }
                if (0.0 <= (float)(int)psVar17[3] * param_3) {
                  fVar35 = (float)(int)psVar17[3] * param_3 * fVar1;
                }
                else {
                  fVar35 = 0.0;
                }
                *puVar28 = (ushort)((int)fVar37 << 5) |
                           (ushort)((int)fVar38 << 10) | (ushort)((int)fVar35 << 0xf) |
                           (ushort)(int)fVar36;
                puVar28 = puVar28 + 1;
                psVar17 = psVar17 + 4;
                iVar26 = iVar26 + 1;
              } while (uVar30 - local_1e4 != iVar26);
            }
            local_1c4 = local_1c4 - uVar7;
            local_84 = local_84 + 1;
          } while (uVar5 - local_1e0 != local_84);
        }
      }
      uVar5 = iVar6 + 7U & 0xfffffff8;
      pvVar40 = (void *)((int)pvVar4 + (uVar5 * ((iVar31 - local_1e0) - local_1d4) + local_1e4) * 2)
      ;
      uVar39 = 0x8366;
    }
    FUN_00017566(param_1,local_1e4,local_1e0,local_1d0,local_1d4,uVar39,pvVar40,uVar5);
LAB_00001b76:
    param_1 = pvVar4;
    _free(param_1);
    return;
  case 0x103:
    iVar6 = *(int *)((int)param_1 + 0x10);
    if (*(char *)(iVar6 + 0x3190) == '\0') {
      local_444 = *(int *)((int)param_1 + 0x15c);
      uVar5 = local_444 + 7U & 0xfffffff8;
      iVar6 = *(int *)((int)param_1 + 0x160);
      local_178 = 0;
      local_184 = 0;
      local_448 = iVar6;
    }
    else {
      local_178 = *(int *)(iVar6 + 0x3180);
      local_448 = *(int *)((int)param_1 + 0x160);
      iVar23 = local_448 - (*(int *)(iVar6 + 0x318c) + *(int *)(iVar6 + 0x3184));
      uVar5 = local_178 + *(int *)(iVar6 + 0x3188);
      iVar31 = *(int *)(iVar6 + 0x318c) + iVar23;
      if (local_178 < 0) {
        local_178 = 0;
      }
      local_184 = 0;
      if (-1 < iVar23) {
        local_184 = iVar23;
      }
      local_444 = *(int *)((int)param_1 + 0x15c);
      uVar7 = local_444 + 7U & 0xfffffff8;
      if ((int)uVar7 < (int)uVar5) {
        uVar5 = uVar7;
      }
      iVar6 = local_448;
      if (iVar31 <= local_448) {
        iVar6 = iVar31;
      }
      uVar5 = uVar5 - local_178;
      iVar6 = iVar6 - local_184;
    }
    if ((int)uVar5 < 1) {
      return;
    }
    if (iVar6 < 1) {
      return;
    }
    iVar31 = uVar5 * 4;
    iVar6 = iVar6 + local_184;
    if ((param_3 < FLOAT_001c5b9c) && (!NAN(param_3) && !NAN(FLOAT_001c5b9c))) {
      *(undefined1 *)((int)param_1 + 0x140) = 1;
    }
    uVar7 = local_444 + 7U & 0xfffffff8;
    local_178 = local_178 + ((local_448 - local_184) + -1) * uVar7;
    if (param_3 == FLOAT_001c5b9c) {
LAB_00002710:
      if ((((param_3 != FLOAT_001c5bc0) &&
           ((param_3 != FLOAT_001c5bc4 && (param_3 != FLOAT_001c5bc8)))) &&
          (param_3 != FLOAT_001c5bcc)) &&
         ((param_3 != FLOAT_001c5bd0 || (NAN(param_3) || NAN(FLOAT_001c5bd0))))) {
        if (*(char *)((int)param_1 + 0x141) == '\x01') {
          if (iVar6 <= local_184) {
            return;
          }
          iVar23 = 0;
          do {
            pcVar8 = (char *)(*(int *)((int)param_1 + 0x148) + local_178 * 4);
            pcVar12 = pcVar8 + iVar31;
            for (; pcVar8 < pcVar12; pcVar8 = pcVar8 + 4) {
              *pcVar8 = (char)(int)((float)(int)*pcVar8 * param_3);
              pcVar8[1] = (char)(int)((float)(int)pcVar8[1] * param_3);
              pcVar8[2] = (char)(int)((float)(int)pcVar8[2] * param_3);
              pcVar8[3] = (char)(int)((float)(int)pcVar8[3] * param_3);
            }
            local_178 = local_178 - uVar7;
            iVar23 = iVar23 + 1;
          } while (iVar23 != iVar6 - local_184);
          return;
        }
        if (iVar6 <= local_184) {
          return;
        }
        iVar31 = 0;
        do {
          psVar17 = (short *)(*(int *)((int)param_1 + 0x148) + local_178 * 8);
          psVar3 = psVar17 + uVar5 * 4;
          for (; psVar17 < psVar3; psVar17 = psVar17 + 4) {
            *psVar17 = (short)(int)((float)(int)*psVar17 * param_3);
            psVar17[1] = (short)(int)((float)(int)psVar17[1] * param_3);
            psVar17[2] = (short)(int)((float)(int)psVar17[2] * param_3);
            psVar17[3] = (short)(int)((float)(int)psVar17[3] * param_3);
          }
          local_178 = local_178 - uVar7;
          iVar31 = iVar31 + 1;
        } while (iVar31 != iVar6 - local_184);
        return;
      }
      iVar23 = (int)param_3;
      if (iVar23 == 4) {
        sVar13 = 2;
        goto LAB_0000276c;
      }
      if (iVar23 < 5) {
        if (iVar23 == 2) {
          sVar13 = 1;
          goto LAB_0000276c;
        }
      }
      else {
        if (iVar23 == 8) {
          sVar13 = 3;
          goto LAB_0000276c;
        }
        if (iVar23 == 0x10) {
          sVar13 = 4;
          goto LAB_0000276c;
        }
      }
      sVar13 = 5;
LAB_0000276c:
      if (*(char *)((int)param_1 + 0x141) == '\x01') {
        if (iVar6 <= local_184) {
          return;
        }
        iVar23 = 0;
        do {
          pcVar8 = (char *)(*(int *)((int)param_1 + 0x148) + local_178 * 4);
          pcVar12 = pcVar8 + iVar31;
          for (; pcVar8 < pcVar12; pcVar8 = pcVar8 + 4) {
            *pcVar8 = *pcVar8 << sVar13;
            pcVar8[1] = pcVar8[1] << sVar13;
            pcVar8[2] = pcVar8[2] << sVar13;
            pcVar8[3] = pcVar8[3] << sVar13;
          }
          local_178 = local_178 - uVar7;
          iVar23 = iVar23 + 1;
        } while (iVar23 != iVar6 - local_184);
        return;
      }
      if (iVar6 <= local_184) {
        return;
      }
      iVar31 = 0;
      do {
        psVar17 = (short *)(*(int *)((int)param_1 + 0x148) + local_178 * 8);
        psVar3 = psVar17 + uVar5 * 4;
        for (; psVar17 < psVar3; psVar17 = psVar17 + 4) {
          *psVar17 = *psVar17 << sVar13;
          psVar17[1] = psVar17[1] << sVar13;
          psVar17[2] = psVar17[2] << sVar13;
          psVar17[3] = psVar17[3] << sVar13;
        }
        local_178 = local_178 - uVar7;
        iVar31 = iVar31 + 1;
      } while (iVar31 != iVar6 - local_184);
      return;
    }
    fVar34 = FLOAT_001c5ba4 / param_3;
    if ((((fVar34 != FLOAT_001c5bc0) && (fVar34 != FLOAT_001c5bc4)) && (fVar34 != FLOAT_001c5bc8))
       && (fVar34 != FLOAT_001c5bcc)) {
      if ((fVar34 != FLOAT_001c5bd0) || (NAN(fVar34) || NAN(FLOAT_001c5bd0))) goto LAB_00002710;
    }
    iVar23 = (int)fVar34;
    if (iVar23 == 4) {
      sVar13 = 2;
    }
    else if (iVar23 < 5) {
      if (iVar23 == 2) {
        sVar13 = 1;
      }
      else {
LAB_00001ccd:
        sVar13 = 5;
      }
    }
    else if (iVar23 == 8) {
      sVar13 = 3;
    }
    else {
      if (iVar23 != 0x10) goto LAB_00001ccd;
      sVar13 = 4;
    }
    if (*(char *)((int)param_1 + 0x141) == '\x01') {
      if (local_184 < iVar6) {
        iVar23 = 0;
        do {
          pcVar8 = (char *)(*(int *)((int)param_1 + 0x148) + local_178 * 4);
          pcVar12 = pcVar8 + iVar31;
          for (; pcVar8 < pcVar12; pcVar8 = pcVar8 + 4) {
            *pcVar8 = (char)((int)*pcVar8 >> sVar13);
            pcVar8[1] = (char)((int)pcVar8[1] >> sVar13);
            pcVar8[2] = (char)((int)pcVar8[2] >> sVar13);
            pcVar8[3] = (char)((int)pcVar8[3] >> sVar13);
          }
          local_178 = local_178 - uVar7;
          iVar23 = iVar23 + 1;
        } while (iVar23 != iVar6 - local_184);
      }
    }
    else if (local_184 < iVar6) {
      iVar31 = 0;
      do {
        psVar17 = (short *)(*(int *)((int)param_1 + 0x148) + local_178 * 8);
        psVar3 = psVar17 + uVar5 * 4;
        for (; psVar17 < psVar3; psVar17 = psVar17 + 4) {
          *psVar17 = (short)((int)*psVar17 >> sVar13);
          psVar17[1] = (short)((int)psVar17[1] >> sVar13);
          psVar17[2] = (short)((int)psVar17[2] >> sVar13);
          psVar17[3] = (short)((int)psVar17[3] >> sVar13);
        }
        local_178 = local_178 - uVar7;
        iVar31 = iVar31 + 1;
      } while (iVar31 != iVar6 - local_184);
    }
    break;
  case 0x104:
    iVar6 = *(int *)((int)param_1 + 0x10);
    if (*(char *)(iVar6 + 0x3190) == '\0') {
      local_444 = *(int *)((int)param_1 + 0x15c);
      uVar5 = local_444 + 7U & 0xfffffff8;
      iVar6 = *(int *)((int)param_1 + 0x160);
      iVar31 = 0;
      local_190 = 0;
      local_448 = iVar6;
    }
    else {
      iVar31 = *(int *)(iVar6 + 0x3180);
      local_448 = *(int *)((int)param_1 + 0x160);
      iVar26 = local_448 - (*(int *)(iVar6 + 0x318c) + *(int *)(iVar6 + 0x3184));
      uVar7 = iVar31 + *(int *)(iVar6 + 0x3188);
      iVar23 = *(int *)(iVar6 + 0x318c) + iVar26;
      if (iVar31 < 0) {
        iVar31 = 0;
      }
      local_190 = 0;
      if (-1 < iVar26) {
        local_190 = iVar26;
      }
      local_444 = *(int *)((int)param_1 + 0x15c);
      uVar5 = local_444 + 7U & 0xfffffff8;
      if ((int)uVar7 <= (int)uVar5) {
        uVar5 = uVar7;
      }
      iVar6 = local_448;
      if (iVar23 <= local_448) {
        iVar6 = iVar23;
      }
      uVar5 = uVar5 - iVar31;
      iVar6 = iVar6 - local_190;
    }
    if ((0 < (int)uVar5) && (0 < iVar6)) {
      iVar6 = iVar6 + local_190;
      if ((param_3 < FLOAT_001c5b9c) && (!NAN(param_3) && !NAN(FLOAT_001c5b9c))) {
        *(undefined1 *)((int)param_1 + 0x140) = 1;
      }
      uVar7 = local_444 + 7U & 0xfffffff8;
      iVar31 = iVar31 + ((local_448 - local_190) + -1) * uVar7;
      if (*(char *)((int)param_1 + 0x141) == '\x01') {
        param_3 = param_3 * FLOAT_001c5bbc;
        if (local_190 < iVar6) {
          local_470 = 0;
          do {
            pcVar8 = (char *)(*(int *)((int)param_1 + 0x148) + iVar31 * 4);
            pcVar12 = pcVar8 + uVar5 * 4;
            for (; pcVar8 < pcVar12; pcVar8 = pcVar8 + 4) {
              cVar18 = (char)(int)param_3;
              *pcVar8 = *pcVar8 + cVar18;
              pcVar8[1] = pcVar8[1] + cVar18;
              pcVar8[2] = pcVar8[2] + cVar18;
              pcVar8[3] = pcVar8[3] + cVar18;
            }
            iVar31 = iVar31 - uVar7;
            local_470 = local_470 + 1;
          } while (local_470 != iVar6 - local_190);
        }
      }
      else {
        param_3 = param_3 * FLOAT_001c5ba0;
        if (local_190 < iVar6) {
          local_470 = 0;
          do {
            psVar17 = (short *)(*(int *)((int)param_1 + 0x148) + iVar31 * 8);
            psVar3 = psVar17 + uVar5 * 4;
            for (; psVar17 < psVar3; psVar17 = psVar17 + 4) {
              sVar20 = (short)(int)param_3;
              *psVar17 = *psVar17 + sVar20;
              psVar17[1] = psVar17[1] + sVar20;
              psVar17[2] = psVar17[2] + sVar20;
              psVar17[3] = psVar17[3] + sVar20;
            }
            iVar31 = iVar31 - uVar7;
            local_470 = local_470 + 1;
          } while (local_470 != iVar6 - local_190);
        }
      }
    }
  }
  return;
}

/* _gldSetInteger @ 0x4854 (1379 bytes) */
int _gldSetInteger(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  bool bVar5;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  if (param_3 == (uint *)0x0) {
    return 0x271e;
  }
  cVar2 = FUN_00014c68(param_1,param_2,param_3);
  if (cVar2 == '\0') {
    if (param_2 == 0x124) {
      local_1c = *param_3;
      iVar4 = _io_connect_method_scalarI_structureI
                        (*(undefined4 *)(param_1 + 4),0xc,&local_1c,1,0,0);
      if (iVar4 != 0) {
        return 0x2719;
      }
    }
    else if (param_2 < 0x125) {
      if (param_2 == 0xcb) {
        local_1c = (uint)*(byte *)(param_1 + 0x142);
        local_18 = *param_3;
        *(char *)(param_1 + 0x146) = (char)local_18;
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_1c,2,0,0);
        return 0;
      }
      if (param_2 < 0xcc) {
        if (param_2 == 200) {
          if (((int)param_3[2] < 0) || ((int)param_3[3] < 0)) {
            return 0x2718;
          }
          local_1c = *param_3;
          *(uint *)(param_1 + 0x124) = local_1c;
          local_18 = param_3[1];
          *(uint *)(param_1 + 0x128) = local_18;
          local_14 = param_3[2];
          *(uint *)(param_1 + 300) = local_14;
          local_10 = param_3[3];
          *(uint *)(param_1 + 0x130) = local_10;
          if (*(char *)(param_1 + 0x144) != '\0') {
            _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),1,&local_1c,4,0,0);
            return 0;
          }
        }
        else {
          if (param_2 != 0xc9) goto LAB_00004a91;
          bVar5 = *param_3 != 0;
          if ((bool)*(char *)(param_1 + 0x144) != bVar5) {
            *(bool *)(param_1 + 0x144) = bVar5;
            if (bVar5) {
              local_1c = *(uint *)(param_1 + 0x124);
              local_18 = *(undefined4 *)(param_1 + 0x128);
              local_14 = *(undefined4 *)(param_1 + 300);
              local_10 = *(undefined4 *)(param_1 + 0x130);
            }
            else {
              local_10 = 0;
              local_14 = 0;
              local_18 = 0;
              local_1c = 0;
            }
            _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),1,&local_1c,4,0,0);
            return 0;
          }
        }
      }
      else {
        if (param_2 == 0xde) {
          local_1c = *param_3;
          *(char *)(param_1 + 0x142) = (char)local_1c;
          local_18 = (uint)*(byte *)(param_1 + 0x146);
          _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_1c,2,0,0);
          return 0;
        }
        if (param_2 != 0xec) goto LAB_00004a91;
      }
    }
    else {
      if (param_2 == 0x29a) {
        *(bool *)(param_1 + 0x21) = *param_3 != 0;
        return 0;
      }
      if (param_2 < 0x29b) {
        if (param_2 == 0x12a) {
          *(undefined1 *)(param_1 + 0x145) = 1;
          *(uint *)(param_1 + 0x134) = *param_3;
          *(uint *)(param_1 + 0x138) = param_3[1];
          *(uint *)(param_1 + 0x13c) = param_3[2];
          return 0;
        }
        if (param_2 == 0x132) {
          uVar1 = *param_3;
          *(bool *)(param_1 + 0x147) = uVar1 != 0;
          local_1c = (uint)(uVar1 != 0);
          _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0x10,&local_1c,1,0,0);
          return 0;
        }
LAB_00004a91:
        uVar3 = FUN_00014e31(param_1,param_2,param_3);
        return uVar3;
      }
      if (param_2 == 0x29d) {
        iVar4 = *(int *)(*(int *)(param_1 + 0x18) + 0x194);
        if ((iVar4 != 0) && (local_1c = *(uint *)(iVar4 + 0x228), local_1c != 0)) {
          _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xf,&local_1c,1,0,0);
          return 0;
        }
      }
      else if (param_2 == 0x1f96) {
        local_1c = *param_3;
        local_18 = param_3[1];
        if (local_1c == 0) {
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) & 0xffffffef;
          *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x26) = 0;
        }
        else {
          *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x10;
          *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x26) = 1;
        }
        iVar4 = _io_connect_method_scalarI_structureI
                          (*(undefined4 *)(param_1 + 4),0x13,&local_1c,2,0,0);
        if (iVar4 != 0) {
          return 0x2712;
        }
      }
      else {
        if (param_2 != 0x29c) goto LAB_00004a91;
        uVar1 = param_3[1];
        if (0xf < *param_3) {
          return 0x2718;
        }
        if (uVar1 == 0x806f) {
          iVar4 = 1;
        }
        else if (uVar1 < 0x8070) {
          if (uVar1 == 0xde0) {
            iVar4 = 4;
          }
          else {
            if (uVar1 != 0xde1) {
              return 0x271a;
            }
            iVar4 = 3;
          }
        }
        else if (uVar1 == 0x84f5) {
          iVar4 = 2;
        }
        else {
          if (uVar1 != 0x8513) {
            return 0x271a;
          }
          iVar4 = 0;
        }
        iVar4 = *(int *)(*(int *)(param_1 + 0x18) + (*param_3 * 5 + iVar4) * 4);
        if ((iVar4 != 0) && (local_1c = *(uint *)(iVar4 + 0x34), local_1c != 0)) {
          _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xf,&local_1c,1,0,0);
          return 0;
        }
      }
    }
  }
  return 0;
}

/* _gldGetInteger @ 0x4db7 (421 bytes) */
int _gldGetInteger(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  uint uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_2c;
  uint uStack_28;
  uint uStack_24;
  undefined4 local_20 [4];
  
  if (param_3 == (uint *)0x0) {
    return 0x271e;
  }
  if (param_2 == 0xde) {
    *param_3 = (uint)*(byte *)(param_1 + 0x142);
    return 0;
  }
  if (param_2 < 0xdf) {
    if (param_2 == 0xc9) {
      *param_3 = (uint)*(byte *)(param_1 + 0x144);
      return 0;
    }
    if (param_2 != 0xcb) {
      if (param_2 == 200) {
        *param_3 = *(uint *)(param_1 + 0x124);
        param_3[1] = *(uint *)(param_1 + 0x128);
        param_3[2] = *(uint *)(param_1 + 300);
        param_3[3] = *(uint *)(param_1 + 0x130);
        return 0;
      }
      return 0x271a;
    }
    *param_3 = (uint)*(byte *)(param_1 + 0x146);
    return 0;
  }
  if (param_2 == 0x132) {
    *param_3 = (uint)*(byte *)(param_1 + 0x147);
    return 0;
  }
  if (param_2 < 0x133) {
    if (param_2 != 0x126) {
      return 0x271a;
    }
    uVar1 = *param_3;
    if (((*(byte *)(uVar1 + 0x39) & 7) != 0) && (cVar2 = FUN_0002fdb4(param_1,uVar1), cVar2 == '\0')
       ) {
      *param_3 = 0;
      return 0;
    }
    *param_3 = *(uint *)(*(int *)(uVar1 + 0x34) + 4);
    return 0;
  }
  if (param_2 == 0x29a) {
    *param_3 = (uint)*(byte *)(param_1 + 0x21);
    return 0;
  }
  if (param_2 != 0x3e3) {
    return 0x271a;
  }
  local_20[0] = 3;
  iVar3 = _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 4),6,param_3,1,&local_2c,local_20);
  if (iVar3 == 0) {
    switch(local_2c & 0xf) {
    case 3:
      *param_3 = 0x1908;
      param_3[1] = 0x8366;
      break;
    case 4:
      *param_3 = 0x1908;
      param_3[1] = 0x8367;
      break;
    default:
      goto LAB_00004f40;
    case 6:
    case 7:
    case 8:
    case 9:
      *param_3 = 0x85b9;
      param_3[1] = 0x85bb;
      break;
    case 10:
      *param_3 = 0x80e1;
      param_3[1] = 0x8367;
      break;
    case 0xb:
      *param_3 = 0x1908;
      param_3[1] = 0x1403;
      break;
    case 0xc:
      *param_3 = 0x1908;
      param_3[1] = 0x140b;
      break;
    case 0xd:
      *param_3 = 0x1908;
      param_3[1] = 0x1406;
    }
    param_3[2] = uStack_28;
    param_3[3] = uStack_24;
    uVar4 = 0;
  }
  else {
LAB_00004f40:
    uVar4 = 0x2722;
  }
  return uVar4;
}

/* _gldCreateBuffer @ 0x5002 (64 bytes) */
int _gldCreateBuffer(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = _malloc(0x24);
  puVar3 = puVar1;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  *puVar1 = param_3;
  puVar1[1] = param_4;
  puVar1[2] = 0;
  *param_2 = puVar1;
  return 0;
}

/* FUN_00005042 @ 0x5042 (224 bytes) */
int FUN_00005042(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  
  if ((*(int **)(param_2 + 8) != (int *)0x0) && (iVar2 = **(int **)(param_2 + 8), iVar2 != 0)) {
    if (*(char *)(iVar2 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush(param_1);
      }
      cVar1 = FUN_00017c5b(param_1,*(undefined4 *)(iVar2 + 8));
      if (cVar1 == '\0') {
        iVar2 = iVar2 + 8;
LAB_000050e5:
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
        goto LAB_000050e5;
      }
    }
  }
  return;
}

/* FUN_00005122 @ 0x5122 (125 bytes) */
int FUN_00005122(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  if ((*(int **)(param_2 + 8) != (int *)0x0) && (iVar1 = **(int **)(param_2 + 8), iVar1 != 0)) {
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
  return 1;
}

/* _gldFlushBuffer @ 0x519f (96 bytes) */
int _gldFlushBuffer(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  ushort *puVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_2 + 8);
  if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
    if (param_3 != 0) {
      FUN_00009943(param_1,param_3,param_4);
      piVar2 = *(int **)(param_2 + 8);
    }
    if (*(char *)(*piVar2 + 0x16) == '\a') {
      *(undefined1 *)(*piVar2 + 0x14) = 1;
      puVar1 = (ushort *)(**(int **)(param_2 + 8) + 0x28);
      *puVar1 = *puVar1 & ~*(ushort *)(**(int **)(param_2 + 8) + 0x1c);
    }
    **(uint **)(param_2 + 4) = **(uint **)(param_2 + 4) & 0xfffffffc;
  }
  return;
}

/* _gldGetMemoryPluginData @ 0x51ff (50 bytes) */
int _gldGetMemoryPluginData(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_2 + 8);
  if ((piVar2 != (int *)0x0) && (iVar1 = *piVar2, iVar1 != 0)) {
    *(ushort *)(iVar1 + 0x1c) = *(ushort *)(iVar1 + 0x1c) | *(ushort *)(iVar1 + 0x28);
    piVar2 = *(int **)(param_2 + 8);
  }
  *param_3 = (int)piVar2;
  *(undefined4 *)(param_2 + 8) = 0;
  return;
}

/* _gldSetMemoryPluginData @ 0x5231 (57 bytes) */
int _gldSetMemoryPluginData(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  
  *(int **)(param_2 + 8) = param_3;
  if ((param_3 != (int *)0x0) && (iVar1 = *param_3, iVar1 != 0)) {
    *(undefined1 *)(iVar1 + 0x14) = 1;
    if (*(char *)(**(int **)(param_2 + 8) + 0x16) == '\a') {
      *(ushort *)(iVar1 + 0x28) = *(ushort *)(iVar1 + 0x28) & ~*(ushort *)(iVar1 + 0x1c);
    }
    **(uint **)(param_2 + 4) = **(uint **)(param_2 + 4) & 0xfffffffe;
  }
  return;
}

/* _gldFinishMemoryPluginData @ 0x526a (190 bytes) */
int _gldFinishMemoryPluginData(param_1, param_2)
  int param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  
  if ((param_2 != (int *)0x0) && (iVar2 = *param_2, iVar2 != 0)) {
    if ((0x1ffff < *(int *)(iVar2 + 0x10)) || ((short)*(int *)(iVar2 + 0x10) != 0)) {
      _gldFlush(param_1);
    }
    if (*(char *)(iVar2 + 0x16) == '\x06') {
      cVar1 = FUN_00017c5b(param_1,*(undefined4 *)(iVar2 + 8));
      if (cVar1 == '\0') {
        iVar2 = iVar2 + 8;
LAB_0000530a:
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar2,1,0,0);
        return;
      }
    }
    else if (*(char *)(iVar2 + 0x16) == '\a') {
      cVar1 = FUN_00017c5b(param_1,*(undefined4 *)(iVar2 + 0xc));
      if (cVar1 == '\0') {
        iVar2 = iVar2 + 0xc;
        goto LAB_0000530a;
      }
    }
  }
  return;
}

/* _gldTestMemoryPluginData @ 0x5328 (88 bytes) */
int _gldTestMemoryPluginData(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  
  if ((param_2 == (int *)0x0) || (iVar1 = *param_2, iVar1 == 0)) {
    return 1;
  }
  if (*(char *)(iVar1 + 0x16) == '\x06') {
    if (0x1ffff < *(int *)(iVar1 + 0x10)) {
      return 0;
    }
    uVar3 = *(undefined4 *)(iVar1 + 8);
  }
  else {
    if (*(char *)(iVar1 + 0x16) != '\a') {
      return 1;
    }
    if (0x1ffff < *(int *)(iVar1 + 0x10)) {
      return 0;
    }
    uVar3 = *(undefined4 *)(iVar1 + 0xc);
  }
  uVar2 = FUN_00017c5b(param_1,uVar3);
  return uVar2;
}

/* _gldDestroyMemoryPluginData @ 0x5380 (171 bytes) */
int _gldDestroyMemoryPluginData(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  if (param_2 != (int *)0x0) {
    iVar1 = *param_2;
    if (iVar1 != 0) {
      if ((0x1ffff < *(int *)(iVar1 + 0x10)) || ((short)*(int *)(iVar1 + 0x10) != 0)) {
        _gldFlush(param_1);
      }
      ((int (*)())_gldFinishMemoryPluginData)(param_1,param_2);
      iVar2 = *(int *)(iVar1 + 0x10);
      *(int *)(iVar1 + 0x10) = iVar2 + -0x10000;
      if (iVar2 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar1,1,0,0);
      }
      *param_2 = 0;
    }
    _free(param_2);
    return;
  }
  return;
}

/* _gldReclaimBuffer @ 0x542b (181 bytes) */
int _gldReclaimBuffer(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_2 + 8);
  if (piVar3 != (int *)0x0) {
    iVar1 = *piVar3;
    if (iVar1 != 0) {
      if ((0x1ffff < *(int *)(iVar1 + 0x10)) || ((short)*(int *)(iVar1 + 0x10) != 0)) {
        _gldFlush(param_1);
      }
      ((int (*)())FUN_00005042)(param_1,param_2);
      iVar2 = *(int *)(iVar1 + 0x10);
      *(int *)(iVar1 + 0x10) = iVar2 + -0x10000;
      if (iVar2 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar1,1,0,0);
      }
      **(undefined4 **)(param_2 + 8) = 0;
      *(undefined4 *)(*(int *)(param_2 + 8) + 4) = 0;
      piVar3 = *(int **)(param_2 + 8);
    }
    _free(piVar3);
    *(undefined4 *)(param_2 + 8) = 0;
  }
  return;
}

/* _gldDestroyBuffer @ 0x54e0 (41 bytes) */
int _gldDestroyBuffer(param_1, param_2)
  undefined4 param_1;
  void *param_2;
{
  ((int (*)())_gldReclaimBuffer)(param_1,param_2);
  _free(param_2);
  return 0;
}

/* FUN_00005509 @ 0x5509 (287 bytes) */
int FUN_00005509(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int *piVar2;
  bool bVar3;
  int local_20;
  undefined1 local_18 [4];
  int local_14;
  undefined4 local_10;
  
  piVar2 = *(int **)(param_2 + 8);
  if (piVar2 == (int *)0x0) {
    piVar2 = _malloc(8);
    *(int **)(param_2 + 8) = piVar2;
    local_20 = 0;
  }
  else {
    local_20 = *piVar2;
  }
  *piVar2 = 0;
  *(undefined4 *)(*(int *)(param_2 + 8) + 4) = 0;
  *(undefined4 *)(param_2 + 0x10) = 6;
  *(undefined4 *)(param_2 + 0x14) = param_3;
  *(undefined4 *)(param_2 + 0x18) = param_4;
  *(undefined4 *)(param_2 + 0x1c) = param_5;
  local_10 = 8;
  iVar1 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 0x10,0x14,local_18,&local_10);
  bVar3 = iVar1 == 0;
  if (bVar3) {
    **(int **)(param_2 + 8) = local_14;
    *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + 0x10000;
    *(undefined1 *)(local_14 + 0x14) = 1;
  }
  if ((local_20 != 0) &&
     (iVar1 = *(int *)(local_20 + 0x10), *(int *)(local_20 + 0x10) = iVar1 + -0x10000,
     iVar1 == 0x10000)) {
    _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,local_20,1,0,0);
    return bVar3;
  }
  return bVar3;
}

/* FUN_00005628 @ 0x5628 (302 bytes) */
int FUN_00005628(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int *piVar2;
  bool bVar3;
  int local_20;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  
  piVar2 = *(int **)(param_2 + 8);
  if (piVar2 == (int *)0x0) {
    piVar2 = _malloc(8);
    *(int **)(param_2 + 8) = piVar2;
    local_20 = 0;
  }
  else {
    local_20 = *piVar2;
  }
  *piVar2 = 0;
  *(undefined4 *)(*(int *)(param_2 + 8) + 4) = 0;
  *(undefined4 *)(param_2 + 0x10) = 7;
  *(undefined4 *)(param_2 + 0x14) = param_3;
  *(undefined4 *)(param_2 + 0x18) = param_4;
  *(undefined4 *)(param_2 + 0x1c) = param_5;
  *(undefined4 *)(param_2 + 0x20) = param_6;
  local_10 = 8;
  iVar1 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 0x10,0x14,&local_18,&local_10);
  bVar3 = iVar1 == 0;
  if (bVar3) {
    **(int **)(param_2 + 8) = local_14;
    *(int *)(local_14 + 0x10) = *(int *)(local_14 + 0x10) + 0x10000;
    *(undefined1 *)(local_14 + 0x14) = 1;
    *(undefined4 *)(*(int *)(param_2 + 8) + 4) = local_18;
  }
  if ((local_20 != 0) &&
     (iVar1 = *(int *)(local_20 + 0x10), *(int *)(local_20 + 0x10) = iVar1 + -0x10000,
     iVar1 == 0x10000)) {
    _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,local_20,1,0,0);
    return bVar3;
  }
  return bVar3;
}

/* _gldCreateContext @ 0x5756 (1936 bytes) */
int _gldCreateContext(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 *param_1;
  int param_2;
  uint param_3;
  int param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  undefined *puVar1;
  int iVar2;
  uint *puVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  uint local_20 [4];
  
  if (param_1 == (undefined4 *)0x0) {
    return 0x271e;
  }
  *param_1 = 0;
  iVar2 = FUN_000187ae(param_2);
  puVar1 = PTR_DAT_002131ad;
  if (iVar2 == 0) {
    if (((*(uint *)(param_2 + 0x30) & *(uint *)PTR_DAT_002131ad) != 0) &&
       ((*(uint *)(param_2 + 0x30) & ~*(uint *)PTR_DAT_002131ad) == 0)) {
      puVar3 = _malloc(0x2b98);
      local_20[0] = 0;
      puVar7 = PTR_DAT_002131ad;
      if ((*(int *)(puVar1 + 4) != 0) && ((*(uint *)(param_2 + 0x30) & 1) == 0)) {
        local_20[0] = 0;
        do {
          local_20[0] = local_20[0] + 1;
          puVar7 = puVar1;
          if (*(uint *)(puVar1 + 4) <= local_20[0]) break;
        } while ((1 << ((byte)local_20[0] & 0x1f) & *(uint *)(param_2 + 0x30)) == 0);
      }
      *puVar3 = local_20[0];
      puVar3[1] = 0;
      iVar2 = _IOServiceOpen(*(undefined4 *)(*(int *)(puVar7 + 8) + local_20[0] * 4),
                             *(undefined4 *)PTR_002131b5,1,puVar3 + 1);
      if (iVar2 == 0) {
        if ((param_4 == 0) ||
           (iVar2 = _IOConnectAddClient(puVar3[1],*(undefined4 *)(param_4 + 4)), iVar2 == 0)) {
          local_20[0] = 3;
          iVar2 = _io_connect_method_scalarI_scalarO(puVar3[1],3,0,0,puVar3 + 9,local_20);
          if (iVar2 == 0) {
            puVar3[0x8e] = 0;
            puVar1 = PTR_002131b5;
            iVar2 = _IOConnectMapMemory(puVar3[1],0,*(undefined4 *)PTR_002131b5,puVar3 + 0x8e,
                                        local_20,0x101);
            if (iVar2 == 0) {
              puVar3[0x79] = 0;
              iVar2 = _IOConnectMapMemory(puVar3[1],1,*(undefined4 *)puVar1,puVar3 + 0x79,
                                          puVar3 + 0x7a,1);
              if (iVar2 == 0) {
                puVar3[0x7f] = 0;
                puVar3[0x80] = 0;
                puVar3[0x7d] = 0;
                puVar3[0x7e] = 0;
                puVar3[0x81] = 0;
                puVar3[0x82] = 0;
                iVar2 = _IOConnectMapMemory(puVar3[1],2,*(undefined4 *)puVar1,puVar3 + 0x82,
                                            puVar3 + 0x83,1);
                if (iVar2 == 0) {
                  puVar3[0x86] = 0;
                  iVar2 = _IOConnectMapMemory(puVar3[1],4,*(undefined4 *)puVar1,puVar3 + 0x86,
                                              puVar3 + 0x87,1);
                  if (iVar2 == 0) {
                    pvVar4 = _malloc(puVar3[0x87] >> 5);
                    puVar3[0x88] = (uint)pvVar4;
                    _memset(pvVar4,0,puVar3[0x87] >> 5);
                    puVar3[0x89] = 0;
                    puVar3[0x8a] = 0;
                    puVar3[0x8b] = 0;
                    puVar3[0x8c] = 0;
                    puVar3[0x8d] = 0;
                    if ((*(uint *)PTR_002131b1 & 8) == 0) {
                      *(byte *)(puVar3 + 2) =
                           (-((*(uint *)PTR_002131b1 & 0x10) == 0) & 0xa0U) + 0x80;
                    }
                    else {
                      *(undefined1 *)(puVar3 + 2) = 0x40;
                    }
                    puVar3[0x8f] = 0;
                    puVar3[0xae4] = (uint)puVar3;
                    puVar3[0xae5] = (uint)DAT_0020c660;
                    DAT_0020c660 = puVar3 + 0xae4;
                    puVar3[3] = param_3;
                    puVar3[5] = param_5;
                    puVar3[4] = param_6;
                    puVar3[6] = param_7;
                    puVar3[7] = 0;
                    puVar3[0xc] = 0;
                    puVar3[0xd] = 0;
                    puVar3[0xe] = 0;
                    puVar3[0x41] = 0;
                    puVar3[0x42] = 0;
                    puVar3[0x43] = 0;
                    puVar3[0x44] = 0;
                    puVar3[0x45] = 0x19;
                    puVar3[0x46] = 0x32;
                    *(undefined1 *)((int)puVar3 + 0x143) = 1;
                    puVar3[0x54] = 0;
                    puVar3[0x85] = 0;
                    puVar3[0x84] = 0;
                    puVar3[0x5e] = 0;
                    puVar3[0xf] = 0;
                    uVar6 = *(uint *)(param_2 + 8);
                    if ((uVar6 & 0x800) != 0) {
                      puVar3[0xf] = 0x2000;
                    }
                    uVar5 = *(uint *)(param_2 + 0xc);
                    if ((uVar5 & 8) == 0) {
                      if ((uVar6 & 2) == 0) {
                        puVar3[0xf] = puVar3[0xf] | 0x800;
                      }
                    }
                    else {
                      puVar3[0xf] = puVar3[0xf] | 0x400;
                    }
                    if ((uVar5 & 2) != 0) {
                      puVar3[0xf] = puVar3[0xf] | 0x10;
                    }
                    uVar6 = *(uint *)(param_2 + 0x10);
                    if ((uVar6 & 0xfffffc) == 0) {
                      if ((uVar6 & 0x3f000000) != 0) {
                        if ((uVar6 & 0x3f00000) == 0) {
                          if ((uVar6 & 0xc000000) != 0) {
                            puVar3[0xf] = puVar3[0xf] | 0xd;
                          }
                        }
                        else {
                          puVar3[0xf] = puVar3[0xf] | 0xc;
                        }
                      }
                    }
                    else if ((uVar6 & 0x3fc0) == 0) {
                      if ((uVar6 & 0xfc000) == 0) {
                        if ((uVar6 & 0x3f00000) != 0) {
                          puVar3[0xf] = puVar3[0xf] | 0xb;
                        }
                      }
                      else {
                        puVar3[0xf] = puVar3[0xf] | 4;
                      }
                    }
                    else {
                      puVar3[0xf] = puVar3[0xf] | 3;
                    }
                    if (*(int *)(param_2 + 0x18) != 1) {
                      puVar3[0xf] = puVar3[0xf] | 0x40;
                    }
                    if (*(int *)(param_2 + 0x1c) != 1) {
                      puVar3[0xf] = puVar3[0xf] | 0x80;
                    }
                    if (*(int *)(param_2 + 0x14) == 0x8000) {
                      *(undefined1 *)((int)puVar3 + 0x141) = 1;
                    }
                    else if (*(int *)(param_2 + 0x14) == 0x800000) {
                      *(undefined1 *)((int)puVar3 + 0x141) = 2;
                    }
                    else {
                      *(undefined1 *)((int)puVar3 + 0x141) = 0;
                    }
                    puVar3[0x52] = 0;
                    puVar3[0x53] = 0;
                    *(undefined1 *)(puVar3 + 0x50) = 0;
                    if (*(short *)(param_2 + 0x22) == 1) {
                      puVar3[0xf] = puVar3[0xf] | 0x100;
                    }
                    else if (*(short *)(param_2 + 0x22) == 2) {
                      puVar3[0xf] = puVar3[0xf] | 0x200;
                    }
                    if (0 < *(short *)(param_2 + 0x24)) {
                      puVar3[0xf] = puVar3[0xf] | 0x1000;
                    }
                    FUN_000155f0(puVar3 + 0xf,param_2);
                    puVar3[0xe] = 0x4000;
                    uVar6 = puVar3[0xf];
                    if ((uVar6 & 0x40) != 0) {
                      puVar3[0xe] = 0x4100;
                    }
                    if ((char)uVar6 < '\0') {
                      uVar5 = puVar3[0xe] | 0x400;
                      puVar3[0xe] = uVar5;
                    }
                    else {
                      uVar5 = puVar3[0xe];
                    }
                    if (*(char *)((int)puVar3 + 0x141) != '\0') {
                      uVar5 = uVar5 | 0x200;
                      puVar3[0xe] = uVar5;
                    }
                    puVar3[0x3e] = 0;
                    *(undefined1 *)(puVar3 + 8) = 0;
                    *(undefined1 *)((int)puVar3 + 0x21) = 1;
                    puVar3[0x49] = 0;
                    puVar3[0x4a] = 0;
                    puVar3[0x4b] = 0;
                    puVar3[0x4c] = 0;
                    *(undefined1 *)(puVar3 + 0x51) = 0;
                    *(undefined1 *)((int)puVar3 + 0x142) = 0;
                    *(undefined1 *)((int)puVar3 + 0x145) = 0;
                    *(undefined1 *)((int)puVar3 + 0x146) = 1;
                    puVar3[0x5d] = 3;
                    puVar3[0x47] = 0;
                    puVar3[0x48] = 0;
                    *(undefined1 *)((int)puVar3 + 0x147) = 0;
                    puVar3[0x55] = uVar6;
                    puVar3[0x56] = uVar5;
                    puVar3[0x57] = puVar3[0x41];
                    puVar3[0x58] = puVar3[0x42];
                    puVar3[0x59] = puVar3[0x43];
                    puVar3[0x5a] = puVar3[0x44];
                    puVar3[0x5b] = puVar3[0x45];
                    puVar3[0x5c] = puVar3[0x46];
                    uVar6 = 0;
                    do {
                      puVar3[uVar6 + 99] = 0;
                      uVar6 = uVar6 + 1;
                    } while (uVar6 < 0x10);
                    local_20[0] = 0;
                    do {
                      puVar3[local_20[0] + 0x73] = 0;
                      local_20[0] = local_20[0] + 1;
                    } while (local_20[0] < 2);
                    puVar3[0x5f] = 0;
                    puVar3[0x60] = 0;
                    puVar3[0x61] = 0;
                    puVar3[0x62] = 0;
                    *(uint *)(param_5 + 0x94) = (-(uint)((puVar3[9] & 2) == 0) & 2) + 1;
                    FUN_0001528b(puVar3,param_5,param_2);
                    puVar3[0x10] = *(uint *)(param_5 + 0x24);
                    puVar3[0x11] = *(uint *)(param_5 + 0x28);
                    puVar3[0x12] = *(uint *)(param_5 + 0x2c);
                    puVar3[0x13] = *(uint *)(param_5 + 0x30);
                    puVar3[0x14] = *(uint *)(param_5 + 0x34);
                    puVar3[0x15] = *(uint *)(param_5 + 0x38);
                    puVar3[0x16] = *(uint *)(param_5 + 0x3c);
                    puVar3[0x17] = *(uint *)(param_5 + 0x40);
                    puVar3[0x18] = *(uint *)(param_5 + 0x44);
                    puVar3[0x19] = *(uint *)(param_5 + 0x48);
                    puVar3[0x1a] = *(uint *)(param_5 + 0x4c);
                    puVar3[0x1b] = *(uint *)(param_5 + 0x50);
                    puVar3[0x1c] = *(uint *)(param_5 + 0x54);
                    puVar3[0x1d] = *(uint *)(param_5 + 0x58);
                    puVar3[0x1e] = *(uint *)(param_5 + 0x5c);
                    FUN_0002a7bc(puVar3,param_2);
                    *param_1 = puVar3;
                    return 0;
                  }
                }
              }
            }
          }
        }
        _IOServiceClose(puVar3[1]);
      }
      _free(puVar3);
      return 0x271f;
    }
    iVar2 = 0x2716;
  }
  return iVar2;
}

/* _gldDestroyContext @ 0x5ee6 (158 bytes) */
int _gldDestroyContext(param_1)
  void *param_1;
{
  int *piVar1;
  int *piVar2;
  
  if (param_1 == (void *)0x0) {
    return 0x2714;
  }
  ((int (*)())FUN_000060c5)(param_1);
  FUN_0002aa79(param_1);
  _IOServiceClose(*(undefined4 *)((int)param_1 + 4));
  if (DAT_0020c660 != (int *)0x0) {
    piVar1 = DAT_0020c660;
    if (param_1 == (void *)*DAT_0020c660) {
      DAT_0020c660 = (int *)DAT_0020c660[1];
    }
    else {
      do {
        piVar2 = piVar1;
        piVar1 = (int *)piVar2[1];
        if (piVar1 == (int *)0x0) goto LAB_00005f38;
      } while (param_1 != (void *)*piVar1);
      piVar2[1] = piVar1[1];
    }
  }
LAB_00005f38:
  if (*(void **)((int)param_1 + 0x148) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 0x148));
  }
  if (*(void **)((int)param_1 + 0x220) != (void *)0x0) {
    _free(*(void **)((int)param_1 + 0x220));
  }
  _free(param_1);
  return 0;
}

/* _gldCreateShared @ 0x5f84 (122 bytes) */
int _gldCreateShared(param_1)
  undefined4 *param_1;
{
  pthread_mutex_t *ppVar1;
  undefined4 uVar2;
  pthread_mutexattr_t local_18;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0x271e;
  }
  else {
    *param_1 = 0;
    ppVar1 = _malloc(0x34);
    if (ppVar1 == (pthread_mutex_t *)0x0) {
      return 0x2720;
    }
    _pthread_mutexattr_init(&local_18);
    _pthread_mutexattr_settype(&local_18,2);
    _pthread_mutex_init(ppVar1,&local_18);
    FUN_000229b0(ppVar1);
    *param_1 = ppVar1;
    uVar2 = 0;
  }
  return uVar2;
}

/* _gldDestroyShared @ 0x5ffe (57 bytes) */
int _gldDestroyShared(param_1)
  pthread_mutex_t *param_1;
{
  if (param_1 != (pthread_mutex_t *)0x0) {
    FUN_000229c1(param_1);
    _pthread_mutex_destroy(param_1);
    _free(param_1);
    return 0;
  }
  return 0x2714;
}

/* _gldReclaimContext @ 0x6037 (142 bytes) */
int _gldReclaimContext(param_1)
  void *param_1;
{
  int iVar1;
  
  FUN_0002ab48(param_1);
  iVar1 = _io_connect_method_scalarI_structureI(*(undefined4 *)((int)param_1 + 4),0x11,0,0,0,0);
  if (iVar1 == 0) {
    *(undefined4 *)((int)param_1 + 0x1fc) = 0;
    *(undefined4 *)((int)param_1 + 0x200) = 0;
    *(undefined4 *)((int)param_1 + 500) = 0;
    *(undefined4 *)((int)param_1 + 0x1f8) = 0;
    *(undefined4 *)((int)param_1 + 0x204) = 0;
    return;
  }
  _free(param_1);
  return;
}

/* FUN_000060c5 @ 0x60c5 (112 bytes) */
int FUN_000060c5(param_1)
  int *param_1;
{
  char cVar1;
  undefined *puVar2;
  
  if ((param_1[0x3e] != 0) &&
     (param_1[0x3e] = 0, puVar2 = PTR_DAT_002131ad, (*(byte *)(param_1 + 0xf) & 0x20) == 0)) {
    cVar1 = PTR_DAT_002131ad[*param_1 + 0x98];
    PTR_DAT_002131ad[*param_1 + 0x98] = cVar1 + -1;
    if ((char)(cVar1 + -1) == '\0') {
      _IOServiceClose(*(undefined4 *)(puVar2 + *param_1 * 4 + 0x18));
      *(undefined4 *)(puVar2 + *param_1 * 4 + 0x18) = 0;
      return;
    }
  }
  return;
}

/* _gldAttachDrawable @ 0x6135 (2377 bytes) */
int _gldAttachDrawable(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int *param_3;
  uint param_4;
{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  size_t sVar8;
  uint *local_68;
  uint *local_50;
  uint local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  byte local_2c [4];
  undefined4 local_28;
  int local_24 [5];
  
  if (param_1 == (int *)0x0) {
    return 0x271e;
  }
  uVar5 = param_4 >> 8 & 0xff;
  if ((param_2 == 0x50) || (param_2 == 0x5a)) {
    if (param_3 == (int *)0x0) {
      return 0x2715;
    }
    param_1[0xf] = param_1[0xf] | 0x20;
    piVar2 = (int *)0x0;
    if (param_2 == 0x5a) {
      piVar2 = param_3;
    }
    FUN_00014cc2(param_1,param_1 + 0xf,piVar2);
    local_28 = 3;
    local_24[0] = param_3[2];
    iVar3 = _io_connect_method_scalarI_scalarO(param_1[1],6,local_24,1,&local_4c,&local_28);
    if (iVar3 == 0) {
      uVar7 = param_1[0xf];
      if ((local_4c & 0xf) != (uVar7 & 0xf)) {
        if ((uVar7 & 0x33c0) != 0) {
          if (param_1[0x54] != 0) {
            return 0x2715;
          }
          param_1[0x55] = uVar7;
          return 0x2715;
        }
        uVar7 = uVar7 & 0xfffffff0 | local_4c & 0xf;
        param_1[0xf] = uVar7;
        if (param_1[0x54] == 0) {
          param_1[0x55] = uVar7;
          FUN_00014da2(param_1);
          uVar7 = param_1[0xf];
        }
      }
    }
    else {
      uVar7 = param_1[0xf];
    }
    if (param_2 == 0x5a) {
      iVar3 = (**(code **)(PTR_DAT_002131ad + 0x14))
                        (0,0,param_3[2],uVar7 & 0x803f,
                         *(undefined4 *)(*(int *)(PTR_DAT_002131ad + 8) + *param_1 * 4));
    }
    else {
      iVar3 = (**(code **)(PTR_DAT_002131ad + 0x14))
                        (*param_3,param_3[1],param_3[2],uVar7 & 0x803f,
                         *(undefined4 *)(*(int *)(PTR_DAT_002131ad + 8) + *param_1 * 4));
    }
    if (iVar3 != 0) goto LAB_00006238;
    local_3c = param_3[2];
    local_38 = param_1[0xf] & 0xffff3fc0;
    local_34 = uVar5;
    local_30 = param_4 & 0xff;
    iVar3 = _io_connect_method_scalarI_structureI(param_1[1],0,&local_3c,4,0,0);
    if ((iVar3 == 0) &&
       ((*(char *)((int)param_1 + 0x145) == '\0' ||
        (iVar3 = _io_connect_method_scalarI_structureI(param_1[1],0xe,param_1 + 0x4d,3,0,0),
        iVar3 == 0)))) {
      local_3c = (uint)*(byte *)((int)param_1 + 0x147);
      _io_connect_method_scalarI_structureI(param_1[1],0x10,&local_3c,1,0,0);
LAB_00006395:
      local_68 = &local_4c;
      local_24[1] = 4;
      piVar2 = local_24 + 1;
      iVar3 = _io_connect_method_scalarI_scalarO(param_1[1],5,0,0,local_68,piVar2);
      if (iVar3 == 0) {
        local_24[1] = 3;
        iVar3 = _io_connect_method_scalarI_scalarO(param_1[1],3,0,0,param_1 + 9,piVar2);
        if (iVar3 == 0) {
          local_24[1] = 1;
          _io_connect_method_scalarI_scalarO(param_1[1],4,0,0,local_2c,piVar2);
          if ((local_2c[0] & 1) == 0) {
            param_1[0x41] = local_4c;
            param_1[0x42] = local_48;
            param_1[0x47] = local_44;
            param_1[0x48] = local_40;
            uVar6 = 0x2720;
          }
          else if (param_3 == (int *)param_1[0x3e]) {
            if ((local_4c == param_1[0x41]) && (local_48 == param_1[0x42])) {
              uVar6 = 0;
            }
            else {
              param_1[0x41] = local_4c;
              param_1[0x42] = local_48;
              param_1[0x47] = local_44;
              param_1[0x48] = local_40;
              uVar6 = 3;
            }
          }
          else {
            param_1[0x41] = local_4c;
            param_1[0x42] = local_48;
            param_1[0x47] = local_44;
            param_1[0x48] = local_40;
            uVar6 = 2;
          }
          if ((*(char *)((int)param_1 + 0x141) != '\0') &&
             (sVar8 = ((uint)(*(char *)((int)param_1 + 0x141) != '\x01') * 4 + 4) *
                      (local_4c + 7 & 0xfffffff8) * local_48, sVar8 - param_1[0x53] != 0)) {
            if ((void *)param_1[0x52] != (void *)0x0) {
              _free((void *)param_1[0x52]);
            }
            pvVar4 = _malloc(sVar8);
            param_1[0x52] = (int)pvVar4;
            param_1[0x53] = sVar8;
          }
          ((int (*)())FUN_000060c5)(param_1);
          param_1[0x3e] = (int)param_3;
          param_1[0x3f] = uVar5;
          param_1[0x40] = param_4 & 0xff;
          if (param_1[0x54] == 0) {
            param_1[0x55] = param_1[0xf];
            param_1[0x57] = param_1[0x41];
            param_1[0x58] = param_1[0x42];
            param_1[0x59] = param_1[0x43];
            param_1[0x5a] = param_1[0x44];
            param_1[0x5b] = param_1[0x45];
            param_1[0x5c] = param_1[0x46];
          }
          return uVar6;
        }
      }
      uVar6 = 0x2715;
      goto LAB_00006243;
    }
  }
  else {
    if (param_2 != 0x36) {
      if (param_2 == 0x35) {
LAB_000067bf:
        uVar6 = 0x2715;
        goto LAB_00006243;
      }
      if (param_2 != 0) {
        if (param_2 == 0x5b) {
          if (param_3 != (int *)0x0) {
            param_1[0x55] = param_3[3];
            param_1[0x56] = param_3[2];
            param_1[0x57] = (uint)*(ushort *)(*param_3 + 0x9a);
            param_1[0x58] = (uint)*(ushort *)(*param_3 + 0x9c);
            param_1[0x59] = 0;
            param_1[0x5a] = 0;
            param_1[0x5b] = 0;
            param_1[0x5c] = 0;
            iVar3 = param_1[5];
            *(int *)(iVar3 + 0x24) = param_3[4];
            *(int *)(iVar3 + 0x28) = param_3[5];
            *(int *)(iVar3 + 0x2c) = param_3[6];
            *(int *)(iVar3 + 0x30) = param_3[7];
            *(int *)(iVar3 + 0x34) = param_3[8];
            *(int *)(iVar3 + 0x38) = param_3[9];
            *(int *)(iVar3 + 0x3c) = param_3[10];
            *(int *)(iVar3 + 0x40) = param_3[0xb];
            *(int *)(iVar3 + 0x44) = param_3[0xc];
            *(int *)(iVar3 + 0x48) = param_3[0xd];
            *(int *)(iVar3 + 0x4c) = param_3[0xe];
            *(int *)(iVar3 + 0x50) = param_3[0xf];
            *(int *)(iVar3 + 0x54) = param_3[0x10];
            *(int *)(iVar3 + 0x58) = param_3[0x11];
            *(int *)(iVar3 + 0x5c) = param_3[0x12];
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
          iVar3 = param_1[5];
          *(int *)(iVar3 + 0x24) = param_1[0x10];
          *(int *)(iVar3 + 0x28) = param_1[0x11];
          *(int *)(iVar3 + 0x2c) = param_1[0x12];
          *(int *)(iVar3 + 0x30) = param_1[0x13];
          *(int *)(iVar3 + 0x34) = param_1[0x14];
          *(int *)(iVar3 + 0x38) = param_1[0x15];
          *(int *)(iVar3 + 0x3c) = param_1[0x16];
          *(int *)(iVar3 + 0x40) = param_1[0x17];
          *(int *)(iVar3 + 0x44) = param_1[0x18];
          *(int *)(iVar3 + 0x48) = param_1[0x19];
          *(int *)(iVar3 + 0x4c) = param_1[0x1a];
          *(int *)(iVar3 + 0x50) = param_1[0x1b];
          *(int *)(iVar3 + 0x54) = param_1[0x1c];
          *(int *)(iVar3 + 0x58) = param_1[0x1d];
          *(int *)(iVar3 + 0x5c) = param_1[0x1e];
          if (*(char *)((int)param_1 + 0x143) != '\0') {
            *(uint *)param_1[5] = *(uint *)param_1[5] | 2;
            return 0;
          }
          *(uint *)param_1[5] = *(uint *)param_1[5] & 0xfffffffd;
          return 0;
        }
        uVar6 = 0x271a;
        goto LAB_00006243;
      }
      if (param_3 == (int *)0x0) {
        uVar6 = 1;
        goto LAB_00006243;
      }
LAB_00006238:
      uVar6 = 0x2715;
      goto LAB_00006243;
    }
    if (param_3 == (int *)0x0) {
      return 0x2715;
    }
    uVar7 = param_1[0xf];
    param_1[0xf] = uVar7 & 0xffffffdf;
    if (((uVar7 & 0x400) != 0) || ((uVar7 & 0x10) != 0)) {
      param_1[0xf] = uVar7 & 0xffffffdf | 0x8000;
    }
    FUN_00014cc2(param_1,param_1 + 0xf,0);
    puVar1 = PTR_DAT_002131ad;
    iVar3 = *param_1;
    if (*(int *)(PTR_DAT_002131ad + iVar3 * 4 + 0x18) == 0) {
      iVar3 = _IOServiceOpen(*(undefined4 *)(iVar3 * 4 + *(int *)(PTR_DAT_002131ad + 8)),
                             *(undefined4 *)PTR_002131b5,0,PTR_DAT_002131ad + iVar3 * 4 + 0x18);
      if (iVar3 != 0) goto LAB_000067bf;
      iVar3 = *param_1;
    }
    puVar1[iVar3 + 0x98] = puVar1[iVar3 + 0x98] + '\x01';
    local_3c = (uint)*(byte *)(*(int *)(puVar1 + 0xc) + *param_1);
    local_38 = param_1[0xf] & 0x803f;
    local_24[0] = 0;
    iVar3 = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(puVar1 + *param_1 * 4 + 0x18),7,&local_3c,2,0,local_24);
    if (iVar3 == 0) {
      local_3c = ~(uint)*(byte *)(*(int *)(puVar1 + 0xc) + *param_1);
      local_38 = param_1[0xf] & 0xffff3fc0;
      local_34 = 0;
      local_30 = 0;
      iVar3 = _io_connect_method_scalarI_structureI(param_1[1],0,&local_3c,4,0,0);
      if (iVar3 == 0) goto LAB_00006395;
    }
  }
  uVar6 = 0x2715;
LAB_00006243:
  local_50 = &local_3c;
  ((int (*)())FUN_000060c5)(param_1);
  local_3c = 0;
  local_38 = 0;
  _io_connect_method_scalarI_structureI(param_1[1],0,local_50,4,0,0);
  return uVar6;
}

/* FUN_00006a7e @ 0x6a7e (27 bytes) */
int FUN_00006a7e(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if (*(int *)(param_1 + 0x178) == 0) {
    *(undefined4 *)(param_1 + 0x178) = param_2;
  }
  return;
}

/* _gldGetError @ 0x6a99 (24 bytes) */
int _gldGetError(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x178);
  *(undefined4 *)(param_1 + 0x178) = 0;
  return uVar1;
}

/* _gldCreateFence @ 0x6ab1 (423 bytes) */
int _gldCreateFence(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  uint *puVar1;
  undefined *puVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  void *pvVar6;
  uint uVar7;
  byte bVar8;
  uint uVar9;
  int local_30;
  
  piVar3 = _malloc(8);
  *piVar3 = 0;
  piVar3[1] = 0;
  puVar2 = PTR_002131b5;
  do {
    uVar4 = *(uint *)(param_1 + 0x21c) >> 8;
    if (uVar4 != 0) {
      puVar1 = *(uint **)(param_1 + 0x220);
      uVar7 = *puVar1;
      if (uVar7 != 0xffffffff) {
        uVar9 = 0;
LAB_00006b09:
        local_30 = 0;
        break;
      }
      uVar9 = 0;
      while (uVar9 = uVar9 + 1, uVar4 != uVar9) {
        uVar7 = puVar1[uVar9];
        if (uVar7 != 0xffffffff) goto LAB_00006b09;
      }
    }
    iVar5 = _IOConnectMapMemory(*(undefined4 *)(param_1 + 4),4,*(undefined4 *)puVar2,param_1 + 0x218
                                ,param_1 + 0x21c,1);
    if (iVar5 != 0) {
      _free(piVar3);
      *param_2 = 0;
      return 0x2720;
    }
    pvVar6 = _realloc(*(void **)(param_1 + 0x220),*(uint *)(param_1 + 0x21c) >> 5);
    *(void **)(param_1 + 0x220) = pvVar6;
    uVar4 = *(uint *)(param_1 + 0x21c) >> 6;
    _memset((void *)((int)pvVar6 + uVar4),0,uVar4);
  } while( true );
  while (local_30 = local_30 + 1, local_30 != 0x20) {
    bVar8 = (byte)local_30;
    if ((uVar7 >> (bVar8 & 0x1f) & 1) == 0) goto LAB_00006b2f;
  }
  bVar8 = 0;
LAB_00006b2f:
  puVar1[uVar9] = puVar1[uVar9] | 1 << (bVar8 & 0x1f);
  local_30 = local_30 + uVar9 * 0x20;
  *piVar3 = local_30;
  *(undefined4 *)(*(int *)(param_1 + 0x218) + local_30 * 8) =
       *(undefined4 *)(*(int *)(param_1 + 0x1e4) + 0x18);
  *(undefined4 *)(*(int *)(param_1 + 0x218) + 4 + *piVar3 * 8) = 0;
  *(undefined1 *)(piVar3 + 1) = 1;
  *param_2 = piVar3;
  return 0;
}

/* _gldDestroyFence @ 0x6c58 (57 bytes) */
int _gldDestroyFence(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint *puVar1;
  byte bVar2;
  
  bVar2 = (byte)*param_2 & 0x1f;
  puVar1 = (uint *)(*(int *)(param_1 + 0x220) + (*param_2 >> 5) * 4);
  *puVar1 = *puVar1 & (-2 << bVar2 | 0xfffffffeU >> 0x20 - bVar2);
  _free(param_2);
  return 0;
}

/* _gldTestObject @ 0x6c91 (187 bytes) */
int _gldTestObject(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 1) {
    uVar1 = FUN_00009a27(param_1,param_3);
    return uVar1;
  }
  if (param_2 == 0) {
    if ((char)param_3[1] == '\0') {
      iVar3 = *param_3;
      iVar2 = *(int *)(param_1 + 0x218);
      if (*(int *)(iVar2 + 4 + iVar3 * 8) != 0) {
        _gldFlush(param_1);
        iVar3 = *param_3;
        iVar2 = *(int *)(param_1 + 0x218);
      }
      uVar1 = FUN_00017c5b(param_1,*(undefined4 *)(iVar2 + iVar3 * 8));
      *(undefined1 *)(param_3 + 1) = uVar1;
    }
    uVar1 = (undefined1)param_3[1];
  }
  else {
    if (param_2 == 2) {
      uVar1 = FUN_0000a525(param_1,param_3);
      return uVar1;
    }
    if (param_2 != 3) {
      return 1;
    }
    uVar1 = ((int (*)())FUN_00005122)(param_1,param_3);
  }
  return uVar1;
}

/* _gldFinishObject @ 0x6d4c (260 bytes) */
int _gldFinishObject(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 1) {
    FUN_0000994d(param_1,param_3);
    return 0;
  }
  if (param_2 == 0) {
    if ((char)param_3[1] == '\0') {
      iVar3 = *param_3;
      iVar2 = *(int *)(param_1 + 0x218);
      if (*(int *)(iVar2 + 4 + iVar3 * 8) != 0) {
        _gldFlush(param_1);
        iVar3 = *param_3;
        iVar2 = *(int *)(param_1 + 0x218);
      }
      cVar1 = FUN_00017c5b(param_1,*(undefined4 *)(iVar2 + iVar3 * 8));
      *(char *)(param_3 + 1) = cVar1;
      if (cVar1 == '\0') {
        _io_connect_method_scalarI_structureI
                  (*(undefined4 *)(param_1 + 4),9,*(int *)(param_1 + 0x218) + *param_3 * 8,1,0,0);
        *(undefined1 *)(param_3 + 1) = 1;
        return 0;
      }
    }
  }
  else {
    if (param_2 == 2) {
      FUN_0000a448(param_1,param_3);
      return 0;
    }
    if (param_2 != 3) {
      return 0x271a;
    }
    ((int (*)())FUN_00005042)(param_1,param_3);
  }
  return 0;
}

/* _gldCreateFramebuffer @ 0x6e50 (70 bytes) */
int _gldCreateFramebuffer(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = _calloc(1,200);
  *puVar1 = param_3;
  puVar1[1] = param_4;
  iVar3 = 6;
  puVar2 = puVar1;
  do {
    puVar2[0x13] = 0;
    puVar2 = puVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_2 = puVar1;
  return 0;
}

/* _gldReclaimFramebuffer @ 0x6e96 (5 bytes) */
int _gldReclaimFramebuffer()
{
  return;
}

/* _gldDestroyFramebuffer @ 0x6e9b (74 bytes) */
int _gldDestroyFramebuffer(param_1, param_2)
  int param_1;
  void *param_2;
{
  if (*(void **)(param_1 + 0x150) != param_2) {
    _free(param_2);
    return 0;
  }
  FUN_00019040(param_1);
  *(undefined4 *)(param_1 + 0x150) = 0;
  _free(param_2);
  return 0;
}

/* FUN_00006ee5 @ 0x6ee5 (205 bytes) */
int FUN_00006ee5(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = *(int **)(*(int *)(param_1 + 0x18) + 0x1a0);
  iVar1 = *(int *)(param_1 + 0x150);
  if (iVar1 != 0) {
    iVar4 = 0;
    do {
      iVar2 = *(int *)(iVar1 + 0x4c + iVar4 * 4);
      if (iVar2 != 0) {
        *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + -0x10000;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 6);
  }
  if ((piVar5 != (int *)0x0) && (*(int *)(*piVar5 + 0xa0) == 0)) {
    if (*(int *)(piVar5[1] + 0x18) == 0) {
      if (*(int *)(piVar5[1] + 0x1c) == 0) goto LAB_00006f37;
    }
    else {
      cVar3 = FUN_0001906f(param_1,piVar5);
      if (cVar3 != '\0') goto LAB_00006f37;
    }
  }
  piVar5 = (int *)0x0;
LAB_00006f37:
  *(int **)(param_1 + 0x150) = piVar5;
  if (piVar5 != (int *)0x0) {
    iVar4 = 0;
    do {
      iVar2 = piVar5[iVar4 + 0x13];
      if (iVar2 != 0) {
        *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + 0x10000;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 6);
  }
  if ((*(int *)(*(int *)(param_1 + 0x18) + 0x1a0) == 0) && (iVar1 != 0)) {
    FUN_00019040();
    return;
  }
  return;
}

/* FUN_00006fb4 @ 0x6fb4 (191 bytes) */
int FUN_00006fb4(param_1)
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
  if (param_1 < 0xc) {
    if (9 < param_1) {
      return 0x1ff00;
    }
    if (7 < param_1) {
      return 0x1ff80;
    }
    if (5 < param_1) {
      return 0x1ffc0;
    }
    if (param_1 != 5) {
      if (3 < param_1) {
        return 0x1fff0;
      }
      if (param_1 != 3) {
        if (1 < param_1) {
          return 0x1fffc;
        }
        return ~-(uint)(param_1 == 0) + 0x1ffff;
      }
      return 0x1fff8;
    }
    return 0x1ffe0;
  }
  return 0x1fe00;
}

/* FUN_00007073 @ 0x7073 (93 bytes) */
int FUN_00007073(param_1)
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
  if (param_1 < 0x21) {
    if (0x10 < param_1) {
      return 0x3fffc000;
    }
    if (param_1 < 9) {
      return (-(uint)(param_1 == 0) & 0x80000000) + 0x3ffffffc;
    }
    return 0x3fffffc0;
  }
  return 0x3ff00000;
}

/* FUN_000070d0 @ 0x70d0 (98 bytes) */
int FUN_000070d0(param_1)
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
  if (param_1 < 9) {
    if (4 < param_1) {
      return 0xaa9a928;
    }
    if (param_1 < 3) {
      if (param_1 != 2) {
        return (-(uint)(param_1 == 0) & 0xb5525254) + 0xaadada8;
      }
      return 0xaada9a8;
    }
    return 0xaa9a9a8;
  }
  return 0xaa00000;
}

/* _gldChoosePixelFormat @ 0x7132 (1975 bytes) */
int _gldChoosePixelFormat(param_1, param_2)
  undefined4 *param_1;
  uint *param_2;
{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint *puVar8;
  uint *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  undefined4 *puVar12;
  uint uVar13;
  int iVar14;
  uint local_1e0;
  undefined4 *local_1dc;
  undefined1 local_1d6;
  undefined1 local_1d5;
  int local_1d4;
  uint local_1d0;
  uint local_1cc;
  uint local_1c8;
  uint local_1c4;
  uint local_1c0;
  uint local_1bc;
  uint local_1b8;
  uint local_1b4;
  uint local_1b0;
  uint local_1ac;
  uint local_1a8;
  uint local_1a4;
  uint local_1a0;
  uint local_198;
  uint local_194;
  undefined1 local_18d;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  uint local_178;
  uint local_174;
  int local_170;
  int local_16c;
  uint local_154 [4];
  uint local_144;
  uint local_140;
  uint local_13c;
  uint local_138;
  undefined2 local_134;
  undefined2 local_132;
  undefined2 local_130;
  undefined2 local_12e;
  undefined4 local_12c;
  undefined1 local_128;
  undefined1 local_127;
  undefined1 local_126;
  undefined1 local_125;
  uint local_124;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  undefined2 local_30;
  undefined2 local_2e;
  int local_2c;
  undefined4 local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  uint local_20;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0x271e;
  }
  *param_1 = 0;
  pcVar1 = _getenv("GL_REJECT_HW");
  if (pcVar1 != (char *)0x0) {
    return 0;
  }
  local_194 = *(uint *)PTR_DAT_002131ad;
  uVar13 = 0;
  local_1d0 = 0;
  local_1cc = 0;
  local_1c8 = 0;
  local_1c4 = 0;
  local_1c0 = 0;
  local_1bc = 0;
  local_1b8 = 0;
  local_1b4 = 0;
  local_1b0 = 0;
  local_1ac = 0;
  local_1a8 = 0;
  local_1a4 = 0xfffffc;
  local_1d6 = 0;
  local_1d5 = 0;
  local_18d = 0;
  local_18c = 0;
  local_188 = 0;
  local_184 = 0;
  local_178 = 0;
  local_174 = 0x510;
  puVar9 = param_2;
  do {
    if (*puVar9 == 0) {
      uVar2 = ((int (*)())FUN_00006fb4)();
      uVar3 = ((int (*)())FUN_00006fb4)();
      local_1b8 = local_1bc + local_1c0 + local_1b8;
      if ((int)uVar13 < (int)local_1b8) {
        uVar13 = local_1b8;
      }
      uVar4 = local_1a4;
      if (((int)uVar13 < 0x21) && (uVar4 = local_1a4 & 0xff0fffff, 8 < (int)local_1c4)) {
        uVar4 = local_1a4;
      }
      local_1a4 = uVar4;
      uVar4 = ((int (*)())FUN_00007073)();
      uVar13 = ((int (*)())FUN_000070d0)();
      uVar13 = local_1a4 & uVar4 & uVar13;
      uVar5 = ((int (*)())FUN_00007073)();
      uVar4 = ((int (*)())FUN_000070d0)();
      uVar4 = uVar5 & 0xbffffffc & uVar4;
      local_20 = local_194;
      local_21 = 0;
      local_22 = 0;
      local_23 = 0;
      local_24 = local_18d;
      local_28 = local_18c;
      local_2c = CONCAT22((undefined2)local_188,(*(unsigned short *)((unsigned char *)&(local_188) + 2)));
      local_2e = (undefined2)local_184;
      local_30 = (*(unsigned short *)((unsigned char *)&(local_184) + 2));
      local_44 = local_178;
      local_48 = local_174;
      local_4c = 0;
      local_50 = 0;
      if (local_2c == 0) {
        local_18d = 0;
        local_18c = 0;
      }
      uVar5 = local_174;
      if (((local_174 & 2) == 0) && (uVar5 = local_174 | 1, (local_174 & 4) != 0)) {
        uVar5 = local_174;
      }
      local_174 = uVar5;
      local_1e0 = *(uint *)(PTR_DAT_002131ad + 4);
      if (local_1e0 == 0) goto LAB_00007b1c;
      local_1a0 = 0;
      local_1d4 = 0;
      local_1dc = (undefined4 *)0x0;
      local_40 = uVar13;
      local_3c = uVar4;
      local_38 = uVar3 & 0x1ffff;
      local_34 = uVar2 & 0x1ffff;
      do {
        piVar11 = *(int **)(PTR_DAT_002131ad + 8);
        iVar6 = piVar11[local_1a0];
        puVar7 = local_1dc;
        if (iVar6 != 0) {
          if (local_1a0 == 0) {
LAB_0000793c:
            local_198 = 1 << ((byte)local_1a0 & 0x1f);
            uVar5 = local_1a0 + 1;
            if (uVar5 < local_1e0) {
              piVar11 = piVar11 + uVar5;
              do {
                if (iVar6 == *piVar11) {
                  local_198 = local_198 | 1 << ((byte)uVar5 & 0x1f);
                }
                uVar5 = uVar5 + 1;
                piVar11 = piVar11 + 1;
              } while (local_1e0 != uVar5);
            }
            local_198 = local_198 & local_194;
            if (local_198 != 0) {
              local_125 = 0;
              local_126 = 0;
              local_127 = 0;
              local_128 = local_18d;
              local_12c = local_18c;
              local_130 = (*(unsigned short *)((unsigned char *)&(local_188) + 2));
              local_134 = (*(unsigned short *)((unsigned char *)&(local_184) + 2));
              local_154[3] = local_178;
              local_154[2] = local_174;
              local_154[1] = 0;
              local_154[0] = 0;
              if ((local_198 & local_198 - 1) != 0) {
                local_154[2] = local_174 | 0x200;
              }
              local_144 = uVar13;
              local_140 = uVar4;
              local_13c = uVar3 & 0x1ffff;
              local_138 = uVar2 & 0x1ffff;
              local_132 = (undefined2)local_184;
              local_12e = (undefined2)local_188;
              local_124 = local_198;
              local_154[1] = FUN_00015275(local_1a0);
              local_154[1] = local_1a0 << 0x18 | local_154[1];
              iVar6 = FUN_00018934(local_154,local_1d5,local_1d6);
              if (iVar6 != 0) {
                local_1d4 = local_1d4 + iVar6;
                puVar7 = _malloc(local_1d4 * 0x34);
                if (puVar7 == (undefined4 *)0x0) {
                  if (local_1dc == (undefined4 *)0x0) {
                    return 0x2720;
                  }
                  _free(local_1dc);
                  return 0x2720;
                }
                iVar14 = local_1d4 - iVar6;
                if (iVar14 < 1) {
                  iVar14 = 0;
                }
                else {
                  local_16c = 0;
                  puVar10 = local_1dc;
                  puVar12 = puVar7;
                  do {
                    *puVar12 = *puVar10;
                    puVar12[1] = puVar10[1];
                    puVar12[2] = puVar10[2];
                    puVar12[3] = puVar10[3];
                    puVar12[4] = puVar10[4];
                    puVar12[5] = puVar10[5];
                    puVar12[6] = puVar10[6];
                    puVar12[7] = puVar10[7];
                    puVar12[8] = puVar10[8];
                    puVar12[9] = puVar10[9];
                    puVar12[10] = puVar10[10];
                    puVar12[0xb] = puVar10[0xb];
                    puVar12[0xc] = puVar10[0xc];
                    *puVar12 = puVar12 + 0xd;
                    local_16c = local_16c + 1;
                    puVar10 = puVar10 + 0xd;
                    puVar12 = puVar12 + 0xd;
                  } while (iVar14 != local_16c);
                }
                if (iVar14 < local_1d4) {
                  puVar9 = local_154 + ((iVar14 - local_1d4) + iVar6) * 0xd;
                  puVar12 = puVar7 + iVar14 * 0xd + 0xd;
                  local_170 = 0;
                  do {
                    puVar12[-0xc] = puVar9[1];
                    puVar12[-0xb] = puVar9[2];
                    puVar12[-10] = puVar9[3];
                    puVar12[-9] = puVar9[4];
                    puVar12[-8] = puVar9[5];
                    puVar12[-7] = puVar9[6];
                    puVar12[-6] = puVar9[7];
                    puVar12[-5] = puVar9[8];
                    puVar12[-4] = puVar9[9];
                    puVar12[-3] = puVar9[10];
                    puVar12[-2] = puVar9[0xb];
                    puVar12[-1] = puVar9[0xc];
                    puVar12[-0xd] = puVar12;
                    local_170 = local_170 + 1;
                    puVar9 = puVar9 + 0xd;
                    puVar12 = puVar12 + 0xd;
                  } while (local_1d4 - iVar14 != local_170);
                  iVar14 = iVar14 + local_170;
                }
                puVar7[iVar14 * 0xd + -0xd] = 0;
                if (local_1dc != (undefined4 *)0x0) {
                  _free(local_1dc);
                }
              }
            }
          }
          else if (*piVar11 != iVar6) {
            uVar5 = 0;
            do {
              uVar5 = uVar5 + 1;
              if (local_1a0 == uVar5) goto LAB_0000793c;
            } while (piVar11[uVar5] != iVar6);
          }
        }
        local_1dc = puVar7;
        local_1a0 = local_1a0 + 1;
        local_1e0 = *(uint *)(PTR_DAT_002131ad + 4);
      } while (local_1a0 < local_1e0);
      if ((local_1dc != (undefined4 *)0x0) && (local_1d4 < 1)) {
        _free(local_1dc);
LAB_00007b1c:
        local_1dc = (undefined4 *)0x0;
      }
      *param_1 = local_1dc;
      return 0;
    }
    puVar8 = puVar9 + 1;
    switch(*puVar9) {
    default:
      goto LAB_00007403;
    case 2:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0;
      }
      break;
    case 3:
      local_184 = CONCAT22((short)*puVar8,(undefined2)local_184);
      puVar8 = puVar9 + 2;
      break;
    case 4:
      break;
    case 5:
      local_178 = local_178 | 8;
      break;
    case 6:
      local_178 = local_178 | 2;
      break;
    case 7:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      local_184 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_184) + 2)),(short)uVar2);
      break;
    case 8:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)uVar13 < (int)uVar2) {
        uVar13 = uVar2;
      }
      break;
    case 0xb:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)local_1c4 < (int)uVar2) {
        local_1c4 = uVar2;
      }
      break;
    case 0xc:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)local_1d0 < (int)uVar2) {
        local_1d0 = uVar2;
      }
      break;
    case 0xd:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)local_1cc < (int)uVar2) {
        local_1cc = uVar2;
      }
      break;
    case 0xe:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)local_1c8 < (int)uVar2) {
        local_1c8 = uVar2;
      }
      break;
    case 0x14:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)local_1c0 < (int)uVar2) {
        local_1c0 = uVar2;
      }
      break;
    case 0x15:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)local_1bc < (int)uVar2) {
        local_1bc = uVar2;
      }
      break;
    case 0x16:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)local_1b8 < (int)uVar2) {
        local_1b8 = uVar2;
      }
      break;
    case 0x17:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)local_1b4 < (int)uVar2) {
        local_1b4 = uVar2;
      }
      break;
    case 0x18:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)local_1b0 < (int)uVar2) {
        local_1b0 = uVar2;
      }
      break;
    case 0x19:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)local_1ac < (int)uVar2) {
        local_1ac = uVar2;
      }
      break;
    case 0x1a:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      if ((int)local_1a8 < (int)uVar2) {
        local_1a8 = uVar2;
      }
      break;
    case 0x33:
      local_1d5 = 1;
      break;
    case 0x34:
      local_1d6 = 1;
      break;
    case 0x35:
      local_174 = local_174 | 4;
      break;
    case 0x36:
      local_174 = local_174 | 2;
      break;
    case 0x37:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      local_188 = CONCAT22((short)uVar2,(undefined2)local_188);
      break;
    case 0x38:
      uVar2 = *puVar8;
      puVar8 = puVar9 + 2;
      if ((int)uVar2 < 0) {
        return 0x2718;
      }
      local_188 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_188) + 2)),(short)uVar2);
      break;
    case 0x39:
      local_174 = local_174 | 0x800;
      break;
    case 0x3a:
      local_1a4 = 0x3f000000;
      break;
    case 0x3b:
      local_18c = 2;
      break;
    case 0x3c:
      local_18c = 1;
      break;
    case 0x3d:
      local_18d = 1;
      break;
    case 0x4c:
      local_174 = local_174 | 8;
      break;
    case 0x50:
      local_174 = local_174 | 1;
      break;
    case 0x54:
      local_194 = local_194 & *puVar8;
      puVar8 = puVar9 + 2;
      break;
    case 0x5a:
      local_174 = local_174 | 0x2000;
    }
    puVar9 = puVar8;
  } while ((int)puVar8 - (int)param_2 < 0x94);
LAB_00007403:
  return 10000;
}

/* _gldDestroyPixelFormat @ 0x7d36 (31 bytes) */
int _gldDestroyPixelFormat(param_1)
  void *param_1;
{
  if (param_1 != (void *)0x0) {
    _free(param_1);
    return 0;
  }
  return 0x271e;
}

/* _gldGetRendererInfo @ 0x7d55 (430 bytes) */
int _gldGetRendererInfo(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  if (((*(uint *)PTR_DAT_002131ad & param_2) == 0) || ((param_2 & ~*(uint *)PTR_DAT_002131ad) != 0))
  {
    return 0x2719;
  }
  iVar2 = *(int *)(PTR_DAT_002131ad + 4);
  if ((iVar2 == 0) || ((param_2 & 1) != 0)) {
    iVar4 = 0;
LAB_00007dcb:
    piVar1 = *(int **)(PTR_DAT_002131ad + 8);
    iVar4 = *(int *)((int)piVar1 + iVar4);
  }
  else {
    iVar4 = 0;
    do {
      iVar4 = iVar4 + 1;
      if (iVar2 == iVar4) {
        iVar4 = iVar2 * 4;
        goto LAB_00007dcb;
      }
    } while ((param_2 & 1 << ((byte)iVar4 & 0x1f)) == 0);
    piVar1 = *(int **)(PTR_DAT_002131ad + 8);
    iVar4 = piVar1[iVar4];
  }
  if ((iVar2 == 0) || (iVar4 == *piVar1)) {
    iVar5 = 0;
  }
  else {
    iVar5 = 0;
    do {
      iVar5 = iVar5 + 1;
      if (iVar2 == iVar5) break;
    } while (iVar4 != piVar1[iVar5]);
  }
  iVar2 = _IOServiceOpen(iVar4,*(undefined4 *)PTR_002131b5,1,&local_24);
  if (iVar2 == 0) {
    local_20[0] = 3;
    iVar2 = _io_connect_method_scalarI_scalarO(local_24,3,0,0,&local_30,local_20);
    if (iVar2 == 0) {
      *param_1 = 0;
      uVar3 = FUN_00015275(iVar5);
      param_1[1] = iVar5 << 0x18 | uVar3;
      param_1[2] = 0xa513;
      param_1[3] = 0xd;
      *(undefined2 *)(param_1 + 8) = 0;
      *(undefined2 *)((int)param_1 + 0x22) = 0;
      param_1[4] = 0x8400;
      param_1[5] = 0x808000;
      param_1[6] = 0x1c01;
      param_1[7] = 0x80;
      *(undefined2 *)(param_1 + 9) = 0;
      *(undefined2 *)((int)param_1 + 0x26) = 0;
      *(undefined2 *)(param_1 + 10) = 0;
      param_1[0xb] = 0;
      *(undefined1 *)((int)param_1 + 0x2a) = 0;
      param_1[0xc] = local_28;
      param_1[0xd] = local_2c;
      FUN_00018ccb(param_1,local_30);
      _IOServiceClose(local_24);
      return 0;
    }
    _IOServiceClose(local_24);
  }
  return 0x271f;
}

/* _gldInitializeLibrary @ 0x7f03 (112 bytes) */
int _gldInitializeLibrary(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_DAT_002131ad;
  *(undefined4 *)(PTR_DAT_002131ad + 8) = param_1;
  *(undefined4 *)(puVar1 + 0xc) = param_2;
  *(uint *)puVar1 = param_3;
  *(undefined4 *)(puVar1 + 4) = 0;
  iVar2 = 0;
  do {
    while( true ) {
      *(undefined4 *)(puVar1 + iVar2 * 4 + 0x18) = 0;
      puVar1[iVar2 + 0x98] = 0;
      if ((1 << ((byte)iVar2 & 0x1f) & param_3) == 0) break;
      iVar2 = iVar2 + 1;
      *(int *)(puVar1 + 4) = iVar2;
      if (0x1f < iVar2) goto LAB_00007f62;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x20);
LAB_00007f62:
  *(undefined4 *)(puVar1 + 0x10) = param_4;
  *(undefined4 *)(puVar1 + 0x14) = param_5;
  return;
}

/* _gldTerminateLibrary @ 0x7f73 (57 bytes) */
int _gldTerminateLibrary()
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_002131ad;
  *(undefined4 *)(PTR_DAT_002131ad + 8) = 0;
  *(undefined4 *)(puVar1 + 0xc) = 0;
  *(undefined4 *)puVar1 = 0;
  *(undefined4 *)(puVar1 + 4) = 0;
  *(undefined4 *)(puVar1 + 0x10) = 0;
  *(undefined4 *)(puVar1 + 0x14) = 0;
  return;
}

/* _gldIsTextureResident @ 0x7fac (19 bytes) */
int _gldIsTextureResident(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return *(int *)(param_2 + 0x34) != 0;
}

/* _gldCreateTexture @ 0x7fbf (152 bytes) */
int _gldCreateTexture(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = _calloc(1,0xd8);
  puVar1[0xc] = param_3;
  puVar1[0xd] = 0;
  *puVar1 = 0;
  puVar1[1] = 3;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = puVar1 + 7;
  puVar1[7] = 0;
  puVar1[8] = puVar1 + 6;
  *(undefined1 *)((int)puVar1 + 0x39) = 3;
  *(undefined1 *)(puVar1 + 0xe) = 0;
  *(undefined2 *)(puVar1 + 9) = 0;
  *(undefined2 *)((int)puVar1 + 0x26) = 0;
  *(undefined2 *)(puVar1 + 10) = 0;
  *(undefined2 *)((int)puVar1 + 0x2a) = 0;
  *(undefined2 *)(puVar1 + 0xb) = 0;
  *(undefined2 *)((int)puVar1 + 0x2e) = 0;
  *param_2 = puVar1;
  return 0;
}

/* _gldCreateTextureLevel @ 0x8057 (51 bytes) */
int _gldCreateTextureLevel(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  ushort *puVar1;
  
  *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | param_3;
  if ((param_3 & 1) != 0) {
    *(undefined1 *)(param_2 + 0x38) = 0;
  }
  if ((param_3 & 7) != 0) {
    puVar1 = (ushort *)(param_2 + 0x24 + param_4 * 2);
    *puVar1 = *puVar1 | (ushort)(1 << (param_5 & 0x1f));
  }
  return 0;
}

/* _gldModifyTexture @ 0x808a (20 bytes) */
int _gldModifyTexture(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | param_3;
  return 0;
}

/* _gldModifyTextureLevel @ 0x809e (116 bytes) */
int _gldModifyTextureLevel(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x34);
  if (param_4 == -1) {
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 0x40;
  }
  else {
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 4;
    puVar1 = (ushort *)(param_2 + 0x24 + param_3 * 2);
    *puVar1 = *puVar1 | (ushort)(1 << ((byte)param_4 & 0x1f));
  }
  if ((iVar2 != 0) && ((byte)(*(char *)(iVar2 + 0x16) - 6U) < 2)) {
    if (0x1ffff < *(int *)(iVar2 + 0x10)) {
      _gldFlush(param_1);
    }
    FUN_0000994d(param_1,param_2);
    return 0;
  }
  return 0;
}

/* _gldGetTextureLevelInfo @ 0x8112 (434 bytes) */
int _gldGetTextureLevelInfo(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  uint param_5;
  uint *param_6;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  byte local_10;
  
  FUN_0002e92a(param_1,param_2,param_3,param_4,&local_34);
  if ((*(byte *)(*(int *)(param_2 + 0x30) + 1) & 1) != 0) {
    uVar1 = FUN_0000985b(param_1,param_2);
    iVar3 = param_1;
    do {
      if (*(int *)(iVar3 + 0x18c) != 0) {
        iVar2 = FUN_0000985b(param_1,*(int *)(iVar3 + 0x18c));
        uVar1 = uVar1 + iVar2;
      }
      iVar3 = iVar3 + 4;
    } while (param_1 + 0x40 != iVar3);
    if (*(uint *)(param_1 + 0x28) < uVar1) {
      *param_6 = 0;
      return 0x2720;
    }
  }
  if (param_5 == 0x805f) {
    *param_6 = local_24;
    return 0;
  }
  if (param_5 < 0x8060) {
    if (param_5 == 0x805c) {
      *param_6 = local_30;
    }
    else if (param_5 < 0x805d) {
      if (param_5 != 0x1003) {
        return 0;
      }
      *param_6 = local_34;
    }
    else if (param_5 == 0x805d) {
      *param_6 = local_2c;
    }
    else {
      if (param_5 != 0x805e) {
        return 0;
      }
      *param_6 = local_28;
    }
  }
  else {
    if (param_5 == 0x86a0) {
      *param_6 = local_14;
      return 0;
    }
    if (param_5 < 0x86a1) {
      if (param_5 == 0x8060) {
        *param_6 = local_20;
      }
      else {
        if (param_5 != 0x8061) {
          return 0;
        }
        *param_6 = local_1c;
      }
    }
    else if (param_5 == 0x86a1) {
      *param_6 = (uint)local_10;
    }
    else {
      if (param_5 != 0x884a) {
        return 0;
      }
      *param_6 = local_18;
    }
  }
  return 0;
}

/* _gldDeleteTextureLevel @ 0x82c4 (180 bytes) */
int _gldDeleteTextureLevel(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  ushort *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_4 == -1) {
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 0x43;
  }
  else {
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 7;
    puVar1 = (ushort *)(param_2 + 0x24 + param_3 * 2);
    *puVar1 = *puVar1 | (ushort)(1 << ((byte)param_4 & 0x1f));
  }
  iVar2 = *(int *)(param_2 + 0x34);
  if ((iVar2 != 0) && ((byte)(*(char *)(iVar2 + 0x16) - 6U) < 2)) {
    if (0x1ffff < *(int *)(iVar2 + 0x10)) {
      _gldFlush(param_1);
    }
    iVar3 = *(int *)(iVar2 + 0x10);
    *(int *)(iVar2 + 0x10) = iVar3 + -0x10000;
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar2,1,0,0);
    }
    *(undefined4 *)(param_2 + 0x34) = 0;
    return 0;
  }
  return 0;
}

/* _gldReclaimTexture @ 0x8378 (352 bytes) */
int _gldReclaimTexture(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    while (param_2 != *(int *)(param_1 + 0x18c + iVar4 * 4)) {
      iVar4 = iVar4 + 1;
      if (iVar4 == 0x10) goto LAB_000083ba;
    }
    *(undefined4 *)(param_1 + 0x18c + iVar4 * 4) = 0;
    FUN_0002e333(param_1,iVar4);
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x10);
LAB_000083ba:
  iVar4 = *(int *)(param_2 + 0x34);
  if (iVar4 != 0) {
    if ((0x1ffff < *(int *)(iVar4 + 0x10)) || ((short)*(int *)(iVar4 + 0x10) != 0)) {
      _gldFlush(param_1);
    }
    FUN_0000994d(param_1,param_2);
    iVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x10) = iVar1 + -0x10000;
    if (iVar1 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
    }
    *(undefined4 *)(param_2 + 0x34) = 0;
  }
  piVar2 = *(int **)(param_2 + 0x18);
  iVar4 = *piVar2;
  while (iVar4 != 0) {
    piVar3 = (int *)piVar2[1];
    *piVar3 = iVar4;
    *(int **)(*piVar2 + 4) = piVar3;
    piVar2[1] = 0;
    *piVar2 = 0;
    if (piVar2 == (int *)0x0) break;
    iVar4 = piVar2[4];
    iVar1 = *(int *)(iVar4 + 0x10);
    *(int *)(iVar4 + 0x10) = iVar1 + -0x10000;
    if (iVar1 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
    }
    piVar2[4] = 0;
    _free(piVar2);
    piVar2 = *(int **)(param_2 + 0x18);
    iVar4 = *piVar2;
  }
  *(undefined1 *)(param_2 + 0x39) = 0x23;
  return;
}

