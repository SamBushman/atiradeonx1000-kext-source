#include "decls.h"

/* FUN_0004c260 @ 0x4c260 (732 bytes) */
int FUN_0004c260(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
  int loopIndex;
  bool bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined *puVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  
  if (param_3 == 0) {
    cVar2 = ((unsigned char *)0x000010e9)[param_2];
    iVar8 = *(int *)(((unsigned char *)0x000036a8) + param_2);
    puVar11 = (undefined4 *)(param_2 + 4);
    puVar12 = ((unsigned char *)0x000010ec);
  }
  else {
    cVar2 = ((unsigned char *)0x000010ea)[param_2];
    iVar8 = *(int *)(((unsigned char *)0x000036b4) + param_2);
    puVar11 = (undefined4 *)(param_2 + 0x20);
    puVar12 = ((unsigned char *)0x00001318);
  }
  puVar12 = puVar12 + param_2;
  if (iVar8 != 0) {
    if (cVar2 == '\0') {
      uVar15 = 0;
      puVar9 = puVar12 + 0x44;
      puVar7 = param_1 + 0xf;
      *param_1 = ((unsigned char *)0x00001181U);
      dataCacheBlockTouch(puVar9);
      uVar5 = *puVar11;
      param_1[2] = ((unsigned char *)0x00001189U);
      param_1[1] = uVar5;
      uVar5 = puVar11[1];
      param_1[4] = ((unsigned char *)0x00001188U);
      param_1[6] = ((unsigned char *)0x0000118cU);
      param_1[5] = 0;
      param_1[3] = uVar5;
      uVar5 = puVar11[2];
      param_1[8] = ((unsigned char *)0x0000118dU);
      param_1[7] = uVar5;
      uVar5 = puVar11[3];
      param_1[10] = ((unsigned char *)0x0000118eU);
      param_1[0xb] = 0;
      param_1[0xc] = ((unsigned char *)0x000010c1U);
      param_1[9] = uVar5;
      param_1[0xd] = *(undefined4 *)(puVar12 + 0x44);
      param_1[0xe] = (*(uint *)(puVar12 + 0x44) & 0xf) << 0x10 | 0x10c8;
      uVar6 = *(uint *)(puVar12 + 0x44);
      uVar13 = uVar6 & 0xf;
      puVar12 = puVar9;
      if (uVar13 == 0) {
        uVar15 = 0;
      }
      else {
        do {
          uVar15 = uVar15 + 2;
          *puVar7 = *(undefined4 *)(puVar12 + 4);
          puVar7[1] = *(undefined4 *)(puVar12 + 8);
          puVar7 = puVar7 + 2;
          puVar12 = puVar12 + 8;
        } while (uVar15 < uVar13);
      }
      if ((uVar6 & 1) == 0) {
        *puVar7 = *(undefined4 *)(puVar9 + uVar15 * 4 + 4);
        puVar7 = puVar7 + 1;
      }
      param_1 = puVar7 + 3;
      puVar7[1] = 0;
      *puVar7 = ((unsigned char *)0x00001094U);
      puVar7[2] = (iVar8 * 6 + -1) * 0x10000 | 0x9095;
      if (0 < iVar8) {
        loopIndex = 0;
        iVar14 = 0;
        do {
          iVar16 = 0;
          iVar17 = 6;
          puVar7 = param_1;
          do {
            iVar3 = iVar16 * 4;
            iVar16 = iVar16 + 1;
            *puVar7 = *(undefined4 *)(iVar3 + iVar14 + puVar11[4]);
            puVar7 = puVar7 + 1;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
          loopIndex = loopIndex + 1;
          param_1 = param_1 + 6;
          iVar14 = iVar14 + 0x18;
        } while (iVar8 != loopIndex);
      }
    }
    if (((unsigned char *)0x000010eb)[param_2] == '\0') {
      dataCacheBlockTouch(param_2);
      uVar13 = 0x10000;
      uVar6 = 0;
      iVar10 = param_2 + 0x80;
      iVar8 = param_2;
      do {
        uVar15 = *(uint *)(((unsigned char *)0x000010b8) + iVar8);
        if (uVar15 != 0) {
          puVar11 = (undefined4 *)(iVar10 + 0xc);
          uVar4 = uVar6;
          do {
            if ((uVar15 & 1) != 0) {
              uVar13 = uVar4 & 0x1ff | uVar13 & 0xfffffe00;
              *param_1 = ((unsigned char *)0x00001094U);
              param_1[2] = 0x39095;
              param_1[1] = uVar13;
              param_1[3] = *puVar11;
              param_1[4] = puVar11[1];
              param_1[5] = puVar11[2];
              param_1[6] = puVar11[3];
              param_1 = param_1 + 7;
            }
            uVar15 = uVar15 >> 1;
            uVar4 = (uVar4 & 0x1ff) + 1;
            puVar11 = puVar11 + 4;
          } while (uVar15 != 0);
        }
        bVar1 = uVar6 != 0xe0;
        iVar8 = iVar8 + 4;
        iVar10 = iVar10 + 0x200;
        uVar6 = uVar6 + 0x20;
      } while (bVar1);
      uVar6 = *(uint *)(((unsigned char *)0x00003748) + param_2);
      if (uVar6 != 0) {
        puVar12 = ((unsigned char *)0x00001300U);
        iVar8 = param_2;
        do {
          if ((uVar6 & 1) != 0) {
            *param_1 = puVar12;
            param_1[1] = *(undefined4 *)(((unsigned char *)0x000036c8) + iVar8);
            param_1 = param_1 + 2;
          }
          uVar6 = uVar6 >> 1;
          puVar12 = puVar12 + 1;
          iVar8 = iVar8 + 4;
        } while (uVar6 != 0);
      }
    }
    if (param_3 == 0) {
      ((unsigned char *)0x000010ea)[param_2] = 0;
      ((unsigned char *)0x000010e9)[param_2] = 1;
    }
    else {
      ((unsigned char *)0x000010e9)[param_2] = 0;
      ((unsigned char *)0x000010ea)[param_2] = 1;
    }
    ((unsigned char *)0x000010eb)[param_2] = 1;
  }
  return param_1;
}

/* noop_4c540 @ 0x4c540 (4 bytes) */
int noop_4c540()
{
  return;
}

/* FUN_0004c560 @ 0x4c560 (440 bytes) */
int FUN_0004c560(glContext, param_2)
  int glContext;
  int param_2;
{
  int glContextWord1e68;
  char cVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint a2;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 *puVar6;
  int iVar7;
  
  glContextWord1e68 = *(int *)(glContext + 0x1e68);
  if (glContextWord1e68 != param_2) {
    if (glContextWord1e68 != 0) {
      ((unsigned char *)0x000010e9)[glContextWord1e68] = 0;
      ((unsigned char *)0x000010ea)[*(int *)(glContext + 0x1e68)] = 0;
      ((unsigned char *)0x000010eb)[*(int *)(glContext + 0x1e68)] = 0;
    }
    ((unsigned char *)0x000010eb)[param_2] = 0;
    ((unsigned char *)0x000010e9)[param_2] = 0;
    ((unsigned char *)0x000010ea)[param_2] = 0;
  }
  *(int *)(glContext + 0x1e68) = param_2;
  if ((glContextWord1e68 != param_2) && (*(int *)(((unsigned char *)0x000010d8) + param_2) != 0)) {
    ((int (*)())gldValidateTexEnvColor)(glContext);
  }
  if (*(uint *)(glContext + 0x23e0) == 0) {
    cVar1 = ((unsigned char *)0x000010e9)[param_2];
  }
  else {
    cVar1 = ((unsigned char *)0x000010ea)[param_2];
  }
  if ((cVar1 == '\0') || (((unsigned char *)0x000010eb)[param_2] == '\0')) {
    if ((*(uint *)(glContext + 0x23e0) & 0xff) == 0) {
      iVar3 = *(int *)(((unsigned char *)0x000036a8) + param_2);
      puVar2 = ((unsigned char *)0x000010ec);
    }
    else {
      iVar3 = *(int *)(((unsigned char *)0x000036b4) + param_2);
      puVar2 = ((unsigned char *)0x00001318);
    }
    uVar4 = (**(code **)(glContext + 0x2758))
                      (glContext,iVar3 * 6 + (*(uint *)(puVar2 + param_2 + 0x44) & 0xf) + 0x910);
    a2 = (uint)*(byte *)(glContext + 0x23e3);
    *(undefined4 *)(0x00002748 + glContext + 4) = uVar4;
    puVar5 = (undefined4 *)((int (*)())FUN_0004c260)(uVar4,param_2,a2);
    *puVar5 = 0x7101d;
    *(undefined4 **)(0x00002748 + glContext + 4) = puVar5 + 1;
    iVar7 = 8;
    iVar3 = glContext;
    do {
      puVar6 = *(undefined4 **)(0x00002748 + glContext + 4);
      puVar5 = (undefined4 *)(iVar3 + 0x1ee8);
      iVar3 = iVar3 + 4;
      *puVar6 = *puVar5;
      *(undefined4 **)(0x00002748 + glContext + 4) = puVar6 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    puVar5 = puVar6 + 5;
    puVar6[1] = ((unsigned char *)0x000011adU);
    puVar6[2] = *(undefined4 *)(0x00002348 + glContext + 4);
    puVar6[3] = ((unsigned char *)0x000010c0U);
    puVar6[4] = *(undefined4 *)(glContext + 0x1f2c);
    *(undefined4 **)(0x00002748 + glContext + 4) = puVar5;
    (**(code **)(glContext + 0x275c))(glContext,puVar5,a2,in_r6,in_r7,in_r8,puVar5);
  }
  *(int *)(glContext + 0x1e64) = param_2;
  return;
}

/* FUN_0004c720 @ 0x4c720 (1632 bytes) */
int FUN_0004c720(glContext, param_2, param_3, param_4, param_5)
  int glContext;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  uint vapOutVtxFmt0;
  int glContextWord276c;
  int loopIndex;
  bool glContextWord23e0;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined *puVar7;
  uint uVar8;
  char cVar9;
  undefined *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined4 glContextWord1bb0;
  int iVar18;
  uint uVar19;
  int iVar20;
  
  uVar15 = *(uint *)(glContext + 0x44);
  vapOutVtxFmt0 = *(uint *)(glContext + 0x1b9c);
  if (((uVar15 & 0x20000) != 0) && (iVar6 = *(int *)(glContext + 0x1e70), iVar6 != 0)) {
    if ((uVar15 & 0x2000) == 0) {
      cVar9 = ((unsigned char *)0x00001136)[glContext];
    }
    else {
      cVar9 = ((unsigned char *)0x000011d0)[glContext];
    }
    if (cVar9 == '\0') {
      uVar8 = (uint)(*(int *)(glContext + 0x2768) == 0);
      goto LAB_0004c770;
    }
  }
  iVar6 = *(int *)(glContext + 0x1e5c);
  uVar8 = 1;
LAB_0004c770:
  glContextWord23e0 = *(int *)(glContext + 0x23e0) == 0;
  if (glContextWord23e0) {
    puVar7 = ((unsigned char *)0x000010ec);
  }
  else {
    puVar7 = ((unsigned char *)0x00001318);
  }
  puVar7 = puVar7 + iVar6;
  if ((uVar8 == 0) || ((uVar15 & 0x100000) == 0)) {
    iVar6 = 0;
  }
  else {
    iVar6 = *(int *)(((unsigned char *)0x00001168) + glContext);
  }
  uVar15 = -(uint)(uVar15 & 0x82000 ^ 0x2000) >> 0x1f;
  if (((((param_2 != 0) || (iVar6 != 0)) || (uVar8 != *(uint *)(puVar7 + 0x228))) ||
      ((*(uint *)(puVar7 + 0x218) != vapOutVtxFmt0 ||
       (*(int *)(puVar7 + 0x220) != *(int *)(glContext + 0x1bb0))))) ||
     ((*(int *)(puVar7 + 0x21c) != *(int *)(glContext + 0x1ba0) ||
      (uVar15 != *(uint *)(puVar7 + 0x224))))) {
    if ((glContextWord23e0) || (*(int *)(glContext + 0x2768) == 0)) {
      uVar19 = *(uint *)(glContext + 0x1ba0);
    }
    else {
      uVar19 = *(uint *)(glContext + 0x1ba0) & ~(7 << (*(int *)(glContext + 0x276c) * 3 & 0x3fU));
      *(uint *)(glContext + 0x1ba0) = uVar19;
    }
    uVar11 = *(uint *)(puVar7 + 0x228);
    glContextWord1bb0 = *(undefined4 *)(glContext + 0x1bb0);
    *(uint *)(puVar7 + 0x218) = vapOutVtxFmt0;
    *(uint *)(puVar7 + 0x21c) = uVar19;
    *(uint *)(puVar7 + 0x224) = uVar15;
    *(undefined4 *)(puVar7 + 0x220) = glContextWord1bb0;
    iVar18 = (vapOutVtxFmt0 >> 1 & 1) + (vapOutVtxFmt0 >> 2 & 1) + (vapOutVtxFmt0 >> 3 & 1) + (vapOutVtxFmt0 >> 4 & 1);
    *(uint *)(puVar7 + 0x228) = uVar8 << 0x1f | uVar11 & 0x7fffffff;
    uVar14 = (uint)(iVar6 != 0) * 0x40000000 |
             (uint)(*(int *)(glContext + 0x2768) != 0) * 0x20000000 |
             uVar8 << 0x1f | uVar11 & 0x1fffffff;
    *(uint *)(puVar7 + 0x228) = uVar14;
    if (iVar18 == 4) {
      iVar18 = 2;
    }
    if (uVar14 == 4) {
      uVar8 = 0;
      uVar14 = 0;
      iVar6 = 0;
      iVar20 = 8;
      puVar10 = puVar7 + 0xc0;
      do {
        glContextWord276c = *(int *)(glContext + 0x276c);
        cVar9 = (char)uVar8;
        if (glContextWord276c == iVar6) {
          uVar11 = 0x3e;
          *(uint *)(puVar10 + 8) =
               (cVar9 + 1) * 0x40 & 0xfc0U | uVar8 & 0x3f | *(uint *)(puVar10 + 8) & 0xfffff000;
          if (2 < *(int *)(puVar7 + 0x210)) {
            uVar11 = (int)cVar9 + 2U & 0x3f;
          }
          *(uint *)(puVar7 + glContextWord276c * 4 + 200) =
               uVar11 << 0xc | *(uint *)(puVar7 + glContextWord276c * 4 + 200) & 0xff000fff | 0xfc0000;
          uVar11 = *(uint *)(puVar7 + 0x210);
        }
        else {
          iVar12 = (int)cVar9;
          uVar11 = uVar19 >> (uVar14 & 0x3f) & 7;
          *(uint *)(puVar10 + 8) =
               (iVar12 + 3) * 0x40000 & 0xfc0000U |
               (iVar12 + 2) * 0x1000 & 0x3f000U |
               (iVar12 + 1) * 0x40 & 0xfc0U | uVar8 & 0x3f | *(uint *)(puVar10 + 8) & 0xff000000;
        }
        uVar8 = uVar8 + uVar11;
        uVar14 = uVar14 + 3;
        iVar6 = iVar6 + 1;
        puVar10 = puVar10 + 4;
        iVar20 = iVar20 + -1;
      } while (iVar20 != 0);
    }
    else if (iVar6 == 0) {
      if ((*(int *)(glContext + 0x23e0) == 0) || (*(int *)(glContext + 0x2768) == 0)) {
        uVar8 = 0;
        uVar14 = 0;
        puVar10 = puVar7 + 0xc0;
        iVar6 = 8;
        do {
          iVar20 = (int)(char)uVar8;
          uVar11 = uVar14 & 0x3f;
          uVar14 = uVar14 + 3;
          uVar16 = uVar8 & 0x3f;
          uVar8 = uVar8 + (uVar19 >> uVar11 & 7);
          *(uint *)(puVar10 + 8) =
               (iVar20 + 3) * 0x40000 & 0xfc0000U |
               (iVar20 + 2) * 0x1000 & 0x3f000U |
               (iVar20 + 1) * 0x40 & 0xfc0U | uVar16 | *(uint *)(puVar10 + 8) & 0xff000000;
          puVar10 = puVar10 + 4;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      else {
        uVar8 = 0;
        uVar14 = 0;
        iVar6 = 0;
        iVar20 = 8;
        puVar10 = puVar7 + 0xc0;
        do {
          glContextWord276c = *(int *)(glContext + 0x276c);
          cVar9 = (char)uVar8;
          if (glContextWord276c == iVar6) {
            uVar11 = 0x3e;
            *(uint *)(puVar10 + 8) =
                 (cVar9 + 1) * 0x40 & 0xfc0U | uVar8 & 0x3f | *(uint *)(puVar10 + 8) & 0xfffff000;
            if (2 < *(int *)(puVar7 + 0x210)) {
              uVar11 = (int)cVar9 + 2U & 0x3f;
            }
            *(uint *)(puVar7 + glContextWord276c * 4 + 200) =
                 uVar11 << 0xc | *(uint *)(puVar7 + glContextWord276c * 4 + 200) & 0xff000fff | 0xfc0000;
            uVar11 = *(uint *)(puVar7 + 0x210);
          }
          else {
            iVar12 = (int)cVar9;
            uVar11 = uVar19 >> (uVar14 & 0x3f) & 7;
            *(uint *)(puVar10 + 8) =
                 (iVar12 + 3) * 0x40000 & 0xfc0000U |
                 (iVar12 + 2) * 0x1000 & 0x3f000U |
                 (iVar12 + 1) * 0x40 & 0xfc0U | uVar8 & 0x3f | *(uint *)(puVar10 + 8) & 0xff000000;
          }
          uVar8 = uVar8 + uVar11;
          uVar14 = uVar14 + 3;
          iVar6 = iVar6 + 1;
          puVar10 = puVar10 + 4;
          iVar20 = iVar20 + -1;
        } while (iVar20 != 0);
      }
    }
    else if (*(int *)(glContext + 0x23e0) == 0) {
      uVar14 = 0;
      uVar8 = 0;
      iVar20 = 8;
      puVar10 = puVar7 + 0xc0;
      do {
        bVar2 = *(byte *)(iVar6 + 0x71);
        if (bVar2 == 0) {
          uVar16 = uVar8 + 3 & 0xff;
          uVar11 = uVar8 + 2 & 0xff;
        }
        else {
          uVar11 = 0x3e;
          if ((bVar2 & 4) != 0) {
            uVar11 = uVar8 + 2 & 0xff;
          }
          uVar16 = uVar8 + 3 & 0xff;
          if ((bVar2 & 8) == 0) {
            uVar16 = 0x3f;
          }
        }
        iVar12 = uVar8 + 1;
        uVar3 = uVar14 & 0x3f;
        iVar6 = iVar6 + 1;
        uVar14 = uVar14 + 3;
        uVar4 = uVar8 & 0x3f;
        uVar8 = uVar8 + (uVar19 >> uVar3 & 7);
        *(uint *)(puVar10 + 8) =
             (uVar16 & 0x3f) << 0x12 |
             (uVar11 & 0x3f) << 0xc |
             iVar12 * 0x40 & 0xfc0U | uVar4 | *(uint *)(puVar10 + 8) & 0xff000000;
        puVar10 = puVar10 + 4;
        iVar20 = iVar20 + -1;
      } while (iVar20 != 0);
    }
    else {
      uVar14 = 0;
      uVar8 = 0;
      iVar12 = 8;
      loopIndex = 0;
      puVar10 = puVar7 + 0xc0;
      do {
        uVar4 = *(uint *)(puVar10 + 8);
        iVar13 = (int)(char)uVar8;
        uVar11 = uVar14 & 0x3f;
        uVar14 = uVar14 + 3;
        uVar3 = uVar8 & 0x3f;
        uVar8 = uVar8 + (uVar19 >> uVar11 & 7);
        uVar11 = (iVar13 + 1) * 0x40 & 0xfc0;
        uVar16 = (iVar13 + 3) * 0x40000 & 0xfc0000;
        *(uint *)(puVar10 + 8) =
             uVar16 | (iVar13 + 2) * 0x1000 & 0x3f000U | uVar11 | uVar3 | uVar4 & 0xff000000;
        bVar2 = *(byte *)(iVar6 + 0x71);
        if (bVar2 != 0) {
          if ((bVar2 & 4) == 0) {
            *(uint *)(puVar10 + 8) = uVar16 | uVar11 | uVar3 | uVar4 & 0xff000000 | 0x3e000;
          }
          if ((bVar2 & 8) == 0) {
            *(uint *)(puVar10 + 8) = *(uint *)(puVar10 + 8) & 0xff03ffff | 0xfc0000;
          }
        }
        if (*(int *)(glContext + 0x276c) == loopIndex) {
          if (*(int *)(puVar7 + 0x210) == 2) {
            *(uint *)(puVar10 + 8) = *(uint *)(puVar10 + 8) & 0xfffc0fff | 0x3e000;
          }
          *(uint *)(puVar10 + 8) = *(uint *)(puVar10 + 8) & 0xff03ffff | 0xfc0000;
          uVar8 = uVar8 + *(int *)(puVar7 + 0x210);
        }
        loopIndex = loopIndex + 1;
        puVar10 = puVar10 + 4;
        iVar6 = iVar6 + 1;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    iVar6 = iVar18;
    if ((uVar8 == 0) && (iVar6 = 1, iVar18 != 0)) {
      iVar6 = iVar18;
    }
    uVar14 = iVar6 << 7 | uVar8 & 0x7f | 0x40000;
    *(uint *)(puVar7 + 0x8c) = (uVar15 ^ 1) << 10 | *(uint *)(puVar7 + 0x8c) & 0xffffe1ff;
    *(uint *)(puVar7 + 200) = *(uint *)(puVar7 + 200) & 0xf8ffffff;
    *(uint *)(puVar7 + 0x208) = uVar14;
    *(uint *)(puVar7 + 0xcc) = *(uint *)(puVar7 + 0xcc) & 0xf8ffffff | 0x1000000;
    *(uint *)(glContext + 0x1f2c) = uVar14;
    *(undefined4 *)(glContext + 0x1ee8) = *(undefined4 *)(puVar7 + 200);
    *(undefined4 *)(glContext + 0x1eec) = *(undefined4 *)(puVar7 + 0xcc);
    *(undefined4 *)(glContext + 0x1ef0) = *(undefined4 *)(puVar7 + 0xd0);
    *(undefined4 *)(glContext + 0x1ef4) = *(undefined4 *)(puVar7 + 0xd4);
    *(undefined4 *)(glContext + 0x1ef8) = *(undefined4 *)(puVar7 + 0xd8);
    *(undefined4 *)(glContext + 0x1efc) = *(undefined4 *)(puVar7 + 0xdc);
    *(undefined4 *)(glContext + 0x1f00) = *(undefined4 *)(puVar7 + 0xe0);
    uVar5 = *(undefined4 *)(puVar7 + 0xe4);
    *(uint *)(glContext + 0x1ba4) = uVar19;
    *(undefined4 *)(glContext + 0x1bb4) = glContextWord1bb0;
    *(undefined4 *)(glContext + 0x1f04) = uVar5;
    if ((*(uint *)(glContext + 0x44) & 0x20000000) != 0) {
      *(undefined4 *)(glContext + 0x277c) = 0xffffffff;
    }
  }
  return;
}

/* freeAndNullField @ 0x4cde0 (72 bytes) */
int freeAndNullField(param_1)
  int param_1;
{
  /* issue #74 / #79: this is the stock's plain free-and-null helper again. It used to carry a
   * malloc_size() guard because the bad values it freed on CGLDestroyContext teardown (0x84c1,
   * 0x110001 in #74; 0x24 in FUN_0004b5d0, #79) looked like table entries - the guard hid a
   * real bug instead of fixing it: FUN_000b5fb0 dropped the object it hands the destroy
   * callback (`lwz r4,0x1448(r30)`, loaded before the branch, so its indirect-call argument
   * count missed it) and the destructor ran on whatever r4 held. With that fixed, cgl_probe
   * runs clean on real hardware WITHOUT the guard (5 runs, zero malloc warnings). */
  if (*(int *)(param_1 + 0x10) != 0) {
    _free(*(int *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}

/* FUN_0004ce30 @ 0x4ce30 (680 bytes) */
int FUN_0004ce30(glContext)
  int glContext;
{
  int glState;
  short sVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint scHyperzEn;
  int zbBwCntl;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  glState = *(int *)(glContext + 4);
  uVar7 = *(uint *)(glContext + 0x1ae0);
  zbBwCntl = *(int *)(glContext + 0x1ab0);
  iVar9 = *(int *)(glState + 0x10);
  sVar1 = *(short *)(((unsigned char *)0x00002dc4) + iVar9);
  iVar8 = glState + 0x30;
  if (*(int *)(glState + 0x150) != 0) {
    iVar8 = *(int *)(glState + 0x150);
  }
  if (((((((unsigned char *)0x00002dc8)[iVar9] == '\0') || (((unsigned char *)0x00002e44)[iVar9] == '\0')) || (sVar1 == 0x200))
      || (sVar1 == 0x202)) ||
     (((*(double *)(0x00001830 + iVar9) == DOUBLE_001aa200 &&
       (*(double *)(iVar9 + 0x1838) == DOUBLE_001aa200)) && (sVar1 == 0x203)))) {
    bVar3 = false;
  }
  else {
    bVar3 = true;
  }
  if (((*(char *)(iVar8 + 0xc5) == '\0') && (((unsigned char *)0x00002dc8)[iVar9] != '\0')) &&
     ((*(uint *)(glContext + 0x44) & 0x200) == 0)) {
    switch(sVar1) {
    case 0x200:
    case 0x201:
    case 0x202:
    case 0x203:
      if ((*(uint *)(iVar8 + 0xc4) & 0xff00ff00) == 0) {
        bVar2 = true;
        iVar4 = 0x201;
      }
      else {
        bVar2 = false;
        iVar4 = 0x201;
      }
      break;
    case 0x204:
    case 0x205:
    case 0x206:
      if ((*(char *)(iVar8 + 0xc4) == '\0') && (*(char *)(iVar8 + 0xc6) != '\0')) {
        bVar2 = true;
        iVar4 = 0x204;
      }
      else {
        bVar2 = false;
        iVar4 = 0x204;
      }
      break;
    case 0x207:
      bVar2 = false;
      iVar4 = 0x207;
      break;
    default:
      bVar2 = false;
      iVar4 = 0x200;
    }
    if (((*(int *)(((unsigned char *)0x000031c0) + iVar9) == 0) ||
        ((((*(short *)(((unsigned char *)0x000031a2) + iVar9) == 0x1e00 &&
           (*(short *)(((unsigned char *)0x000031a4) + iVar9) == 0x1e00)) &&
          (*(short *)(((unsigned char *)0x000031ba) + iVar9) == 0x1e00)) &&
         (*(short *)(((unsigned char *)0x000031bc) + iVar9) == 0x1e00)))) && (!bVar2)) {
      if (iVar4 == 0x204) {
        scHyperzEn = *(uint *)(glContext + 0x1ae0) | 3;
        *(uint *)(glContext + 0x1ae0) = scHyperzEn;
        *(uint *)(glContext + 0x1ab0) = *(uint *)(glContext + 0x1ab0) | 3;
      }
      else if (iVar4 == 0x207) {
        scHyperzEn = *(uint *)(glContext + 0x1ae0) & 0xfffffffe;
        *(uint *)(glContext + 0x1ae0) = scHyperzEn;
        *(uint *)(glContext + 0x1ab0) = *(uint *)(glContext + 0x1ab0) | 1;
      }
      else {
        scHyperzEn = *(uint *)(glContext + 0x1ae0) & 0xfffffffd | 1;
        *(uint *)(glContext + 0x1ae0) = scHyperzEn;
        *(uint *)(glContext + 0x1ab0) = *(uint *)(glContext + 0x1ab0) & 0xfffffffd | 1;
      }
      *(byte *)(iVar8 + 0xc6) = (byte)((scHyperzEn ^ 2) >> 1) & 1;
      if (bVar3) {
        *(undefined1 *)(iVar8 + 0xc4) = 0;
        scHyperzEn = *(uint *)(glContext + 0x1ae0);
      }
      else {
        scHyperzEn = *(uint *)(glContext + 0x1ae0);
      }
      goto LAB_0004d0d0;
    }
  }
  scHyperzEn = *(uint *)(glContext + 0x1ae0) & 0xfffffffe;
  *(uint *)(glContext + 0x1ae0) = scHyperzEn;
  *(uint *)(glContext + 0x1ab0) = *(uint *)(glContext + 0x1ab0) & 0xfffffffe;
  if (bVar3) {
    *(undefined1 *)(iVar8 + 0xc5) = 1;
    scHyperzEn = *(uint *)(glContext + 0x1ae0);
  }
LAB_0004d0d0:
  if ((uVar7 == scHyperzEn) && (zbBwCntl == *(int *)(glContext + 0x1ab0))) {
    return;
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x1000;
  return;
}

/* FUN_0004d100 @ 0x4d100 (1264 bytes) */
int FUN_0004d100(glContext)
  int glContext;
{
  uint zbZstencilcntl;
  int rb3dColorChannelMask;
  int glContextWord1e5c;
  uint fgAlphaFunc;
  bool bVar1;
  bool bVar2;
  uint in_r5;
  uint in_r6;
  uint uVar3;
  int iVar4;
  uint zbCntl;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char cVar10;
  uint glContextWord44;
  uint glContextWord1ab8;
  
  fgAlphaFunc = *(uint *)(glContext + 0x1a4c);
  glContextWord1e5c = *(int *)(glContext + 0x1e5c);
  iVar6 = *(int *)(*(int *)(glContext + 4) + 0x10);
  if ((((*(uint *)(glContext + 0x1a80) & 1) == 0) || ((*(uint *)(glContext + 0x1aa0) & 6) == 6)) ||
     (*(char *)(glContext + 0x23ed) != '\0')) {
    cVar10 = ((unsigned char *)0x00002d66)[iVar6];
    goto LAB_0004d234;
  }
  if (((unsigned char *)0x00002d66)[iVar6] == '\0') {
    cVar10 = '\0';
    if (((*(short *)(((unsigned char *)0x00002d80) + iVar6) != -0x7ffa) ||
        (*(int *)(((unsigned char *)0x00002d68) + iVar6) != *(int *)(((unsigned char *)0x00002d6c) + iVar6))) ||
       (((unsigned char *)0x00002b7e)[*(int *)(glContext + 4)] != '\0')) {
LAB_0004d234:
      if (cVar10 != '\0') goto LAB_0004d240;
      goto LAB_0004d260;
    }
    in_r5 = (uint)*(ushort *)(((unsigned char *)0x00002d68) + iVar6);
    in_r6 = (uint)*(ushort *)(((unsigned char *)0x00002d6a) + iVar6);
    bVar1 = (*(uint *)(glContext + 0x8c) & 0x400000) == 0;
    if (((bVar1) || (*(char *)(glContext + 0x2450) == '\0')) ||
       (bVar2 = true, (int)*(uint *)(glContext + 0x8c) < 0)) {
      bVar2 = false;
    }
    if (((bVar1) || (in_r5 != 0x302)) || (bVar1 = false, in_r6 != 0x303)) {
      if (bVar2) {
        if (in_r5 == 0) {
          if (in_r6 == 0x301) {
LAB_0004d20c:
            if ((*(int *)(((unsigned char *)0x00001098) + glContextWord1e5c) == 1) &&
               (bVar1 = true, *(double *)(0x00001830 + iVar6) != *(double *)(iVar6 + 0x1838)))
            goto LAB_0004d5c4;
          }
        }
        else if (((in_r5 == 1) || (in_r5 == 0x306)) && (in_r6 == 1)) goto LAB_0004d20c;
      }
      goto LAB_0004d234;
    }
LAB_0004d5c4:
    *(uint *)(glContext + 0x1a4c) = *(uint *)(glContext + 0x1a4c) | 0x800;
    *(undefined1 *)(glContext + 0x1a4f) = 0;
    uVar7 = *(uint *)(glContext + 0x1a4c) & 0xfffff8ff | 0x400;
    *(uint *)(glContext + 0x1a4c) = uVar7;
  }
  else {
LAB_0004d240:
    if (*(short *)(((unsigned char *)0x00002d64) + iVar6) == 0x207) {
LAB_0004d260:
      bVar1 = false;
      uVar7 = *(uint *)(glContext + 0x1a4c) & 0xfffff7ff;
      *(uint *)(glContext + 0x1a4c) = uVar7;
    }
    else {
      bVar1 = false;
      uVar7 = *(uint *)(glContext + 0x1a4c) | 0x800;
      *(uint *)(glContext + 0x1a4c) = uVar7;
    }
  }
  if (fgAlphaFunc != uVar7) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x200;
  }
  if (bVar1) {
    *(uint *)(glContext + 0x18a4) = *(uint *)(glContext + 0x18a4) | 0x10;
    if ((*(uint *)(((unsigned char *)0x00001544) + glContextWord1e5c) & 0x10) == 0) {
LAB_0004d2c8:
      FUN_000b6580(glContext,0);
      (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,0);
      (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
    }
  }
  else {
    *(uint *)(glContext + 0x18a4) = *(uint *)(glContext + 0x18a4) & 0xffffffef;
    if ((*(uint *)(((unsigned char *)0x00001544) + glContextWord1e5c) & 0x10) != 0) goto LAB_0004d2c8;
  }
  ((int (*)())FUN_0004ce30)(glContext);
  zbCntl = *(uint *)(glContext + 0x1aa0);
  glContextWord1ab8 = *(uint *)(glContext + 0x1ab8);
  iVar4 = *(int *)(glContext + 4);
  uVar7 = glContextWord1ab8 | 1;
  *(uint *)(glContext + 0x1ab8) = uVar7;
  if ((((zbCntl & 6) != 6) && (((unsigned char *)0x00002b7e)[iVar4] == '\0')) &&
     (*(char *)(glContext + 0x23ed) == '\0')) {
    uVar8 = *(uint *)(glContext + 0x1a4c);
    glContextWord44 = *(uint *)(glContext + 0x44);
    goto LAB_0004d460;
  }
  uVar8 = *(uint *)(glContext + 0x1a4c);
  if ((uVar8 & 0x800) == 0) {
    glContextWord44 = *(uint *)(glContext + 0x44);
    if ((glContextWord44 & 0x60020000) != 0x40000000) {
      if ((((unsigned char *)0x00002e2d)[*(int *)(iVar4 + 0x10)] != '\0') && ((glContextWord44 & 0x20000) == 0)) {
        iVar4 = FUN_0001a010(iVar4,*(undefined4 *)(iVar4 + 0x26a0),in_r5,in_r6,fgAlphaFunc,zbCntl,uVar8);
        if (iVar4 == 0) {
          zbCntl = *(uint *)(glContext + 0x1aa0);
          uVar8 = *(uint *)(glContext + 0x1a4c);
          uVar7 = *(uint *)(glContext + 0x1ab8);
          goto LAB_0004d440;
        }
        iVar4 = *(int *)(glContext + 4);
        zbCntl = *(uint *)(glContext + 0x1aa0);
        uVar8 = *(uint *)(glContext + 0x1a4c);
        uVar7 = *(uint *)(glContext + 0x1ab8);
        glContextWord44 = *(uint *)(glContext + 0x44);
      }
      iVar4 = *(int *)(iVar4 + 0x10);
      if (((((((unsigned char *)0x00002e2c)[iVar4] == '\0') || ((glContextWord44 & 0x20000) != 0)) ||
           (*(short *)(((unsigned char *)0x00002e28) + iVar4) == -1)) &&
          (((((unsigned char *)0x00003178)[iVar4] == '\0' || ((glContextWord44 & 0x20000) != 0)) ||
           ((*(short *)(((unsigned char *)0x00003170) + iVar4) != 0x1b02 &&
            (*(short *)(((unsigned char *)0x00003172) + iVar4) != 0x1b02)))))) &&
         (((uVar8 & 0x10000) == 0 && ((glContextWord44 & 0x2000100) == 0)))) goto LAB_0004d460;
    }
  }
  else {
LAB_0004d440:
    glContextWord44 = *(uint *)(glContext + 0x44);
  }
  uVar7 = uVar7 & 0xfffffffe;
  *(uint *)(glContext + 0x1ab8) = uVar7;
LAB_0004d460:
  if ((((uVar8 & 0x800) != 0) && (*(int *)(glContext + 0x27b0) == 1)) &&
     (uVar8 = *(uint *)(glContext + 0x8c) & 0x400000, uVar8 != 0)) {
    uVar7 = uVar7 & 0xfffffffe;
    *(uint *)(glContext + 0x1ab8) = uVar7;
  }
  if (((zbCntl & 2) != 0) && ((glContextWord44 >> 9 & 1) != 0)) {
    uVar7 = uVar7 & 0xfffffffe;
    *(uint *)(glContext + 0x1ab8) = uVar7;
  }
  if (glContextWord1ab8 != uVar7) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x20000;
  }
  if (*(int *)(glContext + 0x23dc) != 1) {
    uVar7 = *(uint *)(glContext + 0x1bd4);
    zbZstencilcntl = *(uint *)(glContext + 0x1aa4);
    iVar4 = FUN_0001a010(*(undefined4 *)(glContext + 4),*(undefined4 *)(glContext + 0x2460),in_r5,in_r6,
                         fgAlphaFunc,zbCntl,uVar8);
    if (iVar4 == 0) {
      if ((*(uint *)(glContext + 0x1ab8) & 1) == 0) {
        uVar3 = *(uint *)(glContext + 0x1bd4) & 0xfffffffe;
        *(uint *)(glContext + 0x1bd4) = uVar3;
        *(uint *)(glContext + 0x1aa4) = *(uint *)(glContext + 0x1aa4) & 0xf7ffffff;
      }
      else {
        rb3dColorChannelMask = *(int *)(0x00001af4 + glContext);
        uVar3 = *(uint *)(glContext + 0x1bd4) | 1;
        *(uint *)(glContext + 0x1bd4) = uVar3;
        if (rb3dColorChannelMask == 0) {
          *(uint *)(glContext + 0x1aa4) = *(uint *)(glContext + 0x1aa4) | 0x8000000;
        }
        else {
          *(uint *)(glContext + 0x1aa4) = *(uint *)(glContext + 0x1aa4) & 0xf7ffffff;
        }
      }
    }
    else {
      uVar3 = *(uint *)(glContext + 0x1bd4);
      if ((uVar3 & 1) != 0) {
        uVar3 = uVar3 & 0xfffffffe;
        *(uint *)(glContext + 0x1bd4) = uVar3;
        *(uint *)(glContext + 0x1aa4) = *(uint *)(glContext + 0x1aa4) & 0xf7ffffff;
      }
    }
    if (((uVar7 & 1) != (uVar3 & 1)) ||
       ((zbZstencilcntl >> 0x1b & 1) != (*(uint *)(glContext + 0x1aa4) >> 0x1b & 1))) {
      *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x20800;
    }
  }
  return;
}

/* FUN_0004d620 @ 0x4d620 (328 bytes) */
void FUN_0004d620(int glContext,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1)
{
  uint loopIndex;
  int iVar1;
  char cVar2;
  int iVar3;
  uint glContextWord44;
  int iVar5;
  
  glContextWord44 = *(uint *)(glContext + 0x44);
  if ((glContextWord44 & 0x20000) == 0) {
    FUN_000b6580(glContext,0);
                    
                    
    (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
    return;
  }
  if ((glContextWord44 & 0x2000) != 0) {
    ((undefined4 (*)())FUN_000afe40)(glContext,0,param_3,param_4,fparam_1);
    return;
  }
  if ((glContextWord44 & 0x80100000) == 0x80000000) {
    if (*(short *)(((unsigned char *)0x00002d48) + *(int *)(*(int *)(glContext + 4) + 0x10)) == -0x7e06)
    goto LAB_0004d6ac;
  }
  else if ((glContextWord44 & 0x800000) != 0) {
LAB_0004d6ac:
    cVar2 = '\x01';
    goto LAB_0004d6b0;
  }
  cVar2 = '\0';
LAB_0004d6b0:
  iVar5 = *(int *)(((unsigned char *)0x00001154) + glContext);
  if (*(int *)(iVar5 + 4) != 0) {
    loopIndex = 0;
    iVar3 = 0;
    do {
      iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + glContext) * 4 +
                      *(int *)(iVar3 + *(int *)(iVar5 + 0x88) + 0x70));
      if ((iVar1 != 0) && (((unsigned char *)0x0000120c)[iVar1] != cVar2)) {
        *(undefined4 *)(((unsigned char *)0x000016f0) + iVar1) = 1;
        *(undefined1 *)(iVar1 + 0x119) = 1;
        iVar5 = *(int *)(((unsigned char *)0x00001154) + glContext);
      }
      loopIndex = loopIndex + 1;
      iVar3 = iVar3 + 0x78;
    } while (loopIndex < *(uint *)(iVar5 + 4));
  }
  atifsCompileCurrentShader(glContext);
  return;
}

/* FUN_0004d770 @ 0x4d770 (840 bytes) */
void FUN_0004d770(int glContext,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  uint uVar7;
  int glState;
  int glContextWord1c98;
  int glContextWord1c9c;
  int glContextWord1c90;
  int glContextWord1c94;
  int glContextWord1c88;
  uint glContextWord1b14;
  int glContextWord1c8c;
  int iVar16;
  
  dVar6 = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa10c;
  glState = *(int *)(glContext + 4);
  glContextWord1c9c = *(int *)(glContext + 0x1c9c);
  glContextWord1c98 = *(int *)(glContext + 0x1c98);
  glContextWord1c88 = *(int *)(glContext + 0x1c88);
  glContextWord1c94 = *(int *)(glContext + 0x1c94);
  glContextWord1c90 = *(int *)(glContext + 0x1c90);
  glContextWord1c8c = *(int *)(glContext + 0x1c8c);
  iVar16 = *(int *)(glState + 0x10);
  fVar1 = *(float *)(glState + 0x2a58);
  fVar2 = *(float *)(glState + 0x2a54);
  *(undefined4 *)(glContext + 0x1c9c) = *(undefined4 *)(iVar16 + 0x1818);
  *(undefined4 *)(glContext + 0x1c98) = *(undefined4 *)(iVar16 + 0x1828);
  uVar7 = *(uint *)(iVar16 + 0x1840);
  fVar3 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar16 + 0x184c) ^ 0x80000000) -
                         dVar6) * fVar4;
  fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar16 + 0x1844) ^ 0x80000000) -
                         dVar6) + fVar3;
  fVar4 = fVar2 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar16 + 0x1848) ^ 0x80000000) -
                         dVar6) * fVar4;
  if (*(char *)(glContext + 0x293c) != '\0') {
    fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(glState + 0x160) ^ 0x80000000) -
                           dVar6) - fVar5;
    fVar3 = -fVar3;
  }
  *(float *)(glContext + 0x1c8c) = fVar4;
  *(float *)(glContext + 0x1c88) =
       fVar2 * (float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - dVar6) + fVar4;
  *(float *)(glContext + 0x1c94) = fVar3;
  *(float *)(glContext + 0x1c90) = fVar5;
  if (*(char *)(glContext + 0x124) != '\0') {
    *(undefined4 *)(glContext + 0x1c8c) = *(undefined4 *)(glContext + 0x2814);
    *(undefined4 *)(glContext + 0x1c94) = *(undefined4 *)(glContext + 0x2818);
  }
  *(undefined4 *)(glContext + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cb0) = 0x3f800000;
  if (((((glContextWord1c8c != *(int *)(glContext + 0x1c8c)) || (glContextWord1c88 != *(int *)(glContext + 0x1c88))) ||
       (glContextWord1c94 != *(int *)(glContext + 0x1c94))) ||
      ((glContextWord1c90 != *(int *)(glContext + 0x1c90) || (glContextWord1c9c != *(int *)(glContext + 0x1c9c))))) ||
     (glContextWord1c98 != *(int *)(glContext + 0x1c98))) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x80;
  }
  glContextWord1b14 = *(uint *)(0x00001b14 + glContext);
  uVar7 = glContextWord1b14 & 0xfffffff8;
  *(uint *)(0x00001b14 + glContext) = uVar7;
  if ((((*(uint *)(((unsigned char *)0x0000317cU) + iVar16) & 0xffff0000) != 0) || (((unsigned char *)0x0000317b)[iVar16] != '\0'))
     && ((*(float *)(((unsigned char *)0x0000316c) + iVar16) != FLOAT_001aa0d4 ||
         (*(float *)(((unsigned char *)0x00003168) + iVar16) != FLOAT_001aa0d4)))) {
    if (((unsigned char *)0x0000317b)[iVar16] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + iVar16) == 0x1b00) {
        uVar7 = uVar7 | 1;
        *(uint *)(0x00001b14 + glContext) = uVar7;
      }
      if (*(short *)(((unsigned char *)0x00003172) + iVar16) == 0x1b00) {
        uVar7 = uVar7 | 2;
        *(uint *)(0x00001b14 + glContext) = uVar7;
      }
    }
    if (((unsigned char *)0x0000317c)[iVar16] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + iVar16) == 0x1b01) {
        uVar7 = uVar7 | 1;
        *(uint *)(0x00001b14 + glContext) = uVar7;
      }
      if (*(short *)(((unsigned char *)0x00003172) + iVar16) == 0x1b01) {
        uVar7 = uVar7 | 2;
        *(uint *)(0x00001b14 + glContext) = uVar7;
      }
    }
    if (((unsigned char *)0x0000317d)[iVar16] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + iVar16) == 0x1b02) {
        uVar7 = uVar7 | 1;
        *(uint *)(0x00001b14 + glContext) = uVar7;
      }
      if (*(short *)(((unsigned char *)0x00003172) + iVar16) == 0x1b02) {
        uVar7 = uVar7 | 2;
        *(uint *)(0x00001b14 + glContext) = uVar7;
      }
    }
    fVar1 = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(glContext + 8)) - DOUBLE_001aa250) *
            *(float *)(((unsigned char *)0x00003168) + iVar16);
    fVar2 = FLOAT_001aa104;
    if ((*(uint *)(*(int *)(glContext + 4) + 0x154) & 0x30000) == 0x10000) {
      fVar2 = FLOAT_001aa164;
    }
    fVar3 = *(float *)(((unsigned char *)0x0000316c) + iVar16);
    *(float *)(glContext + 0x1b24) = fVar1;
    *(float *)(glContext + 0x1b1c) = fVar1;
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x20;
    *(float *)(glContext + 0x1b20) = fVar2 * fVar3;
    *(float *)(glContext + 0x1b18) = fVar2 * fVar3;
  }
  if (glContextWord1b14 != uVar7) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x20;
  }
  return;
}

