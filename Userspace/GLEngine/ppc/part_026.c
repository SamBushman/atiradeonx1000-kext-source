#include "decls.h"

/* _glUniform2fARB_ListExec @ 0x8cb60 (52 bytes) */
int _glUniform2fARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glUniform2fARB_Exec)(glContext,*listRecord,(double)GH_U2F((unsigned int)(listRecord[1])),(double)GH_U2F((unsigned int)(listRecord[2])));
  return 0xc;
}

/* _glUniform1fARB_ListExec @ 0x8cb94 (44 bytes) */
int _glUniform1fARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glUniform1fARB_Exec)(glContext,*listRecord,(double)GH_U2F((unsigned int)(listRecord[1])));
  return 8;
}

/* _glUniform4fvARB_ListExec @ 0x8cbc0 (68 bytes) */
int _glUniform4fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform4fvARB_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return listRecord[1] * 0x10 + 8;
}

/* _glUniform3fvARB_ListExec @ 0x8cc04 (68 bytes) */
int _glUniform3fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform3fvARB_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return listRecord[1] * 0xc + 8;
}

/* _glUniform2fvARB_ListExec @ 0x8cc48 (68 bytes) */
int _glUniform2fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform2fvARB_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return listRecord[1] * 8 + 8;
}

/* _glUniform1fvARB_ListExec @ 0x8cc8c (68 bytes) */
int _glUniform1fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform1fvARB_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return listRecord[1] * 4 + 8;
}

/* _glUniform4iARB_ListExec @ 0x8ccd0 (60 bytes) */
int _glUniform4iARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform4iARB_Exec(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4]);
  return 0x14;
}

/* _glUniform3iARB_ListExec @ 0x8cd0c (56 bytes) */
int _glUniform3iARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform3iARB_Exec(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3]);
  return 0x10;
}

/* _glUniform2iARB_ListExec @ 0x8cd44 (52 bytes) */
int _glUniform2iARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform2iARB_Exec(glContext,*listRecord,listRecord[1],listRecord[2]);
  return 0xc;
}

/* _glUniform1iARB_ListExec @ 0x8cd78 (44 bytes) */
int _glUniform1iARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform1iARB_Exec(glContext,*listRecord,listRecord[1]);
  return 8;
}

/* _glUniform4ivARB_ListExec @ 0x8cda4 (68 bytes) */
int _glUniform4ivARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform4ivARB_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return listRecord[1] * 0x10 + 8;
}

/* _glUniform3ivARB_ListExec @ 0x8cde8 (68 bytes) */
int _glUniform3ivARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform3ivARB_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return listRecord[1] * 0xc + 8;
}

/* _glUniform2ivARB_ListExec @ 0x8ce2c (68 bytes) */
int _glUniform2ivARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform2ivARB_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return listRecord[1] * 8 + 8;
}

/* _glUniform1ivARB_ListExec @ 0x8ce70 (68 bytes) */
int _glUniform1ivARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glUniform1ivARB_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return listRecord[1] * 4 + 8;
}

