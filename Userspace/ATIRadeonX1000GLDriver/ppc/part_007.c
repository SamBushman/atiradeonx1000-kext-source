#include "decls.h"

/* FUN_0004c260 @ 0x4c260 (732 bytes) */
int FUN_0004c260(param_1, param_2, param_3)
  undefined4 *param_1;
  int param_2;
  int param_3;
{
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
      *param_1 = ((unsigned char *)0x00001181);
      dataCacheBlockTouch(puVar9);
      uVar5 = *puVar11;
      param_1[2] = ((unsigned char *)0x00001189);
      param_1[1] = uVar5;
      uVar5 = puVar11[1];
      param_1[4] = ((unsigned char *)0x00001188);
      param_1[6] = ((unsigned char *)0x0000118c);
      param_1[5] = 0;
      param_1[3] = uVar5;
      uVar5 = puVar11[2];
      param_1[8] = ((unsigned char *)0x0000118d);
      param_1[7] = uVar5;
      uVar5 = puVar11[3];
      param_1[10] = ((unsigned char *)0x0000118e);
      param_1[0xb] = 0;
      param_1[0xc] = ((unsigned char *)0x000010c1);
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
      *puVar7 = ((unsigned char *)0x00001094);
      puVar7[2] = (iVar8 * 6 + -1) * 0x10000 | 0x9095;
      if (0 < iVar8) {
        iVar10 = 0;
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
          iVar10 = iVar10 + 1;
          param_1 = param_1 + 6;
          iVar14 = iVar14 + 0x18;
        } while (iVar8 != iVar10);
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
              *param_1 = ((unsigned char *)0x00001094);
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
        puVar12 = ((unsigned char *)0x00001300);
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

/* FUN_0004c540 @ 0x4c540 (4 bytes) */
int FUN_0004c540()
{
  return;
}

/* FUN_0004c560 @ 0x4c560 (440 bytes) */
int FUN_0004c560(param_1, param_2)
  int param_1;
  int param_2;
{
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
  
  iVar3 = *(int *)(param_1 + 0x1e68);
  if (iVar3 != param_2) {
    if (iVar3 != 0) {
      ((unsigned char *)0x000010e9)[iVar3] = 0;
      ((unsigned char *)0x000010ea)[*(int *)(param_1 + 0x1e68)] = 0;
      ((unsigned char *)0x000010eb)[*(int *)(param_1 + 0x1e68)] = 0;
    }
    ((unsigned char *)0x000010eb)[param_2] = 0;
    ((unsigned char *)0x000010e9)[param_2] = 0;
    ((unsigned char *)0x000010ea)[param_2] = 0;
  }
  *(int *)(param_1 + 0x1e68) = param_2;
  if ((iVar3 != param_2) && (*(int *)(((unsigned char *)0x000010d8) + param_2) != 0)) {
    ((int (*)())FUN_0004dc30)(param_1);
  }
  if (*(uint *)(param_1 + 0x23e0) == 0) {
    cVar1 = ((unsigned char *)0x000010e9)[param_2];
  }
  else {
    cVar1 = ((unsigned char *)0x000010ea)[param_2];
  }
  if ((cVar1 == '\0') || (((unsigned char *)0x000010eb)[param_2] == '\0')) {
    if ((*(uint *)(param_1 + 0x23e0) & 0xff) == 0) {
      iVar3 = *(int *)(((unsigned char *)0x000036a8) + param_2);
      puVar2 = ((unsigned char *)0x000010ec);
    }
    else {
      iVar3 = *(int *)(((unsigned char *)0x000036b4) + param_2);
      puVar2 = ((unsigned char *)0x00001318);
    }
    uVar4 = (**(code **)(param_1 + 0x2758))
                      (param_1,iVar3 * 6 + (*(uint *)(puVar2 + param_2 + 0x44) & 0xf) + 0x910);
    a2 = (uint)*(byte *)(param_1 + 0x23e3);
    *(undefined4 *)(0x00002748 + param_1 + 4) = uVar4;
    puVar5 = (undefined4 *)((int (*)())FUN_0004c260)(uVar4,param_2,a2);
    *puVar5 = 0x7101d;
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar5 + 1;
    iVar7 = 8;
    iVar3 = param_1;
    do {
      puVar6 = *(undefined4 **)(0x00002748 + param_1 + 4);
      puVar5 = (undefined4 *)(iVar3 + 0x1ee8);
      iVar3 = iVar3 + 4;
      *puVar6 = *puVar5;
      *(undefined4 **)(0x00002748 + param_1 + 4) = puVar6 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    puVar5 = puVar6 + 5;
    puVar6[1] = ((unsigned char *)0x000011ad);
    puVar6[2] = *(undefined4 *)(0x00002348 + param_1 + 4);
    puVar6[3] = ((unsigned char *)0x000010c0);
    puVar6[4] = *(undefined4 *)(param_1 + 0x1f2c);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar5;
    (**(code **)(param_1 + 0x275c))(param_1,puVar5,a2,in_r6,in_r7,in_r8,puVar5);
  }
  *(int *)(param_1 + 0x1e64) = param_2;
  return;
}

/* FUN_0004c720 @ 0x4c720 (1632 bytes) */
int FUN_0004c720(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  bool bVar1;
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
  undefined4 uVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  
  uVar15 = *(uint *)(param_1 + 0x44);
  uVar14 = *(uint *)(param_1 + 0x1b9c);
  if (((uVar15 & 0x20000) != 0) && (iVar6 = *(int *)(param_1 + 0x1e70), iVar6 != 0)) {
    if ((uVar15 & 0x2000) == 0) {
      cVar9 = ((unsigned char *)0x00001136)[param_1];
    }
    else {
      cVar9 = ((unsigned char *)0x000011d0)[param_1];
    }
    if (cVar9 == '\0') {
      uVar8 = (uint)(*(int *)(param_1 + 0x2768) == 0);
      goto LAB_0004c770;
    }
  }
  iVar6 = *(int *)(param_1 + 0x1e5c);
  uVar8 = 1;
LAB_0004c770:
  bVar1 = *(int *)(param_1 + 0x23e0) == 0;
  if (bVar1) {
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
    iVar6 = *(int *)(((unsigned char *)0x00001168) + param_1);
  }
  uVar15 = -(uint)(uVar15 & 0x82000 ^ 0x2000) >> 0x1f;
  if (((((param_2 != 0) || (iVar6 != 0)) || (uVar8 != *(uint *)(puVar7 + 0x228))) ||
      ((*(uint *)(puVar7 + 0x218) != uVar14 ||
       (*(int *)(puVar7 + 0x220) != *(int *)(param_1 + 0x1bb0))))) ||
     ((*(int *)(puVar7 + 0x21c) != *(int *)(param_1 + 0x1ba0) ||
      (uVar15 != *(uint *)(puVar7 + 0x224))))) {
    if ((bVar1) || (*(int *)(param_1 + 0x2768) == 0)) {
      uVar19 = *(uint *)(param_1 + 0x1ba0);
    }
    else {
      uVar19 = *(uint *)(param_1 + 0x1ba0) & ~(7 << (*(int *)(param_1 + 0x276c) * 3 & 0x3fU));
      *(uint *)(param_1 + 0x1ba0) = uVar19;
    }
    uVar11 = *(uint *)(puVar7 + 0x228);
    uVar17 = *(undefined4 *)(param_1 + 0x1bb0);
    *(uint *)(puVar7 + 0x218) = uVar14;
    *(uint *)(puVar7 + 0x21c) = uVar19;
    *(uint *)(puVar7 + 0x224) = uVar15;
    *(undefined4 *)(puVar7 + 0x220) = uVar17;
    iVar18 = (uVar14 >> 1 & 1) + (uVar14 >> 2 & 1) + (uVar14 >> 3 & 1) + (uVar14 >> 4 & 1);
    *(uint *)(puVar7 + 0x228) = uVar8 << 0x1f | uVar11 & 0x7fffffff;
    uVar14 = (uint)(iVar6 != 0) * 0x40000000 |
             (uint)(*(int *)(param_1 + 0x2768) != 0) * 0x20000000 |
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
        iVar12 = *(int *)(param_1 + 0x276c);
        cVar9 = (char)uVar8;
        if (iVar12 == iVar6) {
          uVar11 = 0x3e;
          *(uint *)(puVar10 + 8) =
               (cVar9 + 1) * 0x40 & 0xfc0U | uVar8 & 0x3f | *(uint *)(puVar10 + 8) & 0xfffff000;
          if (2 < *(int *)(puVar7 + 0x210)) {
            uVar11 = (int)cVar9 + 2U & 0x3f;
          }
          *(uint *)(puVar7 + iVar12 * 4 + 200) =
               uVar11 << 0xc | *(uint *)(puVar7 + iVar12 * 4 + 200) & 0xff000fff | 0xfc0000;
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
      if ((*(int *)(param_1 + 0x23e0) == 0) || (*(int *)(param_1 + 0x2768) == 0)) {
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
          iVar12 = *(int *)(param_1 + 0x276c);
          cVar9 = (char)uVar8;
          if (iVar12 == iVar6) {
            uVar11 = 0x3e;
            *(uint *)(puVar10 + 8) =
                 (cVar9 + 1) * 0x40 & 0xfc0U | uVar8 & 0x3f | *(uint *)(puVar10 + 8) & 0xfffff000;
            if (2 < *(int *)(puVar7 + 0x210)) {
              uVar11 = (int)cVar9 + 2U & 0x3f;
            }
            *(uint *)(puVar7 + iVar12 * 4 + 200) =
                 uVar11 << 0xc | *(uint *)(puVar7 + iVar12 * 4 + 200) & 0xff000fff | 0xfc0000;
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
    else if (*(int *)(param_1 + 0x23e0) == 0) {
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
      iVar20 = 0;
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
        if (*(int *)(param_1 + 0x276c) == iVar20) {
          if (*(int *)(puVar7 + 0x210) == 2) {
            *(uint *)(puVar10 + 8) = *(uint *)(puVar10 + 8) & 0xfffc0fff | 0x3e000;
          }
          *(uint *)(puVar10 + 8) = *(uint *)(puVar10 + 8) & 0xff03ffff | 0xfc0000;
          uVar8 = uVar8 + *(int *)(puVar7 + 0x210);
        }
        iVar20 = iVar20 + 1;
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
    *(uint *)(param_1 + 0x1f2c) = uVar14;
    *(undefined4 *)(param_1 + 0x1ee8) = *(undefined4 *)(puVar7 + 200);
    *(undefined4 *)(param_1 + 0x1eec) = *(undefined4 *)(puVar7 + 0xcc);
    *(undefined4 *)(param_1 + 0x1ef0) = *(undefined4 *)(puVar7 + 0xd0);
    *(undefined4 *)(param_1 + 0x1ef4) = *(undefined4 *)(puVar7 + 0xd4);
    *(undefined4 *)(param_1 + 0x1ef8) = *(undefined4 *)(puVar7 + 0xd8);
    *(undefined4 *)(param_1 + 0x1efc) = *(undefined4 *)(puVar7 + 0xdc);
    *(undefined4 *)(param_1 + 0x1f00) = *(undefined4 *)(puVar7 + 0xe0);
    uVar5 = *(undefined4 *)(puVar7 + 0xe4);
    *(uint *)(param_1 + 0x1ba4) = uVar19;
    *(undefined4 *)(param_1 + 0x1bb4) = uVar17;
    *(undefined4 *)(param_1 + 0x1f04) = uVar5;
    if ((*(uint *)(param_1 + 0x44) & 0x20000000) != 0) {
      *(undefined4 *)(param_1 + 0x277c) = 0xffffffff;
    }
  }
  return;
}

/* FUN_0004cde0 @ 0x4cde0 (72 bytes) */
int FUN_0004cde0(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x10) != 0) {
    _free(*(int *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}

/* FUN_0004ce30 @ 0x4ce30 (680 bytes) */
int FUN_0004ce30(param_1)
  int param_1;
{
  short sVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  iVar4 = *(int *)(param_1 + 4);
  uVar7 = *(uint *)(param_1 + 0x1ae0);
  iVar6 = *(int *)(param_1 + 0x1ab0);
  iVar9 = *(int *)(iVar4 + 0x10);
  sVar1 = *(short *)(((unsigned char *)0x00002dc4) + iVar9);
  iVar8 = iVar4 + 0x30;
  if (*(int *)(iVar4 + 0x150) != 0) {
    iVar8 = *(int *)(iVar4 + 0x150);
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
     ((*(uint *)(param_1 + 0x44) & 0x200) == 0)) {
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
        uVar5 = *(uint *)(param_1 + 0x1ae0) | 3;
        *(uint *)(param_1 + 0x1ae0) = uVar5;
        *(uint *)(param_1 + 0x1ab0) = *(uint *)(param_1 + 0x1ab0) | 3;
      }
      else if (iVar4 == 0x207) {
        uVar5 = *(uint *)(param_1 + 0x1ae0) & 0xfffffffe;
        *(uint *)(param_1 + 0x1ae0) = uVar5;
        *(uint *)(param_1 + 0x1ab0) = *(uint *)(param_1 + 0x1ab0) | 1;
      }
      else {
        uVar5 = *(uint *)(param_1 + 0x1ae0) & 0xfffffffd | 1;
        *(uint *)(param_1 + 0x1ae0) = uVar5;
        *(uint *)(param_1 + 0x1ab0) = *(uint *)(param_1 + 0x1ab0) & 0xfffffffd | 1;
      }
      *(byte *)(iVar8 + 0xc6) = (byte)((uVar5 ^ 2) >> 1) & 1;
      if (bVar3) {
        *(undefined1 *)(iVar8 + 0xc4) = 0;
        uVar5 = *(uint *)(param_1 + 0x1ae0);
      }
      else {
        uVar5 = *(uint *)(param_1 + 0x1ae0);
      }
      goto LAB_0004d0d0;
    }
  }
  uVar5 = *(uint *)(param_1 + 0x1ae0) & 0xfffffffe;
  *(uint *)(param_1 + 0x1ae0) = uVar5;
  *(uint *)(param_1 + 0x1ab0) = *(uint *)(param_1 + 0x1ab0) & 0xfffffffe;
  if (bVar3) {
    *(undefined1 *)(iVar8 + 0xc5) = 1;
    uVar5 = *(uint *)(param_1 + 0x1ae0);
  }
LAB_0004d0d0:
  if ((uVar7 == uVar5) && (iVar6 == *(int *)(param_1 + 0x1ab0))) {
    return;
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x1000;
  return;
}

/* FUN_0004d100 @ 0x4d100 (1264 bytes) */
int FUN_0004d100(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  uint in_r5;
  uint in_r6;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  char cVar10;
  uint uVar9;
  uint uVar11;
  
  uVar3 = *(uint *)(param_1 + 0x1a4c);
  iVar4 = *(int *)(param_1 + 0x1e5c);
  iVar6 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((((*(uint *)(param_1 + 0x1a80) & 1) == 0) || ((*(uint *)(param_1 + 0x1aa0) & 6) == 6)) ||
     (*(char *)(param_1 + 0x23ed) != '\0')) {
    cVar10 = ((unsigned char *)0x00002d66)[iVar6];
    goto LAB_0004d234;
  }
  if (((unsigned char *)0x00002d66)[iVar6] == '\0') {
    cVar10 = '\0';
    if (((*(short *)(((unsigned char *)0x00002d80) + iVar6) != -0x7ffa) ||
        (*(int *)(((unsigned char *)0x00002d68) + iVar6) != *(int *)(((unsigned char *)0x00002d6c) + iVar6))) ||
       (((unsigned char *)0x00002b7e)[*(int *)(param_1 + 4)] != '\0')) {
LAB_0004d234:
      if (cVar10 != '\0') goto LAB_0004d240;
      goto LAB_0004d260;
    }
    in_r5 = (uint)*(ushort *)(((unsigned char *)0x00002d68) + iVar6);
    in_r6 = (uint)*(ushort *)(((unsigned char *)0x00002d6a) + iVar6);
    bVar1 = (*(uint *)(param_1 + 0x8c) & 0x400000) == 0;
    if (((bVar1) || (*(char *)(param_1 + 0x2450) == '\0')) ||
       (bVar2 = true, (int)*(uint *)(param_1 + 0x8c) < 0)) {
      bVar2 = false;
    }
    if (((bVar1) || (in_r5 != 0x302)) || (bVar1 = false, in_r6 != 0x303)) {
      if (bVar2) {
        if (in_r5 == 0) {
          if (in_r6 == 0x301) {
LAB_0004d20c:
            if ((*(int *)(((unsigned char *)0x00001098) + iVar4) == 1) &&
               (bVar1 = true, *(double *)(0x00001830 + iVar6) != *(double *)(iVar6 + 0x1838)))
            goto LAB_0004d5c4;
          }
        }
        else if (((in_r5 == 1) || (in_r5 == 0x306)) && (in_r6 == 1)) goto LAB_0004d20c;
      }
      goto LAB_0004d234;
    }
LAB_0004d5c4:
    *(uint *)(param_1 + 0x1a4c) = *(uint *)(param_1 + 0x1a4c) | 0x800;
    *(undefined1 *)(param_1 + 0x1a4f) = 0;
    uVar7 = *(uint *)(param_1 + 0x1a4c) & 0xfffff8ff | 0x400;
    *(uint *)(param_1 + 0x1a4c) = uVar7;
  }
  else {
LAB_0004d240:
    if (*(short *)(((unsigned char *)0x00002d64) + iVar6) == 0x207) {
LAB_0004d260:
      bVar1 = false;
      uVar7 = *(uint *)(param_1 + 0x1a4c) & 0xfffff7ff;
      *(uint *)(param_1 + 0x1a4c) = uVar7;
    }
    else {
      bVar1 = false;
      uVar7 = *(uint *)(param_1 + 0x1a4c) | 0x800;
      *(uint *)(param_1 + 0x1a4c) = uVar7;
    }
  }
  if (uVar3 != uVar7) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x200;
  }
  if (bVar1) {
    *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) | 0x10;
    if ((*(uint *)(((unsigned char *)0x00001544) + iVar4) & 0x10) == 0) {
LAB_0004d2c8:
      FUN_000b6580(param_1,0);
      (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,0);
      (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
    }
  }
  else {
    *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) & 0xffffffef;
    if ((*(uint *)(((unsigned char *)0x00001544) + iVar4) & 0x10) != 0) goto LAB_0004d2c8;
  }
  ((int (*)())FUN_0004ce30)(param_1);
  uVar5 = *(uint *)(param_1 + 0x1aa0);
  uVar11 = *(uint *)(param_1 + 0x1ab8);
  iVar4 = *(int *)(param_1 + 4);
  uVar7 = uVar11 | 1;
  *(uint *)(param_1 + 0x1ab8) = uVar7;
  if ((((uVar5 & 6) != 6) && (((unsigned char *)0x00002b7e)[iVar4] == '\0')) &&
     (*(char *)(param_1 + 0x23ed) == '\0')) {
    uVar8 = *(uint *)(param_1 + 0x1a4c);
    uVar9 = *(uint *)(param_1 + 0x44);
    goto LAB_0004d460;
  }
  uVar8 = *(uint *)(param_1 + 0x1a4c);
  if ((uVar8 & 0x800) == 0) {
    uVar9 = *(uint *)(param_1 + 0x44);
    if ((uVar9 & 0x60020000) != 0x40000000) {
      if ((((unsigned char *)0x00002e2d)[*(int *)(iVar4 + 0x10)] != '\0') && ((uVar9 & 0x20000) == 0)) {
        iVar4 = FUN_0001a010(iVar4,*(undefined4 *)(iVar4 + 0x26a0),in_r5,in_r6,uVar3,uVar5,uVar8);
        if (iVar4 == 0) {
          uVar5 = *(uint *)(param_1 + 0x1aa0);
          uVar8 = *(uint *)(param_1 + 0x1a4c);
          uVar7 = *(uint *)(param_1 + 0x1ab8);
          goto LAB_0004d440;
        }
        iVar4 = *(int *)(param_1 + 4);
        uVar5 = *(uint *)(param_1 + 0x1aa0);
        uVar8 = *(uint *)(param_1 + 0x1a4c);
        uVar7 = *(uint *)(param_1 + 0x1ab8);
        uVar9 = *(uint *)(param_1 + 0x44);
      }
      iVar4 = *(int *)(iVar4 + 0x10);
      if (((((((unsigned char *)0x00002e2c)[iVar4] == '\0') || ((uVar9 & 0x20000) != 0)) ||
           (*(short *)(((unsigned char *)0x00002e28) + iVar4) == -1)) &&
          (((((unsigned char *)0x00003178)[iVar4] == '\0' || ((uVar9 & 0x20000) != 0)) ||
           ((*(short *)(((unsigned char *)0x00003170) + iVar4) != 0x1b02 &&
            (*(short *)(((unsigned char *)0x00003172) + iVar4) != 0x1b02)))))) &&
         (((uVar8 & 0x10000) == 0 && ((uVar9 & 0x2000100) == 0)))) goto LAB_0004d460;
    }
  }
  else {
LAB_0004d440:
    uVar9 = *(uint *)(param_1 + 0x44);
  }
  uVar7 = uVar7 & 0xfffffffe;
  *(uint *)(param_1 + 0x1ab8) = uVar7;
LAB_0004d460:
  if ((((uVar8 & 0x800) != 0) && (*(int *)(param_1 + 0x27b0) == 1)) &&
     (uVar8 = *(uint *)(param_1 + 0x8c) & 0x400000, uVar8 != 0)) {
    uVar7 = uVar7 & 0xfffffffe;
    *(uint *)(param_1 + 0x1ab8) = uVar7;
  }
  if (((uVar5 & 2) != 0) && ((uVar9 >> 9 & 1) != 0)) {
    uVar7 = uVar7 & 0xfffffffe;
    *(uint *)(param_1 + 0x1ab8) = uVar7;
  }
  if (uVar11 != uVar7) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x20000;
  }
  if (*(int *)(param_1 + 0x23dc) != 1) {
    uVar7 = *(uint *)(param_1 + 0x1bd4);
    uVar11 = *(uint *)(param_1 + 0x1aa4);
    iVar4 = FUN_0001a010(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 0x2460),in_r5,in_r6,
                         uVar3,uVar5,uVar8);
    if (iVar4 == 0) {
      if ((*(uint *)(param_1 + 0x1ab8) & 1) == 0) {
        uVar3 = *(uint *)(param_1 + 0x1bd4) & 0xfffffffe;
        *(uint *)(param_1 + 0x1bd4) = uVar3;
        *(uint *)(param_1 + 0x1aa4) = *(uint *)(param_1 + 0x1aa4) & 0xf7ffffff;
      }
      else {
        iVar4 = *(int *)(0x00001af4 + param_1);
        uVar3 = *(uint *)(param_1 + 0x1bd4) | 1;
        *(uint *)(param_1 + 0x1bd4) = uVar3;
        if (iVar4 == 0) {
          *(uint *)(param_1 + 0x1aa4) = *(uint *)(param_1 + 0x1aa4) | 0x8000000;
        }
        else {
          *(uint *)(param_1 + 0x1aa4) = *(uint *)(param_1 + 0x1aa4) & 0xf7ffffff;
        }
      }
    }
    else {
      uVar3 = *(uint *)(param_1 + 0x1bd4);
      if ((uVar3 & 1) != 0) {
        uVar3 = uVar3 & 0xfffffffe;
        *(uint *)(param_1 + 0x1bd4) = uVar3;
        *(uint *)(param_1 + 0x1aa4) = *(uint *)(param_1 + 0x1aa4) & 0xf7ffffff;
      }
    }
    if (((uVar7 & 1) != (uVar3 & 1)) ||
       ((uVar11 >> 0x1b & 1) != (*(uint *)(param_1 + 0x1aa4) >> 0x1b & 1))) {
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x20800;
    }
  }
  return;
}

/* FUN_0004d620 @ 0x4d620 (328 bytes) */
void FUN_0004d620(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1)
{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = *(uint *)(param_1 + 0x44);
  if ((uVar4 & 0x20000) == 0) {
    FUN_000b6580(param_1,0);
                    
                    
    (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
    return;
  }
  if ((uVar4 & 0x2000) != 0) {
    ((undefined4 (*)())FUN_000afe40)(param_1,0,param_3,param_4,fparam_1);
    return;
  }
  if ((uVar4 & 0x80100000) == 0x80000000) {
    if (*(short *)("}J3x})+x|B;x}k" + *(int *)(*(int *)(param_1 + 4) + 0x10)) == -0x7e06)
    goto LAB_0004d6ac;
  }
  else if ((uVar4 & 0x800000) != 0) {
LAB_0004d6ac:
    cVar2 = '\x01';
    goto LAB_0004d6b0;
  }
  cVar2 = '\0';
LAB_0004d6b0:
  iVar5 = *(int *)(((unsigned char *)0x00001154) + param_1);
  if (*(int *)(iVar5 + 4) != 0) {
    uVar4 = 0;
    iVar3 = 0;
    do {
      iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 +
                      *(int *)(iVar3 + *(int *)(iVar5 + 0x88) + 0x70));
      if ((iVar1 != 0) && (((unsigned char *)0x0000120c)[iVar1] != cVar2)) {
        *(undefined4 *)(((unsigned char *)0x000016f0) + iVar1) = 1;
        *(undefined1 *)(iVar1 + 0x119) = 1;
        iVar5 = *(int *)(((unsigned char *)0x00001154) + param_1);
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0x78;
    } while (uVar4 < *(uint *)(iVar5 + 4));
  }
  FUN_000b3630(param_1);
  return;
}

/* FUN_0004d770 @ 0x4d770 (840 bytes) */
void FUN_0004d770(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  
  dVar6 = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa10c;
  iVar8 = *(int *)(param_1 + 4);
  iVar10 = *(int *)(param_1 + 0x1c9c);
  iVar9 = *(int *)(param_1 + 0x1c98);
  iVar13 = *(int *)(param_1 + 0x1c88);
  iVar12 = *(int *)(param_1 + 0x1c94);
  iVar11 = *(int *)(param_1 + 0x1c90);
  iVar15 = *(int *)(param_1 + 0x1c8c);
  iVar16 = *(int *)(iVar8 + 0x10);
  fVar1 = *(float *)(iVar8 + 0x2a58);
  fVar2 = *(float *)(iVar8 + 0x2a54);
  *(undefined4 *)(param_1 + 0x1c9c) = *(undefined4 *)(iVar16 + 0x1818);
  *(undefined4 *)(param_1 + 0x1c98) = *(undefined4 *)(iVar16 + 0x1828);
  uVar7 = *(uint *)(iVar16 + 0x1840);
  fVar3 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar16 + 0x184c) ^ 0x80000000) -
                         dVar6) * fVar4;
  fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar16 + 0x1844) ^ 0x80000000) -
                         dVar6) + fVar3;
  fVar4 = fVar2 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar16 + 0x1848) ^ 0x80000000) -
                         dVar6) * fVar4;
  if (*(char *)(param_1 + 0x293c) != '\0') {
    fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar8 + 0x160) ^ 0x80000000) -
                           dVar6) - fVar5;
    fVar3 = -fVar3;
  }
  *(float *)(param_1 + 0x1c8c) = fVar4;
  *(float *)(param_1 + 0x1c88) =
       fVar2 * (float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - dVar6) + fVar4;
  *(float *)(param_1 + 0x1c94) = fVar3;
  *(float *)(param_1 + 0x1c90) = fVar5;
  if (*(char *)(param_1 + 0x124) != '\0') {
    *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
    *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  }
  *(undefined4 *)(param_1 + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cb0) = 0x3f800000;
  if (((((iVar15 != *(int *)(param_1 + 0x1c8c)) || (iVar13 != *(int *)(param_1 + 0x1c88))) ||
       (iVar12 != *(int *)(param_1 + 0x1c94))) ||
      ((iVar11 != *(int *)(param_1 + 0x1c90) || (iVar10 != *(int *)(param_1 + 0x1c9c))))) ||
     (iVar9 != *(int *)(param_1 + 0x1c98))) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x80;
  }
  uVar14 = *(uint *)(0x00001b14 + param_1);
  uVar7 = uVar14 & 0xfffffff8;
  *(uint *)(0x00001b14 + param_1) = uVar7;
  if ((((*(uint *)((*(unsigned char *)0x0000317c) + iVar16) & 0xffff0000) != 0) || (((unsigned char *)0x0000317b)[iVar16] != '\0'))
     && ((*(float *)(((unsigned char *)0x0000316c) + iVar16) != FLOAT_001aa0d4 ||
         (*(float *)(((unsigned char *)0x00003168) + iVar16) != FLOAT_001aa0d4)))) {
    if (((unsigned char *)0x0000317b)[iVar16] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + iVar16) == 0x1b00) {
        uVar7 = uVar7 | 1;
        *(uint *)(0x00001b14 + param_1) = uVar7;
      }
      if (*(short *)(((unsigned char *)0x00003172) + iVar16) == 0x1b00) {
        uVar7 = uVar7 | 2;
        *(uint *)(0x00001b14 + param_1) = uVar7;
      }
    }
    if (((unsigned char *)0x0000317c)[iVar16] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + iVar16) == 0x1b01) {
        uVar7 = uVar7 | 1;
        *(uint *)(0x00001b14 + param_1) = uVar7;
      }
      if (*(short *)(((unsigned char *)0x00003172) + iVar16) == 0x1b01) {
        uVar7 = uVar7 | 2;
        *(uint *)(0x00001b14 + param_1) = uVar7;
      }
    }
    if (((unsigned char *)0x0000317d)[iVar16] != '\0') {
      if (*(short *)(((unsigned char *)0x00003170) + iVar16) == 0x1b02) {
        uVar7 = uVar7 | 1;
        *(uint *)(0x00001b14 + param_1) = uVar7;
      }
      if (*(short *)(((unsigned char *)0x00003172) + iVar16) == 0x1b02) {
        uVar7 = uVar7 | 2;
        *(uint *)(0x00001b14 + param_1) = uVar7;
      }
    }
    fVar1 = (float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_1 + 8)) - DOUBLE_001aa250) *
            *(float *)(((unsigned char *)0x00003168) + iVar16);
    fVar2 = FLOAT_001aa104;
    if ((*(uint *)(*(int *)(param_1 + 4) + 0x154) & 0x30000) == 0x10000) {
      fVar2 = FLOAT_001aa164;
    }
    fVar3 = *(float *)(((unsigned char *)0x0000316c) + iVar16);
    *(float *)(param_1 + 0x1b24) = fVar1;
    *(float *)(param_1 + 0x1b1c) = fVar1;
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x20;
    *(float *)(param_1 + 0x1b20) = fVar2 * fVar3;
    *(float *)(param_1 + 0x1b18) = fVar2 * fVar3;
  }
  if (uVar14 != uVar7) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x20;
  }
  return;
}