/* gldValidateDepthTest @ 0x4dac0 (272 bytes) */
int gldValidateDepthTest(glContext)
  int glContext;
{
  int glState;
  uint oldZControl;
  uint depthControl;
  uint depthFunc;
  
  glState = *(int *)(*(int *)(glContext + 4) + 0x10);
  if ((((unsigned char *)0x00002dc8)[glState] == '\0') || (((unsigned char *)0x00001490)[glContext] == '\0')) {
    oldZControl = *(uint *)(glContext + 0x1930);
    *(uint *)(glContext + 0x1aa0) = *(uint *)(glContext + 0x1aa0) & 0xfffffffd;
  }
  else {
    depthFunc = (uint)*(ushort *)(((unsigned char *)0x00002dc4) + glState);
    depthControl = *(uint *)(glContext + 0x1aa0);
    oldZControl = *(uint *)(glContext + 0x1a50);
    *(uint *)(glContext + 0x1aa0) = depthControl | 2;
    if ((depthFunc == 0x202) ||
       (((depthFunc == 0x203 && (*(double *)(0x00001830 + glState) == DOUBLE_001aa200)) &&
        (*(double *)(glState + 0x1838) == DOUBLE_001aa200)))) {
      *(uint *)(glContext + 0x1aa0) = depthControl & 0xfffffffb | 2;
    }
    else {
      *(uint *)(glContext + 0x1aa0) = ((byte)((unsigned char *)0x00002e44)[glState] & 1) << 2 | depthControl & 0xfffffffb | 2
      ;
    }
    *(uint *)(glContext + 0x1aa4) =
         *(uint *)(&DAT_001db368 + (depthFunc & 7) * 4) & 7 | *(uint *)(glContext + 0x1aa4) & 0xfffffff8;
    if ((*(uint *)(glContext + 0x44) & 0x200) == 0) {
      depthControl = oldZControl & 0xfffffffe;
      *(uint *)(glContext + 0x1a50) = depthControl;
    }
    else {
      depthControl = oldZControl | 1;
      *(uint *)(glContext + 0x1a50) = depthControl;
    }
    if (oldZControl == depthControl) {
      oldZControl = *(uint *)(glContext + 0x1930);
    }
    else {
      oldZControl = *(uint *)(glContext + 0x1930) | 0x8000000;
      *(uint *)(glContext + 0x1930) = oldZControl;
    }
  }
  *(uint *)(glContext + 0x1930) = oldZControl | 0x800;
  return;
}

/* FUN_0004dbe0 @ 0x4dbe0 (76 bytes) */
int FUN_0004dbe0(glContext)
  int glContext;
{
  if (*(char *)(glContext + 0x124) != '\0') {
    FUN_00083110(glContext);
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x40000;
  return;
}

/* gldValidateTexEnvColor @ 0x4dc30 (220 bytes) */
int gldValidateTexEnvColor(glContext)
  int glContext;
{
  int constantOffset;
  uint unit;
  int unitState;
  int programConstants;
  int shadowCursor;
  uint unitCount;
  
  if ((*(uint *)(glContext + 0x44) & 0x20000) != 0) {
    return;
  }
  unitCount = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
  if ((uint)*(byte *)(glContext + 0x2b) <= (uint)(byte)((unsigned char *)0x000013b2)[glContext]) {
    unitCount = (uint)*(byte *)(glContext + 0x2b);
  }
  if (unitCount != 0) {
    unit = 0;
    unitState = glContext;
    shadowCursor = glContext;
    do {
      *(undefined4 *)(shadowCursor + 0x1f38) = *(undefined4 *)(unitState + 0x47c);
      *(undefined4 *)(shadowCursor + 0x1f3c) = *(undefined4 *)(unitState + 0x480);
      *(undefined4 *)(shadowCursor + 8000) = *(undefined4 *)(unitState + 0x484);
      *(undefined4 *)(shadowCursor + 0x1f44) = *(undefined4 *)(unitState + 0x488);
      programConstants = *(int *)(glContext + 0x1e68);
      if (programConstants != 0) {
        if ((1 << (unit & 0x3f) & *(uint *)(((unsigned char *)0x000010d8) + programConstants)) != 0) {
          constantOffset = unit * 0x10;
          *(undefined4 *)(constantOffset + programConstants + 0x8c) = *(undefined4 *)(shadowCursor + 0x1f38);
          *(undefined4 *)(constantOffset + *(int *)(glContext + 0x1e68) + 0x90) =
               *(undefined4 *)(shadowCursor + 0x1f3c);
          *(undefined4 *)(constantOffset + *(int *)(glContext + 0x1e68) + 0x94) = *(undefined4 *)(shadowCursor + 8000)
          ;
          *(undefined4 *)(constantOffset + *(int *)(glContext + 0x1e68) + 0x98) =
               *(undefined4 *)(shadowCursor + 0x1f44);
        }
      }
      unit = unit + 1;
      unitState = unitState + 0xcc;
      shadowCursor = shadowCursor + 0x10;
      unitCount = unitCount - 1;
    } while (unitCount != 0);
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x4000000;
  return;
}

/* gldEmitScissorRegs @ 0x4dd10 (40 bytes) */
int gldEmitScissorRegs(glContext, packet)
  int glContext;
  undefined4 *packet;
{
  *packet = 0x110f8;
  packet[1] = *(undefined4 *)(glContext + 7000);
  packet[2] = *(undefined4 *)(glContext + 0x1b10);
  return packet + 3;
}

/* gldEmitViewportAndGuardBand @ 0x4dd40 (116 bytes) */
int gldEmitViewportAndGuardBand(glContext, packet)
  int glContext;
  undefined4 *packet;
{
  undefined4 glContextWord1c98;
  
  *packet = 0x50766;
  packet[1] = *(undefined4 *)(glContext + 0x1c8c);
  packet[2] = *(undefined4 *)(glContext + 0x1c88);
  packet[3] = *(undefined4 *)(glContext + 0x1c94);
  packet[4] = *(undefined4 *)(glContext + 0x1c90);
  packet[5] = *(undefined4 *)(glContext + 0x1c9c);
  glContextWord1c98 = *(undefined4 *)(glContext + 0x1c98);
  packet[7] = 0x30888;
  packet[6] = glContextWord1c98;
  packet[8] = *(undefined4 *)(glContext + 0x1ca8);
  packet[9] = *(undefined4 *)(glContext + 0x1cac);
  packet[10] = *(undefined4 *)(glContext + 0x1cb0);
  packet[0xb] = *(undefined4 *)(glContext + 0x1cb4);
  return packet + 0xc;
}

/* FUN_0004ddc0 @ 0x4ddc0 (104 bytes) */
int FUN_0004ddc0(glContext)
  int glContext;
{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
  *(undefined4 **)(0x00002748 + glContext + 4) = puVar1;
  puVar1[1] = 0;
  *puVar1 = ((unsigned char *)0x00001040U);
  UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
  *(int *)(0x00002748 + glContext + 4) = *(int *)(0x00002748 + glContext + 4) + 8;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContext,*(int *)(0x00002748 + glContext + 4));
  return;
}

/* FUN_0004de30 @ 0x4de30 (180 bytes) */
int FUN_0004de30(glContext, param_2, param_3, param_4, param_5, param_6)
  int glContext;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 *param_5;
  int param_6;
{
  undefined4 *puVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_2 == 0) {
    if (((*(uint *)(glContext + 0x44) & 0x20000) == 0) ||
       (iVar2 = *(int *)(glContext + 0x1e70), iVar2 == 0)) {
      iVar2 = *(int *)(glContext + 0x1e5c);
    }
  }
  else {
    iVar2 = param_2 + 0x124;
  }
  if (0 < param_6) {
    pcVar3 = ((unsigned char *)0x00002ddcU) + param_4 + iVar2;
    puVar1 = (undefined4 *)(param_4 * 0x10 + iVar2 + 0x8c);
    do {
      if ((*pcVar3 != '\0') && (pcVar3[0x100] == '\0')) {
        *puVar1 = *param_5;
        puVar1[1] = param_5[1];
        puVar1[2] = param_5[2];
        puVar1[3] = param_5[3];
      }
      pcVar3 = pcVar3 + 1;
      param_5 = param_5 + 4;
      puVar1 = puVar1 + 4;
      param_6 = param_6 + -1;
    } while (param_6 != 0);
  }
  ((unsigned char *)0x000010eb)[iVar2] = 0;
  return;
}

