#include "decls.h"

/* orph_97b853f0 @ 0x97b853f0 (8 bytes) */
int orph_97b853f0()
{
  dyld_stub_binding_helper();
  return;
}

/* orph_97b86c5c @ 0x97b86c5c (8 bytes) */
int orph_97b86c5c(param_1, param_2)
  int param_1;
  uint param_2;
{
  return param_1 >> (param_2 & 0x3f);
}

/* orph_97b86c64 @ 0x97b86c64 (8 bytes) */
int orph_97b86c64(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 + param_2;
}

/* orph_97b86c6c @ 0x97b86c6c (8 bytes) */
int orph_97b86c6c(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 - param_2;
}

/* orph_97b86c74 @ 0x97b86c74 (8 bytes) */
int orph_97b86c74(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 * param_2;
}

/* orph_97b86c98 @ 0x97b86c98 (8 bytes) */
int orph_97b86c98(param_1)
  int param_1;
{
  return -param_1;
}

/* orph_97b99088 @ 0x97b99088 (240 bytes) */
int orph_97b99088()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r29);
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d8),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d0),(int)unaff_r30 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe32a4);
  TInfoSinkBase__append(unaff_r29);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  return 0;
}

/* orph_97b99094 @ 0x97b99094 (240 bytes) */
int orph_97b99094()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r29);
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d8),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d0),(int)unaff_r30 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe32a4);
  TInfoSinkBase__append(unaff_r29);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  return 0;
}

/* orph_97b990a0 @ 0x97b990a0 (240 bytes) */
int orph_97b990a0()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r29);
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d8),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d0),(int)unaff_r30 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe32a4);
  TInfoSinkBase__append(unaff_r29);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  return 0;
}

/* orph_97b990ac @ 0x97b990ac (236 bytes) */
int orph_97b990ac()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r29);
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d8),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d0),(int)unaff_r30 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe32a4);
  TInfoSinkBase__append(unaff_r29);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  return 0;
}

/* orph_97b99280 @ 0x97b99280 (248 bytes) */
int orph_97b99280()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  unsigned char * unaff_r27;
  int unaff_r28;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000110;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f644),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f63c),(int)unaff_r29 >> 0x10);
  }
  std__string__string(unaff_r27,&STACKARG(0x130),(unsigned char *)&STACKARG(0x170));
  *(undefined1 *)(in_stack_00000110 + *(int *)(in_stack_00000110 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe2f10);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000110 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000110 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r28 + 0x74) = 1;
  return 0;
}

/* orph_97b9928c @ 0x97b9928c (248 bytes) */
int orph_97b9928c()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  unsigned char * unaff_r27;
  int unaff_r28;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000110;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f644),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f63c),(int)unaff_r29 >> 0x10);
  }
  std__string__string(unaff_r27,&STACKARG(0x130),(unsigned char *)&STACKARG(0x170));
  *(undefined1 *)(in_stack_00000110 + *(int *)(in_stack_00000110 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe2f10);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000110 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000110 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r28 + 0x74) = 1;
  return 0;
}

/* orph_97b99298 @ 0x97b99298 (248 bytes) */
int orph_97b99298()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  unsigned char * unaff_r27;
  int unaff_r28;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000110;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f644),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f63c),(int)unaff_r29 >> 0x10);
  }
  std__string__string(unaff_r27,&STACKARG(0x130),(unsigned char *)&STACKARG(0x170));
  *(undefined1 *)(in_stack_00000110 + *(int *)(in_stack_00000110 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe2f10);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000110 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000110 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r28 + 0x74) = 1;
  return 0;
}

/* orph_97b992a4 @ 0x97b992a4 (244 bytes) */
int orph_97b992a4()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  unsigned char * unaff_r27;
  int unaff_r28;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000110;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f644),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f63c),(int)unaff_r29 >> 0x10);
  }
  std__string__string(unaff_r27,&STACKARG(0x130),(unsigned char *)&STACKARG(0x170));
  *(undefined1 *)(in_stack_00000110 + *(int *)(in_stack_00000110 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe2f10);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000110 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000110 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r28 + 0x74) = 1;
  return 0;
}

