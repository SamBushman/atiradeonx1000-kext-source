#include "decls.h"

/* yy_delete_buffer @ 0x97badae0 (124 bytes) */
int yy_delete_buffer(param_1)
  unsigned char * param_1;
{
  if (param_1 != (unsigned char *)0x0) {
    if (param_1 == _yy_current_buffer) {
      _yy_current_buffer = (unsigned char *)0x0;
    }
    if (*(int *)(param_1 + 0x14) != 0) {
      ((int (*)())yy_flex_free)(*(void **)(param_1 + 4));
    }
    ((int (*)())yy_flex_free)(param_1);
    return;
  }
  return;
}

/* yy_init_buffer @ 0x97badb5c (68 bytes) */
int yy_init_buffer(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  ((int (*)())yy_flush_buffer)(param_1);
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = 1;
  *(unsigned char **)param_1 = param_2;
  return;
}

/* yy_flush_buffer @ 0x97badba0 (88 bytes) */
int yy_flush_buffer(param_1)
  unsigned char * param_1;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  **(undefined1 **)(param_1 + 4) = 0;
  *(undefined1 *)(*(int *)(param_1 + 4) + 1) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 1;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (param_1 != _yy_current_buffer) {
    return;
  }
  yy_load_buffer_state();
  return;
}

/* yy_scan_buffer @ 0x97badbf8 (192 bytes) */
int yy_scan_buffer(param_1, param_2)
  char *param_1;
  uint param_2;
{
  unsigned char * pyVar1;
  
  if (((param_2 < 2) || (param_1[param_2 - 2] != '\0')) || (param_1[param_2 - 1] != '\0')) {
    pyVar1 = (unsigned char *)0x0;
  }
  else {
    pyVar1 = (unsigned char *)((int (*)())yy_flex_alloc)(0x28);
    if (pyVar1 == (unsigned char *)0x0) {
      ((int (*)())yy_fatal_error)("out of dynamic memory in yy_scan_buffer()");
    }
    *(char **)(pyVar1 + 8) = param_1;
    *(uint *)(pyVar1 + 0x10) = param_2 - 2;
    *(undefined4 *)(pyVar1 + 0x1c) = 1;
    *(undefined4 *)(pyVar1 + 0x24) = 0;
    *(uint *)(pyVar1 + 0xc) = param_2 - 2;
    *(char **)(pyVar1 + 4) = param_1;
    *(undefined4 *)(pyVar1 + 0x14) = 0;
    *(undefined4 *)pyVar1 = 0;
    *(undefined4 *)(pyVar1 + 0x18) = 0;
    *(undefined4 *)(pyVar1 + 0x20) = 0;
    yy_switch_to_buffer(pyVar1);
  }
  return pyVar1;
}

/* yy_scan_string @ 0x97badcb8 (44 bytes) */
int yy_scan_string(param_1)
  char *param_1;
{
  char cVar1;
  int iVar2;
  
  iVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    iVar2 = iVar2 + 1;
    cVar1 = param_1[iVar2];
  }
  ((int (*)())yy_scan_bytes)(param_1,iVar2);
  return;
}

/* yy_scan_bytes @ 0x97badce4 (176 bytes) */
int yy_scan_bytes(param_1, param_2)
  char *param_1;
  int param_2;
{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)((int (*)())yy_flex_alloc)(param_2 + 2U);
  if (pcVar2 == (char *)0x0) {
    ((int (*)())yy_fatal_error)("out of dynamic memory in yy_scan_bytes()");
  }
  iVar1 = 0;
  iVar3 = param_2;
  if (0 < param_2) {
    do {
      pcVar2[iVar1] = param_1[iVar1];
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  pcVar2[param_2 + 1] = '\0';
  pcVar2[param_2] = '\0';
  iVar3 = ((int (*)())yy_scan_buffer)(pcVar2,param_2 + 2U);
  if (iVar3 == 0) {
    ((int (*)())yy_fatal_error)("bad buffer in yy_scan_bytes()");
  }
  *(undefined4 *)(iVar3 + 0x14) = 1;
  return iVar3;
}

/* yy_fatal_error @ 0x97badd94 (60 bytes) */
int yy_fatal_error(param_1)
  char *param_1;
{
  _fprintf((FILE *)(PTR_DAT_a7b7c0bc + 0xb0),"%s\n",param_1);
                    
  _exit(2);
}

/* yy_flex_alloc @ 0x97baddd0 (4 bytes) */
int yy_flex_alloc(param_1)
  uint param_1;
{
                    
                    
  return _malloc(param_1);
}

/* yy_flex_realloc @ 0x97baddd4 (4 bytes) */
int yy_flex_realloc(param_1, param_2)
  void *param_1;
  uint param_2;
{
                    
                    
  return _realloc(param_1,param_2);
}

/* yy_flex_free @ 0x97baddd8 (4 bytes) */
int yy_flex_free(param_1)
  void *param_1;
{
                    
                    
  return _free(param_1);
}

/* PaParseStrings @ 0x97badddc (452 bytes) */
int PaParseStrings(param_1, param_2, param_3, param_4, param_5)
  char **param_1;
  int *param_2;
  int param_3;
  int param_4;
  unsigned char * param_5;
{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  char **ppcVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 extraout_r4;
  int iVar7;
  unsigned char * pTVar8;
  undefined4 in_r8;
  int iVar9;
  undefined4 in_r10;
  int local_30 [4];
  
  iVar3 = param_3;
  iVar7 = param_4;
  pTVar8 = param_5;
  _ScanFromString(*param_1);
  uVar5 = 1;
  *(unsigned char **)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) = param_5;
  if (param_3 != 0) {
    iVar9 = 0;
    ppcVar4 = param_1;
    if (0 < param_3) {
      do {
        if (*ppcVar4 == (char *)0x0) {
          TParseContext__error
                    ((int)param_5,(char *)0x0,"Null shader source string","","",in_r8,iVar9,in_r10);
          TParseContext__recover(param_5);
          goto LAB_97badf80;
        }
        iVar9 = iVar9 + 1;
        ppcVar4 = ppcVar4 + 1;
      } while (iVar9 < param_3);
    }
    if (param_2 == (int *)0x0) {
      param_2 = local_30;
      local_30[0] = _strlen(*param_1);
    }
    yyrestart((unsigned char *)0x0);
    puVar1 = PTR__cpp_a7b7c0a4;
    uVar5 = 0;
    *(undefined4 *)(param_5 + 0x60) = 0;
    *(undefined4 *)(*(int *)puVar1 + 0x144) = 0;
    *(char ***)(*(int *)puVar1 + 0x150) = param_1;
    *(int *)(*(int *)puVar1 + 0x14c) = param_3;
    *(int **)(*(int *)puVar1 + 0x148) = param_2;
    *(undefined4 *)(*(int *)puVar1 + 0x28) = 0;
    _yylineno = 1;
    if ((-1 < **(int **)(*(int *)puVar1 + 0x148)) &&
       (((yyparse(param_5,extraout_r4,iVar3,iVar7,pTVar8,in_r8,*(int **)(*(int *)puVar1 + 0x148),
                  in_r10), puVar2 = PTR__cpp_a7b7c0a4, *(int *)(*(int *)puVar1 + 0x140) == 1 ||
         (*(int *)(param_5 + 0x14) != 0)) || (uVar5 = 0, 0 < *(int *)(param_5 + 0x18))))) {
      if (param_4 != 0) {
        iVar3 = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x20);
        while (iVar3 != 0) {
          iVar3 = *(int *)puVar2;
          puVar6 = *(undefined4 **)(iVar3 + 0x20);
          *(undefined4 *)(iVar3 + 0x20) = *puVar6;
          _free(puVar6);
          iVar3 = *(int *)(*(int *)puVar2 + 0x20);
        }
      }
LAB_97badf80:
      uVar5 = 1;
    }
  }
  return uVar5;
}

