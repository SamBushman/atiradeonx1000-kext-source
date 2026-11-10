#include "decls.h"

/* _glVertex4f_CompExec @ 0xa2370 (96 bytes) */
void _glVertex4f_CompExec(undefined4 param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  ((void (*)())_glVertex4f_Comp)(param_1,fparam_1,fparam_2,fparam_3,fparam_4);
  _glVertex4f_Exec(param_1);
  return;
}

/* _glVertex4fv_Comp @ 0xa23d0 (104 bytes) */
int _glVertex4fv_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glVertex4_ListExec_00110410,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_2;
    puVar1[1] = param_2[1];
    puVar1[2] = param_2[2];
    puVar1[3] = param_2[3];
  }
  return puVar1;
}

/* _glVertex4fv_CompExec @ 0xa2438 (56 bytes) */
void _glVertex4fv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex4fv_Comp)(param_1,param_2);
  _glVertex4fv_Exec(param_1,param_2);
  return;
}

/* _glVertex2i_Comp @ 0xa2470 (144 bytes) */
int _glVertex2i_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex2_ListExec_00110418,8);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex2i_CompExec @ 0xa2500 (64 bytes) */
void _glVertex2i_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertex2i_Comp)(param_1,param_2,param_3);
  _glVertex2i_Exec(param_1,param_2,param_3);
  return;
}

/* _glVertex2iv_Exec @ 0xa2540 (152 bytes) */
void _glVertex2iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,param_2,in_r5,in_r6,in_r7,*(int *)(param_1 + 0x4858),0x43300000,
            (double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(param_1 + 0x20),(double)*(float *)(param_1 + 0x24));
  return;
}

/* _glVertex2iv_Comp @ 0xa25d8 (148 bytes) */
int _glVertex2iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex2_ListExec_00110418,8);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex2iv_CompExec @ 0xa266c (56 bytes) */
void _glVertex2iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex2iv_Comp)(param_1,param_2);
  ((int (*)())_glVertex2iv_Exec)(param_1,param_2);
  return;
}

/* _glVertex3i_Exec @ 0xa26a4 (160 bytes) */
void _glVertex3i_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  undefined4 in_r7;
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,param_2,param_3,param_4,in_r7,*(int *)(param_1 + 0x4858),param_4 ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(param_1 + 0x24));
  return;
}

/* _glVertex3i_Comp @ 0xa2744 (176 bytes) */
int _glVertex3i_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex3_ListExec_00110414,0xc);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex3i_CompExec @ 0xa27f4 (72 bytes) */
void _glVertex3i_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glVertex3i_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glVertex3i_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glVertex3iv_Exec @ 0xa283c (172 bytes) */
void _glVertex3iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,param_2,in_r5,in_r6,in_r7,*(int *)(param_1 + 0x4858),param_2[1] ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(param_1 + 0x24));
  return;
}

/* _glVertex3iv_Comp @ 0xa28e8 (180 bytes) */
int _glVertex3iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex3_ListExec_00110414,0xc);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex3iv_CompExec @ 0xa299c (56 bytes) */
void _glVertex3iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex3iv_Comp)(param_1,param_2);
  ((int (*)())_glVertex3iv_Exec)(param_1,param_2);
  return;
}

/* _glVertex4i_Exec @ 0xa29d4 (172 bytes) */
void _glVertex4i_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,param_2,param_3,param_4,param_5,*(int *)(param_1 + 0x4858),param_4 ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58));
  return;
}

/* _glVertex4i_Comp @ 0xa2a80 (208 bytes) */
int _glVertex4i_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex4_ListExec_00110410,0x10);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1);
    pfVar2[3] = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex4i_CompExec @ 0xa2b50 (80 bytes) */
void _glVertex4i_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glVertex4i_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glVertex4i_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glVertex4iv_Exec @ 0xa2ba0 (188 bytes) */
void _glVertex4iv_Exec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,param_2,in_r5,in_r6,in_r7,*(int *)(param_1 + 0x4858),param_2[2] ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) - DOUBLE_00108d58))
  ;
  return;
}

/* _glVertex4iv_Comp @ 0xa2c5c (212 bytes) */
int _glVertex4iv_Comp(param_1, param_2)
  undefined4 param_1;
  uint *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex4_ListExec_00110410,0x10);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_2[1] ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_2[2] ^ 0x80000000) - dVar1);
    pfVar2[3] = (float)((double)CONCAT44(0x43300000,param_2[3] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex4iv_CompExec @ 0xa2d30 (56 bytes) */
void _glVertex4iv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex4iv_Comp)(param_1,param_2);
  ((int (*)())_glVertex4iv_Exec)(param_1,param_2);
  return;
}

/* _glVertex2s_Exec @ 0xa2d68 (144 bytes) */
void _glVertex2s_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) -
                                   DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(param_1 + 0x20),(double)*(float *)(param_1 + 0x24));
  return;
}

/* _glVertex2s_Comp @ 0xa2df8 (144 bytes) */
int _glVertex2s_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex2_ListExec_00110418,8);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex2s_CompExec @ 0xa2e88 (64 bytes) */
void _glVertex2s_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glVertex2s_Comp)(param_1,param_2,param_3);
  ((int (*)())_glVertex2s_Exec)(param_1,param_2,param_3);
  return;
}

/* _glVertex2sv_Exec @ 0xa2ec8 (152 bytes) */
void _glVertex2sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,param_2,in_r5,in_r6,in_r7,*(int *)(param_1 + 0x4858),0x43300000,
            (double)(float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) -
                           DOUBLE_00108d58),(double)*(float *)(param_1 + 0x20),
            (double)*(float *)(param_1 + 0x24));
  return;
}

/* _glVertex2sv_Comp @ 0xa2f60 (148 bytes) */
int _glVertex2sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex2_ListExec_00110418,8);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex2sv_CompExec @ 0xa2ff4 (56 bytes) */
void _glVertex2sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex2sv_Comp)(param_1,param_2);
  ((int (*)())_glVertex2sv_Exec)(param_1,param_2);
  return;
}

/* _glVertex3s_Exec @ 0xa302c (160 bytes) */
void _glVertex3s_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  undefined4 in_r7;
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,param_2,param_3,param_4,in_r7,*(int *)(param_1 + 0x4858),param_4 ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58),
            (double)*(float *)(param_1 + 0x24));
  return;
}

/* _glVertex3s_Comp @ 0xa30cc (176 bytes) */
int _glVertex3s_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex3_ListExec_00110414,0xc);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex3s_CompExec @ 0xa317c (72 bytes) */
void _glVertex3s_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glVertex3s_Comp)(param_1,param_2,param_3,param_4);
  ((int (*)())_glVertex3s_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glVertex3sv_Exec @ 0xa31c4 (172 bytes) */
void _glVertex3sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,param_2,in_r5,in_r6,in_r7,*(int *)(param_1 + 0x4858),
            (int)param_2[1] ^ 0x80000000U,
            (double)(float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000U) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) -
                           DOUBLE_00108d58),(double)*(float *)(param_1 + 0x24));
  return;
}

/* _glVertex3sv_Comp @ 0xa3270 (180 bytes) */
int _glVertex3sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex3_ListExec_00110414,0xc);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex3sv_CompExec @ 0xa3324 (56 bytes) */
void _glVertex3sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex3sv_Comp)(param_1,param_2);
  ((int (*)())_glVertex3sv_Exec)(param_1,param_2);
  return;
}

/* _glVertex4s_Exec @ 0xa335c (172 bytes) */
void _glVertex4s_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,param_2,param_3,param_4,param_5,*(int *)(param_1 + 0x4858),param_4 ^ 0x80000000,
            (double)(float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - DOUBLE_00108d58));
  return;
}

/* _glVertex4s_Comp @ 0xa3408 (208 bytes) */
int _glVertex4s_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex4_ListExec_00110410,0x10);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,param_3 ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - dVar1);
    pfVar2[3] = (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex4s_CompExec @ 0xa34d8 (80 bytes) */
void _glVertex4s_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glVertex4s_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glVertex4s_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glVertex4sv_Exec @ 0xa3528 (188 bytes) */
void _glVertex4sv_Exec(param_1, param_2)
  int param_1;
  short *param_2;
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  code *pcVar1;
  
  pcVar1 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar1 = *(code **)(param_1 + 0x28);
  }
  (*pcVar1)(param_1,param_2,in_r5,in_r6,in_r7,*(int *)(param_1 + 0x4858),
            (int)param_2[2] ^ 0x80000000U,
            (double)(float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000U) -
                           DOUBLE_00108d58),
            (double)(float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) -
                           DOUBLE_00108d58));
  return;
}

/* _glVertex4sv_Comp @ 0xa35e4 (212 bytes) */
int _glVertex4sv_Comp(param_1, param_2)
  undefined4 param_1;
  short *param_2;
{
  double dVar1;
  float *pfVar2;
  
  pfVar2 = (float *)_gleAddListItem(param_1,PTR__glVertex4_ListExec_00110410,0x10);
  dVar1 = DOUBLE_00108d58;
  if (pfVar2 != (float *)0x0) {
    *pfVar2 = (float)((double)CONCAT44(0x43300000,(int)*param_2 ^ 0x80000000) - DOUBLE_00108d58);
    pfVar2[1] = (float)((double)CONCAT44(0x43300000,(int)param_2[1] ^ 0x80000000) - dVar1);
    pfVar2[2] = (float)((double)CONCAT44(0x43300000,(int)param_2[2] ^ 0x80000000) - dVar1);
    pfVar2[3] = (float)((double)CONCAT44(0x43300000,(int)param_2[3] ^ 0x80000000) - dVar1);
  }
  return pfVar2;
}

/* _glVertex4sv_CompExec @ 0xa36b8 (56 bytes) */
void _glVertex4sv_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glVertex4sv_Comp)(param_1,param_2);
  ((int (*)())_glVertex4sv_Exec)(param_1,param_2);
  return;
}

/* _glElementPointerAPPLE_Exec @ 0xa36f0 (528 bytes) */
void _glElementPointerAPPLE_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  
  iVar3 = *(int *)(param_1 + 0x4a60);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (*(int *)(iVar3 + 0xd8) != param_3) {
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
    }
    *(int *)(iVar3 + 0xd8) = param_3;
    iVar8 = *(int *)(iVar3 + 0x35c);
    iVar5 = *(int *)(iVar3 + 0x37c);
    *(undefined4 *)(iVar3 + 0x350) = *(undefined4 *)(iVar3 + 0x350);
    *(uint *)(iVar3 + 0x354) = *(uint *)(iVar3 + 0x354) | 0x800000;
    if (iVar8 != iVar5) {
      if ((iVar5 != 0) &&
         (iVar4 = *(int *)(iVar5 + 8) + -1, *(int *)(iVar5 + 8) = iVar4, iVar4 == 0)) {
        _gleFreeBufferObject(param_1,iVar5);
      }
      if (iVar8 == 0) {
        iVar5 = 0;
        *(undefined4 *)(iVar3 + 0x338) = *(undefined4 *)(iVar3 + 0x338);
        *(uint *)(iVar3 + 0x33c) = *(uint *)(iVar3 + 0x33c) & 0xff7fffff;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar6 = (undefined4 *)(iVar3 + 0x3fc);
          do {
            *puVar6 = 0;
            iVar5 = iVar5 + 1;
            puVar6 = puVar6 + 0x23;
          } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      else {
        *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
        *(undefined4 *)(iVar3 + 0x338) = *(undefined4 *)(iVar3 + 0x338);
        *(uint *)(iVar3 + 0x33c) = *(uint *)(iVar3 + 0x33c) | 0x800000;
        iVar5 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar7 = (undefined4 *)(iVar3 + 0x3fc);
          puVar6 = (undefined4 *)(iVar8 + 0x10);
          do {
            uVar2 = *puVar6;
            iVar5 = iVar5 + 1;
            puVar6 = puVar6 + 1;
            *puVar7 = uVar2;
            puVar7 = puVar7 + 0x23;
          } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      *(int *)(iVar3 + 0x37c) = iVar8;
      *(undefined4 *)(iVar3 + 0x350) = *(undefined4 *)(iVar3 + 0x350);
      *(uint *)(iVar3 + 0x354) = *(uint *)(iVar3 + 0x354) | 0x10;
    }
    if (iVar8 != 0) {
      param_3 = param_3 + *(int *)(iVar8 + 0x30);
    }
    *(int *)(param_1 + 0x4914) = param_3;
    if (*(uint *)(iVar3 + 0xec) == (param_2 & 0xf)) {
      return;
    }
    if (param_2 != 0x1403) {
      if (param_2 < 0x1404) {
        bVar1 = param_2 == 0x1401;
      }
      else {
        bVar1 = param_2 == 0x1405;
      }
      if (!bVar1) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar2 = 0x500;
        goto LAB_000a38b8;
      }
    }
    *(uint *)(iVar3 + 0xec) = param_2 & 0xf;
    *(undefined1 *)(iVar3 + 0xe4) = 1;
    *(short *)(iVar3 + 0xe0) = (short)param_2;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
    *(undefined4 *)(param_1 + 0x4894) = 0;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
LAB_000a38b8:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
  }
  return;
}

