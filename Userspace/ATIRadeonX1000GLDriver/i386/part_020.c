#include "decls.h"

/* FUN_000dc640 @ 0xdc640 (1786 bytes) */
int FUN_000dc640(param_1)
  int *param_1;
{
  uint *puVar1;
  uint uVar2;
  bool bVar3;
  undefined1 uVar4;
  char cVar5;
  ushort uVar6;
  undefined4 uVar7;
  uint uVar8;
  bool bVar9;
  uint local_b0;
  uint local_ac;
  uint local_a4;
  uint local_a0;
  undefined2 local_9c [32];
  char local_5c [76];
  
  puVar1 = (uint *)param_1[2];
  uVar8 = *puVar1;
  param_1[2] = (int)(puVar1 + 1);
  bVar9 = (uVar8 & 0x400000) != 0;
  if (bVar9) {
    local_ac = puVar1[1];
    param_1[2] = (int)(puVar1 + 2);
  }
  if (((ushort)(uVar8 >> 0x10) & 0x180) == 0x80) {
    local_b0 = *(uint *)param_1[2];
    param_1[2] = (int)((uint *)param_1[2] + 1);
  }
  uVar2 = uVar8 & 0x2000000;
  if ((uVar8 >> 0x19 & 1) != 0xffffffff) {
    bVar3 = false;
    local_a4 = 0;
    local_a0 = local_ac;
LAB_000dc6c3:
    FUN_000dc2d8(param_1,uVar8 >> 0x10 & 0x3f);
    if ((byte)(((byte)(uVar8 >> 0x10) & 0x3f) - 0x1b) < 2) {
      _sprintf(local_5c,"%d",uVar8 & 0xffff);
      FUN_000d9bdc(param_1,local_5c);
      bVar3 = true;
    }
LAB_000dc6ea:
    uVar6 = (ushort)(uVar8 >> 0x10);
    if ((uVar8 & 0x1800000) != 0) goto LAB_000dc7cb;
LAB_000dc6f9:
    if (bVar3) {
      if ((uVar8 & 0x4000000) == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = *(undefined4 *)param_1[2];
        param_1[2] = (int)((undefined4 *)param_1[2] + 1);
      }
      _sprintf(local_5c,"[%lu]",uVar7);
      FUN_000d9bdc(param_1,local_5c);
    }
    else {
      if (uVar2 == 0) {
        _sprintf(local_5c,"%d",uVar8 & 0xffff);
      }
      else {
        _sprintf(local_5c,"[%d]",uVar8 & 0xffff);
      }
      FUN_000d9bdc(param_1,local_5c);
    }
LAB_000dc73c:
    do {
      local_a4 = local_a4 + 1;
      if ((uVar8 >> 0x19 & 1) + 1 <= local_a4) {
LAB_000dc847:
        local_ac = local_a0;
        break;
      }
      while( true ) {
        if (local_a4 == 0) goto LAB_000dc6c3;
        puVar1 = (uint *)param_1[2];
        uVar8 = *puVar1;
        param_1[2] = (int)(puVar1 + 1);
        if ((uVar8 >> 0x10 & 0x40) != 0) {
          local_a0 = puVar1[1];
          param_1[2] = (int)(puVar1 + 2);
        }
        uVar6 = (ushort)(uVar8 >> 0x10);
        if ((uVar6 & 0x180) != 0x80) goto LAB_000dc6ea;
        local_b0 = *(uint *)param_1[2];
        param_1[2] = (int)((uint *)param_1[2] + 1);
        if ((uVar8 & 0x1800000) == 0) goto LAB_000dc6f9;
LAB_000dc7cb:
        if ((uVar6 & 0x180) == 0x80) break;
        if ((uVar6 & 0x180) != 0x100) goto LAB_000dc73c;
        local_9c[0] = 0x5b;
        FUN_000d9bdc(param_1,local_9c);
        ((int (*)())FUN_000dc640)(param_1);
        if ((uVar8 & 0x4000000) != 0) {
          uVar7 = *(undefined4 *)param_1[2];
          param_1[2] = (int)((undefined4 *)param_1[2] + 1);
          _sprintf((char *)local_9c,"+%lu",uVar7);
          FUN_000d9bdc(param_1,local_9c);
        }
        FUN_000d9bdc(param_1,"]");
        local_a4 = local_a4 + 1;
        if ((uVar8 >> 0x19 & 1) + 1 <= local_a4) goto LAB_000dc847;
      }
      FUN_000d9bdc(param_1,"[");
      if ((local_b0 >> 0x10 & 1) == 0) {
        _sprintf(local_5c,"a%d",local_b0 & 0xffff);
        FUN_000d9bdc(param_1,local_5c);
        if ((local_b0 >> 0x10 & 0xe) != 0) {
          uVar4 = FUN_000d9bd4(param_1,uVar8);
          cVar5 = FUN_000d9e7a(param_1,local_b0 >> 0x11 & 7,uVar4);
          _sprintf(local_5c,".%c",(int)cVar5);
          FUN_000d9bdc(param_1,local_5c);
        }
      }
      else {
        FUN_000d9bdc(param_1,"al");
      }
      if (bVar3) {
        if ((uVar8 & 0x4000000) == 0) {
          uVar7 = 0;
        }
        else {
          uVar7 = *(undefined4 *)param_1[2];
          param_1[2] = (int)((undefined4 *)param_1[2] + 1);
        }
        _sprintf((char *)local_9c,"+%lu",uVar7);
        FUN_000d9bdc(param_1,local_9c);
      }
      else if ((short)uVar8 != 0) {
        _sprintf(local_5c,"+%d",uVar8 & 0xffff);
        FUN_000d9bdc(param_1,local_5c);
      }
      FUN_000d9bdc(param_1,"]");
    } while( true );
  }
  if (!bVar9) {
    return;
  }
  uVar4 = FUN_000d9bd4(param_1,uVar8);
  FUN_000d9f18(param_1,local_ac,uVar4);
  FUN_000d9d44(param_1,local_ac,uVar4);
  uVar8 = local_ac >> 0x10;
  if ((uVar8 & 1) != 0) {
    FUN_000d9bdc(param_1,"_invert");
  }
  if ((uVar8 & 8) != 0) {
    FUN_000d9bdc(param_1,"_sign");
  }
  if ((uVar8 & 0x10) != 0) {
    FUN_000d9bdc(param_1,"_abs");
  }
  if ((uVar8 & 2) != 0) {
    FUN_000d9bdc(param_1,"_bias");
  }
  if ((uVar8 & 4) != 0) {
    FUN_000d9bdc(param_1,"_x2");
  }
  if ((uVar8 & 0xe0) == 0) {
    return;
  }
  FUN_000d9bdc(param_1,"_divcomp(");
  uVar8 = local_ac >> 0x15 & 7;
  if (uVar8 == 2) {
    FUN_000d9bdc(param_1,"z");
    goto LAB_000dca06;
  }
  if (uVar8 < 3) {
    if (uVar8 == 1) {
      FUN_000d9bdc(param_1,"y");
      goto LAB_000dca06;
    }
  }
  else {
    if (uVar8 == 3) {
      FUN_000d9bdc(param_1,"w");
      goto LAB_000dca06;
    }
    if (uVar8 == 4) {
      FUN_000d9bdc(param_1,"unknown");
      goto LAB_000dca06;
    }
  }
  FUN_000d9bdc(param_1,"!!!invalid!!!");
  *param_1 = *param_1 + 1;
LAB_000dca06:
  FUN_000d9bdc(param_1,")");
  return;
}

/* FUN_000dcd3a @ 0xdcd3a (1384 bytes) */
int FUN_000dcd3a(param_1)
  int *param_1;
{
  uint *puVar1;
  uint uVar2;
  bool bVar3;
  undefined1 uVar4;
  byte bVar5;
  undefined1 uVar6;
  char cVar7;
  ushort uVar8;
  undefined4 uVar10;
  int iVar11;
  uint local_b0;
  uint local_ac;
  short local_a8;
  char local_9c [64];
  char local_5c [76];
  ushort uVar9;
  
  puVar1 = (uint *)param_1[2];
  uVar2 = *puVar1;
  param_1[2] = (int)(puVar1 + 1);
  if ((uVar2 & 0x400000) != 0) {
    local_ac = puVar1[1];
    param_1[2] = (int)(puVar1 + 2);
  }
  uVar9 = (ushort)(uVar2 >> 0x10);
  uVar8 = uVar9 & 0x180;
  if (uVar8 == 0x80) {
    local_b0 = *(uint *)param_1[2];
    param_1[2] = (int)((uint *)param_1[2] + 1);
  }
  if ((uVar2 & 0x400000) != 0) {
    FUN_000da054(param_1,local_ac);
  }
  FUN_000d9bdc(param_1," ");
  uVar4 = FUN_000d9bcc(param_1,uVar2);
  FUN_000dc2d8(param_1,uVar2 >> 0x10 & 0x3f);
  local_a8 = (short)uVar2;
  if ((uVar9 & 0x23f) == 0x21e) {
    _sprintf(local_5c,"[%d]",uVar2 & 0xffff);
    FUN_000d9bdc(param_1,local_5c);
    uVar2 = *(uint *)param_1[2];
    param_1[2] = (int)((uint *)param_1[2] + 1);
    _sprintf(local_5c,"[%d]",uVar2 & 0xffff);
    FUN_000d9bdc(param_1,local_5c);
    if ((uVar2 & 0x400000) != 0) {
      FUN_000da380(param_1,local_ac,uVar4);
    }
  }
  else {
    bVar5 = (byte)(uVar2 >> 0x10) & 0x3f;
    if ((bVar5 == 0x1f) && ((uVar8 == 0x80 || (uVar8 == 0x100)))) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if ((byte)(bVar5 - 0x1b) < 2) {
      _sprintf(local_5c,"%d",uVar2 & 0xffff);
      FUN_000d9bdc(param_1,local_5c);
      bVar3 = true;
    }
    if ((uVar2 & 0x1800000) == 0) {
      if (bVar3) {
        if ((uVar2 & 0x4000000) == 0) {
          uVar10 = 0;
        }
        else {
          uVar10 = *(undefined4 *)param_1[2];
          param_1[2] = (int)((undefined4 *)param_1[2] + 1);
        }
        _sprintf(local_5c,"[%lu]",uVar10);
        FUN_000d9bdc(param_1,local_5c);
      }
      else {
        _sprintf(local_5c,"%d",uVar2 & 0xffff);
        FUN_000d9bdc(param_1,local_5c);
      }
    }
    else if (uVar8 == 0x80) {
      FUN_000d9bdc(param_1,"[");
      if ((local_b0 >> 0x10 & 1) == 0) {
        _sprintf(local_5c,"a%d",local_b0 & 0xffff);
        FUN_000d9bdc(param_1,local_5c);
        if ((local_b0 >> 0x10 & 0xe) != 0) {
          uVar6 = FUN_000d9bcc(param_1,uVar2);
          cVar7 = FUN_000d9e7a(param_1,local_b0 >> 0x11 & 7,uVar6);
          _sprintf(local_5c,".%c",(int)cVar7);
          FUN_000d9bdc(param_1,local_5c);
        }
      }
      else {
        FUN_000d9bdc(param_1,"al");
      }
      if (bVar3) {
        if ((uVar2 & 0x4000000) == 0) {
          uVar10 = 0;
        }
        else {
          uVar10 = *(undefined4 *)param_1[2];
          param_1[2] = (int)((undefined4 *)param_1[2] + 1);
        }
        _sprintf(local_9c,"+%lu",uVar10);
      }
      else if (local_a8 != 0) {
        _sprintf(local_5c,"+%d",uVar2 & 0xffff);
        FUN_000d9bdc(param_1,local_5c);
      }
      FUN_000d9bdc(param_1,"]");
    }
    else if (uVar8 == 0x100) {
      if ((bVar3) || (bVar5 == 0x1f)) {
        FUN_000d9bdc(param_1,"[");
        ((int (*)())FUN_000dc640)(param_1);
        if ((uVar2 & 0x4000000) != 0) {
          iVar11 = *(int *)param_1[2];
          param_1[2] = (int)((int *)param_1[2] + 1);
          if (bVar5 == 0x1f) {
            iVar11 = iVar11 + (uVar2 & 0xffff);
          }
          _sprintf(local_9c,"+%lu",iVar11);
          FUN_000d9bdc(param_1,local_9c);
        }
        FUN_000d9bdc(param_1,"]");
      }
      else {
        FUN_000d9bdc(param_1,
                     "Error! Field relative_address == IL_ADDR_REG_RELATIVE not supported for this reg type."
                    );
        *param_1 = *param_1 + 1;
      }
    }
    if ((uVar2 & 0x400000) != 0) {
      FUN_000da380(param_1,local_ac,uVar4);
    }
  }
  return;
}

/* FUN_000dd2a2 @ 0xdd2a2 (106 bytes) */
int FUN_000dd2a2(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_000dcd3a)(param_1);
  FUN_000d9bdc(param_1,", ");
  ((int (*)())FUN_000dc640)(param_1);
  FUN_000d9bdc(param_1,", ");
  ((int (*)())FUN_000dc640)(param_1);
  FUN_000d9bdc(param_1,", ");
  ((int (*)())FUN_000dc640)(param_1);
  FUN_000d9c46();
  return;
}

/* FUN_000dd30c @ 0xdd30c (86 bytes) */
int FUN_000dd30c(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_000dcd3a)(param_1);
  FUN_000d9bdc(param_1,", ");
  ((int (*)())FUN_000dc640)(param_1);
  FUN_000d9bdc(param_1,", ");
  ((int (*)())FUN_000dc640)(param_1);
  FUN_000d9c46();
  return;
}

/* FUN_000dd362 @ 0xdd362 (64 bytes) */
int FUN_000dd362(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_000dcd3a)(param_1);
  FUN_000d9bdc(param_1,", ");
  ((int (*)())FUN_000dc640)(param_1);
  FUN_000d9c46();
  return;
}