/* yyerror @ 0x97badfa0 (184 bytes) */
int yyerror(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  char *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar2 = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c);
  pcVar3 = _yytext;
  if (*(int *)(iVar2 + 0x60) != 0) {
    if (-1 < *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x154)) {
      return;
    }
    pcVar3 = "pre-mature EOF";
  }
  TParseContext__error(iVar2,_yylineno,"syntax error",pcVar3,param_1,"",param_7,param_8);
  TParseContext__recover(*(unsigned char **)(*(int *)puVar1 + 0x2c));
  return;
}

/* PaReservedWord @ 0x97bae058 (108 bytes) */
int PaReservedWord()
{
  undefined *puVar1;
  undefined4 in_r9;
  undefined4 in_r10;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  TParseContext__error
            (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c),_yylineno,"Reserved word.",_yytext,"","",
             in_r9,in_r10);
  TParseContext__recover(*(unsigned char **)(*(int *)puVar1 + 0x2c));
  return;
}

/* PaIdentOrType @ 0x97bae0c4 (228 bytes) */
int PaIdentOrType(param_1, param_2, param_3)
  unsigned char * param_1;
  unsigned char * param_2;
  unsigned char ** param_3;
{
  unsigned char * a0;
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_30 [5];
  
  piVar3 = *(int **)(param_2 + 4);
  iVar2 = *piVar3;
  iVar4 = (piVar3[1] - iVar2 >> 2) + -1;
  while( true ) {
    iVar2 = *(int *)(iVar2 + iVar4 * 4);
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_30,iVar2,param_1);
    a0 = (unsigned char *)0x0;
    if (local_30[0] != *(int *)(iVar2 + 4)) {
      a0 = *(unsigned char **)(local_30[0] + 0x18);
    }
    iVar4 = iVar4 + -1;
    if ((a0 != (unsigned char *)0x0) || (iVar4 < 0)) break;
    iVar2 = *piVar3;
  }
  *param_3 = a0;
  if ((((*(int *)(param_2 + 0x1c) != 0) || (a0 == (unsigned char *)0x0)) ||
      (iVar2 = (**(code **)(*(int *)a0 + 0x10))(a0), iVar2 == 0)) ||
     (*(int *)(*param_3 + 0x34) == 0)) {
    uVar1 = 0x12a;
  }
  else {
    uVar1 = 299;
    *(undefined4 *)(param_2 + 0x1c) = 1;
  }
  return uVar1;
}

/* PaParseComment @ 0x97bae1a8 (228 bytes) */
int PaParseComment(param_1, param_2)
  int *param_1;
  unsigned char * param_2;
{
  int iVar1;
  undefined4 in_r9;
  undefined4 in_r10;
  int iVar2;
  
  iVar2 = 0;
  do {
    while( true ) {
      iVar1 = yyinput();
      if (iVar1 == 10) {
        *param_1 = *param_1 + 1;
      }
      if (iVar1 != 0x2a) break;
      iVar2 = 1;
    }
    if (iVar1 < 0x2b) {
      if (iVar1 == -1) {
        TParseContext__error
                  ((int)param_2,_yylineno,"End of shader found before end of comment.","","","",
                   in_r9,in_r10);
        TParseContext__recover(*(unsigned char **)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c));
        return 0;
      }
LAB_97bae268:
      iVar2 = 0;
    }
    else {
      if (iVar1 != 0x2f) goto LAB_97bae268;
      if (iVar2 == 1) {
        return 1;
      }
    }
    if (iVar2 == 2) {
      return 1;
    }
  } while( true );
}

/* _CPPDebugLogMsg @ 0x97bae28c (92 bytes) */
int _CPPDebugLogMsg(param_1)
  char *param_1;
{
  void *this;
  
  this = (void *)(*(int *)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) + 8) + 8);
  __ZN13TInfoSinkBase6appendEPKc(this,param_1);
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  return;
}

/* _CPPWarningToInfoLog @ 0x97bae2e8 (92 bytes) */
int _CPPWarningToInfoLog(param_1)
  char *param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint a1;
  void *this;
  char in_RESERVE;
  byte bVar5;
  char *local_70 [4];
  char acStack_60 [64];
  unsigned char aaStack_20 [16];
  
  uVar2 = _yylineno;
  this = *(void **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) + 8);
                    
  __ZN13TInfoSinkBase6appendEPKc(this,"WARNING: ");
  a1 = uVar2 & 0xffff;
  bVar5 = (a1 == 0) << 1;
  iVar4 = (int)uVar2 >> 0x10;
  if (a1 == 0) {
    _sprintf(acStack_60,"%d:? ",iVar4);
  }
  else {
    _sprintf(acStack_60,"%d:%d",iVar4,a1);
  }
  __ZNSsC1EPKcRKSaIcE(local_70,acStack_60,aaStack_20);
  local_70[0][*(int *)(local_70[0] + -0xc)] = *PTR__S_terminal_a7b7c0b8;
  __ZN13TInfoSinkBase6appendEPKc(this,local_70[0]);
  piVar3 = (int *)(local_70[0] + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar1;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_70[0] + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(this,": ");
  __ZN13TInfoSinkBase6appendEPKc(this,param_1);
  __ZN13TInfoSinkBase6appendEPKc(this,"\n");
  return;
}

