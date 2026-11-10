#include "decls.h"

/* _glAlphaFunc_Exec @ 0x16484 (120 bytes) */
void _glAlphaFunc_Exec(int param_1,int param_2,float fparam_1)
{
  undefined4 uVar1;
  double dVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 - 0x200U < 8) {
      dVar2 = (double)*(float *)(param_1 + 0x24);
      if ((dVar2 < fparam_1) || (dVar2 = (double)*(float *)(param_1 + 0x20), fparam_1 < dVar2)) {
        fparam_1 = dVar2;
      }
      *(float *)(param_1 + 0x30c0) = (float)fparam_1;
      *(short *)(param_1 + 0x30c4) = (short)param_2;
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 1;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glDisable_Exec @ 0x164fc (108 bytes) */
double _glDisable_Exec(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(*(int *)(param_1 + 0x4850) + (param_2 & 0x3ff) * 0x10);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    do {
      if (*puVar2 == param_2) {
                    
                    
        (*(code *)puVar2[1])(param_1,param_2,0);
        return;
      }
      puVar2 = (uint *)puVar2[2];
    } while (puVar2 != (uint *)0x0);
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _gleSetEnable_BLEND @ 0x16568 (32 bytes) */
void _gleSetEnable_BLEND(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x30e4) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x30e4) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 2;
  return;
}

/* _gleSetEnable_DEPTH_TEST @ 0x16588 (32 bytes) */
void _gleSetEnable_DEPTH_TEST(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x3128) == param_3) {
    return;
  }
  *(char *)(param_1 + 0x3128) = (char)param_3;
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200;
  return;
}

/* _glDepthMask_Exec @ 0x165a8 (64 bytes) */
void _glDepthMask_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    *(byte *)(param_1 + 0x31a4) = (byte)((uint)-param_2 >> 0x1f);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _gleSetEnable_CULL_FACE @ 0x165e8 (84 bytes) */
void _gleSetEnable_CULL_FACE(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  if (*(byte *)(param_1 + 0x34da) != param_3) {
    *(char *)(param_1 + 0x34da) = (char)param_3;
    _gleUpdatePolyMode(param_1);
    _gleUpdatePrimitiveData(param_1);
    return;
  }
  return;
}

/* _glActiveTexture_Exec @ 0x1663c (132 bytes) */
void _glActiveTexture_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_2 + -0x84c0;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((-1 < iVar2) &&
       ((iVar2 < (int)(uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb6) ||
        (iVar2 < (int)(uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xba))))) {
      *(int *)(param_1 + 0x53d4) = iVar2;
      if (7 < *(int *)(param_1 + 0x4ff4) - 0x10U) {
        return;
      }
      *(int *)(param_1 + 0x4ff4) = param_2 + -0x84b0;
      _gleUpdateMatrixMode(param_1);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glTexEnvfv_Exec @ 0x166c0 (3216 bytes) */
void _glTexEnvfv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  float *param_4;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  float *pfVar8;
  undefined2 *puVar9;
  uint uVar10;
  int iVar11;
  code *pcVar12;
  uint uVar13;
  double dVar14;
  double dVar15;
  
  fVar5 = FLOAT_00108e54;
  fVar4 = FLOAT_00108e50;
  dVar15 = DOUBLE_00108d80;
  uVar13 = *(uint *)(param_1 + 0x53d4);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x86de) {
      iVar7 = param_1 + uVar13 * 0x7c;
      switch(param_3) {
      case 0x86d9:
        dVar15 = (double)*param_4;
        if (DOUBLE_00108d80 <= dVar15) {
          uVar10 = (int)(dVar15 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar10 = (uint)(int)*param_4;
        }
        if ((uVar10 != 0x8536) && (uVar10 != 0x8538)) goto switchD_00016744_caseD_86da;
        *(short *)(iVar7 + 0x356c) = (short)uVar10;
        break;
      default:
switchD_00016744_caseD_86da:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar6 = 0x500;
        goto LAB_0001736c;
      case 0x86df:
        dVar15 = (double)*param_4;
        if (DOUBLE_00108d80 <= dVar15) {
          uVar10 = (int)(dVar15 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar10 = (uint)(int)*param_4;
        }
        iVar11 = _CheckNVShaderOperation(param_1,uVar10);
        if (iVar11 != 0) {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          *(int *)(param_1 + 0x7574) = iVar11;
          return;
        }
        *(short *)(iVar7 + 0x3564) = (short)uVar10;
        _gleUpdateTextureParams(param_1,uVar13);
        break;
      case 0x86e0:
        iVar11 = 4;
        pfVar8 = param_4;
        do {
          fVar4 = *pfVar8;
          dVar14 = (double)fVar4;
          pfVar8 = pfVar8 + 1;
          if (dVar15 <= dVar14) {
            uVar10 = (int)(dVar14 - dVar15) ^ 0x80000000;
          }
          else {
            uVar10 = (uint)(int)fVar4;
          }
          if (((uVar10 != 0x201) && (uVar10 != 0x206)) && (*(int *)(param_1 + 0x7574) == 0)) {
            *(undefined4 *)(param_1 + 0x7574) = 0x500;
          }
          dVar14 = DOUBLE_00108d80;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        iVar11 = 4;
        puVar9 = (undefined2 *)(iVar7 + 0x3570);
        do {
          fVar4 = *param_4;
          dVar15 = (double)fVar4;
          param_4 = param_4 + 1;
          if (dVar14 <= dVar15) {
            uVar10 = (int)(dVar15 - dVar14) ^ 0x80000000;
          }
          else {
            uVar10 = (uint)(int)fVar4;
          }
          if ((uVar10 == 0x201) || (uVar10 == 0x206)) {
            *puVar9 = (short)uVar10;
          }
          puVar9 = puVar9 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        break;
      case 0x86e1:
        *(float *)(iVar7 + 0x3588) = *param_4;
        *(float *)(iVar7 + 0x358c) = param_4[1];
        *(float *)(iVar7 + 0x3590) = param_4[2];
        *(float *)(iVar7 + 0x3594) = param_4[3];
        break;
      case 0x86e2:
        *(float *)(iVar7 + 0x3598) = *param_4;
        break;
      case 0x86e3:
        *(float *)(iVar7 + 0x359c) = *param_4;
        break;
      case 0x86e4:
        dVar15 = (double)*param_4;
        if (DOUBLE_00108d80 <= dVar15) {
          uVar10 = (int)(dVar15 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar10 = (uint)(int)*param_4;
        }
        if ((uVar10 < 0x84c0) || (*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb4) + 0x84c0 <= uVar10)
           ) goto switchD_00016744_caseD_86da;
        *(short *)(iVar7 + 0x356a) = (short)uVar10;
        break;
      case 0x86e5:
        *(float *)(iVar7 + 0x357c) = *param_4;
        *(float *)(iVar7 + 0x3580) = param_4[1];
        *(float *)(iVar7 + 0x3584) = param_4[2];
      }
      uVar10 = *(uint *)(param_1 + 800);
      iVar7 = 1;
    }
    else {
      if (param_2 == 0x8861) {
        if (param_3 == 0x8862) {
          if (*param_4 == FLOAT_00108e50) {
            uVar13 = *(uint *)(param_1 + 0x3444) &
                     (-2 << (uVar13 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar13 & 0x1f));
          }
          else {
            uVar13 = *(uint *)(param_1 + 0x3444) | 1 << (uVar13 & 0x3f);
          }
          *(uint *)(param_1 + 0x3444) = uVar13;
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400000;
          return;
        }
        goto switchD_00016744_caseD_86da;
      }
      if (param_2 != 0x2300) {
        if ((param_2 == 0x8500) && (param_3 == 0x8501)) {
          iVar7 = 0x10000;
          *(float *)(uVar13 * 0x7c + param_1 + 0x3560) = *param_4;
          uVar10 = *(uint *)(param_1 + 800);
          goto LAB_0001734c;
        }
        goto switchD_00016744_caseD_86da;
      }
      if (param_3 == 0x2200) {
        dVar15 = (double)*param_4;
        if (DOUBLE_00108d80 <= dVar15) {
          pcVar12 = (code *)((int)(dVar15 - DOUBLE_00108d80) ^ 0x80000000);
        }
        else {
          pcVar12 = (code *)(int)*param_4;
        }
        if (pcVar12 != (code *)0x1e01) {
          if (pcVar12 < (code *)0x1e02) {
            if (pcVar12 != (code *)0x104) {
              if (pcVar12 < (code *)0x105) {
                bVar1 = pcVar12 == (code *)0x0;
              }
              else {
                bVar1 = pcVar12 == (code *)0xbe2;
              }
LAB_00016b00:
              if (!bVar1) goto switchD_00016744_caseD_86da;
            }
          }
          else {
            if (pcVar12 < (code *)0x2100) goto switchD_00016744_caseD_86da;
            if ((code *)0x2100 < pcVar12) {
              bVar1 = pcVar12 == (code *)0x8570;
              goto LAB_00016b00;
            }
          }
        }
        iVar7 = 1;
        *(short *)(uVar13 * 0x7c + param_1 + 0x3538) = (short)pcVar12;
        uVar10 = *(uint *)(param_1 + 800);
LAB_0001734c:
        *(uint *)(param_1 + 800) = uVar10 | iVar7 << (uVar13 & 0x3f);
        return;
      }
      if (param_3 == 0x2201) {
        fVar3 = *param_4;
        iVar7 = param_1 + uVar13 * 0x7c;
        if (fVar3 < FLOAT_00108e50) {
          *(float *)(iVar7 + 0x3524) = FLOAT_00108e50;
        }
        else if (FLOAT_00108e54 < fVar3) {
          *(float *)(iVar7 + 0x3524) = FLOAT_00108e54;
        }
        else {
          *(float *)(iVar7 + 0x3524) = fVar3;
        }
        fVar3 = param_4[1];
        if (fVar3 < fVar4) {
          *(float *)(iVar7 + 0x3528) = fVar4;
        }
        else if (fVar5 < fVar3) {
          *(float *)(iVar7 + 0x3528) = fVar5;
        }
        else {
          *(float *)(iVar7 + 0x3528) = fVar3;
        }
        fVar3 = param_4[2];
        if (fVar3 < fVar4) {
          *(float *)(iVar7 + 0x352c) = fVar4;
        }
        else if (fVar5 < fVar3) {
          *(float *)(iVar7 + 0x352c) = fVar5;
        }
        else {
          *(float *)(iVar7 + 0x352c) = fVar3;
        }
        fVar3 = param_4[3];
        if (fVar3 < fVar4) {
          *(float *)(iVar7 + 0x3530) = fVar4;
        }
        else if (fVar5 < fVar3) {
          *(float *)(iVar7 + 0x3530) = fVar5;
        }
        else {
          *(float *)(iVar7 + 0x3530) = fVar3;
        }
        if (*(int *)(param_1 + 0x5434) == 0) {
          bVar2 = *(byte *)(uVar13 + *(int *)(param_1 + 0x5420) + 0x30c);
        }
        else {
          bVar2 = *(byte *)(uVar13 + *(int *)(*(int *)(param_1 + 0x5430) + 0x20) + 0x340);
        }
        iVar11 = (bVar2 >> 3 & 0x1c) + param_1;
        iVar7 = *(int *)(param_1 + 0x5424);
        *(uint *)(iVar11 + 0x324) = *(uint *)(iVar11 + 0x324) | 1 << (bVar2 & 0x1f);
        bVar2 = *(byte *)(uVar13 + iVar7 + 0x30c);
        iVar7 = (bVar2 >> 3 & 0x1c) + param_1;
        *(uint *)(iVar7 + 0x348) = *(uint *)(iVar7 + 0x348) | 1 << (bVar2 & 0x1f);
        iVar7 = 0x100;
        uVar10 = *(uint *)(param_1 + 800);
      }
      else {
        if (param_3 == 0x8588) {
          iVar7 = (int)*param_4;
          if (((iVar7 != 0x1702) && (0xf < iVar7 - 0x84c0U)) &&
             (((iVar7 != 0x8576 && (((iVar7 != 0x8577 && (iVar7 != 0x8578)) && (iVar7 != 0)))) &&
              (iVar7 != 1)))) goto switchD_00016744_caseD_86da;
          *(short *)(uVar13 * 0x7c + param_1 + 0x3546) = (short)iVar7;
        }
        else if (param_3 < 0x8589) {
          if (param_3 == 0x8573) {
            fVar4 = *param_4;
            if (((fVar4 == FLOAT_00108e54) || (fVar4 == FLOAT_00108ea4)) ||
               (fVar4 == FLOAT_00108ea8)) {
              *(float *)(uVar13 * 0x7c + param_1 + 0x3558) = fVar4;
            }
            else {
LAB_000172d8:
              if (*(int *)(param_1 + 0x7574) == 0) {
                *(undefined4 *)(param_1 + 0x7574) = 0x500;
              }
            }
          }
          else {
            if (0x8573 < param_3) {
              if (param_3 == 0x8581) {
                iVar7 = (int)*param_4;
                if (((((iVar7 == 0x1702) || (iVar7 - 0x84c0U < 0x10)) || (iVar7 == 0x8576)) ||
                    ((iVar7 == 0x8577 || (iVar7 == 0x8578)))) || ((iVar7 == 0 || (iVar7 == 1)))) {
                  *(short *)(uVar13 * 0x7c + param_1 + 0x3542) = (short)iVar7;
                  goto LAB_000172fc;
                }
              }
              else if (param_3 < 0x8582) {
                if ((param_3 == 0x8580) &&
                   (((((iVar7 = (int)*param_4, iVar7 == 0x1702 || (iVar7 - 0x84c0U < 0x10)) ||
                      ((iVar7 == 0x8576 || ((iVar7 == 0x8577 || (iVar7 == 0x8578)))))) ||
                     (iVar7 == 0)) || (iVar7 == 1)))) {
                  *(short *)(uVar13 * 0x7c + param_1 + 0x3540) = (short)iVar7;
                  goto LAB_000172fc;
                }
              }
              else if ((param_3 == 0x8582) &&
                      (((iVar7 = (int)*param_4, iVar7 == 0x1702 || (iVar7 - 0x84c0U < 0x10)) ||
                       ((iVar7 == 0x8576 ||
                        ((((iVar7 == 0x8577 || (iVar7 == 0x8578)) || (iVar7 == 0)) || (iVar7 == 1)))
                        ))))) {
                *(short *)(uVar13 * 0x7c + param_1 + 0x3544) = (short)iVar7;
                goto LAB_000172fc;
              }
              goto switchD_00016744_caseD_86da;
            }
            if (param_3 == 0x8571) {
              pcVar12 = (code *)(int)*param_4;
              if (pcVar12 < (code *)0x8576) {
                if ((pcVar12 < (code *)0x8574) && (pcVar12 != (code *)0x1e01)) {
                  if (pcVar12 < (code *)0x1e02) {
                    bVar1 = pcVar12 == (code *)0x104;
                  }
                  else {
                    if (pcVar12 == (code *)0x2100) goto LAB_00016dfc;
                    bVar1 = pcVar12 == (code *)0x84e7;
                  }
                  if (!bVar1) goto switchD_00016744_caseD_86da;
                }
              }
              else if ((pcVar12 < (code *)0x86ae) ||
                      (((code *)0x86af < pcVar12 && ((code *)0x2 < pcVar12 + -0x8744))))
              goto switchD_00016744_caseD_86da;
LAB_00016dfc:
              *(short *)(uVar13 * 0x7c + param_1 + 0x353c) = (short)pcVar12;
            }
            else {
              if (param_3 < 0x8572) {
                if (param_3 == 0xd1c) {
                  fVar4 = *param_4;
                  if (((fVar4 != FLOAT_00108e54) && (fVar4 != FLOAT_00108ea4)) &&
                     (fVar4 != FLOAT_00108ea8)) goto LAB_000172d8;
                  *(float *)(uVar13 * 0x7c + param_1 + 0x355c) = fVar4;
                  goto LAB_000172fc;
                }
                goto switchD_00016744_caseD_86da;
              }
              pcVar12 = (code *)(int)*param_4;
              if (pcVar12 != (code *)0x84e7) {
                if (pcVar12 < (code *)0x84e8) {
                  if (pcVar12 != (code *)0x1e01) {
                    if (pcVar12 < (code *)0x1e02) {
                      bVar1 = pcVar12 == (code *)0x104;
                    }
                    else {
                      bVar1 = pcVar12 == (code *)0x2100;
                    }
                    if (!bVar1) goto switchD_00016744_caseD_86da;
                  }
                }
                else if ((pcVar12 < (code *)0x8574) ||
                        (((code *)0x8575 < pcVar12 && ((code *)0x2 < pcVar12 + -0x8744))))
                goto switchD_00016744_caseD_86da;
              }
              *(short *)(uVar13 * 0x7c + param_1 + 0x353e) = (short)pcVar12;
            }
          }
        }
        else {
          if (param_3 != 0x8591) {
            if (param_3 < 0x8592) {
              if (param_3 == 0x858a) {
                iVar7 = (int)*param_4;
                if ((((((iVar7 == 0x1702) || (iVar7 - 0x84c0U < 0x10)) || (iVar7 == 0x8576)) ||
                     ((iVar7 == 0x8577 || (iVar7 == 0x8578)))) || (iVar7 == 0)) || (iVar7 == 1)) {
                  *(short *)(uVar13 * 0x7c + param_1 + 0x354a) = (short)iVar7;
                  goto LAB_000172fc;
                }
              }
              else if (param_3 < 0x858a) {
                iVar7 = (int)*param_4;
                if ((((iVar7 == 0x1702) || (iVar7 - 0x84c0U < 0x10)) ||
                    ((iVar7 == 0x8576 || (((iVar7 == 0x8577 || (iVar7 == 0x8578)) || (iVar7 == 0))))
                    )) || (iVar7 == 1)) {
                  *(short *)(uVar13 * 0x7c + param_1 + 0x3548) = (short)iVar7;
                  goto LAB_000172fc;
                }
              }
              else if ((param_3 == 0x8590) && ((int)*param_4 - 0x300U < 4)) {
                *(short *)(uVar13 * 0x7c + param_1 + 0x354c) = (short)(int)*param_4;
                goto LAB_000172fc;
              }
            }
            else if (param_3 == 0x8598) {
              if ((int)*param_4 - 0x302U < 2) {
                *(short *)(uVar13 * 0x7c + param_1 + 0x3552) = (short)(int)*param_4;
                goto LAB_000172fc;
              }
            }
            else if (param_3 < 0x8599) {
              if ((param_3 == 0x8592) && ((int)*param_4 - 0x300U < 4)) {
                *(short *)(uVar13 * 0x7c + param_1 + 0x3550) = (short)(int)*param_4;
                goto LAB_000172fc;
              }
            }
            else if (param_3 == 0x8599) {
              if ((int)*param_4 - 0x302U < 2) {
                *(short *)(uVar13 * 0x7c + param_1 + 0x3554) = (short)(int)*param_4;
                goto LAB_000172fc;
              }
            }
            else if ((param_3 == 0x859a) && ((int)*param_4 - 0x302U < 2)) {
              *(short *)(uVar13 * 0x7c + param_1 + 0x3556) = (short)(int)*param_4;
              goto LAB_000172fc;
            }
            goto switchD_00016744_caseD_86da;
          }
          if (3 < (int)*param_4 - 0x300U) goto switchD_00016744_caseD_86da;
          *(short *)(uVar13 * 0x7c + param_1 + 0x354e) = (short)(int)*param_4;
        }
LAB_000172fc:
        uVar10 = *(uint *)(param_1 + 800);
        iVar7 = 0x1000000;
      }
    }
    *(uint *)(param_1 + 800) = uVar10 | iVar7 << (uVar13 & 0x3f);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar6 = 0x502;
LAB_0001736c:
    *(undefined4 *)(param_1 + 0x7574) = uVar6;
  }
  return;
}

/* _glHint_Exec @ 0x17384 (444 bytes) */
void _glHint_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  
  puVar2 = PTR__gleSetEyeInterpFunc_0011203c;
  puVar1 = PTR__gleSetClipInterpFunc_00112038;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (2 < param_3 - 0x1100U) goto LAB_00017508;
    if (param_2 == 0x80f0) {
      *(int *)(param_1 + 0x5080) = param_3;
      *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | 1;
      *(uint *)(param_1 + 0x497c) = *(uint *)(param_1 + 0x497c) | 1;
    }
    else {
      uVar4 = (undefined2)param_3;
      if (param_2 < 0x80f1) {
        if (param_2 == 0xc52) {
          *(undefined2 *)(0x3170 + param_1) = uVar4;
        }
        else if (param_2 < 0xc53) {
          if (param_2 == 0xc50) {
            *(undefined2 *)(param_1 + 0x316c) = uVar4;
          }
          else {
            if (param_2 != 0xc51) {
LAB_00017508:
              if (*(int *)(param_1 + 0x7574) != 0) {
                return;
              }
              uVar3 = 0x500;
              goto LAB_00017518;
            }
            *(undefined2 *)(param_1 + 0x316e) = uVar4;
          }
        }
        else if (param_2 == 0xc53) {
          *(undefined2 *)(param_1 + 0x3172) = uVar4;
        }
        else {
          if (param_2 != 0xc54) goto LAB_00017508;
          *(undefined2 *)(param_1 + 0x3174) = uVar4;
          *(undefined **)(param_1 + 0x49c8) = puVar2;
          *(undefined **)(param_1 + 0x49cc) = puVar1;
          ((double (*)())_gleUpdateFogData)(param_1);
        }
      }
      else if (param_2 == 0x8534) {
        *(undefined2 *)(param_1 + 0x317a) = uVar4;
      }
      else if (param_2 < 0x8535) {
        if (param_2 == 0x8192) {
          *(undefined2 *)(param_1 + 0x3178) = uVar4;
        }
        else {
          if (param_2 != 0x84ef) goto LAB_00017508;
          *(undefined2 *)(param_1 + 0x3176) = uVar4;
        }
      }
      else if (param_2 == 0x85b1) {
        *(int *)(param_1 + 0x507c) = param_3;
      }
      else {
        if (param_2 != 0x8b8b) goto LAB_00017508;
        *(undefined2 *)(param_1 + 0x317c) = uVar4;
      }
    }
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x2000;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_00017518:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
  }
  return;
}

