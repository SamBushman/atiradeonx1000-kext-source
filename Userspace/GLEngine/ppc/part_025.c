#include "decls.h"

/* _glDeleteObjectARB_Exec @ 0x8719c (320 bytes) */
void _glDeleteObjectARB_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    return;
  }
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
      uVar1 = 0x501;
      goto LAB_00087260;
    }
    if (*(char *)(iVar3 + 0x14) == '\0') {
      iVar2 = *(int *)(iVar3 + 8) + -1;
      *(int *)(iVar3 + 8) = iVar2;
      if (iVar2 == 1) {
        _gleDeleteHashNameAndObject(param_1,*(int *)(param_1 + 0x5148) + 0x6018,param_2);
      }
      else {
        *(undefined1 *)(iVar3 + 0x14) = 1;
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
LAB_00087260:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glAttachObjectARB_Exec @ 0x872dc (488 bytes) */
void _glAttachObjectARB_Exec(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar4 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar4 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar4 + 0x8028);
      iVar4 = *(int *)(param_1 + 0x5148);
    }
    iVar4 = _gleLookupHashObject(iVar4 + 0x6018,param_2);
    if (iVar4 == 0) {
LAB_00087368:
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_000873fc;
    }
    if (*(int *)(iVar4 + 0x10) == 0x8b40) {
      iVar5 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x6018,param_3);
      if (iVar5 == 0) goto LAB_00087368;
      if (*(int *)(iVar5 + 0x10) == 0x8b48) {
        iVar6 = *(int *)(iVar4 + 0x48);
        iVar7 = 0;
        if (0 < iVar6) {
          piVar3 = *(int **)(iVar4 + 0x44);
          do {
            iVar2 = *piVar3;
            piVar3 = piVar3 + 1;
            if (iVar2 == iVar5) goto LAB_000873d0;
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar6);
        }
        iVar6 = _malloc(iVar6 * 4 + 4);
        iVar7 = 0;
        if (0 < *(int *)(iVar4 + 0x48)) {
          do {
            iVar2 = iVar7 * 4;
            iVar7 = iVar7 + 1;
            *(undefined4 *)(iVar2 + iVar6) = *(undefined4 *)(iVar2 + *(int *)(iVar4 + 0x44));
          } while (iVar7 < *(int *)(iVar4 + 0x48));
        }
        *(int *)(iVar6 + iVar7 * 4) = iVar5;
        *(int *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) + 1;
        if (*(int *)(iVar4 + 0x44) != 0) {
          _free(*(int *)(iVar4 + 0x44));
        }
        *(int *)(iVar4 + 0x44) = iVar6;
        *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + 1;
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
        return;
      }
    }
LAB_000873d0:
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x502;
LAB_000873fc:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glDetachObjectARB_Exec @ 0x874c4 (552 bytes) */
void _glDetachObjectARB_Exec(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  
  bVar1 = false;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar5 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar5 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar5 + 0x8028);
      iVar5 = *(int *)(param_1 + 0x5148);
    }
    iVar5 = _gleLookupHashObject(iVar5 + 0x6018,param_2);
    if (iVar5 == 0) {
LAB_00087554:
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x501;
      goto LAB_000875fc;
    }
    if (*(int *)(iVar5 + 0x10) == 0x8b40) {
      iVar6 = _gleLookupHashObject(*(int *)(param_1 + 0x5148) + 0x6018,param_3);
      if (iVar6 == 0) goto LAB_00087554;
      iVar9 = *(int *)(iVar5 + 0x48);
      iVar10 = 0;
      if (0 < iVar9) {
        piVar4 = *(int **)(iVar5 + 0x44);
        do {
          if (iVar6 == *piVar4) {
            bVar1 = true;
          }
          iVar10 = iVar10 + 1;
          piVar4 = piVar4 + 1;
          if (iVar9 <= iVar10) goto LAB_000875c8;
        } while (!bVar1);
LAB_00087604:
        piVar4 = (int *)0x0;
        iVar10 = 1;
        if (iVar9 != 1) {
          piVar4 = (int *)_malloc(iVar9 * 4 + -4);
          iVar10 = *(int *)(iVar5 + 0x48);
        }
        iVar9 = 0;
        if (iVar10 < 1) {
          iVar7 = *(int *)(iVar5 + 0x44);
        }
        else {
          iVar7 = *(int *)(iVar5 + 0x44);
          piVar8 = piVar4;
          do {
            iVar3 = *(int *)(iVar9 * 4 + iVar7);
            if (iVar6 != iVar3) {
              *piVar8 = iVar3;
              piVar8 = piVar8 + 1;
              iVar10 = *(int *)(iVar5 + 0x48);
              iVar7 = *(int *)(iVar5 + 0x44);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 < iVar10);
        }
        *(int *)(iVar5 + 0x48) = iVar10 + -1;
        if (iVar7 != 0) {
          _free(iVar7);
        }
        *(int **)(iVar5 + 0x44) = piVar4;
        iVar5 = *(int *)(iVar6 + 8) + -1;
        *(int *)(iVar6 + 8) = iVar5;
        if (iVar5 == 1) {
          _gleDeleteHashNameAndObject(param_1,*(int *)(param_1 + 0x5148) + 0x6018,param_3);
        }
        if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
        return;
      }
LAB_000875c8:
      if (bVar1) goto LAB_00087604;
    }
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x502;
LAB_000875fc:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glGetHandleARB_Exec @ 0x876ec (96 bytes) */
int _glGetHandleARB_Exec(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (param_2 == 0x8b40) {
      if (*(int *)(param_1 + 0x5430) == 0) {
        return 0;
      }
      return *(undefined4 *)(*(int *)(param_1 + 0x5430) + 4);
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return 0;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return 0;
}

/* FUN_00087750 @ 0x87750 (716 bytes) */
void FUN_00087750(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (0 < param_3) {
      iVar6 = *(int *)(param_1 + 0x5148);
      if (*(char *)(iVar6 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar6 + 0x8028);
        iVar6 = *(int *)(param_1 + 0x5148);
      }
      iVar6 = _gleLookupHashObject(iVar6 + 0x6018,param_2);
      if (iVar6 != 0) {
        if (*(int *)(iVar6 + 0x10) != 0x8b48) {
          if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
            _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
          }
          goto LAB_000877f0;
        }
        iVar9 = 0;
        iVar10 = 0;
        if (0 < param_3) {
          do {
            if (param_5 == 0) {
              iVar4 = iVar10 << 2;
LAB_00087834:
              iVar5 = _strlen(*(undefined4 *)(param_4 + iVar4));
            }
            else {
              iVar4 = iVar10 * 4;
              iVar5 = *(int *)(param_5 + iVar4);
              if (iVar5 < 0) goto LAB_00087834;
            }
            iVar9 = iVar9 + iVar5;
            iVar10 = iVar10 + 1;
          } while (iVar10 < param_3);
        }
        iVar10 = 0;
        bVar1 = param_3 == 0;
        pcVar7 = (char *)_malloc(iVar9 + 2);
        pcVar8 = pcVar7;
        if (0 < param_3) {
          do {
            if (param_5 == 0) {
              iVar4 = iVar10 << 2;
LAB_00087894:
              pcVar8 = _stpcpy(pcVar8,*(char **)(param_4 + iVar4));
            }
            else {
              iVar4 = iVar10 * 4;
              if ((int)*(size_t *)(iVar4 + param_5) < 0) goto LAB_00087894;
              _strncpy(pcVar8,*(char **)(iVar4 + param_4),*(size_t *)(iVar4 + param_5));
              pcVar8 = pcVar8 + *(int *)(iVar4 + param_5);
              if (pcVar8[-1] == '\0') break;
            }
            iVar10 = iVar10 + 1;
            bVar1 = iVar10 == param_3;
          } while (iVar10 < param_3);
        }
        *pcVar8 = '\0';
        if (bVar1) {
          iVar10 = 0;
          cVar2 = *pcVar7;
          pcVar8 = pcVar7;
          while (cVar2 != '\0') {
            if ((cVar2 == '\r') && (pcVar8[1] == '\n')) {
              *pcVar8 = ' ';
            }
            else if (cVar2 == '\r') {
              *pcVar8 = '\n';
            }
            pcVar8 = pcVar8 + 1;
            iVar10 = iVar10 + 1;
            cVar2 = *pcVar8;
          }
          if (pcVar7[iVar10 + -1] != '\n') {
            iVar9 = iVar9 + 1;
            pcVar7[iVar10] = '\n';
            pcVar7[iVar10 + 1] = '\0';
          }
          if (*(int *)(iVar6 + 0x2c) != 0) {
            _free(*(int *)(iVar6 + 0x2c));
          }
          *(char **)(iVar6 + 0x2c) = pcVar7;
          *(undefined1 *)(iVar6 + 0x24) = 1;
          *(int *)(iVar6 + 0x28) = iVar9;
          if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
            return;
          }
          _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
          return;
        }
        _free(pcVar7);
      }
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x501;
  }
  else {
LAB_000877f0:
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glCompileShaderARB_Exec @ 0x87a1c (252 bytes) */
void _glCompileShaderARB_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
    return;
  }
  iVar2 = *(int *)(param_1 + 0x5148);
  if (*(char *)(iVar2 + 0x8024) != '\0') {
    _pthread_mutex_lock(iVar2 + 0x8028);
    iVar2 = *(int *)(param_1 + 0x5148);
  }
  iVar2 = _gleLookupHashObject(iVar2 + 0x6018,param_2);
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00087ad8;
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(iVar2 + 0x10) == 0x8b48) {
      _gleShaderParse(param_1,iVar2);
      goto LAB_00087ad8;
    }
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00087ad8;
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
LAB_00087ad8:
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) == '\0') {
    return;
  }
  _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
  return;
}