/* _glUniformMatrix2fvARB_Exec @ 0x8ceb4 (816 bytes) */
void _glUniformMatrix2fvARB_Exec(glContext, location, count, transpose, value)
  int glContext;
  int location;
  int count;
  int transpose;
  undefined4 *value;
{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int currentProgram;
  undefined4 *puVar7;
  int iVar8;
  int loopIndex2;
  int iVar9;
  int iVar10;
  int loopIndex3;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int loopIndex;
  int local_40;
  int local_3c;
  undefined2 local_38 [10];
  
  local_3c = 0;
  local_38[0] = 0;
  local_40 = 0;
  bVar3 = false;
  bVar4 = false;
  if (location != -1) {
    currentProgram = *(int *)(glContext + 0x5430);
    if ((((currentProgram == 0) || (*(int *)(currentProgram + 0x30) <= location)) || (count < 0)) ||
       ((iVar8 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&local_40,&local_3c,local_38),
        iVar8 == 0 || (local_3c != 0x8b5a)))) {
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
    }
    else if (count != 0) {
      puVar7 = (undefined4 *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
      if (count < local_40) {
        local_40 = count;
      }
      if (transpose == 0) {
        loopIndex2 = 0;
        if (0 < local_40) {
          do {
            loopIndex2 = loopIndex2 + 1;
            *puVar7 = *value;
            puVar7[1] = value[1];
            puVar7[4] = value[2];
            puVar1 = value + 3;
            value = value + 4;
            puVar7[5] = *puVar1;
            puVar7 = puVar7 + 8;
          } while (loopIndex2 < local_40);
        }
      }
      else {
        loopIndex2 = 0;
        if (0 < local_40) {
          do {
            loopIndex2 = loopIndex2 + 1;
            *puVar7 = *value;
            puVar7[4] = value[1];
            puVar7[1] = value[2];
            puVar1 = value + 3;
            value = value + 4;
            puVar7[5] = *puVar1;
            puVar7 = puVar7 + 8;
          } while (loopIndex2 < local_40);
        }
      }
      loopIndex2 = 0;
      if (0 < local_40) {
        do {
          loopIndex = 0;
          iVar10 = location << 4;
          iVar9 = location << 2;
          do {
            iVar13 = *(int *)(currentProgram + 0x20);
            iVar16 = *(int *)(iVar9 + *(int *)(iVar13 + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar12 = *(int *)(iVar13 + 0x51c);
              bVar3 = true;
              iVar14 = iVar10 + *(int *)(currentProgram + 0x4c);
              uVar11 = *(undefined4 *)(iVar14 + 0xc);
              iVar13 = iVar16 + iVar12;
              uVar5 = *(undefined4 *)(iVar14 + 4);
              uVar15 = *(undefined4 *)(iVar14 + 8);
              *(undefined4 *)(iVar16 + iVar12) = *(undefined4 *)(iVar10 + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(iVar13 + 0xc) = uVar11;
              *(undefined4 *)(iVar13 + 4) = uVar5;
              *(undefined4 *)(iVar13 + 8) = uVar15;
            }
            iVar16 = *(int *)(iVar9 + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar12 = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
              bVar4 = true;
              iVar14 = iVar10 + *(int *)(currentProgram + 0x4c);
              uVar11 = *(undefined4 *)(iVar14 + 0xc);
              iVar13 = iVar16 + iVar12;
              uVar5 = *(undefined4 *)(iVar14 + 4);
              uVar15 = *(undefined4 *)(iVar14 + 8);
              *(undefined4 *)(iVar16 + iVar12) = *(undefined4 *)(iVar10 + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(iVar13 + 0xc) = uVar11;
              *(undefined4 *)(iVar13 + 4) = uVar5;
              *(undefined4 *)(iVar13 + 8) = uVar15;
            }
            loopIndex = loopIndex + 1;
            iVar9 = iVar9 + 4;
            iVar10 = iVar10 + 0x10;
          } while (loopIndex < 2);
          loopIndex2 = loopIndex2 + 1;
          location = location + 2;
        } while (loopIndex2 < local_40);
      }
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
      if (bVar3) {
        iVar8 = glContext + 0x10000;
        loopIndex3 = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = loopIndex3 * 4;
            loopIndex3 = loopIndex3 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(currentProgram + 0x20) + 0x4e4),2);
          } while (loopIndex3 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      if (bVar4) {
        iVar8 = glContext + 0x10000;
        loopIndex3 = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = loopIndex3 * 4;
            loopIndex3 = loopIndex3 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(currentProgram + 0x24) + 0x4e4),2);
          } while (loopIndex3 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
    }
  }
  return;
}

/* _glUniformMatrix3fvARB_Exec @ 0x8d1e4 (900 bytes) */
void _glUniformMatrix3fvARB_Exec(glContext, location, count, transpose, value)
  int glContext;
  int location;
  int count;
  int transpose;
  undefined4 *value;
{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int currentProgram;
  undefined4 *puVar7;
  int iVar8;
  int loopIndex;
  int iVar9;
  int iVar10;
  int loopIndex2;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  int remaining;
  int local_40;
  int local_3c;
  undefined2 local_38 [10];
  
  local_3c = 0;
  local_38[0] = 0;
  local_40 = 0;
  bVar3 = false;
  bVar4 = false;
  if (location != -1) {
    currentProgram = *(int *)(glContext + 0x5430);
    if ((((currentProgram == 0) || (*(int *)(currentProgram + 0x30) <= location)) || (count < 0)) ||
       ((iVar8 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&local_40,&local_3c,local_38),
        iVar8 == 0 || (local_3c != 0x8b5b)))) {
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
    }
    else if (count != 0) {
      puVar7 = (undefined4 *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
      if (count < local_40) {
        local_40 = count;
      }
      if (transpose == 0) {
        loopIndex = 0;
        if (0 < local_40) {
          do {
            loopIndex = loopIndex + 1;
            *puVar7 = *value;
            puVar7[1] = value[1];
            puVar7[2] = value[2];
            puVar7[4] = value[3];
            puVar7[5] = value[4];
            puVar7[6] = value[5];
            puVar7[8] = value[6];
            puVar7[9] = value[7];
            puVar1 = value + 8;
            value = value + 9;
            puVar7[10] = *puVar1;
            puVar7 = puVar7 + 0xc;
          } while (loopIndex < local_40);
        }
      }
      else {
        loopIndex = 0;
        if (0 < local_40) {
          do {
            loopIndex = loopIndex + 1;
            *puVar7 = *value;
            puVar7[4] = value[1];
            puVar7[8] = value[2];
            puVar7[1] = value[3];
            puVar7[5] = value[4];
            puVar7[9] = value[5];
            puVar7[2] = value[6];
            puVar7[6] = value[7];
            puVar1 = value + 8;
            value = value + 9;
            puVar7[10] = *puVar1;
            puVar7 = puVar7 + 0xc;
          } while (loopIndex < local_40);
        }
      }
      loopIndex = 0;
      if (0 < local_40) {
        iVar10 = location << 4;
        do {
          remaining = 3;
          iVar9 = location << 2;
          iVar11 = iVar10;
          do {
            iVar14 = *(int *)(currentProgram + 0x20);
            iVar17 = *(int *)(iVar9 + *(int *)(iVar14 + 0x4e0));
            if (iVar17 != -1) {
              iVar17 = iVar17 * 0x10;
              iVar13 = *(int *)(iVar14 + 0x51c);
              bVar3 = true;
              iVar15 = iVar11 + *(int *)(currentProgram + 0x4c);
              uVar12 = *(undefined4 *)(iVar15 + 0xc);
              iVar14 = iVar17 + iVar13;
              uVar5 = *(undefined4 *)(iVar15 + 4);
              uVar16 = *(undefined4 *)(iVar15 + 8);
              *(undefined4 *)(iVar17 + iVar13) = *(undefined4 *)(iVar11 + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(iVar14 + 0xc) = uVar12;
              *(undefined4 *)(iVar14 + 4) = uVar5;
              *(undefined4 *)(iVar14 + 8) = uVar16;
            }
            iVar17 = *(int *)(iVar9 + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
            if (iVar17 != -1) {
              iVar17 = iVar17 * 0x10;
              iVar13 = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
              bVar4 = true;
              iVar15 = iVar11 + *(int *)(currentProgram + 0x4c);
              uVar12 = *(undefined4 *)(iVar15 + 0xc);
              iVar14 = iVar17 + iVar13;
              uVar5 = *(undefined4 *)(iVar15 + 4);
              uVar16 = *(undefined4 *)(iVar15 + 8);
              *(undefined4 *)(iVar17 + iVar13) = *(undefined4 *)(iVar11 + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(iVar14 + 0xc) = uVar12;
              *(undefined4 *)(iVar14 + 4) = uVar5;
              *(undefined4 *)(iVar14 + 8) = uVar16;
            }
            iVar9 = iVar9 + 4;
            iVar11 = iVar11 + 0x10;
            remaining = remaining + -1;
          } while (remaining != 0);
          loopIndex = loopIndex + 1;
          location = location + 3;
          iVar10 = iVar10 + 0x30;
        } while (loopIndex < local_40);
      }
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
      if (bVar3) {
        iVar8 = glContext + 0x10000;
        loopIndex2 = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = loopIndex2 * 4;
            loopIndex2 = loopIndex2 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(currentProgram + 0x20) + 0x4e4),2);
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      if (bVar4) {
        iVar8 = glContext + 0x10000;
        loopIndex2 = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = loopIndex2 * 4;
            loopIndex2 = loopIndex2 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(currentProgram + 0x24) + 0x4e4),2);
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
    }
  }
  return;
}

/* _glUniformMatrix4fvARB_Exec @ 0x8d568 (1004 bytes) */
void _glUniformMatrix4fvARB_Exec(glContext, location, count, transpose, value)
  int glContext;
  int location;
  int count;
  int transpose;
  undefined4 *value;
{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int currentProgram;
  undefined4 *puVar7;
  int iVar8;
  int loopIndex;
  int iVar9;
  int iVar10;
  int loopIndex2;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  int iVar16;
  int remaining;
  int local_40;
  int local_3c;
  undefined2 local_38 [10];
  
  local_3c = 0;
  local_38[0] = 0;
  local_40 = 0;
  bVar3 = false;
  bVar4 = false;
  if (location != -1) {
    currentProgram = *(int *)(glContext + 0x5430);
    if ((((currentProgram == 0) || (*(int *)(currentProgram + 0x30) <= location)) || (count < 0)) ||
       ((iVar8 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&local_40,&local_3c,local_38),
        iVar8 == 0 || (local_3c != 0x8b5c)))) {
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
    }
    else if (count != 0) {
      puVar7 = (undefined4 *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
      if (count < local_40) {
        local_40 = count;
      }
      if (transpose == 0) {
        loopIndex = 0;
        if (0 < local_40) {
          do {
            loopIndex = loopIndex + 1;
            *puVar7 = *value;
            puVar7[1] = value[1];
            puVar7[2] = value[2];
            puVar7[3] = value[3];
            puVar7[4] = value[4];
            puVar7[5] = value[5];
            puVar7[6] = value[6];
            puVar7[7] = value[7];
            puVar7[8] = value[8];
            puVar7[9] = value[9];
            puVar7[10] = value[10];
            puVar7[0xb] = value[0xb];
            puVar7[0xc] = value[0xc];
            puVar7[0xd] = value[0xd];
            puVar7[0xe] = value[0xe];
            puVar1 = value + 0xf;
            value = value + 0x10;
            puVar7[0xf] = *puVar1;
            puVar7 = puVar7 + 0x10;
          } while (loopIndex < local_40);
        }
      }
      else {
        loopIndex = 0;
        if (0 < local_40) {
          do {
            loopIndex = loopIndex + 1;
            *puVar7 = *value;
            puVar7[4] = value[1];
            puVar7[8] = value[2];
            puVar7[0xc] = value[3];
            puVar7[1] = value[4];
            puVar7[5] = value[5];
            puVar7[9] = value[6];
            puVar7[0xd] = value[7];
            puVar7[2] = value[8];
            puVar7[6] = value[9];
            puVar7[10] = value[10];
            puVar7[0xe] = value[0xb];
            puVar7[3] = value[0xc];
            puVar7[7] = value[0xd];
            puVar7[0xb] = value[0xe];
            puVar1 = value + 0xf;
            value = value + 0x10;
            puVar7[0xf] = *puVar1;
            puVar7 = puVar7 + 0x10;
          } while (loopIndex < local_40);
        }
      }
      loopIndex = 0;
      if (0 < local_40) {
        do {
          iVar10 = location << 4;
          remaining = 4;
          iVar9 = location << 2;
          do {
            iVar13 = *(int *)(currentProgram + 0x20);
            iVar16 = *(int *)(iVar9 + *(int *)(iVar13 + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar12 = *(int *)(iVar13 + 0x51c);
              bVar3 = true;
              iVar14 = iVar10 + *(int *)(currentProgram + 0x4c);
              uVar11 = *(undefined4 *)(iVar14 + 0xc);
              iVar13 = iVar16 + iVar12;
              uVar5 = *(undefined4 *)(iVar14 + 4);
              uVar15 = *(undefined4 *)(iVar14 + 8);
              *(undefined4 *)(iVar16 + iVar12) = *(undefined4 *)(iVar10 + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(iVar13 + 0xc) = uVar11;
              *(undefined4 *)(iVar13 + 4) = uVar5;
              *(undefined4 *)(iVar13 + 8) = uVar15;
            }
            iVar16 = *(int *)(iVar9 + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar12 = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
              bVar4 = true;
              iVar14 = iVar10 + *(int *)(currentProgram + 0x4c);
              uVar11 = *(undefined4 *)(iVar14 + 0xc);
              iVar13 = iVar16 + iVar12;
              uVar5 = *(undefined4 *)(iVar14 + 4);
              uVar15 = *(undefined4 *)(iVar14 + 8);
              *(undefined4 *)(iVar16 + iVar12) = *(undefined4 *)(iVar10 + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(iVar13 + 0xc) = uVar11;
              *(undefined4 *)(iVar13 + 4) = uVar5;
              *(undefined4 *)(iVar13 + 8) = uVar15;
            }
            iVar9 = iVar9 + 4;
            iVar10 = iVar10 + 0x10;
            remaining = remaining + -1;
          } while (remaining != 0);
          loopIndex = loopIndex + 1;
          location = location + 4;
        } while (loopIndex < local_40);
      }
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
      if (bVar3) {
        iVar8 = glContext + 0x10000;
        loopIndex2 = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = loopIndex2 * 4;
            loopIndex2 = loopIndex2 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(currentProgram + 0x20) + 0x4e4),2);
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      if (bVar4) {
        iVar8 = glContext + 0x10000;
        loopIndex2 = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            piVar2 = (int *)(iVar8 + -0x777c);
            iVar9 = loopIndex2 * 4;
            loopIndex2 = loopIndex2 + 1;
            puVar7 = (undefined4 *)(iVar8 + -0x7a54);
            iVar8 = iVar8 + 0x2e0;
            (**(code **)(*piVar2 + 0x194))
                      (*puVar7,*(undefined4 *)(iVar9 + *(int *)(currentProgram + 0x24) + 0x4e4),2);
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
    }
  }
  return;
}

/* _glUniformMatrix2fvARB_Comp @ 0x8d954 (228 bytes) */
int _glUniformMatrix2fvARB_Comp(glContext, location, count, transpose, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  int transpose;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniformMatrix2fvARB_ListExec_001102c0,count * 0x10 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = count;
    *puVar2 = location;
    puVar2 = puVar2 + 2;
    loopIndex = 0;
    if (transpose == 0) {
      while( true ) {
        *puVar2 = *value;
        puVar2[1] = value[1];
        puVar2[2] = value[2];
        puVar2[3] = value[3];
        if (loopIndex == count + -1) break;
        puVar2 = puVar2 + 4;
        value = value + 4;
        loopIndex = loopIndex + 1;
      }
    }
    else {
      while( true ) {
        *puVar2 = *value;
        puVar2[2] = value[1];
        puVar2[1] = value[2];
        puVar2[3] = value[3];
        if (loopIndex == count + -1) break;
        puVar2 = puVar2 + 4;
        value = value + 4;
        loopIndex = loopIndex + 1;
      }
    }
  }
  return puVar2;
}

/* _glUniformMatrix3fvARB_Comp @ 0x8da38 (308 bytes) */
int _glUniformMatrix3fvARB_Comp(glContext, location, count, transpose, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  int transpose;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniformMatrix3fvARB_ListExec_001102bc,count * 0x24 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = count;
    *puVar2 = location;
    puVar2 = puVar2 + 2;
    loopIndex = 0;
    if (transpose == 0) {
      while( true ) {
        *puVar2 = *value;
        puVar2[1] = value[1];
        puVar2[2] = value[2];
        puVar2[3] = value[3];
        puVar2[4] = value[4];
        puVar2[5] = value[5];
        puVar2[6] = value[6];
        puVar2[7] = value[7];
        puVar2[8] = value[8];
        if (loopIndex == count + -1) break;
        puVar2 = puVar2 + 9;
        value = value + 9;
        loopIndex = loopIndex + 1;
      }
    }
    else {
      while( true ) {
        *puVar2 = *value;
        puVar2[3] = value[1];
        puVar2[6] = value[2];
        puVar2[1] = value[3];
        puVar2[4] = value[4];
        puVar2[7] = value[5];
        puVar2[2] = value[6];
        puVar2[5] = value[7];
        puVar2[8] = value[8];
        if (loopIndex == count + -1) break;
        puVar2 = puVar2 + 9;
        value = value + 9;
        loopIndex = loopIndex + 1;
      }
    }
  }
  return puVar2;
}

/* _glUniformMatrix4fvARB_Comp @ 0x8db6c (420 bytes) */
int _glUniformMatrix4fvARB_Comp(glContext, location, count, transpose, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  int transpose;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniformMatrix4fvARB_ListExec_001102b8,count * 0x30 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = count;
    *puVar2 = location;
    puVar2 = puVar2 + 2;
    loopIndex = 0;
    if (transpose == 0) {
      while( true ) {
        *puVar2 = *value;
        puVar2[1] = value[1];
        puVar2[2] = value[2];
        puVar2[3] = value[3];
        puVar2[4] = value[4];
        puVar2[5] = value[5];
        puVar2[6] = value[6];
        puVar2[7] = value[7];
        puVar2[8] = value[8];
        puVar2[9] = value[9];
        puVar2[10] = value[10];
        puVar2[0xb] = value[0xb];
        puVar2[0xc] = value[0xc];
        puVar2[0xd] = value[0xd];
        puVar2[0xe] = value[0xe];
        puVar2[0xf] = value[0xf];
        if (loopIndex == count + -1) break;
        puVar2 = puVar2 + 0xc;
        value = value + 0xc;
        loopIndex = loopIndex + 1;
      }
    }
    else {
      while( true ) {
        *puVar2 = *value;
        puVar2[4] = value[1];
        puVar2[8] = value[2];
        puVar2[0xc] = value[3];
        puVar2[1] = value[4];
        puVar2[5] = value[5];
        puVar2[9] = value[6];
        puVar2[0xd] = value[7];
        puVar2[2] = value[8];
        puVar2[6] = value[9];
        puVar2[10] = value[10];
        puVar2[0xe] = value[0xb];
        puVar2[3] = value[0xc];
        puVar2[7] = value[0xd];
        puVar2[0xb] = value[0xe];
        puVar2[0xf] = value[0xf];
        if (loopIndex == count + -1) break;
        puVar2 = puVar2 + 0xc;
        value = value + 0xc;
        loopIndex = loopIndex + 1;
      }
    }
  }
  return puVar2;
}

/* _glUniformMatrix2fvARB_CompExec @ 0x8dd10 (80 bytes) */
void _glUniformMatrix2fvARB_CompExec(glContext, location, count, transpose, value)
  undefined4 glContext;
  undefined4 location;
  undefined4 count;
  undefined4 transpose;
  undefined4 value;
{
  ((int (*)())_glUniformMatrix2fvARB_Comp)(glContext,location,count,transpose,value);
  ((void (*)())_glUniformMatrix2fvARB_Exec)(glContext,location,count,transpose,value);
  return;
}

/* _glUniformMatrix3fvARB_CompExec @ 0x8dd60 (80 bytes) */
void _glUniformMatrix3fvARB_CompExec(glContext, location, count, transpose, value)
  undefined4 glContext;
  undefined4 location;
  undefined4 count;
  undefined4 transpose;
  undefined4 value;
{
  ((int (*)())_glUniformMatrix3fvARB_Comp)(glContext,location,count,transpose,value);
  ((void (*)())_glUniformMatrix3fvARB_Exec)(glContext,location,count,transpose,value);
  return;
}

/* _glUniformMatrix4fvARB_CompExec @ 0x8ddb0 (80 bytes) */
void _glUniformMatrix4fvARB_CompExec(glContext, location, count, transpose, value)
  undefined4 glContext;
  undefined4 location;
  undefined4 count;
  undefined4 transpose;
  undefined4 value;
{
  ((int (*)())_glUniformMatrix4fvARB_Comp)(glContext,location,count,transpose,value);
  ((void (*)())_glUniformMatrix4fvARB_Exec)(glContext,location,count,transpose,value);
  return;
}

/* _glUniformMatrix2fvARB_ListExec @ 0x8de00 (72 bytes) */
int _glUniformMatrix2fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glUniformMatrix2fvARB_Exec)(glContext,*listRecord,listRecord[1],0,listRecord + 2);
  return listRecord[1] * 0x10 + 8;
}