/* FUN_0004dac0 @ 0x4dac0 (272 bytes) */
int FUN_0004dac0(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((((unsigned char *)0x00002dc8)[iVar1] == '\0') || (((unsigned char *)0x00001490)[param_1] == '\0')) {
    uVar2 = *(uint *)(param_1 + 0x1930);
    *(uint *)(param_1 + 0x1aa0) = *(uint *)(param_1 + 0x1aa0) & 0xfffffffd;
  }
  else {
    uVar4 = (uint)*(ushort *)(((unsigned char *)0x00002dc4) + iVar1);
    uVar3 = *(uint *)(param_1 + 0x1aa0);
    uVar2 = *(uint *)(param_1 + 0x1a50);
    *(uint *)(param_1 + 0x1aa0) = uVar3 | 2;
    if ((uVar4 == 0x202) ||
       (((uVar4 == 0x203 && (*(double *)(0x00001830 + iVar1) == DOUBLE_001aa200)) &&
        (*(double *)(iVar1 + 0x1838) == DOUBLE_001aa200)))) {
      *(uint *)(param_1 + 0x1aa0) = uVar3 & 0xfffffffb | 2;
    }
    else {
      *(uint *)(param_1 + 0x1aa0) = ((byte)((unsigned char *)0x00002e44)[iVar1] & 1) << 2 | uVar3 & 0xfffffffb | 2
      ;
    }
    *(uint *)(param_1 + 0x1aa4) =
         *(uint *)(&DAT_001db368 + (uVar4 & 7) * 4) & 7 | *(uint *)(param_1 + 0x1aa4) & 0xfffffff8;
    if ((*(uint *)(param_1 + 0x44) & 0x200) == 0) {
      uVar3 = uVar2 & 0xfffffffe;
      *(uint *)(param_1 + 0x1a50) = uVar3;
    }
    else {
      uVar3 = uVar2 | 1;
      *(uint *)(param_1 + 0x1a50) = uVar3;
    }
    if (uVar2 == uVar3) {
      uVar2 = *(uint *)(param_1 + 0x1930);
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x1930) | 0x8000000;
      *(uint *)(param_1 + 0x1930) = uVar2;
    }
  }
  *(uint *)(param_1 + 0x1930) = uVar2 | 0x800;
  return;
}

/* FUN_0004dbe0 @ 0x4dbe0 (76 bytes) */
int FUN_0004dbe0(param_1)
  int param_1;
{
  if (*(char *)(param_1 + 0x124) != '\0') {
    FUN_00083110(param_1);
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000;
  return;
}

/* FUN_0004dc30 @ 0x4dc30 (220 bytes) */
int FUN_0004dc30(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if ((*(uint *)(param_1 + 0x44) & 0x20000) != 0) {
    return;
  }
  uVar6 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  if ((uint)*(byte *)(param_1 + 0x2b) <= (uint)(byte)((unsigned char *)0x000013b2)[param_1]) {
    uVar6 = (uint)*(byte *)(param_1 + 0x2b);
  }
  if (uVar6 != 0) {
    uVar2 = 0;
    iVar3 = param_1;
    iVar5 = param_1;
    do {
      *(undefined4 *)(iVar5 + 0x1f38) = *(undefined4 *)(iVar3 + 0x47c);
      *(undefined4 *)(iVar5 + 0x1f3c) = *(undefined4 *)(iVar3 + 0x480);
      *(undefined4 *)(iVar5 + 8000) = *(undefined4 *)(iVar3 + 0x484);
      *(undefined4 *)(iVar5 + 0x1f44) = *(undefined4 *)(iVar3 + 0x488);
      iVar4 = *(int *)(param_1 + 0x1e68);
      if (iVar4 != 0) {
        if ((1 << (uVar2 & 0x3f) & *(uint *)(((unsigned char *)0x000010d8) + iVar4)) != 0) {
          iVar1 = uVar2 * 0x10;
          *(undefined4 *)(iVar1 + iVar4 + 0x8c) = *(undefined4 *)(iVar5 + 0x1f38);
          *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x1e68) + 0x90) =
               *(undefined4 *)(iVar5 + 0x1f3c);
          *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x1e68) + 0x94) = *(undefined4 *)(iVar5 + 8000)
          ;
          *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x1e68) + 0x98) =
               *(undefined4 *)(iVar5 + 0x1f44);
        }
      }
      uVar2 = uVar2 + 1;
      iVar3 = iVar3 + 0xcc;
      iVar5 = iVar5 + 0x10;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x4000000;
  return;
}

/* FUN_0004dd10 @ 0x4dd10 (40 bytes) */
int FUN_0004dd10(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  *param_2 = 0x110f8;
  param_2[1] = *(undefined4 *)(param_1 + 7000);
  param_2[2] = *(undefined4 *)(param_1 + 0x1b10);
  return param_2 + 3;
}

/* FUN_0004dd40 @ 0x4dd40 (116 bytes) */
int FUN_0004dd40(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  
  *param_2 = 0x50766;
  param_2[1] = *(undefined4 *)(param_1 + 0x1c8c);
  param_2[2] = *(undefined4 *)(param_1 + 0x1c88);
  param_2[3] = *(undefined4 *)(param_1 + 0x1c94);
  param_2[4] = *(undefined4 *)(param_1 + 0x1c90);
  param_2[5] = *(undefined4 *)(param_1 + 0x1c9c);
  uVar1 = *(undefined4 *)(param_1 + 0x1c98);
  param_2[7] = 0x30888;
  param_2[6] = uVar1;
  param_2[8] = *(undefined4 *)(param_1 + 0x1ca8);
  param_2[9] = *(undefined4 *)(param_1 + 0x1cac);
  param_2[10] = *(undefined4 *)(param_1 + 0x1cb0);
  param_2[0xb] = *(undefined4 *)(param_1 + 0x1cb4);
  return param_2 + 0xc;
}

