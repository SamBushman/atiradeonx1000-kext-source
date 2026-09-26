#include "decls.h"

/* FUN_000b9f10 @ 0xb9f10 (11376 bytes) */
int FUN_000b9f10(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  char cVar2;
  char cVar3;
  char cVar4;
  bool bVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  int iVar13;
  byte bVar15;
  undefined4 *puVar14;
  uint uVar16;
  undefined4 *puVar17;
  int iVar18;
  undefined4 uVar19;
  int *piVar20;
  undefined4 uVar21;
  int iVar22;
  undefined4 uVar23;
  undefined4 uVar24;
  undefined4 uVar25;
  int iVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined4 uVar30;
  int iVar31;
  uint uVar32;
  uint uVar33;
  int iVar34;
  int iVar35;
  uint uVar36;
  undefined4 *puVar37;
  undefined4 *puVar38;
  int iStack00000018;
  char local_68;
  char local_67;
  char local_66;
  char local_65 [25];
  
  iVar31 = param_2 + 0x1c;
  uVar16 = *(uint *)(param_2 + 0x14);
  uVar8 = uVar16;
  iStack00000018 = param_1;
  if (uVar16 != 0) {
    iVar35 = uVar16 * 0x74;
    uVar32 = 0;
    do {
      iVar9 = *(int *)(param_2 + 0x18);
      uVar36 = uVar16 - uVar32;
      iVar13 = iVar35 + iVar9;
      cVar2 = *(char *)(iVar13 + -0x61);
      cVar3 = *(char *)(iVar13 + -0x5d);
      cVar4 = *(char *)(iVar13 + -0x59);
      bVar1 = *(char *)(iVar13 + -0x65) == '\0';
      if ((((bVar1) && (cVar2 == '\0')) && (cVar3 == '\0')) && (cVar4 == '\0')) {
LAB_000ba610:
        iVar9 = iVar35;
        if (uVar36 < uVar8) {
          do {
            uVar36 = uVar36 + 1;
            iVar13 = iVar9 + *(int *)(param_2 + 0x18);
            _memcpy(iVar13 + -0x74,iVar13,0x74);
            uVar8 = *(uint *)(param_2 + 0x14);
            iVar9 = iVar9 + 0x74;
          } while (uVar36 < uVar8);
        }
        uVar8 = uVar8 - 1;
        *(uint *)(param_2 + 0x14) = uVar8;
      }
      else {
        iVar18 = *(int *)(iVar13 + -0x70);
        if (iVar18 == 1) {
          if (uVar36 < uVar8) {
            iVar9 = uVar8 - uVar36;
            piVar20 = (int *)(iVar13 + 4);
            bVar12 = 0;
            bVar15 = 0;
            bVar11 = 0;
            bVar10 = 0;
            do {
              if ((*piVar20 == 1) && (piVar20[1] == *(int *)(iVar13 + -0x6c))) {
                bVar15 = bVar15 | *(byte *)((int)piVar20 + 0xb);
                bVar12 = bVar12 | *(byte *)((int)piVar20 + 0xf);
                bVar11 = bVar11 | *(byte *)((int)piVar20 + 0x13);
                bVar10 = bVar10 | *(byte *)((int)piVar20 + 0x17);
              }
              piVar20 = piVar20 + 0x1d;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          else {
            bVar15 = 0;
            bVar12 = 0;
            bVar11 = 0;
            bVar10 = 0;
          }
          if ((((bVar1) || (bVar15 != 0)) && ((cVar2 == '\0' || (bVar12 != 0)))) &&
             (((cVar3 == '\0' || (bVar11 != 0)) && ((cVar4 == '\0' || (bVar10 != 0))))))
          goto LAB_000ba610;
        }
        else {
          if (*(int *)(iVar13 + -0x74) == 0x87a2) {
            if (uVar36 < uVar8) {
              iVar9 = uVar8 - uVar36;
              pcVar7 = (char *)(iVar13 + 0x38);
              bVar5 = true;
              bVar12 = 0;
              bVar11 = 0;
              bVar10 = 0;
              bVar15 = 0;
              do {
                if (((*pcVar7 != '\0') || (pcVar7[0x1c] != '\0')) || (pcVar7[0x38] != '\0')) {
                  bVar5 = false;
                }
                if ((*(int *)(pcVar7 + -0x34) == 2) &&
                   (*(int *)(pcVar7 + -0x30) == *(int *)(iVar13 + -0x6c))) {
                  bVar12 = bVar12 | pcVar7[-0x29];
                  bVar11 = bVar11 | pcVar7[-0x25];
                  bVar10 = bVar10 | pcVar7[-0x21];
                  bVar15 = bVar15 | pcVar7[-0x1d];
                }
                pcVar7 = pcVar7 + 0x74;
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
            else {
              bVar5 = true;
              bVar12 = 0;
              bVar11 = 0;
              bVar10 = 0;
              bVar15 = 0;
            }
            if (((((((bVar1) || (bVar12 != 0)) && ((cVar2 == '\0' || (bVar11 != 0)))) &&
                  ((cVar3 == '\0' || (bVar10 != 0)))) && ((cVar4 == '\0' || (bVar15 != 0)))) &&
                (bVar5)) || (uVar8 <= uVar36)) goto LAB_000ba610;
            iVar9 = uVar8 - uVar36;
            pcVar7 = (char *)(iVar13 + 0x38);
            bVar5 = true;
            do {
              if (((*pcVar7 != '\0') || (pcVar7[0x1c] != '\0')) || (pcVar7[0x38] != '\0')) {
                bVar5 = false;
              }
              pcVar7 = pcVar7 + 0x74;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
          else {
            if (*(char *)(param_2 + 0x7b) == '\0') {
              if (iVar18 == 2) {
                iVar18 = *(int *)(iVar13 + -0x6c);
                iVar22 = *(int *)(param_2 + 0x20);
                goto LAB_000ba1a0;
              }
            }
            else if (iVar18 == 2) {
              iVar18 = *(int *)(iVar13 + -0x6c);
              iVar22 = *(int *)(param_2 + 0x20);
              if (*(int *)(iVar18 * 0x54 + iVar22 + 0x28) == 0x87c4) goto LAB_000ba664;
LAB_000ba1a0:
              if (*(int *)(iVar18 * 0x54 + iVar22 + 0x24) == 0x87c0) goto LAB_000ba664;
            }
            if (uVar36 < uVar8) {
              bVar10 = 0;
              bVar11 = 0;
              bVar12 = 0;
              bVar15 = 0;
              bVar5 = true;
              iVar18 = iVar35;
              uVar33 = uVar36;
              while( true ) {
                iVar9 = iVar18 + iVar9;
                if ((((*(int *)(iVar9 + 0x20) == 2) &&
                     (iVar22 = *(int *)(iVar13 + -0x6c), *(int *)(iVar9 + 0x24) == iVar22)) ||
                    ((*(int *)(iVar9 + 0x3c) == 2 &&
                     (iVar22 = *(int *)(iVar13 + -0x6c), *(int *)(iVar9 + 0x40) == iVar22)))) ||
                   ((*(int *)(iVar9 + 0x58) == 2 &&
                    (iVar22 = *(int *)(iVar13 + -0x6c), *(int *)(iVar9 + 0x5c) == iVar22)))) {
                  FUN_000b72d0(iVar31,iVar9,iVar22,&local_68,&local_67,&local_66,local_65);
                  if (((((bVar1) || ((local_68 == '\0' || (bVar15 != 0)))) &&
                       ((cVar2 == '\0' || ((local_67 == '\0' || (bVar12 != 0)))))) &&
                      ((cVar3 == '\0' || ((local_66 == '\0' || (bVar11 != 0)))))) &&
                     ((cVar4 == '\0' || ((local_65[0] == '\0' || (bVar10 != 0)))))) {
                    uVar8 = *(uint *)(param_2 + 0x14);
                  }
                  else {
                    uVar8 = *(uint *)(param_2 + 0x14);
                    bVar5 = false;
                  }
                }
                if ((*(int *)(iVar9 + 4) == 2) && (*(int *)(iVar9 + 8) == *(int *)(iVar13 + -0x6c)))
                {
                  bVar10 = bVar10 | *(byte *)(iVar9 + 0x1b);
                  bVar15 = bVar15 | *(byte *)(iVar9 + 0xf);
                  bVar12 = bVar12 | *(byte *)(iVar9 + 0x13);
                  bVar11 = bVar11 | *(byte *)(iVar9 + 0x17);
                }
                uVar33 = uVar33 + 1;
                iVar18 = iVar18 + 0x74;
                if (uVar8 <= uVar33) break;
                iVar9 = *(int *)(param_2 + 0x18);
              }
            }
            else {
              bVar5 = true;
              bVar15 = 0;
              bVar12 = 0;
              bVar11 = 0;
              bVar10 = 0;
            }
            if (((((bVar1) || (bVar15 != 0)) && ((cVar2 == '\0' || (bVar12 != 0)))) &&
                ((((cVar3 == '\0' || (bVar11 != 0)) && ((cVar4 == '\0' || (bVar10 != 0)))) &&
                 (bVar5)))) || (uVar8 <= uVar36)) goto LAB_000ba610;
            bVar5 = true;
            bVar11 = 0;
            bVar12 = 0;
            bVar15 = 0;
            bVar10 = 0;
            iVar9 = iVar35;
            uVar33 = uVar36;
            do {
              iVar18 = iVar9 + *(int *)(param_2 + 0x18);
              if ((((*(int *)(iVar18 + 0x20) == 2) &&
                   (iVar22 = *(int *)(iVar13 + -0x6c), *(int *)(iVar18 + 0x24) == iVar22)) ||
                  ((*(int *)(iVar18 + 0x3c) == 2 &&
                   (iVar22 = *(int *)(iVar13 + -0x6c), *(int *)(iVar18 + 0x40) == iVar22)))) ||
                 ((*(int *)(iVar18 + 0x58) == 2 &&
                  (iVar22 = *(int *)(iVar13 + -0x6c), *(int *)(iVar18 + 0x5c) == iVar22)))) {
                FUN_000b72d0(iVar31,iVar18,iVar22,&local_68,&local_67,&local_66,local_65);
                if ((((bVar1) || ((local_68 == '\0' || (bVar11 != 0)))) &&
                    (((cVar2 == '\0' || ((local_67 == '\0' || (bVar12 != 0)))) &&
                     ((cVar3 == '\0' || ((local_66 == '\0' || (bVar15 != 0)))))))) &&
                   ((cVar4 == '\0' || ((local_65[0] == '\0' || (bVar10 != 0)))))) {
                  uVar8 = *(uint *)(param_2 + 0x14);
                }
                else {
                  uVar8 = *(uint *)(param_2 + 0x14);
                  bVar5 = false;
                }
              }
              if ((*(int *)(iVar18 + 4) == 2) && (*(int *)(iVar18 + 8) == *(int *)(iVar13 + -0x6c)))
              {
                bVar10 = bVar10 | *(byte *)(iVar18 + 0x1b);
                bVar11 = bVar11 | *(byte *)(iVar18 + 0xf);
                bVar12 = bVar12 | *(byte *)(iVar18 + 0x13);
                bVar15 = bVar15 | *(byte *)(iVar18 + 0x17);
              }
              uVar33 = uVar33 + 1;
              iVar9 = iVar9 + 0x74;
            } while (uVar33 < uVar8);
          }
          if (bVar5) goto LAB_000ba610;
        }
      }
LAB_000ba664:
      uVar32 = uVar32 + 1;
      iVar35 = iVar35 + -0x74;
    } while (uVar16 != uVar32);
  }
  if (uVar8 != 0) {
    uVar16 = 0;
    do {
      iVar9 = uVar16 * 0x74;
      iVar35 = *(int *)(param_2 + 0x18);
      puVar38 = (undefined4 *)(iVar9 + iVar35);
      if ((((*(int *)(iVar9 + iVar35) == 0x8786) && (puVar38[1] == 2)) &&
          ((puVar38[3] != 0 && ((puVar38[4] != 0 && (puVar38[5] != 0)))))) &&
         ((puVar38[6] != 0 && (uVar36 = uVar16 + 1, uVar32 = uVar36, uVar36 < uVar8)))) {
        do {
          iVar13 = uVar32 * 0x74;
          puVar37 = (undefined4 *)(iVar35 + iVar13);
          if (*(int *)(iVar35 + iVar13) == 0x8787) {
            iVar18 = puVar37[8];
            if ((iVar18 != 2) || (iVar22 = puVar38[2], puVar37[9] != iVar22)) {
              if ((puVar37[0xf] != 2) || (iVar22 = puVar38[2], puVar37[0x10] != iVar22))
              goto LAB_000ba7ec;
              iVar34 = 2;
              if (iVar18 == 2) goto LAB_000ba7dc;
            }
            else {
              iVar34 = puVar37[0xf];
              if (iVar34 == 2) {
LAB_000ba7dc:
                if (puVar37[9] == puVar37[0x10]) goto LAB_000ba7ec;
              }
            }
            bVar1 = true;
            if (uVar36 < uVar32) {
              iVar6 = uVar32 - uVar36;
              piVar20 = (int *)(iVar35 + uVar36 * 0x74 + 0x20);
              do {
                if ((((*piVar20 == 2) && (piVar20[1] == iVar22)) ||
                    ((piVar20[7] == 2 && (piVar20[8] == iVar22)))) ||
                   ((((piVar20[0xe] == 2 && (piVar20[0xf] == iVar22)) ||
                     ((iVar26 = piVar20[-7], iVar26 == 2 && (piVar20[-6] == iVar22)))) ||
                    (((iVar26 == puVar38[8] && (piVar20[-6] == puVar38[9])) ||
                     ((iVar26 == puVar38[0xf] && (piVar20[-6] == puVar38[0x10])))))))) {
                  bVar1 = false;
                }
                piVar20 = piVar20 + 0x1d;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
              if (bVar1) goto LAB_000ba8a8;
LAB_000ba754:
              bVar1 = true;
              iVar6 = uVar32 - uVar36;
              piVar20 = (int *)(uVar36 * 0x74 + iVar35 + 0x20);
              if ((uVar32 < uVar16 + 2) || (uVar32 == 0)) {
                iVar6 = 1;
              }
              do {
                if ((((((*piVar20 == 2) && (piVar20[1] == iVar22)) ||
                      ((piVar20[7] == 2 && (piVar20[8] == iVar22)))) ||
                     ((piVar20[0xe] == 2 && (piVar20[0xf] == iVar22)))) ||
                    (((*piVar20 == 2 && (piVar20[1] == puVar37[2])) ||
                     ((((piVar20[7] == 2 && (piVar20[8] == puVar37[2])) ||
                       ((piVar20[0xe] == 2 && (piVar20[0xf] == puVar37[2])))) ||
                      ((iVar26 = piVar20[-7], iVar18 == iVar26 && (piVar20[-6] == puVar37[9]))))))))
                   || (((iVar26 == iVar34 && (piVar20[-6] == puVar37[0x10])) ||
                       ((iVar26 == puVar37[1] && (piVar20[-6] == puVar37[2])))))) {
                  bVar1 = false;
                }
                piVar20 = piVar20 + 0x1d;
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
              if (bVar1) {
LAB_000bc018:
                bVar1 = true;
                uVar33 = uVar32 + 1;
                if (uVar33 < uVar8) {
                  iVar6 = uVar8 - uVar33;
                  piVar20 = (int *)(iVar35 + uVar33 * 0x74 + 0x20);
                  do {
                    if ((((*piVar20 == 2) && (piVar20[1] == iVar22)) ||
                        ((piVar20[7] == 2 && (piVar20[8] == iVar22)))) ||
                       ((piVar20[0xe] == 2 && (piVar20[0xf] == iVar22)))) {
                      bVar1 = false;
                    }
                    piVar20 = piVar20 + 0x1d;
                    iVar6 = iVar6 + -1;
                  } while (iVar6 != 0);
                  if (!bVar1) goto LAB_000bd6dc;
                }
                iVar35 = puVar37[9];
                *puVar38 = 0x8788;
                if (iVar35 == iVar22) {
                  uVar21 = puVar37[0x10];
                  uVar25 = puVar37[0x11];
                  uVar19 = puVar37[0x12];
                  uVar27 = puVar37[0x13];
                  uVar23 = puVar37[0x14];
                  uVar30 = puVar37[0x15];
                  puVar38[0x16] = iVar34;
                  puVar38[0x17] = uVar21;
                  puVar38[0x18] = uVar25;
                  puVar38[0x19] = uVar19;
                  puVar38[0x1a] = uVar27;
                  puVar38[0x1b] = uVar23;
                  puVar38[0x1c] = uVar30;
                }
                else {
                  uVar21 = puVar37[10];
                  uVar25 = puVar37[0xb];
                  uVar29 = puVar37[0xc];
                  uVar28 = puVar37[0xd];
                  uVar24 = puVar37[0xe];
                  uVar27 = puVar37[0x11];
                  uVar23 = puVar37[0x12];
                  uVar19 = puVar37[0x13];
                  uVar30 = puVar37[0x14];
                  puVar38[0x16] = iVar18;
                  puVar38[0x17] = iVar35;
                  puVar38[0x18] = uVar21;
                  puVar38[0x19] = uVar25;
                  puVar38[0x1a] = uVar29;
                  puVar38[0x1b] = uVar28;
                  puVar38[0x1c] = uVar24;
                  puVar37[10] = uVar27;
                  puVar37[0xb] = uVar23;
                  puVar37[0xc] = uVar19;
                  puVar37[0xd] = uVar30;
                }
                uVar21 = puVar37[2];
                puVar14 = puVar37 + 0x11;
                uVar25 = puVar37[3];
                uVar30 = puVar37[4];
                puVar38[1] = puVar37[1];
                puVar38[2] = uVar21;
                puVar38[3] = uVar25;
                puVar38[4] = uVar30;
                uVar25 = puVar37[7];
                uVar21 = puVar37[5];
                puVar38[6] = puVar37[6];
                puVar38[7] = uVar25;
                puVar38[5] = uVar21;
                uVar21 = puVar37[10];
                switch(uVar21) {
                case 0x87d9:
                  uVar21 = 0x87d5;
                  break;
                case 0x87da:
                  uVar21 = 0x87d6;
                  break;
                case 0x87db:
                  uVar21 = 0x87d7;
                  break;
                case 0x87dc:
                  uVar21 = 0x87d8;
                  break;
                case 0x87df:
                  uVar21 = 0x87de;
                }
                uVar25 = puVar37[0xb];
                *puVar14 = uVar21;
                switch(uVar25) {
                case 0x87d9:
                  uVar25 = 0x87d5;
                  break;
                case 0x87da:
                  uVar25 = 0x87d6;
                  break;
                case 0x87db:
                  uVar25 = 0x87d7;
                  break;
                case 0x87dc:
                  uVar25 = 0x87d8;
                  break;
                case 0x87df:
                  uVar25 = 0x87de;
                }
                uVar21 = puVar37[0xc];
                puVar37[0x12] = uVar25;
                switch(uVar21) {
                case 0x87d9:
                  uVar21 = 0x87d5;
                  break;
                case 0x87da:
                  uVar21 = 0x87d6;
                  break;
                case 0x87db:
                  uVar21 = 0x87d7;
                  break;
                case 0x87dc:
                  uVar21 = 0x87d8;
                  break;
                case 0x87df:
                  uVar21 = 0x87de;
                }
                uVar25 = puVar37[0xd];
                puVar37[0x13] = uVar21;
                switch(uVar25) {
                case 0x87d9:
                  uVar25 = 0x87d5;
                  break;
                case 0x87da:
                  uVar25 = 0x87d6;
                  break;
                case 0x87db:
                  uVar25 = 0x87d7;
                  break;
                case 0x87dc:
                  uVar25 = 0x87d8;
                  break;
                case 0x87df:
                  uVar25 = 0x87de;
                }
                uVar21 = puVar37[10];
                puVar37[0x14] = uVar25;
                puVar17 = puVar38 + 10;
                switch(uVar21) {
                case 0x87d5:
                  uVar21 = *puVar17;
                  break;
                case 0x87d6:
                  uVar21 = puVar38[0xb];
                  break;
                case 0x87d7:
                  uVar21 = puVar38[0xc];
                  break;
                case 0x87d8:
                  uVar21 = puVar38[0xd];
                  break;
                case 0x87d9:
                  uVar21 = *puVar17;
                  switch(uVar21) {
                  case 0x87d5:
switchD_000bc544_caseD_87d5:
                    uVar21 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bc544_caseD_87d6:
                    uVar21 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bc544_caseD_87d7:
                    uVar21 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bc544_caseD_87d8:
                    uVar21 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bc544_caseD_87d9:
                    uVar21 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bc544_caseD_87da:
                    uVar21 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bc544_caseD_87db:
                    uVar21 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bc544_caseD_87dc:
                    uVar21 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bc544_caseD_87de:
                    uVar21 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bc544_caseD_87df:
                    uVar21 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar21 = puVar38[0xb];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bc544_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc544_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc544_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc544_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc544_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc544_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc544_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc544_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc544_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc544_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar21 = puVar38[0xc];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bc544_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc544_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc544_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc544_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc544_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc544_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc544_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc544_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc544_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc544_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar21 = puVar38[0xd];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bc544_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc544_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc544_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc544_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc544_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc544_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc544_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc544_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc544_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc544_caseD_87df;
                  }
                }
                uVar25 = puVar37[0xb];
                puVar37[10] = uVar21;
                switch(uVar25) {
                case 0x87d5:
                  uVar25 = *puVar17;
                  break;
                case 0x87d6:
                  uVar25 = puVar38[0xb];
                  break;
                case 0x87d7:
                  uVar25 = puVar38[0xc];
                  break;
                case 0x87d8:
                  uVar25 = puVar38[0xd];
                  break;
                case 0x87d9:
                  uVar25 = *puVar17;
                  switch(uVar25) {
                  case 0x87d5:
switchD_000bc79c_caseD_87d5:
                    uVar25 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bc79c_caseD_87d6:
                    uVar25 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bc79c_caseD_87d7:
                    uVar25 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bc79c_caseD_87d8:
                    uVar25 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bc79c_caseD_87d9:
                    uVar25 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bc79c_caseD_87da:
                    uVar25 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bc79c_caseD_87db:
                    uVar25 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bc79c_caseD_87dc:
                    uVar25 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bc79c_caseD_87de:
                    uVar25 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bc79c_caseD_87df:
                    uVar25 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar25 = puVar38[0xb];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bc79c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc79c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc79c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc79c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc79c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc79c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc79c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc79c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc79c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc79c_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar25 = puVar38[0xc];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bc79c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc79c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc79c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc79c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc79c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc79c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc79c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc79c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc79c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc79c_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar25 = puVar38[0xd];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bc79c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc79c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc79c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc79c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc79c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc79c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc79c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc79c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc79c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc79c_caseD_87df;
                  }
                }
                uVar21 = puVar37[0xc];
                puVar37[0xb] = uVar25;
                switch(uVar21) {
                case 0x87d5:
                  uVar21 = *puVar17;
                  break;
                case 0x87d6:
                  uVar21 = puVar38[0xb];
                  break;
                case 0x87d7:
                  uVar21 = puVar38[0xc];
                  break;
                case 0x87d8:
                  uVar21 = puVar38[0xd];
                  break;
                case 0x87d9:
                  uVar21 = *puVar17;
                  switch(uVar21) {
                  case 0x87d5:
switchD_000bc9f4_caseD_87d5:
                    uVar21 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bc9f4_caseD_87d6:
                    uVar21 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bc9f4_caseD_87d7:
                    uVar21 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bc9f4_caseD_87d8:
                    uVar21 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bc9f4_caseD_87d9:
                    uVar21 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bc9f4_caseD_87da:
                    uVar21 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bc9f4_caseD_87db:
                    uVar21 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bc9f4_caseD_87dc:
                    uVar21 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bc9f4_caseD_87de:
                    uVar21 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bc9f4_caseD_87df:
                    uVar21 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar21 = puVar38[0xb];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bc9f4_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc9f4_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc9f4_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc9f4_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc9f4_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc9f4_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc9f4_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc9f4_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc9f4_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc9f4_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar21 = puVar38[0xc];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bc9f4_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc9f4_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc9f4_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc9f4_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc9f4_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc9f4_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc9f4_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc9f4_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc9f4_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc9f4_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar21 = puVar38[0xd];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bc9f4_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc9f4_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc9f4_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc9f4_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc9f4_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc9f4_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc9f4_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc9f4_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc9f4_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc9f4_caseD_87df;
                  }
                }
                uVar25 = puVar37[0xd];
                puVar37[0xc] = uVar21;
                switch(uVar25) {
                case 0x87d5:
                  uVar25 = *puVar17;
                  break;
                case 0x87d6:
                  uVar25 = puVar38[0xb];
                  break;
                case 0x87d7:
                  uVar25 = puVar38[0xc];
                  break;
                case 0x87d8:
                  uVar25 = puVar38[0xd];
                  break;
                case 0x87d9:
                  uVar25 = *puVar17;
                  switch(uVar25) {
                  case 0x87d5:
switchD_000bcc4c_caseD_87d5:
                    uVar25 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bcc4c_caseD_87d6:
                    uVar25 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bcc4c_caseD_87d7:
                    uVar25 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bcc4c_caseD_87d8:
                    uVar25 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bcc4c_caseD_87d9:
                    uVar25 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bcc4c_caseD_87da:
                    uVar25 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bcc4c_caseD_87db:
                    uVar25 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bcc4c_caseD_87dc:
                    uVar25 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bcc4c_caseD_87de:
                    uVar25 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bcc4c_caseD_87df:
                    uVar25 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar25 = puVar38[0xb];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bcc4c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcc4c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcc4c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcc4c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcc4c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcc4c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcc4c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcc4c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcc4c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcc4c_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar25 = puVar38[0xc];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bcc4c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcc4c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcc4c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcc4c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcc4c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcc4c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcc4c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcc4c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcc4c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcc4c_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar25 = puVar38[0xd];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bcc4c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcc4c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcc4c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcc4c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcc4c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcc4c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcc4c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcc4c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcc4c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcc4c_caseD_87df;
                  }
                }
                uVar21 = *puVar14;
                puVar37[0xd] = uVar25;
                puVar17 = puVar38 + 0x11;
                switch(uVar21) {
                case 0x87d5:
                  uVar21 = *puVar17;
                  break;
                case 0x87d6:
                  uVar21 = puVar38[0x12];
                  break;
                case 0x87d7:
                  uVar21 = puVar38[0x13];
                  break;
                case 0x87d8:
                  uVar21 = puVar38[0x14];
                  break;
                case 0x87d9:
                  uVar21 = *puVar17;
                  switch(uVar21) {
                  case 0x87d5:
switchD_000bcea8_caseD_87d5:
                    uVar21 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bcea8_caseD_87d6:
                    uVar21 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bcea8_caseD_87d7:
                    uVar21 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bcea8_caseD_87d8:
                    uVar21 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bcea8_caseD_87d9:
                    uVar21 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bcea8_caseD_87da:
                    uVar21 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bcea8_caseD_87db:
                    uVar21 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bcea8_caseD_87dc:
                    uVar21 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bcea8_caseD_87de:
                    uVar21 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bcea8_caseD_87df:
                    uVar21 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar21 = puVar38[0x12];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bcea8_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcea8_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcea8_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcea8_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcea8_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcea8_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcea8_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcea8_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcea8_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcea8_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar21 = puVar38[0x13];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bcea8_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcea8_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcea8_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcea8_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcea8_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcea8_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcea8_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcea8_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcea8_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcea8_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar21 = puVar38[0x14];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bcea8_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcea8_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcea8_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcea8_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcea8_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcea8_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcea8_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcea8_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcea8_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcea8_caseD_87df;
                  }
                }
                uVar25 = puVar37[0x12];
                *puVar14 = uVar21;
                switch(uVar25) {
                case 0x87d5:
                  uVar25 = *puVar17;
                  break;
                case 0x87d6:
                  uVar25 = puVar38[0x12];
                  break;
                case 0x87d7:
                  uVar25 = puVar38[0x13];
                  break;
                case 0x87d8:
                  uVar25 = puVar38[0x14];
                  break;
                case 0x87d9:
                  uVar25 = *puVar17;
                  switch(uVar25) {
                  case 0x87d5:
switchD_000bd100_caseD_87d5:
                    uVar25 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bd100_caseD_87d6:
                    uVar25 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bd100_caseD_87d7:
                    uVar25 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bd100_caseD_87d8:
                    uVar25 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bd100_caseD_87d9:
                    uVar25 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bd100_caseD_87da:
                    uVar25 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bd100_caseD_87db:
                    uVar25 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bd100_caseD_87dc:
                    uVar25 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bd100_caseD_87de:
                    uVar25 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bd100_caseD_87df:
                    uVar25 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar25 = puVar38[0x12];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bd100_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd100_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd100_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd100_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd100_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd100_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd100_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd100_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd100_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd100_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar25 = puVar38[0x13];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bd100_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd100_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd100_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd100_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd100_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd100_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd100_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd100_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd100_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd100_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar25 = puVar38[0x14];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bd100_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd100_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd100_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd100_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd100_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd100_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd100_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd100_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd100_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd100_caseD_87df;
                  }
                }
                uVar21 = puVar37[0x13];
                puVar37[0x12] = uVar25;
                switch(uVar21) {
                case 0x87d5:
                  uVar21 = *puVar17;
                  break;
                case 0x87d6:
                  uVar21 = puVar38[0x12];
                  break;
                case 0x87d7:
                  uVar21 = puVar38[0x13];
                  break;
                case 0x87d8:
                  uVar21 = puVar38[0x14];
                  break;
                case 0x87d9:
                  uVar21 = *puVar17;
                  switch(uVar21) {
                  case 0x87d5:
switchD_000bd358_caseD_87d5:
                    uVar21 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bd358_caseD_87d6:
                    uVar21 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bd358_caseD_87d7:
                    uVar21 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bd358_caseD_87d8:
                    uVar21 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bd358_caseD_87d9:
                    uVar21 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bd358_caseD_87da:
                    uVar21 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bd358_caseD_87db:
                    uVar21 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bd358_caseD_87dc:
                    uVar21 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bd358_caseD_87de:
                    uVar21 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bd358_caseD_87df:
                    uVar21 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar21 = puVar38[0x12];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bd358_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd358_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd358_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd358_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd358_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd358_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd358_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd358_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd358_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd358_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar21 = puVar38[0x13];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bd358_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd358_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd358_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd358_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd358_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd358_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd358_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd358_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd358_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd358_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar21 = puVar38[0x14];
                  switch(uVar21) {
                  case 0x87d5:
                    goto switchD_000bd358_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd358_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd358_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd358_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd358_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd358_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd358_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd358_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd358_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd358_caseD_87df;
                  }
                }
                uVar25 = puVar37[0x14];
                puVar37[0x13] = uVar21;
                switch(uVar25) {
                case 0x87d5:
                  uVar25 = *puVar17;
                  break;
                case 0x87d6:
                  uVar25 = puVar38[0x12];
                  break;
                case 0x87d7:
                  uVar25 = puVar38[0x13];
                  break;
                case 0x87d8:
                  uVar25 = puVar38[0x14];
                  break;
                case 0x87d9:
                  uVar25 = *puVar17;
                  switch(uVar25) {
                  case 0x87d5:
switchD_000bd5b0_caseD_87d5:
                    uVar25 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bd5b0_caseD_87d6:
                    uVar25 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bd5b0_caseD_87d7:
                    uVar25 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bd5b0_caseD_87d8:
                    uVar25 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bd5b0_caseD_87d9:
                    uVar25 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bd5b0_caseD_87da:
                    uVar25 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bd5b0_caseD_87db:
                    uVar25 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bd5b0_caseD_87dc:
                    uVar25 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bd5b0_caseD_87de:
                    uVar25 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bd5b0_caseD_87df:
                    uVar25 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar25 = puVar38[0x12];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bd5b0_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd5b0_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd5b0_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd5b0_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd5b0_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd5b0_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd5b0_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd5b0_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd5b0_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd5b0_caseD_87df;
                  }
                  break;
                case 0x87db:
                  uVar25 = puVar38[0x13];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bd5b0_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd5b0_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd5b0_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd5b0_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd5b0_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd5b0_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd5b0_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd5b0_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd5b0_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd5b0_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  uVar25 = puVar38[0x14];
                  switch(uVar25) {
                  case 0x87d5:
                    goto switchD_000bd5b0_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd5b0_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd5b0_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd5b0_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd5b0_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd5b0_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd5b0_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd5b0_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd5b0_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd5b0_caseD_87df;
                  }
                }
                puVar37[0x14] = uVar25;
                uVar30 = puVar37[0x14];
                uVar21 = puVar37[10];
                uVar25 = puVar37[0xb];
                uVar23 = puVar37[0xc];
                uVar29 = puVar37[0xd];
                uVar27 = puVar37[0x11];
                uVar19 = puVar37[0x13];
                puVar38[0x12] = puVar37[0x12];
                puVar38[0x14] = uVar30;
                puVar38[10] = uVar21;
                puVar38[0xb] = uVar25;
                puVar38[0xc] = uVar23;
                puVar38[0xd] = uVar29;
                puVar38[0x11] = uVar27;
                puVar38[0x13] = uVar19;
                uVar8 = *(int *)(param_2 + 0x14) - 1;
                *(uint *)(param_2 + 0x14) = uVar8;
                uVar33 = uVar32;
                if (uVar32 < uVar8) {
                  do {
                    uVar33 = uVar33 + 1;
                    iVar35 = iVar13 + *(int *)(param_2 + 0x18);
                    iVar13 = iVar13 + 0x74;
                    _memcpy(iVar35,iVar35 + 0x74,0x74);
                    uVar8 = *(uint *)(param_2 + 0x14);
                  } while (uVar33 < uVar8);
                }
              }
LAB_000bd6dc:
              uVar32 = uVar32 + 1;
              bVar1 = true;
            }
            else {
LAB_000ba8a8:
              bVar1 = true;
              uVar33 = uVar32 + 1;
              if (uVar33 < uVar8) {
                iVar6 = uVar8 - uVar33;
                piVar20 = (int *)(iVar35 + uVar33 * 0x74 + 0x20);
                do {
                  if (((*piVar20 == 2) && (piVar20[1] == iVar22)) ||
                     (((piVar20[7] == 2 && (piVar20[8] == iVar22)) ||
                      ((piVar20[0xe] == 2 && (piVar20[0xf] == iVar22)))))) {
                    bVar1 = false;
                  }
                  piVar20 = piVar20 + 0x1d;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
                if (!bVar1) {
                  if (uVar36 < uVar32) goto LAB_000ba754;
                  goto LAB_000bc018;
                }
              }
              *puVar37 = 0x8788;
              if (puVar37[9] == iVar22) {
                uVar21 = puVar37[10];
                puVar37[0x16] = iVar34;
                puVar37[0x17] = puVar37[0x10];
                puVar37[0x18] = puVar37[0x11];
                puVar37[0x19] = puVar37[0x12];
                puVar37[0x1a] = puVar37[0x13];
                puVar37[0x1b] = puVar37[0x14];
                puVar37[0x1c] = puVar37[0x15];
              }
              else {
                puVar37[0x18] = puVar37[10];
                uVar21 = puVar37[0x11];
                puVar37[0x16] = iVar18;
                puVar37[0x17] = puVar37[9];
                puVar37[0x19] = puVar37[0xb];
                puVar37[0x1a] = puVar37[0xc];
                puVar37[0x1b] = puVar37[0xd];
                puVar37[0x1c] = puVar37[0xe];
                puVar37[0xb] = puVar37[0x12];
                puVar37[0xc] = puVar37[0x13];
                puVar37[0xd] = puVar37[0x14];
                puVar37[10] = uVar21;
              }
              puVar14 = puVar37 + 0x11;
              switch(uVar21) {
              case 0x87d9:
                uVar21 = 0x87d5;
                break;
              case 0x87da:
                uVar21 = 0x87d6;
                break;
              case 0x87db:
                uVar21 = 0x87d7;
                break;
              case 0x87dc:
                uVar21 = 0x87d8;
                break;
              case 0x87df:
                uVar21 = 0x87de;
              }
              uVar25 = puVar37[0xb];
              *puVar14 = uVar21;
              switch(uVar25) {
              case 0x87d9:
                uVar25 = 0x87d5;
                break;
              case 0x87da:
                uVar25 = 0x87d6;
                break;
              case 0x87db:
                uVar25 = 0x87d7;
                break;
              case 0x87dc:
                uVar25 = 0x87d8;
                break;
              case 0x87df:
                uVar25 = 0x87de;
              }
              uVar21 = puVar37[0xc];
              puVar37[0x12] = uVar25;
              switch(uVar21) {
              case 0x87d9:
                uVar21 = 0x87d5;
                break;
              case 0x87da:
                uVar21 = 0x87d6;
                break;
              case 0x87db:
                uVar21 = 0x87d7;
                break;
              case 0x87dc:
                uVar21 = 0x87d8;
                break;
              case 0x87df:
                uVar21 = 0x87de;
              }
              uVar25 = puVar37[0xd];
              puVar37[0x13] = uVar21;
              switch(uVar25) {
              case 0x87d9:
                uVar25 = 0x87d5;
                break;
              case 0x87da:
                uVar25 = 0x87d6;
                break;
              case 0x87db:
                uVar25 = 0x87d7;
                break;
              case 0x87dc:
                uVar25 = 0x87d8;
                break;
              case 0x87df:
                uVar25 = 0x87de;
              }
              puVar37[0x14] = uVar25;
              puVar17 = puVar38 + 10;
              puVar37[9] = puVar38[9];
              uVar21 = puVar37[10];
              switch(uVar21) {
              case 0x87d5:
                uVar21 = *puVar17;
                break;
              case 0x87d6:
                uVar21 = puVar38[0xb];
                break;
              case 0x87d7:
                uVar21 = puVar38[0xc];
                break;
              case 0x87d8:
                uVar21 = puVar38[0xd];
                break;
              case 0x87d9:
                uVar21 = *puVar17;
                switch(uVar21) {
                case 0x87d5:
switchD_000badac_caseD_87d5:
                  uVar21 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000badac_caseD_87d6:
                  uVar21 = 0x87da;
                  break;
                case 0x87d7:
switchD_000badac_caseD_87d7:
                  uVar21 = 0x87db;
                  break;
                case 0x87d8:
switchD_000badac_caseD_87d8:
                  uVar21 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000badac_caseD_87d9:
                  uVar21 = 0x87d5;
                  break;
                case 0x87da:
switchD_000badac_caseD_87da:
                  uVar21 = 0x87d6;
                  break;
                case 0x87db:
switchD_000badac_caseD_87db:
                  uVar21 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000badac_caseD_87dc:
                  uVar21 = 0x87d8;
                  break;
                case 0x87de:
switchD_000badac_caseD_87de:
                  uVar21 = 0x87df;
                  break;
                case 0x87df:
switchD_000badac_caseD_87df:
                  uVar21 = 0x87de;
                }
                break;
              case 0x87da:
                uVar21 = puVar38[0xb];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000badac_caseD_87d5;
                case 0x87d6:
                  goto switchD_000badac_caseD_87d6;
                case 0x87d7:
                  goto switchD_000badac_caseD_87d7;
                case 0x87d8:
                  goto switchD_000badac_caseD_87d8;
                case 0x87d9:
                  goto switchD_000badac_caseD_87d9;
                case 0x87da:
                  goto switchD_000badac_caseD_87da;
                case 0x87db:
                  goto switchD_000badac_caseD_87db;
                case 0x87dc:
                  goto switchD_000badac_caseD_87dc;
                case 0x87de:
                  goto switchD_000badac_caseD_87de;
                case 0x87df:
                  goto switchD_000badac_caseD_87df;
                }
                break;
              case 0x87db:
                uVar21 = puVar38[0xc];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000badac_caseD_87d5;
                case 0x87d6:
                  goto switchD_000badac_caseD_87d6;
                case 0x87d7:
                  goto switchD_000badac_caseD_87d7;
                case 0x87d8:
                  goto switchD_000badac_caseD_87d8;
                case 0x87d9:
                  goto switchD_000badac_caseD_87d9;
                case 0x87da:
                  goto switchD_000badac_caseD_87da;
                case 0x87db:
                  goto switchD_000badac_caseD_87db;
                case 0x87dc:
                  goto switchD_000badac_caseD_87dc;
                case 0x87de:
                  goto switchD_000badac_caseD_87de;
                case 0x87df:
                  goto switchD_000badac_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar21 = puVar38[0xd];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000badac_caseD_87d5;
                case 0x87d6:
                  goto switchD_000badac_caseD_87d6;
                case 0x87d7:
                  goto switchD_000badac_caseD_87d7;
                case 0x87d8:
                  goto switchD_000badac_caseD_87d8;
                case 0x87d9:
                  goto switchD_000badac_caseD_87d9;
                case 0x87da:
                  goto switchD_000badac_caseD_87da;
                case 0x87db:
                  goto switchD_000badac_caseD_87db;
                case 0x87dc:
                  goto switchD_000badac_caseD_87dc;
                case 0x87de:
                  goto switchD_000badac_caseD_87de;
                case 0x87df:
                  goto switchD_000badac_caseD_87df;
                }
              }
              uVar25 = puVar37[0xb];
              puVar37[10] = uVar21;
              switch(uVar25) {
              case 0x87d5:
                uVar25 = *puVar17;
                break;
              case 0x87d6:
                uVar25 = puVar38[0xb];
                break;
              case 0x87d7:
                uVar25 = puVar38[0xc];
                break;
              case 0x87d8:
                uVar25 = puVar38[0xd];
                break;
              case 0x87d9:
                uVar25 = *puVar17;
                switch(uVar25) {
                case 0x87d5:
switchD_000bb004_caseD_87d5:
                  uVar25 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb004_caseD_87d6:
                  uVar25 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb004_caseD_87d7:
                  uVar25 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb004_caseD_87d8:
                  uVar25 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb004_caseD_87d9:
                  uVar25 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb004_caseD_87da:
                  uVar25 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb004_caseD_87db:
                  uVar25 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb004_caseD_87dc:
                  uVar25 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb004_caseD_87de:
                  uVar25 = 0x87df;
                  break;
                case 0x87df:
switchD_000bb004_caseD_87df:
                  uVar25 = 0x87de;
                }
                break;
              case 0x87da:
                uVar25 = puVar38[0xb];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bb004_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb004_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb004_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb004_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb004_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb004_caseD_87da;
                case 0x87db:
                  goto switchD_000bb004_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb004_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb004_caseD_87de;
                case 0x87df:
                  goto switchD_000bb004_caseD_87df;
                }
                break;
              case 0x87db:
                uVar25 = puVar38[0xc];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bb004_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb004_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb004_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb004_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb004_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb004_caseD_87da;
                case 0x87db:
                  goto switchD_000bb004_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb004_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb004_caseD_87de;
                case 0x87df:
                  goto switchD_000bb004_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar25 = puVar38[0xd];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bb004_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb004_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb004_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb004_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb004_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb004_caseD_87da;
                case 0x87db:
                  goto switchD_000bb004_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb004_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb004_caseD_87de;
                case 0x87df:
                  goto switchD_000bb004_caseD_87df;
                }
              }
              uVar21 = puVar37[0xc];
              puVar37[0xb] = uVar25;
              switch(uVar21) {
              case 0x87d5:
                uVar21 = *puVar17;
                break;
              case 0x87d6:
                uVar21 = puVar38[0xb];
                break;
              case 0x87d7:
                uVar21 = puVar38[0xc];
                break;
              case 0x87d8:
                uVar21 = puVar38[0xd];
                break;
              case 0x87d9:
                uVar21 = *puVar17;
                switch(uVar21) {
                case 0x87d5:
switchD_000bb25c_caseD_87d5:
                  uVar21 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb25c_caseD_87d6:
                  uVar21 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb25c_caseD_87d7:
                  uVar21 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb25c_caseD_87d8:
                  uVar21 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb25c_caseD_87d9:
                  uVar21 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb25c_caseD_87da:
                  uVar21 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb25c_caseD_87db:
                  uVar21 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb25c_caseD_87dc:
                  uVar21 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb25c_caseD_87de:
                  uVar21 = 0x87df;
                  break;
                case 0x87df:
switchD_000bb25c_caseD_87df:
                  uVar21 = 0x87de;
                }
                break;
              case 0x87da:
                uVar21 = puVar38[0xb];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000bb25c_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb25c_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb25c_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb25c_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb25c_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb25c_caseD_87da;
                case 0x87db:
                  goto switchD_000bb25c_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb25c_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb25c_caseD_87de;
                case 0x87df:
                  goto switchD_000bb25c_caseD_87df;
                }
                break;
              case 0x87db:
                uVar21 = puVar38[0xc];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000bb25c_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb25c_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb25c_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb25c_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb25c_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb25c_caseD_87da;
                case 0x87db:
                  goto switchD_000bb25c_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb25c_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb25c_caseD_87de;
                case 0x87df:
                  goto switchD_000bb25c_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar21 = puVar38[0xd];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000bb25c_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb25c_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb25c_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb25c_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb25c_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb25c_caseD_87da;
                case 0x87db:
                  goto switchD_000bb25c_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb25c_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb25c_caseD_87de;
                case 0x87df:
                  goto switchD_000bb25c_caseD_87df;
                }
              }
              uVar25 = puVar37[0xd];
              puVar37[0xc] = uVar21;
              switch(uVar25) {
              case 0x87d5:
                uVar25 = *puVar17;
                break;
              case 0x87d6:
                uVar25 = puVar38[0xb];
                break;
              case 0x87d7:
                uVar25 = puVar38[0xc];
                break;
              case 0x87d8:
                uVar25 = puVar38[0xd];
                break;
              case 0x87d9:
                uVar25 = *puVar17;
                switch(uVar25) {
                case 0x87d5:
switchD_000bb4b4_caseD_87d5:
                  uVar25 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb4b4_caseD_87d6:
                  uVar25 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb4b4_caseD_87d7:
                  uVar25 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb4b4_caseD_87d8:
                  uVar25 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb4b4_caseD_87d9:
                  uVar25 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb4b4_caseD_87da:
                  uVar25 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb4b4_caseD_87db:
                  uVar25 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb4b4_caseD_87dc:
                  uVar25 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb4b4_caseD_87de:
                  uVar25 = 0x87df;
                  break;
                case 0x87df:
switchD_000bb4b4_caseD_87df:
                  uVar25 = 0x87de;
                }
                break;
              case 0x87da:
                uVar25 = puVar38[0xb];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bb4b4_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb4b4_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb4b4_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb4b4_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb4b4_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb4b4_caseD_87da;
                case 0x87db:
                  goto switchD_000bb4b4_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb4b4_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb4b4_caseD_87de;
                case 0x87df:
                  goto switchD_000bb4b4_caseD_87df;
                }
                break;
              case 0x87db:
                uVar25 = puVar38[0xc];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bb4b4_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb4b4_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb4b4_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb4b4_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb4b4_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb4b4_caseD_87da;
                case 0x87db:
                  goto switchD_000bb4b4_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb4b4_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb4b4_caseD_87de;
                case 0x87df:
                  goto switchD_000bb4b4_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar25 = puVar38[0xd];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bb4b4_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb4b4_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb4b4_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb4b4_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb4b4_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb4b4_caseD_87da;
                case 0x87db:
                  goto switchD_000bb4b4_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb4b4_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb4b4_caseD_87de;
                case 0x87df:
                  goto switchD_000bb4b4_caseD_87df;
                }
              }
              puVar37[0xd] = uVar25;
              puVar17 = puVar38 + 0x11;
              puVar37[0x10] = puVar38[0x10];
              uVar21 = *puVar14;
              switch(uVar21) {
              case 0x87d5:
                uVar21 = *puVar17;
                break;
              case 0x87d6:
                uVar21 = puVar38[0x12];
                break;
              case 0x87d7:
                uVar21 = puVar38[0x13];
                break;
              case 0x87d8:
                uVar21 = puVar38[0x14];
                break;
              case 0x87d9:
                uVar21 = *puVar17;
                switch(uVar21) {
                case 0x87d5:
switchD_000bb718_caseD_87d5:
                  uVar21 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb718_caseD_87d6:
                  uVar21 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb718_caseD_87d7:
                  uVar21 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb718_caseD_87d8:
                  uVar21 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb718_caseD_87d9:
                  uVar21 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb718_caseD_87da:
                  uVar21 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb718_caseD_87db:
                  uVar21 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb718_caseD_87dc:
                  uVar21 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb718_caseD_87de:
                  uVar21 = 0x87df;
                  break;
                case 0x87df:
switchD_000bb718_caseD_87df:
                  uVar21 = 0x87de;
                }
                break;
              case 0x87da:
                uVar21 = puVar38[0x12];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000bb718_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb718_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb718_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb718_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb718_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb718_caseD_87da;
                case 0x87db:
                  goto switchD_000bb718_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb718_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb718_caseD_87de;
                case 0x87df:
                  goto switchD_000bb718_caseD_87df;
                }
                break;
              case 0x87db:
                uVar21 = puVar38[0x13];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000bb718_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb718_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb718_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb718_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb718_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb718_caseD_87da;
                case 0x87db:
                  goto switchD_000bb718_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb718_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb718_caseD_87de;
                case 0x87df:
                  goto switchD_000bb718_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar21 = puVar38[0x14];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000bb718_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb718_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb718_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb718_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb718_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb718_caseD_87da;
                case 0x87db:
                  goto switchD_000bb718_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb718_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb718_caseD_87de;
                case 0x87df:
                  goto switchD_000bb718_caseD_87df;
                }
              }
              uVar25 = puVar37[0x12];
              *puVar14 = uVar21;
              switch(uVar25) {
              case 0x87d5:
                uVar25 = *puVar17;
                break;
              case 0x87d6:
                uVar25 = puVar38[0x12];
                break;
              case 0x87d7:
                uVar25 = puVar38[0x13];
                break;
              case 0x87d8:
                uVar25 = puVar38[0x14];
                break;
              case 0x87d9:
                uVar25 = *puVar17;
                switch(uVar25) {
                case 0x87d5:
switchD_000bb970_caseD_87d5:
                  uVar25 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb970_caseD_87d6:
                  uVar25 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb970_caseD_87d7:
                  uVar25 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb970_caseD_87d8:
                  uVar25 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb970_caseD_87d9:
                  uVar25 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb970_caseD_87da:
                  uVar25 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb970_caseD_87db:
                  uVar25 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb970_caseD_87dc:
                  uVar25 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb970_caseD_87de:
                  uVar25 = 0x87df;
                  break;
                case 0x87df:
switchD_000bb970_caseD_87df:
                  uVar25 = 0x87de;
                }
                break;
              case 0x87da:
                uVar25 = puVar38[0x12];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bb970_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb970_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb970_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb970_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb970_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb970_caseD_87da;
                case 0x87db:
                  goto switchD_000bb970_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb970_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb970_caseD_87de;
                case 0x87df:
                  goto switchD_000bb970_caseD_87df;
                }
                break;
              case 0x87db:
                uVar25 = puVar38[0x13];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bb970_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb970_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb970_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb970_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb970_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb970_caseD_87da;
                case 0x87db:
                  goto switchD_000bb970_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb970_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb970_caseD_87de;
                case 0x87df:
                  goto switchD_000bb970_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar25 = puVar38[0x14];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bb970_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb970_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb970_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb970_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb970_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb970_caseD_87da;
                case 0x87db:
                  goto switchD_000bb970_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb970_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb970_caseD_87de;
                case 0x87df:
                  goto switchD_000bb970_caseD_87df;
                }
              }
              uVar21 = puVar37[0x13];
              puVar37[0x12] = uVar25;
              switch(uVar21) {
              case 0x87d5:
                uVar21 = *puVar17;
                break;
              case 0x87d6:
                uVar21 = puVar38[0x12];
                break;
              case 0x87d7:
                uVar21 = puVar38[0x13];
                break;
              case 0x87d8:
                uVar21 = puVar38[0x14];
                break;
              case 0x87d9:
                uVar21 = *puVar17;
                switch(uVar21) {
                case 0x87d5:
switchD_000bbbc8_caseD_87d5:
                  uVar21 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bbbc8_caseD_87d6:
                  uVar21 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bbbc8_caseD_87d7:
                  uVar21 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bbbc8_caseD_87d8:
                  uVar21 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bbbc8_caseD_87d9:
                  uVar21 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bbbc8_caseD_87da:
                  uVar21 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bbbc8_caseD_87db:
                  uVar21 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bbbc8_caseD_87dc:
                  uVar21 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bbbc8_caseD_87de:
                  uVar21 = 0x87df;
                  break;
                case 0x87df:
switchD_000bbbc8_caseD_87df:
                  uVar21 = 0x87de;
                }
                break;
              case 0x87da:
                uVar21 = puVar38[0x12];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000bbbc8_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbbc8_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbbc8_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbbc8_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbbc8_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbbc8_caseD_87da;
                case 0x87db:
                  goto switchD_000bbbc8_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbbc8_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbbc8_caseD_87de;
                case 0x87df:
                  goto switchD_000bbbc8_caseD_87df;
                }
                break;
              case 0x87db:
                uVar21 = puVar38[0x13];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000bbbc8_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbbc8_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbbc8_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbbc8_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbbc8_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbbc8_caseD_87da;
                case 0x87db:
                  goto switchD_000bbbc8_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbbc8_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbbc8_caseD_87de;
                case 0x87df:
                  goto switchD_000bbbc8_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar21 = puVar38[0x14];
                switch(uVar21) {
                case 0x87d5:
                  goto switchD_000bbbc8_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbbc8_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbbc8_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbbc8_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbbc8_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbbc8_caseD_87da;
                case 0x87db:
                  goto switchD_000bbbc8_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbbc8_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbbc8_caseD_87de;
                case 0x87df:
                  goto switchD_000bbbc8_caseD_87df;
                }
              }
              uVar25 = puVar37[0x14];
              puVar37[0x13] = uVar21;
              switch(uVar25) {
              case 0x87d5:
                uVar25 = *puVar17;
                break;
              case 0x87d6:
                uVar25 = puVar38[0x12];
                break;
              case 0x87d7:
                uVar25 = puVar38[0x13];
                break;
              case 0x87d8:
                uVar25 = puVar38[0x14];
                break;
              case 0x87d9:
                uVar25 = *puVar17;
                switch(uVar25) {
                case 0x87d5:
switchD_000bbe20_caseD_87d5:
                  uVar25 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bbe20_caseD_87d6:
                  uVar25 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bbe20_caseD_87d7:
                  uVar25 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bbe20_caseD_87d8:
                  uVar25 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bbe20_caseD_87d9:
                  uVar25 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bbe20_caseD_87da:
                  uVar25 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bbe20_caseD_87db:
                  uVar25 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bbe20_caseD_87dc:
                  uVar25 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bbe20_caseD_87de:
                  uVar25 = 0x87df;
                  break;
                case 0x87df:
switchD_000bbe20_caseD_87df:
                  uVar25 = 0x87de;
                }
                break;
              case 0x87da:
                uVar25 = puVar38[0x12];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bbe20_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbe20_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbe20_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbe20_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbe20_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbe20_caseD_87da;
                case 0x87db:
                  goto switchD_000bbe20_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbe20_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbe20_caseD_87de;
                case 0x87df:
                  goto switchD_000bbe20_caseD_87df;
                }
                break;
              case 0x87db:
                uVar25 = puVar38[0x13];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bbe20_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbe20_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbe20_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbe20_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbe20_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbe20_caseD_87da;
                case 0x87db:
                  goto switchD_000bbe20_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbe20_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbe20_caseD_87de;
                case 0x87df:
                  goto switchD_000bbe20_caseD_87df;
                }
                break;
              case 0x87dc:
                uVar25 = puVar38[0x14];
                switch(uVar25) {
                case 0x87d5:
                  goto switchD_000bbe20_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbe20_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbe20_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbe20_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbe20_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbe20_caseD_87da;
                case 0x87db:
                  goto switchD_000bbe20_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbe20_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbe20_caseD_87de;
                case 0x87df:
                  goto switchD_000bbe20_caseD_87df;
                }
              }
              puVar37[0x14] = uVar25;
              uVar8 = *(int *)(param_2 + 0x14) - 1;
              *(uint *)(param_2 + 0x14) = uVar8;
              iVar35 = iVar9;
              uVar33 = uVar16;
              if (uVar16 < uVar8) {
                do {
                  uVar32 = uVar33;
                  uVar33 = uVar32 + 1;
                  iVar13 = iVar35 + *(int *)(param_2 + 0x18);
                  _memcpy(iVar13,iVar13 + 0x74,0x74);
                  uVar8 = *(uint *)(param_2 + 0x14);
                  iVar35 = iVar35 + 0x74;
                } while (uVar33 < uVar8);
                uVar32 = uVar32 + 2;
                bVar1 = true;
              }
              else {
                bVar1 = true;
                uVar32 = uVar36;
              }
            }
          }
          else {
LAB_000ba7ec:
            bVar1 = false;
            uVar32 = uVar32 + 1;
          }
          if ((uVar8 <= uVar32) || (bVar1)) break;
          iVar35 = *(int *)(param_2 + 0x18);
        } while( true );
      }
      uVar16 = uVar16 + 1;
    } while (uVar16 < uVar8);
    if (uVar8 != 0) {
      uVar16 = 0;
      do {
        iVar35 = *(int *)(param_2 + 0x18);
        iVar9 = iVar35 + uVar16 * 0x74;
        if (((*(int *)(iVar35 + uVar16 * 0x74) == 0x8798) && (*(int *)(iVar9 + 4) == 2)) &&
           (*(int *)(iVar9 + 0x20) == 2)) {
          iVar13 = *(int *)(param_2 + 0x20) + *(int *)(iVar9 + 0x24) * 0x54;
          if ((*(char *)(iVar13 + 0x44) != '\0') && (*(int *)(iVar13 + 0x48) == 0xba6)) {
            uVar32 = uVar16 + 1;
            if (uVar32 < uVar8) {
              iVar13 = uVar8 - uVar32;
              bVar1 = true;
              uVar36 = 0;
              piVar20 = (int *)(uVar32 * 0x74 + iVar35 + 0x3c);
              do {
                if ((*piVar20 == 2) && (piVar20[1] == *(int *)(iVar9 + 8))) {
                  if ((((piVar20[-0xf] == 0x8798) && (piVar20[-7] == 2)) &&
                      (iVar18 = *(int *)(param_2 + 0x20) + piVar20[-6] * 0x54,
                      *(char *)(iVar18 + 0x44) != '\0')) &&
                     ((*(int *)(iVar18 + 0x48) == 0xba7 && (uVar36 == 0)))) {
                    bVar5 = false;
                    uVar36 = uVar32;
                  }
                  else {
LAB_000bd88c:
                    bVar1 = false;
                    bVar5 = true;
                  }
                }
                else {
                  if (((piVar20[-7] == 2) && (piVar20[-6] == *(int *)(iVar9 + 8))) ||
                     ((piVar20[7] == 2 && (piVar20[8] == *(int *)(iVar9 + 8))))) goto LAB_000bd88c;
                  if ((piVar20[-0xe] != 2) || (bVar5 = true, piVar20[-0xd] != *(int *)(iVar9 + 8)))
                  {
                    bVar5 = false;
                  }
                }
                uVar32 = uVar32 + 1;
                iVar13 = iVar13 + -1;
              } while ((iVar13 != 0) && (piVar20 = piVar20 + 0x1d, !bVar5));
              if (!bVar1) goto LAB_000bd970;
              iVar13 = uVar36 * 0x74;
            }
            else {
              uVar36 = 0;
              iVar13 = 0;
            }
            iVar18 = *(int *)(param_2 + 0x2c);
            if (iVar18 == 0) {
              iVar18 = FUN_00054dd0(iStack00000018,iVar31,
                                    *(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + iStack00000018) + 0x18)
                                   );
              iVar35 = *(int *)(param_2 + 0x18);
              *(int *)(param_2 + 0x2c) = iVar18;
            }
            iVar13 = iVar13 + iVar35;
            *(int *)(iVar9 + 0x24) = iVar18;
            uVar21 = *(undefined4 *)(iVar13 + 8);
            uVar30 = *(undefined4 *)(iVar13 + 0xc);
            uVar25 = *(undefined4 *)(iVar13 + 0x10);
            *(undefined4 *)(iVar9 + 4) = *(undefined4 *)(iVar13 + 4);
            *(undefined4 *)(iVar9 + 8) = uVar21;
            *(undefined4 *)(iVar9 + 0xc) = uVar30;
            *(undefined4 *)(iVar9 + 0x10) = uVar25;
            uVar21 = *(undefined4 *)(iVar13 + 0x14);
            uVar25 = *(undefined4 *)(iVar13 + 0x18);
            *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(iVar13 + 0x1c);
            *(undefined4 *)(iVar9 + 0x14) = uVar21;
            *(undefined4 *)(iVar9 + 0x18) = uVar25;
            uVar8 = *(int *)(param_2 + 0x14) - 1;
            *(uint *)(param_2 + 0x14) = uVar8;
            if (uVar36 < uVar8) {
              iVar35 = uVar36 * 0x74;
              do {
                uVar36 = uVar36 + 1;
                iVar9 = iVar35 + *(int *)(param_2 + 0x18);
                iVar35 = iVar35 + 0x74;
                _memcpy(iVar9,iVar9 + 0x74,0x74);
                uVar8 = *(uint *)(param_2 + 0x14);
              } while (uVar36 < uVar8);
            }
          }
        }
LAB_000bd970:
        uVar16 = uVar16 + 1;
      } while (uVar16 < uVar8);
    }
  }
  return;
}

/* FUN_000bd9a0 @ 0xbd9a0 (160 bytes) */
void FUN_000bd9a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1)
{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 extraout_r4;
  undefined4 in_r7;
  undefined4 in_r8;
  int a6;
  
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
    puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
    *puVar3 = 0x860;
    a6 = *(int *)(FUN_00002748 + param_1 + 4);
    *(undefined4 *)(a6 + 4) = *(undefined4 *)(param_1 + 0x1b78);
    iVar2 = *(int *)(FUN_00002748 + param_1 + 4);
    pcVar1 = *(code **)(param_1 + 0x275c);
    *(int *)(FUN_00002748 + param_1 + 4) = iVar2 + 8;
    (*pcVar1)(param_1,iVar2 + 8,param_3,param_4,in_r7,in_r8,a6);
    FUN_0009be00(param_1);
    fparam_1 = (double)FUN_0009cc30(param_1);
    param_2 = extraout_r4;
  }
  ((void (*)())FUN_0004d620)(param_1,param_2,param_3,param_4,fparam_1);
  return;
}

/* FUN_000bda40 @ 0xbda40 (1016 bytes) */
int FUN_000bda40(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  
  uVar14 = *(uint *)(param_1 + 0x44);
  if (((((uVar14 & 0x2000) == 0) || ((*(byte *)(param_1 + 0x2e) & 1) != 0)) ||
      ((*(uint *)(param_1 + 0x38) & 0x8000) != 0)) || (*(short *)(param_1 + 0x42) != 0)) {
    bVar1 = ((unsigned char *)0x000013b0)[param_1];
    iVar16 = param_1 + 0x44;
    *(uint *)(param_1 + 0x8c) = *(uint *)(param_1 + 0x8c) & 0xf07fffff;
    *(uint *)(param_1 + 0x1874) = *(uint *)(param_1 + 0x1874) & 0xfdffffff;
    uVar24 = (uint)*(byte *)(param_1 + 0x2b);
    if ((uint)bVar1 < (uint)*(byte *)(param_1 + 0x2b)) {
      uVar24 = (uint)bVar1;
    }
    if ((uVar14 & 0x20000) == 0) {
      *(undefined1 *)(param_1 + 0x1878) = 0;
      uVar21 = 0;
    }
    else {
      if ((uVar14 & 0x2000) == 0) {
        bVar1 = ((unsigned char *)0x00001135)[param_1];
      }
      else {
        bVar1 = ((unsigned char *)0x000011d3)[param_1];
      }
      uVar21 = (uint)bVar1;
      *(byte *)(param_1 + 0x1878) = bVar1;
    }
    iVar18 = 0;
    if (uVar24 != 0) {
      uVar9 = 0;
      iVar8 = param_1;
      iVar22 = param_1;
      iVar23 = param_1;
      while( true ) {
        uVar6 = *(uint *)(iVar16 + 4) & 0x1e0;
        if ((uVar14 & 0x20000) == 0) {
          uVar14 = *(uint *)(iVar16 + 4) & 0x1f;
        }
        else {
          uVar14 = uVar21 & 1 << (uVar9 & 0x3f);
        }
        iVar10 = param_1 + 0x450 + uVar9 * 0xcc;
        if ((int)-uVar14 < 0) {
          iVar15 = uVar9 * 2 + param_1;
          bVar5 = *(char *)(iVar23 + 0x2784) == '\0';
          *(uint *)(iVar8 + 0x150) = (uint)bVar5;
          uVar7 = (ushort)bVar5 << 0xe;
          uVar2 = *(ushort *)(iVar15 + 0x187c);
          *(ushort *)(iVar15 + 0x187c) = uVar2 & 0xbfff | uVar7;
          if (uVar6 == 0) {
            *(ushort *)(iVar15 + 0x187c) = uVar2 & 0x8003 | uVar7;
            uVar14 = *(uint *)(param_1 + 0x8c);
          }
          else {
            uVar19 = uVar6 >> 7 & 1;
            sVar3 = *(short *)(iVar10 + 0x60);
            uVar14 = uVar6 >> 5 & 1;
            uVar20 = uVar6 >> 6 & 1;
            if ((uVar19 == 0) || (uVar17 = 1, 1 < (ushort)(*(short *)(iVar10 + 0x84) + 0x7aefU))) {
              uVar17 = 0;
            }
            uVar12 = 0;
            if (uVar14 != 0) {
              uVar12 = *(uint *)(&DAT_001dbf70 +
                                (*(ushort *)(iVar22 + 0x48c) >> 2 & 4 |
                                *(ushort *)(iVar22 + 0x48c) & 3) * 4);
            }
            if (uVar20 != 0) {
              uVar12 = uVar12 | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(iVar22 + 0x4b0) >> 2 & 4 |
                                        *(ushort *)(iVar22 + 0x4b0) & 3) * 4) << 3;
            }
            if (uVar19 != 0) {
              uVar12 = uVar12 | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(iVar22 + 0x4d4) >> 2 & 4 |
                                        *(ushort *)(iVar22 + 0x4d4) & 3) * 4) << 6;
            }
            if (uVar6 >> 8 != 0) {
              uVar12 = uVar12 | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(iVar22 + 0x4f8) >> 2 & 4 |
                                        *(ushort *)(iVar22 + 0x4f8) & 3) * 4) << 9;
            }
            iVar15 = uVar9 * 2 + param_1;
            uVar17 = (((ushort)(*(short *)(iVar10 + 0x3c) + 0x7aefU) < 2 || sVar3 == -0x7aee) ||
                     sVar3 == -0x7aef) | uVar17;
            uVar4 = (uint)(*(short *)(iVar10 + 0x3c) == 0x2402 || sVar3 == 0x2402);
            uVar13 = uVar17 | uVar4;
            *(ushort *)(iVar15 + 0x187c) =
                 *(ushort *)(iVar15 + 0x187c) & 0xc003 | (ushort)(uVar12 << 2) & 0x3ffc;
            uVar11 = *(uint *)(param_1 + 0x8c);
            uVar17 = (uVar17 | uVar11 >> 0x1b & 1) << 0x1b;
            *(uint *)(param_1 + 0x1874) =
                 (uVar13 | *(uint *)(param_1 + 0x1874) >> 0x19 & 1) << 0x19 |
                 *(uint *)(param_1 + 0x1874) & 0xfdffffff;
            uVar12 = (uVar4 | (uVar11 & 0xf7ffffff) >> 0x1a & 1) << 0x1a;
            *(uint *)(param_1 + 0x8c) = uVar12 | uVar17 | uVar11 & 0xf3ffffff;
            uVar14 = ((uVar11 & 0x2000000) >> 0x19 |
                     uVar13 | *(short *)(iVar10 + 0x3c) == 0x2400 & uVar14 |
                              *(short *)(iVar10 + 0x60) == 0x2400 & uVar20 |
                              *(short *)(iVar10 + 0x84) == 0x2400 & uVar19 |
                              (uint)(*(short *)(iVar10 + 0xa8) == 0x2400) & uVar6 >> 8) << 0x19 |
                     uVar12 | uVar17 | uVar11 & 0xf1ffffff;
            *(uint *)(param_1 + 0x8c) = uVar14;
          }
          *(uint *)(param_1 + 0x8c) = uVar14 | 0x800000;
          iVar10 = iVar18 * 4;
          iVar18 = iVar18 + 1;
          *(uint *)(param_1 + 0x8c) =
               (uint)(0 < (int)uVar9) << 0x18 | uVar14 & 0xfeffffff | 0x800000;
          *(uint *)(iVar10 + param_1 + 0x98) = uVar9;
        }
        else {
          *(undefined4 *)(iVar8 + 0x150) = 0;
          iVar10 = uVar9 * 2 + param_1;
          *(ushort *)(iVar10 + 0x187c) = *(ushort *)(iVar10 + 0x187c) & 0x8003;
        }
        uVar9 = uVar9 + 1;
        iVar16 = iVar16 + 4;
        iVar8 = iVar8 + 4;
        iVar22 = iVar22 + 0xcc;
        iVar23 = iVar23 + 1;
        uVar24 = uVar24 - 1;
        if (uVar24 == 0) break;
        uVar14 = *(uint *)(param_1 + 0x44);
      }
    }
    *(int *)(param_1 + 0x94) = iVar18;
  }
  return;
}

/* FUN_000bde70 @ 0xbde70 (1504 bytes) */
int FUN_000bde70(param_1, param_2, param_3, param_4)
  uint *param_1;
  uint *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  uint *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  int *piVar16;
  uint uVar17;
  uint uVar18;
  
  if (((param_4 == (undefined4 *)0x0) || (param_4[0xd] != -0x54520ff3)) ||
     (param_3 == (undefined4 *)0x0)) {
    uVar8 = 0x80000005;
  }
  else {
    iVar14 = -(*param_2 & 7);
    uVar18 = iVar14 + 3;
    uVar17 = (*param_1 & 0xf) + 1;
    if (uVar18 < 4) {
      uVar13 = uVar18;
      uVar6 = uVar18;
      if ((*param_2 >> 3 & 1) != 0) goto LAB_000bdeec;
      while( true ) {
        uVar17 = uVar17 + (param_2[uVar6 + 2] >> 6 & 0x3f) + 1;
        uVar13 = uVar6 + 1;
        if (3 < uVar6 + 1) break;
LAB_000bdeec:
        uVar17 = uVar17 + (param_2[uVar13 + 2] >> 0x11 & 0x1f) + 1;
        uVar6 = uVar13;
      }
    }
    piVar16 = (int *)*param_3;
    if (piVar16 == (int *)0x0) {
      piVar16 = (int *)(*(code *)*param_4)(uVar17 * 0x48 + 0x48);
      *piVar16 = 0;
      piVar16[1] = uVar17 + 1;
      *param_3 = piVar16;
    }
    else if ((*piVar16 != 0) || ((uint)piVar16[1] <= uVar17)) {
      return 0x80000006;
    }
    *(undefined2 *)(piVar16 + 5) = 0;
    piVar16[2] = 0;
    *(byte *)((int)piVar16 + 0xd) = (byte)(*param_1 >> 5) & 7;
    uVar13 = 0;
    puVar15 = param_1;
    piVar12 = piVar16;
    do {
      uVar4 = uVar13;
      piVar12[0x12] = 1;
      uVar13 = uVar4 + 1;
      *(byte *)(piVar12 + 0x14) = (byte)puVar15[1] & 0xf;
      *(byte *)((int)piVar12 + 0x51) = (byte)(puVar15[1] >> 4) & 1;
      *(byte *)((int)piVar12 + 0x52) = (byte)(puVar15[1] >> 0xc) & 0xf;
      *(byte *)((int)piVar12 + 0x53) = (byte)*(undefined2 *)(puVar15 + 1) & 3;
      *(byte *)(piVar12 + 0x15) = (byte)(puVar15[1] >> 0x19) & 1;
      *(byte *)((int)piVar12 + 0x55) = (byte)(puVar15[1] >> 0x1b);
      *(ushort *)((int)piVar12 + 0x4e) = (ushort)(puVar15[1] >> 0x12) & 0x7f;
      puVar15 = puVar15 + 1;
      uVar6 = *puVar15;
      *(undefined1 *)((int)piVar12 + 0x57) = 0;
      *(undefined1 *)((int)piVar12 + 0x56) = 0;
      *(ushort *)(piVar12 + 0x13) = (ushort)(uVar6 >> 5) & 0x7f;
      piVar12 = piVar12 + 0x12;
    } while (uVar13 <= (*param_1 & 0xf));
    iVar9 = uVar4 + 2;
    uVar13 = *param_2 >> 3 & 1;
    if (uVar18 < 4) {
      puVar15 = param_2 + iVar14 + 5;
      do {
        uVar4 = *puVar15;
        puVar15 = puVar15 + 1;
        uVar6 = uVar4 & 0x3f;
        uVar10 = uVar4 >> 0xc & 0x1f;
        if ((uVar13 != 0) && (uVar13 = uVar10 + (uVar4 >> 0x11 & 0x1f), uVar10 <= uVar13)) {
          iVar14 = uVar10 << 2;
          piVar12 = piVar16 + iVar9 * 0x12;
          uVar11 = uVar10;
          do {
            *piVar12 = 2;
            bVar3 = uVar11 == uVar10;
            uVar11 = uVar11 + 1;
            iVar9 = iVar9 + 1;
            *(byte *)((int)piVar12 + 0x19) = (byte)(*(uint *)(iVar14 + param_2[7]) >> 0xb) & 0xf;
            uVar5 = *(uint *)(iVar14 + param_2[7]);
            *(bool *)(piVar12 + 8) = bVar3;
            *(undefined1 *)((int)piVar12 + 0x1f) = 0;
            *(byte *)((int)piVar12 + 0x1a) = (byte)(uVar5 >> 0xf) & 7;
            *(ushort *)((int)piVar12 + 0xe) = (ushort)*(undefined4 *)(iVar14 + param_2[7]) & 0x1f;
            puVar1 = (uint *)(iVar14 + param_2[7]);
            iVar14 = iVar14 + 4;
            *(ushort *)(piVar12 + 3) = (ushort)(*puVar1 >> 6) & 0x1f;
            piVar12 = piVar12 + 0x12;
          } while (uVar11 <= uVar13);
        }
        uVar13 = uVar6 + (uVar4 >> 6 & 0x3f);
        if (uVar6 <= uVar13) {
          iVar14 = uVar6 << 2;
          piVar12 = piVar16 + iVar9 * 0x12;
          do {
            *piVar12 = 3;
            *(byte *)(piVar12 + 5) = (byte)(*(uint *)(param_2[8] + iVar14) >> 0x17) & 7;
            *(byte *)((int)piVar12 + 0x15) =
                 (byte)((uint)*(undefined4 *)(param_2[8] + iVar14) >> 0x1a) & 7;
            *(byte *)((int)piVar12 + 0x16) =
                 (byte)((uint)*(undefined4 *)(param_2[8] + iVar14) >> 0x1d) & 3;
            uVar4 = *(uint *)(param_2[8] + iVar14) & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)piVar12 + 0xe) = uVar7;
            uVar4 = *(uint *)(param_2[8] + iVar14) >> 6 & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)(piVar12 + 4) = uVar7;
            uVar4 = *(uint *)(param_2[8] + iVar14) >> 0xc & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)piVar12 + 0x12) = uVar7;
            *(ushort *)(piVar12 + 3) =
                 (ushort)((uint)*(undefined4 *)(param_2[8] + iVar14) >> 0x12) & 0x1f;
            *(byte *)(piVar12 + 8) = (byte)(*(uint *)(param_2[9] + iVar14) >> 0x17) & 1;
            *(byte *)((int)piVar12 + 0x21) = *(byte *)(param_2[9] + iVar14) & 1;
            *(byte *)((int)piVar12 + 0x22) =
                 (byte)((uint)*(undefined4 *)(param_2[9] + iVar14) >> 0x19) & 3;
            *(byte *)((int)piVar12 + 0x23) =
                 (byte)((uint)*(undefined4 *)(param_2[9] + iVar14) >> 0x1b) & 1;
            uVar4 = *(uint *)(param_2[9] + iVar14) & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)piVar12 + 0x1a) = uVar7;
            uVar4 = *(uint *)(param_2[9] + iVar14) >> 6 & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)(piVar12 + 7) = uVar7;
            uVar4 = *(uint *)(param_2[9] + iVar14) >> 0xc & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)piVar12 + 0x1e) = uVar7;
            uVar6 = uVar6 + 1;
            iVar9 = iVar9 + 1;
            *(ushort *)(piVar12 + 6) =
                 (ushort)((uint)*(undefined4 *)(param_2[9] + iVar14) >> 0x12) & 0x1f;
            *(byte *)((int)piVar12 + 0x2a) = (byte)*(undefined4 *)(param_2[0xb] + iVar14) & 0x1f;
            *(byte *)((int)piVar12 + 0x2d) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 5) & 3;
            *(byte *)((int)piVar12 + 0x2b) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 7) & 0x1f;
            *(byte *)((int)piVar12 + 0x2e) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 0xc) & 3;
            *(byte *)(piVar12 + 0xb) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 0xe) & 0x1f;
            *(byte *)((int)piVar12 + 0x2f) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 0x13) & 3;
            *(byte *)(piVar12 + 0xc) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 0x15) & 3;
            *(byte *)((int)piVar12 + 0x31) = (byte)(*(uint *)(param_2[0xb] + iVar14) >> 0x17) & 0xf;
            *(byte *)((int)piVar12 + 0x32) =
                 (byte)((uint)*(undefined4 *)(param_2[0xb] + iVar14) >> 0x1b) & 7;
            *(byte *)((int)piVar12 + 0x33) =
                 (byte)((uint)*(undefined4 *)(param_2[0xb] + iVar14) >> 0x1e) & 1;
            *(byte *)(piVar12 + 0xd) = (byte)((uint)*(undefined4 *)(param_2[0xb] + iVar14) >> 0x1f);
            *(byte *)((int)piVar12 + 0x39) = (byte)*(undefined4 *)(iVar14 + param_2[0xc]) & 0x1f;
            *(byte *)(piVar12 + 0xf) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 5) & 3;
            *(byte *)((int)piVar12 + 0x3a) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 7) & 0x1f;
            *(byte *)((int)piVar12 + 0x3d) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 0xc) & 3;
            *(byte *)((int)piVar12 + 0x3b) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 0xe) & 0x1f;
            *(byte *)((int)piVar12 + 0x3e) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 0x13) & 3;
            *(byte *)((int)piVar12 + 0x3f) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 0x15) & 3;
            *(byte *)(piVar12 + 0x10) = (byte)(*(uint *)(iVar14 + param_2[0xc]) >> 0x17) & 0xf;
            *(byte *)((int)piVar12 + 0x41) =
                 (byte)((uint)*(undefined4 *)(iVar14 + param_2[0xc]) >> 0x1b) & 7;
            puVar2 = (undefined4 *)(iVar14 + param_2[0xc]);
            iVar14 = iVar14 + 4;
            *(byte *)((int)piVar12 + 0x42) = (byte)((uint)*puVar2 >> 0x1e) & 1;
            piVar12 = piVar12 + 0x12;
          } while (uVar6 <= uVar13);
        }
        bVar3 = uVar18 != 3;
        uVar13 = 1;
        uVar18 = uVar18 + 1;
      } while (bVar3);
    }
    uVar8 = 0;
    piVar16[2] = uVar17;
  }
  return uVar8;
}

/* FUN_000be460 @ 0xbe460 (2472 bytes) */
int FUN_000be460(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint *param_2;
  uint *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  int *piVar16;
  uint uVar17;
  uint *puVar18;
  byte bVar19;
  byte bVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  int iVar24;
  
  uVar1 = *(ushort *)(param_1 + 0x16);
  uVar2 = *(ushort *)(param_1 + 0x22);
  uVar21 = *(uint *)(param_1 + 8);
  iVar24 = 4 - (uint)uVar1;
  if ((*(int *)(param_1 + 0x48) == 1) && (uVar21 != 0)) {
    piVar15 = (int *)(param_1 + 0x90);
    uVar12 = 1;
    piVar6 = piVar15;
    piVar16 = (int *)(param_1 + 0x48);
    uVar9 = 0;
    do {
      piVar11 = piVar6;
      uVar17 = uVar9;
      if ((piVar16[2] & 0xff00ffU) != 0) {
        uVar17 = uVar9 + 1;
        param_2[uVar9 + 1] = 0;
        bVar19 = *(byte *)(piVar16 + 2);
        param_2[uVar9 + 1] = bVar19 & 0xf;
        uVar7 = (*(byte *)((int)piVar16 + 9) & 1) << 4 | bVar19 & 0xf;
        param_2[uVar9 + 1] = uVar7;
        uVar7 = (*(byte *)((int)piVar16 + 10) & 0xf) << 0xc | uVar7;
        param_2[uVar9 + 1] = uVar7;
        uVar7 = (*(byte *)((int)piVar16 + 0xb) & 3) << 0x10 | uVar7;
        param_2[uVar9 + 1] = uVar7;
        uVar7 = (*(byte *)(piVar16 + 3) & 1) << 0x19 | uVar7;
        param_2[uVar9 + 1] = uVar7;
        uVar7 = (uint)*(byte *)((int)piVar16 + 0xd) << 0x1b | uVar7;
        param_2[uVar9 + 1] = uVar7;
        uVar7 = (*(ushort *)(piVar16 + 1) & 0x7f) << 5 | uVar7;
        param_2[uVar9 + 1] = uVar7;
        param_2[uVar9 + 1] = (*(ushort *)((int)piVar16 + 6) & 0x7f) << 0x12 | uVar7;
      }
      uVar12 = uVar12 + 1;
      if (*piVar15 != 1) break;
      piVar15 = piVar15 + 0x12;
      piVar6 = piVar11 + 0x12;
      piVar16 = piVar11;
      uVar9 = uVar17;
    } while (uVar12 <= uVar21);
    uVar9 = uVar17 & 0xff;
    if (uVar17 != 0) goto LAB_000be580;
  }
  else {
    uVar12 = 1;
  }
  uVar9 = 1;
  param_2[1] = 0;
LAB_000be580:
  uVar9 = uVar9 - 1 & 0xf;
  *param_2 = uVar9;
  *param_2 = (*(byte *)(param_1 + 0xd) & 7) << 5 | uVar9;
  param_3[1] = uVar2 & 0x7f;
  *param_3 = uVar1 - 1 & 7;
  param_3[0xd] = 0;
  param_3[2] = 0;
  param_3[3] = 0;
  param_3[4] = 0;
  param_3[5] = 0;
  param_3[6] = 0;
  if (uVar12 <= uVar21) {
    bVar4 = false;
    uVar7 = 0;
    uVar17 = 0;
    uVar9 = 0;
    uVar22 = 0;
    puVar10 = (uint *)(param_1 + uVar12 * 0x48);
    bVar20 = 0;
    bVar19 = 0;
    bVar5 = false;
    puVar18 = puVar10 + 0x1a;
    do {
      uVar8 = *puVar10;
      iVar13 = uVar7 + uVar9;
      if (uVar8 == 2) {
        if (*(char *)((int)puVar10 + 0x1a) != '\0') {
          iVar3 = (uVar17 + uVar22) * 4;
          *(undefined4 *)(param_3[7] + iVar3) = 0;
          *(uint *)(iVar3 + param_3[7]) =
               *(byte *)((int)puVar10 + 0xf) & 0x1f | *(uint *)(iVar3 + param_3[7]) & 0xffffffe0;
          *(uint *)(iVar3 + param_3[7]) =
               (*(byte *)((int)puVar10 + 0xd) & 0x1f) << 6 |
               *(uint *)(iVar3 + param_3[7]) & 0xfffff83f;
          *(uint *)(iVar3 + param_3[7]) =
               (*(byte *)((int)puVar10 + 0x19) & 0xf) << 0xb |
               *(uint *)(iVar3 + param_3[7]) & 0xffff87ff;
          *(uint *)(iVar3 + param_3[7]) =
               (*(byte *)((int)puVar10 + 0x1a) & 7) << 0xf |
               *(uint *)(iVar3 + param_3[7]) & 0xfffc7fff;
          *(uint *)(iVar3 + param_3[7]) =
               (*(ushort *)((int)puVar10 + 0xe) & 0x20) << 0xe |
               *(uint *)(iVar3 + param_3[7]) & 0xfff7ffff;
          *(uint *)(iVar3 + param_3[7]) =
               (*(ushort *)(puVar10 + 3) & 0x20) << 0xf | *(uint *)(iVar3 + param_3[7]) & 0xffefffff
          ;
          if (!bVar5) {
            bVar5 = true;
            *param_3 = *param_3 | 8;
          }
          uVar22 = uVar22 + 1;
          bVar4 = false;
        }
      }
      else if ((1 < uVar8) && (uVar8 < 5)) {
        iVar3 = iVar13 * 4;
        *(undefined4 *)(param_3[8] + iVar3) = 0;
        uVar1 = *(ushort *)((int)puVar10 + 0xe);
        uVar8 = uVar1 & 0x1f;
        if ((uVar1 & 0x8000) != 0) {
          uVar8 = (uVar1 & 0x1f) + 0x20;
        }
        *(uint *)(iVar3 + param_3[8]) = uVar8 | *(uint *)(iVar3 + param_3[8]) & 0xffffffc0;
        uVar8 = *(ushort *)(puVar10 + 4) & 0x1f;
        if ((*(ushort *)(puVar10 + 4) & 0x8000) != 0) {
          uVar8 = uVar8 + 0x20;
        }
        *(uint *)(iVar3 + param_3[8]) = uVar8 << 6 | *(uint *)(iVar3 + param_3[8]) & 0xfffff03f;
        uVar8 = *(ushort *)((int)puVar10 + 0x12) & 0x1f;
        if ((*(ushort *)((int)puVar10 + 0x12) & 0x8000) != 0) {
          uVar8 = uVar8 + 0x20;
        }
        *(uint *)(iVar3 + param_3[8]) = uVar8 << 0xc | *(uint *)(iVar3 + param_3[8]) & 0xfffc0fff;
        *(uint *)(iVar3 + param_3[8]) =
             (*(byte *)((int)puVar10 + 0xd) & 0x1f) << 0x12 |
             *(uint *)(iVar3 + param_3[8]) & 0xff83ffff;
        *(uint *)(iVar3 + param_3[8]) =
             (*(byte *)(puVar10 + 5) & 7) << 0x17 | *(uint *)(iVar3 + param_3[8]) & 0xfc7fffff;
        *(uint *)(iVar3 + param_3[8]) =
             (*(byte *)((int)puVar10 + 0x15) & 7) << 0x1a |
             *(uint *)(iVar3 + param_3[8]) & 0xe3ffffff;
        *(uint *)(iVar3 + param_3[8]) =
             (*(byte *)((int)puVar10 + 0x16) & 3) << 0x1d |
             *(uint *)(iVar3 + param_3[8]) & 0x9fffffff;
        *(undefined4 *)(param_3[9] + iVar3) = 0;
        uVar8 = *(ushort *)((int)puVar10 + 0x1a) & 0x1f;
        if ((*(ushort *)((int)puVar10 + 0x1a) & 0x8000) != 0) {
          uVar8 = uVar8 + 0x20;
        }
        *(uint *)(iVar3 + param_3[9]) = uVar8 | *(uint *)(iVar3 + param_3[9]) & 0xffffffc0;
        uVar8 = *(ushort *)(puVar10 + 7) & 0x1f;
        if ((*(ushort *)(puVar10 + 7) & 0x8000) != 0) {
          uVar8 = uVar8 + 0x20;
        }
        *(uint *)(iVar3 + param_3[9]) = uVar8 << 6 | *(uint *)(iVar3 + param_3[9]) & 0xfffff03f;
        uVar8 = *(ushort *)((int)puVar10 + 0x1e) & 0x1f;
        if ((*(ushort *)((int)puVar10 + 0x1e) & 0x8000) != 0) {
          uVar8 = uVar8 + 0x20;
        }
        *(uint *)(iVar3 + param_3[9]) = uVar8 << 0xc | *(uint *)(iVar3 + param_3[9]) & 0xfffc0fff;
        *(uint *)(iVar3 + param_3[9]) =
             (*(byte *)((int)puVar10 + 0x19) & 0x1f) << 0x12 |
             *(uint *)(iVar3 + param_3[9]) & 0xff83ffff;
        *(uint *)(iVar3 + param_3[9]) =
             (*(byte *)(puVar10 + 8) & 1) << 0x17 | *(uint *)(iVar3 + param_3[9]) & 0xff7fffff;
        *(uint *)(iVar3 + param_3[9]) =
             (*(byte *)((int)puVar10 + 0x21) & 1) << 0x18 |
             *(uint *)(iVar3 + param_3[9]) & 0xfeffffff;
        *(uint *)(iVar3 + param_3[9]) =
             (*(byte *)((int)puVar10 + 0x22) & 3) << 0x19 |
             *(uint *)(iVar3 + param_3[9]) & 0xf9ffffff;
        *(uint *)(iVar3 + param_3[9]) =
             (*(byte *)((int)puVar10 + 0x23) & 1) << 0x1b |
             *(uint *)(iVar3 + param_3[9]) & 0xf7ffffff;
        if (param_3[10] != 0) {
          *(undefined4 *)(param_3[10] + iVar3) = 0;
          *(uint *)(iVar3 + param_3[10]) =
               *(ushort *)((int)puVar10 + 0xe) >> 5 & 1 |
               *(uint *)(iVar3 + param_3[10]) & 0xfffffffe;
          *(uint *)(iVar3 + param_3[10]) =
               *(ushort *)(puVar10 + 4) >> 4 & 2 | *(uint *)(iVar3 + param_3[10]) & 0xfffffffd;
          *(uint *)(iVar3 + param_3[10]) =
               *(ushort *)((int)puVar10 + 0x12) >> 3 & 4 |
               *(uint *)(iVar3 + param_3[10]) & 0xfffffffb;
          *(uint *)(iVar3 + param_3[10]) =
               *(ushort *)(puVar10 + 3) >> 2 & 8 | *(uint *)(iVar3 + param_3[10]) & 0xfffffff7;
          *(uint *)(iVar3 + param_3[10]) =
               *(ushort *)((int)puVar10 + 0x1a) >> 1 & 0x10 |
               *(uint *)(iVar3 + param_3[10]) & 0xffffffef;
          *(uint *)(iVar3 + param_3[10]) =
               *(ushort *)(puVar10 + 7) & 0x20 | *(uint *)(iVar3 + param_3[10]) & 0xffffffdf;
          *(uint *)(iVar3 + param_3[10]) =
               (*(ushort *)((int)puVar10 + 0x1e) & 0x20) << 1 |
               *(uint *)(iVar3 + param_3[10]) & 0xffffffbf;
          *(uint *)(iVar3 + param_3[10]) =
               (*(ushort *)(puVar10 + 6) & 0x20) << 2 | *(uint *)(iVar3 + param_3[10]) & 0xffffff7f;
        }
        uVar9 = uVar9 + 1;
        bVar4 = true;
        *(undefined4 *)(param_3[0xb] + iVar3) = 0;
        *(uint *)(iVar3 + param_3[0xb]) =
             *(byte *)((int)puVar10 + 0x2a) & 0x1f | *(uint *)(iVar3 + param_3[0xb]) & 0xffffffe0;
        *(uint *)(iVar3 + param_3[0xb]) =
             (*(byte *)((int)puVar10 + 0x2d) & 3) << 5 |
             *(uint *)(iVar3 + param_3[0xb]) & 0xffffff9f;
        *(uint *)(iVar3 + param_3[0xb]) =
             (*(byte *)((int)puVar10 + 0x2b) & 0x1f) << 7 |
             *(uint *)(iVar3 + param_3[0xb]) & 0xfffff07f;
        *(uint *)(iVar3 + param_3[0xb]) =
             (*(byte *)((int)puVar10 + 0x2e) & 3) << 0xc |
             *(uint *)(iVar3 + param_3[0xb]) & 0xffffcfff;
        *(uint *)(iVar3 + param_3[0xb]) =
             (*(byte *)(puVar10 + 0xb) & 0x1f) << 0xe | *(uint *)(iVar3 + param_3[0xb]) & 0xfff83fff
        ;
        *(uint *)(iVar3 + param_3[0xb]) =
             (*(byte *)((int)puVar10 + 0x2f) & 3) << 0x13 |
             *(uint *)(iVar3 + param_3[0xb]) & 0xffe7ffff;
        *(uint *)(iVar3 + param_3[0xb]) =
             (*(byte *)(puVar10 + 0xc) & 3) << 0x15 | *(uint *)(iVar3 + param_3[0xb]) & 0xff9fffff;
        *(uint *)(iVar3 + param_3[0xb]) =
             (*(byte *)((int)puVar10 + 0x31) & 0xf) << 0x17 |
             *(uint *)(iVar3 + param_3[0xb]) & 0xf87fffff;
        *(uint *)(iVar3 + param_3[0xb]) =
             (*(byte *)((int)puVar10 + 0x32) & 7) << 0x1b |
             *(uint *)(iVar3 + param_3[0xb]) & 0xc7ffffff;
        *(uint *)(iVar3 + param_3[0xb]) =
             (*(byte *)((int)puVar10 + 0x33) & 1) << 0x1e |
             *(uint *)(iVar3 + param_3[0xb]) & 0xbfffffff;
        *(uint *)(iVar3 + param_3[0xb]) =
             (uint)*(byte *)(puVar10 + 0xd) << 0x1f | *(uint *)(iVar3 + param_3[0xb]) & 0x7fffffff;
        *(undefined4 *)(param_3[0xc] + iVar3) = 0;
        *(uint *)(iVar3 + param_3[0xc]) =
             *(byte *)((int)puVar10 + 0x39) & 0x1f | *(uint *)(iVar3 + param_3[0xc]) & 0xffffffe0;
        *(uint *)(iVar3 + param_3[0xc]) =
             (*(byte *)(puVar10 + 0xf) & 3) << 5 | *(uint *)(iVar3 + param_3[0xc]) & 0xffffff9f;
        *(uint *)(iVar3 + param_3[0xc]) =
             (*(byte *)((int)puVar10 + 0x3a) & 0x1f) << 7 |
             *(uint *)(iVar3 + param_3[0xc]) & 0xfffff07f;
        *(uint *)(iVar3 + param_3[0xc]) =
             (*(byte *)((int)puVar10 + 0x3d) & 3) << 0xc |
             *(uint *)(iVar3 + param_3[0xc]) & 0xffffcfff;
        *(uint *)(iVar3 + param_3[0xc]) =
             (*(byte *)((int)puVar10 + 0x3b) & 0x1f) << 0xe |
             *(uint *)(iVar3 + param_3[0xc]) & 0xfff83fff;
        *(uint *)(iVar3 + param_3[0xc]) =
             (*(byte *)((int)puVar10 + 0x3e) & 3) << 0x13 |
             *(uint *)(iVar3 + param_3[0xc]) & 0xffe7ffff;
        *(uint *)(iVar3 + param_3[0xc]) =
             (*(byte *)((int)puVar10 + 0x3f) & 3) << 0x15 |
             *(uint *)(iVar3 + param_3[0xc]) & 0xff9fffff;
        *(uint *)(iVar3 + param_3[0xc]) =
             (*(byte *)(puVar10 + 0x10) & 0xf) << 0x17 |
             *(uint *)(iVar3 + param_3[0xc]) & 0xf87fffff;
        *(uint *)(iVar3 + param_3[0xc]) =
             (*(byte *)((int)puVar10 + 0x41) & 7) << 0x1b |
             *(uint *)(iVar3 + param_3[0xc]) & 0xc7ffffff;
        *(uint *)(iVar3 + param_3[0xc]) =
             (*(byte *)((int)puVar10 + 0x42) & 1) << 0x1e |
             *(uint *)(iVar3 + param_3[0xc]) & 0xbfffffff;
        bVar20 = bVar20 | *(byte *)((int)puVar10 + 0x23);
        bVar19 = bVar19 | *(byte *)((int)puVar10 + 0x15) | *(byte *)((int)puVar10 + 0x21);
      }
      if ((uVar12 == uVar21) || ((puVar18[-8] == 2 && ((bVar4 || (*(char *)puVar18 != '\0')))))) {
        if (uVar22 == 0) {
          uVar22 = 1;
          uVar8 = 1;
          uVar23 = 0;
        }
        else {
          uVar8 = uVar22 & 0xff;
          uVar23 = uVar22 - 1;
        }
        uVar14 = uVar9 & 0xff;
        if (uVar9 == 0) {
          iVar13 = iVar13 * 4;
          *(undefined4 *)(param_3[8] + iVar13) = 0;
          *(undefined4 *)(param_3[9] + iVar13) = 0;
          if (param_3[10] != 0) {
            *(undefined4 *)(param_3[10] + iVar13) = 0;
          }
          uVar14 = 1;
          *(undefined4 *)(param_3[0xb] + iVar13) = 0;
          *(undefined4 *)(param_3[0xc] + iVar13) = 0;
          uVar9 = 1;
        }
        param_3[iVar24 + 2] =
             (uVar23 & 0x1e0) << 0x17 |
             (uVar17 & 0x1e0) << 0x13 |
             (uVar14 - 1) * 0x40 & 0xfc0 |
             (uVar8 - 1) * 0x20000 & 0x3e0000 |
             uVar7 & 0x3f | (uVar17 & 0x1f) << 0xc | param_3[iVar24 + 2] & 0xc00000;
        if (iVar24 == 1) {
          param_3[6] = (uVar9 - 1) * 0x200 & 0x38000 |
                       (uVar7 & 0x1c0) << 6 | param_3[6] & 0xfffc0fff;
        }
        else if (iVar24 == 0) {
          param_3[6] = (uVar9 - 1) * 8 & 0xe00 | uVar7 & 0x1c0 | param_3[6] & 0xfffff03f;
        }
        else if (iVar24 == 2) {
          param_3[6] = (uVar9 - 1) * 0x8000 & 0xe00000 |
                       (uVar7 & 0x1c0) << 0xc | param_3[6] & 0xff03ffff;
        }
        else if (iVar24 == 3) {
          param_3[6] = (uVar9 - 1) * 0x200000 & 0x38000000 |
                       (uVar7 & 0x1c0) << 0x12 | param_3[6] & 0xc0ffffff;
        }
        if (bVar19 != 0) {
          param_3[iVar24 + 2] = param_3[iVar24 + 2] | 0x400000;
        }
        if (bVar20 != 0) {
          param_3[iVar24 + 2] = param_3[iVar24 + 2] | 0x800000;
          param_3[0xd] = param_3[0xd] | 1;
        }
        if (bVar5) {
          uVar17 = uVar17 + uVar22;
        }
        uVar7 = uVar7 + uVar9;
        iVar24 = iVar24 + 1;
        uVar9 = 0;
        uVar22 = 0;
        bVar20 = 0;
        bVar19 = 0;
        bVar5 = true;
      }
      uVar12 = uVar12 + 1;
      puVar10 = puVar10 + 0x12;
      puVar18 = puVar18 + 0x12;
    } while (uVar12 <= uVar21);
  }
  return;
}

/* FUN_000bee40 @ 0xbee40 (244 bytes) */
int FUN_000bee40(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_000c5e60)(param_1);
  if (*(ushort *)(param_1 + 0x16) < 5) {
    if (*(ushort *)(param_1 + 0x18) < 0x11) {
      if (*(ushort *)(param_1 + 0x1a) < 0x21) {
        if (*(ushort *)(param_1 + 0x1e) < 0x41) {
          if (*(short *)(param_1 + 0x20) == 0) {
            if (*(ushort *)(param_1 + 0x22) < 0x20) {
              if (*(ushort *)(param_1 + 0x24) < 0x20) {
                ((int (*)())FUN_000be460)(param_1,param_2,param_3,0,param_5,param_6,param_7);
                uVar1 = 0;
              }
              else {
                uVar1 = 0x80000013;
              }
            }
            else {
              uVar1 = 0x80000012;
            }
          }
          else {
            uVar1 = 0x80000017;
          }
        }
        else {
          uVar1 = 0x80000016;
        }
      }
      else {
        uVar1 = 0x80000015;
      }
    }
    else {
      uVar1 = 0x80000014;
    }
  }
  else {
    uVar1 = 0x80000011;
  }
  return uVar1;
}

/* FUN_000bef40 @ 0xbef40 (1192 bytes) */
int FUN_000bef40(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  dword *param_5;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  dword dVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  char *pcVar10;
  ushort *puVar11;
  ushort *puVar12;
  dword *pdVar13;
  dword *pdVar14;
  int *piVar15;
  dword *pdVar16;
  char *pcVar17;
  uint uVar18;
  dword *pdVar19;
  ushort *puVar20;
  uint uVar21;
  ushort *puVar22;
  ushort *puVar23;
  char *pcVar24;
  ushort *puVar25;
  char *pcVar26;
  dword *pdVar27;
  ushort *puVar28;
  ushort *puVar29;
  ushort *puVar30;
  int iVar31;
  int aiStack_148 [32];
  int aiStack_c8 [35];
  
  ((int (*)())FUN_000c5e60)(param_1);
  if (*(ushort *)(param_1 + 0x16) < 5) {
    if (*(ushort *)(param_1 + 0x18) < 0x11) {
      if (*(ushort *)(param_1 + 0x1a) < 0x201) {
        if (*(ushort *)(param_1 + 0x1e) < 0x201) {
          if (*(short *)(param_1 + 0x20) == 0) {
            if (*(ushort *)(param_1 + 0x22) < 0x40) {
              if (*(ushort *)(param_1 + 0x24) < 0x40) {
                pdVar16 = &(*(GhidraMachOCommand *)0x0000001c).filesize;
                uVar21 = *(uint *)(param_1 + 8);
                iVar7 = 0;
                iVar31 = 0x40;
                do {
                  *(undefined4 *)(iVar7 + (int)aiStack_148) = 0xffffffff;
                  iVar7 = iVar7 + 4;
                  iVar31 = iVar31 + -1;
                } while (iVar31 != 0);
                if ((uVar21 != 0) &&
                   (pdVar14 = (dword *)(param_1 + 0x48), param_5 = pdVar14,
                   *(int *)(param_1 + 0x48) == 1)) {
                  pdVar19 = (dword *)(param_1 + 0x90);
                  uVar18 = 1;
                  bVar1 = false;
                  pdVar27 = pdVar19;
                  pdVar16 = pdVar14;
                  do {
                    pdVar13 = pdVar27;
                    if ((*(char *)((int)pdVar16 + 9) != '\0') &&
                       (uVar3 = *(ushort *)(pdVar16 + 1), aiStack_148[uVar3] = 0,
                       (uVar3 & 0x20) != 0)) {
                      bVar1 = true;
                    }
                    if ((*(char *)((int)pdVar16 + 0xb) != '\0') &&
                       (uVar3 = *(ushort *)((int)pdVar16 + 6), aiStack_148[uVar3] = 0,
                       (uVar3 & 0x20) != 0)) {
                      bVar1 = true;
                    }
                    uVar18 = uVar18 + 1;
                    if (uVar21 < uVar18) break;
                    dVar4 = *pdVar19;
                    pdVar19 = pdVar19 + 0x12;
                    pdVar27 = pdVar13 + 0x12;
                    pdVar16 = pdVar13;
                  } while (dVar4 == 1);
                  if (bVar1) {
                    iVar7 = 0x20;
                    iVar31 = 0;
                    piVar15 = aiStack_c8;
                    do {
                      if (*piVar15 == 0) {
                        if (aiStack_148[iVar31] != -1) {
                          piVar8 = aiStack_148 + iVar31 + 1;
                          do {
                            iVar5 = *piVar8;
                            iVar31 = iVar31 + 1;
                            piVar8 = piVar8 + 1;
                          } while (iVar5 != -1);
                        }
                        *piVar15 = iVar31;
                        aiStack_148[iVar31] = iVar7;
                      }
                      bVar1 = iVar7 != 0x3f;
                      piVar15 = piVar15 + 1;
                      iVar7 = iVar7 + 1;
                    } while (bVar1);
                    pdVar19 = (dword *)(param_1 + 0x56);
                    puVar28 = (ushort *)(param_1 + 0x62);
                    param_5 = (dword *)(param_1 + 0x54);
                    puVar22 = (ushort *)(param_1 + 0x66);
                    puVar23 = (ushort *)(param_1 + 0x4e);
                    pcVar24 = (char *)(param_1 + 0x53);
                    puVar25 = (ushort *)(param_1 + 0x4c);
                    pcVar26 = (char *)(param_1 + 0x51);
                    puVar29 = (ushort *)(param_1 + 100);
                    puVar20 = (ushort *)(param_1 + 0x60);
                    pcVar10 = (char *)(param_1 + 0x68);
                    puVar11 = (ushort *)(param_1 + 0x5a);
                    puVar12 = (ushort *)(param_1 + 0x58);
                    uVar18 = 1;
                    pcVar17 = (char *)(param_1 + 0x5c);
                    pdVar16 = pdVar19;
                    pdVar27 = param_5;
                    puVar30 = puVar28;
                    do {
                      uVar6 = *pdVar14;
                      if (uVar6 != 2) {
                        if (uVar6 < 3) {
                          if (uVar6 == 1) {
                            if ((*pcVar26 != '\0') && (iVar7 = aiStack_148[*puVar25], iVar7 != -1))
                            {
                              *puVar25 = (ushort)iVar7;
                            }
                            if ((*pcVar24 != '\0') && (iVar7 = aiStack_148[*puVar23], iVar7 != -1))
                            {
                              *puVar23 = (ushort)iVar7;
                            }
                          }
                        }
                        else if (uVar6 < 5) {
                          if ((*pcVar17 != '\0') &&
                             (iVar7 = aiStack_148[*(ushort *)param_5], iVar7 != -1)) {
                            *(ushort *)param_5 = (ushort)iVar7;
                          }
                          if (((*(ushort *)pdVar19 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*(ushort *)pdVar19], iVar7 != -1)) {
                            *(ushort *)pdVar19 = (ushort)iVar7;
                          }
                          if (((*puVar12 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*puVar12], iVar7 != -1)) {
                            *puVar12 = (ushort)iVar7;
                          }
                          if (((*puVar11 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*puVar11], iVar7 != -1)) {
                            *puVar11 = (ushort)iVar7;
                          }
                          if ((*pcVar10 != '\0') && (iVar7 = aiStack_148[*puVar20], iVar7 != -1)) {
                            *puVar20 = (ushort)iVar7;
                          }
                          if (((*puVar30 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*puVar30], iVar7 != -1)) {
                            *puVar30 = (ushort)iVar7;
                          }
                          if (((*puVar29 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*puVar29], iVar7 != -1)) {
                            *puVar29 = (ushort)iVar7;
                          }
                          if (((*puVar22 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*puVar22], iVar7 != -1)) {
                            *puVar22 = (ushort)iVar7;
                          }
                        }
                        goto LAB_000bf33c;
                      }
                      bVar2 = *(byte *)puVar28;
                      if (bVar2 == 2) {
LAB_000bf224:
                        iVar7 = aiStack_148[*(ushort *)pdVar16];
                        if (iVar7 != -1) {
                          *(ushort *)pdVar16 = (ushort)iVar7;
                        }
                      }
                      else if (bVar2 < 3) {
                        if (bVar2 == 1) {
LAB_000bf20c:
                          iVar7 = aiStack_148[*(ushort *)pdVar27];
                          if (iVar7 != -1) {
                            *(ushort *)pdVar27 = (ushort)iVar7;
                          }
                          goto LAB_000bf224;
                        }
                      }
                      else if (bVar2 < 5) goto LAB_000bf20c;
LAB_000bf33c:
                      uVar18 = uVar18 + 1;
                      pdVar14 = pdVar14 + 0x12;
                      pdVar16 = pdVar16 + 0x12;
                      puVar22 = puVar22 + 0x24;
                      puVar23 = puVar23 + 0x24;
                      pcVar24 = pcVar24 + 0x48;
                      puVar25 = puVar25 + 0x24;
                      pcVar26 = pcVar26 + 0x48;
                      pdVar27 = pdVar27 + 0x12;
                      puVar28 = puVar28 + 0x24;
                      puVar29 = puVar29 + 0x24;
                      puVar30 = puVar30 + 0x24;
                      puVar20 = puVar20 + 0x24;
                      pcVar10 = pcVar10 + 0x48;
                      puVar11 = puVar11 + 0x24;
                      puVar12 = puVar12 + 0x24;
                      pdVar19 = pdVar19 + 0x12;
                      param_5 = param_5 + 0x12;
                      pcVar17 = pcVar17 + 0x48;
                    } while (uVar18 <= uVar21);
                  }
                }
                ((int (*)())FUN_000be460)(param_1,param_2,param_3,1,param_5,aiStack_148,pdVar16);
                uVar9 = 0;
              }
              else {
                uVar9 = 0x80000013;
              }
            }
            else {
              uVar9 = 0x80000012;
            }
          }
          else {
            uVar9 = 0x80000017;
          }
        }
        else {
          uVar9 = 0x80000016;
        }
      }
      else {
        uVar9 = 0x80000015;
      }
    }
    else {
      uVar9 = 0x80000014;
    }
  }
  else {
    uVar9 = 0x80000011;
  }
  return uVar9;
}

/* FUN_000bf400 @ 0xbf400 (1260 bytes) */
int FUN_000bf400(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  char cVar10;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  undefined1 *puVar16;
  uint uVar17;
  uint uVar18;
  byte bVar19;
  
  if (param_2 <= (*(byte *)(param_1 + 0xf) & 0xf)) {
    return;
  }
  uVar12 = *(uint *)(param_1 + 8);
  if ((*(int *)(param_1 + 0x48) == 1) && (uVar12 != 0)) {
    piVar9 = (int *)(param_1 + 0x90);
    uVar11 = 1;
    do {
      uVar11 = uVar11 + 1;
      if (*piVar9 != 1) goto LAB_000bf474;
      piVar9 = piVar9 + 0x12;
    } while (uVar11 <= uVar12);
LAB_000bf44c:
    bVar19 = 0;
    uVar18 = 0;
    bVar3 = true;
  }
  else {
    uVar11 = 1;
LAB_000bf474:
    if (uVar12 < uVar11) goto LAB_000bf44c;
    bVar19 = 0;
    bVar3 = true;
    puVar14 = (uint *)(param_1 + uVar11 * 0x48);
    uVar17 = 0;
    uVar13 = 0;
    bVar1 = false;
    uVar18 = 0;
    uVar15 = uVar11;
    do {
      uVar4 = *puVar14;
      if (uVar4 < 5) {
        if (uVar4 < 3) {
          if ((uVar4 == 2) &&
             (bVar19 = bVar19 | *(byte *)(puVar14 + 1) | *(byte *)((int)puVar14 + 0x1b),
             *(char *)((int)puVar14 + 0x1a) != '\0')) {
            uVar18 = uVar18 | -(puVar14[7] & 0xffff00) >> 0x1f;
          }
        }
        else {
          bVar19 = bVar19 | *(byte *)(puVar14 + 1);
        }
      }
      else if ((uVar4 == 5) && (bVar19 = bVar19 | *(byte *)(puVar14 + 1), bVar3)) {
        if ((*(char *)((int)puVar14 + 0xe) != '\0') || (*(char *)((int)puVar14 + 0x11) != '\0')) {
          bVar1 = true;
        }
        uVar4 = puVar14[4] & 0xff00ff00;
        if ((uVar4 != 0) &&
           ((*(ushort *)(puVar14 + 3) < uVar13 || (*(char *)((int)puVar14 + 0x19) != '\0')))) {
          bVar1 = true;
        }
        cVar5 = *(char *)(puVar14 + 5);
        cVar6 = *(char *)((int)puVar14 + 0x15);
        cVar10 = cVar5;
        if ((uVar4 != 0) && (cVar10 = cVar6, uVar4 == 0x100ff00)) {
          cVar5 = cVar6;
        }
        cVar6 = cVar10;
        if ((cVar5 == '\x01') || (cVar6 = cVar5, cVar5 != '\0')) {
          if (cVar6 == '\x02') goto LAB_000bf5b4;
          if (cVar6 == '\x01') {
            uVar17 = uVar17 - *(byte *)((int)puVar14 + 0x13);
          }
        }
        else if (cVar10 == '\x02') {
LAB_000bf5b4:
          uVar17 = uVar17 + 1;
        }
        bVar3 = !bVar1;
        if (4 < uVar17) {
          bVar1 = true;
          bVar3 = false;
        }
      }
      uVar15 = uVar15 + 1;
      uVar13 = uVar13 + 1;
      puVar14 = puVar14 + 0x12;
    } while (uVar15 <= uVar12);
    if (uVar13 != 0) goto LAB_000bf45c;
  }
  uVar13 = 1;
LAB_000bf45c:
  if ((*(short *)(param_1 + 0x20) == 0) && (*(short *)(param_1 + 0x12) == 0)) {
    *(short *)(param_1 + 0x12) = (short)uVar13 + -1;
  }
  if (!bVar3) {
    *(undefined2 *)(param_1 + 0x28) = 1;
  }
  if ((*(short *)(param_1 + 0x28) != 0) && (*(short *)(param_1 + 0x22) == 0)) {
    *(undefined2 *)(param_1 + 0x22) = 1;
  }
  if (uVar11 <= uVar12) {
    bVar1 = bVar19 != 0;
    puVar14 = (uint *)(param_1 + uVar11 * 0x48);
    uVar17 = 0;
    puVar16 = (undefined1 *)((int)puVar14 + -3);
    uVar15 = 100000;
    uVar13 = uVar11;
    do {
      uVar7 = *puVar14;
      uVar4 = uVar15;
      if (uVar7 < 5) {
        if (uVar7 < 3) {
          if (uVar7 == 2) {
            if (uVar18 == 0) {
              *(undefined1 *)((int)puVar14 + 0x1d) = 7;
              *(undefined1 *)((int)puVar14 + 0x1e) = 1;
              puVar14[5] = puVar14[5] & 0xffff | 0x1b1b0000;
            }
            bVar2 = *(byte *)((int)puVar14 + 0x1f);
            if (bVar2 != 0) {
              if ((bVar2 & 2) != 0) {
                puVar14[5] = puVar14[5] >> 2 & 0x300000 | puVar14[5] & 0xffcfffff;
              }
              if ((bVar2 & 4) != 0) {
                puVar14[5] = puVar14[5] >> 4 & 0xc0000 | puVar14[5] & 0xfff3ffff;
              }
              if ((bVar2 & 8) != 0) {
                puVar14[5] = puVar14[5] >> 6 & 0x30000 | puVar14[5] & 0xfffcffff;
              }
            }
            uVar4 = uVar13;
            if (((!bVar1) && (*(char *)(puVar14 + 8) != '\0')) && (uVar15 != 100000)) {
              iVar8 = param_1 + uVar15 * 0x48;
              *(undefined1 *)(iVar8 + 4) = 1;
              *(undefined1 *)(iVar8 + 0x1b) = 1;
              *(undefined1 *)(puVar14 + 1) = 1;
            }
          }
        }
        else {
          if (((*(char *)((int)puVar14 + 0x15) == '\0') && ((puVar14[8] & 0xff00ff) == 0)) &&
             (uVar17 != *(ushort *)(param_1 + 0x12))) {
            *puVar14 = 4;
          }
          if ((bVar1) || (uVar15 == 100000)) {
LAB_000bf860:
            uVar4 = 100000;
          }
          else {
            iVar8 = param_1 + uVar15 * 0x48;
            *(undefined1 *)(iVar8 + 4) = 1;
            *(undefined1 *)(iVar8 + 0x1b) = 1;
            *(undefined1 *)(puVar14 + 1) = 1;
            uVar4 = 100000;
          }
        }
      }
      else if (uVar7 == 5) {
        if ((!bVar1) && (uVar15 != 100000)) {
          iVar8 = param_1 + uVar15 * 0x48;
          *(undefined1 *)(iVar8 + 4) = 1;
          *(undefined1 *)(iVar8 + 0x1b) = 1;
          *(undefined1 *)(puVar14 + 1) = 1;
        }
        if ((((byte)(*(byte *)((int)puVar14 + 0x12) & 0xf0) ==
              (byte)(*(byte *)((int)puVar14 + 0x12) << 4)) || (uVar17 == 0)) ||
           (1 < *(int *)(puVar16 + -0x45) - 3U)) goto LAB_000bf860;
        *puVar16 = 1;
        uVar4 = 100000;
      }
      uVar13 = uVar13 + 1;
      uVar17 = uVar17 + 1;
      puVar14 = puVar14 + 0x12;
      puVar16 = puVar16 + 0x48;
      uVar15 = uVar4;
    } while (uVar13 <= uVar12);
    if (((uVar17 != 0) &&
        (iVar8 = (*(ushort *)(param_1 + 0x12) + uVar11) * 0x48, *(int *)(param_1 + iVar8) == 3)) &&
       (bVar19 == 0)) {
      *(undefined1 *)(param_1 + iVar8 + 4) = 1;
    }
  }
  if (((uVar18 != 0) || (bVar19 != 0)) || (*(short *)(param_1 + 0x20) != 0)) {
    param_2 = param_2 | param_2 << 4;
  }
  *(char *)(param_1 + 0xf) = (char)param_2;
  return;
}

/* FUN_000bf910 @ 0xbf910 (796 bytes) */
int FUN_000bf910(param_1, param_2, param_3, param_4)
  uint *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x80) != 0) {
    *param_1 = uVar1 & 0xffffff7f;
    return;
  }
  switch(uVar1) {
  case 0:
    *param_1 = 0;
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 2;
    return;
  case 1:
    *param_1 = 0;
    *param_2 = 0;
    *param_3 = 0;
    *param_4 = 0;
    return;
  case 2:
    uVar2 = 1;
    break;
  case 3:
    uVar2 = 2;
    break;
  case 4:
    *param_1 = 1;
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 2;
    return;
  case 5:
    uVar2 = 0;
    goto LAB_000bfac8;
  case 6:
    *param_1 = 1;
    *param_2 = 1;
    *param_3 = 1;
    *param_4 = 1;
    return;
  case 7:
    uVar2 = 2;
    goto LAB_000bfac8;
  case 8:
    *param_1 = 2;
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 2;
    return;
  case 9:
    uVar2 = 0;
    goto LAB_000bfae4;
  case 10:
    uVar2 = 1;
    goto LAB_000bfae4;
  case 0xb:
    *param_1 = 2;
    *param_2 = 2;
    *param_3 = 2;
    *param_4 = 2;
    return;
  case 0xc:
    uVar2 = 3;
    break;
  case 0xd:
    uVar2 = 3;
LAB_000bfac8:
    *param_1 = 1;
    *param_2 = uVar2;
    *param_3 = uVar2;
    *param_4 = uVar2;
    return;
  case 0xe:
    uVar2 = 3;
LAB_000bfae4:
    *param_1 = 2;
    *param_2 = uVar2;
    *param_3 = uVar2;
    *param_4 = uVar2;
    return;
  case 0xf:
    *param_1 = 3;
    *param_2 = 0;
    *param_3 = 1;
    *param_4 = 2;
    return;
  case 0x10:
    uVar2 = 0;
    goto LAB_000bfb34;
  case 0x11:
    uVar2 = 1;
    goto LAB_000bfb34;
  case 0x12:
    uVar2 = 2;
LAB_000bfb34:
    *param_1 = 3;
    *param_2 = uVar2;
    *param_3 = uVar2;
    *param_4 = uVar2;
    return;
  case 0x13:
    *param_1 = 3;
    *param_2 = 3;
    *param_3 = 3;
    *param_4 = 3;
    return;
  case 0x14:
    uVar2 = 4;
    break;
  case 0x15:
    uVar2 = 6;
    break;
  case 0x16:
    uVar2 = 5;
    break;
  case 0x17:
    *param_1 = 0;
    *param_2 = 1;
    *param_3 = 2;
    *param_4 = 0;
    return;
  case 0x18:
    *param_1 = 1;
    *param_2 = 1;
    *param_3 = 2;
    *param_4 = 0;
    return;
  case 0x19:
    *param_1 = 2;
    *param_2 = 1;
    *param_3 = 2;
    *param_4 = 0;
    return;
  case 0x1a:
    *param_1 = 0;
    *param_2 = 2;
    *param_3 = 0;
    *param_4 = 1;
    return;
  case 0x1b:
    *param_1 = 1;
    *param_2 = 2;
    *param_3 = 0;
    *param_4 = 1;
    return;
  case 0x1c:
    *param_1 = 2;
    *param_2 = 2;
    *param_3 = 0;
    *param_4 = 1;
    return;
  case 0x1d:
    *param_1 = 0;
    *param_2 = 3;
    *param_3 = 2;
    *param_4 = 1;
    return;
  case 0x1e:
    *param_1 = 1;
    *param_2 = 3;
    *param_3 = 2;
    *param_4 = 1;
    return;
  case 0x1f:
    *param_1 = 2;
    *param_2 = 3;
    *param_3 = 2;
    *param_4 = 1;
    return;
  default:
    return;
  }
  *param_1 = 0;
  *param_2 = uVar2;
  *param_3 = uVar2;
  *param_4 = uVar2;
  return;
}

/* FUN_000bfcc0 @ 0xbfcc0 (440 bytes) */
int FUN_000bfcc0(param_1, param_2)
  uint *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x80) == 0) {
    switch(uVar1) {
    case 0:
      *param_1 = 0;
      *param_2 = 0;
      return;
    case 1:
      *param_1 = 0;
      *param_2 = 1;
      return;
    case 2:
      *param_1 = 0;
      *param_2 = 2;
      return;
    case 3:
      *param_1 = 1;
      *param_2 = 0;
      return;
    case 4:
      *param_1 = 1;
      *param_2 = 1;
      return;
    case 5:
      *param_1 = 1;
      *param_2 = 2;
      return;
    case 6:
      *param_1 = 2;
      *param_2 = 0;
      return;
    case 7:
      *param_1 = 2;
      *param_2 = 1;
      return;
    case 8:
      *param_1 = 2;
      *param_2 = 2;
      return;
    case 9:
      *param_1 = 0;
      *param_2 = 3;
      return;
    case 10:
      *param_1 = 1;
      *param_2 = 3;
      return;
    case 0xb:
      *param_1 = 2;
      *param_2 = 3;
      return;
    case 0xc:
      *param_1 = 3;
      *param_2 = 0;
      return;
    case 0xd:
      *param_1 = 3;
      *param_2 = 1;
      return;
    case 0xe:
      *param_1 = 3;
      *param_2 = 2;
      return;
    case 0xf:
      *param_1 = 3;
      *param_2 = 3;
      return;
    case 0x10:
      *param_1 = 0;
      *param_2 = 4;
      return;
    case 0x11:
      *param_1 = 0;
      *param_2 = 6;
      return;
    case 0x12:
      *param_1 = 0;
      *param_2 = 5;
      return;
    default:
      return;
    }
  }
  *param_1 = uVar1 & 0xffffff7f;
  return;
}

/* FUN_000bfed0 @ 0xbfed0 (2464 bytes) */
int FUN_000bfed0(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  uint *param_3;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  ushort uVar17;
  ushort uVar18;
  ushort uVar19;
  ushort uVar20;
  ushort uVar21;
  ushort uVar22;
  ushort uVar23;
  ushort uVar24;
  bool bVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  int *piVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  undefined4 in_r6;
  undefined4 in_r7;
  int *piVar45;
  undefined4 in_r8;
  int *piVar46;
  uint uVar47;
  uint uVar48;
  int iVar49;
  uint uVar50;
  uint uVar51;
  int *piVar52;
  int iVar53;
  uint uVar54;
  uint uVar55;
  int iVar56;
  int iVar57;
  byte bVar58;
  uint uVar59;
  uint *puVar60;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint *local_68;
  uint *local_64;
  uint *local_60;
  
  puVar60 = param_3;
  ((int (*)())FUN_000c5e60)(param_1);
  if (0x10 < *(ushort *)(param_1 + 0x18)) {
    return 0x80000014;
  }
  if (0x200 < (uint)*(ushort *)(param_1 + 0x1a) + (uint)*(ushort *)(param_1 + 0x1c) +
              (uint)*(ushort *)(param_1 + 0x20)) {
    return 0x80000018;
  }
  if (0x7f < *(ushort *)(param_1 + 0x22)) {
    return 0x80000012;
  }
  if (0xff < *(ushort *)(param_1 + 0x24)) {
    return 0x80000013;
  }
  ((int (*)())FUN_000bf400)(param_1,1,puVar60,in_r6,in_r7,in_r8,(uint)*(ushort *)(param_1 + 0x20));
  uVar55 = *(uint *)(param_1 + 8);
  if ((*(int *)(param_1 + 0x48) == 1) && (uVar55 != 0)) {
    piVar46 = (int *)(param_1 + 0x90);
    uVar59 = 1;
    piVar39 = piVar46;
    uVar43 = 0;
    piVar52 = (int *)(param_1 + 0x48);
    do {
      piVar45 = piVar39;
      uVar48 = uVar43;
      if ((piVar52[2] & 0xff00ffU) != 0) {
        uVar48 = uVar43 + 1;
        param_2[uVar43 + 1] = 0;
        bVar58 = *(byte *)(piVar52 + 2);
        param_2[uVar43 + 1] = bVar58 & 0xf;
        uVar40 = (*(byte *)((int)piVar52 + 9) & 1) << 4 | bVar58 & 0xf;
        param_2[uVar43 + 1] = uVar40;
        uVar40 = (*(byte *)((int)piVar52 + 10) & 0xf) << 0xc | uVar40;
        param_2[uVar43 + 1] = uVar40;
        uVar40 = (*(byte *)((int)piVar52 + 0xb) & 3) << 0x10 | uVar40;
        param_2[uVar43 + 1] = uVar40;
        uVar40 = (*(byte *)(piVar52 + 3) & 1) << 0x19 | uVar40;
        param_2[uVar43 + 1] = uVar40;
        uVar40 = (*(ushort *)(piVar52 + 1) & 0x7f) << 5 | uVar40;
        param_2[uVar43 + 1] = uVar40;
        param_2[uVar43 + 1] = (*(ushort *)((int)piVar52 + 6) & 0x7f) << 0x12 | uVar40;
      }
      uVar59 = uVar59 + 1;
      if (*piVar46 != 1) break;
      piVar46 = piVar46 + 0x12;
      piVar39 = piVar45 + 0x12;
      uVar43 = uVar48;
      piVar52 = piVar45;
    } while (uVar59 <= uVar55);
    uVar43 = uVar48 & 0xff;
    if (uVar48 == 0) goto LAB_000c004c;
  }
  else {
    uVar59 = 1;
LAB_000c004c:
    uVar43 = 1;
    param_2[1] = 0;
  }
  uVar43 = uVar43 - 1 & 0xf;
  *param_2 = uVar43;
  *param_2 = (*(byte *)(param_1 + 0xd) & 7) << 5 | uVar43;
  if (uVar55 < uVar59) {
    iVar56 = 0;
    bVar58 = 0;
    iVar53 = 0;
    iVar49 = 1;
  }
  else {
    local_68 = &local_6c;
    local_60 = &local_70;
    bVar58 = 0;
    puVar60 = (uint *)(uVar59 * 0x48 + param_1);
    local_64 = &local_74;
    bVar25 = true;
    iVar49 = 0;
    iVar56 = 0;
    do {
      iVar57 = iVar56;
      uVar43 = *puVar60;
      uVar48 = 0;
      if (uVar43 < 5) {
        if (uVar43 < 3) {
          if (uVar43 == 2) {
            uVar24 = *(ushort *)((int)puVar60 + 0xe);
            uVar17 = *(ushort *)(puVar60 + 3);
            bVar25 = true;
            uVar43 = puVar60[5];
            bVar1 = *(byte *)((int)puVar60 + 6);
            bVar2 = *(byte *)((int)puVar60 + 7);
            bVar3 = *(byte *)(puVar60 + 2);
            bVar4 = *(byte *)((int)puVar60 + 9);
            bVar5 = *(byte *)((int)puVar60 + 0xb);
            bVar6 = *(byte *)((int)puVar60 + 0x1d);
            bVar7 = *(byte *)((int)puVar60 + 0x1e);
            uVar18 = *(ushort *)(puVar60 + 4);
            uVar19 = *(ushort *)((int)puVar60 + 0x12);
            bVar8 = *(byte *)(puVar60 + 1);
            bVar9 = *(byte *)((int)puVar60 + 5);
            *(uint *)(iVar49 + param_3[4] + 4) =
                 (*(byte *)((int)puVar60 + 0x1b) & 1) << 0x19 |
                 (*(byte *)(puVar60 + 7) & 1) << 0x1a |
                 (*(byte *)(puVar60 + 6) & 1) << 0x1b |
                 (*(byte *)((int)puVar60 + 0x1a) & 7) << 0x16 |
                 (*(byte *)((int)puVar60 + 0x19) & 0xf) << 0x10;
            *(uint *)(iVar49 + param_3[4] + 8) =
                 (uVar43 & 0x3000000) << 6 |
                 (uVar43 & 0xc000000) << 2 |
                 uVar43 >> 2 & 0xc000000 |
                 uVar43 >> 6 & 0x3000000 |
                 uVar43 >> 2 & 0xc000 |
                 uVar43 >> 6 & 0x3000 |
                 uVar43 >> 10 & 0xc00 |
                 uVar43 >> 0xe & 0x300 |
                 (uVar17 & 0x4000) << 9 |
                 (uVar17 & 0x7f) << 0x10 | uVar24 >> 7 & 0x80 | uVar24 & 0x7f;
            uVar48 = (bVar7 & 1) << 0xe |
                     (bVar6 & 7) << 0xb |
                     (bVar5 & 1) << 10 |
                     (bVar4 & 1) << 7 |
                     (bVar3 & 1) << 0x16 |
                     (bVar2 & 7) << 0x19 |
                     (bVar1 & 1) << 6 | (bVar9 & 7) << 3 | (bVar8 & 1) << 2 | 3;
            *(uint *)(iVar49 + param_3[4] + 0xc) =
                 uVar43 << 0x1e |
                 (uVar43 & 0xc) << 0x1a |
                 (uVar43 & 0x30) << 0x16 |
                 (uVar43 & 0xc0) << 0x12 |
                 (uVar43 & 0x300) << 6 |
                 (uVar43 & 0xc00) << 2 |
                 uVar43 >> 2 & 0xc00 |
                 uVar43 >> 6 & 0x300 |
                 (uVar19 & 0x4000) << 9 |
                 (uVar19 & 0x7f) << 0x10 | uVar18 >> 7 & 0x80 | uVar18 & 0x7f;
            *(undefined4 *)(iVar49 + param_3[4] + 0x10) = 0;
            *(undefined4 *)(iVar49 + param_3[4] + 0x14) = 0;
          }
        }
        else {
          uVar24 = *(ushort *)((int)puVar60 + 0xe);
          uVar40 = 0xffffff80;
          uVar48 = (*(byte *)(puVar60 + 0x11) & 3) << 0x17 |
                   (*(byte *)((int)puVar60 + 0x43) & 1) << 0x15 |
                   (*(byte *)(puVar60 + 0xd) & 1) << 9 |
                   (*(byte *)((int)puVar60 + 0x42) & 1) << 0x14 |
                   (*(byte *)((int)puVar60 + 0x33) & 1) << 0x13 |
                   (*(byte *)((int)puVar60 + 0x21) & 1) << 0x12 |
                   (*(byte *)((int)puVar60 + 0x15) & 7) << 0xf |
                   (*(byte *)(puVar60 + 8) & 1) << 0xe |
                   (*(byte *)(puVar60 + 5) & 7) << 0xb |
                   (*(byte *)((int)puVar60 + 10) & 1) << 8 |
                   (*(byte *)((int)puVar60 + 9) & 1) << 7 |
                   (*(byte *)(puVar60 + 2) & 1) << 0x16 |
                   (*(byte *)((int)puVar60 + 7) & 7) << 0x19 |
                   (*(byte *)((int)puVar60 + 6) & 1) << 6 |
                   (*(byte *)((int)puVar60 + 5) & 7) << 3 |
                   (*(byte *)(puVar60 + 1) & 1) << 2 | (uint)(uVar43 == 3);
          if ((uVar24 & 0x2000) == 0) {
            uVar40 = 0;
          }
          uVar17 = *(ushort *)(puVar60 + 4);
          uVar43 = 0xffffff80;
          if ((uVar17 & 0x2000) == 0) {
            uVar43 = 0;
          }
          uVar18 = *(ushort *)((int)puVar60 + 0x12);
          uVar47 = 0xffffff80;
          if ((uVar18 & 0x2000) == 0) {
            uVar47 = 0;
          }
          uVar19 = *(ushort *)((int)puVar60 + 0x1a);
          bVar1 = *(byte *)(puVar60 + 0xc);
          uVar50 = 0xffffff80;
          if ((uVar19 & 0x2000) == 0) {
            uVar50 = 0;
          }
          uVar20 = *(ushort *)(puVar60 + 7);
          uVar54 = 0xffffff80;
          if ((uVar20 & 0x2000) == 0) {
            uVar54 = 0;
          }
          uVar21 = *(ushort *)((int)puVar60 + 0x1e);
          uVar51 = 0xffffff80;
          if ((uVar21 & 0x2000) == 0) {
            uVar51 = 0;
          }
          local_6c = (uint)*(byte *)((int)puVar60 + 0x2a);
          bVar2 = *(byte *)((int)puVar60 + 0x3f);
          uVar41 = puVar60[9];
          local_70 = uVar41 >> 0x17 & 7;
          local_78 = uVar41 >> 0x1d;
          local_74 = uVar41 >> 0x1a & 7;
          ((int (*)())FUN_000bf910)(local_68,&local_78,local_64,local_60);
          uVar41 = local_6c & 3;
          uVar26 = local_78 & 7;
          uVar27 = local_74 & 7;
          uVar44 = puVar60[9];
          uVar28 = local_70 & 7;
          local_6c = uVar44 >> 7 & 7;
          local_74 = uVar44 >> 0xd & 7;
          local_78 = uVar44 >> 10 & 7;
          local_70 = (uint)*(byte *)((int)puVar60 + 0x2b);
          ((int (*)())FUN_000bf910)(local_60,local_64,&local_78,local_68);
          bVar3 = *(byte *)((int)puVar60 + 0x2d);
          bVar4 = *(byte *)((int)puVar60 + 0x2e);
          bVar5 = *(byte *)((int)puVar60 + 0x32);
          bVar6 = *(byte *)((int)puVar60 + 0x16);
          bVar7 = *(byte *)((int)puVar60 + 0x45);
          uVar44 = local_70 & 3;
          uVar29 = local_74 & 7;
          uVar30 = local_78 & 7;
          uVar31 = local_6c & 7;
          local_78 = (uint)*(byte *)((int)puVar60 + 0x36);
          local_6c = (uint)*(byte *)((int)puVar60 + 0x39);
          ((int (*)())FUN_000bfcc0)(local_68,&local_78);
          uVar32 = local_6c & 3;
          uVar33 = local_78 & 7;
          local_6c = (uint)*(byte *)((int)puVar60 + 0x37);
          local_78 = (uint)*(byte *)((int)puVar60 + 0x3a);
          ((int (*)())FUN_000bfcc0)(&local_78,local_68);
          bVar8 = *(byte *)(puVar60 + 0xf);
          bVar9 = *(byte *)((int)puVar60 + 0x3d);
          uVar22 = *(ushort *)(puVar60 + 3);
          bVar10 = *(byte *)((int)puVar60 + 0x41);
          bVar11 = *(byte *)((int)puVar60 + 0x22);
          uVar23 = *(ushort *)(puVar60 + 6);
          uVar34 = local_78 & 3;
          bVar12 = *(byte *)((int)puVar60 + 0x23);
          bVar13 = *(byte *)(puVar60 + 0x10);
          uVar35 = local_6c & 7;
          bVar14 = *(byte *)((int)puVar60 + 0x31);
          uVar42 = puVar60[10];
          local_78 = uVar42 >> 0x1d;
          local_70 = uVar42 >> 0x17 & 7;
          local_74 = uVar42 >> 0x1a & 7;
          local_6c = (uint)*(byte *)(puVar60 + 0xb);
          ((int (*)())FUN_000bf910)(local_68,&local_78,local_64,local_60);
          uVar42 = local_6c & 3;
          uVar36 = local_78 & 7;
          uVar37 = local_74 & 7;
          local_78 = (uint)*(byte *)(puVar60 + 0xe);
          uVar38 = local_70 & 7;
          local_70 = (uint)*(byte *)((int)puVar60 + 0x3b);
          ((int (*)())FUN_000bfcc0)(local_60,&local_78);
          bVar25 = false;
          bVar15 = *(byte *)((int)puVar60 + 0x2f);
          bVar16 = *(byte *)((int)puVar60 + 0x3e);
          *(uint *)(iVar49 + param_3[4] + 4) =
               (uint)bVar1 << 0x1e |
               (uVar18 & 0x4000) << 0xf |
               (uVar18 & 0x8000) << 0xd |
               (uVar47 & 0xff | uVar18 & 0x7f) << 0x14 |
               (uVar17 & 0x4000) << 5 |
               (uVar17 & 0x8000) << 3 |
               (uVar43 & 0xff | uVar17 & 0x7f) << 10 |
               uVar24 >> 5 & 0x200 | uVar24 >> 7 & 0x100 | uVar40 & 0xff | uVar24 & 0x7f;
          *(uint *)(iVar49 + param_3[4] + 8) =
               (uint)bVar2 << 0x1e |
               (uVar21 & 0x4000) << 0xf |
               (uVar21 & 0x8000) << 0xd |
               (uVar51 & 0xff | uVar21 & 0x7f) << 0x14 |
               (uVar20 & 0x4000) << 5 |
               (uVar20 & 0x8000) << 3 |
               (uVar54 & 0xff | uVar20 & 0x7f) << 10 |
               uVar19 >> 5 & 0x200 | uVar19 >> 7 & 0x100 | uVar50 & 0xff | uVar19 & 0x7f;
          *(uint *)(iVar49 + param_3[4] + 0xc) =
               (uint)bVar7 << 0x1f |
               (bVar6 & 3) << 0x1d |
               (bVar5 & 7) << 0x1a |
               (bVar4 & 3) << 0x18 |
               (bVar3 & 3) << 0xb |
               uVar31 << 0x15 |
               uVar30 << 0x12 |
               uVar29 << 0xf | uVar44 << 0xd | uVar28 << 8 | uVar27 << 5 | uVar26 << 2 | uVar41;
          *(uint *)(iVar49 + param_3[4] + 0x10) =
               uVar23 >> 3 & 0x800 |
               (uVar23 & 0x7f) << 4 |
               bVar13 & 0xf |
               (uint)bVar12 << 0x1f |
               (bVar11 & 3) << 0x1d |
               (bVar10 & 7) << 0x1a |
               (bVar9 & 3) << 0x18 |
               (bVar8 & 3) << 0x11 | uVar35 << 0x15 | uVar34 << 0x13 | uVar33 << 0xe | uVar32 << 0xc
          ;
          *(uint *)(iVar49 + param_3[4] + 0x14) =
               (uint)bVar16 << 0x1e |
               (bVar15 & 3) << 0x17 |
               (local_78 & 7) << 0x1b |
               (local_70 & 3) << 0x19 |
               uVar38 << 0x14 |
               uVar37 << 0x11 |
               uVar36 << 0xe |
               uVar42 << 0xc | uVar22 >> 3 & 0x800 | (uVar22 & 0x7f) << 4 | bVar14 & 0xf;
          if (*puVar60 == 3) {
            bVar58 = bVar58 | *(byte *)((int)puVar60 + 0x23);
          }
        }
      }
      else if (uVar43 == 5) {
        bVar1 = *(byte *)((int)puVar60 + 0xe);
        bVar2 = *(byte *)((int)puVar60 + 0xf);
        bVar25 = false;
        bVar3 = *(byte *)(puVar60 + 4);
        bVar4 = *(byte *)((int)puVar60 + 0x11);
        bVar5 = *(byte *)((int)puVar60 + 0x12);
        bVar6 = *(byte *)((int)puVar60 + 0x13);
        bVar7 = *(byte *)(puVar60 + 1);
        bVar8 = *(byte *)((int)puVar60 + 5);
        bVar9 = *(byte *)((int)puVar60 + 6);
        bVar10 = *(byte *)((int)puVar60 + 0xb);
        bVar11 = *(byte *)((int)puVar60 + 0x17);
        uVar24 = *(ushort *)(puVar60 + 3);
        bVar12 = *(byte *)((int)puVar60 + 0x19);
        bVar13 = *(byte *)((int)puVar60 + 0x16);
        bVar14 = *(byte *)(puVar60 + 5);
        bVar15 = *(byte *)(puVar60 + 6);
        bVar16 = *(byte *)((int)puVar60 + 0x15);
        *(undefined4 *)(param_3[4] + iVar49 + 4) = 0;
        uVar48 = (bVar10 & 1) << 10 | (bVar9 & 1) << 6 | (bVar8 & 7) << 3 | (bVar7 & 1) << 2 | 2;
        *(uint *)(param_3[4] + iVar49 + 8) =
             (bVar13 & 1) << 0x1c |
             (bVar16 & 3) << 0x1a |
             (bVar14 & 3) << 0x18 |
             (bVar6 & 0x1f) << 0x10 |
             (uint)bVar5 << 8 | (bVar4 & 3) << 6 | (bVar3 & 1) << 5 | (bVar2 & 1) << 4 | bVar1 & 7;
        *(uint *)(param_3[4] + iVar49 + 0xc) =
             (uint)bVar12 << 0x1f | (uVar24 & 0x1ff) << 0x10 | (bVar15 & 0x1f) << 8 | bVar11 & 0x1f;
        *(undefined4 *)(param_3[4] + iVar49 + 0x10) = 0;
        *(undefined4 *)(param_3[4] + iVar49 + 0x14) = 0;
      }
      uVar59 = uVar59 + 1;
      iVar56 = iVar57 + 1;
      puVar60 = puVar60 + 0x12;
      *(uint *)(param_3[4] + iVar49) = uVar48;
      iVar49 = iVar49 + 0x18;
    } while (uVar59 <= uVar55);
    iVar49 = iVar56;
    if (!bVar25) goto LAB_000c07dc;
    iVar53 = iVar56 * 0x18;
    iVar49 = iVar57 + 2;
  }
  *(undefined4 *)(param_3[4] + iVar53) = 0;
  *(undefined4 *)(iVar53 + param_3[4] + 4) = 0;
  *(undefined4 *)(iVar53 + param_3[4] + 8) = 0;
  *(undefined4 *)(iVar53 + param_3[4] + 0xc) = 0;
  *(undefined4 *)(iVar53 + param_3[4] + 0x10) = 0;
  *(undefined4 *)(iVar53 + param_3[4] + 0x14) = 0;
  *(uint *)(iVar53 + param_3[4]) = *(uint *)(iVar53 + param_3[4]) & 0xfffffffc | 1;
  *(uint *)(iVar53 + param_3[4]) = *(uint *)(iVar53 + param_3[4]) | 4;
  if ((iVar56 != 0) && ((uint)*(ushort *)(param_1 + 0x12) == iVar56 - 1U)) {
    *(short *)(param_1 + 0x12) = (short)iVar56;
  }
LAB_000c07dc:
  param_3[2] = 0;
  param_3[3] = (iVar49 + -1) * 0x10000 & 0x1ff0000;
  uVar55 = *(ushort *)(param_1 + 0x10) & 0x1ff;
  param_3[2] = uVar55;
  uVar24 = *(ushort *)(param_1 + 0x12);
  param_3[1] = 0;
  param_3[2] = (uVar24 & 0x1ff) << 0x10 | uVar55;
  uVar24 = *(ushort *)(param_1 + 0x28);
  *param_3 = 0;
  param_3[1] = (uint)uVar24 << 0x1f;
  uVar24 = *(ushort *)(param_1 + 0x22);
  param_3[5] = (uint)(bVar58 != 0);
  *param_3 = uVar24 & 0x7f;
  return 0;
}

/* FUN_000c0880 @ 0xc0880 (1832 bytes) */
int FUN_000c0880(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  ushort uVar16;
  int iVar17;
  uint uVar18;
  ushort *puVar19;
  int iVar20;
  undefined4 *puVar21;
  ushort uVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  uint uVar27;
  int iVar28;
  
  iVar28 = 0;
  iVar25 = 0;
  uVar27 = 0;
  iVar24 = 0;
  do {
    iVar14 = param_1 + iVar24 * 0x40;
    uVar4 = *(ushort *)(iVar14 + 0x28);
    *(undefined4 *)(iVar14 + 0x14) = 0;
    *(undefined4 *)(iVar14 + 0x20) = 0;
    *(undefined4 *)(iVar14 + 0x1c) = 0;
    *(undefined4 *)(iVar14 + 0x24) = 0;
    *(undefined4 *)(iVar14 + 0x18) = 0;
    uVar9 = *(uint *)(iVar14 + 0x30) & 0xffffff89;
    *(uint *)(iVar14 + 0x30) = uVar9;
    if (uVar4 == 2) {
      *(uint *)(iVar14 + 0x30) = uVar9 | 0x52;
      iVar28 = iVar14;
    }
    iVar26 = iVar24 + 1;
    if (uVar4 == 0xd) {
      iVar25 = iVar26;
    }
    bVar1 = (1 << ((int)(short)uVar4 & 0x3fU) & 0x1f1U) != 0;
    uVar9 = 0;
    iVar12 = iVar14;
    do {
      uVar6 = *(ushort *)(iVar14 + 8 + uVar9 * 4);
      uVar16 = *(ushort *)(iVar14 + 8 + uVar9 * 4 + 2);
      uVar23 = uVar6 & 3;
      uVar22 = uVar16 & 0x300;
      uVar13 = uVar16 & 0x1f;
      bVar2 = uVar22 == 0x300;
      if (bVar2) {
        *(uint *)(iVar14 + 0x30) = *(uint *)(iVar14 + 0x30) | 0x10;
      }
      if ((uVar4 == 3) && ((uVar13 | 0xfffffff9) == 0xffffffff)) {
        uVar18 = (1 < uVar9) + 3;
        if (uVar22 == 0x200) {
          uVar18 = uVar18 * 4 & 4 | uVar18 >> 1;
        }
        else if (bVar2) {
          uVar18 = uVar18 * 8 & 8 | uVar18 * 2 & 4 | uVar18 >> 1 & 2;
        }
        else if (uVar22 == 0x100) {
          uVar18 = uVar18 * 2 & 6 | uVar18 >> 2;
        }
        uVar13 = uVar18 & uVar13;
      }
      *(undefined2 *)(iVar12 + 0x34) = 0;
      puVar19 = (ushort *)(iVar12 + 0x34);
      if (((uVar13 & 0x10) == 0) &&
         (((uVar16 & 0x300) != 0 ||
          (((*(ushort *)(iVar14 + 6) | *(ushort *)(iVar14 + 2)) & 0xffef & ~uVar13) != 0)))) {
        *(undefined2 *)(iVar12 + 0x34) = 8;
      }
      bVar3 = uVar23 != 3;
      if (bVar3) {
        uVar18 = uVar23;
        if (uVar13 == 0x11) {
          *puVar19 = *puVar19 | 4;
        }
        else if (uVar13 == 0x12) {
          *puVar19 = *puVar19 | 2;
        }
        else if (uVar13 == 0x10) {
          *puVar19 = *puVar19 | 1;
        }
      }
      else {
        uVar27 = uVar6 & 0x300 | uVar27;
        iVar10 = ((uVar6 & 0x300) >> 8) - 1;
        uVar5 = *(ushort *)(iVar10 * 0x40 + param_1 + 0x2a);
        if (iVar24 != iVar10) {
          *(uint *)(iVar14 + 0x30) = *(uint *)(iVar14 + 0x30) | 0x20;
        }
        uVar23 = (uint)(uVar5 - 1 < 2);
        *puVar19 = *puVar19 | 0x10;
        uVar18 = 0;
      }
      if ((uVar16 & 0x1000) != 0) {
        *puVar19 = *puVar19 | 0x20;
      }
      if ((uVar16 & 0x2000) != 0) {
        *puVar19 = *puVar19 | 0x40;
      }
      if ((iVar24 == 1) && (uVar9 == 2)) {
        iVar28 = 0;
      }
      if ((uVar6 & 0x100) != 0) {
        uVar15 = uVar13 & 7;
        if ((uVar15 | 0xfffffff9) == 0xffffffff) {
          uVar16 = *(ushort *)(iVar14 + 6) | *(ushort *)(iVar14 + 2);
          uVar7 = (uint)uVar16;
          uVar11 = uVar7 & 0xffef;
          if (uVar22 == 0x200) {
            uVar11 = (uVar7 & 1) << 2 | uVar16 >> 1 & 3;
          }
          else if (bVar2) {
            uVar11 = (uVar7 & 2) << 1 | uVar16 >> 1 & 2;
          }
          else if (uVar22 == 0x100) {
            uVar11 = (uVar7 & 3) << 1 | uVar16 >> 2 & 1;
          }
          if ((uVar4 < 9) && (bVar1)) {
            uVar15 = uVar15 & uVar11;
          }
        }
        iVar10 = uVar18 * 2;
        iVar17 = iVar10 + iVar14;
        uVar16 = (ushort)uVar15;
        *(ushort *)(iVar17 + 0x14) = uVar16 | *(ushort *)(iVar17 + 0x14);
        if (iVar28 != 0) {
          *(ushort *)(iVar10 + iVar28 + 0x14) = uVar16 | *(ushort *)(iVar10 + iVar28 + 0x14);
        }
        if (!bVar3) {
          iVar20 = uVar23 * 2 + iVar14;
          *(ushort *)(iVar17 + 0x20) = uVar16 | *(ushort *)(iVar17 + 0x20);
          *(ushort *)(iVar20 + 0x14) = uVar16 | *(ushort *)(iVar20 + 0x14);
          *(ushort *)(iVar20 + 0x20) = uVar16 | *(ushort *)(iVar20 + 0x20);
          if (iVar28 != 0) {
            iVar17 = uVar23 * 2 + iVar28;
            uVar22 = *(ushort *)(iVar17 + 0x14);
            *(ushort *)(iVar10 + iVar28 + 0x20) = uVar16 | *(ushort *)(iVar10 + iVar28 + 0x20);
            *(ushort *)(iVar17 + 0x14) = uVar16 | uVar22;
            *(ushort *)(iVar17 + 0x20) = uVar16 | *(ushort *)(iVar17 + 0x20);
          }
        }
      }
      if ((uVar6 & 0x200) != 0) {
        uVar16 = (ushort)uVar13 & 8;
        if ((((bVar2) && (uVar4 < 9)) && (bVar1)) &&
           ((~(*(ushort *)(iVar14 + 6) | *(ushort *)(iVar14 + 2)) & 1) != 0)) {
          uVar16 = 0;
        }
        iVar10 = uVar18 * 2;
        iVar17 = iVar10 + iVar14;
        *(ushort *)(iVar17 + 0x1a) = uVar16 | *(ushort *)(iVar17 + 0x1a);
        if (iVar28 != 0) {
          *(ushort *)(iVar10 + iVar28 + 0x1a) = uVar16 | *(ushort *)(iVar10 + iVar28 + 0x1a);
        }
        if (!bVar3) {
          iVar20 = uVar23 * 2 + iVar14;
          *(ushort *)(iVar17 + 0x24) = uVar16 | *(ushort *)(iVar17 + 0x24);
          *(ushort *)(iVar20 + 0x1a) = uVar16 | *(ushort *)(iVar20 + 0x1a);
          *(ushort *)(iVar20 + 0x24) = uVar16 | *(ushort *)(iVar20 + 0x24);
          if (iVar28 != 0) {
            iVar17 = uVar23 * 2 + iVar28;
            uVar6 = *(ushort *)(iVar17 + 0x1a);
            *(ushort *)(iVar10 + iVar28 + 0x24) = uVar16 | *(ushort *)(iVar10 + iVar28 + 0x24);
            *(ushort *)(iVar17 + 0x1a) = uVar16 | uVar6;
            *(ushort *)(iVar17 + 0x24) = uVar16 | *(ushort *)(iVar17 + 0x24);
          }
        }
      }
      bVar2 = uVar9 != 2;
      iVar12 = iVar12 + 2;
      uVar9 = uVar9 + 1;
    } while (bVar2);
    iVar24 = iVar26;
  } while (iVar26 != 2);
  if (iVar25 == 1) {
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x54);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 100);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x58);
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 4;
  }
  else if (iVar25 == 2) {
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x14);
    *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x18);
    *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 4;
  }
  iVar24 = 0;
  iVar25 = param_1;
  do {
    if ((*(short *)(iVar25 + 2) == 0 && *(short *)(iVar25 + 6) == 0) &&
       ((*(uint *)(iVar25 + 0x30) & 1) == 0)) {
      *(uint *)(iVar25 + 0x30) = *(uint *)(iVar25 + 0x30) & 0xfffffffb;
    }
    bVar1 = iVar24 != 1;
    iVar25 = iVar25 + 0x40;
    iVar24 = iVar24 + 1;
  } while (bVar1);
  iVar24 = 0;
  puVar21 = (undefined4 *)(param_1 + 0x14);
  iVar25 = param_1;
  do {
    iVar24 = iVar24 + 1;
    if ((uVar27 & iVar24 * 0x100) == 0) {
      *(undefined2 *)((int)puVar21 + 0x16) = 0;
    }
    if ((*(short *)((int)puVar21 + -0x12) == 0 && *(short *)((int)puVar21 + -0xe) == 0) &&
       (uVar9 = puVar21[7], (uVar9 & 1) == 0)) {
      puVar21[4] = 0;
      *puVar21 = 0;
      puVar21[1] = 0;
      puVar21[2] = 0;
      puVar21[7] = uVar9 & 0xfffffff7;
      puVar21[3] = 0;
      puVar21[6] = 0x3f800000;
      if ((*(uint *)(iVar25 + 0x70) & 6) == 0) {
        *(undefined2 *)(puVar21 + 9) = 1;
        *(undefined2 *)((int)puVar21 + 0x22) = 1;
        *(undefined2 *)(puVar21 + 8) = 1;
        puVar21[7] = uVar9 & 0xffffffe5;
        uVar8 = (*(unsigned int *)0x001dbf94);
        *(undefined2 *)(puVar21 + 5) = 0;
        puVar21[-3] = uVar8;
        puVar21[-1] = uVar8;
        puVar21[-2] = uVar8;
      }
    }
    puVar21 = puVar21 + 0x10;
    iVar25 = iVar25 + -0x40;
  } while (iVar24 != 2);
  iVar24 = 0;
  iVar25 = param_1;
  do {
    if (((*(short *)(iVar25 + 2) != 0 || *(short *)(iVar25 + 6) != 0) ||
        ((*(uint *)(iVar25 + 0x30) & 1) != 0)) &&
       ((*(short *)(param_1 + 0x1a) != 0 || *(short *)(param_1 + 0x1c) != 0) ||
        *(short *)(param_1 + 0x1e) != 0)) {
      *(uint *)(iVar25 + 0x30) = *(uint *)(iVar25 + 0x30) | 2;
    }
    bVar1 = iVar24 != 1;
    iVar25 = iVar25 + 0x40;
    param_1 = param_1 + 0x3a;
    iVar24 = iVar24 + 1;
  } while (bVar1);
  return;
}

/* FUN_000c0fd0 @ 0xc0fd0 (1936 bytes) */
int FUN_000c0fd0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  float fVar4;
  ushort uVar5;
  short sVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  ushort uVar12;
  uint uVar13;
  ushort uVar14;
  uint uVar15;
  ushort uVar17;
  uint uVar16;
  int iVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  ushort *puVar22;
  int iVar23;
  undefined4 *puVar24;
  int iVar25;
  short *psVar26;
  ushort uVar29;
  int iVar27;
  undefined4 uVar28;
  int iVar30;
  int iVar31;
  
  bVar3 = false;
  uVar16 = 1;
  iVar30 = param_1;
  do {
    if ((*(short *)(iVar30 + 0x82) != -1) &&
       (*(short *)(iVar30 + 0x80) == *(short *)(iVar30 + 0x82))) {
      iVar27 = 0;
      uVar19 = (uVar16 & 0xff) << 8 | 1;
      do {
        iVar10 = param_1 + iVar27;
        iVar25 = 0;
        do {
          if (*(ushort *)(iVar10 + 8) == uVar19) {
            *(ushort *)(iVar10 + 8) = (ushort)uVar19 ^ 1;
            bVar3 = true;
          }
          bVar2 = iVar25 != 2;
          iVar10 = iVar10 + 4;
          iVar25 = iVar25 + 1;
        } while (bVar2);
        bVar2 = iVar27 != 0x40;
        iVar27 = iVar27 + 0x40;
      } while (bVar2);
    }
    sVar6 = *(short *)(iVar30 + 0x84);
    if (sVar6 != -1) {
      if (*(short *)(iVar30 + 0x80) == sVar6) {
        iVar27 = 0;
        uVar19 = (uVar16 & 0xff) << 8 | 2;
        do {
          iVar10 = param_1 + iVar27;
          iVar25 = 0;
          do {
            if (*(ushort *)(iVar10 + 8) == uVar19) {
              *(ushort *)(iVar10 + 8) = (ushort)uVar19 ^ 2;
              bVar3 = true;
            }
            bVar2 = iVar25 != 2;
            iVar10 = iVar10 + 4;
            iVar25 = iVar25 + 1;
          } while (bVar2);
          bVar2 = iVar27 != 0x40;
          iVar27 = iVar27 + 0x40;
        } while (bVar2);
      }
      else if (*(short *)(iVar30 + 0x82) == sVar6) {
        iVar27 = 0;
        uVar19 = (uVar16 & 0xff) << 8 | 2;
        do {
          iVar10 = param_1 + iVar27;
          iVar25 = 0;
          do {
            if (*(ushort *)(iVar10 + 8) == uVar19) {
              *(ushort *)(iVar10 + 8) = (ushort)uVar19 ^ 3;
              bVar3 = true;
            }
            bVar2 = iVar25 != 2;
            iVar10 = iVar10 + 4;
            iVar25 = iVar25 + 1;
          } while (bVar2);
          bVar2 = iVar27 != 0x40;
          iVar27 = iVar27 + 0x40;
        } while (bVar2);
      }
    }
    bVar2 = uVar16 != 2;
    iVar30 = iVar30 + 6;
    uVar16 = uVar16 + 1;
  } while (bVar2);
  if (bVar3) {
    ((int (*)())FUN_000c0880)(param_1);
    iVar30 = 0;
    iVar27 = param_1 + 0x10;
    do {
      psVar26 = (short *)(iVar27 + 4);
      iVar10 = 0;
      do {
        if (*psVar26 == 0 && psVar26[0x20] == 0) {
          psVar26[0x36] = -1;
        }
        bVar3 = iVar10 != 2;
        psVar26 = psVar26 + 1;
        iVar10 = iVar10 + 1;
      } while (bVar3);
      bVar3 = iVar30 != 1;
      iVar27 = iVar27 + 6;
      iVar30 = iVar30 + 1;
    } while (bVar3);
  }
  bVar3 = false;
  uVar16 = 0;
  iVar30 = 0;
  do {
    iVar27 = iVar30 + param_1;
    uVar20 = *(uint *)(iVar27 + 0x30);
    uVar19 = uVar20 & 0xffff00ff;
    *(uint *)(iVar27 + 0x30) = uVar19;
    if ((*(ushort *)(iVar27 + 2) != 0 || *(ushort *)(iVar27 + 6) != 0) || ((uVar20 & 1) != 0)) {
      uVar14 = *(ushort *)(iVar27 + 0x28);
      if ((uVar14 == 5) &&
         ((*(short *)(iVar27 + 8) == *(short *)(iVar27 + 0xc) &&
          ((*(ushort *)(iVar27 + 10) ^ *(ushort *)(iVar27 + 0xe)) == 0x1000)))) {
        uVar14 = 0;
        *(undefined2 *)(iVar27 + 0x28) = 0;
        bVar3 = true;
        *(undefined2 *)(iVar27 + 0x36) = 2;
        *(ushort *)(iVar27 + 10) = *(ushort *)(iVar27 + 10) & 0xefff | 0x2000;
        *(ushort *)(iVar27 + 0x34) = *(ushort *)(iVar27 + 0x34) & 0xffdf | 0x40;
        uVar28 = (*(unsigned int *)0x001dbf90);
        *(undefined2 *)(iVar27 + 0x38) = 1;
        *(undefined4 *)(iVar27 + 0xc) = uVar28;
        *(undefined4 *)(iVar27 + 0x10) = (*(unsigned int *)0x001dbf94);
      }
      if ((((uVar14 == 7) && (*(short *)(iVar27 + 8) == *(short *)(iVar27 + 0xc))) &&
          (*(int *)(iVar27 + 8) == *(int *)(iVar27 + 0x10))) &&
         ((*(ushort *)(iVar27 + 10) ^ *(ushort *)(iVar27 + 0xe)) == 0x1000)) {
        uVar14 = 0;
        *(undefined2 *)(iVar27 + 0x28) = 0;
        bVar3 = true;
        *(undefined2 *)(iVar27 + 0x36) = 2;
        *(ushort *)(iVar27 + 10) = *(ushort *)(iVar27 + 10) & 0xefff | 0x2000;
        *(ushort *)(iVar27 + 0x34) = *(ushort *)(iVar27 + 0x34) & 0xffdf | 0x40;
        uVar28 = (*(unsigned int *)0x001dbf90);
        *(undefined2 *)(iVar27 + 0x38) = 1;
        *(undefined4 *)(iVar27 + 0xc) = uVar28;
        *(undefined4 *)(iVar27 + 0x10) = (*(unsigned int *)0x001dbf94);
      }
      if (uVar14 == 0) {
        uVar17 = *(ushort *)(iVar27 + 0x36);
        if (((*(ushort *)(iVar27 + 0x34) | uVar17) & 1) == 0) {
          uVar12 = *(ushort *)(iVar27 + 0x38);
        }
        else {
          uVar17 = 2;
          bVar3 = true;
          *(undefined2 *)(iVar27 + 0x36) = 2;
          *(undefined2 *)(iVar27 + 0x34) = *(undefined2 *)(iVar27 + 0x38);
          *(undefined4 *)(iVar27 + 8) = *(undefined4 *)(iVar27 + 0x10);
          uVar28 = (*(unsigned int *)0x001dbf90);
          uVar12 = 1;
          *(undefined2 *)(iVar27 + 0x38) = 1;
          *(undefined4 *)(iVar27 + 0xc) = uVar28;
          *(undefined4 *)(iVar27 + 0x10) = (*(unsigned int *)0x001dbf94);
        }
        uVar29 = uVar17;
        if (((*(ushort *)(iVar27 + 8) & 0x300) == 0) && ((uVar17 & 2) == 0)) {
          uVar29 = *(ushort *)(iVar27 + 0x34);
          uVar28 = *(undefined4 *)(iVar27 + 0xc);
          *(ushort *)(iVar27 + 0x34) = uVar17;
          *(ushort *)(iVar27 + 0x36) = uVar29;
          *(undefined4 *)(iVar27 + 0xc) = *(undefined4 *)(iVar27 + 8);
          *(undefined4 *)(iVar27 + 8) = uVar28;
        }
        if ((uVar29 & 0x20) != 0) {
          *(ushort *)(iVar27 + 0x36) = uVar29 ^ 0x20;
          *(ushort *)(iVar27 + 0x34) = *(ushort *)(iVar27 + 0x34) ^ 0x20;
          *(ushort *)(iVar27 + 10) = *(ushort *)(iVar27 + 10) ^ 0x1000;
          *(ushort *)(iVar27 + 0xe) = *(ushort *)(iVar27 + 0xe) ^ 0x1000;
        }
        if ((uVar12 & 1) == 0) {
          if (((*(ushort *)(iVar27 + 0x36) & 2) == 0) || ((*(ushort *)(iVar27 + 8) & 0x300) != 0)) {
            iVar25 = *(int *)(iVar27 + 8);
            iVar10 = *(int *)(iVar27 + 0x10);
          }
          else {
            uVar17 = *(ushort *)(iVar27 + 0x34);
            iVar25 = *(int *)(iVar27 + 0x10);
            iVar10 = *(int *)(iVar27 + 8);
            *(ushort *)(iVar27 + 0x34) = uVar12;
            *(ushort *)(iVar27 + 0x38) = uVar17;
            *(int *)(iVar27 + 0x10) = iVar10;
            *(int *)(iVar27 + 8) = iVar25;
            if ((uVar17 & 1) != 0) goto LAB_000c14b0;
          }
          if (((iVar25 == iVar10) && ((*(ushort *)(iVar27 + 0x36) & 2) != 0)) &&
             (fVar4 = *(float *)(iVar27 + 0x2c), fVar4 < FLOAT_001aa100)) {
            bVar3 = true;
            *(undefined2 *)(iVar27 + 0x38) = 1;
            uVar28 = (*(unsigned int *)0x001dbf94);
            *(float *)(iVar27 + 0x2c) = fVar4 + fVar4;
            *(undefined4 *)(iVar27 + 0x10) = uVar28;
          }
        }
LAB_000c14b0:
        if (((uVar20 & 8) == 0) && (*(float *)(iVar27 + 0x2c) == FLOAT_001aa0e8)) {
          uVar17 = *(ushort *)(iVar27 + 0x34);
          uVar12 = *(ushort *)(iVar27 + 0x36);
          if (((uVar17 | uVar12) & 0x18) == 0) {
            uVar29 = *(ushort *)(iVar27 + 0x38);
            if (((uVar29 & 1) != 0) &&
               ((((uVar17 ^ uVar12) & 0x40) == 0 || ((*(ushort *)(iVar27 + 0xc) & 0x300) == 0)))) {
              *(uint *)(iVar27 + 0x30) = uVar19 | 0x100;
              if ((uVar17 & 0x40) != 0) {
                *(uint *)(iVar27 + 0x30) = uVar19 | 0x1100;
              }
              if ((uVar17 & 0x20) == 0) {
                uVar19 = *(uint *)(iVar27 + 0x30);
              }
              else {
                uVar19 = *(uint *)(iVar27 + 0x30) | 0x800;
                *(uint *)(iVar27 + 0x30) = uVar19;
              }
            }
          }
          else {
            uVar29 = *(ushort *)(iVar27 + 0x38);
          }
          if ((((uVar17 | uVar29) & 0x18) == 0) && ((uVar12 & 2) != 0)) {
            uVar19 = uVar19 | 0x200;
            *(uint *)(iVar27 + 0x30) = uVar19;
          }
          if ((uVar19 | 0xfffffcff) == 0xffffffff) {
            *(uint *)(iVar27 + 0x30) = uVar19 | 0x400;
          }
        }
      }
      if ((uVar14 < 9) && ((1 << ((int)(short)uVar14 & 0x3fU) & 0x1f1U) != 0)) {
        uVar14 = *(ushort *)(iVar27 + 6) | *(ushort *)(iVar27 + 2);
        uVar19 = (uint)uVar14;
        uVar20 = uVar19 & 0xffef;
        if (((uVar20 - 1 & 0xffff) < 2) || (uVar20 == 4)) {
          iVar10 = iVar27 + 8;
          iVar25 = 0;
          uVar13 = uVar16;
          do {
            uVar17 = *(ushort *)(iVar25 + iVar10 + 2);
            uVar16 = uVar13;
            if ((uVar17 | 0xfffffff9) == 0xffffffff) {
              uVar21 = uVar17 & 0x300;
              uVar16 = (uVar19 & 3) << 1 | (int)(uVar19 & 4) >> 2;
              if (uVar21 != 0x100) {
                if (uVar21 < 0x101) {
                  uVar16 = uVar20;
                  if ((uVar17 & 0x300) != 0) {
                    uVar16 = uVar13;
                  }
                }
                else if (uVar21 == 0x200) {
                  uVar16 = (uVar19 & 1) << 2 | uVar14 >> 1 & 3;
                }
                else {
                  uVar16 = uVar13;
                  if (uVar21 == 0x300) {
                    uVar16 = (uVar19 & 2) << 1 | (int)(uVar19 & 4) >> 1 | (uVar19 & 1) << 3;
                    if ((uVar14 & 1) == 0) {
                      *(ushort *)(iVar25 + iVar10) = *(ushort *)(iVar25 + iVar10) & 0xfdff;
                    }
                    else {
                      *(ushort *)(iVar25 + iVar10) = *(ushort *)(iVar25 + iVar10) & 0xfeff;
                    }
                  }
                }
              }
              bVar3 = true;
              *(ushort *)(iVar25 + iVar10 + 2) = uVar17 & ~((ushort)uVar16 ^ 0xf | 0x300);
            }
            bVar2 = iVar25 != 8;
            iVar25 = iVar25 + 4;
            uVar13 = uVar16;
          } while (bVar2);
        }
      }
      iVar25 = 0;
      iVar10 = iVar27;
      do {
        uVar14 = *(ushort *)(iVar10 + 10);
        uVar17 = uVar14 & 0x1f;
        if (uVar17 == 0x10) {
          *(ushort *)(iVar10 + 10) = uVar14 & 0xcfff;
          *(ushort *)(iVar27 + 0x34) = *(ushort *)(iVar27 + 0x34) & 0xff9f;
        }
        else if ((0xf < uVar17) && (uVar17 < 0x13)) {
          *(ushort *)(iVar10 + 10) = uVar14 & 0xdfff;
          *(ushort *)(iVar27 + 0x34) = *(ushort *)(iVar27 + 0x34) & 0xffbf;
        }
        bVar2 = iVar25 != 2;
        iVar10 = iVar10 + 4;
        iVar27 = iVar27 + 2;
        iVar25 = iVar25 + 1;
      } while (bVar2);
    }
    bVar2 = iVar30 == 0x40;
    iVar30 = iVar30 + 0x40;
    if (bVar2) {
      if (bVar3) {
        iVar10 = 0;
        iVar30 = 0;
        uVar16 = 0;
        iVar27 = 0;
        do {
          iVar25 = param_1 + iVar27 * 0x40;
          uVar14 = *(ushort *)(iVar25 + 0x28);
          *(undefined4 *)(iVar25 + 0x14) = 0;
          *(undefined4 *)(iVar25 + 0x20) = 0;
          *(undefined4 *)(iVar25 + 0x1c) = 0;
          *(undefined4 *)(iVar25 + 0x24) = 0;
          *(undefined4 *)(iVar25 + 0x18) = 0;
          uVar19 = *(uint *)(iVar25 + 0x30) & 0xffffff89;
          *(uint *)(iVar25 + 0x30) = uVar19;
          if (uVar14 == 2) {
            *(uint *)(iVar25 + 0x30) = uVar19 | 0x52;
            iVar10 = iVar25;
          }
          iVar31 = iVar27 + 1;
          if (uVar14 == 0xd) {
            iVar30 = iVar31;
          }
          bVar3 = (1 << ((int)(short)uVar14 & 0x3fU) & 0x1f1U) != 0;
          uVar19 = 0;
          iVar11 = iVar25;
          do {
            uVar12 = *(ushort *)(iVar25 + 8 + uVar19 * 4);
            uVar17 = *(ushort *)(iVar25 + 8 + uVar19 * 4 + 2);
            uVar20 = uVar12 & 3;
            uVar29 = uVar17 & 0x300;
            uVar13 = uVar17 & 0x1f;
            bVar2 = uVar29 == 0x300;
            if (bVar2) {
              *(uint *)(iVar25 + 0x30) = *(uint *)(iVar25 + 0x30) | 0x10;
            }
            if ((uVar14 == 3) && ((uVar13 | 0xfffffff9) == 0xffffffff)) {
              uVar21 = (1 < uVar19) + 3;
              if (uVar29 == 0x200) {
                uVar21 = uVar21 * 4 & 4 | uVar21 >> 1;
              }
              else if (bVar2) {
                uVar21 = uVar21 * 8 & 8 | uVar21 * 2 & 4 | uVar21 >> 1 & 2;
              }
              else if (uVar29 == 0x100) {
                uVar21 = uVar21 * 2 & 6 | uVar21 >> 2;
              }
              uVar13 = uVar21 & uVar13;
            }
            *(undefined2 *)(iVar11 + 0x34) = 0;
            puVar22 = (ushort *)(iVar11 + 0x34);
            if (((uVar13 & 0x10) == 0) &&
               (((uVar17 & 0x300) != 0 ||
                (((*(ushort *)(iVar25 + 6) | *(ushort *)(iVar25 + 2)) & 0xffef & ~uVar13) != 0)))) {
              *(undefined2 *)(iVar11 + 0x34) = 8;
            }
            bVar1 = uVar20 != 3;
            if (bVar1) {
              uVar21 = uVar20;
              if (uVar13 == 0x11) {
                *puVar22 = *puVar22 | 4;
              }
              else if (uVar13 == 0x12) {
                *puVar22 = *puVar22 | 2;
              }
              else if (uVar13 == 0x10) {
                *puVar22 = *puVar22 | 1;
              }
            }
            else {
              uVar16 = uVar12 & 0x300 | uVar16;
              iVar8 = ((uVar12 & 0x300) >> 8) - 1;
              uVar5 = *(ushort *)(iVar8 * 0x40 + param_1 + 0x2a);
              if (iVar27 != iVar8) {
                *(uint *)(iVar25 + 0x30) = *(uint *)(iVar25 + 0x30) | 0x20;
              }
              uVar20 = (uint)(uVar5 - 1 < 2);
              *puVar22 = *puVar22 | 0x10;
              uVar21 = 0;
            }
            if ((uVar17 & 0x1000) != 0) {
              *puVar22 = *puVar22 | 0x20;
            }
            if ((uVar17 & 0x2000) != 0) {
              *puVar22 = *puVar22 | 0x40;
            }
            if ((iVar27 == 1) && (uVar19 == 2)) {
              iVar10 = 0;
            }
            if ((uVar12 & 0x100) != 0) {
              uVar15 = uVar13 & 7;
              if ((uVar15 | 0xfffffff9) == 0xffffffff) {
                uVar17 = *(ushort *)(iVar25 + 6) | *(ushort *)(iVar25 + 2);
                uVar7 = (uint)uVar17;
                uVar9 = uVar7 & 0xffef;
                if (uVar29 == 0x200) {
                  uVar9 = (uVar7 & 1) << 2 | uVar17 >> 1 & 3;
                }
                else if (bVar2) {
                  uVar9 = (uVar7 & 2) << 1 | uVar17 >> 1 & 2;
                }
                else if (uVar29 == 0x100) {
                  uVar9 = (uVar7 & 3) << 1 | uVar17 >> 2 & 1;
                }
                if ((uVar14 < 9) && (bVar3)) {
                  uVar15 = uVar15 & uVar9;
                }
              }
              iVar8 = uVar21 * 2;
              iVar18 = iVar8 + iVar25;
              uVar17 = (ushort)uVar15;
              *(ushort *)(iVar18 + 0x14) = uVar17 | *(ushort *)(iVar18 + 0x14);
              if (iVar10 != 0) {
                *(ushort *)(iVar8 + iVar10 + 0x14) = uVar17 | *(ushort *)(iVar8 + iVar10 + 0x14);
              }
              if (!bVar1) {
                iVar23 = uVar20 * 2 + iVar25;
                *(ushort *)(iVar18 + 0x20) = uVar17 | *(ushort *)(iVar18 + 0x20);
                *(ushort *)(iVar23 + 0x14) = uVar17 | *(ushort *)(iVar23 + 0x14);
                *(ushort *)(iVar23 + 0x20) = uVar17 | *(ushort *)(iVar23 + 0x20);
                if (iVar10 != 0) {
                  iVar18 = uVar20 * 2 + iVar10;
                  uVar29 = *(ushort *)(iVar18 + 0x14);
                  *(ushort *)(iVar8 + iVar10 + 0x20) = uVar17 | *(ushort *)(iVar8 + iVar10 + 0x20);
                  *(ushort *)(iVar18 + 0x14) = uVar17 | uVar29;
                  *(ushort *)(iVar18 + 0x20) = uVar17 | *(ushort *)(iVar18 + 0x20);
                }
              }
            }
            if ((uVar12 & 0x200) != 0) {
              uVar17 = (ushort)uVar13 & 8;
              if ((((bVar2) && (uVar14 < 9)) && (bVar3)) &&
                 ((~(*(ushort *)(iVar25 + 6) | *(ushort *)(iVar25 + 2)) & 1) != 0)) {
                uVar17 = 0;
              }
              iVar8 = uVar21 * 2;
              iVar18 = iVar8 + iVar25;
              *(ushort *)(iVar18 + 0x1a) = uVar17 | *(ushort *)(iVar18 + 0x1a);
              if (iVar10 != 0) {
                *(ushort *)(iVar8 + iVar10 + 0x1a) = uVar17 | *(ushort *)(iVar8 + iVar10 + 0x1a);
              }
              if (!bVar1) {
                iVar23 = uVar20 * 2 + iVar25;
                *(ushort *)(iVar18 + 0x24) = uVar17 | *(ushort *)(iVar18 + 0x24);
                *(ushort *)(iVar23 + 0x1a) = uVar17 | *(ushort *)(iVar23 + 0x1a);
                *(ushort *)(iVar23 + 0x24) = uVar17 | *(ushort *)(iVar23 + 0x24);
                if (iVar10 != 0) {
                  iVar18 = uVar20 * 2 + iVar10;
                  uVar12 = *(ushort *)(iVar18 + 0x1a);
                  *(ushort *)(iVar8 + iVar10 + 0x24) = uVar17 | *(ushort *)(iVar8 + iVar10 + 0x24);
                  *(ushort *)(iVar18 + 0x1a) = uVar17 | uVar12;
                  *(ushort *)(iVar18 + 0x24) = uVar17 | *(ushort *)(iVar18 + 0x24);
                }
              }
            }
            bVar2 = uVar19 != 2;
            iVar11 = iVar11 + 2;
            uVar19 = uVar19 + 1;
          } while (bVar2);
          iVar27 = iVar31;
        } while (iVar31 != 2);
        if (iVar30 == 1) {
          *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x54);
          *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x60);
          *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_1 + 100);
          *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x5c);
          *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x58);
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 4;
        }
        else if (iVar30 == 2) {
          *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x14);
          *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0x20);
          *(undefined4 *)(param_1 + 100) = *(undefined4 *)(param_1 + 0x24);
          *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x1c);
          *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x18);
          *(uint *)(param_1 + 0x70) = *(uint *)(param_1 + 0x70) | 4;
        }
        iVar27 = 0;
        iVar30 = param_1;
        do {
          if ((*(short *)(iVar30 + 2) == 0 && *(short *)(iVar30 + 6) == 0) &&
             ((*(uint *)(iVar30 + 0x30) & 1) == 0)) {
            *(uint *)(iVar30 + 0x30) = *(uint *)(iVar30 + 0x30) & 0xfffffffb;
          }
          bVar3 = iVar27 != 1;
          iVar30 = iVar30 + 0x40;
          iVar27 = iVar27 + 1;
        } while (bVar3);
        iVar27 = 0;
        puVar24 = (undefined4 *)(param_1 + 0x14);
        iVar30 = param_1;
        do {
          iVar27 = iVar27 + 1;
          if ((uVar16 & iVar27 * 0x100) == 0) {
            *(undefined2 *)((int)puVar24 + 0x16) = 0;
          }
          if ((*(short *)((int)puVar24 + -0x12) == 0 && *(short *)((int)puVar24 + -0xe) == 0) &&
             (uVar19 = puVar24[7], (uVar19 & 1) == 0)) {
            puVar24[4] = 0;
            *puVar24 = 0;
            puVar24[1] = 0;
            puVar24[2] = 0;
            puVar24[7] = uVar19 & 0xfffffff7;
            puVar24[3] = 0;
            puVar24[6] = 0x3f800000;
            if ((*(uint *)(iVar30 + 0x70) & 6) == 0) {
              *(undefined2 *)(puVar24 + 9) = 1;
              *(undefined2 *)((int)puVar24 + 0x22) = 1;
              *(undefined2 *)(puVar24 + 8) = 1;
              puVar24[7] = uVar19 & 0xffffffe5;
              uVar28 = (*(unsigned int *)0x001dbf94);
              *(undefined2 *)(puVar24 + 5) = 0;
              puVar24[-3] = uVar28;
              puVar24[-1] = uVar28;
              puVar24[-2] = uVar28;
            }
          }
          puVar24 = puVar24 + 0x10;
          iVar30 = iVar30 + -0x40;
        } while (iVar27 != 2);
        iVar27 = 0;
        iVar30 = param_1;
        do {
          if (((*(short *)(iVar30 + 2) != 0 || *(short *)(iVar30 + 6) != 0) ||
              ((*(uint *)(iVar30 + 0x30) & 1) != 0)) &&
             ((*(short *)(param_1 + 0x1a) != 0 || *(short *)(param_1 + 0x1c) != 0) ||
              *(short *)(param_1 + 0x1e) != 0)) {
            *(uint *)(iVar30 + 0x30) = *(uint *)(iVar30 + 0x30) | 2;
          }
          bVar3 = iVar27 != 1;
          iVar30 = iVar30 + 0x40;
          param_1 = param_1 + 0x3a;
          iVar27 = iVar27 + 1;
        } while (bVar3);
        return;
      }
      return;
    }
  } while( true );
}

/* FUN_000c1780 @ 0xc1780 (1416 bytes) */
int FUN_000c1780(param_1, param_2, param_3)
  ushort *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  float fVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  ushort uVar10;
  uint uVar11;
  ushort uVar13;
  uint uVar12;
  ushort uVar15;
  uint uVar14;
  ushort *puVar16;
  ushort *puVar17;
  int iVar18;
  ushort *puVar19;
  ushort uVar21;
  undefined4 uVar20;
  int iVar22;
  int iVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  
  _memset(param_1,0,0x80);
  iVar22 = *(int *)(param_1 + 0x46);
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  iVar6 = *(int *)(param_1 + 0x48);
  if (iVar22 != 1) {
    if (iVar22 == 0) {
      iVar22 = iVar6 * 4 + param_2;
      param_1[2] = (ushort)((uint)*(undefined4 *)(iVar22 + 4) >> 0x12) & 0x7f;
      param_1[0x40] = *(byte *)(iVar22 + 6) >> 4 | 0xc000;
      if ((*(ushort *)(iVar22 + 4) & 3) != 0) {
        param_1[10] = 0xf;
        param_1[3] = 0xf;
        uVar13 = *(ushort *)(iVar22 + 4) & 3;
        if ((uVar13 == 2) || (uVar13 == 3)) {
          param_1[0x1d] = uVar13;
        }
      }
      iVar6 = iVar6 * 4 + param_2;
      *(undefined4 *)(param_1 + 0x16) =
           *(undefined4 *)((*(uint *)(iVar6 + 4) >> 0x19 & 0x7c) + 0x1dc198);
      param_1[0x22] = (ushort)(*(uint *)(iVar6 + 4) >> 5) & 0x7f;
      param_1[0x43] = (ushort)*(undefined4 *)(iVar6 + 4) & 0xf | 0xa000;
      uVar8 = *(uint *)(iVar6 + 4);
      if ((uVar8 & 0x10) != 0) {
        param_1[0x2d] = 0xf;
        param_1[0x23] = 0xf;
        uVar8 = *(uint *)(iVar6 + 4);
      }
      *(undefined4 *)(param_1 + 0x36) = *(undefined4 *)((uVar8 >> 0x17 & 4) + 0x1dc198);
      return;
    }
    if (iVar22 != 2) {
      return;
    }
    iVar22 = 0;
    iVar6 = iVar6 * 4 + param_3;
    uVar12 = *(uint *)(iVar6 + 0x198);
    uVar14 = *(uint *)(iVar6 + 0x98);
    uVar8 = *(uint *)(iVar6 + 0x398);
    uVar11 = *(uint *)(iVar6 + 0x298);
    param_1[0x40] = (ushort)uVar14 & 0x3f;
    param_1[0x43] = (ushort)uVar12 & 0x3f;
    param_1[0x41] = (ushort)(uVar14 >> 6) & 0x3f;
    param_1[0x42] = (ushort)(uVar14 >> 0xc) & 0x3f;
    param_1[0x44] = (ushort)(uVar12 >> 6) & 0x3f;
    param_1[0x45] = (ushort)(uVar12 >> 0xc) & 0x3f;
    iVar6 = 0x80;
    do {
      puVar19 = (ushort *)((int)param_1 + iVar6);
      iVar23 = 0;
      do {
        if (0x1f < *puVar19) {
          *puVar19 = *puVar19 - 0x20 | 0x8000;
        }
        bVar3 = iVar23 != 2;
        puVar19 = puVar19 + 1;
        iVar23 = iVar23 + 1;
      } while (bVar3);
      bVar3 = iVar22 != 1;
      iVar6 = iVar6 + 6;
      iVar22 = iVar22 + 1;
    } while (bVar3);
    iVar6 = 0;
    puVar19 = param_1;
    puVar17 = param_1;
    do {
      puVar17[0x3a] = 1;
      puVar17[0x1a] = 1;
      uVar20 = (*(unsigned int *)0x001dbf94);
      bVar3 = iVar6 != 2;
      puVar17 = puVar17 + 1;
      iVar6 = iVar6 + 1;
      *(undefined4 *)(puVar19 + 4) = (*(unsigned int *)0x001dbf94);
      *(undefined4 *)(puVar19 + 0x24) = uVar20;
      puVar19 = puVar19 + 2;
    } while (bVar3);
    uVar13 = (ushort)(uVar14 >> 0x10);
    param_1[3] = uVar13 >> 7 & 7;
    param_1[2] = uVar13 >> 2 & 0x1f;
    uVar14 = uVar11 >> 0x15 & 0x3c;
    *param_1 = uVar13 >> 0xd & 3;
    param_1[1] = uVar13 >> 10 & 7;
    param_1[0x14] = *(ushort *)(uVar14 + 0x1dc158);
    uVar14 = (uint)*(ushort *)(uVar14 + 0x1dc15a);
    if (uVar14 != 0) {
      uVar24 = uVar11 >> 5 & 3;
LAB_000c1ab0:
      iVar6 = 0;
      uVar26 = uVar11 & 0x1f;
      uVar7 = uVar24;
      puVar19 = param_1 + 4;
      uVar25 = uVar14;
      if (uVar14 == 0) {
        uVar25 = 1;
      }
      do {
        iVar6 = iVar6 + 1;
        *(undefined4 *)puVar19 = *(undefined4 *)(uVar26 * 4 + 0x1dc0d8);
        puVar19[1] = (ushort)(uVar7 << 0xc) | puVar19[1];
        uVar25 = uVar25 - 1;
        if (uVar25 == 0) break;
        uVar26 = uVar11 >> 7 & 0x1f;
        uVar7 = uVar11 >> 0xc & 3;
        if (iVar6 != 1) {
          if (iVar6 == 0) goto LAB_000c1ab0;
          uVar26 = uVar11 >> 0xe & 0x1f;
          uVar7 = uVar11 >> 0x13 & 3;
          if (iVar6 != 2) {
            uVar26 = 0;
            uVar7 = 0;
          }
        }
        puVar19 = puVar19 + 2;
      } while( true );
    }
    param_1[0x15] = (ushort)(uVar11 >> 0x15) & 3;
    if ((uVar11 & 0x40000000) != 0) {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 8;
    }
    uVar13 = (ushort)(uVar12 >> 0x10);
    uVar20 = *(undefined4 *)((uVar11 >> 0x19 & 0x1c) + 0x1dc198);
    param_1[0x22] = uVar13 >> 2 & 0x1f;
    *(undefined4 *)(param_1 + 0x16) = uVar20;
    if ((uVar12 & 0x800000) != 0) {
      param_1[0x23] = 8;
    }
    param_1[0x20] = uVar13 >> 9 & 3;
    if ((uVar12 & 0x1000000) != 0) {
      param_1[0x21] = 8;
    }
    if ((uVar12 & 0x8000000) != 0) {
      param_1[0x21] = param_1[0x21] | 0x10;
    }
    uVar12 = uVar8 >> 0x15 & 0x3c;
    param_1[0x34] = *(ushort *)(uVar12 + 0x1dc098);
    uVar12 = (uint)*(ushort *)(uVar12 + 0x1dc09a);
    if ((uVar11 & 0x7800000) == 0x1000000) {
      if (uVar12 < 2) {
        uVar12 = 2;
      }
    }
    else if (uVar12 == 0) {
LAB_000c1cec:
      param_1[0x35] = (ushort)(uVar8 >> 0x15) & 3;
      if ((uVar8 & 0x40000000) != 0) {
        *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 8;
      }
      *(undefined4 *)(param_1 + 0x36) = *(undefined4 *)((uVar8 >> 0x19 & 0x1c) + 0x1dc198);
      ((int (*)())FUN_000c0880)(param_1);
      bVar3 = false;
      uVar8 = 1;
      puVar19 = param_1;
      do {
        if ((puVar19[0x41] != 0xffff) && (puVar19[0x40] == puVar19[0x41])) {
          iVar6 = 0;
          uVar11 = (uVar8 & 0xff) << 8 | 1;
          do {
            iVar22 = (int)param_1 + iVar6;
            iVar23 = 0;
            do {
              if (*(ushort *)(iVar22 + 8) == uVar11) {
                *(ushort *)(iVar22 + 8) = (ushort)uVar11 ^ 1;
                bVar3 = true;
              }
              bVar2 = iVar23 != 2;
              iVar22 = iVar22 + 4;
              iVar23 = iVar23 + 1;
            } while (bVar2);
            bVar2 = iVar6 != 0x40;
            iVar6 = iVar6 + 0x40;
          } while (bVar2);
        }
        uVar13 = puVar19[0x42];
        if (uVar13 != 0xffff) {
          if (puVar19[0x40] == uVar13) {
            iVar6 = 0;
            uVar11 = (uVar8 & 0xff) << 8 | 2;
            do {
              iVar22 = (int)param_1 + iVar6;
              iVar23 = 0;
              do {
                if (*(ushort *)(iVar22 + 8) == uVar11) {
                  *(ushort *)(iVar22 + 8) = (ushort)uVar11 ^ 2;
                  bVar3 = true;
                }
                bVar2 = iVar23 != 2;
                iVar22 = iVar22 + 4;
                iVar23 = iVar23 + 1;
              } while (bVar2);
              bVar2 = iVar6 != 0x40;
              iVar6 = iVar6 + 0x40;
            } while (bVar2);
          }
          else if (puVar19[0x41] == uVar13) {
            iVar6 = 0;
            uVar11 = (uVar8 & 0xff) << 8 | 2;
            do {
              iVar22 = (int)param_1 + iVar6;
              iVar23 = 0;
              do {
                if (*(ushort *)(iVar22 + 8) == uVar11) {
                  *(ushort *)(iVar22 + 8) = (ushort)uVar11 ^ 3;
                  bVar3 = true;
                }
                bVar2 = iVar23 != 2;
                iVar22 = iVar22 + 4;
                iVar23 = iVar23 + 1;
              } while (bVar2);
              bVar2 = iVar6 != 0x40;
              iVar6 = iVar6 + 0x40;
            } while (bVar2);
          }
        }
        bVar2 = uVar8 != 2;
        puVar19 = puVar19 + 3;
        uVar8 = uVar8 + 1;
      } while (bVar2);
      if (bVar3) {
        ((int (*)())FUN_000c0880)(param_1);
        iVar6 = 0;
        puVar19 = param_1 + 8;
        do {
          puVar17 = puVar19 + 2;
          iVar22 = 0;
          do {
            if (*puVar17 == 0 && puVar17[0x20] == 0) {
              puVar17[0x36] = 0xffff;
            }
            bVar3 = iVar22 != 2;
            puVar17 = puVar17 + 1;
            iVar22 = iVar22 + 1;
          } while (bVar3);
          bVar3 = iVar6 != 1;
          puVar19 = puVar19 + 3;
          iVar6 = iVar6 + 1;
        } while (bVar3);
      }
      bVar3 = false;
      uVar8 = 0;
      iVar6 = 0;
      do {
        iVar22 = iVar6 + (int)param_1;
        uVar12 = *(uint *)(iVar22 + 0x30);
        uVar11 = uVar12 & 0xffff00ff;
        *(uint *)(iVar22 + 0x30) = uVar11;
        if ((*(ushort *)(iVar22 + 2) != 0 || *(ushort *)(iVar22 + 6) != 0) || ((uVar12 & 1) != 0)) {
          uVar13 = *(ushort *)(iVar22 + 0x28);
          if ((uVar13 == 5) &&
             ((*(short *)(iVar22 + 8) == *(short *)(iVar22 + 0xc) &&
              ((*(ushort *)(iVar22 + 10) ^ *(ushort *)(iVar22 + 0xe)) == 0x1000)))) {
            uVar13 = 0;
            *(undefined2 *)(iVar22 + 0x28) = 0;
            bVar3 = true;
            *(undefined2 *)(iVar22 + 0x36) = 2;
            *(ushort *)(iVar22 + 10) = *(ushort *)(iVar22 + 10) & 0xefff | 0x2000;
            *(ushort *)(iVar22 + 0x34) = *(ushort *)(iVar22 + 0x34) & 0xffdf | 0x40;
            uVar20 = (*(unsigned int *)0x001dbf90);
            *(undefined2 *)(iVar22 + 0x38) = 1;
            *(undefined4 *)(iVar22 + 0xc) = uVar20;
            *(undefined4 *)(iVar22 + 0x10) = (*(unsigned int *)0x001dbf94);
          }
          if ((((uVar13 == 7) && (*(short *)(iVar22 + 8) == *(short *)(iVar22 + 0xc))) &&
              (*(int *)(iVar22 + 8) == *(int *)(iVar22 + 0x10))) &&
             ((*(ushort *)(iVar22 + 10) ^ *(ushort *)(iVar22 + 0xe)) == 0x1000)) {
            uVar13 = 0;
            *(undefined2 *)(iVar22 + 0x28) = 0;
            bVar3 = true;
            *(undefined2 *)(iVar22 + 0x36) = 2;
            *(ushort *)(iVar22 + 10) = *(ushort *)(iVar22 + 10) & 0xefff | 0x2000;
            *(ushort *)(iVar22 + 0x34) = *(ushort *)(iVar22 + 0x34) & 0xffdf | 0x40;
            uVar20 = (*(unsigned int *)0x001dbf90);
            *(undefined2 *)(iVar22 + 0x38) = 1;
            *(undefined4 *)(iVar22 + 0xc) = uVar20;
            *(undefined4 *)(iVar22 + 0x10) = (*(unsigned int *)0x001dbf94);
          }
          if (uVar13 == 0) {
            uVar15 = *(ushort *)(iVar22 + 0x36);
            if (((*(ushort *)(iVar22 + 0x34) | uVar15) & 1) == 0) {
              uVar10 = *(ushort *)(iVar22 + 0x38);
            }
            else {
              uVar15 = 2;
              bVar3 = true;
              *(undefined2 *)(iVar22 + 0x36) = 2;
              *(undefined2 *)(iVar22 + 0x34) = *(undefined2 *)(iVar22 + 0x38);
              *(undefined4 *)(iVar22 + 8) = *(undefined4 *)(iVar22 + 0x10);
              uVar20 = (*(unsigned int *)0x001dbf90);
              uVar10 = 1;
              *(undefined2 *)(iVar22 + 0x38) = 1;
              *(undefined4 *)(iVar22 + 0xc) = uVar20;
              *(undefined4 *)(iVar22 + 0x10) = (*(unsigned int *)0x001dbf94);
            }
            uVar21 = uVar15;
            if (((*(ushort *)(iVar22 + 8) & 0x300) == 0) && ((uVar15 & 2) == 0)) {
              uVar21 = *(ushort *)(iVar22 + 0x34);
              uVar20 = *(undefined4 *)(iVar22 + 0xc);
              *(ushort *)(iVar22 + 0x34) = uVar15;
              *(ushort *)(iVar22 + 0x36) = uVar21;
              *(undefined4 *)(iVar22 + 0xc) = *(undefined4 *)(iVar22 + 8);
              *(undefined4 *)(iVar22 + 8) = uVar20;
            }
            if ((uVar21 & 0x20) != 0) {
              *(ushort *)(iVar22 + 0x36) = uVar21 ^ 0x20;
              *(ushort *)(iVar22 + 0x34) = *(ushort *)(iVar22 + 0x34) ^ 0x20;
              *(ushort *)(iVar22 + 10) = *(ushort *)(iVar22 + 10) ^ 0x1000;
              *(ushort *)(iVar22 + 0xe) = *(ushort *)(iVar22 + 0xe) ^ 0x1000;
            }
            if ((uVar10 & 1) == 0) {
              if (((*(ushort *)(iVar22 + 0x36) & 2) == 0) ||
                 ((*(ushort *)(iVar22 + 8) & 0x300) != 0)) {
                iVar18 = *(int *)(iVar22 + 8);
                iVar23 = *(int *)(iVar22 + 0x10);
              }
              else {
                uVar15 = *(ushort *)(iVar22 + 0x34);
                iVar18 = *(int *)(iVar22 + 0x10);
                iVar23 = *(int *)(iVar22 + 8);
                *(ushort *)(iVar22 + 0x34) = uVar10;
                *(ushort *)(iVar22 + 0x38) = uVar15;
                *(int *)(iVar22 + 0x10) = iVar23;
                *(int *)(iVar22 + 8) = iVar18;
                if ((uVar15 & 1) != 0) goto LAB_000c14b0;
              }
              if (((iVar18 == iVar23) && ((*(ushort *)(iVar22 + 0x36) & 2) != 0)) &&
                 (fVar4 = *(float *)(iVar22 + 0x2c), fVar4 < FLOAT_001aa100)) {
                bVar3 = true;
                *(undefined2 *)(iVar22 + 0x38) = 1;
                uVar20 = (*(unsigned int *)0x001dbf94);
                *(float *)(iVar22 + 0x2c) = fVar4 + fVar4;
                *(undefined4 *)(iVar22 + 0x10) = uVar20;
              }
            }
LAB_000c14b0:
            if (((uVar12 & 8) == 0) && (*(float *)(iVar22 + 0x2c) == FLOAT_001aa0e8)) {
              uVar15 = *(ushort *)(iVar22 + 0x34);
              uVar10 = *(ushort *)(iVar22 + 0x36);
              if (((uVar15 | uVar10) & 0x18) == 0) {
                uVar21 = *(ushort *)(iVar22 + 0x38);
                if (((uVar21 & 1) != 0) &&
                   ((((uVar15 ^ uVar10) & 0x40) == 0 || ((*(ushort *)(iVar22 + 0xc) & 0x300) == 0)))
                   ) {
                  *(uint *)(iVar22 + 0x30) = uVar11 | 0x100;
                  if ((uVar15 & 0x40) != 0) {
                    *(uint *)(iVar22 + 0x30) = uVar11 | 0x1100;
                  }
                  if ((uVar15 & 0x20) == 0) {
                    uVar11 = *(uint *)(iVar22 + 0x30);
                  }
                  else {
                    uVar11 = *(uint *)(iVar22 + 0x30) | 0x800;
                    *(uint *)(iVar22 + 0x30) = uVar11;
                  }
                }
              }
              else {
                uVar21 = *(ushort *)(iVar22 + 0x38);
              }
              if ((((uVar15 | uVar21) & 0x18) == 0) && ((uVar10 & 2) != 0)) {
                uVar11 = uVar11 | 0x200;
                *(uint *)(iVar22 + 0x30) = uVar11;
              }
              if ((uVar11 | 0xfffffcff) == 0xffffffff) {
                *(uint *)(iVar22 + 0x30) = uVar11 | 0x400;
              }
            }
          }
          if ((uVar13 < 9) && ((1 << ((int)(short)uVar13 & 0x3fU) & 0x1f1U) != 0)) {
            uVar13 = *(ushort *)(iVar22 + 6) | *(ushort *)(iVar22 + 2);
            uVar11 = (uint)uVar13;
            uVar12 = uVar11 & 0xffef;
            if (((uVar12 - 1 & 0xffff) < 2) || (uVar12 == 4)) {
              iVar23 = iVar22 + 8;
              iVar18 = 0;
              uVar14 = uVar8;
              do {
                uVar15 = *(ushort *)(iVar18 + iVar23 + 2);
                uVar8 = uVar14;
                if ((uVar15 | 0xfffffff9) == 0xffffffff) {
                  uVar24 = uVar15 & 0x300;
                  uVar8 = (uVar11 & 3) << 1 | (int)(uVar11 & 4) >> 2;
                  if (uVar24 != 0x100) {
                    if (uVar24 < 0x101) {
                      uVar8 = uVar12;
                      if ((uVar15 & 0x300) != 0) {
                        uVar8 = uVar14;
                      }
                    }
                    else if (uVar24 == 0x200) {
                      uVar8 = (uVar11 & 1) << 2 | uVar13 >> 1 & 3;
                    }
                    else {
                      uVar8 = uVar14;
                      if (uVar24 == 0x300) {
                        uVar8 = (uVar11 & 2) << 1 | (int)(uVar11 & 4) >> 1 | (uVar11 & 1) << 3;
                        if ((uVar13 & 1) == 0) {
                          *(ushort *)(iVar18 + iVar23) = *(ushort *)(iVar18 + iVar23) & 0xfdff;
                        }
                        else {
                          *(ushort *)(iVar18 + iVar23) = *(ushort *)(iVar18 + iVar23) & 0xfeff;
                        }
                      }
                    }
                  }
                  bVar3 = true;
                  *(ushort *)(iVar18 + iVar23 + 2) = uVar15 & ~((ushort)uVar8 ^ 0xf | 0x300);
                }
                bVar2 = iVar18 != 8;
                iVar18 = iVar18 + 4;
                uVar14 = uVar8;
              } while (bVar2);
            }
          }
          iVar18 = 0;
          iVar23 = iVar22;
          do {
            uVar13 = *(ushort *)(iVar23 + 10);
            uVar15 = uVar13 & 0x1f;
            if (uVar15 == 0x10) {
              *(ushort *)(iVar23 + 10) = uVar13 & 0xcfff;
              *(ushort *)(iVar22 + 0x34) = *(ushort *)(iVar22 + 0x34) & 0xff9f;
            }
            else if ((0xf < uVar15) && (uVar15 < 0x13)) {
              *(ushort *)(iVar23 + 10) = uVar13 & 0xdfff;
              *(ushort *)(iVar22 + 0x34) = *(ushort *)(iVar22 + 0x34) & 0xffbf;
            }
            bVar2 = iVar18 != 2;
            iVar23 = iVar23 + 4;
            iVar22 = iVar22 + 2;
            iVar18 = iVar18 + 1;
          } while (bVar2);
        }
        bVar2 = iVar6 == 0x40;
        iVar6 = iVar6 + 0x40;
        if (bVar2) {
          if (!bVar3) {
            return;
          }
          puVar19 = (ushort *)0x0;
          iVar6 = 0;
          uVar8 = 0;
          iVar22 = 0;
          do {
            puVar17 = param_1 + iVar22 * 0x20;
            uVar13 = puVar17[0x14];
            uVar11 = *(uint *)(puVar17 + 0x18);
            puVar17[10] = 0;
            puVar17[0xb] = 0;
            puVar17[0x10] = 0;
            puVar17[0x11] = 0;
            puVar17[0xe] = 0;
            puVar17[0xf] = 0;
            puVar17[0x12] = 0;
            puVar17[0x13] = 0;
            puVar17[0xc] = 0;
            puVar17[0xd] = 0;
            *(uint *)(puVar17 + 0x18) = uVar11 & 0xffffff89;
            if (uVar13 == 2) {
              *(uint *)(puVar17 + 0x18) = uVar11 & 0xffffff89 | 0x52;
              puVar19 = puVar17;
            }
            iVar23 = iVar22 + 1;
            if (uVar13 == 0xd) {
              iVar6 = iVar23;
            }
            bVar3 = (1 << ((int)(short)uVar13 & 0x3fU) & 0x1f1U) != 0;
            uVar11 = 0;
            puVar9 = puVar17;
            do {
              uVar10 = puVar17[uVar11 * 2 + 4];
              uVar15 = puVar17[uVar11 * 2 + 5];
              uVar12 = uVar10 & 3;
              uVar21 = uVar15 & 0x300;
              uVar14 = uVar15 & 0x1f;
              bVar2 = uVar21 == 0x300;
              if (bVar2) {
                *(uint *)(puVar17 + 0x18) = *(uint *)(puVar17 + 0x18) | 0x10;
              }
              if ((uVar13 == 3) && ((uVar14 | 0xfffffff9) == 0xffffffff)) {
                uVar24 = (1 < uVar11) + 3;
                if (uVar21 == 0x200) {
                  uVar24 = uVar24 * 4 & 4 | uVar24 >> 1;
                }
                else if (bVar2) {
                  uVar24 = uVar24 * 8 & 8 | uVar24 * 2 & 4 | uVar24 >> 1 & 2;
                }
                else if (uVar21 == 0x100) {
                  uVar24 = uVar24 * 2 & 6 | uVar24 >> 2;
                }
                uVar14 = uVar24 & uVar14;
              }
              puVar9[0x1a] = 0;
              puVar16 = puVar9 + 0x1a;
              if (((uVar14 & 0x10) == 0) &&
                 (((uVar15 & 0x300) != 0 || (((puVar17[3] | puVar17[1]) & 0xffef & ~uVar14) != 0))))
              {
                puVar9[0x1a] = 8;
              }
              bVar1 = uVar12 != 3;
              if (bVar1) {
                uVar24 = uVar12;
                if (uVar14 == 0x11) {
                  *puVar16 = *puVar16 | 4;
                }
                else if (uVar14 == 0x12) {
                  *puVar16 = *puVar16 | 2;
                }
                else if (uVar14 == 0x10) {
                  *puVar16 = *puVar16 | 1;
                }
              }
              else {
                uVar8 = uVar10 & 0x300 | uVar8;
                iVar18 = ((uVar10 & 0x300) >> 8) - 1;
                uVar5 = param_1[iVar18 * 0x20 + 0x15];
                if (iVar22 != iVar18) {
                  *(uint *)(puVar17 + 0x18) = *(uint *)(puVar17 + 0x18) | 0x20;
                }
                uVar12 = (uint)(uVar5 - 1 < 2);
                *puVar16 = *puVar16 | 0x10;
                uVar24 = 0;
              }
              if ((uVar15 & 0x1000) != 0) {
                *puVar16 = *puVar16 | 0x20;
              }
              if ((uVar15 & 0x2000) != 0) {
                *puVar16 = *puVar16 | 0x40;
              }
              if ((iVar22 == 1) && (uVar11 == 2)) {
                puVar19 = (ushort *)0x0;
              }
              if ((uVar10 & 0x100) != 0) {
                uVar26 = uVar14 & 7;
                if ((uVar26 | 0xfffffff9) == 0xffffffff) {
                  uVar15 = puVar17[3] | puVar17[1];
                  uVar7 = (uint)uVar15;
                  uVar25 = uVar7 & 0xffef;
                  if (uVar21 == 0x200) {
                    uVar25 = (uVar7 & 1) << 2 | uVar15 >> 1 & 3;
                  }
                  else if (bVar2) {
                    uVar25 = (uVar7 & 2) << 1 | uVar15 >> 1 & 2;
                  }
                  else if (uVar21 == 0x100) {
                    uVar25 = (uVar7 & 3) << 1 | uVar15 >> 2 & 1;
                  }
                  if ((uVar13 < 9) && (bVar3)) {
                    uVar26 = uVar26 & uVar25;
                  }
                }
                uVar15 = (ushort)uVar26;
                puVar17[uVar24 + 10] = uVar15 | puVar17[uVar24 + 10];
                if (puVar19 != (ushort *)0x0) {
                  puVar19[uVar24 + 10] = uVar15 | puVar19[uVar24 + 10];
                }
                if (!bVar1) {
                  puVar17[uVar24 + 0x10] = uVar15 | puVar17[uVar24 + 0x10];
                  puVar17[uVar12 + 10] = uVar15 | puVar17[uVar12 + 10];
                  puVar17[uVar12 + 0x10] = uVar15 | puVar17[uVar12 + 0x10];
                  if (puVar19 != (ushort *)0x0) {
                    uVar21 = puVar19[uVar12 + 10];
                    puVar19[uVar24 + 0x10] = uVar15 | puVar19[uVar24 + 0x10];
                    puVar19[uVar12 + 10] = uVar15 | uVar21;
                    puVar19[uVar12 + 0x10] = uVar15 | puVar19[uVar12 + 0x10];
                  }
                }
              }
              if ((uVar10 & 0x200) != 0) {
                uVar15 = (ushort)uVar14 & 8;
                if ((((bVar2) && (uVar13 < 9)) && (bVar3)) &&
                   ((~(puVar17[3] | puVar17[1]) & 1) != 0)) {
                  uVar15 = 0;
                }
                puVar17[uVar24 + 0xd] = uVar15 | puVar17[uVar24 + 0xd];
                if (puVar19 != (ushort *)0x0) {
                  puVar19[uVar24 + 0xd] = uVar15 | puVar19[uVar24 + 0xd];
                }
                if (!bVar1) {
                  puVar17[uVar24 + 0x12] = uVar15 | puVar17[uVar24 + 0x12];
                  puVar17[uVar12 + 0xd] = uVar15 | puVar17[uVar12 + 0xd];
                  puVar17[uVar12 + 0x12] = uVar15 | puVar17[uVar12 + 0x12];
                  if (puVar19 != (ushort *)0x0) {
                    uVar10 = puVar19[uVar12 + 0xd];
                    puVar19[uVar24 + 0x12] = uVar15 | puVar19[uVar24 + 0x12];
                    puVar19[uVar12 + 0xd] = uVar15 | uVar10;
                    puVar19[uVar12 + 0x12] = uVar15 | puVar19[uVar12 + 0x12];
                  }
                }
              }
              bVar2 = uVar11 != 2;
              puVar9 = puVar9 + 1;
              uVar11 = uVar11 + 1;
            } while (bVar2);
            iVar22 = iVar23;
          } while (iVar23 != 2);
          if (iVar6 == 1) {
            *(undefined4 *)(param_1 + 10) = *(undefined4 *)(param_1 + 0x2a);
            *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x30);
            *(undefined4 *)(param_1 + 0x12) = *(undefined4 *)(param_1 + 0x32);
            *(undefined4 *)(param_1 + 0xe) = *(undefined4 *)(param_1 + 0x2e);
            *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x2c);
            *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 4;
          }
          else if (iVar6 == 2) {
            *(undefined4 *)(param_1 + 0x2a) = *(undefined4 *)(param_1 + 10);
            *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x10);
            *(undefined4 *)(param_1 + 0x32) = *(undefined4 *)(param_1 + 0x12);
            *(undefined4 *)(param_1 + 0x2e) = *(undefined4 *)(param_1 + 0xe);
            *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(param_1 + 0xc);
            *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 4;
          }
          iVar6 = 0;
          puVar19 = param_1;
          do {
            if ((puVar19[1] == 0 && puVar19[3] == 0) && ((*(uint *)(puVar19 + 0x18) & 1) == 0)) {
              *(uint *)(puVar19 + 0x18) = *(uint *)(puVar19 + 0x18) & 0xfffffffb;
            }
            bVar3 = iVar6 != 1;
            puVar19 = puVar19 + 0x20;
            iVar6 = iVar6 + 1;
          } while (bVar3);
          iVar6 = 0;
          puVar17 = param_1 + 10;
          puVar19 = param_1;
          do {
            iVar6 = iVar6 + 1;
            if ((uVar8 & iVar6 * 0x100) == 0) {
              puVar17[0xb] = 0;
            }
            if ((puVar17[-9] == 0 && puVar17[-7] == 0) &&
               (uVar11 = *(uint *)(puVar17 + 0xe), (uVar11 & 1) == 0)) {
              puVar17[8] = 0;
              puVar17[9] = 0;
              puVar17[0] = 0;
              puVar17[1] = 0;
              puVar17[2] = 0;
              puVar17[3] = 0;
              puVar17[4] = 0;
              puVar17[5] = 0;
              *(uint *)(puVar17 + 0xe) = uVar11 & 0xfffffff7;
              puVar17[6] = 0;
              puVar17[7] = 0;
              puVar17[0xc] = 0x3f80;
              puVar17[0xd] = 0;
              if ((*(uint *)(puVar19 + 0x38) & 6) == 0) {
                puVar17[0x12] = 1;
                puVar17[0x11] = 1;
                puVar17[0x10] = 1;
                *(uint *)(puVar17 + 0xe) = uVar11 & 0xffffffe5;
                uVar20 = (*(unsigned int *)0x001dbf94);
                puVar17[10] = 0;
                *(undefined4 *)(puVar17 + -6) = uVar20;
                *(undefined4 *)(puVar17 + -2) = uVar20;
                *(undefined4 *)(puVar17 + -4) = uVar20;
              }
            }
            puVar17 = puVar17 + 0x20;
            puVar19 = puVar19 + -0x20;
          } while (iVar6 != 2);
          iVar6 = 0;
          puVar19 = param_1;
          do {
            if (((puVar19[1] != 0 || puVar19[3] != 0) || ((*(uint *)(puVar19 + 0x18) & 1) != 0)) &&
               ((param_1[0xd] != 0 || param_1[0xe] != 0) || param_1[0xf] != 0)) {
              *(uint *)(puVar19 + 0x18) = *(uint *)(puVar19 + 0x18) | 2;
            }
            bVar3 = iVar6 != 1;
            puVar19 = puVar19 + 0x20;
            param_1 = param_1 + 0x1d;
            iVar6 = iVar6 + 1;
          } while (bVar3);
          return;
        }
      } while( true );
    }
    uVar11 = uVar8 >> 5 & 3;
LAB_000c1c40:
    iVar6 = 0;
    uVar14 = uVar8 & 0x1f;
    uVar24 = uVar11;
    puVar19 = param_1 + 0x24;
    uVar26 = uVar12;
    if (uVar12 == 0) {
      uVar26 = 1;
    }
    do {
      iVar6 = iVar6 + 1;
      *(undefined4 *)puVar19 = *(undefined4 *)(uVar14 * 4 + 0x1dc04c);
      puVar19[1] = (ushort)(uVar24 << 0xc) | puVar19[1];
      uVar26 = uVar26 - 1;
      if (uVar26 == 0) goto LAB_000c1cec;
      uVar14 = uVar8 >> 7 & 0x1f;
      uVar24 = uVar8 >> 0xc & 3;
      if (iVar6 != 1) {
        if (iVar6 == 0) goto LAB_000c1c40;
        uVar14 = uVar8 >> 0xe & 0x1f;
        uVar24 = uVar8 >> 0x13 & 3;
        if (iVar6 != 2) {
          uVar14 = 0;
          uVar24 = 0;
        }
      }
      puVar19 = puVar19 + 2;
    } while( true );
  }
  iVar22 = iVar6 * 4 + param_3;
  param_1[2] = (ushort)(*(uint *)(iVar22 + 0x18) >> 6) & 0x1f;
  param_1[0x40] = (ushort)*(undefined4 *)(iVar22 + 0x18) & 0x1f;
  uVar8 = *(uint *)(iVar22 + 0x18) >> 0xf & 7;
  if (uVar8 == 2) {
    param_1[0x1d] = 1;
    param_1[0x18] = 0;
    param_1[0x19] = 1;
    param_1[10] = 0xf;
  }
  else {
    if (uVar8 < 3) {
      if (uVar8 != 1) goto LAB_000c1950;
    }
    else if (4 < uVar8) goto LAB_000c1950;
    param_1[10] = 0xf;
    param_1[3] = 0xf;
  }
LAB_000c1950:
  uVar8 = *(uint *)(iVar6 * 4 + param_3 + 0x18);
  param_1[0x16] = 0x3f80;
  param_1[0x17] = 0;
  param_1[0x14] = (ushort)(uVar8 >> 3) & 0xf00 | (ushort)(uVar8 >> 0xf) & 7;
  return;
}

/* FUN_000c1d60 @ 0xc1d60 (276 bytes) */
int FUN_000c1d60(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
{
  bool bVar1;
  undefined2 uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  if (((*(uint *)(param_1 + 0x30) | *(uint *)(param_1 + 0x70)) & 0x10) != 0) {
    return 0;
  }
  if (param_3 == 0) {
    iVar5 = param_2 * 4 + param_1;
    if (*(short *)(iVar5 + 0x20) != 0 || *(short *)(iVar5 + 0x60) != 0) {
      return 0;
    }
LAB_000c1da8:
    if (param_4 != 1) goto LAB_000c1dd0;
  }
  else if (param_3 != 1) goto LAB_000c1da8;
  iVar5 = param_2 * 4 + param_1;
  if (*(short *)(iVar5 + 0x22) != 0 || *(short *)(iVar5 + 0x62) != 0) {
    return 0;
  }
LAB_000c1dd0:
  iVar8 = 0;
  iVar7 = (param_2 * 3 + param_4) * 2 + param_1;
  iVar5 = (param_2 * 3 + param_3) * 2 + param_1;
  uVar2 = *(undefined2 *)(iVar5 + 0x80);
  *(undefined2 *)(iVar5 + 0x80) = *(undefined2 *)(iVar7 + 0x80);
  *(undefined2 *)(iVar7 + 0x80) = uVar2;
  do {
    iVar5 = param_1 + iVar8;
    iVar7 = 0;
    do {
      uVar6 = *(ushort *)(iVar5 + 8) & 0x300;
      uVar4 = *(ushort *)(iVar5 + 8) & 3;
      if (uVar6 == (param_2 + 1) * 0x100) {
        uVar3 = (ushort)uVar6;
        if (param_3 == uVar4) {
          *(ushort *)(iVar5 + 8) = (ushort)param_4 | uVar3;
        }
        else if (param_4 == uVar4) {
          *(ushort *)(iVar5 + 8) = (ushort)param_3 | uVar3;
        }
      }
      bVar1 = iVar7 != 2;
      iVar5 = iVar5 + 4;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    bVar1 = iVar8 != 0x40;
    iVar8 = iVar8 + 0x40;
  } while (bVar1);
  return 1;
}

/* FUN_000c1e90 @ 0xc1e90 (232 bytes) */
int FUN_000c1e90(param_1, param_2)
  int param_1;
  int param_2;
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar2 = param_2 * 6 + param_1;
  if (*(ushort *)(iVar2 + 0x84) < *(ushort *)(iVar2 + 0x82)) {
    uVar4 = ((int (*)())FUN_000c1d60)(param_1,param_2,1,2);
  }
  iVar2 = param_2 * 6 + param_1;
  uVar1 = *(ushort *)(iVar2 + 0x82);
  if (uVar1 < *(ushort *)(iVar2 + 0x80)) {
    uVar3 = ((int (*)())FUN_000c1d60)(param_1,param_2,0,1);
    uVar1 = *(ushort *)(iVar2 + 0x82);
    uVar4 = uVar4 | uVar3;
  }
  if (*(ushort *)(iVar2 + 0x84) < uVar1) {
    uVar3 = ((int (*)())FUN_000c1d60)(param_1,param_2,1,2);
    uVar4 = uVar4 | uVar3;
  }
  if (uVar4 != 0) {
    ((int (*)())FUN_000c0880)(param_1);
  }
  return uVar4;
}

/* FUN_000c1f80 @ 0xc1f80 (1824 bytes) */
int FUN_000c1f80(param_1, param_2, param_3)
  uint *param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  double dVar17;
  
  uVar9 = *param_1;
  if (uVar9 != 0) {
    uVar15 = 0;
    do {
      uVar7 = param_1[2];
      iVar8 = uVar15 * 0xa0 + uVar7;
      iVar5 = *(int *)(iVar8 + 0x8c);
      iVar6 = *(int *)(iVar8 + 0x90);
      uVar12 = (uint)*(ushort *)(iVar8 + 4);
      uVar2 = *(ushort *)(iVar8 + 0x44);
      if (iVar5 == 1) {
        iVar5 = iVar6 * 4 + param_3;
        uVar7 = *(uint *)(iVar5 + 0x18);
        uVar9 = (uVar12 & 0x1f) << 6;
        *(uint *)(iVar5 + 0x18) = uVar9 | uVar7 & 0xfffff83f;
        if ((*(short *)(iVar8 + 2) == 0 && *(short *)(iVar8 + 6) == 0) &&
           ((*(uint *)(iVar8 + 0x30) & 1) == 0)) {
          *(uint *)(iVar5 + 0x18) = uVar9 | uVar7 & 0xfffc783f;
        }
        iVar6 = iVar6 * 4 + param_3;
        uVar12 = *(uint *)(iVar6 + 0x18);
        uVar9 = *(ushort *)(iVar8 + 0x80) & 0x1f;
        *(uint *)(iVar6 + 0x18) = uVar9 | uVar12 & 0xffffffe0;
        uVar7 = (*(byte *)(iVar8 + 0x29) & 7) << 0xf;
        *(uint *)(iVar6 + 0x18) = uVar7 | uVar9 | uVar12 & 0xfffc7fe0;
        *(uint *)(iVar6 + 0x18) =
             (*(ushort *)(iVar8 + 0x28) & 0xf00) << 3 | uVar7 | uVar9 | uVar12 & 0xfff807e0;
        uVar9 = *param_1;
      }
      else if (iVar5 == 0) {
        iVar6 = iVar6 * 4;
        iVar5 = iVar6 + param_2;
        uVar16 = *(uint *)(iVar5 + 4);
        uVar9 = (uVar12 & 0x7f) << 0x12;
        uVar7 = (uVar2 & 0x7f) << 5;
        *(uint *)(iVar5 + 4) = uVar7 | uVar9 | uVar16 & 0xfe03f01f;
        if ((*(short *)(iVar8 + 2) == 0 && *(short *)(iVar8 + 6) == 0) &&
           ((*(uint *)(iVar8 + 0x30) & 1) == 0)) {
          *(uint *)(iVar5 + 4) = uVar7 | uVar9 | uVar16 & 0xfe00f01f;
        }
        else {
          uVar2 = *(ushort *)(iVar8 + 0x3a);
          if ((uVar2 == 2) || (uVar2 == 3)) {
            *(uint *)(iVar6 + param_2 + 4) =
                 (uVar2 & 3) << 0x10 | *(uint *)(iVar6 + param_2 + 4) & 0xfffcffff;
          }
          else if (uVar2 == 0) {
            *(uint *)(iVar6 + param_2 + 4) = *(uint *)(iVar6 + param_2 + 4) & 0xfffcffff | 0x10000;
          }
        }
        if ((*(short *)(iVar8 + 0x42) != 0 || *(short *)(iVar8 + 0x46) != 0) ||
           (iVar5 = 0, (*(uint *)(iVar8 + 0x70) & 1) != 0)) {
          iVar5 = 1;
        }
        iVar10 = iVar6 + param_2;
        uVar7 = *(uint *)(iVar10 + 4);
        uVar9 = iVar5 << 4;
        *(uint *)(iVar10 + 4) = uVar9 | uVar7 & 0xffffffef;
        if (*(ushort *)(iVar8 + 0x80) == 0xffff) {
          *(uint *)(iVar10 + 4) = uVar9 | uVar7 & 0xffff0fef;
        }
        else {
          *(uint *)(iVar10 + 4) =
               (*(ushort *)(iVar8 + 0x80) & 0xf) << 0xc | uVar9 | uVar7 & 0xffff0fef;
        }
        if (*(ushort *)(iVar8 + 0x86) == 0xffff) {
          *(uint *)(iVar6 + param_2 + 4) = *(uint *)(iVar6 + param_2 + 4) & 0xfffffff0;
        }
        else {
          *(uint *)(iVar6 + param_2 + 4) =
               *(ushort *)(iVar8 + 0x86) & 0xf | *(uint *)(iVar6 + param_2 + 4) & 0xfffffff0;
        }
        fVar4 = FLOAT_001aa0e8;
        iVar6 = iVar6 + param_2;
        uVar7 = *(uint *)(iVar6 + 4);
        uVar9 = (uint)(*(float *)(iVar8 + 0x2c) != FLOAT_001aa0e8) << 0x1b;
        *(uint *)(iVar6 + 4) = uVar9 | uVar7 & 0x7ffffff;
        *(uint *)(iVar6 + 4) =
             (uint)(*(float *)(iVar8 + 0x6c) != fVar4) << 0x19 | uVar9 | uVar7 & 0x5ffffff;
        uVar9 = *param_1;
      }
      else if (iVar5 == 2) {
        iVar6 = iVar6 * 4;
        iVar10 = iVar6 + param_3;
        iVar13 = 0;
        *(uint *)(iVar10 + 0x98) = (uVar12 & 0x1f) << 0x12 | *(uint *)(iVar10 + 0x98) & 0xff83ffff;
        *(uint *)(iVar10 + 0x198) = (uVar2 & 0x1f) << 0x12 | *(uint *)(iVar10 + 0x198) & 0xff83ffff;
        uVar12 = *(uint *)(iVar10 + 0x98);
        uVar9 = (*(ushort *)(iVar8 + 2) & 7) << 0x1a;
        *(uint *)(iVar10 + 0x98) = uVar9 | uVar12 & 0xe3ffffff;
        *(uint *)(iVar10 + 0x98) =
             (*(ushort *)(uVar15 * 0xa0 + uVar7) & 3) << 0x1d | uVar9 | uVar12 & 0x83ffffff;
        uVar12 = *(uint *)(iVar10 + 0x198);
        uVar9 = (*(ushort *)(iVar8 + 0x42) & 8) << 0x15;
        *(uint *)(iVar10 + 0x198) = uVar9 | uVar12 & 0xfeffffff;
        uVar7 = (*(ushort *)(iVar8 + 0x42) & 0x10) << 0x17;
        *(uint *)(iVar10 + 0x198) = uVar7 | uVar9 | uVar12 & 0xf6ffffff;
        *(uint *)(iVar10 + 0x198) =
             (*(ushort *)(iVar8 + 0x40) & 3) << 0x19 | uVar7 | uVar9 | uVar12 & 0xf0ffffff;
        *(uint *)(iVar10 + 0x98) =
             (*(ushort *)(iVar8 + 6) & 7) << 0x17 | *(uint *)(iVar10 + 0x98) & 0xfc7fffff;
        *(uint *)(iVar10 + 0x198) =
             (*(ushort *)(iVar8 + 0x46) & 8) << 0x14 | *(uint *)(iVar10 + 0x198) & 0xff7fffff;
        iVar5 = iVar8;
        do {
          uVar2 = *(ushort *)(iVar5 + 0x80);
          uVar9 = (uint)uVar2;
          uVar3 = *(ushort *)(iVar5 + 0x86);
          uVar7 = (uint)uVar3;
          if (uVar9 == 0xffff) {
            uVar9 = 0x20;
          }
          else if ((short)uVar2 < 0) {
            uVar9 = ((int)(short)uVar2 & 0x7fffU) + 0x20;
          }
          if (uVar7 == 0xffff) {
            uVar7 = 0x20;
          }
          else if ((short)uVar3 < 0) {
            uVar7 = ((int)(short)uVar3 & 0x7fffU) + 0x20;
          }
          if (iVar13 == 1) {
            *(uint *)(iVar10 + 0x98) = (uVar9 & 0x3f) << 6 | *(uint *)(iVar10 + 0x98) & 0xfffff03f;
            *(uint *)(iVar10 + 0x198) = (uVar7 & 0x3f) << 6 | *(uint *)(iVar10 + 0x198) & 0xfffff03f
            ;
          }
          else if (iVar13 == 0) {
            *(uint *)(iVar10 + 0x98) = uVar9 & 0x3f | *(uint *)(iVar10 + 0x98) & 0xffffffc0;
            *(uint *)(iVar10 + 0x198) = uVar7 & 0x3f | *(uint *)(iVar10 + 0x198) & 0xffffffc0;
          }
          else if (iVar13 == 2) {
            *(uint *)(iVar10 + 0x98) = (uVar9 & 0x3f) << 0xc | *(uint *)(iVar10 + 0x98) & 0xfffc0fff
            ;
            *(uint *)(iVar10 + 0x198) =
                 (uVar7 & 0x3f) << 0xc | *(uint *)(iVar10 + 0x198) & 0xfffc0fff;
          }
          bVar1 = iVar13 != 2;
          iVar5 = iVar5 + 2;
          iVar13 = iVar13 + 1;
        } while (bVar1);
        iVar5 = iVar6 + param_3;
        iVar10 = 0;
        do {
          uVar12 = 0;
          uVar9 = 0;
          uVar16 = 0;
          uVar7 = 0;
          iVar13 = 0;
          iVar14 = iVar8 + 8;
          do {
            uVar2 = *(ushort *)(iVar10 * 4 + iVar14 + 2);
            uVar11 = *(ushort *)(iVar10 * 4 + iVar14) & 3;
            if (iVar13 == 0) {
              uVar12 = 6;
              if (((uVar2 & 0x300) != 0x100) && (uVar12 = 5, (uVar2 & 0x300) != 0x200)) {
                uVar12 = uVar2 & 0x1f;
              }
              uVar9 = (uVar2 & 0x3000) >> 0xc;
              uVar12 = (uint)*(byte *)(uVar12 * 4 + 0x1dc000 + uVar11);
            }
            else if (iVar13 == 1) {
              uVar7 = (uVar2 & 0x3000) >> 0xc;
              uVar16 = (uint)*(byte *)((uVar2 & 0x1f) * 4 + 0x1dbfb4 + uVar11);
            }
            bVar1 = iVar13 != 1;
            iVar14 = iVar14 + 0x40;
            iVar13 = iVar13 + 1;
          } while (bVar1);
          if (iVar10 == 1) {
            *(uint *)(iVar5 + 0x298) =
                 uVar9 << 0xc | (uVar12 & 0x1f) << 7 | *(uint *)(iVar5 + 0x298) & 0xffffc07f;
            *(uint *)(iVar5 + 0x398) =
                 uVar7 << 0xc | (uVar16 & 0x1f) << 7 | *(uint *)(iVar5 + 0x398) & 0xffffc07f;
          }
          else if (iVar10 == 0) {
            *(uint *)(iVar5 + 0x298) =
                 uVar9 << 5 | uVar12 & 0x1f | *(uint *)(iVar5 + 0x298) & 0xffffff80;
            *(uint *)(iVar5 + 0x398) =
                 uVar7 << 5 | uVar16 & 0x1f | *(uint *)(iVar5 + 0x398) & 0xffffff80;
          }
          else if (iVar10 == 2) {
            *(uint *)(iVar5 + 0x298) =
                 uVar9 << 0x13 | (uVar12 & 0x1f) << 0xe | *(uint *)(iVar5 + 0x298) & 0xffe03fff;
            *(uint *)(iVar5 + 0x398) =
                 uVar7 << 0x13 | (uVar16 & 0x1f) << 0xe | *(uint *)(iVar5 + 0x398) & 0xffe03fff;
          }
          bVar1 = iVar10 != 2;
          iVar10 = iVar10 + 1;
        } while (bVar1);
        iVar10 = 0;
        iVar5 = iVar8;
        do {
          dVar17 = (double)*(float *)(iVar5 + 0x2c) * DOUBLE_001aa290;
          if (DOUBLE_001aa1e8 <= dVar17) {
            uVar9 = (int)(dVar17 - DOUBLE_001aa1e8) + 0x80000000;
          }
          else {
            uVar9 = (uint)dVar17;
          }
          switch(uVar9) {
          case 1:
            uVar9 = 6;
            break;
          case 2:
            uVar9 = 5;
            break;
          case 4:
            uVar9 = 4;
            break;
          case 8:
            uVar9 = 0;
            break;
          case 0x10:
            uVar9 = 1;
            break;
          case 0x20:
            uVar9 = 2;
            break;
          case 0x40:
            uVar9 = 3;
          }
          if (iVar10 == 0) {
            iVar13 = iVar6 + param_3;
            uVar7 = *(uint *)(iVar13 + 0x298);
            uVar9 = (uVar9 & 7) << 0x1b;
            *(uint *)(iVar13 + 0x298) = uVar9 | uVar7 & 0xc7ffffff;
            *(uint *)(iVar13 + 0x298) =
                 (*(uint *)(iVar8 + 0x30) & 8) << 0x1b | uVar9 | uVar7 & 0x87ffffff;
          }
          else if (iVar10 == 1) {
            iVar13 = iVar6 + param_3;
            uVar7 = *(uint *)(iVar13 + 0x398);
            uVar9 = (uVar9 & 7) << 0x1b;
            *(uint *)(iVar13 + 0x398) = uVar9 | uVar7 & 0xc7ffffff;
            *(uint *)(iVar13 + 0x398) =
                 (*(uint *)(iVar8 + 0x70) & 8) << 0x1b | uVar9 | uVar7 & 0x87ffffff;
          }
          bVar1 = iVar10 != 1;
          iVar5 = iVar5 + 0x40;
          iVar10 = iVar10 + 1;
        } while (bVar1);
        iVar6 = iVar6 + param_3;
        iVar10 = 0;
        iVar5 = iVar8;
        do {
          uVar9 = (uint)*(byte *)((uint)*(ushort *)(iVar5 + 0x28) * 2 + 0x1dbf98 + iVar10);
          if (iVar10 == 0) {
            uVar7 = *(uint *)(iVar6 + 0x298);
            uVar9 = (uVar9 & 0xf) << 0x17;
            *(uint *)(iVar6 + 0x298) = uVar9 | uVar7 & 0xf87fffff;
            *(uint *)(iVar6 + 0x298) =
                 (*(ushort *)(iVar8 + 0x2a) & 3) << 0x15 | uVar9 | uVar7 & 0xf81fffff;
          }
          else if (iVar10 == 1) {
            uVar7 = *(uint *)(iVar6 + 0x398);
            uVar9 = (uVar9 & 0xf) << 0x17;
            *(uint *)(iVar6 + 0x398) = uVar9 | uVar7 & 0xf87fffff;
            *(uint *)(iVar6 + 0x398) =
                 (*(ushort *)(iVar8 + 0x6a) & 3) << 0x15 | uVar9 | uVar7 & 0xf81fffff;
          }
          bVar1 = iVar10 != 1;
          iVar5 = iVar5 + 0x40;
          iVar10 = iVar10 + 1;
        } while (bVar1);
        uVar9 = *param_1;
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 < uVar9);
  }
  return;
}

/* FUN_000c2834 @ 0xc2834 (1536 bytes) */
int FUN_000c2834(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  undefined4 param_4;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_r4;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined2 *puVar9;
  int iVar10;
  uint uVar11;
  short sVar13;
  ushort uVar14;
  ushort uVar15;
  short *psVar12;
  ushort *puVar16;
  uint uVar17;
  ushort *puVar18;
  ushort *puVar19;
  uint *puVar20;
  short *psVar21;
  undefined2 uVar22;
  undefined2 uVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  uint uStack_68;
  uint uStack_64;
  short *psStack_60;
  undefined4 uStack_50;
  
  uVar11 = *(uint *)(param_1 + 0x30);
  uVar24 = param_2[3];
  psVar21 = (short *)(uVar24 + uVar11 * 4);
  psStack_60 = psVar21 + 8;
  if (param_3 == 0) {
    puVar20 = (uint *)0x0;
  }
  else {
    puVar20 = &uStack_68;
    uVar11 = 0x80;
  }
  sVar13 = 0;
  iVar26 = 4;
  psVar12 = psVar21;
  do {
    *psVar12 = sVar13;
    psVar12[1] = 0xf;
    sVar13 = sVar13 + 1;
    psVar12 = psVar12 + 2;
    iVar26 = iVar26 + -1;
  } while (iVar26 != 0);
  psVar21[1] = psVar21[1] | 0x10;
  _memset(uVar24,0,*(int *)(param_1 + 0x30) << 2);
  uStack_68 = 0;
  if (uVar11 != 0) {
    uStack_68 = uVar11 & 0xffff;
    iVar26 = 0;
    uVar17 = uStack_68;
    do {
      uVar3 = uVar17 - 1;
      uVar17 = uVar3 & 0xffff;
      psStack_60[iVar26] = (short)uVar3;
      uVar11 = uVar11 - 1;
      iVar26 = iVar26 + 1;
    } while (uVar11 != 0);
  }
  uVar17 = 0;
  uStack_64 = 0;
  uVar11 = *param_2;
  iVar26 = (uVar11 - 1) * 0xa0;
  do {
    iVar25 = iVar26 + param_2[2];
    iVar2 = *(int *)(iVar25 + 0x8c);
    if (iVar2 == 2) {
      iVar8 = 0;
      iVar6 = 0;
      iVar2 = iVar25;
      do {
        if (((((*(ushort *)(iVar2 + 6) != 0) && ((*(uint *)(iVar2 + 0x30) & 0x400) != 0)) &&
             ((*(uint *)(iVar2 + 0x30) & 0x1800) == 0)) &&
            ((uStack_50 = 0x3f800000, *(float *)(iVar2 + 0x2c) == 1.0 &&
             ((*(ushort *)(iVar2 + 10) & 0x10) == 0)))) &&
           ((*(short *)((iVar6 + (*(ushort *)(iVar2 + 8) & 3)) * 2 + iVar25 + 0x80) ==
             *(short *)(iVar2 + 4) &&
            ((*(ushort *)(iVar2 + 6) & ~(*(ushort *)(iVar2 + 10) & 0xf)) == 0)))) {
          *(undefined2 *)(iVar2 + 6) = 0;
        }
        bVar1 = iVar8 != 1;
        iVar2 = iVar2 + 0x40;
        iVar6 = iVar6 + 3;
        iVar8 = iVar8 + 1;
      } while (bVar1);
      iVar2 = *(int *)(iVar25 + 0x8c);
    }
    if (iVar2 == 2) {
      iVar2 = 0;
      do {
        puVar18 = (ushort *)(iVar2 + iVar25);
        uVar14 = puVar18[1];
        bVar1 = (uVar14 >> 4 & 1) != 0;
        if ((bVar1) && ((psVar21[1] & 0x10U) == 0)) {
          uVar14 = uVar14 & 0xffef;
          puVar18[1] = uVar14;
        }
        uVar15 = *puVar18;
        uVar14 = (psVar21[(uint)uVar15 * 2 + 1] | 0x10U) & uVar14;
        puVar18[1] = uVar14;
        psVar21[(uint)uVar15 * 2 + 1] = psVar21[(uint)uVar15 * 2 + 1] & ~uVar14;
        if (bVar1) {
          psVar21[1] = psVar21[1] & 0xffef;
        }
        bVar1 = iVar2 != 0x40;
        iVar2 = iVar2 + 0x40;
      } while (bVar1);
    }
    iVar6 = 0;
    uVar23 = *(undefined2 *)(uVar24 + (uint)*(ushort *)(iVar25 + 4) * 4);
    uVar22 = *(undefined2 *)((uint)*(ushort *)(iVar25 + 0x44) * 4 + uVar24);
    iVar2 = iVar25;
    do {
      puVar9 = (undefined2 *)(uVar24 + (uint)*(ushort *)(iVar2 + 4) * 4);
      uVar14 = puVar9[1];
      uVar15 = uVar14 & *(ushort *)(iVar2 + 6);
      *(ushort *)(iVar2 + 6) = uVar15;
      if ((*(int *)(iVar25 + 0x8c) != 2) && (uVar15 != 0)) {
        uVar15 = 0xf;
        *(undefined2 *)(iVar2 + 6) = 0xf;
      }
      puVar9[1] = puVar9[1] & ~uVar15;
      if ((*(short *)(iVar2 + 2) == 0 && *(short *)(iVar2 + 6) == 0) &&
         ((*(uint *)(iVar2 + 0x30) & 1) == 0)) {
        *(undefined4 *)(iVar2 + 0x24) = 0;
        *(undefined4 *)(iVar2 + 0x14) = 0;
        *(undefined4 *)(iVar2 + 0x18) = 0;
        *(undefined4 *)(iVar2 + 0x1c) = 0;
        *(undefined4 *)(iVar2 + 0x20) = 0;
      }
      if (((puVar20 != (uint *)0x0) && (uVar14 != 0)) && (puVar9[1] == 0)) {
        uVar3 = *puVar20;
        *(undefined2 *)(uVar3 * 2 + puVar20[2]) = *puVar9;
        *puVar20 = uVar3 + 1;
        *puVar9 = 0;
      }
      bVar1 = iVar6 != 0x40;
      iVar2 = iVar2 + 0x40;
      iVar6 = iVar6 + 0x40;
    } while (bVar1);
    iVar8 = 0;
    iVar6 = 0x80;
    iVar2 = iVar25;
    do {
      puVar18 = (ushort *)(iVar25 + iVar6);
      iVar4 = 0;
      iVar5 = iVar2 + 0x10;
      do {
        if ((*puVar18 & 0x8000) == 0) {
          puVar19 = (ushort *)(iVar5 + 4);
          iVar10 = 0;
          puVar16 = (ushort *)(uVar24 + (uint)*puVar18 * 4);
          do {
            uVar14 = puVar16[1];
            uVar15 = *puVar19;
            puVar16[1] = uVar15 | uVar14;
            if ((uVar14 == 0) && (uVar15 != 0)) {
              uStack_68 = uStack_68 - 1;
              uVar14 = psStack_60[uStack_68];
              if (uStack_64 < uVar14) {
                uStack_64 = (uint)uVar14;
              }
              *puVar16 = uVar14;
            }
            bVar1 = iVar10 != 1;
            puVar19 = puVar19 + 0x20;
            iVar10 = iVar10 + 1;
          } while (bVar1);
        }
        bVar1 = iVar4 != 2;
        iVar5 = iVar5 + 2;
        puVar18 = puVar18 + 1;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      bVar1 = iVar8 != 1;
      iVar2 = iVar2 + 6;
      iVar6 = iVar6 + 6;
      iVar8 = iVar8 + 1;
    } while (bVar1);
    if (*(short *)(iVar25 + 6) == 0) {
      uVar23 = 0;
    }
    *(undefined2 *)(iVar25 + 4) = uVar23;
    if (*(short *)(iVar25 + 0x46) == 0) {
      uVar22 = 0;
    }
    *(undefined2 *)(iVar25 + 0x44) = uVar22;
    iVar2 = 0;
    uVar7 = 0xffffffff;
    iVar6 = iVar25 + 0x10;
    do {
      psVar12 = (short *)(iVar6 + 4);
      iVar8 = 0;
      do {
        if (*psVar12 == 0 && psVar12[0x20] == 0) {
          psVar12[0x36] = -1;
        }
        else if ((psVar12[0x36] & 0x8000U) == 0) {
          psVar12[0x36] = *(short *)(uVar24 + (uint)(ushort)psVar12[0x36] * 4);
        }
        bVar1 = iVar8 != 2;
        psVar12 = psVar12 + 1;
        iVar8 = iVar8 + 1;
      } while (bVar1);
      bVar1 = iVar2 != 1;
      iVar6 = iVar6 + 6;
      iVar2 = iVar2 + 1;
    } while (bVar1);
    if (*(int *)(iVar25 + 0x8c) == 2) {
      ((int (*)())FUN_000c0880)(iVar25);
      ((int (*)())FUN_000c1e90)(iVar25,0);
      ((int (*)())FUN_000c1e90)(iVar25,1);
      ((int (*)())FUN_000c0fd0)(iVar25,extraout_r4,iVar4,iVar5,uVar7,iVar2,psVar12,iVar6);
    }
    uVar17 = uVar17 + 1;
    iVar26 = iVar26 + -0xa0;
  } while (uVar11 != uVar17);
  uVar11 = *param_2;
  if (uVar11 == 0) {
    uVar17 = 0;
  }
  else {
    uVar24 = 0;
    uVar17 = 0;
    do {
      iVar26 = param_2[2] + uVar24 * 0xa0;
      if (((*(short *)(iVar26 + 2) != 0 || *(short *)(iVar26 + 6) != 0) ||
          ((*(uint *)(iVar26 + 0x30) & 1) != 0)) ||
         ((*(short *)(iVar26 + 0x42) != 0 || *(short *)(iVar26 + 0x46) != 0 ||
          ((*(uint *)(iVar26 + 0x70) & 1) != 0)))) {
        if (uVar17 < uVar24) {
          _memcpy(uVar17 * 0xa0 + param_2[2],iVar26,0xa0);
          uVar11 = *param_2;
        }
        uVar17 = uVar17 + 1;
      }
      uVar24 = uVar24 + 1;
    } while (uVar24 < uVar11);
  }
  *param_2 = uVar17;
  param_2[1] = uStack_64 + 1;
  if (uVar17 == 0) {
    uVar7 = 0x80000004;
  }
  else {
    if (param_3 != 0) {
      ((int (*)())FUN_000c1f80)(param_2,param_3,param_4);
    }
    uVar7 = 0;
  }
  return uVar7;
}

/* FUN_000c2e40 @ 0xc2e40 (48 bytes) */
int FUN_000c2e40(param_1)
  undefined4 param_1;
{
  ushort uVar1;
  
  uVar1 = (*(unsigned short *)((unsigned char *)&(param_1) + 2)) & 0xf;
  if (((1 < (ushort)(uVar1 - 1)) && (uVar1 != 4)) && (uVar1 != 8)) {
    return 0;
  }
  return 1;
}

/* FUN_000c2e70 @ 0xc2e70 (36 bytes) */
int FUN_000c2e70(param_1, param_2)
  int param_1;
  uint param_2;
{
  if (((*(ushort *)(param_1 + 0x46) & 8) != 0) && (*(ushort *)(param_1 + 0x44) == param_2)) {
    return 1;
  }
  return 0;
}

/* FUN_000c2ea0 @ 0xc2ea0 (120 bytes) */
int FUN_000c2ea0(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  bool bVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = param_1 + 0x50;
  iVar7 = param_1 + 0x54;
  iVar4 = 0;
  iVar3 = param_1 + 0x14;
  do {
    puVar2 = (ushort *)(iVar6 + 4);
    iVar5 = 0;
    do {
      if (puVar2[0x16] == param_2) {
        if (((*(ushort *)((iVar3 - iVar7) + (int)puVar2) & 8) != 0) || ((*puVar2 & 8) != 0)) {
          return 1;
        }
      }
      bVar1 = iVar5 != 2;
      puVar2 = puVar2 + 1;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    bVar1 = iVar4 == 1;
    iVar6 = iVar6 + 6;
    iVar3 = iVar3 + 6;
    iVar7 = iVar7 + 6;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      return 0;
    }
  } while( true );
}

/* FUN_000c2f20 @ 0xc2f20 (140 bytes) */
int FUN_000c2f20(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  
  iVar3 = 0;
  do {
    iVar4 = 0;
    iVar5 = 0;
    iVar2 = iVar3 * 0x40 + param_1 + 0x10;
    do {
      puVar6 = (ushort *)(iVar2 + 4);
      iVar7 = 0;
      puVar8 = (ushort *)(param_1 + iVar5 + 0x80);
      do {
        if ((((*(unsigned short *)((unsigned char *)&(param_2) + 2)) & *puVar6) != 0) && (*puVar8 == param_3)) {
          return 1;
        }
        bVar1 = iVar7 != 2;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
        iVar7 = iVar7 + 1;
      } while (bVar1);
      bVar1 = iVar4 != 1;
      iVar5 = iVar5 + 6;
      iVar2 = iVar2 + 6;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    bVar1 = iVar3 == 1;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return 0;
    }
  } while( true );
}

/* FUN_000c2fb0 @ 0xc2fb0 (148 bytes) */
int FUN_000c2fb0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  
  iVar3 = 0;
  do {
    iVar4 = 0;
    iVar5 = 0;
    iVar2 = iVar3 * 0x40 + param_1 + 0x10;
    do {
      puVar6 = (ushort *)(iVar2 + 4);
      iVar7 = 0;
      puVar8 = (ushort *)(param_1 + iVar5 + 0x80);
      do {
        if ((((*puVar6 & param_2) != 0) && (*puVar6 != param_2)) && (*puVar8 == param_3)) {
          return 1;
        }
        bVar1 = iVar7 != 2;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
        iVar7 = iVar7 + 1;
      } while (bVar1);
      bVar1 = iVar4 != 1;
      iVar5 = iVar5 + 6;
      iVar2 = iVar2 + 6;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    bVar1 = iVar3 == 1;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return 0;
    }
  } while( true );
}

/* FUN_000c3050 @ 0xc3050 (64 bytes) */
int FUN_000c3050(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  if (*(ushort *)(param_1 + 4) == param_3) {
    param_2 = param_2 & ~(uint)*(ushort *)(param_1 + 6);
  }
  if (param_3 == *(ushort *)(param_1 + 0x44)) {
    param_2 = param_2 & ~(uint)*(ushort *)(param_1 + 0x46);
  }
  return param_2 == 0;
}

/* FUN_000c3090 @ 0xc3090 (52 bytes) */
int FUN_000c3090(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    if (*(short *)(param_1 + 0x86) == -1) {
      return iVar2;
    }
    bVar1 = iVar2 != 2;
    param_1 = param_1 + 2;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  return -1;
}

/* FUN_000c30d0 @ 0xc30d0 (40 bytes) */
int FUN_000c30d0(param_1)
  undefined4 param_1;
{
  uint uVar1;
  
  uVar1 = ((int (*)())FUN_000c3090)(param_1);
  return ~uVar1 >> 0x1f;
}

/* FUN_000c3100 @ 0xc3100 (312 bytes) */
int FUN_000c3100(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
  uint param_5;
{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_r4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ushort *puVar9;
  int iVar10;
  
  uVar3 = param_3 >> 3 & 1;
  if ((param_3 & 7) != 0) {
    uVar3 = 0;
  }
  uVar5 = 2;
  if ((param_4 != 2) && (uVar5 = 3, param_4 != 3)) {
    uVar5 = (uint)(param_4 == 1);
  }
  iVar10 = 0;
  iVar7 = (uint)(param_2 == 8) * 3;
  iVar6 = (uVar3 * 3 + param_4) * 2 + param_1;
  iVar4 = param_1;
  do {
    puVar9 = (ushort *)(iVar4 + 10);
    iVar8 = 0;
    do {
      uVar2 = *puVar9;
      uVar3 = (uint)uVar2;
      if (((uVar2 & 0x1f) == param_2) &&
         (*(ushort *)((iVar7 + (puVar9[-1] & 3)) * 2 + param_1 + 0x80) == param_5)) {
        *puVar9 = uVar2 & 0xffe0 | (ushort)param_3;
        puVar9[-1] = puVar9[-1] & 0xfcfc | 0x200 | (ushort)uVar5;
        *(short *)(iVar6 + 0x80) = (short)param_5;
      }
      bVar1 = iVar8 != 2;
      puVar9 = puVar9 + 2;
      iVar8 = iVar8 + 1;
    } while (bVar1);
    bVar1 = iVar10 != 1;
    iVar4 = iVar4 + 0x40;
    iVar10 = iVar10 + 1;
  } while (bVar1);
  if (*(int *)(param_1 + 0x8c) == 2) {
    ((int (*)())FUN_000c0880)(param_1);
    ((int (*)())FUN_000c0fd0)(param_1,extraout_r4,uVar5,iVar6,iVar7,iVar8,puVar9,uVar3);
  }
  return 1;
}

/* FUN_000c3240 @ 0xc3240 (916 bytes) */
int FUN_000c3240(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
  uint param_5;
  uint param_6;
  undefined4 param_7;
  int param_8;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  undefined4 extraout_r4;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  undefined2 *puVar17;
  int iVar18;
  ushort *puVar19;
  uint uVar20;
  uint uVar21;
  int aiStack_58 [11];
  
  uVar20 = (param_5 & 8) << 6;
  if ((param_5 & 7) == 0) {
    if ((param_5 & 8) == 0) {
      return 0;
    }
  }
  else {
    uVar20 = uVar20 | 0x100;
  }
  uVar11 = (uint)(param_4 == 8);
  uVar5 = (ushort)param_5;
  if ((param_5 == 0x10) || (param_5 == 0x12)) {
    param_5 = param_5 & 0xffff;
    iVar15 = 0;
    puVar6 = (ushort *)(param_1 + uVar11 * 0x40 + 8);
    do {
      bVar1 = iVar15 != 2;
      puVar6[1] = uVar5;
      iVar15 = iVar15 + 1;
      *puVar6 = *puVar6 & 0xfcff;
      puVar6 = puVar6 + 2;
    } while (bVar1);
    param_7 = 3;
    uVar14 = param_6;
  }
  else {
    uVar14 = 0;
    bVar2 = (uVar20 >> 8 & 1) != 0;
    bVar1 = uVar20 >> 9 != 0;
    puVar6 = (ushort *)(param_1 + uVar11 * 0x40 + 8);
    do {
      uVar10 = *puVar6 & 3;
      if (((uVar10 < 3) && ((puVar6[1] & 0x1f) == param_6)) &&
         (iVar15 = ((*puVar6 & 0x300) == 0x100 ^ 1) * 3,
         *(ushort *)((iVar15 + uVar10) * 2 + param_1 + 0x80) == param_2)) {
        iVar12 = 0;
        iVar18 = 0;
        do {
          puVar7 = (undefined4 *)((int)aiStack_58 + iVar18);
          iVar16 = 0;
          do {
            bVar3 = iVar16 != 2;
            *puVar7 = 0;
            iVar16 = iVar16 + 1;
            puVar7 = puVar7 + 1;
          } while (bVar3);
          bVar3 = iVar12 != 1;
          iVar18 = iVar18 + 0xc;
          iVar12 = iVar12 + 1;
        } while (bVar3);
        uVar21 = 0;
        iVar12 = param_1;
        iVar18 = param_1;
        do {
          puVar19 = (ushort *)(iVar18 + 8);
          uVar13 = 0;
          do {
            if ((uVar11 != uVar21) || (uVar14 != uVar13)) {
              uVar4 = *puVar19;
              uVar8 = uVar4 & 3;
              if (uVar8 == 3) {
                if (((uVar4 & 0x100) != 0) &&
                   (aiStack_58[0] = 1, (ushort)(*(short *)(iVar12 + 0x2a) - 1U) < 2)) {
                  aiStack_58[1] = 1;
                }
                if (((uVar4 & 0x200) != 0) &&
                   (aiStack_58[3] = 1, (ushort)(*(short *)(iVar12 + 0x2a) - 1U) < 2)) {
                  aiStack_58[4] = 1;
                }
              }
              else {
                if ((uVar4 & 0x100) != 0) {
                  aiStack_58[uVar8] = 1;
                }
                if ((uVar4 & 0x200) != 0) {
                  aiStack_58[uVar8 + 3] = 1;
                }
              }
            }
            bVar3 = uVar13 != 2;
            puVar19 = puVar19 + 2;
            uVar13 = uVar13 + 1;
          } while (bVar3);
          bVar3 = uVar21 != 1;
          iVar18 = iVar18 + 0x40;
          iVar12 = iVar12 + 0x40;
          uVar21 = uVar21 + 1;
        } while (bVar3);
        iVar18 = 0;
        iVar12 = 0x80;
        param_4 = 0;
        do {
          piVar9 = (int *)((int)aiStack_58 + param_4);
          puVar17 = (undefined2 *)(param_1 + iVar12);
          iVar16 = 0;
          do {
            if (*piVar9 == 0) {
              *puVar17 = 0xffff;
            }
            bVar3 = iVar16 != 2;
            piVar9 = piVar9 + 1;
            puVar17 = puVar17 + 1;
            iVar16 = iVar16 + 1;
          } while (bVar3);
          bVar3 = iVar18 != 1;
          param_4 = param_4 + 0xc;
          iVar12 = iVar12 + 6;
          iVar18 = iVar18 + 1;
        } while (bVar3);
        param_8 = 0;
        param_7 = 0xffff;
        iVar12 = param_1;
        while ((((bVar2 && (*(ushort *)(iVar12 + 0x80) != 0xffff)) &&
                (param_3 != *(ushort *)(iVar12 + 0x80))) ||
               (((bVar1 && (*(ushort *)(iVar12 + 0x86) != 0xffff)) &&
                (param_3 != *(ushort *)(iVar12 + 0x86)))))) {
          bVar3 = param_8 == 2;
          iVar12 = iVar12 + 2;
          param_8 = param_8 + 1;
          if (bVar3) {
            *(short *)((iVar15 + uVar10) * 2 + param_1 + 0x80) = (short)param_2;
            return 0;
          }
        }
        if (bVar2) {
          *(short *)(param_8 * 2 + param_1 + 0x80) = (short)param_3;
        }
        if (bVar1) {
          *(short *)(param_8 * 2 + param_1 + 0x86) = (short)param_3;
        }
        puVar6[1] = puVar6[1] & 0xffe0 | uVar5;
        *puVar6 = (*puVar6 & 0xfffc | (ushort)param_8) & 0xfcff | (ushort)uVar20;
      }
      bVar3 = uVar14 != 2;
      puVar6 = puVar6 + 2;
      uVar14 = uVar14 + 1;
    } while (bVar3);
  }
  if (*(int *)(param_1 + 0x8c) == 2) {
    ((int (*)())FUN_000c0880)(param_1);
    ((int (*)())FUN_000c0fd0)(param_1,extraout_r4,uVar11,param_4,param_5,uVar14,param_7,param_8);
  }
  return 0;
}

/* FUN_000c3600 @ 0xc3600 (120 bytes) */
int FUN_000c3600(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  bool bVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = param_1 + 0x50;
  iVar7 = param_1 + 0x54;
  iVar4 = 0;
  iVar3 = param_1 + 0x14;
  do {
    puVar2 = (ushort *)(iVar6 + 4);
    iVar5 = 0;
    do {
      if (puVar2[0x16] == param_2) {
        if (((*(ushort *)((iVar3 - iVar7) + (int)puVar2) & (*(unsigned short *)((unsigned char *)&(param_3) + 2))) != 0) ||
           (((*(unsigned short *)((unsigned char *)&(param_3) + 2)) & *puVar2) != 0)) {
          return 1;
        }
      }
      bVar1 = iVar5 != 1;
      puVar2 = puVar2 + 3;
      iVar5 = iVar5 + 1;
    } while (bVar1);
    bVar1 = iVar4 == 2;
    iVar6 = iVar6 + 2;
    iVar3 = iVar3 + 2;
    iVar7 = iVar7 + 2;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      return 0;
    }
  } while( true );
}

/* FUN_000c3680 @ 0xc3680 (100 bytes) */
int FUN_000c3680(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  bool bVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = param_1 + 0x10;
  iVar5 = 0;
  do {
    puVar2 = (ushort *)(iVar3 + 4);
    iVar4 = 0;
    do {
      if (puVar2[0x36] == param_2) {
        if (((*puVar2 & (*(unsigned short *)((unsigned char *)&(param_3) + 2))) != 0) && ((*puVar2 & ~(*(unsigned short *)((unsigned char *)&(param_3) + 2))) != 0)) {
          return 1;
        }
      }
      bVar1 = iVar4 != 1;
      puVar2 = puVar2 + 3;
      iVar4 = iVar4 + 1;
    } while (bVar1);
    bVar1 = iVar5 == 2;
    iVar3 = iVar3 + 2;
    iVar5 = iVar5 + 1;
    if (bVar1) {
      return 0;
    }
  } while( true );
}

/* FUN_000c36f0 @ 0xc36f0 (60 bytes) */
int FUN_000c36f0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  int iVar2;
  
  iVar2 = 0;
  while ((*(ushort *)(param_1 + 4) != param_2 || ((*(ushort *)(param_1 + 6) & (*(unsigned short *)((unsigned char *)&(param_3) + 2))) == 0)))
  {
    bVar1 = iVar2 == 1;
    param_1 = param_1 + 0x40;
    iVar2 = iVar2 + 1;
    if (bVar1) {
      return 0;
    }
  }
  return 1;
}

/* FUN_000c3740 @ 0xc3740 (120 bytes) */
int FUN_000c3740(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = (ushort *)(param_1 + (uint)(param_2 == 8) * 0x40 + 8);
  do {
    if ((*puVar2 & 3) == 3) {
      return 0;
    }
    bVar1 = iVar3 != 2;
    puVar2 = puVar2 + 2;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  if (((*(uint *)((1 - (uint)(param_2 == 8)) * 0x40 + param_1 + 0x30) & 0x20) == 0) &&
     (1 < param_3 - 1U)) {
    return 1;
  }
  return 0;
}

/* FUN_000c37c0 @ 0xc37c0 (216 bytes) */
int FUN_000c37c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  uint param_2;
  uint param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  ushort uVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  ushort *puVar7;
  int iVar8;
  
  if (param_4 == 0) {
    uVar4 = 0x100;
  }
  else {
    uVar4 = 0x200;
  }
  iVar8 = 0;
  iVar5 = param_1;
  do {
    puVar7 = (ushort *)(iVar5 + 8);
    iVar6 = 0;
    do {
      uVar2 = *puVar7;
      if (((uVar2 & 0x300) != 0) && ((uVar4 & uVar2 & 0x300) != 0)) {
        if ((uVar2 & 3) == param_2) {
          *puVar7 = (ushort)param_3 | uVar2 & 0xfffc;
        }
        if ((uVar2 & 3) == param_3) {
          *puVar7 = (ushort)param_2 | *puVar7 & 0xfffc;
        }
      }
      bVar1 = iVar6 != 2;
      puVar7 = puVar7 + 2;
      iVar6 = iVar6 + 1;
    } while (bVar1);
    bVar1 = iVar8 != 1;
    iVar5 = iVar5 + 0x40;
    iVar8 = iVar8 + 1;
  } while (bVar1);
  iVar8 = (param_4 * 3 + param_3) * 2 + param_1;
  iVar5 = (param_4 * 3 + param_2) * 2 + param_1;
  uVar3 = *(undefined2 *)(iVar5 + 0x80);
  *(undefined2 *)(iVar5 + 0x80) = *(undefined2 *)(iVar8 + 0x80);
  *(undefined2 *)(iVar8 + 0x80) = uVar3;
  return;
}

/* FUN_000c38a0 @ 0xc38a0 (1208 bytes) */
int FUN_000c38a0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  uint param_2;
  undefined4 param_3;
  int param_4;
  uint param_5;
  uint param_6;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  ushort uVar5;
  bool bVar6;
  undefined4 uVar7;
  short *psVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined4 extraout_r4;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  ushort *puVar16;
  int iVar17;
  ushort *puVar18;
  int iVar19;
  ushort *puVar20;
  ushort *puVar21;
  int iVar22;
  undefined4 auStack_108 [2];
  undefined1 auStack_100 [180];
  
  uVar10 = param_5;
  _memcpy(auStack_100,param_1,0xa0);
  iVar17 = 0;
  uVar13 = 0xffffffff;
  iVar19 = param_1 + 0x10;
  do {
    psVar8 = (short *)(iVar19 + 4);
    iVar15 = 0;
    do {
      if ((*psVar8 == 0) && (psVar8[0x20] == 0)) {
        psVar8[0x36] = -1;
      }
      bVar1 = iVar15 != 2;
      psVar8 = psVar8 + 1;
      iVar15 = iVar15 + 1;
    } while (bVar1);
    bVar1 = iVar17 != 1;
    iVar19 = iVar19 + 6;
    iVar17 = iVar17 + 1;
  } while (bVar1);
  bVar1 = (param_6 & 7) != 0;
  if ((bVar1) && (*(ushort *)(param_1 + 0x80) != param_2)) {
    if ((*(ushort *)(param_1 + 0x82) == 0xffff) || (param_2 == *(ushort *)(param_1 + 0x82))) {
      ((int (*)())FUN_000c37c0)(param_1,0,1,0,uVar10,0xffffffff,3);
    }
    else if ((*(ushort *)(param_1 + 0x84) == 0xffff) || (param_2 == *(ushort *)(param_1 + 0x84))) {
      ((int (*)())FUN_000c37c0)(param_1,0,2,0,uVar10,0xffffffff,3);
    }
  }
  bVar2 = (param_6 >> 3 & 1) == 0;
  if (bVar2) {
    iVar17 = 0;
    goto LAB_000c3a40;
  }
  if (*(ushort *)(param_1 + 0x86) != param_2) {
    if ((*(ushort *)(param_1 + 0x88) == 0xffff) || (param_2 == *(ushort *)(param_1 + 0x88))) {
      iVar17 = 1;
      ((int (*)())FUN_000c37c0)(param_1,0,1,1,uVar10,uVar13,iVar15);
      goto LAB_000c3a40;
    }
    if ((*(ushort *)(param_1 + 0x8a) == 0xffff) || (param_2 == *(ushort *)(param_1 + 0x8a))) {
      iVar17 = 1;
      ((int (*)())FUN_000c37c0)(param_1,0,2,1,uVar10,uVar13,iVar15);
      goto LAB_000c3a40;
    }
  }
  iVar17 = 1;
LAB_000c3a40:
  iVar22 = 0;
  iVar15 = param_1 + 0x10;
  iVar19 = param_1;
  do {
    puVar20 = (ushort *)(iVar19 + 10);
    puVar18 = (ushort *)(iVar15 + 4);
    iVar14 = 0;
    do {
      uVar4 = puVar20[-1];
      puVar16 = (ushort *)(uVar4 & 0x100);
      if ((uVar4 & 0x100) == 0) {
        if ((uVar4 & 0x200) != 0) {
          uVar5 = puVar18[3];
          puVar16 = (ushort *)((int)&MACH_HEADER.magic + 1);
          goto LAB_000c3ab0;
        }
      }
      else {
        uVar5 = *puVar18;
        puVar16 = (ushort *)0x0;
LAB_000c3ab0:
        if ((((uVar4 & 3) < 3) &&
            (iVar12 = (int)puVar16 * 3,
            *(ushort *)((iVar12 + (uVar4 & 3)) * 2 + param_1 + 0x80) == param_2)) &&
           ((*puVar20 & 0x1f & (uint)uVar5 & ~param_5) != 0)) {
          iVar9 = (int)puVar16 * 6 + param_1;
          bVar6 = *(short *)(iVar9 + 0x82) == -1;
          uVar10 = (uint)bVar6;
          puVar16 = (ushort *)(int)(short)(ushort)bVar6;
          if (*(short *)(iVar9 + 0x84) == -1) {
            uVar10 = 2;
            puVar16 = (ushort *)((int)&MACH_HEADER.magic + 2);
          }
          *(short *)((iVar12 + uVar10) * 2 + param_1 + 0x80) = (short)param_2;
          puVar20[-1] = (ushort)puVar16 | puVar20[-1] & 0xfffc;
        }
      }
      bVar6 = iVar14 != 2;
      puVar20 = puVar20 + 2;
      puVar18 = puVar18 + 1;
      iVar14 = iVar14 + 1;
    } while (bVar6);
    bVar6 = iVar22 == 1;
    iVar19 = iVar19 + 0x40;
    iVar15 = iVar15 + 0x40;
    iVar22 = iVar22 + 1;
    if (bVar6) {
      bVar6 = false;
      iVar22 = 0;
      iVar15 = 0x80;
      do {
        puVar20 = (ushort *)(param_1 + iVar15);
        uVar10 = 0;
        do {
          uVar7 = _UNK_001aa7f8;
          uVar13 = _UNK_001aa7f4;
          if (*puVar20 == param_2) {
            iVar14 = 0;
            iVar19 = param_1;
            do {
              puVar21 = (ushort *)(iVar19 + 8);
              iVar12 = 0;
              do {
                uVar4 = *puVar21;
                puVar18 = (ushort *)(uint)uVar4;
                auStack_108[0] = uVar13;
                auStack_108[1] = uVar7;
                puVar16 = (ushort *)auStack_108[iVar22];
                if ((uVar4 & 3) == uVar10) {
                  if (((uint)puVar16 & uVar4 & 0x300) != 0) {
                    uVar5 = puVar21[1];
                    uVar11 = (uint)uVar5;
                    puVar16 = puVar21 + 1;
                    if ((uVar5 & param_5) != 0) {
                      if ((uVar5 & 0x2000) == 0) {
                        uVar11 = uVar5 ^ 0x1000;
                        puVar21[1] = (ushort)uVar11;
                      }
                      puVar18 = (ushort *)(uVar4 & 0xfffffffc | 3);
                      *puVar21 = (ushort)puVar18;
                      if ((param_4 != 7) || ((1 < (uVar11 & 0x1f) - 1 && ((uVar11 & 0x1f) != 4)))) {
                        puVar21[1] = (ushort)uVar11 | (ushort)param_6;
                      }
                      if ((param_6 & 1) == 0) {
                        *puVar16 = *puVar16 & 0xfffe;
                      }
                      if ((param_6 & 2) == 0) {
                        *puVar16 = *puVar16 & 0xfffd;
                      }
                      if ((param_6 & 4) == 0) {
                        *puVar16 = *puVar16 & 0xfffb;
                      }
                      if (bVar2) {
                        *puVar16 = *puVar16 & 0xfff7;
                      }
                      bVar6 = true;
                      *puVar21 = uVar4 & 0xfcfc | 3 | (ushort)auStack_108[iVar17];
                    }
                  }
                }
                bVar3 = iVar12 != 2;
                puVar21 = puVar21 + 2;
                iVar12 = iVar12 + 1;
              } while (bVar3);
              bVar3 = iVar14 != 1;
              iVar19 = iVar19 + 0x40;
              iVar14 = iVar14 + 1;
            } while (bVar3);
          }
          uVar13 = 3;
          bVar3 = uVar10 != 2;
          puVar20 = puVar20 + 1;
          uVar10 = uVar10 + 1;
        } while (bVar3);
        bVar3 = iVar22 != 1;
        iVar15 = iVar15 + 6;
        iVar22 = iVar22 + 1;
      } while (bVar3);
      if (bVar6) {
        if (bVar1) {
          *(undefined2 *)(param_1 + 0x80) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
        }
        if (!bVar2) {
          *(undefined2 *)(param_1 + 0x86) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
        }
        ((int (*)())FUN_000c0880)(param_1);
        ((int (*)())FUN_000c0fd0)(param_1,extraout_r4,iVar19,uVar10,puVar20,uVar13,puVar16,puVar18);
      }
      else {
        _memcpy(param_1,auStack_100,0xa0);
      }
      return 1;
    }
  } while( true );
}

/* FUN_000c3d60 @ 0xc3d60 (232 bytes) */
int FUN_000c3d60(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
{
  uint uVar1;
  
  if ((int)(param_4 - 0x20) < 0) {
    uVar1 = (param_2 << 1) << (0x1f - param_4 & 0x3f) | param_3 >> (param_4 & 0x3f);
  }
  else {
    uVar1 = param_2 >> (param_4 - 0x20 & 0x3f);
  }
  if ((uVar1 & 1) != 0) {
    if (((param_5 & 1) == 0) || (*(float *)(param_1 + param_4 * 0x10) == FLOAT_001aa108)) {
      if (((param_5 & 2) == 0) || (*(float *)(param_4 * 0x10 + param_1 + 4) == FLOAT_001aa108)) {
        if (((param_5 & 4) == 0) || (*(float *)(param_4 * 0x10 + param_1 + 8) == FLOAT_001aa108)) {
          if (((param_5 & 8) == 0) || (*(float *)(param_4 * 0x10 + param_1 + 0xc) == FLOAT_001aa108)
             ) {
            if ((param_5 & 0xfffffff0) == 0) {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_000c3e50 @ 0xc3e50 (376 bytes) */
int FUN_000c3e50(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint param_7;
{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  ushort *puVar16;
  
  iVar14 = param_3 + -1;
  iVar9 = *(int *)(param_1 + 8);
  iVar15 = param_3 * 0xa0 + iVar9;
  uVar2 = *(ushort *)(iVar15 + 4);
  uVar3 = *(ushort *)(iVar15 + 6);
  uVar4 = *(ushort *)(iVar15 + 0x44);
  uVar5 = *(ushort *)(iVar15 + 0x46);
  if (iVar14 < param_2) {
LAB_000c3fb0:
    uVar12 = 0;
  }
  else {
    iVar7 = param_4 * 0x40;
    iVar13 = iVar14 * 0xa0;
    while( true ) {
      iVar9 = iVar13 + iVar9;
      iVar10 = ((int (*)())FUN_000c3600)(iVar9,(uint)uVar2,(uint)uVar3,param_4);
      if ((((iVar10 != 0) ||
           (iVar10 = ((int (*)())FUN_000c3600)(iVar9,(uint)uVar4,(uint)uVar5,param_4), iVar10 != 0)) ||
          (iVar10 = ((int (*)())FUN_000c36f0)(iVar9,(uint)uVar2,(uint)uVar3,param_4,param_5,param_6,param_7),
          iVar10 != 0)) ||
         (iVar10 = ((int (*)())FUN_000c36f0)(iVar9,(uint)uVar4,(uint)uVar5,param_4,param_5,param_6,param_7),
         iVar10 != 0)) break;
      puVar16 = (ushort *)(iVar15 + iVar7 + 8);
      iVar10 = 0;
      do {
        uVar6 = *puVar16;
        uVar8 = uVar6 & 3;
        if (uVar8 == 3) goto LAB_000c3fa8;
        param_7 = uVar6 & 0x100;
        if ((uVar6 & 0x100) != 0) {
          iVar11 = ((int (*)())FUN_000c36f0)(iVar9,(uint)*(ushort *)(uVar8 * 2 + iVar15 + 0x80),7,param_4,param_5
                                ,param_6,param_7);
          if (iVar11 != 0) goto LAB_000c3fa8;
          uVar6 = *puVar16;
        }
        if (((uVar6 & 0x200) != 0) &&
           (iVar11 = ((int (*)())FUN_000c36f0)(iVar9,(uint)*(ushort *)(uVar8 * 2 + iVar15 + 0x86),8,param_4,
                                  param_5,param_6,param_7), iVar11 != 0)) goto LAB_000c3fa8;
        bVar1 = iVar10 != 2;
        puVar16 = puVar16 + 2;
        iVar10 = iVar10 + 1;
      } while (bVar1);
      iVar14 = iVar14 + -1;
      iVar13 = iVar13 + -0xa0;
      if (iVar14 < param_2) goto LAB_000c3fb0;
      iVar9 = *(int *)(param_1 + 8);
    }
LAB_000c3fa8:
    uVar12 = 1;
  }
  return uVar12;
}

/* FUN_000c3fd0 @ 0xc3fd0 (784 bytes) */
int FUN_000c3fd0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  bool bVar1;
  ushort uVar2;
  undefined2 uVar3;
  int iVar4;
  short *psVar5;
  uint uVar6;
  undefined2 *puVar7;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined2 *puVar14;
  int iVar15;
  ushort *puVar16;
  
  if ((*(int *)(param_1 + 0x8c) == 2) && (*(int *)(param_2 + 0x8c) == 2)) {
    iVar4 = param_1;
    iVar12 = param_2;
    if (param_3 != 0) {
      iVar4 = param_2;
      iVar12 = param_1;
    }
    iVar13 = 0;
    iVar10 = 0;
    iVar15 = 0;
    do {
      if ((*(ushort *)(iVar12 + 8) & 0x200) != 0) {
        iVar13 = iVar13 + 1;
      }
      if ((*(ushort *)(iVar12 + 8) & 0x100) != 0) {
        iVar10 = iVar10 + 1;
      }
      uVar2 = *(ushort *)(iVar4 + 0x48);
      if ((uVar2 & 0x200) != 0) {
        iVar13 = iVar13 + 1;
      }
      uVar9 = uVar2 & 0x100;
      if ((uVar2 & 0x100) != 0) {
        iVar10 = iVar10 + 1;
      }
      bVar1 = iVar15 != 2;
      iVar12 = iVar12 + 4;
      iVar4 = iVar4 + 4;
      iVar15 = iVar15 + 1;
    } while (bVar1);
    if ((iVar13 < 4) && (iVar10 < 4)) {
      iVar4 = 0;
      puVar14 = (undefined2 *)(param_1 + 0x10);
      do {
        psVar5 = puVar14 + 2;
        iVar12 = 0;
        do {
          if ((*psVar5 == 0) && (psVar5[0x20] == 0)) {
            psVar5[0x36] = -1;
          }
          bVar1 = iVar12 != 2;
          psVar5 = psVar5 + 1;
          iVar12 = iVar12 + 1;
        } while (bVar1);
        bVar1 = iVar4 != 1;
        puVar14 = puVar14 + 3;
        iVar4 = iVar4 + 1;
      } while (bVar1);
      iVar4 = (uint)(param_3 != 0) * 0x40;
      iVar10 = 0;
      iVar12 = iVar4 + 0x16;
      puVar16 = (ushort *)(param_2 + iVar4 + 8);
      iVar13 = param_1 + iVar12;
      uVar11 = 2;
      do {
        uVar6 = (uint)*puVar16;
        if ((*puVar16 & 0x100) != 0) {
          puVar14 = (undefined2 *)(param_1 + iVar4 + 0x14);
          uVar11 = 0;
          param_4 = 0xffff;
          iVar12 = param_1;
          do {
            uVar9 = 0;
            if (*(short *)(iVar12 + 0x80) == -1) {
              if ((uVar6 & 3) == 3) {
                return 0;
              }
              uVar9 = 1;
              *(undefined2 *)(iVar12 + 0x80) = *(undefined2 *)((uVar6 & 3) * 2 + param_2 + 0x80);
              *puVar14 = 7;
              uVar6 = *puVar16 & 0xfffc | uVar11;
              *puVar16 = (ushort)uVar6;
            }
            bVar1 = uVar11 == 2;
            uVar11 = uVar11 + 1;
            if (bVar1) {
              if (uVar9 == 0) {
                return 0;
              }
              break;
            }
            iVar12 = iVar12 + 2;
            puVar14 = puVar14 + 1;
          } while (uVar9 == 0);
        }
        if ((uVar6 & 0x200) != 0) {
          puVar14 = (undefined2 *)(iVar13 + 4);
          uVar11 = 0;
          param_4 = 0xffff;
          iVar12 = param_1;
          do {
            uVar9 = 0;
            if (*(short *)(iVar12 + 0x86) == -1) {
              if ((uVar6 & 3) == 3) {
                return 0;
              }
              uVar9 = 1;
              *(undefined2 *)(iVar12 + 0x86) = *(undefined2 *)((uVar6 & 3) * 2 + param_2 + 0x86);
              *puVar14 = 8;
              uVar6 = *puVar16 & 0xfffc | uVar11;
              *puVar16 = (ushort)uVar6;
            }
            bVar1 = uVar11 == 2;
            uVar11 = uVar11 + 1;
            if (bVar1) {
              if (uVar9 == 0) {
                return 0;
              }
              break;
            }
            iVar12 = iVar12 + 2;
            puVar14 = puVar14 + 1;
          } while (uVar9 == 0);
        }
        bVar1 = iVar10 == 2;
        puVar16 = puVar16 + 2;
        iVar10 = iVar10 + 1;
        if (bVar1) {
          iVar13 = iVar4 + param_1;
          iVar4 = iVar4 + param_2;
          uVar8 = 0x40;
          uVar3 = *(undefined2 *)(iVar13 + 0x2a);
          _memcpy(iVar13,iVar4,0x40);
          puVar7 = (undefined2 *)(iVar4 + 8);
          iVar10 = 0;
          *(undefined2 *)(iVar4 + 6) = 0;
          *(undefined2 *)(iVar4 + 2) = 0;
          *(undefined2 *)(iVar13 + 0x2a) = uVar3;
          do {
            bVar1 = iVar10 != 2;
            *puVar7 = 0;
            puVar7[1] = 0;
            iVar10 = iVar10 + 1;
            puVar7 = puVar7 + 2;
          } while (bVar1);
          ((int (*)())FUN_000c0880)(param_1);
          ((int (*)())FUN_000c0fd0)(param_1,extraout_r4,uVar8,param_4,uVar9,uVar11,iVar12,puVar14);
          ((int (*)())FUN_000c0880)(param_2);
          ((int (*)())FUN_000c0fd0)(param_2,extraout_r4_00,uVar8,param_4,uVar9,uVar11,iVar12,puVar14);
          return 1;
        }
      } while( true );
    }
  }
  return 0;
}

/* FUN_000c42f0 @ 0xc42f0 (2444 bytes) */
int FUN_000c42f0(param_1, param_2)
  uint *param_1;
  uint *param_2;
{
  bool bVar1;
  byte bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  ushort uVar6;
  undefined4 extraout_r4;
  uint *puVar7;
  byte *pbVar8;
  ushort *puVar9;
  char *pcVar10;
  ushort *puVar11;
  byte *pbVar12;
  int iVar13;
  ushort *puVar14;
  uint *puVar15;
  uint *puVar16;
  ushort *puVar17;
  byte *pbVar18;
  byte *pbVar19;
  uint *puVar20;
  byte *pbVar21;
  byte *pbVar22;
  ushort *puVar23;
  byte *pbVar24;
  uint *puVar25;
  byte *pbVar26;
  byte *pbVar27;
  byte *pbVar28;
  ushort *puVar29;
  uint uVar30;
  uint *puStack00000018;
  byte *pbStack_e8;
  byte *pbStack_e4;
  byte *pbStack_e0;
  byte *pbStack_dc;
  uint *puStack_d8;
  ushort *puStack_d4;
  ushort *puStack_d0;
  uint *puStack_cc;
  ushort *puStack_c8;
  byte *pbStack_c4;
  byte *pbStack_c0;
  uint *puStack_bc;
  uint *puStack_b8;
  char *pcStack_b4;
  uint *puStack_b0;
  uint *puStack_ac;
  uint *puStack_a8;
  byte *pbStack_a4;
  char *pcStack_a0;
  byte *pbStack_9c;
  char *pcStack_98;
  char *pcStack_94;
  byte *pbStack_90;
  byte *pbStack_8c;
  byte *pbStack_88;
  byte *pbStack_84;
  ushort *puStack_80;
  char *pcStack_7c;
  uint *puStack_78;
  uint *puStack_74;
  uint *puStack_70;
  byte *pbStack_6c;
  byte *pbStack_68;
  uint uStack_64;
  int iStack_5c;
  
  *(undefined1 *)(param_1 + 4) = *(undefined1 *)(param_2 + 3);
  *(undefined1 *)((int)param_1 + 0x11) = *(undefined1 *)((int)param_2 + 0xd);
  if (*param_1 != 0) {
    puVar16 = param_2 + 0x15;
    puVar9 = (ushort *)((int)param_2 + 0x56);
    pbStack_e8 = (byte *)((int)param_2 + 0x67);
    pbStack_68 = (byte *)((int)param_2 + 0x61);
    pbStack_6c = (byte *)((int)param_2 + 0x89);
    puStack_70 = param_2 + 0x13;
    puStack_74 = param_2 + 0x14;
    pcStack_7c = (char *)((int)param_2 + 0x51);
    puStack_80 = (ushort *)((int)param_2 + 0x4e);
    pbStack_84 = (byte *)((int)param_2 + 0x52);
    pbStack_88 = (byte *)((int)param_2 + 0x55);
    pbStack_8c = (byte *)((int)param_2 + 0x53);
    pbStack_90 = (byte *)((int)param_2 + 0x87);
    pcStack_94 = (char *)((int)param_2 + 0x8a);
    pcStack_98 = (char *)((int)param_2 + 0x6b);
    pbStack_9c = (byte *)((int)param_2 + 0x6a);
    pcStack_a0 = (char *)((int)param_2 + 0x69);
    pbStack_a4 = (byte *)((int)param_2 + 0x7a);
    puStack_a8 = param_2 + 0x18;
    puStack_ac = param_2 + 0x1a;
    puStack_b0 = param_2 + 0x1e;
    pcStack_b4 = (char *)((int)param_2 + 0x7b);
    puStack_bc = param_2 + 0x17;
    pbStack_c0 = (byte *)((int)param_2 + 0x5e);
    pbStack_c4 = (byte *)((int)param_2 + 0x5d);
    puStack_cc = param_2 + 0x16;
    puStack_d0 = (ushort *)((int)param_2 + 0x5a);
    puVar23 = (ushort *)((int)param_2 + 0x62);
    puStack_d8 = param_2 + 0x1d;
    pbStack_dc = (byte *)((int)param_2 + 0x77);
    pbStack_e0 = (byte *)((int)param_2 + 0x83);
    puVar20 = param_2 + 0x22;
    pbVar28 = (byte *)((int)param_2 + 0x79);
    puVar15 = param_2 + 0x19;
    puVar17 = (ushort *)((int)param_2 + 0x66);
    pbVar26 = (byte *)((int)param_2 + 0x72);
    pbVar27 = (byte *)((int)param_2 + 0x75);
    pbVar18 = (byte *)((int)param_2 + 0x73);
    pbVar21 = (byte *)((int)param_2 + 0x76);
    pbVar24 = (byte *)((int)param_2 + 0x81);
    puVar25 = param_2 + 0x21;
    pbVar19 = (byte *)((int)param_2 + 0x82);
    pbVar22 = (byte *)((int)param_2 + 0x85);
    pbStack_e4 = (byte *)((int)param_2 + 0x86);
    uStack_64 = 0;
    iStack_5c = 0;
    puStack00000018 = param_1;
    puStack_d4 = puVar23;
    puStack_c8 = puVar9;
    puStack_b8 = puVar16;
    puStack_78 = puVar16;
    do {
      param_2 = param_2 + 0x12;
      puVar29 = (ushort *)(iStack_5c + puStack00000018[2]);
      _memset(puVar29,0,0x80);
      puVar29[0x40] = 0;
      puVar29[0x41] = 0;
      puVar29[0x44] = 0;
      puVar29[0x45] = 0;
      puVar29[0x42] = 0;
      puVar29[0x43] = 0;
      uVar4 = *param_2;
      if (uVar4 == 2) {
        puVar29[0x48] = 0;
        puVar29[0x49] = 0;
        puVar29[0x4a] = 0;
        puVar29[0x4b] = 0;
        puVar29[0x46] = 0;
        puVar29[0x47] = 1;
        bVar2 = *(byte *)puVar23;
        uVar6 = (ushort)bVar2;
        if (bVar2 == 2) {
          puVar29[10] = 0xf;
          uVar6 = *puVar9;
          puVar29[0x1d] = 1;
          puVar29[0x18] = 0;
          puVar29[0x19] = 1;
          puVar29[0x40] = uVar6;
          uVar6 = (ushort)*(byte *)puVar23;
        }
        else if (bVar2 < 3) {
          if (bVar2 == 1) {
LAB_000c46e8:
            puVar29[3] = 0xf;
            puVar29[2] = *(ushort *)puVar16;
            puVar29[10] = ~(ushort)*pbStack_e8 & 0xf;
            puVar29[0x40] = *puVar9;
            uVar6 = (ushort)*(byte *)puVar23;
          }
        }
        else if (bVar2 < 5) goto LAB_000c46e8;
        bVar2 = *pbStack_68;
        puVar29[0x16] = 0x3f80;
        puVar29[0x17] = 0;
        puVar29[0x14] = (ushort)bVar2 << 8 | uVar6;
      }
      else if (uVar4 < 3) {
        if (uVar4 == 1) {
          puVar29[0x46] = 0;
          puVar29[0x47] = 0;
          puVar29[0x48] = 0;
          puVar29[0x49] = 0;
          puVar29[0x4a] = 0;
          puVar29[0x4b] = 0;
          if (*pbStack_8c == 0) {
            puVar29[0x16] = 0x3f80;
            puVar29[0x17] = 0;
          }
          else {
            puVar29[3] = 0xf;
            uVar6 = *puStack_80;
            puVar29[10] = 0xf;
            puVar29[2] = uVar6;
            puVar29[0x40] = *pbStack_84 | 0xc000;
            *(undefined4 *)(puVar29 + 0x16) = *(undefined4 *)((uint)*pbStack_88 * 4 + 0x1dc198);
            bVar2 = *pbStack_8c;
            if ((bVar2 == 2) || (bVar2 == 3)) {
              puVar29[0x1d] = (ushort)bVar2;
            }
          }
          if (*pcStack_7c == '\0') {
            puVar29[0x36] = 0x3f80;
            puVar29[0x37] = 0;
          }
          else {
            puVar29[0x23] = 0xf;
            uVar6 = *(ushort *)puStack_70;
            puVar29[0x2d] = 0xf;
            puVar29[0x22] = uVar6;
            puVar29[0x43] = *(byte *)puStack_74 | 0xa000;
            *(undefined4 *)(puVar29 + 0x36) =
                 *(undefined4 *)((uint)*(byte *)puStack_78 * 4 + 0x1dc198);
          }
        }
      }
      else if (uVar4 < 5) {
        puVar29[0x48] = 0;
        puVar29[0x49] = 0;
        puVar29[0x4a] = 0;
        puVar29[0x4b] = 0;
        puVar29[0x46] = 0;
        puVar29[0x47] = 2;
        iVar13 = 0;
        puVar29[0x40] = *puStack_c8;
        puVar29[0x41] = *(ushort *)puStack_cc;
        puVar29[0x42] = *puStack_d0;
        puVar29[0x43] = *puStack_d4;
        puVar29[0x44] = *(ushort *)puVar15;
        puVar29[0x45] = *puVar17;
        puVar11 = puVar29;
        puVar14 = puVar29;
        do {
          puVar14[0x3a] = 1;
          puVar14[0x1a] = 1;
          uVar3 = (*(unsigned int *)0x001dbf94);
          bVar1 = iVar13 != 2;
          puVar14 = puVar14 + 1;
          iVar13 = iVar13 + 1;
          *(undefined4 *)(puVar11 + 4) = (*(unsigned int *)0x001dbf94);
          *(undefined4 *)(puVar11 + 0x24) = uVar3;
          puVar11 = puVar11 + 2;
        } while (bVar1);
        puVar29[2] = *(ushort *)puStack_b8;
        puVar29[3] = (ushort)*(byte *)puStack_bc;
        *puVar29 = (ushort)*pbStack_c0;
        puVar29[1] = (ushort)*pbStack_c4;
        puVar29[0x14] = *(ushort *)((uint)*pbVar28 * 4 + 0x1dc158);
        uVar4 = (uint)*(ushort *)((uint)*pbVar28 * 4 + 0x1dc15a);
        if (uVar4 != 0) {
LAB_000c4830:
          uVar5 = (uint)*pbVar26;
          uVar6 = (ushort)*pbVar27;
          iVar13 = 0;
          puVar11 = puVar29 + 4;
          uVar30 = uVar4;
          if (uVar4 == 0) {
            uVar30 = 1;
          }
          do {
            iVar13 = iVar13 + 1;
            *(undefined4 *)puVar11 = *(undefined4 *)(uVar5 * 4 + 0x1dc0d8);
            puVar11[1] = uVar6 << 0xc | puVar11[1];
            uVar30 = uVar30 - 1;
            if (uVar30 == 0) goto LAB_000c48b4;
            if (iVar13 == 1) {
              uVar5 = (uint)*pbVar18;
              uVar6 = (ushort)*pbVar21;
            }
            else {
              if (iVar13 == 0) goto LAB_000c4830;
              if (iVar13 == 2) {
                uVar5 = (uint)*(byte *)puStack_d8;
                uVar6 = (ushort)*pbStack_dc;
              }
              else {
                uVar5 = 0;
                uVar6 = 0;
              }
            }
            puVar11 = puVar11 + 2;
          } while( true );
        }
        iVar13 = 3;
LAB_000c48b4:
        puVar29[0x15] = (ushort)*(byte *)puStack_b0;
        if (*pcStack_b4 == '\x01') {
          *(uint *)(puVar29 + 0x18) = *(uint *)(puVar29 + 0x18) | 8;
        }
        puVar11 = puVar29 + 0x20;
        *(undefined4 *)(puVar29 + 0x16) = *(undefined4 *)((uint)*pbStack_a4 * 4 + 0x1dc198);
        puVar29[0x22] = *(ushort *)puStack_a8;
        if (*(char *)puStack_ac != '\0') {
          puVar29[0x23] = 8;
        }
        puVar29[0x20] = (ushort)*pbStack_9c;
        if (*pcStack_a0 != '\0') {
          puVar29[0x21] = 8;
        }
        if (*pcStack_98 != '\0') {
          puVar29[0x21] = puVar29[0x21] | 0x10;
        }
        puVar29[0x34] = *(ushort *)((uint)*(byte *)puVar20 * 4 + 0x1dc098);
        uVar4 = (uint)*(ushort *)((uint)*(byte *)puVar20 * 4 + 0x1dc09a);
        if (*pbVar28 == 2) {
          if (uVar4 < 2) {
            uVar4 = 2;
          }
LAB_000c49a8:
LAB_000c49b0:
          uVar5 = (uint)*pbVar24;
          uVar6 = (ushort)*(byte *)puVar25;
          iVar13 = 0;
          puVar14 = puVar29 + 0x24;
          uVar30 = uVar4;
          if (uVar4 == 0) {
            uVar30 = 1;
          }
          do {
            iVar13 = iVar13 + 1;
            *(undefined4 *)puVar14 = *(undefined4 *)(uVar5 * 4 + 0x1dc04c);
            puVar14[1] = uVar6 << 0xc | puVar14[1];
            uVar30 = uVar30 - 1;
            puVar7 = (uint *)0x1dc04c;
            if (uVar30 == 0) goto LAB_000c4a74;
            if (iVar13 == 1) {
              uVar5 = (uint)*pbVar19;
              uVar6 = (ushort)*pbVar22;
            }
            else {
              if (iVar13 == 0) goto LAB_000c49b0;
              if (iVar13 == 2) {
                uVar5 = (uint)*pbStack_e0;
                uVar6 = (ushort)*pbStack_e4;
              }
              else {
                uVar5 = 0;
                uVar6 = 0;
              }
            }
            puVar14 = puVar14 + 2;
          } while( true );
        }
        puVar7 = puStack_ac;
        if (uVar4 != 0) goto LAB_000c49a8;
LAB_000c4a74:
        puVar29[0x35] = (ushort)*pbStack_90;
        if (*pcStack_94 == '\x01') {
          *(uint *)(puVar29 + 0x38) = *(uint *)(puVar29 + 0x38) | 8;
        }
        *(undefined4 *)(puVar29 + 0x36) = *(undefined4 *)((uint)*pbStack_6c * 4 + 0x1dc198);
        pbVar8 = pbStack_90;
        pcVar10 = pcStack_94;
        pbVar12 = pbStack_6c;
        ((int (*)())FUN_000c0880)(puVar29);
        ((int (*)())FUN_000c0fd0)(puVar29,extraout_r4,puVar7,pbVar8,pcVar10,puVar11,pbVar12,iVar13);
      }
      puVar23 = puVar23 + 0x24;
      puVar20 = puVar20 + 0x12;
      pbVar28 = pbVar28 + 0x48;
      puVar15 = puVar15 + 0x12;
      puVar17 = puVar17 + 0x24;
      pbVar26 = pbVar26 + 0x48;
      pbVar27 = pbVar27 + 0x48;
      uStack_64 = uStack_64 + 1;
      pbVar18 = pbVar18 + 0x48;
      iStack_5c = iStack_5c + 0xa0;
      pbStack_68 = pbStack_68 + 0x48;
      pbStack_6c = pbStack_6c + 0x48;
      puStack_70 = puStack_70 + 0x12;
      pbVar21 = pbVar21 + 0x48;
      puStack_74 = puStack_74 + 0x12;
      pbVar24 = pbVar24 + 0x48;
      puVar25 = puVar25 + 0x12;
      pcStack_7c = pcStack_7c + 0x48;
      puStack_80 = puStack_80 + 0x24;
      pbStack_84 = pbStack_84 + 0x48;
      puStack_78 = puStack_78 + 0x12;
      pbStack_88 = pbStack_88 + 0x48;
      pbStack_8c = pbStack_8c + 0x48;
      pcStack_94 = pcStack_94 + 0x48;
      pbVar19 = pbVar19 + 0x48;
      pbVar22 = pbVar22 + 0x48;
      pcStack_98 = pcStack_98 + 0x48;
      pbStack_90 = pbStack_90 + 0x48;
      pbStack_9c = pbStack_9c + 0x48;
      puVar16 = puVar16 + 0x12;
      puVar9 = puVar9 + 0x24;
      pcStack_a0 = pcStack_a0 + 0x48;
      pbStack_a4 = pbStack_a4 + 0x48;
      puStack_a8 = puStack_a8 + 0x12;
      puStack_ac = puStack_ac + 0x12;
      puStack_b0 = puStack_b0 + 0x12;
      pcStack_b4 = pcStack_b4 + 0x48;
      puStack_b8 = puStack_b8 + 0x12;
      puStack_bc = puStack_bc + 0x12;
      pbStack_c0 = pbStack_c0 + 0x48;
      pbStack_c4 = pbStack_c4 + 0x48;
      puStack_c8 = puStack_c8 + 0x24;
      puStack_cc = puStack_cc + 0x12;
      puStack_d0 = puStack_d0 + 0x24;
      puStack_d4 = puStack_d4 + 0x24;
      puStack_d8 = puStack_d8 + 0x12;
      pbStack_dc = pbStack_dc + 0x48;
      pbStack_e0 = pbStack_e0 + 0x48;
      pbStack_e4 = pbStack_e4 + 0x48;
      pbStack_e8 = pbStack_e8 + 0x48;
    } while (uStack_64 < *puStack00000018);
  }
  return;
}

/* FUN_000c4ce0 @ 0xc4ce0 (1484 bytes) */
int FUN_000c4ce0(param_1, param_2, param_3)
  uint *param_1;
  undefined4 *param_2;
  uint *param_3;
{
  bool bVar1;
  byte bVar2;
  float fVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  ushort uVar6;
  float fVar7;
  int iVar8;
  short sVar9;
  undefined1 uVar12;
  short sVar11;
  uint uVar10;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  undefined1 uVar19;
  undefined4 uVar20;
  uint uVar21;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined4 *puVar24;
  undefined1 uStack_31;
  
  uVar20 = param_2[1];
  _memset(param_2,0,0x48);
  param_2[1] = uVar20;
  param_2[2] = *param_1;
  *(undefined1 *)(param_2 + 3) = *(undefined1 *)(param_1 + 4);
  *(undefined1 *)((int)param_2 + 0xd) = *(undefined1 *)((int)param_1 + 0x11);
  *param_3 = 0;
  if (*param_1 != 0) {
    uVar22 = 1;
    uVar21 = 0;
    do {
      puVar24 = param_2 + 0x12;
      _memset(puVar24,0,0x48);
      uVar13 = param_1[2];
      iVar17 = uVar21 * 0xa0 + uVar13;
      iVar8 = *(int *)(iVar17 + 0x8c);
      uVar4 = *(undefined2 *)(iVar17 + 4);
      uVar5 = *(undefined2 *)(iVar17 + 0x44);
      if (iVar8 == 1) {
        *(undefined2 *)(param_2 + 0x15) = uVar4;
        *puVar24 = 2;
        *(undefined2 *)((int)param_2 + 0x56) = *(undefined2 *)(iVar17 + 0x80);
        if ((*(short *)(iVar17 + 2) == 0 && *(short *)(iVar17 + 6) == 0) &&
           ((*(uint *)(iVar17 + 0x30) & 1) == 0)) {
          *(undefined1 *)((int)param_2 + 0x61) = 0;
          *(undefined1 *)((int)param_2 + 0x62) = 0;
        }
        else {
          *(char *)((int)param_2 + 0x62) = (char)*(undefined2 *)(iVar17 + 0x28);
          *(char *)((int)param_2 + 0x61) = (char)((ushort)*(undefined2 *)(iVar17 + 0x28) >> 8);
        }
        bVar2 = *(byte *)(iVar17 + 0x15);
        *(undefined1 *)(param_2 + 0x1a) = uVar22;
        uVar22 = 0;
        *(byte *)((int)param_2 + 0x67) = bVar2 ^ 0xf;
      }
      else if (iVar8 == 0) {
        *(undefined2 *)((int)param_2 + 0x4e) = uVar4;
        *(undefined2 *)(param_2 + 0x13) = uVar5;
        *puVar24 = 1;
        if ((*(short *)(iVar17 + 2) == 0 && *(short *)(iVar17 + 6) == 0) &&
           ((*(uint *)(iVar17 + 0x30) & 1) == 0)) {
          *(undefined1 *)((int)param_2 + 0x53) = 0;
        }
        else {
          sVar9 = *(short *)(iVar17 + 0x3a);
          if ((sVar9 == 2) || (sVar9 == 3)) {
            *(char *)((int)param_2 + 0x53) = (char)sVar9;
          }
          else if (sVar9 == 0) {
            *(undefined1 *)((int)param_2 + 0x53) = 1;
          }
        }
        if ((*(short *)(iVar17 + 0x42) != 0 || *(short *)(iVar17 + 0x46) != 0) ||
           (uVar12 = 0, (*(uint *)(iVar17 + 0x70) & 1) != 0)) {
          uVar12 = 1;
        }
        *(undefined1 *)((int)param_2 + 0x51) = uVar12;
        if (*(short *)(iVar17 + 0x80) == -1) {
          *(undefined1 *)((int)param_2 + 0x52) = 0;
        }
        else {
          *(char *)((int)param_2 + 0x52) = (char)*(short *)(iVar17 + 0x80);
        }
        if (*(short *)(iVar17 + 0x86) == -1) {
          *(undefined1 *)(param_2 + 0x14) = 0;
        }
        else {
          *(char *)(param_2 + 0x14) = (char)*(short *)(iVar17 + 0x86);
        }
        fVar7 = FLOAT_001aa0e8;
        *(bool *)((int)param_2 + 0x55) = *(float *)(iVar17 + 0x2c) != FLOAT_001aa0e8;
        fVar3 = *(float *)(iVar17 + 0x6c);
        *(undefined1 *)((int)param_2 + 0x57) = 0;
        *(undefined1 *)((int)param_2 + 0x56) = 0;
        *(bool *)(param_2 + 0x15) = fVar3 != fVar7;
      }
      else if (iVar8 == 2) {
        *(undefined2 *)(param_2 + 0x15) = uVar4;
        *(undefined2 *)(param_2 + 0x18) = uVar5;
        *puVar24 = 3;
        *(char *)((int)param_2 + 0x5d) = (char)*(undefined2 *)(iVar17 + 2);
        *(char *)((int)param_2 + 0x5e) = (char)*(undefined2 *)(uVar21 * 0xa0 + uVar13);
        *(byte *)((int)param_2 + 0x69) = (byte)(*(ushort *)(iVar17 + 0x42) >> 3) & 1;
        uVar6 = *(ushort *)(iVar17 + 0x42) >> 4 & 1;
        *(char *)((int)param_2 + 0x6b) = (char)uVar6;
        if (uVar6 != 0) {
          *param_3 = *param_3 | 1;
        }
        iVar15 = 0;
        *(char *)((int)param_2 + 0x6a) = (char)*(undefined2 *)(iVar17 + 0x40);
        *(char *)(param_2 + 0x17) = (char)*(undefined2 *)(iVar17 + 6);
        *(byte *)(param_2 + 0x1a) = (byte)(*(ushort *)(iVar17 + 0x46) >> 3) & 1;
        iVar8 = iVar17;
        do {
          sVar9 = *(short *)(iVar8 + 0x80);
          sVar11 = *(short *)(iVar8 + 0x86);
          if (sVar9 == -1) {
            sVar9 = -0x8000;
          }
          if (sVar11 == -1) {
            sVar11 = -0x8000;
          }
          if (iVar15 == 1) {
            *(short *)(param_2 + 0x16) = sVar9;
            *(short *)(param_2 + 0x19) = sVar11;
          }
          else if (iVar15 == 0) {
            *(short *)((int)param_2 + 0x56) = sVar9;
            *(short *)((int)param_2 + 0x62) = sVar11;
          }
          else if (iVar15 == 2) {
            *(short *)((int)param_2 + 0x5a) = sVar9;
            *(short *)((int)param_2 + 0x66) = sVar11;
          }
          bVar1 = iVar15 != 2;
          iVar8 = iVar8 + 2;
          iVar15 = iVar15 + 1;
        } while (bVar1);
        iVar8 = 0;
        do {
          uVar22 = 0;
          uVar13 = 0;
          uVar12 = 0;
          uVar18 = 0;
          iVar15 = 0;
          iVar16 = iVar17 + 8;
          do {
            uVar6 = *(ushort *)(iVar8 * 4 + iVar16 + 2);
            uVar14 = *(ushort *)(iVar8 * 4 + iVar16) & 3;
            if (iVar15 == 0) {
              uVar10 = 6;
              if (((uVar6 & 0x300) != 0x100) && (uVar10 = 5, (uVar6 & 0x300) != 0x200)) {
                uVar10 = uVar6 & 0x1f;
              }
              uVar13 = (uVar6 & 0x3000) >> 0xc;
              uVar22 = *(undefined1 *)(uVar10 * 4 + 0x1dc000 + uVar14);
            }
            else if (iVar15 == 1) {
              uVar18 = (uVar6 & 0x3000) >> 0xc;
              uVar12 = *(undefined1 *)((uVar6 & 0x1f) * 4 + 0x1dbfb4 + uVar14);
            }
            bVar1 = iVar15 != 1;
            iVar16 = iVar16 + 0x40;
            iVar15 = iVar15 + 1;
          } while (bVar1);
          uVar23 = (undefined1)uVar13;
          uVar19 = (undefined1)uVar18;
          if (iVar8 == 1) {
            *(undefined1 *)((int)param_2 + 0x73) = uVar22;
            *(undefined1 *)((int)param_2 + 0x76) = uVar23;
            *(undefined1 *)((int)param_2 + 0x82) = uVar12;
            *(undefined1 *)((int)param_2 + 0x85) = uVar19;
          }
          else if (iVar8 == 0) {
            *(undefined1 *)((int)param_2 + 0x72) = uVar22;
            *(undefined1 *)((int)param_2 + 0x75) = uVar23;
            *(undefined1 *)((int)param_2 + 0x81) = uVar12;
            *(undefined1 *)(param_2 + 0x21) = uVar19;
          }
          else if (iVar8 == 2) {
            *(undefined1 *)(param_2 + 0x1d) = uVar22;
            *(undefined1 *)((int)param_2 + 0x77) = uVar23;
            *(undefined1 *)((int)param_2 + 0x83) = uVar12;
            *(undefined1 *)((int)param_2 + 0x86) = uVar19;
          }
          bVar1 = iVar8 != 2;
          iVar8 = iVar8 + 1;
        } while (bVar1);
        iVar15 = 0;
        iVar8 = iVar17;
        do {
          uVar13 = (uint)((double)*(float *)(iVar8 + 0x2c) * DOUBLE_001aa290);
          uStack_31 = (undefined1)uVar13;
          switch(uVar13 & 0xff) {
          case 1:
            uStack_31 = 6;
            break;
          case 2:
            uStack_31 = 5;
            break;
          case 4:
            uStack_31 = 4;
            break;
          case 8:
            uStack_31 = 0;
            break;
          case 0x10:
            uStack_31 = 1;
            break;
          case 0x20:
            uStack_31 = 2;
            break;
          case 0x40:
            uStack_31 = 3;
          }
          if (iVar15 == 0) {
            *(undefined1 *)((int)param_2 + 0x7a) = uStack_31;
            *(byte *)((int)param_2 + 0x7b) = (byte)(*(uint *)(iVar17 + 0x30) >> 3) & 1;
          }
          else if (iVar15 == 1) {
            *(undefined1 *)((int)param_2 + 0x89) = uStack_31;
            *(byte *)((int)param_2 + 0x8a) = (byte)(*(uint *)(iVar17 + 0x70) >> 3) & 1;
          }
          bVar1 = iVar15 != 1;
          iVar8 = iVar8 + 0x40;
          iVar15 = iVar15 + 1;
        } while (bVar1);
        iVar15 = 0;
        iVar8 = iVar17;
        do {
          uVar22 = *(undefined1 *)((uint)*(ushort *)(iVar8 + 0x28) * 2 + 0x1dbf98 + iVar15);
          if (iVar15 == 0) {
            *(undefined1 *)((int)param_2 + 0x79) = uVar22;
            *(char *)(param_2 + 0x1e) = (char)*(undefined2 *)(iVar17 + 0x2a);
          }
          else if (iVar15 == 1) {
            *(undefined1 *)(param_2 + 0x22) = uVar22;
            *(char *)((int)param_2 + 0x87) = (char)*(undefined2 *)(iVar17 + 0x6a);
          }
          bVar1 = iVar15 != 1;
          iVar8 = iVar8 + 0x40;
          iVar15 = iVar15 + 1;
        } while (bVar1);
        uVar22 = 1;
        *(undefined1 *)(param_2 + 0x1f) = 0;
      }
      uVar21 = uVar21 + 1;
      param_2 = puVar24;
    } while (uVar21 < *param_1);
  }
  return;
}

/* FUN_000c5460 @ 0xc5460 (72 bytes) */
int FUN_000c5460(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  uint param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  ushort uVar4;
  
  uVar4 = (ushort)(param_2 & 7);
  if ((param_2 & 7) == 0) {
    return;
  }
  switch(param_1) {
  case 0:
  case 4:
  case 8:
  case 0xf:
    break;
  case 1:
  case 5:
  case 9:
  case 0x10:
    uVar4 = 1;
    break;
  case 2:
  case 6:
  case 10:
  case 0x11:
    uVar4 = 2;
    break;
  case 3:
  case 7:
  case 0xb:
  case 0x12:
    uVar4 = 4;
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x13:
    uVar4 = 8;
    break;
  default:
    uVar4 = 0;
    break;
  case 0x17:
  case 0x18:
  case 0x19:
    uVar4 = (ushort)((param_2 & 3) << 1) | (ushort)(param_2 >> 2) & 1;
    break;
  case 0x1a:
  case 0x1b:
  case 0x1c:
    uVar4 = (ushort)((param_2 & 1) << 2) | (ushort)(param_2 >> 1) & 3;
    break;
  case 0x1d:
  case 0x1e:
  case 0x1f:
    uVar4 = (ushort)((param_2 & 1) << 3) | (ushort)((param_2 & 2) << 1) | (ushort)(param_2 >> 1) & 2
    ;
  }
  switch(param_1) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 0x17:
  case 0x1a:
    *(ushort *)(param_5 + 2) = uVar4 | *(ushort *)(param_5 + 2);
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 0x18:
  case 0x1b:
    *(ushort *)(param_5 + 6) = uVar4 | *(ushort *)(param_5 + 6);
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0x19:
  case 0x1c:
    *(ushort *)(param_5 + 10) = uVar4 | *(ushort *)(param_5 + 10);
    break;
  case 0xc:
    *(ushort *)(param_5 + 0xe) = uVar4 | *(ushort *)(param_5 + 0xe);
    break;
  case 0xd:
    *(ushort *)(param_5 + 0x12) = uVar4 | *(ushort *)(param_5 + 0x12);
    break;
  case 0xe:
    *(ushort *)(param_5 + 0x16) = uVar4 | *(ushort *)(param_5 + 0x16);
    break;
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
    *(ushort *)(param_5 + 2) = uVar4 | *(ushort *)(param_5 + 2);
    *(ushort *)(param_6 + 2) = uVar4 | *(ushort *)(param_6 + 2);
    if (1 < param_3 - 1U) {
      return;
    }
    iVar2 = param_5 + 4;
    iVar3 = param_6 + 4;
    goto code_r0x000c5714;
  case 0x13:
    *(ushort *)(param_5 + 0xe) = uVar4 | *(ushort *)(param_5 + 0xe);
    *(ushort *)(param_6 + 10) = uVar4 | *(ushort *)(param_6 + 10);
    if (1 < param_4 - 1U) {
      return;
    }
    iVar2 = param_5 + 0x10;
    iVar3 = param_6 + 0xc;
code_r0x000c5714:
    *(ushort *)(iVar2 + 2) = uVar4 | *(ushort *)(iVar2 + 2);
    *(ushort *)(iVar3 + 2) = uVar4 | *(ushort *)(iVar3 + 2);
    break;
  case 0x1d:
    *(ushort *)(param_5 + 2) = uVar4 & 7 | *(ushort *)(param_5 + 2);
    *(ushort *)(param_5 + 0xe) = uVar4 & 8 | *(ushort *)(param_5 + 0xe);
    break;
  case 0x1e:
    iVar2 = param_5 + 4;
    iVar3 = param_5 + 0x10;
    uVar1 = *(ushort *)(param_5 + 6);
    goto code_r0x000c5788;
  case 0x1f:
    iVar2 = param_5 + 8;
    iVar3 = param_5 + 0x14;
    uVar1 = *(ushort *)(param_5 + 10);
code_r0x000c5788:
    *(ushort *)(iVar2 + 2) = uVar4 & 7 | uVar1;
    *(ushort *)(iVar3 + 2) = uVar4 & 8 | *(ushort *)(iVar3 + 2);
  }
  return;
}

/* FUN_000c57b0 @ 0xc57b0 (104 bytes) */
int FUN_000c57b0(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  ushort uVar2;
  int iVar3;
  
  if ((param_2 & 8) == 0) {
    return;
  }
  uVar2 = 0;
  switch(param_1) {
  case 0:
  case 3:
  case 6:
  case 0xc:
    uVar2 = 1;
    break;
  case 1:
  case 4:
  case 7:
  case 0xd:
    uVar2 = 2;
    break;
  case 2:
  case 5:
  case 8:
  case 0xe:
    uVar2 = 4;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xf:
    uVar2 = 8;
  }
  switch(param_1) {
  case 0:
  case 1:
  case 2:
    *(ushort *)(param_5 + 2) = uVar2 | *(ushort *)(param_5 + 2);
    break;
  case 3:
  case 4:
  case 5:
    *(ushort *)(param_5 + 6) = uVar2 | *(ushort *)(param_5 + 6);
    break;
  case 6:
  case 7:
  case 8:
    *(ushort *)(param_5 + 10) = uVar2 | *(ushort *)(param_5 + 10);
    break;
  case 9:
    *(ushort *)(param_5 + 0xe) = uVar2 | *(ushort *)(param_5 + 0xe);
    break;
  case 10:
    *(ushort *)(param_5 + 0x12) = uVar2 | *(ushort *)(param_5 + 0x12);
    break;
  case 0xb:
    *(ushort *)(param_5 + 0x16) = uVar2 | *(ushort *)(param_5 + 0x16);
    break;
  case 0xc:
  case 0xd:
  case 0xe:
    *(ushort *)(param_5 + 2) = uVar2 | *(ushort *)(param_5 + 2);
    *(ushort *)(param_6 + 2) = uVar2 | *(ushort *)(param_6 + 2);
    if (1 < (ushort)((*(unsigned short *)((unsigned char *)&(param_3) + 2)) - 1U)) {
      return;
    }
    iVar1 = param_5 + 4;
    iVar3 = param_6 + 4;
    goto code_r0x000c5994;
  case 0xf:
    *(ushort *)(param_5 + 0xe) = uVar2 | *(ushort *)(param_5 + 0xe);
    *(ushort *)(param_6 + 10) = uVar2 | *(ushort *)(param_6 + 10);
    if (1 < (ushort)((*(unsigned short *)((unsigned char *)&(param_4) + 2)) - 1U)) {
      return;
    }
    iVar1 = param_5 + 0x10;
    iVar3 = param_6 + 0xc;
code_r0x000c5994:
    *(ushort *)(iVar1 + 2) = uVar2 | *(ushort *)(iVar1 + 2);
    *(ushort *)(iVar3 + 2) = uVar2 | *(ushort *)(iVar3 + 2);
  }
  return;
}

/* FUN_000c59c0 @ 0xc59c0 (580 bytes) */
int FUN_000c59c0(param_1, param_2, param_3)
  ushort *param_1;
  int *param_2;
  int *param_3;
{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  ushort uVar8;
  int iVar7;
  uint uVar9;
  short sVar10;
  int iVar11;
  uint uVar12;
  
  uVar2 = param_1[1];
  if (uVar2 == 0) {
    *param_1 = 0;
    return;
  }
  uVar1 = (uint)*param_1;
  if (uVar1 < *(ushort *)(param_2 + 2)) {
    iVar6 = param_2[1];
    uVar8 = (uVar2 == 8) + 7;
  }
  else {
    iVar6 = *param_2;
    uVar8 = 0xf;
    uVar1 = uVar1 - *(ushort *)(param_2 + 2) & 0xffff;
  }
  iVar11 = iVar6 + uVar1 * 8;
  uVar2 = uVar2 & *(ushort *)(iVar11 + 4);
  param_1[1] = uVar2;
  if (uVar2 == 0) {
    *param_1 = 0;
    return;
  }
  if (uVar8 == 8) {
    uVar2 = *(ushort *)(iVar11 + 2);
  }
  else {
    uVar2 = *(ushort *)(iVar6 + uVar1 * 8);
  }
  *param_1 = uVar2;
  uVar3 = *(ushort *)(iVar11 + 4) & ~param_1[1];
  *(ushort *)(iVar11 + 4) = uVar3;
  uVar9 = (uint)*(ushort *)(param_3 + 1);
  uVar2 = *param_1;
  uVar1 = uVar9 - 1;
  if ((uVar8 & uVar3) != 0) {
    return;
  }
  if (uVar1 == 0) {
    iVar11 = *param_3;
    iVar6 = 0;
    uVar1 = 0;
  }
  else {
    iVar11 = *param_3;
    iVar6 = uVar1 * 4;
    if (uVar2 <= *(ushort *)(iVar6 + iVar11 + -4)) {
      puVar5 = (ushort *)(iVar6 + iVar11 + -8);
      uVar12 = uVar1;
      do {
        iVar6 = iVar6 + -4;
        uVar1 = uVar1 - 1;
        uVar12 = uVar12 - 1;
        if (uVar12 == 0) {
          iVar6 = uVar1 * 4;
          break;
        }
        uVar3 = *puVar5;
        puVar5 = puVar5 + -2;
      } while (uVar2 <= uVar3);
    }
  }
  if (*(ushort *)(iVar6 + iVar11) == uVar2) {
    *(ushort *)(iVar6 + iVar11 + 2) = uVar8 | *(ushort *)(iVar6 + iVar11 + 2);
    uVar2 = *(ushort *)(param_3 + 1);
  }
  else {
    if (uVar1 < uVar9) {
      iVar4 = uVar9 - uVar1;
      iVar7 = uVar9 << 2;
      if (uVar9 - 1 < uVar1) {
        iVar4 = 1;
      }
      while( true ) {
        *(undefined4 *)(iVar7 + iVar11) = *(undefined4 *)(iVar7 + iVar11 + -4);
        iVar7 = iVar7 + -4;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) break;
        iVar11 = *param_3;
      }
      iVar11 = *param_3;
    }
    *(ushort *)(iVar6 + iVar11) = uVar2;
    *(ushort *)(iVar6 + *param_3 + 2) = uVar8;
    uVar2 = *(short *)(param_3 + 1) + 1;
    *(ushort *)(param_3 + 1) = uVar2;
  }
  uVar1 = (uint)uVar2;
  iVar6 = *param_3;
  if (uVar1 - 1 == 0) {
    return;
  }
  iVar11 = (uVar1 - 2) * 4;
  sVar10 = *(short *)((uVar1 - 1) * 4 + iVar6) + -1;
  if (*(short *)(iVar6 + iVar11) != sVar10) {
    return;
  }
  if (*(short *)(iVar6 + iVar11 + 2) == 0xf) {
    iVar7 = uVar1 - 1;
    while( true ) {
      iVar11 = iVar11 + -4;
      uVar2 = uVar2 - 1;
      *(ushort *)(param_3 + 1) = uVar2;
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) {
        return;
      }
      sVar10 = sVar10 + -1;
      if (*(short *)(iVar11 + iVar6) != sVar10) break;
      if (*(short *)(iVar11 + iVar6 + 2) != 0xf) {
        return;
      }
    }
    return;
  }
  return;
}

/* FUN_000c5c50 @ 0xc5c50 (476 bytes) */
int FUN_000c5c50(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  ushort *param_1;
  int *param_2;
  int *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  ushort uVar9;
  int iVar8;
  ushort *puVar10;
  
  uVar3 = (uint)*param_1;
  if ((*param_1 & 0x8000) == 0) {
    uVar9 = param_1[1];
    uVar2 = 0;
    if (uVar9 != 0) {
      if (uVar3 < *(ushort *)(param_2 + 2)) {
        iVar5 = param_2[1];
        uVar2 = 8;
        if (uVar9 != 8) {
          uVar2 = 7;
          param_1[1] = uVar9 & 0xfff7;
        }
      }
      else {
        iVar5 = *param_2;
        uVar2 = 0xf;
        uVar3 = uVar3 - *(ushort *)(param_2 + 2) & 0xffff;
      }
      puVar7 = (ushort *)(iVar5 + uVar3 * 8);
      uVar9 = puVar7[2];
      if (uVar9 == 0) {
        *(undefined2 *)(iVar5 + uVar3 * 8) = 0xffff;
        puVar7[1] = 0xffff;
      }
      puVar7[2] = uVar9 | param_1[1];
      if ((uVar2 & uVar9) == 0) {
        puVar10 = (ushort *)*param_3;
        uVar9 = puVar10[1];
        if ((uVar2 & ~uVar9) == 0) {
          uVar3 = 0;
          iVar5 = 0;
          uVar6 = 1;
        }
        else {
          puVar4 = puVar10 + 3;
          uVar3 = 0;
          do {
            uVar6 = uVar3;
            uVar9 = *puVar4;
            uVar3 = uVar6 + 1;
            puVar4 = puVar4 + 2;
          } while ((uVar2 & ~uVar9) != 0);
          iVar5 = uVar3 * 4;
          uVar6 = uVar6 + 2;
          puVar10 = puVar10 + uVar3 * 2;
          uVar9 = puVar10[1];
        }
        uVar1 = *puVar10;
        puVar10[1] = uVar9 & ~uVar2;
        if (*(ushort *)(param_3 + 1) == uVar6) {
          if (*(short *)(iVar5 + *param_3 + 2) != 0) {
            *(short *)(param_3 + 1) = (short)uVar6 + 1;
            uVar3 = uVar6;
          }
          *(ushort *)(*param_3 + uVar3 * 4) = uVar1 + 1;
          *(undefined2 *)(uVar3 * 4 + *param_3 + 2) = 0xf;
        }
        else {
          iVar8 = *param_3;
          if ((*(short *)(iVar8 + iVar5 + 2) == 0) &&
             (uVar6 = *(ushort *)(param_3 + 1) - 1, *(short *)(param_3 + 1) = (short)uVar6,
             uVar3 < (uVar6 & 0xffff))) {
            iVar5 = uVar3 << 2;
            while( true ) {
              uVar3 = uVar3 + 1;
              *(undefined4 *)(iVar5 + iVar8) = *(undefined4 *)(iVar5 + iVar8 + 4);
              iVar5 = iVar5 + 4;
              if (*(ushort *)(param_3 + 1) <= uVar3) break;
              iVar8 = *param_3;
            }
          }
        }
        if ((uVar2 & 7) != 0) {
          *puVar7 = uVar1;
        }
        if ((uVar2 & 8) != 0) {
          puVar7[1] = uVar1;
        }
      }
      if (uVar2 == 8) {
        uVar2 = puVar7[1];
      }
      else {
        uVar2 = *puVar7;
      }
    }
    *param_1 = uVar2;
    return;
  }
  return;
}

/* FUN_000c5e60 @ 0xc5e60 (1524 bytes) */
int FUN_000c5e60(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  ushort *puVar10;
  ushort uVar11;
  uint uVar12;
  ushort *puVar13;
  byte *pbVar14;
  ushort *puVar15;
  char *pcVar16;
  ushort *puVar17;
  ushort *puVar18;
  ushort *puVar19;
  ushort *puVar20;
  ushort *puVar21;
  ushort *puVar22;
  char *pcVar23;
  ushort *puVar24;
  ushort *puVar25;
  ushort *puVar26;
  char *pcVar27;
  char *pcVar28;
  uint uVar29;
  int iVar30;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74;
  int local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  uint local_5c;
  uint local_58;
  
  local_7c = (uint)*(ushort *)(param_1 + 5);
  if (local_7c != 0) {
    return;
  }
  local_58 = param_1[2];
  local_98 = local_7c;
  local_94 = local_7c;
  local_90 = local_7c;
  local_8c = local_7c;
  local_88 = local_7c;
  local_84 = local_7c;
  local_80 = local_7c;
  if (local_58 == 0) {
    local_5c = local_58;
    local_74 = local_58;
    local_6c = local_58;
    local_78 = local_58;
    local_70 = 1;
    local_60 = 0;
    local_68 = local_58;
    local_64 = local_58;
    uVar11 = 0;
  }
  else {
    puVar21 = (ushort *)((int)param_1 + 0x62);
    uVar29 = 0;
    local_64 = 0;
    local_70 = 1;
    local_68 = 0;
    local_78 = 0;
    local_6c = 0;
    local_5c = 0;
    local_74 = 0;
    local_60 = 0;
    pcVar23 = (char *)(param_1 + 0x1a);
    puVar24 = (ushort *)((int)param_1 + 0x5a);
    puVar4 = (ushort *)(param_1 + 0x16);
    puVar5 = (ushort *)((int)param_1 + 0x56);
    puVar15 = (ushort *)(param_1 + 0x15);
    pcVar16 = (char *)(param_1 + 0x1f);
    puVar17 = (ushort *)((int)param_1 + 0x66);
    puVar18 = (ushort *)(param_1 + 0x19);
    puVar13 = (ushort *)(param_1 + 0x18);
    pcVar27 = (char *)(param_1 + 0x17);
    pbVar14 = (byte *)((int)param_1 + 0x61);
    puVar10 = (ushort *)(param_1 + 0x13);
    pcVar7 = (char *)((int)param_1 + 0x51);
    puVar6 = (ushort *)((int)param_1 + 0x4e);
    pcVar9 = (char *)((int)param_1 + 0x53);
    uVar12 = 1;
    uVar11 = 0;
    puVar19 = puVar5;
    puVar20 = puVar4;
    puVar22 = puVar21;
    puVar25 = puVar24;
    puVar26 = puVar15;
    pcVar28 = pcVar23;
    puVar3 = param_1;
    do {
      puVar3 = puVar3 + 0x12;
      switch(*puVar3) {
      case 1:
        if ((*pcVar9 != '\0') && (uVar11 < *puVar6)) {
          uVar11 = *puVar6;
        }
        if ((*pcVar7 != '\0') && (uVar11 < *puVar10)) {
          uVar11 = *puVar10;
        }
        uVar29 = uVar29 + 1 & 0xffff;
        break;
      case 2:
        if (local_70 == 0) {
          if (*pcVar28 != '\0') {
            local_5c = local_5c + 1 & 0xffff;
            local_78 = local_78 + 1 & 0xffff;
          }
        }
        else {
          local_5c = local_5c + 1 & 0xffff;
        }
        if (*(byte *)puVar21 < 8) {
          uVar1 = 1 << ((int)(char)*(byte *)puVar21 & 0x3fU);
          if ((uVar1 & 0xba) == 0) {
            if ((uVar1 & 4) == 0) {
              if ((uVar1 & 0x40) != 0) {
                uVar2 = *puVar20;
                if (*puVar20 <= uVar11) {
                  uVar2 = uVar11;
                }
                uVar11 = *puVar24;
                if (*puVar24 <= uVar2) {
                  uVar11 = uVar2;
                }
                goto LAB_000c60a8;
              }
            }
            else if (uVar11 < *puVar19) {
              uVar11 = *puVar19;
            }
          }
          else {
LAB_000c60a8:
            if (uVar11 < *puVar19) {
              uVar11 = *puVar19;
            }
            if (uVar11 < *puVar15) {
              uVar11 = *puVar15;
            }
            if (*pbVar14 < 0x10) {
              iVar8 = (uint)*pbVar14 * 2;
              *(short *)((int)&local_98 + iVar8) = *(short *)((int)&local_98 + iVar8) + 1;
            }
          }
        }
        local_70 = 0;
        local_64 = local_64 + 1 & 0xffff;
        break;
      case 3:
      case 4:
        if (local_5c == 0) {
          local_5c = 1;
        }
        if ((*pcVar27 != '\0') && (uVar11 < *puVar26)) {
          uVar11 = *puVar26;
        }
        uVar2 = *puVar5;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        uVar2 = *puVar4;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        uVar2 = *puVar25;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        if ((*pcVar23 != '\0') && (uVar11 < *puVar13)) {
          uVar11 = *puVar13;
        }
        uVar2 = *puVar22;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        uVar2 = *puVar18;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        uVar2 = *puVar17;
        if ((uVar2 & 0x8000) == 0) {
          if (uVar11 < uVar2) {
            uVar11 = uVar2;
          }
        }
        else if (local_60 < (uVar2 & 0x7fff)) {
          local_60 = uVar2 & 0x7fff;
        }
        if (*pcVar16 != '\0') {
          local_74 = local_74 + 1 & 0xffff;
        }
        local_70 = 1;
        local_68 = local_68 + 1 & 0xffff;
        break;
      case 5:
        local_6c = local_6c + 1 & 0xffff;
      }
      uVar12 = uVar12 + 1;
      pcVar16 = pcVar16 + 0x48;
      puVar17 = puVar17 + 0x24;
      puVar18 = puVar18 + 0x24;
      puVar22 = puVar22 + 0x24;
      puVar13 = puVar13 + 0x24;
      pcVar23 = pcVar23 + 0x48;
      puVar25 = puVar25 + 0x24;
      puVar4 = puVar4 + 0x24;
      puVar5 = puVar5 + 0x24;
      puVar26 = puVar26 + 0x24;
      pcVar27 = pcVar27 + 0x48;
      pbVar14 = pbVar14 + 0x48;
      puVar15 = puVar15 + 0x24;
      puVar19 = puVar19 + 0x24;
      puVar24 = puVar24 + 0x24;
      puVar20 = puVar20 + 0x24;
      puVar21 = puVar21 + 0x24;
      pcVar28 = pcVar28 + 0x48;
      puVar10 = puVar10 + 0x24;
      pcVar7 = pcVar7 + 0x48;
      puVar6 = puVar6 + 0x24;
      pcVar9 = pcVar9 + 0x48;
    } while (uVar12 <= local_58);
    if (uVar29 != 0) goto LAB_000c6350;
  }
  uVar29 = 1;
LAB_000c6350:
  if (local_5c == 0) {
    local_5c = 1;
    local_68 = 1;
  }
  if (local_70 == 0) {
    local_68 = local_68 + 1 & 0xffff;
  }
  uVar12 = (local_68 + local_78 & 0xffff) + local_74 & 0xffff;
  if (uVar12 < local_64) {
    uVar12 = local_64;
  }
  if (uVar12 < local_6c) {
    uVar12 = local_6c;
  }
  if (uVar12 < uVar29) {
    uVar12 = uVar29;
  }
  *(ushort *)((int)param_1 + 0x22) = uVar11;
  *(short *)((int)param_1 + 0x26) = (short)uVar12;
  *(short *)((int)param_1 + 0x1e) = (short)(local_68 + local_78);
  *(short *)(param_1 + 6) = (short)uVar29;
  *(short *)((int)param_1 + 0x16) = (short)local_5c;
  *(undefined2 *)(param_1 + 10) = 0;
  *(short *)(param_1 + 8) = (short)local_6c;
  iVar8 = 0;
  iVar30 = 0x10;
  *(short *)(param_1 + 7) = (short)local_68;
  *(short *)((int)param_1 + 0x1a) = (short)local_64;
  *(undefined2 *)(param_1 + 9) = (*(unsigned short *)((unsigned char *)&(local_60) + 2));
  puVar3 = param_1;
  do {
    uVar11 = *(ushort *)((int)&local_98 + iVar8);
    if (0xff < uVar11) {
      uVar11 = 0xff;
      *(undefined2 *)((int)&local_98 + iVar8) = 0xff;
    }
    *(char *)((int)puVar3 + 0x2a) = (char)uVar11;
    iVar8 = iVar8 + 2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    iVar30 = iVar30 + -1;
  } while (iVar30 != 0);
  *(undefined2 *)(param_1 + 5) = 1;
  return;
}

/* FUN_000c6470 @ 0xc6470 (1284 bytes) */
int FUN_000c6470(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined2 *param_3;
  uint *param_4;
  uint *param_5;
  undefined4 *param_6;
  undefined4 param_7;
  uint param_8;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  ushort auStack_8b8 [4];
  undefined4 uStack_8b0;
  undefined4 uStack_8ac;
  undefined2 *puStack_8a8;
  undefined2 uStack_8a4;
  ushort uStack_8a0;
  undefined2 uStack_89e;
  ushort uStack_89c;
  undefined2 uStack_89a;
  undefined2 *puStack_898;
  undefined2 *puStack_894;
  undefined2 uStack_890;
  undefined4 uStack_88c;
  undefined4 uStack_888;
  undefined4 uStack_884;
  undefined4 uStack_880;
  uint uStack_87c;
  undefined4 uStack_878;
  undefined4 uStack_874;
  undefined4 uStack_870;
  undefined4 uStack_86c;
  undefined4 uStack_868;
  uint auStack_864 [519];
  
  uVar6 = 0xf;
  puStack_8a8 = *(undefined2 **)(param_1 + 0x1c);
  auStack_8b8[1] = 0;
  auStack_8b8[0] = 0;
  auStack_8b8[3] = 0;
  auStack_8b8[2] = 0;
  (*(unsigned short *)((unsigned char *)&(uStack_8b0) + 2)) = 0;
  (*(unsigned short *)((unsigned char *)&(uStack_8b0) + 0)) = 0;
  (*(unsigned short *)((unsigned char *)&(uStack_8ac) + 2)) = 0;
  (*(unsigned short *)((unsigned char *)&(uStack_8ac) + 0)) = 0;
  *puStack_8a8 = 0;
  puStack_8a8[1] = 0xf;
  uStack_8a4 = 1;
  uStack_890 = SUB42((unsigned long)param_3,0);
  puStack_898 = puStack_8a8 + *(int *)(param_1 + 0x30) * 2;
  _memset(puStack_898,0,*(int *)(param_1 + 0x30) << 3);
  if (param_3 == (undefined2 *)0x0) {
    puStack_894 = param_3;
  }
  else {
    puStack_894 = puStack_898 + *(int *)(param_1 + 0x30) * 4;
    _memset(puStack_894,0,*(int *)(param_1 + 0x30) * 8);
  }
  iVar11 = *(int *)(param_2 + 8);
  if (iVar11 != 0) {
    uVar10 = 0;
    iVar12 = 0;
    puVar13 = (uint *)0x0;
    puVar14 = (uint *)(param_2 + iVar11 * 0x48);
    do {
      uVar5 = *puVar14;
      if (uVar5 == 2) {
        uStack_89e = 0xf;
        uStack_8a0 = *(ushort *)(puVar14 + 3);
        if (*(char *)((int)puVar14 + 0x1a) == '\0') {
          uVar6 = 0;
          *(undefined2 *)(puVar14 + 3) = 0;
          *(undefined1 *)((int)puVar14 + 0x1f) = 0xf;
          *(undefined1 *)((int)puVar14 + 0x19) = 0;
          *(undefined2 *)((int)puVar14 + 0xe) = 0;
        }
        else {
          if (*(char *)((int)puVar14 + 0x1a) == '\x02') {
            *(undefined2 *)(puVar14 + 3) = 0;
          }
          else {
            ((int (*)())FUN_000c59c0)(&uStack_8a0,&puStack_898,&puStack_8a8);
            *(ushort *)(puVar14 + 3) = uStack_8a0;
          }
          uStack_87c = CONCAT22(*(undefined2 *)((int)puVar14 + 0xe),
                                (ushort)*(byte *)((int)puVar14 + 0x1f)) ^ 0xf;
          ((int (*)())FUN_000c5c50)(&uStack_87c,&puStack_898,&puStack_8a8,param_4,param_5,param_6,uVar6,param_8);
          uVar6 = (uint)(*(unsigned short *)((unsigned char *)&(uStack_87c) + 0));
          *(ushort *)((int)puVar14 + 0xe) = (*(unsigned short *)((unsigned char *)&(uStack_87c) + 0));
        }
        if (((puVar13 == (uint *)0x0) || (*puVar13 != 2)) || (*(char *)(puVar13 + 8) != '\0')) {
          uVar10 = 0;
        }
        param_5 = (uint *)(uint)*(byte *)((int)puVar14 + 0x1a);
        if (param_5 != (uint *)0x0) {
          uVar5 = uVar10;
          if (uVar10 == 0) {
            uVar6 = (uint)*(ushort *)((int)puVar14 + 0xe);
          }
          else {
            uVar3 = *(ushort *)(puVar14 + 3);
            param_6 = (undefined4 *)(uint)uVar3;
            uVar4 = *(ushort *)((int)puVar14 + 0xe);
            uVar6 = (uint)uVar4;
            param_8 = 0;
            param_4 = auStack_864;
            do {
              uVar8 = param_4[param_8];
              if ((uVar3 == uVar8) && (param_5 != (uint *)((int)&MACH_HEADER.magic + 2))) {
                uVar5 = 0;
                *(undefined1 *)(puVar13 + 8) = 1;
              }
              if (uVar8 == uVar4) {
                uVar10 = param_8;
              }
              param_8 = param_8 + 1;
            } while (param_8 < uVar5);
            bVar1 = uVar10 < uVar5;
            uVar10 = uVar5;
            if (bVar1) goto LAB_000c6e10;
          }
          uVar10 = uVar5 + 1;
          auStack_864[uVar5] = uVar6;
        }
        goto LAB_000c6e10;
      }
      if (uVar5 < 3) {
        if (uVar5 == 1) {
          uStack_8a0 = *(ushort *)((int)puVar14 + 6);
          uVar6 = 0xf;
          uStack_89e = 0xf;
          uStack_89a = 0xf;
          uStack_89c = *(ushort *)(puVar14 + 1);
          if (*(char *)((int)puVar14 + 0xb) == '\0') {
            *(undefined2 *)((int)puVar14 + 6) = 0;
            *(undefined1 *)((int)puVar14 + 0xf) = 0xf;
            *(undefined1 *)((int)puVar14 + 0xd) = 0;
            *(undefined1 *)((int)puVar14 + 10) = 0;
          }
          else {
            ((int (*)())FUN_000c59c0)(&uStack_8a0,&puStack_898,&puStack_8a8);
            *(ushort *)((int)puVar14 + 6) = uStack_8a0;
            *(byte *)((int)puVar14 + 0xf) = (byte)uStack_89e ^ 0xf;
          }
          if (*(char *)((int)puVar14 + 9) == '\0') {
            *(ushort *)(puVar14 + 1) = 0;
            *(undefined1 *)(puVar14 + 3) = 0;
            *(undefined1 *)((int)puVar14 + 0xe) = 0xf;
            *(undefined1 *)(puVar14 + 2) = 0;
          }
          else {
            ((int (*)())FUN_000c59c0)(&uStack_89c,&puStack_898,&puStack_8a8);
            *(ushort *)(puVar14 + 1) = uStack_89c;
            *(byte *)((int)puVar14 + 0xe) = (byte)uStack_89a ^ 0xf;
          }
        }
        goto LAB_000c6e10;
      }
      if (4 < uVar5) goto LAB_000c6e10;
      uStack_8a0 = *(ushort *)(puVar14 + 3);
      uStack_89c = *(ushort *)(puVar14 + 6);
      uStack_89a = 0;
      uStack_89e = (ushort)*(byte *)(puVar14 + 5);
      if (*(char *)(puVar14 + 8) != '\0') {
        uStack_89a = 8;
      }
      ((int (*)())FUN_000c59c0)(&uStack_8a0,&puStack_898,&puStack_8a8);
      *(ushort *)(puVar14 + 3) = uStack_8a0;
      *(byte *)(puVar14 + 5) = (byte)uStack_89e;
      ((int (*)())FUN_000c59c0)(&uStack_89c,&puStack_898,&puStack_8a8);
      uVar6 = 7;
      uStack_880 = 0;
      uStack_87c = 0;
      uStack_878 = 0;
      uStack_874 = 0;
      uStack_870 = 0;
      uStack_86c = 0;
      uStack_868 = 0;
      uStack_88c = 0;
      uStack_888 = 0;
      uStack_884 = 0;
      *(ushort *)(puVar14 + 6) = uStack_89c;
      *(byte *)(puVar14 + 8) = (byte)(-(uint)uStack_89a >> 0x1f);
      bVar9 = *(byte *)(puVar14 + 5) | *(byte *)((int)puVar14 + 0x15);
      if (bVar9 == 0) {
        uVar6 = 0;
      }
      bVar2 = *(byte *)((int)puVar14 + 0x31);
      uVar6 = -(uint)(byte)(*(byte *)(puVar14 + 8) | *(byte *)((int)puVar14 + 0x21) |
                           *(byte *)((int)puVar14 + 0x23)) >> 0x1c & 8 | uVar6;
      if ((bVar2 < 10) && ((1 << ((int)(char)bVar2 & 0x3fU) & 0x3b1U) != 0)) {
        uVar6 = uVar6 & (bVar9 | 8);
      }
      if (((bVar2 == 10) || (bVar2 == 2)) && ((uVar6 & 7) != 0)) {
        uVar6 = uVar6 | 8;
      }
      bVar9 = *(byte *)(puVar14 + 0x10);
      if ((bVar9 == 1) && ((uVar6 & 8) != 0)) {
        uVar6 = uVar6 | 7;
      }
      switch(bVar2) {
      case 0:
      case 7:
      case 8:
        ((int (*)())FUN_000c5460)((uint)*(byte *)((int)puVar14 + 0x2a),uVar6,(uint)*(byte *)(puVar14 + 0xc),
                     (uint)*(byte *)((int)puVar14 + 0x3f),&uStack_87c,&uStack_88c);
        ((int (*)())FUN_000c5460)((uint)*(byte *)((int)puVar14 + 0x2b),uVar6,(uint)*(byte *)(puVar14 + 0xc),
                     (uint)*(byte *)((int)puVar14 + 0x3f),&uStack_87c,&uStack_88c);
        bVar9 = *(byte *)(puVar14 + 0xb);
        goto code_r0x000c6a30;
      case 1:
      case 4:
      case 5:
        ((int (*)())FUN_000c5460)((uint)*(byte *)((int)puVar14 + 0x2a),uVar6,(uint)*(byte *)(puVar14 + 0xc),
                     (uint)*(byte *)((int)puVar14 + 0x3f),&uStack_87c,&uStack_88c);
        bVar9 = *(byte *)((int)puVar14 + 0x2b);
code_r0x000c6a30:
        param_6 = &uStack_88c;
        param_5 = &uStack_87c;
        param_4 = (uint *)(uint)*(byte *)((int)puVar14 + 0x3f);
        ((int (*)())FUN_000c5460)((uint)bVar9,uVar6,(uint)*(byte *)(puVar14 + 0xc),param_4,param_5,param_6);
        bVar9 = *(byte *)(puVar14 + 0x10);
        break;
      case 2:
        param_5 = &uStack_87c;
        param_6 = &uStack_88c;
        ((int (*)())FUN_000c5460)((uint)*(byte *)((int)puVar14 + 0x2a),uVar6,(uint)*(byte *)(puVar14 + 0xc),
                     (uint)*(byte *)((int)puVar14 + 0x3f),param_5,param_6);
        ((int (*)())FUN_000c5460)((uint)*(byte *)((int)puVar14 + 0x2b),uVar6,(uint)*(byte *)(puVar14 + 0xc),
                     (uint)*(byte *)((int)puVar14 + 0x3f),param_5,param_6);
        ((int (*)())FUN_000c57b0)((uint)*(byte *)((int)puVar14 + 0x39),uVar6,(uint)*(byte *)(puVar14 + 0xc),
                     (uint)*(byte *)((int)puVar14 + 0x3f),param_5,param_6);
        param_4 = (uint *)(uint)*(byte *)((int)puVar14 + 0x3f);
        ((int (*)())FUN_000c57b0)((uint)*(byte *)((int)puVar14 + 0x3a),uVar6,(uint)*(byte *)(puVar14 + 0xc),
                     param_4,param_5,param_6);
        bVar9 = *(byte *)(puVar14 + 0x10);
        break;
      case 3:
        param_5 = &uStack_87c;
        param_6 = &uStack_88c;
        ((int (*)())FUN_000c5460)((uint)*(byte *)((int)puVar14 + 0x2a),uVar6 & 3,(uint)*(byte *)(puVar14 + 0xc),
                     (uint)*(byte *)((int)puVar14 + 0x3f),param_5,param_6);
        ((int (*)())FUN_000c5460)((uint)*(byte *)((int)puVar14 + 0x2b),uVar6 & 3,(uint)*(byte *)(puVar14 + 0xc),
                     (uint)*(byte *)((int)puVar14 + 0x3f),param_5,param_6);
        param_4 = (uint *)(uint)*(byte *)((int)puVar14 + 0x3f);
        ((int (*)())FUN_000c5460)((uint)*(byte *)(puVar14 + 0xb),uVar6 & 4,(uint)*(byte *)(puVar14 + 0xc),param_4
                     ,param_5,param_6);
        bVar9 = *(byte *)(puVar14 + 0x10);
        break;
      case 6:
        break;
      case 9:
        param_5 = &uStack_87c;
        param_4 = (uint *)(uint)*(byte *)((int)puVar14 + 0x3f);
        param_6 = &uStack_88c;
        ((int (*)())FUN_000c5460)((uint)*(byte *)((int)puVar14 + 0x2a),uVar6,(uint)*(byte *)(puVar14 + 0xc),
                     param_4,param_5,param_6);
        bVar9 = *(byte *)(puVar14 + 0x10);
      }
      if (bVar9 < 0xc) {
        uVar5 = 1 << ((int)(char)bVar9 & 0x3fU);
        if ((uVar5 & 0x61) == 0) {
          if ((uVar5 & 0xc) == 0) {
            if ((uVar5 & 0xf80) != 0) {
              param_4 = (uint *)(uint)*(byte *)((int)puVar14 + 0x3f);
              param_6 = &uStack_88c;
              param_5 = &uStack_87c;
              ((int (*)())FUN_000c57b0)((uint)*(byte *)((int)puVar14 + 0x39),uVar6,(uint)*(byte *)(puVar14 + 0xc)
                           ,param_4,&uStack_87c,param_6);
            }
            goto code_r0x000c6c50;
          }
          ((int (*)())FUN_000c57b0)((uint)*(byte *)((int)puVar14 + 0x39),uVar6,(uint)*(byte *)(puVar14 + 0xc),
                       (uint)*(byte *)((int)puVar14 + 0x3f),&uStack_87c,&uStack_88c);
          bVar9 = *(byte *)((int)puVar14 + 0x3a);
        }
        else {
          ((int (*)())FUN_000c57b0)((uint)*(byte *)((int)puVar14 + 0x39),uVar6,(uint)*(byte *)(puVar14 + 0xc),
                       (uint)*(byte *)((int)puVar14 + 0x3f),&uStack_87c,&uStack_88c);
          ((int (*)())FUN_000c57b0)((uint)*(byte *)((int)puVar14 + 0x3a),uVar6,(uint)*(byte *)(puVar14 + 0xc),
                       (uint)*(byte *)((int)puVar14 + 0x3f),&uStack_87c,&uStack_88c);
          bVar9 = *(byte *)((int)puVar14 + 0x3b);
        }
        param_6 = &uStack_88c;
        param_4 = (uint *)(uint)*(byte *)((int)puVar14 + 0x3f);
        param_5 = &uStack_87c;
        ((int (*)())FUN_000c57b0)((uint)bVar9,uVar6,(uint)*(byte *)(puVar14 + 0xc),param_4,&uStack_87c,param_6);
      }
code_r0x000c6c50:
      uVar3 = *(ushort *)((int)puVar14 + 0xe);
      param_8 = (uint)uVar3;
      uStack_87c = CONCAT22(uVar3,(*(unsigned short *)((unsigned char *)&(uStack_87c) + 2)));
      uStack_878 = CONCAT22(*(undefined2 *)(puVar14 + 4),(*(unsigned short *)((unsigned char *)&(uStack_878) + 2)));
      uStack_874 = CONCAT22(*(undefined2 *)((int)puVar14 + 0x12),(*(unsigned short *)((unsigned char *)&(uStack_874) + 2)));
      uStack_870 = CONCAT22(*(undefined2 *)((int)puVar14 + 0x1a),(*(unsigned short *)((unsigned char *)&(uStack_870) + 2)));
      uVar4 = *(ushort *)(puVar14 + 7);
      uVar6 = (uint)uVar4;
      uStack_86c = CONCAT22(uVar4,(*(unsigned short *)((unsigned char *)&(uStack_86c) + 2)));
      uStack_888 = CONCAT22(*(undefined2 *)(puVar14 + 4),(*(unsigned short *)((unsigned char *)&(uStack_888) + 2)));
      uStack_884 = CONCAT22(*(undefined2 *)((int)puVar14 + 0x1a),(*(unsigned short *)((unsigned char *)&(uStack_884) + 2)));
      uStack_88c = CONCAT22(uVar3,(*(unsigned short *)((unsigned char *)&(uStack_88c) + 2)));
      uStack_880 = CONCAT22(uVar4,(*(unsigned short *)((unsigned char *)&(uStack_880) + 2)));
      uStack_868 = CONCAT22(*(undefined2 *)((int)puVar14 + 0x1e),(*(unsigned short *)((unsigned char *)&(uStack_868) + 2)));
      ((int (*)())FUN_000c5c50)(&uStack_87c,&puStack_898,&puStack_8a8,param_4,param_5,param_6,uVar6,param_8);
      *(ushort *)((int)puVar14 + 0xe) = (*(unsigned short *)((unsigned char *)&(uStack_87c) + 0));
      ((int (*)())FUN_000c5c50)(&uStack_878,&puStack_898,&puStack_8a8,param_4,param_5,param_6,uVar6,param_8);
      *(undefined2 *)(puVar14 + 4) = (*(unsigned short *)((unsigned char *)&(uStack_878) + 0));
      ((int (*)())FUN_000c5c50)(&uStack_874,&puStack_898,&puStack_8a8,param_4,param_5,param_6,uVar6,param_8);
      *(undefined2 *)((int)puVar14 + 0x12) = (*(unsigned short *)((unsigned char *)&(uStack_874) + 0));
      ((int (*)())FUN_000c5c50)(&uStack_870,&puStack_898,&puStack_8a8,param_4,param_5,param_6,uVar6,param_8);
      *(undefined2 *)((int)puVar14 + 0x1a) = (*(unsigned short *)((unsigned char *)&(uStack_870) + 0));
      ((int (*)())FUN_000c5c50)(&uStack_86c,&puStack_898,&puStack_8a8,param_4,param_5,param_6,uVar6,param_8);
      *(undefined2 *)(puVar14 + 7) = (*(unsigned short *)((unsigned char *)&(uStack_86c) + 0));
      ((int (*)())FUN_000c5c50)(&uStack_868,&puStack_898,&puStack_8a8,param_4,param_5,param_6,uVar6,param_8);
      *(undefined1 *)(puVar14 + 0xd) = 0;
      *(undefined2 *)((int)puVar14 + 0x1e) = (*(unsigned short *)((unsigned char *)&(uStack_868) + 0));
      if ((puVar13 != (uint *)0x0) && (*puVar13 - 3 < 2)) {
        iVar7 = 0;
        param_4 = (uint *)(auStack_8b8 + 4);
        param_6 = (undefined4 *)(uint)*(ushort *)(puVar14 + 3);
        param_8 = (uint)*(ushort *)(puVar14 + 6);
        param_5 = &uStack_8ac;
        uVar6 = -(uint)*(byte *)(puVar14 + 8) >> 0x1c & 8 | (uint)*(byte *)(puVar14 + 5);
        do {
          if ((param_6 == (undefined4 *)(uint)*(ushort *)(iVar7 + (int)param_4)) &&
             ((uVar6 & *(ushort *)((int)auStack_8b8 + iVar7)) != 0)) {
            *(undefined1 *)(puVar14 + 0xd) = 1;
          }
          if ((param_8 == *(ushort *)(iVar7 + (int)param_5)) &&
             ((uVar6 & *(ushort *)((int)auStack_8b8 + iVar7 + 4)) != 0)) {
            *(undefined1 *)(puVar14 + 0xd) = 1;
          }
          bVar1 = iVar7 != 2;
          iVar7 = iVar7 + 2;
        } while (bVar1);
      }
      (*(unsigned short *)((unsigned char *)&(uStack_8b0) + 0)) = *(undefined2 *)((int)puVar14 + 0xe);
      (*(unsigned short *)((unsigned char *)&(uStack_8b0) + 2)) = *(undefined2 *)(puVar14 + 4);
      (*(unsigned short *)((unsigned char *)&(uStack_8ac) + 0)) = *(undefined2 *)((int)puVar14 + 0x1a);
      uVar6 = (uint)*(ushort *)(puVar14 + 7);
      auStack_8b8[0] = (*(unsigned short *)((unsigned char *)&(uStack_88c) + 2));
      auStack_8b8[1] = (*(unsigned short *)((unsigned char *)&(uStack_888) + 2));
      (*(unsigned short *)((unsigned char *)&(uStack_8ac) + 2)) = *(ushort *)(puVar14 + 7);
      auStack_8b8[2] = (*(unsigned short *)((unsigned char *)&(uStack_884) + 2));
      auStack_8b8[3] = (*(unsigned short *)((unsigned char *)&(uStack_880) + 2));
LAB_000c6e10:
      iVar12 = iVar12 + 1;
      puVar13 = puVar14;
      puVar14 = puVar14 + -0x12;
    } while (iVar11 != iVar12);
  }
  ((int (*)())FUN_000c5e60)(param_2);
  return;
}

/* FUN_000c6e50 @ 0xc6e50 (40 bytes) */
int FUN_000c6e50(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  _free(param_2);
  return 0;
}

/* FUN_000c6e80 @ 0xc6e80 (16 bytes) */
int FUN_000c6e80(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  *param_3 = 0;
  return 0;
}

/* FUN_000c6e90 @ 0xc6e90 (88 bytes) */
int FUN_000c6e90(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  undefined1 auStack_118 [264];
  
  _strcpy(auStack_118,param_2);
  iVar1 = _strlen(auStack_118);
  FUN_001a3428(auStack_118 + iVar1,0x100 - iVar1,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000c6ef0 @ 0xc6ef0 (88 bytes) */
int FUN_000c6ef0(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_3 == 2) {
    uVar1 = _fopen(param_2,"w");
    return uVar1;
  }
  if (param_3 != 3) {
    if (param_3 == 1) {
      uVar1 = _fopen(param_2,"r");
      return uVar1;
    }
    return 0;
  }
  uVar1 = _fopen(param_2,"r+");
  return uVar1;
}

/* FUN_000c6f60 @ 0xc6f60 (44 bytes) */
int FUN_000c6f60(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = _fclose(param_2);
  return iVar1 == 0;
}

/* FUN_000c6f90 @ 0xc6f90 (40 bytes) */
int FUN_000c6f90(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  if ((param_3 != 0) && (param_2 != 0)) {
    uVar1 = _fwrite(param_3,1,param_4,param_2);
    return uVar1;
  }
  return 0;
}

/* FUN_000c6fc0 @ 0xc6fc0 (40 bytes) */
int FUN_000c6fc0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  if ((param_3 != 0) && (param_2 != 0)) {
    uVar1 = _fread(param_3,1,param_4,param_2);
    return uVar1;
  }
  return 0;
}

/* FUN_000c6ff0 @ 0xc6ff0 (464 bytes) */
int FUN_000c6ff0(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_54;
  undefined4 *local_50;
  undefined *local_4c;
  code *local_48;
  code *local_44;
  code *local_40;
  code *local_3c;
  code *local_38;
  code *local_34;
  code *local_30;
  
  _memset(&local_7c,0,0x54);
  local_78 = *(undefined4 *)(param_1 + 0x23d8);
  local_80 = 0;
  local_88 = 0;
  if (param_2 == 0) {
    local_7c = 0x2c;
  }
  else {
    puVar1 = *(undefined **)(param_1 + 0x23d4);
    if (((puVar1 + -0x7240 < &MACH_HEADER.ncmds) || (puVar1 + -0x7100 < &MACH_HEADER.ncmds)) ||
       (((((puVar1 != (undefined *)0x71c0 &&
           ((((puVar1 != (undefined *)0x71c2 && (puVar1 != (undefined *)0x71c6)) &&
             (puVar1 != (undefined *)0x71ce)) &&
            ((puVar1 != (undefined *)0x71d2 && (puVar1 != (undefined *)0x71de)))))) &&
          (puVar1 != (undefined *)0x71c4)) &&
         (((puVar1 != (undefined *)0x71c5 && (puVar1 != (undefined *)0x7140)) &&
          ((puVar1 != (undefined *)0x7142 &&
           (((puVar1 != ((unsigned char *)0x00007146) && (puVar1 != ((unsigned char *)0x0000714e))) &&
            (puVar1 != (undefined *)0x7152)))))))) &&
        (((puVar1 != (undefined *)0x715e && (puVar1 != ((unsigned char *)0x00007144))) &&
         ((puVar1 != ((unsigned char *)0x00007145) && ((puVar1 != ((unsigned char *)0x00007148) && (puVar1 != ((unsigned char *)0x00007149))))))))))
       ) {
      local_7c = 0x3c;
    }
    else {
      local_7c = 0x3e;
    }
  }
  local_4c = ((unsigned char *)0x000c6e40);
  local_48 = FUN_000c6e50;
  local_54 = 2;
  local_44 = FUN_000c6e80;
  local_40 = FUN_000c6e90;
  local_84 = 0x7b;
  local_3c = FUN_000c6ef0;
  local_38 = FUN_000c6f60;
  local_34 = FUN_000c6f90;
  local_30 = FUN_000c6fc0;
  local_50 = (undefined4 *)(param_1 + 0x186c);
  uVar2 = FUN_000cd05c(&local_7c,&local_88,0x10001);
  *(undefined4 *)(param_1 + 0x186c) = uVar2;
  *(undefined4 *)(param_1 + 0x1870) = local_84;
  return;
}

/* FUN_000c71e0 @ 0xc71e0 (76 bytes) */
int FUN_000c71e0(param_1)
  int param_1;
{
  if (param_1 != 0) {
    ((int (*)())FUN_000c71e0)(*(undefined4 *)(param_1 + 0x24));
    _free(param_1);
    return;
  }
  return;
}

/* FUN_000c7240 @ 0xc7240 (44 bytes) */
int FUN_000c7240(param_1)
  int param_1;
{
  undefined1 uVar1;
  
  uVar1 = 2;
  if ((param_1 != 2) && (uVar1 = 3, param_1 != 3)) {
    uVar1 = param_1 == 1;
  }
  return uVar1;
}

/* FUN_000c7270 @ 0xc7270 (24 bytes) */
int FUN_000c7270(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  
  iVar1 = param_2 * 4 + param_1;
  *(undefined4 *)(iVar1 + 0x2278) = 1;
  *(undefined4 *)(iVar1 + 0x2238) = param_3;
  return;
}

/* FUN_000c7290 @ 0xc7290 (88 bytes) */
int FUN_000c7290(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = ((int)param_2 >> 5) + (uint)((int)param_2 < 0 && (param_2 & 0x1f) != 0);
  iVar3 = param_2 * 0x10 + param_1;
  iVar5 = iVar2 * 4 + param_1;
  *(undefined4 *)(iVar3 + 0x1a8) = *param_3;
  uVar4 = *(uint *)(iVar5 + 0x188);
  *(undefined4 *)(iVar3 + 0x1ac) = param_3[1];
  *(undefined4 *)(iVar3 + 0x1b0) = param_3[2];
  uVar1 = param_3[3];
  *(uint *)(iVar5 + 0x188) = 1 << (param_2 + iVar2 * -0x20 & 0x3f) | uVar4;
  *(undefined4 *)(iVar3 + 0x1b4) = uVar1;
  return;
}

/* FUN_000c72f0 @ 0xc72f0 (88 bytes) */
int FUN_000c72f0(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 *param_3;
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = ((int)param_2 >> 5) + (uint)((int)param_2 < 0 && (param_2 & 0x1f) != 0);
  iVar5 = param_2 * 0x10 + param_1;
  *(undefined4 *)(((unsigned char *)0x000011c8) + iVar5) = *param_3;
  iVar4 = iVar1 * 4 + param_1;
  uVar3 = *(uint *)(((unsigned char *)0x000011a8) + iVar4);
  *(undefined4 *)((int)((unsigned char *)0x000011cc) + iVar5) = param_3[1];
  *(undefined4 *)((*(unsigned char *)0x000011d0) + iVar5) = param_3[2];
  uVar2 = param_3[3];
  *(uint *)(((unsigned char *)0x000011a8) + iVar4) = 1 << (param_2 + iVar1 * -0x20 & 0x3f) | uVar3;
  *(undefined4 *)(((unsigned char *)0x000011d4) + iVar5) = uVar2;
  return;
}

/* FUN_000c7350 @ 0xc7350 (72 bytes) */
int FUN_000c7350(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 8;
  do {
    uVar1 = 1 << (uVar2 & 0x3f);
    if ((uVar1 & *(uint *)(param_1 + 8)) == 0) {
      *(uint *)(param_1 + 8) = uVar1 | *(uint *)(param_1 + 8);
      return uVar2;
    }
    uVar2 = uVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return 0x11;
}

/* FUN_000c73a0 @ 0xc73a0 (20 bytes) */
int FUN_000c73a0(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
  return;
}

