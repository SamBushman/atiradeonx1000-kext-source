#include "decls.h"

/* FUN_0000f620 @ 0xf620 (27520 bytes) */
int FUN_0000f620(param_1)
  uint *param_1;
{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  ushort uVar5;
  undefined1 *puVar6;
  int iVar7;
  char acVar9;
  char cVar10;
  int iVar8;
  char *pcVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  undefined1 *puVar15;
  int *piVar16;
  uint uVar17;
  uint uVar18;
  undefined4 uVar19;
  char cVar24;
  uint *puVar20;
  int iVar21;
  undefined4 *puVar22;
  int iVar23;
  uint *puVar25;
  undefined4 uVar26;
  void *pvVar27;
  void *pvVar28;
  int iVar29;
  size_t sVar30;
  uint uVar31;
  uint uVar32;
  void *pvVar33;
  int iVar34;
  int *piVar35;
  uint uVar36;
  float *pfVar37;
  uint uVar38;
  uint uVar39;
  ushort uVar40;
  ulonglong uVar41;
  undefined8 uVar42;
  void *local_88[0];
  undefined1 *local_84;
  int local_80 [2];
  void *local_78;
  uint *local_74;
  void *local_70;
  void *local_6c;
  undefined1 *local_68;
  char *local_64;
  undefined1 *local_60;
  undefined1 **local_5c;
  int *local_58;
  undefined1 *local_54;
  
  local_80[0] = 0x800;
  local_88[0] = _malloc(0x800);
  if (local_88[0] == (void *)0x0) {
    return (void *)0x0;
  }
  uVar32 = *param_1;
  uVar1 = (uint)(uVar32 - 0x8b30 < 2);
  if (uVar32 == 0x8804) {
    iVar7 = 0;
    if (s___ARBfp1_0_001a4584[0] != '\0') {
      pcVar11 = "!!ARBfp1.0\n";
      cVar24 = s___ARBfp1_0_001a4584[0];
      do {
        pcVar11 = pcVar11 + 1;
        cVar10 = *pcVar11;
        *(char *)((int)local_88[0] + iVar7) = cVar24;
        iVar7 = iVar7 + 1;
        cVar24 = cVar10;
      } while (cVar10 != '\0');
    }
  }
  else if (uVar32 < 0x8805) {
    if (uVar32 == 0x8620) {
      iVar7 = 0;
      if (s___ARBvp1_0_001a4564[0] != '\0') {
        pcVar11 = "!!ARBvp1.0\n";
        cVar24 = s___ARBvp1_0_001a4564[0];
        do {
          pcVar11 = pcVar11 + 1;
          cVar10 = *pcVar11;
          *(char *)((int)local_88[0] + iVar7) = cVar24;
          iVar7 = iVar7 + 1;
          cVar24 = cVar10;
        } while (cVar10 != '\0');
      }
    }
    else {
LAB_0000f6a4:
      if (s_Unkown_Target__error__001a45a8[0] == '\0') {
        iVar7 = 0;
      }
      else {
        pcVar11 = "Unkown Target (error)\n";
        iVar7 = 0;
        cVar24 = s_Unkown_Target__error__001a45a8[0];
        do {
          pcVar11 = pcVar11 + 1;
          cVar10 = *pcVar11;
          *(char *)((int)local_88[0] + iVar7) = cVar24;
          iVar7 = iVar7 + 1;
          cVar24 = cVar10;
        } while (cVar10 != '\0');
      }
    }
  }
  else if (uVar32 == 0x8b30) {
    iVar7 = 0;
    if (s___ARBfragmentshader_001a4590[0] != '\0') {
      pcVar11 = "!!ARBfragmentshader\n";
      cVar24 = s___ARBfragmentshader_001a4590[0];
      do {
        pcVar11 = pcVar11 + 1;
        cVar10 = *pcVar11;
        *(char *)((int)local_88[0] + iVar7) = cVar24;
        iVar7 = iVar7 + 1;
        cVar24 = cVar10;
      } while (cVar10 != '\0');
    }
  }
  else {
    if (uVar32 != 0x8b31) goto LAB_0000f6a4;
    iVar7 = 0;
    if (s___ARBvertexshader_001a4570[0] != '\0') {
      pcVar11 = "!!ARBvertexshader\n";
      cVar24 = s___ARBvertexshader_001a4570[0];
      do {
        pcVar11 = pcVar11 + 1;
        cVar10 = *pcVar11;
        *(char *)((int)local_88[0] + iVar7) = cVar24;
        iVar7 = iVar7 + 1;
        cVar24 = cVar10;
      } while (cVar10 != '\0');
    }
  }
  local_84 = (undefined1 *)(iVar7 + (int)local_88[0]);
  bVar3 = uVar1 == 0;
  if (!bVar3) {
    local_54 = ((unsigned char *)0x0019f634);
    iVar7 = 0;
    if (s__001a45c0[0] != '\0') {
      pcVar11 = "\n";
      iVar7 = 0;
      cVar24 = s__001a45c0[0];
      do {
        pcVar11 = pcVar11 + 1;
        local_84[iVar7] = cVar24;
        iVar7 = iVar7 + 1;
        cVar24 = *pcVar11;
      } while (cVar24 != '\0');
    }
    local_84 = local_84 + iVar7;
  }
  uVar36 = param_1[0x12];
  puVar13 = param_1 + param_1[0x13] * 2;
  if (0 < (int)uVar36) {
    local_5c = &local_84;
    local_58 = local_80;
    uVar38 = 0;
    do {
      iVar7 = 0;
      if (s_OPTION_001a45c4[0] != '\0') {
        pcVar11 = "OPTION ";
        iVar7 = 0;
        cVar24 = s_OPTION_001a45c4[0];
        do {
          pcVar11 = pcVar11 + 1;
          local_84[iVar7] = cVar24;
          iVar7 = iVar7 + 1;
          cVar24 = *pcVar11;
        } while (cVar24 != '\0');
      }
      local_84 = local_84 + iVar7;
      switch((char)*puVar13) {
      case '\0':
        iVar7 = 0;
        if (s_ARB_position_invariant_001a45cc[0] != '\0') {
          pcVar11 = "ARB_position_invariant";
          cVar24 = s_ARB_position_invariant_001a45cc[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\x01':
        iVar7 = 0;
        if (s_ARB_fog_exp_001a45e4[0] != '\0') {
          pcVar11 = "ARB_fog_exp";
          cVar24 = s_ARB_fog_exp_001a45e4[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\x02':
        iVar7 = 0;
        if (s_ARB_fog_exp2_001a45f0[0] != '\0') {
          pcVar11 = "ARB_fog_exp2";
          cVar24 = s_ARB_fog_exp2_001a45f0[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\x03':
        iVar7 = 0;
        if (s_ARB_fog_linear_001a4600[0] != '\0') {
          pcVar11 = "ARB_fog_linear";
          cVar24 = s_ARB_fog_linear_001a4600[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\x04':
        iVar7 = 0;
        if (s_ARB_precision_hint_fastest_001a4610[0] != '\0') {
          pcVar11 = "ARB_precision_hint_fastest";
          cVar24 = s_ARB_precision_hint_fastest_001a4610[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\x05':
        iVar7 = 0;
        if (s_ARB_precision_hint_nicest_001a462c[0] != '\0') {
          pcVar11 = "ARB_precision_hint_nicest";
          cVar24 = s_ARB_precision_hint_nicest_001a462c[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\x06':
        iVar7 = 0;
        if (s_APPLE_no_runtime_compile_001a4648[0] != '\0') {
          pcVar11 = "APPLE_no_runtime_compile";
          cVar24 = s_APPLE_no_runtime_compile_001a4648[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\a':
        iVar7 = 0;
        if (s_APPLE_no_altivec_001a4664[0] != '\0') {
          pcVar11 = "APPLE_no_altivec";
          cVar24 = s_APPLE_no_altivec_001a4664[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\b':
        iVar7 = 0;
        if (s_NV_fragment_program_001a4678[0] != '\0') {
          pcVar11 = "NV_fragment_program";
          cVar24 = s_NV_fragment_program_001a4678[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\t':
        iVar7 = 0;
        if (s_NV_fragment_program2_001a468c[0] != '\0') {
          pcVar11 = "NV_fragment_program2";
          cVar24 = s_NV_fragment_program2_001a468c[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\n':
        iVar7 = 0;
        if (s_NV_vertex_program2_001a46c0[0] != '\0') {
          pcVar11 = "NV_vertex_program2";
          cVar24 = s_NV_vertex_program2_001a46c0[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\v':
        iVar7 = 0;
        if (s_NV_vertex_program3_001a46d4[0] != '\0') {
          pcVar11 = "NV_vertex_program3";
          cVar24 = s_NV_vertex_program3_001a46d4[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\f':
        iVar7 = 0;
        if (s_ARB_draw_buffers_001a46e8[0] != '\0') {
          pcVar11 = "ARB_draw_buffers";
          cVar24 = s_ARB_draw_buffers_001a46e8[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case '\r':
        iVar7 = 0;
        if (s_ARB_fragment_program_shadow_001a46a4[0] != '\0') {
          pcVar11 = "ARB_fragment_program_shadow";
          cVar24 = s_ARB_fragment_program_shadow_001a46a4[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      default:
        goto switchD_0000f958_default;
      }
      local_84 = local_84 + iVar7;
switchD_0000f958_default:
      iVar7 = 0;
      if (s___001a46fc[0] != '\0') {
        pcVar11 = ";\n";
        iVar7 = 0;
        cVar24 = s___001a46fc[0];
        do {
          pcVar11 = pcVar11 + 1;
          local_84[iVar7] = cVar24;
          iVar7 = iVar7 + 1;
          cVar24 = *pcVar11;
        } while (cVar24 != '\0');
      }
      local_84 = local_84 + iVar7;
      iVar7 = FUN_0000c8a0(local_58,&local_88,local_5c);
      if (iVar7 == 0) goto LAB_00016630;
      uVar38 = uVar38 + 1;
      puVar13 = puVar13 + 2;
    } while (uVar36 != uVar38);
  }
  if ((uVar36 != 0) && (!bVar3)) {
    iVar7 = 0;
    if (s__001a45c0[0] != '\0') {
      pcVar11 = "\n";
      iVar7 = 0;
      cVar24 = s__001a45c0[0];
      do {
        pcVar11 = pcVar11 + 1;
        local_84[iVar7] = cVar24;
        iVar7 = iVar7 + 1;
        cVar24 = *pcVar11;
      } while (cVar24 != '\0');
    }
    local_84 = local_84 + iVar7;
  }
  uVar36 = param_1[6];
  if (uVar36 != 0) {
    iVar7 = 0;
    if (s_ADDRESS_adr0_001a4700[0] != '\0') {
      pcVar11 = "ADDRESS adr0";
      cVar24 = s_ADDRESS_adr0_001a4700[0];
      do {
        pcVar11 = pcVar11 + 1;
        local_84[iVar7] = cVar24;
        iVar7 = iVar7 + 1;
        cVar24 = *pcVar11;
      } while (cVar24 != '\0');
    }
    local_84 = local_84 + iVar7;
    if (1 < (int)uVar36) {
      uVar38 = 1;
      do {
        iVar7 = 0;
        if (s___adr_001a4710[0] != '\0') {
          pcVar11 = ", adr";
          iVar7 = 0;
          cVar24 = s___adr_001a4710[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar7;
        uVar39 = uVar38 + 1;
        iVar7 = FUN_0000cdf0(local_84,uVar38);
        local_84 = local_84 + iVar7;
        uVar38 = uVar39;
      } while (uVar36 != uVar39);
    }
    iVar7 = 0;
    if (s___001a46fc[0] != '\0') {
      pcVar11 = ";\n";
      cVar24 = s___001a46fc[0];
      do {
        pcVar11 = pcVar11 + 1;
        local_84[iVar7] = cVar24;
        iVar7 = iVar7 + 1;
        cVar24 = *pcVar11;
      } while (cVar24 != '\0');
    }
    local_84 = local_84 + iVar7;
    iVar7 = FUN_0000c8a0(local_80,&local_88,&local_84);
    if (iVar7 == 0) goto LAB_00016630;
    if (!bVar3) {
      iVar7 = 0;
      if (s__001a45c0[0] != '\0') {
        pcVar11 = "\n";
        iVar7 = 0;
        cVar24 = s__001a45c0[0];
        do {
          pcVar11 = pcVar11 + 1;
          local_84[iVar7] = cVar24;
          iVar7 = iVar7 + 1;
          cVar24 = *pcVar11;
        } while (cVar24 != '\0');
      }
      local_84 = local_84 + iVar7;
    }
  }
  uVar36 = param_1[4];
  puVar13 = param_1 + param_1[5] * 2;
  if (bVar3) {
    if (0 < (int)uVar36) {
      pvVar27 = (void *)0x0;
      pvVar28 = (void *)0x0;
      pvVar33 = (void *)0x0;
LAB_0001025c:
      local_58 = local_80;
      local_5c = &local_84;
      iVar29 = 0;
      uVar38 = 0;
      iVar7 = -1;
      do {
        puVar12 = puVar13 + uVar38 * 2;
        uVar39 = puVar13[uVar38 * 2] >> 0x1d;
        if (uVar39 == 1) {
          iVar21 = 0;
          if (s_LONG_TEMP_001a4720[0] != '\0') {
            pcVar11 = "LONG TEMP ";
            cVar24 = s_LONG_TEMP_001a4720[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
LAB_00010394:
          local_84 = local_84 + iVar21;
        }
        else {
          if (uVar39 == 2) {
            iVar21 = 0;
            if (s_SHORT_TEMP_001a472c[0] != '\0') {
              pcVar11 = "SHORT TEMP ";
              cVar24 = s_SHORT_TEMP_001a472c[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar21] = cVar24;
                iVar21 = iVar21 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            goto LAB_00010394;
          }
          if (uVar39 == 0) {
            iVar21 = 0;
            if (s_TEMP_001a4718[0] != '\0') {
              pcVar11 = "TEMP ";
              cVar24 = s_TEMP_001a4718[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar21] = cVar24;
                iVar21 = iVar21 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            goto LAB_00010394;
          }
        }
        uVar39 = *puVar12;
        do {
          if (bVar3) {
            iVar21 = 0;
            if (s_tmp_001a4460[0] != '\0') {
              pcVar11 = "tmp";
              cVar24 = s_tmp_001a4460[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar21] = cVar24;
                iVar21 = iVar21 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            local_84 = local_84 + iVar21;
            iVar21 = FUN_0000cdf0(local_84,*(undefined2 *)((int)puVar12 + 6));
            local_84 = local_84 + iVar21;
          }
          else {
            iVar21 = *(int *)((int)pvVar28 + (uint)*(ushort *)((int)puVar12 + 6) * 4);
            if (iVar21 == -1) {
              iVar21 = 0;
              if (s_tmp_001a4460[0] != '\0') {
                pcVar11 = "tmp";
                cVar24 = s_tmp_001a4460[0];
                do {
                  pcVar11 = pcVar11 + 1;
                  local_84[iVar21] = cVar24;
                  iVar21 = iVar21 + 1;
                  cVar24 = *pcVar11;
                } while (cVar24 != '\0');
              }
              local_84 = local_84 + iVar21;
              iVar21 = FUN_0000cdf0(local_84,*(undefined4 *)
                                              ((int)pvVar27 +
                                              (uint)*(ushort *)((int)puVar12 + 6) * 4));
              local_84 = local_84 + iVar21;
              uVar18 = *puVar12;
              local_84 = (undefined1 *)
                         FUN_0000ce90(local_84,uVar18 >> 0x18 & 3,0,uVar18 >> 0x1a & 7,
                                      uVar18 >> 0x1d);
            }
            else {
              if (iVar21 == 0) {
                iVar7 = 0;
                if (s_tmp_001a4460[0] != '\0') {
                  pcVar11 = "tmp";
                  cVar24 = s_tmp_001a4460[0];
                  do {
                    pcVar11 = pcVar11 + 1;
                    local_84[iVar7] = cVar24;
                    iVar7 = iVar7 + 1;
                    cVar24 = *pcVar11;
                  } while (cVar24 != '\0');
                }
                local_84 = local_84 + iVar7;
                iVar7 = FUN_0000cdf0(local_84,*(undefined4 *)
                                               ((int)pvVar27 +
                                               (uint)*(ushort *)((int)puVar12 + 6) * 4));
                iVar21 = 0;
                if (s___001a4464[0] != '\0') {
                  pcVar11 = "[";
                  cVar24 = s___001a4464[0];
                  do {
                    pcVar11 = pcVar11 + 1;
                    local_84[iVar21 + iVar7] = cVar24;
                    iVar21 = iVar21 + 1;
                    cVar24 = *pcVar11;
                  } while (cVar24 != '\0');
                }
                local_84 = local_84 + iVar21 + iVar7;
                iVar21 = iVar29 * 4;
                iVar7 = FUN_0000cdf0(local_84,*(undefined4 *)((int)pvVar33 + iVar21));
                iVar34 = 0;
                if (s___001a4468[0] != '\0') {
                  pcVar11 = "]";
                  cVar24 = s___001a4468[0];
                  do {
                    pcVar11 = pcVar11 + 1;
                    local_84[iVar34 + iVar7] = cVar24;
                    iVar34 = iVar34 + 1;
                    cVar24 = *pcVar11;
                  } while (cVar24 != '\0');
                }
                local_84 = local_84 + iVar34 + iVar7;
                uVar18 = *puVar12;
                local_84 = (undefined1 *)
                           FUN_0000ce90(local_84,uVar18 >> 0x18 & 3,0,uVar18 >> 0x1a & 7,
                                        uVar18 >> 0x1d);
                iVar7 = 0;
                iVar34 = 1;
              }
              else {
                iVar21 = iVar29 << 2;
                iVar34 = iVar7 + 2;
                iVar7 = iVar7 + 1;
              }
              if (iVar34 == *(int *)((int)pvVar33 + iVar21)) {
                iVar29 = iVar29 + 1;
                iVar7 = -1;
              }
            }
          }
          uVar38 = uVar38 + 1;
          if (uVar36 == uVar38) {
            iVar21 = 0;
            if (s___001a46fc[0] != '\0') {
              pcVar11 = ";\n";
              cVar24 = s___001a46fc[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar21] = cVar24;
                iVar21 = iVar21 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
LAB_00010780:
            local_84 = local_84 + iVar21;
            bVar2 = false;
          }
          else if (puVar12[2] >> 0x1d == uVar39 >> 0x1d) {
            bVar2 = false;
            if (iVar7 == -1) {
              iVar21 = 0;
              if (s___001a44f4[0] != '\0') {
                pcVar11 = ", ";
                cVar24 = s___001a44f4[0];
                do {
                  pcVar11 = pcVar11 + 1;
                  local_84[iVar21] = cVar24;
                  iVar21 = iVar21 + 1;
                  cVar24 = *pcVar11;
                } while (cVar24 != '\0');
              }
              goto LAB_00010780;
            }
          }
          else {
            iVar21 = 0;
            if (s___001a46fc[0] != '\0') {
              pcVar11 = ";\n";
              cVar24 = s___001a46fc[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar21] = cVar24;
                iVar21 = iVar21 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            local_84 = local_84 + iVar21;
            bVar2 = true;
          }
          iVar21 = FUN_0000c8a0(local_58,&local_88,local_5c);
          if (iVar21 == 0) goto LAB_00014070;
          if ((int)uVar36 <= (int)uVar38) goto LAB_000107a8;
          puVar12 = puVar12 + 2;
        } while (!bVar2);
      } while( true );
    }
    iVar7 = -1;
    pvVar28 = (void *)0x0;
    pvVar27 = (void *)0x0;
  }
  else {
    if (0 < (int)uVar36) {
      uVar38 = 0xffffffff;
      puVar12 = puVar13;
      uVar39 = uVar36;
      do {
        if ((int)uVar38 < (int)(uint)*(ushort *)((int)puVar12 + 6)) {
          uVar38 = (uint)*(ushort *)((int)puVar12 + 6);
        }
        puVar12 = puVar12 + 2;
        uVar39 = uVar39 - 1;
      } while (uVar39 != 0);
      if (uVar38 == 0xffffffff) goto LAB_000100c0;
      sVar30 = uVar38 * 4 + 4;
      pvVar27 = _malloc(sVar30);
      pvVar28 = _malloc(sVar30);
      if (pvVar27 == (void *)0x0) {
        if (pvVar28 != (void *)0x0) {
LAB_000163f0:
          _free(pvVar28);
        }
        goto LAB_00016630;
      }
      if (pvVar28 == (void *)0x0) {
        _free(pvVar27);
        goto LAB_00016630;
      }
    }
    else {
LAB_000100c0:
      pvVar27 = (void *)0x0;
      pvVar28 = (void *)0x0;
    }
    pvVar33 = (void *)0x0;
    if (param_1[0x10] != 0) {
      pvVar33 = _malloc(param_1[0x10] << 2);
    }
    if (0 < (int)uVar36) {
      iVar7 = 0;
      iVar21 = 0;
      iVar29 = -1;
      uVar38 = 0xffffffff;
      do {
        iVar34 = iVar21 * 8;
        uVar39 = (uint)*(ushort *)((int)puVar13 + iVar34 + 6);
        *(uint *)(uVar39 * 4 + (int)pvVar27) = uVar39;
        uVar39 = param_1[0x10];
        uVar18 = (uint)*(ushort *)((int)puVar13 + iVar34 + 6);
        puVar12 = param_1 + param_1[0x11] * 2;
        if ((uVar39 == 0) || ((int)uVar39 < 1)) {
LAB_00010194:
          iVar23 = uVar18 * 4;
          uVar18 = 0xffffffff;
          *(int *)((int)pvVar28 + iVar23) = iVar29;
        }
        else {
          puVar20 = puVar12;
          if (uVar18 != (ushort)*puVar12) {
            iVar23 = 8;
            do {
              uVar39 = uVar39 - 1;
              if (uVar39 == 0) goto LAB_00010194;
              puVar20 = (uint *)((int)puVar12 + iVar23);
              iVar23 = iVar23 + 8;
            } while (uVar18 != (ushort)*puVar20);
          }
          uVar38 = (uint)*(ushort *)((int)puVar20 + 6);
          iVar29 = 1;
          *(undefined4 *)(uVar18 * 4 + (int)pvVar28) = 0;
        }
        if (*(ushort *)((int)puVar13 + iVar34 + 6) == uVar38) {
          iVar34 = iVar7 * 4;
          uVar18 = 0xffffffff;
          iVar7 = iVar7 + 1;
          uVar38 = 0xffffffff;
          *(int *)((int)pvVar33 + iVar34) = iVar29;
          iVar29 = -1;
        }
        iVar34 = uVar36 - iVar21;
        puVar12 = puVar13 + iVar21 * 2 + 2;
        if (((int)uVar36 < iVar21 + 1) || (uVar36 == 0x80000000)) {
          iVar34 = 1;
        }
        while( true ) {
          iVar21 = iVar21 + 1;
          iVar34 = iVar34 + -1;
          if (iVar34 == 0) goto LAB_0001025c;
          if (uVar18 == 0xffffffff) break;
          if ((int)(uint)*(ushort *)((int)puVar12 + 6) <= (int)uVar38) {
            *(uint *)((uint)*(ushort *)((int)puVar12 + 6) * 4 + (int)pvVar27) = uVar18;
            *(int *)((int)pvVar28 + (uint)*(ushort *)((int)puVar12 + 6) * 4) = iVar29;
            iVar29 = iVar29 + 1;
            if (*(ushort *)((int)puVar12 + 6) == uVar38) {
              iVar23 = iVar7 * 4;
              uVar18 = 0xffffffff;
              iVar7 = iVar7 + 1;
              uVar38 = 0xffffffff;
              *(int *)((int)pvVar33 + iVar23) = iVar29;
              iVar29 = -1;
            }
          }
          puVar12 = puVar12 + 2;
        }
      } while( true );
    }
    iVar7 = -1;
LAB_000107a8:
    if (pvVar33 != (void *)0x0) {
      _free(pvVar33);
    }
  }
  if ((uVar36 != 0) && (!bVar3)) {
    iVar29 = 0;
    if (s__001a45c0[0] != '\0') {
      pcVar11 = "\n";
      iVar29 = 0;
      cVar24 = s__001a45c0[0];
      do {
        pcVar11 = pcVar11 + 1;
        local_84[iVar29] = cVar24;
        iVar29 = iVar29 + 1;
        cVar24 = *pcVar11;
      } while (cVar24 != '\0');
    }
    local_84 = local_84 + iVar29;
  }
  uVar36 = param_1[8];
  puVar13 = param_1 + param_1[9] * 2;
  if (0 < (int)uVar36) {
    uVar38 = 0;
    do {
      uVar5 = *(ushort *)puVar13;
      if ((uVar5 & 0xf) != 0) {
        iVar29 = 0;
        if (s_ATTRIB_att_001a4738[0] != '\0') {
          pcVar11 = "ATTRIB att";
          cVar24 = s_ATTRIB_att_001a4738[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar29;
        iVar29 = FUN_0000cdf0(local_84,*(ushort *)((int)puVar13 + 6));
        local_84 = local_84 + iVar29;
        if (!bVar3) {
          uVar39 = *puVar13;
          local_84 = (undefined1 *)
                     FUN_0000ce90(local_84,uVar39 >> 0x18 & 3,0,uVar39 >> 0x1a & 7,uVar39 >> 0x1d);
        }
        if (uVar32 == 0x8804) {
LAB_00010974:
          iVar29 = 0;
          if (s___fragment__001a4750[0] != '\0') {
            pcVar11 = " = fragment.";
            cVar24 = s___fragment__001a4750[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
LAB_000109bc:
          local_84 = local_84 + iVar29;
        }
        else if (uVar32 < 0x8805) {
          if (uVar32 == 0x8620) {
LAB_0001092c:
            iVar29 = 0;
            if (s___vertex__001a4744[0] != '\0') {
              pcVar11 = " = vertex.";
              cVar24 = s___vertex__001a4744[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            goto LAB_000109bc;
          }
        }
        else {
          if (uVar32 == 0x8b30) goto LAB_00010974;
          if (uVar32 == 0x8b31) goto LAB_0001092c;
        }
        switch(uVar5 & 0xf) {
        default:
          goto switchD_000109e4_caseD_0;
        case 1:
          iVar29 = 0;
          if (s_position_001a4760[0] != '\0') {
            pcVar11 = "position";
            cVar24 = s_position_001a4760[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 2:
          iVar29 = 0;
          if (s_color_primary_001a476c[0] != '\0') {
            pcVar11 = "color.primary";
            cVar24 = s_color_primary_001a476c[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 3:
          iVar29 = 0;
          if (s_color_secondary_001a477c[0] != '\0') {
            pcVar11 = "color.secondary";
            cVar24 = s_color_secondary_001a477c[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 4:
          iVar29 = 0;
          if (s_normal_001a478c[0] != '\0') {
            pcVar11 = "normal";
            cVar24 = s_normal_001a478c[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 5:
          iVar29 = 0;
          if (s_fogcoord_001a4794[0] != '\0') {
            pcVar11 = "fogcoord";
            cVar24 = s_fogcoord_001a4794[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 6:
          iVar29 = 0;
          if (s_weight__001a47b8[0] != '\0') {
            pcVar11 = "weight[";
            cVar24 = s_weight__001a47b8[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar29;
          iVar21 = FUN_0000cdf0(local_84,*puVar13 & 0x1f);
          iVar29 = 0;
          local_84 = local_84 + iVar21;
          if (s___001a4468[0] != '\0') {
            pcVar11 = "]";
            cVar24 = s___001a4468[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 7:
          iVar29 = 0;
          if (s_texcoord__001a47ac[0] != '\0') {
            pcVar11 = "texcoord[";
            cVar24 = s_texcoord__001a47ac[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar29;
          iVar21 = FUN_0000cdf0(local_84,*puVar13 & 0x1f);
          iVar29 = 0;
          local_84 = local_84 + iVar21;
          if (s___001a4468[0] != '\0') {
            pcVar11 = "]";
            cVar24 = s___001a4468[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 8:
          iVar29 = 0;
          if (s_matrixindex__001a47c0[0] != '\0') {
            pcVar11 = "matrixindex[";
            cVar24 = s_matrixindex__001a47c0[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar29;
          iVar21 = FUN_0000cdf0(local_84,*puVar13 & 0x1f);
          iVar29 = 0;
          local_84 = local_84 + iVar21;
          if (s___001a4468[0] != '\0') {
            pcVar11 = "]";
            cVar24 = s___001a4468[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 9:
          iVar29 = 0;
          if (s_attrib__001a47d0[0] != '\0') {
            pcVar11 = "attrib[";
            cVar24 = s_attrib__001a47d0[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar29;
          iVar21 = FUN_0000cdf0(local_84,*puVar13 & 0x1f);
          iVar29 = 0;
          local_84 = local_84 + iVar21;
          if (s___001a4468[0] != '\0') {
            pcVar11 = "]";
            cVar24 = s___001a4468[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 10:
          iVar29 = 0;
          if (s_material__001a47d8[0] != '\0') {
            pcVar11 = "material.";
            iVar29 = 0;
            cVar24 = s_material__001a47d8[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          uVar39 = *puVar13;
          local_84 = local_84 + iVar29;
          if ((uVar39 & 1) == 0) {
            iVar29 = 0;
            if (s_front__001a47e4[0] != '\0') {
              pcVar11 = "front.";
              cVar24 = s_front__001a47e4[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
LAB_00010f94:
              uVar39 = *puVar13;
            }
LAB_00010f9c:
            local_84 = local_84 + iVar29;
          }
          else if ((uVar39 & 1) == 1) {
            iVar29 = 0;
            if (s_back__001a47ec[0] != '\0') {
              pcVar11 = "back.";
              cVar24 = s_back__001a47ec[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
              goto LAB_00010f94;
            }
            goto LAB_00010f9c;
          }
          switch(uVar39 >> 0xc & 0xf) {
          case 0:
            iVar29 = 0;
            if (s_ambient_001a47f4[0] != '\0') {
              pcVar11 = "ambient";
              cVar24 = s_ambient_001a47f4[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            break;
          case 1:
            iVar29 = 0;
            if (s_diffuse_001a47fc[0] != '\0') {
              pcVar11 = "diffuse";
              cVar24 = s_diffuse_001a47fc[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            break;
          case 2:
            iVar29 = 0;
            if (s_specular_001a4804[0] != '\0') {
              pcVar11 = "specular";
              cVar24 = s_specular_001a4804[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            break;
          case 3:
            iVar29 = 0;
            if (s_emission_001a4810[0] != '\0') {
              pcVar11 = "emission";
              cVar24 = s_emission_001a4810[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            break;
          case 4:
            iVar29 = 0;
            if (s_shininess_001a481c[0] != '\0') {
              pcVar11 = "shininess";
              cVar24 = s_shininess_001a481c[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            break;
          default:
            goto switchD_000109e4_caseD_0;
          }
          break;
        case 0xb:
          iVar29 = 0;
          if (s_frontfacing_001a47a0[0] != '\0') {
            pcVar11 = "frontfacing";
            cVar24 = s_frontfacing_001a47a0[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        local_84 = local_84 + iVar29;
switchD_000109e4_caseD_0:
        iVar29 = 0;
        if (s___001a46fc[0] != '\0') {
          pcVar11 = ";\n";
          cVar24 = s___001a46fc[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar29;
        iVar29 = FUN_0000c8a0(local_80,&local_88,&local_84);
        if (iVar29 == 0) goto LAB_00014070;
      }
      uVar38 = uVar38 + 1;
      puVar13 = puVar13 + 2;
    } while (uVar36 != uVar38);
  }
  if ((uVar36 != 0) && (!bVar3)) {
    iVar29 = 0;
    if (s__001a45c0[0] != '\0') {
      pcVar11 = "\n";
      iVar29 = 0;
      cVar24 = s__001a45c0[0];
      do {
        pcVar11 = pcVar11 + 1;
        local_84[iVar29] = cVar24;
        iVar29 = iVar29 + 1;
        cVar24 = *pcVar11;
      } while (cVar24 != '\0');
    }
    local_84 = local_84 + iVar29;
  }
  uVar36 = param_1[10];
  puVar13 = param_1 + param_1[0xb] * 2;
  if (uVar36 == 0) {
    local_6c = (void *)0x0;
    local_70 = (void *)0x0;
    goto LAB_0001376c;
  }
  if ((int)uVar36 < 1) {
LAB_000112d0:
    local_6c = (void *)0x0;
    local_70 = (void *)0x0;
  }
  else {
    uVar38 = 0xffffffff;
    puVar12 = puVar13;
    uVar39 = uVar36;
    do {
      if ((int)uVar38 < (int)(uint)*(ushort *)((int)puVar12 + 6)) {
        uVar38 = (uint)*(ushort *)((int)puVar12 + 6);
      }
      puVar12 = puVar12 + 2;
      uVar39 = uVar39 - 1;
    } while (uVar39 != 0);
    if (uVar38 == 0xffffffff) goto LAB_000112d0;
    sVar30 = uVar38 * 4 + 4;
    local_6c = _malloc(sVar30);
    local_70 = _malloc(sVar30);
    if (local_6c == (void *)0x0) goto joined_r0x000112bc;
    if (local_70 == (void *)0x0) {
      _free(local_6c);
      goto LAB_00014070;
    }
  }
  piVar35 = (int *)0x0;
  if (param_1[0xe] != 0) {
    piVar35 = _malloc(param_1[0xe] << 2);
  }
  if ((int)uVar36 >= 1) {
    uVar18 = 0;
    iVar29 = -1;
    uVar39 = 0xffffffff;
    uVar38 = 0xffffffff;
    piVar16 = piVar35;
    puVar12 = puVar13;
    do {
      if ((*puVar12 & 0x1f0000) != 0) {
        if (uVar39 == 0xffffffff) {
          *(uint *)((uint)*(ushort *)((int)puVar12 + 6) * 4 + (int)local_6c) =
               (uint)*(ushort *)((int)puVar12 + 6);
          uVar31 = param_1[0xe];
          uVar39 = (uint)*(ushort *)((int)puVar12 + 6);
          puVar20 = param_1 + param_1[0xf] * 2;
          if ((uVar31 == 0) || ((int)uVar31 < 1)) {
LAB_000113ac:
            iVar21 = uVar39 * 4;
            uVar39 = 0xffffffff;
            *(int *)((int)local_70 + iVar21) = iVar29;
          }
          else {
            puVar25 = puVar20;
            if (uVar39 != (ushort)*puVar20) {
              iVar21 = 8;
              do {
                uVar31 = uVar31 - 1;
                if (uVar31 == 0) goto LAB_000113ac;
                puVar25 = (uint *)((int)puVar20 + iVar21);
                iVar21 = iVar21 + 8;
              } while (uVar39 != (ushort)*puVar25);
            }
            uVar38 = (uint)*(ushort *)((int)puVar25 + 6);
            iVar29 = 1;
            *(undefined4 *)((int)local_70 + uVar39 * 4) = 0;
          }
          if (*(ushort *)((int)puVar12 + 6) == uVar38) {
LAB_00011410:
            *piVar16 = iVar29;
            uVar39 = 0xffffffff;
            piVar16 = piVar16 + 1;
            iVar29 = -1;
            uVar38 = 0xffffffff;
          }
        }
        else if ((int)(uint)*(ushort *)((int)puVar12 + 6) <= (int)uVar38) {
          *(uint *)((uint)*(ushort *)((int)puVar12 + 6) * 4 + (int)local_6c) = uVar39;
          *(int *)((int)local_70 + (uint)*(ushort *)((int)puVar12 + 6) * 4) = iVar29;
          iVar29 = iVar29 + 1;
          if (*(ushort *)((int)puVar12 + 6) == uVar38) goto LAB_00011410;
        }
      }
      uVar41 = (ulonglong)uVar38;
      uVar18 = uVar18 + 1;
      puVar12 = puVar12 + 2;
    } while (uVar36 != uVar18);
    iVar29 = 0;
    uVar38 = 0;
    do {
      uVar5 = *(ushort *)puVar13;
      uVar40 = uVar5 & 0x1f;
      if ((uVar5 & 0x1f) == 0) goto LAB_000136f0;
      uVar39 = (uint)*(ushort *)((int)puVar13 + 6);
      iVar21 = *(int *)((int)local_70 + uVar39 * 4);
      if (iVar21 == -1) {
        iVar21 = 0;
        if (s_PARAM_prm_001a4828[0] != '\0') {
          pcVar11 = "PARAM prm";
          cVar24 = s_PARAM_prm_001a4828[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
          uVar39 = (uint)*(ushort *)((int)puVar13 + 6);
        }
        local_84 = local_84 + iVar21;
        uVar41 = FUN_0000cdf0(local_84,*(undefined4 *)((int)local_6c + uVar39 * 4));
        local_84 = local_84 + (int)(uVar41 >> 0x20);
        if (!bVar3) {
          uVar39 = *puVar13;
          uVar41 = FUN_0000ce90(local_84,uVar39 >> 0x18 & 3,0,uVar39 >> 0x1a & 7,uVar39 >> 0x1d);
          local_84 = (undefined1 *)(uVar41 >> 0x20);
        }
        iVar21 = 0;
        if (s___001a4834[0] != '\0') {
          pcVar11 = " = ";
          cVar24 = s___001a4834[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
LAB_00011758:
        local_84 = local_84 + iVar21;
      }
      else {
        if (iVar21 != 0) {
          iVar7 = iVar7 + 1;
          iVar21 = 0;
          if (s__001a4844[0] != '\0') {
            pcVar11 = "    ";
            cVar24 = s__001a4844[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          goto LAB_00011758;
        }
        iVar7 = 0;
        if (s_PARAM_prm_001a4828[0] != '\0') {
          pcVar11 = "PARAM prm";
          cVar24 = s_PARAM_prm_001a4828[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
          uVar39 = (uint)*(ushort *)((int)puVar13 + 6);
        }
        local_84 = local_84 + iVar7;
        iVar7 = FUN_0000cdf0(local_84,*(undefined4 *)((int)local_6c + uVar39 * 4));
        iVar21 = 0;
        if (s___001a4464[0] != '\0') {
          pcVar11 = "[";
          cVar24 = s___001a4464[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21 + iVar7] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar21 + iVar7;
        uVar41 = FUN_0000cdf0(local_84,piVar35[iVar29]);
        iVar7 = (int)(uVar41 >> 0x20);
        iVar21 = 0;
        if (s___001a4468[0] != '\0') {
          pcVar11 = "]";
          cVar24 = s___001a4468[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21 + iVar7] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar21 + iVar7;
        if (!bVar3) {
          uVar39 = *puVar13;
          uVar41 = FUN_0000ce90(local_84,uVar39 >> 0x18 & 3,0,uVar39 >> 0x1a & 7,uVar39 >> 0x1d);
          local_84 = (undefined1 *)(uVar41 >> 0x20);
        }
        iVar7 = 0;
        if (s_____001a4838[0] != '\0') {
          pcVar11 = " = {\n    ";
          cVar24 = s_____001a4838[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar7;
        iVar7 = 0;
      }
      if ((uVar5 & 0x1f) != 0) {
        if (uVar40 < 3) {
          iVar21 = 0;
          if (s_program__001a484c[0] != '\0') {
            pcVar11 = "program.";
            cVar24 = s_program__001a484c[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          goto LAB_000118a8;
        }
        if (uVar40 != 0x11) goto LAB_00011778;
        iVar21 = 0;
        if (s__001a4134[0] != '\0') {
          pcVar11 = "";
          acVar9 = s__001a4134[0];
          do {
            local_84[iVar21] = acVar9;
            iVar21 = iVar21 + 1;
            acVar9 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (acVar9 != '\0');
        }
        local_84 = local_84 + iVar21;
switchD_000118c8_caseD_11:
        pfVar37 = (float *)(param_1 + param_1[0x1b] * 2 + (uint)(ushort)*puVar13 * 4);
        switch(*puVar13 >> 0x1a & 7) {
        case 0:
        case 1:
          iVar21 = 0;
          if (s___001a49dc[0] != '\0') {
            pcVar11 = "{";
            cVar24 = s___001a49dc[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar21;
          local_60 = ((unsigned char *)0x0019f634);
          uVar42 = ((char * (*)())FUN_0000bfa0)((double)*pfVar37,DOUBLE_001aa248,(int)(uVar41 >> 0x20),(int)uVar41,
                                local_84,(int)local_88[0] + (local_80[0] - (int)local_84));
          iVar21 = (int)((ulonglong)uVar42 >> 0x20);
          cVar24 = ((unsigned char *)0x00004ec0)[(int)local_60];
          bVar2 = cVar24 != '\0';
          if (bVar2) {
            pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
            iVar34 = 0;
            cVar10 = cVar24;
            do {
              *(char *)(iVar21 + iVar34) = cVar10;
              iVar34 = iVar34 + 1;
              cVar10 = *pcVar11;
              pcVar11 = pcVar11 + 1;
            } while (cVar10 != '\0');
          }
          else {
            iVar34 = 0;
          }
          local_84 = (undefined1 *)(iVar34 + iVar21);
          uVar42 = ((char * (*)())FUN_0000bfa0)((double)pfVar37[1],DOUBLE_001aa248,iVar21,(int)uVar42,local_84,
                                (int)local_88[0] + (local_80[0] - (int)local_84));
          iVar21 = (int)((ulonglong)uVar42 >> 0x20);
          if (bVar2) {
            iVar34 = 0;
            pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
            cVar10 = cVar24;
            do {
              *(char *)(iVar21 + iVar34) = cVar10;
              iVar34 = iVar34 + 1;
              cVar10 = *pcVar11;
              pcVar11 = pcVar11 + 1;
            } while (cVar10 != '\0');
          }
          else {
            iVar34 = 0;
          }
          local_84 = (undefined1 *)(iVar34 + iVar21);
          uVar42 = ((char * (*)())FUN_0000bfa0)((double)pfVar37[2],DOUBLE_001aa248,iVar21,(int)uVar42,local_84,
                                (int)local_88[0] + (local_80[0] - (int)local_84));
          iVar21 = (int)((ulonglong)uVar42 >> 0x20);
          if (bVar2) {
            iVar34 = 0;
            pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
            do {
              *(char *)(iVar21 + iVar34) = cVar24;
              iVar34 = iVar34 + 1;
              cVar24 = *pcVar11;
              pcVar11 = pcVar11 + 1;
            } while (cVar24 != '\0');
          }
          else {
            iVar34 = 0;
          }
          local_84 = (undefined1 *)(iVar34 + iVar21);
          iVar21 = ((char * (*)())FUN_0000bfa0)((double)pfVar37[3],DOUBLE_001aa248,iVar21,(int)uVar42,local_84,
                                (int)local_88[0] + (local_80[0] - (int)local_84));
          iVar34 = 0;
          if (s___001a49e0[0] != '\0') {
            pcVar11 = "}";
            cVar24 = s___001a49e0[0];
            do {
              pcVar11 = pcVar11 + 1;
              *(char *)(iVar21 + iVar34) = cVar24;
              iVar34 = iVar34 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = (undefined1 *)(iVar34 + iVar21);
          break;
        case 2:
          iVar21 = 0;
          if (s_____Fixed_constant_data_not_curr_001a49e4[0] != '\0') {
            pcVar11 = "{-- Fixed constant data not currently supported --}";
            cVar24 = s_____Fixed_constant_data_not_curr_001a49e4[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          goto LAB_000135c0;
        case 3:
        case 4:
          iVar21 = 0;
          if (s___001a49dc[0] != '\0') {
            pcVar11 = "{";
            cVar24 = s___001a49dc[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar21;
          local_60 = ((unsigned char *)0x0019f634);
          iVar21 = FUN_0000cdf0(local_84,*pfVar37);
          cVar24 = ((unsigned char *)0x00004ec0)[(int)local_60];
          bVar2 = cVar24 != '\0';
          if (bVar2) {
            pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
            iVar34 = 0;
            cVar10 = cVar24;
            do {
              local_84[iVar34 + iVar21] = cVar10;
              iVar34 = iVar34 + 1;
              cVar10 = *pcVar11;
              pcVar11 = pcVar11 + 1;
            } while (cVar10 != '\0');
          }
          else {
            iVar34 = 0;
          }
          local_84 = local_84 + iVar34 + iVar21;
          iVar21 = FUN_0000cdf0(local_84,pfVar37[1]);
          if (bVar2) {
            iVar34 = 0;
            pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
            cVar10 = cVar24;
            do {
              local_84[iVar34 + iVar21] = cVar10;
              iVar34 = iVar34 + 1;
              cVar10 = *pcVar11;
              pcVar11 = pcVar11 + 1;
            } while (cVar10 != '\0');
          }
          else {
            iVar34 = 0;
          }
          local_84 = local_84 + iVar34 + iVar21;
          iVar21 = FUN_0000cdf0(local_84,pfVar37[2]);
          if (bVar2) {
            iVar34 = 0;
            pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
            do {
              local_84[iVar34 + iVar21] = cVar24;
              iVar34 = iVar34 + 1;
              cVar24 = *pcVar11;
              pcVar11 = pcVar11 + 1;
            } while (cVar24 != '\0');
          }
          else {
            iVar34 = 0;
          }
          local_84 = local_84 + iVar34 + iVar21;
          iVar34 = FUN_0000cdf0(local_84,pfVar37[3]);
          iVar21 = 0;
          local_84 = local_84 + iVar34;
          if (s___001a49e0[0] != '\0') {
            pcVar11 = "}";
            cVar24 = s___001a49e0[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          goto LAB_000135c0;
        }
        goto switchD_000118c8_caseD_0;
      }
LAB_00011778:
      if (s_state__001a4858[0] == '\0') {
        iVar21 = 0;
      }
      else {
        pcVar11 = "state.";
        iVar21 = 0;
        cVar24 = s_state__001a4858[0];
        do {
          pcVar11 = pcVar11 + 1;
          local_84[iVar21] = cVar24;
          iVar21 = iVar21 + 1;
          cVar24 = *pcVar11;
        } while (cVar24 != '\0');
      }
LAB_000118a8:
      local_84 = local_84 + iVar21;
      switch(uVar40) {
      default:
        goto switchD_000118c8_caseD_0;
      case 1:
        iVar21 = 0;
        if (s_local__001a4860[0] != '\0') {
          pcVar11 = "local[";
          cVar24 = s_local__001a4860[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar21;
        iVar34 = FUN_0000cdf0(local_84,(ushort)*puVar13);
        iVar21 = 0;
        local_84 = local_84 + iVar34;
        if (s___001a4468[0] != '\0') {
          pcVar11 = "]";
          cVar24 = s___001a4468[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 2:
        iVar21 = 0;
        if (s_env__001a4868[0] != '\0') {
          pcVar11 = "env[";
          cVar24 = s_env__001a4868[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar21;
        iVar34 = FUN_0000cdf0(local_84,(ushort)*puVar13);
        iVar21 = 0;
        local_84 = local_84 + iVar34;
        if (s___001a4468[0] != '\0') {
          pcVar11 = "]";
          cVar24 = s___001a4468[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 3:
        iVar21 = 0;
        if (s_light__001a4870[0] != '\0') {
          pcVar11 = "light[";
          cVar24 = s_light__001a4870[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar21;
        iVar21 = FUN_0000cdf0(local_84,(char)*puVar13);
        iVar34 = 0;
        if (s____001a4878[0] != '\0') {
          pcVar11 = "].";
          cVar24 = s____001a4878[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar34 + iVar21] = cVar24;
            iVar34 = iVar34 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar34 + iVar21;
        switch(*puVar13 >> 8 & 0xf) {
        case 0:
          iVar21 = 0;
          if (s_ambient_001a47f4[0] != '\0') {
            pcVar11 = "ambient";
            cVar24 = s_ambient_001a47f4[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 1:
          iVar21 = 0;
          if (s_diffuse_001a47fc[0] != '\0') {
            pcVar11 = "diffuse";
            cVar24 = s_diffuse_001a47fc[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 2:
          iVar21 = 0;
          if (s_specular_001a4804[0] != '\0') {
            pcVar11 = "specular";
            cVar24 = s_specular_001a4804[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 3:
          iVar21 = 0;
          if (s_position_001a4760[0] != '\0') {
            pcVar11 = "position";
            cVar24 = s_position_001a4760[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 4:
          iVar21 = 0;
          if (s_spot_direction_001a487c[0] != '\0') {
            pcVar11 = "spot.direction";
            cVar24 = s_spot_direction_001a487c[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 5:
          iVar21 = 0;
          if (s_attenuation_001a488c[0] != '\0') {
            pcVar11 = "attenuation";
            cVar24 = s_attenuation_001a488c[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 6:
          iVar21 = 0;
          if (s_half_001a4898[0] != '\0') {
            pcVar11 = "half";
            cVar24 = s_half_001a4898[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 7:
          iVar21 = 0;
          if (s_spotcutoff_001a48a0[0] != '\0') {
            pcVar11 = "spotcutoff";
            cVar24 = s_spotcutoff_001a48a0[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        default:
          goto switchD_000118c8_caseD_0;
        }
        break;
      case 4:
        iVar21 = 0;
        if (s_lightprod__001a48ac[0] != '\0') {
          pcVar11 = "lightprod[";
          cVar24 = s_lightprod__001a48ac[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar21;
        iVar21 = FUN_0000cdf0(local_84,(char)*puVar13);
        iVar34 = 0;
        if (s____001a4878[0] != '\0') {
          pcVar11 = "].";
          cVar24 = s____001a4878[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar34 + iVar21] = cVar24;
            iVar34 = iVar34 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        uVar18 = *puVar13;
        local_84 = local_84 + iVar34 + iVar21;
        uVar39 = uVar18 >> 8 & 1;
        if (uVar39 == 0) {
          iVar21 = 0;
          if (s_front__001a47e4[0] != '\0') {
            pcVar11 = "front.";
            cVar24 = s_front__001a47e4[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
LAB_00011f20:
            uVar18 = *puVar13;
          }
LAB_00011f28:
          local_84 = local_84 + iVar21;
        }
        else if (uVar39 == 1) {
          iVar21 = 0;
          if (s_back__001a47ec[0] != '\0') {
            pcVar11 = "back.";
            cVar24 = s_back__001a47ec[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
            goto LAB_00011f20;
          }
          goto LAB_00011f28;
        }
        uVar39 = uVar18 >> 9 & 3;
        if (uVar39 == 1) {
          iVar21 = 0;
          if (s_diffuse_001a47fc[0] != '\0') {
            pcVar11 = "diffuse";
            cVar24 = s_diffuse_001a47fc[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        else if (uVar39 == 2) {
          iVar21 = 0;
          if (s_specular_001a4804[0] != '\0') {
            pcVar11 = "specular";
            cVar24 = s_specular_001a4804[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        else {
          if (uVar39 != 0) goto switchD_000118c8_caseD_0;
          iVar21 = 0;
          if (s_ambient_001a47f4[0] != '\0') {
            pcVar11 = "ambient";
            cVar24 = s_ambient_001a47f4[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        break;
      case 5:
        uVar39 = *puVar13;
        if ((uVar39 >> 1 & 7) == 5) {
          iVar21 = 0;
          if (s_lightmodel__001a48cc[0] != '\0') {
            pcVar11 = "lightmodel.";
            cVar24 = s_lightmodel__001a48cc[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
LAB_00012114:
            uVar39 = *puVar13;
          }
        }
        else {
          iVar21 = 0;
          if (s_material__001a47d8[0] != '\0') {
            pcVar11 = "material.";
            cVar24 = s_material__001a47d8[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
            goto LAB_00012114;
          }
        }
        local_84 = local_84 + iVar21;
        if ((uVar39 & 1) == 0) {
          iVar21 = 0;
          if (s_front__001a47e4[0] != '\0') {
            pcVar11 = "front.";
            cVar24 = s_front__001a47e4[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
LAB_000121c4:
            uVar39 = *puVar13;
          }
LAB_000121cc:
          local_84 = local_84 + iVar21;
        }
        else if ((uVar39 & 1) == 1) {
          iVar21 = 0;
          if (s_back__001a47ec[0] != '\0') {
            pcVar11 = "back.";
            cVar24 = s_back__001a47ec[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
            goto LAB_000121c4;
          }
          goto LAB_000121cc;
        }
        switch(uVar39 >> 1 & 7) {
        case 0:
          iVar21 = 0;
          if (s_ambient_001a47f4[0] != '\0') {
            pcVar11 = "ambient";
            cVar24 = s_ambient_001a47f4[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 1:
          iVar21 = 0;
          if (s_diffuse_001a47fc[0] != '\0') {
            pcVar11 = "diffuse";
            cVar24 = s_diffuse_001a47fc[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 2:
          iVar21 = 0;
          if (s_specular_001a4804[0] != '\0') {
            pcVar11 = "specular";
            cVar24 = s_specular_001a4804[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 3:
          iVar21 = 0;
          if (s_emission_001a4810[0] != '\0') {
            pcVar11 = "emission";
            cVar24 = s_emission_001a4810[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 4:
          iVar21 = 0;
          if (s_shininess_001a481c[0] != '\0') {
            pcVar11 = "shininess";
            cVar24 = s_shininess_001a481c[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 5:
          iVar21 = 0;
          if (s_scenecolor_001a48d8[0] != '\0') {
            pcVar11 = "scenecolor";
            cVar24 = s_scenecolor_001a48d8[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        default:
          goto switchD_000118c8_caseD_0;
        }
        break;
      case 6:
        iVar21 = 0;
        if (s_lightmodel_ambient_001a48b8[0] != '\0') {
          pcVar11 = "lightmodel.ambient";
          cVar24 = s_lightmodel_ambient_001a48b8[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 7:
        iVar21 = 0;
        if (s_texgen__001a48e4[0] != '\0') {
          pcVar11 = "texgen[";
          cVar24 = s_texgen__001a48e4[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar21;
        iVar21 = FUN_0000cdf0(local_84,*puVar13 & 0x1f);
        iVar34 = 0;
        if (s___eye__001a48ec[0] != '\0') {
          pcVar11 = "].eye.";
          cVar24 = s___eye__001a48ec[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar34 + iVar21] = cVar24;
            iVar34 = iVar34 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar34 + iVar21;
        uVar39 = *puVar13 >> 5 & 7;
        if (uVar39 == 1) {
          iVar21 = 0;
          if (s_t_001a48f8[0] != '\0') {
            pcVar11 = "t";
            cVar24 = s_t_001a48f8[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        else if (uVar39 < 2) {
          if (uVar39 != 0) goto switchD_000118c8_caseD_0;
          iVar21 = 0;
          if (s_s_001a48f4[0] != '\0') {
            pcVar11 = "s";
            cVar24 = s_s_001a48f4[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        else if (uVar39 == 2) {
          iVar21 = 0;
          if (s_r_001a48fc[0] != '\0') {
            pcVar11 = "r";
            cVar24 = s_r_001a48fc[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        else {
          if (uVar39 != 3) goto switchD_000118c8_caseD_0;
          iVar21 = 0;
          if (s_q_001a4900[0] != '\0') {
            pcVar11 = "q";
            cVar24 = s_q_001a4900[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        break;
      case 8:
        iVar21 = 0;
        if (s_texgen__001a48e4[0] != '\0') {
          pcVar11 = "texgen[";
          cVar24 = s_texgen__001a48e4[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar21;
        iVar21 = FUN_0000cdf0(local_84,*puVar13 & 0x1f);
        iVar34 = 0;
        if (s___object__001a4904[0] != '\0') {
          pcVar11 = "].object.";
          cVar24 = s___object__001a4904[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar34 + iVar21] = cVar24;
            iVar34 = iVar34 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar34 + iVar21;
        uVar39 = *puVar13 >> 5 & 7;
        if (uVar39 == 1) {
          iVar21 = 0;
          if (s_t_001a48f8[0] != '\0') {
            pcVar11 = "t";
            cVar24 = s_t_001a48f8[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        else if (uVar39 < 2) {
          if (uVar39 != 0) goto switchD_000118c8_caseD_0;
          iVar21 = 0;
          if (s_s_001a48f4[0] != '\0') {
            pcVar11 = "s";
            cVar24 = s_s_001a48f4[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        else if (uVar39 == 2) {
          iVar21 = 0;
          if (s_r_001a48fc[0] != '\0') {
            pcVar11 = "r";
            cVar24 = s_r_001a48fc[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        else {
          if (uVar39 != 3) goto switchD_000118c8_caseD_0;
          iVar21 = 0;
          if (s_q_001a4900[0] != '\0') {
            pcVar11 = "q";
            cVar24 = s_q_001a4900[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        break;
      case 9:
        iVar21 = 0;
        if (s_texenv__001a4910[0] != '\0') {
          pcVar11 = "texenv[";
          cVar24 = s_texenv__001a4910[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar21;
        iVar34 = FUN_0000cdf0(local_84,*puVar13 & 0x1f);
        iVar21 = 0;
        local_84 = local_84 + iVar34;
        if (s___color_001a4918[0] != '\0') {
          pcVar11 = "].color";
          cVar24 = s___color_001a4918[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 10:
        iVar21 = 0;
        if (s_clip__001a4920[0] != '\0') {
          pcVar11 = "clip[";
          cVar24 = s_clip__001a4920[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar21;
        iVar34 = FUN_0000cdf0(local_84,(char)*puVar13);
        iVar21 = 0;
        local_84 = local_84 + iVar34;
        if (s___plane_001a4928[0] != '\0') {
          pcVar11 = "].plane";
          cVar24 = s___plane_001a4928[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 0xb:
        iVar21 = 0;
        if (s_fog_color_001a4930[0] != '\0') {
          pcVar11 = "fog.color";
          cVar24 = s_fog_color_001a4930[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 0xc:
        iVar21 = 0;
        if (s_fog_params_001a493c[0] != '\0') {
          pcVar11 = "fog.params";
          cVar24 = s_fog_params_001a493c[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 0xd:
        iVar21 = 0;
        if (s_point_size_001a4954[0] != '\0') {
          pcVar11 = "point.size";
          cVar24 = s_point_size_001a4954[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 0xe:
        iVar21 = 0;
        if (s_point_attenuation_001a4960[0] != '\0') {
          pcVar11 = "point.attenuation";
          cVar24 = s_point_attenuation_001a4960[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 0xf:
        iVar21 = 0;
        if (s_depth_range_001a4948[0] != '\0') {
          pcVar11 = "depth.range";
          cVar24 = s_depth_range_001a4948[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 0x10:
        iVar21 = 0;
        if (s_matrix__001a4974[0] != '\0') {
          pcVar11 = "matrix.";
          cVar24 = s_matrix__001a4974[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        uVar39 = *puVar13;
        local_84 = local_84 + iVar21;
        switch(uVar39 >> 8 & 7) {
        case 0:
          iVar34 = 0;
          if (s_mvp__001a4988[0] != '\0') {
            pcVar11 = "mvp.";
            cVar24 = s_mvp__001a4988[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar34] = cVar24;
              iVar34 = iVar34 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
LAB_00012bfc:
            uVar39 = *puVar13;
          }
          goto LAB_00012e2c;
        case 1:
          iVar34 = 0;
          if (s_projection__001a497c[0] != '\0') {
            pcVar11 = "projection.";
            cVar24 = s_projection__001a497c[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar34] = cVar24;
              iVar34 = iVar34 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
            goto LAB_00012bfc;
          }
          goto LAB_00012e2c;
        case 2:
          iVar21 = 0;
          if (s_color__001a4990[0] != '\0') {
            pcVar11 = "color[";
            cVar24 = s_color__001a4990[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar21;
          iVar21 = FUN_0000cdf0(local_84,(char)*puVar13);
          iVar34 = 0;
          local_84 = local_84 + iVar21;
          if (s____001a4878[0] != '\0') {
            pcVar11 = "].";
            cVar24 = s____001a4878[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar34] = cVar24;
              iVar34 = iVar34 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          goto LAB_00012d68;
        case 3:
          iVar21 = 0;
          if (s_modelview__001a4998[0] != '\0') {
            pcVar11 = "modelview[";
            cVar24 = s_modelview__001a4998[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar21;
          iVar21 = FUN_0000cdf0(local_84,(char)*puVar13);
          iVar34 = 0;
          local_84 = local_84 + iVar21;
          if (s____001a4878[0] != '\0') {
            pcVar11 = "].";
            cVar24 = s____001a4878[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar34] = cVar24;
              iVar34 = iVar34 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
LAB_00012d68:
          uVar39 = *puVar13;
          local_84 = local_84 + iVar34;
          break;
        case 4:
          iVar21 = 0;
          if (s_texture__001a4514[0] != '\0') {
            pcVar11 = "texture[";
            cVar24 = s_texture__001a4514[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar21;
          iVar21 = FUN_0000cdf0(local_84,(char)*puVar13);
          iVar34 = 0;
          local_84 = local_84 + iVar21;
          if (s____001a4878[0] != '\0') {
            pcVar11 = "].";
            cVar24 = s____001a4878[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar34] = cVar24;
              iVar34 = iVar34 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          uVar39 = *puVar13;
LAB_00012e2c:
          local_84 = local_84 + iVar34;
          break;
        case 5:
          iVar21 = 0;
          if (s_program__001a49a4[0] != '\0') {
            pcVar11 = "program[";
            cVar24 = s_program__001a49a4[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar21;
          iVar21 = FUN_0000cdf0(local_84,(char)*puVar13);
          iVar34 = 0;
          if (s____001a4878[0] != '\0') {
            pcVar11 = "].";
            cVar24 = s____001a4878[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar34 + iVar21] = cVar24;
              iVar34 = iVar34 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar34 + iVar21;
          uVar39 = *puVar13;
        }
        uVar39 = uVar39 >> 0xe & 3;
        if (uVar39 == 2) {
          iVar21 = 0;
          if (s_inverse__001a49bc[0] != '\0') {
            pcVar11 = "inverse.";
            cVar24 = s_inverse__001a49bc[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar21] = cVar24;
              iVar21 = iVar21 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
LAB_00012ff0:
          local_84 = local_84 + iVar21;
        }
        else {
          if (uVar39 == 3) {
            iVar21 = 0;
            if (s_invtrans__001a49c8[0] != '\0') {
              pcVar11 = "invtrans.";
              cVar24 = s_invtrans__001a49c8[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar21] = cVar24;
                iVar21 = iVar21 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            goto LAB_00012ff0;
          }
          if (uVar39 == 1) {
            iVar21 = 0;
            if (s_transpose__001a49b0[0] != '\0') {
              pcVar11 = "transpose.";
              cVar24 = s_transpose__001a49b0[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar21] = cVar24;
                iVar21 = iVar21 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
            goto LAB_00012ff0;
          }
        }
        iVar21 = 0;
        if (s_row__001a49d4[0] != '\0') {
          pcVar11 = "row[";
          cVar24 = s_row__001a49d4[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar21;
        iVar34 = FUN_0000cdf0(local_84,*puVar13 >> 0xc & 3);
        iVar21 = 0;
        local_84 = local_84 + iVar34;
        if (s___001a4468[0] != '\0') {
          pcVar11 = "]";
          cVar24 = s___001a4468[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 0x11:
        goto switchD_000118c8_caseD_11;
      case 0x12:
        iVar21 = 0;
        if (s_normalscale_001a4a18[0] != '\0') {
          pcVar11 = "normalscale";
          cVar24 = s_normalscale_001a4a18[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
      }
LAB_000135c0:
      local_84 = local_84 + iVar21;
switchD_000118c8_caseD_0:
      if (*(int *)((int)local_70 + (uint)*(ushort *)((int)puVar13 + 6) * 4) == -1) {
        iVar21 = 0;
        if (s___001a46fc[0] != '\0') {
          pcVar11 = ";\n";
          cVar24 = s___001a46fc[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
      }
      else if (iVar7 + 1 == piVar35[iVar29]) {
        iVar29 = iVar29 + 1;
        iVar21 = 0;
        if (s____001a4a24[0] != '\0') {
          pcVar11 = "\n};\n";
          cVar24 = s____001a4a24[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
      }
      else {
        iVar21 = 0;
        if (s___001a4a2c[0] != '\0') {
          pcVar11 = ",\n";
          cVar24 = s___001a4a2c[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar21] = cVar24;
            iVar21 = iVar21 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
      }
      local_84 = local_84 + iVar21;
      uVar41 = FUN_0000c8a0(local_80,&local_88,&local_84);
      if ((int)(uVar41 >> 0x20) == 0) goto LAB_00014048;
LAB_000136f0:
      uVar38 = uVar38 + 1;
      puVar13 = puVar13 + 2;
    } while (uVar36 != uVar38);
  }
  if (piVar35 != (int *)0x0) {
    _free(piVar35);
  }
  iVar7 = 0;
  if (s__001a45c0[0] != '\0') {
    pcVar11 = "\n";
    iVar7 = 0;
    cVar24 = s__001a45c0[0];
    do {
      pcVar11 = pcVar11 + 1;
      local_84[iVar7] = cVar24;
      iVar7 = iVar7 + 1;
      cVar24 = *pcVar11;
    } while (cVar24 != '\0');
  }
  local_84 = local_84 + iVar7;
LAB_0001376c:
  uVar36 = param_1[0xc];
  puVar13 = param_1 + param_1[0xd] * 2;
  if (0 < (int)uVar36) {
    uVar38 = 0;
    do {
      uVar39 = *puVar13 >> 0x10 & 0xf;
      if (uVar39 == 0) goto LAB_000140a0;
      uVar18 = *puVar13 >> 0x1d;
      if (uVar18 == 1) {
        iVar7 = 0;
        if (s_LONG_OUTPUT_res_001a4a3c[0] != '\0') {
          pcVar11 = "LONG OUTPUT res";
          cVar24 = s_LONG_OUTPUT_res_001a4a3c[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
LAB_0001389c:
        local_84 = local_84 + iVar7;
      }
      else {
        if (uVar18 == 2) {
          iVar7 = 0;
          if (s_SHORT_OUTPUT_res_001a4a4c[0] != '\0') {
            pcVar11 = "SHORT OUTPUT res";
            cVar24 = s_SHORT_OUTPUT_res_001a4a4c[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar7] = cVar24;
              iVar7 = iVar7 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          goto LAB_0001389c;
        }
        if (uVar18 == 0) {
          iVar7 = 0;
          if (s_OUTPUT_res_001a4a30[0] != '\0') {
            pcVar11 = "OUTPUT res";
            cVar24 = s_OUTPUT_res_001a4a30[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar7] = cVar24;
              iVar7 = iVar7 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          goto LAB_0001389c;
        }
      }
      iVar7 = FUN_0000cdf0(local_84,*(undefined2 *)((int)puVar13 + 6));
      local_84 = local_84 + iVar7;
      if (!bVar3) {
        uVar18 = *puVar13;
        local_84 = (undefined1 *)
                   FUN_0000ce90(local_84,uVar18 >> 0x18 & 3,0,uVar18 >> 0x1a & 7,uVar18 >> 0x1d);
      }
      iVar7 = 0;
      if (s___001a4834[0] != '\0') {
        pcVar11 = " = ";
        cVar24 = s___001a4834[0];
        do {
          pcVar11 = pcVar11 + 1;
          local_84[iVar7] = cVar24;
          iVar7 = iVar7 + 1;
          cVar24 = *pcVar11;
        } while (cVar24 != '\0');
      }
      local_84 = local_84 + iVar7;
      switch(uVar39) {
      default:
        goto switchD_00013960_caseD_0;
      case 1:
        iVar29 = 0;
        if (s_result_position_001a4a60[0] != '\0') {
          pcVar11 = "result.position";
          cVar24 = s_result_position_001a4a60[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 2:
        iVar29 = 0;
        if (s_result_fogcoord_001a4a70[0] != '\0') {
          pcVar11 = "result.fogcoord";
          cVar24 = s_result_fogcoord_001a4a70[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 3:
        iVar29 = 0;
        if (s_result_pointsize_001a4a80[0] != '\0') {
          pcVar11 = "result.pointsize";
          cVar24 = s_result_pointsize_001a4a80[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 4:
        iVar7 = 0;
        if (s_result_color_001a4a94[0] != '\0') {
          pcVar11 = "result.color";
          cVar24 = s_result_color_001a4a94[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar7;
        if ((uVar32 == 0x8620) || (uVar32 == 0x8b31)) {
          if ((*puVar13 & 1) == 0) {
            iVar29 = 0;
            if (s__front_primary_001a4aa4[0] != '\0') {
              pcVar11 = ".front.primary";
              cVar24 = s__front_primary_001a4aa4[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
          }
          else {
            if ((*puVar13 & 1) != 1) goto switchD_00013960_caseD_0;
            iVar29 = 0;
            if (s__back_primary_001a4ab4[0] != '\0') {
              pcVar11 = ".back.primary";
              cVar24 = s__back_primary_001a4ab4[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
          }
        }
        else {
          if (((uVar32 != 0x8804) && (uVar32 != 0x8b30)) ||
             (uVar39 = *puVar13, (uVar39 >> 1 & 7) < 2)) goto switchD_00013960_caseD_0;
          iVar7 = 0;
          if (s___001a4464[0] != '\0') {
            pcVar11 = "[";
            cVar24 = s___001a4464[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar7] = cVar24;
              iVar7 = iVar7 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
            uVar39 = *puVar13;
          }
          local_84 = local_84 + iVar7;
          iVar7 = FUN_0000cdf0(local_84,uVar39 >> 1 & 7);
          iVar29 = 0;
          local_84 = local_84 + iVar7;
          if (s___001a4468[0] != '\0') {
            pcVar11 = "]";
            cVar24 = s___001a4468[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar29] = cVar24;
              iVar29 = iVar29 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
        }
        break;
      case 5:
        iVar7 = 0;
        if (s_result_color_001a4a94[0] != '\0') {
          pcVar11 = "result.color";
          cVar24 = s_result_color_001a4a94[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar7;
        if ((uVar32 == 0x8620) || (uVar32 == 0x8b31)) {
          if ((*puVar13 & 1) == 0) {
            iVar29 = 0;
            if (s__front_secondary_001a4ac4[0] != '\0') {
              pcVar11 = ".front.secondary";
              cVar24 = s__front_secondary_001a4ac4[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
          }
          else {
            if ((*puVar13 & 1) != 1) goto switchD_00013960_caseD_0;
            iVar29 = 0;
            if (s__back_secondary_001a4ad8[0] != '\0') {
              pcVar11 = ".back.secondary";
              cVar24 = s__back_secondary_001a4ad8[0];
              do {
                pcVar11 = pcVar11 + 1;
                local_84[iVar29] = cVar24;
                iVar29 = iVar29 + 1;
                cVar24 = *pcVar11;
              } while (cVar24 != '\0');
            }
          }
          break;
        }
        goto switchD_00013960_caseD_0;
      case 6:
        iVar7 = 0;
        if (s_result_texcoord__001a4ae8[0] != '\0') {
          pcVar11 = "result.texcoord[";
          cVar24 = s_result_texcoord__001a4ae8[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar7;
        iVar7 = FUN_0000cdf0(local_84,*puVar13 & 0x1f);
        iVar29 = 0;
        local_84 = local_84 + iVar7;
        if (s___001a4468[0] != '\0') {
          pcVar11 = "]";
          cVar24 = s___001a4468[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 7:
        iVar29 = 0;
        if (s_result_depth_001a4afc[0] != '\0') {
          pcVar11 = "result.depth";
          cVar24 = s_result_depth_001a4afc[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 8:
        iVar29 = 0;
        if (s_result_eyePosition_001a4b1c[0] != '\0') {
          pcVar11 = "result.eyePosition";
          cVar24 = s_result_eyePosition_001a4b1c[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 9:
        iVar29 = 0;
        if (s_result_clipVertex_001a4b30[0] != '\0') {
          pcVar11 = "result.clipVertex";
          cVar24 = s_result_clipVertex_001a4b30[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        break;
      case 10:
        iVar7 = 0;
        if (s_result_attrib__001a4b0c[0] != '\0') {
          pcVar11 = "result.attrib[";
          cVar24 = s_result_attrib__001a4b0c[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar7] = cVar24;
            iVar7 = iVar7 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar7;
        iVar7 = FUN_0000cdf0(local_84,*puVar13 & 0x1f);
        iVar29 = 0;
        local_84 = local_84 + iVar7;
        if (s___001a4468[0] != '\0') {
          pcVar11 = "]";
          cVar24 = s___001a4468[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
      }
      local_84 = local_84 + iVar29;
switchD_00013960_caseD_0:
      iVar7 = 0;
      if (s___001a46fc[0] != '\0') {
        pcVar11 = ";\n";
        cVar24 = s___001a46fc[0];
        do {
          pcVar11 = pcVar11 + 1;
          local_84[iVar7] = cVar24;
          iVar7 = iVar7 + 1;
          cVar24 = *pcVar11;
        } while (cVar24 != '\0');
      }
      local_84 = local_84 + iVar7;
      iVar7 = FUN_0000c8a0(local_80,&local_88,&local_84);
      if (iVar7 == 0) goto LAB_00014048;
LAB_000140a0:
      uVar38 = uVar38 + 1;
      puVar13 = puVar13 + 2;
    } while (uVar36 != uVar38);
  }
  if ((uVar36 != 0) || (bVar3)) {
    iVar7 = 0;
    if (s__001a45c0[0] != '\0') {
      pcVar11 = "\n";
      iVar7 = 0;
      cVar24 = s__001a45c0[0];
      do {
        pcVar11 = pcVar11 + 1;
        local_84[iVar7] = cVar24;
        iVar7 = iVar7 + 1;
        cVar24 = *pcVar11;
      } while (cVar24 != '\0');
    }
    local_84 = local_84 + iVar7;
  }
  uVar36 = param_1[0x14];
  uVar32 = param_1[0x15];
  if (0 < (int)uVar36) {
    iVar7 = 0;
    sVar30 = 0;
    uVar38 = uVar36;
    do {
      if ((param_1[uVar32 * 2 + iVar7 * 2] >> 0x12 & 0xff) - 0x4b < 2) {
        sVar30 = sVar30 + 1;
      }
      iVar7 = iVar7 + (param_1[uVar32 * 2 + iVar7 * 2] >> 0x1d) + 2;
      uVar38 = uVar38 - 1;
    } while (uVar38 != 0);
    if (sVar30 == 0) {
      local_74 = (uint *)0x0;
      local_78 = (void *)0x0;
      iVar21 = 0;
      bVar4 = true;
    }
    else {
      local_74 = _malloc(sVar30 << 2);
      _memset(local_74,0,sVar30);
      local_78 = _malloc(sVar30 << 2);
      bVar2 = false;
      bVar4 = true;
      _memset(local_78,0,sVar30);
      uVar38 = 0;
      iVar29 = 0;
      iVar7 = 0;
      do {
        iVar21 = iVar7;
        if ((param_1[uVar32 * 2 + iVar29 * 2] >> 0x12 & 0xff) - 0x4b < 2) {
          uVar39 = param_1[uVar32 * 2 + iVar29 * 2] & 0x3ffff;
          uVar18 = (param_1 + uVar32 * 2 + iVar29 * 2)[1] & 0x3ffff;
          if (bVar2) {
            if ((int)*local_74 < (int)uVar18) {
              iVar34 = 0;
              puVar13 = local_74;
              iVar23 = iVar7;
              do {
                iVar34 = iVar34 + 1;
                iVar23 = iVar23 + -1;
                if (iVar23 == 0) goto LAB_00014230;
                puVar13 = puVar13 + 1;
              } while ((int)*puVar13 < (int)uVar18);
            }
            else {
              iVar34 = 0;
            }
          }
          else {
            if (bVar4) {
LAB_00014230:
              iVar21 = iVar7 + 1;
              bVar2 = 0 < iVar21;
              bVar4 = iVar21 == 0;
              local_74[iVar7] = uVar18;
              *(uint *)((int)local_78 + iVar7 * 4) = uVar39;
              goto LAB_00014300;
            }
            iVar34 = 0;
          }
          uVar31 = local_74[iVar34];
          if (uVar18 != uVar31) {
            local_74[iVar34] = uVar18;
            iVar21 = iVar7 + 1;
            iVar23 = iVar34 + 1;
            uVar26 = *(undefined4 *)((int)local_78 + iVar34 * 4);
            *(uint *)((int)local_78 + iVar34 * 4) = uVar39;
            if (iVar23 < iVar7) {
              iVar7 = iVar7 - iVar23;
              iVar34 = 0;
              puVar22 = (undefined4 *)(iVar23 * 4 + (int)local_78);
              puVar13 = local_74 + iVar23;
              uVar19 = uVar26;
              uVar39 = uVar31;
              do {
                uVar31 = *puVar13;
                *puVar13 = uVar39;
                iVar34 = iVar34 + 1;
                puVar13 = puVar13 + 1;
                uVar26 = *puVar22;
                *puVar22 = uVar19;
                puVar22 = puVar22 + 1;
                iVar7 = iVar7 + -1;
                uVar19 = uVar26;
                uVar39 = uVar31;
              } while (iVar7 != 0);
              iVar23 = iVar23 + iVar34;
            }
            bVar2 = 0 < iVar21;
            bVar4 = iVar21 == 0;
            local_74[iVar23] = uVar31;
            *(undefined4 *)((int)local_78 + iVar23 * 4) = uVar26;
          }
        }
LAB_00014300:
        uVar38 = uVar38 + 1;
        iVar29 = iVar29 + (param_1[uVar32 * 2 + iVar29 * 2] >> 0x1d) + 2;
        iVar7 = iVar21;
      } while (uVar36 != uVar38);
    }
    local_58 = local_80;
    local_5c = &local_84;
    local_54 = ((unsigned char *)0x0019f634);
    iVar29 = 0;
    local_64 = s_MUL_V_001df634;
    local_68 = ((unsigned char *)0x0019f634);
    iVar7 = 0;
    uVar38 = 0;
    iVar34 = 1;
    do {
      puVar13 = param_1 + uVar32 * 2 + iVar29 * 2;
      if (((param_1[uVar32 * 2 + iVar29 * 2] & 0x3ffff) == 0) && (!bVar3)) {
        iVar23 = 0;
        if (s_main__001a4b44[0] != '\0') {
          pcVar11 = "main:\n";
          iVar23 = 0;
          cVar24 = s_main__001a4b44[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar23] = cVar24;
            iVar23 = iVar23 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar23;
      }
      if ((bVar4) || (iVar21 <= iVar7)) {
        uVar39 = *puVar13;
      }
      else {
        uVar39 = *puVar13;
        if ((uVar39 & 0x3ffff) == local_74[iVar7]) {
          if (0 < iVar34 + -1) {
            iVar23 = 0;
            do {
              iVar14 = 0;
              if (s__001a4b4c[0] != '\0') {
                pcVar11 = "  ";
                iVar14 = 0;
                cVar24 = s__001a4b4c[0];
                do {
                  pcVar11 = pcVar11 + 1;
                  local_84[iVar14] = cVar24;
                  iVar14 = iVar14 + 1;
                  cVar24 = *pcVar11;
                } while (cVar24 != '\0');
              }
              iVar23 = iVar23 + 1;
              local_84 = local_84 + iVar14;
            } while (iVar34 + -1 != iVar23);
          }
          iVar23 = 0;
          if (s_label__001a4b50[0] != '\0') {
            pcVar11 = "label_";
            cVar24 = s_label__001a4b50[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          local_84 = local_84 + iVar23;
          iVar23 = FUN_0000cdf0(local_84,iVar7);
          iVar7 = iVar7 + 1;
          iVar14 = 0;
          if (s___001a4b58[0] != '\0') {
            pcVar11 = ":\n";
            cVar24 = s___001a4b58[0];
            do {
              pcVar11 = pcVar11 + 1;
              local_84[iVar14 + iVar23] = cVar24;
              iVar14 = iVar14 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          uVar39 = *puVar13;
          local_84 = local_84 + iVar14 + iVar23;
        }
      }
      puVar6 = local_84;
      uVar18 = uVar39 & 0x3fc0000;
      if ((((uVar18 == 0x1ac0000) || (uVar18 == 0x1600000)) || (uVar18 == 0x1640000)) ||
         ((uVar18 == 0x1680000 || (uVar18 == 0x16c0000)))) {
        iVar34 = iVar34 + -1;
      }
      uVar18 = puVar13[1];
      uVar31 = uVar39 >> 0x12 & 0xff;
      puVar15 = local_84;
      if (0 < iVar34) {
        iVar23 = 0;
        do {
          iVar14 = 0;
          if (s__001a4b4c[0] != '\0') {
            pcVar11 = "  ";
            cVar24 = s__001a4b4c[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar14] = cVar24;
              iVar14 = iVar14 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          iVar23 = iVar23 + 1;
          puVar15 = puVar15 + iVar14;
        } while (iVar23 != iVar34);
      }
      iVar23 = 0;
      pcVar11 = *(char **)(local_64 + uVar31 * 4 + -0x6630);
      cVar24 = *pcVar11;
      if (cVar24 != '\0') {
        iVar23 = 0;
        do {
          puVar15[iVar23] = cVar24;
          iVar23 = iVar23 + 1;
          cVar24 = pcVar11[iVar23];
        } while (cVar24 != '\0');
      }
      puVar15 = puVar15 + iVar23;
      iVar23 = 0;
      switch(uVar31) {
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
        uVar26 = FUN_0000ca50(puVar15,puVar13[1] >> 0x12 & 3);
        uVar17 = puVar13[1];
        iVar23 = FUN_0000c930(uVar26,uVar17 >> 0x16 & 1,uVar17 >> 0x15 & 1,uVar17 >> 0x14 & 1);
        if (!bVar3) {
          uVar17 = puVar13[1];
          iVar23 = FUN_0000df50(iVar23,uVar17 >> 0x1a & 3,uVar17 >> 0x1c & 1,uVar17 >> 0x17 & 7);
        }
        iVar14 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            *(char *)(iVar23 + iVar14) = cVar24;
            iVar14 = iVar14 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_60 = ((unsigned char *)0x0019f634);
        iVar14 = FUN_0000d380(puVar13,iVar23 + iVar14,pvVar27,pvVar28,1,uVar1);
        cVar24 = ((unsigned char *)0x00004ec0)[(int)local_60];
        if (cVar24 != '\0') {
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          iVar8 = 0;
          cVar10 = cVar24;
          do {
            *(char *)(iVar14 + iVar8) = cVar10;
            iVar8 = iVar8 + 1;
            cVar10 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar10 != '\0');
        }
        else {
          iVar8 = 0;
        }
        iVar23 = 2;
        puVar15 = (undefined1 *)
                  FUN_0000e1f0(puVar13,iVar14 + iVar8,local_6c,local_70,pvVar27,pvVar28,2,uVar1);
        if (uVar39 >> 0x1d == 2) {
          if (cVar24 != '\0') {
            iVar23 = 0;
            pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
            do {
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
              pcVar11 = pcVar11 + 1;
            } while (cVar24 != '\0');
          }
          else {
            iVar23 = 0;
          }
          puVar15 = puVar15 + iVar23;
          goto LAB_000154ec;
        }
        break;
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
        uVar26 = FUN_0000ca50(puVar15,puVar13[1] >> 0x12 & 3);
        uVar39 = puVar13[1];
        iVar23 = FUN_0000c930(uVar26,uVar39 >> 0x16 & 1,uVar39 >> 0x15 & 1,uVar39 >> 0x14 & 1);
        if (!bVar3) {
          uVar39 = puVar13[1];
          iVar23 = FUN_0000df50(iVar23,uVar39 >> 0x1a & 3,uVar39 >> 0x1c & 1,uVar39 >> 0x17 & 7);
        }
        iVar14 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            *(char *)(iVar23 + iVar14) = cVar24;
            iVar14 = iVar14 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_60 = ((unsigned char *)0x0019f634);
        iVar23 = FUN_0000d380(puVar13,iVar23 + iVar14,pvVar27,pvVar28,1,uVar1);
        cVar24 = ((unsigned char *)0x00004ec0)[(int)local_60];
        if (cVar24 != '\0') {
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          iVar14 = 0;
          cVar10 = cVar24;
          do {
            *(char *)(iVar23 + iVar14) = cVar10;
            iVar14 = iVar14 + 1;
            cVar10 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar10 != '\0');
        }
        else {
          iVar14 = 0;
        }
        iVar23 = FUN_0000e1f0(puVar13,iVar23 + iVar14,local_6c,local_70,pvVar27,pvVar28,2,uVar1);
        if (cVar24 != '\0') {
          iVar14 = 0;
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          do {
            *(char *)(iVar23 + iVar14) = cVar24;
            iVar14 = iVar14 + 1;
            cVar24 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar24 != '\0');
        }
        else {
          iVar14 = 0;
        }
        puVar15 = (undefined1 *)(iVar23 + iVar14);
LAB_000154ec:
        iVar23 = 3;
        puVar15 = (undefined1 *)
                  FUN_0000e1f0(puVar13,puVar15,local_6c,local_70,pvVar27,pvVar28,3,uVar1);
        break;
      case 0x3b:
      case 0x3c:
      case 0x3d:
      case 0x3e:
      case 0x3f:
      case 0x40:
      case 0x53:
      case 0x67:
      case 0x68:
        uVar26 = FUN_0000ca50(puVar15,puVar13[1] >> 0x12 & 3);
        uVar39 = puVar13[1];
        iVar23 = FUN_0000c930(uVar26,uVar39 >> 0x16 & 1,uVar39 >> 0x15 & 1,uVar39 >> 0x14 & 1);
        if (!bVar3) {
          uVar39 = puVar13[1];
          iVar23 = FUN_0000df50(iVar23,uVar39 >> 0x1a & 3,uVar39 >> 0x1c & 1,uVar39 >> 0x17 & 7);
        }
        iVar14 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            *(char *)(iVar23 + iVar14) = cVar24;
            iVar14 = iVar14 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_60 = ((unsigned char *)0x0019f634);
        iVar23 = FUN_0000d380(puVar13,iVar23 + iVar14,pvVar27,pvVar28,1,uVar1);
        cVar24 = ((unsigned char *)0x00004ec0)[(int)local_60];
        bVar2 = cVar24 != '\0';
        if (bVar2) {
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          iVar14 = 0;
          cVar10 = cVar24;
          do {
            *(char *)(iVar23 + iVar14) = cVar10;
            iVar14 = iVar14 + 1;
            cVar10 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar10 != '\0');
        }
        else {
          iVar14 = 0;
        }
        iVar23 = FUN_0000e1f0(puVar13,iVar23 + iVar14,local_6c,local_70,pvVar27,pvVar28,2,uVar1);
        if (bVar2) {
          iVar14 = 0;
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          cVar10 = cVar24;
          do {
            *(char *)(iVar23 + iVar14) = cVar10;
            iVar14 = iVar14 + 1;
            cVar10 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar10 != '\0');
        }
        else {
          iVar14 = 0;
        }
        iVar14 = FUN_0000e1f0(puVar13,iVar23 + iVar14,local_6c,local_70,pvVar27,pvVar28,3,uVar1);
        if (bVar2) {
          iVar8 = 0;
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          do {
            *(char *)(iVar14 + iVar8) = cVar24;
            iVar8 = iVar8 + 1;
            cVar24 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar24 != '\0');
        }
        else {
          iVar8 = 0;
        }
        iVar23 = 4;
        puVar15 = (undefined1 *)
                  FUN_0000e1f0(puVar13,iVar14 + iVar8,local_6c,local_70,pvVar27,pvVar28,4,uVar1);
        break;
      case 0x41:
        uVar39 = puVar13[1];
        iVar23 = FUN_0000c930(puVar15,uVar39 >> 0x16 & 1,uVar39 >> 0x15 & 1,uVar39 >> 0x14 & 1);
        if (!bVar3) {
          uVar39 = puVar13[1];
          iVar23 = FUN_0000df50(iVar23,uVar39 >> 0x1a & 3,uVar39 >> 0x1c & 1,uVar39 >> 0x17 & 7);
        }
        iVar14 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            *(char *)(iVar23 + iVar14) = cVar24;
            iVar14 = iVar14 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        iVar14 = FUN_0000d380(puVar13,iVar23 + iVar14,pvVar27,pvVar28,1,uVar1);
        iVar8 = 0;
        if (s___001a44f4[0] != '\0') {
          pcVar11 = ", ";
          cVar24 = s___001a44f4[0];
          do {
            pcVar11 = pcVar11 + 1;
            *(char *)(iVar14 + iVar8) = cVar24;
            iVar8 = iVar8 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        iVar23 = 3;
        puVar15 = (undefined1 *)
                  FUN_0000e1f0(puVar13,iVar14 + iVar8,local_6c,local_70,pvVar27,pvVar28,2,uVar1);
        break;
      case 0x42:
      case 0x43:
        uVar39 = puVar13[1];
        iVar23 = FUN_0000c930(puVar15,uVar39 >> 0x16 & 1,uVar39 >> 0x15 & 1,uVar39 >> 0x14 & 1);
        if (!bVar3) {
          uVar39 = puVar13[1];
          iVar23 = FUN_0000df50(iVar23,uVar39 >> 0x1a & 3,uVar39 >> 0x1c & 1,uVar39 >> 0x17 & 7);
        }
        iVar14 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            *(char *)(iVar23 + iVar14) = cVar24;
            iVar14 = iVar14 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_60 = ((unsigned char *)0x0019f634);
        iVar23 = FUN_0000d380(puVar13,iVar23 + iVar14,pvVar27,pvVar28,1,uVar1);
        cVar24 = ((unsigned char *)0x00004ec0)[(int)local_60];
        if (cVar24 != '\0') {
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          iVar14 = 0;
          cVar10 = cVar24;
          do {
            *(char *)(iVar23 + iVar14) = cVar10;
            iVar14 = iVar14 + 1;
            cVar10 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar10 != '\0');
        }
        else {
          iVar14 = 0;
        }
        iVar14 = FUN_0000e1f0(puVar13,iVar23 + iVar14,local_6c,local_70,pvVar27,pvVar28,2,uVar1);
        if (cVar24 != '\0') {
          iVar8 = 0;
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          do {
            *(char *)(iVar14 + iVar8) = cVar24;
            iVar8 = iVar8 + 1;
            cVar24 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar24 != '\0');
        }
        else {
          iVar8 = 0;
        }
        iVar23 = uVar1 + 3;
        puVar15 = (undefined1 *)
                  FUN_0000f250(puVar13,iVar14 + iVar8,local_6c,local_70,pvVar27,pvVar28,3,uVar1);
        break;
      case 0x44:
      case 0x45:
      case 0x46:
      case 0x47:
        uVar39 = puVar13[1];
        iVar23 = FUN_0000c930(puVar15,uVar39 >> 0x16 & 1,uVar39 >> 0x15 & 1,uVar39 >> 0x14 & 1);
        if (!bVar3) {
          uVar39 = puVar13[1];
          iVar23 = FUN_0000df50(iVar23,uVar39 >> 0x1a & 3,uVar39 >> 0x1c & 1,uVar39 >> 0x17 & 7);
        }
        iVar14 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            *(char *)(iVar23 + iVar14) = cVar24;
            iVar14 = iVar14 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_60 = ((unsigned char *)0x0019f634);
        iVar23 = FUN_0000d380(puVar13,iVar23 + iVar14,pvVar27,pvVar28,1,uVar1);
        cVar24 = ((unsigned char *)0x00004ec0)[(int)local_60];
        bVar2 = cVar24 != '\0';
        if (bVar2) {
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          iVar14 = 0;
          cVar10 = cVar24;
          do {
            *(char *)(iVar23 + iVar14) = cVar10;
            iVar14 = iVar14 + 1;
            cVar10 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar10 != '\0');
        }
        else {
          iVar14 = 0;
        }
        iVar23 = FUN_0000e1f0(puVar13,iVar23 + iVar14,local_6c,local_70,pvVar27,pvVar28,2,uVar1);
        if (bVar2) {
          iVar14 = 0;
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          cVar10 = cVar24;
          do {
            *(char *)(iVar23 + iVar14) = cVar10;
            iVar14 = iVar14 + 1;
            cVar10 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar10 != '\0');
        }
        else {
          iVar14 = 0;
        }
        puVar15 = (undefined1 *)
                  FUN_0000f250(puVar13,iVar23 + iVar14,local_6c,local_70,pvVar27,pvVar28,3,uVar1);
        if (bVar3) {
          iVar23 = 3;
        }
        else {
          if (bVar2) {
            iVar14 = 0;
            pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
            do {
              puVar15[iVar14] = cVar24;
              iVar14 = iVar14 + 1;
              cVar24 = *pcVar11;
              pcVar11 = pcVar11 + 1;
            } while (cVar24 != '\0');
          }
          else {
            iVar14 = 0;
          }
          iVar23 = uVar1 + 4;
          puVar15 = (undefined1 *)
                    FUN_0000e1f0(puVar13,puVar15 + iVar14,local_6c,local_70,pvVar27,pvVar28,iVar23,
                                 uVar1);
        }
        break;
      case 0x48:
      case 0x49:
      case 0x4a:
        if (!bVar3) {
          uVar39 = puVar13[1];
          puVar15 = (undefined1 *)
                    FUN_0000df50(puVar15,uVar39 >> 0x1a & 3,uVar39 >> 0x1c & 1,uVar39 >> 0x17 & 7);
        }
        iVar23 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          iVar23 = 0;
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            puVar15[iVar23] = cVar24;
            iVar23 = iVar23 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        puVar15 = puVar15 + iVar23;
        puVar12 = puVar13 + 2;
        if ((puVar13[2] & 0xe0000) == 0x80000) {
          iVar23 = 0;
          if (s_adr_001a44f0[0] != '\0') {
            pcVar11 = "adr";
            iVar23 = 0;
            cVar24 = s_adr_001a44f0[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          iVar14 = FUN_0000cdf0(puVar15 + iVar23,*(undefined2 *)((int)puVar13 + 0xe));
          puVar15 = puVar15 + iVar23 + iVar14;
        }
        uVar39 = *puVar12;
        if ((uVar39 & 0x1e000) != 0x1e000) {
          iVar23 = 0;
          if (s___001a448c[0] != '\0') {
            pcVar11 = ".";
            cVar24 = s___001a448c[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
            uVar39 = *puVar12;
          }
          puVar15 = puVar15 + iVar23;
          if (bVar3) {
            if ((uVar39 & 0x2000) != 0) {
              iVar23 = 0;
              if (s_x_001a4490[0] != '\0') {
                pcVar11 = "x";
                cVar24 = s_x_001a4490[0];
                do {
                  pcVar11 = pcVar11 + 1;
                  puVar15[iVar23] = cVar24;
                  iVar23 = iVar23 + 1;
                  cVar24 = *pcVar11;
                } while (cVar24 != '\0');
                uVar39 = *puVar12;
              }
              puVar15 = puVar15 + iVar23;
            }
            if ((uVar39 & 0x4000) != 0) {
              iVar23 = 0;
              if (s_y_001a4494[0] != '\0') {
                pcVar11 = "y";
                cVar24 = s_y_001a4494[0];
                do {
                  pcVar11 = pcVar11 + 1;
                  puVar15[iVar23] = cVar24;
                  iVar23 = iVar23 + 1;
                  cVar24 = *pcVar11;
                } while (cVar24 != '\0');
                uVar39 = *puVar12;
              }
              puVar15 = puVar15 + iVar23;
            }
            if ((uVar39 & 0x8000) != 0) {
              iVar23 = 0;
              if (s_z_001a4498[0] != '\0') {
                pcVar11 = "z";
                cVar24 = s_z_001a4498[0];
                do {
                  pcVar11 = pcVar11 + 1;
                  puVar15[iVar23] = cVar24;
                  iVar23 = iVar23 + 1;
                  cVar24 = *pcVar11;
                } while (cVar24 != '\0');
                uVar39 = *puVar12;
              }
              puVar15 = puVar15 + iVar23;
            }
            if ((uVar39 & 0x10000) != 0) {
              iVar23 = 0;
              if (s_w_001a449c[0] != '\0') {
                pcVar11 = "w";
                cVar24 = s_w_001a449c[0];
                do {
                  pcVar11 = pcVar11 + 1;
                  puVar15[iVar23] = cVar24;
                  iVar23 = iVar23 + 1;
                  cVar24 = *pcVar11;
                } while (cVar24 != '\0');
              }
              goto LAB_00016158;
            }
          }
          else {
            if ((uVar39 & 0x2000) != 0) {
              iVar23 = 0;
              if (s_x_001a4490[0] != '\0') {
                pcVar11 = "x";
                cVar24 = s_x_001a4490[0];
                do {
                  pcVar11 = pcVar11 + 1;
                  puVar15[iVar23] = cVar24;
                  iVar23 = iVar23 + 1;
                  cVar24 = *pcVar11;
                } while (cVar24 != '\0');
                uVar39 = *puVar12;
              }
              puVar15 = puVar15 + iVar23;
            }
            if (((uVar39 & 0xc00) != 0) && ((uVar39 & 0x4000) != 0)) {
              iVar23 = 0;
              if (s_y_001a4494[0] != '\0') {
                pcVar11 = "y";
                cVar24 = s_y_001a4494[0];
                do {
                  pcVar11 = pcVar11 + 1;
                  puVar15[iVar23] = cVar24;
                  iVar23 = iVar23 + 1;
                  cVar24 = *pcVar11;
                } while (cVar24 != '\0');
                uVar39 = *puVar12;
              }
              puVar15 = puVar15 + iVar23;
            }
            if ((1 < (uVar39 >> 10 & 3)) && ((uVar39 & 0x8000) != 0)) {
              iVar23 = 0;
              if (s_z_001a4498[0] != '\0') {
                pcVar11 = "z";
                cVar24 = s_z_001a4498[0];
                do {
                  pcVar11 = pcVar11 + 1;
                  puVar15[iVar23] = cVar24;
                  iVar23 = iVar23 + 1;
                  cVar24 = *pcVar11;
                } while (cVar24 != '\0');
                uVar39 = *puVar12;
              }
              puVar15 = puVar15 + iVar23;
            }
            if ((2 < (uVar39 >> 10 & 3)) && ((uVar39 & 0x10000) != 0)) {
              iVar23 = 0;
              if (s_w_001a449c[0] != '\0') {
                pcVar11 = "w";
                cVar24 = s_w_001a449c[0];
                do {
                  pcVar11 = pcVar11 + 1;
                  puVar15[iVar23] = cVar24;
                  iVar23 = iVar23 + 1;
                  cVar24 = *pcVar11;
                } while (cVar24 != '\0');
              }
LAB_00016158:
              puVar15 = puVar15 + iVar23;
            }
          }
        }
        iVar23 = 0;
        if (s___001a44f4[0] != '\0') {
          pcVar11 = ", ";
          cVar24 = s___001a44f4[0];
          do {
            pcVar11 = pcVar11 + 1;
            puVar15[iVar23] = cVar24;
            iVar23 = iVar23 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
LAB_000161a0:
        puVar15 = puVar15 + iVar23;
        goto LAB_00014cb8;
      case 0x4b:
      case 0x4c:
        iVar23 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          iVar23 = 0;
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            puVar15[iVar23] = cVar24;
            iVar23 = iVar23 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        iVar14 = -1;
        if (local_74 != (uint *)0x0) {
          iVar14 = 0;
          uVar39 = *local_74;
          while ((puVar13[1] & 0x3ffff) != uVar39) {
            iVar14 = iVar14 + 1;
            uVar39 = local_74[iVar14];
          }
        }
        iVar14 = FUN_001a32d0(puVar15 + iVar23,"label_%i",iVar14);
        puVar15 = puVar15 + iVar23 + iVar14;
        if (uVar31 != 0x4b) goto switchD_000146d8_caseD_4d;
        puVar12 = puVar13 + 2;
        switch(puVar13[2] >> 0x1c & 7) {
        case 0:
          iVar23 = 0;
          if (s__TR_001a44a0[0] != '\0') {
            pcVar11 = " (TR";
            cVar24 = s__TR_001a44a0[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 1:
          iVar23 = 0;
          if (s__EQ_001a44a8[0] != '\0') {
            pcVar11 = " (EQ";
            cVar24 = s__EQ_001a44a8[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 2:
          iVar23 = 0;
          if (s__GE_001a44b0[0] != '\0') {
            pcVar11 = " (GE";
            cVar24 = s__GE_001a44b0[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 3:
          iVar23 = 0;
          if (s__GT_001a44b8[0] != '\0') {
            pcVar11 = " (GT";
            cVar24 = s__GT_001a44b8[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 4:
          iVar23 = 0;
          if (s__LE_001a44c0[0] != '\0') {
            pcVar11 = " (LE";
            cVar24 = s__LE_001a44c0[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 5:
          iVar23 = 0;
          if (s__LT_001a44c8[0] != '\0') {
            pcVar11 = " (LT";
            cVar24 = s__LT_001a44c8[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 6:
          iVar23 = 0;
          if (s__NE_001a44d0[0] != '\0') {
            pcVar11 = " (NE";
            cVar24 = s__NE_001a44d0[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 7:
          iVar23 = 0;
          if (s__FL_001a44d8[0] != '\0') {
            pcVar11 = " (FL";
            cVar24 = s__FL_001a44d8[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        default:
          goto switchD_00014df8_default;
        }
        puVar15 = puVar15 + iVar23;
switchD_00014df8_default:
        if ((int)*puVar12 < 0) {
          *puVar15 = 0x31;
          puVar15 = puVar15 + 1;
        }
        iVar23 = 1;
        *puVar15 = 0x2e;
        puVar15[1] = (((byte)(*puVar12 >> 0x1a) & 3) + 1 & 3) + 0x77;
        puVar15[2] = (*(char *)puVar12 + 1U & 3) + 0x77;
        puVar15[3] = (((byte)(*puVar12 >> 0x16) & 3) + 1 & 3) + 0x77;
        uVar39 = *puVar12;
        puVar15[5] = 0x29;
        puVar15[4] = (((byte)(uVar39 >> 0x14) & 3) + 1 & 3) + 0x77;
        puVar15 = puVar15 + 6;
        break;
      case 0x4d:
      case 0x54:
      case 0x59:
      case 0x5a:
      case 0x5b:
      case 0x69:
      case 0x6b:
      case 0x6e:
switchD_000146d8_caseD_4d:
        iVar23 = 1;
        break;
      case 0x4f:
        iVar23 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            puVar15[iVar23] = cVar24;
            iVar23 = iVar23 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        goto LAB_00014cb4;
      case 0x55:
        iVar34 = iVar34 + 1;
        if (!bVar3) {
          uVar39 = puVar13[1];
          puVar15 = (undefined1 *)
                    FUN_0000df50(puVar15,uVar39 >> 0x1a & 3,uVar39 >> 0x1c & 1,uVar39 >> 0x17 & 7);
          iVar23 = 0;
          if (s__001a4b5c[0] != '\0') {
            pcVar11 = " ";
            cVar24 = s__001a4b5c[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          goto LAB_000161a0;
        }
        puVar12 = puVar13 + 2;
        switch(puVar13[2] >> 0x1c & 7) {
        case 0:
          iVar23 = 0;
          if (s_TR_001a4b60[0] != '\0') {
            pcVar11 = " TR";
            cVar24 = s_TR_001a4b60[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 1:
          iVar23 = 0;
          if (s_EQ_001a4b64[0] != '\0') {
            pcVar11 = " EQ";
            cVar24 = s_EQ_001a4b64[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 2:
          iVar23 = 0;
          if (s_GE_001a4b68[0] != '\0') {
            pcVar11 = " GE";
            cVar24 = s_GE_001a4b68[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 3:
          iVar23 = 0;
          if (s_GT_001a4b6c[0] != '\0') {
            pcVar11 = " GT";
            cVar24 = s_GT_001a4b6c[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 4:
          iVar23 = 0;
          if (s_LE_001a4b70[0] != '\0') {
            pcVar11 = " LE";
            cVar24 = s_LE_001a4b70[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 5:
          iVar23 = 0;
          if (s_LT_001a4b74[0] != '\0') {
            pcVar11 = " LT";
            cVar24 = s_LT_001a4b74[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 6:
          iVar23 = 0;
          if (s_NE_001a4b78[0] != '\0') {
            pcVar11 = " NE";
            cVar24 = s_NE_001a4b78[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        case 7:
          iVar23 = 0;
          if (s_FL_001a4b7c[0] != '\0') {
            pcVar11 = " FL";
            cVar24 = s_FL_001a4b7c[0];
            do {
              pcVar11 = pcVar11 + 1;
              puVar15[iVar23] = cVar24;
              iVar23 = iVar23 + 1;
              cVar24 = *pcVar11;
            } while (cVar24 != '\0');
          }
          break;
        default:
          goto switchD_00014940_default;
        }
        puVar15 = puVar15 + iVar23;
switchD_00014940_default:
        if ((int)*puVar12 < 0) {
          *puVar15 = 0x31;
          puVar15 = puVar15 + 1;
        }
        iVar23 = 1;
        *puVar15 = 0x2e;
        puVar15[1] = (((byte)(*puVar12 >> 0x1a) & 3) + 1 & 3) + 0x77;
        puVar15[2] = (*(char *)puVar12 + 1U & 3) + 0x77;
        puVar15[3] = (((byte)(*puVar12 >> 0x16) & 3) + 1 & 3) + 0x77;
        puVar15[4] = (((byte)(*puVar12 >> 0x14) & 3) + 1 & 3) + 0x77;
        puVar15 = puVar15 + 5;
        break;
      case 0x56:
      case 0x57:
        iVar34 = iVar34 + 1;
        iVar23 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            puVar15[iVar23] = cVar24;
            iVar23 = iVar23 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        goto LAB_00014cb4;
      case 0x58:
      case 0x6a:
        iVar34 = iVar34 + 1;
        iVar23 = 1;
        break;
      case 0x60:
      case 0x61:
        iVar23 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            puVar15[iVar23] = cVar24;
            iVar23 = iVar23 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
LAB_00014cb4:
        puVar15 = puVar15 + iVar23;
LAB_00014cb8:
        iVar23 = 2;
        puVar15 = (undefined1 *)
                  FUN_0000e1f0(puVar13,puVar15,local_6c,local_70,pvVar27,pvVar28,2,uVar1);
        break;
      case 0x62:
        uVar39 = puVar13[1];
        iVar23 = FUN_0000c930(puVar15,uVar39 >> 0x16 & 1,uVar39 >> 0x15 & 1,uVar39 >> 0x14 & 1);
        if (!bVar3) {
          uVar39 = puVar13[1];
          iVar23 = FUN_0000df50(iVar23,uVar39 >> 0x1a & 3,uVar39 >> 0x1c & 1,uVar39 >> 0x17 & 7);
        }
        iVar14 = 0;
        if (s__001a4b5c[0] != '\0') {
          pcVar11 = " ";
          cVar24 = s__001a4b5c[0];
          do {
            pcVar11 = pcVar11 + 1;
            *(char *)(iVar23 + iVar14) = cVar24;
            iVar14 = iVar14 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_60 = ((unsigned char *)0x0019f634);
        iVar23 = FUN_0000d380(puVar13,iVar23 + iVar14,pvVar27,pvVar28,1,uVar1);
        cVar24 = ((unsigned char *)0x00004ec0)[(int)local_60];
        bVar2 = cVar24 != '\0';
        if (bVar2) {
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          iVar14 = 0;
          cVar10 = cVar24;
          do {
            *(char *)(iVar23 + iVar14) = cVar10;
            iVar14 = iVar14 + 1;
            cVar10 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar10 != '\0');
        }
        else {
          iVar14 = 0;
        }
        iVar23 = FUN_0000e1f0(puVar13,iVar23 + iVar14,local_6c,local_70,pvVar27,pvVar28,2,uVar1);
        if (bVar2) {
          iVar14 = 0;
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          cVar10 = cVar24;
          do {
            *(char *)(iVar23 + iVar14) = cVar10;
            iVar14 = iVar14 + 1;
            cVar10 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar10 != '\0');
        }
        else {
          iVar14 = 0;
        }
        iVar23 = FUN_0000e1f0(puVar13,iVar23 + iVar14,local_6c,local_70,pvVar27,pvVar28,3,uVar1);
        if (bVar2) {
          iVar14 = 0;
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          cVar10 = cVar24;
          do {
            *(char *)(iVar23 + iVar14) = cVar10;
            iVar14 = iVar14 + 1;
            cVar10 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar10 != '\0');
        }
        else {
          iVar14 = 0;
        }
        iVar14 = FUN_0000e1f0(puVar13,iVar23 + iVar14,local_6c,local_70,pvVar27,pvVar28,4,uVar1);
        if (bVar2) {
          iVar8 = 0;
          pcVar11 = ((unsigned char *)0x00004ec1) + (int)local_60;
          do {
            *(char *)(iVar14 + iVar8) = cVar24;
            iVar8 = iVar8 + 1;
            cVar24 = *pcVar11;
            pcVar11 = pcVar11 + 1;
          } while (cVar24 != '\0');
        }
        else {
          iVar8 = 0;
        }
        iVar23 = uVar1 + 5;
        puVar15 = (undefined1 *)
                  FUN_0000f250(puVar13,iVar14 + iVar8,local_6c,local_70,pvVar27,pvVar28,5,uVar1);
      }
      iVar14 = 0;
      cVar24 = ((unsigned char *)0x00005558)[(int)local_68];
      if (cVar24 != '\0') {
        pcVar11 = ((unsigned char *)0x00005559) + (int)local_68;
        iVar14 = 0;
        do {
          puVar15[iVar14] = cVar24;
          iVar14 = iVar14 + 1;
          cVar24 = *pcVar11;
          pcVar11 = pcVar11 + 1;
        } while (cVar24 != '\0');
      }
      puVar15 = puVar15 + iVar14;
      if (!bVar3) {
        switch(uVar31) {
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
          iVar14 = FUN_001a32d0(puVar15,"    # Target: %d",uVar18 & 0x3ffff);
          puVar15 = puVar15 + iVar14;
        }
      }
      iVar14 = 0;
      cVar24 = ((unsigned char *)0x00004f8c)[(int)local_54];
      if (cVar24 != '\0') {
        pcVar11 = ((unsigned char *)0x00004f8d) + (int)local_54;
        iVar14 = 0;
        do {
          puVar15[iVar14] = cVar24;
          iVar14 = iVar14 + 1;
          cVar24 = *pcVar11;
          pcVar11 = pcVar11 + 1;
        } while (cVar24 != '\0');
      }
      local_84 = puVar15 + (int)(local_84 + (iVar14 - (int)puVar6));
      iVar14 = FUN_0000c8a0(local_58,&local_88,local_5c);
      if (iVar14 == 0) {
        if (local_6c != (void *)0x0) {
          _free(local_6c);
        }
        if (local_70 != (void *)0x0) {
          _free(local_70);
        }
        if (pvVar27 != (void *)0x0) {
          _free(pvVar27);
        }
        if (pvVar28 != (void *)0x0) {
          _free(pvVar28);
        }
        if (bVar4) goto LAB_00016630;
        _free(local_74);
        pvVar28 = local_78;
        goto LAB_000163f0;
      }
      uVar38 = uVar38 + 1;
      iVar29 = iVar29 + iVar23 + 1;
    } while (uVar36 != uVar38);
    if (!bVar4) {
      if ((iVar7 < iVar21) && (uVar36 + 1 == local_74[iVar7])) {
        iVar29 = 0;
        if (s_label__001a4ba4[0] != '\0') {
          pcVar11 = "  label_";
          cVar24 = s_label__001a4ba4[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar29;
        iVar7 = FUN_0000cdf0(local_84,iVar7);
        iVar29 = 0;
        if (s___001a4b58[0] != '\0') {
          pcVar11 = ":\n";
          cVar24 = s___001a4b58[0];
          do {
            pcVar11 = pcVar11 + 1;
            local_84[iVar29 + iVar7] = cVar24;
            iVar29 = iVar29 + 1;
            cVar24 = *pcVar11;
          } while (cVar24 != '\0');
        }
        local_84 = local_84 + iVar29 + iVar7;
      }
      _free(local_74);
      _free(local_78);
    }
  }
  iVar7 = 0;
  if (s_END_001a4bb0[0] != '\0') {
    pcVar11 = "END\n";
    iVar7 = 0;
    cVar24 = s_END_001a4bb0[0];
    do {
      pcVar11 = pcVar11 + 1;
      local_84[iVar7] = cVar24;
      iVar7 = iVar7 + 1;
      cVar24 = *pcVar11;
    } while (cVar24 != '\0');
  }
  local_84[iVar7] = 0;
  local_84 = local_84 + iVar7 + 1;
  if (local_6c != (void *)0x0) {
    _free(local_6c);
  }
  if (local_70 != (void *)0x0) {
    _free(local_70);
  }
  if (pvVar27 != (void *)0x0) {
    _free(pvVar27);
  }
  if (pvVar28 != (void *)0x0) {
    _free(pvVar28);
  }
  if ((int)local_84 - (int)local_88[0] < 1) {
    _free(local_88[0]);
    local_88[0] = (void *)0x0;
  }
  else {
    local_88[0] = _realloc(local_88[0],(int)local_84 - (int)local_88[0]);
  }
  return local_88[0];
LAB_00014048:
  if (local_6c != (void *)0x0) {
    _free(local_6c);
  }
joined_r0x000112bc:
  if (local_70 != (void *)0x0) {
    _free(local_70);
  }
LAB_00014070:
  if (pvVar27 != (void *)0x0) {
    _free(pvVar27);
  }
  if (pvVar28 != (void *)0x0) {
    _free(pvVar28);
  }
LAB_00016630:
  _free(local_88[0]);
  return (void *)0x0;
}

/* FUN_00016fc0 @ 0x16fc0 (272 bytes) */
int FUN_00016fc0(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (param_1 != 0x405) {
    if (param_1 < 0x406) {
      if (param_1 == 0x401) {
LAB_00017070:
        if ((param_2 & 0x10) == 0) {
          return 1;
        }
        return 3;
      }
      if (param_1 < 0x402) {
        if (param_1 == 0) {
          return 0x11;
        }
        if (param_1 == 0x400) {
          return 1;
        }
      }
      else {
        if (param_1 == 0x403) {
          if ((param_2 & 0x400) == 0) {
            return 1;
          }
          if ((param_2 & 0x10) == 0) {
            return 0;
          }
          return 2;
        }
        if (0x403 < param_1) {
          return 1;
        }
      }
    }
    else {
      if (param_1 == 0x408) {
        return 1;
      }
      if (param_1 < 0x409) {
        if (param_1 == 0x406) {
          return 1;
        }
        if (param_1 == 0x407) goto LAB_00017070;
      }
      else if (param_1 == 0x40a) {
        if (0x1ff < (param_2 & 0x300)) {
          return 8;
        }
      }
      else if (param_1 < 0x40a) {
        if (0xff < (param_2 & 0x300)) {
          return 7;
        }
      }
      else if ((param_1 == 0x40b) && (0x2ff < (param_2 & 0x300))) {
        return 9;
      }
    }
  }
  if ((param_2 & 0x400) == 0) {
    return 1;
  }
  return 0;
}

/* FUN_00017100 @ 0x17100 (84 bytes) */
int FUN_00017100(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  if (param_2 == 0xcb) {
    if (*(char *)(param_1 + 0x2a80) != '\0') {
      *(char *)(param_1 + 0x146) = (char)*param_3;
      return 1;
    }
  }
  else if ((param_2 == 0xde) && (*(char *)(param_1 + 0x2a80) != '\0')) {
    *(char *)(param_1 + 0x142) = (char)*param_3;
    return 1;
  }
  return 0;
}

/* FUN_00017160 @ 0x17160 (236 bytes) */
int FUN_00017160(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *param_2 & 0x80ffffff;
  *param_2 = uVar2;
  if (param_3 == 0) {
    *(undefined1 *)(param_1 + 0x143) = 1;
  }
  else {
    iVar3 = *(int *)(param_3 + 0xc);
    if (iVar3 - 0xde0U < 2) {
      uVar2 = uVar2 | 0x10000000;
      *param_2 = uVar2;
    }
    else if (iVar3 == 0x84f5) {
      uVar2 = uVar2 | 0x20000000;
      *param_2 = uVar2;
    }
    else if (iVar3 == 0x8513) {
      uVar2 = uVar2 | 0x30000000;
      *param_2 = uVar2;
    }
    uVar1 = 0xc000000;
    if (*(int *)(param_3 + 0x14) < 0xd) {
      uVar1 = *(int *)(param_3 + 0x14) << 0x18;
    }
    *param_2 = uVar1 & 0xf000000 | uVar2;
    *(undefined1 *)(param_1 + 0x143) = 0;
  }
  if (*(int *)(param_1 + 0x150) == 0) {
    if (param_3 == 0) {
      **(uint **)(param_1 + 0x14) = **(uint **)(param_1 + 0x14) | 2;
      ((unsigned char *)0x00002b7c)[param_1] = 1;
    }
    else {
      **(uint **)(param_1 + 0x14) = **(uint **)(param_1 + 0x14) & 0xfffffffd;
      ((unsigned char *)0x00002b7c)[param_1] = 0;
    }
  }
  FUN_000a7a60();
  return;
}

/* FUN_00017260 @ 0x17260 (168 bytes) */
int FUN_00017260(param_1)
  int param_1;
{
  int iVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  piVar3 = *(int **)(param_1 + 0x150);
  if (piVar3 == (int *)0x0) {
    uVar2 = FUN_0002f410(*(undefined4 *)(param_1 + 0x154));
    ((unsigned char *)0x00002b7f)[param_1] = uVar2;
  }
  else {
    iVar5 = 4;
    ((unsigned char *)0x00002b7f)[param_1] = 0x2f;
    iVar4 = *piVar3;
    do {
      if ((*(ushort *)(iVar4 + 0x90) != 0) &&
         (iVar1 = *(int *)((*(ushort *)(iVar4 + 0x90) - 0x8ce0) * 4 + piVar3[1]), iVar1 != 0)) {
        ((unsigned char *)0x00002b7f)[param_1] = *(undefined1 *)(iVar1 + 0x38);
        break;
      }
      iVar4 = iVar4 + 2;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  FUN_000a7a60(param_1);
  return;
}

/* FUN_00017310 @ 0x17310 (1008 bytes) */
int FUN_00017310(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint *puVar7;
  undefined4 local_28;
  int local_24;
  uint local_20;
  
  puVar2 = ((unsigned char *)0x0000271e);
  if (param_3 != (undefined4 *)0x0) {
    if (param_2 == 0x132) {
      puVar5 = *(undefined4 **)(param_1 + 0x1dc);
      if (*(undefined4 **)(param_1 + 0x1e0) <= puVar5 + 4) {
        ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
        puVar5 = *(undefined4 **)(param_1 + 0x1dc);
      }
      puVar7 = *(uint **)(param_1 + 0x1d8);
      *(undefined4 **)(param_1 + 0x1dc) = puVar5 + 4;
      *puVar7 = (int)puVar5 - (int)puVar7 >> 2 | *puVar7;
      *(undefined4 **)(param_1 + 0x1d8) = puVar5;
      *puVar5 = 0x3d000000;
      puVar5[1] = 0x132;
      puVar5[2] = *param_3;
      puVar5[3] = 0;
      puVar2 = (undefined *)0x0;
    }
    else {
      if (param_2 < 0x133) {
        if (param_2 == 300) {
          puVar5 = *(undefined4 **)(param_1 + 0x1dc);
          if (*(undefined4 **)(param_1 + 0x1e0) <= puVar5 + 6) {
            ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
            puVar5 = *(undefined4 **)(param_1 + 0x1dc);
          }
          *(undefined4 **)(param_1 + 0x1dc) = puVar5 + 6;
          *puVar5 = ((unsigned char *)0x00001040);
          puVar5[1] = 0;
          puVar5[2] = ((unsigned char *)0x00001393);
          puVar5[3] = 10;
          puVar5[4] = 0x5c8;
          puVar5[5] = 0x20000;
          return (undefined *)0x0;
        }
      }
      else {
        if (param_2 == 0x1fe) {
          if ((*(int *)(param_1 + 0xf8) != 0) && (*(int *)(param_1 + 0x2a84) == 0)) {
            puVar2 = (undefined *)((int (*)())FUN_00019db0)(param_1,*param_3,1);
            return puVar2;
          }
          return (undefined *)0x0;
        }
        if (param_2 == 0x29b) {
          if (*(uint *)(param_1 + 0x1e0) <= *(int *)(param_1 + 0x1dc) + 0x60U) {
            ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
          }
          iVar6 = *(int *)(param_1 + 500);
          uVar4 = *(uint *)(param_1 + 0x1f8);
          if (uVar4 <= iVar6 + 0x800U) {
            local_28 = 2;
            uVar4 = *(int *)(param_1 + 0x204) + 1;
            *(uint *)(param_1 + 0x204) = uVar4;
            if (2 < uVar4) {
              if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
                ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
                iVar6 = *(int *)(param_1 + 500);
              }
              *(undefined4 *)(param_1 + 0x204) = 1;
            }
            *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar6 - *(int *)(param_1 + 0x1fc) >> 2;
            _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 4),0x12,0,0,&local_24,&local_28);
            uVar3 = *(uint *)(((unsigned char *)0x000026c8) + param_1);
            *(int *)(param_1 + 0x1fc) = local_24;
            uVar4 = local_24 + (local_20 & 0xfffffffc);
            *(int *)(param_1 + 500) = local_24;
            *(uint *)(param_1 + 0x1f8) = uVar4;
            uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
            *(uint *)(((unsigned char *)0x000026c8) + param_1) = uVar3 | 1;
            *(undefined4 *)(param_1 + 0x200) = uVar1;
            iVar6 = local_24;
          }
          if (uVar4 <= iVar6 + 800U) {
            local_28 = 2;
            uVar4 = *(int *)(param_1 + 0x204) + 1;
            *(uint *)(param_1 + 0x204) = uVar4;
            if (2 < uVar4) {
              if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
                ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
                iVar6 = *(int *)(param_1 + 500);
              }
              *(undefined4 *)(param_1 + 0x204) = 1;
            }
            *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar6 - *(int *)(param_1 + 0x1fc) >> 2;
            _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 4),0x12,0,0,&local_24,&local_28);
            uVar4 = *(uint *)(((unsigned char *)0x000026c8) + param_1);
            *(int *)(param_1 + 0x1fc) = local_24;
            *(int *)(param_1 + 500) = local_24;
            *(uint *)(param_1 + 0x1f8) = local_24 + (local_20 & 0xfffffffc);
            uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
            *(uint *)(((unsigned char *)0x000026c8) + param_1) = uVar4 | 1;
            *(undefined4 *)(param_1 + 0x200) = uVar1;
            iVar6 = local_24;
          }
          iVar6 = iVar6 + 800;
          *(int *)(param_1 + 500) = iVar6;
          local_28 = 2;
          uVar4 = *(int *)(param_1 + 0x204) + 1;
          *(uint *)(param_1 + 0x204) = uVar4;
          if (2 < uVar4) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
              iVar6 = *(int *)(param_1 + 500);
            }
            *(undefined4 *)(param_1 + 0x204) = 1;
          }
          *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar6 - *(int *)(param_1 + 0x1fc) >> 2;
          _io_connect_method_scalarI_scalarO
                    (*(undefined4 *)(param_1 + 4),0x12,0,0,&local_24,&local_28);
          uVar4 = *(uint *)(((unsigned char *)0x000026c8) + param_1);
          *(int *)(param_1 + 0x1fc) = local_24;
          *(int *)(param_1 + 500) = local_24;
          *(uint *)(param_1 + 0x1f8) = local_24 + (local_20 & 0xfffffffc);
          uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
          *(uint *)(((unsigned char *)0x000026c8) + param_1) = uVar4 | 1;
          *(undefined4 *)(param_1 + 0x200) = uVar1;
          return (undefined *)0x0;
        }
      }
      puVar2 = ((unsigned char *)0x0000271a);
    }
  }
  return puVar2;
}

/* FUN_00017720 @ 0x17720 (36 bytes) */
int FUN_00017720()
{
  uint uVar1;
  
  uVar1 = FUN_00039100();
  return uVar1 | 0x1900;
}

/* FUN_00017750 @ 0x17750 (748 bytes) */
int FUN_00017750(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  int param_3;
{
  short sVar1;
  undefined4 uVar2;
  short local_58;
  short local_56;
  short local_54;
  short local_52;
  short local_50;
  
  param_2[0x29] = 0x80;
  *param_2 = 10;
  *(undefined1 *)((int)param_2 + 0x7b) = 1;
  *(undefined1 *)(param_2 + 0x1e) = 1;
  *(undefined1 *)((int)param_2 + 0x79) = 1;
  *(undefined1 *)((int)param_2 + 0x7a) = 1;
  param_2[3] = 0x1000;
  param_2[4] = 0x1000;
  param_2[5] = 4;
  param_2[6] = 4;
  param_2[7] = 0x20;
  param_2[8] = 0x20;
  param_2[0x1b] = 0x3f800000;
  param_2[0x1c] = 0x42800000;
  param_2[0x1d] = 0x3e000000;
  param_2[1] = 0x3f800000;
  param_2[2] = 3;
  param_2[0x28] = 0x80;
  param_2[0x2a] = 0x20;
  param_2[0x18] = 0x3f800000;
  param_2[0x19] = 0x42800000;
  param_2[0x1a] = 0x3e000000;
  *(byte *)(param_2 + 9) = (byte)(-(*(uint *)(param_3 + 0x10) & 0x3ffffffc) >> 0x1f);
  *(byte *)((int)param_2 + 0x25) = (byte)(*(uint *)(param_3 + 0xc) >> 3) & 1;
  *(byte *)((int)param_2 + 0x26) = (byte)(*(uint *)(param_3 + 0xc) >> 1) & 1;
  *(byte *)((int)param_2 + 0x27) = (byte)(-(*(uint *)(param_3 + 0x10) & 0x3f000000) >> 0x1f);
  FUN_0000a180(*(undefined4 *)(param_3 + 0x10),&local_58);
  param_2[10] = (int)local_50;
  param_2[0xb] = (int)local_58;
  param_2[0xc] = (int)local_56;
  param_2[0xd] = (int)local_54;
  param_2[0xe] = (int)local_52;
  FUN_0000a180(*(undefined4 *)(param_3 + 0x14),&local_58);
  param_2[0x11] = (int)local_58;
  param_2[0x12] = (int)local_56;
  param_2[0x13] = (int)local_54;
  param_2[0x14] = (int)local_52;
  uVar2 = FUN_0000a0f0(*(undefined4 *)(param_3 + 0x18));
  param_2[0xf] = uVar2;
  uVar2 = FUN_0000a0f0(*(undefined4 *)(param_3 + 0x1c));
  param_2[0x10] = uVar2;
  param_2[0x15] = (int)*(short *)(param_3 + 0x22);
  param_2[0x16] = (int)*(short *)(param_3 + 0x24);
  sVar1 = *(short *)(param_3 + 0x26);
  *(undefined2 *)((int)param_2 + 0x7e) = 2;
  *(undefined2 *)((int)param_2 + 0x82) = 6;
  *(undefined2 *)(param_2 + 0x1f) = 3;
  param_2[0x22] = 0x800;
  param_2[0x25] = param_2[0x25] | 4;
  param_2[0x23] = 0xffff;
  *(undefined2 *)((int)param_2 + 0xba) = 8;
  param_2[0x2c] = 0x41800000;
  param_2[0x17] = (int)sVar1;
  *(undefined2 *)((int)param_2 + 0xc2) = 0x1000;
  *(undefined2 *)(param_2 + 0x20) = 1;
  *(undefined2 *)(param_2 + 0x21) = 5;
  *(undefined2 *)((int)param_2 + 0x86) = 4;
  param_2[0x47] = 0;
  param_2[0x48] = 0;
  param_2[0x26] = 0;
  param_2[0x24] = 4;
  *(undefined2 *)(param_2 + 0x2d) = 8;
  *(undefined2 *)(param_2 + 0x2e) = 0;
  param_2[0x2b] = 0x41800000;
  *(undefined2 *)(param_2 + 0x2f) = 0x1000;
  *(undefined2 *)((int)param_2 + 0xbe) = 0x200;
  param_2[0x3a] = 0x1000;
  *(undefined2 *)(param_2 + 0x30) = 0x1000;
  *(undefined1 *)((int)param_2 + 199) = 1;
  *(undefined2 *)((int)param_2 + 0xb6) = 0x10;
  param_2[0x32] = 0x83f0;
  *(undefined1 *)((int)param_2 + 0xc6) = 5;
  *(undefined2 *)(param_2 + 0x3c) = 0x100;
  *(undefined2 *)((int)param_2 + 0xf2) = 0x20;
  *(undefined2 *)(param_2 + 0x46) = 1;
  *(undefined2 *)((int)param_2 + 0x102) = 0x40;
  *(undefined2 *)((int)param_2 + 0x10e) = 0x200;
  *(undefined2 *)((int)param_2 + 0xfe) = 10;
  *(undefined2 *)(param_2 + 0x44) = 4;
  *(undefined2 *)((int)param_2 + 0x116) = 0;
  *(undefined2 *)(param_2 + 0x3b) = 0x100;
  *(undefined2 *)(param_2 + 0x3d) = 0;
  *(undefined2 *)((int)param_2 + 0xf6) = 0;
  *(undefined2 *)(param_2 + 0x40) = 0x40;
  *(undefined2 *)(param_2 + 0x43) = 0x200;
  *(undefined2 *)(param_2 + 0x41) = 0;
  *(undefined2 *)((int)param_2 + 0x106) = 0;
  *(undefined2 *)((int)param_2 + 0x112) = 0;
  *(undefined2 *)(param_2 + 0x45) = 0;
  param_2[0x33] = 0x83f1;
  param_2[0x34] = 0x83f2;
  param_2[0x35] = 0x83f3;
  param_2[0x36] = 0x8837;
  param_2[0x3e] = 0;
  param_2[0x42] = 0;
  param_2[0x49] = param_2[0x49] | 0xffb7ffff;
  param_2[0x4b] = param_2[0x4b] | 0x74fc;
  *(undefined2 *)((int)param_2 + 0xee) = 0x12;
  param_2[0x4a] = param_2[0x4a] | 0x447f9e7;
  *(undefined2 *)(param_2 + 0x3f) = 0x400;
  return;
}

/* FUN_00017a40 @ 0x17a40 (200 bytes) */
int FUN_00017a40(param_1, param_2)
  uint *param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_2 + 0x18);
  uVar2 = *param_1;
  if (iVar1 != 1) {
    if (iVar1 == 0x400) {
      uVar2 = uVar2 | 0x10000;
    }
    else if (iVar1 == 0x800) {
      uVar2 = uVar2 | 0x30000;
    }
    else {
      uVar2 = uVar2 | 0x20000;
    }
  }
  if ((*(uint *)(param_2 + 8) & 8) != 0) {
    uVar2 = uVar2 | 0x80000000;
  }
  if (*(short *)(param_2 + 0x24) != 0) {
    if (((uVar2 & 0xf) == 4) && (*(int *)(param_2 + 0x28) != 1)) {
      if (*(short *)(param_2 + 0x26) == 6) {
        uVar2 = uVar2 | 0x400000;
      }
      else if (*(short *)(param_2 + 0x26) == 4) {
        uVar2 = uVar2 | 0x200000;
      }
      else {
        uVar2 = uVar2 | 0x100000;
      }
    }
    else if ((*(short *)(param_2 + 0x26) == 4) || (*(short *)(param_2 + 0x26) == 6)) {
      uVar2 = uVar2 | 0x80000;
    }
    else {
      uVar2 = uVar2 | 0x40000;
    }
  }
  *param_1 = uVar2;
  return;
}

/* FUN_00017b20 @ 0x17b20 (740 bytes) */
int FUN_00017b20(param_1)
  int param_1;
{
  int iVar1;
  pid_t pVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  
  iVar1 = _CFNotificationCenterGetDistributedCenter();
  pVar2 = _getpid();
  *(pid_t *)(param_1 + 0x2a60) = pVar2;
  if (iVar1 == 0) {
    return;
  }
  iVar3 = _CFStringCreateWithCString(0,"ATI Displays",0x600);
  iVar4 = _CFStringCreateWithCString(0,"com.ati.ati_displays",0x600);
  iVar5 = _CFStringCreateWithCString(0,"pid",0x600);
  iVar6 = _CFStringCreateWithCString(0,"gldisplaymask",0x600);
  iVar7 = _CFStringCreateWithCString(0,"ATI GL Driver",0x600);
  iVar8 = _CFStringCreateWithCString(0,"com.ati.ati_gl_driver",0x600);
  if (iVar3 == 0) goto LAB_00017d90;
  if ((((iVar4 != 0) && (iVar5 != 0)) && (iVar6 != 0)) && ((iVar7 != 0 && (iVar8 != 0)))) {
    _CFNotificationCenterAddObserver(iVar1,param_1,PTR_DAT_001e88c4,iVar3,iVar4,2);
    local_48 = iVar5;
    local_40 = _CFNumberCreate(0,3,param_1 + 0x2a60);
    local_44 = iVar6;
    local_3c = _CFNumberCreate(0,3,param_1 + 0x2a64);
    if (local_40 != 0) {
      if (local_3c != 0) {
        iVar9 = _CFDictionaryCreate(*(undefined4 *)PTR_001e88c0,&local_48,&local_40,2,PTR_001e88b8,
                                    PTR_001e88bc);
        if (iVar9 != 0) {
          _CFNotificationCenterPostNotification(iVar1,iVar7,iVar8,iVar9,1);
          _CFRelease(iVar9);
        }
        if (local_40 == 0) goto LAB_00017cfc;
      }
      _CFRelease();
    }
LAB_00017cfc:
    if (local_3c != 0) {
      _CFRelease();
    }
  }
  _CFRelease(iVar3);
LAB_00017d90:
  if (iVar4 != 0) {
    _CFRelease(iVar4);
  }
  if (iVar5 != 0) {
    _CFRelease(iVar5);
  }
  if (iVar6 != 0) {
    _CFRelease(iVar6);
  }
  if (iVar7 != 0) {
    _CFRelease(iVar7);
  }
  if (iVar8 != 0) {
    _CFRelease(iVar8);
  }
  return;
}

/* FUN_00017e10 @ 0x17e10 (204 bytes) */
int FUN_00017e10(param_1)
  undefined4 param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _CFNotificationCenterGetDistributedCenter();
  if (iVar1 != 0) {
    iVar2 = _CFStringCreateWithCString(0,"ATI Displays",0x600);
    iVar3 = _CFStringCreateWithCString(0,"com.ati.ati_displays",0x600);
    if (iVar2 != 0) {
      if (iVar3 != 0) {
        _CFNotificationCenterRemoveObserver(iVar1,param_1,iVar2,iVar3);
      }
      _CFRelease(iVar2);
    }
    if (iVar3 != 0) {
      _CFRelease(iVar3);
      return;
    }
  }
  return;
}

/* FUN_00018a40 @ 0x18a40 (3636 bytes) */
int FUN_00018a40(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  float *param_2;
  uint param_3;
  uint param_4;
  int param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
{
  bool bVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  double dVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  size_t sVar12;
  void *pvVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double dVar29;
  float *pfStack0000001c;
  byte in_stack_0000003b;
  undefined1 auStack_428 [4];
  int local_424;
  int local_420;
  int local_41c;
  undefined1 auStack_418 [4];
  undefined1 auStack_414 [4];
  void *local_410;
  int local_40c;
  undefined4 local_408;
  undefined4 local_404;
  undefined4 local_400;
  uint local_3fc;
  undefined4 local_3f8;
  uint local_3f4;
  uint local_3f0;
  float local_3ec;
  float local_3e8;
  uint local_3e4;
  uint local_3e0;
  uint local_3dc;
  undefined4 local_3d8;
  uint local_3d4;
  uint local_3d0;
  uint local_3cc;
  undefined4 local_3c8;
  uint local_3c4;
  uint local_3c0;
  uint local_3bc;
  undefined4 local_3b8;
  undefined1 local_3b4;
  float local_3b0;
  float local_3ac;
  uint local_144;
  longlong local_138;
  longlong local_130;
  longlong local_128;
  longlong local_120;
  longlong local_118;
  longlong local_110;
  longlong local_108;
  longlong local_100;
  longlong local_f8;
  longlong local_f0;
  longlong local_e8;
  longlong local_e0;
  undefined4 local_d8;
  uint uStack_d4;
  longlong local_d0;
  longlong local_c8;
  undefined4 local_c0;
  uint uStack_bc;
  longlong local_b8[0];
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  undefined4 local_90;
  uint uStack_8c;
  longlong local_88[0];
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  uint uStack_74;
  undefined4 local_70;
  uint uStack_6c;
  int local_68;
  uint local_64;
  
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  iVar25 = *(int *)(param_1 + 0x10);
  local_64 = (uint)in_stack_0000003b;
  if ((((unsigned char *)0x00002d84)[iVar25] == '\0') ||
     (((((*(int *)(((unsigned char *)0x00002d68) + iVar25) == 0x10000 &&
         (*(int *)(((unsigned char *)0x00002d6c) + iVar25) == 0x10000)) &&
        (*(short *)(((unsigned char *)0x00002d80) + iVar25) != -0x7ff5)) &&
       (((*(short *)(((unsigned char *)0x00002d80) + iVar25) != -0x7ff9 &&
         (*(short *)(((unsigned char *)0x00002d82) + iVar25) != -0x7ff5)) &&
        (*(short *)(((unsigned char *)0x00002d82) + iVar25) != -0x7ff9)))) || (((unsigned char *)0x00002e33)[iVar25] != '\0')))) {
    uVar15 = *(uint *)(((unsigned char *)0x000026b0) + param_1) & 0xfffffffd;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  else {
    uVar15 = *(uint *)(((unsigned char *)0x000026b0) + param_1) | 2;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  if (((unsigned char *)0x00002d66)[iVar25] == '\0') {
    uVar15 = uVar15 & 0xfffffffe;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  else {
    uVar15 = uVar15 | 1;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  if ((*(uint *)(((unsigned char *)0x000030b4) + iVar25) & 0xcff1) == 0) {
    uVar15 = uVar15 & 0xfffff7ff;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  else {
    uVar15 = uVar15 | 0x800;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  if ((((unsigned char *)0x00002ddc)[iVar25] == '\0') || ((*(uint *)(param_1 + 0x154) & 0xf) != 3)) {
    uVar15 = uVar15 & 0xffffffdf;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  else {
    uVar15 = uVar15 | 0x20;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  if ((((*(uint *)(((unsigned char *)0x000031c0) + iVar25) & 1) == 0) || ((*(uint *)(param_1 + 0x154) & 0x80) == 0))
     || ((*(short *)(((unsigned char *)0x000031a0) + iVar25) == 0x207 &&
         (*(int *)(((unsigned char *)0x000031a4) + iVar25) == 0x1e001e00)))) {
    uVar15 = uVar15 & 0xfffeffff;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  else {
    uVar15 = uVar15 | 0x10000;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  if ((((unsigned char *)0x00002dc8)[iVar25] == '\0') || ((*(uint *)(param_1 + 0x154) & 0x40) == 0)) {
    uVar15 = uVar15 & 0xffffffef;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  else {
    uVar15 = uVar15 | 0x10;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  if (((unsigned char *)0x00002e0a)[iVar25] == '\0') {
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15 & 0xffffffbf;
  }
  else {
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15 | 0x40;
  }
  pfStack0000001c = param_2;
  if (((((((*(int *)(param_1 + 0x18c) == 0) || (iVar9 = FUN_000a4760(param_1), iVar9 == 0)) &&
         ((*(int *)(param_1 + 400) == 0 || (iVar9 = FUN_000a4760(param_1), iVar9 == 1)))) &&
        ((*(int *)(param_1 + 0x194) == 0 || (iVar9 = FUN_000a4760(param_1), iVar9 == 2)))) &&
       ((*(int *)(param_1 + 0x198) == 0 || (iVar9 = FUN_000a4760(param_1), iVar9 == 3)))) &&
      (((*(int *)(param_1 + 0x19c) == 0 || (iVar9 = FUN_000a4760(param_1), iVar9 == 4)) &&
       ((*(int *)(param_1 + 0x1a0) == 0 || (iVar9 = FUN_000a4760(param_1), iVar9 == 5)))))) &&
     (((*(int *)(param_1 + 0x1a4) == 0 || (iVar9 = FUN_000a4760(param_1), iVar9 == 6)) &&
      ((*(int *)(param_1 + 0x1a8) == 0 || (iVar9 = FUN_000a4760(param_1), iVar9 == 7)))))) {
    uVar15 = *(uint *)(((unsigned char *)0x000026b0) + param_1) & 0xfffdffff;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  else {
    uVar15 = *(uint *)(((unsigned char *)0x000026b0) + param_1) | 0x20000;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  if (((unsigned char *)0x00002e33)[iVar25] == '\0') {
    uVar15 = uVar15 & 0xfffffdff;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  else {
    uVar15 = uVar15 | 0x200;
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15;
  }
  if ((((((unsigned char *)0x00002e43)[iVar25] == '\0') || (((unsigned char *)0x00002e40)[iVar25] == '\0')) ||
      (((unsigned char *)0x00002e41)[iVar25] == '\0')) || (((unsigned char *)0x00002e42)[iVar25] == '\0')) {
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15 | 0x400;
  }
  else {
    *(uint *)(((unsigned char *)0x000026b0) + param_1) = uVar15 & 0xfffffbff;
  }
  if (param_3 == 0) {
    return;
  }
  if (param_4 == 0) {
    return;
  }
  iVar25 = *(int *)(param_1 + 0x10);
  if (((unsigned char *)0x00003190)[iVar25] != '\0') {
    if (*(int *)(((unsigned char *)0x00003188) + iVar25) == 0) {
      return;
    }
    if (*(int *)(((unsigned char *)0x0000318c) + iVar25) == 0) {
      return;
    }
    if (*(int *)(param_1 + 0x15c) <= *(int *)(((unsigned char *)0x00003180) + iVar25)) {
      return;
    }
    if (*(int *)(((unsigned char *)0x00003188) + iVar25) + *(int *)(((unsigned char *)0x00003180) + iVar25) < 1) {
      return;
    }
    if (*(int *)(param_1 + 0x160) <= *(int *)(((unsigned char *)0x00003184) + iVar25)) {
      return;
    }
    if (*(int *)(((unsigned char *)0x0000318c) + iVar25) + *(int *)(((unsigned char *)0x00003184) + iVar25) < 1) {
      return;
    }
  }
  bVar1 = local_64 != 0;
  if (((!bVar1) && ((*(uint *)(((unsigned char *)0x000026b0) + param_1) & 0x30e73) == 0)) &&
     ((1 < param_5 - 0x1901U &&
      (((*(uint *)(((unsigned char *)0x000030b0) + iVar25) & 0x1ff) == 0 &&
       ((*(uint *)(((unsigned char *)0x000030b4) + iVar25) & 0xff0000) == 0)))))) {
    ((int (*)())FUN_0001a010)(param_1,*(undefined4 *)(((unsigned char *)0x000026a0) + param_1));
  }
  local_3e8 = 0.0;
  local_3fc = 0;
  local_3f8 = 0x7ffff;
  local_3ec = 0.0;
  if ((param_8 == 0) &&
     (local_3fc = (uint)(((unsigned char *)0x00002e84)[*(int *)(param_1 + 0x10)] != '\0'),
     ((unsigned char *)0x00002e85)[*(int *)(param_1 + 0x10)] != '\0')) {
    local_3fc = local_3fc | 4;
  }
  bVar2 = param_5 != 0x1901;
  FUN_0000a6e0(param_1,param_5,param_6,param_3,param_4,&local_41c,auStack_428,&local_424);
  FUN_0000a3f0(param_5,param_6);
  _glgConvertType(param_5,param_6,auStack_418,auStack_414);
  dVar7 = DOUBLE_001aa1e0;
  if (bVar2) {
    if (param_5 == 0x1902) {
      local_408 = 0xd;
      local_404 = 7;
    }
    else {
      local_408 = 6;
      local_404 = 0x11;
    }
  }
  else {
    local_408 = 0xe;
    local_404 = 0;
  }
  local_3ec = *pfStack0000001c;
  local_400 = 2;
  fVar4 = local_3ec * *(float *)(param_1 + 0x2a54);
  fVar5 = fVar4 + FLOAT_001aa10c;
  dVar27 = (double)fVar5;
  if ((double)FLOAT_001aa0d4 <= dVar27) {
    iVar25 = (int)fVar5;
    local_130 = (longlong)iVar25;
  }
  else {
    iVar25 = (int)(dVar27 - (double)FLOAT_001aa118);
    local_138 = (longlong)iVar25;
  }
  if (((unsigned char *)0x00002b7c)[param_1] == '\0') {
    fVar3 = *(float *)(param_1 + 0x2a58);
    local_3e8 = pfStack0000001c[1];
    fVar6 = local_3e8 * fVar3 + FLOAT_001aa10c;
    if (FLOAT_001aa0d4 <= fVar6) {
      uVar15 = (uint)fVar6;
      local_110 = (longlong)(int)uVar15;
    }
    else {
      uVar15 = (uint)(fVar6 - FLOAT_001aa118);
      local_118 = (longlong)(int)uVar15;
    }
  }
  else {
    fVar3 = *(float *)(param_1 + 0x2a58);
    local_3e8 = pfStack0000001c[1];
    fVar6 = local_3e8 * fVar3 - FLOAT_001aa10c;
    if (FLOAT_001aa0d4 <= fVar6) {
      uVar15 = (uint)fVar6;
      local_120 = (longlong)(int)uVar15;
    }
    else {
      uVar15 = (uint)(fVar6 + FLOAT_001aa118);
      local_128 = (longlong)(int)uVar15;
    }
  }
  dVar29 = (double)(fVar3 * *(float *)(((unsigned char *)0x00002e4c) + *(int *)(param_1 + 0x10)));
  dVar26 = (double)(*(float *)(param_1 + 0x2a54) *
                   *(float *)(((unsigned char *)0x00002e48) + *(int *)(param_1 + 0x10)));
  if (bVar2) {
    iVar9 = 4;
  }
  else {
    iVar9 = 1;
  }
  if ((dVar26 == (double)FLOAT_001aa0e8) && (dVar29 == (double)FLOAT_001aa0e8)) {
    iVar22 = iVar9 * param_3;
    local_3e8 = 0.0;
    local_3ec = 0.0;
    sVar12 = param_4 * iVar22;
    iVar20 = 1;
    local_68 = 1;
    uVar10 = param_3;
    uVar11 = param_4;
    goto LAB_000194f4;
  }
  fVar3 = fVar3 * local_3e8;
  dVar28 = (double)FLOAT_001aa0d4;
  if (dVar26 < dVar28) {
    dVar26 = -dVar26;
    fVar4 = fVar4 - FLOAT_001aa10c;
    dVar27 = (double)fVar4;
    if (dVar28 <= dVar27) {
      iVar25 = (int)fVar4;
      local_f0 = (longlong)iVar25;
      iVar20 = -1;
    }
    else {
      iVar20 = -1;
      iVar25 = (int)(dVar27 + (double)FLOAT_001aa118);
      local_f8 = (longlong)iVar25;
    }
  }
  else if (dVar28 <= dVar27) {
    iVar25 = (int)fVar5;
    local_100 = (longlong)iVar25;
    iVar20 = 1;
  }
  else {
    iVar20 = 1;
    iVar25 = (int)(dVar27 + (double)FLOAT_001aa118);
    local_108 = (longlong)iVar25;
  }
  if (((unsigned char *)0x00002b7c)[param_1] == '\0') {
    dVar27 = (double)FLOAT_001aa0d4;
    if (dVar29 < dVar27) {
      dVar29 = -dVar29;
      dVar28 = (double)(fVar3 - FLOAT_001aa10c);
      if (dVar27 <= dVar28) {
        uVar15 = (uint)(fVar3 - FLOAT_001aa10c);
        local_a0 = (longlong)(int)uVar15;
        iVar20 = -1;
        local_68 = 1;
      }
      else {
        iVar20 = -1;
        local_68 = 1;
        uVar15 = (uint)(dVar28 + (double)FLOAT_001aa118);
        local_a8 = (longlong)(int)uVar15;
      }
    }
    else {
      dVar28 = (double)(fVar3 + FLOAT_001aa10c);
      if (dVar27 <= dVar28) {
        uVar15 = (uint)(fVar3 + FLOAT_001aa10c);
        local_b0 = (longlong)(int)uVar15;
        local_68 = 1;
      }
      else {
        local_68 = 1;
        uVar15 = (uint)(dVar28 + (double)FLOAT_001aa118);
        local_b8[0] = (longlong)(int)uVar15;
      }
    }
  }
  else {
    dVar27 = (double)FLOAT_001aa0d4;
    if (dVar29 < dVar27) {
      dVar29 = -dVar29;
      dVar28 = (double)(fVar3 + FLOAT_001aa10c);
      if (dVar27 <= dVar28) {
        uVar15 = (uint)(fVar3 + FLOAT_001aa10c);
        local_c8 = (longlong)(int)uVar15;
      }
      else {
        uVar15 = (uint)(dVar28 + (double)FLOAT_001aa118);
        local_d0 = (longlong)(int)uVar15;
      }
      uStack_bc = uVar15 ^ 0x80000000;
      local_c0 = 0x43300000;
      local_68 = -1;
      if ((float)(dVar28 - (double)(float)((double)CONCAT44(0x43300000,uStack_bc) - DOUBLE_001aa1e0)
                 ) == FLOAT_001aa0d4) goto LAB_0001931c;
    }
    else {
      dVar28 = (double)(fVar3 - FLOAT_001aa10c);
      if (dVar27 <= dVar28) {
        uVar15 = (uint)(fVar3 - FLOAT_001aa10c);
        local_e0 = (longlong)(int)uVar15;
      }
      else {
        uVar15 = (uint)(dVar28 + (double)FLOAT_001aa118);
        local_e8 = (longlong)(int)uVar15;
      }
      uStack_d4 = uVar15 ^ 0x80000000;
      local_d8 = 0x43300000;
      local_68 = 1;
      if ((float)((double)(float)((double)CONCAT44(0x43300000,uStack_d4) - DOUBLE_001aa1e0) - dVar28
                 ) + FLOAT_001aa0e8 == FLOAT_001aa0e8) {
LAB_0001931c:
        uVar15 = uVar15 - 1;
      }
    }
  }
  local_98 = (longlong)(int)local_3ec;
  local_88[0] = (longlong)(int)local_3e8;
  uStack_74 = param_3 ^ 0x80000000;
  local_90 = 0x43300000;
  local_78 = 0x43300000;
  local_80 = 0x43300000;
  uStack_8c = (int)local_3ec ^ 0x80000000;
  uStack_7c = (int)local_3e8 ^ 0x80000000;
  local_3ec = local_3ec - (float)((double)CONCAT44(0x43300000,uStack_8c) - DOUBLE_001aa1e0);
  local_3e8 = local_3e8 - (float)((double)CONCAT44(0x43300000,uStack_7c) - DOUBLE_001aa1e0);
  uVar10 = _glgPixelCenters((double)local_3ec,
                            (double)(float)(dVar26 * (double)(float)((double)CONCAT44(0x43300000,
                                                                                      uStack_74) -
                                                                    DOUBLE_001aa1e0) +
                                           (double)local_3ec),dVar26);
  uStack_6c = param_4 ^ 0x80000000;
  local_70 = 0x43300000;
  iVar22 = iVar9 * uVar10;
  uVar11 = _glgPixelCenters((double)local_3e8,
                            (double)(float)(dVar29 * (double)(float)((double)CONCAT44(0x43300000,
                                                                                      uStack_6c) -
                                                                    dVar7) + (double)local_3e8),
                            dVar29);
  sVar12 = uVar11 * iVar22;
LAB_000194f4:
  pvVar13 = _malloc(sVar12);
  if (pvVar13 != (void *)0x0) {
    local_3b4 = 1;
    local_3f0 = param_4;
    local_3f4 = param_3;
    local_420 = param_7 + local_424;
    local_410 = pvVar13;
    local_40c = iVar22;
    if (bVar1) {
      _glgProcessPixels(0,&local_420);
    }
    else {
      iVar14 = *(int *)(param_1 + 0x10);
      if (((((*(uint *)(((unsigned char *)0x000030b0) + iVar14) & 0x1ff) != 0) ||
           ((*(uint *)(((unsigned char *)0x000030b4) + iVar14) & 0xff0000) != 0)) && (bVar2)) && (param_5 != 0x1902)
         ) {
        if ((*(uint *)(((unsigned char *)0x000030b0) + iVar14) & 2) == 0) {
          if (((*(uint *)(((unsigned char *)0x000030b0) + iVar14) & 4) != 0) &&
             (*(short *)(((unsigned char *)0x00002fe8) + iVar14) == -0x7fea)) {
            uVar11 = (uVar11 - *(int *)(((unsigned char *)0x00002ff4) + iVar14)) + 1;
            uVar10 = (uVar10 - *(int *)(((unsigned char *)0x00002ff0) + iVar14)) + 1;
          }
        }
        else if (*(short *)(((unsigned char *)0x00002fa8) + iVar14) == -0x7fea) {
          uVar11 = (uVar11 - *(int *)(((unsigned char *)0x00002fb4) + iVar14)) + 1;
          uVar10 = (uVar10 - *(int *)(((unsigned char *)0x00002fb0) + iVar14)) + 1;
        }
        iVar18 = *(int *)(param_1 + 0x18);
        iVar16 = *(int *)(*(int *)(iVar18 + 0x140) + 0x30);
        local_3e4 = (uint)*(ushort *)(iVar16 + 0x98);
        local_3e0 = (uint)*(ushort *)(iVar16 + 0x9a);
        local_3dc = (uint)*(ushort *)(iVar16 + 0x8c);
        local_3d8 = *(undefined4 *)(iVar16 + 0x9c);
        iVar16 = *(int *)(*(int *)(iVar18 + 0x148) + 0x30);
        local_3d4 = (uint)*(ushort *)(iVar16 + 0x98);
        local_3d0 = (uint)*(ushort *)(iVar16 + 0x9a);
        local_3cc = (uint)*(ushort *)(iVar16 + 0x8c);
        local_3c8 = *(undefined4 *)(iVar16 + 0x9c);
        iVar16 = *(int *)(*(int *)(iVar18 + 0x144) + 0x30);
        local_3c4 = (uint)*(ushort *)(iVar16 + 0x98);
        local_3c0 = (uint)*(ushort *)(iVar16 + 0x9a);
        local_3bc = (uint)*(ushort *)(iVar16 + 0x8c);
        local_3b8 = *(undefined4 *)(iVar16 + 0x9c);
      }
      fVar4 = *(float *)(((unsigned char *)0x00002e48) + iVar14) * *(float *)(param_1 + 0x2a54);
      fVar5 = *(float *)(((unsigned char *)0x00002e4c) + iVar14) * *(float *)(param_1 + 0x2a58);
      _memcpy(&local_3b0,((unsigned char *)0x00002e48) + iVar14,0x274);
      uVar8 = 0x4000;
      if (fVar4 == FLOAT_001aa0e8) {
        uVar8 = 0;
      }
      local_144 = (uint)(fVar5 != FLOAT_001aa0e8) << 0xf | uVar8 | local_144 & 0xffff3fff;
      local_3b0 = fVar4;
      local_3ac = fVar5;
      _glgProcessPixels(&local_3b0,&local_420);
    }
    local_41c = iVar22;
    if (((unsigned char *)0x00002b7c)[param_1] != '\0') {
      local_41c = -iVar22;
    }
    uVar8 = uVar10;
    if (0x7fe < uVar10) {
      uVar8 = 0x7fe;
    }
    uVar23 = 0x7fe / uVar8;
    if (uVar11 < 0x7fe / uVar8) {
      uVar23 = uVar11;
    }
    uVar17 = uVar10 / uVar8;
    uVar19 = uVar11 / uVar23;
    uVar10 = uVar10 - uVar17 * uVar8;
    uVar11 = uVar11 - uVar19 * uVar23;
    uVar21 = uVar17 + 1;
    if (uVar10 == 0) {
      uVar10 = uVar8;
      uVar21 = uVar17;
    }
    uVar17 = uVar19 + 1;
    if (uVar11 == 0) {
      uVar11 = uVar23;
      uVar17 = uVar19;
    }
    if (uVar17 != 0) {
      uVar19 = 0;
      do {
        if (uVar21 != 0) {
          iVar14 = uVar23 * uVar19;
          uVar24 = 0;
          iVar22 = local_68 * iVar14;
          do {
            local_3f0 = uVar23;
            if (uVar19 == uVar17 - 1) {
              local_3f0 = uVar11;
            }
            local_3f4 = uVar10;
            if (uVar24 != uVar21 - 1) {
              local_3f4 = uVar8;
            }
            iVar16 = uVar24 * uVar8;
            if (((unsigned char *)0x00002b7c)[param_1] == '\0') {
              local_420 = iVar14 * local_41c + iVar9 * iVar16;
              iVar18 = iVar22;
            }
            else {
              iVar18 = iVar14 + local_3f0 + -1;
              local_420 = iVar9 * iVar16 - local_41c * iVar18;
              iVar18 = -(local_68 * iVar18);
            }
            local_420 = local_420 + (int)pvVar13;
            uVar24 = uVar24 + 1;
            FUN_00029c00(param_1,local_420,local_3f4,local_3f0,local_41c,iVar9,
                         iVar25 + iVar20 * iVar16,uVar15 + iVar18);
          } while (uVar21 != uVar24);
        }
        uVar19 = uVar19 + 1;
      } while (uVar17 != uVar19);
    }
    _free(pvVar13);
  }
  return;
}

/* FUN_000199a0 @ 0x199a0 (68 bytes) */
int FUN_000199a0()
{
  undefined4 uVar1;
  int in_stack_00000038;
  
  if (in_stack_00000038 == 0) {
    ((int (*)())FUN_00018a40)();
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_0002a3d0();
  }
  return uVar1;
}

/* FUN_000199f0 @ 0x199f0 (212 bytes) */
int FUN_000199f0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    iVar2 = ((int (*)())FUN_00016fc0)(*(undefined2 *)(((unsigned char *)0x00002dba) + *(int *)(param_1 + 0x10)),
                         *(undefined4 *)(param_1 + 0x154));
    uVar1 = *(uint *)(param_1 + 0x154);
    if (((((uVar1 & 0x20) == 0) && (((uVar1 & 0x10) != 0 || ((uVar1 & 0x400) == 0)))) ||
        ((iVar2 != 0 && ((iVar2 != 1 || ((uVar1 & 0x400) != 0)))))) ||
       (((uVar1 & 0x70000000) != 0 ||
        (((uVar3 = 6, param_2 < 6 && (uVar3 = 4, param_2 < 4)) && (uVar3 = 2, param_2 < 2)))))) {
      uVar3 = 1;
    }
    *(undefined4 *)(param_1 + 0x2a50) = uVar3;
    *(undefined1 *)(param_1 + 0x2a5d) = 1;
    *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x2a5c) = 1;
  }
  return;
}

/* FUN_00019ad0 @ 0x19ad0 (360 bytes) */
int FUN_00019ad0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return;
  }
  iVar2 = ((int (*)())FUN_00016fc0)(*(undefined2 *)(((unsigned char *)0x00002dba) + *(int *)(param_1 + 0x10)),
                       *(undefined4 *)(param_1 + 0x154));
  uVar1 = *(uint *)(param_1 + 0x154);
  if (((((uVar1 & 0x20) == 0) && (((uVar1 & 0x10) != 0 || ((uVar1 & 0x400) == 0)))) ||
      ((iVar2 != 0 && ((iVar2 != 1 || ((uVar1 & 0x400) != 0)))))) || ((uVar1 & 0x70000000) != 0)) {
LAB_00019b60:
    *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x2a5d) = 1;
    *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
    *(undefined1 *)(param_1 + 0x2a5c) = 1;
  }
  else {
    if (param_2 < 4) {
      if (param_2 < 2) goto LAB_00019b60;
      *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
      *(undefined1 *)(param_1 + 0x2a5c) = 1;
      if (0x1000 < *(int *)(param_1 + 0x160) << 1) {
        *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5d) = 1;
        goto LAB_00019be0;
      }
    }
    else {
      if (*(int *)(param_1 + 0x15c) << 1 < 0x1001) {
        *(undefined4 *)(param_1 + 0x2a54) = 0x40000000;
        *(undefined1 *)(param_1 + 0x2a5c) = 2;
      }
      else {
        *(undefined4 *)(param_1 + 0x2a54) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5c) = 1;
      }
      if (0x1000 < *(int *)(param_1 + 0x160) << 1) {
        *(undefined4 *)(param_1 + 0x2a58) = 0x3f800000;
        *(undefined1 *)(param_1 + 0x2a5d) = 1;
        goto LAB_00019be0;
      }
    }
    *(undefined4 *)(param_1 + 0x2a58) = 0x40000000;
    *(undefined1 *)(param_1 + 0x2a5d) = 2;
  }
LAB_00019be0:
  *(undefined4 *)(param_1 + 0x2a50) = 1;
  return;
}

/* FUN_00019c50 @ 0x19c50 (308 bytes) */
int FUN_00019c50(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  
  if (param_1 != 0) {
    iVar4 = *(int *)(param_1 + 0x2a50);
    fVar1 = *(float *)(param_1 + 0x2a54);
    fVar2 = *(float *)(param_1 + 0x2a58);
    uVar3 = *(uint *)(param_1 + 0x154) & 0x700000;
    if (uVar3 == 0) {
      uVar3 = *(uint *)(param_1 + 0x154) & 0xc0000;
      if (uVar3 == 0x40000) {
        ((int (*)())FUN_00019ad0)(param_1,2);
      }
      else if (uVar3 == 0x80000) {
        ((int (*)())FUN_00019ad0)(param_1,4);
      }
      else {
        ((int (*)())FUN_00019ad0)(param_1,1);
      }
    }
    else if (uVar3 == 0x200000) {
      ((int (*)())FUN_000199f0)(param_1,4);
    }
    else if (uVar3 == 0x400000) {
      ((int (*)())FUN_000199f0)(param_1,6);
    }
    else if (uVar3 == 0x100000) {
      ((int (*)())FUN_000199f0)(param_1,2);
    }
    else {
      ((int (*)())FUN_000199f0)(param_1,1);
    }
    *(undefined4 *)(param_1 + 0x2a48) = *(undefined4 *)(param_1 + 0x15c);
    *(undefined4 *)(param_1 + 0x2a4c) = *(undefined4 *)(param_1 + 0x160);
    if (((iVar4 != *(int *)(param_1 + 0x2a50)) || (fVar1 != *(float *)(param_1 + 0x2a54))) ||
       (fVar2 != *(float *)(param_1 + 0x2a58))) {
      *(undefined1 *)(param_1 + 0x2a43) = 1;
    }
  }
  return;
}

/* FUN_00019db0 @ 0x19db0 (544 bytes) */
int FUN_00019db0(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  if (param_1[0x3e] == 0) {
    return 0;
  }
  if (param_1[0x79] + 0x28U < (uint)param_1[0x77]) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
  }
  if ((param_1[0x55] & 0xfU) == 3) {
    bVar1 = true;
LAB_00019e50:
    ((int (*)())FUN_00019ad0)(param_1,param_2);
  }
  else {
    bVar1 = param_3 == 0;
    if (bVar1) goto LAB_00019e50;
    ((int (*)())FUN_000199f0)(param_1,param_2);
  }
  local_24 = param_1[0xf] & 0xff83efff;
  param_1[0xf] = local_24;
  if (bVar1) {
    if ((float)param_1[0xa95] <= FLOAT_001aa128) {
      if (FLOAT_001aa128 < (float)param_1[0xa96]) {
        local_24 = local_24 | 0x41000;
        param_1[0xf] = local_24;
        goto LAB_00019f40;
      }
    }
    else if (FLOAT_001aa128 < (float)param_1[0xa96]) {
      local_24 = local_24 | 0x81000;
      param_1[0xf] = local_24;
      goto LAB_00019f40;
    }
    param_1[0xf] = local_24;
  }
  else {
    iVar2 = param_1[0xa94];
    if (iVar2 == 6) {
      local_24 = local_24 | 0x401000;
      param_1[0xf] = local_24;
    }
    else if (iVar2 == 4) {
      local_24 = local_24 | 0x201000;
      param_1[0xf] = local_24;
    }
    else if (iVar2 == 2) {
      local_24 = local_24 | 0x101000;
      param_1[0xf] = local_24;
    }
  }
LAB_00019f40:
  if (param_1[0x54] == 0) {
    param_1[0x55] = local_24;
  }
  if ((local_24 & 0x20) == 0) {
    local_28 = ~(uint)*(byte *)(*(int *)(PTR_DAT_001e88ac + 0xc) + *param_1);
  }
  else {
    local_28 = *(uint *)(param_1[0x3e] + 8);
  }
  local_24 = local_24 & 0xffff3fc0;
  local_20 = param_1[0x3f];
  local_1c = param_1[0x40];
  _io_connect_method_scalarI_structureI(param_1[1],0,&local_28,4,0,0);
  ((int (*)())FUN_00019c50)(param_1);
  ((int (*)())FUN_00022eb0)(param_1,0);
  *(undefined1 *)(param_1 + 0xa91) = 1;
  return 0;
}

/* FUN_0001a010 @ 0x1a010 (176 bytes) */
int FUN_0001a010(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x154);
  if ((((uVar2 & 0x700000) == 0) &&
      (((uVar2 & 0xc0000) == 0 ||
       ((*(float *)(param_1 + 0x2a54) < FLOAT_001aa128 &&
        (*(float *)(param_1 + 0x2a58) < FLOAT_001aa128)))))) ||
     (bVar1 = true, (uVar2 & 0x70000000) != 0)) {
    bVar1 = false;
  }
  if (param_2 == 1) {
    if ((uVar2 & 0x400) != 0) {
      return 0;
    }
  }
  else if (param_2 == 0) {
    if ((uVar2 & 0x400) == 0) {
      return 0;
    }
  }
  else if (1 < param_2 - 4U) {
    return 0;
  }
  if (!bVar1) {
    return 0;
  }
  return 1;
}

/* FUN_0001a0d0 @ 0x1a0d0 (32 bytes) */
int FUN_0001a0d0(param_1, param_2)
  int param_1;
  int param_2;
{
  byte *pbVar1;
  
  pbVar1 = *(byte **)(param_1 + 0x238);
  if ((int)(param_2 -
           ((uint)pbVar1[3] << 0x18 | (uint)pbVar1[2] << 0x10 | (uint)pbVar1[1] << 8 | (uint)*pbVar1
           )) < 1) {
    return 1;
  }
  return 0;
}

/* FUN_0001a0f0 @ 0x1a0f0 (388 bytes) */
int FUN_0001a0f0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  
  puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  cVar1 = ((unsigned char *)0x00002b7e)[param_1];
  *puVar4 = ((unsigned char *)0x00001393);
  puVar4[1] = 0;
  puVar4[2] = 0x5c8;
  puVar4[3] = 0x20000;
  puVar4 = puVar4 + 4;
  if (cVar1 != '\0') {
    puVar4 = (undefined4 *)FUN_0002b7f0(param_1,puVar4);
  }
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *(int *)(*(int *)(param_1 + 0x1e4) + 0x10) =
       (*(int *)(param_1 + 0x1e0) - (int)puVar4 >> 2) +
       (*(int *)(param_1 + 0x1f0) - *(int *)(param_1 + 0x1ec) >> 2) + 0x25;
  puVar2 = PTR_001e88b4;
  *puVar5 = (int)puVar4 - (int)puVar5 >> 2 | *puVar5;
  *puVar4 = param_2;
  _IOConnectMapMemory(*(undefined4 *)(param_1 + 4),1,*(undefined4 *)puVar2,param_1 + 0x1e4,
                      param_1 + 0x1e8,1);
  iVar3 = *(int *)(param_1 + 0x1e4);
  puVar4 = (undefined4 *)(iVar3 + 0x20);
  *(undefined4 **)(param_1 + 0x1e0) = puVar4 + *(int *)(iVar3 + 0x10) + -0x25;
  *(undefined4 *)(iVar3 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x2838) = 0;
  *(undefined4 *)(param_1 + 0x204) = 1;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  *(undefined4 *)(param_1 + 0x2834) = 0;
  *(int *)(param_1 + 0x23c) = *(int *)(param_1 + 0x23c) + 1;
  if (cVar1 != '\0') {
    *puVar4 = ((unsigned char *)0x000013d6);
    *(undefined4 *)(iVar3 + 0x24) = 0;
    puVar4 = (undefined4 *)(iVar3 + 0x28);
  }
  *(int *)(param_1 + 0x1d8) = iVar3 + 0x1c;
  *(undefined4 **)(param_1 + 0x1dc) = puVar4;
  *(undefined4 **)(param_1 + 0x2994) = puVar4 + 0x6000;
  FUN_0002c6c0(param_1);
  return;
}

/* FUN_0001a280 @ 0x1a280 (588 bytes) */
int FUN_0001a280(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint local_28;
  uint local_24;
  
  iVar2 = ((int (*)())FUN_0001a010)(param_1,0);
  if (iVar2 != 0) {
    ((int (*)())FUN_000230d0)(param_1,0,0,1,0,0,*(undefined4 *)(param_1 + 0x15c),*(undefined4 *)(param_1 + 0x160)
                );
  }
  ((int (*)())FUN_0001a0f0)(param_1,0x2000000);
  if ((*(uint *)(*(int *)(param_1 + 0x1e4) + 0x14) & 2) != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0xf8);
    if (*(char *)(param_1 + 0x144) == '\0') {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*puVar4,puVar4[1],puVar4[2],0,0,-(uint)*(byte *)(param_1 + 0x142) >> 0x1f);
    }
    else {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*puVar4,puVar4[1],puVar4[2],param_1 + 0x124,*(undefined4 *)(param_1 + 0x108),
                 -(uint)*(byte *)(param_1 + 0x142) >> 0x1f);
    }
  }
  puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar4 + 5) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
    puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  }
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 5;
  *puVar5 = (int)puVar4 - (int)puVar5 >> 2 | *puVar5;
  *(undefined4 **)(param_1 + 0x1d8) = puVar4;
  *puVar4 = 0x28000000;
  if (*(char *)(param_1 + 0x2a68) != '\0') {
    cVar1 = *(char *)(param_1 + 0x2a6c);
    *(undefined1 *)(param_1 + 0x2a68) = 0;
    *(undefined4 *)(param_1 + 0x2a8c) = *(undefined4 *)(param_1 + 0x2a78);
    *(undefined4 *)(param_1 + 0x2a90) = *(undefined4 *)(param_1 + 0x2a7c);
    *(undefined1 *)(param_1 + 0x2a69) = 1;
    if (*(char *)(param_1 + 0x2a80) != cVar1) {
      *(char *)(param_1 + 0x2a80) = cVar1;
      if (cVar1 == '\x01') {
        local_24 = 0;
        local_28 = 0;
      }
      else if (cVar1 == '\x02') {
        local_24 = 1;
        local_28 = 1;
      }
      else {
        local_28 = (uint)*(byte *)(param_1 + 0x142);
        local_24 = (uint)*(byte *)(param_1 + 0x146);
      }
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_28,2,0,0);
    }
    iVar2 = *(int *)(param_1 + 0x2a70);
    if (*(int *)(param_1 + 0x2a84) == iVar2) {
      uVar3 = *(uint *)(param_1 + 0x2a74);
      if (*(uint *)(param_1 + 0x2a88) == uVar3) {
        return;
      }
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x2a74);
    }
    *(uint *)(param_1 + 0x2a88) = uVar3;
    *(int *)(param_1 + 0x2a84) = iVar2;
    ((int (*)())FUN_00019db0)(param_1,iVar2,uVar3 < 2);
  }
  return;
}

/* _gldFlush @ 0x1a5c0 (28 bytes) */
int _gldFlush(param_1)
  int param_1;
{
  if (*(uint *)(param_1 + 0x1dc) <= *(int *)(param_1 + 0x1e4) + 0x28U) {
    return;
  }
  ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
  return;
}

/* _gldFinish @ 0x1a5e0 (136 bytes) */
int _gldFinish(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
  }
  do {
    iVar1 = _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),8,0,0,0,0);
  } while (iVar1 == -0x1ffffd2a);
  return;
}

/* FUN_0001a9d0 @ 0x1a9d0 (588 bytes) */
int FUN_0001a9d0(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint local_28;
  uint local_24;
  
  iVar2 = ((int (*)())FUN_0001a010)(param_1,1);
  if (iVar2 != 0) {
    ((int (*)())FUN_000230d0)(param_1,0,1,0,0,0,*(undefined4 *)(param_1 + 0x15c),*(undefined4 *)(param_1 + 0x160)
                );
  }
  ((int (*)())FUN_0001a0f0)(param_1,0x3000000);
  if ((*(uint *)(*(int *)(param_1 + 0x1e4) + 0x14) & 2) != 0) {
    puVar4 = *(undefined4 **)(param_1 + 0xf8);
    if (*(char *)(param_1 + 0x144) == '\0') {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*puVar4,puVar4[1],puVar4[2],0,0,-(uint)*(byte *)(param_1 + 0x142) >> 0x1f);
    }
    else {
      (**(code **)(PTR_DAT_001e88ac + 0x10))
                (*puVar4,puVar4[1],puVar4[2],param_1 + 0x124,*(undefined4 *)(param_1 + 0x108),
                 -(uint)*(byte *)(param_1 + 0x142) >> 0x1f);
    }
  }
  puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar4 + 5) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
    puVar4 = *(undefined4 **)(param_1 + 0x1dc);
  }
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *(undefined4 **)(param_1 + 0x1dc) = puVar4 + 5;
  *puVar5 = (int)puVar4 - (int)puVar5 >> 2 | *puVar5;
  *(undefined4 **)(param_1 + 0x1d8) = puVar4;
  *puVar4 = 0x28000000;
  if (*(char *)(param_1 + 0x2a68) != '\0') {
    cVar1 = *(char *)(param_1 + 0x2a6c);
    *(undefined1 *)(param_1 + 0x2a68) = 0;
    *(undefined4 *)(param_1 + 0x2a8c) = *(undefined4 *)(param_1 + 0x2a78);
    *(undefined4 *)(param_1 + 0x2a90) = *(undefined4 *)(param_1 + 0x2a7c);
    *(undefined1 *)(param_1 + 0x2a69) = 1;
    if (*(char *)(param_1 + 0x2a80) != cVar1) {
      *(char *)(param_1 + 0x2a80) = cVar1;
      if (cVar1 == '\x01') {
        local_24 = 0;
        local_28 = 0;
      }
      else if (cVar1 == '\x02') {
        local_24 = 1;
        local_28 = 1;
      }
      else {
        local_28 = (uint)*(byte *)(param_1 + 0x142);
        local_24 = (uint)*(byte *)(param_1 + 0x146);
      }
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),2,&local_28,2,0,0);
    }
    iVar2 = *(int *)(param_1 + 0x2a70);
    if (*(int *)(param_1 + 0x2a84) == iVar2) {
      uVar3 = *(uint *)(param_1 + 0x2a74);
      if (*(uint *)(param_1 + 0x2a88) == uVar3) {
        return;
      }
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x2a74);
    }
    *(uint *)(param_1 + 0x2a88) = uVar3;
    *(int *)(param_1 + 0x2a84) = iVar2;
    ((int (*)())FUN_00019db0)(param_1,iVar2,uVar3 < 2);
  }
  return;
}

/* FUN_0001ac30 @ 0x1ac30 (464 bytes) */
int FUN_0001ac30(param_1)
  int param_1;
{
  bool bVar1;
  ushort uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_1 == 0) {
    return ((unsigned char *)0x0000271e);
  }
  uVar5 = *(uint *)(param_1 + 0x30);
  if ((uVar5 == 0) || ((uVar5 & ~*(uint *)PTR_DAT_001e88ac) != 0)) {
LAB_0001adf0:
    return ((unsigned char *)0x00002716);
  }
  uVar6 = *(uint *)(param_1 + 8);
  bVar1 = (uVar6 >> 1 & 1) != 0;
  if (bVar1) {
    for (; (uVar5 & 1) == 0; uVar5 = uVar5 >> 1) {
    }
    if (uVar5 != 1) goto LAB_0001adf0;
  }
  if ((((((*(uint *)(param_1 + 4) & 0xff00) == 0x1900) && (*(short *)(param_1 + 0x20) == 0)) &&
       (((*(uint *)(param_1 + 0xc) & 2) == 0 || (bVar1)))) && (*(ushort *)(param_1 + 0x22) < 3)) &&
     ((((uVar6 & 0x2000) == 0 || (*(int *)(param_1 + 0x24) == 0)) &&
      (uVar2 = *(ushort *)(param_1 + 0x24), uVar2 < 2)))) {
    if (uVar2 != 0) {
      if (((uVar2 == 1) && (sVar3 = *(short *)(param_1 + 0x26), sVar3 != 6)) &&
         ((sVar3 != 4 && (sVar3 != 2)))) goto LAB_0001ae00;
    }
    else if (*(short *)(param_1 + 0x26) != 0) goto LAB_0001ae00;
    if (((((uVar6 & 0xffffd064) == 0) &&
         (((uVar6 & 8) == 0 || ((*(uint *)(param_1 + 0xc) & 8) != 0)))) &&
        ((*(uint *)(param_1 + 0x10) & 0xf57f7bff) == 0)) &&
       (((*(uint *)(param_1 + 0x10) & 0xa800000) == 0 || ((uVar2 == 0 && ((uVar6 & 0x400) == 0))))))
    {
      iVar4 = *(int *)(param_1 + 0x1c);
      if (iVar4 != 1) {
        if (iVar4 != 0x80) goto LAB_0001ae00;
        uVar5 = 0xfffff7ff;
      }
      else {
        uVar5 = 0xffffe3fe;
      }
      if (((*(uint *)(param_1 + 0x18) & uVar5) == 0) &&
         ((((*(uint *)(param_1 + 0x18) != 1 || (iVar4 != 1)) || ((uVar6 & 0x800) == 0)) &&
          ((uVar5 = *(uint *)(param_1 + 0x14), (uVar5 & 0xff7f7fff) == 0 &&
           ((uVar5 & uVar5 - 1) == 0)))))) {
        return (undefined *)0x0;
      }
    }
  }
LAB_0001ae00:
  return ((unsigned char *)0x00002712);
}

/* FUN_0001ae20 @ 0x1ae20 (768 bytes) */
int FUN_0001ae20(param_1, param_2, param_3)
  void *param_1;
  int param_2;
  int param_3;
{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  
  if ((*(uint *)((int)param_1 + 0x1c) & 1) == 0) {
    *(uint *)((int)param_1 + 0x1c) = *(uint *)((int)param_1 + 0x1c) & 0x80;
    if (param_2 == 0) {
LAB_0001aee0:
      *(undefined4 *)((int)param_1 + 0x18) = 0x800;
    }
    else {
      *(uint *)((int)param_1 + 0x18) = *(uint *)((int)param_1 + 0x18) & 0x800;
    }
  }
  else {
    uVar3 = *(uint *)((int)param_1 + 0x18);
    *(undefined4 *)((int)param_1 + 0x1c) = 1;
    *(uint *)((int)param_1 + 0x18) = uVar3 & 0x1c01;
    if ((param_2 == 0) || ((uVar3 & 0x1c01) != 0)) {
      if (param_3 == 0) {
        if ((uVar3 & 1) != 0) goto LAB_0001ae88;
        if ((uVar3 & 0x400) == 0) {
          if ((uVar3 & 0x800) != 0) goto LAB_0001aee0;
          goto LAB_0001aeb0;
        }
        *(undefined4 *)((int)param_1 + 0x18) = 0x400;
      }
      else if ((uVar3 & 1) == 0) {
LAB_0001aeb0:
        *(undefined4 *)((int)param_1 + 0x18) = 0x1000;
      }
      else {
LAB_0001ae88:
        *(undefined4 *)((int)param_1 + 0x18) = 1;
      }
    }
  }
  uVar3 = *(uint *)((int)param_1 + 0x14);
  if ((int)uVar3 < 0) {
    *(undefined4 *)((int)param_1 + 0x14) = 0;
  }
  else if ((uVar3 & 0x8000) == 0) {
    if ((uVar3 & 0x800000) == 0) {
      *(undefined4 *)((int)param_1 + 0x14) = 0xffffffff;
    }
    else {
      *(undefined4 *)((int)param_1 + 0x14) = 0x800000;
    }
  }
  else {
    *(undefined4 *)((int)param_1 + 0x14) = 0x8000;
  }
  if ((*(uint *)((int)param_1 + 0xc) & 8) == 0) {
    uVar3 = *(uint *)((int)param_1 + 8) & 0xfffffff7;
    *(uint *)((int)param_1 + 8) = uVar3;
  }
  else {
    uVar3 = *(uint *)((int)param_1 + 8);
  }
  if ((uVar3 & 0x2000) != 0) {
    *(undefined2 *)((int)param_1 + 0x24) = 0;
    *(undefined2 *)((int)param_1 + 0x26) = 0;
  }
  uVar1 = 0;
  if (*(short *)((int)param_1 + 0x24) != 0) {
    if (*(short *)((int)param_1 + 0x24) != 1) {
      *(undefined2 *)((int)param_1 + 0x24) = 1;
    }
    if (4 < *(short *)((int)param_1 + 0x26)) {
      *(undefined2 *)((int)param_1 + 0x26) = 6;
      goto LAB_0001aff4;
    }
    if (2 < *(short *)((int)param_1 + 0x26)) {
      *(undefined2 *)((int)param_1 + 0x26) = 4;
      goto LAB_0001aff4;
    }
    uVar1 = 2;
  }
  *(undefined2 *)((int)param_1 + 0x26) = uVar1;
LAB_0001aff4:
  uVar3 = *(uint *)((int)param_1 + 0x10);
  iVar4 = 2;
  _memcpy((void *)((int)param_1 + 0x34),param_1,0x34);
  *(undefined4 *)((int)param_1 + 0x10) = 0x400;
  *(undefined4 *)((int)param_1 + 0x44) = 0x8000;
  if ((uVar3 & 0x800000) != 0) {
    iVar4 = 3;
    _memcpy((void *)((int)param_1 + 0x68),param_1,0x34);
    *(undefined2 *)((int)param_1 + 0x8e) = 0;
    *(undefined4 *)((int)param_1 + 0x78) = 0x800000;
    *(undefined2 *)((int)param_1 + 0x8c) = 0;
    *(uint *)((int)param_1 + 0x70) = *(uint *)((int)param_1 + 0x70) & 0xfffffbff;
  }
  if ((uVar3 & 0x2000000) != 0) {
    iVar5 = iVar4 * 0x34;
    iVar4 = iVar4 + 1;
    pvVar6 = (void *)((int)param_1 + iVar5);
    _memcpy(pvVar6,param_1,0x34);
    *(undefined2 *)((int)pvVar6 + 0x26) = 0;
    *(undefined4 *)((int)pvVar6 + 0x10) = 0x2000000;
    *(undefined2 *)((int)pvVar6 + 0x24) = 0;
    *(uint *)((int)pvVar6 + 8) = *(uint *)((int)pvVar6 + 8) & 0xfffffbff;
  }
  if ((uVar3 & 0x8000000) != 0) {
    iVar5 = iVar4 * 0x34;
    iVar4 = iVar4 + 1;
    pvVar6 = (void *)((int)param_1 + iVar5);
    _memcpy(pvVar6,param_1,0x34);
    *(undefined2 *)((int)pvVar6 + 0x26) = 0;
    *(undefined4 *)((int)pvVar6 + 0x10) = 0x8000000;
    *(undefined2 *)((int)pvVar6 + 0x24) = 0;
    *(uint *)((int)pvVar6 + 8) = *(uint *)((int)pvVar6 + 8) & 0xfffffbff;
  }
  if (iVar4 != 0) {
    iVar5 = 0;
    do {
      iVar2 = ((int (*)())FUN_0001ac30)(param_1);
      if (iVar2 != 0) {
        return 0;
      }
      iVar5 = iVar5 + 1;
      param_1 = (void *)((int)param_1 + 0x34);
    } while (iVar4 != iVar5);
  }
  return iVar4;
}

/* FUN_0001b150 @ 0x1b150 (88 bytes) */
int FUN_0001b150(param_1)
  int param_1;
{
  *(undefined1 *)(param_1 + 0x2a) = 1;
  *(undefined2 *)(param_1 + 0x26) = 1;
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 0xa800000;
  *(uint *)(param_1 + 0x1c) = *(uint *)(param_1 + 0x1c) | 1;
  *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x5000;
  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 2;
  *(undefined2 *)(param_1 + 0x24) = 2;
  *(undefined4 *)(param_1 + 0x2c) = 3;
  *(undefined2 *)(param_1 + 0x28) = 6;
  return;
}

/* _gldFreeVertexBuffer @ 0x1b1b0 (20 bytes) */
int _gldFreeVertexBuffer(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (param_2 == 0) {
    return;
  }
  *(undefined4 *)(param_2 + -0x6c) = 1;
  return;
}

/* _gldCompleteVertexBuffer @ 0x1b1d0 (4 bytes) */
int _gldCompleteVertexBuffer()
{
  return;
}

/* _gldAllocVertexBuffer @ 0x1b1e0 (676 bytes) */
int _gldAllocVertexBuffer(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int *param_3;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 uVar7;
  int iVar8;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  
  iVar4 = *param_3;
  local_48 = 8;
  *param_3 = 0;
  if (0x800 < iVar4) {
    return 0;
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
    return 0;
  }
  switch(param_2 & 0x7fff) {
  default:
    goto LAB_0001b494;
  case 1:
    uVar7 = 9;
    break;
  case 2:
    uVar7 = 10;
    break;
  case 3:
    uVar7 = 0xb;
    break;
  case 4:
    uVar7 = 0xc;
    break;
  case 5:
    uVar7 = 0xd;
    break;
  case 6:
    uVar7 = 0xe;
  }
  if (*(int *)(param_1 + 0x210) == 0) {
    local_3c = 2;
    local_38 = 0x16000;
    iVar4 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,&local_3c,0x14,&local_44,&local_48);
    if (iVar4 != 0) {
      return 0;
    }
    piVar1 = (int *)(local_40 + 0x10);
    *(int *)(local_44 + 0x1c) = local_40;
    do {
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(*piVar1 + 0x10000,0,piVar1);
        *piVar1 = iVar4;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    *(undefined1 *)(local_40 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x214) = 1;
    *(int *)(local_44 + 0x10) = local_44;
    goto LAB_0001b468;
  }
  iVar8 = *(int *)(*(int *)(param_1 + 0x210) + 0x10);
  iVar4 = *(int *)(iVar8 + 0x1c);
  if (*(int *)(iVar8 + 0x14) == 0) {
    if (0x7f < *(uint *)(param_1 + 0x214)) {
      return 0;
    }
LAB_0001b3e4:
    local_3c = 2;
    local_38 = 0x16000;
    iVar4 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,&local_3c,0x14,&local_44,&local_48);
    if (iVar4 != 0) {
LAB_0001b494:
      return 0;
    }
    piVar1 = (int *)(local_40 + 0x10);
    *(int *)(local_44 + 0x1c) = local_40;
    do {
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(*piVar1 + 0x10000,0,piVar1);
        *piVar1 = iVar4;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    *(undefined1 *)(local_40 + 0x14) = 1;
    *(int *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + 1;
    *(undefined4 *)(local_44 + 0x10) = *(undefined4 *)(*(int *)(param_1 + 0x210) + 0x10);
    *(int *)(*(int *)(param_1 + 0x210) + 0x10) = local_44;
  }
  else {
    if (*(int *)(iVar8 + 0x18) == *(int *)(param_1 + 0x23c)) {
      if (*(uint *)(param_1 + 0x214) < 0x80) goto LAB_0001b3e4;
      ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
      pbVar6 = *(byte **)(param_1 + 0x238);
      iVar2 = 0xf4241;
      do {
        if ((int)(*(int *)(iVar4 + 8) -
                 ((uint)pbVar6[3] << 0x18 | (uint)pbVar6[2] << 0x10 | (uint)pbVar6[1] << 8 |
                 (uint)*pbVar6)) < 1) break;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    else {
      uVar5 = *(uint *)(iVar4 + 8);
      pbVar6 = *(byte **)(param_1 + 0x238);
      uVar3 = (uint)pbVar6[3] << 0x18 | (uint)pbVar6[2] << 0x10 | (uint)pbVar6[1] << 8 |
              (uint)*pbVar6;
      in_cr0 = (uVar5 == uVar3) << 1;
      if (0 < (int)(uVar5 - uVar3)) {
        if (*(uint *)(param_1 + 0x214) < 0x80) goto LAB_0001b3e4;
        iVar4 = 0xf4241;
        do {
          if ((int)(uVar5 - ((uint)pbVar6[3] << 0x18 | (uint)pbVar6[2] << 0x10 |
                             (uint)pbVar6[1] << 8 | (uint)*pbVar6)) < 1) break;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
    *(undefined4 *)(iVar8 + 0x14) = 0;
    local_44 = iVar8;
  }
LAB_0001b468:
  iVar4 = *(int *)(param_1 + 0x23c);
  *(int *)(param_1 + 0x210) = local_44;
  *(undefined4 *)(local_44 + 0xc) = uVar7;
  *(int *)(local_44 + 0x18) = iVar4 + -1;
  *param_3 = 0x800;
  return local_44 + 0x80;
}

/* FUN_0001b4b0 @ 0x1b4b0 (44 bytes) */
int FUN_0001b4b0(param_1)
  int param_1;
{
  if ((*(uint *)(param_1 + 0x154) & 0x70000000) == 0) {
    ((unsigned char *)0x00002b7c)[param_1] = 1;
  }
  else {
    ((unsigned char *)0x00002b7c)[param_1] = 0;
  }
  ((unsigned char *)0x00002b7d)[param_1] = 1;
  return;
}

/* FUN_0001b510 @ 0x1b510 (1304 bytes) */
int FUN_0001b510(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  byte bVar2;
  char cVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  
  *(undefined4 *)(param_2[1] + 0x18) = 0;
  iVar17 = 6;
  piVar14 = param_2;
  do {
    piVar14[0x13] = 0;
    piVar14 = piVar14 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  *(undefined1 *)((int)param_2 + 0x11) = 0;
  *(undefined1 *)((int)param_2 + 0x12) = 0;
  param_2[0x12] = 0;
  param_2[5] = 0;
  *(undefined1 *)(param_2 + 4) = 1;
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  piVar14 = (int *)param_2[1];
  if ((piVar14[4] != 0) && (piVar14[5] != 0)) goto LAB_0001b730;
  if ((*(int *)(*(int *)(param_1 + 0x14) + 0xc) < (int)(uint)*(ushort *)(*param_2 + 0x9a)) ||
     (*(int *)(*(int *)(param_1 + 0x14) + 0x10) < (int)(uint)*(ushort *)(*param_2 + 0x9c)))
  goto LAB_0001b730;
  iVar17 = 0;
  iVar16 = 0;
  do {
    if (piVar14[iVar16] != 0) {
      if (iVar16 < 4) {
        iVar17 = piVar14[iVar16];
      }
      iVar10 = FUN_00032100(param_1);
      if (iVar10 == 0) {
        piVar14 = (int *)param_2[1];
        goto LAB_0001b730;
      }
      piVar14 = (int *)param_2[1];
    }
    puVar4 = PTR_DAT_001e88c8;
    bVar1 = iVar16 != 5;
    iVar16 = iVar16 + 1;
  } while (bVar1);
  if (iVar17 == 0) {
    param_2[9] = 0;
    *(undefined1 *)((int)param_2 + 0x13) = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    param_2[8] = 0;
  }
  else {
    bVar2 = *(byte *)(iVar17 + 0x38);
    param_2[6] = *(ushort *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x10) & 0x3f;
    param_2[7] = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x10) >> 10 & 0x3f;
    param_2[8] = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x10) >> 4 & 0x3f;
    uVar5 = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x10);
    if ((((uVar5 & 0x3f0000) == 0) || ((uVar5 & 0xfc00) == 0)) || ((uVar5 & 0x3f0) == 0)) {
      uVar5 = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x14);
LAB_0001b6ac:
      param_2[9] = uVar5 >> 0x1a;
    }
    else {
      uVar5 = *(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x14);
      if ((uVar5 >> 0x1a == 0) || (*(short *)(*(int *)(iVar17 + 0x30) + 2) != 0x1907))
      goto LAB_0001b6ac;
      param_2[9] = 0;
    }
    *(byte *)((int)param_2 + 0x13) =
         (byte)(*(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x20) >> 0x17) & 1;
    if ((*(uint *)(puVar4 + (uint)bVar2 * 0x24 + 0x18) & 0x10000) == 0) goto LAB_0001b730;
  }
  iVar17 = piVar14[4];
  if (iVar17 == 0) {
    param_2[10] = 0;
  }
  else {
    param_2[10] = *(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(iVar17 + 0x38) * 0x24 + 0x14) >> 8 &
                  0x3f;
    if ((*(char *)(iVar17 + 0x38) != '\x10') && (*(char *)(iVar17 + 0x38) != ')'))
    goto LAB_0001b730;
  }
  iVar16 = piVar14[5];
  if (iVar16 == 0) {
    param_2[0xb] = 0;
  }
  else {
    param_2[0xb] = *(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(iVar16 + 0x38) * 0x24 + 0x14) >> 4 &
                   0xf;
    if ((*(char *)(iVar16 + 0x38) != ')') || ((iVar17 != 0 && (iVar17 != iVar16)))) {
LAB_0001b730:
      piVar14[7] = 1;
      return 0;
    }
  }
  iVar17 = 6;
  piVar7 = piVar14;
  piVar12 = param_2;
  do {
    iVar16 = *piVar7;
    piVar7 = piVar7 + 1;
    if (iVar16 != 0) {
      piVar12[0x13] = *(int *)(iVar16 + 0x34);
    }
    puVar4 = PTR_DAT_001e88c8;
    piVar12 = piVar12 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  iVar17 = 4;
  piVar7 = piVar14;
  do {
    if (*piVar7 != 0) {
      switch(*(undefined1 *)(*piVar7 + 0x38)) {
      case 5:
        uVar15 = 0x4000;
        uVar5 = 5;
        break;
      case 6:
      case 7:
        uVar15 = 0x4000;
        uVar5 = 3;
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0x23:
      case 0x24:
        uVar15 = 0x4000;
        uVar5 = 4;
        break;
      default:
        uVar15 = 0x4000;
        uVar5 = 0;
        break;
      case 0x11:
      case 0x12:
        uVar15 = 0x4000;
        uVar5 = 0xd;
        break;
      case 0x17:
      case 0x18:
        uVar15 = 0x4000;
        uVar5 = 0xb;
        break;
      case 0x1d:
      case 0x1e:
        uVar15 = 0x4000;
        uVar5 = 0xc;
      }
      goto LAB_0001b8f4;
    }
    piVar7 = piVar7 + 1;
    iVar17 = iVar17 + -1;
  } while (iVar17 != 0);
  uVar15 = 0;
  uVar5 = 0;
LAB_0001b8f4:
  uVar8 = uVar5;
  if (piVar14[4] != 0) {
    cVar3 = *(char *)(piVar14[4] + 0x38);
    uVar15 = uVar15 | 0x100;
    uVar8 = uVar5 | 0x40;
    if (cVar3 == '\x10') {
      uVar8 = uVar5 | 0x10040;
    }
    else if (cVar3 == ')') {
      uVar8 = uVar5 | 0x20040;
    }
  }
  uVar5 = uVar8;
  if (piVar14[5] != 0) {
    uVar15 = uVar15 | 0x400;
    uVar5 = uVar8 | 0x80;
    if (*(char *)(piVar14[5] + 0x38) == ')') {
      uVar5 = uVar8 | 0x30080;
    }
  }
  iVar16 = 0;
  iVar17 = 0;
  piVar7 = piVar14;
  piVar12 = param_2;
  do {
    piVar13 = (int *)*piVar7;
    piVar7 = piVar7 + 1;
    if (piVar13 == (int *)0x0) {
      piVar12[0x25] = 0;
      piVar12[0x2b] = -1;
      piVar12[0x19] = 0;
      piVar12[0x1f] = 0;
    }
    else {
      iVar11 = *param_2;
      iVar9 = iVar17 + iVar11;
      iVar10 = *(int *)(iVar9 + 8);
      if (*(char *)(piVar13[0xd] + 0x16) == '\x06') {
        uVar8 = (uint)*(ushort *)((int)piVar13 + 0x3e) <<
                (*(uint *)(puVar4 + (uint)*(byte *)(piVar13 + 0xe) * 0x24 + 0x14) & 7);
        for (; iVar10 != 0; iVar10 = iVar10 + -1) {
          uVar8 = ((int)uVar8 >> 1) + (uint)((int)uVar8 < 0 && (uVar8 & 1) != 0);
        }
        iVar10 = 0;
      }
      else {
        iVar6 = *(int *)(iVar9 + 4) * 0xd + iVar10;
        uVar8 = *(uint *)(*piVar13 + 0xc);
        for (; iVar10 != 0; iVar10 = iVar10 + -1) {
          uVar8 = ((int)uVar8 >> 1) + (uint)((int)uVar8 < 0 && (uVar8 & 1) != 0);
        }
        iVar10 = *(int *)(iVar9 + 0xc) * uVar8 * (uint)*(ushort *)(iVar11 + 0x9c) +
                 *(int *)(*piVar13 + iVar6 * 0x20 + 0x48);
      }
      iVar9 = *(int *)piVar13[0xd];
      piVar12[0x19] = iVar10;
      piVar12[0x1f] = uVar8;
      piVar12[0x2b] = iVar9;
      piVar12[0x25] = (uint)*(ushort *)(iVar11 + 0x9a);
    }
    bVar1 = iVar16 != 5;
    iVar17 = iVar17 + 0x18;
    piVar12 = piVar12 + 1;
    iVar16 = iVar16 + 1;
  } while (bVar1);
  param_2[3] = uVar5;
  param_2[2] = uVar15;
  piVar14[7] = 0;
  *(undefined1 *)((int)param_2 + 0xc6) = 0;
  *(undefined1 *)((int)param_2 + 0xc5) = 1;
  *(undefined1 *)(param_2 + 0x31) = 0;
  return 1;
}

/* FUN_0001bac0 @ 0x1bac0 (904 bytes) */
int FUN_0001bac0(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  char in_RESERVE;
  byte in_cr0;
  int iVar9;
  
  ((unsigned char *)0x00002b7c)[param_1] = 0;
  puVar4 = (uint *)(**(code **)(param_1 + 0x2998))(param_1 + 0x240,0x83);
  iVar5 = 0;
  *(uint **)(param_1 + 0x298c) = puVar4;
  puVar2 = (undefined4 *)((uint)(puVar4 + 0xb) & 0xffffffe0);
  *puVar4 = (((int)puVar2 - (int)puVar4) + -8) * 0x4000 | 0xc0001000;
  puVar2[-1] = (int)puVar2 - (int)puVar4;
  iVar9 = 4;
  puVar4 = *(uint **)(param_1 + 0x1d8);
  *puVar4 = (int)puVar2 - (int)puVar4 >> 2 | *puVar4;
  *(undefined4 **)(param_1 + 0x1d8) = puVar2;
  *puVar2 = 0x41000000;
  puVar2[1] = 4;
  puVar2[2] = (uint)*(ushort *)(*param_2 + 0x9a);
  puVar2[3] = (uint)*(ushort *)(*param_2 + 0x9c);
  puVar2[4] = *(undefined4 *)(param_1 + 0x1d20);
  puVar2[5] = *(undefined4 *)(param_1 + 0x1cf0);
  piVar3 = puVar2 + 6;
  do {
    piVar6 = piVar3;
    uVar7 = (uint)*(ushort *)(iVar5 * 2 + *param_2 + 0x90);
    if (uVar7 == 0) {
      piVar6[5] = 0;
      *piVar6 = -1;
      piVar6[1] = 0;
      piVar6[2] = 0;
      piVar6[3] = 0;
      piVar6[4] = 0;
    }
    else {
      iVar1 = (uVar7 - 0x8ce0) * 4;
      *piVar6 = param_2[uVar7 - 0x8cb5];
      piVar6[1] = param_2[uVar7 - 0x8cc7];
      piVar6[2] = param_2[uVar7 - 0x8cc1];
      piVar6[3] = param_2[uVar7 - 0x8cbb];
      iVar8 = (uVar7 - 0x8ce0) * 0x18 + *param_2;
      piVar6[4] = *(int *)(iVar8 + 4) << 0x10 | *(uint *)(iVar8 + 8);
      piVar6[5] = (uint)*(byte *)(*(int *)(iVar1 + param_2[1]) + 0x38);
      *(undefined1 *)(*(int *)(iVar1 + param_2[1]) + 200) = 0;
      piVar3 = (int *)(*(int *)(*(int *)(iVar1 + param_2[1]) + 0x34) + 0x10);
      do {
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
          *piVar3 = iVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
    }
    piVar3 = piVar6 + 6;
    iVar5 = iVar5 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  if (*(int *)(param_2[1] + 0x10) == 0) {
    piVar6[0xb] = 0;
    piVar6[7] = 0;
    piVar6[8] = 0;
    piVar6[9] = 0;
    *piVar3 = -1;
    piVar6[10] = 0;
  }
  else {
    *piVar3 = param_2[0x2f];
    piVar6[7] = param_2[0x1d];
    piVar6[8] = param_2[0x23];
    piVar6[9] = param_2[0x29];
    piVar6[10] = *(int *)(*param_2 + 100) << 0x10 | *(uint *)(*param_2 + 0x68);
    piVar6[0xb] = (uint)*(byte *)(*(int *)(param_2[1] + 0x10) + 0x38);
    *(undefined1 *)(*(int *)(param_2[1] + 0x10) + 200) = 0;
    piVar3 = (int *)(*(int *)(*(int *)(param_2[1] + 0x10) + 0x34) + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
        *piVar3 = iVar5;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  }
  if (*(int *)(param_2[1] + 0x14) == 0) {
    piVar6[0x11] = 0;
    piVar6[0xd] = 0;
    piVar6[0xe] = 0;
    piVar6[0xf] = 0;
    piVar6[0xc] = -1;
    piVar6[0x10] = 0;
  }
  else {
    piVar6[0xc] = param_2[0x30];
    piVar6[0xd] = param_2[0x1e];
    piVar6[0xe] = param_2[0x24];
    piVar6[0xf] = param_2[0x2a];
    piVar6[0x10] = *(int *)(*param_2 + 0x7c) << 0x10 | *(uint *)(*param_2 + 0x80);
    piVar6[0x11] = (uint)*(byte *)(*(int *)(param_2[1] + 0x14) + 0x38);
    *(undefined1 *)(*(int *)(param_2[1] + 0x14) + 200) = 0;
    piVar3 = (int *)(*(int *)(*(int *)(param_2[1] + 0x14) + 0x34) + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar5 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
        *piVar3 = iVar5;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  }
  *(int **)(param_1 + 0x298c) = piVar6 + 0x4b;
  (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
  if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
    ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
  }
  ((unsigned char *)0x00002b7d)[param_1] = 1;
  return;
}

/* FUN_0001be50 @ 0x1be50 (868 bytes) */
int FUN_0001be50(param_1, param_2)
  int param_1;
  byte *param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  byte local_78 [4];
  undefined1 local_74;
  undefined1 local_73;
  undefined1 local_72;
  undefined1 local_71;
  int local_70 [4];
  int local_60;
  uint local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  int local_4c;
  uint local_48;
  int local_44;
  int local_40;
  uint local_3c;
  int local_38;
  int local_34;
  
  iVar10 = 0x10;
  uVar8 = 0xff;
  uVar9 = 0;
  iVar3 = param_1;
  do {
    uVar2 = (uint)*(byte *)(iVar3 + 3);
    iVar3 = iVar3 + 4;
    if (uVar2 < uVar8) {
      uVar8 = uVar2;
    }
    if (uVar9 < uVar2) {
      uVar9 = uVar2;
    }
    iVar10 = iVar10 + -1;
  } while (iVar10 != 0);
  if (uVar8 == 0) {
    if (uVar9 != 0xff) {
LAB_0001bfec:
      local_78[0] = (byte)uVar8;
      local_78[1] = (byte)uVar9;
      local_78[3] = (char)((uVar8 * 3 + uVar9 * 2) / 5);
      local_74 = (char)((uVar8 * 2 + uVar9 * 3) / 5);
      local_78[2] = (char)((uVar9 + uVar8 * 4) / 5);
      local_73 = (char)((uVar8 + uVar9 * 4) / 5);
      local_72 = 0;
      local_71 = 0xff;
      goto LAB_0001bf84;
    }
  }
  else if (uVar9 == 0xff) goto LAB_0001bfec;
  local_78[0] = (byte)uVar9;
  local_78[1] = (byte)uVar8;
  local_78[2] = (char)((uVar8 + uVar9 * 6) / 7);
  local_78[3] = (char)((uVar9 * 5 + uVar8 * 2) / 7);
  local_74 = (char)((uVar9 * 4 + uVar8 * 3) / 7);
  local_73 = (char)((uVar9 * 3 + uVar8 * 4) / 7);
  local_72 = (char)((uVar9 * 2 + uVar8 * 5) / 7);
  local_71 = (char)((uVar9 + uVar8 * 6) / 7);
LAB_0001bf84:
  iVar3 = 0;
  do {
    iVar10 = 0;
    piVar6 = local_70 + iVar3 * 4;
    pbVar7 = (byte *)(param_1 + iVar3 * 0x10 + 3);
    do {
      uVar8 = 0xff;
      iVar5 = 0;
      iVar4 = 0;
      iVar11 = 8;
      do {
        if ((uint)local_78[iVar4] - (uint)*pbVar7 < uVar8) {
          iVar5 = iVar4;
          uVar8 = (uint)local_78[iVar4] - (uint)*pbVar7;
        }
        iVar4 = iVar4 + 1;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
      bVar1 = iVar10 != 3;
      *piVar6 = iVar5;
      pbVar7 = pbVar7 + 4;
      piVar6 = piVar6 + 1;
      iVar10 = iVar10 + 1;
    } while (bVar1);
    bVar1 = iVar3 != 3;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  param_2[1] = local_78[1];
  param_2[2] = (byte)(local_70[2] << 6) | (byte)(local_70[1] << 3) | (byte)local_70[0];
  param_2[3] = (byte)(local_5c << 7) | (byte)(local_60 << 4) | (byte)(local_70[3] << 1) |
               (byte)((uint)local_70[2] >> 2) & 1;
  param_2[5] = (byte)(local_48 << 6) | (byte)(local_4c << 3) | (byte)local_50;
  param_2[4] = (byte)(local_54 << 5) | (byte)(local_58 << 2) | (byte)(local_5c >> 1) & 3;
  param_2[6] = (byte)(local_3c << 7) | (byte)(local_40 << 4) | (byte)(local_44 << 1) |
               (byte)(local_48 >> 2) & 1;
  param_2[7] = (byte)(local_34 << 5) | (byte)(local_38 << 2) | (byte)(local_3c >> 1) & 3;
  *param_2 = local_78[0];
  return param_2 + 8;
}

/* FUN_0001c380 @ 0x1c380 (3664 bytes) */
int FUN_0001c380(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined1 *param_5;
  byte *param_6;
{
  byte *pbVar1;
  byte *pbVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  ushort uVar8;
  ushort uVar9;
  ushort uVar10;
  ushort uVar11;
  ushort uVar12;
  ushort uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  ushort *puVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  byte bVar22;
  byte bVar24;
  byte *pbVar23;
  int iVar25;
  uint uVar26;
  byte bVar27;
  undefined1 *puVar28;
  uint *puVar29;
  byte bVar30;
  byte bVar31;
  int iVar32;
  byte *pbVar33;
  uint uVar34;
  ushort *puVar35;
  byte bVar36;
  int iVar37;
  int *piVar38;
  byte *pbVar39;
  uint uVar40;
  byte *pbVar41;
  int iVar42;
  byte *pbVar43;
  byte bVar45;
  uint uVar44;
  int iVar46;
  int iVar47;
  int iVar48;
  int iVar49;
  int iVar50;
  byte *pbVar51;
  byte in_xer_so;
  int iVar52;
  int iStack00000024;
  byte local_508 [4];
  byte local_504;
  byte local_503;
  byte local_502;
  byte local_501;
  byte local_500;
  byte local_4ff;
  byte local_4fe;
  byte local_4fd;
  byte local_4fc;
  byte local_4fb;
  byte local_4fa;
  byte local_4f9;
  byte local_4f8;
  byte local_4f7;
  undefined1 local_4f6;
  undefined1 local_4f5;
  undefined1 local_4f4;
  undefined1 local_4f3;
  undefined1 local_4f2;
  undefined1 local_4f1;
  int local_4f0 [4];
  byte local_4e0 [16];
  ushort local_4d0 [12];
  byte local_4b8 [7];
  byte local_4b1;
  byte local_4ad;
  byte local_4a9;
  byte local_4a5;
  byte local_4a1;
  byte local_49d;
  byte local_499;
  byte local_495;
  byte local_491;
  byte local_48d;
  byte local_489;
  byte local_485;
  byte local_481;
  byte local_47d;
  byte local_479;
  uint auStack_478 [256];
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  byte *local_68;
  uint *local_64;
  int local_60;
  undefined1 *local_5c;
  uint *local_58;
  ushort *local_54;
  
  if (param_3 == 0x80e0) {
    iVar46 = 2;
    iVar47 = 3;
  }
  else if (param_3 == 0x80e1) {
    iVar46 = 2;
    iVar47 = 4;
  }
  else if (param_3 == 0x1907) {
    iVar46 = 0;
    iVar47 = 3;
  }
  else {
    iVar46 = 0;
    iVar47 = 4;
  }
  if ((param_1 + 3U < 7) || (param_2 + 3U < 7)) {
    iVar48 = param_1;
    if (param_1 < 4) {
      iVar48 = 4;
    }
    local_70 = param_2;
    if (param_2 < 4) {
      local_70 = 4;
    }
    else if (param_2 < 1) {
      return;
    }
    bVar3 = 0 < iVar48;
    iVar50 = 0;
    iVar49 = 0;
    do {
      if (bVar3) {
        iVar25 = 0;
        puVar28 = &DAT_001f65e7 + iVar49 * 4;
        iVar52 = iVar48;
        do {
          iVar42 = iVar47 * (iVar25 + iVar49);
          iVar32 = param_1 * (iVar50 - (iVar50 / param_2) * param_2) +
                   (iVar25 - (iVar25 / param_1) * param_1);
          iVar16 = iVar47 * iVar32;
          (DAT_001f65e4)[iVar42] = param_5[iVar16];
          (DAT_001f65e5)[iVar42] = param_5[iVar16 + 1];
          (DAT_001f65e6)[iVar42] = param_5[iVar16 + 2];
          if (iVar47 == 4) {
            *puVar28 = param_5[iVar32 * 4 + 3];
          }
          iVar25 = iVar25 + 1;
          puVar28 = puVar28 + 4;
          iVar52 = iVar52 + -1;
        } while (iVar52 != 0);
      }
      iVar50 = iVar50 + 1;
      iVar49 = iVar49 + iVar48;
    } while (local_70 != iVar50);
    param_5 = &DAT_001f65e4;
    param_1 = iVar48;
  }
  else {
    if (param_2 < 1) {
      return;
    }
    local_70 = param_2;
    bVar3 = 0 < param_1;
  }
  bVar4 = iVar47 != 4;
  local_68 = &local_500;
  local_5c = param_5 + iVar46;
  local_58 = auStack_478;
  local_54 = local_4d0;
  local_60 = (uint)(byte)((param_4 < 0xc) << 3 | (0xc < param_4) << 2 | (param_4 == 0xc) << 1 |
                         in_xer_so & 1) << 0x1c;
  local_78 = 0;
  iStack00000024 = param_4;
  do {
    param_6 = (byte *)((uint)(param_6 + 0x1f) & 0xffffffe0);
    if (bVar3) {
      local_74 = 0;
      local_64 = auStack_478;
      local_6c = 0x55555556;
      do {
        if ((bool)((byte)((uint)local_60 >> 0x1d) & 1)) {
          if (bVar4) {
LAB_0001c6fc:
            iVar48 = 0;
            do {
              iVar50 = 0;
              iVar52 = 4;
              pbVar33 = local_4b8 + iVar48 * 0x10;
              iVar49 = local_74 + param_1 * (iVar48 + local_78);
              do {
                iVar25 = iVar50 + iVar49;
                iVar50 = iVar50 + 1;
                iVar25 = iVar47 * iVar25;
                *pbVar33 = local_5c[iVar25];
                pbVar33[1] = param_5[iVar25 + 1];
                pbVar33[2] = param_5[(iVar25 - iVar46) + 2];
                pbVar33[3] = 0xff;
                pbVar33 = pbVar33 + 4;
                iVar52 = iVar52 + -1;
              } while (iVar52 != 0);
              bVar6 = iVar48 != 3;
              iVar48 = iVar48 + 1;
            } while (bVar6);
            goto LAB_0001c78c;
          }
          bVar6 = false;
          iVar48 = 0;
          do {
            iVar50 = 4;
            pbVar43 = local_4b8 + iVar48 * 0x10;
            iVar49 = (local_74 + param_1 * (iVar48 + local_78)) * 4;
            pbVar33 = param_5 + iVar46 + iVar49;
            puVar28 = param_5 + iVar49;
            pbVar39 = param_5 + (iVar49 - iVar46) + 2;
            do {
              *pbVar43 = *pbVar33;
              pbVar43[1] = puVar28[1];
              pbVar43[2] = *pbVar39;
              bVar7 = puVar28[3];
              pbVar43[3] = bVar7;
              if (bVar7 < 0x7f) {
                bVar6 = true;
              }
              pbVar33 = pbVar33 + 4;
              pbVar43 = pbVar43 + 4;
              puVar28 = puVar28 + 4;
              pbVar39 = pbVar39 + 4;
              iVar50 = iVar50 + -1;
            } while (iVar50 != 0);
            bVar5 = iVar48 != 3;
            iVar48 = iVar48 + 1;
          } while (bVar5);
        }
        else {
          if (bVar4) goto LAB_0001c6fc;
          iVar48 = 0;
          do {
            iVar50 = 4;
            pbVar43 = local_4b8 + iVar48 * 0x10;
            iVar49 = (local_74 + param_1 * (iVar48 + local_78)) * 4;
            pbVar33 = param_5 + iVar46 + iVar49;
            puVar28 = param_5 + iVar49;
            pbVar39 = param_5 + (iVar49 - iVar46) + 2;
            do {
              bVar7 = *pbVar33;
              pbVar33 = pbVar33 + 4;
              *pbVar43 = bVar7;
              pbVar43[1] = puVar28[1];
              bVar7 = *pbVar39;
              pbVar39 = pbVar39 + 4;
              pbVar43[2] = bVar7;
              pbVar51 = puVar28 + 3;
              puVar28 = puVar28 + 4;
              pbVar43[3] = *pbVar51;
              pbVar43 = pbVar43 + 4;
              iVar50 = iVar50 + -1;
            } while (iVar50 != 0);
            bVar6 = iVar48 != 3;
            iVar48 = iVar48 + 1;
          } while (bVar6);
LAB_0001c78c:
          bVar6 = false;
        }
        iVar48 = 0;
        while (iVar49 = iVar48 + 1, iVar48 != 0xf) {
          iVar50 = iVar48 * 4;
          puVar29 = local_58 + iVar48 * 0x10 + iVar49;
          iVar52 = 0x10 - iVar49;
          bVar7 = local_4b8[iVar50 + 2];
          bVar22 = local_4b8[iVar50];
          bVar24 = local_4b8[iVar50 + 1];
          iVar50 = iVar49;
          if (0x10 < iVar48 + 2) {
            iVar52 = 1;
          }
          do {
            iVar48 = iVar50 * 4;
            iVar50 = iVar50 + 1;
            uVar8 = (ushort)((int)((uint)local_4b8[iVar48] - (uint)bVar22) >> 0x1f);
            uVar9 = (ushort)((int)((uint)local_4b8[iVar48 + 1] - (uint)bVar24) >> 0x1f);
            uVar10 = (ushort)((int)((uint)local_4b8[iVar48 + 2] - (uint)bVar7) >> 0x1f);
            *puVar29 = (int)(short)((uVar8 ^ (ushort)((uint)local_4b8[iVar48] - (uint)bVar22)) -
                                   uVar8) +
                       (int)(short)((uVar9 ^ (ushort)((uint)local_4b8[iVar48 + 1] - (uint)bVar24)) -
                                   uVar9) +
                       (int)(short)((uVar10 ^ (ushort)((uint)local_4b8[iVar48 + 2] - (uint)bVar7)) -
                                   uVar10);
            puVar29 = puVar29 + 1;
            iVar52 = iVar52 + -1;
            iVar48 = iVar49;
          } while (iVar52 != 0);
        }
        bVar5 = !bVar6;
        uVar26 = 0;
        do {
          iVar48 = 0;
          iVar49 = 0x10;
          do {
            local_4e0[iVar48] = (byte)iVar48;
            iVar48 = iVar48 + 1;
            iVar49 = iVar49 + -1;
          } while (iVar49 != 0);
          iVar48 = 0x10;
          uVar34 = 0;
          do {
            bVar7 = local_4e0[uVar34];
            uVar40 = uVar34 + 1;
            if ((bVar7 == uVar34) && ((int)uVar40 < 0x10)) {
              iVar49 = 0x10 - uVar40;
              pbVar33 = local_4e0 + uVar34 + 1;
              puVar29 = local_64 + uVar34 * 0x10 + uVar40;
              uVar34 = uVar40;
              do {
                if (*puVar29 < uVar26) {
                  if (uVar34 == *pbVar33) {
                    iVar48 = iVar48 + -1;
                    *pbVar33 = bVar7;
                  }
                  else if (*puVar29 < auStack_478[(uint)*pbVar33 * 0x10 + uVar34]) {
                    *pbVar33 = bVar7;
                  }
                }
                uVar34 = uVar34 + 1;
                puVar29 = puVar29 + 1;
                pbVar33 = pbVar33 + 1;
                iVar49 = iVar49 + -1;
              } while (iVar49 != 0);
            }
            uVar34 = uVar40;
          } while (uVar40 != 0x10);
          uVar26 = uVar26 + 4;
        } while ((int)(bVar5 + 3) < iVar48);
        if (iVar48 < 1) {
          iVar25 = 0;
          iVar49 = 0;
        }
        else {
          iVar50 = 0;
          puVar17 = local_54;
          iVar49 = iVar48;
          do {
            *puVar17 = 0;
            local_508[iVar50] = 0;
            iVar50 = iVar50 + 1;
            puVar17[1] = 0;
            puVar17[2] = 0;
            puVar17 = puVar17 + 3;
            iVar49 = iVar49 + -1;
          } while (iVar49 != 0);
          iVar49 = 0;
          uVar26 = 0xffffffff;
          puVar17 = local_54;
          do {
            iVar50 = 0;
            pbVar33 = local_4e0;
            iVar52 = 0x10;
            do {
              if ((int)uVar26 < (int)(uint)local_4e0[iVar50]) {
                uVar26 = (uint)*pbVar33;
                break;
              }
              iVar50 = iVar50 + 1;
              pbVar33 = pbVar33 + 1;
              iVar52 = iVar52 + -1;
            } while (iVar52 != 0);
            if ((int)uVar26 < 0x10) {
              iVar50 = 0x10 - uVar26;
              pbVar33 = local_4e0 + uVar26;
              uVar34 = uVar26;
              do {
                if (uVar26 == *pbVar33) {
                  iVar52 = uVar34 * 4;
                  uVar8 = *puVar17;
                  bVar27 = local_508[iVar49];
                  *pbVar33 = (byte)iVar49;
                  bVar7 = local_4b8[iVar52];
                  bVar22 = local_4b8[iVar52 + 1];
                  bVar24 = local_4b8[iVar52 + 2];
                  local_508[iVar49] = bVar27 + 1;
                  *puVar17 = bVar7 + uVar8;
                  puVar17[1] = (ushort)bVar22 + puVar17[1];
                  puVar17[2] = (ushort)bVar24 + puVar17[2];
                }
                uVar34 = uVar34 + 1;
                pbVar33 = pbVar33 + 1;
                iVar50 = iVar50 + -1;
              } while (iVar50 != 0);
            }
            bVar7 = local_508[iVar49];
            iVar49 = iVar49 + 1;
            *puVar17 = *puVar17 / (ushort)bVar7;
            puVar17[1] = puVar17[1] / (ushort)bVar7;
            puVar17[2] = puVar17[2] / (ushort)bVar7;
            puVar17 = puVar17 + 3;
          } while (iVar48 != iVar49);
          iVar50 = 0;
          iVar49 = 0;
          iVar25 = 0;
          puVar17 = local_54;
          iVar52 = 0;
          do {
            iVar16 = iVar52 + 1;
            if (iVar16 < iVar48) {
              iVar42 = iVar48 - iVar16;
              puVar35 = local_54 + iVar16 * 3;
              iVar32 = iVar16;
              do {
                uVar8 = (short)(*puVar17 - *puVar35) >> 0xf;
                uVar9 = (short)(puVar17[1] - puVar35[1]) >> 0xf;
                uVar10 = (short)(puVar17[2] - puVar35[2]) >> 0xf;
                iVar37 = (int)(short)((uVar8 ^ *puVar17 - *puVar35) - uVar8) +
                         (int)(short)((uVar9 ^ puVar17[1] - puVar35[1]) - uVar9) +
                         (int)(short)((uVar10 ^ puVar17[2] - puVar35[2]) - uVar10);
                if (iVar50 < iVar37) {
                  iVar49 = iVar52;
                  iVar50 = iVar37;
                  iVar25 = iVar32;
                }
                iVar32 = iVar32 + 1;
                puVar35 = puVar35 + 3;
                iVar42 = iVar42 + -1;
              } while (iVar42 != 0);
            }
            puVar17 = puVar17 + 3;
            iVar52 = iVar16;
          } while (iVar48 != iVar16);
        }
        uVar8 = local_4d0[iVar49 * 3];
        uVar9 = local_4d0[iVar25 * 3];
        uVar10 = local_4d0[iVar49 * 3 + 2];
        uVar11 = local_4d0[iVar49 * 3 + 1];
        uVar12 = local_4d0[iVar25 * 3 + 2];
        uVar13 = local_4d0[iVar25 * 3 + 1];
        uVar40 = uVar8 & 0xf8;
        uVar26 = uVar10 & 0xf8;
        uVar34 = uVar11 & 0xfc;
        uVar20 = uVar9 & 0xf8;
        if ((uVar40 == (uVar9 & 0xf8)) && (uVar20 = uVar40, uVar8 != uVar9)) {
          if (uVar9 < uVar8) {
            if (uVar40 < 0xf8) {
              uVar40 = uVar40 + 8 & 0xf8;
            }
          }
          else if (uVar40 < 0xf8) {
            uVar20 = uVar40 + 8 & 0xff;
          }
        }
        uVar44 = uVar13 & 0xfc;
        if ((uVar34 == (uVar13 & 0xfc)) && (uVar44 = uVar34, uVar11 != uVar13)) {
          if (uVar13 < uVar11) {
            if (uVar34 < 0xfc) {
              uVar34 = uVar34 + 4 & 0xff;
            }
          }
          else if (uVar34 < 0xfc) {
            uVar44 = uVar34 + 4 & 0xff;
          }
        }
        uVar21 = uVar12 & 0xf8;
        if ((uVar26 == (uVar12 & 0xf8)) && (uVar21 = uVar26, uVar10 != uVar12)) {
          if (uVar12 < uVar10) {
            if (uVar26 < 0xf8) {
              uVar26 = uVar26 + 8 & 0xff;
            }
          }
          else if (uVar26 < 0xf8) {
            uVar21 = uVar26 + 8 & 0xff;
          }
        }
        uVar18 = uVar40 << 8 | uVar34 << 3;
        uVar15 = uVar20 << 8 | uVar44 << 3;
        uVar19 = uVar18 | uVar26 >> 3;
        uVar14 = uVar15 | uVar21 >> 3;
        bVar30 = (byte)uVar40;
        bVar27 = (byte)uVar34;
        bVar24 = (byte)uVar26;
        bVar36 = (byte)uVar20;
        bVar31 = (byte)uVar44;
        bVar22 = (byte)uVar21;
        bVar45 = (byte)uVar19;
        local_502 = (byte)uVar14;
        bVar7 = (byte)(uVar18 >> 8);
        local_501 = (byte)(uVar15 >> 8);
        if (bVar5) {
          if (uVar14 < uVar19) {
            local_4fc = bVar30;
            local_4fb = bVar27;
            local_4fa = bVar24;
            local_4f9 = bVar36;
            local_503 = bVar7;
            local_4f8 = bVar31;
            local_4f7 = bVar22;
            local_504 = bVar45;
          }
          else {
            local_4f9 = bVar30;
            local_4f8 = bVar27;
            local_4f7 = bVar24;
            local_4fc = bVar36;
            local_503 = local_501;
            local_501 = bVar7;
            local_4fb = bVar31;
            local_4fa = bVar22;
            local_504 = local_502;
            local_502 = bVar45;
          }
          local_4f6 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fc * 2 + (uint)local_4f9) *
                             (longlong)local_6c) >> 0x20);
          local_4f5 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fb * 2 + (uint)local_4f8) *
                             (longlong)local_6c) >> 0x20);
          local_4f4 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fa * 2 + (uint)local_4f7) *
                             (longlong)local_6c) >> 0x20);
          local_4f3 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fc + (uint)local_4f9 * 2) *
                             (longlong)local_6c) >> 0x20);
          local_4f2 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fb + (uint)local_4f8 * 2) *
                             (longlong)local_6c) >> 0x20);
          local_4f1 = (char)((ulonglong)
                             ((longlong)(int)((uint)local_4fa + (uint)local_4f7 * 2) *
                             (longlong)local_6c) >> 0x20);
        }
        else {
          if (uVar14 < uVar19) {
            local_4fc = bVar36;
            local_4fb = bVar31;
            local_4fa = bVar22;
            local_4f9 = bVar30;
            local_503 = local_501;
            local_501 = bVar7;
            local_4f8 = bVar27;
            local_4f7 = bVar24;
            local_504 = local_502;
            local_502 = bVar45;
          }
          else {
            local_4f9 = bVar36;
            local_4f8 = bVar31;
            local_4f7 = bVar22;
            local_4fc = bVar30;
            local_503 = bVar7;
            local_4fb = bVar27;
            local_4fa = bVar24;
            local_504 = bVar45;
          }
          local_4f6 = (char)((int)((uint)local_4fc + (uint)local_4f9) >> 1);
          local_4f5 = (char)((int)((uint)local_4fb + (uint)local_4f8) >> 1);
          local_4f4 = (char)((int)((uint)local_4fa + (uint)local_4f7) >> 1);
        }
        local_4fd = 0;
        local_500 = 0;
        local_4ff = 0;
        local_4fe = 0;
        if (bVar5) {
          uVar26 = 4;
        }
        else {
          uVar26 = 3;
        }
        iVar48 = 0;
        pbVar43 = local_4b8 + 2;
        pbVar39 = local_4b8 + 1;
        pbVar51 = local_4b8 + 3;
        pbVar33 = local_68;
        do {
          uVar34 = (uint)*pbVar33;
          uVar40 = 0;
          pbVar23 = local_4b8 + iVar48 * 0x10 + 3;
          do {
            if ((!bVar6) || (uVar20 = 3, 0x7e < *pbVar23)) {
              if (uVar26 != 0) {
                bVar7 = pbVar23[(int)(local_4b8 + (iVar48 * 0x10 - (int)pbVar51))];
                bVar22 = pbVar23[(int)pbVar39 - (int)pbVar51];
                bVar24 = pbVar23[(int)pbVar43 - (int)pbVar51];
                pbVar41 = &local_4fc;
                iVar49 = 0;
                uVar20 = uVar26;
                do {
                  pbVar1 = pbVar41 + 1;
                  bVar27 = *pbVar41;
                  pbVar2 = pbVar41 + 2;
                  pbVar41 = pbVar41 + 3;
                  local_4f0[iVar49] =
                       ((uint)bVar7 - (uint)bVar27) * ((uint)bVar7 - (uint)bVar27) +
                       ((uint)bVar22 - (uint)*pbVar1) * ((uint)bVar22 - (uint)*pbVar1) * 4 +
                       ((uint)bVar24 - (uint)*pbVar2) * ((uint)bVar24 - (uint)*pbVar2);
                  uVar20 = uVar20 - 1;
                  iVar49 = iVar49 + 1;
                } while (uVar20 != 0);
              }
              if (uVar26 < 2) {
                uVar20 = 0;
              }
              else {
                iVar50 = uVar26 - 1;
                uVar44 = 1;
                piVar38 = local_4f0;
                uVar20 = 0;
                iVar49 = local_4f0[0];
                do {
                  piVar38 = piVar38 + 1;
                  if (*piVar38 < iVar49) {
                    uVar20 = uVar44;
                    iVar49 = *piVar38;
                  }
                  uVar44 = uVar44 + 1;
                  iVar50 = iVar50 + -1;
                } while (iVar50 != 0);
                uVar20 = uVar20 & 3;
              }
            }
            bVar5 = uVar40 != 6;
            uVar44 = uVar40 & 0x3f;
            pbVar23 = pbVar23 + 4;
            uVar40 = uVar40 + 2;
            uVar34 = uVar20 << uVar44 | uVar34;
            *pbVar33 = (byte)uVar34;
          } while (bVar5);
          bVar5 = iVar48 != 3;
          pbVar51 = pbVar51 + 0x10;
          pbVar39 = pbVar39 + 0x10;
          pbVar43 = pbVar43 + 0x10;
          pbVar33 = pbVar33 + 1;
          iVar48 = iVar48 + 1;
        } while (bVar5);
        if (param_4 == 0xd) {
          if (bVar4) {
            param_6[7] = 0xff;
            *param_6 = 0xff;
            param_6[1] = 0xff;
            param_6[2] = 0xff;
            param_6[3] = 0xff;
            param_6[4] = 0xff;
            param_6[5] = 0xff;
            param_6[6] = 0xff;
            param_6 = param_6 + 8;
          }
          else {
            *param_6 = local_4b1 & 0xf0 | local_4b8[3] >> 4;
            param_6[1] = local_4a9 & 0xf0 | local_4ad >> 4;
            param_6[2] = local_4a1 & 0xf0 | local_4a5 >> 4;
            param_6[3] = local_499 & 0xf0 | local_49d >> 4;
            param_6[4] = local_491 & 0xf0 | local_495 >> 4;
            param_6[5] = local_489 & 0xf0 | local_48d >> 4;
            param_6[6] = local_481 & 0xf0 | local_485 >> 4;
            param_6[7] = local_479 & 0xf0 | local_47d >> 4;
            param_6 = param_6 + 8;
          }
        }
        else if (iStack00000024 == 0xe) {
          param_6 = (byte *)((int (*)())FUN_0001be50)(local_4b8,param_6);
        }
        local_74 = local_74 + 4;
        *param_6 = local_504;
        param_6[1] = local_503;
        param_6[2] = local_502;
        param_6[3] = local_501;
        param_6[4] = local_500;
        param_6[5] = local_4ff;
        param_6[6] = local_4fe;
        param_6[7] = local_4fd;
        param_6 = param_6 + 8;
      } while (local_74 < param_1);
    }
    local_78 = local_78 + 4;
    if (local_70 <= local_78) {
      return;
    }
  } while( true );
}

/* FUN_0001d7c0 @ 0x1d7c0 (148 bytes) */
uint FUN_0001d7c0(double param_1)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  fVar1 = (float)param_1;
  uVar3 = (uint)fVar1 >> 0x17 & 0xff;
  iVar2 = uVar3 - 0x7f;
  if (iVar2 < 0x11) {
    if (iVar2 < -0xe) {
      if (iVar2 < -0x25) {
        iVar4 = 0;
        uVar3 = 0;
      }
      else {
        iVar4 = 0;
        uVar3 = (((uint)fVar1 & 0x7fffff | 0x800000) >> (-iVar2 - 0xeU & 0x3f)) >> 0xd;
      }
    }
    else {
      iVar4 = uVar3 - 0x70;
      uVar3 = ((uint)fVar1 & 0x7fffff) >> 0xd;
    }
  }
  else {
    iVar4 = 0x1f;
    uVar3 = 0x3ff;
  }
  return ((uint)fVar1 >> 0x1f) << 0xf | iVar4 << 10 | uVar3;
}

/* FUN_0001d880 @ 0x1d880 (704 bytes) */
int FUN_0001d880(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  short sVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  
  bVar1 = param_2 == 0;
  iVar19 = *param_1;
  if (bVar1) {
    uVar17 = *(uint *)(iVar19 + 0x314);
  }
  else {
    uVar17 = 0;
  }
  iVar16 = *(int *)(iVar19 + 0x318);
  if (((*(uint *)(param_1[1] + 0x88) & 1) == 0) || (!bVar1)) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if (bVar1) {
    if ((uVar17 == 0) || (uVar15 = 1, iVar16 == 0)) {
      uVar15 = 0;
    }
    if ((uVar17 & 3) != 0) {
      uVar15 = 0;
    }
  }
  else {
    uVar15 = 1;
  }
  uVar7 = *(uint *)(iVar19 + 0x304) & 0xffff0000;
  if (!bVar4) {
    uVar14 = *(uint *)(param_1[1] + 0x88) & 0xff7f0000;
  }
  else {
    uVar14 = 0xff7f0000;
  }
  bVar2 = uVar14 == 0;
  iVar20 = 0;
  iVar18 = 0;
LAB_0001dae4:
  do {
    while (bVar2) {
      uVar7 = *(uint *)(iVar19 + 0x300);
      if (!bVar4) {
        uVar14 = *(uint *)(param_1[1] + 0x84) & 0xffff;
      }
      else {
        uVar14 = 0xffff;
      }
      iVar18 = iVar18 + 1;
      if (1 < iVar18) {
        iVar19 = param_1[1];
        *(undefined4 *)(iVar19 + 0x84) = 0;
        *(uint *)(iVar19 + 0x88) = *(uint *)(iVar19 + 0x88) & 0xfffb;
        return uVar15;
      }
      bVar2 = uVar14 == 0;
      iVar20 = 0x10;
    }
    uVar5 = *(uint *)(&DAT_001d91f0 + iVar20 * 4);
    if ((uVar14 & uVar5) != 0) {
      uVar14 = uVar14 & ~uVar5;
      puVar9 = (undefined1 *)((int)param_1 + iVar20 + 8);
      bVar2 = uVar14 == 0;
      *(undefined1 *)((int)param_1 + iVar20 + 8) = 1;
      if ((uVar7 & uVar5) != 0) {
        iVar10 = iVar20 * 0x18;
        iVar6 = iVar10 + iVar19;
        uVar13 = *(uint *)(iVar10 + iVar19);
        uVar5 = (uint)*(short *)(iVar6 + 10);
        uVar8 = *(uint *)(iVar6 + 4);
        iVar12 = uVar5 - 1;
        uVar11 = (*(ushort *)(iVar6 + 8) & 0xffff7fff) - 0x1400;
        if (((!bVar1) || (((uVar17 <= uVar13 && (uVar13 < iVar16 + uVar17)) && ((uVar13 & 3) == 0)))
            ) && ((uVar5 < 5 && (uVar8 < 0x200)))) {
          if ((uVar8 & 3) == 0) {
            if ((uVar11 < 0xb) && (iVar6 = uVar11 * 4, *(int *)(&DAT_001d96f4 + iVar6) == 1)) {
              if (uVar8 != 0) {
                uVar5 = uVar8 >> 2;
              }
              bVar2 = uVar14 == 0;
              iVar12 = (iVar6 + iVar12) * 4;
              param_1[iVar20 + 10] =
                   *(uint *)(&DAT_001d9644 + iVar12) & 0x7f |
                   (uVar5 & 0x7f) << 8 | param_1[iVar20 + 10] & 0xffff8080U;
              param_1[iVar20 + 0x2a] = uVar13 - uVar17;
              uVar8 = *(uint *)(&DAT_001d9568 + iVar6);
              uVar5 = *(uint *)(&DAT_001d9594 + iVar12);
              sVar3 = *(short *)(iVar10 + iVar19 + 8);
              param_1[iVar20 + 0x6a] =
                   (*(uint *)(&DAT_001d92a8 + iVar12) & 7) << 9 |
                   (*(uint *)(&DAT_001d9358 + iVar12) & 7) << 6 |
                   (*(uint *)(&DAT_001d9408 + iVar12) & 7) << 3 |
                   *(uint *)(&DAT_001d94b8 + iVar12) & 7 | param_1[iVar20 + 0x6a] & 0xfffff000U;
              param_1[iVar20 + 0x4a] =
                   (uint)(int)sVar3 >> 0x10 & 0x8000 |
                   (uVar8 & 1) << 0xe | uVar5 & 0xf | param_1[iVar20 + 0x4a] & 0xffff3ff0U;
              goto LAB_0001dae0;
            }
            bVar2 = uVar14 == 0;
            *puVar9 = 0;
            goto LAB_0001dae4;
          }
        }
        bVar2 = uVar14 == 0;
        *puVar9 = 0;
        goto LAB_0001dae4;
      }
    }
LAB_0001dae0:
    iVar20 = iVar20 + 1;
  } while( true );
}

/* FUN_0001db50 @ 0x1db50 (180 bytes) */
int FUN_0001db50(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  uint *param_3;
  uint *param_4;
  uint *param_5;
  int *param_6;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0x7fe0;
  if (*(uint *)(param_1 + 0x29d8) < 0x7ffd) {
    uVar1 = *(uint *)(param_1 + 0x29d8) & 0xffffffe0;
  }
  *param_3 = 0;
  *param_5 = 0;
  *param_4 = 0;
  *param_6 = 0;
  if (param_2 < uVar1) {
    *param_3 = param_2;
    if ((param_2 & 0x1f) != 0) {
      *param_3 = param_2 + 0x1f & 0xffffffe0;
    }
    uVar1 = 0;
    *param_5 = 1;
    uVar2 = *param_3;
  }
  else {
    *param_3 = uVar1;
    *param_5 = param_2 / uVar1;
    uVar2 = *param_3;
    uVar1 = (param_2 - (param_2 / uVar2) * uVar2) + 3 & 0xfffffffc;
  }
  *param_4 = uVar2 >> 2;
  if (0x1fff < *param_5) {
    return 0;
  }
  *param_6 = 2 - (uint)(uVar1 == 0);
  return 1;
}

/* FUN_0001dc10 @ 0x1dc10 (976 bytes) */
int FUN_0001dc10(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint local_38;
  int local_34;
  uint local_30;
  uint local_2c [3];
  
  iVar5 = param_2[1];
  iVar7 = *param_2;
  if (*(int *)(iVar5 + 0x84) != 0 || (*(uint *)(iVar5 + 0x88) & 0xfffffff5) != 0) {
    iVar5 = ((int (*)())FUN_0001d880)(param_2,0);
    if (iVar5 == 0) {
      return 0;
    }
    iVar5 = param_2[1];
  }
  uVar4 = *(uint *)(iVar5 + 0x88);
  if (*(int *)(iVar5 + 0x84) == 0 && uVar4 == 0) {
    return 1;
  }
  if ((param_2[0x8a] != 0) && (((uVar4 ^ 1) & 1) != 0)) {
    if (*(short *)(iVar7 + 0x312) == -0x7a42) {
      if (param_2[0x8c] == 7) {
        if ((uVar4 & 2) != 0) {
          *(undefined1 *)(param_2[0x8a] + 0x14) = 1;
          *(ushort *)(param_2[0x8a] + 0x1c) = *(ushort *)(param_2[0x8a] + 0x1c) | 1;
          *(ushort *)(param_2[0x8a] + 0x28) = *(ushort *)(param_2[0x8a] + 0x28) & 0xfffe;
          iVar5 = param_2[1];
        }
        goto LAB_0001dcf8;
      }
    }
    else if (param_2[0x8c] == 6) {
LAB_0001dcf8:
      *(undefined4 *)(iVar5 + 0x84) = 0;
      *(undefined4 *)(iVar5 + 0x88) = 0;
      return 1;
    }
  }
  local_2c[0] = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  iVar5 = ((int (*)())FUN_0001db50)(param_1,*(undefined4 *)(iVar7 + 0x318),local_2c,&local_30,&local_34,&local_38
                      );
  if (iVar5 != 0) {
    if (local_38 < 2) {
      uVar3 = *(uint *)(iVar7 + 0x318);
      uVar4 = 0;
    }
    else {
      uVar3 = *(uint *)(iVar7 + 0x318);
      uVar4 = (uVar3 - (uVar3 / local_2c[0]) * local_2c[0]) + 3 & 0xfffffffc;
    }
    if ((*(short *)(iVar7 + 0x312) == -0x7a42) && (local_38 < 0x4f)) {
      iVar5 = FUN_0000bd60(param_1,param_2,(local_38 * 0x12 + 0xc) * 4,
                           uVar4 + local_2c[0] * local_34,*(undefined4 *)(iVar7 + 0x314));
      if (iVar5 != 0) goto LAB_0001ddc0;
      uVar3 = *(uint *)(iVar7 + 0x318);
    }
    iVar5 = FUN_0000bc60(param_1,param_2,*(undefined4 *)(iVar7 + 0x314),
                         *(undefined4 *)(iVar7 + 0x314),uVar3);
    if (iVar5 != 0) {
LAB_0001ddc0:
      if (param_2[0x8c] == 7) {
        uVar3 = *(uint *)(iVar7 + 0x314);
        *(undefined1 *)(param_2[0x8a] + 0x15) = 0;
        uVar3 = (uVar3 & 0xfff) - (uVar3 & 0xfe0) >> 2;
        *(undefined1 *)(param_2[0x8a] + 0x17) = 0;
        *(undefined1 *)(param_2[0x8a] + 0x34) = 1;
        *(undefined1 *)(param_2[0x8a] + 0x35) = 1;
        piVar6 = (int *)param_2[0x8b];
        piVar6[0x280] = (int)((unsigned char *)0x00001393);
        piVar6[8] = piVar6[8] & 0xafffffffU | 0xa0000000;
        piVar6[0x281] = 10;
        piVar6[0x287] = 2;
        piVar6[0x285] = 2;
        piVar6[0x283] = 0x20000;
        piVar6[0x284] = 0x575;
        piVar6[0x282] = 0x5c8;
        piVar6[0x286] = 0x574;
        *(short *)(piVar6 + 0x10) = (short)((int)(piVar6 + 0x288) - (int)(piVar6 + 0x280) >> 2);
        uVar1 = *(uint *)(iVar7 + 0x314);
        piVar6[0x12] = 0;
        piVar6[0x11] = uVar1 & 0xfe0;
        piVar6[0x13] = local_2c[0] * local_34;
        piVar6[0x14] = local_2c[0] * local_34;
        piVar6[0x15] = 0;
        *(short *)((int)piVar6 + 0x42) = (short)local_38;
        piVar6[0x17] = 0;
        puVar2 = (undefined4 *)
                 FUN_00030a60(piVar6 + 0x288,6,local_2c[0],local_2c[0],0,uVar3,
                              local_34 << 0x10 | local_30);
        if (uVar4 != 0) {
          puVar2 = (undefined4 *)
                   FUN_00030a60(puVar2,6,local_2c[0],local_2c[0],0,uVar3,uVar4 >> 2 | 0x10000);
        }
        *(ushort *)(param_2[0x8a] + 0x1c) = *(ushort *)(param_2[0x8a] + 0x1c) | 1;
        *(ushort *)(param_2[0x8a] + 0x28) = *(ushort *)(param_2[0x8a] + 0x28) & 0xfffe;
        *puVar2 = 0xd0b;
        puVar2[2] = 0x5c8;
        puVar2[1] = 5;
        puVar2[3] = 0x10000;
        *piVar6 = (int)puVar2 + (0x10 - (int)(piVar6 + 0x280)) >> 2;
      }
      *(undefined1 *)(param_2[0x8a] + 0x14) = 1;
      iVar5 = param_2[1];
      *(undefined4 *)(iVar5 + 0x84) = 0;
      *(undefined4 *)(iVar5 + 0x88) = 0;
      return 1;
    }
  }
  return 0;
}

/* FUN_0001dff0 @ 0x1dff0 (140 bytes) */
int FUN_0001dff0(param_1)
  int param_1;
{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = (**(code **)(param_1 + 0x2998))(param_1 + 0x240,1);
  *(int *)(param_1 + 0x298c) = iVar2;
  puVar3 = *(uint **)(param_1 + 0x1d8);
  *puVar3 = iVar2 - (int)puVar3 >> 2 | *puVar3;
  puVar1 = *(undefined4 **)(param_1 + 0x298c);
  *(undefined4 **)(param_1 + 0x1d8) = puVar1;
  *puVar1 = 0x3a000000;
  *(undefined4 **)(param_1 + 0x298c) = puVar1 + 1;
                    
                    
  (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
  return;
}

/* _gldPageoffBuffer @ 0x1e080 (480 bytes) */
int _gldPageoffBuffer(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_28;
  undefined4 local_24;
  
  if (*(int *)(param_2 + 8) != 0) {
    _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
    puVar3 = (undefined4 *)**(undefined4 **)(param_2 + 8);
    cVar1 = (*(unsigned char *)((unsigned char *)&(MACH_HEADER.sizeofcmds) + 2));
    if ((puVar3 == (undefined4 *)0x0) ||
       (cVar1 = *(char *)((int)puVar3 + 0x16), *(char *)((int)puVar3 + 0x16) != '\a')) {
      if (cVar1 == '\x06') {
        if ((0x1ffff < (int)puVar3[4]) &&
           (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))) {
          ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
        }
        if ((*(ushort *)(puVar3 + 10) & ~*(ushort *)(puVar3 + 7) & 1) != 0) {
          iVar4 = ((int (*)())FUN_0001a0d0)(param_1,puVar3[3]);
          if (iVar4 == 0) {
            _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,puVar3 + 3,1,0,0);
          }
          *(ushort *)(puVar3 + 7) = *(ushort *)(puVar3 + 7) | *(ushort *)(puVar3 + 10);
        }
      }
    }
    else {
      if ((0x1ffff < (int)puVar3[4]) &&
         (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))) {
        ((int (*)())FUN_0001a0f0)(param_1,0x1000000);
      }
      if ((*(ushort *)(puVar3 + 10) & ~*(ushort *)(puVar3 + 7) & 1) != 0) {
        local_28 = *puVar3;
        local_24 = 0;
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xd,&local_28,2,0,0);
      }
      iVar4 = *(int *)(*(int *)(param_2 + 8) + 4);
      if ((*(uint *)(iVar4 + 0x20) & 0x10000000) != 0) {
        iVar2 = ((int (*)())FUN_0001a0d0)(param_1,*(undefined4 *)(iVar4 + 0x1c));
        if (iVar2 == 0) {
          _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar4 + 0x1c,1,0,0);
        }
        *(uint *)(iVar4 + 0x20) = *(uint *)(iVar4 + 0x20) & 0xefffffff;
      }
    }
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  }
  return;
}

/* FUN_0001e280 @ 0x1e280 (1184 bytes) */
int FUN_0001e280(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  uint uVar9;
  int *piVar10;
  uint *puVar11;
  uint local_48;
  int local_44;
  uint local_40;
  uint local_3c [6];
  
  bVar1 = param_3 == 0;
  if (bVar1) {
    *(undefined1 *)(param_2 + 3) = 1;
  }
  puVar11 = (uint *)*param_2;
  if (*puVar11 == 0) {
    return 0;
  }
  if (((int *)param_2[2] == (int *)0x0) || (iVar5 = *(int *)param_2[2], iVar5 == 0)) {
LAB_0001e3b0:
    local_3c[0] = 0;
    local_48 = 0;
    local_44 = 0;
    local_40 = 0;
    iVar5 = ((int (*)())FUN_0001db50)(param_1,puVar11[1],local_3c,&local_40,&local_44,&local_48);
    if (iVar5 == 0) {
      return 0;
    }
    if (local_48 < 2) {
      uVar7 = puVar11[1];
      uVar9 = 0;
    }
    else {
      uVar7 = puVar11[1];
      uVar9 = (uVar7 - (uVar7 / local_3c[0]) * local_3c[0]) + 3 & 0xfffffffc;
    }
    if ((*(short *)(puVar11 + 3) == -0x771c) && (local_48 < 0x4f)) {
      if (bVar1) {
        iVar5 = 0;
      }
      else {
        iVar5 = 0x49;
      }
      iVar5 = FUN_000065b0(param_1,param_2,iVar5 + (local_48 * 0x12 + 0xc) * 4,
                           uVar9 + local_3c[0] * local_44,*puVar11);
      if (iVar5 == 0) {
        uVar7 = puVar11[1];
        goto LAB_0001e440;
      }
    }
    else {
LAB_0001e440:
      iVar5 = FUN_00006470(param_1,param_2,*puVar11,*puVar11,uVar7);
      if (iVar5 == 0) {
        return 0;
      }
    }
    if (param_2[4] == 7) {
      uVar7 = *puVar11;
      *(undefined1 *)(*(int *)param_2[2] + 0x15) = 0;
      uVar7 = (uVar7 & 0xfff) - (uVar7 & 0xfe0) >> 2;
      *(undefined1 *)(*(int *)param_2[2] + 0x17) = 0;
      *(undefined1 *)(*(int *)param_2[2] + 0x34) = 1;
      *(undefined1 *)(*(int *)param_2[2] + 0x35) = 1;
      piVar10 = *(int **)(param_2[2] + 4);
      piVar10[0x280] = (int)((unsigned char *)0x00001393);
      piVar10[8] = piVar10[8] & 0xbfffffffU | 0xa0000000;
      piVar10[0x281] = 10;
      piVar10[0x283] = 0x20000;
      piVar10[0x287] = 2;
      piVar10[0x285] = 2;
      piVar10[0x284] = 0x575;
      piVar10[0x282] = 0x5c8;
      piVar10[0x286] = 0x574;
      *(short *)(piVar10 + 0x10) = (short)((int)(piVar10 + 0x288) - (int)(piVar10 + 0x280) >> 2);
      uVar2 = *puVar11;
      piVar10[0x12] = 0;
      piVar10[0x11] = uVar2 & 0xfe0;
      piVar10[0x13] = local_3c[0] * local_44;
      piVar10[0x14] = local_3c[0] * local_44;
      piVar10[0x17] = 0;
      piVar10[0x15] = 0;
      *(short *)((int)piVar10 + 0x42) = (short)local_48;
      puVar4 = (undefined4 *)
               FUN_00030a60(piVar10 + 0x288,6,local_3c[0],local_3c[0],0,uVar7,
                            local_44 << 0x10 | local_40);
      if (uVar9 != 0) {
        puVar4 = (undefined4 *)
                 FUN_00030a60(puVar4,6,local_3c[0],local_3c[0],0,uVar7,uVar9 >> 2 | 0x10000);
      }
      puVar8 = puVar4 + 4;
      *(ushort *)(*(int *)param_2[2] + 0x1c) = *(ushort *)(*(int *)param_2[2] + 0x1c) | 1;
      *(ushort *)(*(int *)param_2[2] + 0x28) = *(ushort *)(*(int *)param_2[2] + 0x28) & 0xfffe;
      *puVar4 = 0xd0b;
      puVar4[2] = 0x5c8;
      puVar4[1] = 5;
      puVar4[3] = 0x10000;
      if (!bVar1) {
        uVar3 = *(undefined4 *)(((unsigned char *)0x00001d74) + param_1);
        puVar8 = puVar4 + 5;
        puVar4[4] = 0x4790b1;
        iVar5 = 0x48;
        do {
          *puVar8 = uVar3;
          puVar8 = puVar8 + 1;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      *piVar10 = (int)puVar8 - (int)(piVar10 + 0x280) >> 2;
    }
    *(undefined1 *)(*(int *)param_2[2] + 0x14) = 1;
    puVar6 = (uint *)param_2[1];
    if (((*puVar6 & 2) == 0) || ((*(uint *)(param_1 + 0x24) & 2) == 0)) goto LAB_0001e6e0;
    FUN_0000b620(param_1,*puVar11,puVar11[2]);
  }
  else {
    puVar6 = (uint *)param_2[1];
    uVar9 = *puVar6;
    if (((uVar9 ^ 1) & 1) == 0) goto LAB_0001e3b0;
    if (*(short *)(puVar11 + 3) != -0x771c) {
      if (param_2[4] == 6) {
        if (((uVar9 & 2) != 0) && ((*(uint *)(param_1 + 0x24) & 2) != 0)) {
          FUN_0000b620(param_1,*puVar11,puVar11[2]);
          puVar6 = (uint *)param_2[1];
        }
        goto LAB_0001e6e0;
      }
      goto LAB_0001e3b0;
    }
    if (param_2[4] != 7) goto LAB_0001e3b0;
    if ((uVar9 & 2) == 0) goto LAB_0001e6e0;
    *(undefined1 *)(iVar5 + 0x14) = 1;
    *(ushort *)(*(int *)param_2[2] + 0x1c) = *(ushort *)(*(int *)param_2[2] + 0x1c) | 1;
    *(ushort *)(*(int *)param_2[2] + 0x28) = *(ushort *)(*(int *)param_2[2] + 0x28) & 0xfffe;
    if ((*(uint *)(param_1 + 0x24) & 2) != 0) {
      FUN_0000b620(param_1,*puVar11,puVar11[2]);
      puVar6 = (uint *)param_2[1];
      goto LAB_0001e6e0;
    }
  }
  puVar6 = (uint *)param_2[1];
LAB_0001e6e0:
  *puVar6 = 0;
  return 1;
}

/* FUN_0001e730 @ 0x1e730 (332 bytes) */
int FUN_0001e730(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  
  iVar7 = *param_2;
  iVar6 = param_2[1];
  uVar5 = *(uint *)(iVar7 + 0x304);
  if ((*(uint *)(iVar7 + 0x300) & ~*(uint *)(iVar7 + 0x308)) == 0 &&
      (uVar5 & ~*(uint *)(iVar7 + 0x30c)) == 0) {
    if (*(int *)(iVar6 + 0x84) != 0 || (*(uint *)(iVar6 + 0x88) & 0xfffffff5) != 0) {
      iVar3 = ((int (*)())FUN_0001d880)(param_2,1);
      if (iVar3 == 0) goto LAB_0001e86c;
      uVar5 = *(uint *)(iVar7 + 0x304);
    }
    uVar5 = uVar5 & 0xffff0000;
    iVar8 = 0;
    iVar3 = 0;
    bVar1 = uVar5 == 0;
    while( true ) {
      while (!bVar1) {
        uVar9 = *(uint *)(&DAT_001d91f0 + iVar8 * 4);
        if ((uVar5 & uVar9) != 0) {
          iVar4 = *(int *)(iVar8 * 4 + iVar6);
          if ((iVar4 == 0) || (iVar4 = ((int (*)())FUN_0001e280)(param_1,iVar4,0), iVar4 == 0))
          goto LAB_0001e86c;
          uVar5 = uVar5 & ~uVar9;
          bVar1 = uVar5 == 0;
        }
        iVar8 = iVar8 + 1;
      }
      iVar3 = iVar3 + 1;
      uVar5 = *(uint *)(iVar7 + 0x300) & 0xffff;
      if (1 < iVar3) break;
      bVar1 = uVar5 == 0;
      iVar8 = 0x10;
    }
    if (*(int *)(iVar6 + 0x80) != 0) {
      ((int (*)())FUN_0001e280)(param_1,*(int *)(iVar6 + 0x80),1);
    }
    iVar6 = param_2[1];
    uVar2 = 1;
    *(undefined4 *)(iVar6 + 0x84) = 0;
    *(undefined4 *)(iVar6 + 0x88) = 0;
  }
  else {
LAB_0001e86c:
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_0001fd00 @ 0x1fd00 (1208 bytes) */
int FUN_0001fd00(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  bool bVar16;
  uint uVar15;
  int *piVar17;
  int iVar18;
  uint *puVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  
  *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
  *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
  *(undefined4 *)(param_1 + 0x2494) = 0;
  iVar8 = *(int *)(param_1 + 4);
  piVar13 = *(int **)(iVar8 + 0x1d4);
  if (piVar13 == (int *)0x0) {
    return;
  }
  iVar6 = *piVar13;
  iVar18 = piVar13[1];
  uVar24 = *(uint *)(param_1 + 0x243c);
  bVar1 = *(uint *)(iVar6 + 0x308) == 0;
  bVar2 = *(uint *)(iVar6 + 0x30c) == 0;
  if (*(int *)(iVar8 + 0x1cc) == 0) {
    uVar7 = *(uint *)(iVar6 + 0x304);
    if ((uVar7 & 0x10000) == 0) goto LAB_0001fdc0;
  }
  else {
    uVar7 = *(uint *)(iVar6 + 0x304);
    if ((*(uint *)(iVar6 + 0x300) & 1) == 0 && (uVar7 & 0x10000) == 0) {
LAB_0001fdc0:
      bVar16 = true;
      goto LAB_0001fd8c;
    }
  }
  bVar16 = false;
LAB_0001fd8c:
  if (((((*(char *)(iVar8 + 0x20) == '\0') || (0x10 < uVar24)) || (uVar24 < 2)) ||
      ((!bVar1 || !bVar2 &&
       ((*(uint *)(iVar6 + 0x300) & ~*(uint *)(iVar6 + 0x308)) != 0 ||
        (uVar7 & ~*(uint *)(iVar6 + 0x30c)) != 0)))) || (bVar16)) {
switchD_0001ffbc_default:
    *(undefined1 *)(param_1 + 0x24e4) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x24dc) = 0;
    *(undefined4 *)(param_1 + 0x24e0) = 0;
    *(undefined1 *)(param_1 + 0x24e4) = 1;
    if (*(int **)(iVar8 + 0x1cc) == (int *)0x0) {
      iVar21 = 0;
      piVar17 = (int *)0x0;
      iVar20 = 0;
      iVar8 = 0;
    }
    else {
      iVar20 = *(int *)(**(int **)(iVar8 + 0x1cc) + 4);
      iVar21 = *(int *)(iVar8 + 0x29e8) + 0x14;
      piVar17 = *(int **)(*(int *)(iVar8 + 0x29e8) + 0x34);
      iVar8 = *(int *)(iVar20 + 0x24);
    }
    puVar19 = (uint *)0x0;
    uVar15 = 0;
    uVar23 = 0;
    uVar7 = 0;
    iVar22 = 0;
    *(uint *)(param_1 + 0x2588) = uVar24 & 0x1f | 0x20;
    iVar25 = 0x16;
    do {
      bVar16 = *(int *)(*(int *)(param_1 + 4) + 0x1cc) == 0;
      if (bVar16) {
        if ((1 << (uVar23 & 0x3f) & *(uint *)(param_1 + 0x1ca0)) != 0) goto LAB_0001ff00;
      }
      else if ((*(int *)(iVar22 + *(int *)(iVar21 + 0x20)) != 0x80) ||
              (*(uint *)(iVar21 + 0x1c) <= uVar23)) {
LAB_0001ff00:
        if (iVar20 != 0) {
          if (uVar23 < *(uint *)(iVar21 + 0x1c)) {
            puVar19 = (uint *)(iVar20 + (iVar8 + *(int *)((int)piVar17 + iVar22)) * 8);
          }
          else {
            puVar19 = (uint *)(iVar20 + (iVar8 + *piVar17) * 8);
          }
        }
        if (bVar16) {
          uVar11 = *(uint *)(iVar22 + 0x1d9720);
        }
        else {
          uVar14 = *puVar19;
          uVar11 = *(uint *)(&DAT_001d9778 + (uVar14 >> 0xe & 0x3c));
          if (uVar11 == 8) {
            uVar11 = (uVar14 & 0x1f) + 8;
          }
          else if (uVar11 == 0x10) {
            uVar11 = (uVar14 & 0x1f) + 0x10;
          }
          else if (uVar11 == 0x2f) {
            switch(uVar14 >> 0xc & 0xf) {
            case 0:
              uVar11 = (uVar14 & 1) + 0x20;
              break;
            case 1:
              uVar11 = (uVar14 & 1) + 0x22;
              break;
            case 2:
              uVar11 = (uVar14 & 1) + 0x24;
              break;
            case 3:
              uVar11 = (uVar14 & 1) + 0x26;
              break;
            case 4:
              uVar11 = (uVar14 & 1) + 0x28;
              break;
            default:
              goto switchD_0001ffbc_default;
            }
          }
        }
        if (uVar11 == 0x30) goto switchD_0001ffbc_default;
        if (uVar11 < 0x10) {
          uVar14 = *(uint *)(iVar6 + 0x304);
        }
        else {
          uVar14 = *(uint *)(iVar6 + 0x300);
        }
        if ((uVar14 & *(uint *)(&DAT_001d91f0 + uVar11 * 4)) == 0) {
          *(int *)(param_1 + 0x24e0) = *(int *)(param_1 + 0x24e0) + 4;
          *(uint *)(param_1 + 0x24dc) = 1 << (uVar23 & 0x3f) | *(uint *)(param_1 + 0x24dc);
          if (bVar1 && bVar2) {
            iVar9 = 4;
            iVar5 = -1;
            uVar14 = 3;
            uVar12 = 0x688;
            iVar10 = uVar15 << 2;
          }
          else {
            iVar10 = uVar15 * 4;
            iVar9 = 4;
            iVar5 = -1;
            uVar14 = 3;
            uVar12 = 0x688;
            *(undefined4 *)(iVar10 + param_1 + 0x24e8) = *(undefined4 *)(iVar10 + param_1 + 0x24e4);
          }
        }
        else {
          if (*(char *)((int)piVar13 + uVar11 + 8) == '\0') {
            *(undefined1 *)(param_1 + 0x24e4) = 0;
            return;
          }
          iVar9 = piVar13[uVar11 + 10];
          iVar5 = piVar13[uVar11 + 0x2a];
          uVar14 = piVar13[uVar11 + 0x4a];
          uVar12 = piVar13[uVar11 + 0x6a];
          if (bVar1 && bVar2) {
            iVar10 = uVar15 << 2;
          }
          else {
            iVar10 = uVar15 * 4;
            puVar3 = *(undefined4 **)(*(int *)(iVar18 + uVar11 * 4) + 8);
            if (puVar3 != (undefined4 *)0x0) {
              *(undefined4 *)(iVar10 + param_1 + 0x24e8) = *puVar3;
            }
          }
        }
        if ((uVar15 & 1) == 0) {
          iVar4 = uVar7 * 4 + param_1;
          *(int *)(iVar4 + 0x2528) = iVar9;
          *(int *)(iVar10 + param_1 + 0x2548) = iVar5;
          *(uint *)(iVar4 + 0x2410) = uVar12 | *(uint *)(iVar4 + 0x1c04) & 0xf000;
          *(uint *)(iVar4 + 0x23f0) =
               uVar14 | *(uint *)(iVar4 + 0x1be4) & 0x1f00 | *(uint *)(iVar4 + 0x1be4) & 0x2000;
        }
        else {
          iVar4 = uVar7 * 4 + param_1;
          *(uint *)(iVar4 + 0x2528) = iVar9 << 0x10 | *(uint *)(iVar4 + 0x2528);
          *(int *)(iVar10 + param_1 + 0x2548) = iVar5;
          *(uint *)(iVar4 + 0x2410) =
               uVar12 << 0x10 | *(uint *)(iVar4 + 0x1c04) & 0xf0000000 | *(uint *)(iVar4 + 0x2410);
          *(uint *)(iVar4 + 0x23f0) =
               uVar14 << 0x10 | *(uint *)(iVar4 + 0x1be4) & 0x1f000000 |
               *(uint *)(iVar4 + 0x1be4) & 0x20000000 | *(uint *)(iVar4 + 0x23f0);
        }
        uVar15 = uVar15 + 1;
        uVar7 = uVar15 >> 1;
      }
      if (uVar15 == uVar24) {
        return;
      }
      uVar23 = uVar23 + 1;
      iVar22 = iVar22 + 4;
      iVar25 = iVar25 + -1;
    } while (iVar25 != 0);
  }
  return;
}

/* FUN_00020210 @ 0x20210 (280 bytes) */
int FUN_00020210(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  iVar3 = *(int *)(param_1 + 0x10);
  if (((unsigned char *)0x00003190)[iVar3] == '\0') {
    local_20 = *(int *)(param_1 + 0x15c);
    local_1c = *(int *)(param_1 + 0x160);
    local_28 = 0;
    local_24 = 0;
  }
  else {
    local_28 = *(int *)(((unsigned char *)0x00003180) + iVar3);
    if (((unsigned char *)0x00002b7c)[param_1] == '\0') {
      local_24 = *(int *)(((unsigned char *)0x00003184) + iVar3);
      iVar1 = *(int *)(((unsigned char *)0x0000318c) + iVar3);
      iVar2 = *(int *)(param_1 + 0x160);
    }
    else {
      iVar1 = *(int *)(((unsigned char *)0x0000318c) + iVar3);
      iVar2 = *(int *)(param_1 + 0x160);
      local_24 = iVar2 - (*(int *)(((unsigned char *)0x00003184) + iVar3) + iVar1);
    }
    iVar3 = *(int *)(((unsigned char *)0x00003188) + iVar3);
    if (local_28 < 0) {
      iVar3 = iVar3 + local_28;
      local_28 = 0;
    }
    if (local_24 < 0) {
      iVar1 = iVar1 + local_24;
      local_24 = 0;
    }
    local_20 = *(int *)(param_1 + 0x15c) - local_28;
    if (iVar3 <= local_20) {
      local_20 = iVar3;
    }
    local_1c = iVar2 - local_24;
    if (iVar1 <= iVar2 - local_24) {
      local_1c = iVar1;
    }
    if (local_20 < 1) {
      return;
    }
    if (local_1c < 1) {
      return;
    }
  }
  local_20 = local_28 + local_20;
  local_1c = local_24 + local_1c;
  FUN_0008f7f0(param_1 + 0x240,0,0,&local_28,0);
  return;
}

/* FUN_00020330 @ 0x20330 (216 bytes) */
int FUN_00020330(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x10);
  param_2 = param_2 & *(uint *)(param_1 + 0x158);
  if (((((unsigned char *)0x00002e43)[iVar1] == '\0' && ((unsigned char *)0x00002e40)[iVar1] == '\0') &&
      ((unsigned char *)0x00002e41)[iVar1] == '\0') && ((unsigned char *)0x00002e42)[iVar1] == '\0') {
    param_2 = param_2 & 0xffffbfff;
  }
  if (((unsigned char *)0x00002e44)[iVar1] == '\0') {
    param_2 = param_2 & 0xfffffeff;
  }
  if ((param_2 & 0x200) != 0) {
    FUN_000027d0(param_1,iVar1);
  }
  if ((param_2 & 0x4000) != 0) {
    param_2 = param_2 & 0xffffbfff;
    ((int (*)())FUN_00020210)(param_1);
  }
  if ((param_2 & 0x500) != 0) {
    FUN_000a6cb0(param_1 + 0x240,param_2);
    return;
  }
  return;
}

/* FUN_00020b00 @ 0x20b00 (40 bytes) */
int FUN_00020b00(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x2a7c) = 0;
  *(undefined4 *)(param_1 + 0x2a70) = 0;
  *(undefined1 *)(param_1 + 0x2a6c) = 0;
  *(undefined1 *)(param_1 + 0x2a6a) = 0;
  *(undefined4 *)(param_1 + 0x2a74) = 0;
  *(undefined4 *)(param_1 + 0x2a78) = 0;
  return;
}

/* _gldUpdateDispatch @ 0x22290 (2632 bytes) */
int _gldUpdateDispatch(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  undefined4 *puVar13;
  short *psVar14;
  uint uVar15;
  uint uVar16;
  char cVar17;
  uint *puVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  uint *puVar25;
  bool bVar26;
  int iVar27;
  
  if (*(char *)(param_1 + 0x2a69) == '\0') {
    if (*(char *)(param_1 + 0x2a44) != '\0') {
      param_3[2] = param_3[2] | 0xfffffffd;
      *param_3 = 0xffffffff;
      param_3[1] = param_3[1] | 0x3ffffff;
      param_3[3] = param_3[3] | 0x7ffffff;
      param_3[4] = 0xffffffff;
      *(undefined4 *)(param_1 + 0x29fc) = 0xffffffff;
      *(undefined1 *)(param_1 + 0x2a44) = 0;
      *(undefined1 *)(param_1 + 0x2a43) = 1;
      ((unsigned char *)0x000026bd)[param_1] = 1;
      *(uint *)(((unsigned char *)0x000026c8) + param_1) = *(uint *)(((unsigned char *)0x000026c8) + param_1) | 7;
    }
  }
  else {
    param_3[2] = param_3[2] | 0xfffffffd;
    *param_3 = 0xffffffff;
    param_3[1] = param_3[1] | 0x3ffffff;
    param_3[3] = param_3[3] | 0x7ffffff;
    param_3[4] = 0xffffffff;
    *(undefined4 *)(param_1 + 0x29fc) = 0xffffffff;
    *(undefined1 *)(param_1 + 0x2a43) = 1;
    *(undefined1 *)(param_1 + 0x2a44) = 0;
    ((unsigned char *)0x000026bd)[param_1] = 1;
    *(undefined1 *)(param_1 + 0x2a69) = 0;
    *(uint *)(((unsigned char *)0x000026c8) + param_1) = *(uint *)(((unsigned char *)0x000026c8) + param_1) | 7;
  }
  if ((int)*param_3 < 0) {
    FUN_00007d50(param_1);
  }
  piVar12 = *(int **)(param_1 + 0x150);
  if (((piVar12 == (int *)0x0) || (*(ushort *)(*piVar12 + 0x90) == 0)) ||
     (iVar8 = *(int *)((uint)*(ushort *)(*piVar12 + 0x90) * 4 + piVar12[1] + -0x23380), iVar8 == 0))
  {
LAB_00022438:
    uVar16 = 4;
    if ((*param_3 & 0x180) != 0) {
      if (piVar12 != (int *)0x0) {
        ((int (*)())FUN_0001bac0)(param_1);
      }
      if ((*(int *)(*(int *)(param_1 + 0x18) + 0x1a0) == 0) ||
         (uVar16 = 0xc, *(int *)(param_1 + 0x150) != 0)) {
        uVar16 = 4;
      }
      ((int (*)())FUN_00017260)(param_1);
    }
    puVar18 = param_3 + 1;
    uVar19 = (uint)*(ushort *)((int)param_3 + 6);
    puVar13 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 0x19c);
    if (puVar13 == (undefined4 *)0x0) {
      cVar17 = '\0';
      if ((((unsigned char *)0x0000430c)[*(int *)(param_1 + 0x10)] != '\0') &&
         ((psVar14 = (short *)**(undefined4 **)(*(int *)(param_1 + 0x18) + 400),
          *(int *)(psVar14 + 2) == 0 || (cVar17 = '\x01', *psVar14 == -0x7e00)))) goto LAB_00022540;
    }
    else if ((*(int *)((short *)*puVar13 + 2) == 0) || (*(short *)*puVar13 == -0x7e00)) {
LAB_00022540:
      cVar17 = '\0';
    }
    else {
      cVar17 = '\x01';
      if (((puVar13[0xe] != 0) && (uVar9 = *(uint *)(puVar13[0xe] + 0x20), (uVar9 & 0x1000000) != 0)
          ) && ((uVar9 >> 0x17 & 1) != (uint)(byte)((unsigned char *)0x00002b7c)[param_1])) {
        param_3[3] = param_3[3] | 0x1000000;
      }
    }
    if ((*(char *)(param_1 + 0x29dc) == cVar17) && (uVar9 = param_3[3], (uVar9 & 0x5000000) == 0)) {
      bVar3 = false;
      if (uVar19 != 0) goto LAB_00022580;
    }
    else {
      *(char *)(param_1 + 0x29dc) = cVar17;
      uVar19 = 0xffff;
      *puVar18 = *puVar18 | 0xffff;
LAB_00022580:
      _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
      piVar12 = *(int **)(*(int *)(param_1 + 0x18) + 0x19c);
      if (piVar12 == (int *)0x0) {
        if (((((unsigned char *)0x0000430c)[*(int *)(param_1 + 0x10)] != '\0') &&
            (puVar13 = *(undefined4 **)(*(int *)(param_1 + 0x18) + 400),
            puVar13 != (undefined4 *)0x0)) && (psVar14 = (short *)*puVar13, *psVar14 != -0x7e00)) {
          uVar9 = *(uint *)(psVar14 + 4);
          uVar21 = *(uint *)(psVar14 + 6);
          goto LAB_000225e8;
        }
        uVar21 = 0;
        iVar20 = 0;
        iVar22 = 0;
        iVar8 = param_1;
        uVar9 = uVar19;
        do {
          if ((uVar9 & 1) != 0) {
            uVar15 = 0;
            iVar27 = 5;
            do {
              if ((*(uint *)(((unsigned char *)0x000031d4) + iVar20 + *(int *)(param_1 + 0x10)) &
                  1 << (uVar15 & 0x3f)) != 0) {
                uVar15 = *(uint *)(iVar22 + *(int *)(param_1 + 0x18) + uVar15 * 4);
                if ((*(byte *)(uVar15 + 0x39) & 0x87) == 0) {
                  uVar24 = uVar15 & -(uint)*(byte *)(uVar15 + 0x3d);
                }
                else {
                  iVar27 = FUN_00032100(param_1,uVar15);
                  if ((iVar27 == 0) || (uVar24 = uVar15, *(char *)(uVar15 + 0x3d) == '\0')) {
                    uVar24 = 0;
                  }
                }
                uVar11 = *(uint *)(((unsigned char *)0x000026b8) + param_1) & ~(1 << (uVar21 & 0x3f));
                *(uint *)(((unsigned char *)0x000026b8) + param_1) = uVar11;
                *(uint *)(((unsigned char *)0x000026b8) + param_1) =
                     uVar11 | (uint)*(byte *)(uVar15 + 0x44) << (uVar21 & 0x3f);
                goto LAB_00022740;
              }
              uVar15 = uVar15 + 1;
              iVar27 = iVar27 + -1;
            } while (iVar27 != 0);
            uVar24 = 0;
            *(uint *)(((unsigned char *)0x000026b8) + param_1) =
                 *(uint *)(((unsigned char *)0x000026b8) + param_1) & ~(1 << (uVar21 & 0x3f));
LAB_00022740:
            *(uint *)(iVar8 + 0x18c) = uVar24;
          }
          uVar9 = uVar9 >> 1;
          uVar21 = uVar21 + 1;
          iVar22 = iVar22 + 0x14;
          iVar20 = iVar20 + 0x7c;
          iVar8 = iVar8 + 4;
        } while (uVar9 != 0);
      }
      else {
        iVar8 = *piVar12;
        uVar9 = *(uint *)(iVar8 + 8);
        uVar21 = *(uint *)(iVar8 + 0xc);
LAB_000225e8:
        uVar24 = 0;
        iVar20 = 0;
        iVar8 = param_1;
        uVar15 = uVar19;
        do {
          if ((uVar15 & 1) != 0) {
            if ((uVar21 & 0xf) < 5) {
              uVar23 = *(uint *)(iVar20 + *(int *)(param_1 + 0x18) + (uVar21 & 0xf) * 4);
              if ((*(byte *)(uVar23 + 0x39) & 0x87) == 0) {
                uVar11 = uVar23 & -(uint)*(byte *)(uVar23 + 0x3d);
              }
              else {
                iVar22 = FUN_00032100(param_1,uVar23);
                if ((iVar22 == 0) || (uVar11 = uVar23, *(char *)(uVar23 + 0x3d) == '\0')) {
                  uVar11 = 0;
                }
              }
              uVar10 = *(uint *)(((unsigned char *)0x000026b8) + param_1) & ~(1 << (uVar24 & 0x3f));
              *(uint *)(((unsigned char *)0x000026b8) + param_1) = uVar10;
              *(uint *)(((unsigned char *)0x000026b8) + param_1) =
                   uVar10 | (uint)*(byte *)(uVar23 + 0x44) << (uVar24 & 0x3f);
            }
            else {
              uVar11 = 0;
              *(uint *)(((unsigned char *)0x000026b8) + param_1) =
                   *(uint *)(((unsigned char *)0x000026b8) + param_1) & ~(1 << (uVar24 & 0x3f));
            }
            *(uint *)(iVar8 + 0x18c) = uVar11;
          }
          uVar15 = uVar15 >> 1;
          uVar11 = uVar9 << 0x1c;
          uVar9 = uVar9 >> 4;
          uVar24 = uVar24 + 1;
          uVar21 = uVar11 | uVar21 >> 4;
          iVar20 = iVar20 + 0x14;
          iVar8 = iVar8 + 4;
        } while (uVar15 != 0);
      }
      FUN_000a7ee0(param_1,uVar19);
      uVar19 = *(uint *)(((unsigned char *)0x000026b8) + param_1);
      if (uVar19 != 0) {
        iVar8 = 0;
        do {
          iVar20 = 0;
          iVar22 = 5;
          do {
            if ((uVar19 & 1) != 0) {
              *(undefined1 *)(*(int *)(iVar8 + iVar20 + *(int *)(param_1 + 0x18)) + 0x44) = 0;
              uVar19 = *(uint *)(((unsigned char *)0x000026b8) + param_1);
            }
            iVar20 = iVar20 + 4;
            iVar22 = iVar22 + -1;
          } while (iVar22 != 0);
          uVar19 = uVar19 >> 1;
          iVar8 = iVar8 + 0x14;
          *(uint *)(((unsigned char *)0x000026b8) + param_1) = uVar19;
        } while (uVar19 != 0);
        goto LAB_00022cbc;
      }
      uVar9 = param_3[3];
      bVar3 = true;
    }
    puVar25 = param_3 + 3;
    bVar1 = !bVar3;
    if ((uVar9 & 0x5400000) != 0) {
      if ((*(int *)(*(int *)(param_1 + 0x18) + 0x198) != 0) ||
         (bVar26 = false, *(int *)(*(int *)(param_1 + 0x18) + 0x18c) != 0)) {
        bVar26 = true;
      }
      bVar1 = bVar3;
      if (!bVar1) {
        _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
      }
      bVar1 = bVar1 && !bVar3;
      FUN_000095e0(param_1);
      iVar8 = *(int *)(param_1 + 0x1cc);
      if (bVar26 != (iVar8 != 0)) {
        ((unsigned char *)0x000026bd)[param_1] = 1;
        iVar8 = *(int *)(param_1 + 0x1cc);
      }
      if (iVar8 == 0) {
        *(undefined4 *)(param_1 + 0x29e8) = 0;
      }
      if ((*(int *)(param_1 + 0x1d0) == 0) &&
         (*(undefined4 *)(param_1 + 0x29ec) = 0, cVar17 != '\0')) {
        uVar16 = 0;
        *(undefined1 *)(param_1 + 0x2a69) = 1;
        *puVar25 = *puVar25 | 0x10000000;
        *(undefined4 *)(param_1 + 0x29e8) = 0;
        *(undefined4 *)(param_1 + 0x1cc) = 0;
      }
    }
    uVar19 = *puVar25;
    if ((uVar19 & 0x4500000) != 0) {
      if (bVar1) {
        _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
        bVar1 = false;
      }
      FUN_0000b750(param_1);
      uVar19 = *puVar25;
    }
    uVar21 = *puVar18;
    uVar9 = *param_3;
    uVar15 = param_3[4];
    uVar24 = param_3[2] | *(uint *)(((unsigned char *)0x000026c0) + param_1);
    uVar19 = uVar19 | *(uint *)(((unsigned char *)0x000026c4) + param_1);
    if (((uVar24 != 0 || (uVar9 != 0 || uVar21 != 0)) || uVar15 != 0) || (uVar19 & 0xffefffff) != 0)
    {
      param_3[2] = uVar24;
      *puVar25 = uVar19;
      FUN_000a9ac0(param_1 + 0x240,param_3);
    }
    if ((uVar19 & 0x10000000) != *(uint *)(param_1 + 0x29c0) ||
        (uVar19 != 0 || ((uVar24 != 0 || (uVar9 != 0 || uVar21 != 0)) || uVar15 != 0))) {
      FUN_0002c230(param_1 + 0x240,param_3);
    }
    puVar7 = PTR_LAB_001e8980;
    puVar6 = PTR__gldFlush_001e897c;
    puVar5 = PTR__gldFinish_001e8978;
    puVar4 = PTR_FUN_001e8938;
    if ((*(uint *)(((unsigned char *)0x000026c8) + param_1) & 2) != 0) {
      uVar16 = uVar16 | 2;
    }
    if ((*param_3 & 0x80) != 0) {
      if (*(int *)(param_1 + 0x150) == 0) {
        uVar9 = *(uint *)(param_1 + 0x154);
        if ((uVar9 & 0x20) == 0) {
          if ((uVar9 & 0x400) == 0) {
            *(undefined **)(param_2 + 0x60) = ((unsigned char *)0x00022280);
          }
          else {
            *(undefined **)(param_2 + 0x60) = PTR_FUN_001e8934;
          }
          puVar4 = PTR__gldFlush_001e897c;
          *(undefined **)(param_2 + 0x58) = PTR__gldFinish_001e8978;
          *(undefined **)(param_2 + 0x5c) = puVar4;
        }
        else if ((uVar9 & 0x400) == 0) {
          *(undefined **)(param_2 + 0x60) = PTR_FUN_001e8938;
          *(undefined **)(param_2 + 0x58) = puVar7;
          *(undefined **)(param_2 + 0x5c) = puVar4;
        }
        else if ((uVar9 & 0x800) == 0) {
          *(undefined **)(param_2 + 0x58) = PTR__gldFinish_001e8978;
          *(undefined **)(param_2 + 0x5c) = puVar6;
          *(undefined **)(param_2 + 0x60) = PTR_FUN_001e8934;
        }
        else if (*(int *)(((unsigned char *)0x000026a0) + param_1) == 0) {
          ((int (*)())FUN_0001a9d0)(param_1);
          puVar4 = PTR__gldFlush_001e897c;
          *(undefined **)(param_2 + 0x58) = PTR__gldFinish_001e8978;
          *(undefined **)(param_2 + 0x5c) = puVar4;
          *(undefined **)(param_2 + 0x60) = PTR_LAB_001e8948;
        }
        else {
          *(undefined **)(param_2 + 0x58) = PTR_LAB_001e8980;
          *(undefined **)(param_2 + 0x5c) = puVar4;
          *(undefined **)(param_2 + 0x60) = PTR_LAB_001e8948;
        }
      }
      else {
        *(undefined **)(param_2 + 0x60) = ((unsigned char *)0x00022280);
        *(undefined **)(param_2 + 0x58) = puVar5;
        *(undefined **)(param_2 + 0x5c) = PTR__gldFlush_001e897c;
      }
    }
    puVar5 = PTR_DAT_001e8910;
    puVar4 = PTR_LAB_001e88ec;
    if ((*(char *)(param_1 + 0x20) == '\0') || (*(int *)(param_1 + 0x1cc) == 0)) {
      *(undefined **)(param_2 + 0x18) = PTR_DAT_001e8944;
      *(undefined **)(param_2 + 0x1c) = puVar5;
      puVar4 = PTR_DAT_001e88d4;
      *(undefined **)(param_2 + 0x24) = PTR_DAT_001e891c;
      *(undefined **)(param_2 + 0x20) = puVar4;
      puVar4 = PTR_DAT_001e88e0;
      *(undefined **)(param_2 + 0x2c) = PTR_DAT_001e8940;
      *(undefined **)(param_2 + 0x34) = puVar4;
      puVar4 = PTR_DAT_001e88e4;
      *(undefined **)(param_2 + 0x30) = PTR_DAT_001e894c;
      *(undefined **)(param_2 + 0x38) = puVar4;
      puVar4 = PTR_DAT_001e8914;
      *(undefined **)(param_2 + 0x3c) = PTR_DAT_001e893c;
      *(undefined **)(param_2 + 0x28) = puVar4;
      puVar4 = PTR_LAB_001e8990;
      if (*(char *)(param_1 + 0x20) == '\0') {
        *(undefined **)(param_2 + 0x40) = PTR_LAB_001e88f8;
        *(undefined **)(param_2 + 0x44) = puVar4;
        *(undefined **)(param_2 + 0x48) = PTR_LAB_001e895c;
      }
      else {
        *(undefined **)(param_2 + 0x48) = ((unsigned char *)0x00022280);
        *(undefined **)(param_2 + 0x40) = ((unsigned char *)0x00022280);
        *(undefined **)(param_2 + 0x44) = ((unsigned char *)0x00022280);
      }
    }
    else {
      *(undefined **)(param_2 + 0x18) = PTR_LAB_001e8918;
      *(undefined **)(param_2 + 0x1c) = puVar4;
      puVar4 = PTR_LAB_001e8954;
      *(undefined **)(param_2 + 0x24) = PTR_LAB_001e8908;
      *(undefined **)(param_2 + 0x28) = puVar4;
      puVar4 = PTR_LAB_001e88f4;
      *(undefined **)(param_2 + 0x20) = PTR_FUN_001e8930;
      *(undefined **)(param_2 + 0x2c) = puVar4;
      puVar4 = PTR_LAB_001e8924;
      *(undefined **)(param_2 + 0x34) = PTR_LAB_001e8960;
      *(undefined **)(param_2 + 0x30) = puVar4;
      puVar4 = PTR_LAB_001e8968;
      *(undefined **)(param_2 + 0x38) = PTR_LAB_001e892c;
      *(undefined **)(param_2 + 0x3c) = puVar4;
    }
    uVar9 = *(uint *)(((unsigned char *)0x000026c8) + param_1);
    *(uint *)(param_1 + 0x29c0) = uVar19 & 0x10000000;
    ((unsigned char *)0x00002b7d)[param_1] = 0;
    ((unsigned char *)0x000026bd)[param_1] = 0;
    *(undefined1 *)(param_1 + 0x2a43) = 0;
    ((unsigned char *)0x00002675)[param_1] = 0;
    *(uint *)(((unsigned char *)0x000026c8) + param_1) = uVar9 & 0xfffffff9;
    if ((*(int *)(param_1 + 0x150) != 0) &&
       (iVar8 = *(int *)(*(int *)(*(int *)(param_1 + 0x150) + 4) + 0x10), iVar8 != 0)) {
      *(undefined1 *)(iVar8 + 200) = 1;
    }
    if (!bVar1) {
      _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    }
    if (*(char *)(param_1 + 0x20) != '\0') {
      uVar16 = uVar16 | 1;
    }
  }
  else {
    bVar2 = *(byte *)(iVar8 + 0x38);
    if (((((unsigned char *)0x00002d84)[*(int *)(param_1 + 0x10)] == '\0') ||
        ((*(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x18) & 0x4000) != 0)) &&
       ((((unsigned char *)0x00002e0a)[*(int *)(param_1 + 0x10)] == '\0' ||
        ((*(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x18) & 0x8000) != 0))))
    goto LAB_00022438;
LAB_00022cbc:
    uVar16 = 0;
  }
  return uVar16;
}

/* _gldInitDispatch @ 0x22ce0 (456 bytes) */
int _gldInitDispatch(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  undefined4 *param_3;
{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  iVar7 = 0;
  uVar5 = *(undefined4 *)(param_1 + 0x108);
  uVar4 = *(undefined4 *)(param_1 + 0x104);
  uVar6 = *(undefined4 *)(param_1 + 0x110);
  param_3[2] = *(undefined4 *)(param_1 + 0x10c);
  param_3[1] = uVar5;
  *param_3 = uVar4;
  param_3[3] = uVar6;
  local_38 = DAT_001aa4b0;
  local_34 = DAT_001aa4b4;
  local_30 = DAT_001aa4b8;
  uVar4 = *(undefined4 *)(param_1 + 0x118);
  local_2c = DAT_001aa4bc;
  local_28 = DAT_001aa4c0;
  param_3[4] = *(undefined4 *)(param_1 + 0x114);
  param_3[5] = uVar4;
  *(undefined4 **)(param_1 + 0x1c) = param_2;
  do {
    FUN_000a82c0(param_1,iVar7);
    puVar2 = PTR_DAT_001e8950;
    bVar1 = iVar7 != 0xf;
    iVar7 = iVar7 + 1;
  } while (bVar1);
  param_2[5] = PTR_DAT_001e88dc;
  *param_2 = puVar2;
  puVar2 = PTR_LAB_001e898c;
  param_2[4] = PTR_DAT_001e8988;
  param_2[2] = puVar2;
  puVar2 = PTR_FUN_001e8958;
  param_2[3] = PTR_FUN_001e8900;
  param_2[1] = puVar2;
  puVar2 = PTR_DAT_001e890c;
  param_2[0x19] = PTR_LAB_001e8964;
  param_2[0x1d] = puVar2;
  puVar2 = PTR_LAB_001e88f0;
  param_2[0x1e] = PTR_DAT_001e88fc;
  param_2[0x1f] = puVar2;
  puVar3 = PTR_LAB_001e8970;
  puVar2 = PTR_LAB_001e8920;
  if (((unsigned char *)0x00002b82)[param_1] == '\0') {
    param_2[0x14] = PTR_LAB_001e88e8;
    param_2[0x15] = puVar2;
  }
  else {
    param_2[0x14] = PTR_LAB_001e8974;
    param_2[0x15] = puVar3;
  }
  puVar2 = PTR_DAT_001e8928;
  param_2[0x1c] = PTR_DAT_001e8984;
  param_2[0x13] = puVar2;
  puVar2 = PTR_LAB_001e8904;
  param_2[0x1a] = PTR_LAB_001e896c;
  param_2[0x1b] = puVar2;
  param_2[0x20] = PTR_LAB_001e88d8;
  ((int (*)())_gldUpdateDispatch)(param_1,param_2,&local_38);
  return;
}

/* FUN_00022eb0 @ 0x22eb0 (536 bytes) */
int FUN_00022eb0(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = param_1 + 0x240;
  FUN_000a5ec0(iVar4);
  bVar1 = param_2 == (undefined4 *)0x0;
  if (bVar1) {
    param_2 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar4,0x23);
    *(undefined4 **)(param_1 + 0x298c) = param_2;
  }
  uVar2 = *(uint *)(param_1 + 0x1b70);
  if ((uVar2 & 0x100) != 0) {
    *param_2 = ((unsigned char *)0x00001393);
    param_2[1] = 10;
    param_2 = param_2 + 2;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x2000000) != 0) {
    *param_2 = ((unsigned char *)0x000013c6);
    param_2[1] = 3;
    param_2 = param_2 + 2;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x200) != 0) {
    *param_2 = ((unsigned char *)0x000012f5);
    param_2[1] = *(undefined4 *)(param_1 + 0x1c8c);
    param_2 = param_2 + 2;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x80000) != 0) {
    *param_2 = ((unsigned char *)0x00001008);
    uVar3 = *(undefined4 *)(param_1 + 0x1ca0);
    param_2[2] = ((unsigned char *)0x00001004);
    param_2[1] = uVar3;
    uVar3 = *(undefined4 *)(param_1 + 0x1ca8);
    param_2[4] = ((unsigned char *)0x00001005);
    param_2[3] = uVar3;
    uVar3 = *(undefined4 *)(param_1 + 0x1cac);
    param_2[6] = ((unsigned char *)0x000010fa);
    param_2[5] = uVar3;
    param_2[7] = *(undefined4 *)(((unsigned char *)0x00001da0) + param_1);
    param_2 = param_2 + 8;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x10000000) != 0) {
    *param_2 = ((unsigned char *)0x000413de);
    param_2[1] = *(undefined4 *)(param_1 + 0x25a0);
    param_2[2] = *(undefined4 *)(param_1 + 0x25a4);
    param_2[3] = *(undefined4 *)(param_1 + 0x25a8);
    param_2[4] = *(undefined4 *)(param_1 + 0x25ac);
    uVar3 = *(undefined4 *)(param_1 + 0x25b0);
    param_2[6] = 0x313e9;
    param_2[5] = uVar3;
    param_2[7] = *(undefined4 *)(param_1 + 0x25b4);
    param_2[8] = *(undefined4 *)(param_1 + 0x25b8);
    param_2[9] = *(undefined4 *)(param_1 + 0x25bc);
    param_2[10] = *(undefined4 *)(param_1 + 0x25c0);
    param_2 = param_2 + 0xb;
    uVar2 = *(uint *)(param_1 + 0x1b70);
  }
  if ((uVar2 & 0x20000000) != 0) {
    *param_2 = ((unsigned char *)0x000813ad);
    param_2[1] = *(undefined4 *)(param_1 + 0x25c4);
    param_2[2] = *(undefined4 *)(param_1 + 0x25c8);
    param_2[3] = *(undefined4 *)(param_1 + 0x25cc);
    param_2[4] = *(undefined4 *)(param_1 + 0x25d0);
    param_2[5] = *(undefined4 *)(param_1 + 0x25d4);
    param_2[6] = *(undefined4 *)(param_1 + 0x25d8);
    param_2[7] = *(undefined4 *)(param_1 + 0x25dc);
    param_2[8] = *(undefined4 *)(param_1 + 0x25e0);
    param_2[9] = *(undefined4 *)(param_1 + 0x25e4);
    param_2 = param_2 + 10;
  }
  if (bVar1) {
    *(undefined4 **)(param_1 + 0x298c) = param_2;
    (**(code **)(param_1 + 0x299c))(iVar4,param_2);
  }
  return param_2;
}

/* FUN_000230d0 @ 0x230d0 (1544 bytes) */
int FUN_000230d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  undefined4 param_7;
  int param_8;
{
  bool bVar1;
  undefined *puVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_1 + 0x240;
  if (*(char *)(param_1 + 0x2a5e) != '\0') {
    if ((*(int *)(param_1 + 0x154) < 0) || (param_4 == 0)) {
      param_4 = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x2a5e) = 0;
    }
    bVar1 = param_2 == (undefined4 *)0x0;
    puVar5 = param_2;
    if (bVar1) {
      puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar7,500);
      *(undefined4 **)(param_1 + 0x298c) = puVar5;
    }
    puVar3 = *(uint **)(param_1 + 0x1d8);
    *puVar3 = (int)puVar5 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x1d8) = puVar5;
    puVar5[2] = param_3;
    *puVar5 = 0x30000000;
    puVar5[1] = 0xfa;
    puVar5[3] = param_4;
    puVar5[4] = param_5;
    if (((unsigned char *)0x00002b7c)[param_1] != '\0') {
      param_6 = (*(int *)(param_1 + 0x160) - param_8) - param_6;
    }
    puVar5[5] = param_6;
    puVar5[6] = param_7;
    puVar5[7] = param_8;
    puVar3 = *(uint **)(param_1 + 0x1d8);
    *puVar3 = (int)(puVar5 + 0xfa) - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x1d8) = puVar5 + 0xfa;
    puVar5[0xfb] = 0;
    puVar5[0xfa] = 0x33000000;
    puVar5[0xfc] = ((unsigned char *)0x00001393);
    puVar5[0xfd] = 10;
    puVar5[0xfe] = ((unsigned char *)0x000013c6);
    puVar5[0xff] = 3;
    puVar5[0x100] = 0x5c8;
    puVar5[0x101] = 0x20000;
    puVar5[0x102] = ((unsigned char *)0x000010ea);
    uVar4 = *(undefined4 *)(param_1 + 0x1cfc);
    puVar5[0x104] = ((unsigned char *)0x000010fa);
    puVar5[0x103] = uVar4;
    uVar4 = *(undefined4 *)(((unsigned char *)0x00001da0) + param_1);
    puVar5[0x106] = 0xc0001000;
    puVar5[0x108] = 0x11004;
    puVar5[0x105] = uVar4;
    puVar5[0x109] = *(undefined4 *)(param_1 + 0x1ca8);
    uVar4 = *(undefined4 *)(param_1 + 0x1cac);
    puVar5[0x10b] = ((unsigned char *)0x00001008);
    puVar5[0x10a] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1ca0);
    puVar5[0x10d] = ((unsigned char *)0x000010e9);
    puVar5[0x10c] = uVar4;
    puVar5[0x10e] = *(undefined4 *)(param_1 + 0x1d20);
    puVar5[0x10f] = ((unsigned char *)0x000013c7);
    uVar4 = *(undefined4 *)(param_1 + 0x1cf0);
    puVar5[0x111] = ((unsigned char *)0x000013c1);
    puVar5[0x110] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1ce4);
    puVar5[0x113] = 0x850;
    puVar5[0x112] = uVar4;
    uVar4 = *(undefined4 *)(((unsigned char *)0x00001dc0) + param_1);
    puVar5[0x115] = 0x887;
    puVar5[0x114] = uVar4;
    uVar4 = *(undefined4 *)(((unsigned char *)0x00001db4) + param_1);
    puVar5[0x1b7] = 0x82c;
    puVar5[0x116] = uVar4;
    uVar4 = *(undefined4 *)(((unsigned char *)0x00001dc4) + param_1);
    puVar5[0x117] = ((unsigned char *)0x000010ae);
    puVar5[0x1b8] = uVar4;
    uVar4 = *(undefined4 *)(((unsigned char *)0x00001d70) + param_1);
    puVar5[0x119] = ((unsigned char *)0x00001394);
    puVar5[0x118] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1d30);
    puVar5[0x11b] = ((unsigned char *)0x00001380);
    puVar5[0x11d] = ((unsigned char *)0x00001002);
    puVar5[0x11c] = 0;
    puVar5[0x11a] = uVar4;
    puVar5[0x11e] = *(undefined4 *)(((unsigned char *)0x00001d90) + param_1);
    uVar4 = *(undefined4 *)(((unsigned char *)0x00001d90) + param_1);
    puVar5[0x11f] = 0x824;
    puVar5[0x11e] = uVar4;
    uVar4 = *(undefined4 *)(((unsigned char *)0x00001ddc) + param_1);
    puVar5[0x121] = 0x825;
    puVar5[0x120] = uVar4;
    puVar5[0x122] = *(undefined4 *)(((unsigned char *)0x00001de0) + param_1);
    puVar5[0x123] = 0x82d;
    puVar2 = PTR_DAT_001e88c8;
    uVar4 = *(undefined4 *)(((unsigned char *)0x000026cc) + param_1);
    puVar5[0x125] = 0x854;
    puVar5[0x124] = uVar4;
    uVar4 = **(undefined4 **)(((unsigned char *)0x00002680) + param_1);
    puVar5[0x127] = 0x878;
    puVar5[0x126] = uVar4;
    uVar4 = **(undefined4 **)(((unsigned char *)0x00002684) + param_1);
    puVar5[0x129] = ((unsigned char *)0x000013c0);
    puVar5[0x128] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1ce0);
    puVar5[299] = ((unsigned char *)0x000012f0);
    puVar5[0x12a] = uVar4;
    uVar6 = *(uint *)(param_1 + 0x1d2c);
    puVar5[300] = uVar6;
    if ((*(uint *)(puVar2 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
      puVar5[300] = uVar6 & 0xfffffffe;
    }
    puVar5[0x12d] = ((unsigned char *)0x000012f5);
    uVar6 = *(uint *)(param_1 + 0x1c8c);
    puVar5[0x12e] = uVar6;
    if ((*(uint *)(puVar2 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
      puVar5[0x12e] = uVar6 & 0xfffff7ff;
    }
    puVar5[0x12f] = ((unsigned char *)0x000010a2);
    uVar4 = *(undefined4 *)(((unsigned char *)0x00001d7c) + param_1);
    puVar5[0x131] = ((unsigned char *)0x00001381);
    puVar5[0x130] = uVar4;
    uVar6 = *(uint *)(param_1 + 0x1cc0);
    puVar5[0x132] = uVar6;
    if ((*(uint *)(puVar2 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x4000) == 0) {
      puVar5[0x132] = uVar6 & 0xfffffffc;
    }
    puVar5[0x133] = ((unsigned char *)0x0000109e);
    param_2 = puVar5 + 0x1b9;
    uVar4 = *(undefined4 *)(((unsigned char *)0x00001d6c) + param_1);
    puVar5[0x135] = ((unsigned char *)0x00001096);
    puVar5[0x134] = uVar4;
    uVar4 = *(undefined4 *)(((unsigned char *)0x00001df8) + param_1);
    puVar5[0x137] = ((unsigned char *)0x00001041);
    puVar5[0x134] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x29f0);
    puVar5[0x139] = ((unsigned char *)0x00001046);
    puVar5[0x138] = uVar4;
    uVar4 = *(undefined4 *)(((unsigned char *)0x00001dfc) + param_1);
    puVar5[0x13b] = ((unsigned char *)0x00001094);
    puVar5[0x153] = ((unsigned char *)0x00001095);
    puVar5[0x13d] = ((unsigned char *)0x00001095);
    puVar5[0x179] = ((unsigned char *)0x00001180);
    puVar5[0x13f] = ((unsigned char *)0x00001095);
    puVar5[0x141] = ((unsigned char *)0x00001095);
    puVar5[0x143] = ((unsigned char *)0x00001095);
    puVar5[0x13a] = uVar4;
    puVar5[0x145] = ((unsigned char *)0x00001095);
    puVar5[0x147] = ((unsigned char *)0x00001095);
    puVar5[0x149] = ((unsigned char *)0x00001095);
    puVar5[0x14b] = ((unsigned char *)0x00001095);
    puVar5[0x14d] = ((unsigned char *)0x00001095);
    puVar5[0x14f] = ((unsigned char *)0x00001095);
    puVar5[0x151] = ((unsigned char *)0x00001095);
    puVar5[0x155] = 0xc0221000;
    puVar5[0x13c] = 0;
    puVar5[0x17a] = 2;
    puVar5[0x17b] = ((unsigned char *)0x00001189);
    puVar5[0x17d] = ((unsigned char *)0x00001181);
    puVar5[0x17f] = ((unsigned char *)0x0000118d);
    puVar5[0x181] = ((unsigned char *)0x0000118e);
    puVar5[0x183] = ((unsigned char *)0x0000118c);
    puVar5[0x185] = ((unsigned char *)0x000011a9);
    uVar4 = *(undefined4 *)(param_1 + 0x257c);
    puVar5[0x187] = ((unsigned char *)0x000011aa);
    puVar5[0x186] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x2580);
    puVar5[0x189] = ((unsigned char *)0x000011ab);
    puVar5[0x188] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x2584);
    puVar5[0x18b] = ((unsigned char *)0x000011ac);
    puVar5[0x18a] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x2588);
    puVar5[0x18d] = ((unsigned char *)0x000010c0);
    puVar5[0x18c] = uVar4;
    uVar4 = *(undefined4 *)(((unsigned char *)0x0000216c) + param_1);
    puVar5[399] = ((unsigned char *)0x000010c1);
    puVar5[0x191] = ((unsigned char *)0x000010c8);
    puVar5[0x193] = ((unsigned char *)0x0000101d);
    puVar5[0x18e] = uVar4;
    uVar4 = *(undefined4 *)(((unsigned char *)0x00002128) + param_1);
    puVar5[0x195] = ((unsigned char *)0x0000138a);
    puVar5[0x197] = ((unsigned char *)0x0000138e);
    puVar5[0x19c] = 0;
    puVar5[0x199] = ((unsigned char *)0x00001040);
    puVar5[0x196] = 0;
    puVar5[0x198] = 0;
    puVar5[0x19a] = 0;
    puVar5[0x194] = uVar4;
    puVar5[0x19b] = ((unsigned char *)0x00001150);
    puVar5[0x19d] = ((unsigned char *)0x00001100);
    uVar4 = *(undefined4 *)(param_1 + 0x1f1c);
    puVar5[0x19f] = ((unsigned char *)0x00001110);
    puVar5[0x19e] = uVar4;
    puVar5[0x1a0] = *(undefined4 *)(((unsigned char *)0x00001f5c) + param_1);
    puVar5[0x1a1] = ((unsigned char *)0x00001120);
    uVar4 = *(undefined4 *)(param_1 + 0x1f9c);
    puVar5[0x1a3] = ((unsigned char *)0x00001130);
    puVar5[0x1a2] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1fdc);
    puVar5[0x1a5] = ((unsigned char *)0x00001140);
    puVar5[0x1a4] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x201c);
    puVar5[0x1a7] = ((unsigned char *)0x000010f4);
    puVar5[0x1a8] = 0xaaaa;
    puVar5[0x1a9] = ((unsigned char *)0x00001383);
    puVar5[0x1a6] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1d34);
    puVar5[0x1ab] = ((unsigned char *)0x00001386);
    puVar5[0x1aa] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1d38);
    puVar5[0x1ad] = 0x110f8;
    puVar5[0x1ac] = uVar4;
    puVar5[0x1ae] = *(undefined4 *)(((unsigned char *)0x00001d98) + param_1);
    uVar4 = *(undefined4 *)(param_1 + 0x1d50);
    puVar5[0x1b0] = ((unsigned char *)0x00001087);
    puVar5[0x1af] = uVar4;
    uVar4 = *(undefined4 *)(param_1 + 0x1f0c);
    puVar5[0x1b2] = 0x31080;
    puVar5[0x1b1] = uVar4;
    puVar5[0x1b3] = *(undefined4 *)(param_1 + 0x1efc);
    puVar5[0x1b4] = *(undefined4 *)(param_1 + 0x1f04);
    puVar5[0x1b5] = *(undefined4 *)(param_1 + 0x1f00);
    puVar5[0x1b6] = *(undefined4 *)(param_1 + 0x1f08);
    FUN_0004c100(puVar5 + 0xfc,iVar7);
    if (bVar1) {
      *(undefined4 **)(param_1 + 0x298c) = param_2;
      (**(code **)(param_1 + 0x299c))(iVar7,param_2);
    }
  }
  return param_2;
}

/* FUN_00023700 @ 0x23700 (360 bytes) */
int FUN_00023700(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 *param_3;
{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  
  puVar5 = param_3 + 5;
  *param_3 = 0x308c8;
  param_3[1] = param_2[0xc];
  param_3[2] = param_2[0xd];
  param_3[3] = param_2[0xe];
  param_3[4] = param_2[0xf];
  if ((*(uint *)(param_1 + 0x1ca0) & 8) != 0) {
    if (((unsigned char *)0x00002e0a)[*(int *)(*(int *)(param_1 + 4) + 0x10)] == '\0') {
      puVar5 = param_3 + 9;
      param_3[5] = ((unsigned char *)0x000208cc);
      param_3[6] = param_2[0x14];
      param_3[7] = param_2[0x15];
      param_3[8] = param_2[0x16];
    }
    else {
      puVar5 = param_3 + 10;
      param_3[5] = 0x308cc;
      param_3[6] = param_2[0x14];
      param_3[7] = param_2[0x15];
      param_3[8] = param_2[0x16];
      param_3[9] = param_2[0x13];
    }
  }
  uVar4 = 10;
  uVar2 = 0x8e8;
  iVar6 = 8;
  puVar3 = param_2;
  do {
    if ((1 << (uVar4 & 0x3f) & *(uint *)(param_1 + 0x1ca0)) != 0) {
      *puVar5 = uVar2 | 0x30000;
      puVar5[1] = puVar3[0x20];
      puVar5[2] = puVar3[0x21];
      puVar5[3] = puVar3[0x22];
      puVar5[4] = puVar3[0x23];
      puVar5 = puVar5 + 5;
    }
    uVar4 = uVar4 + 1;
    uVar2 = uVar2 + 4;
    puVar3 = puVar3 + 4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *puVar5 = 0x917;
  bVar1 = *(byte *)(param_2 + 0x1f);
  puVar5[2] = (uint)FUN_000308c0;
  puVar5[1] = -(uint)bVar1 >> 0x1f;
  puVar5[3] = *param_2;
  puVar5[4] = param_2[1];
  puVar5[5] = param_2[2];
  puVar5[6] = param_2[3];
  return puVar5 + 7;
}

/* FUN_00024fb0 @ 0x24fb0 (16 bytes) */
int FUN_00024fb0(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x30) = param_1 + 0x2c;
  *(int *)(param_1 + 0x2c) = param_1 + 0x2c;
  return;
}

/* FUN_00024fc0 @ 0x24fc0 (4 bytes) */
int FUN_00024fc0()
{
  return;
}

/* FUN_00024fd0 @ 0x24fd0 (4 bytes) */
int FUN_00024fd0()
{
  return;
}

/* FUN_00024fe0 @ 0x24fe0 (2908 bytes) */
int FUN_00024fe0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  float *param_3;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  dword *pdVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  float *pfVar15;
  dword *pdVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  dword *pdVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int *piVar25;
  uint *puVar26;
  double dVar27;
  undefined8 uVar28;
  float local_90;
  float local_8c;
  float local_88[0];
  float local_84 [3];
  undefined4 local_78;
  float fStack_74;
  undefined4 local_70;
  float fStack_6c;
  undefined4 local_68;
  float fStack_64;
  undefined4 local_60;
  float fStack_5c;
  
  uVar28 = FUN_001a3264();
  iVar6 = *(int *)((int)((ulonglong)uVar28 >> 0x20) + 0x18);
  piVar25 = *(int **)(iVar6 + 0x19c);
  bVar1 = piVar25 == (int *)0x0;
  if (bVar1) {
    piVar25 = *(int **)(iVar6 + 400);
  }
  iVar6 = piVar25[0xd];
  if (((iVar6 == 0) && (iVar6 = piVar25[0xc], iVar6 == 0)) && (iVar6 = piVar25[0xb], iVar6 == 0)) {
    iVar18 = *piVar25;
    iVar6 = *(int *)(iVar18 + 4);
  }
  else {
    iVar18 = *piVar25;
  }
  iVar7 = *(int *)(iVar6 + 0x6c);
  iVar23 = *(int *)(iVar18 + 0x18);
  puVar26 = (uint *)(iVar6 + *(int *)(iVar6 + 0x2c) * 8);
  iVar18 = *(int *)(iVar6 + 0x28);
  if ((int)uVar28 < *(int *)(iVar6 + 0x28)) {
    iVar18 = (int)uVar28;
  }
  if (iVar18 < 1) {
LAB_00025b04:
    fVar3 = FLOAT_001aa13c;
    fVar2 = FLOAT_001aa138;
    fVar5 = FLOAT_001aa134;
    iVar6 = piVar25[0xe];
    if (iVar6 != 0) {
      uVar14 = *(uint *)(iVar6 + 0x20);
      if ((uVar14 & 0x4000000) != 0) {
        *param_3 = FLOAT_001aa130;
        param_3[1] = fVar5;
        param_3[2] = fVar2;
        param_3[3] = fVar3;
        param_3 = param_3 + 4;
        uVar14 = *(uint *)(iVar6 + 0x20);
      }
      if ((uVar14 & 0x2000000) != 0) {
        *param_3 = *(float *)(((unsigned char *)0x00002de0) + *(int *)(param_1 + 0x10));
        param_3[1] = *(float *)(((unsigned char *)0x00002de4) + *(int *)(param_1 + 0x10));
        param_3[2] = *(float *)(((unsigned char *)0x00002de8) + *(int *)(param_1 + 0x10));
        param_3[4] = -*(float *)(((unsigned char *)0x00002dfc) + *(int *)(param_1 + 0x10));
        fVar5 = FLOAT_001aa140;
        param_3[5] = *(float *)(((unsigned char *)0x00002df8) + *(int *)(param_1 + 0x10)) *
                     *(float *)(((unsigned char *)0x00002dfc) + *(int *)(param_1 + 0x10));
        fVar2 = FLOAT_001aa144;
        param_3[6] = *(float *)(((unsigned char *)0x00002df0) + *(int *)(param_1 + 0x10)) * fVar5;
        param_3[7] = *(float *)(((unsigned char *)0x00002df0) + *(int *)(param_1 + 0x10)) * fVar2;
      }
    }
    return;
  }
  iVar24 = 0;
LAB_00025090:
  dVar27 = DOUBLE_001aa1e0;
  fVar5 = FLOAT_001aa0e8;
  uVar14 = *puVar26;
  uVar19 = uVar14 & 0x1f0000;
  if (uVar19 == 0) goto LAB_00025af0;
  if (uVar19 == 0x110000) {
    pfVar15 = (float *)(iVar6 + iVar7 * 8 + (uint)(ushort)*puVar26 * 0x10);
LAB_0002546c:
    if ((bVar1) || ((uVar14 & 0x1c000000) == 0x4000000)) {
      *param_3 = *pfVar15;
      param_3[1] = pfVar15[1];
      param_3[2] = pfVar15[2];
      param_3[3] = pfVar15[3];
    }
    else if ((uVar14 & 0x1c000000) == 0xc000000) {
      local_78 = 0x43300000;
      fStack_74 = -*pfVar15;
      *param_3 = (float)((double)CONCAT44(0x43300000,-*pfVar15) - DOUBLE_001aa1e0);
      local_70 = 0x43300000;
      fStack_6c = -pfVar15[1];
      param_3[1] = (float)((double)CONCAT44(0x43300000,-pfVar15[1]) - dVar27);
      local_68 = 0x43300000;
      fStack_64 = -pfVar15[2];
      param_3[2] = (float)((double)CONCAT44(0x43300000,-pfVar15[2]) - dVar27);
      local_60 = 0x43300000;
      fStack_5c = -pfVar15[3];
      param_3[3] = (float)((double)CONCAT44(0x43300000,-pfVar15[3]) - dVar27);
    }
    else {
      if (*pfVar15 == 0.0) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = 1.0;
      }
      *param_3 = fVar5;
      if (pfVar15[1] == 0.0) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = 1.0;
      }
      param_3[1] = fVar5;
      if (pfVar15[2] == 0.0) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = 1.0;
      }
      param_3[2] = fVar5;
      if (pfVar15[3] == 0.0) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = 1.0;
      }
      param_3[3] = fVar5;
    }
    goto LAB_00025af0;
  }
  if (uVar19 == 0x10000) {
    pfVar15 = (float *)(iVar23 + (uint)(ushort)*puVar26 * 0x10);
    goto LAB_0002546c;
  }
  if (uVar19 == 0x20000) {
    iVar22 = (uint)(ushort)*puVar26 * 0x10;
    iVar10 = iVar22 + *(int *)(((unsigned char *)0x00004310) + *(int *)(param_1 + 0x10));
    *param_3 = *(float *)(iVar22 + *(int *)(((unsigned char *)0x00004310) + *(int *)(param_1 + 0x10)));
    param_3[1] = *(float *)(iVar10 + 4);
    param_3[2] = *(float *)(iVar10 + 8);
    param_3[3] = *(float *)(iVar10 + 0xc);
    goto LAB_00025af0;
  }
  if (uVar19 == 0x100000) {
    uVar19 = uVar14 >> 0xc & 3;
    uVar21 = uVar14 & 0xff;
    switch(uVar14 >> 8 & 7) {
    default:
      iVar22 = 0;
      break;
    case 1:
      iVar22 = 0xc0;
      break;
    case 2:
      iVar22 = 0x80;
      break;
    case 3:
      iVar22 = (uVar21 + 4) * 0x40;
      break;
    case 4:
      iVar22 = (uVar21 + 0x10) * 0x40;
      break;
    case 5:
      iVar22 = (uVar21 + 8) * 0x40;
    }
    uVar14 = uVar14 >> 0xe & 3;
    iVar10 = *(int *)(param_1 + 0x10) + 0x1860 + iVar22;
    if ((1 < uVar14) && (iVar10 = iVar22 + *(int *)(param_1 + 0x10) + 0x1e60, 3 < uVar14)) {
      iVar10 = 0;
    }
    if (uVar14 < 3) {
      if (uVar14 == 0) {
LAB_000256f4:
        iVar22 = uVar19 * 4;
        iVar11 = iVar10 + iVar22;
        local_90 = *(float *)(iVar10 + iVar22);
        local_8c = *(float *)(iVar11 + 0x10);
        local_88[0] = *(float *)(iVar11 + 0x20);
        local_84[0] = *(float *)(iVar11 + 0x30);
      }
      else {
        iVar22 = uVar19 * 0x10;
        iVar11 = iVar10 + iVar22;
        local_90 = *(float *)(iVar10 + iVar22);
        local_8c = *(float *)(iVar11 + 4);
        local_88[0] = *(float *)(iVar11 + 8);
        local_84[0] = *(float *)(iVar11 + 0xc);
      }
    }
    else if (uVar14 == 3) goto LAB_000256f4;
    goto LAB_00025ac8;
  }
  switch(uVar14 >> 0x10 & 0x1f) {
  case 0:
    pdVar20 = (dword *)&local_8c;
    pdVar9 = (dword *)&local_88;
    pdVar16 = (dword *)local_84;
    pfVar15 = &local_90;
    break;
  default:
    goto switchD_00025774_caseD_1;
  case 2:
    pfVar15 = (float *)((uVar14 & 0xffff) * 0x10 +
                       *(int *)(((unsigned char *)0x00004308) + *(int *)(param_1 + 0x10)));
    pdVar20 = (dword *)(pfVar15 + 1);
    pdVar9 = (dword *)(pfVar15 + 2);
    pdVar16 = (dword *)(pfVar15 + 3);
    break;
  case 3:
    uVar19 = uVar14 & 0xff;
    switch(uVar14 >> 8 & 0xf) {
    case 0:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x24c0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 1:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x24d0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 2:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x24e0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 3:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x24f0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 4:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x2500 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 5:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x2510 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 6:
      iVar22 = uVar19 * 0x80 + *(int *)(param_1 + 0x10);
      fVar2 = *(float *)(iVar22 + 0x24f4);
      fVar3 = *(float *)(iVar22 + 0x24f0);
      fVar4 = *(float *)(iVar22 + 0x24f8) + FLOAT_001aa0e8;
      dVar27 = (double)_sqrt((double)(fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2));
      local_84[0] = fVar5;
      fVar5 = (float)(DOUBLE_001aa200 / dVar27);
      local_88[0] = fVar4 * fVar5;
      local_90 = fVar3 * fVar5;
      local_8c = fVar2 * fVar5;
      goto LAB_00025ac8;
    case 7:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x2530 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    default:
      goto switchD_00025774_caseD_1;
    }
    break;
  case 4:
    uVar19 = uVar14 >> 9 & 3;
    iVar12 = *(int *)(param_1 + 0x10) + 0x24c0;
    iVar22 = (uVar14 & 0xff) * 0x80;
    iVar10 = (uVar14 >> 8 & 1) * 0x240;
    iVar11 = *(int *)(param_1 + 0x10) + 0x28c0;
    iVar17 = iVar12 + iVar22;
    iVar13 = iVar11 + iVar10;
    if (uVar19 == 1) {
      local_90 = *(float *)(iVar17 + 0x10) * *(float *)(iVar13 + 0x10);
      local_8c = *(float *)(iVar17 + 0x14) * *(float *)(iVar13 + 0x14);
      local_88[0] = *(float *)(iVar17 + 0x18) * *(float *)(iVar13 + 0x18);
      local_84[0] = *(float *)(iVar13 + 0x1c);
    }
    else if (uVar19 == 2) {
      local_90 = *(float *)(iVar17 + 0x20) * *(float *)(iVar13 + 0x20);
      local_8c = *(float *)(iVar17 + 0x24) * *(float *)(iVar13 + 0x24);
      local_88[0] = *(float *)(iVar17 + 0x28) * *(float *)(iVar13 + 0x28);
      local_84[0] = *(float *)(iVar13 + 0x2c);
    }
    else {
      if (uVar19 != 0) goto switchD_00025774_caseD_1;
      local_90 = *(float *)(iVar12 + iVar22) * *(float *)(iVar11 + iVar10);
      local_8c = *(float *)(iVar17 + 4) * *(float *)(iVar13 + 4);
      local_88[0] = *(float *)(iVar17 + 8) * *(float *)(iVar13 + 8);
      local_84[0] = *(float *)(iVar13 + 0xc);
    }
    goto LAB_00025ac8;
  case 5:
    uVar19 = uVar14 & 1;
    switch(uVar14 >> 1 & 7) {
    case 0:
      pfVar15 = (float *)(uVar19 * 0x240 + 0x28c0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 1:
      pfVar15 = (float *)(uVar19 * 0x240 + 0x28d0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 2:
      pfVar15 = (float *)(uVar19 * 0x240 + 0x28e0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 3:
      pfVar15 = (float *)(uVar19 * 0x240 + 0x28f0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 4:
      pfVar15 = (float *)(uVar19 * 0x240 + 0x2900 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 5:
      iVar22 = *(int *)(param_1 + 0x10);
      iVar10 = iVar22 + 0x28c0 + uVar19 * 0x240;
      local_90 = *(float *)(iVar22 + 0x24b0) * *(float *)(iVar22 + 0x28c0 + uVar19 * 0x240) +
                 *(float *)(iVar10 + 0x30);
      local_8c = *(float *)(iVar22 + 0x24b4) * *(float *)(iVar10 + 4) + *(float *)(iVar10 + 0x34);
      local_88[0] = *(float *)(iVar22 + 0x24b8) * *(float *)(iVar10 + 8) + *(float *)(iVar10 + 0x38);
      local_84[0] = *(float *)(iVar10 + 0x1c);
      goto LAB_00025ac8;
    default:
      goto switchD_00025774_caseD_1;
    }
    break;
  case 6:
    iVar22 = *(int *)(param_1 + 0x10);
    pdVar16 = (dword *)(iVar22 + 0x24bc);
    pfVar15 = (float *)(iVar22 + 0x24b0);
    pdVar20 = (dword *)(iVar22 + 0x24b4);
    pdVar9 = (dword *)(iVar22 + 0x24b8);
    break;
  case 7:
    uVar19 = uVar14 >> 5 & 7;
    uVar14 = uVar14 & 0x1f;
    if (uVar19 == 1) {
      iVar22 = *(int *)(param_1 + 0x10);
      puVar8 = ((unsigned char *)0x000039a0) + uVar14 * 0x94;
LAB_00025180:
      pdVar16 = (dword *)(puVar8 + iVar22 + 0x1c);
      pfVar15 = (float *)(puVar8 + iVar22 + 0x10);
      pdVar20 = (dword *)(puVar8 + iVar22 + 0x14);
      pdVar9 = (dword *)(puVar8 + iVar22 + 0x18);
    }
    else {
      if (uVar19 < 2) {
        if (uVar19 == 0) {
          iVar22 = *(int *)(param_1 + 0x10);
          puVar8 = ((unsigned char *)0x00003980) + uVar14 * 0x94;
          goto LAB_0002515c;
        }
        goto switchD_00025774_caseD_1;
      }
      if (uVar19 == 2) {
        iVar22 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039c0) + uVar14 * 0x94;
LAB_000251a4:
        pdVar16 = (dword *)(puVar8 + iVar22 + 0x20);
        pfVar15 = (float *)(puVar8 + iVar22 + 0x14);
        pdVar20 = (dword *)(puVar8 + iVar22 + 0x18);
        pdVar9 = (dword *)(puVar8 + iVar22 + 0x1c);
      }
      else {
        if (uVar19 != 3) goto switchD_00025774_caseD_1;
        iVar22 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039e0) + uVar14 * 0x94;
LAB_000251c8:
        pdVar16 = (dword *)(puVar8 + iVar22 + 0x24);
        pfVar15 = (float *)(puVar8 + iVar22 + 0x18);
        pdVar20 = (dword *)(puVar8 + iVar22 + 0x1c);
        pdVar9 = (dword *)(puVar8 + iVar22 + 0x20);
      }
    }
    break;
  case 8:
    uVar19 = uVar14 >> 5 & 7;
    uVar14 = uVar14 & 0x1f;
    if (uVar19 == 1) {
      iVar22 = *(int *)(param_1 + 0x10);
      puVar8 = ((unsigned char *)0x000039b0) + uVar14 * 0x94;
      goto LAB_00025180;
    }
    if (uVar19 < 2) {
      if (uVar19 == 0) {
        iVar22 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x00003990) + uVar14 * 0x94;
        goto LAB_0002515c;
      }
    }
    else {
      if (uVar19 == 2) {
        iVar22 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039d0) + uVar14 * 0x94;
        goto LAB_000251a4;
      }
      if (uVar19 == 3) {
        iVar22 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039f0) + uVar14 * 0x94;
        goto LAB_000251c8;
      }
    }
    goto switchD_00025774_caseD_1;
  case 9:
    iVar22 = *(int *)(param_1 + 0x10) + (uVar14 & 0x1f) * 0x7c;
    pfVar15 = (float *)(((unsigned char *)0x000031c0) + iVar22 + 4);
    pdVar16 = (dword *)(((unsigned char *)0x000031c0) + iVar22 + 0x10);
    pdVar9 = (dword *)(((unsigned char *)0x000031c0) + iVar22 + 0xc);
    pdVar20 = (dword *)(((unsigned char *)0x000031c0) + iVar22 + 8);
    break;
  case 10:
    iVar22 = *(int *)(param_1 + 0x10);
    puVar8 = ((unsigned char *)0x00003e20) + (uVar14 & 0xff) * 0x10;
LAB_0002515c:
    pdVar16 = (dword *)(puVar8 + iVar22 + 0x18);
    pfVar15 = (float *)(puVar8 + iVar22 + 0xc);
    pdVar20 = (dword *)(puVar8 + iVar22 + 0x10);
    pdVar9 = (dword *)(puVar8 + iVar22 + 0x14);
    break;
  case 0xb:
    iVar22 = *(int *)(param_1 + 0x10);
    pdVar16 = (dword *)(((unsigned char *)0x00002dec) + iVar22);
    pfVar15 = (float *)(((unsigned char *)0x00002de0) + iVar22);
    pdVar20 = (dword *)(((unsigned char *)0x00002de4) + iVar22);
    pdVar9 = (dword *)(((unsigned char *)0x00002de8) + iVar22);
    break;
  case 0xc:
    iVar22 = *(int *)(param_1 + 0x10);
    pdVar16 = (dword *)(((unsigned char *)0x00002dfc) + iVar22);
    pfVar15 = (float *)(((unsigned char *)0x00002df0) + iVar22);
    pdVar20 = (dword *)(((unsigned char *)0x00002df4) + iVar22);
    pdVar9 = (dword *)(((unsigned char *)0x00002df8) + iVar22);
    break;
  case 0xd:
    iVar22 = *(int *)(param_1 + 0x10);
    pdVar16 = (dword *)(((unsigned char *)0x000030c8) + iVar22);
    pfVar15 = (float *)(((unsigned char *)0x000030bc) + iVar22);
    pdVar20 = (dword *)(((unsigned char *)0x000030c0) + iVar22);
    pdVar9 = (dword *)(((unsigned char *)0x000030c4) + iVar22);
    break;
  case 0xe:
    iVar22 = *(int *)(param_1 + 0x10);
    pdVar16 = (dword *)(((unsigned char *)0x000030d8) + iVar22);
    pfVar15 = (float *)(((unsigned char *)0x000030cc) + iVar22);
    pdVar20 = (dword *)(((unsigned char *)0x000030d0) + iVar22);
    pdVar9 = (dword *)(((unsigned char *)0x000030d4) + iVar22);
    break;
  case 0xf:
    iVar22 = *(int *)(param_1 + 0x10);
    local_90 = (float)*(double *)(FUN_00001830 + iVar22);
    local_8c = (float)*(double *)(iVar22 + 0x1838);
    local_84[0] = 1.0;
    local_88[0] = (float)(*(double *)(iVar22 + 0x1838) - *(double *)(FUN_00001830 + iVar22));
    goto LAB_00025ac8;
  case 0x12:
    local_84[0] = *(float *)(*(int *)(param_1 + 0x10) + 0x24a4);
    local_90 = local_84[0];
    local_8c = local_84[0];
    local_88[0] = local_84[0];
    goto LAB_00025ac8;
  }
LAB_00025aa8:
  local_90 = *pfVar15;
  local_8c = (float)*pdVar20;
  local_88[0] = (float)*pdVar9;
  local_84[0] = (float)*pdVar16;
LAB_00025ac8:
  param_3[1] = local_8c;
  param_3[2] = local_88[0];
  *param_3 = local_90;
  param_3[3] = local_84[0];
LAB_00025af0:
  iVar24 = iVar24 + 1;
  puVar26 = puVar26 + 2;
  param_3 = param_3 + 4;
  if (iVar18 == iVar24) goto LAB_00025b04;
  goto LAB_00025090;
switchD_00025774_caseD_1:
  pfVar15 = (float *)0x0;
  pdVar20 = &MACH_HEADER.cputype;
  pdVar9 = &MACH_HEADER.cpusubtype;
  pdVar16 = &MACH_HEADER.filetype;
  goto LAB_00025aa8;
}

/* FUN_00025bf0 @ 0x25bf0 (408 bytes) */
int FUN_00025bf0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (*(int *)(param_2 + 0x1c) != 0) {
    _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
    if (*(int *)(param_2 + 0x2c) != 0) {
      _glpFreePPShaderLinearize();
      *(undefined4 *)(param_2 + 0x2c) = 0;
    }
    if (*(int *)(param_2 + 0x30) != 0) {
      _glpFreePPShaderToProgram();
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    if (*(int *)(param_2 + 0x34) != 0) {
      *(undefined4 *)(param_2 + 0x34) = 0;
    }
    FUN_0003f5d0(*(undefined4 *)(param_2 + 0x38));
    *(undefined4 *)(param_2 + 0x38) = 0;
    piVar2 = *(int **)(param_2 + 0x24);
    while (piVar2 != (int *)(param_2 + 0x20)) {
      iVar1 = *(int *)(param_2 + 0x1c);
      piVar4 = (int *)piVar2[1];
      if (iVar1 == 2) {
        FUN_000a0d70(piVar2[2] + 0x240,1,piVar2 + 5);
        piVar3 = (int *)piVar2[1];
      }
      else if (iVar1 == 3) {
        FUN_0003e4c0(piVar2[2] + 0x240,piVar2 + 5);
        piVar3 = (int *)piVar2[1];
      }
      else {
        piVar3 = piVar4;
        if (iVar1 == 1) {
          FUN_0003c310(piVar2[2] + 0x240,piVar2 + 5);
          piVar3 = (int *)piVar2[1];
        }
      }
      iVar1 = *piVar2;
      piVar2[2] = 0;
      *(int **)(iVar1 + 4) = piVar3;
      *(int *)piVar2[1] = iVar1;
      _free(piVar2);
      piVar2 = piVar4;
    }
    iVar1 = *(int *)(param_2 + 0xc);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_2 + 0x10);
      piVar2 = *(int **)(param_2 + 0x10);
      *(undefined4 *)(param_2 + 0x10) = 0;
      *piVar2 = iVar1;
      *(undefined4 *)(param_2 + 0xc) = 0;
    }
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return;
  }
  return;
}

/* FUN_00025da0 @ 0x25da0 (264 bytes) */
int FUN_00025da0(param_1)
  int param_1;
{
  int iVar1;
  pthread_mutex_t *ppVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  ppVar2 = *(pthread_mutex_t **)(param_1 + 0xc);
  puVar4 = *(undefined1 **)(ppVar2->__opaque + 0x2c);
  if (ppVar2->__opaque + 0x28 != puVar4) {
    do {
      for (piVar5 = *(int **)(puVar4 + 0x18); piVar5 != (int *)(puVar4 + 0x14);
          piVar5 = (int *)piVar5[1]) {
        iVar3 = piVar5[2];
        if (param_1 == iVar3) {
          iVar1 = *(int *)(puVar4 + 0x10);
          if (iVar1 == 2) {
            FUN_000a0d70(iVar3 + 0x240,1,piVar5 + 5);
          }
          else if (iVar1 == 3) {
            FUN_0003e4c0(iVar3 + 0x240,piVar5 + 5);
          }
          else if (iVar1 == 1) {
            FUN_0003c310(iVar3 + 0x240,piVar5 + 5);
          }
          iVar3 = *piVar5;
          piVar5[2] = 0;
          *(int *)(iVar3 + 4) = piVar5[1];
          *(int *)piVar5[1] = iVar3;
          _free(piVar5);
          break;
        }
      }
      puVar4 = *(undefined1 **)(puVar4 + 4);
    } while (ppVar2->__opaque + 0x28 != puVar4);
    ppVar2 = *(pthread_mutex_t **)(param_1 + 0xc);
  }
  _pthread_mutex_unlock(ppVar2);
  return;
}

/* FUN_00025ec0 @ 0x25ec0 (1372 bytes) */
int FUN_00025ec0(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte *pbVar1;
  byte *pbVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  char *pcVar7;
  size_t sVar8;
  undefined4 uVar9;
  int iVar10;
  bool bVar11;
  uint uVar12;
  byte *pbVar13;
  int *piVar14;
  int *piVar15;
  
  piVar15 = (int *)(param_1 + 0x240);
  for (piVar5 = (int *)param_2[9]; piVar5 != param_2 + 8; piVar5 = (int *)piVar5[1]) {
    if (param_1 == piVar5[2]) goto LAB_00025f80;
  }
  piVar5 = _calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
  piVar5[3] = param_2[5] + -1;
  iVar10 = param_2[6];
  piVar5[2] = param_1;
  piVar5[1] = (int)(param_2 + 8);
  piVar5[4] = iVar10 + -1;
  *piVar5 = param_2[8];
  param_2[8] = (int)piVar5;
  *(int **)(*piVar5 + 4) = piVar5;
LAB_00025f80:
  piVar14 = piVar5 + 5;
  if ((piVar5[5] == 0) && (FUN_000a0570(piVar15,1,piVar14), piVar5[5] == 0)) {
LAB_000263d8:
    uVar9 = 0;
  }
  else {
    FUN_000a0380(piVar15,0x8804);
    if (piVar5[3] == param_2[5]) {
      pbVar13 = (byte *)param_2[0xe];
      if (pbVar13 != (byte *)0x0) {
        uVar12 = *(uint *)(pbVar13 + 0x20);
        uVar4 = uVar12 >> 0x1b;
        if (uVar4 == 0) {
LAB_00026008:
          bVar11 = false;
        }
        else {
          if ((uint)pbVar13[1] == *(uint *)(*(int *)(*param_2 + 0x18) + (uint)*pbVar13 * 0x10)) {
            do {
              uVar4 = uVar4 - 1;
              if (uVar4 == 0) goto LAB_00026008;
              pbVar1 = pbVar13 + 2;
              pbVar2 = pbVar13 + 3;
              pbVar13 = pbVar13 + 2;
            } while ((uint)*pbVar2 == *(uint *)(*(int *)(*param_2 + 0x18) + (uint)*pbVar1 * 0x10));
          }
          bVar11 = true;
        }
        if (((((uVar12 & 0x1000000) != 0) &&
             ((uVar12 >> 0x17 & 1) != (uint)(byte)((unsigned char *)0x00002b7c)[param_1])) ||
            (((uVar12 & 0x400000) == 0 &&
             ((uVar12 >> 0x12 & 0xf) != (*(uint *)(param_1 + 0x1ae4) >> 6 & 0xffff))))) || (bVar11))
        {
          uVar4 = param_2[0xf];
          param_2[0xf] = uVar4 | 1;
          param_2[5] = param_2[5] + 1;
          if ((uVar4 & 2) != 0) {
            param_2[6] = param_2[6] + 1;
          }
          param_2[0xf] = 0;
          bVar11 = piVar5[3] != param_2[5];
          if (bVar11) {
            piVar5[3] = param_2[5];
          }
          goto LAB_000260dc;
        }
      }
LAB_000263c0:
      if (*(char *)(param_2 + 10) != '\0') goto LAB_000263d8;
    }
    else {
      piVar5[3] = param_2[5];
      bVar11 = true;
LAB_000260dc:
      if (!bVar11) goto LAB_000263c0;
      *(undefined1 *)(param_2 + 10) = 0;
      if (param_2[0xb] != 0) {
        _glpFreePPShaderLinearize();
        param_2[0xb] = 0;
      }
      if (param_2[0xc] != 0) {
        _glpFreePPShaderToProgram();
        param_2[0xc] = 0;
      }
      if (param_2[0xd] != 0) {
        param_2[0xd] = 0;
      }
      bVar11 = false;
      uVar4 = 0x1f9;
      FUN_0003f5d0(param_2[0xe]);
      param_2[0xe] = 0;
      while( true ) {
        if (*(short *)*param_2 == -0x74d0) {
          iVar10 = _glpPPShaderLinearize(*(undefined4 *)((short *)*param_2 + 2),uVar4);
          param_2[0xb] = iVar10;
        }
        piVar6 = (int *)FUN_0003f660();
        iVar10 = param_2[0xd];
        if (((iVar10 == 0) && (iVar10 = param_2[0xc], iVar10 == 0)) &&
           (iVar10 = param_2[0xb], iVar10 == 0)) {
          iVar10 = *(int *)(*param_2 + 4);
        }
        *piVar6 = iVar10;
        iVar10 = *(int *)(*param_2 + 0xc);
        piVar6[1] = *(int *)(*param_2 + 8);
        piVar6[2] = iVar10;
        piVar6[3] = *(int *)(*param_2 + 0x18);
        *(uint *)(piVar6[0xd] + 0x20) =
             ((byte)((unsigned char *)0x00002b7c)[param_1] & 1) << 0x17 |
             *(uint *)(piVar6[0xd] + 0x20) & 0xff7fffff;
        *(uint *)(piVar6[0xd] + 0x20) =
             (*(uint *)(param_1 + 0x1ae4) & 0x3c0) << 0xc |
             *(uint *)(piVar6[0xd] + 0x20) & 0xffc3ffff;
        iVar10 = FUN_00048da0(piVar6);
        if (iVar10 == 0) {
          *piVar15 = 0;
          FUN_0008e2e0(piVar15,0,piVar6[0xb],piVar6[10]);
          bVar11 = *piVar15 == 0;
          bVar3 = !bVar11;
          if (!bVar3) {
            iVar10 = piVar6[0xd];
            piVar6[0xd] = *piVar15;
            param_2[0xe] = iVar10;
            goto LAB_0002639c;
          }
        }
        else {
          bVar3 = !bVar11;
          if (!bVar3) goto LAB_0002639c;
        }
        if ((*(short *)*param_2 != -0x74d0) || ((uVar4 & 6) == 6)) break;
        if ((uVar4 & 4) == 0) {
          uVar4 = uVar4 | 4;
        }
        else if ((uVar4 & 2) == 0) {
          uVar4 = uVar4 & 0xfffffffb | 2;
        }
        if (param_2[0xb] != 0) {
          _glpFreePPShaderLinearize();
          param_2[0xb] = 0;
        }
        if (param_2[0xc] != 0) {
          _glpFreePPShaderToProgram();
          param_2[0xc] = 0;
        }
        if (param_2[0xd] != 0) {
          param_2[0xd] = 0;
        }
        FUN_0003f5d0(param_2[0xe]);
        param_2[0xe] = 0;
        FUN_0003f5e0(piVar6);
      }
      if (bVar3) {
        if (*(short *)*param_2 == -0x74d0) {
          bVar3 = true;
        }
        else {
          *piVar15 = 0;
          iVar10 = param_2[0xd];
          if (((iVar10 == 0) && (iVar10 = param_2[0xc], iVar10 == 0)) &&
             (iVar10 = param_2[0xb], iVar10 == 0)) {
            iVar10 = *(int *)(*param_2 + 4);
          }
          pcVar7 = (char *)((int (*)())FUN_0000f620)(iVar10);
          if (pcVar7 == (char *)0x0) {
            FUN_000a0d70(piVar15,1,piVar14);
            *piVar14 = 0;
            return 0;
          }
          sVar8 = _strlen(pcVar7);
          FUN_000a0300(piVar15,0x8804,0x8875,sVar8,pcVar7);
          _free(pcVar7);
          bVar3 = *piVar15 != 0;
        }
      }
      else {
        bVar3 = false;
      }
LAB_0002639c:
      FUN_0003f5e0(piVar6);
      if (bVar3) {
        *(undefined1 *)(param_2 + 10) = 1;
        return 0;
      }
    }
    uVar9 = 1;
    *(int **)(param_1 + 0x29ec) = piVar5;
  }
  return uVar9;
}

/* FUN_00026440 @ 0x26440 (500 bytes) */
int FUN_00026440(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  for (piVar1 = (int *)param_2[9]; piVar1 != param_2 + 8; piVar1 = (int *)piVar1[1]) {
    if (param_1 == piVar1[2]) goto LAB_000264f0;
  }
  piVar1 = _calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
  piVar1[3] = param_2[5] + -1;
  iVar2 = param_2[6];
  piVar1[2] = param_1;
  piVar1[1] = (int)(param_2 + 8);
  piVar1[4] = iVar2 + -1;
  *piVar1 = param_2[8];
  param_2[8] = (int)piVar1;
  *(int **)(*piVar1 + 4) = piVar1;
LAB_000264f0:
  iVar3 = param_1 + 0x240;
  iVar2 = FUN_0003b5b0(iVar3,piVar1 + 5);
  if (iVar2 != 0) {
    if (piVar1[3] == param_2[5]) {
      iVar2 = FUN_00053070(iVar3);
    }
    else {
      piVar1[3] = param_2[5];
      if (param_2[0xb] != 0) {
        _glpFreePPShaderLinearize();
        param_2[0xb] = 0;
      }
      if (param_2[0xc] != 0) {
        _glpFreePPShaderToProgram();
        param_2[0xc] = 0;
      }
      if (param_2[0xd] != 0) {
        param_2[0xd] = 0;
      }
      FUN_0003f5d0(param_2[0xe]);
      param_2[0xe] = 0;
      if (*(short *)*param_2 == -0x74cf) {
        iVar2 = _glpPPShaderLinearize(*(undefined4 *)((short *)*param_2 + 2),0xff);
        param_2[0xb] = iVar2;
        if (iVar2 != 0) {
          iVar2 = _glpPPShaderToProgram(iVar2,*(undefined4 *)(*param_2 + 0x18),0);
          param_2[0xc] = iVar2;
        }
      }
      iVar2 = param_2[0xd];
      if (((iVar2 == 0) && (iVar2 = param_2[0xc], iVar2 == 0)) && (iVar2 = param_2[0xb], iVar2 == 0)
         ) {
        iVar2 = *(int *)(*param_2 + 4);
      }
      iVar2 = FUN_0003c400(iVar3,iVar2,piVar1 + 5);
    }
    if (iVar2 != 0) {
      *(int **)(param_1 + 0x29e8) = piVar1;
      return 1;
    }
  }
  return 0;
}