/* FUN_0004def0 @ 0x4def0 (2428 bytes) */
double FUN_0004def0(int glContext,undefined4 param_2,uint param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  uint glContextWord44;
  int glContextWord27b4;
  uint txEnable;
  uint loopIndex;
  uint loopIndex2;
  int *piVar1;
  float fVar2;
  short sVar3;
  ushort uVar4;
  float fVar5;
  bool bVar6;
  double dVar7;
  char cVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int glContextWord1808;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  double extraout_f1;
  double in_stack_ffffff28;
  
  uVar4 = *(ushort *)(glContext + 0x32) | *(ushort *)(glContext + 0x34);
  uVar20 = (uint)uVar4;
  if ((uVar4 != 0) && (*(char *)(glContext + 0x121) != '\0')) {
    uVar9 = (uint)(byte)((unsigned char *)0x000013b0)[glContext];
    if (uVar9 == 0) {
LAB_0004df78:
      *(undefined1 *)(glContext + 0x120) = 0xff;
    }
    else {
      uVar26 = 0;
      if (*(int *)(glContext + 0x48) != 0) {
        uVar26 = 0;
        iVar17 = glContext;
        do {
          uVar26 = uVar26 + 1;
          uVar9 = uVar9 - 1;
          if (uVar9 == 0) goto LAB_0004df78;
          piVar1 = (int *)(iVar17 + 0x4c);
          iVar17 = iVar17 + 4;
        } while (*piVar1 != 0);
        uVar26 = uVar26 & 0xff;
      }
      *(char *)(glContext + 0x120) = (char)uVar26;
      *(uint *)(glContext + 0x1878) = (uVar26 & 7) << 0x15 | *(uint *)(glContext + 0x1878) & 0xff1fffff;
      *(uint *)(glContext + 0x18a4) = (uVar26 & 7) << 0x1a | *(uint *)(glContext + 0x18a4) & 0xe3ffffff;
    }
  }
  glContextWord27b4 = *(int *)(glContext + 0x27b4);
  glContextWord1808 = *(int *)(glContext + 0x1808);
  txEnable = *(uint *)(glContext + 0x27b0) & ~(glContextWord27b4 << 8);
  *(uint *)(glContext + 0x27b0) = txEnable;
  dVar7 = DOUBLE_001aa1e0;
  if (uVar4 != 0) {
    iVar10 = glContext + 0x28b4;
    loopIndex = 0;
    uVar9 = 0;
    iVar25 = glContext + 0x20;
    iVar17 = glContext;
    iVar22 = glContext;
    iVar23 = glContext;
    iVar24 = glContext;
    iVar27 = glContext;
    do {
      if ((uVar20 & 1) != 0) {
        if (glContextWord1808 == 0) {
          iVar18 = *(int *)(((unsigned char *)0x000013f8) + iVar22);
          if (iVar18 == 0) {
            *(uint *)(glContext + 0x27b0) = *(uint *)(glContext + 0x27b0) & ~(1 << (loopIndex & 0x3f));
          }
          else {
            uVar11 = 1 << (loopIndex & 0x3f);
            *(uint *)(glContext + 0x1934) = uVar11 | *(uint *)(glContext + 0x1934);
            *(uint *)(glContext + 0x27b0) = uVar11 | *(uint *)(glContext + 0x27b0);
            *(undefined4 *)(iVar27 + 0x1d5c) = *(undefined4 *)(iVar18 + 0x1c);
            *(undefined4 *)(iVar27 + 0x1d9c) = *(undefined4 *)(iVar18 + 0x20);
            *(undefined4 *)(iVar27 + 0x1ddc) = *(undefined4 *)(iVar18 + 0x24);
            *(undefined4 *)(iVar25 + 0x1dfc) = *(undefined4 *)(iVar18 + 0x28);
            *(uint *)(iVar27 + 0x1cdc) = uVar9 << 0x1c | *(uint *)(iVar18 + 0x14) & 0xfffffff;
            *(uint *)(iVar27 + 0x1d1c) =
                 (*(ushort *)(iVar24 + 0x46e) & 0x3ff) << 3 | *(uint *)(iVar18 + 0x18) & 0xffffe007;
            param_4 = *(undefined4 *)(&DAT_001db98c + (uint)*(byte *)(glContext + 0x2941) * 4);
            param_3 = loopIndex;
            fparam_1 = (double)((double (*)())FUN_000b6f20)(glContext,iVar18,loopIndex,param_4,fparam_1,fparam_2,fparam_3
                                            ,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                                            in_stack_ffffff28);
          }
        }
        else {
          uVar11 = 1 << (loopIndex & 0x3f);
          *(uint *)(glContext + 0x1934) = uVar11 | *(uint *)(glContext + 0x1934);
          if ((loopIndex == *(uint *)(glContext + 0x276c)) && (*(int *)(glContext + 0x2768) != 0)) {
            iVar18 = *(int *)(*(int *)(glContext + 0x2768) + 0xbc);
          }
          else {
            iVar18 = *(int *)(((unsigned char *)0x000013f8) + iVar22);
            if (iVar18 == 0) {
              *(uint *)(glContext + 0x27b0) = ~uVar11 & *(uint *)(glContext + 0x27b0);
              *(uint *)(glContext + 0x27b4) = ~uVar11 & *(uint *)(glContext + 0x27b4);
              goto LAB_0004e760;
            }
          }
          if ((*(uint *)(glContext + 0x44) & 0x20000) == 0) {
            if (((int)(uint)*(byte *)(glContext + 0x20) >> (loopIndex & 0x3f) & 1U) == 0) {
              bVar6 = false;
              iVar16 = loopIndex << 2;
              *(uint *)(glContext + 0x27b4) = *(uint *)(glContext + 0x27b4) & ~uVar11;
            }
            else {
              iVar16 = loopIndex * 0x10;
              uVar13 = *(uint *)(iVar23 + 0x2854);
              uVar12 = *(uint *)(iVar23 + 0x2858);
              iVar15 = iVar10 + iVar16;
              if (*(char *)(iVar17 + 0x21) == '\x01') {
                fVar2 = (float)((double)CONCAT44(0x43300000,*(uint *)(iVar23 + 0x285c) ^ 0x80000000)
                               - dVar7);
                *(float *)(iVar10 + iVar16) =
                     *(float *)(iVar18 + 0x44) /
                     (float)((double)CONCAT44(0x43300000,uVar13 ^ 0x80000000) - dVar7);
                *(float *)(iVar15 + 4) = *(float *)(iVar18 + 0x44) / fVar2;
                fVar5 = (float)((double)CONCAT44(0x43300000,uVar13 + uVar12 ^ 0x80000000) - dVar7) *
                        FLOAT_001aa10c;
                *(float *)(iVar15 + 8) =
                     -(float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) - dVar7) / fVar2;
                *(float *)(iVar15 + 0xc) = fVar5 / *(float *)(iVar18 + 0x44);
              }
              else {
                fVar2 = (float)((double)CONCAT44(0x43300000,*(uint *)(iVar23 + 0x285c) ^ 0x80000000)
                               - dVar7);
                *(float *)(iVar10 + iVar16) =
                     *(float *)(iVar18 + 0x48) /
                     (float)((double)CONCAT44(0x43300000,uVar13 ^ 0x80000000) - dVar7);
                *(float *)(iVar15 + 4) = *(float *)(iVar18 + 0x48) / fVar2;
                fVar5 = (float)((double)CONCAT44(0x43300000,uVar13 + uVar12 ^ 0x80000000) - dVar7) *
                        FLOAT_001aa10c;
                *(float *)(iVar15 + 8) =
                     -(float)((double)CONCAT44(0x43300000,uVar12 ^ 0x80000000) - dVar7) / fVar2;
                *(float *)(iVar15 + 0xc) = fVar5 / *(float *)(iVar18 + 0x48);
              }
              iVar16 = loopIndex << 2;
              fparam_1 = (double)((int (*)())FUN_0004de30)(glContext,0,loopIndex + 0x14,loopIndex + 0x14,iVar15,1);
              bVar6 = false;
              *(uint *)(glContext + 0x27b4) = uVar11 | *(uint *)(glContext + 0x27b4);
            }
          }
          else {
            iVar16 = loopIndex * 4;
            sVar3 = *(short *)(iVar18 + 0x38);
            *(uint *)(iVar16 + *(int *)(((unsigned char *)0x00001144) + glContext) + 0x2c) =
                 (uint)*(byte *)(iVar18 + 0x30);
            iVar15 = *(int *)(((unsigned char *)0x00001154) + glContext);
            if (*(int *)(iVar15 + 4) != 0) {
              loopIndex2 = 0;
              iVar14 = 0;
              do {
                iVar19 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + glContext) * 4 +
                                 *(int *)(iVar14 + *(int *)(iVar15 + 0x88) + 0x70));
                if ((iVar19 != 0) &&
                   ((bool)((unsigned char *)0x00002eb0)[loopIndex + iVar19] != (*(char *)(iVar18 + 0x30) == '\x02')))
                {
                  *(undefined4 *)(((unsigned char *)0x000016f0) + iVar19) = 1;
                  *(undefined1 *)(iVar19 + 0x119) = 1;
                  iVar15 = *(int *)(((unsigned char *)0x00001154) + glContext);
                }
                loopIndex2 = loopIndex2 + 1;
                iVar14 = iVar14 + 0x78;
              } while (loopIndex2 < *(uint *)(iVar15 + 4));
            }
            if ((*(uint *)(glContext + 0x44) & 0x2000) == 0) {
LAB_0004e294:
              bVar6 = false;
            }
            else {
              iVar15 = *(int *)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 +
                               *(int *)(*(int *)(((unsigned char *)0x0000121c) + glContext) + 0x70));
              if (iVar15 != 0) {
                iVar14 = iVar15 + 0x124;
              }
              else {
                iVar14 = 0;
              }
              uVar13 = 0;
              if (sVar3 == 0x1902) {
                uVar12 = (*(ushort *)(iVar18 + 0x5c) - 0x200) * 2;
                uVar13 = uVar12 | 1;
                if (*(short *)(iVar18 + 0x58) == 0x1909) {
                  uVar13 = uVar12 | 0x11;
                }
                else if (*(short *)(iVar18 + 0x58) == -0x7fb7) {
                  uVar13 = uVar12 | 0x21;
                }
              }
              if (iVar14 == 0) goto LAB_0004e294;
              if ((uVar13 != *(uint *)(((unsigned char *)0x000015d0) + iVar16 + iVar14)) &&
                 (*(undefined4 *)(((unsigned char *)0x000015cc) + iVar14) = 1, iVar15 != 0)) {
                *(undefined1 *)(iVar15 + 0x119) = 1;
              }
              if (((unsigned char *)0x00001610)[loopIndex + iVar14] == '\0') goto LAB_0004e294;
              bVar6 = true;
              if (*(float *)(((unsigned char *)0x00001620) + iVar16 + iVar14) !=
                  *(float *)(iVar18 + 0x4c) + *(float *)(iVar24 + 0x470)) {
                iVar15 = *(int *)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 +
                                 *(int *)(*(int *)(((unsigned char *)0x0000121c) + glContext) + 0x70));
                if (iVar15 != 0) {
                  *(undefined1 *)(iVar15 + 0x119) = 1;
                }
                bVar6 = true;
                *(undefined4 *)(((unsigned char *)0x000015cc) + iVar14) = 1;
              }
            }
            *(uint *)(glContext + 0x27b4) = *(uint *)(glContext + 0x27b4) & ~uVar11;
          }
          *(uint *)(glContext + 0x27b0) = uVar11 | *(uint *)(glContext + 0x27b0);
          *(undefined4 *)(iVar27 + 0x1d5c) = *(undefined4 *)(iVar18 + 0x1c);
          *(undefined4 *)(iVar27 + 0x1d9c) = *(undefined4 *)(iVar18 + 0x20);
          *(undefined4 *)(iVar27 + 0x1ddc) = *(undefined4 *)(iVar18 + 0x24);
          *(undefined4 *)(iVar16 + glContext + 0x1e1c) = *(undefined4 *)(iVar18 + 0x28);
          *(uint *)(iVar27 + 0x1cdc) = uVar9 << 0x1c | *(uint *)(iVar18 + 0x14) & 0xfffffff;
          uVar13 = *(uint *)(iVar18 + 0x18);
          if (bVar6) {
            uVar13 = uVar13 & 0xffffe007;
          }
          else {
            fparam_2 = (double)*(float *)(iVar18 + 0x4c);
            if (fparam_2 == (double)FLOAT_001aa0d4) {
              uVar13 = (*(ushort *)(iVar24 + 0x46e) & 0x3ff) << 3 | uVar13 & 0xffffe007;
            }
            else {
              uVar12 = ((int (*)())FUN_00086930)(glContext,(double)*(float *)(iVar24 + 0x470),fparam_2);
              uVar13 = (uVar12 & 0x3ff) << 3 | uVar13 & 0xffffe007;
              fparam_1 = extraout_f1;
            }
          }
          *(uint *)(iVar27 + 0x1d1c) = uVar13;
          param_4 = *(undefined4 *)(&DAT_001db98c + (uint)*(byte *)(glContext + 0x2941) * 4);
          param_3 = loopIndex;
          fparam_1 = (double)((double (*)())FUN_000b6f20)(glContext,iVar18,loopIndex,param_4,fparam_1,fparam_2,fparam_3,
                                          fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                                          in_stack_ffffff28);
          uVar13 = *(uint *)(iVar18 + 0x14);
          if ((uVar13 & 0x1e00) == 0xa00) {
            if ((uVar13 & 7) == 4) {
              *(uint *)(iVar16 + glContext + 0x1cdc) =
                   *(uint *)(iVar16 + glContext + 0x1cdc) & 0xfffffff8 | 2;
              uVar13 = *(uint *)(iVar18 + 0x14);
            }
            else if ((uVar13 & 7) == 5) {
              *(uint *)(iVar16 + glContext + 0x1cdc) =
                   *(uint *)(iVar16 + glContext + 0x1cdc) & 0xfffffff8 | 3;
              uVar13 = *(uint *)(iVar18 + 0x14);
            }
            if ((uVar13 & 0x38) == 0x20) {
              *(uint *)(iVar16 + glContext + 0x1cdc) =
                   *(uint *)(iVar16 + glContext + 0x1cdc) & 0xffffffc7 | 0x10;
              uVar13 = *(uint *)(iVar18 + 0x14);
            }
            else if ((uVar13 & 0x38) == 0x28) {
              *(uint *)(iVar16 + glContext + 0x1cdc) =
                   *(uint *)(iVar16 + glContext + 0x1cdc) & 0xffffffc7 | 0x18;
              uVar13 = *(uint *)(iVar18 + 0x14);
            }
            if ((uVar13 & 0x1c0) == 0x100) {
              *(uint *)(iVar16 + glContext + 0x1cdc) =
                   *(uint *)(iVar16 + glContext + 0x1cdc) & 0xfffffe3f | 0x80;
            }
            else if ((uVar13 & 0x1c0) == 0x140) {
              *(uint *)(iVar16 + glContext + 0x1cdc) =
                   *(uint *)(iVar16 + glContext + 0x1cdc) & 0xfffffe3f | 0xc0;
            }
          }
          cVar8 = *(char *)(iVar18 + 0x31);
          if (cVar8 != '\x03') {
            *(uint *)(iVar16 + glContext + 0x1cdc) = *(uint *)(iVar16 + glContext + 0x1cdc) & 0xfffffe3f
            ;
            cVar8 = *(char *)(iVar18 + 0x31);
          }
          if (cVar8 == '\x01') {
            *(uint *)(iVar16 + glContext + 0x1cdc) = *(uint *)(iVar16 + glContext + 0x1cdc) & 0xffffffc7
            ;
          }
          iVar16 = iVar16 + glContext;
          *(uint *)(iVar16 + 0x1d1c) =
               (*(ushort *)(iVar24 + 0x46e) & 0x3ff) << 3 | *(uint *)(iVar16 + 0x1d1c) & 0xffffe007;
          if ((uVar11 & *(uint *)(glContext + 0x27b4)) != 0) {
            *(undefined4 *)(iVar27 + 0x1cfc) = *(undefined4 *)(iVar27 + 0x1cdc);
            *(uint *)(iVar25 + 0x1cdc) =
                 (uVar9 + 8) * 0x10000000 | *(uint *)(iVar25 + 0x1cdc) & 0xfffffff;
            *(undefined4 *)(iVar27 + 0x1d3c) = *(undefined4 *)(iVar27 + 0x1d1c);
            *(undefined4 *)(iVar27 + 0x1d7c) = *(undefined4 *)(iVar27 + 0x1d5c);
            *(undefined4 *)(iVar27 + 0x1dbc) = *(undefined4 *)(iVar27 + 0x1d9c);
            *(undefined4 *)(iVar27 + 0x1dfc) = *(undefined4 *)(iVar27 + 0x1ddc);
            *(undefined4 *)(iVar27 + 0x1e3c) = *(undefined4 *)(iVar27 + 0x1e1c);
            if (*(char *)(iVar17 + 0x21) == '\x01') {
              *(uint *)(iVar16 + 0x1d5c) =
                   *(int *)(iVar23 + 0x2854) - 1U & 0x7ff | *(uint *)(iVar16 + 0x1d5c) & 0xfffff800;
              *(uint *)(iVar25 + 0x1d5c) =
                   *(int *)(iVar23 + 0x285c) - 1U & 0x7ff | *(uint *)(iVar25 + 0x1d5c) & 0xfffff800;
            }
            else {
              *(uint *)(iVar16 + 0x1d5c) =
                   (*(int *)(iVar23 + 0x2854) + -1) * 0x800 & 0x3ff800U |
                   *(uint *)(iVar16 + 0x1d5c) & 0xffc007ff;
              *(uint *)(iVar25 + 0x1d5c) =
                   (*(int *)(iVar23 + 0x285c) + -1) * 0x800 & 0x3ff800U |
                   *(uint *)(iVar25 + 0x1d5c) & 0xffc007ff;
            }
          }
        }
      }
LAB_0004e760:
      uVar20 = uVar20 >> 1;
      loopIndex = loopIndex + 1;
      uVar9 = uVar9 + 1 & 0xf;
      iVar25 = iVar25 + 4;
      iVar27 = iVar27 + 4;
      iVar24 = iVar24 + 0xcc;
      iVar23 = iVar23 + 0xc;
      iVar22 = iVar22 + 4;
      iVar17 = iVar17 + 1;
    } while (uVar20 != 0);
    glContextWord27b4 = *(int *)(glContext + 0x27b4);
    txEnable = *(uint *)(glContext + 0x27b0);
  }
  glContextWord44 = *(uint *)(glContext + 0x44);
  *(uint *)(glContext + 0x27b0) = glContextWord27b4 << 8 | txEnable;
  if (((glContextWord44 & 0x100000) != 0) && (*(code **)((int)((unsigned char *)0x000011cc) + glContext) != (code *)0x0)) {
    fparam_1 = (double)(**(code **)((int)((unsigned char *)0x000011cc) + glContext))(glContext);
    glContextWord44 = *(uint *)(glContext + 0x44);
  }
  if ((glContextWord44 & 0x20000) == 0) {
    FUN_000b6580(glContext,0);
                    
                    
    (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
    return;
  }
  if ((glContextWord44 & 0x2000) == 0) {
    atifsCompileCurrentShader(glContext);
    return;
  }
  ((undefined4 (*)())FUN_000afe40)(glContext,0,param_3,param_4,fparam_1);
  return;
}

/* FUN_0004e880 @ 0x4e880 (252 bytes) */
int FUN_0004e880(glContext)
  int glContext;
{
  uint glContextWord243c;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(glContext + 0x243c) != 0) {
    glContextWord243c = *(int *)(glContext + 0x243c) + 1U >> 1;
    puVar2 = (uint *)(**(code **)(glContext + 0x2758))(glContext,glContextWord243c * 2 + 2);
    *(uint **)(0x00002748 + glContext + 4) = puVar2;
    uVar4 = (glContextWord243c - 1) * 0x10000;
    *puVar2 = uVar4 | 0x854;
    puVar2[glContextWord243c + 1] = uVar4 | 0x878;
    if (glContextWord243c != 0) {
      iVar3 = 0;
      uVar4 = glContextWord243c;
      do {
        *(undefined4 *)((int)puVar2 + iVar3 + 4) =
             *(undefined4 *)(iVar3 + *(int *)(glContext + 0x2440));
        *(undefined4 *)((int)puVar2 + iVar3 + glContextWord243c * 4 + 8) =
             *(undefined4 *)(iVar3 + *(int *)(glContext + 0x2444));
        iVar3 = iVar3 + 4;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(glContext + 0x275c);
    *(uint *)(0x00002748 + glContext + 4) = glContextWord243c * 8 + *(int *)(0x00002748 + glContext + 4) + 8;
                    
                    
    (*UNRECOVERED_JUMPTABLE)(glContext,*(int *)(0x00002748 + glContext + 4));
    return;
  }
  return;
}

/* FUN_0004e990 @ 0x4e990 (208 bytes) */
int FUN_0004e990(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  double dVar3;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 4) + 0x154) & 0x30000;
  dVar3 = DOUBLE_001aa288;
  if (((uVar1 != 0x20000) && (uVar1 != 0x30000)) && (dVar3 = DOUBLE_001aa280, uVar1 == 0x10000)) {
    dVar3 = DOUBLE_001aa278;
  }
  dVar3 = dVar3 * *(double *)(((unsigned char *)0x00002d88) + *(int *)(*(int *)(param_1 + 4) + 0x10));
  if (DOUBLE_001aa1e8 <= dVar3) {
    iVar2 = (int)(dVar3 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar2 = (int)dVar3;
  }
  return iVar2;
}

/* gldValidatePolygonMode @ 0x4ea70 (260 bytes) */
double gldValidatePolygonMode(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  short sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_1 + 0x1b3c);
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (*(int *)(((unsigned char *)0x00003170) + iVar3) == 0x1b021b02) {
    uVar2 = uVar4 & 0xfffffffc;
    *(uint *)(param_1 + 0x1b3c) = uVar2;
  }
  else {
    *(uint *)(param_1 + 0x1b3c) = uVar4 & 0xfffffffc | 1;
    sVar1 = *(short *)(((unsigned char *)0x00003170) + iVar3);
    if (sVar1 == 0x1b01) {
      *(uint *)(param_1 + 0x1b3c) = uVar4 & 0xffffff8c | 0x11;
    }
    else if (sVar1 == 0x1b02) {
      *(uint *)(param_1 + 0x1b3c) = uVar4 & 0xffffff8c | 0x21;
    }
    else if (sVar1 == 0x1b00) {
      *(uint *)(param_1 + 0x1b3c) = uVar4 & 0xffffff8c | 1;
    }
    sVar1 = *(short *)(((unsigned char *)0x00003172) + iVar3);
    if (sVar1 == 0x1b01) {
      uVar2 = *(uint *)(param_1 + 0x1b3c) & 0xfffffc7f | 0x80;
      *(uint *)(param_1 + 0x1b3c) = uVar2;
    }
    else if (sVar1 == 0x1b02) {
      uVar2 = *(uint *)(param_1 + 0x1b3c) & 0xfffffc7f | 0x100;
      *(uint *)(param_1 + 0x1b3c) = uVar2;
    }
    else if (sVar1 == 0x1b00) {
      uVar2 = *(uint *)(param_1 + 0x1b3c) & 0xfffffc7f;
      *(uint *)(param_1 + 0x1b3c) = uVar2;
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x1b3c);
    }
  }
  if (uVar4 != uVar2) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x2000;
  }
  ((void (*)())FUN_0004d770)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  return;
}