/* _glNormalPointer_Exec @ 0xa3900 (708 bytes) */
void _glNormalPointer_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  code *param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  
  iVar5 = *(int *)(param_1 + 0x4a60);
  uVar7 = param_3 << 7 | (uint)param_2 & 0xf;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    *(undefined4 *)(iVar5 + 0x350) = *(undefined4 *)(iVar5 + 0x350);
    *(uint *)(iVar5 + 0x354) = *(uint *)(iVar5 + 0x354) | 0x20000;
    if (*(int *)(iVar5 + 0x48) != param_4) {
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
    }
    *(int *)(iVar5 + 0x48) = param_4;
    iVar8 = *(int *)(iVar5 + 0x358);
    iVar3 = *(int *)(iVar5 + 0x364);
    if (iVar8 != iVar3) {
      if ((iVar3 != 0) &&
         (iVar2 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar2, iVar2 == 0)) {
        _gleFreeBufferObject(param_1,iVar3);
      }
      if (iVar8 == 0) {
        iVar3 = 0;
        *(undefined4 *)(iVar5 + 0x338) = *(undefined4 *)(iVar5 + 0x338);
        *(uint *)(iVar5 + 0x33c) = *(uint *)(iVar5 + 0x33c) & 0xfffdffff;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar4 = (undefined4 *)(iVar5 + 0x3e4);
          do {
            *puVar4 = 0;
            iVar3 = iVar3 + 1;
            puVar4 = puVar4 + 0x23;
          } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      else {
        *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
        *(undefined4 *)(iVar5 + 0x338) = *(undefined4 *)(iVar5 + 0x338);
        *(uint *)(iVar5 + 0x33c) = *(uint *)(iVar5 + 0x33c) | 0x20000;
        iVar3 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar6 = (undefined4 *)(iVar5 + 0x3e4);
          puVar4 = (undefined4 *)(iVar8 + 0x10);
          do {
            uVar1 = *puVar4;
            iVar3 = iVar3 + 1;
            puVar4 = puVar4 + 1;
            *puVar6 = uVar1;
            puVar6 = puVar6 + 0x23;
          } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      *(int *)(iVar5 + 0x364) = iVar8;
      *(undefined4 *)(iVar5 + 0x350) = *(undefined4 *)(iVar5 + 0x350);
      *(uint *)(iVar5 + 0x354) = *(uint *)(iVar5 + 0x354) | 0x10;
    }
    if (iVar8 != 0) {
      param_4 = param_4 + *(int *)(iVar8 + 0x30);
    }
    *(int *)(param_1 + 0x48fc) = param_4;
    if (*(uint *)(iVar5 + 0x5c) == uVar7) {
      return;
    }
    if (-1 < param_3) {
      switch((int)param_2) {
      case 0x1400:
        iVar3 = 1;
        param_2 = (code *)0x9400;
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x500;
        goto LAB_000a3b64;
      case 0x1402:
        iVar3 = 2;
        param_2 = (code *)0x9402;
        break;
      case 0x1404:
        param_2 = _gleUpdatePolyMode;
      case 0x1406:
        iVar3 = 4;
        break;
      case 0x140a:
        iVar3 = 8;
      }
      *(short *)(iVar5 + 0x50) = (short)param_2;
      *(char *)(iVar5 + 0x54) = (char)iVar3;
      if (param_3 < 1) {
        param_3 = iVar3 * 3;
      }
      *(uint *)(iVar5 + 0x5c) = uVar7;
      *(int *)(iVar5 + 0x4c) = param_3;
      *(undefined4 *)(param_1 + 0x488c) = 0;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
      *(undefined4 *)(param_1 + 0x4890) = 0;
      *(undefined4 *)(param_1 + 0x4894) = 0;
      if (*(int *)(param_1 + 0x5408) != 0) {
        return;
      }
      uVar7 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar7 | *(uint *)(param_1 + 0x4684) & ~uVar7) + 0xc) =
           PTR__glArrayElement_Exec_00110454;
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
LAB_000a3b64:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glSecondaryColorPointer_Exec @ 0xa3bf0 (720 bytes) */
void _glSecondaryColorPointer_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
  int param_5;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  
  iVar5 = *(int *)(param_1 + 0x4a60);
  uVar7 = param_4 << 7 | param_3 & 0xf | (param_2 & 3) << 4;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    *(undefined4 *)(iVar5 + 0x350) = *(undefined4 *)(iVar5 + 0x350);
    *(uint *)(iVar5 + 0x354) = *(uint *)(iVar5 + 0x354) | 0x100000;
    if (*(int *)(iVar5 + 0x90) != param_5) {
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
    }
    *(int *)(iVar5 + 0x90) = param_5;
    iVar8 = *(int *)(iVar5 + 0x358);
    iVar3 = *(int *)(iVar5 + 0x370);
    if (iVar8 != iVar3) {
      if ((iVar3 != 0) &&
         (iVar2 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar2, iVar2 == 0)) {
        _gleFreeBufferObject(param_1,iVar3);
      }
      if (iVar8 == 0) {
        iVar3 = 0;
        *(undefined4 *)(iVar5 + 0x338) = *(undefined4 *)(iVar5 + 0x338);
        *(uint *)(iVar5 + 0x33c) = *(uint *)(iVar5 + 0x33c) & 0xffefffff;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar4 = (undefined4 *)(iVar5 + 0x3f0);
          do {
            *puVar4 = 0;
            iVar3 = iVar3 + 1;
            puVar4 = puVar4 + 0x23;
          } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      else {
        *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
        *(undefined4 *)(iVar5 + 0x338) = *(undefined4 *)(iVar5 + 0x338);
        *(uint *)(iVar5 + 0x33c) = *(uint *)(iVar5 + 0x33c) | 0x100000;
        iVar3 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar6 = (undefined4 *)(iVar5 + 0x3f0);
          puVar4 = (undefined4 *)(iVar8 + 0x10);
          do {
            uVar1 = *puVar4;
            iVar3 = iVar3 + 1;
            puVar4 = puVar4 + 1;
            *puVar6 = uVar1;
            puVar6 = puVar6 + 0x23;
          } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      *(int *)(iVar5 + 0x370) = iVar8;
      *(undefined4 *)(iVar5 + 0x350) = *(undefined4 *)(iVar5 + 0x350);
      *(uint *)(iVar5 + 0x354) = *(uint *)(iVar5 + 0x354) | 0x10;
    }
    if (iVar8 != 0) {
      param_5 = param_5 + *(int *)(iVar8 + 0x30);
    }
    *(int *)(param_1 + 0x4908) = param_5;
    if (*(uint *)(iVar5 + 0xa4) == uVar7) {
      return;
    }
    if ((param_2 == 3) && (-1 < param_4)) {
      switch(param_3) {
      case 0x1400:
      case 0x1401:
        param_3 = param_3 | 0x8000;
        iVar3 = 1;
        break;
      case 0x1402:
      case 0x1403:
        param_3 = param_3 | 0x8000;
        iVar3 = 2;
        break;
      case 0x1404:
      case 0x1405:
        param_3 = param_3 | 0x8000;
      case 0x1406:
        iVar3 = 4;
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x500;
        goto LAB_000a3e5c;
      case 0x140a:
        iVar3 = 8;
      }
      *(short *)(iVar5 + 0x98) = (short)param_3;
      *(char *)(iVar5 + 0x9c) = (char)iVar3;
      *(undefined2 *)(iVar5 + 0x9a) = 3;
      if (param_4 < 1) {
        param_4 = iVar3 * 3;
      }
      *(uint *)(iVar5 + 0xa4) = uVar7;
      *(int *)(iVar5 + 0x94) = param_4;
      *(undefined4 *)(param_1 + 0x488c) = 0;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
      *(undefined4 *)(param_1 + 0x4890) = 0;
      *(undefined4 *)(param_1 + 0x4894) = 0;
      if (*(int *)(param_1 + 0x5408) != 0) {
        return;
      }
      uVar7 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar7 | *(uint *)(param_1 + 0x4684) & ~uVar7) + 0xc) =
           PTR__glArrayElement_Exec_00110454;
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
LAB_000a3e5c:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glFogCoordPointer_Exec @ 0xa3eec (648 bytes) */
void _glFogCoordPointer_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  
  iVar5 = *(int *)(param_1 + 0x4a60);
  uVar7 = param_3 << 7 | param_2 & 0xf;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    *(undefined4 *)(iVar5 + 0x350) = *(undefined4 *)(iVar5 + 0x350);
    *(uint *)(iVar5 + 0x354) = *(uint *)(iVar5 + 0x354) | 0x80000;
    if (*(int *)(iVar5 + 0x78) != param_4) {
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
    }
    *(int *)(iVar5 + 0x78) = param_4;
    iVar8 = *(int *)(iVar5 + 0x358);
    iVar3 = *(int *)(iVar5 + 0x36c);
    if (iVar8 != iVar3) {
      if ((iVar3 != 0) &&
         (iVar2 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar2, iVar2 == 0)) {
        _gleFreeBufferObject(param_1,iVar3);
      }
      if (iVar8 == 0) {
        iVar3 = 0;
        *(undefined4 *)(iVar5 + 0x338) = *(undefined4 *)(iVar5 + 0x338);
        *(uint *)(iVar5 + 0x33c) = *(uint *)(iVar5 + 0x33c) & 0xfff7ffff;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar4 = (undefined4 *)(iVar5 + 0x3ec);
          do {
            *puVar4 = 0;
            iVar3 = iVar3 + 1;
            puVar4 = puVar4 + 0x23;
          } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      else {
        *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
        *(undefined4 *)(iVar5 + 0x338) = *(undefined4 *)(iVar5 + 0x338);
        *(uint *)(iVar5 + 0x33c) = *(uint *)(iVar5 + 0x33c) | 0x80000;
        iVar3 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar6 = (undefined4 *)(iVar5 + 0x3ec);
          puVar4 = (undefined4 *)(iVar8 + 0x10);
          do {
            uVar1 = *puVar4;
            iVar3 = iVar3 + 1;
            puVar4 = puVar4 + 1;
            *puVar6 = uVar1;
            puVar6 = puVar6 + 0x23;
          } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      *(int *)(iVar5 + 0x36c) = iVar8;
      *(undefined4 *)(iVar5 + 0x350) = *(undefined4 *)(iVar5 + 0x350);
      *(uint *)(iVar5 + 0x354) = *(uint *)(iVar5 + 0x354) | 0x10;
    }
    if (iVar8 != 0) {
      param_4 = param_4 + *(int *)(iVar8 + 0x30);
    }
    *(int *)(param_1 + 0x4904) = param_4;
    if (*(uint *)(iVar5 + 0x8c) == uVar7) {
      return;
    }
    if (-1 < param_3) {
      if (param_2 == 0x1406) {
        iVar3 = 4;
      }
      else {
        if (param_2 != 0x140a) {
          if (*(int *)(param_1 + 0x7574) != 0) {
            return;
          }
          uVar1 = 0x500;
          goto LAB_000a40e8;
        }
        iVar3 = 8;
      }
      *(short *)(iVar5 + 0x80) = (short)param_2;
      *(char *)(iVar5 + 0x84) = (char)iVar3;
      if (param_3 < 1) {
        param_3 = iVar3;
      }
      *(uint *)(iVar5 + 0x8c) = uVar7;
      *(int *)(iVar5 + 0x7c) = param_3;
      *(undefined4 *)(param_1 + 0x488c) = 0;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
      *(undefined4 *)(param_1 + 0x4890) = 0;
      *(undefined4 *)(param_1 + 0x4894) = 0;
      if (*(int *)(param_1 + 0x5408) != 0) {
        return;
      }
      uVar7 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar7 | *(uint *)(param_1 + 0x4684) & ~uVar7) + 0xc) =
           PTR__glArrayElement_Exec_00110454;
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
LAB_000a40e8:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glWeightPointerARB_Exec @ 0xa4174 (724 bytes) */
void _glWeightPointerARB_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
  int param_5;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  
  iVar5 = *(int *)(param_1 + 0x4a60);
  uVar7 = param_4 << 7 | param_3 & 0xf | (param_2 & 3) << 4;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    *(undefined4 *)(iVar5 + 0x350) = *(undefined4 *)(iVar5 + 0x350);
    *(uint *)(iVar5 + 0x354) = *(uint *)(iVar5 + 0x354) | 0x200000;
    if (*(int *)(iVar5 + 0xa8) != param_5) {
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
    }
    *(int *)(iVar5 + 0xa8) = param_5;
    iVar8 = *(int *)(iVar5 + 0x358);
    iVar3 = *(int *)(iVar5 + 0x374);
    if (iVar8 != iVar3) {
      if ((iVar3 != 0) &&
         (iVar2 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar2, iVar2 == 0)) {
        _gleFreeBufferObject(param_1,iVar3);
      }
      if (iVar8 == 0) {
        iVar3 = 0;
        *(undefined4 *)(iVar5 + 0x338) = *(undefined4 *)(iVar5 + 0x338);
        *(uint *)(iVar5 + 0x33c) = *(uint *)(iVar5 + 0x33c) & 0xffdfffff;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar4 = (undefined4 *)(iVar5 + 0x3f4);
          do {
            *puVar4 = 0;
            iVar3 = iVar3 + 1;
            puVar4 = puVar4 + 0x23;
          } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      else {
        *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
        *(undefined4 *)(iVar5 + 0x338) = *(undefined4 *)(iVar5 + 0x338);
        *(uint *)(iVar5 + 0x33c) = *(uint *)(iVar5 + 0x33c) | 0x200000;
        iVar3 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          puVar6 = (undefined4 *)(iVar5 + 0x3f4);
          puVar4 = (undefined4 *)(iVar8 + 0x10);
          do {
            uVar1 = *puVar4;
            iVar3 = iVar3 + 1;
            puVar4 = puVar4 + 1;
            *puVar6 = uVar1;
            puVar6 = puVar6 + 0x23;
          } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      *(int *)(iVar5 + 0x374) = iVar8;
      *(undefined4 *)(iVar5 + 0x350) = *(undefined4 *)(iVar5 + 0x350);
      *(uint *)(iVar5 + 0x354) = *(uint *)(iVar5 + 0x354) | 0x10;
    }
    if (iVar8 != 0) {
      param_5 = param_5 + *(int *)(iVar8 + 0x30);
    }
    *(int *)(param_1 + 0x490c) = param_5;
    if (*(uint *)(iVar5 + 0xbc) == uVar7) {
      return;
    }
    if ((param_2 - 1 < 4) && (-1 < param_4)) {
      switch(param_3) {
      case 0x1400:
      case 0x1401:
        param_3 = param_3 | 0x8000;
        iVar3 = 1;
        break;
      case 0x1402:
      case 0x1403:
        param_3 = param_3 | 0x8000;
        iVar3 = 2;
        break;
      case 0x1404:
      case 0x1405:
        param_3 = param_3 | 0x8000;
      case 0x1406:
        iVar3 = 4;
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x500;
        goto LAB_000a43e4;
      case 0x140a:
        iVar3 = 8;
      }
      *(short *)(iVar5 + 0xb0) = (short)param_3;
      *(char *)(iVar5 + 0xb4) = (char)iVar3;
      *(short *)(iVar5 + 0xb2) = (short)param_2;
      if (param_4 < 1) {
        param_4 = param_2 * iVar3;
      }
      *(uint *)(iVar5 + 0xbc) = uVar7;
      *(int *)(iVar5 + 0xac) = param_4;
      *(undefined4 *)(param_1 + 0x488c) = 0;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
      *(undefined4 *)(param_1 + 0x4890) = 0;
      *(undefined4 *)(param_1 + 0x4894) = 0;
      if (*(int *)(param_1 + 0x5408) != 0) {
        return;
      }
      uVar7 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar7 | *(uint *)(param_1 + 0x4684) & ~uVar7) + 0xc) =
           PTR__glArrayElement_Exec_00110454;
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
LAB_000a43e4:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glEdgeFlagPointer_Exec @ 0xa4474 (564 bytes) */
void _glEdgeFlagPointer_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  
  iVar3 = *(int *)(param_1 + 0x4a60);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_2) {
      *(undefined4 *)(iVar3 + 0x350) = *(undefined4 *)(iVar3 + 0x350);
      *(uint *)(iVar3 + 0x354) = *(uint *)(iVar3 + 0x354) | 0x400000;
      if (*(int *)(iVar3 + 0xc0) != param_3) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
      }
      *(int *)(iVar3 + 0xc0) = param_3;
      iVar8 = *(int *)(iVar3 + 0x358);
      iVar5 = *(int *)(iVar3 + 0x378);
      if (iVar8 != iVar5) {
        if ((iVar5 != 0) &&
           (iVar4 = *(int *)(iVar5 + 8) + -1, *(int *)(iVar5 + 8) = iVar4, iVar4 == 0)) {
          _gleFreeBufferObject(param_1,iVar5);
        }
        if (iVar8 == 0) {
          iVar5 = 0;
          *(undefined4 *)(iVar3 + 0x338) = *(undefined4 *)(iVar3 + 0x338);
          *(uint *)(iVar3 + 0x33c) = *(uint *)(iVar3 + 0x33c) & 0xffbfffff;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            puVar6 = (undefined4 *)(iVar3 + 0x3f8);
            do {
              *puVar6 = 0;
              iVar5 = iVar5 + 1;
              puVar6 = puVar6 + 0x23;
            } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
        else {
          *(int *)(iVar8 + 8) = *(int *)(iVar8 + 8) + 1;
          *(undefined4 *)(iVar3 + 0x338) = *(undefined4 *)(iVar3 + 0x338);
          *(uint *)(iVar3 + 0x33c) = *(uint *)(iVar3 + 0x33c) | 0x400000;
          iVar5 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            puVar7 = (undefined4 *)(iVar3 + 0x3f8);
            puVar6 = (undefined4 *)(iVar8 + 0x10);
            do {
              uVar2 = *puVar6;
              iVar5 = iVar5 + 1;
              puVar6 = puVar6 + 1;
              *puVar7 = uVar2;
              puVar7 = puVar7 + 0x23;
            } while (iVar5 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
        *(int *)(iVar3 + 0x378) = iVar8;
        *(undefined4 *)(iVar3 + 0x350) = *(undefined4 *)(iVar3 + 0x350);
        *(uint *)(iVar3 + 0x354) = *(uint *)(iVar3 + 0x354) | 0x10;
      }
      if (iVar8 != 0) {
        param_3 = param_3 + *(int *)(iVar8 + 0x30);
      }
      *(int *)(param_1 + 0x4910) = param_3;
      if (param_2 < 1) {
        param_2 = 1;
      }
      if (param_2 == *(int *)(iVar3 + 0xc4)) {
        return;
      }
      *(int *)(iVar3 + 0xc4) = param_2;
      *(undefined4 *)(param_1 + 0x488c) = 0;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
      *(undefined4 *)(param_1 + 0x4890) = 0;
      *(undefined4 *)(param_1 + 0x4894) = 0;
      if (*(int *)(param_1 + 0x5408) != 0) {
        return;
      }
      uVar1 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
      *(undefined **)
       ((*(uint *)(param_1 + 0x4680) & uVar1 | *(uint *)(param_1 + 0x4684) & ~uVar1) + 0xc) =
           PTR__glArrayElement_Exec_00110454;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glVertexAttribPointerARB_Exec @ 0xa46a8 (892 bytes) */
void _glVertexAttribPointerARB_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  int param_6;
  int param_7;
{
  int iVar1;
  undefined4 uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  
  iVar9 = *(int *)(param_1 + 0x4a60);
  uVar11 = param_6 << 7 | param_4 & 0xf | (param_3 & 3) << 4 | (param_5 & 1) << 6;
  iVar14 = iVar9 + 0x10;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
LAB_000a49a4:
    *(undefined4 *)(param_1 + 0x7574) = uVar2;
    return;
  }
  iVar12 = param_2 + 0x10;
  if (((0xf < param_2) || (3 < param_3 - 1)) || (param_6 < 0)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
    goto LAB_000a49a4;
  }
  uVar4 = 1 << (param_2 & 0x3f);
  *(uint *)(iVar9 + 0x350) = *(uint *)(iVar9 + 0x350) | uVar4;
  *(undefined4 *)(iVar9 + 0x354) = *(undefined4 *)(iVar9 + 0x354);
  iVar5 = iVar14 + iVar12 * 0x18;
  if (*(int *)(iVar5 + 0x20) != param_7) {
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
  }
  iVar1 = iVar12 * 4;
  *(int *)(iVar5 + 0x20) = param_7;
  iVar7 = *(int *)(iVar1 + iVar14 + 0x350);
  iVar13 = *(int *)(iVar9 + 0x358);
  if (iVar13 != iVar7) {
    if ((iVar7 != 0) && (iVar6 = *(int *)(iVar7 + 8) + -1, *(int *)(iVar7 + 8) = iVar6, iVar6 == 0))
    {
      _gleFreeBufferObject(param_1,iVar7);
    }
    if (iVar13 == 0) {
      *(uint *)(iVar9 + 0x338) = *(uint *)(iVar9 + 0x338) & ~uVar4;
      *(undefined4 *)(iVar9 + 0x33c) = *(undefined4 *)(iVar9 + 0x33c);
      iVar7 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        puVar8 = (undefined4 *)(iVar12 * 4 + iVar14 + 0x3d0);
        do {
          *puVar8 = 0;
          iVar7 = iVar7 + 1;
          puVar8 = puVar8 + 0x23;
        } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
    }
    else {
      *(int *)(iVar13 + 8) = *(int *)(iVar13 + 8) + 1;
      *(uint *)(iVar9 + 0x338) = *(uint *)(iVar9 + 0x338) | uVar4;
      *(undefined4 *)(iVar9 + 0x33c) = *(undefined4 *)(iVar9 + 0x33c);
      iVar7 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        puVar8 = (undefined4 *)(iVar13 + 0x10);
        puVar10 = (undefined4 *)(iVar12 * 4 + iVar14 + 0x3d0);
        do {
          uVar2 = *puVar8;
          iVar7 = iVar7 + 1;
          puVar8 = puVar8 + 1;
          *puVar10 = uVar2;
          puVar10 = puVar10 + 0x23;
        } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
    }
    uVar2 = *(undefined4 *)(iVar9 + 0x350);
    uVar4 = *(uint *)(iVar9 + 0x354);
    *(int *)(iVar1 + iVar14 + 0x350) = iVar13;
    *(undefined4 *)(iVar9 + 0x350) = uVar2;
    *(uint *)(iVar9 + 0x354) = uVar4 | 0x10;
  }
  if (iVar13 != 0) {
    param_7 = param_7 + *(int *)(iVar13 + 0x30);
  }
  *(int *)(iVar1 + param_1 + 0x48f8) = param_7;
  if (*(uint *)(iVar5 + 0x34) == uVar11) {
    return;
  }
  switch(param_4) {
  case 0x1400:
  case 0x1401:
    iVar9 = 1;
    break;
  case 0x1402:
  case 0x1403:
    iVar9 = 2;
    break;
  case 0x1404:
  case 0x1405:
    iVar9 = 4;
    break;
  case 0x1406:
    iVar9 = 4;
    goto LAB_000a4974;
  default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x500;
    goto LAB_000a49a4;
  case 0x140a:
    iVar9 = 8;
LAB_000a4974:
    param_5 = 0;
  }
  *(char *)(iVar5 + 0x2c) = (char)iVar9;
  uVar3 = (ushort)param_4;
  if (param_5 != 0) {
    uVar3 = uVar3 | 0x8000;
  }
  *(ushort *)(iVar5 + 0x28) = uVar3;
  *(short *)(iVar5 + 0x2a) = (short)param_3;
  if (param_6 < 1) {
    param_6 = param_3 * iVar9;
  }
  *(uint *)(iVar5 + 0x34) = uVar11;
  *(int *)(iVar5 + 0x24) = param_6;
  *(undefined4 *)(param_1 + 0x488c) = 0;
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
  *(undefined4 *)(param_1 + 0x4890) = 0;
  *(undefined4 *)(param_1 + 0x4894) = 0;
  if (*(int *)(param_1 + 0x5408) == 0) {
    uVar11 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
    *(undefined **)
     ((*(uint *)(param_1 + 0x4680) & uVar11 | *(uint *)(param_1 + 0x4684) & ~uVar11) + 0xc) =
         PTR__glArrayElement_Exec_00110454;
  }
  return;
}

/* _glIndexPointer_Exec @ 0xa4a50 (308 bytes) */
void _glIndexPointer_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (-1 < param_3) {
      switch(param_2) {
      case 0x1401:
        uVar1 = 1;
        break;
      case 0x1402:
        uVar1 = 2;
        break;
      default:
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        uVar1 = 0x500;
        goto LAB_000a4b28;
      case 0x1404:
      case 0x1406:
        uVar1 = 4;
        break;
      case 0x140a:
        uVar1 = 8;
      }
      *(undefined4 *)(param_1 + 0x48e0) = param_4;
      *(short *)(param_1 + 0x48e8) = (short)param_2;
      if (param_3 < 1) {
        *(undefined4 *)(param_1 + 0x48e4) = uVar1;
      }
      else {
        *(int *)(param_1 + 0x48e4) = param_3;
      }
      iVar3 = *(int *)(param_1 + 0x48f4);
      iVar4 = *(int *)(*(int *)(param_1 + 0x4a60) + 0x358);
      if (iVar4 == iVar3) {
        return;
      }
      if ((iVar3 != 0) &&
         (iVar2 = *(int *)(iVar3 + 8) + -1, *(int *)(iVar3 + 8) = iVar2, iVar2 == 0)) {
        _gleFreeBufferObject(param_1,iVar3);
      }
      if (iVar4 != 0) {
        *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 1;
      }
      *(int *)(param_1 + 0x48f4) = iVar4;
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
LAB_000a4b28:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glInterleavedArrays_Exec @ 0xa4bac (1236 bytes) */
void _glInterleavedArrays_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  
  bVar1 = false;
  bVar2 = false;
  bVar3 = false;
  uVar10 = 0x1406;
  uVar8 = 0;
  uVar9 = 0;
  iVar7 = 0;
  iVar6 = 0;
  iVar11 = 0;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar8 = 0x502;
LAB_000a4f70:
    *(undefined4 *)(param_1 + 0x7574) = uVar8;
    return;
  }
  switch(param_2) {
  case 0x2a20:
    iVar4 = _gleTypeSize(param_1,0x1406);
    iVar4 = iVar4 << 1;
    break;
  case 0x2a21:
    iVar4 = _gleTypeSize(param_1,0x1406);
    iVar4 = iVar4 * 3;
    goto LAB_000a4ef0;
  case 0x2a22:
    bVar2 = true;
    iVar11 = _gleTypeSize(param_1,0x1401);
    iVar11 = iVar11 * 4;
    iVar4 = _gleTypeSize(param_1,0x1406);
    uVar9 = 4;
    uVar10 = 0x1401;
    iVar4 = iVar11 + iVar4 * 2;
    break;
  case 0x2a23:
    iVar11 = _gleTypeSize(param_1,0x1401);
    iVar11 = iVar11 << 2;
    iVar4 = _gleTypeSize(param_1,0x1406);
    goto LAB_000a4df4;
  case 0x2a24:
    iVar11 = _gleTypeSize(param_1,0x1406);
    iVar11 = iVar11 * 3;
    goto LAB_000a4e38;
  case 0x2a25:
    bVar3 = true;
    iVar11 = _gleTypeSize(param_1,0x1406);
    iVar11 = iVar11 * 3;
    iVar4 = _gleTypeSize(param_1,0x1406);
    goto LAB_000a4d80;
  case 0x2a26:
    iVar6 = _gleTypeSize(param_1,0x1406);
    iVar6 = iVar6 * 4;
    iVar11 = _gleTypeSize(param_1,0x1406);
    iVar11 = iVar6 + iVar11 * 3;
    iVar4 = _gleTypeSize(param_1,0x1406);
    goto LAB_000a4ee0;
  case 0x2a27:
    bVar1 = true;
    iVar11 = _gleTypeSize(param_1,0x1406);
    iVar11 = iVar11 << 1;
    iVar4 = _gleTypeSize(param_1,0x1406);
    uVar8 = 2;
LAB_000a4d80:
    iVar4 = iVar11 + iVar4 * 3;
    goto LAB_000a4ef0;
  case 0x2a28:
    iVar11 = _gleTypeSize(param_1,0x1406);
    iVar11 = iVar11 * 4;
    iVar4 = _gleTypeSize(param_1,0x1406);
    iVar4 = iVar11 + iVar4 * 4;
    goto LAB_000a4f58;
  case 0x2a29:
    bVar1 = true;
    iVar7 = _gleTypeSize(param_1,0x1406);
    iVar7 = iVar7 * 2;
    iVar11 = _gleTypeSize(param_1,0x1401);
    iVar11 = iVar7 + iVar11 * 4;
    iVar4 = _gleTypeSize(param_1,0x1406);
    uVar8 = 2;
LAB_000a4df4:
    bVar2 = true;
    iVar4 = iVar11 + iVar4 * 3;
    uVar9 = 4;
    uVar10 = 0x1401;
LAB_000a4ef0:
    uVar5 = 3;
    goto LAB_000a4f78;
  case 0x2a2a:
    bVar1 = true;
    iVar7 = _gleTypeSize(param_1,0x1406);
    iVar7 = iVar7 * 2;
    iVar11 = _gleTypeSize(param_1,0x1406);
    uVar8 = 2;
    iVar11 = iVar7 + iVar11 * 3;
LAB_000a4e38:
    bVar2 = true;
    iVar4 = _gleTypeSize(param_1,0x1406);
    iVar4 = iVar11 + iVar4 * 3;
    uVar9 = 3;
    uVar10 = 0x1406;
    goto LAB_000a4ef0;
  case 0x2a2b:
    bVar1 = true;
    iVar6 = _gleTypeSize(param_1,0x1406);
    iVar6 = iVar6 * 2;
    iVar11 = _gleTypeSize(param_1,0x1406);
    uVar8 = 2;
    iVar11 = iVar6 + iVar11 * 3;
    iVar4 = _gleTypeSize(param_1,0x1406);
    iVar4 = iVar11 + iVar4 * 3;
    goto LAB_000a4eec;
  case 0x2a2c:
    bVar1 = true;
    iVar7 = _gleTypeSize(param_1,0x1406);
    iVar7 = iVar7 * 2;
    iVar6 = _gleTypeSize(param_1,0x1406);
    iVar6 = iVar7 + iVar6 * 4;
    iVar11 = _gleTypeSize(param_1,0x1406);
    uVar8 = 2;
    iVar11 = iVar6 + iVar11 * 3;
    iVar4 = _gleTypeSize(param_1,0x1406);
LAB_000a4ee0:
    bVar2 = true;
    iVar4 = iVar11 + iVar4 * 3;
    uVar9 = 4;
LAB_000a4eec:
    uVar10 = 0x1406;
    bVar3 = true;
    goto LAB_000a4ef0;
  case 0x2a2d:
    iVar7 = _gleTypeSize(param_1,0x1406);
    iVar7 = iVar7 * 4;
    iVar6 = _gleTypeSize(param_1,0x1406);
    iVar6 = iVar7 + iVar6 * 4;
    iVar11 = _gleTypeSize(param_1,0x1406);
    iVar11 = iVar6 + iVar11 * 3;
    iVar4 = _gleTypeSize(param_1,0x1406);
    bVar2 = true;
    iVar4 = iVar11 + iVar4 * 4;
    uVar9 = 4;
    bVar3 = true;
LAB_000a4f58:
    uVar10 = 0x1406;
    uVar8 = 4;
    bVar1 = true;
    uVar5 = 4;
    goto LAB_000a4f78;
  default:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar8 = 0x500;
    goto LAB_000a4f70;
  }
  uVar5 = 2;
LAB_000a4f78:
  if (param_3 == 0) {
    param_3 = iVar4;
  }
  _glDisableClientState_Exec(param_1,0x8079);
  _glDisableClientState_Exec(param_1,0x8077);
  if (bVar1) {
    _glEnableClientState_Exec(param_1,0x8078);
    _glTexCoordPointer_Exec(param_1,uVar8,0x1406,param_3,param_4);
  }
  else {
    _glDisableClientState_Exec(param_1,0x8078);
  }
  if (bVar2) {
    _glEnableClientState_Exec(param_1,0x8076);
    _glColorPointer_Exec(param_1,uVar9,uVar10,param_3,param_4 + iVar7);
  }
  else {
    _glDisableClientState_Exec(param_1,0x8076);
  }
  if (bVar3) {
    _glEnableClientState_Exec(param_1,0x8075);
    ((int (*)())_glNormalPointer_Exec)(param_1,0x1406,param_3,param_4 + iVar6);
  }
  else {
    _glDisableClientState_Exec(param_1,0x8075);
  }
  _glEnableClientState_Exec(param_1,0x8074);
  _glVertexPointer_Exec(param_1,uVar5,0x1406,param_3,param_4 + iVar11);
  return;
}

/* _glArrayElement_ListExec @ 0xa50b8 (772 bytes) */
int _glArrayElement_ListExec(param_1, param_2)
  int param_1;
  char *param_2;
{
  float *pfVar1;
  byte bVar2;
  char cVar3;
  float fVar4;
  undefined4 uVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  code *pcVar10;
  float *pfVar11;
  uint uVar12;
  int iVar13;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
    goto LAB_000a53a0;
  }
  bVar2 = param_2[1];
  pfVar11 = (float *)(param_2 + 0x24);
  if (bVar2 != 0) {
    *(undefined4 *)(param_1 + 0x2b0) = *(undefined4 *)(param_2 + 0x24);
    *(undefined4 *)(param_1 + 0x2b4) = *(undefined4 *)(param_2 + 0x28);
    pfVar11 = (float *)((int)pfVar11 + (uint)bVar2);
    *(undefined4 *)(param_1 + 0x2b8) = *(undefined4 *)(param_2 + 0x2c);
  }
  uVar12 = (uint)(byte)param_2[2];
  if (uVar12 != 0) {
    *(float *)(param_1 + 0x2a0) = *pfVar11;
    *(float *)(param_1 + 0x2a4) = pfVar11[1];
    *(float *)(param_1 + 0x2a8) = pfVar11[2];
    if (uVar12 == 0x10) {
      *(float *)(param_1 + 0x2ac) = pfVar11[3];
    }
    else {
      *(undefined4 *)(param_1 + 0x2ac) = 0x3f800000;
    }
    if (*(char *)(param_1 + 0x4df8) != '\0') {
      (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
    }
    pfVar11 = (float *)((int)pfVar11 + uVar12);
  }
  if ((byte)param_2[3] != 0) {
    fVar4 = *pfVar11;
    pfVar11 = (float *)((int)pfVar11 + (uint)(byte)param_2[3]);
    *(float *)(param_1 + 0x2cc) = fVar4;
  }
  bVar2 = param_2[4];
  if (bVar2 != 0) {
    *(float *)(param_1 + 0x2c0) = *pfVar11;
    *(float *)(param_1 + 0x2c4) = pfVar11[1];
    pfVar1 = pfVar11 + 2;
    pfVar11 = (float *)((int)pfVar11 + (uint)bVar2);
    *(float *)(param_1 + 0x2c8) = *pfVar1;
  }
  uVar12 = (uint)(byte)param_2[5];
  if (uVar12 != 0) {
    if (uVar12 == 0x10) {
      fVar4 = pfVar11[3];
LAB_000a51f4:
      *(float *)(param_1 + 0x2dc) = fVar4;
      *(float *)(param_1 + 0x2d8) = pfVar11[2];
LAB_000a5218:
      *(float *)(param_1 + 0x2d4) = pfVar11[1];
    }
    else {
      if (uVar12 == 0xc) {
        fVar4 = *(float *)(param_1 + 0x20);
        goto LAB_000a51f4;
      }
      if (uVar12 == 8) {
        *(undefined4 *)(param_1 + 0x2d8) = *(undefined4 *)(param_1 + 0x20);
        *(undefined4 *)(param_1 + 0x2dc) = *(undefined4 *)(param_1 + 0x20);
        goto LAB_000a5218;
      }
      uVar5 = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x2d4) = uVar5;
      *(undefined4 *)(param_1 + 0x2dc) = uVar5;
      *(undefined4 *)(param_1 + 0x2d8) = uVar5;
    }
    fVar4 = *pfVar11;
    pfVar11 = (float *)((int)pfVar11 + uVar12);
    *(float *)(param_1 + 0x2d0) = fVar4;
  }
  if ((byte)param_2[6] != 0) {
    cVar3 = *(char *)pfVar11;
    pfVar11 = (float *)((int)pfVar11 + (uint)(byte)param_2[6]);
    *(char *)(param_1 + 0x2ec) = cVar3;
  }
  iVar8 = 0;
  iVar13 = 8;
  pbVar9 = (byte *)(param_2 + 8);
  do {
    uVar12 = (uint)*pbVar9;
    pbVar9 = pbVar9 + 1;
    if (uVar12 != 0) {
      if (uVar12 == 0x10) {
        *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 3;
        fVar4 = pfVar11[3];
LAB_000a52c4:
        iVar7 = iVar8 * 0x10 + param_1;
        *(float *)(iVar7 + 300) = fVar4;
        fVar4 = pfVar11[2];
LAB_000a52cc:
        *(float *)(iVar7 + 0x128) = fVar4;
        fVar4 = pfVar11[1];
      }
      else {
        if (uVar12 == 0xc) {
          fVar4 = *(float *)(param_1 + 0x24);
          *(uint *)(param_1 + 0x486c) = *(uint *)(param_1 + 0x486c) | 1;
          goto LAB_000a52c4;
        }
        if (uVar12 == 8) {
          iVar7 = iVar8 * 0x10 + param_1;
          *(undefined4 *)(iVar7 + 300) = *(undefined4 *)(param_1 + 0x24);
          fVar4 = *(float *)(param_1 + 0x20);
          goto LAB_000a52cc;
        }
        iVar7 = iVar8 * 0x10 + param_1;
        *(undefined4 *)(iVar7 + 300) = *(undefined4 *)(param_1 + 0x24);
        *(undefined4 *)(iVar7 + 0x128) = *(undefined4 *)(param_1 + 0x20);
        fVar4 = *(float *)(param_1 + 0x20);
      }
      *(float *)(iVar7 + 0x124) = fVar4;
      fVar4 = *pfVar11;
      pfVar11 = (float *)((int)pfVar11 + uVar12);
      *(float *)(iVar8 * 0x10 + param_1 + 0x120) = fVar4;
    }
    iVar8 = iVar8 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  cVar3 = *param_2;
  if (cVar3 == '\0') goto LAB_000a53a0;
  pcVar10 = *(code **)(param_1 + 0x4884);
  if (*(int *)(param_1 + 0x4858) == *(int *)(param_1 + 0x485c)) {
    pcVar10 = (code *)PTR__gleFlushAndSubmit_00112050;
  }
  if (cVar3 == '\x10') {
    fVar4 = pfVar11[3];
LAB_000a537c:
    fVar6 = pfVar11[2];
  }
  else {
    if (cVar3 == '\f') {
      fVar4 = *(float *)(param_1 + 0x24);
      goto LAB_000a537c;
    }
    fVar4 = *(float *)(param_1 + 0x24);
    fVar6 = *(float *)(param_1 + 0x20);
  }
  (*((int (*)(int,double,double,double,double))pcVar10))(param_1, (double)*pfVar11, (double)pfVar11[1], (double)fVar6, (double)fVar4);
LAB_000a53a0:
  return *(int *)(param_2 + 0x20) + 0x24;
}

/* _glArrayElement_Comp @ 0xa53bc (340 bytes) */
int _glArrayElement_Comp(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined1 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  int iVar7;
  code *pcVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  short *psVar12;
  undefined1 *puVar13;
  longlong lVar14;
  undefined4 local_b0;
  undefined1 auStack_34 [4];
  
  iVar7 = *(int *)(param_1 + 0x4a60);
  if (*(int *)(param_1 + 0x48dc) != 0x14ff) {
    *(undefined4 *)(param_1 + 0x48dc) = 0x14ff;
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x48d8) = 0;
    *(undefined4 *)(param_1 + 0x4978) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  uVar2 = *(uint *)(iVar7 + 0x330);
  uVar4 = *(uint *)(iVar7 + 0x334);
  piVar11 = &local_b0;
  psVar12 = (short *)(iVar7 + 0x3a);
  iVar9 = 0;
  iVar10 = 0x10;
  do {
    lVar14 = ___ashldi3(0,1,iVar10);
    if ((uVar2 & (uint)((ulonglong)lVar14 >> 0x20)) == 0 && (uVar4 & 0xff7fffff & (uint)lVar14) == 0
       ) {
      *piVar11 = 0;
    }
    else {
      iVar9 = iVar9 + *psVar12 * 4;
      *piVar11 = *psVar12 * 4;
    }
    piVar11 = piVar11 + 1;
    iVar10 = iVar10 + 1;
    psVar12 = psVar12 + 0xc;
  } while ((int)piVar11 <= (int)auStack_34);
  puVar5 = (undefined1 *)_gleAddListItem(param_1,PTR__glArrayElement_ListExec_00110450,iVar9 + 0x24)
  ;
  uVar6 = 0;
  if (puVar5 != (undefined1 *)0x0) {
    *(int *)(puVar5 + 0x20) = iVar9;
    iVar9 = 0x20;
    puVar3 = (undefined1 *)((int)&local_b0 + 3);
    puVar13 = puVar5 + 0x24;
    do {
      uVar1 = *puVar3;
      puVar3 = puVar3 + 4;
      *puVar5 = uVar1;
      puVar5 = puVar5 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    pcVar8 = *(code **)(param_1 + 0x488c);
    if (pcVar8 == (code *)0x0) {
      pcVar8 = (code *)_gleGetVertexToListFunc(param_1);
      *(code **)(param_1 + 0x488c) = pcVar8;
    }
    uVar6 = (*pcVar8)(param_1,iVar7 + 0x30,puVar13,param_2);
  }
  return uVar6;
}

/* _glArrayElement_NoopExec @ 0xa5510 (668 bytes) */
void _glArrayElement_NoopExec(int param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
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
  undefined4 in_LR;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (*(char *)(param_1 + 0x759c) == '\0') {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000a5774;
  }
  iVar6 = *(int *)(param_1 + 0x50ac);
  if (iVar6 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000a5758:
    if (*(char *)(param_1 + 0x759d) != '\0') {
      ((void (*)())_glArrayElement_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                 fparam_8,(double)CONCAT44(in_LR,(*(unsigned int *)((unsigned char *)&(fparam_9) + 4))),fparam_10,fparam_11,fparam_12,
                 fparam_13);
      return;
    }
  }
  else {
    iVar5 = *(int *)(param_1 + 0x744c);
    piVar8 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar5 != 0) && (*(int *)(iVar5 + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar5 + 0x10,in_r5,in_r6,in_r7,in_r8,iVar6,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a5644:
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
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000a5644;
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
    if (bVar1) goto LAB_000a5758;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000a573c:
      iVar6 = 0x13;
      do {
        *piVar8 = 0;
        piVar8 = piVar8 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      goto LAB_000a5758;
    }
    uVar7 = (**(code **)(param_1 + 0x4788))
                      (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar8);
    if ((((uVar7 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar7 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar7 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000a573c;
    if ((uVar7 & 4) == 0) {
      uVar7 = uVar7 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar7);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000a573c;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_000a5774:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glArrayElement_Exec @ 0xa57ac (3652 bytes) */
void _glArrayElement_Exec(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  double in_stack_ffffff98;
  double in_stack_ffffffa0;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  
  iVar3 = *(int *)(param_1 + 0x4a60);
  iVar9 = iVar3 + 0x10;
  if ((((*(char *)(param_1 + 0x7580) != '\0') || (*(char *)(param_1 + 0x4664) != '\0')) ||
      (*(char *)(param_1 + 0x30aa) == '\0')) || (*(char *)(param_1 + 0x30ab) == '\0')) {
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x4894);
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      *(undefined4 *)(param_1 + 0x48dc) = 0x14ff;
      UNRECOVERED_JUMPTABLE = (code *)_gleGetVertexElemFunc(param_1);
      *(code **)(param_1 + 0x4894) = UNRECOVERED_JUMPTABLE;
      if (*(int *)(param_1 + 0x5408) == 0) {
        uVar7 = -(uint)(*(int *)(*(uint *)(param_1 + 0x4684) + 0xc) == 0);
        *(code **)((*(uint *)(param_1 + 0x4680) & uVar7 | *(uint *)(param_1 + 0x4684) & ~uVar7) +
                  0xc) = UNRECOVERED_JUMPTABLE;
      }
    }
                    
                    
    (*UNRECOVERED_JUMPTABLE)(param_1,param_2);
    return;
  }
  *(undefined4 *)(param_1 + 0x4894) = 0;
  uVar7 = *(uint *)(iVar3 + 0x334);
  if ((uVar7 & 0x400000) != 0) {
    fparam_1 = (double)_glEdgeFlag_Exec(param_1,(uint)*(byte *)(*(int *)(iVar3 + 0xc0) +
                                                               param_2 * *(int *)(iVar3 + 0xc4)));
  }
  uVar10 = uVar7 & 0xff000000;
  bVar1 = uVar10 == 0;
  if (!bVar1) {
    uVar8 = 0;
    do {
      uVar6 = 0x1000000 << (uVar8 & 0x3f);
      if ((uVar10 & uVar6) != 0) {
        uVar2 = *(ushort *)(iVar9 + 0xea);
        uVar10 = uVar10 & ~uVar6;
        iVar4 = uVar8 + 0x84c0;
        iVar5 = *(int *)(iVar9 + 0xe0) + param_2 * *(int *)(iVar9 + 0xe4);
        if (uVar2 == 2) {
          uVar2 = *(ushort *)(iVar9 + 0xe8);
          if (uVar2 == 0x1404) {
            fparam_1 = (double)_glMultiTexCoord2iv_Exec(param_1,iVar4,iVar5);
          }
          else if (uVar2 < 0x1405) {
            bVar1 = uVar10 == 0;
            if (uVar2 != 0x1402) goto LAB_000a5ab8;
            fparam_1 = (double)_glMultiTexCoord2sv_Exec(param_1,iVar4,iVar5);
          }
          else if (uVar2 == 0x1406) {
            fparam_1 = (double)_glMultiTexCoord2fv_Exec(param_1,iVar4,iVar5);
          }
          else {
            bVar1 = uVar10 == 0;
            if (uVar2 != 0x140a) goto LAB_000a5ab8;
            fparam_1 = (double)_glMultiTexCoord2dv_Exec(param_1,iVar4,iVar5);
          }
        }
        else if (uVar2 < 3) {
          bVar1 = uVar10 == 0;
          if (uVar2 != 1) goto LAB_000a5ab8;
          uVar2 = *(ushort *)(iVar9 + 0xe8);
          if (uVar2 == 0x1404) {
            fparam_1 = (double)_glMultiTexCoord1iv_Exec(param_1,iVar4,iVar5);
          }
          else if (uVar2 < 0x1405) {
            bVar1 = uVar10 == 0;
            if (uVar2 != 0x1402) goto LAB_000a5ab8;
            fparam_1 = (double)_glMultiTexCoord1sv_Exec(param_1,iVar4,iVar5);
          }
          else if (uVar2 == 0x1406) {
            fparam_1 = (double)_glMultiTexCoord1fv_Exec(param_1,iVar4,iVar5);
          }
          else {
            bVar1 = uVar10 == 0;
            if (uVar2 != 0x140a) goto LAB_000a5ab8;
            fparam_1 = (double)_glMultiTexCoord1dv_Exec(param_1,iVar4,iVar5);
          }
        }
        else if (uVar2 == 3) {
          uVar2 = *(ushort *)(iVar9 + 0xe8);
          if (uVar2 == 0x1404) {
            fparam_1 = (double)_glMultiTexCoord3iv_Exec(param_1,iVar4,iVar5);
          }
          else if (uVar2 < 0x1405) {
            bVar1 = uVar10 == 0;
            if (uVar2 != 0x1402) goto LAB_000a5ab8;
            fparam_1 = (double)_glMultiTexCoord3sv_Exec(param_1,iVar4,iVar5);
          }
          else if (uVar2 == 0x1406) {
            fparam_1 = (double)_glMultiTexCoord3fv_Exec(param_1,iVar4,iVar5);
          }
          else {
            bVar1 = uVar10 == 0;
            if (uVar2 != 0x140a) goto LAB_000a5ab8;
            fparam_1 = (double)_glMultiTexCoord3dv_Exec(param_1,iVar4,iVar5);
          }
        }
        else {
          bVar1 = uVar10 == 0;
          if (uVar2 != 4) goto LAB_000a5ab8;
          uVar2 = *(ushort *)(iVar9 + 0xe8);
          if (uVar2 == 0x1404) {
            fparam_1 = (double)_glMultiTexCoord4iv_Exec(param_1,iVar4,iVar5);
          }
          else if (uVar2 < 0x1405) {
            bVar1 = uVar10 == 0;
            if (uVar2 != 0x1402) goto LAB_000a5ab8;
            fparam_1 = (double)_glMultiTexCoord4sv_Exec(param_1,iVar4,iVar5);
          }
          else if (uVar2 == 0x1406) {
            fparam_1 = (double)_glMultiTexCoord4fv_Exec(param_1,iVar4,iVar5);
          }
          else {
            bVar1 = uVar10 == 0;
            if (uVar2 != 0x140a) goto LAB_000a5ab8;
            fparam_1 = (double)_glMultiTexCoord4dv_Exec(param_1,iVar4,iVar5);
          }
        }
        bVar1 = uVar10 == 0;
      }
LAB_000a5ab8:
      uVar8 = uVar8 + 1;
      iVar9 = iVar9 + 0x18;
    } while ((!bVar1) && ((int)uVar8 < 8));
  }
  if ((uVar7 & 0x20000) != 0) {
    uVar2 = *(ushort *)(iVar3 + 0x50);
    iVar9 = *(int *)(iVar3 + 0x48) + param_2 * *(int *)(iVar3 + 0x4c);
    if (uVar2 == 0x9400) {
      fparam_1 = (double)_glNormal3bv_Exec(param_1,iVar9);
    }
    else if (uVar2 < 0x9401) {
      if (uVar2 == 0x1406) {
        fparam_1 = (double)_glNormal3fv_Exec(param_1,iVar9);
      }
      else if (uVar2 == 0x140a) {
        fparam_1 = (double)_glNormal3dv_Exec(param_1,iVar9);
      }
    }
    else if (uVar2 == 0x9402) {
      fparam_1 = (double)_glNormal3sv_Exec(param_1,iVar9);
    }
    else if (uVar2 == 0x9404) {
      fparam_1 = (double)((double (*)())_glNormal3iv_Exec)(param_1,iVar9,fparam_1,fparam_2,fparam_3,fparam_4,
                                           fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff98,
                                           in_stack_ffffffa0,in_stack_ffffffa8);
    }
  }
  if ((uVar7 & 0x40000) != 0) {
    iVar9 = *(int *)(iVar3 + 0x60) + param_2 * *(int *)(iVar3 + 100);
    if (*(short *)(iVar3 + 0x6a) == 3) {
      uVar2 = *(ushort *)(iVar3 + 0x68);
      if (uVar2 == 0x9401) {
        fparam_1 = (double)_glColor3ubv_Exec(param_1,iVar9);
      }
      else if (uVar2 < 0x9402) {
        if (uVar2 == 0x140a) {
          fparam_1 = (double)_glColor3dv_Exec(param_1,iVar9);
        }
        else if (uVar2 < 0x140b) {
          if (uVar2 == 0x1406) {
            if (*(char *)(param_1 + 0x4df8) == '\0') {
              fparam_1 = (double)_glColor3fv_NoColorMat_Exec(param_1,iVar9);
            }
            else {
              fparam_1 = (double)_glColor3fv_ColorMat_Exec(param_1,iVar9);
            }
          }
        }
        else if (uVar2 == 0x9400) {
          fparam_1 = (double)_glColor3bv_Exec(param_1,iVar9);
        }
      }
      else if (uVar2 == 0x9403) {
        fparam_1 = (double)((double (*)())_glColor3usv_Exec)(param_1,iVar9,fparam_1,fparam_2,fparam_3,fparam_4,
                                             fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff98,
                                             in_stack_ffffffa0,in_stack_ffffffa8,in_stack_ffffffb0,
                                             in_stack_ffffffb8);
      }
      else if (uVar2 < 0x9403) {
        fparam_1 = (double)_glColor3sv_Exec(param_1,iVar9);
      }
      else if (uVar2 == 0x9404) {
        fparam_1 = (double)_glColor3iv_Exec(param_1,iVar9);
      }
      else if (uVar2 == 0x9405) {
        fparam_1 = (double)_glColor3uiv_Exec(param_1,iVar9);
      }
    }
    else if (*(short *)(iVar3 + 0x6a) == 4) {
      uVar2 = *(ushort *)(iVar3 + 0x68);
      if (uVar2 == 0x9401) {
        fparam_1 = (double)_glColor4ubv_Exec(param_1,iVar9);
      }
      else if (uVar2 < 0x9402) {
        if (uVar2 == 0x140a) {
          fparam_1 = (double)_glColor4dv_Exec(param_1,iVar9);
        }
        else if (uVar2 < 0x140b) {
          if (uVar2 == 0x1406) {
            if (*(char *)(param_1 + 0x4df8) == '\0') {
              fparam_1 = (double)_glColor4fv_NoColorMat_Exec(param_1,iVar9);
            }
            else {
              fparam_1 = (double)_glColor4fv_ColorMat_Exec(param_1,iVar9);
            }
          }
        }
        else if (uVar2 == 0x9400) {
          fparam_1 = (double)_glColor4bv_Exec(param_1,iVar9);
        }
      }
      else if (uVar2 == 0x9403) {
        fparam_1 = (double)((double (*)())_glColor4usv_Exec)(param_1,iVar9,fparam_1,fparam_2,fparam_3,fparam_4,
                                             fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff98,
                                             in_stack_ffffffa0,in_stack_ffffffa8,in_stack_ffffffb0,
                                             in_stack_ffffffb8);
      }
      else if (uVar2 < 0x9403) {
        fparam_1 = (double)_glColor4sv_Exec(param_1,iVar9);
      }
      else if (uVar2 == 0x9404) {
        fparam_1 = (double)_glColor4iv_Exec(param_1,iVar9);
      }
      else if (uVar2 == 0x9405) {
        fparam_1 = (double)_glColor4uiv_Exec(param_1,iVar9);
      }
    }
  }
  if ((uVar7 & 0x100000) != 0) {
    uVar2 = *(ushort *)(iVar3 + 0x98);
    iVar9 = *(int *)(iVar3 + 0x90) + param_2 * *(int *)(iVar3 + 0x94);
    if (uVar2 == 0x9401) {
      fparam_1 = (double)_glSecondaryColor3ubv_Exec(param_1,iVar9);
    }
    else if (uVar2 < 0x9402) {
      if (uVar2 == 0x140a) {
        fparam_1 = (double)_glSecondaryColor3dv_Exec(param_1,iVar9);
      }
      else if (uVar2 < 0x140b) {
        if (uVar2 == 0x1406) {
          fparam_1 = (double)_glSecondaryColor3fv_Exec(param_1,iVar9);
        }
      }
      else if (uVar2 == 0x9400) {
        fparam_1 = (double)_glSecondaryColor3bv_Exec(param_1,iVar9);
      }
    }
    else if (uVar2 == 0x9403) {
      fparam_1 = (double)_glSecondaryColor3usv_Exec(param_1,iVar9);
    }
    else if (uVar2 < 0x9403) {
      fparam_1 = (double)_glSecondaryColor3sv_Exec(param_1,iVar9);
    }
    else if (uVar2 == 0x9404) {
      fparam_1 = (double)_glSecondaryColor3iv_Exec(param_1,iVar9);
    }
    else if (uVar2 == 0x9405) {
      fparam_1 = (double)_glSecondaryColor3uiv_Exec(param_1,iVar9);
    }
  }
  if ((uVar7 & 0x80000) != 0) {
    iVar9 = *(int *)(iVar3 + 0x78) + param_2 * *(int *)(iVar3 + 0x7c);
    if (*(short *)(iVar3 + 0x80) == 0x1406) {
      fparam_1 = (double)_glFogCoordfv_Exec(param_1,iVar9);
    }
    else if (*(short *)(iVar3 + 0x80) == 0x140a) {
      fparam_1 = (double)_glFogCoorddv_Exec(param_1,iVar9);
    }
  }
  if ((uVar7 & 0x200000) != 0) {
    uVar2 = *(ushort *)(iVar3 + 0xb0);
    iVar9 = *(int *)(iVar3 + 0xa8) + param_2 * *(int *)(iVar3 + 0xac);
    if (uVar2 == 0x9401) {
      fparam_1 = (double)_glWeightubvARB_Exec(param_1,(int)*(short *)(iVar3 + 0xb2),iVar9);
    }
    else if (uVar2 < 0x9402) {
      if (uVar2 == 0x140a) {
        fparam_1 = (double)_glWeightdvARB_Exec(param_1,(int)*(short *)(iVar3 + 0xb2),iVar9);
      }
      else if (uVar2 < 0x140b) {
        if (uVar2 == 0x1406) {
          fparam_1 = (double)_glWeightfvARB_Exec(param_1,(int)*(short *)(iVar3 + 0xb2),iVar9);
        }
      }
      else if (uVar2 == 0x9400) {
        fparam_1 = (double)_glWeightbvARB_Exec(param_1,(int)*(short *)(iVar3 + 0xb2),iVar9);
      }
    }
    else if (uVar2 == 0x9403) {
      fparam_1 = (double)_glWeightusvARB_Exec(param_1,(int)*(short *)(iVar3 + 0xb2),iVar9);
    }
    else if (uVar2 < 0x9403) {
      fparam_1 = (double)_glWeightsvARB_Exec(param_1,(int)*(short *)(iVar3 + 0xb2),iVar9);
    }
    else if (uVar2 == 0x9404) {
      fparam_1 = (double)_glWeightivARB_Exec(param_1,(int)*(short *)(iVar3 + 0xb2),iVar9);
    }
    else if (uVar2 == 0x9405) {
      fparam_1 = (double)_glWeightuivARB_Exec(param_1,(int)*(short *)(iVar3 + 0xb2),iVar9);
    }
  }
  uVar10 = *(uint *)(iVar3 + 0x330);
  if (uVar10 != 0) {
    bVar1 = uVar10 == 0;
    uVar6 = 0xf;
    uVar8 = 0;
    if (!bVar1) {
      iVar9 = iVar3 + 0x178;
      do {
        uVar8 = 1 << (uVar6 & 0x3f);
        if ((uVar10 & uVar8) == 0) goto LAB_000a638c;
        uVar10 = uVar10 & ~uVar8;
        uVar2 = *(ushort *)(iVar9 + 0x1aa);
        iVar4 = *(int *)(iVar9 + 0x1a0) + param_2 * *(int *)(iVar9 + 0x1a4);
        if (uVar2 == 2) {
          uVar2 = *(ushort *)(iVar9 + 0x1a8);
          if (uVar2 == 0x1406) {
            fparam_1 = (double)_glVertexAttrib2fvARB_Exec(param_1,uVar6,iVar4);
            goto LAB_000a6388;
          }
          if (uVar2 < 0x1407) {
            bVar1 = uVar10 == 0;
            if (uVar2 == 0x1402) {
              fparam_1 = (double)_glVertexAttrib2svARB_Exec(param_1,uVar6,iVar4);
              goto LAB_000a6388;
            }
          }
          else {
            bVar1 = uVar10 == 0;
            if (uVar2 == 0x140a) {
              fparam_1 = (double)_glVertexAttrib2dvARB_Exec(param_1,uVar6,iVar4);
              goto LAB_000a6388;
            }
          }
        }
        else {
          if (uVar2 < 3) {
            bVar1 = uVar10 == 0;
            if (uVar2 != 1) goto LAB_000a638c;
            uVar2 = *(ushort *)(iVar9 + 0x1a8);
            if (uVar2 != 0x1406) {
              if (uVar2 < 0x1407) {
                bVar1 = uVar10 == 0;
                if (uVar2 == 0x1402) {
                  fparam_1 = (double)_glVertexAttrib1svARB_Exec(param_1,uVar6,iVar4);
                  goto LAB_000a6388;
                }
              }
              else {
                bVar1 = uVar10 == 0;
                if (uVar2 == 0x140a) {
                  fparam_1 = (double)_glVertexAttrib1dvARB_Exec(param_1,uVar6,iVar4);
                  goto LAB_000a6388;
                }
              }
              goto LAB_000a638c;
            }
            fparam_1 = (double)_glVertexAttrib1fvARB_Exec(param_1,uVar6,iVar4);
          }
          else if (uVar2 == 3) {
            uVar2 = *(ushort *)(iVar9 + 0x1a8);
            if (uVar2 != 0x1406) {
              if (uVar2 < 0x1407) {
                bVar1 = uVar10 == 0;
                if (uVar2 == 0x1402) {
                  fparam_1 = (double)_glVertexAttrib3svARB_Exec(param_1,uVar6,iVar4);
                  goto LAB_000a6388;
                }
              }
              else {
                bVar1 = uVar10 == 0;
                if (uVar2 == 0x140a) {
                  fparam_1 = (double)_glVertexAttrib3dvARB_Exec(param_1,uVar6,iVar4);
                  goto LAB_000a6388;
                }
              }
              goto LAB_000a638c;
            }
            fparam_1 = (double)_glVertexAttrib3fvARB_Exec(param_1,uVar6,iVar4);
          }
          else {
            bVar1 = uVar10 == 0;
            if (uVar2 != 4) goto LAB_000a638c;
            uVar2 = *(ushort *)(iVar9 + 0x1a8);
            if (uVar2 == 0x1406) {
              fparam_1 = (double)_glVertexAttrib4fvARB_Exec(param_1,uVar6,iVar4);
            }
            else if (uVar2 < 0x1407) {
              if (uVar2 == 0x1402) {
                fparam_1 = (double)_glVertexAttrib4svARB_Exec(param_1,uVar6,iVar4);
              }
              else if (uVar2 < 0x1403) {
                if (uVar2 == 0x1400) {
                  fparam_1 = (double)_glVertexAttrib4bvARB_Exec(param_1,uVar6,iVar4);
                }
                else {
                  if (uVar2 != 0x1401) goto LAB_000a638c;
                  fparam_1 = (double)((double (*)())_glVertexAttrib4ubvARB_Exec)(param_1,uVar6,iVar4,fparam_1,fparam_2,fparam_3,
                                                fparam_4);
                }
              }
              else if (uVar2 == 0x1404) {
                fparam_1 = (double)_glVertexAttrib4ivARB_Exec(param_1,uVar6,iVar4);
              }
              else if (uVar2 < 0x1405) {
                fparam_1 = (double)((double (*)())_glVertexAttrib4usvARB_Exec)(param_1,uVar6,iVar4,fparam_1,fparam_2,fparam_3,
                                              fparam_4);
              }
              else {
                fparam_1 = (double)_glVertexAttrib4uivARB_Exec(param_1,uVar6,iVar4);
              }
            }
            else if (uVar2 == 0x9402) {
              fparam_1 = (double)_glVertexAttrib4NsvARB_Exec(param_1,uVar6,iVar4);
            }
            else if (uVar2 < 0x9403) {
              if (uVar2 == 0x9400) {
                fparam_1 = (double)_glVertexAttrib4NbvARB_Exec(param_1,uVar6,iVar4);
              }
              else if (uVar2 < 0x9401) {
                bVar1 = uVar10 == 0;
                if (uVar2 != 0x140a) goto LAB_000a638c;
                fparam_1 = (double)_glVertexAttrib4dvARB_Exec(param_1,uVar6,iVar4);
              }
              else {
                fparam_1 = (double)((double (*)())_glVertexAttrib4NubvARB_Exec)(param_1,uVar6,iVar4,fparam_1,fparam_2,fparam_3,
                                              fparam_4);
              }
            }
            else if (uVar2 == 0x9404) {
              fparam_1 = (double)_glVertexAttrib4NivARB_Exec(param_1,uVar6,iVar4);
            }
            else if (uVar2 < 0x9404) {
              fparam_1 = (double)((double (*)())_glVertexAttrib4NusvARB_Exec)(param_1,uVar6,iVar4,fparam_1,fparam_2,fparam_3,fparam_4)
              ;
            }
            else {
              bVar1 = uVar10 == 0;
              if (uVar2 != 0x9405) goto LAB_000a638c;
              fparam_1 = (double)_glVertexAttrib4NuivARB_Exec(param_1,uVar6,iVar4);
            }
          }
LAB_000a6388:
          bVar1 = uVar10 == 0;
        }
LAB_000a638c:
        uVar6 = uVar6 - 1;
        iVar9 = iVar9 + -0x18;
      } while ((!bVar1) && (-1 < (int)uVar6));
      uVar8 = *(uint *)(iVar3 + 0x330);
    }
    if ((uVar8 & 1) != 0) {
      return;
    }
  }
  if ((uVar7 & 0x10000) != 0) {
    uVar2 = *(ushort *)(iVar3 + 0x3a);
    iVar9 = *(int *)(iVar3 + 0x30) + param_2 * *(int *)(iVar3 + 0x34);
    if (uVar2 == 3) {
      uVar2 = *(ushort *)(iVar3 + 0x38);
      if (uVar2 == 0x1404) {
        ((int (*)())_glVertex3iv_Exec)(param_1,iVar9);
        return;
      }
      if (uVar2 < 0x1405) {
        if (uVar2 == 0x1402) {
          ((int (*)())_glVertex3sv_Exec)(param_1,iVar9);
          return;
        }
      }
      else {
        if (uVar2 == 0x1406) {
          _glVertex3fv_Exec(param_1,iVar9);
          return;
        }
        if (uVar2 == 0x140a) {
          _glVertex3dv_Exec(param_1,iVar9);
          return;
        }
      }
    }
    else if (uVar2 < 4) {
      if (uVar2 == 2) {
        uVar2 = *(ushort *)(iVar3 + 0x38);
        if (uVar2 == 0x1404) {
          ((int (*)())_glVertex2iv_Exec)(param_1,iVar9);
          return;
        }
        if (uVar2 < 0x1405) {
          if (uVar2 == 0x1402) {
            ((int (*)())_glVertex2sv_Exec)(param_1,iVar9);
            return;
          }
        }
        else {
          if (uVar2 == 0x1406) {
            _glVertex2fv_Exec(param_1,iVar9);
            return;
          }
          if (uVar2 == 0x140a) {
            _glVertex2dv_Exec(param_1,iVar9);
            return;
          }
        }
      }
    }
    else if (uVar2 == 4) {
      uVar2 = *(ushort *)(iVar3 + 0x38);
      if (uVar2 == 0x1404) {
        ((int (*)())_glVertex4iv_Exec)(param_1,iVar9);
        return;
      }
      if (uVar2 < 0x1405) {
        if (uVar2 == 0x1402) {
          ((int (*)())_glVertex4sv_Exec)(param_1,iVar9);
          return;
        }
      }
      else {
        if (uVar2 == 0x1406) {
          _glVertex4fv_Exec(param_1,iVar9);
          return;
        }
        if (uVar2 == 0x140a) {
          _glVertex4dv_Exec(param_1,iVar9);
          return;
        }
      }
    }
  }
  return;
}

/* _glArrayElement_CompExec @ 0xa65f0 (56 bytes) */
void _glArrayElement_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  unsigned int ghidra_home[8] = { param_1, param_2, 0, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glArrayElement_Comp)(param_1,param_2);
  ((void (*)())_glArrayElement_Exec)(param_1,param_2,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)((unsigned char *)ghidra_home + 0)),
             (*(double *)((unsigned char *)ghidra_home + 8)),(*(double *)((unsigned char *)ghidra_home + 16)));
  return;
}

/* _gleForcePushMaterial @ 0xa6628 (204 bytes) */
void _gleForcePushMaterial(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined8 uVar4;
  
  puVar2 = *(undefined8 **)(param_1 + 0x4dd8);
  puVar3 = *(undefined8 **)(param_2 * 4 + param_1 + 0x4dd0);
  if (puVar2 == (undefined8 *)0x0) {
    puVar2 = (undefined8 *)_gleVecAlloc(0x240);
    *(float *)((int)puVar2 + 500) = -*(float *)(param_1 + 0x24);
  }
  else {
    *(undefined4 *)(param_1 + 0x4dd8) = *(undefined4 *)((int)puVar2 + 0x23c);
  }
  *puVar2 = *puVar3;
  puVar2[1] = puVar3[1];
  puVar2[2] = puVar3[2];
  puVar2[3] = puVar3[3];
  puVar2[4] = puVar3[4];
  puVar2[5] = puVar3[5];
  puVar2[6] = puVar3[6];
  uVar4 = puVar3[7];
  *(undefined4 *)(puVar2 + 0x47) = 0;
  puVar2[7] = uVar4;
  uVar1 = *(undefined4 *)(puVar3 + 8);
  *(undefined4 *)(puVar2 + 0x3c) = 0;
  *(undefined8 **)(puVar3 + 0x47) = puVar2;
  *(undefined4 *)(puVar2 + 8) = uVar1;
  *(undefined8 **)((int)puVar2 + 0x23c) = puVar3;
  *(undefined8 **)(param_2 * 4 + param_1 + 0x4dd0) = puVar2;
  *(undefined4 *)((int)puVar2 + 0x234) = 0x1f000000;
  return;
}

/* _glDrawArraysOrElements_ListExec @ 0xa66f4 (1740 bytes) */
int _glDrawArraysOrElements_ListExec(int param_1,uint *param_2,undefined4 param_3,undefined4 param_4,uint param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  char cVar6;
  int *piVar4;
  uint *puVar5;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  int iVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  double fparam_1_00;
  double extraout_f1;
  double extraout_f1_00;
  
  uVar14 = param_2[5];
  uVar16 = param_2[6];
  uVar15 = param_2[7];
  if ((*(char *)(param_1 + 0x759c) == '\0') || (-1 < *(short *)(param_1 + 0x4a10))) {
LAB_000a6788:
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000a6da4;
    uVar2 = 0x502;
  }
  else if (uVar14 < 10) {
    if (-1 < (int)uVar16) {
      if ((*(char *)(param_1 + 0x4664) != '\0') &&
         (*(int *)(*(int *)(param_1 + 0x5420) + 0x4cc) == 0)) goto LAB_000a6788;
      if ((uVar16 == 0) || ((*(char *)(param_2 + 8) == '\0' && (*(char *)(param_2 + 0xc) == '\0'))))
      goto LAB_000a6da4;
      cVar6 = *(char *)(param_1 + 0x7580);
      if ((cVar6 != '\0') && ((*param_2 & 3) == 2)) {
        fparam_1 = (double)_gleCreateDrawArraysOrElementsVertexObject(param_1,param_2);
        cVar6 = *(char *)(param_1 + 0x7580);
      }
      if ((cVar6 == '\0') || ((*param_2 & 3) == 0)) {
LAB_000a6acc:
        iVar12 = *(int *)(param_1 + 0x50ac);
        if (iVar12 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
          _gleUpdateMatrixFunc(param_1);
          fparam_1 = extraout_f1_00;
        }
        if (*(char *)(param_1 + 0x4691) != '\0') {
          iVar8 = *(int *)(param_1 + 0x744c);
          piVar13 = (int *)(param_1 + 0x310);
          cVar6 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
          if ((iVar8 != 0) && (*(int *)(iVar8 + 0xec) != 0)) {
            ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar8 + 0x10,param_3,param_4,param_5,param_6,iVar12,fparam_1,fparam_2
                       ,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
            *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
          }
          if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a6bbc:
            uVar9 = *(uint *)(param_1 + 0x31c);
          }
          else {
            iVar12 = 0;
            piVar4 = (int *)(param_1 + 0x324);
            do {
              iVar8 = *piVar4;
              piVar4 = piVar4 + 1;
              if (iVar8 != 0) {
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
                break;
              }
              iVar12 = iVar12 + 1;
            } while (iVar12 < 9);
            uVar9 = *(uint *)(param_1 + 0x31c);
            if ((uVar9 & 0x15555) != 0) {
              if (*(char *)(param_1 + 0x2e54) != '\0') {
                _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
              }
              if (*(char *)(param_1 + 0x3094) != '\0') {
                _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
              }
              goto LAB_000a6bbc;
            }
          }
          bVar1 = cVar6 == '\0';
          if (bVar1) {
            uVar9 = uVar9 & 0x17000000;
          }
          else {
            uVar9 = uVar9 & 0x17ffffff;
          }
          if (bVar1) {
            bVar1 = ((*piVar13 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar9 == 0) &&
                    *(int *)(param_1 + 800) == 0;
          }
          else {
            bVar1 = (((*piVar13 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                     (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
                    *(int *)(param_1 + 800) == 0;
          }
          if (!bVar1) {
            if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
              uVar9 = (**(code **)(param_1 + 0x4788))
                                (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar13);
              if ((((uVar9 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
                  ((uVar9 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
                 ((uVar9 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
                if ((uVar9 & 4) == 0) {
                  uVar9 = uVar9 & 0xfffffffe;
                  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
                }
                _gleUpdateDispatchCodeChange(param_1,uVar9);
                if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_000a6ca8;
              }
            }
            else {
              _gleSwitchToNonRevertRenderer(param_1);
            }
            iVar12 = 0x13;
            do {
              *piVar13 = 0;
              piVar13 = piVar13 + 1;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
          }
        }
        uVar9 = 0;
        if (*(char *)(param_1 + 0x7580) == '\0') {
          uVar10 = 0;
          puVar5 = param_2 + 10;
          do {
            uVar3 = *(uint *)(param_1 + 0x514c) >> (uVar10 & 0x3f);
            if ((uVar3 & 1) == 0) {
              if (uVar3 == 0) break;
            }
            else if (*(char *)puVar5 == '\x10') {
              uVar9 = 3;
            }
            else if (*(char *)puVar5 == '\f') {
              uVar9 = uVar9 | 1;
            }
            uVar10 = uVar10 + 1;
            puVar5 = (uint *)((int)puVar5 + 1);
          } while( true );
        }
        *(uint **)(param_1 + 0x48f0) = param_2 + 0x10;
        *(uint **)(param_1 + 0x48ec) = param_2 + 5;
        uVar2 = _gleGetVertexArrayFunc(param_1);
        _gleDrawArraysOrElements_Core
                  (param_1,uVar14,0,uVar16,uVar9,-(uint)*(byte *)((int)param_2 + 0x22) >> 0x1f,0,
                   uVar2);
        *(undefined4 *)(param_1 + 0x48ec) = 0;
        uVar14 = *param_2;
      }
      else {
        uVar11 = *(undefined4 *)(param_1 + 0x4a60);
        param_3 = _gleGetEnabled(param_1,0x851d);
        _gleSetCurrentVertexObject(param_1,param_2[1]);
        uVar2 = 1;
        iVar12 = 0;
        fparam_1_00 = (double)_gleSetClientEnableFlag(param_1,0x851d,1);
        iVar8 = *(int *)(param_1 + 0x50ac);
        if (iVar8 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
          _gleUpdateMatrixFunc(param_1);
          fparam_1_00 = extraout_f1;
        }
        if (*(char *)(param_1 + 0x4691) != '\0') {
          iVar7 = *(int *)(param_1 + 0x744c);
          piVar13 = (int *)(param_1 + 0x310);
          cVar6 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
          if ((iVar7 != 0) && (*(int *)(iVar7 + 0xec) != 0)) {
            ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar7 + 0x10,uVar2,param_4,param_5,param_6,iVar8,fparam_1_00,fparam_2
                       ,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
            *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
          }
          if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a6938:
            uVar9 = *(uint *)(param_1 + 0x31c);
          }
          else {
            iVar8 = 0;
            piVar4 = (int *)(param_1 + 0x324);
            do {
              iVar7 = *piVar4;
              piVar4 = piVar4 + 1;
              if (iVar7 != 0) {
                *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
                break;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < 9);
            uVar9 = *(uint *)(param_1 + 0x31c);
            if ((uVar9 & 0x15555) != 0) {
              if (*(char *)(param_1 + 0x2e54) != '\0') {
                _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
              }
              if (*(char *)(param_1 + 0x3094) != '\0') {
                _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
              }
              goto LAB_000a6938;
            }
          }
          bVar1 = cVar6 == '\0';
          if (bVar1) {
            uVar9 = uVar9 & 0x17000000;
          }
          else {
            uVar9 = uVar9 & 0x17ffffff;
          }
          if (bVar1) {
            bVar1 = ((*piVar13 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar9 == 0) &&
                    *(int *)(param_1 + 800) == 0;
          }
          else {
            bVar1 = (((*piVar13 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                     (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
                    *(int *)(param_1 + 800) == 0;
          }
          if (bVar1) goto LAB_000a6a4c;
          if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
            _gleSwitchToNonRevertRenderer(param_1);
LAB_000a6a30:
            iVar8 = 0x13;
            do {
              *piVar13 = 0;
              piVar13 = piVar13 + 1;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
            goto LAB_000a6a4c;
          }
          uVar9 = (**(code **)(param_1 + 0x4788))
                            (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar13);
          if ((((uVar9 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
              ((uVar9 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
             ((uVar9 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0'))) goto LAB_000a6a30;
          if ((uVar9 & 4) == 0) {
            uVar9 = uVar9 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          _gleUpdateDispatchCodeChange(param_1,uVar9);
          if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000a6a30;
LAB_000a6ca8:
          if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000a6da4;
          uVar2 = 0x506;
          goto LAB_000a6748;
        }
LAB_000a6a4c:
        if (*(char *)(param_1 + 0x7580) != '\0') {
          param_4 = 0;
          param_6 = 0x14ff;
          param_5 = uVar16;
          iVar12 = _gleExecuteVertexArrayRange(param_1,0,uVar14,0,uVar16,0x14ff,0);
        }
        _gleSetCurrentVertexObject(param_1,uVar11);
        fparam_1 = (double)_gleSetClientEnableFlag(param_1,0x851d,param_3);
        if (iVar12 == 0) goto LAB_000a6acc;
        uVar14 = *param_2;
      }
      if ((uVar14 & 4) != 0) {
        _gleDrawArraysSyncState(param_1,param_2 + 5);
      }
      goto LAB_000a6da4;
    }
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000a6da4;
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_000a6da4;
    uVar2 = 0x500;
  }
LAB_000a6748:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
LAB_000a6da4:
  return uVar16 * uVar15 + 0x40;
}

/* _gleDrawArraysOrElements_Comp @ 0xa6dc0 (392 bytes) */
int _gleDrawArraysOrElements_Comp(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  unsigned char cVar1;
  uint uVar2;
  uint uVar3;
  code *pcVar4;
  code *pcVar5;
  int iVar6;
  code *pcVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  short *psVar11;
  code *pcVar12;
  longlong lVar13;
  undefined4 local_c0;
  undefined1 auStack_44 [12];
  
  iVar6 = *(int *)(param_1 + 0x4a60);
  uVar3 = *(uint *)(iVar6 + 0x330);
  pcVar5 = *(code **)(iVar6 + 0x334);
  uVar2 = (uint)pcVar5 & 0xff7fffff;
  if ((0 < param_4) &&
     (pcVar5 = (code *)((uint)pcVar5 & 0x10000), (uVar3 & 1) != 0 || pcVar5 != (code *)0x0)) {
    piVar10 = &local_c0;
    psVar11 = (short *)(iVar6 + 0x3a);
    iVar8 = 0;
    iVar9 = 0x10;
    do {
      lVar13 = ___ashldi3(0,1,iVar9);
      if ((uVar3 & (uint)((ulonglong)lVar13 >> 0x20)) == 0 && (uVar2 & (uint)lVar13) == 0) {
        *piVar10 = 0;
      }
      else {
        iVar8 = iVar8 + *psVar11 * 4;
        *piVar10 = *psVar11 * 4;
      }
      piVar10 = piVar10 + 1;
      iVar9 = iVar9 + 1;
      psVar11 = psVar11 + 0xc;
    } while ((int)piVar10 <= (int)auStack_44);
    pcVar5 = (code *)_gleAddListItem(param_1,PTR__glDrawArraysOrElements_ListExec_0011044c,
                                     param_4 * iVar8 + 0x40);
    if (pcVar5 != (code *)0x0) {
      *(undefined4 *)(pcVar5 + 0x14) = param_2;
      *(undefined4 *)(pcVar5 + 4) = 0;
      pcVar7 = pcVar5 + 0x20;
      *(undefined4 *)pcVar5 = 0;
      iVar9 = 0x20;
      *(int *)(pcVar5 + 0x1c) = iVar8;
      *(int *)(pcVar5 + 8) = param_4 * iVar8;
      pcVar4 = (code *)((int)&local_c0 + 3);
      *(int *)(pcVar5 + 0x18) = param_4;
      pcVar12 = pcVar5 + 0x40;
      do {
        cVar1 = *(char *)pcVar4;
        pcVar4 = pcVar4 + 4;
        *(char *)pcVar7 = cVar1;
        pcVar7 = pcVar7 + 1;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      pcVar4 = *(code **)(param_1 + 0x488c);
      if (*(code **)(param_1 + 0x488c) == (code *)0x0) {
        pcVar5 = (code *)_gleGetVertexToListFunc(param_1);
        *(code **)(param_1 + 0x488c) = pcVar5;
        pcVar4 = pcVar5;
      }
      iVar8 = param_4 + param_3;
      for (; param_3 < iVar8; param_3 = param_3 + 1) {
        pcVar12 = (code *)(*pcVar4)(param_1,iVar6 + 0x30,pcVar12,param_3);
        pcVar5 = pcVar12;
      }
    }
  }
  return pcVar5;
}

/* _gleDrawArraysOrElements_Exec @ 0xa6f48 (2712 bytes) */
void _gleDrawArraysOrElements_Exec(int param_1,int *param_2,int *param_3,int *param_4,undefined4 param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  short *psVar15;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  double extraout_f1_04;
  double extraout_f1_05;
  double extraout_f1_06;
  longlong lVar16;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_000a6fd8:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000a78b8;
  }
  if ((int *)((int)((unsigned char *)0x8) + 2) <= param_2) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
    goto LAB_000a78b8;
  }
  if ((int)param_4 < 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_000a78b8;
  }
  uVar9 = (uint)*(byte *)(param_1 + 0x4664);
  if ((uVar9 != 0) && (*(int *)(*(int *)(param_1 + 0x5420) + 0x4cc) == 0)) goto LAB_000a6fd8;
  if ((*(uint *)(param_6 + 800) & 1) == 0 && (*(uint *)(param_6 + 0x324) & 0x10000) == 0) {
    return;
  }
  if (param_4 == (int *)0x0) {
    return;
  }
  piVar8 = *(int **)(param_1 + 0x4988);
  piVar6 = param_3;
  piVar7 = param_4;
  if (((piVar8 == (int *)0x0) && (*(char *)(param_1 + 0x7580) != '\0')) &&
     (((((*(char *)(param_1 + 0x465c) != '\0' ||
         ((*(short *)(param_6 + 0x332) == -0x7a42 || (*(short *)(param_6 + 0x332) == -0x7a41)))) &&
        (*(int *)(param_6 + 0x338) != 0)) && (*(int *)(param_6 + 0x334) != 0)) ||
      ((*(uint *)(param_6 + 800) == (*(uint *)(param_6 + 0x328) & *(uint *)(param_6 + 800)) &&
       (*(uint *)(param_6 + 0x324) == (*(uint *)(param_6 + 0x32c) & *(uint *)(param_6 + 0x324)))))))
     ) {
    if (*(int *)(param_6 + 0x340) != 0 || *(int *)(param_6 + 0x344) != 0) {
      uVar11 = *(uint *)(param_6 + 0x340);
      uVar12 = *(uint *)(param_6 + 0x344);
      *(undefined4 *)(param_6 + 0x340) = 0;
      *(undefined4 *)(param_6 + 0x344) = 0;
      iVar13 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        iVar10 = param_6 + 0x450;
        do {
          iVar13 = iVar13 + 1;
          *(uint *)(iVar10 + 4) = *(uint *)(iVar10 + 4) | uVar11;
          *(uint *)(iVar10 + 8) = *(uint *)(iVar10 + 8) | uVar12;
          iVar10 = iVar10 + 0x8c;
        } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
    }
    iVar13 = *(int *)(param_1 + 0x50ac);
    if (iVar13 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(param_1 + 0x4691) != '\0') {
      iVar10 = *(int *)(param_1 + 0x744c);
      piVar14 = (int *)(param_1 + 0x310);
      cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
      if ((iVar10 != 0) && (*(int *)(iVar10 + 0xec) != 0)) {
        ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar10 + 0x10,piVar6,piVar7,piVar8,uVar9,iVar13,fparam_1,fparam_2,
                   fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
        *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
        fparam_1 = fparam_1;
      }
      if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a7208:
        uVar11 = *(uint *)(param_1 + 0x31c);
      }
      else {
        iVar13 = 0;
        piVar5 = (int *)(param_1 + 0x324);
        do {
          iVar10 = *piVar5;
          piVar5 = piVar5 + 1;
          if (iVar10 != 0) {
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
            break;
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < 9);
        uVar11 = *(uint *)(param_1 + 0x31c);
        if ((uVar11 & 0x15555) != 0) {
          if (*(char *)(param_1 + 0x2e54) != '\0') {
            piVar6 = (int *)0x0;
            fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
          }
          if (*(char *)(param_1 + 0x3094) != '\0') {
            piVar6 = (int *)((int)((unsigned char *)0x0) + 1);
            fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
          }
          goto LAB_000a7208;
        }
      }
      bVar1 = cVar2 == '\0';
      if (bVar1) {
        uVar11 = uVar11 & 0x17000000;
      }
      else {
        uVar11 = uVar11 & 0x17ffffff;
      }
      if (bVar1) {
        bVar1 = ((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      else {
        bVar1 = (((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) &&
                 (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
                *(int *)(param_1 + 800) == 0;
      }
      if (!bVar1) {
        if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
          uVar11 = (**(code **)(param_1 + 0x4788))
                             (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar14);
          if ((((uVar11 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
              ((uVar11 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
             (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')
             )) {
            if ((uVar11 & 4) == 0) {
              uVar11 = uVar11 & 0xfffffffe;
              *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
            }
            fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar11);
            if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_000a78a8;
          }
        }
        else {
          fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
        }
        iVar13 = 0x13;
        piVar6 = piVar14;
        do {
          *piVar6 = 0;
          piVar6 = piVar6 + 1;
          iVar13 = iVar13 + -1;
        } while (iVar13 != 0);
      }
    }
    if (*(char *)(param_1 + 0x7580) != '\0') {
      uVar9 = *(uint *)(param_1 + 0x48dc);
      piVar6 = param_2;
      piVar7 = param_3;
      piVar8 = param_4;
      iVar13 = _gleExecuteVertexArrayRange
                         (param_1,param_5,param_2,param_3,param_4,uVar9,
                          *(undefined4 *)(param_1 + 0x48d8));
      fparam_1 = extraout_f1_02;
      if (iVar13 != 0) {
        return;
      }
    }
LAB_000a76cc:
    iVar13 = *(int *)(param_1 + 0x50ac);
    if (iVar13 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      fparam_1 = extraout_f1_06;
    }
    if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_000a78e4;
    iVar10 = *(int *)(param_1 + 0x744c);
    piVar14 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar10 != 0) && (*(int *)(iVar10 + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar10 + 0x10,piVar6,piVar7,piVar8,uVar9,iVar13,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a77bc:
      uVar9 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar13 = 0;
      piVar6 = (int *)(param_1 + 0x324);
      do {
        iVar10 = *piVar6;
        piVar6 = piVar6 + 1;
        if (iVar10 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < 9);
      uVar9 = *(uint *)(param_1 + 0x31c);
      if ((uVar9 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000a77bc;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar9 = uVar9 & 0x17000000;
    }
    else {
      uVar9 = uVar9 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar9 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar9 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000a78e4;
    if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
      uVar9 = (**(code **)(param_1 + 0x4788))
                        (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar14);
      if ((((uVar9 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
          ((uVar9 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
         ((uVar9 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
        if ((uVar9 & 4) == 0) {
          uVar9 = uVar9 & 0xfffffffe;
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
        }
        _gleUpdateDispatchCodeChange(param_1,uVar9);
        if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_000a78a8;
      }
    }
    else {
      _gleSwitchToNonRevertRenderer(param_1);
    }
    iVar13 = 0x13;
    do {
      *piVar14 = 0;
      piVar14 = piVar14 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
LAB_000a78e4:
    uVar9 = 0;
    if (*(char *)(param_1 + 0x7580) != '\0') {
LAB_000a796c:
      iVar13 = *(int *)(param_1 + 0x4890);
      if (iVar13 == 0) {
        iVar13 = _gleGetVertexArrayFunc(param_1);
        *(int *)(param_1 + 0x4890) = iVar13;
      }
      *(int **)(param_1 + 0x4a14) = param_4;
      _gleDrawArraysOrElements_Core
                (param_1,param_2,param_3,param_4,uVar9,*(uint *)(param_6 + 0x324) >> 0x12 & 1,
                 param_6 + 0x20,iVar13);
      *(undefined4 *)(param_1 + 0x4a14) = 0;
      return;
    }
    uVar11 = *(uint *)(param_1 + 0x514c);
    uVar12 = 0;
    psVar15 = (short *)(param_6 + 0xea);
    do {
      uVar4 = uVar11 >> (uVar12 & 0x3f);
      if ((uVar4 & 1) == 0) {
        if (uVar4 == 0) goto LAB_000a796c;
      }
      else {
        lVar16 = ___ashldi3(0,0x1000000,uVar12);
        if ((*(uint *)(param_6 + 800) & (uint)((ulonglong)lVar16 >> 0x20)) != 0 ||
            (*(uint *)(param_6 + 0x324) & (uint)lVar16) != 0) {
          if (*psVar15 == 4) {
            uVar9 = 3;
          }
          else if (*psVar15 == 3) {
            uVar9 = uVar9 | 1;
          }
        }
      }
      uVar12 = uVar12 + 1;
      psVar15 = psVar15 + 0xc;
    } while( true );
  }
  if (((((int)piVar8 < 1) || (*(char *)(param_1 + 0x30aa) != '\0')) ||
      ((uVar9 != 0 || ((*(int *)(param_1 + 0x5434) != 0 || (*(char *)(param_1 + 0x4661) != '\0')))))
      ) || ((*(char *)(param_1 + 0x4fea) != '\0' ||
            ((*(int *)(param_1 + 0x4e1c) != 0x1c00 ||
             ((*(uint *)(param_1 + 0x514c) & 0xfffffffc) != 0)))))) goto LAB_000a76cc;
  if (*(char *)(param_1 + 0x7580) == '\0') {
    if (((((*(char *)(param_1 + 0x4e18) == '\0') && (*(char *)(param_1 + 0x4fe2) != '\0')) &&
         ((*(char *)(param_1 + 0x316a) == '\0' ||
          ((*(short *)(param_1 + 0x3166) == -0x7bae &&
           ((*(uint *)PTR__gle_processor_0011204c & 0x10) != 0)))))) &&
        ((*(char *)(param_1 + 0x34da) == '\0' ||
         (*(char *)(*(int *)(param_1 + 0x468c) + 0x78) != '\0')))) &&
       ((*(int *)(param_1 + 0x34f4) == 0x1d01 && ((*(uint *)(param_1 + 0x514c) & 0xfffffffe) == 0)))
       ) goto LAB_000a7454;
    goto LAB_000a76cc;
  }
  if (*(char *)(param_1 + 0x53e6) != '\0') goto LAB_000a76cc;
LAB_000a7454:
  iVar13 = *(int *)(param_1 + 0x50ac);
  if (iVar13 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1_03;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000a7658:
    if (*(ushort *)(param_1 + 0x4992) == (ushort)*(byte *)(param_1 + 0x7580)) {
      uVar12 = *(uint *)(param_1 + 0x497c);
      uVar11 = *(uint *)(param_1 + 0x4980);
      if ((uVar12 & uVar11) != 0) goto LAB_000a7678;
    }
    else {
LAB_000a7678:
      fparam_1 = (double)_gleCompileVertexArray(param_1);
      uVar12 = *(uint *)(param_1 + 0x497c);
      uVar11 = *(uint *)(param_1 + 0x4980);
    }
    if ((uVar12 & uVar11) == 0) {
      _gleExecuteVertexArray
                (param_1,param_2,param_3,param_4,*(undefined4 *)(param_1 + 0x48dc),
                 *(undefined4 *)(param_1 + 0x4978));
      return;
    }
    goto LAB_000a76cc;
  }
  iVar10 = *(int *)(param_1 + 0x744c);
  piVar14 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar10 != 0) && (*(int *)(iVar10 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar10 + 0x10,piVar6,piVar7,piVar8,uVar9,iVar13,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
    fparam_1 = fparam_1;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a7544:
    uVar11 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar13 = 0;
    piVar5 = (int *)(param_1 + 0x324);
    do {
      iVar10 = *piVar5;
      piVar5 = piVar5 + 1;
      if (iVar10 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < 9);
    uVar11 = *(uint *)(param_1 + 0x31c);
    if ((uVar11 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        piVar6 = (int *)0x0;
        fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        piVar6 = (int *)((int)((unsigned char *)0x0) + 1);
        fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_000a7544;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar11 = uVar11 & 0x17000000;
  }
  else {
    uVar11 = uVar11 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (bVar1) goto LAB_000a7658;
  if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
    fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000a763c:
    iVar13 = 0x13;
    piVar6 = piVar14;
    do {
      *piVar6 = 0;
      piVar6 = piVar6 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    goto LAB_000a7658;
  }
  uVar11 = (**(code **)(param_1 + 0x4788))
                     (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar14);
  if ((((uVar11 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
      ((uVar11 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
     (fparam_1 = extraout_f1_05, (uVar11 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
  goto LAB_000a763c;
  if ((uVar11 & 4) == 0) {
    uVar11 = uVar11 & 0xfffffffe;
    *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
  }
  fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar11);
  if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000a763c;
LAB_000a78a8:
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x506;
LAB_000a78b8:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _gleDrawArraysOrElements_VBO_Exec @ 0xa79e0 (1772 bytes) */
void _gleDrawArraysOrElements_VBO_Exec(int param_1,int *param_2,int *param_3,int *param_4,int *param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int *piVar14;
  uint uVar15;
  short *psVar16;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  longlong lVar17;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_000a7a68:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000a7f7c;
  }
  if ((int *)((int)((unsigned char *)0x8) + 2) <= param_2) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
    goto LAB_000a7f7c;
  }
  if ((int)param_4 < 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_000a7f7c;
  }
  if ((*(char *)(param_1 + 0x4664) != '\0') && (*(int *)(*(int *)(param_1 + 0x5420) + 0x4cc) == 0))
  goto LAB_000a7a68;
  if ((*(uint *)(param_6 + 800) & 1) == 0 && (*(uint *)(param_6 + 0x324) & 0x10000) == 0) {
    return;
  }
  if (param_4 == (int *)0x0) {
    return;
  }
  piVar6 = param_3;
  piVar7 = param_4;
  piVar8 = param_5;
  iVar9 = param_6;
  if ((*(uint *)(param_6 + 800) == (*(uint *)(param_6 + 0x328) & *(uint *)(param_6 + 800))) &&
     (*(uint *)(param_6 + 0x324) == (*(uint *)(param_6 + 0x32c) & *(uint *)(param_6 + 0x324)))) {
    if (*(int *)(param_6 + 0x340) != 0 || *(int *)(param_6 + 0x344) != 0) {
      uVar11 = *(uint *)(param_6 + 0x340);
      uVar12 = *(uint *)(param_6 + 0x344);
      *(undefined4 *)(param_6 + 0x340) = 0;
      *(undefined4 *)(param_6 + 0x344) = 0;
      iVar13 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        iVar10 = param_6 + 0x450;
        do {
          iVar13 = iVar13 + 1;
          *(uint *)(iVar10 + 4) = *(uint *)(iVar10 + 4) | uVar11;
          *(uint *)(iVar10 + 8) = *(uint *)(iVar10 + 8) | uVar12;
          iVar10 = iVar10 + 0x8c;
        } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x100000;
    }
    iVar13 = *(int *)(param_1 + 0x50ac);
    if (iVar13 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
      _gleUpdateMatrixFunc(param_1);
      fparam_1 = extraout_f1;
    }
    if (*(char *)(param_1 + 0x4691) == '\0') {
LAB_000a7d5c:
      if (*(char *)(param_1 + 0x7580) != '\0') {
        iVar9 = *(int *)(param_1 + 0x48dc);
        piVar6 = param_2;
        piVar7 = param_3;
        piVar8 = param_4;
        iVar13 = _gleExecuteVertexArrayRange
                           (param_1,param_5,param_2,param_3,param_4,iVar9,
                            *(undefined4 *)(param_1 + 0x48d8));
        fparam_1 = extraout_f1_02;
        if (iVar13 != 0) {
          return;
        }
      }
      goto LAB_000a7d90;
    }
    iVar10 = *(int *)(param_1 + 0x744c);
    piVar14 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar10 != 0) && (*(int *)(iVar10 + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar10 + 0x10,piVar6,piVar7,piVar8,iVar9,iVar13,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a7c38:
      uVar11 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar13 = 0;
      piVar5 = (int *)(param_1 + 0x324);
      do {
        iVar10 = *piVar5;
        piVar5 = piVar5 + 1;
        if (iVar10 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < 9);
      uVar11 = *(uint *)(param_1 + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          piVar6 = (int *)0x0;
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          piVar6 = (int *)((int)((unsigned char *)0x0) + 1);
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000a7c38;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar11 = uVar11 & 0x17000000;
    }
    else {
      uVar11 = uVar11 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (bVar1) goto LAB_000a7d5c;
    if (*(char *)(param_1 + 0x85a8) != *(char *)(param_1 + 0x85a6)) {
      fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
LAB_000a7d40:
      iVar13 = 0x13;
      piVar6 = piVar14;
      do {
        *piVar6 = 0;
        piVar6 = piVar6 + 1;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      goto LAB_000a7d5c;
    }
    uVar11 = (**(code **)(param_1 + 0x4788))
                       (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar14);
    if ((((uVar11 & 3) == (uint)*(byte *)(param_1 + 0x7580)) &&
        ((uVar11 & 4) == (uint)*(byte *)(param_1 + 0x7581))) &&
       (fparam_1 = extraout_f1_01, (uVar11 & 8) == (uint)(*(char *)(param_1 + 0x759d) == '\0')))
    goto LAB_000a7d40;
    if ((uVar11 & 4) == 0) {
      uVar11 = uVar11 & 0xfffffffe;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
    }
    fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar11);
    if (*(char *)(param_1 + 0x759d) != '\0') goto LAB_000a7d40;
LAB_000a7f6c:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x506;
LAB_000a7f7c:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
    return;
  }
LAB_000a7d90:
  iVar13 = *(int *)(param_1 + 0x50ac);
  if (iVar13 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1_03;
  }
  if (*(char *)(param_1 + 0x4691) == '\0') goto LAB_000a7fa8;
  iVar10 = *(int *)(param_1 + 0x744c);
  piVar14 = (int *)(param_1 + 0x310);
  cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
  if ((iVar10 != 0) && (*(int *)(iVar10 + 0xec) != 0)) {
    ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar10 + 0x10,piVar6,piVar7,piVar8,iVar9,iVar13,fparam_1,fparam_2,fparam_3,
               fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
  }
  if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a7e80:
    uVar11 = *(uint *)(param_1 + 0x31c);
  }
  else {
    iVar9 = 0;
    piVar6 = (int *)(param_1 + 0x324);
    do {
      iVar13 = *piVar6;
      piVar6 = piVar6 + 1;
      if (iVar13 != 0) {
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
        break;
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < 9);
    uVar11 = *(uint *)(param_1 + 0x31c);
    if ((uVar11 & 0x15555) != 0) {
      if (*(char *)(param_1 + 0x2e54) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
      }
      if (*(char *)(param_1 + 0x3094) != '\0') {
        _gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
      }
      goto LAB_000a7e80;
    }
  }
  bVar1 = cVar2 == '\0';
  if (bVar1) {
    uVar11 = uVar11 & 0x17000000;
  }
  else {
    uVar11 = uVar11 & 0x17ffffff;
  }
  if (bVar1) {
    bVar1 = ((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  else {
    bVar1 = (((*piVar14 == 0 && *(int *)(param_1 + 0x314) == 0) &&
             (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
            *(int *)(param_1 + 800) == 0;
  }
  if (bVar1) goto LAB_000a7fa8;
  if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
    uVar11 = (**(code **)(param_1 + 0x4788))
                       (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar14);
    if ((((uVar11 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
        ((uVar11 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
       ((uVar11 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0'))) {
      if ((uVar11 & 4) == 0) {
        uVar11 = uVar11 & 0xfffffffe;
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
      }
      _gleUpdateDispatchCodeChange(param_1,uVar11);
      if (*(char *)(param_1 + 0x759d) == '\0') goto LAB_000a7f6c;
    }
  }
  else {
    _gleSwitchToNonRevertRenderer(param_1);
  }
  iVar9 = 0x13;
  do {
    *piVar14 = 0;
    piVar14 = piVar14 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
LAB_000a7fa8:
  uVar11 = 0;
  if (*(char *)(param_1 + 0x7580) != '\0') {
LAB_000a8030:
    iVar9 = *(int *)(param_1 + 0x4890);
    if (iVar9 == 0) {
      iVar9 = _gleGetVertexArrayFunc(param_1);
      *(int *)(param_1 + 0x4890) = iVar9;
    }
    *(int **)(param_1 + 0x4a14) = param_4;
    _gleDrawArraysOrElements_Core
              (param_1,param_2,param_3,param_4,uVar11,*(uint *)(param_6 + 0x324) >> 0x12 & 1,
               param_6 + 0x20,iVar9);
    *(undefined4 *)(param_1 + 0x4a14) = 0;
    if (*(int *)(param_6 + 0x328) != 0 || *(int *)(param_6 + 0x32c) != 0) {
      return;
    }
    _gleUpdateDrawArraysFuncs(param_1);
    return;
  }
  uVar12 = *(uint *)(param_1 + 0x514c);
  uVar15 = 0;
  psVar16 = (short *)(param_6 + 0xea);
  do {
    uVar4 = uVar12 >> (uVar15 & 0x3f);
    if ((uVar4 & 1) == 0) {
      if (uVar4 == 0) goto LAB_000a8030;
    }
    else {
      lVar17 = ___ashldi3(0,0x1000000,uVar15);
      if ((*(uint *)(param_6 + 800) & (uint)((ulonglong)lVar17 >> 0x20)) != 0 ||
          (*(uint *)(param_6 + 0x324) & (uint)lVar17) != 0) {
        if (*psVar16 == 4) {
          uVar11 = 3;
        }
        else if (*psVar16 == 3) {
          uVar11 = uVar11 | 1;
        }
      }
    }
    uVar15 = uVar15 + 1;
    psVar16 = psVar16 + 0xc;
  } while( true );
}

/* _gleDrawArraysOrElements_CVA_Exec @ 0xa80cc (1152 bytes) */
void _gleDrawArraysOrElements_CVA_Exec(int param_1,uint param_2,undefined4 param_3,int param_4,undefined4 param_5,int param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int *piVar12;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_000a815c:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_000a8388;
  }
  if (9 < param_2) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
    goto LAB_000a8388;
  }
  if (param_4 < 0) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_000a8388;
  }
  if ((*(char *)(param_1 + 0x4664) != '\0') && (*(int *)(*(int *)(param_1 + 0x5420) + 0x4cc) == 0))
  goto LAB_000a815c;
  if ((*(uint *)(param_6 + 800) & 1) == 0 && (*(uint *)(param_6 + 0x324) & 0x10000) == 0) {
    return;
  }
  if (param_4 == 0) {
    return;
  }
  iVar9 = *(int *)(param_1 + 0x50ac);
  uVar3 = param_3;
  iVar10 = param_4;
  uVar8 = param_5;
  iVar4 = param_6;
  if (iVar9 != 0 || (*(uint *)(param_1 + 0x505c) & *(uint *)(param_1 + 0x50b0)) != 0) {
    _gleUpdateMatrixFunc(param_1);
    fparam_1 = extraout_f1;
  }
  if (*(char *)(param_1 + 0x4691) != '\0') {
    iVar7 = *(int *)(param_1 + 0x744c);
    piVar12 = (int *)(param_1 + 0x310);
    cVar2 = *(char *)(*(int *)(param_1 + 0x468c) + 0x79);
    if ((iVar7 != 0) && (*(int *)(iVar7 + 0xec) != 0)) {
      ((void (*)())_gleUpdateFramebufferCompleteness)(param_1,iVar7 + 0x10,uVar3,iVar10,uVar8,iVar4,iVar9,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x80000000;
      fparam_1 = fparam_1;
    }
    if ((*(char *)(param_1 + 0x4664) == '\0') && (*(int *)(param_1 + 0x5430) == 0)) {
LAB_000a828c:
      uVar11 = *(uint *)(param_1 + 0x31c);
    }
    else {
      iVar10 = 0;
      piVar5 = (int *)(param_1 + 0x324);
      do {
        iVar4 = *piVar5;
        piVar5 = piVar5 + 1;
        if (iVar4 != 0) {
          *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x800000;
          break;
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < 9);
      uVar11 = *(uint *)(param_1 + 0x31c);
      if ((uVar11 & 0x15555) != 0) {
        if (*(char *)(param_1 + 0x2e54) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2c20,0);
        }
        if (*(char *)(param_1 + 0x3094) != '\0') {
          fparam_1 = (double)_gleUpdateLightRGBASums(param_1,param_1 + 0x2e60,1);
        }
        goto LAB_000a828c;
      }
    }
    bVar1 = cVar2 == '\0';
    if (bVar1) {
      uVar11 = uVar11 & 0x17000000;
    }
    else {
      uVar11 = uVar11 & 0x17ffffff;
    }
    if (bVar1) {
      bVar1 = ((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    else {
      bVar1 = (((*piVar12 == 0 && *(int *)(param_1 + 0x314) == 0) &&
               (*(uint *)(param_1 + 0x318) & 0xfffffffd) == 0) && uVar11 == 0) &&
              *(int *)(param_1 + 800) == 0;
    }
    if (!bVar1) {
      if (*(char *)(param_1 + 0x85a8) == *(char *)(param_1 + 0x85a6)) {
        uVar11 = (**(code **)(param_1 + 0x4788))
                           (*(undefined4 *)(param_1 + 0x4688),param_1 + 0x4698,piVar12);
        if ((((uVar11 & 3) != (uint)*(byte *)(param_1 + 0x7580)) ||
            ((uVar11 & 4) != (uint)*(byte *)(param_1 + 0x7581))) ||
           (fparam_1 = extraout_f1_01, (uVar11 & 8) != (uint)(*(char *)(param_1 + 0x759d) == '\0')))
        {
          if ((uVar11 & 4) == 0) {
            uVar11 = uVar11 & 0xfffffffe;
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x10000000;
          }
          fparam_1 = (double)_gleUpdateDispatchCodeChange(param_1,uVar11);
          if (*(char *)(param_1 + 0x759d) == '\0') {
            if (*(int *)(param_1 + 0x7574) != 0) {
              return;
            }
            uVar3 = 0x506;
LAB_000a8388:
            *(undefined4 *)(param_1 + 0x7574) = uVar3;
            return;
          }
        }
      }
      else {
        fparam_1 = (double)_gleSwitchToNonRevertRenderer(param_1);
      }
      iVar10 = 0x13;
      do {
        *piVar12 = 0;
        piVar12 = piVar12 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
  }
  if (((((*(int *)(param_1 + 0x4988) < 1) || (*(char *)(param_1 + 0x30aa) != '\0')) ||
       ((*(char *)(param_1 + 0x4664) != '\0' ||
        ((*(int *)(param_1 + 0x5434) != 0 || (*(char *)(param_1 + 0x4661) != '\0')))))) ||
      (*(char *)(param_1 + 0x4fea) != '\0')) ||
     ((*(int *)(param_1 + 0x4e1c) != 0x1c00 || ((*(uint *)(param_1 + 0x514c) & 0xfffffffc) != 0))))
  goto LAB_000a850c;
  if (*(byte *)(param_1 + 0x7580) == 0) {
    if (((((*(char *)(param_1 + 0x4e18) != '\0') || (*(char *)(param_1 + 0x4fe2) == '\0')) ||
         ((*(char *)(param_1 + 0x316a) != '\0' &&
          ((*(short *)(param_1 + 0x3166) != -0x7bae ||
           ((*(uint *)PTR__gle_processor_0011204c & 0x10) == 0)))))) ||
        ((*(char *)(param_1 + 0x34da) != '\0' &&
         (*(char *)(*(int *)(param_1 + 0x468c) + 0x78) == '\0')))) ||
       ((*(int *)(param_1 + 0x34f4) != 0x1d01 || ((*(uint *)(param_1 + 0x514c) & 0xfffffffe) != 0)))
       ) goto LAB_000a850c;
  }
  else if (*(char *)(param_1 + 0x53e6) != '\0') goto LAB_000a850c;
  if (*(ushort *)(param_1 + 0x4992) == (ushort)*(byte *)(param_1 + 0x7580)) {
    uVar6 = *(uint *)(param_1 + 0x497c);
    uVar11 = *(uint *)(param_1 + 0x4980);
    if ((uVar6 & uVar11) != 0) goto LAB_000a84c8;
  }
  else {
LAB_000a84c8:
    fparam_1 = (double)_gleCompileVertexArray(param_1);
    uVar6 = *(uint *)(param_1 + 0x497c);
    uVar11 = *(uint *)(param_1 + 0x4980);
  }
  if ((uVar6 & uVar11) == 0) {
    _gleExecuteVertexArray
              (param_1,param_2,param_3,param_4,*(undefined4 *)(param_1 + 0x48dc),
               *(undefined4 *)(param_1 + 0x4978));
    return;
  }
LAB_000a850c:
  ((void (*)())_gleDrawArraysOrElements_IMM_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
             fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* _glDrawArrays_Comp @ 0xa854c (48 bytes) */
int _glDrawArrays_Comp(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x48dc) != 0x14ff) {
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x48dc) = 0x14ff;
    *(undefined4 *)(param_1 + 0x48d8) = 0;
    *(undefined4 *)(param_1 + 0x4978) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  uVar1 = ((int (*)())_gleDrawArraysOrElements_Comp)(param_1,param_2,param_3,param_4);
  return uVar1;
}

/* _glDrawArrays_STD_Exec @ 0xa85ec (56 bytes) */
void _glDrawArrays_STD_Exec(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  if (*(int *)(param_1 + 0x48dc) != 0x14ff) {
    *(undefined4 *)(param_1 + 0x488c) = 0;
    *(undefined4 *)(param_1 + 0x48dc) = 0x14ff;
    *(undefined4 *)(param_1 + 0x48d8) = 0;
    *(undefined4 *)(param_1 + 0x4978) = 0;
    *(undefined4 *)(param_1 + 0x4890) = 0;
  }
  ((void (*)())_gleDrawArraysOrElements_Exec)(param_1,param_2,param_3,param_4,0,*(int *)(param_1 + 0x4a60) + 0x10,fparam_1,fparam_2,
             fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

