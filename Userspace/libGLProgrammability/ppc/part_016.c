#include "decls.h"

/* _glpPPDisassemble @ 0x97be9d30 (27772 bytes) */
int _glpPPDisassemble(param_1)
  uint *param_1;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  char acVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  undefined1 *puVar13;
  int iVar14;
  void *pvVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  uint *puVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  size_t sVar23;
  float *pfVar24;
  byte in_xer_so;
  uint uVar25;
  undefined8 uVar26;
  char local_2b0;
  char acStack_2af [255];
  char local_1b0 [256];
  int local_b0;
  void *local_ac;
  undefined1 *local_a8;
  uint local_a4;
  uint local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  void *local_88;
  void *local_84;
  void *local_80;
  void *local_7c;
  int *local_78;
  void *local_74;
  void *local_70;
  size_t local_6c;
  int local_68;
  uint local_64;
  char *local_60;
  int local_5c;
  int local_58;
  
  local_b0 = 0x800;
  local_9c = 1;
  local_ac = _malloc(0x800);
  local_90 = 0;
  local_88 = (void *)0x0;
  local_84 = (void *)0x0;
  local_80 = (void *)0x0;
  local_7c = (void *)0x0;
  local_78 = (int *)0x0;
  local_74 = (void *)0x0;
  local_70 = (void *)0x0;
  local_6c = 0;
  local_68 = 0;
  if (local_ac == (void *)0x0) {
    return (void *)0x0;
  }
  uVar16 = *param_1;
  local_64 = (uint)(uVar16 - 0x8b30 < 2);
  if (uVar16 == 0x8804) {
    iVar20 = 0;
    cVar5 = s___ARBfp1_0_97c2d8bc[0];
    while (cVar5 != '\0') {
      *(char *)((int)local_ac + iVar20) = cVar5;
      cVar5 = "!!ARBfp1.0\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
  }
  else if (uVar16 < 0x8805) {
    if (uVar16 == 0x8620) {
      iVar20 = 0;
      cVar5 = s___ARBvp1_0_97c2d89c[0];
      while (cVar5 != '\0') {
        *(char *)((int)local_ac + iVar20) = cVar5;
        cVar5 = "!!ARBvp1.0\n"[iVar20 + 1];
        iVar20 = iVar20 + 1;
      }
    }
    else {
LAB_97be9f08:
      iVar20 = 0;
      cVar5 = s_Unkown_Target__error__97c2d8e0[0];
      while (cVar5 != '\0') {
        *(char *)((int)local_ac + iVar20) = cVar5;
        cVar5 = "Unkown Target (error)\n"[iVar20 + 1];
        iVar20 = iVar20 + 1;
      }
    }
  }
  else if (uVar16 == 0x8b30) {
    iVar20 = 0;
    cVar5 = s___ARBfragmentshader_97c2d8c8[0];
    while (cVar5 != '\0') {
      *(char *)((int)local_ac + iVar20) = cVar5;
      cVar5 = "!!ARBfragmentshader\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
  }
  else {
    if (uVar16 != 0x8b31) goto LAB_97be9f08;
    iVar20 = 0;
    cVar5 = s___ARBvertexshader_97c2d8a8[0];
    while (cVar5 != '\0') {
      *(char *)((int)local_ac + iVar20) = cVar5;
      cVar5 = "!!ARBvertexshader\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
  }
  local_a8 = (undefined1 *)((int)local_ac + iVar20);
  bVar2 = local_64 == 0;
  if (!bVar2) {
    iVar20 = 0;
    cVar5 = s__97c26c38[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
  }
  uVar17 = param_1[0x12];
  iVar20 = 0;
  uVar9 = param_1[0x13];
  if (0 < (int)uVar17) {
    local_60 = "o intialize the Preprocessor";
    do {
      iVar11 = 0;
      cVar5 = s_OPTION_97c2d8fc[0];
      while (cVar5 != '\0') {
        local_a8[iVar11] = cVar5;
        cVar5 = "OPTION "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      local_a8 = local_a8 + iVar11;
      switch(param_1[uVar9 * 2 + iVar20 * 2] & 0xff) {
      case 0:
        iVar11 = 0;
        cVar5 = s_ARB_position_invariant_97c2d904[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_position_invariant"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 1:
        iVar11 = 0;
        cVar5 = s_ARB_fog_exp_97c2d91c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_fog_exp"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 2:
        iVar11 = 0;
        cVar5 = s_ARB_fog_exp2_97c2d928[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_fog_exp2"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 3:
        iVar11 = 0;
        cVar5 = s_ARB_fog_linear_97c2d938[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_fog_linear"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 4:
        iVar11 = 0;
        cVar5 = s_ARB_precision_hint_fastest_97c2d948[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_precision_hint_fastest"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 5:
        iVar11 = 0;
        cVar5 = s_ARB_precision_hint_nicest_97c2d964[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_precision_hint_nicest"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 6:
        iVar11 = 0;
        cVar5 = s_APPLE_no_runtime_compile_97c2d980[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "APPLE_no_runtime_compile"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 7:
        iVar11 = 0;
        cVar5 = s_APPLE_no_altivec_97c2d99c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "APPLE_no_altivec"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 8:
        iVar11 = 0;
        cVar5 = s_NV_fragment_program_97c2d9b0[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "NV_fragment_program"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 9:
        iVar11 = 0;
        cVar5 = s_NV_fragment_program2_97c2d9c4[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "NV_fragment_program2"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 10:
        iVar11 = 0;
        cVar5 = s_NV_vertex_program2_97c2d9f8[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "NV_vertex_program2"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 0xb:
        iVar11 = 0;
        cVar5 = s_NV_vertex_program3_97c2da0c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "NV_vertex_program3"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 0xc:
        iVar11 = 0;
        cVar5 = s_ARB_draw_buffers_97c2da20[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_draw_buffers"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 0xd:
        iVar11 = 0;
        cVar5 = s_ARB_fragment_program_shadow_97c2d9dc[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ARB_fragment_program_shadow"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      default:
        goto switchD_97bea038_default;
      }
      local_a8 = local_a8 + iVar11;
switchD_97bea038_default:
      iVar11 = 0;
      cVar5 = local_60[0x3bbc];
      while (cVar5 != '\0') {
        local_a8[iVar11] = cVar5;
        iVar11 = iVar11 + 1;
        cVar5 = (local_60 + 0x3bbc)[iVar11];
      }
      local_a8 = local_a8 + iVar11;
      iVar11 = _adjustAllocation(&local_b0,&local_ac,&local_a8);
      if (iVar11 == 0) goto LAB_97bf0cec;
      iVar20 = iVar20 + 1;
    } while (iVar20 < (int)uVar17);
  }
  if ((uVar17 != 0) && (!bVar2)) {
    iVar20 = 0;
    cVar5 = s__97c26c38[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
  }
  uVar9 = param_1[6];
  if (uVar9 != 0) {
    iVar20 = 0;
    cVar5 = s_ADDRESS_adr0_97c2da34[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "ADDRESS adr0"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    iVar11 = 1;
    local_a8 = local_a8 + iVar20;
    if (1 < (int)uVar9) {
      do {
        iVar20 = 0;
        cVar5 = s___adr_97c2da44[0];
        while (cVar5 != '\0') {
          local_a8[iVar20] = cVar5;
          cVar5 = ", adr"[iVar20 + 1];
          iVar20 = iVar20 + 1;
        }
        local_a8 = local_a8 + iVar20;
        iVar21 = iVar11 + 1;
        iVar20 = _ncpy(local_a8,iVar11);
        local_a8 = local_a8 + iVar20;
        iVar11 = iVar21;
      } while (iVar21 < (int)uVar9);
    }
    iVar20 = 0;
    cVar5 = s___97c2d8f8[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = ";\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
    iVar20 = _adjustAllocation(&local_b0,&local_ac,&local_a8);
    if (iVar20 == 0) goto LAB_97bf0cec;
    if (!bVar2) {
      iVar20 = 0;
      cVar5 = s__97c26c38[0];
      while (cVar5 != '\0') {
        local_a8[iVar20] = cVar5;
        cVar5 = "\n"[iVar20 + 1];
        iVar20 = iVar20 + 1;
      }
      local_a8 = local_a8 + iVar20;
    }
  }
  uVar9 = 0;
  bVar3 = true;
  uVar17 = param_1[4];
  puVar19 = param_1 + param_1[5] * 2;
  if (!bVar2) {
    uVar22 = 0xffffffff;
    if ((int)uVar17 < 1) {
LAB_97bea680:
      local_5c = (uint)(byte)(((int)local_80 < 0) << 3 | (0 < (int)local_80) << 2 |
                              (local_80 == (void *)0x0) << 1 | in_xer_so & 1) << 0x1c;
      local_58 = local_5c;
LAB_97bea698:
      local_78 = (int *)0x0;
      if (param_1[0x10] != 0) {
        local_78 = _malloc(param_1[0x10] << 2);
      }
      iVar20 = 0;
      iVar11 = -1;
      local_a4 = 0xffffffff;
      uVar22 = 0xffffffff;
      if (0 < (int)uVar17) {
        iVar21 = 0;
        piVar18 = local_78;
        puVar12 = puVar19;
        do {
          if (uVar22 == 0xffffffff) {
            *(uint *)((uint)*(ushort *)((int)puVar12 + 6) * 4 + (int)local_80) =
                 (uint)*(ushort *)((int)puVar12 + 6);
            iVar14 = _isTempArrayStart(param_1,*(undefined2 *)((int)puVar12 + 6),&local_a4);
            if (iVar14 == 0) {
              *(int *)((int)local_7c + (uint)*(ushort *)((int)puVar12 + 6) * 4) = iVar11;
            }
            else {
              uVar22 = (uint)*(ushort *)((int)puVar12 + 6);
              *(undefined4 *)((int)local_7c + uVar22 * 4) = 0;
              iVar11 = 1;
            }
            bVar1 = *(ushort *)((int)puVar19 + iVar21 + 6) == local_a4;
LAB_97bea790:
            if (bVar1) {
              local_a4 = 0xffffffff;
              uVar22 = 0xffffffff;
              *piVar18 = iVar11;
              piVar18 = piVar18 + 1;
              iVar11 = -1;
            }
          }
          else if ((int)(uint)*(ushort *)((int)puVar12 + 6) <= (int)local_a4) {
            *(uint *)((uint)*(ushort *)((int)puVar12 + 6) * 4 + (int)local_80) = uVar22;
            *(int *)((int)local_7c + (uint)*(ushort *)((int)puVar12 + 6) * 4) = iVar11;
            iVar11 = iVar11 + 1;
            bVar1 = *(ushort *)((int)puVar12 + 6) == local_a4;
            goto LAB_97bea790;
          }
          iVar20 = iVar20 + 1;
          iVar21 = iVar21 + 8;
          puVar12 = puVar12 + 2;
        } while (iVar20 < (int)uVar17);
      }
      local_90 = 0;
      goto LAB_97bea7e0;
    }
    puVar12 = puVar19 + 1;
    uVar25 = uVar17;
    do {
      uVar10 = *puVar12;
      puVar12 = puVar12 + 2;
      if ((int)uVar22 < (int)(uVar10 & 0xffff)) {
        uVar22 = uVar10 & 0xffff;
      }
      uVar25 = uVar25 - 1;
    } while (uVar25 != 0);
    if (uVar22 == 0xffffffff) goto LAB_97bea680;
    sVar23 = uVar22 * 4 + 4;
    local_80 = _malloc(sVar23);
    local_5c = (uint)(byte)(((int)local_80 < 0) << 3 | (0 < (int)local_80) << 2 |
                            (local_80 == (void *)0x0) << 1 | in_xer_so & 1) << 0x1c;
    local_7c = _malloc(sVar23);
    bVar7 = (byte)((uint)local_5c >> 0x18);
    if (!(bool)(bVar7 >> 5 & 1)) {
      local_58 = (uint)(byte)(((int)local_7c < 0) << 3 | (0 < (int)local_7c) << 2 |
                              (local_7c == (void *)0x0) << 1 | in_xer_so & 1) << 0x1c;
      if (local_7c == (void *)0x0) goto joined_r0x97bea678;
      goto LAB_97bea698;
    }
    local_58 = (uint)(byte)(((int)local_7c < 0) << 3 | (0 < (int)local_7c) << 2 |
                            (local_7c == (void *)0x0) << 1 | in_xer_so & 1) << 0x1c;
joined_r0x97bea678:
    if (!(bool)(bVar7 >> 5 & 1)) {
      _free(local_80);
    }
    pvVar15 = local_7c;
    if (!(bool)((byte)((uint)local_58 >> 0x1d) & 1)) {
LAB_97bee10c:
      _free(pvVar15);
    }
LAB_97bf0cec:
    _free(local_ac);
    return (void *)0x0;
  }
  local_5c = (uint)(byte)(((int)local_80 < 0) << 3 | (0 < (int)local_80) << 2 |
                          (local_80 == (void *)0x0) << 1 | in_xer_so & 1) << 0x1c;
  local_58 = local_5c;
LAB_97bea7e0:
  uVar22 = 0;
  local_8c = -1;
  if (0 < (int)uVar17) {
    do {
      iVar20 = uVar22 * 8;
      if (bVar3) {
        uVar9 = puVar19[uVar22 * 2] >> 0x1d;
        if (uVar9 == 1) {
          iVar11 = 0;
          cVar5 = s_LONG_TEMP_97c2da54[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "LONG TEMP "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
LAB_97bea924:
          local_a8 = local_a8 + iVar11;
        }
        else if (uVar9 < 2) {
          if (uVar9 == 0) {
            iVar11 = 0;
            cVar5 = s_TEMP_97c2da4c[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "TEMP "[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            goto LAB_97bea924;
          }
        }
        else if (uVar9 == 2) {
          iVar11 = 0;
          cVar5 = s_SHORT_TEMP_97c2da60[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "SHORT TEMP "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          goto LAB_97bea924;
        }
        bVar3 = false;
        uVar9 = puVar19[uVar22 * 2] >> 0x1d;
      }
      if (bVar2) {
        iVar11 = 0;
        cVar5 = s_tmp_97c2d76c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "tmp"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        iVar20 = _ncpy(local_a8,*(undefined2 *)((int)puVar19 + iVar20 + 6));
        local_a8 = local_a8 + iVar20;
      }
      else {
        iVar11 = *(int *)((int)local_7c + (uint)*(ushort *)((int)puVar19 + iVar20 + 6) * 4);
        if (iVar11 == -1) {
          iVar11 = 0;
          cVar5 = s_tmp_97c2d76c[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "tmp"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar20 = _ncpy(local_a8,*(undefined4 *)
                                   ((int)local_80 + (uint)*(ushort *)((int)puVar19 + iVar20 + 6) * 4
                                   ));
          local_a8 = local_a8 + iVar20;
          uVar25 = puVar19[uVar22 * 2];
          local_a8 = (undefined1 *)
                     _glpWriteSizeTypePrecision
                               (local_a8,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,uVar25 >> 0x1d);
        }
        else {
          if (iVar11 == 0) {
            local_8c = 0;
            iVar11 = 0;
            cVar5 = s_tmp_97c2d76c[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "tmp"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            local_a8 = local_a8 + iVar11;
            iVar11 = _ncpy(local_a8,*(undefined4 *)
                                     ((int)local_80 +
                                     (uint)*(ushort *)((int)puVar19 + iVar20 + 6) * 4));
            iVar20 = 0;
            cVar5 = s___97c29860[0];
            while (cVar5 != '\0') {
              local_a8[iVar20 + iVar11] = cVar5;
              cVar5 = "["[iVar20 + 1];
              iVar20 = iVar20 + 1;
            }
            local_a8 = local_a8 + iVar20 + iVar11;
            iVar20 = local_90 * 4;
            iVar21 = _ncpy(local_a8,local_78[local_90]);
            iVar11 = 0;
            cVar5 = s___97c2d770[0];
            while (cVar5 != '\0') {
              local_a8[iVar11 + iVar21] = cVar5;
              cVar5 = "]"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            local_a8 = local_a8 + iVar11 + iVar21;
            uVar25 = puVar19[uVar22 * 2];
            local_a8 = (undefined1 *)
                       _glpWriteSizeTypePrecision
                                 (local_a8,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,uVar25 >> 0x1d);
          }
          else {
            local_8c = local_8c + 1;
            iVar20 = local_90 << 2;
          }
          if (local_8c + 1 == *(int *)(iVar20 + (int)local_78)) {
            local_8c = -1;
            local_90 = local_90 + 1;
          }
        }
      }
      uVar25 = uVar22 + 1;
      if (uVar25 == uVar17) {
        iVar20 = 0;
        cVar5 = s___97c2d8f8[0];
        while (cVar5 != '\0') {
          local_a8[iVar20] = cVar5;
          cVar5 = ";\n"[iVar20 + 1];
          iVar20 = iVar20 + 1;
        }
LAB_97beacc8:
        local_a8 = local_a8 + iVar20;
      }
      else {
        if (puVar19[uVar22 * 2 + 2] >> 0x1d != uVar9) {
          local_60 = "o intialize the Preprocessor";
          iVar20 = 0;
          cVar5 = s___97c2d8f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar20] = cVar5;
            cVar5 = ";\n"[iVar20 + 1];
            iVar20 = iVar20 + 1;
          }
          bVar3 = true;
          goto LAB_97beacc8;
        }
        if (local_8c == -1) {
          iVar20 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            local_a8[iVar20] = cVar5;
            cVar5 = ", "[iVar20 + 1];
            iVar20 = iVar20 + 1;
          }
          goto LAB_97beacc8;
        }
      }
      iVar20 = _adjustAllocation(&local_b0,&local_ac,&local_a8);
      if (iVar20 == 0) goto LAB_97bf0c18;
      uVar22 = uVar25;
    } while ((int)uVar25 < (int)uVar17);
  }
  if (local_78 != (int *)0x0) {
    _free(local_78);
  }
  if ((uVar17 != 0) && (!bVar2)) {
    iVar20 = 0;
    cVar5 = s__97c26c38[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
  }
  uVar17 = param_1[8];
  iVar20 = 0;
  uVar9 = param_1[9];
  if (0 < (int)uVar17) {
    do {
      uVar22 = param_1[uVar9 * 2 + iVar20 * 2] >> 0x10 & 0xf;
      if (uVar22 != 0) {
        iVar11 = 0;
        cVar5 = s_ATTRIB_att_97c2da6c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "ATTRIB att"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        iVar11 = _ncpy(local_a8,*(undefined2 *)((int)param_1 + iVar20 * 8 + uVar9 * 8 + 6));
        local_a8 = local_a8 + iVar11;
        if (!bVar2) {
          uVar25 = param_1[uVar9 * 2 + iVar20 * 2];
          local_a8 = (undefined1 *)
                     _glpWriteSizeTypePrecision
                               (local_a8,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,uVar25 >> 0x1d);
        }
        if (uVar16 == 0x8804) {
LAB_97beae94:
          iVar11 = 0;
          cVar5 = s___fragment__97c2da84[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = " = fragment."[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
LAB_97beaecc:
          local_a8 = local_a8 + iVar11;
        }
        else {
          if (uVar16 < 0x8805) {
            uVar25 = 0x8620;
          }
          else {
            if (uVar16 == 0x8b30) goto LAB_97beae94;
            uVar25 = 0x8b31;
          }
          if (uVar16 == uVar25) {
            iVar11 = 0;
            cVar5 = s___vertex__97c2da78[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = " = vertex."[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            goto LAB_97beaecc;
          }
        }
        switch(uVar22) {
        default:
          goto switchD_97beaef4_caseD_0;
        case 1:
          iVar11 = 0;
          cVar5 = s_position_97c2da94[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "position"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 2:
          iVar11 = 0;
          cVar5 = s_color_primary_97c2daa0[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "color.primary"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 3:
          iVar11 = 0;
          cVar5 = s_color_secondary_97c2dab0[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "color.secondary"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 4:
          iVar11 = 0;
          cVar5 = s_normal_97c2dac0[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "normal"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 5:
          iVar11 = 0;
          cVar5 = s_fogcoord_97c2dac8[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "fogcoord"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 6:
          iVar11 = 0;
          cVar5 = s_weight__97c2daec[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "weight["[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar11 = _ncpy(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
          local_a8 = local_a8 + iVar11;
          iVar11 = 0;
          cVar5 = s___97c2d770[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "]"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 7:
          iVar11 = 0;
          cVar5 = s_texcoord__97c2dae0[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "texcoord["[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar11 = _ncpy(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
          local_a8 = local_a8 + iVar11;
          iVar11 = 0;
          cVar5 = s___97c2d770[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "]"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 8:
          iVar11 = 0;
          cVar5 = s_matrixindex__97c2daf4[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "matrixindex["[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar11 = _ncpy(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
          local_a8 = local_a8 + iVar11;
          iVar11 = 0;
          cVar5 = s___97c2d770[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "]"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 9:
          iVar11 = 0;
          cVar5 = s_attrib__97c2db04[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "attrib["[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar11 = _ncpy(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
          local_a8 = local_a8 + iVar11;
          iVar11 = 0;
          cVar5 = s___97c2d770[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "]"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        case 10:
          iVar11 = 0;
          cVar5 = s_material__97c2db0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "material."[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) == 0) {
            iVar11 = 0;
            cVar5 = s_front__97c2db18[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "front."[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
LAB_97beb3a8:
            local_a8 = local_a8 + iVar11;
          }
          else if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) == 1) {
            iVar11 = 0;
            cVar5 = s_back__97c2db20[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "back."[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            goto LAB_97beb3a8;
          }
          switch(param_1[uVar9 * 2 + iVar20 * 2] >> 0xc & 0xf) {
          case 0:
            iVar11 = 0;
            cVar5 = s_ambient_97c2db28[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "ambient"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            break;
          case 1:
            iVar11 = 0;
            cVar5 = s_diffuse_97c2db30[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "diffuse"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            break;
          case 2:
            iVar11 = 0;
            cVar5 = s_specular_97c2db38[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "specular"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            break;
          case 3:
            iVar11 = 0;
            cVar5 = s_emission_97c2db44[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "emission"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            break;
          case 4:
            iVar11 = 0;
            cVar5 = s_shininess_97c2db50[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = "shininess"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            break;
          default:
            goto switchD_97beaef4_caseD_0;
          }
          break;
        case 0xb:
          iVar11 = 0;
          cVar5 = s_frontfacing_97c2dad4[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "frontfacing"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
        }
        local_a8 = local_a8 + iVar11;
switchD_97beaef4_caseD_0:
        iVar11 = 0;
        cVar5 = s___97c2d8f8[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        iVar11 = _adjustAllocation(&local_b0,&local_ac,&local_a8);
        if (iVar11 == 0) goto LAB_97bf0c18;
      }
      iVar20 = iVar20 + 1;
    } while (iVar20 < (int)uVar17);
  }
  if ((uVar17 != 0) && (!bVar2)) {
    iVar20 = 0;
    cVar5 = s__97c26c38[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
  }
  uVar9 = param_1[10];
  puVar19 = param_1 + param_1[0xb] * 2;
  if (uVar9 == 0) {
    bVar3 = local_88 == (void *)0x0;
    goto LAB_97bed528;
  }
  uVar17 = 0xffffffff;
  if ((int)uVar9 < 1) {
LAB_97beb670:
    bVar3 = local_88 == (void *)0x0;
  }
  else {
    puVar12 = puVar19 + 1;
    uVar22 = uVar9;
    do {
      uVar25 = *puVar12;
      puVar12 = puVar12 + 2;
      if ((int)uVar17 < (int)(uVar25 & 0xffff)) {
        uVar17 = uVar25 & 0xffff;
      }
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
    if (uVar17 == 0xffffffff) goto LAB_97beb670;
    sVar23 = uVar17 * 4 + 4;
    local_88 = _malloc(sVar23);
    bVar1 = local_88 == (void *)0x0;
    local_84 = _malloc(sVar23);
    if ((bVar1) || (bVar3 = false, local_84 == (void *)0x0)) {
      bVar3 = local_84 == (void *)0x0;
joined_r0x97beb668:
      if (!bVar1) {
        _free(local_88);
      }
      if (!bVar3) {
        _free(local_84);
      }
LAB_97bf0c18:
      bVar7 = (byte)((uint)local_5c >> 0x18);
      goto joined_r0x97bea678;
    }
  }
  local_78 = (int *)0x0;
  if (param_1[0xe] != 0) {
    local_78 = _malloc(param_1[0xe] << 2);
  }
  iVar20 = 0;
  iVar11 = -1;
  local_a0 = 0xffffffff;
  uVar17 = 0xffffffff;
  piVar18 = local_78;
  puVar12 = puVar19;
  if (0 < (int)uVar9) {
    do {
      if ((*puVar12 & 0x1f0000) != 0) {
        if (uVar17 == 0xffffffff) {
          *(uint *)((uint)*(ushort *)((int)puVar12 + 6) * 4 + (int)local_88) =
               (uint)*(ushort *)((int)puVar12 + 6);
          iVar21 = _isParamArrayStart(param_1,*(undefined2 *)((int)puVar12 + 6),&local_a0);
          if (iVar21 == 0) {
            *(int *)((int)local_84 + (uint)*(ushort *)((int)puVar12 + 6) * 4) = iVar11;
          }
          else {
            uVar17 = (uint)*(ushort *)((int)puVar12 + 6);
            *(undefined4 *)((int)local_84 + uVar17 * 4) = 0;
            iVar11 = 1;
          }
          if (*(ushort *)((int)puVar12 + 6) == local_a0) {
LAB_97beb790:
            local_a0 = 0xffffffff;
            *piVar18 = iVar11;
            uVar17 = 0xffffffff;
            piVar18 = piVar18 + 1;
            iVar11 = -1;
          }
        }
        else if ((int)(uint)*(ushort *)((int)puVar12 + 6) <= (int)local_a0) {
          *(uint *)((uint)*(ushort *)((int)puVar12 + 6) * 4 + (int)local_88) = uVar17;
          *(int *)((int)local_84 + (uint)*(ushort *)((int)puVar12 + 6) * 4) = iVar11;
          iVar11 = iVar11 + 1;
          if (*(ushort *)((int)puVar12 + 6) == local_a0) goto LAB_97beb790;
        }
      }
      iVar20 = iVar20 + 1;
      puVar12 = puVar12 + 2;
    } while (iVar20 < (int)uVar9);
  }
  iVar20 = 0;
  local_90 = 0;
  if (0 < (int)uVar9) {
    do {
      iVar11 = iVar20 * 8;
      uVar17 = puVar19[iVar20 * 2] >> 0x10 & 0x1f;
      if (uVar17 == 0) goto LAB_97bed4a8;
      iVar21 = *(int *)((int)local_84 + (uint)*(ushort *)((int)puVar19 + iVar11 + 6) * 4);
      if (iVar21 == -1) {
        iVar21 = 0;
        cVar5 = s_PARAM_prm_97c2db5c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "PARAM prm"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = _ncpy(local_a8,*(undefined4 *)
                                 ((int)local_88 + (uint)*(ushort *)((int)puVar19 + iVar11 + 6) * 4))
        ;
        local_a8 = local_a8 + iVar21;
        if (!bVar2) {
          uVar22 = puVar19[iVar20 * 2];
          local_a8 = (undefined1 *)
                     _glpWriteSizeTypePrecision
                               (local_a8,uVar22 >> 0x18 & 3,0,uVar22 >> 0x1a & 7,uVar22 >> 0x1d);
        }
        iVar21 = 0;
        cVar5 = s___97c2db68[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = " = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
      }
      else if (iVar21 == 0) {
        local_8c = 0;
        iVar21 = 0;
        cVar5 = s_PARAM_prm_97c2db5c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "PARAM prm"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = _ncpy(local_a8,*(undefined4 *)
                                 ((int)local_88 + (uint)*(ushort *)((int)puVar19 + iVar11 + 6) * 4))
        ;
        iVar21 = 0;
        cVar5 = s___97c29860[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        iVar14 = _ncpy(local_a8,local_78[local_90]);
        iVar21 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "]"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        puVar13 = local_a8 + iVar21 + iVar14;
        if (!bVar2) {
          uVar22 = puVar19[iVar20 * 2];
          local_a8 = puVar13;
          puVar13 = (undefined1 *)
                    _glpWriteSizeTypePrecision
                              (puVar13,uVar22 >> 0x18 & 3,0,uVar22 >> 0x1a & 7,uVar22 >> 0x1d);
        }
        iVar21 = 0;
        cVar5 = s_____97c2db6c[0];
        while (local_a8 = puVar13, cVar5 != '\0') {
          puVar13[iVar21] = cVar5;
          cVar5 = " = {\n    "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
      }
      else {
        local_8c = local_8c + 1;
        iVar21 = 0;
        cVar5 = s__97c2db78[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "    "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
      }
      if (uVar17 == 0) {
LAB_97bebb2c:
        iVar14 = 0;
        cVar5 = s_state__97c2db8c[0];
        while (cVar5 != '\0') {
          local_a8[iVar14 + iVar21] = cVar5;
          cVar5 = "state."[iVar14 + 1];
          iVar14 = iVar14 + 1;
        }
      }
      else if (uVar17 < 3) {
        iVar14 = 0;
        cVar5 = s_program__97c2db80[0];
        while (cVar5 != '\0') {
          local_a8[iVar14 + iVar21] = cVar5;
          cVar5 = "program."[iVar14 + 1];
          iVar14 = iVar14 + 1;
        }
      }
      else {
        if (uVar17 != 0x11) goto LAB_97bebb2c;
        iVar14 = 0;
        acVar6 = s__97c23d6c[0];
        while (acVar6 != '\0') {
          local_a8[iVar14 + iVar21] = acVar6;
          acVar6 = ""[iVar14];
          iVar14 = iVar14 + 1;
        }
      }
      local_a8 = local_a8 + iVar14 + iVar21;
      switch(uVar17) {
      default:
        goto switchD_97bebb8c_caseD_0;
      case 1:
        iVar21 = 0;
        cVar5 = s_local__97c2db94[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "local["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0xffff);
        local_a8 = local_a8 + iVar21;
        iVar21 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "]"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        goto LAB_97bed350;
      case 2:
        iVar21 = 0;
        cVar5 = s_env__97c2db9c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "env["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0xffff);
        local_a8 = local_a8 + iVar21;
        iVar21 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "]"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        goto LAB_97bed350;
      case 3:
        iVar21 = 0;
        cVar5 = s_light__97c2dba4[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "light["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0xff);
        iVar21 = 0;
        cVar5 = s____97c2dbac[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "]."[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        switch(puVar19[iVar20 * 2] >> 8 & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_ambient_97c2db28[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "ambient"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_diffuse_97c2db30[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "diffuse"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_specular_97c2db38[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "specular"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_position_97c2da94[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "position"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_spot_direction_97c2dbb0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "spot.direction"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_attenuation_97c2dbc0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "attenuation"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_half_97c2dbcc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "half"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_spotcutoff_97c2dbd4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "spotcutoff"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 4:
        iVar21 = 0;
        cVar5 = s_lightprod__97c2dbe0[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "lightprod["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0xff);
        iVar21 = 0;
        cVar5 = s____97c2dbac[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "]."[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        uVar17 = puVar19[iVar20 * 2] >> 8 & 1;
        if (uVar17 == 0) {
          iVar21 = 0;
          cVar5 = s_front__97c2db18[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "front."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
LAB_97bec0ec:
          local_a8 = local_a8 + iVar21;
        }
        else if (uVar17 == 1) {
          iVar21 = 0;
          cVar5 = s_back__97c2db20[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "back."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          goto LAB_97bec0ec;
        }
        uVar17 = puVar19[iVar20 * 2] >> 9 & 3;
        if (uVar17 == 1) {
          iVar21 = 0;
          cVar5 = s_diffuse_97c2db30[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "diffuse"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        }
        if (uVar17 < 2) {
          if (uVar17 == 0) {
            iVar21 = 0;
            cVar5 = s_ambient_97c2db28[0];
            while (cVar5 != '\0') {
              local_a8[iVar21] = cVar5;
              cVar5 = "ambient"[iVar21 + 1];
              iVar21 = iVar21 + 1;
            }
            break;
          }
        }
        else if (uVar17 == 2) {
          iVar21 = 0;
          cVar5 = s_specular_97c2db38[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "specular"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        }
        goto switchD_97bebb8c_caseD_0;
      case 5:
        if ((puVar19[iVar20 * 2] >> 1 & 7) == 5) {
          iVar21 = 0;
          cVar5 = s_lightmodel__97c2dc00[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "lightmodel."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else {
          iVar21 = 0;
          cVar5 = s_material__97c2db0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "material."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        local_a8 = local_a8 + iVar21;
        if ((puVar19[iVar20 * 2] & 1) == 0) {
          iVar21 = 0;
          cVar5 = s_front__97c2db18[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "front."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
LAB_97bec314:
          local_a8 = local_a8 + iVar21;
        }
        else if ((puVar19[iVar20 * 2] & 1) == 1) {
          iVar21 = 0;
          cVar5 = s_back__97c2db20[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "back."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          goto LAB_97bec314;
        }
        switch(puVar19[iVar20 * 2] >> 1 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_ambient_97c2db28[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "ambient"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_diffuse_97c2db30[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "diffuse"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_specular_97c2db38[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "specular"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_emission_97c2db44[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "emission"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_shininess_97c2db50[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "shininess"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_scenecolor_97c2dc0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "scenecolor"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 6:
        iVar21 = 0;
        cVar5 = s_lightmodel_ambient_97c2dbec[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "lightmodel.ambient"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 7:
        iVar21 = 0;
        cVar5 = s_texgen__97c2dc18[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "texgen["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0x1f);
        iVar21 = 0;
        cVar5 = s___eye__97c2dc20[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "].eye."[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        uVar17 = puVar19[iVar20 * 2] >> 5 & 7;
        if (uVar17 == 1) {
          iVar21 = 0;
          cVar5 = s_t_97c2dc2c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "t"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else if (uVar17 < 2) {
          if (uVar17 != 0) goto switchD_97bebb8c_caseD_0;
          iVar21 = 0;
          cVar5 = s_s_97c2dc28[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "s"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else if (uVar17 == 2) {
          iVar21 = 0;
          cVar5 = s_r_97c2dc30[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "r"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else {
          if (uVar17 != 3) goto switchD_97bebb8c_caseD_0;
          iVar21 = 0;
          cVar5 = s_q_97c2dc34[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "q"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        break;
      case 8:
        iVar21 = 0;
        cVar5 = s_texgen__97c2dc18[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "texgen["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0x1f);
        iVar21 = 0;
        cVar5 = s___object__97c2dc38[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = "].object."[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        uVar17 = puVar19[iVar20 * 2] >> 5 & 7;
        if (uVar17 == 1) {
          iVar21 = 0;
          cVar5 = s_t_97c2dc2c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "t"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else if (uVar17 < 2) {
          if (uVar17 != 0) goto switchD_97bebb8c_caseD_0;
          iVar21 = 0;
          cVar5 = s_s_97c2dc28[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "s"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else if (uVar17 == 2) {
          iVar21 = 0;
          cVar5 = s_r_97c2dc30[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "r"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        else {
          if (uVar17 != 3) goto switchD_97bebb8c_caseD_0;
          iVar21 = 0;
          cVar5 = s_q_97c2dc34[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "q"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        break;
      case 9:
        iVar21 = 0;
        cVar5 = s_texenv__97c2dc44[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "texenv["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0x1f);
        local_a8 = local_a8 + iVar21;
        iVar21 = 0;
        cVar5 = s___color_97c2dc4c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "].color"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        goto LAB_97bed350;
      case 10:
        iVar21 = 0;
        cVar5 = s_clip__97c2dc54[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "clip["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0xff);
        local_a8 = local_a8 + iVar21;
        iVar21 = 0;
        cVar5 = s___plane_97c2dc5c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "].plane"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        goto LAB_97bed350;
      case 0xb:
        iVar21 = 0;
        cVar5 = s_fog_color_97c2dc64[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "fog.color"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 0xc:
        iVar21 = 0;
        cVar5 = s_fog_params_97c2dc70[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "fog.params"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 0xd:
        iVar21 = 0;
        cVar5 = s_point_size_97c2dc88[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "point.size"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 0xe:
        iVar21 = 0;
        cVar5 = s_point_attenuation_97c2dc94[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "point.attenuation"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 0xf:
        iVar21 = 0;
        cVar5 = s_depth_range_97c2dc7c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "depth.range"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 0x10:
        iVar21 = 0;
        cVar5 = s_matrix__97c2dca8[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "matrix."[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(puVar19[iVar20 * 2] >> 8 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_mvp__97c2dcbc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "mvp."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          goto LAB_97becb60;
        case 1:
          iVar21 = 0;
          cVar5 = s_projection__97c2dcb0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "projection."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
LAB_97becb60:
          local_a8 = local_a8 + iVar21;
          goto switchD_97becad4_default;
        case 2:
          iVar21 = 0;
          cVar5 = s_color__97c2dcc4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "color["[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          iVar21 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0xff);
          local_a8 = local_a8 + iVar21;
          iVar21 = 0;
          cVar5 = s____97c2dbac[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "]."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_modelview__97c2dccc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "modelview["[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          iVar21 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0xff);
          local_a8 = local_a8 + iVar21;
          iVar21 = 0;
          cVar5 = s____97c2dbac[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "]."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_texture__97c2d814[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "texture["[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          iVar21 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0xff);
          local_a8 = local_a8 + iVar21;
          iVar21 = 0;
          cVar5 = s____97c2dbac[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "]."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_program__97c2dcd8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "program["[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          iVar21 = _ncpy(local_a8,puVar19[iVar20 * 2] & 0xff);
          local_a8 = local_a8 + iVar21;
          iVar21 = 0;
          cVar5 = s____97c2dbac[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "]."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97becad4_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97becad4_default:
        uVar17 = puVar19[iVar20 * 2] >> 0xe & 3;
        if (uVar17 == 1) {
          iVar21 = 0;
          cVar5 = s_transpose__97c2dce4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "transpose."[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
LAB_97becea0:
          local_a8 = local_a8 + iVar21;
        }
        else if (1 < uVar17) {
          if (uVar17 == 2) {
            iVar21 = 0;
            cVar5 = s_inverse__97c2dcf0[0];
            while (cVar5 != '\0') {
              local_a8[iVar21] = cVar5;
              cVar5 = "inverse."[iVar21 + 1];
              iVar21 = iVar21 + 1;
            }
          }
          else {
            if (uVar17 != 3) goto LAB_97becea8;
            iVar21 = 0;
            cVar5 = s_invtrans__97c2dcfc[0];
            while (cVar5 != '\0') {
              local_a8[iVar21] = cVar5;
              cVar5 = "invtrans."[iVar21 + 1];
              iVar21 = iVar21 + 1;
            }
          }
          goto LAB_97becea0;
        }
LAB_97becea8:
        iVar21 = 0;
        cVar5 = s_row__97c2dd08[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "row["[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar21 = _ncpy(local_a8,puVar19[iVar20 * 2] >> 0xc & 3);
        local_a8 = local_a8 + iVar21;
        iVar21 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "]"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
LAB_97bed350:
        local_a8 = local_a8 + iVar21;
        goto switchD_97bebb8c_caseD_0;
      case 0x11:
        pfVar24 = (float *)(param_1 + param_1[0x1b] * 2 + (puVar19[iVar20 * 2] & 0xffff) * 4);
        switch(puVar19[iVar20 * 2] >> 0x1a & 7) {
        case 0:
        case 1:
          iVar21 = 0;
          cVar5 = s___97c2dd10[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "{"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          uVar26 = ((char * (*)())_glp_dtostr)((double)*pfVar24,DOUBLE_97c30a70);
          iVar14 = (int)((ulonglong)uVar26 >> 0x20);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            *(char *)(iVar14 + iVar21) = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = (undefined1 *)(iVar14 + iVar21);
          uVar26 = ((char * (*)())_glp_dtostr)((double)pfVar24[1],DOUBLE_97c30a70,iVar14,(int)uVar26,local_a8,
                               (int)local_ac + (local_b0 - (int)local_a8));
          iVar14 = (int)((ulonglong)uVar26 >> 0x20);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            *(char *)(iVar14 + iVar21) = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = (undefined1 *)(iVar14 + iVar21);
          uVar26 = ((char * (*)())_glp_dtostr)((double)pfVar24[2],DOUBLE_97c30a70,iVar14,(int)uVar26,local_a8,
                               (int)local_ac + (local_b0 - (int)local_a8));
          iVar14 = (int)((ulonglong)uVar26 >> 0x20);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            *(char *)(iVar14 + iVar21) = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = (undefined1 *)(iVar14 + iVar21);
          local_a8 = (undefined1 *)
                     ((char * (*)())_glp_dtostr)((double)pfVar24[3],DOUBLE_97c30a70,iVar14,(int)uVar26,local_a8,
                                 (int)local_ac + (local_b0 - (int)local_a8));
          iVar21 = 0;
          cVar5 = s___97c2dd14[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "}"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_____Fixed_constant_data_not_curr_97c2dd18[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "{-- Fixed constant data not currently supported --}"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
        case 4:
          iVar21 = 0;
          cVar5 = s___97c2dd10[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "{"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
          iVar14 = _ncpy(local_a8,*pfVar24);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            local_a8[iVar21 + iVar14] = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21 + iVar14;
          iVar14 = _ncpy(local_a8,pfVar24[1]);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            local_a8[iVar21 + iVar14] = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21 + iVar14;
          iVar14 = _ncpy(local_a8,pfVar24[2]);
          iVar21 = 0;
          cVar5 = s___97c2d7ec[0];
          while (cVar5 != '\0') {
            local_a8[iVar21 + iVar14] = cVar5;
            cVar5 = ", "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21 + iVar14;
          iVar21 = _ncpy(local_a8,pfVar24[3]);
          local_a8 = local_a8 + iVar21;
          iVar21 = 0;
          cVar5 = s___97c2dd14[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "}"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          goto LAB_97bed350;
        default:
          goto switchD_97bebb8c_caseD_0;
        }
        break;
      case 0x12:
        iVar21 = 0;
        cVar5 = s_normalscale_97c2dd4c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "normalscale"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
      }
      local_a8 = local_a8 + iVar21;
switchD_97bebb8c_caseD_0:
      if (*(int *)((int)local_84 + (uint)*(ushort *)((int)puVar19 + iVar11 + 6) * 4) == -1) {
        iVar11 = 0;
        cVar5 = s___97c2d8f8[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else if (local_8c + 1 == local_78[local_90]) {
        local_90 = local_90 + 1;
        iVar11 = 0;
        cVar5 = s____97c2dd58[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "\n};\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else {
        iVar11 = 0;
        cVar5 = s___97c2dd60[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = ",\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      local_a8 = local_a8 + iVar11;
      iVar11 = _adjustAllocation(&local_b0,&local_ac,&local_a8);
      bVar1 = bVar3;
      if (iVar11 == 0) goto joined_r0x97beb668;
LAB_97bed4a8:
      iVar20 = iVar20 + 1;
    } while (iVar20 < (int)uVar9);
  }
  if (local_78 != (int *)0x0) {
    _free(local_78);
  }
  iVar20 = 0;
  cVar5 = s__97c26c38[0];
  while (cVar5 != '\0') {
    local_a8[iVar20] = cVar5;
    cVar5 = "\n"[iVar20 + 1];
    iVar20 = iVar20 + 1;
  }
  local_a8 = local_a8 + iVar20;
LAB_97bed528:
  uVar17 = param_1[0xc];
  iVar20 = 0;
  uVar9 = param_1[0xd];
  bVar1 = bVar3;
  if (0 < (int)uVar17) {
    do {
      uVar22 = param_1[uVar9 * 2 + iVar20 * 2] >> 0x10 & 0xf;
      if (uVar22 == 0) goto LAB_97bedcb4;
      uVar25 = param_1[uVar9 * 2 + iVar20 * 2] >> 0x1d;
      if (uVar25 == 1) {
        iVar11 = 0;
        cVar5 = s_LONG_OUTPUT_res_97c2dd70[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "LONG OUTPUT res"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
LAB_97bed644:
        local_a8 = local_a8 + iVar11;
      }
      else if (uVar25 < 2) {
        if (uVar25 == 0) {
          iVar11 = 0;
          cVar5 = s_OUTPUT_res_97c2dd64[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "OUTPUT res"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          goto LAB_97bed644;
        }
      }
      else if (uVar25 == 2) {
        iVar11 = 0;
        cVar5 = s_SHORT_OUTPUT_res_97c2dd80[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "SHORT OUTPUT res"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        goto LAB_97bed644;
      }
      iVar11 = _ncpy(local_a8,*(undefined2 *)((int)param_1 + iVar20 * 8 + uVar9 * 8 + 6));
      local_a8 = local_a8 + iVar11;
      if (!bVar2) {
        uVar25 = param_1[uVar9 * 2 + iVar20 * 2];
        local_a8 = (undefined1 *)
                   _glpWriteSizeTypePrecision
                             (local_a8,uVar25 >> 0x18 & 3,0,uVar25 >> 0x1a & 7,uVar25 >> 0x1d);
      }
      iVar11 = 0;
      cVar5 = s___97c2db68[0];
      while (cVar5 != '\0') {
        local_a8[iVar11] = cVar5;
        cVar5 = " = "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      local_a8 = local_a8 + iVar11;
      switch(uVar22) {
      default:
        goto switchD_97bed6f4_caseD_0;
      case 1:
        iVar11 = 0;
        cVar5 = s_result_position_97c2dd94[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.position"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 2:
        iVar11 = 0;
        cVar5 = s_result_fogcoord_97c2dda4[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.fogcoord"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 3:
        iVar11 = 0;
        cVar5 = s_result_pointsize_97c2ddb4[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.pointsize"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 4:
        iVar11 = 0;
        cVar5 = s_result_color_97c2ddc8[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.color"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        if ((uVar16 == 0x8620) || (uVar16 == 0x8b31)) {
          if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) == 0) {
            iVar11 = 0;
            cVar5 = s__front_primary_97c2ddd8[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = ".front.primary"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          else {
            if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) != 1) goto switchD_97bed6f4_caseD_0;
            iVar11 = 0;
            cVar5 = s__back_primary_97c2dde8[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = ".back.primary"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          break;
        }
        if (((uVar16 == 0x8804) || (uVar16 == 0x8b30)) &&
           (1 < (param_1[uVar9 * 2 + iVar20 * 2] >> 1 & 7))) {
          iVar11 = 0;
          cVar5 = s___97c29860[0];
          while (cVar5 != '\0') {
            local_a8[iVar11] = cVar5;
            cVar5 = "["[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11;
          iVar21 = _ncpy(local_a8,param_1[uVar9 * 2 + iVar20 * 2] >> 1 & 7);
          iVar11 = 0;
          cVar5 = s___97c2d770[0];
          while (cVar5 != '\0') {
            local_a8[iVar11 + iVar21] = cVar5;
            cVar5 = "]"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          local_a8 = local_a8 + iVar11 + iVar21;
        }
        goto switchD_97bed6f4_caseD_0;
      case 5:
        iVar11 = 0;
        cVar5 = s_result_color_97c2ddc8[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.color"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        if ((uVar16 == 0x8620) || (uVar16 == 0x8b31)) {
          if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) == 0) {
            iVar11 = 0;
            cVar5 = s__front_secondary_97c2ddf8[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = ".front.secondary"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          else {
            if ((param_1[uVar9 * 2 + iVar20 * 2] & 1) != 1) goto switchD_97bed6f4_caseD_0;
            iVar11 = 0;
            cVar5 = s__back_secondary_97c2de0c[0];
            while (cVar5 != '\0') {
              local_a8[iVar11] = cVar5;
              cVar5 = ".back.secondary"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          break;
        }
        goto switchD_97bed6f4_caseD_0;
      case 6:
        iVar11 = 0;
        cVar5 = s_result_texcoord__97c2de1c[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.texcoord["[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        iVar11 = _ncpy(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
        local_a8 = local_a8 + iVar11;
        iVar11 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "]"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 7:
        iVar11 = 0;
        cVar5 = s_result_depth_97c2de30[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.depth"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 8:
        iVar11 = 0;
        cVar5 = s_result_eyePosition_97c2de50[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.eyePosition"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 9:
        iVar11 = 0;
        cVar5 = s_result_clipVertex_97c2de64[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.clipVertex"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      case 10:
        iVar11 = 0;
        cVar5 = s_result_attrib__97c2de40[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "result.attrib["[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        local_a8 = local_a8 + iVar11;
        iVar11 = _ncpy(local_a8,param_1[uVar9 * 2 + iVar20 * 2] & 0x1f);
        local_a8 = local_a8 + iVar11;
        iVar11 = 0;
        cVar5 = s___97c2d770[0];
        while (cVar5 != '\0') {
          local_a8[iVar11] = cVar5;
          cVar5 = "]"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      local_a8 = local_a8 + iVar11;
switchD_97bed6f4_caseD_0:
      iVar11 = 0;
      cVar5 = s___97c2d8f8[0];
      while (cVar5 != '\0') {
        local_a8[iVar11] = cVar5;
        cVar5 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      local_a8 = local_a8 + iVar11;
      iVar11 = _adjustAllocation(&local_b0,&local_ac,&local_a8);
      if (iVar11 == 0) goto joined_r0x97beb668;
LAB_97bedcb4:
      iVar20 = iVar20 + 1;
    } while (iVar20 < (int)uVar17);
  }
  if ((uVar17 != 0) || (bVar2)) {
    iVar20 = 0;
    cVar5 = s__97c26c38[0];
    while (cVar5 != '\0') {
      local_a8[iVar20] = cVar5;
      cVar5 = "\n"[iVar20 + 1];
      iVar20 = iVar20 + 1;
    }
    local_a8 = local_a8 + iVar20;
  }
  uVar17 = param_1[0x14];
  iVar20 = 0;
  uVar9 = param_1[0x15];
  uVar16 = uVar17;
  if (0 < (int)uVar17) {
    do {
      if ((param_1[uVar9 * 2 + iVar20 * 2] >> 0x12 & 0xff) - 0x4b < 2) {
        local_6c = local_6c + 1;
      }
      iVar20 = iVar20 + (param_1[uVar9 * 2 + iVar20 * 2] >> 0x1d) + 2;
      uVar16 = uVar16 - 1;
    } while (uVar16 != 0);
  }
  bVar4 = local_6c == 0;
  if (!bVar4) {
    sVar23 = local_6c << 2;
    iVar20 = 0;
    iVar11 = 0;
    local_74 = _malloc(sVar23);
    _memset(local_74,0,local_6c);
    local_70 = _malloc(sVar23);
    _memset(local_70,0,local_6c);
    local_6c = 0;
    bVar4 = true;
    if (0 < (int)uVar17) {
      do {
        uVar16 = param_1[uVar9 * 2 + iVar11 * 2];
        if ((uVar16 >> 0x12 & 0xff) - 0x4b < 2) {
          local_6c = _InsertLabel(local_74,local_70,param_1[uVar9 * 2 + iVar11 * 2 + 1] & 0x3ffff,
                                  uVar16 & 0x3ffff,local_6c);
          uVar16 = param_1[uVar9 * 2 + iVar11 * 2];
        }
        iVar20 = iVar20 + 1;
        iVar11 = iVar11 + (uVar16 >> 0x1d) + 2;
        bVar4 = local_6c == 0;
      } while (iVar20 < (int)uVar17);
    }
  }
  iVar20 = 0;
  iVar11 = 0;
  if (0 < (int)uVar17) {
    puVar19 = (uint *)(local_68 * 4 + (int)local_74);
    do {
      if (((param_1[uVar9 * 2 + iVar11 * 2] & 0x3ffff) == 0) && (!bVar2)) {
        iVar21 = 0;
        cVar5 = s_main__97c2de78[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "main:\n"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
      }
      if (((!bVar4) && (local_68 < (int)local_6c)) &&
         ((param_1[uVar9 * 2 + iVar11 * 2] & 0x3ffff) == *puVar19)) {
        iVar21 = 0;
        local_9c = local_9c + -1;
        if (0 < local_9c) {
          do {
            iVar14 = 0;
            cVar5 = s__97c28c28[0];
            while (cVar5 != '\0') {
              local_a8[iVar14] = cVar5;
              cVar5 = "  "[iVar14 + 1];
              iVar14 = iVar14 + 1;
            }
            iVar21 = iVar21 + 1;
            local_a8 = local_a8 + iVar14;
          } while (iVar21 < local_9c);
        }
        iVar21 = 0;
        cVar5 = s_label__97c2de80[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "label_"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        iVar14 = _ncpy(local_a8,local_68);
        local_68 = local_68 + 1;
        puVar19 = puVar19 + 1;
        iVar21 = 0;
        cVar5 = s___97c2de88[0];
        while (cVar5 != '\0') {
          local_a8[iVar21 + iVar14] = cVar5;
          cVar5 = ":\n"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21 + iVar14;
        local_9c = local_9c + 1;
      }
      uVar16 = param_1[uVar9 * 2 + iVar11 * 2] >> 0x12 & 0xff;
      if (((uVar16 == 0x6b) || (uVar16 == 0x58)) ||
         ((uVar16 == 0x59 || ((uVar16 == 0x5a || (uVar16 == 0x5b)))))) {
        local_9c = local_9c + -1;
      }
      _glpDisassemble1Op(param_1 + uVar9 * 2 + iVar11 * 2,local_a8,&local_98,&local_94,local_88,
                         local_84,local_80,local_7c);
      local_a8 = local_a8 + local_94;
      iVar11 = iVar11 + local_98;
      iVar21 = _adjustAllocation(&local_b0,&local_ac,&local_a8);
      if (iVar21 == 0) {
        if (!bVar3) {
          _free(local_88);
          _free(local_84);
        }
        if (!(bool)((byte)((uint)local_5c >> 0x1d) & 1)) {
          _free(local_80);
        }
        if (!(bool)((byte)((uint)local_58 >> 0x1d) & 1)) {
          _free(local_7c);
        }
        if (bVar4) goto LAB_97bf0cec;
        _free(local_74);
        pvVar15 = local_70;
        goto LAB_97bee10c;
      }
      iVar20 = iVar20 + 1;
      iVar11 = iVar11 + 1;
    } while (iVar20 < (int)uVar17);
  }
  if (!bVar4) {
    if ((local_68 < (int)local_6c) && (iVar20 + 1 == *(int *)((int)local_74 + local_68 * 4))) {
      iVar20 = 0;
      cVar5 = s_label__97c2de8c[0];
      while (cVar5 != '\0') {
        local_a8[iVar20] = cVar5;
        cVar5 = "  label_"[iVar20 + 1];
        iVar20 = iVar20 + 1;
      }
      local_a8 = local_a8 + iVar20;
      iVar11 = _ncpy(local_a8,local_68);
      iVar20 = 0;
      cVar5 = s___97c2de88[0];
      while (cVar5 != '\0') {
        local_a8[iVar20 + iVar11] = cVar5;
        cVar5 = ":\n"[iVar20 + 1];
        iVar20 = iVar20 + 1;
      }
      local_a8 = local_a8 + iVar20 + iVar11;
    }
    _free(local_74);
    _free(local_70);
  }
  iVar20 = 0;
  cVar5 = s_END_97c2de98[0];
  while (cVar5 != '\0') {
    local_a8[iVar20] = cVar5;
    cVar5 = "END\n"[iVar20 + 1];
    iVar20 = iVar20 + 1;
  }
  uVar9 = param_1[0x18];
  iVar11 = 0;
  uVar16 = param_1[0x19];
  local_a8 = local_a8 + iVar20;
  iVar20 = 0;
  if (0 < (int)uVar9) {
    local_60 = "o intialize the Preprocessor";
    do {
      uVar17 = param_1[uVar16 * 2 + iVar20 * 2];
      iVar21 = 0;
      cVar5 = s_STATE_97c2dea0[0];
      while (cVar5 != '\0') {
        local_a8[iVar21] = cVar5;
        cVar5 = "STATE "[iVar21 + 1];
        iVar21 = iVar21 + 1;
      }
      local_a8 = local_a8 + iVar21;
      switch(uVar17 >> 0x18 & 7) {
      case 0:
        iVar21 = 0;
        cVar5 = s_ALPHA_TEST_97c2dea8[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "ALPHA_TEST "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        switch(param_1[uVar16 * 2 + iVar20 * 2] & 7) {
        case 0:
          iVar14 = 0;
          cVar5 = s_PP_NEVER_97c2deb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_NEVER "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 1:
          iVar14 = 0;
          cVar5 = s_PP_LESS_97c2dec0[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_LESS "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 2:
          iVar14 = 0;
          cVar5 = s_PP_EQUAL_97c2decc[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_EQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 3:
          iVar14 = 0;
          cVar5 = s_PP_LEQUAL_97c2ded8[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_LEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 4:
          iVar14 = 0;
          cVar5 = s_PP_GREATER_97c2dee4[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_GREATER "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 5:
          iVar14 = 0;
          cVar5 = s_PP_NOTEQUAL_97c2def0[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_NOTEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 6:
          iVar14 = 0;
          cVar5 = s_PP_GEQUAL_97c2df00[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_GEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        default:
          iVar14 = 0;
          cVar5 = s_PP_ALWAYS_97c2df0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_ALWAYS "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
        }
        iVar8 = 0;
        cVar5 = s_ref__97c2df18[0];
        while (cVar5 != '\0') {
          local_a8[iVar8 + iVar14 + iVar21] = cVar5;
          cVar5 = "ref="[iVar8 + 1];
          iVar8 = iVar8 + 1;
        }
        local_a8 = local_a8 + iVar8 + iVar14 + iVar21;
        local_a8 = (undefined1 *)
                   ((char * (*)())_glp_dtostr)((double)(float)param_1[uVar16 * 2 + iVar20 * 2 + 1],DOUBLE_97c30a70);
        goto switchD_97bee2f0_default;
      case 1:
        iVar21 = 0;
        cVar5 = s_STENCIL_TEST_func__97c2df20[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "STENCIL_TEST func="[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0xc & 7) {
        case 0:
          iVar14 = 0;
          cVar5 = s_PP_NEVER_97c2deb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_NEVER "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 1:
          iVar14 = 0;
          cVar5 = s_PP_LESS_97c2dec0[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_LESS "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 2:
          iVar14 = 0;
          cVar5 = s_PP_EQUAL_97c2decc[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_EQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 3:
          iVar14 = 0;
          cVar5 = s_PP_LEQUAL_97c2ded8[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_LEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 4:
          iVar14 = 0;
          cVar5 = s_PP_GREATER_97c2dee4[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_GREATER "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 5:
          iVar14 = 0;
          cVar5 = s_PP_NOTEQUAL_97c2def0[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_NOTEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        case 6:
          iVar14 = 0;
          cVar5 = s_PP_GEQUAL_97c2df00[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_GEQUAL "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
          break;
        default:
          iVar14 = 0;
          cVar5 = s_PP_ALWAYS_97c2df0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar14 + iVar21] = cVar5;
            cVar5 = "PP_ALWAYS "[iVar14 + 1];
            iVar14 = iVar14 + 1;
          }
        }
        iVar8 = 0;
        cVar5 = s_opfail__97c2df34[0];
        while (cVar5 != '\0') {
          local_a8[iVar8 + iVar14 + iVar21] = cVar5;
          cVar5 = "opfail="[iVar8 + 1];
          iVar8 = iVar8 + 1;
        }
        local_a8 = local_a8 + iVar8 + iVar14 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0xf & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_ZERO_97c2df3c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_KEEP_97c2df50[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_KEEP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_REPLACE_97c2df64[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_REPLACE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_97c2df78[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_97c2df8c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INVERT_97c2dfa0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INVERT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_WRAP_97c2dfb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_WRAP_97c2dfcc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bee894_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97bee894_default:
        iVar21 = 0;
        cVar5 = s_opzfail__97c2dfe4[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "opzfail="[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0x12 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_ZERO_97c2df3c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_KEEP_97c2df50[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_KEEP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_REPLACE_97c2df64[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_REPLACE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_97c2df78[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_97c2df8c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INVERT_97c2dfa0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INVERT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_WRAP_97c2dfb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_WRAP_97c2dfcc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97beeaec_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97beeaec_default:
        iVar21 = 0;
        cVar5 = s_opzpass__97c2dff0[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "opzpass="[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0x15 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_ZERO_97c2df3c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_KEEP_97c2df50[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_KEEP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_REPLACE_97c2df64[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_REPLACE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_97c2df78[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_97c2df8c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INVERT_97c2dfa0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INVERT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_INCR_WRAP_97c2dfb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_INCR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_STENCIL_DECR_WRAP_97c2dfcc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_STENCIL_DECR_WRAP "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97beed44_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97beed44_default:
        _sprintf(&local_2b0,"ref= %#x mask = %#x ",param_1[uVar16 * 2 + iVar20 * 2 + 1] >> 0x18,
                 param_1[uVar16 * 2 + iVar20 * 2 + 1] >> 8 & 0xff);
        iVar21 = 0;
        cVar5 = local_2b0;
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = acStack_2af[iVar21];
          iVar21 = iVar21 + 1;
        }
        break;
      case 2:
        iVar21 = 0;
        cVar5 = s_DEPTH_TEST_func__97c2e014[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "DEPTH_TEST func="[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_NEVER_97c2deb4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_NEVER "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_LESS_97c2dec0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LESS "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_EQUAL_97c2decc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_EQUAL "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_LEQUAL_97c2ded8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LEQUAL "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_GREATER_97c2dee4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_GREATER "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_NOTEQUAL_97c2def0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_NOTEQUAL "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_GEQUAL_97c2df00[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_GEQUAL "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          iVar21 = 0;
          cVar5 = s_PP_ALWAYS_97c2df0c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_ALWAYS "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
        }
        break;
      case 3:
        iVar21 = 0;
        cVar5 = s_BLENDING_alpha_equ___97c2e028[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "BLENDING \n\talpha equ = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0x13 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_ADD_97c2e040[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_ADD "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_SUBTRACT_97c2e050[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_SUBTRACT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_REVERSE_SUBTRACT_97c2e064[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_REVERSE_SUBTRACT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_MIN_97c2e080[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_MIN "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_MAX_97c2e090[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_MAX "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bef244_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97bef244_default:
        iVar21 = 0;
        cVar5 = s_rgb_equ___97c2e0a0[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "\n\trgb equ = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0x10 & 7) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_ADD_97c2e040[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_ADD "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_SUBTRACT_97c2e050[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_SUBTRACT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_REVERSE_SUBTRACT_97c2e064[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_REVERSE_SUBTRACT "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_MIN_97c2e080[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_MIN "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_FUNC_MAX_97c2e090[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_FUNC_MAX "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bef3e8_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97bef3e8_default:
        iVar21 = 0;
        cVar5 = s_src___97c2e0b0[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "\n\tsrc = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ZERO_97c2e0bc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_97c2e0cc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_COLOR_97c2e0dc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_COLOR_97c2e0f0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_97c2e110[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_ALPHA_97c2e124[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_ALPHA_97c2e144[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_ALPHA_97c2e158[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 8:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_COLOR_97c2e178[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 9:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_COLO_97c2e194[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 10:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_ALPHA_97c2e1b8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xb:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_ALPH_97c2e1d4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xc:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_COLOR_97c2e1f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xd:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_COLOR_97c2e20c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xe:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_SATURATE_97c2e22c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bef58c_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97bef58c_default:
        iVar21 = 0;
        cVar5 = s_srcA___97c2e24c[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "\n\tsrcA = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 4 & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ZERO_97c2e0bc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_97c2e0cc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_COLOR_97c2e0dc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_COLOR_97c2e0f0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_97c2e110[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_ALPHA_97c2e124[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_ALPHA_97c2e144[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_ALPHA_97c2e158[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 8:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_COLOR_97c2e178[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 9:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_COLO_97c2e194[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 10:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_ALPHA_97c2e1b8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xb:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_ALPH_97c2e1d4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xc:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_COLOR_97c2e1f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xd:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_COLOR_97c2e20c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xe:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_SATURATE_97c2e22c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bef988_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97bef988_default:
        iVar21 = 0;
        cVar5 = s_dst___97c2e258[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "\n\tdst = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 8 & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ZERO_97c2e0bc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_97c2e0cc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_COLOR_97c2e0dc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_COLOR_97c2e0f0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_97c2e110[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_ALPHA_97c2e124[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_ALPHA_97c2e144[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_ALPHA_97c2e158[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 8:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_COLOR_97c2e178[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 9:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_COLO_97c2e194[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 10:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_ALPHA_97c2e1b8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xb:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_ALPH_97c2e1d4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xc:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_COLOR_97c2e1f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xd:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_COLOR_97c2e20c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xe:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_SATURATE_97c2e22c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97befd84_default;
        }
        local_a8 = local_a8 + iVar21;
switchD_97befd84_default:
        iVar21 = 0;
        cVar5 = s_dstA___97c2e264[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "\n\tdstA = "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] >> 0xc & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ZERO_97c2e0bc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ZERO "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_97c2e0cc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_COLOR_97c2e0dc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_COLOR_97c2e0f0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_97c2e110[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_SRC_ALPHA_97c2e124[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_SRC_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_ALPHA_97c2e144[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_ALPHA_97c2e158[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 8:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_COLOR_97c2e178[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 9:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_COLO_97c2e194[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 10:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_CONSTANT_ALPHA_97c2e1b8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xb:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_CONSTANT_ALPH_97c2e1d4[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_CONSTANT_ALPHA "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xc:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_DST_COLOR_97c2e1f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xd:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_ONE_MINUS_DST_COLOR_97c2e20c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_ONE_MINUS_DST_COLOR "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xe:
          iVar21 = 0;
          cVar5 = s_PP_BLEND_SRC_ALPHA_SATURATE_97c2e22c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_BLEND_SRC_ALPHA_SATURATE "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bee2f0_default;
        }
        break;
      case 4:
        iVar21 = 0;
        cVar5 = s_DITHERING_ENABLED_97c2e270[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "DITHERING ENABLED"[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        break;
      case 5:
        iVar21 = 0;
        cVar5 = s_LOGIC_OP_97c2e284[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "LOGIC_OP "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        switch(param_1[uVar16 * 2 + iVar20 * 2] & 0xf) {
        case 0:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_CLEAR_97c2e290[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_CLEAR"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 1:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_SET_97c2e2a0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_SET"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 2:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_COPY_97c2e2b0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_COPY"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 3:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_COPY_INVERTED_97c2e2c0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_COPY_INVERTED"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 4:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_NOOP_97c2e2d8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_NOOP"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 5:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_INVERT_97c2e2e8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_INVERT"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 6:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_AND_97c2e2f8[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_AND"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 7:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_NAND_97c2e308[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_NAND"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 8:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_OR_97c2e318[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_OR"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 9:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_NOR_97c2e324[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_NOR"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 10:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_XOR_97c2e334[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_XOR"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xb:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_EQUIV_97c2e344[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_EQUIV"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xc:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_AND_REVERSE_97c2e354[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_AND_REVERSE"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xd:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_AND_INVERTED_97c2e36c[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_AND_INVERTED"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xe:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_OR_REVERSE_97c2e384[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_OR_REVERSE"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        case 0xf:
          iVar21 = 0;
          cVar5 = s_PP_LOGIC_OR_INVERTED_97c2e398[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "PP_LOGIC_OR_INVERTED"[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          break;
        default:
          goto switchD_97bee2f0_default;
        }
        break;
      case 6:
        iVar21 = 0;
        cVar5 = s_BUFFER_MASK_97c2e3b0[0];
        while (cVar5 != '\0') {
          local_a8[iVar21] = cVar5;
          cVar5 = "BUFFER_MASK "[iVar21 + 1];
          iVar21 = iVar21 + 1;
        }
        local_a8 = local_a8 + iVar21;
        if ((param_1[uVar16 * 2 + iVar20 * 2] & 0x20000) == 0) {
          iVar21 = 0;
          cVar5 = s_RED_MASKED_97c2e3c0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "RED MASKED "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
        }
        if ((param_1[uVar16 * 2 + iVar20 * 2] & 0x40000) == 0) {
          iVar21 = 0;
          cVar5 = s_GREEN_MASKED_97c2e3cc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "GREEN MASKED "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
        }
        if ((param_1[uVar16 * 2 + iVar20 * 2] & 0x80000) == 0) {
          iVar21 = 0;
          cVar5 = s_BLUE_MASKED_97c2e3dc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "BLUE MASKED "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
        }
        if ((param_1[uVar16 * 2 + iVar20 * 2] & 0x100000) == 0) {
          iVar21 = 0;
          cVar5 = s_ALPHA_MASKED_97c2e3ec[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "ALPHA MASKED "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
        }
        if ((param_1[uVar16 * 2 + iVar20 * 2] & 0x10000) == 0) {
          iVar21 = 0;
          cVar5 = s_DEPTH_MASKED_97c2e3fc[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            cVar5 = "DEPTH MASKED "[iVar21 + 1];
            iVar21 = iVar21 + 1;
          }
          local_a8 = local_a8 + iVar21;
        }
        if (*(char *)((int)param_1 + iVar20 * 8 + uVar16 * 8 + 2) != -1) {
          _sprintf(local_1b0,"STENCIL MASK = %0x",param_1[uVar16 * 2 + iVar20 * 2] >> 8 & 0xff);
          iVar21 = 0;
          cVar5 = local_1b0[0];
          while (cVar5 != '\0') {
            local_a8[iVar21] = cVar5;
            iVar21 = iVar21 + 1;
            cVar5 = local_1b0[iVar21];
          }
          break;
        }
      default:
        goto switchD_97bee2f0_default;
      }
      local_a8 = local_a8 + iVar21;
switchD_97bee2f0_default:
      iVar21 = 0;
      cVar5 = local_60[0x3bbc];
      while (cVar5 != '\0') {
        local_a8[iVar21] = cVar5;
        iVar21 = iVar21 + 1;
        cVar5 = (local_60 + 0x3bbc)[iVar21];
      }
      local_a8 = local_a8 + iVar21;
      iVar21 = _adjustAllocation(&local_b0,&local_ac,&local_a8);
      if (iVar21 == 0) goto joined_r0x97beb668;
      iVar11 = iVar11 + 1;
      iVar20 = iVar20 + 1;
    } while (iVar11 < (int)uVar9);
  }
  puVar13 = local_a8 + 1;
  *local_a8 = 0;
  local_a8 = puVar13;
  if (!bVar3) {
    _free(local_88);
    _free(local_84);
  }
  if (!(bool)((byte)((uint)local_5c >> 0x1d) & 1)) {
    _free(local_80);
  }
  if (!(bool)((byte)((uint)local_58 >> 0x1d) & 1)) {
    _free(local_7c);
  }
  if (0 < (int)local_a8 - (int)local_ac) {
    pvVar15 = _realloc(local_ac,(int)local_a8 - (int)local_ac);
    return pvVar15;
  }
  _free(local_ac);
  return (void *)0x0;
}

/* _handleDigit @ 0x97bf0d2c (112 bytes) */
int _handleDigit(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 / 10;
  if (iVar1 != 0) {
    ((int (*)())_handleDigit)(param_1,iVar1);
  }
  *(char *)*param_1 = (char)param_2 + (char)iVar1 * -10 + '0';
  *param_1 = *param_1 + 1;
  return;
}

/* _PPStreamChunkCreateWithType @ 0x97bf0d9c (116 bytes) */
int _PPStreamChunkCreateWithType(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = _GetChunkAllocationSize();
  puVar2 = _calloc(iVar1 + 0xcU,1);
  _memset(puVar2,0,iVar1 + 0xcU);
  *puVar2 = (char)param_1;
  if (param_1 == 8) {
    *(undefined4 *)(puVar2 + 0x40) = param_2;
  }
  else if (param_1 == 0xb) {
    *(undefined4 *)(puVar2 + 0x10) = param_2;
  }
  return puVar2;
}

/* _PPStreamChunkCompare @ 0x97bf0e10 (212 bytes) */
int _PPStreamChunkCompare(param_1, param_2)
  char *param_1;
  char *param_2;
{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  
  uVar1 = 1;
  if (*param_2 == *param_1) {
    switch(*param_2) {
    case '\0':
    case '\x03':
    case '\n':
      sVar3 = 0x10;
      break;
    case '\x01':
      sVar3 = 4;
      break;
    case '\x02':
    case '\x04':
    case '\x05':
    case '\x06':
    case '\a':
    case '\t':
      sVar3 = 8;
      break;
    case '\b':
      sVar3 = 0x38;
      uVar1 = *(undefined4 *)(param_1 + 0x40);
      *(undefined4 *)(param_2 + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
      *(undefined4 *)(param_2 + 0x40) = uVar1;
      break;
    default:
      return 1;
    }
    iVar2 = _memcmp(param_1 + 0xc,param_2 + 0xc,sVar3);
    uVar1 = 1;
    if (iVar2 == 0) {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* _PPStreamChunkListInsertChunkBeforeChunk @ 0x97bf0f14 (84 bytes) */
int _PPStreamChunkListInsertChunkBeforeChunk(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    _PPStreamChunkListAddChunk();
    return;
  }
  uVar1 = *(undefined4 *)(param_3 + 4);
  *(int *)(param_2 + 8) = param_3;
  *(undefined4 *)(param_2 + 4) = uVar1;
  if (*(int *)(param_3 + 4) != 0) {
    *(int *)(*(int *)(param_3 + 4) + 8) = param_2;
  }
  *(int *)(param_3 + 4) = param_2;
  if (*param_1 == param_3) {
    *param_1 = param_2;
  }
  param_1[2] = param_1[2] + 1;
  return;
}

/* _PPStreamChunkListInsertChunkAfterChunk @ 0x97bf0f68 (116 bytes) */
int _PPStreamChunkListInsertChunkAfterChunk(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_3 == 0) {
    *(undefined4 *)(param_2 + 4) = 0;
    if (*param_1 == 0) {
      *(undefined4 *)(param_2 + 8) = 0;
    }
    else {
      *(int *)(param_2 + 8) = *param_1;
      *(int *)(*param_1 + 4) = param_2;
    }
    *param_1 = param_2;
  }
  else {
    uVar1 = *(undefined4 *)(param_3 + 8);
    *(int *)(param_2 + 4) = param_3;
    *(undefined4 *)(param_2 + 8) = uVar1;
    if (*(int *)(param_3 + 8) != 0) {
      *(int *)(*(int *)(param_3 + 8) + 4) = param_2;
    }
    *(int *)(param_3 + 8) = param_2;
    if (param_1[1] == param_3) {
      param_1[1] = param_2;
    }
  }
  param_1[2] = param_1[2] + 1;
  return;
}

/* _PPStreamChunkListRemoveChunkNoFree @ 0x97bf0fdc (88 bytes) */
int _PPStreamChunkListRemoveChunkNoFree(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 4);
  if (iVar1 == 0) {
    *param_1 = *(undefined4 *)(param_2 + 8);
    iVar1 = *(int *)(param_2 + 4);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(param_2 + 8);
  }
  if (*(int *)(param_2 + 8) == 0) {
    param_1[1] = iVar1;
  }
  else {
    *(int *)(*(int *)(param_2 + 8) + 4) = iVar1;
  }
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 0;
  param_1[2] = param_1[2] + -1;
  return;
}

/* _PPStreamChunkListCompare @ 0x97bf1034 (132 bytes) */
int _PPStreamChunkListCompare(param_1, param_2)
  int *param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  uVar1 = 1;
  iVar4 = *param_2;
  if (param_1[2] == param_2[2]) {
    for (; (iVar3 != 0 && (iVar4 != 0)); iVar4 = *(int *)(iVar4 + 8)) {
      iVar2 = ((int (*)())_PPStreamChunkCompare)(iVar3,iVar4);
      if (iVar2 != 0) {
        return 1;
      }
      iVar3 = *(int *)(iVar3 + 8);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _PPStreamDuplicate @ 0x97bf10b8 (636 bytes) */
int _PPStreamDuplicate(param_1)
  undefined4 *param_1;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar2 = (undefined4 *)_PPStreamCreate();
  piVar1 = (int *)param_1[1];
  *puVar2 = *param_1;
  for (iVar4 = *piVar1; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[1],uVar3);
  }
  for (iVar4 = *(int *)param_1[2]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[2],uVar3);
  }
  for (iVar4 = *(int *)param_1[3]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[3],uVar3);
  }
  for (iVar4 = *(int *)param_1[4]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[4],uVar3);
  }
  for (iVar4 = *(int *)param_1[5]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[5],uVar3);
  }
  for (iVar4 = *(int *)param_1[6]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[6],uVar3);
  }
  for (iVar4 = *(int *)param_1[7]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[7],uVar3);
  }
  for (iVar4 = *(int *)param_1[8]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[8],uVar3);
  }
  for (iVar4 = *(int *)param_1[9]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[9],uVar3);
  }
  for (iVar4 = *(int *)param_1[0xb]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[0xb],uVar3);
  }
  for (iVar4 = *(int *)param_1[10]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[10],uVar3);
  }
  for (iVar4 = *(int *)param_1[0xc]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar3 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar2[0xc],uVar3);
  }
  return puVar2;
}

/* _PPStreamAddTempUsageArray @ 0x97bf1334 (92 bytes) */
int _PPStreamAddTempUsageArray(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = _calloc(0x14,1);
  uVar4 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 8);
  uVar3 = *param_2;
  *puVar1 = 6;
  *(undefined4 *)(puVar1 + 0xc) = uVar3;
  *(undefined4 *)(puVar1 + 0x10) = uVar4;
  _PPStreamChunkListAddChunk(uVar2,puVar1);
  return;
}

/* _PPStreamAddAddressUsage @ 0x97bf1390 (84 bytes) */
int _PPStreamAddAddressUsage(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  puVar1 = _calloc(0x10,1);
  uVar3 = *param_2;
  uVar2 = *(undefined4 *)(param_1 + 0xc);
  *puVar1 = 1;
  *(undefined4 *)(puVar1 + 0xc) = uVar3;
  _PPStreamChunkListAddChunk(uVar2,puVar1);
  return;
}

/* _PPStreamAddParamBindingArray @ 0x97bf13e4 (92 bytes) */
int _PPStreamAddParamBindingArray(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = _calloc(0x14,1);
  uVar4 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 0x14);
  uVar3 = *param_2;
  *puVar1 = 5;
  *(undefined4 *)(puVar1 + 0xc) = uVar3;
  *(undefined4 *)(puVar1 + 0x10) = uVar4;
  _PPStreamChunkListAddChunk(uVar2,puVar1);
  return;
}

/* _PPStreamInsertOperationBeforeChunk @ 0x97bf1440 (288 bytes) */
int _PPStreamInsertOperationBeforeChunk(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  void *param_2;
  void *param_3;
  int param_4;
  int param_5;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  size_t sVar5;
  
  sVar5 = *(size_t *)((int)param_2 + 0x34);
  iVar3 = 0x38;
  if (sVar5 != 0) {
    iVar3 = sVar5 + 0x39;
  }
  puVar4 = _calloc(iVar3 + 0xc,1);
  *puVar4 = 8;
  _memcpy(puVar4 + 0xc,param_2,0x38);
  if ((sVar5 != 0) && (param_3 != (void *)0x0)) {
    _memmove(puVar4 + 0x44,param_3,sVar5);
    puVar4[sVar5 + 0x44] = 0;
  }
  if (param_4 == 0) {
    iVar3 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(param_1 + 0x20));
    uVar1 = iVar3 + 1U & 0x3ffff | *(uint *)(puVar4 + 0xc) & 0xfffc0000;
  }
  else {
    uVar1 = *(uint *)(puVar4 + 0xc) & 0xfffc0000;
  }
  *(uint *)(puVar4 + 0xc) = uVar1;
  if (param_5 != 0) {
    uVar1 = *(uint *)(param_5 + 0xc);
    uVar2 = *(uint *)(puVar4 + 0xc);
    *(uint *)(param_5 + 0xc) =
         uVar2 & 0x3ffff | (uVar2 & 0xe3ffffff) >> 3 & 0x1c000000 | uVar1 & 0xe3fc0000;
    *(uint *)(puVar4 + 0xc) = uVar1 & 0x3ffff | (uVar1 >> 0x1a & 7) << 0x1a | uVar2 & 0xe3fc0000;
  }
  ((int (*)())_PPStreamChunkListInsertChunkBeforeChunk)(*(undefined4 *)(param_1 + 0x20),puVar4,param_5);
  return puVar4;
}

/* _PPStreamInsertOperationAfterChunk @ 0x97bf1560 (236 bytes) */
int _PPStreamInsertOperationAfterChunk(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  void *param_2;
  void *param_3;
  int param_4;
  undefined4 param_5;
{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  size_t sVar4;
  
  sVar4 = *(size_t *)((int)param_2 + 0x34);
  iVar2 = 0x38;
  if (sVar4 != 0) {
    iVar2 = sVar4 + 0x39;
  }
  puVar3 = _calloc(iVar2 + 0xc,1);
  *puVar3 = 8;
  _memcpy(puVar3 + 0xc,param_2,0x38);
  if ((sVar4 != 0) && (param_3 != (void *)0x0)) {
    _memmove(puVar3 + 0x44,param_3,sVar4);
    puVar3[sVar4 + 0x44] = 0;
  }
  if (param_4 == 0) {
    iVar2 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(param_1 + 0x20));
    uVar1 = iVar2 + 1U & 0x3ffff | *(uint *)(puVar3 + 0xc) & 0xfffc0000;
  }
  else {
    uVar1 = *(uint *)(puVar3 + 0xc) & 0xfffc0000;
  }
  *(uint *)(puVar3 + 0xc) = uVar1;
  ((int (*)())_PPStreamChunkListInsertChunkAfterChunk)(*(undefined4 *)(param_1 + 0x20),puVar3,param_5);
  return puVar3;
}

/* _PPStreamAddLabel @ 0x97bf164c (128 bytes) */
int _PPStreamAddLabel(param_1, param_2, param_3)
  int param_1;
  void *param_2;
  size_t param_3;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  
  puVar1 = _calloc(param_3 + 0x15,1);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  *puVar1 = 0xb;
  *(size_t *)(puVar1 + 0x10) = param_3;
  iVar3 = _PPStreamChunkListGetMaxIndex(uVar2);
  *(int *)(puVar1 + 0xc) = iVar3 + 1;
  _memmove(puVar1 + 0x14,param_2,param_3);
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  puVar1[param_3 + 0x14] = 0;
  _PPStreamChunkListAddChunk(uVar2,puVar1);
  return;
}

/* _PPStreamRemoveLabelsAtOperationIndex @ 0x97bf16cc (96 bytes) */
int _PPStreamRemoveLabelsAtOperationIndex(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  
  iVar2 = **(int **)(param_1 + 0x24);
  while (iVar2 != 0) {
    piVar1 = (int *)(iVar2 + 0xc);
    iVar2 = *(int *)(iVar2 + 8);
    if (*piVar1 == param_2) {
      _PPStreamChunkListRemoveChunk(*(undefined4 *)(param_1 + 0x24));
    }
  }
  return;
}

/* _PPStreamAddRasterOp @ 0x97bf172c (92 bytes) */
int _PPStreamAddRasterOp(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar1 = _calloc(0x14,1);
  uVar4 = param_2[1];
  uVar2 = *(undefined4 *)(param_1 + 0x28);
  uVar3 = *param_2;
  *puVar1 = 9;
  *(undefined4 *)(puVar1 + 0xc) = uVar3;
  *(undefined4 *)(puVar1 + 0x10) = uVar4;
  _PPStreamChunkListAddChunk(uVar2,puVar1);
  return;
}

/* _PPStreamAttachStream @ 0x97bf1788 (1212 bytes) */
int _PPStreamAttachStream(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  
  uVar7 = 0;
  *param_1 = *param_2;
  if (param_2[6] != 0) {
    do {
      puVar5 = _calloc(0x10,1);
      *(uint *)(puVar5 + 0xc) = uVar7;
      *puVar5 = 1;
      uVar7 = uVar7 + 1;
      _PPStreamChunkListAddChunk(param_1[3],puVar5);
    } while (uVar7 < (uint)param_2[6]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[5] * 2;
  if (param_2[4] != 0) {
    do {
      puVar5 = _calloc(0x1c,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 0;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(param_1[1],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[4]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[9] * 2;
  if (param_2[8] != 0) {
    do {
      puVar5 = _calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 2;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(param_1[6],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[8]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0xb] * 2;
  if (param_2[10] != 0) {
    do {
      puVar5 = _calloc(0x1c,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 3;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(param_1[4],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[10]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0xd] * 2;
  if (param_2[0xc] != 0) {
    do {
      puVar5 = _calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 4;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(param_1[7],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[0xc]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0xf] * 2;
  if (param_2[0xe] != 0) {
    do {
      puVar5 = _calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 5;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(param_1[5],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[0xe]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0x11] * 2;
  if (param_2[0x10] != 0) {
    do {
      puVar5 = _calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 6;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(param_1[2],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[0x10]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0x13] * 2;
  if (param_2[0x12] != 0) {
    do {
      puVar5 = _calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 7;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(param_1[0xc],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[0x12]);
  }
  uVar7 = 0;
  puVar8 = param_2 + param_2[0x15] * 2;
  if (param_2[0x14] != 0) {
    do {
      puVar5 = _calloc(0x44,1);
      *puVar5 = 8;
      *(undefined4 *)(puVar5 + 0x40) = 0;
      uVar2 = puVar8[1];
      uVar10 = *puVar8 >> 0x1d;
      *(uint *)(puVar5 + 0xc) = *puVar8;
      *(uint *)(puVar5 + 0x10) = uVar2;
      puVar1 = puVar8 + 2;
      uVar2 = puVar8[3];
      puVar8 = puVar8 + 4;
      *(uint *)(puVar5 + 0x14) = *puVar1;
      *(uint *)(puVar5 + 0x18) = uVar2;
      if (uVar10 != 0) {
        puVar6 = puVar5 + 0x10;
        do {
          uVar2 = *puVar8;
          uVar4 = puVar8[1];
          puVar8 = puVar8 + 2;
          *(uint *)(puVar6 + 0xc) = uVar2;
          *(uint *)(puVar6 + 0x10) = uVar4;
          puVar6 = puVar6 + 8;
          uVar10 = uVar10 - 1;
        } while (uVar10 != 0);
      }
      uVar7 = uVar7 + 1;
      _PPStreamChunkListAddChunk(param_1[8],puVar5);
    } while (uVar7 < (uint)param_2[0x14]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0x19] * 2;
  if (param_2[0x18] != 0) {
    do {
      puVar5 = _calloc(0x14,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 9;
      uVar3 = puVar9[1];
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = uVar3;
      _PPStreamChunkListAddChunk(param_1[10],puVar5);
      puVar9 = puVar9 + 2;
    } while (uVar7 < (uint)param_2[0x18]);
  }
  uVar7 = 0;
  puVar9 = param_2 + param_2[0x1b] * 2;
  if (param_2[0x1a] != 0) {
    do {
      puVar5 = _calloc(0x1c,1);
      uVar7 = uVar7 + 1;
      *puVar5 = 10;
      *(undefined4 *)(puVar5 + 0xc) = *puVar9;
      *(undefined4 *)(puVar5 + 0x10) = puVar9[1];
      *(undefined4 *)(puVar5 + 0x14) = puVar9[2];
      *(undefined4 *)(puVar5 + 0x18) = puVar9[3];
      puVar9 = puVar9 + 4;
      _PPStreamChunkListAddChunk(param_1[0xb],puVar5);
    } while (uVar7 < (uint)param_2[0x1a]);
  }
  return 0;
}

/* _PPStreamCompare @ 0x97bf1c44 (328 bytes) */
int _PPStreamCompare(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  bool bVar2;
  
  bVar2 = true;
  if (*param_1 == *param_2) {
    iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[1],param_2[1]);
    bVar2 = true;
    if (iVar1 == 0) {
      iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[3],param_2[3]);
      bVar2 = true;
      if (iVar1 == 0) {
        iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[4],param_2[4]);
        bVar2 = true;
        if (iVar1 == 0) {
          iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[5],param_2[5]);
          bVar2 = true;
          if (iVar1 == 0) {
            iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[2],param_2[2]);
            bVar2 = true;
            if (iVar1 == 0) {
              iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[6],param_2[6]);
              bVar2 = true;
              if (iVar1 == 0) {
                iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[7],param_2[7]);
                bVar2 = true;
                if (iVar1 == 0) {
                  iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[8],param_2[8]);
                  bVar2 = true;
                  if (iVar1 == 0) {
                    iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[0xb],param_2[0xb]);
                    bVar2 = true;
                    if (iVar1 == 0) {
                      iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[10],param_2[10]);
                      bVar2 = true;
                      if (iVar1 == 0) {
                        iVar1 = ((int (*)())_PPStreamChunkListCompare)(param_1[0xc],param_2[0xc]);
                        bVar2 = iVar1 != 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return bVar2;
}

/* _PPStreamRenumberOperandIndices @ 0x97bf1d8c (332 bytes) */
int _PPStreamRenumberOperandIndices(param_1, param_2, param_3)
  int param_1;
  byte *param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  
  iVar6 = **(int **)(param_1 + 0x20);
  if (iVar6 == 0) {
    return;
  }
  do {
    uVar2 = *(uint *)(iVar6 + 0xc);
    iVar3 = 0;
    if (uVar2 >> 0x1d != 0) {
      bVar5 = *param_2;
      iVar4 = iVar6 + 0x10;
      do {
        if (bVar5 == 2) {
          if ((*(uint *)(iVar4 + 0xc) & 0x3800000) == 0) goto LAB_97bf1e1c;
        }
        else {
          if (bVar5 < 3) {
            if (bVar5 != 0) goto LAB_97bf1e38;
            bVar1 = (*(uint *)(iVar4 + 0xc) >> 0x17 & 7) == 1;
          }
          else if (bVar5 == 3) {
            bVar1 = (*(uint *)(iVar4 + 0xc) >> 0x17 & 7) == 2;
          }
          else {
            if (bVar5 != 4) goto LAB_97bf1e38;
            bVar1 = (*(uint *)(iVar4 + 0xc) >> 0x17 & 7) == 3;
          }
          if (bVar1) {
LAB_97bf1e1c:
            if (*(short *)(iVar4 + 0x12) == *(short *)(param_2 + 0x12)) {
              *(undefined2 *)(iVar4 + 0x12) = param_3;
              uVar2 = *(uint *)(iVar6 + 0xc);
              bVar5 = *param_2;
            }
          }
        }
LAB_97bf1e38:
        if (bVar5 == 2) {
          if ((*(uint *)(iVar6 + 0x14) & 0xe0000) == 0) goto LAB_97bf1ea0;
        }
        else {
          if (bVar5 < 3) {
            if (bVar5 != 0) goto LAB_97bf1eb4;
            bVar1 = (*(uint *)(iVar6 + 0x14) >> 0x11 & 7) == 1;
          }
          else if (bVar5 == 3) {
            bVar1 = (*(uint *)(iVar6 + 0x14) >> 0x11 & 7) == 2;
          }
          else {
            if (bVar5 != 4) goto LAB_97bf1eb4;
            bVar1 = (*(uint *)(iVar6 + 0x14) >> 0x11 & 7) == 3;
          }
          if (bVar1) {
LAB_97bf1ea0:
            if (*(short *)(iVar6 + 0x1a) == *(short *)(param_2 + 0x12)) {
              *(undefined2 *)(iVar6 + 0x1a) = param_3;
            }
          }
        }
LAB_97bf1eb4:
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 8;
      } while (iVar3 < (int)(uVar2 >> 0x1d));
    }
    iVar6 = *(int *)(iVar6 + 8);
    if (iVar6 == 0) {
      return;
    }
  } while( true );
}

/* _renumberTempArrayIndices @ 0x97bf1ed8 (56 bytes) */
int _renumberTempArrayIndices(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  if (param_1 != 0) {
    do {
      if (param_2 == *(ushort *)(param_1 + 0xe)) {
        *(undefined2 *)(param_1 + 0xe) = param_3;
      }
      if (param_2 == *(ushort *)(param_1 + 0x12)) {
        *(undefined2 *)(param_1 + 0x12) = param_3;
      }
      param_1 = *(int *)(param_1 + 8);
    } while (param_1 != 0);
    return;
  }
  return;
}

/* _renumberParamArrayIndices @ 0x97bf1f10 (56 bytes) */
int _renumberParamArrayIndices(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  if (param_1 != 0) {
    do {
      if (param_2 == *(ushort *)(param_1 + 0xe)) {
        *(undefined2 *)(param_1 + 0xe) = param_3;
      }
      if (param_2 == *(ushort *)(param_1 + 0x12)) {
        *(undefined2 *)(param_1 + 0x12) = param_3;
      }
      param_1 = *(int *)(param_1 + 8);
    } while (param_1 != 0);
    return;
  }
  return;
}

/* _renumberLabels @ 0x97bf1f48 (72 bytes) */
int _renumberLabels(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  if (param_1 != 0) {
    do {
      if (((param_4 == 0) || (*(char *)(param_1 + 1) == '\0')) &&
         (param_2 == *(int *)(param_1 + 0xc))) {
        if (param_4 != 0) {
          *(undefined1 *)(param_1 + 1) = 1;
        }
        *(undefined4 *)(param_1 + 0xc) = param_3;
      }
      param_1 = *(int *)(param_1 + 8);
    } while (param_1 != 0);
    return;
  }
  return;
}

/* _renumberTargets @ 0x97bf1f90 (148 bytes) */
int _renumberTargets(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
{
  if (param_1 == 0) {
    return;
  }
  do {
    switch(*(uint *)(param_1 + 0xc) >> 0x12 & 0xff) {
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
      if (((param_4 == 0) || (*(char *)(param_1 + 1) == '\0')) &&
         (param_2 == (*(uint *)(param_1 + 0x10) & 0x3ffff))) {
        if (param_4 != 0) {
          *(undefined1 *)(param_1 + 1) = 1;
        }
        *(uint *)(param_1 + 0x10) = param_3 & 0x3ffff | *(uint *)(param_1 + 0x10) & 0xfffc0000;
      }
    }
    param_1 = *(int *)(param_1 + 8);
  } while (param_1 != 0);
  return;
}

/* _PPStreamChangeBranchTargets @ 0x97bf20a8 (84 bytes) */
int _PPStreamChangeBranchTargets(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_renumberLabels)(**(undefined4 **)(param_1 + 0x24),param_2,param_3,0);
  ((int (*)())_renumberTargets)(**(undefined4 **)(param_1 + 0x20),param_2,param_3,0);
  return;
}

/* _PPStreamPackIndices @ 0x97bf20fc (612 bytes) */
int _PPStreamPackIndices(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = 0;
  for (iVar3 = **(int **)(param_1 + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar3,uVar2);
      ((int (*)())_renumberTempArrayIndices)(**(undefined4 **)(param_1 + 8),*(undefined2 *)(iVar3 + 0x12),uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  iVar3 = 0;
  for (iVar4 = **(int **)(param_1 + 0xc); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    if (*(int *)(iVar4 + 0xc) != iVar3) {
      ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar4,iVar3);
      *(int *)(iVar4 + 0xc) = iVar3;
    }
    iVar3 = iVar3 + 1;
  }
  uVar2 = 0;
  for (iVar3 = **(int **)(param_1 + 0x10); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar3,uVar2);
      ((int (*)())_renumberParamArrayIndices)(**(undefined4 **)(param_1 + 0x14),*(undefined2 *)(iVar3 + 0x12),uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  for (iVar3 = **(int **)(param_1 + 0x18); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar3,uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  uVar2 = 0;
  for (iVar3 = **(int **)(param_1 + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    if (*(ushort *)(iVar3 + 0x12) != uVar2) {
      ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar3,uVar2);
      *(short *)(iVar3 + 0x12) = (short)uVar2;
    }
    uVar2 = uVar2 + 1;
  }
  for (iVar3 = **(int **)(param_1 + 0x20); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    *(undefined1 *)(iVar3 + 1) = 0;
  }
  for (iVar3 = **(int **)(param_1 + 0x24); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    *(undefined1 *)(iVar3 + 1) = 0;
  }
  uVar2 = 1;
  for (iVar3 = **(int **)(param_1 + 0x20); iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
    uVar1 = *(uint *)(iVar3 + 0xc) & 0x3ffff;
    if ((uVar1 != 0) && (uVar1 != uVar2)) {
      ((int (*)())_renumberLabels)(**(undefined4 **)(param_1 + 0x24),uVar1,uVar2,1);
      ((int (*)())_renumberTargets)(**(undefined4 **)(param_1 + 0x20),*(uint *)(iVar3 + 0xc) & 0x3ffff,uVar2,1);
      *(uint *)(iVar3 + 0xc) = uVar2 & 0x3ffff | *(uint *)(iVar3 + 0xc) & 0xfffc0000;
    }
    uVar2 = uVar2 + 1;
  }
  return;
}

/* _PPStreamSortParamConstants @ 0x97bf2360 (168 bytes) */
int _PPStreamSortParamConstants(param_1)
  int param_1;
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = **(int **)(param_1 + 0x10);
  iVar2 = _PPStreamChunkListGetMaxIndex();
  if (iVar4 != 0) {
    uVar1 = *(ushort *)(iVar4 + 0x12);
    uVar3 = iVar2 + 1U;
    while ((uint)uVar1 < iVar2 + 1U) {
      if ((*(uint *)(iVar4 + 0xc) >> 0x10 & 0x1f) == 0x11) {
        ((int (*)())_PPStreamRenumberOperandIndices)(param_1,iVar4,uVar3);
        ((int (*)())_renumberParamArrayIndices)(**(undefined4 **)(param_1 + 0x14),*(undefined2 *)(iVar4 + 0x12),uVar3);
        *(short *)(iVar4 + 0x12) = (short)uVar3;
        uVar3 = uVar3 + 1;
      }
      iVar4 = *(int *)(iVar4 + 8);
      if (iVar4 == 0) break;
      uVar1 = *(ushort *)(iVar4 + 0x12);
    }
  }
  _PPStreamChunkListSort(*(undefined4 *)(param_1 + 0x10));
  return;
}

/* _PPStreamResolveBranches @ 0x97bf2408 (340 bytes) */
int _PPStreamResolveBranches(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  size_t sVar6;
  int iVar7;
  
  piVar4 = *(int **)(param_1 + 0x20);
  uVar2 = 0;
  piVar3 = *(int **)(param_1 + 0x24);
  iVar5 = *piVar4;
  do {
    if (iVar5 == 0) {
      iVar5 = *piVar3;
      while( true ) {
        if (iVar5 == 0) {
          return uVar2;
        }
        iVar7 = _memcmp("main(",(void *)(iVar5 + 0x14),6);
        if (iVar7 == 0) break;
        iVar5 = *(int *)(iVar5 + 8);
      }
      iVar7 = *piVar4;
      if (iVar7 == 0) {
        return uVar2;
      }
      do {
        if (*(uint *)(iVar5 + 0xc) == (*(uint *)(iVar7 + 0xc) & 0x3ffff)) {
          *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfffc0000;
          *(undefined4 *)(iVar5 + 0xc) = 0;
          return uVar2;
        }
        iVar7 = *(int *)(iVar7 + 8);
      } while (iVar7 != 0);
      return uVar2;
    }
    sVar6 = *(size_t *)(iVar5 + 0x40);
    if (sVar6 != 0) {
      *(uint *)(iVar5 + 0x10) = piVar4[2] + 1U & 0x3ffff | *(uint *)(iVar5 + 0x10) & 0xfffc0000;
      for (iVar7 = *piVar3; iVar7 != 0; iVar7 = *(int *)(iVar7 + 8)) {
        if ((sVar6 == *(size_t *)(iVar7 + 0x10)) &&
           (iVar1 = _strncmp((char *)(iVar5 + 0x44),(char *)(iVar7 + 0x14),sVar6), iVar1 == 0)) {
          *(uint *)(iVar5 + 0x10) =
               *(uint *)(iVar7 + 0xc) & 0x3ffff | *(uint *)(iVar5 + 0x10) & 0xfffc0000;
          goto LAB_97bf24b8;
        }
      }
      uVar2 = 1;
    }
LAB_97bf24b8:
    iVar5 = *(int *)(iVar5 + 8);
  } while( true );
}

/* _PPStreamGetArray @ 0x97bf255c (152 bytes) */
int _PPStreamGetArray(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_2 == 1) {
    for (iVar1 = **(int **)(param_1 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((*(ushort *)(iVar1 + 0xe) <= param_3) && (param_3 <= *(ushort *)(iVar1 + 0x12))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  else if (param_2 == 2) {
    for (iVar1 = **(int **)(param_1 + 0x14); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((*(ushort *)(iVar1 + 0xe) <= param_3) && (param_3 <= *(ushort *)(iVar1 + 0x12))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  return -1;
}

/* _PPStreamFindDuplicateChunk @ 0x97bf25f4 (240 bytes) */
int _PPStreamFindDuplicateChunk(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)0x0;
  switch(*param_2) {
  case 0:
    piVar1 = *(int **)(param_1 + 4);
    break;
  case 1:
    piVar1 = *(int **)(param_1 + 0xc);
    break;
  case 2:
    piVar1 = *(int **)(param_1 + 0x18);
    break;
  case 3:
    piVar1 = *(int **)(param_1 + 0x10);
    break;
  case 4:
    piVar1 = *(int **)(param_1 + 0x1c);
    break;
  case 5:
    piVar1 = *(int **)(param_1 + 0x14);
    break;
  case 6:
    piVar1 = *(int **)(param_1 + 8);
    break;
  case 7:
    piVar1 = *(int **)(param_1 + 0x30);
    break;
  case 8:
    piVar1 = *(int **)(param_1 + 0x20);
    break;
  case 9:
    piVar1 = *(int **)(param_1 + 0x28);
    break;
  case 10:
    piVar1 = *(int **)(param_1 + 0x2c);
    break;
  case 0xb:
    piVar1 = *(int **)(param_1 + 0x24);
  }
  iVar3 = *piVar1;
  while( true ) {
    if (iVar3 == 0) {
      return 0;
    }
    iVar2 = ((int (*)())_PPStreamChunkCompare)(iVar3,param_2);
    if (iVar2 == 0) break;
    iVar3 = *(int *)(iVar3 + 8);
  }
  return iVar3;
}

/* _PPStreamRemoveOperation @ 0x97bf2714 (192 bytes) */
int _PPStreamRemoveOperation(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_2 + 8);
  if (iVar5 != 0) {
    uVar2 = *(uint *)(iVar5 + 0xc);
    uVar1 = (*(uint *)(param_2 + 0xc) >> 0x1a & 7) << 0x1a;
    *(uint *)(iVar5 + 0xc) = uVar1 | uVar2 & 0xe3ffffff;
    uVar3 = *(uint *)(param_2 + 0xc) & 0x3ffff;
    if (uVar3 == 0) {
      uVar4 = 0;
      uVar3 = *(uint *)(*(int *)(param_2 + 8) + 0xc);
      *(uint *)(iVar5 + 0xc) = uVar1 | uVar2 & 0xe3fc0000;
      uVar3 = uVar3 & 0x3ffff;
    }
    else {
      uVar4 = uVar2 & 0x3ffff;
    }
    ((int (*)())_renumberLabels)(**(undefined4 **)(param_1 + 0x24),uVar3,uVar4,0);
    ((int (*)())_renumberTargets)(**(undefined4 **)(param_1 + 0x20),uVar3,uVar4,0);
  }
  _PPStreamChunkListRemoveChunk(*(undefined4 *)(param_1 + 0x20),param_2);
  return iVar5;
}

/* _adjustAllocation_97bf27d4 @ 0x97bf27d4 (124 bytes) */
int _adjustAllocation_97bf27d4(param_1, param_2, param_3)
  size_t *param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  int iVar4;
  
  iVar1 = *param_2;
  iVar4 = *param_3;
  if ((int)(*param_1 - (iVar4 - iVar1)) < 0x800) {
    sVar3 = *param_1 + 0x1000;
    *param_1 = sVar3;
    pvVar2 = _realloc((void *)*param_2,sVar3);
    *param_3 = (int)pvVar2;
    if (pvVar2 == (void *)0x0) {
      return 0;
    }
    *param_2 = (int)pvVar2;
    *param_3 = (int)pvVar2 + (iVar4 - iVar1);
  }
  return 1;
}

/* _ncpy_97bf2850 @ 0x97bf2850 (144 bytes) */
int _ncpy_97bf2850(param_1, param_2)
  char *param_1;
  int param_2;
{
  int iVar1;
  char *local_20 [4];
  
  local_20[0] = param_1;
  if (param_2 < 0) {
    local_20[0] = param_1 + 1;
    *param_1 = '-';
    param_2 = -param_2;
  }
  iVar1 = param_2 / 10;
  if (iVar1 != 0) {
    ((int (*)())_handleDigit)(local_20,iVar1);
  }
  *local_20[0] = (char)param_2 + (char)iVar1 * -10 + '0';
  return local_20[0] + (1 - (int)param_1);
}

/* _glpSourceSign @ 0x97bf28e0 (180 bytes) */
int _glpSourceSign(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  char cVar1;
  int iVar2;
  
  if ((param_4 & 1) == 0) {
    if ((*(uint *)(param_1 + param_3 * 8) & 0x8000000) == 0) {
      return param_2;
    }
    iVar2 = 0;
    cVar1 = s___97c2a2d4[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "-"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
  }
  else {
    if ((*(uint *)(param_1 + param_3 * 8) & 0x8000000) != 0) {
      return param_2;
    }
    iVar2 = 0;
    cVar1 = s___97c2a2d4[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "-"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
  }
  return param_2 + iVar2;
}

/* _glpSourceType @ 0x97bf2994 (1080 bytes) */
int _glpSourceType(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  uint param_6;
  uint param_7;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((param_7 & 0x10) != 0) {
    if (param_6 == 1) {
      param_6 = *(uint *)(param_1 + 8) >> 6 & 3;
    }
    else if ((int)param_6 < 2) {
      if (param_6 == 0) {
        param_6 = *(uint *)(param_1 + 8) >> 8 & 3;
      }
    }
    else if (param_6 == 2) {
      param_6 = *(uint *)(param_1 + 8) >> 4 & 3;
    }
    else if (param_6 == 3) {
      param_6 = *(uint *)(param_1 + 8) >> 2 & 3;
    }
  }
  param_5 = param_5 * 8;
  uVar2 = *(uint *)(param_5 + param_1) >> 0x17 & 7;
  if (uVar2 == 1) {
    iVar3 = 0;
    cVar1 = s_tmp_97c2d76c[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar3) = cVar1;
      cVar1 = "tmp"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
LAB_97bf2d98:
    iVar5 = _ncpy(param_2 + iVar3,*(ushort *)(param_5 + param_1 + 6) + param_6);
    return param_2 + iVar3 + iVar5;
  }
  if (uVar2 < 2) {
    if (uVar2 != 0) {
      return param_2;
    }
    iVar3 = 0;
    cVar1 = s_att_97c2d7e4[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar3) = cVar1;
      cVar1 = "att"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    goto LAB_97bf2d98;
  }
  if (uVar2 != 2) {
    if (uVar2 != 3) {
      return param_2;
    }
    iVar3 = 0;
    cVar1 = s_res_97c2d774[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar3) = cVar1;
      cVar1 = "res"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    goto LAB_97bf2d98;
  }
  iVar3 = 0;
  cVar1 = s_prm_97c2d7e8[0];
  while (cVar1 != '\0') {
    *(char *)(param_2 + iVar3) = cVar1;
    cVar1 = "prm"[iVar3 + 1];
    iVar3 = iVar3 + 1;
  }
  iVar5 = _ncpy(param_2 + iVar3,
                *(int *)(param_3 + (uint)*(ushort *)(param_5 + param_1 + 6) * 4) + param_6);
  iVar5 = param_2 + iVar3 + iVar5;
  if (-1 < *(int *)(param_5 + param_1)) {
    if (*(int *)(param_4 + (uint)*(ushort *)(param_5 + param_1 + 6) * 4) == -1) {
      return iVar5;
    }
    iVar3 = 0;
    cVar1 = s___97c29860[0];
    while (cVar1 != '\0') {
      *(char *)(iVar5 + iVar3) = cVar1;
      cVar1 = "["[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    iVar4 = _ncpy(iVar5 + iVar3,
                  *(undefined4 *)(param_4 + (uint)*(ushort *)(param_5 + param_1 + 6) * 4));
    iVar4 = iVar5 + iVar3 + iVar4;
    iVar3 = 0;
    cVar1 = s___97c2d770[0];
    while (cVar1 != '\0') {
      *(char *)(iVar4 + iVar3) = cVar1;
      cVar1 = "]"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    goto LAB_97bf2d5c;
  }
  iVar3 = 0;
  cVar1 = s__adr_97c2d778[0];
  while (cVar1 != '\0') {
    *(char *)(iVar5 + iVar3) = cVar1;
    cVar1 = "[adr"[iVar3 + 1];
    iVar3 = iVar3 + 1;
  }
  iVar4 = _ncpy(iVar5 + iVar3,*(uint *)(param_5 + param_1) >> 0x1e & 1);
  iVar4 = iVar5 + iVar3 + iVar4;
  uVar2 = *(uint *)(param_5 + param_1) >> 0x1c & 3;
  if (uVar2 == 1) {
    iVar3 = 0;
    cVar1 = s__y_97c2d784[0];
    while (cVar1 != '\0') {
      *(char *)(iVar4 + iVar3) = cVar1;
      cVar1 = ".y"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
LAB_97bf2c84:
    iVar4 = iVar4 + iVar3;
  }
  else {
    if (1 < uVar2) {
      if (uVar2 == 2) {
        iVar3 = 0;
        cVar1 = s__z_97c2d788[0];
        while (cVar1 != '\0') {
          *(char *)(iVar4 + iVar3) = cVar1;
          cVar1 = ".z"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
      }
      else {
        if (uVar2 != 3) goto LAB_97bf2c88;
        iVar3 = 0;
        cVar1 = s__w_97c2d78c[0];
        while (cVar1 != '\0') {
          *(char *)(iVar4 + iVar3) = cVar1;
          cVar1 = ".w"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
      }
      goto LAB_97bf2c84;
    }
    if (uVar2 == 0) {
      iVar3 = 0;
      cVar1 = s__x_97c2d780[0];
      while (cVar1 != '\0') {
        *(char *)(iVar4 + iVar3) = cVar1;
        cVar1 = ".x"[iVar3 + 1];
        iVar3 = iVar3 + 1;
      }
      goto LAB_97bf2c84;
    }
  }
LAB_97bf2c88:
  iVar3 = 0;
  cVar1 = s___97c2d770[0];
  while (cVar1 != '\0') {
    *(char *)(iVar4 + iVar3) = cVar1;
    cVar1 = "]"[iVar3 + 1];
    iVar3 = iVar3 + 1;
  }
LAB_97bf2d5c:
  return iVar4 + iVar3;
}

/* _glpSourceComponents @ 0x97bf2dcc (504 bytes) */
int _glpSourceComponents(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  char *param_2;
  int param_3;
  uint param_4;
  uint param_5;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  uVar7 = 0x3210;
  if ((param_5 & 0x40) == 0) {
    uVar7 = *(uint *)(param_1 + param_3 * 8);
    uVar7 = uVar7 >> 3 & 0x3000 | uVar7 >> 9 & 0x300 | uVar7 >> 0xf & 0x30 | uVar7 >> 0x15 & 3;
  }
  uVar8 = uVar7;
  if ((param_5 & 0xc) != 0) {
    uVar4 = param_4;
    if ((param_5 & 4) == 0) {
      uVar4 = *(uint *)(param_1 + 8);
      uVar4 = (uVar4 & 0xc) << 10 | (uVar4 & 0x30) << 4 | uVar4 >> 2 & 0x30 | uVar4 >> 8 & 3;
    }
    if (uVar4 != 0x3210) {
      iVar10 = 4;
      uVar9 = 0;
      uVar8 = 0;
      do {
        uVar2 = uVar9 & 0x3f;
        uVar5 = (uVar4 & 3) * 4 - uVar9;
        if ((int)uVar5 < 1) {
          uVar5 = uVar7 << (-uVar5 & 0x3f);
        }
        else {
          uVar5 = (int)uVar7 >> (uVar5 & 0x3f);
        }
        uVar9 = uVar9 + 4;
        uVar8 = uVar8 | uVar5 & 3 << uVar2;
        uVar4 = (int)uVar4 >> 4;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
  }
  if ((param_5 & 2) == 0) {
    iVar10 = 4;
    if ((*(uint *)(param_1 + param_3 * 8) & 0x3000) == 0) {
      iVar10 = 1;
    }
    if (uVar8 != 0x3210) {
      iVar3 = 0;
      cVar1 = s___97c2a130[0];
      while (cVar1 != '\0') {
        param_2[iVar3] = cVar1;
        cVar1 = "."[iVar3 + 1];
        iVar3 = iVar3 + 1;
      }
      param_2 = param_2 + iVar3;
      for (; iVar10 != 0; iVar10 = iVar10 + -1) {
        cVar1 = (char)uVar8;
        uVar8 = (int)uVar8 >> 4;
        *param_2 = (cVar1 + 1U & 3) + 0x77;
        param_2 = param_2 + 1;
      }
    }
  }
  else {
    iVar10 = 0;
    cVar1 = s___97c2a130[0];
    while (cVar1 != '\0') {
      param_2[iVar10] = cVar1;
      cVar1 = "."[iVar10 + 1];
      iVar10 = iVar10 + 1;
    }
    pcVar6 = param_2 + iVar10;
    if (param_4 == 1) {
      uVar8 = (int)uVar8 >> 4;
    }
    else if ((int)param_4 < 2) {
      if (param_4 != 0) {
        return pcVar6;
      }
    }
    else if (param_4 == 2) {
      uVar8 = (int)uVar8 >> 8;
    }
    else {
      if (param_4 != 3) {
        return pcVar6;
      }
      uVar8 = (int)uVar8 >> 0xc;
    }
    param_2[iVar10] = ((char)uVar8 + 1U & 3) + 0x77;
    param_2 = pcVar6 + 1;
  }
  return param_2;
}

/* _glpWriteComponentsWithDestinationSwizzle @ 0x97bf2fc4 (244 bytes) */
int _glpWriteComponentsWithDestinationSwizzle(param_1, param_2)
  int param_1;
  char *param_2;
{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = *(uint *)(param_1 + 8);
  uVar6 = (uVar6 & 0xc) << 10 | (uVar6 & 0x30) << 4 | uVar6 >> 2 & 0x30 | uVar6 >> 8 & 3;
  if (uVar6 == 0x3210) {
    return param_2;
  }
  iVar7 = 4;
  uVar5 = 0;
  uVar4 = 0;
  do {
    uVar2 = uVar4 & 0x3f;
    uVar3 = (uVar6 & 3) * 4 - uVar4;
    if ((int)uVar3 < 1) {
      uVar3 = 0x3210 << (-uVar3 & 0x3f);
    }
    else {
      uVar3 = 0x3210 >> (uVar3 & 0x3f);
    }
    uVar4 = uVar4 + 4;
    uVar5 = uVar5 | uVar3 & 3 << uVar2;
    uVar6 = (int)uVar6 >> 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  if (uVar5 != 0x3210) {
    iVar7 = 0;
    cVar1 = s___97c2a130[0];
    while (cVar1 != '\0') {
      param_2[iVar7] = cVar1;
      cVar1 = "."[iVar7 + 1];
      iVar7 = iVar7 + 1;
    }
    param_2 = param_2 + iVar7;
    iVar7 = 0;
    do {
      iVar7 = iVar7 + 1;
      cVar1 = (char)uVar5;
      uVar5 = (int)uVar5 >> 4;
      *param_2 = (cVar1 + 1U & 3) + 0x77;
      param_2 = param_2 + 1;
    } while (iVar7 < 4);
    return param_2;
  }
  return param_2;
}

/* _glpWriteSourceOperand_97bf30b8 @ 0x97bf30b8 (128 bytes) */
int _glpWriteSourceOperand_97bf30b8(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())_glpSourceSign)(param_1,param_2,param_5,param_8);
  uVar1 = ((int (*)())_glpSourceType)(param_1,uVar1,param_3,param_4,param_5,param_6,param_8);
  ((int (*)())_glpSourceComponents)(param_1,uVar1,param_5,param_7,param_8);
  return;
}

/* _glpWriteDestinationMask @ 0x97bf3138 (1312 bytes) */
int _glpWriteDestinationMask(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  uint uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if ((param_4 & 2) == 0) {
    uVar1 = *(uint *)(param_1 + 8);
    if ((uVar1 & 0x1e000) == 0x1e000) {
      return param_2;
    }
    iVar4 = 0;
    iVar3 = iVar4;
    cVar2 = s___97c2a130[0];
    if (s___97c2a130[0] != '\0') {
      do {
        *(char *)(param_2 + iVar3) = cVar2;
        iVar4 = iVar3 + 1;
        cVar2 = "."[iVar3 + 1];
        iVar3 = iVar4;
      } while (cVar2 != '\0');
      uVar1 = *(uint *)(param_1 + 8);
    }
    param_2 = param_2 + iVar4;
    if ((uVar1 & 0x2000) != 0) {
      iVar4 = 0;
      iVar3 = iVar4;
      cVar2 = s_x_97c2d790[0];
      if (s_x_97c2d790[0] != '\0') {
        do {
          *(char *)(param_2 + iVar3) = cVar2;
          iVar4 = iVar3 + 1;
          cVar2 = "x"[iVar3 + 1];
          iVar3 = iVar4;
        } while (cVar2 != '\0');
        uVar1 = *(uint *)(param_1 + 8);
      }
      param_2 = param_2 + iVar4;
    }
    if ((uVar1 & 0x4000) != 0) {
      iVar4 = 0;
      iVar3 = iVar4;
      cVar2 = s_y_97c2d794[0];
      if (s_y_97c2d794[0] != '\0') {
        do {
          *(char *)(param_2 + iVar3) = cVar2;
          iVar4 = iVar3 + 1;
          cVar2 = "y"[iVar3 + 1];
          iVar3 = iVar4;
        } while (cVar2 != '\0');
        uVar1 = *(uint *)(param_1 + 8);
      }
      param_2 = param_2 + iVar4;
    }
    if ((uVar1 & 0x8000) != 0) {
      iVar4 = 0;
      iVar3 = iVar4;
      cVar2 = s_z_97c2d798[0];
      if (s_z_97c2d798[0] != '\0') {
        do {
          *(char *)(param_2 + iVar3) = cVar2;
          iVar4 = iVar3 + 1;
          cVar2 = "z"[iVar3 + 1];
          iVar3 = iVar4;
        } while (cVar2 != '\0');
        uVar1 = *(uint *)(param_1 + 8);
      }
      param_2 = param_2 + iVar4;
    }
    if ((uVar1 & 0x10000) == 0) {
      return param_2;
    }
    iVar3 = 0;
    cVar2 = s_w_97c2d79c[0];
    while (cVar2 != '\0') {
      *(char *)(param_2 + iVar3) = cVar2;
      cVar2 = "w"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
  }
  else if (param_3 == 1) {
    iVar3 = 0;
    cVar2 = s___97c2a130[0];
    while (cVar2 != '\0') {
      *(char *)(param_2 + iVar3) = cVar2;
      cVar2 = "."[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    uVar1 = *(uint *)(param_1 + 8);
    param_2 = param_2 + iVar3;
    if ((uVar1 & 0x4000) == 0) {
      if ((uVar1 & 0x8000) == 0) {
        if ((uVar1 & 0x10000) == 0) {
          return param_2;
        }
        iVar3 = 0;
        cVar2 = s_w_97c2d79c[0];
        while (cVar2 != '\0') {
          *(char *)(param_2 + iVar3) = cVar2;
          cVar2 = "w"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
      }
      else {
        iVar3 = 0;
        cVar2 = s_z_97c2d798[0];
        while (cVar2 != '\0') {
          *(char *)(param_2 + iVar3) = cVar2;
          cVar2 = "z"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
      }
    }
    else {
      iVar3 = 0;
      cVar2 = s_y_97c2d794[0];
      while (cVar2 != '\0') {
        *(char *)(param_2 + iVar3) = cVar2;
        cVar2 = "y"[iVar3 + 1];
        iVar3 = iVar3 + 1;
      }
    }
  }
  else if (param_3 < 2) {
    if (param_3 != 0) {
      return param_2;
    }
    iVar3 = 0;
    cVar2 = s___97c2a130[0];
    while (cVar2 != '\0') {
      *(char *)(param_2 + iVar3) = cVar2;
      cVar2 = "."[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    uVar1 = *(uint *)(param_1 + 8);
    param_2 = param_2 + iVar3;
    if ((uVar1 & 0x2000) == 0) {
      if ((uVar1 & 0x4000) == 0) {
        if ((uVar1 & 0x8000) == 0) {
          if ((uVar1 & 0x10000) == 0) {
            return param_2;
          }
          iVar3 = 0;
          cVar2 = s_w_97c2d79c[0];
          while (cVar2 != '\0') {
            *(char *)(param_2 + iVar3) = cVar2;
            cVar2 = "w"[iVar3 + 1];
            iVar3 = iVar3 + 1;
          }
        }
        else {
          iVar3 = 0;
          cVar2 = s_z_97c2d798[0];
          while (cVar2 != '\0') {
            *(char *)(param_2 + iVar3) = cVar2;
            cVar2 = "z"[iVar3 + 1];
            iVar3 = iVar3 + 1;
          }
        }
      }
      else {
        iVar3 = 0;
        cVar2 = s_y_97c2d794[0];
        while (cVar2 != '\0') {
          *(char *)(param_2 + iVar3) = cVar2;
          cVar2 = "y"[iVar3 + 1];
          iVar3 = iVar3 + 1;
        }
      }
    }
    else {
      iVar3 = 0;
      cVar2 = s_x_97c2d790[0];
      while (cVar2 != '\0') {
        *(char *)(param_2 + iVar3) = cVar2;
        cVar2 = "x"[iVar3 + 1];
        iVar3 = iVar3 + 1;
      }
    }
  }
  else if (param_3 == 2) {
    iVar3 = 0;
    cVar2 = s___97c2a130[0];
    while (cVar2 != '\0') {
      *(char *)(param_2 + iVar3) = cVar2;
      cVar2 = "."[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    param_2 = param_2 + iVar3;
    if ((*(uint *)(param_1 + 8) & 0x8000) == 0) {
      if ((*(uint *)(param_1 + 8) & 0x10000) == 0) {
        return param_2;
      }
      iVar3 = 0;
      cVar2 = s_w_97c2d79c[0];
      while (cVar2 != '\0') {
        *(char *)(param_2 + iVar3) = cVar2;
        cVar2 = "w"[iVar3 + 1];
        iVar3 = iVar3 + 1;
      }
    }
    else {
      iVar3 = 0;
      cVar2 = s_z_97c2d798[0];
      while (cVar2 != '\0') {
        *(char *)(param_2 + iVar3) = cVar2;
        cVar2 = "z"[iVar3 + 1];
        iVar3 = iVar3 + 1;
      }
    }
  }
  else {
    if (param_3 != 3) {
      return param_2;
    }
    iVar3 = 0;
    cVar2 = s___97c2a130[0];
    while (cVar2 != '\0') {
      *(char *)(param_2 + iVar3) = cVar2;
      cVar2 = "."[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    param_2 = param_2 + iVar3;
    if ((*(uint *)(param_1 + 8) & 0x10000) == 0) {
      return param_2;
    }
    iVar3 = 0;
    cVar2 = s_w_97c2d79c[0];
    while (cVar2 != '\0') {
      *(char *)(param_2 + iVar3) = cVar2;
      cVar2 = "w"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
  }
  return param_2 + iVar3;
}

/* _glpWriteDestinationOperand_97bf3658 @ 0x97bf3658 (348 bytes) */
int _glpWriteDestinationOperand_97bf3658(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  uint param_5;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 8) >> 0x11 & 7;
  if (uVar2 == 3) {
    iVar3 = 0;
    cVar1 = s_res_97c2d774[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar3) = cVar1;
      cVar1 = "res"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
  }
  else if (uVar2 < 4) {
    if (uVar2 != 1) goto LAB_97bf3754;
    iVar3 = 0;
    cVar1 = s_tmp_97c2d76c[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar3) = cVar1;
      cVar1 = "tmp"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
  }
  else {
    if (uVar2 != 4) goto LAB_97bf3754;
    iVar3 = 0;
    cVar1 = s_adr_97c2d7e0[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar3) = cVar1;
      cVar1 = "adr"[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
  }
  param_2 = param_2 + iVar3;
LAB_97bf3754:
  iVar3 = _ncpy(param_2,(uint)*(ushort *)(param_1 + 0xe) + param_3);
  if ((param_5 & 0x40) == 0) {
    ((int (*)())_glpWriteDestinationMask)(param_1,param_2 + iVar3,param_4,param_5);
  }
  else {
    ((int (*)())_glpSourceComponents)(param_1,param_2 + iVar3,1,param_4,param_5);
  }
  return;
}

/* _glpWriteTextureOperand_97bf37b4 @ 0x97bf37b4 (760 bytes) */
int _glpWriteTextureOperand_97bf37b4(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  cVar1 = s_texture__97c2d814[0];
  while (cVar1 != '\0') {
    *(char *)(param_2 + iVar2) = cVar1;
    cVar1 = "texture["[iVar2 + 1];
    iVar2 = iVar2 + 1;
  }
  param_2 = param_2 + iVar2;
  if (param_4 == 0) {
    iVar2 = 0;
    cVar1 = s_0_97c2d800[0];
    while (cVar1 != '\0') {
      *(char *)(param_2 + iVar2) = cVar1;
      cVar1 = "0"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    param_3 = param_3 << 3;
  }
  else {
    param_3 = param_3 * 8;
    iVar2 = _ncpy(param_2,*(undefined4 *)(param_4 + (uint)*(ushort *)(param_3 + param_1 + 6) * 0x10)
                 );
  }
  iVar3 = 0;
  cVar1 = s____97c2d820[0];
  while (cVar1 != '\0') {
    *(char *)(param_2 + iVar2 + iVar3) = cVar1;
    cVar1 = "], "[iVar3 + 1];
    iVar3 = iVar3 + 1;
  }
  iVar3 = param_2 + iVar2 + iVar3;
  switch(*(uint *)(param_3 + param_1) >> 5 & 7) {
  case 0:
    iVar2 = 0;
    cVar1 = s_CUBE_97c2d830[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "CUBE"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 1:
    iVar2 = 0;
    cVar1 = s_3D_97c2d82c[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "3D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 2:
    iVar2 = 0;
    cVar1 = s_RECT_97c2d838[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "RECT"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 3:
    iVar2 = 0;
    cVar1 = s_2D_97c2d828[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "2D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 4:
    iVar2 = 0;
    cVar1 = s_1D_97c2d824[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "1D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 5:
    iVar2 = 0;
    cVar1 = s_SHADOWRECT_97c2d840[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "SHADOWRECT"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 6:
    iVar2 = 0;
    cVar1 = s_SHADOW2D_97c2d84c[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "SHADOW2D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  case 7:
    iVar2 = 0;
    cVar1 = s_SHADOW1D_97c2d858[0];
    while (cVar1 != '\0') {
      *(char *)(iVar3 + iVar2) = cVar1;
      cVar1 = "SHADOW1D"[iVar2 + 1];
      iVar2 = iVar2 + 1;
    }
    break;
  default:
    goto switchD_97bf38d0_default;
  }
  iVar3 = iVar3 + iVar2;
switchD_97bf38d0_default:
  return iVar3;
}

/* _glpDisassemble2Op @ 0x97bf3acc (56112 bytes) */
int _glpDisassemble2Op(param_1, param_2, param_3, param_4, param_5, param_6)
  uint *param_1;
  int param_2;
  int *param_3;
  int *param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  undefined *puVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint *in_stack_00000038;
  int in_stack_0000003c;
  undefined4 in_stack_00000040;
  
  puVar2 = PTR__ppstreamOpString_a7b7c108;
  uVar8 = *param_1;
  uVar9 = uVar8 >> 0x12 & 0xff;
  if ((int)param_1[3] < 0) {
    return 0xffffffff;
  }
  if (((((uVar8 >> 0x1d != 0) && ((int)param_1[4] < 0)) &&
       (((param_1[4] >> 0x17 & 7) != 2 || (in_stack_0000003c == 0x8b30)))) ||
      (((1 < uVar8 >> 0x1d && ((int)param_1[6] < 0)) &&
       (((param_1[6] >> 0x17 & 7) != 2 || (in_stack_0000003c == 0x8b30)))))) ||
     ((((2 < uVar8 >> 0x1d && ((int)param_1[8] < 0)) &&
       (((param_1[8] >> 0x17 & 7) != 2 || (in_stack_0000003c == 0x8b30)))) || (0x70 < uVar9)))) {
LAB_97c017a4:
    return 0xffffffff;
  }
  iVar11 = uVar9 * 4;
  iVar6 = param_2;
  switch(uVar9) {
  case 0:
    iVar11 = 1;
    if ((param_1[2] & 0x1000) != 0) {
      iVar11 = (param_1[2] >> 10 & 3) + 1;
    }
    iVar5 = 0;
    if (iVar11 == 0) goto LAB_97c0178c;
    do {
      iVar13 = 0;
      cVar3 = s_MOV_97c2e430[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar13) = cVar3;
        cVar3 = "MOV "[iVar13 + 1];
        iVar13 = iVar13 + 1;
      }
      iVar13 = _glpWriteDestinationOperand(param_1,iVar6 + iVar13,iVar5,0,0);
      iVar6 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar13 + iVar6) = cVar3;
        cVar3 = ", "[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar13 + iVar6,param_5,param_6,2,iVar5,0,8);
      iVar13 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar13) = cVar3;
        cVar3 = ";\n"[iVar13 + 1];
        iVar13 = iVar13 + 1;
      }
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + iVar13;
    } while (iVar5 < iVar11);
    goto LAB_97c01788;
  default:
    goto LAB_97c017a4;
  case 2:
  case 4:
  case 5:
    iVar6 = 0;
    pcVar4 = *(char **)(PTR__ppstreamOpString_a7b7c108 + iVar11);
    cVar3 = *pcVar4;
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar6) = cVar3;
      iVar6 = iVar6 + 1;
      cVar3 = pcVar4[iVar6];
    }
    iVar11 = 0;
    cVar3 = s__97c291c0[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar6 + iVar11) = cVar3;
      cVar3 = " "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar6 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 3:
    *in_stack_00000038 = *in_stack_00000038 | 1;
    iVar11 = 0;
    cVar3 = s_FLR_scratch__97c2e420[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "FLR scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,9);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MOV_97c2e430[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "MOV "[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
    iVar11 = 0;
    cVar3 = s____scratch__97c2e438[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", -scratch;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 6:
    if ((in_stack_00000038[1] & 0x400000) == 0) {
      return 0xffffffff;
    }
    if (in_stack_0000003c != 0x8b30) {
      return 0xffffffff;
    }
    *in_stack_00000038 = *in_stack_00000038 | 0x400003;
    iVar11 = 0;
    cVar3 = s_DDX_scratch__97c2f7fc[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "DDX scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "ABS scratch, scratch;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_DDY_scratch1__97c2f80c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "DDY scratch1, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_ABS_scratch1__scratch1__97c2e880[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "ABS scratch1, scratch1;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_ADD_97c2e6d4[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "ADD "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch__scratch1__97c2e4f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch, scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 7:
    if (((in_stack_00000038[1] & 0x100000) == 0) || (in_stack_0000003c != 0x8b31)) {
      *in_stack_00000038 = *in_stack_00000038 | 0x1003;
      iVar11 = 0;
      cVar3 = s_SLT_scratch__97c2e474[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "SLT scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___kZERO__97c2e484[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_SLT_scratch1__97c2e490[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "SLT scratch1, "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11 + iVar5,param_5,param_6,2,0,0,9);
      iVar11 = 0;
      cVar3 = s___kZERO__97c2e484[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_SUB_97c2e934[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "SUB "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch1__scratch__97c2e93c[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch1, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      *in_stack_00000038 = *in_stack_00000038 | 0x100000;
      iVar11 = 0;
      cVar3 = s_SSG_97c2e92c[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "SSG "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s_____end_97c2e910[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n# end\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 8:
    uVar9 = *in_stack_00000038;
    *in_stack_00000038 = uVar9 | 0x2000;
    uVar8 = param_1[4] >> 0xc & 3;
    if (uVar8 == 2) {
      *in_stack_00000038 = uVar9 | 0x3001;
      iVar11 = 0;
      cVar3 = s_DP3_scratch_x__97c2e734[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "DP3 scratch.x, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
      iVar11 = 0;
      cVar3 = s___kONE__97c2e9b0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", kONE;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
LAB_97bfb2c8:
      iVar11 = iVar6 + iVar11;
    }
    else {
      iVar11 = param_2;
      if (uVar8 < 3) {
        if (uVar8 == 1) {
          *in_stack_00000038 = uVar9 | 0x2001;
          iVar11 = 0;
          cVar3 = s_ADD_scratch_x__97c2e960[0];
          while (cVar3 != '\0') {
            *(char *)(param_2 + iVar11) = cVar3;
            cVar3 = "ADD scratch.x, "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,2);
          iVar11 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar11) = cVar3;
            cVar3 = ", "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,2);
          iVar11 = 0;
          cVar3 = s___97c2d8f8[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar11) = cVar3;
            cVar3 = ";\n"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          goto LAB_97bfb2c8;
        }
      }
      else if (uVar8 == 3) {
        *in_stack_00000038 = uVar9 | 0x3001;
        iVar11 = 0;
        cVar3 = s_DP4_scratch_x__97c2e744[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "DP4 scratch.x, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
        iVar11 = 0;
        cVar3 = s___kONE__97c2e9b0[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", kONE;\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        goto LAB_97bfb2c8;
      }
    }
    iVar6 = 0;
    cVar3 = s_SGE_97c2e91c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar11 + iVar6) = cVar3;
      cVar3 = "SGE "[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar11 + iVar6,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch_x__kHALF__97c2e970[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch.x, kHALF;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 9:
    uVar9 = param_1[4] >> 0xc & 3;
    if (uVar9 == 2) {
      *in_stack_00000038 = *in_stack_00000038 | 1;
      iVar11 = 0;
      cVar3 = s_MUL_scratch_x__97c2e6fc[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "MUL scratch.x, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,2);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,1,2);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MUL_97c2e4f0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "MUL "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch_x__97c2e9a0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch.x, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,2,2);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else if (uVar9 < 3) {
      if (uVar9 != 1) goto LAB_97c0178c;
      iVar11 = 0;
      cVar3 = s_MUL_97c2e4f0[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "MUL "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,2);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,1,2);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      if (uVar9 != 3) goto LAB_97c0178c;
      *in_stack_00000038 = *in_stack_00000038 | 1;
      iVar11 = 0;
      cVar3 = s_MUL_scratch_xy__97c2e510[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "MUL scratch.xy, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0x3210,4);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0x3232,4);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MUL_97c2e4f0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "MUL "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch_x__scratch_y__97c2e524[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch.x, scratch.y;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 10:
    *in_stack_00000038 = *in_stack_00000038 | 0x1000;
    iVar11 = 0;
    cVar3 = s_SUB_97c2e934[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "SUB "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___kONE__97c2e954[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", kONE, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0xc:
    uVar8 = param_1[2];
    *in_stack_00000038 = *in_stack_00000038 | 1;
    uVar9 = param_1[2];
    uVar8 = uVar8 >> 0xd & 0xf;
    iVar11 = 0;
    do {
      if ((uVar8 & 1) != 0) {
        iVar5 = 0;
        cVar3 = s_RSQ_scratch_x__97c2e57c[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = "RSQ scratch.x, "[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar5 = _glpWriteSourceOperand(param_1,iVar6 + iVar5,param_5,param_6,2,0,iVar11,10);
        iVar6 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar6) = cVar3;
          cVar3 = ";\n"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar13 = 0;
        cVar3 = s_RCP_97c2e58c[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar6 + iVar13) = cVar3;
          cVar3 = "RCP "[iVar13 + 1];
          iVar13 = iVar13 + 1;
        }
        iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar6 + iVar13,0,iVar11,2);
        iVar5 = 0;
        cVar3 = s___scratch_x__97c2e594[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = ", scratch.x;\n"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        uVar9 = param_1[2];
        iVar6 = iVar6 + iVar5;
      }
      iVar11 = iVar11 + 1;
      uVar8 = (int)uVar8 >> 1;
    } while (iVar11 <= (int)(uVar9 >> 10 & 3));
    goto LAB_97c01788;
  case 0xd:
  case 0x10:
  case 0x13:
    uVar8 = param_1[2];
    uVar9 = uVar8 >> 0xd & 0xf;
    iVar5 = 0;
    do {
      if ((uVar9 & 1) != 0) {
        pcVar4 = *(char **)(puVar2 + iVar11);
        iVar13 = 0;
        cVar3 = *pcVar4;
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar13) = cVar3;
          iVar13 = iVar13 + 1;
          cVar3 = pcVar4[iVar13];
        }
        iVar12 = 0;
        cVar3 = s__97c291c0[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar13 + iVar12) = cVar3;
          cVar3 = " "[iVar12 + 1];
          iVar12 = iVar12 + 1;
        }
        iVar13 = _glpWriteDestinationOperand(param_1,iVar6 + iVar13 + iVar12,0,iVar5,2);
        iVar6 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar13 + iVar6) = cVar3;
          cVar3 = ", "[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar13 + iVar6,param_5,param_6,2,0,iVar5,10);
        iVar13 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar13) = cVar3;
          cVar3 = ";\n"[iVar13 + 1];
          iVar13 = iVar13 + 1;
        }
        uVar8 = param_1[2];
        iVar6 = iVar6 + iVar13;
      }
      iVar5 = iVar5 + 1;
      uVar9 = (int)uVar9 >> 1;
    } while (iVar5 <= (int)(uVar8 >> 10 & 3));
    goto LAB_97c01788;
  case 0x12:
    *in_stack_00000038 = *in_stack_00000038 | 1;
    uVar8 = param_1[4] >> 0xc & 3;
    if (uVar8 == 1) {
      iVar11 = 0;
      cVar3 = s_SWZ_scratch__97c2e79c[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "SWZ scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = ((int (*)())_glpSourceType)(param_1,param_2 + iVar11,param_5,param_6,2,0,0);
      iVar11 = 0;
      cVar3 = s___x__y__0__0__97c2e7ac[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", x, y, 0, 0;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_DP3_scratch_x__scratch__scratch__97c2e7bc[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = "DP3 scratch.x, scratch, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      if (uVar8 == 0) {
        iVar11 = 0;
        cVar3 = s_MUL_scratch_x__97c2e6fc[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "MUL scratch.x, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else if (uVar8 == 2) {
        iVar11 = 0;
        cVar3 = s_DP3_scratch_x__97c2e734[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "DP3 scratch.x, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else {
        iVar11 = 0;
        cVar3 = s_DP4_scratch_x__97c2e744[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "DP4 scratch.x, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    iVar5 = 0;
    cVar3 = s_RSQ_scratch_x__scratch_x__97c2e754[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "RSQ scratch.x, scratch.x;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_RCP_97c2e58c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "RCP "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch_x__97c2e594[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch.x;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x15:
    if ((((param_1[4] >> 0xc & 3) == 3) || ((in_stack_00000038[1] & 0x800000) == 0)) ||
       (in_stack_0000003c != 0x8b30)) {
      *in_stack_00000038 = *in_stack_00000038 | 1;
      uVar8 = param_1[2] >> 10 & 3;
      if (uVar8 == 0) {
        iVar11 = 0;
        cVar3 = s_MUL_scratch_x__97c2e6fc[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "MUL scratch.x, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else if (uVar8 == 1) {
        iVar11 = 0;
        cVar3 = s_MUL_scratch_xy__97c2e510[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "MUL scratch.xy, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = iVar6 + iVar11;
        iVar11 = 0;
        cVar3 = s_MUL_scratch_x__scratch_x__scratc_97c2e70c[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = "MUL scratch.x, scratch.x, scratch.y;\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else {
        if (uVar8 == 2) {
          iVar11 = 0;
          cVar3 = s_DP3_scratch_x__97c2e734[0];
          while (cVar3 != '\0') {
            *(char *)(param_2 + iVar11) = cVar3;
            cVar3 = "DP3 scratch.x, "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
        }
        else {
          iVar11 = 0;
          cVar3 = s_DP4_scratch_x__97c2e744[0];
          while (cVar3 != '\0') {
            *(char *)(param_2 + iVar11) = cVar3;
            cVar3 = "DP4 scratch.x, "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
        }
        iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      iVar5 = 0;
      cVar3 = s_RSQ_scratch_x__scratch_x__97c2e754[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "RSQ scratch.x, scratch.x;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar6 + iVar11 + iVar5;
      iVar11 = 0;
      cVar3 = s_MUL_97c2e4f0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MUL "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___scratch_x__97c2e594[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch.x;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      uVar8 = *in_stack_00000038;
      *in_stack_00000038 = uVar8 | 0x800000;
      if ((param_1[4] >> 0xc & 3) == 2) {
        iVar11 = 0;
        cVar3 = s_NRM_97c2e6dc[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "NRM "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar11 = param_2 + iVar11;
        if ((param_1[2] & 0x3fc) == 0x6c) {
          iVar11 = _glpWriteDestinationOperand(param_1,iVar11,0,0,0);
        }
        else {
          iVar6 = 0;
          cVar3 = s_scratch_97c2e63c[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar6) = cVar3;
            cVar3 = "scratch"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar11 = iVar11 + iVar6;
        }
        iVar6 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar11 + iVar6) = cVar3;
          cVar3 = ", "[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar11 + iVar6,param_5,param_6,2,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else {
        *in_stack_00000038 = uVar8 | 0x800001;
        iVar11 = 0;
        cVar3 = s_MUL_scratch__97c2e62c[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "MUL scratch, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar11 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
        if ((param_1[4] & 0x3000) == 0) {
          *in_stack_00000038 = *in_stack_00000038 | 0x1000;
          iVar5 = 0;
          cVar3 = s___kFLOAT__97c2e6e4[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = ", kFLOAT;\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        else {
          *in_stack_00000038 = *in_stack_00000038 | 0x1000;
          iVar5 = 0;
          cVar3 = s___kVEC2__97c2e6f0[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = ", kVEC2;\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        iVar6 = 0;
        cVar3 = s_NRM_97c2e6dc[0];
        while (cVar3 != '\0') {
          *(char *)(iVar11 + iVar5 + iVar6) = cVar3;
          cVar3 = "NRM "[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar6 = iVar11 + iVar5 + iVar6;
        if ((param_1[2] & 0x3fc) == 0x6c) {
          iVar6 = _glpWriteDestinationOperand(param_1,iVar6,0,0,0);
        }
        else {
          iVar11 = 0;
          cVar3 = s_scratch_97c2e63c[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar11) = cVar3;
            cVar3 = "scratch"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          iVar6 = iVar6 + iVar11;
        }
        iVar11 = 0;
        cVar3 = s___scratch__97c2e620[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", scratch;\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      iVar6 = iVar6 + iVar11;
      if ((param_1[2] & 0x3fc) == 0x6c) goto LAB_97c01788;
      iVar11 = 0;
      cVar3 = s_MOV_97c2e430[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = "MOV "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch_97c2e65c[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = ((int (*)())_glpWriteComponentsWithDestinationSwizzle)(param_1,iVar6 + iVar11);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 0x16:
    iVar11 = 0;
    cVar3 = s_MUL_97c2e4f0[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "MUL "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___0_0174532925199__97c2e9d0[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", 0.0174532925199;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x17:
    iVar11 = 0;
    cVar3 = s_MUL_97c2e4f0[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "MUL "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___57_295779513082__97c2e9bc[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", 57.295779513082;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x19:
    if (in_stack_0000003c == 0x8b30) {
      iVar11 = 0;
      do {
        iVar5 = 0;
        cVar3 = s_SIN_97c2eb80[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = "SIN "[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar5 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,0,iVar11,2);
        iVar6 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar6) = cVar3;
          cVar3 = ", "[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,2,0,iVar11,10);
        iVar5 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = ";\n"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar11 = iVar11 + 1;
        iVar6 = iVar6 + iVar5;
      } while (iVar11 <= (int)(param_1[2] >> 10 & 3));
      iVar11 = 0;
      cVar3 = s___end_97c2eb88[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = "# end\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      if (((in_stack_00000038[1] & 0x100000) != 0) && (in_stack_0000003c == 0x8b31)) {
        *in_stack_00000038 = *in_stack_00000038 | 0x100000;
        iVar6 = 0;
        cVar3 = s___sine__SIN__using_NV_vertex_pro_97c2eb90[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar6) = cVar3;
          cVar3 = "# sine (SIN) using NV_vertex_program2_option\n"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar6 = param_2 + iVar6;
        iVar11 = 0;
        do {
          iVar5 = 0;
          cVar3 = s_SIN_97c2eb80[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = "SIN "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar5 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,0,iVar11,2);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,2,0,iVar11,10);
          iVar5 = 0;
          cVar3 = s___97c2d8f8[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = ";\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar11 = iVar11 + 1;
          iVar6 = iVar6 + iVar5;
        } while (iVar11 <= (int)(param_1[2] >> 10 & 3));
        goto LAB_97c01788;
      }
      *in_stack_00000038 = *in_stack_00000038 | 0x7007;
      iVar11 = 0;
      cVar3 = s_MAD_scratch__97c2e64c[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "MAD scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___k2PI_RCP__kHALF__97c2ebc0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", k2PI_RCP, kHALF;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_FRC_scratch__scratch__97c2ebd4[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "FRC scratch, scratch;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar6 + iVar11 + iVar5;
      iVar11 = 0;
      cVar3 = s_MAD_scratch__scratch__k2PI___kPI_97c2ebec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MAD scratch, scratch, k2PI, -kPI;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_SLT_scratch1__scratch__kZERO__97c2ec10[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "SLT scratch1, scratch, kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "ABS scratch, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_SUB_scratch__scratch__kHALFPI__97c2ec30[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "SUB scratch, scratch, kHALFPI;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "ABS scratch, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_scratch__scratch__kHALFPI_RC_97c2ec50[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MUL scratch, scratch, kHALFPI_RCP;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_SUB_scratch2__kTHREE__scratch__97c2ec74[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "SUB scratch2, kTHREE, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_scratch2__scratch2__scratch__97c2ec94[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MUL scratch2, scratch2, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_scratch2__scratch2__scratch__97c2ec94[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MUL scratch2, scratch2, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MAD_scratch2__scratch2___kHALF__k_97c2ecb8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MAD scratch2, scratch2, -kHALF, kONE;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MAD_scratch1__scratch1___kTWO__k_97c2ece0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MAD scratch1, scratch1, -kTWO, kONE;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_97c2e4f0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MUL "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch2__scratch1__97c2ed08[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch2, scratch1;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 0x1a:
    if (in_stack_0000003c == 0x8b30) {
      iVar6 = 0;
      cVar3 = s___cosine__COS__97c2ed20[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar6) = cVar3;
        cVar3 = "# cosine (COS)\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar6 = param_2 + iVar6;
      iVar11 = 0;
      do {
        iVar5 = 0;
        cVar3 = s_COS_97c2ed30[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = "COS "[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar5 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,0,iVar11,2);
        iVar6 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar6) = cVar3;
          cVar3 = ", "[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,2,0,iVar11,10);
        iVar5 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = ";\n"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar11 = iVar11 + 1;
        iVar6 = iVar6 + iVar5;
      } while (iVar11 <= (int)(param_1[2] >> 10 & 3));
      iVar11 = 0;
      cVar3 = s___end_97c2eb88[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = "# end\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      if (((in_stack_00000038[1] & 0x100000) != 0) && (in_stack_0000003c == 0x8b31)) {
        *in_stack_00000038 = *in_stack_00000038 | 0x100000;
        iVar6 = 0;
        cVar3 = s___cosine__COS__using_NV_vertex_p_97c2ed38[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar6) = cVar3;
          cVar3 = "# cosine (COS) using NV_vertex_program2_option\n"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar6 = param_2 + iVar6;
        iVar11 = 0;
        do {
          iVar5 = 0;
          cVar3 = s_COS_97c2ed30[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = "COS "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar5 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,0,iVar11,2);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,2,0,iVar11,10);
          iVar5 = 0;
          cVar3 = s___97c2d8f8[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = ";\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar11 = iVar11 + 1;
          iVar6 = iVar6 + iVar5;
        } while (iVar11 <= (int)(param_1[2] >> 10 & 3));
        goto LAB_97c01788;
      }
      *in_stack_00000038 = *in_stack_00000038 | 0x7003;
      iVar11 = 0;
      cVar3 = s_MAD_scratch__97c2e64c[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "MAD scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___k2PI_RCP__kHALF__97c2ebc0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", k2PI_RCP, kHALF;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_FRC_scratch__scratch__97c2ebd4[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "FRC scratch, scratch;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar6 + iVar11 + iVar5;
      iVar11 = 0;
      cVar3 = s_MAD_scratch__scratch__k2PI___kPI_97c2ebec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MAD scratch, scratch, k2PI, -kPI;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "ABS scratch, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_scratch__scratch__kHALFPI_RC_97c2ec50[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MUL scratch, scratch, kHALFPI_RCP;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_SUB_scratch1__kTHREE__scratch__97c2ed68[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "SUB scratch1, kTHREE, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_scratch1__scratch1__scratch__97c2ed88[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MUL scratch1, scratch1, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_scratch1__scratch1__scratch__97c2ed88[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MUL scratch1, scratch1, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MAD_97c2e644[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MAD "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch1___kHALF__kONE__97c2edac[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch1, -kHALF, kONE;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 0x1b:
    *in_stack_00000038 = *in_stack_00000038 | 0x2f00f;
    iVar11 = 0;
    cVar3 = s_MAD_scratch__97c2e64c[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "MAD scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___kPI_RCP__kHALF__97c2edc8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", kPI_RCP, kHALF;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_FRC_scratch__scratch__97c2ebd4[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "FRC scratch, scratch;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_MAD_scratch__scratch__kPI___kHAL_97c2eddc[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MAD scratch, scratch, kPI, -kHALFPI;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_MUL_scratch1__scratch__scratch__97c2ee04[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MUL scratch1, scratch, scratch;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_MUL_scratch2__scratch1__scratch__97c2ee28[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MUL scratch2, scratch1, scratch;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_MUL_scratch3__scratch1__scratch1_97c2ee4c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MUL scratch3, scratch1, scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_MAD_scratch__kTAN_K1__scratch2__s_97c2ee70[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MAD scratch, kTAN_K1, scratch2, scratch;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_MAD_scratch2__kTAN_K2__scratch1__97c2ee9c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MAD scratch2, kTAN_K2, scratch1, kONE;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_MAD_scratch1__kTAN_K3__scratch3__97c2eec4[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MAD scratch1, kTAN_K3, scratch3, scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    pcVar4 = (char *)(iVar5 + iVar11);
    if ((param_1[2] & 0x3000) == 0) {
      iVar11 = 0;
      cVar3 = s_RCP_scratch1_x__scratch1_x__97c2eef0[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11] = cVar3;
        cVar3 = "RCP scratch1.x, scratch1.x;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      pcVar4 = pcVar4 + iVar11;
    }
    else {
      iVar11 = 0;
      do {
        iVar6 = 0;
        cVar3 = s_RCP_scratch1__97c2ea98[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6] = cVar3;
          cVar3 = "RCP scratch1."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar11 = iVar11 + 1;
        pcVar4 = pcVar4 + iVar6;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___scratch1__97c2ef10[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ", scratch1."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ";\n"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
      } while (iVar11 <= (int)(param_1[2] >> 10 & 3));
    }
    iVar11 = 0;
    cVar3 = s_MUL_97c2e4f0[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11] = cVar3;
      cVar3 = "MUL "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,pcVar4 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch__scratch1__97c2e4f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch, scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x1c:
    *in_stack_00000038 = *in_stack_00000038 | 0x1307f;
    iVar11 = 0;
    cVar3 = s_SLT_scratch__97c2e474[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "SLT scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___kZERO__97c2e484[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", kZERO;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MUL_scratch1__97c2ef1c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "MUL scratch1, "[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11 + iVar5,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_SUB_scratch1__kONE__scratch1__97c2ef2c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "SUB scratch1, kONE, scratch1;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_SGE_scratch5__kZERO__scratch1__97c2ef4c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "SGE scratch5, kZERO, scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    pcVar4 = (char *)(iVar5 + iVar11);
    iVar11 = 0;
    do {
      iVar6 = 0;
      cVar3 = s_RSQ_scratch1__97c2ef6c[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6] = cVar3;
        cVar3 = "RSQ scratch1."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar11 = iVar11 + 1;
      pcVar4 = pcVar4 + iVar6;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___scratch1__97c2ef10[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ", scratch1."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ";\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
    } while (iVar11 <= (int)(param_1[4] >> 0xc & 3));
    iVar11 = 0;
    cVar3 = s_MUL_scratch2__97c2ef7c[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11] = cVar3;
      cVar3 = "MUL scratch2, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,pcVar4 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___scratch1__97c2e684[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_ABS_scratch2__scratch2__97c2ef8c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "ABS scratch2, scratch2;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_SLT_scratch6__kONE__scratch2__97c2efa8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "SLT scratch6, kONE, scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    pcVar4 = (char *)(iVar5 + iVar11);
    iVar11 = 0;
    do {
      iVar6 = 0;
      cVar3 = s_RCP_scratch3__97c2efc8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6] = cVar3;
        cVar3 = "RCP scratch3."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar11 = iVar11 + 1;
      pcVar4 = pcVar4 + iVar6;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___scratch2__97c2efd8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ", scratch2."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ";\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
    } while (iVar11 <= (int)(param_1[4] >> 0xc & 3));
    iVar11 = 0;
    cVar3 = s_SUB_scratch3__scratch3__scratch2_97c2efe4[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11] = cVar3;
      cVar3 = "SUB scratch3, scratch3, scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = 0;
    cVar3 = s_MAD_scratch2__scratch6__scratch3_97c2f008[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch2, scratch6, scratch3, scratch2;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MUL_scratch1__scratch2__scratch2_97c2f038[0];
    while (cVar3 != '\0') {
      pcVar4[iVar5 + iVar6 + iVar11] = cVar3;
      cVar3 = "MUL scratch1, scratch2, scratch2;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar5 + iVar6 + iVar11;
    iVar11 = 0;
    cVar3 = s_MUL_scratch3__scratch1__scratch2_97c2f05c[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11 + iVar5] = cVar3;
      cVar3 = "MUL scratch3, scratch1, scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar11 = iVar11 + iVar5;
    iVar6 = 0;
    cVar3 = s_MUL_scratch4__scratch1__scratch1_97c2f080[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MUL scratch4, scratch1, scratch1;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar6 = iVar6 + iVar11;
    iVar11 = 0;
    cVar3 = s_MUL_scratch2__kATAN_K1__scratch2_97c2f0a4[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11 + iVar6] = cVar3;
      cVar3 = "MUL scratch2, kATAN_K1, scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar11 = iVar11 + iVar6;
    iVar6 = 0;
    cVar3 = s_MAD_scratch2__kATAN_K3__scratch3_97c2f0c8[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch2, kATAN_K3, scratch3, scratch2;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar6 = iVar6 + iVar11;
    iVar11 = 0;
    cVar3 = s_MAD_scratch1__kATAN_K2__scratch1_97c2f0f8[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11 + iVar6] = cVar3;
      cVar3 = "MAD scratch1, kATAN_K2, scratch1, kONE;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar11 = iVar11 + iVar6;
    iVar6 = 0;
    cVar3 = s_MAD_scratch1__kATAN_K4__scratch4_97c2f124[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch1, kATAN_K4, scratch4, scratch1;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    pcVar4 = pcVar4 + iVar6 + iVar11;
    iVar11 = 0;
    do {
      iVar6 = 0;
      cVar3 = s_RCP_scratch1__97c2ea98[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6] = cVar3;
        cVar3 = "RCP scratch1."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar11 = iVar11 + 1;
      pcVar4 = pcVar4 + iVar6;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___scratch1__97c2ef10[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ", scratch1."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ";\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
    } while (iVar11 <= (int)(param_1[4] >> 0xc & 3));
    iVar11 = 0;
    cVar3 = s_MUL_scratch2__scratch2__scratch1_97c2f154[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11] = cVar3;
      cVar3 = "MUL scratch2, scratch2, scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = 0;
    cVar3 = s_MAD_scratch1__kTWO___scratch2__k_97c2f178[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch1, kTWO, -scratch2, kHALFPI;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MAD_scratch2__scratch6__scratch1_97c2f1a4[0];
    while (cVar3 != '\0') {
      pcVar4[iVar5 + iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch2, scratch6, scratch1, scratch2;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar5 + iVar6 + iVar11;
    iVar11 = 0;
    cVar3 = s_SUB_scratch1__kHALFPI__scratch2__97c2f1d4[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11 + iVar5] = cVar3;
      cVar3 = "SUB scratch1, kHALFPI, scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar11 = iVar11 + iVar5;
    iVar6 = 0;
    cVar3 = s_MAD_scratch2__scratch5__scratch1_97c2f1f8[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch2, scratch5, scratch1, scratch2;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar6 = iVar6 + iVar11;
    iVar11 = 0;
    cVar3 = s_MAD_scratch__scratch___kTWO__kON_97c2f228[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11 + iVar6] = cVar3;
      cVar3 = "MAD scratch, scratch, -kTWO, kONE;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar11 = iVar11 + iVar6;
    iVar6 = 0;
    cVar3 = s_MUL_97c2e4f0[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MUL "[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,pcVar4 + iVar6 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch2__scratch__97c2f24c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch2, scratch;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x1d:
    *in_stack_00000038 = *in_stack_00000038 | 0x3307f;
    iVar11 = 0;
    cVar3 = s_SLT_scratch__97c2e474[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "SLT scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___kZERO__97c2e484[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", kZERO;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MUL_scratch1__97c2ef1c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "MUL scratch1, "[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11 + iVar5,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_SUB_scratch1__kONE__scratch1__97c2ef2c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "SUB scratch1, kONE, scratch1;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_SGE_scratch5__kZERO__scratch1__97c2ef4c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "SGE scratch5, kZERO, scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    pcVar4 = (char *)(iVar5 + iVar11);
    iVar11 = 0;
    do {
      iVar6 = 0;
      cVar3 = s_RSQ_scratch1__97c2ef6c[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6] = cVar3;
        cVar3 = "RSQ scratch1."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar11 = iVar11 + 1;
      pcVar4 = pcVar4 + iVar6;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___scratch1__97c2ef10[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ", scratch1."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ";\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
    } while (iVar11 <= (int)(param_1[4] >> 0xc & 3));
    iVar11 = 0;
    cVar3 = s_MUL_scratch2__97c2ef7c[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11] = cVar3;
      cVar3 = "MUL scratch2, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,pcVar4 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___scratch1__97c2e684[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_ABS_scratch2__scratch2__97c2ef8c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "ABS scratch2, scratch2;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_ADD_scratch2__scratch2__kOFFSET__97c2f5c0[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "ADD scratch2, scratch2, kOFFSET;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_SLT_scratch6__kONE__scratch2__97c2efa8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "SLT scratch6, kONE, scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    pcVar4 = (char *)(iVar5 + iVar11);
    iVar11 = 0;
    do {
      iVar6 = 0;
      cVar3 = s_RCP_scratch3__97c2efc8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6] = cVar3;
        cVar3 = "RCP scratch3."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar11 = iVar11 + 1;
      pcVar4 = pcVar4 + iVar6;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___scratch2__97c2efd8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ", scratch2."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ";\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
    } while (iVar11 <= (int)(param_1[4] >> 0xc & 3));
    iVar11 = 0;
    cVar3 = s_SUB_scratch3__scratch3__scratch2_97c2efe4[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11] = cVar3;
      cVar3 = "SUB scratch3, scratch3, scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = 0;
    cVar3 = s_MAD_scratch2__scratch6__scratch3_97c2f008[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch2, scratch6, scratch3, scratch2;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MUL_scratch1__scratch2__scratch2_97c2f038[0];
    while (cVar3 != '\0') {
      pcVar4[iVar5 + iVar6 + iVar11] = cVar3;
      cVar3 = "MUL scratch1, scratch2, scratch2;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar5 + iVar6 + iVar11;
    iVar11 = 0;
    cVar3 = s_MUL_scratch3__scratch1__scratch2_97c2f05c[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11 + iVar5] = cVar3;
      cVar3 = "MUL scratch3, scratch1, scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar11 = iVar11 + iVar5;
    iVar6 = 0;
    cVar3 = s_MUL_scratch4__scratch1__scratch1_97c2f080[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MUL scratch4, scratch1, scratch1;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar6 = iVar6 + iVar11;
    iVar11 = 0;
    cVar3 = s_MUL_scratch2__kATAN_K1__scratch2_97c2f0a4[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11 + iVar6] = cVar3;
      cVar3 = "MUL scratch2, kATAN_K1, scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar11 = iVar11 + iVar6;
    iVar6 = 0;
    cVar3 = s_MAD_scratch2__kATAN_K3__scratch3_97c2f0c8[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch2, kATAN_K3, scratch3, scratch2;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar6 = iVar6 + iVar11;
    iVar11 = 0;
    cVar3 = s_MAD_scratch1__kATAN_K2__scratch1_97c2f0f8[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11 + iVar6] = cVar3;
      cVar3 = "MAD scratch1, kATAN_K2, scratch1, kONE;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar11 = iVar11 + iVar6;
    iVar6 = 0;
    cVar3 = s_MAD_scratch1__kATAN_K4__scratch4_97c2f124[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch1, kATAN_K4, scratch4, scratch1;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    pcVar4 = pcVar4 + iVar6 + iVar11;
    iVar11 = 0;
    do {
      iVar6 = 0;
      cVar3 = s_RCP_scratch1__97c2ea98[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6] = cVar3;
        cVar3 = "RCP scratch1."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar11 = iVar11 + 1;
      pcVar4 = pcVar4 + iVar6;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___scratch1__97c2ef10[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ", scratch1."[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
      *pcVar4 = ((byte)iVar11 & 3) + 0x77;
      iVar6 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + 1] = cVar3;
        cVar3 = ";\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + 1;
    } while (iVar11 <= (int)(param_1[4] >> 0xc & 3));
    iVar11 = 0;
    cVar3 = s_MUL_scratch2__scratch2__scratch1_97c2f154[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11] = cVar3;
      cVar3 = "MUL scratch2, scratch2, scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = 0;
    cVar3 = s_MAD_scratch1__kTWO___scratch2__k_97c2f178[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch1, kTWO, -scratch2, kHALFPI;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MAD_scratch2__scratch6__scratch1_97c2f1a4[0];
    while (cVar3 != '\0') {
      pcVar4[iVar5 + iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch2, scratch6, scratch1, scratch2;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar5 + iVar6 + iVar11;
    iVar11 = 0;
    cVar3 = s_SUB_scratch1__kHALFPI__scratch2__97c2f1d4[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11 + iVar5] = cVar3;
      cVar3 = "SUB scratch1, kHALFPI, scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar11 = iVar11 + iVar5;
    iVar6 = 0;
    cVar3 = s_MAD_scratch2__scratch5__scratch1_97c2f1f8[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MAD scratch2, scratch5, scratch1, scratch2;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar6 = iVar6 + iVar11;
    iVar11 = 0;
    cVar3 = s_MAD_scratch__scratch___kTWO__kON_97c2f228[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11 + iVar6] = cVar3;
      cVar3 = "MAD scratch, scratch, -kTWO, kONE;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar11 = iVar11 + iVar6;
    iVar6 = 0;
    cVar3 = s_MUL_scratch__scratch2__scratch__97c2f5e4[0];
    while (cVar3 != '\0') {
      pcVar4[iVar6 + iVar11] = cVar3;
      cVar3 = "MUL scratch, scratch2, scratch;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar6 = iVar6 + iVar11;
    iVar11 = 0;
    cVar3 = s_SUB_97c2e934[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11 + iVar6] = cVar3;
      cVar3 = "SUB "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,pcVar4 + iVar11 + iVar6,0,0,0);
    iVar11 = 0;
    cVar3 = s___kHALFPI__scratch__97c2f608[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", kHALFPI, scratch;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x1e:
    *in_stack_00000038 = *in_stack_00000038 | 0x331ff;
    if (*param_1 >> 0x1d == 2) {
      iVar11 = 0;
      cVar3 = s_SGE_scratch__97c2f264[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "SGE scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___kZERO__97c2e484[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MAD_scratch__scratch__k2PI___kPI_97c2ebec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "MAD scratch, scratch, k2PI, -kPI;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar6 + iVar11 + iVar5;
      iVar11 = 0;
      cVar3 = s_SLT_scratch1__97c2e490[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "SLT scratch1, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,3,0,0,8);
      iVar11 = 0;
      cVar3 = s___kZERO__97c2e484[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MUL_scratch4__scratch__scratch1__97c2f274[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "MUL scratch4, scratch, scratch1;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar6 + iVar11 + iVar5;
      iVar11 = 0;
      cVar3 = s_ABS_scratch__97c2e448[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "ABS scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,3,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_SGE_scratch5___scratch__kZERO__97c2f298[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "SGE scratch5, -scratch, kZERO;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar6 + iVar11 + iVar5;
      iVar11 = 0;
      cVar3 = s_SLT_scratch__97c2e474[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "SLT scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___kZERO__97c2e484[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MAD_scratch6__scratch___kPI__kHA_97c2f2b8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "MAD scratch6, scratch, -kPI, kHALFPI;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar6 + iVar11 + iVar5;
      iVar11 = 0;
      cVar3 = s_MAD_scratch1__scratch5__kOFFSET__97c2f2e0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MAD scratch1, scratch5, kOFFSET, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,3,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      pcVar4 = (char *)(iVar6 + iVar11);
      iVar11 = 0;
      do {
        iVar6 = 0;
        cVar3 = s_RCP_scratch__97c2e5f0[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6] = cVar3;
          cVar3 = "RCP scratch."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar11 = iVar11 + 1;
        pcVar4 = pcVar4 + iVar6;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___scratch1__97c2ef10[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ", scratch1."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ";\n"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
      } while (iVar11 <= (int)(param_1[6] >> 0xc & 3));
      iVar11 = 0;
      cVar3 = s_MUL_scratch__97c2e62c[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11] = cVar3;
        cVar3 = "MUL scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,pcVar4 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___scratch__97c2e620[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_SLT_scratch7__scratch__kZERO__97c2f304[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "SLT scratch7, scratch, kZERO;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar6 + iVar11 + iVar5;
      iVar11 = 0;
      cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "ABS scratch, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_SLT_scratch8__kONE__scratch__97c2f324[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "SLT scratch8, kONE, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_SGE_scratch1___scratch__kZERO__97c2f344[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "SGE scratch1, -scratch, kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MAD_scratch__scratch1__kOFFSET__s_97c2f364[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MAD scratch, scratch1, kOFFSET, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      pcVar4 = (char *)(iVar5 + iVar11);
      iVar11 = 0;
      do {
        iVar6 = 0;
        cVar3 = s_RCP_scratch1__97c2ea98[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6] = cVar3;
          cVar3 = "RCP scratch1."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar11 = iVar11 + 1;
        pcVar4 = pcVar4 + iVar6;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___scratch__97c2eaa8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ", scratch."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ";\n"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
      } while (iVar11 <= (int)(param_1[4] >> 0xc & 3));
      iVar11 = 0;
      cVar3 = s_SUB_scratch1__scratch1__scratch__97c2f390[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11] = cVar3;
        cVar3 = "SUB scratch1, scratch1, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = 0;
      cVar3 = s_MAD_scratch__scratch8__scratch1__97c2f3b4[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MAD scratch, scratch8, scratch1, scratch;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MUL_scratch1__scratch__scratch__97c2ee04[0];
      while (cVar3 != '\0') {
        pcVar4[iVar5 + iVar6 + iVar11] = cVar3;
        cVar3 = "MUL scratch1, scratch, scratch;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar5 + iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_scratch2__scratch1__scratch__97c2ee28[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11 + iVar5] = cVar3;
        cVar3 = "MUL scratch2, scratch1, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar11 = iVar11 + iVar5;
      iVar6 = 0;
      cVar3 = s_MUL_scratch3__scratch1__scratch1_97c2ee4c[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MUL scratch3, scratch1, scratch1;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_scratch__kATAN_K1__scratch__97c2f3e0[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11 + iVar6] = cVar3;
        cVar3 = "MUL scratch, kATAN_K1, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar11 = iVar11 + iVar6;
      iVar6 = 0;
      cVar3 = s_MAD_scratch2__kATAN_K3__scratch2_97c2f404[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MAD scratch2, kATAN_K3, scratch2, scratch;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_MAD_scratch__kATAN_K2__scratch1__97c2f430[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11 + iVar6] = cVar3;
        cVar3 = "MAD scratch, kATAN_K2, scratch1, kONE;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar11 = iVar11 + iVar6;
      iVar6 = 0;
      cVar3 = s_MAD_scratch__kATAN_K4__scratch3__97c2f458[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MAD scratch, kATAN_K4, scratch3, scratch;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + iVar11;
      iVar11 = 0;
      do {
        iVar6 = 0;
        cVar3 = s_RCP_scratch__97c2e5f0[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6] = cVar3;
          cVar3 = "RCP scratch."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar11 = iVar11 + 1;
        pcVar4 = pcVar4 + iVar6;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___scratch__97c2eaa8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ", scratch."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ";\n"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
      } while (iVar11 <= (int)(param_1[4] >> 0xc & 3));
      iVar11 = 0;
      cVar3 = s_MUL_scratch1__scratch2__scratch__97c2f484[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11] = cVar3;
        cVar3 = "MUL scratch1, scratch2, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = 0;
      cVar3 = s_MAD_scratch__kTWO___scratch1__kH_97c2f4a8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MAD scratch, kTWO, -scratch1, kHALFPI;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MAD_scratch__scratch8__scratch__s_97c2f4d0[0];
      while (cVar3 != '\0') {
        pcVar4[iVar5 + iVar6 + iVar11] = cVar3;
        cVar3 = "MAD scratch, scratch8, scratch, scratch1;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar5 + iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_MAD_scratch2__scratch7___kTWO__k_97c2f4fc[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11 + iVar5] = cVar3;
        cVar3 = "MAD scratch2, scratch7, -kTWO, kONE;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar11 = iVar11 + iVar5;
      iVar6 = 0;
      cVar3 = s_MUL_scratch__scratch__scratch2__97c2f524[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MUL scratch, scratch, scratch2;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_ADD_scratch__scratch__scratch4__97c2f548[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11 + iVar6] = cVar3;
        cVar3 = "ADD scratch, scratch, scratch4;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar11 = iVar11 + iVar6;
      iVar6 = 0;
      cVar3 = s_SUB_scratch1__scratch6__scratch__97c2f56c[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "SUB scratch1, scratch6, scratch;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_MAD_97c2e644[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11 + iVar6] = cVar3;
        cVar3 = "MAD "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,pcVar4 + iVar11 + iVar6,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch5__scratch1__scratch__97c2f590[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch5, scratch1, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      iVar11 = 0;
      cVar3 = s_SLT_scratch__97c2e474[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "SLT scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___kZERO__97c2e484[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_ABS_scratch2__97c2f5b0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "ABS scratch2, "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11 + iVar5,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_SLT_scratch6__kONE__scratch2__97c2efa8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "SLT scratch6, kONE, scratch2;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      pcVar4 = (char *)(iVar6 + iVar11 + iVar5);
      iVar11 = 0;
      do {
        iVar6 = 0;
        cVar3 = s_RCP_scratch3__97c2efc8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6] = cVar3;
          cVar3 = "RCP scratch3."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar11 = iVar11 + 1;
        pcVar4 = pcVar4 + iVar6;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___scratch2__97c2efd8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ", scratch2."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ";\n"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
      } while (iVar11 <= (int)(param_1[4] >> 0xc & 3));
      iVar11 = 0;
      cVar3 = s_SUB_scratch3__scratch3__scratch2_97c2efe4[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11] = cVar3;
        cVar3 = "SUB scratch3, scratch3, scratch2;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = 0;
      cVar3 = s_MAD_scratch2__scratch6__scratch3_97c2f008[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MAD scratch2, scratch6, scratch3, scratch2;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MUL_scratch1__scratch2__scratch2_97c2f038[0];
      while (cVar3 != '\0') {
        pcVar4[iVar5 + iVar6 + iVar11] = cVar3;
        cVar3 = "MUL scratch1, scratch2, scratch2;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar5 + iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_scratch3__scratch1__scratch2_97c2f05c[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11 + iVar5] = cVar3;
        cVar3 = "MUL scratch3, scratch1, scratch2;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar11 = iVar11 + iVar5;
      iVar6 = 0;
      cVar3 = s_MUL_scratch4__scratch1__scratch1_97c2f080[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MUL scratch4, scratch1, scratch1;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_scratch2__kATAN_K1__scratch2_97c2f0a4[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11 + iVar6] = cVar3;
        cVar3 = "MUL scratch2, kATAN_K1, scratch2;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar11 = iVar11 + iVar6;
      iVar6 = 0;
      cVar3 = s_MAD_scratch2__kATAN_K3__scratch3_97c2f0c8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MAD scratch2, kATAN_K3, scratch3, scratch2;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar6 = iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_MAD_scratch1__kATAN_K2__scratch1_97c2f0f8[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11 + iVar6] = cVar3;
        cVar3 = "MAD scratch1, kATAN_K2, scratch1, kONE;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar11 = iVar11 + iVar6;
      iVar6 = 0;
      cVar3 = s_MAD_scratch1__kATAN_K4__scratch4_97c2f124[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MAD scratch1, kATAN_K4, scratch4, scratch1;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      pcVar4 = pcVar4 + iVar6 + iVar11;
      iVar11 = 0;
      do {
        iVar6 = 0;
        cVar3 = s_RCP_scratch1__97c2ea98[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6] = cVar3;
          cVar3 = "RCP scratch1."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar11 = iVar11 + 1;
        pcVar4 = pcVar4 + iVar6;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___scratch1__97c2ef10[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ", scratch1."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ";\n"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
      } while (iVar11 <= (int)(param_1[4] >> 0xc & 3));
      iVar11 = 0;
      cVar3 = s_MUL_scratch2__scratch2__scratch1_97c2f154[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11] = cVar3;
        cVar3 = "MUL scratch2, scratch2, scratch1;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = 0;
      cVar3 = s_MAD_scratch1__kTWO___scratch2__k_97c2f178[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MAD scratch1, kTWO, -scratch2, kHALFPI;\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MAD_scratch2__scratch6__scratch1_97c2f1a4[0];
      while (cVar3 != '\0') {
        pcVar4[iVar5 + iVar6 + iVar11] = cVar3;
        cVar3 = "MAD scratch2, scratch6, scratch1, scratch2;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar5 + iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_MAD_scratch__scratch___kTWO__kON_97c2f228[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11 + iVar5] = cVar3;
        cVar3 = "MAD scratch, scratch, -kTWO, kONE;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar11 = iVar11 + iVar5;
      iVar6 = 0;
      cVar3 = s_MUL_97c2e4f0[0];
      while (cVar3 != '\0') {
        pcVar4[iVar6 + iVar11] = cVar3;
        cVar3 = "MUL "[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,pcVar4 + iVar6 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch2__scratch__97c2f24c[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch2, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 0x1f:
  case 0x20:
    iVar5 = 1;
    if ((param_1[2] & 0x1000) != 0) {
      iVar5 = (param_1[2] >> 10 & 3) + 1;
    }
    iVar13 = 0;
    if (iVar5 == 0) goto LAB_97c0178c;
    do {
      iVar12 = 0;
      pcVar4 = *(char **)(PTR__ppstreamOpString_a7b7c108 + iVar11);
      cVar3 = *pcVar4;
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar12) = cVar3;
        iVar12 = iVar12 + 1;
        cVar3 = pcVar4[iVar12];
      }
      iVar7 = 0;
      cVar3 = s__97c291c0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar12 + iVar7) = cVar3;
        cVar3 = " "[iVar7 + 1];
        iVar7 = iVar7 + 1;
      }
      iVar12 = _glpWriteDestinationOperand(param_1,iVar6 + iVar12 + iVar7,iVar13,0,0);
      iVar6 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar12 + iVar6) = cVar3;
        cVar3 = ", "[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar7 = iVar13;
      if ((param_1[4] & 0x4000) == 0) {
        iVar7 = 0;
      }
      iVar12 = _glpWriteSourceOperand(param_1,iVar12 + iVar6,param_5,param_6,2,iVar7,0,8);
      iVar6 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar12 + iVar6) = cVar3;
        cVar3 = ", "[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar7 = iVar13;
      if ((param_1[6] & 0x4000) == 0) {
        iVar7 = 0;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar12 + iVar6,param_5,param_6,3,iVar7,0,8);
      iVar12 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar12) = cVar3;
        cVar3 = ";\n"[iVar12 + 1];
        iVar12 = iVar12 + 1;
      }
      iVar13 = iVar13 + 1;
      iVar6 = iVar6 + iVar12;
    } while (iVar13 < iVar5);
    goto LAB_97c01788;
  case 0x21:
    *in_stack_00000038 = *in_stack_00000038 | 1;
    if ((param_1[6] >> 0xc & 3) == 0) {
      iVar11 = 0;
      cVar3 = s_RCP_scratch__97c2e600[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "RCP scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,3,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = iVar6 + iVar11;
    }
    else {
      iVar11 = 0;
      do {
        iVar5 = 0;
        cVar3 = s_RCP_scratch__97c2e5f0[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = "RCP scratch."[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar13 = iVar11 + 1;
        pcVar4 = (char *)(iVar6 + iVar5);
        *pcVar4 = ((byte)iVar13 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ", "[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,pcVar4 + iVar6 + 1,param_5,param_6,3,0,iVar11,10);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = iVar6 + iVar11;
        iVar11 = iVar13;
      } while (iVar13 <= (int)(param_1[6] >> 0xc & 3));
    }
    iVar11 = 0;
    cVar3 = s_MUL_scratch__scratch__97c2e9ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = "MUL scratch, scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_FLR_scratch__scratch__97c2ea04[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "FLR scratch, scratch;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_MAD_97c2e644[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MAD "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch__97c2e570[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,9);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x22:
  case 0x4e:
    bVar1 = false;
    if ((*(short *)((int)param_1 + 0xe) == *(short *)((int)param_1 + 0x16)) ||
       (*(short *)((int)param_1 + 0xe) == *(short *)((int)param_1 + 0x1e))) {
      bVar1 = true;
    }
    uVar8 = param_1[4];
    if (((uVar8 & 0x4000) == 0) || ((param_1[6] & 0x4000) == 0)) {
      if (((uVar8 & 0x4000) == 0) && ((param_1[6] & 0x4000) == 0)) {
        iVar11 = 0;
        cVar3 = s_MUL_97c2e4f0[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "MUL "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,8);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        break;
      }
      if (((uVar8 & 0x3000) == 0) || (uVar9 = param_1[6] >> 0xc & 3, uVar9 == 0)) {
        iVar11 = 0;
        do {
          iVar5 = 0;
          cVar3 = s_MUL_97c2e4f0[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = "MUL "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar5 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,iVar11,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar13 = iVar11;
          if ((param_1[4] & 0x4000) == 0) {
            iVar13 = 0;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,2,iVar13,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar13 = iVar11;
          if ((param_1[6] & 0x4000) == 0) {
            iVar13 = 0;
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,iVar13,0,0);
          iVar5 = 0;
          cVar3 = s___97c2d8f8[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = ";\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar11 = iVar11 + 1;
          iVar6 = iVar6 + iVar5;
        } while (iVar11 <= (int)(param_1[2] >> 10 & 3));
      }
      else if ((uVar8 & 0x4000) == 0) {
        if (bVar1) {
          if ((uVar9 != 1) ||
             (((in_stack_00000038[1] & 0x800000) != 0 && (in_stack_0000003c == 0x8b30)))) {
            *in_stack_00000038 = *in_stack_00000038 | 1;
            uVar8 = param_1[2];
            uVar10 = uVar8 >> 0xd & 0xf;
            iVar6 = 0;
            iVar11 = param_2;
            do {
              if ((uVar10 & 1) != 0) {
                if (uVar9 != 1) {
                  if (uVar9 == 2) {
                    iVar5 = 0;
                    cVar3 = s_DP3_scratch_97c2e6bc[0];
                    while (cVar3 != '\0') {
                      *(char *)(iVar11 + iVar5) = cVar3;
                      cVar3 = "DP3 scratch"[iVar5 + 1];
                      iVar5 = iVar5 + 1;
                    }
                  }
                  else {
                    iVar5 = 0;
                    cVar3 = s_DP4_scratch_97c2e6c8[0];
                    while (cVar3 != '\0') {
                      *(char *)(iVar11 + iVar5) = cVar3;
                      cVar3 = "DP4 scratch"[iVar5 + 1];
                      iVar5 = iVar5 + 1;
                    }
                  }
                }
                else {
                  *in_stack_00000038 = *in_stack_00000038 | 0x800000;
                  iVar5 = 0;
                  cVar3 = s___NV_fragment_program2_DP2_97c2e694[0];
                  while (cVar3 != '\0') {
                    *(char *)(iVar11 + iVar5) = cVar3;
                    cVar3 = "# NV_fragment_program2:DP2\n"[iVar5 + 1];
                    iVar5 = iVar5 + 1;
                  }
                  iVar11 = iVar11 + iVar5;
                  iVar5 = 0;
                  cVar3 = s_DP2_scratch_97c2e6b0[0];
                  while (cVar3 != '\0') {
                    *(char *)(iVar11 + iVar5) = cVar3;
                    cVar3 = "DP2 scratch"[iVar5 + 1];
                    iVar5 = iVar5 + 1;
                  }
                }
                iVar5 = ((int (*)())_glpWriteDestinationMask)(param_1,iVar11 + iVar5,iVar6,2);
                iVar11 = 0;
                cVar3 = s___97c2d7ec[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar5 + iVar11) = cVar3;
                  cVar3 = ", "[iVar11 + 1];
                  iVar11 = iVar11 + 1;
                }
                iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,2,0,0,0);
                iVar11 = 0;
                cVar3 = s___97c2d7ec[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar5 + iVar11) = cVar3;
                  cVar3 = ", "[iVar11 + 1];
                  iVar11 = iVar11 + 1;
                }
                iVar11 = _glpWriteSourceOperand
                                   (param_1,iVar5 + iVar11,param_5,param_6,3,iVar6,0,0x10);
                iVar5 = 0;
                cVar3 = s___97c2d8f8[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar11 + iVar5) = cVar3;
                  cVar3 = ";\n"[iVar5 + 1];
                  iVar5 = iVar5 + 1;
                }
                uVar8 = param_1[2];
                iVar11 = iVar11 + iVar5;
              }
              iVar6 = iVar6 + 1;
              uVar10 = (int)uVar10 >> 1;
            } while (iVar6 <= (int)(uVar8 >> 10 & 3));
            iVar6 = 0;
            cVar3 = s_MOV_97c2e430[0];
            while (cVar3 != '\0') {
              *(char *)(iVar11 + iVar6) = cVar3;
              cVar3 = "MOV "[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            iVar6 = _glpWriteDestinationOperand(param_1,iVar11 + iVar6,0,0,0);
            iVar11 = 0;
            cVar3 = s___scratch__97c2e620[0];
            while (cVar3 != '\0') {
              *(char *)(iVar6 + iVar11) = cVar3;
              cVar3 = ", scratch;\n"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          else {
            *in_stack_00000038 = *in_stack_00000038 | 3;
            uVar8 = param_1[2];
            uVar9 = uVar8 >> 0xd & 0xf;
            iVar6 = 0;
            iVar11 = param_2;
            do {
              if ((uVar9 & 1) != 0) {
                iVar5 = 0;
                cVar3 = s_MUL_scratch__97c2e62c[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar11 + iVar5) = cVar3;
                  cVar3 = "MUL scratch, "[iVar5 + 1];
                  iVar5 = iVar5 + 1;
                }
                iVar5 = _glpWriteSourceOperand(param_1,iVar11 + iVar5,param_5,param_6,2,0,0,0);
                iVar11 = 0;
                cVar3 = s___97c2d7ec[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar5 + iVar11) = cVar3;
                  cVar3 = ", "[iVar11 + 1];
                  iVar11 = iVar11 + 1;
                }
                iVar5 = _glpWriteSourceOperand
                                  (param_1,iVar5 + iVar11,param_5,param_6,3,iVar6,0,0x10);
                iVar11 = 0;
                cVar3 = s___97c2d8f8[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar5 + iVar11) = cVar3;
                  cVar3 = ";\n"[iVar11 + 1];
                  iVar11 = iVar11 + 1;
                }
                iVar13 = 0;
                cVar3 = s_ADD_scratch1_97c2e674[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar5 + iVar11 + iVar13) = cVar3;
                  cVar3 = "ADD scratch1"[iVar13 + 1];
                  iVar13 = iVar13 + 1;
                }
                iVar11 = ((int (*)())_glpWriteDestinationMask)(param_1,iVar5 + iVar11 + iVar13,iVar6,2);
                iVar5 = 0;
                cVar3 = s___scratch_x__scratch_y__97c2e524[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar11 + iVar5) = cVar3;
                  cVar3 = ", scratch.x, scratch.y;\n"[iVar5 + 1];
                  iVar5 = iVar5 + 1;
                }
                uVar8 = param_1[2];
                iVar11 = iVar11 + iVar5;
              }
              iVar6 = iVar6 + 1;
              uVar9 = (int)uVar9 >> 1;
            } while (iVar6 <= (int)(uVar8 >> 10 & 3));
            iVar6 = 0;
            cVar3 = s_MOV_97c2e430[0];
            while (cVar3 != '\0') {
              *(char *)(iVar11 + iVar6) = cVar3;
              cVar3 = "MOV "[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            iVar6 = _glpWriteDestinationOperand(param_1,iVar11 + iVar6,0,0,0);
            iVar11 = 0;
            cVar3 = s___scratch1__97c2e684[0];
            while (cVar3 != '\0') {
              *(char *)(iVar6 + iVar11) = cVar3;
              cVar3 = ", scratch1;\n"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          break;
        }
        if ((uVar9 != 1) ||
           (((in_stack_00000038[1] & 0x800000) != 0 && (in_stack_0000003c == 0x8b30)))) {
          uVar8 = param_1[2];
          uVar10 = uVar8 >> 0xd & 0xf;
          iVar11 = 0;
          do {
            if ((uVar10 & 1) != 0) {
              if (uVar9 != 1) {
                if (uVar9 == 2) {
                  iVar5 = 0;
                  cVar3 = s_DP3_97c2e548[0];
                  while (cVar3 != '\0') {
                    *(char *)(iVar6 + iVar5) = cVar3;
                    cVar3 = "DP3 "[iVar5 + 1];
                    iVar5 = iVar5 + 1;
                  }
                }
                else {
                  iVar5 = 0;
                  cVar3 = s_DP4_97c2e550[0];
                  while (cVar3 != '\0') {
                    *(char *)(iVar6 + iVar5) = cVar3;
                    cVar3 = "DP4 "[iVar5 + 1];
                    iVar5 = iVar5 + 1;
                  }
                }
              }
              else {
                *in_stack_00000038 = *in_stack_00000038 | 0x800000;
                iVar5 = 0;
                cVar3 = s___NV_fragment_program2_DP2_97c2e694[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar6 + iVar5) = cVar3;
                  cVar3 = "# NV_fragment_program2:DP2\n"[iVar5 + 1];
                  iVar5 = iVar5 + 1;
                }
                iVar6 = iVar6 + iVar5;
                iVar5 = 0;
                cVar3 = s_DP2_97c2e540[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar6 + iVar5) = cVar3;
                  cVar3 = "DP2 "[iVar5 + 1];
                  iVar5 = iVar5 + 1;
                }
              }
              iVar5 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,0,iVar11,2);
              iVar6 = 0;
              cVar3 = s___97c2d7ec[0];
              while (cVar3 != '\0') {
                *(char *)(iVar5 + iVar6) = cVar3;
                cVar3 = ", "[iVar6 + 1];
                iVar6 = iVar6 + 1;
              }
              iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,2,0,0,0);
              iVar6 = 0;
              cVar3 = s___97c2d7ec[0];
              while (cVar3 != '\0') {
                *(char *)(iVar5 + iVar6) = cVar3;
                cVar3 = ", "[iVar6 + 1];
                iVar6 = iVar6 + 1;
              }
              iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,iVar11,0,0x10);
              iVar5 = 0;
              cVar3 = s___97c2d8f8[0];
              while (cVar3 != '\0') {
                *(char *)(iVar6 + iVar5) = cVar3;
                cVar3 = ";\n"[iVar5 + 1];
                iVar5 = iVar5 + 1;
              }
              uVar8 = param_1[2];
              iVar6 = iVar6 + iVar5;
            }
            iVar11 = iVar11 + 1;
            uVar10 = (int)uVar10 >> 1;
          } while (iVar11 <= (int)(uVar8 >> 10 & 3));
        }
        else {
          *in_stack_00000038 = *in_stack_00000038 | 1;
          uVar8 = param_1[2];
          uVar9 = uVar8 >> 0xd & 0xf;
          iVar11 = 0;
          do {
            if ((uVar9 & 1) != 0) {
              iVar5 = 0;
              cVar3 = s_MUL_scratch__97c2e62c[0];
              while (cVar3 != '\0') {
                *(char *)(iVar6 + iVar5) = cVar3;
                cVar3 = "MUL scratch, "[iVar5 + 1];
                iVar5 = iVar5 + 1;
              }
              iVar5 = _glpWriteSourceOperand(param_1,iVar6 + iVar5,param_5,param_6,2,0,0,0);
              iVar6 = 0;
              cVar3 = s___97c2d7ec[0];
              while (cVar3 != '\0') {
                *(char *)(iVar5 + iVar6) = cVar3;
                cVar3 = ", "[iVar6 + 1];
                iVar6 = iVar6 + 1;
              }
              iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,iVar11,0,0x10);
              iVar6 = 0;
              cVar3 = s___97c2d8f8[0];
              while (cVar3 != '\0') {
                *(char *)(iVar5 + iVar6) = cVar3;
                cVar3 = ";\n"[iVar6 + 1];
                iVar6 = iVar6 + 1;
              }
              iVar13 = 0;
              cVar3 = s_ADD_97c2e6d4[0];
              while (cVar3 != '\0') {
                *(char *)(iVar5 + iVar6 + iVar13) = cVar3;
                cVar3 = "ADD "[iVar13 + 1];
                iVar13 = iVar13 + 1;
              }
              iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar6 + iVar13,0,iVar11,2);
              iVar5 = 0;
              cVar3 = s___scratch_x__scratch_y__97c2e524[0];
              while (cVar3 != '\0') {
                *(char *)(iVar6 + iVar5) = cVar3;
                cVar3 = ", scratch.x, scratch.y;\n"[iVar5 + 1];
                iVar5 = iVar5 + 1;
              }
              uVar8 = param_1[2];
              iVar6 = iVar6 + iVar5;
            }
            iVar11 = iVar11 + 1;
            uVar9 = (int)uVar9 >> 1;
          } while (iVar11 <= (int)(uVar8 >> 10 & 3));
        }
      }
      else {
        *in_stack_00000038 = *in_stack_00000038 | 1;
        uVar8 = param_1[4];
        uVar9 = 0;
        do {
          if (uVar9 == 0) {
            iVar5 = 0;
            iVar11 = iVar5;
            cVar3 = s_MUL_97c2e4f0[0];
            if (s_MUL_97c2e4f0[0] != '\0') {
              do {
                *(char *)(iVar6 + iVar11) = cVar3;
                iVar5 = iVar11 + 1;
                cVar3 = "MUL "[iVar11 + 1];
                iVar11 = iVar5;
              } while (cVar3 != '\0');
              goto LAB_97bf6dac;
            }
          }
          else {
            iVar5 = 0;
            iVar11 = iVar5;
            cVar3 = s_MAD_97c2e644[0];
            if (s_MAD_97c2e644[0] != '\0') {
              do {
                *(char *)(iVar6 + iVar11) = cVar3;
                iVar5 = iVar11 + 1;
                cVar3 = "MAD "[iVar11 + 1];
                iVar11 = iVar5;
              } while (cVar3 != '\0');
LAB_97bf6dac:
              uVar8 = param_1[4];
            }
          }
          iVar6 = iVar6 + iVar5;
          if (uVar9 == (uVar8 >> 0xc & 3)) {
            iVar6 = _glpWriteDestinationOperand(param_1,iVar6,0,0,0);
            iVar11 = 0;
            cVar3 = s___97c2d7ec[0];
            while (cVar3 != '\0') {
              *(char *)(iVar6 + iVar11) = cVar3;
              cVar3 = ", "[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          else {
            iVar11 = 0;
            cVar3 = s_scratch__97c2e668[0];
            while (cVar3 != '\0') {
              *(char *)(iVar6 + iVar11) = cVar3;
              cVar3 = "scratch, "[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,uVar9,0,8);
          iVar11 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar11) = cVar3;
            cVar3 = ", "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,uVar9,2);
          if (uVar9 == 0) {
            iVar11 = 0;
            cVar3 = s___97c2d8f8[0];
            while (cVar3 != '\0') {
              *(char *)(iVar6 + iVar11) = cVar3;
              cVar3 = ";\n"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          else {
            iVar11 = 0;
            cVar3 = s___scratch__97c2e620[0];
            while (cVar3 != '\0') {
              *(char *)(iVar6 + iVar11) = cVar3;
              cVar3 = ", scratch;\n"[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
          }
          uVar8 = param_1[4];
          iVar6 = iVar6 + iVar11;
          uVar9 = uVar9 + 1;
        } while ((int)uVar9 <= (int)(uVar8 >> 0xc & 3));
      }
    }
    else {
      *in_stack_00000038 = *in_stack_00000038 | 1;
      uVar8 = param_1[2] >> 10 & 3;
      if (uVar8 == 1) {
        iVar11 = 0;
        do {
          iVar5 = 0;
          cVar3 = s_MUL_scratch__97c2e62c[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = "MUL scratch, "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar6 + iVar5,param_5,param_6,2,0,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,0,iVar11,2);
          iVar6 = 0;
          cVar3 = s___97c2d8f8[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ";\n"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar13 = 0;
          cVar3 = s_MAD_97c2e644[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6 + iVar13) = cVar3;
            cVar3 = "MAD "[iVar13 + 1];
            iVar13 = iVar13 + 1;
          }
          iVar13 = iVar5 + iVar6 + iVar13;
          if (!bVar1) {
            iVar6 = _glpWriteDestinationOperand(param_1,iVar13,iVar11,0,0);
          }
          else {
            iVar5 = 0;
            cVar3 = s_scratch_97c2e63c[0];
            while (cVar3 != '\0') {
              *(char *)(iVar13 + iVar5) = cVar3;
              cVar3 = "scratch"[iVar5 + 1];
              iVar5 = iVar5 + 1;
            }
            iVar6 = _ncpy(iVar13 + iVar5,iVar11 + 1);
            iVar6 = iVar13 + iVar5 + iVar6;
          }
          iVar13 = iVar11 + 1;
          iVar5 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = ", "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar6 + iVar5,param_5,param_6,2,1,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,1,iVar11,2);
          iVar11 = 0;
          cVar3 = s___scratch__97c2e620[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar11) = cVar3;
            cVar3 = ", scratch;\n"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          iVar6 = iVar6 + iVar11;
          iVar11 = iVar13;
        } while (iVar13 <= (int)(param_1[2] >> 10 & 3));
        if (bVar1) {
          uVar8 = *in_stack_00000038 | 6;
LAB_97bf68e0:
          *in_stack_00000038 = uVar8;
LAB_97bf68e4:
          if (bVar1) {
            iVar11 = 0;
            do {
              iVar5 = 0;
              cVar3 = s_MOV_97c2e430[0];
              while (cVar3 != '\0') {
                *(char *)(iVar6 + iVar5) = cVar3;
                cVar3 = "MOV "[iVar5 + 1];
                iVar5 = iVar5 + 1;
              }
              iVar13 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,iVar11,0,0);
              iVar5 = 0;
              cVar3 = s___scratch_97c2e65c[0];
              while (cVar3 != '\0') {
                *(char *)(iVar13 + iVar5) = cVar3;
                cVar3 = ", scratch"[iVar5 + 1];
                iVar5 = iVar5 + 1;
              }
              iVar11 = iVar11 + 1;
              iVar6 = _ncpy(iVar13 + iVar5,iVar11);
              iVar6 = iVar13 + iVar5 + iVar6;
              iVar5 = 0;
              cVar3 = s___97c2d8f8[0];
              while (cVar3 != '\0') {
                *(char *)(iVar6 + iVar5) = cVar3;
                cVar3 = ";\n"[iVar5 + 1];
                iVar5 = iVar5 + 1;
              }
              iVar6 = iVar6 + iVar5;
            } while (iVar11 <= (int)(param_1[2] >> 10 & 3));
          }
        }
      }
      else if (uVar8 == 2) {
        iVar11 = 0;
        do {
          iVar5 = 0;
          cVar3 = s_MUL_scratch__97c2e62c[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = "MUL scratch, "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar6 + iVar5,param_5,param_6,2,0,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,0,iVar11,2);
          iVar6 = 0;
          cVar3 = s___97c2d8f8[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ";\n"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar13 = 0;
          cVar3 = s_MAD_scratch__97c2e64c[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6 + iVar13) = cVar3;
            cVar3 = "MAD scratch, "[iVar13 + 1];
            iVar13 = iVar13 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6 + iVar13,param_5,param_6,2,1,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,1,iVar11,2);
          iVar6 = 0;
          cVar3 = s___scratch__97c2e620[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", scratch;\n"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar13 = 0;
          cVar3 = s_MAD_97c2e644[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6 + iVar13) = cVar3;
            cVar3 = "MAD "[iVar13 + 1];
            iVar13 = iVar13 + 1;
          }
          iVar13 = iVar5 + iVar6 + iVar13;
          if (!bVar1) {
            iVar6 = _glpWriteDestinationOperand(param_1,iVar13,iVar11,0,0);
          }
          else {
            iVar5 = 0;
            cVar3 = s_scratch_97c2e63c[0];
            while (cVar3 != '\0') {
              *(char *)(iVar13 + iVar5) = cVar3;
              cVar3 = "scratch"[iVar5 + 1];
              iVar5 = iVar5 + 1;
            }
            iVar6 = _ncpy(iVar13 + iVar5,iVar11 + 1);
            iVar6 = iVar13 + iVar5 + iVar6;
          }
          iVar13 = iVar11 + 1;
          iVar5 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = ", "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar6 + iVar5,param_5,param_6,2,2,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,2,iVar11,2);
          iVar11 = 0;
          cVar3 = s___scratch__97c2e620[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar11) = cVar3;
            cVar3 = ", scratch;\n"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          iVar6 = iVar6 + iVar11;
          iVar11 = iVar13;
        } while (iVar13 <= (int)(param_1[2] >> 10 & 3));
        if (bVar1) {
          uVar8 = *in_stack_00000038 | 0xe;
          goto LAB_97bf68e0;
        }
      }
      else {
        if (uVar8 != 3) goto LAB_97bf68e4;
        iVar11 = 0;
        do {
          iVar5 = 0;
          cVar3 = s_MUL_scratch__97c2e62c[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = "MUL scratch, "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar6 + iVar5,param_5,param_6,2,0,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,0,iVar11,2);
          iVar6 = 0;
          cVar3 = s___97c2d8f8[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ";\n"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar13 = 0;
          cVar3 = s_MAD_scratch__97c2e64c[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6 + iVar13) = cVar3;
            cVar3 = "MAD scratch, "[iVar13 + 1];
            iVar13 = iVar13 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6 + iVar13,param_5,param_6,2,1,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,1,iVar11,2);
          iVar6 = 0;
          cVar3 = s___scratch__97c2e620[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", scratch;\n"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar13 = 0;
          cVar3 = s_MAD_scratch__97c2e64c[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6 + iVar13) = cVar3;
            cVar3 = "MAD scratch, "[iVar13 + 1];
            iVar13 = iVar13 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6 + iVar13,param_5,param_6,2,2,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,2,iVar11,2);
          iVar6 = 0;
          cVar3 = s___scratch__97c2e620[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", scratch;\n"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar13 = 0;
          cVar3 = s_MAD_97c2e644[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6 + iVar13) = cVar3;
            cVar3 = "MAD "[iVar13 + 1];
            iVar13 = iVar13 + 1;
          }
          iVar13 = iVar5 + iVar6 + iVar13;
          if (!bVar1) {
            iVar6 = _glpWriteDestinationOperand(param_1,iVar13,iVar11,0,0);
          }
          else {
            iVar5 = 0;
            cVar3 = s_scratch_97c2e63c[0];
            while (cVar3 != '\0') {
              *(char *)(iVar13 + iVar5) = cVar3;
              cVar3 = "scratch"[iVar5 + 1];
              iVar5 = iVar5 + 1;
            }
            iVar6 = _ncpy(iVar13 + iVar5,iVar11 + 1);
            iVar6 = iVar13 + iVar5 + iVar6;
          }
          iVar13 = iVar11 + 1;
          iVar5 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = ", "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar5 = _glpWriteSourceOperand(param_1,iVar6 + iVar5,param_5,param_6,2,3,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,3,iVar11,2);
          iVar11 = 0;
          cVar3 = s___scratch__97c2e620[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar11) = cVar3;
            cVar3 = ", scratch;\n"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          iVar6 = iVar6 + iVar11;
          iVar11 = iVar13;
        } while (iVar13 <= (int)(param_1[2] >> 10 & 3));
        if (bVar1) {
          uVar8 = *in_stack_00000038 | 0x1e;
          goto LAB_97bf68e0;
        }
      }
    }
    goto LAB_97c01788;
  case 0x23:
    bVar1 = false;
    if ((*(short *)((int)param_1 + 0xe) == *(short *)((int)param_1 + 0x16)) ||
       (*(short *)((int)param_1 + 0xe) == *(short *)((int)param_1 + 0x1e))) {
      bVar1 = true;
    }
    iVar11 = 0;
    do {
      iVar5 = 0;
      cVar3 = s_MUL_97c2e4f0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar5) = cVar3;
        cVar3 = "MUL "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = iVar6 + iVar5;
      if (!bVar1) {
        iVar6 = _glpWriteDestinationOperand(param_1,iVar6,iVar11,0,0);
      }
      else {
        iVar5 = 0;
        cVar3 = s_scratch_97c2e63c[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = "scratch"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar6 = iVar6 + iVar5;
        if (iVar11 != 0) {
          iVar5 = _ncpy(iVar6,iVar11);
          iVar6 = iVar6 + iVar5;
        }
      }
      iVar5 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar5) = cVar3;
        cVar3 = ", "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = _glpWriteSourceOperand(param_1,iVar6 + iVar5,param_5,param_6,2,iVar11,0,0);
      iVar6 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar6) = cVar3;
        cVar3 = ", "[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,3,iVar11,0,0);
      iVar5 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar5) = cVar3;
        cVar3 = ";\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar11 = iVar11 + 1;
      iVar6 = iVar6 + iVar5;
      uVar8 = param_1[2] >> 10 & 3;
    } while (iVar11 <= (int)uVar8);
    if (bVar1) {
      if (uVar8 == 1) {
        uVar8 = *in_stack_00000038 | 3;
LAB_97bf7aec:
        *in_stack_00000038 = uVar8;
      }
      else {
        if (uVar8 == 2) {
          uVar8 = *in_stack_00000038 | 7;
          goto LAB_97bf7aec;
        }
        if (uVar8 == 3) {
          uVar8 = *in_stack_00000038 | 0xf;
          goto LAB_97bf7aec;
        }
      }
      iVar11 = 0;
      do {
        iVar5 = 0;
        cVar3 = s_MOV_97c2e430[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = "MOV "[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,iVar11,0,0);
        iVar5 = 0;
        cVar3 = s___scratch_97c2e65c[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = ", scratch"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar6 = iVar6 + iVar5;
        if (iVar11 != 0) {
          iVar5 = _ncpy(iVar6,iVar11);
          iVar6 = iVar6 + iVar5;
        }
        iVar5 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = ";\n"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar11 = iVar11 + 1;
        iVar6 = iVar6 + iVar5;
      } while (iVar11 <= (int)(param_1[2] >> 10 & 3));
    }
    goto LAB_97c01788;
  case 0x24:
    iVar11 = 0;
    cVar3 = s_MUL_97c2e4f0[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "MUL "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x25:
    *in_stack_00000038 = *in_stack_00000038 | 0x2001;
    iVar11 = 0;
    cVar3 = s_ADD_scratch_x__97c2e960[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "ADD scratch.x, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_SGE_97c2e91c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "SGE "[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch_x__kHALF__97c2e970[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch.x, kHALF;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x26:
    *in_stack_00000038 = *in_stack_00000038 | 1;
    iVar11 = 0;
    cVar3 = s_SUB_scratch_x__97c2e988[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "SUB scratch.x, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_ABS_97c2e998[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "ABS "[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch_x__97c2e594[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch.x;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x27:
    uVar8 = param_1[4];
    if (((uVar8 >> 0xc & 3) == 1) &&
       (((in_stack_00000038[1] & 0x800000) == 0 || (in_stack_0000003c != 0x8b30)))) {
      iVar11 = 0;
      cVar3 = s_MUL_scratch_xy__97c2e510[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "MUL scratch.xy, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MUL_97c2e4f0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "MUL "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch_x__scratch_y__97c2e524[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch.x, scratch.y;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      if ((uVar8 >> 0xc & 3) == 1) {
        *in_stack_00000038 = *in_stack_00000038 | 0x800000;
        uVar8 = param_1[4];
      }
      uVar8 = uVar8 >> 0xc & 3;
      if (uVar8 == 0) {
        iVar11 = 0;
        cVar3 = s_MUL_97c2e4f0[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "MUL "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else if (uVar8 == 1) {
        iVar11 = 0;
        cVar3 = s_DP2_97c2e540[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "DP2 "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else if (uVar8 == 2) {
        iVar11 = 0;
        cVar3 = s_DP3_97c2e548[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "DP3 "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else {
        iVar11 = 0;
        cVar3 = s_DP4_97c2e550[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "DP4 "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 0x2b:
    *in_stack_00000038 = *in_stack_00000038 | 1;
    iVar11 = 0;
    cVar3 = s_ADD_scratch__97c2e7e0[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "ADD scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,1);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = iVar6 + iVar11;
    uVar8 = param_1[4] >> 0xc & 3;
    if (uVar8 == 1) {
      iVar11 = 0;
      cVar3 = s_SWZ_scratch__scratch__x__y__0__0_97c2e7f0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = "SWZ scratch, scratch, x, y, 0, 0;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = iVar6 + iVar11;
      iVar11 = 0;
      cVar3 = s_DP3_scratch_x__scratch__scratch__97c2e7bc[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = "DP3 scratch.x, scratch, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else if (uVar8 == 0) {
      iVar11 = 0;
      cVar3 = s_MUL_scratch_x__scratch_x__scratc_97c2e814[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = "MUL scratch.x, scratch.x, scratch.x;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else if (uVar8 == 2) {
      iVar11 = 0;
      cVar3 = s_DP3_scratch_x__scratch__scratch__97c2e7bc[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = "DP3 scratch.x, scratch, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      iVar11 = 0;
      cVar3 = s_DP4_scratch_x__scratch__scratch__97c2e83c[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = "DP4 scratch.x, scratch, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    iVar5 = 0;
    cVar3 = s_RSQ_scratch_x__scratch_x__97c2e754[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "RSQ scratch.x, scratch.x;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_RCP_97c2e58c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "RCP "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch_x__97c2e594[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch.x;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x2c:
  case 0x2d:
    iVar6 = 0;
    pcVar4 = *(char **)(PTR__ppstreamOpString_a7b7c108 + iVar11);
    cVar3 = *pcVar4;
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar6) = cVar3;
      iVar6 = iVar6 + 1;
      cVar3 = pcVar4[iVar6];
    }
    iVar11 = 0;
    cVar3 = s__97c291c0[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar6 + iVar11) = cVar3;
      cVar3 = " "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar6 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x2e:
  case 0x32:
  case 0x35:
    iVar6 = 0;
    pcVar4 = *(char **)(PTR__ppstreamOpString_a7b7c108 + iVar11);
    cVar3 = *pcVar4;
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar6) = cVar3;
      iVar6 = iVar6 + 1;
      cVar3 = pcVar4[iVar6];
    }
    iVar11 = 0;
    cVar3 = s__97c291c0[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar6 + iVar11) = cVar3;
      cVar3 = " "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar6 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x2f:
    *in_stack_00000038 = *in_stack_00000038 | 1;
    if ((param_1[2] >> 10 & 3) == 2) {
      iVar11 = 0;
      cVar3 = s_DP3_scratch_x__97c2e734[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "DP3 scratch.x, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      iVar11 = 0;
      cVar3 = s_DP4_scratch_x__97c2e744[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "DP4 scratch.x, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MUL_scratch__97c2e62c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "MUL scratch, "[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11 + iVar5,param_5,param_6,3,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch_x__97c2e594[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch.x;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_ADD_scratch__scratch__scratch__97c2e770[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "ADD scratch, scratch, scratch;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_ADD_97c2e6d4[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "ADD "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s____scratch_97c2e790[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", -scratch"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = ((int (*)())_glpWriteComponentsWithDestinationSwizzle)(param_1,iVar6 + iVar11);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x31:
    if (((param_1[4] & 0x4000) == 0) && ((param_1[6] & 0x4000) == 0)) {
      if ((((in_stack_00000038[1] & 0x100000) == 0) || (in_stack_0000003c != 0x8b31)) &&
         (((in_stack_00000038[1] & 0x400000) == 0 || (in_stack_0000003c != 0x8b30)))) {
        *in_stack_00000038 = *in_stack_00000038 | 0x1001;
        iVar11 = 0;
        cVar3 = s_SUB_scratch__97c2e870[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "SUB scratch, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,8);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar5 = 0;
        cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
          cVar3 = "ABS scratch, scratch;\n"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar5 = iVar6 + iVar11 + iVar5;
        iVar11 = 0;
        cVar3 = s_SGE_97c2e91c[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar11) = cVar3;
          cVar3 = "SGE "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
        iVar11 = 0;
        cVar3 = s____scratch__kZERO__97c2e460[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", -scratch, kZERO;\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else {
        if (in_stack_0000003c == 0x8b31) {
          uVar8 = *in_stack_00000038 | 0x100000;
        }
        else {
          uVar8 = *in_stack_00000038 | 0x400000;
        }
        *in_stack_00000038 = uVar8;
        iVar11 = 0;
        cVar3 = s_SEQ_97c2e924[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "SEQ "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,8);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
    }
    else {
      *in_stack_00000038 = *in_stack_00000038 | 3;
      uVar8 = param_1[4];
      if ((uVar8 & 0x4000) == 0) {
        uVar8 = param_1[6];
      }
      uVar8 = uVar8 >> 0xc & 3;
      iVar6 = 0;
      iVar11 = param_2;
      do {
        bVar1 = iVar6 == 0;
        if (bVar1) {
          iVar5 = 0;
          cVar3 = s_SUB_scratch__97c2e870[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = "SUB scratch, "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        else {
          iVar5 = 0;
          cVar3 = s_SUB_scratch1__97c2e860[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = "SUB scratch1, "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        iVar13 = iVar6;
        if ((param_1[4] & 0x4000) == 0) {
          iVar13 = 0;
        }
        iVar5 = _glpWriteSourceOperand(param_1,iVar11 + iVar5,param_5,param_6,2,iVar13,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar13 = iVar6;
        if ((param_1[6] & 0x4000) == 0) {
          iVar13 = 0;
        }
        iVar11 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,3,iVar13,0,0);
        iVar5 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar11 + iVar5) = cVar3;
          cVar3 = ";\n"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar11 = iVar11 + iVar5;
        if (bVar1) {
          iVar5 = 0;
          cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = "ABS scratch, scratch;\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        else {
          iVar5 = 0;
          cVar3 = s_ABS_scratch1__scratch1__97c2e880[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = "ABS scratch1, scratch1;\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        iVar11 = iVar11 + iVar5;
        if (!bVar1) {
          iVar5 = 0;
          cVar3 = s_ADD_scratch__scratch__scratch1__97c2e89c[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = "ADD scratch, scratch, scratch1;\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar11 = iVar11 + iVar5;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 <= (int)uVar8);
      iVar6 = 0;
      cVar3 = s_DP4_scratch__scratch__97c2e8d8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar11 + iVar6) = cVar3;
        cVar3 = "DP4 scratch, scratch, "[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar11 = iVar11 + iVar6;
      if (uVar8 == 1) {
        *in_stack_00000038 = *in_stack_00000038 | 0x1000;
        iVar6 = 0;
        cVar3 = s_kVEC2_97c2e8f0[0];
        while (cVar3 != '\0') {
          *(char *)(iVar11 + iVar6) = cVar3;
          cVar3 = "kVEC2"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
LAB_97bf9b6c:
        iVar11 = iVar11 + iVar6;
      }
      else {
        if (uVar8 == 2) {
          *in_stack_00000038 = *in_stack_00000038 | 0x1000;
          iVar6 = 0;
          cVar3 = s_kVEC3_97c2e8f8[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar6) = cVar3;
            cVar3 = "kVEC3"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          goto LAB_97bf9b6c;
        }
        if (uVar8 == 3) {
          *in_stack_00000038 = *in_stack_00000038 | 0x1000;
          iVar6 = 0;
          cVar3 = s_kVEC4_97c2e900[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar6) = cVar3;
            cVar3 = "kVEC4"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          goto LAB_97bf9b6c;
        }
      }
      iVar6 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar11 + iVar6) = cVar3;
        cVar3 = ";\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar5 = 0;
      cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar11 + iVar6 + iVar5) = cVar3;
        cVar3 = "ABS scratch, scratch;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar11 + iVar6 + iVar5;
      iVar11 = 0;
      cVar3 = s_SGE_97c2e91c[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "SGE "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s____scratch__kZERO__97c2e460[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", -scratch, kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 0x33:
    iVar11 = 0;
    cVar3 = s_SLT_97c2e458[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "SLT "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,1);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,1);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x34:
    iVar11 = 0;
    cVar3 = s_SGE_97c2e91c[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "SGE "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,1);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,1);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x36:
    if (((param_1[4] & 0x4000) == 0) && ((param_1[6] & 0x4000) == 0)) {
      if ((((in_stack_00000038[1] & 0x100000) == 0) || (in_stack_0000003c != 0x8b31)) &&
         (((in_stack_00000038[1] & 0x400000) == 0 || (in_stack_0000003c != 0x8b30)))) {
        *in_stack_00000038 = *in_stack_00000038 | 0x1001;
        iVar11 = 0;
        cVar3 = s_SUB_scratch__97c2e870[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "SUB scratch, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar5 = 0;
        cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
          cVar3 = "ABS scratch, scratch;\n"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar5 = iVar6 + iVar11 + iVar5;
        iVar11 = 0;
        cVar3 = s_SLT_97c2e458[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar11) = cVar3;
          cVar3 = "SLT "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
        iVar11 = 0;
        cVar3 = s____scratch__kZERO__97c2e460[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", -scratch, kZERO;\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else {
        if (in_stack_0000003c == 0x8b31) {
          uVar8 = *in_stack_00000038 | 0x100000;
        }
        else {
          uVar8 = *in_stack_00000038 | 0x400000;
        }
        *in_stack_00000038 = uVar8;
        iVar11 = 0;
        cVar3 = s_SNE_97c2e908[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "SNE "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,8);
        iVar11 = 0;
        cVar3 = s_____end_97c2e910[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n# end\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
    }
    else {
      *in_stack_00000038 = *in_stack_00000038 | 3;
      uVar8 = param_1[4];
      if ((uVar8 & 0x4000) == 0) {
        uVar8 = param_1[6];
      }
      uVar8 = uVar8 >> 0xc & 3;
      iVar6 = 0;
      iVar11 = param_2;
      do {
        bVar1 = iVar6 == 0;
        if (bVar1) {
          iVar5 = 0;
          cVar3 = s_SUB_scratch__97c2e870[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = "SUB scratch, "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        else {
          iVar5 = 0;
          cVar3 = s_SUB_scratch1__97c2e860[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = "SUB scratch1, "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        iVar13 = iVar6;
        if ((param_1[4] & 0x4000) == 0) {
          iVar13 = 0;
        }
        iVar5 = _glpWriteSourceOperand(param_1,iVar11 + iVar5,param_5,param_6,2,iVar13,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar13 = iVar6;
        if ((param_1[6] & 0x4000) == 0) {
          iVar13 = 0;
        }
        iVar11 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,3,iVar13,0,0);
        iVar5 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar11 + iVar5) = cVar3;
          cVar3 = ";\n"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar11 = iVar11 + iVar5;
        if (bVar1) {
          iVar5 = 0;
          cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = "ABS scratch, scratch;\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        else {
          iVar5 = 0;
          cVar3 = s_ABS_scratch1__scratch1__97c2e880[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = "ABS scratch1, scratch1;\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
        }
        iVar11 = iVar11 + iVar5;
        if (!bVar1) {
          iVar5 = 0;
          cVar3 = s_ADD_scratch__scratch__scratch1__97c2e89c[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar5) = cVar3;
            cVar3 = "ADD scratch, scratch, scratch1;\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar11 = iVar11 + iVar5;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 <= (int)uVar8);
      iVar6 = 0;
      cVar3 = s_DP4_scratch__scratch__97c2e8d8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar11 + iVar6) = cVar3;
        cVar3 = "DP4 scratch, scratch, "[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar11 = iVar11 + iVar6;
      if (uVar8 == 1) {
        *in_stack_00000038 = *in_stack_00000038 | 0x1000;
        iVar6 = 0;
        cVar3 = s_kVEC2_97c2e8f0[0];
        while (cVar3 != '\0') {
          *(char *)(iVar11 + iVar6) = cVar3;
          cVar3 = "kVEC2"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
LAB_97bf9370:
        iVar11 = iVar11 + iVar6;
      }
      else {
        if (uVar8 == 2) {
          *in_stack_00000038 = *in_stack_00000038 | 0x1000;
          iVar6 = 0;
          cVar3 = s_kVEC3_97c2e8f8[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar6) = cVar3;
            cVar3 = "kVEC3"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          goto LAB_97bf9370;
        }
        if (uVar8 == 3) {
          *in_stack_00000038 = *in_stack_00000038 | 0x1000;
          iVar6 = 0;
          cVar3 = s_kVEC4_97c2e900[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar6) = cVar3;
            cVar3 = "kVEC4"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          goto LAB_97bf9370;
        }
      }
      iVar6 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar11 + iVar6) = cVar3;
        cVar3 = ";\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar5 = 0;
      cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar11 + iVar6 + iVar5) = cVar3;
        cVar3 = "ABS scratch, scratch;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar11 + iVar6 + iVar5;
      iVar11 = 0;
      cVar3 = s_SLT_97c2e458[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "SLT "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s____scratch__kZERO__97c2e460[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", -scratch, kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 0x38:
    uVar8 = param_1[2];
    uVar9 = uVar8 >> 0xd & 0xf;
    iVar5 = 0;
    do {
      if ((uVar9 & 1) != 0) {
        pcVar4 = *(char **)(puVar2 + iVar11);
        iVar13 = 0;
        cVar3 = *pcVar4;
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar13) = cVar3;
          iVar13 = iVar13 + 1;
          cVar3 = pcVar4[iVar13];
        }
        iVar12 = 0;
        cVar3 = s__97c291c0[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar13 + iVar12) = cVar3;
          cVar3 = " "[iVar12 + 1];
          iVar12 = iVar12 + 1;
        }
        iVar13 = _glpWriteDestinationOperand(param_1,iVar6 + iVar13 + iVar12,0,iVar5,2);
        iVar6 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar13 + iVar6) = cVar3;
          cVar3 = ", "[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar13 = _glpWriteSourceOperand(param_1,iVar13 + iVar6,param_5,param_6,2,0,iVar5,10);
        iVar6 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar13 + iVar6) = cVar3;
          cVar3 = ", "[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar13 + iVar6,param_5,param_6,3,0,iVar5,10);
        iVar13 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar13) = cVar3;
          cVar3 = ";\n"[iVar13 + 1];
          iVar13 = iVar13 + 1;
        }
        uVar8 = param_1[2];
        iVar6 = iVar6 + iVar13;
      }
      iVar5 = iVar5 + 1;
      uVar9 = (int)uVar9 >> 1;
    } while (iVar5 <= (int)(uVar8 >> 10 & 3));
    goto LAB_97c01788;
  case 0x39:
    *in_stack_00000038 = *in_stack_00000038 | 0x1001;
    iVar11 = 0;
    cVar3 = s_SUB_scratch__kSEL__97c2f620[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "SUB scratch, kSEL, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,3,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "ABS scratch, scratch;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_SGE_scratch___scratch__kZERO__97c2f634[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "SGE scratch, -scratch, kZERO;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_DP4_97c2e550[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "DP4 "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch__97c2e570[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x3a:
    *in_stack_00000038 = *in_stack_00000038 | 1;
    if (((param_1[4] & 0x4000) == 0) || ((param_1[6] & 0x4000) == 0)) {
      if ((param_1[4] & 0x4000) == 0) {
        if ((param_1[6] & 0x4000) == 0) {
          if ((param_1[6] & 0x3000) == 0) {
            iVar11 = 0;
            cVar3 = s_RCP_scratch__97c2e600[0];
            while (cVar3 != '\0') {
              *(char *)(param_2 + iVar11) = cVar3;
              cVar3 = "RCP scratch, "[iVar11 + 1];
              iVar11 = iVar11 + 1;
            }
            iVar11 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,3,0,0,0);
            iVar6 = 0;
            cVar3 = s___97c2d8f8[0];
            while (cVar3 != '\0') {
              *(char *)(iVar11 + iVar6) = cVar3;
              cVar3 = ";\n"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            iVar11 = iVar11 + iVar6;
          }
          else {
            uVar8 = param_1[2];
            uVar9 = uVar8 >> 0xd & 0xf;
            iVar6 = 0;
            iVar11 = param_2;
            do {
              if ((uVar9 & 1) != 0) {
                iVar5 = 0;
                cVar3 = s_RCP_scratch__97c2e5f0[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar11 + iVar5) = cVar3;
                  cVar3 = "RCP scratch."[iVar5 + 1];
                  iVar5 = iVar5 + 1;
                }
                pcVar4 = (char *)(iVar11 + iVar5);
                *pcVar4 = ((char)iVar6 + 1U & 3) + 0x77;
                iVar11 = 0;
                cVar3 = s___97c2d7ec[0];
                while (cVar3 != '\0') {
                  pcVar4[iVar11 + 1] = cVar3;
                  cVar3 = ", "[iVar11 + 1];
                  iVar11 = iVar11 + 1;
                }
                iVar11 = _glpWriteSourceOperand
                                   (param_1,pcVar4 + iVar11 + 1,param_5,param_6,3,0,iVar6,10);
                iVar5 = 0;
                cVar3 = s___97c2d8f8[0];
                while (cVar3 != '\0') {
                  *(char *)(iVar11 + iVar5) = cVar3;
                  cVar3 = ";\n"[iVar5 + 1];
                  iVar5 = iVar5 + 1;
                }
                uVar8 = param_1[2];
                iVar11 = iVar11 + iVar5;
              }
              iVar6 = iVar6 + 1;
              uVar9 = (int)uVar9 >> 1;
            } while (iVar6 <= (int)(uVar8 >> 10 & 3));
          }
          iVar6 = 0;
          cVar3 = s_MUL_97c2e4f0[0];
          while (cVar3 != '\0') {
            *(char *)(iVar11 + iVar6) = cVar3;
            cVar3 = "MUL "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar6 = _glpWriteDestinationOperand(param_1,iVar11 + iVar6,0,0,0);
          iVar11 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar11) = cVar3;
            cVar3 = ", "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
          iVar11 = 0;
          cVar3 = s___scratch__97c2e620[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar11) = cVar3;
            cVar3 = ", scratch;\n"[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          break;
        }
        iVar11 = 0;
        do {
          iVar5 = 0;
          do {
            iVar13 = 0;
            cVar3 = s_RCP_scratch__97c2e5f0[0];
            while (cVar3 != '\0') {
              *(char *)(iVar6 + iVar13) = cVar3;
              cVar3 = "RCP scratch."[iVar13 + 1];
              iVar13 = iVar13 + 1;
            }
            iVar12 = iVar5 + 1;
            pcVar4 = (char *)(iVar6 + iVar13);
            *pcVar4 = ((byte)iVar12 & 3) + 0x77;
            iVar6 = 0;
            cVar3 = s___97c2d7ec[0];
            while (cVar3 != '\0') {
              pcVar4[iVar6 + 1] = cVar3;
              cVar3 = ", "[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            iVar6 = _glpWriteSourceOperand
                              (param_1,pcVar4 + iVar6 + 1,param_5,param_6,3,iVar11,iVar5,2);
            iVar5 = 0;
            cVar3 = s___97c2d8f8[0];
            while (cVar3 != '\0') {
              *(char *)(iVar6 + iVar5) = cVar3;
              cVar3 = ";\n"[iVar5 + 1];
              iVar5 = iVar5 + 1;
            }
            iVar6 = iVar6 + iVar5;
            iVar5 = iVar12;
          } while (iVar12 <= (int)(param_1[6] >> 0xc & 3));
          iVar5 = 0;
          cVar3 = s_MUL_97c2e4f0[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = "MUL "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar5 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,iVar11,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,2,0,0,0);
          iVar5 = 0;
          cVar3 = s___scratch__97c2e5e0[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = ", scratch; \n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar11 = iVar11 + 1;
          iVar6 = iVar6 + iVar5;
        } while (iVar11 <= (int)(param_1[6] >> 0xc & 3));
      }
      else {
        iVar11 = 0;
        cVar3 = s_RCP_scratch__97c2e600[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "RCP scratch, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,3,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = iVar6 + iVar11;
        iVar11 = 0;
        do {
          iVar5 = 0;
          cVar3 = s_MUL_97c2e4f0[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = "MUL "[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar5 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,iVar11,0,0);
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            *(char *)(iVar5 + iVar6) = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,2,iVar11,0,0);
          iVar5 = 0;
          cVar3 = s___scratch_x__97c2e610[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = ", scratch.x; \n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar11 = iVar11 + 1;
          iVar6 = iVar6 + iVar5;
        } while (iVar11 <= (int)(param_1[2] >> 10 & 3));
      }
    }
    else {
      iVar11 = 0;
      do {
        iVar5 = 0;
        do {
          iVar13 = 0;
          cVar3 = s_RCP_scratch__97c2e5f0[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar13) = cVar3;
            cVar3 = "RCP scratch."[iVar13 + 1];
            iVar13 = iVar13 + 1;
          }
          iVar12 = iVar5 + 1;
          pcVar4 = (char *)(iVar6 + iVar13);
          *pcVar4 = ((byte)iVar12 & 3) + 0x77;
          iVar6 = 0;
          cVar3 = s___97c2d7ec[0];
          while (cVar3 != '\0') {
            pcVar4[iVar6 + 1] = cVar3;
            cVar3 = ", "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          iVar6 = _glpWriteSourceOperand
                            (param_1,pcVar4 + iVar6 + 1,param_5,param_6,3,iVar11,iVar5,2);
          iVar5 = 0;
          cVar3 = s___97c2d8f8[0];
          while (cVar3 != '\0') {
            *(char *)(iVar6 + iVar5) = cVar3;
            cVar3 = ";\n"[iVar5 + 1];
            iVar5 = iVar5 + 1;
          }
          iVar6 = iVar6 + iVar5;
          iVar5 = iVar12;
        } while (iVar12 <= (int)(param_1[6] >> 0xc & 3));
        iVar5 = 0;
        cVar3 = s_MUL_97c2e4f0[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = "MUL "[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar5 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,iVar11,0,0);
        iVar6 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar6) = cVar3;
          cVar3 = ", "[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,2,iVar11,0,0);
        iVar5 = 0;
        cVar3 = s___scratch__97c2e5e0[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = ", scratch; \n"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar11 = iVar11 + 1;
        iVar6 = iVar6 + iVar5;
      } while (iVar11 <= (int)(param_1[6] >> 0xc & 3));
    }
    goto LAB_97c01788;
  case 0x3b:
    *in_stack_00000038 = *in_stack_00000038 | 0x1001;
    uVar8 = param_1[8] >> 0xc & 3;
    if (uVar8 == 1) {
      iVar11 = 0;
      cVar3 = s_SWZ_scratch__97c2e79c[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "SWZ scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = ((int (*)())_glpSourceType)(param_1,param_2 + iVar11,param_5,param_6,4,0,0);
      iVar11 = 0;
      cVar3 = s___x__y__0__0__97c2e7ac[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", x, y, 0, 0;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_DP3_scratch_x__scratch__97c2ea1c[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "DP3 scratch.x, scratch, "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11 + iVar5,param_5,param_6,3,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      if (uVar8 == 0) {
        iVar11 = 0;
        cVar3 = s_MUL_scratch_x__97c2e6fc[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "MUL scratch.x, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else if (uVar8 == 2) {
        iVar11 = 0;
        cVar3 = s_DP3_scratch_x__97c2e734[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "DP3 scratch.x, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else {
        iVar11 = 0;
        cVar3 = s_DP4_scratch_x__97c2e744[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "DP4 scratch.x, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,4,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    iVar5 = 0;
    cVar3 = s_SLT_scratch__scratch_x__kZERO__97c2ea38[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "SLT scratch, scratch.x, kZERO;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_MAD_scratch__scratch__kTWO___kON_97c2ea58[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MAD scratch, scratch, kTWO, -kONE;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_MUL_97c2e4f0[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MUL "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch__97c2e570[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x3c:
    if (in_stack_0000003c == 0x8b30) {
      iVar11 = 0;
      cVar3 = s_LRP_97c2e9e4[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "LRP "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,4,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      *in_stack_00000038 = *in_stack_00000038 | 1;
      iVar11 = 0;
      cVar3 = s_MAD_scratch__97c2e64c[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "MAD scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,4,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,9);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,4,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MAD_97c2e644[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "MAD "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___scratch__97c2e620[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 0x3d:
    *in_stack_00000038 = *in_stack_00000038 | 1;
    iVar11 = 0;
    cVar3 = s_MAX_scratch__97c2e558[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "MAX scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MIN_97c2e568[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "MIN "[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch__97c2e570[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,4,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x3e:
    if (in_stack_0000003c == 0x8b30) {
      iVar11 = 0;
      cVar3 = s_CMP_97c2f81c[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "CMP "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,4,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      *in_stack_00000038 = *in_stack_00000038 | 0x1001;
      iVar11 = 0;
      cVar3 = s_SLT_scratch__97c2e474[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "SLT scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
      iVar11 = 0;
      cVar3 = s___kZERO__97c2e484[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = iVar6 + iVar11;
      if (in_stack_0000003c == 0x8b30) {
        iVar11 = 0;
        cVar3 = s_LRP_97c2e9e4[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = "LRP "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11,0,0,0);
        iVar11 = 0;
        cVar3 = s___scratch__97c2e570[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", scratch, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d7ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,4,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else {
        *in_stack_00000038 = *in_stack_00000038 | 0x1002;
        iVar11 = 0;
        cVar3 = s_SUB_scratch1__kONE__scratch__97c2f668[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = "SUB scratch1, kONE, scratch;\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar5 = 0;
        cVar3 = s_MUL_scratch__scratch__97c2e9ec[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
          cVar3 = "MUL scratch, scratch, "[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11 + iVar5,param_5,param_6,3,0,0,0);
        iVar11 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ";\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar5 = 0;
        cVar3 = s_MAD_97c2e644[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
          cVar3 = "MAD "[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
        iVar11 = 0;
        cVar3 = s___scratch1__97c2f688[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", scratch1, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,4,0,0,0);
        iVar11 = 0;
        cVar3 = s___scratch__97c2e620[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar11) = cVar3;
          cVar3 = ", scratch;\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
    }
    break;
  case 0x40:
    *in_stack_00000038 = *in_stack_00000038 | 0x1003;
    iVar11 = 0;
    cVar3 = s_SUB_scratch__97c2e870[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "SUB scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,3,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    pcVar4 = (char *)(iVar6 + iVar11);
    if ((param_1[8] >> 0xc & 3) == 0) {
      iVar11 = 0;
      cVar3 = s_RCP_scratch1_x__scratch_x__97c2ea7c[0];
      while (cVar3 != '\0') {
        pcVar4[iVar11] = cVar3;
        cVar3 = "RCP scratch1.x, scratch.x;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      pcVar4 = pcVar4 + iVar11;
    }
    else {
      iVar11 = 0;
      do {
        iVar6 = 0;
        cVar3 = s_RCP_scratch1__97c2ea98[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6] = cVar3;
          cVar3 = "RCP scratch1."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar11 = iVar11 + 1;
        pcVar4 = pcVar4 + iVar6;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___scratch__97c2eaa8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ", scratch."[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
        *pcVar4 = ((byte)iVar11 & 3) + 0x77;
        iVar6 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          pcVar4[iVar6 + 1] = cVar3;
          cVar3 = ";\n"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        pcVar4 = pcVar4 + iVar6 + 1;
      } while (iVar11 <= (int)(param_1[8] >> 0xc & 3));
    }
    iVar11 = 0;
    cVar3 = s_SUB_scratch__97c2e870[0];
    while (cVar3 != '\0') {
      pcVar4[iVar11] = cVar3;
      cVar3 = "SUB scratch, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,pcVar4 + iVar11,param_5,param_6,4,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MUL_scratch__scratch__scratch1__97c2eab4[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "MUL scratch, scratch, scratch1;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_MAX_scratch__scratch__kZERO__97c2ead8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MAX scratch, scratch, kZERO;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_MIN_scratch__scratch__kONE__97c2eaf8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MIN scratch, scratch, kONE;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_ADD_scratch1__scratch__scratch__97c2eb18[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "ADD scratch1, scratch, scratch;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_SUB_scratch1__kTHREE__scratch1__97c2eb3c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "SUB scratch1, kTHREE, scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_MUL_scratch__scratch__scratch__97c2eb60[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MUL scratch, scratch, scratch;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_MUL_97c2e4f0[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MUL "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch__scratch1__97c2e4f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch, scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x42:
  case 0x43:
  case 0x44:
    if (in_stack_0000003c == 0x8b30) {
      uVar8 = in_stack_00000038[1];
    }
    else {
      uVar8 = in_stack_00000038[1];
      if ((uVar8 & 0x200000) == 0) {
        return 0xffffffff;
      }
      if (in_stack_0000003c != 0x8b31) {
        return 0xffffffff;
      }
    }
    if (((uVar8 & 0x400000) == 0) || (in_stack_0000003c != 0x8b30)) {
      if ((param_1[8] >> 5 & 7) - 5 < 3) {
        return 0xffffffff;
      }
    }
    else {
      *in_stack_00000038 = *in_stack_00000038 | 0x1000000;
    }
    if (in_stack_0000003c == 0x8b31) {
      *in_stack_00000038 = *in_stack_00000038 | 0x200000;
    }
    iVar6 = 0;
    pcVar4 = *(char **)(PTR__ppstreamOpString_a7b7c108 + iVar11);
    cVar3 = *pcVar4;
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar6) = cVar3;
      iVar6 = iVar6 + 1;
      cVar3 = pcVar4[iVar6];
    }
    iVar11 = 0;
    cVar3 = s__97c291c0[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar6 + iVar11) = cVar3;
      cVar3 = " "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar6 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteTextureOperand(param_1,iVar6 + iVar11,4,in_stack_00000040);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x48:
    if (in_stack_0000003c != 0x8b31) {
      return 0xffffffff;
    }
    iVar11 = 0;
    cVar3 = s_ARL_97c2f7e4[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "ARL "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x4d:
    iVar6 = 0;
    iVar11 = iVar6;
    cVar3 = s__97c26c38[0];
    if (s__97c26c38[0] != '\0') {
      do {
        *(char *)(param_2 + iVar11) = cVar3;
        iVar6 = iVar11 + 1;
        cVar3 = "\n"[iVar11 + 1];
        iVar11 = iVar6;
      } while (cVar3 != '\0');
      uVar8 = *param_1;
    }
    iVar6 = param_2 + iVar6;
    goto LAB_97c0178c;
  case 0x4f:
    iVar6 = 0;
    pcVar4 = *(char **)(PTR__ppstreamOpString_a7b7c108 + iVar11);
    cVar3 = *pcVar4;
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar6) = cVar3;
      iVar6 = iVar6 + 1;
      cVar3 = pcVar4[iVar6];
    }
    iVar11 = 0;
    cVar3 = s__97c291c0[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar6 + iVar11) = cVar3;
      cVar3 = " "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x50:
    if ((in_stack_00000038[1] & 0x400000) == 0) {
      return 0xffffffff;
    }
    if (in_stack_0000003c != 0x8b30) {
      return 0xffffffff;
    }
    *in_stack_00000038 = *in_stack_00000038 | 0x400000;
    iVar11 = 0;
    cVar3 = s_DDX_97c2f7ec[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "DDX "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x51:
    if ((in_stack_00000038[1] & 0x400000) == 0) {
      return 0xffffffff;
    }
    if (in_stack_0000003c != 0x8b30) {
      return 0xffffffff;
    }
    *in_stack_00000038 = *in_stack_00000038 | 0x400000;
    iVar11 = 0;
    cVar3 = s_DDY_97c2f7f4[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "DDY "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x57:
    if ((in_stack_00000038[1] & 0x800000) == 0) {
      return 0xffffffff;
    }
    if (in_stack_0000003c != 0x8b30) {
      return 0xffffffff;
    }
    *in_stack_00000038 = *in_stack_00000038 | 0x800000;
    iVar11 = 0;
    cVar3 = s_REP_97c2f824[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "REP "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x5b:
    if ((in_stack_00000038[1] & 0x800000) == 0) {
      return 0xffffffff;
    }
    if (in_stack_0000003c != 0x8b30) {
      return 0xffffffff;
    }
    *in_stack_00000038 = *in_stack_00000038 | 0x800000;
    iVar6 = 0;
    cVar3 = s_ENDREP__97c2f82c[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar6) = cVar3;
      cVar3 = "ENDREP;\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar6 = param_2 + iVar6;
    goto LAB_97c01788;
  case 0x68:
    *in_stack_00000038 = *in_stack_00000038 | 0x1007;
    uVar8 = param_1[2] >> 10 & 3;
    if (uVar8 == 1) {
      iVar11 = 0;
      cVar3 = s_MUL_scratch_xy__97c2e510[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "MUL scratch.xy, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
      iVar6 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar6) = cVar3;
        cVar3 = ";\n"[iVar6 + 1];
        iVar6 = iVar6 + 1;
      }
      iVar11 = 0;
      cVar3 = s_MUL_scratch__scratch_x__scratch__97c2f6b4[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar6 + iVar11) = cVar3;
        cVar3 = "MUL scratch, scratch.x, scratch.y;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar11 = iVar5 + iVar6 + iVar11;
    }
    else {
      if (uVar8 == 0) {
        iVar11 = 0;
        cVar3 = s_MUL_scratch__97c2e62c[0];
        while (cVar3 != '\0') {
          *(char *)(param_2 + iVar11) = cVar3;
          cVar3 = "MUL scratch, "[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
LAB_97c00620:
        iVar11 = param_2 + iVar11;
      }
      else {
        if (uVar8 == 2) {
          iVar11 = 0;
          cVar3 = s_DP3_scratch__97c2f6d8[0];
          while (cVar3 != '\0') {
            *(char *)(param_2 + iVar11) = cVar3;
            cVar3 = "DP3 scratch, "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          goto LAB_97c00620;
        }
        iVar11 = param_2;
        if (uVar8 == 3) {
          iVar11 = 0;
          cVar3 = s_DP4_scratch__97c2f6e8[0];
          while (cVar3 != '\0') {
            *(char *)(param_2 + iVar11) = cVar3;
            cVar3 = "DP4 scratch, "[iVar11 + 1];
            iVar11 = iVar11 + 1;
          }
          goto LAB_97c00620;
        }
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar11,param_5,param_6,2,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar11 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
    }
    iVar6 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar11 + iVar6) = cVar3;
      cVar3 = ";\n"[iVar6 + 1];
      iVar6 = iVar6 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MAD_scratch1__scratch___scratch__97c2f6f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar11 + iVar6 + iVar5) = cVar3;
      cVar3 = "MAD scratch1, scratch, -scratch, kONE;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar11 + iVar6 + iVar5;
    iVar11 = 0;
    cVar3 = s_MUL_scratch2__97c2ef7c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MUL scratch2, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,4,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,4,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MAD_scratch1__scratch2___scratch_97c2f720[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "MAD scratch1, scratch2, -scratch1, kONE;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_RSQ_scratch2__scratch1_x__97c2f74c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "RSQ scratch2, scratch1.x;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_RCP_scratch2__scratch2_x__97c2f768[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "RCP scratch2, scratch2.x;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = iVar5 + iVar11;
    iVar11 = 0;
    cVar3 = s_MAD_scratch2__scratch_x__97c2f784[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MAD scratch2, scratch.x, "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,4,0,0,8);
    iVar11 = 0;
    cVar3 = s___scratch2_x__97c2f7a0[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch2.x;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MUL_scratch2__97c2ef7c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "MUL scratch2, "[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11 + iVar5,param_5,param_6,3,0,0,8);
    iVar11 = 0;
    cVar3 = s___scratch2_x__97c2f7a0[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch2.x;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_MAD_scratch__97c2e64c[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "MAD scratch, "[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11 + iVar5,param_5,param_6,2,0,0,8);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,4,0,0,8);
    iVar11 = 0;
    cVar3 = s____scratch2__97c2f7b0[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", -scratch2;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar5 = 0;
    cVar3 = s_SGE_scratch1__scratch1_x__kZERO__97c2f7c0[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
      cVar3 = "SGE scratch1, scratch1.x, kZERO;\n"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar5 = iVar6 + iVar11 + iVar5;
    iVar11 = 0;
    cVar3 = s_MUL_97c2e4f0[0];
    while (cVar3 != '\0') {
      *(char *)(iVar5 + iVar11) = cVar3;
      cVar3 = "MUL "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
    iVar11 = 0;
    cVar3 = s___scratch__scratch1__97c2e4f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", scratch, scratch1;\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    break;
  case 0x6c:
    uVar9 = param_1[1] >> 0x17 & 7;
    if (uVar9 == 4) {
      *in_stack_00000038 = *in_stack_00000038 | 0x1001;
      iVar11 = 0;
      cVar3 = s_ABS_scratch__97c2e448[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "ABS scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_SLT_97c2e458[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "SLT "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
      iVar11 = 0;
      cVar3 = s____scratch__kZERO__97c2e460[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", -scratch, kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else if (uVar9 == 3) {
      *in_stack_00000038 = *in_stack_00000038 | 0x1003;
      iVar11 = 0;
      cVar3 = s_SLT_scratch__97c2e474[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "SLT scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,param_2 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___kZERO__97c2e484[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_SLT_scratch1__97c2e490[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "SLT scratch1, "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11 + iVar5,param_5,param_6,2,0,0,9);
      iVar11 = 0;
      cVar3 = s___kZERO__97c2e484[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", kZERO;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_ADD_scratch___scratch__scratch1__97c2e4a0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "ADD scratch, -scratch, scratch1;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar6 + iVar11 + iVar5;
      iVar11 = 0;
      cVar3 = s_ABS_scratch1__97c2e4c4[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "ABS scratch1, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_FLR_scratch1__scratch1__97c2e4d4[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "FLR scratch1, scratch1;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar6 + iVar11 + iVar5;
      iVar11 = 0;
      cVar3 = s_MUL_97c2e4f0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MUL "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch__scratch1__97c2e4f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch, scratch1;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      if (uVar9 != 1) goto LAB_97c0178c;
      iVar11 = 0;
      cVar3 = s_MOV_97c2e430[0];
      while (cVar3 != '\0') {
        *(char *)(param_2 + iVar11) = cVar3;
        cVar3 = "MOV "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,param_2 + iVar11,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,8);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 0x6d:
    if ((param_1[2] >> 0x11 & 7) != 1) {
      return 0xffffffff;
    }
    *in_stack_00000038 = *in_stack_00000038 | 0x1001;
    iVar11 = 0;
    cVar3 = s_SUB_scratch__kSEL_97c2f654[0];
    while (cVar3 != '\0') {
      *(char *)(param_2 + iVar11) = cVar3;
      cVar3 = "SUB scratch, kSEL"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = ((int (*)())_glpWriteComponentsWithDestinationSwizzle)(param_1,param_2 + iVar11);
    iVar11 = 0;
    cVar3 = s___97c2d7ec[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ", "[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,3,0,0,0);
    iVar11 = 0;
    cVar3 = s___97c2d8f8[0];
    while (cVar3 != '\0') {
      *(char *)(iVar6 + iVar11) = cVar3;
      cVar3 = ";\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    iVar6 = iVar6 + iVar11;
    if (in_stack_0000003c == 0x8b31) {
      *in_stack_00000038 = *in_stack_00000038 | 0x1002;
      iVar11 = 0;
      cVar3 = s_ABS_scratch__scratch__97c2e8c0[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = "ABS scratch, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_SGE_scratch___scratch__kZERO__97c2f634[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "SGE scratch, -scratch, kZERO;\n"[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar5 = iVar6 + iVar11 + iVar5;
      iVar11 = 0;
      cVar3 = s_SUB_scratch1__kONE__scratch__97c2f668[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "SUB scratch1, kONE, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = iVar5 + iVar11;
      iVar11 = 0;
      cVar3 = s_MUL_scratch__scratch__97c2e9ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar5 + iVar11) = cVar3;
        cVar3 = "MUL scratch, scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar11,param_5,param_6,2,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_MAD_97c2e644[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "MAD "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch1__97c2f688[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch1, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11,0,0,0x40);
      iVar11 = 0;
      cVar3 = s___scratch__97c2e620[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    else {
      iVar11 = 0;
      cVar3 = s_ABS_SAT_scratch__scratch__97c2f698[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = "ABS_SAT scratch, scratch;\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar5 = 0;
      cVar3 = s_LRP_97c2e9e4[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11 + iVar5) = cVar3;
        cVar3 = "LRP "[iVar5 + 1];
        iVar5 = iVar5 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11 + iVar5,0,0,0);
      iVar11 = 0;
      cVar3 = s___scratch__97c2e570[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", scratch, "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteDestinationOperand(param_1,iVar6 + iVar11,0,0,0x40);
      iVar11 = 0;
      cVar3 = s___97c2d7ec[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ", "[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
      iVar6 = _glpWriteSourceOperand(param_1,iVar6 + iVar11,param_5,param_6,2,0,0,0);
      iVar11 = 0;
      cVar3 = s___97c2d8f8[0];
      while (cVar3 != '\0') {
        *(char *)(iVar6 + iVar11) = cVar3;
        cVar3 = ";\n"[iVar11 + 1];
        iVar11 = iVar11 + 1;
      }
    }
    break;
  case 0x6f:
    *in_stack_00000038 = *in_stack_00000038 | 0x20000;
    uVar8 = param_1[2];
    iVar11 = 0;
    uVar9 = uVar8 >> 0xd & 0xf;
    do {
      if ((uVar9 & 1) != 0) {
        iVar5 = 0;
        cVar3 = s_POW_97c2e5a4[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = "POW "[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar5 = _glpWriteDestinationOperand(param_1,iVar6 + iVar5,0,iVar11,2);
        iVar6 = 0;
        cVar3 = s___kE__97c2e5ac[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar6) = cVar3;
          cVar3 = ", kE, "[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar6 = _glpWriteSourceOperand(param_1,iVar5 + iVar6,param_5,param_6,2,0,iVar11,10);
        iVar5 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = ";\n"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        uVar8 = param_1[2];
        iVar6 = iVar6 + iVar5;
      }
      iVar11 = iVar11 + 1;
      uVar9 = (int)uVar9 >> 1;
    } while (iVar11 <= (int)(uVar8 >> 10 & 3));
    goto LAB_97c01788;
  case 0x70:
    *in_stack_00000038 = *in_stack_00000038 | 0x20001;
    uVar8 = param_1[2];
    iVar11 = 0;
    uVar9 = uVar8 >> 0xd & 0xf;
    do {
      if ((uVar9 & 1) != 0) {
        iVar5 = 0;
        cVar3 = s_LG2_scratch__97c2e5b4[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = "LG2 scratch, "[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        iVar5 = _glpWriteSourceOperand(param_1,iVar6 + iVar5,param_5,param_6,2,0,iVar11,10);
        iVar6 = 0;
        cVar3 = s___97c2d8f8[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar6) = cVar3;
          cVar3 = ";\n"[iVar6 + 1];
          iVar6 = iVar6 + 1;
        }
        iVar13 = 0;
        cVar3 = s_MUL_97c2e4f0[0];
        while (cVar3 != '\0') {
          *(char *)(iVar5 + iVar6 + iVar13) = cVar3;
          cVar3 = "MUL "[iVar13 + 1];
          iVar13 = iVar13 + 1;
        }
        iVar6 = _glpWriteDestinationOperand(param_1,iVar5 + iVar6 + iVar13,0,iVar11,2);
        iVar5 = 0;
        cVar3 = s___scratch__k1_OVER_LOG2_E__97c2e5c4[0];
        while (cVar3 != '\0') {
          *(char *)(iVar6 + iVar5) = cVar3;
          cVar3 = ", scratch, k1_OVER_LOG2_E;\n"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        uVar8 = param_1[2];
        iVar6 = iVar6 + iVar5;
      }
      iVar11 = iVar11 + 1;
      uVar9 = (int)uVar9 >> 1;
    } while (iVar11 <= (int)(uVar8 >> 10 & 3));
    goto LAB_97c01788;
  }
  iVar6 = iVar6 + iVar11;
LAB_97c01788:
  uVar8 = *param_1;
LAB_97c0178c:
  *param_3 = (uVar8 >> 0x1d) + 1;
  *param_4 = iVar6 - param_2;
  return 0;
}

/* _isParamArrayStart_97c017c0 @ 0x97c017c0 (96 bytes) */
int _isParamArrayStart_97c017c0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint *param_3;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x38);
  param_1 = param_1 + *(int *)(param_1 + 0x3c) * 8;
  if ((iVar2 != 0) && (iVar1 = 0, 0 < iVar2)) {
    do {
      if ((*(uint *)(param_1 + iVar1 * 8) & 0xffff) == param_2) {
        *param_3 = (uint)*(ushort *)(iVar1 * 8 + param_1 + 6);
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < iVar2);
  }
  return 0;
}

/* _glpPPShaderToProgramString @ 0x97c01820 (15972 bytes) */
int _glpPPShaderToProgramString(param_1)
  int *param_1;
{
  char cVar1;
  char acVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  void *pvVar14;
  int iVar15;
  int *piVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  size_t sVar20;
  uint uVar21;
  float *pfVar22;
  undefined8 uVar23;
  size_t local_68;
  char *local_64;
  char *local_60;
  uint local_5c;
  int local_58;
  int local_54;
  int local_50;
  char *local_4c;
  char *local_48 [2];
  
  local_68 = 0x1000;
  local_50 = 1;
  local_64 = _malloc(0x1000);
  iVar11 = 0;
  pvVar14 = (void *)0x0;
  piVar13 = (int *)0x0;
  piVar12 = (int *)0x0;
  if (local_64 == (char *)0x0) {
    return (void *)0x0;
  }
  iVar15 = *param_1;
  iVar17 = param_1[6];
  local_60 = local_64;
  if (iVar17 != 0) {
    iVar5 = 0;
    cVar1 = s_ADDRESS_adr0_97c2da34[0];
    while (cVar1 != '\0') {
      local_64[iVar5] = cVar1;
      cVar1 = "ADDRESS adr0"[iVar5 + 1];
      iVar5 = iVar5 + 1;
    }
    iVar18 = 1;
    local_60 = local_64 + iVar5;
    if (1 < iVar17) {
      do {
        iVar5 = 0;
        cVar1 = s___adr_97c2da44[0];
        while (cVar1 != '\0') {
          local_60[iVar5] = cVar1;
          cVar1 = ", adr"[iVar5 + 1];
          iVar5 = iVar5 + 1;
        }
        local_60 = local_60 + iVar5;
        iVar19 = iVar18 + 1;
        iVar5 = _ncpy(local_60,iVar18);
        local_60 = local_60 + iVar5;
        iVar18 = iVar19;
      } while (iVar19 < iVar17);
    }
    iVar17 = 0;
    cVar1 = s___97c2d8f8[0];
    while (cVar1 != '\0') {
      local_60[iVar17] = cVar1;
      cVar1 = ";\n"[iVar17 + 1];
      iVar17 = iVar17 + 1;
    }
    local_60 = local_60 + iVar17;
    iVar17 = _adjustAllocation(&local_68,&local_64,&local_60);
    pcVar9 = local_64;
    if (iVar17 == 0) goto LAB_97c04d50;
    iVar17 = 0;
    cVar1 = s__97c26c38[0];
    while (cVar1 != '\0') {
      local_60[iVar17] = cVar1;
      cVar1 = "\n"[iVar17 + 1];
      iVar17 = iVar17 + 1;
    }
    local_60 = local_60 + iVar17;
  }
  iVar17 = param_1[4];
  iVar5 = 0;
  if (0 < iVar17) {
    piVar16 = param_1 + param_1[5] * 2 + 1;
    do {
      iVar18 = 0;
      cVar1 = s_TEMP_97c2da4c[0];
      while (cVar1 != '\0') {
        local_60[iVar18] = cVar1;
        cVar1 = "TEMP "[iVar18 + 1];
        iVar18 = iVar18 + 1;
      }
      iVar19 = 0;
      cVar1 = s_tmp_97c2d76c[0];
      while (cVar1 != '\0') {
        local_60[iVar19 + iVar18] = cVar1;
        cVar1 = "tmp"[iVar19 + 1];
        iVar19 = iVar19 + 1;
      }
      local_60 = local_60 + iVar19 + iVar18;
      iVar19 = _ncpy(local_60,(short)*piVar16);
      iVar18 = 0;
      cVar1 = s___97c2d8f8[0];
      while (cVar1 != '\0') {
        local_60[iVar18 + iVar19] = cVar1;
        cVar1 = ";\n"[iVar18 + 1];
        iVar18 = iVar18 + 1;
      }
      local_60 = local_60 + iVar18 + iVar19;
      iVar18 = _adjustAllocation(&local_68,&local_64,&local_60);
      pcVar9 = local_64;
      if (iVar18 == 0) goto LAB_97c04d50;
      iVar5 = iVar5 + 1;
      piVar16 = piVar16 + 2;
    } while (iVar5 < iVar17);
  }
  if (iVar17 != 0) {
    iVar17 = 0;
    cVar1 = s__97c26c38[0];
    while (cVar1 != '\0') {
      local_60[iVar17] = cVar1;
      cVar1 = "\n"[iVar17 + 1];
      iVar17 = iVar17 + 1;
    }
    local_60 = local_60 + iVar17;
  }
  iVar5 = param_1[8];
  iVar18 = 0;
  iVar17 = param_1[9];
  if (0 < iVar5) {
    do {
      uVar21 = (uint)param_1[iVar17 * 2 + iVar18 * 2] >> 0x10 & 0xf;
      if (uVar21 == 0) goto LAB_97c0239c;
      iVar19 = 0;
      cVar1 = s_ATTRIB_att_97c2da6c[0];
      while (cVar1 != '\0') {
        local_60[iVar19] = cVar1;
        cVar1 = "ATTRIB att"[iVar19 + 1];
        iVar19 = iVar19 + 1;
      }
      local_60 = local_60 + iVar19;
      iVar19 = _ncpy(local_60,*(undefined2 *)((int)param_1 + iVar18 * 8 + iVar17 * 8 + 6));
      local_60 = local_60 + iVar19;
      if (iVar15 == 0x8b30) {
        iVar19 = 0;
        cVar1 = s___fragment__97c2da84[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = " = fragment."[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
LAB_97c01cf8:
        local_60 = local_60 + iVar19;
      }
      else if (iVar15 == 0x8b31) {
        iVar19 = 0;
        cVar1 = s___vertex__97c2da78[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = " = vertex."[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        goto LAB_97c01cf8;
      }
      switch(uVar21) {
      default:
        goto switchD_97c01d20_caseD_0;
      case 1:
        iVar19 = 0;
        cVar1 = s_position_97c2da94[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "position"[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        break;
      case 2:
        iVar19 = 0;
        cVar1 = s_color_primary_97c2daa0[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "color.primary"[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        break;
      case 3:
        iVar19 = 0;
        cVar1 = s_color_secondary_97c2dab0[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "color.secondary"[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        break;
      case 4:
        iVar19 = 0;
        cVar1 = s_normal_97c2dac0[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "normal"[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        break;
      case 5:
        iVar19 = 0;
        cVar1 = s_fogcoord_97c2dac8[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "fogcoord"[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        break;
      case 6:
        iVar19 = 0;
        cVar1 = s_weight__97c2daec[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "weight["[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        local_60 = local_60 + iVar19;
        iVar19 = _ncpy(local_60,param_1[iVar17 * 2 + iVar18 * 2] & 0x1f);
        local_60 = local_60 + iVar19;
        iVar19 = 0;
        cVar1 = s___97c2d770[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "]"[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        goto LAB_97c02104;
      case 7:
        iVar19 = 0;
        cVar1 = s_texcoord__97c2dae0[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "texcoord["[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        local_60 = local_60 + iVar19;
        iVar19 = _ncpy(local_60,param_1[iVar17 * 2 + iVar18 * 2] & 0x1f);
        local_60 = local_60 + iVar19;
        iVar19 = 0;
        cVar1 = s___97c2d770[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "]"[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        goto LAB_97c02104;
      case 8:
        iVar19 = 0;
        cVar1 = s_matrixindex__97c2daf4[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "matrixindex["[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        local_60 = local_60 + iVar19;
        iVar19 = _ncpy(local_60,param_1[iVar17 * 2 + iVar18 * 2] & 0x1f);
        local_60 = local_60 + iVar19;
        iVar19 = 0;
        cVar1 = s___97c2d770[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "]"[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        goto LAB_97c02104;
      case 9:
        iVar19 = 0;
        cVar1 = s_attrib__97c2db04[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "attrib["[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        local_60 = local_60 + iVar19;
        iVar19 = _ncpy(local_60,param_1[iVar17 * 2 + iVar18 * 2] & 0x1f);
        local_60 = local_60 + iVar19;
        iVar19 = 0;
        cVar1 = s___97c2d770[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "]"[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
LAB_97c02104:
        local_60 = local_60 + iVar19;
        goto switchD_97c01d20_caseD_0;
      case 10:
        iVar19 = 0;
        cVar1 = s_material__97c2db0c[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "material."[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
        local_60 = local_60 + iVar19;
        if ((param_1[iVar17 * 2 + iVar18 * 2] & 1U) == 0) {
          iVar19 = 0;
          cVar1 = s_front__97c2db18[0];
          while (cVar1 != '\0') {
            local_60[iVar19] = cVar1;
            cVar1 = "front."[iVar19 + 1];
            iVar19 = iVar19 + 1;
          }
LAB_97c021dc:
          local_60 = local_60 + iVar19;
        }
        else if ((param_1[iVar17 * 2 + iVar18 * 2] & 1U) == 1) {
          iVar19 = 0;
          cVar1 = s_back__97c2db20[0];
          while (cVar1 != '\0') {
            local_60[iVar19] = cVar1;
            cVar1 = "back."[iVar19 + 1];
            iVar19 = iVar19 + 1;
          }
          goto LAB_97c021dc;
        }
        switch((uint)param_1[iVar17 * 2 + iVar18 * 2] >> 0xc & 0xf) {
        case 0:
          iVar19 = 0;
          cVar1 = s_ambient_97c2db28[0];
          while (cVar1 != '\0') {
            local_60[iVar19] = cVar1;
            cVar1 = "ambient"[iVar19 + 1];
            iVar19 = iVar19 + 1;
          }
          break;
        case 1:
          iVar19 = 0;
          cVar1 = s_diffuse_97c2db30[0];
          while (cVar1 != '\0') {
            local_60[iVar19] = cVar1;
            cVar1 = "diffuse"[iVar19 + 1];
            iVar19 = iVar19 + 1;
          }
          break;
        case 2:
          iVar19 = 0;
          cVar1 = s_specular_97c2db38[0];
          while (cVar1 != '\0') {
            local_60[iVar19] = cVar1;
            cVar1 = "specular"[iVar19 + 1];
            iVar19 = iVar19 + 1;
          }
          break;
        case 3:
          iVar19 = 0;
          cVar1 = s_emission_97c2db44[0];
          while (cVar1 != '\0') {
            local_60[iVar19] = cVar1;
            cVar1 = "emission"[iVar19 + 1];
            iVar19 = iVar19 + 1;
          }
          break;
        case 4:
          iVar19 = 0;
          cVar1 = s_shininess_97c2db50[0];
          while (cVar1 != '\0') {
            local_60[iVar19] = cVar1;
            cVar1 = "shininess"[iVar19 + 1];
            iVar19 = iVar19 + 1;
          }
          break;
        default:
          goto switchD_97c01d20_caseD_0;
        }
        break;
      case 0xb:
        iVar19 = 0;
        cVar1 = s_frontfacing_97c2dad4[0];
        while (cVar1 != '\0') {
          local_60[iVar19] = cVar1;
          cVar1 = "frontfacing"[iVar19 + 1];
          iVar19 = iVar19 + 1;
        }
      }
      local_60 = local_60 + iVar19;
switchD_97c01d20_caseD_0:
      iVar19 = 0;
      cVar1 = s___97c2d8f8[0];
      while (cVar1 != '\0') {
        local_60[iVar19] = cVar1;
        cVar1 = ";\n"[iVar19 + 1];
        iVar19 = iVar19 + 1;
      }
      local_60 = local_60 + iVar19;
      iVar19 = _adjustAllocation(&local_68,&local_64,&local_60);
      pcVar9 = local_64;
      if (iVar19 == 0) goto LAB_97c04d50;
LAB_97c0239c:
      iVar18 = iVar18 + 1;
    } while (iVar18 < iVar5);
  }
  if (iVar5 != 0) {
    iVar17 = 0;
    cVar1 = s__97c26c38[0];
    while (cVar1 != '\0') {
      local_60[iVar17] = cVar1;
      cVar1 = "\n"[iVar17 + 1];
      iVar17 = iVar17 + 1;
    }
    local_60 = local_60 + iVar17;
  }
  iVar5 = param_1[10];
  iVar17 = param_1[0xb];
  if (iVar5 != 0) {
    uVar21 = 0xffffffff;
    if (0 < iVar5) {
      puVar4 = (uint *)(param_1 + iVar17 * 2 + 1);
      iVar18 = iVar5;
      do {
        uVar3 = *puVar4;
        puVar4 = puVar4 + 2;
        if ((int)uVar21 < (int)(uVar3 & 0xffff)) {
          uVar21 = uVar3 & 0xffff;
        }
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
      if (uVar21 != 0xffffffff) {
        sVar20 = uVar21 * 4 + 4;
        pvVar14 = _malloc(sVar20);
        piVar13 = _malloc(sVar20);
        if ((pvVar14 == (void *)0x0) || (piVar13 == (int *)0x0)) {
          piVar12 = piVar13;
          pcVar9 = local_64;
          if (pvVar14 != (void *)0x0) {
            _free(pvVar14);
            pcVar9 = local_64;
          }
joined_r0x97c02488:
          local_64 = pcVar9;
          if (piVar12 != (int *)0x0) {
            _free(piVar12);
            pcVar9 = local_64;
          }
          goto LAB_97c04d50;
        }
      }
    }
    if (param_1[0xe] != 0) {
      piVar12 = _malloc(param_1[0xe] << 2);
    }
    iVar18 = 0;
    iVar19 = -1;
    local_5c = 0xffffffff;
    uVar21 = 0xffffffff;
    piVar16 = piVar12;
    if (0 < iVar5) {
      do {
        iVar8 = iVar18 * 8 + iVar17 * 8;
        if ((param_1[iVar17 * 2 + iVar18 * 2] & 0x1f0000U) != 0) {
          if (uVar21 == 0xffffffff) {
            uVar3 = (uint)*(ushort *)((int)param_1 + iVar8 + 6);
            *(uint *)(uVar3 * 4 + (int)pvVar14) = uVar3;
            iVar6 = _isParamArrayStart(param_1,*(undefined2 *)((int)param_1 + iVar8 + 6),&local_5c);
            if (iVar6 == 0) {
              piVar13[*(ushort *)((int)param_1 + iVar8 + 6)] = iVar19;
            }
            else {
              uVar21 = (uint)*(ushort *)((int)param_1 + iVar8 + 6);
              piVar13[uVar21] = 0;
              iVar19 = 1;
            }
          }
          else {
            uVar3 = (uint)*(ushort *)((int)param_1 + iVar8 + 6);
            if ((int)uVar3 <= (int)local_5c) {
              *(uint *)(uVar3 * 4 + (int)pvVar14) = uVar21;
              piVar13[*(ushort *)((int)param_1 + iVar8 + 6)] = iVar19;
              iVar19 = iVar19 + 1;
              if (*(ushort *)((int)param_1 + iVar8 + 6) == local_5c) {
                uVar21 = 0xffffffff;
                local_5c = 0xffffffff;
                *piVar16 = iVar19;
                piVar16 = piVar16 + 1;
                iVar19 = -1;
              }
            }
          }
        }
        iVar18 = iVar18 + 1;
      } while (iVar18 < iVar5);
    }
    iVar19 = 0;
    iVar18 = 0;
    if (0 < iVar5) {
      do {
        iVar8 = iVar19 * 8;
        uVar21 = (uint)param_1[iVar17 * 2 + iVar19 * 2] >> 0x10 & 0x1f;
        if (uVar21 == 0) goto LAB_97c04238;
        if (piVar13[*(ushort *)((int)param_1 + iVar8 + iVar17 * 8 + 6)] == -1) {
          iVar6 = 0;
          cVar1 = s_PARAM_prm_97c2db5c[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "PARAM prm"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6;
          iVar7 = _ncpy(local_60,*(undefined4 *)
                                  ((int)pvVar14 +
                                  (uint)*(ushort *)((int)param_1 + iVar8 + iVar17 * 8 + 6) * 4));
          iVar6 = 0;
          cVar1 = s___97c2db68[0];
          while (cVar1 != '\0') {
            local_60[iVar6 + iVar7] = cVar1;
            cVar1 = " = "[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6 + iVar7;
        }
        else {
          if (piVar13[*(ushort *)((int)param_1 + iVar8 + iVar17 * 8 + 6)] == 0) {
            iVar11 = 0;
            iVar6 = 0;
            cVar1 = s_PARAM_prm_97c2db5c[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "PARAM prm"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6;
            iVar7 = _ncpy(local_60,*(undefined4 *)
                                    ((int)pvVar14 +
                                    (uint)*(ushort *)((int)param_1 + iVar8 + iVar17 * 8 + 6) * 4));
            iVar6 = 0;
            cVar1 = s___97c29860[0];
            while (cVar1 != '\0') {
              local_60[iVar6 + iVar7] = cVar1;
              cVar1 = "["[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6 + iVar7;
            iVar7 = _ncpy(local_60,piVar12[iVar18]);
            iVar6 = 0;
            cVar1 = s___97c2d770[0];
            while (cVar1 != '\0') {
              local_60[iVar6 + iVar7] = cVar1;
              cVar1 = "]"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6 + iVar7;
            iVar6 = 0;
            cVar1 = s_____97c2db6c[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = " = {\n    "[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          else {
            iVar11 = iVar11 + 1;
            iVar6 = 0;
            cVar1 = s__97c2db78[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "    "[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          local_60 = local_60 + iVar6;
        }
        if (uVar21 == 0) {
LAB_97c028a4:
          iVar6 = 0;
          cVar1 = s_state__97c2db8c[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "state."[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
        }
        else if (uVar21 < 3) {
          iVar6 = 0;
          cVar1 = s_program__97c2db80[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "program."[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
        }
        else {
          if (uVar21 != 0x11) goto LAB_97c028a4;
          iVar6 = 0;
          acVar2 = s__97c23d6c[0];
          while (acVar2 != '\0') {
            local_60[iVar6] = acVar2;
            acVar2 = ""[iVar6];
            iVar6 = iVar6 + 1;
          }
        }
        local_60 = local_60 + iVar6;
        switch(uVar21) {
        default:
          goto switchD_97c02904_caseD_0;
        case 1:
          iVar6 = 0;
          cVar1 = s_local__97c2db94[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "local["[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6;
          iVar6 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0xffff);
          local_60 = local_60 + iVar6;
          iVar6 = 0;
          cVar1 = s___97c2d770[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "]"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          goto LAB_97c040c8;
        case 2:
          iVar6 = 0;
          cVar1 = s_env__97c2db9c[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "env["[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6;
          iVar6 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0xffff);
          local_60 = local_60 + iVar6;
          iVar6 = 0;
          cVar1 = s___97c2d770[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "]"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          goto LAB_97c040c8;
        case 3:
          iVar6 = 0;
          cVar1 = s_light__97c2dba4[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "light["[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6;
          iVar7 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0xff);
          iVar6 = 0;
          cVar1 = s____97c2dbac[0];
          while (cVar1 != '\0') {
            local_60[iVar6 + iVar7] = cVar1;
            cVar1 = "]."[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6 + iVar7;
          switch((uint)param_1[iVar17 * 2 + iVar19 * 2] >> 8 & 0xf) {
          case 0:
            iVar6 = 0;
            cVar1 = s_ambient_97c2db28[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "ambient"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 1:
            iVar6 = 0;
            cVar1 = s_diffuse_97c2db30[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "diffuse"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 2:
            iVar6 = 0;
            cVar1 = s_specular_97c2db38[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "specular"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 3:
            iVar6 = 0;
            cVar1 = s_position_97c2da94[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "position"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 4:
            iVar6 = 0;
            cVar1 = s_spot_direction_97c2dbb0[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "spot.direction"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 5:
            iVar6 = 0;
            cVar1 = s_attenuation_97c2dbc0[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "attenuation"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 6:
            iVar6 = 0;
            cVar1 = s_half_97c2dbcc[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "half"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 7:
            iVar6 = 0;
            cVar1 = s_spotcutoff_97c2dbd4[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "spotcutoff"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          default:
            goto switchD_97c02904_caseD_0;
          }
          break;
        case 4:
          iVar6 = 0;
          cVar1 = s_lightprod__97c2dbe0[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "lightprod["[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6;
          iVar7 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0xff);
          iVar6 = 0;
          cVar1 = s____97c2dbac[0];
          while (cVar1 != '\0') {
            local_60[iVar6 + iVar7] = cVar1;
            cVar1 = "]."[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6 + iVar7;
          uVar21 = (uint)param_1[iVar17 * 2 + iVar19 * 2] >> 8 & 1;
          if (uVar21 == 0) {
            iVar6 = 0;
            cVar1 = s_front__97c2db18[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "front."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
LAB_97c02e64:
            local_60 = local_60 + iVar6;
          }
          else if (uVar21 == 1) {
            iVar6 = 0;
            cVar1 = s_back__97c2db20[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "back."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            goto LAB_97c02e64;
          }
          uVar21 = (uint)param_1[iVar17 * 2 + iVar19 * 2] >> 9 & 3;
          if (uVar21 == 1) {
            iVar6 = 0;
            cVar1 = s_diffuse_97c2db30[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "diffuse"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          }
          if (uVar21 < 2) {
            if (uVar21 == 0) {
              iVar6 = 0;
              cVar1 = s_ambient_97c2db28[0];
              while (cVar1 != '\0') {
                local_60[iVar6] = cVar1;
                cVar1 = "ambient"[iVar6 + 1];
                iVar6 = iVar6 + 1;
              }
              break;
            }
          }
          else if (uVar21 == 2) {
            iVar6 = 0;
            cVar1 = s_specular_97c2db38[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "specular"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          }
          goto switchD_97c02904_caseD_0;
        case 5:
          if (((uint)param_1[iVar17 * 2 + iVar19 * 2] >> 1 & 7) == 5) {
            iVar6 = 0;
            cVar1 = s_lightmodel__97c2dc00[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "lightmodel."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          else {
            iVar6 = 0;
            cVar1 = s_material__97c2db0c[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "material."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          local_60 = local_60 + iVar6;
          if ((param_1[iVar17 * 2 + iVar19 * 2] & 1U) == 0) {
            iVar6 = 0;
            cVar1 = s_front__97c2db18[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "front."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
LAB_97c0308c:
            local_60 = local_60 + iVar6;
          }
          else if ((param_1[iVar17 * 2 + iVar19 * 2] & 1U) == 1) {
            iVar6 = 0;
            cVar1 = s_back__97c2db20[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "back."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            goto LAB_97c0308c;
          }
          switch((uint)param_1[iVar17 * 2 + iVar19 * 2] >> 1 & 7) {
          case 0:
            iVar6 = 0;
            cVar1 = s_ambient_97c2db28[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "ambient"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 1:
            iVar6 = 0;
            cVar1 = s_diffuse_97c2db30[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "diffuse"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 2:
            iVar6 = 0;
            cVar1 = s_specular_97c2db38[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "specular"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 3:
            iVar6 = 0;
            cVar1 = s_emission_97c2db44[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "emission"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 4:
            iVar6 = 0;
            cVar1 = s_shininess_97c2db50[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "shininess"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 5:
            iVar6 = 0;
            cVar1 = s_scenecolor_97c2dc0c[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "scenecolor"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          default:
            goto switchD_97c02904_caseD_0;
          }
          break;
        case 6:
          iVar6 = 0;
          cVar1 = s_lightmodel_ambient_97c2dbec[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "lightmodel.ambient"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          break;
        case 7:
          iVar6 = 0;
          cVar1 = s_texgen__97c2dc18[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "texgen["[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6;
          iVar7 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0x1f);
          iVar6 = 0;
          cVar1 = s___eye__97c2dc20[0];
          while (cVar1 != '\0') {
            local_60[iVar6 + iVar7] = cVar1;
            cVar1 = "].eye."[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6 + iVar7;
          uVar21 = (uint)param_1[iVar17 * 2 + iVar19 * 2] >> 5 & 7;
          if (uVar21 == 1) {
            iVar6 = 0;
            cVar1 = s_t_97c2dc2c[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "t"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          else if (uVar21 < 2) {
            if (uVar21 != 0) goto switchD_97c02904_caseD_0;
            iVar6 = 0;
            cVar1 = s_s_97c2dc28[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "s"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          else if (uVar21 == 2) {
            iVar6 = 0;
            cVar1 = s_r_97c2dc30[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "r"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          else {
            if (uVar21 != 3) goto switchD_97c02904_caseD_0;
            iVar6 = 0;
            cVar1 = s_q_97c2dc34[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "q"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          break;
        case 8:
          iVar6 = 0;
          cVar1 = s_texgen__97c2dc18[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "texgen["[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6;
          iVar7 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0x1f);
          iVar6 = 0;
          cVar1 = s___object__97c2dc38[0];
          while (cVar1 != '\0') {
            local_60[iVar6 + iVar7] = cVar1;
            cVar1 = "].object."[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6 + iVar7;
          uVar21 = (uint)param_1[iVar17 * 2 + iVar19 * 2] >> 5 & 7;
          if (uVar21 == 1) {
            iVar6 = 0;
            cVar1 = s_t_97c2dc2c[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "t"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          else if (uVar21 < 2) {
            if (uVar21 != 0) goto switchD_97c02904_caseD_0;
            iVar6 = 0;
            cVar1 = s_s_97c2dc28[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "s"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          else if (uVar21 == 2) {
            iVar6 = 0;
            cVar1 = s_r_97c2dc30[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "r"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          else {
            if (uVar21 != 3) goto switchD_97c02904_caseD_0;
            iVar6 = 0;
            cVar1 = s_q_97c2dc34[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "q"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
          }
          break;
        case 9:
          iVar6 = 0;
          cVar1 = s_texenv__97c2dc44[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "texenv["[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6;
          iVar6 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0x1f);
          local_60 = local_60 + iVar6;
          iVar6 = 0;
          cVar1 = s___color_97c2dc4c[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "].color"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          goto LAB_97c040c8;
        case 10:
          iVar6 = 0;
          cVar1 = s_clip__97c2dc54[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "clip["[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6;
          iVar6 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0xff);
          local_60 = local_60 + iVar6;
          iVar6 = 0;
          cVar1 = s___plane_97c2dc5c[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "].plane"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          goto LAB_97c040c8;
        case 0xb:
          iVar6 = 0;
          cVar1 = s_fog_color_97c2dc64[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "fog.color"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          break;
        case 0xc:
          iVar6 = 0;
          cVar1 = s_fog_params_97c2dc70[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "fog.params"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          break;
        case 0xd:
          iVar6 = 0;
          cVar1 = s_point_size_97c2dc88[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "point.size"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          break;
        case 0xe:
          iVar6 = 0;
          cVar1 = s_point_attenuation_97c2dc94[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "point.attenuation"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          break;
        case 0xf:
          iVar6 = 0;
          cVar1 = s_depth_range_97c2dc7c[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "depth.range"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          break;
        case 0x10:
          iVar6 = 0;
          cVar1 = s_matrix__97c2dca8[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "matrix."[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6;
          switch((uint)param_1[iVar17 * 2 + iVar19 * 2] >> 8 & 7) {
          case 0:
            iVar6 = 0;
            cVar1 = s_mvp__97c2dcbc[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "mvp."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            goto LAB_97c038d8;
          case 1:
            iVar6 = 0;
            cVar1 = s_projection__97c2dcb0[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "projection."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
LAB_97c038d8:
            local_60 = local_60 + iVar6;
            goto switchD_97c0384c_default;
          case 2:
            iVar6 = 0;
            cVar1 = s_color__97c2dcc4[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "color["[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6;
            iVar6 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0xff);
            local_60 = local_60 + iVar6;
            iVar6 = 0;
            cVar1 = s____97c2dbac[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "]."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 3:
            iVar6 = 0;
            cVar1 = s_modelview__97c2dccc[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "modelview["[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6;
            iVar6 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0xff);
            local_60 = local_60 + iVar6;
            iVar6 = 0;
            cVar1 = s____97c2dbac[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "]."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 4:
            iVar6 = 0;
            cVar1 = s_texture__97c2d814[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "texture["[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6;
            iVar6 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0xff);
            local_60 = local_60 + iVar6;
            iVar6 = 0;
            cVar1 = s____97c2dbac[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "]."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 5:
            iVar6 = 0;
            cVar1 = s_program__97c2dcd8[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "program["[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6;
            iVar6 = _ncpy(local_60,param_1[iVar17 * 2 + iVar19 * 2] & 0xff);
            local_60 = local_60 + iVar6;
            iVar6 = 0;
            cVar1 = s____97c2dbac[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "]."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          default:
            goto switchD_97c0384c_default;
          }
          local_60 = local_60 + iVar6;
switchD_97c0384c_default:
          uVar21 = (uint)param_1[iVar17 * 2 + iVar19 * 2] >> 0xe & 3;
          if (uVar21 == 1) {
            iVar6 = 0;
            cVar1 = s_transpose__97c2dce4[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "transpose."[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
LAB_97c03c18:
            local_60 = local_60 + iVar6;
          }
          else if (1 < uVar21) {
            if (uVar21 == 2) {
              iVar6 = 0;
              cVar1 = s_inverse__97c2dcf0[0];
              while (cVar1 != '\0') {
                local_60[iVar6] = cVar1;
                cVar1 = "inverse."[iVar6 + 1];
                iVar6 = iVar6 + 1;
              }
            }
            else {
              if (uVar21 != 3) goto LAB_97c03c20;
              iVar6 = 0;
              cVar1 = s_invtrans__97c2dcfc[0];
              while (cVar1 != '\0') {
                local_60[iVar6] = cVar1;
                cVar1 = "invtrans."[iVar6 + 1];
                iVar6 = iVar6 + 1;
              }
            }
            goto LAB_97c03c18;
          }
LAB_97c03c20:
          iVar6 = 0;
          cVar1 = s_row__97c2dd08[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "row["[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
          local_60 = local_60 + iVar6;
          iVar6 = _ncpy(local_60,(uint)param_1[iVar17 * 2 + iVar19 * 2] >> 0xc & 3);
          local_60 = local_60 + iVar6;
          iVar6 = 0;
          cVar1 = s___97c2d770[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "]"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
LAB_97c040c8:
          local_60 = local_60 + iVar6;
          goto switchD_97c02904_caseD_0;
        case 0x11:
          pfVar22 = (float *)(param_1 +
                             param_1[0x1b] * 2 + (param_1[iVar17 * 2 + iVar19 * 2] & 0xffffU) * 4);
          switch((uint)param_1[iVar17 * 2 + iVar19 * 2] >> 0x1a & 7) {
          case 0:
          case 1:
            iVar6 = 0;
            cVar1 = s___97c2dd10[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "{"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6;
            uVar23 = ((char * (*)())_glp_dtostr)((double)*pfVar22,DOUBLE_97c30a70);
            iVar7 = (int)((ulonglong)uVar23 >> 0x20);
            iVar6 = 0;
            cVar1 = s___97c2d7ec[0];
            while (cVar1 != '\0') {
              *(char *)(iVar7 + iVar6) = cVar1;
              cVar1 = ", "[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = (char *)(iVar7 + iVar6);
            uVar23 = ((char * (*)())_glp_dtostr)((double)pfVar22[1],DOUBLE_97c30a70,iVar7,(int)uVar23,local_60,
                                 local_64 + (local_68 - (int)local_60));
            iVar7 = (int)((ulonglong)uVar23 >> 0x20);
            iVar6 = 0;
            cVar1 = s___97c2d7ec[0];
            while (cVar1 != '\0') {
              *(char *)(iVar7 + iVar6) = cVar1;
              cVar1 = ", "[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = (char *)(iVar7 + iVar6);
            uVar23 = ((char * (*)())_glp_dtostr)((double)pfVar22[2],DOUBLE_97c30a70,iVar7,(int)uVar23,local_60,
                                 local_64 + (local_68 - (int)local_60));
            iVar7 = (int)((ulonglong)uVar23 >> 0x20);
            iVar6 = 0;
            cVar1 = s___97c2d7ec[0];
            while (cVar1 != '\0') {
              *(char *)(iVar7 + iVar6) = cVar1;
              cVar1 = ", "[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = (char *)(iVar7 + iVar6);
            local_60 = (char *)((char * (*)())_glp_dtostr)((double)pfVar22[3],DOUBLE_97c30a70,iVar7,(int)uVar23,
                                           local_60,local_64 + (local_68 - (int)local_60));
            iVar6 = 0;
            cVar1 = s___97c2dd14[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "}"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 2:
            iVar6 = 0;
            cVar1 = s_____Fixed_constant_data_not_curr_97c2dd18[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "{-- Fixed constant data not currently supported --}"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            break;
          case 3:
          case 4:
            iVar6 = 0;
            cVar1 = s___97c2dd10[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "{"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6;
            iVar7 = _ncpy(local_60,*pfVar22);
            iVar6 = 0;
            cVar1 = s___97c2d7ec[0];
            while (cVar1 != '\0') {
              local_60[iVar6 + iVar7] = cVar1;
              cVar1 = ", "[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6 + iVar7;
            iVar7 = _ncpy(local_60,pfVar22[1]);
            iVar6 = 0;
            cVar1 = s___97c2d7ec[0];
            while (cVar1 != '\0') {
              local_60[iVar6 + iVar7] = cVar1;
              cVar1 = ", "[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6 + iVar7;
            iVar7 = _ncpy(local_60,pfVar22[2]);
            iVar6 = 0;
            cVar1 = s___97c2d7ec[0];
            while (cVar1 != '\0') {
              local_60[iVar6 + iVar7] = cVar1;
              cVar1 = ", "[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            local_60 = local_60 + iVar6 + iVar7;
            iVar6 = _ncpy(local_60,pfVar22[3]);
            local_60 = local_60 + iVar6;
            iVar6 = 0;
            cVar1 = s___97c2dd14[0];
            while (cVar1 != '\0') {
              local_60[iVar6] = cVar1;
              cVar1 = "}"[iVar6 + 1];
              iVar6 = iVar6 + 1;
            }
            goto LAB_97c040c8;
          default:
            goto switchD_97c02904_caseD_0;
          }
          break;
        case 0x12:
          iVar6 = 0;
          cVar1 = s_normalscale_97c2dd4c[0];
          while (cVar1 != '\0') {
            local_60[iVar6] = cVar1;
            cVar1 = "normalscale"[iVar6 + 1];
            iVar6 = iVar6 + 1;
          }
        }
        local_60 = local_60 + iVar6;
switchD_97c02904_caseD_0:
        if (piVar13[*(ushort *)((int)param_1 + iVar8 + iVar17 * 8 + 6)] == -1) {
          iVar8 = 0;
          cVar1 = s___97c2d8f8[0];
          while (cVar1 != '\0') {
            local_60[iVar8] = cVar1;
            cVar1 = ";\n"[iVar8 + 1];
            iVar8 = iVar8 + 1;
          }
        }
        else if (iVar11 + 1 == piVar12[iVar18]) {
          iVar18 = iVar18 + 1;
          iVar8 = 0;
          cVar1 = s____97c2dd58[0];
          while (cVar1 != '\0') {
            local_60[iVar8] = cVar1;
            cVar1 = "\n};\n"[iVar8 + 1];
            iVar8 = iVar8 + 1;
          }
        }
        else {
          iVar8 = 0;
          cVar1 = s___97c2dd60[0];
          while (cVar1 != '\0') {
            local_60[iVar8] = cVar1;
            cVar1 = ",\n"[iVar8 + 1];
            iVar8 = iVar8 + 1;
          }
        }
        local_60 = local_60 + iVar8;
        iVar8 = _adjustAllocation(&local_68,&local_64,&local_60);
        if (iVar8 == 0) {
          if (pvVar14 != (void *)0x0) {
            _free(pvVar14);
          }
          pcVar9 = local_64;
          if (piVar13 != (int *)0x0) {
            _free(piVar13);
            pcVar9 = local_64;
          }
          goto joined_r0x97c02488;
        }
LAB_97c04238:
        iVar19 = iVar19 + 1;
      } while (iVar19 < iVar5);
    }
    if (piVar12 != (int *)0x0) {
      _free(piVar12);
    }
  }
  iVar17 = param_1[0xc];
  iVar5 = 0;
  iVar11 = param_1[0xd];
  if (0 < iVar17) {
    do {
      uVar21 = (uint)param_1[iVar11 * 2 + iVar5 * 2] >> 0x10 & 0xf;
      if (uVar21 == 0) goto LAB_97c04904;
      iVar18 = 0;
      cVar1 = s_OUTPUT_res_97c2dd64[0];
      while (cVar1 != '\0') {
        local_60[iVar18] = cVar1;
        cVar1 = "OUTPUT res"[iVar18 + 1];
        iVar18 = iVar18 + 1;
      }
      local_60 = local_60 + iVar18;
      iVar19 = _ncpy(local_60,*(undefined2 *)((int)param_1 + iVar5 * 8 + iVar11 * 8 + 6));
      iVar18 = 0;
      cVar1 = s___97c2db68[0];
      while (cVar1 != '\0') {
        local_60[iVar18 + iVar19] = cVar1;
        cVar1 = " = "[iVar18 + 1];
        iVar18 = iVar18 + 1;
      }
      local_60 = local_60 + iVar18 + iVar19;
      switch(uVar21) {
      default:
        goto switchD_97c04350_caseD_0;
      case 1:
        iVar18 = 0;
        cVar1 = s_result_position_97c2dd94[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "result.position"[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
        break;
      case 2:
        iVar18 = 0;
        cVar1 = s_result_fogcoord_97c2dda4[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "result.fogcoord"[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
        break;
      case 3:
        iVar18 = 0;
        cVar1 = s_result_pointsize_97c2ddb4[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "result.pointsize"[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
        break;
      case 4:
        iVar18 = 0;
        cVar1 = s_result_color_97c2ddc8[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "result.color"[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
        local_60 = local_60 + iVar18;
        if (iVar15 == 0x8b31) {
          if ((param_1[iVar11 * 2 + iVar5 * 2] & 1U) == 0) {
            iVar18 = 0;
            cVar1 = s__front_primary_97c2ddd8[0];
            while (cVar1 != '\0') {
              local_60[iVar18] = cVar1;
              cVar1 = ".front.primary"[iVar18 + 1];
              iVar18 = iVar18 + 1;
            }
          }
          else {
            if ((param_1[iVar11 * 2 + iVar5 * 2] & 1U) != 1) goto switchD_97c04350_caseD_0;
            iVar18 = 0;
            cVar1 = s__back_primary_97c2dde8[0];
            while (cVar1 != '\0') {
              local_60[iVar18] = cVar1;
              cVar1 = ".back.primary"[iVar18 + 1];
              iVar18 = iVar18 + 1;
            }
          }
          break;
        }
        if ((iVar15 == 0x8b30) && (1 < ((uint)param_1[iVar11 * 2 + iVar5 * 2] >> 1 & 7))) {
          iVar18 = 0;
          cVar1 = s___97c29860[0];
          while (cVar1 != '\0') {
            local_60[iVar18] = cVar1;
            cVar1 = "["[iVar18 + 1];
            iVar18 = iVar18 + 1;
          }
          local_60 = local_60 + iVar18;
          iVar18 = _ncpy(local_60,(uint)param_1[iVar11 * 2 + iVar5 * 2] >> 1 & 7);
          local_60 = local_60 + iVar18;
          iVar18 = 0;
          cVar1 = s___97c2d770[0];
          while (cVar1 != '\0') {
            local_60[iVar18] = cVar1;
            cVar1 = "]"[iVar18 + 1];
            iVar18 = iVar18 + 1;
          }
          goto LAB_97c04808;
        }
        goto switchD_97c04350_caseD_0;
      case 5:
        iVar18 = 0;
        cVar1 = s_result_color_97c2ddc8[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "result.color"[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
        local_60 = local_60 + iVar18;
        if (iVar15 == 0x8b31) {
          if ((param_1[iVar11 * 2 + iVar5 * 2] & 1U) == 0) {
            iVar18 = 0;
            cVar1 = s__front_secondary_97c2ddf8[0];
            while (cVar1 != '\0') {
              local_60[iVar18] = cVar1;
              cVar1 = ".front.secondary"[iVar18 + 1];
              iVar18 = iVar18 + 1;
            }
          }
          else {
            if ((param_1[iVar11 * 2 + iVar5 * 2] & 1U) != 1) goto switchD_97c04350_caseD_0;
            iVar18 = 0;
            cVar1 = s__back_secondary_97c2de0c[0];
            while (cVar1 != '\0') {
              local_60[iVar18] = cVar1;
              cVar1 = ".back.secondary"[iVar18 + 1];
              iVar18 = iVar18 + 1;
            }
          }
          break;
        }
        goto switchD_97c04350_caseD_0;
      case 6:
        iVar18 = 0;
        cVar1 = s_result_texcoord__97c2de1c[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "result.texcoord["[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
        local_60 = local_60 + iVar18;
        iVar18 = _ncpy(local_60,param_1[iVar11 * 2 + iVar5 * 2] & 0x1f);
        local_60 = local_60 + iVar18;
        iVar18 = 0;
        cVar1 = s___97c2d770[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "]"[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
        goto LAB_97c04808;
      case 7:
        iVar18 = 0;
        cVar1 = s_result_depth_97c2de30[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "result.depth"[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
        break;
      case 8:
        iVar18 = 0;
        cVar1 = s_result_eyePosition_97c2de50[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "result.eyePosition"[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
        break;
      case 9:
        iVar18 = 0;
        cVar1 = s_result_clipVertex_97c2de64[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "result.clipVertex"[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
        break;
      case 10:
        iVar18 = 0;
        cVar1 = s_result_attrib__97c2de40[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "result.attrib["[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
        local_60 = local_60 + iVar18;
        iVar18 = _ncpy(local_60,param_1[iVar11 * 2 + iVar5 * 2] & 0x1f);
        local_60 = local_60 + iVar18;
        iVar18 = 0;
        cVar1 = s___97c2d770[0];
        while (cVar1 != '\0') {
          local_60[iVar18] = cVar1;
          cVar1 = "]"[iVar18 + 1];
          iVar18 = iVar18 + 1;
        }
LAB_97c04808:
        local_60 = local_60 + iVar18;
        goto switchD_97c04350_caseD_0;
      }
      local_60 = local_60 + iVar18;
switchD_97c04350_caseD_0:
      iVar18 = 0;
      cVar1 = s___97c2d8f8[0];
      while (cVar1 != '\0') {
        local_60[iVar18] = cVar1;
        cVar1 = ";\n"[iVar18 + 1];
        iVar18 = iVar18 + 1;
      }
      local_60 = local_60 + iVar18;
      iVar18 = _adjustAllocation(&local_68,&local_64,&local_60);
      if (iVar18 == 0) {
        piVar12 = piVar13;
        pcVar9 = local_64;
        if (pvVar14 != (void *)0x0) {
          _free(pvVar14);
          pcVar9 = local_64;
        }
        goto joined_r0x97c02488;
      }
LAB_97c04904:
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar17);
  }
  iVar11 = 0;
  cVar1 = s__97c26c38[0];
  while (cVar1 != '\0') {
    local_60[iVar11] = cVar1;
    cVar1 = "\n"[iVar11 + 1];
    iVar11 = iVar11 + 1;
  }
  local_60 = local_60 + iVar11;
  local_48[0] = _malloc(local_68);
  pcVar9 = local_64;
  if (local_48[0] != (char *)0x0) {
    iVar15 = param_1[0x14];
    iVar17 = 0;
    iVar11 = param_1[0x15];
    iVar5 = 0;
    local_4c = local_48[0];
    if (0 < iVar15) {
      do {
        iVar18 = ((int (*)())_glpDisassemble2Op)(param_1 + iVar11 * 2 + iVar5 * 2,local_48[0],&local_58,&local_54
                                    ,pvVar14,piVar13,0,&local_50);
        if (iVar18 == -1) {
LAB_97c04a0c:
          if (pvVar14 != (void *)0x0) {
            _free(pvVar14);
          }
          if (piVar13 != (int *)0x0) {
            _free(piVar13);
          }
          goto LAB_97c04ab8;
        }
        local_48[0] = local_48[0] + local_54;
        iVar5 = iVar5 + local_58;
        iVar18 = _adjustAllocation(&local_68,&local_4c,local_48);
        if (iVar18 == 0) goto LAB_97c04a0c;
        iVar17 = iVar17 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar17 < iVar15);
    }
    if (pvVar14 != (void *)0x0) {
      _free(pvVar14);
    }
    if (piVar13 != (int *)0x0) {
      _free(piVar13);
    }
    iVar11 = 0;
    cVar1 = s_END_97c2de98[0];
    while (cVar1 != '\0') {
      local_48[0][iVar11] = cVar1;
      cVar1 = "END\n"[iVar11 + 1];
      iVar11 = iVar11 + 1;
    }
    local_48[0] = local_48[0] + iVar11;
    pcVar9 = _malloc(local_68);
    if (pcVar9 == (char *)0x0) {
LAB_97c04ab8:
      _free(local_64);
      pcVar9 = local_4c;
    }
    else {
      if (*param_1 == 0x8b30) {
        iVar11 = 0;
        cVar1 = s___ARBfp1_0_97c2f848[0];
        while (cVar1 != '\0') {
          pcVar9[iVar11] = cVar1;
          cVar1 = "!!ARBfp1.0\n\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else if (*param_1 == 0x8b31) {
        iVar11 = 0;
        cVar1 = s___ARBvp1_0_97c2f838[0];
        while (cVar1 != '\0') {
          pcVar9[iVar11] = cVar1;
          cVar1 = "!!ARBvp1.0\n\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      else {
        iVar11 = 0;
        cVar1 = s_Unknown_Target__error__97c2f858[0];
        while (cVar1 != '\0') {
          pcVar9[iVar11] = cVar1;
          cVar1 = "Unknown Target (error)\n\n"[iVar11 + 1];
          iVar11 = iVar11 + 1;
        }
      }
      pcVar10 = _malloc(local_68);
      if (pcVar10 != (char *)0x0) {
        pvVar14 = _malloc((size_t)(pcVar9 + iVar11 +
                                  (int)(local_60 +
                                       (int)(local_48[0] +
                                            ((-(int)local_64 - (int)pcVar9) - (int)local_4c) + 1))))
        ;
        pcVar9[iVar11] = '\0';
        iVar11 = 0;
        *local_60 = '\0';
        *pcVar10 = '\0';
        *local_48[0] = '\0';
        cVar1 = *pcVar9;
        while (cVar1 != '\0') {
          *(char *)((int)pvVar14 + iVar11) = cVar1;
          iVar11 = iVar11 + 1;
          cVar1 = pcVar9[iVar11];
        }
        iVar15 = 0;
        cVar1 = *local_64;
        while (cVar1 != '\0') {
          *(char *)((int)pvVar14 + iVar15 + iVar11) = cVar1;
          iVar15 = iVar15 + 1;
          cVar1 = local_64[iVar15];
        }
        iVar17 = 0;
        cVar1 = *pcVar10;
        while (cVar1 != '\0') {
          *(char *)((int)pvVar14 + iVar17 + iVar15 + iVar11) = cVar1;
          iVar17 = iVar17 + 1;
          cVar1 = pcVar10[iVar17];
        }
        iVar17 = iVar17 + iVar15 + iVar11;
        iVar11 = 0;
        cVar1 = *local_4c;
        while (cVar1 != '\0') {
          *(char *)((int)pvVar14 + iVar11 + iVar17) = cVar1;
          iVar11 = iVar11 + 1;
          cVar1 = local_4c[iVar11];
        }
        *(undefined1 *)((int)pvVar14 + iVar11 + iVar17) = 0;
        _free(pcVar9);
        _free(local_64);
        _free(pcVar10);
        _free(local_4c);
        return pvVar14;
      }
      _free(local_64);
      _free(local_4c);
    }
  }
LAB_97c04d50:
  _free(pcVar9);
  return (void *)0x0;
}

/* _glpPPShaderToProgram @ 0x97c057a4 (472 bytes) */
int _glpPPShaderToProgram(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  void *pvVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  size_t local_30 [5];
  
  _memset(&local_70,0,0x3c);
  pvVar1 = (void *)((int (*)())_glpPPShaderToProgramString)(param_1,param_2,param_3);
  iVar5 = 0;
  pvVar2 = (void *)0x0;
  if (pvVar1 != (void *)0x0) {
    if (*param_1 == 0x8b30) {
      iVar5 = _PPParserCreate(2);
      local_60 = 0x100;
      local_64 = 0x8000;
      local_5c = 0x80;
      local_58 = 0x40;
      local_54 = 0;
      local_70 = 0x80;
      local_6c = 0x80;
      local_38 = 0;
    }
    else if (*param_1 == 0x8b31) {
      iVar5 = _PPParserCreate(0);
      local_38 = 0x10;
      local_64 = 0x8000;
      local_5c = 0x100;
      local_58 = 0x20;
      local_54 = 2;
      local_70 = 0x100;
      local_6c = 0x100;
      local_60 = 0x100;
    }
    uVar3 = _PPStreamCreate();
    _PPParserAttachStream(iVar5,uVar3);
    local_4c = 0x10;
    local_48 = 4;
    local_44 = 1;
    local_40 = 6;
    local_3c = 8;
    local_68 = 8;
    local_50 = 8;
    _memcpy((void *)(iVar5 + 0x450),&local_70,0x3c);
    _PPParserAttachString(iVar5,pvVar1,1);
    iVar4 = _PPParserParse(iVar5);
    pvVar2 = (void *)0x0;
    if (iVar4 == 0) {
      _PPStreamGetStream(uVar3,0,local_30);
      pvVar2 = _calloc(local_30[0],8);
      _PPStreamGetStream(uVar3,pvVar2,local_30);
      _PPStreamFree(uVar3);
      _PPParserFree(iVar5);
      _free(pvVar1);
    }
  }
  return pvVar2;
}

/* _glpFreePPShaderToProgram @ 0x97c0597c (12 bytes) */
int _glpFreePPShaderToProgram(param_1)
  void *param_1;
{
  if (param_1 == (void *)0x0) {
    return;
  }
  _free(param_1);
  return;
}

/* _glpUniformToFloat @ 0x97c05988 (344 bytes) */
int _glpUniformToFloat(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  float *param_3;
  float *param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  double dVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  dVar6 = DOUBLE_97c30a58;
  if (param_1 != 0) {
    iVar8 = *(int *)(param_1 + 0x28);
    bVar4 = false;
    bVar5 = false;
    param_1 = param_1 + *(int *)(param_1 + 0x2c) * 8;
    if (iVar8 != 0) {
      iVar9 = 0;
      if (0 < iVar8) {
        do {
          uVar7 = *(uint *)(param_1 + iVar9 * 8);
          if (((uVar7 >> 0x10 & 0x1f) == 1) && ((uVar7 & 0xffff) == param_2)) {
            bVar4 = true;
            if ((-1 < *(int *)(iVar9 * 8 + param_1 + 4)) && ((uVar7 >> 0x1a & 7) != 1)) {
              bVar5 = true;
            }
            break;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < iVar8);
      }
      if (bVar4) {
        if (bVar5) {
          *param_4 = (float)((double)CONCAT44(0x43300000,-*param_3) - DOUBLE_97c30a58);
          param_4[1] = (float)((double)CONCAT44(0x43300000,-param_3[1]) - dVar6);
          param_4[2] = (float)((double)CONCAT44(0x43300000,-param_3[2]) - dVar6);
          param_4[3] = (float)((double)CONCAT44(0x43300000,-param_3[3]) - dVar6);
        }
        else {
          fVar1 = *param_3;
          fVar2 = param_3[1];
          fVar3 = param_3[2];
          param_4[3] = param_3[3];
          *param_4 = fVar1;
          param_4[1] = fVar2;
          param_4[2] = fVar3;
        }
      }
    }
  }
  return;
}

/* _glpUniformsToFloats @ 0x97c05ae0 (144 bytes) */
int _glpUniformsToFloats(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != 0) {
    iVar4 = *(int *)(param_1 + 0x28);
    iVar2 = *(int *)(param_1 + 0x2c);
    if ((iVar4 != 0) && (iVar5 = 0, 0 < iVar4)) {
      do {
        uVar3 = *(uint *)(param_1 + iVar2 * 8 + iVar5 * 8);
        if ((uVar3 >> 0x10 & 0x1f) == 1) {
          uVar3 = uVar3 & 0xffff;
          iVar1 = uVar3 * 0x10;
          ((int (*)())_glpUniformToFloat)(param_1,uVar3,param_2 + iVar1,param_3 + iVar1);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar4);
    }
  }
  return;
}

/* _handleDigit_97c05b70 @ 0x97c05b70 (112 bytes) */
int _handleDigit_97c05b70(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 / 10;
  if (iVar1 != 0) {
    ((int (*)())_handleDigit)(param_1,iVar1);
  }
  *(char *)*param_1 = (char)param_2 + (char)iVar1 * -10 + '0';
  *param_1 = *param_1 + 1;
  return;
}

/* _clearFuncInfoList @ 0x97c05be0 (68 bytes) */
int _clearFuncInfoList(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_2 != 0) {
    do {
      iVar1 = iVar3 * 0x20;
      iVar3 = iVar3 + 1;
      iVar2 = iVar1 + param_1;
      *(undefined4 *)(param_1 + iVar1) = 0xffffffff;
      *(undefined4 *)(iVar2 + 0x14) = 0;
      *(undefined4 *)(iVar2 + 4) = 0xffffffff;
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined4 *)(iVar2 + 0xc) = 0;
      *(undefined4 *)(iVar2 + 0x10) = 0;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    return;
  }
  return;
}

/* _UpdateFunctionIndex @ 0x97c05c24 (60 bytes) */
int _UpdateFunctionIndex(param_1, param_2, param_3, param_4)
  uint param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  uint uVar1;
  
  uVar1 = 0;
  if (param_4 != 0) {
    do {
      if (param_2 == *(int *)(param_3 + uVar1 * 0x20)) break;
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_4);
  }
  if (uVar1 == param_4) {
    uVar1 = param_1;
  }
  return uVar1;
}

/* _RecordFunctionCall @ 0x97c05c60 (188 bytes) */
int _RecordFunctionCall(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  uint param_3;
{
  void *pvVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      if (param_1 == *(int *)(uVar2 * 0x20 + *param_2)) break;
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_3);
  }
  if (uVar2 == param_3) {
    if ((param_3 & 0x7f) == 0) {
      pvVar1 = _malloc(param_3 * 0x20 + 0x1000);
      ((int (*)())_clearFuncInfoList)(pvVar1,param_3 + 0x80);
      _memcpy(pvVar1,(void *)*param_2,param_3 * 0x20);
      if ((void *)*param_2 != (void *)0x0) {
        _free((void *)*param_2);
      }
      *param_2 = (int)pvVar1;
    }
    param_3 = param_3 + 1;
    *(int *)(uVar2 * 0x20 + *param_2) = param_1;
  }
  return param_3;
}

/* _RecordFunctionEdge @ 0x97c05d1c (72 bytes) */
int _RecordFunctionEdge(param_1, param_2, param_3, param_4, param_5)
  uint param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  uint param_5;
{
  uint uVar1;
  
  uVar1 = 0;
  if (param_5 == 0) {
    return param_1;
  }
  do {
    if (param_2 == *(int *)(param_4 + uVar1 * 0x20)) {
      if (-1 < (int)param_1) {
        *(undefined4 *)(param_1 * 0x20 + param_4 + 4) = param_3;
      }
      return uVar1;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < param_5);
  return param_1;
}

/* _ClearJumpTable @ 0x97c05d64 (92 bytes) */
int _ClearJumpTable(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0xc) != 0) {
    _free(*(void **)(param_1 + 0x10));
    _free(*(void **)(param_1 + 0x14));
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    *(undefined4 *)(param_1 + 0x14) = 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}

/* _AddOpToJumpTable @ 0x97c05dc0 (396 bytes) */
int _AddOpToJumpTable(param_1, param_2)
  uint *param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  
  *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
  uVar4 = *param_1;
  switch(uVar4 >> 0x12 & 0xff) {
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
    uVar2 = *(uint *)(param_2 + 0xc);
    if ((uVar2 & 0x7f) == 0) {
      pvVar3 = _malloc(uVar2 * 4 + 0x200);
      _memset(pvVar3,0,*(int *)(param_2 + 0xc) * 4 + 0x200);
      uVar2 = 0;
      uVar4 = 0;
      if (*(int *)(param_2 + 0xc) != 0) {
        do {
          iVar1 = uVar2 * 4;
          uVar2 = uVar2 + 1;
          *(undefined4 *)(iVar1 + (int)pvVar3) = *(undefined4 *)(iVar1 + *(int *)(param_2 + 0x10));
          uVar4 = *(uint *)(param_2 + 0xc);
        } while (uVar2 < uVar4);
      }
      if (*(void **)(param_2 + 0x10) != (void *)0x0) {
        _free(*(void **)(param_2 + 0x10));
        uVar4 = *(uint *)(param_2 + 0xc);
      }
      *(void **)(param_2 + 0x10) = pvVar3;
      pvVar3 = _malloc(uVar4 * 4 + 0x200);
      _memset(pvVar3,0,*(int *)(param_2 + 0xc) * 4 + 0x200);
      uVar4 = 0;
      uVar2 = 0;
      if (*(int *)(param_2 + 0xc) != 0) {
        do {
          iVar1 = uVar4 * 4;
          uVar4 = uVar4 + 1;
          *(undefined4 *)(iVar1 + (int)pvVar3) = *(undefined4 *)(iVar1 + *(int *)(param_2 + 0x14));
          uVar2 = *(uint *)(param_2 + 0xc);
        } while (uVar4 < uVar2);
      }
      if (*(void **)(param_2 + 0x14) != (void *)0x0) {
        _free(*(void **)(param_2 + 0x14));
        uVar2 = *(uint *)(param_2 + 0xc);
      }
      *(void **)(param_2 + 0x14) = pvVar3;
      uVar4 = *param_1;
    }
    *(uint *)(uVar2 * 4 + *(int *)(param_2 + 0x10)) = uVar4 & 0x3ffff;
    *(uint *)(*(int *)(param_2 + 0xc) * 4 + *(int *)(param_2 + 0x14)) = param_1[1] & 0x3ffff;
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
  }
  return;
}

/* _UpdateFunctionTable @ 0x97c05fd0 (68 bytes) */
int _UpdateFunctionTable(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_5 != 0) {
    do {
      iVar1 = iVar2 * 0x20;
      if (param_1 == *(int *)(iVar1 + param_4)) {
        *(undefined4 *)(iVar1 + param_4) = param_2;
      }
      if (param_1 == *(int *)(iVar1 + param_4 + 4)) {
        *(undefined4 *)(iVar1 + param_4 + 4) = param_3;
      }
      iVar2 = iVar2 + 1;
      param_5 = param_5 + -1;
    } while (param_5 != 0);
    return;
  }
  return;
}

/* _FindFunctionIndex @ 0x97c06014 (48 bytes) */
int _FindFunctionIndex(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  uint uVar1;
  
  uVar1 = 0;
  if (param_3 != 0) {
    do {
      if (param_1 == *(int *)(param_2 + uVar1 * 0x20)) {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_3);
  }
  return uVar1;
}

/* _InlineFunctionsBranch @ 0x97c06044 (1488 bytes) */
int _InlineFunctionsBranch(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  bool bVar16;
  uint uVar17;
  int iVar18;
  uint local_90;
  uint local_8c;
  void *local_50 [6];
  
  piVar3 = *(int **)(param_1 + 0x20);
  local_50[0] = (void *)0x0;
  uVar17 = 0;
  iVar15 = *piVar3;
  uVar13 = 0;
  iVar14 = -1;
  if (iVar15 != 0) {
    do {
      uVar7 = *(uint *)(iVar15 + 0xc);
      uVar17 = uVar7 & 0x3ffff;
      if (uVar17 == 0) {
        uVar13 = ((int (*)())_RecordFunctionCall)(0,local_50,uVar13);
        uVar7 = *(uint *)(iVar15 + 0xc);
      }
      if ((uVar7 >> 0x12 & 0xff) == 0x4c) {
        uVar13 = ((int (*)())_RecordFunctionCall)(*(uint *)(iVar15 + 0x10) & 0x3ffff,local_50,uVar13);
      }
      iVar15 = *(int *)(iVar15 + 8);
    } while (iVar15 != 0);
    piVar3 = *(int **)(param_1 + 0x20);
  }
  uVar7 = 0;
  for (iVar15 = *piVar3; iVar15 != 0; iVar15 = *(int *)(iVar15 + 8)) {
    uVar17 = *(uint *)(iVar15 + 0xc) & 0x3ffff;
    iVar14 = ((int (*)())_RecordFunctionEdge)(iVar14,uVar17,uVar7,local_50[0],uVar13);
    ((int (*)())_AddOpToJumpTable)(iVar15 + 0xc,(void *)((int)local_50[0] + iVar14 * 0x20));
    uVar7 = uVar17;
  }
  ((int (*)())_RecordFunctionEdge)(iVar14,0,uVar17,local_50[0],uVar13);
  if (1 < uVar13) {
    piVar3 = *(int **)(param_1 + 0x20);
    iVar15 = *piVar3;
    bVar16 = iVar15 == 0;
    if (!bVar16) {
      do {
        iVar14 = ((int (*)())_UpdateFunctionIndex)(iVar14,*(uint *)(iVar15 + 0xc) & 0x3ffff,local_50[0],uVar13);
        iVar18 = iVar15;
        if ((*(uint *)(iVar15 + 0xc) >> 0x12 & 0xff) == 0x4c) {
          uVar7 = 0xffffffff;
          iVar12 = 0;
          iVar5 = ((int (*)())_FindFunctionIndex)(*(uint *)(iVar15 + 0x10) & 0x3ffff,local_50[0],uVar13);
          uVar10 = *(uint *)(*(int *)(iVar15 + 8) + 0xc);
          uVar17 = *(uint *)(iVar15 + 0xc) & 0x3ffff;
          iVar18 = *(int *)(iVar15 + 4);
          iVar5 = iVar5 * 0x20;
          _PPStreamChunkListRemoveChunk(*(undefined4 *)(param_1 + 0x20),iVar15);
          iVar15 = **(int **)(param_1 + 0x20);
          uVar2 = *(uint *)(iVar15 + 0xc);
          while (*(uint *)(iVar5 + (int)local_50[0]) != (uVar2 & 0x3ffff)) {
            iVar15 = *(int *)(iVar15 + 8);
            uVar2 = *(uint *)(iVar15 + 0xc);
          }
          bVar16 = true;
          iVar6 = iVar18;
          do {
            _memcpy(&local_90,(void *)(iVar15 + 0xc),0x38);
            if (((local_90 >> 0x12 & 0xff) == 0x4d) &&
               ((local_90 & 0x3ffff) != *(uint *)((int)local_50[0] + iVar5 + 4))) {
              local_8c = uVar10 & 0x3ffff | local_8c & 0xfffc0000;
              local_90 = local_90 & 0xfc03ffff | 0x12c0000;
            }
            else if ((local_90 >> 0x12 & 0xff) == 0x4d) {
              local_90 = local_90 & 0xfc03ffff | 0x1b80000;
            }
            uVar8 = 0;
            if ((uVar17 == 0) && (uVar7 == 0xffffffff)) {
              uVar8 = 1;
            }
            iVar6 = ((int (*)())_PPStreamInsertOperationAfterChunk)(param_1,&local_90,iVar15 + 0x44,uVar8,iVar6);
            uVar2 = *(uint *)(iVar6 + 0x10);
            if ((uVar2 & 0x3ffff) != 0) {
              iVar9 = 0;
              iVar4 = **(int **)(param_1 + 0x20);
              uVar11 = *(uint *)(iVar4 + 0xc);
              while (*(uint *)(iVar5 + (int)local_50[0]) != (uVar11 & 0x3ffff)) {
                iVar4 = *(int *)(iVar4 + 8);
                uVar11 = *(uint *)(iVar4 + 0xc);
              }
              bVar1 = true;
              while ((uVar11 & 0x3ffff) != (uVar2 & 0x3ffff)) {
                if ((uVar11 & 0x3ffff) == *(uint *)((int)local_50[0] + iVar5 + 4)) {
                  bVar1 = false;
                }
                iVar4 = *(int *)(iVar4 + 8);
                iVar9 = iVar9 + 1;
                if (!bVar1) goto LAB_97c0638c;
                uVar11 = *(uint *)(iVar4 + 0xc);
              }
              *(uint *)(iVar6 + 0x10) =
                   ((*(uint *)(iVar6 + 0xc) & 0x3ffff) - iVar12) + iVar9 & 0x3ffff |
                   uVar2 & 0xfffc0000;
            }
LAB_97c0638c:
            if (uVar7 == 0xffffffff) {
              uVar7 = *(uint *)(iVar6 + 0xc) & 0x3ffff;
            }
            if ((*(uint *)(iVar15 + 0xc) & 0x3ffff) == *(uint *)((int)local_50[0] + iVar5 + 4)) {
              bVar16 = false;
            }
            iVar15 = *(int *)(iVar15 + 8);
            iVar12 = iVar12 + 1;
          } while (bVar16);
          if (iVar12 < 1) {
            iVar15 = *(int *)(iVar6 + 8);
            if (uVar17 == 0) {
              *(uint *)(iVar15 + 0xc) = *(uint *)(iVar15 + 0xc) & 0xfffc0000;
            }
            uVar7 = *(uint *)(iVar15 + 0xc) & 0x3ffff;
            uVar2 = uVar7;
          }
          else {
            uVar2 = *(uint *)(iVar6 + 0xc) & 0x3ffff;
          }
          bVar16 = iVar18 == 0;
          ((int (*)())_PPStreamChangeBranchTargets)(param_1,uVar17,uVar7);
          ((int (*)())_UpdateFunctionTable)(uVar17,uVar7,uVar2,local_50[0],uVar13);
        }
        iVar15 = iVar14 * 0x20;
        iVar5 = **(int **)(param_1 + 0x20);
        ((int (*)())_ClearJumpTable)((void *)((int)local_50[0] + iVar15));
        uVar17 = *(uint *)(iVar5 + 0xc);
        while (*(uint *)(iVar15 + (int)local_50[0]) != (uVar17 & 0x3ffff)) {
          iVar5 = *(int *)(iVar5 + 8);
          uVar17 = *(uint *)(iVar5 + 0xc);
        }
        if (*(uint *)((int)local_50[0] + iVar15 + 4) != (uVar17 & 0x3ffff)) {
          do {
            ((int (*)())_AddOpToJumpTable)(iVar5 + 0xc,(void *)((int)local_50[0] + iVar15));
            iVar5 = *(int *)(iVar5 + 8);
          } while (*(uint *)((int)local_50[0] + iVar15 + 4) != (*(uint *)(iVar5 + 0xc) & 0x3ffff));
        }
        ((int (*)())_AddOpToJumpTable)(iVar5 + 0xc,(void *)((int)local_50[0] + iVar15));
        if (bVar16) {
          iVar15 = **(int **)(param_1 + 0x20);
        }
        else {
          iVar15 = *(int *)(iVar18 + 8);
        }
        bVar16 = iVar15 == 0;
      } while (!bVar16);
      piVar3 = *(int **)(param_1 + 0x20);
    }
    uVar17 = 0;
    bVar16 = false;
    iVar14 = *piVar3;
    while (iVar15 = iVar14, iVar15 != 0) {
      iVar14 = *(int *)(iVar15 + 8);
      if ((bVar16) || (uVar17 = 0, uVar13 == 0)) {
        uVar7 = *(uint *)(iVar15 + 0xc);
      }
      else {
        uVar7 = *(uint *)(iVar15 + 0xc);
        do {
          uVar2 = *(uint *)(uVar17 * 0x20 + (int)local_50[0]);
          if ((uVar2 != 0) && (uVar2 == (uVar7 & 0x3ffff))) {
            bVar16 = true;
            break;
          }
          uVar17 = uVar17 + 1;
        } while (uVar17 < uVar13);
      }
      if (bVar16) {
        if (*(uint *)((int)local_50[0] + uVar17 * 0x20 + 4) == (uVar7 & 0x3ffff)) {
          bVar16 = false;
        }
        ((int (*)())_PPStreamRemoveLabelsAtOperationIndex)(param_1);
        _PPStreamChunkListRemoveChunk(*(undefined4 *)(param_1 + 0x20),iVar15);
      }
      else if ((uVar7 >> 0x12 & 0xff) == 0x6e) {
        ((int (*)())_PPStreamRemoveOperation)(param_1,iVar15);
      }
    }
  }
  if (local_50[0] != (void *)0x0) {
    uVar17 = 0;
    if (uVar13 != 0) {
      do {
        iVar14 = uVar17 * 0x20;
        uVar17 = uVar17 + 1;
        ((int (*)())_ClearJumpTable)((void *)((int)local_50[0] + iVar14));
      } while (uVar17 < uVar13);
    }
    _free(local_50[0]);
  }
  return;
}

/* _IsParamSampler @ 0x97c06614 (84 bytes) */
int _IsParamSampler(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if ((param_1 == 2) &&
     (iVar1 = _PPStreamChunkListChunkAtIndex(*(undefined4 *)(param_3 + 0x10)),
     (*(uint *)(iVar1 + 0xc) >> 0x10 & 0x1f) == 1)) {
    uVar2 = *(uint *)(iVar1 + 0x10) >> 0x1f;
  }
  return uVar2;
}

/* _GetStreamArray @ 0x97c06668 (152 bytes) */
int _GetStreamArray(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 == 1) {
    for (iVar1 = **(int **)(param_3 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((*(ushort *)(iVar1 + 0xe) <= param_2) && (param_2 <= *(ushort *)(iVar1 + 0x12))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  else if (param_1 == 2) {
    for (iVar1 = **(int **)(param_3 + 0x14); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      if ((*(ushort *)(iVar1 + 0xe) <= param_2) && (param_2 <= *(ushort *)(iVar1 + 0x12))) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    }
  }
  return -1;
}