/* _glUniformMatrix3fvARB_ListExec @ 0x8de48 (72 bytes) */
int _glUniformMatrix3fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glUniformMatrix3fvARB_Exec)(glContext,*listRecord,listRecord[1],0,listRecord + 2);
  return listRecord[1] * 0x24 + 8;
}

/* _glUniformMatrix4fvARB_ListExec @ 0x8de90 (72 bytes) */
int _glUniformMatrix4fvARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glUniformMatrix4fvARB_Exec)(glContext,*listRecord,listRecord[1],0,listRecord + 2);
  return listRecord[1] * 0x40 + 8;
}

/* _gleGetObjectParameter @ 0x8ded8 (508 bytes) */
int _gleGetObjectParameter(unusedArg1, param_2, param_3, param_4)
  undefined4 unusedArg1;
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
void _glGetObjectParameterfvARB_Exec(glContext, obj, pname, params)
  int glContext;
  undefined4 obj;
  undefined4 pname;
  float *params;
{
  int iVar1;
  uint local_28 [5];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar1 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar1 + 0x8028);
      iVar1 = *(int *)(glContext + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1 + 0x6018,obj);
    if (iVar1 != 0) {
      iVar1 = ((int (*)())_gleGetObjectParameter)(glContext,iVar1,pname,local_28);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (iVar1 != 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        *(int *)(glContext + 0x7574) = iVar1;
        return;
      }
      *params = (float)((double)CONCAT44(0x43300000,local_28[0] ^ 0x80000000) - DOUBLE_00108d58);
      return;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glGetObjectParameterivARB_Exec @ 0x8e2f4 (256 bytes) */
void _glGetObjectParameterivARB_Exec(glContext, obj, pname, params)
  int glContext;
  undefined4 obj;
  undefined4 pname;
  undefined4 *params;
{
  int iVar1;
  undefined4 local_30 [7];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar1 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar1 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar1 + 0x8028);
      iVar1 = *(int *)(glContext + 0x5148);
    }
    iVar1 = _gleLookupHashObject(iVar1 + 0x6018,obj);
    if (iVar1 != 0) {
      iVar1 = ((int (*)())_gleGetObjectParameter)(glContext,iVar1,pname,local_30);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (iVar1 != 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        *(int *)(glContext + 0x7574) = iVar1;
        return;
      }
      *params = local_30[0];
      return;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return;
}

