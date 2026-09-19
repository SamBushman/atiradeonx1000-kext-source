#include "decls.h"

/* FUN_00089a20 @ 0x89a20 (144 bytes) */
int FUN_00089a20(param_1)
  int *param_1;
{
  int iVar1;
  
  if (((param_1[5] == 0xf) && (iVar1 = param_1[6], -1 < iVar1)) &&
     (iVar1 < *(int *)(((unsigned char *)0x000011fc) + *param_1))) {
    FUN_00088920();
  }
  else {
    iVar1 = 0;
    FUN_00088e70(param_1,"invalid program local parameter number");
  }
  return iVar1;
}

/* FUN_00089ac0 @ 0x89ac0 (144 bytes) */
int FUN_00089ac0(param_1)
  int *param_1;
{
  int iVar1;
  
  if (((param_1[5] == 0xf) && (iVar1 = param_1[6], -1 < iVar1)) &&
     (iVar1 < *(int *)(((unsigned char *)0x00001200) + *param_1))) {
    FUN_00088920();
  }
  else {
    iVar1 = 0;
    FUN_00088e70(param_1,"invalid program environment parameter number");
  }
  return iVar1;
}

/* FUN_00089b60 @ 0x89b60 (168 bytes) */
int FUN_00089b60(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = 0;
  if (param_1[5] == 0x15) {
    FUN_00088920();
    if (((param_1[5] != 0xf) || (iVar1 = param_1[6], iVar1 < 0)) ||
       ((int)(uint)(byte)((unsigned char *)0x000013b0)[*param_1] <= iVar1)) {
      FUN_00088e70(param_1,"invalid texture coordinate");
      iVar1 = param_1[6];
    }
    FUN_00088920(param_1);
    FUN_00089160(param_1,0x16);
  }
  return iVar1;
}

/* FUN_00089c10 @ 0x89c10 (128 bytes) */
int FUN_00089c10(param_1)
  int param_1;
{
  uint uVar1;
  
  if (((*(int *)(param_1 + 0x14) == 0xf) && (uVar1 = *(uint *)(param_1 + 0x18), -1 < (int)uVar1)) &&
     (uVar1 < 4)) {
    FUN_00088920();
  }
  else {
    uVar1 = 0;
    FUN_00088e70(param_1,"invalid matrix row number");
  }
  return uVar1;
}

/* FUN_00089ca0 @ 0x89ca0 (144 bytes) */
int FUN_00089ca0(param_1)
  int *param_1;
{
  int iVar1;
  
  if (((param_1[5] == 0xf) && (iVar1 = param_1[6], -1 < iVar1)) &&
     (iVar1 < (int)(uint)(byte)((unsigned char *)0x000013b5)[*param_1])) {
    FUN_00088920();
  }
  else {
    iVar1 = 0;
    FUN_00088e70(param_1,"invalid light number");
  }
  return iVar1;
}

/* FUN_0008aa40 @ 0x8aa40 (3780 bytes) */
int FUN_0008aa40(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  double dVar12;
  float local_28;
  float local_24;
  float local_20;
  
  if (0x1a < (uint)param_1[5]) {
LAB_0008aaa0:
    pcVar9 = "invalid parameter binding";
    goto LAB_0008ab20;
  }
  uVar2 = 1 << (param_1[5] & 0x3fU);
  if ((uVar2 & 0x818000) == 0) {
    if ((uVar2 & 1) != 0) {
      if (param_1[6] == 0x1d) {
        FUN_00088920();
        FUN_00089160(param_1,0x11);
        puVar3 = (undefined4 *)FUN_00089280(param_1,param_2);
        *puVar3 = 2;
        if (param_1[5] == 0) {
          if (param_1[6] == 9) {
            puVar3[2] = 0x32;
            FUN_00088920(param_1);
            FUN_00089160(param_1,0x15);
            iVar6 = ((int (*)())FUN_00089ac0)(param_1);
            iVar7 = iVar6;
            if ((param_3 == 0) || (param_1[5] != 0x12)) {
LAB_0008abb4:
              FUN_00089160(param_1,0x16);
              puVar3[3] = iVar6;
              while (iVar6 = iVar6 + 1, iVar6 <= iVar7) {
                puVar8 = (undefined4 *)FUN_00089280(param_1,param_2);
                uVar4 = puVar3[1];
                uVar10 = puVar3[2];
                uVar11 = puVar3[3];
                *puVar8 = *puVar3;
                puVar8[1] = uVar4;
                puVar8[3] = uVar11;
                puVar8[2] = uVar10;
                uVar4 = puVar3[4];
                puVar8[3] = iVar6;
                puVar8[4] = uVar4;
                puVar3 = puVar8;
              }
              return;
            }
            FUN_00088920(param_1);
            iVar7 = ((int (*)())FUN_00089ac0)(param_1);
            if (iVar6 <= iVar7) goto LAB_0008abb4;
          }
          else {
            if (param_1[6] != 0x14) goto LAB_0008ab0c;
            puVar3[2] = 0x33;
            FUN_00088920(param_1);
            FUN_00089160(param_1,0x15);
            iVar6 = ((int (*)())FUN_00089a20)(param_1);
            iVar7 = iVar6;
            if ((param_3 == 0) || (param_1[5] != 0x12)) goto LAB_0008abb4;
            FUN_00088920(param_1);
            iVar7 = ((int (*)())FUN_00089a20)(param_1);
            if (iVar6 <= iVar7) goto LAB_0008abb4;
          }
          pcVar9 = "invalid program parameter range";
        }
        else {
LAB_0008ab0c:
          pcVar9 = "invalid program parameter type";
        }
LAB_0008ab20:
        FUN_00088e70(param_1,pcVar9);
        return;
      }
      if (param_1[6] != 0x27) {
        pcVar9 = "invalid parameter binding";
        goto LAB_0008ab20;
      }
      FUN_00088920();
      FUN_00089160(param_1,0x11);
      if (param_1[5] != 0) {
        FUN_00088e70(param_1,"invalid state binding");
      }
      puVar3 = (undefined4 *)FUN_00089280(param_1,param_2);
      *puVar3 = 2;
      switch(param_1[6]) {
      case 5:
        if (param_1[5] != 0) {
LAB_0008a570:
          FUN_00089140(param_1);
          return;
        }
        FUN_00088920(param_1);
        FUN_00089160(param_1,0x11);
        if ((param_1[5] == 0) && (param_1[6] == 0x1f)) {
          FUN_00088920(param_1);
          puVar3[2] = 0x18;
          return;
        }
        pcVar9 = "invalid depth property";
        break;
      default:
        pcVar9 = "invalid state binding";
        break;
      case 10:
        if (param_1[5] != 0) goto LAB_0008a570;
        FUN_00088920(param_1);
        FUN_00089160(param_1,0x11);
        if (param_1[5] == 0) {
          if (param_1[6] == 4) {
            FUN_00088920(param_1);
            puVar3[2] = 0x16;
            return;
          }
          if (param_1[6] == 0x1a) {
            FUN_00088920(param_1);
            puVar3[2] = 0x17;
            return;
          }
        }
        pcVar9 = "invalid fog property";
        break;
      case 0x11:
        if (param_1[5] != 0) goto LAB_0008a570;
        FUN_00088920(param_1);
        FUN_00089160(param_1,0x15);
        uVar4 = ((int (*)())FUN_00089ca0)(param_1);
        puVar3[3] = uVar4;
        FUN_00089160(param_1,0x16);
        FUN_00089160(param_1,0x11);
        if (param_1[5] == 0) {
          switch(param_1[6]) {
          default:
            goto switchD_0008a094_caseD_0;
          case 1:
            uVar4 = 10;
            break;
          case 2:
            uVar4 = 0xe;
            break;
          case 6:
            uVar4 = 0xb;
            break;
          case 0xe:
            uVar4 = 0x10;
            break;
          case 0x1b:
            uVar4 = 0xd;
            break;
          case 0x25:
            uVar4 = 0xc;
            break;
          case 0x26:
            FUN_00088920(param_1);
            FUN_00089160(param_1,0x11);
            if ((param_1[5] != 0) || (param_1[6] != 7)) {
              pcVar9 = "invalid spot light property";
              goto LAB_0008a9fc;
            }
            uVar4 = 0xf;
          }
LAB_00089fc4:
          puVar3[2] = uVar4;
          FUN_00088920(param_1);
          return;
        }
switchD_0008a094_caseD_0:
        pcVar9 = "invalid light property";
        break;
      case 0x12:
        if (param_1[5] != 0) {
          FUN_00089140(param_1);
        }
        FUN_00088920(param_1);
        FUN_00089160(param_1,0x11);
        if (param_1[5] == 0) {
          puVar3[3] = 0;
          iVar6 = param_1[6];
          if (iVar6 == 3) {
            puVar3[3] = 1;
            FUN_00088920(param_1);
            FUN_00089160(param_1,0x11);
          }
          else if (iVar6 == 0xd) {
            FUN_00088920(param_1);
            FUN_00089160(param_1,0x11);
          }
          else if (iVar6 == 1) {
            uVar4 = 0x11;
            goto LAB_00089fc4;
          }
          if ((param_1[5] == 0) && (param_1[6] == 0x22)) {
            uVar4 = 0x12;
            goto LAB_00089fc4;
          }
        }
        pcVar9 = "invalid light model property";
        break;
      case 0x13:
        if (param_1[5] != 0) goto LAB_0008a570;
        FUN_00088920(param_1);
        FUN_00089160(param_1,0x15);
        uVar4 = ((int (*)())FUN_00089ca0)(param_1);
        puVar3[3] = uVar4;
        FUN_00089160(param_1,0x16);
        FUN_00089160(param_1,0x11);
        puVar3[4] = 0;
        if (param_1[5] == 0) {
          if (param_1[6] == 3) {
            puVar3[4] = 1;
LAB_0008a31c:
            FUN_00088920(param_1);
            FUN_00089160(param_1,0x11);
            if (param_1[5] != 0) goto LAB_0008a38c;
          }
          else if (param_1[6] == 0xd) goto LAB_0008a31c;
          iVar6 = param_1[6];
          if (iVar6 == 6) {
            uVar4 = 0x14;
            goto LAB_00089fc4;
          }
          if (iVar6 == 0x25) {
            uVar4 = 0x15;
            goto LAB_00089fc4;
          }
          if (iVar6 == 1) {
            uVar4 = 0x13;
            goto LAB_00089fc4;
          }
        }
LAB_0008a38c:
        pcVar9 = "invalid light product property";
        break;
      case 0x15:
        if (param_1[5] != 0) goto LAB_0008a570;
        FUN_00088920(param_1);
        FUN_00089160(param_1,0x11);
        puVar3[3] = 0;
        if (param_1[5] == 0) {
          if (param_1[6] == 3) {
            puVar3[3] = 1;
LAB_00089ec0:
            FUN_00088920(param_1);
            FUN_00089160(param_1,0x11);
            if (param_1[5] != 0) goto switchD_00089f14_caseD_0;
          }
          else if (param_1[6] == 0xd) goto LAB_00089ec0;
          switch(param_1[6]) {
          default:
            goto switchD_00089f14_caseD_0;
          case 1:
            uVar4 = 5;
            break;
          case 6:
            uVar4 = 6;
            break;
          case 8:
            uVar4 = 8;
            break;
          case 0x24:
            uVar4 = 9;
            break;
          case 0x25:
            uVar4 = 7;
          }
          goto LAB_00089fc4;
        }
switchD_00089f14_caseD_0:
        pcVar9 = "invalid material property";
        break;
      case 0x16:
        if (param_1[5] != 0) goto LAB_0008a570;
        FUN_00088920(param_1);
        FUN_00089160(param_1,0x11);
        if (param_1[5] != 0) {
          FUN_00088e70(param_1,"invalid matrix property");
        }
        switch(param_1[6]) {
        case 0x17:
          iVar6 = 0;
          FUN_00088920(param_1);
          puVar3[2] = 0x1a;
          if (param_1[5] == 0x15) {
            FUN_00088920(param_1);
            if (((param_1[5] == 0xf) && (iVar6 = param_1[6], -1 < iVar6)) &&
               (iVar6 < (int)(uint)(byte)((unsigned char *)0x000013b4)[*param_1])) {
              FUN_00088920(param_1);
            }
            else {
              iVar6 = 0;
              FUN_00088e70(param_1,"invalid modelview matrix number");
            }
            FUN_00089160(param_1,0x16);
          }
          puVar3[3] = iVar6;
          break;
        case 0x18:
          FUN_00088920(param_1);
          puVar3[2] = 0x22;
          break;
        case 0x19:
          FUN_00088920(param_1);
          puVar3[2] = 0x2a;
          FUN_00089160(param_1,0x15);
          FUN_00088e70(param_1,"invalid palette matrix number");
          puVar3[3] = 0;
          FUN_00089160(param_1,0x16);
          break;
        default:
          FUN_00088e70(param_1,"invalid matrix property");
          break;
        case 0x1d:
          FUN_00088920(param_1);
          puVar3[2] = 0x2e;
          FUN_00089160(param_1,0x15);
          if (((param_1[5] == 0xf) && (iVar6 = param_1[6], -1 < iVar6)) &&
             (iVar6 < *(int *)(((unsigned char *)0x0000149c) + *param_1))) {
            FUN_00088920(param_1);
          }
          else {
            iVar6 = 0;
            FUN_00088e70(param_1,"invalid program matrix number");
          }
          puVar3[3] = iVar6;
          FUN_00089160(param_1,0x16);
          break;
        case 0x1e:
          FUN_00088920(param_1);
          puVar3[2] = 0x1e;
          break;
        case 0x2a:
          FUN_00088920(param_1);
          puVar3[2] = 0x26;
          uVar4 = ((int (*)())FUN_00089b60)(param_1);
          puVar3[3] = uVar4;
        }
        if (param_1[5] == 0x11) {
          FUN_00088920(param_1);
          if (param_1[5] != 0) {
            pcVar9 = "invalid matrix modifier";
            break;
          }
          iVar6 = param_1[6];
          if (iVar6 == 0x10) {
            FUN_00088920(param_1);
            bVar1 = param_1[5] != 0x11;
            if (!bVar1) {
              FUN_00088920(param_1);
            }
            puVar3[4] = 3;
LAB_0008a838:
            if (bVar1) goto LAB_0008a960;
          }
          else {
            if (iVar6 == 0x2b) {
              FUN_00088920(param_1);
              bVar1 = param_1[5] != 0x11;
              if (!bVar1) {
                FUN_00088920(param_1);
              }
              puVar3[4] = 2;
              goto LAB_0008a838;
            }
            if (iVar6 == 0xf) {
              FUN_00088920(param_1);
              bVar1 = param_1[5] != 0x11;
              if (!bVar1) {
                FUN_00088920(param_1);
              }
              puVar3[4] = 1;
              goto LAB_0008a838;
            }
            puVar3[4] = 0;
          }
          if ((param_1[5] == 0) && (param_1[6] == 0x21)) {
            FUN_00088920(param_1);
            FUN_00089160(param_1,0x15);
            iVar5 = ((int (*)())FUN_00089c10)(param_1);
            iVar7 = iVar5;
            if ((param_3 != 0) && (param_1[5] == 0x12)) {
              FUN_00088920(param_1);
              iVar7 = ((int (*)())FUN_00089c10)(param_1);
              if (iVar7 < iVar5) {
                pcVar9 = "invalid matrix row range";
                break;
              }
            }
            iVar6 = iVar5 + 1;
            FUN_00089160(param_1,0x16);
LAB_0008a984:
            puVar3[2] = iVar5 + puVar3[2];
            for (; iVar6 <= iVar7; iVar6 = iVar6 + 1) {
              puVar8 = (undefined4 *)FUN_00089280(param_1,param_2);
              iVar5 = puVar3[2];
              uVar4 = *puVar3;
              uVar10 = puVar3[1];
              uVar11 = puVar3[3];
              puVar8[2] = iVar5;
              *puVar8 = uVar4;
              puVar8[1] = uVar10;
              puVar8[3] = uVar11;
              uVar4 = puVar3[4];
              puVar8[2] = iVar5 + 1;
              puVar8[4] = uVar4;
              puVar3 = puVar8;
            }
            return;
          }
          pcVar9 = "invalid matrix row selector";
        }
        else {
LAB_0008a960:
          if (param_3 != 0) {
            iVar7 = 3;
            iVar5 = 0;
            iVar6 = 1;
            goto LAB_0008a984;
          }
          pcVar9 = "missing matrix row selector";
        }
        break;
      case 0x29:
        if (param_1[5] != 0) goto LAB_0008a570;
        iVar6 = 0;
        FUN_00088920(param_1);
        if (param_1[5] == 0x15) {
          FUN_00088920(param_1);
          if (((param_1[5] != 0xf) || (iVar6 = param_1[6], iVar6 < 0)) ||
             ((int)(uint)(byte)((unsigned char *)0x000013b2)[*param_1] <= iVar6)) {
            FUN_00088e70(param_1,"invalid legacy texture unit");
            iVar6 = param_1[6];
          }
          FUN_00088920(param_1);
          FUN_00089160(param_1,0x16);
        }
        puVar3[3] = iVar6;
        FUN_00089160(param_1,0x11);
        if ((param_1[5] == 0) && (param_1[6] == 4)) {
          uVar4 = 0x19;
          goto LAB_00089fc4;
        }
        pcVar9 = "invalid texenv property";
      }
LAB_0008a9fc:
      FUN_00088e70(param_1,pcVar9);
      return;
    }
    if ((uVar2 & 0x6000000) == 0) goto LAB_0008aaa0;
    if (param_4 == 0) {
      pcVar9 = "consecutive sign operators";
      goto LAB_0008ab20;
    }
  }
  puVar3 = (undefined4 *)FUN_00089280();
  puVar3[2] = 0x34;
  *puVar3 = 2;
  if (0x1a < (uint)param_1[5]) {
LAB_000898c0:
    FUN_00088e70(param_1,"invalid constant");
    return;
  }
  uVar2 = 1 << (param_1[5] & 0x3fU);
  if ((uVar2 & 0x6018000) != 0) {
    dVar12 = (double)((double (*)())FUN_000897b0)(param_1);
    local_28 = (float)dVar12;
    local_24 = local_28;
    local_20 = local_28;
    uVar4 = FUN_00089320(param_1,&local_28);
    puVar3[3] = uVar4;
    return;
  }
  if ((uVar2 & 0x800000) == 0) goto LAB_000898c0;
  FUN_00088920(param_1);
  local_20 = 0.0;
  local_24 = 0.0;
  dVar12 = (double)((double (*)())FUN_000897b0)(param_1);
  local_28 = (float)dVar12;
  if (param_1[5] == 0x13) {
    FUN_00088920(param_1);
    dVar12 = (double)((double (*)())FUN_000897b0)(param_1);
    local_24 = (float)dVar12;
    if (param_1[5] == 0x13) {
      FUN_00088920(param_1);
      dVar12 = (double)((double (*)())FUN_000897b0)(param_1);
      local_20 = (float)dVar12;
      if (param_1[5] == 0x13) {
        FUN_00088920(param_1);
        ((double (*)())FUN_000897b0)(param_1);
        goto LAB_000899e0;
      }
    }
  }
  if ((param_1[10] < 0) && (param_1[0xb] == -1)) {
    param_1[0xb] = param_1[9];
    param_1[0xc] = (int)
                   "warning: <paramConstVector> rule match where parser is supplying some default component(s)"
    ;
  }
LAB_000899e0:
  FUN_00089160(param_1,0x18);
  uVar4 = FUN_00089320(param_1,&local_28);
  puVar3[3] = uVar4;
  return;
}

/* FUN_0008ace0 @ 0x8ace0 (464 bytes) */
int FUN_0008ace0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  if ((*(int *)(param_1 + 0x14) == 0) && (*(int *)(param_1 + 0x18) == 0xc)) {
    *(undefined4 *)(param_2 + 0x18) = 1;
    FUN_00088920();
    FUN_00089160(param_1,0x11);
    if (*(int *)(param_1 + 0x14) != 0) {
      FUN_00088e70(param_1,"invalid fragment attribute binding item");
    }
    uVar1 = *(uint *)(param_1 + 0x18);
    if (uVar1 == 0xb) {
      FUN_00088920(param_1);
      *(undefined4 *)(param_2 + 0x20) = 3;
      return;
    }
    if (uVar1 < 0xc) {
      if (uVar1 == 4) {
        FUN_00088920(param_1);
        *(undefined4 *)(param_2 + 0x20) = 1;
        uVar2 = 0;
        if (*(int *)(param_1 + 0x14) == 0x11) {
          FUN_00088920(param_1);
          if (*(int *)(param_1 + 0x14) == 0) {
            if (*(int *)(param_1 + 0x18) == 0x1c) {
              FUN_00088920(param_1);
              uVar2 = 0;
            }
            else if (*(int *)(param_1 + 0x18) == 0x23) {
              FUN_00088920(param_1);
              uVar2 = 1;
            }
            else {
              *(int *)(param_1 + 0xc) = *(int *)(param_1 + 8) + -1;
              FUN_00088920(param_1);
              uVar2 = 0;
            }
          }
          else {
            FUN_00088e70(param_1,"invalid color type");
            uVar2 = 0;
          }
        }
        *(undefined4 *)(param_2 + 0x24) = uVar2;
        return;
      }
    }
    else {
      if (uVar1 == 0x1b) {
        FUN_00088920(param_1);
        *(undefined4 *)(param_2 + 0x20) = 4;
        return;
      }
      if (uVar1 == 0x28) {
        FUN_00088920(param_1);
        *(undefined4 *)(param_2 + 0x20) = 2;
        uVar2 = ((int (*)())FUN_00089b60)(param_1);
        *(undefined4 *)(param_2 + 0x24) = uVar2;
        return;
      }
    }
    pcVar3 = "invalid fragment attribute binding item";
  }
  else {
    pcVar3 = "invalid fragment attribute binding";
  }
  FUN_00088e70(param_1,pcVar3);
  return;
}

/* FUN_0008aec0 @ 0x8aec0 (136 bytes) */
int FUN_0008aec0(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 0x14) == 0) &&
     (*(int *)(param_1 + 0xc) - (int)*(undefined1 **)(param_1 + 8) == 1)) {
    uVar1 = FUN_00089190(param_1,**(undefined1 **)(param_1 + 8));
    FUN_00088920(param_1);
  }
  else {
    uVar1 = 0;
    FUN_00088e70(param_1,"invalid component");
  }
  return uVar1;
}