/* FUN_0004ddc0 @ 0x4ddc0 (104 bytes) */
int FUN_0004ddc0(param_1)
  int param_1;
{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar1;
  puVar1[1] = 0;
  *puVar1 = ((unsigned char *)0x00001040);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(0x00002748 + param_1 + 4) = *(int *)(0x00002748 + param_1 + 4) + 8;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

/* FUN_0004de30 @ 0x4de30 (180 bytes) */
int FUN_0004de30(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
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
    if (((*(uint *)(param_1 + 0x44) & 0x20000) == 0) ||
       (iVar2 = *(int *)(param_1 + 0x1e70), iVar2 == 0)) {
      iVar2 = *(int *)(param_1 + 0x1e5c);
    }
  }
  else {
    iVar2 = param_2 + 0x124;
  }
  if (0 < param_6) {
    pcVar3 = (*(unsigned char *)0x00002ddc) + param_4 + iVar2;
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
double FUN_0004def0(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
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
  int iVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  double extraout_f1;
  double in_stack_ffffff28;
  
  uVar4 = *(ushort *)(param_1 + 0x32) | *(ushort *)(param_1 + 0x34);
  uVar20 = (uint)uVar4;
  if ((uVar4 != 0) && (*(char *)(param_1 + 0x121) != '\0')) {
    uVar9 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar9 == 0) {
LAB_0004df78:
      *(undefined1 *)(param_1 + 0x120) = 0xff;
    }
    else {
      uVar26 = 0;
      if (*(int *)(param_1 + 0x48) != 0) {
        uVar26 = 0;
        iVar17 = param_1;
        do {
          uVar26 = uVar26 + 1;
          uVar9 = uVar9 - 1;
          if (uVar9 == 0) goto LAB_0004df78;
          piVar1 = (int *)(iVar17 + 0x4c);
          iVar17 = iVar17 + 4;
        } while (*piVar1 != 0);
        uVar26 = uVar26 & 0xff;
      }
      *(char *)(param_1 + 0x120) = (char)uVar26;
      *(uint *)(param_1 + 0x1878) = (uVar26 & 7) << 0x15 | *(uint *)(param_1 + 0x1878) & 0xff1fffff;
      *(uint *)(param_1 + 0x18a4) = (uVar26 & 7) << 0x1a | *(uint *)(param_1 + 0x18a4) & 0xe3ffffff;
    }
  }
  iVar17 = *(int *)(param_1 + 0x27b4);
  iVar21 = *(int *)(param_1 + 0x1808);
  uVar9 = *(uint *)(param_1 + 0x27b0) & ~(iVar17 << 8);
  *(uint *)(param_1 + 0x27b0) = uVar9;
  dVar7 = DOUBLE_001aa1e0;
  if (uVar4 != 0) {
    iVar10 = param_1 + 0x28b4;
    uVar26 = 0;
    uVar9 = 0;
    iVar25 = param_1 + 0x20;
    iVar17 = param_1;
    iVar22 = param_1;
    iVar23 = param_1;
    iVar24 = param_1;
    iVar27 = param_1;
    do {
      if ((uVar20 & 1) != 0) {
        if (iVar21 == 0) {
          iVar18 = *(int *)(((unsigned char *)0x000013f8) + iVar22);
          if (iVar18 == 0) {
            *(uint *)(param_1 + 0x27b0) = *(uint *)(param_1 + 0x27b0) & ~(1 << (uVar26 & 0x3f));
          }
          else {
            uVar11 = 1 << (uVar26 & 0x3f);
            *(uint *)(param_1 + 0x1934) = uVar11 | *(uint *)(param_1 + 0x1934);
            *(uint *)(param_1 + 0x27b0) = uVar11 | *(uint *)(param_1 + 0x27b0);
            *(undefined4 *)(iVar27 + 0x1d5c) = *(undefined4 *)(iVar18 + 0x1c);
            *(undefined4 *)(iVar27 + 0x1d9c) = *(undefined4 *)(iVar18 + 0x20);
            *(undefined4 *)(iVar27 + 0x1ddc) = *(undefined4 *)(iVar18 + 0x24);
            *(undefined4 *)(iVar25 + 0x1dfc) = *(undefined4 *)(iVar18 + 0x28);
            *(uint *)(iVar27 + 0x1cdc) = uVar9 << 0x1c | *(uint *)(iVar18 + 0x14) & 0xfffffff;
            *(uint *)(iVar27 + 0x1d1c) =
                 (*(ushort *)(iVar24 + 0x46e) & 0x3ff) << 3 | *(uint *)(iVar18 + 0x18) & 0xffffe007;
            param_4 = *(undefined4 *)(&DAT_001db98c + (uint)*(byte *)(param_1 + 0x2941) * 4);
            param_3 = uVar26;
            fparam_1 = (double)((double (*)())FUN_000b6f20)(param_1,iVar18,uVar26,param_4,fparam_1,fparam_2,fparam_3
                                            ,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                                            in_stack_ffffff28);
          }
        }
        else {
          uVar11 = 1 << (uVar26 & 0x3f);
          *(uint *)(param_1 + 0x1934) = uVar11 | *(uint *)(param_1 + 0x1934);
          if ((uVar26 == *(uint *)(param_1 + 0x276c)) && (*(int *)(param_1 + 0x2768) != 0)) {
            iVar18 = *(int *)(*(int *)(param_1 + 0x2768) + 0xbc);
          }
          else {
            iVar18 = *(int *)(((unsigned char *)0x000013f8) + iVar22);
            if (iVar18 == 0) {
              *(uint *)(param_1 + 0x27b0) = ~uVar11 & *(uint *)(param_1 + 0x27b0);
              *(uint *)(param_1 + 0x27b4) = ~uVar11 & *(uint *)(param_1 + 0x27b4);
              goto LAB_0004e760;
            }
          }
          if ((*(uint *)(param_1 + 0x44) & 0x20000) == 0) {
            if (((int)(uint)*(byte *)(param_1 + 0x20) >> (uVar26 & 0x3f) & 1U) == 0) {
              bVar6 = false;
              iVar16 = uVar26 << 2;
              *(uint *)(param_1 + 0x27b4) = *(uint *)(param_1 + 0x27b4) & ~uVar11;
            }
            else {
              iVar16 = uVar26 * 0x10;
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
              iVar16 = uVar26 << 2;
              fparam_1 = (double)((int (*)())FUN_0004de30)(param_1,0,uVar26 + 0x14,uVar26 + 0x14,iVar15,1);
              bVar6 = false;
              *(uint *)(param_1 + 0x27b4) = uVar11 | *(uint *)(param_1 + 0x27b4);
            }
          }
          else {
            iVar16 = uVar26 * 4;
            sVar3 = *(short *)(iVar18 + 0x38);
            *(uint *)(iVar16 + *(int *)(((unsigned char *)0x00001144) + param_1) + 0x2c) =
                 (uint)*(byte *)(iVar18 + 0x30);
            iVar15 = *(int *)(((unsigned char *)0x00001154) + param_1);
            if (*(int *)(iVar15 + 4) != 0) {
              uVar13 = 0;
              iVar14 = 0;
              do {
                iVar19 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 +
                                 *(int *)(iVar14 + *(int *)(iVar15 + 0x88) + 0x70));
                if ((iVar19 != 0) &&
                   ((bool)((unsigned char *)0x00002eb0)[uVar26 + iVar19] != (*(char *)(iVar18 + 0x30) == '\x02')))
                {
                  *(undefined4 *)(((unsigned char *)0x000016f0) + iVar19) = 1;
                  *(undefined1 *)(iVar19 + 0x119) = 1;
                  iVar15 = *(int *)(((unsigned char *)0x00001154) + param_1);
                }
                uVar13 = uVar13 + 1;
                iVar14 = iVar14 + 0x78;
              } while (uVar13 < *(uint *)(iVar15 + 4));
            }
            if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
LAB_0004e294:
              bVar6 = false;
            }
            else {
              iVar15 = *(int *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 +
                               *(int *)(*(int *)(((unsigned char *)0x0000121c) + param_1) + 0x70));
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
              if (((unsigned char *)0x00001610)[uVar26 + iVar14] == '\0') goto LAB_0004e294;
              bVar6 = true;
              if (*(float *)(((unsigned char *)0x00001620) + iVar16 + iVar14) !=
                  *(float *)(iVar18 + 0x4c) + *(float *)(iVar24 + 0x470)) {
                iVar15 = *(int *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 +
                                 *(int *)(*(int *)(((unsigned char *)0x0000121c) + param_1) + 0x70));
                if (iVar15 != 0) {
                  *(undefined1 *)(iVar15 + 0x119) = 1;
                }
                bVar6 = true;
                *(undefined4 *)(((unsigned char *)0x000015cc) + iVar14) = 1;
              }
            }
            *(uint *)(param_1 + 0x27b4) = *(uint *)(param_1 + 0x27b4) & ~uVar11;
          }
          *(uint *)(param_1 + 0x27b0) = uVar11 | *(uint *)(param_1 + 0x27b0);
          *(undefined4 *)(iVar27 + 0x1d5c) = *(undefined4 *)(iVar18 + 0x1c);
          *(undefined4 *)(iVar27 + 0x1d9c) = *(undefined4 *)(iVar18 + 0x20);
          *(undefined4 *)(iVar27 + 0x1ddc) = *(undefined4 *)(iVar18 + 0x24);
          *(undefined4 *)(iVar16 + param_1 + 0x1e1c) = *(undefined4 *)(iVar18 + 0x28);
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
              uVar12 = ((int (*)())FUN_00086930)(param_1,(double)*(float *)(iVar24 + 0x470),fparam_2);
              uVar13 = (uVar12 & 0x3ff) << 3 | uVar13 & 0xffffe007;
              fparam_1 = extraout_f1;
            }
          }
          *(uint *)(iVar27 + 0x1d1c) = uVar13;
          param_4 = *(undefined4 *)(&DAT_001db98c + (uint)*(byte *)(param_1 + 0x2941) * 4);
          param_3 = uVar26;
          fparam_1 = (double)((double (*)())FUN_000b6f20)(param_1,iVar18,uVar26,param_4,fparam_1,fparam_2,fparam_3,
                                          fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
                                          in_stack_ffffff28);
          uVar13 = *(uint *)(iVar18 + 0x14);
          if ((uVar13 & 0x1e00) == 0xa00) {
            if ((uVar13 & 7) == 4) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xfffffff8 | 2;
              uVar13 = *(uint *)(iVar18 + 0x14);
            }
            else if ((uVar13 & 7) == 5) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xfffffff8 | 3;
              uVar13 = *(uint *)(iVar18 + 0x14);
            }
            if ((uVar13 & 0x38) == 0x20) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xffffffc7 | 0x10;
              uVar13 = *(uint *)(iVar18 + 0x14);
            }
            else if ((uVar13 & 0x38) == 0x28) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xffffffc7 | 0x18;
              uVar13 = *(uint *)(iVar18 + 0x14);
            }
            if ((uVar13 & 0x1c0) == 0x100) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xfffffe3f | 0x80;
            }
            else if ((uVar13 & 0x1c0) == 0x140) {
              *(uint *)(iVar16 + param_1 + 0x1cdc) =
                   *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xfffffe3f | 0xc0;
            }
          }
          cVar8 = *(char *)(iVar18 + 0x31);
          if (cVar8 != '\x03') {
            *(uint *)(iVar16 + param_1 + 0x1cdc) = *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xfffffe3f
            ;
            cVar8 = *(char *)(iVar18 + 0x31);
          }
          if (cVar8 == '\x01') {
            *(uint *)(iVar16 + param_1 + 0x1cdc) = *(uint *)(iVar16 + param_1 + 0x1cdc) & 0xffffffc7
            ;
          }
          iVar16 = iVar16 + param_1;
          *(uint *)(iVar16 + 0x1d1c) =
               (*(ushort *)(iVar24 + 0x46e) & 0x3ff) << 3 | *(uint *)(iVar16 + 0x1d1c) & 0xffffe007;
          if ((uVar11 & *(uint *)(param_1 + 0x27b4)) != 0) {
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
      uVar26 = uVar26 + 1;
      uVar9 = uVar9 + 1 & 0xf;
      iVar25 = iVar25 + 4;
      iVar27 = iVar27 + 4;
      iVar24 = iVar24 + 0xcc;
      iVar23 = iVar23 + 0xc;
      iVar22 = iVar22 + 4;
      iVar17 = iVar17 + 1;
    } while (uVar20 != 0);
    iVar17 = *(int *)(param_1 + 0x27b4);
    uVar9 = *(uint *)(param_1 + 0x27b0);
  }
  uVar20 = *(uint *)(param_1 + 0x44);
  *(uint *)(param_1 + 0x27b0) = iVar17 << 8 | uVar9;
  if (((uVar20 & 0x100000) != 0) && (*(code **)((int)((unsigned char *)0x000011cc) + param_1) != (code *)0x0)) {
    fparam_1 = (double)(**(code **)((int)((unsigned char *)0x000011cc) + param_1))(param_1);
    uVar20 = *(uint *)(param_1 + 0x44);
  }
  if ((uVar20 & 0x20000) == 0) {
    FUN_000b6580(param_1,0);
                    
                    
    (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
    return;
  }
  if ((uVar20 & 0x2000) == 0) {
    FUN_000b3630(param_1);
    return;
  }
  ((undefined4 (*)())FUN_000afe40)(param_1,0,param_3,param_4,fparam_1);
  return;
}

/* FUN_0004e880 @ 0x4e880 (252 bytes) */
int FUN_0004e880(param_1)
  int param_1;
{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  
  if (*(int *)(param_1 + 0x243c) != 0) {
    uVar1 = *(int *)(param_1 + 0x243c) + 1U >> 1;
    puVar2 = (uint *)(**(code **)(param_1 + 0x2758))(param_1,uVar1 * 2 + 2);
    *(uint **)(0x00002748 + param_1 + 4) = puVar2;
    uVar4 = (uVar1 - 1) * 0x10000;
    *puVar2 = uVar4 | 0x854;
    puVar2[uVar1 + 1] = uVar4 | 0x878;
    if (uVar1 != 0) {
      iVar3 = 0;
      uVar4 = uVar1;
      do {
        *(undefined4 *)((int)puVar2 + iVar3 + 4) =
             *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x2440));
        *(undefined4 *)((int)puVar2 + iVar3 + uVar1 * 4 + 8) =
             *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x2444));
        iVar3 = iVar3 + 4;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
    *(uint *)(0x00002748 + param_1 + 4) = uVar1 * 8 + *(int *)(0x00002748 + param_1 + 4) + 8;
                    
                    
    (*UNRECOVERED_JUMPTABLE)(param_1);
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

/* FUN_0004ea70 @ 0x4ea70 (260 bytes) */
double FUN_0004ea70(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
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
int FUN_0004eba0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
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
  
  iVar1 = *(int *)(param_1 + 4);
  iVar5 = *(int *)(param_1 + 0x2768);
  iVar4 = *(int *)(param_1 + 8);
  if ((((((unsigned char *)0x00002e2d)[*(int *)(iVar1 + 0x10)] == '\0') ||
       ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
      (iVar1 = FUN_0001a010(iVar1,*(undefined4 *)(iVar1 + 0x26a0),param_3,param_4,param_5,param_6,
                            param_7), iVar1 != 0)) || (iVar5 == 0)) {
    iVar3 = *(int *)(param_1 + 4);
    iVar1 = ((uint (*)())FUN_000a3560)(param_1,(double)*(float *)(((unsigned char *)0x00002e20) + *(int *)(iVar3 + 0x10)));
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x26a0);
    *(short *)(param_1 + 0x1b42) = (short)((uint)(iVar4 * iVar1) >> 1);
    iVar1 = FUN_0001a010(*(int *)(param_1 + 4),uVar2,param_3,param_4,param_5,param_6,iVar3);
    dVar6 = extraout_f1_00;
    if (iVar1 == 0) {
      *(uint *)(param_1 + 0x1b40) = *(uint *)(param_1 + 0x1b40) & 0xfffcffff | 0x20000;
    }
    else {
      *(uint *)(param_1 + 0x1b40) = *(uint *)(param_1 + 0x1b40) & 0xfffcffff | 0x30000;
    }
  }
  else {
    *(short *)(param_1 + 0x1b42) = (short)*(undefined4 *)(iVar5 + 0x18);
    *(uint *)(param_1 + 0x1b40) = *(uint *)(param_1 + 0x1b40) & 0xfffcffff | 0x30000;
    dVar6 = extraout_f1;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((((unsigned char *)0x00002e2c)[iVar1] != '\0') && ((*(uint *)(param_1 + 0x44) & 0x20000) == 0)) &&
     (*(short *)(((unsigned char *)0x00002e28) + iVar1) != -1)) {
    *(uint *)(param_1 + 0x1b64) =
         (uint)(FLOAT_001aa0e8 /
               ((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00002e24) + iVar1) ^ 0x80000000) -
                       DOUBLE_001aa1e0) * FLOAT_001aa0fc *
               (float)((double)CONCAT44(0x43300000,iVar4) - DOUBLE_001aa250))) & 0xfffffffc |
         *(uint *)(param_1 + 0x1b64) & 3;
  }
  if (iVar5 != 0) {
    *(undefined4 *)(param_1 + 0x1b70) = *(undefined4 *)(iVar5 + 0x24);
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x4000;
  ((void (*)())FUN_0004d770)(param_1,dVar6,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* FUN_0004ed90 @ 0x4ed90 (692 bytes) */
int FUN_0004ed90(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  iVar7 = *(int *)(param_1 + 0x2768);
  iVar6 = *(int *)(param_1 + 8);
  iVar4 = FUN_000a3670(param_1);
  uVar5 = *(uint *)(param_1 + 0x44);
  if (((uVar5 & 0x60020000) == 0x40000000) && (iVar7 != 0)) {
    *(short *)(param_1 + 0x1ccc) = (short)*(undefined4 *)(iVar7 + 4);
    *(short *)(param_1 + 0x1cce) = (short)*(undefined4 *)(iVar7 + 4);
    *(undefined4 *)(param_1 + 0x1cc0) = *(undefined4 *)(iVar7 + 0xc);
    *(undefined4 *)(param_1 + 0x1cc8) = *(undefined4 *)(iVar7 + 0x10);
  }
  else {
    if (iVar4 == 0) {
      uVar3 = (undefined2)((uint)(iVar6 * *(int *)(param_1 + 0xe4)) >> 1);
    }
    else {
      uVar3 = (undefined2)((uint)(iVar6 * (int)(*(float *)(param_1 + 0xf0) + FLOAT_001aa10c)) >> 1);
    }
    *(undefined2 *)(param_1 + 0x1cce) = uVar3;
    *(undefined2 *)(param_1 + 0x1ccc) = uVar3;
  }
  if ((uVar5 & 0x60020000) == 0x40000000) {
    if (iVar4 == 0) {
      fVar1 = *(float *)(param_1 + 0x100) + FLOAT_001aa0e8;
      fVar2 = *(float *)(param_1 + 0x104) + FLOAT_001aa0e8;
    }
    else {
      if ((uVar5 & 0x80) != 0) {
        fVar2 = *(float *)(((unsigned char *)0x000013c4) + param_1);
        fVar1 = (float)((double)CONCAT44(0x43300000,iVar6) - DOUBLE_001aa250);
        *(short *)(param_1 + 0x1cd0) =
             (short)((int)(fVar1 * *(float *)((*(unsigned char *)0x000013c8) + param_1)) >> 1);
        *(short *)(param_1 + 0x1cd2) = (short)((int)(fVar1 * fVar2) >> 1);
        goto LAB_0004efc0;
      }
      fVar1 = *(float *)(param_1 + 0x100);
      fVar2 = *(float *)(param_1 + 0x104);
    }
    *(short *)(param_1 + 0x1cd2) = (short)((uint)(iVar6 * (int)fVar1) >> 1);
    *(short *)(param_1 + 0x1cd0) = (short)((uint)(iVar6 * (int)fVar2) >> 1);
  }
  else if ((uVar5 & 0x80) == 0) {
    *(short *)(param_1 + 0x1cd2) = (short)((uint)(iVar6 * *(int *)(param_1 + 0x108)) >> 1);
    *(short *)(param_1 + 0x1cd0) = (short)((uint)(iVar6 * *(int *)(param_1 + 0x10c)) >> 1);
  }
  else {
    iVar4 = *(int *)(((unsigned char *)0x000013d4) + param_1);
    *(short *)(param_1 + 0x1cd2) = (short)(iVar6 * *(int *)((*(unsigned char *)0x000013d0) + param_1) >> 1);
    *(short *)(param_1 + 0x1cd0) = (short)(iVar6 * iVar4 >> 1);
  }
LAB_0004efc0:
  *(uint *)(param_1 + 0x1b74) = *(uint *)(param_1 + 0x1b74) & 0xffff3fff;
  if ((uVar5 & 0x20000000) == 0) {
    *(undefined4 *)(param_1 + 0x1cbc) = 0;
    *(undefined4 *)(param_1 + 0x1cc4) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x1cc0) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x1cbc) = 0;
    *(undefined4 *)(param_1 + 0x1cc4) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x1cc8) = 0;
  }
  if (*(int *)(param_1 + 0x2768) == 0) {
    if ((uVar5 & 0x20000000) == 0) {
      *(undefined4 *)(param_1 + 0x1b50) = 7;
      if ((*(uint *)(param_1 + 0x1a64) & 0x10) != 0) {
        *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) & 0xffffffef;
        uVar5 = *(uint *)(param_1 + 0x1930) | 0x2000;
        *(uint *)(param_1 + 0x1930) = uVar5;
        goto LAB_0004f054;
      }
    }
  }
  uVar5 = *(uint *)(param_1 + 0x1930);
LAB_0004f054:
  *(uint *)(param_1 + 0x1930) = uVar5 | 0xc08000;
  ((void (*)())FUN_0004d770)(param_1,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* FUN_0004f080 @ 0x4f080 (192 bytes) */
int FUN_0004f080(param_1)
  int param_1;
{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((unsigned char *)0x000013b8)[param_1] == '\0') {
    if (*(short *)(((unsigned char *)0x00003174) + iVar3) == 0x900) goto LAB_0004f0c0;
  }
  else if (*(short *)(((unsigned char *)0x00003174) + iVar3) != 0x900) {
LAB_0004f0c0:
    uVar2 = *(uint *)(param_1 + 0x1b30) & 0xfffffffb;
    *(uint *)(param_1 + 0x1b30) = uVar2;
    goto LAB_0004f0dc;
  }
  uVar2 = *(uint *)(param_1 + 0x1b30) | 4;
  *(uint *)(param_1 + 0x1b30) = uVar2;
LAB_0004f0dc:
  if (((unsigned char *)0x0000317a)[iVar3] == '\0') {
    *(uint *)(param_1 + 0x1b30) = uVar2 & 0xfffffffc;
  }
  else {
    sVar1 = *(short *)(((unsigned char *)0x00003176) + iVar3);
    if (sVar1 == 0x405) {
      *(uint *)(param_1 + 0x1b30) = uVar2 & 0xfffffffe | 2;
    }
    else if (sVar1 == 0x408) {
      *(uint *)(param_1 + 0x1b30) = uVar2 | 3;
    }
    else if (sVar1 == 0x404) {
      *(uint *)(param_1 + 0x1b30) = uVar2 & 0xfffffffd | 1;
    }
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x400;
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
      uVar1 = (uint)(*(float *)(((unsigned char *)0x00002de4) + iVar2) * FLOAT_001aa0f0);
    }
  }
  else if (param_2 == 3) {
    dVar4 = (double)(*(float *)(((unsigned char *)0x00002de8) + iVar2) * FLOAT_001aa0f0);
    if (DOUBLE_001aa1e8 <= dVar4) {
      uVar1 = (int)(dVar4 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar1 = (uint)(*(float *)(((unsigned char *)0x00002de8) + iVar2) * FLOAT_001aa0f0);
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
      uVar1 = (uint)(*(float *)(((unsigned char *)0x00002de0) + iVar2) * FLOAT_001aa0f0);
    }
  }
  uVar3 = uVar1 >> 6;
  uVar1 = uVar1 << 2;
LAB_0004f2c8:
  return uVar3 & 3 | uVar1;
}