/* _glGetShaderiv_Exec @ 0x8e3f4 (348 bytes) */
void _glGetShaderiv_Exec(glContext, shader, pname, params)
  int glContext;
  undefined4 shader;
  int pname;
  undefined4 *params;
{
  undefined4 glErrorCode;
  int iVar2;
  undefined4 local_30 [7];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,shader);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_0008e4c4;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b48) {
      if (pname == 0x8b4e) {
        pname = 0x8b4f;
      }
      iVar2 = ((int (*)())_gleGetObjectParameter)(glContext,iVar2,pname,local_30);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (iVar2 != 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        *(int *)(glContext + 0x7574) = iVar2;
        return;
      }
      *params = local_30[0];
      return;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0008e4c4:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetProgramiv_Exec @ 0x8e550 (324 bytes) */
void _glGetProgramiv_Exec(glContext, program, pname, params)
  int glContext;
  undefined4 program;
  undefined4 pname;
  undefined4 *params;
{
  undefined4 glErrorCode;
  int iVar2;
  undefined4 local_30 [7];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,program);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_0008e620;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b40) {
      iVar2 = ((int (*)())_gleGetObjectParameter)(glContext,iVar2,pname,local_30);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (iVar2 != 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        *(int *)(glContext + 0x7574) = iVar2;
        return;
      }
      *params = local_30[0];
      return;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0008e620:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetInfoLogARB_Exec @ 0x8e694 (356 bytes) */
void _glGetInfoLogARB_Exec(glContext, obj, maxLength, length, infoLog)
  int glContext;
  undefined4 obj;
  int maxLength;
  size_t *length;
  char *infoLog;
{
  undefined4 glErrorCode;
  int iVar2;
  uint uVar3;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,obj);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_0008e778;
    }
    if ((*(int *)(iVar2 + 0x10) == 0x8b40) || (*(int *)(iVar2 + 0x10) == 0x8b48)) {
      uVar3 = *(uint *)(iVar2 + 0x1c);
      if (maxLength - 1U < *(uint *)(iVar2 + 0x1c)) {
        uVar3 = maxLength - 1U;
      }
      _strncpy(infoLog,*(char **)(iVar2 + 0x18),uVar3);
      infoLog[uVar3] = '\0';
      if (length != (size_t *)0x0) {
        *length = uVar3;
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0008e778:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetShaderInfoLog_Exec @ 0x8e7f8 (340 bytes) */
void _glGetShaderInfoLog_Exec(glContext, shader, bufSize, length, infoLog)
  int glContext;
  undefined4 shader;
  int bufSize;
  size_t *length;
  char *infoLog;
{
  undefined4 glErrorCode;
  int iVar2;
  uint uVar3;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,shader);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_0008e8cc;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b48) {
      uVar3 = *(uint *)(iVar2 + 0x1c);
      if (bufSize - 1U < *(uint *)(iVar2 + 0x1c)) {
        uVar3 = bufSize - 1U;
      }
      _strncpy(infoLog,*(char **)(iVar2 + 0x18),uVar3);
      infoLog[uVar3] = '\0';
      if (length != (size_t *)0x0) {
        *length = uVar3;
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0008e8cc:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetProgramInfoLog_Exec @ 0x8e94c (340 bytes) */
void _glGetProgramInfoLog_Exec(glContext, program, bufSize, length, infoLog)
  int glContext;
  undefined4 program;
  int bufSize;
  size_t *length;
  char *infoLog;
{
  undefined4 glErrorCode;
  int iVar2;
  uint uVar3;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,program);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_0008ea20;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b40) {
      uVar3 = *(uint *)(iVar2 + 0x1c);
      if (bufSize - 1U < *(uint *)(iVar2 + 0x1c)) {
        uVar3 = bufSize - 1U;
      }
      _strncpy(infoLog,*(char **)(iVar2 + 0x18),uVar3);
      infoLog[uVar3] = '\0';
      if (length != (size_t *)0x0) {
        *length = uVar3;
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0008ea20:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glIsShader_Exec @ 0x8eaa0 (216 bytes) */
int _glIsShader_Exec(glContext, shader)
  int glContext;
  undefined4 shader;
{
  bool bVar1;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,shader);
    if (iVar2 != 0) {
      bVar1 = *(int *)(iVar2 + 0x10) == 0x8b48;
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return bVar1;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return bVar1;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return false;
}

/* _glIsProgram_Exec @ 0x8eb78 (216 bytes) */
int _glIsProgram_Exec(glContext, program)
  int glContext;
  undefined4 program;
{
  bool bVar1;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,program);
    if (iVar2 != 0) {
      bVar1 = *(int *)(iVar2 + 0x10) == 0x8b40;
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return bVar1;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return bVar1;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  else if (*(int *)(glContext + 0x7574) == 0) {
    *(undefined4 *)(glContext + 0x7574) = 0x502;
  }
  return false;
}

/* _glGetAttachedObjectsARB_Exec @ 0x8ec50 (364 bytes) */
void _glGetAttachedObjectsARB_Exec(glContext, containerObj, maxCount, count, obj)
  int glContext;
  undefined4 containerObj;
  int maxCount;
  int *count;
  int obj;
{
  int iVar1;
  undefined4 glErrorCode;
  int iVar3;
  int loopIndex;
  
  loopIndex = 0;
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar3 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar3 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar3 + 0x8028);
      iVar3 = *(int *)(glContext + 0x5148);
    }
    iVar3 = _gleLookupHashObject(iVar3 + 0x6018,containerObj);
    if (iVar3 == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_0008ed28;
    }
    if (*(int *)(iVar3 + 0x10) == 0x8b40) {
      if ((0 < *(int *)(iVar3 + 0x48)) && (0 < maxCount)) {
        do {
          iVar1 = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(iVar1 + obj) =
               *(undefined4 *)(*(int *)(iVar1 + *(int *)(iVar3 + 0x44)) + 4);
          if (*(int *)(iVar3 + 0x48) <= loopIndex) break;
        } while (loopIndex < maxCount);
      }
      if (count != (int *)0x0) {
        *count = loopIndex;
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0008ed28:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetUniformLocationARB_Exec @ 0x8edbc (296 bytes) */
int _glGetUniformLocationARB_Exec(glContext, programObj, name)
  int glContext;
  undefined4 programObj;
  undefined4 name;
{
  undefined4 uVar1;
  undefined4 glErrorCode;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,programObj);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0xffffffff;
      }
      glErrorCode = 0x501;
      goto LAB_0008ee94;
    }
    if ((*(int *)(iVar2 + 0x10) == 0x8b40) && (*(char *)(iVar2 + 0x3c) == '\x01')) {
      uVar1 = _ShGetUniformLocation(*(undefined4 *)(iVar2 + 0x40),name);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return uVar1;
      }
      return uVar1;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0xffffffff;
  }
  glErrorCode = 0x502;
LAB_0008ee94:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0xffffffff;
}

/* _glGetActiveUniformARB_Exec @ 0x8eee4 (348 bytes) */
void _glGetActiveUniformARB_Exec(glContext, programObj, index, maxLength, length, size, type, name)
  int glContext;
  undefined4 programObj;
  uint index;
  undefined4 maxLength;
  undefined4 length;
  undefined4 size;
  undefined4 type;
  undefined4 name;
{
  undefined4 glErrorCode;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,programObj);
    if (iVar2 == 0) {
LAB_0008ef74:
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_0008eff8;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b40) {
      if (*(uint *)(iVar2 + 0x28) <= index) goto LAB_0008ef74;
      iVar2 = _ShGetActiveUniform(*(undefined4 *)(iVar2 + 0x40),index,maxLength,length,size,
                                  type,name);
      if (iVar2 != 0) {
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return;
      }
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0008eff8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetUniformfvARB_Exec @ 0x8f040 (1316 bytes) */
void _glGetUniformfvARB_Exec(glContext, programObj, location, params)
  int glContext;
  undefined4 programObj;
  int location;
  float *params;
{
  float fVar1;
  double dVar2;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  uint *puVar6;
  undefined1 auStack_38 [4];
  uint local_34;
  undefined2 local_30 [14];
  
  local_30[0] = 0;
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_0008f154:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0008f164:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  iVar4 = *(int *)(glContext + 0x5148);
  if (*(char *)(iVar4 + 0x8024) != '\0') {
    _pthread_mutex_lock(iVar4 + 0x8028);
    iVar4 = *(int *)(glContext + 0x5148);
  }
  iVar4 = _gleLookupHashObject(iVar4 + 0x6018,programObj);
  if (iVar4 == 0) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_0008f164;
  }
  if ((((*(int *)(iVar4 + 0x10) != 0x8b40) || (*(char *)(iVar4 + 0x3c) != '\x01')) ||
      (*(int *)(iVar4 + 0x30) <= location)) ||
     ((location == -1 ||
      (iVar5 = _ShGetUniformTypeInfo
                         (*(undefined4 *)(iVar4 + 0x40),location,auStack_38,&local_34,local_30),
      dVar2 = DOUBLE_00108d58, iVar5 == 0)))) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    goto LAB_0008f154;
  }
  iVar5 = *(int *)(iVar4 + 0x4c);
  iVar4 = location * 0x10;
  puVar6 = (uint *)(iVar5 + iVar4);
  if (local_34 == 0x8b56) {
LAB_0008f414:
    fVar1 = (float)((double)CONCAT44(0x43300000,*puVar6 ^ 0x80000000) - DOUBLE_00108d58);
  }
  else {
    if (0x8b56 < local_34) {
      if (local_34 == 0x8b5a) {
        *params = *(float *)(iVar5 + iVar4);
        params[1] = GH_U2F((unsigned int)(puVar6[1]));
        params[2] = GH_U2F((unsigned int)(puVar6[4]));
        fVar1 = GH_U2F((unsigned int)(puVar6[5]));
LAB_0008f460:
        params[3] = fVar1;
        goto LAB_0008f534;
      }
      if (local_34 < 0x8b5b) {
        if (local_34 != 0x8b58) {
          if (0x8b58 < local_34) {
LAB_0008f290:
            *params = (float)((double)CONCAT44(0x43300000,*puVar6 ^ 0x80000000) - DOUBLE_00108d58);
            params[1] = (float)((double)CONCAT44(0x43300000,puVar6[1] ^ 0x80000000) - dVar2);
            params[2] = (float)((double)CONCAT44(0x43300000,puVar6[2] ^ 0x80000000) - dVar2);
            params[3] = (float)((double)CONCAT44(0x43300000,puVar6[3] ^ 0x80000000) - dVar2);
            goto LAB_0008f534;
          }
          goto LAB_0008f3bc;
        }
LAB_0008f338:
        *params = (float)((double)CONCAT44(0x43300000,*puVar6 ^ 0x80000000) - DOUBLE_00108d58);
        params[1] = (float)((double)CONCAT44(0x43300000,puVar6[1] ^ 0x80000000) - dVar2);
        fVar1 = (float)((double)CONCAT44(0x43300000,puVar6[2] ^ 0x80000000) - dVar2);
        goto LAB_0008f3a0;
      }
      if (local_34 == 0x8b5c) {
        *params = *(float *)(iVar5 + iVar4);
        params[1] = GH_U2F((unsigned int)(puVar6[1]));
        params[2] = GH_U2F((unsigned int)(puVar6[2]));
        params[3] = GH_U2F((unsigned int)(puVar6[3]));
        params[4] = GH_U2F((unsigned int)(puVar6[4]));
        params[5] = GH_U2F((unsigned int)(puVar6[5]));
        params[6] = GH_U2F((unsigned int)(puVar6[6]));
        params[7] = GH_U2F((unsigned int)(puVar6[7]));
        params[8] = GH_U2F((unsigned int)(puVar6[8]));
        params[9] = GH_U2F((unsigned int)(puVar6[9]));
        params[10] = GH_U2F((unsigned int)(puVar6[10]));
        params[0xb] = GH_U2F((unsigned int)(puVar6[0xb]));
        params[0xc] = GH_U2F((unsigned int)(puVar6[0xc]));
        params[0xd] = GH_U2F((unsigned int)(puVar6[0xd]));
        params[0xe] = GH_U2F((unsigned int)(puVar6[0xe]));
        params[0xf] = GH_U2F((unsigned int)(puVar6[0xf]));
        goto LAB_0008f534;
      }
      if (local_34 < 0x8b5c) {
        *params = *(float *)(iVar5 + iVar4);
        params[1] = GH_U2F((unsigned int)(puVar6[1]));
        params[2] = GH_U2F((unsigned int)(puVar6[2]));
        params[3] = GH_U2F((unsigned int)(puVar6[4]));
        params[4] = GH_U2F((unsigned int)(puVar6[5]));
        params[5] = GH_U2F((unsigned int)(puVar6[6]));
        params[6] = GH_U2F((unsigned int)(puVar6[8]));
        params[7] = GH_U2F((unsigned int)(puVar6[9]));
        params[8] = GH_U2F((unsigned int)(puVar6[10]));
        goto LAB_0008f534;
      }
      if (0x8b64 < local_34) goto LAB_0008f534;
      goto LAB_0008f414;
    }
    if (local_34 == 0x8b51) {
      *params = *(float *)(iVar5 + iVar4);
      params[1] = GH_U2F((unsigned int)(puVar6[1]));
      fVar1 = GH_U2F((unsigned int)(puVar6[2]));
LAB_0008f3a0:
      params[2] = fVar1;
      goto LAB_0008f534;
    }
    if (0x8b51 < local_34) {
      if (local_34 == 0x8b53) {
LAB_0008f3bc:
        *params = (float)((double)CONCAT44(0x43300000,*puVar6 ^ 0x80000000) - DOUBLE_00108d58);
        params[1] = (float)((double)CONCAT44(0x43300000,puVar6[1] ^ 0x80000000) - dVar2);
        goto LAB_0008f534;
      }
      if (0x8b52 < local_34) {
        if (local_34 != 0x8b54) {
          if (local_34 != 0x8b55) goto LAB_0008f534;
          goto LAB_0008f290;
        }
        goto LAB_0008f338;
      }
      *params = *(float *)(iVar5 + iVar4);
      params[1] = GH_U2F((unsigned int)(puVar6[1]));
      params[2] = GH_U2F((unsigned int)(puVar6[2]));
      fVar1 = GH_U2F((unsigned int)(puVar6[3]));
      goto LAB_0008f460;
    }
    if (local_34 != 0x1406) {
      if (0x1406 < local_34) {
        if (local_34 == 0x8b50) {
          *params = *(float *)(iVar5 + iVar4);
          params[1] = GH_U2F((unsigned int)(puVar6[1]));
        }
        goto LAB_0008f534;
      }
      if (local_34 != 0x1404) goto LAB_0008f534;
      goto LAB_0008f414;
    }
    fVar1 = *(float *)(iVar5 + iVar4);
  }
  *params = fVar1;
LAB_0008f534:
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
    return;
  }
  _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
  return;
}

