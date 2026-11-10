#include "decls.h"

/* _glUniform2fARB_ListExec @ 0x8cb60 (52 bytes) */
int _glUniform2fARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glUniform2fARB_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])),(double)GH_U2F((unsigned int)(param_2[2])));
  return 0xc;
}

/* _glUniform1fARB_ListExec @ 0x8cb94 (44 bytes) */
int _glUniform1fARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glUniform1fARB_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])));
  return 8;
}

/* _glUniform4fvARB_ListExec @ 0x8cbc0 (68 bytes) */
int _glUniform4fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform4fvARB_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return param_2[1] * 0x10 + 8;
}

/* _glUniform3fvARB_ListExec @ 0x8cc04 (68 bytes) */
int _glUniform3fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform3fvARB_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return param_2[1] * 0xc + 8;
}

/* _glUniform2fvARB_ListExec @ 0x8cc48 (68 bytes) */
int _glUniform2fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform2fvARB_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return param_2[1] * 8 + 8;
}

/* _glUniform1fvARB_ListExec @ 0x8cc8c (68 bytes) */
int _glUniform1fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform1fvARB_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return param_2[1] * 4 + 8;
}

/* _glUniform4iARB_ListExec @ 0x8ccd0 (60 bytes) */
int _glUniform4iARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform4iARB_Exec(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4]);
  return 0x14;
}

/* _glUniform3iARB_ListExec @ 0x8cd0c (56 bytes) */
int _glUniform3iARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform3iARB_Exec(param_1,*param_2,param_2[1],param_2[2],param_2[3]);
  return 0x10;
}

/* _glUniform2iARB_ListExec @ 0x8cd44 (52 bytes) */
int _glUniform2iARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform2iARB_Exec(param_1,*param_2,param_2[1],param_2[2]);
  return 0xc;
}

/* _glUniform1iARB_ListExec @ 0x8cd78 (44 bytes) */
int _glUniform1iARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform1iARB_Exec(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glUniform4ivARB_ListExec @ 0x8cda4 (68 bytes) */
int _glUniform4ivARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform4ivARB_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return param_2[1] * 0x10 + 8;
}

/* _glUniform3ivARB_ListExec @ 0x8cde8 (68 bytes) */
int _glUniform3ivARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform3ivARB_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return param_2[1] * 0xc + 8;
}

/* _glUniform2ivARB_ListExec @ 0x8ce2c (68 bytes) */
int _glUniform2ivARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform2ivARB_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return param_2[1] * 8 + 8;
}

/* _glUniform1ivARB_ListExec @ 0x8ce70 (68 bytes) */
int _glUniform1ivARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glUniform1ivARB_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return param_2[1] * 4 + 8;
}

/* _glUniformMatrix2fvARB_Exec @ 0x8ceb4 (816 bytes) */
void _glUniformMatrix2fvARB_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 *param_5;
{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  int local_40;
  int local_3c;
  undefined2 local_38 [10];
  
  local_3c = 0;
  local_38[0] = 0;
  local_40 = 0;
  bVar3 = false;
  bVar4 = false;
  if (param_2 != -1) {
    iVar6 = *(int *)(param_1 + 0x5430);
    if ((((iVar6 == 0) || (*(int *)(iVar6 + 0x30) <= param_2)) || (param_3 < 0)) ||
       ((iVar8 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(iVar6 + 0x40),param_2,&local_40,&local_3c,local_38),
        iVar8 == 0 || (local_3c != 0x8b5a)))) {
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
      }
    }
    else if (param_3 != 0) {
      puVar7 = (undefined4 *)(*(int *)(iVar6 + 0x4c) + param_2 * 0x10);
      if (param_3 < local_40) {
        local_40 = param_3;
      }
      if (param_4 == 0) {
        iVar8 = 0;
        if (0 < local_40) {
          do {
            iVar8 = iVar8 + 1;
            *puVar7 = *param_5;
            puVar7[1] = param_5[1];
            puVar7[4] = param_5[2];
            puVar1 = param_5 + 3;
            param_5 = param_5 + 4;
            puVar7[5] = *puVar1;
            puVar7 = puVar7 + 8;
          } while (iVar8 < local_40);
        }
      }
      else {
        iVar8 = 0;
        if (0 < local_40) {
          do {
            iVar8 = iVar8 + 1;
            *puVar7 = *param_5;
            puVar7[4] = param_5[1];
            puVar7[1] = param_5[2];
            puVar1 = param_5 + 3;
            param_5 = param_5 + 4;
            puVar7[5] = *puVar1;
            puVar7 = puVar7 + 8;
          } while (iVar8 < local_40);
        }
      }
      iVar8 = 0;
      if (0 < local_40) {
        do {
          iVar17 = 0;
          iVar10 = param_2 << 4;
          iVar9 = param_2 << 2;
          do {
            iVar13 = *(int *)(iVar6 + 0x20);
            iVar16 = *(int *)(iVar9 + *(int *)(iVar13 + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar12 = *(int *)(iVar13 + 0x51c);
              bVar3 = true;
              iVar14 = iVar10 + *(int *)(iVar6 + 0x4c);
              uVar11 = *(undefined4 *)(iVar14 + 0xc);
              iVar13 = iVar16 + iVar12;
              uVar5 = *(undefined4 *)(iVar14 + 4);
              uVar15 = *(undefined4 *)(iVar14 + 8);
              *(undefined4 *)(iVar16 + iVar12) = *(undefined4 *)(iVar10 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar13 + 0xc) = uVar11;
              *(undefined4 *)(iVar13 + 4) = uVar5;
              *(undefined4 *)(iVar13 + 8) = uVar15;
            }
            iVar16 = *(int *)(iVar9 + *(int *)(*(int *)(iVar6 + 0x24) + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar12 = *(int *)(*(int *)(iVar6 + 0x24) + 0x51c);
              bVar4 = true;
              iVar14 = iVar10 + *(int *)(iVar6 + 0x4c);
              uVar11 = *(undefined4 *)(iVar14 + 0xc);
              iVar13 = iVar16 + iVar12;
              uVar5 = *(undefined4 *)(iVar14 + 4);
              uVar15 = *(undefined4 *)(iVar14 + 8);
              *(undefined4 *)(iVar16 + iVar12) = *(undefined4 *)(iVar10 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar13 + 0xc) = uVar11;
              *(undefined4 *)(iVar13 + 4) = uVar5;
              *(undefined4 *)(iVar13 + 8) = uVar15;
            }
            iVar17 = iVar17 + 1;
            iVar9 = iVar9 + 4;
            iVar10 = iVar10 + 0x10;
          } while (iVar17 < 2);
          iVar8 = iVar8 + 1;
          param_2 = param_2 + 2;
        } while (iVar8 < local_40);
      }
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
      if (bVar3) {
        iVar8 = param_1 + 0x10000;
        iVar10 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = iVar10 * 4;
            iVar10 = iVar10 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(iVar6 + 0x20) + 0x4e4),2);
          } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      if (bVar4) {
        iVar8 = param_1 + 0x10000;
        iVar10 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = iVar10 * 4;
            iVar10 = iVar10 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(iVar6 + 0x24) + 0x4e4),2);
          } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
    }
  }
  return;
}