/* _evaluateImageUnits @ 0x87b18 (1000 bytes) */
int _evaluateImageUnits(param_1, param_2)
  int param_1;
  int param_2;
{
  ushort uVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  longlong lVar18;
  int local_120 [32];
  ushort local_a0 [32];
  undefined4 local_60;
  char local_5c [4];
  uint local_58;
  
  piVar10 = (int *)(param_2 + 0x20);
  iVar11 = 0;
  local_58 = (uint)*(byte *)(param_2 + 0x3e);
  *(undefined1 *)(param_2 + 0x3e) = 1;
  do {
    if (iVar11 == 0) {
      iVar16 = *piVar10;
      iVar17 = 0;
    }
    else {
      iVar16 = *(int *)(param_2 + 0x24);
      iVar17 = 0x10;
    }
    if (iVar17 != 0) {
      piVar13 = local_120 + iVar11 * 0x10;
      puVar7 = local_a0 + iVar11 * 0x10;
      iVar6 = iVar16 + 0x60;
      do {
        *piVar13 = *(int *)(iVar16 + 0x2c);
        piVar13 = piVar13 + 1;
        *puVar7 = *(ushort *)(iVar6 + 0xc);
        puVar7 = puVar7 + 1;
        *(undefined4 *)(iVar16 + 0x2c) = 0;
        iVar16 = iVar16 + 4;
        *(undefined2 *)(iVar6 + 0xc) = 0;
        iVar6 = iVar6 + 2;
        iVar17 = iVar17 + -1;
      } while (iVar17 != 0);
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < 2);
  iVar11 = 0;
  if (*(int *)(param_2 + 0x30) < 1) {
LAB_00087d18:
    cVar3 = *(char *)(param_2 + 0x3e);
  }
  else {
    cVar3 = *(char *)(param_2 + 0x3e);
    if (cVar3 == '\x01') {
      do {
        local_60 = 0;
        local_5c[0] = '\0';
        local_5c[1] = '\0';
        iVar17 = _ShGetUniformTypeInfo(*(undefined4 *)(param_2 + 0x40),iVar11,0,&local_60,local_5c);
        if ((iVar17 != 0) && (local_60 - 0x8b5d < 8)) {
          iVar17 = 0;
          pcVar5 = local_5c;
          do {
            cVar3 = *pcVar5;
            pcVar5 = pcVar5 + 1;
            if (cVar3 != '\0') {
              iVar16 = *(int *)(*(int *)(param_2 + 0x4c) + iVar11 * 0x10);
              if (iVar17 == 0) {
                iVar6 = *piVar10;
                iVar2 = 0;
              }
              else {
                iVar6 = *(int *)(param_2 + 0x24);
                iVar2 = 0x10;
              }
              if ((iVar2 <= iVar16) || (iVar16 < 0)) {
LAB_00087ce4:
                *(undefined1 *)(param_2 + 0x3e) = 0;
                break;
              }
              if (*(int *)(iVar16 * 4 + iVar6 + 0x2c) < 1) {
                iVar2 = iVar16 << 1;
              }
              else {
                iVar2 = iVar16 * 2;
                if (local_60 != *(ushort *)(iVar2 + iVar6 + 0x6c)) goto LAB_00087ce4;
              }
              iVar16 = iVar16 * 4 + iVar6;
              *(int *)(iVar16 + 0x2c) = *(int *)(iVar16 + 0x2c) + 1;
              *(undefined2 *)(iVar2 + iVar6 + 0x6c) = (*(unsigned short *)((unsigned char *)&(local_60) + 2));
            }
            iVar17 = iVar17 + 1;
          } while (iVar17 < 2);
        }
        iVar11 = iVar11 + 1;
        if (*(int *)(param_2 + 0x30) <= iVar11) goto LAB_00087d18;
        cVar3 = *(char *)(param_2 + 0x3e);
      } while (cVar3 == '\x01');
    }
  }
  if (cVar3 == '\0') {
    iVar11 = 0;
    do {
      if (iVar11 == 0) {
        iVar16 = *piVar10;
        iVar17 = 0;
      }
      else {
        iVar16 = *(int *)(param_2 + 0x24);
        iVar17 = 0x10;
      }
      if (iVar17 != 0) {
        piVar13 = local_120 + iVar11 * 0x10;
        puVar8 = local_a0 + iVar11 * 0x10;
        piVar9 = (int *)(iVar16 + 0x2c);
        puVar7 = (ushort *)(iVar16 + 0x6c);
        do {
          iVar16 = *piVar13;
          piVar13 = piVar13 + 1;
          *piVar9 = iVar16;
          piVar9 = piVar9 + 1;
          uVar1 = *puVar8;
          puVar8 = puVar8 + 1;
          *puVar7 = uVar1;
          puVar7 = puVar7 + 1;
          iVar17 = iVar17 + -1;
        } while (iVar17 != 0);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 2);
  }
  else {
    iVar11 = 0;
    do {
      if (iVar11 == 0) {
        iVar16 = *piVar10;
        iVar17 = 0;
      }
      else {
        iVar16 = *(int *)(param_2 + 0x24);
        iVar17 = 0x10;
      }
      uVar12 = 0;
      *(undefined4 *)(iVar16 + 0x50c) = 0xffffffff;
      *(undefined4 *)(iVar16 + 0x510) = 0xffffffff;
      if (iVar17 != 0) {
        puVar7 = (ushort *)(iVar16 + 0x6c);
        piVar13 = (int *)(iVar16 + 0x2c);
        do {
          iVar6 = *piVar13;
          piVar13 = piVar13 + 1;
          if (iVar6 != 0) {
            lVar18 = ___ashldi3(0,0xf,uVar12 << 2);
            uVar15 = *(uint *)(iVar16 + 0x510) & ~(uint)lVar18;
            uVar14 = *(uint *)(iVar16 + 0x50c) & ~(uint)((ulonglong)lVar18 >> 0x20);
            uVar1 = *puVar7;
            *(uint *)(iVar16 + 0x50c) = uVar14;
            *(uint *)(iVar16 + 0x510) = uVar15;
            uVar4 = _getIndexForGLSLSamplerType((uint)uVar1);
            lVar18 = ___ashldi3(0,uVar4,uVar12 << 2);
            *(uint *)(iVar16 + 0x50c) = uVar14 | (uint)((ulonglong)lVar18 >> 0x20);
            *(uint *)(iVar16 + 0x510) = uVar15 | (uint)lVar18;
          }
          if ((*(int *)(param_1 + 0x5430) == param_2) &&
             ((iVar2 = iVar11 * 0x10 + uVar12, iVar6 != local_120[iVar2] ||
              ((iVar6 != 0 && (*puVar7 != local_a0[iVar2])))))) {
            *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 1 << (uVar12 & 0x3f);
          }
          uVar12 = uVar12 + 1;
          puVar7 = puVar7 + 1;
        } while ((int)uVar12 < iVar17);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 2);
  }
  return -(uint)(local_58 ^ *(byte *)(param_2 + 0x3e)) >> 0x1f;
}

/* _setImageUnit @ 0x87f00 (576 bytes) */
double _setImageUnit(int param_1,int param_2,uint param_3,uint param_4,char *param_5,uint param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  double fparam_1_00;
  double extraout_f1;
  longlong lVar12;
  
  piVar8 = (int *)(param_2 + 0x20);
  if (*(char *)(param_2 + 0x3e) == '\0') {
    iVar3 = ((int (*)())_evaluateImageUnits)(param_1,param_2);
    if (iVar3 != 0) {
      ((void (*)())_updateShaderState)(param_1,piVar8,(uint)*(byte *)(param_1 + 0x759c),
                         (uint)**(byte **)(param_2 + 0x20),(uint)**(byte **)(param_2 + 0x24),
                         fparam_1_00,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8)
      ;
      return;
    }
  }
  else {
    iVar7 = 0;
    iVar3 = param_3 * 4;
    do {
      cVar1 = *param_5;
      param_5 = param_5 + 1;
      if (cVar1 != '\0') {
        if (iVar7 == 0) {
          iVar11 = *piVar8;
          iVar5 = 0;
        }
        else {
          iVar11 = *(int *)(param_2 + 0x24);
          iVar5 = 0x10;
        }
        if ((iVar5 <= (int)param_3) || ((int)param_3 < 0)) {
LAB_000880f8:
          *(undefined1 *)(param_2 + 0x3e) = 0;
          ((void (*)())_updateShaderState)(param_1,piVar8,(uint)*(byte *)(param_1 + 0x759c),(uint)*(byte *)*piVar8
                             ,(uint)**(byte **)(param_2 + 0x24),fparam_1,fparam_2,fparam_3,fparam_4,
                             fparam_5,fparam_6,fparam_7,fparam_8);
          return;
        }
        if (*(int *)(iVar3 + iVar11 + 0x2c) < 1) {
          iVar6 = param_3 << 1;
        }
        else {
          iVar6 = param_3 * 2;
          if (*(ushort *)(iVar6 + iVar11 + 0x6c) != param_6) goto LAB_000880f8;
        }
        iVar2 = *(int *)(iVar3 + iVar11 + 0x2c);
        *(short *)(iVar6 + iVar11 + 0x6c) = (short)param_6;
        *(int *)(iVar3 + iVar11 + 0x2c) = iVar2 + 1;
        if ((int)param_4 < iVar5) {
          if (*(int *)(param_1 + 0x5430) == param_2) {
            *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 1 << (param_4 & 0x3f);
          }
          iVar5 = param_4 * 4 + iVar11;
          iVar6 = *(int *)(iVar5 + 0x2c) + -1;
          *(int *)(iVar5 + 0x2c) = iVar6;
          if (iVar6 == 0) {
            lVar12 = ___ashldi3(0,0xf,param_4 * 4);
            *(uint *)(iVar11 + 0x50c) =
                 *(uint *)(iVar11 + 0x50c) | (uint)((ulonglong)lVar12 >> 0x20);
            *(uint *)(iVar11 + 0x510) = *(uint *)(iVar11 + 0x510) | (uint)lVar12;
          }
        }
        lVar12 = ___ashldi3(0,0xf,iVar3);
        uVar10 = *(uint *)(iVar11 + 0x510) & ~(uint)lVar12;
        uVar9 = *(uint *)(iVar11 + 0x50c) & ~(uint)((ulonglong)lVar12 >> 0x20);
        *(uint *)(iVar11 + 0x50c) = uVar9;
        *(uint *)(iVar11 + 0x510) = uVar10;
        uVar4 = _getIndexForGLSLSamplerType(param_6);
        lVar12 = ___ashldi3(0,uVar4,iVar3);
        *(uint *)(iVar11 + 0x50c) = uVar9 | (uint)((ulonglong)lVar12 >> 0x20);
        *(uint *)(iVar11 + 0x510) = uVar10 | (uint)lVar12;
        fparam_1 = extraout_f1;
        if (*(int *)(param_1 + 0x5430) == param_2) {
          *(uint *)(param_1 + 0x314) = *(uint *)(param_1 + 0x314) | 1 << (param_3 & 0x3f);
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 2);
  }
  return;
}

/* _glLinkProgramARB_Exec @ 0x88140 (2600 bytes) */
void _glLinkProgramARB_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  undefined1 uVar12;
  undefined4 uVar11;
  int *piVar13;
  int iVar14;
  int *piVar15;
  char *pcVar16;
  undefined1 *puVar17;
  int iVar18;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  int local_60 [2];
  int local_58 [2];
  undefined1 auStack_50 [4];
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [12];
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar9 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar9 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar9 + 0x8028);
      iVar9 = *(int *)(param_1 + 0x5148);
    }
    iVar9 = _gleLookupHashObject(iVar9 + 0x6018,param_2);
    if (iVar9 == 0) {
      if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      }
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar4 = 0x501;
      goto LAB_00088210;
    }
    if (*(int *)(iVar9 + 0x10) == 0x8b40) {
      piVar15 = (int *)(iVar9 + 0x20);
      *(undefined1 *)(iVar9 + 0x3e) = 0;
      *(undefined1 *)(iVar9 + 0x3c) = 0;
      *(undefined4 *)(iVar9 + 0x28) = 0;
      *(undefined4 *)(iVar9 + 0x2c) = 0;
      *(undefined4 *)(iVar9 + 0x34) = 0;
      *(undefined4 *)(iVar9 + 0x38) = 0;
      *(undefined4 *)(iVar9 + 0x30) = 0;
      if (*(int *)(iVar9 + 0x4c) != 0) {
        _gleVecFree(*(int *)(iVar9 + 0x4c));
      }
      iVar14 = 0;
      *(undefined4 *)(iVar9 + 0x4c) = 0;
      bVar2 = **(byte **)(iVar9 + 0x20);
      bVar3 = **(byte **)(iVar9 + 0x24);
      do {
        if (iVar14 == 0) {
          puVar17 = (undefined1 *)*piVar15;
        }
        else {
          puVar17 = *(undefined1 **)(iVar9 + 0x24);
        }
        *puVar17 = 0;
        iVar18 = 9;
        *(undefined4 *)(puVar17 + 4) = 0;
        puVar5 = (undefined4 *)(puVar17 + 8);
        do {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
          iVar18 = iVar18 + -1;
        } while (iVar18 != 0);
        if (*(int *)(puVar17 + 0x4dc) != 0) {
          _PPEmulatorProgramFree();
        }
        *(undefined4 *)(puVar17 + 0x4dc) = 0;
        *(undefined4 *)(puVar17 + 0x4e0) = 0;
        if (*(int *)(puVar17 + 0x508) != 0) {
          _gleVecFree(*(int *)(puVar17 + 0x508));
        }
        *(undefined4 *)(puVar17 + 0x508) = 0;
        *(undefined4 *)(puVar17 + 0x50c) = 0xffffffff;
        *(undefined4 *)(puVar17 + 0x510) = 0xffffffff;
        if (*(int *)(puVar17 + 0x51c) != 0) {
          _gleVecFree(*(int *)(puVar17 + 0x51c));
        }
        iVar18 = *(int *)(puVar17 + 0x518);
        *(undefined4 *)(puVar17 + 0x51c) = 0;
        if (iVar18 != 0) {
          if (*(int *)(iVar18 + 0x20) != 0) {
            _gleVecFree(*(int *)(iVar18 + 0x20));
            iVar18 = *(int *)(puVar17 + 0x518);
          }
          if (*(int *)(iVar18 + 8) != 0) {
            _gleVecFree(*(int *)(iVar18 + 8));
            iVar18 = *(int *)(puVar17 + 0x518);
          }
          if (*(int *)(iVar18 + 0xc) != 0) {
            _gleVecFree(*(int *)(iVar18 + 0xc));
            iVar18 = *(int *)(puVar17 + 0x518);
          }
          if (*(int *)(iVar18 + 0x18) != 0) {
            _gleVecFree(*(int *)(iVar18 + 0x18));
            iVar18 = *(int *)(puVar17 + 0x518);
          }
          if (*(int *)(iVar18 + 0x1c) != 0) {
            _gleVecFree(*(int *)(iVar18 + 0x1c));
            iVar18 = *(int *)(puVar17 + 0x518);
          }
          _gleVecFree(iVar18);
          *(undefined4 *)(puVar17 + 0x518) = 0;
        }
        iVar14 = iVar14 + 1;
      } while (iVar14 < 2);
      iVar18 = *(int *)(iVar9 + 0x48);
      iVar14 = 0;
      if (0 < iVar18) {
        piVar13 = *(int **)(iVar9 + 0x44);
        do {
          iVar6 = *piVar13;
          piVar13 = piVar13 + 1;
          if (*(char *)(iVar6 + 0x25) == '\0') {
            uVar4 = _strlen("ERROR: One or more attached shaders not successfully compiled\n");
            *(undefined4 *)(iVar9 + 0x1c) = uVar4;
            if (*(int *)(iVar9 + 0x18) != 0) {
              _free(*(int *)(iVar9 + 0x18));
            }
            *(undefined4 *)(iVar9 + 0x18) = 0;
            if (*(int *)(iVar9 + 0x1c) != 0) {
              pcVar10 = (char *)_malloc(*(int *)(iVar9 + 0x1c) + 1);
              *(char **)(iVar9 + 0x18) = pcVar10;
              if (pcVar10 != (char *)0x0) {
                _strncpy(pcVar10,"ERROR: One or more attached shaders not successfully compiled\n",
                         *(size_t *)(iVar9 + 0x1c));
              }
            }
            goto LAB_00088b38;
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 < iVar18);
      }
      if (iVar18 == 0) {
        uVar12 = _ShLink(*(undefined4 *)(iVar9 + 0x40),0,0,*(undefined4 *)(param_1 + 0x7594),
                         *(undefined4 *)(param_1 + 0x7598));
        *(undefined1 *)(iVar9 + 0x3c) = uVar12;
        *(undefined4 *)(iVar9 + 0x1c) = 0;
        if (*(int *)(iVar9 + 0x18) != 0) {
          _free(*(int *)(iVar9 + 0x18));
          *(undefined4 *)(iVar9 + 0x18) = 0;
        }
        ((int (*)())_evaluateImageUnits)(param_1,iVar9);
        fparam_1 = extraout_f1_03;
      }
      else {
        iVar6 = 0;
        iVar14 = _malloc(iVar18 << 2);
        iVar18 = *(int *)(iVar9 + 0x48);
        if (0 < iVar18) {
          do {
            iVar18 = iVar6 * 4;
            iVar6 = iVar6 + 1;
            *(undefined4 *)(iVar18 + iVar14) =
                 *(undefined4 *)(*(int *)(iVar18 + *(int *)(iVar9 + 0x44)) + 0x30);
            iVar18 = *(int *)(iVar9 + 0x48);
          } while (iVar6 < iVar18);
        }
        iVar6 = 0;
        uVar12 = _ShLink(*(undefined4 *)(iVar9 + 0x40),iVar14,iVar18,
                         *(undefined4 *)(param_1 + 0x7594),*(undefined4 *)(param_1 + 0x7598));
        *(undefined1 *)(iVar9 + 0x3c) = uVar12;
        _free(iVar14);
        uVar4 = _ShGetNumActiveUniforms(*(undefined4 *)(iVar9 + 0x40));
        *(undefined4 *)(iVar9 + 0x28) = uVar4;
        uVar4 = _ShGetMaxUniformLength(*(undefined4 *)(iVar9 + 0x40));
        *(undefined4 *)(iVar9 + 0x2c) = uVar4;
        uVar4 = _ShGetNumActiveAttributes(*(undefined4 *)(iVar9 + 0x40));
        *(undefined4 *)(iVar9 + 0x34) = uVar4;
        uVar4 = _ShGetMaxAttributeLength(*(undefined4 *)(iVar9 + 0x40));
        *(undefined4 *)(iVar9 + 0x38) = uVar4;
        uVar4 = _ShGetActiveUserUniformsSize(*(undefined4 *)(iVar9 + 0x40));
        iVar14 = *piVar15;
        *(undefined4 *)(iVar9 + 0x30) = uVar4;
        uVar4 = _ShGetShaderLocalParamRemapTable(*(undefined4 *)(iVar9 + 0x40),0);
        *(undefined4 *)(iVar14 + 0x4e0) = uVar4;
        iVar14 = *(int *)(iVar9 + 0x24);
        uVar4 = _ShGetShaderLocalParamRemapTable(*(undefined4 *)(iVar9 + 0x40),1);
        *(undefined4 *)(iVar14 + 0x4e0) = uVar4;
        iVar14 = _gleVecAlloc(*(int *)(iVar9 + 0x30) << 4);
        *(int *)(iVar9 + 0x4c) = iVar14;
        if (0 < *(int *)(iVar9 + 0x30)) {
          do {
            iVar18 = iVar6 * 0x10;
            iVar6 = iVar6 + 1;
            iVar7 = iVar18 + iVar14;
            *(undefined4 *)(iVar14 + iVar18) = 0;
            *(undefined4 *)(iVar7 + 0xc) = 0;
            *(undefined4 *)(iVar7 + 4) = 0;
            *(undefined4 *)(iVar7 + 8) = 0;
          } while (iVar6 < *(int *)(iVar9 + 0x30));
        }
        iVar14 = *piVar15;
        iVar18 = _ShGetNumShaderLocalParams(*(undefined4 *)(iVar9 + 0x40),0);
        if (iVar18 != 0) {
          iVar7 = 0;
          iVar6 = _gleVecAlloc(iVar18 << 4);
          *(int *)(iVar14 + 0x51c) = iVar6;
          if (0 < iVar18) {
            do {
              iVar14 = iVar7 * 0x10;
              iVar7 = iVar7 + 1;
              iVar8 = iVar14 + iVar6;
              *(undefined4 *)(iVar6 + iVar14) = 0;
              *(undefined4 *)(iVar8 + 0xc) = 0;
              *(undefined4 *)(iVar8 + 4) = 0;
              *(undefined4 *)(iVar8 + 8) = 0;
              iVar18 = iVar18 + -1;
            } while (iVar18 != 0);
          }
        }
        iVar14 = *(int *)(iVar9 + 0x24);
        iVar18 = _ShGetNumShaderLocalParams(*(undefined4 *)(iVar9 + 0x40),1);
        if (iVar18 != 0) {
          iVar7 = 0;
          iVar6 = _gleVecAlloc(iVar18 << 4);
          *(int *)(iVar14 + 0x51c) = iVar6;
          if (0 < iVar18) {
            do {
              iVar14 = iVar7 * 0x10;
              iVar7 = iVar7 + 1;
              iVar8 = iVar14 + iVar6;
              *(undefined4 *)(iVar6 + iVar14) = 0;
              *(undefined4 *)(iVar8 + 0xc) = 0;
              *(undefined4 *)(iVar8 + 4) = 0;
              *(undefined4 *)(iVar8 + 8) = 0;
              iVar18 = iVar18 + -1;
            } while (iVar18 != 0);
          }
        }
        iVar14 = 0;
        do {
          bVar1 = iVar14 != 0;
          if (bVar1) {
            puVar17 = *(undefined1 **)(iVar9 + 0x24);
          }
          else {
            puVar17 = (undefined1 *)*piVar15;
          }
          iVar18 = _ShGetPPStreamManager(*(undefined4 *)(iVar9 + 0x40),bVar1);
          if (iVar18 != 0) {
            _PPStreamGetStream(iVar18,0,local_60);
            if (local_60[0] != 0) {
              uVar4 = _gleVecAlloc(local_60[0] << 3);
              *(undefined4 *)(puVar17 + 0x508) = uVar4;
              _PPStreamGetStream(iVar18,uVar4,local_60);
              if ((*(int *)(puVar17 + 0x508) != 0) && (*puVar17 = 1, !bVar1)) {
                uVar4 = _PPStreamDuplicate(iVar18);
                _glpPPShaderLinearizeStreamMgr(uVar4,0xf9);
                uVar11 = _PPEmulatorProgramCreate();
                *(undefined4 *)(puVar17 + 0x4dc) = uVar11;
                _PPEmulatorProgramSetupHandlesFromPPStream(uVar11,param_1,uVar4);
                _PPEmulatorProgramConvertFromPPStream(*(undefined4 *)(puVar17 + 0x4dc),uVar4);
                _PPStreamFree(uVar4);
              }
            }
            _gleShaderDataUpdateParams(puVar17);
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 < 2);
        ((int (*)())_evaluateImageUnits)(param_1,iVar9);
        if (*(char *)(param_1 + 0x4693) == '\x01') {
          local_58[0] = 0;
          local_58[1] = 0;
          iVar14 = *(int *)(iVar9 + 0x48);
          bVar1 = iVar14 < 3;
          iVar18 = 0;
          if (iVar14 < 1) {
LAB_0008879c:
            if (bVar1) {
              iVar14 = 0;
              do {
                if (iVar14 == 0) {
                  pcVar10 = (char *)*piVar15;
                }
                else {
                  pcVar10 = *(char **)(iVar9 + 0x24);
                }
                if ((*pcVar10 != '\0') && (local_58[iVar14] != 0)) {
                  puVar5 = (undefined4 *)_gleVecAlloc(0x24);
                  *puVar5 = 0;
                  puVar5[1] = 0;
                  puVar5[2] = 0;
                  puVar5[3] = 0;
                  puVar5[4] = 0;
                  puVar5[5] = 0;
                  puVar5[6] = 0;
                  puVar5[7] = 0;
                  puVar5[8] = 0;
                  *puVar5 = *(undefined4 *)(iVar9 + 0x28);
                  puVar5[1] = *(undefined4 *)(iVar9 + 0x2c);
                  if (*(int *)(iVar9 + 0x28) != 0) {
                    iVar18 = 0;
                    uVar4 = _gleVecAlloc(*(int *)(iVar9 + 0x28) * *(int *)(iVar9 + 0x2c));
                    puVar5[2] = uVar4;
                    uVar4 = _gleVecAlloc(*(int *)(iVar9 + 0x28) << 2);
                    puVar5[3] = uVar4;
                    if (0 < *(int *)(iVar9 + 0x28)) {
                      do {
                        iVar6 = _ShGetActiveUniform(*(undefined4 *)(iVar9 + 0x40),iVar18,
                                                    *(int *)(iVar9 + 0x2c),auStack_50,auStack_4c,
                                                    auStack_48,
                                                    puVar5[2] + iVar18 * *(int *)(iVar9 + 0x2c));
                        if (iVar6 == 0) {
                          *(undefined4 *)(iVar18 * 4 + puVar5[3]) = 0xffffffff;
                        }
                        else {
                          uVar4 = _ShGetUniformLocation
                                            (*(undefined4 *)(iVar9 + 0x40),
                                             puVar5[2] + iVar18 * *(int *)(iVar9 + 0x2c));
                          *(undefined4 *)(iVar18 * 4 + puVar5[3]) = uVar4;
                        }
                        iVar18 = iVar18 + 1;
                      } while (iVar18 < *(int *)(iVar9 + 0x28));
                    }
                  }
                  puVar5[4] = *(undefined4 *)(iVar9 + 0x34);
                  puVar5[5] = *(undefined4 *)(iVar9 + 0x38);
                  if (*(int *)(iVar9 + 0x34) != 0) {
                    iVar18 = 0;
                    uVar4 = _gleVecAlloc(*(int *)(iVar9 + 0x34) * *(int *)(iVar9 + 0x38));
                    puVar5[6] = uVar4;
                    uVar4 = _gleVecAlloc(*(int *)(iVar9 + 0x34) << 2);
                    puVar5[7] = uVar4;
                    if (0 < *(int *)(iVar9 + 0x34)) {
                      do {
                        iVar6 = _ShGetActiveAttrib(*(undefined4 *)(iVar9 + 0x40),iVar18,
                                                   *(int *)(iVar9 + 0x38),auStack_50,auStack_4c,
                                                   auStack_48,
                                                   puVar5[6] + iVar18 * *(int *)(iVar9 + 0x38));
                        if (iVar6 == 0) {
                          *(undefined4 *)(iVar18 * 4 + puVar5[7]) = 0xffffffff;
                        }
                        else {
                          uVar4 = _ShGetAttribLocation
                                            (*(undefined4 *)(iVar9 + 0x40),
                                             puVar5[6] + iVar18 * *(int *)(iVar9 + 0x38));
                          *(undefined4 *)(iVar18 * 4 + puVar5[7]) = uVar4;
                        }
                        iVar18 = iVar18 + 1;
                      } while (iVar18 < *(int *)(iVar9 + 0x34));
                    }
                  }
                  pcVar16 = *(char **)(local_58[iVar14] + 0x2c);
                  if ((pcVar16 != (char *)0x0) && (*pcVar16 != '\0')) {
                    iVar18 = _strlen(pcVar16);
                    uVar4 = _gleVecAlloc(iVar18 + 1);
                    puVar5[8] = uVar4;
                    iVar18 = _strlen(pcVar16);
                    _strncpy((char *)puVar5[8],pcVar16,iVar18 + 1);
                  }
                  *(undefined4 **)(pcVar10 + 0x518) = puVar5;
                }
                iVar14 = iVar14 + 1;
              } while (iVar14 < 2);
            }
          }
          else if (bVar1) {
            bVar1 = true;
            do {
              iVar6 = *(int *)(iVar18 * 4 + *(int *)(iVar9 + 0x44));
              if (iVar6 != 0) {
                if ((local_58[0] == 0) && (*(int *)(iVar6 + 0x20) == 0x8b31)) {
                  local_58[0] = iVar6;
                }
                else {
                  if ((local_58[1] != 0) ||
                     (iVar6 = *(int *)(iVar18 * 4 + *(int *)(iVar9 + 0x44)),
                     *(code **)(iVar6 + 0x20) != (code *)0x8b30)) {
                    bVar1 = false;
                    goto LAB_00088784;
                  }
                  local_58[1] = iVar6;
                }
                iVar14 = *(int *)(iVar9 + 0x48);
              }
LAB_00088784:
              iVar18 = iVar18 + 1;
              if (iVar14 <= iVar18) goto LAB_0008879c;
            } while (bVar1);
          }
        }
        uVar4 = _ShGetInfoLog(*(undefined4 *)(iVar9 + 0x40));
        uVar4 = _strlen(uVar4);
        *(undefined4 *)(iVar9 + 0x1c) = uVar4;
        fparam_1 = extraout_f1;
        if (*(int *)(iVar9 + 0x18) != 0) {
          _free(*(int *)(iVar9 + 0x18));
          fparam_1 = extraout_f1_00;
        }
        *(undefined4 *)(iVar9 + 0x18) = 0;
        if (*(int *)(iVar9 + 0x1c) != 0) {
          iVar14 = _malloc(*(int *)(iVar9 + 0x1c) + 1);
          *(int *)(iVar9 + 0x18) = iVar14;
          fparam_1 = extraout_f1_01;
          if (iVar14 != 0) {
            pcVar10 = (char *)_ShGetInfoLog(*(undefined4 *)(iVar9 + 0x40));
            _strncpy(*(char **)(iVar9 + 0x18),pcVar10,*(size_t *)(iVar9 + 0x1c));
            fparam_1 = extraout_f1_02;
          }
        }
      }
      if (*(int *)(param_1 + 0x5430) == iVar9) {
        ((void (*)())_updateShaderState)(param_1,piVar15,(uint)*(byte *)(param_1 + 0x759c),(uint)bVar2,(uint)bVar3
                           ,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
      }
      iVar14 = 0;
      if (*(char *)(param_1 + 0x85a4) != '\0') {
        iVar18 = param_1 + 0x85a0;
        do {
          iVar6 = iVar14 * 4;
          iVar14 = iVar14 + 1;
          (**(code **)(*(int *)(iVar18 + 0x2e4) + 0x194))
                    (*(undefined4 *)(iVar18 + 0xc),*(undefined4 *)(iVar6 + *piVar15 + 0x4e4),1);
          piVar13 = (int *)(iVar18 + 0x2e4);
          puVar5 = (undefined4 *)(iVar18 + 0xc);
          iVar18 = iVar18 + 0x2e0;
          (**(code **)(*piVar13 + 0x194))
                    (*puVar5,*(undefined4 *)(iVar6 + *(int *)(iVar9 + 0x24) + 0x4e4),1);
        } while (iVar14 < (int)(uint)*(byte *)(param_1 + 0x85a4));
      }
LAB_00088b38:
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
  uVar4 = 0x502;
LAB_00088210:
  *(undefined4 *)(param_1 + 0x7574) = uVar4;
  return;
}

/* _glValidateProgramARB_Exec @ 0x88b68 (612 bytes) */
void _glValidateProgramARB_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar5 = 
  "Validation Failed: Sampler error:\n  Samplers of different types use the same texture image unit.\n   - or -\n  A sampler\'s texture unit is out of range (greater than max allowed or negative).\n"
  ;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    iVar2 = *(int *)(param_1 + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_unlock(iVar2 + 0x8028);
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
      goto LAB_00088c48;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b40) {
      *(undefined1 *)(iVar2 + 0x3d) = 1;
      if (*(char *)(iVar2 + 0x3c) == '\0') {
        *(undefined1 *)(iVar2 + 0x3d) = 0;
        iVar3 = _strlen("Validation Failed: Program is not successfully linked.\n");
        pcVar4 = (char *)_malloc(*(int *)(iVar2 + 0x1c) + iVar3 + 2);
        if (*(char **)(iVar2 + 0x18) == (char *)0x0) {
          _strcpy(pcVar4,"Validation Failed: Program is not successfully linked.\n");
          iVar3 = _strlen("Validation Failed: Program is not successfully linked.\n");
          pcVar4[iVar3] = '\0';
        }
        else {
          _strncpy(pcVar4,*(char **)(iVar2 + 0x18),*(size_t *)(iVar2 + 0x1c));
          pcVar4[*(int *)(iVar2 + 0x1c)] = '\n';
          _strcpy(pcVar4 + *(int *)(iVar2 + 0x1c) + 1,
                  "Validation Failed: Program is not successfully linked.\n");
          pcVar5 = "Validation Failed: Program is not successfully linked.\n";
LAB_00088d48:
          iVar3 = _strlen(pcVar5);
          pcVar4[*(int *)(iVar2 + 0x1c) + iVar3 + 1] = '\0';
          _free(*(undefined4 *)(iVar2 + 0x18));
        }
      }
      else {
        if (*(char *)(iVar2 + 0x3e) != '\0') goto LAB_00088d8c;
        *(undefined1 *)(iVar2 + 0x3d) = 0;
        iVar3 = _strlen(
                       "Validation Failed: Sampler error:\n  Samplers of different types use the same texture image unit.\n   - or -\n  A sampler\'s texture unit is out of range (greater than max allowed or negative).\n"
                       );
        pcVar4 = (char *)_malloc(*(int *)(iVar2 + 0x1c) + iVar3 + 2);
        if (*(char **)(iVar2 + 0x18) != (char *)0x0) {
          _strncpy(pcVar4,*(char **)(iVar2 + 0x18),*(size_t *)(iVar2 + 0x1c));
          pcVar4[*(int *)(iVar2 + 0x1c)] = '\n';
          _strcpy(pcVar4 + *(int *)(iVar2 + 0x1c) + 1,
                  "Validation Failed: Sampler error:\n  Samplers of different types use the same texture image unit.\n   - or -\n  A sampler\'s texture unit is out of range (greater than max allowed or negative).\n"
                 );
          goto LAB_00088d48;
        }
        _strcpy(pcVar4,
                "Validation Failed: Sampler error:\n  Samplers of different types use the same texture image unit.\n   - or -\n  A sampler\'s texture unit is out of range (greater than max allowed or negative).\n"
               );
        iVar3 = _strlen(
                       "Validation Failed: Sampler error:\n  Samplers of different types use the same texture image unit.\n   - or -\n  A sampler\'s texture unit is out of range (greater than max allowed or negative).\n"
                       );
        pcVar4[iVar3] = '\0';
      }
      *(char **)(iVar2 + 0x18) = pcVar4;
      uVar1 = _strlen(pcVar4);
      *(undefined4 *)(iVar2 + 0x1c) = uVar1;
LAB_00088d8c:
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
LAB_00088c48:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glUniform4fARB_Exec @ 0x88dcc (716 bytes) */
void _glUniform4fARB_Exec(int param_1,int param_2,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 local_50;
  int local_4c;
  undefined2 local_48 [4];
  
  local_48[0] = 0;
  local_4c = 0;
  local_50 = 0;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar4 = *(int *)(param_1 + 0x5430), iVar4 != 0)) &&
        (param_2 < *(int *)(iVar4 + 0x30))) &&
       ((iVar5 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(iVar4 + 0x40),param_2,&local_50,&local_4c,local_48),
        iVar5 != 0 && ((local_4c == 0x8b52 || (local_4c == 0x8b59)))))) {
      if (local_4c == 0x8b52) {
        iVar5 = *(int *)(iVar4 + 0x4c) + param_2 * 0x10;
        *(float *)(*(int *)(iVar4 + 0x4c) + param_2 * 0x10) = (float)fparam_1;
        *(float *)(iVar5 + 0xc) = (float)fparam_4;
        *(float *)(iVar5 + 4) = (float)fparam_2;
        *(float *)(iVar5 + 8) = (float)fparam_3;
      }
      else {
        iVar5 = *(int *)(iVar4 + 0x4c) + param_2 * 0x10;
        *(uint *)(*(int *)(iVar4 + 0x4c) + param_2 * 0x10) =
             (uint)(fparam_1 != (double)FLOAT_00108e50);
        *(uint *)(iVar5 + 4) = (uint)(fparam_2 != (double)FLOAT_00108e50);
        *(uint *)(iVar5 + 8) = (uint)(fparam_3 != (double)FLOAT_00108e50);
        *(uint *)(iVar5 + 0xc) = (uint)(fparam_4 != (double)FLOAT_00108e50);
      }
      iVar11 = param_2 * 0x10;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
      iVar8 = *(int *)(iVar4 + 0x20);
      iVar5 = *(int *)(param_2 * 4 + *(int *)(iVar8 + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar7 = *(int *)(iVar8 + 0x51c);
        iVar12 = param_1 + 0x10000;
        iVar9 = iVar11 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar9 + 4);
        iVar8 = iVar5 + iVar7;
        uVar6 = *(undefined4 *)(iVar9 + 0xc);
        iVar13 = 0;
        uVar10 = *(undefined4 *)(iVar9 + 8);
        *(undefined4 *)(iVar5 + iVar7) = *(undefined4 *)(iVar11 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar8 + 0xc) = uVar6;
        *(undefined4 *)(iVar8 + 4) = uVar3;
        *(undefined4 *)(iVar8 + 8) = uVar10;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar12 + -0x777c);
            iVar5 = iVar13 * 4;
            iVar13 = iVar13 + 1;
            puVar2 = (undefined4 *)(iVar12 + -0x7a54);
            iVar12 = iVar12 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar4 + 0x20) + 0x4e4),2);
          } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      iVar5 = *(int *)(param_2 * 4 + *(int *)(*(int *)(iVar4 + 0x24) + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar7 = *(int *)(*(int *)(iVar4 + 0x24) + 0x51c);
        iVar13 = param_1 + 0x10000;
        iVar9 = iVar11 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar9 + 4);
        iVar8 = iVar5 + iVar7;
        uVar6 = *(undefined4 *)(iVar9 + 0xc);
        iVar12 = 0;
        uVar10 = *(undefined4 *)(iVar9 + 8);
        *(undefined4 *)(iVar5 + iVar7) = *(undefined4 *)(iVar11 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar8 + 0xc) = uVar6;
        *(undefined4 *)(iVar8 + 4) = uVar3;
        *(undefined4 *)(iVar8 + 8) = uVar10;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar13 + -0x777c);
            iVar5 = iVar12 * 4;
            iVar12 = iVar12 + 1;
            puVar2 = (undefined4 *)(iVar13 + -0x7a54);
            iVar13 = iVar13 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar4 + 0x24) + 0x4e4),2);
          } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform3fARB_Exec @ 0x89098 (712 bytes) */