/* _glGetUniformivARB_Exec @ 0x8f564 (1628 bytes) */
void _glGetUniformivARB_Exec(glContext, programObj, location, params)
  int glContext;
  undefined4 programObj;
  int location;
  int *params;
{
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  int *piVar4;
  float fVar5;
  undefined1 auStack_38 [4];
  uint local_34;
  undefined2 local_30 [14];
  
  local_30[0] = 0;
  if (-1 < *(short *)(glContext + 0x4a10)) {
LAB_0008f670:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
LAB_0008f680:
    *(undefined4 *)(glContext + 0x7574) = glErrorCode;
    return;
  }
  iVar2 = *(int *)(glContext + 0x5148);
  if (*(char *)(iVar2 + 0x8024) != '\0') {
    _pthread_mutex_lock(iVar2 + 0x8028);
    iVar2 = *(int *)(glContext + 0x5148);
  }
  iVar2 = _gleLookupHashObject(iVar2 + 0x6018,programObj);
  if (iVar2 == 0) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_0008f680;
  }
  if ((((*(int *)(iVar2 + 0x10) != 0x8b40) || (*(char *)(iVar2 + 0x3c) != '\x01')) ||
      (*(int *)(iVar2 + 0x30) <= location)) ||
     ((location == -1 ||
      (iVar3 = _ShGetUniformTypeInfo
                         (*(undefined4 *)(iVar2 + 0x40),location,auStack_38,&local_34,local_30),
      iVar3 == 0)))) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    goto LAB_0008f670;
  }
  iVar3 = *(int *)(iVar2 + 0x4c);
  iVar2 = location * 0x10;
  piVar4 = (int *)(iVar3 + iVar2);
  if (local_34 == 0x8b56) {
LAB_0008f8c4:
    iVar2 = *piVar4;
  }
  else {
    if (0x8b56 < local_34) {
      if (local_34 == 0x8b5a) {
        fVar5 = _roundf(*(float *)(iVar3 + iVar2));
        *params = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
        params[1] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[4])));
        params[2] = (int)fVar5;
        fVar5 = GH_U2F((unsigned int)(piVar4[5]));