/* _CPPShInfoLogMsg @ 0x97bae468 (100 bytes) */
int _CPPShInfoLogMsg(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 in_r10;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  TParseContext__error
            (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c),_yylineno,"","",param_1,"",param_7,in_r10);
  TParseContext__recover(*(unsigned char **)(*(int *)puVar1 + 0x2c));
  return;
}

/* _CPPErrorToInfoLog @ 0x97bae4cc (104 bytes) */
int _CPPErrorToInfoLog(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 in_r10;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  TParseContext__error
            (*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c),_yylineno,"syntax error","",param_1,"",
             param_7,in_r10);
  TParseContext__recover(*(unsigned char **)(*(int *)puVar1 + 0x2c));
  return;
}

/* _SetLineNumber @ 0x97bae534 (44 bytes) */
int _SetLineNumber(param_1)
  uint param_1;
{
  _yylineno = _yylineno & 0xffff0000 | param_1;
  return;
}

/* _SetStringNumber @ 0x97bae560 (44 bytes) */
int _SetStringNumber(param_1)
  int param_1;
{
  _yylineno = param_1 << 0x10 | (uint)(*(unsigned short *)((unsigned char *)&(_yylineno) + 2));
  return _yylineno;
}

/* _GetStringNumber @ 0x97bae58c (32 bytes) */
int _GetStringNumber()
{
  return _yylineno >> 0x10;
}

/* _GetLineNumber @ 0x97bae5ac (32 bytes) */
int _GetLineNumber()
{
  return _yylineno & 0xffff;
}

/* _IncLineNumber @ 0x97bae5cc (52 bytes) */
int _IncLineNumber()
{
  if (0xffff < (_yylineno & 0xffff)) {
    return;
  }
  _yylineno = _yylineno + 1;
  return;
}

/* _DecLineNumber @ 0x97bae600 (52 bytes) */
int _DecLineNumber()
{
  if ((_yylineno & 0xffff) == 0) {
    return;
  }
  _yylineno = _yylineno - 1;
  return;
}

/* _HandlePragma @ 0x97bae634 (576 bytes) */
int _HandlePragma(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  char *pcVar2;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 uVar3;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int in_r9;
  undefined4 uVar4;
  
  uVar4 = *param_1;
  uVar3 = 9;
  iVar1 = _memcmp(uVar4,"optimize",9);
  if (iVar1 == 0) {
    if (param_2 == 4) {
      uVar3 = 2;
      iVar1 = _memcmp(param_1[1],"(",2);
      if (iVar1 == 0) {
        uVar4 = param_1[2];
        iVar1 = _memcmp(uVar4,"on",3);
        if (iVar1 == 0) {
          in_r9 = *(int *)PTR__cpp_a7b7c0a4;
          *(undefined4 *)(*(int *)(in_r9 + 0x2c) + 0x40) = 1;
        }
        else {
          uVar3 = 4;
          iVar1 = _memcmp(uVar4,"off",4);
          if (iVar1 != 0) {
            pcVar2 = "\"on\" or \"off\" expected after \'(\' for \'optimize\' pragma";
            uVar4 = extraout_r4_01;
            goto LAB_97bae84c;
          }
          in_r9 = *(int *)PTR__cpp_a7b7c0a4;
          *(undefined4 *)(*(int *)(in_r9 + 0x2c) + 0x40) = 0;
        }
        uVar3 = 2;
        iVar1 = _memcmp(param_1[3],")",2);
        if (iVar1 == 0) {
          return;
        }
        pcVar2 = "\")\" expected to end \'optimize\' pragma";
        uVar4 = extraout_r4_02;
      }
      else {
        pcVar2 = "\"(\" expected after \'optimize\' keyword";
        uVar4 = extraout_r4_00;
      }
    }
    else {
      pcVar2 = "optimize pragma syntax is incorrect";
      uVar4 = extraout_r4;
    }
  }
  else {
    uVar3 = 6;
    iVar1 = _memcmp(uVar4,"debug",6);
    if (iVar1 != 0) {
      return;
    }
    if (param_2 == 4) {
      uVar3 = 2;
      iVar1 = _memcmp(param_1[1],"(",2);
      if (iVar1 == 0) {
        uVar4 = param_1[2];
        iVar1 = _memcmp(uVar4,"on",3);
        if (iVar1 == 0) {
          in_r9 = *(int *)PTR__cpp_a7b7c0a4;
          *(undefined4 *)(*(int *)(in_r9 + 0x2c) + 0x44) = 1;
        }
        else {
          uVar3 = 4;
          iVar1 = _memcmp(uVar4,"off",4);
          if (iVar1 != 0) {
            pcVar2 = "\"on\" or \"off\" expected after \'(\' for \'debug\' pragma";
            uVar4 = extraout_r4_05;
            goto LAB_97bae84c;
          }
          in_r9 = *(int *)PTR__cpp_a7b7c0a4;
          *(undefined4 *)(*(int *)(in_r9 + 0x2c) + 0x44) = 0;
        }
        uVar3 = 2;
        iVar1 = _memcmp(param_1[3],")",2);
        if (iVar1 == 0) {
          return;
        }
        pcVar2 = "\")\" expected to end \'debug\' pragma";
        uVar4 = extraout_r4_06;
      }
      else {
        pcVar2 = "\"(\" expected after \'debug\' keyword";
        uVar4 = extraout_r4_04;
      }
    }
    else {
      pcVar2 = "debug pragma syntax is incorrect";
      uVar4 = extraout_r4_03;
    }
  }
LAB_97bae84c:
  ((int (*)())_CPPShInfoLogMsg)(pcVar2,uVar4,uVar3,in_r6,in_r7,in_r8,in_r9);
  return;
}

