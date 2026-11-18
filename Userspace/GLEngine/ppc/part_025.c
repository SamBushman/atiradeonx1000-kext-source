#include "decls.h"

/* _glDeleteObjectARB_Exec @ 0x8719c (320 bytes) */
void _glDeleteObjectARB_Exec(glContext, obj)
  int glContext;
  int obj;
{
  undefined4 glErrorCode;
  int iVar2;
  int iVar3;
  
  if (obj == 0) {
    return;
  }
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar3 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar3 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar3 + 0x8028);
      iVar3 = *(int *)(glContext + 0x5148);
    }
    iVar3 = _gleLookupHashObject(iVar3 + 0x6018,obj);
    if (iVar3 == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_00087260;
    }
    if (*(char *)(iVar3 + 0x14) == '\0') {
      iVar2 = *(int *)(iVar3 + 8) + -1;
      *(int *)(iVar3 + 8) = iVar2;
      if (iVar2 == 1) {
        _gleDeleteHashNameAndObject(glContext,*(int *)(glContext + 0x5148) + 0x6018,obj);
      }
      else {
        *(undefined1 *)(iVar3 + 0x14) = 1;
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
LAB_00087260:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glAttachObjectARB_Exec @ 0x872dc (488 bytes) */
void _glAttachObjectARB_Exec(glContext, containerObj, obj)
  int glContext;
  undefined4 containerObj;
  undefined4 obj;
{
  undefined4 glErrorCode;
  int iVar2;
  int *srcCursor;
  int iVar4;
  int hashObject;
  int iVar6;
  int loopIndex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar4 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar4 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar4 + 0x8028);
      iVar4 = *(int *)(glContext + 0x5148);
    }
    iVar4 = _gleLookupHashObject(iVar4 + 0x6018,containerObj);
    if (iVar4 == 0) {
LAB_00087368:
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_000873fc;
    }
    if (*(int *)(iVar4 + 0x10) == 0x8b40) {
      hashObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x6018,obj);
      if (hashObject == 0) goto LAB_00087368;
      if (*(int *)(hashObject + 0x10) == 0x8b48) {
        iVar6 = *(int *)(iVar4 + 0x48);
        loopIndex = 0;
        if (0 < iVar6) {
          srcCursor = *(int **)(iVar4 + 0x44);
          do {
            iVar2 = *srcCursor;
            srcCursor = srcCursor + 1;
            if (iVar2 == hashObject) goto LAB_000873d0;
            loopIndex = loopIndex + 1;
          } while (loopIndex < iVar6);
        }
        iVar6 = _malloc(iVar6 * 4 + 4);
        loopIndex = 0;
        if (0 < *(int *)(iVar4 + 0x48)) {
          do {
            iVar2 = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(undefined4 *)(iVar2 + iVar6) = *(undefined4 *)(iVar2 + *(int *)(iVar4 + 0x44));
          } while (loopIndex < *(int *)(iVar4 + 0x48));
        }
        *(int *)(iVar6 + loopIndex * 4) = hashObject;
        *(int *)(iVar4 + 0x48) = *(int *)(iVar4 + 0x48) + 1;
        if (*(int *)(iVar4 + 0x44) != 0) {
          _free(*(int *)(iVar4 + 0x44));
        }
        *(int *)(iVar4 + 0x44) = iVar6;
        *(int *)(hashObject + 8) = *(int *)(hashObject + 8) + 1;
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return;
      }
    }
LAB_000873d0:
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_000873fc:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glDetachObjectARB_Exec @ 0x874c4 (552 bytes) */
void _glDetachObjectARB_Exec(glContext, containerObj, attachedObj)
  int glContext;
  undefined4 containerObj;
  undefined4 attachedObj;
{
  bool bVar1;
  undefined4 glErrorCode;
  int iVar3;
  int *piVar4;
  int *srcCursor;
  int iVar5;
  int hashObject;
  int iVar7;
  int *dstCursor;
  int iVar9;
  int loopIndex;
  int iVar10;
  int loopIndex2;
  
  bVar1 = false;
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar5 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar5 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar5 + 0x8028);
      iVar5 = *(int *)(glContext + 0x5148);
    }
    iVar5 = _gleLookupHashObject(iVar5 + 0x6018,containerObj);
    if (iVar5 == 0) {
LAB_00087554:
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_000875fc;
    }
    if (*(int *)(iVar5 + 0x10) == 0x8b40) {
      hashObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x6018,attachedObj);
      if (hashObject == 0) goto LAB_00087554;
      iVar9 = *(int *)(iVar5 + 0x48);
      loopIndex2 = 0;
      if (0 < iVar9) {
        srcCursor = *(int **)(iVar5 + 0x44);
        do {
          if (hashObject == *srcCursor) {
            bVar1 = true;
          }
          loopIndex2 = loopIndex2 + 1;
          srcCursor = srcCursor + 1;
          if (iVar9 <= loopIndex2) goto LAB_000875c8;
        } while (!bVar1);
LAB_00087604:
        piVar4 = (int *)0x0;
        iVar10 = 1;
        if (iVar9 != 1) {
          piVar4 = (int *)_malloc(iVar9 * 4 + -4);
          iVar10 = *(int *)(iVar5 + 0x48);
        }
        loopIndex = 0;
        if (iVar10 < 1) {
          iVar7 = *(int *)(iVar5 + 0x44);
        }
        else {
          iVar7 = *(int *)(iVar5 + 0x44);
          dstCursor = piVar4;
          do {
            iVar3 = *(int *)(loopIndex * 4 + iVar7);
            if (hashObject != iVar3) {
              *dstCursor = iVar3;
              dstCursor = dstCursor + 1;
              iVar10 = *(int *)(iVar5 + 0x48);
              iVar7 = *(int *)(iVar5 + 0x44);
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < iVar10);
        }
        *(int *)(iVar5 + 0x48) = iVar10 + -1;
        if (iVar7 != 0) {
          _free(iVar7);
        }
        *(int **)(iVar5 + 0x44) = piVar4;
        iVar5 = *(int *)(hashObject + 8) + -1;
        *(int *)(hashObject + 8) = iVar5;
        if (iVar5 == 1) {
          _gleDeleteHashNameAndObject(glContext,*(int *)(glContext + 0x5148) + 0x6018,attachedObj);
        }
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return;
      }
LAB_000875c8:
      if (bVar1) goto LAB_00087604;
    }
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
  }
  if (*(int *)(glContext + 0x7574) != 0) {
    return;
  }
  glErrorCode = 0x502;
LAB_000875fc:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glGetHandleARB_Exec @ 0x876ec (96 bytes) */
int _glGetHandleARB_Exec(glContext, pname)
  int glContext;
  int pname;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (pname == 0x8b40) {
      if (*(int *)(glContext + 0x5430) == 0) {
        return 0;
      }
      return *(undefined4 *)(*(int *)(glContext + 0x5430) + 4);
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x500;
  }
  else {
    if (*(int *)(glContext + 0x7574) != 0) {
      return 0;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return 0;
}

/* _glShaderSourceARB_Exec_body @ 0x87750 (716 bytes) */
void _glShaderSourceARB_Exec_body(glContext, forwardedArg2, param_3, param_4, param_5)
  int glContext;
  undefined4 forwardedArg2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  char cVar2;
  undefined4 glErrorCode;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int iVar9;
  int loopIndex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (0 < param_3) {
      iVar6 = *(int *)(glContext + 0x5148);
      if (*(char *)(iVar6 + 0x8024) != '\0') {
        _pthread_mutex_lock(iVar6 + 0x8028);
        iVar6 = *(int *)(glContext + 0x5148);
      }
      iVar6 = _gleLookupHashObject(iVar6 + 0x6018,forwardedArg2);
      if (iVar6 != 0) {
        if (*(int *)(iVar6 + 0x10) != 0x8b48) {
          if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
            _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
          }
          goto LAB_000877f0;
        }
        iVar9 = 0;
        loopIndex = 0;
        if (0 < param_3) {
          do {
            if (param_5 == 0) {
              iVar4 = loopIndex << 2;
LAB_00087834:
              iVar5 = _strlen(*(undefined4 *)(param_4 + iVar4));
            }
            else {
              iVar4 = loopIndex * 4;
              iVar5 = *(int *)(param_5 + iVar4);
              if (iVar5 < 0) goto LAB_00087834;
            }
            iVar9 = iVar9 + iVar5;
            loopIndex = loopIndex + 1;
          } while (loopIndex < param_3);
        }
        loopIndex = 0;
        bVar1 = param_3 == 0;
        pcVar7 = (char *)_malloc(iVar9 + 2);
        pcVar8 = pcVar7;
        if (0 < param_3) {
          do {
            if (param_5 == 0) {
              iVar4 = loopIndex << 2;
LAB_00087894:
              pcVar8 = _stpcpy(pcVar8,*(char **)(param_4 + iVar4));
            }
            else {
              iVar4 = loopIndex * 4;
              if ((int)*(size_t *)(iVar4 + param_5) < 0) goto LAB_00087894;
              _strncpy(pcVar8,*(char **)(iVar4 + param_4),*(size_t *)(iVar4 + param_5));
              pcVar8 = pcVar8 + *(int *)(iVar4 + param_5);
              if (pcVar8[-1] == '\0') break;
            }
            loopIndex = loopIndex + 1;
            bVar1 = loopIndex == param_3;
          } while (loopIndex < param_3);
        }
        *pcVar8 = '\0';
        if (bVar1) {
          loopIndex = 0;
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
            loopIndex = loopIndex + 1;
            cVar2 = *pcVar8;
          }
          if (pcVar7[loopIndex + -1] != '\n') {
            iVar9 = iVar9 + 1;
            pcVar7[loopIndex] = '\n';
            pcVar7[loopIndex + 1] = '\0';
          }
          if (*(int *)(iVar6 + 0x2c) != 0) {
            _free(*(int *)(iVar6 + 0x2c));
          }
          *(char **)(iVar6 + 0x2c) = pcVar7;
          *(undefined1 *)(iVar6 + 0x24) = 1;
          *(int *)(iVar6 + 0x28) = iVar9;
          if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
            return;
          }
          _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
          return;
        }
        _free(pcVar7);
      }
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
  }
  else {
LAB_000877f0:
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glCompileShaderARB_Exec @ 0x87a1c (252 bytes) */
void _glCompileShaderARB_Exec(glContext, shaderObj)
  int glContext;
  undefined4 shaderObj;
{
  undefined4 glErrorCode;
  int iVar2;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  iVar2 = *(int *)(glContext + 0x5148);
  if (*(char *)(iVar2 + 0x8024) != '\0') {
    _pthread_mutex_lock(iVar2 + 0x8028);
    iVar2 = *(int *)(glContext + 0x5148);
  }
  iVar2 = _gleLookupHashObject(iVar2 + 0x6018,shaderObj);
  if (iVar2 == 0) {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00087ad8;
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(iVar2 + 0x10) == 0x8b48) {
      _gleShaderParse(glContext,iVar2);
      goto LAB_00087ad8;
    }
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00087ad8;
    glErrorCode = 0x502;
  }
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
LAB_00087ad8:
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
    return;
  }
  _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
  return;
}