/* orph_97b998a8 @ 0x97b998a8 (248 bytes) */
int orph_97b998a8()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efb0),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efa8),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe287c);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b998b4 @ 0x97b998b4 (248 bytes) */
int orph_97b998b4()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efb0),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efa8),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe287c);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b998c0 @ 0x97b998c0 (248 bytes) */
int orph_97b998c0()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efb0),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efa8),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe287c);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b998cc @ 0x97b998cc (244 bytes) */
int orph_97b998cc()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efb0),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efa8),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe287c);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b99ec4 @ 0x97b99ec4 (248 bytes) */
int orph_97b99ec4()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e994),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e98c),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe2260);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b99ed0 @ 0x97b99ed0 (248 bytes) */
int orph_97b99ed0()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e994),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e98c),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe2260);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b99edc @ 0x97b99edc (248 bytes) */
int orph_97b99edc()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e994),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e98c),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe2260);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b99ee8 @ 0x97b99ee8 (244 bytes) */
int orph_97b99ee8()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e994),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e98c),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe2260);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b9a058 @ 0x97b9a058 (248 bytes) */
int orph_97b9a058()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e800),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e7f8),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe20cc);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b9a064 @ 0x97b9a064 (248 bytes) */
int orph_97b9a064()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e800),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e7f8),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe20cc);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b9a070 @ 0x97b9a070 (248 bytes) */
int orph_97b9a070()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e800),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e7f8),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe20cc);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b9a07c @ 0x97b9a07c (244 bytes) */
int orph_97b9a07c()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_r27;
  uint unaff_r29;
  char *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r30);
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e800),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e7f8),(int)unaff_r29 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe20cc);
  TInfoSinkBase__append(unaff_r30);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  TInfoSinkBase__append(unaff_r30);
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b9a850 @ 0x97b9a850 (324 bytes) */
int orph_97b9a850(param_1)
  char *param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint unaff_r28;
  char *pcVar5;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar6;
  int in_stack_000001d0;
  
  TInfoSinkBase__append(param_1);
  pcVar5 = *(char **)(unaff_r30 + 8);
  bVar1 = (unaff_r28 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e018),(int)unaff_r28 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e010),(int)unaff_r28 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x1d0),&STACKARG(0x1e0),(unsigned char *)&STACKARG(0x220));
  *(undefined1 *)(in_stack_000001d0 + *(int *)(in_stack_000001d0 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe18e4);
  TInfoSinkBase__append(pcVar5);
  piVar3 = (int *)(in_stack_000001d0 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_000001d0 + -0xc));
  }
  TInfoSinkBase__append(pcVar5);
  pcVar5 = *(char **)(unaff_r30 + 8);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  *(int *)(unaff_r30 + 0x18) = *(int *)(unaff_r30 + 0x18) + 1;
  return;
}

/* orph_97b9a85c @ 0x97b9a85c (324 bytes) */
int orph_97b9a85c(param_1)
  char *param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint unaff_r28;
  char *pcVar5;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar6;
  int in_stack_000001d0;
  
  TInfoSinkBase__append(param_1);
  pcVar5 = *(char **)(unaff_r30 + 8);
  bVar1 = (unaff_r28 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e018),(int)unaff_r28 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e010),(int)unaff_r28 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x1d0),&STACKARG(0x1e0),(unsigned char *)&STACKARG(0x220));
  *(undefined1 *)(in_stack_000001d0 + *(int *)(in_stack_000001d0 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe18e4);
  TInfoSinkBase__append(pcVar5);
  piVar3 = (int *)(in_stack_000001d0 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_000001d0 + -0xc));
  }
  TInfoSinkBase__append(pcVar5);
  pcVar5 = *(char **)(unaff_r30 + 8);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  *(int *)(unaff_r30 + 0x18) = *(int *)(unaff_r30 + 0x18) + 1;
  return;
}