/* _StoreStr @ 0x97bae874 (448 bytes) */
int _StoreStr(param_1)
  char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  ulong uVar4;
  unsigned char * paVar5;
  unsigned char * this;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_c0;
  int local_bc;
  undefined4 local_b0;
  undefined4 local_a0;
  int local_9c;
  undefined4 local_90 [4];
  undefined4 local_80 [4];
  undefined4 local_70;
  int local_6c;
  undefined4 local_60;
  int local_5c;
  undefined4 local_50 [4];
  undefined4 local_40 [4];
  undefined4 local_30 [7];
  
  iVar3 = DAT_a7b7baa8;
  piVar2 = (int *)(DAT_a7b7baa8 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_c0 = GetGlobalPoolAllocator();
  local_bc = iVar3 + 0xc;
  local_b0 = local_c0;
  local_90[0] = GetGlobalPoolAllocator();
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
            ((unsigned char *)&local_a0,param_1,(unsigned char *)local_90);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(&local_c0,(unsigned char *)&local_a0);
  piVar2 = (int *)(local_9c + -4);
  local_80[0] = local_a0;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_9c + -0xc),local_80);
  }
  this = (unsigned char *)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) + 0x58);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&local_60,this);
  uVar4 = _strlen(" ");
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm((unsigned char *)&local_60," ",uVar4);
  __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
            ((unsigned char *)&local_70,(unsigned char *)&local_60,&local_c0);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(this,(unsigned char *)&local_70);
  piVar2 = (int *)(local_6c + -4);
  local_50[0] = local_70;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_6c + -0xc),local_50);
  }
  piVar2 = (int *)(local_5c + -4);
  local_40[0] = local_60;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(local_5c + -0xc),local_40);
  }
  piVar2 = (int *)(local_bc + -4);
  paVar5 = (unsigned char *)(local_bc + -0xc);
  local_30[0] = local_c0;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    paVar5 = (unsigned char *)
             __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar5,local_30);
  }
  return paVar5;
}

/* _GetStrfromTStr @ 0x97baea34 (80 bytes) */
int _GetStrfromTStr()
{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  puVar1 = PTR__cpp_a7b7c0a4;
  iVar2 = *(int *)PTR__cpp_a7b7c0a4;
  iVar3 = *(int *)(iVar2 + 0x2c);
  iVar4 = *(int *)(iVar3 + 0x5c);
  *(undefined1 *)(iVar4 + *(int *)(iVar4 + -0xc)) = *DAT_a7b7baa4;
  *(undefined4 *)(iVar2 + 0x13c) = *(undefined4 *)(iVar3 + 0x5c);
  return *(undefined4 *)(*(int *)puVar1 + 0x13c);
}

/* _ResetTString @ 0x97baea84 (252 bytes) */
int _ResetTString()
{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  unsigned char * psVar4;
  
  iVar1 = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c);
  uVar2 = _strlen("");
  if (0x3ffffffc < uVar2) {
    std____throw_length_error("basic_string::assign");
  }
  pcVar3 = *(char **)(iVar1 + 0x5c);
  if (((0 < *(int *)(pcVar3 + -4)) || ("" < pcVar3)) || (pcVar3 + *(int *)(pcVar3 + -0xc) < "")) {
    psVar4 = __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE15_M_replace_safeIPKcEERS3_N9__gnu_cxx17__normal_iteratorIPcS3_EESB_T_SC_
                       ((void *)(iVar1 + 0x58),pcVar3,pcVar3 + *(int *)(pcVar3 + -0xc),"","" + uVar2
                       );
    return (char *)psVar4;
  }
  if ((uint)((int)"" - (int)pcVar3) < uVar2) {
    if (pcVar3 == "") goto LAB_97baeb5c;
    _memmove(pcVar3,"",uVar2);
  }
  else {
    _memcpy(pcVar3,"",uVar2);
  }
  pcVar3 = *(char **)(iVar1 + 0x5c);
LAB_97baeb5c:
  *(uint *)(pcVar3 + -0xc) = uVar2;
  *(undefined1 *)(*(int *)(iVar1 + 0x5c) + uVar2) = 0;
  return pcVar3;
}

/* _GetBehavior @ 0x97baeb80 (484 bytes) */
int _GetBehavior(param_1)
  char *param_1;
{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  ulong uVar6;
  undefined4 extraout_r4;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_80;
  int local_7c;
  undefined4 local_70;
  int local_6c;
  undefined4 local_60;
  int local_5c;
  undefined4 local_50 [4];
  undefined4 local_40 [4];
  undefined4 local_30 [4];
  undefined4 local_20 [4];
  
  iVar4 = _memcmp("require",param_1,8);
  uVar5 = 0;
  if (iVar4 != 0) {
    iVar4 = _memcmp("enable",param_1,7);
    uVar5 = 1;
    if (iVar4 != 0) {
      iVar4 = _memcmp("disable",param_1,8);
      uVar5 = 3;
      if (iVar4 != 0) {
        iVar4 = _memcmp("warn",param_1,5);
        uVar5 = 2;
        if (iVar4 != 0) {
          local_50[0] = GetGlobalPoolAllocator();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    ((unsigned char *)&local_60,"behavior \'",(unsigned char *)local_50);
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
                    ((unsigned char *)&local_70,(unsigned char *)&local_60);
          uVar6 = _strlen(param_1);
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm
                    ((unsigned char *)&local_70,param_1,uVar6);
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_80,(unsigned char *)&local_70);
          uVar6 = _strlen("\' is not supported");
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm
                    (&local_80,"\' is not supported",uVar6);
          bVar1 = *DAT_a7b7baa4;
          *(byte *)(local_7c + *(int *)(local_7c + -0xc)) = bVar1;
          ((int (*)())_CPPShInfoLogMsg)(local_7c,extraout_r4,uVar6,in_r6,in_r7,in_r8,(uint)bVar1);
          piVar3 = (int *)(local_7c + -4);
          local_40[0] = local_80;
          do {
            iVar4 = *piVar3;
            if (in_RESERVE != '\0') {
              iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
              *piVar3 = iVar2;
              in_cr0 = 2;
            }
          } while (!(bool)(in_cr0 >> 1 & 1));
          if (iVar4 < 1) {
            __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                      ((unsigned char *)(local_7c + -0xc),local_40);
          }
          piVar3 = (int *)(local_6c + -4);
          local_30[0] = local_70;
          do {
            iVar4 = *piVar3;
            if (in_RESERVE != '\0') {
              iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
              *piVar3 = iVar2;
              in_cr0 = 2;
            }
          } while (!(bool)(in_cr0 >> 1 & 1));
          if (iVar4 < 1) {
            __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                      ((unsigned char *)(local_6c + -0xc),local_30);
          }
          piVar3 = (int *)(local_5c + -4);
          local_20[0] = local_60;
          do {
            iVar4 = *piVar3;
            if (in_RESERVE != '\0') {
              iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
              *piVar3 = iVar2;
              in_cr0 = 2;
            }
          } while (!(bool)(in_cr0 >> 1 & 1));
          if (iVar4 < 1) {
            __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                      ((unsigned char *)(local_5c + -0xc),local_20);
          }
          uVar5 = 3;
        }
      }
    }
  }
  return uVar5;
}