/* FUN_0004f2e0 @ 0x4f2e0 (616 bytes) */
void FUN_0004f2e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1)
{
  byte bVar1;
  short sVar2;
  undefined *puVar3;
  int iVar4;
  uint uVar5;
  
  puVar3 = PTR_DAT_001e88c8;
  bVar1 = *(byte *)(param_1 + 0x293f);
  if ((*(uint *)(param_1 + 0x44) & 0x1002000) == 0x1000000) {
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    sVar2 = *(short *)(((unsigned char *)0x00002e04) + iVar4);
    if (sVar2 == 0x801) {
      *(undefined4 *)(param_1 + 0x134) = 0;
      *(float *)(param_1 + 0x138) =
           -(*(float *)(((unsigned char *)0x00002df0) + iVar4) * *(float *)(((unsigned char *)0x00002df0) + iVar4));
    }
    else if (sVar2 == 0x2601) {
      *(float *)(param_1 + 0x134) =
           *(float *)(((unsigned char *)0x00002df8) + iVar4) * *(float *)(((unsigned char *)0x00002dfc) + iVar4);
      *(float *)(param_1 + 0x138) = -*(float *)(((unsigned char *)0x00002dfc) + iVar4);
    }
    else if (sVar2 == 0x800) {
      *(undefined4 *)(param_1 + 0x134) = 0;
      *(float *)(param_1 + 0x138) = -*(float *)(((unsigned char *)0x00002df0) + iVar4);
    }
    *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) & 0xfdffffff;
    *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) & 0xfffffff8 | 1;
    *(uint *)(param_1 + 0x1878) = *(uint *)(param_1 + 0x1878) & 0xffefffff;
    *(uint *)(param_1 + 0x1aec) = *(uint *)(param_1 + 0x1aec) & 0xfffffff9 | 1;
    *(undefined4 *)(param_1 + 0x1a78) = 0x3f800000;
    *(undefined4 *)(param_1 + 0x1a7c) = 0xbf800000;
    if (*(char *)(param_1 + 0x121) != '\0') {
      *(undefined1 *)(param_1 + 0x121) = 0;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    }
  }
  else {
    *(uint *)(param_1 + 0x1aec) = *(uint *)(param_1 + 0x1aec) & 0xfffffffe;
    *(uint *)(param_1 + 0x18a4) = *(uint *)(param_1 + 0x18a4) & 0xfdffffff;
    *(uint *)(param_1 + 0x1878) = *(uint *)(param_1 + 0x1878) & 0xffefffff;
    if (*(char *)(param_1 + 0x121) != '\0') {
      *(undefined1 *)(param_1 + 0x121) = 0;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
    }
  }
  if ((*(uint *)(param_1 + 0x44) & 0x20000) == 0) {
    FUN_000b6580(param_1,0);
    (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
  }
  else if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
    FUN_000b3630(param_1);
  }
  else {
    ((undefined4 (*)())FUN_000afe40)(param_1,0,param_3,param_4,fparam_1);
  }
  uVar5 = ((int (*)())FUN_0004f160)(param_1,*(uint *)(puVar3 + (uint)bVar1 * 0x24 + 0x1c) >> 0x1e);
  *(uint *)(param_1 + 0x1a54) = uVar5 & 0x3ff | *(uint *)(param_1 + 0x1a54) & 0xfffffc00;
  uVar5 = ((int (*)())FUN_0004f160)(param_1,*(uint *)(puVar3 + (uint)bVar1 * 0x24 + 0x18) >> 1 & 3);
  *(uint *)(param_1 + 0x1a58) = uVar5 & 0x3ff | *(uint *)(param_1 + 0x1a58) & 0xfffffc00;
  uVar5 = ((int (*)())FUN_0004f160)(param_1,*(uint *)(puVar3 + (uint)bVar1 * 0x24 + 0x18) >> 3 & 3);
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 1;
  *(uint *)(param_1 + 0x1a5c) = uVar5 & 0x3ff | *(uint *)(param_1 + 0x1a5c) & 0xfffffc00;
  return;
}

/* FUN_0004f550 @ 0x4f550 (452 bytes) */
int FUN_0004f550(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar3 = 0;
  uVar4 = (uint)((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001358) + param_1) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) * *(float *)(param_1 + 0x2814));
  uVar2 = (uint)(*(float *)(param_1 + 0x2818) *
                 (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001364) + param_1) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) - FLOAT_001aa0e8);
  uVar5 = (uint)((float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x0000135c) + param_1) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) * *(float *)(param_1 + 0x2818));
  uVar7 = (uint)(*(float *)(param_1 + 0x2814) *
                 (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x00001360) + param_1) ^ 0x80000000
                                         ) - DOUBLE_001aa1e0) - FLOAT_001aa0e8);
  if (-1 < (int)uVar4) {
    uVar3 = uVar4 & 0xffff;
  }
  if ((int)(uint)*(ushort *)(((unsigned char *)0x000013bc) + param_1) < (int)uVar7) {
    uVar7 = (uint)*(ushort *)(((unsigned char *)0x000013bc) + param_1);
  }
  if (((unsigned char *)0x000013b8)[param_1] == '\0') {
    uVar4 = 0;
    if (-1 < (int)uVar5) {
      uVar4 = uVar5 & 0xffff;
    }
    if ((int)(*(ushort *)(((unsigned char *)0x000013ba) + param_1) - 1) < (int)uVar2) {
      uVar2 = *(ushort *)(((unsigned char *)0x000013ba) + param_1) - 1;
    }
  }
  else {
    uVar4 = 0xffff;
    if (-2 < (int)uVar5) {
      uVar4 = uVar5 & 0xffff;
    }
    if ((int)(uint)*(ushort *)(((unsigned char *)0x000013ba) + param_1) < (int)uVar2) {
      uVar2 = (uint)*(ushort *)(((unsigned char *)0x000013ba) + param_1);
    }
  }
  uVar6 = *(uint *)(param_1 + 7000);
  uVar5 = *(uint *)(param_1 + 0x1b10);
  uVar4 = (uVar4 & 0x1fff) << 0xd | uVar3 & 0x1fff | uVar6 & 0xfc000000;
  uVar2 = (uVar2 & 0x1fff) << 0xd | uVar7 & 0x1fff | uVar5 & 0xfc000000;
  *(uint *)(param_1 + 7000) = uVar4;
  *(uint *)(param_1 + 0x1b10) = uVar2;
  if ((uVar6 != uVar4) || (bVar1 = false, uVar5 != uVar2)) {
    bVar1 = true;
  }
  if (bVar1) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 2;
    return;
  }
  return;
}

