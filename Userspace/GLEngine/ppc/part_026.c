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
  undefined4 *srcLastElement;
  int *rendererCallbacks;
  bool stage0Updated;
  bool stage1Updated;
  undefined4 uniformWord1;
  int currentProgram;
  undefined4 *dstCursor;
  undefined4 *rendererHandlePtr;
  int typeInfoFound;
  int rendererRecordCursor;
  int loopIndex2;
  int elementMapOffset;
  int rendererSlotOffset;
  int elementValueOffset;
  int loopIndex3;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int registerIndexThenOffset;
  int loopIndex;
  int uniformSize;
  int uniformType;
  undefined2 uniformStageUse [10];
  
  uniformType = 0;
  uniformStageUse[0] = 0;
  uniformSize = 0;
  stage0Updated = false;
  stage1Updated = false;
  if (location != -1) {
    currentProgram = *(int *)(glContext + 0x5430);
    if ((((currentProgram == 0) || (*(int *)(currentProgram + 0x30) <= location)) || (count < 0)) ||
       ((typeInfoFound = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
        typeInfoFound == 0 || (uniformType != 0x8b5a)))) {
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
    }
    else if (count != 0) {
      dstCursor = (undefined4 *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
      if (count < uniformSize) {
        uniformSize = count;
      }
      if (transpose == 0) {
        loopIndex2 = 0;
        if (0 < uniformSize) {
          do {
            loopIndex2 = loopIndex2 + 1;
            *dstCursor = *value;
            dstCursor[1] = value[1];
            dstCursor[4] = value[2];
            srcLastElement = value + 3;
            value = value + 4;
            dstCursor[5] = *srcLastElement;
            dstCursor = dstCursor + 8;
          } while (loopIndex2 < uniformSize);
        }
      }
      else {
        loopIndex2 = 0;
        if (0 < uniformSize) {
          do {
            loopIndex2 = loopIndex2 + 1;
            *dstCursor = *value;
            dstCursor[4] = value[1];
            dstCursor[1] = value[2];
            srcLastElement = value + 3;
            value = value + 4;
            dstCursor[5] = *srcLastElement;
            dstCursor = dstCursor + 8;
          } while (loopIndex2 < uniformSize);
        }
      }
      loopIndex2 = 0;
      if (0 < uniformSize) {
        do {
          loopIndex = 0;
          elementValueOffset = location << 4;
          elementMapOffset = location << 2;
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
          } while (loopIndex < 2);
          loopIndex2 = loopIndex2 + 1;
          location = location + 2;
        } while (loopIndex2 < uniformSize);
      }
      *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x4000000;
      if (stage0Updated) {
        rendererRecordCursor = glContext + 0x10000;
        loopIndex3 = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
            rendererSlotOffset = loopIndex3 * 4;
            loopIndex3 = loopIndex3 + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
            rendererRecordCursor = rendererRecordCursor + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x20) + 0x4e4),2);
          } while (loopIndex3 < (int)(uint)*(byte *)(glContext + 0x85a4));
        }
      }
      if (stage1Updated) {
        rendererRecordCursor = glContext + 0x10000;
        loopIndex3 = 0;
        if (*(char *)(glContext + 0x85a4) != '\0') {
          do {
            rendererCallbacks = (int *)(rendererRecordCursor + -0x777c);
            rendererSlotOffset = loopIndex3 * 4;
            loopIndex3 = loopIndex3 + 1;
            rendererHandlePtr = (undefined4 *)(rendererRecordCursor + -0x7a54);
            rendererRecordCursor = rendererRecordCursor + 0x2e0;
            (**(code **)(*rendererCallbacks + 0x194))
                      (*rendererHandlePtr,*(undefined4 *)(rendererSlotOffset + *(int *)(currentProgram + 0x24) + 0x4e4),2);
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
  undefined4 *srcLastElement;
  int *rendererCallbacks;
  bool stage0Updated;
  bool stage1Updated;
  undefined4 uniformWord1;
  int currentProgram;
  undefined4 *dstCursor;
  undefined4 *rendererHandlePtr;
  int typeInfoFound;
  int rendererRecordCursor;
  int loopIndex;
  int elementMapOffset;
  int rendererSlotOffset;
  int iVar10;
  int loopIndex2;
  int iVar11;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int registerIndexThenOffset;
  int remaining;
  int uniformSize;
  int uniformType;
  undefined2 uniformStageUse [10];
  
  uniformType = 0;
  uniformStageUse[0] = 0;
  uniformSize = 0;
  stage0Updated = false;
  stage1Updated = false;
  if (location != -1) {
    currentProgram = *(int *)(glContext + 0x5430);
    if ((((currentProgram == 0) || (*(int *)(currentProgram + 0x30) <= location)) || (count < 0)) ||
       ((typeInfoFound = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
        typeInfoFound == 0 || (uniformType != 0x8b5b)))) {
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
    }
    else if (count != 0) {
      dstCursor = (undefined4 *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
      if (count < uniformSize) {
        uniformSize = count;
      }
      if (transpose == 0) {
        loopIndex = 0;
        if (0 < uniformSize) {
          do {
            loopIndex = loopIndex + 1;
            *dstCursor = *value;
            dstCursor[1] = value[1];
            dstCursor[2] = value[2];
            dstCursor[4] = value[3];
            dstCursor[5] = value[4];
            dstCursor[6] = value[5];
            dstCursor[8] = value[6];
            dstCursor[9] = value[7];
            srcLastElement = value + 8;
            value = value + 9;
            dstCursor[10] = *srcLastElement;
            dstCursor = dstCursor + 0xc;
          } while (loopIndex < uniformSize);
        }
      }
      else {
        loopIndex = 0;
        if (0 < uniformSize) {
          do {
            loopIndex = loopIndex + 1;
            *dstCursor = *value;
            dstCursor[4] = value[1];
            dstCursor[8] = value[2];
            dstCursor[1] = value[3];
            dstCursor[5] = value[4];
            dstCursor[9] = value[5];
            dstCursor[2] = value[6];
            dstCursor[6] = value[7];
            srcLastElement = value + 8;
            value = value + 9;
            dstCursor[10] = *srcLastElement;
            dstCursor = dstCursor + 0xc;
          } while (loopIndex < uniformSize);
        }
      }
      loopIndex = 0;
      if (0 < uniformSize) {
        iVar10 = location << 4;
        do {
          remaining = 3;
          elementMapOffset = location << 2;
          iVar11 = iVar10;
          do {
            stage0Record = *(int *)(currentProgram + 0x20);
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(stage0Record + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(stage0Record + 0x51c);
              stage0Updated = true;
              uniformValueSlot = iVar11 + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(iVar11 + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            registerIndexThenOffset = *(int *)(elementMapOffset + *(int *)(*(int *)(currentProgram + 0x24) + 0x4e0));
            if (registerIndexThenOffset != -1) {
              registerIndexThenOffset = registerIndexThenOffset * 0x10;
              constantRegisterFile = *(int *)(*(int *)(currentProgram + 0x24) + 0x51c);
              stage1Updated = true;
              uniformValueSlot = iVar11 + *(int *)(currentProgram + 0x4c);
              uniformWord3 = *(undefined4 *)(uniformValueSlot + 0xc);
              constantRegister = registerIndexThenOffset + constantRegisterFile;
              uniformWord1 = *(undefined4 *)(uniformValueSlot + 4);
              uniformWord2 = *(undefined4 *)(uniformValueSlot + 8);
              *(undefined4 *)(registerIndexThenOffset + constantRegisterFile) = *(undefined4 *)(iVar11 + *(int *)(currentProgram + 0x4c));
              *(undefined4 *)(constantRegister + 0xc) = uniformWord3;
              *(undefined4 *)(constantRegister + 4) = uniformWord1;
              *(undefined4 *)(constantRegister + 8) = uniformWord2;
            }
            elementMapOffset = elementMapOffset + 4;
            iVar11 = iVar11 + 0x10;
            remaining = remaining + -1;
          } while (remaining != 0);
          loopIndex = loopIndex + 1;
          location = location + 3;
          iVar10 = iVar10 + 0x30;
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
  undefined4 *srcLastElement;
  int *rendererCallbacks;
  bool stage0Updated;
  bool stage1Updated;
  undefined4 uniformWord1;
  int currentProgram;
  undefined4 *dstCursor;
  undefined4 *rendererHandlePtr;
  int typeInfoFound;
  int rendererRecordCursor;
  int loopIndex;
  int elementMapOffset;
  int rendererSlotOffset;
  int elementValueOffset;
  int loopIndex2;
  undefined4 uniformWord3;
  int constantRegisterFile;
  int stage0Record;
  int constantRegister;
  int uniformValueSlot;
  undefined4 uniformWord2;
  int registerIndexThenOffset;
  int remaining;
  int uniformSize;
  int uniformType;
  undefined2 uniformStageUse [10];
  
  uniformType = 0;
  uniformStageUse[0] = 0;
  uniformSize = 0;
  stage0Updated = false;
  stage1Updated = false;
  if (location != -1) {
    currentProgram = *(int *)(glContext + 0x5430);
    if ((((currentProgram == 0) || (*(int *)(currentProgram + 0x30) <= location)) || (count < 0)) ||
       ((typeInfoFound = _ShGetUniformTypeInfo
                           (*(undefined4 *)(currentProgram + 0x40),location,&uniformSize,&uniformType,uniformStageUse),
        typeInfoFound == 0 || (uniformType != 0x8b5c)))) {
      if (*(int *)(glContext + 0x7574) == 0) {
        *(undefined4 *)(glContext + 0x7574) = 0x502;
      }
    }
    else if (count != 0) {
      dstCursor = (undefined4 *)(*(int *)(currentProgram + 0x4c) + location * 0x10);
      if (count < uniformSize) {
        uniformSize = count;
      }
      if (transpose == 0) {
        loopIndex = 0;
        if (0 < uniformSize) {
          do {
            loopIndex = loopIndex + 1;
            *dstCursor = *value;
            dstCursor[1] = value[1];
            dstCursor[2] = value[2];
            dstCursor[3] = value[3];
            dstCursor[4] = value[4];
            dstCursor[5] = value[5];
            dstCursor[6] = value[6];
            dstCursor[7] = value[7];
            dstCursor[8] = value[8];
            dstCursor[9] = value[9];
            dstCursor[10] = value[10];
            dstCursor[0xb] = value[0xb];
            dstCursor[0xc] = value[0xc];
            dstCursor[0xd] = value[0xd];
            dstCursor[0xe] = value[0xe];
            srcLastElement = value + 0xf;
            value = value + 0x10;
            dstCursor[0xf] = *srcLastElement;
            dstCursor = dstCursor + 0x10;
          } while (loopIndex < uniformSize);
        }
      }
      else {
        loopIndex = 0;
        if (0 < uniformSize) {
          do {
            loopIndex = loopIndex + 1;
            *dstCursor = *value;
            dstCursor[4] = value[1];
            dstCursor[8] = value[2];
            dstCursor[0xc] = value[3];
            dstCursor[1] = value[4];
            dstCursor[5] = value[5];
            dstCursor[9] = value[6];
            dstCursor[0xd] = value[7];
            dstCursor[2] = value[8];
            dstCursor[6] = value[9];
            dstCursor[10] = value[10];
            dstCursor[0xe] = value[0xb];
            dstCursor[3] = value[0xc];
            dstCursor[7] = value[0xd];
            dstCursor[0xb] = value[0xe];
            srcLastElement = value + 0xf;
            value = value + 0x10;
            dstCursor[0xf] = *srcLastElement;
            dstCursor = dstCursor + 0x10;
          } while (loopIndex < uniformSize);
        }
      }
      loopIndex = 0;
      if (0 < uniformSize) {
        do {
          elementValueOffset = location << 4;
          remaining = 4;
          elementMapOffset = location << 2;
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
            elementMapOffset = elementMapOffset + 4;
            elementValueOffset = elementValueOffset + 0x10;
            remaining = remaining + -1;
          } while (remaining != 0);
          loopIndex = loopIndex + 1;
          location = location + 4;
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
  undefined4 *listRecordThenDestination;
  
  listRecordThenDestination = (undefined4 *)
           _gleAddListItem(glContext,PTR__glUniformMatrix2fvARB_ListExec_001102c0,count * 0x10 + 8);
  if (listRecordThenDestination != (undefined4 *)0x0) {
    listRecordThenDestination[1] = count;
    *listRecordThenDestination = location;
    listRecordThenDestination = listRecordThenDestination + 2;
    loopIndex = 0;
    if (transpose == 0) {
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
    else {
      while( true ) {
        *listRecordThenDestination = *value;
        listRecordThenDestination[2] = value[1];
        listRecordThenDestination[1] = value[2];
        listRecordThenDestination[3] = value[3];
        if (loopIndex == count + -1) break;
        listRecordThenDestination = listRecordThenDestination + 4;
        value = value + 4;
        loopIndex = loopIndex + 1;
      }
    }
  }
  return listRecordThenDestination;
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
int _gleGetObjectParameter(unusedArg1, shaderObject, pname, result)
  undefined4 unusedArg1;
  int shaderObject;
  undefined4 pname;
  uint *result;
{
  uint value;
  uint objectTypeThenZero;
  int logLength;
  
  switch(pname) {
  case 0x8b4e:
    objectTypeThenZero = *(uint *)(shaderObject + 0x10);
    if ((objectTypeThenZero != 0x8b40) && (objectTypeThenZero != 0x8b48)) {
      return 0x502;
    }
    goto LAB_0008e178;
  case 0x8b4f:
    if (*(int *)(shaderObject + 0x10) != 0x8b48) {
      return 0x502;
    }
    value = *(uint *)(shaderObject + 0x20);
    break;
  default:
    return 0x500;
  case 0x8b80:
    if ((*(int *)(shaderObject + 0x10) != 0x8b40) && (*(int *)(shaderObject + 0x10) != 0x8b48)) {
      return 0x502;
    }
    value = (uint)*(byte *)(shaderObject + 0x14);
    break;
  case 0x8b81:
    if (*(int *)(shaderObject + 0x10) != 0x8b48) {
      return 0x502;
    }
    value = (uint)*(byte *)(shaderObject + 0x25);
    break;
  case 0x8b82:
    if (*(int *)(shaderObject + 0x10) != 0x8b40) {
      return 0x502;
    }
    value = (uint)*(byte *)(shaderObject + 0x3c);
    break;
  case 0x8b83:
    if (*(int *)(shaderObject + 0x10) != 0x8b40) {
      return 0x502;
    }
    value = (uint)*(byte *)(shaderObject + 0x3d);
    break;
  case 0x8b84:
    if ((*(int *)(shaderObject + 0x10) != 0x8b40) && (*(int *)(shaderObject + 0x10) != 0x8b48)) {
      return 0x502;
    }
    logLength = *(int *)(shaderObject + 0x1c);
    goto LAB_0008e16c;
  case 0x8b85:
    if (*(int *)(shaderObject + 0x10) != 0x8b40) {
      return 0x502;
    }
    value = *(uint *)(shaderObject + 0x48);
    break;
  case 0x8b86:
    if (*(int *)(shaderObject + 0x10) != 0x8b40) {
      return 0x502;
    }
    value = *(uint *)(shaderObject + 0x28);
    break;
  case 0x8b87:
    if (*(int *)(shaderObject + 0x10) != 0x8b40) {
      return 0x502;
    }
    value = *(uint *)(shaderObject + 0x2c);
    break;
  case 0x8b88:
    if (*(int *)(shaderObject + 0x10) != 0x8b48) {
      return 0x502;
    }
    logLength = *(int *)(shaderObject + 0x28);
LAB_0008e16c:
    value = logLength + 1;
    objectTypeThenZero = 0;
    if (logLength == 0) {
LAB_0008e178:
      *result = objectTypeThenZero;
      return 0;
    }
    break;
  case 0x8b89:
    if (*(int *)(shaderObject + 0x10) != 0x8b40) {
      return 0x502;
    }
    value = *(uint *)(shaderObject + 0x34);
    break;
  case 0x8b8a:
    if (*(int *)(shaderObject + 0x10) != 0x8b40) {
      return 0x502;
    }
    value = *(uint *)(shaderObject + 0x38);
  }
  *result = value;
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
  int sharedStateThenObjectThenError;
  undefined4 paramValues [7];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    sharedStateThenObjectThenError = *(int *)(glContext + 0x5148);
    if (*(char *)(sharedStateThenObjectThenError + 0x8024) != '\0') {
      _pthread_mutex_lock(sharedStateThenObjectThenError + 0x8028);
      sharedStateThenObjectThenError = *(int *)(glContext + 0x5148);
    }
    sharedStateThenObjectThenError = _gleLookupHashObject(sharedStateThenObjectThenError + 0x6018,obj);
    if (sharedStateThenObjectThenError != 0) {
      sharedStateThenObjectThenError = ((int (*)())_gleGetObjectParameter)(glContext,sharedStateThenObjectThenError,pname,paramValues);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (sharedStateThenObjectThenError != 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        *(int *)(glContext + 0x7574) = sharedStateThenObjectThenError;
        return;
      }
      *params = paramValues[0];
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
  int sharedStateThenShaderObjectThenError;
  undefined4 paramValues [7];
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    sharedStateThenShaderObjectThenError = *(int *)(glContext + 0x5148);
    if (*(char *)(sharedStateThenShaderObjectThenError + 0x8024) != '\0') {
      _pthread_mutex_lock(sharedStateThenShaderObjectThenError + 0x8028);
      sharedStateThenShaderObjectThenError = *(int *)(glContext + 0x5148);
    }
    sharedStateThenShaderObjectThenError = _gleLookupHashObject(sharedStateThenShaderObjectThenError + 0x6018,shader);
    if (sharedStateThenShaderObjectThenError == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_0008e4c4;
    }
    if (*(int *)(sharedStateThenShaderObjectThenError + 0x10) == 0x8b48) {
      if (pname == 0x8b4e) {
        pname = 0x8b4f;
      }
      sharedStateThenShaderObjectThenError = ((int (*)())_gleGetObjectParameter)(glContext,sharedStateThenShaderObjectThenError,pname,paramValues);
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (sharedStateThenShaderObjectThenError != 0) {
        if (*(int *)(glContext + 0x7574) != 0) {
          return;
        }
        *(int *)(glContext + 0x7574) = sharedStateThenShaderObjectThenError;
        return;
      }
      *params = paramValues[0];
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
  int sharedStateThenProgramObject;
  uint copyLength;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    sharedStateThenProgramObject = *(int *)(glContext + 0x5148);
    if (*(char *)(sharedStateThenProgramObject + 0x8024) != '\0') {
      _pthread_mutex_lock(sharedStateThenProgramObject + 0x8028);
      sharedStateThenProgramObject = *(int *)(glContext + 0x5148);
    }
    sharedStateThenProgramObject = _gleLookupHashObject(sharedStateThenProgramObject + 0x6018,program);
    if (sharedStateThenProgramObject == 0) {
      if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
        _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      }
      if (*(int *)(glContext + 0x7574) != 0) {
        return;
      }
      glErrorCode = 0x501;
      goto LAB_0008ea20;
    }
    if (*(int *)(sharedStateThenProgramObject + 0x10) == 0x8b40) {
      copyLength = *(uint *)(sharedStateThenProgramObject + 0x1c);
      if (bufSize - 1U < *(uint *)(sharedStateThenProgramObject + 0x1c)) {
        copyLength = bufSize - 1U;
      }
      _strncpy(infoLog,*(char **)(sharedStateThenProgramObject + 0x18),copyLength);
      infoLog[copyLength] = '\0';
      if (length != (size_t *)0x0) {
        *length = copyLength;
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
  int sharedStateThenProgramObjectThenQueryResult;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    sharedStateThenProgramObjectThenQueryResult = *(int *)(glContext + 0x5148);
    if (*(char *)(sharedStateThenProgramObjectThenQueryResult + 0x8024) != '\0') {
      _pthread_mutex_lock(sharedStateThenProgramObjectThenQueryResult + 0x8028);
      sharedStateThenProgramObjectThenQueryResult = *(int *)(glContext + 0x5148);
    }
    sharedStateThenProgramObjectThenQueryResult = _gleLookupHashObject(sharedStateThenProgramObjectThenQueryResult + 0x6018,programObj);
    if (sharedStateThenProgramObjectThenQueryResult == 0) {
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
    if (*(int *)(sharedStateThenProgramObjectThenQueryResult + 0x10) == 0x8b40) {
      if (*(uint *)(sharedStateThenProgramObjectThenQueryResult + 0x28) <= index) goto LAB_0008ef74;
      sharedStateThenProgramObjectThenQueryResult = _ShGetActiveUniform(*(undefined4 *)(sharedStateThenProgramObjectThenQueryResult + 0x40),index,maxLength,length,size,
                                  type,name);
      if (sharedStateThenProgramObjectThenQueryResult != 0) {
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
  float lastComponent;
  double intToDoubleBias;
  undefined4 glErrorCode;
  int sharedStateThenProgramObject;
  int locationValueOffset;
  int uniformValues;
  int typeInfoFound;
  uint *uniformValue;
  undefined1 auStack_38 [4];
  uint uniformType;
  undefined2 uniformStageUse [14];
  
  uniformStageUse[0] = 0;
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
  sharedStateThenProgramObject = *(int *)(glContext + 0x5148);
  if (*(char *)(sharedStateThenProgramObject + 0x8024) != '\0') {
    _pthread_mutex_lock(sharedStateThenProgramObject + 0x8028);
    sharedStateThenProgramObject = *(int *)(glContext + 0x5148);
  }
  sharedStateThenProgramObject = _gleLookupHashObject(sharedStateThenProgramObject + 0x6018,programObj);
  if (sharedStateThenProgramObject == 0) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_0008f164;
  }
  if ((((*(int *)(sharedStateThenProgramObject + 0x10) != 0x8b40) || (*(char *)(sharedStateThenProgramObject + 0x3c) != '\x01')) ||
      (*(int *)(sharedStateThenProgramObject + 0x30) <= location)) ||
     ((location == -1 ||
      (typeInfoFound = _ShGetUniformTypeInfo
                         (*(undefined4 *)(sharedStateThenProgramObject + 0x40),location,auStack_38,&uniformType,uniformStageUse),
      intToDoubleBias = DOUBLE_00108d58, typeInfoFound == 0)))) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    goto LAB_0008f154;
  }
  uniformValues = *(int *)(sharedStateThenProgramObject + 0x4c);
  locationValueOffset = location * 0x10;
  uniformValue = (uint *)(uniformValues + locationValueOffset);
  if (uniformType == 0x8b56) {
LAB_0008f414:
    lastComponent = (float)((double)CONCAT44(0x43300000,*uniformValue ^ 0x80000000) - DOUBLE_00108d58);
  }
  else {
    if (0x8b56 < uniformType) {
      if (uniformType == 0x8b5a) {
        *params = *(float *)(uniformValues + locationValueOffset);
        params[1] = GH_U2F((unsigned int)(uniformValue[1]));
        params[2] = GH_U2F((unsigned int)(uniformValue[4]));
        lastComponent = GH_U2F((unsigned int)(uniformValue[5]));
LAB_0008f460:
        params[3] = lastComponent;
        goto LAB_0008f534;
      }
      if (uniformType < 0x8b5b) {
        if (uniformType != 0x8b58) {
          if (0x8b58 < uniformType) {
LAB_0008f290:
            *params = (float)((double)CONCAT44(0x43300000,*uniformValue ^ 0x80000000) - DOUBLE_00108d58);
            params[1] = (float)((double)CONCAT44(0x43300000,uniformValue[1] ^ 0x80000000) - intToDoubleBias);
            params[2] = (float)((double)CONCAT44(0x43300000,uniformValue[2] ^ 0x80000000) - intToDoubleBias);
            params[3] = (float)((double)CONCAT44(0x43300000,uniformValue[3] ^ 0x80000000) - intToDoubleBias);
            goto LAB_0008f534;
          }
          goto LAB_0008f3bc;
        }
LAB_0008f338:
        *params = (float)((double)CONCAT44(0x43300000,*uniformValue ^ 0x80000000) - DOUBLE_00108d58);
        params[1] = (float)((double)CONCAT44(0x43300000,uniformValue[1] ^ 0x80000000) - intToDoubleBias);
        lastComponent = (float)((double)CONCAT44(0x43300000,uniformValue[2] ^ 0x80000000) - intToDoubleBias);
        goto LAB_0008f3a0;
      }
      if (uniformType == 0x8b5c) {
        *params = *(float *)(uniformValues + locationValueOffset);
        params[1] = GH_U2F((unsigned int)(uniformValue[1]));
        params[2] = GH_U2F((unsigned int)(uniformValue[2]));
        params[3] = GH_U2F((unsigned int)(uniformValue[3]));
        params[4] = GH_U2F((unsigned int)(uniformValue[4]));
        params[5] = GH_U2F((unsigned int)(uniformValue[5]));
        params[6] = GH_U2F((unsigned int)(uniformValue[6]));
        params[7] = GH_U2F((unsigned int)(uniformValue[7]));
        params[8] = GH_U2F((unsigned int)(uniformValue[8]));
        params[9] = GH_U2F((unsigned int)(uniformValue[9]));
        params[10] = GH_U2F((unsigned int)(uniformValue[10]));
        params[0xb] = GH_U2F((unsigned int)(uniformValue[0xb]));
        params[0xc] = GH_U2F((unsigned int)(uniformValue[0xc]));
        params[0xd] = GH_U2F((unsigned int)(uniformValue[0xd]));
        params[0xe] = GH_U2F((unsigned int)(uniformValue[0xe]));
        params[0xf] = GH_U2F((unsigned int)(uniformValue[0xf]));
        goto LAB_0008f534;
      }
      if (uniformType < 0x8b5c) {
        *params = *(float *)(uniformValues + locationValueOffset);
        params[1] = GH_U2F((unsigned int)(uniformValue[1]));
        params[2] = GH_U2F((unsigned int)(uniformValue[2]));
        params[3] = GH_U2F((unsigned int)(uniformValue[4]));
        params[4] = GH_U2F((unsigned int)(uniformValue[5]));
        params[5] = GH_U2F((unsigned int)(uniformValue[6]));
        params[6] = GH_U2F((unsigned int)(uniformValue[8]));
        params[7] = GH_U2F((unsigned int)(uniformValue[9]));
        params[8] = GH_U2F((unsigned int)(uniformValue[10]));
        goto LAB_0008f534;
      }
      if (0x8b64 < uniformType) goto LAB_0008f534;
      goto LAB_0008f414;
    }
    if (uniformType == 0x8b51) {
      *params = *(float *)(uniformValues + locationValueOffset);
      params[1] = GH_U2F((unsigned int)(uniformValue[1]));
      lastComponent = GH_U2F((unsigned int)(uniformValue[2]));
LAB_0008f3a0:
      params[2] = lastComponent;
      goto LAB_0008f534;
    }
    if (0x8b51 < uniformType) {
      if (uniformType == 0x8b53) {
LAB_0008f3bc:
        *params = (float)((double)CONCAT44(0x43300000,*uniformValue ^ 0x80000000) - DOUBLE_00108d58);
        params[1] = (float)((double)CONCAT44(0x43300000,uniformValue[1] ^ 0x80000000) - intToDoubleBias);
        goto LAB_0008f534;
      }
      if (0x8b52 < uniformType) {
        if (uniformType != 0x8b54) {
          if (uniformType != 0x8b55) goto LAB_0008f534;
          goto LAB_0008f290;
        }
        goto LAB_0008f338;
      }
      *params = *(float *)(uniformValues + locationValueOffset);
      params[1] = GH_U2F((unsigned int)(uniformValue[1]));
      params[2] = GH_U2F((unsigned int)(uniformValue[2]));
      lastComponent = GH_U2F((unsigned int)(uniformValue[3]));
      goto LAB_0008f460;
    }
    if (uniformType != 0x1406) {
      if (0x1406 < uniformType) {
        if (uniformType == 0x8b50) {
          *params = *(float *)(uniformValues + locationValueOffset);
          params[1] = GH_U2F((unsigned int)(uniformValue[1]));
        }
        goto LAB_0008f534;
      }
      if (uniformType != 0x1404) goto LAB_0008f534;
      goto LAB_0008f414;
    }
    lastComponent = *(float *)(uniformValues + locationValueOffset);
  }
  *params = lastComponent;
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
  int intValue;
  int programObject;
  int sharedState;
  int locationValueOffset;
  int uniformValues;
  int typeInfoFound;
  int *uniformValue;
  float roundedComponent;
  undefined1 auStack_38 [4];
  uint uniformType;
  undefined2 uniformStageUse [14];
  
  uniformStageUse[0] = 0;
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
  sharedState = *(int *)(glContext + 0x5148);
  if (*(char *)(sharedState + 0x8024) != '\0') {
    _pthread_mutex_lock(sharedState + 0x8028);
    sharedState = *(int *)(glContext + 0x5148);
  }
  programObject = _gleLookupHashObject(sharedState + 0x6018,programObj);
  if (programObject == 0) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    if (*(int *)(glContext + 0x7574) != 0) {
      return;
    }
    glErrorCode = 0x501;
    goto LAB_0008f680;
  }
  if ((((*(int *)(programObject + 0x10) != 0x8b40) || (*(char *)(programObject + 0x3c) != '\x01')) ||
      (*(int *)(programObject + 0x30) <= location)) ||
     ((location == -1 ||
      (typeInfoFound = _ShGetUniformTypeInfo
                         (*(undefined4 *)(programObject + 0x40),location,auStack_38,&uniformType,uniformStageUse),
      typeInfoFound == 0)))) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    goto LAB_0008f670;
  }
  uniformValues = *(int *)(programObject + 0x4c);
  locationValueOffset = location * 0x10;
  uniformValue = (int *)(uniformValues + locationValueOffset);
  if (uniformType == 0x8b56) {
LAB_0008f8c4:
    intValue = *uniformValue;
  }
  else {
    if (0x8b56 < uniformType) {
      if (uniformType == 0x8b5a) {
        roundedComponent = _roundf(*(float *)(uniformValues + locationValueOffset));
        *params = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[1])));
        params[1] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[4])));
        params[2] = (int)roundedComponent;
        roundedComponent = GH_U2F((unsigned int)(uniformValue[5]));
LAB_0008f91c:
        roundedComponent = _roundf(roundedComponent);
        params[3] = (int)roundedComponent;
        goto LAB_0008fb90;
      }
      if (uniformType < 0x8b5b) {
        if (uniformType != 0x8b58) {
          if (0x8b58 < uniformType) {
LAB_0008f7dc:
            *params = *uniformValue;
            params[1] = uniformValue[1];
            params[2] = uniformValue[2];
            params[3] = uniformValue[3];
            goto LAB_0008fb90;
          }
          goto LAB_0008f898;
        }
LAB_0008f848:
        *params = *uniformValue;
        params[1] = uniformValue[1];
        intValue = uniformValue[2];
        goto LAB_0008f85c;
      }
      if (uniformType == 0x8b5c) {
        roundedComponent = _roundf(*(float *)(uniformValues + locationValueOffset));
        *params = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[1])));
        params[1] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[2])));
        params[2] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[3])));
        params[3] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[4])));
        params[4] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[5])));
        params[5] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[6])));
        params[6] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[7])));
        params[7] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[8])));
        params[8] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[9])));
        params[9] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[10])));
        params[10] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[0xb])));
        params[0xb] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[0xc])));
        params[0xc] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[0xd])));
        params[0xd] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[0xe])));
        params[0xe] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[0xf])));
        params[0xf] = (int)roundedComponent;
        goto LAB_0008fb90;
      }
      if (uniformType < 0x8b5c) {
        roundedComponent = _roundf(*(float *)(uniformValues + locationValueOffset));
        *params = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[1])));
        params[1] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[2])));
        params[2] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[4])));
        params[3] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[5])));
        params[4] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[6])));
        params[5] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[8])));
        params[6] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[9])));
        params[7] = (int)roundedComponent;
        roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[10])));
        params[8] = (int)roundedComponent;
        goto LAB_0008fb90;
      }
      if (0x8b64 < uniformType) goto LAB_0008fb90;
      goto LAB_0008f8c4;
    }
    if (uniformType == 0x8b51) {
      roundedComponent = _roundf(*(float *)(uniformValues + locationValueOffset));
      *params = (int)roundedComponent;
      roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[1])));
      params[1] = (int)roundedComponent;
      roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[2])));
      intValue = (int)roundedComponent;
