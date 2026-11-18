#include "decls.h"

/* _LFSStreamChunkListCreate @ 0xd1854 (12 bytes) */
int _LFSStreamChunkListCreate()
{
  undefined4 chunkList;
  
  chunkList = _calloc(0xc,1);
  return chunkList;
}

/* _LFSStreamChunkListCreateFromChunkList @ 0xd1860 (96 bytes) */
int _LFSStreamChunkListCreateFromChunkList(sourceList)
  int *sourceList;
{
  undefined4 newList;
  undefined4 newChunk;
  int chunk;
  
  newList = ((int (*)())_LFSStreamChunkListCreate)();
  for (chunk = *sourceList; chunk != 0; chunk = *(int *)(chunk + 0x4c)) {
    newChunk = _LFSStreamChunkCreateFromChunk(chunk);
    ((void (*)())_LFSStreamChunkListAddChunk)(newList,newChunk);
  }
  return newList;
}

/* _LFSStreamChunkListFree @ 0xd18c0 (80 bytes) */
void _LFSStreamChunkListFree(chunkList)
  int *chunkList;
{
  int chunk;
  
  chunk = *chunkList;
  while (chunk != 0) {
    ((void (*)())_LFSStreamChunkListRemoveChunk)(chunkList,chunk);
    chunk = *chunkList;
  }
  _free(chunkList);
  return;
}

/* _LFSStreamChunkListAddChunk @ 0xd1910 (64 bytes) */
void _LFSStreamChunkListAddChunk(chunkList, chunk)
  int *chunkList;
  int chunk;
{
  int headChunk;
  
  headChunk = *chunkList;
  if (*chunkList == 0) {
    headChunk = chunk;
  }
  *chunkList = headChunk;
  if (chunkList[1] != 0) {
    *(int *)(chunkList[1] + 0x4c) = chunk;
    *(int *)(chunk + 0x48) = chunkList[1];
  }
  chunkList[1] = chunk;
  chunkList[2] = chunkList[2] + 1;
  return;
}

/* _LFSStreamChunkListRemoveChunk @ 0xd1950 (120 bytes) */
void _LFSStreamChunkListRemoveChunk(chunkList, chunk)
  undefined4 *chunkList;
  int chunk;
{
  int previousChunk;
  
  previousChunk = *(int *)(chunk + 0x48);
  if (previousChunk == 0) {
    *chunkList = *(undefined4 *)(chunk + 0x4c);
    previousChunk = *(int *)(chunk + 0x48);
  }
  else {
    *(undefined4 *)(previousChunk + 0x4c) = *(undefined4 *)(chunk + 0x4c);
  }
  if (*(int *)(chunk + 0x4c) == 0) {
    chunkList[1] = previousChunk;
  }
  else {
    *(int *)(*(int *)(chunk + 0x4c) + 0x48) = previousChunk;
  }
  _LFSStreamChunkFree(chunk);
  chunkList[2] = chunkList[2] + -1;
  return;
}

/* _LFSStreamChunkListGetStream @ 0xd19c8 (280 bytes) */
void _LFSStreamChunkListGetStream(chunkList, outStream, outCount, forwardedArg4)
  int *chunkList;
  int outStream;
  int *outCount;
  undefined4 forwardedArg4;
{
  undefined4 streamWord;
  int wordIndex;
  int byteOffset;
  int chunk;
  uint subIndex;
  undefined4 *dstCursor;
  uint chunkWordCount;
  undefined1 scratchCount [12];
  
  wordIndex = 0;
  *outCount = 0;
  for (chunk = *chunkList; chunk != 0; chunk = *(int *)(chunk + 0x4c)) {
    _LFSStreamChunkGetStream(chunk,forwardedArg4,&chunkWordCount,0);
    *outCount = *outCount + chunkWordCount;
  }
  if ((outStream != 0) && (chunk = *chunkList, chunk != 0)) {
    byteOffset = 0;
    do {
      streamWord = _LFSStreamChunkGetStream(chunk,forwardedArg4,&chunkWordCount,0);
      wordIndex = wordIndex + 1;
      *(undefined4 *)(byteOffset + outStream) = streamWord;
      byteOffset = byteOffset + 4;
      if (1 < chunkWordCount) {
        chunkWordCount = chunkWordCount - 1;
        subIndex = 0;
        if (chunkWordCount != 0) {
          dstCursor = (undefined4 *)(wordIndex * 4 + outStream);
          do {
            subIndex = subIndex + 1;
            wordIndex = wordIndex + 1;
            streamWord = _LFSStreamChunkGetStream(chunk,forwardedArg4,scratchCount,subIndex);
            byteOffset = byteOffset + 4;
            *dstCursor = streamWord;
            dstCursor = dstCursor + 1;
          } while (subIndex < chunkWordCount);
        }
      }
      chunk = *(int *)(chunk + 0x4c);
    } while (chunk != 0);
  }
  return;
}

/* _LFSStreamChunkListCompare @ 0xd1b0c (132 bytes) */
int _LFSStreamChunkListCompare(listA, listB)
  int *listA;
  int *listB;
{
  undefined4 differs;
  int chunkCompareResult;
  int chunkA;
  int chunkB;
  
  chunkA = *listA;
  differs = 1;
  chunkB = *listB;
  if (listA[2] == listB[2]) {
    for (; (chunkA != 0 && (chunkB != 0)); chunkB = *(int *)(chunkB + 0x4c)) {
      chunkCompareResult = _LFSStreamChunkCompare(chunkA,chunkB);
      if (chunkCompareResult != 0) {
        return 1;
      }
      chunkA = *(int *)(chunkA + 0x4c);
    }
    differs = 0;
  }
  return differs;
}

/* _LFSStreamChunkListOutputDebugInfo @ 0xd1b90 (68 bytes) */
void _LFSStreamChunkListOutputDebugInfo(chunkList)
  int *chunkList;
{
  int chunk;
  
  for (chunk = *chunkList; chunk != 0; chunk = *(int *)(chunk + 0x4c)) {
    _LFSStreamChunkOutputDebugInfo(chunk);
  }
  return;
}

/* _LFSStreamCreate @ 0xd1bd4 (104 bytes) */
int _LFSStreamCreate()
{
  undefined4 *stream;
  undefined4 chunkList;
  
  stream = (undefined4 *)_calloc(0x18,1);
  chunkList = ((int (*)())_LFSStreamChunkListCreate)();
  *stream = chunkList;
  chunkList = ((int (*)())_LFSStreamChunkListCreate)();
  stream[1] = chunkList;
  chunkList = ((int (*)())_LFSStreamChunkListCreate)();
  stream[2] = chunkList;
  chunkList = ((int (*)())_LFSStreamChunkListCreate)();
  stream[3] = chunkList;
  chunkList = ((int (*)())_LFSStreamChunkListCreate)();
  stream[4] = chunkList;
  chunkList = ((int (*)())_LFSStreamChunkListCreate)();
  stream[5] = chunkList;
  return stream;
}

/* _LFSStreamFree @ 0xd1c3c (92 bytes) */
void _LFSStreamFree(stream)
  undefined4 *stream;
{
  ((void (*)())_LFSStreamChunkListFree)(*stream);
  ((void (*)())_LFSStreamChunkListFree)(stream[1]);
  ((void (*)())_LFSStreamChunkListFree)(stream[2]);
  ((void (*)())_LFSStreamChunkListFree)(stream[3]);
  ((void (*)())_LFSStreamChunkListFree)(stream[4]);
  ((void (*)())_LFSStreamChunkListFree)(stream[5]);
  _free(stream);
  return;
}

/* _LFSStreamAddConstantBinding @ 0xd1c98 (104 bytes) */
void _LFSStreamAddConstantBinding(stream, binding)
  undefined4 *stream;
  undefined4 *binding;
{
  undefined4 constantIndex;
  undefined1 *chunk;
  undefined4 envParameterIndex;
  undefined4 inlineConstantIndex;
  
  chunk = (undefined1 *)_LFSStreamChunkCreate();
  *chunk = 3;
  constantIndex = binding[1];
  envParameterIndex = binding[2];
  inlineConstantIndex = binding[3];
  *(undefined4 *)(chunk + 4) = *binding;
  *(undefined4 *)(chunk + 8) = constantIndex;
  *(undefined4 *)(chunk + 0xc) = envParameterIndex;
  *(undefined4 *)(chunk + 0x10) = inlineConstantIndex;
  *(undefined4 *)(chunk + 0x14) = binding[4];
  ((void (*)())_LFSStreamChunkListAddChunk)(*stream,chunk);
  return;
}

/* _LFSStreamAddPreliminaryPassRegisterInit @ 0xd1d00 (104 bytes) */
void _LFSStreamAddPreliminaryPassRegisterInit(stream, registerInit)
  int stream;
  undefined4 *registerInit;
{
  undefined4 initWord1;
  undefined1 *chunk;
  undefined4 initWord2;
  undefined4 initWord3;
  
  chunk = (undefined1 *)_LFSStreamChunkCreate();
  *chunk = 1;
  initWord1 = registerInit[1];
  initWord2 = registerInit[2];
  initWord3 = registerInit[3];
  *(undefined4 *)(chunk + 4) = *registerInit;
  *(undefined4 *)(chunk + 8) = initWord1;
  *(undefined4 *)(chunk + 0xc) = initWord2;
  *(undefined4 *)(chunk + 0x10) = initWord3;
  *(undefined4 *)(chunk + 0x14) = registerInit[4];
  ((void (*)())_LFSStreamChunkListAddChunk)(*(undefined4 *)(stream + 4),chunk);
  return;
}

/* _LFSStreamAddPreliminaryPassOperation @ 0xd1d68 (84 bytes) */
void _LFSStreamAddPreliminaryPassOperation(stream, operation)
  int stream;
  undefined4 operation;
{
  undefined1 *chunk;
  
  chunk = (undefined1 *)_LFSStreamChunkCreate();
  *chunk = 2;
  _memcpy(chunk + 4,operation,0x44);
  ((void (*)())_LFSStreamChunkListAddChunk)(*(undefined4 *)(stream + 8),chunk);
  return;
}

/* _LFSStreamAddOutputPassRegisterInit @ 0xd1dbc (104 bytes) */
void _LFSStreamAddOutputPassRegisterInit(stream, registerInit)
  int stream;
  undefined4 *registerInit;
{
  undefined4 registerInitWord1;
  undefined1 *chunk;
  undefined4 registerInitWord2;
  undefined4 registerInitWord3;
  
  chunk = (undefined1 *)_LFSStreamChunkCreate();
  *chunk = 1;
  registerInitWord1 = registerInit[1];
  registerInitWord2 = registerInit[2];
  registerInitWord3 = registerInit[3];
  *(undefined4 *)(chunk + 4) = *registerInit;
  *(undefined4 *)(chunk + 8) = registerInitWord1;
  *(undefined4 *)(chunk + 0xc) = registerInitWord2;
  *(undefined4 *)(chunk + 0x10) = registerInitWord3;
  *(undefined4 *)(chunk + 0x14) = registerInit[4];
  ((void (*)())_LFSStreamChunkListAddChunk)(*(undefined4 *)(stream + 0xc),chunk);
  return;
}

/* _LFSStreamAddOutputPassOperation @ 0xd1e24 (84 bytes) */
void _LFSStreamAddOutputPassOperation(stream, operation)
  int stream;
  undefined4 operation;
{
  undefined1 *chunk;
  
  chunk = (undefined1 *)_LFSStreamChunkCreate();
  *chunk = 2;
  _memcpy(chunk + 4,operation,0x44);
  ((void (*)())_LFSStreamChunkListAddChunk)(*(undefined4 *)(stream + 0x10),chunk);
  return;
}

/* _LFSStreamAddConstant @ 0xd1e78 (84 bytes) */
void _LFSStreamAddConstant(stream, constantValues)
  int stream;
  undefined4 constantValues;
{
  undefined1 *chunk;
  
  chunk = (undefined1 *)_LFSStreamChunkCreate();
  *chunk = 4;
  _memmove(chunk + 4,constantValues,0x10);
  ((void (*)())_LFSStreamChunkListAddChunk)(*(undefined4 *)(stream + 0x14),chunk);
  return;
}

/* _LFSStreamGetStream @ 0xd1ecc (628 bytes) */
void _LFSStreamGetStream(chunkLists, streamOut, sizeOut)
  int *chunkLists;
  uint *streamOut;
  int *sizeOut;
{
  uint *paddingCursor;
  int totalWords;
  uint wordOffset;
  uint lastListOffset;
  int listWords [7];
  
  ((void (*)())_LFSStreamChunkListGetStream)(*chunkLists,0,listWords,chunkLists);
  totalWords = listWords[0];
  ((void (*)())_LFSStreamChunkListGetStream)(chunkLists[1],0,listWords,chunkLists);
  totalWords = totalWords + listWords[0];
  ((void (*)())_LFSStreamChunkListGetStream)(chunkLists[2],0,listWords,chunkLists);
  totalWords = totalWords + listWords[0];
  ((void (*)())_LFSStreamChunkListGetStream)(chunkLists[3],0,listWords,chunkLists);
  totalWords = totalWords + listWords[0];
  ((void (*)())_LFSStreamChunkListGetStream)(chunkLists[4],0,listWords,chunkLists);
  totalWords = totalWords + listWords[0];
  ((void (*)())_LFSStreamChunkListGetStream)(chunkLists[5],0,listWords,chunkLists);
  totalWords = totalWords + listWords[0];
  *sizeOut = (totalWords - (totalWords + 6U & 3)) + 10;
  if (streamOut != (uint *)0x0) {
    *streamOut = *(int *)(*chunkLists + 8) << 0x10 | 0x10000006;
    ((void (*)())_LFSStreamChunkListGetStream)(*chunkLists,streamOut + 6,listWords,chunkLists);
    wordOffset = listWords[0] + 6;
    streamOut[1] = *(int *)(chunkLists[1] + 8) << 0x10 | wordOffset | 0x10000000;
    ((void (*)())_LFSStreamChunkListGetStream)(chunkLists[1],streamOut + wordOffset,listWords,chunkLists);
    wordOffset = wordOffset + listWords[0];
    streamOut[2] = *(int *)(chunkLists[2] + 8) << 0x10 | wordOffset | 0x10000000;
    ((void (*)())_LFSStreamChunkListGetStream)(chunkLists[2],streamOut + wordOffset,listWords,chunkLists);
    wordOffset = wordOffset + listWords[0];
    streamOut[3] = *(int *)(chunkLists[3] + 8) << 0x10 | wordOffset | 0x10000000;
    ((void (*)())_LFSStreamChunkListGetStream)(chunkLists[3],streamOut + wordOffset,listWords,chunkLists);
    wordOffset = wordOffset + listWords[0];
    streamOut[4] = *(int *)(chunkLists[4] + 8) << 0x10 | wordOffset | 0x10000000;
    ((void (*)())_LFSStreamChunkListGetStream)(chunkLists[4],streamOut + wordOffset,listWords,chunkLists);
    lastListOffset = wordOffset + listWords[0] + 1;
    streamOut[wordOffset + listWords[0]] = 0;
    if ((lastListOffset & 3) != 0) {
      paddingCursor = streamOut + lastListOffset;
      do {
        lastListOffset = lastListOffset + 1;
        *paddingCursor = 0x50000000;
        paddingCursor = paddingCursor + 1;
      } while ((lastListOffset & 3) != 0);
    }
    streamOut[5] = *(int *)(chunkLists[5] + 8) << 0x10 | lastListOffset | 0x10000000;
    ((void (*)())_LFSStreamChunkListGetStream)(chunkLists[5],streamOut + lastListOffset,listWords,chunkLists);
  }
  return;
}

/* _LFSStreamCompare @ 0xd2148 (164 bytes) */
int _LFSStreamCompare(streamA, streamB)
  int streamA;
  int streamB;
{
  int listCompareResult;
  bool streamsDiffer;
  
  listCompareResult = ((int (*)())_LFSStreamChunkListCompare)(*(undefined4 *)(streamA + 4),*(undefined4 *)(streamB + 4));
  streamsDiffer = true;
  if (listCompareResult == 0) {
    listCompareResult = ((int (*)())_LFSStreamChunkListCompare)(*(undefined4 *)(streamA + 8),*(undefined4 *)(streamB + 8));
    streamsDiffer = true;
    if (listCompareResult == 0) {
      listCompareResult = ((int (*)())_LFSStreamChunkListCompare)(*(undefined4 *)(streamA + 0xc),*(undefined4 *)(streamB + 0xc));
      streamsDiffer = true;
      if (listCompareResult == 0) {
        listCompareResult = ((int (*)())_LFSStreamChunkListCompare)(*(undefined4 *)(streamA + 0x10),*(undefined4 *)(streamB + 0x10));
        streamsDiffer = true;
        if (listCompareResult == 0) {
          listCompareResult = ((int (*)())_LFSStreamChunkListCompare)(*(undefined4 *)(streamA + 0x14),*(undefined4 *)(streamB + 0x14));
          streamsDiffer = listCompareResult != 0;
        }
      }
    }
  }
  return streamsDiffer;
}

/* _LFSStreamOutputDebugInfo @ 0xd21ec (164 bytes) */
void _LFSStreamOutputDebugInfo(stream)
  undefined4 *stream;
{
  _puts("LFSStream {");
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(*stream);
  _puts("   preliminarypass {");
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(stream[1]);
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(stream[2]);
  _puts("   };");
  _puts("   outputpass {");
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(stream[3]);
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(stream[4]);
  _puts("   };");
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(stream[5]);
  _puts("};");
  return;
}

/* _gleFPChanged @ 0xd2290 (76 bytes) */
void _gleFPChanged(glContext)
  int glContext;
{
  undefined *setClipInterpFunc;
  
  _gleSelectVertexSubmitFunc(glContext);
  setClipInterpFunc = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(glContext + 0x49cc) = setClipInterpFunc;
  return;
}

/* _gleFPEnable @ 0xd22dc (64 bytes) */
void _gleFPEnable(glContext)
  int glContext;
{
  ((void (*)())_gleFPChanged)(glContext);
  _gleSelectVertexSubmitFunc(glContext);
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x1000000;
  return;
}

/* _gleFPDisable @ 0xd231c (64 bytes) */
void _gleFPDisable(glContext)
  int glContext;
{
  ((void (*)())_gleFPChanged)(glContext);
  _gleSelectVertexSubmitFunc(glContext);
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x1000000;
  return;
}

/* _zeroTargetExtractor @ 0xd235c (8 bytes) */
int _zeroTargetExtractor()
{
  return 0;
}

/* _gleGetHashMachineObjectNameTargetPairs @ 0xd2364 (400 bytes) */
void _gleGetHashMachineObjectNameTargetPairs(glContext, hashBuckets, objectType, valuePtr)
  int glContext;
  int *hashBuckets;
  int objectType;
  int *valuePtr;
{
  undefined *zeroTargetExtractor;
  int *bucketSlotThenEntry;
  int *resultArray;
  undefined4 objectTarget;
  int a2;
  int *a3;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int *nextBucket;
  int a6;
  code *targetExtractor;
  int entryCount;
  int pairWordIndex;
  
  zeroTargetExtractor = PTR__zeroTargetExtractor_00110e30;
  entryCount = 0;
  a2 = objectType;
  a3 = valuePtr;
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
  }
  bucketSlotThenEntry = hashBuckets;
  do {
    nextBucket = bucketSlotThenEntry + 1;
    for (bucketSlotThenEntry = (int *)*bucketSlotThenEntry; bucketSlotThenEntry != (int *)0x0; bucketSlotThenEntry = (int *)*bucketSlotThenEntry) {
      entryCount = entryCount + 1;
    }
    bucketSlotThenEntry = nextBucket;
  } while (nextBucket <= hashBuckets + 0x3ff);
  if (entryCount == 0) {
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    *valuePtr = 0;
  }
  else {
    resultArray = (int *)_malloc(entryCount * 8 + 4);
    *resultArray = entryCount;
    *valuePtr = (int)resultArray;
    targetExtractor = (code *)PTR__gleTextureTargetExtractor_0011215c;
    if ((objectType != 2) &&
       (targetExtractor = (code *)PTR__glePipelineProgramTargetExtactor_00112158, objectType != 4)) {
      targetExtractor = (code *)zeroTargetExtractor;
    }
    pairWordIndex = 0;
    bucketSlotThenEntry = hashBuckets;
    do {
      nextBucket = bucketSlotThenEntry + 1;
      for (bucketSlotThenEntry = (int *)*bucketSlotThenEntry; bucketSlotThenEntry != (int *)0x0; bucketSlotThenEntry = (int *)*bucketSlotThenEntry) {
        a6 = *valuePtr;
        *(int *)((pairWordIndex + 1) * 4 + a6) = bucketSlotThenEntry[1];
        pairWordIndex = pairWordIndex + 2;
        objectTarget = (*targetExtractor)(glContext,bucketSlotThenEntry,a2,a3,incomingR7,incomingR8,a6);
        *(undefined4 *)(pairWordIndex * 4 + *valuePtr) = objectTarget;
      }
      bucketSlotThenEntry = nextBucket;
    } while (nextBucket <= hashBuckets + 0x3ff);
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
  }
  return;
}

