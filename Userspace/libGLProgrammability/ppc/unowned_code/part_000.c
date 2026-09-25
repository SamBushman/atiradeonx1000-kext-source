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
  char *unaff_r28;
  void *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8f99c));
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d8),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d0),(int)unaff_r30 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe32a4);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8f9e0));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8de24));
  return 0;
}

/* orph_97b990a0 @ 0x97b990a0 (240 bytes) */
int orph_97b990a0()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r28;
  void *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8f9b8));
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d8),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d0),(int)unaff_r30 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe32a4);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8f9e0));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8de24));
  return 0;
}

/* orph_97b990ac @ 0x97b990ac (236 bytes) */
int orph_97b990ac()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r28;
  void *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8f9c8));
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d8),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8f9d0),(int)unaff_r30 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe32a4);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8f9e0));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x8de24));
  return 0;
}

/* orph_97b9928c @ 0x97b9928c (248 bytes) */
int orph_97b9928c()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  void *unaff_r27;
  int unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8f610));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f644),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f63c),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(unaff_r27,&STACKARG(0x130),(unsigned char *)&STACKARG(0x170));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -0xc)] = **(char **)(unaff_r31 + 0xffe2f10);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8f64c));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,&STACKARG(0x40));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8da90));
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
  void *unaff_r27;
  int unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8f624));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f644),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f63c),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(unaff_r27,&STACKARG(0x130),(unsigned char *)&STACKARG(0x170));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -0xc)] = **(char **)(unaff_r31 + 0xffe2f10);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8f64c));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,&STACKARG(0x40));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8da90));
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
  void *unaff_r27;
  int unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8f634));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f644),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x130),(char *)(unaff_r31 + 0x8f63c),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(unaff_r27,&STACKARG(0x130),(unsigned char *)&STACKARG(0x170));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -0xc)] = **(char **)(unaff_r31 + 0xffe2f10);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x110)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8f64c));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,&STACKARG(0x40));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8da90));
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
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8ef74));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efb0),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efa8),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe287c);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8efb8));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8d3fc));
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
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8ef90));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efb0),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efa8),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe287c);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8efb8));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8d3fc));
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
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8efa0));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efb0),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8efa8),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe287c);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8efb8));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8d3fc));
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
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e958));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e994),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e98c),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe2260);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e99c));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8cde0));
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
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e974));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e994),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e98c),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe2260);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e99c));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8cde0));
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
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e984));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e994),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e98c),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe2260);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e99c));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8cde0));
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
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e7c4));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e800),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e7f8),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe20cc);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e808));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8cc4c));
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
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e7e0));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e800),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e7f8),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe20cc);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e808));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8cc4c));
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
  char *unaff_r28;
  uint unaff_r29;
  void *unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e7f0));
  bVar1 = (unaff_r29 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e800),(int)unaff_r29 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x8e7f8),(int)unaff_r29 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffe20cc);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8e808));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r30,(char *)(unaff_r31 + 0x8cc4c));
  *(undefined4 *)(unaff_r27 + 0x74) = 1;
  return 0;
}

/* orph_97b9a85c @ 0x97b9a85c (324 bytes) */
int orph_97b9a85c(param_1)
  void *param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r26;
  char *unaff_r27;
  uint unaff_r28;
  void *pvVar5;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar6;
  
  __ZN13TInfoSinkBase6appendEPKc(param_1,(char *)(unaff_r31 + 0x8dfe4));
  pvVar5 = *(void **)(unaff_r30 + 8);
  bVar1 = (unaff_r28 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e018),(int)unaff_r28 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e010),(int)unaff_r28 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x1d0),&STACKARG(0x1e0),(unsigned char *)&STACKARG(0x220));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -0xc)] = **(char **)(unaff_r31 + 0xffe18e4);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e020));
  pvVar5 = *(void **)(unaff_r30 + 8);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9e0));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,unaff_r27);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9e4));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,unaff_r26);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9ec));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,&STACKARG(0x40));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8c464));
  *(int *)(unaff_r30 + 0x18) = *(int *)(unaff_r30 + 0x18) + 1;
  return;
}