/* _glGenTextures_Exec @ 0x17540 (236 bytes) */
void _glGenTextures_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      iVar4 = *(int *)(param_1 + 0x5148);
      if (*(char *)(iVar4 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar4 + 0x8028);
        iVar4 = *(int *)(param_1 + 0x5148);
      }
      iVar4 = _gleGenHashNames(iVar4 + 0x2008,param_2);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (iVar4 == 0) {
        return;
      }
      iVar3 = 0;
      if (param_2 < 1) {
        return;
      }
      do {
        iVar2 = iVar4 + iVar3;
        iVar3 = iVar3 + 1;
        *param_3 = iVar2;
        param_3 = param_3 + 1;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glPixelStorei_Exec @ 0x1762c (648 bytes) */
void _glPixelStorei_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
      return;
    }
    return;
  }
  if (param_2 == 0xd02) {
    if (-1 < param_3) {
      *(int *)(param_1 + 0x31b0) = param_3;
      goto LAB_000178a4;
    }
LAB_00017874:
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000178a4;
    uVar1 = 0x501;
  }
  else {
    if (param_2 < 0xd03) {
      if (param_2 == 0xcf3) {
        if (-1 < param_3) {
          *(int *)(param_1 + 0x31d4) = param_3;
          goto LAB_000178a4;
        }
      }
      else if (param_2 < 0xcf4) {
        if (param_2 == 0xcf1) {
          if (param_3 == 0) {
            *(undefined1 *)(param_1 + 0x31e5) = 0;
          }
          else {
            *(undefined1 *)(param_1 + 0x31e5) = 1;
          }
          goto LAB_000178a4;
        }
        if (param_2 < 0xcf2) {
          if (param_2 == 0xcf0) {
            if (param_3 == 0) {
              *(undefined1 *)(param_1 + 0x31e4) = 0;
            }
            else {
              *(undefined1 *)(param_1 + 0x31e4) = 1;
            }
            goto LAB_000178a4;
          }
          goto LAB_00017890;
        }
        if (-1 < param_3) {
          *(int *)(param_1 + 0x31cc) = param_3;
          goto LAB_000178a4;
        }
      }
      else if (param_2 == 0xcf5) {
        if (((param_3 - 1U < 2) || (param_3 == 4)) || (param_3 == 8)) {
          *(int *)(param_1 + 0x31e0) = param_3;
          goto LAB_000178a4;
        }
      }
      else if (param_2 < 0xcf5) {
        if (-1 < param_3) {
          *(int *)(param_1 + 0x31d8) = param_3;
          goto LAB_000178a4;
        }
      }
      else if (param_2 == 0xd00) {
        if (-1 < param_3) {
          *(char *)(param_1 + 0x31c8) = (char)param_3;
          goto LAB_000178a4;
        }
      }
      else {
        if (param_2 != 0xd01) goto LAB_00017890;
        if (-1 < param_3) {
          *(char *)(param_1 + 0x31c9) = (char)param_3;
          goto LAB_000178a4;
        }
      }
      goto LAB_00017874;
    }
    if (param_2 == 0x806b) {
      if (-1 < param_3) {
        *(int *)(param_1 + 0x31c0) = param_3;
        goto LAB_000178a4;
      }
      goto LAB_00017874;
    }
    if (0x806b < param_2) {
      if (param_2 == 0x806d) {
        if (-1 < param_3) {
          *(int *)(param_1 + 0x31dc) = param_3;
          goto LAB_000178a4;
        }
      }
      else if (param_2 < 0x806d) {
        if (-1 < param_3) {
          *(int *)(0x31b4 + param_1) = param_3;
          goto LAB_000178a4;
        }
      }
      else {
        if (param_2 != 0x806e) {
          if (param_2 == 0x85b2) {
            if (param_3 == 0) {
              *(undefined1 *)(param_1 + 0x31e6) = 0;
            }
            else {
              *(undefined1 *)(param_1 + 0x31e6) = 1;
            }
            goto LAB_000178a4;
          }
          goto LAB_00017890;
        }
        if (-1 < param_3) {
          *(int *)(param_1 + 0x31d0) = param_3;
          goto LAB_000178a4;
        }
      }
      goto LAB_00017874;
    }
    if (param_2 == 0xd04) {
      if (-1 < param_3) {
        *(int *)(param_1 + 0x31bc) = param_3;
        goto LAB_000178a4;
      }
      goto LAB_00017874;
    }
    if (param_2 < 0xd04) {
      if (-1 < param_3) {
        *(int *)(param_1 + 0x31b8) = param_3;
        goto LAB_000178a4;
      }
      goto LAB_00017874;
    }
    if (param_2 == 0xd05) {
      if (((param_3 - 1U < 2) || (param_3 == 4)) || (param_3 == 8)) {
        *(int *)(param_1 + 0x31c4) = param_3;
        goto LAB_000178a4;
      }
      goto LAB_00017874;
    }
LAB_00017890:
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000178a4;
    uVar1 = 0x500;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
LAB_000178a4:
  *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x200000;
  return;
}

/* _glBindTexture_Exec @ 0x178b4 (388 bytes) */
void _glBindTexture_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_000179ac;
  }
  if (param_2 != 0x84f5) {
    if (param_2 < 0x84f6) {
      if (param_2 == 0xde1) {
        uVar1 = 3;
        goto LAB_000179b4;
      }
      if (param_2 < 0xde2) {
        if (param_2 == 0xde0) {
          uVar1 = 4;
          goto LAB_000179b4;
        }
      }
      else if (param_2 == 0x806f) {
        uVar1 = 1;
        goto LAB_000179b4;
      }
    }
    else {
      if (param_2 == 0x85b3) goto LAB_00017994;
      if (param_2 < 0x85b4) {
        if (param_2 == 0x8513) {
          uVar1 = 0;
          goto LAB_000179b4;
        }
      }
      else if (param_2 == 0x184f5) goto LAB_00017994;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x500;
LAB_000179ac:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
    return;
  }
LAB_00017994:
  uVar1 = 2;
LAB_000179b4:
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
    ((void (*)())_gleBindTexture)(param_1,uVar1,param_3,*(undefined4 *)(param_1 + 0x53d4));
    return;
  }
  iVar2 = *(int *)(param_1 + 0x5148) + 0x8028;
  _pthread_mutex_lock(iVar2);
  ((void (*)())_gleBindTexture)(param_1,uVar1,param_3,*(undefined4 *)(param_1 + 0x53d4));
  _pthread_mutex_unlock(iVar2);
  return;
}

/* _gleBindTexture @ 0x17a38 (420 bytes) */
void _gleBindTexture(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  int param_3;
  uint param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  
  iVar7 = *(int *)(param_1 + 0x5148) + 0x2008;
  if (param_3 == 0) {
    if ((param_2 & 0xfffffff0) != 0) {
LAB_00017ac4:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
      }
      goto LAB_00017bb4;
    }
    iVar3 = *(int *)(param_2 * 4 + param_1 + 0x5294);
  }
  else {
    iVar3 = ((int (*)())_gleLookupHashObject)(iVar7,param_3);
    if (iVar3 == 0) {
      iVar3 = _gleCreateTextureObject(param_2,param_3);
      _gleCreatePluginTexture(param_1,iVar3 + 0x10);
      ((int (*)())_gleAddHashNameAndObject)(param_1,iVar7,iVar3);
    }
    else if ((*(ushort *)(iVar3 + 0x34) & 0xffffc3ff) != param_2) goto LAB_00017ac4;
  }
  iVar7 = (param_4 * 5 + (param_2 & 0xf)) * 4 + param_1;
  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
  iVar5 = *(int *)(iVar7 + 0x5154);
  iVar2 = *(int *)(iVar5 + 8) + -1;
  *(int *)(iVar5 + 8) = iVar2;
  if (iVar2 == 0) {
    _gleFreeTextureObject(param_1,iVar5);
  }
  *(int *)(iVar7 + 0x5154) = iVar3;
  if ((*(int *)(iVar3 + 0x30) != 0) &&
     (*(int *)(iVar3 + 0x30) !=
      *(int *)((uint)*(byte *)(param_1 + 0x85a8) * 4 + *(int *)(param_1 + 0x5148) + 0x8054))) {
    _gleSynchronizePluginTextureLevels(param_1,iVar3 + 0x10);
  }
  iVar7 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    puVar4 = (undefined4 *)(iVar3 + 0x10);
    puVar6 = (undefined4 *)((param_4 * 5 + (param_2 & 0xf)) * 4 + param_1 + 0x86e0);
    do {
      uVar1 = *puVar4;
      iVar7 = iVar7 + 1;
      puVar4 = puVar4 + 1;
      *puVar6 = uVar1;
      puVar6 = puVar6 + 0xb8;
    } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
LAB_00017bb4:
  *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 1 << (param_4 & 0x3f);
  return;
}

/* _gleLookupHashObject @ 0x17bdc (120 bytes) */
int _gleLookupHashObject(param_1, param_2)
  int param_1;
  uint param_2;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = (param_2 & 0x3ff) * 4;
  piVar4 = *(int **)(iVar3 + param_1);
  if (piVar4 == (int *)0x0) {
    return (int *)0x0;
  }
  if (piVar4[1] != param_2) {
    piVar1 = piVar4;
    piVar2 = (int *)*piVar4;
    while( true ) {
      if (piVar2 == (int *)0x0) {
        return (int *)0x0;
      }
      if (piVar2[1] == param_2) break;
      piVar1 = piVar2;
      piVar2 = (int *)*piVar2;
    }
    *piVar1 = *piVar2;
    *piVar2 = (int)piVar4;
    *(int **)(iVar3 + param_1) = piVar2;
    return piVar2;
  }
  return piVar4;
}

/* _gleAddHashNameAndObject @ 0x17c54 (76 bytes) */
int _gleAddHashNameAndObject(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())_gleAddHashName)(param_2,*(undefined4 *)(param_3 + 4));
  ((void (*)())_gleAddHashObject)(param_2,param_3);
  return uVar1;
}

/* _gleAddHashName @ 0x17ca0 (320 bytes) */
int _gleAddHashName(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  piVar6 = *(int **)(param_1 + 0x1000);
  if ((piVar6 == (int *)0x0) || (uVar3 = piVar6[1], param_2 < uVar3 - 1)) {
    puVar4 = (undefined4 *)_malloc(0xc);
    uVar1 = *(undefined4 *)(param_1 + 0x1000);
    puVar4[1] = param_2;
    *puVar4 = uVar1;
    puVar4[2] = 1;
    *(undefined4 **)(param_1 + 0x1000) = puVar4;
  }
  else {
    do {
      piVar7 = piVar6;
      iVar5 = piVar7[2];
      if (param_2 == uVar3 - 1) {
        piVar7[1] = param_2;
        piVar7[2] = iVar5 + 1;
        return 1;
      }
      if ((uVar3 <= param_2) && (param_2 < uVar3 + iVar5)) {
        return 0;
      }
      if (param_2 == uVar3 + iVar5) {
        piVar6 = (int *)*piVar7;
        piVar7[2] = iVar5 + 1;
        if (piVar6 == (int *)0x0) {
          return 1;
        }
        if (param_2 + 1 != piVar6[1]) {
          return 1;
        }
        iVar2 = piVar6[2];
        *piVar7 = *piVar6;
        piVar7[2] = iVar5 + 1 + iVar2;
        _free(piVar6);
        return 1;
      }
      piVar6 = (int *)*piVar7;
    } while ((piVar6 != (int *)0x0) && (uVar3 = piVar6[1], uVar3 - 1 <= param_2));
    piVar6 = (int *)_malloc(0xc);
    iVar5 = *piVar7;
    piVar6[1] = param_2;
    *piVar6 = iVar5;
    piVar6[2] = 1;
    *piVar7 = (int)piVar6;
  }
  return 1;
}

/* _gleAddHashObject @ 0x17de0 (24 bytes) */
void _gleAddHashObject(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  
  iVar1 = (param_2[1] & 0x3ff) * 4;
  *param_2 = *(undefined4 *)(param_1 + iVar1);
  *(undefined4 **)(param_1 + iVar1) = param_2;
  return;
}

/* _glTextureRangeAPPLE_Exec @ 0x17df8 (176 bytes) */
void _glTextureRangeAPPLE_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = ((int (*)())_gleLookUpNonProxyTexture)(param_1,param_2);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x500;
    }
    else {
      if (-1 < param_3) {
        *(undefined4 *)(iVar2 + 0x74) = param_4;
        *(int *)(iVar2 + 0x70) = param_3;
        *(uint *)(param_1 + 0x314) =
             *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
        return;
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _gleLookUpNonProxyTexture @ 0x17ea8 (224 bytes) */
int _gleLookUpNonProxyTexture(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x53d4);
  if (param_2 != 0x84f5) {
    if (param_2 < 0x84f6) {
      if (param_2 == 0xde1) {
        iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5160);
      }
      else if (param_2 < 0xde2) {
        if (param_2 != 0xde0) {
          return 0;
        }
        iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5164);
      }
      else {
        if (param_2 != 0x806f) {
          return 0;
        }
        iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5158);
      }
      goto LAB_00017f48;
    }
    if (param_2 < 0x851b) {
      if ((param_2 < 0x8515) && (param_2 != 0x8513)) {
        return 0;
      }
      iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5154);
      goto LAB_00017f48;
    }
    if (param_2 != 0x85b3) {
      return 0;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x515c);
LAB_00017f48:
  return iVar1 + 0x10;
}

/* _glTexParameteri_Exec @ 0x17f88 (40 bytes) */
void _glTexParameteri_Exec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param_4;
  ((int (*)())_glTexParameterI_Exec)(param_1,param_2,param_3,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
  return;
}

/* _glTexParameterI_Exec @ 0x17fb0 (2056 bytes) */
int _glTexParameterI_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined *param_3;
  uint *param_4;
{
  bool bVar1;
  float fVar2;
  double dVar3;
  uint uVar4;
  undefined4 uVar5;
  float fVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  
  iVar7 = ((int (*)())_gleLookUpNonProxyTexture)(param_1,param_2);
  fVar6 = FLOAT_00108e50;
  dVar3 = DOUBLE_00108d58;
  uVar8 = 0;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (iVar7 == 0) goto LAB_00018768;
    if (param_3 == (undefined *)0x813c) {
      if ((int)*param_4 < 0) goto LAB_00018554;
      uVar8 = 1;
      *(short *)(iVar7 + 0x60) = (short)*param_4;
    }
    else if (param_3 < (undefined *)0x813d) {
      if (param_3 != (undefined *)0x2803) {
        if ((undefined *)0x2803 < param_3) {
          if (param_3 == (undefined *)0x80bf) {
            if ((int)*param_4 < 1) {
              uVar5 = 0;
            }
            else {
              uVar5 = 0x3f800000;
            }
            *(undefined4 *)(iVar7 + 0x68) = uVar5;
          }
          else if (param_3 < (undefined *)0x80c0) {
            if (param_3 == (undefined *)0x8066) {
              fVar6 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
              if (fVar6 < FLOAT_00108e50) {
                fVar6 = 0.0;
              }
              else if (FLOAT_00108e54 < fVar6) {
                fVar6 = 1.0;
              }
              *(float *)(iVar7 + 0x28) = fVar6;
            }
            else {
              if (param_3 != (undefined *)0x8072) goto LAB_00018768;
              uVar9 = *param_4;
              if (uVar9 != 0x812f) {
                if (uVar9 < 0x8130) {
                  if (0x28ff < uVar9) {
                    if (0x2901 < uVar9) {
                      uVar4 = 0x812d;
                      goto LAB_0001830c;
                    }
                    goto LAB_00018314;
                  }
                }
                else {
                  if (uVar9 < 0x8744) {
                    if (0x8741 < uVar9) goto LAB_00018314;
                    uVar4 = 0x8370;
                  }
                  else {
                    uVar4 = 0x8912;
                  }
LAB_0001830c:
                  if (uVar9 == uVar4) goto LAB_00018314;
                }
                goto LAB_00018768;
              }
LAB_00018314:
              *(short *)(iVar7 + 0x38) = (short)uVar9;
            }
          }
          else if (param_3 == (undefined *)0x813a) {
            *(float *)(iVar7 + 0x54) =
                 (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
          }
          else {
            if (param_3 != (undefined *)0x813b) goto LAB_00018768;
            *(float *)(iVar7 + 0x58) =
                 (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
          }
          goto LAB_00018780;
        }
        if (param_3 == (undefined *)0x2800) {
          if (*param_4 - 0x2600 < 2) {
            *(short *)(iVar7 + 0x3c) = (short)*param_4;
            goto LAB_00018780;
          }
        }
        else if (param_3 < (undefined *)0x2801) {
          if (param_3 == ((unsigned char *)0x00001004)) {
            fVar2 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58) *
                    FLOAT_00108e68 + FLOAT_00108e6c;
            if (fVar2 < FLOAT_00108e50) {
              *(float *)(iVar7 + 0x40) = FLOAT_00108e50;
            }
            else {
              *(float *)(iVar7 + 0x40) = fVar2;
            }
            fVar2 = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - DOUBLE_00108d58)
                    * FLOAT_00108e68 + FLOAT_00108e6c;
            if (fVar2 < fVar6) {
              *(float *)(iVar7 + 0x44) = fVar6;
            }
            else {
              *(float *)(iVar7 + 0x44) = fVar2;
            }
            fVar2 = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - DOUBLE_00108d58)
                    * FLOAT_00108e68 + FLOAT_00108e6c;
            if (fVar2 < fVar6) {
              *(float *)(iVar7 + 0x48) = fVar6;
            }
            else {
              *(float *)(iVar7 + 0x48) = fVar2;
            }
            fVar2 = (float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - DOUBLE_00108d58)
                    * FLOAT_00108e68 + FLOAT_00108e6c;
            if (!(fVar2 < fVar6)) goto LAB_00018760;
            *(float *)(iVar7 + 0x4c) = fVar6;
            goto LAB_00018780;
          }
        }
        else if (param_3 == (undefined *)0x2801) {
          uVar9 = *param_4;
          if ((0x25ff < uVar9) && ((uVar9 < 0x2602 || (uVar9 - 0x2700 < 4)))) {
            *(short *)(iVar7 + 0x3a) = (short)uVar9;
            uVar8 = 1;
            goto LAB_00018780;
          }
        }
        else if (param_3 == (undefined *)0x2802) {
          uVar9 = *param_4;
          if (uVar9 == 0x812f) {
LAB_0001823c:
            *(short *)(iVar7 + 0x34) = (short)uVar9;
            goto LAB_00018780;
          }
          if (uVar9 < 0x8130) {
            if (0x28ff < uVar9) {
              if (0x2901 < uVar9) {
                uVar4 = 0x812d;
                goto LAB_00018234;
              }
              goto LAB_0001823c;
            }
          }
          else {
            if (uVar9 < 0x8744) {
              if (0x8741 < uVar9) goto LAB_0001823c;
              uVar4 = 0x8370;
            }
            else {
              uVar4 = 0x8912;
            }
LAB_00018234:
            if (uVar9 == uVar4) goto LAB_0001823c;
          }
        }
        goto LAB_00018768;
      }
      uVar9 = *param_4;
      if (uVar9 != 0x812f) {
        if (uVar9 < 0x8130) {
          if (uVar9 < 0x2900) goto LAB_00018768;
          if (0x2901 < uVar9) {
            uVar4 = 0x812d;
            goto LAB_000182a0;
          }
        }
        else {
          if (uVar9 < 0x8744) {
            if (0x8741 < uVar9) goto LAB_000182a8;
            uVar4 = 0x8370;
          }
          else {
            uVar4 = 0x8912;
          }
LAB_000182a0:
          if (uVar9 != uVar4) goto LAB_00018768;
        }
      }
LAB_000182a8:
      *(short *)(iVar7 + 0x36) = (short)uVar9;
    }
    else if (param_3 == (undefined *)0x85bc) {
      if (2 < *param_4 - 0x85bd) goto LAB_00018768;
      *(short *)(iVar7 + 0x3e) = (short)*param_4;
    }
    else {
      if ((undefined *)0x85bc < param_3) {
        if (param_3 == (undefined *)0x884c) {
          uVar9 = *param_4;
          if ((uVar9 == 0) || (uVar9 == 0x884e)) {
            *(short *)(iVar7 + 0x66) = (short)uVar9;
            goto LAB_00018780;
          }
        }
        else if (param_3 < (undefined *)0x884d) {
          if (param_3 == (undefined *)0x871a) {
            *(float *)(iVar7 + 0x40) =
                 (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
            *(float *)(iVar7 + 0x44) =
                 (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - dVar3);
            *(float *)(iVar7 + 0x48) =
                 (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - dVar3);
            fVar2 = (float)((double)CONCAT44(0x43300000,param_4[3] ^ 0x80000000) - dVar3);
LAB_00018760:
            *(float *)(iVar7 + 0x4c) = fVar2;
            goto LAB_00018780;
          }
          if (param_3 == (undefined *)0x884b) {
            uVar9 = *param_4;
            if (uVar9 != 0x1909) {
              if (uVar9 < 0x190a) {
                bVar1 = uVar9 == 0x1906;
              }
              else {
                bVar1 = uVar9 == 0x8049;
              }
              if (!bVar1) goto LAB_00018768;
            }
            *(short *)(iVar7 + 0x6c) = (short)uVar9;
            goto LAB_00018780;
          }
        }
        else if (param_3 == (undefined *)0x884d) {
          if (*param_4 - 0x200 < 8) {
            *(short *)(iVar7 + 100) = (short)*param_4;
            goto LAB_00018780;
          }
        }
        else if ((param_3 == (undefined *)0x8a7f) && (*param_4 < 2)) {
          uVar9 = (*param_4 & 1) << 6 | *(uint *)(iVar7 + 0x6c) & 0xffffffbf;
          goto LAB_00018448;
        }
LAB_00018768:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return iVar7;
        }
        uVar8 = 0x500;
        goto LAB_00018778;
      }
      if (param_3 == (undefined *)0x84fe) {
        if ((int)*param_4 < 1) {
LAB_00018554:
          if (*(int *)(param_1 + 0x7574) != 0) {
            return iVar7;
          }
          uVar8 = 0x501;
          goto LAB_00018778;
        }
        *(float *)(iVar7 + 0x50) =
             (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
      }
      else if (param_3 < (undefined *)0x84ff) {
        if (param_3 == (undefined *)0x813d) {
          if ((int)*param_4 < 0) goto LAB_00018554;
          uVar8 = 1;
          *(short *)(iVar7 + 0x62) = (short)*param_4;
        }
        else {
          if ((param_3 != (undefined *)0x8191) || (1 < *param_4)) goto LAB_00018768;
          uVar9 = (*param_4 & 1) << 0xf | *(uint *)(iVar7 + 0x6c) & 0xffff7fff;
LAB_00018448:
          *(uint *)(iVar7 + 0x6c) = uVar9;
        }
      }
      else if (param_3 == (undefined *)0x8501) {
        *(float *)(iVar7 + 0x5c) =
             (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58);
      }
      else {
        if (param_3 != (undefined *)0x85b6) goto LAB_00018768;
        *(uint *)(iVar7 + 0x6c) =
             (uint)(*param_4 != 0) * 0x80 | *(uint *)(iVar7 + 0x6c) & 0xffffff7f;
      }
    }
LAB_00018780:
    iVar7 = ((int (*)())_gleModifyPluginTexture)(param_1,iVar7,uVar8);
    *(uint *)(param_1 + 0x314) =
         *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar7;
    }
    uVar8 = 0x502;
LAB_00018778:
    *(undefined4 *)(param_1 + 0x7574) = uVar8;
  }
  return iVar7;
}

/* _gleModifyPluginTexture @ 0x187b8 (368 bytes) */
int _gleModifyPluginTexture(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  
  uVar7 = 0;
  if (param_3 != 0) {
    uVar7 = ((int (*)())_gleResetLevels)(param_1,param_2,0);
  }
  iVar8 = param_1 + 0x10000;
  iVar9 = 0;
  puVar10 = param_2;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar4 = (int *)(iVar8 + -0x777c);
      iVar9 = iVar9 + 1;
      puVar1 = (undefined4 *)(iVar8 + -0x7a54);
      iVar8 = iVar8 + 0x2e0;
      (**(code **)(*piVar4 + 0x154))(*puVar1,*puVar10,uVar7 | 0x80);
      puVar10 = puVar10 + 1;
    } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  if (param_3 != 0) {
    uVar7 = (uint)*(byte *)(param_2 + 0x24);
    iVar8 = 0;
    if (uVar7 != 0) {
      uVar2 = (uint)*(byte *)((int)param_2 + 0x8f);
      iVar9 = 0;
      do {
        uVar5 = (uint)*(byte *)((int)param_2 + 0x8d);
        if (uVar5 < uVar2) {
          piVar4 = (int *)((int)param_2 + uVar5 * 0x18 + iVar9 + 0xc4);
          do {
            if ((*(byte *)((int)piVar4 + 0xb) & 0x80) != 0) {
              iVar6 = 0;
              iVar3 = *(int *)(param_1 + 0x744c) + 0x10;
              *(undefined4 *)(*(int *)(param_1 + 0x744c) + 0xec) = 1;
              if (*(char *)(param_1 + 0x85a4) != '\0') {
                do {
                  *(undefined4 *)(iVar3 + 0xf8) = 1;
                  iVar6 = iVar6 + 1;
                  *(undefined4 *)(iVar3 + 0xfc) = 0;
                  iVar3 = iVar3 + 0x20;
                } while (iVar6 < (int)(uint)*(byte *)(param_1 + 0x85a4));
              }
              *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
            }
            uVar5 = uVar5 + 1;
            *piVar4 = *piVar4 + 1;
            piVar4 = piVar4 + 6;
            uVar2 = (uint)*(byte *)((int)param_2 + 0x8f);
          } while ((int)uVar5 < (int)uVar2);
          uVar7 = (uint)*(byte *)(param_2 + 0x24);
        }
        iVar8 = iVar8 + 1;
        iVar9 = iVar9 + 0x168;
      } while (iVar8 < (int)uVar7);
    }
  }
  return;
}

