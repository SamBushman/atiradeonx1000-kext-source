#include "decls.h"

/* _updateExtensionBehavior @ 0x97baed64 (1252 bytes) */
int _updateExtensionBehavior(param_1, param_2)
  char *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_1e0;
  int local_1dc;
  undefined4 local_1d0;
  int local_1c0;
  int local_1b0;
  int local_1a0 [4];
  undefined4 local_190;
  int local_18c;
  undefined4 local_180 [4];
  undefined4 local_170;
  int local_160;
  undefined4 local_150;
  int local_14c;
  undefined4 local_140;
  int local_13c;
  undefined4 local_130;
  int local_12c;
  undefined4 local_120 [4];
  undefined4 local_110;
  undefined4 local_100;
  undefined4 local_f0;
  undefined4 local_e0;
  int local_dc;
  undefined4 local_d0 [4];
  undefined4 local_c0;
  undefined4 local_b0;
  undefined4 local_a0;
  undefined4 local_50;
  undefined4 local_40;
  undefined4 local_30;
  
  uVar4 = _GetBehavior(param_2);
  local_1dc = DAT_a7b7baa8;
  piVar3 = (int *)(DAT_a7b7baa8 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar5 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar5;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_1e0 = GetGlobalPoolAllocator();
  local_1dc = local_1dc + 0xc;
  local_1d0 = local_1e0;
  iVar5 = _memcmp(param_1,"all",4);
  puVar2 = PTR__cpp_a7b7c0a4;
  if (iVar5 == 0) {
    if (uVar4 < 2) {
      _CPPShInfoLogMsg("extension \'all\' cannot have \'require\' or \'enable\' behavior");
      piVar3 = (int *)(local_1dc + -4);
      do {
        iVar5 = *piVar3;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
          *piVar3 = iVar1;
          in_cr0 = 2;
        }
        local_30 = local_1e0;
      } while (!(bool)(in_cr0 >> 1 & 1));
      goto joined_r0x97baf310;
    }
    iVar5 = *(int *)(*(int *)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) + 0x34) + 8);
    local_1c0 = iVar5;
    while (local_1b0 = *(int *)(*(int *)(*(int *)puVar2 + 0x2c) + 0x34), iVar5 != local_1b0) {
      *(uint *)(iVar5 + 0x18) = uVar4;
      std___Rb_tree_base_iterator___M_increment();
    }
  }
  else {
    local_180[0] = GetGlobalPoolAllocator();
    std__string__string((unsigned char *)&local_190,param_1,(unsigned char *)local_180);
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
    ::find((unsigned char *)local_1a0);
    piVar3 = (int *)(local_18c + -4);
    local_170 = local_190;
    do {
      iVar5 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
        *piVar3 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar5 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_18c + -0xc));
    }
    local_160 = *(int *)(*(int *)(*(int *)puVar2 + 0x2c) + 0x34);
    if (local_1a0[0] == local_160) {
      if (uVar4 == 0) {
        local_120[0] = GetGlobalPoolAllocator();
        std__string__string((unsigned char *)&local_130,"extension \'",(unsigned char *)local_120);
        std__string__string((unsigned char *)&local_140,(unsigned char *)&local_130);
        _strlen(param_1);
        std__string__append((char *)&local_140,(ulong)param_1);
        std__string__string((unsigned char *)&local_150,(unsigned char *)&local_140);
        _strlen("\' is not supported");
        std__string__append((char *)&local_150,0x97c2aa10);
        *(undefined1 *)(local_14c + *(int *)(local_14c + -0xc)) = *DAT_a7b7baa4;
        _CPPShInfoLogMsg(local_14c);
        piVar3 = (int *)(local_14c + -4);
        local_110 = local_150;
        do {
          iVar5 = *piVar3;
          if (in_RESERVE != '\0') {
            iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
            *piVar3 = iVar1;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar5 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_14c + -0xc));
        }
        piVar3 = (int *)(local_13c + -4);
        local_100 = local_140;
        do {
          iVar5 = *piVar3;
          if (in_RESERVE != '\0') {
            iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
            *piVar3 = iVar1;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar5 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_13c + -0xc));
        }
        piVar3 = (int *)(local_12c + -4);
        local_f0 = local_130;
        do {
          iVar5 = *piVar3;
          if (in_RESERVE != '\0') {
            iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
            *piVar3 = iVar1;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar5 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_12c + -0xc));
        }
      }
      else if ((-1 < (int)uVar4) && ((int)uVar4 < 4)) {
        local_d0[0] = GetGlobalPoolAllocator();
        std__string__string((unsigned char *)&local_e0,"extension \'",(unsigned char *)local_d0);
        std__string__string((unsigned char *)&local_140,(unsigned char *)&local_e0);
        _strlen(param_1);
        std__string__append((char *)&local_140,(ulong)param_1);
        std__string__string((unsigned char *)&local_150,(unsigned char *)&local_140);
        _strlen("\' is not supported");
        std__string__append((char *)&local_150,0x97c2aa10);
        std__string__assign((unsigned char *)&local_1e0);
        piVar3 = (int *)(local_14c + -4);
        local_c0 = local_150;
        do {
          iVar5 = *piVar3;
          if (in_RESERVE != '\0') {
            iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
            *piVar3 = iVar1;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar5 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_14c + -0xc));
        }
        piVar3 = (int *)(local_13c + -4);
        local_b0 = local_140;
        do {
          iVar5 = *piVar3;
          if (in_RESERVE != '\0') {
            iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
            *piVar3 = iVar1;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar5 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_13c + -0xc));
        }
        piVar3 = (int *)(local_dc + -4);
        local_a0 = local_e0;
        do {
          iVar5 = *piVar3;
          if (in_RESERVE != '\0') {
            iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
            *piVar3 = iVar1;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar5 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_dc + -0xc));
        }
        UNRECOVERED_JUMPTABLE = (code *)(((unsigned char *)0x97baf1c8) + (*(unsigned char *)0x97baf1cc));
        *(undefined1 *)(local_1dc + *(int *)(local_1dc + -0xc)) = *DAT_a7b7baa4;
                    
                    
        (*UNRECOVERED_JUMPTABLE)();
        return;
      }
      piVar3 = (int *)(local_1dc + -4);
      do {
        iVar5 = *piVar3;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
          *piVar3 = iVar1;
          in_cr0 = 2;
        }
        local_40 = local_1e0;
      } while (!(bool)(in_cr0 >> 1 & 1));
      goto joined_r0x97baf310;
    }
    *(uint *)(local_1a0[0] + 0x18) = uVar4;
  }
  piVar3 = (int *)(local_1dc + -4);
  do {
    iVar5 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar5 + -1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
    local_50 = local_1e0;
  } while (!(bool)(in_cr0 >> 1 & 1));
joined_r0x97baf310:
  if (iVar5 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_1dc + -0xc));
  }
  return;
}

/* setInitialState @ 0x97baf364 (32 bytes) */
int setInitialState()
{
  _yy_start = 1;
  return;
}

/* scpy @ 0x97baf384 (52 bytes) */
int scpy(param_1, param_2)
  char *param_1;
  char *param_2;
{
  char cVar1;
  int iVar2;
  
  cVar1 = *param_2;
  iVar2 = 0;
  if (cVar1 != '\0') {
    do {
      param_1[iVar2] = cVar1;
      iVar2 = iVar2 + 1;
      cVar1 = param_2[iVar2];
    } while (cVar1 != '\0');
    return;
  }
  return;
}

/* handleDigit @ 0x97baf3b8 (112 bytes) */
int handleDigit(param_1, param_2)
  char **param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = param_2 / 10;
  if (iVar1 != 0) {
    ((int (*)())handleDigit)(param_1,iVar1);
  }
  **param_1 = (char)param_2 + (char)iVar1 * -10 + '0';
  *param_1 = *param_1 + 1;
  return;
}

