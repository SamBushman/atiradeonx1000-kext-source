#include "decls.h"

/* _glAlphaFunc_Exec @ 0x16484 (120 bytes) */
void _glAlphaFunc_Exec(int glContext,int func,float ref)
{
  undefined4 glErrorCode;
  double dVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (func - 0x200U < 8) {
      dVar2 = (double)*(float *)(glContext + 0x24);
      if ((dVar2 < ref) || (dVar2 = (double)*(float *)(glContext + 0x20), ref < dVar2)) {
        ref = dVar2;
      }
      *(float *)(glContext + 0x30c0) = (float)ref;
      *(short *)(glContext + 0x30c4) = (short)func;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 1;
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

/* _glDisable_Exec @ 0x164fc (108 bytes) */
double _glDisable_Exec(glContext, cap)
  int glContext;
  uint cap;
{
  undefined4 glErrorCode;
  uint *puVar2;
  
  puVar2 = (uint *)(*(int *)(glContext + 0x4850) + (cap & 0x3ff) * 0x10);
  if (*(short *)(glContext + 0x4a10) < 0) {
    do {
      if (*puVar2 == cap) {
                    
                    
        (*(code *)puVar2[1])(glContext,cap,0);
        return;
      }
      puVar2 = (uint *)puVar2[2];
    } while (puVar2 != (uint *)0x0);
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

/* _gleSetEnable_BLEND @ 0x16568 (32 bytes) */
void _gleSetEnable_BLEND(param_1, unusedArg2, param_3)
  int param_1;
  undefined4 unusedArg2;
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
void _gleSetEnable_DEPTH_TEST(param_1, unusedArg2, param_3)
  int param_1;
  undefined4 unusedArg2;
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
void _glDepthMask_Exec(glContext, flag)
  int glContext;
  int flag;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    *(byte *)(glContext + 0x31a4) = (byte)((uint)-flag >> 0x1f);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000;
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _gleSetEnable_CULL_FACE @ 0x165e8 (84 bytes) */
void _gleSetEnable_CULL_FACE(glContext, unusedArg2, param_3)
  int glContext;
  undefined4 unusedArg2;
  uint param_3;
{
  if (*(byte *)(glContext + 0x34da) != param_3) {
    *(char *)(glContext + 0x34da) = (char)param_3;
    _gleUpdatePolyMode(glContext);
    _gleUpdatePrimitiveData(glContext);
    return;
  }
  return;
}

/* _glActiveTexture_Exec @ 0x1663c (132 bytes) */
void _glActiveTexture_Exec(glContext, texture)
  int glContext;
  int texture;
{
  undefined4 glErrorCode;
  int iVar2;
  
  iVar2 = texture + -0x84c0;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((-1 < iVar2) &&
       ((iVar2 < (int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xb6) ||
        (iVar2 < (int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xba))))) {
      *(int *)(glContext + 0x53d4) = iVar2;
      if (7 < *(int *)(glContext + 0x4ff4) - 0x10U) {
        return;
      }
      *(int *)(glContext + 0x4ff4) = texture + -0x84b0;
      _gleUpdateMatrixMode(glContext);
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

/* _glTexEnvfv_Exec @ 0x166c0 (3216 bytes) */
void _glTexEnvfv_Exec(glContext, target, pname, params)
  int glContext;
  int target;
  uint pname;
  float *params;
{
  float floatZero;
  double twoPow31B;
  double twoPow31;
  int remaining2;
  int remaining;
  bool matchesAllowedEnum;
  byte dirtyBitIndex;
  float envColorR;
  float envColorA;
  float envColorB;
  float envColorG;
  float paramFloat;
  float alphaScale;
  float rgbScale;
  float floatOne;
  undefined4 glErrorCode;
  int texUnitState;
  int paramInt;
  int dirtyWordAt348;
  int unitDirtyBit;
  int glContextWord5424;
  float *cursor;
  undefined2 *dstCursor;
  uint paramValueInt;
  uint unitDirtyWord;
  int shaderOpError;
  int dirtyWordAt324;
  code *texEnvMode;
  code *combineAlpha;
  code *combineRgb;
  uint texUnit;
  double validateParamAsDouble;
  double paramAsDouble;
  
  floatOne = FLOAT_00108e54;
  floatZero = FLOAT_00108e50;
  twoPow31B = DOUBLE_00108d80;
  texUnit = *(uint *)(glContext + 0x53d4);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x86de) {
      texUnitState = glContext + texUnit * 0x7c;
      switch(pname) {
      case 0x86d9:
        paramAsDouble = (double)*params;
        if (DOUBLE_00108d80 <= paramAsDouble) {
          paramValueInt = (int)(paramAsDouble - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          paramValueInt = (uint)(int)*params;
        }
        if ((paramValueInt != 0x8536) && (paramValueInt != 0x8538)) goto switchD_00016744_caseD_86da;
        *(short *)(texUnitState + 0x356c) = (short)paramValueInt;
        break;
      default:
switchD_00016744_caseD_86da:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0001736c;
      case 0x86df:
        paramAsDouble = (double)*params;
        if (DOUBLE_00108d80 <= paramAsDouble) {
          paramValueInt = (int)(paramAsDouble - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          paramValueInt = (uint)(int)*params;
        }
        shaderOpError = _CheckNVShaderOperation(glContext,paramValueInt);
        if (shaderOpError != 0) {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          *(int *)(glContext + 0x7574) = shaderOpError;
          return;
        }
        *(short *)(texUnitState + 0x3564) = (short)paramValueInt;
        _gleUpdateTextureParams(glContext,texUnit);
        break;
      case 0x86e0:
        remaining = 4;
        cursor = params;
        do {
          paramFloat = *cursor;
          validateParamAsDouble = (double)paramFloat;
          cursor = cursor + 1;
          if (twoPow31B <= validateParamAsDouble) {
            paramValueInt = (int)(validateParamAsDouble - twoPow31B) ^ 0x80000000;
          }
          else {
            paramValueInt = (uint)(int)paramFloat;
          }
          if (((paramValueInt != 0x201) && (paramValueInt != 0x206)) && (*(int *)(glContext + 0x7574) == 0)) {
            *(undefined4 *)(glContext + 0x7574) = 0x500;
          }
          twoPow31 = DOUBLE_00108d80;
          remaining = remaining + -1;
        } while (remaining != 0);
        remaining2 = 4;
        dstCursor = (undefined2 *)(texUnitState + 0x3570);
        do {
          paramFloat = *params;
          paramAsDouble = (double)paramFloat;
          params = params + 1;
          if (twoPow31 <= paramAsDouble) {
            paramValueInt = (int)(paramAsDouble - twoPow31) ^ 0x80000000;
          }
          else {
            paramValueInt = (uint)(int)paramFloat;
          }
          if ((paramValueInt == 0x201) || (paramValueInt == 0x206)) {
            *dstCursor = (short)paramValueInt;
          }
          dstCursor = dstCursor + 1;
          remaining2 = remaining2 + -1;
        } while (remaining2 != 0);
        break;
      case 0x86e1:
        *(float *)(texUnitState + 0x3588) = *params;
        *(float *)(texUnitState + 0x358c) = params[1];
        *(float *)(texUnitState + 0x3590) = params[2];
        *(float *)(texUnitState + 0x3594) = params[3];
        break;
      case 0x86e2:
        *(float *)(texUnitState + 0x3598) = *params;
        break;
      case 0x86e3:
        *(float *)(texUnitState + 0x359c) = *params;
        break;
      case 0x86e4:
        paramAsDouble = (double)*params;
        if (DOUBLE_00108d80 <= paramAsDouble) {
          paramValueInt = (int)(paramAsDouble - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          paramValueInt = (uint)(int)*params;
        }
        if ((paramValueInt < 0x84c0) || (*(ushort *)(*(int *)(glContext + 0x468c) + 0xb4) + 0x84c0 <= paramValueInt)
           ) goto switchD_00016744_caseD_86da;
        *(short *)(texUnitState + 0x356a) = (short)paramValueInt;
        break;
      case 0x86e5:
        *(float *)(texUnitState + 0x357c) = *params;
        *(float *)(texUnitState + 0x3580) = params[1];
        *(float *)(texUnitState + 0x3584) = params[2];
      }
      unitDirtyWord = *(uint *)(glContext + 800);
      unitDirtyBit = 1;
    }
    else {
      if (target == 0x8861) {
        if (pname == 0x8862) {
          if (*params == FLOAT_00108e50) {
            texUnit = *(uint *)(glContext + 0x3444) &
                     (-2 << (texUnit & 0x1f) | 0xfffffffeU >> 0x20 - (texUnit & 0x1f));
          }
          else {
            texUnit = *(uint *)(glContext + 0x3444) | 1 << (texUnit & 0x3f);
          }
          *(uint *)(glContext + 0x3444) = texUnit;
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400000;
          return;
        }
        goto switchD_00016744_caseD_86da;
      }
      if (target != 0x2300) {
        if ((target == 0x8500) && (pname == 0x8501)) {
          unitDirtyBit = 0x10000;
          *(float *)(texUnit * 0x7c + glContext + 0x3560) = *params;
          unitDirtyWord = *(uint *)(glContext + 800);
          goto LAB_0001734c;
        }
        goto switchD_00016744_caseD_86da;
      }
      if (pname == 0x2200) {
        paramAsDouble = (double)*params;
        if (DOUBLE_00108d80 <= paramAsDouble) {
          texEnvMode = (code *)((int)(paramAsDouble - DOUBLE_00108d80) ^ 0x80000000);
        }
        else {
          texEnvMode = (code *)(int)*params;
        }
        if (texEnvMode != (code *)0x1e01) {
          if (texEnvMode < (code *)0x1e02) {
            if (texEnvMode != (code *)0x104) {
              if (texEnvMode < (code *)0x105) {
                matchesAllowedEnum = texEnvMode == (code *)0x0;
              }
              else {
                matchesAllowedEnum = texEnvMode == (code *)0xbe2;
              }
LAB_00016b00:
              if (!matchesAllowedEnum) goto switchD_00016744_caseD_86da;
            }
          }
          else {
            if (texEnvMode < (code *)0x2100) goto switchD_00016744_caseD_86da;
            if ((code *)0x2100 < texEnvMode) {
              matchesAllowedEnum = texEnvMode == (code *)0x8570;
              goto LAB_00016b00;
            }
          }
        }
        unitDirtyBit = 1;
        *(short *)(texUnit * 0x7c + glContext + 0x3538) = (short)texEnvMode;
        unitDirtyWord = *(uint *)(glContext + 800);
LAB_0001734c:
        *(uint *)(glContext + 800) = unitDirtyWord | unitDirtyBit << (texUnit & 0x3f);
        return;
      }
      if (pname == 0x2201) {
        envColorR = *params;
        texUnitState = glContext + texUnit * 0x7c;
        if (envColorR < FLOAT_00108e50) {
          *(float *)(texUnitState + 0x3524) = FLOAT_00108e50;
        }
        else if (FLOAT_00108e54 < envColorR) {
          *(float *)(texUnitState + 0x3524) = FLOAT_00108e54;
        }
        else {
          *(float *)(texUnitState + 0x3524) = envColorR;
        }
        envColorG = params[1];
        if (envColorG < floatZero) {
          *(float *)(texUnitState + 0x3528) = floatZero;
        }
        else if (floatOne < envColorG) {
          *(float *)(texUnitState + 0x3528) = floatOne;
        }
        else {
          *(float *)(texUnitState + 0x3528) = envColorG;
        }
        envColorB = params[2];
        if (envColorB < floatZero) {
          *(float *)(texUnitState + 0x352c) = floatZero;
        }
        else if (floatOne < envColorB) {
          *(float *)(texUnitState + 0x352c) = floatOne;
        }
        else {
          *(float *)(texUnitState + 0x352c) = envColorB;
        }
        envColorA = params[3];
        if (envColorA < floatZero) {
          *(float *)(texUnitState + 0x3530) = floatZero;
        }
        else if (floatOne < envColorA) {
          *(float *)(texUnitState + 0x3530) = floatOne;
        }
        else {
          *(float *)(texUnitState + 0x3530) = envColorA;
        }
        if (*(int *)(glContext + 0x5434) == 0) {
          dirtyBitIndex = *(byte *)(texUnit + *(int *)(glContext + 0x5420) + 0x30c);
        }
        else {
          dirtyBitIndex = *(byte *)(texUnit + *(int *)(*(int *)(glContext + 0x5430) + 0x20) + 0x340);
        }
        dirtyWordAt324 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        glContextWord5424 = *(int *)(glContext + 0x5424);
        *(uint *)(dirtyWordAt324 + 0x324) = *(uint *)(dirtyWordAt324 + 0x324) | 1 << (dirtyBitIndex & 0x1f);
        dirtyBitIndex = *(byte *)(texUnit + glContextWord5424 + 0x30c);
        dirtyWordAt348 = (dirtyBitIndex >> 3 & 0x1c) + glContext;
        *(uint *)(dirtyWordAt348 + 0x348) = *(uint *)(dirtyWordAt348 + 0x348) | 1 << (dirtyBitIndex & 0x1f);
        unitDirtyBit = 0x100;
        unitDirtyWord = *(uint *)(glContext + 800);
      }
      else {
        if (pname == 0x8588) {
          paramInt = (int)*params;
          if (((paramInt != 0x1702) && (0xf < paramInt - 0x84c0U)) &&
             (((paramInt != 0x8576 && (((paramInt != 0x8577 && (paramInt != 0x8578)) && (paramInt != 0)))) &&
              (paramInt != 1)))) goto switchD_00016744_caseD_86da;
          *(short *)(texUnit * 0x7c + glContext + 0x3546) = (short)paramInt;
        }
        else if (pname < 0x8589) {
          if (pname == 0x8573) {
            rgbScale = *params;
            if (((rgbScale == FLOAT_00108e54) || (rgbScale == FLOAT_00108ea4)) ||
               (rgbScale == FLOAT_00108ea8)) {
              *(float *)(texUnit * 0x7c + glContext + 0x3558) = rgbScale;
            }
            else {
LAB_000172d8:
              if (*(int *)(glContext + 0x7574) == 0) {
                *(undefined4 *)(glContext + 0x7574) = 0x500;
              }
            }
          }
          else {
            if (0x8573 < pname) {
              if (pname == 0x8581) {
                paramInt = (int)*params;
                if (((((paramInt == 0x1702) || (paramInt - 0x84c0U < 0x10)) || (paramInt == 0x8576)) ||
                    ((paramInt == 0x8577 || (paramInt == 0x8578)))) || ((paramInt == 0 || (paramInt == 1)))) {
                  *(short *)(texUnit * 0x7c + glContext + 0x3542) = (short)paramInt;
                  goto LAB_000172fc;
                }
              }
              else if (pname < 0x8582) {
                if ((pname == 0x8580) &&
                   (((((paramInt = (int)*params, paramInt == 0x1702 || (paramInt - 0x84c0U < 0x10)) ||
                      ((paramInt == 0x8576 || ((paramInt == 0x8577 || (paramInt == 0x8578)))))) ||
                     (paramInt == 0)) || (paramInt == 1)))) {
                  *(short *)(texUnit * 0x7c + glContext + 0x3540) = (short)paramInt;
                  goto LAB_000172fc;
                }
              }
              else if ((pname == 0x8582) &&
                      (((paramInt = (int)*params, paramInt == 0x1702 || (paramInt - 0x84c0U < 0x10)) ||
                       ((paramInt == 0x8576 ||
                        ((((paramInt == 0x8577 || (paramInt == 0x8578)) || (paramInt == 0)) || (paramInt == 1)))
                        ))))) {
                *(short *)(texUnit * 0x7c + glContext + 0x3544) = (short)paramInt;
                goto LAB_000172fc;
              }
              goto switchD_00016744_caseD_86da;
            }
            if (pname == 0x8571) {
              combineRgb = (code *)(int)*params;
              if (combineRgb < (code *)0x8576) {
                if ((combineRgb < (code *)0x8574) && (combineRgb != (code *)0x1e01)) {
                  if (combineRgb < (code *)0x1e02) {
                    matchesAllowedEnum = combineRgb == (code *)0x104;
                  }
                  else {
                    if (combineRgb == (code *)0x2100) goto LAB_00016dfc;
                    matchesAllowedEnum = combineRgb == (code *)0x84e7;
                  }
                  if (!matchesAllowedEnum) goto switchD_00016744_caseD_86da;
                }
              }
              else if ((combineRgb < (code *)0x86ae) ||
                      (((code *)0x86af < combineRgb && ((code *)0x2 < combineRgb + -0x8744))))
              goto switchD_00016744_caseD_86da;
LAB_00016dfc:
              *(short *)(texUnit * 0x7c + glContext + 0x353c) = (short)combineRgb;
            }
            else {
              if (pname < 0x8572) {
                if (pname == 0xd1c) {
                  alphaScale = *params;
                  if (((alphaScale != FLOAT_00108e54) && (alphaScale != FLOAT_00108ea4)) &&
                     (alphaScale != FLOAT_00108ea8)) goto LAB_000172d8;
                  *(float *)(texUnit * 0x7c + glContext + 0x355c) = alphaScale;
                  goto LAB_000172fc;
                }
                goto switchD_00016744_caseD_86da;
              }
              combineAlpha = (code *)(int)*params;
              if (combineAlpha != (code *)0x84e7) {
                if (combineAlpha < (code *)0x84e8) {
                  if (combineAlpha != (code *)0x1e01) {
                    if (combineAlpha < (code *)0x1e02) {
                      matchesAllowedEnum = combineAlpha == (code *)0x104;
                    }
                    else {
                      matchesAllowedEnum = combineAlpha == (code *)0x2100;
                    }
                    if (!matchesAllowedEnum) goto switchD_00016744_caseD_86da;
                  }
                }
                else if ((combineAlpha < (code *)0x8574) ||
                        (((code *)0x8575 < combineAlpha && ((code *)0x2 < combineAlpha + -0x8744))))
                goto switchD_00016744_caseD_86da;
              }
              *(short *)(texUnit * 0x7c + glContext + 0x353e) = (short)combineAlpha;
            }
          }
        }
        else {
          if (pname != 0x8591) {
            if (pname < 0x8592) {
              if (pname == 0x858a) {
                paramInt = (int)*params;
                if ((((((paramInt == 0x1702) || (paramInt - 0x84c0U < 0x10)) || (paramInt == 0x8576)) ||
                     ((paramInt == 0x8577 || (paramInt == 0x8578)))) || (paramInt == 0)) || (paramInt == 1)) {
                  *(short *)(texUnit * 0x7c + glContext + 0x354a) = (short)paramInt;
                  goto LAB_000172fc;
                }
              }
              else if (pname < 0x858a) {
                paramInt = (int)*params;
                if ((((paramInt == 0x1702) || (paramInt - 0x84c0U < 0x10)) ||
                    ((paramInt == 0x8576 || (((paramInt == 0x8577 || (paramInt == 0x8578)) || (paramInt == 0))))
                    )) || (paramInt == 1)) {
                  *(short *)(texUnit * 0x7c + glContext + 0x3548) = (short)paramInt;
                  goto LAB_000172fc;
                }
              }
              else if ((pname == 0x8590) && ((int)*params - 0x300U < 4)) {
                *(short *)(texUnit * 0x7c + glContext + 0x354c) = (short)(int)*params;
                goto LAB_000172fc;
              }
            }
            else if (pname == 0x8598) {
              if ((int)*params - 0x302U < 2) {
                *(short *)(texUnit * 0x7c + glContext + 0x3552) = (short)(int)*params;
                goto LAB_000172fc;
              }
            }
            else if (pname < 0x8599) {
              if ((pname == 0x8592) && ((int)*params - 0x300U < 4)) {
                *(short *)(texUnit * 0x7c + glContext + 0x3550) = (short)(int)*params;
                goto LAB_000172fc;
              }
            }
            else if (pname == 0x8599) {
              if ((int)*params - 0x302U < 2) {
                *(short *)(texUnit * 0x7c + glContext + 0x3554) = (short)(int)*params;
                goto LAB_000172fc;
              }
            }
            else if ((pname == 0x859a) && ((int)*params - 0x302U < 2)) {
              *(short *)(texUnit * 0x7c + glContext + 0x3556) = (short)(int)*params;
              goto LAB_000172fc;
            }
            goto switchD_00016744_caseD_86da;
          }
          if (3 < (int)*params - 0x300U) goto switchD_00016744_caseD_86da;
          *(short *)(texUnit * 0x7c + glContext + 0x354e) = (short)(int)*params;
        }
LAB_000172fc:
        unitDirtyWord = *(uint *)(glContext + 800);
        unitDirtyBit = 0x1000000;
      }
    }
    *(uint *)(glContext + 800) = unitDirtyWord | unitDirtyBit << (texUnit & 0x3f);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0001736c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glHint_Exec @ 0x17384 (444 bytes) */
void _glHint_Exec(glContext, target, mode)
  int glContext;
  uint target;
  int mode;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 glErrorCode;
  undefined2 uVar4;
  
  puVar2 = PTR__gleSetEyeInterpFunc_0011203c;
  puVar1 = PTR__gleSetClipInterpFunc_00112038;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (2 < mode - 0x1100U) goto LAB_00017508;
    if (target == 0x80f0) {
      *(int *)(glContext + 0x5080) = mode;
      *(uint *)(glContext + 0x50ac) = *(uint *)(glContext + 0x50ac) | 1;
      *(uint *)(glContext + 0x497c) = *(uint *)(glContext + 0x497c) | 1;
    }
    else {
      uVar4 = (undefined2)mode;
      if (target < 0x80f1) {
        if (target == 0xc52) {
          *(undefined2 *)(0x3170 + glContext) = uVar4;
        }
        else if (target < 0xc53) {
          if (target == 0xc50) {
            *(undefined2 *)(glContext + 0x316c) = uVar4;
          }
          else {
            if (target != 0xc51) {
LAB_00017508:
              if (*(int *)(glContext + 0x7574) != 0) {
                return;
              }
              glErrorCode = 0x500;
              goto LAB_00017518;
            }
            *(undefined2 *)(glContext + 0x316e) = uVar4;
          }
        }
        else if (target == 0xc53) {
          *(undefined2 *)(glContext + 0x3172) = uVar4;
        }
        else {
          if (target != 0xc54) goto LAB_00017508;
          *(undefined2 *)(glContext + 0x3174) = uVar4;
          *(undefined **)(glContext + 0x49c8) = puVar2;
          *(undefined **)(glContext + 0x49cc) = puVar1;
          ((double (*)())_gleUpdateFogData)(glContext);
        }
      }
      else if (target == 0x8534) {
        *(undefined2 *)(glContext + 0x317a) = uVar4;
      }
      else if (target < 0x8535) {
        if (target == 0x8192) {
          *(undefined2 *)(glContext + 0x3178) = uVar4;
        }
        else {
          if (target != 0x84ef) goto LAB_00017508;
          *(undefined2 *)(glContext + 0x3176) = uVar4;
        }
      }
      else if (target == 0x85b1) {
        *(int *)(glContext + 0x507c) = mode;
      }
      else {
        if (target != 0x8b8b) goto LAB_00017508;
        *(undefined2 *)(glContext + 0x317c) = uVar4;
      }
    }
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x2000;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_00017518:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glGenTextures_Exec @ 0x17540 (236 bytes) */
void _glGenTextures_Exec(glContext, n, textures)
  int glContext;
  int n;
  int *textures;
{
  undefined4 glErrorCode;
  int iVar2;
  int loopIndex;
  int iVar4;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (-1 < n) {
      iVar4 = *(int *)(glContext + 0x5148);
      if (*(char *)(iVar4 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar4 + 0x8028);
        iVar4 = *(int *)(glContext + 0x5148);
      }
      iVar4 = _gleGenHashNames(iVar4 + 0x2008,n);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (iVar4 == 0) {
        return;
      }
      loopIndex = 0;
      if (n < 1) {
        return;
      }
      do {
        iVar2 = iVar4 + loopIndex;
        loopIndex = loopIndex + 1;
        *textures = iVar2;
        textures = textures + 1;
        n = n + -1;
      } while (n != 0);
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

/* _glPixelStorei_Exec @ 0x1762c (648 bytes) */
void _glPixelStorei_Exec(glContext, pname, param)
  int glContext;
  uint pname;
  int param;
{
  undefined4 glErrorCode;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
      return;
    }
    return;
  }
  if (pname == 0xd02) {
    if (-1 < param) {
      *(int *)(glContext + 0x31b0) = param;
      goto LAB_000178a4;
    }
LAB_00017874:
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_000178a4;
    glErrorCode = 0x501;
  }
  else {
    if (pname < 0xd03) {
      if (pname == 0xcf3) {
        if (-1 < param) {
          *(int *)(glContext + 0x31d4) = param;
          goto LAB_000178a4;
        }
      }
      else if (pname < 0xcf4) {
        if (pname == 0xcf1) {
          if (param == 0) {
            *(undefined1 *)(glContext + 0x31e5) = 0;
          }
          else {
            *(undefined1 *)(glContext + 0x31e5) = 1;
          }
          goto LAB_000178a4;
        }
        if (pname < 0xcf2) {
          if (pname == 0xcf0) {
            if (param == 0) {
              *(undefined1 *)(glContext + 0x31e4) = 0;
            }
            else {
              *(undefined1 *)(glContext + 0x31e4) = 1;
            }
            goto LAB_000178a4;
          }
          goto LAB_00017890;
        }
        if (-1 < param) {
          *(int *)(glContext + 0x31cc) = param;
          goto LAB_000178a4;
        }
      }
      else if (pname == 0xcf5) {
        if (((param - 1U < 2) || (param == 4)) || (param == 8)) {
          *(int *)(glContext + 0x31e0) = param;
          goto LAB_000178a4;
        }
      }
      else if (pname < 0xcf5) {
        if (-1 < param) {
          *(int *)(glContext + 0x31d8) = param;
          goto LAB_000178a4;
        }
      }
      else if (pname == 0xd00) {
        if (-1 < param) {
          *(char *)(glContext + 0x31c8) = (char)param;
          goto LAB_000178a4;
        }
      }
      else {
        if (pname != 0xd01) goto LAB_00017890;
        if (-1 < param) {
          *(char *)(glContext + 0x31c9) = (char)param;
          goto LAB_000178a4;
        }
      }
      goto LAB_00017874;
    }
    if (pname == 0x806b) {
      if (-1 < param) {
        *(int *)(glContext + 0x31c0) = param;
        goto LAB_000178a4;
      }
      goto LAB_00017874;
    }
    if (0x806b < pname) {
      if (pname == 0x806d) {
        if (-1 < param) {
          *(int *)(glContext + 0x31dc) = param;
          goto LAB_000178a4;
        }
      }
      else if (pname < 0x806d) {
        if (-1 < param) {
          *(int *)(0x31b4 + glContext) = param;
          goto LAB_000178a4;
        }
      }
      else {
        if (pname != 0x806e) {
          if (pname == 0x85b2) {
            if (param == 0) {
              *(undefined1 *)(glContext + 0x31e6) = 0;
            }
            else {
              *(undefined1 *)(glContext + 0x31e6) = 1;
            }
            goto LAB_000178a4;
          }
          goto LAB_00017890;
        }
        if (-1 < param) {
          *(int *)(glContext + 0x31d0) = param;
          goto LAB_000178a4;
        }
      }
      goto LAB_00017874;
    }
    if (pname == 0xd04) {
      if (-1 < param) {
        *(int *)(glContext + 0x31bc) = param;
        goto LAB_000178a4;
      }
      goto LAB_00017874;
    }
    if (pname < 0xd04) {
      if (-1 < param) {
        *(int *)(glContext + 0x31b8) = param;
        goto LAB_000178a4;
      }
      goto LAB_00017874;
    }
    if (pname == 0xd05) {
      if (((param - 1U < 2) || (param == 4)) || (param == 8)) {
        *(int *)(glContext + 0x31c4) = param;
        goto LAB_000178a4;
      }
      goto LAB_00017874;
    }
LAB_00017890:
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_000178a4;
    glErrorCode = 0x500;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_000178a4:
  *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x200000;
  return;
}

/* _glBindTexture_Exec @ 0x178b4 (388 bytes) */
void _glBindTexture_Exec(glContext, target, texture)
  int glContext;
  uint target;
  undefined4 texture;
{
  undefined4 glErrorCode;
  undefined4 uVar1;
  int iVar2;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000179ac;
  }
  if (target != 0x84f5) {
    if (target < 0x84f6) {
      if (target == 0xde1) {
        uVar1 = 3;
        goto LAB_000179b4;
      }
      if (target < 0xde2) {
        if (target == 0xde0) {
          uVar1 = 4;
          goto LAB_000179b4;
        }
      }
      else if (target == 0x806f) {
        uVar1 = 1;
        goto LAB_000179b4;
      }
    }
    else {
      if (target == 0x85b3) goto LAB_00017994;
      if (target < 0x85b4) {
        if (target == 0x8513) {
          uVar1 = 0;
          goto LAB_000179b4;
        }
      }
      else if (target == 0x184f5) goto LAB_00017994;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
LAB_000179ac:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
LAB_00017994:
  uVar1 = 2;
LAB_000179b4:
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
    ((void (*)())_gleBindTexture)(glContext,uVar1,texture,*(undefined4 *)(glContext + 0x53d4));
    return;
  }
  iVar2 = *(int *)(glContext + 0x5148) + 0x8028;
  _pthread_mutex_lock(iVar2);
  ((void (*)())_gleBindTexture)(glContext,uVar1,texture,*(undefined4 *)(glContext + 0x53d4));
  _pthread_mutex_unlock(iVar2);
  return;
}

/* _gleBindTexture @ 0x17a38 (420 bytes) */
void _gleBindTexture(glContext, param_2, texture, param_4)
  int glContext;
  uint param_2;
  int texture;
  uint param_4;
{
  int loopIndex;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *srcCursor;
  int iVar5;
  undefined4 *dstCursor;
  int iVar7;
  
  iVar7 = *(int *)(glContext + 0x5148) + 0x2008;
  if (texture == 0) {
    if ((param_2 & 0xfffffff0) != 0) {
LAB_00017ac4:
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
      goto LAB_00017bb4;
    }
    iVar3 = *(int *)(param_2 * 4 + glContext + 0x5294);
  }
  else {
    iVar3 = ((int (*)())_gleLookupHashObject)(iVar7,texture);
    if (iVar3 == 0) {
      iVar3 = _gleCreateTextureObject(param_2,texture);
      _gleCreatePluginTexture(glContext,iVar3 + 0x10);
      ((int (*)())_gleAddHashNameAndObject)(glContext,iVar7,iVar3);
    }
    else if ((*(ushort *)(iVar3 + 0x34) & 0xffffc3ff) != param_2) goto LAB_00017ac4;
  }
  iVar7 = (param_4 * 5 + (param_2 & 0xf)) * 4 + glContext;
  *(int *)(iVar3 + 8) = *(int *)(iVar3 + 8) + 1;
  iVar5 = *(int *)(iVar7 + 0x5154);
  iVar2 = *(int *)(iVar5 + 8) + -1;
  *(int *)(iVar5 + 8) = iVar2;
  if (iVar2 == 0) {
    _gleFreeTextureObject(glContext,iVar5);
  }
  *(int *)(iVar7 + 0x5154) = iVar3;
  if ((*(int *)(iVar3 + 0x30) != 0) &&
     (*(int *)(iVar3 + 0x30) !=
      *(int *)((uint)*(byte *)(glContext + 0x85a8) * 4 + *(int *)(glContext + 0x5148) + 0x8054))) {
    _gleSynchronizePluginTextureLevels(glContext,iVar3 + 0x10);
  }
  loopIndex = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    srcCursor = (undefined4 *)(iVar3 + 0x10);
    dstCursor = (undefined4 *)((param_4 * 5 + (param_2 & 0xf)) * 4 + glContext + 0x86e0);
    do {
      uVar1 = *srcCursor;
      loopIndex = loopIndex + 1;
      srcCursor = srcCursor + 1;
      *dstCursor = uVar1;
      dstCursor = dstCursor + 0xb8;
    } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
LAB_00017bb4:
  *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 1 << (param_4 & 0x3f);
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
int _gleAddHashNameAndObject(glContext, forwardedArg2, hashObject)
  undefined4 glContext;
  undefined4 forwardedArg2;
  int hashObject;
{
  undefined4 uVar1;
  
  uVar1 = ((int (*)())_gleAddHashName)(forwardedArg2,*(undefined4 *)(hashObject + 4));
  ((void (*)())_gleAddHashObject)(forwardedArg2,hashObject);
  return uVar1;
}

/* _gleAddHashName @ 0x17ca0 (320 bytes) */
int _gleAddHashName(hashTable, hashName)
  int hashTable;
  uint hashName;
{
  undefined4 oldListHead;
  int followingRangeCount;
  uint rangeFirstName;
  undefined4 *allocatedBlock2;
  int rangeCount;
  int *nextRangeNode;
  int *allocatedBlock;
  int *currentRangeNode;
  
  nextRangeNode = *(int **)(hashTable + 0x1000);
  if ((nextRangeNode == (int *)0x0) || (rangeFirstName = nextRangeNode[1], hashName < rangeFirstName - 1)) {
    allocatedBlock2 = (undefined4 *)_malloc(0xc);
    oldListHead = *(undefined4 *)(hashTable + 0x1000);
    allocatedBlock2[1] = hashName;
    *allocatedBlock2 = oldListHead;
    allocatedBlock2[2] = 1;
    *(undefined4 **)(hashTable + 0x1000) = allocatedBlock2;
  }
  else {
    do {
      currentRangeNode = nextRangeNode;
      rangeCount = currentRangeNode[2];
      if (hashName == rangeFirstName - 1) {
        currentRangeNode[1] = hashName;
        currentRangeNode[2] = rangeCount + 1;
        return 1;
      }
      if ((rangeFirstName <= hashName) && (hashName < rangeFirstName + rangeCount)) {
        return 0;
      }
      if (hashName == rangeFirstName + rangeCount) {
        nextRangeNode = (int *)*currentRangeNode;
        currentRangeNode[2] = rangeCount + 1;
        if (nextRangeNode == (int *)0x0) {
          return 1;
        }
        if (hashName + 1 != nextRangeNode[1]) {
          return 1;
        }
        followingRangeCount = nextRangeNode[2];
        *currentRangeNode = *nextRangeNode;
        currentRangeNode[2] = rangeCount + 1 + followingRangeCount;
        _free(nextRangeNode);
        return 1;
      }
      nextRangeNode = (int *)*currentRangeNode;
    } while ((nextRangeNode != (int *)0x0) && (rangeFirstName = nextRangeNode[1], rangeFirstName - 1 <= hashName));
    allocatedBlock = (int *)_malloc(0xc);
    rangeCount = *currentRangeNode;
    allocatedBlock[1] = hashName;
    *allocatedBlock = rangeCount;
    allocatedBlock[2] = 1;
    *currentRangeNode = (int)allocatedBlock;
  }
  return 1;
}

/* _gleAddHashObject @ 0x17de0 (24 bytes) */
void _gleAddHashObject(hashTable, object)
  int hashTable;
  undefined4 *object;
{
  int bucketOffset;
  
  bucketOffset = (object[1] & 0x3ff) * 4;
  *object = *(undefined4 *)(hashTable + bucketOffset);
  *(undefined4 **)(hashTable + bucketOffset) = object;
  return;
}

/* _glTextureRangeAPPLE_Exec @ 0x17df8 (176 bytes) */
void _glTextureRangeAPPLE_Exec(glContext, target, length, pointer)
  int glContext;
  undefined4 target;
  int length;
  undefined4 pointer;
{
  undefined4 glErrorCode;
  int textureObject;
  
  textureObject = ((int (*)())_gleLookUpNonProxyTexture)(glContext,target);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (textureObject == 0) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x500;
    }
    else {
      if (-1 < length) {
        *(undefined4 *)(textureObject + 0x74) = pointer;
        *(int *)(textureObject + 0x70) = length;
        *(uint *)(glContext + 0x314) =
             *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
        return;
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
    }
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

/* _gleLookUpNonProxyTexture @ 0x17ea8 (224 bytes) */
int _gleLookUpNonProxyTexture(glContext, target)
  int glContext;
  uint target;
{
  int iVar1;
  
  iVar1 = *(int *)(glContext + 0x53d4);
  if (target != 0x84f5) {
    if (target < 0x84f6) {
      if (target == 0xde1) {
        iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5160);
      }
      else if (target < 0xde2) {
        if (target != 0xde0) {
          return 0;
        }
        iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5164);
      }
      else {
        if (target != 0x806f) {
          return 0;
        }
        iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5158);
      }
      goto LAB_00017f48;
    }
    if (target < 0x851b) {
      if ((target < 0x8515) && (target != 0x8513)) {
        return 0;
      }
      iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x5154);
      goto LAB_00017f48;
    }
    if (target != 0x85b3) {
      return 0;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x14 + glContext + 0x515c);
LAB_00017f48:
  return iVar1 + 0x10;
}

/* _glTexParameteri_Exec @ 0x17f88 (40 bytes) */
void _glTexParameteri_Exec(glContext, target, pname, param)
  undefined4 glContext;
  undefined4 target;
  undefined4 pname;
  undefined4 param;
{
  unsigned int ghidra_home[8] = { glContext, target, pname, param, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = param;
  ((int (*)())_glTexParameterI_Exec)(glContext,target,pname,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
  return;
}

/* _glTexParameterI_Exec @ 0x17fb0 (2056 bytes) */
int _glTexParameterI_Exec(glContext, target, pname, params)
  int glContext;
  undefined4 target;
  undefined *pname;
  uint *params;
{
  float floatZero;
  undefined4 glErrorCode;
  bool formatAllowed;
  float colorComponent;
  double intToDoubleMagic;
  uint allowedValue;
  undefined4 onOffFloatBits;
  float clampedPriority;
  int textureObject;
  undefined4 levelRangeChanged;
  uint paramValue;
  uint newFlags;
  
  textureObject = ((int (*)())_gleLookUpNonProxyTexture)(glContext,target);
  floatZero = FLOAT_00108e50;
  intToDoubleMagic = DOUBLE_00108d58;
  levelRangeChanged = 0;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (textureObject == 0) goto LAB_00018768;
    if (pname == (undefined *)0x813c) {
      if ((int)*params < 0) goto LAB_00018554;
      levelRangeChanged = 1;
      *(short *)(textureObject + 0x60) = (short)*params;
    }
    else if (pname < (undefined *)0x813d) {
      if (pname != (undefined *)0x2803) {
        if ((undefined *)0x2803 < pname) {
          if (pname == (undefined *)0x80bf) {
            if ((int)*params < 1) {
              onOffFloatBits = 0;
            }
            else {
              onOffFloatBits = 0x3f800000;
            }
            *(undefined4 *)(textureObject + 0x68) = onOffFloatBits;
          }
          else if (pname < (undefined *)0x80c0) {
            if (pname == (undefined *)0x8066) {
              clampedPriority = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
              if (clampedPriority < FLOAT_00108e50) {
                clampedPriority = 0.0;
              }
              else if (FLOAT_00108e54 < clampedPriority) {
                clampedPriority = 1.0;
              }
              *(float *)(textureObject + 0x28) = clampedPriority;
            }
            else {
              if (pname != (undefined *)0x8072) goto LAB_00018768;
              paramValue = *params;
              if (paramValue != 0x812f) {
                if (paramValue < 0x8130) {
                  if (0x28ff < paramValue) {
                    if (0x2901 < paramValue) {
                      allowedValue = 0x812d;
                      goto LAB_0001830c;
                    }
                    goto LAB_00018314;
                  }
                }
                else {
                  if (paramValue < 0x8744) {
                    if (0x8741 < paramValue) goto LAB_00018314;
                    allowedValue = 0x8370;
                  }
                  else {
                    allowedValue = 0x8912;
                  }
LAB_0001830c:
                  if (paramValue == allowedValue) goto LAB_00018314;
                }
                goto LAB_00018768;
              }
LAB_00018314:
              *(short *)(textureObject + 0x38) = (short)paramValue;
            }
          }
          else if (pname == (undefined *)0x813a) {
            *(float *)(textureObject + 0x54) =
                 (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
          }
          else {
            if (pname != (undefined *)0x813b) goto LAB_00018768;
            *(float *)(textureObject + 0x58) =
                 (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
          }
          goto LAB_00018780;
        }
        if (pname == (undefined *)0x2800) {
          if (*params - 0x2600 < 2) {
            *(short *)(textureObject + 0x3c) = (short)*params;
            goto LAB_00018780;
          }
        }
        else if (pname < (undefined *)0x2801) {
          if (pname == ((unsigned char *)0x00001004)) {
            colorComponent = (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58) *
                    FLOAT_00108e68 + FLOAT_00108e6c;
            if (colorComponent < FLOAT_00108e50) {
              *(float *)(textureObject + 0x40) = FLOAT_00108e50;
            }
            else {
              *(float *)(textureObject + 0x40) = colorComponent;
            }
            colorComponent = (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - DOUBLE_00108d58)
                    * FLOAT_00108e68 + FLOAT_00108e6c;
            if (colorComponent < floatZero) {
              *(float *)(textureObject + 0x44) = floatZero;
            }
            else {
              *(float *)(textureObject + 0x44) = colorComponent;
            }
            colorComponent = (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - DOUBLE_00108d58)
                    * FLOAT_00108e68 + FLOAT_00108e6c;
            if (colorComponent < floatZero) {
              *(float *)(textureObject + 0x48) = floatZero;
            }
            else {
              *(float *)(textureObject + 0x48) = colorComponent;
            }
            colorComponent = (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - DOUBLE_00108d58)
                    * FLOAT_00108e68 + FLOAT_00108e6c;
            if (!(colorComponent < floatZero)) goto LAB_00018760;
            *(float *)(textureObject + 0x4c) = floatZero;
            goto LAB_00018780;
          }
        }
        else if (pname == (undefined *)0x2801) {
          paramValue = *params;
          if ((0x25ff < paramValue) && ((paramValue < 0x2602 || (paramValue - 0x2700 < 4)))) {
            *(short *)(textureObject + 0x3a) = (short)paramValue;
            levelRangeChanged = 1;
            goto LAB_00018780;
          }
        }
        else if (pname == (undefined *)0x2802) {
          paramValue = *params;
          if (paramValue == 0x812f) {
LAB_0001823c:
            *(short *)(textureObject + 0x34) = (short)paramValue;
            goto LAB_00018780;
          }
          if (paramValue < 0x8130) {
            if (0x28ff < paramValue) {
              if (0x2901 < paramValue) {
                allowedValue = 0x812d;
                goto LAB_00018234;
              }
              goto LAB_0001823c;
            }
          }
          else {
            if (paramValue < 0x8744) {
              if (0x8741 < paramValue) goto LAB_0001823c;
              allowedValue = 0x8370;
            }
            else {
              allowedValue = 0x8912;
            }
LAB_00018234:
            if (paramValue == allowedValue) goto LAB_0001823c;
          }
        }
        goto LAB_00018768;
      }
      paramValue = *params;
      if (paramValue != 0x812f) {
        if (paramValue < 0x8130) {
          if (paramValue < 0x2900) goto LAB_00018768;
          if (0x2901 < paramValue) {
            allowedValue = 0x812d;
            goto LAB_000182a0;
          }
        }
        else {
          if (paramValue < 0x8744) {
            if (0x8741 < paramValue) goto LAB_000182a8;
            allowedValue = 0x8370;
          }
          else {
            allowedValue = 0x8912;
          }
LAB_000182a0:
          if (paramValue != allowedValue) goto LAB_00018768;
        }
      }
LAB_000182a8:
      *(short *)(textureObject + 0x36) = (short)paramValue;
    }
    else if (pname == (undefined *)0x85bc) {
      if (2 < *params - 0x85bd) goto LAB_00018768;
      *(short *)(textureObject + 0x3e) = (short)*params;
    }
    else {
      if ((undefined *)0x85bc < pname) {
        if (pname == (undefined *)0x884c) {
          paramValue = *params;
          if ((paramValue == 0) || (paramValue == 0x884e)) {
            *(short *)(textureObject + 0x66) = (short)paramValue;
            goto LAB_00018780;
          }
        }
        else if (pname < (undefined *)0x884d) {
          if (pname == (undefined *)0x871a) {
            *(float *)(textureObject + 0x40) =
                 (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
            *(float *)(textureObject + 0x44) =
                 (float)((double)CONCAT44(0x43300000,params[1] ^ 0x80000000) - intToDoubleMagic);
            *(float *)(textureObject + 0x48) =
                 (float)((double)CONCAT44(0x43300000,params[2] ^ 0x80000000) - intToDoubleMagic);
            colorComponent = (float)((double)CONCAT44(0x43300000,params[3] ^ 0x80000000) - intToDoubleMagic);
LAB_00018760:
            *(float *)(textureObject + 0x4c) = colorComponent;
            goto LAB_00018780;
          }
          if (pname == (undefined *)0x884b) {
            paramValue = *params;
            if (paramValue != 0x1909) {
              if (paramValue < 0x190a) {
                formatAllowed = paramValue == 0x1906;
              }
              else {
                formatAllowed = paramValue == 0x8049;
              }
              if (!formatAllowed) goto LAB_00018768;
            }
            *(short *)(textureObject + 0x6c) = (short)paramValue;
            goto LAB_00018780;
          }
        }
        else if (pname == (undefined *)0x884d) {
          if (*params - 0x200 < 8) {
            *(short *)(textureObject + 100) = (short)*params;
            goto LAB_00018780;
          }
        }
        else if ((pname == (undefined *)0x8a7f) && (*params < 2)) {
          newFlags = (*params & 1) << 6 | *(uint *)(textureObject + 0x6c) & 0xffffffbf;
          goto LAB_00018448;
        }
LAB_00018768:
        if (*(int *)(glContext + 0x7574) != 0) {
          return textureObject;
        }
        glErrorCode = 0x500;
        goto LAB_00018778;
      }
      if (pname == (undefined *)0x84fe) {
        if ((int)*params < 1) {
LAB_00018554:
          if (*(int *)(glContext + 0x7574) != 0) {
            return textureObject;
          }
          glErrorCode = 0x501;
          goto LAB_00018778;
        }
        *(float *)(textureObject + 0x50) =
             (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
      }
      else if (pname < (undefined *)0x84ff) {
        if (pname == (undefined *)0x813d) {
          if ((int)*params < 0) goto LAB_00018554;
          levelRangeChanged = 1;
          *(short *)(textureObject + 0x62) = (short)*params;
        }
        else {
          if ((pname != (undefined *)0x8191) || (1 < *params)) goto LAB_00018768;
          newFlags = (*params & 1) << 0xf | *(uint *)(textureObject + 0x6c) & 0xffff7fff;
LAB_00018448:
          *(uint *)(textureObject + 0x6c) = newFlags;
        }
      }
      else if (pname == (undefined *)0x8501) {
        *(float *)(textureObject + 0x5c) =
             (float)((double)CONCAT44(0x43300000,*params ^ 0x80000000) - DOUBLE_00108d58);
      }
      else {
        if (pname != (undefined *)0x85b6) goto LAB_00018768;
        *(uint *)(textureObject + 0x6c) =
             (uint)(*params != 0) * 0x80 | *(uint *)(textureObject + 0x6c) & 0xffffff7f;
      }
    }
LAB_00018780:
    textureObject = ((int (*)())_gleModifyPluginTexture)(glContext,textureObject,levelRangeChanged);
    *(uint *)(glContext + 0x314) =
         *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return textureObject;
    }
    glErrorCode = 0x502;
LAB_00018778:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return textureObject;
}

/* _gleModifyPluginTexture @ 0x187b8 (368 bytes) */
int _gleModifyPluginTexture(glContext, param_2, param_3)
  int glContext;
  undefined4 *param_2;
  int param_3;
{
  int loopIndex4;
  int loopIndex2;
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int loopIndex;
  uint uVar7;
  int iVar8;
  int loopIndex3;
  undefined4 *cursor;
  
  uVar7 = 0;
  if (param_3 != 0) {
    uVar7 = ((int (*)())_gleResetLevels)(glContext,param_2,0);
  }
  iVar8 = glContext + 0x10000;
  loopIndex3 = 0;
  cursor = param_2;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      piVar4 = (int *)(iVar8 + -0x777c);
      loopIndex3 = loopIndex3 + 1;
      puVar1 = (undefined4 *)(iVar8 + -0x7a54);
      iVar8 = iVar8 + 0x2e0;
      (**(code **)(*piVar4 + 0x154))(*puVar1,*cursor,uVar7 | 0x80);
      cursor = cursor + 1;
    } while (loopIndex3 < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  if (param_3 != 0) {
    uVar7 = (uint)*(byte *)(param_2 + 0x24);
    loopIndex2 = 0;
    if (uVar7 != 0) {
      uVar2 = (uint)*(byte *)((int)param_2 + 0x8f);
      loopIndex4 = 0;
      do {
        uVar5 = (uint)*(byte *)((int)param_2 + 0x8d);
        if (uVar5 < uVar2) {
          piVar4 = (int *)((int)param_2 + uVar5 * 0x18 + loopIndex4 + 0xc4);
          do {
            if ((*(byte *)((int)piVar4 + 0xb) & 0x80) != 0) {
              loopIndex = 0;
              iVar3 = *(int *)(glContext + 0x744c) + 0x10;
              *(undefined4 *)(*(int *)(glContext + 0x744c) + 0xec) = 1;
              if (*(char *)(glContext + 0x85a4) != '\0') {
                do {
                  *(undefined4 *)(iVar3 + 0xf8) = 1;
                  loopIndex = loopIndex + 1;
                  *(undefined4 *)(iVar3 + 0xfc) = 0;
                  iVar3 = iVar3 + 0x20;
                } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
              }
              *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
            }
            uVar5 = uVar5 + 1;
            *piVar4 = *piVar4 + 1;
            piVar4 = piVar4 + 6;
            uVar2 = (uint)*(byte *)((int)param_2 + 0x8f);
          } while ((int)uVar5 < (int)uVar2);
          uVar7 = (uint)*(byte *)(param_2 + 0x24);
        }
        loopIndex2 = loopIndex2 + 1;
        loopIndex4 = loopIndex4 + 0x168;
      } while (loopIndex2 < (int)uVar7);
    }
  }
  return;
}

/* _glTexImage2D_Exec @ 0x18928 (916 bytes) */
int _glTexImage2D_Exec(glContext, target, level, internalformat, width, height, border, format, type, pixels)
  int glContext;
  int target;
  int level;
  undefined4 internalformat;
  int width;
  int height;
  undefined4 border;
  undefined4 format;
  undefined4 type;
  int pixels;
{
  byte levelFlags;
  ushort textureTargetBits;
  undefined4 glErrorCode;
  uint faceIndex;
  int levelWidth;
  int imageEndOffset;
  int iVar6;
  int levelHeight;
  int pixelUnpackBuffer;
  int iVar8;
  int textureLevel;
  double bytesPerElement;
  
  iVar6 = glContext;
  if (-1 < *(short *)(glContext + 0x4a10)) goto LAB_00018a8c;
  if ((pixels == 0) && (*(char *)(glContext + 0x31e6) != '\0')) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return glContext;
    }
    glErrorCode = 0x501;
    goto LAB_00018a9c;
  }
  pixelUnpackBuffer = *(int *)(glContext + 0x4a6c);
  if (pixelUnpackBuffer != 0) {
    imageEndOffset = _gleOffsetLimitImage(glContext + 0x31cc,width,height,format,type,pixels);
    iVar8 = *(int *)(pixelUnpackBuffer + 0x38);
    bytesPerElement = (double)((double (*)())_gleBytesPerElement)(type);
    iVar6 = (int)bytesPerElement;
    if (imageEndOffset <= iVar8) {
      if (iVar6 == 0) {
        iVar6 = ((int (*)())_glePixelBytes)(format,type);
      }
      if (pixels == (pixels / iVar6) * iVar6) {
        if (*(int *)(pixelUnpackBuffer + 0x40) != 0) {
          _gleSynchronizePluginBuffer(glContext,pixelUnpackBuffer + 0x10);
        }
        pixels = pixels + *(int *)(pixelUnpackBuffer + 0x30);
        goto LAB_00018a2c;
      }
    }
LAB_00018a8c:
    if (*(int *)(glContext + 0x7574) != 0) {
      return iVar6;
    }
    glErrorCode = 0x502;
LAB_00018a9c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return iVar6;
  }
LAB_00018a2c:
  iVar6 = ((int (*)())_gleCheckTexImage2DArgs)(glContext,target,level,internalformat,width,height,border,format,type);
  if (iVar6 == 0) {
    return 0;
  }
  textureTargetBits = *(ushort *)(iVar6 + 0x24);
  if ((textureTargetBits & 0x3c00) != 0x1000) {
    if ((textureTargetBits & 0x3c00) == 0) {
      *(ushort *)(iVar6 + 0x24) = textureTargetBits | 0x1000;
    }
    else if ((textureTargetBits & 0xc00) != 0) goto LAB_00018a8c;
  }
  levelHeight = height;
  levelWidth = width;
  if ((*(uint *)(glContext + 0x3410) & 2) == 0) {
    if (((*(uint *)(glContext + 0x3410) & 4) == 0) || (*(short *)(glContext + 0x3348) != -0x7fea))
    goto LAB_00018b08;
    levelHeight = *(int *)(glContext + 0x3354);
    levelWidth = *(int *)(glContext + 0x3350);
  }
  else {
    if (*(short *)(glContext + 0x3308) != -0x7fea) goto LAB_00018b08;
    levelHeight = *(int *)(glContext + 0x3314);
    levelWidth = *(int *)(glContext + 0x3310);
  }
  levelHeight = (height - levelHeight) + 1;
  levelWidth = (width - levelWidth) + 1;
LAB_00018b08:
  faceIndex = target - 0x8515;
  if (5 < faceIndex) {
    faceIndex = 0;
  }
  iVar8 = iVar6 + faceIndex * 0x168 + level * 0x18;
  textureLevel = iVar8 + 0xc4;
  if ((*(byte *)(iVar8 + 0xcf) & 0x20) != 0) {
    _gleDeletePluginTextureLevel(glContext,iVar6,textureLevel,faceIndex,level);
    if (*(int *)(iVar8 + 0xd8) != 0) {
      levelFlags = *(byte *)(iVar8 + 0xcf);
      if ((levelFlags & 1) == 0) {
        _gleFreeTextureLevel(glContext,iVar6,textureLevel);
        levelFlags = *(byte *)(iVar8 + 0xcf);
      }
      else {
        *(undefined4 *)(iVar8 + 0xd8) = 0;
      }
      *(byte *)(iVar8 + 0xcf) = levelFlags & 0xef;
    }
    *(byte *)(iVar8 + 0xcf) = *(byte *)(iVar8 + 0xcf) & 0xdf;
  }
  iVar8 = ((int (*)())_gleCreateTextureLevel)(glContext,iVar6,textureLevel,internalformat,levelWidth,levelHeight,1,border,format,type,1,pixels);
  if ((iVar8 != 0) && (pixels != 0)) {
    iVar8 = ((int (*)())_gleTextureImagePut)(glContext,textureLevel,0,0,0,width,height,1,format,type,1,
                                glContext + 0x31cc,pixels);
  }
  if ((((levelWidth != 0) && (levelHeight != 0)) &&
      (iVar8 = ((int (*)())_gleCreatePluginTextureLevel)(glContext,iVar6,textureLevel,faceIndex,level,internalformat),
      (*(uint *)(iVar6 + 0x6c) & 0x8000) != 0)) &&
     ((*(short *)(iVar6 + 0x60) == level &&
      (iVar6 = _gleGenMipmapsToLevel(glContext,iVar6,faceIndex,level,0xf,1), iVar8 = 0, iVar6 != 0)))) {
    return iVar6;
  }
  *(uint *)(glContext + 0x314) =
       *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
  return iVar8;
}

/* _gleCheckTexImage2DArgs @ 0x18cbc (504 bytes) */
int _gleCheckTexImage2DArgs(glContext, target, level, internalformat, width, height, border, format, type)
  int glContext;
  undefined4 target;
  undefined4 level;
  undefined4 internalformat;
  int width;
  int height;
  int border;
  undefined4 format;
  undefined4 type;
{
  undefined4 glErrorCode;
  ushort uVar1;
  int iVar2;
  int glContextPtr468c;
  int textureObject;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  
  textureObject = ((int (*)())_gleLookUpTexture2D)(glContext,target);
  uVar7 = 1;
  uVar6 = 1;
  if (textureObject == 0) {
    if (*(int *)(glContext + 0x7574) == 0) {
      glErrorCode = 0x500;
LAB_00018e64:
      *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    }
LAB_00018e68:
    iVar2 = 0;
  }
  else {
    if ((*(uint *)(glContext + 0x3410) & 2) == 0) {
      if (((*(uint *)(glContext + 0x3410) & 4) != 0) && (*(short *)(glContext + 0x3348) == -0x7fea)) {
        iVar5 = *(int *)(glContext + 0x3354);
        iVar2 = *(int *)(glContext + 0x3350);
        goto LAB_00018d64;
      }
    }
    else if (*(short *)(glContext + 0x3308) == -0x7fea) {
      iVar5 = *(int *)(glContext + 0x3314);
      iVar2 = *(int *)(glContext + 0x3310);
LAB_00018d64:
      width = (width - iVar2) + 1;
      height = (height - iVar5) + 1;
    }
    uVar8 = height + border * -2;
    uVar9 = width + border * -2;
    uVar1 = *(ushort *)(textureObject + 0x24) & 0xf;
    if (uVar1 == 2) {
      uVar6 = 0;
      if ((((int)uVar9 < 0) ||
          (uVar4 = (uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc0), (int)uVar4 < (int)uVar9))
         || ((int)uVar8 < 0)) goto LAB_00018e54;
LAB_00018e50:
      if ((int)uVar4 < (int)uVar8) {
LAB_00018e54:
        if (*(int *)(glContext + 0x7574) == 0) {
          glErrorCode = 0x501;
          goto LAB_00018e64;
        }
        goto LAB_00018e68;
      }
    }
    else if (uVar1 < 3) {
      if ((*(ushort *)(textureObject + 0x24) & 0xf) == 0) {
        uVar7 = 0;
        if ((uVar9 != uVar8) ||
           ((int)(uint)*(ushort *)(*(int *)(glContext + 0x468c) + 0xc2) < (int)uVar8))
        goto LAB_00018e54;
LAB_00018dc8:
        if (-1 < (int)uVar9) {
          if ((uVar9 & uVar9 - 1) == 0) {
            glContextPtr468c = *(int *)(glContext + 0x468c);
          }
          else {
            glContextPtr468c = *(int *)(glContext + 0x468c);
            if ((*(uint *)(glContextPtr468c + 0x124) & 0x80000) == 0) goto LAB_00018e54;
          }
          uVar4 = (uint)*(ushort *)(glContextPtr468c + 0xbc);
          if ((((int)uVar9 <= (int)uVar4) && (-1 < (int)uVar8)) &&
             (((uVar8 & uVar8 - 1) == 0 || ((*(uint *)(glContextPtr468c + 0x124) & 0x80000) != 0))))
          goto LAB_00018e50;
        }
        goto LAB_00018e54;
      }
    }
    else if (uVar1 == 3) goto LAB_00018dc8;
    iVar5 = ((int (*)())_gleCheckTexImageArgs)(glContext,level,format,type,internalformat,border,uVar7,uVar6);
    iVar2 = 0;
    if (iVar5 != 0) {
      iVar2 = textureObject;
    }
  }
  return iVar2;
}

/* _gleLookUpTexture2D @ 0x18eb4 (244 bytes) */
int _gleLookUpTexture2D(glContext, target)
  int glContext;
  uint target;
{
  int activeUnitThenTextureObject;
  
  activeUnitThenTextureObject = *(int *)(glContext + 0x53d4);
  if (target == 0x8513) {
LAB_00018f60:
    activeUnitThenTextureObject = *(int *)(activeUnitThenTextureObject * 0x14 + glContext + 0x5154);
  }
  else {
    if (target < 0x8514) {
      if (target == 0x8064) {
        activeUnitThenTextureObject = *(int *)(glContext + 0x52b4);
LAB_00018f90:
        return activeUnitThenTextureObject + 0x10;
      }
      if (target < 0x8065) {
        if (target != 0xde1) {
          return 0;
        }
        activeUnitThenTextureObject = *(int *)(activeUnitThenTextureObject * 0x14 + glContext + 0x5160);
        goto LAB_00018f6c;
      }
      if (target != 0x84f5) {
        if (target != 0x84f7) {
          return 0;
        }
        activeUnitThenTextureObject = *(int *)(glContext + 0x52b0);
        goto LAB_00018f90;
      }
    }
    else {
      if (target == 0x851b) {
        activeUnitThenTextureObject = *(int *)(glContext + 0x52a8);
        goto LAB_00018f90;
      }
      if (target < 0x851c) {
        if (target < 0x8515) {
          return 0;
        }
        goto LAB_00018f60;
      }
      if (target != 0x85b3) {
        return 0;
      }
    }
    activeUnitThenTextureObject = *(int *)(activeUnitThenTextureObject * 0x14 + glContext + 0x515c);
  }
LAB_00018f6c:
  return activeUnitThenTextureObject + 0x10;
}

/* _gleCheckTexImageArgs @ 0x18fa8 (648 bytes) */
int _gleCheckTexImageArgs(glContext, level, format, type, internalformat, border, param_7, param_8)
  int glContext;
  undefined4 level;
  int format;
  undefined4 type;
  int internalformat;
  uint border;
  int param_7;
  int param_8;
{
  bool bVar1;
  bool bVar2;
  undefined4 glErrorCode;
  uint uVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = ((int (*)())_gleCheckTexSubImageArgs)(glContext,level,format,type);
  bVar6 = false;
  bVar2 = false;
  if (iVar5 == 0) {
    return 0;
  }
  if (internalformat < 0x83f4) {
    if (internalformat < 0x83f0) {
      if (internalformat < 0x804e) {
        if (internalformat < 0x803b) {
          if (internalformat == 0x1902) goto LAB_0001917c;
          if (internalformat < 0x1903) {
            bVar1 = 3 < internalformat - 1U;
            goto LAB_0001916c;
          }
          if (internalformat < 0x1906) goto LAB_000191c8;
          if (0x190a < internalformat) {
            bVar1 = internalformat == 0x2a10;
            goto LAB_00019104;
          }
        }
        goto LAB_00019188;
      }
      if (internalformat < 33000) {
        if (internalformat < 0x80e2) {
          uVar4 = internalformat - 0x804f;
          goto LAB_00019144;
        }
        bVar2 = true;
        goto LAB_00019188;
      }
      if (2 < internalformat - 0x81a5U) goto LAB_000191c8;
LAB_0001917c:
      bVar6 = true;
      if (param_7 != 0) goto LAB_00019188;
    }
    else {
LAB_00019188:
      if (bVar6 == (format == 0x1902)) {
        if ((param_8 != 0) || ((!bVar2 && (format != 0x1900)))) {
          if (((border & 0xfffffffe) == 0) && ((border == 0 || (format != 0x85b9)))) {
            return 1;
          }
          if (*(int *)(glContext + 0x7574) != 0) {
            return 0;
          }
          glErrorCode = 0x501;
          goto LAB_0001920c;
        }
        goto LAB_000191c8;
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x502;
  }
  else {
    if (internalformat < 0x8700) {
      if (internalformat < 0x86fe) {
        if (0x86f6 < internalformat) {
          bVar1 = 4 < internalformat - 0x86f8U;
          goto LAB_0001916c;
        }
        if (internalformat < 0x86f4) {
          if (internalformat < 0x84e9) goto LAB_000191c8;
          if (0x84ee < internalformat) {
            bVar1 = internalformat == 0x86dc;
LAB_00019104:
            if (!bVar1) goto LAB_000191c8;
          }
        }
      }
      goto LAB_00019188;
    }
    if (0x881f < internalformat) {
      if (internalformat != 0x8837) {
        if (internalformat < 0x8837) goto LAB_000191c8;
        bVar1 = 1 < internalformat - 0x885eU;
        goto LAB_0001916c;
      }
      goto LAB_00019188;
    }
    if (0x8813 < internalformat) goto LAB_00019188;
    uVar4 = internalformat - 0x8701;
LAB_00019144:
    bVar1 = 0xc < uVar4;
LAB_0001916c:
    if (!bVar1) goto LAB_00019188;
LAB_000191c8:
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x500;
  }
LAB_0001920c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _gleCheckTexSubImageArgs @ 0x19230 (380 bytes) */
int _gleCheckTexSubImageArgs(glContext, level, format, type)
  int glContext;
  uint level;
  uint format;
  uint type;
{
  bool bVar1;
  uint uVar2;
  undefined4 glErrorCode;
  
  if (type < 0x8365) {
    if (0x8361 < type) {
LAB_00019314:
      bVar1 = format == 0x1907;
      goto LAB_0001933c;
    }
    if (type == 0x1a00) {
      bVar1 = format == 0x1900;
LAB_00019368:
      if (bVar1) goto LAB_00019380;
LAB_0001936c:
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      glErrorCode = 0x500;
      goto LAB_0001939c;
    }
    if (0x1a00 < type) {
      if (type == 0x8032) goto LAB_00019314;
      if (0x8031 < type) {
        bVar1 = 0x8036 < type;
        goto LAB_000192a0;
      }
      goto LAB_0001936c;
    }
    if ((type < 0x1400) || ((0x1406 < type && (type != 0x140b)))) goto LAB_0001936c;
    if (format != 0x8000) {
      if (format < 0x8001) {
        if (format != 0x1900) {
          if (0x18ff < format) {
            bVar1 = 8 < format - 0x1902;
LAB_0001930c:
            if (!bVar1) goto LAB_00019380;
          }
          goto LAB_0001936c;
        }
      }
      else {
        if (format < 0x80e0) goto LAB_0001936c;
        if (0x80e1 < format) {
          bVar1 = 3 < format - 0x86f4;
          goto LAB_0001930c;
        }
      }
    }
  }
  else {
    if (0x85bb < type) {
      if (type - 0x86da < 2) {
        bVar1 = format == 0x86f7;
        goto LAB_00019368;
      }
      goto LAB_0001936c;
    }
    if (type < 0x85ba) {
      bVar1 = 0x8368 < type;
LAB_000192a0:
      if (bVar1) goto LAB_0001936c;
      if (format == 0x1908) goto LAB_00019380;
      uVar2 = 0x80e1;
    }
    else {
      uVar2 = 0x85b9;
    }
    bVar1 = format == uVar2;
LAB_0001933c:
    if (!bVar1) {
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0;
      }
      glErrorCode = 0x502;
      goto LAB_0001939c;
    }
  }
LAB_00019380:
  if (level < 0xf) {
    return 1;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0;
  }
  glErrorCode = 0x501;
LAB_0001939c:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _gleCreateTextureLevel @ 0x193ac (776 bytes) */
int _gleCreateTextureLevel(glContext, textureObject, textureLevel, internalformat, width, height, depth, border, format, type, levelStorage, pixels)
  int glContext;
  int textureObject;
  int *textureLevel;
  int internalformat;
  int width;
  int height;
  int depth;
  undefined4 border;
  int format;
  undefined4 type;
  int levelStorage;
  int pixels;
{
  byte levelFlagsBefore;
  bool useGenericPath;
  int framebufferCursor;
  int allocResult;
  int loopIndex;
  undefined2 height16;
  undefined2 width16;
  uint rowBytes;
  undefined1 rowPadding [4];
  uint imageBytes;
  undefined1 imagePadding [4];
  uint pixelBytes;
  int startOffset [5];
  
  levelFlagsBefore = *(byte *)((int)textureLevel + 0xb);
  if ((levelFlagsBefore & 0x80) != 0) {
    loopIndex = 0;
    framebufferCursor = *(int *)(glContext + 0x744c) + 0x10;
    *(undefined4 *)(*(int *)(glContext + 0x744c) + 0xec) = 1;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        *(undefined4 *)(framebufferCursor + 0xf8) = 1;
        loopIndex = loopIndex + 1;
        *(undefined4 *)(framebufferCursor + 0xfc) = 0;
        framebufferCursor = framebufferCursor + 0x20;
      } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  *textureLevel = *textureLevel + 1;
  if (((width != 0) && (height != 0)) && (depth != 0)) {
    width16 = (undefined2)width;
    height16 = (undefined2)height;
    if ((*(ushort *)(textureObject + 0x24) & 0x100) != 0) {
      textureLevel[5] = 0;
      *(undefined2 *)(textureLevel + 1) = width16;
      *(undefined2 *)((int)textureLevel + 6) = height16;
      *(short *)(textureLevel + 2) = (short)depth;
      *(undefined1 *)((int)textureLevel + 0xb) = 0x20;
      *(char *)((int)textureLevel + 10) = (char)border;
      *(short *)(textureLevel + 4) = (short)format;
      *(short *)((int)textureLevel + 0x12) = (short)type;
      *(undefined2 *)((int)textureLevel + 0xe) = 0;
      goto LAB_00019690;
    }
    if ((((levelStorage == 0) || ((format == 0x1900 && (5 < internalformat - 0x80e2U)))) ||
        (*(char *)(glContext + 0x31e6) == '\0')) ||
       ((*(char *)(glContext + 0x31e4) != '\0' || ((*(uint *)(glContext + 0x3410) & 0x1ff) != 0)))) {
LAB_000195c0:
      levelStorage = 0;
      useGenericPath = true;
    }
    else {
      useGenericPath = (*(uint *)(glContext + 0x3414) & 0xff0000) == 0;
      if ((!useGenericPath) || ((*(uint *)(glContext + 0x3414) & 0xff1) != 0)) goto LAB_000195c0;
      ((void (*)())_glePixelPackSettings)(glContext,format,type,width,height,glContext + 0x31cc,&pixelBytes,startOffset,
                 &rowBytes,rowPadding,&imageBytes,imagePadding);
      if (rowBytes == (rowBytes / pixelBytes) * pixelBytes) {
        pixels = pixels + startOffset[0];
        *(undefined1 *)((int)textureLevel + 0xb) = 0x31;
        if ((levelFlagsBefore & 0x80) != 0) {
          *(undefined1 *)((int)textureLevel + 0xb) = 0xb1;
        }
        *(short *)(textureLevel + 3) = (short)(rowBytes / pixelBytes);
        textureLevel[5] = pixels;
        *(short *)(textureLevel + 4) = (short)format;
        *(short *)((int)textureLevel + 0x12) = (short)type;
        *(short *)((int)textureLevel + 0xe) = (short)(imageBytes / rowBytes);
        useGenericPath = false;
      }
      else {
        levelStorage = 0;
      }
    }
    *(undefined2 *)(textureLevel + 1) = width16;
    *(undefined2 *)((int)textureLevel + 6) = height16;
    *(short *)(textureLevel + 2) = (short)depth;
    *(char *)((int)textureLevel + 10) = (char)border;
    if (!useGenericPath) {
      return 1;
    }
    *(undefined1 *)((int)textureLevel + 0xb) = 0x20;
    if ((levelFlagsBefore & 0x80) != 0) {
      *(undefined1 *)((int)textureLevel + 0xb) = 0xa0;
    }
    *(undefined2 *)(textureLevel + 3) = width16;
    *(undefined2 *)((int)textureLevel + 0xe) = height16;
    textureLevel[5] = levelStorage;
    _gleTexLevelStorage(glContext,internalformat,format,type,textureLevel + 4,(int)textureLevel + 0x12,border);
    if (pixels == 0) {
      return 1;
    }
    allocResult = _gleAllocateTextureLevel(glContext,textureObject,textureLevel);
    if (allocResult != 0) {
      *(byte *)((int)textureLevel + 0xb) = *(byte *)((int)textureLevel + 0xb) | 0x10;
      return 1;
    }
  }
  textureLevel[5] = 0;
  *(undefined2 *)((int)textureLevel + 0xe) = 0;
  *(undefined2 *)(textureLevel + 1) = 0;
  *(undefined2 *)((int)textureLevel + 6) = 0;
  *(undefined2 *)(textureLevel + 2) = 0;
  *(undefined1 *)((int)textureLevel + 10) = 0;
  *(undefined1 *)((int)textureLevel + 0xb) = 0;
  *(undefined2 *)(textureLevel + 4) = 0;
  *(undefined2 *)((int)textureLevel + 0x12) = 0;
LAB_00019690:
  *(undefined2 *)(textureLevel + 3) = 0;
  return 0;
}

/* _glePixelPackSettings @ 0x196b4 (376 bytes) */
void _glePixelPackSettings(glContext, format, type, width, height, packSettings, pixelBytesOut, startOffsetOut, rowBytesOut, rowPaddingOut, imageBytesOut, imagePaddingOut)
  undefined4 glContext;
  undefined4 format;
  int type;
  undefined4 width;
  int height;
  int *packSettings;
  int *pixelBytesOut;
  int *startOffsetOut;
  uint *rowBytesOut;
  int *rowPaddingOut;
  int *imageBytesOut;
  int *imagePaddingOut;
{
  int pixelBytes;
  int imageBytes;
  int rowOversize;
  int componentCount;
  uint rowBytesThenAlignment;
  int alignPadding;
  uint packedRowBytes;
  int rowLength;
  int alignRemainder;
  
  pixelBytes = ((int (*)())_glePixelBytes)(format,type);
  *pixelBytesOut = pixelBytes;
  rowBytesThenAlignment = ((int (*)())_gleRowBytes)(format,type,width);
  if (packSettings == (int *)0x0) {
    *rowBytesOut = rowBytesThenAlignment;
    *startOffsetOut = 0;
    *rowPaddingOut = 0;
    *imagePaddingOut = 0;
  }
  else {
    rowLength = *packSettings;
    if (rowLength == 0) {
      *rowBytesOut = rowBytesThenAlignment;
      rowOversize = 0;
      packedRowBytes = rowBytesThenAlignment;
    }
    else {
      if (type == 0x1a00) {
        componentCount = ((int (*)())_gleComponents)(format);
        *rowBytesOut = rowLength * componentCount + 7 >> 3;
      }
      else {
        *rowBytesOut = rowLength * pixelBytes;
      }
      packedRowBytes = *rowBytesOut;
      rowOversize = packedRowBytes - rowBytesThenAlignment;
    }
    rowBytesThenAlignment = packSettings[5];
    alignPadding = 0;
    alignRemainder = packedRowBytes - (packedRowBytes / rowBytesThenAlignment) * rowBytesThenAlignment;
    if (alignRemainder != 0) {
      alignPadding = rowBytesThenAlignment - alignRemainder;
      *rowBytesOut = packedRowBytes + alignPadding;
    }
    *rowPaddingOut = rowOversize + alignPadding;
    if (packSettings[1] == 0) {
      imageBytes = height * *rowBytesOut;
    }
    else {
      imageBytes = packSettings[1] * *rowBytesOut;
    }
    *imageBytesOut = imageBytes;
    *imagePaddingOut = *imageBytesOut - height * *rowBytesOut;
    *startOffsetOut = packSettings[3] * *pixelBytesOut + packSettings[2] * *rowBytesOut + packSettings[4] * *imageBytesOut;
  }
  return;
}

/* _glePixelBytes @ 0x1982c (400 bytes) */
int _glePixelBytes(format, type)
  uint format;
  uint type;
{
  undefined4 componentCount2;
  int componentCount;
  
  if (type == 0x8032) {
    return 1;
  }
  if (0x8032 < type) {
    if (type < 0x8367) {
      if (type < 0x8363) {
        if (type < 0x8037) {
          if (type < 0x8035) {
            return 2;
          }
        }
        else if (type == 0x8362) {
          return 1;
        }
        return 4;
      }
    }
    else {
      if (0x85bb < type) {
        return 4;
      }
      if (type < 0x85ba) {
        return 4;
      }
    }
    return 2;
  }
  if (0x1401 < type) {
    if (type < 0x1407) {
      if (0x1403 < type) {
        componentCount = ((int (*)())_gleComponents)(format);
        return componentCount << 2;
      }
    }
    else if (type != 0x140b) {
      if (type != 0x1a00) {
        return 4;
      }
      return 0;
    }
    componentCount = ((int (*)())_gleComponents)(format);
    return componentCount << 1;
  }
  if (0x13ff < type) {
    componentCount2 = ((int (*)())_gleComponents)(format);
    return componentCount2;
  }
  if (type == 1) {
    return 4;
  }
  if (type == 0) {
    if (format == 0x84ea) {
      return 8;
    }
    if (format < 0x84eb) {
      if (format < 0x83f0) {
        return 0;
      }
      if (format < 0x83f2) {
        return 8;
      }
      if (0x83f3 < format) {
        return 0;
      }
    }
    else if (format < 0x84ee) {
      if (0x84eb < format) {
        return 8;
      }
    }
    else if ((format != 0x84ee) && (format != 0x8837)) {
      return 0;
    }
    return 0x10;
  }
  return 4;
}

/* _gleRowBytes @ 0x199bc (108 bytes) */
int _gleRowBytes(format, type, param_3)
  undefined4 format;
  int type;
  int param_3;
{
  int iVar1;
  
  if (type == 0) {
    iVar1 = ((int (*)())_glePixelBytes)(format,0);
    iVar1 = iVar1 * (param_3 + 3 >> 2) >> 2;
  }
  else if (type == 0x1a00) {
    iVar1 = ((int (*)())_gleComponents)(format);
    iVar1 = param_3 * iVar1 + 7 >> 3;
  }
  else {
    iVar1 = ((int (*)())_glePixelBytes)(format,type);
    iVar1 = iVar1 * param_3;
  }
  return iVar1;
}

/* _gleTextureImagePut @ 0x19a28 (300 bytes) */
int _gleTextureImagePut(glContext, textureLevel, xoffset, yoffset, zoffset, width, height, depth, format, type, param_11, unpackState, pixels)
  int glContext;
  int textureLevel;
  undefined4 xoffset;
  undefined4 yoffset;
  int zoffset;
  undefined4 width;
  undefined4 height;
  int depth;
  int format;
  int type;
  uint param_11;
  int unpackState;
  undefined4 pixels;
{
  int iVar1;
  
  if ((type != 0x1a00) && ((format != 0x1900 || (*(short *)(textureLevel + 0x10) == 0x1900)))) {
    if ((*(uint *)(glContext + 0x3414) & 0xff1) == 0) {
      if ((param_11 & 0xff) == 1) {
        if (((*(uint *)(glContext + 0x3410) & 0x1ff) != 0) ||
           ((*(uint *)(glContext + 0x3414) & 0xff0000) != 0)) goto LAB_00019af8;
      }
      if (((unpackState == 0) || (*(char *)(unpackState + 0x18) == '\0')) &&
         ((depth == 1 && (zoffset == 0)))) {
        iVar1 = ((int (*)())_gleTextureImagePut_Fast)(glContext,textureLevel,xoffset,yoffset,width,height,format,type,unpackState
                           ,pixels);
        if (iVar1 != 0) {
          return;
        }
      }
    }
  }
LAB_00019af8:
  _gleTextureImagePut_Slow
            (glContext,textureLevel,xoffset,yoffset,zoffset,width,height,depth,format,type,
             param_11 & 0xff,unpackState,pixels);
  return;
}

/* _gleTextureImagePut_Fast @ 0x19b54 (900 bytes) */
int _gleTextureImagePut_Fast(glContext, textureLevel, xoffset, yoffset, width, height, format, type, forwardedArg9, pixels)
  int glContext;
  int textureLevel;
  int xoffset;
  int yoffset;
  int width;
  undefined4 height;
  uint format;
  uint type;
  undefined4 forwardedArg9;
  int pixels;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int levelRowBytes;
  undefined4 putResult;
  int levelRowComponents;
  int destPixels;
  int srcRowBytes;
  undefined1 srcRowPadding [4];
  undefined1 srcImageBytes [4];
  undefined1 srcImagePadding [4];
  int srcPixelBytes;
  int srcStartThenPointer [6];
  
  iVar2 = ((int (*)())_gleComponents)((uint)*(ushort *)(textureLevel + 0x10));
  iVar3 = ((int (*)())_glePixelBytes)((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12));
  levelRowComponents = iVar2 * (uint)*(ushort *)(textureLevel + 0xc);
  levelRowBytes = ((int (*)())_gleRowBytes)((uint)*(ushort *)(textureLevel + 0x10),(uint)*(ushort *)(textureLevel + 0x12),
                       (uint)*(ushort *)(textureLevel + 0xc));
  destPixels = *(int *)(textureLevel + 0x14) + iVar3 * ((uint)*(ushort *)(textureLevel + 0xc) * yoffset + xoffset);
  ((void (*)())_glePixelPackSettings)(glContext,format,type,width,height,forwardedArg9,&srcPixelBytes,srcStartThenPointer,&srcRowBytes,srcRowPadding
             ,srcImageBytes,srcImagePadding);
  iVar3 = ((int (*)())_gleComponents)(format);
  srcStartThenPointer[0] = pixels + srcStartThenPointer[0];
  iVar2 = levelRowComponents - iVar2 * width;
  iVar3 = iVar3 * width;
  if ((srcStartThenPointer[0] == destPixels) && (srcRowBytes == levelRowBytes)) {
    return 1;
  }
  if (type == 0x140b) {
LAB_00019e6c:
    if ((*(ushort *)(textureLevel + 0x10) == format) && (*(ushort *)(textureLevel + 0x12) == type)) {
      _gleCopy(srcStartThenPointer[0],destPixels,width * srcPixelBytes,height,srcRowBytes,levelRowBytes);
      return 1;
    }
    return 0;
  }
  if (type < 0x140c) {
    if (type == 0x1403) {
      if (*(short *)(textureLevel + 0x12) == 0x1401) {
        putResult = _gleTextureImagePut_FastUshort
                          (glContext,width,height,srcStartThenPointer[0],destPixels,srcRowBytes,iVar3,iVar2,levelRowComponents,
                           (uint)*(ushort *)(textureLevel + 0x10),format);
        return putResult;
      }
      return 0;
    }
    if (type < 0x1404) {
      if (type == 0x1401) {
        if (*(short *)(textureLevel + 0x12) == 0x1401) {
          putResult = _gleTextureImagePut_FastUbyte
                            (glContext,width,height,srcStartThenPointer[0],destPixels,srcRowBytes,iVar3,iVar2,levelRowComponents,
                             (uint)*(ushort *)(textureLevel + 0x10),format);
          return putResult;
        }
        return 0;
      }
      if (0x1401 < type) {
        if (*(short *)(textureLevel + 0x12) == 0x1401) {
          putResult = _gleTextureImagePut_FastShort
                            (glContext,width,height,srcStartThenPointer[0],destPixels,srcRowBytes,iVar3,iVar2,levelRowComponents,
                             (uint)*(ushort *)(textureLevel + 0x10),format);
          return putResult;
        }
        return 0;
      }
      if (type == 0x1400) {
        if (*(short *)(textureLevel + 0x12) == 0x1401) {
          putResult = _gleTextureImagePut_FastByte
                            (glContext,width,height,srcStartThenPointer[0],destPixels,srcRowBytes,iVar3,iVar2,levelRowComponents,
                             (uint)*(ushort *)(textureLevel + 0x10),format);
          return putResult;
        }
        return 0;
      }
    }
    else {
      if (type == 0x1405) {
        if (*(short *)(textureLevel + 0x12) == 0x1401) {
          putResult = _gleTextureImagePut_FastUint
                            (glContext,width,height,srcStartThenPointer[0],destPixels,srcRowBytes,iVar3,iVar2,levelRowComponents,
                             (uint)*(ushort *)(textureLevel + 0x10),format);
          return putResult;
        }
        return 0;
      }
      if (type < 0x1405) {
        if (*(short *)(textureLevel + 0x12) == 0x1401) {
          putResult = _gleTextureImagePut_FastInt
                            (glContext,width,height,srcStartThenPointer[0],destPixels,srcRowBytes,iVar3,iVar2,levelRowComponents,
                             (uint)*(ushort *)(textureLevel + 0x10),format);
          return putResult;
        }
        return 0;
      }
      if (type == 0x1406) goto LAB_00019e6c;
    }
  }
  else {
    if (type < 0x8369) {
      if (0x8361 < type) goto LAB_00019e6c;
      bVar1 = 4 < type - 0x8032;
    }
    else {
      if (type < 0x85ba) goto LAB_00019eac;
      if (type < 0x85bc) goto LAB_00019e6c;
      bVar1 = 1 < type - 0x86da;
    }
    if (!bVar1) goto LAB_00019e6c;
  }
LAB_00019eac:
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x500;
  return 0;
}

/* _gleComponents @ 0x19ed8 (228 bytes) */
int _gleComponents(format)
  uint format;
{
  uint uVar1;
  
  if (format == 0x8049) {
    return 1;
  }
  if (format < 0x804a) {
    if (format != 0x1908) {
      if (format < 0x1909) {
        if (0x18ff < format) {
          if (0x1906 < format) {
            return 3;
          }
          return 1;
        }
      }
      else {
        if (format == 0x190a) {
          return 2;
        }
        if (format < 0x190a) {
          return 1;
        }
      }
    }
  }
  else {
    if (format == 0x86dc) {
      return 4;
    }
    if (format < 0x86dd) {
      if (format == 0x80e1) {
        return 4;
      }
      if (0x80e1 < format) {
        if (format != 0x85b9) {
          return 4;
        }
        return 2;
      }
      uVar1 = 0x80e0;
    }
    else {
      if (format < 0x86f4) {
        return 4;
      }
      if (format < 0x86f6) {
        return 2;
      }
      uVar1 = 0x86f6;
    }
    if (format == uVar1) {
      return 3;
    }
  }
  return 4;
}

/* _gleCreatePluginTextureLevel @ 0x19fbc (1228 bytes) */
int _gleCreatePluginTextureLevel(glContext, textureObject, textureLevel, face, level, internalformat)
  int glContext;
  undefined4 *textureObject;
  int textureLevel;
  int face;
  uint level;
  uint internalformat;
{
  uint loopIndex4;
  int loopIndex2;
  int *rendererDispatch;
  byte faceCount;
  ushort levelBit;
  bool levelInconsistent;
  int remaining;
  uint log2Height;
  uint log2Depth;
  undefined4 baseFormat;
  undefined4 resetResult;
  uint border;
  uint maxLog2Size;
  uint levelBorder;
  undefined4 rendererTextureName;
  undefined4 *faceMaskCursor;
  undefined4 *rendererContext;
  int widthAtLevel;
  int levelRecord;
  int loopIndex;
  int heightNoBorder;
  int depthNoBorder;
  int rendererCursor;
  uint depthDimFlag;
  uint heightDimFlag;
  int widthNoBorder;
  uint changeFlags;
  int loopIndex3;
  undefined4 *faceMaskCursor2;
  int depthAtLevel;
  int heightAtLevel;
  
  border = (uint)*(byte *)(textureLevel + 10);
  heightDimFlag = (uint)*(byte *)((int)textureObject + 0x92);
  depthDimFlag = (uint)*(byte *)((int)textureObject + 0x93);
  widthNoBorder = (uint)*(ushort *)(textureLevel + 4) + border * -2;
  faceCount = *(byte *)(textureObject + 0x24);
  heightNoBorder = (uint)*(ushort *)(textureLevel + 6) - border * heightDimFlag;
  changeFlags = 0;
  depthNoBorder = (uint)*(ushort *)(textureLevel + 8) - border * depthDimFlag;
  if (level == 0) {
    if (*(int *)(textureLevel + 0x14) != 0) {
      changeFlags = 4;
    }
    if (*(char *)((int)textureObject + 0x91) == '\0') {
      maxLog2Size = 0x1f - LZCOUNT(widthNoBorder);
      if (*(byte *)(textureObject + 0x21) != maxLog2Size) {
        *(char *)(textureObject + 0x21) = (char)maxLog2Size;
        changeFlags = changeFlags | 1;
      }
      if (heightDimFlag != 0) {
        log2Height = 0x1f - LZCOUNT(heightNoBorder);
        if ((int)maxLog2Size < (int)log2Height) {
          maxLog2Size = log2Height;
        }
        if (*(byte *)((int)textureObject + 0x85) != log2Height) {
          *(char *)((int)textureObject + 0x85) = (char)log2Height;
          changeFlags = changeFlags | 1;
        }
        if (depthDimFlag != 0) {
          log2Depth = 0x1f - LZCOUNT(depthNoBorder);
          if ((int)maxLog2Size < (int)log2Depth) {
            maxLog2Size = log2Depth;
          }
          if (*(byte *)((int)textureObject + 0x86) != log2Depth) {
            *(char *)((int)textureObject + 0x86) = (char)log2Depth;
            changeFlags = changeFlags | 1;
          }
        }
      }
      *(char *)((int)textureObject + 0x87) = (char)maxLog2Size;
    }
    else {
      changeFlags = changeFlags | 1;
      maxLog2Size = 1;
    }
    if ((changeFlags & 1) == 0) {
      *(ushort *)((int)textureObject + face * 2 + 0x94) =
           *(ushort *)((int)textureObject + face * 2 + 0x94) | 1;
      if (*(int *)(textureLevel + 0x14) != 0) {
        *(ushort *)((int)textureObject + face * 2 + 0xa0) =
             *(ushort *)((int)textureObject + face * 2 + 0xa0) | 1;
      }
    }
    else {
      loopIndex3 = 0;
      if (faceCount != 0) {
        loopIndex = 0;
        faceMaskCursor = textureObject;
        faceMaskCursor2 = textureObject;
        do {
          loopIndex4 = 0;
          *(undefined2 *)(faceMaskCursor + 0x25) = 0;
          *(undefined2 *)(faceMaskCursor + 0x28) = 0;
          if (-1 < (int)maxLog2Size) {
            remaining = maxLog2Size + 1;
            levelRecord = (int)textureObject + loopIndex + 0xc4;
            widthAtLevel = widthNoBorder;
            depthAtLevel = depthNoBorder;
            heightAtLevel = heightNoBorder;
            do {
              levelBorder = (uint)*(byte *)(levelRecord + 10);
              if ((((uint)*(ushort *)(levelRecord + 4) == widthAtLevel + levelBorder * 2) &&
                  ((uint)*(ushort *)(levelRecord + 6) == heightAtLevel + levelBorder * heightDimFlag)) &&
                 ((uint)*(ushort *)(levelRecord + 8) == depthAtLevel + levelBorder * depthDimFlag)) {
                levelBit = (ushort)(1 << (loopIndex4 & 0x3f));
                *(ushort *)(faceMaskCursor2 + 0x25) = *(ushort *)(faceMaskCursor2 + 0x25) | levelBit;
                if (*(int *)(levelRecord + 0x14) != 0) {
                  *(ushort *)(faceMaskCursor2 + 0x28) = *(ushort *)(faceMaskCursor2 + 0x28) | levelBit;
                }
              }
              if (1 < widthAtLevel) {
                widthAtLevel = widthAtLevel >> 1;
              }
              if (1 < heightAtLevel) {
                heightAtLevel = heightAtLevel >> 1;
              }
              if (1 < depthAtLevel) {
                depthAtLevel = depthAtLevel >> 1;
              }
              loopIndex4 = loopIndex4 + 1;
              levelRecord = levelRecord + 0x18;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          loopIndex3 = loopIndex3 + 1;
          faceMaskCursor2 = (undefined4 *)((int)faceMaskCursor2 + 2);
          faceMaskCursor = (undefined4 *)((int)faceMaskCursor + 2);
          loopIndex = loopIndex + 0x168;
        } while (loopIndex3 < (int)(uint)faceCount);
      }
    }
    if ((internalformat != *(ushort *)(textureObject + 0x1e)) || (*(int *)(textureLevel + 0x10) != textureObject[0x1f])) {
      *(short *)(textureObject + 0x1e) = (short)internalformat;
      *(undefined2 *)(textureObject + 0x1f) = *(undefined2 *)(textureLevel + 0x10);
      *(undefined2 *)((int)textureObject + 0x7e) = *(undefined2 *)(textureLevel + 0x12);
      if (internalformat - 0x80e2 < 6) {
        internalformat = (uint)*(ushort *)((int)textureObject + 0x7a);
      }
      baseFormat = ((int (*)())_gleReqToBase)(internalformat);
      changeFlags = changeFlags | 1;
      *(short *)((int)textureObject + 0x26) = (short)baseFormat;
    }
    goto LAB_0001a408;
  }
  if ((int)level < 1) {
    if (*(int *)(textureLevel + 0x14) != 0) {
      changeFlags = 0x40;
    }
    if ((uint)*(byte *)(textureObject + 0x23) != 0x1fU - LZCOUNT(widthNoBorder)) {
      *(char *)(textureObject + 0x23) = (char)(0x1fU - LZCOUNT(widthNoBorder));
      changeFlags = changeFlags | 0x20;
    }
    if (internalformat != *(ushort *)((int)textureObject + 0x7a)) {
      *(short *)((int)textureObject + 0x7a) = (short)internalformat;
      if ((ushort)(*(short *)(textureObject + 0x1e) + 0x7f1eU) < 6) {
        baseFormat = ((int (*)())_gleReqToBase)(internalformat);
        *(short *)((int)textureObject + 0x26) = (short)baseFormat;
      }
      changeFlags = changeFlags | 0x20;
    }
    goto LAB_0001a408;
  }
  if (*(int *)(textureLevel + 0x14) != 0) {
    changeFlags = 4;
  }
  levelInconsistent = false;
  if (*(char *)((int)textureObject + 0x91) == '\0') {
    if (((0x1f - LZCOUNT(widthNoBorder)) + level == (uint)*(byte *)(textureObject + 0x21)) ||
       ((0x1f - LZCOUNT(widthNoBorder) == 0 && ((int)(uint)*(byte *)(textureObject + 0x21) < (int)level)))) {
      levelInconsistent = false;
      if (heightDimFlag != 0) {
        if (((0x1f - LZCOUNT(heightNoBorder)) + level != (uint)*(byte *)((int)textureObject + 0x85)) &&
           ((0x1f - LZCOUNT(heightNoBorder) != 0 ||
            ((int)level <= (int)(uint)*(byte *)((int)textureObject + 0x85))))) goto LAB_0001a32c;
        levelInconsistent = false;
        if (depthDimFlag != 0) {
          if (((0x1f - LZCOUNT(depthNoBorder)) + level != (uint)*(byte *)((int)textureObject + 0x86)) &&
             ((0x1f - LZCOUNT(depthNoBorder) != 0 ||
              ((int)level <= (int)(uint)*(byte *)((int)textureObject + 0x86))))) goto LAB_0001a32c;
          levelInconsistent = false;
        }
      }
    }
    else {
LAB_0001a32c:
      levelInconsistent = true;
    }
  }
  levelBit = (ushort)(1 << (level & 0x3f));
  if (levelInconsistent) {
    *(ushort *)((int)textureObject + face * 2 + 0x94) =
         *(ushort *)((int)textureObject + face * 2 + 0x94) & ~levelBit;
    *(ushort *)((int)textureObject + face * 2 + 0xa0) =
         *(ushort *)((int)textureObject + face * 2 + 0xa0) & ~levelBit;
  }
  else {
    *(ushort *)((int)textureObject + face * 2 + 0x94) =
         levelBit | *(ushort *)((int)textureObject + face * 2 + 0x94);
    if (*(int *)(textureLevel + 0x14) != 0) {
      *(ushort *)((int)textureObject + face * 2 + 0xa0) =
           levelBit | *(ushort *)((int)textureObject + face * 2 + 0xa0);
    }
  }
LAB_0001a408:
  rendererCursor = glContext + 0x10000;
  resetResult = ((int (*)())_gleResetLevels)(glContext,textureObject,changeFlags);
  loopIndex2 = 0;
  if (*(char *)(glContext + 0x85a4) != '\0') {
    do {
      rendererDispatch = (int *)(rendererCursor + -0x777c);
      rendererTextureName = *textureObject;
      rendererContext = (undefined4 *)(rendererCursor + -0x7a54);
      rendererCursor = rendererCursor + 0x2e0;
      loopIndex2 = loopIndex2 + 1;
      textureObject = textureObject + 1;
      (**(code **)(*rendererDispatch + 0x150))(*rendererContext,rendererTextureName,resetResult,face,level);
    } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
  }
  return;
}

/* _gleReqToBase @ 0x1a488 (948 bytes) */
int _gleReqToBase(internalformat)
  uint internalformat;
{
  if (internalformat == 0x86f4) {
    return 0x86f4;
  }
  if (internalformat < 0x86f5) {
    if (0x804d < internalformat) {
      if (internalformat == 0x83f0) {
        return 0x1907;
      }
      if (internalformat < 0x83f1) {
        if (0x805b < internalformat) {
          if (internalformat < 0x80e2) {
            return internalformat;
          }
          if (32999 < internalformat) {
            if (internalformat - 0x81a5 < 3) {
              return 0x1902;
            }
            return internalformat;
          }
          return 0x1900;
        }
        if (internalformat < 0x8055) {
          if (0x804e < internalformat) {
            return 0x1907;
          }
          return internalformat;
        }
      }
      else {
        if (internalformat == 0x84eb) {
          return 0x190a;
        }
        if (internalformat < 0x84ec) {
          if (internalformat == 0x84e9) {
            return 0x1906;
          }
          if (0x84e9 < internalformat) {
            return 0x1909;
          }
          if (0x83f3 < internalformat) {
            return internalformat;
          }
        }
        else {
          if (internalformat == 0x84ed) {
            return 0x1907;
          }
          if (internalformat < 0x84ed) {
            return 0x8049;
          }
          if (internalformat != 0x84ee) {
            if (internalformat == 0x86dc) {
              return 0x86dc;
            }
            return internalformat;
          }
        }
      }
      return 0x1908;
    }
    if (0x8049 < internalformat) {
      return 0x8049;
    }
    if (internalformat < 0x190b) {
      if (0x1905 < internalformat) {
        return internalformat;
      }
      if (internalformat == 3) {
        return 0x1907;
      }
      if (3 < internalformat) {
        if (internalformat == 0x1900) {
          return 0x1900;
        }
        if (0x1900 < internalformat) {
          if (internalformat == 0x1902) {
            return 0x1902;
          }
          return internalformat;
        }
        if (internalformat == 4) {
          return 0x1908;
        }
        return internalformat;
      }
      if (internalformat == 1) {
        return 0x1909;
      }
      if (internalformat != 2) {
        return internalformat;
      }
    }
    else {
      if (internalformat < 0x8043) {
        if (0x803e < internalformat) {
          return 0x1909;
        }
        if (internalformat == 0x2a10) {
          return 0x1907;
        }
        if (internalformat < 0x2a10) {
          return internalformat;
        }
        if (0x803a < internalformat) {
          return 0x1906;
        }
        return internalformat;
      }
      if (0x8048 < internalformat) {
        return internalformat;
      }
    }
  }
  else {
    if (internalformat == 0x870a) {
      return 0x86f6;
    }
    if (internalformat < 0x870b) {
      if (internalformat < 0x8703) {
        if (0x8700 < internalformat) {
          return 0x1909;
        }
        if (0x86fa < internalformat) {
          if (internalformat < 0x86fd) {
            return 0x1908;
          }
          if (internalformat - 0x86fe < 2) {
            return 0x1907;
          }
          return internalformat;
        }
        if (0x86f7 < internalformat) {
          return 0x86f4;
        }
        if (internalformat != 0x86f5) {
          if (internalformat == 0x86f6) {
            return 0x86f6;
          }
          return internalformat;
        }
      }
      else {
        if (internalformat < 0x8707) {
          if (internalformat < 0x8705) {
            return 0x190a;
          }
          return 0x1906;
        }
        if (internalformat < 0x8709) {
          return 0x8049;
        }
      }
      return 0x86f5;
    }
    if (internalformat != 0x8819) {
      if (internalformat < 0x881a) {
        if (internalformat == 0x8814) {
          return 0x1908;
        }
        if (internalformat < 0x8815) {
          if (internalformat == 0x870b) {
            return 0x86dc;
          }
          if (internalformat < 0x870e) {
            return 0x1908;
          }
          return internalformat;
        }
        if (internalformat == 0x8816) {
          return 0x1906;
        }
        if (internalformat < 0x8816) {
          return 0x1907;
        }
        if (internalformat == 0x8817) {
          return 0x8049;
        }
        if (internalformat == 0x8818) {
          return 0x1909;
        }
        return internalformat;
      }
      if (internalformat == 0x881e) {
        return 0x1909;
      }
      if (internalformat < 0x881f) {
        if (internalformat == 0x881b) {
          return 0x1907;
        }
        if (internalformat < 0x881b) {
          return 0x1908;
        }
        if (internalformat == 0x881c) {
          return 0x1906;
        }
        if (internalformat == 0x881d) {
          return 0x8049;
        }
        return internalformat;
      }
      if (internalformat != 0x8837) {
        if (0x8837 < internalformat) {
          if (internalformat - 0x885e < 2) {
            return 0x86f4;
          }
          return internalformat;
        }
        if (internalformat != 0x881f) {
          return internalformat;
        }
      }
    }
  }
  return 0x190a;
}

/* _gleResetLevels @ 0x1a83c (1016 bytes) */
int _gleResetLevels(glContext, textureObject, updateFlags)
  int glContext;
  int textureObject;
  uint updateFlags;
{
  uint loopIndex3;
  int loopIndex2;
  int remaining;
  byte levelFlags;
  ushort faceLevelMask;
  bool allFacesHaveBaseThenChainRequired;
  bool levelRangeRestrictedThenSkipDowngrade;
  bool hasUpperLevels;
  bool restrictLevels;
  bool allFacesHaveRange;
  byte *srcCursor;
  uint lastDefinedThenResidentLevelCount;
  uint highestFlaggedThenClampedMaxLevel;
  ushort *srcCursor2;
  ushort minFilter;
  uint faceCount;
  uint maxLevelThenLevelMask;
  uint baseLevel;
  int loopIndex;
  uint baseLevelBitThenFlags;
  int levelRecord;
  int clampedChannelLevel;
  uint faceCountdownThenLevelCursor;
  
  baseLevel = (uint)*(short *)(textureObject + 0x60);
  lastDefinedThenResidentLevelCount = (uint)*(byte *)(textureObject + 0x87);
  levelRangeRestrictedThenSkipDowngrade = false;
  faceCount = (uint)*(byte *)(textureObject + 0x90);
  maxLevelThenLevelMask = (uint)*(short *)(textureObject + 0x62);
  minFilter = *(ushort *)(textureObject + 0x3a);
  if ((baseLevel != 0) || (maxLevelThenLevelMask != 1000)) {
    levelRangeRestrictedThenSkipDowngrade = true;
  }
  if ((*(ushort *)(textureObject + 0x24) & 0x400) != 0) {
    highestFlaggedThenClampedMaxLevel = 0;
    remaining = 0xf;
    loopIndex3 = 0;
    srcCursor = (byte *)(textureObject + 0xcf);
    do {
      levelFlags = *srcCursor;
      srcCursor = srcCursor + 0x18;
      if ((levelFlags & 0x10) != 0) {
        highestFlaggedThenClampedMaxLevel = loopIndex3;
      }
      loopIndex3 = loopIndex3 + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
    if ((highestFlaggedThenClampedMaxLevel != 0) && ((int)highestFlaggedThenClampedMaxLevel < (int)maxLevelThenLevelMask)) {
      maxLevelThenLevelMask = highestFlaggedThenClampedMaxLevel;
    }
  }
  if ((int)lastDefinedThenResidentLevelCount < (int)baseLevel) {
    baseLevel = lastDefinedThenResidentLevelCount;
  }
  highestFlaggedThenClampedMaxLevel = lastDefinedThenResidentLevelCount;
  if (((int)maxLevelThenLevelMask <= (int)lastDefinedThenResidentLevelCount) && (highestFlaggedThenClampedMaxLevel = maxLevelThenLevelMask, (int)maxLevelThenLevelMask < (int)baseLevel)) {
    highestFlaggedThenClampedMaxLevel = baseLevel;
  }
  *(byte *)(textureObject + 0x8b) = *(byte *)(textureObject + 0x87) - (char)baseLevel;
  clampedChannelLevel = *(byte *)(textureObject + 0x84) - baseLevel;
  if (clampedChannelLevel < 0) {
    clampedChannelLevel = 0;
  }
  *(char *)(textureObject + 0x88) = (char)clampedChannelLevel;
  clampedChannelLevel = *(byte *)(textureObject + 0x85) - baseLevel;
  if (clampedChannelLevel < 0) {
    clampedChannelLevel = 0;
  }
  *(char *)(textureObject + 0x89) = (char)clampedChannelLevel;
  clampedChannelLevel = *(byte *)(textureObject + 0x86) - baseLevel;
  if (clampedChannelLevel < 0) {
    clampedChannelLevel = 0;
  }
  *(char *)(textureObject + 0x8a) = (char)clampedChannelLevel;
  maxLevelThenLevelMask = (uint)(-1 << ((0x1f - highestFlaggedThenClampedMaxLevel) + baseLevel & 0x3f)) >> (0x1f - highestFlaggedThenClampedMaxLevel & 0x3f) | 1;
  baseLevelBitThenFlags = 1 << (baseLevel & 0x3f) | 1;
  allFacesHaveRange = true;
  hasUpperLevels = false;
  allFacesHaveBaseThenChainRequired = true;
  if (faceCount != 0) {
    srcCursor2 = (ushort *)(textureObject + 0x94);
    faceCountdownThenLevelCursor = faceCount;
    do {
      faceLevelMask = *srcCursor2;
      srcCursor2 = srcCursor2 + 1;
      if ((faceLevelMask & maxLevelThenLevelMask) != maxLevelThenLevelMask) {
        allFacesHaveRange = false;
      }
      if ((faceLevelMask & baseLevelBitThenFlags) != baseLevelBitThenFlags) {
        allFacesHaveBaseThenChainRequired = false;
      }
      if ((faceLevelMask & 0xfffe) != 0) {
        hasUpperLevels = true;
      }
      faceCountdownThenLevelCursor = faceCountdownThenLevelCursor - 1;
    } while (faceCountdownThenLevelCursor != 0);
    if (!allFacesHaveBaseThenChainRequired) {
      minFilter = 0;
    }
  }
  allFacesHaveBaseThenChainRequired = false;
  if ((0x2601 < minFilter) && (*(char *)(textureObject + 0x91) == '\0')) {
    allFacesHaveBaseThenChainRequired = true;
  }
  restrictLevels = false;
  if (((levelRangeRestrictedThenSkipDowngrade) || (allFacesHaveBaseThenChainRequired)) || (hasUpperLevels)) {
    restrictLevels = true;
  }
  maxLevelThenLevelMask = baseLevel;
  if (restrictLevels) {
    if ((*(ushort *)(textureObject + 0x24) & 0x400) == 0) {
      baseLevelBitThenFlags = *(uint *)(textureObject + 0x6c);
      if (((baseLevelBitThenFlags & 0x80) == 0) && (*(char *)(*(int *)(glContext + 0x468c) + 199) != '\0'))
      goto LAB_0001aa44;
    }
    else {
      baseLevelBitThenFlags = *(uint *)(textureObject + 0x6c);
LAB_0001aa44:
      maxLevelThenLevelMask = 0;
    }
    faceCountdownThenLevelCursor = highestFlaggedThenClampedMaxLevel;
    if ((baseLevelBitThenFlags & 0x80) == 0) {
      faceCountdownThenLevelCursor = lastDefinedThenResidentLevelCount;
    }
    lastDefinedThenResidentLevelCount = (faceCountdownThenLevelCursor - maxLevelThenLevelMask) + 1;
  }
  else {
    lastDefinedThenResidentLevelCount = 1;
  }
  if ((((updateFlags & 1) != 0) || (lastDefinedThenResidentLevelCount != *(byte *)(textureObject + 0x8e))) ||
     (maxLevelThenLevelMask != *(byte *)(textureObject + 0x8d))) {
    loopIndex2 = 0;
    if (faceCount != 0) {
      baseLevelBitThenFlags = (uint)*(byte *)(textureObject + 0x8f);
      loopIndex = 0;
      do {
        faceCountdownThenLevelCursor = (uint)*(byte *)(textureObject + 0x8d);
        if (faceCountdownThenLevelCursor <= baseLevelBitThenFlags) {
          levelRecord = faceCountdownThenLevelCursor * 0x18 + textureObject + loopIndex + 0xc4;
          do {
            if ((*(byte *)(levelRecord + 0xb) & 0x50) == 0x40) {
              _gleUploadPluginTextureLevel
                        (glContext,textureObject,levelRecord,loopIndex2,faceCountdownThenLevelCursor,(uint)*(byte *)(glContext + 0x85a8));
              _gleModifyPluginTextureLevel
                        (glContext,textureObject,levelRecord,loopIndex2,faceCountdownThenLevelCursor,0,0,0,(uint)*(ushort *)(levelRecord + 4),
                         (uint)*(ushort *)(levelRecord + 6),(uint)*(ushort *)(levelRecord + 8));
              baseLevelBitThenFlags = (uint)*(byte *)(textureObject + 0x8f);
            }
            faceCountdownThenLevelCursor = faceCountdownThenLevelCursor + 1;
            levelRecord = levelRecord + 0x18;
          } while ((int)faceCountdownThenLevelCursor <= (int)baseLevelBitThenFlags);
        }
        loopIndex2 = loopIndex2 + 1;
        loopIndex = loopIndex + 0x168;
      } while (loopIndex2 < (int)faceCount);
    }
    *(char *)(textureObject + 0x8e) = (char)lastDefinedThenResidentLevelCount;
    *(char *)(textureObject + 0x8d) = (char)maxLevelThenLevelMask;
    *(char *)(textureObject + 0x8f) = (char)maxLevelThenLevelMask + (char)lastDefinedThenResidentLevelCount + -1;
    updateFlags = updateFlags | 2;
  }
  levelRangeRestrictedThenSkipDowngrade = false;
  if (((allFacesHaveBaseThenChainRequired) && (allFacesHaveRange)) || ((*(uint *)(textureObject + 0x6c) & 0x8000) != 0)) {
    levelRangeRestrictedThenSkipDowngrade = true;
  }
  if ((levelRangeRestrictedThenSkipDowngrade) || (highestFlaggedThenClampedMaxLevel = baseLevel, 0x2601 >= minFilter)) goto LAB_0001abf0;
  if (*(char *)(glContext + 0x53e7) == '\0') {
    minFilter = 0;
    goto LAB_0001abf0;
  }
  if (minFilter == 0x2701) {
LAB_0001abcc:
    minFilter = 0x2601;
  }
  else {
    if (minFilter < 0x2702) {
      if (minFilter != 0x2700) goto LAB_0001abf0;
    }
    else if (minFilter != 0x2702) {
      if (minFilter != 0x2703) goto LAB_0001abf0;
      goto LAB_0001abcc;
    }
    minFilter = 0x2600;
  }
LAB_0001abf0:
  *(ushort *)(textureObject + 0x80) = minFilter;
  if ((highestFlaggedThenClampedMaxLevel != *(byte *)(textureObject + 0x83)) || (baseLevel != *(byte *)(textureObject + 0x82))) {
    *(char *)(textureObject + 0x83) = (char)highestFlaggedThenClampedMaxLevel;
    *(char *)(textureObject + 0x82) = (char)baseLevel;
  }
  return updateFlags;
}

/* _glTexParameterf_Exec @ 0x1ac34 (40 bytes) */
void _glTexParameterf_Exec(undefined4 glContext,undefined4 target,undefined4 pname,float param)
{
  float fStack00000024;
  
  fStack00000024 = (float)param;
  ((int (*)())_glTexParameterF_Exec)(glContext,target,pname,&STACKARG(0x24));
  return;
}

/* _glTexParameterF_Exec @ 0x1ac5c (2288 bytes) */
int _glTexParameterF_Exec(glContext, target, pname, params)
  int glContext;
  undefined4 target;
  undefined *pname;
  float *params;
{
  undefined4 glErrorCode;
  bool isLegalEnum;
  float borderColorComponent;
  float fVar3;
  uint legalEnum;
  int textureObject;
  undefined4 modifyFlag;
  float fVar7;
  uint paramInt;
  float paramDouble;
  
  textureObject = ((int (*)())_gleLookUpNonProxyTexture)(glContext,target);
  fVar3 = FLOAT_00108e54;
  fVar7 = FLOAT_00108e50;
  modifyFlag = 0;
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (textureObject == 0) goto LAB_0001b4fc;
    if (pname == (undefined *)0x813c) {
      if ((int)*params < 0) goto LAB_0001b268;
      *(short *)(textureObject + 0x60) = (short)(int)*params;
LAB_0001b280:
      modifyFlag = 1;
    }
    else if (pname < (undefined *)0x813d) {
      if (pname != (undefined *)0x2803) {
        if ((undefined *)0x2803 < pname) {
          if (pname == (undefined *)0x80bf) {
            fVar7 = *params;
            fVar3 = FLOAT_00108e50;
            if ((fVar7 <= FLOAT_00108e50) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 <= fVar7)) {
              *(float *)(textureObject + 0x68) = fVar3;
            }
            else {
              *(float *)(textureObject + 0x68) = fVar7;
            }
          }
          else if (pname < (undefined *)0x80c0) {
            if (pname == (undefined *)0x8066) {
              fVar7 = *params;
              if (fVar7 < FLOAT_00108e50) {
                fVar7 = 0.0;
              }
              else if (FLOAT_00108e54 < fVar7) {
                fVar7 = 1.0;
              }
              *(float *)(textureObject + 0x28) = fVar7;
            }
            else {
              if (pname != (undefined *)0x8072) goto LAB_0001b4fc;
              paramDouble = (double)*params;
              if (DOUBLE_00108d80 <= (double)paramDouble) {
                paramInt = (int)((double)paramDouble - DOUBLE_00108d80) ^ 0x80000000;
              }
              else {
                paramInt = (uint)(int)*params;
              }
              if (paramInt != 0x812f) {
                if (paramInt < 0x8130) {
                  if (0x28ff < paramInt) {
                    if (0x2901 < paramInt) {
                      legalEnum = 0x812d;
                      goto LAB_0001b220;
                    }
                    goto LAB_0001b228;
                  }
                }
                else {
                  if (paramInt < 0x8744) {
                    if (0x8741 < paramInt) goto LAB_0001b228;
                    legalEnum = 0x8370;
                  }
                  else {
                    legalEnum = 0x8912;
                  }
LAB_0001b220:
                  if (paramInt == legalEnum) goto LAB_0001b228;
                }
                goto LAB_0001b4fc;
              }
LAB_0001b228:
              *(short *)(textureObject + 0x38) = (short)paramInt;
            }
          }
          else if (pname == (undefined *)0x813a) {
            *(float *)(textureObject + 0x54) = *params;
          }
          else {
            if (pname != (undefined *)0x813b) goto LAB_0001b4fc;
            *(float *)(textureObject + 0x58) = *params;
          }
          goto LAB_0001b514;
        }
        if (pname == (undefined *)0x2800) {
          paramDouble = (double)*params;
          if (DOUBLE_00108d80 <= (double)paramDouble) {
            paramInt = (int)((double)paramDouble - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            paramInt = (uint)(int)*params;
          }
          if (paramInt - 0x2600 < 2) {
            *(short *)(textureObject + 0x3c) = (short)paramInt;
            goto LAB_0001b514;
          }
        }
        else if (pname < (undefined *)0x2801) {
          if (pname == ((unsigned char *)0x00001004)) {
            borderColorComponent = *params;
            if (borderColorComponent < FLOAT_00108e50) {
              *(float *)(textureObject + 0x40) = FLOAT_00108e50;
            }
            else if (FLOAT_00108e54 < borderColorComponent) {
              *(float *)(textureObject + 0x40) = FLOAT_00108e54;
            }
            else {
              *(float *)(textureObject + 0x40) = borderColorComponent;
            }
            borderColorComponent = params[1];
            if (borderColorComponent < fVar7) {
              *(float *)(textureObject + 0x44) = fVar7;
            }
            else if (fVar3 < borderColorComponent) {
              *(float *)(textureObject + 0x44) = fVar3;
            }
            else {
              *(float *)(textureObject + 0x44) = borderColorComponent;
            }
            borderColorComponent = params[2];
            if (borderColorComponent < fVar7) {
              *(float *)(textureObject + 0x48) = fVar7;
            }
            else if (fVar3 < borderColorComponent) {
              *(float *)(textureObject + 0x48) = fVar3;
            }
            else {
              *(float *)(textureObject + 0x48) = borderColorComponent;
            }
            borderColorComponent = params[3];
            if (borderColorComponent < fVar7) goto LAB_0001af8c;
            if (fVar3 < borderColorComponent) {
              *(float *)(textureObject + 0x4c) = fVar3;
            }
            else {
              *(float *)(textureObject + 0x4c) = borderColorComponent;
            }
            goto LAB_0001b514;
          }
        }
        else if (pname == (undefined *)0x2801) {
          paramDouble = (double)*params;
          if (DOUBLE_00108d80 <= (double)paramDouble) {
            paramInt = (int)((double)paramDouble - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            paramInt = (uint)(int)*params;
          }
          if ((0x25ff < paramInt) && ((paramInt < 0x2602 || (paramInt - 0x2700 < 4)))) {
            *(short *)(textureObject + 0x3a) = (short)paramInt;
            goto LAB_0001b280;
          }
        }
        else if (pname == (undefined *)0x2802) {
          paramDouble = (double)*params;
          if (DOUBLE_00108d80 <= (double)paramDouble) {
            paramInt = (int)((double)paramDouble - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            paramInt = (uint)(int)*params;
          }
          if (paramInt == 0x812f) {
LAB_0001b0e0:
            *(short *)(textureObject + 0x34) = (short)paramInt;
            goto LAB_0001b514;
          }
          if (paramInt < 0x8130) {
            if (0x28ff < paramInt) {
              if (0x2901 < paramInt) {
                legalEnum = 0x812d;
                goto LAB_0001b0d8;
              }
              goto LAB_0001b0e0;
            }
          }
          else {
            if (paramInt < 0x8744) {
              if (0x8741 < paramInt) goto LAB_0001b0e0;
              legalEnum = 0x8370;
            }
            else {
              legalEnum = 0x8912;
            }
LAB_0001b0d8:
            if (paramInt == legalEnum) goto LAB_0001b0e0;
          }
        }
        goto LAB_0001b4fc;
      }
      paramDouble = (double)*params;
      if (DOUBLE_00108d80 <= (double)paramDouble) {
        paramInt = (int)((double)paramDouble - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        paramInt = (uint)(int)*params;
      }
      if (paramInt != 0x812f) {
        if (paramInt < 0x8130) {
          if (paramInt < 0x2900) goto LAB_0001b4fc;
          if (0x2901 < paramInt) {
            legalEnum = 0x812d;
            goto LAB_0001b17c;
          }
        }
        else {
          if (paramInt < 0x8744) {
            if (0x8741 < paramInt) goto LAB_0001b184;
            legalEnum = 0x8370;
          }
          else {
            legalEnum = 0x8912;
          }
LAB_0001b17c:
          if (paramInt != legalEnum) goto LAB_0001b4fc;
        }
      }
LAB_0001b184:
      *(short *)(textureObject + 0x36) = (short)paramInt;
    }
    else if (pname == (undefined *)0x85bc) {
      paramDouble = (double)*params;
      if (DOUBLE_00108d80 <= (double)paramDouble) {
        paramInt = (int)((double)paramDouble - DOUBLE_00108d80) ^ 0x80000000;
      }
      else {
        paramInt = (uint)(int)*params;
      }
      if (2 < paramInt - 0x85bd) goto LAB_0001b4fc;
      *(short *)(textureObject + 0x3e) = (short)paramInt;
    }
    else {
      if ((undefined *)0x85bc < pname) {
        if (pname == (undefined *)0x884c) {
          paramDouble = (double)*params;
          if (DOUBLE_00108d80 <= (double)paramDouble) {
            paramInt = (int)((double)paramDouble - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            paramInt = (uint)(int)*params;
          }
          if ((paramInt == 0) || (paramInt == 0x884e)) {
            *(short *)(textureObject + 0x66) = (short)paramInt;
            goto LAB_0001b514;
          }
        }
        else if (pname < (undefined *)0x884d) {
          if (pname == (undefined *)0x871a) {
            *(float *)(textureObject + 0x40) = *params;
            *(float *)(textureObject + 0x44) = params[1];
            *(float *)(textureObject + 0x48) = params[2];
            fVar7 = params[3];
LAB_0001af8c:
            *(float *)(textureObject + 0x4c) = fVar7;
            goto LAB_0001b514;
          }
          if (pname == (undefined *)0x884b) {
            paramDouble = (double)*params;
            if (DOUBLE_00108d80 <= (double)paramDouble) {
              paramInt = (int)((double)paramDouble - DOUBLE_00108d80) ^ 0x80000000;
            }
            else {
              paramInt = (uint)(int)*params;
            }
            if (paramInt != 0x1909) {
              if (paramInt < 0x190a) {
                isLegalEnum = paramInt == 0x1906;
              }
              else {
                isLegalEnum = paramInt == 0x8049;
              }
              if (!isLegalEnum) goto LAB_0001b4fc;
            }
            *(short *)(textureObject + 0x6c) = (short)paramInt;
            goto LAB_0001b514;
          }
        }
        else if (pname == (undefined *)0x884d) {
          paramDouble = (double)*params;
          if (DOUBLE_00108d80 <= (double)paramDouble) {
            paramInt = (int)((double)paramDouble - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            paramInt = (uint)(int)*params;
          }
          if (paramInt - 0x200 < 8) {
            *(short *)(textureObject + 100) = (short)paramInt;
            goto LAB_0001b514;
          }
        }
        else if (pname == (undefined *)0x8a7f) {
          paramDouble = (double)*params;
          if (DOUBLE_00108d80 <= (double)paramDouble) {
            paramInt = (int)((double)paramDouble - DOUBLE_00108d80) ^ 0x80000000;
          }
          else {
            paramInt = (uint)(int)*params;
          }
          if (paramInt < 2) {
            paramInt = (paramInt & 1) << 6 | *(uint *)(textureObject + 0x6c) & 0xffffffbf;
            goto LAB_0001b4f4;
          }
        }
LAB_0001b4fc:
        if (*(int *)(glContext + 0x7574) != 0) {
          return textureObject;
        }
        glErrorCode = 0x500;
        goto LAB_0001b50c;
      }
      if (pname == (undefined *)0x84fe) {
        if (*params < FLOAT_00108e54) goto LAB_0001b268;
        *(float *)(textureObject + 0x50) = *params;
      }
      else {
        if (pname < (undefined *)0x84ff) {
          if (pname != (undefined *)0x813d) {
            if (pname == (undefined *)0x8191) {
              paramDouble = (double)*params;
              if (DOUBLE_00108d80 <= (double)paramDouble) {
                paramInt = (int)((double)paramDouble - DOUBLE_00108d80) ^ 0x80000000;
              }
              else {
                paramInt = (uint)(int)*params;
              }
              if (paramInt < 2) {
                paramInt = (paramInt & 1) << 0xf | *(uint *)(textureObject + 0x6c) & 0xffff7fff;
                goto LAB_0001b4f4;
              }
            }
            goto LAB_0001b4fc;
          }
          if (-1 < (int)*params) {
            *(short *)(textureObject + 0x62) = (short)(int)*params;
            goto LAB_0001b280;
          }
LAB_0001b268:
          if (*(int *)(glContext + 0x7574) != 0) {
            return textureObject;
          }
          glErrorCode = 0x501;
          goto LAB_0001b50c;
        }
        if (pname == (undefined *)0x8501) {
          *(float *)(textureObject + 0x5c) = *params;
        }
        else {
          if (pname != (undefined *)0x85b6) goto LAB_0001b4fc;
          paramInt = (uint)(*params != FLOAT_00108e50) << 7 | *(uint *)(textureObject + 0x6c) & 0xffffff7f;
LAB_0001b4f4:
          *(uint *)(textureObject + 0x6c) = paramInt;
        }
      }
    }
LAB_0001b514:
    textureObject = ((int (*)())_gleModifyPluginTexture)(glContext,textureObject,modifyFlag);
    *(uint *)(glContext + 0x314) =
         *(uint *)(glContext + 0x314) | 1 << (*(uint *)(glContext + 0x53d4) & 0x3f);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return textureObject;
    }
    glErrorCode = 0x502;
LAB_0001b50c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return textureObject;
}

/* _glGetError_Exec @ 0x1b54c (176 bytes) */
int _glGetError_Exec(glContext)
  int glContext;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar1 = *(int *)(glContext + 0x7574);
    *(undefined4 *)(glContext + 0x7574) = 0;
    if ((iVar1 == 0) && (*(char *)(glContext + 0x85a4) != '\0')) {
      do {
        iVar1 = uVar2 * 0x2e0 + glContext;
        iVar1 = (**(code **)(*(int *)(iVar1 + 0x8884) + 0x180))(*(undefined4 *)(iVar1 + 0x85ac));
        uVar2 = uVar2 + 1 & 0xff;
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = 0;
      } while (uVar2 < *(byte *)(glContext + 0x85a4));
    }
  }
  else {
    if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
    iVar1 = 0;
  }
  return iVar1;
}

/* _glBlendFunc_Exec @ 0x1b5fc (168 bytes) */
void _glBlendFunc_Exec(glContext, sfactor, dfactor)
  int glContext;
  uint sfactor;
  uint dfactor;
{
  bool bVar1;
  undefined4 glErrorCode;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_0001b654;
  }
  if (dfactor < 0x308) {
    if (dfactor < 0x300) {
      bVar1 = 1 < dfactor;
      goto LAB_0001b640;
    }
LAB_0001b65c:
    if (sfactor < 0x309) {
      if (0x2ff < sfactor) goto LAB_0001b684;
      bVar1 = 1 < sfactor;
    }
    else {
      bVar1 = 3 < sfactor - 0x8001;
    }
    if (!bVar1) {
LAB_0001b684:
      *(short *)(glContext + 0x30ce) = (short)dfactor;
      *(short *)(glContext + 0x30cc) = (short)sfactor;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 2;
      *(short *)(glContext + 0x30ca) = (short)dfactor;
      *(short *)(glContext + 0x30c8) = (short)sfactor;
      return;
    }
  }
  else {
    bVar1 = 3 < dfactor - 0x8001;
LAB_0001b640:
    if (!bVar1) goto LAB_0001b65c;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_0001b654:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glColorMask_Exec @ 0x1b6a4 (100 bytes) */
void _glColorMask_Exec(glContext, red, green, blue, alpha)
  int glContext;
  int red;
  int green;
  int blue;
  int alpha;
{
  if (*(short *)(glContext + 0x4a10) < 0) {
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x40000;
    *(byte *)(glContext + 0x31a0) = (byte)((uint)-red >> 0x1f);
    *(byte *)(glContext + 0x31a1) = (byte)((uint)-green >> 0x1f);
    *(byte *)(glContext + 0x31a2) = (byte)((uint)-blue >> 0x1f);
    *(byte *)(glContext + 0x31a3) = (byte)((uint)-alpha >> 0x1f);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glColor4ub_Exec @ 0x1b708 (80 bytes) */
void _glColor4ub_Exec(glContext, red, green, blue, alpha)
  int glContext;
  int red;
  int green;
  int blue;
  int alpha;
{
  undefined4 alphaBits;
  undefined4 greenBits;
  undefined4 blueBits;
  int glContextWord4674;
  
  glContextWord4674 = *(int *)(glContext + 0x4674);
  alphaBits = *(undefined4 *)(alpha * 4 + glContextWord4674);
  greenBits = *(undefined4 *)(green * 4 + glContextWord4674);
  blueBits = *(undefined4 *)(blue * 4 + glContextWord4674);
  *(undefined4 *)(glContext + 0x2a0) = *(undefined4 *)(red * 4 + glContextWord4674);
  *(undefined4 *)(glContext + 0x2a4) = greenBits;
  *(undefined4 *)(glContext + 0x2a8) = blueBits;
  *(undefined4 *)(glContext + 0x2ac) = alphaBits;
  if (*(char *)(glContext + 0x4df8) == '\0') {
    return;
  }
                    
                    
  (**(code **)(glContext + 0x4de0))(glContext,glContext + 0x2a0);
  return;
}

/* _glTexEnvf_Exec @ 0x1b758 (2524 bytes) */
void _glTexEnvf_Exec(int glContext,int target,uint pname,double param)
{
  bool enumAllowed;
  undefined4 glErrorCode;
  int texUnitState;
  int sourceEnum;
  int texEnvDirtyBit;
  int shaderOpError;
  uint paramEnum;
  uint texEnvDirtyWord;
  code *envModeValue;
  code *combineAlphaValue;
  code *combineRgbValue;
  uint texUnit;
  uint coordReplaceMask;
  
  texUnit = *(uint *)(glContext + 0x53d4);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (target == 0x86de) {
      texUnitState = glContext + texUnit * 0x7c;
      switch(pname) {
      case 0x86d9:
        if (DOUBLE_00108d80 <= param) {
          paramEnum = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          paramEnum = (uint)(int)param;
        }
        if ((paramEnum != 0x8536) && (paramEnum != 0x8538)) goto switchD_0001b7dc_caseD_86da;
        *(short *)(texUnitState + 0x356c) = (short)paramEnum;
        break;
      default:
switchD_0001b7dc_caseD_86da:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0001c14c;
      case 0x86df:
        if (DOUBLE_00108d80 <= param) {
          paramEnum = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          paramEnum = (uint)(int)param;
        }
        shaderOpError = _CheckNVShaderOperation(glContext,paramEnum);
        if (shaderOpError != 0) {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          *(int *)(glContext + 0x7574) = shaderOpError;
          return;
        }
        *(short *)(texUnitState + 0x3564) = (short)paramEnum;
        _gleUpdateTextureParams(glContext,texUnit);
        break;
      case 0x86e2:
        *(float *)(texUnitState + 0x3598) = (float)param;
        break;
      case 0x86e3:
        *(float *)(texUnitState + 0x359c) = (float)param;
        break;
      case 0x86e4:
        if (DOUBLE_00108d80 <= param) {
          paramEnum = (int)(param - DOUBLE_00108d80) ^ 0x80000000;
        }
        else {
          paramEnum = (uint)(int)param;
        }
        if ((paramEnum < 0x84c0) || (*(ushort *)(*(int *)(glContext + 0x468c) + 0xb4) + 0x84c0 <= paramEnum))
        goto switchD_0001b7dc_caseD_86da;
        *(short *)(texUnitState + 0x356a) = (short)paramEnum;
      }
      texEnvDirtyWord = *(uint *)(glContext + 800);
      texEnvDirtyBit = 1;
    }
    else {
      if (target == 0x8861) {
        if (pname == 0x8862) {
          if (param == (double)FLOAT_00108e50) {
            coordReplaceMask = *(uint *)(glContext + 0x3444) &
                    (-2 << (texUnit & 0x1f) | 0xfffffffeU >> 0x20 - (texUnit & 0x1f));
          }
          else {
            coordReplaceMask = *(uint *)(glContext + 0x3444) | 1 << (texUnit & 0x3f);
          }
          *(uint *)(glContext + 0x3444) = coordReplaceMask;
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400000;
          return;
        }
        goto switchD_0001b7dc_caseD_86da;
      }
      if (target != 0x2300) {
        if ((target == 0x8500) && (pname == 0x8501)) {
          texEnvDirtyBit = 0x10000;
          *(float *)(texUnit * 0x7c + glContext + 0x3560) = (float)param;
          texEnvDirtyWord = *(uint *)(glContext + 800);
          goto LAB_0001c12c;
        }
        goto switchD_0001b7dc_caseD_86da;
      }
      if (pname == 0x2200) {
        if (DOUBLE_00108d80 <= param) {
          envModeValue = (code *)((int)(param - DOUBLE_00108d80) ^ 0x80000000);
        }
        else {
          envModeValue = (code *)(int)param;
        }
        if (envModeValue != (code *)0x1e01) {
          if (envModeValue < (code *)0x1e02) {
            if (envModeValue != (code *)0x104) {
              if (envModeValue < (code *)0x105) {
                enumAllowed = envModeValue == (code *)0x0;
              }
              else {
                enumAllowed = envModeValue == (code *)0xbe2;
              }
LAB_0001ba68:
              if (!enumAllowed) goto switchD_0001b7dc_caseD_86da;
            }
          }
          else {
            if (envModeValue < (code *)0x2100) goto switchD_0001b7dc_caseD_86da;
            if ((code *)0x2100 < envModeValue) {
              enumAllowed = envModeValue == (code *)0x8570;
              goto LAB_0001ba68;
            }
          }
        }
        texEnvDirtyBit = 1;
        *(short *)(texUnit * 0x7c + glContext + 0x3538) = (short)envModeValue;
        texEnvDirtyWord = *(uint *)(glContext + 800);
LAB_0001c12c:
        *(uint *)(glContext + 800) = texEnvDirtyWord | texEnvDirtyBit << (texUnit & 0x3f);
        return;
      }
      if (pname == 0x8588) {
        sourceEnum = (int)param;
        if (((sourceEnum == 0x1702) || (sourceEnum - 0x84c0U < 0x10)) ||
           (((sourceEnum == 0x8576 || (((sourceEnum == 0x8577 || (sourceEnum == 0x8578)) || (sourceEnum == 0)))) ||
            (sourceEnum == 1)))) {
          *(short *)(texUnit * 0x7c + glContext + 0x3546) = (short)sourceEnum;
          goto LAB_0001c0e0;
        }
        goto switchD_0001b7dc_caseD_86da;
      }
      if (pname < 0x8589) {
        if (pname == 0x8573) {
          if (((param == (double)FLOAT_00108e54) || (param == (double)FLOAT_00108ea4)) ||
             (param == (double)FLOAT_00108ea8)) {
            *(float *)(texUnit * 0x7c + glContext + 0x3558) = (float)param;
          }
          else {
LAB_0001c0bc:
            if (*(int *)(glContext + 0x7574) == 0) {
              *(undefined4 *)(glContext + 0x7574) = 0x500;
            }
          }
        }
        else {
          if (0x8573 < pname) {
            if (pname == 0x8581) {
              sourceEnum = (int)param;
              if (((((sourceEnum == 0x1702) || (sourceEnum - 0x84c0U < 0x10)) || (sourceEnum == 0x8576)) ||
                  ((sourceEnum == 0x8577 || (sourceEnum == 0x8578)))) || ((sourceEnum == 0 || (sourceEnum == 1)))) {
                *(short *)(texUnit * 0x7c + glContext + 0x3542) = (short)sourceEnum;
                goto LAB_0001c0e0;
              }
            }
            else if (pname < 0x8582) {
              if ((pname == 0x8580) &&
                 (((((sourceEnum = (int)param, sourceEnum == 0x1702 || (sourceEnum - 0x84c0U < 0x10)) ||
                    ((sourceEnum == 0x8576 || ((sourceEnum == 0x8577 || (sourceEnum == 0x8578)))))) || (sourceEnum == 0)
                   ) || (sourceEnum == 1)))) {
                *(short *)(texUnit * 0x7c + glContext + 0x3540) = (short)sourceEnum;
                goto LAB_0001c0e0;
              }
            }
            else if ((pname == 0x8582) &&
                    (((sourceEnum = (int)param, sourceEnum == 0x1702 || (sourceEnum - 0x84c0U < 0x10)) ||
                     ((sourceEnum == 0x8576 ||
                      ((((sourceEnum == 0x8577 || (sourceEnum == 0x8578)) || (sourceEnum == 0)) || (sourceEnum == 1)))))
                     ))) {
              *(short *)(texUnit * 0x7c + glContext + 0x3544) = (short)sourceEnum;
              goto LAB_0001c0e0;
            }
            goto switchD_0001b7dc_caseD_86da;
          }
          if (pname == 0x8571) {
            combineRgbValue = (code *)(int)param;
            if (combineRgbValue < (code *)0x8576) {
              if ((combineRgbValue < (code *)0x8574) && (combineRgbValue != (code *)0x1e01)) {
                if (combineRgbValue < (code *)0x1e02) {
                  enumAllowed = combineRgbValue == (code *)0x104;
                }
                else {
                  if (combineRgbValue == (code *)0x2100) goto LAB_0001bc1c;
                  enumAllowed = combineRgbValue == (code *)0x84e7;
                }
                if (!enumAllowed) goto switchD_0001b7dc_caseD_86da;
              }
            }
            else if ((combineRgbValue < (code *)0x86ae) ||
                    (((code *)0x86af < combineRgbValue && ((code *)0x2 < combineRgbValue + -0x8744))))
            goto switchD_0001b7dc_caseD_86da;
LAB_0001bc1c:
            *(short *)(texUnit * 0x7c + glContext + 0x353c) = (short)combineRgbValue;
          }
          else {
            if (pname < 0x8572) {
              if (pname == 0xd1c) {
                if (((param != (double)FLOAT_00108e54) && (param != (double)FLOAT_00108ea4))
                   && (param != (double)FLOAT_00108ea8)) goto LAB_0001c0bc;
                *(float *)(texUnit * 0x7c + glContext + 0x355c) = (float)param;
                goto LAB_0001c0e0;
              }
              goto switchD_0001b7dc_caseD_86da;
            }
            combineAlphaValue = (code *)(int)param;
            if (combineAlphaValue != (code *)0x84e7) {
              if (combineAlphaValue < (code *)0x84e8) {
                if (combineAlphaValue != (code *)0x1e01) {
                  if (combineAlphaValue < (code *)0x1e02) {
                    enumAllowed = combineAlphaValue == (code *)0x104;
                  }
                  else {
                    enumAllowed = combineAlphaValue == (code *)0x2100;
                  }
                  if (!enumAllowed) goto switchD_0001b7dc_caseD_86da;
                }
              }
              else if ((combineAlphaValue < (code *)0x8574) ||
                      (((code *)0x8575 < combineAlphaValue && ((code *)0x2 < combineAlphaValue + -0x8744))))
              goto switchD_0001b7dc_caseD_86da;
            }
            *(short *)(texUnit * 0x7c + glContext + 0x353e) = (short)combineAlphaValue;
          }
        }
      }
      else {
        if (pname != 0x8591) {
          if (pname < 0x8592) {
            if (pname == 0x858a) {
              sourceEnum = (int)param;
              if ((((((sourceEnum == 0x1702) || (sourceEnum - 0x84c0U < 0x10)) || (sourceEnum == 0x8576)) ||
                   ((sourceEnum == 0x8577 || (sourceEnum == 0x8578)))) || (sourceEnum == 0)) || (sourceEnum == 1)) {
                *(short *)(texUnit * 0x7c + glContext + 0x354a) = (short)sourceEnum;
                goto LAB_0001c0e0;
              }
            }
            else if (pname < 0x858a) {
              sourceEnum = (int)param;
              if ((((sourceEnum == 0x1702) || (sourceEnum - 0x84c0U < 0x10)) ||
                  ((sourceEnum == 0x8576 || (((sourceEnum == 0x8577 || (sourceEnum == 0x8578)) || (sourceEnum == 0))))))
                 || (sourceEnum == 1)) {
                *(short *)(texUnit * 0x7c + glContext + 0x3548) = (short)sourceEnum;
                goto LAB_0001c0e0;
              }
            }
            else if ((pname == 0x8590) && ((int)param - 0x300U < 4)) {
              *(short *)(texUnit * 0x7c + glContext + 0x354c) = (short)(int)param;
              goto LAB_0001c0e0;
            }
          }
          else if (pname == 0x8598) {
            if ((int)param - 0x302U < 2) {
              *(short *)(texUnit * 0x7c + glContext + 0x3552) = (short)(int)param;
              goto LAB_0001c0e0;
            }
          }
          else if (pname < 0x8599) {
            if ((pname == 0x8592) && ((int)param - 0x300U < 4)) {
              *(short *)(texUnit * 0x7c + glContext + 0x3550) = (short)(int)param;
              goto LAB_0001c0e0;
            }
          }
          else if (pname == 0x8599) {
            if ((int)param - 0x302U < 2) {
              *(short *)(texUnit * 0x7c + glContext + 0x3554) = (short)(int)param;
              goto LAB_0001c0e0;
            }
          }
          else if ((pname == 0x859a) && ((int)param - 0x302U < 2)) {
            *(short *)(texUnit * 0x7c + glContext + 0x3556) = (short)(int)param;
            goto LAB_0001c0e0;
          }
          goto switchD_0001b7dc_caseD_86da;
        }
        if (3 < (int)param - 0x300U) goto switchD_0001b7dc_caseD_86da;
        *(short *)(texUnit * 0x7c + glContext + 0x354e) = (short)(int)param;
      }
LAB_0001c0e0:
      texEnvDirtyWord = *(uint *)(glContext + 800);
      texEnvDirtyBit = 0x1000000;
    }
    *(uint *)(glContext + 800) = texEnvDirtyWord | texEnvDirtyBit << (texUnit & 0x3f);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0001c14c:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _glTexEnvi_Exec @ 0x1c164 (2280 bytes) */
void _glTexEnvi_Exec(glContext, target, pname, param)
  int glContext;
  int target;
  uint pname;
  code *param;
{
  bool paramAllowed;
  undefined4 glErrorCode;
  int texUnitState;
  int dirtyBit;
  uint glContextWord320;
  int shaderOpError;
  undefined2 paramShort;
  uint activeTexUnitThenEnableMask;
  
  activeTexUnitThenEnableMask = *(uint *)(glContext + 0x53d4);
  if (*(short *)(glContext + 0x4a10) < 0) {
    paramShort = SUB42(param,0);
    if (target == 0x86de) {
      texUnitState = glContext + activeTexUnitThenEnableMask * 0x7c;
      switch(pname) {
      case 0x86d9:
        if ((param != (code *)0x8536) && (param != (code *)0x8538))
        goto switchD_0001c1ec_caseD_86da;
        *(undefined2 *)(texUnitState + 0x356c) = paramShort;
        break;
      default:
switchD_0001c1ec_caseD_86da:
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        glErrorCode = 0x500;
        goto LAB_0001ca64;
      case 0x86df:
        shaderOpError = _CheckNVShaderOperation(glContext,param);
        if (shaderOpError != 0) {
          if (*(int *)(glContext + 0x7574) != 0) {
            return;
          }
          *(int *)(glContext + 0x7574) = shaderOpError;
          return;
        }
        *(undefined2 *)(texUnitState + 0x3564) = paramShort;
        _gleUpdateTextureParams(glContext,activeTexUnitThenEnableMask);
        break;
      case 0x86e2:
        *(float *)(texUnitState + 0x3598) =
             (float)((double)CONCAT44(0x43300000,(uint)param ^ 0x80000000) - DOUBLE_00108d58);
        break;
      case 0x86e3:
        *(float *)(texUnitState + 0x359c) =
             (float)((double)CONCAT44(0x43300000,(uint)param ^ 0x80000000) - DOUBLE_00108d58);
        break;
      case 0x86e4:
        if (((int)param < 0x84c0) ||
           ((int)(*(ushort *)(*(int *)(glContext + 0x468c) + 0xb4) + 0x84c0) <= (int)param))
        goto switchD_0001c1ec_caseD_86da;
        *(undefined2 *)(texUnitState + 0x356a) = paramShort;
      }
      glContextWord320 = *(uint *)(glContext + 800);
      dirtyBit = 1;
    }
    else {
      if (target == 0x8861) {
        if (pname == 0x8862) {
          if (param == (code *)0x0) {
            activeTexUnitThenEnableMask = *(uint *)(glContext + 0x3444) &
                    (-2 << (activeTexUnitThenEnableMask & 0x1f) | 0xfffffffeU >> 0x20 - (activeTexUnitThenEnableMask & 0x1f));
          }
          else {
            activeTexUnitThenEnableMask = *(uint *)(glContext + 0x3444) | 1 << (activeTexUnitThenEnableMask & 0x3f);
          }
          *(uint *)(glContext + 0x3444) = activeTexUnitThenEnableMask;
          *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x400000;
          return;
        }
        goto switchD_0001c1ec_caseD_86da;
      }
      if (target != 0x2300) {
        if ((target == 0x8500) && (pname == 0x8501)) {
          *(float *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3560) =
               (float)((double)CONCAT44(0x43300000,(uint)param ^ 0x80000000) - DOUBLE_00108d58);
          *(uint *)(glContext + 800) = *(uint *)(glContext + 800) | 0x10000 << (activeTexUnitThenEnableMask & 0x3f);
          return;
        }
        goto switchD_0001c1ec_caseD_86da;
      }
      if (pname == 0x2200) {
        if (param == (code *)0x1e01) goto LAB_0001c3c8;
        if ((int)param < 0x1e02) {
          if (param == (code *)0x104) goto LAB_0001c3c8;
          if ((int)param < 0x105) {
            paramAllowed = param == (code *)0x0;
          }
          else {
            paramAllowed = param == (code *)0xbe2;
          }
        }
        else {
          if ((int)param < 0x2100) goto switchD_0001c1ec_caseD_86da;
          if ((int)param < 0x2102) goto LAB_0001c3c8;
          paramAllowed = param == (code *)0x8570;
        }
        if (paramAllowed) {
LAB_0001c3c8:
          *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3538) = paramShort;
          *(uint *)(glContext + 800) = *(uint *)(glContext + 800) | 1 << (activeTexUnitThenEnableMask & 0x3f);
          return;
        }
        goto switchD_0001c1ec_caseD_86da;
      }
      if (pname == 0x8588) {
        if (((((param == (code *)0x1702) || (param + -0x84c0 < ((unsigned char *)0x10))) ||
             (param == (code *)0x8576)) ||
            ((param == (code *)0x8577 || (param == (code *)0x8578)))) ||
           ((param == (code *)0x0 || (param == (code *)0x1)))) {
          *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3546) = paramShort;
          goto LAB_0001c9d4;
        }
        goto switchD_0001c1ec_caseD_86da;
      }
      if (pname < 0x8589) {
        if (pname == 0x8573) {
          if ((param + -1 < (code *)0x2) || (param == (code *)0x4)) {
            *(float *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3558) =
                 (float)((double)CONCAT44(0x43300000,(uint)param ^ 0x80000000) - DOUBLE_00108d58);
          }
          else {
LAB_0001c98c:
            if (*(int *)(glContext + 0x7574) == 0) {
              *(undefined4 *)(glContext + 0x7574) = 0x500;
            }
          }
        }
        else {
          if (0x8573 < pname) {
            if (pname == 0x8581) {
              if ((((((param == (code *)0x1702) || (param + -0x84c0 < (code *)0x10)) ||
                    (param == (code *)0x8576)) ||
                   ((param == (code *)0x8577 || (param == (code *)0x8578)))) ||
                  (param == (code *)0x0)) || (param == (code *)0x1)) {
                *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3542) = paramShort;
                goto LAB_0001c9d4;
              }
            }
            else if (pname < 0x8582) {
              if ((pname == 0x8580) &&
                 (((param == (code *)0x1702 || (param + -0x84c0 < (code *)0x10)) ||
                  ((((param == (code *)0x8576 ||
                     ((param == (code *)0x8577 || (param == (code *)0x8578)))) ||
                    (param == (code *)0x0)) || (param == (code *)0x1)))))) {
                *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3540) = paramShort;
                goto LAB_0001c9d4;
              }
            }
            else if ((pname == 0x8582) &&
                    ((((param == (code *)0x1702 || (param + -0x84c0 < (code *)0x10)) ||
                      ((param == (code *)0x8576 ||
                       (((param == (code *)0x8577 || (param == (code *)0x8578)) ||
                        (param == (code *)0x0)))))) || (param == (code *)0x1)))) {
              *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3544) = paramShort;
              goto LAB_0001c9d4;
            }
            goto switchD_0001c1ec_caseD_86da;
          }
          if (pname == 0x8571) {
            if ((int)param < 0x8576) {
              if (((int)param < 0x8574) && (param != (code *)0x1e01)) {
                if ((int)param < 0x1e02) {
                  paramAllowed = param == (code *)0x104;
                }
                else {
                  if (param == (code *)0x2100) goto LAB_0001c594;
                  paramAllowed = param == (code *)0x84e7;
                }
                if (!paramAllowed) goto switchD_0001c1ec_caseD_86da;
              }
            }
            else if (((int)param < 0x86ae) ||
                    ((0x86af < (int)param && ((code *)0x2 < param + -0x8744))))
            goto switchD_0001c1ec_caseD_86da;
LAB_0001c594:
            *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x353c) = paramShort;
          }
          else {
            if (pname < 0x8572) {
              if (pname == 0xd1c) {
                if (((code *)0x1 < param + -1) && (param != (code *)0x4)) goto LAB_0001c98c;
                *(float *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x355c) =
                     (float)((double)CONCAT44(0x43300000,(uint)param ^ 0x80000000) -
                            DOUBLE_00108d58);
                goto LAB_0001c9d4;
              }
              goto switchD_0001c1ec_caseD_86da;
            }
            if (param != (code *)0x84e7) {
              if ((int)param < 0x84e8) {
                if (param != (code *)0x1e01) {
                  if ((int)param < 0x1e02) {
                    paramAllowed = param == (code *)0x104;
                  }
                  else {
                    paramAllowed = param == (code *)0x2100;
                  }
                  if (!paramAllowed) goto switchD_0001c1ec_caseD_86da;
                }
              }
              else if (((int)param < 0x8574) ||
                      ((0x8575 < (int)param && ((code *)0x2 < param + -0x8744))))
              goto switchD_0001c1ec_caseD_86da;
            }
            *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x353e) = paramShort;
          }
        }
      }
      else {
        if (pname != 0x8591) {
          if (pname < 0x8592) {
            if (pname == 0x858a) {
              if ((((param == (code *)0x1702) || (param + -0x84c0 < (code *)0x10)) ||
                  (param == (code *)0x8576)) ||
                 (((param == (code *)0x8577 || (param == (code *)0x8578)) ||
                  ((param == (code *)0x0 || (param == (code *)0x1)))))) {
                *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x354a) = paramShort;
                goto LAB_0001c9d4;
              }
            }
            else if (pname < 0x858a) {
              if ((((param == (code *)0x1702) || (param + -0x84c0 < (code *)0x10)) ||
                  ((param == (code *)0x8576 ||
                   (((param == (code *)0x8577 || (param == (code *)0x8578)) ||
                    (param == (code *)0x0)))))) || (param == (code *)0x1)) {
                *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3548) = paramShort;
                goto LAB_0001c9d4;
              }
            }
            else if ((pname == 0x8590) && (param + -0x300 < (code *)0x4)) {
              *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x354c) = paramShort;
              goto LAB_0001c9d4;
            }
          }
          else if (pname == 0x8598) {
            if (param + -0x302 < (code *)0x2) {
              *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3552) = paramShort;
              goto LAB_0001c9d4;
            }
          }
          else if (pname < 0x8599) {
            if ((pname == 0x8592) && (param + -0x300 < (code *)0x4)) {
              *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3550) = paramShort;
              goto LAB_0001c9d4;
            }
          }
          else if (pname == 0x8599) {
            if (param + -0x302 < (code *)0x2) {
              *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3554) = paramShort;
              goto LAB_0001c9d4;
            }
          }
          else if ((pname == 0x859a) && (param + -0x302 < (code *)0x2)) {
            *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x3556) = paramShort;
            goto LAB_0001c9d4;
          }
          goto switchD_0001c1ec_caseD_86da;
        }
        if ((code *)((int)((unsigned char *)0x0) + 3) < param + -0x300)
        goto switchD_0001c1ec_caseD_86da;
        *(undefined2 *)(activeTexUnitThenEnableMask * 0x7c + glContext + 0x354e) = paramShort;
      }
LAB_0001c9d4:
      glContextWord320 = *(uint *)(glContext + 800);
      dirtyBit = 0x1000000;
    }
    *(uint *)(glContext + 800) = glContextWord320 | dirtyBit << (activeTexUnitThenEnableMask & 0x3f);
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0001ca64:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  }
  return;
}

/* _gleSetEnable_TEXTURE_RECTANGLE_EXT @ 0x1ca7c (80 bytes) */
void _gleSetEnable_TEXTURE_RECTANGLE_EXT(glContext, unusedArg2, param_3)
  int glContext;
  undefined4 unusedArg2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  uint texUnit;
  uint uVar4;
  
  texUnit = *(uint *)(glContext + 0x53d4);
  if (texUnit < 8) {
    iVar2 = texUnit * 0x7c + glContext;
    uVar4 = *(uint *)(iVar2 + 0x3534);
    uVar1 = uVar4 & 0xfffffffb | param_3 << 2;
    if (uVar4 == uVar1) {
      return;
    }
    *(uint *)(iVar2 + 0x3534) = uVar1;
    _gleUpdateTextureParams(glContext,texUnit);
    return;
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(glContext + 0x7574) = 0x502;
  return;
}

/* _glBegin_Exec @ 0x1cacc (704 bytes) */
void _glBegin_Exec(int glContext,uint mode,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
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
    goto LAB_0001cd18;
  }
  if (9 < mode) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x500;
    goto LAB_0001cd18;
  }
  matrixChangeBits = *(int *)(glContext + 0x50ac);
  if (matrixChangeBits != 0 || (*(uint *)(glContext + 0x505c) & *(uint *)(glContext + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(glContext);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(glContext + 0x4691) == '\0') goto LAB_0001cd44;
  framebufferObject = *(int *)(glContext + 0x744c);
  changeWordCursor = (int *)(glContext + 0x310);
  rendererInfoByte79 = *(char *)(*(int *)(glContext + 0x468c) + 0x79);
  if ((framebufferObject != 0) && (*(int *)(framebufferObject + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(glContext,framebufferObject + 0x10,incomingR5,incomingR6,incomingR7,incomingR8,matrixChangeBits,fparam_1,forwardedFloatArg2,forwardedFloatArg3,
               forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
    *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x80000000;
  }
  if ((*(char *)(glContext + 0x4664) == '\0') && (*(int *)(glContext + 0x5430) == 0)) {
LAB_0001cc1c:
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
        _gleUpdateLightRGBASums(glContext,glContext + 0x2c20,0);
      }
      if (*(char *)(glContext + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(glContext,glContext + 0x2e60,1);
      }
      goto LAB_0001cc1c;
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
LAB_0001cd18:
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
LAB_0001cd44:
  *(short *)(glContext + 0x4a10) = (short)mode;
  *(undefined4 *)(glContext + 0x4884) = *(undefined4 *)(glContext + 0x4888);
                    
                    
  (**(code **)(mode * 4 + glContext + 0x49e0))(glContext);
  return;
}

/* _gleUpdateDrawArraysFuncs @ 0x1cd8c (916 bytes) */
void _gleUpdateDrawArraysFuncs(glContext)
  int glContext;
{
  int multiDrawElementArraySlot;
  undefined *handlerPtr;
  uint selectMask;
  uint glContextWord4680;
  uint glContextPtr4684;
  
  if (*(int *)(glContext + 0x5408) != 0) {
    return;
  }
  if ((*(char *)(glContext + 0x759c) == '\0') || (*(char *)(glContext + 0x759d) == '\0')) {
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0xc) =
         PTR__glArrayElement_NoopExec_00112110;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x104) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x104) =
         PTR__glDrawArrays_NoopExec_0011210c;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10c) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x10c) =
         PTR__glDrawElements_NoopExec_00112108;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x654) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x654) =
         PTR__glDrawRangeElements_NoopExec_00112104;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8dc) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x8dc) =
         PTR__glMultiDrawArrays_NoopExec_00112100;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e0) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x8e0) =
         PTR__glMultiDrawElements_NoopExec_001120fc;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b0) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x8b0) =
         PTR__glDrawRangeElementArrayAPPLE_NoopExec_001120f8;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8ac) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x8ac) =
         PTR__glDrawElementArrayAPPLE_NoopExec_001120f4;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa60) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0xa60) =
         PTR__glMultiDrawRangeElementArrayAPPLE_NoopExec_001120f0;
    glContextPtr4684 = *(uint *)(glContext + 0x4684);
    glContextWord4680 = *(uint *)(glContext + 0x4680);
    multiDrawElementArraySlot = *(int *)(glContextPtr4684 + 0xa5c);
    handlerPtr = PTR__glMultiDrawElementArrayAPPLE_NoopExec_001120ec;
  }
  else {
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xc) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0xc) =
         PTR__glArrayElement_Exec_001120e8;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x104) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x104) =
         PTR__glDrawArrays_Exec_001120e4;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x10c) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x10c) =
         PTR__glDrawElements_Exec_001120e0;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x654) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x654) =
         PTR__glDrawRangeElements_Exec_001120dc;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8dc) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x8dc) =
         PTR__glMultiDrawArrays_Exec_001120d8;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8e0) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x8e0) =
         PTR__glMultiDrawElements_Exec_001120d4;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8b0) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x8b0) =
         PTR__glDrawRangeElementArrayAPPLE_Exec_001120d0;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0x8ac) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0x8ac) =
         PTR__glDrawElementArrayAPPLE_Exec_001120cc;
    selectMask = -(uint)(*(int *)(*(uint *)(glContext + 0x4684) + 0xa60) == 0);
    *(undefined **)
     ((*(uint *)(glContext + 0x4680) & selectMask | *(uint *)(glContext + 0x4684) & ~selectMask) + 0xa60) =
         PTR__glMultiDrawRangeElementArrayAPPLE_Exec_001120c8;
    glContextPtr4684 = *(uint *)(glContext + 0x4684);
    glContextWord4680 = *(uint *)(glContext + 0x4680);
    multiDrawElementArraySlot = *(int *)(glContextPtr4684 + 0xa5c);
    handlerPtr = PTR__glMultiDrawElementArrayAPPLE_Exec_001120c4;
  }
  *(undefined **)((glContextWord4680 & -(uint)(multiDrawElementArraySlot == 0) | glContextPtr4684 & ~-(uint)(multiDrawElementArraySlot == 0)) + 0xa5c) = handlerPtr;
  return;
}