/* FUN_0008b160 @ 0x8b160 (864 bytes) */
int FUN_0008b160(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x14);
  if (uVar4 < 0x11) {
    if (0xe < uVar4) goto LAB_0008b1f0;
    if (uVar4 != 0) goto LAB_0008b1a0;
    iVar1 = *(int *)(param_1 + 0x18);
    if ((iVar1 == 0x1d) || (iVar1 == 0x27)) goto LAB_0008b1f0;
    if (iVar1 == 0xc) {
      iVar1 = FUN_00088f00();
      if (iVar1 == 0) {
        return;
      }
LAB_0008b270:
      *param_2 = iVar1;
      if (*(int *)(param_1 + 0x14) != 0) {
        FUN_00089140();
        return;
      }
      if (*(int *)(param_1 + 0x18) == 0xc) {
        ((int (*)())FUN_0008ace0)();
      }
      else {
        FUN_00088920(param_1,iVar1);
      }
      param_2[6] = 0;
      return;
    }
    iVar1 = FUN_00088fd0();
    if (iVar1 == 0) {
      pcVar3 = "undefined variable";
      goto LAB_0008b220;
    }
    iVar2 = *(int *)(iVar1 + 0x18);
    if (iVar2 == 1) goto LAB_0008b270;
    if (iVar2 == 0) {
      param_2[6] = 0;
      *param_2 = iVar1;
      FUN_00088920(param_1);
      return;
    }
    if (iVar2 != 2) {
      if (iVar2 != 3) {
        FUN_00089140(param_1);
        return;
      }
      pcVar3 = "invalid source register type";
      goto LAB_0008b220;
    }
  }
  else {
    if (uVar4 != 0x17) {
LAB_0008b1a0:
      pcVar3 = "invalid source register";
LAB_0008b220:
      FUN_00088e70(param_1,pcVar3);
      return;
    }
LAB_0008b1f0:
    iVar1 = FUN_00088f00(param_1);
    if (iVar1 == 0) {
      return;
    }
  }
  *param_2 = iVar1;
  uVar4 = *(uint *)(param_1 + 0x14);
  if (uVar4 < 0x11) {
    if (uVar4 < 0xf) {
      if (uVar4 == 0) {
        if ((*(int *)(param_1 + 0x18) != 0x1d) && (*(int *)(param_1 + 0x18) != 0x27)) {
          if (*(int *)(iVar1 + 0xc) == 0) {
            FUN_00088920();
            param_2[6] = 0;
            return;
          }
          FUN_00088920();
          FUN_00089160(param_1,0x15);
          if (*(int *)(param_1 + 0x14) == 0xf) {
            iVar2 = *(int *)(param_1 + 0x18);
            param_2[6] = iVar2;
            if (iVar2 <= *(int *)(iVar1 + 0xc)) {
              FUN_00088920(param_1);
              FUN_00089160(param_1,0x16);
              return;
            }
            pcVar3 = "invalid array index";
          }
          else {
            pcVar3 = "invalid array addressing";
          }
          FUN_00088e70(param_1,pcVar3);
          return;
        }
        ((int (*)())FUN_0008aa40)(param_1,iVar1,0,0);
        param_2[6] = 0;
        return;
      }
LAB_0008afa0:
      FUN_00089140(param_1);
      return;
    }
  }
  else if (uVar4 != 0x17) goto LAB_0008afa0;
  ((int (*)())FUN_0008aa40)(param_1,iVar1,0,0);
  param_2[6] = 0;
  return;
}

/* FUN_0008b300 @ 0x8b300 (396 bytes) */
int FUN_0008b300(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar3 = FUN_00089740();
  if (*(int *)(param_1 + 0x14) == 0) {
    bVar4 = **(char **)(param_1 + 8) + 0x9f;
    if (bVar4 < 0x1a) {
      iVar5 = 1;
      uVar1 = 1 << ((int)(char)bVar4 & 0x3fU);
      if (((uVar1 & 0x20043) == 0) && (iVar5 = 0, (uVar1 & 0x3c00000) == 0)) goto LAB_0008b3d0;
    }
    else {
LAB_0008b3d0:
      iVar5 = -1;
    }
    uVar6 = ((int (*)())FUN_0008aec0)(param_1);
    iVar2 = *param_2;
    if (*param_2 == -1) {
      *param_2 = iVar5;
      iVar2 = iVar5;
    }
    if (iVar5 == iVar2) goto LAB_0008b41c;
  }
  else if (*(int *)(param_1 + 0x14) == 0xf) {
    if (*(int *)(param_1 + 0x18) == 0) {
      uVar6 = 4;
      FUN_00088920(param_1);
      goto LAB_0008b41c;
    }
    if (*(int *)(param_1 + 0x18) == 1) {
      uVar6 = 5;
      FUN_00088920(param_1);
      goto LAB_0008b41c;
    }
  }
  uVar6 = 0;
  FUN_00088e70(param_1,"invalid extended swizzle selector");
LAB_0008b41c:
  if (iVar3 == -1) {
    switch(uVar6) {
    case 0:
      uVar6 = 6;
      break;
    case 1:
      uVar6 = 7;
      break;
    case 2:
      uVar6 = 8;
      break;
    case 3:
      uVar6 = 9;
      break;
    case 4:
      uVar6 = 4;
      break;
    case 5:
      uVar6 = 10;
      break;
    default:
      FUN_00089140(param_1);
    }
  }
  return uVar6;
}

/* FUN_0008b4b0 @ 0x8b4b0 (496 bytes) */
int FUN_0008b4b0(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  char cVar5;
  uint uVar6;
  undefined1 *puVar7;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    if (*(int *)(param_1 + 0x18) == 0x20) {
      iVar2 = FUN_00088f00();
      if (iVar2 != 0) {
        FUN_000895b0(param_1,iVar2 + 0x18);
      }
    }
    else {
      iVar2 = FUN_00088fd0();
      if (iVar2 == 0) {
        FUN_00088e70(param_1,"undefined variable");
      }
      else {
        uVar6 = *(uint *)(iVar2 + 0x18);
        if (uVar6 < 3) {
          if (uVar6 == 0) {
LAB_0008b558:
            FUN_00088920(param_1);
          }
          else {
            iVar2 = 0;
            FUN_00088e70(param_1,"invalid destination register type");
          }
        }
        else {
          if (uVar6 == 3) goto LAB_0008b558;
          iVar2 = 0;
          FUN_00089140(param_1);
        }
      }
    }
  }
  else {
    iVar2 = 0;
    FUN_00088e70(param_1,"invalid destination register");
  }
  *param_2 = iVar2;
  uVar6 = 0xf;
  if (*(int *)(param_1 + 0x14) == 0x11) {
    FUN_00088920(param_1);
    if (*(int *)(param_1 + 0x14) == 0) {
      puVar7 = *(undefined1 **)(param_1 + 8);
      if ((int)*(undefined1 **)(param_1 + 0xc) - (int)puVar7 < 5) {
        uVar6 = 0;
        if (puVar7 < *(undefined1 **)(param_1 + 0xc)) {
          cVar4 = '\x02';
          do {
            uVar3 = FUN_00089190(param_1,*puVar7);
            uVar3 = 1 << (uVar3 & 0x3f);
            cVar5 = 3 < (byte)(**(char **)(param_1 + 8) + 0x89U);
            if ((cVar4 == '\x02') || (bVar1 = cVar4 == cVar5, cVar5 = cVar4, bVar1)) {
              if (uVar6 < uVar3) {
                uVar6 = uVar6 | uVar3;
              }
              else {
                FUN_00088e70(param_1,"invalid writemask order");
              }
            }
            else {
              FUN_00088e70(param_1,"invalid writemask components");
            }
            puVar7 = puVar7 + 1;
            cVar4 = cVar5;
          } while (puVar7 < *(undefined1 **)(param_1 + 0xc));
        }
        FUN_00088920(param_1);
        goto LAB_0008b6a0;
      }
    }
    uVar6 = 0xf;
    FUN_00088e70(param_1,"invalid writemask");
  }
LAB_0008b6a0:
  param_2[1] = uVar6;
  return;
}

/* FUN_0008b6d0 @ 0x8b6d0 (624 bytes) */
int FUN_0008b6d0(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  
  iVar2 = FUN_00089740();
  if (iVar2 == -1) {
    *(undefined1 *)(param_2 + 0x14) = 1;
  }
  else {
    *(undefined1 *)(param_2 + 0x14) = 0;
  }
  ((int (*)())FUN_0008b160)(param_1,param_2);
  if (*(int *)(param_1 + 0x14) != 0x11) {
    *(undefined4 *)(param_2 + 4) = 0;
    *(undefined4 *)(param_2 + 0x10) = 3;
    *(undefined4 *)(param_2 + 8) = 1;
    *(undefined4 *)(param_2 + 0xc) = 2;
    return;
  }
  FUN_00088920(param_1);
  if (*(int *)(param_1 + 0x14) == 0) {
    iVar2 = *(int *)(param_1 + 0xc) - (int)*(undefined1 **)(param_1 + 8);
    if ((iVar2 == 1) || (iVar2 == 4)) {
      uVar3 = FUN_00089190(param_1,**(undefined1 **)(param_1 + 8));
      *(undefined4 *)(param_2 + 4) = uVar3;
      if (*(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) < 2) {
        *(undefined4 *)(param_2 + 0x10) = uVar3;
        *(undefined4 *)(param_2 + 8) = uVar3;
        *(undefined4 *)(param_2 + 0xc) = uVar3;
      }
      else {
        uVar3 = FUN_00089190(param_1,*(undefined1 *)(*(int *)(param_1 + 8) + 1));
        *(undefined4 *)(param_2 + 8) = uVar3;
        uVar3 = FUN_00089190(param_1,*(undefined1 *)(*(int *)(param_1 + 8) + 2));
        *(undefined4 *)(param_2 + 0xc) = uVar3;
        uVar3 = FUN_00089190(param_1,*(undefined1 *)(*(int *)(param_1 + 8) + 3));
        *(undefined4 *)(param_2 + 0x10) = uVar3;
        pcVar4 = *(char **)(param_1 + 8);
        if ((byte)(*pcVar4 + 0x89U) < 4) {
          cVar1 = pcVar4[1];
          if (((((cVar1 != 'r') && (cVar1 != 'g')) && (cVar1 != 'b')) &&
              (((cVar1 != 'a' && (cVar1 = pcVar4[2], cVar1 != 'r')) &&
               (((cVar1 != 'g' && ((cVar1 != 'b' && (cVar1 != 'a')))) &&
                (cVar1 = pcVar4[3], cVar1 != 'r')))))) &&
             (((cVar1 != 'g' && (cVar1 != 'b')) && (cVar1 != 'a')))) goto LAB_0008b93c;
        }
        else if (((((3 < (byte)(pcVar4[1] + 0x89U)) && (cVar1 = pcVar4[2], cVar1 != 'x')) &&
                  (cVar1 != 'y')) &&
                 (((cVar1 != 'z' && (cVar1 != 'w')) &&
                  ((cVar1 = pcVar4[3], cVar1 != 'x' && ((cVar1 != 'y' && (cVar1 != 'z')))))))) &&
                (cVar1 != 'w')) goto LAB_0008b93c;
        FUN_00088e70(param_1,"invalid swizzle suffix");
      }
LAB_0008b93c:
      FUN_00088920(param_1);
      return;
    }
  }
  FUN_00088e70(param_1,"invalid swizzle suffix");
  return;
}

/* FUN_0008b960 @ 0x8b960 (132 bytes) */
int FUN_0008b960(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00089740();
  if (iVar1 == -1) {
    *(undefined1 *)(param_2 + 0x14) = 1;
  }
  else {
    *(undefined1 *)(param_2 + 0x14) = 0;
  }
  ((int (*)())FUN_0008b160)(param_1,param_2);
  FUN_00089160(param_1,0x11);
  uVar2 = ((int (*)())FUN_0008aec0)(param_1);
  *(undefined4 *)(param_2 + 0x10) = uVar2;
  *(undefined4 *)(param_2 + 4) = uVar2;
  *(undefined4 *)(param_2 + 8) = uVar2;
  *(undefined4 *)(param_2 + 0xc) = uVar2;
  return;
}