LAB_0008f91c:
        fVar5 = _roundf(fVar5);
        params[3] = (int)fVar5;
        goto LAB_0008fb90;
      }
      if (local_34 < 0x8b5b) {
        if (local_34 != 0x8b58) {
          if (0x8b58 < local_34) {
LAB_0008f7dc:
            *params = *piVar4;
            params[1] = piVar4[1];
            params[2] = piVar4[2];
            params[3] = piVar4[3];
            goto LAB_0008fb90;
          }
          goto LAB_0008f898;
        }
LAB_0008f848:
        *params = *piVar4;
        params[1] = piVar4[1];
        iVar2 = piVar4[2];
        goto LAB_0008f85c;
      }
      if (local_34 == 0x8b5c) {
        fVar5 = _roundf(*(float *)(iVar3 + iVar2));
        *params = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
        params[1] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[2])));
        params[2] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[3])));
        params[3] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[4])));
        params[4] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[5])));
        params[5] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[6])));
        params[6] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[7])));
        params[7] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[8])));
        params[8] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[9])));
        params[9] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[10])));
        params[10] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[0xb])));
        params[0xb] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[0xc])));
        params[0xc] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[0xd])));
        params[0xd] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[0xe])));
        params[0xe] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[0xf])));
        params[0xf] = (int)fVar5;
        goto LAB_0008fb90;
      }
      if (local_34 < 0x8b5c) {
        fVar5 = _roundf(*(float *)(iVar3 + iVar2));
        *params = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
        params[1] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[2])));
        params[2] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[4])));
        params[3] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[5])));
        params[4] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[6])));
        params[5] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[8])));
        params[6] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[9])));
        params[7] = (int)fVar5;
        fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[10])));
        params[8] = (int)fVar5;
        goto LAB_0008fb90;
      }
      if (0x8b64 < local_34) goto LAB_0008fb90;
      goto LAB_0008f8c4;
    }
    if (local_34 == 0x8b51) {
      fVar5 = _roundf(*(float *)(iVar3 + iVar2));
      *params = (int)fVar5;
      fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
      params[1] = (int)fVar5;
      fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[2])));
      iVar2 = (int)fVar5;