/* FUN_000dd3a2 @ 0xdd3a2 (15336 bytes) */
int FUN_000dd3a2(param_1)
  int *param_1;
{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  char *local_1bc;
  undefined4 local_1a4;
  char local_18f [255];
  char local_90 [100];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  puVar1 = (uint *)param_1[2];
  uVar8 = *puVar1;
  param_1[2] = (int)(puVar1 + 1);
  switch(uVar8 & 0xffff) {
  default:
    *param_1 = *param_1 + 1;
    FUN_000d9bdc(param_1,"!!!unknownOpcode!!!");
    local_1a4 = 1;
    break;
  case 1:
    FUN_000d9ca8(param_1,param_1[0x87],"abs");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 2:
    FUN_000d9ca8(param_1,param_1[0x87],"acos");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 3:
    FUN_000d9ca8(param_1,param_1[0x87],"add");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 4:
    FUN_000d9ca8(param_1,param_1[0x87],"asin");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 5:
    FUN_000d9ca8(param_1,param_1[0x87],"atan");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 6:
    FUN_000d9ca8(param_1,param_1[0x87],"break");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 7:
    FUN_000d9ca8(param_1,param_1[0x87],"breakc");
    FUN_000dc120(param_1,uVar8);
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9bdc(param_1,", ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 8:
    FUN_000d9ca8(param_1,param_1[0x87],"call");
    FUN_000d9bdc(param_1," ");
    FUN_000da536(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 9:
    FUN_000d9ca8(param_1,param_1[0x87],"callnz");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9bdc(param_1,", ");
    FUN_000da536(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 10:
    FUN_000d9ca8(param_1,param_1[0x87],"clamp");
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0xb:
    FUN_000d9ca8(param_1,param_1[0x87],"clg");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xc:
    FUN_000d9ca8(param_1,param_1[0x87],"cmov");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xd:
    FUN_000d9ca8(param_1,param_1[0x87],"cmp");
    FUN_000dc120(param_1,uVar8);
    FUN_000da580(param_1,uVar8);
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0xe:
    FUN_000d9ca8(param_1,param_1[0x87],"colorclamp");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xf:
    uVar8 = puVar1[1];
    param_1[2] = (int)(puVar1 + 2);
    uVar8 = uVar8 & 0xffff;
    iVar9 = uVar8 * 4;
    FUN_000d9ca8(param_1,param_1[0x87]," ); ");
    pcVar10 = (char *)param_1[2];
    if (uVar8 == 0) {
      iVar12 = 0;
    }
    else {
      cVar7 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      if (cVar7 == '\0') {
        iVar12 = 1;
      }
      else {
        iVar11 = 1;
        do {
          FUN_000d9bdc(param_1,"%c",(int)cVar7);
          iVar12 = iVar9;
          if (iVar11 == iVar9) break;
          cVar7 = *pcVar10;
          pcVar10 = pcVar10 + 1;
          iVar12 = iVar11 + 1;
          iVar11 = iVar12;
        } while (cVar7 != '\0');
      }
    }
    if (iVar9 != iVar12) {
      iVar11 = 0;
      do {
        pcVar10 = pcVar10 + 1;
        iVar11 = iVar11 + 1;
      } while (iVar9 - iVar12 != iVar11);
    }
    param_1[2] = (int)pcVar10;
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x10:
    FUN_000d9ca8(param_1,param_1[0x87],"continue");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x11:
    FUN_000d9ca8(param_1,param_1[0x87],"continuec");
    FUN_000dc120(param_1,uVar8);
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9bdc(param_1,", ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x12:
    FUN_000d9ca8(param_1,param_1[0x87],"cos");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x13:
    FUN_000d9ca8(param_1,param_1[0x87],"crs");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x14:
    FUN_000d9ca8(param_1,param_1[0x87],"dclarray");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9bdc(param_1,", ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x15:
    FUN_000d9ca8(param_1,param_1[0x87],"dcldef");
    FUN_000db8d0(param_1,uVar8,0);
    ((int (*)())FUN_000dcd3a)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x16:
    FUN_000d9ca8(param_1,param_1[0x87],"dclpi");
    FUN_000db586(param_1,uVar8);
    ((int (*)())FUN_000dcd3a)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x17:
    FUN_000d9ca8(param_1,param_1[0x87],"dclpin");
    FUN_000db264(param_1,uVar8);
    ((int (*)())FUN_000dcd3a)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x18:
    FUN_000d9ca8(param_1,param_1[0x87],"dclpp");
    FUN_000d9ca8(param_1,param_1[0x87],"dclv");
    _sprintf(local_90,"_param(%d)",uVar8 >> 0x10 & 0xff);
    FUN_000d9bdc(param_1,local_90);
    ((int (*)())FUN_000dcd3a)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x19:
    FUN_000d9ca8(param_1,param_1[0x87],"dclpt");
    FUN_000db7ca(param_1,uVar8);
    FUN_000dbc6a(param_1,uVar8);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x1a:
    FUN_000d9ca8(param_1,param_1[0x87],"dclv");
    FUN_000db438(param_1,uVar8);
    ((int (*)())FUN_000dcd3a)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x1b:
    FUN_000d9ca8(param_1,param_1[0x87],"dclvout");
    FUN_000db0fc(param_1,uVar8);
    ((int (*)())FUN_000dcd3a)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x1c:
    FUN_000d9ca8(param_1,param_1[0x87],"def");
    if (((byte)((uint)*(undefined4 *)param_1[2] >> 0x10) & 0x3f) == 1) {
      ((int (*)())FUN_000dcd3a)(param_1);
      puVar2 = (undefined4 *)param_1[2];
      local_24 = *puVar2;
      param_1[2] = (int)(puVar2 + 1);
      local_28 = puVar2[1];
      param_1[2] = (int)(puVar2 + 2);
      local_2c = puVar2[2];
      param_1[2] = (int)(puVar2 + 3);
      local_20 = puVar2[3];
      param_1[2] = (int)(puVar2 + 4);
      local_90[0] = ',';
      local_90[1] = ' ';
      local_90[2] = 0;
      ((char * (*)())FUN_000cbe42)(local_24,10,local_18f);
      pcVar10 = local_90 + 2;
      iVar9 = _sprintf(pcVar10,"%s, ",local_18f);
      pcVar10 = pcVar10 + iVar9;
      ((char * (*)())FUN_000cbe42)(local_28,10,local_18f);
      iVar9 = _sprintf(pcVar10,"%s, ",local_18f);
      ((char * (*)())FUN_000cbe42)(local_2c,10,local_18f);
      iVar11 = _sprintf(pcVar10 + iVar9,"%s, ",local_18f);
      ((char * (*)())FUN_000cbe42)(local_20,10,local_18f);
      _sprintf(pcVar10 + iVar9 + iVar11,"%s",local_18f);
    }
    else {
      ((int (*)())FUN_000dcd3a)(param_1);
      puVar2 = (undefined4 *)param_1[2];
      uVar3 = *puVar2;
      param_1[2] = (int)(puVar2 + 1);
      uVar4 = puVar2[1];
      param_1[2] = (int)(puVar2 + 2);
      uVar5 = puVar2[2];
      param_1[2] = (int)(puVar2 + 3);
      uVar6 = puVar2[3];
      param_1[2] = (int)(puVar2 + 4);
      _sprintf(local_90,", %lu, %lu, %lu, %lu",uVar3,uVar4,uVar5,uVar6);
    }
    local_1bc = local_90;
    FUN_000d9bdc(param_1,local_1bc);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x1d:
    FUN_000d9ca8(param_1,param_1[0x87],"defb");
    ((int (*)())FUN_000dcd3a)(param_1);
    uVar3 = *(undefined4 *)param_1[2];
    param_1[2] = (int)((undefined4 *)param_1[2] + 1);
    _sprintf(local_90,", %lu",uVar3);
    FUN_000d9bdc(param_1,local_90);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x1e:
    FUN_000d9ca8(param_1,param_1[0x87],"det");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x1f:
    FUN_000d9ca8(param_1,param_1[0x87],"dist");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x20:
    FUN_000d9ca8(param_1,param_1[0x87],"div");
    FUN_000db9a0(param_1,uVar8);
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x21:
    FUN_000d9ca8(param_1,param_1[0x87],"dp2add");
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0x22:
    FUN_000d9ca8(param_1,param_1[0x87],"dp3");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x23:
    FUN_000d9ca8(param_1,param_1[0x87],"dp4");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x24:
    FUN_000d9ca8(param_1,param_1[0x87],"dst");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x25:
    FUN_000d9ca8(param_1,param_1[0x87],"dsx");
    FUN_000dbe72(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x26:
    FUN_000d9ca8(param_1,param_1[0x87],"dsy");
    FUN_000dbe72(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x27:
    FUN_000d9bb4(param_1,param_1[0x87] + -1);
    FUN_000d9ca8(param_1,param_1[0x87],"else");
    FUN_000d9bb4(param_1,param_1[0x87] + 1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x28:
    FUN_000d9ca8(param_1,param_1[0x87],"end");
    FUN_000d9c46(param_1);
    local_1a4 = 0;
    break;
  case 0x29:
    FUN_000d9bb4(param_1,param_1[0x87] + -1);
    FUN_000d9ca8(param_1,param_1[0x87],"endif");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x2a:
    FUN_000d9bb4(param_1,param_1[0x87] + -1);
    FUN_000d9ca8(param_1,param_1[0x87],"endloop");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x2b:
    FUN_000d9ca8(param_1,param_1[0x87],"endmain");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x2c:
    FUN_000d9ca8(param_1,param_1[0x87],"exn");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x2d:
    FUN_000d9ca8(param_1,param_1[0x87],"exp");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x2e:
    FUN_000d9ca8(param_1,param_1[0x87],"expp");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x2f:
    FUN_000d9ca8(param_1,param_1[0x87],"faceforward");
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0x30:
    FUN_000d9ca8(param_1,param_1[0x87],"flr");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x31:
    FUN_000d9ca8(param_1,param_1[0x87],"frc");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x32:
    FUN_000d9ca8(param_1,param_1[0x87],"func");
    FUN_000d9bb4(param_1,param_1[0x87] + 1);
    FUN_000d9bdc(param_1," ");
    FUN_000da536(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x33:
    FUN_000d9ca8(param_1,param_1[0x87],"fwidth");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x34:
    FUN_000d9ca8(param_1,param_1[0x87],"ifc");
    FUN_000d9bb4(param_1,param_1[0x87] + 1);
    FUN_000dc120(param_1,uVar8);
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9bdc(param_1,", ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x35:
    FUN_000d9ca8(param_1,param_1[0x87],"ifnz ");
    FUN_000d9bb4(param_1,param_1[0x87] + 1);
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x36:
  case 0x43:
    FUN_000d9ca8(param_1,param_1[0x87],"memimport");
    _sprintf(local_90,"_elem(%d)",uVar8 >> 0x10 & 0x3f);
    FUN_000d9bdc(param_1,local_90);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x37:
    FUN_000d9ca8(param_1,param_1[0x87],"kill");
    FUN_000dbc6a(param_1,uVar8);
    FUN_000dbe52(param_1,uVar8);
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x38:
    FUN_000d9ca8(param_1,param_1[0x87],"len");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x39:
    FUN_000d9ca8(param_1,param_1[0x87],"lit");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x3a:
    FUN_000d9ca8(param_1,param_1[0x87],"ln");
    FUN_000db9a0(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x3b:
    FUN_000d9ca8(param_1,param_1[0x87],"lod");
    FUN_000dbc6a(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x3c:
    FUN_000d9ca8(param_1,param_1[0x87],"log");
    FUN_000db9a0(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x3d:
    FUN_000d9ca8(param_1,param_1[0x87],"logp");
    FUN_000db9a0(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x3e:
    FUN_000d9ca8(param_1,param_1[0x87],"loop");
    if ((uVar8 & 0x10000) == 0) {
      pcVar10 = " ";
    }
    else {
      pcVar10 = "_rep ";
    }
    FUN_000d9bdc(param_1,pcVar10);
    FUN_000d9bb4(param_1,param_1[0x87] + 1);
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x3f:
    FUN_000d9ca8(param_1,param_1[0x87],"lrp");
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0x40:
    FUN_000d9ca8(param_1,param_1[0x87],"mad");
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0x41:
    FUN_000d9ca8(param_1,param_1[0x87],"max");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x42:
    FUN_000d9ca8(param_1,param_1[0x87],"memexport");
    _sprintf(local_90,"_exportStream(%d)_stateStride(%d)_elemOffset(%d)",uVar8 >> 0x10 & 0x3f,
             uVar8 >> 0x16 & 1,uVar8 >> 0x17 & 0x3f);
    FUN_000d9bdc(param_1,local_90);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x44:
    FUN_000d9ca8(param_1,param_1[0x87],"min");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x45:
    FUN_000d9ca8(param_1,param_1[0x87],"mmul");
    FUN_000dbfce(param_1,uVar8);
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x46:
    FUN_000d9ca8(param_1,param_1[0x87],"mod");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x47:
    FUN_000d9ca8(param_1,param_1[0x87],"mov");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x48:
    FUN_000d9ca8(param_1,param_1[0x87],"mova");
    FUN_000dbe32(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x49:
    FUN_000d9ca8(param_1,param_1[0x87],"mul");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x4a:
    FUN_000d9ca8(param_1,param_1[0x87],"noise");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x4b:
    FUN_000d9ca8(param_1,param_1[0x87],"nop");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x4c:
    FUN_000d9ca8(param_1,param_1[0x87],"nrm");
    if ((uVar8 & 0x40000) != 0) {
      FUN_000d9bdc(param_1,"_nrm4");
    }
    FUN_000db9a0(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x4d:
    FUN_000d9ca8(param_1,param_1[0x87],"pireduce");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x4e:
    FUN_000d9ca8(param_1,param_1[0x87],"pow");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x50:
    FUN_000d9ca8(param_1,param_1[0x87],"project");
    FUN_000dbc6a(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x51:
    FUN_000d9ca8(param_1,param_1[0x87],"rcp");
    FUN_000db9a0(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x52:
    FUN_000d9ca8(param_1,param_1[0x87],"reflect");
    FUN_000dbe12(param_1,uVar8);
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x53:
    FUN_000d9bb4(param_1,param_1[0x87] + -1);
    FUN_000d9ca8(param_1,param_1[0x87],"ret");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x54:
    FUN_000d9ca8(param_1,param_1[0x87],"rnd");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x55:
    FUN_000d9ca8(param_1,param_1[0x87],"rsq");
    FUN_000db9a0(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x56:
    FUN_000d9ca8(param_1,param_1[0x87],"set");
    FUN_000dc120(param_1,uVar8);
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x57:
    FUN_000d9ca8(param_1,param_1[0x87],"sgn");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x58:
    FUN_000d9ca8(param_1,param_1[0x87],"sin");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x59:
    FUN_000d9ca8(param_1,param_1[0x87],"sincos");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x5a:
    FUN_000d9ca8(param_1,param_1[0x87],"sqrt");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x5b:
    FUN_000d9ca8(param_1,param_1[0x87],"sub");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x5c:
    FUN_000d9ca8(param_1,param_1[0x87],"tan");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x5d:
    FUN_000d9ca8(param_1,param_1[0x87],"texld");
    FUN_000dbf52(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x5e:
    FUN_000d9ca8(param_1,param_1[0x87],"texldb");
    FUN_000dbe92(param_1,uVar8);
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x5f:
    FUN_000d9ca8(param_1,param_1[0x87],"texldd");
    FUN_000dbf52(param_1,uVar8);
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0x60:
    FUN_000d9ca8(param_1,param_1[0x87],"texldms");
    FUN_000dbcaa(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x61:
    FUN_000d9ca8(param_1,param_1[0x87],"texweight");
    FUN_000dbc6a(param_1,uVar8);
    FUN_000dbe72(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x62:
    FUN_000d9ca8(param_1,param_1[0x87],"transpose");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 99:
    FUN_000d9ca8(param_1,param_1[0x87],"trc");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 100:
    FUN_000d9ca8(param_1,param_1[0x87],"dxsincos");
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0x65:
    FUN_000d9ca8(param_1,param_1[0x87],"break_logicalz");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x66:
    FUN_000d9ca8(param_1,param_1[0x87],"break_logicalnz");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x67:
    FUN_000d9ca8(param_1,param_1[0x87],"call_logicalz");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9bdc(param_1,", ");
    FUN_000da536(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x68:
    FUN_000d9ca8(param_1,param_1[0x87],"call_logicalnz");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9bdc(param_1,", ");
    FUN_000da536(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x69:
    FUN_000d9ca8(param_1,param_1[0x87],"case ");
    FUN_000d9bdc(param_1," ");
    uVar3 = *(undefined4 *)param_1[2];
    param_1[2] = (int)((undefined4 *)param_1[2] + 1);
    _sprintf(local_90,"%lu",uVar3);
    FUN_000d9bdc(param_1,local_90);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x6a:
    FUN_000d9ca8(param_1,param_1[0x87],"continue_logicalz");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x6b:
    FUN_000d9ca8(param_1,param_1[0x87],"continue_logicalnz");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x6c:
    FUN_000d9ca8(param_1,param_1[0x87],"default");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x6d:
    FUN_000d9ca8(param_1,param_1[0x87],"endswitch");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x6e:
    FUN_000d9ca8(param_1,param_1[0x87],"endfunc");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x6f:
    FUN_000d9ca8(param_1,param_1[0x87],"if_logicalz ");
    FUN_000d9bb4(param_1,param_1[0x87] + 1);
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x70:
    FUN_000d9ca8(param_1,param_1[0x87],"if_logicalnz ");
    FUN_000d9bb4(param_1,param_1[0x87] + 1);
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x71:
    FUN_000d9ca8(param_1,param_1[0x87],"whileloop");
    FUN_000d9c46(param_1);
    FUN_000d9bb4(param_1,param_1[0x87] + 1);
    local_1a4 = 1;
    break;
  case 0x72:
    FUN_000d9ca8(param_1,param_1[0x87],"switch");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x73:
    FUN_000d9ca8(param_1,param_1[0x87],"ret_dyn");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x74:
    FUN_000d9ca8(param_1,param_1[0x87],"ret_logicalz ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x75:
    FUN_000d9ca8(param_1,param_1[0x87],"ret_logicalnz ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x76:
    if ((int)uVar8 < 0) {
      FUN_000d9ca8(param_1,param_1[0x87],"dcl_immed_cb");
      iVar9 = *(int *)param_1[2];
      param_1[2] = (int)((int *)param_1[2] + 1);
      _sprintf(local_90,"count = %d ",iVar9);
      FUN_000d9bdc(param_1,local_90);
      FUN_000d9c46(param_1);
      if (0 < iVar9) {
        iVar11 = 0;
        do {
          uVar3 = *(undefined4 *)param_1[2];
          param_1[2] = (int)((undefined4 *)param_1[2] + 1);
          _sprintf(local_90," 0x%x ",uVar3);
          FUN_000d9ca8(param_1,param_1[0x87] + 1,local_90);
          FUN_000d9c46(param_1);
          iVar11 = iVar11 + 1;
        } while (iVar9 != iVar11);
      }
      local_1a4 = 1;
    }
    else {
      FUN_000d9ca8(param_1,param_1[0x87],"dcl_cb");
      FUN_000d9bdc(param_1," ");
      ((int (*)())FUN_000dc640)(param_1);
      FUN_000d9c46(param_1);
      local_1a4 = 1;
    }
    break;
  case 0x77:
    FUN_000d9ca8(param_1,param_1[0x87],"dcl_indexed_temp_array");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x78:
    FUN_000d9ca8(param_1,param_1[0x87],"dcl_input_primitive");
    FUN_000dbb54(param_1,uVar8);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x79:
    FUN_000d9ca8(param_1,param_1[0x87],"dcl_literal");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9bdc(param_1,",");
    puVar2 = (undefined4 *)param_1[2];
    uVar3 = *puVar2;
    param_1[2] = (int)(puVar2 + 1);
    uVar4 = puVar2[1];
    param_1[2] = (int)(puVar2 + 2);
    uVar5 = puVar2[2];
    param_1[2] = (int)(puVar2 + 3);
    uVar6 = puVar2[3];
    param_1[2] = (int)(puVar2 + 4);
    _sprintf(local_18f," 0x%08lX, 0x%08lX, 0x%08lX, 0x%08lX",uVar3,uVar4,uVar5,uVar6);
    FUN_000d9bdc(param_1,local_18f);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x7a:
    FUN_000d9ca8(param_1,param_1[0x87],"dcl_max_output_vertex_count");
    _sprintf(local_90,"(%d)",uVar8 >> 0x10 & 0x3fff);
    FUN_000d9bdc(param_1,local_90);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x7b:
    FUN_000d9ca8(param_1,param_1[0x87],"dcl_odepth");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x7c:
    FUN_000d9ca8(param_1,param_1[0x87],"dcl_output_topology");
    FUN_000dbaa2(param_1,uVar8);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x7d:
    FUN_000d9ca8(param_1,param_1[0x87],"dcl_output");
    uVar8 = uVar8 >> 0x10 & 0x3fff;
    if (uVar8 < 0x13) {
      FUN_000d9bdc(param_1,(PTR_s__position_001ef160)[uVar8]);
    }
    ((int (*)())FUN_000dcd3a)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x7e:
    FUN_000d9ca8(param_1,param_1[0x87],"dcl_input");
    if (((byte)(uVar8 >> 0x10) & 0x1f) != 5) {
      FUN_000d9bdc(param_1,(PTR_s__position_001ef160)[uVar8 >> 0x10 & 0x1f]);
    }
    switch(uVar8 >> 0x15 & 7) {
    case 0:
      break;
    case 1:
      FUN_000d9bdc(param_1,"_interp(constant)");
      break;
    case 2:
      FUN_000d9bdc(param_1,"_interp(linear)");
      break;
    case 3:
      FUN_000d9bdc(param_1,"_interp(linear_centroid)");
      break;
    case 4:
      FUN_000d9bdc(param_1,"_interp(linear_noperspective)");
      break;
    case 5:
      FUN_000d9bdc(param_1,"_interp(linear_noperspective_centroid)");
      break;
    default:
      FUN_000d9bdc(param_1,"!!!bad interp mode!!!");
      *param_1 = *param_1 + 1;
    }
    ((int (*)())FUN_000dcd3a)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x7f:
    FUN_000d9ca8(param_1,param_1[0x87],"dcl_vprim");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x80:
    FUN_000d9ca8(param_1,param_1[0x87],"dcl_resource");
    _sprintf(local_18f,"_id(%d)",uVar8 >> 0x10 & 0xff);
    FUN_000d9bdc(param_1,local_18f);
    FUN_000db6b8(param_1,uVar8 >> 0x18 & 0xf);
    FUN_000da20e(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x81:
    FUN_000d9ca8(param_1,param_1[0x87],"cut");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x82:
    FUN_000d9ca8(param_1,param_1[0x87],"discard_logicalz");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x83:
    FUN_000d9ca8(param_1,param_1[0x87],"discard_logicalnz");
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x84:
    FUN_000d9ca8(param_1,param_1[0x87],"emit");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x85:
    FUN_000d9ca8(param_1,param_1[0x87],"emitcut");
    FUN_000d9c46(param_1);
    local_1a4 = 1;
    break;
  case 0x86:
    FUN_000d9ca8(param_1,param_1[0x87],"load");
    _sprintf(local_18f,"_id(%d)",uVar8 >> 0x10 & 0x1fff);
    FUN_000d9bdc(param_1,local_18f);
    FUN_000daa8e(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x87:
    FUN_000d9ca8(param_1,param_1[0x87],"resinfo");
    _sprintf(local_18f,"_id(%d)",uVar8 >> 0x10 & 0xfff);
    FUN_000d9bdc(param_1,local_18f);
    if ((uVar8 & 0x10000000) != 0) {
      FUN_000d9bdc(param_1,"_uint");
    }
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x88:
    FUN_000d9ca8(param_1,param_1[0x87],"sample");
    FUN_000dab56(param_1,uVar8);
    FUN_000daa8e(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x89:
    FUN_000d9ca8(param_1,param_1[0x87],"sample_b");
    FUN_000dab56(param_1,uVar8);
    FUN_000daa8e(param_1,uVar8);
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x8a:
    FUN_000d9ca8(param_1,param_1[0x87],"sample_g");
    FUN_000dab56(param_1,uVar8);
    FUN_000daa8e(param_1,uVar8);
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0x8b:
    FUN_000d9ca8(param_1,param_1[0x87],"sample_l");
    FUN_000dab56(param_1,uVar8);
    FUN_000daa8e(param_1,uVar8);
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x8c:
    FUN_000d9ca8(param_1,param_1[0x87],"sample_c");
    FUN_000dab56(param_1,uVar8);
    FUN_000daa8e(param_1,uVar8);
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x8d:
    FUN_000d9ca8(param_1,param_1[0x87],"sample_c_lz");
    FUN_000dab56(param_1,uVar8);
    FUN_000daa8e(param_1,uVar8);
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x8e:
    FUN_000d9ca8(param_1,param_1[0x87],"inot");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x8f:
    FUN_000d9ca8(param_1,param_1[0x87],"ior");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x90:
    FUN_000d9ca8(param_1,param_1[0x87],"ixor");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x91:
    FUN_000d9ca8(param_1,param_1[0x87],"iadd");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x92:
    FUN_000d9ca8(param_1,param_1[0x87],"imad");
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0x93:
    FUN_000d9ca8(param_1,param_1[0x87],"imax");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x94:
    FUN_000d9ca8(param_1,param_1[0x87],"imin");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x95:
    FUN_000d9ca8(param_1,param_1[0x87],"imul");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x96:
    FUN_000d9ca8(param_1,param_1[0x87],"imul_high");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x97:
    FUN_000d9ca8(param_1,param_1[0x87],"ieq");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x98:
    FUN_000d9ca8(param_1,param_1[0x87],"ige");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x99:
    FUN_000d9ca8(param_1,param_1[0x87],"ilt");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x9a:
    FUN_000d9ca8(param_1,param_1[0x87],"inegate");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0x9b:
    FUN_000d9ca8(param_1,param_1[0x87],"ine");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x9c:
    FUN_000d9ca8(param_1,param_1[0x87],"ishl");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x9d:
    FUN_000d9ca8(param_1,param_1[0x87],"ishr");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x9e:
    FUN_000d9ca8(param_1,param_1[0x87],"ushr");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0x9f:
    FUN_000d9ca8(param_1,param_1[0x87],"udiv");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xa0:
    FUN_000d9ca8(param_1,param_1[0x87],"umod");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xa1:
    FUN_000d9ca8(param_1,param_1[0x87],"umad");
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0xa2:
    FUN_000d9ca8(param_1,param_1[0x87],"umax");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xa3:
    FUN_000d9ca8(param_1,param_1[0x87],"umin");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xa4:
    FUN_000d9ca8(param_1,param_1[0x87],"ult");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xa5:
    FUN_000d9ca8(param_1,param_1[0x87],"uge");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xa6:
    FUN_000d9ca8(param_1,param_1[0x87],"umul");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xa7:
    FUN_000d9ca8(param_1,param_1[0x87],"umul_high");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xa8:
    FUN_000d9ca8(param_1,param_1[0x87],"ftoi");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xa9:
    FUN_000d9ca8(param_1,param_1[0x87],"ftou");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xaa:
    FUN_000d9ca8(param_1,param_1[0x87],"itof");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xab:
    FUN_000d9ca8(param_1,param_1[0x87],"utof");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xac:
    FUN_000d9ca8(param_1,param_1[0x87],"and");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xad:
    FUN_000d9ca8(param_1,param_1[0x87],"cmov_logical");
    ((int (*)())FUN_000dd2a2)(param_1);
    local_1a4 = 1;
    break;
  case 0xae:
    FUN_000d9ca8(param_1,param_1[0x87],"eq");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xaf:
    FUN_000d9ca8(param_1,param_1[0x87],"exp_vec");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xb0:
    FUN_000d9ca8(param_1,param_1[0x87],"ge");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xb1:
    FUN_000d9ca8(param_1,param_1[0x87],"log_vec");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xb2:
    FUN_000d9ca8(param_1,param_1[0x87],"lt");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xb3:
    FUN_000d9ca8(param_1,param_1[0x87],"ne");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xb4:
    FUN_000d9ca8(param_1,param_1[0x87],"round_nearest");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xb5:
    FUN_000d9ca8(param_1,param_1[0x87],"round_neginf");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xb6:
    FUN_000d9ca8(param_1,param_1[0x87],"round_plusinf");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xb7:
    FUN_000d9ca8(param_1,param_1[0x87],"round_zero");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xb8:
    FUN_000d9ca8(param_1,param_1[0x87],"rsq_vec");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xb9:
    FUN_000d9ca8(param_1,param_1[0x87],"sin_vec");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xba:
    FUN_000d9ca8(param_1,param_1[0x87],"cos_vec");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xbb:
    FUN_000d9ca8(param_1,param_1[0x87],"sqrt_vec");
    ((int (*)())FUN_000dd362)(param_1);
    local_1a4 = 1;
    break;
  case 0xbc:
    FUN_000d9ca8(param_1,param_1[0x87],"dp2");
    ((int (*)())FUN_000dd30c)(param_1);
    local_1a4 = 1;
    break;
  case 0xbe:
    FUN_000d9ca8(param_1,param_1[0x87],"scatter");
    if ((uVar8 & 0x3fff0000) != 0) {
      FUN_000d9bdc(param_1,"_quad");
    }
    FUN_000d9bdc(param_1," ");
    ((int (*)())FUN_000dc640)(param_1);
    FUN_000d9c46(param_1);
    local_1a4 = 1;
  }
  return local_1a4;
}

/* FUN_000e12a0 @ 0xe12a0 (42 bytes) */
int FUN_000e12a0(param_1)
  int param_1;
{
  char cVar1;
  
  do {
    if ((uint)(*(int *)(param_1 + 4) + *(int *)(param_1 + 0xc) * 4) <= *(uint *)(param_1 + 8)) {
      return;
    }
    cVar1 = ((int (*)())FUN_000dd3a2)(param_1);
  } while (cVar1 != '\0');
  return;
}

/* FUN_000e12ca @ 0xe12ca (54 bytes) */
int FUN_000e12ca(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  FUN_000d9ba8(param_1);
  FUN_000dc220(param_1);
  ((int (*)())FUN_000e12a0)();
  return;
}

/* FUN_000e1300 @ 0xe1300 (106 bytes) */
int FUN_000e1300(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 local_22c [528];
  int local_1c;
  undefined4 local_18;
  
  if (((param_4 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    FUN_000d9b56(local_22c);
    local_18 = param_1;
    local_1c = param_4;
    ((int (*)())FUN_000e12ca)(local_22c,param_2,param_3);
    return;
  }
  return;
}

/* FUN_000e136a @ 0xe136a (72 bytes) */
int FUN_000e136a(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  *(undefined4 *)(param_1 + 8) = param_2;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_3;
  _memset((void *)(param_1 + 0x10),0,0x200);
  *(undefined1 *)(param_1 + 0x218) = 0;
  ((int (*)())FUN_000e12a0)();
  return;
}

/* FUN_000e13b2 @ 0xe13b2 (5 bytes) */
int FUN_000e13b2()
{
  return;
}

/* FUN_000e13b8 @ 0xe13b8 (35 bytes) */
int FUN_000e13b8(param_1, param_2)
  int param_1;
  int param_2;
{
  byte *pbVar1;
  
  pbVar1 = (byte *)((param_2 >> 3) + 0x2d1 + param_1);
  *pbVar1 = *pbVar1 | (byte)(1 << ((byte)param_2 & 7));
  return;
}

/* FUN_000e13dc @ 0xe13dc (37 bytes) */
int FUN_000e13dc(param_1, param_2)
  int param_1;
  int param_2;
{
  byte *pbVar1;
  
  pbVar1 = (byte *)((param_2 >> 3) + 0x2d1 + param_1);
  *pbVar1 = *pbVar1 & ~(byte)(1 << ((byte)param_2 & 7));
  return;
}

/* FUN_000e1402 @ 0xe1402 (75 bytes) */
int FUN_000e1402(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  
  if (((int)*(char *)((param_2 >> 3) + 0x2d1 + param_1) >> ((byte)param_2 & 7) & 1U) != 0) {
    cVar1 = FUN_001132b4(*(undefined4 *)(param_1 + 0x54),param_2);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}

/* FUN_000e144e @ 0xe144e (35 bytes) */
int FUN_000e144e(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  if ((param_2 == 0) && (*(int *)(param_1 + 0x380) == param_3)) {
    return 1;
  }
  return 0;
}

/* FUN_000e1472 @ 0xe1472 (1550 bytes) */
int FUN_000e1472(param_1)
  int param_1;
{
  ((int (*)())FUN_000e13dc)(param_1,0);
  ((int (*)())FUN_000e13b8)(param_1,1);
  ((int (*)())FUN_000e13b8)(param_1,2);
  ((int (*)())FUN_000e13b8)(param_1,3);
  ((int (*)())FUN_000e13dc)(param_1,4);
  ((int (*)())FUN_000e13b8)(param_1,5);
  ((int (*)())FUN_000e13b8)(param_1,6);
  ((int (*)())FUN_000e13b8)(param_1,7);
  ((int (*)())FUN_000e13dc)(param_1,8);
  ((int (*)())FUN_000e13b8)(param_1,9);
  ((int (*)())FUN_000e13b8)(param_1,10);
  ((int (*)())FUN_000e13dc)(param_1,0xb);
  ((int (*)())FUN_000e13b8)(param_1,0xc);
  ((int (*)())FUN_000e13dc)(param_1,0xd);
  ((int (*)())FUN_000e13b8)(param_1,0xe);
  ((int (*)())FUN_000e13b8)(param_1,0xf);
  ((int (*)())FUN_000e13dc)(param_1,0x10);
  ((int (*)())FUN_000e13b8)(param_1,0x11);
  ((int (*)())FUN_000e13dc)(param_1,0x12);
  ((int (*)())FUN_000e13b8)(param_1,0x13);
  ((int (*)())FUN_000e13b8)(param_1,0x14);
  ((int (*)())FUN_000e13b8)(param_1,0x15);
  ((int (*)())FUN_000e13b8)(param_1,0x16);
  ((int (*)())FUN_000e13b8)(param_1,0x17);
  ((int (*)())FUN_000e13b8)(param_1,0x18);
  ((int (*)())FUN_000e13b8)(param_1,0x19);
  ((int (*)())FUN_000e13b8)(param_1,0x1a);
  ((int (*)())FUN_000e13b8)(param_1,0x1b);
  ((int (*)())FUN_000e13b8)(param_1,0x1c);
  ((int (*)())FUN_000e13b8)(param_1,0x1d);
  ((int (*)())FUN_000e13b8)(param_1,0x1e);
  ((int (*)())FUN_000e13b8)(param_1,0x1f);
  ((int (*)())FUN_000e13b8)(param_1,0x20);
  ((int (*)())FUN_000e13b8)(param_1,0x21);
  ((int (*)())FUN_000e13b8)(param_1,0x22);
  ((int (*)())FUN_000e13b8)(param_1,0x23);
  ((int (*)())FUN_000e13b8)(param_1,0x24);
  ((int (*)())FUN_000e13b8)(param_1,0x25);
  ((int (*)())FUN_000e13b8)(param_1,0x26);
  ((int (*)())FUN_000e13b8)(param_1,0x27);
  ((int (*)())FUN_000e13b8)(param_1,0x28);
  ((int (*)())FUN_000e13b8)(param_1,0x29);
  ((int (*)())FUN_000e13dc)(param_1,0x2a);
  ((int (*)())FUN_000e13dc)(param_1,0x2b);
  ((int (*)())FUN_000e13dc)(param_1,0x2c);
  ((int (*)())FUN_000e13b8)(param_1,0x2e);
  ((int (*)())FUN_000e13b8)(param_1,0x2f);
  ((int (*)())FUN_000e13dc)(param_1,0x4e);
  ((int (*)())FUN_000e13dc)(param_1,0x4f);
  ((int (*)())FUN_000e13b8)(param_1,0x30);
  ((int (*)())FUN_000e13b8)(param_1,0x31);
  ((int (*)())FUN_000e13b8)(param_1,0x32);
  ((int (*)())FUN_000e13b8)(param_1,0x33);
  ((int (*)())FUN_000e13dc)(param_1,0x34);
  ((int (*)())FUN_000e13b8)(param_1,0x35);
  ((int (*)())FUN_000e13dc)(param_1,0x36);
  ((int (*)())FUN_000e13dc)(param_1,0x37);
  ((int (*)())FUN_000e13b8)(param_1,0x38);
  ((int (*)())FUN_000e13b8)(param_1,0x39);
  ((int (*)())FUN_000e13b8)(param_1,0x3a);
  ((int (*)())FUN_000e13b8)(param_1,0x3b);
  ((int (*)())FUN_000e13b8)(param_1,0x3c);
  ((int (*)())FUN_000e13b8)(param_1,0x3d);
  ((int (*)())FUN_000e13dc)(param_1,0x3e);
  ((int (*)())FUN_000e13b8)(param_1,0x3f);
  ((int (*)())FUN_000e13dc)(param_1,0x40);
  ((int (*)())FUN_000e13b8)(param_1,0x41);
  ((int (*)())FUN_000e13b8)(param_1,0x42);
  ((int (*)())FUN_000e13b8)(param_1,0x43);
  ((int (*)())FUN_000e13dc)(param_1,0x44);
  ((int (*)())FUN_000e13b8)(param_1,0x45);
  ((int (*)())FUN_000e13dc)(param_1,0x46);
  ((int (*)())FUN_000e13b8)(param_1,0x47);
  ((int (*)())FUN_000e13b8)(param_1,0x48);
  ((int (*)())FUN_000e13b8)(param_1,0x49);
  ((int (*)())FUN_000e13b8)(param_1,0x4a);
  ((int (*)())FUN_000e13b8)(param_1,0x4b);
  ((int (*)())FUN_000e13dc)(param_1,0x4c);
  ((int (*)())FUN_000e13b8)(param_1,0x4d);
  *(undefined4 *)(param_1 + 0x380) = 2;
  *(undefined4 *)(param_1 + 900) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x388) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x38c) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x390) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x394) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x398) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x39c) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3a4) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3a0) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3a8) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3ac) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3b0) = 100;
  *(undefined4 *)(param_1 + 0x3b4) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3b8) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3bc) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3c0) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3c4) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3c8) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3cc) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3d0) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3d4) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3d8) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3dc) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x3e0) = 4;
  *(undefined4 *)(param_1 + 0x3e4) = 0x7fffffff;
  *(undefined4 *)(param_1 + 1000) = 0x7fffffff;
  return;
}

/* FUN_000e1a80 @ 0xe1a80 (39 bytes) */
int FUN_000e1a80(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x1bc) = 0x400;
  *(undefined1 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined1 *)(param_1 + 0x60) = 0;
  return;
}

/* FUN_000e1aa8 @ 0xe1aa8 (5 bytes) */
int FUN_000e1aa8()
{
  return;
}

/* FUN_000e1aae @ 0xe1aae (12 bytes) */
int FUN_000e1aae(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  return (*(unsigned char *)((unsigned char *)&(param_2) + 3)) & 1;
}

/* FUN_000e1aba @ 0xe1aba (376 bytes) */
int FUN_000e1aba(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  char cVar1;
  
  cVar1 = ((int (*)())FUN_000e1aae)(param_1,param_2);
  if (cVar1 != '\0') {
    ((int (*)())FUN_000e13dc)(param_1,9);
    ((int (*)())FUN_000e13dc)(param_1,0x14);
    ((int (*)())FUN_000e13dc)(param_1,0x1c);
    ((int (*)())FUN_000e13dc)(param_1,0x1d);
    ((int (*)())FUN_000e13dc)(param_1,0x39);
    ((int (*)())FUN_000e13dc)(param_1,0x3b);
    ((int (*)())FUN_000e13dc)(param_1,0x42);
    ((int (*)())FUN_000e13dc)(param_1,0x27);
  }
  if ((param_2 & 0x100000) != 0) {
    ((int (*)())FUN_000e13b8)(param_1,0x2a);
  }
  if ((param_2 & 0x200000) != 0) {
    ((int (*)())FUN_000e13b8)(param_1,0x2b);
  }
  if ((param_2 & 0x200) != 0) {
    ((int (*)())FUN_000e13dc)(param_1,0x3f);
  }
  if ((param_2 & 0x800) != 0) {
    ((int (*)())FUN_000e13dc)(param_1,0x37);
  }
  if ((param_2 & 0x1000) != 0) {
    ((int (*)())FUN_000e13b8)(param_1,0x3e);
  }
  if ((param_2 & 0x2000) != 0) {
    ((int (*)())FUN_000e13b8)(param_1,0x4e);
  }
  if ((param_2 & 0x4000) == 0) {
    return;
  }
  ((int (*)())FUN_000e13b8)();
  return;
}

/* FUN_000e1c32 @ 0xe1c32 (5 bytes) */
int FUN_000e1c32()
{
  return;
}

/* FUN_000e1c38 @ 0xe1c38 (5 bytes) */
int FUN_000e1c38()
{
  return;
}

/* FUN_000e1c3e @ 0xe1c3e (5 bytes) */
int FUN_000e1c3e()
{
  return;
}

/* FUN_000e1c44 @ 0xe1c44 (147 bytes) */
int FUN_000e1c44(param_1)
  int param_1;
{
  int iVar1;
  undefined1 local_8d [128];
  undefined1 local_d;
  
  if (*(int *)(param_1 + 0xe8) < 1) {
    *(undefined4 *)(param_1 + 0xe8) = 0;
    *(undefined4 *)(param_1 + 0xec) = 0;
    return;
  }
  iVar1 = 0;
  do {
    _memcpy(local_8d,(void *)(iVar1 + *(int *)(param_1 + 0xe4)),0x80);
    local_d = 0;
    iVar1 = iVar1 + 0x80;
  } while (iVar1 < *(int *)(param_1 + 0xe8));
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  return;
}

/* FUN_000e1cd8 @ 0xe1cd8 (5 bytes) */
int FUN_000e1cd8()
{
  return;
}

/* FUN_000e1cde @ 0xe1cde (10 bytes) */
int FUN_000e1cde()
{
  return;
}

/* FUN_000e1ce8 @ 0xe1ce8 (34 bytes) */
int FUN_000e1ce8(param_1)
  int param_1;
{
  if ((((param_1 != ' ') && (param_1 != '\t')) && (param_1 != '\n')) && (param_1 != '\r')) {
    return 0;
  }
  return 1;
}

/* FUN_000e1d0a @ 0xe1d0a (2295 bytes) */
int FUN_000e1d0a(param_1, param_2, param_3)
  int param_1;
  char *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  size_t sVar5;
  undefined **ppuVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int iVar10;
  char *pcVar11;
  bool bVar12;
  
  uVar3 = 0xffffffff;
  pcVar8 = param_2;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  sVar4 = ~uVar3 - 1;
  iVar10 = 0;
  ppuVar6 = &PTR_s_OPT_IGNORE_DEFINED_CONSTANTS_001ef1c0;
  do {
    iVar2 = _strncmp(*ppuVar6,param_2,sVar4);
    if (iVar2 == 0) {
      if (param_3 == 0) {
        ((int (*)())FUN_000e13dc)();
        return;
      }
      ((int (*)())FUN_000e13b8)();
      return;
    }
    iVar10 = iVar10 + 1;
    ppuVar6 = ppuVar6 + 1;
  } while (iVar10 != 0x50);
  sVar5 = 0x15;
  if ((int)sVar4 < 0x16) {
    sVar5 = sVar4;
  }
  bVar12 = true;
  pcVar8 = "opt_flatten_if_state";
  pcVar9 = param_2;
  do {
    pcVar7 = pcVar8;
    pcVar11 = pcVar9;
    if (sVar5 == 0) break;
    sVar5 = sVar5 - 1;
    pcVar11 = pcVar9 + 1;
    pcVar7 = pcVar8 + 1;
    bVar12 = *pcVar8 == *pcVar9;
    pcVar8 = pcVar7;
    pcVar9 = pcVar11;
  } while (bVar12);
  iVar10 = 0;
  if (!bVar12) {
    iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
  }
  if (iVar10 == 0) {
    *(int *)(param_1 + 0x380) = param_3;
  }
  else {
    sVar5 = 0xf;
    if ((int)sVar4 < 0x10) {
      sVar5 = sVar4;
    }
    bVar12 = true;
    pcVar8 = "max_copy_folds";
    pcVar9 = param_2;
    do {
      pcVar7 = pcVar8;
      pcVar11 = pcVar9;
      if (sVar5 == 0) break;
      sVar5 = sVar5 - 1;
      pcVar11 = pcVar9 + 1;
      pcVar7 = pcVar8 + 1;
      bVar12 = *pcVar8 == *pcVar9;
      pcVar8 = pcVar7;
      pcVar9 = pcVar11;
    } while (bVar12);
    iVar10 = 0;
    if (!bVar12) {
      iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
    }
    if (iVar10 == 0) {
      *(int *)(param_1 + 900) = param_3;
    }
    else {
      sVar5 = 0xd;
      if ((int)sVar4 < 0xe) {
        sVar5 = sVar4;
      }
      bVar12 = true;
      pcVar8 = "max_vn_kills";
      pcVar9 = param_2;
      do {
        pcVar7 = pcVar8;
        pcVar11 = pcVar9;
        if (sVar5 == 0) break;
        sVar5 = sVar5 - 1;
        pcVar11 = pcVar9 + 1;
        pcVar7 = pcVar8 + 1;
        bVar12 = *pcVar8 == *pcVar9;
        pcVar8 = pcVar7;
        pcVar9 = pcVar11;
      } while (bVar12);
      iVar10 = 0;
      if (!bVar12) {
        iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
      }
      if (iVar10 == 0) {
        *(int *)(param_1 + 0x388) = param_3;
      }
      else {
        sVar5 = 0x12;
        if ((int)sVar4 < 0x13) {
          sVar5 = sVar4;
        }
        bVar12 = true;
        pcVar8 = "max_vn_transforms";
        pcVar9 = param_2;
        do {
          pcVar7 = pcVar8;
          pcVar11 = pcVar9;
          if (sVar5 == 0) break;
          sVar5 = sVar5 - 1;
          pcVar11 = pcVar9 + 1;
          pcVar7 = pcVar8 + 1;
          bVar12 = *pcVar8 == *pcVar9;
          pcVar8 = pcVar7;
          pcVar9 = pcVar11;
        } while (bVar12);
        iVar10 = 0;
        if (!bVar12) {
          iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
        }
        if (iVar10 == 0) {
          *(int *)(param_1 + 0x38c) = param_3;
        }
        else {
          sVar5 = 0x10;
          if ((int)sVar4 < 0x11) {
            sVar5 = sVar4;
          }
          bVar12 = true;
          pcVar8 = "max_copy_merges";
          pcVar9 = param_2;
          do {
            pcVar7 = pcVar8;
            pcVar11 = pcVar9;
            if (sVar5 == 0) break;
            sVar5 = sVar5 - 1;
            pcVar11 = pcVar9 + 1;
            pcVar7 = pcVar8 + 1;
            bVar12 = *pcVar8 == *pcVar9;
            pcVar8 = pcVar7;
            pcVar9 = pcVar11;
          } while (bVar12);
          iVar10 = 0;
          if (!bVar12) {
            iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
          }
          if (iVar10 == 0) {
            *(int *)(param_1 + 0x390) = param_3;
          }
          else {
            sVar5 = 0xf;
            if ((int)sVar4 < 0x10) {
              sVar5 = sVar4;
            }
            bVar12 = true;
            pcVar8 = "max_copy_props";
            pcVar9 = param_2;
            do {
              pcVar7 = pcVar8;
              pcVar11 = pcVar9;
              if (sVar5 == 0) break;
              sVar5 = sVar5 - 1;
              pcVar11 = pcVar9 + 1;
              pcVar7 = pcVar8 + 1;
              bVar12 = *pcVar8 == *pcVar9;
              pcVar8 = pcVar7;
              pcVar9 = pcVar11;
            } while (bVar12);
            iVar10 = 0;
            if (!bVar12) {
              iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
            }
            if (iVar10 == 0) {
              *(int *)(param_1 + 0x394) = param_3;
            }
            else {
              sVar5 = 0xe;
              if ((int)sVar4 < 0xf) {
                sVar5 = sVar4;
              }
              bVar12 = true;
              pcVar8 = "max_mix_insts";
              pcVar9 = param_2;
              do {
                pcVar7 = pcVar8;
                pcVar11 = pcVar9;
                if (sVar5 == 0) break;
                sVar5 = sVar5 - 1;
                pcVar11 = pcVar9 + 1;
                pcVar7 = pcVar8 + 1;
                bVar12 = *pcVar8 == *pcVar9;
                pcVar8 = pcVar7;
                pcVar9 = pcVar11;
              } while (bVar12);
              iVar10 = 0;
              if (!bVar12) {
                iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
              }
              if (iVar10 == 0) {
                *(int *)(param_1 + 0x398) = param_3;
              }
              else {
                sVar5 = 0xc;
                if ((int)sVar4 < 0xd) {
                  sVar5 = sVar4;
                }
                bVar12 = true;
                pcVar8 = "max_presubs";
                pcVar9 = param_2;
                do {
                  pcVar7 = pcVar8;
                  pcVar11 = pcVar9;
                  if (sVar5 == 0) break;
                  sVar5 = sVar5 - 1;
                  pcVar11 = pcVar9 + 1;
                  pcVar7 = pcVar8 + 1;
                  bVar12 = *pcVar8 == *pcVar9;
                  pcVar8 = pcVar7;
                  pcVar9 = pcVar11;
                } while (bVar12);
                iVar10 = 0;
                if (!bVar12) {
                  iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                }
                if (iVar10 == 0) {
                  *(int *)(param_1 + 0x39c) = param_3;
                }
                else {
                  sVar5 = 0x12;
                  if ((int)sVar4 < 0x13) {
                    sVar5 = sVar4;
                  }
                  bVar12 = true;
                  pcVar8 = "max_mov_and_shift";
                  pcVar9 = param_2;
                  do {
                    pcVar7 = pcVar8;
                    pcVar11 = pcVar9;
                    if (sVar5 == 0) break;
                    sVar5 = sVar5 - 1;
                    pcVar11 = pcVar9 + 1;
                    pcVar7 = pcVar8 + 1;
                    bVar12 = *pcVar8 == *pcVar9;
                    pcVar8 = pcVar7;
                    pcVar9 = pcVar11;
                  } while (bVar12);
                  iVar10 = 0;
                  if (!bVar12) {
                    iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                  }
                  if (iVar10 == 0) {
                    *(int *)(param_1 + 0x3a4) = param_3;
                  }
                  else {
                    sVar5 = 0x11;
                    if ((int)sVar4 < 0x12) {
                      sVar5 = sVar4;
                    }
                    bVar12 = true;
                    pcVar8 = "max_useless_phis";
                    pcVar9 = param_2;
                    do {
                      pcVar7 = pcVar8;
                      pcVar11 = pcVar9;
                      if (sVar5 == 0) break;
                      sVar5 = sVar5 - 1;
                      pcVar11 = pcVar9 + 1;
                      pcVar7 = pcVar8 + 1;
                      bVar12 = *pcVar8 == *pcVar9;
                      pcVar8 = pcVar7;
                      pcVar9 = pcVar11;
                    } while (bVar12);
                    iVar10 = 0;
                    if (!bVar12) {
                      iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                    }
                    if (iVar10 == 0) {
                      *(int *)(param_1 + 0x3a0) = param_3;
                    }
                    else {
                      sVar5 = 0x18;
                      if ((int)sVar4 < 0x19) {
                        sVar5 = sVar4;
                      }
                      bVar12 = true;
                      pcVar8 = "max_balance_conversions";
                      pcVar9 = param_2;
                      do {
                        pcVar7 = pcVar8;
                        pcVar11 = pcVar9;
                        if (sVar5 == 0) break;
                        sVar5 = sVar5 - 1;
                        pcVar11 = pcVar9 + 1;
                        pcVar7 = pcVar8 + 1;
                        bVar12 = *pcVar8 == *pcVar9;
                        pcVar8 = pcVar7;
                        pcVar9 = pcVar11;
                      } while (bVar12);
                      iVar10 = 0;
                      if (!bVar12) {
                        iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                      }
                      if (iVar10 == 0) {
                        *(int *)(param_1 + 0x3a8) = param_3;
                      }
                      else {
                        sVar5 = 0x13;
                        if ((int)sVar4 < 0x14) {
                          sVar5 = sVar4;
                        }
                        bVar12 = true;
                        pcVar8 = "max_coalesce_loops";
                        pcVar9 = param_2;
                        do {
                          pcVar7 = pcVar8;
                          pcVar11 = pcVar9;
                          if (sVar5 == 0) break;
                          sVar5 = sVar5 - 1;
                          pcVar11 = pcVar9 + 1;
                          pcVar7 = pcVar8 + 1;
                          bVar12 = *pcVar8 == *pcVar9;
                          pcVar8 = pcVar7;
                          pcVar9 = pcVar11;
                        } while (bVar12);
                        iVar10 = 0;
                        if (!bVar12) {
                          iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                        }
                        if (iVar10 == 0) {
                          *(int *)(param_1 + 0x3ac) = param_3;
                        }
                        else {
                          sVar5 = 0x10;
                          if ((int)sVar4 < 0x11) {
                            sVar5 = sVar4;
                          }
                          bVar12 = true;
                          pcVar8 = "max_spill_loops";
                          pcVar9 = param_2;
                          do {
                            pcVar7 = pcVar8;
                            pcVar11 = pcVar9;
                            if (sVar5 == 0) break;
                            sVar5 = sVar5 - 1;
                            pcVar11 = pcVar9 + 1;
                            pcVar7 = pcVar8 + 1;
                            bVar12 = *pcVar8 == *pcVar9;
                            pcVar8 = pcVar7;
                            pcVar9 = pcVar11;
                          } while (bVar12);
                          iVar10 = 0;
                          if (!bVar12) {
                            iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                          }
                          if (iVar10 == 0) {
                            *(int *)(param_1 + 0x3b0) = param_3;
                          }
                          else {
                            sVar5 = 0x10;
                            if ((int)sVar4 < 0x11) {
                              sVar5 = sVar4;
                            }
                            bVar12 = true;
                            pcVar8 = "max_inst_hoists";
                            pcVar9 = param_2;
                            do {
                              pcVar7 = pcVar8;
                              pcVar11 = pcVar9;
                              if (sVar5 == 0) break;
                              sVar5 = sVar5 - 1;
                              pcVar11 = pcVar9 + 1;
                              pcVar7 = pcVar8 + 1;
                              bVar12 = *pcVar8 == *pcVar9;
                              pcVar8 = pcVar7;
                              pcVar9 = pcVar11;
                            } while (bVar12);
                            iVar10 = 0;
                            if (!bVar12) {
                              iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                            }
                            if (iVar10 == 0) {
                              *(int *)(param_1 + 0x3b4) = param_3;
                            }
                            else {
                              sVar5 = 0x13;
                              if ((int)sVar4 < 0x14) {
                                sVar5 = sVar4;
                              }
                              bVar12 = true;
                              pcVar8 = "max_mad_mul_to_d2a";
                              pcVar9 = param_2;
                              do {
                                pcVar7 = pcVar8;
                                pcVar11 = pcVar9;
                                if (sVar5 == 0) break;
                                sVar5 = sVar5 - 1;
                                pcVar11 = pcVar9 + 1;
                                pcVar7 = pcVar8 + 1;
                                bVar12 = *pcVar8 == *pcVar9;
                                pcVar8 = pcVar7;
                                pcVar9 = pcVar11;
                              } while (bVar12);
                              iVar10 = 0;
                              if (!bVar12) {
                                iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                              }
                              if (iVar10 == 0) {
                                *(int *)(param_1 + 0x3b8) = param_3;
                              }
                              else {
                                sVar5 = 0x13;
                                if ((int)sVar4 < 0x14) {
                                  sVar5 = sVar4;
                                }
                                bVar12 = true;
                                pcVar8 = "max_mad_d2a_to_dp3";
                                pcVar9 = param_2;
                                do {
                                  pcVar7 = pcVar8;
                                  pcVar11 = pcVar9;
                                  if (sVar5 == 0) break;
                                  sVar5 = sVar5 - 1;
                                  pcVar11 = pcVar9 + 1;
                                  pcVar7 = pcVar8 + 1;
                                  bVar12 = *pcVar8 == *pcVar9;
                                  pcVar8 = pcVar7;
                                  pcVar9 = pcVar11;
                                } while (bVar12);
                                iVar10 = 0;
                                if (!bVar12) {
                                  iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                                }
                                if (iVar10 == 0) {
                                  *(int *)(param_1 + 0x3bc) = param_3;
                                }
                                else {
                                  sVar5 = 0x13;
                                  if ((int)sVar4 < 0x14) {
                                    sVar5 = sVar4;
                                  }
                                  bVar12 = true;
                                  pcVar8 = "max_add_add_to_dp3";
                                  pcVar9 = param_2;
                                  do {
                                    pcVar7 = pcVar8;
                                    pcVar11 = pcVar9;
                                    if (sVar5 == 0) break;
                                    sVar5 = sVar5 - 1;
                                    pcVar11 = pcVar9 + 1;
                                    pcVar7 = pcVar8 + 1;
                                    bVar12 = *pcVar8 == *pcVar9;
                                    pcVar8 = pcVar7;
                                    pcVar9 = pcVar11;
                                  } while (bVar12);
                                  iVar10 = 0;
                                  if (!bVar12) {
                                    iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                                  }
                                  if (iVar10 == 0) {
                                    *(int *)(param_1 + 0x3c0) = param_3;
                                  }
                                  else {
                                    sVar5 = 0x13;
                                    if ((int)sVar4 < 0x14) {
                                      sVar5 = sVar4;
                                    }
                                    bVar12 = true;
                                    pcVar8 = "max_add_mul_to_mad";
                                    pcVar9 = param_2;
                                    do {
                                      pcVar7 = pcVar8;
                                      pcVar11 = pcVar9;
                                      if (sVar5 == 0) break;
                                      sVar5 = sVar5 - 1;
                                      pcVar11 = pcVar9 + 1;
                                      pcVar7 = pcVar8 + 1;
                                      bVar12 = *pcVar8 == *pcVar9;
                                      pcVar8 = pcVar7;
                                      pcVar9 = pcVar11;
                                    } while (bVar12);
                                    iVar10 = 0;
                                    if (!bVar12) {
                                      iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                                    }
                                    if (iVar10 == 0) {
                                      *(int *)(param_1 + 0x3c4) = param_3;
                                    }
                                    else {
                                      sVar5 = 0x1f;
                                      if ((int)sVar4 < 0x20) {
                                        sVar5 = sVar4;
                                      }
                                      bVar12 = true;
                                      pcVar8 = "max_add_mad_mul_to_mov_mad_mad";
                                      pcVar9 = param_2;
                                      do {
                                        pcVar7 = pcVar8;
                                        pcVar11 = pcVar9;
                                        if (sVar5 == 0) break;
                                        sVar5 = sVar5 - 1;
                                        pcVar11 = pcVar9 + 1;
                                        pcVar7 = pcVar8 + 1;
                                        bVar12 = *pcVar8 == *pcVar9;
                                        pcVar8 = pcVar7;
                                        pcVar9 = pcVar11;
                                      } while (bVar12);
                                      iVar10 = 0;
                                      if (!bVar12) {
                                        iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                                      }
                                      if (iVar10 == 0) {
                                        *(int *)(param_1 + 0x3c8) = param_3;
                                      }
                                      else {
                                        sVar5 = 0x10;
                                        if ((int)sVar4 < 0x11) {
                                          sVar5 = sVar4;
                                        }
                                        bVar12 = true;
                                        pcVar8 = "max_reassociate";
                                        pcVar9 = param_2;
                                        do {
                                          pcVar7 = pcVar8;
                                          pcVar11 = pcVar9;
                                          if (sVar5 == 0) break;
                                          sVar5 = sVar5 - 1;
                                          pcVar11 = pcVar9 + 1;
                                          pcVar7 = pcVar8 + 1;
                                          bVar12 = *pcVar8 == *pcVar9;
                                          pcVar8 = pcVar7;
                                          pcVar9 = pcVar11;
                                        } while (bVar12);
                                        iVar10 = 0;
                                        if (!bVar12) {
                                          iVar10 = (uint)(byte)pcVar7[-1] - (uint)(byte)pcVar11[-1];
                                        }
                                        if (iVar10 == 0) {
                                          *(int *)(param_1 + 0x3cc) = param_3;
                                        }
                                        else {
                                          sVar5 = 0x10;
                                          if ((int)sVar4 < 0x11) {
                                            sVar5 = sVar4;
                                          }
                                          bVar12 = true;
                                          pcVar8 = "max_reconst_alu";
                                          pcVar9 = param_2;
                                          do {
                                            pcVar7 = pcVar8;
                                            pcVar11 = pcVar9;
                                            if (sVar5 == 0) break;
                                            sVar5 = sVar5 - 1;
                                            pcVar11 = pcVar9 + 1;
                                            pcVar7 = pcVar8 + 1;
                                            bVar12 = *pcVar8 == *pcVar9;
                                            pcVar8 = pcVar7;
                                            pcVar9 = pcVar11;
                                          } while (bVar12);
                                          iVar10 = 0;
                                          if (!bVar12) {
                                            iVar10 = (uint)(byte)pcVar7[-1] -
                                                     (uint)(byte)pcVar11[-1];
                                          }
                                          if (iVar10 == 0) {
                                            *(int *)(param_1 + 0x3d0) = param_3;
                                          }
                                          else {
                                            sVar5 = 0x15;
                                            if ((int)sVar4 < 0x16) {
                                              sVar5 = sVar4;
                                            }
                                            bVar12 = true;
                                            pcVar8 = "max_remove_cnd_input";
                                            pcVar9 = param_2;
                                            do {
                                              pcVar7 = pcVar8;
                                              pcVar11 = pcVar9;
                                              if (sVar5 == 0) break;
                                              sVar5 = sVar5 - 1;
                                              pcVar11 = pcVar9 + 1;
                                              pcVar7 = pcVar8 + 1;
                                              bVar12 = *pcVar8 == *pcVar9;
                                              pcVar8 = pcVar7;
                                              pcVar9 = pcVar11;
                                            } while (bVar12);
                                            iVar10 = 0;
                                            if (!bVar12) {
                                              iVar10 = (uint)(byte)pcVar7[-1] -
                                                       (uint)(byte)pcVar11[-1];
                                            }
                                            if (iVar10 == 0) {
                                              *(int *)(param_1 + 0x3d4) = param_3;
                                            }
                                            else {
                                              sVar5 = 0x1e;
                                              if ((int)sVar4 < 0x1f) {
                                                sVar5 = sVar4;
                                              }
                                              bVar12 = true;
                                              pcVar8 = "max_r600_minimize_cf_attempts";
                                              pcVar9 = param_2;
                                              do {
                                                pcVar7 = pcVar8;
                                                pcVar11 = pcVar9;
                                                if (sVar5 == 0) break;
                                                sVar5 = sVar5 - 1;
                                                pcVar11 = pcVar9 + 1;
                                                pcVar7 = pcVar8 + 1;
                                                bVar12 = *pcVar8 == *pcVar9;
                                                pcVar8 = pcVar7;
                                                pcVar9 = pcVar11;
                                              } while (bVar12);
                                              iVar10 = 0;
                                              if (!bVar12) {
                                                iVar10 = (uint)(byte)pcVar7[-1] -
                                                         (uint)(byte)pcVar11[-1];
                                              }
                                              if (iVar10 == 0) {
                                                *(int *)(param_1 + 0x3d8) = param_3;
                                              }
                                              else {
                                                sVar5 = 0xf;
                                                if ((int)sVar4 < 0x10) {
                                                  sVar5 = sVar4;
                                                }
                                                bVar12 = true;
                                                pcVar8 = "max_flatten_if";
                                                pcVar9 = param_2;
                                                do {
                                                  pcVar7 = pcVar8;
                                                  pcVar11 = pcVar9;
                                                  if (sVar5 == 0) break;
                                                  sVar5 = sVar5 - 1;
                                                  pcVar11 = pcVar9 + 1;
                                                  pcVar7 = pcVar8 + 1;
                                                  bVar12 = *pcVar8 == *pcVar9;
                                                  pcVar8 = pcVar7;
                                                  pcVar9 = pcVar11;
                                                } while (bVar12);
                                                iVar10 = 0;
                                                if (!bVar12) {
                                                  iVar10 = (uint)(byte)pcVar7[-1] -
                                                           (uint)(byte)pcVar11[-1];
                                                }
                                                if (iVar10 == 0) {
                                                  *(int *)(param_1 + 0x3dc) = param_3;
                                                }
                                                else {
                                                  sVar5 = 0x15;
                                                  if ((int)sVar4 < 0x16) {
                                                    sVar5 = sVar4;
                                                  }
                                                  bVar12 = true;
                                                  pcVar8 = "rearrange_tree_depth";
                                                  pcVar9 = param_2;
                                                  do {
                                                    pcVar7 = pcVar8;
                                                    pcVar11 = pcVar9;
                                                    if (sVar5 == 0) break;
                                                    sVar5 = sVar5 - 1;
                                                    pcVar11 = pcVar9 + 1;
                                                    pcVar7 = pcVar8 + 1;
                                                    bVar12 = *pcVar8 == *pcVar9;
                                                    pcVar8 = pcVar7;
                                                    pcVar9 = pcVar11;
                                                  } while (bVar12);
                                                  iVar10 = 0;
                                                  if (!bVar12) {
                                                    iVar10 = (uint)(byte)pcVar7[-1] -
                                                             (uint)(byte)pcVar11[-1];
                                                  }
                                                  if (iVar10 == 0) {
                                                    *(int *)(param_1 + 0x3e0) = param_3;
                                                  }
                                                  else {
                                                    sVar5 = 0x10;
                                                    if ((int)sVar4 < 0x11) {
                                                      sVar5 = sVar4;
                                                    }
                                                    bVar12 = true;
                                                    pcVar8 = "limit_registers";
                                                    pcVar9 = param_2;
                                                    do {
                                                      pcVar7 = pcVar8;
                                                      pcVar11 = pcVar9;
                                                      if (sVar5 == 0) break;
                                                      sVar5 = sVar5 - 1;
                                                      pcVar11 = pcVar9 + 1;
                                                      pcVar7 = pcVar8 + 1;
                                                      bVar12 = *pcVar8 == *pcVar9;
                                                      pcVar8 = pcVar7;
                                                      pcVar9 = pcVar11;
                                                    } while (bVar12);
                                                    iVar10 = 0;
                                                    if (!bVar12) {
                                                      iVar10 = (uint)(byte)pcVar7[-1] -
                                                               (uint)(byte)pcVar11[-1];
                                                    }
                                                    if (iVar10 == 0) {
                                                      *(int *)(param_1 + 0x3e4) = param_3;
                                                    }
                                                    else {
                                                      sVar5 = 0x13;
                                                      if ((int)sVar4 < 0x14) {
                                                        sVar5 = sVar4;
                                                      }
                                                      bVar12 = true;
                                                      pcVar8 = "limit_instructions";
                                                      do {
                                                        pcVar9 = pcVar8;
                                                        pcVar7 = param_2;
                                                        if (sVar5 == 0) break;
                                                        sVar5 = sVar5 - 1;
                                                        pcVar7 = param_2 + 1;
                                                        pcVar9 = pcVar8 + 1;
                                                        bVar12 = *pcVar8 == *param_2;
                                                        pcVar8 = pcVar9;
                                                        param_2 = pcVar7;
                                                      } while (bVar12);
                                                      iVar10 = 0;
                                                      if (!bVar12) {
                                                        iVar10 = (uint)(byte)pcVar9[-1] -
                                                                 (uint)(byte)pcVar7[-1];
                                                      }
                                                      if (iVar10 == 0) {
                                                        *(int *)(param_1 + 1000) = param_3;
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
          }
        }
      }
    }
  }
  return;
}

/* FUN_000e2602 @ 0xe2602 (5 bytes) */
int FUN_000e2602()
{
  return;
}

/* FUN_000e2608 @ 0xe2608 (5 bytes) */
int FUN_000e2608()
{
  return;
}

/* FUN_000e260e @ 0xe260e (12 bytes) */
int FUN_000e260e(param_1)
  int param_1;
{
  *(undefined1 *)(param_1 + 0x61) = 1;
  return;
}

/* FUN_000e261a @ 0xe261a (219 bytes) */
int FUN_000e261a(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x78) = 1;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 0;
  *(undefined4 *)(param_1 + 0x84) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0xf0) = 0;
  *(undefined4 *)(param_1 + 0xf4) = 0;
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0xfc) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined4 *)(param_1 + 0x104) = 0;
  *(undefined4 *)(param_1 + 0x108) = 0xffffffff;
  FUN_0018334c(param_1);
  *(undefined4 *)(param_1 + 0x37c) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  if (*(char *)(param_1 + 0x60) == '\0') {
    *(undefined4 *)(param_1 + 0xe0) = 0;
    *(undefined1 *)(param_1 + 0x3ec) = 0;
    *(undefined1 *)(param_1 + 0x3ed) = 0;
  }
  return;
}

/* FUN_000e26f6 @ 0xe26f6 (53 bytes) */
int FUN_000e26f6(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
{
  *(undefined1 *)(param_1 + 0x2cc) = param_2;
  *(undefined1 *)(param_1 + 0x2cd) = param_4;
  *(undefined1 *)(param_1 + 0x2ce) = param_5;
  *(undefined1 *)(param_1 + 0x2d0) = param_6;
  *(undefined1 *)(param_1 + 0x2cf) = param_7;
  return;
}

/* FUN_000e272c @ 0xe272c (16 bytes) */
int FUN_000e272c()
{
  return "timer.out";
}

/* FUN_000e273c @ 0xe273c (5 bytes) */
int FUN_000e273c()
{
  return;
}

/* FUN_000e2742 @ 0xe2742 (55 bytes) */
int FUN_000e2742(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x2c8) != 0) {
    (**(code **)(param_1 + 0x90))(*(undefined4 *)(param_1 + 0x98),*(int *)(param_1 + 0x2c8));
    *(undefined4 *)(param_1 + 0x2c8) = 0;
  }
  return;
}

/* FUN_000e277a @ 0xe277a (21 bytes) */
int FUN_000e277a(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  *(undefined4 *)(param_1 + 0x278 + param_2 * 4) = param_3;
  return;
}

/* FUN_000e2790 @ 0xe2790 (57 bytes) */
int FUN_000e2790(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0x54) + 0x174))
                    (*(int **)(param_1 + 0x54),param_2,param_3,param_1);
  *(undefined4 *)(param_1 + 0x218 + param_3 * 4) = uVar1;
  return;
}

/* FUN_000e27ca @ 0xe27ca (44 bytes) */
int FUN_000e27ca(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = 1;
  if (param_2 != 0) {
    iVar1 = param_2;
  }
  *(int *)(param_1 + 0x5c) = iVar1;
                    
  _longjmp(*(int **)(param_1 + 4),1);
}

/* FUN_000e27f6 @ 0xe27f6 (73 bytes) */
int FUN_000e27f6(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x94))(*(undefined4 *)(param_1 + 0x98),param_2);
  if (iVar1 != 0) {
    return iVar1;
  }
  ((int (*)())FUN_000e27ca)(param_1,2);
  return 0;
}

/* FUN_000e2840 @ 0xe2840 (47 bytes) */
int FUN_000e2840(param_1)
  int param_1;
{
  byte bVar1;
  
  bVar1 = (byte)((uint)(int)*(char *)(param_1 + 0x2d6) >> 1) & 1;
  *(byte *)(*(int *)(param_1 + 0xb4) + 0x28) = bVar1;
  *(byte *)(*(int *)(param_1 + 0xb8) + 0x28) = bVar1;
  *(byte *)(*(int *)(param_1 + 0xbc) + 0x28) = bVar1;
  return;
}

/* FUN_000e2870 @ 0xe2870 (53 bytes) */
int FUN_000e2870(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x3f4) + 0x30);
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 0x2000) != 0) {
      return *(undefined4 *)(param_1 + 0x27c);
    }
    if ((uVar1 & 0x4000) != 0) {
      return *(undefined4 *)(param_1 + 0x280);
    }
  }
  return *(undefined4 *)(param_1 + 0x278);
}

/* FUN_000e28a6 @ 0xe28a6 (127 bytes) */
int FUN_000e28a6(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((*(char *)(param_1 + 0x1c0) != '\0') &&
     ((param_2 == 5 || ((param_2 == 4 && (*(char *)(param_1 + 0x3ed) != '\0')))))) {
    *(undefined1 *)(param_1 + 0x1c0) = 0;
    *(int *)(param_1 + 0x1bc) = *(int *)(param_1 + 0x1c4) + -1;
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined1 *)(param_1 + 0x60) = 1;
    return 1;
  }
  if ((*(char *)(param_1 + 0x3ed) == '\0') && (param_2 == 4)) {
    *(undefined1 *)(param_1 + 0x3ec) = 1;
    *(undefined1 *)(param_1 + 0x3ed) = 1;
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(undefined1 *)(param_1 + 0x60) = 1;
    return 1;
  }
  return 0;
}

/* FUN_000e2926 @ 0xe2926 (66 bytes) */
int FUN_000e2926(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x3f4) + 0x30);
  if ((uVar1 & 0x2000) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0xdc) + 0x38);
  }
  if ((uVar1 & 1) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0xdc) + 0x3c);
  }
  if ((uVar1 & 0x4000) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0xdc) + 0x40);
  }
  return 0;
}

/* FUN_000e2968 @ 0xe2968 (114 bytes) */
int FUN_000e2968(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = ((int (*)())FUN_000e2926)(param_1);
  iVar2 = param_2;
  if (param_2 < 0) {
    iVar2 = param_2 + 0x1f;
  }
  if (param_2 < 0) {
    puVar1 = (uint *)(iVar3 + 0xb8 + (iVar2 >> 5) * 4);
    *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
    return;
  }
  puVar1 = (uint *)(iVar3 + 0xb8 + (iVar2 >> 5) * 4);
  *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
  return;
}

/* FUN_000e29da @ 0xe29da (114 bytes) */
int FUN_000e29da(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = ((int (*)())FUN_000e2926)(param_1);
  iVar2 = param_2;
  if (param_2 < 0) {
    iVar2 = param_2 + 0x1f;
  }
  if (param_2 < 0) {
    puVar1 = (uint *)(iVar3 + 0xd8 + (iVar2 >> 5) * 4);
    *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
    return;
  }
  puVar1 = (uint *)(iVar3 + 0xd8 + (iVar2 >> 5) * 4);
  *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
  return;
}

/* FUN_000e2a4c @ 0xe2a4c (114 bytes) */
int FUN_000e2a4c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = ((int (*)())FUN_000e2926)(param_1);
  iVar2 = param_2;
  if (param_2 < 0) {
    iVar2 = param_2 + 0x1f;
  }
  if (param_2 < 0) {
    puVar1 = (uint *)(iVar3 + 0x98 + (iVar2 >> 5) * 4);
    *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
    return;
  }
  puVar1 = (uint *)(iVar3 + 0x98 + (iVar2 >> 5) * 4);
  *puVar1 = *puVar1 | 1 << ((byte)param_2 & 0x1f);
  return;
}

/* FUN_000e2abe @ 0xe2abe (135 bytes) */
int FUN_000e2abe(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  
  if (*(int *)(param_1 + 0xb4 + param_2 * 4) != 0) {
    return;
  }
  piVar1 = (int *)((int (*)())FUN_000e27f6)(param_1,0x2c);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    piVar1[4] = 0;
    piVar1[5] = 0;
    piVar1[6] = 0;
    piVar1[7] = 0;
    piVar1[8] = 0;
    piVar1[9] = 0;
    *(undefined1 *)(piVar1 + 10) = 0;
    *piVar1 = param_1;
  }
  *(int **)(param_1 + 0xb4 + param_2 * 4) = piVar1;
  return;
}

/* FUN_000e2b46 @ 0xe2b46 (177 bytes) */
int FUN_000e2b46(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  *(undefined4 *)(param_1 + 0x3f0) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x2c8) = 0;
  *(undefined4 *)(param_1 + 0x274) = 0;
  iVar3 = 0x14;
  iVar1 = param_1;
  do {
    *(undefined4 *)(iVar1 + 0x1c8) = 0;
    *(undefined4 *)(iVar1 + 0x218) = 0;
    *(undefined4 *)(iVar1 + 0x278) = 0;
    iVar1 = iVar1 + 4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar1 = 0;
  do {
    ((int (*)())FUN_000e2abe)(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 != 3);
  uVar2 = FUN_001a7bca(*(undefined4 *)(param_1 + 0xb4),0x2000);
  *(undefined4 *)(param_1 + 0xe4) = uVar2;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  *(undefined4 *)(param_1 + 0xec) = 0;
  ((int (*)())FUN_000e1472)();
  return;
}

/* FUN_000e2bf8 @ 0xe2bf8 (345 bytes) */
int FUN_000e2bf8(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  undefined4 *param_1;
  undefined4 param_2;
  code *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
{
  int iVar1;
  
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  *(undefined1 *)((int)param_1 + 0x61) = 1;
  param_1[0x6f] = 0x400;
  *(undefined1 *)(param_1 + 0x70) = 0;
  param_1[0x71] = 0;
  *(undefined1 *)(param_1 + 0xb3) = 1;
  param_1[0xfd] = 0;
  param_1[0x1b] = param_6;
  param_1[0x28] = param_8;
  param_1[0x29] = param_9;
  param_1[0x2a] = param_10;
  param_1[0x2b] = param_11;
  param_1[0x27] = param_7;
  param_1[0x24] = param_4;
  param_1[0x25] = param_3;
  param_1[0x26] = param_2;
  *param_1 = param_5;
  param_1[0x2c] = param_12;
  param_1[0x19] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[1] = (int)(param_1 + 2) + (-(int)(param_1 + 2) & 7U);
  iVar1 = (*param_3)(param_2,0x1744);
  *(undefined1 *)(param_1 + 0x4f) = 0;
  if (iVar1 == 0) {
    param_1[0x17] = 2;
    return;
  }
  FUN_001306b2(iVar1,param_1,0);
  param_1[0x15] = iVar1;
  iVar1 = _setjmp((int *)param_1[1]);
  if (iVar1 != 0) {
    return;
  }
  ((int (*)())FUN_000e2b46)(param_1);
  ((int (*)())FUN_000e261a)(param_1);
  return;
}

/* FUN_000e2d5a @ 0xe2d5a (345 bytes) */
int FUN_000e2d5a(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  undefined4 *param_1;
  undefined4 param_2;
  code *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
{
  int iVar1;
  
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  *(undefined1 *)((int)param_1 + 0x61) = 1;
  param_1[0x6f] = 0x400;
  *(undefined1 *)(param_1 + 0x70) = 0;
  param_1[0x71] = 0;
  *(undefined1 *)(param_1 + 0xb3) = 1;
  param_1[0xfd] = 0;
  param_1[0x1b] = param_6;
  param_1[0x28] = param_8;
  param_1[0x29] = param_9;
  param_1[0x2a] = param_10;
  param_1[0x2b] = param_11;
  param_1[0x27] = param_7;
  param_1[0x24] = param_4;
  param_1[0x25] = param_3;
  param_1[0x26] = param_2;
  *param_1 = param_5;
  param_1[0x2c] = param_12;
  param_1[0x19] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[1] = (int)(param_1 + 2) + (-(int)(param_1 + 2) & 7U);
  iVar1 = (*param_3)(param_2,0x1744);
  *(undefined1 *)(param_1 + 0x4f) = 0;
  if (iVar1 == 0) {
    param_1[0x17] = 2;
    return;
  }
  FUN_001306b2(iVar1,param_1,0);
  param_1[0x15] = iVar1;
  iVar1 = _setjmp((int *)param_1[1]);
  if (iVar1 != 0) {
    return;
  }
  ((int (*)())FUN_000e2b46)(param_1);
  ((int (*)())FUN_000e261a)(param_1);
  return;
}

/* FUN_000e2ebc @ 0xe2ebc (190 bytes) */
int FUN_000e2ebc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x54) != 0) {
    (**(code **)(param_1 + 0x90))(*(undefined4 *)(param_1 + 0x98),*(int *)(param_1 + 0x54));
    *(undefined4 *)(param_1 + 0x54) = 0;
  }
  if (0 < param_2) {
    if (param_2 < 4) {
      iVar1 = ((int (*)())FUN_000e27f6)(param_1,0x10);
      if (iVar1 != 0) {
        FUN_001136d6(iVar1,param_1);
      }
      *(int *)(param_1 + 0x58) = iVar1;
      if (param_2 == 2) {
        FUN_00113366(*(undefined4 *)(iVar1 + 4));
        *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x58) + 8) + 0x1740) = 2;
        return;
      }
    }
    else if (param_2 == 4) {
      iVar1 = ((int (*)())FUN_000e27f6)(param_1,0x10);
      if (iVar1 != 0) {
        FUN_00113790(iVar1,param_1);
      }
      *(int *)(param_1 + 0x58) = iVar1;
      return;
    }
  }
  return;
}

/* FUN_000e2f82 @ 0xe2f82 (847 bytes) */
int FUN_000e2f82(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  char cVar6;
  int *piVar7;
  int *piVar8;
  uint *puVar9;
  int iVar10;
  uint local_28;
  uint local_20;
  int local_1c;
  int local_14;
  
  if (((*(uint *)(param_1 + 0x30) & 1) == 0) && ((*(uint *)(param_1 + 0x30) & 0x2000) != 0)) {
    uVar1 = *(undefined4 *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0x378);
    iVar3 = *(int *)(iVar2 + 8);
    while (iVar3 != 0) {
      piVar4 = *(int **)(iVar2 + 0x98);
      iVar3 = piVar4[2];
      while (iVar3 != 0) {
        if ((*(byte *)(piVar4 + 5) & 1) != 0) {
          if (*(int *)(piVar4[0x22] + 8) == 0x13) {
            piVar7 = (int *)FUN_0010b180(piVar4,1);
            piVar8 = (int *)FUN_0010b180(piVar4,2);
            cVar6 = (**(code **)(*piVar7 + 0x4c))(piVar7);
            if (((cVar6 != '\0') && (cVar6 = (**(code **)(*piVar8 + 0x48))(piVar8), cVar6 != '\0'))
               || ((cVar6 = (**(code **)(*piVar8 + 0x4c))(piVar8), cVar6 != '\0' &&
                   (cVar6 = (**(code **)(*piVar7 + 0x48))(piVar7), cVar6 != '\0')))) {
              cVar6 = (**(code **)(*piVar7 + 0x4c))(piVar7);
              if (cVar6 == '\0') {
                piVar7 = piVar8;
              }
              puVar9 = (uint *)piVar4[4];
              local_28 = puVar9[1] - 1;
              if (-1 < (int)local_28) {
                local_14 = local_28 * 4;
                do {
                  if (local_28 < *puVar9) {
                    uVar5 = puVar9[1];
                    if (uVar5 <= local_28) {
                      _memset((void *)(puVar9[2] + uVar5 * 4),0,(local_28 - uVar5) * 4 + 4);
                      puVar9[1] = local_28 + 1;
                    }
                    iVar3 = *(int *)(local_14 + puVar9[2]);
                    iVar10 = *(int *)(iVar3 + 0x84);
                  }
                  else {
                    piVar8 = (int *)FUN_001a7f7c(puVar9,local_28);
                    iVar3 = *piVar8;
                    iVar10 = *(int *)(iVar3 + 0x84);
                  }
                  if (0 < iVar10) {
                    iVar10 = 1;
                    do {
                      piVar8 = (int *)FUN_0010b180(iVar3,iVar10);
                      if (piVar4 == piVar8) {
                        FUN_0010ba02(iVar3,iVar10,piVar7,1,uVar1);
                        break;
                      }
                      iVar10 = iVar10 + 1;
                    } while (iVar10 <= *(int *)(iVar3 + 0x84));
                  }
                  local_28 = local_28 - 1;
                  local_14 = local_14 + -4;
                  if (local_28 == 0xffffffff) break;
                  puVar9 = (uint *)piVar4[4];
                } while( true );
              }
            }
          }
          cVar6 = (**(code **)(*piVar4 + 100))(piVar4);
          if ((cVar6 != '\0') && ((piVar4[0x49] != 0 || ((char)piVar4[0x48] != '\0')))) {
            piVar7 = (int *)FUN_0010b180(piVar4,1);
            cVar6 = (**(code **)(*piVar7 + 0x4c))(piVar7);
            if (cVar6 != '\0') {
              puVar9 = (uint *)piVar4[4];
              local_20 = puVar9[1] - 1;
              if (-1 < (int)local_20) {
                local_1c = local_20 * 4;
                do {
                  if (local_20 < *puVar9) {
                    uVar5 = puVar9[1];
                    if (uVar5 <= local_20) {
                      _memset((void *)(puVar9[2] + uVar5 * 4),0,(local_20 - uVar5) * 4 + 4);
                      puVar9[1] = local_20 + 1;
                    }
                    iVar3 = *(int *)(local_1c + puVar9[2]);
                    iVar10 = *(int *)(iVar3 + 0x84);
                  }
                  else {
                    piVar8 = (int *)FUN_001a7f7c(puVar9,local_20);
                    iVar3 = *piVar8;
                    iVar10 = *(int *)(iVar3 + 0x84);
                  }
                  if (0 < iVar10) {
                    iVar10 = 1;
                    do {
                      piVar8 = (int *)FUN_0010b180(iVar3,iVar10);
                      if (piVar4 == piVar8) {
                        FUN_0010ba02(iVar3,iVar10,piVar7,1,uVar1);
                        break;
                      }
                      iVar10 = iVar10 + 1;
                    } while (iVar10 <= *(int *)(iVar3 + 0x84));
                  }
                  if (local_20 == 0) break;
                  local_1c = local_1c + -4;
                  local_20 = local_20 - 1;
                  puVar9 = (uint *)piVar4[4];
                } while( true );
              }
            }
          }
        }
        piVar4 = (int *)piVar4[2];
        iVar3 = piVar4[2];
      }
      iVar2 = *(int *)(iVar2 + 8);
      iVar3 = *(int *)(iVar2 + 8);
    }
  }
  return;
}

/* FUN_000e32d2 @ 0xe32d2 (134 bytes) */
int FUN_000e32d2(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((param_2 != '\0') && (*(int *)(param_1 + 0x58) != 0)) {
    FUN_0011352c(*(int *)(param_1 + 0x58),param_1);
    (**(code **)(param_1 + 0x90))(*(undefined4 *)(param_1 + 0x98),*(undefined4 *)(param_1 + 0x58));
  }
  iVar1 = param_1;
  do {
    if (*(int *)(iVar1 + 0xb4) != 0) {
      FUN_001a7afe(*(int *)(iVar1 + 0xb4));
      (**(code **)(param_1 + 0x90))(*(undefined4 *)(param_1 + 0x98),*(undefined4 *)(iVar1 + 0xb4));
      *(undefined4 *)(iVar1 + 0xb4) = 0;
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 != param_1 + 0xc);
  return;
}

/* FUN_000e3358 @ 0xe3358 (27 bytes) */
int FUN_000e3358(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_000e32d2)(param_1,1);
  return;
}

/* FUN_000e3374 @ 0xe3374 (27 bytes) */
int FUN_000e3374(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_000e32d2)(param_1,1);
  return;
}

