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
  int entryOrEqualsResult;
  uint bucketEntries;
  uint hashCode;
  int bucketOffset;
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
      entryOrEqualsResult = *(int *)(bucketEntries + loopIndex * 4);
      if ((entryOrEqualsResult != 0) &&
         (entryOrEqualsResult = (*(code *)hashSet[3])(entryOrEqualsResult,element,unusedArg5,unusedArg6,unusedArg7,unusedArg8,buckets), entryOrEqualsResult == 0)) {
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
LAB_97c08e8c:
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
      if ((rangeStart <= registerNumber) && (registerNumber <= *(ushort *)(arrayChunk + 0x12))) goto LAB_97c08e8c;
      arrayIndex = arrayIndex + 1;
    }
  }
  return -1;
}

/* _GetRegisterIndicies @ 0x97c08ee4 (168 bytes) */
int _GetRegisterIndicies(stream, outFirstIndex, outLastIndex, listKind, registerNumber, lookUpArrays, isArray, arrayExtent)
  undefined4 stream;
  int *outFirstIndex;
  int *outLastIndex;
  undefined4 listKind;
  int registerNumber;
  int lookUpArrays;
  int isArray;
  int arrayExtent;
{
  int lastIndex;
  
  *outFirstIndex = 0;
  *outLastIndex = -1;
  if (lookUpArrays != 0) {
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
int _RegistersMerge(param_1)
  int param_1;
{
  int registerVectorCanMergeResult;
  int registerVectorIsFixedResult;
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int allocation2;
  undefined4 allocation3;
  int *allocation;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint loopIndex;
  uint uVar14;
  int iVar15;
  int iVar16;
  int local_50 [6];
  
  allocation2 = _malloc(8);
  iVar11 = 0;
  allocation3 = _malloc(0x10);
  allocation = (int *)_realloc(allocation3,0x10);
  iVar16 = 4;
  loopIndex = 1;
  iVar8 = 0;
  piVar4 = allocation;
  do {
    iVar3 = *(int *)(param_1 + 0x10) + iVar8;
    iVar8 = iVar8 + 0x2c;
    *piVar4 = iVar3;
    piVar4 = piVar4 + 1;
    iVar16 = iVar16 + -1;
  } while (iVar16 != 0);
  uVar12 = 4;
  if (4 < *(uint *)(param_1 + 0xc)) {
    iVar8 = 0xb0;
    do {
      iVar16 = iVar8 + *(int *)(param_1 + 0x10);
      iVar3 = 4;
      piVar4 = local_50;
      do {
        *piVar4 = iVar16;
        piVar4 = piVar4 + 1;
        iVar16 = iVar16 + 0x2c;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      bVar2 = false;
      registerVectorIsFixedResult = ((int (*)())_RegisterVectorIsFixed)(local_50);
      if (registerVectorIsFixedResult == 0) {
        uVar14 = 0;
        piVar4 = allocation;
        if (loopIndex != 0) {
LAB_97c09514:
          registerVectorCanMergeResult = ((int (*)())_RegisterVectorCanMerge)(piVar4,local_50);
          if (registerVectorCanMergeResult == 0) goto LAB_97c09608;
          iVar3 = 0;
          iVar16 = 3;
          do {
            iVar11 = iVar11 + 1;
            _BitSetOrEquals(*(undefined4 *)(*(int *)(iVar3 + (int)piVar4) + 8),
                            *(undefined4 *)(*(int *)(iVar3 + (int)local_50) + 8));
            *(int *)(*(int *)(iVar3 + (int)piVar4) + 0x24) =
                 *(int *)(*(int *)(iVar3 + (int)piVar4) + 0x24) +
                 *(int *)(*(int *)(iVar3 + (int)local_50) + 0x24);
            *(undefined4 *)(*(int *)(iVar3 + (int)local_50) + 0x18) = 1;
            ((int (*)())_RegistersReInterfere)(param_1,*(undefined4 *)(iVar3 + (int)local_50),
                       *(undefined4 *)(iVar3 + (int)piVar4));
            allocation2 = _realloc(allocation2,iVar11 * 8);
            iVar15 = allocation2 + iVar11 * 8;
            iVar16 = iVar16 + -1;
            *(undefined4 *)(iVar15 + -8) = *(undefined4 *)(iVar3 + (int)local_50);
            puVar1 = (undefined4 *)(iVar3 + (int)piVar4);
            iVar3 = iVar3 + 4;
            *(undefined4 *)(iVar15 + -4) = *puVar1;
          } while (-1 < iVar16);
          if ((*(int *)(*piVar4 + 0x14) == 1) && (*(int *)(local_50[0] + 0x14) == 1)) {
            iVar16 = *(int *)(*piVar4 + 0x28);
            uVar10 = *(uint *)(iVar16 + 0xc);
            uVar14 = *(uint *)(*(int *)(local_50[0] + 0x28) + 0xc) >> 0x18 & 3;
            uVar9 = uVar10 >> 0x18 & 3;
            if (uVar14 < uVar9) {
              uVar14 = uVar9;
            }
            *(uint *)(iVar16 + 0xc) = uVar14 << 0x18 | uVar10 & 0xfcffffff;
          }
          bVar2 = true;
        }
LAB_97c09618:
        if (!bVar2) goto LAB_97c09620;
      }
      else {
LAB_97c09620:
        loopIndex = loopIndex + 1;
        allocation = (int *)_realloc(allocation,loopIndex * 0x10);
        iVar3 = 4;
        iVar16 = 0;
        do {
          *(undefined4 *)((int)allocation + iVar16 + loopIndex * 0x10 + -0x10) =
               *(undefined4 *)(iVar16 + (int)local_50);
          iVar16 = iVar16 + 4;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      uVar12 = uVar12 + 4;
      iVar8 = iVar8 + 0xb0;
    } while (uVar12 < *(uint *)(param_1 + 0xc));
  }
  if (allocation != (int *)0x0) {
    _free(allocation);
  }
  ((int (*)())_RegistersReplace)(param_1,iVar11,allocation2);
  if (allocation2 != 0) {
    _free(allocation2);
  }
  return;
LAB_97c09608:
  uVar14 = uVar14 + 1;
  piVar4 = piVar4 + 4;
  if (loopIndex <= uVar14) goto LAB_97c09618;
  goto LAB_97c09514;
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
LAB_97c0978c:
              if (isDead) {
                _PPStreamRemoveOperation(*program,instruction[6]);
                instruction[5] = 1;
                goto LAB_97c09828;
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
                  if (destCount <= destIndex) goto LAB_97c0978c;
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
LAB_97c09828:
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
int _RegistersReplace(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int *param_3;
{
  int iVar1;
  uint *puVar2;
  uint loopIndex4;
  int *piVar4;
  uint *puVar5;
  int loopIndex2;
  int iVar7;
  uint uVar8;
  uint loopIndex;
  int iVar10;
  int iVar11;
  uint loopIndex3;
  int iVar13;
  
  for (iVar13 = **(int **)(*param_1 + 0x20); iVar13 != 0; iVar13 = *(int *)(iVar13 + 8)) {
    iVar11 = 0;
    if (0 < param_2) {
      do {
        iVar1 = ((int (*)())_GetValidArgs)(iVar13);
        loopIndex2 = 0;
        piVar4 = param_3 + iVar11 * 2;
        if (iVar1 < 1) {
          iVar7 = *piVar4;
        }
        else {
          iVar7 = param_3[iVar11 * 2];
          iVar10 = iVar13;
          do {
            if (((*(uint *)(iVar10 + 0x1c) >> 0x17 & 7) == *(uint *)(iVar7 + 0x14)) &&
               ((uint)*(ushort *)(iVar10 + 0x22) == *(uint *)(iVar7 + 4))) {
              *(uint *)(iVar10 + 0x1c) =
                   (*(uint *)(piVar4[1] + 0x14) & 7) << 0x17 | *(uint *)(iVar10 + 0x1c) & 0xfc7fffff
              ;
              *(undefined2 *)(iVar10 + 0x22) = *(undefined2 *)(piVar4[1] + 6);
              iVar7 = *piVar4;
            }
            loopIndex2 = loopIndex2 + 1;
            iVar10 = iVar10 + 8;
          } while (loopIndex2 < iVar1);
        }
        if (((*(uint *)(iVar13 + 0x14) >> 0x11 & 7) == *(uint *)(iVar7 + 0x14)) &&
           ((uint)*(ushort *)(iVar13 + 0x1a) == *(uint *)(iVar7 + 4))) {
          *(uint *)(iVar13 + 0x14) =
               (*(uint *)(piVar4[1] + 0x14) & 7) << 0x11 | *(uint *)(iVar13 + 0x14) & 0xfff1ffff;
          *(undefined2 *)(iVar13 + 0x1a) = *(undefined2 *)(piVar4[1] + 6);
        }
        iVar11 = iVar11 + 4;
      } while (iVar11 < param_2);
    }
  }
  uVar8 = param_1[1];
  loopIndex3 = 0;
  if (uVar8 != 0) {
    iVar13 = 0;
    do {
      loopIndex4 = 0;
      puVar2 = (uint *)(param_1[2] + iVar13);
      if (*(int *)(param_1[2] + iVar13) != 0) {
        iVar11 = 0;
        do {
          puVar5 = (uint *)(puVar2[1] + iVar11);
          if ((puVar5[5] == 0) && (piVar4 = param_3, iVar1 = param_2, 0 < param_2)) {
            do {
              uVar8 = *puVar5;
              loopIndex = 0;
              if (uVar8 != 0) {
                do {
                  if (*(int *)(loopIndex * 4 + puVar5[1]) == *piVar4) {
                    *(int *)(loopIndex * 4 + puVar5[1]) = piVar4[1];
                    uVar8 = *puVar5;
                  }
                  loopIndex = loopIndex + 1;
                } while (loopIndex < uVar8);
              }
              uVar8 = puVar5[2];
              loopIndex = 0;
              if (uVar8 != 0) {
                do {
                  if (*(int *)(loopIndex * 4 + puVar5[3]) == *piVar4) {
                    *(int *)(loopIndex * 4 + puVar5[3]) = piVar4[1];
                    uVar8 = puVar5[2];
                  }
                  loopIndex = loopIndex + 1;
                } while (loopIndex < uVar8);
              }
              iVar1 = iVar1 + -1;
              piVar4 = piVar4 + 2;
            } while (iVar1 != 0);
          }
          loopIndex4 = loopIndex4 + 1;
          iVar11 = iVar11 + 0x1c;
        } while (loopIndex4 < *puVar2);
        uVar8 = param_1[1];
      }
      loopIndex3 = loopIndex3 + 1;
      iVar13 = iVar13 + 0x2c;
    } while (loopIndex3 < uVar8);
  }
  return;
}

/* _RegistersCleanup @ 0x97c09b30 (628 bytes) */
int _RegistersCleanup(param_1)
  int *param_1;
{
  uint loopIndex;
  uint loopIndex3;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint loopIndex2;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  loopIndex = 0;
  uVar8 = 0;
  if (param_1[3] != 0) {
    iVar6 = 0;
    do {
      loopIndex = loopIndex + 1;
      iVar2 = param_1[4] + iVar6;
      iVar6 = iVar6 + 0x2c;
      *(undefined4 *)(iVar2 + 0x18) = 1;
      uVar8 = param_1[3];
    } while (loopIndex < uVar8);
  }
  uVar9 = param_1[1];
  uVar10 = 0;
  if (uVar9 != 0) {
    iVar6 = 0;
    do {
      loopIndex3 = 0;
      puVar4 = (uint *)(param_1[2] + iVar6);
      if (*(int *)(param_1[2] + iVar6) != 0) {
        iVar2 = 0;
        do {
          uVar9 = puVar4[1];
          puVar5 = (uint *)(uVar9 + iVar2);
          if (puVar5[5] == 0) {
            loopIndex2 = 0;
            if (*(int *)(uVar9 + iVar2) != 0) {
              do {
                iVar1 = loopIndex2 * 4;
                loopIndex2 = loopIndex2 + 1;
                *(undefined4 *)(*(int *)(iVar1 + puVar5[1]) + 0x18) = 0;
              } while (loopIndex2 < *puVar5);
            }
            loopIndex = 0;
            if (puVar5[2] != 0) {
              do {
                iVar1 = loopIndex * 4;
                loopIndex = loopIndex + 1;
                *(undefined4 *)(*(int *)(iVar1 + puVar5[3]) + 0x18) = 0;
              } while (loopIndex < puVar5[2]);
            }
          }
          loopIndex3 = loopIndex3 + 1;
          iVar2 = iVar2 + 0x1c;
        } while (loopIndex3 < *puVar4);
        uVar9 = param_1[1];
      }
      uVar10 = uVar10 + 1;
      iVar6 = iVar6 + 0x2c;
    } while (uVar10 < uVar9);
    uVar8 = param_1[3];
  }
  uVar9 = 0;
  for (iVar6 = **(int **)(*param_1 + 0x10); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    uVar10 = uVar9;
    if (((*(uint *)(iVar6 + 0xc) >> 0x10 & 0x1f) != 0x11) &&
       (uVar10 = *(ushort *)(iVar6 + 0x12) + 1, uVar10 < uVar9)) {
      uVar10 = uVar9;
    }
    uVar9 = uVar10;
  }
  uVar10 = 0;
  if (uVar8 != 0) {
    do {
      iVar6 = param_1[4] + uVar10 * 0x2c;
      if ((((*(int *)(iVar6 + 0x18) == 0) || (*(int *)(iVar6 + 0x44) == 0)) ||
          (*(int *)(iVar6 + 0x70) == 0)) ||
         ((*(int *)(iVar6 + 0x9c) == 0 || (*(int *)(iVar6 + 0x28) == 0)))) goto LAB_97c09d98;
      switch(*(undefined4 *)(iVar6 + 0x14)) {
      default:
        goto switchD_97c09d2c_caseD_0;
      case 1:
        uVar3 = *(undefined4 *)(*param_1 + 4);
        break;
      case 2:
        if (uVar9 <= *(uint *)(iVar6 + 4)) {
          uVar3 = *(undefined4 *)(*param_1 + 0x10);
          break;
        }
        goto switchD_97c09d2c_caseD_0;
      case 3:
        uVar3 = *(undefined4 *)(*param_1 + 0x1c);
        break;
      case 4:
        uVar3 = *(undefined4 *)(*param_1 + 0xc);
      }
      _PPStreamChunkListRemoveChunk(uVar3,*(int *)(iVar6 + 0x28));
switchD_97c09d2c_caseD_0:
      *(undefined4 *)(iVar6 + 0x28) = 0;
      *(undefined4 *)(iVar6 + 0x54) = 0;
      *(undefined4 *)(iVar6 + 0x80) = 0;
      *(undefined4 *)(iVar6 + 0xac) = 0;
      uVar8 = param_1[3];
LAB_97c09d98:
      uVar10 = uVar10 + 4;
    } while (uVar10 < uVar8);
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
int _InstructionAdd(param_1, param_2, param_3)
  undefined4 *param_1;
  int *param_2;
  int param_3;
{
  int validArgs;
  int loopIndex;
  int loopIndex3;
  undefined4 allocation;
  int allocation2;
  int allocation4;
  int allocation3;
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 registerValue2;
  int iVar6;
  int iVar7;
  int registerValue3;
  uint uVar9;
  int registerValue;
  int *piVar11;
  int iVar12;
  uint *puVar13;
  int loopIndex2;
  int iVar15;
  uint local_70 [5];
  int local_5c;
  int local_58;
  int local_54 [3];
  
  iVar3 = *param_2;
  *param_2 = iVar3 + 1;
  uVar9 = 0;
  bVar1 = false;
  allocation2 = _realloc(param_2[1],(iVar3 + 1) * 0x1c);
  param_2[1] = allocation2;
  iVar3 = allocation2 + *param_2 * 0x1c;
  piVar11 = (int *)(iVar3 + -0x1c);
  *(undefined4 *)(iVar3 + -0xc) = 0;
  *(int *)(iVar3 + -4) = param_3;
  switch(*(uint *)(param_3 + 0xc) >> 0x12 & 0xff) {
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
    *(undefined4 *)(iVar3 + -0xc) = 1;
    break;
  case 0x6d:
    bVar1 = true;
  }
  *piVar11 = 0;
  loopIndex3 = 0;
  *(undefined4 *)(iVar3 + -8) = 0;
  allocation = _malloc(4);
  *(undefined4 *)(iVar3 + -0x18) = allocation;
  validArgs = ((int (*)())_GetValidArgs)(param_3);
  iVar12 = param_3;
  iVar15 = param_3;
  if (0 < validArgs) {
    do {
      uVar4 = *(uint *)(iVar15 + 0x1c);
      local_70[0] = 0;
      uVar2 = uVar4 >> 0xc & 3;
      local_70[1] = 0;
      local_70[2] = 0;
      local_70[3] = 0;
      if (uVar2 == 1) {
LAB_97c0a284:
        *(undefined4 *)((int)local_70 + (*(uint *)(iVar15 + 0x1c) >> 0x11 & 0xc)) = 1;
LAB_97c0a290:
        *(undefined4 *)((int)local_70 + (*(uint *)(iVar15 + 0x1c) >> 0x13 & 0xc)) = 1;
      }
      else {
        if (1 < uVar2) {
          if (uVar2 != 2) {
            if (uVar2 != 3) goto LAB_97c0a29c;
            *(undefined4 *)((int)local_70 + (uVar4 >> 0xd & 0xc)) = 1;
            uVar4 = *(uint *)(iVar15 + 0x1c);
          }
          *(undefined4 *)((int)local_70 + (uVar4 >> 0xf & 0xc)) = 1;
          goto LAB_97c0a284;
        }
        if (uVar2 == 0) goto LAB_97c0a290;
      }
LAB_97c0a29c:
      uVar2 = *(uint *)(iVar15 + 0x1c);
      uVar9 = uVar9 | uVar2 >> 0x1f;
      ((int (*)())_GetRegisterIndicies)(*param_1,local_70 + 4,&local_5c,uVar2 >> 0x17 & 7,(uint)*(ushort *)(iVar15 + 0x22),
                 uVar2 >> 0x1f,uVar2 >> 0xe & 1,uVar2 >> 0xc & 3);
      if ((int)local_70[4] <= local_5c) {
        uVar2 = local_70[4];
        do {
          loopIndex2 = 0;
          puVar13 = local_70;
          do {
            uVar4 = *puVar13;
            puVar13 = puVar13 + 1;
            if ((uVar4 != 0) &&
               (iVar7 = ((int (*)())_GetRegister)(param_1,*(uint *)(iVar12 + 0x1c) >> 0x17 & 7,uVar2,loopIndex2),
               iVar7 != 0)) {
              iVar7 = *piVar11;
              *piVar11 = iVar7 + 1;
              iVar7 = _realloc(*(undefined4 *)(iVar3 + -0x18),(iVar7 + 1) * 4);
              *(int *)(iVar3 + -0x18) = iVar7;
              iVar7 = iVar7 + *piVar11 * 4;
              registerValue3 = ((int (*)())_GetRegister)(param_1,*(uint *)(iVar12 + 0x1c) >> 0x17 & 7,uVar2,loopIndex2);
              *(int *)(iVar7 + -4) = registerValue3;
              uVar4 = 0;
              *(uint *)(registerValue3 + 0x1c) = *(uint *)(registerValue3 + 0x1c) | *(uint *)(iVar12 + 0x1c) >> 0x1f;
              iVar7 = *(int *)(iVar7 + -4);
              if (((*(uint *)(iVar12 + 0x1c) & 0x4000) != 0) &&
                 (1 < (*(uint *)(iVar12 + 0x1c) >> 0xc & 3) + 1)) {
                uVar4 = 1;
              }
              *(uint *)(iVar7 + 0x20) = *(uint *)(iVar7 + 0x20) | uVar4;
            }
            loopIndex2 = loopIndex2 + 1;
          } while (loopIndex2 < 4);
          uVar2 = uVar2 + 1;
        } while ((int)uVar2 <= local_5c);
      }
      loopIndex3 = loopIndex3 + 1;
      iVar12 = iVar12 + 8;
      iVar15 = iVar15 + 8;
    } while (loopIndex3 < validArgs);
  }
  uVar2 = *(uint *)(param_3 + 0x14);
  local_70[1] = uVar2 >> 0xe & 1;
  local_70[3] = uVar2 >> 0x10 & 1;
  local_70[0] = uVar2 >> 0xd & 1;
  local_70[2] = uVar2 >> 0xf & 1;
  *(undefined4 *)(iVar3 + -0x14) = 0;
  allocation = _malloc(4);
  *(undefined4 *)(iVar3 + -0x10) = allocation;
  *(uint *)(iVar3 + -0xc) =
       *(uint *)(iVar3 + -0xc) | (uint)((*(uint *)(param_3 + 0x14) >> 0x11 & 7) == 3);
  uVar4 = *(uint *)(param_3 + 0x14);
  uVar2 = *(uint *)(param_3 + 0x18);
  ((int (*)())_GetRegisterIndicies)(*param_1,&local_58,local_54,uVar4 >> 0x11 & 7,uVar2 & 0xffff,uVar2 >> 0x1f,
             uVar4 >> 0xc & 1,uVar4 >> 10 & 3);
  if (local_58 <= local_54[0]) {
    iVar12 = local_58;
    do {
      loopIndex = 0;
      puVar13 = local_70;
      do {
        uVar4 = *puVar13;
        puVar13 = puVar13 + 1;
        if (uVar4 != 0) {
          iVar6 = ((int (*)())_GetRegister)(param_1,*(uint *)(param_3 + 0x14) >> 0x11 & 7,iVar12,loopIndex);
          if (iVar6 != 0) {
            iVar6 = *(int *)(iVar3 + -0x14) + 1;
            *(int *)(iVar3 + -0x14) = iVar6;
            iVar6 = _realloc(*(undefined4 *)(iVar3 + -0x10),iVar6 * 4);
            *(int *)(iVar3 + -0x10) = iVar6;
            iVar6 = iVar6 + *(int *)(iVar3 + -0x14) * 4;
            registerValue = ((int (*)())_GetRegister)(param_1,*(uint *)(param_3 + 0x14) >> 0x11 & 7,iVar12,loopIndex);
            *(int *)(iVar6 + -4) = registerValue;
            uVar4 = 0;
            *(uint *)(registerValue + 0x1c) = *(uint *)(registerValue + 0x1c) | *(uint *)(param_3 + 0x18) >> 0x1f;
            iVar6 = *(int *)(iVar6 + -4);
            if (((*(uint *)(param_3 + 0x14) & 0x1000) != 0) &&
               (1 < (*(uint *)(param_3 + 0x14) >> 10 & 3) + 1)) {
              uVar4 = 1;
            }
            *(uint *)(iVar6 + 0x20) = *(uint *)(iVar6 + 0x20) | uVar4;
          }
          if ((bVar1 || (int)uVar2 < 0) &&
             (iVar6 = ((int (*)())_GetRegister)(param_1,*(uint *)(param_3 + 0x14) >> 0x11 & 7,iVar12,loopIndex),
             iVar6 != 0)) {
            iVar6 = *piVar11;
            *piVar11 = iVar6 + 1;
            allocation3 = _realloc(*(undefined4 *)(iVar3 + -0x18),(iVar6 + 1) * 4);
            iVar6 = *piVar11;
            *(int *)(iVar3 + -0x18) = allocation3;
            registerValue2 = ((int (*)())_GetRegister)(param_1,*(uint *)(param_3 + 0x14) >> 0x11 & 7,iVar12,loopIndex);
            *(undefined4 *)(allocation3 + iVar6 * 4 + -4) = registerValue2;
          }
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < 4);
      iVar12 = iVar12 + 1;
    } while (iVar12 <= local_54[0]);
  }
  if ((uVar9 != 0 || (int)uVar2 < 0) && (iVar12 = ((int (*)())_GetRegister)(param_1,4,0,0), iVar12 != 0)) {
    iVar12 = *piVar11;
    *piVar11 = iVar12 + 1;
    allocation4 = _realloc(*(undefined4 *)(iVar3 + -0x18),(iVar12 + 1) * 4);
    iVar12 = *piVar11;
    *(int *)(iVar3 + -0x18) = allocation4;
    registerValue2 = ((int (*)())_GetRegister)(param_1,4,0,0);
    *(undefined4 *)(allocation4 + iVar12 * 4 + -4) = registerValue2;
  }
  return piVar11;
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
int _Blockify(param_1)
  int *param_1;
{
  int block2;
  int iVar1;
  int iVar2;
  int block;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 local_30 [6];
  
  _memset(param_1[6],0,param_1[5] << 2);
  ((int (*)())_GetOrAddBlock)(param_1,0);
  iVar7 = **(int **)(*param_1 + 0x20);
  while (iVar7 != 0) {
    iVar5 = *(int *)(iVar7 + 8);
    uVar4 = *(uint *)(iVar7 + 0xc);
    if (iVar5 != 0) {
      uVar4 = *(uint *)(iVar5 + 0xc);
    }
    uVar4 = uVar4 & 0x3ffff;
    switch(*(uint *)(iVar7 + 0xc) >> 0x12 & 0xff) {
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
      ((int (*)())_GetOrAddBlock)(param_1,uVar4);
    case 0x4c:
      uVar4 = *(uint *)(iVar7 + 0x10) & 0x3ffff;
      break;
    case 0x4d:
    case 0x59:
      break;
    default:
      goto switchD_97c0ac70_caseD_4e;
    }
    ((int (*)())_GetOrAddBlock)(param_1,uVar4);
    iVar5 = *(int *)(iVar7 + 8);
switchD_97c0ac70_caseD_4e:
    iVar7 = iVar5;
  }
  _memset(param_1[6],0,param_1[5] << 2);
  local_30[0] = 0;
  ((int (*)())_GetBlockFrom)(param_1,0,local_30);
  iVar5 = *param_1;
  iVar7 = **(int **)(iVar5 + 0x20);
  if (**(int **)(iVar5 + 0x20) != 0) {
    do {
      iVar5 = *(int *)(iVar7 + 8);
      uVar4 = *(uint *)(iVar7 + 0xc);
      if (iVar5 != 0) {
        uVar4 = *(uint *)(iVar5 + 0xc);
      }
      uVar4 = uVar4 & 0x3ffff;
      switch(*(uint *)(iVar7 + 0xc) >> 0x12 & 0xff) {
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
        ((int (*)())_GetBlockFrom)(param_1,uVar4,local_30);
      case 0x4c:
        uVar4 = *(uint *)(iVar7 + 0x10) & 0x3ffff;
        break;
      case 0x4d:
      case 0x59:
        break;
      default:
        goto switchD_97c0adac_caseD_4e;
      }
      ((int (*)())_GetBlockFrom)(param_1,uVar4,local_30);
      iVar5 = *(int *)(iVar7 + 8);
switchD_97c0adac_caseD_4e:
      iVar7 = iVar5;
    } while (iVar5 != 0);
    iVar5 = *param_1;
  }
  iVar1 = ((int (*)())_GetBlock)(param_1,0);
  iVar7 = **(int **)(iVar5 + 0x20);
  do {
    if (iVar7 == 0) {
      return;
    }
    uVar4 = *(uint *)(iVar7 + 0xc) & 0x3ffff;
    uVar6 = uVar4;
    if (*(int *)(iVar7 + 8) != 0) {
      uVar6 = *(uint *)(*(int *)(iVar7 + 8) + 0xc) & 0x3ffff;
    }
    block2 = ((int (*)())_GetBlock)(param_1,uVar4);
    iVar5 = iVar1;
    if (block2 != 0) {
      iVar5 = block2;
    }
    ((int (*)())_InstructionAdd)(param_1,iVar5,iVar7);
    iVar1 = iVar5;
    switch(*(uint *)(iVar7 + 0xc) >> 0x12 & 0xff) {
    case 0x4b:
    case 0x54:
    case 0x58:
    case 0x69:
      iVar2 = ((int (*)())_GetBlock)(param_1,uVar6);
      block = ((int (*)())_GetBlock)(param_1,*(uint *)(iVar7 + 0x10) & 0x3ffff);
      goto LAB_97c0b02c;
    case 0x4c:
      break;
    case 0x4d:
      iVar1 = ((int (*)())_GetBlock)(param_1,uVar6);
      break;
    default:
      block = ((int (*)())_GetBlock)(param_1,uVar6);
      iVar2 = block;
      if (block != 0) goto LAB_97c0b02c;
      break;
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x5a:
    case 0x5b:
    case 0x6a:
    case 0x6b:
      iVar2 = ((int (*)())_GetBlock)(param_1,uVar6);
      block = ((int (*)())_GetBlock)(param_1,*(uint *)(iVar7 + 0x10) & 0x3ffff);
      ((int (*)())_BlockAddSuccessor)(iVar5,iVar2);
      goto LAB_97c0b02c;
    case 0x59:
      block = ((int (*)())_GetBlock)(param_1,uVar6);
      iVar2 = block;
LAB_97c0b02c:
      iVar1 = iVar2;
      ((int (*)())_BlockAddSuccessor)(iVar5,block);
    }
    iVar7 = *(int *)(iVar7 + 8);
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
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  iVar11 = **(int **)(stream + 0x20);
  do {
    while( true ) {
      if (iVar11 == 0) {
        return;
      }
      iVar10 = iVar11;
      if ((*(uint *)(iVar11 + 0xc) >> 0x12 & 0xff) == 0x55) break;
LAB_97c0b480:
      iVar11 = *(int *)(iVar10 + 8);
    }
    iVar7 = 0;
    bVar2 = true;
    uVar8 = *(uint *)(iVar11 + 0x10) & 0x3ffff;
    iVar4 = 0;
    iVar9 = iVar11;
    do {
      if (((*(uint *)(iVar9 + 0xc) & 0x3ffff) == uVar8) && (iVar4 != 0)) {
        uVar3 = *(uint *)(iVar4 + 0xc) >> 0x12 & 0xff;
        if (uVar3 == 0x58) {
          uVar8 = *(uint *)(iVar4 + 0x10) & 0x3ffff;
          iVar7 = iVar4;
        }
        else {
          iVar6 = iVar4;
          if (uVar3 == 0x59) break;
        }
      }
      switch(*(uint *)(iVar9 + 0xc) >> 0x12 & 0xff) {
      case 0x4b:
      case 0x54:
      case 0x69:
        if (uVar8 < (*(uint *)(iVar9 + 0x10) & 0x3ffff)) goto switchD_97c0b318_caseD_4c;
        break;
      case 0x4c:
      case 0x4d:
switchD_97c0b318_caseD_4c:
        bVar2 = false;
      }
      iVar4 = ((int (*)())_GetValidArgs)(iVar9);
      if (0 < iVar4) {
        puVar5 = (uint *)(iVar9 + 0x1c);
        do {
          uVar3 = *puVar5;
          puVar5 = puVar5 + 2;
          if ((int)uVar3 < 0) {
            bVar2 = false;
          }
          if (((uVar3 & 0x4000) != 0) && (1 < (uVar3 >> 0xc & 3) + 1)) {
            bVar2 = false;
          }
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      uVar3 = *(uint *)(iVar9 + 0x14);
      if ((uVar3 & 0x1e000) != 0) {
        if (*(int *)(iVar9 + 0x18) < 0) {
          bVar2 = false;
        }
        if (((uVar3 & 0x1000) != 0) && (1 < (uVar3 >> 10 & 3) + 1)) {
          bVar2 = false;
        }
      }
      piVar1 = (int *)(iVar9 + 8);
      iVar4 = iVar9;
      iVar6 = 0;
      iVar9 = *piVar1;
    } while (*piVar1 != 0);
    if (!bVar2) goto LAB_97c0b480;
    iVar10 = *(int *)(iVar11 + 4);
    _FlattenIf(stream,iVar11,iVar7,iVar6);
    if (iVar10 != 0) goto LAB_97c0b480;
    iVar11 = **(int **)(stream + 0x20);
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
int _AddTempRegister(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
{
  undefined4 maxIndex;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  maxIndex = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(param_1 + 4));
  local_30 = (param_4 & 3) << 0x18 | (param_3 & 7) << 0x1a | param_2 << 0x1d | local_30 & 0xffffff;
  local_2c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_2c) + 0)),(short)maxIndex + 1);
  _PPStreamAddTempUsage(param_1,&local_30);
  return local_2c & 0xffff;
}

/* _AddConstantParam @ 0x97c0b550 (436 bytes) */
int _AddConstantParam(param_1, param_2, param_3, param_4, param_5_w, param_6_w, param_7_w, param_8_w)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  unsigned int param_5_w;
  unsigned int param_6_w;
  unsigned int param_7_w;
  unsigned int param_8_w;
{
  float param_5 = GH_U2F(param_5_w);
  float param_6 = GH_U2F(param_6_w);
  float param_7 = GH_U2F(param_7_w);
  float param_8 = GH_U2F(param_8_w);
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  float fStack00000028;
  float fStack0000002c;
  float fStack00000030;
  float fStack00000034;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  longlong local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_50 = param_5;
  local_4c = param_6;
  local_48 = param_7;
  local_44 = param_8;
  if (param_3 != 1) {
    local_50 = GH_U2F((unsigned int)((int)param_5));
    local_4c = GH_U2F((unsigned int)((int)param_6));
    local_48 = GH_U2F((unsigned int)((int)param_7));
    local_44 = GH_U2F((unsigned int)((int)param_8));
    local_40 = (longlong)(int)GH_F2U(local_44);
  }
  piVar4 = *(int **)(param_1 + 0x10);
  iVar5 = *piVar4;
  fStack00000028 = param_5;
  fStack0000002c = param_6;
  fStack00000030 = param_7;
  fStack00000034 = param_8;
  if (iVar5 != 0) {
    do {
      uVar3 = *(uint *)(iVar5 + 0xc);
      if (((((uVar3 >> 0x10 & 0x1f) == 0x11) && ((uVar3 >> 0x1a & 7) == param_3)) &&
          ((uVar3 >> 0x18 & 3) == param_4)) && (uVar3 >> 0x1d == param_2)) {
        iVar1 = _PPStreamChunkListChunkAtIndex(*(undefined4 *)(param_1 + 0x2c),uVar3 & 0xffff);
        iVar1 = _memcmp(&local_50,iVar1 + 0xc,0x10);
        if (iVar1 == 0) {
          return *(undefined2 *)(iVar5 + 0x12);
        }
      }
      iVar5 = *(int *)(iVar5 + 8);
    } while (iVar5 != 0);
    piVar4 = *(int **)(param_1 + 0x10);
  }
  local_2c = 0;
  local_30 = 0x110000;
  local_28 = 0;
  uVar2 = _PPStreamChunkListGetMaxIndex(piVar4);
  uVar3 = (uint)local_30 >> 0x10;
  local_2c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_2c) + 0)),(short)uVar2 + 1);
  local_30 = CONCAT22((ushort)((param_2 << 0x1d) >> 0x10) |
                      (ushort)(((param_4 & 3) << 0x18) >> 0x10) |
                      (ushort)(((param_3 & 7) << 0x1a) >> 0x10) | (ushort)uVar3 & 0xff,
                      *(undefined2 *)(*(int *)(param_1 + 0x2c) + 10));
  _PPStreamAddConstant(param_1,&local_50);
  _PPStreamAddParamBinding(param_1,&local_30);
  return (*(unsigned short *)((unsigned char *)&(local_2c) + 2));
}