void _glUniform3fARB_Exec(int param_1,int param_2,float fparam_1,float fparam_2,float fparam_3)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 local_50;
  int local_4c;
  undefined2 local_48 [8];
  
  local_48[0] = 0;
  local_4c = 0;
  local_50 = 0;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar4 = *(int *)(param_1 + 0x5430), iVar4 != 0)) &&
        (param_2 < *(int *)(iVar4 + 0x30))) &&
       ((iVar5 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(iVar4 + 0x40),param_2,&local_50,&local_4c,local_48),
        iVar5 != 0 && ((local_4c == 0x8b51 || (local_4c == 0x8b58)))))) {
      if (local_4c == 0x8b51) {
        iVar5 = *(int *)(iVar4 + 0x4c) + param_2 * 0x10;
        *(float *)(*(int *)(iVar4 + 0x4c) + param_2 * 0x10) = (float)fparam_1;
        *(float *)(iVar5 + 8) = (float)fparam_3;
        *(float *)(iVar5 + 4) = (float)fparam_2;
      }
      else {
        iVar5 = *(int *)(iVar4 + 0x4c) + param_2 * 0x10;
        *(uint *)(*(int *)(iVar4 + 0x4c) + param_2 * 0x10) =
             (uint)(fparam_1 != (double)FLOAT_00108e50);
        *(uint *)(iVar5 + 4) = (uint)(fparam_2 != (double)FLOAT_00108e50);
        *(uint *)(iVar5 + 8) = (uint)(fparam_3 != (double)FLOAT_00108e50);
      }
      iVar11 = param_2 * 0x10;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
      iVar8 = *(int *)(iVar4 + 0x20);
      iVar5 = *(int *)(param_2 * 4 + *(int *)(iVar8 + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar7 = *(int *)(iVar8 + 0x51c);
        iVar12 = param_1 + 0x10000;
        iVar9 = iVar11 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar9 + 4);
        iVar8 = iVar5 + iVar7;
        uVar6 = *(undefined4 *)(iVar9 + 0xc);
        iVar13 = 0;
        uVar10 = *(undefined4 *)(iVar9 + 8);
        *(undefined4 *)(iVar5 + iVar7) = *(undefined4 *)(iVar11 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar8 + 0xc) = uVar6;
        *(undefined4 *)(iVar8 + 4) = uVar3;
        *(undefined4 *)(iVar8 + 8) = uVar10;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar12 + -0x777c);
            iVar5 = iVar13 * 4;
            iVar13 = iVar13 + 1;
            puVar2 = (undefined4 *)(iVar12 + -0x7a54);
            iVar12 = iVar12 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar4 + 0x20) + 0x4e4),2);
          } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      iVar5 = *(int *)(param_2 * 4 + *(int *)(*(int *)(iVar4 + 0x24) + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar7 = *(int *)(*(int *)(iVar4 + 0x24) + 0x51c);
        iVar13 = param_1 + 0x10000;
        iVar9 = iVar11 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar9 + 4);
        iVar8 = iVar5 + iVar7;
        uVar6 = *(undefined4 *)(iVar9 + 0xc);
        iVar12 = 0;
        uVar10 = *(undefined4 *)(iVar9 + 8);
        *(undefined4 *)(iVar5 + iVar7) = *(undefined4 *)(iVar11 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar8 + 0xc) = uVar6;
        *(undefined4 *)(iVar8 + 4) = uVar3;
        *(undefined4 *)(iVar8 + 8) = uVar10;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar13 + -0x777c);
            iVar5 = iVar12 * 4;
            iVar12 = iVar12 + 1;
            puVar2 = (undefined4 *)(iVar13 + -0x7a54);
            iVar13 = iVar13 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar4 + 0x24) + 0x4e4),2);
          } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform2fARB_Exec @ 0x89360 (668 bytes) */