/* FUN_000e3390 @ 0xe3390 (1561 bytes) */
int FUN_000e3390(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 local_28;
  
  ((int (*)())FUN_000e2840)(param_1);
  *(char **)(param_1 + 0x2dc) = "INITIAL_INPUT";
  *(char **)(param_1 + 0x2f0) = "BUILD_SSA";
  *(char **)(param_1 + 0x304) = "REDUCE_DEP";
  *(char **)(param_1 + 0x318) = "PEEPHOLE";
  *(char **)(param_1 + 0x32c) = "SCHED";
  *(char **)(param_1 + 0x340) = "REPLACE_PHI";
  *(char **)(param_1 + 0x354) = "GLOBAL_ALLOC";
  *(char **)(param_1 + 0x368) = "ASSEMBLY";
  FUN_0011afba(param_1);
  iVar3 = *(int *)(param_2 + 8) + -1;
  *(int *)(param_1 + 0x270) = iVar3;
  do {
    if (iVar3 < 0) {
      return;
    }
    ((int (*)())FUN_000e261a)(param_1);
    iVar3 = *(int *)(param_1 + 0x270);
    if (iVar3 < 2) {
      local_28 = *(undefined4 *)(param_2 + 0xc + iVar3 * 4);
    }
    else {
      local_28 = *(undefined4 *)(*(int *)(param_2 + 0x14) + iVar3 * 4);
    }
    uVar6 = *(undefined4 *)(param_1 + 0xb8);
    puVar4 = (undefined4 *)FUN_001a7bca(uVar6,0x478);
    *puVar4 = uVar6;
    FUN_000ef382(puVar4 + 1,param_1);
    *(undefined4 **)(param_1 + 0x3f4) = puVar4 + 1;
    uVar6 = *(undefined4 *)(param_1 + 0xbc);
    puVar5 = (undefined4 *)FUN_001a7bca(uVar6,0x290);
    *puVar5 = uVar6;
    puVar4 = puVar5 + 1;
    FUN_000e6cbe(puVar4,local_28,param_1);
    if ((*(byte *)(param_2 + 4) & 0x20) != 0) {
      iVar3 = *(int *)(param_1 + 0x270) + 1;
      if (iVar3 < 2) {
        uVar6 = *(undefined4 *)(param_2 + 0xc + iVar3 * 4);
      }
      else {
        uVar6 = *(undefined4 *)(*(int *)(param_2 + 0x14) + iVar3 * 4);
      }
      FUN_000e5ab2(puVar4,uVar6);
    }
    (**(code **)(**(int **)(param_1 + 0x54) + 0x60))(*(int **)(param_1 + 0x54));
    FUN_000f16bc(*(undefined4 *)(param_1 + 0x3f4),puVar4);
    if (puVar4 != (undefined4 *)0x0) {
      FUN_000e5f76(puVar4);
      FUN_001a7aba(*puVar5,puVar5);
    }
    FUN_001a7afe(*(undefined4 *)(param_1 + 0xbc));
    FUN_0012a21c(*(undefined4 *)(param_1 + 0x3f4));
    FUN_001a7afe(*(undefined4 *)(param_1 + 0xbc));
    cVar2 = ((int (*)())FUN_000e1402)(param_1,0xf);
    if (cVar2 == '\0') {
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x34);
      if (cVar2 != '\0') goto LAB_000e37fd;
LAB_000e34c2:
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x35);
      if (cVar2 != '\0') goto LAB_000e3823;
LAB_000e34da:
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x10);
      if (cVar2 != '\0') goto LAB_000e3849;