/* _gleImagingTexFormatToInternal @ 0xd24f4 (560 bytes) */
int _gleImagingTexFormatToInternal(internalformat)
  uint internalformat;
{
  bool formatMatches;
  uint candidateFormat;
  
  if (internalformat < 0x805c) {
    if (0x8054 < internalformat) {
      return 0x1908;
    }
    if (0x803e < internalformat) {
      if (internalformat == 0x8049) {
        return 0x8049;
      }
      if (internalformat < 0x804a) {
        if (0x8042 < internalformat) {
          return 0x190a;
        }
        return 0x1909;
      }
      if (internalformat < 0x804e) {
        return 0x8049;
      }
      if (internalformat < 0x804f) {
        return 0;
      }
      return 0x1907;
    }
    if (0x803a < internalformat) {
      return 0x1906;
    }
    if (internalformat == 4) {
      return 0x1908;
    }
    if (internalformat < 5) {
      if (internalformat == 2) {
        return 0x190a;
      }
      if (internalformat < 3) {
        if (internalformat != 1) {
          return 0;
        }
        return 0x1909;
      }
      return 0x1907;
    }
    if (internalformat < 0x1906) {
      return 0;
    }
    if (internalformat < 0x190b) {
      return internalformat;
    }
    formatMatches = internalformat == 0x2a10;
  }
  else {
    if (internalformat == 0x8817) {
      return 0x8049;
    }
    if (internalformat < 0x8818) {
      if (internalformat == 0x84ed) {
        return 0x1907;
      }
      if (internalformat < 0x84ee) {
        if (internalformat == 0x84ea) {
          return 0x1909;
        }
        if (0x84ea < internalformat) {
          if (internalformat == 0x84eb) {
            return 0x190a;
          }
          if (internalformat != 0x84ec) {
            return 0;
          }
          return 0x8049;
        }
        candidateFormat = 0x84e9;
      }
      else {
        if (internalformat == 0x8814) {
          return 0x1908;
        }
        if (internalformat < 0x8815) {
          if (internalformat == 0x84ee) {
            return 0x1908;
          }
          return 0;
        }
        if (internalformat == 0x8815) {
          return 0x1907;
        }
        candidateFormat = 0x8816;
      }
      if (internalformat == candidateFormat) {
        return 0x1906;
      }
      return 0;
    }
    if (internalformat == 0x881c) {
      return 0x1906;
    }
    if (0x881c < internalformat) {
      if (internalformat == 0x881e) {
        return 0x1909;
      }
      if (0x881d < internalformat) {
        if ((internalformat != 0x881f) && (internalformat != 0x8837)) {
          return 0;
        }
        return 0x190a;
      }
      return 0x8049;
    }
    if (internalformat == 0x8819) {
      return 0x190a;
    }
    if (internalformat < 0x8819) {
      return 0x1909;
    }
    if (internalformat == 0x881a) {
      return 0x1908;
    }
    formatMatches = internalformat == 0x881b;
  }
  if (formatMatches) {
    return 0x1907;
  }
  return 0;
}

/* _gleImagingUnpackData @ 0xd2724 (316 bytes) */
void _gleImagingUnpackData(glContext, width, height, format, sourceType, internalformat, type, image, filterData)
  int glContext;
  int width;
  undefined4 height;
  undefined4 format;
  undefined4 sourceType;
  undefined4 internalformat;
  undefined4 type;
  int image;
  undefined4 filterData;
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int unpackStore;
  undefined1 *puVar5;
  int *piVar6;
  int local_c0;
  undefined4 local_bc;
  undefined1 auStack_b8 [4];
  undefined1 auStack_b4 [4];
  undefined4 local_b0;
  int local_ac;
  undefined1 auStack_a8 [4];
  undefined1 auStack_a4 [4];
  undefined4 local_a0;
  uint local_9c;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  undefined1 local_54;
  undefined4 local_50;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  int local_3c [6];
  
  unpackStore = glContext + 0x31cc;
  puVar5 = auStack_40;
  piVar6 = local_3c;
  uVar3 = height;
  _glePixelPackSettings
            (glContext,internalformat,type,width,height,unpackStore,puVar5,piVar6,&local_50,auStack_4c,
             auStack_48,auStack_44);
  _glgConvertType(format,sourceType,auStack_b8,auStack_b4,uVar3,unpackStore,puVar5,piVar6);
  puVar1 = auStack_a8;
  puVar2 = auStack_a4;
  _glgConvertType(internalformat,type,puVar1,puVar2,uVar3,unpackStore,puVar5,piVar6);
  local_c0 = image + local_3c[0];
  local_98 = 5;
  local_bc = local_50;
  local_a0 = 2;
  local_b0 = filterData;
  local_9c = 0;
  local_94 = width;
  local_90 = height;
  local_ac = _glePixelBytes(internalformat,type);
  local_ac = width * local_ac;
  local_54 = 0;
  if (*(char *)(glContext + 0x31e4) != '\0') {
    local_9c = local_9c | 1;
  }
  if (*(char *)(glContext + 0x31e5) != '\0') {
    local_9c = local_9c | 4;
  }
  _glgProcessPixels(glContext + 0x31a8,&local_c0,puVar1,puVar2,uVar3,unpackStore,puVar5,piVar6);
  return;
}

/* _gleImagingPackData @ 0xd2860 (312 bytes) */
void _gleImagingPackData(glContext, rowWidth, height, format, type, dstFormat, dstType, filterData, dest)
  int glContext;
  int rowWidth;
  undefined4 height;
  undefined4 format;
  undefined4 type;
  undefined4 dstFormat;
  undefined4 dstType;
  undefined4 filterData;
  int dest;
{
  undefined1 *dstConvertAPtr;
  undefined1 *dstConvertBPtr;
  undefined4 heightArg;
  int packState;
  undefined1 *pixelBytesOutPtr;
  int *packOffsets;
  undefined4 procSrcAddress;
  int procSrcRowBytes;
  undefined1 procSrcConvertA [4];
  undefined1 procSrcConvertB [4];
  int procDstAddress;
  undefined4 procDstRowBytes;
  undefined1 procDstConvertA [4];
  undefined1 procDstConvertB [4];
  undefined4 procMode;
  uint procFlags;
  undefined4 procMask;
  int procWidth;
  undefined4 procHeight;
  undefined1 procEnd;
  undefined4 packRowBytes;
  undefined1 rowPaddingOut [4];
  undefined1 imageBytesOut [4];
  undefined1 imagePaddingOut [4];
  undefined1 pixelBytesOut [4];
  int packOffsetStorage [6];
  
  packState = glContext + 0x31b0;
  pixelBytesOutPtr = pixelBytesOut;
  packOffsets = packOffsetStorage;
  heightArg = height;
  _glePixelPackSettings
            (glContext,format,type,rowWidth,height,packState,pixelBytesOutPtr,packOffsets,&packRowBytes,rowPaddingOut,
             imageBytesOut,imagePaddingOut);
  _glgConvertType(format,type,procSrcConvertA,procSrcConvertB,heightArg,packState,pixelBytesOutPtr,packOffsets);
  dstConvertAPtr = procDstConvertA;
  dstConvertBPtr = procDstConvertB;
  _glgConvertType(dstFormat,dstType,dstConvertAPtr,dstConvertBPtr,heightArg,packState,pixelBytesOutPtr,packOffsets);
  procSrcAddress = filterData;
  procSrcRowBytes = _glePixelBytes(format,type);
  procSrcRowBytes = rowWidth * procSrcRowBytes;
  procDstAddress = dest + packOffsetStorage[0];
  procMask = 5;
  procMode = 2;
  procDstRowBytes = packRowBytes;
  procEnd = 0;
  procFlags = (uint)(*(char *)(glContext + 0x31c8) != '\0');
  if (*(char *)(glContext + 0x31c9) != '\0') {
    procFlags = procFlags | 4;
  }
  procWidth = rowWidth;
  procHeight = height;
  _glgProcessPixels(glContext + 0x31a8,&procSrcAddress,dstConvertAPtr,dstConvertBPtr,heightArg,packState,0,packOffsets);
  return;
}

/* _gleImagingScaleAndBias @ 0xd2998 (936 bytes) */
void _gleImagingScaleAndBias(unusedArg1, scaleBias, pixels, format, startPixel, pixelCount, clamp)
  undefined4 unusedArg1;
  float *scaleBias;
  int pixels;
  undefined4 format;
  int startPixel;
  int pixelCount;
  int clamp;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int componentCount;
  int pixelIndex;
  float *pixelPtr;
  
  if (((((*scaleBias != FLOAT_00108e54) || (scaleBias[2] != FLOAT_00108e54)) ||
       (scaleBias[4] != FLOAT_00108e54)) ||
      ((scaleBias[6] != FLOAT_00108e54 || (scaleBias[1] != FLOAT_00108e50)))) ||
     ((scaleBias[3] != FLOAT_00108e50 ||
      ((scaleBias[5] != FLOAT_00108e50 || (scaleBias[7] != FLOAT_00108e50)))))) {
    componentCount = _gleComponents(format);
    pixelIndex = 0;
    pixelPtr = (float *)(pixels + startPixel * componentCount * 4);
    if (0 < pixelCount) {
      do {
        switch(format) {
        case 0x1906:
          fVar1 = *pixelPtr * scaleBias[6] + scaleBias[7];
          if ((clamp != 0) &&
             ((fVar2 = FLOAT_00108e50, !(FLOAT_00108e50 < fVar1) ||
              (fVar2 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)))) {
            fVar1 = fVar2;
          }
          *pixelPtr = fVar1;
          break;
        case 0x1907:
          fVar1 = *pixelPtr * *scaleBias + scaleBias[1];
          fVar2 = pixelPtr[1] * scaleBias[2] + scaleBias[3];
          fVar3 = pixelPtr[2] * scaleBias[4] + scaleBias[5];
          if (clamp != 0) {
            fVar5 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar1)) || (fVar5 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)) {
              fVar1 = fVar5;
            }
            fVar5 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar2)) || (fVar5 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
              fVar2 = fVar5;
            }
            fVar5 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar3)) || (fVar5 = FLOAT_00108e54, FLOAT_00108e54 < fVar3)) {
              fVar3 = fVar5;
            }
          }
          *pixelPtr = fVar1;
          pixelPtr[1] = fVar2;
          pixelPtr = pixelPtr + 2;
          *pixelPtr = fVar3;
          break;
        case 0x1908:
          fVar1 = *pixelPtr * *scaleBias + scaleBias[1];
          fVar3 = pixelPtr[1] * scaleBias[2] + scaleBias[3];
          fVar5 = pixelPtr[2] * scaleBias[4] + scaleBias[5];
          fVar2 = pixelPtr[3] * scaleBias[6] + scaleBias[7];
          if (clamp != 0) {
            fVar4 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar1)) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)) {
              fVar1 = fVar4;
            }
            fVar4 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar3)) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar3)) {
              fVar3 = fVar4;
            }
            fVar4 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar5)) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar5)) {
              fVar5 = fVar4;
            }
            fVar4 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar2)) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
              fVar2 = fVar4;
            }
          }
          *pixelPtr = fVar1;
          pixelPtr[1] = fVar3;
          pixelPtr = pixelPtr + 2;
          *pixelPtr = fVar5;
          goto LAB_000d2d2c;
        case 0x1909:
          fVar1 = *pixelPtr * *scaleBias + scaleBias[1];
          if ((clamp != 0) &&
             ((fVar2 = FLOAT_00108e50, !(FLOAT_00108e50 < fVar1) ||
              (fVar2 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)))) {
            fVar1 = fVar2;
          }
          *pixelPtr = fVar1;
          break;
        case 0x190a:
          fVar1 = *pixelPtr * *scaleBias + scaleBias[1];
          fVar2 = pixelPtr[1] * scaleBias[6] + scaleBias[7];
          if (clamp != 0) {
            fVar3 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar1)) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)) {
              fVar1 = fVar3;
            }
            fVar3 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar2)) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
              fVar2 = fVar3;
            }
          }
          *pixelPtr = fVar1;
LAB_000d2d2c:
          pixelPtr = pixelPtr + 1;
          *pixelPtr = fVar2;
          break;
        default:
          goto switchD_000d2a7c_default;
        }
        pixelPtr = pixelPtr + 1;
switchD_000d2a7c_default:
        pixelIndex = pixelIndex + 1;
      } while (pixelIndex < pixelCount);
    }
  }
  return;
}

/* _gleGetHistogram @ 0xd2d54 (3104 bytes) */
void _gleGetHistogram(glContext, unusedArg2, reset, format, type, values)
  int glContext;
  undefined4 unusedArg2;
  int reset;
  uint format;
  uint type;
  int values;
{
  bool formatIsAbgr;
  bool formatIsBgr;
  bool formatIsBgra;
  bool formatIsRed;
  bool formatIsNotGreen;
  bool formatIsAlpha;
  bool formatIsRgb;
  bool swapBytes;
  bool formatIsRgba;
  bool formatIsLuminance;
  bool formatIsBlue;
  bool formatIsLuminanceAlpha;
  bool formatAboveRgba;
  bool formatAboveBlue;
  bool formatAboveAbgr;
  double uintToDoubleBias;
  undefined1 outByte;
  ushort outShort;
  int binIndex;
  int binsRemaining;
  int packAlignment;
  int pixelBytes;
  int binByteOffset;
  float componentTemp1;
  float componentTemp2;
  float componentTemp3;
  float componentTemp4;
  float *resetCursor;
  float *dstCursor;
  int binCountThenRemaining;
  float *histogramTable;
  float *binCursor;
  undefined4 binWord0;
  undefined4 binWord1;
  undefined4 binWord2;
  undefined4 binWord3;
  
  histogramTable = *(float **)(glContext + 0x3384);
  binCountThenRemaining = *(int *)(glContext + 0x3388);
  pixelBytes = _glePixelBytes(format,type);
  uintToDoubleBias = DOUBLE_00108d58;
  packAlignment = *(int *)(glContext + 0x31c4);
  dstCursor = (float *)(values + pixelBytes * *(int *)(glContext + 0x31bc));
  if (packAlignment == 4) {
    if (((uint)dstCursor & 3) != 0) {
      dstCursor = (float *)((uint)(dstCursor + 1) & 0xfffffffc);
    }
  }
  else if (packAlignment < 5) {
    if ((packAlignment == 2) && (((uint)dstCursor & 1) != 0)) {
      dstCursor = (float *)((int)dstCursor + 1);
    }
  }
  else if ((packAlignment == 8) && (((uint)dstCursor & 7) != 0)) {
    dstCursor = (float *)((uint)(dstCursor + 2) & 0xfffffff8);
  }
  if (0 < binCountThenRemaining) {
    formatAboveBlue = 0x1905 < format;
    formatIsAbgr = format == 0x8000;
    formatIsRed = format == 0x1903;
    formatIsNotGreen = format != 0x1904;
    formatIsBgr = format == 0x80e0;
    formatIsBgra = format == 0x80e1;
    formatIsAlpha = format == 0x1906;
    formatIsRgb = format == 0x1907;
    swapBytes = *(char *)(glContext + 0x31c8) != '\0';
    formatAboveAbgr = 0x8000 < format;
    formatIsRgba = format == 0x1908;
    formatIsLuminance = format == 0x1909;
    formatAboveRgba = 0x1908 < format;
    formatIsBlue = format == 0x1905;
    formatIsLuminanceAlpha = format == 0x190a;
    binCursor = histogramTable;
    binsRemaining = binCountThenRemaining;
    do {
      if (type == 0x1406) {
        componentTemp1 = (float)((double)CONCAT44(0x43300000,-*binCursor) - uintToDoubleBias);
        componentTemp2 = (float)((double)CONCAT44(0x43300000,-binCursor[1]) - uintToDoubleBias);
        componentTemp3 = (float)((double)CONCAT44(0x43300000,-binCursor[2]) - uintToDoubleBias);
        componentTemp4 = (float)((double)CONCAT44(0x43300000,-binCursor[3]) - uintToDoubleBias);
        if (swapBytes) {
          componentTemp1 = GH_U2F((unsigned int)(((uint)GH_F2U(componentTemp1) >> 0x18 | (uint)GH_F2U(componentTemp1) >> 8 & 0xff00 |
                           ((uint)GH_F2U(componentTemp1) & 0xff00) << 8 | (int)GH_F2U(componentTemp1) << 0x18)));
          componentTemp2 = GH_U2F((unsigned int)(((uint)GH_F2U(componentTemp2) >> 0x18 | (uint)GH_F2U(componentTemp2) >> 8 & 0xff00 |
                           ((uint)GH_F2U(componentTemp2) & 0xff00) << 8 | (int)GH_F2U(componentTemp2) << 0x18)));
          componentTemp3 = GH_U2F((unsigned int)(((uint)GH_F2U(componentTemp3) >> 0x18 | (uint)GH_F2U(componentTemp3) >> 8 & 0xff00 |
                           ((uint)GH_F2U(componentTemp3) & 0xff00) << 8 | (int)GH_F2U(componentTemp3) << 0x18)));
          componentTemp4 = GH_U2F((unsigned int)(((uint)GH_F2U(componentTemp4) >> 0x18 | (uint)GH_F2U(componentTemp4) >> 8 & 0xff00 |
                           ((uint)GH_F2U(componentTemp4) & 0xff00) << 8 | (int)GH_F2U(componentTemp4) << 0x18)));
        }
        if (formatIsRgba) {
          *dstCursor = componentTemp1;
          dstCursor[1] = componentTemp2;
          dstCursor = dstCursor + 2;
          *dstCursor = componentTemp3;
          goto LAB_000d372c;
        }
        if (formatAboveRgba) {
          if (!formatIsAbgr) {
            if (formatAboveAbgr) {
              if (formatIsBgr) {
                *dstCursor = componentTemp3;
                goto LAB_000d3714;
              }
              if (formatIsBgra) {
                *dstCursor = componentTemp3;
                dstCursor[1] = componentTemp2;
                dstCursor = dstCursor + 2;
                *dstCursor = componentTemp1;
                goto LAB_000d372c;
              }
            }
            else {
              if (formatIsLuminance) goto LAB_000d3720;
              if (formatIsLuminanceAlpha) {
                *dstCursor = componentTemp1;
LAB_000d372c:
                dstCursor = dstCursor + 1;
                *dstCursor = componentTemp4;
                goto LAB_000d3730;
              }
            }
            goto LAB_000d3734;
          }
          *dstCursor = componentTemp4;
          dstCursor = dstCursor + 1;
          *dstCursor = componentTemp3;
LAB_000d3714:
          dstCursor[1] = componentTemp2;
          dstCursor = dstCursor + 2;
          *dstCursor = componentTemp1;
        }
        else if (formatIsBlue) {
          *dstCursor = componentTemp3;
        }
        else if (formatAboveBlue) {
          if (formatIsAlpha) {
            *dstCursor = componentTemp4;
          }
          else {
            if (!formatIsRgb) goto LAB_000d3734;
            *dstCursor = componentTemp1;
            dstCursor[1] = componentTemp2;
            dstCursor = dstCursor + 2;
            *dstCursor = componentTemp3;
          }
        }
        else if (formatIsRed) {
LAB_000d3720:
          *dstCursor = componentTemp1;
        }
        else {
          if (formatIsNotGreen) goto LAB_000d3734;
          *dstCursor = componentTemp2;
        }
LAB_000d3730:
        dstCursor = dstCursor + 1;
        goto LAB_000d3734;
      }
      if (0x1406 < type) goto LAB_000d3734;
      if (type != 0x1402) {
        if (type < 0x1403) {
          if (type == 0x1400) {
            if (formatIsRgba) {
LAB_000d3048:
              *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 3);
              *(undefined1 *)((int)dstCursor + 1) = *(undefined1 *)((int)binCursor + 7);
              outByte = *(undefined1 *)((int)binCursor + 0xb);
LAB_000d3074:
              dstCursor = (float *)((int)dstCursor + 2);
              *(undefined1 *)dstCursor = outByte;
LAB_000d30ac:
              outByte = *(undefined1 *)((int)binCursor + 0xf);
            }
            else {
              if (!formatAboveRgba) {
                if (!formatIsBlue) goto LAB_000d2f78;
LAB_000d3020:
                outByte = *(undefined1 *)((int)binCursor + 0xb);
                goto LAB_000d2f38;
              }
LAB_000d2fc4:
              if (!formatIsAbgr) {
                if (formatAboveAbgr) {
                  if (formatIsBgr) {
                    *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 0xb);
                    *(undefined1 *)((int)dstCursor + 1) = *(undefined1 *)((int)binCursor + 7);
                    outByte = *(undefined1 *)((int)binCursor + 3);
LAB_000d2f54:
                    dstCursor = (float *)((int)dstCursor + 2);
                    *(undefined1 *)dstCursor = outByte;
                    goto LAB_000d30b4;
                  }
                  if (!formatIsBgra) goto LAB_000d3734;
                  *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 0xb);
                  *(undefined1 *)((int)dstCursor + 1) = *(undefined1 *)((int)binCursor + 7);
                  outByte = *(undefined1 *)((int)binCursor + 3);
                  goto LAB_000d3074;
                }
                if (formatIsLuminance) {
LAB_000d309c:
                  outByte = *(undefined1 *)((int)binCursor + 3);
                  goto LAB_000d2f38;
                }
                if (!formatIsLuminanceAlpha) goto LAB_000d3734;
                *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 3);
                goto LAB_000d30ac;
              }
              *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 0xf);
              *(undefined1 *)((int)dstCursor + 1) = *(undefined1 *)((int)binCursor + 0xb);
              dstCursor = (float *)((int)dstCursor + 2);
              *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 7);
              outByte = *(undefined1 *)((int)binCursor + 3);
            }
            dstCursor = (float *)((int)dstCursor + 1);
            *(undefined1 *)dstCursor = outByte;
          }
          else {
            if (type != 0x1401) goto LAB_000d3734;
            if (formatIsRgba) goto LAB_000d3048;
            if (formatAboveRgba) goto LAB_000d2fc4;
            if (formatIsBlue) goto LAB_000d3020;
LAB_000d2f78:
            if (formatAboveBlue) {
              if (!formatIsAlpha) {
                if (!formatIsRgb) goto LAB_000d3734;
                *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 3);
                *(undefined1 *)((int)dstCursor + 1) = *(undefined1 *)((int)binCursor + 7);
                outByte = *(undefined1 *)((int)binCursor + 0xb);
                goto LAB_000d2f54;
              }
              outByte = *(undefined1 *)((int)binCursor + 0xf);
            }
            else {
              if (formatIsRed) goto LAB_000d309c;
              if (formatIsNotGreen) goto LAB_000d3734;
              outByte = *(undefined1 *)((int)binCursor + 7);
            }