/* _glTexImage2D_Exec @ 0x18928 (916 bytes) */
int _glTexImage2D_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  int param_10;
{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  double dVar10;
  
  iVar6 = param_1;
  if (-1 < *(short *)(param_1 + 0x4a10)) goto LAB_00018a8c;
  if ((param_10 == 0) && (*(char *)(param_1 + 0x31e6) != '\0')) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar3 = 0x501;
    goto LAB_00018a9c;
  }
  iVar7 = *(int *)(param_1 + 0x4a6c);
  if (iVar7 != 0) {
    iVar5 = _gleOffsetLimitImage(param_1 + 0x31cc,param_5,param_6,param_8,param_9,param_10);
    iVar8 = *(int *)(iVar7 + 0x38);
    dVar10 = (double)((double (*)())_gleBytesPerElement)(param_9);
    iVar6 = (int)dVar10;
    if (iVar5 <= iVar8) {
      if (iVar6 == 0) {
        iVar6 = ((int (*)())_glePixelBytes)(param_8,param_9);
      }
      if (param_10 == (param_10 / iVar6) * iVar6) {
        if (*(int *)(iVar7 + 0x40) != 0) {
          _gleSynchronizePluginBuffer(param_1,iVar7 + 0x10);
        }
        param_10 = param_10 + *(int *)(iVar7 + 0x30);
        goto LAB_00018a2c;
      }
    }
LAB_00018a8c:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar6;
    }
    uVar3 = 0x502;
LAB_00018a9c:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
    return iVar6;
  }
LAB_00018a2c:
  iVar6 = ((int (*)())_gleCheckTexImage2DArgs)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  if (iVar6 == 0) {
    return 0;
  }
  uVar2 = *(ushort *)(iVar6 + 0x24);
  if ((uVar2 & 0x3c00) != 0x1000) {
    if ((uVar2 & 0x3c00) == 0) {
      *(ushort *)(iVar6 + 0x24) = uVar2 | 0x1000;
    }
    else if ((uVar2 & 0xc00) != 0) goto LAB_00018a8c;
  }
  iVar7 = param_6;
  iVar5 = param_5;
  if ((*(uint *)(param_1 + 0x3410) & 2) == 0) {
    if (((*(uint *)(param_1 + 0x3410) & 4) == 0) || (*(short *)(param_1 + 0x3348) != -0x7fea))
    goto LAB_00018b08;
    iVar7 = *(int *)(param_1 + 0x3354);
    iVar5 = *(int *)(param_1 + 0x3350);
  }
  else {
    if (*(short *)(param_1 + 0x3308) != -0x7fea) goto LAB_00018b08;
    iVar7 = *(int *)(param_1 + 0x3314);
    iVar5 = *(int *)(param_1 + 0x3310);
  }
  iVar7 = (param_6 - iVar7) + 1;
  iVar5 = (param_5 - iVar5) + 1;
LAB_00018b08:
  uVar4 = param_2 - 0x8515;
  if (5 < uVar4) {
    uVar4 = 0;
  }
  iVar8 = iVar6 + uVar4 * 0x168 + param_3 * 0x18;
  iVar9 = iVar8 + 0xc4;
  if ((*(byte *)(iVar8 + 0xcf) & 0x20) != 0) {
    _gleDeletePluginTextureLevel(param_1,iVar6,iVar9,uVar4,param_3);
    if (*(int *)(iVar8 + 0xd8) != 0) {
      bVar1 = *(byte *)(iVar8 + 0xcf);
      if ((bVar1 & 1) == 0) {
        _gleFreeTextureLevel(param_1,iVar6,iVar9);
        bVar1 = *(byte *)(iVar8 + 0xcf);
      }
      else {
        *(undefined4 *)(iVar8 + 0xd8) = 0;
      }
      *(byte *)(iVar8 + 0xcf) = bVar1 & 0xef;
    }
    *(byte *)(iVar8 + 0xcf) = *(byte *)(iVar8 + 0xcf) & 0xdf;
  }
  iVar8 = ((int (*)())_gleCreateTextureLevel)(param_1,iVar6,iVar9,param_4,iVar5,iVar7,1,param_7,param_8,param_9,1,param_10);
  if ((iVar8 != 0) && (param_10 != 0)) {
    iVar8 = ((int (*)())_gleTextureImagePut)(param_1,iVar9,0,0,0,param_5,param_6,1,param_8,param_9,1,
                                param_1 + 0x31cc,param_10);
  }
  if ((((iVar5 != 0) && (iVar7 != 0)) &&
      (iVar8 = ((int (*)())_gleCreatePluginTextureLevel)(param_1,iVar6,iVar9,uVar4,param_3,param_4),
      (*(uint *)(iVar6 + 0x6c) & 0x8000) != 0)) &&
     ((*(short *)(iVar6 + 0x60) == param_3 &&
      (iVar6 = _gleGenMipmapsToLevel(param_1,iVar6,uVar4,param_3,0xf,1), iVar8 = 0, iVar6 != 0)))) {
    return iVar6;
  }
  *(uint *)(param_1 + 0x314) =
       *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
  return iVar8;
}

/* _gleCheckTexImage2DArgs @ 0x18cbc (504 bytes) */
int _gleCheckTexImage2DArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  int param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar3 = ((int (*)())_gleLookUpTexture2D)(param_1,param_2);
  uVar7 = 1;
  uVar6 = 1;
  if (iVar3 == 0) {
    if (*(int *)(param_1 + 0x7574) == 0) {
      uVar6 = 0x500;
LAB_00018e64:
      *(undefined4 *)(param_1 + 0x7574) = uVar6;
    }
LAB_00018e68:
    iVar2 = 0;
  }
  else {
    if ((*(uint *)(param_1 + 0x3410) & 2) == 0) {
      if (((*(uint *)(param_1 + 0x3410) & 4) != 0) && (*(short *)(param_1 + 0x3348) == -0x7fea)) {
        iVar5 = *(int *)(param_1 + 0x3354);
        iVar2 = *(int *)(param_1 + 0x3350);
        goto LAB_00018d64;
      }
    }
    else if (*(short *)(param_1 + 0x3308) == -0x7fea) {
      iVar5 = *(int *)(param_1 + 0x3314);
      iVar2 = *(int *)(param_1 + 0x3310);
LAB_00018d64:
      param_5 = (param_5 - iVar2) + 1;
      param_6 = (param_6 - iVar5) + 1;
    }
    uVar8 = param_6 + param_7 * -2;
    uVar9 = param_5 + param_7 * -2;
    uVar1 = *(ushort *)(iVar3 + 0x24) & 0xf;
    if (uVar1 == 2) {
      uVar6 = 0;
      if ((((int)uVar9 < 0) ||
          (uVar4 = (uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xc0), (int)uVar4 < (int)uVar9))
         || ((int)uVar8 < 0)) goto LAB_00018e54;
LAB_00018e50:
      if ((int)uVar4 < (int)uVar8) {
LAB_00018e54:
        if (*(int *)(param_1 + 0x7574) == 0) {
          uVar6 = 0x501;
          goto LAB_00018e64;
        }
        goto LAB_00018e68;
      }
    }
    else if (uVar1 < 3) {
      if ((*(ushort *)(iVar3 + 0x24) & 0xf) == 0) {
        uVar7 = 0;
        if ((uVar9 != uVar8) ||
           ((int)(uint)*(ushort *)(*(int *)(param_1 + 0x468c) + 0xc2) < (int)uVar8))
        goto LAB_00018e54;
LAB_00018dc8:
        if (-1 < (int)uVar9) {
          if ((uVar9 & uVar9 - 1) == 0) {
            iVar2 = *(int *)(param_1 + 0x468c);
          }
          else {
            iVar2 = *(int *)(param_1 + 0x468c);
            if ((*(uint *)(iVar2 + 0x124) & 0x80000) == 0) goto LAB_00018e54;
          }
          uVar4 = (uint)*(ushort *)(iVar2 + 0xbc);
          if ((((int)uVar9 <= (int)uVar4) && (-1 < (int)uVar8)) &&
             (((uVar8 & uVar8 - 1) == 0 || ((*(uint *)(iVar2 + 0x124) & 0x80000) != 0))))
          goto LAB_00018e50;
        }
        goto LAB_00018e54;
      }
    }
    else if (uVar1 == 3) goto LAB_00018dc8;
    iVar5 = ((int (*)())_gleCheckTexImageArgs)(param_1,param_3,param_8,param_9,param_4,param_7,uVar7,uVar6);
    iVar2 = 0;
    if (iVar5 != 0) {
      iVar2 = iVar3;
    }
  }
  return iVar2;
}

/* _gleLookUpTexture2D @ 0x18eb4 (244 bytes) */
int _gleLookUpTexture2D(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x53d4);
  if (param_2 == 0x8513) {
LAB_00018f60:
    iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5154);
  }
  else {
    if (param_2 < 0x8514) {
      if (param_2 == 0x8064) {
        iVar1 = *(int *)(param_1 + 0x52b4);
LAB_00018f90:
        return iVar1 + 0x10;
      }
      if (param_2 < 0x8065) {
        if (param_2 != 0xde1) {
          return 0;
        }
        iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x5160);
        goto LAB_00018f6c;
      }
      if (param_2 != 0x84f5) {
        if (param_2 != 0x84f7) {
          return 0;
        }
        iVar1 = *(int *)(param_1 + 0x52b0);
        goto LAB_00018f90;
      }
    }
    else {
      if (param_2 == 0x851b) {
        iVar1 = *(int *)(param_1 + 0x52a8);
        goto LAB_00018f90;
      }
      if (param_2 < 0x851c) {
        if (param_2 < 0x8515) {
          return 0;
        }
        goto LAB_00018f60;
      }
      if (param_2 != 0x85b3) {
        return 0;
      }
    }
    iVar1 = *(int *)(iVar1 * 0x14 + param_1 + 0x515c);
  }
LAB_00018f6c:
  return iVar1 + 0x10;
}

/* _gleCheckTexImageArgs @ 0x18fa8 (648 bytes) */
int _gleCheckTexImageArgs(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  uint param_6;
  int param_7;
  int param_8;
{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = ((int (*)())_gleCheckTexSubImageArgs)(param_1,param_2,param_3,param_4);
  bVar6 = false;
  bVar2 = false;
  if (iVar5 == 0) {
    return 0;
  }
  if (param_5 < 0x83f4) {
    if (param_5 < 0x83f0) {
      if (param_5 < 0x804e) {
        if (param_5 < 0x803b) {
          if (param_5 == 0x1902) goto LAB_0001917c;
          if (param_5 < 0x1903) {
            bVar1 = 3 < param_5 - 1U;
            goto LAB_0001916c;
          }
          if (param_5 < 0x1906) goto LAB_000191c8;
          if (0x190a < param_5) {
            bVar1 = param_5 == 0x2a10;
            goto LAB_00019104;
          }
        }
        goto LAB_00019188;
      }
      if (param_5 < 33000) {
        if (param_5 < 0x80e2) {
          uVar4 = param_5 - 0x804f;
          goto LAB_00019144;
        }
        bVar2 = true;
        goto LAB_00019188;
      }
      if (2 < param_5 - 0x81a5U) goto LAB_000191c8;
LAB_0001917c:
      bVar6 = true;
      if (param_7 != 0) goto LAB_00019188;
    }
    else {
LAB_00019188:
      if (bVar6 == (param_3 == 0x1902)) {
        if ((param_8 != 0) || ((!bVar2 && (param_3 != 0x1900)))) {
          if (((param_6 & 0xfffffffe) == 0) && ((param_6 == 0 || (param_3 != 0x85b9)))) {
            return 1;
          }
          if (*(int *)(param_1 + 0x7574) != 0) {
            return 0;
          }
          uVar3 = 0x501;
          goto LAB_0001920c;
        }
        goto LAB_000191c8;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar3 = 0x502;
  }
  else {
    if (param_5 < 0x8700) {
      if (param_5 < 0x86fe) {
        if (0x86f6 < param_5) {
          bVar1 = 4 < param_5 - 0x86f8U;
          goto LAB_0001916c;
        }
        if (param_5 < 0x86f4) {
          if (param_5 < 0x84e9) goto LAB_000191c8;
          if (0x84ee < param_5) {
            bVar1 = param_5 == 0x86dc;
LAB_00019104:
            if (!bVar1) goto LAB_000191c8;
          }
        }
      }
      goto LAB_00019188;
    }
    if (0x881f < param_5) {
      if (param_5 != 0x8837) {
        if (param_5 < 0x8837) goto LAB_000191c8;
        bVar1 = 1 < param_5 - 0x885eU;
        goto LAB_0001916c;
      }
      goto LAB_00019188;
    }
    if (0x8813 < param_5) goto LAB_00019188;
    uVar4 = param_5 - 0x8701;
LAB_00019144:
    bVar1 = 0xc < uVar4;
LAB_0001916c:
    if (!bVar1) goto LAB_00019188;
LAB_000191c8:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar3 = 0x500;
  }
LAB_0001920c:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return 0;
}

/* _gleCheckTexSubImageArgs @ 0x19230 (380 bytes) */
int _gleCheckTexSubImageArgs(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_4 < 0x8365) {
    if (0x8361 < param_4) {
LAB_00019314:
      bVar1 = param_3 == 0x1907;
      goto LAB_0001933c;
    }
    if (param_4 == 0x1a00) {
      bVar1 = param_3 == 0x1900;
LAB_00019368:
      if (bVar1) goto LAB_00019380;
LAB_0001936c:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0;
      }
      uVar3 = 0x500;
      goto LAB_0001939c;
    }
    if (0x1a00 < param_4) {
      if (param_4 == 0x8032) goto LAB_00019314;
      if (0x8031 < param_4) {
        bVar1 = 0x8036 < param_4;
        goto LAB_000192a0;
      }
      goto LAB_0001936c;
    }
    if ((param_4 < 0x1400) || ((0x1406 < param_4 && (param_4 != 0x140b)))) goto LAB_0001936c;
    if (param_3 != 0x8000) {
      if (param_3 < 0x8001) {
        if (param_3 != 0x1900) {
          if (0x18ff < param_3) {
            bVar1 = 8 < param_3 - 0x1902;
LAB_0001930c:
            if (!bVar1) goto LAB_00019380;
          }
          goto LAB_0001936c;
        }
      }
      else {
        if (param_3 < 0x80e0) goto LAB_0001936c;
        if (0x80e1 < param_3) {
          bVar1 = 3 < param_3 - 0x86f4;
          goto LAB_0001930c;
        }
      }
    }
  }
  else {
    if (0x85bb < param_4) {
      if (param_4 - 0x86da < 2) {
        bVar1 = param_3 == 0x86f7;
        goto LAB_00019368;
      }
      goto LAB_0001936c;
    }
    if (param_4 < 0x85ba) {
      bVar1 = 0x8368 < param_4;
LAB_000192a0:
      if (bVar1) goto LAB_0001936c;
      if (param_3 == 0x1908) goto LAB_00019380;
      uVar2 = 0x80e1;
    }
    else {
      uVar2 = 0x85b9;
    }
    bVar1 = param_3 == uVar2;
LAB_0001933c:
    if (!bVar1) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0;
      }
      uVar3 = 0x502;
      goto LAB_0001939c;
    }
  }
LAB_00019380:
  if (param_2 < 0xf) {
    return 1;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0;
  }
  uVar3 = 0x501;
LAB_0001939c:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return 0;
}

/* _gleCreateTextureLevel @ 0x193ac (776 bytes) */
int _gleCreateTextureLevel(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int param_1;
  int param_2;
  int *param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  undefined4 param_8;
  int param_9;
  undefined4 param_10;
  int param_11;
  int param_12;
{
  byte bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  uint local_60;
  undefined1 auStack_5c [4];
  uint local_58;
  undefined1 auStack_54 [4];
  uint local_50;
  int local_4c [5];
  
  bVar1 = *(byte *)((int)param_3 + 0xb);
  if ((bVar1 & 0x80) != 0) {
    iVar4 = 0;
    iVar3 = *(int *)(param_1 + 0x744c) + 0x10;
    *(undefined4 *)(*(int *)(param_1 + 0x744c) + 0xec) = 1;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      do {
        *(undefined4 *)(iVar3 + 0xf8) = 1;
        iVar4 = iVar4 + 1;
        *(undefined4 *)(iVar3 + 0xfc) = 0;
        iVar3 = iVar3 + 0x20;
      } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  *param_3 = *param_3 + 1;
  if (((param_5 != 0) && (param_6 != 0)) && (param_7 != 0)) {
    uVar6 = (undefined2)param_5;
    uVar5 = (undefined2)param_6;
    if ((*(ushort *)(param_2 + 0x24) & 0x100) != 0) {
      param_3[5] = 0;
      *(undefined2 *)(param_3 + 1) = uVar6;
      *(undefined2 *)((int)param_3 + 6) = uVar5;
      *(short *)(param_3 + 2) = (short)param_7;
      *(undefined1 *)((int)param_3 + 0xb) = 0x20;
      *(char *)((int)param_3 + 10) = (char)param_8;
      *(short *)(param_3 + 4) = (short)param_9;
      *(short *)((int)param_3 + 0x12) = (short)param_10;
      *(undefined2 *)((int)param_3 + 0xe) = 0;
      goto LAB_00019690;
    }
    if ((((param_11 == 0) || ((param_9 == 0x1900 && (5 < param_4 - 0x80e2U)))) ||
        (*(char *)(param_1 + 0x31e6) == '\0')) ||
       ((*(char *)(param_1 + 0x31e4) != '\0' || ((*(uint *)(param_1 + 0x3410) & 0x1ff) != 0)))) {
LAB_000195c0:
      param_11 = 0;
      bVar2 = true;
    }
    else {
      bVar2 = (*(uint *)(param_1 + 0x3414) & 0xff0000) == 0;
      if ((!bVar2) || ((*(uint *)(param_1 + 0x3414) & 0xff1) != 0)) goto LAB_000195c0;
      ((void (*)())_glePixelPackSettings)(param_1,param_9,param_10,param_5,param_6,param_1 + 0x31cc,&local_50,local_4c,
                 &local_60,auStack_5c,&local_58,auStack_54);
      if (local_60 == (local_60 / local_50) * local_50) {
        param_12 = param_12 + local_4c[0];
        *(undefined1 *)((int)param_3 + 0xb) = 0x31;
        if ((bVar1 & 0x80) != 0) {
          *(undefined1 *)((int)param_3 + 0xb) = 0xb1;
        }
        *(short *)(param_3 + 3) = (short)(local_60 / local_50);
        param_3[5] = param_12;
        *(short *)(param_3 + 4) = (short)param_9;
        *(short *)((int)param_3 + 0x12) = (short)param_10;
        *(short *)((int)param_3 + 0xe) = (short)(local_58 / local_60);
        bVar2 = false;
      }
      else {
        param_11 = 0;
      }
    }
    *(undefined2 *)(param_3 + 1) = uVar6;
    *(undefined2 *)((int)param_3 + 6) = uVar5;
    *(short *)(param_3 + 2) = (short)param_7;
    *(char *)((int)param_3 + 10) = (char)param_8;
    if (!bVar2) {
      return 1;
    }
    *(undefined1 *)((int)param_3 + 0xb) = 0x20;
    if ((bVar1 & 0x80) != 0) {
      *(undefined1 *)((int)param_3 + 0xb) = 0xa0;
    }
    *(undefined2 *)(param_3 + 3) = uVar6;
    *(undefined2 *)((int)param_3 + 0xe) = uVar5;
    param_3[5] = param_11;
    _gleTexLevelStorage(param_1,param_4,param_9,param_10,param_3 + 4,(int)param_3 + 0x12,param_8);
    if (param_12 == 0) {
      return 1;
    }
    iVar3 = _gleAllocateTextureLevel(param_1,param_2,param_3);
    if (iVar3 != 0) {
      *(byte *)((int)param_3 + 0xb) = *(byte *)((int)param_3 + 0xb) | 0x10;
      return 1;
    }
  }
  param_3[5] = 0;
  *(undefined2 *)((int)param_3 + 0xe) = 0;
  *(undefined2 *)(param_3 + 1) = 0;
  *(undefined2 *)((int)param_3 + 6) = 0;
  *(undefined2 *)(param_3 + 2) = 0;
  *(undefined1 *)((int)param_3 + 10) = 0;
  *(undefined1 *)((int)param_3 + 0xb) = 0;
  *(undefined2 *)(param_3 + 4) = 0;
  *(undefined2 *)((int)param_3 + 0x12) = 0;
LAB_00019690:
  *(undefined2 *)(param_3 + 3) = 0;
  return 0;
}

/* _glePixelPackSettings @ 0x196b4 (376 bytes) */
void _glePixelPackSettings(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  int *param_6;
  int *param_7;
  int *param_8;
  uint *param_9;
  int *param_10;
  int *param_11;
  int *param_12;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = ((int (*)())_glePixelBytes)(param_2,param_3);
  *param_7 = iVar1;
  uVar2 = ((int (*)())_gleRowBytes)(param_2,param_3,param_4);
  if (param_6 == (int *)0x0) {
    *param_9 = uVar2;
    *param_8 = 0;
    *param_10 = 0;
    *param_12 = 0;
  }
  else {
    iVar5 = *param_6;
    if (iVar5 == 0) {
      *param_9 = uVar2;
      iVar1 = 0;
      uVar4 = uVar2;
    }
    else {
      if (param_3 == 0x1a00) {
        iVar1 = ((int (*)())_gleComponents)(param_2);
        *param_9 = iVar5 * iVar1 + 7 >> 3;
      }
      else {
        *param_9 = iVar5 * iVar1;
      }
      uVar4 = *param_9;
      iVar1 = uVar4 - uVar2;
    }
    uVar2 = param_6[5];
    iVar3 = 0;
    iVar5 = uVar4 - (uVar4 / uVar2) * uVar2;
    if (iVar5 != 0) {
      iVar3 = uVar2 - iVar5;
      *param_9 = uVar4 + iVar3;
    }
    *param_10 = iVar1 + iVar3;
    if (param_6[1] == 0) {
      iVar1 = param_5 * *param_9;
    }
    else {
      iVar1 = param_6[1] * *param_9;
    }
    *param_11 = iVar1;
    *param_12 = *param_11 - param_5 * *param_9;
    *param_8 = param_6[3] * *param_7 + param_6[2] * *param_9 + param_6[4] * *param_11;
  }
  return;
}

/* _glePixelBytes @ 0x1982c (400 bytes) */
int _glePixelBytes(param_1, param_2)
  uint param_1;
  uint param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  if (param_2 == 0x8032) {
    return 1;
  }
  if (0x8032 < param_2) {
    if (param_2 < 0x8367) {
      if (param_2 < 0x8363) {
        if (param_2 < 0x8037) {
          if (param_2 < 0x8035) {
            return 2;
          }
        }
        else if (param_2 == 0x8362) {
          return 1;
        }
        return 4;
      }
    }
    else {
      if (0x85bb < param_2) {
        return 4;
      }
      if (param_2 < 0x85ba) {
        return 4;
      }
    }
    return 2;
  }
  if (0x1401 < param_2) {
    if (param_2 < 0x1407) {
      if (0x1403 < param_2) {
        iVar2 = ((int (*)())_gleComponents)(param_1);
        return iVar2 << 2;
      }
    }
    else if (param_2 != 0x140b) {
      if (param_2 != 0x1a00) {
        return 4;
      }
      return 0;
    }
    iVar2 = ((int (*)())_gleComponents)(param_1);
    return iVar2 << 1;
  }
  if (0x13ff < param_2) {
    uVar1 = ((int (*)())_gleComponents)(param_1);
    return uVar1;
  }
  if (param_2 == 1) {
    return 4;
  }
  if (param_2 == 0) {
    if (param_1 == 0x84ea) {
      return 8;
    }
    if (param_1 < 0x84eb) {
      if (param_1 < 0x83f0) {
        return 0;
      }
      if (param_1 < 0x83f2) {
        return 8;
      }
      if (0x83f3 < param_1) {
        return 0;
      }
    }
    else if (param_1 < 0x84ee) {
      if (0x84eb < param_1) {
        return 8;
      }
    }
    else if ((param_1 != 0x84ee) && (param_1 != 0x8837)) {
      return 0;
    }
    return 0x10;
  }
  return 4;
}

/* _gleRowBytes @ 0x199bc (108 bytes) */
int _gleRowBytes(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = ((int (*)())_glePixelBytes)(param_1,0);
    iVar1 = iVar1 * (param_3 + 3 >> 2) >> 2;
  }
  else if (param_2 == 0x1a00) {
    iVar1 = ((int (*)())_gleComponents)(param_1);
    iVar1 = param_3 * iVar1 + 7 >> 3;
  }
  else {
    iVar1 = ((int (*)())_glePixelBytes)(param_1,param_2);
    iVar1 = iVar1 * param_3;
  }
  return iVar1;
}