/* FUN_0004eba0 @ 0x4eba0 (476 bytes) */
int FUN_0004eba0(glContext, param_2, param_3, param_4, param_5, param_6, param_7)
  int glContext;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  undefined4 uVar2;
  int glState;
  int glContextWord8;
  int glContextWord2768;
  double extraout_f1;
  double extraout_f1_00;
  double dVar6;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  iVar1 = *(int *)(glContext + 4);
  glContextWord2768 = *(int *)(glContext + 0x2768);
  glContextWord8 = *(int *)(glContext + 8);
  if ((((((unsigned char *)0x00002e2d)[*(int *)(iVar1 + 0x10)] == '\0') ||
       ((*(uint *)(glContext + 0x44) & 0x20000) != 0)) ||
      (iVar1 = FUN_0001a010(iVar1,*(undefined4 *)(iVar1 + 0x26a0),param_3,param_4,param_5,param_6,
                            param_7), iVar1 != 0)) || (glContextWord2768 == 0)) {
    glState = *(int *)(glContext + 4);
    iVar1 = ((uint (*)())FUN_000a3560)(glContext,(double)*(float *)(((unsigned char *)0x00002e20) + *(int *)(glState + 0x10)));
    uVar2 = *(undefined4 *)(*(int *)(glContext + 4) + 0x26a0);
    *(short *)(glContext + 0x1b42) = (short)((uint)(glContextWord8 * iVar1) >> 1);
    iVar1 = FUN_0001a010(*(int *)(glContext + 4),uVar2,param_3,param_4,param_5,param_6,glState);
    dVar6 = extraout_f1_00;
    if (iVar1 == 0) {
      *(uint *)(glContext + 0x1b40) = *(uint *)(glContext + 0x1b40) & 0xfffcffff | 0x20000;
    }
    else {
      *(uint *)(glContext + 0x1b40) = *(uint *)(glContext + 0x1b40) & 0xfffcffff | 0x30000;
    }
  }
  else {
    *(short *)(glContext + 0x1b42) = (short)*(undefined4 *)(glContextWord2768 + 0x18);
    *(uint *)(glContext + 0x1b40) = *(uint *)(glContext + 0x1b40) & 0xfffcffff | 0x30000;
    dVar6 = extraout_f1;
  }
  iVar1 = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (((((unsigned char *)0x00002e2c)[iVar1] != '\0') && ((*(uint *)(glContext + 0x44) & 0x20000) == 0)) &&
     (*(short *)(((unsigned char *)0x00002e28) + iVar1) != -1)) {
    *(uint *)(glContext + 0x1b64) =
         (uint)(int)(FLOAT_001aa0e8 /
               ((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00002e24) + iVar1) ^ 0x80000000) -
                       DOUBLE_001aa1e0) * FLOAT_001aa0fc *
               (float)((double)CONCAT44(0x43300000,glContextWord8) - DOUBLE_001aa250))) & 0xfffffffc |
         *(uint *)(glContext + 0x1b64) & 3;
  }
  if (glContextWord2768 != 0) {
    *(undefined4 *)(glContext + 0x1b70) = *(undefined4 *)(glContextWord2768 + 0x24);
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x4000;
  ((void (*)())FUN_0004d770)(glContext,dVar6,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* FUN_0004ed90 @ 0x4ed90 (692 bytes) */
int FUN_0004ed90(glContext)
  int glContext;
{
  uint registerDirty;
  float glContextWord104;
  float glContextWord100;
  float fVar1;
  float fVar2;
  undefined2 uVar3;
  int iVar4;
  uint glContextWord44;
  int glContextWord8;
  int glContextWord2768;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  glContextWord2768 = *(int *)(glContext + 0x2768);
  glContextWord8 = *(int *)(glContext + 8);
  iVar4 = FUN_000a3670(glContext);
  glContextWord44 = *(uint *)(glContext + 0x44);
  if (((glContextWord44 & 0x60020000) == 0x40000000) && (glContextWord2768 != 0)) {
    *(short *)(glContext + 0x1ccc) = (short)*(undefined4 *)(glContextWord2768 + 4);
    *(short *)(glContext + 0x1cce) = (short)*(undefined4 *)(glContextWord2768 + 4);
    *(undefined4 *)(glContext + 0x1cc0) = *(undefined4 *)(glContextWord2768 + 0xc);
    *(undefined4 *)(glContext + 0x1cc8) = *(undefined4 *)(glContextWord2768 + 0x10);
  }
  else {
    if (iVar4 == 0) {
      uVar3 = (undefined2)((uint)(glContextWord8 * *(int *)(glContext + 0xe4)) >> 1);
    }
    else {
      uVar3 = (undefined2)((uint)(int)(glContextWord8 * (int)(*(float *)(glContext + 0xf0) + FLOAT_001aa10c)) >> 1);
    }
    *(undefined2 *)(glContext + 0x1cce) = uVar3;
    *(undefined2 *)(glContext + 0x1ccc) = uVar3;
  }
  if ((glContextWord44 & 0x60020000) == 0x40000000) {
    if (iVar4 == 0) {
      glContextWord100 = *(float *)(glContext + 0x100) + FLOAT_001aa0e8;
      glContextWord104 = *(float *)(glContext + 0x104) + FLOAT_001aa0e8;
    }
    else {
      if ((glContextWord44 & 0x80) != 0) {
        fVar2 = *(float *)(((unsigned char *)0x000013c4) + glContext);
        fVar1 = (float)((double)CONCAT44(0x43300000,glContextWord8) - DOUBLE_001aa250);
        *(short *)(glContext + 0x1cd0) =
             (short)((int)(fVar1 * *(float *)(((unsigned char *)0x000013c8U) + glContext)) >> 1);
        *(short *)(glContext + 0x1cd2) = (short)((int)(fVar1 * fVar2) >> 1);
        goto LAB_0004efc0;
      }
      glContextWord100 = *(float *)(glContext + 0x100);
      glContextWord104 = *(float *)(glContext + 0x104);
    }
    *(short *)(glContext + 0x1cd2) = (short)((uint)(int)(glContextWord8 * (int)glContextWord100) >> 1);
    *(short *)(glContext + 0x1cd0) = (short)((uint)(int)(glContextWord8 * (int)glContextWord104) >> 1);
  }
  else if ((glContextWord44 & 0x80) == 0) {
    *(short *)(glContext + 0x1cd2) = (short)((uint)(glContextWord8 * *(int *)(glContext + 0x108)) >> 1);
    *(short *)(glContext + 0x1cd0) = (short)((uint)(glContextWord8 * *(int *)(glContext + 0x10c)) >> 1);
  }
  else {
    iVar4 = *(int *)(((unsigned char *)0x000013d4) + glContext);
    *(short *)(glContext + 0x1cd2) = (short)(glContextWord8 * *(int *)(((unsigned char *)0x000013d0U) + glContext) >> 1);
    *(short *)(glContext + 0x1cd0) = (short)(glContextWord8 * iVar4 >> 1);
  }
LAB_0004efc0:
  *(uint *)(glContext + 0x1b74) = *(uint *)(glContext + 0x1b74) & 0xffff3fff;
  if ((glContextWord44 & 0x20000000) == 0) {
    *(undefined4 *)(glContext + 0x1cbc) = 0;
    *(undefined4 *)(glContext + 0x1cc4) = 0;
  }
  else {
    *(undefined4 *)(glContext + 0x1cc0) = 0x3f800000;
    *(undefined4 *)(glContext + 0x1cbc) = 0;
    *(undefined4 *)(glContext + 0x1cc4) = 0x3f800000;
    *(undefined4 *)(glContext + 0x1cc8) = 0;
  }
  if (*(int *)(glContext + 0x2768) == 0) {
    if ((glContextWord44 & 0x20000000) == 0) {
      *(undefined4 *)(glContext + 0x1b50) = 7;
      if ((*(uint *)(glContext + 0x1a64) & 0x10) != 0) {
        *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) & 0xffffffef;
        registerDirty = *(uint *)(glContext + 0x1930) | 0x2000;
        *(uint *)(glContext + 0x1930) = registerDirty;
        goto LAB_0004f054;
      }
    }
  }
  registerDirty = *(uint *)(glContext + 0x1930);
LAB_0004f054:
  *(uint *)(glContext + 0x1930) = registerDirty | 0xc08000;
  ((void (*)())FUN_0004d770)(glContext,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* gldValidateCullFace @ 0x4f080 (192 bytes) */
int gldValidateCullFace(glContext)
  int glContext;
{
  short cullMode;
  uint faceControl;
  int glState;
  
  glState = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (((unsigned char *)0x000013b8)[glContext] == '\0') {
    if (*(short *)(((unsigned char *)0x00003174) + glState) == 0x900) goto LAB_0004f0c0;
  }
  else if (*(short *)(((unsigned char *)0x00003174) + glState) != 0x900) {
LAB_0004f0c0:
    faceControl = *(uint *)(glContext + 0x1b30) & 0xfffffffb;
    *(uint *)(glContext + 0x1b30) = faceControl;
    goto LAB_0004f0dc;
  }
  faceControl = *(uint *)(glContext + 0x1b30) | 4;
  *(uint *)(glContext + 0x1b30) = faceControl;
LAB_0004f0dc:
  if (((unsigned char *)0x0000317a)[glState] == '\0') {
    *(uint *)(glContext + 0x1b30) = faceControl & 0xfffffffc;
  }
  else {
    cullMode = *(short *)(((unsigned char *)0x00003176) + glState);
    if (cullMode == 0x405) {
      *(uint *)(glContext + 0x1b30) = faceControl & 0xfffffffe | 2;
    }
    else if (cullMode == 0x408) {
      *(uint *)(glContext + 0x1b30) = faceControl | 3;
    }
    else if (cullMode == 0x404) {
      *(uint *)(glContext + 0x1b30) = faceControl & 0xfffffffd | 1;
    }
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x400;
  return;
}

/* FUN_0004f160 @ 0x4f160 (352 bytes) */
int FUN_0004f160(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  double dVar4;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (param_2 == 2) {
    dVar4 = (double)(*(float *)(((unsigned char *)0x00002de4) + iVar2) * FLOAT_001aa0f0);
    if (DOUBLE_001aa1e8 <= dVar4) {
      uVar1 = (int)(dVar4 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar1 = (uint)(int)(*(float *)(((unsigned char *)0x00002de4) + iVar2) * FLOAT_001aa0f0);
    }
  }
  else if (param_2 == 3) {
    dVar4 = (double)(*(float *)(((unsigned char *)0x00002de8) + iVar2) * FLOAT_001aa0f0);
    if (DOUBLE_001aa1e8 <= dVar4) {
      uVar1 = (int)(dVar4 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar1 = (uint)(int)(*(float *)(((unsigned char *)0x00002de8) + iVar2) * FLOAT_001aa0f0);
    }
  }
  else {
    if (param_2 != 1) {
      uVar1 = 0;
      uVar3 = 0;
      goto LAB_0004f2c8;
    }
    dVar4 = (double)(*(float *)(((unsigned char *)0x00002de0) + iVar2) * FLOAT_001aa0f0);
    if (DOUBLE_001aa1e8 <= dVar4) {
      uVar1 = (int)(dVar4 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar1 = (uint)(int)(*(float *)(((unsigned char *)0x00002de0) + iVar2) * FLOAT_001aa0f0);
    }
  }
  uVar3 = uVar1 >> 6;
  uVar1 = uVar1 << 2;
LAB_0004f2c8:
  return uVar3 & 3 | uVar1;
}

/* FUN_0004f2e0 @ 0x4f2e0 (616 bytes) */
void FUN_0004f2e0(int glContext,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1)
{
  byte colorFormatIndex;
  short sVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar3 = PTR_DAT_001e88c8;
  colorFormatIndex = *(byte *)(glContext + 0x293f);
  if ((*(uint *)(glContext + 0x44) & 0x1002000) == 0x1000000) {
    iVar4 = *(int *)(*(int *)(glContext + 4) + 0x10);
    sVar2 = *(short *)(((unsigned char *)0x00002e04) + iVar4);
    if (sVar2 == 0x801) {
      *(undefined4 *)(glContext + 0x134) = 0;
      *(float *)(glContext + 0x138) =
           -(*(float *)(((unsigned char *)0x00002df0) + iVar4) * *(float *)(((unsigned char *)0x00002df0) + iVar4));
    }
    else if (sVar2 == 0x2601) {
      *(float *)(glContext + 0x134) =
           *(float *)(((unsigned char *)0x00002df8) + iVar4) * *(float *)(((unsigned char *)0x00002dfc) + iVar4);
      *(float *)(glContext + 0x138) = -*(float *)(((unsigned char *)0x00002dfc) + iVar4);
    }
    else if (sVar2 == 0x800) {
      *(undefined4 *)(glContext + 0x134) = 0;
      *(float *)(glContext + 0x138) = -*(float *)(((unsigned char *)0x00002df0) + iVar4);
    }
    *(uint *)(glContext + 0x18a4) = *(uint *)(glContext + 0x18a4) & 0xfdffffff;
    *(uint *)(glContext + 0x1a64) = *(uint *)(glContext + 0x1a64) & 0xfffffff8 | 1;
    *(uint *)(glContext + 0x1878) = *(uint *)(glContext + 0x1878) & 0xffefffff;
    *(uint *)(glContext + 0x1aec) = *(uint *)(glContext + 0x1aec) & 0xfffffff9 | 1;
    *(undefined4 *)(glContext + 0x1a78) = 0x3f800000;
    *(undefined4 *)(glContext + 0x1a7c) = 0xbf800000;
    if (*(char *)(glContext + 0x121) != '\0') {
      *(undefined1 *)(glContext + 0x121) = 0;
      *(undefined1 *)(glContext + 0x29) = 1;
      *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1000;
    }
  }
  else {
    *(uint *)(glContext + 0x1aec) = *(uint *)(glContext + 0x1aec) & 0xfffffffe;
    *(uint *)(glContext + 0x18a4) = *(uint *)(glContext + 0x18a4) & 0xfdffffff;
    *(uint *)(glContext + 0x1878) = *(uint *)(glContext + 0x1878) & 0xffefffff;
    if (*(char *)(glContext + 0x121) != '\0') {
      *(undefined1 *)(glContext + 0x121) = 0;
      *(undefined1 *)(glContext + 0x29) = 1;
      *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1000;
    }
  }
  if ((*(uint *)(glContext + 0x44) & 0x20000) == 0) {
    FUN_000b6580(glContext,0);
    (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
  }
  else if ((*(uint *)(glContext + 0x44) & 0x2000) == 0) {
    atifsCompileCurrentShader(glContext);
  }
  else {
    ((undefined4 (*)())FUN_000afe40)(glContext,0,param_3,param_4,fparam_1);
  }
  uVar5 = ((int (*)())FUN_0004f160)(glContext,*(uint *)(puVar3 + (uint)colorFormatIndex * 0x24 + 0x1c) >> 0x1e);
  *(uint *)(glContext + 0x1a54) = uVar5 & 0x3ff | *(uint *)(glContext + 0x1a54) & 0xfffffc00;
  uVar5 = ((int (*)())FUN_0004f160)(glContext,*(uint *)(puVar3 + (uint)colorFormatIndex * 0x24 + 0x18) >> 1 & 3);
  *(uint *)(glContext + 0x1a58) = uVar5 & 0x3ff | *(uint *)(glContext + 0x1a58) & 0xfffffc00;
  uVar5 = ((int (*)())FUN_0004f160)(glContext,*(uint *)(puVar3 + (uint)colorFormatIndex * 0x24 + 0x18) >> 3 & 3);
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 1;
  *(uint *)(glContext + 0x1a5c) = uVar5 & 0x3ff | *(uint *)(glContext + 0x1a5c) & 0xfffffc00;
  return;
}

/* gldValidateScissor @ 0x4f550 (452 bytes) */
int gldValidateScissor(glContext)
  int glContext;
{
  bool changed;
  uint bottom;
  uint left;
  uint scaledLeft;
  uint top;
  uint oldTopLeft;
  uint right;
  
  left = 0;
  scaledLeft = (uint)(int)((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001358) + glContext) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) * *(float *)(glContext + 0x2814));
  bottom = (uint)(int)(*(float *)(glContext + 0x2818) *
                 (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001364) + glContext) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) - FLOAT_001aa0e8);
  top = (uint)(int)((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x0000135c) + glContext) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) * *(float *)(glContext + 0x2818));
  right = (uint)(int)(*(float *)(glContext + 0x2814) *
                 (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001360) + glContext) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) - FLOAT_001aa0e8);
  if (-1 < (int)scaledLeft) {
    left = scaledLeft & 0xffff;
  }
  if ((int)(uint)*(ushort *)(((unsigned char *)0x000013bc) + glContext) < (int)right) {
    right = (uint)*(ushort *)(((unsigned char *)0x000013bc) + glContext);
  }
  if (((unsigned char *)0x000013b8)[glContext] == '\0') {
    scaledLeft = 0;
    if (-1 < (int)top) {
      scaledLeft = top & 0xffff;
    }
    if ((int)(*(ushort *)(((unsigned char *)0x000013ba) + glContext) - 1) < (int)bottom) {
      bottom = *(ushort *)(((unsigned char *)0x000013ba) + glContext) - 1;
    }
  }
  else {
    scaledLeft = 0xffff;
    if (-2 < (int)top) {
      scaledLeft = top & 0xffff;
    }
    if ((int)(uint)*(ushort *)(((unsigned char *)0x000013ba) + glContext) < (int)bottom) {
      bottom = (uint)*(ushort *)(((unsigned char *)0x000013ba) + glContext);
    }
  }
  oldTopLeft = *(uint *)(glContext + 7000);
  top = *(uint *)(glContext + 0x1b10);
  scaledLeft = (scaledLeft & 0x1fff) << 0xd | left & 0x1fff | oldTopLeft & 0xfc000000;
  bottom = (bottom & 0x1fff) << 0xd | right & 0x1fff | top & 0xfc000000;
  *(uint *)(glContext + 7000) = scaledLeft;
  *(uint *)(glContext + 0x1b10) = bottom;
  if ((oldTopLeft != scaledLeft) || (changed = false, top != bottom)) {
    changed = true;
  }
  if (changed) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 2;
    return;
  }
  return;
}

/* gldInitStateDefaults @ 0x4f720 (1348 bytes) */
int gldInitStateDefaults(glContext)
  int glContext;
{
  uint glContextWord2454;
  uint scEdgerule;
  float fVar1;
  int glContextWord23d0;
  undefined4 uVar3;
  uint rb3dRopcntl;
  uint rb3dColorChannelMask;
  int iVar6;
  
  *(undefined4 *)(glContext + 0x1bd0) = 0;
  *(undefined4 *)(glContext + 0x1930) = 0;
  *(undefined4 *)(glContext + 0x1934) = 0;
  *(undefined4 *)(glContext + 0x1938) = 0;
  *(undefined4 *)(glContext + 0x193c) = 0;
  *(undefined4 *)(glContext + 0x1a4c) = 0;
  *(undefined4 *)(glContext + 0x1a50) = 0;
  *(undefined4 *)(glContext + 0x1a54) = 0;
  *(undefined4 *)(glContext + 0x1a58) = 0;
  *(undefined4 *)(glContext + 0x1a5c) = 0;
  *(undefined4 *)(glContext + 0x1aec) = 0;
  *(undefined4 *)(glContext + 0x1bcc) = 0;
  if ((*(uint *)(glContext + 0x2454) & 0x8000000) != 0) {
    *(undefined4 *)(glContext + 0x1bcc) = 1;
  }
  if (*(int *)(glContext + 0x23dc) == 2) {
    *(uint *)(glContext + 0x1bd0) = *(uint *)(glContext + 0x1bd0) & 0xfffffffc | 3;
  }
  else {
    *(uint *)(glContext + 0x1bd0) = *(uint *)(glContext + 0x1bd0) & 0xfffffffc | 1;
  }
  rb3dColorChannelMask = *(uint *)(0x00001af4 + glContext);
  rb3dRopcntl = *(uint *)(glContext + 0x1af8);
  *(undefined4 *)(glContext + 0x1b70) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cc0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cc8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1b4c) = 2;
  *(undefined4 *)(glContext + 0x1a64) = 0;
  *(undefined4 *)(glContext + 0x1cbc) = 0;
  *(undefined4 *)(glContext + 0x1cc4) = 0;
  *(undefined4 *)(glContext + 0x1ccc) = 0;
  *(undefined4 *)(glContext + 0x1cd0) = 0;
  *(undefined4 *)(glContext + 0x1b64) = 0;
  *(undefined4 *)(glContext + 0x1b68) = 0;
  *(undefined4 *)(glContext + 0x1b6c) = 0;
  *(undefined4 *)(glContext + 0x1a70) = 0;
  *(undefined4 *)(glContext + 0x1a74) = 0;
  *(undefined4 *)(glContext + 0x1b3c) = 0;
  *(undefined4 *)(glContext + 0x1b44) = 0;
  *(undefined4 *)(glContext + 0x1a78) = 0;
  *(undefined4 *)(glContext + 0x1a7c) = 0;
  *(undefined4 *)(glContext + 0x1a60) = 0;
  *(undefined4 *)(glContext + 0x1b54) = 0x50005;
  *(undefined4 *)(glContext + 0x1b40) = 0x20000;
  *(undefined4 *)(glContext + 0x1b50) = 7;
  *(undefined4 *)(glContext + 0x1b2c) = 0x30000;
  *(undefined4 *)(glContext + 0x1a6c) = 0x5666666;
  *(undefined4 *)(glContext + 0x1a68) = 0x55666666;
  *(undefined4 *)(glContext + 0x1a80) = 0x20220000;
  *(undefined1 *)(glContext + 0x247c) = 1;
  *(undefined4 *)(glContext + 0x1b48) = 1;
  *(uint *)(0x00001af4 + glContext) = rb3dColorChannelMask | 0xf;
  *(undefined4 *)(glContext + 8) = 0xc;
  *(undefined4 *)(glContext + 0x23c0) = 0;
  scEdgerule = *(uint *)(glContext + 0x1abc);
  *(undefined4 *)(glContext + 0x1af0) = 0;
  *(uint *)(glContext + 0x1af8) = rb3dRopcntl & 0xfffffffb;
  *(undefined4 *)(glContext + 0x1ae0) = 0;
  *(undefined4 *)(glContext + 7000) = 0;
  *(undefined4 *)(glContext + 0x1b10) = 0;
  *(undefined4 *)(glContext + 0x1b60) = 0xffffff;
  *(undefined4 *)(glContext + 0x1bd4) = 0;
  *(undefined4 *)(glContext + 0x1b30) = 0;
  *(undefined4 *)(0x00001b14 + glContext) = 0;
  *(undefined4 *)(glContext + 0x1b28) = 0;
  *(undefined4 *)(glContext + 0x27b0) = 0;
  *(uint *)(glContext + 0x1abc) = scEdgerule & 0xc0000000 | 0x2da49525;
  _memset(glContext + 0x1cdc,0,0x40);
  *(undefined4 *)(0x00002348 + glContext) = 0x1b0f;
  *(undefined4 *)(glContext + 0x233c) = 0x1b0f;
  *(undefined4 *)(glContext + 0x2340) = 0x1b0f;
  *(undefined4 *)(glContext + 0x2344) = 0x1b0f;
  FUN_0004ab60(glContext);
  glContextWord2454 = *(uint *)(glContext + 0x2454);
  *(undefined4 *)(glContext + 0x1b7c) = 0x80006a;
  if ((int)glContextWord2454 < 0) {
    *(undefined4 *)(glContext + 0x1b7c) = 0x80086a;
  }
  else if ((glContextWord2454 & 0x8000000) == 0) {
    if ((glContextWord2454 & 0x2000000) == 0) {
      *(undefined4 *)(glContext + 0x1b7c) = 0x80046a;
    }
    else {
      *(undefined4 *)(glContext + 0x1b7c) = 0x80026a;
    }
  }
  else {
    *(undefined4 *)(glContext + 0x1b7c) = 0x80056a;
  }
  *(undefined4 *)(glContext + 0x1b80) = 2;
  *(undefined4 *)(glContext + 0x1ca0) = 0;
  *(undefined4 *)(glContext + 0x1b9c) = 0;
  *(undefined4 *)(glContext + 0x1ba0) = 0;
  *(undefined4 *)(glContext + 0x1cb4) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cac) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cb0) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1b74) = 0;
  *(undefined4 *)(glContext + 0x1b98) = 0;
  *(undefined4 *)(glContext + 0x1bc8) = 0;
  *(undefined4 *)(glContext + 0x1ab0) = 0xc0800;
  *(undefined1 *)(glContext + 0x23ec) = 1;
  *(undefined4 *)(glContext + 0x1b84) = 0x43f;
  *(uint *)(glContext + 0x1b7c) = *(uint *)(glContext + 0x1b7c) & 0xffc3ffff | 0x300000;
  *(undefined4 *)(glContext + 0x1b88) = 0xffff;
  *(undefined4 *)(glContext + 0x1aa0) = 0x10;
  if (*(char *)(glContext + 0x2451) != '\0') {
    *(undefined4 *)(glContext + 0x1ab0) = 0xc3800;
  }
  *(undefined4 *)(glContext + 0x1aa8) = 0;
  *(undefined1 *)(glContext + 0x1aab) = 0;
  *(undefined1 *)(glContext + 0x1aa9) = 0xff;
  *(undefined1 *)(glContext + 0x1aaa) = 0xff;
  *(undefined4 *)(glContext + 0x1ae4) = 0;
  fVar1 = FLOAT_001aa150;
  *(undefined4 *)(glContext + 0x1a98) = 0;
  *(undefined4 *)(glContext + 0x1a9c) = 0;
  *(undefined4 *)(glContext + 0x1afc) = 0;
  *(undefined4 *)(glContext + 0x1ae8) = 0;
  *(undefined4 *)(glContext + 0x1ab4) = 0;
  *(undefined4 *)(glContext + 0x1aa4) = 0;
  *(float *)(glContext + 0x1b38) = fVar1;
  *(undefined4 *)(glContext + 0x1bd8) = 1;
  *(uint *)(glContext + 0x1cd4) = *(uint *)(glContext + 0x1cd4) & 0xfffc0003;
  *(undefined4 *)(glContext + 0x2358) = 0xffffffff;
  *(undefined4 *)(glContext + 0x235c) = 0;
  *(uint *)(glContext + 0x1cd8) = *(uint *)(glContext + 0x1cd8) & 0xffffc00f;
  *(uint *)(glContext + 0x1ab8) = *(uint *)(glContext + 0x1ab8) | 1;
  *(undefined4 *)(0x00001b34 + glContext) = 0;
  glContextWord23d0 = *(int *)(glContext + 0x23d0);
  iVar6 = glContextWord23d0 * 0xb4;
  *(undefined4 *)(glContext + 0x2360) = DAT_001db928;
  *(undefined4 *)(glContext + 0x2364) = DAT_001db92c;
  *(undefined4 *)(glContext + 0x236c) = DAT_001db934;
  *(undefined4 *)(0x00002368 + glContext) = DAT_001db930;
  *(undefined4 *)(glContext + 0x2370) = DAT_001db938;
  *(undefined4 *)(glContext + 0x2374) = *(undefined4 *)(&DAT_001db5b8 + iVar6);
  *(undefined4 *)(glContext + 0x237c) = *(undefined4 *)(&DAT_001db5c0 + iVar6);
  *(undefined4 *)(glContext + 0x2378) = *(undefined4 *)(&DAT_001db5bc + iVar6);
  *(undefined4 *)(glContext + 0x2380) = *(undefined4 *)(&DAT_001db5c4 + iVar6);
  *(undefined4 *)(glContext + 0x2384) = *(undefined4 *)(&DAT_001db2d4 + iVar6);
  *(undefined4 *)(0x00002388 + glContext) = *(undefined4 *)(&DAT_001db2d8 + iVar6);
  *(undefined4 *)(glContext + 0x2398) = *(undefined4 *)(&DAT_001db2e0 + iVar6);
  *(undefined **)(glContext + 0x238c) = (PTR_FUN_001db2dc)[glContextWord23d0 * 0x2d];
  *(undefined4 *)(glContext + 0x239c) = *(undefined4 *)(&DAT_001db2e4 + iVar6);
  *(undefined4 *)(glContext + 0x2390) = *(undefined4 *)(&DAT_001db2e8 + iVar6);
  *(undefined4 *)(glContext + 0x23a0) = *(undefined4 *)(&DAT_001db2f0 + iVar6);
  *(undefined **)(glContext + 0x2394) = (PTR_FUN_001db2ec)[glContextWord23d0 * 0x2d];
  uVar3 = *(undefined4 *)(&DAT_001db2f4 + iVar6);
  *(undefined4 *)(glContext + 0x23c4) = 0;
  *(undefined4 *)(glContext + 0x23c8) = 0;
  *(undefined4 *)(glContext + 0x23cc) = 0;
  *(undefined4 *)(glContext + 0x23a4) = uVar3;
  if (glContextWord23d0 == 4) {
    *(undefined4 *)(glContext + 0x23c8) = 0x101fe;
    *(undefined4 *)(glContext + 0x23cc) = 0x101fe;
    *(undefined4 *)(glContext + 0x23c4) = 0x111;
  }
  *(undefined1 *)(glContext + 0x29) = 1;
  *(undefined2 *)(glContext + 0x34) = 0xffff;
  *(undefined1 *)(glContext + 0x2e) = 3;
  *(undefined1 *)(glContext + 0x2a) = 1;
  *(undefined2 *)(glContext + 0x32) = 0xffff;
  *(undefined4 *)(glContext + 0x23e0) = 0;
  *(undefined4 *)(glContext + 0x1bac) = 0;
  *(undefined4 *)(glContext + 0x1bb0) = 0;
  *(undefined4 *)(glContext + 0x1bbc) = 0;
  *(undefined4 *)(glContext + 0x1bc0) = 0;
  *(undefined4 *)(glContext + 0x1bc4) = 0;
  *(undefined4 *)(glContext + 0x2354) = 0;
  *(undefined4 *)(glContext + 0x3c) = 0x800015ff;
  *(undefined1 *)(glContext + 0x2d) = 0xf;
  *(undefined1 *)(glContext + 0x2c) = 0xff;
  *(undefined4 *)(glContext + 0x38) = 0x7ffff;
  *(undefined4 *)(glContext + 0x40) = 0x7ffff;
  *(undefined1 *)(glContext + 0x30) = 7;
  *(undefined4 *)(glContext + 0x1bb8) = 0xaaaaa;
  return;
}

/* FUN_0004fc80 @ 0x4fc80 (252 bytes) */
int FUN_0004fc80(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
  uint param_8;
{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x1868) != '\0') {
    iVar2 = 0;
    param_5 = *(uint *)(param_5 * 4 + *(int *)(param_1 + 0x1864));
    if (param_5 == 0x16) goto LAB_0004fcb4;
  }
  iVar2 = 0xf;
LAB_0004fcb4:
  if ((param_2 & 1) == 0) {
    iVar1 = (param_2 >> 1) * 4 + param_1;
    *(uint *)(iVar1 + 0x1be4) =
         (param_8 & 1) << 0xf |
         (param_7 & 1) << 0xe |
         (param_6 & 1) << 0xd |
         (param_5 & 0x1f) << 8 |
         (param_4 & 0xf) << 4 | param_3 & 0xf | *(uint *)(iVar1 + 0x1be4) & 0xffff0000;
    *(uint *)(iVar1 + 0x1c04) = iVar2 << 0xc | *(uint *)(iVar1 + 0x1c04) & 0xffff0000 | 0x688;
  }
  else {
    iVar1 = (param_2 >> 1) * 4 + param_1;
    *(uint *)(iVar1 + 0x1be4) =
         param_8 << 0x1f |
         (param_7 & 1) << 0x1e |
         (param_6 & 1) << 0x1d |
         (param_5 & 0x1f) << 0x18 |
         (param_4 & 0xf) << 0x14 | (param_3 & 0xf) << 0x10 | *(uint *)(iVar1 + 0x1be4) & 0xffff;
    *(uint *)(iVar1 + 0x1c04) = iVar2 << 0x1c | *(uint *)(iVar1 + 0x1c04) & 0xffff | 0x6880000;
  }
  return;
}