LAB_000d2f38:
            *(undefined1 *)dstCursor = outByte;
          }
LAB_000d30b4:
          dstCursor = (float *)((int)dstCursor + 1);
          goto LAB_000d3734;
        }
        if ((type == 0x1404) || (0x1404 < type)) {
          binWord0 = GH_F2U(*binCursor);
          binWord1 = GH_F2U(binCursor[1]);
          binWord2 = GH_F2U(binCursor[2]);
          binWord3 = GH_F2U(binCursor[3]);
          if (swapBytes) {
            componentTemp4 = *binCursor;
            componentTemp3 = binCursor[1];
            componentTemp2 = binCursor[2];
            componentTemp1 = binCursor[3];
            binWord0 = ((unsigned int)(((int)GH_F2U(componentTemp4) >> 0x18 | (uint)GH_F2U(componentTemp4) >> 8 & 0xff00 |
                               ((uint)GH_F2U(componentTemp4) & 0xff00) << 8 | (int)GH_F2U(componentTemp4) << 0x18)));
            binWord1 = ((unsigned int)(((int)GH_F2U(componentTemp3) >> 0x18 | (uint)GH_F2U(componentTemp3) >> 8 & 0xff00 |
                               ((uint)GH_F2U(componentTemp3) & 0xff00) << 8 | (int)GH_F2U(componentTemp3) << 0x18)));
            binWord2 = ((unsigned int)(((int)GH_F2U(componentTemp2) >> 0x18 | (uint)GH_F2U(componentTemp2) >> 8 & 0xff00 |
                               ((uint)GH_F2U(componentTemp2) & 0xff00) << 8 | (int)GH_F2U(componentTemp2) << 0x18)));
            binWord3 = ((unsigned int)(((int)GH_F2U(componentTemp1) >> 0x18 | (uint)GH_F2U(componentTemp1) >> 8 & 0xff00 |
                               ((uint)GH_F2U(componentTemp1) & 0xff00) << 8 | (int)GH_F2U(componentTemp1) << 0x18)));
          }
          if (formatIsRgba) {
            *(unsigned int *)dstCursor = binWord0;
            ((unsigned int *)dstCursor)[1] = binWord1;
            binWord0 = binWord2;
LAB_000d32f4:
            dstCursor = dstCursor + 2;
            *(unsigned int *)dstCursor = binWord0;
            binWord0 = binWord3;
          }
          else {
            if (!formatAboveRgba) {
              componentTemp1 = GH_U2F(binWord2);
              if (!formatIsBlue) {
                if (formatAboveBlue) {
                  componentTemp1 = GH_U2F(binWord3);
                  if (formatIsAlpha) goto LAB_000d32bc;
                  if (formatIsRgb) {
                    *(unsigned int *)dstCursor = binWord0;
                    ((unsigned int *)dstCursor)[1] = binWord1;
                    goto LAB_000d32d8;
                  }
                }
                else {
                  componentTemp1 = GH_U2F(binWord0);
                  if ((formatIsRed) || (componentTemp1 = GH_U2F(binWord1), !formatIsNotGreen)) goto LAB_000d32bc;
                }
                goto LAB_000d3734;
              }
LAB_000d32bc:
              *dstCursor = componentTemp1;
              goto LAB_000d3730;
            }
            if (!formatIsAbgr) {
              if (formatAboveAbgr) {
                if (formatIsBgr) {
                  *(unsigned int *)dstCursor = binWord2;
                  ((unsigned int *)dstCursor)[1] = binWord1;
                  binWord2 = binWord0;
LAB_000d32d8:
                  dstCursor = dstCursor + 2;
                  *(unsigned int *)dstCursor = binWord2;
                  goto LAB_000d3730;
                }
                if (formatIsBgra) {
                  *(unsigned int *)dstCursor = binWord2;
                  ((unsigned int *)dstCursor)[1] = binWord1;
                  goto LAB_000d32f4;
                }
              }
              else {
                componentTemp1 = GH_U2F(binWord0);
                if (formatIsLuminance) goto LAB_000d32bc;
                if (formatIsLuminanceAlpha) {
                  *(unsigned int *)dstCursor = binWord0;
                  binWord0 = binWord3;
                  goto LAB_000d32fc;
                }
              }
              goto LAB_000d3734;
            }
            *(unsigned int *)dstCursor = binWord3;
            ((unsigned int *)dstCursor)[1] = binWord2;
            dstCursor = dstCursor + 2;
            *(unsigned int *)dstCursor = binWord1;
          }
LAB_000d32fc:
          dstCursor = dstCursor + 1;
          *(unsigned int *)dstCursor = binWord0;
          goto LAB_000d3730;
        }
      }
      (*(unsigned short *)((unsigned char *)&(binWord0) + 2)) = SUB42(*binCursor,0);
      (*(unsigned short *)((unsigned char *)&(binWord1) + 2)) = SUB42(binCursor[1],0);
      (*(unsigned short *)((unsigned char *)&(binWord2) + 2)) = SUB42(binCursor[2],0);
      (*(unsigned short *)((unsigned char *)&(binWord3) + 2)) = SUB42(binCursor[3],0);
      if (swapBytes) {
        (*(unsigned short *)((unsigned char *)&(binWord0) + 2)) =
             (ushort)(((uint)GH_F2U(*binCursor) & 0xff) << 8) | (ushort)((uint)GH_F2U(*binCursor) >> 8) & 0xff;
        (*(unsigned short *)((unsigned char *)&(binWord1) + 2)) =
             (ushort)(((uint)GH_F2U(binCursor[1]) & 0xff) << 8) | (ushort)((uint)GH_F2U(binCursor[1]) >> 8) & 0xff;
        (*(unsigned short *)((unsigned char *)&(binWord2) + 2)) =
             (ushort)(((uint)GH_F2U(binCursor[2]) & 0xff) << 8) | (ushort)((uint)GH_F2U(binCursor[2]) >> 8) & 0xff;
        (*(unsigned short *)((unsigned char *)&(binWord3) + 2)) =
             (ushort)(((uint)GH_F2U(binCursor[3]) & 0xff) << 8) | (ushort)((uint)GH_F2U(binCursor[3]) >> 8) & 0xff;
      }
      if (formatIsRgba) {
        *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(binWord0) + 2));
        *(ushort *)((int)dstCursor + 2) = (*(unsigned short *)((unsigned char *)&(binWord1) + 2));
        (*(unsigned short *)((unsigned char *)&(binWord0) + 2)) = (*(unsigned short *)((unsigned char *)&(binWord2) + 2));
LAB_000d3270:
        dstCursor = dstCursor + 1;
        *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(binWord0) + 2));
        (*(unsigned short *)((unsigned char *)&(binWord0) + 2)) = (*(unsigned short *)((unsigned char *)&(binWord3) + 2));
LAB_000d32ac:
        dstCursor = (float *)((int)dstCursor + 2);
        *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(binWord0) + 2));
LAB_000d32b0:
        dstCursor = (float *)((int)dstCursor + 2);
      }
      else if (formatAboveRgba) {
        if (formatIsAbgr) {
          *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(binWord3) + 2));
          *(ushort *)((int)dstCursor + 2) = (*(unsigned short *)((unsigned char *)&(binWord2) + 2));
          dstCursor = dstCursor + 1;
          *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(binWord1) + 2));
          goto LAB_000d32ac;
        }
        if (formatAboveAbgr) {
          if (formatIsBgr) {
            *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(binWord2) + 2));
            *(ushort *)((int)dstCursor + 2) = (*(unsigned short *)((unsigned char *)&(binWord1) + 2));
            (*(unsigned short *)((unsigned char *)&(binWord2) + 2)) = (*(unsigned short *)((unsigned char *)&(binWord0) + 2));
LAB_000d30dc:
            dstCursor = dstCursor + 1;
            *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(binWord2) + 2));
            goto LAB_000d32b0;
          }
          if (formatIsBgra) {
            *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(binWord2) + 2));
            *(ushort *)((int)dstCursor + 2) = (*(unsigned short *)((unsigned char *)&(binWord1) + 2));
            goto LAB_000d3270;
          }
        }
        else {
          outShort = (*(unsigned short *)((unsigned char *)&(binWord0) + 2));
          if (formatIsLuminance) goto LAB_000d30c0;
          if (formatIsLuminanceAlpha) {
            *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(binWord0) + 2));
            (*(unsigned short *)((unsigned char *)&(binWord0) + 2)) = (*(unsigned short *)((unsigned char *)&(binWord3) + 2));
            goto LAB_000d32ac;
          }
        }
      }
      else {
        outShort = (*(unsigned short *)((unsigned char *)&(binWord2) + 2));
        if (formatIsBlue) {
LAB_000d30c0:
          *(ushort *)dstCursor = outShort;
          goto LAB_000d32b0;
        }
        if (formatAboveBlue) {
          outShort = (*(unsigned short *)((unsigned char *)&(binWord3) + 2));
          if (formatIsAlpha) goto LAB_000d30c0;
          if (formatIsRgb) {
            *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(binWord0) + 2));
            *(ushort *)((int)dstCursor + 2) = (*(unsigned short *)((unsigned char *)&(binWord1) + 2));
            goto LAB_000d30dc;
          }
        }
        else {
          outShort = (*(unsigned short *)((unsigned char *)&(binWord0) + 2));
          if ((formatIsRed) || (outShort = (*(unsigned short *)((unsigned char *)&(binWord1) + 2)), !formatIsNotGreen)) goto LAB_000d30c0;
        }
      }
LAB_000d3734:
      binCursor = binCursor + 4;
      binsRemaining = binsRemaining + -1;
    } while (binsRemaining != 0);
  }
  if ((reset != 0) && (binIndex = 0, 0 < binCountThenRemaining)) {
    resetCursor = histogramTable;
    do {
      if (format == 0x8032) goto LAB_000d3938;
      if (format < 0x8033) {
        if (format == 0x1906) {
LAB_000d3920:
          resetCursor[3] = 0.0;
        }
        else if (format < 0x1907) {
          if (format == 0x1904) {
            resetCursor[1] = 0.0;
          }
          else if (format < 0x1905) {
            if (format == 0x1903) {
LAB_000d3904:
              *resetCursor = 0.0;
            }
          }
          else {
            resetCursor[2] = 0.0;
          }
        }
        else {
          if (format == 0x1908) goto LAB_000d3928;
          if (format < 0x1908) goto LAB_000d3938;
          if (format == 0x1909) goto LAB_000d3904;
          if (format == 0x190a) {
            *resetCursor = 0.0;
            goto LAB_000d3920;
          }
        }
      }
      else {
        if (format == 0x80e1) {
LAB_000d3928:
          binByteOffset = binIndex * 0x10;
          histogramTable[binIndex * 4 + 3] = 0.0;
        }
        else {
          if (0x80e1 < format) {
            if (0x8361 < format) {
              if (format < 0x8365) goto LAB_000d3938;
              if (format < 0x8369) goto LAB_000d3928;
            }
            goto LAB_000d394c;
          }
          if (format < 0x8037) goto LAB_000d3928;
          if (format != 0x80e0) goto LAB_000d394c;
LAB_000d3938:
          binByteOffset = binIndex << 4;
        }
        *(undefined4 *)((int)histogramTable + binByteOffset) = 0;
        *(undefined4 *)((int)histogramTable + binByteOffset + 8) = 0;
        *(undefined4 *)((int)histogramTable + binByteOffset + 4) = 0;
      }
LAB_000d394c:
      binIndex = binIndex + 1;
      resetCursor = resetCursor + 4;
      binCountThenRemaining = binCountThenRemaining + -1;
    } while (binCountThenRemaining != 0);
  }
  return;
}

/* _gleGetMinmax @ 0xd3974 (628 bytes) */
void _gleGetMinmax(glContext, unusedArg2, reset, format, type, values)
  int glContext;
  undefined4 unusedArg2;
  int reset;
  uint format;
  undefined4 type;
  int values;
{
  float zeroValue;
  double intToDoubleBias;
  int pixelBytes;
  code *insertFunc;
  undefined4 *minmaxTable;
  undefined1 pixelRecordHeader [4];
  undefined4 pixelRed;
  undefined4 pixelGreen;
  undefined4 pixelBlue;
  undefined4 pixelAlpha;
  
  minmaxTable = *(undefined4 **)(glContext + 0x337c);
  pixelBytes = _glePixelBytes(format,type);
  insertFunc = (code *)_gleSelectPixelInsertFunc(format,type);
  pixelRed = *minmaxTable;
  pixelGreen = minmaxTable[1];
  pixelBlue = minmaxTable[2];
  pixelAlpha = minmaxTable[3];
  (*insertFunc)(pixelRecordHeader,values);
  pixelRed = minmaxTable[4];
  pixelGreen = minmaxTable[5];
  pixelBlue = minmaxTable[6];
  pixelAlpha = minmaxTable[7];
  (*insertFunc)(pixelRecordHeader,values + pixelBytes);
  if (reset == 0) {
    return;
  }
  if (format == 0x8032) goto LAB_000d3b98;
  if (format < 0x8033) {
    if (format == 0x1906) {
      minmaxTable[3] = 0x3f800000;
      minmaxTable[7] = 0;
      return;
    }
    if (format < 0x1907) {
      if (format == 0x1904) {
        minmaxTable[1] = 0x3f800000;
        minmaxTable[5] = 0;
        return;
      }
      if (0x1904 < format) {
        minmaxTable[2] = 0x3f800000;
        minmaxTable[6] = 0;
        return;
      }
      if (format != 0x1903) {
        return;
      }
LAB_000d3af4:
      *minmaxTable = 0x3f800000;
      minmaxTable[4] = (float)(4503601774854144.0 - DOUBLE_00108d58);
      return;
    }
    if (format != 0x1908) {
      if (format < 0x1908) goto LAB_000d3b98;
      if (format != 0x1909) {
        if (format != 0x190a) {
          return;
        }
        minmaxTable[3] = 0x3f800000;
        *minmaxTable = 0x3f800000;
        minmaxTable[7] = 0;
        minmaxTable[4] = 0;
        return;
      }
      goto LAB_000d3af4;
    }
  }
  else if (format != 0x80e1) {
    if (format < 0x80e2) {
      if (0x8036 < format) {
        if (format != 0x80e0) {
          return;
        }
        goto LAB_000d3b98;
      }
    }
    else {
      if (format < 0x8362) {
        return;
      }
      if (format < 0x8365) goto LAB_000d3b98;
      if (0x8368 < format) {
        return;
      }
    }
  }
  minmaxTable[3] = 0x3f800000;
  minmaxTable[7] = (float)(4503601774854144.0 - DOUBLE_00108d58);
LAB_000d3b98:
  *minmaxTable = 0x3f800000;
  intToDoubleBias = DOUBLE_00108d58;
  minmaxTable[2] = 0x3f800000;
  minmaxTable[1] = 0x3f800000;
  zeroValue = (float)(4503601774854144.0 - intToDoubleBias);
  minmaxTable[6] = zeroValue;
  minmaxTable[4] = zeroValue;
  minmaxTable[5] = zeroValue;
  return;
}

/* _gleConvolutionFilter1D @ 0xd3be8 (224 bytes) */
void _gleConvolutionFilter1D(glContext, unusedArg2, internalformat, width, format, type, image)
  int glContext;
  undefined4 unusedArg2;
  undefined4 internalformat;
  int width;
  undefined4 format;
  undefined4 type;
  undefined4 image;
{
  int bytesPerPixel;
  undefined4 filterData;
  
  if (*(int *)(glContext + 0x32cc) != 0) {
    _free(*(int *)(glContext + 0x32cc));
  }
  *(undefined4 *)(glContext + 0x32d4) = 1;
  *(int *)(glContext + 0x32d0) = width;
  if (width == 0) {
    *(undefined4 *)(glContext + 0x32cc) = 0;
    return;
  }
  bytesPerPixel = _glePixelBytes(internalformat,0x1406);
  filterData = _malloc(width * bytesPerPixel);
  *(undefined4 *)(glContext + 0x32cc) = filterData;
  *(short *)(glContext + 0x32ca) = (short)internalformat;
  ((void (*)())_gleImagingUnpackData)(glContext,width,1,format,type,internalformat,0x1406,image,filterData);
  ((void (*)())_gleImagingScaleAndBias)(glContext,glContext + 0x32a8,*(undefined4 *)(glContext + 0x32cc),
             (uint)*(ushort *)(glContext + 0x32ca),0,width,0);
  return;
}

/* _gleConvolutionFilter2D @ 0xd3cc8 (240 bytes) */
void _gleConvolutionFilter2D(glContext, unusedArg2, internalformat, width, height, format, type, image)
  int glContext;
  undefined4 unusedArg2;
  undefined4 internalformat;
  int width;
  int height;
  undefined4 format;
  undefined4 type;
  undefined4 image;
{
  int bytesPerPixel;
  undefined4 filterData;
  
  if (*(int *)(glContext + 0x330c) != 0) {
    _free(*(int *)(glContext + 0x330c));
  }
  *(int *)(glContext + 0x3310) = width;
  *(int *)(glContext + 0x3314) = height;
  if ((width != 0) && (height != 0)) {
    bytesPerPixel = _glePixelBytes(internalformat,0x1406);
    filterData = _malloc(width * height * bytesPerPixel);
    *(undefined4 *)(glContext + 0x330c) = filterData;
    *(short *)(glContext + 0x330a) = (short)internalformat;
    ((void (*)())_gleImagingUnpackData)(glContext,width,height,format,type,internalformat,0x1406,image,filterData);
    ((void (*)())_gleImagingScaleAndBias)(glContext,glContext + 0x32e8,*(undefined4 *)(glContext + 0x330c),
               (uint)*(ushort *)(glContext + 0x330a),0,width * height,0);
    return;
  }
  *(undefined4 *)(glContext + 0x330c) = 0;
  return;
}

/* _gleGetConvolutionFilter @ 0xd3db8 (100 bytes) */
void _gleGetConvolutionFilter(glContext, target, format, type, image)
  int glContext;
  int target;
  undefined4 format;
  undefined4 type;
  undefined4 image;
{
  int convolutionState;
  
  convolutionState = glContext + 0x3298;
  if (target != 0x8010) {
    convolutionState = glContext + 0x32d8;
  }
  if (*(int *)(convolutionState + 0x34) != 0) {
    ((void (*)())_gleImagingPackData)(glContext,*(undefined4 *)(convolutionState + 0x38),*(undefined4 *)(convolutionState + 0x3c),
                        (uint)*(ushort *)(convolutionState + 0x32),0x1406,format,type,
                        *(int *)(convolutionState + 0x34),image);
  }
  return;
}