/* FUN_0004f720 @ 0x4f720 (1348 bytes) */
int FUN_0004f720(param_1)
  int param_1;
{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  *(undefined4 *)(param_1 + 0x1bd0) = 0;
  *(undefined4 *)(param_1 + 0x1930) = 0;
  *(undefined4 *)(param_1 + 0x1934) = 0;
  *(undefined4 *)(param_1 + 0x1938) = 0;
  *(undefined4 *)(param_1 + 0x193c) = 0;
  *(undefined4 *)(param_1 + 0x1a4c) = 0;
  *(undefined4 *)(param_1 + 0x1a50) = 0;
  *(undefined4 *)(param_1 + 0x1a54) = 0;
  *(undefined4 *)(param_1 + 0x1a58) = 0;
  *(undefined4 *)(param_1 + 0x1a5c) = 0;
  *(undefined4 *)(param_1 + 0x1aec) = 0;
  *(undefined4 *)(param_1 + 0x1bcc) = 0;
  if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
    *(undefined4 *)(param_1 + 0x1bcc) = 1;
  }
  if (*(int *)(param_1 + 0x23dc) == 2) {
    *(uint *)(param_1 + 0x1bd0) = *(uint *)(param_1 + 0x1bd0) & 0xfffffffc | 3;
  }
  else {
    *(uint *)(param_1 + 0x1bd0) = *(uint *)(param_1 + 0x1bd0) & 0xfffffffc | 1;
  }
  uVar5 = *(uint *)(0x00001af4 + param_1);
  uVar4 = *(uint *)(param_1 + 0x1af8);
  *(undefined4 *)(param_1 + 0x1b70) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cc0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cc8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1b4c) = 2;
  *(undefined4 *)(param_1 + 0x1a64) = 0;
  *(undefined4 *)(param_1 + 0x1cbc) = 0;
  *(undefined4 *)(param_1 + 0x1cc4) = 0;
  *(undefined4 *)(param_1 + 0x1ccc) = 0;
  *(undefined4 *)(param_1 + 0x1cd0) = 0;
  *(undefined4 *)(param_1 + 0x1b64) = 0;
  *(undefined4 *)(param_1 + 0x1b68) = 0;
  *(undefined4 *)(param_1 + 0x1b6c) = 0;
  *(undefined4 *)(param_1 + 0x1a70) = 0;
  *(undefined4 *)(param_1 + 0x1a74) = 0;
  *(undefined4 *)(param_1 + 0x1b3c) = 0;
  *(undefined4 *)(param_1 + 0x1b44) = 0;
  *(undefined4 *)(param_1 + 0x1a78) = 0;
  *(undefined4 *)(param_1 + 0x1a7c) = 0;
  *(undefined4 *)(param_1 + 0x1a60) = 0;
  *(undefined4 *)(param_1 + 0x1b54) = 0x50005;
  *(undefined4 *)(param_1 + 0x1b40) = 0x20000;
  *(undefined4 *)(param_1 + 0x1b50) = 7;
  *(undefined4 *)(param_1 + 0x1b2c) = 0x30000;
  *(undefined4 *)(param_1 + 0x1a6c) = 0x5666666;
  *(undefined4 *)(param_1 + 0x1a68) = 0x55666666;
  *(undefined4 *)(param_1 + 0x1a80) = 0x20220000;
  *(undefined1 *)(param_1 + 0x247c) = 1;
  *(undefined4 *)(param_1 + 0x1b48) = 1;
  *(uint *)(0x00001af4 + param_1) = uVar5 | 0xf;
  *(undefined4 *)(param_1 + 8) = 0xc;
  *(undefined4 *)(param_1 + 0x23c0) = 0;
  uVar5 = *(uint *)(param_1 + 0x1abc);
  *(undefined4 *)(param_1 + 0x1af0) = 0;
  *(uint *)(param_1 + 0x1af8) = uVar4 & 0xfffffffb;
  *(undefined4 *)(param_1 + 0x1ae0) = 0;
  *(undefined4 *)(param_1 + 7000) = 0;
  *(undefined4 *)(param_1 + 0x1b10) = 0;
  *(undefined4 *)(param_1 + 0x1b60) = 0xffffff;
  *(undefined4 *)(param_1 + 0x1bd4) = 0;
  *(undefined4 *)(param_1 + 0x1b30) = 0;
  *(undefined4 *)(0x00001b14 + param_1) = 0;
  *(undefined4 *)(param_1 + 0x1b28) = 0;
  *(undefined4 *)(param_1 + 0x27b0) = 0;
  *(uint *)(param_1 + 0x1abc) = uVar5 & 0xc0000000 | 0x2da49525;
  _memset(param_1 + 0x1cdc,0,0x40);
  *(undefined4 *)(0x00002348 + param_1) = 0x1b0f;
  *(undefined4 *)(param_1 + 0x233c) = 0x1b0f;
  *(undefined4 *)(param_1 + 0x2340) = 0x1b0f;
  *(undefined4 *)(param_1 + 0x2344) = 0x1b0f;
  FUN_0004ab60(param_1);
  uVar5 = *(uint *)(param_1 + 0x2454);
  *(undefined4 *)(param_1 + 0x1b7c) = 0x80006a;
  if ((int)uVar5 < 0) {
    *(undefined4 *)(param_1 + 0x1b7c) = 0x80086a;
  }
  else if ((uVar5 & 0x8000000) == 0) {
    if ((uVar5 & 0x2000000) == 0) {
      *(undefined4 *)(param_1 + 0x1b7c) = 0x80046a;
    }
    else {
      *(undefined4 *)(param_1 + 0x1b7c) = 0x80026a;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1b7c) = 0x80056a;
  }
  *(undefined4 *)(param_1 + 0x1b80) = 2;
  *(undefined4 *)(param_1 + 0x1ca0) = 0;
  *(undefined4 *)(param_1 + 0x1b9c) = 0;
  *(undefined4 *)(param_1 + 0x1ba0) = 0;
  *(undefined4 *)(param_1 + 0x1cb4) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cac) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cb0) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1b74) = 0;
  *(undefined4 *)(param_1 + 0x1b98) = 0;
  *(undefined4 *)(param_1 + 0x1bc8) = 0;
  *(undefined4 *)(param_1 + 0x1ab0) = 0xc0800;
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  *(undefined4 *)(param_1 + 0x1b84) = 0x43f;
  *(uint *)(param_1 + 0x1b7c) = *(uint *)(param_1 + 0x1b7c) & 0xffc3ffff | 0x300000;
  *(undefined4 *)(param_1 + 0x1b88) = 0xffff;
  *(undefined4 *)(param_1 + 0x1aa0) = 0x10;
  if (*(char *)(param_1 + 0x2451) != '\0') {
    *(undefined4 *)(param_1 + 0x1ab0) = 0xc3800;
  }
  *(undefined4 *)(param_1 + 0x1aa8) = 0;
  *(undefined1 *)(param_1 + 0x1aab) = 0;
  *(undefined1 *)(param_1 + 0x1aa9) = 0xff;
  *(undefined1 *)(param_1 + 0x1aaa) = 0xff;
  *(undefined4 *)(param_1 + 0x1ae4) = 0;
  fVar1 = FLOAT_001aa150;
  *(undefined4 *)(param_1 + 0x1a98) = 0;
  *(undefined4 *)(param_1 + 0x1a9c) = 0;
  *(undefined4 *)(param_1 + 0x1afc) = 0;
  *(undefined4 *)(param_1 + 0x1ae8) = 0;
  *(undefined4 *)(param_1 + 0x1ab4) = 0;
  *(undefined4 *)(param_1 + 0x1aa4) = 0;
  *(float *)(param_1 + 0x1b38) = fVar1;
  *(undefined4 *)(param_1 + 0x1bd8) = 1;
  *(uint *)(param_1 + 0x1cd4) = *(uint *)(param_1 + 0x1cd4) & 0xfffc0003;
  *(undefined4 *)(param_1 + 0x2358) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x235c) = 0;
  *(uint *)(param_1 + 0x1cd8) = *(uint *)(param_1 + 0x1cd8) & 0xffffc00f;
  *(uint *)(param_1 + 0x1ab8) = *(uint *)(param_1 + 0x1ab8) | 1;
  *(undefined4 *)(0x00001b34 + param_1) = 0;
  iVar2 = *(int *)(param_1 + 0x23d0);
  iVar6 = iVar2 * 0xb4;
  *(undefined4 *)(param_1 + 0x2360) = DAT_001db928;
  *(undefined4 *)(param_1 + 0x2364) = DAT_001db92c;
  *(undefined4 *)(param_1 + 0x236c) = DAT_001db934;
  *(undefined4 *)(0x00002368 + param_1) = DAT_001db930;
  *(undefined4 *)(param_1 + 0x2370) = DAT_001db938;
  *(undefined4 *)(param_1 + 0x2374) = *(undefined4 *)(&DAT_001db5b8 + iVar6);
  *(undefined4 *)(param_1 + 0x237c) = *(undefined4 *)(&DAT_001db5c0 + iVar6);
  *(undefined4 *)(param_1 + 0x2378) = *(undefined4 *)(&DAT_001db5bc + iVar6);
  *(undefined4 *)(param_1 + 0x2380) = *(undefined4 *)(&DAT_001db5c4 + iVar6);
  *(undefined4 *)(param_1 + 0x2384) = *(undefined4 *)(&DAT_001db2d4 + iVar6);
  *(undefined4 *)(0x00002388 + param_1) = *(undefined4 *)(&DAT_001db2d8 + iVar6);
  *(undefined4 *)(param_1 + 0x2398) = *(undefined4 *)(&DAT_001db2e0 + iVar6);
  *(undefined **)(param_1 + 0x238c) = (PTR_FUN_001db2dc)[iVar2 * 0x2d];
  *(undefined4 *)(param_1 + 0x239c) = *(undefined4 *)(&DAT_001db2e4 + iVar6);
  *(undefined4 *)(param_1 + 0x2390) = *(undefined4 *)(&DAT_001db2e8 + iVar6);
  *(undefined4 *)(param_1 + 0x23a0) = *(undefined4 *)(&DAT_001db2f0 + iVar6);
  *(undefined **)(param_1 + 0x2394) = (PTR_FUN_001db2ec)[iVar2 * 0x2d];
  uVar3 = *(undefined4 *)(&DAT_001db2f4 + iVar6);
  *(undefined4 *)(param_1 + 0x23c4) = 0;
  *(undefined4 *)(param_1 + 0x23c8) = 0;
  *(undefined4 *)(param_1 + 0x23cc) = 0;
  *(undefined4 *)(param_1 + 0x23a4) = uVar3;
  if (iVar2 == 4) {
    *(undefined4 *)(param_1 + 0x23c8) = 0x101fe;
    *(undefined4 *)(param_1 + 0x23cc) = 0x101fe;
    *(undefined4 *)(param_1 + 0x23c4) = 0x111;
  }
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(undefined2 *)(param_1 + 0x34) = 0xffff;
  *(undefined1 *)(param_1 + 0x2e) = 3;
  *(undefined1 *)(param_1 + 0x2a) = 1;
  *(undefined2 *)(param_1 + 0x32) = 0xffff;
  *(undefined4 *)(param_1 + 0x23e0) = 0;
  *(undefined4 *)(param_1 + 0x1bac) = 0;
  *(undefined4 *)(param_1 + 0x1bb0) = 0;
  *(undefined4 *)(param_1 + 0x1bbc) = 0;
  *(undefined4 *)(param_1 + 0x1bc0) = 0;
  *(undefined4 *)(param_1 + 0x1bc4) = 0;
  *(undefined4 *)(param_1 + 0x2354) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0x800015ff;
  *(undefined1 *)(param_1 + 0x2d) = 0xf;
  *(undefined1 *)(param_1 + 0x2c) = 0xff;
  *(undefined4 *)(param_1 + 0x38) = 0x7ffff;
  *(undefined4 *)(param_1 + 0x40) = 0x7ffff;
  *(undefined1 *)(param_1 + 0x30) = 7;
  *(undefined4 *)(param_1 + 0x1bb8) = 0xaaaaa;
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
int FUN_0004fd80(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  code *pcVar7;
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
  
  iVar12 = *(int *)(((unsigned char *)0x00001154) + param_1);
  iVar11 = iVar12 + 0x10;
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    iVar11 = *(int *)(((unsigned char *)0x00001144) + param_1);
  }
  uVar14 = 0;
  puVar13 = ((unsigned char *)0x00001300);
  iVar16 = 0;
  iVar15 = param_1;
  do {
    iVar9 = *(int *)(param_1 + 0x1e70);
    if ((((1 << (uVar14 & 0x3f) & *(uint *)(((unsigned char *)0x000010b8) + iVar9)) != 0) &&
        (*(char *)(*(int *)(iVar11 + 0x28) + iVar16) == '\0')) &&
       (*(char *)(iVar16 + *(int *)(iVar12 + 0xc)) != '\0')) {
      uVar2 = *(uint *)(iVar16 + *(int *)(iVar12 + 0xc) + 4);
      iVar6 = uVar14 * 0x10;
      iVar10 = iVar6 + iVar9;
      uVar3 = *(uint *)(*(int *)(iVar12 + 0xc) + iVar16 + 8);
      uVar4 = *(uint *)(iVar16 + *(int *)(iVar12 + 0xc) + 0xc);
      uVar5 = *(uint *)(iVar16 + *(int *)(iVar12 + 0xc) + 0x10);
      if (((uVar2 != *(uint *)(iVar10 + 0x8c)) || (uVar3 != *(uint *)(iVar10 + 0x90))) ||
         ((uVar4 != *(uint *)(iVar10 + 0x94) || (uVar5 != *(uint *)(iVar10 + 0x98))))) {
        *(uint *)(iVar6 + iVar9 + 0x8c) = uVar2;
        *(uint *)(iVar6 + *(int *)(param_1 + 0x1e70) + 0x90) = uVar3;
        iVar9 = iVar6 + *(int *)(param_1 + 0x1e70);
        *(uint *)(iVar9 + 0x94) = uVar4;
        *(uint *)(iVar6 + *(int *)(param_1 + 0x1e70) + 0x98) = uVar5;
        *(uint *)(iVar15 + 0x1f38) = uVar2;
        *(uint *)(iVar15 + 0x1f3c) = uVar3;
        *(uint *)(iVar15 + 8000) = uVar4;
        *(uint *)(iVar15 + 0x1f44) = uVar5;
        puVar8 = (uint *)(**(code **)(param_1 + 0x2758))(param_1,5,in_r5,in_r6,in_r7,in_r8,iVar9);
        *(uint **)(0x00002748 + param_1 + 4) = puVar8;
        puVar8[4] = uVar5;
        *puVar8 = (uint)puVar13 | 0x30000;
        puVar8[1] = uVar2;
        puVar8[2] = uVar3;
        puVar8[3] = uVar4;
        iVar9 = *(int *)(0x00002748 + param_1 + 4);
        pcVar7 = *(code **)(param_1 + 0x275c);
        *(int *)(0x00002748 + param_1 + 4) = iVar9 + 0x14;
        (*pcVar7)(param_1,iVar9 + 0x14);
        *(undefined4 *)(param_1 + 0x1e68) = 0;
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

/* FUN_0004ff70 @ 0x4ff70 (416 bytes) */
int FUN_0004ff70(param_1)
  int param_1;
{
  float fVar1;
  int iVar2;
  undefined2 uVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  
  fVar1 = FLOAT_001aa168;
  iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if (((unsigned char *)0x00002d66)[iVar5] == '\0') {
    *(uint *)(param_1 + 0x1a4c) = *(uint *)(param_1 + 0x1a4c) & 0xfffff7ff;
  }
  else {
    switch(*(undefined2 *)(((unsigned char *)0x00002d64) + iVar5)) {
    case 0x201:
      uVar6 = 1;
      iVar2 = 1;
      break;
    case 0x202:
      uVar6 = 2;
      iVar2 = 2;
      break;
    case 0x203:
      uVar6 = 3;
      iVar2 = 3;
      break;
    case 0x204:
      uVar6 = 4;
      iVar2 = 4;
      break;
    case 0x205:
      uVar6 = 5;
      iVar2 = 5;
      break;
    case 0x206:
      uVar6 = 6;
      iVar2 = 6;
      break;
    case 0x207:
      uVar6 = 7;
      iVar2 = 7;
      break;
    default:
      uVar6 = 0;
      iVar2 = 0;
    }
    uVar4 = 0xff;
    *(uint *)(param_1 + 0x1a4c) = iVar2 << 8 | *(uint *)(param_1 + 0x1a4c) & 0xfffff8ff;
    if ((uint)(int)(*(float *)(((unsigned char *)0x00002d60) + iVar5) * fVar1) < 0x100) {
      uVar4 = (undefined1)(int)(*(float *)(((unsigned char *)0x00002d60) + iVar5) * fVar1);
    }
    *(undefined1 *)(param_1 + 0x1a4f) = uVar4;
    if ((*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x3c00) ==
        0x2800) {
      uVar3 = ((uint (*)())FUN_0001d7c0)((double)*(float *)(((unsigned char *)0x00002d60) + iVar5));
      *(undefined2 *)(param_1 + 0x1bde) = uVar3;
    }
    else {
      *(short *)(param_1 + 0x1bde) =
           (short)(int)(*(float *)(((unsigned char *)0x00002d60) + iVar5) * FLOAT_001aa154 + FLOAT_001aa10c);
    }
    *(uint *)(param_1 + 0x1a4c) =
         -(uVar6 ^ 7) >> 0x14 & 0x800 | *(uint *)(param_1 + 0x1a4c) & 0xfffff7ff | 0x1000;
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x200;
  return;
}

/* FUN_00050140 @ 0x50140 (424 bytes) */
int FUN_00050140(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  byte bVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  
  puVar2 = PTR_DAT_001e88c8;
  bVar1 = *(byte *)(param_1 + 0x293f);
  iVar4 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(uint *)(param_1 + 0x18a4) & 0x3fffc0) == 0) {
    *(undefined4 *)(0x00001af4 + param_1) = 0;
  }
  else {
    uVar3 = (uint)(((unsigned char *)0x00002e40)[iVar4] == '\x01') *
            ((byte)PTR_DAT_001e88c8[(uint)bVar1 * 0x24 + 0x1c] & 0xf);
    *(uint *)(0x00001af4 + param_1) = uVar3;
    uVar3 = uVar3 | (uint)(((unsigned char *)0x00002e41)[iVar4] == '\x01') *
                    (*(uint *)(puVar2 + (uint)bVar1 * 0x24 + 0x1c) >> 0x14 & 0xf);
    *(uint *)(0x00001af4 + param_1) = uVar3;
    uVar3 = uVar3 | (uint)(((unsigned char *)0x00002e42)[iVar4] == '\x01') *
                    (*(ushort *)(puVar2 + (uint)bVar1 * 0x24 + 0x1c) & 0xf);
    *(uint *)(0x00001af4 + param_1) = uVar3;
    *(uint *)(0x00001af4 + param_1) =
         uVar3 | (uint)(((unsigned char *)0x00002e43)[iVar4] == '\x01') *
                 (*(uint *)(puVar2 + (uint)bVar1 * 0x24 + 0x1c) >> 0xc & 0xf);
  }
  uVar3 = *(uint *)(param_1 + 0x1b2c);
  *(uint *)(param_1 + 0x1b2c) = uVar3 & 0xfffcffff | 0x30000;
  if (*(int *)(((unsigned char *)0x00003194) + iVar4) == 0x1d01) {
    *(uint *)(param_1 + 0x1bb8) = *(uint *)(param_1 + 0x1bb8) & 0xfff0ffff | 0xa0000;
    *(uint *)(param_1 + 0x1b2c) = uVar3 & 0xfffc0000 | 0x3aaaa;
  }
  else {
    *(uint *)(param_1 + 0x1b2c) = uVar3 & 0xfffcc0c0 | 0x31515;
    if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
      *(uint *)(param_1 + 0x1b2c) = uVar3 & 0xfffc0000 | 0x39595;
    }
    else {
      *(uint *)(param_1 + 0x1b2c) = uVar3 & 0xfffc0000 | 0x35555;
    }
    *(uint *)(param_1 + 0x1bb8) = *(uint *)(param_1 + 0x1bb8) & 0xfff0ffff | 0x50000;
  }
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x10;
  return;
}

/* FUN_00050300 @ 0x50300 (3048 bytes) */
int FUN_00050300(param_1)
  int param_1;
{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 in_r5;
  undefined4 *puVar4;
  undefined *puVar5;
  undefined4 in_r6;
  int iVar6;
  undefined4 uVar7;
  undefined4 in_r7;
  undefined4 a4;
  undefined4 in_r8;
  undefined4 a5;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  
  iVar9 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,6);
  puVar2[1] = 0;
  *puVar2 = ((unsigned char *)0x000010a4);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2 + 2;
  (**(code **)(param_1 + 0x275c))(param_1,puVar2 + 2);
  puVar2 = (undefined4 *)
           (**(code **)(param_1 + 0x2758))
                     (param_1,4,in_r5,in_r6,in_r7,in_r8,*(code **)(param_1 + 0x2758));
  *puVar2 = ((unsigned char *)0x00001393);
  puVar2[1] = 10;
  puVar2[2] = ((unsigned char *)0x000013c6);
  puVar2[3] = 3;
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2 + 4;
  (**(code **)(param_1 + 0x275c))(param_1,puVar2 + 4,in_r5,in_r6,in_r7,in_r8,3);
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x1b4);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2;
  *puVar2 = ((unsigned char *)0x00001394);
  puVar3 = puVar2 + 0x5a;
  uVar8 = *(undefined4 *)(param_1 + 0x1af0);
  puVar2[2] = 0x850;
  puVar2[1] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b80);
  puVar2[4] = 0x110ad;
  puVar2[3] = uVar8;
  puVar2[5] = *(undefined4 *)(0x00001b14 + param_1);
  uVar8 = *(undefined4 *)(param_1 + 0x1b30);
  puVar2[7] = 0x110a2;
  puVar2[6] = uVar8;
  puVar2[8] = *(undefined4 *)(param_1 + 0x1b3c);
  uVar8 = *(undefined4 *)(param_1 + 0x1b48);
  puVar2[10] = ((unsigned char *)0x0000108d);
  puVar2[9] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b40);
  puVar2[0xc] = ((unsigned char *)0x00001002);
  puVar2[0xb] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b50);
  puVar2[0xe] = ((unsigned char *)0x00001085);
  puVar2[0xd] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b54);
  puVar2[0x10] = ((unsigned char *)0x0000108e);
  puVar2[0xf] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b64);
  puVar2[0x12] = ((unsigned char *)0x00001098);
  puVar2[0x11] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b68);
  puVar2[0x14] = 0x11099;
  puVar2[0x13] = uVar8;
  puVar2[0x15] = *(undefined4 *)(param_1 + 0x1b6c);
  uVar8 = *(undefined4 *)(param_1 + 0x1b70);
  puVar2[0x19] = 0x11007;
  puVar2[0x18] = 0;
  puVar2[0x17] = 0x823;
  puVar2[0x16] = uVar8;
  puVar2[0x1a] = *(undefined4 *)(param_1 + 0x1a64);
  uVar8 = *(undefined4 *)(param_1 + 0x1a60);
  puVar2[0x1c] = 0x11004;
  puVar2[0x1b] = uVar8;
  puVar2[0x1d] = *(undefined4 *)(param_1 + 0x1a68);
  uVar8 = *(undefined4 *)(param_1 + 0x1a6c);
  puVar2[0x1f] = ((unsigned char *)0x000010fa);
  puVar2[0x1e] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b60);
  puVar2[0x21] = ((unsigned char *)0x000013a2);
  puVar2[0x20] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x23c0);
  puVar2[0x23] = ((unsigned char *)0x0000109d);
  puVar2[0x22] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b4c);
  puVar2[0x25] = ((unsigned char *)0x000010a8);
  puVar2[0x24] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b28);
  puVar2[0x27] = 0x311a9;
  puVar2[0x26] = uVar8;
  puVar2[0x28] = *(undefined4 *)(param_1 + 0x233c);
  puVar2[0x29] = *(undefined4 *)(param_1 + 0x2340);
  puVar2[0x2a] = *(undefined4 *)(param_1 + 0x2344);
  puVar2[0x2b] = *(undefined4 *)(0x00002348 + param_1);
  puVar2[0x2c] = ((unsigned char *)0x00001385);
  uVar8 = *(undefined4 *)(param_1 + 0x1a94);
  puVar2[0x2e] = 0x110a5;
  puVar2[0x2d] = uVar8;
  puVar2[0x2f] = *(undefined4 *)(param_1 + 0x1a7c);
  uVar8 = *(undefined4 *)(param_1 + 0x1a78);
  puVar2[0x31] = ((unsigned char *)0x0000109e);
  puVar2[0x30] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b2c);
  puVar2[0x33] = 0x861;
  puVar2[0x32] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1ca0);
  puVar2[0x35] = 0x10824;
  puVar2[0x34] = uVar8;
  puVar2[0x36] = *(undefined4 *)(param_1 + 0x1b9c);
  uVar8 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar2[0x38] = 0x1082c;
  puVar2[0x37] = uVar8;
  puVar2[0x39] = *(undefined4 *)(param_1 + 0x1b84);
  uVar8 = *(undefined4 *)(param_1 + 0x248c);
  puVar2[0x3b] = 0x860;
  puVar2[0x3a] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b78);
  puVar2[0x3d] = 0x887;
  puVar2[0x3c] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1b74);
  puVar2[0x3f] = 0x8a2;
  puVar2[0x3e] = uVar8;
  puVar2[0x40] = *(undefined4 *)(param_1 + 0x1b88);
  puVar2[0x41] = 0x877;
  uVar8 = *(undefined4 *)(param_1 + 0x1cb8);
  puVar2[0x43] = 0x1084d;
  puVar2[0x46] = 0x5c8;
  puVar2[0x44] = 0xffffff;
  puVar2[0x47] = 0x8000;
  puVar2[0x48] = 0xc0001000;
  puVar2[0x4a] = (*(unsigned char *)0x000010ea);
  puVar2[0x49] = 0;
  puVar2[0x42] = uVar8;
  puVar2[0x45] = 0;
  uVar8 = *(undefined4 *)(param_1 + 0x1abc);
  puVar2[0x4c] = ((unsigned char *)0x00001096);
  puVar2[0x4b] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1bb8);
  puVar2[0x4e] = ((unsigned char *)0x00001046);
  puVar2[0x4d] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1bbc);
  puVar2[0x50] = ((unsigned char *)0x00001048);
  puVar2[0x4f] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1bc0);
  puVar2[0x52] = ((unsigned char *)0x00001047);
  puVar2[0x51] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1bb0);
  puVar2[0x54] = ((unsigned char *)0x00001045);
  puVar2[0x53] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1bc4);
  puVar2[0x56] = 0x886;
  puVar2[0x55] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1bc8);
  puVar2[0x59] = 2;
  puVar2[0x58] = ((unsigned char *)0x00001180);
  puVar2[0x57] = uVar8;
  if ((*(uint *)(param_1 + 0x2454) & 0x8000000) != 0) {
    puVar3 = puVar2 + 0x62;
    puVar2[0x5a] = ((unsigned char *)0x000012fb);
    uVar8 = *(undefined4 *)(param_1 + 0x1bcc);
    puVar2[0x5c] = ((unsigned char *)0x000012fa);
    puVar2[0x5b] = uVar8;
    uVar8 = *(undefined4 *)(param_1 + 0x1bd0);
    puVar2[0x5e] = ((unsigned char *)0x000010e6);
    puVar2[0x5d] = uVar8;
    uVar8 = *(undefined4 *)(param_1 + 0x1bd4);
    puVar2[0x60] = ((unsigned char *)0x000011f2);
    puVar2[0x5f] = uVar8;
    puVar2[0x61] = *(undefined4 *)(param_1 + 0x1bd8);
  }
  pcVar1 = *(code **)(param_1 + 0x275c);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar3;
  (*pcVar1)(param_1,puVar3);
  ((int (*)())FUN_0004e880)(param_1);
  uVar14 = *(uint *)(param_1 + 0x27b0) |
           (*(uint *)(param_1 + 0x27b0) & *(uint *)(param_1 + 0x27b4)) << 8;
  if (uVar14 != 0) {
    puVar10 = (undefined4 *)(param_1 + 0x1cdc);
    puVar11 = (undefined4 *)(param_1 + 0x1d1c);
    puVar12 = (undefined4 *)(param_1 + 0x1d5c);
    puVar13 = (undefined4 *)(param_1 + 0x1d9c);
    puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xe0);
    iVar6 = *(int *)(param_1 + 0x1938);
    puVar3 = (undefined4 *)(param_1 + 0x1ddc);
    puVar4 = (undefined4 *)(param_1 + 0x1e1c);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2;
    do {
      if ((uVar14 & 1) != 0) {
        *puVar2 = ((unsigned char *)0x00001100) + iVar6;
        uVar8 = *puVar10;
        puVar2[2] = ((unsigned char *)0x00001110) + iVar6;
        puVar2[1] = uVar8;
        uVar8 = *puVar11;
        puVar2[4] = (*(unsigned char *)0x00001120) + iVar6;
        puVar2[3] = uVar8;
        uVar8 = *puVar12;
        puVar2[6] = ((unsigned char *)0x00001130) + iVar6;
        puVar2[5] = uVar8;
        uVar8 = *puVar13;
        puVar2[8] = (*(unsigned char *)0x00001170) + iVar6;
        puVar2[7] = uVar8;
        uVar8 = *puVar4;
        puVar2[10] = ((unsigned char *)0x00001160) + iVar6;
        puVar2[0xc] = ((unsigned char *)0x00001140) + iVar6;
        puVar2[0xb] = 0;
        puVar2[9] = uVar8;
        puVar2[0xd] = *puVar3;
        puVar2 = puVar2 + 0xe;
      }
      uVar14 = uVar14 >> 1;
      iVar6 = iVar6 + 1;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
      puVar12 = puVar12 + 1;
      puVar13 = puVar13 + 1;
      puVar4 = puVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar14 != 0);
    pcVar1 = *(code **)(param_1 + 0x275c);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2;
    (*pcVar1)(param_1,puVar2);
  }
  if ((*(uint *)(param_1 + 0x44) & 0x100) != 0) {
    if ((*(uint *)(param_1 + 0x27b0) & 1) == 0) {
      puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
      puVar3 = puVar2 + 4;
      *puVar2 = ((unsigned char *)0x00001041);
      puVar2[1] = (*(uint *)(param_1 + 0x27b0) | 1) << (*(uint *)(param_1 + 0x1938) & 0x3f);
      iVar6 = *(int *)(param_1 + 0x1938);
      puVar2[3] = 0;
      puVar2[2] = ((unsigned char *)0x00001100) + iVar6;
      goto LAB_00050920;
    }
  }
  puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  puVar3 = puVar2 + 2;
  *puVar2 = ((unsigned char *)0x00001041);
  puVar2[1] = *(int *)(param_1 + 0x27b0) << (*(uint *)(param_1 + 0x1938) & 0x3f);