/* FUN_0008b9f0 @ 0x8b9f0 (2664 bytes) */
int FUN_0008b9f0(param_1)
  int *param_1;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_38 [7];
  
  pcVar4 = (char *)param_1[3];
  cVar1 = *pcVar4;
  pcVar5 = pcVar4 + 1;
  param_1[3] = (int)pcVar5;
  if (cVar1 == '!') {
    cVar1 = pcVar4[1];
    pcVar5 = pcVar4 + 2;
    param_1[3] = (int)pcVar5;
    if (cVar1 == '!') {
      cVar1 = pcVar4[2];
      pcVar5 = pcVar4 + 3;
      param_1[3] = (int)pcVar5;
      if (cVar1 == 'A') {
        cVar1 = pcVar4[3];
        pcVar5 = pcVar4 + 4;
        param_1[3] = (int)pcVar5;
        if (cVar1 == 'R') {
          cVar1 = pcVar4[4];
          pcVar5 = pcVar4 + 5;
          param_1[3] = (int)pcVar5;
          if (cVar1 == 'B') {
            cVar1 = pcVar4[5];
            pcVar5 = pcVar4 + 6;
            param_1[3] = (int)pcVar5;
            if (cVar1 == 'f') {
              cVar1 = pcVar4[6];
              pcVar5 = pcVar4 + 7;
              param_1[3] = (int)pcVar5;
              if (cVar1 == 'p') {
                cVar1 = pcVar4[7];
                pcVar5 = pcVar4 + 8;
                param_1[3] = (int)pcVar5;
                if (cVar1 == '1') {
                  cVar1 = pcVar4[8];
                  pcVar5 = pcVar4 + 9;
                  param_1[3] = (int)pcVar5;
                  if (cVar1 == '.') {
                    cVar1 = pcVar4[9];
                    pcVar5 = pcVar4 + 10;
                    param_1[3] = (int)pcVar5;
                    if (cVar1 == '0') {
                      FUN_00088920();
                      uVar7 = param_1[5];
                      while (uVar7 == 8) {
                        FUN_00088920(param_1);
                        if (param_1[5] == 1) {
                          *(undefined1 *)((int)param_1 + param_1[6] + 0x34) = 1;
                          FUN_00088920(param_1);
                        }
                        else {
                          FUN_00088e70(param_1,"invalid option name");
                        }
                        FUN_00089160(param_1,0x14);
                        uVar7 = param_1[5];
                      }
LAB_0008bbb0:
                      if ((uVar7 == 6) || (uVar7 == 0x1c)) {
                        FUN_00089160(param_1,6);
                        FUN_00089160(param_1,0x1c);
                        return (uint)param_1[10] >> 0x1f;
                      }
                      if (uVar7 < 0xe) {
                        uVar2 = 1 << (uVar7 & 0x3f);
                        if ((uVar2 & 0x3618) != 0) {
                          if (param_1[0x9014] < *(int *)(((unsigned char *)0x00001204) + *param_1)) {
                            piVar6 = param_1 + (param_1[0x9014] + param_1[0x9015]) * 0x18 + 0x14;
                            switch(uVar7) {
                            case 3:
                              *piVar6 = param_1[6];
                              FUN_00088920(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              FUN_00089160(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 3);
                              FUN_00089160(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 10);
                              piVar6[0x11] = 0;
                              break;
                            case 4:
                              *piVar6 = param_1[6];
                              FUN_00088920(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              FUN_00089160(param_1,0x13);
                              ((int (*)())FUN_0008b960)(param_1,piVar6 + 3);
                              FUN_00089160(param_1,0x13);
                              ((int (*)())FUN_0008b960)(param_1,piVar6 + 10);
                              piVar6[0x11] = 0;
                              break;
                            default:
                              FUN_00089140(param_1);
                              break;
                            case 9:
                              *piVar6 = param_1[6];
                              FUN_00088920(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              FUN_00089160(param_1,0x13);
                              ((int (*)())FUN_0008b960)(param_1,piVar6 + 3);
                              piVar6[0x11] = 0;
                              piVar6[10] = 0;
                              break;
                            case 10:
                              *piVar6 = param_1[6];
                              FUN_00088920(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              FUN_00089160(param_1,0x13);
                              ((int (*)())FUN_0008b160)(param_1,piVar6 + 3);
                              FUN_00089160(param_1,0x13);
                              local_38[0] = 0xffffffff;
                              iVar3 = ((int (*)())FUN_0008b300)(param_1,local_38);
                              piVar6[4] = iVar3;
                              FUN_00089160(param_1,0x13);
                              iVar3 = ((int (*)())FUN_0008b300)(param_1,local_38);
                              piVar6[5] = iVar3;
                              FUN_00089160(param_1,0x13);
                              iVar3 = ((int (*)())FUN_0008b300)(param_1,local_38);
                              piVar6[6] = iVar3;
                              FUN_00089160(param_1,0x13);
                              iVar3 = ((int (*)())FUN_0008b300)(param_1,local_38);
                              piVar6[7] = iVar3;
                              piVar6[0x11] = 0;
                              *(undefined1 *)(piVar6 + 8) = 0;
                              piVar6[10] = 0;
                              break;
                            case 0xc:
                              *piVar6 = param_1[6];
                              FUN_00088920(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              FUN_00089160(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 3);
                              FUN_00089160(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 10);
                              FUN_00089160(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 0x11);
                              break;
                            case 0xd:
                              *piVar6 = param_1[6];
                              FUN_00088920(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,piVar6 + 1);
                              FUN_00089160(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,piVar6 + 3);
                              piVar6[0x11] = 0;
                              piVar6[10] = 0;
                            }
                            param_1[0x9014] = param_1[0x9014] + 1;
                            goto LAB_0008bba0;
                          }
                          FUN_00088e70(param_1,"too many ALU instructions");
                          uVar7 = param_1[5];
                          goto LAB_0008bbb0;
                        }
                        if ((uVar2 & 0x24) == 0) {
                          if ((uVar2 & 0x880) == 0) goto LAB_0008bb90;
                          if (param_1[0x9015] < *(int *)(((unsigned char *)0x00001208) + *param_1)) {
                            iVar3 = param_1[0x9015] + param_1[0x9014];
                            if (uVar7 == 7) {
                              param_1[iVar3 * 0x18 + 0x14] = param_1[6];
                              FUN_00088920(param_1);
                              param_1[iVar3 * 0x18 + 0x15] = 0;
                              ((int (*)())FUN_0008b6d0)(param_1,param_1 + iVar3 * 0x18 + 0x17);
                              param_1[iVar3 * 0x18 + 0x25] = 0;
                              param_1[iVar3 * 0x18 + 0x1e] = 0;
                            }
                            else if (uVar7 == 0xb) {
                              param_1[iVar3 * 0x18 + 0x14] = param_1[6];
                              FUN_00088920(param_1);
                              ((int (*)())FUN_0008b4b0)(param_1,param_1 + iVar3 * 0x18 + 0x15);
                              FUN_00089160(param_1,0x13);
                              ((int (*)())FUN_0008b6d0)(param_1,param_1 + iVar3 * 0x18 + 0x17);
                              FUN_00089160(param_1,0x13);
                              if ((param_1[5] != 0) || (param_1[6] != 0x2a)) {
                                FUN_00088e70(param_1,"invalid texture image unit");
                              }
                              iVar8 = 0;
                              FUN_00088920(param_1);
                              if (param_1[5] == 0x15) {
                                FUN_00088920(param_1);
                                if (((param_1[5] != 0xf) || (iVar8 = param_1[6], iVar8 < 0)) ||
                                   ((int)(uint)(byte)((unsigned char *)0x000013b1)[*param_1] <= iVar8)) {
                                  FUN_00088e70(param_1,"invalid texture image unit number");
                                  iVar8 = param_1[6];
                                }
                                FUN_00088920(param_1);
                                FUN_00089160(param_1,0x16);
                              }
                              param_1[iVar3 * 0x18 + 0x24] = iVar8;
                              FUN_00089160(param_1,0x13);
                              if (param_1[5] != 0xe) {
                                FUN_00088e70(param_1,"invalid texture target");
                              }
                              FUN_00088920(param_1);
                              iVar8 = param_1[6];
                              param_1[iVar3 * 0x18 + 0x2b] = iVar8;
                              if ((*(char *)((int)param_1 + 0x39) == '\0') && (iVar8 - 6U < 3)) {
                                FUN_00088e70(param_1,"invalid texture target");
                              }
                              param_1[iVar3 * 0x18 + 0x25] = 0;
                              param_1[iVar3 * 0x18 + 0x1e] = 0;
                            }
                            else {
                              FUN_00089140(param_1);
                            }
                            param_1[0x9015] = param_1[0x9015] + 1;
                            goto LAB_0008bba0;
                          }
                          FUN_00088e70(param_1,"too many texture instructions");
                          uVar7 = param_1[5];
                          goto LAB_0008bbb0;
                        }
                        if ((uVar7 != 2) && (uVar7 != 5)) {
                          FUN_00089140(param_1);
                          uVar7 = param_1[5];
                        }
                        if (uVar7 == 2) {
                          FUN_00088920(param_1);
                          iVar3 = FUN_00088fd0(param_1);
                          if (iVar3 != 0) {
                            FUN_00088e70(param_1,"redeclared variable name");
                          }
                          piVar6 = (int *)(**(code **)(*param_1 + 0xc))(0x10);
                          if (piVar6 == (int *)0x0) {
                            FUN_00088ee0(param_1);
                          }
                          piVar6[2] = param_1[3] - param_1[2];
                          piVar6[1] = param_1[2];
                          iVar3 = param_1[0x13];
                          piVar6[3] = 0;
                          *piVar6 = iVar3;
                          param_1[0x13] = (int)piVar6;
                          FUN_00088920(param_1);
                          FUN_00089160(param_1,0x1b);
                          iVar3 = FUN_00088fd0(param_1);
                          if (iVar3 == 0) {
                            FUN_00088e70(param_1,"undefined variable binding in alias");
                          }
                          else {
                            piVar6[3] = iVar3;
                            FUN_00088920(param_1);
                          }
                        }
                        else {
                          iVar3 = param_1[6];
                          if (iVar3 == 1) {
                            FUN_00088920(param_1);
                            iVar3 = FUN_00089430(param_1);
                            if (iVar3 != 0) {
                              FUN_00089160(param_1,0x1b);
                              ((int (*)())FUN_0008ace0)(param_1,iVar3);
                            }
                          }
                          else if (iVar3 == 0) {
                            FUN_00088920(param_1);
                            if (param_1[5] != 0x1c) {
                              while (iVar3 = FUN_00089430(param_1), iVar3 != 0) {
                                *(undefined4 *)(iVar3 + 0x20) = 0;
                                *(undefined4 *)(iVar3 + 0x18) = 0;
                                if ((param_1[5] != 0x13) ||
                                   (FUN_00088920(param_1), param_1[5] == 0x1c)) break;
                              }
                            }
                          }
                          else if (iVar3 == 2) {
                            FUN_00088920(param_1);
                            iVar3 = FUN_00089430(param_1);
                            if (iVar3 != 0) {
                              *(undefined4 *)(iVar3 + 0x18) = 2;
                              if (param_1[5] == 0x15) {
                                FUN_00088920(param_1);
                                if (param_1[5] == 0xf) {
                                  iVar8 = param_1[6];
                                  if ((iVar8 == 0) || (*(int *)(((unsigned char *)0x000011e4) + *param_1) < iVar8))
                                  {
                                    FUN_00088e70(param_1,"invalid parameter array size");
                                    iVar8 = 1;
                                  }
                                  else {
                                    FUN_00088920(param_1);
                                  }
                                }
                                else {
                                  iVar8 = *(int *)(((unsigned char *)0x000011e4) + *param_1) + 1;
                                }
                                *(int *)(iVar3 + 0xc) = iVar8;
                                iVar8 = (**(code **)(*param_1 + 0xc))(iVar8 * 0x14);
                                *(int *)(iVar3 + 0x14) = iVar8;
                                *(undefined4 *)(iVar3 + 0x10) = 0;
                                if (iVar8 == 0) {
                                  FUN_00088ee0(param_1);
                                }
                                else {
                                  FUN_00089160(param_1,0x16);
                                  FUN_00089160(param_1,0x1b);
                                  FUN_00089160(param_1,0x17);
                                  iVar8 = param_1[5];
                                  while ((iVar8 != 0x1c &&
                                         (((int (*)())FUN_0008aa40)(param_1,iVar3,1,1), param_1[5] == 0x13))) {
                                    FUN_00088920(param_1);
                                    iVar8 = param_1[5];
                                  }
                                  if (*(int *)(((unsigned char *)0x000011e4) + *param_1) < *(int *)(iVar3 + 0xc)) {
                                    *(undefined4 *)(iVar3 + 0xc) = *(undefined4 *)(iVar3 + 0x10);
                                  }
                                  else if (*(int *)(iVar3 + 0xc) != *(int *)(iVar3 + 0x10)) {
                                    FUN_00088e70(param_1,"array size and binding count mismatch");
                                  }
                                  FUN_00089160(param_1,0x18);
                                }
                              }
                              else {
                                *(undefined4 *)(iVar3 + 0xc) = 0;
                                FUN_00089160(param_1,0x1b);
                                ((int (*)())FUN_0008aa40)(param_1,iVar3,0,1);
                              }
                            }
                          }
                          else if (iVar3 == 3) {
                            FUN_00088920(param_1);
                            iVar3 = FUN_00089430(param_1);
                            if (iVar3 != 0) {
                              FUN_00089160(param_1,0x1b);
                              FUN_000895b0(param_1,iVar3 + 0x18);
                            }
                          }
                          else {
                            FUN_00089140(param_1);
                          }
                        }
                      }
                      else {
LAB_0008bb90:
                        FUN_00088e70(param_1,"invalid statement");
                      }
LAB_0008bba0:
                      FUN_00089160(param_1,0x14);
                      uVar7 = param_1[5];
                      goto LAB_0008bbb0;
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
  param_1[2] = (int)(pcVar5 + -1);
  FUN_00088e70(param_1,"invalid header");
  return 0;
}

/* FUN_0008c490 @ 0x8c490 (248 bytes) */
int FUN_0008c490(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  uint *param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 *param_6;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  uVar1 = *param_3;
  if (0 < (int)uVar1) {
    uVar4 = 0;
    iVar2 = param_2;
    uVar6 = uVar1;
    do {
      if (((*(int *)(iVar2 + 8) == param_6[2]) && (*(int *)(iVar2 + 0xc) == param_6[3])) &&
         (*(int *)(iVar2 + 0x10) == param_6[4])) {
        if (-1 < (int)uVar4) {
          param_6[1] = uVar4;
          return uVar4;
        }
        break;
      }
      uVar4 = uVar4 + 1;
      iVar2 = iVar2 + 0x14;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  if (uVar1 < param_4) {
    uVar5 = param_6[2];
    uVar3 = param_6[3];
    param_6[1] = uVar1;
    iVar2 = uVar1 * 0x14 + param_2;
    *(undefined4 *)(param_2 + uVar1 * 0x14) = *param_6;
    *(undefined4 *)(iVar2 + 8) = uVar5;
    *(undefined4 *)(iVar2 + 0xc) = uVar3;
    *(uint *)(iVar2 + 4) = uVar1;
    *(undefined4 *)(iVar2 + 0x10) = param_6[4];
    *param_3 = *param_3 + 1;
  }
  else {
    FUN_00088e70(param_1,param_5);
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

/* FUN_0008c590 @ 0x8c590 (3768 bytes) */
int FUN_0008c590(param_1, param_2, param_3, param_4)
  int param_1;
  undefined1 *param_2;
  size_t param_3;
  void *param_4;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  int *piVar5;
  byte bVar9;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int *piVar10;
  void *pvVar11;
  size_t sVar12;
  char *pcVar13;
  uint *puVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  void *pvVar18;
  uint uVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  uint *puVar23;
  int iVar24;
  int iVar25;
  int local_d8 [16];
  uint local_98;
  int local_94;
  int local_90;
  uint local_8c;
  undefined *local_88;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int *local_70;
  undefined *local_6c;
  int *local_68;
  int *local_64;
  int local_60;
  int *local_5c;
  
  piVar10 = (int *)(**(code **)(param_1 + 0xc))(0x24a30);
  param_2[0x54] = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  if (*(int *)(param_2 + 0x60) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(param_2 + 0x60) = 0;
  }
  *(undefined4 *)(param_2 + 0x10) = 0;
  *(undefined4 *)(param_2 + 100) = 0;
  *(undefined4 *)(param_2 + 0x78) = 0;
  *(undefined4 *)(param_2 + 0x7c) = 0;
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(undefined4 *)(param_2 + 0x8c) = 0;
  *(undefined4 *)(param_2 + 0x90) = 0;
  *(undefined4 *)(param_2 + 0x88) = 0;
  *(undefined4 *)(param_2 + 0x74) = 0;
  *(undefined4 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 0x70) = 0;
  *(undefined4 *)(param_2 + 0x68) = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  if (((unsigned char *)0x000013b1)[param_1] != '\0') {
    iVar15 = 0;
    puVar4 = param_2;
    do {
      *(undefined4 *)(puVar4 + 0x14) = 0;
      iVar15 = iVar15 + 1;
      puVar4 = puVar4 + 4;
    } while (iVar15 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
  }
  if (0 < *(int *)(((unsigned char *)0x000011d4) + param_1)) {
    iVar15 = 0;
    do {
      *(undefined1 *)(*(int *)(param_2 + 0x94) + iVar15) = 0;
      iVar15 = iVar15 + 1;
    } while (iVar15 < *(int *)(((unsigned char *)0x000011d4) + param_1));
  }
  pvVar11 = (void *)(**(code **)(param_1 + 0xc))(param_3 + 1);
  if (pvVar11 == (void *)0x0) {
    _free(piVar10);
    return;
  }
  _memcpy(pvVar11,param_4,param_3);
  *(undefined1 *)((int)pvVar11 + param_3) = 0;
  piVar10[3] = (int)pvVar11;
  *piVar10 = param_1;
  piVar10[1] = (int)pvVar11;
  piVar10[2] = (int)pvVar11;
  piVar10[4] = (int)pvVar11 + param_3;
  piVar10[0xb] = -1;
  piVar10[10] = -1;
  piVar10[9] = 1;
  iVar15 = 7;
  piVar10[0xc] = (int)"";
  piVar5 = piVar10;
  do {
    *(undefined1 *)(piVar5 + 0xd) = 0;
    piVar5 = (int *)((int)piVar5 + 1);
    iVar15 = iVar15 + -1;
  } while (iVar15 != 0);
  piVar10[0xf] = 0;
  piVar10[0x928b] = 0;
  piVar10[0x10] = 0;
  piVar10[0x11] = 0;
  piVar10[0x12] = 0;
  piVar10[0x13] = 0;
  piVar10[0x9014] = 0;
  piVar10[0x9015] = 0;
  piVar10[0x9116] = 0;
  piVar10[0x9149] = 0;
  piVar10[0x928a] = 0;
  iVar15 = ((int (*)())FUN_0008b9f0)(piVar10);
  if (iVar15 != 0) {
    iVar15 = *piVar10;
    bVar9 = *(char *)(piVar10 + 0xd) == '\x01';
    if (*(char *)((int)piVar10 + 0x35) == '\x01') {
      bVar9 = bVar9 + 1;
    }
    if (*(char *)((int)piVar10 + 0x36) == '\x01') {
      bVar9 = bVar9 + 1;
    }
    if (bVar9 < 2) {
      local_98 = (uint)(bVar9 == 1);
      bVar9 = *(char *)((int)piVar10 + 0x37) == '\x01';
      if (*(char *)(piVar10 + 0xe) == '\x01') {
        bVar9 = bVar9 + 1;
      }
      if (bVar9 < 2) {
LAB_0008c88c:
        piVar5 = (int *)piVar10[0xf];
        local_94 = 0;
        do {
          if (piVar5 != (int *)0x0) {
            local_68 = piVar10 + 0x914a;
            local_6c = &DAT_001ac5a4;
            bVar1 = local_98 == 0;
            local_8c = local_98;
            local_64 = piVar10 + 0x928a;
            local_88 = &DAT_001ac5a4;
            do {
              iVar2 = piVar5[6];
              if (iVar2 == 1) {
                iVar2 = ((int (*)())FUN_0008c490)(piVar10,piVar10 + 0x9117,piVar10 + 0x9149,
                                     *(int *)(((unsigned char *)0x000011ec) + iVar15) - local_8c,local_88 + -0x6920,
                                     piVar5 + 6);
                if (iVar2 < 0) goto LAB_0008d2d0;
              }
              else if (iVar2 == 0) {
                if ((int)(*(int *)(((unsigned char *)0x000011dc) + iVar15) - local_8c) <= piVar10[0x928b]) {
                  FUN_00088e70(piVar10,"too many temporaries");
                  goto LAB_0008d2d0;
                }
                piVar5[7] = piVar10[0x928b];
                piVar10[0x928b] = piVar10[0x928b] + 1;
              }
              else if (iVar2 == 2) {
                iVar2 = piVar5[3];
                local_90 = 1;
                if ((iVar2 == 0) || (local_90 = iVar2, 0 < iVar2)) {
                  iVar2 = 0;
                  iVar16 = 0;
                  do {
                    if (bVar1) {
                      iVar20 = 0;
                    }
                    else {
                      iVar20 = 2;
                    }
                    iVar20 = ((int (*)())FUN_0008c490)(piVar10,local_68,local_64,
                                          *(int *)(((unsigned char *)0x000011e4) + iVar15) - iVar20,
                                          local_6c + -0x693c,iVar16 + piVar5[5]);
                    if (iVar20 < 0) goto LAB_0008d2d0;
                    iVar2 = iVar2 + 1;
                    iVar16 = iVar16 + 0x14;
                  } while (local_90 != iVar2);
                }
              }
              else if (iVar2 != 3) {
                FUN_00089140(piVar10);
                goto LAB_0008d2d0;
              }
              piVar5 = (int *)*piVar5;
            } while (piVar5 != (int *)0x0);
          }
          local_94 = local_94 + 1;
          if (1 < local_94) {
            iVar20 = piVar10[0x9014];
            iVar16 = *(int *)(((unsigned char *)0x000011d4) + iVar15);
            iVar2 = iVar20 + piVar10[0x9015];
            if (iVar2 <= iVar16) {
              bVar1 = local_98 == 0;
              if (!bVar1) {
                if (*(char *)(piVar10 + 0xd) == '\x01') {
                  if (iVar20 <= *(int *)(((unsigned char *)0x00001204) + iVar15) + -3) {
                    if (iVar16 + -3 < iVar2) goto LAB_0008cad4;
                    goto LAB_0008ca70;
                  }
LAB_0008cab4:
                  FUN_00088e70(piVar10,"too many ALU instructions");
                  goto LAB_0008d2d0;
                }
LAB_0008ca70:
                if (*(char *)((int)piVar10 + 0x35) == '\x01') {
                  if (*(int *)(((unsigned char *)0x00001204) + iVar15) + -4 < iVar20) goto LAB_0008cab4;
                  if (iVar16 + -4 < iVar2) goto LAB_0008cad4;
                }
                if (*(char *)((int)piVar10 + 0x36) == '\x01') {
                  if (*(int *)(((unsigned char *)0x00001204) + iVar15) + -2 < iVar20) goto LAB_0008cab4;
                  if (iVar16 + -2 < iVar2) goto LAB_0008cad4;
                }
              }
              uVar3 = (uint)(byte)((unsigned char *)0x000013b1)[iVar15];
              if (uVar3 != 0) {
                piVar5 = local_d8;
                do {
                  *piVar5 = 0;
                  piVar5 = piVar5 + 1;
                  uVar3 = uVar3 - 1;
                } while (uVar3 != 0);
              }
              if (iVar2 < 1) {
                iVar20 = 0;
                iVar24 = 1;
              }
              else {
                local_70 = local_d8;
                uVar19 = 0;
                uVar22 = 0;
                uVar3 = 0;
                uVar21 = 0;
                iVar20 = 0;
                iVar24 = 1;
                iVar25 = 0;
                iVar16 = iVar2;
                do {
                  uVar6 = *(uint *)((int)piVar10 + iVar25 + 0x50);
                  if (uVar6 < 0x20) {
                    if ((0x1c < uVar6) || (uVar6 == 0xb)) goto LAB_0008cb94;
LAB_0008cb70:
                    iVar8 = *(int *)((int)piVar10 + iVar25 + 0x5c);
                    if (*(int *)(iVar8 + 0x18) == 0) {
                      uVar17 = *(uint *)(iVar8 + 0x1c);
                      uVar7 = uVar17 - 0x20;
                      if ((int)uVar7 < 0) {
                        uVar7 = 0;
                        uVar17 = 1 << (uVar17 & 0x3f);
                      }
                      else {
                        uVar17 = 0;
                        uVar7 = 1 << (uVar7 & 0x3f);
                      }
                      uVar3 = uVar3 | uVar7;
                      uVar21 = uVar21 | uVar17;
                    }
                    iVar8 = *(int *)((int)piVar10 + iVar25 + 0x78);
                    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x18) == 0)) {
                      uVar17 = *(uint *)(iVar8 + 0x1c) - 0x20;
                      if ((int)uVar17 < 0) {
                        uVar17 = 0;
                        uVar7 = 1 << (*(uint *)(iVar8 + 0x1c) & 0x3f);
                      }
                      else {
                        uVar7 = 0;
                        uVar17 = 1 << (uVar17 & 0x3f);
                      }
                      uVar3 = uVar3 | uVar17;
                      uVar21 = uVar21 | uVar7;
                    }
                    iVar8 = *(int *)((int)piVar10 + iVar25 + 0x94);
                    if ((iVar8 != 0) && (*(int *)(iVar8 + 0x18) == 0)) {
                      uVar17 = *(uint *)(iVar8 + 0x1c) - 0x20;
                      if ((int)uVar17 < 0) {
                        uVar17 = 0;
                        uVar7 = 1 << (*(uint *)(iVar8 + 0x1c) & 0x3f);
                      }
                      else {
                        uVar7 = 0;
                        uVar17 = 1 << (uVar17 & 0x3f);
                      }
                      uVar3 = uVar3 | uVar17;
                      uVar21 = uVar21 | uVar7;
                    }
                    iVar8 = *(int *)((int)piVar10 + iVar25 + 0x54);
                    if (*(int *)(iVar8 + 0x18) == 0) {
                      uVar17 = *(uint *)(iVar8 + 0x1c) - 0x20;
                      if ((int)uVar17 < 0) {
                        local_80 = 0;
                        local_7c = 1 << (*(uint *)(iVar8 + 0x1c) & 0x3f);
                      }
                      else {
                        local_7c = 0;
                        local_80 = 1 << (uVar17 & 0x3f);
                      }
                      uVar3 = uVar3 | local_80;
                      uVar21 = uVar21 | local_7c;
                    }
                    if (uVar6 == 0xb) goto LAB_0008ce38;
LAB_0008cddc:
                    if (*(int *)(iVar8 + 0x18) == 0) {
                      uVar6 = *(uint *)(iVar8 + 0x1c) - 0x20;
                      if ((int)uVar6 < 0) {
                        local_78 = 0;
                        local_74 = 1 << (*(uint *)(iVar8 + 0x1c) & 0x3f);
                      }
                      else {
                        local_78 = 1 << (uVar6 & 0x3f);
                        local_74 = 0;
                      }
                      uVar19 = uVar19 | local_78;
                      uVar22 = uVar22 | local_74;
                    }
                  }
                  else {
                    if (2 < uVar6 - 0x3d) goto LAB_0008cb70;
LAB_0008cb94:
                    iVar8 = *(int *)((int)piVar10 + iVar25 + 0x5c);
                    uVar17 = *(uint *)(iVar8 + 0x1c);
                    if (*(int *)(iVar8 + 0x18) == 0) {
                      if ((int)(uVar17 - 0x20) < 0) {
                        uVar17 = (uVar19 << 1) << (0x1f - uVar17 & 0x3f) | uVar22 >> (uVar17 & 0x3f)
                        ;
                      }
                      else {
                        uVar17 = uVar19 >> (uVar17 - 0x20 & 0x3f);
                      }
                      if ((uVar17 & 1) == 0) goto LAB_0008cbd4;
LAB_0008cc20:
                      iVar24 = iVar24 + 1;
                      if (uVar6 != 0xb) {
                        uVar19 = 0;
                        uVar22 = 0;
                        uVar3 = 0;
                        uVar21 = 0;
LAB_0008cc50:
                        iVar8 = *(int *)((int)piVar10 + iVar25 + 0x90);
                        if (local_70[iVar8] == 0) {
                          local_70[iVar8] = *(int *)((int)piVar10 + iVar25 + 0xac);
                          iVar8 = *(int *)((int)piVar10 + iVar25 + 0x54);
                        }
                        else {
                          if (local_70[iVar8] != *(int *)((int)piVar10 + iVar25 + 0xac)) {
                            FUN_00088e70(piVar10,"multiple targets on texture context");
                            goto LAB_0008d2d0;
                          }
                          iVar8 = *(int *)((int)piVar10 + iVar25 + 0x54);
                        }
                        goto LAB_0008cddc;
                      }
                      uVar19 = 0;
                      uVar22 = 0;
                      iVar20 = 1;
                      uVar3 = 0;
                      uVar21 = 0;
                    }
                    else {
LAB_0008cbd4:
                      if (uVar6 != 0xb) {
                        iVar8 = *(int *)((int)piVar10 + iVar25 + 0x54);
                        if (*(int *)(iVar8 + 0x18) == 0) {
                          uVar17 = *(uint *)(iVar8 + 0x1c);
                          if ((int)(uVar17 - 0x20) < 0) {
                            uVar17 = (uVar3 << 1) << (0x1f - uVar17 & 0x3f) |
                                     uVar21 >> (uVar17 & 0x3f);
                          }
                          else {
                            uVar17 = uVar3 >> (uVar17 - 0x20 & 0x3f);
                          }
                          if ((uVar17 & 1) != 0) goto LAB_0008cc20;
                        }
                        goto LAB_0008cc50;
                      }
                      iVar20 = 1;
                    }
                  }
LAB_0008ce38:
                  iVar25 = iVar25 + 0x60;
                  iVar16 = iVar16 + -1;
                } while (iVar16 != 0);
              }
              if (*(int *)((*(unsigned char *)0x0000120c) + iVar15) < iVar24) {
                FUN_00088e70(piVar10,"too many indirections");
              }
              else {
                local_60 = iVar20;
                iVar2 = (**(code **)(iVar15 + 0xc))
                                  (iVar2 * 0x70 + (piVar10[0x9149] + piVar10[0x928a]) * 0x14 +
                                   piVar10[0x9116] * 0x10 + 0x70);
                *(int *)(param_2 + 0x60) = iVar2;
                if (iVar2 != 0) {
                  if (local_60 != 0) {
                    param_2[3] = 1;
                  }
                  if (*(char *)((int)piVar10 + 0x3a) == '\x01') {
                    param_2[5] = 1;
                  }
                  if (bVar1) {
                    *(uint *)(param_2 + 8) = local_98;
                  }
                  else {
                    param_2[1] = 1;
                    if (*(char *)(piVar10 + 0xd) == '\x01') {
                      *(undefined4 *)(param_2 + 8) = 0x800;
                    }
                    else if (*(char *)((int)piVar10 + 0x35) == '\x01') {
                      *(undefined4 *)(param_2 + 8) = 0x801;
                    }
                    else if (*(char *)((int)piVar10 + 0x36) == '\x01') {
                      *(undefined4 *)(param_2 + 8) = 0x2601;
                    }
                    else {
                      *(undefined4 *)(param_2 + 8) = 0;
                    }
                  }
                  if (((unsigned char *)0x000013b1)[iVar15] != '\0') {
                    iVar2 = 0;
                    piVar5 = local_d8;
                    puVar4 = param_2;
                    do {
                      iVar16 = *piVar5;
                      iVar2 = iVar2 + 1;
                      piVar5 = piVar5 + 1;
                      *(int *)(puVar4 + 0x14) = iVar16;
                      puVar4 = puVar4 + 4;
                    } while (iVar2 < (int)(uint)(byte)((unsigned char *)0x000013b1)[iVar15]);
                  }
                  *(int *)(param_2 + 100) = *(int *)(param_2 + 0x60);
                  *(int *)(param_2 + 0x68) = piVar10[0x9014] + piVar10[0x9015];
                  *(int *)(param_2 + 0x6c) = piVar10[0x9014];
                  *(int *)(param_2 + 0x70) = piVar10[0x9015];
                  pvVar11 = (void *)((piVar10[0x9014] + piVar10[0x9015]) * 0x70 +
                                     *(int *)(param_2 + 0x60) + 0x70);
                  *(void **)(param_2 + 0x78) = pvVar11;
                  *(int *)(param_2 + 0x7c) = piVar10[0x9149];
                  pvVar18 = (void *)(piVar10[0x9149] * 0x14 + (int)pvVar11);
                  *(void **)(param_2 + 0x80) = pvVar18;
                  *(int *)(param_2 + 0x84) = piVar10[0x928a];
                  *(void **)(param_2 + 0x8c) = (void *)(piVar10[0x928a] * 0x14 + (int)pvVar18);
                  *(int *)(param_2 + 0x90) = piVar10[0x9116];
                  iVar15 = piVar10[0x928b];
                  *(int *)(param_2 + 0x74) = iVar24;
                  iVar2 = 0;
                  *(int *)(param_2 + 0x88) = iVar15;
                  _memcpy(pvVar11,piVar10 + 0x9117,piVar10[0x9149] * 0x14);
                  _memcpy(*(void **)(param_2 + 0x80),piVar10 + 0x914a,piVar10[0x928a] * 0x14);
                  _memcpy(*(void **)(param_2 + 0x8c),piVar10 + 0x9016,piVar10[0x9116] << 4);
                  if (0 < piVar10[0x9014] + piVar10[0x9015]) {
                    iVar2 = 0;
                    local_5c = piVar10 + 0x14;
                    iVar16 = 0;
                    iVar15 = 0;
                    do {
                      iVar25 = *(int *)(param_2 + 100);
                      iVar20 = (int)local_5c + iVar15;
                      puVar23 = (uint *)(iVar16 + iVar25);
                      _memset(puVar23,0,0x70);
                      *(undefined4 *)(iVar16 + iVar25) = *(undefined4 *)((int)local_5c + iVar15);
                      iVar25 = *(int *)(iVar20 + 4);
                      *(undefined1 *)(iVar2 + *(int *)(param_2 + 0x94)) = 0;
                      if (iVar25 != 0) {
                        uVar3 = *(uint *)(iVar25 + 0x1c);
                        puVar23[1] = *(uint *)(iVar25 + 0x18);
                        puVar23[2] = uVar3;
                        if (*(int *)(iVar25 + 0x18) == 3) {
                          if (*(int *)(iVar25 + 0x1c) == 1) {
                            param_2[4] = 1;
                          }
                          else if (*(int *)(iVar25 + 0x1c) == 0) {
                            *(char *)(iVar2 + *(int *)(param_2 + 0x94)) =
                                 (char)*(undefined4 *)(iVar25 + 0x24);
                          }
                        }
                      }
                      iVar25 = 0;
                      puVar23[3] = *(uint *)(iVar20 + 8);
                      puVar14 = puVar23;
                      do {
                        iVar24 = *(int *)(iVar20 + 0xc);
                        if (iVar24 == 0) {
                          uVar3 = *puVar23;
                          if ((0x1c < uVar3) &&
                             (((uVar3 < 0x20 || (uVar3 - 0x3d < 3)) &&
                              (puVar14[0xb] = *(uint *)(iVar20 + 0x24), iVar25 == 1)))) {
                            *(uint *)(param_2 + 0x10) =
                                 1 << (puVar23[0x13] & 0x3f) | *(uint *)(param_2 + 0x10);
                          }
                        }
                        else {
                          if (*(int *)(iVar24 + 0xc) == 0) {
                            uVar3 = *(uint *)(iVar24 + 0x1c);
                            uVar19 = *(uint *)(iVar24 + 0x18);
                            puVar14[0xb] = 0;
                            puVar14[5] = uVar3;
                            puVar14[4] = uVar19;
                          }
                          else {
                            iVar8 = *(int *)(iVar20 + 0x24) * 0x14;
                            uVar3 = *(uint *)(iVar8 + *(int *)(iVar24 + 0x14));
                            uVar19 = *(uint *)(iVar8 + *(int *)(iVar24 + 0x14) + 4);
                            puVar14[0xb] = 0;
                            puVar14[4] = uVar3;
                            puVar14[5] = uVar19;
                          }
                          if (puVar14[4] == 1) {
                            iVar8 = puVar14[5] * 0x14 + *(int *)(param_2 + 0x78);
                            iVar24 = *(int *)(iVar8 + 8);
                            if (iVar24 == 1) {
                              if (*(int *)(iVar8 + 0xc) == 1) {
                                *param_2 = 1;
                              }
                            }
                            else if (iVar24 == 2) {
                              *(uint *)(param_2 + 0xc) =
                                   1 << (*(uint *)(iVar8 + 0xc) & 0x3f) | *(uint *)(param_2 + 0xc);
                            }
                            else if (iVar24 == 3) {
                              param_2[1] = 1;
                            }
                            else if (iVar24 == 4) {
                              param_2[2] = 1;
                            }
                          }
                          uVar3 = *(uint *)(iVar20 + 0x14);
                          uVar19 = *(uint *)(iVar20 + 0x18);
                          uVar21 = *(uint *)(iVar20 + 0x1c);
                          puVar14[6] = *(uint *)(iVar20 + 0x10);
                          puVar14[7] = uVar3;
                          puVar14[8] = uVar19;
                          puVar14[9] = uVar21;
                          *(undefined1 *)(puVar14 + 10) = *(undefined1 *)(iVar20 + 0x20);
                        }
                        bVar1 = iVar25 != 2;
                        iVar20 = iVar20 + 0x1c;
                        puVar14 = puVar14 + 8;
                        iVar25 = iVar25 + 1;
                      } while (bVar1);
                      iVar2 = iVar2 + 1;
                      iVar15 = iVar15 + 0x60;
                      iVar16 = iVar16 + 0x70;
                    } while (iVar2 < piVar10[0x9014] + piVar10[0x9015]);
                  }
                  _memset((void *)(iVar2 * 0x70 + *(int *)(param_2 + 100)),0,0x70);
                  *(undefined4 *)(iVar2 * 0x70 + *(int *)(param_2 + 100)) = 0x41;
                  param_2[0x54] = 1;
                }
              }
              goto LAB_0008d2d0;
            }
LAB_0008cad4:
            FUN_00088e70(piVar10,"too many total instructions");
            goto LAB_0008d2d0;
          }
          if (local_94 == 0) goto LAB_0008c88c;
          piVar5 = (int *)piVar10[0x11];
        } while( true );
      }
      FUN_00088e70(piVar10,"more than one precision hint option");
    }
    else {
      FUN_00088e70(piVar10,"more than one fog option");
    }
  }
LAB_0008d2d0:
  *(int *)(((unsigned char *)0x00001124) + param_1) = piVar10[10];
  if (*(int *)(((unsigned char *)0x00001128) + param_1) != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  sVar12 = _strlen((char *)piVar10[0xc]);
  pcVar13 = (char *)(**(code **)(param_1 + 0xc))(sVar12 + 0xb);
  *(char **)(((unsigned char *)0x00001128) + param_1) = pcVar13;
  if ((uint)piVar10[0xb] < 10000) {
    FUN_001a32d0(pcVar13,"line %d: %s",piVar10[0xb],piVar10[0xc]);
  }
  else {
    _strcpy(pcVar13,(char *)piVar10[0xc]);
  }
  if (piVar10[1] != 0) {
    (**(code **)(param_1 + 0x18))();
  }
  piVar5 = (int *)piVar10[0xf];
  while (piVar5 != (int *)0x0) {
    if ((int *)piVar5[5] != piVar5 + 6) {
      (**(code **)(param_1 + 0x18))();
    }
    iVar15 = *piVar5;
    (**(code **)(param_1 + 0x18))(piVar5);
    piVar5 = (int *)iVar15;
  }
  piVar5 = (int *)piVar10[0x11];
  while (piVar5 != (int *)0x0) {
    if ((int *)piVar5[5] != piVar5 + 6) {
      (**(code **)(param_1 + 0x18))();
    }
    iVar15 = *piVar5;
    (**(code **)(param_1 + 0x18))(piVar5);
    piVar5 = (int *)iVar15;
  }
  piVar5 = (int *)piVar10[0x13];
  while (piVar5 != (int *)0x0) {
    iVar15 = *piVar5;
    (**(code **)(param_1 + 0x18))(piVar5);
    piVar5 = (int *)iVar15;
  }
                    
                    
  (**(code **)(param_1 + 0x18))(piVar10);
  return;
}

/* FUN_0008d470 @ 0x8d470 (1744 bytes) */
int FUN_0008d470(param_1)
  int param_1;
{
  uint *puVar1;
  bool bVar2;
  uint uVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  undefined *puVar7;
  char *pcVar8;
  byte bVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  char *pcVar14;
  uint uVar15;
  undefined *puVar16;
  int iVar17;
  
  puVar7 = (*(unsigned char *)0x000011d0) + param_1;
  uVar11 = *(uint *)(param_1 + 0x44);
  iVar17 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  ((unsigned char *)0x000011d2)[param_1] = 0;
  ((unsigned char *)0x000011d1)[param_1] = 0;
  pcVar8 = *(char **)(((unsigned char *)0x0000121c) + param_1);
  if (*(char *)(*(int *)(pcVar8 + 0x74) + 0x54) == '\0') {
    ((unsigned char *)0x000011d3)[param_1] = 0;
    *(undefined4 *)(((unsigned char *)0x00001228) + param_1) = 0;
    if (((unsigned char *)0x000013b1)[param_1] != '\0') {
      iVar10 = 0;
      puVar16 = puVar7;
      do {
        *(undefined4 *)(puVar16 + 0x5c) = 0;
        iVar10 = iVar10 + 1;
        puVar16 = puVar16 + 4;
      } while (iVar10 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
    }
    uVar12 = 0xffffffff;
  }
  else {
    uVar3 = *(uint *)(pcVar8 + 8);
    ((unsigned char *)0x000011d3)[param_1] = (char)uVar3;
    uVar5 = *(uint *)(pcVar8 + 0xc);
    *(uint *)(((unsigned char *)0x00001228) + param_1) = uVar5;
    uVar15 = (uint)(byte)((unsigned char *)0x000013b6)[param_1];
    uVar12 = uVar15 - 1;
    if (-1 < (int)uVar12) {
      do {
        if (((uVar3 & 0xff | uVar5) >> (uVar12 & 0x3f) & 1) != 0) goto LAB_0008d4f8;
        uVar12 = uVar12 - 1;
        uVar15 = uVar15 - 1;
      } while (uVar15 != 0);
    }
    uVar12 = 0xffffffff;
LAB_0008d4f8:
    uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
    if (uVar15 != 0) {
      iVar10 = 0;
      pcVar14 = pcVar8;
      puVar16 = puVar7;
      do {
        switch(*(undefined4 *)(pcVar14 + 0x10)) {
        case 0:
          *(undefined4 *)(puVar16 + 0x5c) = 0;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
          break;
        case 1:
        case 6:
          *(undefined4 *)(puVar16 + 0x5c) = 0x10;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
          break;
        case 2:
        case 7:
          *(undefined4 *)(puVar16 + 0x5c) = 8;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
          break;
        case 3:
          *(undefined4 *)(puVar16 + 0x5c) = 2;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
          break;
        case 4:
          *(undefined4 *)(puVar16 + 0x5c) = 1;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
          break;
        case 5:
        case 8:
          *(undefined4 *)(puVar16 + 0x5c) = 4;
          uVar15 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
        }
        iVar10 = iVar10 + 1;
        pcVar14 = pcVar14 + 4;
        puVar16 = puVar16 + 4;
      } while (iVar10 < (int)uVar15);
    }
  }
  bVar2 = (uVar11 >> 0xd & 1) == 0;
  if ((pcVar8[4] == '\0') || (bVar2)) {
    uVar11 = *(uint *)(param_1 + 0x44);
    if ((uVar11 & 0x200) != 0) {
      uVar15 = *(uint *)(param_1 + 0x3c);
      uVar11 = uVar11 & 0xfffffdff;
      goto LAB_0008d6a4;
    }
  }
  else {
    uVar11 = *(uint *)(param_1 + 0x44);
    if ((uVar11 & 0x200) == 0) {
      uVar15 = *(uint *)(param_1 + 0x3c);
      uVar11 = uVar11 | 0x200;
LAB_0008d6a4:
      *(uint *)(param_1 + 0x44) = uVar11;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x3c) = uVar15 | 1;
    }
  }
  if ((*pcVar8 == '\0') || (bVar2)) {
    if ((uVar11 & 0x1000) != 0) {
      uVar11 = uVar11 & 0xffffefff;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    }
    if ((bVar2) && ((uVar11 & 0x4000) != 0)) goto joined_r0x0008d734;
    if ((uVar11 & 0x10000) != 0) {
      uVar15 = *(uint *)(param_1 + 0x38);
      uVar11 = uVar11 & 0xfffeffff;
      goto LAB_0008d760;
    }
  }
  else {
    if ((uVar11 & 0x1000) == 0) {
      uVar11 = uVar11 | 0x1000;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    }
joined_r0x0008d734:
    if ((uVar11 & 0x10000) == 0) {
      uVar15 = *(uint *)(param_1 + 0x38);
      uVar11 = uVar11 | 0x10000;
LAB_0008d760:
      *(uint *)(param_1 + 0x44) = uVar11;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = uVar15 | 0x20;
    }
  }
  if ((pcVar8[3] == '\0') || (bVar2)) {
    if ((uVar11 & 0x100) != 0) {
      uVar15 = *(uint *)(param_1 + 0x38);
      uVar11 = uVar11 & 0xfffffeff;
      goto LAB_0008d7b0;
    }
  }
  else if ((uVar11 & 0x100) == 0) {
    uVar15 = *(uint *)(param_1 + 0x38);
    uVar11 = uVar11 | 0x100;
LAB_0008d7b0:
    *(uint *)(param_1 + 0x44) = uVar11;
    *(undefined1 *)(param_1 + 0x2a) = 1;
    *(uint *)(param_1 + 0x38) = uVar15 | 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  if ((pcVar8[1] == '\0') || (bVar2)) {
    if ((uVar11 & 0x800) != 0) {
      uVar11 = uVar11 & 0xfffff7ff;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffdfff;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  else {
    if ((uVar11 & 0x800) == 0) {
      uVar11 = uVar11 | 0x800;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) | 0x2000;
    }
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
  }
  if ((pcVar8[2] == '\0') || (bVar2)) {
    if ((uVar11 & 0x400) != 0) {
      uVar11 = uVar11 & 0xfffffbff;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xffffefff;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  else {
    if ((uVar11 & 0x400) == 0) {
      uVar11 = uVar11 | 0x400;
      *(uint *)(param_1 + 0x44) = uVar11;
      *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) | 0x1000;
    }
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
  }
  if ((uVar11 & 0xc00) != 0) {
    bVar9 = ((unsigned char *)0x000013b0)[param_1];
    uVar15 = (uint)bVar9;
    if (uVar15 == 0) {
      uVar5 = 0xffffffff;
      uVar13 = 0xffffffff;
    }
    else {
      uVar6 = 0;
      uVar5 = 0xffffffff;
      uVar3 = 0xffffffff;
      do {
        uVar13 = uVar3;
        if (((((int)(uint)(byte)((unsigned char *)0x000011d3)[param_1] >> (uVar6 & 0x3f) & 1U) == 0) &&
            (uVar13 = uVar6, uVar3 != 0xffffffff)) && (uVar13 = uVar3, uVar5 == 0xffffffff)) {
          uVar5 = uVar6;
        }
        uVar6 = uVar6 + 1;
        uVar15 = uVar15 - 1;
        uVar3 = uVar13;
      } while (uVar15 != 0);
    }
    if ((uVar11 & 0x800) == 0) {
      if ((uVar11 & 0x400) != 0) {
        if (uVar13 != 0xffffffff) {
          bVar9 = (byte)uVar13;
        }
        ((unsigned char *)0x000011d2)[param_1] = bVar9;
        if ((int)uVar13 <= (int)uVar12) goto LAB_0008d98c;
        uVar11 = *(uint *)(param_1 + 0x44);
        uVar12 = uVar13;
      }
    }
    else {
      if (uVar13 != 0xffffffff) {
        bVar9 = (byte)uVar13;
      }
      ((unsigned char *)0x000011d1)[param_1] = bVar9;
      if ((int)uVar12 < (int)uVar13) {
        uVar12 = uVar13;
      }
      uVar11 = *(uint *)(param_1 + 0x44);
      if ((uVar11 & 0x400) != 0) {
        uVar4 = (undefined1)uVar5;
        if (uVar5 == 0xffffffff) {
          uVar4 = ((unsigned char *)0x000013b0)[param_1];
        }
        ((unsigned char *)0x000011d2)[param_1] = uVar4;
        if ((int)uVar12 < (int)uVar5) {
          uVar11 = *(uint *)(param_1 + 0x44);
          uVar12 = uVar5;
        }
        else {
LAB_0008d98c:
          uVar11 = *(uint *)(param_1 + 0x44);
        }
      }
    }
  }
  if ((bVar2) && (((unsigned char *)0x00002e0a)[iVar17] != '\0')) {
    if ((uVar11 & 0x1000000) == 0) {
      *(uint *)(param_1 + 0x44) = uVar11 | 0x1000000;
      uVar12 = *(uint *)(param_1 + 0x38);
      *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) | 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = uVar12 | 0x100;
      if ((((int)uVar11 < 0 || (uVar11 & 0x800000) != 0) || (uVar11 & 0x200000) != 0) ||
          (uVar11 & 0x10000) != 0) {
        *(uint *)(param_1 + 0x38) = uVar12 | 0x120;
      }
    }
  }
  else {
    if ((uVar11 & 0x1000000) != 0) {
      uVar15 = uVar11 & 0xfeffffff;
      *(uint *)(param_1 + 0x44) = uVar15;
      uVar3 = *(uint *)(param_1 + 0x38);
      *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) & 0xfffffffe;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = uVar3 | 0x100;
      if ((((int)uVar11 < 0 || (uVar15 >> 0x17 & 1) != 0) || (uVar15 >> 0x15 & 1) != 0) ||
          (uVar15 >> 0x10 & 1) != 0) {
        *(uint *)(param_1 + 0x38) = uVar3 | 0x120;
      }
    }
    if (!bVar2) {
      uVar11 = (uint)(byte)((unsigned char *)0x000013b1)[param_1];
      if (uVar11 != 0) {
        iVar17 = param_1;
        if ((uVar11 == 0) || (uVar11 == 0x80000000)) {
          uVar11 = 1;
        }
        do {
          uVar15 = *(uint *)(iVar17 + 0x48) & 0xffffffe0;
          *(uint *)(iVar17 + 0x48) = uVar15;
          puVar1 = (uint *)(puVar7 + 0x5c);
          puVar7 = puVar7 + 4;
          *(uint *)(iVar17 + 0x48) = uVar15 | *puVar1;
          iVar17 = iVar17 + 4;
          uVar11 = uVar11 - 1;
        } while (uVar11 != 0);
      }
      if ((int)(uint)*(byte *)(param_1 + 0x2b) <= (int)uVar12) {
        *(char *)(param_1 + 0x2b) = (char)uVar12 + '\x01';
      }
      bVar9 = ((unsigned char *)0x000013b6)[param_1];
      uVar11 = *(uint *)(param_1 + 0x3c);
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2200;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(ushort *)(param_1 + 0x34) = (short)(1 << (bVar9 & 0x3f)) - 1U | *(ushort *)(param_1 + 0x34);
      goto LAB_0008da14;
    }
  }
  *(undefined1 *)(param_1 + 0x29) = 1;
  uVar11 = *(uint *)(param_1 + 0x3c) | 0x100;
  *(uint *)(param_1 + 0x3c) = uVar11;
LAB_0008da14:
  *(uint *)(param_1 + 0x3c) = uVar11 | 0x40;
  *(undefined1 *)(param_1 + 0x29) = 1;
  return;
}

/* FUN_0008dbd0 @ 0x8dbd0 (100 bytes) */
int FUN_0008dbd0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(((unsigned char *)0x00001270) + param_1) != param_2) {
    *(int *)(((unsigned char *)0x00001270) + param_1) = param_2;
    *(undefined4 *)(((unsigned char *)0x0000121c) + param_1) =
         *(undefined4 *)(param_2 * 0x18 + *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 8) + 0x14);
    ((int (*)())FUN_0008d470)();
    ((unsigned char *)0x000011d0)[param_1] = 1;
  }
  return;
}

/* FUN_0008dc40 @ 0x8dc40 (12 bytes) */
int FUN_0008dc40(param_1)
  int param_1;
{
                    
                    
  (**(code **)(((unsigned char *)0x00001278) + param_1))();
  return;
}

/* FUN_0008dc50 @ 0x8dc50 (336 bytes) */
int FUN_0008dc50(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  param_2[4] = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  if (((unsigned char *)0x000013b1)[param_1] != '\0') {
    iVar4 = 0;
    puVar1 = param_2;
    do {
      *(undefined4 *)(puVar1 + 0x10) = 0;
      iVar4 = iVar4 + 1;
      puVar1 = puVar1 + 4;
    } while (iVar4 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
  }
  uVar2 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 0x10),4)
  ;
  *(undefined4 *)(param_2 + 0x50) = 0;
  *(undefined4 *)(param_2 + 0x54) = 0;
  *(undefined4 *)(param_2 + 0x70) = uVar2;
  *(undefined4 *)(param_2 + 0x58) = 0;
  param_2[0x6c] = 1;
  *(undefined4 *)(param_2 + 0x5c) = 0;
  *(undefined4 *)(param_2 + 0x60) = 0;
  *(undefined4 *)(param_2 + 100) = 0;
  *(undefined4 *)(param_2 + 0x68) = 0;
  iVar4 = (**(code **)(param_1 + 0xc))(0x98);
  *(int *)(param_2 + 0x74) = iVar4;
  *(undefined1 *)(iVar4 + 0x54) = 0;
  *(undefined1 *)(*(int *)(param_2 + 0x74) + 0x55) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x60) = 0;
  *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x58) = 0;
  iVar5 = *(int *)(((unsigned char *)0x000011d4) + param_1);
  iVar3 = (**(code **)(param_1 + 0x10))(iVar5,1);
  *(int *)(iVar4 + 0x94) = iVar3;
  if (0 < iVar5) {
    iVar4 = 0;
    do {
      *(undefined1 *)(iVar3 + iVar4) = 0;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return;
}

/* FUN_0008dda0 @ 0x8dda0 (408 bytes) */
int FUN_0008dda0(param_1, param_2)
  int param_1;
  undefined1 *param_2;
{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *(undefined4 *)(param_2 + 0xc) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  param_2[4] = 0;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  if (((unsigned char *)0x000013b1)[param_1] != '\0') {
    iVar3 = 0;
    puVar2 = param_2;
    do {
      *(undefined4 *)(puVar2 + 0x10) = 0;
      iVar3 = iVar3 + 1;
      puVar2 = puVar2 + 4;
    } while (iVar3 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
  }
  iVar3 = *(int *)(param_2 + 0x70);
  iVar4 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  if (iVar3 != 0) {
    iVar1 = *(int *)(iVar4 + 0x10);
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        if (*(int *)(iVar5 * 4 + iVar3) != 0) {
          *(undefined4 *)(iVar5 * 4 + iVar3) = 0;
          (**(code **)(((unsigned char *)0x00001224) + param_1))(param_1);
          iVar3 = *(int *)(param_2 + 0x70);
          iVar1 = *(int *)(iVar4 + 0x10);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
    }
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(param_2 + 0x70) = 0;
  }
  iVar3 = *(int *)(param_2 + 0x74);
  if (iVar3 != 0) {
    if (*(int *)(iVar3 + 0x60) != 0) {
      (**(code **)(param_1 + 0x18))(*(int *)(iVar3 + 0x60));
      *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x60) = 0;
      iVar3 = *(int *)(param_2 + 0x74);
    }
    if (*(int *)(iVar3 + 0x94) != 0) {
      (**(code **)(param_1 + 0x18))(*(int *)(iVar3 + 0x94));
      *(undefined4 *)(*(int *)(param_2 + 0x74) + 0x94) = 0;
      iVar3 = *(int *)(param_2 + 0x74);
    }
    (**(code **)(param_1 + 0x18))(iVar3);
    *(undefined4 *)(param_2 + 0x74) = 0;
  }
  return;
}

/* FUN_0008df50 @ 0x8df50 (880 bytes) */
int FUN_0008df50(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
  char *param_4;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 *puVar13;
  int iVar14;
  undefined1 *puVar15;
  undefined4 uVar16;
  int iVar17;
  undefined4 uVar18;
  
  puVar15 = (undefined1 *)param_1[0x487];
  if ((*(int *)(puVar15 + 0x74) != 0) && (iVar4 = (*(code *)param_1[3])(0x78), iVar4 != 0)) {
    ((int (*)())FUN_0008dc50)(param_1,iVar4);
    iVar17 = *(int *)(iVar4 + 0x74);
    if (iVar17 == 0) {
      ((int (*)())FUN_0008dda0)(param_1,iVar4);
      (*(code *)param_1[6])(iVar4);
      *param_1 = 0x505;
    }
    else {
      iVar14 = param_1[1099];
      iVar5 = _strncmp(param_4,"!!ILfs1.0\n",10);
      if (iVar5 == 0) {
        *(undefined1 *)(iVar17 + 0x55) = 1;
        *(char **)(*(int *)(iVar4 + 0x74) + 0x58) = param_4;
        *(undefined4 *)(*(int *)(iVar4 + 0x74) + 0x5c) = param_3;
        *(undefined1 *)(*(int *)(iVar4 + 0x74) + 0x54) = 1;
      }
      else {
        *(undefined1 *)(iVar17 + 0x55) = 0;
        ((int (*)())FUN_0008c590)(param_1,*(undefined4 *)(iVar4 + 0x74),param_3,param_4);
        if (*(char *)(*(int *)(iVar4 + 0x74) + 0x54) == '\0') {
          ((int (*)())FUN_0008dda0)(param_1,iVar4);
          (*(code *)param_1[6])(iVar4);
          *param_1 = 0x502;
          return;
        }
      }
      param_1[0x487] = iVar4;
      *(int *)(param_1[0x49c] * 0x18 + *(int *)(iVar14 + 8) + 0x14) = iVar4;
      iVar17 = *(int *)(puVar15 + 0x74);
      *(undefined1 *)(iVar4 + 2) = *(undefined1 *)(iVar17 + 2);
      *(undefined1 *)(iVar4 + 1) = *(undefined1 *)(iVar17 + 1);
      iVar17 = (*(code *)param_1[0x49f])(param_1,1);
      if (iVar17 == 0) {
        *param_1 = 0x502;
      }
      iVar17 = param_1[0x49c] * 0x18 + *(int *)(param_1[1099] + 8);
      *(undefined4 *)(iVar17 + 8) = param_2;
      *(undefined4 *)(iVar17 + 0xc) = param_3;
      if (*(int *)(iVar17 + 0x10) != 0) {
        (*(code *)param_1[6])();
      }
      uVar6 = (*(code *)param_1[3])(param_3);
      *(undefined4 *)(iVar17 + 0x10) = uVar6;
      (*(code *)param_1[0x4d1])(uVar6,param_4,param_3);
      *(undefined4 *)(*(int *)(iVar4 + 0x74) + 0x58) = *(undefined4 *)(iVar17 + 0x10);
      param_1[0x487] = puVar15;
      *(undefined1 **)(param_1[0x49c] * 0x18 + *(int *)(iVar14 + 8) + 0x14) = puVar15;
      uVar7 = *(undefined4 *)(iVar4 + 0x70);
      uVar2 = *(undefined4 *)(iVar4 + 0x54);
      uVar16 = *(undefined4 *)(puVar15 + 0x70);
      uVar18 = *(undefined4 *)(puVar15 + 0x74);
      uVar6 = *(undefined4 *)(iVar4 + 0x50);
      uVar10 = *(undefined4 *)(iVar4 + 0x58);
      uVar12 = *(undefined4 *)(iVar4 + 0x5c);
      uVar11 = *(undefined4 *)(iVar4 + 0x60);
      uVar9 = *(undefined4 *)(iVar4 + 100);
      uVar8 = *(undefined4 *)(iVar4 + 0x68);
      uVar1 = *(undefined1 *)(iVar4 + 0x6c);
      *(undefined4 *)(puVar15 + 0x74) = *(undefined4 *)(iVar4 + 0x74);
      *(undefined4 *)(puVar15 + 0x70) = uVar7;
      *(undefined4 *)(puVar15 + 0x54) = uVar2;
      *(undefined4 *)(puVar15 + 0x50) = uVar6;
      *(undefined4 *)(puVar15 + 0x58) = uVar10;
      *(undefined4 *)(puVar15 + 0x5c) = uVar12;
      *(undefined4 *)(puVar15 + 0x60) = uVar11;
      *(undefined4 *)(puVar15 + 100) = uVar9;
      *(undefined4 *)(puVar15 + 0x68) = uVar8;
      puVar15[0x6c] = uVar1;
      *(undefined4 *)(iVar4 + 0x70) = uVar16;
      *(undefined4 *)(iVar4 + 0x74) = uVar18;
      ((int (*)())FUN_0008dda0)(param_1,iVar4);
      (*(code *)param_1[6])(iVar4);
      puVar13 = *(undefined1 **)(puVar15 + 0x74);
      puVar15[4] = puVar13[4];
      *puVar15 = *puVar13;
      puVar15[1] = puVar13[1];
      puVar15[2] = puVar13[2];
      puVar15[3] = puVar13[3];
      *(undefined4 *)(puVar15 + 8) = *(undefined4 *)(puVar13 + 0xc);
      *(undefined4 *)(puVar15 + 0xc) = *(undefined4 *)(puVar13 + 0x10);
      if (*(char *)((int)param_1 + 0x13b1) != '\0') {
        puVar3 = (undefined4 *)(puVar13 + 0x14);
        iVar4 = 0;
        do {
          uVar6 = *puVar3;
          iVar4 = iVar4 + 1;
          puVar3 = puVar3 + 1;
          *(undefined4 *)(puVar15 + 0x10) = uVar6;
          puVar15 = puVar15 + 4;
        } while (iVar4 < (int)(uint)*(byte *)((int)param_1 + 0x13b1));
      }
      ((int (*)())FUN_0008d470)(param_1);
      *(undefined1 *)(param_1 + 0x474) = 1;
    }
  }
  return;
}

/* FUN_0008e2e0 @ 0x8e2e0 (168 bytes) */
int FUN_0008e2e0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  void *param_4;
{
  size_t sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  char *pcVar5;
  
  sVar1 = param_3 * 4;
  pcVar5 = _malloc(sVar1 + 0xd);
  cVar4 = s___ILfs1_0_001a5d2c[0xc];
  uVar3 = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 8));
  uVar2 = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 4));
  *(undefined4 *)pcVar5 = (*(unsigned int *)((unsigned char *)&(s___ILfs1_0_001a5d2c) + 0));
  *(undefined4 *)(pcVar5 + 4) = uVar2;
  pcVar5[0xc] = cVar4;
  *(undefined4 *)(pcVar5 + 8) = uVar3;
  _memcpy(pcVar5 + 10,param_4,sVar1);
  pcVar5[sVar1 + 0xc] = '\0';
  ((int (*)())FUN_0008df50)(param_1,0x8875,sVar1 + 0xc,pcVar5);
  _free(pcVar5);
  return;
}

/* FUN_0008ebb0 @ 0x8ebb0 (4284 bytes) */
int FUN_0008ebb0(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
  float *pfVar14;
  float *pfVar15;
  int iVar16;
  float *pfVar17;
  int iVar18;
  float *pfVar19;
  float *pfVar20;
  double dVar21;
  double dVar22;
  undefined8 uVar23;
  float local_e8 [4];
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
  float local_a8 [14];
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  
  pfVar7 = param_3;
  uVar23 = FUN_001a3264();
  fVar1 = FLOAT_001aa0e8;
  iVar18 = *(int *)((int)uVar23 + 8);
  iVar13 = *(int *)((int)((ulonglong)uVar23 >> 0x20) + 4);
  iVar9 = *(int *)((int)uVar23 + 0xc);
  iVar16 = *(int *)(iVar13 + 0x10);
  switch(iVar18) {
  case 5:
    if (iVar9 == 0) {
      *pfVar7 = *(float *)(iVar16 + 0x28c0);
      pfVar7[1] = *(float *)(iVar16 + 0x28c4);
      pfVar7[2] = *(float *)(iVar16 + 0x28c8);
      pfVar7[3] = *(float *)(iVar16 + 0x28cc);
    }
    else {
      *pfVar7 = *(float *)(iVar16 + 0x2b00);
      pfVar7[1] = *(float *)(iVar16 + 0x2b04);
      pfVar7[2] = *(float *)(iVar16 + 0x2b08);
      pfVar7[3] = *(float *)(iVar16 + 0x2b0c);
    }
    break;
  case 6:
    if (iVar9 == 0) {
      *pfVar7 = *(float *)(iVar16 + 0x28d0);
      pfVar7[1] = *(float *)(iVar16 + 0x28d4);
      pfVar7[2] = *(float *)(iVar16 + 0x28d8);
      pfVar7[3] = *(float *)(iVar16 + 0x28dc);
    }
    else {
      *pfVar7 = *(float *)(iVar16 + 0x2b10);
      pfVar7[1] = *(float *)(iVar16 + 0x2b14);
      pfVar7[2] = *(float *)(iVar16 + 0x2b18);
      pfVar7[3] = *(float *)(iVar16 + 0x2b1c);
    }
    break;
  case 7:
    if (iVar9 == 0) {
      *pfVar7 = *(float *)(iVar16 + 0x28e0);
      pfVar7[1] = *(float *)(iVar16 + 0x28e4);
      pfVar7[2] = *(float *)(iVar16 + 0x28e8);
      pfVar7[3] = *(float *)(iVar16 + 0x28ec);
    }
    else {
      *pfVar7 = *(float *)(iVar16 + 0x2b20);
      pfVar7[1] = *(float *)(iVar16 + 0x2b24);
      pfVar7[2] = *(float *)(iVar16 + 0x2b28);
      pfVar7[3] = *(float *)(iVar16 + 0x2b2c);
    }
    break;
  case 8:
    if (iVar9 == 0) {
      *pfVar7 = *(float *)(iVar16 + 0x28f0);
      pfVar7[1] = *(float *)(iVar16 + 0x28f4);
      pfVar7[2] = *(float *)(iVar16 + 0x28f8);
      pfVar7[3] = *(float *)(iVar16 + 0x28fc);
    }
    else {
      *pfVar7 = *(float *)(iVar16 + 0x2b30);
      pfVar7[1] = *(float *)(iVar16 + 0x2b34);
      pfVar7[2] = *(float *)(((unsigned char *)0x00002b38) + iVar16);
      pfVar7[3] = *(float *)(((unsigned char *)0x00002b3c) + iVar16);
    }
    break;
  case 9:
    if (iVar9 == 0) {
      fVar1 = *(float *)(iVar16 + 0x2900);
    }
    else {
      fVar1 = *(float *)(((unsigned char *)0x00002b40) + iVar16);
    }
    *param_3 = fVar1;
    param_3[3] = 1.0;
    param_3[1] = 0.0;
    param_3[2] = 0.0;
    break;
  case 10:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x24c0);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24c4);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24c8);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24cc);
    break;
  case 0xb:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x24d0);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24d4);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24d8);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24dc);
    break;
  case 0xc:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x24e0);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24e4);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24e8);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24ec);
    break;
  case 0xd:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x24f0);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24f4);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24f8);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24fc);
    break;
  case 0xe:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x2510);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x2514);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x2518);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x251c);
    break;
  case 0xf:
    *pfVar7 = *(float *)(iVar9 * 0x80 + iVar16 + 0x2500);
    pfVar7[1] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x2504);
    pfVar7[2] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x2508);
    pfVar7[3] = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x250c);
    break;
  case 0x10:
    fVar2 = *(float *)(iVar9 * 0x80 + iVar16 + 0x24f0);
    *pfVar7 = fVar2;
    fVar3 = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24f4);
    pfVar7[1] = fVar3;
    fVar5 = *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24f8) + fVar1;
    pfVar7[2] = fVar5;
    dVar21 = (double)_sqrt((double)(fVar5 * fVar5 + fVar2 * fVar2 + fVar3 * fVar3));
    param_3[3] = fVar1;
    fVar1 = fVar1 / (float)dVar21;
    param_3[2] = fVar5 * fVar1;
    *param_3 = fVar1 * fVar2;
    param_3[1] = fVar3 * fVar1;
    break;
  case 0x11:
    *pfVar7 = *(float *)(iVar16 + 0x24b0);
    pfVar7[1] = *(float *)(iVar16 + 0x24b4);
    pfVar7[2] = *(float *)(iVar16 + 0x24b8);
    pfVar7[3] = *(float *)(iVar16 + 0x24bc);
    break;
  case 0x12:
    if (iVar9 == 0) {
      *pfVar7 = *(float *)(iVar16 + 0x24b0) * *(float *)(iVar16 + 0x28c0) +
                *(float *)(iVar16 + 0x28f0);
      pfVar7[1] = *(float *)(iVar16 + 0x24b4) * *(float *)(iVar16 + 0x28c4) +
                  *(float *)(iVar16 + 0x28f4);
      pfVar7[2] = *(float *)(iVar16 + 0x24b8) * *(float *)(iVar16 + 0x28c8) +
                  *(float *)(iVar16 + 0x28f8);
      pfVar7[3] = *(float *)(iVar16 + 0x28dc);
    }
    else {
      *pfVar7 = *(float *)(iVar16 + 0x24b0) * *(float *)(iVar16 + 0x2b00) +
                *(float *)(iVar16 + 0x2b30);
      pfVar7[1] = *(float *)(iVar16 + 0x24b4) * *(float *)(iVar16 + 0x2b04) +
                  *(float *)(iVar16 + 0x2b34);
      pfVar7[2] = *(float *)(iVar16 + 0x24b8) * *(float *)(iVar16 + 0x2b08) +
                  *(float *)(((unsigned char *)0x00002b38) + iVar16);
      pfVar7[3] = *(float *)(iVar16 + 0x2b1c);
    }
    break;
  case 0x13:
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28c0);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b00);
    }
    *param_3 = fVar1 * *(float *)(iVar9 * 0x80 + iVar16 + 0x24c0);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28c4);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b04);
    }
    param_3[1] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24c4);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28c8);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b08);
    }
    param_3[2] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24c8);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28cc);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b0c);
    }
    goto LAB_0008f398;
  case 0x14:
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28d0);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b10);
    }
    *param_3 = fVar1 * *(float *)(iVar9 * 0x80 + iVar16 + 0x24d0);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28d4);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b14);
    }
    param_3[1] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24d4);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28d8);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b18);
    }
    param_3[2] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24d8);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28dc);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b1c);
    }
    goto LAB_0008f398;
  case 0x15:
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28e0);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b20);
    }
    *param_3 = fVar1 * *(float *)(iVar9 * 0x80 + iVar16 + 0x24e0);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28e4);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b24);
    }
    param_3[1] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24e4);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28e8);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b28);
    }
    param_3[2] = fVar1 * *(float *)(*(int *)(param_2 + 0xc) * 0x80 + iVar16 + 0x24e8);
    if (*(int *)(param_2 + 0x10) == 0) {
      fVar1 = *(float *)(iVar16 + 0x28ec);
    }
    else {
      fVar1 = *(float *)(iVar16 + 0x2b2c);
    }
    goto LAB_0008f398;
  case 0x16:
    *pfVar7 = *(float *)(((unsigned char *)0x00002de0) + iVar16);
    pfVar7[1] = *(float *)(((unsigned char *)0x00002de4) + iVar16);
    pfVar7[2] = *(float *)(((unsigned char *)0x00002de8) + iVar16);
    pfVar7[3] = *(float *)(((unsigned char *)0x00002dec) + iVar16);
    break;
  case 0x17:
    *pfVar7 = *(float *)(((unsigned char *)0x00002df0) + iVar16);
    pfVar7[1] = *(float *)(((unsigned char *)0x00002df4) + iVar16);
    pfVar7[2] = *(float *)(((unsigned char *)0x00002df8) + iVar16);
    pfVar7[3] = *(float *)(((unsigned char *)0x00002dfc) + iVar16);
    break;
  case 0x18:
    *pfVar7 = (float)*(double *)(FUN_00001830 + iVar16);
    pfVar7[1] = (float)*(double *)(iVar16 + 0x1838);
    dVar22 = *(double *)(FUN_00001830 + iVar16);
    dVar21 = *(double *)(iVar16 + 0x1838);
    pfVar7[3] = 1.0;
    pfVar7[2] = (float)(dVar21 - dVar22);
    break;
  case 0x19:
    *pfVar7 = *(float *)(((unsigned char *)0x000031c4) + iVar9 * 0x7c + iVar16);
    pfVar7[1] = *(float *)(((unsigned char *)0x000031c8) + *(int *)(param_2 + 0xc) * 0x7c + *(int *)(iVar13 + 0x10))
    ;
    pfVar7[2] = *(float *)(((unsigned char *)0x000031cc) + *(int *)(param_2 + 0xc) * 0x7c + *(int *)(iVar13 + 0x10))
    ;
    fVar1 = *(float *)(((unsigned char *)0x000031d0) + *(int *)(param_2 + 0xc) * 0x7c + *(int *)(iVar13 + 0x10));
