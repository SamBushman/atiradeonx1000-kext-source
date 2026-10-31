#include "decls.h"

/* _BitSetXorEquals @ 0x97c08238 (128 bytes) */
int _BitSetXorEquals(bitSet, otherBitSet)
  undefined4 *bitSet;
  undefined4 *otherBitSet;
{
  int byteOffset;
  int wordIndex;
  uint wordsLeft;
  
  _BitSetExpandEquals(bitSet,*otherBitSet);
  _BitSetExpandEquals(otherBitSet,*bitSet);
  wordIndex = 0;
  for (wordsLeft = (uint)bitSet[1] >> 2; wordsLeft != 0; wordsLeft = wordsLeft - 1) {
    byteOffset = wordIndex * 4;
    wordIndex = wordIndex + 1;
    *(uint *)(byteOffset + bitSet[2]) = *(uint *)(byteOffset + bitSet[2]) ^ *(uint *)(byteOffset + otherBitSet[2]);
  }
  return bitSet;
}

/* _BitSetCopyEquals @ 0x97c082b8 (120 bytes) */
int _BitSetCopyEquals(bitSet, otherBitSet)
  undefined4 *bitSet;
  undefined4 *otherBitSet;
{
  int byteOffset;
  int wordIndex;
  uint wordsLeft;
  
  _BitSetExpandEquals(bitSet,*otherBitSet);
  _BitSetExpandEquals(otherBitSet,*bitSet);
  wordIndex = 0;
  for (wordsLeft = (uint)bitSet[1] >> 2; wordsLeft != 0; wordsLeft = wordsLeft - 1) {
    byteOffset = wordIndex * 4;
    wordIndex = wordIndex + 1;
    *(undefined4 *)(byteOffset + bitSet[2]) = *(undefined4 *)(byteOffset + otherBitSet[2]);
  }
  return bitSet;
}