LAB_00050920:
  pcVar1 = *(code **)(param_1 + 0x275c);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar3;
  (*pcVar1)(param_1,puVar3);
  uVar8 = (**(code **)(param_1 + 0x2758))(param_1,0x90);
  *(undefined4 *)(0x00002748 + param_1 + 4) = uVar8;
  puVar2 = (undefined4 *)((int (*)())FUN_0004dd40)(param_1,uVar8);
  puVar3 = puVar2 + 9;
  *puVar2 = ((unsigned char *)0x0000108c);
  uVar8 = *(undefined4 *)(param_1 + 0x1cd0);
  puVar2[2] = ((unsigned char *)0x00001087);
  puVar2[1] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1ccc);
  puVar2[4] = 0x31080;
  puVar2[3] = uVar8;
  puVar2[5] = *(undefined4 *)(param_1 + 0x1cbc);
  puVar2[6] = *(undefined4 *)(param_1 + 0x1cc4);
  puVar2[7] = *(undefined4 *)(param_1 + 0x1cc0);
  puVar2[8] = *(undefined4 *)(param_1 + 0x1cc8);
  if ((*(int *)(((unsigned char *)0x000031c0) + iVar9) != 0) && (((unsigned char *)0x00001491)[param_1] != '\0')) {
    puVar3 = puVar2 + 0xb;
    puVar2[9] = ((unsigned char *)0x000013c2);
    puVar2[10] = *(undefined4 *)(param_1 + 0x1aa8);
  }
  puVar2 = puVar3 + 4;
  *puVar3 = ((unsigned char *)0x00001386);
  uVar8 = *(undefined4 *)(param_1 + 0x1af8);
  puVar3[2] = ((unsigned char *)0x00001383);
  puVar3[1] = uVar8;
  puVar3[3] = *(undefined4 *)(0x00001af4 + param_1);
  if ((*(uint *)(0x00001b14 + param_1) & 3) != 0) {
    puVar2 = puVar3 + 9;
    puVar3[4] = 0x310a9;
    puVar3[5] = *(undefined4 *)(param_1 + 0x1b1c);
    puVar3[6] = *(undefined4 *)(param_1 + 0x1b18);
    puVar3[7] = *(undefined4 *)(param_1 + 0x1b24);
    puVar3[8] = *(undefined4 *)(param_1 + 0x1b20);
  }
  puVar2 = (undefined4 *)((int (*)())FUN_0004dd10)(param_1,puVar2);
  puVar5 = PTR_DAT_001e88c8;
  *puVar2 = 0x112f5;
  uVar14 = *(uint *)(param_1 + 0x1a4c);
  puVar2[1] = uVar14;
  if ((*(uint *)(puVar5 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    puVar2[1] = uVar14 & 0xfffff7ff;
  }
  uVar8 = *(undefined4 *)(param_1 + 0x1a50);
  puVar2[3] = ((unsigned char *)0x000012f8);
  puVar2[2] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1bdc);
  puVar2[5] = 0x212f2;
  puVar2[4] = uVar8;
  puVar2[6] = *(undefined4 *)(param_1 + 0x1a54);
  puVar2[7] = *(undefined4 *)(param_1 + 0x1a58);
  uVar8 = *(undefined4 *)(param_1 + 0x1a5c);
  puVar2[9] = ((unsigned char *)0x00001007);
  puVar2[8] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1a64);
  puVar2[0xb] = ((unsigned char *)0x000012f0);
  puVar2[10] = uVar8;
  uVar14 = *(uint *)(param_1 + 0x1aec);
  puVar2[0xc] = uVar14;
  if ((*(uint *)(puVar5 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
    puVar2[0xc] = uVar14 & 0xfffffffe;
  }
  puVar2[0xd] = 0x1109f;
  puVar2[0xe] = *(undefined4 *)(param_1 + 0x1a70);
  uVar8 = *(undefined4 *)(param_1 + 0x1a74);
  puVar2[0x10] = 0x11381;
  puVar2[0xf] = uVar8;
  uVar14 = *(uint *)(param_1 + 0x1a80);
  puVar2[0x11] = uVar14;
  if ((*(uint *)(puVar5 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
    puVar2[0x11] = uVar14 & 0xfffffffc;
  }
  uVar8 = *(undefined4 *)(param_1 + 0x1a84);
  puVar2[0x13] = ((unsigned char *)0x00001384);
  puVar2[0x12] = uVar8;
  a5 = 0x113a8;
  a4 = 0x413de;
  uVar7 = 0x313e9;
  puVar5 = ((unsigned char *)0x000813ad);
  uVar8 = *(undefined4 *)(param_1 + 0x1a88);
  puVar2[0x15] = ((unsigned char *)0x000013be);
  puVar2[0x14] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1a8c);
  puVar2[0x17] = ((unsigned char *)0x000013bf);
  puVar2[0x16] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1a90);
  puVar2[0x19] = ((unsigned char *)0x000013c5);
  puVar2[0x18] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x1ab8);
  puVar2[0x1b] = 0x113c0;
  puVar2[0x1a] = uVar8;
  puVar2[0x1c] = *(undefined4 *)(param_1 + 0x1aa0);
  uVar8 = *(undefined4 *)(param_1 + 0x1aa4);
  puVar2[0x1e] = 0x110b0;
  puVar2[0x1d] = uVar8;
  puVar2[0x1f] = *(undefined4 *)(param_1 + 0x1b38);
  uVar8 = *(undefined4 *)(0x00001b34 + param_1);
  puVar2[0x21] = ((unsigned char *)0x0000100a);
  puVar2[0x20] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x2354);
  puVar2[0x23] = 0x113a8;
  puVar2[0x22] = uVar8;
  puVar2[0x24] = *(undefined4 *)(param_1 + 0x235c);
  uVar8 = *(undefined4 *)(param_1 + 0x2358);
  puVar2[0x26] = 0x413de;
  puVar2[0x25] = uVar8;
  puVar2[0x27] = *(undefined4 *)(param_1 + 0x2360);
  puVar2[0x28] = *(undefined4 *)(param_1 + 0x2364);
  puVar2[0x29] = *(undefined4 *)(0x00002368 + param_1);
  puVar2[0x2a] = *(undefined4 *)(param_1 + 0x236c);
  uVar8 = *(undefined4 *)(param_1 + 0x2370);
  puVar2[0x2c] = 0x313e9;
  puVar2[0x2b] = uVar8;
  puVar2[0x2d] = *(undefined4 *)(param_1 + 0x2374);
  puVar2[0x2e] = *(undefined4 *)(param_1 + 0x2378);
  puVar2[0x2f] = *(undefined4 *)(param_1 + 0x237c);
  uVar8 = *(undefined4 *)(param_1 + 0x2380);
  puVar2[0x31] = ((unsigned char *)0x000813ad);
  puVar2[0x30] = uVar8;
  puVar2[0x32] = *(undefined4 *)(param_1 + 0x2384);
  puVar2[0x33] = *(undefined4 *)(0x00002388 + param_1);
  puVar2[0x34] = *(undefined4 *)(param_1 + 0x238c);
  puVar2[0x35] = *(undefined4 *)(param_1 + 0x2390);
  puVar2[0x36] = *(undefined4 *)(param_1 + 0x2394);
  puVar2[0x37] = *(undefined4 *)(param_1 + 0x2398);
  puVar2[0x38] = *(undefined4 *)(param_1 + 0x239c);
  puVar2[0x39] = *(undefined4 *)(param_1 + 0x23a0);
  uVar8 = *(undefined4 *)(param_1 + 0x23a4);
  puVar2[0x3b] = ((unsigned char *)0x000013e6);
  puVar2[0x3a] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x23c4);
  puVar2[0x3d] = ((unsigned char *)0x000013e7);
  puVar2[0x3c] = uVar8;
  uVar8 = *(undefined4 *)(param_1 + 0x23c8);
  puVar2[0x3f] = ((unsigned char *)0x000013e8);
  puVar2[0x3e] = uVar8;
  puVar2[0x40] = *(undefined4 *)(param_1 + 0x23cc);
  if ((*(uint *)(param_1 + 0x44) & 0x20000) == 0) {
    *(undefined4 *)(param_1 + 0x1e68) = 0;
  }
  pcVar1 = *(code **)(param_1 + 0x275c);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2 + 0x41;
  (*pcVar1)(param_1);
  if (*(int *)(param_1 + 0x2494) != 0) {
    puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x12);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2;
    *puVar2 = 0x830;
    uVar8 = *(undefined4 *)(param_1 + 0x2490);
    puVar2[2] = 0x831;
    puVar2[1] = uVar8;
    uVar8 = **(undefined4 **)(param_1 + 0x2494);
    puVar2[4] = 0x834;
    puVar2[3] = uVar8;
    uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 4);
    puVar2[6] = 0x837;
    puVar2[5] = uVar8;
    uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 8);
    puVar2[8] = 0x83a;
    puVar2[7] = uVar8;
    uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0xc);
    puVar2[10] = 0x83d;
    puVar2[9] = uVar8;
    uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x10);
    puVar2[0xc] = 0x840;
    puVar2[0xb] = uVar8;
    uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x14);
    puVar2[0xe] = 0x843;
    puVar2[0xd] = uVar8;
    uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x18);
    puVar2[0x10] = 0x846;
    puVar2[0xf] = uVar8;
    puVar2[0x11] = *(undefined4 *)(*(int *)(param_1 + 0x2494) + 0x1c);
    iVar9 = *(int *)(0x00002748 + param_1 + 4);
    pcVar1 = *(code **)(param_1 + 0x275c);
    *(int *)(0x00002748 + param_1 + 4) = iVar9 + 0x48;
    (*pcVar1)(param_1,iVar9 + 0x48,puVar5,uVar7,a4,a5,puVar2);
  }
  iVar9 = FUN_0004aa00(param_1,1);
  if (iVar9 == 0) {
    (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,0xc0100000);
    (**(code **)(((unsigned char *)0x00001338) + param_1))(param_1);
    FUN_00086710(param_1);
  }
  uVar14 = *(uint *)(param_1 + 0x8c);
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  *(uint *)(param_1 + 0x8c) = uVar14 | 0x58000;
  if ((((uVar14 & 0x50000000) == 0) && (*(code **)(((unsigned char *)0x000012b0) + param_1) != (code *)0x0)) &&
     ((uVar14 & 0x200000) != 0)) {
    uVar7 = *(undefined4 *)(param_1 + 0x38);
    uVar8 = *(undefined4 *)(param_1 + 0x3c);
    (**(code **)(((unsigned char *)0x000012b0) + param_1))(param_1);
    *(undefined4 *)(param_1 + 0x38) = uVar7;
    *(undefined4 *)(param_1 + 0x3c) = uVar8;
  }
  else {
    *(undefined1 *)(param_1 + 0x23ec) = 1;
    FUN_0009d2e0(param_1);
  }
  *(undefined1 *)(param_1 + 0x23ec) = 1;
  return;
}

/* FUN_00050ef0 @ 0x50ef0 (284 bytes) */
int FUN_00050ef0(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  code *pcVar1;
  uint uVar2;
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
  uVar2 = *(uint *)(param_1 + 0x1b7c);
  if ((uVar4 != (uVar2 & 0xf)) || (uVar5 != (uVar2 >> 4 & 0xf))) {
    *(undefined1 *)(param_1 + 0x23ec) = 1;
    *(uint *)(param_1 + 0x1b7c) = (uVar5 & 0xf) << 4 | uVar4 & 0xf | uVar2 & 0xffffff00;
  }
  if (*(char *)(param_1 + 0x23ec) != '\0') {
    a6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
    *(undefined4 **)(0x00002748 + param_1 + 4) = a6;
    a6[1] = 0;
    *a6 = 0x8a1;
    a6[2] = 0x820;
    a6[3] = *(undefined4 *)(param_1 + 0x1b7c);
    iVar3 = *(int *)(0x00002748 + param_1 + 4);
    pcVar1 = *(code **)(param_1 + 0x275c);
    *(int *)(0x00002748 + param_1 + 4) = iVar3 + 0x10;
    (*pcVar1)(param_1,iVar3 + 0x10,param_3,param_4,in_r7,in_r8,a6);
    *(undefined1 *)(param_1 + 0x23ec) = 0;
  }
  return;
}

/* FUN_00051010 @ 0x51010 (1024 bytes) */
int FUN_00051010(param_1)
  int param_1;
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
  
  iVar7 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(int *)(((unsigned char *)0x000031c0) + iVar7) == 0) || (((unsigned char *)0x00001491)[param_1] == '\0')) {
    *(undefined1 *)(param_1 + 0x23ed) = 0;
    *(uint *)(param_1 + 0x1aa0) = *(uint *)(param_1 + 0x1aa0) & 0xfffffffe;
    goto LAB_00051404;
  }
  iVar2 = 3;
  *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) | 0x20000000;
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
  *(char *)(param_1 + 0x1aab) = (char)*(undefined4 *)(((unsigned char *)0x0000319c) + iVar7);
  *(char *)(param_1 + 0x1aaa) = (char)*(undefined4 *)(((unsigned char *)0x00003198) + iVar7);
  *(char *)(param_1 + 0x1aa9) = (char)*(undefined4 *)(((unsigned char *)0x00002e38) + iVar7);
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
  *(undefined1 *)(param_1 + 0x23ed) = 1;
  *(uint *)(param_1 + 0x1aa0) = *(uint *)(param_1 + 0x1aa0) | 1;
  *(uint *)(param_1 + 0x1aa4) =
       iVar8 << 0x18 |
       iVar6 << 0x15 |
       iVar4 << 0xc |
       iVar3 << 9 |
       iVar5 << 0x12 |
       (uVar9 & 7) << 0xf |
       iVar2 << 6 | (uVar10 & 7) << 3 | *(uint *)(param_1 + 0x1aa4) & 0xf8000007;
  if ((*(int *)(((unsigned char *)0x00002e38) + iVar7) == 0) ||
     (iVar8 == 0 && (iVar6 == 0 && (iVar4 == 0 && (iVar3 == 0 && (iVar5 == 0 && iVar2 == 0)))))) {
    *(undefined1 *)(param_1 + 0x23ed) = 0;
  }
LAB_00051404:
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x808;
  return;
}

/* FUN_00051420 @ 0x51420 (3152 bytes) */
int FUN_00051420(param_1)
  int param_1;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  bool bVar4;
  bool bVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
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
  int iVar21;
  double dVar22;
  double dVar23;
  
  uVar17 = *(uint *)(param_1 + 0x1a80);
  uVar20 = *(uint *)(0x00001af4 + param_1 + 4);
  iVar21 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  *(uint *)(param_1 + 0x1a80) = uVar17 & 0x3ffffffe;
  if (((((unsigned char *)0x00002d84)[iVar21] == '\0') || (((unsigned char *)0x00002e33)[iVar21] != '\0')) ||
     ((*(int *)(((unsigned char *)0x00002d80) + iVar21) == -0x7ff97ffa &&
      ((((*(short *)(((unsigned char *)0x00002d68) + iVar21) == 1 && (*(short *)(((unsigned char *)0x00002d6c) + iVar21) == 1)) &&
        (*(short *)(((unsigned char *)0x00002d6a) + iVar21) == 0)) && (*(short *)(((unsigned char *)0x00002d6e) + iVar21) == 0))))))
  goto LAB_00051ee0;
  uVar1 = *(ushort *)(((unsigned char *)0x00002d80) + iVar21);
  if (uVar1 == 0x8008) {
    bVar4 = true;
    iVar19 = 5;
  }
  else if (uVar1 < 0x8009) {
    if (uVar1 == 0x8007) {
      bVar4 = true;
      iVar19 = 4;
    }
    else {
LAB_000514ec:
      bVar4 = false;
      iVar19 = 0;
    }
  }
  else if (uVar1 == 0x800a) {
    bVar4 = false;
    iVar19 = 2;
  }
  else {
    if (uVar1 != 0x800b) goto LAB_000514ec;
    bVar4 = false;
    iVar19 = 6;
  }
  uVar2 = *(ushort *)(((unsigned char *)0x00002d82) + iVar21);
  if (uVar2 == 0x8008) {
    bVar5 = true;
    iVar13 = 5;
  }
  else if (uVar2 < 0x8009) {
    if (uVar2 == 0x8007) {
      bVar5 = true;
      iVar13 = 4;
    }
    else {
LAB_0005157c:
      bVar5 = false;
      iVar13 = 0;
    }
  }
  else if (uVar2 == 0x800a) {
    bVar5 = false;
    iVar13 = 2;
  }
  else {
    if (uVar2 != 0x800b) goto LAB_0005157c;
    bVar5 = false;
    iVar13 = 6;
  }
  uVar2 = *(ushort *)(((unsigned char *)0x00002d68) + iVar21);
  if (uVar2 == 0x305) {
    iVar8 = 0x29;
    bVar4 = true;
    iVar15 = 0x29;
  }
  else if (uVar2 < 0x306) {
    if (uVar2 == 0x301) {
      iVar8 = 0x23;
      iVar15 = 0x23;
    }
    else if (uVar2 < 0x302) {
      if (uVar2 == 0) {
        iVar8 = 0x20;
        iVar15 = 0x20;
      }
      else {
        if (uVar2 != 0x300) goto LAB_00051614;
        iVar8 = 0x22;
        iVar15 = 0x22;
      }
    }
    else if (uVar2 == 0x303) {
      iVar8 = 0x27;
      iVar15 = 0x27;
    }
    else if (uVar2 < 0x304) {
      iVar8 = 0x26;
      iVar15 = 0x26;
    }
    else {
      iVar8 = 0x28;
      bVar4 = true;
      iVar15 = 0x28;
    }
  }
  else if (uVar2 == 0x8001) {
    iVar8 = 0x2b;
    iVar15 = 0x2b;
  }
  else if (uVar2 < 0x8002) {
    if (uVar2 == 0x307) {
      iVar8 = 0x25;
      bVar4 = true;
      iVar15 = 0x25;
    }
    else if (uVar2 < 0x307) {
      iVar8 = 0x24;
      bVar4 = true;
      iVar15 = 0x24;
    }
    else if (uVar2 == 0x308) {
      iVar8 = 0x2a;
      bVar4 = true;
      iVar15 = 0x2a;
    }
    else {
LAB_00051614:
      iVar8 = 0x21;
      iVar15 = 0x21;
    }
  }
  else if (uVar2 == 0x8003) {
    iVar15 = 0x2d;
    iVar8 = 0x2d;
  }
  else if (uVar2 < 0x8003) {
    iVar8 = 0x2c;
    iVar15 = 0x2c;
  }
  else {
    if (uVar2 != 0x8004) goto LAB_00051614;
    iVar8 = 0x2e;
    iVar15 = 0x2e;
  }
  uVar3 = *(ushort *)(((unsigned char *)0x00002d6c) + iVar21);
  if (uVar2 != uVar3) {
    if (uVar3 == 0x305) {
      bVar5 = true;
      iVar8 = 0x29;
    }
    else if (uVar3 < 0x306) {
      iVar8 = 0x23;
      if (uVar3 != 0x301) {
        if (uVar3 < 0x302) {
          iVar8 = 0x20;
          if ((uVar3 != 0) && (iVar8 = 0x22, uVar3 != 0x300)) goto LAB_0005179c;
        }
        else {
          iVar8 = 0x27;
          if ((uVar3 != 0x303) && (iVar8 = 0x26, 0x303 < uVar3)) {
            bVar5 = true;
            iVar8 = 0x28;
          }
        }
      }
    }
    else {
      iVar8 = 0x2b;
      if (uVar3 != 0x8001) {
        if (uVar3 < 0x8002) {
          if (uVar3 == 0x307) {
            bVar5 = true;
            iVar8 = 0x25;
          }
          else if (uVar3 < 0x307) {
            bVar5 = true;
            iVar8 = 0x24;
          }
          else {
            if (uVar3 != 0x308) goto LAB_0005179c;
            bVar5 = true;
            iVar8 = 0x2a;
          }
        }
        else {
          iVar8 = 0x2d;
          if (((uVar3 != 0x8003) && (iVar8 = 0x2c, 0x8002 < uVar3)) &&
             (iVar8 = 0x2e, uVar3 != 0x8004)) {
LAB_0005179c:
            iVar8 = 0x21;
          }
        }
      }
    }
  }
  uVar2 = *(ushort *)(((unsigned char *)0x00002d6a) + iVar21);
  if (uVar2 == 0x305) {
    iVar9 = 0x29;
    bVar4 = true;
    iVar16 = 0x29;
  }
  else if (uVar2 < 0x306) {
    if (uVar2 == 0x301) {
      iVar9 = 0x23;
      bVar4 = true;
      iVar16 = 0x23;
    }
    else if (uVar2 < 0x302) {
      if (uVar2 == 1) {
        iVar9 = 0x21;
        bVar4 = true;
        iVar16 = 0x21;
      }
      else {
        if (uVar2 != 0x300) goto LAB_000518a4;
        iVar9 = 0x22;
        bVar4 = true;
        iVar16 = 0x22;
      }
    }
    else if (uVar2 == 0x303) {
      iVar9 = 0x27;
      bVar4 = true;
      iVar16 = 0x27;
    }
    else if (uVar2 < 0x304) {
      iVar9 = 0x26;
      bVar4 = true;
      iVar16 = 0x26;
    }
    else {
      iVar9 = 0x28;
      bVar4 = true;
      iVar16 = 0x28;
    }
  }
  else if (uVar2 == 0x8001) {
    iVar9 = 0x2b;
    bVar4 = true;
    iVar16 = 0x2b;
  }
  else if (uVar2 < 0x8002) {
    if (uVar2 == 0x306) {
      iVar9 = 0x24;
      bVar4 = true;
      iVar16 = 0x24;
    }
    else if (uVar2 == 0x307) {
      iVar9 = 0x25;
      bVar4 = true;
      iVar16 = 0x25;
    }
    else {
LAB_000518a4:
      iVar9 = 0x20;
      iVar16 = 0x20;
    }
  }
  else if (uVar2 == 0x8003) {
    iVar9 = 0x2d;
    bVar4 = true;
    iVar16 = 0x2d;
  }
  else if (uVar2 < 0x8003) {
    iVar9 = 0x2c;
    bVar4 = true;
    iVar16 = 0x2c;
  }
  else {
    if (uVar2 != 0x8004) goto LAB_000518a4;
    iVar9 = 0x2e;
    bVar4 = true;
    iVar16 = 0x2e;
  }
  uVar3 = *(ushort *)(((unsigned char *)0x00002d6e) + iVar21);
  if (uVar2 != uVar3) {
    if (uVar3 == 0x305) {
      bVar5 = true;
      iVar9 = 0x29;
    }
    else if (uVar3 < 0x306) {
      if (uVar3 == 0x301) {
        bVar5 = true;
        iVar9 = 0x23;
      }
      else if (uVar3 < 0x302) {
        if (uVar3 == 1) {
          bVar5 = true;
          iVar9 = 0x21;
        }
        else {
          if (uVar3 != 0x300) goto LAB_00051a20;
          bVar5 = true;
          iVar9 = 0x22;
        }
      }
      else if (uVar3 == 0x303) {
        bVar5 = true;
        iVar9 = 0x27;
      }
      else if (uVar3 < 0x304) {
        bVar5 = true;
        iVar9 = 0x26;
      }
      else {
        bVar5 = true;
        iVar9 = 0x28;
      }
    }
    else if (uVar3 == 0x8001) {
      bVar5 = true;
      iVar9 = 0x2b;
    }
    else if (uVar3 < 0x8002) {
      if (uVar3 == 0x306) {
        bVar5 = true;
        iVar9 = 0x24;
      }
      else if (uVar3 == 0x307) {
        bVar5 = true;
        iVar9 = 0x25;
      }
      else {
LAB_00051a20:
        iVar9 = 0x20;
      }
    }
    else if (uVar3 == 0x8003) {
      bVar5 = true;
      iVar9 = 0x2d;
    }
    else if (uVar3 < 0x8003) {
      bVar5 = true;
      iVar9 = 0x2c;
    }
    else {
      if (uVar3 != 0x8004) goto LAB_00051a20;
      bVar5 = true;
      iVar9 = 0x2e;
    }
  }
  if ((uVar1 == 0x8006) &&
     (iVar11 = *(int *)(((unsigned char *)0x00002d68) + iVar21), iVar11 == *(int *)(((unsigned char *)0x00002d6c) + iVar21))) {
    if ((iVar11 == 0x3020303) || ((iVar11 == 0x3020001 || (iVar11 == 0x303)))) {
      iVar18 = 1;
    }
    else if ((((iVar11 == 0x301) || (iVar11 == 0x10001)) || (iVar11 == 0x3060001)) ||
            (iVar11 == 0x3040001)) {
      iVar18 = 2;
      if ((*(uint *)(param_1 + 0x8c) & 0x400000) == 0) goto LAB_00051c10;
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
  uVar10 = *(uint *)(param_1 + 0x1a80);
  *(uint *)(param_1 + 0x1a80) = uVar10 | 3;
  dVar22 = DOUBLE_001aa258;
  dVar23 = DOUBLE_001aa1e8;
  if ((bVar4) || (iVar11 = 0, bVar5)) {
    iVar11 = 1;
  }
  *(uint *)(param_1 + 0x1a84) =
       iVar9 << 0x18 | iVar8 << 0x10 | iVar13 << 0xc | *(uint *)(param_1 + 0x1a84) & 0xc0c08fff;
  *(uint *)(param_1 + 0x1a80) =
       iVar16 << 0x18 |
       iVar15 << 0x10 | iVar19 << 0xc | iVar18 << 3 | iVar11 << 2 | uVar10 & 0xc0c08fc3 | 3;
  dVar22 = (double)*(float *)(((unsigned char *)0x00002d7c) + iVar21) * dVar22;
  if (dVar23 <= dVar22) {
    iVar19 = (int)(dVar22 - dVar23) + -0x80000000;
  }
  else {
    iVar19 = (int)dVar22;
  }
  dVar23 = (double)*(float *)(((unsigned char *)0x00002d70) + iVar21) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar23) {
    iVar13 = (int)(dVar23 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar13 = (int)dVar23;
  }
  dVar23 = (double)*(float *)(((unsigned char *)0x00002d74) + iVar21) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar23) {
    iVar8 = (int)(dVar23 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar8 = (int)dVar23;
  }
  dVar23 = (double)*(float *)(((unsigned char *)0x00002d78) + iVar21) * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar23) {
    uVar10 = (int)(dVar23 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar10 = (uint)dVar23;
  }
  *(uint *)(param_1 + 0x1a88) = iVar19 << 0x18 | iVar13 << 0x10 | iVar8 << 8 | uVar10;
  fVar7 = FLOAT_001aa154;
  fVar6 = FLOAT_001aa10c;
  if ((*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x3c00) ==
      0x2800) {
    uVar14 = ((uint (*)())FUN_0001d7c0)((double)*(float *)(((unsigned char *)0x00002d70) + iVar21));
    *(undefined2 *)(param_1 + 0x1a8e) = uVar14;
    uVar14 = ((uint (*)())FUN_0001d7c0)((double)*(float *)(((unsigned char *)0x00002d7c) + iVar21));
    *(undefined2 *)(param_1 + 0x1a8c) = uVar14;
    uVar14 = ((uint (*)())FUN_0001d7c0)((double)*(float *)(((unsigned char *)0x00002d78) + iVar21));
    *(undefined2 *)(param_1 + 0x1a92) = uVar14;
    uVar14 = ((uint (*)())FUN_0001d7c0)((double)*(float *)(((unsigned char *)0x00002d74) + iVar21));
    *(undefined2 *)(param_1 + 0x1a90) = uVar14;
  }
  else {
    *(short *)(param_1 + 0x1a8e) =
         (short)(int)(*(float *)(((unsigned char *)0x00002d70) + iVar21) * FLOAT_001aa154 + FLOAT_001aa10c);
    *(short *)(param_1 + 0x1a8c) = (short)(int)(*(float *)(((unsigned char *)0x00002d7c) + iVar21) * fVar7 + fVar6);
    *(short *)(param_1 + 0x1a92) = (short)(int)(*(float *)(((unsigned char *)0x00002d78) + iVar21) * fVar7 + fVar6);
    *(short *)(param_1 + 0x1a90) = (short)(int)(*(float *)(((unsigned char *)0x00002d74) + iVar21) * fVar7 + fVar6);
  }
LAB_00051ee0:
  if ((((unsigned char *)0x00002ddc)[iVar21] == '\0') || ((*(uint *)(*(int *)(param_1 + 4) + 0x154) & 0xf) != 3))
  {
    *(uint *)(param_1 + 0x1af0) = *(uint *)(param_1 + 0x1af0) & 0xfffffff0 | 5;
  }
  else {
    *(uint *)(param_1 + 0x1af0) = *(uint *)(param_1 + 0x1af0) & 0xfffffff0 | 6;
  }
  if ((((unsigned char *)0x00002e33)[iVar21] == '\0') || (((unsigned char *)0x00001492)[param_1] != '\0')) {
    uVar10 = *(uint *)(0x00001af4 + param_1 + 4) & 0xfffffffb;
    *(uint *)(0x00001af4 + param_1 + 4) = uVar10;
  }
  else {
    switch(*(undefined2 *)(((unsigned char *)0x00002e30) + iVar21)) {
    case 0x1500:
      iVar21 = 0;
      break;
    case 0x1501:
      iVar21 = 8;
      break;
    case 0x1502:
      iVar21 = 4;
      break;
    default:
      iVar21 = 0xc;
      break;
    case 0x1504:
      iVar21 = 2;
      break;
    case 0x1505:
      iVar21 = 10;
      break;
    case 0x1506:
      iVar21 = 6;
      break;
    case 0x1507:
      iVar21 = 0xe;
      break;
    case 0x1508:
      iVar21 = 1;
      break;
    case 0x1509:
      iVar21 = 9;
      break;
    case 0x150a:
      iVar21 = 5;
      break;
    case 0x150b:
      iVar21 = 0xd;
      break;
    case 0x150c:
      iVar21 = 3;
      break;
    case 0x150d:
      iVar21 = 0xb;
      break;
    case 0x150e:
      iVar21 = 7;
      break;
    case 0x150f:
      iVar21 = 0xf;
    }
    uVar10 = iVar21 << 8 | *(uint *)(0x00001af4 + param_1 + 4) & 0xfffff0ff | 4;
    *(uint *)(0x00001af4 + param_1 + 4) = uVar10;
  }
  uVar12 = *(uint *)(param_1 + 0x1930);
  *(uint *)(param_1 + 0x1930) = uVar12 | 4;
  if (uVar20 != uVar10) {
    *(uint *)(param_1 + 0x1930) = uVar12 | 0x10004;
  }
  if (((uVar17 & 1) == 0) && ((*(uint *)(param_1 + 0x1a80) & 1) != 0)) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x100;
  }
  return;
}