/* _glUniformMatrix3fvARB_Exec @ 0x8d1e4 (900 bytes) */
void _glUniformMatrix3fvARB_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 *param_5;
{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  int local_40;
  int local_3c;
  undefined2 local_38 [10];
  
  local_3c = 0;
  local_38[0] = 0;
  local_40 = 0;
  bVar3 = false;
  bVar4 = false;
  if (param_2 != -1) {
    iVar6 = *(int *)(param_1 + 0x5430);
    if ((((iVar6 == 0) || (*(int *)(iVar6 + 0x30) <= param_2)) || (param_3 < 0)) ||
       ((iVar8 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(iVar6 + 0x40),param_2,&local_40,&local_3c,local_38),
        iVar8 == 0 || (local_3c != 0x8b5b)))) {
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
      }
    }
    else if (param_3 != 0) {
      puVar7 = (undefined4 *)(*(int *)(iVar6 + 0x4c) + param_2 * 0x10);
      if (param_3 < local_40) {
        local_40 = param_3;
      }
      if (param_4 == 0) {
        iVar8 = 0;
        if (0 < local_40) {
          do {
            iVar8 = iVar8 + 1;
            *puVar7 = *param_5;
            puVar7[1] = param_5[1];
            puVar7[2] = param_5[2];
            puVar7[4] = param_5[3];
            puVar7[5] = param_5[4];
            puVar7[6] = param_5[5];
            puVar7[8] = param_5[6];
            puVar7[9] = param_5[7];
            puVar1 = param_5 + 8;
            param_5 = param_5 + 9;
            puVar7[10] = *puVar1;
            puVar7 = puVar7 + 0xc;
          } while (iVar8 < local_40);
        }
      }
      else {
        iVar8 = 0;
        if (0 < local_40) {
          do {
            iVar8 = iVar8 + 1;
            *puVar7 = *param_5;
            puVar7[4] = param_5[1];
            puVar7[8] = param_5[2];
            puVar7[1] = param_5[3];
            puVar7[5] = param_5[4];
            puVar7[9] = param_5[5];
            puVar7[2] = param_5[6];
            puVar7[6] = param_5[7];
            puVar1 = param_5 + 8;
            param_5 = param_5 + 9;
            puVar7[10] = *puVar1;
            puVar7 = puVar7 + 0xc;
          } while (iVar8 < local_40);
        }
      }
      iVar8 = 0;
      if (0 < local_40) {
        iVar10 = param_2 << 4;
        do {
          iVar18 = 3;
          iVar9 = param_2 << 2;
          iVar11 = iVar10;
          do {
            iVar14 = *(int *)(iVar6 + 0x20);
            iVar17 = *(int *)(iVar9 + *(int *)(iVar14 + 0x4e0));
            if (iVar17 != -1) {
              iVar17 = iVar17 * 0x10;
              iVar13 = *(int *)(iVar14 + 0x51c);
              bVar3 = true;
              iVar15 = iVar11 + *(int *)(iVar6 + 0x4c);
              uVar12 = *(undefined4 *)(iVar15 + 0xc);
              iVar14 = iVar17 + iVar13;
              uVar5 = *(undefined4 *)(iVar15 + 4);
              uVar16 = *(undefined4 *)(iVar15 + 8);
              *(undefined4 *)(iVar17 + iVar13) = *(undefined4 *)(iVar11 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar14 + 0xc) = uVar12;
              *(undefined4 *)(iVar14 + 4) = uVar5;
              *(undefined4 *)(iVar14 + 8) = uVar16;
            }
            iVar17 = *(int *)(iVar9 + *(int *)(*(int *)(iVar6 + 0x24) + 0x4e0));
            if (iVar17 != -1) {
              iVar17 = iVar17 * 0x10;
              iVar13 = *(int *)(*(int *)(iVar6 + 0x24) + 0x51c);
              bVar4 = true;
              iVar15 = iVar11 + *(int *)(iVar6 + 0x4c);
              uVar12 = *(undefined4 *)(iVar15 + 0xc);
              iVar14 = iVar17 + iVar13;
              uVar5 = *(undefined4 *)(iVar15 + 4);
              uVar16 = *(undefined4 *)(iVar15 + 8);
              *(undefined4 *)(iVar17 + iVar13) = *(undefined4 *)(iVar11 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar14 + 0xc) = uVar12;
              *(undefined4 *)(iVar14 + 4) = uVar5;
              *(undefined4 *)(iVar14 + 8) = uVar16;
            }
            iVar9 = iVar9 + 4;
            iVar11 = iVar11 + 0x10;
            iVar18 = iVar18 + -1;
          } while (iVar18 != 0);
          iVar8 = iVar8 + 1;
          param_2 = param_2 + 3;
          iVar10 = iVar10 + 0x30;
        } while (iVar8 < local_40);
      }
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
      if (bVar3) {
        iVar8 = param_1 + 0x10000;
        iVar10 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = iVar10 * 4;
            iVar10 = iVar10 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(iVar6 + 0x20) + 0x4e4),2);
          } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      if (bVar4) {
        iVar8 = param_1 + 0x10000;
        iVar10 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = iVar10 * 4;
            iVar10 = iVar10 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(iVar6 + 0x24) + 0x4e4),2);
          } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
    }
  }
  return;
}