/* orph_97b9a868 @ 0x97b9a868 (324 bytes) */
int orph_97b9a868(param_1)
  void *param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r26;
  char *unaff_r27;
  uint unaff_r28;
  void *pvVar5;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar6;
  
  __ZN13TInfoSinkBase6appendEPKc(param_1,(char *)(unaff_r31 + 0x8dff8));
  pvVar5 = *(void **)(unaff_r30 + 8);
  bVar1 = (unaff_r28 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e018),(int)unaff_r28 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e010),(int)unaff_r28 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x1d0),&STACKARG(0x1e0),(unsigned char *)&STACKARG(0x220));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -0xc)] = **(char **)(unaff_r31 + 0xffe18e4);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e020));
  pvVar5 = *(void **)(unaff_r30 + 8);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9e0));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,unaff_r27);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9e4));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,unaff_r26);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9ec));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,&STACKARG(0x40));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8c464));
  *(int *)(unaff_r30 + 0x18) = *(int *)(unaff_r30 + 0x18) + 1;
  return;
}

/* orph_97b9a874 @ 0x97b9a874 (320 bytes) */
int orph_97b9a874(param_1)
  void *param_1;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r26;
  char *unaff_r27;
  uint unaff_r28;
  void *pvVar5;
  int unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar6;
  
  __ZN13TInfoSinkBase6appendEPKc(param_1,(char *)(unaff_r31 + 0x8e008));
  pvVar5 = *(void **)(unaff_r30 + 8);
  bVar1 = (unaff_r28 & 0xffff) == 0;
  bVar6 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e018),(int)unaff_r28 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x1e0),(char *)(unaff_r31 + 0x8e010),(int)unaff_r28 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x1d0),&STACKARG(0x1e0),(unsigned char *)&STACKARG(0x220));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -0xc)] = **(char **)(unaff_r31 + 0xffe18e4);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar6 = 2;
    }
  } while (!(bool)(bVar6 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x1d0)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e020));
  pvVar5 = *(void **)(unaff_r30 + 8);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9e0));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,unaff_r27);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9e4));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,unaff_r26);
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8e9ec));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,&STACKARG(0x40));
  __ZN13TInfoSinkBase6appendEPKc(pvVar5,(char *)(unaff_r31 + 0x8c464));
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
  char *unaff_r28;
  void *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x7a4c0));
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4fc),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4f4),(int)unaff_r30 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffcddc8);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x7a504));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x78948));
  return;
}

/* orph_97bae368 @ 0x97bae368 (236 bytes) */
int orph_97bae368()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r28;
  void *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x7a4c8));
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4fc),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4f4),(int)unaff_r30 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffcddc8);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x7a504));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x78948));
  return;
}

/* orph_97bae374 @ 0x97bae374 (236 bytes) */
int orph_97bae374()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r28;
  void *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x7a4dc));
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4fc),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4f4),(int)unaff_r30 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffcddc8);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x7a504));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x78948));
  return;
}

/* orph_97bae380 @ 0x97bae380 (232 bytes) */
int orph_97bae380()
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char *unaff_r28;
  void *unaff_r29;
  uint unaff_r30;
  int unaff_r31;
  char in_RESERVE;
  byte bVar5;
  
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x7a4ec));
  bVar1 = (unaff_r30 & 0xffff) == 0;
  bVar5 = bVar1 << 1;
  if (bVar1) {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4fc),(int)unaff_r30 >> 0x10);
  }
  else {
    _sprintf(&STACKARG(0x50),(char *)(unaff_r31 + 0x7a4f4),(int)unaff_r30 >> 0x10);
  }
  __ZNSsC1EPKcRKSaIcE(&STACKARG(0x40),&STACKARG(0x50),(unsigned char *)&STACKARG(0x90));
  (*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40))[*(int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc)] = **(char **)(unaff_r31 + 0xffcddc8);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)));
  piVar3 = (int *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar2;
      bVar5 = 2;
    }
  } while (!(bool)(bVar5 >> 1 & 1));
  if (iVar4 < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)((*(char * *)(*(unsigned int *)__builtin_frame_address(0) + 0x40)) + -0xc));
  }
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x7a504));
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,unaff_r28);
  __ZN13TInfoSinkBase6appendEPKc(unaff_r29,(char *)(unaff_r31 + 0x78948));
  return;
}

/* orph_97bd3c20 @ 0x97bd3c20 (8 bytes) */
int orph_97bd3c20(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  _InterpreterTextureSamplerSampleTexelRECTFromLevel(param_1,param_2,0,param_4,param_5);
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

/* orph_97c1ddfc @ 0x97c1ddfc (20 bytes) */
int orph_97c1ddfc()
{
  
                    
                    
  (**(code **)((*(int *)(*(unsigned int *)__builtin_frame_address(0) + 0x0)) + 8))();
  return;
}