LAB_0008f85c:
      params[2] = iVar2;
      goto LAB_0008fb90;
    }
    if (0x8b51 < local_34) {
      if (local_34 == 0x8b53) {
LAB_0008f898:
        *params = *piVar4;
        params[1] = piVar4[1];
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
      *params = (int)fVar5;
      fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
      params[1] = (int)fVar5;
      fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[2])));
      params[2] = (int)fVar5;
      fVar5 = GH_U2F((unsigned int)(piVar4[3]));
      goto LAB_0008f91c;
    }
    if (local_34 != 0x1406) {
      if (0x1406 < local_34) {
        if (local_34 == 0x8b50) {
          fVar5 = _roundf(*(float *)(iVar3 + iVar2));
          *params = (int)fVar5;
          fVar5 = _roundf(GH_U2F((unsigned int)(piVar4[1])));
          params[1] = (int)fVar5;
        }
        goto LAB_0008fb90;
      }
      if (local_34 != 0x1404) goto LAB_0008fb90;
      goto LAB_0008f8c4;
    }
    fVar5 = _roundf(*(float *)(iVar3 + iVar2));
    iVar2 = (int)fVar5;
  }
  *params = iVar2;
LAB_0008fb90:
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
    return;
  }
  _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
  return;
}

/* _glGetShaderSourceARB_Exec @ 0x8fbc0 (340 bytes) */
void _glGetShaderSourceARB_Exec(glContext, obj, maxLength, length, source)
  int glContext;
  undefined4 obj;
  int maxLength;
  size_t *length;
  char *source;
{
  undefined4 glErrorCode;
  int iVar2;
  uint uVar3;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,obj);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_0008fc94;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b48) {
      uVar3 = *(uint *)(iVar2 + 0x28);
      if (maxLength - 1U < *(uint *)(iVar2 + 0x28)) {
        uVar3 = maxLength - 1U;
      }
      _strncpy(source,*(char **)(iVar2 + 0x2c),uVar3);
      source[uVar3] = '\0';
      if (length != (size_t *)0x0) {
        *length = uVar3;
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
        return;
      }
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_0008fc94:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glBindAttribLocationARB_Exec @ 0x8fd14 (360 bytes) */
void _glBindAttribLocationARB_Exec(glContext, programObj, index, name)
  int glContext;
  undefined4 programObj;
  uint index;
  char *name;
{
  undefined4 glErrorCode;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,programObj);
    if (iVar2 != 0) {
      if ((*(int *)(iVar2 + 0x10) != 0x8b40) ||
         ((((name != (char *)0x0 && (*name == 'g')) && (name[1] == 'l')) &&
          (name[2] == '_')))) {
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
          _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        }
        goto LAB_0008fddc;
      }
      if (index < 0x10) {
        _ShAttributeBindingRequest(*(undefined4 *)(iVar2 + 0x40),index,name);
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return;
      }
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
LAB_0008fddc:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetAttribLocationARB_Exec @ 0x8fe7c (296 bytes) */
int _glGetAttribLocationARB_Exec(glContext, programObj, name)
  int glContext;
  undefined4 programObj;
  undefined4 name;
{
  undefined4 uVar1;
  undefined4 glErrorCode;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,programObj);
    if (iVar2 == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return 0xffffffff;
      }
      glErrorCode = 0x501;
      goto LAB_0008ff54;
    }
    if ((*(int *)(iVar2 + 0x10) == 0x8b40) && (*(char *)(iVar2 + 0x3c) == '\x01')) {
      uVar1 = _ShGetAttribLocation(*(undefined4 *)(iVar2 + 0x40),name);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return uVar1;
      }
      return uVar1;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return 0xffffffff;
  }
  glErrorCode = 0x502;
LAB_0008ff54:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0xffffffff;
}

/* _glGetActiveAttribARB_Exec @ 0x8ffa4 (348 bytes) */
void _glGetActiveAttribARB_Exec(glContext, programObj, index, maxLength, length, size, type, name)
  int glContext;
  undefined4 programObj;
  uint index;
  undefined4 maxLength;
  undefined4 length;
  undefined4 size;
  undefined4 type;
  undefined4 name;
{
  undefined4 glErrorCode;
  int iVar2;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar2 + 0x8028);
      iVar2 = *(int *)(glContext + 0x5148);
    }
    iVar2 = _gleLookupHashObject(iVar2 + 0x6018,programObj);
    if (iVar2 == 0) {
LAB_00090034:
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_000900b8;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b40) {
      if (*(uint *)(iVar2 + 0x34) <= index) goto LAB_00090034;
      iVar2 = _ShGetActiveAttrib(*(undefined4 *)(iVar2 + 0x40),index,maxLength,length,size,
                                 type,name);
      if (iVar2 != 0) {
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return;
      }
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_000900b8:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetPointerv_Exec @ 0x90100 (404 bytes) */
void _glGetPointerv_Exec(glContext, pname, params)
  int glContext;
  uint pname;
  undefined4 *params;
{
  undefined4 uVar1;
  undefined4 glErrorCode;
  int clientState;
  
  clientState = *(int *)(glContext + 0x4a60);
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (pname == 0x8092) {
      uVar1 = *(undefined4 *)(*(int *)(glContext + 0x53d8) * 0x18 + clientState + 0xf0);
      goto LAB_00090210;
    }
    if (pname < 0x8093) {
      if (pname == 0x808e) {
        uVar1 = *(undefined4 *)(clientState + 0x30);
LAB_00090210:
        *params = uVar1;
        return;
      }
      if (0x808e < pname) {
        if (pname == 0x8090) {
          uVar1 = *(undefined4 *)(clientState + 0x60);
        }
        else if (pname < 0x8091) {
          uVar1 = *(undefined4 *)(clientState + 0x48);
        }
        else {
          uVar1 = *(undefined4 *)(glContext + 0x48e0);
        }
        goto LAB_00090210;
      }
      if (pname == 0xdf0) {
        uVar1 = *(undefined4 *)(glContext + 0x4fcc);
        goto LAB_00090210;
      }
      if (pname == 0xdf3) {
        uVar1 = *(undefined4 *)(glContext + 20000);
        goto LAB_00090210;
      }
    }
    else {
      if (pname == 0x845d) {
        uVar1 = *(undefined4 *)(clientState + 0x90);
        goto LAB_00090210;
      }
      if (pname < 0x845e) {
        if (pname == 0x8093) {
          uVar1 = *(undefined4 *)(clientState + 0xc0);
          goto LAB_00090210;
        }
        if (pname == 0x8456) {
          uVar1 = *(undefined4 *)(clientState + 0x78);
          goto LAB_00090210;
        }
      }
      else {
        if (pname == 0x86ac) {
          uVar1 = *(undefined4 *)(clientState + 0xa8);
          goto LAB_00090210;
        }
        if (pname < 0x86ad) {
          if (pname == 0x8521) {
            uVar1 = *(undefined4 *)(clientState + 0x344);
            goto LAB_00090210;
          }
        }
        else if (pname == 0x8a0e) {
          uVar1 = *(undefined4 *)(clientState + 0xd8);
          goto LAB_00090210;
        }
      }
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

/* _glStencilFunc_ListExec @ 0x90294 (52 bytes) */
int _glStencilFunc_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glStencilFunc_Exec(glContext,*listRecord,listRecord[1],listRecord[2]);
  return 0xc;
}

/* _glStencilOp_ListExec @ 0x902c8 (52 bytes) */
int _glStencilOp_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glStencilOp_Exec(glContext,*listRecord,listRecord[1],listRecord[2]);
  return 0xc;
}

/* _glActiveStencilFace_ListExec @ 0x902fc (80 bytes) */
int _glActiveStencilFace_ListExec(glContext, param_2)
  int glContext;
  uint *param_2;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*param_2 < 2) {
      *(char *)(glContext + 0x7583) = (char)*param_2;
      return 4;
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 4;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 4;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 4;
}