/* FUN_0004fd80 @ 0x4fd80 (492 bytes) */
int FUN_0004fd80(glContext)
  int glContext;
{
  int glContextWord1e70;
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  code *streamSetCurrent;
  uint *puVar8;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined *puVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  
  iVar12 = *(int *)(((unsigned char *)0x00001154) + glContext);
  iVar11 = iVar12 + 0x10;
  if (((unsigned char *)0x00001134)[glContext] == '\0') {
    iVar11 = *(int *)(((unsigned char *)0x00001144) + glContext);
  }
  uVar14 = 0;
  puVar13 = ((unsigned char *)0x00001300U);
  iVar16 = 0;
  iVar15 = glContext;
  do {
    glContextWord1e70 = *(int *)(glContext + 0x1e70);
    if ((((1 << (uVar14 & 0x3f) & *(uint *)(((unsigned char *)0x000010b8) + glContextWord1e70)) != 0) &&
        (*(char *)(*(int *)(iVar11 + 0x28) + iVar16) == '\0')) &&
       (*(char *)(iVar16 + *(int *)(iVar12 + 0xc)) != '\0')) {
      uVar2 = *(uint *)(iVar16 + *(int *)(iVar12 + 0xc) + 4);
      iVar6 = uVar14 * 0x10;
      iVar10 = iVar6 + glContextWord1e70;
      uVar3 = *(uint *)(*(int *)(iVar12 + 0xc) + iVar16 + 8);
      uVar4 = *(uint *)(iVar16 + *(int *)(iVar12 + 0xc) + 0xc);
      uVar5 = *(uint *)(iVar16 + *(int *)(iVar12 + 0xc) + 0x10);
      if (((uVar2 != *(uint *)(iVar10 + 0x8c)) || (uVar3 != *(uint *)(iVar10 + 0x90))) ||
         ((uVar4 != *(uint *)(iVar10 + 0x94) || (uVar5 != *(uint *)(iVar10 + 0x98))))) {
        *(uint *)(iVar6 + glContextWord1e70 + 0x8c) = uVar2;
        *(uint *)(iVar6 + *(int *)(glContext + 0x1e70) + 0x90) = uVar3;
        iVar9 = iVar6 + *(int *)(glContext + 0x1e70);
        *(uint *)(iVar9 + 0x94) = uVar4;
        *(uint *)(iVar6 + *(int *)(glContext + 0x1e70) + 0x98) = uVar5;
        *(uint *)(iVar15 + 0x1f38) = uVar2;
        *(uint *)(iVar15 + 0x1f3c) = uVar3;
        *(uint *)(iVar15 + 8000) = uVar4;
        *(uint *)(iVar15 + 0x1f44) = uVar5;
        puVar8 = (uint *)(**(code **)(glContext + 0x2758))(glContext,5,in_r5,in_r6,in_r7,in_r8,iVar9);
        *(uint **)(0x00002748 + glContext + 4) = puVar8;
        puVar8[4] = uVar5;
        *puVar8 = (uint)puVar13 | 0x30000;
        puVar8[1] = uVar2;
        puVar8[2] = uVar3;
        puVar8[3] = uVar4;
        iVar9 = *(int *)(0x00002748 + glContext + 4);
        streamSetCurrent = *(code **)(glContext + 0x275c);
        *(int *)(0x00002748 + glContext + 4) = iVar9 + 0x14;
        (*streamSetCurrent)(glContext,iVar9 + 0x14);
        *(undefined4 *)(glContext + 0x1e68) = 0;
      }
    }
    bVar1 = uVar14 != 7;
    iVar16 = iVar16 + 0x14;
    iVar15 = iVar15 + 0x10;
    puVar13 = puVar13 + 4;
    uVar14 = uVar14 + 1;
  } while (bVar1);
  return;
}

/* gldValidateAlphaTest @ 0x4ff70 (416 bytes) */
int gldValidateAlphaTest(glContext)
  int glContext;
{
  float alphaScale;
  int alphaFuncCode;
  undefined2 alphaRef16;
  undefined1 alphaRefByte;
  int glState;
  uint alphaFunc;
  
  alphaScale = FLOAT_001aa168;
  glState = *(int *)(*(int *)(glContext + 4) + 0x10);
  if (((unsigned char *)0x00002d66)[glState] == '\0') {
    *(uint *)(glContext + 0x1a4c) = *(uint *)(glContext + 0x1a4c) & 0xfffff7ff;
  }
  else {
    switch(*(undefined2 *)(((unsigned char *)0x00002d64) + glState)) {
    case 0x201:
      alphaFunc = 1;
      alphaFuncCode = 1;
      break;
    case 0x202:
      alphaFunc = 2;
      alphaFuncCode = 2;
      break;
    case 0x203:
      alphaFunc = 3;
      alphaFuncCode = 3;
      break;
    case 0x204:
      alphaFunc = 4;
      alphaFuncCode = 4;
      break;
    case 0x205:
      alphaFunc = 5;
      alphaFuncCode = 5;
      break;
    case 0x206:
      alphaFunc = 6;
      alphaFuncCode = 6;
      break;
    case 0x207:
      alphaFunc = 7;
      alphaFuncCode = 7;
      break;
    default:
      alphaFunc = 0;
      alphaFuncCode = 0;
    }
    alphaRefByte = 0xff;
    *(uint *)(glContext + 0x1a4c) = alphaFuncCode << 8 | *(uint *)(glContext + 0x1a4c) & 0xfffff8ff;
    if ((uint)(int)(*(float *)(((unsigned char *)0x00002d60) + glState) * alphaScale) < 0x100) {
      alphaRefByte = (undefined1)(int)(*(float *)(((unsigned char *)0x00002d60) + glState) * alphaScale);
    }
    *(undefined1 *)(glContext + 0x1a4f) = alphaRefByte;
    if ((*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x3c00) ==
        0x2800) {
      alphaRef16 = ((uint (*)())floatToHalfBits)((double)*(float *)(((unsigned char *)0x00002d60) + glState));
      *(undefined2 *)(glContext + 0x1bde) = alphaRef16;
    }
    else {
      *(short *)(glContext + 0x1bde) =
           (short)(int)(*(float *)(((unsigned char *)0x00002d60) + glState) * FLOAT_001aa154 + FLOAT_001aa10c);
    }
    *(uint *)(glContext + 0x1a4c) =
         -(alphaFunc ^ 7) >> 0x14 & 0x800 | *(uint *)(glContext + 0x1a4c) & 0xfffff7ff | 0x1000;
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x200;
  return;
}

/* FUN_00050140 @ 0x50140 (424 bytes) */
int FUN_00050140(glContext, param_2, param_3, param_4, param_5, param_6)
  int glContext;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  uint glContextWord1b2c;
  byte colorFormatIndex;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  
  puVar2 = PTR_DAT_001e88c8;
  colorFormatIndex = *(byte *)(glContext + 0x293f);
  iVar4 = *(int *)(*(int *)(glContext + 4) + 0x10);
  if ((*(uint *)(glContext + 0x18a4) & 0x3fffc0) == 0) {
    *(undefined4 *)(0x00001af4 + glContext) = 0;
  }
  else {
    uVar3 = (uint)(((unsigned char *)0x00002e40)[iVar4] == '\x01') *
            ((byte)PTR_DAT_001e88c8[(uint)colorFormatIndex * 0x24 + 0x1c] & 0xf);
    *(uint *)(0x00001af4 + glContext) = uVar3;
    uVar3 = uVar3 | (uint)(((unsigned char *)0x00002e41)[iVar4] == '\x01') *
                    (*(uint *)(puVar2 + (uint)colorFormatIndex * 0x24 + 0x1c) >> 0x14 & 0xf);
    *(uint *)(0x00001af4 + glContext) = uVar3;
    uVar3 = uVar3 | (uint)(((unsigned char *)0x00002e42)[iVar4] == '\x01') *
                    (*(ushort *)(puVar2 + (uint)colorFormatIndex * 0x24 + 0x1c) & 0xf);
    *(uint *)(0x00001af4 + glContext) = uVar3;
    *(uint *)(0x00001af4 + glContext) =
         uVar3 | (uint)(((unsigned char *)0x00002e43)[iVar4] == '\x01') *
                 (*(uint *)(puVar2 + (uint)colorFormatIndex * 0x24 + 0x1c) >> 0xc & 0xf);
  }
  glContextWord1b2c = *(uint *)(glContext + 0x1b2c);
  *(uint *)(glContext + 0x1b2c) = glContextWord1b2c & 0xfffcffff | 0x30000;
  if (*(int *)(((unsigned char *)0x00003194) + iVar4) == 0x1d01) {
    *(uint *)(glContext + 0x1bb8) = *(uint *)(glContext + 0x1bb8) & 0xfff0ffff | 0xa0000;
    *(uint *)(glContext + 0x1b2c) = glContextWord1b2c & 0xfffc0000 | 0x3aaaa;
  }
  else {
    *(uint *)(glContext + 0x1b2c) = glContextWord1b2c & 0xfffcc0c0 | 0x31515;
    if ((*(uint *)(glContext + 0x44) & 0x2000) == 0) {
      *(uint *)(glContext + 0x1b2c) = glContextWord1b2c & 0xfffc0000 | 0x39595;
    }
    else {
      *(uint *)(glContext + 0x1b2c) = glContextWord1b2c & 0xfffc0000 | 0x35555;
    }
    *(uint *)(glContext + 0x1bb8) = *(uint *)(glContext + 0x1bb8) & 0xfff0ffff | 0x50000;
  }
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x10;
  return;
}

/* gldEmitHardwareState @ 0x50300 (3048 bytes) */
int gldEmitHardwareState(glContext)
  int glContext;
{
  undefined4 ctxWord278;
  undefined *finalCallArgR5;
  int reserveResult;
  int streamCurrent;
  undefined4 streamStateWord;
  undefined4 allocatedPacket;
  undefined4 unitShadowValue5;
  undefined4 unitShadowValue3;
  undefined4 unitShadowValue2;
  undefined4 unitShadowValue1;
  uint dirtyUnitMask;
  undefined4 *texUnitShadowPtr4;
  undefined4 *packetCursor;
  uint rb3dBlendcntl;
  uint fgFogBlend;
  uint fgAlphaFunc;
  undefined4 ctxWord27c;
  undefined4 vapVtxNumArrays;
  undefined4 ctxWord2608;
  undefined4 ctxWord2604;
  undefined4 ctxWord25e4;
  undefined4 ctxWord25c0;
  undefined4 ctxWord25b0;
  undefined4 ctxWord2598;
  undefined4 gbZPeqConfig;
  undefined4 suDepthOffset;
  undefined4 zbZstencilcntl;
  undefined4 zbZtop;
  undefined4 rb3dConstantColorGb;
  undefined4 rb3dConstantColorAr;
  undefined4 rb3dConstantColor;
  undefined4 rb3dAblendcntl;
  undefined4 gaSolidBa;
  undefined4 gbSelect;
  undefined4 fgFogColorB;
  undefined4 fgAlphaValue;
  undefined4 fgDepthSrc;
  undefined4 rb3dRopcntl;
  undefined4 gaPointSize;
  undefined4 gaPointMinmax;
  undefined4 ctxWord1e14;
  undefined4 ctxWord1e10;
  undefined4 ctxWord1e0c;
  undefined4 vapTexToColorCntl;
  undefined4 suTexWrapPs3;
  undefined4 ps3VtxFmt;
  undefined4 ps3TexSource;
  undefined4 gbPs3Enable;
  undefined4 gaColorControl1df8;
  undefined4 scEdgerule;
  undefined4 vapPscSgnNormCntl;
  undefined4 vapClipCntl;
  undefined4 vapVtxStateCntl;
  undefined4 vapVtxSize;
  undefined4 vapOutVtxFmt1;
  undefined4 ctxWord1ee0;
  undefined4 gaColorControl;
  undefined4 gaFogOffset;
  undefined4 rb3dColorClearValue;
  undefined4 suTexWrap;
  undefined4 gaEnhance;
  undefined4 rb3dAaresolveCtl;
  undefined4 scScreendoor;
  undefined4 gbMspos1;
  undefined4 gbAaConfig;
  undefined4 gaLineS1;
  undefined4 gaLineStippleValue;
  undefined4 gaLineStippleConfig;
  undefined4 gaTriangleStipple;
  undefined4 gbEnable;
  undefined4 gaLineCntl;
  undefined4 gaRoundMode;
  undefined4 suCullMode;
  undefined4 vapCntlStatus;
  undefined4 rb3dDitherCtl;
  code *streamSetCurrent;
  undefined4 *packet;
  undefined4 *packetEnd;
  undefined4 passThroughR5;
  undefined4 *texUnitShadowPtr5;
  undefined *engineCapsEntry;
  undefined4 passThroughR6;
  int unitIndex;
  undefined4 finalCallArgR6;
  undefined4 passThroughR7;
  undefined4 a4;
  undefined4 passThroughR8;
  undefined4 a5;
  undefined4 unitShadowValue0;
  int glStateBlock;
  undefined4 *texUnitShadowPtr0;
  undefined4 *texUnitShadowPtr1;
  undefined4 *texUnitShadowPtr2;
  undefined4 *texUnitShadowPtr3;
  uint ctxWord2cc;
  
  glStateBlock = *(int *)(*(int *)(glContext + 4) + 0x10);
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,6);
  packet[1] = 0;
  *packet = ((unsigned char *)0x000010a4U);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet + 2;
  (**(code **)(glContext + 0x275c))(glContext,packet + 2);
  packet = (undefined4 *)
           (**(code **)(glContext + 0x2758))
                     (glContext,4,passThroughR5,passThroughR6,passThroughR7,passThroughR8,*(code **)(glContext + 0x2758));
  *packet = ((unsigned char *)0x00001393U);
  packet[1] = 10;
  packet[2] = ((unsigned char *)0x000013c6U);
  packet[3] = 3;
  *(undefined4 **)(0x00002748 + glContext + 4) = packet + 4;
  (**(code **)(glContext + 0x275c))(glContext,packet + 4,passThroughR5,passThroughR6,passThroughR7,passThroughR8,3);
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0x1b4);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet;
  *packet = ((unsigned char *)0x00001394U);
  packetEnd = packet + 0x5a;
  rb3dDitherCtl = *(undefined4 *)(glContext + 0x1af0);
  packet[2] = 0x850;
  packet[1] = rb3dDitherCtl;
  vapCntlStatus = *(undefined4 *)(glContext + 0x1b80);
  packet[4] = 0x110ad;
  packet[3] = vapCntlStatus;
  packet[5] = *(undefined4 *)(0x00001b14 + glContext);
  suCullMode = *(undefined4 *)(glContext + 0x1b30);
  packet[7] = 0x110a2;
  packet[6] = suCullMode;
  packet[8] = *(undefined4 *)(glContext + 0x1b3c);
  gaRoundMode = *(undefined4 *)(glContext + 0x1b48);
  packet[10] = ((unsigned char *)0x0000108dU);
  packet[9] = gaRoundMode;
  gaLineCntl = *(undefined4 *)(glContext + 0x1b40);
  packet[0xc] = ((unsigned char *)0x00001002U);
  packet[0xb] = gaLineCntl;
  gbEnable = *(undefined4 *)(glContext + 0x1b50);
  packet[0xe] = ((unsigned char *)0x00001085U);
  packet[0xd] = gbEnable;
  gaTriangleStipple = *(undefined4 *)(glContext + 0x1b54);
  packet[0x10] = ((unsigned char *)0x0000108eU);
  packet[0xf] = gaTriangleStipple;
  gaLineStippleConfig = *(undefined4 *)(glContext + 0x1b64);
  packet[0x12] = ((unsigned char *)0x00001098U);
  packet[0x11] = gaLineStippleConfig;
  gaLineStippleValue = *(undefined4 *)(glContext + 0x1b68);
  packet[0x14] = 0x11099;
  packet[0x13] = gaLineStippleValue;
  packet[0x15] = *(undefined4 *)(glContext + 0x1b6c);
  gaLineS1 = *(undefined4 *)(glContext + 0x1b70);
  packet[0x19] = 0x11007;
  packet[0x18] = 0;
  packet[0x17] = 0x823;
  packet[0x16] = gaLineS1;
  packet[0x1a] = *(undefined4 *)(glContext + 0x1a64);
  gbAaConfig = *(undefined4 *)(glContext + 0x1a60);
  packet[0x1c] = 0x11004;
  packet[0x1b] = gbAaConfig;
  packet[0x1d] = *(undefined4 *)(glContext + 0x1a68);
  gbMspos1 = *(undefined4 *)(glContext + 0x1a6c);
  packet[0x1f] = ((unsigned char *)0x000010faU);
  packet[0x1e] = gbMspos1;
  scScreendoor = *(undefined4 *)(glContext + 0x1b60);
  packet[0x21] = ((unsigned char *)0x000013a2U);
  packet[0x20] = scScreendoor;
  rb3dAaresolveCtl = *(undefined4 *)(glContext + 0x23c0);
  packet[0x23] = ((unsigned char *)0x0000109dU);
  packet[0x22] = rb3dAaresolveCtl;
  gaEnhance = *(undefined4 *)(glContext + 0x1b4c);
  packet[0x25] = ((unsigned char *)0x000010a8U);
  packet[0x24] = gaEnhance;
  suTexWrap = *(undefined4 *)(glContext + 0x1b28);
  packet[0x27] = 0x311a9;
  packet[0x26] = suTexWrap;
  packet[0x28] = *(undefined4 *)(glContext + 0x233c);
  packet[0x29] = *(undefined4 *)(glContext + 0x2340);
  packet[0x2a] = *(undefined4 *)(glContext + 0x2344);
  packet[0x2b] = *(undefined4 *)(0x00002348 + glContext);
  packet[0x2c] = ((unsigned char *)0x00001385U);
  rb3dColorClearValue = *(undefined4 *)(glContext + 0x1a94);
  packet[0x2e] = 0x110a5;
  packet[0x2d] = rb3dColorClearValue;
  packet[0x2f] = *(undefined4 *)(glContext + 0x1a7c);
  gaFogOffset = *(undefined4 *)(glContext + 0x1a78);
  packet[0x31] = ((unsigned char *)0x0000109eU);
  packet[0x30] = gaFogOffset;
  gaColorControl = *(undefined4 *)(glContext + 0x1b2c);
  packet[0x33] = 0x861;
  packet[0x32] = gaColorControl;
  ctxWord1ee0 = *(undefined4 *)(glContext + 0x1ca0);
  packet[0x35] = 0x10824;
  packet[0x34] = ctxWord1ee0;
  packet[0x36] = *(undefined4 *)(glContext + 0x1b9c);
  vapOutVtxFmt1 = *(undefined4 *)(glContext + 0x1ba0);
  packet[0x38] = 0x1082c;
  packet[0x37] = vapOutVtxFmt1;
  packet[0x39] = *(undefined4 *)(glContext + 0x1b84);
  vapVtxSize = *(undefined4 *)(glContext + 0x248c);
  packet[0x3b] = 0x860;
  packet[0x3a] = vapVtxSize;
  vapVtxStateCntl = *(undefined4 *)(glContext + 0x1b78);
  packet[0x3d] = 0x887;
  packet[0x3c] = vapVtxStateCntl;
  vapClipCntl = *(undefined4 *)(glContext + 0x1b74);
  packet[0x3f] = 0x8a2;
  packet[0x3e] = vapClipCntl;
  packet[0x40] = *(undefined4 *)(glContext + 0x1b88);
  packet[0x41] = 0x877;
  vapPscSgnNormCntl = *(undefined4 *)(glContext + 0x1cb8);
  packet[0x43] = 0x1084d;
  packet[0x46] = 0x5c8;
  packet[0x44] = 0xffffff;
  packet[0x47] = 0x8000;
  packet[0x48] = 0xc0001000;
  packet[0x4a] = ((unsigned char *)0x000010eaU);
  packet[0x49] = 0;
  packet[0x42] = vapPscSgnNormCntl;
  packet[0x45] = 0;
  scEdgerule = *(undefined4 *)(glContext + 0x1abc);
  packet[0x4c] = ((unsigned char *)0x00001096U);
  packet[0x4b] = scEdgerule;
  gaColorControl1df8 = *(undefined4 *)(glContext + 0x1bb8);
  packet[0x4e] = ((unsigned char *)0x00001046U);
  packet[0x4d] = gaColorControl1df8;
  gbPs3Enable = *(undefined4 *)(glContext + 0x1bbc);
  packet[0x50] = ((unsigned char *)0x00001048U);
  packet[0x4f] = gbPs3Enable;
  ps3TexSource = *(undefined4 *)(glContext + 0x1bc0);
  packet[0x52] = ((unsigned char *)0x00001047U);
  packet[0x51] = ps3TexSource;
  ps3VtxFmt = *(undefined4 *)(glContext + 0x1bb0);
  packet[0x54] = ((unsigned char *)0x00001045U);
  packet[0x53] = ps3VtxFmt;
  suTexWrapPs3 = *(undefined4 *)(glContext + 0x1bc4);
  packet[0x56] = 0x886;
  packet[0x55] = suTexWrapPs3;
  vapTexToColorCntl = *(undefined4 *)(glContext + 0x1bc8);
  packet[0x59] = 2;
  packet[0x58] = ((unsigned char *)0x00001180U);
  packet[0x57] = vapTexToColorCntl;
  if ((*(uint *)(glContext + 0x2454) & 0x8000000) != 0) {
    packetEnd = packet + 0x62;
    packet[0x5a] = ((unsigned char *)0x000012fbU);
    ctxWord1e0c = *(undefined4 *)(glContext + 0x1bcc);
    packet[0x5c] = ((unsigned char *)0x000012faU);
    packet[0x5b] = ctxWord1e0c;
    ctxWord1e10 = *(undefined4 *)(glContext + 0x1bd0);
    packet[0x5e] = ((unsigned char *)0x000010e6U);
    packet[0x5d] = ctxWord1e10;
    ctxWord1e14 = *(undefined4 *)(glContext + 0x1bd4);
    packet[0x60] = ((unsigned char *)0x000011f2U);
    packet[0x5f] = ctxWord1e14;
    packet[0x61] = *(undefined4 *)(glContext + 0x1bd8);
  }
  streamSetCurrent = *(code **)(glContext + 0x275c);
  *(undefined4 **)(0x00002748 + glContext + 4) = packetEnd;
  (*streamSetCurrent)(glContext,packetEnd);
  ((int (*)())FUN_0004e880)(glContext);
  dirtyUnitMask = *(uint *)(glContext + 0x27b0) |
           (*(uint *)(glContext + 0x27b0) & *(uint *)(glContext + 0x27b4)) << 8;
  if (dirtyUnitMask != 0) {
    texUnitShadowPtr0 = (undefined4 *)(glContext + 0x1cdc);
    texUnitShadowPtr1 = (undefined4 *)(glContext + 0x1d1c);
    texUnitShadowPtr2 = (undefined4 *)(glContext + 0x1d5c);
    texUnitShadowPtr3 = (undefined4 *)(glContext + 0x1d9c);
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0xe0);
    unitIndex = *(int *)(glContext + 0x1938);
    texUnitShadowPtr4 = (undefined4 *)(glContext + 0x1ddc);
    texUnitShadowPtr5 = (undefined4 *)(glContext + 0x1e1c);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    do {
      if ((dirtyUnitMask & 1) != 0) {
        *packet = ((unsigned char *)0x00001100) + unitIndex;
        unitShadowValue0 = *texUnitShadowPtr0;
        packet[2] = ((unsigned char *)0x00001110) + unitIndex;
        packet[1] = unitShadowValue0;
        unitShadowValue1 = *texUnitShadowPtr1;
        packet[4] = ((unsigned char *)0x00001120U) + unitIndex;
        packet[3] = unitShadowValue1;
        unitShadowValue2 = *texUnitShadowPtr2;
        packet[6] = ((unsigned char *)0x00001130) + unitIndex;
        packet[5] = unitShadowValue2;
        unitShadowValue3 = *texUnitShadowPtr3;
        packet[8] = ((unsigned char *)0x00001170U) + unitIndex;
        packet[7] = unitShadowValue3;
        unitShadowValue5 = *texUnitShadowPtr5;
        packet[10] = ((unsigned char *)0x00001160) + unitIndex;
        packet[0xc] = ((unsigned char *)0x00001140) + unitIndex;
        packet[0xb] = 0;
        packet[9] = unitShadowValue5;
        packet[0xd] = *texUnitShadowPtr4;
        packet = packet + 0xe;
      }
      dirtyUnitMask = dirtyUnitMask >> 1;
      unitIndex = unitIndex + 1;
      texUnitShadowPtr0 = texUnitShadowPtr0 + 1;
      texUnitShadowPtr1 = texUnitShadowPtr1 + 1;
      texUnitShadowPtr2 = texUnitShadowPtr2 + 1;
      texUnitShadowPtr3 = texUnitShadowPtr3 + 1;
      texUnitShadowPtr5 = texUnitShadowPtr5 + 1;
      texUnitShadowPtr4 = texUnitShadowPtr4 + 1;
    } while (dirtyUnitMask != 0);
    streamSetCurrent = *(code **)(glContext + 0x275c);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    (*streamSetCurrent)(glContext,packet);
  }
  if ((*(uint *)(glContext + 0x44) & 0x100) != 0) {
    if ((*(uint *)(glContext + 0x27b0) & 1) == 0) {
      packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,4);
      packetEnd = packet + 4;
      *packet = ((unsigned char *)0x00001041U);
      packet[1] = (*(uint *)(glContext + 0x27b0) | 1) << (*(uint *)(glContext + 0x1938) & 0x3f);
      unitIndex = *(int *)(glContext + 0x1938);
      packet[3] = 0;
      packet[2] = ((unsigned char *)0x00001100) + unitIndex;
      goto LAB_00050920;
    }
  }
  packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
  packetEnd = packet + 2;
  *packet = ((unsigned char *)0x00001041U);
  packet[1] = *(int *)(glContext + 0x27b0) << (*(uint *)(glContext + 0x1938) & 0x3f);