LAB_000e34f2:
      puVar1 = (uint *)(*(int *)(param_1 + 0x3f4) + 0x30);
      *puVar1 = *puVar1 | 0x80;
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x11);
      if (cVar2 != '\0') goto LAB_000e387c;
LAB_000e3517:
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x1a);
      if (cVar2 != '\0') goto LAB_000e38aa;
LAB_000e352f:
      puVar1 = (uint *)(*(int *)(param_1 + 0x3f4) + 0x30);
      *puVar1 = *puVar1 & 0xffffff7f;
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x20);
      if (cVar2 != '\0') goto LAB_000e38d0;
LAB_000e3554:
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x12);
      if (cVar2 != '\0') goto LAB_000e38f6;
LAB_000e356c:
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x22);
    }
    else {
      FUN_00144e30(*(undefined4 *)(param_1 + 0x3f4));
      FUN_00145544(*(undefined4 *)(param_1 + 0x3f4));
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x34);
      if (cVar2 == '\0') goto LAB_000e34c2;
LAB_000e37fd:
      FUN_00141ff8(*(undefined4 *)(param_1 + 0x3f4));
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x35);
      if (cVar2 == '\0') goto LAB_000e34da;
LAB_000e3823:
      FUN_00147d20(*(undefined4 *)(param_1 + 0x3f4));
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x10);
      if (cVar2 == '\0') goto LAB_000e34f2;