/* _gleBeginPrimitiveTCLFunc @ 0x1d120 (168 bytes) */
void _gleBeginPrimitiveTCLFunc(glContext)
  int glContext;
{
  short sVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int local_20 [5];
  
  local_20[0] = *(int *)(glContext + 0x4a14);
  *(undefined1 *)(glContext + 0x4a18) = 0;
  if (local_20[0] == 0) {
    sVar1 = *(short *)(glContext + 0x4880);
  }
  else {
    sVar1 = *(short *)(glContext + 0x4882);
  }
  iVar4 = (**(code **)(glContext + 0x46e8))
                    (*(undefined4 *)(glContext + 0x4688),(int)*(short *)(glContext + 0x4a10),local_20);
  puVar2 = PTR__gleRenderPrimitiveTCLFunc_001113cc;
  *(undefined2 *)(glContext + 0x4a12) = *(undefined2 *)(glContext + 0x4a10);
  puVar3 = PTR__gleFlushPrimitiveTCLFunc_001113d0;
  *(undefined **)(glContext + 0x4a08) = puVar2;
  *(undefined **)(glContext + 0x4a0c) = puVar3;
  *(int *)(glContext + 0x485c) = iVar4 + sVar1 * local_20[0];
  *(short *)(glContext + 0x487c) = sVar1;
  *(int *)(glContext + 0x4868) = iVar4;
  *(int *)(glContext + 0x4858) = iVar4;
  return;
}