LAB_00050920:
  streamSetCurrent = *(code **)(glContext + 0x275c);
  *(undefined4 **)(0x00002748 + glContext + 4) = packetEnd;
  (*streamSetCurrent)(glContext,packetEnd);
  allocatedPacket = (**(code **)(glContext + 0x2758))(glContext,0x90);
  *(undefined4 *)(0x00002748 + glContext + 4) = allocatedPacket;
  packet = (undefined4 *)((int (*)())gldEmitViewportAndGuardBand)(glContext,allocatedPacket);
  packetCursor = packet + 9;
  *packet = ((unsigned char *)0x0000108cU);
  gaPointMinmax = *(undefined4 *)(glContext + 0x1cd0);
  packet[2] = ((unsigned char *)0x00001087U);
  packet[1] = gaPointMinmax;
  gaPointSize = *(undefined4 *)(glContext + 0x1ccc);
  packet[4] = 0x31080;
  packet[3] = gaPointSize;
  packet[5] = *(undefined4 *)(glContext + 0x1cbc);
  packet[6] = *(undefined4 *)(glContext + 0x1cc4);
  packet[7] = *(undefined4 *)(glContext + 0x1cc0);
  packet[8] = *(undefined4 *)(glContext + 0x1cc8);
  if ((*(int *)(((unsigned char *)0x000031c0) + glStateBlock) != 0) && (((unsigned char *)0x00001491)[glContext] != '\0')) {
    packetCursor = packet + 0xb;
    packet[9] = ((unsigned char *)0x000013c2U);
    packet[10] = *(undefined4 *)(glContext + 0x1aa8);
  }
  packet = packetCursor + 4;
  *packetCursor = ((unsigned char *)0x00001386U);
  rb3dRopcntl = *(undefined4 *)(glContext + 0x1af8);
  packetCursor[2] = ((unsigned char *)0x00001383U);
  packetCursor[1] = rb3dRopcntl;
  packetCursor[3] = *(undefined4 *)(0x00001af4 + glContext);
  if ((*(uint *)(0x00001b14 + glContext) & 3) != 0) {
    packet = packetCursor + 9;
    packetCursor[4] = 0x310a9;
    packetCursor[5] = *(undefined4 *)(glContext + 0x1b1c);
    packetCursor[6] = *(undefined4 *)(glContext + 0x1b18);
    packetCursor[7] = *(undefined4 *)(glContext + 0x1b24);
    packetCursor[8] = *(undefined4 *)(glContext + 0x1b20);
  }
  packet = (undefined4 *)((int (*)())gldEmitScissorRegs)(glContext,packet);
  engineCapsEntry = PTR_DAT_001e88c8;
  *packet = 0x112f5;
  fgAlphaFunc = *(uint *)(glContext + 0x1a4c);
  packet[1] = fgAlphaFunc;
  if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    packet[1] = fgAlphaFunc & 0xfffff7ff;
  }
  fgDepthSrc = *(undefined4 *)(glContext + 0x1a50);
  packet[3] = ((unsigned char *)0x000012f8U);
  packet[2] = fgDepthSrc;
  fgAlphaValue = *(undefined4 *)(glContext + 0x1bdc);
  packet[5] = 0x212f2;
  packet[4] = fgAlphaValue;
  packet[6] = *(undefined4 *)(glContext + 0x1a54);
  packet[7] = *(undefined4 *)(glContext + 0x1a58);
  fgFogColorB = *(undefined4 *)(glContext + 0x1a5c);
  packet[9] = ((unsigned char *)0x00001007U);
  packet[8] = fgFogColorB;
  gbSelect = *(undefined4 *)(glContext + 0x1a64);
  packet[0xb] = ((unsigned char *)0x000012f0U);
  packet[10] = gbSelect;
  fgFogBlend = *(uint *)(glContext + 0x1aec);
  packet[0xc] = fgFogBlend;
  if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    packet[0xc] = fgFogBlend & 0xfffffffe;
  }
  packet[0xd] = 0x1109f;
  packet[0xe] = *(undefined4 *)(glContext + 0x1a70);
  gaSolidBa = *(undefined4 *)(glContext + 0x1a74);
  packet[0x10] = 0x11381;
  packet[0xf] = gaSolidBa;
  rb3dBlendcntl = *(uint *)(glContext + 0x1a80);
  packet[0x11] = rb3dBlendcntl;
  if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
    packet[0x11] = rb3dBlendcntl & 0xfffffffc;
  }
  rb3dAblendcntl = *(undefined4 *)(glContext + 0x1a84);
  packet[0x13] = ((unsigned char *)0x00001384U);
  packet[0x12] = rb3dAblendcntl;
  a5 = 0x113a8;
  a4 = 0x413de;
  finalCallArgR6 = 0x313e9;
  finalCallArgR5 = ((unsigned char *)0x000813adU);
  rb3dConstantColor = *(undefined4 *)(glContext + 0x1a88);
  packet[0x15] = ((unsigned char *)0x000013beU);
  packet[0x14] = rb3dConstantColor;
  rb3dConstantColorAr = *(undefined4 *)(glContext + 0x1a8c);
  packet[0x17] = ((unsigned char *)0x000013bfU);
  packet[0x16] = rb3dConstantColorAr;
  rb3dConstantColorGb = *(undefined4 *)(glContext + 0x1a90);
  packet[0x19] = ((unsigned char *)0x000013c5U);
  packet[0x18] = rb3dConstantColorGb;
  zbZtop = *(undefined4 *)(glContext + 0x1ab8);
  packet[0x1b] = 0x113c0;
  packet[0x1a] = zbZtop;
  packet[0x1c] = *(undefined4 *)(glContext + 0x1aa0);
  zbZstencilcntl = *(undefined4 *)(glContext + 0x1aa4);
  packet[0x1e] = 0x110b0;
  packet[0x1d] = zbZstencilcntl;
  packet[0x1f] = *(undefined4 *)(glContext + 0x1b38);
  suDepthOffset = *(undefined4 *)(0x00001b34 + glContext);
  packet[0x21] = ((unsigned char *)0x0000100aU);
  packet[0x20] = suDepthOffset;
  gbZPeqConfig = *(undefined4 *)(glContext + 0x2354);
  packet[0x23] = 0x113a8;
  packet[0x22] = gbZPeqConfig;
  packet[0x24] = *(undefined4 *)(glContext + 0x235c);
  ctxWord2598 = *(undefined4 *)(glContext + 0x2358);
  packet[0x26] = 0x413de;
  packet[0x25] = ctxWord2598;
  packet[0x27] = *(undefined4 *)(glContext + 0x2360);
  packet[0x28] = *(undefined4 *)(glContext + 0x2364);
  packet[0x29] = *(undefined4 *)(0x00002368 + glContext);
  packet[0x2a] = *(undefined4 *)(glContext + 0x236c);
  ctxWord25b0 = *(undefined4 *)(glContext + 0x2370);
  packet[0x2c] = 0x313e9;
  packet[0x2b] = ctxWord25b0;
  packet[0x2d] = *(undefined4 *)(glContext + 0x2374);
  packet[0x2e] = *(undefined4 *)(glContext + 0x2378);
  packet[0x2f] = *(undefined4 *)(glContext + 0x237c);
  ctxWord25c0 = *(undefined4 *)(glContext + 0x2380);
  packet[0x31] = ((unsigned char *)0x000813adU);
  packet[0x30] = ctxWord25c0;
  packet[0x32] = *(undefined4 *)(glContext + 0x2384);
  packet[0x33] = *(undefined4 *)(0x00002388 + glContext);
  packet[0x34] = *(undefined4 *)(glContext + 0x238c);
  packet[0x35] = *(undefined4 *)(glContext + 0x2390);
  packet[0x36] = *(undefined4 *)(glContext + 0x2394);
  packet[0x37] = *(undefined4 *)(glContext + 0x2398);
  packet[0x38] = *(undefined4 *)(glContext + 0x239c);
  packet[0x39] = *(undefined4 *)(glContext + 0x23a0);
  ctxWord25e4 = *(undefined4 *)(glContext + 0x23a4);
  packet[0x3b] = ((unsigned char *)0x000013e6U);
  packet[0x3a] = ctxWord25e4;
  ctxWord2604 = *(undefined4 *)(glContext + 0x23c4);
  packet[0x3d] = ((unsigned char *)0x000013e7U);
  packet[0x3c] = ctxWord2604;
  ctxWord2608 = *(undefined4 *)(glContext + 0x23c8);
  packet[0x3f] = ((unsigned char *)0x000013e8U);
  packet[0x3e] = ctxWord2608;
  packet[0x40] = *(undefined4 *)(glContext + 0x23cc);
  if ((*(uint *)(glContext + 0x44) & 0x20000) == 0) {
    *(undefined4 *)(glContext + 0x1e68) = 0;
  }
  streamSetCurrent = *(code **)(glContext + 0x275c);
  *(undefined4 **)(0x00002748 + glContext + 4) = packet + 0x41;
  /* issue #79 class: `stw r4,0x274c(r30)` leaves the new write pointer in r4 for the `bctrl` at
   * 0x50d10 - the callback is (ctx, write pointer), like every sibling call through 0x275c */
  (*streamSetCurrent)(glContext,packet + 0x41);
  if (*(int *)(glContext + 0x2494) != 0) {
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0x12);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    *packet = 0x830;
    vapVtxNumArrays = *(undefined4 *)(glContext + 0x2490);
    packet[2] = 0x831;
    packet[1] = vapVtxNumArrays;
    streamStateWord = **(undefined4 **)(glContext + 0x2494);
    packet[4] = 0x834;
    packet[3] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 4);
    packet[6] = 0x837;
    packet[5] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 8);
    packet[8] = 0x83a;
    packet[7] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 0xc);
    packet[10] = 0x83d;
    packet[9] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 0x10);
    packet[0xc] = 0x840;
    packet[0xb] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 0x14);
    packet[0xe] = 0x843;
    packet[0xd] = streamStateWord;
    streamStateWord = *(undefined4 *)(*(int *)(glContext + 0x2494) + 0x18);
    packet[0x10] = 0x846;
    packet[0xf] = streamStateWord;
    packet[0x11] = *(undefined4 *)(*(int *)(glContext + 0x2494) + 0x1c);
    streamCurrent = *(int *)(0x00002748 + glContext + 4);
    streamSetCurrent = *(code **)(glContext + 0x275c);
    *(int *)(0x00002748 + glContext + 4) = streamCurrent + 0x48;
    (*streamSetCurrent)(glContext,streamCurrent + 0x48,finalCallArgR5,finalCallArgR6,a4,a5,packet);
  }
  reserveResult = FUN_0004aa00(glContext,1);
  if (reserveResult == 0) {
    (**(code **)(((unsigned char *)0x00001330) + glContext))(glContext,0xc0100000);
    (**(code **)(((unsigned char *)0x00001338) + glContext))(glContext);
    FUN_00086710(glContext);
  }
  ctxWord2cc = *(uint *)(glContext + 0x8c);
  *(undefined1 *)(glContext + 0x23ec) = 1;
  *(uint *)(glContext + 0x8c) = ctxWord2cc | 0x58000;
  if ((((ctxWord2cc & 0x50000000) == 0) && (*(code **)(((unsigned char *)0x000012b0) + glContext) != (code *)0x0)) &&
     ((ctxWord2cc & 0x200000) != 0)) {
    ctxWord278 = *(undefined4 *)(glContext + 0x38);
    ctxWord27c = *(undefined4 *)(glContext + 0x3c);
    (**(code **)(((unsigned char *)0x000012b0) + glContext))(glContext);
    *(undefined4 *)(glContext + 0x38) = ctxWord278;
    *(undefined4 *)(glContext + 0x3c) = ctxWord27c;
  }
  else {
    *(undefined1 *)(glContext + 0x23ec) = 1;
    ffvpRunStateHook(glContext);
  }
  *(undefined1 *)(glContext + 0x23ec) = 1;
  return;
}

/* FUN_00050ef0 @ 0x50ef0 (284 bytes) */
int FUN_00050ef0(glContext, param_2, param_3, param_4)
  int glContext;
  uint param_2;
  uint param_3;
  uint param_4;
{
  code *streamSetCurrent;
  uint glContextWord1b7c;
  undefined4 *a6;
  int iVar3;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0x80 / param_2;
  if (0x80 / param_3 < 0x80 / param_2) {
    uVar4 = 0x80 / param_3;
  }
  if (10 < uVar4) {
    uVar4 = 10;
  }
  uVar5 = 6;
  if ((param_4 != 0) && (uVar5 = 0x80 / param_4, 6 < uVar5)) {
    uVar5 = 6;
  }
  glContextWord1b7c = *(uint *)(glContext + 0x1b7c);
  if ((uVar4 != (glContextWord1b7c & 0xf)) || (uVar5 != (glContextWord1b7c >> 4 & 0xf))) {
    *(undefined1 *)(glContext + 0x23ec) = 1;
    *(uint *)(glContext + 0x1b7c) = (uVar5 & 0xf) << 4 | uVar4 & 0xf | glContextWord1b7c & 0xffffff00;
  }
  if (*(char *)(glContext + 0x23ec) != '\0') {
    a6 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,4);
    *(undefined4 **)(0x00002748 + glContext + 4) = a6;
    a6[1] = 0;
    *a6 = 0x8a1;
    a6[2] = 0x820;
    a6[3] = *(undefined4 *)(glContext + 0x1b7c);
    iVar3 = *(int *)(0x00002748 + glContext + 4);
    streamSetCurrent = *(code **)(glContext + 0x275c);
    *(int *)(0x00002748 + glContext + 4) = iVar3 + 0x10;
    (*streamSetCurrent)(glContext,iVar3 + 0x10,param_3,param_4,in_r7,in_r8,a6);
    *(undefined1 *)(glContext + 0x23ec) = 0;
  }
  return;
}

/* gldValidateStencil @ 0x51010 (1024 bytes) */
int gldValidateStencil(glContext)
  int glContext;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  iVar7 = *(int *)(*(int *)(glContext + 4) + 0x10);
  if ((*(int *)(((unsigned char *)0x000031c0) + iVar7) == 0) || (((unsigned char *)0x00001491)[glContext] == '\0')) {
    *(undefined1 *)(glContext + 0x23ed) = 0;
    *(uint *)(glContext + 0x1aa0) = *(uint *)(glContext + 0x1aa0) & 0xfffffffe;
    goto LAB_00051404;
  }
  iVar2 = 3;
  *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) | 0x20000000;
  uVar1 = *(ushort *)(((unsigned char *)0x000031a2) + iVar7);
  uVar10 = *(uint *)(&DAT_001db348 + (*(ushort *)(((unsigned char *)0x000031a0) + iVar7) & 7) * 4);
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar2 = 5;
      if (((uVar1 != 0x150a) && (iVar2 = 2, uVar1 != 0x1e01)) && (iVar2 = 1, uVar1 != 0)) {
LAB_000510a0:
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 6;
      if ((uVar1 != 0x8507) && (iVar2 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_000510a0;
        iVar2 = 4;
      }
    }
  }
  uVar1 = *(ushort *)(((unsigned char *)0x000031a6) + iVar7);
  iVar3 = 3;
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar3 = 5;
      if (((uVar1 != 0x150a) && (iVar3 = 2, uVar1 != 0x1e01)) && (iVar3 = 1, uVar1 != 0)) {
LAB_0005111c:
        iVar3 = 0;
      }
    }
    else {
      iVar3 = 6;
      if ((uVar1 != 0x8507) && (iVar3 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_0005111c;
        iVar3 = 4;
      }
    }
  }
  uVar1 = *(ushort *)(((unsigned char *)0x000031a4) + iVar7);
  iVar4 = 3;
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar4 = 5;
      if (((uVar1 != 0x150a) && (iVar4 = 2, uVar1 != 0x1e01)) && (iVar4 = 1, uVar1 != 0)) {
LAB_0005119c:
        iVar4 = 0;
      }
    }
    else {
      iVar4 = 6;
      if ((uVar1 != 0x8507) && (iVar4 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_0005119c;
        iVar4 = 4;
      }
    }
  }
  iVar5 = 3;
  *(char *)(glContext + 0x1aab) = (char)*(undefined4 *)(((unsigned char *)0x0000319c) + iVar7);
  *(char *)(glContext + 0x1aaa) = (char)*(undefined4 *)(((unsigned char *)0x00003198) + iVar7);
  *(char *)(glContext + 0x1aa9) = (char)*(undefined4 *)(((unsigned char *)0x00002e38) + iVar7);
  uVar1 = *(ushort *)(((unsigned char *)0x000031ba) + iVar7);
  uVar9 = *(uint *)(&DAT_001db348 + (*(ushort *)(((unsigned char *)0x000031b8) + iVar7) & 7) * 4);
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar5 = 5;
      if (((uVar1 != 0x150a) && (iVar5 = 2, uVar1 != 0x1e01)) && (iVar5 = 1, uVar1 != 0)) {
LAB_00051244:
        iVar5 = 0;
      }
    }
    else {
      iVar5 = 6;
      if ((uVar1 != 0x8507) && (iVar5 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_00051244;
        iVar5 = 4;
      }
    }
  }
  uVar1 = *(ushort *)(((unsigned char *)0x000031be) + iVar7);
  iVar6 = 3;
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar6 = 5;
      if (((uVar1 != 0x150a) && (iVar6 = 2, uVar1 != 0x1e01)) && (iVar6 = 1, uVar1 != 0)) {
LAB_000512bc:
        iVar6 = 0;
      }
    }
    else {
      iVar6 = 6;
      if ((uVar1 != 0x8507) && (iVar6 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_000512bc;
        iVar6 = 4;
      }
    }
  }
  uVar1 = *(ushort *)(((unsigned char *)0x000031bc) + iVar7);
  iVar8 = 3;
  if (uVar1 != 0x1e02) {
    if (uVar1 < 0x1e03) {
      iVar8 = 5;
      if (((uVar1 != 0x150a) && (iVar8 = 2, uVar1 != 0x1e01)) && (iVar8 = 1, uVar1 != 0)) {
LAB_0005133c:
        iVar8 = 0;
      }
    }
    else {
      iVar8 = 6;
      if ((uVar1 != 0x8507) && (iVar8 = 7, uVar1 != 0x8508)) {
        if (uVar1 != 0x1e03) goto LAB_0005133c;
        iVar8 = 4;
      }
    }
  }
  *(undefined1 *)(glContext + 0x23ed) = 1;
  *(uint *)(glContext + 0x1aa0) = *(uint *)(glContext + 0x1aa0) | 1;
  *(uint *)(glContext + 0x1aa4) =
       iVar8 << 0x18 |
       iVar6 << 0x15 |
       iVar4 << 0xc |
       iVar3 << 9 |
       iVar5 << 0x12 |
       (uVar9 & 7) << 0xf |
       iVar2 << 6 | (uVar10 & 7) << 3 | *(uint *)(glContext + 0x1aa4) & 0xf8000007;
  if ((*(int *)(((unsigned char *)0x00002e38) + iVar7) == 0) ||
     (iVar8 == 0 && (iVar6 == 0 && (iVar4 == 0 && (iVar3 == 0 && (iVar5 == 0 && iVar2 == 0)))))) {
    *(undefined1 *)(glContext + 0x23ed) = 0;
  }
LAB_00051404:
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x808;
  return;
}

/* gldValidateBlend @ 0x51420 (3152 bytes) */
int gldValidateBlend(glContext)
  int glContext;
{
  ushort equationRgb;
  ushort srcFactorRgb;
  ushort uVar3;
  bool usesDestinationColor;
  bool usesDestinationAlpha;
  float fVar6;
  float fVar7;
  int hwSrcFactorRgb;
  int hwDstFactorRgb;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined2 uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  int glState;
  double dVar22;
  double dVar23;
  
  uVar17 = *(uint *)(glContext + 0x1a80);
  uVar20 = *(uint *)(0x00001af4 + glContext + 4);
  glState = *(int *)(*(int *)(glContext + 4) + 0x10);
  *(uint *)(glContext + 0x1a80) = uVar17 & 0x3ffffffe;
  if (((((unsigned char *)0x00002d84)[glState] == '\0') || (((unsigned char *)0x00002e33)[glState] != '\0')) ||
     ((*(int *)(((unsigned char *)0x00002d80) + glState) == -0x7ff97ffa &&
      ((((*(short *)(((unsigned char *)0x00002d68) + glState) == 1 && (*(short *)(((unsigned char *)0x00002d6c) + glState) == 1)) &&
        (*(short *)(((unsigned char *)0x00002d6a) + glState) == 0)) && (*(short *)(((unsigned char *)0x00002d6e) + glState) == 0))))))
  goto LAB_00051ee0;
  equationRgb = *(ushort *)(((unsigned char *)0x00002d80) + glState);
  if (equationRgb == 0x8008) {
    usesDestinationColor = true;
    iVar19 = 5;
  }
  else if (equationRgb < 0x8009) {
    if (equationRgb == 0x8007) {
      usesDestinationColor = true;
      iVar19 = 4;
    }
    else {
LAB_000514ec:
      usesDestinationColor = false;
      iVar19 = 0;
    }
  }
  else if (equationRgb == 0x800a) {
    usesDestinationColor = false;
    iVar19 = 2;
  }
  else {
    if (equationRgb != 0x800b) goto LAB_000514ec;
    usesDestinationColor = false;
    iVar19 = 6;
  }
  srcFactorRgb = *(ushort *)(((unsigned char *)0x00002d82) + glState);
  if (srcFactorRgb == 0x8008) {
    usesDestinationAlpha = true;
    iVar13 = 5;
  }
  else if (srcFactorRgb < 0x8009) {
    if (srcFactorRgb == 0x8007) {
      usesDestinationAlpha = true;
      iVar13 = 4;
    }
    else {
LAB_0005157c:
      usesDestinationAlpha = false;
      iVar13 = 0;
    }
  }
  else if (srcFactorRgb == 0x800a) {
    usesDestinationAlpha = false;
    iVar13 = 2;
  }
  else {
    if (srcFactorRgb != 0x800b) goto LAB_0005157c;
    usesDestinationAlpha = false;
    iVar13 = 6;
  }
  srcFactorRgb = *(ushort *)(((unsigned char *)0x00002d68) + glState);
  if (srcFactorRgb == 0x305) {
    hwSrcFactorRgb = 0x29;
    usesDestinationColor = true;
    iVar15 = 0x29;
  }
  else if (srcFactorRgb < 0x306) {
    if (srcFactorRgb == 0x301) {
      hwSrcFactorRgb = 0x23;
      iVar15 = 0x23;
    }
    else if (srcFactorRgb < 0x302) {
      if (srcFactorRgb == 0) {
        hwSrcFactorRgb = 0x20;
        iVar15 = 0x20;
      }
      else {
        if (srcFactorRgb != 0x300) goto LAB_00051614;
        hwSrcFactorRgb = 0x22;
        iVar15 = 0x22;
      }
    }
    else if (srcFactorRgb == 0x303) {
      hwSrcFactorRgb = 0x27;
      iVar15 = 0x27;
    }
    else if (srcFactorRgb < 0x304) {
      hwSrcFactorRgb = 0x26;
      iVar15 = 0x26;
    }
    else {
      hwSrcFactorRgb = 0x28;
      usesDestinationColor = true;
      iVar15 = 0x28;
    }
  }
  else if (srcFactorRgb == 0x8001) {
    hwSrcFactorRgb = 0x2b;
    iVar15 = 0x2b;
  }
  else if (srcFactorRgb < 0x8002) {
    if (srcFactorRgb == 0x307) {
      hwSrcFactorRgb = 0x25;
      usesDestinationColor = true;
      iVar15 = 0x25;
    }
    else if (srcFactorRgb < 0x307) {
      hwSrcFactorRgb = 0x24;
      usesDestinationColor = true;
      iVar15 = 0x24;
    }
    else if (srcFactorRgb == 0x308) {
      hwSrcFactorRgb = 0x2a;
      usesDestinationColor = true;
      iVar15 = 0x2a;
    }
    else {
LAB_00051614:
      hwSrcFactorRgb = 0x21;
      iVar15 = 0x21;
    }
  }
  else if (srcFactorRgb == 0x8003) {
    iVar15 = 0x2d;
    hwSrcFactorRgb = 0x2d;
  }
  else if (srcFactorRgb < 0x8003) {
    hwSrcFactorRgb = 0x2c;
    iVar15 = 0x2c;
  }
  else {
    if (srcFactorRgb != 0x8004) goto LAB_00051614;
    hwSrcFactorRgb = 0x2e;
    iVar15 = 0x2e;
  }
  uVar3 = *(ushort *)(((unsigned char *)0x00002d6c) + glState);
  if (srcFactorRgb != uVar3) {
    if (uVar3 == 0x305) {
      usesDestinationAlpha = true;
      hwSrcFactorRgb = 0x29;
    }
    else if (uVar3 < 0x306) {
      hwSrcFactorRgb = 0x23;
      if (uVar3 != 0x301) {
        if (uVar3 < 0x302) {
          hwSrcFactorRgb = 0x20;
          if ((uVar3 != 0) && (hwSrcFactorRgb = 0x22, uVar3 != 0x300)) goto LAB_0005179c;
        }
        else {
          hwSrcFactorRgb = 0x27;
          if ((uVar3 != 0x303) && (hwSrcFactorRgb = 0x26, 0x303 < uVar3)) {
            usesDestinationAlpha = true;
            hwSrcFactorRgb = 0x28;
          }
        }
      }
    }
    else {
      hwSrcFactorRgb = 0x2b;
      if (uVar3 != 0x8001) {
        if (uVar3 < 0x8002) {
          if (uVar3 == 0x307) {
            usesDestinationAlpha = true;
            hwSrcFactorRgb = 0x25;
          }
          else if (uVar3 < 0x307) {
            usesDestinationAlpha = true;
            hwSrcFactorRgb = 0x24;
          }
          else {
            if (uVar3 != 0x308) goto LAB_0005179c;
            usesDestinationAlpha = true;
            hwSrcFactorRgb = 0x2a;
          }
        }
        else {
          hwSrcFactorRgb = 0x2d;
          if (((uVar3 != 0x8003) && (hwSrcFactorRgb = 0x2c, 0x8002 < uVar3)) &&
             (hwSrcFactorRgb = 0x2e, uVar3 != 0x8004)) {
LAB_0005179c:
            hwSrcFactorRgb = 0x21;
          }
        }
      }
    }
  }
  srcFactorRgb = *(ushort *)(((unsigned char *)0x00002d6a) + glState);
  if (srcFactorRgb == 0x305) {
    hwDstFactorRgb = 0x29;
    usesDestinationColor = true;
    iVar16 = 0x29;
  }
  else if (srcFactorRgb < 0x306) {
    if (srcFactorRgb == 0x301) {
      hwDstFactorRgb = 0x23;
      usesDestinationColor = true;
      iVar16 = 0x23;
    }
    else if (srcFactorRgb < 0x302) {
      if (srcFactorRgb == 1) {
        hwDstFactorRgb = 0x21;
        usesDestinationColor = true;
        iVar16 = 0x21;
      }
      else {
        if (srcFactorRgb != 0x300) goto LAB_000518a4;
        hwDstFactorRgb = 0x22;
        usesDestinationColor = true;
        iVar16 = 0x22;
      }
    }
    else if (srcFactorRgb == 0x303) {
      hwDstFactorRgb = 0x27;
      usesDestinationColor = true;
      iVar16 = 0x27;
    }
    else if (srcFactorRgb < 0x304) {
      hwDstFactorRgb = 0x26;
      usesDestinationColor = true;
      iVar16 = 0x26;
    }
    else {
      hwDstFactorRgb = 0x28;
      usesDestinationColor = true;
      iVar16 = 0x28;
    }
  }
  else if (srcFactorRgb == 0x8001) {
    hwDstFactorRgb = 0x2b;
    usesDestinationColor = true;
    iVar16 = 0x2b;
  }
  else if (srcFactorRgb < 0x8002) {
    if (srcFactorRgb == 0x306) {
      hwDstFactorRgb = 0x24;
      usesDestinationColor = true;
      iVar16 = 0x24;
    }
    else if (srcFactorRgb == 0x307) {
      hwDstFactorRgb = 0x25;
      usesDestinationColor = true;
      iVar16 = 0x25;
    }
    else {
LAB_000518a4:
      hwDstFactorRgb = 0x20;
      iVar16 = 0x20;
    }
  }
  else if (srcFactorRgb == 0x8003) {
    hwDstFactorRgb = 0x2d;
    usesDestinationColor = true;
    iVar16 = 0x2d;
  }
  else if (srcFactorRgb < 0x8003) {
    hwDstFactorRgb = 0x2c;
    usesDestinationColor = true;
    iVar16 = 0x2c;
  }
  else {
    if (srcFactorRgb != 0x8004) goto LAB_000518a4;
    hwDstFactorRgb = 0x2e;
    usesDestinationColor = true;
    iVar16 = 0x2e;
  }
  uVar3 = *(ushort *)(((unsigned char *)0x00002d6e) + glState);
  if (srcFactorRgb != uVar3) {
    if (uVar3 == 0x305) {
      usesDestinationAlpha = true;
      hwDstFactorRgb = 0x29;
    }
    else if (uVar3 < 0x306) {
      if (uVar3 == 0x301) {
        usesDestinationAlpha = true;
        hwDstFactorRgb = 0x23;
      }
      else if (uVar3 < 0x302) {
        if (uVar3 == 1) {
          usesDestinationAlpha = true;
          hwDstFactorRgb = 0x21;
        }
        else {
          if (uVar3 != 0x300) goto LAB_00051a20;
          usesDestinationAlpha = true;
          hwDstFactorRgb = 0x22;
        }
      }
      else if (uVar3 == 0x303) {
        usesDestinationAlpha = true;
        hwDstFactorRgb = 0x27;
      }
      else if (uVar3 < 0x304) {
        usesDestinationAlpha = true;
        hwDstFactorRgb = 0x26;
      }
      else {
        usesDestinationAlpha = true;
        hwDstFactorRgb = 0x28;
      }
    }
    else if (uVar3 == 0x8001) {
      usesDestinationAlpha = true;
      hwDstFactorRgb = 0x2b;
    }
    else if (uVar3 < 0x8002) {
      if (uVar3 == 0x306) {
        usesDestinationAlpha = true;
        hwDstFactorRgb = 0x24;
      }
      else if (uVar3 == 0x307) {
        usesDestinationAlpha = true;
        hwDstFactorRgb = 0x25;
      }
      else {
LAB_00051a20:
        hwDstFactorRgb = 0x20;
      }
    }
    else if (uVar3 == 0x8003) {
      usesDestinationAlpha = true;
      hwDstFactorRgb = 0x2d;
    }
    else if (uVar3 < 0x8003) {
      usesDestinationAlpha = true;
      hwDstFactorRgb = 0x2c;
    }
    else {
      if (uVar3 != 0x8004) goto LAB_00051a20;
      usesDestinationAlpha = true;
      hwDstFactorRgb = 0x2e;
    }
  }
  if ((equationRgb == 0x8006) &&
     (iVar11 = *(int *)(((unsigned char *)0x00002d68) + glState), iVar11 == *(int *)(((unsigned char *)0x00002d6c) + glState))) {
    if ((iVar11 == 0x3020303) || ((iVar11 == 0x3020001 || (iVar11 == 0x303)))) {
      iVar18 = 1;
    }
    else if ((((iVar11 == 0x301) || (iVar11 == 0x10001)) || (iVar11 == 0x3060001)) ||
            (iVar11 == 0x3040001)) {
      iVar18 = 2;
      if ((*(uint *)(glContext + 0x8c) & 0x400000) == 0) goto LAB_00051c10;
    }
    else if (iVar11 == 0x3070001) {
LAB_00051c10:
      iVar18 = 3;
    }
    else {
      iVar18 = 4;
      if ((iVar11 != 0x3030001) && (iVar18 = 6, iVar11 != 0x3060000)) goto LAB_00051c00;
    }
  }
  else {
LAB_00051c00:
    iVar18 = 0;
  }
  uVar10 = *(uint *)(glContext + 0x1a80);
  *(uint *)(glContext + 0x1a80) = uVar10 | 3;
  dVar22 = DOUBLE_001aa258;
  dVar23 = DOUBLE_001aa1e8;
  if ((usesDestinationColor) || (iVar11 = 0, usesDestinationAlpha)) {
    iVar11 = 1;
  }
  *(uint *)(glContext + 0x1a84) =
       hwDstFactorRgb << 0x18 | hwSrcFactorRgb << 0x10 | iVar13 << 0xc | *(uint *)(glContext + 0x1a84) & 0xc0c08fff;
  *(uint *)(glContext + 0x1a80) =
       iVar16 << 0x18 |
       iVar15 << 0x10 | iVar19 << 0xc | iVar18 << 3 | iVar11 << 2 | uVar10 & 0xc0c08fc3 | 3;
  dVar22 = (double)*(float *)(((unsigned char *)0x00002d7c) + glState) * dVar22;
  if (dVar23 <= dVar22) {
    iVar19 = (int)(dVar22 - dVar23) + -0x80000000;
  }
  else {
    iVar19 = (int)dVar22;
  }
  dVar23 = (double)*(float *)(((unsigned char *)0x00002d70) + glState) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar23) {
    iVar13 = (int)(dVar23 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar13 = (int)dVar23;
  }
  dVar23 = (double)*(float *)(((unsigned char *)0x00002d74) + glState) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar23) {
    hwSrcFactorRgb = (int)(dVar23 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    hwSrcFactorRgb = (int)dVar23;
  }
  dVar23 = (double)*(float *)(((unsigned char *)0x00002d78) + glState) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar23) {
    uVar10 = (int)(dVar23 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar10 = (uint)(int)dVar23;
  }
  *(uint *)(glContext + 0x1a88) = iVar19 << 0x18 | iVar13 << 0x10 | hwSrcFactorRgb << 8 | uVar10;
  fVar7 = FLOAT_001aa154;
  fVar6 = FLOAT_001aa10c;
  if ((*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x3c00) ==
      0x2800) {
    uVar14 = ((uint (*)())floatToHalfBits)((double)*(float *)(((unsigned char *)0x00002d70) + glState));
    *(undefined2 *)(glContext + 0x1a8e) = uVar14;
    uVar14 = ((uint (*)())floatToHalfBits)((double)*(float *)(((unsigned char *)0x00002d7c) + glState));
    *(undefined2 *)(glContext + 0x1a8c) = uVar14;
    uVar14 = ((uint (*)())floatToHalfBits)((double)*(float *)(((unsigned char *)0x00002d78) + glState));
    *(undefined2 *)(glContext + 0x1a92) = uVar14;
    uVar14 = ((uint (*)())floatToHalfBits)((double)*(float *)(((unsigned char *)0x00002d74) + glState));
    *(undefined2 *)(glContext + 0x1a90) = uVar14;
  }
  else {
    *(short *)(glContext + 0x1a8e) =
         (short)(int)(*(float *)(((unsigned char *)0x00002d70) + glState) * FLOAT_001aa154 + FLOAT_001aa10c);
    *(short *)(glContext + 0x1a8c) = (short)(int)(*(float *)(((unsigned char *)0x00002d7c) + glState) * fVar7 + fVar6);
    *(short *)(glContext + 0x1a92) = (short)(int)(*(float *)(((unsigned char *)0x00002d78) + glState) * fVar7 + fVar6);
    *(short *)(glContext + 0x1a90) = (short)(int)(*(float *)(((unsigned char *)0x00002d74) + glState) * fVar7 + fVar6);
  }
LAB_00051ee0:
  if ((((unsigned char *)0x00002ddc)[glState] == '\0') || ((*(uint *)(*(int *)(glContext + 4) + 0x154) & 0xf) != 3))
  {
    *(uint *)(glContext + 0x1af0) = *(uint *)(glContext + 0x1af0) & 0xfffffff0 | 5;
  }
  else {
    *(uint *)(glContext + 0x1af0) = *(uint *)(glContext + 0x1af0) & 0xfffffff0 | 6;
  }
  if ((((unsigned char *)0x00002e33)[glState] == '\0') || (((unsigned char *)0x00001492)[glContext] != '\0')) {
    uVar10 = *(uint *)(0x00001af4 + glContext + 4) & 0xfffffffb;
    *(uint *)(0x00001af4 + glContext + 4) = uVar10;
  }
  else {
    switch(*(undefined2 *)(((unsigned char *)0x00002e30) + glState)) {
    case 0x1500:
      glState = 0;
      break;
    case 0x1501:
      glState = 8;
      break;
    case 0x1502:
      glState = 4;
      break;
    default:
      glState = 0xc;
      break;
    case 0x1504:
      glState = 2;
      break;
    case 0x1505:
      glState = 10;
      break;
    case 0x1506:
      glState = 6;
      break;
    case 0x1507:
      glState = 0xe;
      break;
    case 0x1508:
      glState = 1;
      break;
    case 0x1509:
      glState = 9;
      break;
    case 0x150a:
      glState = 5;
      break;
    case 0x150b:
      glState = 0xd;
      break;
    case 0x150c:
      glState = 3;
      break;
    case 0x150d:
      glState = 0xb;
      break;
    case 0x150e:
      glState = 7;
      break;
    case 0x150f:
      glState = 0xf;
    }
    uVar10 = glState << 8 | *(uint *)(0x00001af4 + glContext + 4) & 0xfffff0ff | 4;
    *(uint *)(0x00001af4 + glContext + 4) = uVar10;
  }
  uVar12 = *(uint *)(glContext + 0x1930);
  *(uint *)(glContext + 0x1930) = uVar12 | 4;
  if (uVar20 != uVar10) {
    *(uint *)(glContext + 0x1930) = uVar12 | 0x10004;
  }
  if (((uVar17 & 1) == 0) && ((*(uint *)(glContext + 0x1a80) & 1) != 0)) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x100;
  }
  return;
}