/* _glUniformMatrix4fvARB_Exec @ 0x8d568 (1004 bytes) */
void _glUniformMatrix4fvARB_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 *param_5;
{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int iVar17;
  int local_40;
  int local_3c;
  undefined2 local_38 [10];
  
  local_3c = 0;
  local_38[0] = 0;
  local_40 = 0;
  bVar3 = false;
  bVar4 = false;
  if (param_2 != -1) {
    iVar6 = *(int *)(param_1 + 0x5430);
    if ((((iVar6 == 0) || (*(int *)(iVar6 + 0x30) <= param_2)) || (param_3 < 0)) ||
       ((iVar8 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(iVar6 + 0x40),param_2,&local_40,&local_3c,local_38),
        iVar8 == 0 || (local_3c != 0x8b5c)))) {
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x502;
      }
    }
    else if (param_3 != 0) {
      puVar7 = (undefined4 *)(*(int *)(iVar6 + 0x4c) + param_2 * 0x10);
      if (param_3 < local_40) {
        local_40 = param_3;
      }
      if (param_4 == 0) {
        iVar8 = 0;
        if (0 < local_40) {
          do {
            iVar8 = iVar8 + 1;
            *puVar7 = *param_5;
            puVar7[1] = param_5[1];
            puVar7[2] = param_5[2];
            puVar7[3] = param_5[3];
            puVar7[4] = param_5[4];
            puVar7[5] = param_5[5];
            puVar7[6] = param_5[6];
            puVar7[7] = param_5[7];
            puVar7[8] = param_5[8];
            puVar7[9] = param_5[9];
            puVar7[10] = param_5[10];
            puVar7[0xb] = param_5[0xb];
            puVar7[0xc] = param_5[0xc];
            puVar7[0xd] = param_5[0xd];
            puVar7[0xe] = param_5[0xe];
            puVar1 = param_5 + 0xf;
            param_5 = param_5 + 0x10;
            puVar7[0xf] = *puVar1;
            puVar7 = puVar7 + 0x10;
          } while (iVar8 < local_40);
        }
      }
      else {
        iVar8 = 0;
        if (0 < local_40) {
          do {
            iVar8 = iVar8 + 1;
            *puVar7 = *param_5;
            puVar7[4] = param_5[1];
            puVar7[8] = param_5[2];
            puVar7[0xc] = param_5[3];
            puVar7[1] = param_5[4];
            puVar7[5] = param_5[5];
            puVar7[9] = param_5[6];
            puVar7[0xd] = param_5[7];
            puVar7[2] = param_5[8];
            puVar7[6] = param_5[9];
            puVar7[10] = param_5[10];
            puVar7[0xe] = param_5[0xb];
            puVar7[3] = param_5[0xc];
            puVar7[7] = param_5[0xd];
            puVar7[0xb] = param_5[0xe];
            puVar1 = param_5 + 0xf;
            param_5 = param_5 + 0x10;
            puVar7[0xf] = *puVar1;
            puVar7 = puVar7 + 0x10;
          } while (iVar8 < local_40);
        }
      }
      iVar8 = 0;
      if (0 < local_40) {
        do {
          iVar10 = param_2 << 4;
          iVar17 = 4;
          iVar9 = param_2 << 2;
          do {
            iVar13 = *(int *)(iVar6 + 0x20);
            iVar16 = *(int *)(iVar9 + *(int *)(iVar13 + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar12 = *(int *)(iVar13 + 0x51c);
              bVar3 = true;
              iVar14 = iVar10 + *(int *)(iVar6 + 0x4c);
              uVar11 = *(undefined4 *)(iVar14 + 0xc);
              iVar13 = iVar16 + iVar12;
              uVar5 = *(undefined4 *)(iVar14 + 4);
              uVar15 = *(undefined4 *)(iVar14 + 8);
              *(undefined4 *)(iVar16 + iVar12) = *(undefined4 *)(iVar10 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar13 + 0xc) = uVar11;
              *(undefined4 *)(iVar13 + 4) = uVar5;
              *(undefined4 *)(iVar13 + 8) = uVar15;
            }
            iVar16 = *(int *)(iVar9 + *(int *)(*(int *)(iVar6 + 0x24) + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar12 = *(int *)(*(int *)(iVar6 + 0x24) + 0x51c);
              bVar4 = true;
              iVar14 = iVar10 + *(int *)(iVar6 + 0x4c);
              uVar11 = *(undefined4 *)(iVar14 + 0xc);
              iVar13 = iVar16 + iVar12;
              uVar5 = *(undefined4 *)(iVar14 + 4);
              uVar15 = *(undefined4 *)(iVar14 + 8);
              *(undefined4 *)(iVar16 + iVar12) = *(undefined4 *)(iVar10 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar13 + 0xc) = uVar11;
              *(undefined4 *)(iVar13 + 4) = uVar5;
              *(undefined4 *)(iVar13 + 8) = uVar15;
            }
            iVar9 = iVar9 + 4;
            iVar10 = iVar10 + 0x10;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
          iVar8 = iVar8 + 1;
          param_2 = param_2 + 4;
        } while (iVar8 < local_40);
      }
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
      if (bVar3) {
        iVar8 = param_1 + 0x10000;
        iVar10 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = iVar10 * 4;
            iVar10 = iVar10 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(iVar6 + 0x20) + 0x4e4),2);
          } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      if (bVar4) {
        iVar8 = param_1 + 0x10000;
        iVar10 = 0;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = iVar10 * 4;
            iVar10 = iVar10 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(iVar6 + 0x24) + 0x4e4),2);
          } while (iVar10 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
    }
  }
  return;
}

/* _glUniformMatrix2fvARB_Comp @ 0x8d954 (228 bytes) */
int _glUniformMatrix2fvARB_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  undefined4 *param_5;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glUniformMatrix2fvARB_ListExec_001102c0,param_3 * 0x10 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = param_3;
    *puVar2 = param_2;
    puVar2 = puVar2 + 2;
    iVar1 = 0;
    if (param_4 == 0) {
      while( true ) {
        *puVar2 = *param_5;
        puVar2[1] = param_5[1];
        puVar2[2] = param_5[2];
        puVar2[3] = param_5[3];
        if (iVar1 == param_3 + -1) break;
        puVar2 = puVar2 + 4;
        param_5 = param_5 + 4;
        iVar1 = iVar1 + 1;
      }
    }
    else {
      while( true ) {
        *puVar2 = *param_5;
        puVar2[2] = param_5[1];
        puVar2[1] = param_5[2];
        puVar2[3] = param_5[3];
        if (iVar1 == param_3 + -1) break;
        puVar2 = puVar2 + 4;
        param_5 = param_5 + 4;
        iVar1 = iVar1 + 1;
      }
    }
  }
  return puVar2;
}

/* _glUniformMatrix3fvARB_Comp @ 0x8da38 (308 bytes) */
int _glUniformMatrix3fvARB_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  undefined4 *param_5;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glUniformMatrix3fvARB_ListExec_001102bc,param_3 * 0x24 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = param_3;
    *puVar2 = param_2;
    puVar2 = puVar2 + 2;
    iVar1 = 0;
    if (param_4 == 0) {
      while( true ) {
        *puVar2 = *param_5;
        puVar2[1] = param_5[1];
        puVar2[2] = param_5[2];
        puVar2[3] = param_5[3];
        puVar2[4] = param_5[4];
        puVar2[5] = param_5[5];
        puVar2[6] = param_5[6];
        puVar2[7] = param_5[7];
        puVar2[8] = param_5[8];
        if (iVar1 == param_3 + -1) break;
        puVar2 = puVar2 + 9;
        param_5 = param_5 + 9;
        iVar1 = iVar1 + 1;
      }
    }
    else {
      while( true ) {
        *puVar2 = *param_5;
        puVar2[3] = param_5[1];
        puVar2[6] = param_5[2];
        puVar2[1] = param_5[3];
        puVar2[4] = param_5[4];
        puVar2[7] = param_5[5];
        puVar2[2] = param_5[6];
        puVar2[5] = param_5[7];
        puVar2[8] = param_5[8];
        if (iVar1 == param_3 + -1) break;
        puVar2 = puVar2 + 9;
        param_5 = param_5 + 9;
        iVar1 = iVar1 + 1;
      }
    }
  }
  return puVar2;
}

/* _glUniformMatrix4fvARB_Comp @ 0x8db6c (420 bytes) */
int _glUniformMatrix4fvARB_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  undefined4 *param_5;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glUniformMatrix4fvARB_ListExec_001102b8,param_3 * 0x30 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = param_3;
    *puVar2 = param_2;
    puVar2 = puVar2 + 2;
    iVar1 = 0;
    if (param_4 == 0) {
      while( true ) {
        *puVar2 = *param_5;
        puVar2[1] = param_5[1];
        puVar2[2] = param_5[2];
        puVar2[3] = param_5[3];
        puVar2[4] = param_5[4];
        puVar2[5] = param_5[5];
        puVar2[6] = param_5[6];
        puVar2[7] = param_5[7];
        puVar2[8] = param_5[8];
        puVar2[9] = param_5[9];
        puVar2[10] = param_5[10];
        puVar2[0xb] = param_5[0xb];
        puVar2[0xc] = param_5[0xc];
        puVar2[0xd] = param_5[0xd];
        puVar2[0xe] = param_5[0xe];
        puVar2[0xf] = param_5[0xf];
        if (iVar1 == param_3 + -1) break;
        puVar2 = puVar2 + 0xc;
        param_5 = param_5 + 0xc;
        iVar1 = iVar1 + 1;
      }
    }
    else {
      while( true ) {
        *puVar2 = *param_5;
        puVar2[4] = param_5[1];
        puVar2[8] = param_5[2];
        puVar2[0xc] = param_5[3];
        puVar2[1] = param_5[4];
        puVar2[5] = param_5[5];
        puVar2[9] = param_5[6];
        puVar2[0xd] = param_5[7];
        puVar2[2] = param_5[8];
        puVar2[6] = param_5[9];
        puVar2[10] = param_5[10];
        puVar2[0xe] = param_5[0xb];
        puVar2[3] = param_5[0xc];
        puVar2[7] = param_5[0xd];
        puVar2[0xb] = param_5[0xe];
        puVar2[0xf] = param_5[0xf];
        if (iVar1 == param_3 + -1) break;
        puVar2 = puVar2 + 0xc;
        param_5 = param_5 + 0xc;
        iVar1 = iVar1 + 1;
      }
    }
  }
  return puVar2;
}

