#include "decls.h"

/* _PPParserParseBranchCondition @ 0x97c1161c (972 bytes) */
int _PPParserParseBranchCondition(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  char local_110 [256];
  
  bVar1 = param_3 != 0x55;
  if (bVar1) {
    iVar6 = _PPParserGetPart(param_1,local_110,0);
    if (iVar6 == 0) {
      return 0x2d;
    }
    if (local_110[0] != '(') {
      _PPParserReturnPart(param_1);
      return 0;
    }
  }
  iVar6 = _PPParserGetPart(param_1,local_110,0);
  if (iVar6 == 0) {
    return 0x2d;
  }
  if (*(int *)(param_1 + 0x48c) == 0x34) {
    if (1 < iVar6 - 2U) {
      return 0x10;
    }
  }
  else if (iVar6 != 2) {
    return 0x10;
  }
  iVar7 = _memcmp(local_110,"TR",2);
  if (iVar7 == 0) {
    uVar5 = *param_2 & 0x8fffffff;
  }
  else {
    iVar7 = _memcmp(local_110,"EQ",2);
    if (iVar7 == 0) {
      uVar5 = *param_2;
      iVar7 = 1;
    }
    else {
      iVar7 = _memcmp(local_110,"GE",2);
      if (iVar7 == 0) {
        uVar5 = *param_2;
        iVar7 = 2;
      }
      else {
        iVar7 = _memcmp(local_110,"GT",2);
        if (iVar7 == 0) {
          uVar5 = *param_2;
          iVar7 = 3;
        }
        else {
          iVar7 = _memcmp(local_110,"LE",2);
          if (iVar7 == 0) {
            uVar5 = *param_2;
            iVar7 = 4;
          }
          else {
            iVar7 = _memcmp(local_110,"LT",2);
            if (iVar7 == 0) {
              uVar5 = *param_2;
              iVar7 = 5;
            }
            else {
              iVar7 = _memcmp(local_110,"NE",2);
              if (iVar7 != 0) {
                iVar7 = _memcmp(local_110,"FL",2);
                if (iVar7 != 0) {
                  return 0x10;
                }
                uVar5 = *param_2 | 0x70000000;
                goto LAB_97c1180c;
              }
              uVar5 = *param_2;
              iVar7 = 6;
            }
          }
        }
      }
    }
    uVar5 = iVar7 << 0x1c | uVar5 & 0x8fffffff;
  }
LAB_97c1180c:
  *param_2 = uVar5;
  if ((*(int *)(param_1 + 0x48c) == 0x34) && (iVar6 == 3)) {
    if (local_110[2] == '0') {
      uVar5 = *param_2 & 0x7fffffff;
    }
    else {
      if (local_110[2] != '1') goto LAB_97c11858;
      uVar5 = *param_2 | 0x80000000;
    }
    *param_2 = uVar5;
  }
LAB_97c11858:
  iVar6 = _PPParserGetPart(param_1,local_110,0);
  if (iVar6 == 0) {
    return 0x2d;
  }
  if ((bVar1) && (local_110[0] == ')')) {
    return 0;
  }
  if ((local_110[0] != '.') || (iVar6 != 1)) {
    return 0x10;
  }
  iVar6 = _PPParserGetPart(param_1,local_110,0);
  if (iVar6 == 0) {
    return 0x2d;
  }
  if ((iVar6 != 1) && (iVar6 != 4)) {
    return 0x10;
  }
  uVar5 = 0;
  pcVar8 = local_110;
  do {
    cVar3 = *pcVar8;
    if (cVar3 == 'x') {
      iVar7 = 0;
    }
    else {
      if (cVar3 < 'y') {
        bVar2 = cVar3 == 'w';
        iVar7 = 3;
      }
      else {
        if (cVar3 == 'y') {
          iVar7 = 1;
          goto LAB_97c1192c;
        }
        bVar2 = cVar3 == 'z';
        iVar7 = 2;
      }
      if (!bVar2) {
        return 0x10;
      }
    }
LAB_97c1192c:
    if (uVar5 == 1) {
      uVar4 = iVar7 << 0x18 | *param_2 & 0xfcffffff;
LAB_97c1197c:
      *param_2 = uVar4;
    }
    else {
      if (uVar5 == 0) {
        uVar4 = iVar7 << 0x1a | *param_2 & 0xf3ffffff;
        goto LAB_97c1197c;
      }
      if (uVar5 == 2) {
        uVar4 = iVar7 << 0x16 | *param_2 & 0xff3fffff;
        goto LAB_97c1197c;
      }
      if (uVar5 == 3) {
        uVar4 = iVar7 << 0x14 | *param_2 & 0xffcfffff;
        goto LAB_97c1197c;
      }
    }
    if (iVar6 == 4) {
      pcVar8 = pcVar8 + 1;
    }
    uVar5 = uVar5 + 1;
    if (3 < uVar5) {
      if (bVar1) {
        iVar6 = _PPParserGetPart(param_1,local_110,0);
        if (iVar6 == 0) {
          return 0x2d;
        }
        if (local_110[0] != ')') {
          return 0x10;
        }
      }
      return 0;
    }
  } while( true );
}

/* _PPParserParseAddressSourceVar @ 0x97c119e8 (140 bytes) */
int _PPParserParseAddressSourceVar(param_1, param_2)
  int param_1;
  uint *param_2;
{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_110 [260];
  
  iVar3 = _PPParserGetPart(param_1,auStack_110,0);
  uVar2 = 0x2d;
  if (iVar3 != 0) {
    iVar3 = _PPParserScopeFindIdentifier(*(undefined4 *)(param_1 + 0x44c),auStack_110);
    uVar2 = 0x1a;
    if ((iVar3 != 0) && (uVar2 = 0x16, *(int *)(iVar3 + 0xc) == -1)) {
      uVar1 = *(undefined2 *)(iVar3 + 10);
      *param_2 = *param_2 & 0xfc7fffff | 0x2000000;
      uVar2 = 0;
      *(undefined2 *)((int)param_2 + 6) = uVar1;
    }
  }
  return uVar2;
}