LAB_0008f398:
    param_3[3] = fVar1;
    break;
  case 0x1a:
  case 0x1b:
  case 0x1c:
  case 0x1d:
    iVar18 = iVar18 + -0x1a;
    iVar16 = iVar16 + iVar9 * 0x40 + 0x1960;
    goto LAB_0008f444;
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
    iVar16 = iVar16 + 0x1920;
    iVar18 = iVar18 + -0x1e;
    goto LAB_0008f444;
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
    iVar16 = iVar16 + 0x1860;
    iVar18 = iVar18 + -0x22;
    goto LAB_0008f444;
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
    iVar18 = iVar18 + -0x26;
    iVar16 = iVar16 + iVar9 * 0x40 + 0x1c60;
    goto LAB_0008f444;
  case 0x2e:
  case 0x2f:
  case 0x30:
  case 0x31:
    iVar18 = iVar18 + -0x2e;
    iVar16 = iVar16 + iVar9 * 0x40 + 0x1a60;
LAB_0008f444:
    iVar9 = 0;
    iVar13 = 0x10;
    pfVar7 = local_e8;
    do {
      iVar4 = iVar9 * 4;
      iVar9 = iVar9 + 1;
      *pfVar7 = *(float *)(iVar16 + iVar4);
      pfVar7 = pfVar7 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    iVar9 = *(int *)(param_2 + 0x10);
    if ((iVar9 == 1) || (iVar9 == 3)) {
      local_a8[4] = 1.0;
      local_a8[0xd] = 1.0;
      local_a8[1] = local_d8;
      local_a8[2] = local_c8;
      local_68 = local_e8[2];
      local_a8[0] = local_e8[0];
      local_a8[7] = FLOAT_001aa0d4;
      local_a8[6] = FLOAT_001aa0d4;
      local_a8[5] = FLOAT_001aa0d4;
      local_a8[8] = local_e8[1];
      local_6c = FLOAT_001aa0d4;
      local_a8[3] = local_b8;
      local_a8[9] = local_d4;
      local_a8[0xc] = FLOAT_001aa0d4;
      local_a8[10] = local_c4;
      local_a8[0xb] = local_b4;
      local_64 = local_d0;
      local_60 = local_c0;
      local_5c = local_b0;
      local_50 = 0x3f800000;
      local_4c = FLOAT_001aa0d4;
      local_2c = 0x3f800000;
      local_54 = FLOAT_001aa0d4;
      local_58 = FLOAT_001aa0d4;
      local_30 = FLOAT_001aa0d4;
      local_34 = FLOAT_001aa0d4;
      local_38 = FLOAT_001aa0d4;
      local_44 = local_cc;
      local_40 = local_bc;
      local_48 = local_e8[3];
      local_3c = local_ac;
      pfVar7 = &STACKARG(0xffffffb8);
      pfVar17 = &STACKARG(0xffffff98);
      if (ABS(local_e8[3]) <= ABS(local_e8[2])) {
        pfVar7 = &STACKARG(0xffffff98);
        pfVar17 = &STACKARG(0xffffffb8);
      }
      pfVar11 = local_a8 + 8;
      fVar1 = *pfVar7;
      if (ABS(*pfVar7) <= ABS(local_e8[1])) {
        pfVar11 = pfVar7;
        pfVar7 = local_a8 + 8;
        fVar1 = local_e8[1];
      }
      pfVar12 = local_a8;
      if (ABS(local_e8[0]) < ABS(fVar1)) {
        pfVar12 = pfVar7;
        pfVar7 = local_a8;
      }
      fVar1 = *pfVar12;
      if (fVar1 != FLOAT_001aa0d4) {
        fVar2 = pfVar12[1];
        pfVar10 = pfVar12 + 4;
        fVar3 = *pfVar7 / fVar1;
        fVar5 = *pfVar11 / fVar1;
        fVar1 = *pfVar17 / fVar1;
        pfVar7[1] = -(fVar3 * fVar2 - pfVar7[1]);
        pfVar11[1] = -(fVar5 * fVar2 - pfVar11[1]);
        pfVar17[1] = -(fVar1 * fVar2 - pfVar17[1]);
        fVar2 = pfVar12[2];
        pfVar7[2] = -(fVar3 * fVar2 - pfVar7[2]);
        pfVar11[2] = -(fVar5 * fVar2 - pfVar11[2]);
        pfVar17[2] = -(fVar1 * fVar2 - pfVar17[2]);
        fVar2 = pfVar12[3];
        pfVar7[3] = -(fVar3 * fVar2 - pfVar7[3]);
        pfVar11[3] = -(fVar5 * fVar2 - pfVar11[3]);
        pfVar17[3] = -(fVar1 * fVar2 - pfVar17[3]);
        fVar2 = pfVar12[4];
        if (fVar2 != FLOAT_001aa0d4) {
          pfVar7[4] = -(fVar3 * fVar2 - pfVar7[4]);
          pfVar11[4] = -(fVar5 * fVar2 - pfVar11[4]);
          pfVar17[4] = -(fVar1 * fVar2 - pfVar17[4]);
        }
        fVar2 = pfVar12[5];
        pfVar8 = pfVar12 + 5;
        if (fVar2 != FLOAT_001aa0d4) {
          pfVar7[5] = -(fVar3 * fVar2 - pfVar7[5]);
          pfVar11[5] = -(fVar5 * fVar2 - pfVar11[5]);
          pfVar17[5] = -(fVar1 * fVar2 - pfVar17[5]);
        }
        fVar2 = pfVar12[6];
        pfVar19 = pfVar12 + 6;
        if (fVar2 != FLOAT_001aa0d4) {
          pfVar7[6] = -(fVar3 * fVar2 - pfVar7[6]);
          pfVar11[6] = -(fVar5 * fVar2 - pfVar11[6]);
          pfVar17[6] = -(fVar1 * fVar2 - pfVar17[6]);
        }
        fVar2 = pfVar12[7];
        pfVar20 = pfVar12 + 7;
        if (fVar2 != FLOAT_001aa0d4) {
          pfVar7[7] = -(fVar3 * fVar2 - pfVar7[7]);
          pfVar11[7] = -(fVar5 * fVar2 - pfVar11[7]);
          pfVar17[7] = -(fVar1 * fVar2 - pfVar17[7]);
        }
        pfVar15 = pfVar11;
        if (ABS(pfVar11[1]) < ABS(pfVar17[1])) {
          pfVar15 = pfVar17;
          pfVar17 = pfVar11;
        }
        fVar1 = pfVar15[1];
        fVar2 = pfVar7[1];
        pfVar11 = pfVar7 + 1;
        pfVar14 = pfVar15;
        if (ABS(fVar2) < ABS(fVar1)) {
          pfVar11 = pfVar15 + 1;
          pfVar14 = pfVar7;
          pfVar7 = pfVar15;
          fVar2 = fVar1;
        }
        if (fVar2 != FLOAT_001aa0d4) {
          fVar3 = pfVar14[1] / fVar2;
          fVar2 = pfVar17[1] / fVar2;
          pfVar14[2] = -(fVar3 * pfVar7[2] - pfVar14[2]);
          pfVar17[2] = -(fVar2 * pfVar7[2] - pfVar17[2]);
          pfVar14[3] = -(fVar3 * pfVar7[3] - pfVar14[3]);
          pfVar17[3] = -(fVar2 * pfVar7[3] - pfVar17[3]);
          fVar1 = pfVar7[4];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[4] = -(fVar3 * fVar1 - pfVar14[4]);
            pfVar17[4] = -(fVar2 * fVar1 - pfVar17[4]);
          }
          fVar1 = pfVar7[5];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[5] = -(fVar3 * fVar1 - pfVar14[5]);
            pfVar17[5] = -(fVar2 * fVar1 - pfVar17[5]);
          }
          fVar1 = pfVar7[6];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[6] = -(fVar3 * fVar1 - pfVar14[6]);
            pfVar17[6] = -(fVar2 * fVar1 - pfVar17[6]);
          }
          fVar1 = pfVar7[7];
          if (fVar1 != FLOAT_001aa0d4) {
            pfVar14[7] = -(fVar3 * fVar1 - pfVar14[7]);
            pfVar17[7] = -(fVar2 * fVar1 - pfVar17[7]);
          }
          pfVar15 = pfVar14;
          if (ABS(pfVar14[2]) < ABS(pfVar17[2])) {
            pfVar15 = pfVar17;
            pfVar17 = pfVar14;
          }
          fVar1 = pfVar15[2];
          if (fVar1 != FLOAT_001aa0d4) {
            fVar1 = pfVar17[2] / fVar1;
            fVar2 = -(fVar1 * pfVar15[3] - pfVar17[3]);
            pfVar17[3] = fVar2;
            fVar3 = -(fVar1 * pfVar15[4] - pfVar17[4]);
            pfVar17[4] = fVar3;
            fVar6 = -(fVar1 * pfVar15[5] - pfVar17[5]);
            pfVar17[5] = fVar6;
            fVar5 = -(fVar1 * pfVar15[6] - pfVar17[6]);
            pfVar17[6] = fVar5;
            fVar1 = -(fVar1 * pfVar15[7] - pfVar17[7]);
            pfVar17[7] = fVar1;
            if (fVar2 != FLOAT_001aa0d4) {
              fVar2 = FLOAT_001aa0e8 / fVar2;
              fVar3 = fVar2 * fVar3;
              pfVar17[4] = fVar3;
              pfVar17[7] = fVar2 * fVar1;
              pfVar17[5] = fVar2 * fVar6;
              pfVar17[6] = fVar2 * fVar5;
              fVar1 = pfVar15[3];
              fVar2 = FLOAT_001aa0e8 / pfVar15[2];
              pfVar15[4] = fVar2 * -(fVar1 * fVar3 - pfVar15[4]);
              pfVar15[5] = fVar2 * -(fVar1 * pfVar17[5] - pfVar15[5]);
              pfVar15[6] = fVar2 * -(fVar1 * pfVar17[6] - pfVar15[6]);
              pfVar15[7] = fVar2 * -(fVar1 * pfVar17[7] - pfVar15[7]);
              fVar1 = pfVar7[3];
              pfVar7[4] = -(fVar1 * pfVar17[4] - pfVar7[4]);
              pfVar7[5] = -(fVar1 * pfVar17[5] - pfVar7[5]);
              pfVar7[6] = -(fVar1 * pfVar17[6] - pfVar7[6]);
              pfVar7[7] = -(fVar1 * pfVar17[7] - pfVar7[7]);
              fVar1 = pfVar12[3];
              *pfVar10 = -(fVar1 * pfVar17[4] - *pfVar10);
              *pfVar8 = -(fVar1 * pfVar17[5] - *pfVar8);
              *pfVar19 = -(fVar1 * pfVar17[6] - *pfVar19);
              *pfVar20 = -(fVar1 * pfVar17[7] - *pfVar20);
              fVar1 = pfVar7[2];
              fVar2 = FLOAT_001aa0e8 / *pfVar11;
              pfVar7[4] = fVar2 * -(fVar1 * pfVar15[4] - pfVar7[4]);
              pfVar7[5] = fVar2 * -(fVar1 * pfVar15[5] - pfVar7[5]);
              pfVar7[6] = fVar2 * -(fVar1 * pfVar15[6] - pfVar7[6]);
              pfVar7[7] = fVar2 * -(fVar1 * pfVar15[7] - pfVar7[7]);
              fVar1 = pfVar12[2];
              *pfVar10 = -(fVar1 * pfVar15[4] - *pfVar10);
              *pfVar8 = -(fVar1 * pfVar15[5] - *pfVar8);
              *pfVar19 = -(fVar1 * pfVar15[6] - *pfVar19);
              *pfVar20 = -(fVar1 * pfVar15[7] - *pfVar20);
              fVar1 = pfVar12[1];
              local_b8 = FLOAT_001aa0e8 / *pfVar12;
              *pfVar10 = local_b8 * -(fVar1 * pfVar7[4] - *pfVar10);
              *pfVar8 = local_b8 * -(fVar1 * pfVar7[5] - *pfVar8);
              *pfVar19 = local_b8 * -(fVar1 * pfVar7[6] - *pfVar19);
              local_b8 = local_b8 * -(fVar1 * pfVar7[7] - *pfVar20);
              *pfVar20 = local_b8;
              local_e8[0] = *pfVar10;
              local_d8 = *pfVar8;
              local_c8 = *pfVar19;
              local_e8[1] = pfVar7[4];
              local_d4 = pfVar7[5];
              local_c4 = pfVar7[6];
              local_b4 = pfVar7[7];
              local_e8[2] = pfVar15[4];
              local_d0 = pfVar15[5];
              local_c0 = pfVar15[6];
              iVar9 = *(int *)(param_2 + 0x10);
              local_b0 = pfVar15[7];
              local_e8[3] = pfVar17[4];
              local_cc = pfVar17[5];
              local_bc = pfVar17[6];
              local_ac = pfVar17[7];
              goto LAB_0008eb2c;
            }
          }
        }
        iVar9 = *(int *)(param_2 + 0x10);
      }
    }