void _glUniform2fARB_Exec(int param_1,int param_2,float fparam_1,float fparam_2)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 local_40;
  int local_3c;
  undefined2 local_38 [4];
  
  local_38[0] = 0;
  local_3c = 0;
  local_40 = 0;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar4 = *(int *)(param_1 + 0x5430), iVar4 != 0)) &&
        (param_2 < *(int *)(iVar4 + 0x30))) &&
       ((iVar5 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(iVar4 + 0x40),param_2,&local_40,&local_3c,local_38),
        iVar5 != 0 && ((local_3c == 0x8b50 || (local_3c == 0x8b57)))))) {
      if (local_3c == 0x8b50) {
        iVar5 = *(int *)(iVar4 + 0x4c);
        *(float *)(iVar5 + param_2 * 0x10) = (float)fparam_1;
        *(float *)(iVar5 + param_2 * 0x10 + 4) = (float)fparam_2;
      }
      else {
        iVar5 = *(int *)(iVar4 + 0x4c);
        *(uint *)(iVar5 + param_2 * 0x10) = (uint)(fparam_1 != (double)FLOAT_00108e50);
        *(uint *)(iVar5 + param_2 * 0x10 + 4) = (uint)(fparam_2 != (double)FLOAT_00108e50);
      }
      iVar11 = param_2 * 0x10;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
      iVar8 = *(int *)(iVar4 + 0x20);
      iVar5 = *(int *)(param_2 * 4 + *(int *)(iVar8 + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar7 = *(int *)(iVar8 + 0x51c);
        iVar12 = param_1 + 0x10000;
        iVar9 = iVar11 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar9 + 4);
        iVar8 = iVar5 + iVar7;
        uVar6 = *(undefined4 *)(iVar9 + 0xc);
        iVar13 = 0;
        uVar10 = *(undefined4 *)(iVar9 + 8);
        *(undefined4 *)(iVar5 + iVar7) = *(undefined4 *)(iVar11 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar8 + 0xc) = uVar6;
        *(undefined4 *)(iVar8 + 4) = uVar3;
        *(undefined4 *)(iVar8 + 8) = uVar10;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar12 + -0x777c);
            iVar5 = iVar13 * 4;
            iVar13 = iVar13 + 1;
            puVar2 = (undefined4 *)(iVar12 + -0x7a54);
            iVar12 = iVar12 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar4 + 0x20) + 0x4e4),2);
          } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      iVar5 = *(int *)(param_2 * 4 + *(int *)(*(int *)(iVar4 + 0x24) + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar7 = *(int *)(*(int *)(iVar4 + 0x24) + 0x51c);
        iVar13 = param_1 + 0x10000;
        iVar9 = iVar11 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar9 + 4);
        iVar8 = iVar5 + iVar7;
        uVar6 = *(undefined4 *)(iVar9 + 0xc);
        iVar12 = 0;
        uVar10 = *(undefined4 *)(iVar9 + 8);
        *(undefined4 *)(iVar5 + iVar7) = *(undefined4 *)(iVar11 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar8 + 0xc) = uVar6;
        *(undefined4 *)(iVar8 + 4) = uVar3;
        *(undefined4 *)(iVar8 + 8) = uVar10;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar13 + -0x777c);
            iVar5 = iVar12 * 4;
            iVar12 = iVar12 + 1;
            puVar2 = (undefined4 *)(iVar13 + -0x7a54);
            iVar13 = iVar13 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar4 + 0x24) + 0x4e4),2);
          } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform1fARB_Exec @ 0x895fc (600 bytes) */
void _glUniform1fARB_Exec(int param_1,int param_2,float fparam_1)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 local_40;
  int local_3c;
  undefined2 local_38 [8];
  
  local_38[0] = 0;
  local_3c = 0;
  local_40 = 0;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar4 = *(int *)(param_1 + 0x5430), iVar4 != 0)) &&
        (param_2 < *(int *)(iVar4 + 0x30))) &&
       ((iVar5 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(iVar4 + 0x40),param_2,&local_40,&local_3c,local_38),
        iVar5 != 0 && ((local_3c == 0x1406 || (local_3c == 0x8b56)))))) {
      if (local_3c == 0x1406) {
        *(float *)(*(int *)(iVar4 + 0x4c) + param_2 * 0x10) = (float)fparam_1;
      }
      else {
        *(uint *)(*(int *)(iVar4 + 0x4c) + param_2 * 0x10) =
             (uint)(fparam_1 != (double)FLOAT_00108e50);
      }
      iVar11 = param_2 * 0x10;
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
      iVar8 = *(int *)(iVar4 + 0x20);
      iVar5 = *(int *)(param_2 * 4 + *(int *)(iVar8 + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar7 = *(int *)(iVar8 + 0x51c);
        iVar12 = param_1 + 0x10000;
        iVar9 = iVar11 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar9 + 4);
        iVar8 = iVar5 + iVar7;
        uVar6 = *(undefined4 *)(iVar9 + 0xc);
        iVar13 = 0;
        uVar10 = *(undefined4 *)(iVar9 + 8);
        *(undefined4 *)(iVar5 + iVar7) = *(undefined4 *)(iVar11 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar8 + 0xc) = uVar6;
        *(undefined4 *)(iVar8 + 4) = uVar3;
        *(undefined4 *)(iVar8 + 8) = uVar10;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar12 + -0x777c);
            iVar5 = iVar13 * 4;
            iVar13 = iVar13 + 1;
            puVar2 = (undefined4 *)(iVar12 + -0x7a54);
            iVar12 = iVar12 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar4 + 0x20) + 0x4e4),2);
          } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      iVar5 = *(int *)(param_2 * 4 + *(int *)(*(int *)(iVar4 + 0x24) + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar7 = *(int *)(*(int *)(iVar4 + 0x24) + 0x51c);
        iVar13 = param_1 + 0x10000;
        iVar9 = iVar11 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar9 + 4);
        iVar8 = iVar5 + iVar7;
        uVar6 = *(undefined4 *)(iVar9 + 0xc);
        iVar12 = 0;
        uVar10 = *(undefined4 *)(iVar9 + 8);
        *(undefined4 *)(iVar5 + iVar7) = *(undefined4 *)(iVar11 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar8 + 0xc) = uVar6;
        *(undefined4 *)(iVar8 + 4) = uVar3;
        *(undefined4 *)(iVar8 + 8) = uVar10;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar13 + -0x777c);
            iVar5 = iVar12 * 4;
            iVar12 = iVar12 + 1;
            puVar2 = (undefined4 *)(iVar13 + -0x7a54);
            iVar13 = iVar13 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar4 + 0x24) + 0x4e4),2);
          } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform4fvARB_Exec @ 0x89854 (924 bytes) */
void _glUniform4fvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  float *param_4;
{
  float *pfVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  float *pfVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  int local_30;
  int local_2c;
  undefined2 local_28 [4];
  
  local_2c = 0;
  local_28[0] = 0;
  local_30 = 0;
  bVar3 = false;
  bVar4 = false;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar7 = *(int *)(param_1 + 0x5430), iVar7 != 0)) &&
        (param_2 < *(int *)(iVar7 + 0x30))) &&
       (((-1 < param_3 &&
         (iVar10 = _ShGetUniformTypeInfo
                             (*(undefined4 *)(iVar7 + 0x40),param_2,&local_30,&local_2c,local_28),
         fVar5 = FLOAT_00108e50, iVar10 != 0)) && ((local_2c == 0x8b52 || (local_2c == 0x8b59))))))
    {
      if (param_3 != 0) {
        if (param_3 < local_30) {
          local_30 = param_3;
        }
        if (local_2c == 0x8b52) {
          iVar10 = 0;
          pfVar8 = (float *)(*(int *)(iVar7 + 0x4c) + param_2 * 0x10);
          if (0 < local_30) {
            do {
              iVar10 = iVar10 + 1;
              *pfVar8 = *param_4;
              pfVar8[1] = param_4[1];
              pfVar8[2] = param_4[2];
              pfVar1 = param_4 + 3;
              param_4 = param_4 + 4;
              pfVar8[3] = *pfVar1;
              pfVar8 = pfVar8 + 4;
            } while (iVar10 < local_30);
          }
        }
        else {
          iVar10 = 0;
          puVar9 = (undefined4 *)(*(int *)(iVar7 + 0x4c) + param_2 * 0x10);
          if (0 < local_30) {
            do {
              if (*param_4 == fVar5) {
                *puVar9 = 0;
              }
              else {
                *puVar9 = 1;
              }
              if (param_4[1] == fVar5) {
                puVar9[1] = 0;
              }
              else {
                puVar9[1] = 1;
              }
              if (param_4[2] == fVar5) {
                puVar9[2] = 0;
              }
              else {
                puVar9[2] = 1;
              }
              if (param_4[3] == fVar5) {
                puVar9[3] = 0;
              }
              else {
                puVar9[3] = 1;
              }
              iVar10 = iVar10 + 1;
              puVar9 = puVar9 + 4;
              param_4 = param_4 + 4;
            } while (iVar10 < local_30);
          }
        }
        iVar10 = 0;
        if (0 < local_30) {
          iVar12 = param_2 << 2;
          iVar11 = param_2 << 4;
          do {
            iVar15 = *(int *)(iVar7 + 0x20);
            iVar18 = *(int *)(iVar12 + *(int *)(iVar15 + 0x4e0));
            if (iVar18 != -1) {
              iVar18 = iVar18 * 0x10;
              iVar14 = *(int *)(iVar15 + 0x51c);
              bVar3 = true;
              iVar16 = iVar11 + *(int *)(iVar7 + 0x4c);
              uVar13 = *(undefined4 *)(iVar16 + 0xc);
              iVar15 = iVar18 + iVar14;
              uVar6 = *(undefined4 *)(iVar16 + 4);
              uVar17 = *(undefined4 *)(iVar16 + 8);
              *(undefined4 *)(iVar18 + iVar14) = *(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x4c));
              *(undefined4 *)(iVar15 + 0xc) = uVar13;
              *(undefined4 *)(iVar15 + 4) = uVar6;
              *(undefined4 *)(iVar15 + 8) = uVar17;
            }
            iVar18 = *(int *)(iVar12 + *(int *)(*(int *)(iVar7 + 0x24) + 0x4e0));
            if (iVar18 != -1) {
              iVar18 = iVar18 * 0x10;
              iVar14 = *(int *)(*(int *)(iVar7 + 0x24) + 0x51c);
              bVar4 = true;
              iVar16 = iVar11 + *(int *)(iVar7 + 0x4c);
              uVar13 = *(undefined4 *)(iVar16 + 0xc);
              iVar15 = iVar18 + iVar14;
              uVar6 = *(undefined4 *)(iVar16 + 4);
              uVar17 = *(undefined4 *)(iVar16 + 8);
              *(undefined4 *)(iVar18 + iVar14) = *(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x4c));
              *(undefined4 *)(iVar15 + 0xc) = uVar13;
              *(undefined4 *)(iVar15 + 4) = uVar6;
              *(undefined4 *)(iVar15 + 8) = uVar17;
            }
            iVar10 = iVar10 + 1;
            iVar12 = iVar12 + 4;
            iVar11 = iVar11 + 0x10;
          } while (iVar10 < local_30);
        }
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
        if (bVar3) {
          iVar10 = param_1 + 0x10000;
          iVar12 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar2 = (int *)(iVar10 + -0x777c);
              iVar11 = iVar12 * 4;
              iVar12 = iVar12 + 1;
              puVar9 = (undefined4 *)(iVar10 + -0x7a54);
              iVar10 = iVar10 + 0x2e0;
              (**(code **)(*piVar2 + 0x194))
                        (*puVar9,*(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x20) + 0x4e4),2);
            } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
        if (bVar4) {
          iVar10 = param_1 + 0x10000;
          iVar12 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar2 = (int *)(iVar10 + -0x777c);
              iVar11 = iVar12 * 4;
              iVar12 = iVar12 + 1;
              puVar9 = (undefined4 *)(iVar10 + -0x7a54);
              iVar10 = iVar10 + 0x2e0;
              (**(code **)(*piVar2 + 0x194))
                        (*puVar9,*(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x24) + 0x4e4),2);
            } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform3fvARB_Exec @ 0x89bf0 (892 bytes) */