LAB_000e3849:
      ((int (*)())FUN_000e2f82)(*(undefined4 *)(param_1 + 0x3f4));
      puVar1 = (uint *)(*(int *)(param_1 + 0x3f4) + 0x30);
      *puVar1 = *puVar1 | 0x80;
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x11);
      if (cVar2 == '\0') goto LAB_000e3517;
LAB_000e387c:
      FUN_00143642(*(undefined4 *)(param_1 + 0x3f4),0);
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x1a);
      if (cVar2 == '\0') goto LAB_000e352f;
LAB_000e38aa:
      FUN_00144b86(*(undefined4 *)(param_1 + 0x3f4));
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x20);
      if (cVar2 == '\0') goto LAB_000e3554;
LAB_000e38d0:
      FUN_0013779e(*(undefined4 *)(param_1 + 0x3f4));
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x12);
      if (cVar2 == '\0') goto LAB_000e356c;
LAB_000e38f6:
      FUN_00145544(*(undefined4 *)(param_1 + 0x3f4));
      puVar1 = (uint *)(*(int *)(param_1 + 0x3f4) + 0x30);
      *puVar1 = *puVar1 | 0x80;
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x11);
      if (cVar2 != '\0') {
        FUN_00143642(*(undefined4 *)(param_1 + 0x3f4),0);
      }
      FUN_0014fa92(*(undefined4 *)(param_1 + 0x3f4));
      puVar1 = (uint *)(*(int *)(param_1 + 0x3f4) + 0x30);
      *puVar1 = *puVar1 & 0xffffff7f;
      cVar2 = ((int (*)())FUN_000e1402)(param_1,0x22);
    }
    if (cVar2 != '\0') {
      FUN_00141442(*(undefined4 *)(param_1 + 0x3f4));
    }
    FUN_000f5430(*(undefined4 *)(param_1 + 0x3f4));
    FUN_001a7afe(*(undefined4 *)(param_1 + 0xbc));
    FUN_0018240c(*(undefined4 *)(param_1 + 0x3f4));
    FUN_001a7afe(*(undefined4 *)(param_1 + 0xbc));
    FUN_00127ac6(*(undefined4 *)(param_1 + 0x3f4));
    FUN_001a7afe(*(undefined4 *)(param_1 + 0xbc));
    FUN_0013bcfa(*(undefined4 *)(param_1 + 0x3f4));
    FUN_001a7afe(*(undefined4 *)(param_1 + 0xbc));
    FUN_000f81b6(*(undefined4 *)(param_1 + 0x3f4),param_1);
    puVar1 = (uint *)(*(int *)(param_1 + 0x3f4) + 0x30);
    *puVar1 = *puVar1 | 0x10000;
    FUN_00131f6a(*(undefined4 *)(param_1 + 0x3f4));
    FUN_000e4ccc(*(undefined4 *)(param_1 + 0x3f4),param_1 + 0x1c8 + *(int *)(param_1 + 0x270) * 4,
                 *(int *)(param_1 + 0x270));
    FUN_001a7afe(*(undefined4 *)(param_1 + 0xbc));
    FUN_00137d0a(*(undefined4 *)(param_1 + 0x3f4),0);
    (**(code **)(**(int **)(param_1 + 0x54) + 0x38))
              (*(int **)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x270),param_1);
    (**(code **)(**(int **)(param_1 + 0x54) + 0x8c))
              (*(int **)(param_1 + 0x54),
               *(undefined4 *)(param_1 + 0x268 + *(int *)(param_1 + 0x270) * 4),
               *(undefined4 *)(param_1 + 0x218 + *(int *)(param_1 + 0x270) * 4),param_1);
    iVar3 = *(int *)(param_1 + 0x3f4);
    if (iVar3 != 0) {
      FUN_000ee67a(iVar3);
      FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
    }
    FUN_001a7afe(*(undefined4 *)(param_1 + 0xb8));
    FUN_001a7afe(*(undefined4 *)(param_1 + 0xbc));
    iVar3 = *(int *)(param_1 + 0x270) + -1;
    *(int *)(param_1 + 0x270) = iVar3;
  } while( true );
}