LAB_0008eb2c:
    if (-1 < iVar9) {
      if (iVar9 < 2) {
        iVar9 = 0;
        iVar16 = 4;
        pfVar7 = local_e8 + iVar18;
        do {
          fVar1 = *pfVar7;
          pfVar7 = pfVar7 + 4;
          *(float *)(iVar9 + (int)param_3) = fVar1;
          iVar9 = iVar9 + 4;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
      }
      else if (iVar9 < 4) {
        iVar9 = 0;
        pfVar7 = local_e8 + iVar18 * 4;
        iVar16 = 4;
        do {
          fVar1 = *pfVar7;
          pfVar7 = pfVar7 + 1;
          *(float *)(iVar9 + (int)param_3) = fVar1;
          iVar9 = iVar9 + 4;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
      }
    }
    return;
  case 0x32:
    *(undefined8 *)pfVar7 = *(undefined8 *)(((unsigned char *)0x00001010) + iVar9 * 0x10 + iVar16);
    *(undefined8 *)(pfVar7 + 2) = *(undefined8 *)(((unsigned char *)0x00001010) + iVar9 * 0x10 + iVar16 + 8);
    break;
  case 0x33:
    iVar16 = *(int *)(**(int **)(*(int *)(iVar13 + 0x18) + 400) + 0x18);
    *(undefined8 *)pfVar7 = *(undefined8 *)(iVar9 * 0x10 + iVar16);
    *(undefined8 *)(pfVar7 + 2) = *(undefined8 *)(iVar9 * 0x10 + iVar16 + 8);
  }
  return;
}