/* FUN_000520c0 @ 0x520c0 (436 bytes) */
double FUN_000520c0(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  dVar6 = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa10c;
  iVar8 = *(int *)(param_1 + 4);
  iVar10 = *(int *)(param_1 + 0x1c9c);
  iVar9 = *(int *)(param_1 + 0x1c98);
  iVar13 = *(int *)(param_1 + 0x1c88);
  iVar12 = *(int *)(param_1 + 0x1c94);
  iVar11 = *(int *)(param_1 + 0x1c90);
  iVar15 = *(int *)(param_1 + 0x1c8c);
  iVar14 = *(int *)(iVar8 + 0x10);
  fVar1 = *(float *)(iVar8 + 0x2a58);
  fVar2 = *(float *)(iVar8 + 0x2a54);
  *(undefined4 *)(param_1 + 0x1c9c) = *(undefined4 *)(iVar14 + 0x1818);
  *(undefined4 *)(param_1 + 0x1c98) = *(undefined4 *)(iVar14 + 0x1828);
  uVar7 = *(uint *)(iVar14 + 0x1840);
  fVar3 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar14 + 0x184c) ^ 0x80000000) -
                         dVar6) * fVar4;
  fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar14 + 0x1844) ^ 0x80000000) -
                         dVar6) + fVar3;
  fVar4 = fVar2 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar14 + 0x1848) ^ 0x80000000) -
                         dVar6) * fVar4;
  if (*(char *)(param_1 + 0x293c) != '\0') {
    fVar5 = fVar1 * (float)((double)CONCAT44(0x43300000,*(uint *)(iVar8 + 0x160) ^ 0x80000000) -
                           dVar6) - fVar5;
    fVar3 = -fVar3;
  }
  *(float *)(param_1 + 0x1c8c) = fVar4;
  *(float *)(param_1 + 0x1c88) =
       fVar2 * (float)((double)CONCAT44(0x43300000,uVar7 ^ 0x80000000) - dVar6) + fVar4;
  *(float *)(param_1 + 0x1c94) = fVar3;
  *(float *)(param_1 + 0x1c90) = fVar5;
  if (*(char *)(param_1 + 0x124) != '\0') {
    *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
    *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  }
  *(undefined4 *)(param_1 + 0x1ca8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x1cb0) = 0x3f800000;
  if ((((iVar15 != *(int *)(param_1 + 0x1c8c)) || (iVar13 != *(int *)(param_1 + 0x1c88))) ||
      (iVar12 != *(int *)(param_1 + 0x1c94))) ||
     (((iVar11 != *(int *)(param_1 + 0x1c90) || (iVar10 != *(int *)(param_1 + 0x1c9c))) ||
      (iVar9 != *(int *)(param_1 + 0x1c98))))) {
    *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x80;
  }
  ((int (*)())FUN_0004f550)(param_1);
  return;
}

/* FUN_00052280 @ 0x52280 (2608 bytes) */
int FUN_00052280(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined4 uVar2;
  code *pcVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  int iVar16;
  
  uVar12 = *(uint *)(param_1 + 0x1930);
  uVar4 = *(uint *)(param_1 + 0x1934) & *(uint *)(param_1 + 0x27b0);
  uVar4 = uVar4 | (uVar4 & *(uint *)(param_1 + 0x27b4)) << 8;
  if (uVar4 != 0) {
    puVar13 = (undefined4 *)(param_1 + 0x1cdc);
    puVar14 = (undefined4 *)(param_1 + 0x1d1c);
    puVar15 = (undefined4 *)(param_1 + 0x1d5c);
    puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xe0);
    iVar9 = *(int *)(param_1 + 0x1938);
    puVar11 = (undefined4 *)(param_1 + 0x1d9c);
    puVar7 = (undefined4 *)(param_1 + 0x1ddc);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar6;
    puVar8 = (undefined4 *)(param_1 + 0x1e1c);
    do {
      if ((uVar4 & 1) != 0) {
        *puVar6 = ((unsigned char *)0x00001100) + iVar9;
        uVar2 = *puVar13;
        puVar6[2] = ((unsigned char *)0x00001110) + iVar9;
        puVar6[1] = uVar2;
        uVar2 = *puVar14;
        puVar6[4] = (*(unsigned char *)0x00001120) + iVar9;
        puVar6[3] = uVar2;
        uVar2 = *puVar15;
        puVar6[6] = ((unsigned char *)0x00001130) + iVar9;
        puVar6[5] = uVar2;
        uVar2 = *puVar11;
        puVar6[8] = (*(unsigned char *)0x00001170) + iVar9;
        puVar6[7] = uVar2;
        uVar2 = *puVar8;
        puVar6[10] = ((unsigned char *)0x00001160) + iVar9;
        puVar6[0xc] = ((unsigned char *)0x00001140) + iVar9;
        puVar6[0xb] = 0;
        puVar6[9] = uVar2;
        puVar6[0xd] = *puVar7;
        puVar6 = puVar6 + 0xe;
      }
      uVar4 = uVar4 >> 1;
      iVar9 = iVar9 + 1;
      puVar13 = puVar13 + 1;
      puVar14 = puVar14 + 1;
      puVar15 = puVar15 + 1;
      puVar11 = puVar11 + 1;
      puVar8 = puVar8 + 1;
      puVar7 = puVar7 + 1;
    } while (uVar4 != 0);
    pcVar3 = *(code **)(param_1 + 0x275c);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar6;
    (*pcVar3)(param_1,puVar6);
  }
  if (((*(uint *)(param_1 + 0x44) & 0x100) == 0) || ((*(uint *)(param_1 + 0x27b0) & 1) != 0)) {
    puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    puVar7 = puVar6 + 2;
    *puVar6 = ((unsigned char *)0x00001041);
    puVar6[1] = *(int *)(param_1 + 0x27b0) << (*(uint *)(param_1 + 0x1938) & 0x3f);
  }
  else {
    puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,4);
    puVar7 = puVar6 + 4;
    *puVar6 = ((unsigned char *)0x00001041);
    puVar6[1] = (*(uint *)(param_1 + 0x27b0) | 1) << (*(uint *)(param_1 + 0x1938) & 0x3f);
    iVar9 = *(int *)(param_1 + 0x1938);
    puVar6[3] = 0;
    puVar6[2] = ((unsigned char *)0x00001100) + iVar9;
  }
  pcVar3 = *(code **)(param_1 + 0x275c);
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar7;
  (*pcVar3)(param_1,puVar7);
  if (uVar12 == 0) {
    *(undefined4 *)(param_1 + 0x1934) = 0;
  }
  else {
    puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xde);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar7;
    puVar6 = puVar7;
    if ((uVar12 & 0x100) != 0) {
      puVar6 = puVar7 + 2;
      *puVar7 = ((unsigned char *)0x00001393);
      puVar7[1] = 10;
    }
    if ((uVar12 & 0x2000000) != 0) {
      *puVar6 = ((unsigned char *)0x000013c6);
      puVar6[1] = 3;
      puVar6 = puVar6 + 2;
    }
    if ((uVar12 & 1) != 0) {
      *puVar6 = 0x212f2;
      puVar6[1] = *(undefined4 *)(param_1 + 0x1a54);
      puVar6[2] = *(undefined4 *)(param_1 + 0x1a58);
      puVar1 = PTR_DAT_001e88c8;
      uVar2 = *(undefined4 *)(param_1 + 0x1a5c);
      puVar6[4] = ((unsigned char *)0x000012f0);
      puVar6[3] = uVar2;
      uVar4 = *(uint *)(param_1 + 0x1aec);
      puVar6[5] = uVar4;
      if ((*(uint *)(puVar1 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
        puVar6[5] = uVar4 & 0xfffffffe;
      }
      puVar6[6] = 0x110a5;
      puVar6[7] = *(undefined4 *)(param_1 + 0x1a7c);
      uVar2 = *(undefined4 *)(param_1 + 0x1a78);
      puVar6[9] = ((unsigned char *)0x00001007);
      puVar6[8] = uVar2;
      puVar6[10] = *(undefined4 *)(param_1 + 0x1a64);
      puVar6 = puVar6 + 0xb;
    }
    puVar1 = PTR_DAT_001e88c8;
    if ((uVar12 & 4) != 0) {
      *puVar6 = 0x11381;
      uVar4 = *(uint *)(param_1 + 0x1a80);
      puVar6[1] = uVar4;
      if ((*(uint *)(puVar1 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x4000) == 0) {
        puVar6[1] = uVar4 & 0xfffffffc;
      }
      uVar2 = *(undefined4 *)(param_1 + 0x1a84);
      puVar6[3] = ((unsigned char *)0x00001384);
      puVar6[2] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1a88);
      puVar6[5] = ((unsigned char *)0x00001394);
      puVar6[4] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1af0);
      puVar6[7] = ((unsigned char *)0x000013be);
      puVar6[6] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1a8c);
      puVar6[9] = ((unsigned char *)0x000013bf);
      puVar6[8] = uVar2;
      puVar6[10] = *(undefined4 *)(param_1 + 0x1a90);
      puVar6 = puVar6 + 0xb;
    }
    if ((uVar12 & 0x10000) != 0) {
      *puVar6 = ((unsigned char *)0x00001386);
      puVar6[1] = *(undefined4 *)(param_1 + 0x1af8);
      puVar6 = puVar6 + 2;
    }
    if ((uVar12 & 0x200) != 0) {
      *puVar6 = ((unsigned char *)0x000012f5);
      puVar1 = PTR_DAT_001e88c8;
      uVar4 = *(uint *)(param_1 + 0x1a4c);
      puVar6[1] = uVar4;
      if ((*(uint *)(puVar1 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x18) & 0x8000) == 0) {
        puVar6[1] = uVar4 & 0xfffff7ff;
      }
      puVar6[2] = ((unsigned char *)0x000012f8);
      puVar6[3] = *(undefined4 *)(param_1 + 0x1bdc);
      puVar6 = puVar6 + 4;
    }
    if ((uVar12 & 0x8000000) != 0) {
      *puVar6 = ((unsigned char *)0x000012f6);
      puVar6[1] = *(undefined4 *)(param_1 + 0x1a50);
      puVar6 = puVar6 + 2;
    }
    puVar7 = puVar6;
    if ((uVar12 & 0x20000) != 0) {
      puVar7 = puVar6 + 2;
      *puVar6 = ((unsigned char *)0x000013c5);
      puVar6[1] = *(undefined4 *)(param_1 + 0x1ab8);
      if (1 < *(int *)(param_1 + 0x23dc)) {
        puVar7 = puVar6 + 4;
        puVar6[2] = ((unsigned char *)0x000010e6);
        puVar6[3] = *(undefined4 *)(param_1 + 0x1bd4);
      }
    }
    if ((uVar12 & 0x800) != 0) {
      *puVar7 = 0x113c0;
      puVar7[1] = *(undefined4 *)(param_1 + 0x1aa0);
      puVar7[2] = *(undefined4 *)(param_1 + 0x1aa4);
      puVar7 = puVar7 + 3;
    }
    if ((uVar12 & 8) != 0) {
      *puVar7 = ((unsigned char *)0x000013c2);
      puVar7[1] = *(undefined4 *)(param_1 + 0x1aa8);
      puVar7 = puVar7 + 2;
    }
    if ((uVar12 & 0x1000) != 0) {
      iVar9 = *(int *)(param_1 + 4);
      puVar5 = *(uint **)(iVar9 + 0x1d8);
      *puVar5 = (int)puVar7 - (int)puVar5 >> 2 | *puVar5;
      *(undefined4 **)(iVar9 + 0x1d8) = puVar7;
      *puVar7 = 0x2f000000;
      puVar7[1] = (*(unsigned char *)0x000010e9);
      uVar2 = *(undefined4 *)(param_1 + 0x1ae0);
      puVar7[3] = ((unsigned char *)0x000013c7);
      puVar7[2] = uVar2;
      puVar7[4] = *(undefined4 *)(param_1 + 0x1ab0);
      puVar7 = puVar7 + 5;
    }
    if ((uVar12 & 0x20) != 0) {
      *puVar7 = 0x410a9;
      puVar7[1] = *(undefined4 *)(param_1 + 0x1b1c);
      puVar7[2] = *(undefined4 *)(param_1 + 0x1b18);
      puVar7[3] = *(undefined4 *)(param_1 + 0x1b24);
      puVar7[4] = *(undefined4 *)(param_1 + 0x1b20);
      puVar7[5] = *(undefined4 *)(0x00001b14 + param_1);
      puVar7 = puVar7 + 6;
    }
    if ((uVar12 & 0x2000) != 0) {
      *puVar7 = ((unsigned char *)0x000010a2);
      uVar2 = *(undefined4 *)(param_1 + 0x1b3c);
      puVar7[2] = ((unsigned char *)0x00001002);
      puVar7[1] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1b50);
      puVar7[4] = ((unsigned char *)0x00001007);
      puVar7[3] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1a64);
      puVar7[6] = 0x825;
      puVar7[5] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
      puVar7[8] = ((unsigned char *)0x00001048);
      puVar7[7] = uVar2;
      puVar7[9] = *(undefined4 *)(param_1 + 0x1bc0);
      puVar7 = puVar7 + 10;
    }
    if ((uVar12 & 0x8000) != 0) {
      *puVar7 = ((unsigned char *)0x00001087);
      uVar2 = *(undefined4 *)(param_1 + 0x1ccc);
      puVar7[2] = 0x31080;
      puVar7[1] = uVar2;
      puVar7[3] = *(undefined4 *)(param_1 + 0x1cbc);
      puVar7[4] = *(undefined4 *)(param_1 + 0x1cc4);
      puVar7[5] = *(undefined4 *)(param_1 + 0x1cc0);
      uVar2 = *(undefined4 *)(param_1 + 0x1cc8);
      puVar7[7] = ((unsigned char *)0x0000108c);
      puVar7[6] = uVar2;
      puVar7[8] = *(undefined4 *)(param_1 + 0x1cd0);
      puVar7 = puVar7 + 9;
    }
    if ((uVar12 & 0x4000) != 0) {
      *puVar7 = 0x1108d;
      puVar7[1] = *(undefined4 *)(param_1 + 0x1b40);
      uVar2 = *(undefined4 *)(param_1 + 0x1b64);
      puVar7[3] = ((unsigned char *)0x0000109a);
      puVar7[2] = uVar2;
      puVar7[4] = *(undefined4 *)(param_1 + 0x1b70);
      puVar7 = puVar7 + 5;
    }
    if ((uVar12 & 0x10) != 0) {
      *puVar7 = ((unsigned char *)0x00001383);
      uVar2 = *(undefined4 *)(0x00001af4 + param_1);
      puVar7[2] = ((unsigned char *)0x0000109e);
      puVar7[1] = uVar2;
      puVar7[3] = *(undefined4 *)(param_1 + 0x1b2c);
      puVar7 = puVar7 + 4;
    }
    if ((uVar12 & 0x40) != 0) {
      *puVar7 = 0x311a9;
      puVar7[1] = *(undefined4 *)(param_1 + 0x233c);
      puVar7[2] = *(undefined4 *)(param_1 + 0x2340);
      puVar7[3] = *(undefined4 *)(param_1 + 0x2344);
      uVar2 = *(undefined4 *)(0x00002348 + param_1);
      puVar7[5] = ((unsigned char *)0x000010b1);
      puVar7[4] = uVar2;
      uVar2 = *(undefined4 *)(0x00001b34 + param_1);
      puVar7[7] = ((unsigned char *)0x000010b0);
      puVar7[6] = uVar2;
      puVar7[8] = *(undefined4 *)(param_1 + 0x1b38);
      puVar7 = puVar7 + 9;
    }
    if ((uVar12 & 0x400) != 0) {
      *puVar7 = ((unsigned char *)0x000010ae);
      puVar7[1] = *(undefined4 *)(param_1 + 0x1b30);
      puVar7 = puVar7 + 2;
    }
    if ((uVar12 & 0x80000) != 0) {
      *puVar7 = ((unsigned char *)0x00001008);
      uVar2 = *(undefined4 *)(param_1 + 0x1a60);
      puVar7[2] = 0x11004;
      puVar7[1] = uVar2;
      puVar7[3] = *(undefined4 *)(param_1 + 0x1a68);
      uVar2 = *(undefined4 *)(param_1 + 0x1a6c);
      puVar7[5] = ((unsigned char *)0x000010fa);
      puVar7[4] = uVar2;
      puVar7[6] = *(undefined4 *)(param_1 + 0x1b60);
      puVar7 = puVar7 + 7;
    }
    if ((uVar12 & 2) != 0) {
      puVar7 = (undefined4 *)((int (*)())FUN_0004dd10)(param_1,puVar7);
    }
    if ((uVar12 & 0x80) != 0) {
      puVar7 = (undefined4 *)((int (*)())FUN_0004dd40)(param_1,puVar7);
    }
    puVar6 = puVar7;
    if ((uVar12 & 0x40000) != 0) {
      puVar6 = puVar7 + 10;
      *puVar7 = 0x10860;
      puVar7[1] = *(undefined4 *)(param_1 + 0x1b78);
      uVar2 = *(undefined4 *)(param_1 + 0x1ca0);
      puVar7[3] = 0x82d;
      puVar7[2] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1ca4);
      puVar7[5] = 0x10824;
      puVar7[4] = uVar2;
      puVar7[6] = *(undefined4 *)(param_1 + 0x1b9c);
      uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
      puVar7[8] = ((unsigned char *)0x00001047);
      puVar7[7] = uVar2;
      puVar7[9] = *(undefined4 *)(param_1 + 0x1bb0);
      if ((-1 < (int)uVar12) || (*(char *)(param_1 + 0x1868) != '\0')) {
        iVar16 = 8;
        puVar7[10] = ((unsigned char *)0x000010c0);
        iVar10 = 0;
        puVar7[0xb] = *(undefined4 *)(param_1 + 0x1f2c);
        puVar7[0xc] = *(uint *)(param_1 + 0x1f28) | 0x70000;
        iVar9 = param_1;
        do {
          puVar6 = (undefined4 *)(iVar9 + 0x1ee8);
          iVar9 = iVar9 + 4;
          *(undefined4 *)((int)puVar7 + iVar10 + 0x34) = *puVar6;
          iVar10 = iVar10 + 4;
          iVar16 = iVar16 + -1;
        } while (iVar16 != 0);
        puVar6 = puVar7 + 0x15;
      }
    }
    if ((uVar12 & 0x400000) != 0) {
      *puVar6 = 0x887;
      puVar6[1] = *(undefined4 *)(param_1 + 0x1b74);
      puVar6 = puVar6 + 2;
    }
    if ((uVar12 & 0x800000) != 0) {
      *puVar6 = ((unsigned char *)0x00001002);
      uVar2 = *(undefined4 *)(param_1 + 0x1b50);
      puVar6[2] = 0x825;
      puVar6[1] = uVar2;
      uVar2 = *(undefined4 *)(param_1 + 0x1ba0);
      puVar6[4] = ((unsigned char *)0x00001048);
      puVar6[3] = uVar2;
      puVar6[5] = *(undefined4 *)(param_1 + 0x1bc0);
      puVar6 = puVar6 + 6;
    }
    if ((uVar12 & 0x4000000) != 0) {
      *(undefined4 *)(param_1 + 0x1e68) = 0;
    }
    if ((uVar12 & 0x10000000) != 0) {
      *puVar6 = 0x413de;
      puVar6[1] = *(undefined4 *)(param_1 + 0x2360);
      puVar6[2] = *(undefined4 *)(param_1 + 0x2364);
      puVar6[3] = *(undefined4 *)(0x00002368 + param_1);
      puVar6[4] = *(undefined4 *)(param_1 + 0x236c);
      uVar2 = *(undefined4 *)(param_1 + 0x2370);
      puVar6[6] = 0x313e9;
      puVar6[5] = uVar2;
      puVar6[7] = *(undefined4 *)(param_1 + 0x2374);
      puVar6[8] = *(undefined4 *)(param_1 + 0x2378);
      puVar6[9] = *(undefined4 *)(param_1 + 0x237c);
      puVar6[10] = *(undefined4 *)(param_1 + 0x2380);
      puVar6 = puVar6 + 0xb;
    }
    if ((uVar12 & 0x20000000) != 0) {
      *puVar6 = ((unsigned char *)0x000813ad);
      puVar6[1] = *(undefined4 *)(param_1 + 0x2384);
      puVar6[2] = *(undefined4 *)(0x00002388 + param_1);
      puVar6[3] = *(undefined4 *)(param_1 + 0x238c);
      puVar6[4] = *(undefined4 *)(param_1 + 0x2390);
      puVar6[5] = *(undefined4 *)(param_1 + 0x2394);
      puVar6[6] = *(undefined4 *)(param_1 + 0x2398);
      puVar6[7] = *(undefined4 *)(param_1 + 0x239c);
      puVar6[8] = *(undefined4 *)(param_1 + 0x23a0);
      puVar6[9] = *(undefined4 *)(param_1 + 0x23a4);
      puVar6 = puVar6 + 10;
    }
    uVar12 = (uint)-(int)puVar6 >> 2 & 0xf;
    puVar7 = puVar6;
    for (uVar4 = uVar12; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = 0x80000000;
      puVar7 = puVar7 + 1;
    }
    pcVar3 = *(code **)(param_1 + 0x275c);
    *(undefined4 **)(0x00002748 + param_1 + 4) = puVar6 + uVar12;
    (*pcVar3)(param_1,puVar6 + uVar12);
    uVar4 = *(uint *)(param_1 + 0x1930);
    if ((uVar4 & 0xc0100000) != 0) {
      (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,0xc0100000);
      uVar4 = *(uint *)(param_1 + 0x1930);
    }
    if ((uVar4 & 0x200000) != 0) {
      FUN_00086710(param_1);
      uVar4 = *(uint *)(param_1 + 0x1930);
    }
    if ((uVar4 & 0x1000000) != 0) {
      FUN_00086840(param_1);
    }
    *(undefined4 *)(param_1 + 0x1934) = 0;
    *(undefined4 *)(param_1 + 0x1930) = 0;
  }
  return;
}