/* _glTexCoord2f_Exec @ 0x1d1c8 (28 bytes) */
void _glTexCoord2f_Exec(int glContext,float sCoord,float tCoord)
{
  *(float *)(glContext + 0x120) = (float)sCoord;
  *(undefined4 *)(glContext + 300) = *(undefined4 *)(glContext + 0x24);
  *(float *)(glContext + 0x124) = (float)tCoord;
  *(undefined4 *)(glContext + 0x128) = *(undefined4 *)(glContext + 0x20);
  return;
}

/* _glMultiTexCoord2f_Exec @ 0x1d1e4 (40 bytes) */
void _glMultiTexCoord2f_Exec(int glContext,uint target,float sCoord,float tCoord)
{
  undefined4 glContextWord24;
  undefined4 glContextWord20;
  int unitTexCoord;
  
  glContextWord24 = *(undefined4 *)(glContext + 0x24);
  glContextWord20 = *(undefined4 *)(glContext + 0x20);
  unitTexCoord = glContext + (target & 7) * 0x10;
  *(float *)(unitTexCoord + 0x120) = (float)sCoord;
  *(undefined4 *)(unitTexCoord + 300) = glContextWord24;
  *(float *)(unitTexCoord + 0x124) = (float)tCoord;
  *(undefined4 *)(unitTexCoord + 0x128) = glContextWord20;
  return;
}