/* FUN_0008f520 @ 0x8f520 (456 bytes) */
int FUN_0008f520(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = (*(unsigned char *)0x000011d0) + param_1;
  iVar4 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  *(undefined4 *)(((unsigned char *)0x0000126c) + param_1) = 1;
  *(undefined4 *)(((unsigned char *)0x00001220) + param_1) = 2;
  (**(code **)(((unsigned char *)0x00001274) + param_1))();
  ((unsigned char *)0x000011d3)[param_1] = 0;
  *(undefined4 *)(((unsigned char *)0x00001228) + param_1) = 0;
  if (((unsigned char *)0x000013b1)[param_1] != '\0') {
    iVar2 = 0;
    do {
      *(undefined4 *)(puVar5 + 0x5c) = 0;
      iVar2 = iVar2 + 1;
      puVar5 = puVar5 + 4;
    } while (iVar2 < (int)(uint)(byte)((unsigned char *)0x000013b1)[param_1]);
  }
  FUN_000a0350(param_1,*(int *)(((unsigned char *)0x0000126c) + param_1) * 0x18 + *(int *)(iVar4 + 8));
  *(undefined4 *)(*(int *)(((unsigned char *)0x0000126c) + param_1) * 0x18 + *(int *)(iVar4 + 8) + 4) = 0x8804;
  *(undefined4 *)(*(int *)(((unsigned char *)0x0000126c) + param_1) * 0x18 + *(int *)(iVar4 + 8)) = 0;
  iVar2 = *(int *)(((unsigned char *)0x0000126c) + param_1);
  iVar3 = *(int *)(iVar4 + 8);
  uVar1 = (**(code **)(param_1 + 0xc))(0x78);
  *(undefined4 *)(iVar2 * 0x18 + iVar3 + 0x14) = uVar1;
  ((int (*)())FUN_0008dc50)(param_1,*(undefined4 *)
                        (*(int *)(((unsigned char *)0x0000126c) + param_1) * 0x18 + *(int *)(iVar4 + 8) + 0x14));
  FUN_000a0350(param_1,*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 + *(int *)(iVar4 + 8));
  *(undefined4 *)(*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 + *(int *)(iVar4 + 8) + 4) = 0x8804;
  *(undefined4 *)(*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 + *(int *)(iVar4 + 8)) = 0;
  iVar2 = *(int *)(((unsigned char *)0x00001220) + param_1);
  iVar3 = *(int *)(iVar4 + 8);
  uVar1 = (**(code **)(param_1 + 0xc))(0x78);
  *(undefined4 *)(iVar2 * 0x18 + iVar3 + 0x14) = uVar1;
  ((int (*)())FUN_0008dc50)(param_1,*(undefined4 *)
                        (*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 + *(int *)(iVar4 + 8) + 0x14));
  return;
}

/* FUN_0008f6f0 @ 0x8f6f0 (108 bytes) */
int FUN_0008f6f0(param_1, param_2)
  int param_1;
  int param_2;
{
  void *pvVar1;
  void *pvVar2;
  int iVar3;
  
  iVar3 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  pvVar2 = *(void **)(param_2 + 0x70);
  pvVar1 = (void *)(**(code **)(param_1 + 0x10))(*(undefined4 *)(iVar3 + 0x10),4);
  *(void **)(param_2 + 0x70) = pvVar1;
  _memcpy(pvVar1,pvVar2,*(int *)(iVar3 + 0x10) * 4 - 4);
                    
                    
  (**(code **)(param_1 + 0x18))(pvVar2);
  return;
}

/* FUN_0008f760 @ 0x8f760 (144 bytes) */
int FUN_0008f760(param_1)
  int param_1;
{
  ((unsigned char *)0x000011d0)[param_1] = 1;
  *(int *)(((unsigned char *)0x00001270) + param_1) = *(int *)(((unsigned char *)0x0000126c) + param_1);
  *(undefined4 *)(((unsigned char *)0x0000121c) + param_1) =
       *(undefined4 *)
        (*(int *)(((unsigned char *)0x0000126c) + param_1) * 0x18 + *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 8)
        + 0x14);
  ((int (*)())FUN_0008c590)(param_1,*(undefined4 *)
                        (*(int *)(*(int *)(((unsigned char *)0x00001220) + param_1) * 0x18 +
                                  *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 8) + 0x14) + 0x74),
               0xf,"!!ARBfp1.0\nEND\n");
  ((int (*)())FUN_0008dbd0)(param_1,*(undefined4 *)(((unsigned char *)0x0000126c) + param_1));
  return;
}

/* FUN_0008f7f0 @ 0x8f7f0 (884 bytes) */
int FUN_0008f7f0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint *param_4;
{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  bool bVar11;
  float fVar12;
  float fVar13;
  code *pcVar14;
  undefined4 uVar15;
  int iVar16;
  undefined4 *puVar17;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  undefined1 auStack_f8 [144];
  undefined4 local_68;
  uint uStack_64;
  undefined4 local_60;
  uint uStack_5c;
  undefined4 local_58;
  uint uStack_54;
  undefined4 local_50;
  uint uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  longlong local_40;
  longlong local_38;
  
  iVar20 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  iVar16 = (**(code **)(param_1 + 0x2758))(param_1,10000);
  pcVar14 = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = iVar16;
  (*pcVar14)(param_1,iVar16);
  iVar19 = *(int *)(param_1 + 4);
  if (((((*(uint *)(iVar19 + 0x154) & 0x700000) == 0) || (*param_4 != 0)) || (param_4[1] != 0)) ||
     ((param_4[2] != *(uint *)(iVar19 + 0x15c) || (param_4[3] != *(uint *)(iVar19 + 0x160))))) {
    bVar11 = false;
    iVar19 = 0;
  }
  else {
    bVar11 = true;
    FUN_000a5c40(param_1,param_2);
    iVar19 = *(int *)(FUN_00002748 + param_1 + 4);
  }
  FUN_00086ba0(param_1,1,0,0,auStack_f8);
  uVar18 = 0x25;
  if (*(char *)(param_1 + 0x2802) != '\0') {
    uVar18 = 0x23;
  }
  puVar17 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,uVar18);
  cVar7 = *(char *)(param_1 + 0x2802);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar17;
  if (cVar7 == '\0') {
    puVar17[1] = 0x10000000;
    *puVar17 = 0x5c8;
    *(undefined1 *)(param_1 + 0x2802) = 1;
  }
  uVar18 = (**(code **)(param_1 + 0x2758))(param_1,0x23);
  *(undefined4 *)(FUN_00002748 + param_1 + 4) = uVar18;
  puVar17 = (undefined4 *)FUN_00083c90(param_1);
  if (bVar11) {
    *(int *)(iVar16 + 8) = (int)puVar17 - iVar16 >> 2;
  }
  local_68 = 0x43300000;
  local_60 = 0x43300000;
  local_58 = 0x43300000;
  local_50 = 0x43300000;
  uStack_4c = param_4[2] ^ 0x80000000;
  uStack_64 = param_4[1] ^ 0x80000000;
  uStack_5c = *param_4 ^ 0x80000000;
  uStack_54 = param_4[3] ^ 0x80000000;
  uStack_44 = *(undefined4 *)(param_1 + 8);
  uVar18 = *(undefined4 *)(((unsigned char *)0x00002dac) + iVar20);
  uVar8 = *(undefined4 *)(((unsigned char *)0x00002da0) + iVar20);
  uVar9 = *(undefined4 *)(((unsigned char *)0x00002da4) + iVar20);
  uVar10 = *(undefined4 *)(((unsigned char *)0x00002da8) + iVar20);
  local_48 = 0x43300000;
  fVar2 = (float)((double)CONCAT44(0x43300000,uStack_4c) - DOUBLE_001aa1e0);
  fVar3 = (float)((double)CONCAT44(0x43300000,uStack_64) - DOUBLE_001aa1e0);
  fVar4 = (float)((double)CONCAT44(0x43300000,uStack_54) - DOUBLE_001aa1e0);
  fVar5 = (float)((double)CONCAT44(0x43300000,uStack_5c) - DOUBLE_001aa1e0);
  fVar12 = (fVar5 + fVar2) * FLOAT_001aa10c;
  fVar13 = (fVar3 + fVar4) * FLOAT_001aa10c;
  fVar6 = (float)((double)CONCAT44(0x43300000,uStack_44) - DOUBLE_001aa250);
  uVar1 = (uint)(*(float *)(param_1 + 0x2818) * FLOAT_001aa10c * fVar6 * (fVar4 - fVar3));
  local_40 = (longlong)(int)uVar1;
  iVar20 = (int)(fVar6 * *(float *)(param_1 + 0x2814) * FLOAT_001aa10c * (fVar2 - fVar5));
  local_38 = (longlong)iVar20;
  puVar17[2] = 0x82c;
  *puVar17 = ((unsigned char *)0x00001087);
  puVar17[1] = iVar20 << 0x10 | uVar1 & 0xffff;
  uVar15 = *(undefined4 *)(param_1 + 0x1b84);
  puVar17[5] = 0x10031;
  puVar17[4] = 0xc0083500;
  puVar17[6] = fVar12;
  puVar17[7] = fVar13;
  puVar17[9] = 0x3f800000;
  puVar17[10] = uVar8;
  puVar17[0xb] = uVar9;
  puVar17[3] = uVar15;
  puVar17[0xc] = uVar10;
  puVar17[0xd] = uVar18;
  puVar17[0xe] = ((unsigned char *)0x00001087);
  puVar17[8] = 0;
  puVar17[0xf] = *(undefined4 *)(param_1 + 0x1ccc);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar17 + 0x10;
  (**(code **)(param_1 + 0x275c))(param_1,puVar17 + 0x10);
  FUN_0009d3b0(param_1);
  FUN_000872e0(param_1,auStack_f8);
  if (bVar11) {
    *(int *)(iVar16 + 4) = *(int *)(FUN_00002748 + param_1 + 4) - iVar19 >> 2;
  }
  return;
}

/* FUN_0008fb70 @ 0x8fb70 (248 bytes) */
int FUN_0008fb70(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  if (*(int *)(((unsigned char *)0x00003e28) + *(int *)(*(int *)(param_1 + 4) + 0x10)) != 0) {
    FUN_00086840();
  }
  iVar2 = *(int *)(param_1 + 0x1b7c);
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  if (*(char *)(param_1 + 0x1868) == '\0') {
    if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
      FUN_000651e0(param_1);
    }
  }
  else if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
    iVar1 = **(int **)(*(int *)(((unsigned char *)0x0000118c) + param_1) * 4 + **(int **)(((unsigned char *)0x00001168) + param_1));
    (**(code **)((int)((unsigned char *)0x00001294) + param_1))
              (param_1,iVar1 + 0x13c,*(undefined4 *)(iVar1 + 0x130));
  }
  FUN_0009d2e0(param_1);
  *(char *)(param_1 + 0x23ec) = '\x01' - (iVar2 == *(int *)(param_1 + 0x1b7c));
  return;
}

/* FUN_0008fc70 @ 0x8fc70 (1028 bytes) */
int FUN_0008fc70(param_1)
  int param_1;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  _memset((void *)(param_1 + 0x19c),-1,0x68);
  FUN_0004fc80(param_1,0,3,0,0,0,0,0);
  *(undefined4 *)(param_1 + 0x19c) = 0;
  if (*(int *)(param_1 + 0x44) < 0) {
    FUN_0004fc80(param_1,1,3,0,1,0,0,0);
    *(undefined4 *)(param_1 + 0x1a0) = 1;
    if ("}J3x})+x|B;x}k"[iVar4 + 3] == '\0') {
      uVar3 = *(uint *)(param_1 + 0x44);
      uVar5 = 2;
    }
    else {
      uVar5 = 3;
      FUN_0004fc80(param_1,2,3,0,2,0,0,0);
      uVar3 = *(uint *)(param_1 + 0x44);
      *(undefined4 *)(param_1 + 0x1a8) = 2;
    }
  }
  else {
    uVar5 = *(uint *)(param_1 + 0x8c);
    if (((uVar5 >> 0x14 & 1) == 0 && (uVar5 >> 0x1a & 1) == 0) && (uVar5 >> 0x1b & 1) == 0) {
      iVar7 = 1;
      uVar6 = 1;
      uVar5 = 2;
    }
    else {
      iVar7 = 2;
      uVar5 = 3;
      FUN_0004fc80(param_1,1,3,0,1,0,0,0);
      uVar6 = 2;
      *(undefined4 *)(param_1 + 0x1a0) = 1;
    }
    FUN_0004fc80(param_1,uVar6,3,0,uVar6,0,0,0);
    uVar3 = *(uint *)(param_1 + 0x44);
    *(undefined4 *)(param_1 + 0x1a8) = uVar6;
    if ((uVar3 & 0xa10000) != 0) {
      FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
      uVar3 = *(uint *)(param_1 + 0x44);
      *(uint *)(param_1 + 0x1ac) = uVar5;
      uVar5 = iVar7 + 2;
    }
  }
  if ((uVar3 & 0x20000) == 0) {
    uVar2 = (uint)*(byte *)(param_1 + 0x2b);
    if ((uint)(byte)((unsigned char *)0x000013b0)[param_1] < (uint)*(byte *)(param_1 + 0x2b)) {
      uVar2 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    }
    if (uVar2 == 0) goto LAB_0008ff78;
    uVar3 = 0;
    iVar7 = param_1;
    iVar8 = param_1;
    do {
      if ((((unsigned char *)0x00001438)[iVar8] != '\0') && (*(int *)(((unsigned char *)0x000013f8) + iVar7) != 0)) {
        FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
        *(uint *)(iVar7 + 0x1c8) = uVar5;
        uVar5 = uVar5 + 1;
      }
      uVar3 = uVar3 + 1;
      iVar8 = iVar8 + 1;
      iVar7 = iVar7 + 4;
    } while (uVar3 != uVar2);
  }
  else {
    if ((uVar3 & 0x2000) == 0) {
      bVar1 = ((unsigned char *)0x00001135)[param_1];
    }
    else {
      bVar1 = ((unsigned char *)0x000011d3)[param_1];
    }
    uVar2 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar2 == 0) goto LAB_0008ff78;
    uVar3 = 0;
    iVar7 = param_1;
    do {
      if (((uint)bVar1 & 1 << (uVar3 & 0x3f)) != 0) {
        FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
        uVar2 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
        *(uint *)(iVar7 + 0x1c8) = uVar5;
        uVar5 = uVar5 + 1;
      }
      uVar3 = uVar3 + 1;
      iVar7 = iVar7 + 4;
    } while ((int)uVar3 < (int)uVar2);
  }
  uVar3 = *(uint *)(param_1 + 0x44);
LAB_0008ff78:
  if (((uVar3 & 0x1000800) != 0) && (*(short *)(((unsigned char *)0x00002e06) + iVar4) == -0x7baf)) {
    FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
    *(uint *)(param_1 + 0x1ec) = uVar5;
    uVar5 = uVar5 + 1;
    *(undefined4 *)(param_1 + 0x1f0) = 0;
  }
  if (((unsigned char *)0x00004301)[iVar4] != '\0') {
    FUN_0004fc80(param_1,uVar5,3,0,uVar5,0,0,0);
    *(uint *)(param_1 + 0x1f8) = uVar5;
    uVar5 = uVar5 + 1;
  }
  uVar3 = uVar5 - 1;
  if ((uVar3 & 1) == 0) {
    iVar4 = (uVar3 * 2 & 0xfffffffc) + param_1;
    *(uint *)(iVar4 + 0x1be4) = *(uint *)(iVar4 + 0x1be4) | 0x2000;
  }
  else {
    iVar4 = (uVar3 * 2 & 0xfffffffc) + param_1;
    *(uint *)(iVar4 + 0x1be4) = *(uint *)(iVar4 + 0x1be4) | 0x20000000;
  }
  *(char *)(param_1 + 0x131) = (char)uVar5;
  *(uint *)(param_1 + 0x2430) = uVar5;
  *(uint *)(param_1 + 0x2438) = uVar5;
  *(undefined1 *)(param_1 + 0x2435) = 1;
  *(uint *)(param_1 + 0x243c) = uVar5;
  *(uint *)(param_1 + 0x1ca4) = (uVar5 & 0x1f) << 2 | *(uint *)(param_1 + 0x1ca4) & 0xffffff80;
  return;
}