/* _glUniformMatrix2fvARB_CompExec @ 0x8dd10 (80 bytes) */
void _glUniformMatrix2fvARB_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glUniformMatrix2fvARB_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glUniformMatrix2fvARB_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glUniformMatrix3fvARB_CompExec @ 0x8dd60 (80 bytes) */
void _glUniformMatrix3fvARB_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glUniformMatrix3fvARB_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glUniformMatrix3fvARB_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glUniformMatrix4fvARB_CompExec @ 0x8ddb0 (80 bytes) */
void _glUniformMatrix4fvARB_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glUniformMatrix4fvARB_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glUniformMatrix4fvARB_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glUniformMatrix2fvARB_ListExec @ 0x8de00 (72 bytes) */
int _glUniformMatrix2fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glUniformMatrix2fvARB_Exec)(param_1,*param_2,param_2[1],0,param_2 + 2);
  return param_2[1] * 0x10 + 8;
}

/* _glUniformMatrix3fvARB_ListExec @ 0x8de48 (72 bytes) */
int _glUniformMatrix3fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glUniformMatrix3fvARB_Exec)(param_1,*param_2,param_2[1],0,param_2 + 2);
  return param_2[1] * 0x24 + 8;
}

/* _glUniformMatrix4fvARB_ListExec @ 0x8de90 (72 bytes) */
int _glUniformMatrix4fvARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glUniformMatrix4fvARB_Exec)(param_1,*param_2,param_2[1],0,param_2 + 2);
  return param_2[1] * 0x40 + 8;
}

/* _gleGetObjectParameter @ 0x8ded8 (508 bytes) */
int _gleGetObjectParameter(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  uint *param_4;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  switch(param_3) {
  case 0x8b4e:
    uVar2 = *(uint *)(param_2 + 0x10);
    if ((uVar2 != 0x8b40) && (uVar2 != 0x8b48)) {
      return 0x502;
    }
    goto LAB_0008e178;
  case 0x8b4f:
    if (*(int *)(param_2 + 0x10) != 0x8b48) {
      return 0x502;
    }
    uVar1 = *(uint *)(param_2 + 0x20);
    break;
  default:
    return 0x500;
  case 0x8b80:
    if ((*(int *)(param_2 + 0x10) != 0x8b40) && (*(int *)(param_2 + 0x10) != 0x8b48)) {
      return 0x502;
    }
    uVar1 = (uint)*(byte *)(param_2 + 0x14);
    break;
  case 0x8b81:
    if (*(int *)(param_2 + 0x10) != 0x8b48) {
      return 0x502;
    }
    uVar1 = (uint)*(byte *)(param_2 + 0x25);
    break;
  case 0x8b82:
    if (*(int *)(param_2 + 0x10) != 0x8b40) {
      return 0x502;
    }
    uVar1 = (uint)*(byte *)(param_2 + 0x3c);
    break;
  case 0x8b83:
    if (*(int *)(param_2 + 0x10) != 0x8b40) {
      return 0x502;
    }
    uVar1 = (uint)*(byte *)(param_2 + 0x3d);
    break;
  case 0x8b84:
    if ((*(int *)(param_2 + 0x10) != 0x8b40) && (*(int *)(param_2 + 0x10) != 0x8b48)) {
      return 0x502;
    }
    iVar3 = *(int *)(param_2 + 0x1c);
    goto LAB_0008e16c;
  case 0x8b85:
    if (*(int *)(param_2 + 0x10) != 0x8b40) {
      return 0x502;
    }
    uVar1 = *(uint *)(param_2 + 0x48);
    break;
  case 0x8b86:
    if (*(int *)(param_2 + 0x10) != 0x8b40) {
      return 0x502;
    }
    uVar1 = *(uint *)(param_2 + 0x28);
    break;
  case 0x8b87:
    if (*(int *)(param_2 + 0x10) != 0x8b40) {
      return 0x502;
    }
    uVar1 = *(uint *)(param_2 + 0x2c);
    break;
  case 0x8b88:
    if (*(int *)(param_2 + 0x10) != 0x8b48) {
      return 0x502;
    }
    iVar3 = *(int *)(param_2 + 0x28);
LAB_0008e16c:
    uVar1 = iVar3 + 1;
    uVar2 = 0;
    if (iVar3 == 0) {
LAB_0008e178:
      *param_4 = uVar2;
      return 0;
    }
    break;
  case 0x8b89:
    if (*(int *)(param_2 + 0x10) != 0x8b40) {
      return 0x502;
    }
    uVar1 = *(uint *)(param_2 + 0x34);
    break;
  case 0x8b8a:
    if (*(int *)(param_2 + 0x10) != 0x8b40) {
      return 0x502;
    }
    uVar1 = *(uint *)(param_2 + 0x38);
  }
  *param_4 = uVar1;
  return 0;
}

/* _glGetObjectParameterfvARB_Exec @ 0x8e1c8 (300 bytes) */
void _glGetObjectParameterfvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  float *param_4;
{
  int iVar1;
  uint local_28 [5];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar1 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar1 + 0x8028);
      iVar1 = *(int *)(param_1 + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1 + 0x6018,param_2);
    if (iVar1 != 0) {
      iVar1 = ((int (*)())_gleGetObjectParameter)(param_1,iVar1,param_3,local_28);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (iVar1 != 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        *(int *)(param_1 + 0x7574) = iVar1;
        return;
      }
      *param_4 = (float)((double)CONCAT44(0x43300000,local_28[0] ^ 0x80000000) - DOUBLE_00108d58);
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glGetObjectParameterivARB_Exec @ 0x8e2f4 (256 bytes) */
void _glGetObjectParameterivARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 local_30 [7];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar1 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar1 + 0x8028);
      iVar1 = *(int *)(param_1 + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1 + 0x6018,param_2);
    if (iVar1 != 0) {
      iVar1 = ((int (*)())_gleGetObjectParameter)(param_1,iVar1,param_3,local_30);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (iVar1 != 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        *(int *)(param_1 + 0x7574) = iVar1;
        return;
      }
      *param_4 = local_30[0];
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return;
}