/* _gleTextureImagePut @ 0x19a28 (300 bytes) */
int _gleTextureImagePut(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
  int param_9;
  int param_10;
  uint param_11;
  int param_12;
  undefined4 param_13;
{
  int iVar1;
  
  if ((param_10 != 0x1a00) && ((param_9 != 0x1900 || (*(short *)(param_2 + 0x10) == 0x1900)))) {
    if ((*(uint *)(param_1 + 0x3414) & 0xff1) == 0) {
      if ((param_11 & 0xff) == 1) {
        if (((*(uint *)(param_1 + 0x3410) & 0x1ff) != 0) ||
           ((*(uint *)(param_1 + 0x3414) & 0xff0000) != 0)) goto LAB_00019af8;
      }
      if (((param_12 == 0) || (*(char *)(param_12 + 0x18) == '\0')) &&
         ((param_8 == 1 && (param_5 == 0)))) {
        iVar1 = ((int (*)())_gleTextureImagePut_Fast)(param_1,param_2,param_3,param_4,param_6,param_7,param_9,param_10,param_12
                           ,param_13);
        if (iVar1 != 0) {
          return;
        }
      }
    }
  }
LAB_00019af8:
  _gleTextureImagePut_Slow
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
             param_11 & 0xff,param_12,param_13);
  return;
}

/* _gleTextureImagePut_Fast @ 0x19b54 (900 bytes) */
int _gleTextureImagePut_Fast(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  uint param_7;
  uint param_8;
  undefined4 param_9;
  int param_10;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int local_60;
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [4];
  undefined1 auStack_54 [4];
  int local_50;
  int local_4c [6];
  
  iVar2 = ((int (*)())_gleComponents)((uint)*(ushort *)(param_2 + 0x10));
  iVar3 = ((int (*)())_glePixelBytes)((uint)*(ushort *)(param_2 + 0x10),(uint)*(ushort *)(param_2 + 0x12));
  iVar6 = iVar2 * (uint)*(ushort *)(param_2 + 0xc);
  iVar4 = ((int (*)())_gleRowBytes)((uint)*(ushort *)(param_2 + 0x10),(uint)*(ushort *)(param_2 + 0x12),
                       (uint)*(ushort *)(param_2 + 0xc));
  iVar7 = *(int *)(param_2 + 0x14) + iVar3 * ((uint)*(ushort *)(param_2 + 0xc) * param_4 + param_3);
  ((void (*)())_glePixelPackSettings)(param_1,param_7,param_8,param_5,param_6,param_9,&local_50,local_4c,&local_60,auStack_5c
             ,auStack_58,auStack_54);
  iVar3 = ((int (*)())_gleComponents)(param_7);
  local_4c[0] = param_10 + local_4c[0];
  iVar2 = iVar6 - iVar2 * param_5;
  iVar3 = iVar3 * param_5;
  if ((local_4c[0] == iVar7) && (local_60 == iVar4)) {
    return 1;
  }
  if (param_8 == 0x140b) {
LAB_00019e6c:
    if ((*(ushort *)(param_2 + 0x10) == param_7) && (*(ushort *)(param_2 + 0x12) == param_8)) {
      _gleCopy(local_4c[0],iVar7,param_5 * local_50,param_6,local_60,iVar4);
      return 1;
    }
    return 0;
  }
  if (param_8 < 0x140c) {
    if (param_8 == 0x1403) {
      if (*(short *)(param_2 + 0x12) == 0x1401) {
        uVar5 = _gleTextureImagePut_FastUshort
                          (param_1,param_5,param_6,local_4c[0],iVar7,local_60,iVar3,iVar2,iVar6,
                           (uint)*(ushort *)(param_2 + 0x10),param_7);
        return uVar5;
      }
      return 0;
    }
    if (param_8 < 0x1404) {
      if (param_8 == 0x1401) {
        if (*(short *)(param_2 + 0x12) == 0x1401) {
          uVar5 = _gleTextureImagePut_FastUbyte
                            (param_1,param_5,param_6,local_4c[0],iVar7,local_60,iVar3,iVar2,iVar6,
                             (uint)*(ushort *)(param_2 + 0x10),param_7);
          return uVar5;
        }
        return 0;
      }
      if (0x1401 < param_8) {
        if (*(short *)(param_2 + 0x12) == 0x1401) {
          uVar5 = _gleTextureImagePut_FastShort
                            (param_1,param_5,param_6,local_4c[0],iVar7,local_60,iVar3,iVar2,iVar6,
                             (uint)*(ushort *)(param_2 + 0x10),param_7);
          return uVar5;
        }
        return 0;
      }
      if (param_8 == 0x1400) {
        if (*(short *)(param_2 + 0x12) == 0x1401) {
          uVar5 = _gleTextureImagePut_FastByte
                            (param_1,param_5,param_6,local_4c[0],iVar7,local_60,iVar3,iVar2,iVar6,
                             (uint)*(ushort *)(param_2 + 0x10),param_7);
          return uVar5;
        }
        return 0;
      }
    }
    else {
      if (param_8 == 0x1405) {
        if (*(short *)(param_2 + 0x12) == 0x1401) {
          uVar5 = _gleTextureImagePut_FastUint
                            (param_1,param_5,param_6,local_4c[0],iVar7,local_60,iVar3,iVar2,iVar6,
                             (uint)*(ushort *)(param_2 + 0x10),param_7);
          return uVar5;
        }
        return 0;
      }
      if (param_8 < 0x1405) {
        if (*(short *)(param_2 + 0x12) == 0x1401) {
          uVar5 = _gleTextureImagePut_FastInt
                            (param_1,param_5,param_6,local_4c[0],iVar7,local_60,iVar3,iVar2,iVar6,
                             (uint)*(ushort *)(param_2 + 0x10),param_7);
          return uVar5;
        }
        return 0;
      }
      if (param_8 == 0x1406) goto LAB_00019e6c;
    }
  }
  else {
    if (param_8 < 0x8369) {
      if (0x8361 < param_8) goto LAB_00019e6c;
      bVar1 = 4 < param_8 - 0x8032;
    }
    else {
      if (param_8 < 0x85ba) goto LAB_00019eac;
      if (param_8 < 0x85bc) goto LAB_00019e6c;
      bVar1 = 1 < param_8 - 0x86da;
    }
    if (!bVar1) goto LAB_00019e6c;
  }
LAB_00019eac:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x500;
  return 0;
}

/* _gleComponents @ 0x19ed8 (228 bytes) */
int _gleComponents(param_1)
  uint param_1;
{
  uint uVar1;
  
  if (param_1 == 0x8049) {
    return 1;
  }
  if (param_1 < 0x804a) {
    if (param_1 != 0x1908) {
      if (param_1 < 0x1909) {
        if (0x18ff < param_1) {
          if (0x1906 < param_1) {
            return 3;
          }
          return 1;
        }
      }
      else {
        if (param_1 == 0x190a) {
          return 2;
        }
        if (param_1 < 0x190a) {
          return 1;
        }
      }
    }
  }
  else {
    if (param_1 == 0x86dc) {
      return 4;
    }
    if (param_1 < 0x86dd) {
      if (param_1 == 0x80e1) {
        return 4;
      }
      if (0x80e1 < param_1) {
        if (param_1 != 0x85b9) {
          return 4;
        }
        return 2;
      }
      uVar1 = 0x80e0;
    }
    else {
      if (param_1 < 0x86f4) {
        return 4;
      }
      if (param_1 < 0x86f6) {
        return 2;
      }
      uVar1 = 0x86f6;
    }
    if (param_1 == uVar1) {
      return 3;
    }
  }
  return 4;
}