/* _updateExtensionBehavior @ 0x97baed64 (1124 bytes) */
int _updateExtensionBehavior(param_1, param_2)
  char *param_1;
  undefined4 param_2;
{
  byte bVar1;
  int iVar2;
  undefined *puVar3;
  char *pcVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  ulong uVar8;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 in_r6;
  uint a1;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  void *this;
  char in_RESERVE;
  byte in_cr0;
  int local_1f0 [4];
  undefined4 local_1e0;
  char *local_1dc;
  undefined4 local_1d0;
  int local_1c0;
  int local_1b0;
  int local_1a0 [4];
  undefined4 local_190;
  int local_18c;
  undefined4 local_180 [4];
  undefined4 local_170 [4];
  int local_160;
  char *local_150;
  int local_14c;
  undefined4 local_140;
  int local_13c;
  undefined4 local_130;
  int local_12c;
  undefined4 local_120 [4];
  char *local_110 [4];
  undefined4 local_100 [4];
  undefined4 local_f0 [4];
  undefined4 local_e0;
  int local_dc;
  undefined4 local_d0 [4];
  char *local_c0 [4];
  undefined4 local_b0 [4];
  undefined4 local_a0 [4];
  char acStack_90 [64];
  undefined4 local_50 [4];
  undefined4 local_40 [4];
  undefined4 local_30 [5];
  
  uVar6 = ((int (*)())_GetBehavior)(param_2);
  iVar7 = DAT_a7b7baa8;
  piVar5 = (int *)(DAT_a7b7baa8 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(*piVar5 + 1,0,piVar5);
      *piVar5 = iVar2;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_1e0 = GetGlobalPoolAllocator();
  local_1dc = (char *)(iVar7 + 0xc);
  uVar10 = 4;
  local_1d0 = local_1e0;
  iVar7 = _memcmp(param_1,"all",4);
  puVar3 = PTR__cpp_a7b7c0a4;
  if (iVar7 == 0) {
    if (1 < uVar6) {
      local_1f0[0] = *(int *)(*(int *)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) + 0x34) + 8);
      local_1c0 = local_1f0[0];
      while (local_1b0 = *(int *)(*(int *)(*(int *)puVar3 + 0x2c) + 0x34), local_1f0[0] != local_1b0
            ) {
        *(uint *)(local_1f0[0] + 0x18) = uVar6;
        std___Rb_tree_base_iterator___M_increment((unsigned char *)local_1f0);
      }
LAB_97baf31c:
      piVar5 = (int *)(local_1dc + -4);
      local_50[0] = local_1e0;
      do {
        iVar7 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar2 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
          *piVar5 = iVar2;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (0 < iVar7) {
        return;
      }
      puVar9 = local_50;
      goto code_r0x97baf34c;
    }
    ((int (*)())_CPPShInfoLogMsg)("extension \'all\' cannot have \'require\' or \'enable\' behavior",extraout_r4,
                     uVar10,in_r6,in_r7,in_r8,in_r9);
    piVar5 = (int *)(local_1dc + -4);
    local_30[0] = local_1e0;
    do {
      iVar7 = *piVar5;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
        *piVar5 = iVar2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    puVar9 = local_30;
  }
  else {
    iVar7 = *(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c);
    local_180[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (&local_190,param_1,(unsigned char *)local_180);
    std___Rb_tree_std__string_std__pair_std__string_const_TBehavior__std___Select1st_std__pair_std__string_const_TBehavior___std__less_std__string__pool_allocator_std__pair_std__string_const_TBehavior_____find((unsigned char *)local_1a0,iVar7 + 0x30,&local_190);
    local_1f0[0] = local_1a0[0];
    piVar5 = (int *)(local_18c + -4);
    local_170[0] = local_190;
    do {
      iVar7 = *piVar5;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
        *piVar5 = iVar2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_18c + -0xc),local_170);
    }
    local_160 = *(int *)(*(int *)(*(int *)puVar3 + 0x2c) + 0x34);
    if (local_1f0[0] != local_160) {
      *(uint *)(local_1f0[0] + 0x18) = uVar6;
      goto LAB_97baf31c;
    }
    if (uVar6 == 0) {
      local_120[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                ((unsigned char *)&local_130,"extension \'",(unsigned char *)local_120);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
                ((unsigned char *)&local_140,(unsigned char *)&local_130);
      uVar8 = _strlen(param_1);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm((unsigned char *)&local_140,param_1,uVar8)
      ;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_150,(unsigned char *)&local_140);
      uVar8 = _strlen("\' is not supported");
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm
                (&local_150,"\' is not supported",uVar8);
      bVar1 = *DAT_a7b7baa4;
      *(byte *)(local_14c + *(int *)(local_14c + -0xc)) = bVar1;
      ((int (*)())_CPPShInfoLogMsg)(local_14c,extraout_r4_00,uVar8,in_r6,in_r7,in_r8,(uint)bVar1);
      piVar5 = (int *)(local_14c + -4);
      local_110[0] = local_150;
      do {
        iVar7 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar2 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
          *piVar5 = iVar2;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar7 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_14c + -0xc),local_110);
      }
      piVar5 = (int *)(local_13c + -4);
      local_100[0] = local_140;
      do {
        iVar7 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar2 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
          *piVar5 = iVar2;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar7 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_13c + -0xc),local_100);
      }
      piVar5 = (int *)(local_12c + -4);
      local_f0[0] = local_130;
      do {
        iVar7 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar2 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
          *piVar5 = iVar2;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar7 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_12c + -0xc),local_f0);
      }
    }
    else if ((-1 < (int)uVar6) && ((int)uVar6 < 4)) {
      local_d0[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                ((unsigned char *)&local_e0,"extension \'",(unsigned char *)local_d0);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
                ((unsigned char *)&local_140,(unsigned char *)&local_e0);
      uVar8 = _strlen(param_1);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm((unsigned char *)&local_140,param_1,uVar8)
      ;
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
                ((unsigned char *)&local_150,(unsigned char *)&local_140);
      uVar8 = _strlen("\' is not supported");
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm
                ((unsigned char *)&local_150,"\' is not supported",uVar8);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_(&local_1e0,(unsigned char *)&local_150);
      piVar5 = (int *)(local_14c + -4);
      local_c0[0] = local_150;
      do {
        iVar7 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar2 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
          *piVar5 = iVar2;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar7 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_14c + -0xc),local_c0);
      }
      piVar5 = (int *)(local_13c + -4);
      local_b0[0] = local_140;
      do {
        iVar7 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar2 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
          *piVar5 = iVar2;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar7 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_13c + -0xc),local_b0);
      }
      piVar5 = (int *)(local_dc + -4);
      local_a0[0] = local_e0;
      do {
        iVar7 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar2 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
          *piVar5 = iVar2;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar7 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_dc + -0xc),local_a0);
      }
      pcVar4 = local_1dc;
      this = *(void **)(*(int *)(*(int *)PTR__cpp_a7b7c0a4 + 0x2c) + 8);
      local_1dc[*(int *)(local_1dc + -0xc)] = *DAT_a7b7baa4;
      uVar6 = _yylineno;
                    
      __ZN13TInfoSinkBase6appendEPKc(this,"WARNING: ");
      a1 = uVar6 & 0xffff;
      in_cr0 = (a1 == 0) << 1;
      iVar7 = (int)uVar6 >> 0x10;
      if (a1 == 0) {
        _sprintf(acStack_90,"%d:? ",iVar7);
      }
      else {
        _sprintf(acStack_90,"%d:%d",iVar7,a1);
      }
      __ZNSsC1EPKcRKSaIcE((unsigned char *)&local_150,acStack_90,(unsigned char *)&local_140);
      local_150[*(int *)(local_150 + -0xc)] = *PTR__S_terminal_a7b7c0b8;
      __ZN13TInfoSinkBase6appendEPKc(this,local_150);
      piVar5 = (int *)(local_150 + -4);
      do {
        iVar7 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar2 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
          *piVar5 = iVar2;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar7 < 1) {
        __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(local_150 + -0xc));
      }
      __ZN13TInfoSinkBase6appendEPKc(this,": ");
      __ZN13TInfoSinkBase6appendEPKc(this,pcVar4);
      __ZN13TInfoSinkBase6appendEPKc(this,"\n");
    }
    piVar5 = (int *)(local_1dc + -4);
    local_40[0] = local_1e0;
    do {
      iVar7 = *piVar5;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar7 + -1,0,piVar5);
        *piVar5 = iVar2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    puVar9 = local_40;
  }
  if (0 < iVar7) {
    return;
  }