/* FUN_000e39de @ 0xe39de (343 bytes) */
int FUN_000e39de(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  char cVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0xdc) = param_5;
  ((int (*)())FUN_000e1a80)(param_1);
  while( true ) {
    iVar2 = _setjmp(*(int **)(param_1 + 4));
    if (iVar2 == 0) {
      ((int (*)())FUN_000e2b46)(param_1);
      ((int (*)())FUN_000e1aba)(param_1,param_4);
      iVar2 = FUN_001a7a04(param_3,param_1);
      *(int *)(param_1 + 0x268) = param_2;
      if ((*(uint *)(iVar2 + 4) & 4) == 0) {
        if ((*(uint *)(iVar2 + 4) & 2) == 0) {
          *(undefined4 *)(param_2 + 0xf8) = 2;
        }
        else {
          *(undefined4 *)(param_2 + 0xf8) = 0;
        }
      }
      else {
        *(undefined4 *)(param_2 + 0xf8) = 1;
      }
      *(undefined4 *)(param_2 + 0xfc) = *(undefined4 *)(*(int *)(param_1 + 0xdc) + 0x28);
      ((int (*)())FUN_000e3390)(param_1,iVar2);
      if (iVar2 != 0) {
        FUN_001a79de(iVar2);
        FUN_001a7aba(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
      }
    }
    *(undefined4 *)(param_1 + 0x1c8) = 0;
    *(undefined4 *)(param_1 + 0x218) = 0;
    *(undefined4 *)(param_1 + 0x1cc) = 0;
    *(undefined4 *)(param_1 + 0x21c) = 0;
    iVar2 = *(int *)(param_1 + 0x5c);
    ((int (*)())FUN_000e1c44)(param_1);
    ((int (*)())FUN_000e32d2)(param_1,0);
    if (iVar2 == 0) break;
    cVar1 = ((int (*)())FUN_000e28a6)(param_1,iVar2);
    if (cVar1 == '\0') {
      return iVar2;
    }
  }
  return 0;
}