/* ncpy @ 0x97baf428 (88 bytes) */
int ncpy(param_1, param_2)
  char *param_1;
  int param_2;
{
  char *local_20 [6];
  
  local_20[0] = param_1;
  if (param_2 < 0) {
    local_20[0] = param_1 + 1;
    *param_1 = '-';
    param_2 = -param_2;
  }
  ((int (*)())handleDigit)(local_20,param_2);
  return (int)local_20[0] - (int)param_1;
}

/* PrintAttribute @ 0x97baf480 (456 bytes) */
int PrintAttribute(param_1, param_2)
  uint param_1;
  uint param_2;
{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uStack00000018;
  uint uStack0000001c;
  
  uStack00000018 = param_1;
  uStack0000001c = param_2;
  pcVar2 = _malloc(0x100);
  iVar3 = ((int (*)())ncpy)(pcVar2,uStack0000001c & 0xffff);
  pcVar5 = pcVar2 + iVar3;
  switch(uStack00000018 >> 0x10 & 0xf) {
  case 0:
    pcVar4 = ": PP_BIND_ATTRIB_NONE";
    break;
  case 1:
    pcVar4 = ": PP_BIND_ATTRIB_POSITION";
    break;
  case 2:
    pcVar4 = ": PP_BIND_ATTRIB_COLOR";
    break;
  case 3:
    pcVar4 = ": PP_BIND_ATTRIB_SEC_COLOR";
    break;
  case 4:
    pcVar4 = ": PP_BIND_ATTRIB_NORMAL";
    break;
  case 5:
    pcVar4 = ": PP_BIND_ATTRIB_FOG_COORD";
    break;
  case 6:
    pcVar4 = ": PP_BIND_ATTRIB_WEIGHT:";
    goto LAB_97baf584;
  case 7:
    pcVar4 = ": PP_BIND_ATTRIB_TEX_COORD:";
    goto LAB_97baf584;
  case 8:
    pcVar4 = ": PP_BIND_ATTRIB_MATRIX_INDICES:";
    goto LAB_97baf584;
  case 9:
    pcVar4 = ": PP_BIND_ATTRIB_ATTRIB:";
LAB_97baf584:
    iVar3 = ((int (*)())scpy)(pcVar5,pcVar4);
    pcVar5 = pcVar5 + iVar3;
    uVar1 = uStack00000018 & 0x1f;
LAB_97baf658:
    iVar3 = ((int (*)())ncpy)(pcVar5,uVar1);
    goto LAB_97baf660;
  case 10:
    iVar3 = ((int (*)())scpy)(pcVar5,"PP_BIND_ATTRIB_MATERIAL:");
    pcVar5 = pcVar5 + iVar3;
    switch(uStack00000018 >> 0xc & 0xf) {
    case 0:
      pcVar4 = "PP_ATTRIB_MATERIAL_AMBIENT:";
      break;
    case 1:
      pcVar4 = "PP_ATTRIB_MATERIAL_DIFFUSE:";
      break;
    case 2:
      pcVar4 = "PP_ATTRIB_MATERIAL_SPECULAR:";
      break;
    case 3:
      pcVar4 = "PP_ATTRIB_MATERIAL_EMISSION:";
      break;
    case 4:
      pcVar4 = "PP_ATTRIB_MATERIAL_SHININESS:";
      break;
    default:
      goto switchD_97baf5f0_default;
    }
    iVar3 = ((int (*)())scpy)(pcVar5,pcVar4);
    pcVar5 = pcVar5 + iVar3;
switchD_97baf5f0_default:
    uVar1 = uStack00000018 & 1;
    goto LAB_97baf658;
  case 0xb:
    pcVar4 = ": PP_BIND_ATTRIB_FRONT_FACING";
    break;
  default:
    goto switchD_97baf4e0_default;
  }
  iVar3 = ((int (*)())scpy)(pcVar5,pcVar4);
LAB_97baf660:
  pcVar5 = pcVar5 + iVar3;
switchD_97baf4e0_default:
  *pcVar5 = '\0';
  _realloc(pcVar2,(size_t)(pcVar5 + (1 - (int)pcVar2)));
  return;
}