/* _evaluateImageUnits @ 0x87b18 (1000 bytes) */
int _evaluateImageUnits(glContext, param_2)
  int glContext;
  int param_2;
{
  ushort uVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  char *srcCursor;
  int iVar6;
  ushort *dstCursor2;
  ushort *srcCursor2;
  ushort *srcCursor3;
  int *dstCursor;
  int *piVar10;
  int loopIndex;
  uint loopIndex2;
  int *dstCursor3;
  int *srcCursor4;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int loopIndex3;
  int remaining;
  longlong lVar18;
  int local_120 [32];
  ushort local_a0 [32];
  undefined4 local_60;
  char local_5c [4];
  uint local_58;
  
  piVar10 = (int *)(param_2 + 0x20);
  loopIndex = 0;
  local_58 = (uint)*(byte *)(param_2 + 0x3e);
  *(undefined1 *)(param_2 + 0x3e) = 1;
  do {
    if (loopIndex == 0) {
      iVar16 = *piVar10;
      remaining = 0;
    }
    else {
      iVar16 = *(int *)(param_2 + 0x24);
      remaining = 0x10;
    }
    if (remaining != 0) {
      dstCursor3 = local_120 + loopIndex * 0x10;
      dstCursor2 = local_a0 + loopIndex * 0x10;
      iVar6 = iVar16 + 0x60;
      do {
        *dstCursor3 = *(int *)(iVar16 + 0x2c);
        dstCursor3 = dstCursor3 + 1;
        *dstCursor2 = *(ushort *)(iVar6 + 0xc);
        dstCursor2 = dstCursor2 + 1;
        *(undefined4 *)(iVar16 + 0x2c) = 0;
        iVar16 = iVar16 + 4;
        *(undefined2 *)(iVar6 + 0xc) = 0;
        iVar6 = iVar6 + 2;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
    loopIndex = loopIndex + 1;
  } while (loopIndex < 2);
  loopIndex = 0;
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
        iVar17 = _ShGetUniformTypeInfo(*(undefined4 *)(param_2 + 0x40),loopIndex,0,&local_60,local_5c);
        if ((iVar17 != 0) && (local_60 - 0x8b5d < 8)) {
          loopIndex3 = 0;
          srcCursor = local_5c;
          do {
            cVar3 = *srcCursor;
            srcCursor = srcCursor + 1;
            if (cVar3 != '\0') {
              iVar16 = *(int *)(*(int *)(param_2 + 0x4c) + loopIndex * 0x10);
              if (loopIndex3 == 0) {
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
            loopIndex3 = loopIndex3 + 1;
          } while (loopIndex3 < 2);
        }
        loopIndex = loopIndex + 1;
        if (*(int *)(param_2 + 0x30) <= loopIndex) goto LAB_00087d18;
        cVar3 = *(char *)(param_2 + 0x3e);
      } while (cVar3 == '\x01');
    }
  }
  if (cVar3 == '\0') {
    loopIndex = 0;
    do {
      if (loopIndex == 0) {
        iVar16 = *piVar10;
        remaining = 0;
      }
      else {
        iVar16 = *(int *)(param_2 + 0x24);
        remaining = 0x10;
      }
      if (remaining != 0) {
        srcCursor4 = local_120 + loopIndex * 0x10;
        srcCursor3 = local_a0 + loopIndex * 0x10;
        dstCursor = (int *)(iVar16 + 0x2c);
        dstCursor2 = (ushort *)(iVar16 + 0x6c);
        do {
          iVar16 = *srcCursor4;
          srcCursor4 = srcCursor4 + 1;
          *dstCursor = iVar16;
          dstCursor = dstCursor + 1;
          uVar1 = *srcCursor3;
          srcCursor3 = srcCursor3 + 1;
          *dstCursor2 = uVar1;
          dstCursor2 = dstCursor2 + 1;
          remaining = remaining + -1;
        } while (remaining != 0);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 2);
  }
  else {
    loopIndex = 0;
    do {
      if (loopIndex == 0) {
        iVar16 = *piVar10;
        iVar17 = 0;
      }
      else {
        iVar16 = *(int *)(param_2 + 0x24);
        iVar17 = 0x10;
      }
      loopIndex2 = 0;
      *(undefined4 *)(iVar16 + 0x50c) = 0xffffffff;
      *(undefined4 *)(iVar16 + 0x510) = 0xffffffff;
      if (iVar17 != 0) {
        srcCursor2 = (ushort *)(iVar16 + 0x6c);
        srcCursor4 = (int *)(iVar16 + 0x2c);
        do {
          iVar6 = *srcCursor4;
          srcCursor4 = srcCursor4 + 1;
          if (iVar6 != 0) {
            lVar18 = ___ashldi3(0,0xf,loopIndex2 << 2);
            uVar15 = *(uint *)(iVar16 + 0x510) & ~(uint)lVar18;
            uVar14 = *(uint *)(iVar16 + 0x50c) & ~(uint)((ulonglong)lVar18 >> 0x20);
            uVar1 = *srcCursor2;
            *(uint *)(iVar16 + 0x50c) = uVar14;
            *(uint *)(iVar16 + 0x510) = uVar15;
            uVar4 = _getIndexForGLSLSamplerType((uint)uVar1);
            lVar18 = ___ashldi3(0,uVar4,loopIndex2 << 2);
            *(uint *)(iVar16 + 0x50c) = uVar14 | (uint)((ulonglong)lVar18 >> 0x20);
            *(uint *)(iVar16 + 0x510) = uVar15 | (uint)lVar18;
          }
          if ((*(int *)(glContext + 0x5430) == param_2) &&
             ((iVar2 = loopIndex * 0x10 + loopIndex2, iVar6 != local_120[iVar2] ||
              ((iVar6 != 0 && (*srcCursor2 != local_a0[iVar2])))))) {
            *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 1 << (loopIndex2 & 0x3f);
          }
          loopIndex2 = loopIndex2 + 1;
          srcCursor2 = srcCursor2 + 1;
        } while ((int)loopIndex2 < iVar17);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 2);
  }
  return -(uint)(local_58 ^ *(byte *)(param_2 + 0x3e)) >> 0x1f;
}

/* _setImageUnit @ 0x87f00 (576 bytes) */
double _setImageUnit(int glContext,int param_2,uint param_3,uint param_4,char *param_5,uint param_6,double fparam_1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8)
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int loopIndex;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  double fparam_1_00;
  double extraout_f1;
  longlong lVar12;
  
  piVar8 = (int *)(param_2 + 0x20);
  if (*(char *)(param_2 + 0x3e) == '\0') {
    iVar3 = ((int (*)())_evaluateImageUnits)(glContext,param_2);
    if (iVar3 != 0) {
      ((void (*)())_updateShaderState)(glContext,piVar8,(uint)*(byte *)(glContext + 0x759c),
                         (uint)**(byte **)(param_2 + 0x20),(uint)**(byte **)(param_2 + 0x24),
                         fparam_1_00,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8)
      ;
      return;
    }
  }
  else {
    loopIndex = 0;
    iVar3 = param_3 * 4;
    do {
      cVar1 = *param_5;
      param_5 = param_5 + 1;
      if (cVar1 != '\0') {
        if (loopIndex == 0) {
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
          ((void (*)())_updateShaderState)(glContext,piVar8,(uint)*(byte *)(glContext + 0x759c),(uint)*(byte *)*piVar8
                             ,(uint)**(byte **)(param_2 + 0x24),fparam_1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,
                             forwardedFloatArg5,forwardedFloatArg6,forwardedFloatArg7,forwardedFloatArg8);
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
          if (*(int *)(glContext + 0x5430) == param_2) {
            *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 1 << (param_4 & 0x3f);
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
        if (*(int *)(glContext + 0x5430) == param_2) {
          *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 1 << (param_3 & 0x3f);
        }
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 2);
  }
  return;
}

/* _glLinkProgramARB_Exec @ 0x88140 (2600 bytes) */
void _glLinkProgramARB_Exec(glContext, programObj)
  int glContext;
  undefined4 programObj;
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
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar9 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar9 + 0x8024) != '\0') {
      _pthread_mutex_lock(iVar9 + 0x8028);
      iVar9 = *(int *)(glContext + 0x5148);
    }
    iVar9 = _gleLookupHashObject(iVar9 + 0x6018,programObj);
    if (iVar9 == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
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
          _PPEmulatorProgramFree(*(int *)(puVar17 + 0x4dc));
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
        uVar12 = _ShLink(*(undefined4 *)(iVar9 + 0x40),0,0,*(undefined4 *)(glContext + 0x7594),
                         *(undefined4 *)(glContext + 0x7598));
        *(undefined1 *)(iVar9 + 0x3c) = uVar12;
        *(undefined4 *)(iVar9 + 0x1c) = 0;
        if (*(int *)(iVar9 + 0x18) != 0) {
          _free(*(int *)(iVar9 + 0x18));
          *(undefined4 *)(iVar9 + 0x18) = 0;
        }
        ((int (*)())_evaluateImageUnits)(glContext,iVar9);
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
                         *(undefined4 *)(glContext + 0x7594),*(undefined4 *)(glContext + 0x7598));
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
                _PPEmulatorProgramSetupHandlesFromPPStream(uVar11,glContext,uVar4);
                _PPEmulatorProgramConvertFromPPStream(*(undefined4 *)(puVar17 + 0x4dc),uVar4);
                _PPStreamFree(uVar4);
              }
            }
            _gleShaderDataUpdateParams(puVar17);
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 < 2);
        ((int (*)())_evaluateImageUnits)(glContext,iVar9);
        if (*(char *)(glContext + 0x4693) == '\x01') {
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
      if (*(int *)(glContext + 0x5430) == iVar9) {
        ((void (*)())_updateShaderState)(glContext,piVar15,(uint)*(byte *)(glContext + 0x759c),(uint)bVar2,(uint)bVar3
                           ,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
      }
      iVar14 = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        iVar18 = glContext + 0x85a0;
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
        } while (iVar14 < (int)(uint)*(byte *)(glContext + 0x85a4));
      }
LAB_00088b38:
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
  uVar4 = 0x502;
LAB_00088210:
  *(undefined4 *)(glContext + 0x7574) = uVar4;
  return;
}