/* _PPParserParseMacroDeclaration @ 0x97c11a74 (720 bytes) */
int _PPParserParseMacroDeclaration(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  size_t sVar8;
  char local_130 [256];
  int local_30;
  int local_2c;
  
  iVar1 = _PPParserGetPart(param_1,local_130,0);
  uVar2 = 0x2d;
  if ((iVar1 != 0) && (uVar2 = 10, local_130[0] == '{')) {
    iVar1 = _PPParserGetPart(param_1,local_130,0);
    uVar2 = 0x2d;
    if (iVar1 != 0) {
      iVar3 = _PPParserMacroCreate(0x2d);
      _PPParserMacroSetSearchString(param_1,iVar3,local_130,iVar1);
      local_30 = param_1[3];
      local_2c = param_1[4];
      uVar5 = 0;
      while( true ) {
        iVar1 = _PPParserGetPart(param_1,local_130,0);
        if (iVar1 == 0) {
          return 0x2d;
        }
        uVar6 = uVar5 + 1;
        iVar1 = _PPParserGetPart(param_1,local_130,0);
        if (iVar1 == 0) {
          return 0x2d;
        }
        if (local_130[0] == '}') break;
        uVar5 = uVar6;
        if (local_130[0] != ',') {
          return 0x1f;
        }
      }
      uVar7 = 0;
      _PPParserMacroSetParamStringsCount(iVar3,uVar6);
      param_1[4] = local_2c;
      param_1[3] = local_30;
      if (uVar6 != 0) {
        do {
          _PPParserGetPart(param_1,local_130,0);
          _PPParserMacroSetParamString(iVar3,uVar7,local_130);
          if (uVar7 != uVar5) {
            _PPParserGetPart(param_1,local_130,0);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar6);
      }
      iVar1 = _PPParserGetPart(param_1,local_130,0);
      uVar2 = 0x2d;
      if ((iVar1 != 0) && (uVar2 = 10, local_130[0] == '}')) {
        iVar1 = _PPParserGetPart(param_1,local_130,0);
        uVar2 = 0x2d;
        if ((iVar1 != 0) && (uVar2 = 10, local_130[0] == '=')) {
          iVar1 = _PPParserGetPart(param_1,local_130,0);
          uVar2 = 0x2d;
          if ((iVar1 != 0) && (uVar2 = 10, local_130[0] == '{')) {
            iVar1 = param_1[4];
            *(int *)(iVar3 + 0x10) = param_1[3];
            *(int *)(iVar3 + 0x14) = iVar1;
            local_30 = param_1[3];
            local_2c = param_1[4];
            while( true ) {
              iVar1 = _PPParserGetPart(param_1,local_130,0);
              uVar2 = 0x2d;
              if (iVar1 == 0) break;
              if (local_130[0] == '}') {
                sVar8 = (param_1[3] - local_30) - 2;
                pvVar4 = _malloc((param_1[3] - local_30) - 1);
                _memmove(pvVar4,(void *)(*param_1 + local_30),sVar8);
                *(undefined1 *)((int)pvVar4 + sVar8) = 0;
                _PPParserMacroSetReplaceString(param_1,iVar3,pvVar4);
                iVar1 = _PPParserGetPart(param_1,local_130,0);
                if (iVar1 == 0) {
                  return 0x2d;
                }
                if (local_130[0] != ';') {
                  return 0x1e;
                }
                _PPParserScopeAddMacro(param_1[0x113],iVar3);
                return 0;
              }
            }
          }
        }
      }
    }
  }
  return uVar2;
}

/* _PPParserExpandMacro @ 0x97c11d44 (664 bytes) */
int _PPParserExpandMacro(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  size_t sVar7;
  uint uVar8;
  undefined4 *puVar9;
  char local_130 [256];
  undefined4 local_30;
  undefined4 local_2c;
  
  local_30 = *(undefined4 *)(param_1 + 0xc);
  local_2c = *(undefined4 *)(param_1 + 0x10);
  iVar6 = 0;
  do {
    iVar1 = _PPParserGetPart(param_1,local_130,0);
    if (iVar1 == 0) {
      return 0x2d;
    }
    if (local_130[0] == ',') {
      iVar6 = iVar6 + 1;
    }
  } while (local_130[0] != ';');
  sVar7 = iVar6 + 1;
  uVar2 = 0x26;
  if (sVar7 == param_2[2]) {
    uVar8 = 0;
    puVar3 = _calloc(4,sVar7);
    *(undefined4 *)(param_1 + 0x10) = local_2c;
    *(undefined4 *)(param_1 + 0xc) = local_30;
    if (sVar7 != 0) {
      do {
        pvVar4 = _calloc(0x100,1);
        puVar3[uVar8] = pvVar4;
        _PPParserGetPart(param_1,local_130,0);
        if ((local_130[0] != ',') && (local_130[0] != ';')) {
          while( true ) {
            _strcat((char *)puVar3[uVar8],local_130);
            _PPParserGetPart(param_1,local_130,0);
            if ((local_130[0] == ',') || (local_130[0] == ';')) break;
            _strcat((char *)puVar3[uVar8]," ");
          }
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < sVar7);
    }
    iVar6 = _PPParserMacroGetReplaceString(param_2,*(undefined4 *)(param_1 + 0x48c),puVar3,0);
    uVar8 = 0;
    pvVar4 = _malloc(iVar6 + 1);
    _PPParserMacroGetReplaceString(param_2,*(undefined4 *)(param_1 + 0x48c),puVar3,pvVar4);
    puVar9 = puVar3;
    if (sVar7 != 0) {
      do {
        uVar8 = uVar8 + 1;
        _free((void *)*puVar9);
        puVar9 = puVar9 + 1;
      } while (uVar8 < sVar7);
    }
    _free(puVar3);
    iVar6 = _PPParserCreate(*(undefined4 *)(param_1 + 0x48c));
    _PPParserInitFromParent(iVar6,param_1);
    _PPParserInherit(iVar6,param_1);
    uVar2 = _PPParserScopeCreateFromScope(*(undefined4 *)(param_1 + 0x44c));
    _PPParserAddScope(iVar6,uVar2);
    _PPParserAttachString(iVar6,pvVar4,0);
    _PPParserAttachStream(iVar6,*(undefined4 *)(param_1 + 0x1c));
    uVar5 = *(undefined4 *)(param_1 + 0xc);
    *(byte *)(iVar6 + 0x441) = *(byte *)(iVar6 + 0x441) | 1;
    uVar2 = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(iVar6 + 0x14) = uVar5;
    *(undefined4 *)(iVar6 + 0x18) = uVar2;
    *(byte *)(iVar6 + 0x441) = *(byte *)(iVar6 + 0x441) | 2;
    iVar1 = _PPParserParse(iVar6);
    if (iVar1 == 0) {
      _PPParserInherit(param_1,iVar6);
      _PPParserFree(iVar6);
      _free(pvVar4);
      uVar2 = 0;
    }
    else {
      ((int (*)())_PPParserBuildErrorString)(iVar6,iVar1,*param_2);
      sVar7 = _strlen((char *)(iVar6 + 0x3c));
      _memmove((void *)(param_1 + 0x3c),(char *)(iVar6 + 0x3c),sVar7);
      _PPParserFree(iVar6);
      uVar2 = 2;
    }
  }
  return uVar2;
}

/* _PPParserBuildErrorString @ 0x97c11fdc (912 bytes) */
int _PPParserBuildErrorString(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  char *pcVar1;
  int iVar2;
  undefined1 auStack_130 [16];
  undefined1 auStack_120 [264];
  
  switch(param_2) {
  default:
    pcVar1 = "";
    break;
  case 4:
    pcVar1 = "missing or invalid version";
    break;
  case 5:
    pcVar1 = "unrecognised option";
    break;
  case 6:
    pcVar1 = "unrecognised statement";
    break;
  case 7:
    pcVar1 = "unrecognised block parameter";
    break;
  case 8:
    pcVar1 = "unexpected option";
    break;
  case 9:
    pcVar1 = "unexpected statement";
    break;
  case 10:
    pcVar1 = "malformed declaration";
    break;
  case 0xb:
    pcVar1 = "malformed array specifier";
    break;
  case 0xc:
    pcVar1 = "malformed destination mask";
    break;
  case 0xd:
    pcVar1 = "malformed source swizzle";
    break;
  case 0xe:
    pcVar1 = "malformed source texture";
    break;
  case 0xf:
    pcVar1 = "malformed extended swizzle code";
    break;
  case 0x10:
    pcVar1 = "invalid condition mask";
    break;
  case 0x11:
    pcVar1 = "invalid texture coordinate plane";
    break;
  case 0x12:
    pcVar1 = "invalid identifier name";
    break;
  case 0x13:
    pcVar1 = "invalid attribute pair";
    break;
  case 0x14:
    pcVar1 = "invalid swizzle for scalar op";
    break;
  case 0x15:
    pcVar1 = "invalid number";
    break;
  case 0x16:
    pcVar1 = "invalid address identifier";
    break;
  case 0x17:
    pcVar1 = "invalid source identifier";
    break;
  case 0x18:
    pcVar1 = "invalid dest identifier";
    break;
  case 0x19:
    pcVar1 = "undefined destination identifier";
    break;
  case 0x1a:
    pcVar1 = "undefined source identifier";
    break;
  case 0x1b:
    pcVar1 = "undefined branch label";
    break;
  case 0x1c:
    pcVar1 = "an identifier with this name already exists";
    break;
  case 0x1d:
    pcVar1 = "duplicate branch label";
    break;
  case 0x1e:
    pcVar1 = "missing semicolon";
    break;
  case 0x1f:
    pcVar1 = "missing comma";
    break;
  case 0x20:
    pcVar1 = "identifier is not an array";
    break;
  case 0x21:
    pcVar1 = "identifier is an array";
    break;
  case 0x22:
    pcVar1 = "use of result.position illegal with ARB_position_invariant";
    break;
  case 0x23:
    pcVar1 = "out of range array index";
    break;
  case 0x24:
    pcVar1 = "out of range indirect offset";
    break;
  case 0x25:
    pcVar1 = "incorrect array component count";
    break;
  case 0x26:
    pcVar1 = "incorrect argument count for macro";
    break;
  case 0x27:
    pcVar1 = "conflicting option specification";
    break;
  case 0x28:
    pcVar1 = "conflicting texture target";
    break;
  case 0x29:
    pcVar1 = "impossible array";
    break;
  case 0x2a:
    pcVar1 = "precision qualifier only allowed for temporaries or outputs";
    break;
  case 0x2b:
    pcVar1 = "unpack instructions cannot take SHORT source";
    break;
  case 0x2c:
    pcVar1 = "pack instructions cannot take SHORT destination";
    break;
  case 0x2d:
    pcVar1 = "unexpected end of program";
    break;
  case 0x2e:
    pcVar1 = "program env limit exceeded";
    break;
  case 0x2f:
    pcVar1 = "program local limit exceeded";
    break;
  case 0x30:
    pcVar1 = "program matrices limit exceeded";
    break;
  case 0x31:
    pcVar1 = "program matrix stack depth exceeded";
    break;
  case 0x32:
    pcVar1 = "program instruction count exceeded";
    break;
  case 0x33:
    pcVar1 = "program temporary count exceeded";
    break;
  case 0x34:
    pcVar1 = "program parameter count exceeded";
    break;
  case 0x35:
  case 0x36:
    pcVar1 = "program attribute count exceeded";
    break;
  case 0x37:
    pcVar1 = "program address registers limit exceeded";
    break;
  case 0x38:
    pcVar1 = "texture unit limit exceeded";
    break;
  case 0x39:
    pcVar1 = "vertex unit limit exceeded";
    break;
  case 0x3a:
    pcVar1 = "palette matrix limit exceeded";
    break;
  case 0x3b:
    pcVar1 = "clip plane limit exceeded";
    break;
  case 0x3c:
    pcVar1 = "light limit exceeded";
    break;
  case 0x3d:
    pcVar1 = "vertex attribute limit exceeded";
  }
  _PPParserReturnPart(param_1);
  _PPParserGetPart(param_1,auStack_120,0);
  _PPParserReturnCharacter(param_1,auStack_130);
  iVar2 = *(int *)(param_1 + 0x10) + 1;
  _PPParserGetCharacter(param_1,auStack_130);
  if (param_3 == 0) {
    _sprintf((char *)(param_1 + 0x3c),"Error on line %u: %s (hint: \'%s\')",iVar2,pcVar1,auStack_120
            );
  }
  else {
    _sprintf((char *)(param_1 + 0x3c),"Error in macro %s on line %u: %s (hint: \'%s\')",param_3,
             iVar2,pcVar1,auStack_120);
  }
  return;
}

/* _pow_10 @ 0x97c12464 (156 bytes) */
double _pow_10(int param_1)

{
  undefined *puVar1;
  double dVar2;
  
  dVar2 = DOUBLE_97c30a60;
  if (param_1 < 1) {
    if (-1 < param_1) {
      return DOUBLE_97c30a60;
    }
    for (; param_1 < -0x20; param_1 = param_1 + 0x20) {
      dVar2 = dVar2 * DOUBLE_97c30aa8;
    }
    puVar1 = &_down_1 + param_1 * -8;
  }
  else {
    for (; 0x20 < param_1; param_1 = param_1 + -0x20) {
      dVar2 = dVar2 * DOUBLE_97c30ab0;
    }
    puVar1 = &_up_0 + param_1 * 8;
  }
  return dVar2 * *(double *)(puVar1 + -8);
}

/* _glp_strtod @ 0x97c12500 (824 bytes) */
double _glp_strtod(byte *param_1,undefined4 *param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  byte bVar5;
  bool bVar6;
  byte *pbVar7;
  byte *pbVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  byte *pbStack00000018;
  
  bVar3 = false;
  bVar6 = false;
  bVar2 = false;
  if (*param_1 == 0x2b) {
LAB_97c12560:
    param_1 = param_1 + 1;
  }
  else if (*param_1 == 0x2d) {
    bVar3 = true;
    goto LAB_97c12560;
  }
  bVar5 = *param_1;
  bVar1 = bVar5 == 0x2e;
  pbStack00000018 = param_1;
  dVar9 = DOUBLE_97c30a48;
  if (bVar5 == 0) {
LAB_97c12644:
    if (bVar1) goto LAB_97c12648;
  }
  else {
    if (!bVar1) {
      if ((bVar5 != 0x65) && (pbVar7 = param_1, bVar5 != 0x45)) {
        while (bVar5 - 0x30 < 10) {
          bVar5 = pbVar7[1];
          pbVar7 = pbVar7 + 1;
        }
        if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
          pbStack00000018 = pbVar7;
        }
        pbVar7 = pbVar7 + -1;
        if (param_1 <= pbVar7) {
          iVar4 = (int)pbVar7 - (int)(param_1 + -1);
          dVar10 = DOUBLE_97c30a60;
          do {
            bVar5 = *pbVar7;
            pbVar7 = pbVar7 + -1;
            dVar9 = ((double)CONCAT44(0x43300000,(int)(char)bVar5 - 0x30U ^ 0x80000000) -
                    DOUBLE_97c30a58) * dVar10 + dVar9;
            dVar10 = dVar10 * DOUBLE_97c30a50;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        bVar5 = *pbStack00000018;
        bVar2 = true;
        bVar1 = bVar5 == 0x2e;
      }
      goto LAB_97c12644;
    }
LAB_97c12648:
    pbVar8 = pbStack00000018 + 1;
    bVar5 = pbStack00000018[1];
    pbVar7 = pbVar8;
    while (bVar5 - 0x30 < 10) {
      pbVar7 = pbVar7 + 1;
      bVar5 = *pbVar7;
    }
    dVar10 = DOUBLE_97c30a48;
    if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
      pbStack00000018 = pbVar7;
    }
    while (pbVar7 = pbVar7 + -1, pbVar8 <= pbVar7) {
      dVar10 = dVar10 * DOUBLE_97c30ab8 +
               ((double)CONCAT44(0x43300000,(int)(char)*pbVar7 - 0x30U ^ 0x80000000) -
               DOUBLE_97c30a58);
    }
    bVar2 = true;
    bVar5 = *pbStack00000018;
    dVar9 = dVar10 * DOUBLE_97c30ab8 + dVar9;
  }
  if ((!bVar2) || ((bVar5 != 0x65 && (bVar5 != 0x45)))) goto LAB_97c12804;
  pbVar7 = pbStack00000018 + 1;
  if (*pbVar7 == 0x2b) {
LAB_97c12738:
    pbVar7 = pbStack00000018 + 2;
  }
  else if (*pbVar7 == 0x2d) {
    bVar6 = true;
    goto LAB_97c12738;
  }
  bVar5 = *pbVar7;
  pbVar8 = pbVar7;
  while (bVar5 - 0x30 < 10) {
    pbVar8 = pbVar8 + 1;
    bVar5 = *pbVar8;
  }
  pbStack00000018 = pbVar7;
  if (&STACKARG(0x0) != (undefined1 *)0xffffffe8) {
    pbStack00000018 = pbVar8;
  }
  pbVar8 = pbVar8 + -1;
  dVar10 = DOUBLE_97c30a48;
  if (pbVar7 <= pbVar8) {
    iVar4 = (int)pbVar8 - (int)(pbVar7 + -1);
    dVar11 = DOUBLE_97c30a60;
    do {
      bVar5 = *pbVar8;
      pbVar8 = pbVar8 + -1;
      dVar10 = ((double)CONCAT44(0x43300000,(int)(char)bVar5 - 0x30U ^ 0x80000000) - DOUBLE_97c30a58
               ) * dVar11 + dVar10;
      dVar11 = dVar11 * DOUBLE_97c30a50;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  if (bVar6) {
    dVar10 = -dVar10;
  }
  dVar10 = (double)((double (*)())_pow_10)((int)dVar10);
  dVar9 = dVar9 * dVar10;
LAB_97c12804:
  if (bVar3) {
    dVar9 = -dVar9;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = pbStack00000018;
  }
  return dVar9;
}

/* _glp_dtostr @ 0x97c12838 (1096 bytes) */
char * _glp_dtostr(undefined8 param_1,double param_2,undefined4 param_3,undefined4 param_4,
                  char *param_5,uint param_6)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 extraout_r4;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  uint local_50 [6];
  
  dVar7 = (double)FUN_97c1a258();
  dVar8 = DOUBLE_97c30a48;
  pcVar4 = param_5 + param_6;
  if (param_2 <= DOUBLE_97c30a48) {
    param_2 = DOUBLE_97c30ac0;
  }
  if (param_6 < 2) {
    return (char *)0x0;
  }
  if (dVar7 < DOUBLE_97c30a48) {
    dVar7 = -dVar7;
    *param_5 = '-';
    param_5 = param_5 + 1;
  }
  dVar10 = param_2;
  if (dVar8 < dVar7) {
    if ((dVar7 < DOUBLE_97c30ac8) || (DOUBLE_97c30ad8 < dVar7)) {
      _frexp(dVar7,0,extraout_r4,local_50);
      dVar8 = (double)_round(((double)CONCAT44(0x43300000,local_50[0] ^ 0x80000000) -
                             DOUBLE_97c30a58) * DOUBLE_97c30ad0);
      local_50[0] = (uint)dVar8;
      dVar8 = (double)((double (*)())_pow_10)(local_50[0]);
      dVar9 = (double)((double (*)())_pow_10)(-local_50[0]);
      dVar10 = param_2 * dVar8;
      dVar8 = dVar7 * dVar9;
    }
    else {
      local_50[0] = 0;
      dVar8 = dVar7;
    }
    for (; DOUBLE_97c30a50 <= dVar8 + param_2 * DOUBLE_97c30a88; dVar8 = dVar8 * DOUBLE_97c30ab8) {
      local_50[0] = local_50[0] + 1;
      dVar10 = dVar10 * DOUBLE_97c30a50;
    }
    for (; dVar8 + param_2 * DOUBLE_97c30a88 < DOUBLE_97c30a60; dVar8 = dVar8 * DOUBLE_97c30a50) {
      local_50[0] = local_50[0] - 1;
      dVar10 = dVar10 * DOUBLE_97c30ab8;
    }
    if (3 < (int)(((int)local_50[0] >> 0x1f ^ local_50[0]) - ((int)local_50[0] >> 0x1f)))
    goto LAB_97c12a28;
  }
  local_50[0] = 0;
  dVar8 = dVar7;
  param_2 = dVar10;
LAB_97c12a28:
  dVar8 = param_2 * DOUBLE_97c30a88 + dVar8;
  dVar7 = (double)_floor(dVar8);
  dVar9 = DOUBLE_97c30ab8;
  dVar10 = DOUBLE_97c30a50;
  pcVar5 = param_5;
  while (param_2 < dVar7) {
    if (pcVar5 == pcVar4) {
      return (char *)0x0;
    }
    dVar11 = dVar7 * dVar9;
    dVar7 = (double)_floor(dVar11,0);
    *pcVar5 = (char)(int)((dVar11 - dVar7) * dVar10) + '0';
    pcVar5 = pcVar5 + 1;
  }
  if (param_5 < pcVar5) {
    iVar3 = (int)pcVar5 - (int)param_5;
    pcVar6 = pcVar5;
    while (1 < iVar3) {
      pcVar6 = pcVar6 + -1;
      cVar2 = *pcVar6;
      *pcVar6 = *param_5;
      *param_5 = cVar2;
      param_5 = param_5 + 1;
      iVar3 = (int)pcVar6 - (int)param_5;
    }
  }
  else {
    *pcVar5 = '0';
    pcVar5 = pcVar5 + 1;
  }
  dVar10 = (double)_floor(dVar8);
  dVar7 = DOUBLE_97c30a50;
  dVar8 = dVar8 - dVar10;
  if (dVar8 <= param_2) {
    if (local_50[0] == 0) {
      if ((int)pcVar4 - (int)pcVar5 < 2) {
        return (char *)0x0;
      }
      *pcVar5 = '.';
      pcVar5[1] = '0';
      pcVar5 = pcVar5 + 2;
    }
  }
  else {
    if (pcVar5 == pcVar4) {
      return (char *)0x0;
    }
    *pcVar5 = '.';
    pcVar5 = pcVar5 + 1;
    do {
      if (pcVar5 == pcVar4) {
        return (char *)0x0;
      }
      dVar8 = dVar8 * dVar7;
      param_2 = param_2 * dVar7;
      dVar10 = (double)_floor(dVar8,0);
      dVar8 = dVar8 - dVar10;
      *pcVar5 = (char)(int)dVar10 + '0';
      pcVar5 = pcVar5 + 1;
    } while (param_2 < dVar8);
  }
  if (local_50[0] != 0) {
    if ((int)pcVar4 - (int)pcVar5 < 3) {
      return (char *)0x0;
    }
    *pcVar5 = 'e';
    pcVar6 = pcVar5 + 1;
    pcVar1 = pcVar6;
    if ((int)local_50[0] < 0) {
      local_50[0] = -local_50[0];
      *pcVar6 = '-';
      pcVar6 = pcVar5 + 2;
      pcVar1 = pcVar6;
    }
    while (pcVar5 = pcVar1, 0 < (int)local_50[0]) {
      if (pcVar5 == pcVar4) {
        return (char *)0x0;
      }
      *pcVar5 = (char)local_50[0] + (char)((int)local_50[0] / 10) * -10 + '0';
      local_50[0] = (int)local_50[0] / 10;
      pcVar1 = pcVar5 + 1;
    }
    iVar3 = (int)pcVar5 - (int)pcVar6;
    pcVar1 = pcVar5;
    while (1 < iVar3) {
      pcVar1 = pcVar1 + -1;
      cVar2 = *pcVar1;
      *pcVar1 = *pcVar6;
      *pcVar6 = cVar2;
      pcVar6 = pcVar6 + 1;
      iVar3 = (int)pcVar1 - (int)pcVar6;
    }
  }
  pcVar6 = (char *)0x0;
  if (pcVar5 != pcVar4) {
    *pcVar5 = '\0';
    pcVar6 = pcVar5;
  }
  return pcVar6;
}

/* std____throw_bad_exception @ 0x97c12c80 (68 bytes) */
int std____throw_bad_exception()
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)___cxa_allocate_exception(4);
  puVar2 = PTR_typeinfo_a7b7c180;
  puVar1 = PTR__bad_exception_a7b7c17c;
  *puVar3 = PTR_vtable_a7b7c184 + 8;
                    
  ___cxa_throw(puVar3,puVar2,puVar1);
}

/* std____throw_bad_alloc @ 0x97c12cc4 (68 bytes) */
int std____throw_bad_alloc()
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)___cxa_allocate_exception(4);
  puVar2 = PTR_typeinfo_a7b7c174;
  puVar1 = PTR__bad_alloc_a7b7c170;
  *puVar3 = PTR_vtable_a7b7c178 + 8;
                    
  ___cxa_throw(puVar3,puVar2,puVar1);
}