/* _gleCreatePluginTextureLevel @ 0x19fbc (1228 bytes) */
int _gleCreatePluginTextureLevel(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
  uint param_5;
  uint param_6;
{
  int *piVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  undefined4 *puVar22;
  int iVar23;
  int iVar24;
  
  uVar8 = (uint)*(byte *)(param_3 + 10);
  uVar18 = (uint)*(byte *)((int)param_2 + 0x92);
  uVar17 = (uint)*(byte *)((int)param_2 + 0x93);
  iVar19 = (uint)*(ushort *)(param_3 + 4) + uVar8 * -2;
  bVar2 = *(byte *)(param_2 + 0x24);
  iVar15 = (uint)*(ushort *)(param_3 + 6) - uVar8 * uVar18;
  uVar20 = 0;
  iVar16 = (uint)*(ushort *)(param_3 + 8) - uVar8 * uVar17;
  if (param_5 == 0) {
    if (*(int *)(param_3 + 0x14) != 0) {
      uVar20 = 4;
    }
    if (*(char *)((int)param_2 + 0x91) == '\0') {
      uVar8 = 0x1f - LZCOUNT(iVar19);
      if (*(byte *)(param_2 + 0x21) != uVar8) {
        *(char *)(param_2 + 0x21) = (char)uVar8;
        uVar20 = uVar20 | 1;
      }
      if (uVar18 != 0) {
        uVar6 = 0x1f - LZCOUNT(iVar15);
        if ((int)uVar8 < (int)uVar6) {
          uVar8 = uVar6;
        }
        if (*(byte *)((int)param_2 + 0x85) != uVar6) {
          *(char *)((int)param_2 + 0x85) = (char)uVar6;
          uVar20 = uVar20 | 1;
        }
        if (uVar17 != 0) {
          uVar6 = 0x1f - LZCOUNT(iVar16);
          if ((int)uVar8 < (int)uVar6) {
            uVar8 = uVar6;
          }
          if (*(byte *)((int)param_2 + 0x86) != uVar6) {
            *(char *)((int)param_2 + 0x86) = (char)uVar6;
            uVar20 = uVar20 | 1;
          }
        }
      }
      *(char *)((int)param_2 + 0x87) = (char)uVar8;
    }
    else {
      uVar20 = uVar20 | 1;
      uVar8 = 1;
    }
    if ((uVar20 & 1) == 0) {
      *(ushort *)((int)param_2 + param_4 * 2 + 0x94) =
           *(ushort *)((int)param_2 + param_4 * 2 + 0x94) | 1;
      if (*(int *)(param_3 + 0x14) != 0) {
        *(ushort *)((int)param_2 + param_4 * 2 + 0xa0) =
             *(ushort *)((int)param_2 + param_4 * 2 + 0xa0) | 1;
      }
    }
    else {
      iVar21 = 0;
      if (bVar2 != 0) {
        iVar14 = 0;
        puVar11 = param_2;
        puVar22 = param_2;
        do {
          uVar6 = 0;
          *(undefined2 *)(puVar11 + 0x25) = 0;
          *(undefined2 *)(puVar11 + 0x28) = 0;
          if (-1 < (int)uVar8) {
            iVar5 = uVar8 + 1;
            iVar13 = (int)param_2 + iVar14 + 0xc4;
            iVar12 = iVar19;
            iVar23 = iVar16;
            iVar24 = iVar15;
            do {
              uVar9 = (uint)*(byte *)(iVar13 + 10);
              if ((((uint)*(ushort *)(iVar13 + 4) == iVar12 + uVar9 * 2) &&
                  ((uint)*(ushort *)(iVar13 + 6) == iVar24 + uVar9 * uVar18)) &&
                 ((uint)*(ushort *)(iVar13 + 8) == iVar23 + uVar9 * uVar17)) {
                uVar3 = (ushort)(1 << (uVar6 & 0x3f));
                *(ushort *)(puVar22 + 0x25) = *(ushort *)(puVar22 + 0x25) | uVar3;
                if (*(int *)(iVar13 + 0x14) != 0) {
                  *(ushort *)(puVar22 + 0x28) = *(ushort *)(puVar22 + 0x28) | uVar3;
                }
              }
              if (1 < iVar12) {
                iVar12 = iVar12 >> 1;
              }
              if (1 < iVar24) {
                iVar24 = iVar24 >> 1;
              }
              if (1 < iVar23) {
                iVar23 = iVar23 >> 1;
              }
              uVar6 = uVar6 + 1;
              iVar13 = iVar13 + 0x18;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
          }
          iVar21 = iVar21 + 1;
          puVar22 = (undefined4 *)((int)puVar22 + 2);
          puVar11 = (undefined4 *)((int)puVar11 + 2);
          iVar14 = iVar14 + 0x168;
        } while (iVar21 < (int)(uint)bVar2);
      }
    }
    if ((param_6 != *(ushort *)(param_2 + 0x1e)) || (*(int *)(param_3 + 0x10) != param_2[0x1f])) {
      *(short *)(param_2 + 0x1e) = (short)param_6;
      *(undefined2 *)(param_2 + 0x1f) = *(undefined2 *)(param_3 + 0x10);
      *(undefined2 *)((int)param_2 + 0x7e) = *(undefined2 *)(param_3 + 0x12);
      if (param_6 - 0x80e2 < 6) {
        param_6 = (uint)*(ushort *)((int)param_2 + 0x7a);
      }
      uVar7 = ((int (*)())_gleReqToBase)(param_6);
      uVar20 = uVar20 | 1;
      *(short *)((int)param_2 + 0x26) = (short)uVar7;
    }
    goto LAB_0001a408;
  }
  if ((int)param_5 < 1) {
    if (*(int *)(param_3 + 0x14) != 0) {
      uVar20 = 0x40;
    }
    if ((uint)*(byte *)(param_2 + 0x23) != 0x1fU - LZCOUNT(iVar19)) {
      *(char *)(param_2 + 0x23) = (char)(0x1fU - LZCOUNT(iVar19));
      uVar20 = uVar20 | 0x20;
    }
    if (param_6 != *(ushort *)((int)param_2 + 0x7a)) {
      *(short *)((int)param_2 + 0x7a) = (short)param_6;
      if ((ushort)(*(short *)(param_2 + 0x1e) + 0x7f1eU) < 6) {
        uVar7 = ((int (*)())_gleReqToBase)(param_6);
        *(short *)((int)param_2 + 0x26) = (short)uVar7;
      }
      uVar20 = uVar20 | 0x20;
    }
    goto LAB_0001a408;
  }
  if (*(int *)(param_3 + 0x14) != 0) {
    uVar20 = 4;
  }
  bVar4 = false;
  if (*(char *)((int)param_2 + 0x91) == '\0') {
    if (((0x1f - LZCOUNT(iVar19)) + param_5 == (uint)*(byte *)(param_2 + 0x21)) ||
       ((0x1f - LZCOUNT(iVar19) == 0 && ((int)(uint)*(byte *)(param_2 + 0x21) < (int)param_5)))) {
      bVar4 = false;
      if (uVar18 != 0) {
        if (((0x1f - LZCOUNT(iVar15)) + param_5 != (uint)*(byte *)((int)param_2 + 0x85)) &&
           ((0x1f - LZCOUNT(iVar15) != 0 ||
            ((int)param_5 <= (int)(uint)*(byte *)((int)param_2 + 0x85))))) goto LAB_0001a32c;
        bVar4 = false;
        if (uVar17 != 0) {
          if (((0x1f - LZCOUNT(iVar16)) + param_5 != (uint)*(byte *)((int)param_2 + 0x86)) &&
             ((0x1f - LZCOUNT(iVar16) != 0 ||
              ((int)param_5 <= (int)(uint)*(byte *)((int)param_2 + 0x86))))) goto LAB_0001a32c;
          bVar4 = false;
        }
      }
    }
    else {
LAB_0001a32c:
      bVar4 = true;
    }
  }
  uVar3 = (ushort)(1 << (param_5 & 0x3f));
  if (bVar4) {
    *(ushort *)((int)param_2 + param_4 * 2 + 0x94) =
         *(ushort *)((int)param_2 + param_4 * 2 + 0x94) & ~uVar3;
    *(ushort *)((int)param_2 + param_4 * 2 + 0xa0) =
         *(ushort *)((int)param_2 + param_4 * 2 + 0xa0) & ~uVar3;
  }
  else {
    *(ushort *)((int)param_2 + param_4 * 2 + 0x94) =
         uVar3 | *(ushort *)((int)param_2 + param_4 * 2 + 0x94);
    if (*(int *)(param_3 + 0x14) != 0) {
      *(ushort *)((int)param_2 + param_4 * 2 + 0xa0) =
           uVar3 | *(ushort *)((int)param_2 + param_4 * 2 + 0xa0);
    }
  }
LAB_0001a408:
  iVar16 = param_1 + 0x10000;
  uVar7 = ((int (*)())_gleResetLevels)(param_1,param_2,uVar20);
  iVar15 = 0;
  if (*(char *)(param_1 + 0x85a4) != '\0') {
    do {
      piVar1 = (int *)(iVar16 + -0x777c);
      uVar10 = *param_2;
      puVar11 = (undefined4 *)(iVar16 + -0x7a54);
      iVar16 = iVar16 + 0x2e0;
      iVar15 = iVar15 + 1;
      param_2 = param_2 + 1;
      (**(code **)(*piVar1 + 0x150))(*puVar11,uVar10,uVar7,param_4,param_5);
    } while (iVar15 < (int)(uint)*(byte *)(param_1 + 0x85a4));
  }
  return;
}

/* _gleReqToBase @ 0x1a488 (948 bytes) */
int _gleReqToBase(param_1)
  uint param_1;
{
  if (param_1 == 0x86f4) {
    return 0x86f4;
  }
  if (param_1 < 0x86f5) {
    if (0x804d < param_1) {
      if (param_1 == 0x83f0) {
        return 0x1907;
      }
      if (param_1 < 0x83f1) {
        if (0x805b < param_1) {
          if (param_1 < 0x80e2) {
            return param_1;
          }
          if (32999 < param_1) {
            if (param_1 - 0x81a5 < 3) {
              return 0x1902;
            }
            return param_1;
          }
          return 0x1900;
        }
        if (param_1 < 0x8055) {
          if (0x804e < param_1) {
            return 0x1907;
          }
          return param_1;
        }
      }
      else {
        if (param_1 == 0x84eb) {
          return 0x190a;
        }
        if (param_1 < 0x84ec) {
          if (param_1 == 0x84e9) {
            return 0x1906;
          }
          if (0x84e9 < param_1) {
            return 0x1909;
          }
          if (0x83f3 < param_1) {
            return param_1;
          }
        }
        else {
          if (param_1 == 0x84ed) {
            return 0x1907;
          }
          if (param_1 < 0x84ed) {
            return 0x8049;
          }
          if (param_1 != 0x84ee) {
            if (param_1 == 0x86dc) {
              return 0x86dc;
            }
            return param_1;
          }
        }
      }
      return 0x1908;
    }
    if (0x8049 < param_1) {
      return 0x8049;
    }
    if (param_1 < 0x190b) {
      if (0x1905 < param_1) {
        return param_1;
      }
      if (param_1 == 3) {
        return 0x1907;
      }
      if (3 < param_1) {
        if (param_1 == 0x1900) {
          return 0x1900;
        }
        if (0x1900 < param_1) {
          if (param_1 == 0x1902) {
            return 0x1902;
          }
          return param_1;
        }
        if (param_1 == 4) {
          return 0x1908;
        }
        return param_1;
      }
      if (param_1 == 1) {
        return 0x1909;
      }
      if (param_1 != 2) {
        return param_1;
      }
    }
    else {
      if (param_1 < 0x8043) {
        if (0x803e < param_1) {
          return 0x1909;
        }
        if (param_1 == 0x2a10) {
          return 0x1907;
        }
        if (param_1 < 0x2a10) {
          return param_1;
        }
        if (0x803a < param_1) {
          return 0x1906;
        }
        return param_1;
      }
      if (0x8048 < param_1) {
        return param_1;
      }
    }
  }
  else {
    if (param_1 == 0x870a) {
      return 0x86f6;
    }
    if (param_1 < 0x870b) {
      if (param_1 < 0x8703) {
        if (0x8700 < param_1) {
          return 0x1909;
        }
        if (0x86fa < param_1) {
          if (param_1 < 0x86fd) {
            return 0x1908;
          }
          if (param_1 - 0x86fe < 2) {
            return 0x1907;
          }
          return param_1;
        }
        if (0x86f7 < param_1) {
          return 0x86f4;
        }
        if (param_1 != 0x86f5) {
          if (param_1 == 0x86f6) {
            return 0x86f6;
          }
          return param_1;
        }
      }
      else {
        if (param_1 < 0x8707) {
          if (param_1 < 0x8705) {
            return 0x190a;
          }
          return 0x1906;
        }
        if (param_1 < 0x8709) {
          return 0x8049;
        }
      }
      return 0x86f5;
    }
    if (param_1 != 0x8819) {
      if (param_1 < 0x881a) {
        if (param_1 == 0x8814) {
          return 0x1908;
        }
        if (param_1 < 0x8815) {
          if (param_1 == 0x870b) {
            return 0x86dc;
          }
          if (param_1 < 0x870e) {
            return 0x1908;
          }
          return param_1;
        }
        if (param_1 == 0x8816) {
          return 0x1906;
        }
        if (param_1 < 0x8816) {
          return 0x1907;
        }
        if (param_1 == 0x8817) {
          return 0x8049;
        }
        if (param_1 == 0x8818) {
          return 0x1909;
        }
        return param_1;
      }
      if (param_1 == 0x881e) {
        return 0x1909;
      }
      if (param_1 < 0x881f) {
        if (param_1 == 0x881b) {
          return 0x1907;
        }
        if (param_1 < 0x881b) {
          return 0x1908;
        }
        if (param_1 == 0x881c) {
          return 0x1906;
        }
        if (param_1 == 0x881d) {
          return 0x8049;
        }
        return param_1;
      }
      if (param_1 != 0x8837) {
        if (0x8837 < param_1) {
          if (param_1 - 0x885e < 2) {
            return 0x86f4;
          }
          return param_1;
        }
        if (param_1 != 0x881f) {
          return param_1;
        }
      }
    }
  }
  return 0x190a;
}

/* _gleResetLevels @ 0x1a83c (1016 bytes) */
int _gleResetLevels(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint param_3;
{
  byte bVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  ushort *puVar11;
  ushort uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  
  uVar15 = (uint)*(short *)(param_2 + 0x60);
  uVar9 = (uint)*(byte *)(param_2 + 0x87);
  bVar4 = false;
  uVar13 = (uint)*(byte *)(param_2 + 0x90);
  uVar14 = (uint)*(short *)(param_2 + 0x62);
  uVar12 = *(ushort *)(param_2 + 0x3a);
  if ((uVar15 != 0) || (uVar14 != 1000)) {
    bVar4 = true;
  }
  if ((*(ushort *)(param_2 + 0x24) & 0x400) != 0) {
    uVar10 = 0;
    iVar19 = 0xf;
    uVar17 = 0;
    pbVar8 = (byte *)(param_2 + 0xcf);
    do {
      bVar1 = *pbVar8;
      pbVar8 = pbVar8 + 0x18;
      if ((bVar1 & 0x10) != 0) {
        uVar10 = uVar17;
      }
      uVar17 = uVar17 + 1;
      iVar19 = iVar19 + -1;
    } while (iVar19 != 0);
    if ((uVar10 != 0) && ((int)uVar10 < (int)uVar14)) {
      uVar14 = uVar10;
    }
  }
  if ((int)uVar9 < (int)uVar15) {
    uVar15 = uVar9;
  }
  uVar10 = uVar9;
  if (((int)uVar14 <= (int)uVar9) && (uVar10 = uVar14, (int)uVar14 < (int)uVar15)) {
    uVar10 = uVar15;
  }
  *(byte *)(param_2 + 0x8b) = *(byte *)(param_2 + 0x87) - (char)uVar15;
  iVar19 = *(byte *)(param_2 + 0x84) - uVar15;
  if (iVar19 < 0) {
    iVar19 = 0;
  }
  *(char *)(param_2 + 0x88) = (char)iVar19;
  iVar19 = *(byte *)(param_2 + 0x85) - uVar15;
  if (iVar19 < 0) {
    iVar19 = 0;
  }
  *(char *)(param_2 + 0x89) = (char)iVar19;
  iVar19 = *(byte *)(param_2 + 0x86) - uVar15;
  if (iVar19 < 0) {
    iVar19 = 0;
  }
  *(char *)(param_2 + 0x8a) = (char)iVar19;
  uVar14 = (uint)(-1 << ((0x1f - uVar10) + uVar15 & 0x3f)) >> (0x1f - uVar10 & 0x3f) | 1;
  uVar17 = 1 << (uVar15 & 0x3f) | 1;
  bVar7 = true;
  bVar5 = false;
  bVar3 = true;
  if (uVar13 != 0) {
    puVar11 = (ushort *)(param_2 + 0x94);
    uVar20 = uVar13;
    do {
      uVar2 = *puVar11;
      puVar11 = puVar11 + 1;
      if ((uVar2 & uVar14) != uVar14) {
        bVar7 = false;
      }
      if ((uVar2 & uVar17) != uVar17) {
        bVar3 = false;
      }
      if ((uVar2 & 0xfffe) != 0) {
        bVar5 = true;
      }
      uVar20 = uVar20 - 1;
    } while (uVar20 != 0);
    if (!bVar3) {
      uVar12 = 0;
    }
  }
  bVar3 = false;
  if ((0x2601 < uVar12) && (*(char *)(param_2 + 0x91) == '\0')) {
    bVar3 = true;
  }
  bVar6 = false;
  if (((bVar4) || (bVar3)) || (bVar5)) {
    bVar6 = true;
  }
  uVar14 = uVar15;
  if (bVar6) {
    if ((*(ushort *)(param_2 + 0x24) & 0x400) == 0) {
      uVar17 = *(uint *)(param_2 + 0x6c);
      if (((uVar17 & 0x80) == 0) && (*(char *)(*(int *)(param_1 + 0x468c) + 199) != '\0'))
      goto LAB_0001aa44;
    }
    else {
      uVar17 = *(uint *)(param_2 + 0x6c);
LAB_0001aa44:
      uVar14 = 0;
    }
    uVar20 = uVar10;
    if ((uVar17 & 0x80) == 0) {
      uVar20 = uVar9;
    }
    uVar9 = (uVar20 - uVar14) + 1;
  }
  else {
    uVar9 = 1;
  }
  if ((((param_3 & 1) != 0) || (uVar9 != *(byte *)(param_2 + 0x8e))) ||
     (uVar14 != *(byte *)(param_2 + 0x8d))) {
    iVar19 = 0;
    if (uVar13 != 0) {
      uVar17 = (uint)*(byte *)(param_2 + 0x8f);
      iVar16 = 0;
      do {
        uVar20 = (uint)*(byte *)(param_2 + 0x8d);
        if (uVar20 <= uVar17) {
          iVar18 = uVar20 * 0x18 + param_2 + iVar16 + 0xc4;
          do {
            if ((*(byte *)(iVar18 + 0xb) & 0x50) == 0x40) {
              _gleUploadPluginTextureLevel
                        (param_1,param_2,iVar18,iVar19,uVar20,(uint)*(byte *)(param_1 + 0x85a8));
              _gleModifyPluginTextureLevel
                        (param_1,param_2,iVar18,iVar19,uVar20,0,0,0,(uint)*(ushort *)(iVar18 + 4),
                         (uint)*(ushort *)(iVar18 + 6),(uint)*(ushort *)(iVar18 + 8));
              uVar17 = (uint)*(byte *)(param_2 + 0x8f);
            }
            uVar20 = uVar20 + 1;
            iVar18 = iVar18 + 0x18;
          } while ((int)uVar20 <= (int)uVar17);
        }
        iVar19 = iVar19 + 1;
        iVar16 = iVar16 + 0x168;
      } while (iVar19 < (int)uVar13);
    }
    *(char *)(param_2 + 0x8e) = (char)uVar9;
    *(char *)(param_2 + 0x8d) = (char)uVar14;
    *(char *)(param_2 + 0x8f) = (char)uVar14 + (char)uVar9 + -1;
    param_3 = param_3 | 2;
  }
  bVar4 = false;
  if (((bVar3) && (bVar7)) || ((*(uint *)(param_2 + 0x6c) & 0x8000) != 0)) {
    bVar4 = true;
  }
  if ((bVar4) || (uVar10 = uVar15, 0x2601 >= uVar12)) goto LAB_0001abf0;
  if (*(char *)(param_1 + 0x53e7) == '\0') {
    uVar12 = 0;
    goto LAB_0001abf0;
  }
  if (uVar12 == 0x2701) {
LAB_0001abcc:
    uVar12 = 0x2601;
  }
  else {
    if (uVar12 < 0x2702) {
      if (uVar12 != 0x2700) goto LAB_0001abf0;
    }
    else if (uVar12 != 0x2702) {
      if (uVar12 != 0x2703) goto LAB_0001abf0;
      goto LAB_0001abcc;
    }
    uVar12 = 0x2600;
  }
LAB_0001abf0:
  *(ushort *)(param_2 + 0x80) = uVar12;
  if ((uVar10 != *(byte *)(param_2 + 0x83)) || (uVar15 != *(byte *)(param_2 + 0x82))) {
    *(char *)(param_2 + 0x83) = (char)uVar10;
    *(char *)(param_2 + 0x82) = (char)uVar15;
  }
  return param_3;
}

/* _glTexParameterf_Exec @ 0x1ac34 (40 bytes) */
void _glTexParameterf_Exec(undefined4 param_1,undefined4 param_2,undefined4 param_3,float fparam_1)
{
  float fStack00000024;
  
  fStack00000024 = (float)fparam_1;
  ((int (*)())_glTexParameterF_Exec)(param_1,param_2,param_3,&STACKARG(0x24));
  return;
}

/* _glTexParameterF_Exec @ 0x1ac5c (2288 bytes) */
int _glTexParameterF_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined *param_3;
  float *param_4;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  float fVar7;
  uint uVar8;
  float dVar9;
  
  iVar5 = ((int (*)())_gleLookUpNonProxyTexture)(param_1,param_2);
  fVar3 = FLOAT_00108e54;
  fVar7 = FLOAT_00108e50;
  uVar6 = 0;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (iVar5 == 0) goto LAB_0001b4fc;
    if (param_3 == (undefined *)0x813c) {
      if ((int)*param_4 < 0) goto LAB_0001b268;
      *(short *)(iVar5 + 0x60) = (short)(int)*param_4;
LAB_0001b280:
      uVar6 = 1;
    }
    else if (param_3 < (undefined *)0x813d) {
      if (param_3 != (undefined *)0x2803) {
        if ((undefined *)0x2803 < param_3) {
          if (param_3 == (undefined *)0x80bf) {
            fVar7 = *param_4;
            fVar3 = FLOAT_00108e50;
            if ((fVar7 <= FLOAT_00108e50) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 <= fVar7)) {
              *(float *)(iVar5 + 0x68) = fVar3;
            }
            else {
              *(float *)(iVar5 + 0x68) = fVar7;
            }
          }
          else if (param_3 < (undefined *)0x80c0) {
            if (param_3 == (undefined *)0x8066) {
              fVar7 = *param_4;
              if (fVar7 < FLOAT_00108e50) {
                fVar7 = 0.0;
              }
              else if (FLOAT_00108e54 < fVar7) {
                fVar7 = 1.0;
              }
              *(float *)(iVar5 + 0x28) = fVar7;
            }
            else {
              if (param_3 != (undefined *)0x8072) goto LAB_0001b4fc;
              dVar9 = (double)*param_4;
              if (DOUBLE_00108d80 <= (double)dVar9) {
                uVar8 = (int)((double)dVar9 - DOUBLE_00108d80) ^ 0x80000000;
              }
              else {
                uVar8 = (uint)(int)*param_4;
              }
              if (uVar8 != 0x812f) {
                if (uVar8 < 0x8130) {
                  if (0x28ff < uVar8) {
                    if (0x2901 < uVar8) {
                      uVar4 = 0x812d;
                      goto LAB_0001b220;
                    }
                    goto LAB_0001b228;
                  }
                }
                else {
                  if (uVar8 < 0x8744) {
                    if (0x8741 < uVar8) goto LAB_0001b228;
                    uVar4 = 0x8370;
                  }
                  else {
                    uVar4 = 0x8912;
                  }
LAB_0001b220:
                  if (uVar8 == uVar4) goto LAB_0001b228;
                }
                goto LAB_0001b4fc;
              }
LAB_0001b228:
              *(short *)(iVar5 + 0x38) = (short)uVar8;
            }
          }
          else if (param_3 == (undefined *)0x813a) {
            *(float *)(iVar5 + 0x54) = *param_4;
          }
          else {
            if (param_3 != (undefined *)0x813b) goto LAB_0001b4fc;
            *(float *)(iVar5 + 0x58) = *param_4;
          }
          goto LAB_0001b514;
        }
        if (param_3 == (undefined *)0x2800) {
          dVar9 = (double)*param_4;
          if (DOUBLE_00108d80 <= (double)dVar9) {
            uVar8 = (int)((double)dVar9 - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar8 = (uint)(int)*param_4;
          }
          if (uVar8 - 0x2600 < 2) {
            *(short *)(iVar5 + 0x3c) = (short)uVar8;
            goto LAB_0001b514;
          }
        }
        else if (param_3 < (undefined *)0x2801) {
          if (param_3 == ((unsigned char *)0x00001004)) {
            fVar2 = *param_4;
            if (fVar2 < FLOAT_00108e50) {
              *(float *)(iVar5 + 0x40) = FLOAT_00108e50;
            }
            else if (FLOAT_00108e54 < fVar2) {
              *(float *)(iVar5 + 0x40) = FLOAT_00108e54;
            }
            else {
              *(float *)(iVar5 + 0x40) = fVar2;
            }
            fVar2 = param_4[1];
            if (fVar2 < fVar7) {
              *(float *)(iVar5 + 0x44) = fVar7;
            }
            else if (fVar3 < fVar2) {
              *(float *)(iVar5 + 0x44) = fVar3;
            }
            else {
              *(float *)(iVar5 + 0x44) = fVar2;
            }
            fVar2 = param_4[2];
            if (fVar2 < fVar7) {
              *(float *)(iVar5 + 0x48) = fVar7;
            }
            else if (fVar3 < fVar2) {
              *(float *)(iVar5 + 0x48) = fVar3;
            }
            else {
              *(float *)(iVar5 + 0x48) = fVar2;
            }
            fVar2 = param_4[3];
            if (fVar2 < fVar7) goto LAB_0001af8c;
            if (fVar3 < fVar2) {
              *(float *)(iVar5 + 0x4c) = fVar3;
            }
            else {
              *(float *)(iVar5 + 0x4c) = fVar2;
            }
            goto LAB_0001b514;
          }
        }
        else if (param_3 == (undefined *)0x2801) {
          dVar9 = (double)*param_4;
          if (DOUBLE_00108d80 <= (double)dVar9) {
            uVar8 = (int)((double)dVar9 - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar8 = (uint)(int)*param_4;
          }
          if ((0x25ff < uVar8) && ((uVar8 < 0x2602 || (uVar8 - 0x2700 < 4)))) {
            *(short *)(iVar5 + 0x3a) = (short)uVar8;
            goto LAB_0001b280;
          }
        }
        else if (param_3 == (undefined *)0x2802) {
          dVar9 = (double)*param_4;
          if (DOUBLE_00108d80 <= (double)dVar9) {
            uVar8 = (int)((double)dVar9 - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar8 = (uint)(int)*param_4;
          }
          if (uVar8 == 0x812f) {
LAB_0001b0e0:
            *(short *)(iVar5 + 0x34) = (short)uVar8;
            goto LAB_0001b514;
          }
          if (uVar8 < 0x8130) {
            if (0x28ff < uVar8) {
              if (0x2901 < uVar8) {
                uVar4 = 0x812d;
                goto LAB_0001b0d8;
              }
              goto LAB_0001b0e0;
            }
          }
          else {
            if (uVar8 < 0x8744) {
              if (0x8741 < uVar8) goto LAB_0001b0e0;
              uVar4 = 0x8370;
            }
            else {
              uVar4 = 0x8912;
            }
LAB_0001b0d8:
            if (uVar8 == uVar4) goto LAB_0001b0e0;
          }
        }
        goto LAB_0001b4fc;
      }
      dVar9 = (double)*param_4;
      if (DOUBLE_00108d80 <= (double)dVar9) {
        uVar8 = (int)((double)dVar9 - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        uVar8 = (uint)(int)*param_4;
      }
      if (uVar8 != 0x812f) {
        if (uVar8 < 0x8130) {
          if (uVar8 < 0x2900) goto LAB_0001b4fc;
          if (0x2901 < uVar8) {
            uVar4 = 0x812d;
            goto LAB_0001b17c;
          }
        }
        else {
          if (uVar8 < 0x8744) {
            if (0x8741 < uVar8) goto LAB_0001b184;
            uVar4 = 0x8370;
          }
          else {
            uVar4 = 0x8912;
          }
LAB_0001b17c:
          if (uVar8 != uVar4) goto LAB_0001b4fc;
        }
      }
LAB_0001b184:
      *(short *)(iVar5 + 0x36) = (short)uVar8;
    }
    else if (param_3 == (undefined *)0x85bc) {
      dVar9 = (double)*param_4;
      if (DOUBLE_00108d80 <= (double)dVar9) {
        uVar8 = (int)((double)dVar9 - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        uVar8 = (uint)(int)*param_4;
      }
      if (2 < uVar8 - 0x85bd) goto LAB_0001b4fc;
      *(short *)(iVar5 + 0x3e) = (short)uVar8;
    }
    else {
      if ((undefined *)0x85bc < param_3) {
        if (param_3 == (undefined *)0x884c) {
          dVar9 = (double)*param_4;
          if (DOUBLE_00108d80 <= (double)dVar9) {
            uVar8 = (int)((double)dVar9 - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar8 = (uint)(int)*param_4;
          }
          if ((uVar8 == 0) || (uVar8 == 0x884e)) {
            *(short *)(iVar5 + 0x66) = (short)uVar8;
            goto LAB_0001b514;
          }
        }
        else if (param_3 < (undefined *)0x884d) {
          if (param_3 == (undefined *)0x871a) {
            *(float *)(iVar5 + 0x40) = *param_4;
            *(float *)(iVar5 + 0x44) = param_4[1];
            *(float *)(iVar5 + 0x48) = param_4[2];
            fVar7 = param_4[3];
LAB_0001af8c:
            *(float *)(iVar5 + 0x4c) = fVar7;
            goto LAB_0001b514;
          }
          if (param_3 == (undefined *)0x884b) {
            dVar9 = (double)*param_4;
            if (DOUBLE_00108d80 <= (double)dVar9) {
              uVar8 = (int)((double)dVar9 - DOUBLE_00108d80) ^ 0x80000000;
            }
            else {
              uVar8 = (uint)(int)*param_4;
            }
            if (uVar8 != 0x1909) {
              if (uVar8 < 0x190a) {
                bVar1 = uVar8 == 0x1906;
              }
              else {
                bVar1 = uVar8 == 0x8049;
              }
              if (!bVar1) goto LAB_0001b4fc;
            }
            *(short *)(iVar5 + 0x6c) = (short)uVar8;
            goto LAB_0001b514;
          }
        }
        else if (param_3 == (undefined *)0x884d) {
          dVar9 = (double)*param_4;
          if (DOUBLE_00108d80 <= (double)dVar9) {
            uVar8 = (int)((double)dVar9 - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar8 = (uint)(int)*param_4;
          }
          if (uVar8 - 0x200 < 8) {
            *(short *)(iVar5 + 100) = (short)uVar8;
            goto LAB_0001b514;
          }
        }
        else if (param_3 == (undefined *)0x8a7f) {
          dVar9 = (double)*param_4;
          if (DOUBLE_00108d80 <= (double)dVar9) {
            uVar8 = (int)((double)dVar9 - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            uVar8 = (uint)(int)*param_4;
          }
          if (uVar8 < 2) {
            uVar8 = (uVar8 & 1) << 6 | *(uint *)(iVar5 + 0x6c) & 0xffffffbf;
            goto LAB_0001b4f4;
          }
        }
LAB_0001b4fc:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return iVar5;
        }
        uVar6 = 0x500;
        goto LAB_0001b50c;
      }
      if (param_3 == (undefined *)0x84fe) {
        if (*param_4 < FLOAT_00108e54) goto LAB_0001b268;
        *(float *)(iVar5 + 0x50) = *param_4;
      }
      else {
        if (param_3 < (undefined *)0x84ff) {
          if (param_3 != (undefined *)0x813d) {
            if (param_3 == (undefined *)0x8191) {
              dVar9 = (double)*param_4;
              if (DOUBLE_00108d80 <= (double)dVar9) {
                uVar8 = (int)((double)dVar9 - DOUBLE_00108d80) ^ 0x80000000;
              }
              else {
                uVar8 = (uint)(int)*param_4;
              }
              if (uVar8 < 2) {
                uVar8 = (uVar8 & 1) << 0xf | *(uint *)(iVar5 + 0x6c) & 0xffff7fff;
                goto LAB_0001b4f4;
              }
            }
            goto LAB_0001b4fc;
          }
          if (-1 < (int)*param_4) {
            *(short *)(iVar5 + 0x62) = (short)(int)*param_4;
            goto LAB_0001b280;
          }
LAB_0001b268:
          if (*(int *)(param_1 + 0x7574) != 0) {
            return iVar5;
          }
          uVar6 = 0x501;
          goto LAB_0001b50c;
        }
        if (param_3 == (undefined *)0x8501) {
          *(float *)(iVar5 + 0x5c) = *param_4;
        }
        else {
          if (param_3 != (undefined *)0x85b6) goto LAB_0001b4fc;
          uVar8 = (uint)(*param_4 != FLOAT_00108e50) << 7 | *(uint *)(iVar5 + 0x6c) & 0xffffff7f;
LAB_0001b4f4:
          *(uint *)(iVar5 + 0x6c) = uVar8;
        }
      }
    }
LAB_0001b514:
    iVar5 = ((int (*)())_gleModifyPluginTexture)(param_1,iVar5,uVar6);
    *(uint *)(param_1 + 0x314) =
         *(uint *)(param_1 + 0x314) | 1 << (*(uint *)(param_1 + 0x53d4) & 0x3f);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return iVar5;
    }
    uVar6 = 0x502;
LAB_0001b50c:
    *(undefined4 *)(param_1 + 0x7574) = uVar6;
  }
  return iVar5;
}

/* _glGetError_Exec @ 0x1b54c (176 bytes) */
int _glGetError_Exec(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar1 = *(int *)(param_1 + 0x7574);
    *(undefined4 *)(param_1 + 0x7574) = 0;
    if ((iVar1 == 0) && (*(char *)(param_1 + 0x85a4) != '\0')) {
      do {
        iVar1 = uVar2 * 0x2e0 + param_1;
        iVar1 = (**(code **)(*(int *)(iVar1 + 0x8884) + 0x180))(*(undefined4 *)(iVar1 + 0x85ac));
        uVar2 = uVar2 + 1 & 0xff;
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = 0;
      } while (uVar2 < *(byte *)(param_1 + 0x85a4));
    }
  }
  else {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    iVar1 = 0;
  }
  return iVar1;
}

/* _glBlendFunc_Exec @ 0x1b5fc (168 bytes) */
void _glBlendFunc_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  bool bVar1;
  undefined4 uVar2;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
    goto LAB_0001b654;
  }
  if (param_3 < 0x308) {
    if (param_3 < 0x300) {
      bVar1 = 1 < param_3;
      goto LAB_0001b640;
    }
LAB_0001b65c:
    if (param_2 < 0x309) {
      if (0x2ff < param_2) goto LAB_0001b684;
      bVar1 = 1 < param_2;
    }
    else {
      bVar1 = 3 < param_2 - 0x8001;
    }
    if (!bVar1) {
LAB_0001b684:
      *(short *)(param_1 + 0x30ce) = (short)param_3;
      *(short *)(param_1 + 0x30cc) = (short)param_2;
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 2;
      *(short *)(param_1 + 0x30ca) = (short)param_3;
      *(short *)(param_1 + 0x30c8) = (short)param_2;
      return;
    }
  }
  else {
    bVar1 = 3 < param_3 - 0x8001;
LAB_0001b640:
    if (!bVar1) goto LAB_0001b65c;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x500;
LAB_0001b654:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glColorMask_Exec @ 0x1b6a4 (100 bytes) */
void _glColorMask_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40000;
    *(byte *)(param_1 + 0x31a0) = (byte)((uint)-param_2 >> 0x1f);
    *(byte *)(param_1 + 0x31a1) = (byte)((uint)-param_3 >> 0x1f);
    *(byte *)(param_1 + 0x31a2) = (byte)((uint)-param_4 >> 0x1f);
    *(byte *)(param_1 + 0x31a3) = (byte)((uint)-param_5 >> 0x1f);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glColor4ub_Exec @ 0x1b708 (80 bytes) */
void _glColor4ub_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x4674);
  uVar1 = *(undefined4 *)(param_5 * 4 + iVar4);
  uVar2 = *(undefined4 *)(param_3 * 4 + iVar4);
  uVar3 = *(undefined4 *)(param_4 * 4 + iVar4);
  *(undefined4 *)(param_1 + 0x2a0) = *(undefined4 *)(param_2 * 4 + iVar4);
  *(undefined4 *)(param_1 + 0x2a4) = uVar2;
  *(undefined4 *)(param_1 + 0x2a8) = uVar3;
  *(undefined4 *)(param_1 + 0x2ac) = uVar1;
  if (*(char *)(param_1 + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  return;
}

/* _glTexEnvf_Exec @ 0x1b758 (2524 bytes) */
void _glTexEnvf_Exec(int param_1,int param_2,uint param_3,double fparam_1)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  
  uVar7 = *(uint *)(param_1 + 0x53d4);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x86de) {
      iVar3 = param_1 + uVar7 * 0x7c;
      switch(param_3) {
      case 0x86d9:
        if (DOUBLE_00108d80 <= fparam_1) {
          uVar5 = (int)(fparam_1 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar5 = (uint)(int)fparam_1;
        }
        if ((uVar5 != 0x8536) && (uVar5 != 0x8538)) goto switchD_0001b7dc_caseD_86da;
        *(short *)(iVar3 + 0x356c) = (short)uVar5;
        break;
      default:
switchD_0001b7dc_caseD_86da:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x500;
        goto LAB_0001c14c;
      case 0x86df:
        if (DOUBLE_00108d80 <= fparam_1) {
          uVar5 = (int)(fparam_1 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar5 = (uint)(int)fparam_1;
        }
        iVar4 = _CheckNVShaderOperation(param_1,uVar5);
        if (iVar4 != 0) {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          *(int *)(param_1 + 0x7574) = iVar4;
          return;
        }
        *(short *)(iVar3 + 0x3564) = (short)uVar5;
        _gleUpdateTextureParams(param_1,uVar7);
        break;
      case 0x86e2:
        *(float *)(iVar3 + 0x3598) = (float)fparam_1;
        break;
      case 0x86e3:
        *(float *)(iVar3 + 0x359c) = (float)fparam_1;
        break;
      case 0x86e4:
        if (DOUBLE_00108d80 <= fparam_1) {
          uVar5 = (int)(fparam_1 - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          uVar5 = (uint)(int)fparam_1;
        }
        if ((uVar5 < 0x84c0) || (*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb4) + 0x84c0 <= uVar5))
        goto switchD_0001b7dc_caseD_86da;
        *(short *)(iVar3 + 0x356a) = (short)uVar5;
      }
      uVar5 = *(uint *)(param_1 + 800);
      iVar3 = 1;
    }
    else {
      if (param_2 == 0x8861) {
        if (param_3 == 0x8862) {
          if (fparam_1 == (double)FLOAT_00108e50) {
            uVar7 = *(uint *)(param_1 + 0x3444) &
                    (-2 << (uVar7 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar7 & 0x1f));
          }
          else {
            uVar7 = *(uint *)(param_1 + 0x3444) | 1 << (uVar7 & 0x3f);
          }
          *(uint *)(param_1 + 0x3444) = uVar7;
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400000;
          return;
        }
        goto switchD_0001b7dc_caseD_86da;
      }
      if (param_2 != 0x2300) {
        if ((param_2 == 0x8500) && (param_3 == 0x8501)) {
          iVar3 = 0x10000;
          *(float *)(uVar7 * 0x7c + param_1 + 0x3560) = (float)fparam_1;
          uVar5 = *(uint *)(param_1 + 800);
          goto LAB_0001c12c;
        }
        goto switchD_0001b7dc_caseD_86da;
      }
      if (param_3 == 0x2200) {
        if (DOUBLE_00108d80 <= fparam_1) {
          pcVar6 = (code *)((int)(fparam_1 - DOUBLE_00108d80) ^ 0x80000000);
        }
        else {
          pcVar6 = (code *)(int)fparam_1;
        }
        if (pcVar6 != (code *)0x1e01) {
          if (pcVar6 < (code *)0x1e02) {
            if (pcVar6 != (code *)0x104) {
              if (pcVar6 < (code *)0x105) {
                bVar1 = pcVar6 == (code *)0x0;
              }
              else {
                bVar1 = pcVar6 == (code *)0xbe2;
              }
LAB_0001ba68:
              if (!bVar1) goto switchD_0001b7dc_caseD_86da;
            }
          }
          else {
            if (pcVar6 < (code *)0x2100) goto switchD_0001b7dc_caseD_86da;
            if ((code *)0x2100 < pcVar6) {
              bVar1 = pcVar6 == (code *)0x8570;
              goto LAB_0001ba68;
            }
          }
        }
        iVar3 = 1;
        *(short *)(uVar7 * 0x7c + param_1 + 0x3538) = (short)pcVar6;
        uVar5 = *(uint *)(param_1 + 800);
LAB_0001c12c:
        *(uint *)(param_1 + 800) = uVar5 | iVar3 << (uVar7 & 0x3f);
        return;
      }
      if (param_3 == 0x8588) {
        iVar3 = (int)fparam_1;
        if (((iVar3 == 0x1702) || (iVar3 - 0x84c0U < 0x10)) ||
           (((iVar3 == 0x8576 || (((iVar3 == 0x8577 || (iVar3 == 0x8578)) || (iVar3 == 0)))) ||
            (iVar3 == 1)))) {
          *(short *)(uVar7 * 0x7c + param_1 + 0x3546) = (short)iVar3;
          goto LAB_0001c0e0;
        }
        goto switchD_0001b7dc_caseD_86da;
      }
      if (param_3 < 0x8589) {
        if (param_3 == 0x8573) {
          if (((fparam_1 == (double)FLOAT_00108e54) || (fparam_1 == (double)FLOAT_00108ea4)) ||
             (fparam_1 == (double)FLOAT_00108ea8)) {
            *(float *)(uVar7 * 0x7c + param_1 + 0x3558) = (float)fparam_1;
          }
          else {
LAB_0001c0bc:
            if (*(int *)(param_1 + 0x7574) == 0) {
              *(undefined4 *)(param_1 + 0x7574) = 0x500;
            }
          }
        }
        else {
          if (0x8573 < param_3) {
            if (param_3 == 0x8581) {
              iVar3 = (int)fparam_1;
              if (((((iVar3 == 0x1702) || (iVar3 - 0x84c0U < 0x10)) || (iVar3 == 0x8576)) ||
                  ((iVar3 == 0x8577 || (iVar3 == 0x8578)))) || ((iVar3 == 0 || (iVar3 == 1)))) {
                *(short *)(uVar7 * 0x7c + param_1 + 0x3542) = (short)iVar3;
                goto LAB_0001c0e0;
              }
            }
            else if (param_3 < 0x8582) {
              if ((param_3 == 0x8580) &&
                 (((((iVar3 = (int)fparam_1, iVar3 == 0x1702 || (iVar3 - 0x84c0U < 0x10)) ||
                    ((iVar3 == 0x8576 || ((iVar3 == 0x8577 || (iVar3 == 0x8578)))))) || (iVar3 == 0)
                   ) || (iVar3 == 1)))) {
                *(short *)(uVar7 * 0x7c + param_1 + 0x3540) = (short)iVar3;
                goto LAB_0001c0e0;
              }
            }
            else if ((param_3 == 0x8582) &&
                    (((iVar3 = (int)fparam_1, iVar3 == 0x1702 || (iVar3 - 0x84c0U < 0x10)) ||
                     ((iVar3 == 0x8576 ||
                      ((((iVar3 == 0x8577 || (iVar3 == 0x8578)) || (iVar3 == 0)) || (iVar3 == 1)))))
                     ))) {
              *(short *)(uVar7 * 0x7c + param_1 + 0x3544) = (short)iVar3;
              goto LAB_0001c0e0;
            }
            goto switchD_0001b7dc_caseD_86da;
          }
          if (param_3 == 0x8571) {
            pcVar6 = (code *)(int)fparam_1;
            if (pcVar6 < (code *)0x8576) {
              if ((pcVar6 < (code *)0x8574) && (pcVar6 != (code *)0x1e01)) {
                if (pcVar6 < (code *)0x1e02) {
                  bVar1 = pcVar6 == (code *)0x104;
                }
                else {
                  if (pcVar6 == (code *)0x2100) goto LAB_0001bc1c;
                  bVar1 = pcVar6 == (code *)0x84e7;
                }
                if (!bVar1) goto switchD_0001b7dc_caseD_86da;
              }
            }
            else if ((pcVar6 < (code *)0x86ae) ||
                    (((code *)0x86af < pcVar6 && ((code *)0x2 < pcVar6 + -0x8744))))
            goto switchD_0001b7dc_caseD_86da;
LAB_0001bc1c:
            *(short *)(uVar7 * 0x7c + param_1 + 0x353c) = (short)pcVar6;
          }
          else {
            if (param_3 < 0x8572) {
              if (param_3 == 0xd1c) {
                if (((fparam_1 != (double)FLOAT_00108e54) && (fparam_1 != (double)FLOAT_00108ea4))
                   && (fparam_1 != (double)FLOAT_00108ea8)) goto LAB_0001c0bc;
                *(float *)(uVar7 * 0x7c + param_1 + 0x355c) = (float)fparam_1;
                goto LAB_0001c0e0;
              }
              goto switchD_0001b7dc_caseD_86da;
            }
            pcVar6 = (code *)(int)fparam_1;
            if (pcVar6 != (code *)0x84e7) {
              if (pcVar6 < (code *)0x84e8) {
                if (pcVar6 != (code *)0x1e01) {
                  if (pcVar6 < (code *)0x1e02) {
                    bVar1 = pcVar6 == (code *)0x104;
                  }
                  else {
                    bVar1 = pcVar6 == (code *)0x2100;
                  }
                  if (!bVar1) goto switchD_0001b7dc_caseD_86da;
                }
              }
              else if ((pcVar6 < (code *)0x8574) ||
                      (((code *)0x8575 < pcVar6 && ((code *)0x2 < pcVar6 + -0x8744))))
              goto switchD_0001b7dc_caseD_86da;
            }
            *(short *)(uVar7 * 0x7c + param_1 + 0x353e) = (short)pcVar6;
          }
        }
      }
      else {
        if (param_3 != 0x8591) {
          if (param_3 < 0x8592) {
            if (param_3 == 0x858a) {
              iVar3 = (int)fparam_1;
              if ((((((iVar3 == 0x1702) || (iVar3 - 0x84c0U < 0x10)) || (iVar3 == 0x8576)) ||
                   ((iVar3 == 0x8577 || (iVar3 == 0x8578)))) || (iVar3 == 0)) || (iVar3 == 1)) {
                *(short *)(uVar7 * 0x7c + param_1 + 0x354a) = (short)iVar3;
                goto LAB_0001c0e0;
              }
            }
            else if (param_3 < 0x858a) {
              iVar3 = (int)fparam_1;
              if ((((iVar3 == 0x1702) || (iVar3 - 0x84c0U < 0x10)) ||
                  ((iVar3 == 0x8576 || (((iVar3 == 0x8577 || (iVar3 == 0x8578)) || (iVar3 == 0))))))
                 || (iVar3 == 1)) {
                *(short *)(uVar7 * 0x7c + param_1 + 0x3548) = (short)iVar3;
                goto LAB_0001c0e0;
              }
            }
            else if ((param_3 == 0x8590) && ((int)fparam_1 - 0x300U < 4)) {
              *(short *)(uVar7 * 0x7c + param_1 + 0x354c) = (short)(int)fparam_1;
              goto LAB_0001c0e0;
            }
          }
          else if (param_3 == 0x8598) {
            if ((int)fparam_1 - 0x302U < 2) {
              *(short *)(uVar7 * 0x7c + param_1 + 0x3552) = (short)(int)fparam_1;
              goto LAB_0001c0e0;
            }
          }
          else if (param_3 < 0x8599) {
            if ((param_3 == 0x8592) && ((int)fparam_1 - 0x300U < 4)) {
              *(short *)(uVar7 * 0x7c + param_1 + 0x3550) = (short)(int)fparam_1;
              goto LAB_0001c0e0;
            }
          }
          else if (param_3 == 0x8599) {
            if ((int)fparam_1 - 0x302U < 2) {
              *(short *)(uVar7 * 0x7c + param_1 + 0x3554) = (short)(int)fparam_1;
              goto LAB_0001c0e0;
            }
          }
          else if ((param_3 == 0x859a) && ((int)fparam_1 - 0x302U < 2)) {
            *(short *)(uVar7 * 0x7c + param_1 + 0x3556) = (short)(int)fparam_1;
            goto LAB_0001c0e0;
          }
          goto switchD_0001b7dc_caseD_86da;
        }
        if (3 < (int)fparam_1 - 0x300U) goto switchD_0001b7dc_caseD_86da;
        *(short *)(uVar7 * 0x7c + param_1 + 0x354e) = (short)(int)fparam_1;
      }
LAB_0001c0e0:
      uVar5 = *(uint *)(param_1 + 800);
      iVar3 = 0x1000000;
    }
    *(uint *)(param_1 + 800) = uVar5 | iVar3 << (uVar7 & 0x3f);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
LAB_0001c14c:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
  }
  return;
}

/* _glTexEnvi_Exec @ 0x1c164 (2280 bytes) */
void _glTexEnvi_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  code *param_4;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 uVar6;
  uint uVar7;
  
  uVar7 = *(uint *)(param_1 + 0x53d4);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    uVar6 = SUB42(param_4,0);
    if (param_2 == 0x86de) {
      iVar3 = param_1 + uVar7 * 0x7c;
      switch(param_3) {
      case 0x86d9:
        if ((param_4 != (code *)0x8536) && (param_4 != (code *)0x8538))
        goto switchD_0001c1ec_caseD_86da;
        *(undefined2 *)(iVar3 + 0x356c) = uVar6;
        break;
      default:
switchD_0001c1ec_caseD_86da:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x500;
        goto LAB_0001ca64;
      case 0x86df:
        iVar5 = _CheckNVShaderOperation(param_1,param_4);
        if (iVar5 != 0) {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          *(int *)(param_1 + 0x7574) = iVar5;
          return;
        }
        *(undefined2 *)(iVar3 + 0x3564) = uVar6;
        _gleUpdateTextureParams(param_1,uVar7);
        break;
      case 0x86e2:
        *(float *)(iVar3 + 0x3598) =
             (float)((double)CONCAT44(0x43300000,(uint)param_4 ^ 0x80000000) - DOUBLE_00108d58);
        break;
      case 0x86e3:
        *(float *)(iVar3 + 0x359c) =
             (float)((double)CONCAT44(0x43300000,(uint)param_4 ^ 0x80000000) - DOUBLE_00108d58);
        break;
      case 0x86e4:
        if (((int)param_4 < 0x84c0) ||
           ((int)(*(ushort *)(*(int *)(param_1 + 0x468c) + 0xb4) + 0x84c0) <= (int)param_4))
        goto switchD_0001c1ec_caseD_86da;
        *(undefined2 *)(iVar3 + 0x356a) = uVar6;
      }
      uVar4 = *(uint *)(param_1 + 800);
      iVar3 = 1;
    }
    else {
      if (param_2 == 0x8861) {
        if (param_3 == 0x8862) {
          if (param_4 == (code *)0x0) {
            uVar7 = *(uint *)(param_1 + 0x3444) &
                    (-2 << (uVar7 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar7 & 0x1f));
          }
          else {
            uVar7 = *(uint *)(param_1 + 0x3444) | 1 << (uVar7 & 0x3f);
          }
          *(uint *)(param_1 + 0x3444) = uVar7;
          *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x400000;
          return;
        }
        goto switchD_0001c1ec_caseD_86da;
      }
      if (param_2 != 0x2300) {
        if ((param_2 == 0x8500) && (param_3 == 0x8501)) {
          *(float *)(uVar7 * 0x7c + param_1 + 0x3560) =
               (float)((double)CONCAT44(0x43300000,(uint)param_4 ^ 0x80000000) - DOUBLE_00108d58);
          *(uint *)(param_1 + 800) = *(uint *)(param_1 + 800) | 0x10000 << (uVar7 & 0x3f);
          return;
        }
        goto switchD_0001c1ec_caseD_86da;
      }
      if (param_3 == 0x2200) {
        if (param_4 == (code *)0x1e01) goto LAB_0001c3c8;
        if ((int)param_4 < 0x1e02) {
          if (param_4 == (code *)0x104) goto LAB_0001c3c8;
          if ((int)param_4 < 0x105) {
            bVar1 = param_4 == (code *)0x0;
          }
          else {
            bVar1 = param_4 == (code *)0xbe2;
          }
        }
        else {
          if ((int)param_4 < 0x2100) goto switchD_0001c1ec_caseD_86da;
          if ((int)param_4 < 0x2102) goto LAB_0001c3c8;
          bVar1 = param_4 == (code *)0x8570;
        }
        if (bVar1) {
LAB_0001c3c8:
          *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x3538) = uVar6;
          *(uint *)(param_1 + 800) = *(uint *)(param_1 + 800) | 1 << (uVar7 & 0x3f);
          return;
        }
        goto switchD_0001c1ec_caseD_86da;
      }
      if (param_3 == 0x8588) {
        if (((((param_4 == (code *)0x1702) || (param_4 + -0x84c0 < ((unsigned char *)0x10))) ||
             (param_4 == (code *)0x8576)) ||
            ((param_4 == (code *)0x8577 || (param_4 == (code *)0x8578)))) ||
           ((param_4 == (code *)0x0 || (param_4 == (code *)0x1)))) {
          *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x3546) = uVar6;
          goto LAB_0001c9d4;
        }
        goto switchD_0001c1ec_caseD_86da;
      }
      if (param_3 < 0x8589) {
        if (param_3 == 0x8573) {
          if ((param_4 + -1 < (code *)0x2) || (param_4 == (code *)0x4)) {
            *(float *)(uVar7 * 0x7c + param_1 + 0x3558) =
                 (float)((double)CONCAT44(0x43300000,(uint)param_4 ^ 0x80000000) - DOUBLE_00108d58);
          }
          else {
LAB_0001c98c:
            if (*(int *)(param_1 + 0x7574) == 0) {
              *(undefined4 *)(param_1 + 0x7574) = 0x500;
            }
          }
        }
        else {
          if (0x8573 < param_3) {
            if (param_3 == 0x8581) {
              if ((((((param_4 == (code *)0x1702) || (param_4 + -0x84c0 < (code *)0x10)) ||
                    (param_4 == (code *)0x8576)) ||
                   ((param_4 == (code *)0x8577 || (param_4 == (code *)0x8578)))) ||
                  (param_4 == (code *)0x0)) || (param_4 == (code *)0x1)) {
                *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x3542) = uVar6;
                goto LAB_0001c9d4;
              }
            }
            else if (param_3 < 0x8582) {
              if ((param_3 == 0x8580) &&
                 (((param_4 == (code *)0x1702 || (param_4 + -0x84c0 < (code *)0x10)) ||
                  ((((param_4 == (code *)0x8576 ||
                     ((param_4 == (code *)0x8577 || (param_4 == (code *)0x8578)))) ||
                    (param_4 == (code *)0x0)) || (param_4 == (code *)0x1)))))) {
                *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x3540) = uVar6;
                goto LAB_0001c9d4;
              }
            }
            else if ((param_3 == 0x8582) &&
                    ((((param_4 == (code *)0x1702 || (param_4 + -0x84c0 < (code *)0x10)) ||
                      ((param_4 == (code *)0x8576 ||
                       (((param_4 == (code *)0x8577 || (param_4 == (code *)0x8578)) ||
                        (param_4 == (code *)0x0)))))) || (param_4 == (code *)0x1)))) {
              *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x3544) = uVar6;
              goto LAB_0001c9d4;
            }
            goto switchD_0001c1ec_caseD_86da;
          }
          if (param_3 == 0x8571) {
            if ((int)param_4 < 0x8576) {
              if (((int)param_4 < 0x8574) && (param_4 != (code *)0x1e01)) {
                if ((int)param_4 < 0x1e02) {
                  bVar1 = param_4 == (code *)0x104;
                }
                else {
                  if (param_4 == (code *)0x2100) goto LAB_0001c594;
                  bVar1 = param_4 == (code *)0x84e7;
                }
                if (!bVar1) goto switchD_0001c1ec_caseD_86da;
              }
            }
            else if (((int)param_4 < 0x86ae) ||
                    ((0x86af < (int)param_4 && ((code *)0x2 < param_4 + -0x8744))))
            goto switchD_0001c1ec_caseD_86da;
LAB_0001c594:
            *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x353c) = uVar6;
          }
          else {
            if (param_3 < 0x8572) {
              if (param_3 == 0xd1c) {
                if (((code *)0x1 < param_4 + -1) && (param_4 != (code *)0x4)) goto LAB_0001c98c;
                *(float *)(uVar7 * 0x7c + param_1 + 0x355c) =
                     (float)((double)CONCAT44(0x43300000,(uint)param_4 ^ 0x80000000) -
                            DOUBLE_00108d58);
                goto LAB_0001c9d4;
              }
              goto switchD_0001c1ec_caseD_86da;
            }
            if (param_4 != (code *)0x84e7) {
              if ((int)param_4 < 0x84e8) {
                if (param_4 != (code *)0x1e01) {
                  if ((int)param_4 < 0x1e02) {
                    bVar1 = param_4 == (code *)0x104;
                  }
                  else {
                    bVar1 = param_4 == (code *)0x2100;
                  }
                  if (!bVar1) goto switchD_0001c1ec_caseD_86da;
                }
              }
              else if (((int)param_4 < 0x8574) ||
                      ((0x8575 < (int)param_4 && ((code *)0x2 < param_4 + -0x8744))))
              goto switchD_0001c1ec_caseD_86da;
            }
            *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x353e) = uVar6;
          }
        }
      }
      else {
        if (param_3 != 0x8591) {
          if (param_3 < 0x8592) {
            if (param_3 == 0x858a) {
              if ((((param_4 == (code *)0x1702) || (param_4 + -0x84c0 < (code *)0x10)) ||
                  (param_4 == (code *)0x8576)) ||
                 (((param_4 == (code *)0x8577 || (param_4 == (code *)0x8578)) ||
                  ((param_4 == (code *)0x0 || (param_4 == (code *)0x1)))))) {
                *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x354a) = uVar6;
                goto LAB_0001c9d4;
              }
            }
            else if (param_3 < 0x858a) {
              if ((((param_4 == (code *)0x1702) || (param_4 + -0x84c0 < (code *)0x10)) ||
                  ((param_4 == (code *)0x8576 ||
                   (((param_4 == (code *)0x8577 || (param_4 == (code *)0x8578)) ||
                    (param_4 == (code *)0x0)))))) || (param_4 == (code *)0x1)) {
                *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x3548) = uVar6;
                goto LAB_0001c9d4;
              }
            }
            else if ((param_3 == 0x8590) && (param_4 + -0x300 < (code *)0x4)) {
              *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x354c) = uVar6;
              goto LAB_0001c9d4;
            }
          }
          else if (param_3 == 0x8598) {
            if (param_4 + -0x302 < (code *)0x2) {
              *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x3552) = uVar6;
              goto LAB_0001c9d4;
            }
          }
          else if (param_3 < 0x8599) {
            if ((param_3 == 0x8592) && (param_4 + -0x300 < (code *)0x4)) {
              *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x3550) = uVar6;
              goto LAB_0001c9d4;
            }
          }
          else if (param_3 == 0x8599) {
            if (param_4 + -0x302 < (code *)0x2) {
              *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x3554) = uVar6;
              goto LAB_0001c9d4;
            }
          }
          else if ((param_3 == 0x859a) && (param_4 + -0x302 < (code *)0x2)) {
            *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x3556) = uVar6;
            goto LAB_0001c9d4;
          }
          goto switchD_0001c1ec_caseD_86da;
        }
        if ((code *)((int)((unsigned char *)0x0) + 3) < param_4 + -0x300)
        goto switchD_0001c1ec_caseD_86da;
        *(undefined2 *)(uVar7 * 0x7c + param_1 + 0x354e) = uVar6;
      }