/* PrintParam @ 0x97baf68c (1228 bytes) */
int PrintParam(param_1, param_2)
  uint param_1;
  uint param_2;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  uint uStack00000018;
  uint uStack0000001c;
  
  uStack00000018 = param_1;
  uStack0000001c = param_2;
  pcVar1 = _malloc(0x100);
  iVar2 = ((int (*)())ncpy)(pcVar1,uStack0000001c & 0xffff);
  pcVar6 = pcVar1 + iVar2;
  switch(uStack00000018 >> 0x10 & 0x1f) {
  case 0:
    pcVar5 = ": PP_BIND_PARAM_NONE:";
    goto LAB_97baf750;
  case 1:
    pcVar5 = ": PP_BIND_PARAM_PROGRAM_LOCAL:";
    goto LAB_97baf750;
  case 2:
    pcVar5 = ": PP_BIND_PARAM_PROGRAM_ENV:";
    goto LAB_97baf750;
  case 3:
    iVar2 = ((int (*)())scpy)(pcVar6,": PP_BIND_PARAM_LIGHT:");
    iVar3 = ((int (*)())ncpy)(pcVar6 + iVar2,uStack00000018 & 0xff);
    pcVar6 = pcVar6 + iVar2 + iVar3;
    switch(uStack00000018 >> 8 & 0xf) {
    case 0:
      pcVar5 = ":PP_PARAM_LIGHT_AMBIENT";
      break;
    case 1:
      pcVar5 = ":PP_PARAM_LIGHT_DIFFUSE";
      break;
    case 2:
      pcVar5 = ":PP_PARAM_LIGHT_SPECULAR";
      break;
    case 3:
      pcVar5 = ":PP_PARAM_LIGHT_POSITION";
      break;
    case 4:
      pcVar5 = ":PP_PARAM_LIGHT_DIRECTION";
      break;
    case 5:
      pcVar5 = ":PP_PARAM_LIGHT_ATTENUATION";
      break;
    case 6:
      pcVar5 = ":PP_PARAM_LIGHT_HALF";
      break;
    case 7:
      pcVar5 = ":PP_PARAM_LIGHT_SPOTCUTOFF";
      break;
    default:
      goto switchD_97bafb24_default;
    }
    break;
  case 4:
    iVar2 = ((int (*)())scpy)(pcVar6,": PP_BIND_PARAM_LIGHT_PROD:");
    pcVar6 = pcVar6 + iVar2;
    iVar2 = ((int (*)())ncpy)(pcVar6,uStack00000018 & 0xff);
    pcVar6 = pcVar6 + iVar2;
    iVar2 = ((int (*)())scpy)(pcVar6,":");
    iVar3 = ((int (*)())ncpy)(pcVar6 + iVar2,uStack00000018 >> 8 & 1);
    pcVar6 = pcVar6 + iVar2 + iVar3;
    uVar4 = uStack00000018 >> 9 & 3;
    if (uVar4 == 1) {
      pcVar5 = ":PP_PARAM_LIGHT_PROD_DIFFUSE";
    }
    else if (uVar4 == 0) {
      pcVar5 = ":PP_PARAM_LIGHT_PROD_AMBIENT";
    }
    else {
      if (uVar4 != 2) goto switchD_97bafb24_default;
      pcVar5 = ":PP_PARAM_LIGHT_PROD_SPECULAR";
    }
    break;
  case 5:
    iVar2 = ((int (*)())scpy)(pcVar6,": PP_BIND_PARAM_MATERIAL:");
    iVar3 = ((int (*)())ncpy)(pcVar6 + iVar2,uStack00000018 & 1);
    pcVar6 = pcVar6 + iVar2 + iVar3;
    switch(uStack00000018 >> 1 & 7) {
    case 0:
      pcVar5 = ":PP_PARAM_MATERIAL_AMBIENT";
      break;
    case 1:
      pcVar5 = ":PP_PARAM_MATERIAL_DIFFUSE";
      break;
    case 2:
      pcVar5 = ":PP_PARAM_MATERIAL_SPECULAR";
      break;
    case 3:
      pcVar5 = ":PP_PARAM_MATERIAL_EMISSION";
      break;
    case 4:
      pcVar5 = ":PP_PARAM_MATERIAL_SHININESS";
      break;
    case 5:
      pcVar5 = ":PP_PARAM_MATERIAL_SCENE_COLOR";
      break;
    default:
      goto switchD_97bafb24_default;
    }
    break;
  case 6:
    pcVar5 = ": PP_BIND_PARAM_LIGHT_MODEL";
    break;
  case 7:
    pcVar5 = ": PP_BIND_PARAM_TEX_GEN_EYE_PLANE:";
    goto LAB_97baf9a4;
  case 8:
    pcVar5 = ": PP_BIND_PARAM_TEX_GEN_OBJECT_PLANE:";
LAB_97baf9a4:
    iVar2 = ((int (*)())scpy)(pcVar6,pcVar5);
    pcVar6 = pcVar6 + iVar2;
    uVar4 = uStack00000018 >> 5 & 7;
    if (uVar4 == 1) {
      pcVar5 = "PP_PARAM_TEX_GEN_COORD_T:";
LAB_97bafa10:
      iVar2 = ((int (*)())scpy)(pcVar6,pcVar5);
      pcVar6 = pcVar6 + iVar2;
    }
    else {
      if (uVar4 == 0) {
        pcVar5 = "PP_PARAM_TEX_GEN_COORD_S:";
        goto LAB_97bafa10;
      }
      if (uVar4 == 2) {
        pcVar5 = "PP_PARAM_TEX_GEN_COORD_R:";
        goto LAB_97bafa10;
      }
      if (uVar4 == 3) {
        pcVar5 = "PP_PARAM_TEX_GEN_COORD_Q:";
        goto LAB_97bafa10;
      }
    }
    uVar4 = uStack00000018 & 0x1f;
    goto LAB_97baf760;
  default:
    pcVar5 = ": Error, binding not found.";
    break;
  case 10:
    pcVar5 = ": PP_BIND_PARAM_CLIP_PLANE:";
    goto LAB_97bafb84;
  case 0xb:
    pcVar5 = ": PP_BIND_PARAM_FOG_COLOR";
    break;
  case 0xc:
    pcVar5 = ": PP_BIND_PARAM_FOG_PARAMETERS";
    break;
  case 0xd:
    pcVar5 = ": PP_BIND_PARAM_POINT_PARAMETERS";
    break;
  case 0xe:
    pcVar5 = ": PP_BIND_PARAM_POINT_ATTENUATION";
    break;
  case 0xf:
    pcVar5 = ": PP_BIND_PARAM_DEPTH_RANGE";
    break;
  case 0x10:
    iVar2 = ((int (*)())scpy)(pcVar6,": PP_BIND_PARAM_MATRIX:");
    pcVar6 = pcVar6 + iVar2;
    uVar4 = uStack00000018 >> 0xe & 3;
    if (uVar4 == 1) {
      pcVar5 = "PP_MATRIX_TRANSFORM_TRANSPOSE:";
LAB_97bafae0:
      iVar2 = ((int (*)())scpy)(pcVar6,pcVar5);
      pcVar6 = pcVar6 + iVar2;
    }
    else {
      if (uVar4 == 0) {
        pcVar5 = "PP_MATRIX_TRANSFORM_IDENTITY:";
        goto LAB_97bafae0;
      }
      if (uVar4 == 2) {
        pcVar5 = "PP_MATRIX_TRANSFORM_INVERSE:";
        goto LAB_97bafae0;
      }
      if (uVar4 == 3) {
        pcVar5 = "PP_MATRIX_TRANSFORM_INVERSE_TRANSPOSE:";
        goto LAB_97bafae0;
      }
    }
    iVar2 = ((int (*)())ncpy)(pcVar6,uStack00000018 >> 0xc & 3);
    pcVar6 = pcVar6 + iVar2;
    switch(uStack00000018 >> 8 & 7) {
    case 0:
      pcVar5 = ":PP_PARAM_MATRIX_MODELVIEW_PROJECTION";
      break;
    case 1:
      pcVar5 = ":PP_PARAM_MATRIX_PROJECTION";
      break;
    case 2:
      pcVar5 = ":PP_PARAM_MATRIX_COLOR";
      break;
    case 3:
      pcVar5 = ":PP_PARAM_MATRIX_MODELVIEW:";
      goto LAB_97bafb84;
    case 4:
      pcVar5 = ":PP_PARAM_MATRIX_TEXTURE:";
      goto LAB_97bafb84;
    case 5:
      pcVar5 = ":PP_PARAM_MATRIX_PROGRAM:";
LAB_97bafb84:
      iVar2 = ((int (*)())scpy)(pcVar6,pcVar5);
      uVar4 = uStack00000018 & 0xff;
      goto LAB_97baf75c;
    default:
      goto switchD_97bafb24_default;
    }
    break;
  case 0x11:
    pcVar5 = ": PP_BIND_PARAM_CONSTANT:";
LAB_97baf750:
    iVar2 = ((int (*)())scpy)(pcVar6,pcVar5);
    uVar4 = uStack00000018 & 0xffff;
LAB_97baf75c:
    pcVar6 = pcVar6 + iVar2;
LAB_97baf760:
    iVar2 = ((int (*)())ncpy)(pcVar6,uVar4);
    goto LAB_97bafbc8;
  case 0x12:
    pcVar5 = ": PP_BIND_PARAM_NORMAL_SCALE";
  }
  iVar2 = ((int (*)())scpy)(pcVar6,pcVar5);
LAB_97bafbc8:
  pcVar6 = pcVar6 + iVar2;
switchD_97bafb24_default:
  *pcVar6 = '\0';
  _realloc(pcVar1,(size_t)(pcVar6 + (1 - (int)pcVar1)));
  return;
}

/* PrintOutput @ 0x97bafbf4 (420 bytes) */
int PrintOutput(param_1, param_2)
  uint param_1;
  uint param_2;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  uint uStack00000018;
  uint uStack0000001c;
  
  uStack00000018 = param_1;
  uStack0000001c = param_2;
  pcVar1 = _malloc(0x100);
  iVar2 = ((int (*)())ncpy)(pcVar1,uStack0000001c & 0xffff);
  pcVar6 = pcVar1 + iVar2;
  switch(uStack00000018 >> 0x10 & 0xf) {
  default:
    pcVar5 = ": Error, binding not found.";
    break;
  case 1:
    pcVar5 = ": PP_BIND_OUTPUT_RESULT_POSITION";
    break;
  case 2:
    pcVar5 = ": PP_BIND_OUTPUT_RESULT_FOG_COORD";
    break;
  case 3:
    pcVar5 = ": PP_BIND_OUTPUT_RESULT_POINT_SIZE";
    break;
  case 4:
    iVar2 = ((int (*)())scpy)(pcVar6,": PP_BIND_OUTPUT_RESULT_COLOR:");
    if ((uStack00000018 & 1) == 0) {
      pcVar5 = "PP_FACE_FRONT:";
    }
    else {
      pcVar5 = "PP_FACE_BACK:";
    }
    iVar3 = ((int (*)())scpy)(pcVar6 + iVar2,pcVar5);
    pcVar6 = pcVar6 + iVar2 + iVar3;
    uVar4 = uStack00000018 >> 1 & 7;
    goto LAB_97bafcf4;
  case 5:
    iVar2 = ((int (*)())scpy)(pcVar6,": PP_BIND_OUTPUT_RESULT_SEC_COLOR:");
    pcVar6 = pcVar6 + iVar2;
    if ((uStack00000018 & 1) == 0) {
      pcVar5 = "PP_FACE_FRONT";
    }
    else {
      pcVar5 = "PP_FACE_BACK";
    }
    break;
  case 6:
    pcVar5 = ": PP_BIND_OUTPUT_RESULT_TEX_COORD:";
    goto LAB_97bafd6c;
  case 7:
    pcVar5 = ": PP_BIND_OUTPUT_RESULT_DEPTH";
    break;
  case 8:
    pcVar5 = ": PP_BIND_OUTPUT_RESULT_EYE_POSITION";
    break;
  case 9:
    pcVar5 = ": PP_BIND_OUTPUT_RESULT_CLIP_VERTEX";
    break;
  case 10:
    pcVar5 = ": PP_BIND_OUTPUT_RESULT_ATTRIB:";
LAB_97bafd6c:
    iVar2 = ((int (*)())scpy)(pcVar6,pcVar5);
    pcVar6 = pcVar6 + iVar2;
    uVar4 = uStack00000018 & 0x1f;
LAB_97bafcf4:
    iVar2 = ((int (*)())ncpy)(pcVar6,uVar4);
    goto LAB_97bafd98;
  }
  iVar2 = ((int (*)())scpy)(pcVar6,pcVar5);