/* std____throw_bad_cast @ 0x97c12d08 (68 bytes) */
int std____throw_bad_cast()
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)___cxa_allocate_exception(4);
  puVar2 = PTR_typeinfo_a7b7c168;
  puVar1 = PTR__bad_cast_a7b7c164;
  *puVar3 = PTR_vtable_a7b7c16c + 8;
                    
  ___cxa_throw(puVar3,puVar2,puVar1);
}

/* std____throw_bad_typeid @ 0x97c12d4c (68 bytes) */
int std____throw_bad_typeid()
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)___cxa_allocate_exception(4);
  puVar2 = PTR_typeinfo_a7b7c15c;
  puVar1 = PTR__bad_typeid_a7b7c158;
  *puVar3 = PTR_vtable_a7b7c160 + 8;
                    
  ___cxa_throw(puVar3,puVar2,puVar1);
}

/* std____throw_logic_error @ 0x97c12d90 (132 bytes) */
int std____throw_logic_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  logic_error *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  allocator aaStack_30 [40];
  
  ((int (*)())std__string__string)((unsigned char *)local_40,param_1,aaStack_30);
  this = (unsigned char *)___cxa_allocate_exception(8);
  std__logic_error__logic_error(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c154,PTR__logic_error_a7b7c150);
}

/* std____throw_domain_error @ 0x97c12e18 (132 bytes) */
int std____throw_domain_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  domain_error *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  allocator aaStack_30 [40];
  
  ((int (*)())std__string__string)((unsigned char *)local_40,param_1,aaStack_30);
  this = (unsigned char *)___cxa_allocate_exception(8);
  std__domain_error__domain_error(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c14c,PTR__domain_error_a7b7c148);
}