LAB_0001c9d4:
      uVar4 = *(uint *)(param_1 + 800);
      iVar3 = 0x1000000;
    }
    *(uint *)(param_1 + 800) = uVar4 | iVar3 << (uVar7 & 0x3f);
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
LAB_0001ca64:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
  }
  return;
}

/* _gleSetEnable_TEXTURE_RECTANGLE_EXT @ 0x1ca7c (80 bytes) */
void _gleSetEnable_TEXTURE_RECTANGLE_EXT(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *(uint *)(param_1 + 0x53d4);
  if (uVar3 < 8) {
    iVar2 = uVar3 * 0x7c + param_1;
    uVar4 = *(uint *)(iVar2 + 0x3534);
    uVar1 = uVar4 & 0xfffffffb | param_3 << 2;
    if (uVar4 == uVar1) {
      return;
    }
    *(uint *)(iVar2 + 0x3534) = uVar1;
    _gleUpdateTextureParams(param_1,uVar3);
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glBegin_Exec @ 0x1cacc (704 bytes) */
void _glBegin_Exec(int param_1,uint param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar6;
  uint uVar7;
  int *piVar8;
  double extraout_f1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_0001cd18;
  }
  if (9 < param_2) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
    goto LAB_0001cd18;
  }
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_0001cd44;
  iVar5 = *(int *)(param_1 + 0x744c);
  piVar8 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_0001cc1c:
    uVar7 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar6 = 0;
    piVar4 = (int *)(param_1 + 0x324);
    do {
      iVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      if (iVar5 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 9);
    uVar7 = *(uint *)(param_1 + 0x31c);
    if ((uVar7 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_0001cc1c;
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
    bVar1 = ((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar8 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar7 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (!bVar1) {
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar7 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
      if ((((uVar7 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar7 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar7 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar7 & 4) == 0) {
          uVar7 = uVar7 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar7);
        if (*(char *)(param_1 + 0x759d) == '\0') {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar3 = 0x506;
LAB_0001cd18:
          *(undefined4 *)(param_1 + 0x7574) = uVar3;
          return;
        }
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar6 = 0x13;
    do {
      *piVar8 = 0;
      piVar8 = piVar8 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
LAB_0001cd44:
  *(short *)(param_1 + 0x4a10) = (short)param_2;
  *(undefined4 *)(param_1 + 0x4884) = *(undefined4 *)(param_1 + 0x4888);
                    
                    
  (**(code **)(param_2 * 4 + param_1 + 0x49e0))(param_1);
  return;
}

/* _gleUpdateDrawArraysFuncs @ 0x1cd8c (916 bytes) */
void _gleUpdateDrawArraysFuncs(param_1)
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x5408) != 0) {
    return;
  }
  if ((*(char *)(param_1 + 0x759c) == '\0') || (*(char *)(param_1 + 0x759d) == '\0')) {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xc) =
         PTR__glArrayElement_NoopExec_00112110;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x104) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x104) =
         PTR__glDrawArrays_NoopExec_0011210c;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10c) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x10c) =
         PTR__glDrawElements_NoopExec_00112108;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x654) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x654) =
         PTR__glDrawRangeElements_NoopExec_00112104;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8dc) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8dc) =
         PTR__glMultiDrawArrays_NoopExec_00112100;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8e0) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8e0) =
         PTR__glMultiDrawElements_NoopExec_001120fc;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8b0) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8b0) =
         PTR__glDrawRangeElementArrayAPPLE_NoopExec_001120f8;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8ac) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8ac) =
         PTR__glDrawElementArrayAPPLE_NoopExec_001120f4;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa60) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa60) =
         PTR__glMultiDrawRangeElementArrayAPPLE_NoopExec_001120f0;
    uVar4 = *(uint *)(param_1 + 0x4684);
    uVar3 = *(uint *)(param_1 + 0x4680);
    iVar1 = *(int *)(uVar4 + 0xa5c);
    puVar2 = PTR__glMultiDrawElementArrayAPPLE_NoopExec_001120ec;
  }
  else {
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xc) =
         PTR__glArrayElement_Exec_001120e8;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x104) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x104) =
         PTR__glDrawArrays_Exec_001120e4;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x10c) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x10c) =
         PTR__glDrawElements_Exec_001120e0;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x654) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x654) =
         PTR__glDrawRangeElements_Exec_001120dc;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8dc) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8dc) =
         PTR__glMultiDrawArrays_Exec_001120d8;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8e0) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8e0) =
         PTR__glMultiDrawElements_Exec_001120d4;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8b0) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8b0) =
         PTR__glDrawRangeElementArrayAPPLE_Exec_001120d0;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0x8ac) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0x8ac) =
         PTR__glDrawElementArrayAPPLE_Exec_001120cc;
    uVar3 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xa60) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar3 | *(uint *)(param_1 + 0x4684) & ~uVar3) + 0xa60) =
         PTR__glMultiDrawRangeElementArrayAPPLE_Exec_001120c8;
    uVar4 = *(uint *)(param_1 + 0x4684);
    uVar3 = *(uint *)(param_1 + 0x4680);
    iVar1 = *(int *)(uVar4 + 0xa5c);
    puVar2 = PTR__glMultiDrawElementArrayAPPLE_Exec_001120c4;
  }
  *(undefined **)((uVar3 & -(uint)(iVar1 == 0) | uVar4 & ~-(uint)(iVar1 == 0)) + 0xa5c) = puVar2;
  return;
}