/* orph_97b9a868 @ 0x97b9a868 (324 bytes) */
int orph_97b9a868(param_1)
  char *param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint unaff_r28;
  char *pcVar5;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar6;
  int in_stack_000001d0;
  
  TInfoSinkBase__append(param_1);
  pcVar5 = *(char **)(unaff_r30 + 8);
  bVar1 = (unaff_r28 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e018),(int)unaff_r28 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e010),(int)unaff_r28 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x1d0),&STACKARG(0x1e0),(unsigned char *)&STACKARG(0x220));
  *(undefined1 *)(in_stack_000001d0 + *(int *)(in_stack_000001d0 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe18e4);
  TInfoSinkBase__append(pcVar5);
  piVar3 = (int *)(in_stack_000001d0 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_000001d0 + -0xc));
  }
  TInfoSinkBase__append(pcVar5);
  pcVar5 = *(char **)(unaff_r30 + 8);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  *(int *)(unaff_r30 + 0x18) = *(int *)(unaff_r30 + 0x18) + 1;
  return;
}

/* orph_97b9a874 @ 0x97b9a874 (320 bytes) */
int orph_97b9a874(param_1)
  char *param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint unaff_r28;
  char *pcVar5;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar6;
  int in_stack_000001d0;
  
  TInfoSinkBase__append(param_1);
  pcVar5 = *(char **)(unaff_r30 + 8);
  bVar1 = (unaff_r28 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e018),(int)unaff_r28 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e010),(int)unaff_r28 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x1d0),&STACKARG(0x1e0),(unsigned char *)&STACKARG(0x220));
  *(undefined1 *)(in_stack_000001d0 + *(int *)(in_stack_000001d0 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffe18e4);
  TInfoSinkBase__append(pcVar5);
  piVar3 = (int *)(in_stack_000001d0 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_000001d0 + -0xc));
  }
  TInfoSinkBase__append(pcVar5);
  pcVar5 = *(char **)(unaff_r30 + 8);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  TInfoSinkBase__append(pcVar5);
  *(int *)(unaff_r30 + 0x18) = *(int *)(unaff_r30 + 0x18) + 1;
  return;
}

/* orph_97bae35c @ 0x97bae35c (236 bytes) */
int orph_97bae35c()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r29);
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4fc),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4f4),(int)unaff_r30 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffcddc8);
  TInfoSinkBase__append(unaff_r29);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  return;
}

/* orph_97bae368 @ 0x97bae368 (236 bytes) */
int orph_97bae368()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r29);
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4fc),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4f4),(int)unaff_r30 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffcddc8);
  TInfoSinkBase__append(unaff_r29);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  return;
}

/* orph_97bae374 @ 0x97bae374 (236 bytes) */
int orph_97bae374()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r29);
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4fc),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4f4),(int)unaff_r30 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffcddc8);
  TInfoSinkBase__append(unaff_r29);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  return;
}

/* orph_97bae380 @ 0x97bae380 (232 bytes) */
int orph_97bae380()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  int in_stack_00000040;
  
  TInfoSinkBase__append(unaff_r29);
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4fc),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4f4),(int)unaff_r30 >> 0x10);
  }
  std__string__string((unsigned char *)&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  *(undefined1 *)(in_stack_00000040 + *(int *)(in_stack_00000040 + -0xc)) =
       **(undefined1 **)(unaff_r31 + 0xffcddc8);
  TInfoSinkBase__append(unaff_r29);
  piVar3 = (int *)(in_stack_00000040 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(in_stack_00000040 + -0xc));
  }
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  TInfoSinkBase__append(unaff_r29);
  return;
}

/* orph_97bd3c20 @ 0x97bd3c20 (8 bytes) */
int orph_97bd3c20(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  _InterpreterTextureSamplerSampleTexelRECTFromLevel(param_1,param_2,0);
  return;
}

/* orph_97c08028 @ 0x97c08028 (8 bytes) */
int orph_97c08028(param_1)
  undefined4 param_1;
{
  _BitSetNextSetBit(param_1,0xffffffff);
  return;
}

/* orph_97c102ec @ 0x97c102ec (8 bytes) */
int orph_97c102ec(param_1, param_2)
  int param_1;
  int param_2;
{
  return param_1 - param_2;
}