/* FUN_000900a0 @ 0x900a0 (944 bytes) */
int FUN_000900a0(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  
  uVar9 = *(uint *)(param_1 + 0x1b9c);
  iVar11 = *(int *)(param_1 + 0x1ba0);
  iVar10 = *(int *)(param_1 + 0x1ca0);
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(char *)(param_1 + 0x1868) != '\0') && (*(char *)(param_1 + 0x124) != '\0')) {
    FUN_0004dbe0();
    return;
  }
  uVar8 = *(uint *)(param_1 + 0x44);
  *(undefined4 *)(param_1 + 0x1ca0) = 1;
  if ((int)uVar8 < 0) {
    *(undefined4 *)(param_1 + 0x1ca0) = 3;
    if ("}J3x})+x|B;x}k"[iVar5 + 3] != '\0') {
      *(undefined4 *)(param_1 + 0x1ca0) = 7;
    }
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x8c);
    if (((uVar1 >> 0x14 & 1) != 0 || (uVar1 >> 0x1a & 1) != 0) || (uVar1 >> 0x1b & 1) != 0) {
      *(undefined4 *)(param_1 + 0x1ca0) = 3;
    }
    uVar1 = *(uint *)(param_1 + 0x1ca0);
    *(uint *)(param_1 + 0x1ca0) = uVar1 | 4;
    if ((uVar8 & 0xa10000) != 0) {
      *(uint *)(param_1 + 0x1ca0) = uVar1 | 0xc;
    }
  }
  if (((uVar8 & 0x1000800) != 0) && (*(short *)(((unsigned char *)0x00002e06) + iVar5) == -0x7baf)) {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x40000;
  }
  if (((unsigned char *)0x00004301)[iVar5] != '\0') {
    *(uint *)(param_1 + 0x1ca0) = *(uint *)(param_1 + 0x1ca0) | 0x80000;
  }
  uVar1 = 3;
  *(undefined4 *)(param_1 + 0x1b9c) = 3;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  uVar4 = *(uint *)(param_1 + 0x44);
  if ((int)uVar4 < 0) {
    if (*(short *)("}J3x})+x|B;x}k" + iVar5) == -0x7e06) {
      *(undefined4 *)(param_1 + 0x1b9c) = 7;
    }
    if ("}J3x})+x|B;x}k"[iVar5 + 4] == '\0') {
      uVar1 = *(uint *)(param_1 + 0x1b9c);
    }
    else {
      uVar1 = *(uint *)(param_1 + 0x1b9c) | 0x1c;
      *(uint *)(param_1 + 0x1b9c) = uVar1;
    }
  }
  else if (((uVar4 >> 0x17 & 1) != 0 || (uVar4 >> 0x15 & 1) != 0) || (uVar4 >> 0x10 & 1) != 0) {
    uVar1 = 7;
    *(undefined4 *)(param_1 + 0x1b9c) = 7;
  }
  if ((*(uint *)(param_1 + 0xe8) & 1) != 0) {
    uVar1 = uVar1 | 0x10000;
    *(uint *)(param_1 + 0x1b9c) = uVar1;
  }
  if (((uVar8 & 0x1000000) != 0) && (*(char *)(param_1 + 0x121) == '\0')) {
    uVar1 = uVar1 | 4;
    *(uint *)(param_1 + 0x1b9c) = uVar1;
  }
  if ((uVar8 & 0x20000) == 0) {
    uVar8 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if ((uint)*(byte *)(param_1 + 0x2b) <= (uint)(byte)((unsigned char *)0x000013b0)[param_1]) {
      uVar8 = (uint)*(byte *)(param_1 + 0x2b);
    }
    if (uVar8 != 0) {
      iVar2 = 0;
      uVar4 = 0;
      iVar5 = param_1;
      iVar7 = param_1;
      do {
        if ((((unsigned char *)0x00001438)[iVar7] != '\0') && (*(int *)(((unsigned char *)0x000013f8) + iVar5) != 0)) {
          *(uint *)(param_1 + 0x1ba0) = 4 << (uVar4 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
          *(uint *)(param_1 + 0x1ca0) = 1 << (iVar2 + 10U & 0x3f) | *(uint *)(param_1 + 0x1ca0);
        }
        iVar2 = iVar2 + 1;
        uVar4 = uVar4 + 3;
        iVar7 = iVar7 + 1;
        iVar5 = iVar5 + 4;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
  }
  else {
    if ((uVar8 & 0x2000) == 0) {
      uVar4 = (uint)(byte)((unsigned char *)0x00001135)[param_1];
    }
    else {
      uVar4 = (uint)(byte)((unsigned char *)0x000011d3)[param_1];
      if ((uVar8 & 0x800) != 0) {
        *(uint *)(param_1 + 0x1ba0) =
             4 << ((uint)(byte)((unsigned char *)0x000011d1)[param_1] * 3 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
      }
      if ((uVar8 & 0x400) != 0) {
        *(uint *)(param_1 + 0x1ba0) =
             4 << ((uint)(byte)((unsigned char *)0x000011d2)[param_1] * 3 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
      }
    }
    uVar8 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar8 != 0) {
      uVar6 = 0;
      uVar3 = 0;
      if (uVar8 == 0) {
        uVar8 = 1;
      }
      do {
        if ((uVar4 & 1 << (uVar6 & 0x3f)) != 0) {
          *(uint *)(param_1 + 0x1ba0) = 4 << (uVar3 & 0x3f) | *(uint *)(param_1 + 0x1ba0);
          *(uint *)(param_1 + 0x1ca0) = 1 << (uVar6 + 10 & 0x3f) | *(uint *)(param_1 + 0x1ca0);
        }
        uVar6 = uVar6 + 1;
        uVar3 = uVar3 + 3;
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
  }
  if ((((uVar9 != uVar1) || (iVar11 != *(int *)(param_1 + 0x1ba0))) ||
      (iVar10 != *(int *)(param_1 + 0x1ca0))) || (*(char *)(param_1 + 299) != '\0')) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
    ((int (*)())FUN_0008fc70)(param_1);
    (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,1);
    *(undefined1 *)(param_1 + 299) = 0;
  }
  return;
}

/* FUN_00090470 @ 0x90470 (952 bytes) */
int FUN_00090470(param_1)
  int param_1;
{
  uint uVar1;
  
  if (*(char *)(param_1 + 0x1868) != '\0') {
    if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
      *(code **)(((unsigned char *)0x000012b4) + param_1) = FUN_000900a0;
    }
    else {
      *(undefined **)(((unsigned char *)0x000012b4) + param_1) = PTR_FUN_001e89ec;
    }
  }
  if ((*(uint *)(param_1 + 0x1808) & 0x20000000) != 0) {
    FUN_000a4980(param_1);
  }
  uVar1 = *(uint *)(param_1 + 0x38);
  if (uVar1 != 0) {
    if ((uVar1 & 4) != 0) {
      FUN_0004ea70(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 2) != 0) {
      FUN_0004eba0(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 8) != 0) {
      FUN_0004ed90(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 0x400) != 0) {
      FUN_000520c0(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 0x100) != 0) {
      FUN_0004f2e0(param_1);
      FUN_0009cf10(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 0x800) != 0) {
      FUN_0009cff0(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 0x4000) != 0) {
      FUN_0004f080(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((uVar1 & 0x2200) != 0) {
      FUN_0004def0(param_1);
      uVar1 = *(uint *)(param_1 + 0x38);
    }
    if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
      if ((uVar1 & 0x20000) != 0) {
        FUN_000867b0(param_1);
        uVar1 = *(uint *)(param_1 + 0x38);
      }
      if ((uVar1 & 0x20) != 0) {
        FUN_000bd9a0(param_1);
        uVar1 = *(uint *)(param_1 + 0x38);
      }
      if ((uVar1 & 0x1000) != 0) {
        if (*(char *)(param_1 + 0x1868) == '\0') {
          FUN_00064f40(param_1);
        }
        else {
          (**(code **)((int)((unsigned char *)0x000011cc) + param_1))(param_1);
        }
      }
    }
    else if ((uVar1 & 0x20) != 0) {
      FUN_0004d620(param_1);
    }
  }
  uVar1 = *(uint *)(param_1 + 0x3c);
  if (uVar1 != 0) {
    if ((uVar1 & 1) != 0) {
      FUN_0004dac0(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 2) != 0) {
      FUN_0004f550(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 8) != 0) {
      FUN_00051420(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 0x10) != 0) {
      FUN_0004ff70(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 0x20) != 0) {
      FUN_00051010(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 0x40) != 0) {
      FUN_00050140(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 0x400) != 0) {
      FUN_0004dc30(param_1);
      uVar1 = *(uint *)(param_1 + 0x3c);
    }
    if ((uVar1 & 0x1000) != 0) {
      FUN_000a5ec0(param_1);
    }
  }
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
    if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
      if ((((*(uint *)(param_1 + 0x38) & 0x4b928) != 0) || (*(short *)(param_1 + 0x34) != 0)) ||
         (*(char *)(param_1 + 299) != '\0')) {
        ((int (*)())FUN_000900a0)(param_1);
      }
    }
    else {
      FUN_0004dbe0(param_1);
    }
  }
  FUN_0004d100(param_1);
  FUN_00052280(param_1);
  *(undefined1 *)(param_1 + 0x2e) = 0;
  *(undefined1 *)(param_1 + 0x29) = 0;
  *(undefined2 *)(param_1 + 0x32) = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  *(undefined4 *)(param_1 + 0x1810) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x180c) = 0;
  return;
}

/* FUN_00090840 @ 0x90840 (264 bytes) */
int FUN_00090840(param_1)
  int param_1;
{
  uint uVar1;
  float fVar2;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar3;
  bool bVar4;
  
  fVar2 = FLOAT_001aa0e8;
  if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
    *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & 0xfffeffff;
    *(uint *)(param_1 + 0x1b84) = *(uint *)(param_1 + 0x1b84) & 0xfffffcff | 0x43f;
  }
  else {
    bVar4 = *(float *)(param_1 + 0x2814) != FLOAT_001aa0e8;
    uVar1 = *(uint *)(param_1 + 0x1b84) & 0xfffffbc0;
    *(uint *)(param_1 + 0x1b84) = uVar1 | 0x300;
    if ((bVar4) || (*(float *)(param_1 + 0x2818) != fVar2)) {
      *(uint *)(param_1 + 0x1b84) = uVar1 | 0x305;
    }
    *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) | 0x10000;
  }
  puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
  *puVar3 = 0x82c;
  *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_1 + 0x1b84);
  *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 8) = 0x887;
  *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 0xc) = *(undefined4 *)(param_1 + 0x1b74);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x10;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

/* FUN_00090960 @ 0x90960 (48 bytes) */
int FUN_00090960(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if (*(char *)(iVar1 + 0x20) == '\0') {
    return;
  }
  if ((*(uint *)(param_1 + 0x8c) & 0x40000000) == 0) {
    return;
  }
  *(undefined1 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x1cc) = 0;
  ((int (*)())FUN_00090840)();
  return;
}

/* FUN_00090990 @ 0x90990 (772 bytes) */
int FUN_00090990(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(iVar3 + 0x10);
  if ((*(int *)(((unsigned char *)0x00003e28) + iVar4) == 0) || (bVar1 = true, ((unsigned char *)0x000013a8)[param_1] != '\0')) {
    bVar1 = false;
  }
  if ((((((*(char *)(iVar3 + 0x21) != '\0') && ((param_2[3] & 0x10000000) == 0)) &&
        ((*(int *)(*(int *)(iVar3 + 0x18) + 0x198) == 0 || (*(int *)(iVar3 + 0x1cc) != 0)))) &&
       ((((unsigned char *)0x00004304)[iVar4] == '\0' || (*(int *)(iVar3 + 0x1cc) != 0)))) &&
      (("}J3x})+x|B;x}k"[iVar4 + 2] == '\0' || ("}J3x})+x|B;x}k"[iVar4 + 6] == '\0')))) && (!bVar1))
  {
    if (*(char *)(iVar3 + 0x20) == '\0') {
      *(undefined1 *)(iVar3 + 0x20) = 1;
      *(undefined1 *)(param_1 + 299) = 1;
      *(undefined1 *)(param_1 + 0x125) = 0;
      *(undefined1 *)(param_1 + 0x126) = 0;
      *(undefined1 *)(param_1 + 0x124) = 0;
      *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xbfffffff;
      param_2[4] = 0xffffffff;
      *param_2 = 0xffffffff;
      param_2[2] = param_2[2] | 0xfffffffd;
      param_2[1] = param_2[1] | 0x3ffffff;
      param_2[3] = param_2[3] | 0x7ffffff;
      *(undefined1 *)(param_1 + 0x2c) = 0xff;
      *(undefined4 *)(param_1 + 0x38) = 0x7ffff;
      *(undefined1 *)(param_1 + 0x2d) = 0xf;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(undefined2 *)(param_1 + 0x34) = 0xffff;
      *(undefined4 *)(param_1 + 0x3c) = 0x800015ff;
      *(undefined1 *)(param_1 + 0x2a) = 1;
      *(undefined4 *)(param_1 + 0x40) = 0x7ffff;
      *(undefined2 *)(param_1 + 0x32) = 0xffff;
      *(undefined1 *)(param_1 + 0x2e) = 3;
      *(undefined1 *)(param_1 + 0x30) = 7;
      *(undefined4 *)(param_1 + 0x180c) = 5;
      *(undefined4 *)(param_1 + 0x1810) = 0x1f;
      uVar2 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
      if (uVar2 != 0) {
        iVar3 = param_1;
        if (uVar2 == 0) {
          uVar2 = 1;
        }
        do {
          *(undefined1 *)(iVar3 + 0x1814) = 0x3f;
          *(undefined1 *)(iVar3 + 0x181c) = 3;
          iVar3 = iVar3 + 1;
          uVar2 = uVar2 - 1;
        } while (uVar2 != 0);
      }
      *(undefined1 *)(param_1 + 0x2803) = 1;
      *(undefined1 *)(param_1 + 0x23ec) = 1;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(undefined1 *)(param_1 + 0x247d) = 1;
      *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 7;
      return;
    }
    return;
  }
  if (*(char *)(iVar3 + 0x20) != '\0') {
    *(undefined1 *)(iVar3 + 0x20) = 0;
    *(undefined1 *)(param_1 + 299) = 1;
    *(undefined1 *)(param_1 + 0x126) = 1;
    *(undefined1 *)(param_1 + 0x124) = 1;
    *(undefined1 *)(param_1 + 0x125) = 0;
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x40000000;
    param_2[4] = 0xffffffff;
    *param_2 = 0xffffffff;
    param_2[2] = param_2[2] | 0xfffffffd;
    param_2[1] = param_2[1] | 0x3ffffff;
    param_2[3] = param_2[3] | 0x7ffffff;
    *(undefined1 *)(param_1 + 0x2c) = 0xff;
    *(undefined4 *)(param_1 + 0x38) = 0x7ffff;
    *(undefined1 *)(param_1 + 0x2d) = 0xf;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(undefined2 *)(param_1 + 0x34) = 0xffff;
    *(undefined4 *)(param_1 + 0x3c) = 0x800015ff;
    *(undefined1 *)(param_1 + 0x2a) = 1;
    *(undefined4 *)(param_1 + 0x40) = 0x7ffff;
    *(undefined2 *)(param_1 + 0x32) = 0xffff;
    *(undefined1 *)(param_1 + 0x2e) = 3;
    *(undefined1 *)(param_1 + 0x30) = 7;
    *(undefined4 *)(param_1 + 0x180c) = 5;
    *(undefined4 *)(param_1 + 0x1810) = 0x1f;
    uVar2 = (uint)(byte)((unsigned char *)0x000013b5)[param_1];
    if (uVar2 != 0) {
      iVar4 = param_1;
      if (uVar2 == 0) {
        uVar2 = 1;
      }
      do {
        *(undefined1 *)(iVar4 + 0x1814) = 0x3f;
        *(undefined1 *)(iVar4 + 0x181c) = 3;
        iVar4 = iVar4 + 1;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    *(undefined1 *)(param_1 + 0x2803) = 1;
    *(undefined1 *)(param_1 + 0x23ec) = 1;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(undefined1 *)(param_1 + 0x247d) = 1;
    *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 7;
  }
  *(undefined4 *)(iVar3 + 0x1cc) = 0;
  return;
}

/* FUN_00090ca0 @ 0x90ca0 (1240 bytes) */
int FUN_00090ca0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  *param_3 = param_2;
  if (param_2 == 1) {
    iVar6 = *(int *)(param_1 + 1000);
    if (iVar6 != 0) {
      uVar7 = 0;
      iVar5 = param_1;
      do {
        if (((*(char *)(iVar5 + 0x6c4) == '\0') && (*(char *)(iVar5 + 0x6c5) == '\0')) &&
           (*(char *)(iVar5 + 0x6c6) == '\0')) {
          param_3[1] = uVar7;
          iVar3 = DAT_001dbd90;
          iVar5 = DAT_001dbd8c;
          iVar6 = DAT_001dbd88;
          iVar4 = uVar7 * 4 + param_1;
          param_3[2] = DAT_001dbd84;
          param_3[5] = iVar3;
          param_3[3] = iVar6;
          param_3[4] = iVar5;
          iVar3 = DAT_001dbd80;
          iVar5 = DAT_001dbd7c;
          iVar6 = DAT_001dbd78;
          param_3[6] = DAT_001dbd74;
          param_3[9] = iVar3;
          param_3[7] = iVar6;
          param_3[8] = iVar5;
          *(undefined1 *)(iVar4 + 0x6c6) = 1;
          *(undefined1 *)(iVar4 + 0x6c4) = 1;
          *(undefined1 *)(iVar4 + 0x6c5) = 1;
          if (uVar7 < *(uint *)(param_1 + 0x3d0)) {
            return 0;
          }
          goto LAB_00090e50;
        }
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else if (param_2 == 0) {
    iVar6 = *(int *)(param_1 + 1000);
    if (iVar6 != 0) {
      uVar7 = 0;
      iVar5 = param_1;
      do {
        if (((*(char *)(iVar5 + 0x6c4) == '\0') && (*(char *)(iVar5 + 0x6c5) == '\0')) &&
           ((*(char *)(iVar5 + 0x6c6) == '\0' && (*(char *)(iVar5 + 0x6c7) == '\0')))) {
          param_3[1] = uVar7;
          iVar3 = DAT_001dbd30;
          iVar5 = DAT_001dbd2c;
          iVar6 = DAT_001dbd28;
          iVar4 = uVar7 * 4 + param_1;
          param_3[2] = DAT_001dbd24;
          param_3[5] = iVar3;
          param_3[3] = iVar6;
          param_3[4] = iVar5;
          iVar3 = DAT_001dbd20;
          iVar5 = DAT_001dbd1c;
          iVar6 = DAT_001dbd18;
          param_3[6] = DAT_001dbd14;
          param_3[9] = iVar3;
          param_3[7] = iVar6;
          param_3[8] = iVar5;
          *(undefined1 *)(iVar4 + 0x6c7) = 1;
          *(undefined1 *)(iVar4 + 0x6c4) = 1;
          *(undefined1 *)(iVar4 + 0x6c5) = 1;
          *(undefined1 *)(iVar4 + 0x6c6) = 1;
          if (uVar7 < *(uint *)(param_1 + 0x3d0)) {
            return 0;
          }
LAB_00090e50:
          *(uint *)(param_1 + 0x3d0) = uVar7 + 1;
          return 0;
        }
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 + 4;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
  }
  else {
    if (param_2 != 2) {
      return 4;
    }
    iVar6 = *(int *)(param_1 + 1000);
    if (iVar6 != 0) {
      uVar7 = 0;
      if (*(char *)(param_1 + 0x6c4) == '\0') {
LAB_00090e7c:
        param_3[1] = uVar7;
        iVar3 = DAT_001dbd10;
        iVar5 = DAT_001dbd0c;
        iVar6 = DAT_001dbd08;
        param_3[2] = DAT_001dbd04;
        param_3[5] = iVar3;
        param_3[3] = iVar6;
        param_3[4] = iVar5;
        iVar3 = DAT_001fa600;
        iVar5 = DAT_001fa5fc;
        iVar6 = DAT_001fa5f8;
        param_3[9] = DAT_001fa604;
        param_3[7] = iVar5;
        param_3[6] = iVar6;
        param_3[8] = iVar3;
        *(undefined1 *)(uVar7 * 4 + param_1 + 0x6c4) = 1;
        if (*(uint *)(param_1 + 0x3d0) <= uVar7) goto LAB_00091070;
      }
      else if (*(char *)(param_1 + 0x6c5) == '\0') {
LAB_00090efc:
        param_3[1] = uVar7;
        iVar3 = DAT_001dbd70;
        iVar5 = DAT_001dbd6c;
        iVar6 = DAT_001dbd68;
        param_3[2] = DAT_001dbd64;
        param_3[5] = iVar3;
        param_3[3] = iVar6;
        param_3[4] = iVar5;
        iVar3 = DAT_001dbcec;
        iVar5 = DAT_001dbce8;
        iVar6 = DAT_001dbce4;
        param_3[9] = DAT_001dbcf0;
        param_3[7] = iVar5;
        param_3[6] = iVar6;
        param_3[8] = iVar3;
        *(undefined1 *)(uVar7 * 4 + param_1 + 0x6c5) = 1;
        if (*(uint *)(param_1 + 0x3d0) <= uVar7) goto LAB_00091070;
      }
      else if (*(char *)(param_1 + 0x6c6) == '\0') {
LAB_00090f7c:
        param_3[1] = uVar7;
        iVar3 = DAT_001dbd60;
        iVar5 = DAT_001dbd5c;
        iVar6 = DAT_001dbd58;
        param_3[2] = DAT_001dbd54;
        param_3[5] = iVar3;
        param_3[3] = iVar6;
        param_3[4] = iVar5;
        iVar3 = DAT_001dbcfc;
        iVar5 = DAT_001dbcf8;
        iVar6 = DAT_001dbcf4;
        param_3[9] = DAT_001dbd00;
        param_3[7] = iVar5;
        param_3[6] = iVar6;
        param_3[8] = iVar3;
        *(undefined1 *)(uVar7 * 4 + param_1 + 0x6c6) = 1;
        if (*(uint *)(param_1 + 0x3d0) <= uVar7) {
LAB_00091070:
          *(uint *)(param_1 + 0x3d0) = uVar7 + 1;
          return 0;
        }
      }
      else {
        cVar2 = *(char *)(param_1 + 0x6c7);
        iVar5 = param_1;
        while (cVar2 != '\0') {
          uVar7 = uVar7 + 1;
          iVar6 = iVar6 + -1;
          if (iVar6 == 0) goto LAB_00091090;
          if (*(char *)(iVar5 + 0x6c8) == '\0') goto LAB_00090e7c;
          if (*(char *)(iVar5 + 0x6c9) == '\0') goto LAB_00090efc;
          if (*(char *)(iVar5 + 0x6ca) == '\0') goto LAB_00090f7c;
          pcVar1 = (char *)(iVar5 + 0x6cb);
          iVar5 = iVar5 + 4;
          cVar2 = *pcVar1;
        }
        param_3[1] = uVar7;
        iVar3 = DAT_001dbd50;
        iVar5 = DAT_001dbd4c;
        iVar6 = DAT_001dbd48;
        param_3[2] = DAT_001dbd44;
        param_3[5] = iVar3;
        param_3[3] = iVar6;
        param_3[4] = iVar5;
        iVar3 = DAT_001dbcdc;
        iVar5 = DAT_001dbcd8;
        iVar6 = DAT_001dbcd4;
        param_3[9] = DAT_001dbce0;
        param_3[7] = iVar5;
        param_3[6] = iVar6;
        param_3[8] = iVar3;
        *(undefined1 *)(uVar7 * 4 + param_1 + 0x6c7) = 1;
        if (*(uint *)(param_1 + 0x3d0) <= uVar7) goto LAB_00091070;
      }
      return 0;
    }
  }
LAB_00091090:
  param_3[1] = -1;
  iVar3 = DAT_001fa614;
  iVar5 = DAT_001fa610;
  iVar6 = DAT_001fa60c;
  param_3[2] = DAT_001fa608;
  param_3[5] = iVar3;
  param_3[3] = iVar6;
  param_3[4] = iVar5;
  iVar3 = DAT_001dbd40;
  iVar5 = DAT_001dbd3c;
  iVar6 = DAT_001dbd38;
  param_3[6] = DAT_001dbd34;
  param_3[9] = iVar3;
  param_3[7] = iVar6;
  param_3[8] = iVar5;
  return 7;
}

/* FUN_000911a0 @ 0x911a0 (316 bytes) */
int FUN_000911a0(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 == 1) {
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c4) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c5) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c6) = 0;
    return;
  }
  if (iVar1 == 0) {
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c4) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c5) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c6) = 0;
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c7) = 0;
    return;
  }
  if (iVar1 != 2) {
    return;
  }
  iVar1 = param_2[6];
  if (iVar1 != 1) {
    if (iVar1 == 0) {
      *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c4) = 0;
      return;
    }
    if (iVar1 != 2) {
      if (iVar1 != 3) {
        return;
      }
      *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c7) = 0;
      return;
    }
    *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c6) = 0;
    return;
  }
  *(undefined1 *)(param_2[1] * 4 + param_1 + 0x6c5) = 0;
  return;
}

/* FUN_000912f0 @ 0x912f0 (208 bytes) */
int FUN_000912f0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  int *param_5;
{
  uint uVar1;
  
  uVar1 = param_2 - 8;
  if (uVar1 < 2) {
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
    if (param_3 == 1) {
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2dc);
    }
    else if (param_3 == 0) {
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2d8);
    }
    else if (param_3 == 2) {
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2e0);
    }
    else {
      if (param_3 != 3) {
        return 4;
      }
      *param_5 = *(int *)(uVar1 * 0x24 + param_1 + 0x2ec);
    }
  }
  else {
    *param_4 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    *param_5 = *(int *)(param_2 * 4 + param_1 + 0xc);
  }
  return (uint)(*param_5 == -1) << 1;
}

/* FUN_000913e0 @ 0x913e0 (224 bytes) */
int FUN_000913e0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  undefined4 *param_3;
  int *param_4;
  undefined4 *param_5;
{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 < 2) {
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    *param_4 = *(int *)(param_1 + 0x58);
  }
  else {
    if (3 < param_2) {
      return 4;
    }
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
    *param_4 = *(int *)((param_2 & 1) * 4 + param_1 + 800);
  }
  uVar2 = 2;
  if (*param_4 != -1) {
    iVar1 = (param_2 & 1) * 4;
    uVar2 = 0;
    *param_5 = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
    param_5[1] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
    param_5[2] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
    param_5[3] = *(undefined4 *)((PTR_DAT_001dbdd4)[*(int *)(param_1 + 0x3d8)] + iVar1);
  }
  return uVar2;
}

/* FUN_000914c0 @ 0x914c0 (28 bytes) */
int FUN_000914c0()
{
  return;
}

/* FUN_000914e0 @ 0x914e0 (492 bytes) */
int FUN_000914e0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x3f8) == -1) {
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,param_1 + 0x3f4);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
      uVar5 = *(undefined4 *)(param_1 + 0x3f8);
      iVar2 = *(int *)(param_1 + 0xb4);
      (**(code **)(((unsigned char *)0x000012ec) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,iVar2,&DAT_001dbd14,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_000916d0 @ 0x916d0 (420 bytes) */
int FUN_000916d0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x3f8) == -1) {
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,param_1 + 0x3f4);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar5 = *(undefined4 *)(param_1 + 0x3f8);
      iVar2 = *(int *)(param_1 + 0xb4);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd04,uVar1,iVar2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd64,uVar1,iVar2 + 1,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd54,uVar1,iVar2 + 2,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd44,uVar1,iVar2 + 3,&DAT_001dbd14,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091880 @ 0x91880 (248 bytes) */
int FUN_00091880(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x510) == -1) {
    iVar4 = *(int *)(param_1 + 0x3f8);
    if (iVar4 == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar3) & 4) == 0) {
        ((int (*)())FUN_000916d0)();
      }
      else {
        ((int (*)())FUN_000914e0)();
      }
      iVar4 = *(int *)(param_1 + 0x3f8);
      if (iVar4 == -1) {
        return 2;
      }
    }
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x50c);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x510),
                 param_1 + 0x514,**(undefined4 **)(param_1 + 0x3ec),iVar4);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091980 @ 0x91980 (176 bytes) */
int FUN_00091980(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x6a0) == -1) {
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x69c);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x00001314) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x6a0),
                 param_1 + 0x6a4,param_2,param_3,&DAT_001dbcd4,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091a30 @ 0x91a30 (352 bytes) */
int FUN_00091a30(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x448) == -1) {
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x444);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8);
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar5 = *(undefined4 *)(param_1 + 0x448);
      iVar2 = *(int *)(param_1 + 0xc4);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd04,uVar1,iVar2,&DAT_001dbd74,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd64,uVar1,iVar2 + 1,&DAT_001dbd74,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uVar5,&DAT_001dbd54,uVar1,iVar2 + 2,&DAT_001dbd74,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00091b90 @ 0x91b90 (460 bytes) */