/* _glActiveStencilFace_Comp @ 0x9034c (80 bytes) */
int _glActiveStencilFace_Comp(glContext, face)
  undefined4 glContext;
  int face;
{
  int *listRecord;
  
  listRecord = (int *)_gleAddListItem(glContext,PTR__glActiveStencilFace_ListExec_00110314,4);
  if (listRecord != (int *)0x0) {
    *listRecord = face + -0x404;
  }
  return listRecord;
}

/* _glActiveStencilFace_Exec @ 0x9039c (76 bytes) */
void _glActiveStencilFace_Exec(glContext, face)
  int glContext;
  int face;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (face - 0x404U < 2) {
      *(char *)(glContext + 0x7583) = (char)(face - 0x404U);
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

/* _glActiveStencilFace_CompExec @ 0x903e8 (56 bytes) */
void _glActiveStencilFace_CompExec(glContext, face)
  undefined4 glContext;
  undefined4 face;
{
  ((int (*)())_glActiveStencilFace_Comp)(glContext,face);
  ((void (*)())_glActiveStencilFace_Exec)(glContext,face);
  return;
}

/* _glStencilFuncSeparateATI_ListExec @ 0x90420 (56 bytes) */
int _glStencilFuncSeparateATI_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glStencilFuncSeparateATI_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3]);
  return 0x10;
}

/* _glStencilFuncSeparateATI_Comp @ 0x90458 (100 bytes) */
int _glStencilFuncSeparateATI_Comp(glContext, frontfunc, backfunc, ref, mask)
  undefined4 glContext;
  undefined4 frontfunc;
  undefined4 backfunc;
  undefined4 ref;
  undefined4 mask;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)
           _gleAddListItem(glContext,PTR__glStencilFuncSeparateATI_ListExec_00110310,0x10);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[3] = mask;
    *listRecord = frontfunc;
    listRecord[1] = backfunc;
    listRecord[2] = ref;
  }
  return listRecord;
}

/* _glStencilFuncSeparateATI_Exec @ 0x904bc (176 bytes) */
void _glStencilFuncSeparateATI_Exec(glContext, frontfunc, backfunc, ref, mask)
  int glContext;
  int frontfunc;
  int backfunc;
  uint ref;
  undefined4 mask;
{
  undefined4 glErrorCode;
  uint uVar2;
  int iVar3;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if ((frontfunc - 0x200U < 8) && (backfunc - 0x200U < 8)) {
      if ((int)ref < 0) {
        ref = 0;
      }
      else {
        uVar2 = 0xffffffff >> (0x20U - *(int *)(*(int *)(glContext + 0x468c) + 0x40) & 0x3f);
        if (uVar2 < ref) {
          ref = uVar2;
        }
      }
      iVar3 = (uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext;
      *(undefined4 *)(iVar3 + 0x34f8) = mask;
      *(short *)(iVar3 + 0x3500) = (short)frontfunc;
      *(uint *)(iVar3 + 0x34fc) = ref;
      *(short *)(glContext + 0x3518) = (short)backfunc;
      *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x10000000;
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

/* _glStencilFuncSeparateATI_CompExec @ 0x9056c (80 bytes) */
void _glStencilFuncSeparateATI_CompExec(glContext, frontfunc, backfunc, ref, mask)
  undefined4 glContext;
  undefined4 frontfunc;
  undefined4 backfunc;
  undefined4 ref;
  undefined4 mask;
{
  ((int (*)())_glStencilFuncSeparateATI_Comp)(glContext,frontfunc,backfunc,ref,mask);
  ((void (*)())_glStencilFuncSeparateATI_Exec)(glContext,frontfunc,backfunc,ref,mask);
  return;
}

/* _glStencilOpSeparateATI_ListExec @ 0x905bc (56 bytes) */
int _glStencilOpSeparateATI_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glStencilOpSeparateATI_Exec)(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3]);
  return 0x10;
}

/* _glStencilOpSeparateATI_Comp @ 0x905f4 (100 bytes) */
int _glStencilOpSeparateATI_Comp(glContext, face, sfail, dpfail, dppass)
  undefined4 glContext;
  undefined4 face;
  undefined4 sfail;
  undefined4 dpfail;
  undefined4 dppass;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glStencilOpSeparateATI_ListExec_0011030c,0x10)
  ;
  if (listRecord != (undefined4 *)0x0) {
    listRecord[3] = dppass;
    *listRecord = face;
    listRecord[1] = sfail;
    listRecord[2] = dpfail;
  }
  return listRecord;
}

/* _glStencilOpSeparateATI_Exec @ 0x90658 (336 bytes) */
void _glStencilOpSeparateATI_Exec(glContext, face, sfail, dpfail, dppass)
  int glContext;
  uint face;
  uint sfail;
  uint dpfail;
  uint dppass;
{
  undefined4 glErrorCode;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
    goto LAB_000906bc;
  }
  if (sfail < 0x1e04) {
    if (((0x1dff < sfail) || (sfail == 0)) || (sfail == 0x150a)) {
LAB_000906c4:
      if (dpfail < 0x1e04) {
        if (((0x1dff < dpfail) || (dpfail == 0)) || (dpfail == 0x150a)) {
LAB_000906f8:
          if (dppass < 0x1e04) {
            if (((0x1dff < dppass) || (dppass == 0)) || (dppass == 0x150a)) {
LAB_0009072c:
              uVar3 = (undefined2)sfail;
              uVar4 = (undefined2)dpfail;
              uVar5 = (undefined2)dppass;
              if (face == 0x405) {
LAB_0009078c:
                *(undefined2 *)(glContext + 0x351a) = uVar3;
                *(undefined2 *)(glContext + 0x351c) = uVar4;
                *(undefined2 *)(glContext + 0x351e) = uVar5;
LAB_00090798:
                *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x10000000;
                return;
              }
              if (face < 0x406) {
                if (face == 0x404) {
                  iVar2 = (uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext;
                  *(undefined2 *)(iVar2 + 0x3506) = uVar5;
                  *(undefined2 *)(iVar2 + 0x3502) = uVar3;
                  *(undefined2 *)(iVar2 + 0x3504) = uVar4;
                  goto LAB_00090798;
                }
              }
              else if (face == 0x408) {
                iVar2 = (uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext;
                *(undefined2 *)(iVar2 + 0x3506) = uVar5;
                *(undefined2 *)(iVar2 + 0x3502) = uVar3;
                *(undefined2 *)(iVar2 + 0x3504) = uVar4;
                goto LAB_0009078c;
              }
            }
          }
          else if (dppass - 0x8507 < 2) goto LAB_0009072c;
        }
      }
      else if (dpfail - 0x8507 < 2) goto LAB_000906f8;
    }
  }
  else if (sfail - 0x8507 < 2) goto LAB_000906c4;
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x500;
LAB_000906bc:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glStencilOpSeparateATI_CompExec @ 0x907a8 (80 bytes) */
void _glStencilOpSeparateATI_CompExec(glContext, face, sfail, dpfail, dppass)
  undefined4 glContext;
  undefined4 face;
  undefined4 sfail;
  undefined4 dpfail;
  undefined4 dppass;
{
  ((int (*)())_glStencilOpSeparateATI_Comp)(glContext,face,sfail,dpfail,dppass);
  ((void (*)())_glStencilOpSeparateATI_Exec)(glContext,face,sfail,dpfail,dppass);
  return;
}