LAB_0008f85c:
      params[2] = intValue;
      goto LAB_0008fb90;
    }
    if (0x8b51 < uniformType) {
      if (uniformType == 0x8b53) {
LAB_0008f898:
        *params = *uniformValue;
        params[1] = uniformValue[1];
        goto LAB_0008fb90;
      }
      if (0x8b52 < uniformType) {
        if (uniformType != 0x8b54) {
          if (uniformType != 0x8b55) goto LAB_0008fb90;
          goto LAB_0008f7dc;
        }
        goto LAB_0008f848;
      }
      roundedComponent = _roundf(*(float *)(uniformValues + locationValueOffset));
      *params = (int)roundedComponent;
      roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[1])));
      params[1] = (int)roundedComponent;
      roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[2])));
      params[2] = (int)roundedComponent;
      roundedComponent = GH_U2F((unsigned int)(uniformValue[3]));
      goto LAB_0008f91c;
    }
    if (uniformType != 0x1406) {
      if (0x1406 < uniformType) {
        if (uniformType == 0x8b50) {
          roundedComponent = _roundf(*(float *)(uniformValues + locationValueOffset));
          *params = (int)roundedComponent;
          roundedComponent = _roundf(GH_U2F((unsigned int)(uniformValue[1])));
          params[1] = (int)roundedComponent;
        }
        goto LAB_0008fb90;
      }
      if (uniformType != 0x1404) goto LAB_0008fb90;
      goto LAB_0008f8c4;
    }
    roundedComponent = _roundf(*(float *)(uniformValues + locationValueOffset));
    intValue = (int)roundedComponent;
  }
  *params = intValue;
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
int _glActiveStencilFace_ListExec(glContext, listRecord)
  int glContext;
  uint *listRecord;
{
  undefined4 glErrorCode;
  
  if (*(short *)(glContext + 0x4a10) < 0) {
    if (*listRecord < 2) {
      *(char *)(glContext + 0x7583) = (char)*listRecord;
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
  int stencilOpRecord;
  undefined2 sfailShort;
  undefined2 dpfailShort;
  undefined2 dppassShort;
  
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
              sfailShort = (undefined2)sfail;
              dpfailShort = (undefined2)dpfail;
              dppassShort = (undefined2)dppass;
              if (face == 0x405) {
LAB_0009078c:
                *(undefined2 *)(glContext + 0x351a) = sfailShort;
                *(undefined2 *)(glContext + 0x351c) = dpfailShort;
                *(undefined2 *)(glContext + 0x351e) = dppassShort;
LAB_00090798:
                *(uint *)(glContext + 0x310) = *(uint *)(glContext + 0x310) | 0x10000000;
                return;
              }
              if (face < 0x406) {
                if (face == 0x404) {
                  stencilOpRecord = (uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext;
                  *(undefined2 *)(stencilOpRecord + 0x3506) = dppassShort;
                  *(undefined2 *)(stencilOpRecord + 0x3502) = sfailShort;
                  *(undefined2 *)(stencilOpRecord + 0x3504) = dpfailShort;
                  goto LAB_00090798;
                }
              }
              else if (face == 0x408) {
                stencilOpRecord = (uint)*(byte *)(glContext + 0x7583) * 0x10 + glContext;
                *(undefined2 *)(stencilOpRecord + 0x3506) = dppassShort;
                *(undefined2 *)(stencilOpRecord + 0x3502) = sfailShort;
                *(undefined2 *)(stencilOpRecord + 0x3504) = dpfailShort;
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