/* _glVertex2f_Exec @ 0x1d20c (44 bytes) */
void _glVertex2f_Exec(int glContext,double x,double y)
{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x4884);
  if (*(int *)(glContext + 0x4858) == *(int *)(glContext + 0x485c)) {
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x28);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)
            (glContext,x,y,(double)*(float *)(glContext + 0x20),
             (double)*(float *)(glContext + 0x24));
  return;
}

/* _gleSetVertexSubmitFunc @ 0x1d238 (156 bytes) */
void _gleSetVertexSubmitFunc(int glContext,undefined4 unusedArg2,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,undefined4 unusedArg6,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4)
{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(glContext,0);
  UNRECOVERED_JUMPTABLE = (code *)*puVar1;
  *(code **)(glContext + 0x4888) = UNRECOVERED_JUMPTABLE;
  if (-1 < *(short *)(glContext + 0x4a10)) {
    *(code **)(glContext + 0x4884) = UNRECOVERED_JUMPTABLE;
  }
                    
                    
  (*((int (*)(int,double,double,double,double))UNRECOVERED_JUMPTABLE))(glContext, forwardedFloatArg1, forwardedFloatArg2, forwardedFloatArg3, forwardedFloatArg4);
  return;
}

/* _gleBuildVertexFuncNO @ 0x1d2d4 (2472 bytes) */
int _gleBuildVertexFuncNO(glContext, param_2, param_3, param_4, forwardedArg5, forwardedArg6, param_7, forwardedArg8)
  int glContext;
  int param_2;
  uint *param_3;
  uint param_4;
  undefined4 forwardedArg5;
  undefined4 forwardedArg6;
  uint *param_7;
  undefined4 forwardedArg8;
{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined *puVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *dstCursor;
  uint *srcCursor;
  uint uVar9;
  uint *puVar10;
  uint *instrCursor;
  int iVar12;
  uint uVar13;
  undefined4 uVar14;
  uint *puVar15;
  uint *srcCursor2;
  byte *pbVar16;
  int *piVar17;
  int iVar18;
  ushort *srcCursor3;
  uint *puVar20;
  int *piVar21;
  int *piVar22;
  int iVar23;
  int loopIndex;
  uint uVar24;
  uint uVar25;
  int iVar26;
  int chunkWordCount;
  int glContextWord5434;
  int remaining;
  uint uVar27;
  uint uStack_d0;
  uint auStack_cc [33];
  
  if (param_2 == 3) {
    _gleSetFunctionIDToList(glContext,*(int *)(glContext + 0x4a60) + 0x30,&uStack_d0);
  }
  else {
    if (((*(char *)(glContext + 0x7580) == '\0') || (*(int *)(glContext + 0x4e1c) != 0x1c00)) ||
       (*(byte **)(glContext + 0x48d0) == (byte *)0x0)) {
      if (*(char *)(glContext + 0x4664) == '\0') {
        glContextWord5434 = *(int *)(glContext + 0x5434);
        if (glContextWord5434 == 0) {
          param_3 = &uStack_d0;
          _gleSetFuncOutputDesc(glContext,param_2,param_3);
          goto LAB_0001d42c;
        }
      }
      else {
        glContextWord5434 = *(int *)(glContext + 0x5434);
      }
      if (glContextWord5434 == 0) {
        uVar25 = *(uint *)(*(int *)(glContext + 0x5420) + 0x4cc);
      }
      else {
        param_7 = *(uint **)(*(int *)(glContext + 0x5430) + 0x20);
        uVar25 = param_7[0x142];
      }
      uVar14 = 0;
      if (uVar25 != 0) {
        uVar14 = *(undefined4 *)(uVar25 + 0x20);
        uVar25 = uVar25 + *(int *)(uVar25 + 0x24) * 8;
      }
      param_3 = &uStack_d0;
      param_4 = (uint)(*(int *)(glContext + 0x34d0) != 0x1b021b02);
      _gleVPSetFuncOutputDesc(uVar25,uVar14,param_3,param_4);
    }
    else {
      if (((param_2 != 1) || (*(int *)(glContext + 0x48ec) != 0)) ||
         (pbVar16 = *(byte **)(glContext + 0x48d4), *(byte **)(glContext + 0x48d4) == (byte *)0x0)) {
        pbVar16 = *(byte **)(glContext + 0x48d0);
      }
      remaining = ((int)(*pbVar16 + 1) >> 1) + 1;
      if (remaining != 0) {
        param_7 = &uStack_d0;
        iVar23 = 0;
        do {
          param_7[iVar23] = *(uint *)(pbVar16 + iVar23 * 4);
          remaining = remaining + -1;
          iVar23 = iVar23 + 1;
        } while (remaining != 0);
      }
    }
LAB_0001d42c:
    if (param_2 == 0) {
      ((void (*)())_gleSetFunctionIDFromCurrent)(glContext,&uStack_d0,param_3,param_4,forwardedArg5,forwardedArg6,param_7,forwardedArg8);
    }
    else if (*(int *)(glContext + 0x48ec) == 0) {
      _gleSetFunctionIDFromArray(glContext,*(int *)(glContext + 0x4a60) + 0x30,&uStack_d0);
    }
    else {
      _gleSetFunctionIDFromList(glContext,*(int *)(glContext + 0x48ec),&uStack_d0);
    }
  }
  uVar25 = uStack_d0 >> 0x18;
  switch(param_2) {
  case 0:
    piVar17 = (int *)(glContext + 0x48a0);
    break;
  case 1:
    piVar17 = (int *)(glContext + 0x48a8);
    break;
  case 2:
    piVar17 = (int *)(glContext + 0x48b0);
    break;
  default:
    piVar17 = (int *)(glContext + 0x48b8);
    break;
  case 4:
    piVar17 = (int *)(glContext + 0x48c0);
  }
  piVar21 = (int *)*piVar17;
  remaining = uVar25 + 1;
  piVar22 = piVar21;
  do {
    loopIndex = 0;
    if ((remaining != 0) && (uStack_d0 == piVar22[3])) {
      srcCursor2 = (uint *)(piVar22 + 3);
      srcCursor = &uStack_d0;
      do {
        loopIndex = loopIndex + 1;
        if (remaining <= loopIndex) break;
        srcCursor = srcCursor + 1;
        srcCursor2 = srcCursor2 + 1;
      } while (*srcCursor == *srcCursor2);
    }
    if (loopIndex == remaining) {
      if (piVar22 == piVar21) goto LAB_0001de0c;
      _gleMoveFuncCacheElem(piVar21,piVar22);
      goto LAB_0001de08;
    }
    piVar22 = (int *)*piVar22;
  } while (piVar22 != piVar21);
  iVar23 = ((int (*)())_gleCreateFuncCacheElem)(piVar22,0xf0);
  if (remaining != 0) {
    dstCursor = (uint *)(iVar23 + 0xc);
    srcCursor2 = &uStack_d0;
    do {
      uVar6 = *srcCursor2;
      srcCursor2 = srcCursor2 + 1;
      *dstCursor = uVar6;
      dstCursor = dstCursor + 1;
      remaining = remaining + -1;
    } while (remaining != 0);
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
    srcCursor3 = (ushort *)((int)auStack_cc + uVar25 * 2);
    uVar24 = 0;
    instrCursor = puVar10;
    do {
      uVar2 = *(ushort *)(puVar20 + 1);
      uVar7 = (uint)(uVar2 >> 10);
      uVar13 = uVar24;
      if (uVar7 == 6) {
        puVar10 = instrCursor;
        if ((uVar9 & 0x40) == 0) {
          if ((*srcCursor3 >> 10 & 0xf) == 0xe) {
            uVar7 = 0x892302ec;
LAB_0001d970:
            *instrCursor = uVar7;
            uVar13 = uVar24;
          }
          else {
            uVar13 = *srcCursor3 & 0x3ff;
            if ((uVar6 == 0) && (param_2 != 2)) {
              instrCursor = (uint *)_gleSetArrayLoadAddressNO(instrCursor,puVar15,0x4910,uVar13);
              uVar7 = 0x89270000;
              goto LAB_0001d970;
            }
            *instrCursor = uVar13 - uVar24 & 0xffff | 0x38e70000;
            instrCursor = instrCursor + 1;
            *instrCursor = 0x81270000;
          }
          uVar2 = *(ushort *)(puVar20 + 1);
          instrCursor = instrCursor + 1;
          uVar3 = uVar2 >> 6 & 3;
          if (uVar3 == 1) {
            uVar24 = (uVar2 & 0x3f) << 2 | 0x99250000;
LAB_0001d9b8:
            *instrCursor = uVar24;
            uVar24 = uVar13;
LAB_0001dcc8:
            instrCursor = instrCursor + 1;
            uVar13 = uVar24;
            puVar10 = instrCursor;
          }
          else {
            puVar10 = instrCursor;
            if (uVar3 < 2) {
              if (uVar3 == 0) {
                chunkWordCount = _gleRTCAddAChunk_b50a8(&_gleSetEdgeBitRTC,instrCursor);
                instrCursor = instrCursor + chunkWordCount;
                puVar10 = instrCursor;
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
          uVar3 = *srcCursor3;
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
              instrCursor = (uint *)((int (*)())_gleLoadDataElementFromCtxNO)(instrCursor,iVar26,uVar27,iVar12);
            }
          }
          else {
            uVar27 = uVar3 & 0x3ff;
            if ((uVar6 != 0) || (param_2 == 2)) {
              uVar14 = 0;
              *instrCursor = uVar27 - uVar24 & 0xffff | 0x38e70000;
              instrCursor = instrCursor + 1;
              uVar24 = uVar27;
            }
            else {
              instrCursor = (uint *)_gleSetArrayLoadAddressNO(instrCursor,puVar15,uVar7 * 4 + 0x48f8,uVar27)
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
            instrCursor = (uint *)_gleLoadDataElementNO(instrCursor,iVar26,uVar13,uVar27,uVar14);
          }
          uVar2 = *(ushort *)(puVar20 + 1);
          uVar7 = uStack_d0;
        }
        else {
          if (0x29 < uVar7) {
            if (uVar7 < 0x2c) {
              if ((uStack_d0 >> 0x10 & 0xf) == 6) {
                *instrCursor = 0x39200001;
                instrCursor[1] = (uVar7 - 0x1f) * 0x10000 | 0x912001e0;
                instrCursor = instrCursor + 2;
                uVar2 = *(ushort *)(puVar20 + 1);
              }
              *instrCursor = (uVar7 - 0x1f) * 0x200000 | (uVar2 & 0x3f) << 2 | 0x90050000;
              puVar10 = instrCursor + 1;
              goto LAB_0001dcd0;
            }
            *instrCursor = 0x812302ec;
            instrCursor = instrCursor + 1;
            *instrCursor = (*(ushort *)(puVar20 + 1) & 0x3f) << 2 | 0x91250000;
            goto LAB_0001dcc8;
          }
          uVar14 = 0;
          iVar18 = (uVar2 >> 8 & 3) + 1;
          iVar26 = (*srcCursor3 >> 0xe) + 1;
          if ((((0x21 < uVar7) && (uVar14 = 0x10, 0x23 < uVar7)) && (uVar14 = 0x20, 0x25 < uVar7))
             && (uVar14 = 0x30, 0x27 < uVar7)) {
            uVar14 = 0x40;
          }
          uVar27 = uStack_d0 >> 0x13 & 4;
          instrCursor = (uint *)_gleLoadDataElementFromMatNO(instrCursor,iVar26,uVar27,uVar14,uVar7 & 1);
          uVar2 = *(ushort *)(puVar20 + 1);
          uVar7 = uStack_d0 >> 0x15 & 1;
          uVar13 = 6;
        }
        puVar10 = (uint *)((int (*)())_gleStoreDataElementNO)(instrCursor,(uVar2 & 0x3f) << 2,iVar26,uVar13,uVar27,iVar18,uVar7);
        uVar13 = uVar24;
      }
LAB_0001dcd0:
      uVar25 = uVar25 - 1;
      puVar20 = (uint *)((int)puVar20 + 2);
      srcCursor3 = srcCursor3 + 1;
      uVar24 = uVar13;
      puVar15 = instrCursor;
      instrCursor = puVar10;
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
void _gleSetFunctionIDFromCurrent(glContext, param_2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  int glContext;
  uint *param_2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  ushort uVar1;
  int glContextPtr4674;
  uint *puVar3;
  ushort *dstCursor;
  uint uVar5;
  
  glContextPtr4674 = *(int *)(glContext + 0x4674);
  uVar5 = *param_2 >> 0x18;
  *param_2 = *param_2 | 0x60000;
  if (uVar5 == 0) {
    return;
  }
  puVar3 = param_2 + 1;
  dstCursor = (ushort *)((int)param_2 + uVar5 * 2 + 4);
  do {
    uVar1 = *(ushort *)puVar3;
    puVar3 = (uint *)((int)puVar3 + 2);
    *dstCursor = (*(byte *)(glContextPtr4674 + 0x400 + (uint)(uVar1 >> 10)) - 1) * 0x4000 | 0x3800;
    dstCursor = dstCursor + 1;
    uVar5 = uVar5 - 1;
  } while (uVar5 != 0);
  return;
}

/* _gleCreateFuncCacheElem @ 0x1de88 (156 bytes) */
int _gleCreateFuncCacheElem(funcCache, slotCount)
  int funcCache;
  int slotCount;
{
  int *newElem;
  int *resultElem;
  undefined4 *oldTail;
  
  newElem = (int *)_gleDCBAlloc(slotCount * 4 + 0x20);
  resultElem = (int *)0x0;
  if (newElem != (int *)0x0) {
    _gleBlockClear(newElem + 8,slotCount);
    oldTail = *(undefined4 **)(funcCache + 4);
    *oldTail = newElem;
    newElem[1] = (int)oldTail;
    newElem[slotCount + 7] = 0;
    newElem[5] = -1;
    *(int **)(funcCache + 4) = newElem;
    newElem[2] = -1;
    newElem[3] = -1;
    newElem[4] = -1;
    *newElem = funcCache;
    resultElem = newElem;
  }
  return resultElem;
}

/* _gleCalculateOptions @ 0x1df24 (468 bytes) */
int _gleCalculateOptions(functionId, attributeCount)
  uint *functionId;
  int attributeCount;
{
  uint attributeIndex;
  bool typeAndSizeMatch;
  uint typeCode;
  ushort uVar4;
  uint options;
  ushort *srcCursor;
  uint *selectorWordCursor;
  ushort selectorComponentCount;
  int loopIndex;
  int attribute6ByteOffset;
  int highAttributeByteOffset;
  int remaining;
  
  options = 0;
  highAttributeByteOffset = 0;
  attribute6ByteOffset = -1;
  loopIndex = 0;
  if (0 < attributeCount) {
    srcCursor = (ushort *)((int)functionId + attributeCount * 2 + 4);
    selectorWordCursor = functionId + 1;
    remaining = attributeCount;
    do {
      uVar4 = *(ushort *)selectorWordCursor;
      attributeIndex = (uint)(uVar4 >> 10);
      if (attributeIndex == 6) {
        if (((*srcCursor >> 10 & 0xf) == 0xe) && ((uVar4 >> 6 & 3) == 1)) {
          attribute6ByteOffset = (uVar4 & 0x3f) << 2;
        }
      }
      else if (attributeIndex < 0x2a) {
        typeAndSizeMatch = false;
        if (attributeIndex < 0x20) {
          typeCode = *(ushort *)((int)functionId + (attributeCount + loopIndex) * 2 + 4) >> 10 & 0xf;
          if ((typeCode < 6) || (typeCode - 8 < 6)) {
            uVar4 = uVar4 >> 6 & 3;
            if ((((typeCode < 2) || ((typeCode == 8 || (typeCode == 9)))) && (uVar4 == 1)) ||
               ((((typeCode - 2 < 2 || (typeCode == 10)) || (typeCode == 0xb)) && (uVar4 == 2)))) {
              typeAndSizeMatch = true;
            }
            else {
              options = options | 4;
            }
          }
        }
        else {
          options = options | 1 << (attributeIndex & 1);
        }
        selectorComponentCount = (*(ushort *)selectorWordCursor >> 8 & 3) + 1;
        uVar4 = (*(ushort *)((int)functionId + (attributeCount + loopIndex) * 2 + 4) >> 0xe) + 1;
        if ((uVar4 < selectorComponentCount) && (!typeAndSizeMatch)) {
          if ((attributeIndex == 5) || (selectorComponentCount != 4)) {
            options = options | 8;
          }
          else if (uVar4 == 3) {
            options = options | 0x10;
          }
          else if ((*functionId & 0x200000) == 0) {
            options = options | 0x18;
          }
          else if (uVar4 == 2) {
            options = options | 0x20;
          }
          else {
            options = options | 0x28;
          }
        }
      }
      else if (attributeIndex < 0x2c) {
        options = options | 1 << (attributeIndex - 0x2a & 0x3f);
      }
      else {
        highAttributeByteOffset = (uVar4 & 0x3f) << 2;
      }
      loopIndex = loopIndex + 1;
      srcCursor = srcCursor + 1;
      selectorWordCursor = (uint *)((int)selectorWordCursor + 2);
      remaining = remaining + -1;
    } while (remaining != 0);
  }
  if (attribute6ByteOffset == highAttributeByteOffset) {
    options = options | 0x40;
  }
  return options;
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
int _gleStoreDataElementNO(instrCursor, destOffset, srcComponentCount, elementType, elementSizeSelector, destComponentCount, formatFlags)
  uint *instrCursor;
  uint destOffset;
  int srcComponentCount;
  uint elementType;
  int elementSizeSelector;
  int destComponentCount;
  uint formatFlags;
{
  bool caseMatched;
  uint secondWord;
  uint *cursor;
  uint defaultFourthComponent;
  uint firstWord;
  uint nextDisplacement;
  
  if (elementSizeSelector == 1) {
    if ((srcComponentCount < 4) && (destComponentCount == 4)) {
      defaultFourthComponent = 0x7f;
      if ((elementType != 8) && ((elementType < 9 || (defaultFourthComponent = 0xff, elementType != 9)))) {
        defaultFourthComponent = 1;
      }
    }
    else {
      defaultFourthComponent = 0;
    }
    if ((formatFlags >> 0x14 & 1) == 0) {
      if (srcComponentCount == 2) {
        if (destComponentCount == 3) {
          nextDisplacement = destOffset + 2;
          secondWord = destOffset & 0xffff | 0xb0050000;
          *instrCursor = 0x39400000;
          goto LAB_0001e570;
        }
        if (destComponentCount < 4) {
          if (destComponentCount != 2) {
            return instrCursor;
          }
switchD_0001e87c_caseD_1:
          goto LAB_0001e284;
        }
        if (destComponentCount == 4) {
          secondWord = 0x5400801e;
          goto LAB_0001e59c;
        }
        if (destComponentCount != 5) {
          return instrCursor;
        }
switchD_0001e87c_caseD_2:
        defaultFourthComponent = 0x5400801e;
LAB_0001e588:
        secondWord = destOffset & 0xffff | 0x90050000;
        goto LAB_0001e304;
      }
      if (srcComponentCount < 3) {
        if (srcComponentCount != 1) {
          return instrCursor;
        }
        switch(destComponentCount) {
        default:
          goto switchD_0001e254_caseD_0;
        case 1:
          goto LAB_0001e4c8;
        case 2:
          defaultFourthComponent = 0x5400402e;
          secondWord = destOffset & 0xffff | 0xb0050000;
          goto LAB_0001e304;
        case 3:
          *instrCursor = 0x5400402e;
          secondWord = destOffset + 2 & 0xffff | 0x98050000;
          instrCursor = instrCursor + 1;
          *instrCursor = destOffset & 0xffff | 0xb0050000;
          break;
        case 4:
          secondWord = 0x5400c00e;
LAB_0001e59c:
          *instrCursor = secondWord;
          secondWord = destOffset & 0xffff | 0x90050000;
          instrCursor = instrCursor + 1;
          *instrCursor = defaultFourthComponent | 0x60000000;
          break;
        case 5:
          defaultFourthComponent = 0x5400c00e;
          goto LAB_0001e588;
        }
        goto LAB_0001e308;
      }
      if (srcComponentCount != 3) {
        caseMatched = srcComponentCount == 4;
LAB_0001e8f0:
        if (!caseMatched) {
          return instrCursor;
        }
        goto switchD_0001e254_caseD_5;
      }
      if (destComponentCount == 4) {
        *instrCursor = 0x5400801e;
        instrCursor[1] = 0x554a402e;
        instrCursor[2] = 0x7c005378;
        cursor = instrCursor + 3;
        *cursor = defaultFourthComponent | 0x60000000;
      }
      else {
        if (destComponentCount < 5) {
          if (destComponentCount != 3) {
            return instrCursor;
          }
          defaultFourthComponent = destOffset & 0xffff | 0xb0050000;
          secondWord = destOffset + 2 & 0xffff | 0x99450000;
          goto LAB_0001e304;
        }
        if (destComponentCount != 5) {
          return instrCursor;
        }
        *instrCursor = 0x5400801e;
        instrCursor[1] = 0x554a402e;
        cursor = instrCursor + 2;
        *cursor = 0x7c005378;
      }
      firstWord = destOffset & 0xffff | 0x90050000;
LAB_0001ebe0:
      instrCursor = cursor + 1;
      *instrCursor = firstWord;
    }
    else {
      if (srcComponentCount == 2) {
        if (destComponentCount == 3) {
          nextDisplacement = destOffset + 1;
          *instrCursor = destOffset + 2 & 0xffff | 0x39400000;
          instrCursor = instrCursor + 1;
          *instrCursor = 0x7c05572c;
          secondWord = destOffset & 0xffff | 0x39400000;
LAB_0001e570:
          instrCursor = instrCursor + 1;
          *instrCursor = secondWord;
          secondWord = nextDisplacement & 0xffff | 0x99450000;
          goto LAB_0001e308;
        }
        if (3 < destComponentCount) {
          if (destComponentCount != 4) {
            if (destComponentCount != 5) {
              return instrCursor;
            }
            firstWord = destOffset & 0xffff | 0x39400000;
            *instrCursor = 0x5400801e;
            secondWord = 0x7c05552c;
            goto LAB_0001e35c;
          }
          *instrCursor = 0x5400801e;
          instrCursor[1] = destOffset & 0xffff | 0x39400000;
          cursor = instrCursor + 2;
          *cursor = defaultFourthComponent | 0x60000000;
          goto LAB_0001e448;
        }
        if (destComponentCount != 2) {
          return instrCursor;
        }
        secondWord = 0x7c05572c;
        defaultFourthComponent = destOffset + 2 & 0xffff | 0x39400000;
      }
      else {
        if (srcComponentCount < 3) {
          if (srcComponentCount != 1) {
            return instrCursor;
          }
          switch(destComponentCount) {
          default:
            goto switchD_0001e254_caseD_0;
          case 1:
            destOffset = destOffset + 3;
LAB_0001e4c8:
            firstWord = destOffset & 0xffff | 0x98050000;
            break;
          case 2:
switchD_0001e254_caseD_2:
            destOffset = destOffset + 2;
LAB_0001e284:
            firstWord = destOffset & 0xffff | 0xb0050000;
            break;
          case 3:
            firstWord = destOffset + 2 & 0xffff | 0xb0050000;
            *instrCursor = 0x39400000;
            secondWord = destOffset + 1 & 0xffff | 0x99450000;
LAB_0001e35c:
            instrCursor[1] = firstWord;
            instrCursor = instrCursor + 2;
            *instrCursor = secondWord;
            goto LAB_0001ebe4;
          case 4:
            defaultFourthComponent = defaultFourthComponent << 8 | 0x64000000;
            goto LAB_0001e588;
          case 5:
switchD_0001e254_caseD_5:
            firstWord = destOffset & 0xffff | 0x90050000;
          }
          goto LAB_0001e288;
        }
        if (srcComponentCount == 3) {
          if (destComponentCount == 4) {
            *instrCursor = 0x5400801e;
            instrCursor[1] = 0x554a402e;
            instrCursor[2] = 0x7c005378;
            defaultFourthComponent = defaultFourthComponent | 0x60000000;
            cursor = instrCursor + 3;
            *cursor = destOffset & 0xffff | 0x39400000;
          }
          else {
            if (destComponentCount < 5) {
              if (destComponentCount != 3) {
                return instrCursor;
              }
              firstWord = destOffset + 2 & 0xffff | 0x39400000;
              *instrCursor = destOffset + 1 & 0xffff | 0x99450000;
              secondWord = 0x7c05572c;
              goto LAB_0001e35c;
            }
            if (destComponentCount != 5) {
              return instrCursor;
            }
            *instrCursor = 0x5400801e;
            instrCursor[1] = 0x554a402e;
            defaultFourthComponent = destOffset & 0xffff | 0x39400000;
            cursor = instrCursor + 2;
            *cursor = 0x7c005378;
          }
          cursor = cursor + 1;
          *cursor = defaultFourthComponent;
LAB_0001e448:
          firstWord = 0x7c05552c;
          goto LAB_0001ebe0;
        }
        if (srcComponentCount != 4) {
          return instrCursor;
        }
        defaultFourthComponent = destOffset & 0xffff | 0x39400000;
        secondWord = 0x7c05552c;
      }
LAB_0001e304:
      *instrCursor = defaultFourthComponent;
LAB_0001e308:
      instrCursor = instrCursor + 1;
      *instrCursor = secondWord;
    }
  }
  else {
    if (elementSizeSelector == 2) {
      if ((srcComponentCount < 4) && (destComponentCount == 4)) {
        defaultFourthComponent = 0x7fff;
        if ((elementType != 10) && ((elementType < 0xb || (defaultFourthComponent = 0xffff, elementType != 0xb)))) {
          defaultFourthComponent = 1;
        }
      }
      else {
        defaultFourthComponent = 0;
      }
      if ((formatFlags >> 0x14 & 1) == 0) {
        if (srcComponentCount != 2) {
          if (2 < srcComponentCount) {
            if (srcComponentCount == 3) {
              if (destComponentCount == 4) {
                secondWord = 0x554a0000;
                defaultFourthComponent = defaultFourthComponent | 0x614a0000;
                goto LAB_0001e9d8;
              }
              if (4 < destComponentCount) {
                if (destComponentCount != 5) {
                  return instrCursor;
                }
                secondWord = destOffset + 4 & 0xffff;
                defaultFourthComponent = 0x554a801e;
                goto LAB_0001e9bc;
              }
              if (destComponentCount != 3) {
                return instrCursor;
              }
              defaultFourthComponent = destOffset & 0xffff | 0x90050000;
              secondWord = destOffset + 4 & 0xffff | 0xb1450000;
            }
            else {
              if (srcComponentCount != 4) {
                return instrCursor;
              }
              defaultFourthComponent = destOffset & 0xffff | 0x90050000;
              secondWord = destOffset + 4 & 0xffff | 0x91450000;
            }
            goto LAB_0001e304;
          }
          if (srcComponentCount != 1) {
            return instrCursor;
          }
          switch(destComponentCount) {
          default:
            goto switchD_0001e254_caseD_0;
          case 1:
            goto switchD_0001e87c_caseD_1;
          case 2:
            goto switchD_0001e87c_caseD_2;
          case 3:
            secondWord = 0x5400801e;
            nextDisplacement = destOffset + 4;
            goto LAB_0001e8b0;
          case 4:
            secondWord = 0x54000000;
            defaultFourthComponent = defaultFourthComponent | 0x39400000;
            break;
          case 5:
            firstWord = 0x5400801e;
LAB_0001e780:
            *instrCursor = firstWord;
            instrCursor = instrCursor + 1;
            *instrCursor = 0x39400000;
LAB_0001e79c:
            secondWord = destOffset + 4 & 0xffff;
            instrCursor = instrCursor + 1;
            *instrCursor = destOffset & 0xffff | 0x90050000;
            goto LAB_0001e9c8;
          }
LAB_0001e9d8:
          secondWord = secondWord | 0x801e;
LAB_0001e9dc:
          *instrCursor = secondWord;
          instrCursor[1] = defaultFourthComponent;
          cursor = instrCursor + 2;
          *cursor = destOffset & 0xffff | 0x90050000;
          firstWord = destOffset + 4 & 0xffff | 0x91450000;
          goto LAB_0001ebe0;
        }
        if (destComponentCount != 3) {
          if (destComponentCount < 4) {
            caseMatched = destComponentCount == 2;
            goto LAB_0001e8f0;
          }
          if (destComponentCount != 4) {
            if (destComponentCount != 5) {
              return instrCursor;
            }
            goto switchD_0001e6ec_caseD_5;
          }
          secondWord = destOffset + 4 & 0xffff;
          defaultFourthComponent = defaultFourthComponent | 0x39400000;
          goto LAB_0001e9bc;
        }
        nextDisplacement = destOffset + 4;
LAB_0001e920:
        *instrCursor = 0x39400000;
LAB_0001e930:
        instrCursor = instrCursor + 1;
        *instrCursor = destOffset & 0xffff | 0x90050000;
      }
      else {
        if (srcComponentCount == 2) {
          if (destComponentCount == 3) {
            secondWord = 0x5400803e;
            nextDisplacement = destOffset + 6;
LAB_0001e8b0:
            *instrCursor = secondWord;
            instrCursor = instrCursor + 1;
            *instrCursor = 0x39400000;
            goto LAB_0001e930;
          }
          if (destComponentCount < 4) {
            if (destComponentCount != 2) {
              return instrCursor;
            }
            defaultFourthComponent = 0x5400803e;
            goto LAB_0001e588;
          }
          if (destComponentCount != 4) {
            if (destComponentCount != 5) {
              return instrCursor;
            }
            firstWord = 0x5400803e;
            goto LAB_0001e780;
          }
          defaultFourthComponent = defaultFourthComponent | 0x3d400000;
LAB_0001e818:
          secondWord = 0x5400803e;
          goto LAB_0001e9dc;
        }
        if (srcComponentCount < 3) {
          if (srcComponentCount != 1) {
            return instrCursor;
          }
          switch(destComponentCount) {
          default:
            goto switchD_0001e254_caseD_0;
          case 1:
            goto switchD_0001e254_caseD_2;
          case 2:
            goto switchD_0001e254_caseD_5;
          case 3:
            nextDisplacement = destOffset + 6;
            goto LAB_0001e920;
          case 4:
            secondWord = destOffset + 4 & 0xffff;
            defaultFourthComponent = defaultFourthComponent | 0x3d400000;
            break;
          case 5:
switchD_0001e6ec_caseD_5:
            *instrCursor = 0x39400000;
            goto LAB_0001e79c;
          }
LAB_0001e9bc:
          *instrCursor = defaultFourthComponent;
          instrCursor = instrCursor + 1;
          *instrCursor = destOffset & 0xffff | 0x90050000;
LAB_0001e9c8:
          secondWord = secondWord | 0x91450000;
          goto LAB_0001e308;
        }
        if (srcComponentCount != 3) {
          if (srcComponentCount != 4) {
            return instrCursor;
          }
          secondWord = 0x5400803e;
          defaultFourthComponent = 0x554a803e;
          goto LAB_0001e9dc;
        }
        if (destComponentCount == 4) {
          defaultFourthComponent = defaultFourthComponent | 0x654a0000;
          goto LAB_0001e818;
        }
        if (4 < destComponentCount) {
          if (destComponentCount != 5) {
            return instrCursor;
          }
          secondWord = destOffset + 4 & 0xffff;
          defaultFourthComponent = 0x5400803e;
          goto LAB_0001e9bc;
        }
        if (destComponentCount != 3) {
          return instrCursor;
        }
        nextDisplacement = destOffset + 6;
        *instrCursor = 0x5400803e;
        instrCursor = instrCursor + 1;
        *instrCursor = destOffset & 0xffff | 0x90050000;
      }
      secondWord = nextDisplacement & 0xffff | 0xb1450000;
      goto LAB_0001e308;
    }
    if (srcComponentCount == 2) {
      if (elementSizeSelector == 4) {
        *instrCursor = destOffset & 0xffff | 0xd8250000;
      }
      else {
        *instrCursor = destOffset & 0xffff | 0xd0250000;
        instrCursor = instrCursor + 1;
        *instrCursor = destOffset + 4 & 0xffff | 0xd0450000;
      }
LAB_0001eaac:
      instrCursor = instrCursor + 1;
      if ((formatFlags >> 0x15 & 1) == 0) {
        if (destComponentCount < 3) {
          return instrCursor;
        }
        firstWord = destOffset + 8 & 0xffff | 0xd0e50000;
        goto LAB_0001eb54;
      }
      firstWord = destOffset + 8;
      if (destComponentCount != 3) {
        if (destComponentCount == 4) {
          firstWord = destOffset + 8 & 0xffff | 0xd9250000;
        }
        else {
          if (destComponentCount != 5) {
            return instrCursor;
          }
          firstWord = destOffset + 8 & 0xffff | 0xd8e50000;
        }
        goto LAB_0001e288;
      }
    }
    else {
      if (srcComponentCount < 3) {
        if (srcComponentCount != 1) {
          return instrCursor;
        }
        *instrCursor = destOffset & 0xffff | 0xd0250000;
        instrCursor = instrCursor + 1;
        if (destComponentCount < 2) {
          return instrCursor;
        }
        *instrCursor = destOffset + 4 & 0xffff | 0xd0e50000;
        goto LAB_0001eaac;
      }
      if (srcComponentCount != 3) {
        if (srcComponentCount != 4) {
          return instrCursor;
        }
        if (elementSizeSelector == 4) {
          defaultFourthComponent = destOffset & 0xffff | 0xd8250000;
          secondWord = destOffset + 8 & 0xffff | 0xd8650000;
          goto LAB_0001e304;
        }
        *instrCursor = destOffset & 0xffff | 0xd0250000;
        instrCursor[1] = destOffset + 4 & 0xffff | 0xd0450000;
        cursor = instrCursor + 2;
        *cursor = destOffset + 8 & 0xffff | 0xd0650000;
        firstWord = destOffset + 0xc & 0xffff | 0xd0850000;
        goto LAB_0001ebe0;
      }
      if (elementSizeSelector == 4) {
        *instrCursor = destOffset & 0xffff | 0xd8250000;
      }
      else {
        *instrCursor = destOffset & 0xffff | 0xd0250000;
        instrCursor = instrCursor + 1;
        *instrCursor = destOffset + 4 & 0xffff | 0xd0450000;
      }
      instrCursor = instrCursor + 1;
      firstWord = destOffset + 8 & 0xffff | 0xd0650000;
LAB_0001eb54:
      *instrCursor = firstWord;
      instrCursor = instrCursor + 1;
      if (destComponentCount == 4) {
        firstWord = destOffset + 0xc & 0xffff | 0xd1050000;
        goto LAB_0001e288;
      }
      if (destComponentCount != 5) {
        return instrCursor;
      }
      firstWord = destOffset + 0xc;
    }
    firstWord = firstWord & 0xffff | 0xd0e50000;
LAB_0001e288:
    *instrCursor = firstWord;
  }
LAB_0001ebe4:
  instrCursor = instrCursor + 1;
switchD_0001e254_caseD_0:
  return instrCursor;
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