/* _glGetShaderiv_Exec @ 0x8e3f4 (348 bytes) */
void _glGetShaderiv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_30 [7];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_0008e4c4;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b48) {
      if (param_3 == 0x8b4e) {
        param_3 = 0x8b4f;
      }
      iVar2 = ((int (*)())_gleGetObjectParameter)(param_1,iVar2,param_3,local_30);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (iVar2 != 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        *(int *)(param_1 + 0x7574) = iVar2;
        return;
      }
      *param_4 = local_30[0];
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0008e4c4:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetProgramiv_Exec @ 0x8e550 (324 bytes) */
void _glGetProgramiv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 *param_4;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_30 [7];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_0008e620;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b40) {
      iVar2 = ((int (*)())_gleGetObjectParameter)(param_1,iVar2,param_3,local_30);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (iVar2 != 0) {
        if (*(int *)(param_1 + 0x7574) != 0) {
          return;
        }
        *(int *)(param_1 + 0x7574) = iVar2;
        return;
      }
      *param_4 = local_30[0];
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0008e620:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetInfoLogARB_Exec @ 0x8e694 (356 bytes) */
void _glGetInfoLogARB_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  size_t *param_4;
  char *param_5;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_0008e778;
    }
    if ((*(int *)(iVar2 + 0x10) == 0x8b40) || (*(int *)(iVar2 + 0x10) == 0x8b48)) {
      uVar3 = *(uint *)(iVar2 + 0x1c);
      if (param_3 - 1U < *(uint *)(iVar2 + 0x1c)) {
        uVar3 = param_3 - 1U;
      }
      _strncpy(param_5,*(char **)(iVar2 + 0x18),uVar3);
      param_5[uVar3] = '\0';
      if (param_4 != (size_t *)0x0) {
        *param_4 = uVar3;
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0008e778:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetShaderInfoLog_Exec @ 0x8e7f8 (340 bytes) */
void _glGetShaderInfoLog_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  size_t *param_4;
  char *param_5;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_0008e8cc;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b48) {
      uVar3 = *(uint *)(iVar2 + 0x1c);
      if (param_3 - 1U < *(uint *)(iVar2 + 0x1c)) {
        uVar3 = param_3 - 1U;
      }
      _strncpy(param_5,*(char **)(iVar2 + 0x18),uVar3);
      param_5[uVar3] = '\0';
      if (param_4 != (size_t *)0x0) {
        *param_4 = uVar3;
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0008e8cc:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetProgramInfoLog_Exec @ 0x8e94c (340 bytes) */
void _glGetProgramInfoLog_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  size_t *param_4;
  char *param_5;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_0008ea20;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b40) {
      uVar3 = *(uint *)(iVar2 + 0x1c);
      if (param_3 - 1U < *(uint *)(iVar2 + 0x1c)) {
        uVar3 = param_3 - 1U;
      }
      _strncpy(param_5,*(char **)(iVar2 + 0x18),uVar3);
      param_5[uVar3] = '\0';
      if (param_4 != (size_t *)0x0) {
        *param_4 = uVar3;
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0008ea20:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glIsShader_Exec @ 0x8eaa0 (216 bytes) */
int _glIsShader_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  bool bVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 != 0) {
      bVar1 = *(int *)(iVar2 + 0x10) == 0x8b48;
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return bVar1;
      }
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return bVar1;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return false;
}

/* _glIsProgram_Exec @ 0x8eb78 (216 bytes) */
int _glIsProgram_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  bool bVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 != 0) {
      bVar1 = *(int *)(iVar2 + 0x10) == 0x8b40;
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return bVar1;
      }
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return bVar1;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return false;
}

/* _glGetAttachedObjectsARB_Exec @ 0x8ec50 (364 bytes) */
void _glGetAttachedObjectsARB_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int *param_4;
  int param_5;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar3 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar3 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar3 + 0x8028);
      iVar3 = *(int *)(param_1 + 0x5148);
    }
    iVar3 = _gleLookupHashObject(iVar3 + 0x6018,param_2);
    if (iVar3 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x501;
      goto LAB_0008ed28;
    }
    if (*(int *)(iVar3 + 0x10) == 0x8b40) {
      if ((0 < *(int *)(iVar3 + 0x48)) && (0 < param_3)) {
        do {
          iVar1 = iVar4 * 4;
          iVar4 = iVar4 + 1;
          *(undefined4 *)(iVar1 + param_5) =
               *(undefined4 *)(*(int *)(iVar1 + *(int *)(iVar3 + 0x44)) + 4);
          if (*(int *)(iVar3 + 0x48) <= iVar4) break;
        } while (iVar4 < param_3);
      }
      if (param_4 != (int *)0x0) {
        *param_4 = iVar4;
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x502;
LAB_0008ed28:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glGetUniformLocationARB_Exec @ 0x8edbc (296 bytes) */
int _glGetUniformLocationARB_Exec(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0xffffffff;
      }
      uVar1 = 0x501;
      goto LAB_0008ee94;
    }
    if ((*(int *)(iVar2 + 0x10) == 0x8b40) && (*(char *)(iVar2 + 0x3c) == '\x01')) {
      uVar1 = _ShGetUniformLocation(*(undefined4 *)(iVar2 + 0x40),param_3);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
        return uVar1;
      }
      return uVar1;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0xffffffff;
  }
  uVar1 = 0x502;
LAB_0008ee94:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0xffffffff;
}