/* FUN_000e3b36 @ 0xe3b36 (312 bytes) */
int FUN_000e3b36(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  char cVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0xdc) = param_7;
  ((int (*)())FUN_000e1a80)(param_1);
  while( true ) {
    iVar2 = _setjmp(*(int **)(param_1 + 4));
    if (iVar2 == 0) {
      ((int (*)())FUN_000e2b46)(param_1);
      ((int (*)())FUN_000e1aba)(param_1,param_5);
      iVar2 = FUN_001a7938(param_3,param_4,param_1);
      *(int *)(param_1 + 0x268) = param_2;
      *(undefined4 *)(param_2 + 0xf8) = 0;
      *(undefined4 *)(param_2 + 0xfc) = *(undefined4 *)(*(int *)(param_1 + 0xdc) + 0x28);
      ((int (*)())FUN_000e3390)(param_1,iVar2);
      if (iVar2 != 0) {
        FUN_001a79de(iVar2);
        FUN_001a7aba(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
      }
    }
    *(undefined4 *)(param_1 + 0x1c8) = 0;
    *(undefined4 *)(param_1 + 0x218) = 0;
    *(undefined4 *)(param_1 + 0x1cc) = 0;
    *(undefined4 *)(param_1 + 0x21c) = 0;
    iVar2 = *(int *)(param_1 + 0x5c);
    ((int (*)())FUN_000e1c44)(param_1);
    ((int (*)())FUN_000e32d2)(param_1,0);
    if (iVar2 == 0) break;
    cVar1 = ((int (*)())FUN_000e28a6)(param_1,iVar2);
    if (cVar1 == '\0') {
      return iVar2;
    }
  }
  return 0;
}

/* FUN_000e3c6e @ 0xe3c6e (136 bytes) */
int FUN_000e3c6e(param_1, param_2)
  int param_1;
  int param_2;
{
  *(int *)(param_1 + 0x290) = *(int *)(param_1 + 0x290) + *(int *)(param_2 + 4);
  *(int *)(param_1 + 0x294) = *(int *)(param_1 + 0x294) + *(int *)(param_2 + 8);
  *(int *)(param_1 + 0x298) = *(int *)(param_1 + 0x298) + *(int *)(param_2 + 0xc);
  *(int *)(param_1 + 0x29c) = *(int *)(param_1 + 0x29c) + *(int *)(param_2 + 0x10);
  *(int *)(param_1 + 0x2a0) = *(int *)(param_1 + 0x2a0) + *(int *)(param_2 + 0x14);
  *(int *)(param_1 + 0x2a4) = *(int *)(param_1 + 0x2a4) + *(int *)(param_2 + 0x18);
  *(int *)(param_1 + 0x2a8) = *(int *)(param_1 + 0x2a8) + *(int *)(param_2 + 0x1c);
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x1c))();
  return;
}