/* std____throw_invalid_argument @ 0x97c12ea0 (132 bytes) */
int std____throw_invalid_argument(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  invalid_argument *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  allocator aaStack_30 [40];
  
  ((int (*)())std__string__string)((unsigned char *)local_40,param_1,aaStack_30);
  this = (unsigned char *)___cxa_allocate_exception(8);
  std__invalid_argument__invalid_argument(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c144,PTR__invalid_argument_a7b7c140);
}

/* std____throw_length_error @ 0x97c12f28 (132 bytes) */
int std____throw_length_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  length_error *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  allocator aaStack_30 [40];
  
  ((int (*)())std__string__string)((unsigned char *)local_40,param_1,aaStack_30);
  this = (unsigned char *)___cxa_allocate_exception(8);
  std__length_error__length_error(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c13c,PTR__length_error_a7b7c138);
}

/* std____throw_out_of_range @ 0x97c12fb0 (132 bytes) */
int std____throw_out_of_range(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  out_of_range *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  allocator aaStack_30 [40];
  
  ((int (*)())std__string__string)((unsigned char *)local_40,param_1,aaStack_30);
  this = (unsigned char *)___cxa_allocate_exception(8);
  std__out_of_range__out_of_range(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c134,PTR__out_of_range_a7b7c130);
}