/* _glValidateProgramARB_Exec @ 0x88b68 (612 bytes) */
void _glValidateProgramARB_Exec(glContext, programObj)
  int glContext;
  undefined4 programObj;
{
  undefined4 glErrorCode;
  undefined4 stringLength2;
  int iVar2;
  int stringLength;
  char *pcVar4;
  char *pcVar5;
  
  pcVar5 = 
  "Validation Failed: Sampler error:\n  Samplers of different types use the same texture image unit.\n   - or -\n  A sampler\'s texture unit is out of range (greater than max allowed or negative).\n"
  ;
  if (*(short *)(glContext + 0x4a10) < 0) {
    iVar2 = *(int *)(glContext + 0x5148);
    if (*(char *)(iVar2 + 0x8024) != '\0') {
      _pthread_mutex_unlock(iVar2 + 0x8028);
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
      goto LAB_00088c48;
    }
    if (*(int *)(iVar2 + 0x10) == 0x8b40) {
      *(undefined1 *)(iVar2 + 0x3d) = 1;
      if (*(char *)(iVar2 + 0x3c) == '\0') {
        *(undefined1 *)(iVar2 + 0x3d) = 0;
        stringLength = _strlen("Validation Failed: Program is not successfully linked.\n");
        pcVar4 = (char *)_malloc(*(int *)(iVar2 + 0x1c) + stringLength + 2);
        if (*(char **)(iVar2 + 0x18) == (char *)0x0) {
          _strcpy(pcVar4,"Validation Failed: Program is not successfully linked.\n");
          stringLength = _strlen("Validation Failed: Program is not successfully linked.\n");
          pcVar4[stringLength] = '\0';
        }
        else {
          _strncpy(pcVar4,*(char **)(iVar2 + 0x18),*(size_t *)(iVar2 + 0x1c));
          pcVar4[*(int *)(iVar2 + 0x1c)] = '\n';
          _strcpy(pcVar4 + *(int *)(iVar2 + 0x1c) + 1,
                  "Validation Failed: Program is not successfully linked.\n");
          pcVar5 = "Validation Failed: Program is not successfully linked.\n";
LAB_00088d48:
          stringLength = _strlen(pcVar5);
          pcVar4[*(int *)(iVar2 + 0x1c) + stringLength + 1] = '\0';
          _free(*(undefined4 *)(iVar2 + 0x18));
        }
      }
      else {
        if (*(char *)(iVar2 + 0x3e) != '\0') goto LAB_00088d8c;
        *(undefined1 *)(iVar2 + 0x3d) = 0;
        stringLength = _strlen(
                       "Validation Failed: Sampler error:\n  Samplers of different types use the same texture image unit.\n   - or -\n  A sampler\'s texture unit is out of range (greater than max allowed or negative).\n"
                       );
        pcVar4 = (char *)_malloc(*(int *)(iVar2 + 0x1c) + stringLength + 2);
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
        stringLength = _strlen(
                       "Validation Failed: Sampler error:\n  Samplers of different types use the same texture image unit.\n   - or -\n  A sampler\'s texture unit is out of range (greater than max allowed or negative).\n"
                       );
        pcVar4[stringLength] = '\0';
      }
      *(char **)(iVar2 + 0x18) = pcVar4;
      stringLength2 = _strlen(pcVar4);
      *(undefined4 *)(iVar2 + 0x1c) = stringLength2;
LAB_00088d8c:
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
LAB_00088c48:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
  return;
}

/* _glUniform4fARB_Exec @ 0x88dcc (716 bytes) */
void _glUniform4fARB_Exec(int glContext,int location,float v0,float v1,float v2,float v3)
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  undefined4 uniformWord1;
  int currentProgram;
  int typeInfoFound;
  int rendererSlotOffset;
  int registerIndexThenOffset;
  int uniformValueSlot;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot2;
  undefined4 uniformWord2;
  int locationValueOffset;
  int rendererRecordCursor;
  int loopIndex;
  int rendererRecordCursor2;
  int loopIndex2;
  undefined4 uniformSize;
  int uniformType;
  undefined2 uniformStageUse [4];
  
  uniformStageUse[0] = 0;
  uniformType = 0;
  uniformSize = 0;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       ((typeInfoFound = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
        typeInfoFound != 0 && ((uniformType == 0x8b52 || (uniformType == 0x8b59)))))) {
      if (uniformType == 0x8b52) {
        uniformValueSlot = *(int *)(currentProgram + 0x4c) + location * 0x10;
        *(float *)(*(int *)(currentProgram + 0x4c) + location * 0x10) = (float)v0;
        *(float *)(uniformValueSlot + 0xc) = (float)v3;
        *(float *)(uniformValueSlot + 4) = (float)v1;
        *(float *)(uniformValueSlot + 8) = (float)v2;
      }
      else {
        uniformValueSlot = *(int *)(currentProgram + 0x4c) + location * 0x10;
        *(uint *)(*(int *)(currentProgram + 0x4c) + location * 0x10) =
             (uint)(v0 != (double)FLOAT_00108e50);
        *(uint *)(uniformValueSlot + 4) = (uint)(v1 != (double)FLOAT_00108e50);
        *(uint *)(uniformValueSlot + 8) = (uint)(v2 != (double)FLOAT_00108e50);
        *(uint *)(uniformValueSlot + 0xc) = (uint)(v3 != (double)FLOAT_00108e50);
      }
      locationValueOffset = location * 0x10;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
      stage0Record = *(int *)(currentProgram + 0x20);
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(stage0Record + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(stage0Record + 0x51c);
        rendererRecordCursor = glContext + 0x10000;
        uniformValueSlot2 = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot2 + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot2 + 0xc);
        loopIndex2 = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot2 + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
            rendererSlotOffset = loopIndex2 * 4;
            loopIndex2 = loopIndex2 + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
            rendererRecordCursor = rendererRecordCursor + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
        rendererRecordCursor2 = glContext + 0x10000;
        uniformValueSlot2 = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot2 + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot2 + 0xc);
        loopIndex = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot2 + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor2 + -0x777c);
            rendererSlotOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor2 + -0x7a54);
            rendererRecordCursor2 = rendererRecordCursor2 + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform3fARB_Exec @ 0x89098 (712 bytes) */
void _glUniform3fARB_Exec(int glContext,int location,float v0,float v1,float v2)
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  undefined4 uniformWord1;
  int currentProgram;
  int typeInfoFound;
  int rendererSlotOffset;
  int registerIndexThenOffset;
  int uniformValueSlot;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot2;
  undefined4 uniformWord2;
  int locationValueOffset;
  int rendererRecordCursor;
  int loopIndex;
  int rendererRecordCursor2;
  int loopIndex2;
  undefined4 uniformSize;
  int uniformType;
  undefined2 uniformStageUse [8];
  
  uniformStageUse[0] = 0;
  uniformType = 0;
  uniformSize = 0;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       ((typeInfoFound = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
        typeInfoFound != 0 && ((uniformType == 0x8b51 || (uniformType == 0x8b58)))))) {
      if (uniformType == 0x8b51) {
        uniformValueSlot = *(int *)(currentProgram + 0x4c) + location * 0x10;
        *(float *)(*(int *)(currentProgram + 0x4c) + location * 0x10) = (float)v0;
        *(float *)(uniformValueSlot + 8) = (float)v2;
        *(float *)(uniformValueSlot + 4) = (float)v1;
      }
      else {
        uniformValueSlot = *(int *)(currentProgram + 0x4c) + location * 0x10;
        *(uint *)(*(int *)(currentProgram + 0x4c) + location * 0x10) =
             (uint)(v0 != (double)FLOAT_00108e50);
        *(uint *)(uniformValueSlot + 4) = (uint)(v1 != (double)FLOAT_00108e50);
        *(uint *)(uniformValueSlot + 8) = (uint)(v2 != (double)FLOAT_00108e50);
      }
      locationValueOffset = location * 0x10;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
      stage0Record = *(int *)(currentProgram + 0x20);
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(stage0Record + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(stage0Record + 0x51c);
        rendererRecordCursor = glContext + 0x10000;
        uniformValueSlot2 = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot2 + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot2 + 0xc);
        loopIndex2 = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot2 + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
            rendererSlotOffset = loopIndex2 * 4;
            loopIndex2 = loopIndex2 + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
            rendererRecordCursor = rendererRecordCursor + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
        rendererRecordCursor2 = glContext + 0x10000;
        uniformValueSlot2 = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot2 + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot2 + 0xc);
        loopIndex = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot2 + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor2 + -0x777c);
            rendererSlotOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor2 + -0x7a54);
            rendererRecordCursor2 = rendererRecordCursor2 + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform2fARB_Exec @ 0x89360 (668 bytes) */
void _glUniform2fARB_Exec(int glContext,int location,float v0,float v1)
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  undefined4 uniformWord1;
  int currentProgram;
  int iVar5;
  int rendererSlotOffset;
  int registerIndexThenOffset;
  int typeInfoFound;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int locationValueOffset;
  int rendererRecordCursor;
  int loopIndex;
  int rendererRecordCursor2;
  int loopIndex2;
  undefined4 uniformSize;
  int uniformType;
  undefined2 uniformStageUse [4];
  
  uniformStageUse[0] = 0;
  uniformType = 0;
  uniformSize = 0;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       ((typeInfoFound = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
        typeInfoFound != 0 && ((uniformType == 0x8b50 || (uniformType == 0x8b57)))))) {
      if (uniformType == 0x8b50) {
        iVar5 = *(int *)(currentProgram + 0x4c);
        *(float *)(iVar5 + location * 0x10) = (float)v0;
        *(float *)(iVar5 + location * 0x10 + 4) = (float)v1;
      }
      else {
        iVar5 = *(int *)(currentProgram + 0x4c);
        *(uint *)(iVar5 + location * 0x10) = (uint)(v0 != (double)FLOAT_00108e50);
        *(uint *)(iVar5 + location * 0x10 + 4) = (uint)(v1 != (double)FLOAT_00108e50);
      }
      locationValueOffset = location * 0x10;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
      stage0Record = *(int *)(currentProgram + 0x20);
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(stage0Record + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(stage0Record + 0x51c);
        rendererRecordCursor = glContext + 0x10000;
        uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
        loopIndex2 = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
            rendererSlotOffset = loopIndex2 * 4;
            loopIndex2 = loopIndex2 + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
            rendererRecordCursor = rendererRecordCursor + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
        rendererRecordCursor2 = glContext + 0x10000;
        uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
        loopIndex = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor2 + -0x777c);
            rendererSlotOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor2 + -0x7a54);
            rendererRecordCursor2 = rendererRecordCursor2 + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform1fARB_Exec @ 0x895fc (600 bytes) */
void _glUniform1fARB_Exec(int glContext,int location,float v0)
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  undefined4 uniformWord1;
  int currentProgram;
  int typeInfoFound;
  int rendererSlotOffset;
  int registerIndexThenOffset;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int locationValueOffset;
  int rendererRecordCursor;
  int loopIndex;
  int rendererRecordCursor2;
  int loopIndex2;
  undefined4 uniformSize;
  int uniformType;
  undefined2 uniformStageUse [8];
  
  uniformStageUse[0] = 0;
  uniformType = 0;
  uniformSize = 0;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       ((typeInfoFound = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
        typeInfoFound != 0 && ((uniformType == 0x1406 || (uniformType == 0x8b56)))))) {
      if (uniformType == 0x1406) {
        *(float *)(*(int *)(currentProgram + 0x4c) + location * 0x10) = (float)v0;
      }
      else {
        *(uint *)(*(int *)(currentProgram + 0x4c) + location * 0x10) =
             (uint)(v0 != (double)FLOAT_00108e50);
      }
      locationValueOffset = location * 0x10;
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
      stage0Record = *(int *)(currentProgram + 0x20);
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(stage0Record + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(stage0Record + 0x51c);
        rendererRecordCursor = glContext + 0x10000;
        uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
        loopIndex2 = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
            rendererSlotOffset = loopIndex2 * 4;
            loopIndex2 = loopIndex2 + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
            rendererRecordCursor = rendererRecordCursor + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
        rendererRecordCursor2 = glContext + 0x10000;
        uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
        loopIndex = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor2 + -0x777c);
            rendererSlotOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor2 + -0x7a54);
            rendererRecordCursor2 = rendererRecordCursor2 + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform4fvARB_Exec @ 0x89854 (924 bytes) */