/* _gleSeparableFilter2D @ 0xd3e1c (340 bytes) */
void _gleSeparableFilter2D(glContext, unusedArg2, internalformat, width, height, format, type, row, column)
  int glContext;
  undefined4 unusedArg2;
  undefined4 internalformat;
  int width;
  int height;
  undefined4 format;
  undefined4 type;
  undefined4 row;
  undefined4 column;
{
  int pixelBytesThenColumnFilterData;
  int filterData;
  
  pixelBytesThenColumnFilterData = _glePixelBytes(internalformat,0x1406);
  if (*(int *)(glContext + 0x334c) != 0) {
    _free(*(int *)(glContext + 0x334c));
  }
  *(int *)(glContext + 0x3350) = width;
  *(int *)(glContext + 0x3354) = height;
  if ((width != 0) && (height != 0)) {
    filterData = _malloc((width + height) * pixelBytesThenColumnFilterData);
    *(int *)(glContext + 0x334c) = filterData;
    *(short *)(glContext + 0x334a) = (short)internalformat;
    *(int *)(glContext + 0x3350) = width;
    *(int *)(glContext + 0x3354) = height;
    pixelBytesThenColumnFilterData = filterData + width * pixelBytesThenColumnFilterData;
    ((void (*)())_gleImagingUnpackData)(glContext,width,1,format,type,internalformat,0x1406,row,filterData);
    ((void (*)())_gleImagingUnpackData)(glContext,height,1,format,type,internalformat,0x1406,column,pixelBytesThenColumnFilterData);
    ((void (*)())_gleImagingScaleAndBias)(glContext,glContext + 0x3328,*(undefined4 *)(glContext + 0x334c),
               (uint)*(ushort *)(glContext + 0x334a),0,width,0);
    ((void (*)())_gleImagingScaleAndBias)(glContext,glContext + 0x3328,pixelBytesThenColumnFilterData,(uint)*(ushort *)(glContext + 0x334a),0,height,0);
    return;
  }
  *(undefined4 *)(glContext + 0x334c) = 0;
  return;
}

/* _gleGetSeparableFilter @ 0xd3f70 (164 bytes) */
void _gleGetSeparableFilter(glContext, unusedArg2, format, type, row, column)
  int glContext;
  undefined4 unusedArg2;
  undefined4 format;
  undefined4 type;
  undefined4 row;
  undefined4 column;
{
  int bytesPerPixel;
  int rowWidth;
  int filterData;
  
  bytesPerPixel = _glePixelBytes((uint)*(ushort *)(glContext + 0x334a),0x1406);
  rowWidth = *(int *)(glContext + 0x3350);
  filterData = *(int *)(glContext + 0x334c);
  ((void (*)())_gleImagingPackData)(glContext,rowWidth,1,(uint)*(ushort *)(glContext + 0x334a),0x1406,format,type,
                      filterData,row);
  ((void (*)())_gleImagingPackData)(glContext,*(undefined4 *)(glContext + 0x3354),1,
                      (uint)*(ushort *)(glContext + 0x334a),0x1406,format,type,
                      filterData + rowWidth * bytesPerPixel,column);
  return;
}

/* _gleColorTable @ 0xd4014 (128 bytes) */
void _gleColorTable(glContext, scaleBias, levelRecord, width, format, type, table)
  undefined4 glContext;
  undefined4 scaleBias;
  int levelRecord;
  undefined4 width;
  undefined4 format;
  undefined4 type;
  undefined4 table;
{
  ((void (*)())_gleImagingUnpackData)(glContext,width,1,format,type,(uint)*(ushort *)(levelRecord + 0x10),
             (uint)*(ushort *)(levelRecord + 0x12),table,*(undefined4 *)(levelRecord + 0x14));
  ((void (*)())_gleImagingScaleAndBias)(glContext,scaleBias,*(undefined4 *)(levelRecord + 0x14),(uint)*(ushort *)(levelRecord + 0x10),0,
             width,1);
  return;
}

/* _gleColorSubTable @ 0xd4094 (160 bytes) */
void _gleColorSubTable(glContext, scaleBias, tableLevel, start, pixelCount, format, type, data)
  undefined4 glContext;
  undefined4 scaleBias;
  int tableLevel;
  int start;
  undefined4 pixelCount;
  undefined4 format;
  undefined4 type;
  undefined4 data;
{
  int pixelBytes;
  
  pixelBytes = _glePixelBytes((uint)*(ushort *)(tableLevel + 0x10),(uint)*(ushort *)(tableLevel + 0x12));
  ((void (*)())_gleImagingUnpackData)(glContext,pixelCount,1,format,type,(uint)*(ushort *)(tableLevel + 0x10),
             (uint)*(ushort *)(tableLevel + 0x12),data,*(int *)(tableLevel + 0x14) + pixelBytes * start);
  ((void (*)())_gleImagingScaleAndBias)(glContext,scaleBias,*(undefined4 *)(tableLevel + 0x14),(uint)*(ushort *)(tableLevel + 0x10),
             start,pixelCount,1);
  return;
}

/* _gleTransformLightDirection @ 0xd4134 (296 bytes) */
void _gleTransformLightDirection(int glContext,int lightIndex,double unusedFloatArg1ThenCalleeResult,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  float lightVectorXThenPositionalOffset;
  float lightVectorY;
  float lightVectorZ;
  float transformedZ;
  float transformedY;
  float transformedX;
  int lightRecord;
  bool positionalLight;
  
  lightRecord = glContext + lightIndex * 0x80;
  lightVectorXThenPositionalOffset = *(float *)(lightRecord + 0x2860);
  lightVectorY = *(float *)(lightRecord + 0x2864);
  lightVectorZ = *(float *)(lightRecord + 0x2868);
  if ((*(uint *)(glContext + 0x50b0) & 0x10) != 0) {
    unusedFloatArg1ThenCalleeResult = ((double (*)())_gleModelMatInvert)(glContext);
  }
  positionalLight = *(float *)(lightRecord + 0x285c) != FLOAT_00108e50;
  transformedX = lightVectorZ * *(float *)(glContext + 0x22e0) +
          (lightVectorXThenPositionalOffset * *(float *)(glContext + 0x22c0) + lightVectorY * *(float *)(glContext + 0x22d0));
  *(float *)(lightRecord + 0x2860) = transformedX;
  transformedY = lightVectorZ * *(float *)(glContext + 0x22e4) +
          (lightVectorXThenPositionalOffset * *(float *)(glContext + 0x22c4) + lightVectorY * *(float *)(glContext + 0x22d4));
  *(float *)(lightRecord + 0x2864) = transformedY;
  transformedZ = lightVectorZ * *(float *)(glContext + 0x22e8) +
          (lightVectorXThenPositionalOffset * *(float *)(glContext + 0x22c8) + lightVectorY * *(float *)(glContext + 0x22d8));
  *(float *)(lightRecord + 0x2868) = transformedZ;
  if (positionalLight) {
    lightVectorXThenPositionalOffset = -(lightVectorZ * *(float *)(lightRecord + 0x2858) +
             (lightVectorXThenPositionalOffset * *(float *)(lightRecord + 0x2850) + lightVectorY * *(float *)(lightRecord + 0x2854))) /
            *(float *)(lightRecord + 0x285c);
    *(float *)(lightRecord + 0x2860) = lightVectorXThenPositionalOffset * *(float *)(glContext + 0x22f0) + transformedX;
    *(float *)(lightRecord + 0x2864) = lightVectorXThenPositionalOffset * *(float *)(glContext + 0x22f4) + transformedY;
    *(float *)(lightRecord + 0x2868) = lightVectorXThenPositionalOffset * *(float *)(glContext + 0x22f8) + transformedZ;
  }
  ((void (*)())_gleUpdateLightDirection)(glContext,lightIndex,unusedFloatArg1ThenCalleeResult);
  return;
}

/* _gleAddVertexMaterialNoop @ 0xd425c (4 bytes) */
void _gleAddVertexMaterialNoop()
{
  return;
}

/* _gleAddVertexMaterial @ 0xd4260 (132 bytes) */
void _gleAddVertexMaterial(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_2 + 0x74);
  *(undefined4 *)(iVar2 + 0x1e0) = 1;
  if (iVar2 == param_1 + 0x2c20) {
    return;
  }
  if (iVar2 == *(int *)(param_1 + 0x4dd0)) {
    return;
  }
  iVar1 = *(int *)(iVar2 + 0x23c);
  iVar3 = *(int *)(iVar2 + 0x238);
  if (iVar2 == *(int *)(param_1 + 0x4dd8)) {
    *(int *)(param_1 + 0x4dd8) = iVar1;
  }
  else {
    *(int *)(iVar3 + 0x23c) = iVar1;
  }
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x238) = iVar3;
  }
  iVar3 = *(int *)(param_1 + 0x4dd0);
  iVar1 = *(int *)(iVar3 + 0x23c);
  *(int *)(iVar2 + 0x238) = iVar3;
  *(int *)(iVar2 + 0x23c) = iVar1;
  *(int *)(iVar3 + 0x23c) = iVar2;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x238) = iVar2;
  }
  *(undefined1 *)(iVar3 + 0x236) = 1;
  *(undefined1 *)(iVar3 + 0x235) = 0x1f;
  return;
}

/* _gleAddVertexMaterial2Sided @ 0xd42e4 (160 bytes) */
void _gleAddVertexMaterial2Sided(glContext, vertex)
  int glContext;
  int vertex;
{
  int material;
  int *materialSlot;
  int facesLeft;
  int contextMaterial;
  int nextLinkThenHeadNext;
  int *listHeadSlot;
  int previousLinkThenListHead;
  
  materialSlot = (int *)(vertex + 0x74);
  listHeadSlot = (int *)(glContext + 0x4dd0);
  contextMaterial = glContext + 0x2c20;
  facesLeft = 1;
  do {
    material = *materialSlot;
    materialSlot = materialSlot + 1;
    *(undefined4 *)(material + 0x1e0) = 1;
    if ((material != contextMaterial) && (material != *listHeadSlot)) {
      nextLinkThenHeadNext = *(int *)(material + 0x23c);
      previousLinkThenListHead = *(int *)(material + 0x238);
      if (material == *(int *)(glContext + 0x4dd8)) {
        *(int *)(glContext + 0x4dd8) = nextLinkThenHeadNext;
      }
      else {
        *(int *)(previousLinkThenListHead + 0x23c) = nextLinkThenHeadNext;
      }
      if (nextLinkThenHeadNext != 0) {
        *(int *)(nextLinkThenHeadNext + 0x238) = previousLinkThenListHead;
      }
      previousLinkThenListHead = *listHeadSlot;
      nextLinkThenHeadNext = *(int *)(previousLinkThenListHead + 0x23c);
      *(int *)(material + 0x238) = previousLinkThenListHead;
      *(int *)(material + 0x23c) = nextLinkThenHeadNext;
      *(int *)(previousLinkThenListHead + 0x23c) = material;
      if (nextLinkThenHeadNext != 0) {
        *(int *)(nextLinkThenHeadNext + 0x238) = material;
      }
      *(undefined1 *)(previousLinkThenListHead + 0x236) = 1;
      *(undefined1 *)(previousLinkThenListHead + 0x235) = 0x1f;
    }
    facesLeft = facesLeft + -1;
    contextMaterial = contextMaterial + 0x240;
    listHeadSlot = listHeadSlot + 1;
  } while (-1 < facesLeft);
  return;
}

/* _gleSetAddVertexMaterialFunc @ 0xd4384 (136 bytes) */
void _gleSetAddVertexMaterialFunc(glContext)
  int glContext;
{
  char useTwoSidedFlag;
  undefined *materialFunc;
  
  materialFunc = PTR__gleAddVertexMaterialNoop_00110e40;
  if (*(int *)(glContext + 0x4e1c) == 0x1c00) {
    if ((*(char *)(glContext + 0x30aa) == '\0') || (*(char *)(glContext + 0x7580) != '\0'))
    goto LAB_000d43fc;
    useTwoSidedFlag = *(char *)(glContext + 0x30ac);
    materialFunc = PTR__gleAddVertexMaterial_00110e3c;
  }
  else {
    if (*(int *)(glContext + 0x4e1c) != 0x1c01) goto LAB_000d43fc;
    useTwoSidedFlag = *(char *)(glContext + 0x30aa);
  }
  if (useTwoSidedFlag != '\0') {
    materialFunc = PTR__gleAddVertexMaterial2Sided_00110e38;
  }
LAB_000d43fc:
  *(undefined **)(glContext + 0x4de4) = materialFunc;
                    
                    
  (**(int ( **)(int))(glContext + 0x4de4))(glContext);
  return;
}

/* _glePopMaterials @ 0xd440c (124 bytes) */
void _glePopMaterials(glContext)
  int glContext;
{
  int freeListHead;
  int remainingFaces;
  int baseNewerRecord;
  int *currentMaterialCursor;
  int currentMaterialRecord;
  int baseMaterialRecord;
  int olderMaterialRecord;
  
  baseMaterialRecord = glContext + 0x2c20;
  currentMaterialCursor = (int *)(glContext + 0x4dd0);
  remainingFaces = 1;
  do {
    currentMaterialRecord = *currentMaterialCursor;
    currentMaterialCursor = currentMaterialCursor + 1;
    olderMaterialRecord = *(int *)(currentMaterialRecord + 0x23c);
    if (olderMaterialRecord != 0) {
      if (*(int *)(olderMaterialRecord + 0x23c) != 0) {
        freeListHead = *(int *)(glContext + 0x4dd8);
        baseNewerRecord = *(int *)(baseMaterialRecord + 0x238);
        *(int *)(baseNewerRecord + 0x23c) = freeListHead;
        if (freeListHead != 0) {
          *(int *)(freeListHead + 0x238) = baseNewerRecord;
        }
        *(int *)(glContext + 0x4dd8) = olderMaterialRecord;
        *(int *)(baseMaterialRecord + 0x238) = currentMaterialRecord;
        *(int *)(currentMaterialRecord + 0x23c) = baseMaterialRecord;
      }
      *(undefined1 *)(baseMaterialRecord + 0x236) = 1;
    }
    remainingFaces = remainingFaces + -1;
    *(undefined1 *)(currentMaterialRecord + 0x236) = 0;
    *(undefined4 *)(currentMaterialRecord + 0x1e0) = 0;
    baseMaterialRecord = baseMaterialRecord + 0x240;
    *(undefined1 *)(currentMaterialRecord + 0x235) = 0;
  } while (-1 < remainingFaces);
  return;
}

/* _gleMaterialShinePow @ 0xd4488 (176 bytes) */
double _gleMaterialShinePow(undefined4 unusedArg1,int powerTable,float floatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  uint tableIndex;
  float tablePosition;
  int tableEntry;
  float one;
  float fraction;
  
  one = (double)FLOAT_00108e54;
  if ((double)one < floatArg1) {
    return (double)((floatArg1 - one) * *(float *)(powerTable + 0x1c) + one);
  }
  if (floatArg1 <= (double)*(float *)(powerTable + 0x10)) {
    return (double)(floatArg1 * *(float *)(powerTable + 0x18));
  }
  tablePosition = (floatArg1 - *(float *)(powerTable + 0x10)) * *(float *)(powerTable + 0x14);
  tableIndex = (uint)(int)tablePosition;
  tableEntry = tableIndex * 4 + powerTable;
  fraction = (double)(tablePosition - (float)((double)CONCAT44(0x43300000,tableIndex ^ 0x80000000) - DOUBLE_00108d58
                                  ));
  return (double)((one - fraction) * *(float *)(tableEntry + 0x20) +
                 (fraction * *(float *)(tableEntry + 0x24)));
}

/* _gleLightExponentPow @ 0xd4538 (176 bytes) */
double _gleLightExponentPow(undefined4 unusedArg1,int exponentTable,float floatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  uint tableIndex;
  float scaledIndex;
  int tableEntry;
  float one;
  float fraction;
  
  one = (double)FLOAT_00108e54;
  if ((double)one < floatArg1) {
    return (double)((floatArg1 - one) * *(float *)(exponentTable + 0x34) + one);
  }
  if (floatArg1 <= (double)*(float *)(exponentTable + 0x28)) {
    return (double)(floatArg1 * *(float *)(exponentTable + 0x30));
  }
  scaledIndex = (floatArg1 - *(float *)(exponentTable + 0x28)) * *(float *)(exponentTable + 0x2c);
  tableIndex = (uint)(int)scaledIndex;
  tableEntry = tableIndex * 4 + exponentTable;
  fraction = (double)(scaledIndex - (float)((double)CONCAT44(0x43300000,tableIndex ^ 0x80000000) - DOUBLE_00108d58
                                  ));
  return (double)((one - fraction) * *(float *)(tableEntry + 0x38) +
                 (fraction * *(float *)(tableEntry + 0x3c)));
}

/* _gleVtxLightRGBAFront_body @ 0xd45ec (1180 bytes) */
void _gleVtxLightRGBAFront_body(int glContext,int vertex,int vertexCount,double fparam_1)
{
  float fVar1;
  float inverseW;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int iVar4;
  int extraout_r3;
  int r3AfterCall1;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int material;
  int lightParams2;
  int lightProducts;
  int lightRecord;
  double extraout_f1;
  double f1AfterCall1;
  double dVar14;
  double floatZero;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  float floatOne;
  float lightContributionG;
  float lightContributionR;
  float lightContributionB;
  float colorB;
  float colorG;
  float colorR;
  float lightAttenuation;
  double incomingStack_fffffee8;
  double incomingStack_fffffef0;
  double incomingStack_fffffef8;
  double incomingStack_ffffff00;
  double incomingStack_ffffff08;
  float eyeX;
  float eyeY;
  float eyeZ;
  float toLightX;
  float toLightY;
  float toLightZ;
  float halfX;
  float halfY;
  float halfZ;
  uint localViewer;
  float *local_ac;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar4 = glContext;
  if (vertexCount < 1) {
    return;
  }
LAB_000d462c:
  if ((*(byte *)(vertex + 0x7e) & 2) != 0) {
    material = *(int *)(vertex + 0x74);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
          }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      inverseW = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyeX;
      eyeZ = *(float *)(vertex + 0x28) * inverseW;
      eyeX = *(float *)(vertex + 0x20) * inverseW;
      eyeY = *(float *)(vertex + 0x24) * inverseW;
    }
    colorR = (double)*(float *)(material + 0x1d0);
    colorG = (double)*(float *)(material + 0x1d4);
    lightIndex = 0;
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    local_ac = &FLOAT_00108e80;
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d4a5c;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          toLightX = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall1 = ((double (*)())(*(code **)vectorNormalize))(glContext,&toLightX,&toLightX);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall1 < (double)*local_ac)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
          }
          else {
            fVar1 = (float)((double)floatOne / f1AfterCall1);
            lightAttenuation = (double)(floatOne / (*(float *)(lightParams2 + 0x2878) * fVar1 * fVar1 +
                                                      (*(float *)(lightParams2 + 0x2874) * fVar1 +
                                                      *(float *)(lightParams2 + 0x2870))));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          toLightX = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (toLightX * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d4a44;
          dVar14 = ((double (*)())_gleLightExponentPow)(iVar4,lightRecord + 0x4a70,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                              incomingFpr8,incomingStack_fffffee8,incomingStack_fffffef0,incomingStack_fffffef8,
                              incomingStack_ffffff00,incomingStack_ffffff08);
          lightAttenuation = (double)(float)((double)lightAttenuation * dVar14);
        }
        if (localViewer == 0) {
          halfZ = (toLightZ + floatOne);
          halfX = toLightX;
          halfY = toLightY;
        }
        else {
          halfX = -*eyePosition;
          halfY = -eyePosition[1];
          halfZ = -eyePosition[2];
          (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
          halfX = halfX + toLightX;
          halfY = halfY + toLightY;
          halfZ = halfZ + toLightZ;
        }
        f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
        floatZero = (double)FLOAT_00108e50;
        fparam_1 = f1AfterCall2;
        if ((double)lightAttenuation != floatZero) {
          incomingFpr8 = (double)*(float *)(vertex + 0x40);
          incomingFpr7 = (double)*(float *)(vertex + 0x48);
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          fparam_1 = (double)(float)(incomingFpr7 * (double)toLightZ +
                                    (double)(float)(incomingFpr8 * (double)toLightX +
                                                   (double)(*(float *)(vertex + 0x44) * toLightY)))
          ;
          if (floatZero < fparam_1) {
            lightContributionB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x68) + (double)lightContributionB);
            lightContributionR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x60) + (double)lightContributionR);
            lightContributionG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 100) + (double)lightContributionG);
            fparam_1 = (double)(float)(incomingFpr7 * (double)halfZ +
                                      (double)(float)(incomingFpr8 * (double)halfX +
                                                     (double)(*(float *)(vertex + 0x44) * halfY)
                                                     ));
            if (floatZero < fparam_1) {
              incomingFpr2 = (double)*(float *)(material + 0x40);
              dVar14 = _pow(fparam_1,incomingFpr2);
              fparam_1 = (double)(float)dVar14;
              lightContributionB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)lightContributionB);
              lightContributionR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)lightContributionR);
              lightContributionG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)lightContributionG);
              iVar4 = r3AfterCall1;
            }
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
          }
          else {
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
          }
        }
      }
      else {
        incomingFpr8 = (double)*(float *)(vertex + 0x48);
        incomingFpr7 = (double)FLOAT_00108e50;
        fparam_1 = (double)(float)(incomingFpr8 * (double)*(float *)(lightRecord + 0x4a84) +
                                  (double)(*(float *)(vertex + 0x40) * *(float *)(lightRecord + 0x4a7c)
                                          + *(float *)(vertex + 0x44) * *(float *)(lightRecord + 0x4a80)
                                          ));
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if (incomingFpr7 < fparam_1) {
          colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x60) + (double)colorR);
          colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 100) + (double)colorG);
          colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x68) + (double)colorB);
          fparam_1 = (double)(float)(incomingFpr8 * (double)*(float *)(lightParams + 0x2888) +
                                    (double)(*(float *)(vertex + 0x40) * *(float *)(lightParams + 0x2880)
                                            + *(float *)(vertex + 0x44) *
                                              *(float *)(lightParams + 0x2884)));
          if (incomingFpr7 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,material + 0x1e8,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                                  incomingFpr8,incomingStack_fffffee8,incomingStack_fffffef0,incomingStack_fffffef8,
                                  incomingStack_ffffff00,incomingStack_ffffff08);
            colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d4a44:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d4a6c;