/* std____throw_runtime_error @ 0x97c13038 (132 bytes) */
int std____throw_runtime_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  runtime_error *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  allocator aaStack_30 [40];
  
  ((int (*)())std__string__string)((unsigned char *)local_40,param_1,aaStack_30);
  this = (unsigned char *)___cxa_allocate_exception(8);
  std__runtime_error__runtime_error(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c12c,PTR__runtime_error_a7b7c128);
}

/* std____throw_range_error @ 0x97c130c0 (132 bytes) */
int std____throw_range_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  range_error *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  allocator aaStack_30 [40];
  
  ((int (*)())std__string__string)((unsigned char *)local_40,param_1,aaStack_30);
  this = (unsigned char *)___cxa_allocate_exception(8);
  std__range_error__range_error(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c124,PTR__range_error_a7b7c120);
}

/* std____throw_overflow_error @ 0x97c13148 (132 bytes) */
int std____throw_overflow_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  overflow_error *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  allocator aaStack_30 [40];
  
  ((int (*)())std__string__string)((unsigned char *)local_40,param_1,aaStack_30);
  this = (unsigned char *)___cxa_allocate_exception(8);
  std__overflow_error__overflow_error(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c11c,PTR__overflow_error_a7b7c118);
}

/* std____throw_underflow_error @ 0x97c131d0 (132 bytes) */
int std____throw_underflow_error(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  underflow_error *this;
  char in_RESERVE;
  byte in_cr0;
  int local_40 [4];
  allocator aaStack_30 [40];
  
  ((int (*)())std__string__string)((unsigned char *)local_40,param_1,aaStack_30);
  this = (unsigned char *)___cxa_allocate_exception(8);
  std__underflow_error__underflow_error(this,(unsigned char *)local_40);
  piVar2 = (int *)(local_40[0] + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_40[0] + -0xc));
  }
                    
  ___cxa_throw(this,PTR_typeinfo_a7b7c114,PTR__underflow_error_a7b7c110);
}