LAB_97bafd98:
  pcVar6[iVar2] = '\0';
  _realloc(pcVar1,(size_t)(pcVar6 + iVar2 + (1 - (int)pcVar1)));
  return;
}

/* PrintTemp @ 0x97bafdc4 (76 bytes) */
int PrintTemp(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  char *pcVar1;
  int iVar2;
  undefined4 uStack00000018;
  uint uStack0000001c;
  
  uStack00000018 = param_1;
  uStack0000001c = param_2;
  pcVar1 = _malloc(0x10);
  iVar2 = ((int (*)())ncpy)(pcVar1,uStack0000001c & 0xffff);
  pcVar1[iVar2] = '\0';
  return pcVar1;
}

/* Binding__ClearName @ 0x97bafe10 (72 bytes) */
int Binding__ClearName(this)
  unsigned char *this;
{
  if (*(void **)(this + 8) != (void *)0x0) {
    _free(*(void **)(this + 8));
  }
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}

/* Binding__Binding @ 0x97bafe58 (4 bytes) */
int Binding__Binding(this)
  unsigned char *this;
{
  this[0x35] = (Binding)0x0;
  *(undefined4 *)(this + 0x20) = 0xffffffff;
  *(undefined4 *)(this + 0x1c) = 1;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 1;
  *(undefined2 *)(this + 0x24) = 0;
  *(undefined4 *)this = 0;
  this[0x34] = (Binding)0x0;
  return;
}

/* Binding__Binding_97bafe5c @ 0x97bafe5c (4 bytes) */
int Binding__Binding_97bafe5c(this)
  unsigned char *this;
{
  this[0x35] = (Binding)0x0;
  *(undefined4 *)(this + 0x20) = 0xffffffff;
  *(undefined4 *)(this + 0x1c) = 1;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 1;
  *(undefined2 *)(this + 0x24) = 0;
  *(undefined4 *)this = 0;
  this[0x34] = (Binding)0x0;
  return;
}

/* Binding__Binding_97bafe60 @ 0x97bafe60 (76 bytes) */
int Binding__Binding_97bafe60(this)
  unsigned char *this;
{
  this[0x35] = (Binding)0x0;
  *(undefined4 *)(this + 0x20) = 0xffffffff;
  *(undefined4 *)(this + 0x1c) = 1;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x18) = 1;
  *(undefined2 *)(this + 0x24) = 0;
  *(undefined4 *)this = 0;
  this[0x34] = (Binding)0x0;
  return;
}

/* Binding___Binding @ 0x97bafeac (8 bytes) */
int Binding___Binding(this)
  unsigned char *this;
{
  ~Binding(this);
  return;
}

/* Binding___Binding_97bafeb4 @ 0x97bafeb4 (8 bytes) */
int Binding___Binding_97bafeb4(this)
  unsigned char *this;
{
  ~Binding(this);
  return;
}

/* Binding___Binding_97bafebc @ 0x97bafebc (4 bytes) */
int Binding___Binding_97bafebc(this)
  unsigned char *this;
{
  if (*(void **)(this + 8) != (void *)0x0) {
    _free(*(void **)(this + 8));
  }
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}

/* Binding__Binding_97bafec0 @ 0x97bafec0 (4 bytes) */
int Binding__Binding_97bafec0(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  bool bVar4;
  ushort uVar3;
  ulong uVar2;
  char *pcVar5;
  
  *(undefined4 *)(this + 8) = 0;
  pcVar5 = *(char **)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  SetName(this,pcVar5);
  iVar1 = ((int (*)())Binding__GetLocation)(param_1);
  ((int (*)())Binding__SetLocation)(this,iVar1);
  iVar1 = ((int (*)())Binding__GetActiveIndex)(param_1);
  ((int (*)())Binding__SetActiveIndex)(this,iVar1);
  bVar4 = (bool)((int (*)())Binding__IsClientRequest)(param_1);
  ((int (*)())Binding__SetClientRequest)(this,bVar4);
  bVar4 = (bool)((int (*)())Binding__IsBuiltIn)(param_1);
  ((int (*)())Binding__SetBuiltIn)(this,bVar4);
  uVar3 = ((int (*)())Binding__GetOpenGLType)(param_1);
  ((int (*)())Binding__SetOpenGLType)(this,uVar3);
  uVar2 = ((int (*)())Binding__GetDecSize)(param_1);
  ((int (*)())Binding__SetDecSize)(this,uVar2);
  uVar2 = ((int (*)())Binding__GetActualSize)(param_1);
  ((int (*)())Binding__SetActualSize)(this,uVar2);
  this[0x35] = (Binding)0x0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  this[0x34] = (Binding)0x0;
  return;
}

/* Binding__Binding_97bafec4 @ 0x97bafec4 (4 bytes) */
int Binding__Binding_97bafec4(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  bool bVar4;
  ushort uVar3;
  ulong uVar2;
  char *pcVar5;
  
  *(undefined4 *)(this + 8) = 0;
  pcVar5 = *(char **)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  SetName(this,pcVar5);
  iVar1 = ((int (*)())Binding__GetLocation)(param_1);
  ((int (*)())Binding__SetLocation)(this,iVar1);
  iVar1 = ((int (*)())Binding__GetActiveIndex)(param_1);
  ((int (*)())Binding__SetActiveIndex)(this,iVar1);
  bVar4 = (bool)((int (*)())Binding__IsClientRequest)(param_1);
  ((int (*)())Binding__SetClientRequest)(this,bVar4);
  bVar4 = (bool)((int (*)())Binding__IsBuiltIn)(param_1);
  ((int (*)())Binding__SetBuiltIn)(this,bVar4);
  uVar3 = ((int (*)())Binding__GetOpenGLType)(param_1);
  ((int (*)())Binding__SetOpenGLType)(this,uVar3);
  uVar2 = ((int (*)())Binding__GetDecSize)(param_1);
  ((int (*)())Binding__SetDecSize)(this,uVar2);
  uVar2 = ((int (*)())Binding__GetActualSize)(param_1);
  ((int (*)())Binding__SetActualSize)(this,uVar2);
  this[0x35] = (Binding)0x0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  this[0x34] = (Binding)0x0;
  return;
}