LAB_000d4a5c:
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d4a6c:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (vertexCount <= vertexIndex) {
    return;
  }
  goto LAB_000d462c;
}

/* _gleVtxLightRGBABack_body @ 0xd4a8c (1188 bytes) */
void _gleVtxLightRGBABack_body(int glContext,int vertex,int vertexCount,double fparam_1,double fparam_2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double fparam_7,double fparam_8,double unusedFloatArg9)
{
  float fVar1;
  float inverseW;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int iVar4;
  int extraout_r3;
  int r3AfterCall1;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int material;
  int lightParams2;
  int lightProducts;
  int lightRecord;
  double extraout_f1;
  double f1AfterCall1;
  double dVar14;
  double f1AfterCall2;
  float dVar15;
  float lightAttenuation;
  float floatOne;
  float lightContributionG;
  float lightContributionR;
  float lightContributionB;
  float colorB;
  float colorG;
  float colorR;
  double incomingStack_fffffee8;
  double incomingStack_fffffef0;
  double incomingStack_fffffef8;
  double incomingStack_ffffff00;
  double incomingStack_ffffff08;
  float eyeX;
  float eyeY;
  float eyeZ;
  float toLightX;
  float toLightY;
  float toLightZ;
  float halfX;
  float halfY;
  float halfZ;
  uint localViewer;
  float *local_ac;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar4 = glContext;
  if (vertexCount < 1) {
    return;
  }
LAB_000d4acc:
  if ((*(byte *)(vertex + 0x7e) & 4) != 0) {
    material = *(int *)(vertex + 0x78);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
          }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      inverseW = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyeX;
      eyeZ = *(float *)(vertex + 0x28) * inverseW;
      eyeX = *(float *)(vertex + 0x20) * inverseW;
      eyeY = *(float *)(vertex + 0x24) * inverseW;
    }
    colorR = (double)*(float *)(material + 0x1d0);
    colorG = (double)*(float *)(material + 0x1d4);
    lightIndex = 0;
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    local_ac = &FLOAT_00108e80;
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d4f04;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          toLightX = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall1 = ((double (*)())(*(code **)vectorNormalize))(glContext,&toLightX,&toLightX);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall1 < (double)*local_ac)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
          }
          else {
            fVar1 = (float)((double)floatOne / f1AfterCall1);
            lightAttenuation = (double)(floatOne / (*(float *)(lightParams2 + 0x2878) * fVar1 * fVar1 +
                                                      (*(float *)(lightParams2 + 0x2874) * fVar1 +
                                                      *(float *)(lightParams2 + 0x2870))));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          toLightX = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (toLightX * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d4eec;
          dVar14 = ((double (*)())_gleLightExponentPow)(iVar4,lightRecord + 0x4a70,fparam_1,fparam_2,floatArg3,floatArg4,floatArg5,
                              floatArg6,fparam_7,fparam_8,incomingStack_fffffee8,incomingStack_fffffef0,
                              incomingStack_fffffef8,incomingStack_ffffff00,incomingStack_ffffff08);
          lightAttenuation = (double)(float)((double)lightAttenuation * dVar14);
        }
        if (localViewer == 0) {
          halfZ = (toLightZ + floatOne);
          halfX = toLightX;
          halfY = toLightY;
        }
        else {
          halfX = -*eyePosition;
          halfY = -eyePosition[1];
          halfZ = -eyePosition[2];
          (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
          halfX = halfX + toLightX;
          halfY = halfY + toLightY;
          halfZ = halfZ + toLightZ;
        }
        f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
        fparam_8 = (double)FLOAT_00108e50;
        fparam_1 = f1AfterCall2;
        if ((double)lightAttenuation != fparam_8) {
          fparam_7 = (double)*(float *)(vertex + 0x48);
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          dVar14 = (double)(float)(fparam_7 * (double)toLightZ +
                                  (double)(*(float *)(vertex + 0x40) * toLightX +
                                          *(float *)(vertex + 0x44) * toLightY));
          fparam_1 = -dVar14;
          if (fparam_8 < fparam_1) {
            lightContributionR = -(double)(float)(dVar14 * (double)*(float *)(lightProducts + 0x60) - (double)lightContributionR);
            lightContributionB = -(double)(float)(dVar14 * (double)*(float *)(lightProducts + 0x68) - (double)lightContributionB);
            fparam_1 = -(double)(float)(fparam_7 * (double)halfZ +
                                       (double)(*(float *)(vertex + 0x40) * halfX +
                                               *(float *)(vertex + 0x44) * halfY));
            lightContributionG = -(double)(float)(dVar14 * (double)*(float *)(lightProducts + 100) - (double)lightContributionG);
            if (fparam_8 < fparam_1) {
              fparam_2 = (double)*(float *)(material + 0x40);
              dVar14 = _pow(fparam_1,fparam_2);
              fparam_1 = (double)(float)dVar14;
              lightContributionB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)lightContributionB);
              lightContributionR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)lightContributionR);
              lightContributionG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)lightContributionG);
              iVar4 = r3AfterCall1;
            }
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
          }
          else {
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
          }
        }
      }
      else {
        fparam_8 = (double)*(float *)(vertex + 0x48);
        fparam_7 = (double)FLOAT_00108e50;
        dVar15 = (double)(float)(fparam_8 * (double)*(float *)(lightRecord + 0x4a84) +
                                (double)(*(float *)(vertex + 0x40) * *(float *)(lightRecord + 0x4a7c) +
                                        *(float *)(vertex + 0x44) * *(float *)(lightRecord + 0x4a80)));
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        fparam_1 = -(double)dVar15;
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if (fparam_7 < fparam_1) {
          colorR = -(double)(dVar15 * *(float *)(lightProducts + 0x60) - colorR);
          colorG = -(double)(dVar15 * *(float *)(lightProducts + 100) - colorG);
          fparam_1 = -(double)(float)(fparam_8 * (double)*(float *)(lightParams + 0x2888) +
                                     (double)(*(float *)(vertex + 0x40) *
                                              *(float *)(lightParams + 0x2880) +
                                             *(float *)(vertex + 0x44) * *(float *)(lightParams + 0x2884)
                                             ));
          colorB = -(double)(dVar15 * *(float *)(lightProducts + 0x68) - colorB);
          if (fparam_7 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,material + 0x1e8,fparam_1,fparam_2,floatArg3,floatArg4,floatArg5,
                                  floatArg6,fparam_7,fparam_8,incomingStack_fffffee8,incomingStack_fffffef0,
                                  incomingStack_fffffef8,incomingStack_ffffff00,incomingStack_ffffff08);
            colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d4eec:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d4f14;
LAB_000d4f04:
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d4f14:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (vertexCount <= vertexIndex) {
    return;
  }
  goto LAB_000d4acc;
}

/* _gleVtxLightSpecRGBAFront @ 0xd4f30 (1632 bytes) */
void _gleVtxLightSpecRGBAFront(int glContext,int vertex,int vertexCount,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  float fVar1;
  float inverseW;
  float fVar2;
  float fVar3;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int iVar6;
  int extraout_r3;
  int extraout_r3_00;
  int r3AfterCall2;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int lightParams2;
  int material;
  int lightProducts;
  int lightRecord;
  double extraout_f1;
  double f1AfterCall1;
  double f1AfterCall2;
  double f1AfterCall3;
  double dVar16;
  float dVar17;
  float lightContributionB;
  double dVar18;
  double lightAttenuation;
  float floatOne;
  float dVar20;
  float dVar21;
  float floatZero;
  float dVar23;
  float lightContributionG;
  float lightContributionR;
  float dVar26;
  float colorB;
  float colorG;
  float colorR;
  int iStack00000020;
  double incomingStackWord_fffffea8;
  double incomingStackWord_fffffeb0;
  double incomingStackWord_fffffeb8;
  double incomingStackWord_fffffec0;
  double incomingStackWord_fffffec8;
  float eyeX;
  float eyeY;
  float eyeZ;
  float halfX;
  float halfY;
  float halfZ;
  float local_100;
  float local_fc;
  float toLightY;
  float local_f8;
  float toLightZ;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  uint localViewer;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar6 = glContext;
  iStack00000020 = vertexCount;
  if (vertexCount < 1) {
    return;
  }
LAB_000d4f74:
  if ((*(byte *)(vertex + 0x7e) & 2) != 0) {
    material = *(int *)(vertex + 0x74);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
          }
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      inverseW = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyeX;
      eyeZ = *(float *)(vertex + 0x28) * inverseW;
      eyeX = *(float *)(vertex + 0x20) * inverseW;
      eyeY = *(float *)(vertex + 0x24) * inverseW;
    }
    if (*(char *)(glContext + 0x30ae) != '\0') {
      if ((localViewer == 0) || (*(int *)(glContext + 0x4ddc) == 0)) {
        halfY = 0.0;
        halfZ = 1.0;
        halfX = 0.0;
      }
      else {
        halfX = -*eyePosition;
        halfY = -eyePosition[1];
        halfZ = -eyePosition[2];
        f1AfterCall1 = ((double (*)())(*(code **)PTR__gleVectorNormalize_00112064))(glContext,&halfX,&halfX);
        fparam_1 = f1AfterCall1;
      }
    }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    floatZero = (double)FLOAT_00108e50;
    colorR = (double)*(float *)(material + 0x1d0);
    lightIndex = 0;
    colorG = (double)*(float *)(material + 0x1d4);
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    dVar20 = (double)floatZero;
    dVar21 = (double)floatZero;
    dVar23 = (double)floatZero;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d5530;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          local_100 = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&local_100,&local_100);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall2 < (double)FLOAT_00108e80)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
            fparam_1 = f1AfterCall2;
          }
          else {
            fparam_1 = (double)(float)((double)floatOne / f1AfterCall2);
            lightAttenuation = (double)(floatOne / (float)((double)(float)((double)*(float *)(
                                                  lightParams2 + 0x2878) * fparam_1) * fparam_1 +
                                                  (double)(float)((double)*(float *)(lightParams2 + 0x2874
                                                                                    ) * fparam_1 +
                                                                 (double)*(float *)(lightParams2 + 0x2870)
                                                                 )));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          local_100 = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (local_100 * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d5518;
          fparam_1 = ((double (*)())_gleLightExponentPow)(iVar6,lightRecord + 0x4a70,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                fparam_6,fparam_7,fparam_8,incomingStackWord_fffffea8,incomingStackWord_fffffeb0,
                                incomingStackWord_fffffeb8,incomingStackWord_fffffec0,incomingStackWord_fffffec8);
          lightAttenuation = (double)(float)(lightAttenuation * fparam_1);
          iVar6 = iVar6;
        }
        if (*(char *)(glContext + 0x30ae) == '\0') {
          if (localViewer == 0) {
            halfZ = (toLightZ + floatOne);
            halfX = local_100;
            halfY = toLightY;
          }
          else {
            halfX = -*eyePosition;
            halfY = -eyePosition[1];
            halfZ = -eyePosition[2];
            (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
            halfX = halfX + local_100;
            halfY = halfY + toLightY;
            halfZ = halfZ + toLightZ;
          }
          f1AfterCall3 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
          fparam_1 = f1AfterCall3;
        }
        if (lightAttenuation != (double)FLOAT_00108e50) {
          fparam_4 = (double)*(float *)(vertex + 0x44);
          dVar26 = (double)toLightY;
          fparam_5 = (double)*(float *)(vertex + 0x40);
          fparam_3 = (double)local_100;
          fparam_6 = (double)*(float *)(vertex + 0x48);
          fparam_2 = (double)toLightZ;
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          dVar16 = (double)(float)(fparam_6 * fparam_2 +
                                  (double)(float)(fparam_5 * fparam_3 +
                                                 (double)(float)(fparam_4 * (double)dVar26)));
          if ((double)FLOAT_00108e50 < dVar16) {
            lightContributionR = (double)(float)(dVar16 * (double)*(float *)(lightProducts + 0x60) + (double)lightContributionR);
            lightContributionG = (double)(float)(dVar16 * (double)*(float *)(lightProducts + 100) + (double)lightContributionG);
            lightContributionB = (double)(float)(dVar16 * (double)*(float *)(lightProducts + 0x68) + (double)lightContributionB);
            if (*(char *)(glContext + 0x30ae) == '\0') {
              fVar1 = (float)(fparam_6 * (double)halfZ +
                             (double)(float)(fparam_5 * (double)halfX +
                                            (double)(float)(fparam_4 * (double)halfY)));
            }
            else {
              local_e8 = (float)(fparam_5 * (double)dVar26 - (double)(float)(fparam_4 * fparam_3));
              fparam_7 = (double)local_e8;
              local_f0 = (float)(fparam_4 * fparam_2 - (double)(float)(fparam_6 * (double)dVar26));
              dVar16 = (double)local_f0;
              local_ec = (float)(fparam_6 * fparam_3 - (double)(float)(fparam_5 * fparam_2));
              fparam_8 = (double)local_ec;
              fVar1 = (float)(fparam_6 * dVar16 - (double)(float)(fparam_5 * fparam_7));
              fVar2 = (float)(fparam_5 * fparam_8 - (double)(float)(fparam_4 * dVar16));
              fVar3 = (float)(fparam_4 * fparam_7 - (double)(float)(fparam_6 * fparam_8));
              local_dc = ((fVar1 + fVar1) + dVar26);
              local_d8 = (float)((double)(fVar2 + fVar2) + fparam_2);
              local_e0 = (float)((double)(fVar3 + fVar3) + fparam_3);
              fVar1 = local_d8 * halfZ + (local_e0 * halfX + local_dc * halfY);
            }
            if (!((double)floatZero < (double)fVar1)) goto LAB_000d54cc;
            fparam_2 = (double)*(float *)(material + 0x40);
            dVar16 = _pow((double)fVar1,fparam_2);
            fVar1 = (float)dVar16;
            dVar26 = (double)(fVar1 * *(float *)(lightProducts + 0x78));
            iVar6 = r3AfterCall2;
            fparam_1 = (double)(fVar1 * *(float *)(lightProducts + 0x74));
            dVar16 = (double)(fVar1 * *(float *)(lightProducts + 0x70));
          }
          else {
LAB_000d54cc:
            dVar26 = (double)FLOAT_00108e50;
            fparam_1 = (double)dVar26;
            dVar16 = (double)dVar26;
          }
          if (lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
            dVar23 = (double)(float)((double)dVar23 + dVar16);
            dVar21 = (double)(float)((double)dVar21 + fparam_1);
            dVar20 = (double)(dVar20 + dVar26);
          }
          else {
            dVar20 = (double)(float)(lightAttenuation * (double)dVar26 + (double)dVar20);
            colorR = (double)(float)(lightAttenuation * (double)lightContributionR + (double)colorR);
            colorG = (double)(float)(lightAttenuation * (double)lightContributionG + (double)colorG);
            colorB = (double)(float)(lightAttenuation * (double)lightContributionB + (double)colorB);
            dVar23 = (double)(float)(lightAttenuation * dVar16 + (double)dVar23);
            dVar21 = (double)(float)(lightAttenuation * fparam_1 + (double)dVar21);
          }
        }
      }
      else {
        dVar16 = (double)*(float *)(vertex + 0x44);
        fparam_7 = (double)*(float *)(lightRecord + 0x4a80);
        fparam_8 = (double)*(float *)(vertex + 0x40);
        dVar17 = (double)*(float *)(vertex + 0x48);
        dVar18 = (double)*(float *)(lightRecord + 0x4a84);
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        fparam_1 = (double)(float)((double)dVar17 * dVar18 +
                                  (double)(float)(fparam_8 * (double)*(float *)(lightRecord + 0x4a7c) +
                                                 (double)(float)(dVar16 * fparam_7)));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if ((double)floatZero < fparam_1) {
          colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x60) + (double)colorR);
          colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 100) + (double)colorG);
          colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x68) + (double)colorB);
          if (*(char *)(glContext + 0x30ae) == '\0') {
            dVar18 = (double)dVar17 * (double)*(float *)(lightParams + 0x2888) +
                     (double)(float)(fparam_8 * (double)*(float *)(lightParams + 0x2880) +
                                    (double)(float)(dVar16 * (double)*(float *)(lightParams + 0x2884)));
          }
          else {
            local_f8 = *(float *)(lightRecord + 0x4a84);
            local_100 = (float)(dVar16 * dVar18 - (double)(float)((double)dVar17 * fparam_7));
            local_fc = (dVar17 * *(float *)(lightRecord + 0x4a7c) - (float)(fparam_8 * dVar18));
            fVar1 = (float)(fparam_8 * (double)local_fc -
                           (double)(float)(dVar16 * (double)local_100));
            dVar18 = (double)(fVar1 + fVar1) + dVar18;
          }
          fparam_1 = (double)(float)dVar18;
          if ((double)floatZero < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar6,material + 0x1e8,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                  fparam_6,fparam_7,fparam_8,incomingStackWord_fffffea8,incomingStackWord_fffffeb0,
                                  incomingStackWord_fffffeb8,incomingStackWord_fffffec0,incomingStackWord_fffffec8);
            dVar20 = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)dVar20);
            dVar23 = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)dVar23);
            dVar21 = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)dVar21);
            iVar6 = iVar6;
          }
        }
      }
LAB_000d5518:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d5570;
LAB_000d5530:
  if (*(short *)(glContext + 0x30a8) == -0x7e06) {
    *(float *)(vertex + 0x50) = (float)(double)dVar23;
    *(float *)(vertex + 0x54) = (float)(double)dVar21;
    *(float *)(vertex + 0x58) = (float)(double)dVar20;
  }
  else {
    colorR = (double)(colorR + dVar23);
    colorG = (double)(colorG + dVar21);
    colorB = (double)(colorB + dVar20);
  }
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d5570:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (iStack00000020 <= vertexIndex) {
    return;
  }
  goto LAB_000d4f74;
}