/* std__string___M_data @ 0x97c13258 (8 bytes) */
int std__string___M_data(this)
  unsigned char *this;
{
  return *(undefined4 *)this;
}

/* std__string___M_data_97c13260 @ 0x97c13260 (12 bytes) */
int std__string___M_data_97c13260(this, param_1)
  unsigned char *this;
  char *param_1;
{
  *(char **)this = param_1;
  return param_1;
}

/* std__string___M_rep @ 0x97c1326c (12 bytes) */
int std__string___M_rep(this)
  unsigned char *this;
{
  return *(int *)this + -0xc;
}

/* std__string___M_ibegin @ 0x97c13278 (12 bytes) */
int std__string___M_ibegin()
{
  undefined4 *in_r3;
  undefined4 *in_r4;
  
  *in_r3 = *in_r4;
  return;
}

/* std__string__size @ 0x97c13284 (12 bytes) */
int std__string__size(this)
  unsigned char *this;
{
  return *(undefined4 *)(*(int *)this + -0xc);
}

/* std__string___M_iend @ 0x97c13290 (20 bytes) */
int std__string___M_iend()
{
  int *in_r3;
  int *in_r4;
  
  *in_r3 = *in_r4 + *(int *)(*in_r4 + -0xc);
  return;
}

/* std__string___Rep___M_is_leaked @ 0x97c132a4 (12 bytes) */
int std__string___Rep___M_is_leaked(this)
  unsigned char *this;
{
  return *(uint *)(this + 8) >> 0x1f;
}