void _glUniform3fvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  float *param_4;
{
  float *pfVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  float *pfVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  int local_30;
  int local_2c;
  undefined2 local_28 [4];
  
  local_2c = 0;
  local_28[0] = 0;
  local_30 = 0;
  bVar3 = false;
  bVar4 = false;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar7 = *(int *)(param_1 + 0x5430), iVar7 != 0)) &&
        (param_2 < *(int *)(iVar7 + 0x30))) &&
       (((-1 < param_3 &&
         (iVar10 = _ShGetUniformTypeInfo
                             (*(undefined4 *)(iVar7 + 0x40),param_2,&local_30,&local_2c,local_28),
         fVar5 = FLOAT_00108e50, iVar10 != 0)) && ((local_2c == 0x8b51 || (local_2c == 0x8b58))))))
    {
      if (param_3 != 0) {
        if (param_3 < local_30) {
          local_30 = param_3;
        }
        if (local_2c == 0x8b51) {
          iVar10 = 0;
          pfVar8 = (float *)(*(int *)(iVar7 + 0x4c) + param_2 * 0x10);
          if (0 < local_30) {
            do {
              iVar10 = iVar10 + 1;
              *pfVar8 = *param_4;
              pfVar8[1] = param_4[1];
              pfVar1 = param_4 + 2;
              param_4 = param_4 + 3;
              pfVar8[2] = *pfVar1;
              pfVar8 = pfVar8 + 4;
            } while (iVar10 < local_30);
          }
        }
        else {
          iVar10 = 0;
          puVar9 = (undefined4 *)(*(int *)(iVar7 + 0x4c) + param_2 * 0x10);
          if (0 < local_30) {
            do {
              if (*param_4 == fVar5) {
                *puVar9 = 0;
              }
              else {
                *puVar9 = 1;
              }
              if (param_4[1] == fVar5) {
                puVar9[1] = 0;
              }
              else {
                puVar9[1] = 1;
              }
              if (param_4[2] == fVar5) {
                puVar9[2] = 0;
              }
              else {
                puVar9[2] = 1;
              }
              iVar10 = iVar10 + 1;
              puVar9 = puVar9 + 4;
              param_4 = param_4 + 3;
            } while (iVar10 < local_30);
          }
        }
        iVar10 = 0;
        if (0 < local_30) {
          iVar12 = param_2 << 2;
          iVar11 = param_2 << 4;
          do {
            iVar15 = *(int *)(iVar7 + 0x20);
            iVar18 = *(int *)(iVar12 + *(int *)(iVar15 + 0x4e0));
            if (iVar18 != -1) {
              iVar18 = iVar18 * 0x10;
              iVar14 = *(int *)(iVar15 + 0x51c);
              bVar3 = true;
              iVar16 = iVar11 + *(int *)(iVar7 + 0x4c);
              uVar13 = *(undefined4 *)(iVar16 + 0xc);
              iVar15 = iVar18 + iVar14;
              uVar6 = *(undefined4 *)(iVar16 + 4);
              uVar17 = *(undefined4 *)(iVar16 + 8);
              *(undefined4 *)(iVar18 + iVar14) = *(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x4c));
              *(undefined4 *)(iVar15 + 0xc) = uVar13;
              *(undefined4 *)(iVar15 + 4) = uVar6;
              *(undefined4 *)(iVar15 + 8) = uVar17;
            }
            iVar18 = *(int *)(iVar12 + *(int *)(*(int *)(iVar7 + 0x24) + 0x4e0));
            if (iVar18 != -1) {
              iVar18 = iVar18 * 0x10;
              iVar14 = *(int *)(*(int *)(iVar7 + 0x24) + 0x51c);
              bVar4 = true;
              iVar16 = iVar11 + *(int *)(iVar7 + 0x4c);
              uVar13 = *(undefined4 *)(iVar16 + 0xc);
              iVar15 = iVar18 + iVar14;
              uVar6 = *(undefined4 *)(iVar16 + 4);
              uVar17 = *(undefined4 *)(iVar16 + 8);
              *(undefined4 *)(iVar18 + iVar14) = *(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x4c));
              *(undefined4 *)(iVar15 + 0xc) = uVar13;
              *(undefined4 *)(iVar15 + 4) = uVar6;
              *(undefined4 *)(iVar15 + 8) = uVar17;
            }
            iVar10 = iVar10 + 1;
            iVar12 = iVar12 + 4;
            iVar11 = iVar11 + 0x10;
          } while (iVar10 < local_30);
        }
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
        if (bVar3) {
          iVar10 = param_1 + 0x10000;
          iVar12 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar2 = (int *)(iVar10 + -0x777c);
              iVar11 = iVar12 * 4;
              iVar12 = iVar12 + 1;
              puVar9 = (undefined4 *)(iVar10 + -0x7a54);
              iVar10 = iVar10 + 0x2e0;
              (**(code **)(*piVar2 + 0x194))
                        (*puVar9,*(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x20) + 0x4e4),2);
            } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
        if (bVar4) {
          iVar10 = param_1 + 0x10000;
          iVar12 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar2 = (int *)(iVar10 + -0x777c);
              iVar11 = iVar12 * 4;
              iVar12 = iVar12 + 1;
              puVar9 = (undefined4 *)(iVar10 + -0x7a54);
              iVar10 = iVar10 + 0x2e0;
              (**(code **)(*piVar2 + 0x194))
                        (*puVar9,*(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x24) + 0x4e4),2);
            } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform2fvARB_Exec @ 0x89f6c (860 bytes) */
void _glUniform2fvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  float *param_4;
{
  float *pfVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  float fVar5;
  undefined4 uVar6;
  int iVar7;
  float *pfVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  int local_30;
  int local_2c;
  undefined2 local_28 [4];
  
  local_2c = 0;
  local_28[0] = 0;
  local_30 = 0;
  bVar3 = false;
  bVar4 = false;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar7 = *(int *)(param_1 + 0x5430), iVar7 != 0)) &&
        (param_2 < *(int *)(iVar7 + 0x30))) &&
       (((-1 < param_3 &&
         (iVar10 = _ShGetUniformTypeInfo
                             (*(undefined4 *)(iVar7 + 0x40),param_2,&local_30,&local_2c,local_28),
         fVar5 = FLOAT_00108e50, iVar10 != 0)) && ((local_2c == 0x8b50 || (local_2c == 0x8b57))))))
    {
      if (param_3 != 0) {
        if (param_3 < local_30) {
          local_30 = param_3;
        }
        if (local_2c == 0x8b50) {
          iVar10 = 0;
          pfVar8 = (float *)(*(int *)(iVar7 + 0x4c) + param_2 * 0x10);
          if (0 < local_30) {
            do {
              iVar10 = iVar10 + 1;
              *pfVar8 = *param_4;
              pfVar1 = param_4 + 1;
              param_4 = param_4 + 2;
              pfVar8[1] = *pfVar1;
              pfVar8 = pfVar8 + 4;
            } while (iVar10 < local_30);
          }
        }
        else {
          iVar10 = 0;
          puVar9 = (undefined4 *)(*(int *)(iVar7 + 0x4c) + param_2 * 0x10);
          if (0 < local_30) {
            do {
              if (*param_4 == fVar5) {
                *puVar9 = 0;
              }
              else {
                *puVar9 = 1;
              }
              if (param_4[1] == fVar5) {
                puVar9[1] = 0;
              }
              else {
                puVar9[1] = 1;
              }
              iVar10 = iVar10 + 1;
              puVar9 = puVar9 + 4;
              param_4 = param_4 + 2;
            } while (iVar10 < local_30);
          }
        }
        iVar10 = 0;
        if (0 < local_30) {
          iVar12 = param_2 << 2;
          iVar11 = param_2 << 4;
          do {
            iVar15 = *(int *)(iVar7 + 0x20);
            iVar18 = *(int *)(iVar12 + *(int *)(iVar15 + 0x4e0));
            if (iVar18 != -1) {
              iVar18 = iVar18 * 0x10;
              iVar14 = *(int *)(iVar15 + 0x51c);
              bVar3 = true;
              iVar16 = iVar11 + *(int *)(iVar7 + 0x4c);
              uVar13 = *(undefined4 *)(iVar16 + 0xc);
              iVar15 = iVar18 + iVar14;
              uVar6 = *(undefined4 *)(iVar16 + 4);
              uVar17 = *(undefined4 *)(iVar16 + 8);
              *(undefined4 *)(iVar18 + iVar14) = *(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x4c));
              *(undefined4 *)(iVar15 + 0xc) = uVar13;
              *(undefined4 *)(iVar15 + 4) = uVar6;
              *(undefined4 *)(iVar15 + 8) = uVar17;
            }
            iVar18 = *(int *)(iVar12 + *(int *)(*(int *)(iVar7 + 0x24) + 0x4e0));
            if (iVar18 != -1) {
              iVar18 = iVar18 * 0x10;
              iVar14 = *(int *)(*(int *)(iVar7 + 0x24) + 0x51c);
              bVar4 = true;
              iVar16 = iVar11 + *(int *)(iVar7 + 0x4c);
              uVar13 = *(undefined4 *)(iVar16 + 0xc);
              iVar15 = iVar18 + iVar14;
              uVar6 = *(undefined4 *)(iVar16 + 4);
              uVar17 = *(undefined4 *)(iVar16 + 8);
              *(undefined4 *)(iVar18 + iVar14) = *(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x4c));
              *(undefined4 *)(iVar15 + 0xc) = uVar13;
              *(undefined4 *)(iVar15 + 4) = uVar6;
              *(undefined4 *)(iVar15 + 8) = uVar17;
            }
            iVar10 = iVar10 + 1;
            iVar12 = iVar12 + 4;
            iVar11 = iVar11 + 0x10;
          } while (iVar10 < local_30);
        }
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
        if (bVar3) {
          iVar10 = param_1 + 0x10000;
          iVar12 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar2 = (int *)(iVar10 + -0x777c);
              iVar11 = iVar12 * 4;
              iVar12 = iVar12 + 1;
              puVar9 = (undefined4 *)(iVar10 + -0x7a54);
              iVar10 = iVar10 + 0x2e0;
              (**(code **)(*piVar2 + 0x194))
                        (*puVar9,*(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x20) + 0x4e4),2);
            } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
        if (bVar4) {
          iVar10 = param_1 + 0x10000;
          iVar12 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar2 = (int *)(iVar10 + -0x777c);
              iVar11 = iVar12 * 4;
              iVar12 = iVar12 + 1;
              puVar9 = (undefined4 *)(iVar10 + -0x7a54);
              iVar10 = iVar10 + 0x2e0;
              (**(code **)(*piVar2 + 0x194))
                        (*puVar9,*(undefined4 *)(iVar11 + *(int *)(iVar7 + 0x24) + 0x4e4),2);
            } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform1fvARB_Exec @ 0x8a2c8 (812 bytes) */
void _glUniform1fvARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  float *param_4;
{
  int *piVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  float *pfVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 uVar16;
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
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar6 = *(int *)(param_1 + 0x5430), iVar6 != 0)) &&
        (param_2 < *(int *)(iVar6 + 0x30))) &&
       (((-1 < param_3 &&
         (iVar9 = _ShGetUniformTypeInfo
                            (*(undefined4 *)(iVar6 + 0x40),param_2,&local_40,&local_3c,local_38),
         fVar2 = FLOAT_00108e50, iVar9 != 0)) && ((local_3c == 0x1406 || (local_3c == 0x8b56)))))) {
      if (param_3 != 0) {
        if (param_3 < local_40) {
          local_40 = param_3;
        }
        if (local_3c == 0x1406) {
          iVar9 = 0;
          pfVar7 = (float *)(*(int *)(iVar6 + 0x4c) + param_2 * 0x10);
          if (0 < local_40) {
            do {
              fVar2 = *param_4;
              iVar9 = iVar9 + 1;
              param_4 = param_4 + 1;
              *pfVar7 = fVar2;
              pfVar7 = pfVar7 + 4;
            } while (iVar9 < local_40);
          }
        }
        else {
          iVar9 = 0;
          puVar8 = (undefined4 *)(*(int *)(iVar6 + 0x4c) + param_2 * 0x10);
          if (0 < local_40) {
            do {
              if (*param_4 == fVar2) {
                *puVar8 = 0;
              }
              else {
                *puVar8 = 1;
              }
              iVar9 = iVar9 + 1;
              puVar8 = puVar8 + 4;
              param_4 = param_4 + 1;
            } while (iVar9 < local_40);
          }
        }
        iVar9 = 0;
        if (0 < local_40) {
          iVar11 = param_2 << 2;
          iVar10 = param_2 << 4;
          do {
            iVar14 = *(int *)(iVar6 + 0x20);
            iVar17 = *(int *)(iVar11 + *(int *)(iVar14 + 0x4e0));
            if (iVar17 != -1) {
              iVar17 = iVar17 * 0x10;
              iVar13 = *(int *)(iVar14 + 0x51c);
              bVar3 = true;
              iVar15 = iVar10 + *(int *)(iVar6 + 0x4c);
              uVar12 = *(undefined4 *)(iVar15 + 0xc);
              iVar14 = iVar17 + iVar13;
              uVar5 = *(undefined4 *)(iVar15 + 4);
              uVar16 = *(undefined4 *)(iVar15 + 8);
              *(undefined4 *)(iVar17 + iVar13) = *(undefined4 *)(iVar10 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar14 + 0xc) = uVar12;
              *(undefined4 *)(iVar14 + 4) = uVar5;
              *(undefined4 *)(iVar14 + 8) = uVar16;
            }
            iVar17 = *(int *)(iVar11 + *(int *)(*(int *)(iVar6 + 0x24) + 0x4e0));
            if (iVar17 != -1) {
              iVar17 = iVar17 * 0x10;
              iVar13 = *(int *)(*(int *)(iVar6 + 0x24) + 0x51c);
              bVar4 = true;
              iVar15 = iVar10 + *(int *)(iVar6 + 0x4c);
              uVar12 = *(undefined4 *)(iVar15 + 0xc);
              iVar14 = iVar17 + iVar13;
              uVar5 = *(undefined4 *)(iVar15 + 4);
              uVar16 = *(undefined4 *)(iVar15 + 8);
              *(undefined4 *)(iVar17 + iVar13) = *(undefined4 *)(iVar10 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar14 + 0xc) = uVar12;
              *(undefined4 *)(iVar14 + 4) = uVar5;
              *(undefined4 *)(iVar14 + 8) = uVar16;
            }
            iVar9 = iVar9 + 1;
            iVar11 = iVar11 + 4;
            iVar10 = iVar10 + 0x10;
          } while (iVar9 < local_40);
        }
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
        if (bVar3) {
          iVar11 = param_1 + 0x10000;
          iVar9 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar1 = (int *)(iVar11 + -0x777c);
              iVar10 = iVar9 * 4;
              iVar9 = iVar9 + 1;
              puVar8 = (undefined4 *)(iVar11 + -0x7a54);
              iVar11 = iVar11 + 0x2e0;
              (**(code **)(*piVar1 + 0x194))
                        (*puVar8,*(undefined4 *)(iVar10 + *(int *)(iVar6 + 0x20) + 0x4e4),2);
            } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
        if (bVar4) {
          iVar11 = param_1 + 0x10000;
          iVar9 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar1 = (int *)(iVar11 + -0x777c);
              iVar10 = iVar9 * 4;
              iVar9 = iVar9 + 1;
              puVar8 = (undefined4 *)(iVar11 + -0x7a54);
              iVar11 = iVar11 + 0x2e0;
              (**(code **)(*piVar1 + 0x194))
                        (*puVar8,*(undefined4 *)(iVar10 + *(int *)(iVar6 + 0x24) + 0x4e4),2);
            } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform4iARB_Exec @ 0x8a5f4 (684 bytes) */
void _glUniform4iARB_Exec(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 local_40;
  int local_3c;
  undefined2 local_38 [10];
  
  local_38[0] = 0;
  local_3c = 0;
  local_40 = 0;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar4 = *(int *)(param_1 + 0x5430), iVar4 != 0)) &&
        (param_2 < *(int *)(iVar4 + 0x30))) &&
       ((iVar6 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(iVar4 + 0x40),param_2,&local_40,&local_3c,local_38),
        iVar6 != 0 && ((local_3c == 0x8b55 || (local_3c == 0x8b59)))))) {
      iVar6 = param_2 * 0x10;
      iVar5 = *(int *)(iVar4 + 0x4c);
      iVar9 = iVar5 + iVar6;
      if (local_3c == 0x8b55) {
        *(int *)(iVar5 + iVar6) = param_3;
        *(int *)(iVar9 + 0xc) = param_6;
        *(int *)(iVar9 + 4) = param_4;
        *(int *)(iVar9 + 8) = param_5;
      }
      else {
        if (param_3 == 0) {
          *(undefined4 *)(iVar5 + iVar6) = 0;
        }
        else {
          *(undefined4 *)(iVar5 + iVar6) = 1;
        }
        if (param_4 == 0) {
          *(undefined4 *)(iVar9 + 4) = 0;
        }
        else {
          *(undefined4 *)(iVar9 + 4) = 1;
        }
        if (param_5 == 0) {
          *(undefined4 *)(iVar9 + 8) = 0;
        }
        else {
          *(undefined4 *)(iVar9 + 8) = 1;
        }
        if (param_6 == 0) {
          *(undefined4 *)(iVar9 + 0xc) = 0;
        }
        else {
          *(undefined4 *)(iVar9 + 0xc) = 1;
        }
      }
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
      iVar9 = *(int *)(iVar4 + 0x20);
      iVar5 = *(int *)(param_2 * 4 + *(int *)(iVar9 + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar8 = *(int *)(iVar9 + 0x51c);
        iVar12 = param_1 + 0x10000;
        iVar10 = iVar6 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar10 + 4);
        iVar9 = iVar5 + iVar8;
        uVar7 = *(undefined4 *)(iVar10 + 0xc);
        iVar13 = 0;
        uVar11 = *(undefined4 *)(iVar10 + 8);
        *(undefined4 *)(iVar5 + iVar8) = *(undefined4 *)(iVar6 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar9 + 0xc) = uVar7;
        *(undefined4 *)(iVar9 + 4) = uVar3;
        *(undefined4 *)(iVar9 + 8) = uVar11;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar12 + -0x777c);
            iVar5 = iVar13 * 4;
            iVar13 = iVar13 + 1;
            puVar2 = (undefined4 *)(iVar12 + -0x7a54);
            iVar12 = iVar12 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar4 + 0x20) + 0x4e4),2);
          } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      iVar5 = *(int *)(param_2 * 4 + *(int *)(*(int *)(iVar4 + 0x24) + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar8 = *(int *)(*(int *)(iVar4 + 0x24) + 0x51c);
        iVar13 = param_1 + 0x10000;
        iVar10 = iVar6 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar10 + 4);
        iVar9 = iVar5 + iVar8;
        uVar7 = *(undefined4 *)(iVar10 + 0xc);
        iVar12 = 0;
        uVar11 = *(undefined4 *)(iVar10 + 8);
        *(undefined4 *)(iVar5 + iVar8) = *(undefined4 *)(iVar6 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar9 + 0xc) = uVar7;
        *(undefined4 *)(iVar9 + 4) = uVar3;
        *(undefined4 *)(iVar9 + 8) = uVar11;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar13 + -0x777c);
            iVar6 = iVar12 * 4;
            iVar12 = iVar12 + 1;
            puVar2 = (undefined4 *)(iVar13 + -0x7a54);
            iVar13 = iVar13 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar6 + *(int *)(iVar4 + 0x24) + 0x4e4),2);
          } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform3iARB_Exec @ 0x8a8a0 (652 bytes) */