/* _gleVtxLightSpecRGBABack @ 0xd5590 (1640 bytes) */
void _gleVtxLightSpecRGBABack(int glContext,int vertex,int vertexCount,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  float doubleCrossY;
  float directionalDoubleCrossZ;
  float specularFactor;
  float inverseW;
  float doubleCrossX;
  float doubleCrossZ;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int glContextForCalls;
  int r3AfterCall;
  int r3AfterCall1;
  int r3AfterCall2;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int lightParams2;
  int material;
  int lightProducts;
  int lightRecord;
  double f1AfterCall;
  double f1AfterCall1;
  double f1AfterCall2;
  double f1AfterCall3;
  float normalZ;
  float lightAttenuation;
  double normalDotLight;
  double directionalLightZ;
  double specularR;
  double lnCrossXCopy;
  double specularDot;
  float normalDotDirection;
  float lightContributionB;
  float floatOne;
  float specularSumB;
  float specularSumG;
  float floatZero;
  float specularSumR;
  float lightContributionG;
  float lightContributionR;
  float toLightYCopy;
  float specularB;
  float colorB;
  float colorG;
  float colorR;
  int iStack00000020;
  double incomingStackWord_fffffea8;
  double incomingStackWord_fffffeb0;
  double incomingStackWord_fffffeb8;
  double incomingStackWord_fffffec0;
  double incomingStackWord_fffffec8;
  float eyeX;
  float eyeY;
  float eyeZ;
  float halfX;
  float halfY;
  float halfZ;
  float toLightX;
  float lnCrossYDir;
  float toLightY;
  float lightDirZ;
  float toLightZ;
  float lnCrossX;
  float lnCrossY;
  float lnCrossZ;
  float crossAdjustedLightX;
  float crossAdjustedLightY;
  float crossAdjustedLightZ;
  uint localViewer;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  glContextForCalls = glContext;
  iStack00000020 = vertexCount;
  if (vertexCount < 1) {
    return;
  }
LAB_000d55d4:
  if ((*(byte *)(vertex + 0x7e) & 4) != 0) {
    material = *(int *)(vertex + 0x78);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
          }
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      inverseW = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyeX;
      eyeZ = *(float *)(vertex + 0x28) * inverseW;
      eyeX = *(float *)(vertex + 0x20) * inverseW;
      eyeY = *(float *)(vertex + 0x24) * inverseW;
    }
    if (*(char *)(glContext + 0x30ae) != '\0') {
      if ((localViewer == 0) || (*(int *)(glContext + 0x4ddc) == 0)) {
        halfY = 0.0;
        halfZ = 1.0;
        halfX = 0.0;
      }
      else {
        halfX = -*eyePosition;
        halfY = -eyePosition[1];
        halfZ = -eyePosition[2];
        f1AfterCall1 = ((double (*)())(*(code **)PTR__gleVectorNormalize_00112064))(glContext,&halfX,&halfX);
        floatArg1 = f1AfterCall1;
      }
    }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    floatZero = (double)FLOAT_00108e50;
    colorR = (double)*(float *)(material + 0x1d0);
    lightIndex = 0;
    colorG = (double)*(float *)(material + 0x1d4);
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    specularSumB = (double)floatZero;
    specularSumG = (double)floatZero;
    specularSumR = (double)floatZero;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d5b98;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          toLightX = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&toLightX,&toLightX);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall2 < (double)FLOAT_00108e80)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
            floatArg1 = f1AfterCall2;
          }
          else {
            floatArg1 = (double)(float)((double)floatOne / f1AfterCall2);
            lightAttenuation = (double)(floatOne / (float)((double)(float)((double)*(float *)(
                                                  lightParams2 + 0x2878) * floatArg1) * floatArg1 +
                                                  (double)(float)((double)*(float *)(lightParams2 + 0x2874
                                                                                    ) * floatArg1 +
                                                                 (double)*(float *)(lightParams2 + 0x2870)
                                                                 )));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          toLightX = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          floatArg1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (toLightX * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (floatArg1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d5b80;
          floatArg1 = ((double (*)())_gleLightExponentPow)(glContextForCalls,lightRecord + 0x4a70,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,
                                floatArg6,floatArg7,floatArg8,incomingStackWord_fffffea8,incomingStackWord_fffffeb0,
                                incomingStackWord_fffffeb8,incomingStackWord_fffffec0,incomingStackWord_fffffec8);
          lightAttenuation = (double)(float)((double)lightAttenuation * floatArg1);
          glContextForCalls = glContextForCalls;
        }
        if (*(char *)(glContext + 0x30ae) == '\0') {
          if (localViewer == 0) {
            halfZ = (toLightZ + floatOne);
            halfX = toLightX;
            halfY = toLightY;
          }
          else {
            halfX = -*eyePosition;
            halfY = -eyePosition[1];
            halfZ = -eyePosition[2];
            (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
            halfX = halfX + toLightX;
            halfY = halfY + toLightY;
            halfZ = halfZ + toLightZ;
          }
          f1AfterCall3 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
          floatArg1 = f1AfterCall3;
        }
        if ((double)lightAttenuation != (double)FLOAT_00108e50) {
          floatArg4 = (double)*(float *)(vertex + 0x44);
          toLightYCopy = (double)toLightY;
          floatArg5 = (double)*(float *)(vertex + 0x40);
          floatArg3 = (double)toLightX;
          floatArg6 = (double)*(float *)(vertex + 0x48);
          floatArg2 = (double)toLightZ;
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          normalDotLight = (double)(float)(floatArg6 * floatArg2 +
                                  (double)(float)(floatArg5 * floatArg3 +
                                                 (double)(float)(floatArg4 * (double)toLightYCopy)));
          if ((double)FLOAT_00108e50 < -normalDotLight) {
            lightContributionR = -(double)(float)(normalDotLight * (double)*(float *)(lightProducts + 0x60) - (double)lightContributionR);
            lightContributionG = -(double)(float)(normalDotLight * (double)*(float *)(lightProducts + 100) - (double)lightContributionG);
            lightContributionB = -(double)(float)(normalDotLight * (double)*(float *)(lightProducts + 0x68) - (double)lightContributionB);
            if (*(char *)(glContext + 0x30ae) == '\0') {
              specularDot = -(double)(float)(floatArg6 * (double)halfZ +
                                       (double)(float)(floatArg5 * (double)halfX +
                                                      (double)(float)(floatArg4 * (double)halfY))
                                       );
            }
            else {
              lnCrossX = (float)(floatArg6 * (double)toLightYCopy - (double)(float)(floatArg4 * floatArg2));
              lnCrossXCopy = (double)lnCrossX;
              lnCrossZ = (float)(floatArg4 * floatArg3 - (double)(float)(floatArg5 * (double)toLightYCopy));
              floatArg7 = (double)lnCrossZ;
              lnCrossY = (float)(floatArg5 * floatArg2 - (double)(float)(floatArg6 * floatArg3));
              floatArg8 = (double)lnCrossY;
              doubleCrossY = (float)(floatArg5 * floatArg7 - (double)(float)(floatArg6 * lnCrossXCopy));
              doubleCrossX = (float)(floatArg6 * floatArg8 - (double)(float)(floatArg4 * floatArg7));
              doubleCrossZ = (float)(floatArg4 * lnCrossXCopy - (double)(float)(floatArg5 * floatArg8));
              crossAdjustedLightY = ((doubleCrossY + doubleCrossY) + toLightYCopy);
              crossAdjustedLightX = (float)((double)(doubleCrossX + doubleCrossX) + floatArg3);
              crossAdjustedLightZ = (float)((double)(doubleCrossZ + doubleCrossZ) + floatArg2);
              specularDot = (double)(crossAdjustedLightZ * halfZ + (crossAdjustedLightX * halfX + crossAdjustedLightY * halfY));
            }
            if (!((double)floatZero < specularDot)) goto LAB_000d5b34;
            floatArg2 = (double)*(float *)(material + 0x40);
            specularDot = _pow(specularDot,floatArg2);
            specularFactor = (float)specularDot;
            specularB = (double)(specularFactor * *(float *)(lightProducts + 0x78));
            glContextForCalls = r3AfterCall2;
            floatArg1 = (double)(specularFactor * *(float *)(lightProducts + 0x74));
            specularR = (double)(specularFactor * *(float *)(lightProducts + 0x70));
          }
          else {
LAB_000d5b34:
            specularB = (double)FLOAT_00108e50;
            floatArg1 = (double)specularB;
            specularR = (double)specularB;
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
            specularSumR = (double)(float)((double)specularSumR + specularR);
            specularSumG = (double)(float)((double)specularSumG + floatArg1);
            specularSumB = (double)(specularSumB + specularB);
          }
          else {
            specularSumB = (double)(lightAttenuation * specularB + specularSumB);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            specularSumR = (double)(float)((double)lightAttenuation * specularR + (double)specularSumR);
            specularSumG = (double)(float)((double)lightAttenuation * floatArg1 + (double)specularSumG);
          }
        }
      }
      else {
        floatArg7 = (double)*(float *)(vertex + 0x44);
        floatArg6 = (double)*(float *)(lightRecord + 0x4a80);
        floatArg8 = (double)*(float *)(vertex + 0x40);
        normalZ = (double)*(float *)(vertex + 0x48);
        directionalLightZ = (double)*(float *)(lightRecord + 0x4a84);
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        normalDotDirection = (double)(float)((double)normalZ * directionalLightZ +
                                (double)(float)(floatArg8 * (double)*(float *)(lightRecord + 0x4a7c) +
                                               (double)(float)(floatArg7 * floatArg6)));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        floatArg1 = -(double)normalDotDirection;
        if ((double)floatZero < floatArg1) {
          colorR = -(double)(normalDotDirection * *(float *)(lightProducts + 0x60) - colorR);
          colorG = -(double)(normalDotDirection * *(float *)(lightProducts + 100) - colorG);
          colorB = -(double)(normalDotDirection * *(float *)(lightProducts + 0x68) - colorB);
          if (*(char *)(glContext + 0x30ae) == '\0') {
            floatArg1 = -(double)(normalZ * *(float *)(lightParams + 0x2888) + (float)(floatArg8 *
                                                       (double)*(float *)(lightParams + 0x2880) +
                                                      (double)(float)(floatArg7 *
                                                                     (double)*(float *)(lightParams + 
                                                  0x2884))));
          }
          else {
            lightDirZ = *(float *)(lightRecord + 0x4a84);
            toLightX = (float)((double)normalZ * floatArg6 - (double)(float)(floatArg7 * directionalLightZ));
            lnCrossYDir = (float)(floatArg8 * directionalLightZ -
                              (double)(normalZ * *(float *)(lightRecord + 0x4a7c)));
            directionalDoubleCrossZ = (float)(floatArg7 * (double)toLightX -
                           (double)(float)(floatArg8 * (double)lnCrossYDir));
            floatArg1 = (double)(float)((double)(directionalDoubleCrossZ + directionalDoubleCrossZ) + directionalLightZ);
          }
          if ((double)floatZero < floatArg1) {
            floatArg1 = ((double (*)())_gleMaterialShinePow)(glContextForCalls,material + 0x1e8,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,
                                  floatArg6,floatArg7,floatArg8,incomingStackWord_fffffea8,incomingStackWord_fffffeb0,
                                  incomingStackWord_fffffeb8,incomingStackWord_fffffec0,incomingStackWord_fffffec8);
            colorB = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            glContextForCalls = glContextForCalls;
          }
        }
      }
LAB_000d5b80:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d5bd8;
LAB_000d5b98:
  if (*(short *)(glContext + 0x30a8) == -0x7e06) {
    *(float *)(vertex + 0x50) = (float)(double)specularSumR;
    *(float *)(vertex + 0x54) = (float)(double)specularSumG;
    *(float *)(vertex + 0x58) = (float)(double)specularSumB;
  }
  else {
    colorR = (double)(colorR + specularSumR);
    colorG = (double)(colorG + specularSumG);
    colorB = (double)(colorB + specularSumB);
  }
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d5bd8:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (iStack00000020 <= vertexIndex) {
    return;
  }
  goto LAB_000d55d4;
}

/* _gleVtxLightFastRGBAFront @ 0xd5bf8 (372 bytes) */
void _gleVtxLightFastRGBAFront(int glContext,int vertex,int vertexCount,double unusedFloatArg1)
{
  undefined4 colorAlpha;
  int iVar2;
  int extraout_r3;
  int vertexIndex;
  uint enabledLightMask;
  uint lightIndex;
  int lightParams;
  int iVar7;
  int material;
  int iVar9;
  double dVar10;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double floatZero;
  double fparam_8;
  float dVar11;
  float dVar12;
  float dVar13;
  double incomingStackWord_ffffff78;
  double incomingStackWord_ffffff80;
  double incomingStackWord_ffffff88;
  double incomingStackWord_ffffff90;
  double incomingStackWord_ffffff98;
  
  vertexIndex = 0;
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar2 = glContext;
  if (vertexCount < 1) {
LAB_000d5d60:
    return;
  }
LAB_000d5c2c:
  if ((*(byte *)(vertex + 0x7e) & 2) != 0) {
    material = *(int *)(vertex + 0x74);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
    }
    dVar13 = (double)*(float *)(material + 0x1e8);
    iVar7 = material + 0x50;
    dVar12 = (double)*(float *)(material + 0x1ec);
    dVar11 = (double)*(float *)(material + 0x1f0);
    lightIndex = 0;
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    lightParams = glContext + 0x2820;
    iVar9 = glContext + 0x4a70;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d5d40;
      }
      else {
        fparam_8 = (double)*(float *)(vertex + 0x48);
        floatZero = (double)FLOAT_00108e50;
        dVar10 = (double)(float)(fparam_8 * (double)*(float *)(iVar9 + 0x14) +
                                (double)(*(float *)(vertex + 0x40) * *(float *)(iVar9 + 0xc) +
                                        *(float *)(vertex + 0x44) * *(float *)(iVar9 + 0x10)));
        if (floatZero < dVar10) {
          dVar12 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x14) + (double)dVar12);
          dVar11 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x18) + (double)dVar11);
          dVar13 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x10) + (double)dVar13);
          dVar10 = (double)(float)(fparam_8 * (double)*(float *)(lightParams + 0x68) +
                                  (double)(*(float *)(vertex + 0x40) * *(float *)(lightParams + 0x60) +
                                          *(float *)(vertex + 0x44) * *(float *)(lightParams + 100)));
          if (floatZero < dVar10) {
            dVar10 = ((double (*)())_gleMaterialShinePow)(iVar2,material + 0x1e8,dVar10,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,floatZero,
                                fparam_8,incomingStackWord_ffffff78,incomingStackWord_ffffff80,incomingStackWord_ffffff88,
                                incomingStackWord_ffffff90,incomingStackWord_ffffff98);
            dVar13 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x20) + (double)dVar13);
            dVar12 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x24) + (double)dVar12);
            dVar11 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x28) + (double)dVar11);
            iVar2 = iVar2;
          }
        }
      }
      lightIndex = lightIndex + 1;
      iVar9 = iVar9 + 0x6c;
      iVar7 = iVar7 + 0x30;
      lightParams = lightParams + 0x80;
    } while( true );
  }
  goto LAB_000d5d50;
LAB_000d5d40:
  *(float *)(vertex + 0x30) = (float)(double)dVar13;
  *(float *)(vertex + 0x34) = (float)(double)dVar12;
  *(float *)(vertex + 0x38) = (float)(double)dVar11;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d5d50:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (vertexCount <= vertexIndex) goto LAB_000d5d60;
  goto LAB_000d5c2c;
}

/* _gleVtxLightFastRGBABack @ 0xd5d6c (376 bytes) */
void _gleVtxLightFastRGBABack(int glContext,int vertex,int vertexCount,double unusedFloatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9)
{
  undefined4 colorAlpha;
  int glContextCopy;
  int r3AfterCall;
  int vertexIndex;
  uint enabledLightMask;
  uint lightIndex;
  int lightParams;
  int lightProducts;
  int material;
  int lightRecord;
  double fparam_1_00;
  double zeroThenShineFactor;
  double fparam_8_00;
  float normalDotLight;
  float colorB;
  float colorG;
  float colorR;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  
  vertexIndex = 0;
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  glContextCopy = glContext;
  if (vertexCount < 1) {
LAB_000d5ed8:
    return;
  }
LAB_000d5da0:
  if ((*(byte *)(vertex + 0x7e) & 4) != 0) {
    material = *(int *)(vertex + 0x78);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
    }
    colorR = (double)*(float *)(material + 0x1e8);
    lightProducts = material + 0x50;
    colorG = (double)*(float *)(material + 0x1ec);
    colorB = (double)*(float *)(material + 0x1f0);
    lightIndex = 0;
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    lightParams = glContext + 0x2820;
    lightRecord = glContext + 0x4a70;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d5eb8;
      }
      else {
        fparam_8_00 = (double)*(float *)(vertex + 0x48);
        zeroThenShineFactor = (double)FLOAT_00108e50;
        normalDotLight = (double)(float)(fparam_8_00 * (double)*(float *)(lightRecord + 0x14) +
                                (double)(*(float *)(vertex + 0x40) * *(float *)(lightRecord + 0xc) +
                                        *(float *)(vertex + 0x44) * *(float *)(lightRecord + 0x10)));
        if (zeroThenShineFactor < -(double)normalDotLight) {
          colorR = -(double)(normalDotLight * *(float *)(lightProducts + 0x10) - colorR);
          colorG = -(double)(normalDotLight * *(float *)(lightProducts + 0x14) - colorG);
          fparam_1_00 = -(double)(float)(fparam_8_00 * (double)*(float *)(lightParams + 0x68) +
                                        (double)(*(float *)(vertex + 0x40) *
                                                 *(float *)(lightParams + 0x60) +
                                                *(float *)(vertex + 0x44) * *(float *)(lightParams + 100)
                                                ));
          colorB = -(double)(normalDotLight * *(float *)(lightProducts + 0x18) - colorB);
          if (zeroThenShineFactor < fparam_1_00) {
            zeroThenShineFactor = ((double (*)())_gleMaterialShinePow)(glContextCopy,material + 0x1e8,fparam_1_00,floatArg2,floatArg3,floatArg4,floatArg5,
                                floatArg6,zeroThenShineFactor,fparam_8_00,incomingStack_ffffff78,incomingStack_ffffff80,
                                incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98);
            colorR = (double)(float)(zeroThenShineFactor * (double)*(float *)(lightProducts + 0x20) + (double)colorR);
            colorG = (double)(float)(zeroThenShineFactor * (double)*(float *)(lightProducts + 0x24) + (double)colorG);
            colorB = (double)(float)(zeroThenShineFactor * (double)*(float *)(lightProducts + 0x28) + (double)colorB);
            glContextCopy = glContextCopy;
          }
        }
      }
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
    } while( true );
  }
  goto LAB_000d5ec8;
LAB_000d5eb8:
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d5ec8:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (vertexCount <= vertexIndex) goto LAB_000d5ed8;
  goto LAB_000d5da0;
}

/* _gleVtxLightRGBAFrontPtr @ 0xd5ee4 (1192 bytes) */
void _gleVtxLightRGBAFrontPtr(int glContext,int *vertexPtrCursor,int vertexCount,double fparam_1)
{
  float inverseWThenInverseDistance;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int forwardedGlContext;
  int r3AfterCall;
  int r3AfterCall1;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int material;
  int lightParams2;
  int lightProducts;
  int lightRecord;
  int vertex;
  double f1AfterCall;
  double f1AfterCall1;
  double spotFactorThenSpecularPower;
  double floatZero;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  float floatOne;
  float lightContributionG;
  float lightContributionR;
  float lightContributionB;
  float colorB;
  float colorG;
  float colorR;
  float lightAttenuation;
  int vertexCountCopy;
  double incomingStackWord_fffffee8;
  double incomingStackWord_fffffef0;
  double incomingStackWord_fffffef8;
  double incomingStackWord_ffffff00;
  double incomingStackWord_ffffff08;
  float eyePositionX;
  float eyePositionY;
  float eyePositionZ;
  float toLightX;
  float toLightY;
  float toLightZ;
  float halfX;
  float halfY;
  float halfZ;
  uint localViewer;
  float *minLightDistancePtr;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  forwardedGlContext = glContext;
  vertexCountCopy = vertexCount;
  if (vertexCount < 1) {
    return;
  }
LAB_000d5f28:
  vertex = *vertexPtrCursor;
  vertexPtrCursor = vertexPtrCursor + 1;
  if ((*(byte *)(vertex + 0x7e) & 2) != 0) {
    material = *(int *)(vertex + 0x74);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
          }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      inverseWThenInverseDistance = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyePositionX;
      eyePositionZ = *(float *)(vertex + 0x28) * inverseWThenInverseDistance;
      eyePositionX = *(float *)(vertex + 0x20) * inverseWThenInverseDistance;
      eyePositionY = *(float *)(vertex + 0x24) * inverseWThenInverseDistance;
    }
    colorR = (double)*(float *)(material + 0x1d0);
    colorG = (double)*(float *)(material + 0x1d4);
    lightIndex = 0;
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    minLightDistancePtr = &FLOAT_00108e80;
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d6360;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          toLightX = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall1 = ((double (*)())(*(code **)vectorNormalize))(glContext,&toLightX,&toLightX);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall1 < (double)*minLightDistancePtr)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
          }
          else {
            inverseWThenInverseDistance = (float)((double)floatOne / f1AfterCall1);
            lightAttenuation = (double)(floatOne / (*(float *)(lightParams2 + 0x2878) * inverseWThenInverseDistance * inverseWThenInverseDistance +
                                                      (*(float *)(lightParams2 + 0x2874) * inverseWThenInverseDistance +
                                                      *(float *)(lightParams2 + 0x2870))));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          toLightX = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (toLightX * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d6348;
          spotFactorThenSpecularPower = ((double (*)())_gleLightExponentPow)(forwardedGlContext,lightRecord + 0x4a70,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                              incomingFpr8,incomingStackWord_fffffee8,incomingStackWord_fffffef0,incomingStackWord_fffffef8,
                              incomingStackWord_ffffff00,incomingStackWord_ffffff08);
          lightAttenuation = (double)(float)((double)lightAttenuation * spotFactorThenSpecularPower);
        }
        if (localViewer == 0) {
          halfZ = (toLightZ + floatOne);
          halfX = toLightX;
          halfY = toLightY;
        }
        else {
          halfX = -*eyePosition;
          halfY = -eyePosition[1];
          halfZ = -eyePosition[2];
          (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
          halfX = halfX + toLightX;
          halfY = halfY + toLightY;
          halfZ = halfZ + toLightZ;
        }
        f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
        floatZero = (double)FLOAT_00108e50;
        fparam_1 = f1AfterCall2;
        if ((double)lightAttenuation != floatZero) {
          incomingFpr8 = (double)*(float *)(vertex + 0x40);
          incomingFpr7 = (double)*(float *)(vertex + 0x48);
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          fparam_1 = (double)(float)(incomingFpr7 * (double)toLightZ +
                                    (double)(float)(incomingFpr8 * (double)toLightX +
                                                   (double)(*(float *)(vertex + 0x44) * toLightY)));
          if (floatZero < fparam_1) {
            lightContributionB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x68) + (double)lightContributionB);
            lightContributionR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x60) + (double)lightContributionR);
            lightContributionG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 100) + (double)lightContributionG);
            fparam_1 = (double)(float)(incomingFpr7 * (double)halfZ +
                                      (double)(float)(incomingFpr8 * (double)halfX +
                                                     (double)(*(float *)(vertex + 0x44) * halfY))
                                      );
            if (floatZero < fparam_1) {
              incomingFpr2 = (double)*(float *)(material + 0x40);
              spotFactorThenSpecularPower = _pow(fparam_1,incomingFpr2);
              fparam_1 = (double)(float)spotFactorThenSpecularPower;
              lightContributionB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)lightContributionB);
              lightContributionR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)lightContributionR);
              lightContributionG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)lightContributionG);
              forwardedGlContext = r3AfterCall1;
            }
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
          }
          else {
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
          }
        }
      }
      else {
        incomingFpr8 = (double)*(float *)(vertex + 0x48);
        incomingFpr7 = (double)FLOAT_00108e50;
        fparam_1 = (double)(float)(incomingFpr8 * (double)*(float *)(lightRecord + 0x4a84) +
                                  (double)(*(float *)(vertex + 0x40) * *(float *)(lightRecord + 0x4a7c) +
                                          *(float *)(vertex + 0x44) * *(float *)(lightRecord + 0x4a80)));
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if (incomingFpr7 < fparam_1) {
          colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x60) + (double)colorR);
          colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 100) + (double)colorG);
          colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x68) + (double)colorB);
          fparam_1 = (double)(float)(incomingFpr8 * (double)*(float *)(lightParams + 0x2888) +
                                    (double)(*(float *)(vertex + 0x40) * *(float *)(lightParams + 0x2880)
                                            + *(float *)(vertex + 0x44) * *(float *)(lightParams + 0x2884)
                                            ));
          if (incomingFpr7 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(forwardedGlContext,material + 0x1e8,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                                  incomingFpr8,incomingStackWord_fffffee8,incomingStackWord_fffffef0,incomingStackWord_fffffef8,
                                  incomingStackWord_ffffff00,incomingStackWord_ffffff08);
            colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            forwardedGlContext = forwardedGlContext;
          }
        }
      }