/* std__string___M_leak @ 0x97c132b0 (20 bytes) */
int std__string___M_leak(this)
  unsigned char *this;
{
  if (*(int *)(*(int *)this + -4) < 0) {
    return;
  }
  ((int (*)())std__string___M_leak_hard)(this);
  return;
}

/* std__string___M_check @ 0x97c132c4 (112 bytes) */
int std__string___M_check(param_1)
  ulong param_1;
{
  int *in_r4;
  uint in_r5;
  int local_20;
  
  if (*(uint *)(*in_r4 + -0xc) < in_r5) {
    ((int (*)())std____throw_out_of_range)("basic_string::_M_check");
  }
  _M_ibegin();
  *(uint *)param_1 = local_20 + in_r5;
  return param_1;
}

/* std__string___M_fold @ 0x97c13334 (100 bytes) */
int std__string___M_fold(param_1, param_2)
  ulong param_1;
  ulong param_2;
{
  uint uVar1;
  int in_r5;
  uint in_r6;
  undefined4 local_20;
  
  uVar1 = *(int *)(*(int *)param_2 + -0xc) - in_r5;
  if (uVar1 <= in_r6) {
    in_r6 = uVar1;
  }
  _M_ibegin();
  *(uint *)param_1 = local_20 + in_r5 + in_r6;
  return param_1;
}

/* std__string___S_copy_chars @ 0x97c13398 (36 bytes) */
int std__string___S_copy_chars(param_1, param_2, param_3)
  char *param_1;
  char *param_2;
  char *param_3;
{
  _memcpy(param_1,param_2,(int)param_3 - (int)param_2);
  return;
}

/* std__string___S_copy_chars_97c133bc @ 0x97c133bc (36 bytes) */
int std__string___S_copy_chars_97c133bc(param_1, param_2, param_3)
  void *param_1;
  void *param_2;
  int param_3;
{
  _memcpy(param_1,param_2,param_3 - (int)param_2);
  return;
}

/* std__string___S_copy_chars_97c133e0 @ 0x97c133e0 (36 bytes) */
int std__string___S_copy_chars_97c133e0(param_1, param_2, param_3)
  char *param_1;
  char *param_2;
  char *param_3;
{
  _memcpy(param_1,param_2,(int)param_3 - (int)param_2);
  return;
}

/* std__string___S_copy_chars_97c13404 @ 0x97c13404 (36 bytes) */
int std__string___S_copy_chars_97c13404(param_1, param_2, param_3)
  void *param_1;
  void *param_2;
  int param_3;
{
  _memcpy(param_1,param_2,param_3 - (int)param_2);
  return;
}

/* std__string___Rep___M_is_shared @ 0x97c13428 (24 bytes) */
int std__string___Rep___M_is_shared(this)
  unsigned char *this;
{
  if (0 < *(int *)(this + 8)) {
    return 1;
  }
  return 0;
}

/* std__string__capacity @ 0x97c13440 (12 bytes) */
int std__string__capacity(this)
  unsigned char *this;
{
  return *(undefined4 *)(*(int *)this + -8);
}

/* std__string__get_allocator @ 0x97c1344c (4 bytes) */
int std__string__get_allocator()
{
  return;
}

/* std__string___Rep___M_refdata @ 0x97c13450 (8 bytes) */
int std__string___Rep___M_refdata(this)
  unsigned char *this;
{
  return this + 0xc;
}

/* std__string___Rep___M_dispose @ 0x97c13458 (32 bytes) */
int std__string___Rep___M_dispose(param_1)
  unsigned char *param_1;
{
  int iVar1;
  allocator *paVar2;
  int iVar3;
  char in_RESERVE;
  byte in_cr0;
  
  paVar2 = param_1 + 8;
  do {
    iVar3 = *(int *)paVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,paVar2);
      *(int *)paVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (0 < iVar3) {
    return;
  }
  _M_destroy(param_1);
  return;
}

/* std__string___Rep___M_set_sharable @ 0x97c13478 (12 bytes) */
int std__string___Rep___M_set_sharable(this)
  unsigned char *this;
{
  *(undefined4 *)(this + 8) = 0;
  return;
}

/* std__string___M_mutate @ 0x97c13484 (340 bytes) */
int std__string___M_mutate(this, param_1, param_2, param_3)
  unsigned char *this;
  ulong param_1;
  ulong param_2;
  ulong param_3;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  void *pvVar8;
  size_t sVar9;
  uint uVar10;
  char in_RESERVE;
  byte in_cr0;
  allocator aaStack_40 [32];
  
  pvVar5 = *(void **)this;
  pvVar8 = (void *)((int)pvVar5 + param_2 + param_1);
  sVar9 = (*(int *)((int)pvVar5 + -0xc) - param_1) - param_2;
  uVar10 = (*(int *)((int)pvVar5 + -0xc) + param_3) - param_2;
  if (*(int *)((int)pvVar5 + -4) < 1) {
    uVar2 = *(uint *)((int)pvVar5 + -8);
    if (uVar10 <= uVar2) {
      if ((sVar9 != 0) && (param_2 != param_3)) {
        _memmove((void *)((int)pvVar5 + param_3 + param_1),pvVar8,sVar9);
        pvVar5 = *(void **)this;
      }
      goto LAB_97c135b0;
    }
  }
  else {
    uVar2 = *(uint *)((int)pvVar5 + -8);
  }
  uVar6 = uVar10;
  if (((uVar2 < uVar10) && (0xfe3 < uVar10)) && (uVar6 = uVar2 << 1, uVar2 << 1 < uVar10)) {
    uVar6 = uVar10;
  }
  iVar7 = _Rep::_S_create(uVar6,aaStack_40);
  pvVar5 = (void *)(iVar7 + 0xc);
  if (param_1 != 0) {
    _memcpy(pvVar5,*(void **)this,param_1);
  }
  if (sVar9 != 0) {
    _memcpy((void *)((int)pvVar5 + param_3 + param_1),pvVar8,sVar9);
  }
  iVar7 = *(int *)this;
  piVar3 = (int *)(iVar7 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar4 < 1) {
    _Rep::_M_destroy((unsigned char *)(iVar7 + -0xc));
  }
  *(void **)this = pvVar5;
LAB_97c135b0:
  *(undefined4 *)((int)pvVar5 + -4) = 0;
  *(uint *)(*(int *)this + -0xc) = uVar10;
  *(undefined1 *)(*(int *)this + uVar10) = 0;
  return;
}