int FUN_00091b90(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [32];
  
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x498) != -1) {
    return 0;
  }
  if (*(char *)(iVar3 + 0x12a) == '\0') {
    iVar4 = *(int *)(param_1 + 4);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
    iVar1 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x494);
    if (iVar1 != 0) {
      return 7;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 0x448);
    if (iVar4 == -1) {
      ((int (*)())FUN_00091a30)();
      iVar4 = *(int *)(param_1 + 0x448);
      if (iVar4 == -1) {
        return 2;
      }
    }
    uVar2 = **(undefined4 **)(param_1 + 0x3ec);
    _memcpy((void *)(param_1 + 0x494),(void *)(param_1 + 0x444),0x28);
  }
  iVar1 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_68);
  if (iVar1 != 0) {
    return 7;
  }
  uVar7 = **(undefined4 **)(param_1 + 0x3f0);
  uVar5 = **(undefined4 **)(param_1 + 0x3ec);
  uVar6 = *(undefined4 *)(param_1 + 0x498);
  (**(code **)(((unsigned char *)0x000012e4) + iVar3))
            (param_1,uVar7,local_64,auStack_60,uVar2,iVar4,&DAT_001dbd74,&DAT_001fa5e8);
  (**(code **)(((unsigned char *)0x00001318) + iVar3))
            (param_1,uVar7,local_64,auStack_60,uVar5,local_64,auStack_50,&DAT_001fa5e8);
  (**(code **)(((unsigned char *)0x000012ec) + iVar3))
            (param_1,uVar7,uVar6,&DAT_001dbd84,uVar5,local_64,auStack_50,&DAT_001fa5e8);
  ((int (*)())FUN_000911a0)(param_1,auStack_68);
  return 0;
}

/* FUN_00091d70 @ 0x91d70 (300 bytes) */
int FUN_00091d70(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x470) == -1) {
    if (*(char *)(iVar2 + 0x12a) == '\0') {
      iVar1 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x46c);
      if (iVar1 != 0) {
        return 7;
      }
    }
    else {
      if ((*(int *)(param_1 + 0x448) == -1) && (((int (*)())FUN_00091a30)(), *(int *)(param_1 + 0x448) == -1)) {
        return 2;
      }
      _memcpy((void *)(param_1 + 0x46c),(void *)(param_1 + 0x444),0x28);
    }
    (**(code **)(((unsigned char *)0x000012ec) + iVar2))
              (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x470),
               &DAT_001dbd84,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 8),
               *(undefined4 *)(param_1 + 0x344),&DAT_001fa5f8);
  }
  return 0;
}

/* FUN_00091eb0 @ 0x91eb0 (648 bytes) */
int FUN_00091eb0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  
  uVar1 = 0;
  iVar6 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x560) == -1) {
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,param_1 + 0x55c);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar5 = *(undefined4 *)(param_1 + 0x560);
      uVar3 = *(undefined4 *)(param_1 + 0x5c);
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4);
      if (param_2 < 4) {
        if (param_3 == 0) {
          (**(code **)(((unsigned char *)0x000012e8) + iVar6))
                    (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,uVar3,&DAT_001dbd74,&DAT_001fa5e8);
          uVar1 = 0;
        }
        else {
          local_58 = DAT_001fa608;
          local_48 = DAT_001dbd74;
          local_54 = DAT_001fa60c;
          local_4c = DAT_001fa614;
          local_50 = DAT_001fa610;
          local_3c = DAT_001dbd80;
          local_44 = DAT_001dbd78;
          local_40 = DAT_001dbd7c;
          if (param_2 == 1) {
            local_40 = 4;
            local_44 = 4;
            local_54 = 1;
          }
          else if (param_2 == 0) {
            local_40 = 4;
            local_58 = 1;
            local_48 = 4;
            local_44 = 4;
          }
          else if (param_2 == 2) {
            local_50 = 1;
            local_40 = 4;
          }
          else if (param_2 == 3) {
            local_4c = 1;
          }
          local_30 = 1;
          local_38 = 1;
          local_34 = 1;
          local_2c = 0;
          (**(code **)(((unsigned char *)0x000012e8) + iVar6))
                    (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,uVar3,&local_48,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar6))
                    (param_1,uVar4,uVar5,&local_58,**(undefined4 **)(param_1 + 0x3ec),uVar5,
                     &DAT_001dbdb4,&local_38);
          uVar1 = 0;
        }
      }
      else {
        (**(code **)(((unsigned char *)0x000012e8) + iVar6))
                  (param_1,uVar4,uVar5,&DAT_001dbd24,uVar1,uVar3,&DAT_001dbd14,&DAT_001fa5e8);
        uVar1 = 0;
      }
    }
  }
  return uVar1;
}

/* FUN_00092150 @ 0x92150 (200 bytes) */
int FUN_00092150(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x538) == -1) {
    iVar4 = *(int *)(param_1 + 0x510);
    if (iVar4 == -1) {
      ((int (*)())FUN_00091880)();
      iVar4 = *(int *)(param_1 + 0x510);
      if (iVar4 == -1) {
        return 2;
      }
    }
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x534);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x00001318) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x538),
                 param_1 + 0x53c,**(undefined4 **)(param_1 + 0x3ec),iVar4,param_1 + 0x524,
                 &DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00092220 @ 0x92220 (296 bytes) */
int FUN_00092220(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x420) != -1) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0x538);
  if (iVar4 == -1) {
    ((int (*)())FUN_00092150)();
    iVar4 = *(int *)(param_1 + 0x538);
    if (iVar4 != -1) goto LAB_0009226c;
LAB_00092320:
    uVar1 = 2;
  }
  else {
LAB_0009226c:
    if (*(int *)(param_1 + 0x3f8) == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar3) & 4) == 0) {
        ((int (*)())FUN_000916d0)(param_1);
      }
      else {
        ((int (*)())FUN_000914e0)(param_1);
      }
      if (*(int *)(param_1 + 0x3f8) == -1) goto LAB_00092320;
    }
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x41c);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x000012ec) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x420),
                 &DAT_001dbd84,**(undefined4 **)(param_1 + 0x3ec),iVar4,param_1 + 0x54c);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_00092350 @ 0x92350 (512 bytes) */
int FUN_00092350(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [40];
  
  iVar2 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x4c0) != -1) {
    return 0;
  }
  iVar3 = *(int *)(param_1 + 0x420);
  if (iVar3 == -1) {
    ((int (*)())FUN_00092220)();
    iVar3 = *(int *)(param_1 + 0x420);
    if (iVar3 == -1) {
      return 2;
    }
  }
  if (*(char *)(iVar2 + 0x128) == '\0') {
    if (*(char *)(iVar2 + 300) == '\0') {
      if (*(int *)(param_1 + 0x448) != -1) goto LAB_00092420;
      ((int (*)())FUN_00091a30)(param_1);
      iVar4 = *(int *)(param_1 + 0x448);
    }
    else {
      if (*(int *)(param_1 + 0x470) != -1) goto LAB_00092420;
      ((int (*)())FUN_00091d70)(param_1);
      iVar4 = *(int *)(param_1 + 0x470);
    }
  }
  else {
    if (*(int *)(param_1 + 0x498) != -1) goto LAB_00092420;
    ((int (*)())FUN_00091b90)(param_1);
    iVar4 = *(int *)(param_1 + 0x498);
  }
  if (iVar4 == -1) {
    return 2;
  }
LAB_00092420:
  iVar4 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x4bc);
  if (iVar4 == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x4c0);
    iVar4 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_68);
    if (iVar4 == 0) {
      uVar6 = **(undefined4 **)(param_1 + 0x3ec);
      uVar5 = **(undefined4 **)(param_1 + 0x3f0);
      (**(code **)(((unsigned char *)0x000012e4) + iVar2))
                (param_1,uVar5,local_64,auStack_60,uVar6,iVar3,&DAT_001dbd74,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012f8) + iVar2))
                (param_1,uVar5,uVar1,&DAT_001dbd84,uVar6,local_64,auStack_50,&DAT_001fa5e8);
      ((int (*)())FUN_000911a0)(param_1,auStack_68);
      return 0;
    }
  }
  return 7;
}

/* FUN_00092570 @ 0x92570 (796 bytes) */
int FUN_00092570(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [4];
  undefined4 local_a4;
  undefined1 auStack_a0 [16];
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  undefined1 auStack_78 [16];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_5c;
  
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x4e8) == -1) {
    if ((*(int *)(param_1 + 0x4c0) == -1) && (((int (*)())FUN_00092350)(), *(int *)(param_1 + 0x4c0) == -1)) {
      return 2;
    }
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,1,param_1 + 0x4e4);
    if (iVar2 == 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x4e8);
      iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_a8);
      if (iVar2 == 0) {
        iVar2 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_80);
        if (iVar2 == 0) {
          uVar5 = **(undefined4 **)(param_1 + 0x3ec);
          uVar4 = **(undefined4 **)(param_1 + 0x3f0);
          (**(code **)(((unsigned char *)0x000012f0) + iVar3))
                    (param_1,uVar4,local_a4,auStack_a0,uVar5,local_a4,&DAT_001dbdb4,&DAT_001fa5e8);
          local_d8 = 4;
          local_d4 = 4;
          local_cc = 4;
          local_d0 = local_88;
          (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                    (param_1,uVar4,uVar1,&DAT_001dbd84,uVar5,local_a4,&local_90,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                    (param_1,uVar4,local_a4,auStack_a0,uVar5,uVar1,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + iVar3))
                    (param_1,uVar4,local_a4,auStack_a0,uVar5,local_a4,&local_90,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x0000131c) + iVar3))
                    (param_1,uVar4,local_7c,auStack_78,uVar5,local_7c,&DAT_001dbdb4,&DAT_001dbd94);
          local_c8 = *(undefined4 *)(param_1 + 0x4d4);
          local_c4 = *(undefined4 *)(param_1 + 0x4d8);
          local_b0 = 4;
          local_d0 = 4;
          local_cc = 4;
          local_d8 = local_90;
          local_d4 = local_8c;
          local_c0 = 4;
          local_bc = 4;
          local_b8 = local_68;
          local_b4 = local_64;
          local_ac = local_5c;
          (**(code **)(((unsigned char *)0x000012f4) + iVar3))
                    (param_1,uVar4,uVar1,&DAT_001dbd84,uVar5,local_a4,&local_d8,&DAT_001fa5e8);
          ((int (*)())FUN_000911a0)(param_1,auStack_a8);
          ((int (*)())FUN_000911a0)(param_1,auStack_80);
          return 0;
        }
      }
    }
    uVar1 = 7;
  }
  return uVar1;
}

/* FUN_000928a0 @ 0x928a0 (792 bytes) */
int FUN_000928a0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  undefined1 auStack_68 [4];
  undefined4 local_64;
  undefined1 auStack_60 [16];
  undefined1 auStack_50 [32];
  
  uVar4 = 0;
  iVar10 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x588) == -1) {
    puVar2 = *(undefined4 **)(param_1 + 0x3ec);
    uVar4 = *(undefined4 *)(param_1 + 0x330);
    uVar8 = **(undefined4 **)(param_1 + 0x3f0);
    uVar6 = puVar2[2];
    if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(iVar10 + 4) + 0x10)) == -0x7bae) {
      iVar3 = *(int *)(param_1 + 0x3f8);
      if (iVar3 == -1) {
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar10) & 4) == 0) {
          ((int (*)())FUN_000916d0)();
        }
        else {
          ((int (*)())FUN_000914e0)();
        }
        iVar3 = *(int *)(param_1 + 0x3f8);
        if (iVar3 == -1) {
          return 2;
        }
        puVar2 = *(undefined4 **)(param_1 + 0x3ec);
      }
      uVar9 = *puVar2;
      puVar2 = &DAT_001dbcf4;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x54);
      uVar9 = puVar2[1];
      iVar3 = *(int *)(param_1 + 0x50);
      if (iVar1 == 1) {
        puVar2 = &DAT_001dbce4;
      }
      else if (iVar1 == 0) {
        puVar2 = &DAT_001fa5f8;
      }
      else if (iVar1 == 2) {
        puVar2 = &DAT_001dbcf4;
      }
      else if (iVar1 == 3) {
        puVar2 = &DAT_001dbcd4;
      }
      else {
        puVar2 = &DAT_001dbd14;
      }
    }
    iVar1 = ((int (*)())FUN_00090ca0)(param_1,2,param_1 + 0x584);
    if (iVar1 == 0) {
      uVar7 = *(undefined4 *)(param_1 + 0x588);
      iVar1 = ((int (*)())FUN_00090ca0)(param_1,2,auStack_68);
      if (iVar1 == 0) {
        iVar5 = *(int *)(param_1 + 0x3d4);
        iVar1 = *(int *)(*(int *)(iVar5 + 4) + 0x10);
        if ((*(short *)(((unsigned char *)0x00002e06) + iVar1) == -0x7bae) &&
           (*(short *)(((unsigned char *)0x00002e08) + iVar1) == -0x7aa5)) {
          (**(code **)(((unsigned char *)0x000012e4) + iVar5))(param_1,uVar8,local_64,auStack_60,uVar9,iVar3);
        }
        else {
          (**(code **)(((unsigned char *)0x000012ec) + iVar5))(param_1,uVar8,local_64,auStack_60,uVar9,iVar3,puVar2)
          ;
        }
        uVar9 = **(undefined4 **)(param_1 + 0x3ec);
        (**(code **)(((unsigned char *)0x000012ec) + iVar10))
                  (param_1,uVar8,local_64,auStack_60,uVar6,uVar4,&DAT_001dbcf4);
        if (*(int *)(param_1 + 0x3d8) == 0) {
          puVar2 = (undefined4 *)(param_1 + 0x58c);
          if (-1 < *(int *)(iVar10 + 0x44)) {
            uVar7 = *(undefined4 *)(param_1 + 0x70);
            puVar2 = &DAT_001dbd44;
            uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
          }
        }
        else {
          uVar7 = *(undefined4 *)(param_1 + 0x70);
          puVar2 = &DAT_001dbd04;
          uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18);
        }
        (**(code **)(((unsigned char *)0x00001320) + iVar10))
                  (param_1,uVar8,uVar7,puVar2,uVar9,local_64,auStack_50,&DAT_001fa5e8);
        ((int (*)())FUN_000911a0)(param_1,auStack_68);
        return 0;
      }
    }
    uVar4 = 7;
  }
  return uVar4;
}

/* FUN_00092bf0 @ 0x92bf0 (328 bytes) */
int FUN_00092bf0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  void *pvVar1;
  
  pvVar1 = (void *)0x0;
  if (param_2 < 3) {
    pvVar1 = (void *)(**(code **)(param_1 + 0xc))(0x1998);
    *(int *)((int)pvVar1 + 0x3d4) = param_1;
    _memset(pvVar1,-1,0x68);
    _memset((void *)((int)pvVar1 + 0x68),-1,0x3c);
    _memset((void *)((int)pvVar1 + 0xa4),-1,0x324);
    *(uint *)((int)pvVar1 + 0x3d8) = param_2;
    *(undefined4 *)((int)pvVar1 + 0x3e0) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3c8) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3cc) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3d0) = 0;
    *(undefined4 *)((int)pvVar1 + 0x3e4) = *(undefined4 *)(&DAT_001dbeac + param_2 * 4);
    *(undefined4 *)((int)pvVar1 + 1000) = *(undefined4 *)(&DAT_001dbea4 + param_2 * 4);
    *(undefined **)((int)pvVar1 + 0x3ec) = (PTR_DAT_001dbe84)[param_2];
    *(undefined **)((int)pvVar1 + 0x3f0) = (PTR_DAT_001dbe3c)[param_2];
    _memset((void *)((int)pvVar1 + 0x3f4),-1,0x2d0);
    _memset((void *)((int)pvVar1 + 0x6c4),0,0x80);
    *(undefined1 *)((int)pvVar1 + 0x744) = param_3;
    *(code **)((int)pvVar1 + 0x748) = FUN_00090ca0;
    *(code **)((int)pvVar1 + 0x74c) = FUN_000911a0;
    if (*(code **)(((unsigned char *)0x000012d4) + param_1) != (code *)0x0) {
      (**(code **)(((unsigned char *)0x000012d4) + param_1))(param_1,pvVar1);
    }
  }
  return pvVar1;
}

/* FUN_00092d40 @ 0x92d40 (340 bytes) */
int FUN_00092d40(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint param_3;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if ((param_1[0x1a] != -1) && (iVar3 = *param_1, iVar3 != -1)) {
    if (param_2 != 0) {
      if (7 < param_3) {
        return 3;
      }
      if (param_1[param_3 + 0x21] == -1) {
        return 2;
      }
    }
    iVar1 = param_1[0xf5];
    uVar2 = *(undefined4 *)(param_1[0xfb] + 4);
    (**(code **)(((unsigned char *)0x000012e8) + iVar1))
              (param_1,*(undefined4 *)(param_1[0xfc] + 8),param_1[0x1a],&DAT_001dbd24,uVar2,iVar3,
               &DAT_001dbd14,&DAT_001fa5e8);
    if (((*(char *)(param_1 + 0x1d1) == '\0') || (param_1[0x1a8] != -1)) ||
       (((int (*)())FUN_00091980)(param_1,uVar2,iVar3), param_1[0x1a8] != -1)) {
      if (param_2 != 0) {
        (**(code **)(((unsigned char *)0x000012e8) + iVar1))
                  (param_1,*(undefined4 *)(param_1[0xfc] + 0x14),param_1[param_3 + 0x21],
                   &DAT_001dbd24,uVar2,iVar3,&DAT_001dbd14,&DAT_001fa5e8);
      }
      return 0;
    }
  }
  return 2;
}

/* FUN_00092ea0 @ 0x92ea0 (324 bytes) */
int FUN_00092ea0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  if (param_1 == 0) {
    return 1;
  }
  if (param_2 == 3) {
    if (1 < param_4) {
      return 3;
    }
    iVar3 = *(int *)(param_4 * 4 + param_1 + 0x74);
    if ((iVar3 == -1) || (iVar5 = *(int *)(param_3 * 4 + param_1 + 0xc), iVar5 == -1)) {
      return 2;
    }
    iVar1 = *(int *)(param_1 + 0x3d8);
    iVar6 = *(int *)(param_1 + 0x3d4);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0xc);
  }
  else {
    if (1 < param_4) {
      return 3;
    }
    iVar3 = *(int *)(param_4 * 4 + param_1 + 0x7c);
    if (iVar3 == -1) {
      return 2;
    }
    iVar5 = *(int *)(param_3 * 4 + param_1 + 0xc);
    if (iVar5 == -1) {
      return 2;
    }
    iVar1 = *(int *)(param_1 + 0x3d8);
    iVar6 = *(int *)(param_1 + 0x3d4);
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x10);
  }
  if ((iVar1 == 0) && (iVar3 == *(int *)(param_1 + 0x70))) {
    puVar4 = &DAT_001dbd84;
  }
  else {
    puVar4 = &DAT_001dbd24;
  }
  (**(code **)(((unsigned char *)0x000012e8) + iVar6))
            (param_1,uVar2,iVar3,puVar4,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),iVar5,
             &DAT_001dbd14,&DAT_001fa5e8);
  return 0;
}

/* FUN_00093000 @ 0x93000 (288 bytes) */
int FUN_00093000(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return 1;
  }
  if (7 < param_2) {
    return 3;
  }
  iVar2 = param_2 * 4 + param_1;
  iVar3 = *(int *)(iVar2 + 0x84);
  if (((iVar3 != -1) && (iVar2 = *(int *)(iVar2 + 0x2c), iVar2 != -1)) &&
     ((bVar1 = *(char *)(param_1 + 0x744) == '\0', bVar1 || (*(int *)(param_1 + 0xa4) != -1)))) {
    if (bVar1) {
      (**(code **)(((unsigned char *)0x000012e8) + *(int *)(param_1 + 0x3d4)))();
      return 0;
    }
    if (*(int *)(param_1 + 0x6a0) != -1) {
      (**(code **)(((unsigned char *)0x000012ec) + *(int *)(param_1 + 0x3d4)))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x14),iVar3,&DAT_001dbd24,
                 *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),iVar2,&DAT_001dbd14);
      return 0;
    }
  }
  return 2;
}

/* FUN_00093130 @ 0x93130 (168 bytes) */
int FUN_00093130(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0x6c) == -1) || (*(int *)(param_1 + 0x4c) == -1)) {
      uVar1 = 2;
    }
    else {
      (**(code **)(((unsigned char *)0x000012e8) + *(int *)(param_1 + 0x3d4)))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x1c),*(int *)(param_1 + 0x6c),
                 &DAT_001dbd24,*(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),
                 *(int *)(param_1 + 0x4c),&DAT_001fa5f8,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* FUN_000931e0 @ 0x931e0 (404 bytes) */
int FUN_000931e0(param_1)
  int param_1;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  uVar3 = 1;
  if (param_1 != 0) {
    iVar1 = *(int *)(param_1 + 0x70);
    if ((iVar1 == -1) || (*(int *)(param_1 + 0x50) == -1)) {
      uVar3 = 2;
    }
    else if ((*(uint *)(param_1 + 0x54) < 4) &&
            ((((*(int *)(param_1 + 0x3d8) != 0 || (iVar1 == *(int *)(param_1 + 0x74))) ||
              (iVar1 == *(int *)(param_1 + 0x78))) ||
             ((iVar1 == *(int *)(param_1 + 0x7c) || (iVar1 == *(int *)(param_1 + 0x80))))))) {
      uVar3 = 0;
      *(undefined1 *)(*(int *)(param_1 + 0x3d4) + 0x12e) = 1;
      if (-1 < *(int *)(*(int *)(param_1 + 0x3d4) + 0x44)) {
        iVar1 = *(int *)(param_1 + 0x54);
        if (iVar1 == 1) {
          puVar4 = &DAT_001dbce4;
        }
        else if (iVar1 == 0) {
          puVar4 = &DAT_001fa5f8;
        }
        else if (iVar1 == 2) {
          puVar4 = &DAT_001dbcf4;
        }
        else if (iVar1 == 3) {
          puVar4 = &DAT_001dbcd4;
        }
        else {
          puVar4 = &DAT_001dbd14;
        }
        if (*(int *)(param_1 + 0x3d8) == 0) {
          puVar2 = &DAT_001dbd44;
        }
        else {
          puVar2 = &DAT_001dbd04;
        }
        (**(code **)(((unsigned char *)0x000012e8) + *(int *)(param_1 + 0x3d4)))
                  (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 0x18),
                   *(undefined4 *)(param_1 + 0x70),puVar2,
                   *(undefined4 *)(*(int *)(param_1 + 0x3ec) + 4),*(undefined4 *)(param_1 + 0x50),
                   puVar4,&DAT_001fa5e8);
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 3;
    }
  }
  return uVar3;
}

/* FUN_00093390 @ 0x93390 (352 bytes) */
int FUN_00093390(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_68 [4];
  undefined4 uStack_64;
  
  uVar1 = 1;
  if ((param_1 != 0) && (uVar1 = 2, *(int *)(param_1 + 8) != -1)) {
    iVar3 = *(int *)(param_1 + 0x3d4);
    iVar2 = ((int (*)())FUN_00090ca0)(param_1,0,auStack_68);
    uVar1 = 7;
    if (iVar2 == 0) {
      uVar5 = *(undefined4 *)(param_1 + 8);
      uVar6 = (*(undefined4 **)(param_1 + 0x3ec))[1];
      uVar4 = **(undefined4 **)(param_1 + 0x3f0);
      uVar1 = **(undefined4 **)(param_1 + 0x3ec);
      (**(code **)(((unsigned char *)0x000012e4) + iVar3))
                (param_1,uVar4,uStack_64,&DAT_001dbd24,uVar6,uVar5,&DAT_001dbdb4,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012ec) + iVar3))
                (param_1,uVar4,uStack_64,&DAT_001dbd24,uVar6,uVar5,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x00001310) + iVar3))
                (param_1,*(undefined4 *)(*(int *)(param_1 + 0x3f0) + 4),0,&DAT_001dbd24,uVar1,
                 uStack_64,&DAT_001dbd14,&DAT_001fa5e8);
      ((int (*)())FUN_000911a0)(param_1,auStack_68);
      uVar1 = 0;
    }
  }
  return uVar1;
}