void _glUniform3iARB_Exec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 local_30;
  int local_2c;
  undefined2 local_28 [4];
  
  local_28[0] = 0;
  local_2c = 0;
  local_30 = 0;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar4 = *(int *)(param_1 + 0x5430), iVar4 != 0)) &&
        (param_2 < *(int *)(iVar4 + 0x30))) &&
       ((iVar6 = _ShGetUniformTypeInfo
                           (*(undefined4 *)(iVar4 + 0x40),param_2,&local_30,&local_2c,local_28),
        iVar6 != 0 && ((local_2c == 0x8b54 || (local_2c == 0x8b58)))))) {
      iVar6 = param_2 * 0x10;
      iVar5 = *(int *)(iVar4 + 0x4c);
      iVar9 = iVar5 + iVar6;
      if (local_2c == 0x8b54) {
        *(int *)(iVar5 + iVar6) = param_3;
        *(int *)(iVar9 + 8) = param_5;
        *(int *)(iVar9 + 4) = param_4;
      }
      else {
        if (param_3 == 0) {
          *(undefined4 *)(iVar5 + iVar6) = 0;
        }
        else {
          *(undefined4 *)(iVar5 + iVar6) = 1;
        }
        if (param_4 == 0) {
          *(undefined4 *)(iVar9 + 4) = 0;
        }
        else {
          *(undefined4 *)(iVar9 + 4) = 1;
        }
        if (param_5 == 0) {
          *(undefined4 *)(iVar9 + 8) = 0;
        }
        else {
          *(undefined4 *)(iVar9 + 8) = 1;
        }
      }
      *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
      iVar9 = *(int *)(iVar4 + 0x20);
      iVar5 = *(int *)(param_2 * 4 + *(int *)(iVar9 + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar8 = *(int *)(iVar9 + 0x51c);
        iVar12 = param_1 + 0x10000;
        iVar10 = iVar6 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar10 + 4);
        iVar9 = iVar5 + iVar8;
        uVar7 = *(undefined4 *)(iVar10 + 0xc);
        iVar13 = 0;
        uVar11 = *(undefined4 *)(iVar10 + 8);
        *(undefined4 *)(iVar5 + iVar8) = *(undefined4 *)(iVar6 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar9 + 0xc) = uVar7;
        *(undefined4 *)(iVar9 + 4) = uVar3;
        *(undefined4 *)(iVar9 + 8) = uVar11;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar12 + -0x777c);
            iVar5 = iVar13 * 4;
            iVar13 = iVar13 + 1;
            puVar2 = (undefined4 *)(iVar12 + -0x7a54);
            iVar12 = iVar12 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar4 + 0x20) + 0x4e4),2);
          } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
      iVar5 = *(int *)(param_2 * 4 + *(int *)(*(int *)(iVar4 + 0x24) + 0x4e0));
      if (iVar5 != -1) {
        iVar5 = iVar5 * 0x10;
        iVar8 = *(int *)(*(int *)(iVar4 + 0x24) + 0x51c);
        iVar13 = param_1 + 0x10000;
        iVar10 = iVar6 + *(int *)(iVar4 + 0x4c);
        uVar3 = *(undefined4 *)(iVar10 + 4);
        iVar9 = iVar5 + iVar8;
        uVar7 = *(undefined4 *)(iVar10 + 0xc);
        iVar12 = 0;
        uVar11 = *(undefined4 *)(iVar10 + 8);
        *(undefined4 *)(iVar5 + iVar8) = *(undefined4 *)(iVar6 + *(int *)(iVar4 + 0x4c));
        *(undefined4 *)(iVar9 + 0xc) = uVar7;
        *(undefined4 *)(iVar9 + 4) = uVar3;
        *(undefined4 *)(iVar9 + 8) = uVar11;
        if (*(char *)(param_1 + 0x85a4) != '\0') {
          do {
            piVar1 = (int *)(iVar13 + -0x777c);
            iVar6 = iVar12 * 4;
            iVar12 = iVar12 + 1;
            puVar2 = (undefined4 *)(iVar13 + -0x7a54);
            iVar13 = iVar13 + 0x2e0;
            (**(code **)(*piVar1 + 0x194))
                      (*puVar2,*(undefined4 *)(iVar6 + *(int *)(iVar4 + 0x24) + 0x4e4),2);
          } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform2iARB_Exec @ 0x8ab2c (616 bytes) */
void _glUniform2iARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 local_30;
  int local_2c;
  undefined2 local_28 [4];
  
  local_28[0] = 0;
  local_2c = 0;
  local_30 = 0;
  if (param_2 == -1) {
    return;
  }
  if ((((-1 < *(short *)(param_1 + 0x4a10)) || (iVar4 = *(int *)(param_1 + 0x5430), iVar4 == 0)) ||
      (*(int *)(iVar4 + 0x30) <= param_2)) ||
     ((iVar6 = _ShGetUniformTypeInfo
                         (*(undefined4 *)(iVar4 + 0x40),param_2,&local_30,&local_2c,local_28),
      iVar6 == 0 || ((local_2c != 0x8b53 && (local_2c != 0x8b57)))))) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
    return;
  }
  iVar6 = param_2 * 0x10;
  iVar5 = *(int *)(iVar4 + 0x4c);
  if (local_2c == 0x8b53) {
    *(int *)(iVar5 + iVar6) = param_3;
  }
  else {
    if (param_3 == 0) {
      *(undefined4 *)(iVar5 + iVar6) = 0;
    }
    else {
      *(undefined4 *)(iVar5 + iVar6) = 1;
    }
    if (param_4 != 0) {
      *(undefined4 *)(iVar5 + iVar6 + 4) = 1;
      goto LAB_0008ac38;
    }
  }
  *(int *)(iVar5 + iVar6 + 4) = param_4;
LAB_0008ac38:
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
  iVar9 = *(int *)(iVar4 + 0x20);
  iVar5 = *(int *)(param_2 * 4 + *(int *)(iVar9 + 0x4e0));
  if (iVar5 != -1) {
    iVar5 = iVar5 * 0x10;
    iVar8 = *(int *)(iVar9 + 0x51c);
    iVar12 = param_1 + 0x10000;
    iVar10 = iVar6 + *(int *)(iVar4 + 0x4c);
    uVar3 = *(undefined4 *)(iVar10 + 4);
    iVar9 = iVar5 + iVar8;
    uVar7 = *(undefined4 *)(iVar10 + 0xc);
    iVar13 = 0;
    uVar11 = *(undefined4 *)(iVar10 + 8);
    *(undefined4 *)(iVar5 + iVar8) = *(undefined4 *)(iVar6 + *(int *)(iVar4 + 0x4c));
    *(undefined4 *)(iVar9 + 0xc) = uVar7;
    *(undefined4 *)(iVar9 + 4) = uVar3;
    *(undefined4 *)(iVar9 + 8) = uVar11;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      do {
        piVar1 = (int *)(iVar12 + -0x777c);
        iVar5 = iVar13 * 4;
        iVar13 = iVar13 + 1;
        puVar2 = (undefined4 *)(iVar12 + -0x7a54);
        iVar12 = iVar12 + 0x2e0;
        (**(code **)(*piVar1 + 0x194))
                  (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar4 + 0x20) + 0x4e4),2);
      } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
  }
  iVar5 = *(int *)(param_2 * 4 + *(int *)(*(int *)(iVar4 + 0x24) + 0x4e0));
  if (iVar5 != -1) {
    iVar5 = iVar5 * 0x10;
    iVar8 = *(int *)(*(int *)(iVar4 + 0x24) + 0x51c);
    iVar13 = param_1 + 0x10000;
    iVar10 = iVar6 + *(int *)(iVar4 + 0x4c);
    uVar3 = *(undefined4 *)(iVar10 + 4);
    iVar9 = iVar5 + iVar8;
    uVar7 = *(undefined4 *)(iVar10 + 0xc);
    iVar12 = 0;
    uVar11 = *(undefined4 *)(iVar10 + 8);
    *(undefined4 *)(iVar5 + iVar8) = *(undefined4 *)(iVar6 + *(int *)(iVar4 + 0x4c));
    *(undefined4 *)(iVar9 + 0xc) = uVar7;
    *(undefined4 *)(iVar9 + 4) = uVar3;
    *(undefined4 *)(iVar9 + 8) = uVar11;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      do {
        piVar1 = (int *)(iVar13 + -0x777c);
        iVar6 = iVar12 * 4;
        iVar12 = iVar12 + 1;
        puVar2 = (undefined4 *)(iVar13 + -0x7a54);
        iVar13 = iVar13 + 0x2e0;
        (**(code **)(*piVar1 + 0x194))
                  (*puVar2,*(undefined4 *)(iVar6 + *(int *)(iVar4 + 0x24) + 0x4e4),2);
      } while (iVar12 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
  }
  return;
}

/* _glUniform1iARB_Exec @ 0x8ad94 (756 bytes) */
void _glUniform1iARB_Exec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  undefined4 local_40;
  int local_3c;
  undefined2 local_38 [10];
  
  local_38[0] = 0;
  local_3c = 0;
  uVar11 = 2;
  local_40 = 0;
  if (param_2 == -1) {
    return;
  }
  if (((((-1 < *(short *)(param_1 + 0x4a10)) || (iVar12 = *(int *)(param_1 + 0x5430), iVar12 == 0))
       || (*(int *)(iVar12 + 0x30) <= param_2)) ||
      (iVar4 = _ShGetUniformTypeInfo
                         (*(undefined4 *)(iVar12 + 0x40),param_2,&local_40,&local_3c,local_38),
      iVar4 == 0)) ||
     ((((local_3c != 0x1404 && (local_3c != 0x8b56)) &&
       ((local_3c != 0x8b5d && ((local_3c != 0x8b5e && (local_3c != 0x8b5f)))))) &&
      ((local_3c != 0x8b60 &&
       ((((local_3c != 0x8b61 && (local_3c != 0x8b62)) && (local_3c != 0x8b63)) &&
        (local_3c != 0x8b64)))))))) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
    return;
  }
  iVar8 = *(int *)(iVar12 + 0x4c);
  iVar4 = param_2 * 0x10;
  iVar5 = *(int *)(iVar8 + iVar4);
  if (iVar5 == param_3) {
    return;
  }
  if (local_3c != 0x1404) {
    if (local_3c - 0x8b5dU < 8) {
      *(int *)(iVar8 + iVar4) = param_3;
      uVar11 = 6;
      ((double (*)())_setImageUnit)(param_1,iVar12,param_3,iVar5,local_38,local_3c,fparam_1,in_f2,in_f3,in_f4,in_f5,
                    in_f6,in_f7,in_f8);
      goto LAB_0008af2c;
    }
    if (param_3 != 0) {
      *(undefined4 *)(iVar8 + iVar4) = 1;
      goto LAB_0008af2c;
    }
  }
  *(int *)(iVar8 + iVar4) = param_3;
LAB_0008af2c:
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
  iVar8 = *(int *)(iVar12 + 0x20);
  iVar5 = *(int *)(param_2 * 4 + *(int *)(iVar8 + 0x4e0));
  if (iVar5 != -1) {
    iVar5 = iVar5 * 0x10;
    iVar7 = *(int *)(iVar8 + 0x51c);
    iVar13 = param_1 + 0x10000;
    iVar9 = iVar4 + *(int *)(iVar12 + 0x4c);
    uVar3 = *(undefined4 *)(iVar9 + 4);
    iVar8 = iVar5 + iVar7;
    uVar6 = *(undefined4 *)(iVar9 + 0xc);
    iVar14 = 0;
    uVar10 = *(undefined4 *)(iVar9 + 8);
    *(undefined4 *)(iVar5 + iVar7) = *(undefined4 *)(iVar4 + *(int *)(iVar12 + 0x4c));
    *(undefined4 *)(iVar8 + 0xc) = uVar6;
    *(undefined4 *)(iVar8 + 4) = uVar3;
    *(undefined4 *)(iVar8 + 8) = uVar10;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      do {
        piVar1 = (int *)(iVar13 + -0x777c);
        iVar5 = iVar14 * 4;
        iVar14 = iVar14 + 1;
        puVar2 = (undefined4 *)(iVar13 + -0x7a54);
        iVar13 = iVar13 + 0x2e0;
        (**(code **)(*piVar1 + 0x194))
                  (*puVar2,*(undefined4 *)(iVar5 + *(int *)(iVar12 + 0x20) + 0x4e4),uVar11);
      } while (iVar14 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
  }
  iVar5 = *(int *)(param_2 * 4 + *(int *)(*(int *)(iVar12 + 0x24) + 0x4e0));
  if (iVar5 != -1) {
    iVar5 = iVar5 * 0x10;
    iVar7 = *(int *)(*(int *)(iVar12 + 0x24) + 0x51c);
    iVar14 = param_1 + 0x10000;
    iVar9 = iVar4 + *(int *)(iVar12 + 0x4c);
    uVar3 = *(undefined4 *)(iVar9 + 4);
    iVar8 = iVar5 + iVar7;
    uVar6 = *(undefined4 *)(iVar9 + 0xc);
    iVar13 = 0;
    uVar10 = *(undefined4 *)(iVar9 + 8);
    *(undefined4 *)(iVar5 + iVar7) = *(undefined4 *)(iVar4 + *(int *)(iVar12 + 0x4c));
    *(undefined4 *)(iVar8 + 0xc) = uVar6;
    *(undefined4 *)(iVar8 + 4) = uVar3;
    *(undefined4 *)(iVar8 + 8) = uVar10;
    if (*(char *)(param_1 + 0x85a4) != '\0') {
      do {
        piVar1 = (int *)(iVar14 + -0x777c);
        iVar4 = iVar13 * 4;
        iVar13 = iVar13 + 1;
        puVar2 = (undefined4 *)(iVar14 + -0x7a54);
        iVar14 = iVar14 + 0x2e0;
        (**(code **)(*piVar1 + 0x194))
                  (*puVar2,*(undefined4 *)(iVar4 + *(int *)(iVar12 + 0x24) + 0x4e4),uVar11);
      } while (iVar13 < (int)(uint)*(byte *)(param_1 + 0x85a4));
    }
  }
  return;
}