LAB_000d6348:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d6370;
LAB_000d6360:
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
LAB_000d6370:
  vertexIndex = vertexIndex + 1;
  if (vertexCountCopy <= vertexIndex) {
    return;
  }
  goto LAB_000d5f28;
}

/* _gleVtxLightRGBABackPtr @ 0xd638c (1200 bytes) */
void _gleVtxLightRGBABackPtr(int glContext,int *vertexPtrCursor,int vertexCount,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9)
{
  float invW;
  float inverseDistance;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int glContextForCalls;
  int r3AfterCall;
  int r3AfterCall1;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int material;
  int lightParams2;
  int lightProducts;
  int lightRecord;
  int vertex;
  double f1AfterCall;
  double f1AfterCall1;
  double spotFactor;
  double specularPow;
  double normalDotLight;
  double f1AfterCall2;
  float normalDotDirection;
  float lightAttenuation;
  float floatOne;
  float lightContributionG;
  float lightContributionR;
  float lightContributionB;
  float colorB;
  float colorG;
  float colorR;
  int iStack00000020;
  double incomingStack_fffffee8;
  double incomingStack_fffffef0;
  double incomingStack_fffffef8;
  double incomingStack_ffffff00;
  double incomingStack_ffffff08;
  float eyeX;
  float eyeY;
  float eyeZ;
  float toLightX;
  float toLightY;
  float toLightZ;
  float halfX;
  float halfY;
  float halfZ;
  uint localViewer;
  float *distanceThresholdPtr;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  glContextForCalls = glContext;
  iStack00000020 = vertexCount;
  if (vertexCount < 1) {
    return;
  }
LAB_000d63d0:
  vertex = *vertexPtrCursor;
  vertexPtrCursor = vertexPtrCursor + 1;
  if ((*(byte *)(vertex + 0x7e) & 4) != 0) {
    material = *(int *)(vertex + 0x78);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
          }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      invW = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyeX;
      eyeZ = *(float *)(vertex + 0x28) * invW;
      eyeX = *(float *)(vertex + 0x20) * invW;
      eyeY = *(float *)(vertex + 0x24) * invW;
    }
    colorR = (double)*(float *)(material + 0x1d0);
    colorG = (double)*(float *)(material + 0x1d4);
    lightIndex = 0;
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    distanceThresholdPtr = &FLOAT_00108e80;
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d6810;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          toLightX = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall1 = ((double (*)())(*(code **)vectorNormalize))(glContext,&toLightX,&toLightX);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall1 < (double)*distanceThresholdPtr)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
          }
          else {
            inverseDistance = (float)((double)floatOne / f1AfterCall1);
            lightAttenuation = (double)(floatOne / (*(float *)(lightParams2 + 0x2878) * inverseDistance * inverseDistance +
                                                      (*(float *)(lightParams2 + 0x2874) * inverseDistance +
                                                      *(float *)(lightParams2 + 0x2870))));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          toLightX = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          floatArg1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (toLightX * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (floatArg1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d67f8;
          spotFactor = ((double (*)())_gleLightExponentPow)(glContextForCalls,lightRecord + 0x4a70,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,
                              floatArg6,floatArg7,floatArg8,incomingStack_fffffee8,incomingStack_fffffef0,
                              incomingStack_fffffef8,incomingStack_ffffff00,incomingStack_ffffff08);
          lightAttenuation = (double)(float)((double)lightAttenuation * spotFactor);
        }
        if (localViewer == 0) {
          halfZ = (toLightZ + floatOne);
          halfX = toLightX;
          halfY = toLightY;
        }
        else {
          halfX = -*eyePosition;
          halfY = -eyePosition[1];
          halfZ = -eyePosition[2];
          (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
          halfX = halfX + toLightX;
          halfY = halfY + toLightY;
          halfZ = halfZ + toLightZ;
        }
        f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
        floatArg8 = (double)FLOAT_00108e50;
        floatArg1 = f1AfterCall2;
        if ((double)lightAttenuation != floatArg8) {
          floatArg7 = (double)*(float *)(vertex + 0x48);
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          normalDotLight = (double)(float)(floatArg7 * (double)toLightZ +
                                  (double)(*(float *)(vertex + 0x40) * toLightX +
                                          *(float *)(vertex + 0x44) * toLightY));
          floatArg1 = -normalDotLight;
          if (floatArg8 < floatArg1) {
            lightContributionR = -(double)(float)(normalDotLight * (double)*(float *)(lightProducts + 0x60) - (double)lightContributionR);
            lightContributionB = -(double)(float)(normalDotLight * (double)*(float *)(lightProducts + 0x68) - (double)lightContributionB);
            floatArg1 = -(double)(float)(floatArg7 * (double)halfZ +
                                       (double)(*(float *)(vertex + 0x40) * halfX +
                                               *(float *)(vertex + 0x44) * halfY));
            lightContributionG = -(double)(float)(normalDotLight * (double)*(float *)(lightProducts + 100) - (double)lightContributionG);
            if (floatArg8 < floatArg1) {
              floatArg2 = (double)*(float *)(material + 0x40);
              specularPow = _pow(floatArg1,floatArg2);
              floatArg1 = (double)(float)specularPow;
              lightContributionB = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x78) + (double)lightContributionB);
              lightContributionR = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x70) + (double)lightContributionR);
              lightContributionG = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x74) + (double)lightContributionG);
              glContextForCalls = r3AfterCall1;
            }
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
          }
          else {
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
          }
        }
      }
      else {
        floatArg8 = (double)*(float *)(vertex + 0x48);
        floatArg7 = (double)FLOAT_00108e50;
        normalDotDirection = (double)(float)(floatArg8 * (double)*(float *)(lightRecord + 0x4a84) +
                                (double)(*(float *)(vertex + 0x40) * *(float *)(lightRecord + 0x4a7c) +
                                        *(float *)(vertex + 0x44) * *(float *)(lightRecord + 0x4a80)));
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        floatArg1 = -(double)normalDotDirection;
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if (floatArg7 < floatArg1) {
          colorR = -(double)(normalDotDirection * *(float *)(lightProducts + 0x60) - colorR);
          colorG = -(double)(normalDotDirection * *(float *)(lightProducts + 100) - colorG);
          floatArg1 = -(double)(float)(floatArg8 * (double)*(float *)(lightParams + 0x2888) +
                                     (double)(*(float *)(vertex + 0x40) * *(float *)(lightParams + 0x2880)
                                             + *(float *)(vertex + 0x44) *
                                               *(float *)(lightParams + 0x2884)));
          colorB = -(double)(normalDotDirection * *(float *)(lightProducts + 0x68) - colorB);
          if (floatArg7 < floatArg1) {
            floatArg1 = ((double (*)())_gleMaterialShinePow)(glContextForCalls,material + 0x1e8,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,
                                  floatArg6,floatArg7,floatArg8,incomingStack_fffffee8,incomingStack_fffffef0,
                                  incomingStack_fffffef8,incomingStack_ffffff00,incomingStack_ffffff08);
            colorB = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            glContextForCalls = glContextForCalls;
          }
        }
      }
LAB_000d67f8:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d6820;
LAB_000d6810:
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
LAB_000d6820:
  vertexIndex = vertexIndex + 1;
  if (iStack00000020 <= vertexIndex) {
    return;
  }
  goto LAB_000d63d0;
}

/* _gleVtxLightSpecRGBAFrontPtr @ 0xd683c (1680 bytes) */
void _gleVtxLightSpecRGBAFrontPtr(int glContext,int vertexArray,int vertexCount,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8)
{
  float invW;
  float specularFactor;
  float doubleCrossZ;
  float doubleCrossY;
  float doubleCrossX;
  float specularDot;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int glContextForCalls;
  int extraout_r3;
  int extraout_r3_00;
  int r3AfterCall2;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int lightParams2;
  int material;
  int lightProducts;
  int lightRecord;
  int vertex;
  double extraout_f1;
  double f1AfterCall1;
  double f1AfterCall2;
  double f1AfterCall3;
  double normalDotLight;
  double specularR;
  double specularPow;
  double normalCrossLightYCopy;
  double dVar16;
  double lightAttenuation;
  float normalZ;
  float specularB;
  float normalCrossLightZCopy;
  float normalY;
  float floatOne;
  float specularSumB;
  float specularSumG;
  float floatZero;
  float specularSumR;
  float lightContributionB;
  float lightContributionG;
  float lightContributionR;
  float colorB;
  float colorG;
  float colorR;
  int iStack0000001c;
  double incomingStackWord_fffffea8;
  double incomingStackWord_fffffeb0;
  double incomingStackWord_fffffeb8;
  double incomingStackWord_fffffec0;
  double incomingStackWord_fffffec8;
  float eyeX;
  float eyeY;
  float eyeZ;
  float halfX;
  float halfY;
  float halfZ;
  float local_100;
  float directionalCrossY;
  float toLightY;
  float local_f8;
  float toLightZ;
  float normalCrossLightX;
  float normalCrossLightY;
  float normalCrossLightZ;
  float crossAdjustedLightX;
  float crossAdjustedLightY;
  float crossAdjustedLightZ;
  uint localViewer;
  float *distanceThresholdPtr;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  glContextForCalls = glContext;
  iStack0000001c = vertexArray;
  if (vertexCount < 1) {
    return;
  }
LAB_000d6880:
  vertex = *(int *)(iStack0000001c + vertexIndex * 4);
  if ((*(byte *)(vertex + 0x7e) & 2) != 0) {
    material = *(int *)(vertex + 0x74);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
          }
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      invW = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyeX;
      eyeZ = *(float *)(vertex + 0x28) * invW;
      eyeX = *(float *)(vertex + 0x20) * invW;
      eyeY = *(float *)(vertex + 0x24) * invW;
    }
    if (*(char *)(glContext + 0x30ae) != '\0') {
      if ((localViewer == 0) || (*(int *)(glContext + 0x4ddc) == 0)) {
        halfY = 0.0;
        halfZ = 1.0;
        halfX = 0.0;
      }
      else {
        halfX = -*eyePosition;
        halfY = -eyePosition[1];
        halfZ = -eyePosition[2];
        f1AfterCall1 = ((double (*)())(*(code **)PTR__gleVectorNormalize_00112064))(glContext,&halfX,&halfX);
        floatArg1 = f1AfterCall1;
      }
    }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    floatZero = (double)FLOAT_00108e50;
    colorR = (double)*(float *)(material + 0x1d0);
    lightIndex = 0;
    colorG = (double)*(float *)(material + 0x1d4);
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    distanceThresholdPtr = &FLOAT_00108e80;
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    specularSumB = (double)floatZero;
    specularSumG = (double)floatZero;
    specularSumR = (double)floatZero;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d6e74;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          local_100 = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&local_100,&local_100);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall2 < (double)*distanceThresholdPtr)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
            floatArg1 = f1AfterCall2;
          }
          else {
            floatArg1 = (double)(float)((double)floatOne / f1AfterCall2);
            lightAttenuation = (double)(floatOne / (float)((double)(float)((double)*(float *)(
                                                  lightParams2 + 0x2878) * floatArg1) * floatArg1 +
                                                  (double)(float)((double)*(float *)(lightParams2 + 0x2874
                                                                                    ) * floatArg1 +
                                                                 (double)*(float *)(lightParams2 + 0x2870)
                                                                 )));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          local_100 = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          floatArg1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (local_100 * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (floatArg1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d6e5c;
          floatArg1 = ((double (*)())_gleLightExponentPow)(glContextForCalls,lightRecord + 0x4a70,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,
                                floatArg6,floatArg7,floatArg8,incomingStackWord_fffffea8,incomingStackWord_fffffeb0,
                                incomingStackWord_fffffeb8,incomingStackWord_fffffec0,incomingStackWord_fffffec8);
          lightAttenuation = (double)(float)(lightAttenuation * floatArg1);
          glContextForCalls = glContextForCalls;
        }
        if (*(char *)(glContext + 0x30ae) == '\0') {
          if (localViewer == 0) {
            halfZ = (toLightZ + floatOne);
            halfX = local_100;
            halfY = toLightY;
          }
          else {
            halfX = -*eyePosition;
            halfY = -eyePosition[1];
            halfZ = -eyePosition[2];
            (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
            halfX = halfX + local_100;
            halfY = halfY + toLightY;
            halfZ = halfZ + toLightZ;
          }
          f1AfterCall3 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
          floatArg1 = f1AfterCall3;
        }
        if (lightAttenuation != (double)FLOAT_00108e50) {
          normalY = (double)*(float *)(vertex + 0x44);
          floatArg6 = (double)toLightY;
          floatArg7 = (double)local_100;
          normalZ = (double)*(float *)(vertex + 0x48);
          floatArg5 = (double)toLightZ;
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          normalDotLight = (double)(float)((double)normalZ * floatArg5 +
                                  (double)(float)((double)*(float *)(vertex + 0x40) * floatArg7 +
                                                 (double)(float)((double)normalY * floatArg6)));
          if ((double)FLOAT_00108e50 < normalDotLight) {
            lightContributionR = (double)(float)(normalDotLight * (double)*(float *)(lightProducts + 0x60) + (double)lightContributionR);
            lightContributionG = (double)(float)(normalDotLight * (double)*(float *)(lightProducts + 100) + (double)lightContributionG);
            lightContributionB = (double)(float)(normalDotLight * (double)*(float *)(lightProducts + 0x68) + (double)lightContributionB);
            if (*(char *)(glContext + 0x30ae) == '\0') {
              specularDot = (normalZ * halfZ + (*(float *)(vertex + 0x40) * halfX + (normalY * halfY)));
            }
            else {
              normalCrossLightX = (float)((double)normalY * floatArg5 - (double)(float)((double)normalZ * floatArg6));
              floatArg8 = (double)normalCrossLightX;
              normalCrossLightY = (float)((double)normalZ * floatArg7 -
                                (double)(float)((double)*(float *)(vertex + 0x40) * floatArg5));
              normalCrossLightYCopy = (double)normalCrossLightY;
              normalCrossLightZ = (float)((double)*(float *)(vertex + 0x40) * floatArg6 -
                                (double)(float)((double)*(float *)(vertex + 0x44) * floatArg7));
              normalCrossLightZCopy = (double)normalCrossLightZ;
              doubleCrossX = (*(float *)(vertex + 0x44) * normalCrossLightZCopy - (float)((double)*(float *)(vertex + 0x48) * normalCrossLightYCopy));
              crossAdjustedLightX = (float)((double)(doubleCrossX + doubleCrossX) + floatArg7);
              doubleCrossY = (float)((double)*(float *)(vertex + 0x48) * floatArg8 -
                             (double)(*(float *)(vertex + 0x40) * normalCrossLightZCopy));
              crossAdjustedLightY = (float)((double)(doubleCrossY + doubleCrossY) + floatArg6);
              doubleCrossZ = (float)((double)*(float *)(vertex + 0x40) * normalCrossLightYCopy -
                             (double)(float)((double)*(float *)(vertex + 0x44) * floatArg8));
              crossAdjustedLightZ = (float)((double)(doubleCrossZ + doubleCrossZ) + floatArg5);
              specularDot = crossAdjustedLightZ * halfZ + (crossAdjustedLightX * halfX + crossAdjustedLightY * halfY);
            }
            if (!((double)floatZero < (double)specularDot)) goto LAB_000d6e10;
            floatArg2 = (double)*(float *)(material + 0x40);
            specularPow = _pow((double)specularDot,floatArg2);
            specularFactor = (float)specularPow;
            specularB = (double)(specularFactor * *(float *)(lightProducts + 0x78));
            glContextForCalls = r3AfterCall2;
            floatArg1 = (double)(specularFactor * *(float *)(lightProducts + 0x74));
            specularR = (double)(specularFactor * *(float *)(lightProducts + 0x70));
          }
          else {
LAB_000d6e10:
            specularB = (double)FLOAT_00108e50;
            floatArg1 = (double)specularB;
            specularR = (double)specularB;
          }
          if (lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
            specularSumR = (double)(float)((double)specularSumR + specularR);
            specularSumG = (double)(float)((double)specularSumG + floatArg1);
            specularSumB = (double)(specularSumB + specularB);
          }
          else {
            specularSumB = (double)(float)(lightAttenuation * (double)specularB + (double)specularSumB);
            colorR = (double)(float)(lightAttenuation * (double)lightContributionR + (double)colorR);
            colorG = (double)(float)(lightAttenuation * (double)lightContributionG + (double)colorG);
            colorB = (double)(float)(lightAttenuation * (double)lightContributionB + (double)colorB);
            specularSumR = (double)(float)(lightAttenuation * specularR + (double)specularSumR);
            specularSumG = (double)(float)(lightAttenuation * floatArg1 + (double)specularSumG);
          }
        }
      }
      else {
        floatArg8 = (double)*(float *)(vertex + 0x44);
        floatArg7 = (double)*(float *)(lightRecord + 0x4a80);
        dVar16 = (double)*(float *)(lightRecord + 0x4a84);
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        floatArg1 = (double)(float)((double)*(float *)(vertex + 0x48) * dVar16 +
                                  (double)(*(float *)(vertex + 0x40) * *(float *)(lightRecord + 0x4a7c) +
                                          (float)(floatArg8 * floatArg7)));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if ((double)floatZero < floatArg1) {
          colorR = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x60) + (double)colorR);
          colorG = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 100) + (double)colorG);
          colorB = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x68) + (double)colorB);
          if (*(char *)(glContext + 0x30ae) == '\0') {
            dVar16 = (double)*(float *)(vertex + 0x48) * (double)*(float *)(lightParams + 0x2888) +
                     (double)(*(float *)(vertex + 0x40) * *(float *)(lightParams + 0x2880) +
                             (float)(floatArg8 * (double)*(float *)(lightParams + 0x2884)));
          }
          else {
            local_f8 = *(float *)(lightRecord + 0x4a84);
            local_100 = (float)(floatArg8 * dVar16 -
                               (double)(float)((double)*(float *)(vertex + 0x48) * floatArg7));
            directionalCrossY = (*(float *)(vertex + 0x48) * *(float *)(lightRecord + 0x4a7c) - (float)((double)*(float *)(vertex + 0x40) * dVar16));
            doubleCrossZ = (*(float *)(vertex + 0x40) * directionalCrossY - (*(float *)(vertex + 0x44) * local_100));
            dVar16 = (double)(doubleCrossZ + doubleCrossZ) + dVar16;
          }
          floatArg1 = (double)(float)dVar16;
          if ((double)floatZero < floatArg1) {
            floatArg1 = ((double (*)())_gleMaterialShinePow)(glContextForCalls,material + 0x1e8,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,
                                  floatArg6,floatArg7,floatArg8,incomingStackWord_fffffea8,incomingStackWord_fffffeb0,
                                  incomingStackWord_fffffeb8,incomingStackWord_fffffec0,incomingStackWord_fffffec8);
            colorB = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            glContextForCalls = glContextForCalls;
          }
        }
      }
LAB_000d6e5c:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d6eb4;
LAB_000d6e74:
  if (*(short *)(glContext + 0x30a8) == -0x7e06) {
    *(float *)(vertex + 0x50) = (float)(double)specularSumR;
    *(float *)(vertex + 0x54) = (float)(double)specularSumG;
    *(float *)(vertex + 0x58) = (float)(double)specularSumB;
  }
  else {
    colorR = (double)(colorR + specularSumR);
    colorG = (double)(colorG + specularSumG);
    colorB = (double)(colorB + specularSumB);
  }
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
LAB_000d6eb4:
  vertexIndex = vertexIndex + 1;
  if (vertexCount <= vertexIndex) {
    return;
  }
  goto LAB_000d6880;
}