/* std__string___Rep___M_set_leaked @ 0x97c135dc (12 bytes) */
int std__string___Rep___M_set_leaked(this)
  unsigned char *this;
{
  *(undefined4 *)(this + 8) = 0xffffffff;
  return;
}

/* std__string___M_leak_hard @ 0x97c135e8 (84 bytes) */
int std__string___M_leak_hard(this)
  unsigned char *this;
{
  int iVar1;
  
  iVar1 = *(int *)this;
  if (0 < *(int *)(iVar1 + -4)) {
    _M_mutate(this,0,0,0);
    iVar1 = *(int *)this;
  }
  *(undefined4 *)(iVar1 + -4) = 0xffffffff;
  return;
}

/* std__string___S_empty_rep @ 0x97c1363c (28 bytes) */
int std__string___S_empty_rep()
{
  return &_S_empty_rep_storage;
}

/* std__string__string @ 0x97c13658 (4 bytes) */
int std__string__string(this)
  unsigned char *this;
{
  string(this);
  return;
}

/* std__string__string_97c1365c @ 0x97c1365c (4 bytes) */
int std__string__string_97c1365c(this)
  unsigned char *this;
{
  string(this);
  return;
}

/* std__string___Alloc_hider___Alloc_hider @ 0x97c13660 (4 bytes) */
int std__string___Alloc_hider___Alloc_hider(this, param_1, param_2)
  unsigned char *this;
  char *param_1;
  unsigned char *param_2;
{
  _Alloc_hider(this,param_1,param_2);
  return;
}

/* std__string___Alloc_hider___Alloc_hider_97c13664 @ 0x97c13664 (4 bytes) */
int std__string___Alloc_hider___Alloc_hider_97c13664(this, param_1, param_2)
  unsigned char *this;
  char *param_1;
  unsigned char *param_2;
{
  _Alloc_hider(this,param_1,param_2);
  return;
}

/* std__string___Alloc_hider___Alloc_hider_97c13668 @ 0x97c13668 (8 bytes) */
int std__string___Alloc_hider___Alloc_hider_97c13668(this, param_1, param_2)
  unsigned char *this;
  char *param_1;
  unsigned char *param_2;
{
  *(char **)this = param_1;
  return;
}

/* std__string___Rep___M_refcopy @ 0x97c13670 (28 bytes) */
int std__string___Rep___M_refcopy(this)
  unsigned char *this;
{
  int iVar1;
  _Rep *p_Var2;
  char in_RESERVE;
  byte in_cr0;
  
  p_Var2 = this + 8;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*(int *)p_Var2 + 1,0,p_Var2);
      *(int *)p_Var2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  return this + 0xc;
}

/* std__string__string_97c1368c @ 0x97c1368c (84 bytes) */
int std__string__string_97c1368c(this)
  unsigned char *this;
{
  char in_RESERVE;
  byte in_cr0;
  allocator aaStack_20 [28];
  
  do {
    if (in_RESERVE != '\0') {
      DAT_a7b7bf8c = storeWordConditionalIndexed(DAT_a7b7bf8c + 1,0,0xa7b7bf8c);
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  _Alloc_hider::_Alloc_hider((unsigned char *)this,&DAT_a7b7bf90,aaStack_20);
  return;
}

/* std__string__string_97c136e0 @ 0x97c136e0 (4 bytes) */
int std__string__string_97c136e0(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  string(this,param_1);
  return;
}

/* std__string__string_97c136e4 @ 0x97c136e4 (4 bytes) */
int std__string__string_97c136e4(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  string(this,param_1);
  return;
}

/* std__string__string_97c136e8 @ 0x97c136e8 (76 bytes) */
int std__string__string_97c136e8(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  char *pcVar1;
  
  pcVar1 = (char *)std__string___S_construct(0,'\0',param_1);
  _Alloc_hider::_Alloc_hider((unsigned char *)this,pcVar1,param_1);
  return;
}

/* std__string__string_97c13734 @ 0x97c13734 (4 bytes) */
int std__string__string_97c13734(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  string(this,param_1);
  return;
}

/* std__string__string_97c13738 @ 0x97c13738 (4 bytes) */
int std__string__string_97c13738(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  char in_RESERVE;
  byte in_cr0;
  allocator aaStack_50 [32];
  allocator aaStack_30 [28];
  
  pcVar3 = *(char **)param_1;
  get_allocator();
  if (*(int *)(pcVar3 + -4) < 0) {
    pcVar3 = (char *)_Rep::_M_clone((unsigned char *)(pcVar3 + -0xc),aaStack_50,0);
  }
  else {
    piVar2 = (int *)(pcVar3 + -4);
    do {
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  }
  get_allocator();
  _Alloc_hider::_Alloc_hider((unsigned char *)this,pcVar3,aaStack_30);
  return;
}

/* std__string___Rep___M_grab @ 0x97c1373c (48 bytes) */
int std__string___Rep___M_grab(param_1, param_2)
  unsigned char *param_1;
  unsigned char *param_2;
{
  int iVar1;
  allocator *paVar2;
  char in_RESERVE;
  byte in_cr0;
  
  if (*(int *)(param_1 + 8) < 0) {
    paVar2 = (unsigned char *)_M_clone((unsigned char *)param_1,param_2,0);
    return paVar2;
  }
  paVar2 = param_1 + 8;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*(int *)paVar2 + 1,0,paVar2);
      *(int *)paVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  return param_1 + 0xc;
}

/* std__string__string_97c1376c @ 0x97c1376c (152 bytes) */
int std__string__string_97c1376c(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  char in_RESERVE;
  byte in_cr0;
  allocator aaStack_50 [32];
  allocator aaStack_30 [28];
  
  pcVar3 = *(char **)param_1;
  get_allocator();
  if (*(int *)(pcVar3 + -4) < 0) {
    pcVar3 = (char *)_Rep::_M_clone((unsigned char *)(pcVar3 + -0xc),aaStack_50,0);
  }
  else {
    piVar2 = (int *)(pcVar3 + -4);
    do {
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
  }
  get_allocator();
  _Alloc_hider::_Alloc_hider((unsigned char *)this,pcVar3,aaStack_30);
  return;
}

/* std__string__string_97c13808 @ 0x97c13808 (4 bytes) */
int std__string__string_97c13808(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  ulong param_2;
  ulong param_3;
{
  string(this,param_1,param_2,param_3);
  return;
}