/* _glUniform4ivARB_Exec @ 0x8b088 (892 bytes) */
void _glUniform4ivARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int *piVar1;
  undefined4 *puVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int *piVar15;
  int iVar16;
  int local_30;
  int local_2c;
  undefined2 local_28 [4];
  
  local_2c = 0;
  local_28[0] = 0;
  local_30 = 0;
  bVar3 = false;
  bVar4 = false;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar6 = *(int *)(param_1 + 0x5430), iVar6 != 0)) &&
        (param_2 < *(int *)(iVar6 + 0x30))) &&
       (((-1 < param_3 &&
         (iVar7 = _ShGetUniformTypeInfo
                            (*(undefined4 *)(iVar6 + 0x40),param_2,&local_30,&local_2c,local_28),
         iVar7 != 0)) && ((local_2c == 0x8b55 || (local_2c == 0x8b59)))))) {
      if (param_3 != 0) {
        if (param_3 < local_30) {
          local_30 = param_3;
        }
        piVar15 = (int *)(*(int *)(iVar6 + 0x4c) + param_2 * 0x10);
        if (local_2c == 0x8b55) {
          iVar7 = 0;
          if (0 < local_30) {
            do {
              iVar7 = iVar7 + 1;
              *piVar15 = *param_4;
              piVar15[1] = param_4[1];
              piVar15[2] = param_4[2];
              piVar1 = param_4 + 3;
              param_4 = param_4 + 4;
              piVar15[3] = *piVar1;
              piVar15 = piVar15 + 4;
            } while (iVar7 < local_30);
          }
        }
        else {
          iVar7 = 0;
          if (0 < local_30) {
            do {
              if (*param_4 == 0) {
                *piVar15 = 0;
              }
              else {
                *piVar15 = 1;
              }
              if (param_4[1] == 0) {
                piVar15[1] = 0;
              }
              else {
                piVar15[1] = 1;
              }
              if (param_4[2] == 0) {
                piVar15[2] = 0;
              }
              else {
                piVar15[2] = 1;
              }
              if (param_4[3] == 0) {
                piVar15[3] = 0;
              }
              else {
                piVar15[3] = 1;
              }
              iVar7 = iVar7 + 1;
              piVar15 = piVar15 + 4;
              param_4 = param_4 + 4;
            } while (iVar7 < local_30);
          }
        }
        iVar7 = 0;
        if (0 < local_30) {
          iVar9 = param_2 << 2;
          iVar8 = param_2 << 4;
          do {
            iVar12 = *(int *)(iVar6 + 0x20);
            iVar16 = *(int *)(iVar9 + *(int *)(iVar12 + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar11 = *(int *)(iVar12 + 0x51c);
              bVar3 = true;
              iVar13 = iVar8 + *(int *)(iVar6 + 0x4c);
              uVar10 = *(undefined4 *)(iVar13 + 0xc);
              iVar12 = iVar16 + iVar11;
              uVar5 = *(undefined4 *)(iVar13 + 4);
              uVar14 = *(undefined4 *)(iVar13 + 8);
              *(undefined4 *)(iVar16 + iVar11) = *(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar12 + 0xc) = uVar10;
              *(undefined4 *)(iVar12 + 4) = uVar5;
              *(undefined4 *)(iVar12 + 8) = uVar14;
            }
            iVar16 = *(int *)(iVar9 + *(int *)(*(int *)(iVar6 + 0x24) + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar11 = *(int *)(*(int *)(iVar6 + 0x24) + 0x51c);
              bVar4 = true;
              iVar13 = iVar8 + *(int *)(iVar6 + 0x4c);
              uVar10 = *(undefined4 *)(iVar13 + 0xc);
              iVar12 = iVar16 + iVar11;
              uVar5 = *(undefined4 *)(iVar13 + 4);
              uVar14 = *(undefined4 *)(iVar13 + 8);
              *(undefined4 *)(iVar16 + iVar11) = *(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar12 + 0xc) = uVar10;
              *(undefined4 *)(iVar12 + 4) = uVar5;
              *(undefined4 *)(iVar12 + 8) = uVar14;
            }
            iVar7 = iVar7 + 1;
            iVar9 = iVar9 + 4;
            iVar8 = iVar8 + 0x10;
          } while (iVar7 < local_30);
        }
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
        if (bVar3) {
          iVar7 = param_1 + 0x10000;
          iVar9 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar15 = (int *)(iVar7 + -0x777c);
              iVar8 = iVar9 * 4;
              iVar9 = iVar9 + 1;
              puVar2 = (undefined4 *)(iVar7 + -0x7a54);
              iVar7 = iVar7 + 0x2e0;
              (**(code **)(*piVar15 + 0x194))
                        (*puVar2,*(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x20) + 0x4e4),2);
            } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
        if (bVar4) {
          iVar7 = param_1 + 0x10000;
          iVar9 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar15 = (int *)(iVar7 + -0x777c);
              iVar8 = iVar9 * 4;
              iVar9 = iVar9 + 1;
              puVar2 = (undefined4 *)(iVar7 + -0x7a54);
              iVar7 = iVar7 + 0x2e0;
              (**(code **)(*piVar15 + 0x194))
                        (*puVar2,*(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x24) + 0x4e4),2);
            } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform3ivARB_Exec @ 0x8b404 (860 bytes) */
void _glUniform3ivARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int *piVar1;
  undefined4 *puVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int *piVar15;
  int iVar16;
  int local_30;
  int local_2c;
  undefined2 local_28 [4];
  
  local_2c = 0;
  local_28[0] = 0;
  local_30 = 0;
  bVar3 = false;
  bVar4 = false;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar6 = *(int *)(param_1 + 0x5430), iVar6 != 0)) &&
        (param_2 < *(int *)(iVar6 + 0x30))) &&
       (((-1 < param_3 &&
         (iVar7 = _ShGetUniformTypeInfo
                            (*(undefined4 *)(iVar6 + 0x40),param_2,&local_30,&local_2c,local_28),
         iVar7 != 0)) && ((local_2c == 0x8b54 || (local_2c == 0x8b58)))))) {
      if (param_3 != 0) {
        if (param_3 < local_30) {
          local_30 = param_3;
        }
        piVar15 = (int *)(*(int *)(iVar6 + 0x4c) + param_2 * 0x10);
        if (local_2c == 0x8b54) {
          iVar7 = 0;
          if (0 < local_30) {
            do {
              iVar7 = iVar7 + 1;
              *piVar15 = *param_4;
              piVar15[1] = param_4[1];
              piVar1 = param_4 + 2;
              param_4 = param_4 + 3;
              piVar15[2] = *piVar1;
              piVar15 = piVar15 + 4;
            } while (iVar7 < local_30);
          }
        }
        else {
          iVar7 = 0;
          if (0 < local_30) {
            do {
              if (*param_4 == 0) {
                *piVar15 = 0;
              }
              else {
                *piVar15 = 1;
              }
              if (param_4[1] == 0) {
                piVar15[1] = 0;
              }
              else {
                piVar15[1] = 1;
              }
              if (param_4[2] == 0) {
                piVar15[2] = 0;
              }
              else {
                piVar15[2] = 1;
              }
              iVar7 = iVar7 + 1;
              piVar15 = piVar15 + 4;
              param_4 = param_4 + 3;
            } while (iVar7 < local_30);
          }
        }
        iVar7 = 0;
        if (0 < local_30) {
          iVar9 = param_2 << 2;
          iVar8 = param_2 << 4;
          do {
            iVar12 = *(int *)(iVar6 + 0x20);
            iVar16 = *(int *)(iVar9 + *(int *)(iVar12 + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar11 = *(int *)(iVar12 + 0x51c);
              bVar3 = true;
              iVar13 = iVar8 + *(int *)(iVar6 + 0x4c);
              uVar10 = *(undefined4 *)(iVar13 + 0xc);
              iVar12 = iVar16 + iVar11;
              uVar5 = *(undefined4 *)(iVar13 + 4);
              uVar14 = *(undefined4 *)(iVar13 + 8);
              *(undefined4 *)(iVar16 + iVar11) = *(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar12 + 0xc) = uVar10;
              *(undefined4 *)(iVar12 + 4) = uVar5;
              *(undefined4 *)(iVar12 + 8) = uVar14;
            }
            iVar16 = *(int *)(iVar9 + *(int *)(*(int *)(iVar6 + 0x24) + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar11 = *(int *)(*(int *)(iVar6 + 0x24) + 0x51c);
              bVar4 = true;
              iVar13 = iVar8 + *(int *)(iVar6 + 0x4c);
              uVar10 = *(undefined4 *)(iVar13 + 0xc);
              iVar12 = iVar16 + iVar11;
              uVar5 = *(undefined4 *)(iVar13 + 4);
              uVar14 = *(undefined4 *)(iVar13 + 8);
              *(undefined4 *)(iVar16 + iVar11) = *(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar12 + 0xc) = uVar10;
              *(undefined4 *)(iVar12 + 4) = uVar5;
              *(undefined4 *)(iVar12 + 8) = uVar14;
            }
            iVar7 = iVar7 + 1;
            iVar9 = iVar9 + 4;
            iVar8 = iVar8 + 0x10;
          } while (iVar7 < local_30);
        }
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
        if (bVar3) {
          iVar7 = param_1 + 0x10000;
          iVar9 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar15 = (int *)(iVar7 + -0x777c);
              iVar8 = iVar9 * 4;
              iVar9 = iVar9 + 1;
              puVar2 = (undefined4 *)(iVar7 + -0x7a54);
              iVar7 = iVar7 + 0x2e0;
              (**(code **)(*piVar15 + 0x194))
                        (*puVar2,*(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x20) + 0x4e4),2);
            } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
        if (bVar4) {
          iVar7 = param_1 + 0x10000;
          iVar9 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar15 = (int *)(iVar7 + -0x777c);
              iVar8 = iVar9 * 4;
              iVar9 = iVar9 + 1;
              puVar2 = (undefined4 *)(iVar7 + -0x7a54);
              iVar7 = iVar7 + 0x2e0;
              (**(code **)(*piVar15 + 0x194))
                        (*puVar2,*(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x24) + 0x4e4),2);
            } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform2ivARB_Exec @ 0x8b760 (828 bytes) */
void _glUniform2ivARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int *piVar1;
  undefined4 *puVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int *piVar15;
  int iVar16;
  int local_30;
  int local_2c;
  undefined2 local_28 [4];
  
  local_2c = 0;
  local_28[0] = 0;
  local_30 = 0;
  bVar3 = false;
  bVar4 = false;
  if (param_2 != -1) {
    if ((((*(short *)(param_1 + 0x4a10) < 0) && (iVar6 = *(int *)(param_1 + 0x5430), iVar6 != 0)) &&
        (param_2 < *(int *)(iVar6 + 0x30))) &&
       (((-1 < param_3 &&
         (iVar7 = _ShGetUniformTypeInfo
                            (*(undefined4 *)(iVar6 + 0x40),param_2,&local_30,&local_2c,local_28),
         iVar7 != 0)) && ((local_2c == 0x8b53 || (local_2c == 0x8b57)))))) {
      if (param_3 != 0) {
        if (param_3 < local_30) {
          local_30 = param_3;
        }
        piVar15 = (int *)(*(int *)(iVar6 + 0x4c) + param_2 * 0x10);
        if (local_2c == 0x8b53) {
          iVar7 = 0;
          if (0 < local_30) {
            do {
              iVar7 = iVar7 + 1;
              *piVar15 = *param_4;
              piVar1 = param_4 + 1;
              param_4 = param_4 + 2;
              piVar15[1] = *piVar1;
              piVar15 = piVar15 + 4;
            } while (iVar7 < local_30);
          }
        }
        else {
          iVar7 = 0;
          if (0 < local_30) {
            do {
              if (*param_4 == 0) {
                *piVar15 = 0;
              }
              else {
                *piVar15 = 1;
              }
              if (param_4[1] == 0) {
                piVar15[1] = 0;
              }
              else {
                piVar15[1] = 1;
              }
              iVar7 = iVar7 + 1;
              piVar15 = piVar15 + 4;
              param_4 = param_4 + 2;
            } while (iVar7 < local_30);
          }
        }
        iVar7 = 0;
        if (0 < local_30) {
          iVar9 = param_2 << 2;
          iVar8 = param_2 << 4;
          do {
            iVar12 = *(int *)(iVar6 + 0x20);
            iVar16 = *(int *)(iVar9 + *(int *)(iVar12 + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar11 = *(int *)(iVar12 + 0x51c);
              bVar3 = true;
              iVar13 = iVar8 + *(int *)(iVar6 + 0x4c);
              uVar10 = *(undefined4 *)(iVar13 + 0xc);
              iVar12 = iVar16 + iVar11;
              uVar5 = *(undefined4 *)(iVar13 + 4);
              uVar14 = *(undefined4 *)(iVar13 + 8);
              *(undefined4 *)(iVar16 + iVar11) = *(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar12 + 0xc) = uVar10;
              *(undefined4 *)(iVar12 + 4) = uVar5;
              *(undefined4 *)(iVar12 + 8) = uVar14;
            }
            iVar16 = *(int *)(iVar9 + *(int *)(*(int *)(iVar6 + 0x24) + 0x4e0));
            if (iVar16 != -1) {
              iVar16 = iVar16 * 0x10;
              iVar11 = *(int *)(*(int *)(iVar6 + 0x24) + 0x51c);
              bVar4 = true;
              iVar13 = iVar8 + *(int *)(iVar6 + 0x4c);
              uVar10 = *(undefined4 *)(iVar13 + 0xc);
              iVar12 = iVar16 + iVar11;
              uVar5 = *(undefined4 *)(iVar13 + 4);
              uVar14 = *(undefined4 *)(iVar13 + 8);
              *(undefined4 *)(iVar16 + iVar11) = *(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x4c));
              *(undefined4 *)(iVar12 + 0xc) = uVar10;
              *(undefined4 *)(iVar12 + 4) = uVar5;
              *(undefined4 *)(iVar12 + 8) = uVar14;
            }
            iVar7 = iVar7 + 1;
            iVar9 = iVar9 + 4;
            iVar8 = iVar8 + 0x10;
          } while (iVar7 < local_30);
        }
        *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
        if (bVar3) {
          iVar7 = param_1 + 0x10000;
          iVar9 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar15 = (int *)(iVar7 + -0x777c);
              iVar8 = iVar9 * 4;
              iVar9 = iVar9 + 1;
              puVar2 = (undefined4 *)(iVar7 + -0x7a54);
              iVar7 = iVar7 + 0x2e0;
              (**(code **)(*piVar15 + 0x194))
                        (*puVar2,*(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x20) + 0x4e4),2);
            } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
        if (bVar4) {
          iVar7 = param_1 + 0x10000;
          iVar9 = 0;
          if (*(char *)(param_1 + 0x85a4) != '\0') {
            do {
              piVar15 = (int *)(iVar7 + -0x777c);
              iVar8 = iVar9 * 4;
              iVar9 = iVar9 + 1;
              puVar2 = (undefined4 *)(iVar7 + -0x7a54);
              iVar7 = iVar7 + 0x2e0;
              (**(code **)(*piVar15 + 0x194))
                        (*puVar2,*(undefined4 *)(iVar8 + *(int *)(iVar6 + 0x24) + 0x4e4),2);
            } while (iVar9 < (int)(uint)*(byte *)(param_1 + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform1ivARB_Exec @ 0x8ba9c (936 bytes) */
void _glUniform1ivARB_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  undefined4 *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  int *piVar16;
  double extraout_f1;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  int local_40;
  int local_3c;
  undefined2 local_38 [6];
  
  local_3c = 0;
  local_38[0] = 0;
  local_40 = 0;
  bVar3 = false;
  bVar4 = false;
  bVar2 = false;
  if (param_2 != -1) {
    if (((((*(short *)(param_1 + 0x4a10) < 0) && (iVar15 = *(int *)(param_1 + 0x5430), iVar15 != 0))
         && (param_2 < *(int *)(iVar15 + 0x30))) &&
        ((-1 < param_3 &&
         (iVar7 = _ShGetUniformTypeInfo
                            (*(undefined4 *)(iVar15 + 0x40),param_2,&local_40,&local_3c,local_38),
         iVar7 != 0)))) &&
       ((((local_3c == 0x1404 || ((local_3c == 0x8b56 || (local_3c == 0x8b5d)))) ||
         ((local_3c == 0x8b5e ||
          ((((local_3c == 0x8b5f || (local_3c == 0x8b60)) || (local_3c == 0x8b61)) ||
           ((local_3c == 0x8b62 || (local_3c == 0x8b63)))))))) || (local_3c == 0x8b64)))) {
      if (param_3 != 0) {
        if (param_3 < local_40) {
          local_40 = param_3;
        }
        iVar14 = 0;
        piVar16 = (int *)(*(int *)(iVar15 + 0x4c) + param_2 * 0x10);
        iVar7 = local_40;
        fparam_1 = extraout_f1;
        if (0 < local_40) {
          do {
            iVar8 = *piVar16;
            iVar5 = *param_4;
            if (iVar8 != iVar5) {
              bVar2 = true;
              iVar7 = local_40;
              if (local_3c == 0x1404) {
LAB_0008bc7c:
                *piVar16 = iVar5;
              }
              else if (local_3c - 0x8b5dU < 8) {
                *piVar16 = iVar5;
                fparam_1 = (double)((double (*)())_setImageUnit)(param_1,iVar15,*param_4,iVar8,local_38,local_3c,
                                                 fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8)
                ;
                iVar7 = local_40;
              }
              else {
                if (iVar5 == 0) goto LAB_0008bc7c;
                *piVar16 = 1;
              }
            }
            iVar14 = iVar14 + 1;
            piVar16 = piVar16 + 4;
            param_4 = param_4 + 1;
          } while (iVar14 < iVar7);
          if (bVar2) {
            iVar14 = 0;
            if (0 < iVar7) {
              iVar7 = param_2 << 2;
              iVar5 = param_2 << 4;
              do {
                iVar11 = *(int *)(iVar15 + 0x20);
                iVar8 = *(int *)(iVar7 + *(int *)(iVar11 + 0x4e0));
                if (iVar8 != -1) {
                  iVar8 = iVar8 * 0x10;
                  iVar10 = *(int *)(iVar11 + 0x51c);
                  bVar3 = true;
                  iVar12 = iVar5 + *(int *)(iVar15 + 0x4c);
                  uVar9 = *(undefined4 *)(iVar12 + 0xc);
                  iVar11 = iVar8 + iVar10;
                  uVar6 = *(undefined4 *)(iVar12 + 4);
                  uVar13 = *(undefined4 *)(iVar12 + 8);
                  *(undefined4 *)(iVar8 + iVar10) = *(undefined4 *)(iVar5 + *(int *)(iVar15 + 0x4c))
                  ;
                  *(undefined4 *)(iVar11 + 0xc) = uVar9;
                  *(undefined4 *)(iVar11 + 4) = uVar6;
                  *(undefined4 *)(iVar11 + 8) = uVar13;
                }
                iVar8 = *(int *)(iVar7 + *(int *)(*(int *)(iVar15 + 0x24) + 0x4e0));
                if (iVar8 != -1) {
                  iVar8 = iVar8 * 0x10;
                  iVar10 = *(int *)(*(int *)(iVar15 + 0x24) + 0x51c);
                  bVar4 = true;
                  iVar12 = iVar5 + *(int *)(iVar15 + 0x4c);
                  uVar9 = *(undefined4 *)(iVar12 + 0xc);
                  iVar11 = iVar8 + iVar10;
                  uVar6 = *(undefined4 *)(iVar12 + 4);
                  uVar13 = *(undefined4 *)(iVar12 + 8);
                  *(undefined4 *)(iVar8 + iVar10) = *(undefined4 *)(iVar5 + *(int *)(iVar15 + 0x4c))
                  ;
                  *(undefined4 *)(iVar11 + 0xc) = uVar9;
                  *(undefined4 *)(iVar11 + 4) = uVar6;
                  *(undefined4 *)(iVar11 + 8) = uVar13;
                }
                iVar14 = iVar14 + 1;
                iVar7 = iVar7 + 4;
                iVar5 = iVar5 + 0x10;
              } while (iVar14 < local_40);
            }
            *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x4000000;
            if (bVar3) {
              iVar14 = param_1 + 0x10000;
              iVar7 = 0;
              if (*(char *)(param_1 + 0x85a4) != '\0') {
                do {
                  piVar16 = (int *)(iVar14 + -0x777c);
                  iVar5 = iVar7 * 4;
                  iVar7 = iVar7 + 1;
                  puVar1 = (undefined4 *)(iVar14 + -0x7a54);
                  iVar14 = iVar14 + 0x2e0;
                  (**(code **)(*piVar16 + 0x194))
                            (*puVar1,*(undefined4 *)(iVar5 + *(int *)(iVar15 + 0x20) + 0x4e4),2);
                } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x85a4));
              }
            }
            if (bVar4) {
              iVar14 = param_1 + 0x10000;
              iVar7 = 0;
              if (*(char *)(param_1 + 0x85a4) != '\0') {
                do {
                  piVar16 = (int *)(iVar14 + -0x777c);
                  iVar5 = iVar7 * 4;
                  iVar7 = iVar7 + 1;
                  puVar1 = (undefined4 *)(iVar14 + -0x7a54);
                  iVar14 = iVar14 + 0x2e0;
                  (**(code **)(*piVar16 + 0x194))
                            (*puVar1,*(undefined4 *)(iVar5 + *(int *)(iVar15 + 0x24) + 0x4e4),2);
                } while (iVar7 < (int)(uint)*(byte *)(param_1 + 0x85a4));
              }
            }
          }
        }
      }
    }
    else if (*(int *)(param_1 + 0x7574) == 0) {
      *(undefined4 *)(param_1 + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform4fARB_Comp @ 0x8be44 (100 bytes) */
void _glUniform4fARB_Comp(undefined4 param_1,undefined4 param_2,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glUniform4fARB_ListExec_00110300,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = (float)fparam_4;
    *puVar1 = param_2;
    puVar1[1] = (float)fparam_1;
    puVar1[2] = (float)fparam_2;
    puVar1[3] = (float)fparam_3;
  }
  return;
}

/* _glUniform3fARB_Comp @ 0x8bea8 (124 bytes) */
undefined4 * _glUniform3fARB_Comp(undefined4 param_1,undefined4 param_2,float fparam_1,float fparam_2,float fparam_3)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glUniform3fARB_ListExec_001102fc,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = (float)fparam_3;
    *puVar1 = param_2;
    puVar1[1] = (float)fparam_1;
    puVar1[2] = (float)fparam_2;
  }
  return puVar1;
}

/* _glUniform2fARB_Comp @ 0x8bf24 (108 bytes) */
undefined4 * _glUniform2fARB_Comp(undefined4 param_1,undefined4 param_2,float fparam_1,float fparam_2)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glUniform2fARB_ListExec_001102f8,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = (float)fparam_2;
    *puVar1 = param_2;
    puVar1[1] = (float)fparam_1;
  }
  return puVar1;
}

/* _glUniform1fARB_Comp @ 0x8bf90 (92 bytes) */
undefined4 * _glUniform1fARB_Comp(undefined4 param_1,undefined4 param_2,float fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glUniform1fARB_ListExec_001102f4,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = (float)fparam_1;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glUniform4fvARB_Comp @ 0x8bfec (160 bytes) */
int _glUniform4fvARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glUniform4fvARB_ListExec_001102f0,param_3 * 0x10 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = param_3;
    iVar1 = 0;
    *puVar2 = param_2;
    puVar2 = puVar2 + 2;
    while( true ) {
      *puVar2 = *param_4;
      puVar2[1] = param_4[1];
      puVar2[2] = param_4[2];
      puVar2[3] = param_4[3];
      if (iVar1 == param_3 + -1) break;
      puVar2 = puVar2 + 4;
      param_4 = param_4 + 4;
      iVar1 = iVar1 + 1;
    }
  }
  return puVar2;
}

/* _glUniform3fvARB_Comp @ 0x8c08c (152 bytes) */
int _glUniform3fvARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glUniform3fvARB_ListExec_001102ec,param_3 * 0xc + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = param_3;
    iVar1 = 0;
    *puVar2 = param_2;
    puVar2 = puVar2 + 2;
    while( true ) {
      *puVar2 = *param_4;
      puVar2[1] = param_4[1];
      puVar2[2] = param_4[2];
      if (iVar1 == param_3 + -1) break;
      puVar2 = puVar2 + 3;
      param_4 = param_4 + 3;
      iVar1 = iVar1 + 1;
    }
  }
  return puVar2;
}

/* _glUniform2fvARB_Comp @ 0x8c124 (144 bytes) */
int _glUniform2fvARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glUniform2fvARB_ListExec_001102e8,param_3 * 8 + 8);
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = param_3;
    iVar1 = 0;
    *puVar2 = param_2;
    while( true ) {
      puVar3 = puVar2 + 2;
      *puVar3 = *param_4;
      puVar2[3] = param_4[1];
      if (iVar1 == param_3 + -1) break;
      param_4 = param_4 + 2;
      iVar1 = iVar1 + 1;
      puVar2 = puVar3;
    }
  }
  return puVar3;
}