/* FUN_00052cc0 @ 0x52cc0 (372 bytes) */
int FUN_00052cc0(param_1)
  int param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  
  puVar2 = PTR_FUN_001e89b8;
  puVar1 = PTR_FUN_001e89b0;
  uVar3 = 0;
  if (param_1 != -0x1168) {
    if (*(char *)(param_1 + 0x1868) == '\0') {
      *(undefined **)(((unsigned char *)0x000011a0) + param_1) = PTR_FUN_001e89c4;
      *(undefined **)(((unsigned char *)0x000011a8) + param_1) = puVar2;
      puVar1 = PTR_FUN_001e89d8;
      *(undefined **)(((unsigned char *)0x000011a4) + param_1) = PTR_FUN_001e89c8;
      *(undefined **)(((unsigned char *)0x000011b0) + param_1) = puVar1;
      puVar1 = PTR_FUN_001e89a8;
      *(undefined **)(((unsigned char *)0x000011ac) + param_1) = PTR_LAB_001e89cc;
      *(undefined **)(((unsigned char *)0x00001190) + param_1) = puVar1;
      puVar1 = PTR_FUN_001e89e8;
      *(undefined **)(((unsigned char *)0x00001194) + param_1) = PTR_FUN_001e89b4;
      *(undefined **)(((unsigned char *)0x0000119c) + param_1) = puVar1;
      *(undefined **)(((unsigned char *)0x00001198) + param_1) = PTR_FUN_001e89a4;
    }
    else {
      *(undefined **)(((unsigned char *)0x000011a0) + param_1) = PTR_FUN_001e89bc;
      *(undefined **)(((unsigned char *)0x000011a8) + param_1) = puVar1;
      puVar1 = PTR_FUN_001e89d8;
      *(undefined **)(((unsigned char *)0x000011a4) + param_1) = PTR_FUN_001e89d0;
      *(undefined **)(((unsigned char *)0x000011b0) + param_1) = puVar1;
      puVar1 = PTR_FUN_001e89a0;
      *(undefined **)(((unsigned char *)0x000011ac) + param_1) = PTR_LAB_001e89d4;
      *(undefined **)(((unsigned char *)0x00001190) + param_1) = puVar1;
      puVar1 = PTR_FUN_001e89dc;
      *(undefined **)(((unsigned char *)0x00001194) + param_1) = PTR_FUN_001e89e4;
      *(undefined **)(((unsigned char *)0x0000119c) + param_1) = puVar1;
      *(undefined **)(((unsigned char *)0x00001198) + param_1) = PTR_FUN_001e89c0;
    }
    puVar1 = PTR_FUN_001e89ac;
    if (*(char *)(param_1 + 0x1868) == '\0') {
      *(undefined4 *)(((unsigned char *)0x00001354) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x0000134c) + param_1) = 0;
      *(undefined **)(((unsigned char *)0x00001350) + param_1) = PTR_FUN_001e89e0;
    }
    else {
      *(undefined4 *)(((unsigned char *)0x00001354) + param_1) = 0;
      *(undefined4 *)(((unsigned char *)0x0000134c) + param_1) = 0;
      *(undefined **)(((unsigned char *)0x00001350) + param_1) = puVar1;
    }
    ((unsigned char *)0x000013b0)[param_1] = 8;
    FUN_00054b20(param_1);
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_00052e60 @ 0x52e60 (112 bytes) */
int FUN_00052e60(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  undefined4 uVar1;
  
  *(undefined4 *)(0x00002748 + param_1 + 4) = param_2;
  *(uint *)(param_1 + 0x44) =
       (param_3 & 1) << 0x13 | (param_3 & 1) << 0x14 | *(uint *)(param_1 + 0x44) & 0xffe7ffff;
  if (*(char *)(param_1 + 0x1868) == '\0') {
    FUN_00064f40(param_1,param_2);
  }
  else {
    (**(code **)((int)((unsigned char *)0x000011cc) + param_1))(param_1);
  }
  uVar1 = *(undefined4 *)(0x00002748 + param_1 + 4);
  *(undefined1 *)(param_1 + 0x2d) = 0;
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
  iVar1 = FUN_00054da0(iVar2,param_2);
  if (iVar1 == 0) {
    iVar2 = *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x14;
    iVar1 = FUN_00054da0(iVar2,param_2);
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
  iVar1 = FUN_00054da0(iVar2,param_2);
  if (iVar1 == 0) {
    iVar2 = *(int *)(((unsigned char *)0x0000116c) + param_1) + 0x14;
    iVar1 = FUN_00054da0(iVar2,param_2);
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
int FUN_00053000(param_1, param_2)
  int param_1;
  uint param_2;
{
  byte bVar1;
  
  bVar1 = 0xc;
  if ((param_2 & 2) == 0) {
    bVar1 = 0;
  }
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x1000;
  *(byte *)(param_1 + 0x2d) = bVar1 | *(byte *)(param_1 + 0x2d);
  *(undefined1 *)(param_1 + 0x29) = 1;
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

/* FUN_00053060 @ 0x53060 (4 bytes) */
int FUN_00053060()
{
  return;
}

/* FUN_00053070 @ 0x53070 (36 bytes) */
int FUN_00053070(param_1)
  int param_1;
{
  if ((*(int *)(((unsigned char *)0x00001168) + param_1) != 0) &&
     (*(char *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0x10) != '\0')) {
    return 1;
  }
  return 0;
}

/* FUN_000530a0 @ 0x530a0 (24 bytes) */
int FUN_000530a0(param_1)
  int param_1;
{
  if (*(int *)(((unsigned char *)0x00001168) + param_1) == 0) {
    return;
  }
  *(undefined1 *)(*(int *)(((unsigned char *)0x00001168) + param_1) + 0x10) = 0;
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

/* FUN_00053220 @ 0x53220 (284 bytes) */
int FUN_00053220(param_1, param_2, param_3, param_4, param_5, param_6)
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
      iVar2 = FUN_00055610(param_1,iVar4,param_4,param_5,0x87e1,0,0,param_3);
      if (iVar2 != 0) {
        iVar4 = FUN_00055a30(iVar4,iVar2);
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

/* FUN_00053340 @ 0x53340 (368 bytes) */
int FUN_00053340(param_1, param_2, param_3, param_4, param_5, param_6)
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
  uint uVar4;
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
    uVar5 = FUN_00055610(param_1,iVar3,param_2,param_3,param_4,0,param_5,param_6);
    if (1 < param_5) {
      uVar4 = 1;
      do {
        iVar1 = param_5 - uVar4;
        iVar2 = uVar4 + param_6;
        uVar4 = uVar4 + 1;
        FUN_00055610(param_1,iVar3,param_2,param_3,param_4,uVar5,iVar1,iVar2);
      } while (param_5 != uVar4);
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
  uVar2 = FUN_00055610(param_1,iVar1 + 0x1c,0x87bf,local_48[*param_3],0x87e1,0,param_2,*param_4);
  *param_5 = uVar2;
  if (1 < param_2) {
    uVar3 = 1;
    do {
      uVar4 = uVar3 + 1;
      uVar2 = FUN_00055610(param_1,iVar1 + 0x1c,0x87bf,local_48[param_3[uVar3]],0x87e1,*param_5,
                           param_2 - uVar3,param_4[uVar3]);
      param_5[uVar3] = uVar2;
      uVar3 = uVar4;
    } while (param_2 != uVar4);
  }
  return;
}

/* FUN_00053610 @ 0x53610 (136 bytes) */
int FUN_00053610(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (((unsigned char *)0x00001170)[param_1] != '\0') {
    FUN_000553c0(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,param_4,param_5,
                 param_6,0,&DAT_001db998,0,&DAT_001db998);
  }
  return;
}

/* FUN_000536a0 @ 0x536a0 (144 bytes) */
int FUN_000536a0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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
    FUN_000553c0(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,param_4,param_5,
                 param_6,param_7,param_8,0,&DAT_001db998);
  }
  return;
}

/* FUN_00053730 @ 0x53730 (132 bytes) */
int FUN_00053730(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
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
    FUN_000553c0(param_1,*(undefined4 *)(((unsigned char *)0x00001168) + param_1),param_2,param_3,param_4,param_5,
                 param_6,param_7,param_8,param_9,param_10);
  }
  return;
}

/* FUN_000537c0 @ 0x537c0 (276 bytes) */
int FUN_000537c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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
    iVar1 = FUN_000553c0(param_1,iVar2,0x879a,param_2,param_3,param_4,&iStack_38,0,&DAT_001db998,0,
                         &DAT_001db998);
    if ((iVar1 != 0) && (param_2 - 0x879dU < 0x10)) {
      *(undefined1 *)((param_2 - 0x879dU) + iVar2 + 0x44) = 1;
    }
  }
  return;
}

/* FUN_000538e0 @ 0x538e0 (164 bytes) */
int FUN_000538e0(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (((unsigned char *)0x00001170)[param_1] == '\0') {
    uVar1 = *(undefined4 *)(((unsigned char *)0x00001168) + param_1);
    ((unsigned char *)0x00001170)[param_1] = 1;
    FUN_00055300(param_1,uVar1);
    FUN_00055b50(param_1,uVar1);
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

/* FUN_00053990 @ 0x53990 (244 bytes) */
int FUN_00053990(param_1)
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
    FUN_000b9f10(param_1,a1);
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

/* FUN_00053a90 @ 0x53a90 (100 bytes) */
int FUN_00053a90(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 != 0) {
    if (param_2 == *(int *)(*(int *)(param_1 + 0xc) + 8)) {
      return 0;
    }
    piVar3 = (int *)(*(int *)(param_1 + 0xc) + 0x84);
    iVar2 = 0;
    while( true ) {
      iVar2 = iVar2 + 1;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) break;
      iVar1 = *piVar3;
      piVar3 = piVar3 + 0x1f;
      if (param_2 == iVar1) {
        return iVar2;
      }
    }
  }
  return -1;
}

/* FUN_00053b00 @ 0x53b00 (84 bytes) */
int FUN_00053b00(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(((unsigned char *)0x0000116c) + param_1);
  iVar2 = ((int (*)())FUN_00053a90)(iVar3,param_2);
  iVar1 = 0;
  if (-1 < iVar2) {
    iVar1 = iVar2 * 0x7c + *(int *)(iVar3 + 0xc);
  }
  return iVar1;
}

/* FUN_00053b60 @ 0x53b60 (568 bytes) */
int FUN_00053b60(param_1, param_2)
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
    iVar2 = ((int (*)())FUN_00053a90)(iVar6,param_2);
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
        FUN_00055d00(param_1);
        uVar1 = *(uint *)(iVar6 + 4);
      }
      FUN_00055b50(param_1,uVar1 * 0x7c + *(int *)(iVar6 + 0xc));
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
            (*(short *)("}J3x})+x|B;x}k" + *(int *)(*(int *)(param_1 + 4) + 0x10)) == -0x7e06)) ||
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