void _glUniform4fvARB_Exec(glContext, location, count, value)
  int glContext;
  int location;
  int count;
  float *value;
{
  float *srcLastElement;
  int *rendererCallbacks;
  bool stage0Updated;
  bool stage1Updated;
  float floatZero;
  undefined4 uniformWord1;
  int currentProgram;
  float *dstCursor;
  undefined4 *dstCursor2;
  undefined4 *rendererHandlePtr;
  int typeInfoFound;
  int rendererRecordCursor;
  int loopIndex;
  int elementValueOffset;
  int rendererSlotOffset;
  int elementMapOffset;
  int loopIndex2;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int registerIndexThenOffset;
  int uniformSize;
  int uniformType;
  undefined2 uniformStageUse [4];
  
  uniformType = 0;
  uniformStageUse[0] = 0;
  uniformSize = 0;
  stage0Updated = false;
  stage1Updated = false;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       (((-1 < count &&
         (typeInfoFound = _ShGetUniformTypeInfo
                             (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
         floatZero = FLOAT_00108e50, typeInfoFound != 0)) && ((uniformType == 0x8b52 || (uniformType == 0x8b59))))))
    {
      if (count != 0) {
        if (count < uniformSize) {
          uniformSize = count;
        }
        if (uniformType == 0x8b52) {
          loopIndex = 0;
          dstCursor = (float *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
          if (0 < uniformSize) {
            do {
              loopIndex = loopIndex + 1;
              *dstCursor = *value;
              dstCursor[1] = value[1];
              dstCursor[2] = value[2];
              srcLastElement = value + 3;
              value = value + 4;
              dstCursor[3] = *srcLastElement;
              dstCursor = dstCursor + 4;
            } while (loopIndex < uniformSize);
          }
        }
        else {
          loopIndex = 0;
          dstCursor2 = (undefined4 *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
          if (0 < uniformSize) {
            do {
              if (*value == floatZero) {
                *dstCursor2 = 0;
              }
              else {
                *dstCursor2 = 1;
              }
              if (value[1] == floatZero) {
                dstCursor2[1] = 0;
              }
              else {
                dstCursor2[1] = 1;
              }
              if (value[2] == floatZero) {
                dstCursor2[2] = 0;
              }
              else {
                dstCursor2[2] = 1;
              }
              if (value[3] == floatZero) {
                dstCursor2[3] = 0;
              }
              else {
                dstCursor2[3] = 1;
              }
              loopIndex = loopIndex + 1;
              dstCursor2 = dstCursor2 + 4;
              value = value + 4;
            } while (loopIndex < uniformSize);
          }
        }
        loopIndex = 0;
        if (0 < uniformSize) {
          elementMapOffset = location << 2;
          elementValueOffset = location << 4;
          do {
            stage0Record = *(int *)(currentProgram + 0x20);
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(stage0Record + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(stage0Record + 0x51c);
              stage0Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
              stage1Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            loopIndex = loopIndex + 1;
            elementMapOffset = elementMapOffset + 4;
            elementValueOffset = elementValueOffset + 0x10;
          } while (loopIndex < uniformSize);
        }
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
        if (stage0Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
        if (stage1Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform3fvARB_Exec @ 0x89bf0 (892 bytes) */
void _glUniform3fvARB_Exec(glContext, location, count, value)
  int glContext;
  int location;
  int count;
  float *value;
{
  float *srcLastElement;
  int *rendererCallbacks;
  bool stage0Updated;
  bool stage1Updated;
  float floatZero;
  undefined4 uniformWord1;
  int currentProgram;
  float *dstCursor;
  undefined4 *dstCursor2;
  undefined4 *rendererHandlePtr;
  int typeInfoFound;
  int rendererRecordCursor;
  int loopIndex;
  int elementValueOffset;
  int rendererSlotOffset;
  int elementMapOffset;
  int loopIndex2;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int registerIndexThenOffset;
  int uniformSize;
  int uniformType;
  undefined2 uniformStageUse [4];
  
  uniformType = 0;
  uniformStageUse[0] = 0;
  uniformSize = 0;
  stage0Updated = false;
  stage1Updated = false;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       (((-1 < count &&
         (typeInfoFound = _ShGetUniformTypeInfo
                             (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
         floatZero = FLOAT_00108e50, typeInfoFound != 0)) && ((uniformType == 0x8b51 || (uniformType == 0x8b58))))))
    {
      if (count != 0) {
        if (count < uniformSize) {
          uniformSize = count;
        }
        if (uniformType == 0x8b51) {
          loopIndex = 0;
          dstCursor = (float *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
          if (0 < uniformSize) {
            do {
              loopIndex = loopIndex + 1;
              *dstCursor = *value;
              dstCursor[1] = value[1];
              srcLastElement = value + 2;
              value = value + 3;
              dstCursor[2] = *srcLastElement;
              dstCursor = dstCursor + 4;
            } while (loopIndex < uniformSize);
          }
        }
        else {
          loopIndex = 0;
          dstCursor2 = (undefined4 *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
          if (0 < uniformSize) {
            do {
              if (*value == floatZero) {
                *dstCursor2 = 0;
              }
              else {
                *dstCursor2 = 1;
              }
              if (value[1] == floatZero) {
                dstCursor2[1] = 0;
              }
              else {
                dstCursor2[1] = 1;
              }
              if (value[2] == floatZero) {
                dstCursor2[2] = 0;
              }
              else {
                dstCursor2[2] = 1;
              }
              loopIndex = loopIndex + 1;
              dstCursor2 = dstCursor2 + 4;
              value = value + 3;
            } while (loopIndex < uniformSize);
          }
        }
        loopIndex = 0;
        if (0 < uniformSize) {
          elementMapOffset = location << 2;
          elementValueOffset = location << 4;
          do {
            stage0Record = *(int *)(currentProgram + 0x20);
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(stage0Record + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(stage0Record + 0x51c);
              stage0Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
              stage1Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            loopIndex = loopIndex + 1;
            elementMapOffset = elementMapOffset + 4;
            elementValueOffset = elementValueOffset + 0x10;
          } while (loopIndex < uniformSize);
        }
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
        if (stage0Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
        if (stage1Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform2fvARB_Exec @ 0x89f6c (860 bytes) */
void _glUniform2fvARB_Exec(glContext, location, count, value)
  int glContext;
  int location;
  int count;
  float *value;
{
  float *srcLastElement;
  int *rendererCallbacks;
  bool stage0Updated;
  bool stage1Updated;
  float floatZero;
  undefined4 uniformWord1;
  int currentProgram;
  float *dstCursor;
  undefined4 *dstCursor2;
  undefined4 *rendererHandlePtr;
  int typeInfoFound;
  int rendererRecordCursor;
  int loopIndex;
  int elementValueOffset;
  int rendererSlotOffset;
  int elementMapOffset;
  int loopIndex2;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int registerIndexThenOffset;
  int uniformSize;
  int uniformType;
  undefined2 uniformStageUse [4];
  
  uniformType = 0;
  uniformStageUse[0] = 0;
  uniformSize = 0;
  stage0Updated = false;
  stage1Updated = false;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       (((-1 < count &&
         (typeInfoFound = _ShGetUniformTypeInfo
                             (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
         floatZero = FLOAT_00108e50, typeInfoFound != 0)) && ((uniformType == 0x8b50 || (uniformType == 0x8b57))))))
    {
      if (count != 0) {
        if (count < uniformSize) {
          uniformSize = count;
        }
        if (uniformType == 0x8b50) {
          loopIndex = 0;
          dstCursor = (float *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
          if (0 < uniformSize) {
            do {
              loopIndex = loopIndex + 1;
              *dstCursor = *value;
              srcLastElement = value + 1;
              value = value + 2;
              dstCursor[1] = *srcLastElement;
              dstCursor = dstCursor + 4;
            } while (loopIndex < uniformSize);
          }
        }
        else {
          loopIndex = 0;
          dstCursor2 = (undefined4 *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
          if (0 < uniformSize) {
            do {
              if (*value == floatZero) {
                *dstCursor2 = 0;
              }
              else {
                *dstCursor2 = 1;
              }
              if (value[1] == floatZero) {
                dstCursor2[1] = 0;
              }
              else {
                dstCursor2[1] = 1;
              }
              loopIndex = loopIndex + 1;
              dstCursor2 = dstCursor2 + 4;
              value = value + 2;
            } while (loopIndex < uniformSize);
          }
        }
        loopIndex = 0;
        if (0 < uniformSize) {
          elementMapOffset = location << 2;
          elementValueOffset = location << 4;
          do {
            stage0Record = *(int *)(currentProgram + 0x20);
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(stage0Record + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(stage0Record + 0x51c);
              stage0Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
              stage1Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            loopIndex = loopIndex + 1;
            elementMapOffset = elementMapOffset + 4;
            elementValueOffset = elementValueOffset + 0x10;
          } while (loopIndex < uniformSize);
        }
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
        if (stage0Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
        if (stage1Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform1fvARB_Exec @ 0x8a2c8 (812 bytes) */
void _glUniform1fvARB_Exec(glContext, location, count, value)
  int glContext;
  int location;
  int count;
  float *value;
{
  int *rendererCallbacks;
  float fVar2;
  float floatZero;
  bool stage0Updated;
  bool stage1Updated;
  undefined4 uniformWord1;
  int currentProgram;
  float *dstCursor;
  undefined4 *rendererHandlePtr;
  undefined4 *dstCursor2;
  int typeInfoFound;
  int loopIndex;
  int elementValueOffset;
  int rendererSlotOffset;
  int elementMapOffset;
  int rendererRecordCursor;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int registerIndexThenOffset;
  int uniformSize;
  int uniformType;
  undefined2 uniformStageUse [10];
  
  uniformType = 0;
  uniformStageUse[0] = 0;
  uniformSize = 0;
  stage0Updated = false;
  stage1Updated = false;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       (((-1 < count &&
         (typeInfoFound = _ShGetUniformTypeInfo
                            (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
         floatZero = FLOAT_00108e50, typeInfoFound != 0)) && ((uniformType == 0x1406 || (uniformType == 0x8b56)))))) {
      if (count != 0) {
        if (count < uniformSize) {
          uniformSize = count;
        }
        if (uniformType == 0x1406) {
          loopIndex = 0;
          dstCursor = (float *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
          if (0 < uniformSize) {
            do {
              fVar2 = *value;
              loopIndex = loopIndex + 1;
              value = value + 1;
              *dstCursor = fVar2;
              dstCursor = dstCursor + 4;
            } while (loopIndex < uniformSize);
          }
        }
        else {
          loopIndex = 0;
          dstCursor2 = (undefined4 *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
          if (0 < uniformSize) {
            do {
              if (*value == floatZero) {
                *dstCursor2 = 0;
              }
              else {
                *dstCursor2 = 1;
              }
              loopIndex = loopIndex + 1;
              dstCursor2 = dstCursor2 + 4;
              value = value + 1;
            } while (loopIndex < uniformSize);
          }
        }
        loopIndex = 0;
        if (0 < uniformSize) {
          elementMapOffset = location << 2;
          elementValueOffset = location << 4;
          do {
            stage0Record = *(int *)(currentProgram + 0x20);
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(stage0Record + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(stage0Record + 0x51c);
              stage0Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
              stage1Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            loopIndex = loopIndex + 1;
            elementMapOffset = elementMapOffset + 4;
            elementValueOffset = elementValueOffset + 0x10;
          } while (loopIndex < uniformSize);
        }
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
        if (stage0Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex * 4;
              loopIndex = loopIndex + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
            } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
        if (stage1Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex * 4;
              loopIndex = loopIndex + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
            } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform4iARB_Exec @ 0x8a5f4 (684 bytes) */
void _glUniform4iARB_Exec(glContext, location, v0, v1, v2, v3)
  int glContext;
  int location;
  int v0;
  int v1;
  int v2;
  int v3;
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  undefined4 uniformWord1;
  int currentProgram;
  int iVar5;
  int rendererSlotOffset;
  int registerIndexThenOffset;
  int typeInfoFound;
  int rendererSlotOffset2;
  int locationValueOffset;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int constantRegister;
  int stage0Record;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int rendererRecordCursor;
  int loopIndex;
  int rendererRecordCursor2;
  int loopIndex2;
  undefined4 uniformSize;
  int uniformType;
  undefined2 uniformStageUse [10];
  
  uniformStageUse[0] = 0;
  uniformType = 0;
  uniformSize = 0;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       ((typeInfoFound = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
        typeInfoFound != 0 && ((uniformType == 0x8b55 || (uniformType == 0x8b59)))))) {
      locationValueOffset = location * 0x10;
      iVar5 = *(int *)(currentProgram + 0x4c);
      constantRegister = iVar5 + locationValueOffset;
      if (uniformType == 0x8b55) {
        *(int *)(iVar5 + locationValueOffset) = v0;
        *(int *)(constantRegister + 0xc) = v3;
        *(int *)(constantRegister + 4) = v1;
        *(int *)(constantRegister + 8) = v2;
      }
      else {
        if (v0 == 0) {
          *(undefined4 *)(iVar5 + locationValueOffset) = 0;
        }
        else {
          *(undefined4 *)(iVar5 + locationValueOffset) = 1;
        }
        if (v1 == 0) {
          *(undefined4 *)(constantRegister + 4) = 0;
        }
        else {
          *(undefined4 *)(constantRegister + 4) = 1;
        }
        if (v2 == 0) {
          *(undefined4 *)(constantRegister + 8) = 0;
        }
        else {
          *(undefined4 *)(constantRegister + 8) = 1;
        }
        if (v3 == 0) {
          *(undefined4 *)(constantRegister + 0xc) = 0;
        }
        else {
          *(undefined4 *)(constantRegister + 0xc) = 1;
        }
      }
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
      stage0Record = *(int *)(currentProgram + 0x20);
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(stage0Record + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(stage0Record + 0x51c);
        rendererRecordCursor = glContext + 0x10000;
        uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
        loopIndex2 = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
            rendererSlotOffset = loopIndex2 * 4;
            loopIndex2 = loopIndex2 + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
            rendererRecordCursor = rendererRecordCursor + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
        rendererRecordCursor2 = glContext + 0x10000;
        uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
        loopIndex = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor2 + -0x777c);
            rendererSlotOffset2 = loopIndex * 4;
            loopIndex = loopIndex + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor2 + -0x7a54);
            rendererRecordCursor2 = rendererRecordCursor2 + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset2 + *(int *)(currentProgram + 0x24) + 0x4e4),2);
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform3iARB_Exec @ 0x8a8a0 (652 bytes) */
void _glUniform3iARB_Exec(glContext, location, v0, v1, v2)
  int glContext;
  int location;
  int v0;
  int v1;
  int v2;
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  undefined4 uniformWord1;
  int currentProgram;
  int iVar5;
  int rendererSlotOffset;
  int registerIndexThenOffset;
  int typeInfoFound;
  int rendererSlotOffset2;
  int locationValueOffset;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int iVar9;
  int constantRegister;
  int stage0Record;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int rendererRecordCursor;
  int loopIndex;
  int rendererRecordCursor2;
  int loopIndex2;
  undefined4 uniformSize;
  int uniformType;
  undefined2 uniformStageUse [4];
  
  uniformStageUse[0] = 0;
  uniformType = 0;
  uniformSize = 0;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       ((typeInfoFound = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
        typeInfoFound != 0 && ((uniformType == 0x8b54 || (uniformType == 0x8b58)))))) {
      locationValueOffset = location * 0x10;
      iVar5 = *(int *)(currentProgram + 0x4c);
      iVar9 = iVar5 + locationValueOffset;
      if (uniformType == 0x8b54) {
        *(int *)(iVar5 + locationValueOffset) = v0;
        *(int *)(iVar9 + 8) = v2;
        *(int *)(iVar9 + 4) = v1;
      }
      else {
        if (v0 == 0) {
          *(undefined4 *)(iVar5 + locationValueOffset) = 0;
        }
        else {
          *(undefined4 *)(iVar5 + locationValueOffset) = 1;
        }
        if (v1 == 0) {
          *(undefined4 *)(iVar9 + 4) = 0;
        }
        else {
          *(undefined4 *)(iVar9 + 4) = 1;
        }
        if (v2 == 0) {
          *(undefined4 *)(iVar9 + 8) = 0;
        }
        else {
          *(undefined4 *)(iVar9 + 8) = 1;
        }
      }
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
      stage0Record = *(int *)(currentProgram + 0x20);
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(stage0Record + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(stage0Record + 0x51c);
        rendererRecordCursor = glContext + 0x10000;
        uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
        loopIndex2 = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
            rendererSlotOffset = loopIndex2 * 4;
            loopIndex2 = loopIndex2 + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
            rendererRecordCursor = rendererRecordCursor + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
          } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      registerIndexThenOffset = *(int *)(location * 4 + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
      if (registerIndexThenOffset != -1) {
        registerIndexThenOffset = registerIndexThenOffset * 0x10;
        constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
        rendererRecordCursor2 = glContext + 0x10000;
        uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
        uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
        constantRegister = registerIndexThenOffset + constantRegisterFile;
        uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
        loopIndex = 0;
        uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
        *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
        *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
        *(undefined4 *)(constantRegister + 4) = uniformWord1;
        *(undefined4 *)(constantRegister + 8) = uniformWord2;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor2 + -0x777c);
            rendererSlotOffset2 = loopIndex * 4;
            loopIndex = loopIndex + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor2 + -0x7a54);
            rendererRecordCursor2 = rendererRecordCursor2 + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset2 + *(int *)(currentProgram + 0x24) + 0x4e4),2);
          } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform2iARB_Exec @ 0x8ab2c (616 bytes) */
void _glUniform2iARB_Exec(glContext, location, v0, v1)
  int glContext;
  int location;
  int v0;
  int v1;
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  undefined4 uniformWord1;
  int currentProgram;
  int iVar5;
  int rendererSlotOffset;
  int registerIndexThenOffset;
  int typeInfoFound;
  int rendererSlotOffset2;
  int locationValueOffset;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int rendererRecordCursor;
  int loopIndex;
  int rendererRecordCursor2;
  int loopIndex2;
  undefined4 uniformSize;
  int uniformType;
  undefined2 uniformStageUse [4];
  
  uniformStageUse[0] = 0;
  uniformType = 0;
  uniformSize = 0;
  if (location == -1) {
    return;
  }
  if ((((-1 < *(short *)(glContext + 0x4a10)) || (currentProgram = *(int *)(glContext + 0x5430), currentProgram == 0)) ||
      (*(int *)(currentProgram + 0x30) <= location)) ||
     ((typeInfoFound = _ShGetUniformTypeInfo
                         (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
      typeInfoFound == 0 || ((uniformType != 0x8b53 && (uniformType != 0x8b57)))))) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  locationValueOffset = location * 0x10;
  iVar5 = *(int *)(currentProgram + 0x4c);
  if (uniformType == 0x8b53) {
    *(int *)(iVar5 + locationValueOffset) = v0;
  }
  else {
    if (v0 == 0) {
      *(undefined4 *)(iVar5 + locationValueOffset) = 0;
    }
    else {
      *(undefined4 *)(iVar5 + locationValueOffset) = 1;
    }
    if (v1 != 0) {
      *(undefined4 *)(iVar5 + locationValueOffset + 4) = 1;
      goto LAB_0008ac38;
    }
  }
  *(int *)(iVar5 + locationValueOffset + 4) = v1;
LAB_0008ac38:
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
  stage0Record = *(int *)(currentProgram + 0x20);
  registerIndexThenOffset = *(int *)(location * 4 + *(int *)(stage0Record + 0x4e0));
  if (registerIndexThenOffset != -1) {
    registerIndexThenOffset = registerIndexThenOffset * 0x10;
    constantRegisterFile = *(int *)(stage0Record + 0x51c);
    rendererRecordCursor = glContext + 0x10000;
    uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
    uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
    constantRegister = registerIndexThenOffset + constantRegisterFile;
    uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
    loopIndex2 = 0;
    uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
    *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
    *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
    *(undefined4 *)(constantRegister + 4) = uniformWord1;
    *(undefined4 *)(constantRegister + 8) = uniformWord2;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
        rendererSlotOffset = loopIndex2 * 4;
        loopIndex2 = loopIndex2 + 1;
        rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
        rendererRecordCursor = rendererRecordCursor + 0x2e0;
        (**(code **)(*rendererCallbacks + 0x194))
                  (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
      } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  registerIndexThenOffset = *(int *)(location * 4 + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
  if (registerIndexThenOffset != -1) {
    registerIndexThenOffset = registerIndexThenOffset * 0x10;
    constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
    rendererRecordCursor2 = glContext + 0x10000;
    uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
    uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
    constantRegister = registerIndexThenOffset + constantRegisterFile;
    uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
    loopIndex = 0;
    uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
    *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
    *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
    *(undefined4 *)(constantRegister + 4) = uniformWord1;
    *(undefined4 *)(constantRegister + 8) = uniformWord2;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        rendererCallbacks = (int *)(rendererRecordCursor2 + -0x777c);
        rendererSlotOffset2 = loopIndex * 4;
        loopIndex = loopIndex + 1;
        rendererHandlePtr = (undefined4 *)(rendererRecordCursor2 + -0x7a54);
        rendererRecordCursor2 = rendererRecordCursor2 + 0x2e0;
        (**(code **)(*rendererCallbacks + 0x194))
                  (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset2 + *(int *)(currentProgram + 0x24) + 0x4e4),2);
      } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  return;
}

/* _glUniform1iARB_Exec @ 0x8ad94 (756 bytes) */
void _glUniform1iARB_Exec(glContext, location, v0)
  int glContext;
  int location;
  int v0;
{
  int *rendererCallbacks;
  undefined4 *rendererHandlePtr;
  undefined4 uniformWord1;
  int typeInfoFound;
  int rendererSlotOffset;
  int locationValueOffset;
  int iVar5;
  int rendererSlotOffset2;
  int registerIndexThenOffset;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int iVar8;
  int constantRegister;
  int stage0Record;
  int uniformValueSlot;
  undefined4 uniformWord2;
  undefined4 uVar11;
  int currentProgram;
  int rendererRecordCursor;
  int loopIndex;
  int rendererRecordCursor2;
  int loopIndex2;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  undefined4 uniformSize;
  int uniformType;
  undefined2 uniformStageUse [10];
  
  uniformStageUse[0] = 0;
  uniformType = 0;
  uVar11 = 2;
  uniformSize = 0;
  if (location == -1) {
    return;
  }
  if (((((-1 < *(short *)(glContext + 0x4a10)) || (currentProgram = *(int *)(glContext + 0x5430), currentProgram == 0))
       || (*(int *)(currentProgram + 0x30) <= location)) ||
      (typeInfoFound = _ShGetUniformTypeInfo
                         (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
      typeInfoFound == 0)) ||
     ((((uniformType != 0x1404 && (uniformType != 0x8b56)) &&
       ((uniformType != 0x8b5d && ((uniformType != 0x8b5e && (uniformType != 0x8b5f)))))) &&
      ((uniformType != 0x8b60 &&
       ((((uniformType != 0x8b61 && (uniformType != 0x8b62)) && (uniformType != 0x8b63)) &&
        (uniformType != 0x8b64)))))))) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  iVar8 = *(int *)(currentProgram + 0x4c);
  locationValueOffset = location * 0x10;
  iVar5 = *(int *)(iVar8 + locationValueOffset);
  if (iVar5 == v0) {
    return;
  }
  if (uniformType != 0x1404) {
    if (uniformType - 0x8b5dU < 8) {
      *(int *)(iVar8 + locationValueOffset) = v0;
      uVar11 = 6;
      ((double (*)())_setImageUnit)(glContext,currentProgram,v0,iVar5,uniformStageUse,uniformType,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                    incomingFpr6,incomingFpr7,incomingFpr8);
      goto LAB_0008af2c;
    }
    if (v0 != 0) {
      *(undefined4 *)(iVar8 + locationValueOffset) = 1;
      goto LAB_0008af2c;
    }
  }
  *(int *)(iVar8 + locationValueOffset) = v0;
LAB_0008af2c:
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
  stage0Record = *(int *)(currentProgram + 0x20);
  registerIndexThenOffset = *(int *)(location * 4 + *(int *)(stage0Record + 0x4e0));
  if (registerIndexThenOffset != -1) {
    registerIndexThenOffset = registerIndexThenOffset * 0x10;
    constantRegisterFile = *(int *)(stage0Record + 0x51c);
    rendererRecordCursor = glContext + 0x10000;
    uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
    uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
    constantRegister = registerIndexThenOffset + constantRegisterFile;
    uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
    loopIndex2 = 0;
    uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
    *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
    *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
    *(undefined4 *)(constantRegister + 4) = uniformWord1;
    *(undefined4 *)(constantRegister + 8) = uniformWord2;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
        rendererSlotOffset2 = loopIndex2 * 4;
        loopIndex2 = loopIndex2 + 1;
        rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
        rendererRecordCursor = rendererRecordCursor + 0x2e0;
        (**(code **)(*rendererCallbacks + 0x194))
                  (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset2 + *(int *)(currentProgram + 0x20) + 0x4e4),uVar11);
      } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  registerIndexThenOffset = *(int *)(location * 4 + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
  if (registerIndexThenOffset != -1) {
    registerIndexThenOffset = registerIndexThenOffset * 0x10;
    constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
    rendererRecordCursor2 = glContext + 0x10000;
    uniformValueSlot = locationValueOffset + *(int *)(currentProgram + 0x4c);
    uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
    constantRegister = registerIndexThenOffset + constantRegisterFile;
    uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
    loopIndex = 0;
    uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
    *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(locationValueOffset + *(int *)(currentProgram + 0x4c));
    *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
    *(undefined4 *)(constantRegister + 4) = uniformWord1;
    *(undefined4 *)(constantRegister + 8) = uniformWord2;
    if (*(char *)(glContext + 0x85a4) != '\0') {
      do {
        rendererCallbacks = (int *)(rendererRecordCursor2 + -0x777c);
        rendererSlotOffset = loopIndex * 4;
        loopIndex = loopIndex + 1;
        rendererHandlePtr = (undefined4 *)(rendererRecordCursor2 + -0x7a54);
        rendererRecordCursor2 = rendererRecordCursor2 + 0x2e0;
        (**(code **)(*rendererCallbacks + 0x194))
                  (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),uVar11);
      } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
    }
  }
  return;
}

/* _glUniform4ivARB_Exec @ 0x8b088 (892 bytes) */
void _glUniform4ivARB_Exec(glContext, location, count, value)
  int glContext;
  int location;
  int count;
  int *value;
{
  int *srcLastElement;
  undefined4 *rendererHandlePtr;
  bool stage0Updated;
  bool stage1Updated;
  undefined4 uniformWord1;
  int currentProgram;
  int typeInfoFound;
  int rendererRecordCursor;
  int loopIndex;
  int elementValueOffset;
  int rendererSlotOffset;
  int elementMapOffset;
  int loopIndex2;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int *dstCursor;
  int *rendererCallbacks;
  int registerIndexThenOffset;
  int uniformSize;
  int uniformType;
  undefined2 uniformStageUse [4];
  
  uniformType = 0;
  uniformStageUse[0] = 0;
  uniformSize = 0;
  stage0Updated = false;
  stage1Updated = false;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       (((-1 < count &&
         (typeInfoFound = _ShGetUniformTypeInfo
                            (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
         typeInfoFound != 0)) && ((uniformType == 0x8b55 || (uniformType == 0x8b59)))))) {
      if (count != 0) {
        if (count < uniformSize) {
          uniformSize = count;
        }
        dstCursor = (int *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
        if (uniformType == 0x8b55) {
          loopIndex = 0;
          if (0 < uniformSize) {
            do {
              loopIndex = loopIndex + 1;
              *dstCursor = *value;
              dstCursor[1] = value[1];
              dstCursor[2] = value[2];
              srcLastElement = value + 3;
              value = value + 4;
              dstCursor[3] = *srcLastElement;
              dstCursor = dstCursor + 4;
            } while (loopIndex < uniformSize);
          }
        }
        else {
          loopIndex = 0;
          if (0 < uniformSize) {
            do {
              if (*value == 0) {
                *dstCursor = 0;
              }
              else {
                *dstCursor = 1;
              }
              if (value[1] == 0) {
                dstCursor[1] = 0;
              }
              else {
                dstCursor[1] = 1;
              }
              if (value[2] == 0) {
                dstCursor[2] = 0;
              }
              else {
                dstCursor[2] = 1;
              }
              if (value[3] == 0) {
                dstCursor[3] = 0;
              }
              else {
                dstCursor[3] = 1;
              }
              loopIndex = loopIndex + 1;
              dstCursor = dstCursor + 4;
              value = value + 4;
            } while (loopIndex < uniformSize);
          }
        }
        loopIndex = 0;
        if (0 < uniformSize) {
          elementMapOffset = location << 2;
          elementValueOffset = location << 4;
          do {
            stage0Record = *(int *)(currentProgram + 0x20);
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(stage0Record + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(stage0Record + 0x51c);
              stage0Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
              stage1Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            loopIndex = loopIndex + 1;
            elementMapOffset = elementMapOffset + 4;
            elementValueOffset = elementValueOffset + 0x10;
          } while (loopIndex < uniformSize);
        }
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
        if (stage0Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
        if (stage1Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform3ivARB_Exec @ 0x8b404 (860 bytes) */
void _glUniform3ivARB_Exec(glContext, location, count, value)
  int glContext;
  int location;
  int count;
  int *value;
{
  int *srcLastElement;
  undefined4 *rendererHandlePtr;
  bool stage0Updated;
  bool stage1Updated;
  undefined4 uniformWord1;
  int currentProgram;
  int typeInfoFound;
  int rendererRecordCursor;
  int loopIndex;
  int elementValueOffset;
  int rendererSlotOffset;
  int elementMapOffset;
  int loopIndex2;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int *dstCursor;
  int *rendererCallbacks;
  int registerIndexThenOffset;
  int uniformSize;
  int uniformType;
  undefined2 uniformStageUse [4];
  
  uniformType = 0;
  uniformStageUse[0] = 0;
  uniformSize = 0;
  stage0Updated = false;
  stage1Updated = false;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       (((-1 < count &&
         (typeInfoFound = _ShGetUniformTypeInfo
                            (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
         typeInfoFound != 0)) && ((uniformType == 0x8b54 || (uniformType == 0x8b58)))))) {
      if (count != 0) {
        if (count < uniformSize) {
          uniformSize = count;
        }
        dstCursor = (int *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
        if (uniformType == 0x8b54) {
          loopIndex = 0;
          if (0 < uniformSize) {
            do {
              loopIndex = loopIndex + 1;
              *dstCursor = *value;
              dstCursor[1] = value[1];
              srcLastElement = value + 2;
              value = value + 3;
              dstCursor[2] = *srcLastElement;
              dstCursor = dstCursor + 4;
            } while (loopIndex < uniformSize);
          }
        }
        else {
          loopIndex = 0;
          if (0 < uniformSize) {
            do {
              if (*value == 0) {
                *dstCursor = 0;
              }
              else {
                *dstCursor = 1;
              }
              if (value[1] == 0) {
                dstCursor[1] = 0;
              }
              else {
                dstCursor[1] = 1;
              }
              if (value[2] == 0) {
                dstCursor[2] = 0;
              }
              else {
                dstCursor[2] = 1;
              }
              loopIndex = loopIndex + 1;
              dstCursor = dstCursor + 4;
              value = value + 3;
            } while (loopIndex < uniformSize);
          }
        }
        loopIndex = 0;
        if (0 < uniformSize) {
          elementMapOffset = location << 2;
          elementValueOffset = location << 4;
          do {
            stage0Record = *(int *)(currentProgram + 0x20);
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(stage0Record + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(stage0Record + 0x51c);
              stage0Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
              stage1Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            loopIndex = loopIndex + 1;
            elementMapOffset = elementMapOffset + 4;
            elementValueOffset = elementValueOffset + 0x10;
          } while (loopIndex < uniformSize);
        }
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
        if (stage0Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
        if (stage1Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform2ivARB_Exec @ 0x8b760 (828 bytes) */
void _glUniform2ivARB_Exec(glContext, location, count, value)
  int glContext;
  int location;
  int count;
  int *value;
{
  int *srcLastElement;
  undefined4 *rendererHandlePtr;
  bool stage0Updated;
  bool stage1Updated;
  undefined4 uniformWord1;
  int currentProgram;
  int typeInfoFound;
  int rendererRecordCursor;
  int loopIndex;
  int elementValueOffset;
  int rendererSlotOffset;
  int elementMapOffset;
  int loopIndex2;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int *dstCursor;
  int *rendererCallbacks;
  int registerIndexThenOffset;
  int uniformSize;
  int uniformType;
  undefined2 uniformStageUse [4];
  
  uniformType = 0;
  uniformStageUse[0] = 0;
  uniformSize = 0;
  stage0Updated = false;
  stage1Updated = false;
  if (location != -1) {
    if ((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0)) &&
        (location < *(int *)(currentProgram + 0x30))) &&
       (((-1 < count &&
         (typeInfoFound = _ShGetUniformTypeInfo
                            (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
         typeInfoFound != 0)) && ((uniformType == 0x8b53 || (uniformType == 0x8b57)))))) {
      if (count != 0) {
        if (count < uniformSize) {
          uniformSize = count;
        }
        dstCursor = (int *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
        if (uniformType == 0x8b53) {
          loopIndex = 0;
          if (0 < uniformSize) {
            do {
              loopIndex = loopIndex + 1;
              *dstCursor = *value;
              srcLastElement = value + 1;
              value = value + 2;
              dstCursor[1] = *srcLastElement;
              dstCursor = dstCursor + 4;
            } while (loopIndex < uniformSize);
          }
        }
        else {
          loopIndex = 0;
          if (0 < uniformSize) {
            do {
              if (*value == 0) {
                *dstCursor = 0;
              }
              else {
                *dstCursor = 1;
              }
              if (value[1] == 0) {
                dstCursor[1] = 0;
              }
              else {
                dstCursor[1] = 1;
              }
              loopIndex = loopIndex + 1;
              dstCursor = dstCursor + 4;
              value = value + 2;
            } while (loopIndex < uniformSize);
          }
        }
        loopIndex = 0;
        if (0 < uniformSize) {
          elementMapOffset = location << 2;
          elementValueOffset = location << 4;
          do {
            stage0Record = *(int *)(currentProgram + 0x20);
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(stage0Record + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(stage0Record + 0x51c);
              stage0Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
              stage1Updated = true;
              uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            loopIndex = loopIndex + 1;
            elementMapOffset = elementMapOffset + 4;
            elementValueOffset = elementValueOffset + 0x10;
          } while (loopIndex < uniformSize);
        }
        *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
        if (stage0Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
        if (stage1Updated) {
          rendererRecordCursor = glContext + 0x10000;
          loopIndex2 = 0;
          if (*(char *)(glContext + 0x85a4) != '\0') {
            do {
              rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
              rendererSlotOffset = loopIndex2 * 4;
              loopIndex2 = loopIndex2 + 1;
              rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
              rendererRecordCursor = rendererRecordCursor + 0x2e0;
              (**(code **)(*rendererCallbacks + 0x194))
                        (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
            } while (loopIndex2 < (int)(uint)*(byte *)(glContext + 0x85a4));
          }
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform1ivARB_Exec @ 0x8ba9c (936 bytes) */
void _glUniform1ivARB_Exec(glContext, location, count, value)
  int glContext;
  int location;
  int count;
  int *value;
{
  undefined4 *rendererHandlePtr;
  bool stage0Updated;
  bool stage0Updated2;
  bool stage1Updated;
  int iVar5;
  int rendererSlotOffset;
  int elementValueOffset;
  undefined4 uniformWord1;
  int iVar7;
  int elementMapOffset;
  int typeInfoFound;
  int loopIndex;
  int iVar8;
  int registerIndexThenOffset;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int rendererRecordCursor;
  int loopIndex2;
  int currentProgram;
  int *dstCursor;
  int *rendererCallbacks;
  double extraout_f1;
  double fparam_1;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  int uniformSize;
  int uniformType;
  undefined2 uniformStageUse [6];
  
  uniformType = 0;
  uniformStageUse[0] = 0;
  uniformSize = 0;
  stage0Updated2 = false;
  stage1Updated = false;
  stage0Updated = false;
  if (location != -1) {
    if (((((*(short *)(glContext + 0x4a10) < 0) && (currentProgram = *(int *)(glContext + 0x5430), currentProgram != 0))
         && (location < *(int *)(currentProgram + 0x30))) &&
        ((-1 < count &&
         (typeInfoFound = _ShGetUniformTypeInfo
                            (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
         typeInfoFound != 0)))) &&
       ((((uniformType == 0x1404 || ((uniformType == 0x8b56 || (uniformType == 0x8b5d)))) ||
         ((uniformType == 0x8b5e ||
          ((((uniformType == 0x8b5f || (uniformType == 0x8b60)) || (uniformType == 0x8b61)) ||
           ((uniformType == 0x8b62 || (uniformType == 0x8b63)))))))) || (uniformType == 0x8b64)))) {
      if (count != 0) {
        if (count < uniformSize) {
          uniformSize = count;
        }
        loopIndex2 = 0;
        dstCursor = (int *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
        iVar7 = uniformSize;
        fparam_1 = extraout_f1;
        if (0 < uniformSize) {
          do {
            iVar8 = *dstCursor;
            iVar5 = *value;
            if (iVar8 != iVar5) {
              stage0Updated = true;
              iVar7 = uniformSize;
              if (uniformType == 0x1404) {
LAB_0008bc7c:
                *dstCursor = iVar5;
              }
              else if (uniformType - 0x8b5dU < 8) {
                *dstCursor = iVar5;
                fparam_1 = (double)((double (*)())_setImageUnit)(glContext,currentProgram,*value,iVar8,uniformStageUse,uniformType,
                                                 fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8)
                ;
                iVar7 = uniformSize;
              }
              else {
                if (iVar5 == 0) goto LAB_0008bc7c;
                *dstCursor = 1;
              }
            }
            loopIndex2 = loopIndex2 + 1;
            dstCursor = dstCursor + 4;
            value = value + 1;
          } while (loopIndex2 < iVar7);
          if (stage0Updated) {
            loopIndex2 = 0;
            if (0 < iVar7) {
              elementMapOffset = location << 2;
              elementValueOffset = location << 4;
              do {
                stage0Record = *(int *)(currentProgram + 0x20);
                registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(stage0Record + 0x4e0));
                if (registerIndexThenOffset != -1) {
                  registerIndexThenOffset = registerIndexThenOffset * 0x10;
                  constantRegisterFile = *(int *)(stage0Record + 0x51c);
                  stage0Updated2 = true;
                  uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
                  uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
                  constantRegister = registerIndexThenOffset + constantRegisterFile;
                  uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
                  uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
                  *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c))
                  ;
                  *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
                  *(undefined4 *)(constantRegister + 4) = uniformWord1;
                  *(undefined4 *)(constantRegister + 8) = uniformWord2;
                }
                registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
                if (registerIndexThenOffset != -1) {
                  registerIndexThenOffset = registerIndexThenOffset * 0x10;
                  constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
                  stage1Updated = true;
                  uniformValueSlot = elementValueOffset + *(int *)(currentProgram + 0x4c);
                  uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
                  constantRegister = registerIndexThenOffset + constantRegisterFile;
                  uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
                  uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
                  *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(elementValueOffset + *(int *)(currentProgram + 0x4c))
                  ;
                  *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
                  *(undefined4 *)(constantRegister + 4) = uniformWord1;
                  *(undefined4 *)(constantRegister + 8) = uniformWord2;
                }
                loopIndex2 = loopIndex2 + 1;
                elementMapOffset = elementMapOffset + 4;
                elementValueOffset = elementValueOffset + 0x10;
              } while (loopIndex2 < uniformSize);
            }
            *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
            if (stage0Updated2) {
              rendererRecordCursor = glContext + 0x10000;
              loopIndex = 0;
              if (*(char *)(glContext + 0x85a4) != '\0') {
                do {
                  rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
                  rendererSlotOffset = loopIndex * 4;
                  loopIndex = loopIndex + 1;
                  rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
                  rendererRecordCursor = rendererRecordCursor + 0x2e0;
                  (**(code **)(*rendererCallbacks + 0x194))
                            (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
                } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
              }
            }
            if (stage1Updated) {
              rendererRecordCursor = glContext + 0x10000;
              loopIndex = 0;
              if (*(char *)(glContext + 0x85a4) != '\0') {
                do {
                  rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
                  rendererSlotOffset = loopIndex * 4;
                  loopIndex = loopIndex + 1;
                  rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
                  rendererRecordCursor = rendererRecordCursor + 0x2e0;
                  (**(code **)(*rendererCallbacks + 0x194))
                            (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
                } while (loopIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
              }
            }
          }
        }
      }
    }
    else if (*(int *)(glContext + 0x7574) == 0) {
      *(undefined4 *)(glContext + 0x7574) = 0x502;
    }
  }
  return;
}

/* _glUniform4fARB_Comp @ 0x8be44 (100 bytes) */
void _glUniform4fARB_Comp(undefined4 glContext,undefined4 location,float v0,float v1,float v2,float v3)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glUniform4fARB_ListExec_00110300,0x14);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[4] = (float)v3;
    *listRecord = location;
    listRecord[1] = (float)v0;
    listRecord[2] = (float)v1;
    listRecord[3] = (float)v2;
  }
  return;
}

/* _glUniform3fARB_Comp @ 0x8bea8 (124 bytes) */
undefined4 * _glUniform3fARB_Comp(undefined4 glContext,undefined4 location,float v0,float v1,float v2)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glUniform3fARB_ListExec_001102fc,0x10);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[3] = (float)v2;
    *listRecord = location;
    listRecord[1] = (float)v0;
    listRecord[2] = (float)v1;
  }
  return listRecord;
}

/* _glUniform2fARB_Comp @ 0x8bf24 (108 bytes) */
undefined4 * _glUniform2fARB_Comp(undefined4 glContext,undefined4 location,float v0,float v1)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glUniform2fARB_ListExec_001102f8,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = (float)v1;
    *listRecord = location;
    listRecord[1] = (float)v0;
  }
  return listRecord;
}

/* _glUniform1fARB_Comp @ 0x8bf90 (92 bytes) */
undefined4 * _glUniform1fARB_Comp(undefined4 glContext,undefined4 location,float v0)
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glUniform1fARB_ListExec_001102f4,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = (float)v0;
    *listRecord = location;
  }
  return listRecord;
}

/* _glUniform4fvARB_Comp @ 0x8bfec (160 bytes) */
int _glUniform4fvARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform4fvARB_ListExec_001102f0,count * 0x10 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = count;
    loopIndex = 0;
    *puVar2 = location;
    puVar2 = puVar2 + 2;
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
  return puVar2;
}

/* _glUniform3fvARB_Comp @ 0x8c08c (152 bytes) */
int _glUniform3fvARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform3fvARB_ListExec_001102ec,count * 0xc + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = count;
    loopIndex = 0;
    *puVar2 = location;
    puVar2 = puVar2 + 2;
    while( true ) {
      *puVar2 = *value;
      puVar2[1] = value[1];
      puVar2[2] = value[2];
      if (loopIndex == count + -1) break;
      puVar2 = puVar2 + 3;
      value = value + 3;
      loopIndex = loopIndex + 1;
    }
  }
  return puVar2;
}

/* _glUniform2fvARB_Comp @ 0x8c124 (144 bytes) */
int _glUniform2fvARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform2fvARB_ListExec_001102e8,count * 8 + 8);
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = count;
    loopIndex = 0;
    *puVar2 = location;
    while( true ) {
      puVar3 = puVar2 + 2;
      *puVar3 = *value;
      puVar2[3] = value[1];
      if (loopIndex == count + -1) break;
      value = value + 2;
      loopIndex = loopIndex + 1;
      puVar2 = puVar3;
    }
  }
  return puVar3;
}

/* _glUniform1fvARB_Comp @ 0x8c1b4 (136 bytes) */
int _glUniform1fvARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform1fvARB_ListExec_001102e4,count * 4 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = count;
    *puVar2 = location;
    puVar2 = puVar2 + 2;
    for (loopIndex = 0; *puVar2 = *value, loopIndex != count + -1; loopIndex = loopIndex + 1) {
      puVar2 = puVar2 + 1;
      value = value + 1;
    }
  }
  return puVar2;
}

/* _glUniform4iARB_Comp @ 0x8c23c (108 bytes) */
int _glUniform4iARB_Comp(glContext, location, v0, v1, v2, v3)
  undefined4 glContext;
  undefined4 location;
  undefined4 v0;
  undefined4 v1;
  undefined4 v2;
  undefined4 v3;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glUniform4iARB_ListExec_001102e0,0x14);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[4] = v3;
    *listRecord = location;
    listRecord[1] = v0;
    listRecord[2] = v1;
    listRecord[3] = v2;
  }
  return listRecord;
}

/* _glUniform3iARB_Comp @ 0x8c2a8 (100 bytes) */
int _glUniform3iARB_Comp(glContext, location, v0, v1, v2)
  undefined4 glContext;
  undefined4 location;
  undefined4 v0;
  undefined4 v1;
  undefined4 v2;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glUniform3iARB_ListExec_001102dc,0x10);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[3] = v2;
    *listRecord = location;
    listRecord[1] = v0;
    listRecord[2] = v1;
  }
  return listRecord;
}

/* _glUniform2iARB_Comp @ 0x8c30c (92 bytes) */
int _glUniform2iARB_Comp(glContext, location, v0, v1)
  undefined4 glContext;
  undefined4 location;
  undefined4 v0;
  undefined4 v1;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glUniform2iARB_ListExec_001102d8,0xc);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[2] = v1;
    *listRecord = location;
    listRecord[1] = v0;
  }
  return listRecord;
}

/* _glUniform1iARB_Comp @ 0x8c368 (84 bytes) */
int _glUniform1iARB_Comp(glContext, location, v0)
  undefined4 glContext;
  undefined4 location;
  undefined4 v0;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glUniform1iARB_ListExec_001102d4,8);
  if (listRecord != (undefined4 *)0x0) {
    listRecord[1] = v0;
    *listRecord = location;
  }
  return listRecord;
}

/* _glUniform4ivARB_Comp @ 0x8c3bc (160 bytes) */
int _glUniform4ivARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  undefined4 *puVar1;
  int loopIndex;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform4ivARB_ListExec_001102d0,count * 0x10 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = count;
    loopIndex = 0;
    *puVar1 = location;
    puVar1 = puVar1 + 2;
    while( true ) {
      *puVar1 = *value;
      puVar1[1] = value[1];
      puVar1[2] = value[2];
      puVar1[3] = value[3];
      if (loopIndex == count + -1) break;
      puVar1 = puVar1 + 4;
      value = value + 4;
      loopIndex = loopIndex + 1;
    }
  }
  return puVar1;
}

/* _glUniform3ivARB_Comp @ 0x8c45c (152 bytes) */
int _glUniform3ivARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  undefined4 *puVar1;
  int loopIndex;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform3ivARB_ListExec_001102cc,count * 0xc + 8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = count;
    loopIndex = 0;
    *puVar1 = location;
    puVar1 = puVar1 + 2;
    while( true ) {
      *puVar1 = *value;
      puVar1[1] = value[1];
      puVar1[2] = value[2];
      if (loopIndex == count + -1) break;
      puVar1 = puVar1 + 3;
      value = value + 3;
      loopIndex = loopIndex + 1;
    }
  }
  return puVar1;
}

/* _glUniform2ivARB_Comp @ 0x8c4f4 (144 bytes) */
int _glUniform2ivARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int loopIndex;
  
  puVar1 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform2ivARB_ListExec_001102c8,count * 8 + 8);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = count;
    loopIndex = 0;
    *puVar1 = location;
    while( true ) {
      puVar2 = puVar1 + 2;
      *puVar2 = *value;
      puVar1[3] = value[1];
      if (loopIndex == count + -1) break;
      value = value + 2;
      loopIndex = loopIndex + 1;
      puVar1 = puVar2;
    }
  }
  return puVar2;
}

/* _glUniform1ivARB_Comp @ 0x8c584 (136 bytes) */
int _glUniform1ivARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform1ivARB_ListExec_001102c4,count * 4 + 8);
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = count;
    *puVar2 = location;
    puVar2 = puVar2 + 2;
    for (loopIndex = 0; *puVar2 = *value, loopIndex != count + -1; loopIndex = loopIndex + 1) {
      puVar2 = puVar2 + 1;
      value = value + 1;
    }
  }
  return puVar2;
}

/* _glUniform4fARB_CompExec @ 0x8c60c (104 bytes) */
void _glUniform4fARB_CompExec(undefined4 glContext,undefined4 location,float v0,float v1,float v2,float v3)
{
  ((void (*)())_glUniform4fARB_Comp)(glContext,location,v0,v1,v2,v3);
  ((void (*)())_glUniform4fARB_Exec)(glContext,location,v0,v1,v2,v3);
  return;
}

/* _glUniform3fARB_CompExec @ 0x8c674 (104 bytes) */
void _glUniform3fARB_CompExec(undefined4 glContext,undefined4 location,float v0,float v1,float v2)
{
  ((undefined4 * (*)())_glUniform3fARB_Comp)(glContext,location,v0,v1,v2);
  ((void (*)())_glUniform3fARB_Exec)(glContext,location,v0,v1,v2);
  return;
}

/* _glUniform2fARB_CompExec @ 0x8c6dc (88 bytes) */
void _glUniform2fARB_CompExec(undefined4 glContext,undefined4 location,float v0,float v1)
{
  ((undefined4 * (*)())_glUniform2fARB_Comp)(glContext,location,v0,v1);
  ((void (*)())_glUniform2fARB_Exec)(glContext,location,v0,v1);
  return;
}

/* _glUniform1fARB_CompExec @ 0x8c734 (72 bytes) */
void _glUniform1fARB_CompExec(undefined4 glContext,undefined4 location,float v0)
{
  ((undefined4 * (*)())_glUniform1fARB_Comp)(glContext,location,v0);
  ((void (*)())_glUniform1fARB_Exec)(glContext,location,v0);
  return;
}

/* _glUniform4fvARB_CompExec @ 0x8c77c (72 bytes) */
void _glUniform4fvARB_CompExec(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  undefined4 count;
  undefined4 value;
{
  ((int (*)())_glUniform4fvARB_Comp)(glContext,location,count,value);
  ((void (*)())_glUniform4fvARB_Exec)(glContext,location,count,value);
  return;
}

/* _glUniform3fvARB_CompExec @ 0x8c7c4 (72 bytes) */
void _glUniform3fvARB_CompExec(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  undefined4 count;
  undefined4 value;
{
  ((int (*)())_glUniform3fvARB_Comp)(glContext,location,count,value);
  ((void (*)())_glUniform3fvARB_Exec)(glContext,location,count,value);
  return;
}

/* _glUniform2fvARB_CompExec @ 0x8c80c (72 bytes) */
void _glUniform2fvARB_CompExec(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  undefined4 count;
  undefined4 value;
{
  ((int (*)())_glUniform2fvARB_Comp)(glContext,location,count,value);
  ((void (*)())_glUniform2fvARB_Exec)(glContext,location,count,value);
  return;
}

/* _glUniform1fvARB_CompExec @ 0x8c854 (72 bytes) */
void _glUniform1fvARB_CompExec(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  undefined4 count;
  undefined4 value;
{
  ((int (*)())_glUniform1fvARB_Comp)(glContext,location,count,value);
  ((void (*)())_glUniform1fvARB_Exec)(glContext,location,count,value);
  return;
}

/* _glUniform4iARB_CompExec @ 0x8c89c (88 bytes) */
void _glUniform4iARB_CompExec(glContext, location, v0, v1, v2, v3)
  undefined4 glContext;
  undefined4 location;
  undefined4 v0;
  undefined4 v1;
  undefined4 v2;
  undefined4 v3;
{
  ((int (*)())_glUniform4iARB_Comp)(glContext,location,v0,v1,v2,v3);
  ((void (*)())_glUniform4iARB_Exec)(glContext,location,v0,v1,v2,v3);
  return;
}

/* _glUniform3iARB_CompExec @ 0x8c8f4 (80 bytes) */
void _glUniform3iARB_CompExec(glContext, location, v0, v1, v2)
  undefined4 glContext;
  undefined4 location;
  undefined4 v0;
  undefined4 v1;
  undefined4 v2;
{
  ((int (*)())_glUniform3iARB_Comp)(glContext,location,v0,v1,v2);
  ((void (*)())_glUniform3iARB_Exec)(glContext,location,v0,v1,v2);
  return;
}

/* _glUniform2iARB_CompExec @ 0x8c944 (72 bytes) */
void _glUniform2iARB_CompExec(glContext, location, v0, v1)
  undefined4 glContext;
  undefined4 location;
  undefined4 v0;
  undefined4 v1;
{
  ((int (*)())_glUniform2iARB_Comp)(glContext,location,v0,v1);
  ((void (*)())_glUniform2iARB_Exec)(glContext,location,v0,v1);
  return;
}

/* _glUniform1iARB_CompExec @ 0x8c98c (64 bytes) */
void _glUniform1iARB_CompExec(glContext, location, v0)
  undefined4 glContext;
  undefined4 location;
  undefined4 v0;
{
  ((int (*)())_glUniform1iARB_Comp)(glContext,location,v0);
  ((void (*)())_glUniform1iARB_Exec)(glContext,location,v0);
  return;
}

/* _glUniform4ivARB_CompExec @ 0x8c9cc (72 bytes) */
void _glUniform4ivARB_CompExec(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  undefined4 count;
  undefined4 value;
{
  ((int (*)())_glUniform4ivARB_Comp)(glContext,location,count,value);
  ((void (*)())_glUniform4ivARB_Exec)(glContext,location,count,value);
  return;
}

/* _glUniform3ivARB_CompExec @ 0x8ca14 (72 bytes) */
void _glUniform3ivARB_CompExec(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  undefined4 count;
  undefined4 value;
{
  ((int (*)())_glUniform3ivARB_Comp)(glContext,location,count,value);
  ((void (*)())_glUniform3ivARB_Exec)(glContext,location,count,value);
  return;
}

/* _glUniform2ivARB_CompExec @ 0x8ca5c (72 bytes) */
void _glUniform2ivARB_CompExec(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  undefined4 count;
  undefined4 value;
{
  ((int (*)())_glUniform2ivARB_Comp)(glContext,location,count,value);
  ((void (*)())_glUniform2ivARB_Exec)(glContext,location,count,value);
  return;
}

/* _glUniform1ivARB_CompExec @ 0x8caa4 (72 bytes) */
void _glUniform1ivARB_CompExec(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  undefined4 count;
  undefined4 value;
{
  ((int (*)())_glUniform1ivARB_Comp)(glContext,location,count,value);
  ((void (*)())_glUniform1ivARB_Exec)(glContext,location,count,value);
  return;
}

/* _glUniform4fARB_ListExec @ 0x8caec (60 bytes) */
int _glUniform4fARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glUniform4fARB_Exec)(glContext,*listRecord,(double)GH_U2F((unsigned int)(listRecord[1])),(double)GH_U2F((unsigned int)(listRecord[2])),
             (double)GH_U2F((unsigned int)(listRecord[3])),(double)GH_U2F((unsigned int)(listRecord[4])));
  return 0x14;
}

/* _glUniform3fARB_ListExec @ 0x8cb28 (56 bytes) */
int _glUniform3fARB_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glUniform3fARB_Exec)(glContext,*listRecord,(double)GH_U2F((unsigned int)(listRecord[1])),(double)GH_U2F((unsigned int)(listRecord[2])),
             (double)GH_U2F((unsigned int)(listRecord[3])));
  return 0x10;
}