/* _glGetActiveUniformARB_Exec @ 0x8eee4 (348 bytes) */
void _glGetActiveUniformARB_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 == 0) {
LAB_0008ef74:
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_0008eff8;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b40) {
      if (*(uint *)(iVar2 + 0x28) <= param_3) goto LAB_0008ef74;
      iVar2 = _ShGetActiveUniform(*(undefined4 *)(iVar2 + 0x40),param_3,param_4,param_5,param_6,
                                  param_7,param_8);
      if (iVar2 != 0) {
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
        return;
      }
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0008eff8:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetUniformfvARB_Exec @ 0x8f040 (1316 bytes) */
void _glGetUniformfvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  float *param_4;
{
  float fVar1;
  double dVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  undefined1 auStack_38 [4];
  uint local_34;
  undefined2 local_30 [14];
  
  local_30[0] = 0;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_0008f154:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
LAB_0008f164:
    *(undefined4 *)(param_1 + 0x7574) = uVar3;
    return;
  }
  iVar4 = *(int *)(param_1 + 0x5148);
  if (*(char *)(iVar4 + 0x8024) != '\0') {
    _pthread_mutex_lock(iVar4 + 0x8028);
    iVar4 = *(int *)(param_1 + 0x5148);
  }
  iVar4 = _gleLookupHashObject(iVar4 + 0x6018,param_2);
  if (iVar4 == 0) {
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
    goto LAB_0008f164;
  }
  if ((((*(int *)(iVar4 + 0x10) != 0x8b40) || (*(char *)(iVar4 + 0x3c) != '\x01')) ||
      (*(int *)(iVar4 + 0x30) <= param_3)) ||
     ((param_3 == -1 ||
      (iVar5 = _ShGetUniformTypeInfo
                         (*(undefined4 *)(iVar4 + 0x40),param_3,auStack_38,&local_34,local_30),
      dVar2 = DOUBLE_00108d58, iVar5 == 0)))) {
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    goto LAB_0008f154;
  }
  iVar5 = *(int *)(iVar4 + 0x4c);
  iVar4 = param_3 * 0x10;
  puVar6 = (uint *)(iVar5 + iVar4);
  if (local_34 == 0x8b56) {
LAB_0008f414:
    fVar1 = (float)((double)CONCAT44(0x43300000,*puVar6 ^ 0x80000000) - DOUBLE_00108d58);
  }
  else {
    if (0x8b56 < local_34) {
      if (local_34 == 0x8b5a) {
        *param_4 = *(float *)(iVar5 + iVar4);
        param_4[1] = GH_U2F((unsigned int)(puVar6[1]));
        param_4[2] = GH_U2F((unsigned int)(puVar6[4]));
        fVar1 = GH_U2F((unsigned int)(puVar6[5]));
LAB_0008f460:
        param_4[3] = fVar1;
        goto LAB_0008f534;
      }
      if (local_34 < 0x8b5b) {
        if (local_34 != 0x8b58) {
          if (0x8b58 < local_34) {
LAB_0008f290:
            *param_4 = (float)((double)CONCAT44(0x43300000,*puVar6 ^ 0x80000000) - DOUBLE_00108d58);
            param_4[1] = (float)((double)CONCAT44(0x43300000,puVar6[1] ^ 0x80000000) - dVar2);
            param_4[2] = (float)((double)CONCAT44(0x43300000,puVar6[2] ^ 0x80000000) - dVar2);
            param_4[3] = (float)((double)CONCAT44(0x43300000,puVar6[3] ^ 0x80000000) - dVar2);
            goto LAB_0008f534;
          }
          goto LAB_0008f3bc;
        }
LAB_0008f338:
        *param_4 = (float)((double)CONCAT44(0x43300000,*puVar6 ^ 0x80000000) - DOUBLE_00108d58);
        param_4[1] = (float)((double)CONCAT44(0x43300000,puVar6[1] ^ 0x80000000) - dVar2);
        fVar1 = (float)((double)CONCAT44(0x43300000,puVar6[2] ^ 0x80000000) - dVar2);
        goto LAB_0008f3a0;
      }
      if (local_34 == 0x8b5c) {
        *param_4 = *(float *)(iVar5 + iVar4);
        param_4[1] = GH_U2F((unsigned int)(puVar6[1]));
        param_4[2] = GH_U2F((unsigned int)(puVar6[2]));
        param_4[3] = GH_U2F((unsigned int)(puVar6[3]));
        param_4[4] = GH_U2F((unsigned int)(puVar6[4]));
        param_4[5] = GH_U2F((unsigned int)(puVar6[5]));
        param_4[6] = GH_U2F((unsigned int)(puVar6[6]));
        param_4[7] = GH_U2F((unsigned int)(puVar6[7]));
        param_4[8] = GH_U2F((unsigned int)(puVar6[8]));
        param_4[9] = GH_U2F((unsigned int)(puVar6[9]));
        param_4[10] = GH_U2F((unsigned int)(puVar6[10]));
        param_4[0xb] = GH_U2F((unsigned int)(puVar6[0xb]));
        param_4[0xc] = GH_U2F((unsigned int)(puVar6[0xc]));
        param_4[0xd] = GH_U2F((unsigned int)(puVar6[0xd]));
        param_4[0xe] = GH_U2F((unsigned int)(puVar6[0xe]));
        param_4[0xf] = GH_U2F((unsigned int)(puVar6[0xf]));
        goto LAB_0008f534;
      }
      if (local_34 < 0x8b5c) {
        *param_4 = *(float *)(iVar5 + iVar4);
        param_4[1] = GH_U2F((unsigned int)(puVar6[1]));
        param_4[2] = GH_U2F((unsigned int)(puVar6[2]));
        param_4[3] = GH_U2F((unsigned int)(puVar6[4]));
        param_4[4] = GH_U2F((unsigned int)(puVar6[5]));
        param_4[5] = GH_U2F((unsigned int)(puVar6[6]));
        param_4[6] = GH_U2F((unsigned int)(puVar6[8]));
        param_4[7] = GH_U2F((unsigned int)(puVar6[9]));
        param_4[8] = GH_U2F((unsigned int)(puVar6[10]));
        goto LAB_0008f534;
      }
      if (0x8b64 < local_34) goto LAB_0008f534;
      goto LAB_0008f414;
    }
    if (local_34 == 0x8b51) {
      *param_4 = *(float *)(iVar5 + iVar4);
      param_4[1] = GH_U2F((unsigned int)(puVar6[1]));
      fVar1 = GH_U2F((unsigned int)(puVar6[2]));
LAB_0008f3a0:
      param_4[2] = fVar1;
      goto LAB_0008f534;
    }
    if (0x8b51 < local_34) {
      if (local_34 == 0x8b53) {
LAB_0008f3bc:
        *param_4 = (float)((double)CONCAT44(0x43300000,*puVar6 ^ 0x80000000) - DOUBLE_00108d58);
        param_4[1] = (float)((double)CONCAT44(0x43300000,puVar6[1] ^ 0x80000000) - dVar2);
        goto LAB_0008f534;
      }
      if (0x8b52 < local_34) {
        if (local_34 != 0x8b54) {
          if (local_34 != 0x8b55) goto LAB_0008f534;
          goto LAB_0008f290;
        }
        goto LAB_0008f338;
      }
      *param_4 = *(float *)(iVar5 + iVar4);
      param_4[1] = GH_U2F((unsigned int)(puVar6[1]));
      param_4[2] = GH_U2F((unsigned int)(puVar6[2]));
      fVar1 = GH_U2F((unsigned int)(puVar6[3]));
      goto LAB_0008f460;
    }
    if (local_34 != 0x1406) {
      if (0x1406 < local_34) {
        if (local_34 == 0x8b50) {
          *param_4 = *(float *)(iVar5 + iVar4);
          param_4[1] = GH_U2F((unsigned int)(puVar6[1]));
        }
        goto LAB_0008f534;
      }
      if (local_34 != 0x1404) goto LAB_0008f534;
      goto LAB_0008f414;
    }
    fVar1 = *(float *)(iVar5 + iVar4);
  }
  *param_4 = fVar1;
LAB_0008f534:
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
    return;
  }
  _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
  return;
}

/* _glGetUniformivARB_Exec @ 0x8f564 (1628 bytes) */
void _glGetUniformivARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int *param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  float fVar5;
  undefined1 auStack_38 [4];
  uint local_34;
  undefined2 local_30 [14];
  
  local_30[0] = 0;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
LAB_0008f670:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
LAB_0008f680:
    *(undefined4 *)(param_1 + 0x7574) = uVar1;
    return;
  }
  iVar2 = *(int *)(param_1 + 0x5148);
  if (*(char *)(iVar2 + 0x8024) != '\0') {
    _pthread_mutex_lock(iVar2 + 0x8028);
    iVar2 = *(int *)(param_1 + 0x5148);
  }
  iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
  if (iVar2 == 0) {
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
    goto LAB_0008f680;
  }
  if ((((*(int *)(iVar2 + 0x10) != 0x8b40) || (*(char *)(iVar2 + 0x3c) != '\x01')) ||
      (*(int *)(iVar2 + 0x30) <= param_3)) ||
     ((param_3 == -1 ||
      (iVar3 = _ShGetUniformTypeInfo
                         (*(undefined4 *)(iVar2 + 0x40),param_3,auStack_38,&local_34,local_30),
      iVar3 == 0)))) {
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    goto LAB_0008f670;
  }
  iVar3 = *(int *)(iVar2 + 0x4c);
  iVar2 = param_3 * 0x10;
  piVar4 = (int *)(iVar3 + iVar2);
  if (local_34 == 0x8b56) {
LAB_0008f8c4:
    iVar2 = *piVar4;
  }
  else {
    if (0x8b56 < local_34) {
      if (local_34 == 0x8b5a) {
        fVar5 = _roundf(*(float *)(iVar3 + iVar2));
        *param_4 = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
        param_4[1] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[4])));
        param_4[2] = (int)fVar5;
        fVar5 = GH_U2F((unsigned int)(piVar4[5]));