code_r0x97baf34c:
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
            ((unsigned char *)(local_1dc + -0xc),puVar9);
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
    return iVar2;
  }
  return iVar2;
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
  pcVar2 = (char *)_malloc(0x100);
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
  _realloc(pcVar2,pcVar5 + (1 - (int)pcVar2));
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
  pcVar1 = (char *)_malloc(0x100);
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
  _realloc(pcVar1,pcVar6 + (1 - (int)pcVar1));
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
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  uint uStack00000018;
  uint uStack0000001c;
  
  uStack00000018 = param_1;
  uStack0000001c = param_2;
  pcVar1 = (char *)_malloc(0x100);
  iVar2 = ((int (*)())ncpy)(pcVar1,uStack0000001c & 0xffff);
  pcVar7 = pcVar1 + iVar2;
  switch(uStack00000018 >> 0x10 & 0xf) {
  default:
    pcVar6 = ": Error, binding not found.";
    break;
  case 1:
    pcVar6 = ": PP_BIND_OUTPUT_RESULT_POSITION";
    break;
  case 2:
    pcVar6 = ": PP_BIND_OUTPUT_RESULT_FOG_COORD";
    break;
  case 3:
    pcVar6 = ": PP_BIND_OUTPUT_RESULT_POINT_SIZE";
    break;
  case 4:
    iVar2 = ((int (*)())scpy)(pcVar7,": PP_BIND_OUTPUT_RESULT_COLOR:");
    if ((uStack00000018 & 1) == 0) {
      pcVar6 = "PP_FACE_FRONT:";
    }
    else {
      pcVar6 = "PP_FACE_BACK:";
    }
    iVar3 = ((int (*)())scpy)(pcVar7 + iVar2,pcVar6);
    pcVar7 = pcVar7 + iVar2 + iVar3;
    uVar5 = uStack00000018 >> 1 & 7;
    goto LAB_97bafcf4;
  case 5:
    iVar2 = ((int (*)())scpy)(pcVar7,": PP_BIND_OUTPUT_RESULT_SEC_COLOR:");
    pcVar7 = pcVar7 + iVar2;
    if ((uStack00000018 & 1) == 0) {
      pcVar6 = "PP_FACE_FRONT";
    }
    else {
      pcVar6 = "PP_FACE_BACK";
    }
    break;
  case 6:
    pcVar6 = ": PP_BIND_OUTPUT_RESULT_TEX_COORD:";
    goto LAB_97bafd6c;
  case 7:
    pcVar6 = ": PP_BIND_OUTPUT_RESULT_DEPTH";
    break;
  case 8:
    pcVar6 = ": PP_BIND_OUTPUT_RESULT_EYE_POSITION";
    break;
  case 9:
    pcVar6 = ": PP_BIND_OUTPUT_RESULT_CLIP_VERTEX";
    break;
  case 10:
    pcVar6 = ": PP_BIND_OUTPUT_RESULT_ATTRIB:";
LAB_97bafd6c:
    iVar2 = ((int (*)())scpy)(pcVar7,pcVar6);
    pcVar7 = pcVar7 + iVar2;
    uVar5 = uStack00000018 & 0x1f;
LAB_97bafcf4:
    iVar2 = ((int (*)())ncpy)(pcVar7,uVar5);
    goto LAB_97bafd98;
  }
  iVar2 = ((int (*)())scpy)(pcVar7,pcVar6);
LAB_97bafd98:
  pcVar7[iVar2] = '\0';
  uVar4 = _realloc(pcVar1,pcVar7 + iVar2 + (1 - (int)pcVar1));
  return uVar4;
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
  pcVar1 = (char *)_malloc(0x10);
  iVar2 = ((int (*)())ncpy)(pcVar1,uStack0000001c & 0xffff);
  pcVar1[iVar2] = '\0';
  return pcVar1;
}

/* Binding__ClearName @ 0x97bafe10 (72 bytes) */
int Binding__ClearName(this)
  unsigned char * this;
{
  if (*(int *)(this + 8) != 0) {
    _free(*(int *)(this + 8));
  }
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  return;
}

/* __ZN7BindingC2Ev @ 0x97bafe58 (4 bytes) */
int __ZN7BindingC2Ev(this)
  void *this;
{
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)((int)this + 0x20) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1c) = 1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 1;
  *(undefined2 *)((int)this + 0x24) = 0;
  *(undefined4 *)this = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* __ZN7BindingC1Ev @ 0x97bafe5c (4 bytes) */