/* _gleBeginPrimitiveTCLFunc @ 0x1d120 (168 bytes) */
void _gleBeginPrimitiveTCLFunc(param_1)
  int param_1;
{
  short sVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int local_20 [5];
  
  local_20[0] = *(int *)(param_1 + 0x4a14);
  *(undefined1 *)(param_1 + 0x4a18) = 0;
  if (local_20[0] == 0) {
    sVar1 = *(short *)(param_1 + 0x4880);
  }
  else {
    sVar1 = *(short *)(param_1 + 0x4882);
  }
  iVar4 = (**(code **)(param_1 + 0x46e8))
                    (*(undefined4 *)(param_1 + 0x4688),(int)*(short *)(param_1 + 0x4a10),local_20);
  puVar2 = PTR__gleRenderPrimitiveTCLFunc_001113cc;
  *(undefined2 *)(param_1 + 0x4a12) = *(undefined2 *)(param_1 + 0x4a10);
  puVar3 = PTR__gleFlushPrimitiveTCLFunc_001113d0;
  *(undefined **)(param_1 + 0x4a08) = puVar2;
  *(undefined **)(param_1 + 0x4a0c) = puVar3;
  *(int *)(param_1 + 0x485c) = iVar4 + sVar1 * local_20[0];
  *(short *)(param_1 + 0x487c) = sVar1;
  *(int *)(param_1 + 0x4868) = iVar4;
  *(int *)(param_1 + 0x4858) = iVar4;
  return;
}

/* _glTexCoord2f_Exec @ 0x1d1c8 (28 bytes) */
void _glTexCoord2f_Exec(int param_1,float fparam_1,float fparam_2)
{
  *(float *)(param_1 + 0x120) = (float)fparam_1;
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x24);
  *(float *)(param_1 + 0x124) = (float)fparam_2;
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x20);
  return;
}

/* _glMultiTexCoord2f_Exec @ 0x1d1e4 (40 bytes) */
void _glMultiTexCoord2f_Exec(int param_1,uint param_2,float fparam_1,float fparam_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x24);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  iVar3 = param_1 + (param_2 & 7) * 0x10;
  *(float *)(iVar3 + 0x120) = (float)fparam_1;
  *(undefined4 *)(iVar3 + 300) = uVar1;
  *(float *)(iVar3 + 0x124) = (float)fparam_2;
  *(undefined4 *)(iVar3 + 0x128) = uVar2;
  return;
}

/* _glVertex2f_Exec @ 0x1d20c (44 bytes) */
void _glVertex2f_Exec(param_1)
  int param_1;
{
  code *UNRECOVERED_JUMPTABLE;
  undefined8 in_f1;
  undefined8 in_f2;
  
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x28);
  }
                    
                    
  (*((int (*)(int,double,double,double,double))UNRECOVERED_JUMPTABLE))
            (param_1, in_f1, in_f2, (double)*(float *)(param_1 + 0x20), (double)*(float *)(param_1 + 0x24));
  return;
}

/* _gleSetVertexSubmitFunc @ 0x1d238 (156 bytes) */
void _gleSetVertexSubmitFunc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(param_1,0);
  UNRECOVERED_JUMPTABLE = (code *)*puVar1;
  *(code **)(param_1 + 0x4888) = UNRECOVERED_JUMPTABLE;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    *(code **)(param_1 + 0x4884) = UNRECOVERED_JUMPTABLE;
  }
                    
                    
  (*((int (*)(int,double,double,double,double))UNRECOVERED_JUMPTABLE))(param_1, fparam_1, fparam_2, fparam_3, fparam_4);
  return;
}