/* Binding__Binding_97bafec8 @ 0x97bafec8 (224 bytes) */
int Binding__Binding_97bafec8(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  bool bVar4;
  ushort uVar3;
  ulong uVar2;
  char *pcVar5;
  
  *(undefined4 *)(this + 8) = 0;
  pcVar5 = *(char **)(param_1 + 8);
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  SetName(this,pcVar5);
  iVar1 = ((int (*)())Binding__GetLocation)(param_1);
  ((int (*)())Binding__SetLocation)(this,iVar1);
  iVar1 = ((int (*)())Binding__GetActiveIndex)(param_1);
  ((int (*)())Binding__SetActiveIndex)(this,iVar1);
  bVar4 = (bool)((int (*)())Binding__IsClientRequest)(param_1);
  ((int (*)())Binding__SetClientRequest)(this,bVar4);
  bVar4 = (bool)((int (*)())Binding__IsBuiltIn)(param_1);
  ((int (*)())Binding__SetBuiltIn)(this,bVar4);
  uVar3 = ((int (*)())Binding__GetOpenGLType)(param_1);
  ((int (*)())Binding__SetOpenGLType)(this,uVar3);
  uVar2 = ((int (*)())Binding__GetDecSize)(param_1);
  ((int (*)())Binding__SetDecSize)(this,uVar2);
  uVar2 = ((int (*)())Binding__GetActualSize)(param_1);
  ((int (*)())Binding__SetActualSize)(this,uVar2);
  this[0x35] = (Binding)0x0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  this[0x34] = (Binding)0x0;
  return;
}

/* Binding__operator_ @ 0x97baffa8 (232 bytes) */
int Binding__operator_(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  Binding BVar1;
  int iVar2;
  bool bVar5;
  ushort uVar4;
  ulong uVar3;
  
  if (this != param_1) {
    SetName(this,*(char **)(param_1 + 8));
    iVar2 = ((int (*)())Binding__GetLocation)(param_1);
    ((int (*)())Binding__SetLocation)(this,iVar2);
    iVar2 = ((int (*)())Binding__GetActiveIndex)(param_1);
    ((int (*)())Binding__SetActiveIndex)(this,iVar2);
    bVar5 = (bool)((int (*)())Binding__IsClientRequest)(param_1);
    ((int (*)())Binding__SetClientRequest)(this,bVar5);
    bVar5 = (bool)((int (*)())Binding__IsBuiltIn)(param_1);
    ((int (*)())Binding__SetBuiltIn)(this,bVar5);
    uVar4 = ((int (*)())Binding__GetOpenGLType)(param_1);
    ((int (*)())Binding__SetOpenGLType)(this,uVar4);
    uVar3 = ((int (*)())Binding__GetDecSize)(param_1);
    ((int (*)())Binding__SetDecSize)(this,uVar3);
    uVar3 = ((int (*)())Binding__GetActualSize)(param_1);
    ((int (*)())Binding__SetActualSize)(this,uVar3);
    this[0x34] = param_1[0x34];
    BVar1 = param_1[0x35];
    *(undefined4 *)(this + 4) = 0;
    this[0x35] = BVar1;
    *(undefined4 *)this = 0;
  }
  return this;
}

/* operator__ @ 0x97bb0090 (88 bytes) */
int operator__(param_1, param_2)
  unsigned char *param_1;
  unsigned char *param_2;
{
  int iVar1;
  
  if (((*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc)) &&
      (*(size_t *)(param_1 + 0x10) == *(size_t *)(param_2 + 0x10))) &&
     (iVar1 = _strncmp(*(char **)(param_1 + 8),*(char **)(param_2 + 8),*(size_t *)(param_1 + 0x10)),
     iVar1 == 0)) {
    return 1;
  }
  return 0;
}

/* Binding__CatName @ 0x97bb00e8 (208 bytes) */
int Binding__CatName(this, param_1)
  unsigned char *this;
  char *param_1;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  int iVar6;
  
  if (param_1 != (char *)0x0) {
    sVar4 = _strlen(param_1);
    pcVar5 = _malloc(sVar4 + *(int *)(this + 0x10) + 1);
    if (*(char **)(this + 8) != (char *)0x0) {
      _strncpy(pcVar5,*(char **)(this + 8),*(int *)(this + 0x10) + 1);
    }
    _strncpy(pcVar5 + *(int *)(this + 0x10),param_1,sVar4 + 1);
    *(size_t *)(this + 0x10) = *(int *)(this + 0x10) + sVar4;
    _free(*(void **)(this + 8));
    iVar2 = *(int *)(this + 0x10);
    iVar6 = 0;
    *(undefined4 *)(this + 0xc) = 0;
    *(char **)(this + 8) = pcVar5;
    if (iVar2 != 0) {
      iVar3 = 0;
      do {
        pcVar1 = pcVar5 + iVar6;
        iVar6 = iVar6 + 1;
        iVar3 = iVar3 + *pcVar1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      *(int *)(this + 0xc) = iVar3;
    }
  }
  return;
}