/* FUN_000520c0 @ 0x520c0 (436 bytes) */
double FUN_000520c0(int glContext,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  uint uVar7;
  int glState;
  int glContextWord1c98;
  int glContextWord1c9c;
  int glContextWord1c90;
  int glContextWord1c94;
  int glContextWord1c88;
  int iVar14;
  int glContextWord1c8c;
  
  dVar6 = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa10c;
  glState = *(int *)(glContext + 4);
  glContextWord1c9c = *(int *)(glContext + 0x1c9c);
  glContextWord1c98 = *(int *)(glContext + 0x1c98);
  glContextWord1c88 = *(int *)(glContext + 0x1c88);
  glContextWord1c94 = *(int *)(glContext + 0x1c94);
  glContextWord1c90 = *(int *)(glContext + 0x1c90);
  glContextWord1c8c = *(int *)(glContext + 0x1c8c);
  iVar14 = *(int *)(glState + 0x10);
  fVar1 = *(float *)(glState + 0x2a58);
  fVar2 = *(float *)(glState + 0x2a54);
  *(undefined4 *)(glContext + 0x1c9c) = *(undefined4 *)(iVar14 + 0x1818);
  *(undefined4 *)(glContext + 0x1c98) = *(undefined4 *)(iVar14 + 0x1828);
  uVar7 = *(uint *)(iVar14 + 0x1840);
  fVar3 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar14 + 0x184c) ^ 0x80000000) -
                         dVar6) * fVar4;
  fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar14 + 0x1844) ^ 0x80000000) -
                         dVar6) + fVar3;
  fVar4 = fVar2 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar14 + 0x1848) ^ 0x80000000) -
                         dVar6) * fVar4;
  if (*(char *)(glContext + 0x293c) != '\0') {
    fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(glState + 0x160) ^ 0x80000000) -
                           dVar6) - fVar5;
    fVar3 = -fVar3;
  }
  *(float *)(glContext + 0x1c8c) = fVar4;
  *(float *)(glContext + 0x1c88) =
       fVar2 * (float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - dVar6) + fVar4;
  *(float *)(glContext + 0x1c94) = fVar3;
  *(float *)(glContext + 0x1c90) = fVar5;
  if (*(char *)(glContext + 0x124) != '\0') {
    *(undefined4 *)(glContext + 0x1c8c) = *(undefined4 *)(glContext + 0x2814);
    *(undefined4 *)(glContext + 0x1c94) = *(undefined4 *)(glContext + 0x2818);
  }
  *(undefined4 *)(glContext + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(glContext + 0x1cb0) = 0x3f800000;
  if ((((glContextWord1c8c != *(int *)(glContext + 0x1c8c)) || (glContextWord1c88 != *(int *)(glContext + 0x1c88))) ||
      (glContextWord1c94 != *(int *)(glContext + 0x1c94))) ||
     (((glContextWord1c90 != *(int *)(glContext + 0x1c90) || (glContextWord1c9c != *(int *)(glContext + 0x1c9c))) ||
      (glContextWord1c98 != *(int *)(glContext + 0x1c98))))) {
    *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x80;
  }
  ((int (*)())gldValidateScissor)(glContext);
  return;
}

/* FUN_00052280 @ 0x52280 (2608 bytes) */
int FUN_00052280(glContext)
  int glContext;
{
  uint padCountdown;
  uint padWords;
  undefined4 *nextPacket;
  undefined4 *packet;
  undefined4 unitShadowValue5;
  undefined4 unitShadowValue3;
  undefined4 unitShadowValue2;
  undefined4 unitShadowValue1;
  int glState;
  int unitIndex;
  uint registerDirty;
  uint fgAlphaFunc;
  uint rb3dBlendcntl;
  uint fgFogBlend;
  undefined4 glContextWord2370;
  undefined4 vapVtxSize;
  undefined4 glContextWord1ca0;
  undefined4 gbMspos1;
  undefined4 gbAaConfig;
  undefined4 suDepthOffset;
  undefined4 usOutFmt3;
  undefined4 rb3dColorChannelMask;
  undefined4 gaLineStippleConfig;
  undefined4 gaPointT1;
  undefined4 gaPointSize;
  undefined4 vapOutVtxFmt1;
  undefined4 gbSelect;
  undefined4 gbEnable;
  undefined4 gaPolyMode;
  undefined4 scHyperzEn;
  undefined4 rb3dConstantColorAr;
  undefined4 rb3dDitherCtl;
  undefined4 rb3dConstantColor;
  undefined4 rb3dAblendcntl;
  undefined4 gaFogOffset;
  undefined4 fgFogColorB;
  undefined *engineCapsEntry;
  undefined4 unitShadowValue0;
  code *streamSetCurrent;
  uint dirtyUnitMask;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 *texUnitShadowPtr4;
  undefined4 *texUnitShadowPtr5;
  int iVar9;
  int iVar10;
  undefined4 *texUnitShadowPtr3;
  uint dirtyBits;
  undefined4 *texUnitShadowPtr0;
  undefined4 *texUnitShadowPtr1;
  undefined4 *texUnitShadowPtr2;
  int iVar16;
  
  dirtyBits = *(uint *)(glContext + 0x1930);
  dirtyUnitMask = *(uint *)(glContext + 0x1934) & *(uint *)(glContext + 0x27b0);
  dirtyUnitMask = dirtyUnitMask | (dirtyUnitMask & *(uint *)(glContext + 0x27b4)) << 8;
  if (dirtyUnitMask != 0) {
    texUnitShadowPtr0 = (undefined4 *)(glContext + 0x1cdc);
    texUnitShadowPtr1 = (undefined4 *)(glContext + 0x1d1c);
    texUnitShadowPtr2 = (undefined4 *)(glContext + 0x1d5c);
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0xe0);
    iVar9 = *(int *)(glContext + 0x1938);
    texUnitShadowPtr3 = (undefined4 *)(glContext + 0x1d9c);
    texUnitShadowPtr4 = (undefined4 *)(glContext + 0x1ddc);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    texUnitShadowPtr5 = (undefined4 *)(glContext + 0x1e1c);
    do {
      if ((dirtyUnitMask & 1) != 0) {
        *packet = ((unsigned char *)0x00001100) + iVar9;
        unitShadowValue0 = *texUnitShadowPtr0;
        packet[2] = ((unsigned char *)0x00001110) + iVar9;
        packet[1] = unitShadowValue0;
        unitShadowValue1 = *texUnitShadowPtr1;
        packet[4] = ((unsigned char *)0x00001120U) + iVar9;
        packet[3] = unitShadowValue1;
        unitShadowValue2 = *texUnitShadowPtr2;
        packet[6] = ((unsigned char *)0x00001130) + iVar9;
        packet[5] = unitShadowValue2;
        unitShadowValue3 = *texUnitShadowPtr3;
        packet[8] = ((unsigned char *)0x00001170U) + iVar9;
        packet[7] = unitShadowValue3;
        unitShadowValue5 = *texUnitShadowPtr5;
        packet[10] = ((unsigned char *)0x00001160) + iVar9;
        packet[0xc] = ((unsigned char *)0x00001140) + iVar9;
        packet[0xb] = 0;
        packet[9] = unitShadowValue5;
        packet[0xd] = *texUnitShadowPtr4;
        packet = packet + 0xe;
      }
      dirtyUnitMask = dirtyUnitMask >> 1;
      iVar9 = iVar9 + 1;
      texUnitShadowPtr0 = texUnitShadowPtr0 + 1;
      texUnitShadowPtr1 = texUnitShadowPtr1 + 1;
      texUnitShadowPtr2 = texUnitShadowPtr2 + 1;
      texUnitShadowPtr3 = texUnitShadowPtr3 + 1;
      texUnitShadowPtr5 = texUnitShadowPtr5 + 1;
      texUnitShadowPtr4 = texUnitShadowPtr4 + 1;
    } while (dirtyUnitMask != 0);
    streamSetCurrent = *(code **)(glContext + 0x275c);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet;
    (*streamSetCurrent)(glContext,packet);
  }
  if (((*(uint *)(glContext + 0x44) & 0x100) == 0) || ((*(uint *)(glContext + 0x27b0) & 1) != 0)) {
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
    nextPacket = packet + 2;
    *packet = ((unsigned char *)0x00001041U);
    packet[1] = *(int *)(glContext + 0x27b0) << (*(uint *)(glContext + 0x1938) & 0x3f);
  }
  else {
    packet = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,4);
    nextPacket = packet + 4;
    *packet = ((unsigned char *)0x00001041U);
    packet[1] = (*(uint *)(glContext + 0x27b0) | 1) << (*(uint *)(glContext + 0x1938) & 0x3f);
    unitIndex = *(int *)(glContext + 0x1938);
    packet[3] = 0;
    packet[2] = ((unsigned char *)0x00001100) + unitIndex;
  }
  streamSetCurrent = *(code **)(glContext + 0x275c);
  *(undefined4 **)(0x00002748 + glContext + 4) = nextPacket;
  (*streamSetCurrent)(glContext,nextPacket);
  if (dirtyBits == 0) {
    *(undefined4 *)(glContext + 0x1934) = 0;
  }
  else {
    nextPacket = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,0xde);
    *(undefined4 **)(0x00002748 + glContext + 4) = nextPacket;
    packet = nextPacket;
    if ((dirtyBits & 0x100) != 0) {
      packet = nextPacket + 2;
      *nextPacket = ((unsigned char *)0x00001393U);
      nextPacket[1] = 10;
    }
    if ((dirtyBits & 0x2000000) != 0) {
      *packet = ((unsigned char *)0x000013c6U);
      packet[1] = 3;
      packet = packet + 2;
    }
    if ((dirtyBits & 1) != 0) {
      *packet = 0x212f2;
      packet[1] = *(undefined4 *)(glContext + 0x1a54);
      packet[2] = *(undefined4 *)(glContext + 0x1a58);
      engineCapsEntry = PTR_DAT_001e88c8;
      fgFogColorB = *(undefined4 *)(glContext + 0x1a5c);
      packet[4] = ((unsigned char *)0x000012f0U);
      packet[3] = fgFogColorB;
      fgFogBlend = *(uint *)(glContext + 0x1aec);
      packet[5] = fgFogBlend;
      if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
        packet[5] = fgFogBlend & 0xfffffffe;
      }
      packet[6] = 0x110a5;
      packet[7] = *(undefined4 *)(glContext + 0x1a7c);
      gaFogOffset = *(undefined4 *)(glContext + 0x1a78);
      packet[9] = ((unsigned char *)0x00001007U);
      packet[8] = gaFogOffset;
      packet[10] = *(undefined4 *)(glContext + 0x1a64);
      packet = packet + 0xb;
    }
    engineCapsEntry = PTR_DAT_001e88c8;
    if ((dirtyBits & 4) != 0) {
      *packet = 0x11381;
      rb3dBlendcntl = *(uint *)(glContext + 0x1a80);
      packet[1] = rb3dBlendcntl;
      if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
        packet[1] = rb3dBlendcntl & 0xfffffffc;
      }
      rb3dAblendcntl = *(undefined4 *)(glContext + 0x1a84);
      packet[3] = ((unsigned char *)0x00001384U);
      packet[2] = rb3dAblendcntl;
      rb3dConstantColor = *(undefined4 *)(glContext + 0x1a88);
      packet[5] = ((unsigned char *)0x00001394U);
      packet[4] = rb3dConstantColor;
      rb3dDitherCtl = *(undefined4 *)(glContext + 0x1af0);
      packet[7] = ((unsigned char *)0x000013beU);
      packet[6] = rb3dDitherCtl;
      rb3dConstantColorAr = *(undefined4 *)(glContext + 0x1a8c);
      packet[9] = ((unsigned char *)0x000013bfU);
      packet[8] = rb3dConstantColorAr;
      packet[10] = *(undefined4 *)(glContext + 0x1a90);
      packet = packet + 0xb;
    }
    if ((dirtyBits & 0x10000) != 0) {
      *packet = ((unsigned char *)0x00001386U);
      packet[1] = *(undefined4 *)(glContext + 0x1af8);
      packet = packet + 2;
    }
    if ((dirtyBits & 0x200) != 0) {
      *packet = ((unsigned char *)0x000012f5U);
      engineCapsEntry = PTR_DAT_001e88c8;
      fgAlphaFunc = *(uint *)(glContext + 0x1a4c);
      packet[1] = fgAlphaFunc;
      if ((*(uint *)(engineCapsEntry + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
        packet[1] = fgAlphaFunc & 0xfffff7ff;
      }
      packet[2] = ((unsigned char *)0x000012f8U);
      packet[3] = *(undefined4 *)(glContext + 0x1bdc);
      packet = packet + 4;
    }
    if ((dirtyBits & 0x8000000) != 0) {
      *packet = ((unsigned char *)0x000012f6U);
      packet[1] = *(undefined4 *)(glContext + 0x1a50);
      packet = packet + 2;
    }
    nextPacket = packet;
    if ((dirtyBits & 0x20000) != 0) {
      nextPacket = packet + 2;
      *packet = ((unsigned char *)0x000013c5U);
      packet[1] = *(undefined4 *)(glContext + 0x1ab8);
      if (1 < *(int *)(glContext + 0x23dc)) {
        nextPacket = packet + 4;
        packet[2] = ((unsigned char *)0x000010e6U);
        packet[3] = *(undefined4 *)(glContext + 0x1bd4);
      }
    }
    if ((dirtyBits & 0x800) != 0) {
      *nextPacket = 0x113c0;
      nextPacket[1] = *(undefined4 *)(glContext + 0x1aa0);
      nextPacket[2] = *(undefined4 *)(glContext + 0x1aa4);
      nextPacket = nextPacket + 3;
    }
    if ((dirtyBits & 8) != 0) {
      *nextPacket = ((unsigned char *)0x000013c2U);
      nextPacket[1] = *(undefined4 *)(glContext + 0x1aa8);
      nextPacket = nextPacket + 2;
    }
    if ((dirtyBits & 0x1000) != 0) {
      glState = *(int *)(glContext + 4);
      puVar5 = *(uint **)(glState + 0x1d8);
      *puVar5 = (int)nextPacket - (int)puVar5 >> 2 | *puVar5;
      *(undefined4 **)(glState + 0x1d8) = nextPacket;
      *nextPacket = 0x2f000000;
      nextPacket[1] = ((unsigned char *)0x000010e9U);
      scHyperzEn = *(undefined4 *)(glContext + 0x1ae0);
      nextPacket[3] = ((unsigned char *)0x000013c7U);
      nextPacket[2] = scHyperzEn;
      nextPacket[4] = *(undefined4 *)(glContext + 0x1ab0);
      nextPacket = nextPacket + 5;
    }
    if ((dirtyBits & 0x20) != 0) {
      *nextPacket = 0x410a9;
      nextPacket[1] = *(undefined4 *)(glContext + 0x1b1c);
      nextPacket[2] = *(undefined4 *)(glContext + 0x1b18);
      nextPacket[3] = *(undefined4 *)(glContext + 0x1b24);
      nextPacket[4] = *(undefined4 *)(glContext + 0x1b20);
      nextPacket[5] = *(undefined4 *)(0x00001b14 + glContext);
      nextPacket = nextPacket + 6;
    }
    if ((dirtyBits & 0x2000) != 0) {
      *nextPacket = ((unsigned char *)0x000010a2U);
      gaPolyMode = *(undefined4 *)(glContext + 0x1b3c);
      nextPacket[2] = ((unsigned char *)0x00001002U);
      nextPacket[1] = gaPolyMode;
      gbEnable = *(undefined4 *)(glContext + 0x1b50);
      nextPacket[4] = ((unsigned char *)0x00001007U);
      nextPacket[3] = gbEnable;
      gbSelect = *(undefined4 *)(glContext + 0x1a64);
      nextPacket[6] = 0x825;
      nextPacket[5] = gbSelect;
      vapOutVtxFmt1 = *(undefined4 *)(glContext + 0x1ba0);
      nextPacket[8] = ((unsigned char *)0x00001048U);
      nextPacket[7] = vapOutVtxFmt1;
      nextPacket[9] = *(undefined4 *)(glContext + 0x1bc0);
      nextPacket = nextPacket + 10;
    }
    if ((dirtyBits & 0x8000) != 0) {
      *nextPacket = ((unsigned char *)0x00001087U);
      gaPointSize = *(undefined4 *)(glContext + 0x1ccc);
      nextPacket[2] = 0x31080;
      nextPacket[1] = gaPointSize;
      nextPacket[3] = *(undefined4 *)(glContext + 0x1cbc);
      nextPacket[4] = *(undefined4 *)(glContext + 0x1cc4);
      nextPacket[5] = *(undefined4 *)(glContext + 0x1cc0);
      gaPointT1 = *(undefined4 *)(glContext + 0x1cc8);
      nextPacket[7] = ((unsigned char *)0x0000108cU);
      nextPacket[6] = gaPointT1;
      nextPacket[8] = *(undefined4 *)(glContext + 0x1cd0);
      nextPacket = nextPacket + 9;
    }
    if ((dirtyBits & 0x4000) != 0) {
      *nextPacket = 0x1108d;
      nextPacket[1] = *(undefined4 *)(glContext + 0x1b40);
      gaLineStippleConfig = *(undefined4 *)(glContext + 0x1b64);
      nextPacket[3] = ((unsigned char *)0x0000109aU);
      nextPacket[2] = gaLineStippleConfig;
      nextPacket[4] = *(undefined4 *)(glContext + 0x1b70);
      nextPacket = nextPacket + 5;
    }
    if ((dirtyBits & 0x10) != 0) {
      *nextPacket = ((unsigned char *)0x00001383U);
      rb3dColorChannelMask = *(undefined4 *)(0x00001af4 + glContext);
      nextPacket[2] = ((unsigned char *)0x0000109eU);
      nextPacket[1] = rb3dColorChannelMask;
      nextPacket[3] = *(undefined4 *)(glContext + 0x1b2c);
      nextPacket = nextPacket + 4;
    }
    if ((dirtyBits & 0x40) != 0) {
      *nextPacket = 0x311a9;
      nextPacket[1] = *(undefined4 *)(glContext + 0x233c);
      nextPacket[2] = *(undefined4 *)(glContext + 0x2340);
      nextPacket[3] = *(undefined4 *)(glContext + 0x2344);
      usOutFmt3 = *(undefined4 *)(0x00002348 + glContext);
      nextPacket[5] = ((unsigned char *)0x000010b1U);
      nextPacket[4] = usOutFmt3;
      suDepthOffset = *(undefined4 *)(0x00001b34 + glContext);
      nextPacket[7] = ((unsigned char *)0x000010b0U);
      nextPacket[6] = suDepthOffset;
      nextPacket[8] = *(undefined4 *)(glContext + 0x1b38);
      nextPacket = nextPacket + 9;
    }
    if ((dirtyBits & 0x400) != 0) {
      *nextPacket = ((unsigned char *)0x000010aeU);
      nextPacket[1] = *(undefined4 *)(glContext + 0x1b30);
      nextPacket = nextPacket + 2;
    }
    if ((dirtyBits & 0x80000) != 0) {
      *nextPacket = ((unsigned char *)0x00001008U);
      gbAaConfig = *(undefined4 *)(glContext + 0x1a60);
      nextPacket[2] = 0x11004;
      nextPacket[1] = gbAaConfig;
      nextPacket[3] = *(undefined4 *)(glContext + 0x1a68);
      gbMspos1 = *(undefined4 *)(glContext + 0x1a6c);
      nextPacket[5] = ((unsigned char *)0x000010faU);
      nextPacket[4] = gbMspos1;
      nextPacket[6] = *(undefined4 *)(glContext + 0x1b60);
      nextPacket = nextPacket + 7;
    }
    if ((dirtyBits & 2) != 0) {
      nextPacket = (undefined4 *)((int (*)())gldEmitScissorRegs)(glContext,nextPacket);
    }
    if ((dirtyBits & 0x80) != 0) {
      nextPacket = (undefined4 *)((int (*)())gldEmitViewportAndGuardBand)(glContext,nextPacket);
    }
    packet = nextPacket;
    if ((dirtyBits & 0x40000) != 0) {
      packet = nextPacket + 10;
      *nextPacket = 0x10860;
      nextPacket[1] = *(undefined4 *)(glContext + 0x1b78);
      glContextWord1ca0 = *(undefined4 *)(glContext + 0x1ca0);
      nextPacket[3] = 0x82d;
      nextPacket[2] = glContextWord1ca0;
      vapVtxSize = *(undefined4 *)(glContext + 0x1ca4);
      nextPacket[5] = 0x10824;
      nextPacket[4] = vapVtxSize;
      nextPacket[6] = *(undefined4 *)(glContext + 0x1b9c);
      vapOutVtxFmt1 = *(undefined4 *)(glContext + 0x1ba0);
      nextPacket[8] = ((unsigned char *)0x00001047U);
      nextPacket[7] = vapOutVtxFmt1;
      nextPacket[9] = *(undefined4 *)(glContext + 0x1bb0);
      if ((-1 < (int)dirtyBits) || (*(char *)(glContext + 0x1868) != '\0')) {
        iVar16 = 8;
        nextPacket[10] = ((unsigned char *)0x000010c0U);
        iVar10 = 0;
        nextPacket[0xb] = *(undefined4 *)(glContext + 0x1f2c);
        nextPacket[0xc] = *(uint *)(glContext + 0x1f28) | 0x70000;
        iVar9 = glContext;
        do {
          puVar6 = (undefined4 *)(iVar9 + 0x1ee8);
          iVar9 = iVar9 + 4;
          *(undefined4 *)((int)nextPacket + iVar10 + 0x34) = *puVar6;
          iVar10 = iVar10 + 4;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        packet = nextPacket + 0x15;
      }
    }
    if ((dirtyBits & 0x400000) != 0) {
      *packet = 0x887;
      packet[1] = *(undefined4 *)(glContext + 0x1b74);
      packet = packet + 2;
    }
    if ((dirtyBits & 0x800000) != 0) {
      *packet = ((unsigned char *)0x00001002U);
      gbEnable = *(undefined4 *)(glContext + 0x1b50);
      packet[2] = 0x825;
      packet[1] = gbEnable;
      vapOutVtxFmt1 = *(undefined4 *)(glContext + 0x1ba0);
      packet[4] = ((unsigned char *)0x00001048U);
      packet[3] = vapOutVtxFmt1;
      packet[5] = *(undefined4 *)(glContext + 0x1bc0);
      packet = packet + 6;
    }
    if ((dirtyBits & 0x4000000) != 0) {
      *(undefined4 *)(glContext + 0x1e68) = 0;
    }
    if ((dirtyBits & 0x10000000) != 0) {
      *packet = 0x413de;
      packet[1] = *(undefined4 *)(glContext + 0x2360);
      packet[2] = *(undefined4 *)(glContext + 0x2364);
      packet[3] = *(undefined4 *)(0x00002368 + glContext);
      packet[4] = *(undefined4 *)(glContext + 0x236c);
      glContextWord2370 = *(undefined4 *)(glContext + 0x2370);
      packet[6] = 0x313e9;
      packet[5] = glContextWord2370;
      packet[7] = *(undefined4 *)(glContext + 0x2374);
      packet[8] = *(undefined4 *)(glContext + 0x2378);
      packet[9] = *(undefined4 *)(glContext + 0x237c);
      packet[10] = *(undefined4 *)(glContext + 0x2380);
      packet = packet + 0xb;
    }
    if ((dirtyBits & 0x20000000) != 0) {
      *packet = ((unsigned char *)0x000813adU);
      packet[1] = *(undefined4 *)(glContext + 0x2384);
      packet[2] = *(undefined4 *)(0x00002388 + glContext);
      packet[3] = *(undefined4 *)(glContext + 0x238c);
      packet[4] = *(undefined4 *)(glContext + 0x2390);
      packet[5] = *(undefined4 *)(glContext + 0x2394);
      packet[6] = *(undefined4 *)(glContext + 0x2398);
      packet[7] = *(undefined4 *)(glContext + 0x239c);
      packet[8] = *(undefined4 *)(glContext + 0x23a0);
      packet[9] = *(undefined4 *)(glContext + 0x23a4);
      packet = packet + 10;
    }
    padWords = (uint)-(int)packet >> 2 & 0xf;
    nextPacket = packet;
    for (padCountdown = padWords; padCountdown != 0; padCountdown = padCountdown - 1) {
      *nextPacket = 0x80000000;
      nextPacket = nextPacket + 1;
    }
    streamSetCurrent = *(code **)(glContext + 0x275c);
    *(undefined4 **)(0x00002748 + glContext + 4) = packet + padWords;
    (*streamSetCurrent)(glContext,packet + padWords);
    registerDirty = *(uint *)(glContext + 0x1930);
    if ((registerDirty & 0xc0100000) != 0) {
      (**(code **)(((unsigned char *)0x00001330) + glContext))(glContext,0xc0100000);
      registerDirty = *(uint *)(glContext + 0x1930);
    }
    if ((registerDirty & 0x200000) != 0) {
      FUN_00086710(glContext);
      registerDirty = *(uint *)(glContext + 0x1930);
    }
    if ((registerDirty & 0x1000000) != 0) {
      FUN_00086840(glContext);
    }
    *(undefined4 *)(glContext + 0x1934) = 0;
    *(undefined4 *)(glContext + 0x1930) = 0;
  }
  return;
}

/* FUN_00052cc0 @ 0x52cc0 (372 bytes) */
int FUN_00052cc0(glContext)
  int glContext;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  puVar2 = PTR_FUN_001e89b8;
  puVar1 = PTR_FUN_001e89b0;
  uVar3 = 0;
  if (glContext != -0x1168) {
    if (*(char *)(glContext + 0x1868) == '\0') {
      *(undefined **)(((unsigned char *)0x000011a0) + glContext) = PTR_FUN_001e89c4;
      *(undefined **)(((unsigned char *)0x000011a8) + glContext) = puVar2;
      puVar1 = PTR_FUN_001e89d8;
      *(undefined **)(((unsigned char *)0x000011a4) + glContext) = PTR_FUN_001e89c8;
      *(undefined **)(((unsigned char *)0x000011b0) + glContext) = puVar1;
      puVar1 = PTR_FUN_001e89a8;
      *(undefined **)(((unsigned char *)0x000011ac) + glContext) = PTR_LAB_001e89cc;
      *(undefined **)(((unsigned char *)0x00001190) + glContext) = puVar1;
      puVar1 = PTR_FUN_001e89e8;
      *(undefined **)(((unsigned char *)0x00001194) + glContext) = PTR_FUN_001e89b4;
      *(undefined **)(((unsigned char *)0x0000119c) + glContext) = puVar1;
      *(undefined **)(((unsigned char *)0x00001198) + glContext) = PTR_FUN_001e89a4;
    }
    else {
      *(undefined **)(((unsigned char *)0x000011a0) + glContext) = PTR_FUN_001e89bc;
      *(undefined **)(((unsigned char *)0x000011a8) + glContext) = puVar1;
      puVar1 = PTR_FUN_001e89d8;
      *(undefined **)(((unsigned char *)0x000011a4) + glContext) = PTR_FUN_001e89d0;
      *(undefined **)(((unsigned char *)0x000011b0) + glContext) = puVar1;
      puVar1 = PTR_FUN_001e89a0;
      *(undefined **)(((unsigned char *)0x000011ac) + glContext) = PTR_LAB_001e89d4;
      *(undefined **)(((unsigned char *)0x00001190) + glContext) = puVar1;
      puVar1 = PTR_FUN_001e89dc;
      *(undefined **)(((unsigned char *)0x00001194) + glContext) = PTR_FUN_001e89e4;
      *(undefined **)(((unsigned char *)0x0000119c) + glContext) = puVar1;
      *(undefined **)(((unsigned char *)0x00001198) + glContext) = PTR_FUN_001e89c0;
    }
    puVar1 = PTR_FUN_001e89ac;
    if (*(char *)(glContext + 0x1868) == '\0') {
      *(undefined4 *)(((unsigned char *)0x00001354) + glContext) = 0;
      *(undefined4 *)(((unsigned char *)0x0000134c) + glContext) = 0;
      *(undefined **)(((unsigned char *)0x00001350) + glContext) = PTR_FUN_001e89e0;
    }
    else {
      *(undefined4 *)(((unsigned char *)0x00001354) + glContext) = 0;
      *(undefined4 *)(((unsigned char *)0x0000134c) + glContext) = 0;
      *(undefined **)(((unsigned char *)0x00001350) + glContext) = puVar1;
    }
    ((unsigned char *)0x000013b0)[glContext] = 8;
    extvsInitState(glContext);
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_00052e60 @ 0x52e60 (112 bytes) */
int FUN_00052e60(glContext, param_2, param_3)
  int glContext;
  undefined4 param_2;
  uint param_3;
{
  undefined4 uVar1;
  
  *(undefined4 *)(0x00002748 + glContext + 4) = param_2;
  *(uint *)(glContext + 0x44) =
       (param_3 & 1) << 0x13 | (param_3 & 1) << 0x14 | *(uint *)(glContext + 0x44) & 0xffe7ffff;
  if (*(char *)(glContext + 0x1868) == '\0') {
    FUN_00064f40(glContext,param_2);
  }
  else {
    (**(code **)((int)((unsigned char *)0x000011cc) + glContext))(glContext);
  }
  uVar1 = *(undefined4 *)(0x00002748 + glContext + 4);
  *(undefined1 *)(glContext + 0x2d) = 0;
  return uVar1;
}

/* FUN_00052ee0 @ 0x52ee0 (128 bytes) */
int FUN_00052ee0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1) + 0x1c;
  iVar1 = extvsSymbolListGetIndex(iVar2,param_2);
  if (iVar1 == 0) {
    iVar2 = *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x14;
    iVar1 = extvsSymbolListGetIndex(iVar2,param_2);
    if (iVar1 == 0) {
      return -0x3ffcf000;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x54 + *(int *)(iVar2 + 4));
  if (iVar1 == 0) {
    return -0x3ffcf000;
  }
  return iVar1;
}

/* FUN_00052f60 @ 0x52f60 (148 bytes) */
int FUN_00052f60(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1) + 0x1c;
  iVar1 = extvsSymbolListGetIndex(iVar2,param_2);
  if (iVar1 == 0) {
    iVar2 = *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x14;
    iVar1 = extvsSymbolListGetIndex(iVar2,param_2);
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = *(int *)(iVar1 * 0x54 + *(int *)(iVar2 + 4) + 4);
  if (iVar1 == 0) {
    iVar1 = 0x81;
  }
  return iVar1;
}

/* FUN_00053000 @ 0x53000 (52 bytes) */
int FUN_00053000(glContext, param_2)
  int glContext;
  uint param_2;
{
  byte bVar1;
  
  bVar1 = 0xc;
  if ((param_2 & 2) == 0) {
    bVar1 = 0;
  }
  *(uint *)(glContext + 0x38) = *(uint *)(glContext + 0x38) | 0x1000;
  *(byte *)(glContext + 0x2d) = bVar1 | *(byte *)(glContext + 0x2d);
  *(undefined1 *)(glContext + 0x29) = 1;
  return;
}

/* FUN_00053040 @ 0x53040 (20 bytes) */
int FUN_00053040(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (param_2 != 0) {
    return 0x882;
  }
  return 4;
}

/* noop_53060 @ 0x53060 (4 bytes) */
int noop_53060(param_1)
  undefined4 param_1;
{
  /* hidden-argument defect (hidden_params.py) - real body is a single `blr`: an identity function
   * on r3, and its one real caller (part_005.c) does supply a real param_1. */
  return param_1;
}

/* extvsConstantsDirty @ 0x53070 (36 bytes) */
int extvsConstantsDirty(ctx)
  int ctx;
{
  if ((*(int *)(((unsigned char *)0x00001168) + ctx) != 0) &&
     (*(char *)(*(int *)(((unsigned char *)0x00001168) + ctx) + 0x10) != '\0')) {
    return 1;
  }
  return 0;
}

/* extvsClearConstantsDirty @ 0x530a0 (24 bytes) */
int extvsClearConstantsDirty(ctx)
  int ctx;
{
  if (*(int *)(((unsigned char *)0x00001168) + ctx) == 0) {
    return;
  }
  *(undefined1 *)(*(int *)(((unsigned char *)0x00001168) + ctx) + 0x10) = 0;
  return;
}

/* FUN_000530c0 @ 0x530c0 (184 bytes) */
int FUN_000530c0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 *param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1);
  if ((iVar2 == 0) || (param_2 != *(int *)(iVar2 + 8))) {
    iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 4);
    if (iVar1 == 0) {
LAB_00053150:
      param_3[4] = 0;
      *param_3 = 0;
      param_3[1] = 0;
      param_3[2] = 0;
      param_3[3] = 0;
      return;
    }
    iVar3 = *(int *)(*(int *)(((unsigned char *)0x0000116c) + param_1) + 0xc);
    do {
      iVar2 = iVar3;
      if (*(int *)(iVar3 + 8) != param_2) {
        iVar2 = 0;
      }
      iVar1 = iVar1 + -1;
      if (iVar1 == 0) {
        if (iVar2 == 0) goto LAB_00053150;
        break;
      }
      iVar3 = iVar3 + 0x7c;
    } while (iVar2 == 0);
  }
  *param_3 = *(undefined4 *)(iVar2 + 0x54);
  param_3[1] = *(int *)(iVar2 + 0x5c) + *(int *)(iVar2 + 0x60);
  param_3[2] = *(undefined4 *)(iVar2 + 100);
  param_3[3] = *(undefined4 *)(iVar2 + 0x58);
  param_3[4] = *(undefined4 *)(iVar2 + 0x68);
  return;
}