/* _BitSetEqualsTest @ 0x97c08330 (144 bytes) */
int _BitSetEqualsTest(bitSet, otherBitSet)
  int *bitSet;
  undefined4 *otherBitSet;
{
  int bitSetEquals;
  int bitSetEquals2;
  int sizeInBits;
  undefined4 isEqual;
  int loopIndex;
  
  isEqual = 1;
  _BitSetExpandEquals(bitSet,*otherBitSet);
  loopIndex = 0;
  _BitSetExpandEquals(otherBitSet,*bitSet);
  sizeInBits = *bitSet;
  if (0 < sizeInBits) {
    do {
      bitSetEquals = _BitSetGetEquals(bitSet,loopIndex);
      bitSetEquals2 = _BitSetGetEquals(otherBitSet,loopIndex);
      if (bitSetEquals != bitSetEquals2) {
        isEqual = 0;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < sizeInBits);
  }
  return isEqual;
}

/* _BitSetAndTest @ 0x97c083c0 (136 bytes) */
int _BitSetAndTest(bitSet, otherBitSet)
  int *bitSet;
  undefined4 *otherBitSet;
{
  uint bitSetEquals;
  uint otherBit;
  int sizeInBits;
  uint anyCommonBit;
  int bitIndex;
  int nextBitIndex;
  
  anyCommonBit = 0;
  _BitSetExpandEquals(bitSet,*otherBitSet);
  _BitSetExpandEquals(otherBitSet,*bitSet);
  sizeInBits = *bitSet;
  bitIndex = 0;
  if (0 < sizeInBits) {
    do {
      bitSetEquals = _BitSetGetEquals(bitSet,bitIndex);
      nextBitIndex = bitIndex + 1;
      otherBit = _BitSetGetEquals(otherBitSet,bitIndex);
      anyCommonBit = anyCommonBit | bitSetEquals & otherBit;
      bitIndex = nextBitIndex;
    } while (nextBitIndex < sizeInBits);
  }
  return anyCommonBit;
}

/* _BitSetAndNotTest @ 0x97c08448 (136 bytes) */
int _BitSetAndNotTest(bitSet, otherBitSet)
  int *bitSet;
  undefined4 *otherBitSet;
{
  uint bitSetEquals;
  uint bitSetEquals2;
  int sizeInBits;
  uint anyBitOnlyInThis;
  int bitIndex;
  int nextBitIndex;
  
  anyBitOnlyInThis = 0;
  _BitSetExpandEquals(bitSet,*otherBitSet);
  _BitSetExpandEquals(otherBitSet,*bitSet);
  sizeInBits = *bitSet;
  bitIndex = 0;
  if (0 < sizeInBits) {
    do {
      bitSetEquals = _BitSetGetEquals(bitSet,bitIndex);
      nextBitIndex = bitIndex + 1;
      bitSetEquals2 = _BitSetGetEquals(otherBitSet,bitIndex);
      anyBitOnlyInThis = anyBitOnlyInThis | bitSetEquals & ~bitSetEquals2;
      bitIndex = nextBitIndex;
    } while (nextBitIndex < sizeInBits);
  }
  return anyBitOnlyInThis;
}

/* _BitSetOrTest @ 0x97c084d0 (136 bytes) */
int _BitSetOrTest(bitSet, otherBitSet)
  int *bitSet;
  undefined4 *otherBitSet;
{
  uint bitSetEquals;
  uint bitSetEquals2;
  int sizeInBits;
  uint anyBitInEither;
  int bitIndex;
  int nextBitIndex;
  
  anyBitInEither = 0;
  _BitSetExpandEquals(bitSet,*otherBitSet);
  _BitSetExpandEquals(otherBitSet,*bitSet);
  sizeInBits = *bitSet;
  bitIndex = 0;
  if (0 < sizeInBits) {
    do {
      bitSetEquals = _BitSetGetEquals(bitSet,bitIndex);
      nextBitIndex = bitIndex + 1;
      bitSetEquals2 = _BitSetGetEquals(otherBitSet,bitIndex);
      anyBitInEither = anyBitInEither | bitSetEquals | bitSetEquals2;
      bitIndex = nextBitIndex;
    } while (nextBitIndex < sizeInBits);
  }
  return anyBitInEither;
}

/* _BitSetXorTest @ 0x97c08558 (136 bytes) */
int _BitSetXorTest(bitSet, otherBitSet)
  int *bitSet;
  undefined4 *otherBitSet;
{
  uint bitSetEquals;
  uint bitSetEquals2;
  int sizeInBits;
  uint anyDifferingBit;
  int bitIndex;
  int nextBitIndex;
  
  anyDifferingBit = 0;
  _BitSetExpandEquals(bitSet,*otherBitSet);
  _BitSetExpandEquals(otherBitSet,*bitSet);
  sizeInBits = *bitSet;
  bitIndex = 0;
  if (0 < sizeInBits) {
    do {
      bitSetEquals = _BitSetGetEquals(bitSet,bitIndex);
      nextBitIndex = bitIndex + 1;
      bitSetEquals2 = _BitSetGetEquals(otherBitSet,bitIndex);
      anyDifferingBit = anyDifferingBit | bitSetEquals ^ bitSetEquals2;
      bitIndex = nextBitIndex;
    } while (nextBitIndex < sizeInBits);
  }
  return anyDifferingBit;
}

/* _defaultHashFunction @ 0x97c085e0 (4 bytes) */
int _defaultHashFunction()
{
  return;
}

/* _defaultEqualsFunction @ 0x97c085e4 (8 bytes) */
int _defaultEqualsFunction(key1, key2)
  int key1;
  int key2;
{
  return key1 - key2;
}

/* _HashSetNew @ 0x97c085ec (192 bytes) */
int _HashSetNew(bucketCount, hashFunction, equalsFunction)
  uint bucketCount;
  uint hashFunction;
  uint equalsFunction;
{
  uint buckets;
  int bucketOffset;
  uint *hashSet;
  uint bucketBase;
  undefined4 bucketEntries;
  uint loopIndex;
  
  hashSet = (uint *)_malloc(0x10);
  if (hashFunction == 0) {
    hashFunction = DAT_a7b7bf70;
  }
  hashSet[2] = hashFunction;
  if (equalsFunction == 0) {
    equalsFunction = DAT_a7b7bf6c;
  }
  hashSet[3] = equalsFunction;
  *hashSet = bucketCount;
  buckets = _malloc(bucketCount << 3);
  loopIndex = 0;
  hashSet[1] = buckets;
  if (*hashSet != 0) {
    do {
      bucketBase = hashSet[1];
      bucketOffset = loopIndex * 8;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(bucketBase + bucketOffset) = 0;
      bucketEntries = _malloc(4);
      *(undefined4 *)(bucketBase + bucketOffset + 4) = bucketEntries;
    } while (loopIndex < *hashSet);
  }
  return hashSet;
}

/* _HashSetFree @ 0x97c086ac (132 bytes) */
int _HashSetFree(hashSet)
  uint *hashSet;
{
  uint buckets;
  int bucketEntries;
  uint bucketCount;
  uint loopIndex;
  
  loopIndex = 0;
  bucketCount = *hashSet;
  if (bucketCount == 0) {
    buckets = hashSet[1];
  }
  else {
    buckets = hashSet[1];
    do {
      bucketEntries = *(int *)(buckets + loopIndex * 8 + 4);
      if (bucketEntries != 0) {
        _free(bucketEntries);
        bucketCount = *hashSet;
        buckets = hashSet[1];
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < bucketCount);
  }
  if (buckets != 0) {
    _free(buckets);
  }
  return _free(hashSet);
}

/* _HashSetAdd @ 0x97c08730 (272 bytes) */
int _HashSetAdd(hashSet, element)
  uint *hashSet;
  undefined4 element;
{
  uint oldEntryCount;
  int equalsResult;
  int entry;
  uint bucketEntries;
  uint grownEntries;
  uint hashCode;
  int bucketOffset;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
  uint buckets;
  uint firstFreeSlot;
  uint loopIndex;
  uint *bucket;
  
  loopIndex = 0;
  firstFreeSlot = 0xffffffff;
  hashCode = (*(code *)hashSet[2])(element,element);
  buckets = hashSet[1];
  bucketOffset = (hashCode - (hashCode / *hashSet) * *hashSet) * 8;
  bucket = (uint *)(buckets + bucketOffset);
  if (*(int *)(buckets + bucketOffset) == 0) {
    bucketEntries = bucket[1];
  }
  else {
    bucketEntries = bucket[1];
    do {
      entry = *(int *)(bucketEntries + loopIndex * 4);
      if (entry == 0) {
        if (firstFreeSlot == 0xffffffff) {
          firstFreeSlot = loopIndex;
        }
      }
      else {
        equalsResult = (*(code *)hashSet[3])(entry,element,unusedArg5,unusedArg6,unusedArg7,unusedArg8,buckets);
        if (equalsResult == 0) {
          *(undefined4 *)(bucketEntries + loopIndex * 4) = element;
          return hashSet;
        }
        bucketEntries = bucket[1];
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < *bucket);
  }
  if (firstFreeSlot == 0xffffffff) {
    oldEntryCount = *bucket;
    *bucket = oldEntryCount + 1;
    grownEntries = _realloc(bucketEntries,(oldEntryCount + 1) * 4);
    bucket[1] = grownEntries;
    *(undefined4 *)(grownEntries + *bucket * 4 + -4) = element;
  }
  else {
    *(undefined4 *)(bucketEntries + firstFreeSlot * 4) = element;
  }
  return hashSet;
}

/* _HashSetGet @ 0x97c08840 (176 bytes) */
int _HashSetGet(hashSet, element)
  uint *hashSet;
  undefined4 element;
{
  int equalsResult;
  int entry;
  int bucketOffset;
  uint bucketEntries;
  uint hashCode;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
  uint buckets;
  uint *bucket;
  uint loopIndex;
  
  loopIndex = 0;
  hashCode = (*(code *)hashSet[2])(element,element);
  buckets = hashSet[1];
  bucketOffset = (hashCode - (hashCode / *hashSet) * *hashSet) * 8;
  bucket = (uint *)(buckets + bucketOffset);
  if (*(int *)(buckets + bucketOffset) != 0) {
    do {
      bucketEntries = bucket[1];
      entry = *(int *)(bucketEntries + loopIndex * 4);
      if ((entry != 0) &&
         (equalsResult = (*(code *)hashSet[3])(entry,element,unusedArg5,unusedArg6,unusedArg7,unusedArg8,buckets), equalsResult == 0)) {
        return *(undefined4 *)(bucketEntries + loopIndex * 4);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < *bucket);
  }
  return 0;
}

/* _HashSetRemove @ 0x97c088f0 (184 bytes) */
int _HashSetRemove(hashSet, element)
  uint *hashSet;
  undefined4 element;
{
  int entryOffset;
  uint bucketEntries;
  int bucketOffset;
  undefined4 removedEntry;
  uint hashCode;
  int equalsResult;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
  uint buckets;
  uint *bucket;
  uint loopIndex;
  
  loopIndex = 0;
  hashCode = (*(code *)hashSet[2])(element,element);
  buckets = hashSet[1];
  bucketOffset = (hashCode - (hashCode / *hashSet) * *hashSet) * 8;
  bucket = (uint *)(buckets + bucketOffset);
  if (*(int *)(buckets + bucketOffset) != 0) {
    do {
      bucketEntries = bucket[1];
      entryOffset = loopIndex * 4;
      if ((*(int *)(bucketEntries + entryOffset) != 0) &&
         (equalsResult = (*(code *)hashSet[3])(*(int *)(bucketEntries + entryOffset),element,unusedArg5,unusedArg6,unusedArg7,unusedArg8,buckets),
         equalsResult == 0)) {
        removedEntry = *(undefined4 *)(bucketEntries + entryOffset);
        *(undefined4 *)(bucketEntries + entryOffset) = 0;
        return removedEntry;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < *bucket);
  }
  return 0;
}

/* _HashSetIteratorSetup @ 0x97c089a8 (24 bytes) */
int _HashSetIteratorSetup(hashSet, iterator)
  undefined4 hashSet;
  undefined4 *iterator;
{
  *iterator = hashSet;
  iterator[2] = 0;
  iterator[1] = 0;
  return iterator;
}

/* _HashSetIteratorNext @ 0x97c089c0 (160 bytes) */
int _HashSetIteratorNext(iterator)
  undefined4 *iterator;
{
  uint bucketEntries;
  uint bucketIndex;
  int entryOffset;
  uint *hashSet;
  uint *bucket;
  uint entryIndex;
  
  hashSet = (uint *)*iterator;
  bucketIndex = iterator[1];
  if (bucketIndex < *hashSet) {
    do {
      entryIndex = iterator[2];
      bucket = (uint *)(hashSet[1] + bucketIndex * 8);
      if (entryIndex < *(uint *)(hashSet[1] + bucketIndex * 8)) {
        entryOffset = entryIndex << 2;
        do {
          entryIndex = entryIndex + 1;
          bucketEntries = bucket[1];
          if (*(int *)(bucketEntries + entryOffset) != 0) {
            iterator[2] = entryIndex;
            return *(undefined4 *)(bucketEntries + entryOffset);
          }
          iterator[2] = entryIndex;
          entryOffset = entryOffset + 4;
        } while (entryIndex < *bucket);
      }
      iterator[2] = 0;
      bucketIndex = iterator[1] + 1;
      iterator[1] = bucketIndex;
    } while (bucketIndex < *hashSet);
  }
  return 0;
}

/* _HashTableNew @ 0x97c08a60 (84 bytes) */
int _HashTableNew(bucketCount, hashFunction, equalsFunction)
  undefined4 bucketCount;
  undefined4 hashFunction;
  undefined4 equalsFunction;
{
  undefined4 *hashTable;
  undefined4 hashSet;
  
  hashTable = (undefined4 *)_malloc(4);
  hashSet = ((int (*)())_HashSetNew)(bucketCount,hashFunction,equalsFunction);
  *hashTable = hashSet;
  return hashTable;
}

/* _HashTableFree @ 0x97c08ab4 (160 bytes) */
int _HashTableFree(hashTable)
  int *hashTable;
{
  uint *hashSet;
  int pair;
  uint bucketCount;
  uint bucketIndex;
  uint *bucket;
  uint entryIndex;
  
  bucketIndex = 0;
  hashSet = (uint *)*hashTable;
  bucketCount = *hashSet;
  if (bucketCount != 0) {
    do {
      entryIndex = 0;
      bucket = (uint *)(hashSet[1] + bucketIndex * 8);
      if (*(int *)(hashSet[1] + bucketIndex * 8) != 0) {
        do {
          pair = *(int *)(bucket[1] + entryIndex * 4);
          if (pair != 0) {
            _free(pair);
          }
          entryIndex = entryIndex + 1;
        } while (entryIndex < *bucket);
        bucketCount = *hashSet;
      }
      bucketIndex = bucketIndex + 1;
    } while (bucketIndex < bucketCount);
    hashSet = (uint *)*hashTable;
  }
  ((int (*)())_HashSetFree)(hashSet);
  return _free(hashTable);
}

/* _HashTableAdd @ 0x97c08b54 (336 bytes) */
int _HashTableAdd(hashTable, key, value)
  undefined4 *hashTable;
  undefined4 key;
  undefined4 value;
{
  uint oldEntryCount;
  int pair;
  int entriesEnd;
  int entryOffset;
  uint bucketEntries;
  uint grownEntries;
  int bucketOffset;
  uint hashCode;
  int equalsResult;
  undefined4 *newPair;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
  uint buckets;
  uint firstFreeSlot;
  uint *hashSet;
  uint loopIndex;
  uint *bucket;
  
  hashSet = (uint *)*hashTable;
  loopIndex = 0;
  firstFreeSlot = 0xffffffff;
  unusedArg5 = value;
  hashCode = (*(code *)hashSet[2])(key,key,value);
  buckets = hashSet[1];
  bucketOffset = (hashCode - (hashCode / *hashSet) * *hashSet) * 8;
  bucket = (uint *)(buckets + bucketOffset);
  if (*(int *)(buckets + bucketOffset) == 0) {
    bucketEntries = bucket[1];
  }
  else {
    bucketEntries = bucket[1];
    do {
      entryOffset = loopIndex * 4;
      if (*(undefined4 **)(bucketEntries + entryOffset) == (undefined4 *)0x0) {
        if (firstFreeSlot == 0xffffffff) {
          firstFreeSlot = loopIndex;
        }
      }
      else {
        equalsResult = (*(code *)hashSet[3])
                          (**(undefined4 **)(bucketEntries + entryOffset),key,unusedArg5,unusedArg6,unusedArg7,unusedArg8,buckets);
        if (equalsResult == 0) {
          **(undefined4 **)(bucketEntries + entryOffset) = key;
          *(undefined4 *)(*(int *)(bucketEntries + entryOffset) + 4) = value;
          return hashTable;
        }
        bucketEntries = bucket[1];
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < *bucket);
  }
  if (firstFreeSlot == 0xffffffff) {
    oldEntryCount = *bucket;
    *bucket = oldEntryCount + 1;
    grownEntries = _realloc(bucketEntries,(oldEntryCount + 1) * 4);
    bucket[1] = grownEntries;
    entriesEnd = grownEntries + *bucket * 4;
    newPair = (undefined4 *)_malloc(8);
    *(undefined4 **)(entriesEnd + -4) = newPair;
    *newPair = key;
    pair = *(int *)(entriesEnd + -4);
  }
  else {
    newPair = (undefined4 *)_malloc(8);
    *(undefined4 **)(bucketEntries + firstFreeSlot * 4) = newPair;
    *newPair = key;
    pair = *(int *)(bucketEntries + firstFreeSlot * 4);
  }
  *(undefined4 *)(pair + 4) = value;
  return hashTable;
}

/* _HashTableGet @ 0x97c08ca4 (184 bytes) */
int _HashTableGet(hashTable, key)
  undefined4 *hashTable;
  undefined4 key;
{
  int equalsResult;
  uint bucketEntries;
  uint hashCode;
  undefined4 *pair;
  int bucketOffset;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
  uint buckets;
  uint *hashSet;
  uint *bucket;
  uint loopIndex;
  
  loopIndex = 0;
  hashSet = (uint *)*hashTable;
  hashCode = (*(code *)hashSet[2])(key,key);
  buckets = hashSet[1];
  bucketOffset = (hashCode - (hashCode / *hashSet) * *hashSet) * 8;
  bucket = (uint *)(buckets + bucketOffset);
  if (*(int *)(buckets + bucketOffset) != 0) {
    do {
      bucketEntries = bucket[1];
      pair = *(undefined4 **)(bucketEntries + loopIndex * 4);
      if ((pair != (undefined4 *)0x0) &&
         (equalsResult = (*(code *)hashSet[3])(*pair,key,unusedArg5,unusedArg6,unusedArg7,unusedArg8,buckets), equalsResult == 0)) {
        return *(undefined4 *)(*(int *)(bucketEntries + loopIndex * 4) + 4);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < *bucket);
  }
  return 0;
}

/* _HashTableRemove @ 0x97c08d5c (196 bytes) */
int _HashTableRemove(hashTable, key, unusedArg3, unusedArg4, unusedArg5, unusedArg6)
  undefined4 *hashTable;
  undefined4 key;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
{
  int entryOffset;
  uint bucketEntries;
  int bucketOffset;
  uint hashCode;
  int equalsResult;
  uint buckets;
  uint *hashSet;
  uint *bucket;
  uint loopIndex;
  undefined4 removedValue;
  
  loopIndex = 0;
  hashSet = (uint *)*hashTable;
  hashCode = (*(code *)hashSet[2])(key,key,unusedArg3,unusedArg4,unusedArg5,unusedArg6);
  buckets = hashSet[1];
  bucketOffset = (hashCode - (hashCode / *hashSet) * *hashSet) * 8;
  bucket = (uint *)(buckets + bucketOffset);
  if (*(int *)(buckets + bucketOffset) != 0) {
    do {
      bucketEntries = bucket[1];
      entryOffset = loopIndex * 4;
      if ((*(undefined4 **)(bucketEntries + entryOffset) != (undefined4 *)0x0) &&
         (equalsResult = (*(code *)hashSet[3])
                            (**(undefined4 **)(bucketEntries + entryOffset),key,unusedArg3,unusedArg4,unusedArg5,
                             unusedArg6,buckets), equalsResult == 0)) {
        removedValue = *(undefined4 *)(*(int *)(bucketEntries + entryOffset) + 4);
        _free(*(int *)(bucketEntries + entryOffset));
        *(undefined4 *)(bucketEntries + entryOffset) = 0;
        return removedValue;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < *bucket);
  }
  return 0;
}

/* _GetValidArgs @ 0x97c08e20 (32 bytes) */
int _GetValidArgs(instruction)
  int instruction;
{
  uint sourceCount;
  
  sourceCount = *(uint *)(instruction + 0xc) >> 0x1d;
  if (3 < (*(uint *)(instruction + 0xc) >> 0x12 & 0xff) - 0x42) {
    return sourceCount;
  }
  return sourceCount - 1;
}

/* _GetStreamArray_97c08e40 @ 0x97c08e40 (164 bytes) */
int _GetStreamArray_97c08e40(listKind, registerNumber, stream, outRangeStart, outRangeEnd)
  int listKind;
  uint registerNumber;
  int stream;
  uint *outRangeStart;
  uint *outRangeEnd;
{
  int arrayChunk;
  int arrayIndex;
  uint rangeStart;
  
  arrayIndex = 0;
  if (listKind == 1) {
    for (arrayChunk = **(int **)(stream + 8); arrayChunk != 0; arrayChunk = *(int *)(arrayChunk + 8)) {
      rangeStart = (uint)*(ushort *)(arrayChunk + 0xe);
      if ((rangeStart <= registerNumber) && (registerNumber <= *(ushort *)(arrayChunk + 0x12))) {
loopStoreOutRangeStart:
        *outRangeStart = rangeStart;
        *outRangeEnd = (uint)*(ushort *)(arrayChunk + 0x12);
        return arrayIndex;
      }
      arrayIndex = arrayIndex + 1;
    }
  }
  else if (listKind == 2) {
    for (arrayChunk = **(int **)(stream + 0x14); arrayChunk != 0; arrayChunk = *(int *)(arrayChunk + 8)) {
      rangeStart = (uint)*(ushort *)(arrayChunk + 0xe);
      if ((rangeStart <= registerNumber) && (registerNumber <= *(ushort *)(arrayChunk + 0x12))) goto loopStoreOutRangeStart;
      arrayIndex = arrayIndex + 1;
    }
  }
  return -1;
}

/* _GetRegisterIndicies @ 0x97c08ee4 (168 bytes) */
int _GetRegisterIndicies(stream, outFirstIndex, outLastIndex, listKind, registerNumber, isIndirect, isArray, arrayExtent)
  undefined4 stream;
  int *outFirstIndex;
  int *outLastIndex;
  undefined4 listKind;
  int registerNumber;
  int isIndirect;
  int isArray;
  int arrayExtent;
{
  int lastIndex;
  
  *outFirstIndex = 0;
  *outLastIndex = -1;
  if (isIndirect != 0) {
    ((int (*)())_GetStreamArray_97c08e40)(listKind,registerNumber,stream,outFirstIndex,outLastIndex);
  }
  lastIndex = *outLastIndex;
  if (((lastIndex == -1) && (isArray != 0)) && (1 < arrayExtent + 1)) {
    lastIndex = registerNumber + arrayExtent;
    *outFirstIndex = registerNumber;
    *outLastIndex = lastIndex;
  }
  if (lastIndex == -1) {
    *outFirstIndex = registerNumber;
    *outLastIndex = registerNumber;
  }
  return;
}

/* _GetRegister @ 0x97c08f8c (160 bytes) */
int _GetRegister(program, bank, registerIndex, component)
  int program;
  undefined4 bank;
  int registerIndex;
  int component;
{
  uint recordIndex;
  uint bankEndRecord;
  int bankFirstRecord;
  
  bankFirstRecord = 0;
  bankEndRecord = 0;
  switch(bank) {
  case 0:
    bankFirstRecord = *(int *)(program + 0x24);
    bankEndRecord = *(uint *)(program + 0x38);
    break;
  case 1:
    bankFirstRecord = *(int *)(program + 0x20);
    bankEndRecord = *(uint *)(program + 0x34);
    break;
  case 2:
    bankFirstRecord = *(int *)(program + 0x28);
    bankEndRecord = *(uint *)(program + 0x3c);
    break;
  case 3:
    bankFirstRecord = *(int *)(program + 0x1c);
    bankEndRecord = *(uint *)(program + 0x30);
    break;
  case 4:
    bankFirstRecord = *(int *)(program + 0x2c);
    bankEndRecord = *(uint *)(program + 0x40);
  }
  recordIndex = bankFirstRecord + registerIndex * 4 + component;
  if (recordIndex < bankEndRecord) {
    return *(int *)(program + 0x10) + recordIndex * 0x2c;
  }
  return 0;
}

/* _BuildGenKill @ 0x97c09040 (364 bytes) */
int _BuildGenKill(program)
  int program;
{
  int instructionOffset;
  int blockInstructionCount;
  uint bitSetNewResult;
  uint sourceIndex;
  uint destCount;
  int isKilled;
  uint blockIndex;
  int blockOffset;
  uint instructionIndex;
  uint *block;
  uint *instruction;
  int blocks;
  undefined4 *reg;
  uint destIndex;
  
  blockIndex = 0;
  if (*(int *)(program + 4) != 0) {
    blockOffset = 0;
    do {
      blocks = *(int *)(program + 8);
      instructionIndex = 0;
      block = (uint *)(blocks + blockOffset);
      bitSetNewResult = _BitSetNew(*(undefined4 *)(program + 0xc));
      block[9] = bitSetNewResult;
      bitSetNewResult = _BitSetNew(*(undefined4 *)(program + 0xc));
      block[10] = bitSetNewResult;
      bitSetNewResult = _BitSetNew(*(undefined4 *)(program + 0xc));
      blockInstructionCount = *(int *)(blocks + blockOffset);
      block[6] = bitSetNewResult;
      if (blockInstructionCount != 0) {
        instructionOffset = 0;
        do {
          instruction = (uint *)(block[1] + instructionOffset);
          if (instruction[5] == 0) {
            sourceIndex = 0;
            if (*(int *)(block[1] + instructionOffset) != 0) {
              do {
                reg = *(undefined4 **)(sourceIndex * 4 + instruction[1]);
                if (reg[6] == 0) {
                  isKilled = _BitSetGetEquals(block[10],*reg);
                  if (isKilled == 0) {
                    _BitSetSetEquals(block[9],*reg);
                  }
                  reg[9] = reg[9] + 1;
                }
                sourceIndex = sourceIndex + 1;
              } while (sourceIndex < *instruction);
            }
            destCount = instruction[2];
            destIndex = 0;
            if (destCount != 0) {
              do {
                reg = *(undefined4 **)(destIndex * 4 + instruction[3]);
                if (reg[6] == 0) {
                  _BitSetSetEquals(block[10],*reg);
                  reg[9] = reg[9] + 1;
                  destCount = instruction[2];
                }
                destIndex = destIndex + 1;
              } while (destIndex < destCount);
            }
          }
          instructionIndex = instructionIndex + 1;
          instructionOffset = instructionOffset + 0x1c;
        } while (instructionIndex < *block);
      }
      blockIndex = blockIndex + 1;
      blockOffset = blockOffset + 0x2c;
    } while (blockIndex < *(uint *)(program + 4));
  }
  return;
}

/* _BuildLiveOut @ 0x97c091ac (240 bytes) */
int _BuildLiveOut(program)
  int program;
{
  int successor;
  int liveOutUnchanged;
  uint successorIndex;
  bool anyChanged;
  uint blockCount;
  undefined4 oldLiveOut;
  undefined4 successorLive;
  uint blockIndex;
  int blockOffset;
  int successorOffset;
  int block;
  
  blockCount = *(uint *)(program + 4);
  do {
    anyChanged = false;
    blockIndex = 0;
    if (blockCount != 0) {
      blockOffset = 0;
      do {
        successorIndex = 0;
        block = *(int *)(program + 8) + blockOffset;
        oldLiveOut = _BitSetClone(*(undefined4 *)(block + 0x18));
        if (*(int *)(block + 0x10) != 0) {
          do {
            successorOffset = successorIndex * 4;
            successorIndex = successorIndex + 1;
            successor = *(int *)(successorOffset + *(int *)(block + 0x14));
            successorLive = _BitSetClone(*(undefined4 *)(successor + 0x18));
            _BitSetAndNotEquals(successorLive,*(undefined4 *)(successor + 0x28));
            _BitSetOrEquals(successorLive,*(undefined4 *)(successor + 0x24));
            _BitSetOrEquals(*(undefined4 *)(block + 0x18),successorLive);
            _BitSetFree(successorLive);
          } while (successorIndex < *(uint *)(block + 0x10));
        }
        blockIndex = blockIndex + 1;
        blockOffset = blockOffset + 0x2c;
        liveOutUnchanged = ((int (*)())_BitSetEqualsTest)(oldLiveOut,*(undefined4 *)(block + 0x18));
        anyChanged = (bool)(anyChanged | liveOutUnchanged == 0);
        _BitSetFree(oldLiveOut);
        blockCount = *(uint *)(program + 4);
      } while (blockIndex < blockCount);
    }
  } while (anyChanged);
  return;
}

/* _BuildInterferenceSets @ 0x97c0929c (436 bytes) */
int _BuildInterferenceSets(program)
  int program;
{
  uint sourceCount;
  int instructionIndex;
  undefined4 liveSet;
  int liveRegisterId;
  uint destCount;
  uint blockIndex;
  int blockOffset;
  int block;
  int instructionOffset;
  uint *instruction;
  undefined4 *reg;
  uint loopIndex;
  int blocks;
  int liveRegister;
  
  blockIndex = 0;
  if (*(int *)(program + 4) != 0) {
    blockOffset = 0;
    do {
      blocks = *(int *)(program + 8);
      block = blocks + blockOffset;
      liveSet = _BitSetClone(*(undefined4 *)(block + 0x18));
      instructionIndex = *(int *)(blocks + blockOffset) + -1;
      if (-1 < instructionIndex) {
        instructionOffset = instructionIndex * 0x1c;
        do {
          instruction = (uint *)(*(int *)(block + 4) + instructionOffset);
          if (instruction[5] == 0) {
            destCount = instruction[2];
            loopIndex = 0;
            if (destCount != 0) {
              do {
                reg = *(undefined4 **)(loopIndex * 4 + instruction[3]);
                if (reg[6] == 0) {
                  for (liveRegisterId = _BitSetFirstSetBit(liveSet); liveRegisterId != -1;
                      liveRegisterId = _BitSetNextSetBit(liveSet,liveRegisterId)) {
                    liveRegister = *(int *)(program + 0x10) + liveRegisterId * 0x2c;
                    if (*(int *)(liveRegister + 0x18) == 0) {
                      _BitSetSetEquals(reg[2],
                                       *(undefined4 *)(*(int *)(program + 0x10) + liveRegisterId * 0x2c));
                      _BitSetSetEquals(*(undefined4 *)(liveRegister + 8),*reg);
                    }
                  }
                  destCount = instruction[2];
                }
                loopIndex = loopIndex + 1;
              } while (loopIndex < destCount);
            }
            loopIndex = 0;
            if (destCount != 0) {
              do {
                reg = *(undefined4 **)(loopIndex * 4 + instruction[3]);
                if (reg[6] == 0) {
                  _BitSetClearEquals(liveSet,*reg);
                  destCount = instruction[2];
                }
                loopIndex = loopIndex + 1;
              } while (loopIndex < destCount);
            }
            sourceCount = *instruction;
            loopIndex = 0;
            if (sourceCount != 0) {
              do {
                reg = *(undefined4 **)(loopIndex * 4 + instruction[1]);
                if (reg[6] == 0) {
                  _BitSetSetEquals(liveSet,*reg);
                  sourceCount = *instruction;
                }
                loopIndex = loopIndex + 1;
              } while (loopIndex < sourceCount);
            }
          }
          instructionIndex = instructionIndex + -1;
          instructionOffset = instructionOffset + -0x1c;
        } while (-1 < instructionIndex);
      }
      blockIndex = blockIndex + 1;
      _BitSetFree(liveSet);
      blockOffset = blockOffset + 0x2c;
    } while (blockIndex < *(uint *)(program + 4));
  }
  return;
}

/* _RegistersMerge @ 0x97c09450 (612 bytes) */
int _RegistersMerge(program)
  int program;
{
  int copyOffset;
  int keptChunk;
  int candidateRecordAddress;
  int componentOffset;
  int componentsLeft;
  int *keptVector;
  int *candidateCursor;
  uint mergedSize;
  int registerVectorCanMergeResult;
  int registerVectorIsFixedResult;
  undefined4 *keptSlot;
  bool merged;
  int recordAddress;
  int *firstVectorCursor;
  int replacements;
  undefined4 firstVectorStorage;
  int *keptVectors;
  int recordOffset;
  uint keptSize;
  uint keptChunkWord;
  int replacementCount;
  uint recordIndex;
  uint keptVectorCount;
  uint keptVectorIndex;
  int replacementsEnd;
  int componentsRemaining;
  int candidateVector [6];
  
  replacements = _malloc(8);
  replacementCount = 0;
  firstVectorStorage = _malloc(0x10);
  keptVectors = (int *)_realloc(firstVectorStorage,0x10);
  componentsRemaining = 4;
  keptVectorCount = 1;
  recordOffset = 0;
  firstVectorCursor = keptVectors;
  do {
    recordAddress = *(int *)(program + 0x10) + recordOffset;
    recordOffset = recordOffset + 0x2c;
    *firstVectorCursor = recordAddress;
    firstVectorCursor = firstVectorCursor + 1;
    componentsRemaining = componentsRemaining + -1;
  } while (componentsRemaining != 0);
  recordIndex = 4;
  if (4 < *(uint *)(program + 0xc)) {
    recordOffset = 0xb0;
    do {
      candidateRecordAddress = recordOffset + *(int *)(program + 0x10);
      componentsLeft = 4;
      candidateCursor = candidateVector;
      do {
        *candidateCursor = candidateRecordAddress;
        candidateCursor = candidateCursor + 1;
        candidateRecordAddress = candidateRecordAddress + 0x2c;
        componentsLeft = componentsLeft + -1;
      } while (componentsLeft != 0);
      merged = false;
      registerVectorIsFixedResult = ((int (*)())_RegisterVectorIsFixed)(candidateVector);
      if (registerVectorIsFixedResult == 0) {
        keptVectorIndex = 0;
        keptVector = keptVectors;
        if (keptVectorCount != 0) {
loopSetRegisterVectorCanMergeResult:
          registerVectorCanMergeResult = ((int (*)())_RegisterVectorCanMerge)(keptVector,candidateVector);
          if (registerVectorCanMergeResult == 0) goto setKeptVectorIndex;
          componentOffset = 0;
          componentsRemaining = 3;
          do {
            replacementCount = replacementCount + 1;
            _BitSetOrEquals(*(undefined4 *)(*(int *)(componentOffset + (int)keptVector) + 8),
                            *(undefined4 *)(*(int *)(componentOffset + (int)candidateVector) + 8));
            *(int *)(*(int *)(componentOffset + (int)keptVector) + 0x24) =
                 *(int *)(*(int *)(componentOffset + (int)keptVector) + 0x24) +
                 *(int *)(*(int *)(componentOffset + (int)candidateVector) + 0x24);
            *(undefined4 *)(*(int *)(componentOffset + (int)candidateVector) + 0x18) = 1;
            ((int (*)())_RegistersReInterfere)(program,*(undefined4 *)(componentOffset + (int)candidateVector),
                       *(undefined4 *)(componentOffset + (int)keptVector));
            replacements = _realloc(replacements,replacementCount * 8);
            replacementsEnd = replacements + replacementCount * 8;
            componentsRemaining = componentsRemaining + -1;
            *(undefined4 *)(replacementsEnd + -8) = *(undefined4 *)(componentOffset + (int)candidateVector);
            keptSlot = (undefined4 *)(componentOffset + (int)keptVector);
            componentOffset = componentOffset + 4;
            *(undefined4 *)(replacementsEnd + -4) = *keptSlot;
          } while (-1 < componentsRemaining);
          if ((*(int *)(*keptVector + 0x14) == 1) && (*(int *)(candidateVector[0] + 0x14) == 1)) {
            keptChunk = *(int *)(*keptVector + 0x28);
            keptChunkWord = *(uint *)(keptChunk + 0xc);
            mergedSize = *(uint *)(*(int *)(candidateVector[0] + 0x28) + 0xc) >> 0x18 & 3;
            keptSize = keptChunkWord >> 0x18 & 3;
            if (mergedSize < keptSize) {
              mergedSize = keptSize;
            }
            *(uint *)(keptChunk + 0xc) = mergedSize << 0x18 | keptChunkWord & 0xfcffffff;
          }
          merged = true;
        }
loopCheckMerged:
        if (!merged) goto setKeptVectorCount;
      }
      else {
setKeptVectorCount:
        keptVectorCount = keptVectorCount + 1;
        keptVectors = (int *)_realloc(keptVectors,keptVectorCount * 0x10);
        componentsLeft = 4;
        copyOffset = 0;
        do {
          *(undefined4 *)((int)keptVectors + copyOffset + keptVectorCount * 0x10 + -0x10) =
               *(undefined4 *)(copyOffset + (int)candidateVector);
          copyOffset = copyOffset + 4;
          componentsLeft = componentsLeft + -1;
        } while (componentsLeft != 0);
      }
      recordIndex = recordIndex + 4;
      recordOffset = recordOffset + 0xb0;
    } while (recordIndex < *(uint *)(program + 0xc));
  }
  if (keptVectors != (int *)0x0) {
    _free(keptVectors);
  }
  ((int (*)())_RegistersReplace)(program,replacementCount,replacements);
  if (replacements != 0) {
    _free(replacements);
  }
  return;
setKeptVectorIndex:
  keptVectorIndex = keptVectorIndex + 1;
  keptVector = keptVector + 4;
  if (keptVectorCount <= keptVectorIndex) goto loopCheckMerged;
  goto loopSetRegisterVectorCanMergeResult;
}

/* _DeadCodeEliminationSimple @ 0x97c096b4 (440 bytes) */
int _DeadCodeEliminationSimple(program)
  undefined4 *program;
{
  uint sourceCount;
  int instructionIndex;
  uint registerIndex;
  bool isDead;
  undefined4 liveSet;
  int isLive;
  undefined4 *reg;
  uint destCount;
  uint blockIndex;
  int blockOffset;
  int block;
  int instructionOffset;
  int blocks;
  uint destIndex;
  uint *instruction;
  
  blockIndex = 0;
  if (program[1] != 0) {
    blockOffset = 0;
    do {
      blocks = program[2];
      block = blocks + blockOffset;
      liveSet = _BitSetClone(*(undefined4 *)(block + 0x18));
      instructionIndex = *(int *)(blocks + blockOffset) + -1;
      if (-1 < instructionIndex) {
        instructionOffset = instructionIndex * 0x1c;
        do {
          instruction = (uint *)(*(int *)(block + 4) + instructionOffset);
          if (instruction[5] == 0) {
            destCount = instruction[2];
            destIndex = 0;
            if (destCount == 0) {
              isDead = instruction[4] == 0;
loopCheckIsDead:
              if (isDead) {
                _PPStreamRemoveOperation(*program,instruction[6]);
                instruction[5] = 1;
                goto setInstructionIndex;
              }
            }
            else {
              isDead = instruction[4] == 0;
              if (isDead) {
                do {
                  reg = *(undefined4 **)(destIndex * 4 + instruction[3]);
                  if (reg[6] == 0) {
                    isLive = _BitSetGetEquals(liveSet,*reg);
                    if (isLive != 0) {
                      isDead = false;
                    }
                    destCount = instruction[2];
                  }
                  destIndex = destIndex + 1;
                  if (destCount <= destIndex) goto loopCheckIsDead;
                } while (isDead);
              }
            }
            registerIndex = 0;
            if (destCount != 0) {
              do {
                reg = *(undefined4 **)(registerIndex * 4 + instruction[3]);
                if (reg[6] == 0) {
                  _BitSetClearEquals(liveSet,*reg);
                  destCount = instruction[2];
                }
                registerIndex = registerIndex + 1;
              } while (registerIndex < destCount);
            }
            sourceCount = *instruction;
            registerIndex = 0;
            if (sourceCount != 0) {
              do {
                reg = *(undefined4 **)(registerIndex * 4 + instruction[1]);
                if (reg[6] == 0) {
                  _BitSetSetEquals(liveSet,*reg);
                  sourceCount = *instruction;
                }
                registerIndex = registerIndex + 1;
              } while (registerIndex < sourceCount);
            }
          }
setInstructionIndex:
          instructionIndex = instructionIndex + -1;
          instructionOffset = instructionOffset + -0x1c;
        } while (-1 < instructionIndex);
      }
      blockIndex = blockIndex + 1;
      _BitSetFree(liveSet);
      blockOffset = blockOffset + 0x2c;
    } while (blockIndex < (uint)program[1]);
  }
  return;
}

/* _RegistersReInterfere @ 0x97c0986c (140 bytes) */
int _RegistersReInterfere(program, mergedRegister, keptRegister)
  int program;
  undefined4 *mergedRegister;
  undefined4 *keptRegister;
{
  int interferingId;
  int interferingRegister;
  
  for (interferingId = _BitSetFirstSetBit(mergedRegister[2]); interferingId != -1;
      interferingId = _BitSetNextSetBit(mergedRegister[2],interferingId)) {
    interferingRegister = *(int *)(program + 0x10) + interferingId * 0x2c;
    if (*(int *)(interferingRegister + 0x18) == 0) {
      _BitSetClearEquals(*(undefined4 *)(interferingRegister + 8),*mergedRegister);
      _BitSetSetEquals(*(undefined4 *)(interferingRegister + 8),*keptRegister);
    }
  }
  return;
}

/* _RegistersReplace @ 0x97c098f8 (568 bytes) */
int _RegistersReplace(program, replacementCount, replacements)
  int *program;
  int replacementCount;
  int *replacements;
{
  uint destCount;
  uint sourceCount;
  int replacementsLeft;
  int instructionOffset;
  int blockOffset;
  int operandCount;
  uint *block;
  uint instructionIndex;
  int *replacementPair;
  uint *instruction;
  int operandIndex;
  int fromRegister;
  uint blockCount;
  uint loopIndex;
  int operand;
  int pairIndex;
  uint blockIndex;
  int operationChunk;
  
  for (operationChunk = **(int **)(*program + 0x20); operationChunk != 0; operationChunk = *(int *)(operationChunk + 8)) {
    pairIndex = 0;
    if (0 < replacementCount) {
      do {
        operandCount = ((int (*)())_GetValidArgs)(operationChunk);
        operandIndex = 0;
        replacementPair = replacements + pairIndex * 2;
        if (operandCount < 1) {
          fromRegister = *replacementPair;
        }
        else {
          fromRegister = replacements[pairIndex * 2];
          operand = operationChunk;
          do {
            if (((*(uint *)(operand + 0x1c) >> 0x17 & 7) == *(uint *)(fromRegister + 0x14)) &&
               ((uint)*(ushort *)(operand + 0x22) == *(uint *)(fromRegister + 4))) {
              *(uint *)(operand + 0x1c) =
                   (*(uint *)(replacementPair[1] + 0x14) & 7) << 0x17 | *(uint *)(operand + 0x1c) & 0xfc7fffff
              ;
              *(undefined2 *)(operand + 0x22) = *(undefined2 *)(replacementPair[1] + 6);
              fromRegister = *replacementPair;
            }
            operandIndex = operandIndex + 1;
            operand = operand + 8;
          } while (operandIndex < operandCount);
        }
        if (((*(uint *)(operationChunk + 0x14) >> 0x11 & 7) == *(uint *)(fromRegister + 0x14)) &&
           ((uint)*(ushort *)(operationChunk + 0x1a) == *(uint *)(fromRegister + 4))) {
          *(uint *)(operationChunk + 0x14) =
               (*(uint *)(replacementPair[1] + 0x14) & 7) << 0x11 | *(uint *)(operationChunk + 0x14) & 0xfff1ffff;
          *(undefined2 *)(operationChunk + 0x1a) = *(undefined2 *)(replacementPair[1] + 6);
        }
        pairIndex = pairIndex + 4;
      } while (pairIndex < replacementCount);
    }
  }
  blockCount = program[1];
  blockIndex = 0;
  if (blockCount != 0) {
    blockOffset = 0;
    do {
      instructionIndex = 0;
      block = (uint *)(program[2] + blockOffset);
      if (*(int *)(program[2] + blockOffset) != 0) {
        instructionOffset = 0;
        do {
          instruction = (uint *)(block[1] + instructionOffset);
          if ((instruction[5] == 0) && (replacementPair = replacements, replacementsLeft = replacementCount, 0 < replacementCount)) {
            do {
              sourceCount = *instruction;
              loopIndex = 0;
              if (sourceCount != 0) {
                do {
                  if (*(int *)(loopIndex * 4 + instruction[1]) == *replacementPair) {
                    *(int *)(loopIndex * 4 + instruction[1]) = replacementPair[1];
                    sourceCount = *instruction;
                  }
                  loopIndex = loopIndex + 1;
                } while (loopIndex < sourceCount);
              }
              destCount = instruction[2];
              loopIndex = 0;
              if (destCount != 0) {
                do {
                  if (*(int *)(loopIndex * 4 + instruction[3]) == *replacementPair) {
                    *(int *)(loopIndex * 4 + instruction[3]) = replacementPair[1];
                    destCount = instruction[2];
                  }
                  loopIndex = loopIndex + 1;
                } while (loopIndex < destCount);
              }
              replacementsLeft = replacementsLeft + -1;
              replacementPair = replacementPair + 2;
            } while (replacementsLeft != 0);
          }
          instructionIndex = instructionIndex + 1;
          instructionOffset = instructionOffset + 0x1c;
        } while (instructionIndex < *block);
        blockCount = program[1];
      }
      blockIndex = blockIndex + 1;
      blockOffset = blockOffset + 0x2c;
    } while (blockIndex < blockCount);
  }
  return;
}

/* _RegistersCleanup @ 0x97c09b30 (628 bytes) */
int _RegistersCleanup(program)
  int *program;
{
  uint recordIndex;
  uint candidateCount;
  uint paramRegisterCount;
  uint instructions;
  int groupRecord;
  int paramChunk;
  int blockOffset;
  int instructionOffset;
  uint loopIndex;
  uint instructionIndex;
  int slotOffset;
  int record;
  undefined4 usageList;
  uint *block;
  uint *instruction;
  int recordOffset;
  uint sourceIndex;
  uint registerCount;
  uint blockCount;
  uint blockIndex;
  
  loopIndex = 0;
  registerCount = 0;
  if (program[3] != 0) {
    recordOffset = 0;
    do {
      loopIndex = loopIndex + 1;
      record = program[4] + recordOffset;
      recordOffset = recordOffset + 0x2c;
      *(undefined4 *)(record + 0x18) = 1;
      registerCount = program[3];
    } while (loopIndex < registerCount);
  }
  blockCount = program[1];
  blockIndex = 0;
  if (blockCount != 0) {
    blockOffset = 0;
    do {
      instructionIndex = 0;
      block = (uint *)(program[2] + blockOffset);
      if (*(int *)(program[2] + blockOffset) != 0) {
        instructionOffset = 0;
        do {
          instructions = block[1];
          instruction = (uint *)(instructions + instructionOffset);
          if (instruction[5] == 0) {
            sourceIndex = 0;
            if (*(int *)(instructions + instructionOffset) != 0) {
              do {
                slotOffset = sourceIndex * 4;
                sourceIndex = sourceIndex + 1;
                *(undefined4 *)(*(int *)(slotOffset + instruction[1]) + 0x18) = 0;
              } while (sourceIndex < *instruction);
            }
            loopIndex = 0;
            if (instruction[2] != 0) {
              do {
                slotOffset = loopIndex * 4;
                loopIndex = loopIndex + 1;
                *(undefined4 *)(*(int *)(slotOffset + instruction[3]) + 0x18) = 0;
              } while (loopIndex < instruction[2]);
            }
          }
          instructionIndex = instructionIndex + 1;
          instructionOffset = instructionOffset + 0x1c;
        } while (instructionIndex < *block);
        blockCount = program[1];
      }
      blockIndex = blockIndex + 1;
      blockOffset = blockOffset + 0x2c;
    } while (blockIndex < blockCount);
    registerCount = program[3];
  }
  paramRegisterCount = 0;
  for (paramChunk = **(int **)(*program + 0x10); paramChunk != 0; paramChunk = *(int *)(paramChunk + 8)) {
    candidateCount = paramRegisterCount;
    if (((*(uint *)(paramChunk + 0xc) >> 0x10 & 0x1f) != 0x11) &&
       (candidateCount = *(ushort *)(paramChunk + 0x12) + 1, candidateCount < paramRegisterCount)) {
      candidateCount = paramRegisterCount;
    }
    paramRegisterCount = candidateCount;
  }
  recordIndex = 0;
  if (registerCount != 0) {
    do {
      groupRecord = program[4] + recordIndex * 0x2c;
      if ((((*(int *)(groupRecord + 0x18) == 0) || (*(int *)(groupRecord + 0x44) == 0)) ||
          (*(int *)(groupRecord + 0x70) == 0)) ||
         ((*(int *)(groupRecord + 0x9c) == 0 || (*(int *)(groupRecord + 0x28) == 0)))) goto setRecordIndex;
      switch(*(undefined4 *)(groupRecord + 0x14)) {
      default:
        goto groupRecordCase0;
      case 1:
        usageList = *(undefined4 *)(*program + 4);
        break;
      case 2:
        if (paramRegisterCount <= *(uint *)(groupRecord + 4)) {
          usageList = *(undefined4 *)(*program + 0x10);
          break;
        }
        goto groupRecordCase0;
      case 3:
        usageList = *(undefined4 *)(*program + 0x1c);
        break;
      case 4:
        usageList = *(undefined4 *)(*program + 0xc);
      }
      _PPStreamChunkListRemoveChunk(usageList,*(int *)(groupRecord + 0x28));
groupRecordCase0:
      *(undefined4 *)(groupRecord + 0x28) = 0;
      *(undefined4 *)(groupRecord + 0x54) = 0;
      *(undefined4 *)(groupRecord + 0x80) = 0;
      *(undefined4 *)(groupRecord + 0xac) = 0;
      registerCount = program[3];
setRecordIndex:
      recordIndex = recordIndex + 4;
    } while (recordIndex < registerCount);
  }
  return;
}

/* _RegisterIsMergeable @ 0x97c09db8 (40 bytes) */
int _RegisterIsMergeable(reg)
  int reg;
{
  undefined4 isMergeable;
  
  isMergeable = 0;
  if ((*(int *)(reg + 0x14) == 1) && (*(int *)(reg + 0x18) == 0)) {
    isMergeable = 1;
  }
  return isMergeable;
}

/* _RegisterCanMerge @ 0x97c09de0 (168 bytes) */
int _RegisterCanMerge(registerA, registerB)
  int registerA;
  undefined4 *registerB;
{
  int testResult;
  undefined4 canMerge;
  
  canMerge = 0;
  if (((((*(int *)(registerA + 0x10) == registerB[4]) && (*(int *)(registerA + 0xc) == registerB[3])) &&
       (testResult = ((int (*)())_RegisterIsMergeable)(registerA), testResult != 0)) &&
      ((testResult = ((int (*)())_RegisterIsMergeable)(registerB), testResult != 0 &&
       ((testResult = ((int (*)())_RegisterIsFixed)(registerA), testResult == 0 ||
        (testResult = ((int (*)())_RegisterIsFixed)(registerB), testResult == 0)))))) &&
     (testResult = _BitSetGetEquals(*(undefined4 *)(registerA + 8),*registerB), testResult == 0)) {
    canMerge = 1;
  }
  return canMerge;
}

/* _RegisterIsFixed @ 0x97c09e88 (40 bytes) */
int _RegisterIsFixed(reg)
  int reg;
{
  undefined4 isFixed;
  
  isFixed = 0;
  if ((*(int *)(reg + 0x1c) != 0) || (*(int *)(reg + 0x20) != 0)) {
    isFixed = 1;
  }
  return isFixed;
}

/* _RegisterVectorCanMerge @ 0x97c09eb0 (136 bytes) */
int _RegisterVectorCanMerge(vectorA, vectorB)
  undefined4 *vectorA;
  undefined4 *vectorB;
{
  int componentCanMerge;
  undefined4 canMerge;
  
  canMerge = 0;
  componentCanMerge = ((int (*)())_RegisterCanMerge)(*vectorA,*vectorB);
  if ((((componentCanMerge != 0) && (componentCanMerge = ((int (*)())_RegisterCanMerge)(vectorA[1],vectorB[1]), componentCanMerge != 0)) &&
      (componentCanMerge = ((int (*)())_RegisterCanMerge)(vectorA[2],vectorB[2]), componentCanMerge != 0)) &&
     (componentCanMerge = ((int (*)())_RegisterCanMerge)(vectorA[3],vectorB[3]), componentCanMerge != 0)) {
    canMerge = 1;
  }
  return canMerge;
}

/* _RegisterVectorIsFixed @ 0x97c09f38 (116 bytes) */
int _RegisterVectorIsFixed(vector)
  undefined4 *vector;
{
  int componentIsFixed;
  undefined4 isFixed;
  
  isFixed = 0;
  componentIsFixed = ((int (*)())_RegisterIsFixed)(*vector);
  if ((((componentIsFixed != 0) || (componentIsFixed = ((int (*)())_RegisterIsFixed)(vector[1]), componentIsFixed != 0)) ||
      (componentIsFixed = ((int (*)())_RegisterIsFixed)(vector[2]), componentIsFixed != 0)) ||
     (componentIsFixed = ((int (*)())_RegisterIsFixed)(vector[3]), componentIsFixed != 0)) {
    isFixed = 1;
  }
  return isFixed;
}

/* _RegisterAdd @ 0x97c09fac (232 bytes) */
int _RegisterAdd(program, streamChunk, bank, bankFirstRecord, streamRegisterNumber, typeBits)
  int program;
  undefined4 streamChunk;
  undefined4 bank;
  int bankFirstRecord;
  int streamRegisterNumber;
  undefined4 typeBits;
{
  int grownRegisters;
  int component;
  int record;
  int recordOffset;
  int firstRecordIndex;
  int componentsLeft;
  
  firstRecordIndex = bankFirstRecord + streamRegisterNumber * 4;
  if (*(uint *)(program + 0xc) < firstRecordIndex + 4U) {
    grownRegisters = _realloc(*(undefined4 *)(program + 0x10),firstRecordIndex * 0x2c + 0xb0);
    *(int *)(program + 0x10) = grownRegisters;
    _memset(*(int *)(program + 0xc) * 0x2c + grownRegisters,0,(firstRecordIndex - *(int *)(program + 0xc)) * 0x2c + 0xb0
           );
    *(uint *)(program + 0xc) = firstRecordIndex + 4U;
  }
  recordOffset = firstRecordIndex * 0x2c;
  componentsLeft = 4;
  component = 0;
  do {
    record = *(int *)(program + 0x10) + recordOffset;
    *(int *)(*(int *)(program + 0x10) + recordOffset) = firstRecordIndex + component;
    *(int *)(record + 0xc) = component;
    recordOffset = recordOffset + 0x2c;
    *(undefined4 *)(record + 0x28) = streamChunk;
    component = component + 1;
    *(undefined4 *)(record + 8) = 0;
    *(undefined4 *)(record + 0x14) = bank;
    *(undefined4 *)(record + 0x10) = typeBits;
    *(int *)(record + 4) = streamRegisterNumber;
    *(undefined4 *)(record + 0x18) = 0;
    *(undefined4 *)(record + 0x1c) = 0;
    *(undefined4 *)(record + 0x20) = 0;
    componentsLeft = componentsLeft + -1;
  } while (componentsLeft != 0);
  return 0;
}

/* _RegisterFree @ 0x97c0a094 (16 bytes) */
int _RegisterFree(reg)
  int reg;
{
  if (*(int *)(reg + 8) == 0) {
    return;
  }
  return _BitSetFree(*(int *)(reg + 8));
}

/* _InstructionAdd @ 0x97c0a0a4 (1324 bytes) */
int _InstructionAdd(program, block, operationChunk)
  undefined4 *program;
  int *block;
  int operationChunk;
{
  int newSourceCount;
  int oldSourceCount;
  int destAsSourceProbe;
  int destSlotRegister;
  int destsEnd;
  int grownDests;
  int newDestCount;
  int sourceSlotRegister;
  int sourcesEnd;
  int grownSources;
  int oldSourceCountInLoop;
  uint destIsArrayAccess;
  uint destComponentUsed;
  uint destWord1Copy;
  uint sourceIsArrayAccess;
  uint sourceComponentUsed;
  uint destWord2;
  uint destWord;
  uint sourceRegisterIndex;
  uint operandWord;
  int sourceCountBeforeAddress;
  int addressRegisterProbe;
  int destRegisterIndex;
  int instructionsEnd;
  int validArgs;
  int destComponent;
  int operandIndex;
  undefined4 newArray;
  int grownInstructions;
  int grownSourcesForAddress;
  int grownSourcesForDest;
  bool destIsAlsoSource;
  uint operandSizeBits;
  int oldInstructionCount;
  uint sourceWord;
  undefined4 addedSourceRegister;
  int destProbe;
  int sourceProbe;
  int sourceRegister;
  uint usesIndirect;
  int destRegister;
  int *instruction;
  int sourceOperandCursor;
  uint *componentFlagCursor;
  int sourceComponent;
  int operandCursor;
  uint operandScratch [5];
  int sourceLastIndex;
  int destFirstIndex;
  int destLastIndex [3];
  
  oldInstructionCount = *block;
  *block = oldInstructionCount + 1;
  usesIndirect = 0;
  destIsAlsoSource = false;
  grownInstructions = _realloc(block[1],(oldInstructionCount + 1) * 0x1c);
  block[1] = grownInstructions;
  instructionsEnd = grownInstructions + *block * 0x1c;
  instruction = (int *)(instructionsEnd + -0x1c);
  *(undefined4 *)(instructionsEnd + -0xc) = 0;
  *(int *)(instructionsEnd + -4) = operationChunk;
  switch(*(uint *)(operationChunk + 0xc) >> 0x12 & 0xff) {
  case 0x4b:
  case 0x4c:
  case 0x4d:
  case 0x4f:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5b:
  case 0x69:
  case 0x6a:
  case 0x6b:
    *(undefined4 *)(instructionsEnd + -0xc) = 1;
    break;
  case 0x6d:
    destIsAlsoSource = true;
  }
  *instruction = 0;
  operandIndex = 0;
  *(undefined4 *)(instructionsEnd + -8) = 0;
  newArray = _malloc(4);
  *(undefined4 *)(instructionsEnd + -0x18) = newArray;
  validArgs = ((int (*)())_GetValidArgs)(operationChunk);
  sourceOperandCursor = operationChunk;
  operandCursor = operationChunk;
  if (0 < validArgs) {
    do {
      sourceWord = *(uint *)(operandCursor + 0x1c);
      operandScratch[0] = 0;
      operandSizeBits = sourceWord >> 0xc & 3;
      operandScratch[1] = 0;
      operandScratch[2] = 0;
      operandScratch[3] = 0;
      if (operandSizeBits == 1) {
loopStoreOperandScratch:
        *(undefined4 *)((int)operandScratch + (*(uint *)(operandCursor + 0x1c) >> 0x11 & 0xc)) = 1;
loopStoreOperandScratch2:
        *(undefined4 *)((int)operandScratch + (*(uint *)(operandCursor + 0x1c) >> 0x13 & 0xc)) = 1;
      }
      else {
        if (1 < operandSizeBits) {
          if (operandSizeBits != 2) {
            if (operandSizeBits != 3) goto setOperandWord;
            *(undefined4 *)((int)operandScratch + (sourceWord >> 0xd & 0xc)) = 1;
            sourceWord = *(uint *)(operandCursor + 0x1c);
          }
          *(undefined4 *)((int)operandScratch + (sourceWord >> 0xf & 0xc)) = 1;
          goto loopStoreOperandScratch;
        }
        if (operandSizeBits == 0) goto loopStoreOperandScratch2;
      }
setOperandWord:
      operandWord = *(uint *)(operandCursor + 0x1c);
      usesIndirect = usesIndirect | operandWord >> 0x1f;
      ((int (*)())_GetRegisterIndicies)(*program,operandScratch + 4,&sourceLastIndex,operandWord >> 0x17 & 7,(uint)*(ushort *)(operandCursor + 0x22),
                 operandWord >> 0x1f,operandWord >> 0xe & 1,operandWord >> 0xc & 3);
      if ((int)operandScratch[4] <= sourceLastIndex) {
        sourceRegisterIndex = operandScratch[4];
        do {
          sourceComponent = 0;
          componentFlagCursor = operandScratch;
          do {
            sourceComponentUsed = *componentFlagCursor;
            componentFlagCursor = componentFlagCursor + 1;
            if ((sourceComponentUsed != 0) &&
               (sourceProbe = ((int (*)())_GetRegister)(program,*(uint *)(sourceOperandCursor + 0x1c) >> 0x17 & 7,sourceRegisterIndex,sourceComponent),
               sourceProbe != 0)) {
              oldSourceCountInLoop = *instruction;
              *instruction = oldSourceCountInLoop + 1;
              grownSources = _realloc(*(undefined4 *)(instructionsEnd + -0x18),(oldSourceCountInLoop + 1) * 4);
              *(int *)(instructionsEnd + -0x18) = grownSources;
              sourcesEnd = grownSources + *instruction * 4;
              sourceRegister = ((int (*)())_GetRegister)(program,*(uint *)(sourceOperandCursor + 0x1c) >> 0x17 & 7,sourceRegisterIndex,sourceComponent);
              *(int *)(sourcesEnd + -4) = sourceRegister;
              sourceIsArrayAccess = 0;
              *(uint *)(sourceRegister + 0x1c) = *(uint *)(sourceRegister + 0x1c) | *(uint *)(sourceOperandCursor + 0x1c) >> 0x1f;
              sourceSlotRegister = *(int *)(sourcesEnd + -4);
              if (((*(uint *)(sourceOperandCursor + 0x1c) & 0x4000) != 0) &&
                 (1 < (*(uint *)(sourceOperandCursor + 0x1c) >> 0xc & 3) + 1)) {
                sourceIsArrayAccess = 1;
              }
              *(uint *)(sourceSlotRegister + 0x20) = *(uint *)(sourceSlotRegister + 0x20) | sourceIsArrayAccess;
            }
            sourceComponent = sourceComponent + 1;
          } while (sourceComponent < 4);
          sourceRegisterIndex = sourceRegisterIndex + 1;
        } while ((int)sourceRegisterIndex <= sourceLastIndex);
      }
      operandIndex = operandIndex + 1;
      sourceOperandCursor = sourceOperandCursor + 8;
      operandCursor = operandCursor + 8;
    } while (operandIndex < validArgs);
  }
  destWord = *(uint *)(operationChunk + 0x14);
  operandScratch[1] = destWord >> 0xe & 1;
  operandScratch[3] = destWord >> 0x10 & 1;
  operandScratch[0] = destWord >> 0xd & 1;
  operandScratch[2] = destWord >> 0xf & 1;
  *(undefined4 *)(instructionsEnd + -0x14) = 0;
  newArray = _malloc(4);
  *(undefined4 *)(instructionsEnd + -0x10) = newArray;
  *(uint *)(instructionsEnd + -0xc) =
       *(uint *)(instructionsEnd + -0xc) | (uint)((*(uint *)(operationChunk + 0x14) >> 0x11 & 7) == 3);
  destWord1Copy = *(uint *)(operationChunk + 0x14);
  destWord2 = *(uint *)(operationChunk + 0x18);
  ((int (*)())_GetRegisterIndicies)(*program,&destFirstIndex,destLastIndex,destWord1Copy >> 0x11 & 7,destWord2 & 0xffff,destWord2 >> 0x1f,
             destWord1Copy >> 0xc & 1,destWord1Copy >> 10 & 3);
  if (destFirstIndex <= destLastIndex[0]) {
    destRegisterIndex = destFirstIndex;
    do {
      destComponent = 0;
      componentFlagCursor = operandScratch;
      do {
        destComponentUsed = *componentFlagCursor;
        componentFlagCursor = componentFlagCursor + 1;
        if (destComponentUsed != 0) {
          destProbe = ((int (*)())_GetRegister)(program,*(uint *)(operationChunk + 0x14) >> 0x11 & 7,destRegisterIndex,destComponent);
          if (destProbe != 0) {
            newDestCount = *(int *)(instructionsEnd + -0x14) + 1;
            *(int *)(instructionsEnd + -0x14) = newDestCount;
            grownDests = _realloc(*(undefined4 *)(instructionsEnd + -0x10),newDestCount * 4);
            *(int *)(instructionsEnd + -0x10) = grownDests;
            destsEnd = grownDests + *(int *)(instructionsEnd + -0x14) * 4;
            destRegister = ((int (*)())_GetRegister)(program,*(uint *)(operationChunk + 0x14) >> 0x11 & 7,destRegisterIndex,destComponent);
            *(int *)(destsEnd + -4) = destRegister;
            destIsArrayAccess = 0;
            *(uint *)(destRegister + 0x1c) = *(uint *)(destRegister + 0x1c) | *(uint *)(operationChunk + 0x18) >> 0x1f;
            destSlotRegister = *(int *)(destsEnd + -4);
            if (((*(uint *)(operationChunk + 0x14) & 0x1000) != 0) &&
               (1 < (*(uint *)(operationChunk + 0x14) >> 10 & 3) + 1)) {
              destIsArrayAccess = 1;
            }
            *(uint *)(destSlotRegister + 0x20) = *(uint *)(destSlotRegister + 0x20) | destIsArrayAccess;
          }
          if ((destIsAlsoSource || (int)destWord2 < 0) &&
             (destAsSourceProbe = ((int (*)())_GetRegister)(program,*(uint *)(operationChunk + 0x14) >> 0x11 & 7,destRegisterIndex,destComponent),
             destAsSourceProbe != 0)) {
            oldSourceCount = *instruction;
            *instruction = oldSourceCount + 1;
            grownSourcesForDest = _realloc(*(undefined4 *)(instructionsEnd + -0x18),(oldSourceCount + 1) * 4);
            newSourceCount = *instruction;
            *(int *)(instructionsEnd + -0x18) = grownSourcesForDest;
            addedSourceRegister = ((int (*)())_GetRegister)(program,*(uint *)(operationChunk + 0x14) >> 0x11 & 7,destRegisterIndex,destComponent);
            *(undefined4 *)(grownSourcesForDest + newSourceCount * 4 + -4) = addedSourceRegister;
          }
        }
        destComponent = destComponent + 1;
      } while (destComponent < 4);
      destRegisterIndex = destRegisterIndex + 1;
    } while (destRegisterIndex <= destLastIndex[0]);
  }
  if ((usesIndirect != 0 || (int)destWord2 < 0) && (addressRegisterProbe = ((int (*)())_GetRegister)(program,4,0,0), addressRegisterProbe != 0)) {
    sourceCountBeforeAddress = *instruction;
    *instruction = sourceCountBeforeAddress + 1;
    grownSourcesForAddress = _realloc(*(undefined4 *)(instructionsEnd + -0x18),(sourceCountBeforeAddress + 1) * 4);
    sourceCountBeforeAddress = *instruction;
    *(int *)(instructionsEnd + -0x18) = grownSourcesForAddress;
    addedSourceRegister = ((int (*)())_GetRegister)(program,4,0,0);
    *(undefined4 *)(grownSourcesForAddress + sourceCountBeforeAddress * 4 + -4) = addedSourceRegister;
  }
  return instruction;
}

/* _InstructionFree @ 0x97c0a65c (88 bytes) */
int _InstructionFree(instruction)
  int instruction;
{
  if (*(int *)(instruction + 4) != 0) {
    _free(*(int *)(instruction + 4));
  }
  if (*(int *)(instruction + 0xc) != 0) {
    _free(*(int *)(instruction + 0xc));
    return;
  }
  return;
}

/* _BlockAdd @ 0x97c0a6b4 (160 bytes) */
int _BlockAdd(program)
  int program;
{
  int blocksEnd;
  int grownBlocks;
  int newBlockCount;
  undefined4 newArray;
  
  newBlockCount = *(int *)(program + 4) + 1;
  *(int *)(program + 4) = newBlockCount;
  grownBlocks = _realloc(*(undefined4 *)(program + 8),newBlockCount * 0x2c);
  *(int *)(program + 8) = grownBlocks;
  blocksEnd = grownBlocks + *(int *)(program + 4) * 0x2c;
  *(undefined4 *)(blocksEnd + -0x2c) = 0;
  newArray = _malloc(0x1c);
  *(undefined4 *)(blocksEnd + -0x24) = 0;
  *(undefined4 *)(blocksEnd + -0x28) = newArray;
  newArray = _malloc(4);
  *(undefined4 *)(blocksEnd + -0x1c) = 0;
  *(undefined4 *)(blocksEnd + -0x20) = newArray;
  newArray = _malloc(4);
  *(undefined4 *)(blocksEnd + -4) = 0;
  *(undefined4 *)(blocksEnd + -0x18) = newArray;
  *(undefined4 *)(blocksEnd + -0x14) = 0;
  *(undefined4 *)(blocksEnd + -0x10) = 0;
  *(undefined4 *)(blocksEnd + -0xc) = 0;
  *(undefined4 *)(blocksEnd + -8) = 0;
  return blocksEnd + -0x2c;
}

/* _BlockFree @ 0x97c0a754 (236 bytes) */
int _BlockFree(block)
  uint *block;
{
  uint instructionIndex;
  int instructionOffset;
  
  instructionIndex = 0;
  if (*block != 0) {
    instructionOffset = 0;
    do {
      instructionIndex = instructionIndex + 1;
      ((int (*)())_InstructionFree)(block[1] + instructionOffset);
      instructionOffset = instructionOffset + 0x1c;
    } while (instructionIndex < *block);
  }
  if (block[1] != 0) {
    _free(block[1]);
  }
  if (block[3] != 0) {
    _free(block[3]);
  }
  if (block[5] != 0) {
    _free(block[5]);
  }
  if (block[6] != 0) {
    _BitSetFree(block[6]);
  }
  if (block[7] != 0) {
    _BitSetFree(block[7]);
  }
  if (block[8] != 0) {
    _BitSetFree(block[8]);
  }
  if (block[9] != 0) {
    _BitSetFree(block[9]);
  }
  if (block[10] != 0) {
    _BitSetFree(block[10]);
    return;
  }
  return;
}

/* _RegistersInitialize @ 0x97c0a840 (104 bytes) */
int _RegistersInitialize(program)
  int program;
{
  int record;
  int registers;
  uint registerCount;
  undefined4 bitSetNewResult;
  int recordOffset;
  uint recordIndex;
  
  recordIndex = 0;
  registerCount = *(uint *)(program + 0xc);
  if (registerCount != 0) {
    recordOffset = 0;
    do {
      registers = *(int *)(program + 0x10);
      bitSetNewResult = _BitSetNew(registerCount);
      record = registers + recordOffset;
      recordOffset = recordOffset + 0x2c;
      *(undefined4 *)(record + 8) = bitSetNewResult;
      _BitSetSetEquals(bitSetNewResult,recordIndex);
      registerCount = *(uint *)(program + 0xc);
      recordIndex = recordIndex + 1;
    } while (recordIndex < registerCount);
  }
  return;
}

/* _Registerify @ 0x97c0a8a8 (424 bytes) */
int _Registerify(program)
  int *program;
{
  int addressChunk;
  int registerCount;
  undefined4 registersInitializeResult;
  int stream;
  int chunk;
  
  registerCount = program[3];
  stream = *program;
  program[7] = registerCount;
  chunk = **(int **)(stream + 0x1c);
  if (chunk != 0) {
    do {
      ((int (*)())_RegisterAdd)(program,chunk,3,program[7],(uint)*(ushort *)(chunk + 0x12),
                   *(uint *)(chunk + 0xc) >> 0x1a & 7);
      chunk = *(int *)(chunk + 8);
    } while (chunk != 0);
    registerCount = program[3];
    stream = *program;
  }
  program[0xc] = registerCount;
  program[8] = registerCount;
  chunk = **(int **)(stream + 4);
  if (chunk != 0) {
    do {
      ((int (*)())_RegisterAdd)(program,chunk,1,program[8],(uint)*(ushort *)(chunk + 0x12),
                   *(uint *)(chunk + 0xc) >> 0x1a & 7);
      chunk = *(int *)(chunk + 8);
    } while (chunk != 0);
    registerCount = program[3];
    stream = *program;
  }
  program[0xd] = registerCount;
  program[9] = registerCount;
  chunk = **(int **)(stream + 0x18);
  if (chunk != 0) {
    do {
      ((int (*)())_RegisterAdd)(program,chunk,0,program[9],(uint)*(ushort *)(chunk + 0x12),
                   *(uint *)(chunk + 0xc) >> 0x1a & 7);
      chunk = *(int *)(chunk + 8);
    } while (chunk != 0);
    registerCount = program[3];
    stream = *program;
  }
  program[0xe] = registerCount;
  program[10] = registerCount;
  chunk = **(int **)(stream + 0x10);
  if (chunk != 0) {
    do {
      ((int (*)())_RegisterAdd)(program,chunk,2,program[10],(uint)*(ushort *)(chunk + 0x12),
                   *(uint *)(chunk + 0xc) >> 0x1a & 7);
      chunk = *(int *)(chunk + 8);
    } while (chunk != 0);
    registerCount = program[3];
    stream = *program;
  }
  program[0xf] = registerCount;
  program[0xb] = registerCount;
  addressChunk = **(int **)(stream + 0xc);
  if (addressChunk != 0) {
    do {
      ((int (*)())_RegisterAdd)(program,addressChunk,4,program[0xb],*(undefined4 *)(addressChunk + 0xc),3);
      addressChunk = *(int *)(addressChunk + 8);
    } while (addressChunk != 0);
    registerCount = program[3];
  }
  program[0x10] = registerCount;
  registersInitializeResult = ((int (*)())_RegistersInitialize)(program);
  return registersInitializeResult;
}

/* _RegistersFree @ 0x97c0aa50 (124 bytes) */
int _RegistersFree(program)
  int program;
{
  int record;
  uint recordIndex;
  int recordOffset;
  
  recordIndex = 0;
  if (*(int *)(program + 0xc) != 0) {
    recordOffset = 0;
    do {
      recordIndex = recordIndex + 1;
      record = *(int *)(program + 0x10) + recordOffset;
      recordOffset = recordOffset + 0x2c;
      ((int (*)())_RegisterFree)(record);
    } while (recordIndex < *(uint *)(program + 0xc));
  }
  if (*(int *)(program + 0x10) != 0) {
    _free(*(int *)(program + 0x10));
    return;
  }
  return;
}

/* _GetOrAddBlock @ 0x97c0aacc (148 bytes) */
int _GetOrAddBlock(program, labelIndex)
  int program;
  int labelIndex;
{
  int slotOffset;
  int grownBlockByLabel;
  undefined4 blockAddResult;
  
  slotOffset = labelIndex * 4;
  if (*(uint *)(program + 0x14) < labelIndex + 1U) {
    grownBlockByLabel = _realloc(*(undefined4 *)(program + 0x18),slotOffset + 4);
    *(int *)(program + 0x18) = grownBlockByLabel;
    _memset(*(int *)(program + 0x14) * 4 + grownBlockByLabel,0,(labelIndex - *(int *)(program + 0x14)) * 4 + 4);
    *(uint *)(program + 0x14) = labelIndex + 1U;
  }
  if (*(int *)(slotOffset + *(int *)(program + 0x18)) == 0) {
    blockAddResult = ((int (*)())_BlockAdd)(program);
    *(undefined4 *)(slotOffset + *(int *)(program + 0x18)) = blockAddResult;
  }
  return;
}

/* _GetBlockFrom @ 0x97c0ab60 (84 bytes) */
int _GetBlockFrom(program, labelIndex, nextBlockIndex)
  int program;
  uint labelIndex;
  int *nextBlockIndex;
{
  int slotOffset;
  int blockByLabel;
  
  if (*(uint *)(program + 0x14) <= labelIndex) {
    return 0;
  }
  blockByLabel = *(int *)(program + 0x18);
  slotOffset = labelIndex * 4;
  if (*(int *)(slotOffset + blockByLabel) == 0) {
    *(int *)(slotOffset + blockByLabel) = *(int *)(program + 8) + *nextBlockIndex * 0x2c;
    *nextBlockIndex = *nextBlockIndex + 1;
    blockByLabel = *(int *)(program + 0x18);
  }
  return *(undefined4 *)(slotOffset + blockByLabel);
}

/* _GetBlock @ 0x97c0abb4 (36 bytes) */
int _GetBlock(program, labelIndex)
  int program;
  uint labelIndex;
{
  if (*(uint *)(program + 0x14) <= labelIndex) {
    return 0;
  }
  return *(undefined4 *)(labelIndex * 4 + *(int *)(program + 0x18));
}

/* _Blockify @ 0x97c0abd8 (752 bytes) */
int _Blockify(program)
  int *program;
{
  uint operationLabel;
  int ownerBlock;
  int stream;
  int operationBlock;
  int currentBlock;
  int fallthroughBlock;
  int edgeTargetBlock;
  uint blockLabel;
  int nextOperation;
  uint nextOperationLabel;
  int operationChunk;
  undefined4 nextBlockIndex [6];
  
  _memset(program[6],0,program[5] << 2);
  ((int (*)())_GetOrAddBlock)(program,0);
  operationChunk = **(int **)(*program + 0x20);
  while (operationChunk != 0) {
    nextOperation = *(int *)(operationChunk + 8);
    blockLabel = *(uint *)(operationChunk + 0xc);
    if (nextOperation != 0) {
      blockLabel = *(uint *)(nextOperation + 0xc);
    }
    blockLabel = blockLabel & 0x3ffff;
    switch(*(uint *)(operationChunk + 0xc) >> 0x12 & 0xff) {
    case 0x4b:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x5a:
    case 0x5b:
    case 0x69:
    case 0x6a:
    case 0x6b:
      ((int (*)())_GetOrAddBlock)(program,blockLabel);
    case 0x4c:
      blockLabel = *(uint *)(operationChunk + 0x10) & 0x3ffff;
      break;
    case 0x4d:
    case 0x59:
      break;
    default:
      goto operationChunkCase4e;
    }
    ((int (*)())_GetOrAddBlock)(program,blockLabel);
    nextOperation = *(int *)(operationChunk + 8);
operationChunkCase4e:
    operationChunk = nextOperation;
  }
  _memset(program[6],0,program[5] << 2);
  nextBlockIndex[0] = 0;
  ((int (*)())_GetBlockFrom)(program,0,nextBlockIndex);
  stream = *program;
  operationChunk = **(int **)(stream + 0x20);
  if (**(int **)(stream + 0x20) != 0) {
    do {
      nextOperation = *(int *)(operationChunk + 8);
      blockLabel = *(uint *)(operationChunk + 0xc);
      if (nextOperation != 0) {
        blockLabel = *(uint *)(nextOperation + 0xc);
      }
      blockLabel = blockLabel & 0x3ffff;
      switch(*(uint *)(operationChunk + 0xc) >> 0x12 & 0xff) {
      case 0x4b:
      case 0x54:
      case 0x55:
      case 0x56:
      case 0x57:
      case 0x58:
      case 0x5a:
      case 0x5b:
      case 0x69:
      case 0x6a:
      case 0x6b:
        ((int (*)())_GetBlockFrom)(program,blockLabel,nextBlockIndex);
      case 0x4c:
        blockLabel = *(uint *)(operationChunk + 0x10) & 0x3ffff;
        break;
      case 0x4d:
      case 0x59:
        break;
      default:
        goto operationChunkCase4e2;
      }
      ((int (*)())_GetBlockFrom)(program,blockLabel,nextBlockIndex);
      nextOperation = *(int *)(operationChunk + 8);
operationChunkCase4e2:
      operationChunk = nextOperation;
    } while (nextOperation != 0);
    stream = *program;
  }
  currentBlock = ((int (*)())_GetBlock)(program,0);
  operationChunk = **(int **)(stream + 0x20);
  do {
    if (operationChunk == 0) {
      return;
    }
    operationLabel = *(uint *)(operationChunk + 0xc) & 0x3ffff;
    nextOperationLabel = operationLabel;
    if (*(int *)(operationChunk + 8) != 0) {
      nextOperationLabel = *(uint *)(*(int *)(operationChunk + 8) + 0xc) & 0x3ffff;
    }
    operationBlock = ((int (*)())_GetBlock)(program,operationLabel);
    ownerBlock = currentBlock;
    if (operationBlock != 0) {
      ownerBlock = operationBlock;
    }
    ((int (*)())_InstructionAdd)(program,ownerBlock,operationChunk);
    currentBlock = ownerBlock;
    switch(*(uint *)(operationChunk + 0xc) >> 0x12 & 0xff) {
    case 0x4b:
    case 0x54:
    case 0x58:
    case 0x69:
      fallthroughBlock = ((int (*)())_GetBlock)(program,nextOperationLabel);
      edgeTargetBlock = ((int (*)())_GetBlock)(program,*(uint *)(operationChunk + 0x10) & 0x3ffff);
      goto setCurrentBlock;
    case 0x4c:
      break;
    case 0x4d:
      currentBlock = ((int (*)())_GetBlock)(program,nextOperationLabel);
      break;
    default:
      edgeTargetBlock = ((int (*)())_GetBlock)(program,nextOperationLabel);
      fallthroughBlock = edgeTargetBlock;
      if (edgeTargetBlock != 0) goto setCurrentBlock;
      break;
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x5a:
    case 0x5b:
    case 0x6a:
    case 0x6b:
      fallthroughBlock = ((int (*)())_GetBlock)(program,nextOperationLabel);
      edgeTargetBlock = ((int (*)())_GetBlock)(program,*(uint *)(operationChunk + 0x10) & 0x3ffff);
      ((int (*)())_BlockAddSuccessor)(ownerBlock,fallthroughBlock);
      goto setCurrentBlock;
    case 0x59:
      edgeTargetBlock = ((int (*)())_GetBlock)(program,nextOperationLabel);
      fallthroughBlock = edgeTargetBlock;
setCurrentBlock:
      currentBlock = fallthroughBlock;
      ((int (*)())_BlockAddSuccessor)(ownerBlock,edgeTargetBlock);
    }
    operationChunk = *(int *)(operationChunk + 8);
  } while( true );
}

/* _BlockAddSuccessor @ 0x97c0b054 (144 bytes) */
int _BlockAddSuccessor(fromBlock, toBlock)
  int fromBlock;
  int toBlock;
{
  int grownList;
  int newCount;
  
  if ((fromBlock != 0) && (toBlock != 0)) {
    newCount = *(int *)(toBlock + 8) + 1;
    *(int *)(toBlock + 8) = newCount;
    grownList = _realloc(*(undefined4 *)(toBlock + 0xc),newCount * 4);
    *(int *)(toBlock + 0xc) = grownList;
    *(int *)(grownList + *(int *)(toBlock + 8) * 4 + -4) = fromBlock;
    newCount = *(int *)(fromBlock + 0x10) + 1;
    *(int *)(fromBlock + 0x10) = newCount;
    grownList = _realloc(*(undefined4 *)(fromBlock + 0x14),newCount * 4);
    *(int *)(fromBlock + 0x14) = grownList;
    *(int *)(grownList + *(int *)(fromBlock + 0x10) * 4 + -4) = toBlock;
  }
  return;
}

/* _BlockAddPredecessor @ 0x97c0b0e4 (16 bytes) */
int _BlockAddPredecessor(block, predecessorBlock)
  undefined4 block;
  undefined4 predecessorBlock;
{
  return ((int (*)())_BlockAddSuccessor)(predecessorBlock,block);
}

/* _BlocksFree @ 0x97c0b0f4 (124 bytes) */
int _BlocksFree(program)
  int program;
{
  int block;
  uint blockIndex;
  int blockOffset;
  
  blockIndex = 0;
  if (*(int *)(program + 4) != 0) {
    blockOffset = 0;
    do {
      blockIndex = blockIndex + 1;
      block = *(int *)(program + 8) + blockOffset;
      blockOffset = blockOffset + 0x2c;
      ((int (*)())_BlockFree)(block);
    } while (blockIndex < *(uint *)(program + 4));
  }
  if (*(int *)(program + 8) != 0) {
    _free(*(int *)(program + 8));
    return;
  }
  return;
}

/* _ProgramNew @ 0x97c0b170 (152 bytes) */
int _ProgramNew(stream)
  undefined4 stream;
{
  undefined4 *program;
  undefined4 newArray;
  
  program = (undefined4 *)_malloc(0x44);
  *program = stream;
  program[1] = 0;
  newArray = _malloc(0x2c);
  program[2] = newArray;
  program[3] = 0;
  newArray = _malloc(0x2c);
  program[4] = newArray;
  program[5] = 0;
  newArray = _malloc(4);
  program[6] = newArray;
  program[0x10] = 0;
  program[7] = 0;
  program[8] = 0;
  program[9] = 0;
  program[10] = 0;
  program[0xb] = 0;
  program[0xc] = 0;
  program[0xd] = 0;
  program[0xe] = 0;
  program[0xf] = 0;
  return program;
}

/* _ProgramFree @ 0x97c0b208 (76 bytes) */
int _ProgramFree(program)
  int program;
{
  if (*(int *)(program + 0x18) != 0) {
    _free(*(int *)(program + 0x18));
  }
  ((int (*)())_RegistersFree)(program);
  ((int (*)())_BlocksFree)(program);
  return _free(program);
}

/* _FlattenIfs @ 0x97c0b254 (468 bytes) */
int _FlattenIfs(stream)
  int stream;
{
  uint destWord;
  uint sourceWord;
  int sourceCount;
  int *nextLink;
  bool canFlatten;
  uint prevOpcode;
  int prevOperation;
  uint *operandCursor;
  int endifOperation;
  int elseOperation;
  uint targetLabel;
  int scanOperation;
  int resumeOperation;
  int operationChunk;
  
  operationChunk = **(int **)(stream + 0x20);
  do {
    while( true ) {
      if (operationChunk == 0) {
        return;
      }
      resumeOperation = operationChunk;
      if ((*(uint *)(operationChunk + 0xc) >> 0x12 & 0xff) == 0x55) break;
loopSetOperationChunk:
      operationChunk = *(int *)(resumeOperation + 8);
    }
    elseOperation = 0;
    canFlatten = true;
    targetLabel = *(uint *)(operationChunk + 0x10) & 0x3ffff;
    prevOperation = 0;
    scanOperation = operationChunk;
    do {
      if (((*(uint *)(scanOperation + 0xc) & 0x3ffff) == targetLabel) && (prevOperation != 0)) {
        prevOpcode = *(uint *)(prevOperation + 0xc) >> 0x12 & 0xff;
        if (prevOpcode == 0x58) {
          targetLabel = *(uint *)(prevOperation + 0x10) & 0x3ffff;
          elseOperation = prevOperation;
        }
        else {
          endifOperation = prevOperation;
          if (prevOpcode == 0x59) break;
        }
      }
      switch(*(uint *)(scanOperation + 0xc) >> 0x12 & 0xff) {
      case 0x4b:
      case 0x54:
      case 0x69:
        if (targetLabel < (*(uint *)(scanOperation + 0x10) & 0x3ffff)) goto scanOperationCase4c;
        break;
      case 0x4c:
      case 0x4d:
scanOperationCase4c:
        canFlatten = false;
      }
      sourceCount = ((int (*)())_GetValidArgs)(scanOperation);
      if (0 < sourceCount) {
        operandCursor = (uint *)(scanOperation + 0x1c);
        do {
          sourceWord = *operandCursor;
          operandCursor = operandCursor + 2;
          if ((int)sourceWord < 0) {
            canFlatten = false;
          }
          if (((sourceWord & 0x4000) != 0) && (1 < (sourceWord >> 0xc & 3) + 1)) {
            canFlatten = false;
          }
          sourceCount = sourceCount + -1;
        } while (sourceCount != 0);
      }
      destWord = *(uint *)(scanOperation + 0x14);
      if ((destWord & 0x1e000) != 0) {
        if (*(int *)(scanOperation + 0x18) < 0) {
          canFlatten = false;
        }
        if (((destWord & 0x1000) != 0) && (1 < (destWord >> 10 & 3) + 1)) {
          canFlatten = false;
        }
      }
      nextLink = (int *)(scanOperation + 8);
      prevOperation = scanOperation;
      endifOperation = 0;
      scanOperation = *nextLink;
    } while (*nextLink != 0);
    if (!canFlatten) goto loopSetOperationChunk;
    resumeOperation = *(int *)(operationChunk + 4);
    _FlattenIf(stream,operationChunk,elseOperation,endifOperation);
    if (resumeOperation != 0) goto loopSetOperationChunk;
    operationChunk = **(int **)(stream + 0x20);
  } while( true );
}

/* _regEqualsFunction @ 0x97c0b4ac (36 bytes) */
int _regEqualsFunction(registerA, registerB)
  int *registerA;
  int *registerB;
{
  if (registerA[1] - registerB[1] != 0) {
    return registerA[1] - registerB[1];
  }
  return *registerA - *registerB;
}

/* _AddTempRegister @ 0x97c0b4d0 (128 bytes) */
int _AddTempRegister(stream, precision, type, vecSize)
  int stream;
  int precision;
  uint type;
  uint vecSize;
{
  undefined4 maxIndex;
  uint usageWord0;
  undefined4 usageWord1;
  undefined4 usageWord2;
  
  usageWord0 = 0;
  usageWord1 = 0;
  usageWord2 = 0;
  maxIndex = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(stream + 4));
  usageWord0 = (vecSize & 3) << 0x18 | (type & 7) << 0x1a | precision << 0x1d | usageWord0 & 0xffffff;
  usageWord1 = CONCAT22((*(unsigned short *)((unsigned char *)&(usageWord1) + 0)),(short)maxIndex + 1);
  _PPStreamAddTempUsage(stream,&usageWord0);
  return usageWord1 & 0xffff;
}

/* _AddConstantParam @ 0x97c0b550 (436 bytes) */
int _AddConstantParam(stream, precision, type, vecSize, constXBits, constYBits, constZBits, constWBits)
  int stream;
  uint precision;
  uint type;
  uint vecSize;
  unsigned int constXBits;
  unsigned int constYBits;
  unsigned int constZBits;
  unsigned int constWBits;
{
  float constX = GH_U2F(constXBits);
  float constY = GH_U2F(constYBits);
  float constZ = GH_U2F(constZBits);
  float constW = GH_U2F(constWBits);
  int constantChunk;
  undefined4 maxIndex;
  uint chunkWord;
  int *bindingList;
  int bindingChunk;
  float stackConstX;
  float stackConstY;
  float stackConstZ;
  float stackConstW;
  float constantX;
  float constantY;
  float constantZ;
  float constantW;
  longlong convertScratch;
  undefined4 bindingWord0;
  undefined4 bindingWord1;
  undefined4 bindingWord2;
  
  constantX = constX;
  constantY = constY;
  constantZ = constZ;
  constantW = constW;
  if (type != 1) {
    constantX = GH_U2F((unsigned int)((int)constX));
    constantY = GH_U2F((unsigned int)((int)constY));
    constantZ = GH_U2F((unsigned int)((int)constZ));
    constantW = GH_U2F((unsigned int)((int)constW));
    convertScratch = (longlong)(int)GH_F2U(constantW);
  }
  bindingList = *(int **)(stream + 0x10);
  bindingChunk = *bindingList;
  stackConstX = constX;
  stackConstY = constY;
  stackConstZ = constZ;
  stackConstW = constW;
  if (bindingChunk != 0) {
    do {
      chunkWord = *(uint *)(bindingChunk + 0xc);
      if (((((chunkWord >> 0x10 & 0x1f) == 0x11) && ((chunkWord >> 0x1a & 7) == type)) &&
          ((chunkWord >> 0x18 & 3) == vecSize)) && (chunkWord >> 0x1d == precision)) {
        constantChunk = _PPStreamChunkListChunkAtIndex(*(undefined4 *)(stream + 0x2c),chunkWord & 0xffff);
        constantChunk = _memcmp(&constantX,constantChunk + 0xc,0x10);
        if (constantChunk == 0) {
          return *(undefined2 *)(bindingChunk + 0x12);
        }
      }
      bindingChunk = *(int *)(bindingChunk + 8);
    } while (bindingChunk != 0);
    bindingList = *(int **)(stream + 0x10);
  }
  bindingWord1 = 0;
  bindingWord0 = 0x110000;
  bindingWord2 = 0;
  maxIndex = _PPStreamChunkListGetMaxIndex(bindingList);
  chunkWord = (uint)bindingWord0 >> 0x10;
  bindingWord1 = CONCAT22((*(unsigned short *)((unsigned char *)&(bindingWord1) + 0)),(short)maxIndex + 1);
  bindingWord0 = CONCAT22((ushort)((precision << 0x1d) >> 0x10) |
                      (ushort)(((vecSize & 3) << 0x18) >> 0x10) |
                      (ushort)(((type & 7) << 0x1a) >> 0x10) | (ushort)chunkWord & 0xff,
                      *(undefined2 *)(*(int *)(stream + 0x2c) + 10));
  _PPStreamAddConstant(stream,&constantX);
  _PPStreamAddParamBinding(stream,&bindingWord0);
  return (*(unsigned short *)((unsigned char *)&(bindingWord1) + 2));
}