int __ZN7BindingC1Ev(this)
  void *this;
{
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)((int)this + 0x20) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1c) = 1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 1;
  *(undefined2 *)((int)this + 0x24) = 0;
  *(undefined4 *)this = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* __ZN7BindingC4Ev @ 0x97bafe60 (76 bytes) */
int __ZN7BindingC4Ev(this)
  void *this;
{
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)((int)this + 0x20) = 0xffffffff;
  *(undefined4 *)((int)this + 0x1c) = 1;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 1;
  *(undefined2 *)((int)this + 0x24) = 0;
  *(undefined4 *)this = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* __ZN7BindingD2Ev @ 0x97bafeac (8 bytes) */
int __ZN7BindingD2Ev(this)
  void *this;
{
  ((int (*)())__ZN7BindingD4Ev)(this);
  return;
}

/* __ZN7BindingD1Ev @ 0x97bafeb4 (8 bytes) */
int __ZN7BindingD1Ev(this)
  void *this;
{
  ((int (*)())__ZN7BindingD4Ev)(this);
  return;
}

/* __ZN7BindingD4Ev @ 0x97bafebc (4 bytes) */
int __ZN7BindingD4Ev(this)
  void *this;
{
  if (*(void **)((int)this + 8) != (void *)0x0) {
    _free(*(void **)((int)this + 8));
  }
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  return;
}

/* __ZN7BindingC2ERKS_ @ 0x97bafec0 (4 bytes) */
int __ZN7BindingC2ERKS_(this, param_2)
  void *this;
  unsigned char * param_2;
{
  int iVar1;
  bool bVar4;
  ushort uVar3;
  ulong uVar2;
  char *pcVar5;
  
  *(undefined4 *)((int)this + 8) = 0;
  pcVar5 = *(char **)(param_2 + 8);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  ((int (*)())Binding__SetName)(this,pcVar5);
  iVar1 = Binding__GetLocation(param_2);
  Binding__SetLocation(this,iVar1);
  iVar1 = Binding__GetActiveIndex(param_2);
  Binding__SetActiveIndex(this,iVar1);
  bVar4 = (bool)((int (*)())Binding__IsClientRequest)(param_2);
  ((int (*)())Binding__SetClientRequest)(this,bVar4);
  bVar4 = (bool)((int (*)())Binding__IsBuiltIn)(param_2);
  ((int (*)())Binding__SetBuiltIn)(this,bVar4);
  uVar3 = Binding__GetOpenGLType(param_2);
  Binding__SetOpenGLType(this,uVar3);
  uVar2 = Binding__GetDecSize(param_2);
  Binding__SetDecSize(this,uVar2);
  uVar2 = Binding__GetActualSize(param_2);
  Binding__SetActualSize(this,uVar2);
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* __ZN7BindingC1ERKS_ @ 0x97bafec4 (4 bytes) */
int __ZN7BindingC1ERKS_(this, param_2)
  void *this;
  unsigned char * param_2;
{
  int iVar1;
  bool bVar4;
  ushort uVar3;
  ulong uVar2;
  char *pcVar5;
  
  *(undefined4 *)((int)this + 8) = 0;
  pcVar5 = *(char **)(param_2 + 8);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  ((int (*)())Binding__SetName)(this,pcVar5);
  iVar1 = Binding__GetLocation(param_2);
  Binding__SetLocation(this,iVar1);
  iVar1 = Binding__GetActiveIndex(param_2);
  Binding__SetActiveIndex(this,iVar1);
  bVar4 = (bool)((int (*)())Binding__IsClientRequest)(param_2);
  ((int (*)())Binding__SetClientRequest)(this,bVar4);
  bVar4 = (bool)((int (*)())Binding__IsBuiltIn)(param_2);
  ((int (*)())Binding__SetBuiltIn)(this,bVar4);
  uVar3 = Binding__GetOpenGLType(param_2);
  Binding__SetOpenGLType(this,uVar3);
  uVar2 = Binding__GetDecSize(param_2);
  Binding__SetDecSize(this,uVar2);
  uVar2 = Binding__GetActualSize(param_2);
  Binding__SetActualSize(this,uVar2);
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* __ZN7BindingC4ERKS_ @ 0x97bafec8 (224 bytes) */
int __ZN7BindingC4ERKS_(this, param_2)
  void *this;
  unsigned char * param_2;
{
  int iVar1;
  undefined4 uVar2;
  ushort uVar4;
  ulong uVar3;
  char *pcVar5;
  
  *(undefined4 *)((int)this + 8) = 0;
  pcVar5 = *(char **)(param_2 + 8);
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  ((int (*)())Binding__SetName)(this,pcVar5);
  iVar1 = Binding__GetLocation(param_2);
  Binding__SetLocation(this,iVar1);
  iVar1 = Binding__GetActiveIndex(param_2);
  Binding__SetActiveIndex(this,iVar1);
  uVar2 = ((int (*)())Binding__IsClientRequest)(param_2);
  ((int (*)())Binding__SetClientRequest)(this,uVar2);
  uVar2 = ((int (*)())Binding__IsBuiltIn)(param_2);
  ((int (*)())Binding__SetBuiltIn)(this,uVar2);
  uVar4 = Binding__GetOpenGLType(param_2);
  Binding__SetOpenGLType(this,uVar4);
  uVar3 = Binding__GetDecSize(param_2);
  Binding__SetDecSize(this,uVar3);
  uVar3 = Binding__GetActualSize(param_2);
  Binding__SetActualSize(this,uVar3);
  *(undefined1 *)((int)this + 0x35) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined1 *)((int)this + 0x34) = 0;
  return;
}

/* Binding__operator_ @ 0x97baffa8 (232 bytes) */
int Binding__operator_(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  unsigned char BVar1;
  int iVar2;
  undefined4 uVar3;
  ushort uVar5;
  ulong uVar4;
  
  if (this != param_2) {
    SetName(this,*(char **)(param_2 + 8));
    iVar2 = Binding__GetLocation(param_2);
    Binding__SetLocation(this,iVar2);
    iVar2 = Binding__GetActiveIndex(param_2);
    Binding__SetActiveIndex(this,iVar2);
    uVar3 = ((int (*)())Binding__IsClientRequest)(param_2);
    ((int (*)())Binding__SetClientRequest)(this,uVar3);
    uVar3 = ((int (*)())Binding__IsBuiltIn)(param_2);
    ((int (*)())Binding__SetBuiltIn)(this,uVar3);
    uVar5 = Binding__GetOpenGLType(param_2);
    Binding__SetOpenGLType(this,uVar5);
    uVar4 = Binding__GetDecSize(param_2);
    Binding__SetDecSize(this,uVar4);
    uVar4 = Binding__GetActualSize(param_2);
    Binding__SetActualSize(this,uVar4);
    this[0x34] = param_2[0x34];
    BVar1 = param_2[0x35];
    *(undefined4 *)(this + 4) = 0;
    this[0x35] = BVar1;
    *(undefined4 *)this = 0;
  }
  return this;
}

/* __ZeqRK7BindingS1_ @ 0x97bb0090 (88 bytes) */
int __ZeqRK7BindingS1_(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  int iVar1;
  
  if (((*(int *)(param_1 + 0xc) == *(int *)(param_2 + 0xc)) &&
      (*(int *)(param_1 + 0x10) == *(int *)(param_2 + 0x10))) &&
     (iVar1 = _strncmp(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_2 + 8),
                       *(int *)(param_1 + 0x10)), iVar1 == 0)) {
    return 1;
  }
  return 0;
}