LAB_0008f91c:
        fVar5 = _roundf(fVar5);
        param_4[3] = (int)fVar5;
        goto LAB_0008fb90;
      }
      if (local_34 < 0x8b5b) {
        if (local_34 != 0x8b58) {
          if (0x8b58 < local_34) {
LAB_0008f7dc:
            *param_4 = *piVar4;
            param_4[1] = piVar4[1];
            param_4[2] = piVar4[2];
            param_4[3] = piVar4[3];
            goto LAB_0008fb90;
          }
          goto LAB_0008f898;
        }
LAB_0008f848:
        *param_4 = *piVar4;
        param_4[1] = piVar4[1];
        iVar2 = piVar4[2];
        goto LAB_0008f85c;
      }
      if (local_34 == 0x8b5c) {
        fVar5 = _roundf(*(float *)(iVar3 + iVar2));
        *param_4 = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
        param_4[1] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[2])));
        param_4[2] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[3])));
        param_4[3] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[4])));
        param_4[4] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[5])));
        param_4[5] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[6])));
        param_4[6] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[7])));
        param_4[7] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[8])));
        param_4[8] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[9])));
        param_4[9] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[10])));
        param_4[10] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[0xb])));
        param_4[0xb] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[0xc])));
        param_4[0xc] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[0xd])));
        param_4[0xd] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[0xe])));
        param_4[0xe] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[0xf])));
        param_4[0xf] = (int)fVar5;
        goto LAB_0008fb90;
      }
      if (local_34 < 0x8b5c) {
        fVar5 = _roundf(*(float *)(iVar3 + iVar2));
        *param_4 = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
        param_4[1] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[2])));
        param_4[2] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[4])));
        param_4[3] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[5])));
        param_4[4] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[6])));
        param_4[5] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[8])));
        param_4[6] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[9])));
        param_4[7] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[10])));
        param_4[8] = (int)fVar5;
        goto LAB_0008fb90;
      }
      if (0x8b64 < local_34) goto LAB_0008fb90;
      goto LAB_0008f8c4;
    }
    if (local_34 == 0x8b51) {
      fVar5 = _roundf(*(float *)(iVar3 + iVar2));
      *param_4 = (int)fVar5;
      fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
      param_4[1] = (int)fVar5;
      fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[2])));
      iVar2 = (int)fVar5;
LAB_0008f85c:
      param_4[2] = iVar2;
      goto LAB_0008fb90;
    }
    if (0x8b51 < local_34) {
      if (local_34 == 0x8b53) {
LAB_0008f898:
        *param_4 = *piVar4;
        param_4[1] = piVar4[1];
        goto LAB_0008fb90;
      }
      if (0x8b52 < local_34) {
        if (local_34 != 0x8b54) {
          if (local_34 != 0x8b55) goto LAB_0008fb90;
          goto LAB_0008f7dc;
        }
        goto LAB_0008f848;
      }
      fVar5 = _roundf(*(float *)(iVar3 + iVar2));
      *param_4 = (int)fVar5;
      fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
      param_4[1] = (int)fVar5;
      fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[2])));
      param_4[2] = (int)fVar5;
      fVar5 = GH_U2F((unsigned int)(piVar4[3]));
      goto LAB_0008f91c;
    }
    if (local_34 != 0x1406) {
      if (0x1406 < local_34) {
        if (local_34 == 0x8b50) {
          fVar5 = _roundf(*(float *)(iVar3 + iVar2));
          *param_4 = (int)fVar5;
          fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
          param_4[1] = (int)fVar5;
        }
        goto LAB_0008fb90;
      }
      if (local_34 != 0x1404) goto LAB_0008fb90;
      goto LAB_0008f8c4;
    }
    fVar5 = _roundf(*(float *)(iVar3 + iVar2));
    iVar2 = (int)fVar5;
  }
  *param_4 = iVar2;
LAB_0008fb90:
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
    return;
  }
  _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
  return;
}

/* _glGetShaderSourceARB_Exec @ 0x8fbc0 (340 bytes) */
void _glGetShaderSourceARB_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  size_t *param_4;
  char *param_5;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_0008fc94;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b48) {
      uVar3 = *(uint *)(iVar2 + 0x28);
      if (param_3 - 1U < *(uint *)(iVar2 + 0x28)) {
        uVar3 = param_3 - 1U;
      }
      _strncpy(param_5,*(char **)(iVar2 + 0x2c),uVar3);
      param_5[uVar3] = '\0';
      if (param_4 != (size_t *)0x0) {
        *param_4 = uVar3;
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_0008fc94:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glBindAttribLocationARB_Exec @ 0x8fd14 (360 bytes) */
void _glBindAttribLocationARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  uint param_3;
  char *param_4;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 != 0) {
      if ((*(int *)(iVar2 + 0x10) != 0x8b40) ||
         ((((param_4 != (char *)0x0 && (*param_4 == 'g')) && (param_4[1] == 'l')) &&
          (param_4[2] == '_')))) {
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
        }
        goto LAB_0008fddc;
      }
      if (param_3 < 0x10) {
        _ShAttributeBindingRequest(*(undefined4 *)(iVar2 + 0x40),param_3,param_4);
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
        return;
      }
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x501;
  }
  else {
LAB_0008fddc:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetAttribLocationARB_Exec @ 0x8fe7c (296 bytes) */
int _glGetAttribLocationARB_Exec(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return 0xffffffff;
      }
      uVar1 = 0x501;
      goto LAB_0008ff54;
    }
    if ((*(int *)(iVar2 + 0x10) == 0x8b40) && (*(char *)(iVar2 + 0x3c) == '\x01')) {
      uVar1 = _ShGetAttribLocation(*(undefined4 *)(iVar2 + 0x40),param_3);
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
        return uVar1;
      }
      return uVar1;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return 0xffffffff;
  }
  uVar1 = 0x502;
LAB_0008ff54:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0xffffffff;
}

/* _glGetActiveAttribARB_Exec @ 0x8ffa4 (348 bytes) */
void _glGetActiveAttribARB_Exec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  int iVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(param_1 + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
    if (iVar2 == 0) {
LAB_00090034:
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_000900b8;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b40) {
      if (*(uint *)(iVar2 + 0x34) <= param_3) goto LAB_00090034;
      iVar2 = _ShGetActiveAttrib(*(undefined4 *)(iVar2 + 0x40),param_3,param_4,param_5,param_6,
                                 param_7,param_8);
      if (iVar2 != 0) {
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
        return;
      }
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_000900b8:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glGetPointerv_Exec @ 0x90100 (404 bytes) */
void _glGetPointerv_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x4a60);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8092) {
      uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x53d8) * 0x18 + iVar2 + 0xf0);
      goto LAB_00090210;
    }
    if (param_2 < 0x8093) {
      if (param_2 == 0x808e) {
        uVar1 = *(undefined4 *)(iVar2 + 0x30);
LAB_00090210:
        *param_3 = uVar1;
        return;
      }
      if (0x808e < param_2) {
        if (param_2 == 0x8090) {
          uVar1 = *(undefined4 *)(iVar2 + 0x60);
        }
        else if (param_2 < 0x8091) {
          uVar1 = *(undefined4 *)(iVar2 + 0x48);
        }
        else {
          uVar1 = *(undefined4 *)(param_1 + 0x48e0);
        }
        goto LAB_00090210;
      }
      if (param_2 == 0xdf0) {
        uVar1 = *(undefined4 *)(param_1 + 0x4fcc);
        goto LAB_00090210;
      }
      if (param_2 == 0xdf3) {
        uVar1 = *(undefined4 *)(param_1 + 20000);
        goto LAB_00090210;
      }
    }
    else {
      if (param_2 == 0x845d) {
        uVar1 = *(undefined4 *)(iVar2 + 0x90);
        goto LAB_00090210;
      }
      if (param_2 < 0x845e) {
        if (param_2 == 0x8093) {
          uVar1 = *(undefined4 *)(iVar2 + 0xc0);
          goto LAB_00090210;
        }
        if (param_2 == 0x8456) {
          uVar1 = *(undefined4 *)(iVar2 + 0x78);
          goto LAB_00090210;
        }
      }
      else {
        if (param_2 == 0x86ac) {
          uVar1 = *(undefined4 *)(iVar2 + 0xa8);
          goto LAB_00090210;
        }
        if (param_2 < 0x86ad) {
          if (param_2 == 0x8521) {
            uVar1 = *(undefined4 *)(iVar2 + 0x344);
            goto LAB_00090210;
          }
        }
        else if (param_2 == 0x8a0e) {
          uVar1 = *(undefined4 *)(iVar2 + 0xd8);
          goto LAB_00090210;
        }
      }
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

/* _glStencilFunc_ListExec @ 0x90294 (52 bytes) */
int _glStencilFunc_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glStencilFunc_Exec(param_1,*param_2,param_2[1],param_2[2]);
  return 0xc;
}

