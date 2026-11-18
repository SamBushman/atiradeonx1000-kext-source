#include "decls.h"

/* _glDeleteObjectARB_Exec @ 0x8719c (320 bytes) */
void _glDeleteObjectARB_Exec(glContext, obj)
  int glContext;
  int obj;
{
  undefined4 glErrorCode;
  int remainingRefCount;
  int sharedStateThenHandleObject;
  
  if (obj == 0) {
    return;
  }
  if (*(short *)(glContext + 0x4a10) < 0) {
    sharedStateThenHandleObject = *(int *)(glContext + 0x5148);
    if (*(char *)(sharedStateThenHandleObject + 0x8024) != '\0') {
      _pthread_mutex_lock(sharedStateThenHandleObject + 0x8028);
      sharedStateThenHandleObject = *(int *)(glContext + 0x5148);
    }
    sharedStateThenHandleObject = _gleLookupHashObject(sharedStateThenHandleObject + 0x6018,obj);
    if (sharedStateThenHandleObject == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_00087260;
    }
    if (*(char *)(sharedStateThenHandleObject + 0x14) == '\0') {
      remainingRefCount = *(int *)(sharedStateThenHandleObject + 8) + -1;
      *(int *)(sharedStateThenHandleObject + 8) = remainingRefCount;
      if (remainingRefCount == 1) {
        _gleDeleteHashNameAndObject(glContext,*(int *)(glContext + 0x5148) + 0x6018,obj);
      }
      else {
        *(undefined1 *)(sharedStateThenHandleObject + 0x14) = 1;
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
  int attachedObject;
  int byteOffset;
  int *srcCursor;
  int sharedStateThenContainerObject;
  int hashObject;
  int attachedCount;
  int newAttachedObjects;
  int loopIndex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    sharedStateThenContainerObject = *(int *)(glContext + 0x5148);
    if (*(char *)(sharedStateThenContainerObject + 0x8024) != '\0') {
      _pthread_mutex_lock(sharedStateThenContainerObject + 0x8028);
      sharedStateThenContainerObject = *(int *)(glContext + 0x5148);
    }
    sharedStateThenContainerObject = _gleLookupHashObject(sharedStateThenContainerObject + 0x6018,containerObj);
    if (sharedStateThenContainerObject == 0) {
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
    if (*(int *)(sharedStateThenContainerObject + 0x10) == 0x8b40) {
      hashObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x6018,obj);
      if (hashObject == 0) goto LAB_00087368;
      if (*(int *)(hashObject + 0x10) == 0x8b48) {
        attachedCount = *(int *)(sharedStateThenContainerObject + 0x48);
        loopIndex = 0;
        if (0 < attachedCount) {
          srcCursor = *(int **)(sharedStateThenContainerObject + 0x44);
          do {
            attachedObject = *srcCursor;
            srcCursor = srcCursor + 1;
            if (attachedObject == hashObject) goto LAB_000873d0;
            loopIndex = loopIndex + 1;
          } while (loopIndex < attachedCount);
        }
        newAttachedObjects = _malloc(attachedCount * 4 + 4);
        loopIndex = 0;
        if (0 < *(int *)(sharedStateThenContainerObject + 0x48)) {
          do {
            byteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(undefined4 *)(byteOffset + newAttachedObjects) = *(undefined4 *)(byteOffset + *(int *)(sharedStateThenContainerObject + 0x44));
          } while (loopIndex < *(int *)(sharedStateThenContainerObject + 0x48));
        }
        *(int *)(newAttachedObjects + loopIndex * 4) = hashObject;
        *(int *)(sharedStateThenContainerObject + 0x48) = *(int *)(sharedStateThenContainerObject + 0x48) + 1;
        if (*(int *)(sharedStateThenContainerObject + 0x44) != 0) {
          _free(*(int *)(sharedStateThenContainerObject + 0x44));
        }
        *(int *)(sharedStateThenContainerObject + 0x44) = newAttachedObjects;
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
  bool attachmentFound;
  undefined4 glErrorCode;
  int attachmentEntry;
  int *newAttachments;
  int *srcCursor;
  int sharedStateThenContainerObject;
  int attachedRefCount;
  int hashObject;
  int oldAttachments;
  int *dstCursor;
  int attachmentCount;
  int loopIndex;
  int attachmentScanIndexThenAttachmentCountForCopy;
  
  attachmentFound = false;
  if (*(short *)(glContext + 0x4a10) < 0) {
    sharedStateThenContainerObject = *(int *)(glContext + 0x5148);
    if (*(char *)(sharedStateThenContainerObject + 0x8024) != '\0') {
      _pthread_mutex_lock(sharedStateThenContainerObject + 0x8028);
      sharedStateThenContainerObject = *(int *)(glContext + 0x5148);
    }
    sharedStateThenContainerObject = _gleLookupHashObject(sharedStateThenContainerObject + 0x6018,containerObj);
    if (sharedStateThenContainerObject == 0) {
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
    if (*(int *)(sharedStateThenContainerObject + 0x10) == 0x8b40) {
      hashObject = _gleLookupHashObject(*(int *)(glContext + 0x5148) + 0x6018,attachedObj);
      if (hashObject == 0) goto LAB_00087554;
      attachmentCount = *(int *)(sharedStateThenContainerObject + 0x48);
      attachmentScanIndexThenAttachmentCountForCopy = 0;
      if (0 < attachmentCount) {
        srcCursor = *(int **)(sharedStateThenContainerObject + 0x44);
        do {
          if (hashObject == *srcCursor) {
            attachmentFound = true;
          }
          attachmentScanIndexThenAttachmentCountForCopy = attachmentScanIndexThenAttachmentCountForCopy + 1;
          srcCursor = srcCursor + 1;
          if (attachmentCount <= attachmentScanIndexThenAttachmentCountForCopy) goto LAB_000875c8;
        } while (!attachmentFound);
LAB_00087604:
        newAttachments = (int *)0x0;
        attachmentScanIndexThenAttachmentCountForCopy = 1;
        if (attachmentCount != 1) {
          newAttachments = (int *)_malloc(attachmentCount * 4 + -4);
          attachmentScanIndexThenAttachmentCountForCopy = *(int *)(sharedStateThenContainerObject + 0x48);
        }
        loopIndex = 0;
        if (attachmentScanIndexThenAttachmentCountForCopy < 1) {
          oldAttachments = *(int *)(sharedStateThenContainerObject + 0x44);
        }
        else {
          oldAttachments = *(int *)(sharedStateThenContainerObject + 0x44);
          dstCursor = newAttachments;
          do {
            attachmentEntry = *(int *)(loopIndex * 4 + oldAttachments);
            if (hashObject != attachmentEntry) {
              *dstCursor = attachmentEntry;
              dstCursor = dstCursor + 1;
              attachmentScanIndexThenAttachmentCountForCopy = *(int *)(sharedStateThenContainerObject + 0x48);
              oldAttachments = *(int *)(sharedStateThenContainerObject + 0x44);
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex < attachmentScanIndexThenAttachmentCountForCopy);
        }
        *(int *)(sharedStateThenContainerObject + 0x48) = attachmentScanIndexThenAttachmentCountForCopy + -1;
        if (oldAttachments != 0) {
          _free(oldAttachments);
        }
        *(int **)(sharedStateThenContainerObject + 0x44) = newAttachments;
        attachedRefCount = *(int *)(hashObject + 8) + -1;
        *(int *)(hashObject + 8) = attachedRefCount;
        if (attachedRefCount == 1) {
          _gleDeleteHashNameAndObject(glContext,*(int *)(glContext + 0x5148) + 0x6018,attachedObj);
        }
        if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
          return;
        }
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
        return;
      }
LAB_000875c8:
      if (attachmentFound) goto LAB_00087604;
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
void _glShaderSourceARB_Exec_body(glContext, forwardedArg2, stringCount, strings, lengths)
  int glContext;
  undefined4 forwardedArg2;
  int stringCount;
  int strings;
  int lengths;
{
  bool allStringsCopied;
  char currentChar;
  undefined4 glErrorCode;
  int stringOffset;
  int stringLength;
  int sharedStateThenShaderObject;
  char *sourceBuffer;
  char *writeCursorThenScanCursor;
  int totalLength;
  int loopIndex;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (0 < stringCount) {
      sharedStateThenShaderObject = *(int *)(glContext + 0x5148);
      if (*(char *)(sharedStateThenShaderObject + 0x8024) != '\0') {
        _pthread_mutex_lock(sharedStateThenShaderObject + 0x8028);
        sharedStateThenShaderObject = *(int *)(glContext + 0x5148);
      }
      sharedStateThenShaderObject = _gleLookupHashObject(sharedStateThenShaderObject + 0x6018,forwardedArg2);
      if (sharedStateThenShaderObject != 0) {
        if (*(int *)(sharedStateThenShaderObject + 0x10) != 0x8b48) {
          if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
            _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
          }
          goto LAB_000877f0;
        }
        totalLength = 0;
        loopIndex = 0;
        if (0 < stringCount) {
          do {
            if (lengths == 0) {
              stringOffset = loopIndex << 2;
LAB_00087834:
              stringLength = _strlen(*(undefined4 *)(strings + stringOffset));
            }
            else {
              stringOffset = loopIndex * 4;
              stringLength = *(int *)(lengths + stringOffset);
              if (stringLength < 0) goto LAB_00087834;
            }
            totalLength = totalLength + stringLength;
            loopIndex = loopIndex + 1;
          } while (loopIndex < stringCount);
        }
        loopIndex = 0;
        allStringsCopied = stringCount == 0;
        sourceBuffer = (char *)_malloc(totalLength + 2);
        writeCursorThenScanCursor = sourceBuffer;
        if (0 < stringCount) {
          do {
            if (lengths == 0) {
              stringOffset = loopIndex << 2;
LAB_00087894:
              writeCursorThenScanCursor = _stpcpy(writeCursorThenScanCursor,*(char **)(strings + stringOffset));
            }
            else {
              stringOffset = loopIndex * 4;
              if ((int)*(size_t *)(stringOffset + lengths) < 0) goto LAB_00087894;
              _strncpy(writeCursorThenScanCursor,*(char **)(stringOffset + strings),*(size_t *)(stringOffset + lengths));
              writeCursorThenScanCursor = writeCursorThenScanCursor + *(int *)(stringOffset + lengths);
              if (writeCursorThenScanCursor[-1] == '\0') break;
            }
            loopIndex = loopIndex + 1;
            allStringsCopied = loopIndex == stringCount;
          } while (loopIndex < stringCount);
        }
        *writeCursorThenScanCursor = '\0';
        if (allStringsCopied) {
          loopIndex = 0;
          currentChar = *sourceBuffer;
          writeCursorThenScanCursor = sourceBuffer;
          while (currentChar != '\0') {
            if ((currentChar == '\r') && (writeCursorThenScanCursor[1] == '\n')) {
              *writeCursorThenScanCursor = ' ';
            }
            else if (currentChar == '\r') {
              *writeCursorThenScanCursor = '\n';
            }
            writeCursorThenScanCursor = writeCursorThenScanCursor + 1;
            loopIndex = loopIndex + 1;
            currentChar = *writeCursorThenScanCursor;
          }
          if (sourceBuffer[loopIndex + -1] != '\n') {
            totalLength = totalLength + 1;
            sourceBuffer[loopIndex] = '\n';
            sourceBuffer[loopIndex + 1] = '\0';
          }
          if (*(int *)(sharedStateThenShaderObject + 0x2c) != 0) {
            _free(*(int *)(sharedStateThenShaderObject + 0x2c));
          }
          *(char **)(sharedStateThenShaderObject + 0x2c) = sourceBuffer;
          *(undefined1 *)(sharedStateThenShaderObject + 0x24) = 1;
          *(int *)(sharedStateThenShaderObject + 0x28) = totalLength;
          if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) == '\0') {
            return;
          }
          _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
          return;
        }
        _free(sourceBuffer);
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
  int sharedStateThenShaderObject;
  
  if (-1 < *(short *)(glContext + 0x4a10)) {
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    *(undefined4 *)(glContext + 0x7574) = 0x502;
    return;
  }
  sharedStateThenShaderObject = *(int *)(glContext + 0x5148);
  if (*(char *)(sharedStateThenShaderObject + 0x8024) != '\0') {
    _pthread_mutex_lock(sharedStateThenShaderObject + 0x8028);
    sharedStateThenShaderObject = *(int *)(glContext + 0x5148);
  }
  sharedStateThenShaderObject = _gleLookupHashObject(sharedStateThenShaderObject + 0x6018,shaderObj);
  if (sharedStateThenShaderObject == 0) {
    if (*(int *)(glContext + 0x7574) != 0) goto LAB_00087ad8;
    glErrorCode = 0x501;
  }
  else {
    if (*(int *)(sharedStateThenShaderObject + 0x10) == 0x8b48) {
      _gleShaderParse(glContext,sharedStateThenShaderObject);
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
int _evaluateImageUnits(glContext, program)
  int glContext;
  int program;
{
  ushort unitType;
  int unitLimitThenTypeOffsetThenSavedIndex;
  char stageUsedThenValidFlag;
  undefined4 samplerIndex;
  char *srcCursor;
  int typeCursorThenStageRecordThenUseCount;
  ushort *dstCursor2;
  ushort *srcCursor2;
  ushort *srcCursor3;
  int *dstCursor;
  int *stageRecords;
  int loopIndex;
  uint loopIndex2;
  int *dstCursor3;
  int *srcCursor4;
  uint samplerMaskHigh;
  uint samplerMaskLow;
  int stageRecordThenImageUnit;
  int typeInfoResultThenUnitCount;
  int loopIndex3;
  int remaining;
  longlong nibbleMaskThenTypeBits;
  int savedCounts [32];
  ushort savedTypes [32];
  undefined4 uniformType;
  char stagesUsed [4];
  uint savedValidFlag;
  
  stageRecords = (int *)(program + 0x20);
  loopIndex = 0;
  savedValidFlag = (uint)*(byte *)(program + 0x3e);
  *(undefined1 *)(program + 0x3e) = 1;
  do {
    if (loopIndex == 0) {
      stageRecordThenImageUnit = *stageRecords;
      remaining = 0;
    }
    else {
      stageRecordThenImageUnit = *(int *)(program + 0x24);
      remaining = 0x10;
    }
    if (remaining != 0) {
      dstCursor3 = savedCounts + loopIndex * 0x10;
      dstCursor2 = savedTypes + loopIndex * 0x10;
      typeCursorThenStageRecordThenUseCount = stageRecordThenImageUnit + 0x60;
      do {
        *dstCursor3 = *(int *)(stageRecordThenImageUnit + 0x2c);
        dstCursor3 = dstCursor3 + 1;
        *dstCursor2 = *(ushort *)(typeCursorThenStageRecordThenUseCount + 0xc);
        dstCursor2 = dstCursor2 + 1;
        *(undefined4 *)(stageRecordThenImageUnit + 0x2c) = 0;
        stageRecordThenImageUnit = stageRecordThenImageUnit + 4;
        *(undefined2 *)(typeCursorThenStageRecordThenUseCount + 0xc) = 0;
        typeCursorThenStageRecordThenUseCount = typeCursorThenStageRecordThenUseCount + 2;
        remaining = remaining + -1;
      } while (remaining != 0);
    }
    loopIndex = loopIndex + 1;
  } while (loopIndex < 2);
  loopIndex = 0;
  if (*(int *)(program + 0x30) < 1) {
LAB_00087d18:
    stageUsedThenValidFlag = *(char *)(program + 0x3e);
  }
  else {
    stageUsedThenValidFlag = *(char *)(program + 0x3e);
    if (stageUsedThenValidFlag == '\x01') {
      do {
        uniformType = 0;
        stagesUsed[0] = '\0';
        stagesUsed[1] = '\0';
        typeInfoResultThenUnitCount = _ShGetUniformTypeInfo(*(undefined4 *)(program + 0x40),loopIndex,0,&uniformType,stagesUsed);
        if ((typeInfoResultThenUnitCount != 0) && (uniformType - 0x8b5d < 8)) {
          loopIndex3 = 0;
          srcCursor = stagesUsed;
          do {
            stageUsedThenValidFlag = *srcCursor;
            srcCursor = srcCursor + 1;
            if (stageUsedThenValidFlag != '\0') {
              stageRecordThenImageUnit = *(int *)(*(int *)(program + 0x4c) + loopIndex * 0x10);
              if (loopIndex3 == 0) {
                typeCursorThenStageRecordThenUseCount = *stageRecords;
                unitLimitThenTypeOffsetThenSavedIndex = 0;
              }
              else {
                typeCursorThenStageRecordThenUseCount = *(int *)(program + 0x24);
                unitLimitThenTypeOffsetThenSavedIndex = 0x10;
              }
              if ((unitLimitThenTypeOffsetThenSavedIndex <= stageRecordThenImageUnit) || (stageRecordThenImageUnit < 0)) {
LAB_00087ce4:
                *(undefined1 *)(program + 0x3e) = 0;
                break;
              }
              if (*(int *)(stageRecordThenImageUnit * 4 + typeCursorThenStageRecordThenUseCount + 0x2c) < 1) {
                unitLimitThenTypeOffsetThenSavedIndex = stageRecordThenImageUnit << 1;
              }
              else {
                unitLimitThenTypeOffsetThenSavedIndex = stageRecordThenImageUnit * 2;
                if (uniformType != *(ushort *)(unitLimitThenTypeOffsetThenSavedIndex + typeCursorThenStageRecordThenUseCount + 0x6c)) goto LAB_00087ce4;
              }
              stageRecordThenImageUnit = stageRecordThenImageUnit * 4 + typeCursorThenStageRecordThenUseCount;
              *(int *)(stageRecordThenImageUnit + 0x2c) = *(int *)(stageRecordThenImageUnit + 0x2c) + 1;
              *(undefined2 *)(unitLimitThenTypeOffsetThenSavedIndex + typeCursorThenStageRecordThenUseCount + 0x6c) = (*(unsigned short *)((unsigned char *)&(uniformType) + 2));
            }
            loopIndex3 = loopIndex3 + 1;
          } while (loopIndex3 < 2);
        }
        loopIndex = loopIndex + 1;
        if (*(int *)(program + 0x30) <= loopIndex) goto LAB_00087d18;
        stageUsedThenValidFlag = *(char *)(program + 0x3e);
      } while (stageUsedThenValidFlag == '\x01');
    }
  }
  if (stageUsedThenValidFlag == '\0') {
    loopIndex = 0;
    do {
      if (loopIndex == 0) {
        stageRecordThenImageUnit = *stageRecords;
        remaining = 0;
      }
      else {
        stageRecordThenImageUnit = *(int *)(program + 0x24);
        remaining = 0x10;
      }
      if (remaining != 0) {
        srcCursor4 = savedCounts + loopIndex * 0x10;
        srcCursor3 = savedTypes + loopIndex * 0x10;
        dstCursor = (int *)(stageRecordThenImageUnit + 0x2c);
        dstCursor2 = (ushort *)(stageRecordThenImageUnit + 0x6c);
        do {
          stageRecordThenImageUnit = *srcCursor4;
          srcCursor4 = srcCursor4 + 1;
          *dstCursor = stageRecordThenImageUnit;
          dstCursor = dstCursor + 1;
          unitType = *srcCursor3;
          srcCursor3 = srcCursor3 + 1;
          *dstCursor2 = unitType;
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
        stageRecordThenImageUnit = *stageRecords;
        typeInfoResultThenUnitCount = 0;
      }
      else {
        stageRecordThenImageUnit = *(int *)(program + 0x24);
        typeInfoResultThenUnitCount = 0x10;
      }
      loopIndex2 = 0;
      *(undefined4 *)(stageRecordThenImageUnit + 0x50c) = 0xffffffff;
      *(undefined4 *)(stageRecordThenImageUnit + 0x510) = 0xffffffff;
      if (typeInfoResultThenUnitCount != 0) {
        srcCursor2 = (ushort *)(stageRecordThenImageUnit + 0x6c);
        srcCursor4 = (int *)(stageRecordThenImageUnit + 0x2c);
        do {
          typeCursorThenStageRecordThenUseCount = *srcCursor4;
          srcCursor4 = srcCursor4 + 1;
          if (typeCursorThenStageRecordThenUseCount != 0) {
            nibbleMaskThenTypeBits = ___ashldi3(0,0xf,loopIndex2 << 2);
            samplerMaskLow = *(uint *)(stageRecordThenImageUnit + 0x510) & ~(uint)nibbleMaskThenTypeBits;
            samplerMaskHigh = *(uint *)(stageRecordThenImageUnit + 0x50c) & ~(uint)((ulonglong)nibbleMaskThenTypeBits >> 0x20);
            unitType = *srcCursor2;
            *(uint *)(stageRecordThenImageUnit + 0x50c) = samplerMaskHigh;
            *(uint *)(stageRecordThenImageUnit + 0x510) = samplerMaskLow;
            samplerIndex = _getIndexForGLSLSamplerType((uint)unitType);
            nibbleMaskThenTypeBits = ___ashldi3(0,samplerIndex,loopIndex2 << 2);
            *(uint *)(stageRecordThenImageUnit + 0x50c) = samplerMaskHigh | (uint)((ulonglong)nibbleMaskThenTypeBits >> 0x20);
            *(uint *)(stageRecordThenImageUnit + 0x510) = samplerMaskLow | (uint)nibbleMaskThenTypeBits;
          }
          if ((*(int *)(glContext + 0x5430) == program) &&
             ((unitLimitThenTypeOffsetThenSavedIndex = loopIndex * 0x10 + loopIndex2, typeCursorThenStageRecordThenUseCount != savedCounts[unitLimitThenTypeOffsetThenSavedIndex] ||
              ((typeCursorThenStageRecordThenUseCount != 0 && (*srcCursor2 != savedTypes[unitLimitThenTypeOffsetThenSavedIndex])))))) {
            *(uint *)(glContext + 0x314) = *(uint *)(glContext + 0x314) | 1 << (loopIndex2 & 0x3f);
          }
          loopIndex2 = loopIndex2 + 1;
          srcCursor2 = srcCursor2 + 1;
        } while ((int)loopIndex2 < typeInfoResultThenUnitCount);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 2);
  }
  return -(uint)(savedValidFlag ^ *(byte *)(program + 0x3e)) >> 0x1f;
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
  bool isFragmentStage;
  bool attachmentsValid;
  byte vertexStageHadProgramByte;
  byte fragmentStageHadProgramByte;
  undefined4 glErrorCode;
  undefined4 infoLogThenLength;
  undefined4 shaderStringCopy;
  undefined4 attribLocation;
  undefined4 attribLocationTable;
  undefined4 attribNameBuffer;
  undefined4 uniformLocation;
  undefined4 uniformLocationTable;
  undefined4 uniformNameBuffer;
  undefined4 streamCopy;
  undefined4 streamBuffer;
  undefined4 localParamRemapTable;
  undefined4 activeUserUniformsSize;
  undefined4 maxAttributeNameLength;
  undefined4 numActiveAttributes;
  undefined4 maxUniformNameLength;
  undefined4 numActiveUniforms;
  undefined4 errorLogLength;
  undefined4 *puVar5;
  undefined4 *linkInfoRecord;
  undefined4 *zeroCursor;
  int attachedShader;
  int perUnitByteOffset;
  int activeAttribOk;
  int activeUniformOk;
  int fragmentLocalParams;
  int vertexLocalParams;
  int loopIndex;
  int uniformEntry;
  int rowIndex;
  int localParamEntry;
  int sharedStateThenProgramObj;
  char *errorLogBuffer;
  char *infoLogText;
  char *stageRecordForInfo;
  undefined1 linkSucceeded;
  undefined4 emulatorProgram;
  int *piVar13;
  int *attachedShaderCursor;
  int stageIndex;
  int unitIndex;
  int infoLogBuffer;
  int attachedCountCopy;
  int localParamOffset;
  int uniformStore;
  int fragmentStage;
  int vertexStage;
  int shaderHandles;
  int attachIndex;
  int *stageRecordSlots;
  char *shaderString;
  undefined1 *stageRecord;
  int iVar18;
  int fragmentLocalParamCount;
  int unitRecord;
  int shaderStringLength;
  int attribIndex;
  int uniformIndex;
  int vertexLocalParamCount;
  int uniformEntryOffset;
  int handleByteOffset;
  int attachedCountForLink;
  int attachedShaderCount;
  int linkInfoOld;
  int clearCount;
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
  int streamLength [2];
  int stageShaders [2];
  undefined1 activeNameLength [4];
  undefined1 activeSize [4];
  undefined1 activeType [12];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    sharedStateThenProgramObj = *(int *)(glContext + 0x5148);
    if (*(char *)(sharedStateThenProgramObj + 0x8024) != '\0') {
      _pthread_mutex_lock(sharedStateThenProgramObj + 0x8028);
      sharedStateThenProgramObj = *(int *)(glContext + 0x5148);
    }
    sharedStateThenProgramObj = _gleLookupHashObject(sharedStateThenProgramObj + 0x6018,programObj);
    if (sharedStateThenProgramObj == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_00088210;
    }
    if (*(int *)(sharedStateThenProgramObj + 0x10) == 0x8b40) {
      stageRecordSlots = (int *)(sharedStateThenProgramObj + 0x20);
      *(undefined1 *)(sharedStateThenProgramObj + 0x3e) = 0;
      *(undefined1 *)(sharedStateThenProgramObj + 0x3c) = 0;
      *(undefined4 *)(sharedStateThenProgramObj + 0x28) = 0;
      *(undefined4 *)(sharedStateThenProgramObj + 0x2c) = 0;
      *(undefined4 *)(sharedStateThenProgramObj + 0x34) = 0;
      *(undefined4 *)(sharedStateThenProgramObj + 0x38) = 0;
      *(undefined4 *)(sharedStateThenProgramObj + 0x30) = 0;
      if (*(int *)(sharedStateThenProgramObj + 0x4c) != 0) {
        _gleVecFree(*(int *)(sharedStateThenProgramObj + 0x4c));
      }
      stageIndex = 0;
      *(undefined4 *)(sharedStateThenProgramObj + 0x4c) = 0;
      vertexStageHadProgramByte = **(byte **)(sharedStateThenProgramObj + 0x20);
      fragmentStageHadProgramByte = **(byte **)(sharedStateThenProgramObj + 0x24);
      do {
        if (stageIndex == 0) {
          stageRecord = (undefined1 *)*stageRecordSlots;
        }
        else {
          stageRecord = *(undefined1 **)(sharedStateThenProgramObj + 0x24);
        }
        *stageRecord = 0;
        clearCount = 9;
        *(undefined4 *)(stageRecord + 4) = 0;
        zeroCursor = (undefined4 *)(stageRecord + 8);
        do {
          *zeroCursor = 0;
          zeroCursor = zeroCursor + 1;
          clearCount = clearCount + -1;
        } while (clearCount != 0);
        if (*(int *)(stageRecord + 0x4dc) != 0) {
          _PPEmulatorProgramFree(*(int *)(stageRecord + 0x4dc));
        }
        *(undefined4 *)(stageRecord + 0x4dc) = 0;
        *(undefined4 *)(stageRecord + 0x4e0) = 0;
        if (*(int *)(stageRecord + 0x508) != 0) {
          _gleVecFree(*(int *)(stageRecord + 0x508));
        }
        *(undefined4 *)(stageRecord + 0x508) = 0;
        *(undefined4 *)(stageRecord + 0x50c) = 0xffffffff;
        *(undefined4 *)(stageRecord + 0x510) = 0xffffffff;
        if (*(int *)(stageRecord + 0x51c) != 0) {
          _gleVecFree(*(int *)(stageRecord + 0x51c));
        }
        linkInfoOld = *(int *)(stageRecord + 0x518);
        *(undefined4 *)(stageRecord + 0x51c) = 0;
        if (linkInfoOld != 0) {
          if (*(int *)(linkInfoOld + 0x20) != 0) {
            _gleVecFree(*(int *)(linkInfoOld + 0x20));
            linkInfoOld = *(int *)(stageRecord + 0x518);
          }
          if (*(int *)(linkInfoOld + 8) != 0) {
            _gleVecFree(*(int *)(linkInfoOld + 8));
            linkInfoOld = *(int *)(stageRecord + 0x518);
          }
          if (*(int *)(linkInfoOld + 0xc) != 0) {
            _gleVecFree(*(int *)(linkInfoOld + 0xc));
            linkInfoOld = *(int *)(stageRecord + 0x518);
          }
          if (*(int *)(linkInfoOld + 0x18) != 0) {
            _gleVecFree(*(int *)(linkInfoOld + 0x18));
            linkInfoOld = *(int *)(stageRecord + 0x518);
          }
          if (*(int *)(linkInfoOld + 0x1c) != 0) {
            _gleVecFree(*(int *)(linkInfoOld + 0x1c));
            linkInfoOld = *(int *)(stageRecord + 0x518);
          }
          _gleVecFree(linkInfoOld);
          *(undefined4 *)(stageRecord + 0x518) = 0;
        }
        stageIndex = stageIndex + 1;
      } while (stageIndex < 2);
      attachedShaderCount = *(int *)(sharedStateThenProgramObj + 0x48);
      attachIndex = 0;
      if (0 < attachedShaderCount) {
        attachedShaderCursor = *(int **)(sharedStateThenProgramObj + 0x44);
        do {
          attachedShader = *attachedShaderCursor;
          attachedShaderCursor = attachedShaderCursor + 1;
          if (*(char *)(attachedShader + 0x25) == '\0') {
            errorLogLength = _strlen("ERROR: One or more attached shaders not successfully compiled\n");
            *(undefined4 *)(sharedStateThenProgramObj + 0x1c) = errorLogLength;
            if (*(int *)(sharedStateThenProgramObj + 0x18) != 0) {
              _free(*(int *)(sharedStateThenProgramObj + 0x18));
            }
            *(undefined4 *)(sharedStateThenProgramObj + 0x18) = 0;
            if (*(int *)(sharedStateThenProgramObj + 0x1c) != 0) {
              errorLogBuffer = (char *)_malloc(*(int *)(sharedStateThenProgramObj + 0x1c) + 1);
              *(char **)(sharedStateThenProgramObj + 0x18) = errorLogBuffer;
              if (errorLogBuffer != (char *)0x0) {
                _strncpy(errorLogBuffer,"ERROR: One or more attached shaders not successfully compiled\n",
                         *(size_t *)(sharedStateThenProgramObj + 0x1c));
              }
            }
            goto LAB_00088b38;
          }
          attachIndex = attachIndex + 1;
        } while (attachIndex < attachedShaderCount);
      }
      if (attachedShaderCount == 0) {
        linkSucceeded = _ShLink(*(undefined4 *)(sharedStateThenProgramObj + 0x40),0,0,*(undefined4 *)(glContext + 0x7594),
                         *(undefined4 *)(glContext + 0x7598));
        *(undefined1 *)(sharedStateThenProgramObj + 0x3c) = linkSucceeded;
        *(undefined4 *)(sharedStateThenProgramObj + 0x1c) = 0;
        if (*(int *)(sharedStateThenProgramObj + 0x18) != 0) {
          _free(*(int *)(sharedStateThenProgramObj + 0x18));
          *(undefined4 *)(sharedStateThenProgramObj + 0x18) = 0;
        }
        ((int (*)())_evaluateImageUnits)(glContext,sharedStateThenProgramObj);
        fparam_1 = extraout_f1_03;
      }
      else {
        loopIndex = 0;
        shaderHandles = _malloc(attachedShaderCount << 2);
        attachedCountForLink = *(int *)(sharedStateThenProgramObj + 0x48);
        if (0 < attachedCountForLink) {
          do {
            handleByteOffset = loopIndex * 4;
            loopIndex = loopIndex + 1;
            *(undefined4 *)(handleByteOffset + shaderHandles) =
                 *(undefined4 *)(*(int *)(handleByteOffset + *(int *)(sharedStateThenProgramObj + 0x44)) + 0x30);
            attachedCountForLink = *(int *)(sharedStateThenProgramObj + 0x48);
          } while (loopIndex < attachedCountForLink);
        }
        loopIndex = 0;
        linkSucceeded = _ShLink(*(undefined4 *)(sharedStateThenProgramObj + 0x40),shaderHandles,attachedCountForLink,
                         *(undefined4 *)(glContext + 0x7594),*(undefined4 *)(glContext + 0x7598));
        *(undefined1 *)(sharedStateThenProgramObj + 0x3c) = linkSucceeded;
        _free(shaderHandles);
        numActiveUniforms = _ShGetNumActiveUniforms(*(undefined4 *)(sharedStateThenProgramObj + 0x40));
        *(undefined4 *)(sharedStateThenProgramObj + 0x28) = numActiveUniforms;
        maxUniformNameLength = _ShGetMaxUniformLength(*(undefined4 *)(sharedStateThenProgramObj + 0x40));
        *(undefined4 *)(sharedStateThenProgramObj + 0x2c) = maxUniformNameLength;
        numActiveAttributes = _ShGetNumActiveAttributes(*(undefined4 *)(sharedStateThenProgramObj + 0x40));
        *(undefined4 *)(sharedStateThenProgramObj + 0x34) = numActiveAttributes;
        maxAttributeNameLength = _ShGetMaxAttributeLength(*(undefined4 *)(sharedStateThenProgramObj + 0x40));
        *(undefined4 *)(sharedStateThenProgramObj + 0x38) = maxAttributeNameLength;
        activeUserUniformsSize = _ShGetActiveUserUniformsSize(*(undefined4 *)(sharedStateThenProgramObj + 0x40));
        vertexStage = *stageRecordSlots;
        *(undefined4 *)(sharedStateThenProgramObj + 0x30) = activeUserUniformsSize;
        localParamRemapTable = _ShGetShaderLocalParamRemapTable(*(undefined4 *)(sharedStateThenProgramObj + 0x40),0);
        *(undefined4 *)(vertexStage + 0x4e0) = localParamRemapTable;
        fragmentStage = *(int *)(sharedStateThenProgramObj + 0x24);
        localParamRemapTable = _ShGetShaderLocalParamRemapTable(*(undefined4 *)(sharedStateThenProgramObj + 0x40),1);
        *(undefined4 *)(fragmentStage + 0x4e0) = localParamRemapTable;
        uniformStore = _gleVecAlloc(*(int *)(sharedStateThenProgramObj + 0x30) << 4);
        *(int *)(sharedStateThenProgramObj + 0x4c) = uniformStore;
        if (0 < *(int *)(sharedStateThenProgramObj + 0x30)) {
          do {
            uniformEntryOffset = loopIndex * 0x10;
            loopIndex = loopIndex + 1;
            uniformEntry = uniformEntryOffset + uniformStore;
            *(undefined4 *)(uniformStore + uniformEntryOffset) = 0;
            *(undefined4 *)(uniformEntry + 0xc) = 0;
            *(undefined4 *)(uniformEntry + 4) = 0;
            *(undefined4 *)(uniformEntry + 8) = 0;
          } while (loopIndex < *(int *)(sharedStateThenProgramObj + 0x30));
        }
        vertexStage = *stageRecordSlots;
        vertexLocalParamCount = _ShGetNumShaderLocalParams(*(undefined4 *)(sharedStateThenProgramObj + 0x40),0);
        if (vertexLocalParamCount != 0) {
          rowIndex = 0;
          vertexLocalParams = _gleVecAlloc(vertexLocalParamCount << 4);
          *(int *)(vertexStage + 0x51c) = vertexLocalParams;
          if (0 < vertexLocalParamCount) {
            do {
              localParamOffset = rowIndex * 0x10;
              rowIndex = rowIndex + 1;
              localParamEntry = localParamOffset + vertexLocalParams;
              *(undefined4 *)(vertexLocalParams + localParamOffset) = 0;
              *(undefined4 *)(localParamEntry + 0xc) = 0;
              *(undefined4 *)(localParamEntry + 4) = 0;
              *(undefined4 *)(localParamEntry + 8) = 0;
              vertexLocalParamCount = vertexLocalParamCount + -1;
            } while (vertexLocalParamCount != 0);
          }
        }
        fragmentStage = *(int *)(sharedStateThenProgramObj + 0x24);
        fragmentLocalParamCount = _ShGetNumShaderLocalParams(*(undefined4 *)(sharedStateThenProgramObj + 0x40),1);
        if (fragmentLocalParamCount != 0) {
          rowIndex = 0;
          fragmentLocalParams = _gleVecAlloc(fragmentLocalParamCount << 4);
          *(int *)(fragmentStage + 0x51c) = fragmentLocalParams;
          if (0 < fragmentLocalParamCount) {
            do {
              localParamOffset = rowIndex * 0x10;
              rowIndex = rowIndex + 1;
              localParamEntry = localParamOffset + fragmentLocalParams;
              *(undefined4 *)(fragmentLocalParams + localParamOffset) = 0;
              *(undefined4 *)(localParamEntry + 0xc) = 0;
              *(undefined4 *)(localParamEntry + 4) = 0;
              *(undefined4 *)(localParamEntry + 8) = 0;
              fragmentLocalParamCount = fragmentLocalParamCount + -1;
            } while (fragmentLocalParamCount != 0);
          }
        }
        stageIndex = 0;
        do {
          isFragmentStage = stageIndex != 0;
          if (isFragmentStage) {
            stageRecord = *(undefined1 **)(sharedStateThenProgramObj + 0x24);
          }
          else {
            stageRecord = (undefined1 *)*stageRecordSlots;
          }
          iVar18 = _ShGetPPStreamManager(*(undefined4 *)(sharedStateThenProgramObj + 0x40),isFragmentStage);
          if (iVar18 != 0) {
            _PPStreamGetStream(iVar18,0,streamLength);
            if (streamLength[0] != 0) {
              streamBuffer = _gleVecAlloc(streamLength[0] << 3);
              *(undefined4 *)(stageRecord + 0x508) = streamBuffer;
              _PPStreamGetStream(iVar18,streamBuffer,streamLength);
              if ((*(int *)(stageRecord + 0x508) != 0) && (*stageRecord = 1, !isFragmentStage)) {
                streamCopy = _PPStreamDuplicate(iVar18);
                _glpPPShaderLinearizeStreamMgr(streamCopy,0xf9);
                emulatorProgram = _PPEmulatorProgramCreate();
                *(undefined4 *)(stageRecord + 0x4dc) = emulatorProgram;
                _PPEmulatorProgramSetupHandlesFromPPStream(emulatorProgram,glContext,streamCopy);
                _PPEmulatorProgramConvertFromPPStream(*(undefined4 *)(stageRecord + 0x4dc),streamCopy);
                _PPStreamFree(streamCopy);
              }
            }
            _gleShaderDataUpdateParams(stageRecord);
          }
          stageIndex = stageIndex + 1;
        } while (stageIndex < 2);
        ((int (*)())_evaluateImageUnits)(glContext,sharedStateThenProgramObj);
        if (*(char *)(glContext + 0x4693) == '\x01') {
          stageShaders[0] = 0;
          stageShaders[1] = 0;
          attachedCountCopy = *(int *)(sharedStateThenProgramObj + 0x48);
          attachmentsValid = attachedCountCopy < 3;
          iVar18 = 0;
          if (attachedCountCopy < 1) {
LAB_0008879c:
            if (attachmentsValid) {
              stageIndex = 0;
              do {
                if (stageIndex == 0) {
                  stageRecordForInfo = (char *)*stageRecordSlots;
                }
                else {
                  stageRecordForInfo = *(char **)(sharedStateThenProgramObj + 0x24);
                }
                if ((*stageRecordForInfo != '\0') && (stageShaders[stageIndex] != 0)) {
                  linkInfoRecord = (undefined4 *)_gleVecAlloc(0x24);
                  *linkInfoRecord = 0;
                  linkInfoRecord[1] = 0;
                  linkInfoRecord[2] = 0;
                  linkInfoRecord[3] = 0;
                  linkInfoRecord[4] = 0;
                  linkInfoRecord[5] = 0;
                  linkInfoRecord[6] = 0;
                  linkInfoRecord[7] = 0;
                  linkInfoRecord[8] = 0;
                  *linkInfoRecord = *(undefined4 *)(sharedStateThenProgramObj + 0x28);
                  linkInfoRecord[1] = *(undefined4 *)(sharedStateThenProgramObj + 0x2c);
                  if (*(int *)(sharedStateThenProgramObj + 0x28) != 0) {
                    uniformIndex = 0;
                    uniformNameBuffer = _gleVecAlloc(*(int *)(sharedStateThenProgramObj + 0x28) * *(int *)(sharedStateThenProgramObj + 0x2c));
                    linkInfoRecord[2] = uniformNameBuffer;
                    uniformLocationTable = _gleVecAlloc(*(int *)(sharedStateThenProgramObj + 0x28) << 2);
                    linkInfoRecord[3] = uniformLocationTable;
                    if (0 < *(int *)(sharedStateThenProgramObj + 0x28)) {
                      do {
                        activeUniformOk = _ShGetActiveUniform(*(undefined4 *)(sharedStateThenProgramObj + 0x40),uniformIndex,
                                                    *(int *)(sharedStateThenProgramObj + 0x2c),activeNameLength,activeSize,
                                                    activeType,
                                                    linkInfoRecord[2] + uniformIndex * *(int *)(sharedStateThenProgramObj + 0x2c));
                        if (activeUniformOk == 0) {
                          *(undefined4 *)(uniformIndex * 4 + linkInfoRecord[3]) = 0xffffffff;
                        }
                        else {
                          uniformLocation = _ShGetUniformLocation
                                            (*(undefined4 *)(sharedStateThenProgramObj + 0x40),
                                             linkInfoRecord[2] + uniformIndex * *(int *)(sharedStateThenProgramObj + 0x2c));
                          *(undefined4 *)(uniformIndex * 4 + linkInfoRecord[3]) = uniformLocation;
                        }
                        uniformIndex = uniformIndex + 1;
                      } while (uniformIndex < *(int *)(sharedStateThenProgramObj + 0x28));
                    }
                  }
                  linkInfoRecord[4] = *(undefined4 *)(sharedStateThenProgramObj + 0x34);
                  linkInfoRecord[5] = *(undefined4 *)(sharedStateThenProgramObj + 0x38);
                  if (*(int *)(sharedStateThenProgramObj + 0x34) != 0) {
                    attribIndex = 0;
                    attribNameBuffer = _gleVecAlloc(*(int *)(sharedStateThenProgramObj + 0x34) * *(int *)(sharedStateThenProgramObj + 0x38));
                    linkInfoRecord[6] = attribNameBuffer;
                    attribLocationTable = _gleVecAlloc(*(int *)(sharedStateThenProgramObj + 0x34) << 2);
                    linkInfoRecord[7] = attribLocationTable;
                    if (0 < *(int *)(sharedStateThenProgramObj + 0x34)) {
                      do {
                        activeAttribOk = _ShGetActiveAttrib(*(undefined4 *)(sharedStateThenProgramObj + 0x40),attribIndex,
                                                   *(int *)(sharedStateThenProgramObj + 0x38),activeNameLength,activeSize,
                                                   activeType,
                                                   linkInfoRecord[6] + attribIndex * *(int *)(sharedStateThenProgramObj + 0x38));
                        if (activeAttribOk == 0) {
                          *(undefined4 *)(attribIndex * 4 + linkInfoRecord[7]) = 0xffffffff;
                        }
                        else {
                          attribLocation = _ShGetAttribLocation
                                            (*(undefined4 *)(sharedStateThenProgramObj + 0x40),
                                             linkInfoRecord[6] + attribIndex * *(int *)(sharedStateThenProgramObj + 0x38));
                          *(undefined4 *)(attribIndex * 4 + linkInfoRecord[7]) = attribLocation;
                        }
                        attribIndex = attribIndex + 1;
                      } while (attribIndex < *(int *)(sharedStateThenProgramObj + 0x34));
                    }
                  }
                  shaderString = *(char **)(stageShaders[stageIndex] + 0x2c);
                  if ((shaderString != (char *)0x0) && (*shaderString != '\0')) {
                    shaderStringLength = _strlen(shaderString);
                    shaderStringCopy = _gleVecAlloc(shaderStringLength + 1);
                    linkInfoRecord[8] = shaderStringCopy;
                    shaderStringLength = _strlen(shaderString);
                    _strncpy((char *)linkInfoRecord[8],shaderString,shaderStringLength + 1);
                  }
                  *(undefined4 **)(stageRecordForInfo + 0x518) = linkInfoRecord;
                }
                stageIndex = stageIndex + 1;
              } while (stageIndex < 2);
            }
          }
          else if (attachmentsValid) {
            attachmentsValid = true;
            do {
              attachedShader = *(int *)(iVar18 * 4 + *(int *)(sharedStateThenProgramObj + 0x44));
              if (attachedShader != 0) {
                if ((stageShaders[0] == 0) && (*(int *)(attachedShader + 0x20) == 0x8b31)) {
                  stageShaders[0] = attachedShader;
                }
                else {
                  if ((stageShaders[1] != 0) ||
                     (attachedShader = *(int *)(iVar18 * 4 + *(int *)(sharedStateThenProgramObj + 0x44)),
                     *(code **)(attachedShader + 0x20) != (code *)0x8b30)) {
                    attachmentsValid = false;
                    goto LAB_00088784;
                  }
                  stageShaders[1] = attachedShader;
                }
                attachedCountCopy = *(int *)(sharedStateThenProgramObj + 0x48);
              }
LAB_00088784:
              iVar18 = iVar18 + 1;
              if (attachedCountCopy <= iVar18) goto LAB_0008879c;
            } while (attachmentsValid);
          }
        }
        infoLogThenLength = _ShGetInfoLog(*(undefined4 *)(sharedStateThenProgramObj + 0x40));
        infoLogThenLength = _strlen(infoLogThenLength);
        *(undefined4 *)(sharedStateThenProgramObj + 0x1c) = infoLogThenLength;
        fparam_1 = extraout_f1;
        if (*(int *)(sharedStateThenProgramObj + 0x18) != 0) {
          _free(*(int *)(sharedStateThenProgramObj + 0x18));
          fparam_1 = extraout_f1_00;
        }
        *(undefined4 *)(sharedStateThenProgramObj + 0x18) = 0;
        if (*(int *)(sharedStateThenProgramObj + 0x1c) != 0) {
          infoLogBuffer = _malloc(*(int *)(sharedStateThenProgramObj + 0x1c) + 1);
          *(int *)(sharedStateThenProgramObj + 0x18) = infoLogBuffer;
          fparam_1 = extraout_f1_01;
          if (infoLogBuffer != 0) {
            infoLogText = (char *)_ShGetInfoLog(*(undefined4 *)(sharedStateThenProgramObj + 0x40));
            _strncpy(*(char **)(sharedStateThenProgramObj + 0x18),infoLogText,*(size_t *)(sharedStateThenProgramObj + 0x1c));
            fparam_1 = extraout_f1_02;
          }
        }
      }
      if (*(int *)(glContext + 0x5430) == sharedStateThenProgramObj) {
        ((void (*)())_updateShaderState)(glContext,stageRecordSlots,(uint)*(byte *)(glContext + 0x759c),(uint)vertexStageHadProgramByte,(uint)fragmentStageHadProgramByte
                           ,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
      }
      unitIndex = 0;
      if (*(char *)(glContext + 0x85a4) != '\0') {
        unitRecord = glContext + 0x85a0;
        do {
          perUnitByteOffset = unitIndex * 4;
          unitIndex = unitIndex + 1;
          (**(code **)(*(int *)(unitRecord + 0x2e4) + 0x194))
                    (*(undefined4 *)(unitRecord + 0xc),*(undefined4 *)(perUnitByteOffset + *stageRecordSlots + 0x4e4),1);
          piVar13 = (int *)(unitRecord + 0x2e4);
          puVar5 = (undefined4 *)(unitRecord + 0xc);
          unitRecord = unitRecord + 0x2e0;
          (**(code **)(*piVar13 + 0x194))
                    (*puVar5,*(undefined4 *)(perUnitByteOffset + *(int *)(sharedStateThenProgramObj + 0x24) + 0x4e4),1);
        } while (unitIndex < (int)(uint)*(byte *)(glContext + 0x85a4));
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
  glErrorCode = 0x502;
LAB_00088210:
  *(undefined4 *)(glContext + 0x7574) = glErrorCode;
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
  int uniformValueTable;
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
        uniformValueTable = *(int *)(currentProgram + 0x4c);
        *(float *)(uniformValueTable + location * 0x10) = (float)v0;
        *(float *)(uniformValueTable + location * 0x10 + 4) = (float)v1;
      }
      else {
        uniformValueTable = *(int *)(currentProgram + 0x4c);
        *(uint *)(uniformValueTable + location * 0x10) = (uint)(v0 != (double)FLOAT_00108e50);
        *(uint *)(uniformValueTable + location * 0x10 + 4) = (uint)(v1 != (double)FLOAT_00108e50);
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
  float uniformFloat;
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
              uniformFloat = *value;
              loopIndex = loopIndex + 1;
              value = value + 1;
              *dstCursor = uniformFloat;
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
  int uniformValueTable;
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
      uniformValueTable = *(int *)(currentProgram + 0x4c);
      constantRegister = uniformValueTable + locationValueOffset;
      if (uniformType == 0x8b55) {
        *(int *)(uniformValueTable + locationValueOffset) = v0;
        *(int *)(constantRegister + 0xc) = v3;
        *(int *)(constantRegister + 4) = v1;
        *(int *)(constantRegister + 8) = v2;
      }
      else {
        if (v0 == 0) {
          *(undefined4 *)(uniformValueTable + locationValueOffset) = 0;
        }
        else {
          *(undefined4 *)(uniformValueTable + locationValueOffset) = 1;
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
  int uniformValueBase;
  int rendererSlotOffset;
  int registerIndexThenOffset;
  int typeInfoFound;
  int rendererSlotOffset2;
  int locationValueOffset;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int uniformValueAddress;
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
      uniformValueBase = *(int *)(currentProgram + 0x4c);
      uniformValueAddress = uniformValueBase + locationValueOffset;
      if (uniformType == 0x8b54) {
        *(int *)(uniformValueBase + locationValueOffset) = v0;
        *(int *)(uniformValueAddress + 8) = v2;
        *(int *)(uniformValueAddress + 4) = v1;
      }
      else {
        if (v0 == 0) {
          *(undefined4 *)(uniformValueBase + locationValueOffset) = 0;
        }
        else {
          *(undefined4 *)(uniformValueBase + locationValueOffset) = 1;
        }
        if (v1 == 0) {
          *(undefined4 *)(uniformValueAddress + 4) = 0;
        }
        else {
          *(undefined4 *)(uniformValueAddress + 4) = 1;
        }
        if (v2 == 0) {
          *(undefined4 *)(uniformValueAddress + 8) = 0;
        }
        else {
          *(undefined4 *)(uniformValueAddress + 8) = 1;
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
  int uniformValues;
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
  uniformValues = *(int *)(currentProgram + 0x4c);
  if (uniformType == 0x8b53) {
    *(int *)(uniformValues + locationValueOffset) = v0;
  }
  else {
    if (v0 == 0) {
      *(undefined4 *)(uniformValues + locationValueOffset) = 0;
    }
    else {
      *(undefined4 *)(uniformValues + locationValueOffset) = 1;
    }
    if (v1 != 0) {
      *(undefined4 *)(uniformValues + locationValueOffset + 4) = 1;
      goto LAB_0008ac38;
    }
  }
  *(int *)(uniformValues + locationValueOffset + 4) = v1;
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
  int previousValue;
  int rendererSlotOffset2;
  int registerIndexThenOffset;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int uniformValueBase;
  int constantRegister;
  int stage0Record;
  int uniformValueSlot;
  undefined4 uniformWord2;
  undefined4 uniformUpdateKind;
  int currentProgram;
  int rendererRecordCursor;
  int loopIndex;
  int rendererRecordCursor2;
  int loopIndex2;
  double incomingFpr1;
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
  uniformUpdateKind = 2;
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
  uniformValueBase = *(int *)(currentProgram + 0x4c);
  locationValueOffset = location * 0x10;
  previousValue = *(int *)(uniformValueBase + locationValueOffset);
  if (previousValue == v0) {
    return;
  }
  if (uniformType != 0x1404) {
    if (uniformType - 0x8b5dU < 8) {
      *(int *)(uniformValueBase + locationValueOffset) = v0;
      uniformUpdateKind = 6;
      ((double (*)())_setImageUnit)(glContext,currentProgram,v0,previousValue,uniformStageUse,uniformType,incomingFpr1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,
                    incomingFpr6,incomingFpr7,incomingFpr8);
      goto LAB_0008af2c;
    }
    if (v0 != 0) {
      *(undefined4 *)(uniformValueBase + locationValueOffset) = 1;
      goto LAB_0008af2c;
    }
  }
  *(int *)(uniformValueBase + locationValueOffset) = v0;
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
                  (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset2 + *(int *)(currentProgram + 0x20) + 0x4e4),uniformUpdateKind);
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
                  (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),uniformUpdateKind);
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
  int newValue;
  int rendererSlotOffset;
  int elementValueOffset;
  undefined4 uniformWord1;
  int elementCount;
  int elementMapOffset;
  int typeInfoFound;
  int loopIndex;
  int oldValue;
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
  double f1AfterCall;
  double forwardedFloatArg1;
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
        elementCount = uniformSize;
        forwardedFloatArg1 = f1AfterCall;
        if (0 < uniformSize) {
          do {
            oldValue = *dstCursor;
            newValue = *value;
            if (oldValue != newValue) {
              stage0Updated = true;
              elementCount = uniformSize;
              if (uniformType == 0x1404) {
LAB_0008bc7c:
                *dstCursor = newValue;
              }
              else if (uniformType - 0x8b5dU < 8) {
                *dstCursor = newValue;
                forwardedFloatArg1 = (double)((double (*)())_setImageUnit)(glContext,currentProgram,*value,oldValue,uniformStageUse,uniformType,
                                                 forwardedFloatArg1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8)
                ;
                elementCount = uniformSize;
              }
              else {
                if (newValue == 0) goto LAB_0008bc7c;
                *dstCursor = 1;
              }
            }
            loopIndex2 = loopIndex2 + 1;
            dstCursor = dstCursor + 4;
            value = value + 1;
          } while (loopIndex2 < elementCount);
          if (stage0Updated) {
            loopIndex2 = 0;
            if (0 < elementCount) {
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
  undefined4 *listRecordThenWriteCursor;
  
  listRecordThenWriteCursor = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform4fvARB_ListExec_001102f0,count * 0x10 + 8);
  if (listRecordThenWriteCursor != (undefined4 *)0x0) {
    listRecordThenWriteCursor[1] = count;
    loopIndex = 0;
    *listRecordThenWriteCursor = location;
    listRecordThenWriteCursor = listRecordThenWriteCursor + 2;
    while( true ) {
      *listRecordThenWriteCursor = *value;
      listRecordThenWriteCursor[1] = value[1];
      listRecordThenWriteCursor[2] = value[2];
      listRecordThenWriteCursor[3] = value[3];
      if (loopIndex == count + -1) break;
      listRecordThenWriteCursor = listRecordThenWriteCursor + 4;
      value = value + 4;
      loopIndex = loopIndex + 1;
    }
  }
  return listRecordThenWriteCursor;
}

/* _glUniform3fvARB_Comp @ 0x8c08c (152 bytes) */
int _glUniform3fvARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *listRecordThenDstCursor;
  
  listRecordThenDstCursor = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform3fvARB_ListExec_001102ec,count * 0xc + 8);
  if (listRecordThenDstCursor != (undefined4 *)0x0) {
    listRecordThenDstCursor[1] = count;
    loopIndex = 0;
    *listRecordThenDstCursor = location;
    listRecordThenDstCursor = listRecordThenDstCursor + 2;
    while( true ) {
      *listRecordThenDstCursor = *value;
      listRecordThenDstCursor[1] = value[1];
      listRecordThenDstCursor[2] = value[2];
      if (loopIndex == count + -1) break;
      listRecordThenDstCursor = listRecordThenDstCursor + 3;
      value = value + 3;
      loopIndex = loopIndex + 1;
    }
  }
  return listRecordThenDstCursor;
}

/* _glUniform2fvARB_Comp @ 0x8c124 (144 bytes) */
int _glUniform2fvARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *listRecordThenPreviousSlot;
  undefined4 *vectorSlot;
  
  listRecordThenPreviousSlot = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform2fvARB_ListExec_001102e8,count * 8 + 8);
  vectorSlot = (undefined4 *)0x0;
  if (listRecordThenPreviousSlot != (undefined4 *)0x0) {
    listRecordThenPreviousSlot[1] = count;
    loopIndex = 0;
    *listRecordThenPreviousSlot = location;
    while( true ) {
      vectorSlot = listRecordThenPreviousSlot + 2;
      *vectorSlot = *value;
      listRecordThenPreviousSlot[3] = value[1];
      if (loopIndex == count + -1) break;
      value = value + 2;
      loopIndex = loopIndex + 1;
      listRecordThenPreviousSlot = vectorSlot;
    }
  }
  return vectorSlot;
}

/* _glUniform1fvARB_Comp @ 0x8c1b4 (136 bytes) */
int _glUniform1fvARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *listRecordThenDestination;
  
  listRecordThenDestination = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform1fvARB_ListExec_001102e4,count * 4 + 8);
  if (listRecordThenDestination != (undefined4 *)0x0) {
    listRecordThenDestination[1] = count;
    *listRecordThenDestination = location;
    listRecordThenDestination = listRecordThenDestination + 2;
    for (loopIndex = 0; *listRecordThenDestination = *value, loopIndex != count + -1; loopIndex = loopIndex + 1) {
      listRecordThenDestination = listRecordThenDestination + 1;
      value = value + 1;
    }
  }
  return listRecordThenDestination;
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
  undefined4 *listRecordThenDestination;
  int loopIndex;
  
  listRecordThenDestination = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform4ivARB_ListExec_001102d0,count * 0x10 + 8);
  if (listRecordThenDestination != (undefined4 *)0x0) {
    listRecordThenDestination[1] = count;
    loopIndex = 0;
    *listRecordThenDestination = location;
    listRecordThenDestination = listRecordThenDestination + 2;
    while( true ) {
      *listRecordThenDestination = *value;
      listRecordThenDestination[1] = value[1];
      listRecordThenDestination[2] = value[2];
      listRecordThenDestination[3] = value[3];
      if (loopIndex == count + -1) break;
      listRecordThenDestination = listRecordThenDestination + 4;
      value = value + 4;
      loopIndex = loopIndex + 1;
    }
  }
  return listRecordThenDestination;
}

/* _glUniform3ivARB_Comp @ 0x8c45c (152 bytes) */
int _glUniform3ivARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  undefined4 *listRecordThenWriteCursor;
  int loopIndex;
  
  listRecordThenWriteCursor = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform3ivARB_ListExec_001102cc,count * 0xc + 8);
  if (listRecordThenWriteCursor != (undefined4 *)0x0) {
    listRecordThenWriteCursor[1] = count;
    loopIndex = 0;
    *listRecordThenWriteCursor = location;
    listRecordThenWriteCursor = listRecordThenWriteCursor + 2;
    while( true ) {
      *listRecordThenWriteCursor = *value;
      listRecordThenWriteCursor[1] = value[1];
      listRecordThenWriteCursor[2] = value[2];
      if (loopIndex == count + -1) break;
      listRecordThenWriteCursor = listRecordThenWriteCursor + 3;
      value = value + 3;
      loopIndex = loopIndex + 1;
    }
  }
  return listRecordThenWriteCursor;
}

/* _glUniform2ivARB_Comp @ 0x8c4f4 (144 bytes) */
int _glUniform2ivARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  undefined4 *recordCursor;
  undefined4 *pairDestOrNull;
  int loopIndex;
  
  recordCursor = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform2ivARB_ListExec_001102c8,count * 8 + 8);
  pairDestOrNull = (undefined4 *)0x0;
  if (recordCursor != (undefined4 *)0x0) {
    recordCursor[1] = count;
    loopIndex = 0;
    *recordCursor = location;
    while( true ) {
      pairDestOrNull = recordCursor + 2;
      *pairDestOrNull = *value;
      recordCursor[3] = value[1];
      if (loopIndex == count + -1) break;
      value = value + 2;
      loopIndex = loopIndex + 1;
      recordCursor = pairDestOrNull;
    }
  }
  return pairDestOrNull;
}

/* _glUniform1ivARB_Comp @ 0x8c584 (136 bytes) */
int _glUniform1ivARB_Comp(glContext, location, count, value)
  undefined4 glContext;
  undefined4 location;
  int count;
  undefined4 *value;
{
  int loopIndex;
  undefined4 *listRecordThenDstCursor;
  
  listRecordThenDstCursor = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniform1ivARB_ListExec_001102c4,count * 4 + 8);
  if (listRecordThenDstCursor != (undefined4 *)0x0) {
    listRecordThenDstCursor[1] = count;
    *listRecordThenDstCursor = location;
    listRecordThenDstCursor = listRecordThenDstCursor + 2;
    for (loopIndex = 0; *listRecordThenDstCursor = *value, loopIndex != count + -1; loopIndex = loopIndex + 1) {
      listRecordThenDstCursor = listRecordThenDstCursor + 1;
      value = value + 1;
    }
  }
  return listRecordThenDstCursor;
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