/* _gleVtxLightSpecRGBABackPtr @ 0xd6ecc (1688 bytes) */
void _gleVtxLightSpecRGBABackPtr(int glContext,int vertexArray,int vertexCount,double floatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double floatArg7,double floatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  float invW;
  float specularFactor;
  float doubleCrossZ;
  float doubleCrossX;
  float doubleCrossY;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int glContextForCalls;
  int extraout_r3;
  int extraout_r3_00;
  int r3AfterCall2;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int lightParams2;
  int material;
  int lightProducts;
  int lightRecord;
  int vertex;
  double extraout_f1;
  double f1AfterCall1;
  double f1AfterCall2;
  double f1AfterCall3;
  float directionalLightZ;
  float lightAttenuation;
  double dVar17;
  double normalDotDirection;
  double specularR;
  double lnCrossZCopy;
  float lnCrossYCopy;
  float normalDotLight;
  float normalY;
  float specularB;
  float lnCrossXCopy;
  float floatOne;
  float specularSumB;
  float specularSumG;
  float floatZero;
  float specularSumR;
  float lightContributionB;
  float lightContributionG;
  float lightContributionR;
  float colorB;
  float colorG;
  float colorR;
  int iStack0000001c;
  int iStack00000020;
  double incomingStack_fffffea8;
  double incomingStack_fffffeb0;
  double incomingStack_fffffeb8;
  double incomingStack_fffffec0;
  double incomingStack_fffffec8;
  float eyeX;
  float eyeY;
  float eyeZ;
  float halfX;
  float halfY;
  float halfZ;
  float local_100;
  float directionalCrossY;
  float toLightY;
  float local_f8;
  float toLightZ;
  float lnCrossX;
  float lnCrossY;
  float lnCrossZ;
  float crossAdjustedLightX;
  float crossAdjustedLightY;
  float crossAdjustedLightZ;
  uint localViewer;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  glContextForCalls = glContext;
  iStack0000001c = vertexArray;
  iStack00000020 = vertexCount;
  if (vertexCount < 1) {
    return;
  }
LAB_000d6f10:
  vertex = *(int *)(iStack0000001c + vertexIndex * 4);
  if ((*(byte *)(vertex + 0x7e) & 4) != 0) {
    material = *(int *)(vertex + 0x78);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
          }
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      invW = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyeX;
      eyeZ = *(float *)(vertex + 0x28) * invW;
      eyeX = *(float *)(vertex + 0x20) * invW;
      eyeY = *(float *)(vertex + 0x24) * invW;
    }
    if (*(char *)(glContext + 0x30ae) != '\0') {
      if ((localViewer == 0) || (*(int *)(glContext + 0x4ddc) == 0)) {
        halfY = 0.0;
        halfZ = 1.0;
        halfX = 0.0;
      }
      else {
        halfX = -*eyePosition;
        halfY = -eyePosition[1];
        halfZ = -eyePosition[2];
        f1AfterCall1 = ((double (*)())(*(code **)PTR__gleVectorNormalize_00112064))(glContext,&halfX,&halfX);
        floatArg1 = f1AfterCall1;
      }
    }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    floatZero = (double)FLOAT_00108e50;
    colorR = (double)*(float *)(material + 0x1d0);
    lightIndex = 0;
    colorG = (double)*(float *)(material + 0x1d4);
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    specularSumB = (double)floatZero;
    specularSumG = (double)floatZero;
    specularSumR = (double)floatZero;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d7508;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          local_100 = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&local_100,&local_100);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall2 < (double)FLOAT_00108e80)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
            floatArg1 = f1AfterCall2;
          }
          else {
            floatArg1 = (double)(float)((double)floatOne / f1AfterCall2);
            lightAttenuation = (double)(floatOne / (float)((double)(float)((double)*(float *)(
                                                  lightParams2 + 0x2878) * floatArg1) * floatArg1 +
                                                  (double)(float)((double)*(float *)(lightParams2 + 0x2874
                                                                                    ) * floatArg1 +
                                                                 (double)*(float *)(lightParams2 + 0x2870)
                                                                 )));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          local_100 = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          floatArg1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (local_100 * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (floatArg1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d74f0;
          floatArg1 = ((double (*)())_gleLightExponentPow)(glContextForCalls,lightRecord + 0x4a70,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,
                                floatArg6,floatArg7,floatArg8,incomingStack_fffffea8,incomingStack_fffffeb0,
                                incomingStack_fffffeb8,incomingStack_fffffec0,incomingStack_fffffec8);
          lightAttenuation = (double)(float)((double)lightAttenuation * floatArg1);
          glContextForCalls = glContextForCalls;
        }
        if (*(char *)(glContext + 0x30ae) == '\0') {
          if (localViewer == 0) {
            halfZ = (toLightZ + floatOne);
            halfX = local_100;
            halfY = toLightY;
          }
          else {
            halfX = -*eyePosition;
            halfY = -eyePosition[1];
            halfZ = -eyePosition[2];
            (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
            halfX = halfX + local_100;
            halfY = halfY + toLightY;
            halfZ = halfZ + toLightZ;
          }
          f1AfterCall3 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
          floatArg1 = f1AfterCall3;
        }
        if ((double)lightAttenuation != (double)FLOAT_00108e50) {
          dVar17 = (double)*(float *)(vertex + 0x44);
          floatArg5 = (double)toLightY;
          floatArg4 = (double)*(float *)(vertex + 0x40);
          floatArg7 = (double)local_100;
          floatArg8 = (double)*(float *)(vertex + 0x48);
          floatArg6 = (double)toLightZ;
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          normalDotLight = (double)(float)(floatArg8 * floatArg6 +
                                  (double)(float)(floatArg4 * floatArg7 +
                                                 (double)(float)(dVar17 * floatArg5)));
          if ((double)FLOAT_00108e50 < -(double)normalDotLight) {
            lightContributionR = -(double)(normalDotLight * *(float *)(lightProducts + 0x60) - lightContributionR);
            lightContributionG = -(double)(normalDotLight * *(float *)(lightProducts + 100) - lightContributionG);
            lightContributionB = -(double)(normalDotLight * *(float *)(lightProducts + 0x68) - lightContributionB);
            if (*(char *)(glContext + 0x30ae) == '\0') {
              dVar17 = -(double)(float)(floatArg8 * (double)halfZ +
                                       (double)(float)(floatArg4 * (double)halfX +
                                                      (double)(float)(dVar17 * (double)halfY)));
            }
            else {
              lnCrossX = (float)(floatArg8 * floatArg5 - (double)(float)(dVar17 * floatArg6));
              lnCrossXCopy = (double)lnCrossX;
              lnCrossY = (float)((double)*(float *)(vertex + 0x40) * floatArg6 -
                                (double)(float)(floatArg8 * floatArg7));
              lnCrossYCopy = (double)lnCrossY;
              lnCrossZ = (float)((double)*(float *)(vertex + 0x44) * floatArg7 -
                                (double)(float)((double)*(float *)(vertex + 0x40) * floatArg5));
              lnCrossZCopy = (double)lnCrossZ;
              doubleCrossX = (*(float *)(vertex + 0x48) * lnCrossYCopy - (float)((double)*(float *)(vertex + 0x44) * lnCrossZCopy));
              doubleCrossY = (float)((double)*(float *)(vertex + 0x40) * lnCrossZCopy -
                             (double)(*(float *)(vertex + 0x48) * lnCrossXCopy));
              crossAdjustedLightX = (float)((double)(doubleCrossX + doubleCrossX) + floatArg7);
              crossAdjustedLightY = (float)((double)(doubleCrossY + doubleCrossY) + floatArg5);
              doubleCrossZ = (*(float *)(vertex + 0x44) * lnCrossXCopy - (*(float *)(vertex + 0x40) * lnCrossYCopy));
              crossAdjustedLightZ = (float)((double)(doubleCrossZ + doubleCrossZ) + floatArg6);
              dVar17 = (double)(crossAdjustedLightZ * halfZ + (crossAdjustedLightX * halfX + crossAdjustedLightY * halfY));
            }
            if (!((double)floatZero < dVar17)) goto LAB_000d74a4;
            floatArg2 = (double)*(float *)(material + 0x40);
            dVar17 = _pow(dVar17,floatArg2);
            specularFactor = (float)dVar17;
            specularB = (double)(specularFactor * *(float *)(lightProducts + 0x78));
            glContextForCalls = r3AfterCall2;
            floatArg1 = (double)(specularFactor * *(float *)(lightProducts + 0x74));
            specularR = (double)(specularFactor * *(float *)(lightProducts + 0x70));
          }
          else {
LAB_000d74a4:
            specularB = (double)FLOAT_00108e50;
            floatArg1 = (double)specularB;
            specularR = (double)specularB;
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
            specularSumR = (double)(float)((double)specularSumR + specularR);
            specularSumG = (double)(float)((double)specularSumG + floatArg1);
            specularSumB = (double)(specularSumB + specularB);
          }
          else {
            specularSumB = (double)(lightAttenuation * specularB + specularSumB);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            specularSumR = (double)(float)((double)lightAttenuation * specularR + (double)specularSumR);
            specularSumG = (double)(float)((double)lightAttenuation * floatArg1 + (double)specularSumG);
          }
        }
      }
      else {
        normalY = (double)*(float *)(vertex + 0x44);
        floatArg6 = (double)*(float *)(lightRecord + 0x4a80);
        floatArg7 = (double)*(float *)(vertex + 0x40);
        floatArg8 = (double)*(float *)(vertex + 0x48);
        directionalLightZ = (double)*(float *)(lightRecord + 0x4a84);
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        normalDotDirection = (double)(float)(floatArg8 * (double)directionalLightZ +
                                (double)(float)(floatArg7 * (double)*(float *)(lightRecord + 0x4a7c) +
                                               (double)(float)((double)normalY * floatArg6)));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        floatArg1 = -normalDotDirection;
        if ((double)floatZero < floatArg1) {
          colorR = -(double)(float)(normalDotDirection * (double)*(float *)(lightProducts + 0x60) - (double)colorR);
          colorG = -(double)(float)(normalDotDirection * (double)*(float *)(lightProducts + 100) - (double)colorG);
          colorB = -(double)(float)(normalDotDirection * (double)*(float *)(lightProducts + 0x68) - (double)colorB);
          if (*(char *)(glContext + 0x30ae) == '\0') {
            floatArg1 = -(double)(float)(floatArg8 * (double)*(float *)(lightParams + 0x2888) +
                                       (double)(float)(floatArg7 *
                                                       (double)*(float *)(lightParams + 0x2880) +
                                                      (double)(normalY * *(float *)(
                                                  lightParams + 0x2884))));
          }
          else {
            local_f8 = *(float *)(lightRecord + 0x4a84);
            local_100 = (float)((double)*(float *)(vertex + 0x48) * floatArg6 -
                               (double)(normalY * directionalLightZ));
            directionalCrossY = (*(float *)(vertex + 0x40) * directionalLightZ - (*(float *)(vertex + 0x48) * *(float *)(lightRecord + 0x4a7c)));
            doubleCrossZ = *(float *)(vertex + 0x44) * local_100 -
                    (*(float *)(vertex + 0x40) * directionalCrossY);
            floatArg1 = (double)((doubleCrossZ + doubleCrossZ) + directionalLightZ);
          }
          if ((double)floatZero < floatArg1) {
            floatArg1 = ((double (*)())_gleMaterialShinePow)(glContextForCalls,material + 0x1e8,floatArg1,floatArg2,floatArg3,floatArg4,floatArg5,
                                  floatArg6,floatArg7,floatArg8,incomingStack_fffffea8,incomingStack_fffffeb0,
                                  incomingStack_fffffeb8,incomingStack_fffffec0,incomingStack_fffffec8);
            colorB = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(floatArg1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            glContextForCalls = glContextForCalls;
          }
        }
      }
LAB_000d74f0:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d7548;
LAB_000d7508:
  if (*(short *)(glContext + 0x30a8) == -0x7e06) {
    *(float *)(vertex + 0x50) = (float)(double)specularSumR;
    *(float *)(vertex + 0x54) = (float)(double)specularSumG;
    *(float *)(vertex + 0x58) = (float)(double)specularSumB;
  }
  else {
    colorR = (double)(colorR + specularSumR);
    colorG = (double)(colorG + specularSumG);
    colorB = (double)(colorB + specularSumB);
  }
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
LAB_000d7548:
  vertexIndex = vertexIndex + 1;
  if (iStack00000020 <= vertexIndex) {
    return;
  }
  goto LAB_000d6f10;
}

/* _gleVtxLightFastRGBAFrontPtr @ 0xd7564 (376 bytes) */
void _gleVtxLightFastRGBAFrontPtr(int glContext,int *vertexPtrCursor,int vertexCount,double unusedFloatArg1)
{
  undefined4 colorAlpha;
  int iVar2;
  int extraout_r3;
  int vertexIndex;
  uint enabledLightMask;
  uint lightIndex;
  int lightParams;
  int iVar7;
  int iVar8;
  int material;
  int iVar10;
  double dVar11;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double floatZero;
  double fparam_8;
  float dVar12;
  float dVar13;
  float dVar14;
  double incomingStack_ffffff68;
  double incomingStack_ffffff70;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  
  vertexIndex = 0;
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar2 = glContext;
  if (vertexCount < 1) {
LAB_000d76d0:
    return;
  }
LAB_000d7598:
  iVar7 = *vertexPtrCursor;
  vertexPtrCursor = vertexPtrCursor + 1;
  if ((*(byte *)(iVar7 + 0x7e) & 2) != 0) {
    material = *(int *)(iVar7 + 0x74);
    *(byte *)(iVar7 + 0x7e) = *(byte *)(iVar7 + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
    }
    dVar14 = (double)*(float *)(material + 0x1e8);
    iVar8 = material + 0x50;
    dVar13 = (double)*(float *)(material + 0x1ec);
    dVar12 = (double)*(float *)(material + 0x1f0);
    lightIndex = 0;
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    lightParams = glContext + 0x2820;
    iVar10 = glContext + 0x4a70;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d76b4;
      }
      else {
        fparam_8 = (double)*(float *)(iVar7 + 0x48);
        floatZero = (double)FLOAT_00108e50;
        dVar11 = (double)(float)(fparam_8 * (double)*(float *)(iVar10 + 0x14) +
                                (double)(*(float *)(iVar7 + 0x40) * *(float *)(iVar10 + 0xc) +
                                        *(float *)(iVar7 + 0x44) * *(float *)(iVar10 + 0x10)));
        if (floatZero < dVar11) {
          dVar13 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x14) + (double)dVar13);
          dVar12 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x18) + (double)dVar12);
          dVar14 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x10) + (double)dVar14);
          dVar11 = (double)(float)(fparam_8 * (double)*(float *)(lightParams + 0x68) +
                                  (double)(*(float *)(iVar7 + 0x40) * *(float *)(lightParams + 0x60) +
                                          *(float *)(iVar7 + 0x44) * *(float *)(lightParams + 100)));
          if (floatZero < dVar11) {
            dVar11 = ((double (*)())_gleMaterialShinePow)(iVar2,material + 0x1e8,dVar11,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,floatZero,
                                fparam_8,incomingStack_ffffff68,incomingStack_ffffff70,incomingStack_ffffff78,
                                incomingStack_ffffff80,incomingStack_ffffff88);
            dVar14 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x20) + (double)dVar14);
            dVar13 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x24) + (double)dVar13);
            dVar12 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x28) + (double)dVar12);
            iVar2 = iVar2;
          }
        }
      }
      lightIndex = lightIndex + 1;
      iVar10 = iVar10 + 0x6c;
      iVar8 = iVar8 + 0x30;
      lightParams = lightParams + 0x80;
    } while( true );
  }
  goto LAB_000d76c4;
LAB_000d76b4:
  *(undefined4 *)(iVar7 + 0x3c) = colorAlpha;
  *(float *)(iVar7 + 0x30) = (float)(double)dVar14;
  *(float *)(iVar7 + 0x34) = (float)(double)dVar13;
  *(float *)(iVar7 + 0x38) = (float)(double)dVar12;
LAB_000d76c4:
  vertexIndex = vertexIndex + 1;
  if (vertexCount <= vertexIndex) goto LAB_000d76d0;
  goto LAB_000d7598;
}

/* _gleVtxLightFastRGBABackPtr @ 0xd76dc (380 bytes) */
void _gleVtxLightFastRGBABackPtr(int glContext,int *vertexPtrCursor,int vertexCount,double unusedFloatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9)
{
  undefined4 colorAlpha;
  int forwardedGlContext;
  int r3AfterCall;
  int vertexIndex;
  uint enabledLightMask;
  uint lightIndex;
  int lightParams;
  int vertex;
  int lightProducts;
  int material;
  int lightCache;
  double negatedNormalDotHalf;
  double floatZeroThenShinePow;
  double normalZ;
  float normalDotLight;
  float colorB;
  float colorG;
  float colorR;
  double incomingStackWord_ffffff68;
  double incomingStackWord_ffffff70;
  double incomingStackWord_ffffff78;
  double incomingStackWord_ffffff80;
  double incomingStackWord_ffffff88;
  
  vertexIndex = 0;
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  forwardedGlContext = glContext;
  if (vertexCount < 1) {
LAB_000d784c:
    return;
  }
LAB_000d7710:
  vertex = *vertexPtrCursor;
  vertexPtrCursor = vertexPtrCursor + 1;
  if ((*(byte *)(vertex + 0x7e) & 4) != 0) {
    material = *(int *)(vertex + 0x78);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
    }
    colorR = (double)*(float *)(material + 0x1e8);
    lightProducts = material + 0x50;
    colorG = (double)*(float *)(material + 0x1ec);
    colorB = (double)*(float *)(material + 0x1f0);
    lightIndex = 0;
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    lightParams = glContext + 0x2820;
    lightCache = glContext + 0x4a70;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d7830;
      }
      else {
        normalZ = (double)*(float *)(vertex + 0x48);
        floatZeroThenShinePow = (double)FLOAT_00108e50;
        normalDotLight = (double)(float)(normalZ * (double)*(float *)(lightCache + 0x14) +
                                (double)(*(float *)(vertex + 0x40) * *(float *)(lightCache + 0xc) +
                                        *(float *)(vertex + 0x44) * *(float *)(lightCache + 0x10)));
        if (floatZeroThenShinePow < -(double)normalDotLight) {
          colorR = -(double)(normalDotLight * *(float *)(lightProducts + 0x10) - colorR);
          colorG = -(double)(normalDotLight * *(float *)(lightProducts + 0x14) - colorG);
          negatedNormalDotHalf = -(double)(float)(normalZ * (double)*(float *)(lightParams + 0x68) +
                                        (double)(*(float *)(vertex + 0x40) * *(float *)(lightParams + 0x60)
                                                + *(float *)(vertex + 0x44) * *(float *)(lightParams + 100)
                                                ));
          colorB = -(double)(normalDotLight * *(float *)(lightProducts + 0x18) - colorB);
          if (floatZeroThenShinePow < negatedNormalDotHalf) {
            floatZeroThenShinePow = ((double (*)())_gleMaterialShinePow)(forwardedGlContext,material + 0x1e8,negatedNormalDotHalf,floatArg2,floatArg3,floatArg4,floatArg5,
                                floatArg6,floatZeroThenShinePow,normalZ,incomingStackWord_ffffff68,incomingStackWord_ffffff70,
                                incomingStackWord_ffffff78,incomingStackWord_ffffff80,incomingStackWord_ffffff88);
            colorR = (double)(float)(floatZeroThenShinePow * (double)*(float *)(lightProducts + 0x20) + (double)colorR);
            colorG = (double)(float)(floatZeroThenShinePow * (double)*(float *)(lightProducts + 0x24) + (double)colorG);
            colorB = (double)(float)(floatZeroThenShinePow * (double)*(float *)(lightProducts + 0x28) + (double)colorB);
            forwardedGlContext = forwardedGlContext;
          }
        }
      }
      lightIndex = lightIndex + 1;
      lightCache = lightCache + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
    } while( true );
  }
  goto LAB_000d7840;
LAB_000d7830:
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
LAB_000d7840:
  vertexIndex = vertexIndex + 1;
  if (vertexCount <= vertexIndex) goto LAB_000d784c;
  goto LAB_000d7710;
}

/* _gleBeginLinesRenderSmooth @ 0xd7858 (52 bytes) */
void _gleBeginLinesRenderSmooth(glContext)
  int glContext;
{
  undefined *flushAtomicFunc;
  
  flushAtomicFunc = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderSmoothLinesFunc_00112220;
  return;
}

/* _gleBeginLinesRenderFlat @ 0xd788c (52 bytes) */
void _gleBeginLinesRenderFlat(glContext)
  int glContext;
{
  undefined *flushAtomicFunc;
  
  flushAtomicFunc = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderFlatLinesFunc_0011221c;
  return;
}

/* _gleBeginLinesRenderTCL @ 0xd78c0 (52 bytes) */
void _gleBeginLinesRenderTCL(glContext)
  int glContext;
{
  undefined *flushAtomicTCLFunc;
  
  flushAtomicTCLFunc = PTR__gleFlushAtomicTCLFunc_00112218;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicTCLFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderLinesTCLFunc_00112214;
  return;
}