/* Binding__CatName @ 0x97bb00e8 (208 bytes) */
int Binding__CatName(this, param_2)
  unsigned char * this;
  char *param_2;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  if (param_2 != (char *)0x0) {
    iVar3 = _strlen(param_2);
    pcVar4 = (char *)_malloc(iVar3 + *(int *)(this + 0x10) + 1);
    if (*(char **)(this + 8) != (char *)0x0) {
      _strncpy(pcVar4,*(char **)(this + 8),*(int *)(this + 0x10) + 1);
    }
    _strncpy(pcVar4 + *(int *)(this + 0x10),param_2,iVar3 + 1);
    *(int *)(this + 0x10) = *(int *)(this + 0x10) + iVar3;
    _free(*(undefined4 *)(this + 8));
    iVar3 = *(int *)(this + 0x10);
    iVar5 = 0;
    *(undefined4 *)(this + 0xc) = 0;
    *(char **)(this + 8) = pcVar4;
    if (iVar3 != 0) {
      iVar2 = 0;
      do {
        pcVar1 = pcVar4 + iVar5;
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + *pcVar1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      *(int *)(this + 0xc) = iVar2;
    }
  }
  return;
}

/* Binding__SetName @ 0x97bb01b8 (164 bytes) */
int Binding__SetName(this, param_2)
  unsigned char * this;
  char *param_2;
{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  ClearName(this);
  if ((param_2 != (char *)0x0) && (iVar1 = _strlen(param_2), 0 < iVar1)) {
    *(int *)(this + 0x10) = iVar1;
    pcVar2 = (char *)_malloc(iVar1 + 1);
    *(char **)(this + 8) = pcVar2;
    _strncpy(pcVar2,param_2,*(int *)(this + 0x10) + 1);
    iVar1 = *(int *)(this + 0x10);
    iVar3 = 0;
    *(undefined4 *)(this + 0xc) = 0;
    if (iVar1 != 0) {
      do {
        pcVar2 = (char *)(*(int *)(this + 8) + iVar3);
        iVar3 = iVar3 + 1;
        *(int *)(this + 0xc) = *(int *)(this + 0xc) + (int)*pcVar2;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

/* Binding__SetNameFromArrayName @ 0x97bb025c (332 bytes) */
int Binding__SetNameFromArrayName(this, param_2)
  unsigned char * this;
  char *param_2;
{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  ClearName(this);
  uVar5 = 0;
  if ((param_2 != (char *)0x0) && (iVar2 = _strlen(param_2), 0 < iVar2)) {
    *(int *)(this + 0x10) = iVar2;
    pcVar3 = (char *)_malloc(iVar2 + 1);
    *(char **)(this + 8) = pcVar3;
    _strncpy(pcVar3,param_2,*(int *)(this + 0x10) + 1);
    iVar4 = *(int *)(this + 8);
    iVar2 = *(int *)(this + 0x10);
    if (*(char *)(iVar4 + iVar2 + -1) == ']') {
      bVar1 = false;
      iVar6 = iVar2 + -1;
      do {
        iVar6 = iVar6 + -1;
        if (*(char *)(iVar4 + iVar6) == '[') {
          bVar1 = true;
        }
        if (iVar6 < 0) {
          if (!bVar1) goto LAB_97bb0358;
          break;
        }
      } while (!bVar1);
      uVar5 = _atoi(iVar4 + iVar6 + 1);
      iVar2 = iVar6;
      if (iVar6 < *(int *)(this + 0x10) + 1) {
        do {
          *(undefined1 *)(*(int *)(this + 8) + iVar2) = 0;
          iVar2 = iVar2 + 1;
        } while (iVar2 < *(int *)(this + 0x10) + 1);
      }
      *(int *)(this + 0x10) = iVar6;
      iVar2 = iVar6;
    }
LAB_97bb0358:
    iVar4 = 0;
    *(undefined4 *)(this + 0xc) = 0;
    if (iVar2 != 0) {
      do {
        pcVar3 = (char *)(*(int *)(this + 8) + iVar4);
        iVar4 = iVar4 + 1;
        *(int *)(this + 0xc) = *(int *)(this + 0xc) + (int)*pcVar3;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return uVar5;
}

/* Binding__RemoveNameBackToChar @ 0x97bb03a8 (132 bytes) */
int Binding__RemoveNameBackToChar(this, param_2)
  unsigned char * this;
  int param_2;
{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(this + 0x10);
  bVar2 = false;
  if (-1 < iVar3) {
    do {
      if (*(char *)(*(int *)(this + 8) + iVar3) == param_2) {
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
int Binding__GetHash(this, param_2)
  unsigned char * this;
  uint param_2;
{
  return *(uint *)(this + 0xc) - (*(uint *)(this + 0xc) / param_2) * param_2;
}

/* Binding__IsClientRequest @ 0x97bb0440 (8 bytes) */
int Binding__IsClientRequest(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x2c);
}

/* Binding__SetClientRequest @ 0x97bb0448 (8 bytes) */
int Binding__SetClientRequest(this, param_2)
  unsigned char * this;
  undefined4 param_2;
{
  *(undefined4 *)(this + 0x2c) = param_2;
  return;
}

/* Binding__IsBuiltIn @ 0x97bb0450 (8 bytes) */
int Binding__IsBuiltIn(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x30);
}

/* Binding__SetBuiltIn @ 0x97bb0458 (8 bytes) */
int Binding__SetBuiltIn(this, param_2)
  unsigned char * this;
  undefined4 param_2;
{
  *(undefined4 *)(this + 0x30) = param_2;
  return;
}