/* orph_97c10924 @ 0x97c10924 (8 bytes) */
int orph_97c10924(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  uint uVar7;
  
  if (param_2 < 1) {
    if (param_1 != 0) {
      _glpDCBFree();
    }
    uVar3 = 0;
  }
  else {
    if (param_1 == 0) {
      uVar3 = _glpDCBAlloc(param_2);
      return uVar3;
    }
    uVar7 = (uint)*(byte *)(param_1 + -1);
    pvVar5 = _realloc((void *)(param_1 - uVar7),param_2 + 0x3fU & 0xffffffe0);
    uVar3 = 0;
    if (pvVar5 != (void *)0x0) {
      uVar3 = (int)pvVar5 + 0x20U & 0xffffffe0;
      uVar2 = uVar3 - (int)pvVar5 & 0xff;
      if (uVar2 != uVar7) {
        iVar4 = param_2 + 3 >> 2;
        if (uVar2 < uVar7) {
          iVar6 = 0;
          if (0 < iVar4) {
            do {
              iVar1 = iVar6 * 4;
              iVar6 = iVar6 + 1;
              *(undefined4 *)(iVar1 + uVar3) = *(undefined4 *)((int)pvVar5 + iVar1 + uVar7);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        else {
          iVar6 = iVar4 + -1;
          if (-1 < iVar6) {
            do {
              iVar1 = iVar6 * 4;
              iVar6 = iVar6 + -1;
              *(undefined4 *)(iVar1 + uVar3) = *(undefined4 *)((int)pvVar5 + iVar1 + uVar7);
              iVar4 = iVar4 + -1;
            } while (iVar4 != 0);
          }
        }
        *(char *)(uVar3 - 1) = (char)(uVar3 - (int)pvVar5);
      }
    }
  }
  return uVar3;
}

/* orph_97c1992c @ 0x97c1992c (8 bytes) */
int orph_97c1992c(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  int param_3;
  int param_4;
  unsigned char param_5;
  unsigned char * param_6;
{
  bool bVar1;
  uchar uVar2;
  uchar *puVar3;
  uchar *puVar4;
  unsigned char uVar5;
  uint uVar6;
  uchar *puVar7;
  unsigned char * ptVar8;
  int iVar9;
  undefined4 uVar10;
  unsigned char new_value;
  unsigned char new_value_00;
  uchar *puVar11;
  unsigned char * ptVar12;
  int iStack_80;
  int iStack_7c;
  undefined4 uStack_78;
  uchar *puStack_70;
  uchar uStack_6c;
  uchar uStack_6b;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  int iStack_4c;
  void *apvStack_48 [2];
  
  apvStack_48[0] = (void *)(param_5 + 0x20);
  if (param_1 != 1) {
    return 3;
  }
  if (((param_2 == 6) && (param_3 == 0x474e5543)) && (param_4 == 0x432b2b00)) {
    new_value = *(unsigned char *)(param_5 - 0xc);
    new_value_00 = *(unsigned char *)(param_5 - 0x18);
    bVar1 = new_value == 0;
    goto LAB_97c19c74;
  }
  puVar3 = (uchar *)__Unwind_GetLanguageSpecificData(param_6);
  if (puVar3 == (uchar *)0x0) {
    return 8;
  }
  new_value = 0;
  puVar4 = (uchar *)parse_lsda_header(param_6,puVar3,(unsigned char *)&iStack_80);
  puVar11 = (uchar *)0x0;
  new_value_00 = 0;
  uStack_78 = base_of_encoded_value(uStack_6c,param_6);
  uVar5 = __Unwind_GetIP(param_6);
  if (puVar4 < puStack_70) {
    do {
      uVar2 = uStack_6b;
      uVar6 = base_of_encoded_value(uStack_6b,(unsigned char *)0x0);
      puVar4 = (uchar *)read_encoded_value_with_base(uVar2,uVar6,puVar4,&uStack_60);
      uVar2 = uStack_6b;
      uVar6 = base_of_encoded_value(uStack_6b,(unsigned char *)0x0);
      puVar4 = (uchar *)read_encoded_value_with_base(uVar2,uVar6,puVar4,&uStack_5c);
      uVar2 = uStack_6b;
      uVar6 = base_of_encoded_value(uStack_6b,(unsigned char *)0x0);
      puVar4 = (uchar *)read_encoded_value_with_base(uVar2,uVar6,puVar4,&uStack_58);
      puVar7 = (uchar *)read_uleb128(puVar4,&uStack_54);
      puVar4 = puStack_70;
      if ((iStack_80 + uStack_60 <= uVar5 - 1) &&
         (puVar4 = puVar7, uVar5 - 1 < iStack_80 + uStack_60 + uStack_5c)) {
        if (uStack_58 != 0) {
          new_value = iStack_7c + uStack_58;
        }
        if (uStack_54 != 0) {
          puVar11 = puStack_70 + (uStack_54 - 1);
        }
        if (new_value == 0) {
          return 8;
        }
        uVar6 = 2;
        if (puVar11 == (uchar *)0x0) goto LAB_97c19c1c;
        bVar1 = false;
        if ((((param_2 & 8) == 0) && (param_3 == 0x474e5543)) && (param_4 == 0x432b2b00)) {
          ptVar12 = *(unsigned char **)(param_5 - 0x30);
        }
        else {
          ptVar12 = (unsigned char *)0x0;
        }
        goto LAB_97c19b58;
      }
    } while (puVar4 < puStack_70);
  }
  uVar6 = (param_2 ^ 8) >> 3 & 1;
LAB_97c19c0c:
  if (uVar6 == 0) {
    return 8;
  }
LAB_97c19c1c:
  bVar1 = uVar6 == 1;
  if ((param_2 & 1) != 0) {
    if (uVar6 != 2) {
      if ((param_3 == 0x474e5543) && (param_4 == 0x432b2b00)) {
        *(unsigned char *)(param_5 - 0xc) = new_value;
        *(unsigned char *)(param_5 - 0x18) = new_value_00;
        *(uchar **)(param_5 - 0x14) = puVar11;
        *(uchar **)(param_5 - 0x10) = puVar3;
        *(void **)(param_5 - 8) = apvStack_48[0];
      }
      return 6;
    }
    return 8;
  }
LAB_97c19c74:
  if (bVar1) {
    ___cxa_begin_catch(param_5);
    __cxxabiv1____terminate(*(unsigned char **)(param_5 - 0x24));
  }
  if ((int)new_value_00 < 0) {
    parse_lsda_header(param_6,*(uchar **)(param_5 - 0x10),(unsigned char *)&iStack_80);
    uVar10 = base_of_encoded_value(uStack_6c,param_6);
    *(undefined4 *)(param_5 - 0xc) = uVar10;
  }
  __Unwind_SetGR(param_6,3,param_5);
  __Unwind_SetGR(param_6,4,new_value_00);
  __Unwind_SetIP(param_6,new_value);
  return 7;
LAB_97c19b58:
  puVar4 = (uchar *)read_sleb128(puVar11,(int *)&uStack_50);
  read_sleb128(puVar4,&iStack_4c);
  if (uStack_50 == 0) {
    bVar1 = true;
  }
  else {
    if (0 < (int)uStack_50) {
      ptVar8 = (unsigned char *)get_ttype_entry((unsigned char *)&iStack_80,uStack_50);
      uVar6 = param_2 & 8;
      if (ptVar8 == (unsigned char *)0x0) goto joined_r0x97c19bd8;
      if ((ptVar12 == (unsigned char *)0x0) ||
         (iVar9 = get_adjusted_ptr(ptVar8,ptVar12,apvStack_48), iVar9 == 0)) goto LAB_97c19bdc;
LAB_97c19bf0:
      uVar6 = 3;
      new_value_00 = uStack_50;
      goto LAB_97c19c1c;
    }
    if (ptVar12 != (unsigned char *)0x0) {
      uVar6 = check_exception_spec((unsigned char *)&iStack_80,ptVar12,apvStack_48[0],uStack_50);
joined_r0x97c19bd8:
      if (uVar6 == 0) goto LAB_97c19bf0;
    }
  }
LAB_97c19bdc:
  if (iStack_4c == 0) goto LAB_97c19bfc;
  puVar11 = puVar4 + iStack_4c;
  goto LAB_97c19b58;
LAB_97c19bfc:
  uVar6 = 2;
  if (!bVar1) {
    uVar6 = 0;
    goto LAB_97c19c0c;
  }
  goto LAB_97c19c1c;
}

/* orph_97c1ddfc @ 0x97c1ddfc (20 bytes) */
int orph_97c1ddfc()
{
  int in_stack_00000000;
  
                    
                    
  (**(code **)(in_stack_00000000 + 8))();
  return;
}