/* _glUniform1fvARB_Comp @ 0x8c1b4 (136 bytes) */
int _glUniform1fvARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glUniform1fvARB_ListExec_001102e4,param_3 * 4 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = param_3;
    *puVar2 = param_2;
    puVar2 = puVar2 + 2;
    for (iVar1 = 0; *puVar2 = *param_4, iVar1 != param_3 + -1; iVar1 = iVar1 + 1) {
      puVar2 = puVar2 + 1;
      param_4 = param_4 + 1;
    }
  }
  return puVar2;
}

/* _glUniform4iARB_Comp @ 0x8c23c (108 bytes) */
int _glUniform4iARB_Comp(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glUniform4iARB_ListExec_001102e0,0x14);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[4] = param_6;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
    puVar1[3] = param_5;
  }
  return puVar1;
}

/* _glUniform3iARB_Comp @ 0x8c2a8 (100 bytes) */
int _glUniform3iARB_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glUniform3iARB_ListExec_001102dc,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = param_5;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
  }
  return puVar1;
}

/* _glUniform2iARB_Comp @ 0x8c30c (92 bytes) */
int _glUniform2iARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glUniform2iARB_ListExec_001102d8,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = param_4;
    *puVar1 = param_2;
    puVar1[1] = param_3;
  }
  return puVar1;
}

/* _glUniform1iARB_Comp @ 0x8c368 (84 bytes) */
int _glUniform1iARB_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glUniform1iARB_ListExec_001102d4,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glUniform4ivARB_Comp @ 0x8c3bc (160 bytes) */
int _glUniform4ivARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glUniform4ivARB_ListExec_001102d0,param_3 * 0x10 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    iVar2 = 0;
    *puVar1 = param_2;
    puVar1 = puVar1 + 2;
    while( true ) {
      *puVar1 = *param_4;
      puVar1[1] = param_4[1];
      puVar1[2] = param_4[2];
      puVar1[3] = param_4[3];
      if (iVar2 == param_3 + -1) break;
      puVar1 = puVar1 + 4;
      param_4 = param_4 + 4;
      iVar2 = iVar2 + 1;
    }
  }
  return puVar1;
}

/* _glUniform3ivARB_Comp @ 0x8c45c (152 bytes) */
int _glUniform3ivARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glUniform3ivARB_ListExec_001102cc,param_3 * 0xc + 8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    iVar2 = 0;
    *puVar1 = param_2;
    puVar1 = puVar1 + 2;
    while( true ) {
      *puVar1 = *param_4;
      puVar1[1] = param_4[1];
      puVar1[2] = param_4[2];
      if (iVar2 == param_3 + -1) break;
      puVar1 = puVar1 + 3;
      param_4 = param_4 + 3;
      iVar2 = iVar2 + 1;
    }
  }
  return puVar1;
}

/* _glUniform2ivARB_Comp @ 0x8c4f4 (144 bytes) */
int _glUniform2ivARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glUniform2ivARB_ListExec_001102c8,param_3 * 8 + 8);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    iVar3 = 0;
    *puVar1 = param_2;
    while( true ) {
      puVar2 = puVar1 + 2;
      *puVar2 = *param_4;
      puVar1[3] = param_4[1];
      if (iVar3 == param_3 + -1) break;
      param_4 = param_4 + 2;
      iVar3 = iVar3 + 1;
      puVar1 = puVar2;
    }
  }
  return puVar2;
}

/* _glUniform1ivARB_Comp @ 0x8c584 (136 bytes) */
int _glUniform1ivARB_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 *param_4;
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(param_1,PTR__glUniform1ivARB_ListExec_001102c4,param_3 * 4 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = param_3;
    *puVar2 = param_2;
    puVar2 = puVar2 + 2;
    for (iVar1 = 0; *puVar2 = *param_4, iVar1 != param_3 + -1; iVar1 = iVar1 + 1) {
      puVar2 = puVar2 + 1;
      param_4 = param_4 + 1;
    }
  }
  return puVar2;
}

/* _glUniform4fARB_CompExec @ 0x8c60c (104 bytes) */
void _glUniform4fARB_CompExec(undefined4 param_1,undefined4 param_2,float fparam_1,float fparam_2,float fparam_3,float fparam_4)
{
  ((void (*)())_glUniform4fARB_Comp)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glUniform4fARB_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glUniform3fARB_CompExec @ 0x8c674 (104 bytes) */
void _glUniform3fARB_CompExec(undefined4 param_1,undefined4 param_2,float fparam_1,float fparam_2,float fparam_3)
{
  ((undefined4 * (*)())_glUniform3fARB_Comp)(param_1,param_2,fparam_1,fparam_2,fparam_3);
  ((void (*)())_glUniform3fARB_Exec)(param_1,param_2,fparam_1,fparam_2,fparam_3);
  return;
}

/* _glUniform2fARB_CompExec @ 0x8c6dc (88 bytes) */
void _glUniform2fARB_CompExec(undefined4 param_1,undefined4 param_2,float fparam_1,float fparam_2)
{
  ((undefined4 * (*)())_glUniform2fARB_Comp)(param_1,param_2,fparam_1,fparam_2);
  ((void (*)())_glUniform2fARB_Exec)(param_1,param_2,fparam_1,fparam_2);
  return;
}

/* _glUniform1fARB_CompExec @ 0x8c734 (72 bytes) */
void _glUniform1fARB_CompExec(undefined4 param_1,undefined4 param_2,float fparam_1)
{
  ((undefined4 * (*)())_glUniform1fARB_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glUniform1fARB_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glUniform4fvARB_CompExec @ 0x8c77c (72 bytes) */
void _glUniform4fvARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glUniform4fvARB_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glUniform4fvARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glUniform3fvARB_CompExec @ 0x8c7c4 (72 bytes) */
void _glUniform3fvARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glUniform3fvARB_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glUniform3fvARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glUniform2fvARB_CompExec @ 0x8c80c (72 bytes) */
void _glUniform2fvARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glUniform2fvARB_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glUniform2fvARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glUniform1fvARB_CompExec @ 0x8c854 (72 bytes) */
void _glUniform1fvARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glUniform1fvARB_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glUniform1fvARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glUniform4iARB_CompExec @ 0x8c89c (88 bytes) */
void _glUniform4iARB_CompExec(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  ((int (*)())_glUniform4iARB_Comp)(param_1,param_2,param_3,param_4,param_5,param_6);
  ((void (*)())_glUniform4iARB_Exec)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _glUniform3iARB_CompExec @ 0x8c8f4 (80 bytes) */
void _glUniform3iARB_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glUniform3iARB_Comp)(param_1,param_2,param_3,param_4,param_5);
  ((void (*)())_glUniform3iARB_Exec)(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glUniform2iARB_CompExec @ 0x8c944 (72 bytes) */
void _glUniform2iARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glUniform2iARB_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glUniform2iARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glUniform1iARB_CompExec @ 0x8c98c (64 bytes) */
void _glUniform1iARB_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glUniform1iARB_Comp)(param_1,param_2,param_3);
  ((void (*)())_glUniform1iARB_Exec)(param_1,param_2,param_3);
  return;
}

/* _glUniform4ivARB_CompExec @ 0x8c9cc (72 bytes) */
void _glUniform4ivARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glUniform4ivARB_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glUniform4ivARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glUniform3ivARB_CompExec @ 0x8ca14 (72 bytes) */
void _glUniform3ivARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glUniform3ivARB_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glUniform3ivARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glUniform2ivARB_CompExec @ 0x8ca5c (72 bytes) */
void _glUniform2ivARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glUniform2ivARB_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glUniform2ivARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glUniform1ivARB_CompExec @ 0x8caa4 (72 bytes) */
void _glUniform1ivARB_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  ((int (*)())_glUniform1ivARB_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glUniform1ivARB_Exec)(param_1,param_2,param_3,param_4);
  return;
}

/* _glUniform4fARB_ListExec @ 0x8caec (60 bytes) */
int _glUniform4fARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glUniform4fARB_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])),(double)GH_U2F((unsigned int)(param_2[2])),
             (double)GH_U2F((unsigned int)(param_2[3])),(double)GH_U2F((unsigned int)(param_2[4])));
  return 0x14;
}

/* _glUniform3fARB_ListExec @ 0x8cb28 (56 bytes) */
int _glUniform3fARB_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glUniform3fARB_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])),(double)GH_U2F((unsigned int)(param_2[2])),
             (double)GH_U2F((unsigned int)(param_2[3])));
  return 0x10;
}