/* Binding__SetName @ 0x97bb01b8 (164 bytes) */
int Binding__SetName(this, param_1)
  unsigned char *this;
  char *param_1;
{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  
  ClearName(this);
  if ((param_1 != (char *)0x0) && (sVar2 = _strlen(param_1), 0 < (int)sVar2)) {
    *(size_t *)(this + 0x10) = sVar2;
    pcVar3 = _malloc(sVar2 + 1);
    *(char **)(this + 8) = pcVar3;
    _strncpy(pcVar3,param_1,*(int *)(this + 0x10) + 1);
    iVar1 = *(int *)(this + 0x10);
    iVar4 = 0;
    *(undefined4 *)(this + 0xc) = 0;
    if (iVar1 != 0) {
      do {
        pcVar3 = (char *)(*(int *)(this + 8) + iVar4);
        iVar4 = iVar4 + 1;
        *(int *)(this + 0xc) = *(int *)(this + 0xc) + (int)*pcVar3;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

/* Binding__SetNameFromArrayName @ 0x97bb025c (332 bytes) */
int Binding__SetNameFromArrayName(this, param_1)
  unsigned char *this;
  char *param_1;
{
  bool bVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  ClearName(this);
  iVar6 = 0;
  if ((param_1 != (char *)0x0) && (sVar2 = _strlen(param_1), 0 < (int)sVar2)) {
    *(size_t *)(this + 0x10) = sVar2;
    pcVar3 = _malloc(sVar2 + 1);
    *(char **)(this + 8) = pcVar3;
    _strncpy(pcVar3,param_1,*(int *)(this + 0x10) + 1);
    iVar4 = *(int *)(this + 8);
    iVar5 = *(int *)(this + 0x10);
    if (*(char *)(iVar4 + iVar5 + -1) == ']') {
      bVar1 = false;
      iVar7 = iVar5 + -1;
      do {
        iVar7 = iVar7 + -1;
        if (*(char *)(iVar4 + iVar7) == '[') {
          bVar1 = true;
        }
        if (iVar7 < 0) {
          if (!bVar1) goto LAB_97bb0358;
          break;
        }
      } while (!bVar1);
      iVar6 = _atoi((char *)(iVar4 + iVar7 + 1));
      iVar5 = iVar7;
      if (iVar7 < *(int *)(this + 0x10) + 1) {
        do {
          *(undefined1 *)(*(int *)(this + 8) + iVar5) = 0;
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(this + 0x10) + 1);
      }
      *(int *)(this + 0x10) = iVar7;
      iVar5 = iVar7;
    }
LAB_97bb0358:
    iVar4 = 0;
    *(undefined4 *)(this + 0xc) = 0;
    if (iVar5 != 0) {
      do {
        pcVar3 = (char *)(*(int *)(this + 8) + iVar4);
        iVar4 = iVar4 + 1;
        *(int *)(this + 0xc) = *(int *)(this + 0xc) + (int)*pcVar3;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  return iVar6;
}

/* Binding__RemoveNameBackToChar @ 0x97bb03a8 (132 bytes) */
int Binding__RemoveNameBackToChar(this, param_1)
  unsigned char *this;
  int param_1;
{
  char *pcVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(this + 0x10);
  bVar2 = false;
  if (-1 < iVar3) {
    do {
      if ((int)*(char *)(*(int *)(this + 8) + iVar3) == CONCAT31(in_register_00000010,param_1)) {
        bVar2 = true;
      }
      *(undefined1 *)(*(int *)(this + 8) + iVar3) = 0;
      iVar3 = iVar3 + -1;
    } while ((-1 < iVar3) && (!bVar2));
  }
  iVar3 = iVar3 + 1;
  iVar4 = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(int *)(this + 0x10) = iVar3;
  if (0 < iVar3) {
    do {
      pcVar1 = (char *)(*(int *)(this + 8) + iVar4);
      iVar4 = iVar4 + 1;
      *(int *)(this + 0xc) = *(int *)(this + 0xc) + (int)*pcVar1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    return;
  }
  return;
}

/* Binding__GetHash @ 0x97bb042c (20 bytes) */
int Binding__GetHash(this, param_1)
  unsigned char *this;
  uint param_1;
{
  return *(uint *)(this + 0xc) - (*(uint *)(this + 0xc) / param_1) * param_1;
}

/* Binding__IsClientRequest @ 0x97bb0440 (8 bytes) */
int Binding__IsClientRequest(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x2c);
}

/* Binding__SetClientRequest @ 0x97bb0448 (8 bytes) */
int Binding__SetClientRequest(this, param_1)
  unsigned char *this;
  int param_1;
{
  undefined3 in_register_00000010;
  
  *(uint *)(this + 0x2c) = CONCAT31(in_register_00000010,param_1);
  return;
}

/* Binding__IsBuiltIn @ 0x97bb0450 (8 bytes) */
int Binding__IsBuiltIn(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x30);
}

/* Binding__SetBuiltIn @ 0x97bb0458 (8 bytes) */
int Binding__SetBuiltIn(this, param_1)
  unsigned char *this;
  int param_1;
{
  undefined3 in_register_00000010;
  
  *(uint *)(this + 0x30) = CONCAT31(in_register_00000010,param_1);
  return;
}

/* Binding__GetLocation @ 0x97bb0460 (8 bytes) */
int Binding__GetLocation(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x14);
}

/* Binding__SetLocation @ 0x97bb0468 (8 bytes) */
int Binding__SetLocation(this, param_1)
  unsigned char *this;
  int param_1;
{
  *(int *)(this + 0x14) = param_1;
  return;
}

/* Binding__GetActiveIndex @ 0x97bb0470 (8 bytes) */
int Binding__GetActiveIndex(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x20);
}

/* Binding__SetActiveIndex @ 0x97bb0478 (8 bytes) */
int Binding__SetActiveIndex(this, param_1)
  unsigned char *this;
  int param_1;
{
  *(int *)(this + 0x20) = param_1;
  return;
}

/* Binding__SetOpenGLType @ 0x97bb0480 (8 bytes) */
int Binding__SetOpenGLType(this, param_1)
  unsigned char *this;
  int param_1;
{
  *(ushort *)(this + 0x24) = param_1;
  return;
}

/* Binding__GetOpenGLType @ 0x97bb0488 (8 bytes) */
int Binding__GetOpenGLType(this)
  unsigned char *this;
{
  return *(undefined2 *)(this + 0x24);
}

/* Binding__GetBindingBasicSize @ 0x97bb0490 (8 bytes) */
int Binding__GetBindingBasicSize(this)
  unsigned char *this;
{
  GetVec4sForType(*(ushort *)(this + 0x24));
  return;
}

/* Binding__GetBindingSlots @ 0x97bb0498 (8 bytes) */
int Binding__GetBindingSlots(this)
  unsigned char *this;
{
  GetVec4sForType(*(ushort *)(this + 0x24));
  return;
}

/* Binding__SetDecSize @ 0x97bb04a0 (8 bytes) */
int Binding__SetDecSize(this, param_1)
  unsigned char *this;
  ulong param_1;
{
  *(ulong *)(this + 0x18) = param_1;
  return;
}

/* Binding__SetActualSize @ 0x97bb04a8 (8 bytes) */
int Binding__SetActualSize(this, param_1)
  unsigned char *this;
  ulong param_1;
{
  *(ulong *)(this + 0x1c) = param_1;
  return;
}

/* Binding__GetDecSize @ 0x97bb04b0 (8 bytes) */
int Binding__GetDecSize(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x18);
}

/* Binding__GetActualSize @ 0x97bb04b8 (8 bytes) */
int Binding__GetActualSize(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x1c);
}

/* Binding__GetNextBinding @ 0x97bb04c0 (8 bytes) */
int Binding__GetNextBinding(this)
  unsigned char *this;
{
  return *(undefined4 *)this;
}

/* Binding__GetNextBindingInHash @ 0x97bb04c8 (8 bytes) */
int Binding__GetNextBindingInHash(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 4);
}

/* Binding__SetNextBinding @ 0x97bb04d0 (8 bytes) */
int Binding__SetNextBinding(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  *(Binding **)this = param_1;
  return;
}

/* Binding__SetNextBindingInHash @ 0x97bb04d8 (8 bytes) */
int Binding__SetNextBindingInHash(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  *(Binding **)(this + 4) = param_1;
  return;
}

/* Binding__GetString @ 0x97bb04e0 (256 bytes) */
int Binding__GetString(this)
  unsigned char *this;
{
  int iVar1;
  size_t sVar2;
  ushort uVar9;
  char *pcVar3;
  size_t sVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined8 local_30 [2];
  
  local_30[0] = _PTR_s__02d____02d____s____s__c__c_a7b7d6bc;
  iVar1 = ((int (*)())Binding__IsClientRequest)(this);
  sVar2 = _strlen(*(char **)((int)local_30 + iVar1 * 4));
  iVar1 = *(int *)(this + 0x10);
  uVar9 = ((int (*)())Binding__GetOpenGLType)(this);
  pcVar3 = (char *)GetGLStringForType(uVar9);
  sVar4 = _strlen(pcVar3);
  pcVar5 = _malloc(sVar2 + iVar1 + sVar4 + 0x15);
  pcVar3 = (char *)0x0;
  if (pcVar5 != (char *)0x0) {
    iVar1 = ((int (*)())Binding__IsClientRequest)(this);
    uVar6 = ((int (*)())Binding__GetActiveIndex)(this);
    uVar7 = ((int (*)())Binding__GetLocation)(this);
    uVar9 = ((int (*)())Binding__GetOpenGLType)(this);
    uVar12 = *(undefined4 *)(this + 8);
    uVar8 = GetGLStringForType(uVar9);
    uVar10 = 0x56;
    if (this[0x34] == (Binding)0x0) {
      uVar10 = 0x20;
    }
    uVar11 = 0x46;
    if (this[0x35] == (Binding)0x0) {
      uVar11 = 0x20;
    }
    _sprintf(pcVar5,*(char **)((int)local_30 + iVar1 * 4),uVar6,uVar7,uVar12,uVar8,uVar10,uVar11);
    pcVar3 = pcVar5;
  }
  return pcVar3;
}

/* BindingTable__BindingTable @ 0x97bb05e0 (4 bytes) */
int BindingTable__BindingTable(this, param_1)
  unsigned char *this;
  uint param_1;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  
  *(uint *)this = param_1;
  pvVar3 = operator_new__(param_1 << 2);
  uVar4 = 0;
  *(void **)(this + 8) = pvVar3;
  *(undefined4 *)(this + 4) = 0;
  uVar2 = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 8)) = 0;
      uVar2 = *(uint *)this;
    } while (uVar4 < uVar2);
  }
  pvVar3 = operator_new__(uVar2 << 2);
  uVar4 = 0;
  *(void **)(this + 0x10) = pvVar3;
  *(undefined4 *)(this + 0xc) = 0;
  uVar2 = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 0x10)) = 0;
      uVar2 = *(uint *)this;
    } while (uVar4 < uVar2);
  }
  pvVar3 = operator_new__(uVar2 << 2);
  uVar2 = 0;
  *(void **)(this + 0x18) = pvVar3;
  *(undefined4 *)(this + 0x14) = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar2 * 4;
      uVar2 = uVar2 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 0x18)) = 0;
    } while (uVar2 < *(uint *)this);
  }
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  return;
}

/* BindingTable__BindingTable_97bb05e4 @ 0x97bb05e4 (4 bytes) */
int BindingTable__BindingTable_97bb05e4(this, param_1)
  unsigned char *this;
  uint param_1;
{
  BindingTable(this,param_1);
  return;
}