/* FUN_00053190 @ 0x53190 (116 bytes) */
int FUN_00053190(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(((unsigned char *)0x00001168) + param_1);
  if ((iVar1 != 0) && (uVar2 = (uint)(byte)((unsigned char *)0x000013b0)[param_1], uVar2 != 0)) {
    uVar4 = 0;
    uVar3 = 0;
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    do {
      if (*(char *)(iVar1 + 0x71) != '\0') {
        uVar3 = uVar3 | 1 << (uVar4 & 0x3f);
      }
      uVar4 = uVar4 + 1;
      iVar1 = iVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
    return uVar3;
  }
  return 0;
}

/* extvsGetOrCreateStateSymbol @ 0x53220 (284 bytes) */
int extvsGetOrCreateStateSymbol(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = (param_2 + param_3) * 4 & 0x7c;
  piVar1 = *(int **)(uVar3 + *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x28);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      iVar4 = *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x14;
      iVar2 = extvsCreateSymbol(param_1,iVar4,param_4,param_5,0x87e1,0,0,param_3);
      if (iVar2 != 0) {
        iVar4 = extvsSymbolListGetSymbol(iVar4,iVar2);
        *(undefined4 *)(iVar4 + 0x50) = param_6;
        *(int *)(iVar4 + 0x48) = param_2;
        *(undefined1 *)(iVar4 + 0x44) = 1;
        *(int *)(iVar4 + 0x4c) = param_3;
        piVar1 = (int *)(**(code **)(param_1 + 0xc))(0x10);
        *piVar1 = param_2;
        piVar1[1] = param_3;
        piVar1[2] = iVar2;
        piVar1[3] = *(int *)(uVar3 + *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x28);
        *(int **)(uVar3 + *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x28) = piVar1;
      }
      return iVar2;
    }
    if ((param_2 == *piVar1) && (param_3 == piVar1[1])) break;
    piVar1 = (int *)piVar1[3];
  }
  return piVar1[2];
}

/* glGenSymbolsEXT_impl @ 0x53340 (368 bytes) */
int glGenSymbolsEXT_impl(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
  int param_6;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint loopIndex;
  undefined4 uVar5;
  
  if (((param_2 - 0x87beU < 3) &&
      (((((param_3 - 0x87c1U < 2 || (param_3 == 0x87c4)) || (param_3 == 0x87c3)) ||
        ((param_3 == -3 || (param_3 == -2)))) || (param_3 == -1)))) && (param_4 - 0x87e0U < 2)) {
    if (((param_3 - 0x87c3U < 2) || (param_3 == -3)) || ((param_3 == -2 || (param_3 == -1)))) {
      iVar3 = *(int *)(((unsigned char *)0x00001168) + param_1) + 0x1c;
      if (((unsigned char *)0x00001170)[param_1] == '\0') goto LAB_000534a0;
    }
    else {
      iVar3 = *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x14;
    }
    uVar5 = extvsCreateSymbol(param_1,iVar3,param_2,param_3,param_4,0,param_5,param_6);
    if (1 < param_5) {
      loopIndex = 1;
      do {
        iVar1 = param_5 - loopIndex;
        iVar2 = loopIndex + param_6;
        loopIndex = loopIndex + 1;
        extvsCreateSymbol(param_1,iVar3,param_2,param_3,param_4,uVar5,iVar1,iVar2);
      } while (param_5 != loopIndex);
    }
  }
  else {
LAB_000534a0:
    uVar5 = 0;
  }
  return uVar5;
}

/* FUN_000534c0 @ 0x534c0 (260 bytes) */
int FUN_000534c0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  byte *param_3;
  undefined4 *param_4;
  undefined4 *param_5;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_48 [8];
  
  local_48[0] = DAT_001aa584;
  local_48[2] = DAT_001aa58c;
  local_48[1] = DAT_001aa588;
  iVar1 = *(int *)(((unsigned char *)0x00001168) + param_1);
  uVar2 = extvsCreateSymbol(param_1,iVar1 + 0x1c,0x87bf,local_48[*param_3],0x87e1,0,param_2,*param_4);
  *param_5 = uVar2;
  if (1 < param_2) {
    uVar3 = 1;
    do {
      uVar4 = uVar3 + 1;
      uVar2 = extvsCreateSymbol(param_1,iVar1 + 0x1c,0x87bf,local_48[param_3[uVar3]],0x87e1,*param_5,
                           param_2 - uVar3,param_4[uVar3]);
      param_5[uVar3] = uVar2;
      uVar3 = uVar4;
    } while (param_2 != uVar4);
  }
  return;
}

/* extvsShaderOp1Explicit @ 0x53610 (136 bytes) */
int extvsShaderOp1Explicit(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    extvsAppendInstruction(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,param_4,param_5,
                 param_6,0,&DAT_001db998,0,&DAT_001db998);
  }
  return;
}

/* extvsShaderOp2Explicit @ 0x536a0 (144 bytes) */
int extvsShaderOp2Explicit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    extvsAppendInstruction(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,param_4,param_5,
                 param_6,param_7,param_8,0,&DAT_001db998);
  }
  return;
}

/* extvsShaderOp3Explicit @ 0x53730 (132 bytes) */
int extvsShaderOp3Explicit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
{
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    extvsAppendInstruction(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,param_4,param_5,
                 param_6,param_7,param_8,param_9,param_10);
  }
  return;
}

/* glSwizzleEXT_impl @ 0x537c0 (276 bytes) */
int glSwizzleEXT_impl(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  uint param_6;
  uint param_7;
  uint param_8;
{
  int iVar1;
  int iVar2;
  int iStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  if (((((((unsigned char *)0x00001170)[param_1] != '\0') && (param_5 - 0x87d5U < 0xb)) && (0x87d4 < param_6)) &&
      ((param_6 < 0x87e0 && (0x87d4 < param_7)))) &&
     ((param_7 < 0x87e0 && ((0x87d4 < param_8 && (param_8 < 0x87e0)))))) {
    iVar2 = *(int *)(((unsigned char *)0x00001168) + param_1);
    iStack_38 = param_5;
    uStack_34 = param_6;
    uStack_30 = param_7;
    uStack_2c = param_8;
    iVar1 = extvsAppendInstruction(param_1,iVar2,0x879a,param_2,param_3,param_4,&iStack_38,0,&DAT_001db998,0,
                         &DAT_001db998);
    if ((iVar1 != 0) && (param_2 - 0x879dU < 0x10)) {
      *(undefined1 *)((param_2 - 0x879dU) + iVar2 + 0x44) = 1;
    }
  }
  return;
}

/* extvsBeginShader @ 0x538e0 (164 bytes) */
int extvsBeginShader(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (((unsigned char *)0x00001170)[param_1] == '\0') {
    uVar1 = *(undefined4 *)(((unsigned char *)0x00001168) + param_1);
    ((unsigned char *)0x00001170)[param_1] = 1;
    extvsFreeShaderObject(param_1,uVar1);
    extvsInitShaderObject(param_1,uVar1);
    *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = 0;
    *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = 0;
    if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 7;
    }
  }
  return;
}

/* extvsEndShader @ 0x53990 (244 bytes) */
int extvsEndShader(param_1)
  int param_1;
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int a1;
  
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    a1 = *(int *)(((unsigned char *)0x00001168) + param_1);
    ((unsigned char *)0x00001170)[param_1] = 0;
    extvsOptimizeProgram(param_1,a1);
    (**(code **)(((unsigned char *)0x00001190) + param_1))(param_1,a1);
    (**(code **)(((unsigned char *)0x00001194) + param_1))(param_1,a1);
    (**(code **)(((unsigned char *)0x0000119c) + param_1))
              (param_1,a1,in_r5,in_r6,in_r7,in_r8,*(code **)(((unsigned char *)0x0000119c) + param_1));
    *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = *(undefined4 *)(a1 + 0x54);
    *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = *(undefined4 *)(a1 + 0x58);
    *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = *(undefined4 *)(a1 + 0x5c);
    *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = *(undefined4 *)(a1 + 0x60);
    *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = *(undefined4 *)(a1 + 100);
    if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
      *(byte *)(param_1 + 0x2d) = *(byte *)(param_1 + 0x2d) | 7;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  return;
}

/* extvsFindShaderIndex @ 0x53a90 (100 bytes) */
int extvsFindShaderIndex(shaderTable, shaderId)
  int shaderTable;
  int shaderId;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(shaderTable + 4);
  if (iVar4 != 0) {
    if (shaderId == *(int *)(*(int *)(shaderTable + 0xc) + 8)) {
      return 0;
    }
    piVar3 = (int *)(*(int *)(shaderTable + 0xc) + 0x84);
    iVar2 = 0;
    while( true ) {
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) break;
      iVar1 = *piVar3;
      piVar3 = piVar3 + 0x1f;
      if (shaderId == iVar1) {
        return iVar2;
      }
    }
  }
  return -1;
}

/* extvsGetShaderById @ 0x53b00 (84 bytes) */
int extvsGetShaderById(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  iVar2 = ((int (*)())extvsFindShaderIndex)(iVar3,param_2);
  iVar1 = 0;
  if (-1 < iVar2) {
    iVar1 = iVar2 * 0x7c + *(int *)(iVar3 + 0xc);
  }
  return iVar1;
}

/* extvsBindShader @ 0x53b60 (568 bytes) */
int extvsBindShader(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar6 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  iVar2 = *(int *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0xc);
  if (iVar2 != 0) {
    *(int *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0xc) = iVar2 + -1;
  }
  if (((unsigned char *)0x00001170)[param_1] == '\0') {
    iVar2 = ((int (*)())extvsFindShaderIndex)(iVar6,param_2);
    if (iVar2 < 0) {
      uVar1 = *(uint *)(iVar6 + 4);
      if ((uVar1 & 0xf) == 0) {
        iVar2 = (**(code **)(param_1 + 0xc))(uVar1 * 0x7c + 0x7c0);
        if (iVar2 == 0) {
          return;
        }
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (iVar2,*(undefined4 *)(iVar6 + 0xc),*(int *)(iVar6 + 4) * 0x7c);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar6 + 0xc));
        *(int *)(iVar6 + 0xc) = iVar2;
        extvsRefreshBoundVertexPrograms(param_1);
        uVar1 = *(uint *)(iVar6 + 4);
      }
      extvsInitShaderObject(param_1,uVar1 * 0x7c + *(int *)(iVar6 + 0xc));
      *(undefined4 *)(*(int *)(iVar6 + 4) * 0x7c + *(int *)(iVar6 + 0xc) + 8) = param_2;
      *(undefined4 *)(((unsigned char *)0x00001188) + param_1) = *(undefined4 *)(iVar6 + 4);
      *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + 1;
      *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = 0;
    }
    else {
      iVar3 = *(int *)(iVar6 + 0xc);
      *(int *)(((unsigned char *)0x00001188) + param_1) = iVar2;
      iVar3 = iVar2 * 0x7c + iVar3;
      *(undefined4 *)(((unsigned char *)0x00001174) + param_1) = *(undefined4 *)(iVar3 + 0x54);
      *(undefined4 *)(((unsigned char *)0x0000117c) + param_1) = *(undefined4 *)(iVar3 + 0x58);
      *(undefined4 *)(((unsigned char *)0x00001178) + param_1) = *(undefined4 *)(iVar3 + 0x5c);
      *(undefined4 *)(((unsigned char *)0x00001180) + param_1) = *(undefined4 *)(iVar3 + 0x60);
      *(undefined4 *)(((unsigned char *)0x00001184) + param_1) = *(undefined4 *)(iVar3 + 100);
    }
    iVar2 = *(int *)(((unsigned char *)0x00001188) + param_1) * 0x7c + *(int *)(iVar6 + 0xc);
    *(int *)(((unsigned char *)0x00001168) + param_1) = iVar2;
    *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + 1;
    uVar1 = *(uint *)(param_1 + 0x44);
    if ((uVar1 & 0x800000) != 0) {
      uVar5 = *(uint *)(param_1 + 0x18a4);
      if ((uVar1 & 0x100000) == 0) {
        if ((((int)uVar1 < 0) &&
            (*(short *)(((unsigned char *)0x00002d48) + *(int *)(*(int *)(param_1 + 4) + 0x10)) == -0x7e06)) ||
           (uVar4 = 0, (uVar1 & 0x80800000) == 0x800000)) {
          uVar4 = 1;
        }
      }
      else {
        uVar4 = *(char *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0x6e) == '\0' ^ 1;
      }
      *(uint *)(param_1 + 0x18a4) = uVar4 << 2 | uVar5 & 0xfffffffb;
      if ((uVar5 >> 2 & 1) != uVar4) {
        *(undefined1 *)(param_1 + 0x29) = 1;
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
      }
    }
  }
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl noop_4c540");
asm(".set noop_4c540, _noop_4c540");
asm(".globl FUN_0004c560");
asm(".set FUN_0004c560, _FUN_0004c560");
asm(".globl FUN_0004c720");
asm(".set FUN_0004c720, _FUN_0004c720");
asm(".globl FUN_0004dbe0");
asm(".set FUN_0004dbe0, _FUN_0004dbe0");
asm(".globl FUN_0004de30");
asm(".set FUN_0004de30, _FUN_0004de30");

/* issue #75 (follow-up #3): Ghidra recognized this as a THUNK - a pure trampoline stub that
 * just branches straight to the real function below, no different behavior or arguments - but
 * decls.h declares "thunk_FUN_xxx" as its own separate extern function that nothing in this
 * corpus ever DEFINES a body for. The stock ld apparently tolerated the resulting undefined
 * reference (never actually called in a way that mattered, or silently resolved some other
 * way); ld64 leaves it a real unresolved lazy symbol, crashing the moment this call path is
 * first taken. Real fix: alias the thunk name directly onto the real function, so calling
 * "thunk_FUN_xxx" IS calling FUN_xxx - which is exactly what the original binary's trampoline
 * did. */
asm(".globl _thunk_FUN_00053b60");
asm(".set _thunk_FUN_00053b60, _extvsBindShader");