/* _glStencilOp_ListExec @ 0x902c8 (52 bytes) */
int _glStencilOp_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glStencilOp_Exec(param_1,*param_2,param_2[1],param_2[2]);
  return 0xc;
}

/* _glActiveStencilFace_ListExec @ 0x902fc (80 bytes) */
int _glActiveStencilFace_ListExec(param_1, param_2)
  int param_1;
  uint *param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (*param_2 < 2) {
      *(char *)(param_1 + 0x7583) = (char)*param_2;
      return 4;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 4;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 4;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 4;
}

/* _glActiveStencilFace_Comp @ 0x9034c (80 bytes) */
int _glActiveStencilFace_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int *piVar1;
  
  piVar1 = (int *)_gleAddListItem(param_1,PTR__glActiveStencilFace_ListExec_00110314,4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2 + -0x404;
  }
  return piVar1;
}

/* _glActiveStencilFace_Exec @ 0x9039c (76 bytes) */
void _glActiveStencilFace_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 - 0x404U < 2) {
      *(char *)(param_1 + 0x7583) = (char)(param_2 - 0x404U);
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

/* _glActiveStencilFace_CompExec @ 0x903e8 (56 bytes) */
void _glActiveStencilFace_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glActiveStencilFace_Comp)(param_1,param_2);
  ((int (*)())_glActiveStencilFace_Exec)(param_1,param_2);
  return;
}

/* _glStencilFuncSeparateATI_ListExec @ 0x90420 (56 bytes) */
int _glStencilFuncSeparateATI_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glStencilFuncSeparateATI_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3]);
  return 0x10;
}

/* _glStencilFuncSeparateATI_Comp @ 0x90458 (100 bytes) */
int _glStencilFuncSeparateATI_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glStencilFuncSeparateATI_ListExec_00110310,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = param_5;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
  }
  return puVar1;
}

/* _glStencilFuncSeparateATI_Exec @ 0x904bc (176 bytes) */
void _glStencilFuncSeparateATI_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((param_2 - 0x200U < 8) && (param_3 - 0x200U < 8)) {
      if ((int)param_4 < 0) {
        param_4 = 0;
      }
      else {
        uVar2 = 0xffffffff >> (0x20U - *(int *)(*(int *)(param_1 + 0x468c) + 0x40) & 0x3f);
        if (uVar2 < param_4) {
          param_4 = uVar2;
        }
      }
      iVar3 = (uint)*(byte *)(param_1 + 0x7583) * 0x10 + param_1;
      *(undefined4 *)(iVar3 + 0x34f8) = param_5;
      *(short *)(iVar3 + 0x3500) = (short)param_2;
      *(uint *)(iVar3 + 0x34fc) = param_4;
      *(short *)(param_1 + 0x3518) = (short)param_3;
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x10000000;
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

/* _glStencilFuncSeparateATI_CompExec @ 0x9056c (80 bytes) */
void _glStencilFuncSeparateATI_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glStencilFuncSeparateATI_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glStencilFuncSeparateATI_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glStencilOpSeparateATI_ListExec @ 0x905bc (56 bytes) */
int _glStencilOpSeparateATI_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glStencilOpSeparateATI_Exec)(param_1,*param_2,param_2[1],param_2[2],param_2[3]);
  return 0x10;
}

/* _glStencilOpSeparateATI_Comp @ 0x905f4 (100 bytes) */
int _glStencilOpSeparateATI_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glStencilOpSeparateATI_ListExec_0011030c,0x10)
  ;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = param_5;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
  }
  return puVar1;
}

/* _glStencilOpSeparateATI_Exec @ 0x90658 (336 bytes) */
void _glStencilOpSeparateATI_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  undefined4 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_000906bc;
  }
  if (param_3 < 0x1e04) {
    if (((0x1dff < param_3) || (param_3 == 0)) || (param_3 == 0x150a)) {
LAB_000906c4:
      if (param_4 < 0x1e04) {
        if (((0x1dff < param_4) || (param_4 == 0)) || (param_4 == 0x150a)) {
LAB_000906f8:
          if (param_5 < 0x1e04) {
            if (((0x1dff < param_5) || (param_5 == 0)) || (param_5 == 0x150a)) {
LAB_0009072c:
              uVar3 = (undefined2)param_3;
              uVar4 = (undefined2)param_4;
              uVar5 = (undefined2)param_5;
              if (param_2 == 0x405) {
LAB_0009078c:
                *(undefined2 *)(param_1 + 0x351a) = uVar3;
                *(undefined2 *)(param_1 + 0x351c) = uVar4;
                *(undefined2 *)(param_1 + 0x351e) = uVar5;
LAB_00090798:
                *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x10000000;
                return;
              }
              if (param_2 < 0x406) {
                if (param_2 == 0x404) {
                  iVar2 = (uint)*(byte *)(param_1 + 0x7583) * 0x10 + param_1;
                  *(undefined2 *)(iVar2 + 0x3506) = uVar5;
                  *(undefined2 *)(iVar2 + 0x3502) = uVar3;
                  *(undefined2 *)(iVar2 + 0x3504) = uVar4;
                  goto LAB_00090798;
                }
              }
              else if (param_2 == 0x408) {
                iVar2 = (uint)*(byte *)(param_1 + 0x7583) * 0x10 + param_1;
                *(undefined2 *)(iVar2 + 0x3506) = uVar5;
                *(undefined2 *)(iVar2 + 0x3502) = uVar3;
                *(undefined2 *)(iVar2 + 0x3504) = uVar4;
                goto LAB_0009078c;
              }
            }
          }
          else if (param_5 - 0x8507 < 2) goto LAB_0009072c;
        }
      }
      else if (param_4 - 0x8507 < 2) goto LAB_000906f8;
    }
  }
  else if (param_3 - 0x8507 < 2) goto LAB_000906c4;
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x500;
LAB_000906bc:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glStencilOpSeparateATI_CompExec @ 0x907a8 (80 bytes) */
void _glStencilOpSeparateATI_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glStencilOpSeparateATI_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((int (*)())_glStencilOpSeparateATI_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