/* BindingTable__BindingTable_97bb05e8 @ 0x97bb05e8 (288 bytes) */
int BindingTable__BindingTable_97bb05e8(this, param_1)
  unsigned char *this;
  uint param_1;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  
  *(uint *)this = param_1;
  pvVar3 = operator_new__(param_1 << 2);
  uVar4 = 0;
  *(void **)(this + 8) = pvVar3;
  *(undefined4 *)(this + 4) = 0;
  uVar2 = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 8)) = 0;
      uVar2 = *(uint *)this;
    } while (uVar4 < uVar2);
  }
  pvVar3 = operator_new__(uVar2 << 2);
  uVar4 = 0;
  *(void **)(this + 0x10) = pvVar3;
  *(undefined4 *)(this + 0xc) = 0;
  uVar2 = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 0x10)) = 0;
      uVar2 = *(uint *)this;
    } while (uVar4 < uVar2);
  }
  pvVar3 = operator_new__(uVar2 << 2);
  uVar2 = 0;
  *(void **)(this + 0x18) = pvVar3;
  *(undefined4 *)(this + 0x14) = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar2 * 4;
      uVar2 = uVar2 + 1;
      *(undefined4 *)(iVar1 + *(int *)(this + 0x18)) = 0;
    } while (uVar2 < *(uint *)this);
  }
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  return;
}

/* BindingTable___BindingTable @ 0x97bb0708 (8 bytes) */
int BindingTable___BindingTable(this)
  unsigned char *this;
{
  ~BindingTable(this);
  return;
}

/* BindingTable___BindingTable_97bb0710 @ 0x97bb0710 (8 bytes) */
int BindingTable___BindingTable_97bb0710(this)
  unsigned char *this;
{
  ~BindingTable(this);
  return;
}

/* BindingTable___BindingTable_97bb0718 @ 0x97bb0718 (148 bytes) */
int BindingTable___BindingTable_97bb0718(this)
  unsigned char *this;
{
  bool bVar1;
  Binding *pBVar2;
  Binding *this_00;
  
  this_00 = *(Binding **)(this + 4);
  bVar1 = this_00 == (unsigned char *)0x0;
  if (!bVar1) {
    while( true ) {
      pBVar2 = (unsigned char *)((int (*)())Binding__GetNextBinding)(this_00);
      if (!bVar1) {
        ((int (*)())Binding___Binding)(this_00);
        operator_delete(this_00);
      }
      if (pBVar2 == (unsigned char *)0x0) break;
      bVar1 = false;
      this_00 = pBVar2;
    }
  }
  ((int (*)())BindingTable__ClearInternalBindings)(this);
  operator_delete(*(void **)(this + 8));
  operator_delete(*(void **)(this + 0x10));
  operator_delete(*(void **)(this + 0x18));
  return;
}

/* BindingTable__ClearInternalBindings @ 0x97bb07ac (336 bytes) */
int BindingTable__ClearInternalBindings(this)
  unsigned char *this;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  Binding *pBVar4;
  uint uVar5;
  Binding *pBVar6;
  
  pBVar6 = *(Binding **)(this + 0xc);
  *(undefined4 *)(this + 0x40) = 0;
  bVar1 = pBVar6 == (unsigned char *)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  if (!bVar1) {
    while( true ) {
      pBVar4 = (unsigned char *)((int (*)())Binding__GetNextBinding)(pBVar6);
      if (!bVar1) {
        ((int (*)())Binding___Binding)(pBVar6);
        operator_delete(pBVar6);
      }
      if (pBVar4 == (unsigned char *)0x0) break;
      bVar1 = false;
      pBVar6 = pBVar4;
    }
  }
  pBVar6 = *(Binding **)(this + 0x14);
  *(undefined4 *)(this + 0xc) = 0;
  bVar1 = pBVar6 == (unsigned char *)0x0;
  if (!bVar1) {
    while( true ) {
      pBVar4 = (unsigned char *)((int (*)())Binding__GetNextBinding)(pBVar6);
      if (!bVar1) {
        ((int (*)())Binding___Binding)(pBVar6);
        operator_delete(pBVar6);
      }
      if (pBVar4 == (unsigned char *)0x0) break;
      bVar1 = false;
      pBVar6 = pBVar4;
    }
  }
  uVar5 = 0;
  *(undefined4 *)(this + 0x14) = 0;
  uVar3 = 0;
  if (*(int *)this != 0) {
    do {
      iVar2 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(iVar2 + *(int *)(this + 0x10)) = 0;
      uVar3 = *(uint *)this;
    } while (uVar5 < uVar3);
  }
  uVar5 = 0;
  if (uVar3 != 0) {
    do {
      iVar2 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(iVar2 + *(int *)(this + 0x18)) = 0;
    } while (uVar5 < *(uint *)this);
  }
  return;
}

/* BindingTable__InsertAttribRequestBinding @ 0x97bb08fc (244 bytes) */
int BindingTable__InsertAttribRequestBinding(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  Binding *pBVar1;
  int iVar2;
  Binding *pBVar3;
  
  if (param_1 != (unsigned char *)0x0) {
    pBVar1 = (unsigned char *)((int (*)())BindingTable__FindAttribRequestBinding)(this,param_1);
    if (pBVar1 == (unsigned char *)0x0) {
      pBVar1 = *(Binding **)(this + 4);
      if (*(Binding **)(this + 4) == (unsigned char *)0x0) {
        *(Binding **)(this + 4) = param_1;
        iVar2 = ((int (*)())Binding__GetHash)(param_1,*(uint *)this);
        *(Binding **)(iVar2 * 4 + *(int *)(this + 8)) = param_1;
      }
      else {
        do {
          pBVar3 = pBVar1;
          pBVar1 = (unsigned char *)((int (*)())Binding__GetNextBinding)(pBVar3);
        } while (pBVar1 != (unsigned char *)0x0);
        ((int (*)())Binding__SetNextBinding)(pBVar3,param_1);
        iVar2 = ((int (*)())Binding__GetHash)(param_1,*(uint *)this);
        pBVar1 = *(Binding **)(iVar2 * 4 + *(int *)(this + 8));
        if (pBVar1 == (unsigned char *)0x0) {
          *(Binding **)(iVar2 * 4 + *(int *)(this + 8)) = param_1;
        }
        else {
          do {
            pBVar3 = pBVar1;
            pBVar1 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(pBVar3);
          } while (pBVar1 != (unsigned char *)0x0);
          ((int (*)())Binding__SetNextBindingInHash)(pBVar3,param_1);
        }
      }
      return 1;
    }
    iVar2 = ((int (*)())Binding__GetLocation)(param_1);
    ((int (*)())Binding__SetLocation)(pBVar1,iVar2);
  }
  return 0;
}

/* BindingTable__NextAttribRequestBinding @ 0x97bb09f0 (24 bytes) */
int BindingTable__NextAttribRequestBinding(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  undefined4 uVar1;
  
  if (param_1 != (unsigned char *)0x0) {
    uVar1 = ((int (*)())Binding__GetNextBinding)(param_1);
    return uVar1;
  }
  return *(undefined4 *)(this + 4);
}

/* BindingTable__FindAttribRequestBinding @ 0x97bb0a08 (116 bytes) */
int BindingTable__FindAttribRequestBinding(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  Binding *this_00;
  
  iVar1 = ((int (*)())Binding__GetHash)(param_1,*(uint *)this);
  this_00 = *(Binding **)(iVar1 * 4 + *(int *)(this + 8));
  while ((this_00 != (unsigned char *)0x0 && (iVar1 = ((int (*)())operator__)(this_00,param_1), iVar1 != 1))) {
    this_00 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(this_00);
  }
  return this_00;
}