/* _gleBuildVertexFuncNO @ 0x1d2d4 (2472 bytes) */
int _gleBuildVertexFuncNO(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  uint *param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint *param_7;
  undefined4 param_8;
{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  uint *puVar11;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  uint *puVar15;
  byte *pbVar16;
  int *piVar17;
  int iVar18;
  ushort *puVar19;
  uint *puVar20;
  int *piVar21;
  int *piVar22;
  int iVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  uint uVar27;
  uint uStack_d0;
  uint auStack_cc [33];
  
  if (param_2 == 3) {
    _gleSetFunctionIDToList(param_1,*(int *)(param_1 + 0x4a60) + 0x30,&uStack_d0);
  }
  else {
    if (((*(char *)(param_1 + 0x7580) == '\0') || (*(int *)(param_1 + 0x4e1c) != 0x1c00)) ||
       (*(byte **)(param_1 + 0x48d0) == (byte *)0x0)) {
      if (*(char *)(param_1 + 0x4664) == '\0') {
        iVar26 = *(int *)(param_1 + 0x5434);
        if (iVar26 == 0) {
          param_3 = &uStack_d0;
          _gleSetFuncOutputDesc(param_1,param_2,param_3);
          goto LAB_0001d42c;
        }
      }
      else {
        iVar26 = *(int *)(param_1 + 0x5434);
      }
      if (iVar26 == 0) {
        uVar25 = *(uint *)(*(int *)(param_1 + 0x5420) + 0x4cc);
      }
      else {
        param_7 = *(uint **)(*(int *)(param_1 + 0x5430) + 0x20);
        uVar25 = param_7[0x142];
      }
      uVar14 = 0;
      if (uVar25 != 0) {
        uVar14 = *(undefined4 *)(uVar25 + 0x20);
        uVar25 = uVar25 + *(int *)(uVar25 + 0x24) * 8;
      }
      param_3 = &uStack_d0;
      param_4 = (uint)(*(int *)(param_1 + 0x34d0) != 0x1b021b02);
      _gleVPSetFuncOutputDesc(uVar25,uVar14,param_3,param_4);
    }
    else {
      if (((param_2 != 1) || (*(int *)(param_1 + 0x48ec) != 0)) ||
         (pbVar16 = *(byte **)(param_1 + 0x48d4), *(byte **)(param_1 + 0x48d4) == (byte *)0x0)) {
        pbVar16 = *(byte **)(param_1 + 0x48d0);
      }
      iVar26 = ((int)(*pbVar16 + 1) >> 1) + 1;
      if (iVar26 != 0) {
        param_7 = &uStack_d0;
        iVar23 = 0;
        do {
          param_7[iVar23] = *(uint *)(pbVar16 + iVar23 * 4);
          iVar26 = iVar26 + -1;
          iVar23 = iVar23 + 1;
        } while (iVar26 != 0);
      }
    }
LAB_0001d42c:
    if (param_2 == 0) {
      ((void (*)())_gleSetFunctionIDFromCurrent)(param_1,&uStack_d0,param_3,param_4,param_5,param_6,param_7,param_8);
    }
    else if (*(int *)(param_1 + 0x48ec) == 0) {
      _gleSetFunctionIDFromArray(param_1,*(int *)(param_1 + 0x4a60) + 0x30,&uStack_d0);
    }
    else {
      _gleSetFunctionIDFromList(param_1,*(int *)(param_1 + 0x48ec),&uStack_d0);
    }
  }
  uVar25 = uStack_d0 >> 0x18;
  switch(param_2) {
  case 0:
    piVar17 = (int *)(param_1 + 0x48a0);
    break;
  case 1:
    piVar17 = (int *)(param_1 + 0x48a8);
    break;
  case 2:
    piVar17 = (int *)(param_1 + 0x48b0);
    break;
  default:
    piVar17 = (int *)(param_1 + 0x48b8);
    break;
  case 4:
    piVar17 = (int *)(param_1 + 0x48c0);
  }
  piVar21 = (int *)*piVar17;
  iVar26 = uVar25 + 1;
  piVar22 = piVar21;
  do {
    iVar23 = 0;
    if ((iVar26 != 0) && (uStack_d0 == piVar22[3])) {
      puVar15 = (uint *)(piVar22 + 3);
      puVar8 = &uStack_d0;
      do {
        iVar23 = iVar23 + 1;
        if (iVar26 <= iVar23) break;
        puVar8 = puVar8 + 1;
        puVar15 = puVar15 + 1;
      } while (*puVar8 == *puVar15);
    }
    if (iVar23 == iVar26) {
      if (piVar22 == piVar21) goto LAB_0001de0c;
      _gleMoveFuncCacheElem(piVar21,piVar22);
      goto LAB_0001de08;
    }
    piVar22 = (int *)*piVar22;
  } while (piVar22 != piVar21);
  iVar23 = ((int (*)())_gleCreateFuncCacheElem)(piVar22,0xf0);
  if (iVar26 != 0) {
    puVar8 = (uint *)(iVar23 + 0xc);
    puVar15 = &uStack_d0;
    do {
      uVar6 = *puVar15;
      puVar15 = puVar15 + 1;
      *puVar8 = uVar6;
      puVar8 = puVar8 + 1;
      iVar26 = iVar26 + -1;
    } while (iVar26 != 0);
  }
  if (*(short *)((int)piVar17 + 6) == *(short *)(piVar17 + 1)) {
    _gleDeleteFuncCacheElem(*(undefined4 *)(iVar23 + 4));
  }
  else {
    *(short *)((int)piVar17 + 6) = *(short *)((int)piVar17 + 6) + 1;
  }
  iVar26 = uVar25 - 4;
  if (iVar26 < 0) {
    iVar26 = 0;
  }
  iVar26 = iVar23 + iVar26 * 4;
  puVar8 = (uint *)(iVar26 + 0x20);
  bVar1 = param_2 != 4;
  uVar9 = ((int (*)())_gleCalculateOptions)(&uStack_d0,uVar25);
  *(uint **)(iVar23 + 8) = puVar8;
  uVar6 = uStack_d0 & 0xff;
  uVar24 = uVar6 << 2;
  if (!bVar1) {
    *(undefined4 *)(iVar26 + 0x20) = 0x7c0802a6;
    puVar8 = (uint *)(iVar26 + 0x3c);
    *(undefined4 *)(iVar26 + 0x24) = 0x90010008;
    *(undefined4 *)(iVar26 + 0x28) = 0x9421fe5c;
    *(undefined4 *)(iVar26 + 0x2c) = 0x81034a60;
    *(undefined4 *)(iVar26 + 0x30) = 0x7c862378;
    *(undefined4 *)(iVar26 + 0x34) = 0x80880010;
    *(undefined4 *)(iVar26 + 0x38) = 0x80a34858;
  }
  puVar15 = puVar8;
  switch(uStack_d0 >> 0x10 & 0xf) {
  default:
    (*(volatile unsigned int *)0x0) = 0;
    break;
  case 1:
    *puVar8 = 0x90c348cc;
    puVar8[1] = 0x80e34978;
    puVar8[2] = 0x7cc730ae;
    puVar15 = puVar8 + 3;
    puVar8 = puVar8 + 1;
    break;
  case 3:
    *puVar8 = 0x90c348cc;
    uVar24 = 0x54c6083c;
    uVar7 = 0x7cc7322e;
    goto code_r0x0001d73c;
  case 5:
    *puVar8 = 0x90c348cc;
    uVar24 = 0x54c6103a;
    uVar7 = 0x7cc7302e;
code_r0x0001d73c:
    puVar8[1] = 0x80e34978;
    puVar8[2] = uVar24;
    puVar8[3] = uVar7;
    puVar15 = puVar8 + 4;
    puVar8 = puVar8 + 1;
    break;
  case 6:
    *puVar8 = 0x7d054378;
    puVar15 = puVar8 + 1;
    break;
  case 7:
    if (uVar6 == 0) {
      puVar15 = puVar8 + 1;
      *puVar8 = 0x7c872378;
    }
    else {
      uVar7 = 0x1f - LZCOUNT(uVar24);
      *puVar8 = 0x810348f0;
      if ((uVar24 & (-2 << (uVar7 & 0x1f) | 0xfffffffeU >> 0x20 - (uVar7 & 0x1f))) == 0) {
        uVar24 = uVar7 * 0x800 | 0xc90000 | (0x1f - uVar7) * 2 | 0x54000000;
      }
      else {
        uVar24 = uVar24 | 0x1d260000;
      }
      puVar8[1] = uVar24;
      puVar8[2] = 0x7ce84a14;
      puVar15 = puVar8 + 3;
    }
    break;
  case 0xe:
    break;
  }
  if ((uStack_d0 & 0x400000) != 0) {
    uVar24 = uStack_d0 >> 6 & 0x3fc;
    if ((*(uint *)PTR__gle_processor_0011204c & 0x40) == 0) {
      *puVar15 = 0x3900001f;
      puVar15[1] = 0x7c0547ec;
      puVar15 = puVar15 + 2;
      if (0x20 < uVar24) {
        uVar24 = uVar24 - 1 >> 5;
        do {
          *puVar15 = 0x39080020;
          puVar15[1] = 0x7c0547ec;
          puVar15 = puVar15 + 2;
          uVar24 = uVar24 - 1;
        } while (uVar24 != 0);
      }
    }
    else {
      *puVar15 = 0x3900007f;
      puVar15[1] = 0x7c2547ec;
      puVar15 = puVar15 + 2;
      if (0x80 < uVar24) {
        uVar24 = uVar24 - 1 >> 7;
        do {
          *puVar15 = 0x39080080;
          puVar15[1] = 0x7c2547ec;
          puVar15 = puVar15 + 2;
          uVar24 = uVar24 - 1;
        } while (uVar24 != 0);
      }
    }
  }
  puVar10 = (uint *)((int (*)())_gleLoadForOptionsNO)(puVar15,uVar9);
  if (uVar25 != 0) {
    puVar20 = &uStack_d0;
    puVar19 = (ushort *)((int)auStack_cc + uVar25 * 2);
    uVar24 = 0;
    puVar11 = puVar10;
    do {
      uVar2 = *(ushort *)(puVar20 + 1);
      uVar7 = (uint)(uVar2 >> 10);
      uVar13 = uVar24;
      if (uVar7 == 6) {
        puVar10 = puVar11;
        if ((uVar9 & 0x40) == 0) {
          if ((*puVar19 >> 10 & 0xf) == 0xe) {
            uVar7 = 0x892302ec;
LAB_0001d970:
            *puVar11 = uVar7;
            uVar13 = uVar24;
          }
          else {
            uVar13 = *puVar19 & 0x3ff;
            if ((uVar6 == 0) && (param_2 != 2)) {
              puVar11 = (uint *)_gleSetArrayLoadAddressNO(puVar11,puVar15,0x4910,uVar13);
              uVar7 = 0x89270000;
              goto LAB_0001d970;
            }
            *puVar11 = uVar13 - uVar24 & 0xffff | 0x38e70000;
            puVar11 = puVar11 + 1;
            *puVar11 = 0x81270000;
          }
          uVar2 = *(ushort *)(puVar20 + 1);
          puVar11 = puVar11 + 1;
          uVar3 = uVar2 >> 6 & 3;
          if (uVar3 == 1) {
            uVar24 = (uVar2 & 0x3f) << 2 | 0x99250000;
LAB_0001d9b8:
            *puVar11 = uVar24;
            uVar24 = uVar13;
LAB_0001dcc8:
            puVar11 = puVar11 + 1;
            uVar13 = uVar24;
            puVar10 = puVar11;
          }
          else {
            puVar10 = puVar11;
            if (uVar3 < 2) {
              if (uVar3 == 0) {
                iVar26 = _gleRTCAddAChunk_b50a8(&_gleSetEdgeBitRTC,puVar11);
                puVar11 = puVar11 + iVar26;
                puVar10 = puVar11;
              }
            }
            else if (uVar3 == 3) {
              uVar24 = (uVar2 & 0x3f) << 2 | 0x91250000;
              goto LAB_0001d9b8;
            }
          }
        }
      }
      else {
        if (uVar7 < 0x20) {
          uVar3 = *puVar19;
          iVar18 = (uVar2 >> 8 & 3) + 1;
          uVar4 = uVar2 >> 6 & 3;
          uVar13 = uVar3 >> 10 & 0xf;
          iVar26 = (uVar3 >> 0xe) + 1;
          if (uVar13 == 0xe) {
            if (((uVar2 >> 10 == 0) || (uVar7 == 0x10)) ||
               (((iVar12 = 0x2a0, uVar7 != 2 &&
                 (((iVar12 = 0x2c0, uVar7 != 4 && (iVar12 = 0x2b0, uVar7 != 1)) &&
                  (iVar12 = 0x2cc, uVar7 != 3)))) &&
                ((iVar12 = 0x2d0, uVar7 != 5 && (iVar12 = uVar7 * 0x10 + 0xa0, iVar12 == 0)))))) {
              uVar27 = 0;
            }
            else {
              uVar27 = uStack_d0 >> 0x13 & 4;
              uVar13 = 6;
              puVar11 = (uint *)((int (*)())_gleLoadDataElementFromCtxNO)(puVar11,iVar26,uVar27,iVar12);
            }
          }
          else {
            uVar27 = uVar3 & 0x3ff;
            if ((uVar6 != 0) || (param_2 == 2)) {
              uVar14 = 0;
              *puVar11 = uVar27 - uVar24 & 0xffff | 0x38e70000;
              puVar11 = puVar11 + 1;
              uVar24 = uVar27;
            }
            else {
              puVar11 = (uint *)_gleSetArrayLoadAddressNO(puVar11,puVar15,uVar7 * 4 + 0x48f8,uVar27)
              ;
              uVar14 = 0;
              if (((uStack_d0 & 0x800000) != 0) && ((uVar3 & 3) == 0)) {
                uVar14 = 1;
              }
            }
            if ((uVar7 == 5) && (iVar18 == 4)) {
              iVar18 = 5;
            }
            if (((((1 < uVar13) && (uVar13 != 8)) && (uVar13 != 9)) || (uVar27 = 1, uVar4 != 1)) &&
               (((((1 < uVar13 - 2 && (uVar13 != 10)) && (uVar13 != 0xb)) ||
                 (uVar27 = 2, uVar4 != 2)) &&
                ((uVar13 != 6 || (uVar27 = 4, (uStack_d0 & 0x200000) == 0)))))) {
              uVar27 = 0;
            }
            puVar11 = (uint *)_gleLoadDataElementNO(puVar11,iVar26,uVar13,uVar27,uVar14);
          }
          uVar2 = *(ushort *)(puVar20 + 1);
          uVar7 = uStack_d0;
        }
        else {
          if (0x29 < uVar7) {
            if (uVar7 < 0x2c) {
              if ((uStack_d0 >> 0x10 & 0xf) == 6) {
                *puVar11 = 0x39200001;
                puVar11[1] = (uVar7 - 0x1f) * 0x10000 | 0x912001e0;
                puVar11 = puVar11 + 2;
                uVar2 = *(ushort *)(puVar20 + 1);
              }
              *puVar11 = (uVar7 - 0x1f) * 0x200000 | (uVar2 & 0x3f) << 2 | 0x90050000;
              puVar10 = puVar11 + 1;
              goto LAB_0001dcd0;
            }
            *puVar11 = 0x812302ec;
            puVar11 = puVar11 + 1;
            *puVar11 = (*(ushort *)(puVar20 + 1) & 0x3f) << 2 | 0x91250000;
            goto LAB_0001dcc8;
          }
          uVar14 = 0;
          iVar18 = (uVar2 >> 8 & 3) + 1;
          iVar26 = (*puVar19 >> 0xe) + 1;
          if ((((0x21 < uVar7) && (uVar14 = 0x10, 0x23 < uVar7)) && (uVar14 = 0x20, 0x25 < uVar7))
             && (uVar14 = 0x30, 0x27 < uVar7)) {
            uVar14 = 0x40;
          }
          uVar27 = uStack_d0 >> 0x13 & 4;
          puVar11 = (uint *)_gleLoadDataElementFromMatNO(puVar11,iVar26,uVar27,uVar14,uVar7 & 1);
          uVar2 = *(ushort *)(puVar20 + 1);
          uVar7 = uStack_d0 >> 0x15 & 1;
          uVar13 = 6;
        }
        puVar10 = (uint *)((int (*)())_gleStoreDataElementNO)(puVar11,(uVar2 & 0x3f) << 2,iVar26,uVar13,uVar27,iVar18,uVar7);
        uVar13 = uVar24;
      }
LAB_0001dcd0:
      uVar25 = uVar25 - 1;
      puVar20 = (uint *)((int)puVar20 + 2);
      puVar19 = puVar19 + 1;
      uVar24 = uVar13;
      puVar15 = puVar11;
      puVar11 = puVar10;
    } while (uVar25 != 0);
  }
  uVar25 = uStack_d0 >> 6 & 0x3fc;
  if (bVar1) {
    if (param_2 == 1) {
      puVar10 = (uint *)_gleArrayIncAndStoreVertexLoop
                                  (puVar10,puVar8,uVar25,uStack_d0 >> 0x10 & 0xf);
    }
    else if ((uStack_d0 >> 0x10 & 0xf) == 6) {
      *puVar10 = uVar25 | 0x39250000;
      puVar10[1] = 0x91234858;
      puVar10 = puVar10 + 2;
    }
    else {
      *puVar10 = uVar25 | 0x38650000;
      puVar10 = puVar10 + 1;
    }
  }
  else {
    puVar10 = (uint *)_gleArrayElemAddPrimitiveFlushFuncCall(puVar10,uVar25);
  }
  if (bVar1) {
    *puVar10 = 0x4e800020;
  }
  else {
    puVar10[1] = 0x7c0803a6;
    *puVar10 = 0x800101ac;
    puVar10[2] = 0x302101a4;
    puVar10 = puVar10 + 3;
    *puVar10 = 0x4e800020;
  }
  iVar26 = (int)puVar10 + (-0x19 - iVar23) >> 2;
  if (0xf0 < iVar26) {
                    
    _exit(1);
  }
  piVar22 = (int *)_gleShrinkFuncCacheElem(iVar23,iVar26);
  puVar5 = PTR__glePushInstructions_00112054;
  iVar23 = (int)piVar22 + (0x20 - (iVar23 + 0x20));
  piVar22[2] = piVar22[2] + iVar23;
  (**(code **)puVar5)(iVar26,piVar22 + 8,iVar23);
LAB_0001de08:
  *piVar17 = (int)piVar22;
LAB_0001de0c:
  return piVar22 + 2;
}

/* _gleSetFunctionIDFromCurrent @ 0x1de2c (92 bytes) */
void _gleSetFunctionIDFromCurrent(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  ushort uVar1;
  int iVar2;
  uint *puVar3;
  ushort *puVar4;
  uint uVar5;
  
  iVar2 = *(int *)(param_1 + 0x4674);
  uVar5 = *param_2 >> 0x18;
  *param_2 = *param_2 | 0x60000;
  if (uVar5 == 0) {
    return;
  }
  puVar3 = param_2 + 1;
  puVar4 = (ushort *)((int)param_2 + uVar5 * 2 + 4);
  do {
    uVar1 = *(ushort *)puVar3;
    puVar3 = (uint *)((int)puVar3 + 2);
    *puVar4 = (*(byte *)(iVar2 + 0x400 + (uint)(uVar1 >> 10)) - 1) * 0x4000 | 0x3800;
    puVar4 = puVar4 + 1;
    uVar5 = uVar5 - 1;
  } while (uVar5 != 0);
  return;
}

/* _gleCreateFuncCacheElem @ 0x1de88 (156 bytes) */
int _gleCreateFuncCacheElem(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  piVar1 = (int *)_gleDCBAlloc(param_2 * 4 + 0x20);
  piVar2 = (int *)0x0;
  if (piVar1 != (int *)0x0) {
    _gleBlockClear(piVar1 + 8,param_2);
    puVar3 = *(undefined4 **)(param_1 + 4);
    *puVar3 = piVar1;
    piVar1[1] = (int)puVar3;
    piVar1[param_2 + 7] = 0;
    piVar1[5] = -1;
    *(int **)(param_1 + 4) = piVar1;
    piVar1[2] = -1;
    piVar1[3] = -1;
    piVar1[4] = -1;
    *piVar1 = param_1;
    piVar2 = piVar1;
  }
  return piVar2;
}

/* _gleCalculateOptions @ 0x1df24 (468 bytes) */
int _gleCalculateOptions(param_1, param_2)
  uint *param_1;
  int param_2;
{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  ushort *puVar6;
  uint *puVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  uVar5 = 0;
  iVar11 = 0;
  iVar10 = -1;
  iVar9 = 0;
  if (0 < param_2) {
    puVar6 = (ushort *)((int)param_1 + param_2 * 2 + 4);
    puVar7 = param_1 + 1;
    iVar12 = param_2;
    do {
      uVar4 = *(ushort *)puVar7;
      uVar1 = (uint)(uVar4 >> 10);
      if (uVar1 == 6) {
        if (((*puVar6 >> 10 & 0xf) == 0xe) && ((uVar4 >> 6 & 3) == 1)) {
          iVar10 = (uVar4 & 0x3f) << 2;
        }
      }
      else if (uVar1 < 0x2a) {
        bVar2 = false;
        if (uVar1 < 0x20) {
          uVar3 = *(ushort *)((int)param_1 + (param_2 + iVar9) * 2 + 4) >> 10 & 0xf;
          if ((uVar3 < 6) || (uVar3 - 8 < 6)) {
            uVar4 = uVar4 >> 6 & 3;
            if ((((uVar3 < 2) || ((uVar3 == 8 || (uVar3 == 9)))) && (uVar4 == 1)) ||
               ((((uVar3 - 2 < 2 || (uVar3 == 10)) || (uVar3 == 0xb)) && (uVar4 == 2)))) {
              bVar2 = true;
            }
            else {
              uVar5 = uVar5 | 4;
            }
          }
        }
        else {
          uVar5 = uVar5 | 1 << (uVar1 & 1);
        }
        uVar8 = (*(ushort *)puVar7 >> 8 & 3) + 1;
        uVar4 = (*(ushort *)((int)param_1 + (param_2 + iVar9) * 2 + 4) >> 0xe) + 1;
        if ((uVar4 < uVar8) && (!bVar2)) {
          if ((uVar1 == 5) || (uVar8 != 4)) {
            uVar5 = uVar5 | 8;
          }
          else if (uVar4 == 3) {
            uVar5 = uVar5 | 0x10;
          }
          else if ((*param_1 & 0x200000) == 0) {
            uVar5 = uVar5 | 0x18;
          }
          else if (uVar4 == 2) {
            uVar5 = uVar5 | 0x20;
          }
          else {
            uVar5 = uVar5 | 0x28;
          }
        }
      }
      else if (uVar1 < 0x2c) {
        uVar5 = uVar5 | 1 << (uVar1 - 0x2a & 0x3f);
      }
      else {
        iVar11 = (uVar4 & 0x3f) << 2;
      }
      iVar9 = iVar9 + 1;
      puVar6 = puVar6 + 1;
      puVar7 = (uint *)((int)puVar7 + 2);
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  if (iVar10 == iVar11) {
    uVar5 = uVar5 | 0x40;
  }
  return uVar5;
}

/* _gleLoadForOptionsNO @ 0x1e0f8 (172 bytes) */
int _gleLoadForOptionsNO(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  if ((param_2 & 1) != 0) {
    *param_1 = 0x81634dd0;
    param_1 = param_1 + 1;
  }
  if ((param_2 & 2) != 0) {
    *param_1 = 0x81834dd4;
    param_1 = param_1 + 1;
  }
  if ((param_2 & 4) != 0) {
    *param_1 = 0x8043002c;
    param_1[1] = 0xc94200e0;
    param_1[2] = 0xc96200e8;
    param_1 = param_1 + 3;
  }
  if ((param_2 & 8) != 0) {
    *param_1 = 0xc0e30020;
    param_1 = param_1 + 1;
  }
  if ((param_2 & 0x10) != 0) {
    *param_1 = 0xc1030024;
    param_1 = param_1 + 1;
  }
  if ((param_2 & 0x20) == 0) {
    return param_1;
  }
  *param_1 = 0xc9230020;
  return param_1 + 1;
}

/* _gleStoreDataElementNO @ 0x1e1a4 (2540 bytes) */
int _gleStoreDataElementNO(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  uint *param_1;
  uint param_2;
  int param_3;
  uint param_4;
  int param_5;
  int param_6;
  uint param_7;
{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  if (param_5 == 1) {
    if ((param_3 < 4) && (param_6 == 4)) {
      uVar4 = 0x7f;
      if ((param_4 != 8) && ((param_4 < 9 || (uVar4 = 0xff, param_4 != 9)))) {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = 0;
    }
    if ((param_7 >> 0x14 & 1) == 0) {
      if (param_3 == 2) {
        if (param_6 == 3) {
          uVar4 = param_2 + 2;
          uVar2 = param_2 & 0xffff | 0xb0050000;
          *param_1 = 0x39400000;
          goto LAB_0001e570;
        }
        if (param_6 < 4) {
          if (param_6 != 2) {
            return param_1;
          }
switchD_0001e87c_caseD_1:
          goto LAB_0001e284;
        }
        if (param_6 == 4) {
          uVar2 = 0x5400801e;
          goto LAB_0001e59c;
        }
        if (param_6 != 5) {
          return param_1;
        }
switchD_0001e87c_caseD_2:
        uVar4 = 0x5400801e;
LAB_0001e588:
        uVar2 = param_2 & 0xffff | 0x90050000;
        goto LAB_0001e304;
      }
      if (param_3 < 3) {
        if (param_3 != 1) {
          return param_1;
        }
        switch(param_6) {
        default:
          goto switchD_0001e254_caseD_0;
        case 1:
          goto LAB_0001e4c8;
        case 2:
          uVar4 = 0x5400402e;
          uVar2 = param_2 & 0xffff | 0xb0050000;
          goto LAB_0001e304;
        case 3:
          *param_1 = 0x5400402e;
          uVar2 = param_2 + 2 & 0xffff | 0x98050000;
          param_1 = param_1 + 1;
          *param_1 = param_2 & 0xffff | 0xb0050000;
          break;
        case 4:
          uVar2 = 0x5400c00e;
LAB_0001e59c:
          *param_1 = uVar2;
          uVar2 = param_2 & 0xffff | 0x90050000;
          param_1 = param_1 + 1;
          *param_1 = uVar4 | 0x60000000;
          break;
        case 5:
          uVar4 = 0x5400c00e;
          goto LAB_0001e588;
        }
        goto LAB_0001e308;
      }
      if (param_3 != 3) {
        bVar1 = param_3 == 4;
LAB_0001e8f0:
        if (!bVar1) {
          return param_1;
        }
        goto switchD_0001e254_caseD_5;
      }
      if (param_6 == 4) {
        *param_1 = 0x5400801e;
        param_1[1] = 0x554a402e;
        param_1[2] = 0x7c005378;
        puVar3 = param_1 + 3;
        *puVar3 = uVar4 | 0x60000000;
      }
      else {
        if (param_6 < 5) {
          if (param_6 != 3) {
            return param_1;
          }
          uVar4 = param_2 & 0xffff | 0xb0050000;
          uVar2 = param_2 + 2 & 0xffff | 0x99450000;
          goto LAB_0001e304;
        }
        if (param_6 != 5) {
          return param_1;
        }
        *param_1 = 0x5400801e;
        param_1[1] = 0x554a402e;
        puVar3 = param_1 + 2;
        *puVar3 = 0x7c005378;
      }
      uVar4 = param_2 & 0xffff | 0x90050000;
LAB_0001ebe0:
      param_1 = puVar3 + 1;
      *param_1 = uVar4;
    }
    else {
      if (param_3 == 2) {
        if (param_6 == 3) {
          uVar4 = param_2 + 1;
          *param_1 = param_2 + 2 & 0xffff | 0x39400000;
          param_1 = param_1 + 1;
          *param_1 = 0x7c05572c;
          uVar2 = param_2 & 0xffff | 0x39400000;
LAB_0001e570:
          param_1 = param_1 + 1;
          *param_1 = uVar2;
          uVar2 = uVar4 & 0xffff | 0x99450000;
          goto LAB_0001e308;
        }
        if (3 < param_6) {
          if (param_6 != 4) {
            if (param_6 != 5) {
              return param_1;
            }
            uVar4 = param_2 & 0xffff | 0x39400000;
            *param_1 = 0x5400801e;
            uVar2 = 0x7c05552c;
            goto LAB_0001e35c;
          }
          *param_1 = 0x5400801e;
          param_1[1] = param_2 & 0xffff | 0x39400000;
          puVar3 = param_1 + 2;
          *puVar3 = uVar4 | 0x60000000;
          goto LAB_0001e448;
        }
        if (param_6 != 2) {
          return param_1;
        }
        uVar2 = 0x7c05572c;
        uVar4 = param_2 + 2 & 0xffff | 0x39400000;
      }
      else {
        if (param_3 < 3) {
          if (param_3 != 1) {
            return param_1;
          }
          switch(param_6) {
          default:
            goto switchD_0001e254_caseD_0;
          case 1:
            param_2 = param_2 + 3;
LAB_0001e4c8:
            uVar4 = param_2 & 0xffff | 0x98050000;
            break;
          case 2:
switchD_0001e254_caseD_2:
            param_2 = param_2 + 2;
LAB_0001e284:
            uVar4 = param_2 & 0xffff | 0xb0050000;
            break;
          case 3:
            uVar4 = param_2 + 2 & 0xffff | 0xb0050000;
            *param_1 = 0x39400000;
            uVar2 = param_2 + 1 & 0xffff | 0x99450000;
LAB_0001e35c:
            param_1[1] = uVar4;
            param_1 = param_1 + 2;
            *param_1 = uVar2;
            goto LAB_0001ebe4;
          case 4:
            uVar4 = uVar4 << 8 | 0x64000000;
            goto LAB_0001e588;
          case 5:
switchD_0001e254_caseD_5:
            uVar4 = param_2 & 0xffff | 0x90050000;
          }
          goto LAB_0001e288;
        }
        if (param_3 == 3) {
          if (param_6 == 4) {
            *param_1 = 0x5400801e;
            param_1[1] = 0x554a402e;
            param_1[2] = 0x7c005378;
            uVar4 = uVar4 | 0x60000000;
            puVar3 = param_1 + 3;
            *puVar3 = param_2 & 0xffff | 0x39400000;
          }
          else {
            if (param_6 < 5) {
              if (param_6 != 3) {
                return param_1;
              }
              uVar4 = param_2 + 2 & 0xffff | 0x39400000;
              *param_1 = param_2 + 1 & 0xffff | 0x99450000;
              uVar2 = 0x7c05572c;
              goto LAB_0001e35c;
            }
            if (param_6 != 5) {
              return param_1;
            }
            *param_1 = 0x5400801e;
            param_1[1] = 0x554a402e;
            uVar4 = param_2 & 0xffff | 0x39400000;
            puVar3 = param_1 + 2;
            *puVar3 = 0x7c005378;
          }
          puVar3 = puVar3 + 1;
          *puVar3 = uVar4;
LAB_0001e448:
          uVar4 = 0x7c05552c;
          goto LAB_0001ebe0;
        }
        if (param_3 != 4) {
          return param_1;
        }
        uVar4 = param_2 & 0xffff | 0x39400000;
        uVar2 = 0x7c05552c;
      }
LAB_0001e304:
      *param_1 = uVar4;
LAB_0001e308:
      param_1 = param_1 + 1;
      *param_1 = uVar2;
    }
  }
  else {
    if (param_5 == 2) {
      if ((param_3 < 4) && (param_6 == 4)) {
        uVar4 = 0x7fff;
        if ((param_4 != 10) && ((param_4 < 0xb || (uVar4 = 0xffff, param_4 != 0xb)))) {
          uVar4 = 1;
        }
      }
      else {
        uVar4 = 0;
      }
      if ((param_7 >> 0x14 & 1) == 0) {
        if (param_3 != 2) {
          if (2 < param_3) {
            if (param_3 == 3) {
              if (param_6 == 4) {
                uVar2 = 0x554a0000;
                uVar4 = uVar4 | 0x614a0000;
                goto LAB_0001e9d8;
              }
              if (4 < param_6) {
                if (param_6 != 5) {
                  return param_1;
                }
                uVar2 = param_2 + 4 & 0xffff;
                uVar4 = 0x554a801e;
                goto LAB_0001e9bc;
              }
              if (param_6 != 3) {
                return param_1;
              }
              uVar4 = param_2 & 0xffff | 0x90050000;
              uVar2 = param_2 + 4 & 0xffff | 0xb1450000;
            }
            else {
              if (param_3 != 4) {
                return param_1;
              }
              uVar4 = param_2 & 0xffff | 0x90050000;
              uVar2 = param_2 + 4 & 0xffff | 0x91450000;
            }
            goto LAB_0001e304;
          }
          if (param_3 != 1) {
            return param_1;
          }
          switch(param_6) {
          default:
            goto switchD_0001e254_caseD_0;
          case 1:
            goto switchD_0001e87c_caseD_1;
          case 2:
            goto switchD_0001e87c_caseD_2;
          case 3:
            uVar2 = 0x5400801e;
            uVar4 = param_2 + 4;
            goto LAB_0001e8b0;
          case 4:
            uVar2 = 0x54000000;
            uVar4 = uVar4 | 0x39400000;
            break;
          case 5:
            uVar4 = 0x5400801e;
LAB_0001e780:
            *param_1 = uVar4;
            param_1 = param_1 + 1;
            *param_1 = 0x39400000;
LAB_0001e79c:
            uVar2 = param_2 + 4 & 0xffff;
            param_1 = param_1 + 1;
            *param_1 = param_2 & 0xffff | 0x90050000;
            goto LAB_0001e9c8;
          }
LAB_0001e9d8:
          uVar2 = uVar2 | 0x801e;
LAB_0001e9dc:
          *param_1 = uVar2;
          param_1[1] = uVar4;
          puVar3 = param_1 + 2;
          *puVar3 = param_2 & 0xffff | 0x90050000;
          uVar4 = param_2 + 4 & 0xffff | 0x91450000;
          goto LAB_0001ebe0;
        }
        if (param_6 != 3) {
          if (param_6 < 4) {
            bVar1 = param_6 == 2;
            goto LAB_0001e8f0;
          }
          if (param_6 != 4) {
            if (param_6 != 5) {
              return param_1;
            }
            goto switchD_0001e6ec_caseD_5;
          }
          uVar2 = param_2 + 4 & 0xffff;
          uVar4 = uVar4 | 0x39400000;
          goto LAB_0001e9bc;
        }
        uVar4 = param_2 + 4;
LAB_0001e920:
        *param_1 = 0x39400000;
LAB_0001e930:
        param_1 = param_1 + 1;
        *param_1 = param_2 & 0xffff | 0x90050000;
      }
      else {
        if (param_3 == 2) {
          if (param_6 == 3) {
            uVar2 = 0x5400803e;
            uVar4 = param_2 + 6;
LAB_0001e8b0:
            *param_1 = uVar2;
            param_1 = param_1 + 1;
            *param_1 = 0x39400000;
            goto LAB_0001e930;
          }
          if (param_6 < 4) {
            if (param_6 != 2) {
              return param_1;
            }
            uVar4 = 0x5400803e;
            goto LAB_0001e588;
          }
          if (param_6 != 4) {
            if (param_6 != 5) {
              return param_1;
            }
            uVar4 = 0x5400803e;
            goto LAB_0001e780;
          }
          uVar4 = uVar4 | 0x3d400000;
LAB_0001e818:
          uVar2 = 0x5400803e;
          goto LAB_0001e9dc;
        }
        if (param_3 < 3) {
          if (param_3 != 1) {
            return param_1;
          }
          switch(param_6) {
          default:
            goto switchD_0001e254_caseD_0;
          case 1:
            goto switchD_0001e254_caseD_2;
          case 2:
            goto switchD_0001e254_caseD_5;
          case 3:
            uVar4 = param_2 + 6;
            goto LAB_0001e920;
          case 4:
            uVar2 = param_2 + 4 & 0xffff;
            uVar4 = uVar4 | 0x3d400000;
            break;
          case 5:
switchD_0001e6ec_caseD_5:
            *param_1 = 0x39400000;
            goto LAB_0001e79c;
          }
LAB_0001e9bc:
          *param_1 = uVar4;
          param_1 = param_1 + 1;
          *param_1 = param_2 & 0xffff | 0x90050000;
LAB_0001e9c8:
          uVar2 = uVar2 | 0x91450000;
          goto LAB_0001e308;
        }
        if (param_3 != 3) {
          if (param_3 != 4) {
            return param_1;
          }
          uVar2 = 0x5400803e;
          uVar4 = 0x554a803e;
          goto LAB_0001e9dc;
        }
        if (param_6 == 4) {
          uVar4 = uVar4 | 0x654a0000;
          goto LAB_0001e818;
        }
        if (4 < param_6) {
          if (param_6 != 5) {
            return param_1;
          }
          uVar2 = param_2 + 4 & 0xffff;
          uVar4 = 0x5400803e;
          goto LAB_0001e9bc;
        }
        if (param_6 != 3) {
          return param_1;
        }
        uVar4 = param_2 + 6;
        *param_1 = 0x5400803e;
        param_1 = param_1 + 1;
        *param_1 = param_2 & 0xffff | 0x90050000;
      }
      uVar2 = uVar4 & 0xffff | 0xb1450000;
      goto LAB_0001e308;
    }
    if (param_3 == 2) {
      if (param_5 == 4) {
        *param_1 = param_2 & 0xffff | 0xd8250000;
      }
      else {
        *param_1 = param_2 & 0xffff | 0xd0250000;
        param_1 = param_1 + 1;
        *param_1 = param_2 + 4 & 0xffff | 0xd0450000;
      }
LAB_0001eaac:
      param_1 = param_1 + 1;
      if ((param_7 >> 0x15 & 1) == 0) {
        if (param_6 < 3) {
          return param_1;
        }
        uVar4 = param_2 + 8 & 0xffff | 0xd0e50000;
        goto LAB_0001eb54;
      }
      uVar4 = param_2 + 8;
      if (param_6 != 3) {
        if (param_6 == 4) {
          uVar4 = param_2 + 8 & 0xffff | 0xd9250000;
        }
        else {
          if (param_6 != 5) {
            return param_1;
          }
          uVar4 = param_2 + 8 & 0xffff | 0xd8e50000;
        }
        goto LAB_0001e288;
      }
    }
    else {
      if (param_3 < 3) {
        if (param_3 != 1) {
          return param_1;
        }
        *param_1 = param_2 & 0xffff | 0xd0250000;
        param_1 = param_1 + 1;
        if (param_6 < 2) {
          return param_1;
        }
        *param_1 = param_2 + 4 & 0xffff | 0xd0e50000;
        goto LAB_0001eaac;
      }
      if (param_3 != 3) {
        if (param_3 != 4) {
          return param_1;
        }
        if (param_5 == 4) {
          uVar4 = param_2 & 0xffff | 0xd8250000;
          uVar2 = param_2 + 8 & 0xffff | 0xd8650000;
          goto LAB_0001e304;
        }
        *param_1 = param_2 & 0xffff | 0xd0250000;
        param_1[1] = param_2 + 4 & 0xffff | 0xd0450000;
        puVar3 = param_1 + 2;
        *puVar3 = param_2 + 8 & 0xffff | 0xd0650000;
        uVar4 = param_2 + 0xc & 0xffff | 0xd0850000;
        goto LAB_0001ebe0;
      }
      if (param_5 == 4) {
        *param_1 = param_2 & 0xffff | 0xd8250000;
      }
      else {
        *param_1 = param_2 & 0xffff | 0xd0250000;
        param_1 = param_1 + 1;
        *param_1 = param_2 + 4 & 0xffff | 0xd0450000;
      }
      param_1 = param_1 + 1;
      uVar4 = param_2 + 8 & 0xffff | 0xd0650000;
LAB_0001eb54:
      *param_1 = uVar4;
      param_1 = param_1 + 1;
      if (param_6 == 4) {
        uVar4 = param_2 + 0xc & 0xffff | 0xd1050000;
        goto LAB_0001e288;
      }
      if (param_6 != 5) {
        return param_1;
      }
      uVar4 = param_2 + 0xc;
    }
    uVar4 = uVar4 & 0xffff | 0xd0e50000;
LAB_0001e288:
    *param_1 = uVar4;
  }
LAB_0001ebe4:
  param_1 = param_1 + 1;
switchD_0001e254_caseD_0:
  return param_1;
}

/* _gleLoadDataElementFromCtxNO @ 0x1ebf0 (200 bytes) */
int _gleLoadDataElementFromCtxNO(param_1, param_2, param_3, param_4)
  uint *param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  uint uVar1;
  
  if (param_3 == 4) {
    if (param_2 == 1) {
      uVar1 = param_4 & 0xffff | 0xc0230000;
    }
    else {
      if (param_2 < 2) {
        return param_1;
      }
      *param_1 = param_4 & 0xffff | 0xc8230000;
      param_1 = param_1 + 1;
      if (param_2 == 3) {
        uVar1 = param_4 + 8 & 0xffff | 0xc0630000;
      }
      else {
        if (param_2 != 4) {
          return param_1;
        }
        uVar1 = param_4 + 8 & 0xffff | 0xc8630000;
      }
    }
  }
  else {
    *param_1 = param_4 & 0xffff | 0xc0230000;
    if (param_2 < 2) {
      return param_1 + 1;
    }
    param_1[1] = param_4 + 4 & 0xffff | 0xc0430000;
    if (param_2 < 3) {
      return param_1 + 2;
    }
    param_1[2] = param_4 + 8 & 0xffff | 0xc0630000;
    param_1 = param_1 + 3;
    if (param_2 != 4) {
      return param_1;
    }
    uVar1 = param_4 + 0xc & 0xffff | 0xc0830000;
  }
  *param_1 = uVar1;
  return param_1 + 1;
}