/* BindingTable__FindAttribRequestBindingLocationByName @ 0x97bb0a7c (228 bytes) */
int BindingTable__FindAttribRequestBindingLocationByName(this, param_1)
  unsigned char *this;
  char *param_1;
{
  Binding *this_00;
  int iVar1;
  undefined4 uVar2;
  Binding *this_01;
  
  if (param_1 != (char *)0x0) {
    this_00 = operator_new(0x38);
    ((int (*)())Binding__Binding)(this_00);
    if (this_00 != (unsigned char *)0x0) {
      ((int (*)())Binding__SetName)(this_00,param_1);
      iVar1 = ((int (*)())Binding__GetHash)(this_00,*(uint *)this);
      this_01 = *(Binding **)(iVar1 * 4 + *(int *)(this + 8));
      while ((this_01 != (unsigned char *)0x0 && (iVar1 = ((int (*)())operator__)(this_01,this_00), iVar1 != 1))) {
        this_01 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(this_01);
      }
      ((int (*)())Binding___Binding)(this_00);
      operator_delete(this_00);
      if (this_01 != (unsigned char *)0x0) {
        uVar2 = ((int (*)())Binding__GetLocation)(this_01);
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

/* BindingTable__InsertClientAttribBinding @ 0x97bb0b60 (368 bytes) */
int BindingTable__InsertClientAttribBinding(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  Binding *this_00;
  int iVar1;
  int iVar2;
  Binding *pBVar3;
  Binding *pBVar4;
  Binding *this_01;
  
  if (param_1 == (unsigned char *)0x0) {
    return 0;
  }
  this_00 = operator_new(0x38);
  ((int (*)())Binding__Binding)(this_00,param_1);
  pBVar4 = *(Binding **)(this + 0xc);
  if (pBVar4 != (unsigned char *)0x0) {
    iVar1 = ((int (*)())Binding__GetLocation)(this_00);
    pBVar3 = (unsigned char *)0x0;
    this_01 = pBVar4;
    do {
      iVar2 = ((int (*)())Binding__GetLocation)(this_01);
      pBVar4 = this_01;
      if (iVar1 < iVar2) break;
      pBVar4 = (unsigned char *)((int (*)())Binding__GetNextBinding)(this_01);
      pBVar3 = this_01;
      this_01 = pBVar4;
    } while (pBVar4 != (unsigned char *)0x0);
    if (pBVar3 != (unsigned char *)0x0) {
      ((int (*)())Binding__SetNextBinding)(pBVar3,this_00);
      goto LAB_97bb0bf0;
    }
  }
  *(Binding **)(this + 0xc) = this_00;
LAB_97bb0bf0:
  ((int (*)())Binding__SetNextBinding)(this_00,pBVar4);
  iVar1 = ((int (*)())Binding__GetHash)(this_00,*(uint *)this);
  pBVar4 = *(Binding **)(iVar1 * 4 + *(int *)(this + 0x10));
  if (pBVar4 == (unsigned char *)0x0) {
    *(Binding **)(iVar1 * 4 + *(int *)(this + 0x10)) = this_00;
  }
  else {
    do {
      pBVar3 = pBVar4;
      pBVar4 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(pBVar3);
    } while (pBVar4 != (unsigned char *)0x0);
    ((int (*)())Binding__SetNextBindingInHash)(pBVar3,this_00);
  }
  ((int (*)())Binding__SetNextBindingInHash)(this_00,(unsigned char *)0x0);
  iVar1 = *(int *)(this + 0x1c);
  *(int *)(this + 0x1c) = iVar1 + 1;
  ((int (*)())Binding__SetActiveIndex)(this_00,iVar1);
  iVar1 = ((int (*)())Binding__IsBuiltIn)(this_00);
  if (iVar1 == 0) {
    iVar1 = ((int (*)())Binding__GetBindingSlots)(this_00);
    *(int *)(this + 0x28) = *(int *)(this + 0x28) + iVar1;
  }
  iVar1 = ((int (*)())Binding__GetBindingSlots)(this_00);
  *(int *)(this + 0x34) = *(int *)(this + 0x34) + iVar1;
  if (*(int *)(this + 0x38) < *(int *)(this_00 + 0x10) + 1) {
    *(int *)(this + 0x38) = *(int *)(this_00 + 0x10) + 1;
  }
  return 1;
}

/* BindingTable__InsertAttribBinding @ 0x97bb0cd0 (508 bytes) */
int BindingTable__InsertAttribBinding(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  Binding *pBVar5;
  Binding *pBVar6;
  Binding *this_00;
  
  uVar1 = 0;
  if (param_1 != (unsigned char *)0x0) {
    iVar3 = 0;
    iVar2 = ((int (*)())Binding__IsBuiltIn)(param_1);
    pBVar6 = *(Binding **)(this + 0xc);
    iVar4 = 1;
    if ((iVar2 != 0) && (iVar2 = _memcmp(*(void **)(param_1 + 8),"gl_Vertex",10), iVar2 == 0)) {
      if ((pBVar6 != (unsigned char *)0x0) && (iVar2 = ((int (*)())Binding__GetLocation)(pBVar6), iVar2 == 0)) {
        return 0;
      }
      iVar4 = 0;
    }
    pBVar5 = (unsigned char *)0x0;
    if (pBVar6 != (unsigned char *)0x0) {
      do {
        this_00 = pBVar6;
        iVar4 = iVar3 + iVar4;
        iVar2 = ((int (*)())Binding__GetLocation)(this_00);
        iVar3 = ((int (*)())Binding__GetBindingSlots)(param_1);
        pBVar6 = this_00;
        if (iVar4 + iVar3 <= iVar2) goto LAB_97bb0db4;
        iVar3 = ((int (*)())Binding__GetLocation)(this_00);
        iVar4 = ((int (*)())Binding__GetBindingSlots)(this_00);
        pBVar6 = (unsigned char *)((int (*)())Binding__GetNextBinding)(this_00);
        pBVar5 = this_00;
      } while (pBVar6 != (unsigned char *)0x0);
      iVar4 = iVar3 + iVar4;
    }
LAB_97bb0db4:
    if (pBVar5 == (unsigned char *)0x0) {
      *(Binding **)(this + 0xc) = param_1;
    }
    else {
      ((int (*)())Binding__SetNextBinding)(pBVar5,param_1);
    }
    ((int (*)())Binding__SetNextBinding)(param_1,pBVar6);
    ((int (*)())Binding__SetLocation)(param_1,iVar4);
    iVar2 = ((int (*)())Binding__GetHash)(param_1,*(uint *)this);
    pBVar6 = *(Binding **)(iVar2 * 4 + *(int *)(this + 0x10));
    if (pBVar6 == (unsigned char *)0x0) {
      *(Binding **)(iVar2 * 4 + *(int *)(this + 0x10)) = param_1;
    }
    else {
      do {
        pBVar5 = pBVar6;
        pBVar6 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(pBVar5);
      } while (pBVar6 != (unsigned char *)0x0);
      ((int (*)())Binding__SetNextBindingInHash)(pBVar5,param_1);
    }
    ((int (*)())Binding__SetNextBindingInHash)(param_1,(unsigned char *)0x0);
    iVar2 = *(int *)(this + 0x1c);
    *(int *)(this + 0x1c) = iVar2 + 1;
    ((int (*)())Binding__SetActiveIndex)(param_1,iVar2);
    iVar2 = ((int (*)())Binding__IsBuiltIn)(param_1);
    if (iVar2 == 0) {
      iVar2 = ((int (*)())Binding__GetBindingSlots)(param_1);
      *(int *)(this + 0x28) = *(int *)(this + 0x28) + iVar2;
    }
    iVar2 = ((int (*)())Binding__GetBindingSlots)(param_1);
    *(int *)(this + 0x34) = *(int *)(this + 0x34) + iVar2;
    if (*(int *)(this + 0x38) < *(int *)(param_1 + 0x10) + 1) {
      *(int *)(this + 0x38) = *(int *)(param_1 + 0x10) + 1;
    }
    uVar1 = 1;
    param_1[0x34] = (Binding)0x1;
  }
  return uVar1;
}

