#include "decls.h"

/* Scheduler__allocateRegisterForNode @ 0x16c970 (1108 bytes) */
int Scheduler__allocateRegisterForNode(scheduler, node)
  int *scheduler;
  int node;
{
  uint nodeReg;
  uint instFlags;
  int nodeInstAlias;
  int consumerCounterCursor;
  int memberInst2;
  int threadLimit;
  int liveOutSet;
  int nodeInst;
  int nodeIssueCycle;
  int memberInstAlias;
  int memberInst;
  int componentsLeft;
  int groupCycleBound;
  int componentIndex;
  bool noHwRegister;
  int flagBit0Result;
  uint setWordOffset;
  int componentsLeft2;
  uint groupReg;
  char *laneByteCursor;
  int registerCount;
  char *groupRegionCursor;
  int *inst;
  char *groupRecord;
  int componentsLeft3;
  
  inst = *(int **)(node + 0x38);
  if (((((inst[5] & 0x20U) == 0) && (inst[0x20] != 0)) &&
      (flagBit0Result = RegKind__flagBit0(inst[0x26]), flagBit0Result != 0)) && ((inst[5] & 2U) == 0)) {
    (**(code **)(*inst + 0x50))(inst);
  }
  groupRecord = *(char **)(node + 0x60);
  if (groupRecord != (char *)0x0) {
    componentsLeft2 = 4;
    componentIndex = 0;
    laneByteCursor = groupRecord;
    groupRegionCursor = groupRecord;
    do {
      if (((*laneByteCursor != '\0') && (*(int *)(groupRegionCursor + 0x18) != 0)) &&
         (0 < *(int *)(componentIndex * 4 + *(int *)(groupRegionCursor + 0x18) + 0x48))) {
        return;
      }
      componentIndex = componentIndex + 1;
      laneByteCursor = laneByteCursor + 1;
      groupRegionCursor = groupRegionCursor + 4;
      componentsLeft2 = componentsLeft2 + -1;
    } while (componentsLeft2 != 0);
    groupReg = *(uint *)(groupRecord + 4);
    if ((-1 < (int)groupReg) && ((int)groupReg < scheduler[0x51])) {
      groupCycleBound = *(int *)(groupRecord + 0x14);
      if (groupCycleBound == 0) {
        liveOutSet = scheduler[0x4c];
        setWordOffset = groupReg >> 3 & 0x1ffffffc;
      }
      else {
        liveOutSet = scheduler[0x4c];
        setWordOffset = groupReg >> 3 & 0x1ffffffc;
        if ((*(uint *)(setWordOffset + liveOutSet + 8) >> (groupReg & 0x1f) & 1) != 0) goto LAB_0016cd84;
      }
      if ((*(uint *)(setWordOffset + liveOutSet + 8) >> (groupReg & 0x1f) & 1) == 0) {
        return;
      }
      componentsLeft = 4;
      inst = scheduler;
      laneByteCursor = groupRecord;
      do {
        if (*laneByteCursor != '\0') {
          *(int *)(*(int *)(groupRecord + 4) * 4 + inst[0x54]) = scheduler[0xb];
        }
        laneByteCursor = laneByteCursor + 1;
        inst = inst + 1;
        componentsLeft = componentsLeft + -1;
      } while (componentsLeft != 0);
      return;
    }
    groupCycleBound = *(int *)(groupRecord + 0x14);
LAB_0016cd84:
    threadLimit = (**(code **)(*(int *)scheduler[3] + 0x18))((int *)scheduler[3]);
    if ((threadLimit <= groupCycleBound) &&
       (threadLimit = Scheduler__findFreeHwRegister(scheduler,*(undefined4 *)groupRecord,groupCycleBound,1), -1 < threadLimit)) {
      registerCount = scheduler[0x51];
      memberInst = *(int *)(*(int *)(groupRecord + 8) + 0x38);
      while( true ) {
        if (memberInst == 0) {
          return;
        }
        *(int *)(memberInst + 0x94) = threadLimit + registerCount;
        if ((*(uint *)(memberInst + 0x14) & 0x200) == 0) break;
        memberInst = IRInst__getOperandSource(memberInst,*(undefined4 *)(memberInst + 0x84));
      }
      return;
    }
    groupCycleBound = Scheduler__findFreeHwRegister(scheduler,*(undefined4 *)groupRecord,groupCycleBound,0);
    noHwRegister = groupCycleBound < 0;
    if (noHwRegister) {
      groupCycleBound = *(int *)(*scheduler + 0x3c4) + 1;
      *(int *)(*scheduler + 0x3c4) = groupCycleBound;
    }
    memberInst2 = *(int *)(*(int *)(groupRecord + 8) + 0x38);
    while( true ) {
      if (memberInst2 == 0) {
        return;
      }
      *(int *)(memberInst2 + 0x94) = groupCycleBound;
      if (noHwRegister) {
        instFlags = *(uint *)(memberInst2 + 0x14) & 0xffffffbf;
        *(uint *)(memberInst2 + 0x14) = instFlags;
      }
      else {
        instFlags = *(uint *)(memberInst2 + 0x14) | 0x40;
        *(uint *)(memberInst2 + 0x14) = instFlags;
      }
      if ((instFlags & 0x200) == 0) break;
      memberInst2 = IRInst__getOperandSource(memberInst2,*(undefined4 *)(memberInst2 + 0x84));
    }
    return;
  }
  nodeInstAlias = *(int *)(node + 0x38);
  componentsLeft3 = 4;
  memberInstAlias = nodeInstAlias;
  consumerCounterCursor = node;
  do {
    if ((*(char *)(memberInstAlias + 0xc) != '\0') && (0 < *(int *)(consumerCounterCursor + 0x48))) {
      return;
    }
    memberInstAlias = memberInstAlias + 1;
    consumerCounterCursor = consumerCounterCursor + 4;
    componentsLeft3 = componentsLeft3 + -1;
  } while (componentsLeft3 != 0);
  nodeReg = *(uint *)(nodeInstAlias + 0x94);
  if (((*(uint *)(nodeInstAlias + 0x14) & 0x40) == 0) || (scheduler[0x51] <= (int)nodeReg)) {
    nodeIssueCycle = *(int *)(node + 0x2c);
LAB_0016cd5c:
    threadLimit = (**(code **)(*(int *)scheduler[3] + 0x18))((int *)scheduler[3]);
    if ((nodeIssueCycle < threadLimit) ||
       (threadLimit = Scheduler__findFreeHwRegister(scheduler,*(undefined4 *)(*(int *)(node + 0x38) + 0xc),nodeIssueCycle,1),
       threadLimit < 0)) {
      nodeIssueCycle = Scheduler__findFreeHwRegister(scheduler,*(undefined4 *)(*(int *)(node + 0x38) + 0xc),nodeIssueCycle,0);
      noHwRegister = nodeIssueCycle < 0;
      if (noHwRegister) {
        nodeIssueCycle = *(int *)(*scheduler + 0x3c4) + 1;
        *(int *)(*scheduler + 0x3c4) = nodeIssueCycle;
      }
      *(int *)(*(int *)(node + 0x38) + 0x94) = nodeIssueCycle;
      nodeInst = *(int *)(node + 0x38);
      if (noHwRegister) {
        *(uint *)(nodeInst + 0x14) = *(uint *)(nodeInst + 0x14) & 0xffffffbf;
      }
      else {
        *(uint *)(nodeInst + 0x14) = *(uint *)(nodeInst + 0x14) | 0x40;
      }
    }
    else {
      *(int *)(*(int *)(node + 0x38) + 0x94) = threadLimit + scheduler[0x51];
    }
  }
  else {
    nodeIssueCycle = *(int *)(node + 0x2c);
    if (nodeIssueCycle == 0) {
      liveOutSet = scheduler[0x4c];
      setWordOffset = nodeReg >> 3 & 0x1ffffffc;
    }
    else {
      liveOutSet = scheduler[0x4c];
      setWordOffset = nodeReg >> 3 & 0x1ffffffc;
      if ((*(uint *)(setWordOffset + liveOutSet + 8) >> (nodeReg & 0x1f) & 1) != 0) goto LAB_0016cd5c;
    }
    if ((*(uint *)(setWordOffset + liveOutSet + 8) >> (nodeReg & 0x1f) & 1) != 0) {
      componentsLeft2 = 4;
      componentIndex = 0;
      inst = scheduler;
      while( true ) {
        if (*(char *)(nodeInstAlias + componentIndex + 0xc) != '\0') {
          *(int *)(inst[0x54] + nodeReg * 4) = scheduler[0xb];
        }
        componentIndex = componentIndex + 1;
        inst = inst + 1;
        componentsLeft2 = componentsLeft2 + -1;
        if (componentsLeft2 == 0) break;
        nodeInstAlias = *(int *)(node + 0x38);
      }
    }
  }
  return;
}

/* Scheduler__releaseOperandsOfIssuedNode @ 0x16cdc4 (1516 bytes) */
int Scheduler__releaseOperandsOfIssuedNode(scheduler, node)
  undefined4 *scheduler;
  int node;
{
  int group;
  int componentIndex;
  int operandNumber;
  int schedulerReorderPwEnabled;
  int counterCursor;
  undefined4 *writerArrayCursor;
  uint producerFlags;
  bool moreComponents;
  char *groupSelectCursor;
  uint vectorCount;
  undefined4 *predEdgeSlot;
  int isMix;
  undefined4 operandVReg;
  int operandRecord;
  uint predEdgeCount;
  int *inst;
  int *producerInst;
  uint loopIndex;
  int producerNode;
  uint *predecessorEdges;
  int *edge;
  undefined4 destSelectBytes [7];
  
  loopIndex = 0;
  predecessorEdges = *(uint **)(node + 0x44);
  inst = *(int **)(node + 0x38);
  predEdgeCount = predecessorEdges[1];
  if (0 < (int)predEdgeCount) {
    while( true ) {
      if (loopIndex < *predecessorEdges) {
        vectorCount = predecessorEdges[1];
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + predecessorEdges[2],0,(loopIndex - vectorCount) * 4 + 4);
          predecessorEdges[1] = loopIndex + 1;
        }
        predEdgeSlot = (undefined4 *)(loopIndex * 4 + predecessorEdges[2]);
      }
      else {
        predEdgeSlot = (undefined4 *)Vector__elementRefGrow(predecessorEdges,loopIndex);
      }
      loopIndex = loopIndex + 1;
      edge = (int *)*predEdgeSlot;
      if (edge[2] == 0) {
        producerNode = *edge;
        isMix = (**(code **)(*inst + 0x60))(inst);
        if ((isMix != 0) &&
           (isMix = (**(code **)(**(int **)(producerNode + 0x38) + 0x5c))(*(int **)(producerNode + 0x38)),
           isMix != 0)) {
          DList__unlink(producerNode);
        }
        counterCursor = producerNode;
        do {
          if (((((*(char *)(edge + 6) != '\0') &&
                (operandRecord = *(int *)(counterCursor + 0x48) + -1, *(int *)(counterCursor + 0x48) = operandRecord, operandRecord == 0))
               && (producerInst = *(int **)(producerNode + 0x38), (producerInst[5] & 0x20U) == 0)) &&
              ((producerInst[0x20] != 0 && (operandRecord = RegKind__flagBit0(producerInst[0x26]), operandRecord != 0)))) &&
             (((producerInst[5] & 2U) == 0 &&
              ((operandRecord = (**(code **)(*producerInst + 0x50))(producerInst), operandRecord == 0 &&
               (operandRecord = Compiler__isOptionEnabled(*scheduler,0x25), operandRecord != 0)))))) {
            if (scheduler[0x58] == 0) {
              if ((int)scheduler[0x51] <= *(int *)(*(int *)(producerNode + 0x38) + 0x94)) {
                Scheduler__assignFreshVirtualRegister(scheduler,producerNode);
              }
            }
            else {
              ((int (*)())Scheduler__allocateRegisterForNode)(scheduler,producerNode);
            }
          }
          counterCursor = counterCursor + 4;
          edge = (int *)((int)edge + 1);
        } while (producerNode + 0x10 != counterCursor);
      }
      if (predEdgeCount == loopIndex) break;
      predecessorEdges = *(uint **)(node + 0x44);
    }
  }
  schedulerReorderPwEnabled = Compiler__isOptionEnabled(*scheduler,0x26);
  if (schedulerReorderPwEnabled != 0) {
    producerNode = 1;
    schedulerReorderPwEnabled = Compiler__isOptionEnabled(*scheduler,0x25);
    if (schedulerReorderPwEnabled != 0) {
      for (; schedulerReorderPwEnabled = (**(code **)(*inst + 0x14))(inst), producerNode <= schedulerReorderPwEnabled; producerNode = producerNode + 1) {
        operandVReg = IRInst__getOperandSource(inst,producerNode);
        while (schedulerReorderPwEnabled = IRInst__getOperandSource(operandVReg,0), schedulerReorderPwEnabled != 0) {
          operandVReg = IRInst__getOperandSource(operandVReg,0);
        }
        IRInst__setOperandSource(inst,producerNode,operandVReg,0,*scheduler);
      }
      goto LAB_0016d0d8;
    }
  }
  if (((inst[5] & 0x200U) != 0) &&
     (schedulerReorderPwEnabled = IRInst__getOperandSource(inst,inst[0x21]), (*(uint *)(schedulerReorderPwEnabled + 0x14) & 1) == 0)) {
    IRInst__setOperandSource(inst,inst[0x21],0,0,*scheduler);
    inst[5] = inst[5] & 0xfffffdff;
    producerFlags = *(uint *)(schedulerReorderPwEnabled + 0x14);
    inst[0x21] = inst[0x21] + -1;
    if ((producerFlags & 0x200) != 0) {
      operandVReg = IRInst__getOperandSource(schedulerReorderPwEnabled,*(undefined4 *)(schedulerReorderPwEnabled + 0x84));
      IRInst__setExtraOperandSource(inst,operandVReg,0,*scheduler);
    }
  }
LAB_0016d0d8:
  operandNumber = Compiler__isOptionEnabled(*scheduler,0x25);
  if ((operandNumber != 0) && (operandNumber = *(int *)(node + 0x60), operandNumber != 0)) {
    producerNode = *(int *)(operandNumber + 4);
    if (-1 < producerNode) {
      inst[0x25] = producerNode;
      inst[5] = inst[5] | 0x40;
      componentIndex = 0;
      writerArrayCursor = scheduler;
      do {
        operandRecord = IRInst__getOperandRecord(inst,0);
        if (*(char *)(componentIndex + operandRecord + 0x10) != '\x01') {
          *(int *)(writerArrayCursor[0x4d] + producerNode * 4) = node;
          if ((writerArrayCursor[0x54] != 0) && (*(int *)(*(int *)(node + 0x60) + 0x14) == 0)) {
            *(undefined4 *)(writerArrayCursor[0x54] + producerNode * 4) = 0x7fffffff;
          }
        }
        moreComponents = componentIndex != 3;
        writerArrayCursor = writerArrayCursor + 1;
        componentIndex = componentIndex + 1;
      } while (moreComponents);
      operandNumber = *(int *)(node + 0x60);
    }
    if (*(int *)(node + 0x2c) < *(int *)(operandNumber + 0x14)) {
      *(int *)(operandNumber + 0x14) = *(int *)(node + 0x2c);
    }
    operandNumber = 0;
    do {
      producerNode = IRInst__getOperandRecord(inst,0);
      if (*(char *)(operandNumber + producerNode + 0x10) != '\x01') {
        *(int *)(operandNumber * 4 + *(int *)(node + 0x60) + 0x18) = node;
      }
      moreComponents = operandNumber != 3;
      operandNumber = operandNumber + 1;
    } while (moreComponents);
  }
  edge = *(int **)(node + 0x38);
  if (((((edge[5] & 0x20U) == 0) && (edge[0x20] != 0)) &&
      (operandNumber = RegKind__flagBit0(edge[0x26]), operandNumber != 0)) &&
     (((edge[5] & 2U) == 0 && (operandNumber = (**(code **)(*edge + 0x50))(edge), operandNumber == 0)))) {
    if ((*(int *)(node + 0x60) == 0) ||
       (operandNumber = *(int *)(*(int *)(node + 0x60) + 8), operandNumber == 0)) {
      operandNumber = 0;
    }
    else {
      operandNumber = *(int *)(operandNumber + 0x38);
    }
    producerNode = Compiler__isOptionEnabled(*scheduler,0x26);
    if ((producerNode != 0) && (producerNode = Compiler__isOptionEnabled(*scheduler,0x25), producerNode != 0)) {
      if (operandNumber == 0) {
        if ((*(uint *)(*(int *)(node + 0x38) + 0x14) & 0x200) != 0) {
          IRInst__setOperandSource(inst,inst[0x21],0,0,*scheduler);
          inst[0x21] = inst[0x21] + -1;
          inst[5] = inst[5] & 0xfffffdff;
        }
      }
      else {
        IRInst__setOperandSource(operandNumber,0,*(undefined4 *)(node + 0x38),0,*scheduler);
        IRInst__setExtraOperandSource(inst,operandNumber,0,*scheduler);
      }
    }
    if ((*(int *)(node + 0x60) != 0) &&
       (operandNumber = IRInst__getOperandRecord(inst,0), *(int *)(operandNumber + 0x10) != 0x1010101)) {
      group = *(int *)(node + 0x60);
      if ((*(int *)(group + 8) == 0) || (*(int *)(*(int *)(group + 8) + 0x2c) != scheduler[0xb])) {
        producerNode = IRInst__getOperandRecord(*(undefined4 *)(node + 0x38),0);
        *(undefined4 *)(group + 0xc) = *(undefined4 *)(producerNode + 0x10);
      }
      else {
        producerNode = IRInst__getOperandRecord(*(undefined4 *)(node + 0x38),0);
        groupSelectCursor = (char *)(group + 0xc);
        componentIndex = 0;
        destSelectBytes[0] = *(undefined4 *)(producerNode + 0x10);
        producerNode = 4;
        do {
          if (*(char *)((int)destSelectBytes + componentIndex) != '\x01') {
            *groupSelectCursor = *(char *)((int)destSelectBytes + componentIndex);
          }
          componentIndex = componentIndex + 1;
          groupSelectCursor = groupSelectCursor + 1;
          producerNode = producerNode + -1;
        } while (producerNode != 0);
      }
      *(int *)(*(int *)(node + 0x60) + 8) = node;
    }
  }
  return;
}

/* Scheduler__issueNode @ 0x16d3b0 (392 bytes) */
int Scheduler__issueNode(scheduler, node)
  int *scheduler;
  int node;
{
  int cycleOrCheck;
  int vcalld4Result;
  int vcall5cResult;
  
  vcall5cResult = (**(code **)(**(int **)(node + 0x38) + 0x5c))(*(int **)(node + 0x38),node);
  if (vcall5cResult == 0) {
    (**(code **)(*(int *)scheduler[2] + 0x74))((int *)scheduler[2],node,scheduler[0xc]);
  }
  else {
    DList__pushBack(scheduler + 0x25,node);
  }
  cycleOrCheck = scheduler[0xb];
  *(int *)(node + 0x2c) = cycleOrCheck;
  *(int *)(node + 0x30) = cycleOrCheck;
  (**(code **)(*(int *)scheduler[2] + 0x10))((int *)scheduler[2],*(undefined4 *)(node + 0x38));
  ((int (*)())SchedModel__uncountNode)(scheduler[2],node);
  (**(code **)(*(int *)scheduler[3] + 0x10))((int *)scheduler[3],node);
  ((int (*)())Scheduler__releaseOperandsOfIssuedNode)(scheduler,node);
  vcalld4Result = (**(code **)(**(int **)(*scheduler + 0x30c) + 0xd4))(*(int **)(*scheduler + 0x30c));
  if ((vcalld4Result != 0) && ((*(uint *)(*(int *)(node + 0x38) + 0x14) & 0x1000) != 0)) {
    ((int (*)())Scheduler__splitAddressRegisterUses)(scheduler);
  }
  ((int (*)())Scheduler__updateSuccessorsAfterIssue)(scheduler,node);
  cycleOrCheck = (**(code **)(*(int *)scheduler[3] + 0x20))
                    ((int *)scheduler[3],*(undefined4 *)(node + 0x38));
  if (((cycleOrCheck != 0) ||
      (cycleOrCheck = (**(code **)(*(int *)scheduler[3] + 0x24))
                         ((int *)scheduler[3],*(undefined4 *)(node + 0x38)), cycleOrCheck != 0)) &&
     (scheduler[0x4a] <= *(int *)(node + 0xc))) {
    scheduler[0x4b] = scheduler[0x4b] + 1;
  }
  return;
}

/* Scheduler__tryReuseAddressRegister @ 0x16d538 (1996 bytes) */
int Scheduler__tryReuseAddressRegister(scheduler, node)
  int *scheduler;
  int node;
{
  undefined *selectTable;
  undefined4 edgeTarget;
  uint slotIndex;
  uint slotGroupEnd;
  int compiler;
  int consumerNode2;
  int nodeAddressSource;
  int succEdge2;
  int consumerNode;
  int succEdge;
  int reusedSelectRecord;
  int slotCount;
  int newLoadNode;
  int canAdd;
  int spareInst;
  int existingLoadNode;
  int scanLoadNode;
  int reusedLoadNode;
  undefined4 sourceDef2;
  int operandRecord2;
  int sourceDef3;
  int operandRecord;
  int operandRecord3;
  int sourceDef;
  uint loopIndex2;
  uint loopIndex;
  bool moreComponents;
  undefined *slotSelectTable;
  int slotLane;
  uint vectorCount;
  int *addressRegisterSlot;
  undefined4 a3;
  undefined4 in_r7;
  int *in_r8;
  int *a0;
  uint componentSelect;
  int slotComponent;
  uint chosenSlot;
  int nodeInst;
  uint bestSlot;
  int firstWrittenComponent;
  int reusedLoadInst;
  undefined4 selectConst;
  uint *succEdges;
  undefined4 selectConst2;
  undefined4 laneMask [8];
  
  IRInst__isProjectionOfClass26or3a(*(undefined4 *)(node + 0x38));
  if (scheduler[0x61] < 0) {
    if (*(int *)(*(int *)(node + 0x38) + 0x98) == 0x3a) {
      scheduler[0x61] = 1;
    }
    else {
      scheduler[0x61] = *(int *)(*(int *)(*scheduler + 0x30c) + 0x1c);
    }
  }
  nodeInst = *(int *)(node + 0x38);
  firstWrittenComponent = 0;
  operandRecord = IRInst__getOperandRecord(nodeInst,1);
  SelectWord__isSplat(*(undefined4 *)(operandRecord + 0x10));
  do {
    operandRecord = IRInst__getOperandRecord(nodeInst,0);
    if (*(char *)(firstWrittenComponent + operandRecord + 0x10) != '\x01') {
      operandRecord = IRInst__getOperandRecord(nodeInst,1);
      componentSelect = (uint)*(byte *)(firstWrittenComponent + operandRecord + 0x10);
      goto LAB_0016d5f8;
    }
    moreComponents = firstWrittenComponent != 3;
    firstWrittenComponent = firstWrittenComponent + 1;
  } while (moreComponents);
  componentSelect = 4;
LAB_0016d5f8:
  slotCount = scheduler[0x61];
  if (0 < slotCount) {
    loopIndex = 0;
    addressRegisterSlot = scheduler;
    do {
      if (addressRegisterSlot[0x5c] != 0) {
        sourceDef3 = IRInst__getOperandSource(*(undefined4 *)(addressRegisterSlot[0x5c] + 0x38),1);
        sourceDef = IRInst__getOperandSource(nodeInst,1);
        if (sourceDef3 == sourceDef) {
          reusedLoadNode = addressRegisterSlot[0x5c];
          reusedLoadInst = *(int *)(reusedLoadNode + 0x38);
          slotComponent = loopIndex + (((int)loopIndex >> 2) + (uint)((int)loopIndex < 0 && (loopIndex & 3) != 0)) * -4;
          reusedSelectRecord = IRInst__getOperandRecord(reusedLoadInst,1);
          if ((componentSelect == *(byte *)(slotComponent + reusedSelectRecord + 0x10)) &&
             (reusedSelectRecord = (**(code **)(**(int **)(reusedLoadInst + 0x88) + 0x18))(*(int **)(reusedLoadInst + 0x88)),
             reusedSelectRecord == *(int *)(nodeInst + 300))) {
            IRInst__setOperandSource(nodeInst,1,reusedLoadInst,0,*scheduler);
            selectConst = *(undefined4 *)(PTR_DAT_001e8b8c + slotComponent * 4);
            operandRecord = IRInst__getOperandRecord(nodeInst,1);
            *(undefined4 *)(operandRecord + 0x10) = selectConst;
            if (*(int *)(reusedLoadNode + 0x6c) != 0) {
              *(int *)(node + 0x6c) = *(int *)(reusedLoadNode + 0x6c);
            }
            succEdges = *(uint **)(node + 0x40);
            loopIndex = 0;
            *(int *)(reusedLoadNode + 0x6c) = node;
            componentSelect = succEdges[1];
            if ((int)componentSelect < 1) {
              return 1;
            }
            while( true ) {
              if (loopIndex < *succEdges) {
                vectorCount = succEdges[1];
                if (vectorCount <= loopIndex) {
                  _memset(vectorCount * 4 + succEdges[2],0,(loopIndex - vectorCount) * 4 + 4);
                  succEdges[1] = loopIndex + 1;
                }
                addressRegisterSlot = (int *)(loopIndex * 4 + succEdges[2]);
              }
              else {
                addressRegisterSlot = (int *)Vector__elementRefGrow(succEdges,loopIndex);
              }
              loopIndex = loopIndex + 1;
              succEdge = *addressRegisterSlot;
              consumerNode = *(int *)(succEdge + 4);
              if (*(int *)(succEdge + 8) == 0) {
                laneMask[0] = 0;
                *(undefined1 *)((int)laneMask + slotComponent) = 1;
                Scheduler__addDataDependencyEdge(scheduler,reusedLoadNode,consumerNode,*(undefined4 *)(succEdge + 0x10),
                             *(undefined4 *)(succEdge + 0x14),laneMask[0],(uint)laneMask);
                *(int *)(consumerNode + 0x34) = *(int *)(consumerNode + 0x34) + -1;
              }
              if (componentSelect == loopIndex) break;
              succEdges = *(uint **)(node + 0x40);
            }
            return 1;
          }
        }
        slotCount = scheduler[0x61];
      }
      loopIndex = loopIndex + 1;
      addressRegisterSlot = addressRegisterSlot + 1;
    } while ((int)loopIndex < slotCount);
    if (0 < slotCount) {
      scanLoadNode = scheduler[0x5c];
      if (scanLoadNode == 0) {
        chosenSlot = 0;
        slotLane = 0;
      }
      else {
        loopIndex2 = 0;
        bestSlot = 0xffffffff;
        in_r8 = scheduler;
        do {
          if ((*(int *)((loopIndex2 + (((int)loopIndex2 >> 2) + (uint)((int)loopIndex2 < 0 && (loopIndex2 & 3) != 0)) *
                                 -4) * 4 + scanLoadNode + 0x48) == 0) &&
             (((int)bestSlot < 0 ||
              (*(int *)(scanLoadNode + 0x2c) < *(int *)(scheduler[bestSlot + 0x5c] + 0x2c))))) {
            bestSlot = loopIndex2;
          }
          loopIndex2 = loopIndex2 + 1;
          slotCount = slotCount + -1;
          chosenSlot = bestSlot;
          if (slotCount == 0) break;
          scanLoadNode = in_r8[0x5d];
          in_r8 = in_r8 + 1;
          chosenSlot = loopIndex2;
        } while (scanLoadNode != 0);
        if ((int)chosenSlot < 0) {
          return 0;
        }
        slotLane = chosenSlot + (((int)chosenSlot >> 2) + (uint)((int)chosenSlot < 0 && (chosenSlot & 3) != 0)) * -4;
      }
      slotIndex = chosenSlot - slotLane;
      slotGroupEnd = slotIndex + 4;
      addressRegisterSlot = scheduler + slotIndex + 0x5c;
      do {
        if ((((*(uint *)(*(int *)(*scheduler + 0x30c) + 8) & 0x200) == 0) && (*addressRegisterSlot != 0)) &&
           (slotIndex != chosenSlot)) {
          sourceDef = IRInst__getOperandSource(*(undefined4 *)(*addressRegisterSlot + 0x38),1);
          nodeAddressSource = IRInst__getOperandSource(nodeInst,1);
          if (sourceDef == nodeAddressSource) {
            existingLoadNode = *addressRegisterSlot;
            a0 = *(int **)(existingLoadNode + 0x38);
            if (*(int *)(nodeInst + 300) == 0) {
              if (*(int *)(a0[0x22] + 8) == 0xa6) goto LAB_0016d91c;
            }
            else if (*(int *)(a0[0x22] + 8) == 0x2b) {
LAB_0016d91c:
              if ((scheduler[chosenSlot + 0x5c] == 0) ||
                 (nodeAddressSource = SchedNode__getLastConsumerCycle(scheduler[chosenSlot + 0x5c],slotLane), nodeAddressSource < *(int *)(existingLoadNode + 0x2c)
                 )) {
                *(undefined1 *)((int)a0 + slotLane + 0x9c) = 0;
                (**(code **)(*a0 + 0x88))(a0,1,slotLane,componentSelect,in_r7,in_r8,*(code **)(*a0 + 0x88));
                *(undefined1 *)((int)a0 + slotLane + 0xc) = 1;
                compiler = *scheduler;
                scheduler[chosenSlot + 0x5c] = existingLoadNode;
                IRInst__setOperandSource(nodeInst,1,a0,0,compiler);
                selectConst = *(undefined4 *)(PTR_DAT_001e8b8c + slotLane * 4);
                operandRecord2 = IRInst__getOperandRecord(nodeInst,1);
                *(undefined4 *)(operandRecord2 + 0x10) = selectConst;
                if (*(int *)(existingLoadNode + 0x6c) != 0) {
                  *(int *)(node + 0x6c) = *(int *)(existingLoadNode + 0x6c);
                }
                succEdges = *(uint **)(node + 0x40);
                loopIndex = 0;
                *(int *)(existingLoadNode + 0x6c) = node;
                componentSelect = succEdges[1];
                if ((int)componentSelect < 1) {
                  return 1;
                }
                while( true ) {
                  if (loopIndex < *succEdges) {
                    vectorCount = succEdges[1];
                    if (vectorCount <= loopIndex) {
                      _memset(vectorCount * 4 + succEdges[2],0,(loopIndex - vectorCount) * 4 + 4);
                      succEdges[1] = loopIndex + 1;
                    }
                    addressRegisterSlot = (int *)(loopIndex * 4 + succEdges[2]);
                  }
                  else {
                    addressRegisterSlot = (int *)Vector__elementRefGrow(succEdges,loopIndex);
                  }
                  loopIndex = loopIndex + 1;
                  succEdge2 = *addressRegisterSlot;
                  consumerNode2 = *(int *)(succEdge2 + 4);
                  if (*(int *)(succEdge2 + 8) == 0) {
                    laneMask[0] = 0;
                    *(undefined1 *)((int)laneMask + slotLane) = 1;
                    Scheduler__addDataDependencyEdge(scheduler,existingLoadNode,consumerNode2,*(undefined4 *)(succEdge2 + 0x10),
                                 *(undefined4 *)(succEdge2 + 0x14),laneMask[0],(uint)laneMask);
                    *(int *)(consumerNode2 + 0x34) = *(int *)(consumerNode2 + 0x34) + -1;
                  }
                  if (componentSelect == loopIndex) break;
                  succEdges = *(uint **)(node + 0x40);
                }
                return 1;
              }
            }
          }
        }
        slotIndex = slotIndex + 1;
        addressRegisterSlot = addressRegisterSlot + 1;
      } while (slotGroupEnd != slotIndex);
      spareInst = (**(code **)(*(int *)scheduler[2] + 0x80))
                         ((int *)scheduler[2],scheduler[0x60],*(undefined4 *)(nodeInst + 300),
                          *(undefined4 *)(nodeInst + 0x130),*(int *)(nodeInst + 0x98) == 0x3a);
      slotSelectTable = PTR_DAT_001e8b64;
      scheduler[0x60] = spareInst;
      *(undefined4 *)(spareInst + 0x98) = 0x20;
      *(uint *)(spareInst + 0x94) = ((int)chosenSlot >> 2) + (uint)((int)chosenSlot < 0 && (chosenSlot & 3) != 0);
      *(undefined4 *)(scheduler[0x60] + 0x9c) = *(undefined4 *)(slotSelectTable + slotLane * 4);
      spareInst = scheduler[0x60];
      sourceDef2 = IRInst__getOperandSource(nodeInst,1);
      compiler = *scheduler;
      a3 = 0;
      IRInst__setOperandSource(spareInst,1,sourceDef2,0,compiler);
      selectTable = PTR_DAT_001e8b8c;
      selectConst2 = *(undefined4 *)(PTR_DAT_001e8b8c + componentSelect * 4);
      operandRecord3 = IRInst__getOperandRecord(scheduler[0x60],1);
      *(undefined4 *)(operandRecord3 + 0x10) = selectConst2;
      *(undefined4 *)(scheduler[0x60] + 0xc) = 0;
      spareInst = scheduler[0x60];
      *(undefined1 *)(spareInst + slotLane + 0xc) = 1;
      canAdd = (**(code **)(*(int *)scheduler[2] + 0xc))
                         ((int *)scheduler[2],scheduler[0x60],sourceDef2,a3,compiler,in_r8,spareInst + slotLane);
      if (canAdd != 0) {
        newLoadNode = Scheduler__createNode(scheduler,scheduler[0x60],node + 0xc,scheduler[0xb]);
        scheduler[0x60] = 0;
        scheduler[chosenSlot + 0x5c] = newLoadNode;
        IRInst__setOperandSource(nodeInst,1,*(undefined4 *)(newLoadNode + 0x38),0,*scheduler);
        selectConst = *(undefined4 *)(selectTable + slotLane * 4);
        operandRecord2 = IRInst__getOperandRecord(nodeInst,1);
        *(undefined4 *)(operandRecord2 + 0x10) = selectConst;
        loopIndex = 0;
        succEdges = *(uint **)(node + 0x40);
        *(int *)(newLoadNode + 0x6c) = node;
        componentSelect = succEdges[1];
        if (0 < (int)componentSelect) {
          while( true ) {
            if (loopIndex < *succEdges) {
              vectorCount = succEdges[1];
              if (vectorCount <= loopIndex) {
                _memset(vectorCount * 4 + succEdges[2],0,(loopIndex - vectorCount) * 4 + 4);
                succEdges[1] = loopIndex + 1;
              }
              addressRegisterSlot = (int *)(loopIndex * 4 + succEdges[2]);
            }
            else {
              addressRegisterSlot = (int *)Vector__elementRefGrow(succEdges,loopIndex);
            }
            loopIndex = loopIndex + 1;
            succEdge2 = *addressRegisterSlot;
            edgeTarget = *(undefined4 *)(succEdge2 + 4);
            if (*(int *)(succEdge2 + 8) == 0) {
              laneMask[0] = 0;
              *(undefined1 *)((int)laneMask + slotLane) = 1;
              Scheduler__addDataDependencyEdge(scheduler,newLoadNode,edgeTarget,*(undefined4 *)(succEdge2 + 0x10),
                           *(undefined4 *)(succEdge2 + 0x14),laneMask[0],(uint)laneMask);
            }
            if (componentSelect == loopIndex) break;
            succEdges = *(uint **)(node + 0x40);
          }
        }
        ((int (*)())Scheduler__issueNode)(scheduler,newLoadNode);
        return 1;
      }
    }
  }
  return 0;
}

/* Scheduler__tryReuseLoopIndexLoad @ 0x16dd04 (596 bytes) */
int Scheduler__tryReuseLoopIndexLoad(scheduler, node)
  int *scheduler;
  int node;
{
  undefined4 operandSource;
  undefined4 arena;
  int newLoadNode;
  bool lastFreeSlot;
  int *freeSlotCursor;
  int sourceDef2;
  int sourceDef;
  int loopIndex;
  bool lastSlot;
  int *loadSlotCursor2;
  int requestedIndex;
  int compiler;
  undefined4 *allocation;
  uint requestedIndex2;
  undefined4 inst;
  int loadSize;
  int slotNumber;
  int loadStart;
  int *loadSlotCursor;
  undefined4 *newLoadInst;
  int loadBaseReg;
  undefined4 defaultSelect;
  code *setSourceFn;
  int loadInst;
  
  slotNumber = 0;
  inst = *(undefined4 *)(node + 0x38);
  IRInst__isProjectionOfClass44(inst);
  loadSlotCursor2 = scheduler;
  loadSlotCursor = scheduler;
  do {
    if (loadSlotCursor[0x62] != 0) {
      loadInst = *(int *)(loadSlotCursor[0x62] + 0x38);
      loadBaseReg = *(int *)(loadInst + 0x130);
      loadStart = *(int *)(loadInst + 0x134);
      loadSize = *(int *)(loadInst + 300);
      requestedIndex = IRInst__getDefiningField128(inst,0);
      sourceDef2 = IRInst__getOperandSource(inst,1);
      if (loadBaseReg == *(int *)(sourceDef2 + 0x94)) {
        if ((loadStart <= requestedIndex) && (requestedIndex < loadStart + loadSize)) goto LAB_0016ddd8;
        if (loadSize == 0x10) {
          if ((loadStart <= requestedIndex) && (requestedIndex < loadStart + 0x20)) {
            *(undefined4 *)(loadInst + 300) = 0x20;
LAB_0016ddd8:
            IRInst__setOperandSource(inst,1,loadInst,0,*scheduler);
            *(undefined4 *)(node + 0x6c) = *(undefined4 *)(loadSlotCursor2[0x62] + 0x6c);
            *(int *)(loadSlotCursor2[0x62] + 0x6c) = node;
            return 1;
          }
          if ((loadStart + -0x10 <= requestedIndex) && (requestedIndex < loadStart + 0x10)) {
            *(undefined4 *)(loadInst + 300) = 0x20;
            *(int *)(loadInst + 0x134) = loadStart + -0x10;
            goto LAB_0016ddd8;
          }
        }
      }
    }
    lastSlot = slotNumber == 1;
    loadSlotCursor2 = loadSlotCursor2 + 1;
    loadSlotCursor = loadSlotCursor + 1;
    slotNumber = slotNumber + 1;
    if (lastSlot) {
      loopIndex = 0;
      freeSlotCursor = scheduler;
      do {
        if (freeSlotCursor[0x62] == 0) {
          if (loopIndex < 0) {
            return 0;
          }
          arena = *(undefined4 *)(*scheduler + 0x374);
          allocation = (undefined4 *)Arena__alloc(arena,0x168);
          *allocation = arena;
          newLoadInst = allocation + 1;
          IRLoad__ctor_109a80(newLoadInst,0xfa,*scheduler);
          requestedIndex2 = IRInst__getDefiningField128(inst,0);
          allocation[0x27] = 0x45;
          allocation[0x26] = loopIndex;
          sourceDef = IRInst__getOperandSource(inst,1);
          defaultSelect = DAT_001b0194;
          allocation[0x4d] = *(undefined4 *)(sourceDef + 0x94);
          allocation[0x4c] = 0x10;
          allocation[0x4e] = (((int)requestedIndex2 >> 4) + (uint)((int)requestedIndex2 < 0 && (requestedIndex2 & 0xf) != 0)) * 0x10;
          allocation[4] = defaultSelect;
          setSourceFn = *(code **)(allocation[1] + 0x94);
          operandSource = IRInst__getOperandSource(inst,1);
          (*setSourceFn)(newLoadInst,operandSource,*scheduler);
          newLoadNode = Scheduler__createNode(scheduler,newLoadInst,node + 0xc,scheduler[0xb]);
          compiler = *scheduler;
          scheduler[loopIndex + 0x62] = newLoadNode;
          IRInst__setOperandSource(inst,1,newLoadInst,0,compiler);
          *(int *)(newLoadNode + 0x6c) = node;
          ((int (*)())Scheduler__issueNode)(scheduler,newLoadNode);
          return 1;
        }
        lastFreeSlot = loopIndex != 1;
        freeSlotCursor = freeSlotCursor + 1;
        loopIndex = loopIndex + 1;
      } while (lastFreeSlot);
      return 0;
    }
  } while( true );
}

/* Scheduler__enqueueReadyNode @ 0x16df8c (536 bytes) */
int Scheduler__enqueueReadyNode(scheduler, node)
  int scheduler;
  int node;
{
  int compareResult;
  int compareNode;
  int consumerCounterCursor;
  int readyList;
  int nextCompareNode;
  int checkResult;
  int componentsLeft;
  int *nodeInst;
  
  Scheduler__isNodeReady(scheduler,node);
  readyList = scheduler + 0xf8;
  if (*(int *)(node + 0x68) == 0) {
    checkResult = (**(code **)(**(int **)(scheduler + 0xc) + 0x20))
                      (*(int **)(scheduler + 0xc),*(undefined4 *)(node + 0x38));
    if ((checkResult == 0) &&
       (checkResult = (**(code **)(**(int **)(scheduler + 0xc) + 0x24))
                          (*(int **)(scheduler + 0xc),*(undefined4 *)(node + 0x38)), checkResult == 0)) {
      if (((*(int *)(node + 0x58) == 0) &&
          (checkResult = IRInst__isProjectionOfClass26or3a(*(undefined4 *)(node + 0x38)), checkResult == 0)) &&
         (checkResult = IRInst__isProjectionOfClass44(*(undefined4 *)(node + 0x38)), checkResult == 0)) {
        ((int (*)())Scheduler__issueNode)(scheduler,node);
        return;
      }
      nodeInst = *(int **)(node + 0x38);
      if ((((nodeInst[5] & 0x20U) == 0) && (nodeInst[0x20] != 0)) &&
         ((checkResult = RegKind__flagBit0(nodeInst[0x26]), checkResult != 0 &&
          (((nodeInst[5] & 2U) == 0 && (checkResult = (**(code **)(*nodeInst + 0x50))(nodeInst), checkResult == 0)))))
         ) {
        componentsLeft = 4;
        consumerCounterCursor = node;
        while (*(int *)(consumerCounterCursor + 0x48) < 1) {
          consumerCounterCursor = consumerCounterCursor + 4;
          componentsLeft = componentsLeft + -1;
          if (componentsLeft == 0) {
            ((int (*)())Scheduler__issueDeadNode)(scheduler,node);
            return;
          }
        }
      }
      readyList = scheduler + 0x4c;
      compareNode = *(int *)(scheduler + 0x54);
      nextCompareNode = *(int *)(compareNode + 8);
      while (nextCompareNode != 0) {
        compareResult = Scheduler__compareNodes(scheduler,node,compareNode,0);
        if (0 < compareResult) {
LAB_0016e148:
          DList__insertBefore(node,compareNode);
          return;
        }
        compareNode = *(int *)(compareNode + 8);
        nextCompareNode = *(int *)(compareNode + 8);
      }
    }
    else {
      readyList = scheduler + 0x34;
      compareNode = *(int *)(scheduler + 0x3c);
      nextCompareNode = *(int *)(compareNode + 8);
      while (nextCompareNode != 0) {
        compareResult = Scheduler__compareNodes(scheduler,node,compareNode,0);
        if (0 < compareResult) goto LAB_0016e148;
        compareNode = *(int *)(compareNode + 8);
        nextCompareNode = *(int *)(compareNode + 8);
      }
    }
  }
  return DList__pushBack(readyList,node);
}

/* Scheduler__splitAddressRegisterUses @ 0x16e1a4 (1668 bytes) */
int Scheduler__splitAddressRegisterUses(scheduler)
  undefined4 *scheduler;
{
  undefined4 addressSelect;
  uint succEdgeCount2;
  uint succIndex2;
  uint vectorCount3;
  uint predEdgeCount;
  undefined4 *predEdgeSlot;
  undefined4 *appendSlot;
  uint *targetPredEdges;
  uint *copySuccEdges;
  int predByteOffset;
  int copyCountCursor2;
  int componentsLeft3;
  int pendingPreds;
  int copyCountCursor;
  int operandNumber;
  int edgeTarget;
  int loopIndexConsumer;
  uint vectorCount;
  uint vectorCount2;
  undefined4 clonedInst;
  undefined4 addressSource;
  uint succIndex;
  undefined4 *succEdgeSlot;
  int operandNumber2;
  int clonedNode;
  int addressComponent;
  uint loadSlot;
  uint predVisited;
  undefined4 *loadSlotCursor;
  int addressLoadNode;
  int *succEdge;
  int consumerNode;
  uint predIndex;
  uint *succEdges;
  uint succEdgeCount;
  int componentsLeft;
  int componentsLeft2;
  int operandCountOrNode;
  
  clonedNode = scheduler[0x61];
  if (0 < clonedNode) {
    loadSlot = 0;
    loadSlotCursor = scheduler;
    do {
      addressLoadNode = loadSlotCursor[0x5c];
      addressComponent = loadSlot + (((int)loadSlot >> 2) + (uint)((int)loadSlot < 0 && (loadSlot & 3) != 0)) * -4;
      if ((addressLoadNode != 0) && (*(int *)(addressLoadNode + 0x2c) < (int)scheduler[0xb])) {
        loadSlotCursor[0x5c] = 0;
        if ((0 < *(int *)(addressComponent * 4 + addressLoadNode + 0x48)) &&
           (consumerNode = *(int *)(addressLoadNode + 0x6c), consumerNode != 0)) {
          do {
            clonedNode = IRInst__getOperandRecord(*(undefined4 *)(consumerNode + 0x38),1);
            if (*(int *)(clonedNode + 0x10) == (DAT_001aa818)[addressComponent]) {
              componentsLeft = 4;
              clonedNode = consumerNode;
LAB_0016e258:
              if (*(int *)(clonedNode + 0x48) < 1) goto code_r0x0016e264;
              clonedInst = IRInst__clone(*(undefined4 *)(consumerNode + 0x38),*scheduler,0);
              addressSource = IRInst__getOperandSource(*(undefined4 *)(addressLoadNode + 0x38),1);
              IRInst__setOperandSource(clonedInst,1,addressSource,0,*scheduler);
              clonedNode = IRInst__getOperandRecord(*(undefined4 *)(addressLoadNode + 0x38),1);
              addressSelect = (DAT_001aa818)[*(byte *)(addressComponent + clonedNode + 0x10)];
              clonedNode = IRInst__getOperandRecord(clonedInst,1);
              *(undefined4 *)(clonedNode + 0x10) = addressSelect;
              succIndex = 0;
              clonedNode = Scheduler__createNode(scheduler,clonedInst,consumerNode + 0xc,scheduler[0xb]);
              succEdges = *(uint **)(consumerNode + 0x40);
              succEdgeCount = succEdges[1];
              if (0 < (int)succEdgeCount) {
                while( true ) {
                  if (succIndex < *succEdges) {
                    vectorCount = succEdges[1];
                    if (vectorCount <= succIndex) {
                      _memset(vectorCount * 4 + succEdges[2],0,(succIndex - vectorCount) * 4 + 4);
                      succEdges[1] = succIndex + 1;
                    }
                    succEdgeSlot = (undefined4 *)(succIndex * 4 + succEdges[2]);
                  }
                  else {
                    succEdgeSlot = (undefined4 *)Vector__elementRefGrow(succEdges,succIndex);
                  }
                  succIndex = succIndex + 1;
                  succEdge = (int *)*succEdgeSlot;
                  operandNumber2 = 1;
                  edgeTarget = succEdge[1];
                  if (*(int *)(edgeTarget + 0x2c) < 0) {
                    for (; operandCountOrNode = (**(code **)(**(int **)(edgeTarget + 0x38) + 0x14))
                                              (*(int **)(edgeTarget + 0x38)), operandNumber2 <= operandCountOrNode;
                        operandNumber2 = operandNumber2 + 1) {
                      operandCountOrNode = IRInst__getOperandSource(*(undefined4 *)(edgeTarget + 0x38),operandNumber2);
                      if (operandCountOrNode == *(int *)(consumerNode + 0x38)) {
                        IRInst__setOperandSource(*(undefined4 *)(edgeTarget + 0x38),operandNumber2,clonedInst,0,*scheduler);
                      }
                    }
                    *succEdge = clonedNode;
                    copySuccEdges = *(uint **)(clonedNode + 0x40);
                    vectorCount = copySuccEdges[1];
                    if (vectorCount < *copySuccEdges) {
                      _memset(vectorCount * 4 + copySuccEdges[2],0,4);
                      appendSlot = (undefined4 *)(vectorCount * 4 + copySuccEdges[2]);
                      copySuccEdges[1] = vectorCount + 1;
                    }
                    else {
                      appendSlot = (undefined4 *)Vector__elementRefGrow(copySuccEdges,vectorCount);
                    }
                    *appendSlot = succEdge;
                    componentsLeft2 = 4;
                    copyCountCursor2 = clonedNode;
                    operandCountOrNode = consumerNode;
                    do {
                      if (*(char *)(succEdge + 6) != '\0') {
                        *(int *)(copyCountCursor2 + 0x48) = *(int *)(copyCountCursor2 + 0x48) + 1;
                        *(int *)(operandCountOrNode + 0x48) = *(int *)(operandCountOrNode + 0x48) + -1;
                      }
                      succEdge = (int *)((int)succEdge + 1);
                      copyCountCursor2 = copyCountCursor2 + 4;
                      operandCountOrNode = operandCountOrNode + 4;
                      componentsLeft2 = componentsLeft2 + -1;
                    } while (componentsLeft2 != 0);
                    targetPredEdges = *(uint **)(edgeTarget + 0x44);
                    predEdgeCount = targetPredEdges[1];
                    predIndex = predEdgeCount - 1;
                    if (-1 < (int)predIndex) {
                      predByteOffset = predIndex * 4;
                      predVisited = 0;
                      while( true ) {
                        if (predIndex < *targetPredEdges) {
                          vectorCount2 = targetPredEdges[1];
                          if (vectorCount2 <= predIndex) {
                            _memset(vectorCount2 * 4 + targetPredEdges[2],0,(predIndex - vectorCount2) * 4 + 4);
                            targetPredEdges[1] = predIndex + 1;
                          }
                          predEdgeSlot = (undefined4 *)(predByteOffset + targetPredEdges[2]);
                        }
                        else {
                          predEdgeSlot = (undefined4 *)Vector__elementRefGrow(targetPredEdges,predIndex);
                        }
                        if ((addressLoadNode == *(int *)*predEdgeSlot) &&
                           (*(char *)((int)*predEdgeSlot + addressComponent + 0x18) != '\0')) {
                          Vector__removeAt(*(undefined4 *)(edgeTarget + 0x44),predIndex);
                          operandCountOrNode = addressComponent * 4 + addressLoadNode;
                          *(int *)(operandCountOrNode + 0x48) = *(int *)(operandCountOrNode + 0x48) + -1;
                        }
                        predVisited = predVisited + 1;
                        predIndex = predIndex - 1;
                        predByteOffset = predByteOffset + -4;
                        if (predEdgeCount == predVisited) break;
                        targetPredEdges = *(uint **)(edgeTarget + 0x44);
                      }
                    }
                    operandNumber2 = *(int *)(edgeTarget + 0x34);
                    if (operandNumber2 == 0) {
                      DList__unlink(edgeTarget);
                      operandNumber2 = *(int *)(edgeTarget + 0x34);
                    }
                    *(int *)(edgeTarget + 0x34) = operandNumber2 + 1;
                  }
                  if (succEdgeCount == succIndex) break;
                  succEdges = *(uint **)(consumerNode + 0x40);
                }
              }
              ((int (*)())Scheduler__enqueueReadyNode)(scheduler,clonedNode);
            }
LAB_0016e574:
            consumerNode = *(int *)(consumerNode + 0x6c);
          } while (consumerNode != 0);
          clonedNode = scheduler[0x61];
        }
      }
      loadSlot = loadSlot + 1;
      loadSlotCursor = loadSlotCursor + 1;
    } while ((int)loadSlot < clonedNode);
  }
  loadSlotCursor = scheduler;
  do {
    clonedNode = loadSlotCursor[0x62];
    if ((clonedNode != 0) && (*(int *)(clonedNode + 0x2c) < (int)scheduler[0xb])) {
      loadSlotCursor[0x62] = 0;
      for (loopIndexConsumer = *(int *)(clonedNode + 0x6c); loopIndexConsumer != 0; loopIndexConsumer = *(int *)(loopIndexConsumer + 0x6c)) {
        consumerNode = 4;
        addressLoadNode = loopIndexConsumer;
        while (*(int *)(addressLoadNode + 0x48) < 1) {
          addressLoadNode = addressLoadNode + 4;
          consumerNode = consumerNode + -1;
          if (consumerNode == 0) goto LAB_0016e800;
        }
        clonedInst = IRInst__clone(*(undefined4 *)(loopIndexConsumer + 0x38),*scheduler,0);
        addressSource = IRInst__getOperandSource(*(undefined4 *)(clonedNode + 0x38),1);
        IRInst__setOperandSource(clonedInst,1,addressSource,0,*scheduler);
        addressLoadNode = Scheduler__createNode(scheduler,clonedInst,loopIndexConsumer + 0xc,scheduler[0xb]);
        succEdges = *(uint **)(loopIndexConsumer + 0x40);
        succIndex2 = 0;
        succEdgeCount2 = succEdges[1];
        if (0 < (int)succEdgeCount2) {
          while( true ) {
            if (succIndex2 < *succEdges) {
              vectorCount3 = succEdges[1];
              if (vectorCount3 <= succIndex2) {
                _memset(vectorCount3 * 4 + succEdges[2],0,(succIndex2 - vectorCount3) * 4 + 4);
                succEdges[1] = succIndex2 + 1;
              }
              succEdgeSlot = (undefined4 *)(succIndex2 * 4 + succEdges[2]);
            }
            else {
              succEdgeSlot = (undefined4 *)Vector__elementRefGrow(succEdges,succIndex2);
            }
            succIndex2 = succIndex2 + 1;
            succEdge = (int *)*succEdgeSlot;
            operandNumber = 1;
            consumerNode = succEdge[1];
            if (*(int *)(consumerNode + 0x2c) < 0) {
              for (; operandNumber2 = (**(code **)(**(int **)(consumerNode + 0x38) + 0x14))
                                       (*(int **)(consumerNode + 0x38)), operandNumber <= operandNumber2;
                  operandNumber = operandNumber + 1) {
                operandNumber2 = IRInst__getOperandSource(*(undefined4 *)(consumerNode + 0x38),operandNumber);
                if (operandNumber2 == *(int *)(loopIndexConsumer + 0x38)) {
                  IRInst__setOperandSource(*(undefined4 *)(consumerNode + 0x38),operandNumber,clonedInst,0,*scheduler);
                }
              }
              *succEdge = addressLoadNode;
              copySuccEdges = *(uint **)(addressLoadNode + 0x40);
              vectorCount3 = copySuccEdges[1];
              if (vectorCount3 < *copySuccEdges) {
                _memset(vectorCount3 * 4 + copySuccEdges[2],0,4);
                appendSlot = (undefined4 *)(vectorCount3 * 4 + copySuccEdges[2]);
                copySuccEdges[1] = vectorCount3 + 1;
              }
              else {
                appendSlot = (undefined4 *)Vector__elementRefGrow(copySuccEdges,vectorCount3);
              }
              *appendSlot = succEdge;
              componentsLeft3 = 4;
              copyCountCursor = addressLoadNode;
              operandNumber2 = loopIndexConsumer;
              do {
                if (*(char *)(succEdge + 6) != '\0') {
                  *(int *)(copyCountCursor + 0x48) = *(int *)(copyCountCursor + 0x48) + 1;
                  *(int *)(operandNumber2 + 0x48) = *(int *)(operandNumber2 + 0x48) + -1;
                }
                succEdge = (int *)((int)succEdge + 1);
                copyCountCursor = copyCountCursor + 4;
                operandNumber2 = operandNumber2 + 4;
                componentsLeft3 = componentsLeft3 + -1;
              } while (componentsLeft3 != 0);
              pendingPreds = *(int *)(consumerNode + 0x34);
              if (pendingPreds == 0) {
                DList__unlink(consumerNode);
                pendingPreds = *(int *)(consumerNode + 0x34);
              }
              *(int *)(consumerNode + 0x34) = pendingPreds + 1;
            }
            if (succEdgeCount2 == succIndex2) break;
            succEdges = *(uint **)(loopIndexConsumer + 0x40);
          }
        }
        ((int (*)())Scheduler__enqueueReadyNode)(scheduler,addressLoadNode);
LAB_0016e800: ;
      }
    }
    loadSlotCursor = loadSlotCursor + 1;
    if (scheduler + 2 == loadSlotCursor) {
      return;
    }
  } while( true );
code_r0x0016e264:
  clonedNode = clonedNode + 4;
  componentsLeft = componentsLeft + -1;
  if (componentsLeft == 0) goto LAB_0016e574;
  goto LAB_0016e258;
}

/* Scheduler__advanceCycle @ 0x16e828 (1640 bytes) */
int Scheduler__advanceCycle(scheduler)
  int *scheduler;
{
  int threadIsFetchClass3;
  int isNodeReady;
  int topFetchCount;
  int maxFetchDepth;
  int aluReadyCycle;
  int nextSpecialNode;
  int nextWaitingNode;
  int requeueNode;
  int nextNode;
  int nodeReadyCycle;
  int nodeHeight;
  int target53Result;
  int specialListNode;
  int specialListEmpty;
  int waitCursor;
  int threadIsFetchClass;
  int firstPassedOver;
  int targetDepth;
  int specialNode;
  int waitingNode;
  int passedOverNode;
  int nextFetchNode;
  int fetchListNode;
  int aluListNode;
  bool noFetchReadyCycle;
  bool noAluReadyCycle;
  undefined4 *bundleSlotCursor;
  undefined4 *bundleRecord;
  int threadIsFetchClass2;
  int requeueNext;
  int prevCycle;
  int fetchReadyCycle;
  int nextAluNode;
  int slotsLeft;
  
  prevCycle = scheduler[0xb];
  (**(code **)(*(int *)scheduler[3] + 0x14))((int *)scheduler[3],scheduler[0xc]);
  (**(code **)(*(int *)scheduler[2] + 0x14))((int *)scheduler[2]);
  bundleRecord = (undefined4 *)scheduler[0xc];
  slotsLeft = 5;
  scheduler[0xb] = scheduler[0xb] + 1;
  bundleSlotCursor = bundleRecord;
  do {
    *bundleSlotCursor = 0;
    bundleSlotCursor = bundleSlotCursor + 1;
    slotsLeft = slotsLeft + -1;
  } while (slotsLeft != 0);
  DList__initSentinel(bundleRecord + 5);
  aluListNode = scheduler[0x15];
  for (nextAluNode = *(int *)(scheduler[0x15] + 8); nextAluNode != 0; nextAluNode = *(int *)(nextAluNode + 8)) {
    DList__unlink(aluListNode);
    DList__pushBack(scheduler + 0x1f,aluListNode);
    aluListNode = nextAluNode;
  }
  fetchListNode = scheduler[0xf];
  for (nextFetchNode = *(int *)(scheduler[0xf] + 8); nextFetchNode != 0; nextFetchNode = *(int *)(nextFetchNode + 8)) {
    DList__unlink(fetchListNode);
    DList__pushBack(scheduler + 0x1f,fetchListNode);
    fetchListNode = nextFetchNode;
  }
  scheduler[0x44] = 0;
  scheduler[0x48] = -1;
  scheduler[0x47] = -1;
  passedOverNode = scheduler[0x21];
  if (*(int *)(passedOverNode + 8) == 0) {
    fetchReadyCycle = -1;
    aluReadyCycle = -1;
  }
  else {
    fetchReadyCycle = -1;
    aluReadyCycle = -1;
    do {
      if (scheduler[0x44] < *(int *)(passedOverNode + 0x14)) {
        scheduler[0x44] = *(int *)(passedOverNode + 0x14);
      }
      threadIsFetchClass2 = (**(code **)(*(int *)scheduler[3] + 0x20))
                        ((int *)scheduler[3],*(undefined4 *)(passedOverNode + 0x38));
      if ((threadIsFetchClass2 == 0) &&
         (threadIsFetchClass2 = (**(code **)(*(int *)scheduler[3] + 0x24))
                            ((int *)scheduler[3],*(undefined4 *)(passedOverNode + 0x38)), threadIsFetchClass2 == 0)) {
        nodeHeight = *(int *)(passedOverNode + 0xc);
        if (*(int *)(passedOverNode + 0xc) < scheduler[0x47]) {
          nodeHeight = scheduler[0x47];
        }
        aluReadyCycle = scheduler[0xb];
        scheduler[0x47] = nodeHeight;
      }
      else {
        nodeHeight = *(int *)(passedOverNode + 0xc);
        if (*(int *)(passedOverNode + 0xc) < scheduler[0x48]) {
          nodeHeight = scheduler[0x48];
        }
        fetchReadyCycle = scheduler[0xb];
        scheduler[0x48] = nodeHeight;
      }
      passedOverNode = *(int *)(passedOverNode + 8);
    } while (*(int *)(passedOverNode + 8) != 0);
  }
  waitingNode = scheduler[0x1b];
  if (*(int *)(waitingNode + 8) == 0) {
    noFetchReadyCycle = fetchReadyCycle < 0;
    noAluReadyCycle = aluReadyCycle < 0;
  }
  else {
    noFetchReadyCycle = fetchReadyCycle < 0;
    noAluReadyCycle = aluReadyCycle < 0;
    do {
      if (scheduler[0x44] < *(int *)(waitingNode + 0x14)) {
        scheduler[0x44] = *(int *)(waitingNode + 0x14);
      }
      threadIsFetchClass2 = (**(code **)(*(int *)scheduler[3] + 0x20))
                        ((int *)scheduler[3],*(undefined4 *)(waitingNode + 0x38));
      if ((threadIsFetchClass2 == 0) &&
         (threadIsFetchClass2 = (**(code **)(*(int *)scheduler[3] + 0x24))
                            ((int *)scheduler[3],*(undefined4 *)(waitingNode + 0x38)), threadIsFetchClass2 == 0)) {
        nodeHeight = *(int *)(waitingNode + 0xc);
        if (*(int *)(waitingNode + 0xc) < scheduler[0x47]) {
          nodeHeight = scheduler[0x47];
        }
        scheduler[0x47] = nodeHeight;
        if (noAluReadyCycle) {
          nodeReadyCycle = *(int *)(waitingNode + 0x30);
        }
        else {
          nodeReadyCycle = *(int *)(waitingNode + 0x30);
          if (aluReadyCycle <= nodeReadyCycle) goto LAB_0016eb08;
        }
        noAluReadyCycle = nodeReadyCycle < 0;
        aluReadyCycle = nodeReadyCycle;
      }
      else {
        nodeHeight = *(int *)(waitingNode + 0xc);
        if (*(int *)(waitingNode + 0xc) < scheduler[0x48]) {
          nodeHeight = scheduler[0x48];
        }
        scheduler[0x48] = nodeHeight;
        if (noFetchReadyCycle) {
          nodeReadyCycle = *(int *)(waitingNode + 0x30);
        }
        else {
          nodeReadyCycle = *(int *)(waitingNode + 0x30);
          if (fetchReadyCycle <= nodeReadyCycle) goto LAB_0016eb08;
        }
        noFetchReadyCycle = nodeReadyCycle < 0;
        fetchReadyCycle = nodeReadyCycle;
      }
LAB_0016eb08:
      waitingNode = *(int *)(waitingNode + 8);
    } while (*(int *)(waitingNode + 8) != 0);
  }
  specialNode = scheduler[0x40];
  nextNode = *(int *)(specialNode + 8);
  while (nextNode != 0) {
    if (scheduler[0x44] < *(int *)(specialNode + 0x14)) {
      scheduler[0x44] = *(int *)(specialNode + 0x14);
    }
    nodeHeight = *(int *)(specialNode + 0xc);
    if (*(int *)(specialNode + 0xc) < scheduler[0x47]) {
      nodeHeight = scheduler[0x47];
    }
    scheduler[0x47] = nodeHeight;
    if (noAluReadyCycle) {
      nodeReadyCycle = *(int *)(specialNode + 0x30);
LAB_0016eb7c:
      noAluReadyCycle = nodeReadyCycle < 0;
      aluReadyCycle = nodeReadyCycle;
    }
    else {
      nodeReadyCycle = *(int *)(specialNode + 0x30);
      noAluReadyCycle = false;
      if (nodeReadyCycle < aluReadyCycle) goto LAB_0016eb7c;
    }
    specialNode = *(int *)(specialNode + 8);
    nextNode = *(int *)(specialNode + 8);
  }
  targetDepth = (**(code **)(*(int *)scheduler[2] + 0x5c))((int *)scheduler[2]);
  scheduler[0x45] = targetDepth;
  scheduler[9] = (uint)(scheduler[0x44] <= targetDepth);
  if (noAluReadyCycle) {
    if (noFetchReadyCycle) goto LAB_0016ec14;
  }
  else if (((noFetchReadyCycle) || (scheduler[0x46] == 0)) || (aluReadyCycle <= fetchReadyCycle)) {
    if (aluReadyCycle <= scheduler[0xb]) {
      aluReadyCycle = scheduler[0xb];
    }
    scheduler[0xb] = aluReadyCycle;
    goto LAB_0016ec14;
  }
  if (fetchReadyCycle <= scheduler[0xb]) {
    fetchReadyCycle = scheduler[0xb];
  }
  scheduler[0xb] = fetchReadyCycle;
LAB_0016ec14:
  firstPassedOver = *(int *)(scheduler[0x21] + 8);
  if (firstPassedOver == 0) {
    topFetchCount = 0;
    maxFetchDepth = 0;
  }
  else {
    topFetchCount = 0;
    maxFetchDepth = 0;
    requeueNode = scheduler[0x21];
    do {
      requeueNext = firstPassedOver;
      DList__unlink(requeueNode);
      ((int (*)())Scheduler__enqueueReadyNode)(scheduler,requeueNode);
      threadIsFetchClass = (**(code **)(*(int *)scheduler[3] + 0x20))
                         ((int *)scheduler[3],*(undefined4 *)(requeueNode + 0x38));
      if ((threadIsFetchClass != 0) ||
         (threadIsFetchClass = (**(code **)(*(int *)scheduler[3] + 0x24))
                             ((int *)scheduler[3],*(undefined4 *)(requeueNode + 0x38)), threadIsFetchClass != 0)) {
        if (maxFetchDepth < *(int *)(requeueNode + 0x14)) {
          maxFetchDepth = *(int *)(requeueNode + 0x14);
        }
        if (*(int *)(requeueNode + 0xc) == scheduler[0x48]) {
          topFetchCount = topFetchCount + 1;
        }
      }
      firstPassedOver = *(int *)(requeueNext + 8);
      requeueNode = requeueNext;
    } while (firstPassedOver != 0);
  }
  waitCursor = scheduler[0x1b];
  for (nextWaitingNode = *(int *)(scheduler[0x1b] + 8); nextWaitingNode != 0; nextWaitingNode = *(int *)(nextWaitingNode + 8)) {
    isNodeReady = Scheduler__isNodeReady(scheduler,waitCursor);
    if (isNodeReady != 0) {
      DList__unlink(waitCursor);
      ((int (*)())Scheduler__enqueueReadyNode)(scheduler,waitCursor);
      threadIsFetchClass3 = (**(code **)(*(int *)scheduler[3] + 0x20))
                        ((int *)scheduler[3],*(undefined4 *)(waitCursor + 0x38));
      if ((threadIsFetchClass3 != 0) ||
         (threadIsFetchClass3 = (**(code **)(*(int *)scheduler[3] + 0x24))
                            ((int *)scheduler[3],*(undefined4 *)(waitCursor + 0x38)), threadIsFetchClass3 != 0)) {
        if (maxFetchDepth < *(int *)(waitCursor + 0x14)) {
          maxFetchDepth = *(int *)(waitCursor + 0x14);
        }
        if (*(int *)(waitCursor + 0xc) == scheduler[0x48]) {
          topFetchCount = topFetchCount + 1;
        }
      }
    }
    waitCursor = nextWaitingNode;
  }
  specialListEmpty = DList__isEmpty(scheduler + 0x3e);
  if ((((specialListEmpty == 0) && (specialListEmpty = DList__isEmpty(scheduler + 0x13), specialListEmpty != 0)) &&
      (specialListEmpty = DList__isEmpty(scheduler + 0xd), specialListEmpty != 0)) &&
     (specialListEmpty = DList__count(scheduler + 0x3e), specialListEmpty == scheduler[0x3d])) {
    specialListNode = scheduler[0x40];
    for (nextSpecialNode = *(int *)(scheduler[0x40] + 8); nextSpecialNode != 0; nextSpecialNode = *(int *)(nextSpecialNode + 8)) {
      DList__unlink(specialListNode);
      *(undefined4 *)(specialListNode + 0x68) = 0;
      DList__pushBack(scheduler + 0x13,specialListNode);
      specialListNode = nextSpecialNode;
    }
  }
  target53Result = (**(code **)(**(int **)(*scheduler + 0x30c) + 0xd4))(*(int **)(*scheduler + 0x30c));
  if ((target53Result != 0) &&
     (target53Result = (**(code **)(*(int *)scheduler[2] + 0x18))((int *)scheduler[2]), target53Result != 0)) {
    ((int (*)())Scheduler__splitAddressRegisterUses)(scheduler);
  }
  Scheduler__updateFetchBatchMode(scheduler,topFetchCount,maxFetchDepth);
  return scheduler[0xb] - prevCycle;
}

/* Scheduler__onNodeReady @ 0x16ee90 (284 bytes) */
int Scheduler__onNodeReady(scheduler, node)
  undefined4 *scheduler;
  int node;
{
  int isNodeReadyResult;
  int balanceEnabled;
  int newClass;
  int vcall34Result;
  int vcall50Result;
  int isFetchFlag;
  
  vcall50Result = (**(code **)(*(int *)scheduler[2] + 0x50))((int *)scheduler[2],node);
  if (vcall50Result == 0) goto LAB_0016ef60;
  balanceEnabled = Compiler__isOptionEnabled(*scheduler,0x28);
  if (balanceEnabled == 0) {
LAB_0016ef04:
    isFetchFlag = 0;
  }
  else {
    isFetchFlag = 1;
    vcall34Result = (**(code **)(*(int *)scheduler[2] + 0x34))((int *)scheduler[2],node);
    if (vcall34Result == 0) goto LAB_0016ef04;
  }
  newClass = (**(code **)(*(int *)scheduler[2] + 0x4c))
                    ((int *)scheduler[2],*(undefined4 *)(node + 0x38));
  if ((newClass != *(int *)(node + 0x58)) || (isFetchFlag != *(int *)(node + 0x5c))) {
    ((int (*)())SchedModel__uncountNode)(scheduler[2],node);
    *(int *)(node + 0x58) = newClass;
    *(int *)(node + 0x5c) = isFetchFlag;
    ((int (*)())SchedModel__countIssuedNode)(scheduler[2],node);
  }
LAB_0016ef60:
  isNodeReadyResult = Scheduler__isNodeReady(scheduler,node);
  if (isNodeReadyResult != 0) {
    ((int (*)())Scheduler__enqueueReadyNode)(scheduler,node);
    return;
  }
  return DList__pushBack(scheduler + 0x19,node);
}

/* Scheduler__selectNextNode @ 0x16ff54 (6540 bytes) */
int Scheduler__selectNextNode(scheduler, cycleLimit)
  int *scheduler;
  int cycleLimit;
{
  int *edgeCompCursor;
  int compsLeft;
  int compIndex;
  int siblingCountCursor;
  undefined *copyScanIndex;
  int *newSourceSlot;
  int *newCopySlot;
  int *foundCopySlot;
  int *copyScanSlot;
  int sourceAppendOffset;
  int copyAppendOffset;
  int siblingCycle;
  int siblingNode;
  uint stackCountBefore;
  int *siblingEdge;
  undefined4 *consumerPredSlot;
  uint consumerPredCount;
  uint consumerPredIndex;
  uint *consumerPredEdges;
  int consumer;
  int workEdge;
  int *workSuccSlot;
  uint workSuccCount;
  uint workSuccIndex;
  uint *workSuccEdges;
  int workNode;
  int *topSlot;
  uint topIndex;
  int *sourceSlot;
  int copyInst;
  int copyNode;
  int *copySlot;
  undefined *copyCount;
  int copyByteOffset;
  int stackByteOffset;
  int *pushSlot;
  int stackPushOffset;
  uint pushIndex;
  uint *newGroup;
  uint candidateWriteMask;
  undefined4 *zeroCursor;
  int fieldsLeft;
  int previousGroup;
  int candidateIssuable;
  int candidateCopy;
  int candidateBundleEmpty;
  int candidateCanAdd;
  int candidate;
  int firstAluNode;
  int *schedulerPtr;
  int earliestCycle;
  undefined4 a0UserInst;
  undefined4 *copyPredSlot;
  uint *copyPredEdges;
  uint targetPredCount;
  int *targetPredEdge;
  undefined4 *targetPredSlot;
  int targetPredByteOffset;
  uint *targetPredEdges;
  undefined4 *copySuccSlot;
  uint *copySuccEdges;
  int a0UserCountCursor;
  int copyCountCursor;
  int edgeCompsLeft;
  int pendingPreds;
  int operandSource;
  int operandCount;
  int operandIndex;
  int edgeTarget;
  int *succEdge;
  undefined4 *succEdgeSlot;
  uint *succEdges;
  uint succCount;
  uint succIndex;
  int succByteOffset;
  int a0UserCopy;
  int componentCountCursor;
  int componentCountsLeft;
  int a0User;
  int slotByteOffset;
  uint loadSlot;
  int addrRegLoadCount;
  int bundleListEmpty;
  int *bundleSlotCursor;
  int slotsLeft;
  int selectsLeft;
  int destOperandRecord;
  int pendingByteOffset;
  int *predEdge;
  undefined4 *predEdgeSlot;
  uint *predEdges;
  int writerNode;
  int componentByteOffset;
  int *componentArrayCursor;
  int componentIndex;
  int groupReg;
  int componentsLeft;
  int flagBit0Result;
  int schedulerAllocRegEnabled2;
  int deferredBucket;
  int savedNext;
  int candidateFits;
  int lastNodeStateFits;
  int nodeFitsAlone;
  int lastBundleNode;
  int rewritableCount;
  int occupiedSlots;
  int registerStateFits;
  int insertedCopy;
  int canAdd;
  int nextNode;
  int issuableNow;
  int selectsRewritable;
  int firstTempReg;
  int freeTempReg;
  int componentMask;
  int isNotTextureFetch;
  int leaderRegKind;
  int coGroup;
  int reuseResult;
  int waitingListEmpty;
  int fetchBatchMode;
  bool moreBundleSlots;
  undefined4 *copyAppendSlot;
  int producerIsUndefined;
  int producerFlagBit0Result;
  int bundleEmpty;
  int currentListEmpty;
  int isEmpty;
  int isProjectionOfClass44;
  int isProjectionOfClass26or3a;
  int dependencyLatency;
  int balanceEnabled;
  int schedulerAllocRegEnabled;
  int operandRecord;
  int operandRecord2;
  int sourceDef2;
  int sourceDef;
  undefined4 arenaAt378;
  bool nothingPassedOver;
  bool moreComponents;
  uint edgeIndex;
  int iVar4;
  int isOptionEnabledResult;
  char *groupSelectCursor;
  uint predVectorCount;
  undefined4 pendingConsumers;
  undefined4 *allocation;
  int *nodeInst;
  uint vectorCount;
  uint edgeVectorCount;
  int *targetDescription;
  int iVar13;
  int slotIndex;
  undefined4 *copySourceSlot;
  uint predEdgeCount;
  int node1;
  int bundleSlotNode;
  undefined *puVar19;
  uint *puVar20;
  uint *vector1;
  int loopIndexLoadsSeen;
  int otherNodesSeen;
  int addrRegLoadsSeen;
  uint targetPredVisited;
  undefined *copyIndexPlusOne;
  uint targetPredIndex;
  uint succVisited;
  undefined *copyIndex;
  int node;
  int *producerInst;
  undefined4 arena;
  int slotRewritable;
  int *piStack00000018;
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vecCapacity/vecCount/vecData/vecArena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_78_buf [0x10];
  #define vecCapacity (*(undefined * *)(local_78_buf + 0x00))
  #define vecCount (*(undefined * *)(local_78_buf + 0x04))
  #define vecData (*(int *)(local_78_buf + 0x08))
  #define vecArena (*(undefined4 *)(local_78_buf + 0x0c))
  /* issue #64 (auto): growable-vector header (capacity/count/data-pointer/arena) used with Vector__elementRefGrow - vec2Capacity/vec2Count/vec2Data/vec2Arena are its four words by their own hex offsets. Vector__elementRefGrow unconditionally reads all four on every call (even its "no grow needed" path reallocs+copies+frees), so they must be one contiguous buffer; left as four separate locals, an -O0 rebuild does not place them contiguously. Merged into one 0x10-byte buffer (part of the issue #64 live-differential sweep). */
  unsigned char local_68_buf [0x10];
  #define vec2Capacity (*(undefined * *)(local_68_buf + 0x00))
  #define vec2Count (*(undefined * *)(local_68_buf + 0x04))
  #define vec2Data (*(int *)(local_68_buf + 0x08))
  #define vec2Arena (*(undefined4 *)(local_68_buf + 0x0c))
  uint workStackCapacity;
  uint workStackCount;
  int workStackData;
  undefined4 in_stack_ffffffb8;
  undefined4 in_stack_ffffffbc;
  
  fetchBatchMode = scheduler[0x46];
  if (fetchBatchMode == 0) {
    node = scheduler[0x15];
  }
  else {
    node = scheduler[0xf];
  }
  nothingPassedOver = true;
  addrRegLoadsSeen = 0;
  loopIndexLoadsSeen = 0;
  otherNodesSeen = 0;
  while (*(int *)(node + 8) != 0) {
    nodeInst = *(int **)(node + 0x38);
    if ((fetchBatchMode == 0) && (cycleLimit < *(int *)(node + 0x10))) goto LAB_00170868;
    isProjectionOfClass26or3a = IRInst__isProjectionOfClass26or3a(nodeInst);
    if (isProjectionOfClass26or3a == 0) {
      isProjectionOfClass44 = IRInst__isProjectionOfClass44(nodeInst);
      if (isProjectionOfClass44 != 0) {
        reuseResult = ((int (*)())Scheduler__tryReuseLoopIndexLoad)(scheduler,node);
        loopIndexLoadsSeen = loopIndexLoadsSeen + 1;
        goto joined_r0x00170058;
      }
      coGroup = *(int *)(node + 0x60);
      otherNodesSeen = otherNodesSeen + 1;
      if (coGroup == 0) {
LAB_0017036c:
        schedulerAllocRegEnabled = Compiler__isOptionEnabled(*scheduler,0x25);
        if ((schedulerAllocRegEnabled != 0) &&
           (((((*(int *)(node + 0x60) == 0 || (*(int *)(*(int *)(node + 0x60) + 4) < 0)) &&
              (nodeInst[0x26] == 1)) && ((*(int *)(node + 100) == 0 && ((nodeInst[5] & 0x40U) == 0))))
            && ((nodeInst[5] & 0x20U) == 0)))) {
          isNotTextureFetch = (**(code **)(**(int **)(*scheduler + 0x30c) + 0x7c))
                            (*(int **)(*scheduler + 0x30c),nodeInst);
          if (isNotTextureFetch == 0) {
            componentMask = 0x1010101;
          }
          else if (*(int **)(node + 0x60) == (int *)0x0) {
            componentMask = nodeInst[3];
          }
          else {
            componentMask = **(int **)(node + 0x60);
          }
          freeTempReg = Scheduler__findFreeTempRegister(scheduler,1,componentMask);
          targetDescription = *(int **)(*scheduler + 0x30c);
          firstTempReg = (**(code **)(*targetDescription + 0x138))(targetDescription,*scheduler);
          if ((freeTempReg < 0) || (firstTempReg + 4 <= freeTempReg)) {
            if ((*(int *)(node + 0x58) == 2) &&
               (selectsRewritable = (**(code **)(*(int *)scheduler[2] + 0x34))((int *)scheduler[2],node),
               selectsRewritable != 0)) {
              ((int (*)())SchedModel__uncountNode)(scheduler[2],node);
              (**(code **)(*(int *)scheduler[2] + 0x38))((int *)scheduler[2],node);
              ((int (*)())SchedModel__countIssuedNode)(scheduler[2],node);
            }
            nodeInst[0x26] = 0;
          }
        }
        issuableNow = (**(code **)(*(int *)scheduler[3] + 0xc))((int *)scheduler[3],nodeInst);
        if (issuableNow == 0) {
          nextNode = *(int *)(node + 8);
          nothingPassedOver = false;
          DList__unlink(node);
          DList__pushBack(scheduler + 0x1f,node);
          node = nextNode;
        }
        else {
          if ((*(uint *)(*(int *)(*scheduler + 0x30c) + 8) & 0x200) == 0) {
            canAdd = (**(code **)(*(int *)scheduler[2] + 0xc))((int *)scheduler[2],nodeInst);
            if (canAdd != 0) goto LAB_001705f8;
            bundleEmpty = (**(code **)(*(int *)scheduler[2] + 0x24))((int *)scheduler[2]);
            if (bundleEmpty != 0) {
              insertedCopy = Scheduler__insertOperandCopy(scheduler,node);
              if (insertedCopy != 0) {
                return insertedCopy;
              }
              goto LAB_001705f8;
            }
            balanceEnabled = Compiler__isOptionEnabled(*scheduler,0x28);
            if (balanceEnabled != 0) {
              selectsRewritable = (**(code **)(*(int *)scheduler[2] + 0x34))((int *)scheduler[2],node);
              if ((selectsRewritable != 0) &&
                 (registerStateFits = (**(code **)(*(int *)scheduler[2] + 0x2c))
                                    ((int *)scheduler[2],node,scheduler + 0x4d), registerStateFits != 0))
              goto LAB_001705f8;
              occupiedSlots = 0;
              rewritableCount = 0;
              lastBundleNode = 0;
              slotIndex = 0;
              do {
                bundleSlotNode = *(int *)(scheduler[0xc] + slotIndex * 4);
                if (bundleSlotNode != 0) {
                  occupiedSlots = occupiedSlots + 1;
                  slotRewritable = (**(code **)(*(int *)scheduler[2] + 0x34))((int *)scheduler[2],bundleSlotNode);
                  lastBundleNode = bundleSlotNode;
                  if (slotRewritable != 0) {
                    rewritableCount = rewritableCount + 1;
                  }
                }
                moreBundleSlots = slotIndex != 4;
                slotIndex = slotIndex + 1;
              } while (moreBundleSlots);
              if ((occupiedSlots == 1) && (rewritableCount == 1)) {
                (**(code **)(*(int *)scheduler[2] + 8))((int *)scheduler[2]);
                nodeFitsAlone = (**(code **)(*(int *)scheduler[2] + 0xc))
                                   ((int *)scheduler[2],*(undefined4 *)(node + 0x38));
                if (nodeFitsAlone != 0) {
                  (**(code **)(*(int *)scheduler[2] + 0x10))
                            ((int *)scheduler[2],*(undefined4 *)(node + 0x38));
                  lastNodeStateFits = (**(code **)(*(int *)scheduler[2] + 0x2c))
                                     ((int *)scheduler[2],lastBundleNode,scheduler + 0x4d);
                  if (lastNodeStateFits != 0) {
                    (**(code **)(*(int *)scheduler[2] + 8))((int *)scheduler[2]);
                    (**(code **)(*(int *)scheduler[2] + 0x10))
                              ((int *)scheduler[2],*(undefined4 *)(lastBundleNode + 0x38));
                    DList__unlink(node);
                    return node;
                  }
                }
                (**(code **)(*(int *)scheduler[2] + 8))((int *)scheduler[2]);
                (**(code **)(*(int *)scheduler[2] + 0x10))
                          ((int *)scheduler[2],*(undefined4 *)(lastBundleNode + 0x38));
              }
            }
          }
          else {
            iVar4 = (**(code **)(*(int *)scheduler[2] + 0x34))((int *)scheduler[2],node);
            if ((iVar4 == 0) || (iVar4 = Compiler__isOptionEnabled(*scheduler,0x28), iVar4 == 0)) {
              candidateFits = (**(code **)(*(int *)scheduler[2] + 0xc))((int *)scheduler[2],nodeInst);
            }
            else {
              candidateFits = (**(code **)(*(int *)scheduler[2] + 0x2c))
                                ((int *)scheduler[2],node,scheduler + 0x4d);
            }
            if (candidateFits != 0) goto LAB_001705f8;
          }
          savedNext = *(int *)(node + 8);
          DList__unlink(node);
          isOptionEnabledResult = Compiler__isOptionEnabled(*scheduler,0x27);
          if ((((isOptionEnabledResult != 0) && (isOptionEnabledResult = Compiler__isOptionEnabled(*scheduler,0x2b), isOptionEnabledResult == 0)) &&
              (scheduler[0x46] == 0)) &&
             ((*(int *)(node + 0x60) == 0 || ((*(uint *)(scheduler[1] + 0x30) & 0x2000) != 0)))) {
            deferredBucket = (**(code **)(*(int *)scheduler[2] + 0x3c))((int *)scheduler[2],nodeInst);
            if (deferredBucket - 1U < 3) {
              nothingPassedOver = false;
              DList__pushBack(scheduler + (deferredBucket - 1U) * 6 + 0x2b,node);
              node = savedNext;
              goto LAB_00170838;
            }
          }
          DList__pushBack(scheduler + 0x1f,node);
          nothingPassedOver = false;
          node = savedNext;
        }
      }
      else {
        if (-1 < *(int *)(coGroup + 4)) {
          schedulerAllocRegEnabled2 = Compiler__isOptionEnabled(*scheduler,0x25);
          if (schedulerAllocRegEnabled2 != 0) {
            if (((nodeInst[0x20] != 0) && (flagBit0Result = RegKind__flagBit0(nodeInst[0x26]), flagBit0Result != 0)) &&
               ((nodeInst[5] & 2U) == 0)) {
              (**(code **)(*nodeInst + 0x50))(nodeInst);
            }
            componentsLeft = 4;
            groupReg = *(int *)(*(int *)(node + 0x60) + 4);
            componentIndex = 0;
            componentArrayCursor = scheduler;
            do {
              componentByteOffset = componentIndex << 2;
              writerNode = *(int *)(groupReg * 4 + componentArrayCursor[0x4d]);
              pendingConsumers = 0;
              if (writerNode != 0) {
                componentByteOffset = componentIndex * 4;
                pendingConsumers = *(undefined4 *)(componentByteOffset + writerNode + 0x48);
              }
              *(undefined4 *)((int)&vec2Count + componentByteOffset) = pendingConsumers;
              componentIndex = componentIndex + 1;
              componentArrayCursor = componentArrayCursor + 1;
              componentsLeft = componentsLeft + -1;
            } while (componentsLeft != 0);
            predEdges = *(uint **)(node + 0x44);
            edgeIndex = 0;
            predEdgeCount = predEdges[1];
            if (0 < (int)predEdgeCount) {
              while( true ) {
                if (edgeIndex < *predEdges) {
                  vectorCount = predEdges[1];
                  if (vectorCount <= edgeIndex) {
                    _memset(vectorCount * 4 + predEdges[2],0,(edgeIndex - vectorCount) * 4 + 4);
                    predEdges[1] = edgeIndex + 1;
                  }
                  predEdgeSlot = (undefined4 *)(edgeIndex * 4 + predEdges[2]);
                }
                else {
                  predEdgeSlot = (undefined4 *)Vector__elementRefGrow(predEdges,edgeIndex);
                }
                edgeIndex = edgeIndex + 1;
                predEdge = (int *)*predEdgeSlot;
                iVar4 = *predEdge;
                if (((((predEdge[2] == 0) && (producerInst = *(int **)(iVar4 + 0x38), producerInst[0x20] != 0))
                     && ((producerFlagBit0Result = RegKind__flagBit0(producerInst[0x26]), producerFlagBit0Result != 0 &&
                         (((producerInst[5] & 2U) == 0 &&
                          (producerIsUndefined = (**(code **)(*producerInst + 0x50))(producerInst), producerIsUndefined == 0)))))) &&
                    (iVar4 = *(int *)(iVar4 + 0x38), (*(uint *)(iVar4 + 0x14) & 0x40) != 0)) &&
                   (groupReg == *(int *)(iVar4 + 0x94))) {
                  componentsLeft = 4;
                  pendingByteOffset = 0;
                  do {
                    if (*(char *)(predEdge + 6) != '\0') {
                      *(int *)((int)&vec2Count + pendingByteOffset) = *(int *)((int)&vec2Count + pendingByteOffset) + -1;
                    }
                    predEdge = (int *)((int)predEdge + 1);
                    pendingByteOffset = pendingByteOffset + 4;
                    componentsLeft = componentsLeft + -1;
                  } while (componentsLeft != 0);
                }
                if (predEdgeCount == edgeIndex) break;
                predEdges = *(uint **)(node + 0x44);
              }
            }
            componentIndex = 0;
            do {
              destOperandRecord = IRInst__getOperandRecord(nodeInst,0);
              if ((*(char *)(componentIndex + destOperandRecord + 0x10) != '\x01') && (0 < (int)(&vec2Count)[componentIndex]))
              goto LAB_00170968;
              moreComponents = componentIndex != 3;
              componentIndex = componentIndex + 1;
            } while (moreComponents);
          }
          coGroup = *(int *)(node + 0x60);
          if (coGroup == 0) goto LAB_0017036c;
        }
        if (*(int *)(coGroup + 8) == 0) goto LAB_0017036c;
        if (*(int *)(*(int *)(coGroup + 8) + 0x2c) == scheduler[0xb]) {
          operandRecord2 = IRInst__getOperandRecord(nodeInst,0);
          groupSelectCursor = (char *)(coGroup + 0xc);
          componentIndex = 0;
          vec2Capacity = *(undefined **)(operandRecord2 + 0x10);
          selectsLeft = 4;
          do {
            if ((*groupSelectCursor != '\x01') && (*(char *)((int)&vec2Capacity + componentIndex) != '\x01'))
            goto LAB_00170320;
            componentIndex = componentIndex + 1;
            groupSelectCursor = groupSelectCursor + 1;
            selectsLeft = selectsLeft + -1;
          } while (selectsLeft != 0);
          coGroup = *(int *)(node + 0x60);
        }
        leaderRegKind = *(int *)(*(int *)(*(int *)(coGroup + 8) + 0x38) + 0x98);
        if (leaderRegKind == nodeInst[0x26]) goto LAB_0017036c;
        if (nodeInst[0x26] == 1) {
          nodeInst[0x26] = 0;
          goto LAB_0017036c;
        }
        if (((nodeInst[5] & 0x20U) == 0) && (leaderRegKind == 1)) {
          nodeInst[0x26] = 1;
          goto LAB_0017036c;
        }
LAB_00170968:
        node = *(int *)(node + 8);
      }
    }
    else {
      reuseResult = ((int (*)())Scheduler__tryReuseAddressRegister)(scheduler,node);
      addrRegLoadsSeen = addrRegLoadsSeen + 1;
joined_r0x00170058:
      if (reuseResult != 0) {
LAB_001705f8:
        DList__unlink(node);
        return node;
      }
LAB_00170320:
      nextNode = *(int *)(node + 8);
      DList__unlink(node);
      DList__pushBack(scheduler + 0x1f,node);
      node = nextNode;
    }
LAB_00170838:
    fetchBatchMode = scheduler[0x46];
  }
  if (fetchBatchMode == 0) {
LAB_00170868:
    if (((0 < addrRegLoadsSeen) || (0 < loopIndexLoadsSeen)) &&
       ((otherNodesSeen == 0 && (waitingListEmpty = DList__isEmpty(scheduler + 0x19), waitingListEmpty != 0)))) {
      slotsLeft = 5;
      bundleSlotCursor = (int *)scheduler[0xc];
      do {
        if (*bundleSlotCursor != 0) goto LAB_001708c4;
        bundleSlotCursor = bundleSlotCursor + 1;
        slotsLeft = slotsLeft + -1;
      } while (slotsLeft != 0);
      bundleListEmpty = DList__isEmpty((int *)scheduler[0xc] + 5);
      if (bundleListEmpty != 0) {
        if (0 >= addrRegLoadsSeen) {
          if (loopIndexLoadsSeen < 1) {
            return 0;
          }
          (**(code **)(*(int *)scheduler[2] + 0x1c))((int *)scheduler[2]);
          return 0;
        }
        addrRegLoadCount = scheduler[0x61];
        piStack00000018 = scheduler;
        if (0 < addrRegLoadCount) {
          loadSlot = 0;
          do {
            vec2Data = scheduler[0x5c];
            vec2Count = (undefined *)
                       (loadSlot + (((int)loadSlot >> 2) + (uint)((int)loadSlot < 0 && (loadSlot & 3) != 0))
                                 * -4);
            a0User = *(int *)(vec2Data + 0x6c);
            if (a0User != 0) {
              slotByteOffset = (int)vec2Count * 4;
              do {
                operandRecord = IRInst__getOperandRecord(*(undefined4 *)(a0User + 0x38),1);
                if (*(int *)(operandRecord + 0x10) == *(int *)(PTR_DAT_001e8b8c + slotByteOffset)) {
                  componentCountsLeft = 4;
                  componentCountCursor = a0User;
LAB_0016f038:
                  if (*(int *)(componentCountCursor + 0x48) < 1) goto code_r0x0016f044;
                  puVar19 = PTR_DAT_001e8b8c;
                  SelectWord__selectWhereMasked(&vec2Capacity,0,*(undefined4 *)(*(int *)(a0User + 0x38) + 0xc));
                  a0UserCopy = Scheduler__createCopyNode(piStack00000018,*(undefined4 *)(a0User + 0x38),vec2Capacity,
                                        piStack00000018[0xb],a0User + 0xc);
                  succEdges = *(uint **)(a0User + 0x40);
                  succCount = succEdges[1];
                  succIndex = succCount - 1;
                  if (-1 < (int)succIndex) {
                    succByteOffset = succIndex * 4;
                    succVisited = 0;
                    while( true ) {
                      if (succIndex < *succEdges) {
                        edgeVectorCount = succEdges[1];
                        if (edgeVectorCount <= succIndex) {
                          _memset(edgeVectorCount * 4 + succEdges[2],0,(succIndex - edgeVectorCount) * 4 + 4);
                          succEdges[1] = succIndex + 1;
                        }
                        succEdgeSlot = (undefined4 *)(succByteOffset + succEdges[2]);
                      }
                      else {
                        succEdgeSlot = (undefined4 *)Vector__elementRefGrow(succEdges,succIndex);
                      }
                      succEdge = (int *)*succEdgeSlot;
                      operandIndex = 1;
                      edgeTarget = succEdge[1];
                      if (*(int *)(edgeTarget + 0x2c) < 0) {
                        for (; operandCount = (**(code **)(**(int **)(edgeTarget + 0x38) + 0x14))
                                                  (*(int **)(edgeTarget + 0x38)), operandIndex <= operandCount;
                            operandIndex = operandIndex + 1) {
                          operandSource = IRInst__getOperandSource(*(undefined4 *)(edgeTarget + 0x38),operandIndex);
                          if (operandSource == *(int *)(a0User + 0x38)) {
                            IRInst__setOperandSource(*(undefined4 *)(edgeTarget + 0x38),operandIndex,
                                         *(undefined4 *)(a0UserCopy + 0x38),0,*piStack00000018);
                          }
                        }
                        *succEdge = a0UserCopy;
                        Vector__removeAt(*(undefined4 *)(a0User + 0x40),succIndex);
                        copySuccEdges = *(uint **)(a0UserCopy + 0x40);
                        edgeVectorCount = copySuccEdges[1];
                        if (edgeVectorCount < *copySuccEdges) {
                          _memset(edgeVectorCount * 4 + copySuccEdges[2],0,4);
                          copySuccSlot = (undefined4 *)(edgeVectorCount * 4 + copySuccEdges[2]);
                          copySuccEdges[1] = edgeVectorCount + 1;
                        }
                        else {
                          copySuccSlot = (undefined4 *)Vector__elementRefGrow(copySuccEdges,edgeVectorCount);
                        }
                        *copySuccSlot = succEdge;
                        pendingPreds = *(int *)(edgeTarget + 0x34);
                        if (pendingPreds == 0) {
                          DList__unlink(edgeTarget);
                          pendingPreds = *(int *)(edgeTarget + 0x34);
                        }
                        *(int *)(edgeTarget + 0x34) = pendingPreds + 1;
                        edgeCompsLeft = 4;
                        copyCountCursor = a0UserCopy;
                        a0UserCountCursor = a0User;
                        do {
                          if (*(char *)(succEdge + 6) != '\0') {
                            *(int *)(copyCountCursor + 0x48) = *(int *)(copyCountCursor + 0x48) + 1;
                            puVar19 = (undefined *)(*(int *)(a0UserCountCursor + 0x48) + -1);
                            *(undefined **)(a0UserCountCursor + 0x48) = puVar19;
                          }
                          succEdge = (int *)((int)succEdge + 1);
                          copyCountCursor = copyCountCursor + 4;
                          a0UserCountCursor = a0UserCountCursor + 4;
                          edgeCompsLeft = edgeCompsLeft + -1;
                        } while (edgeCompsLeft != 0);
                        targetPredEdges = *(uint **)(edgeTarget + 0x44);
                        targetPredCount = targetPredEdges[1];
                        targetPredIndex = targetPredCount - 1;
                        if (-1 < (int)targetPredIndex) {
                          targetPredByteOffset = targetPredIndex * 4;
                          targetPredVisited = 0;
                          while( true ) {
                            if (targetPredIndex < *targetPredEdges) {
                              predVectorCount = targetPredEdges[1];
                              if (predVectorCount <= targetPredIndex) {
                                _memset(predVectorCount * 4 + targetPredEdges[2],0,(targetPredIndex - predVectorCount) * 4 + 4);
                                targetPredEdges[1] = targetPredIndex + 1;
                              }
                              targetPredSlot = (undefined4 *)(targetPredByteOffset + targetPredEdges[2]);
                            }
                            else {
                              targetPredSlot = (undefined4 *)Vector__elementRefGrow(targetPredEdges,targetPredIndex);
                            }
                            targetPredEdge = (int *)*targetPredSlot;
                            if ((vec2Data == *targetPredEdge) &&
                               (puVar19 = vec2Count, (vec2Count + (int)targetPredEdge)[0x18] != '\0')) {
                              Vector__removeAt(*(undefined4 *)(edgeTarget + 0x44),targetPredIndex);
                              targetPredEdge[1] = a0UserCopy;
                              copyPredEdges = *(uint **)(a0UserCopy + 0x44);
                              predVectorCount = copyPredEdges[1];
                              if (predVectorCount < *copyPredEdges) {
                                _memset(predVectorCount * 4 + copyPredEdges[2],0,4);
                                copyPredSlot = (undefined4 *)(predVectorCount * 4 + copyPredEdges[2]);
                                copyPredEdges[1] = predVectorCount + 1;
                              }
                              else {
                                copyPredSlot = (undefined4 *)Vector__elementRefGrow(copyPredEdges,predVectorCount);
                              }
                              *copyPredSlot = targetPredEdge;
                            }
                            targetPredVisited = targetPredVisited + 1;
                            targetPredIndex = targetPredIndex - 1;
                            targetPredByteOffset = targetPredByteOffset + -4;
                            if (targetPredCount == targetPredVisited) break;
                            targetPredEdges = *(uint **)(edgeTarget + 0x44);
                          }
                        }
                      }
                      succVisited = succVisited + 1;
                      succIndex = succIndex - 1;
                      succByteOffset = succByteOffset + -4;
                      if (succCount == succVisited) break;
                      succEdges = *(uint **)(a0User + 0x40);
                    }
                  }
                  Scheduler__addDataDependencyEdge(piStack00000018,a0User,a0UserCopy,1,0,
                               *(undefined4 *)(*(int *)(a0UserCopy + 0x38) + 0xc),(uint)puVar19);
                  a0UserInst = *(undefined4 *)(a0User + 0x38);
                  *(int *)(a0UserCopy + 0x34) = *(int *)(a0UserCopy + 0x34) + -1;
                  earliestCycle = *(int *)(a0User + 0x2c);
                  dependencyLatency = Scheduler__getDependencyLatency(piStack00000018,a0UserInst,*(undefined4 *)(a0UserCopy + 0x38),0,1,0);
                  earliestCycle = earliestCycle + dependencyLatency;
                  if (*(int *)(a0UserCopy + 0x30) < earliestCycle) {
                    *(int *)(a0UserCopy + 0x30) = earliestCycle;
                  }
                  ((int (*)())Scheduler__onNodeReady)(piStack00000018,a0UserCopy);
                }
LAB_0016f3cc:
                a0User = *(int *)(a0User + 0x6c);
              } while (a0User != 0);
              addrRegLoadCount = piStack00000018[0x61];
            }
            loadSlot = loadSlot + 1;
            scheduler = scheduler + 1;
          } while ((int)loadSlot < addrRegLoadCount);
        }
        schedulerPtr = piStack00000018;
        isEmpty = DList__isEmpty(piStack00000018 + 0x13);
        if (isEmpty == 0) {
          firstAluNode = schedulerPtr[0x15];
          canAdd = (**(code **)(*(int *)piStack00000018[2] + 0xc))
                            ((int *)piStack00000018[2],*(undefined4 *)(firstAluNode + 0x38));
          if ((canAdd != 0) &&
             (issuableNow = (**(code **)(*(int *)piStack00000018[3] + 0xc))
                                ((int *)piStack00000018[3],*(undefined4 *)(firstAluNode + 0x38)),
             issuableNow != 0)) {
            DList__unlink(firstAluNode);
            return firstAluNode;
          }
        }
        return 0;
      }
    }
LAB_001708c4:
    currentListEmpty = DList__isEmpty(scheduler + 0x13);
  }
  else {
    currentListEmpty = DList__isEmpty(scheduler + 0xd);
  }
  if ((currentListEmpty != 0) || (!nothingPassedOver)) {
    return 0;
  }
  if (scheduler[0x46] == 0) {
    candidate = scheduler[0x15];
  }
  else {
    candidate = scheduler[0xf];
  }
  do {
    if (*(int *)(candidate + 8) == 0) {
LAB_0016f574:
      bundleEmpty = (**(code **)(*(int *)scheduler[2] + 0x24))((int *)scheduler[2]);
      if (bundleEmpty != 0) {
        (**(code **)(*(int *)scheduler[2] + 0x7c))((int *)scheduler[2]);
      }
      return 0;
    }
    if ((scheduler[0x46] == 0) && (cycleLimit < *(int *)(candidate + 0x10))) {
      return 0;
    }
    candidateCanAdd = (**(code **)(*(int *)scheduler[2] + 0xc))
                       ((int *)scheduler[2],*(undefined4 *)(candidate + 0x38));
    if (candidateCanAdd == 0) {
      candidateBundleEmpty = (**(code **)(*(int *)scheduler[2] + 0x24))((int *)scheduler[2]);
      if (candidateBundleEmpty != 0) {
        candidateCopy = Scheduler__insertOperandCopy(scheduler,candidate);
        if (candidateCopy != 0) {
          return candidateCopy;
        }
        goto LAB_0016f530;
      }
    }
    else {
LAB_0016f530:
      candidateIssuable = (**(code **)(*(int *)scheduler[3] + 0xc))
                         ((int *)scheduler[3],*(undefined4 *)(candidate + 0x38));
      if (candidateIssuable != 0) {
        if (*(int *)(candidate + 8) != 0) {
          vecArena = *(undefined4 *)(*scheduler + 0x378);
          vecCount = (undefined *)0x0;
          vecCapacity = (undefined *)0x2;
          vecData = Arena__alloc(vecArena,8);
          vec2Arena = *(undefined4 *)(*scheduler + 0x378);
          vec2Count = (undefined *)0x0;
          vec2Capacity = (undefined *)0x2;
          vec2Data = Arena__alloc(vec2Arena,8);
          arenaAt378 = *(undefined4 *)(*scheduler + 0x378);
          workStackCapacity = 2;
          workStackCount = 0;
          workStackData = Arena__alloc(arenaAt378,8);
          arena = *(undefined4 *)(*scheduler + 0x378);
          previousGroup = *(int *)(candidate + 0x60);
          allocation = (undefined4 *)Arena__alloc(arena,0x2c);
          pushIndex = workStackCount;
          *allocation = arena;
          allocation[4] = 0x1010101;
          allocation[1] = 0;
          allocation[2] = 0xffffffff;
          allocation[5] = 0;
          allocation[6] = 0x7fffffff;
          fieldsLeft = 4;
          allocation[3] = 0;
          zeroCursor = allocation + 1;
          do {
            zeroCursor[6] = 0;
            zeroCursor = zeroCursor + 1;
            fieldsLeft = fieldsLeft + -1;
          } while (fieldsLeft != 0);
          *(undefined4 **)(candidate + 0x60) = allocation + 1;
          allocation[5] = 1;
          puVar20 = *(uint **)(candidate + 0x38);
          candidateWriteMask = puVar20[3];
          newGroup = *(uint **)(candidate + 0x60);
          *(int *)(previousGroup + 0x10) = *(int *)(previousGroup + 0x10) + -1;
          *newGroup = candidateWriteMask;
          if (workStackCount < workStackCapacity) {
            stackPushOffset = workStackCount * 4;
            _memset(stackPushOffset + workStackData,0,4);
            workStackCount = pushIndex + 1;
            pushSlot = (int *)(stackPushOffset + workStackData);
          }
          else {
            pushSlot = (int *)Vector__elementRefGrow(&workStackCapacity,workStackCount);
          }
          *pushSlot = candidate;
LAB_0016fcc0:
          do {
            copyCount = vecCount;
            if (workStackCount == 0) {
              if (0 < (int)vecCount) {
                copyIndex = (undefined *)0x0;
                copyIndexPlusOne = (undefined *)0x1;
                copyByteOffset = 0;
                do {
                  if (copyIndex < vecCapacity) {
                    if (vecCount <= copyIndex) {
                      _memset((int)vecCount * 4 + vecData,0,((int)copyIndex - (int)vecCount) * 4 + 4)
                      ;
                      vecCount = copyIndexPlusOne;
                    }
                    copySlot = (int *)(copyByteOffset + vecData);
                  }
                  else {
                    copySlot = (int *)Vector__elementRefGrow(&vecCapacity,copyIndex);
                  }
                  copyNode = *copySlot;
                  ((int (*)())SchedModel__uncountNode)(scheduler[2],copyNode);
                  copyInst = *(int *)(copyNode + 0x38);
                  SelectWord__selectWhereMasked(&STACKARG(0xffffffb8),0,*(undefined4 *)(copyInst + 0xc));
                  *(undefined4 *)(copyInst + 0x9c) = in_stack_ffffffb8;
                  copyInst = *(int *)(copyNode + 0x38);
                  SelectWord__maskUnused(&STACKARG(0xffffffbc),0x10203,*(undefined4 *)(copyInst + 0xc));
                  operandRecord = IRInst__getOperandRecord(copyInst,1);
                  *(undefined4 *)(operandRecord + 0x10) = in_stack_ffffffbc;
                  arena = (**(code **)(*(int *)scheduler[2] + 0x4c))
                                     ((int *)scheduler[2],*(undefined4 *)(copyNode + 0x38));
                  *(undefined4 *)(copyNode + 0x58) = arena;
                  if (copyIndex < vec2Capacity) {
                    if (vec2Count <= copyIndex) {
                      _memset((int)vec2Count * 4 + vec2Data,0,((int)copyIndex - (int)vec2Count) * 4 + 4)
                      ;
                      vec2Count = copyIndexPlusOne;
                    }
                    copySourceSlot = (undefined4 *)(copyByteOffset + vec2Data);
                  }
                  else {
                    copySourceSlot = (undefined4 *)Vector__elementRefGrow(&vec2Capacity,copyIndex);
                  }
                  Scheduler__addDataDependencyEdge(scheduler,*copySourceSlot,copyNode,1,0,
                               *(undefined4 *)(*(int *)(copyNode + 0x38) + 0xc),(uint)puVar20);
                  ((int (*)())SchedModel__countIssuedNode)(scheduler[2],copyNode);
                  if (copyIndex < vec2Capacity) {
                    if (vec2Count <= copyIndex) {
                      _memset((int)vec2Count * 4 + vec2Data,0,((int)copyIndex - (int)vec2Count) * 4 + 4)
                      ;
                      vec2Count = copyIndexPlusOne;
                    }
                    sourceSlot = (int *)(copyByteOffset + vec2Data);
                  }
                  else {
                    sourceSlot = (int *)Vector__elementRefGrow(&vec2Capacity,copyIndex);
                  }
                  if (-1 < *(int *)(*sourceSlot + 0x2c)) {
                    *(int *)(copyNode + 0x34) = *(int *)(copyNode + 0x34) + -1;
                    ((int (*)())Scheduler__onNodeReady)(scheduler,copyNode);
                  }
                  copyIndex = copyIndex + 1;
                  copyIndexPlusOne = copyIndexPlusOne + 1;
                  copyByteOffset = copyByteOffset + 4;
                } while (copyCount != copyIndex);
              }
              DList__unlink(candidate);
              Arena__free(arenaAt378,workStackData);
              Arena__free(vec2Arena,vec2Data);
              Arena__free(vecArena,vecData);
              return candidate;
            }
            topIndex = workStackCount - 1;
            topSlot = (int *)0x0;
            if (topIndex < workStackCount) {
              topSlot = (int *)(topIndex * 4 + workStackData);
            }
            workNode = *topSlot;
            Vector__removeAt(&workStackCapacity,topIndex);
            workSuccEdges = *(uint **)(workNode + 0x40);
            workSuccIndex = 0;
            workSuccCount = workSuccEdges[1];
          } while ((int)workSuccCount < 1);
          do {
            if (workSuccIndex < *workSuccEdges) {
              vectorCount = workSuccEdges[1];
              if (vectorCount <= workSuccIndex) {
                _memset(vectorCount * 4 + workSuccEdges[2],0,(workSuccIndex - vectorCount) * 4 + 4);
                workSuccEdges[1] = workSuccIndex + 1;
              }
              workSuccSlot = (int *)(workSuccIndex * 4 + workSuccEdges[2]);
            }
            else {
              workSuccSlot = (int *)Vector__elementRefGrow(workSuccEdges,workSuccIndex);
            }
            workEdge = *workSuccSlot;
            if (*(int *)(workEdge + 8) == 0) {
              consumer = *(int *)(workEdge + 4);
              consumerPredIndex = 0;
              consumerPredEdges = *(uint **)(consumer + 0x44);
              consumerPredCount = consumerPredEdges[1];
              if (0 < (int)consumerPredCount) {
                do {
                  if (consumerPredIndex < *consumerPredEdges) {
                    edgeVectorCount = consumerPredEdges[1];
                    if (edgeVectorCount <= consumerPredIndex) {
                      _memset(edgeVectorCount * 4 + consumerPredEdges[2],0,(consumerPredIndex - edgeVectorCount) * 4 + 4);
                      consumerPredEdges[1] = consumerPredIndex + 1;
                    }
                    consumerPredSlot = (undefined4 *)(consumerPredIndex * 4 + consumerPredEdges[2]);
                  }
                  else {
                    consumerPredSlot = (undefined4 *)Vector__elementRefGrow(consumerPredEdges,consumerPredIndex);
                  }
                  siblingEdge = (int *)*consumerPredSlot;
                  if ((((siblingEdge[2] == 0) && (node1 = *siblingEdge, workNode != node1)) &&
                      (siblingEdge[4] == *(int *)(workEdge + 0x10))) &&
                     (siblingEdge[5] == *(int *)(workEdge + 0x14))) {
                    if (((*(int *)(node1 + 0x2c) < 0) ||
                        ((*(uint *)(*(int *)(node1 + 0x38) + 0x14) & 0x40) == 0)) &&
                       (node1 = Scheduler__hasOtherFlaggedProducer(scheduler,node1), stackCountBefore = workStackCount, node1 == 0)) {
                      puVar20 = (uint *)*siblingEdge;
                      if (puVar20[0x18] != *(uint *)(candidate + 0x60)) {
                        puVar20[0x18] = *(uint *)(candidate + 0x60);
                        *(int *)(*(int *)(candidate + 0x60) + 0x10) =
                             *(int *)(*(int *)(candidate + 0x60) + 0x10) + 1;
                        puVar20 = *(uint **)(*siblingEdge + 0x38);
                        **(uint **)(candidate + 0x60) = **(uint **)(candidate + 0x60) | puVar20[3];
                        *(int *)(previousGroup + 0x10) = *(int *)(previousGroup + 0x10) + -1;
                        siblingNode = *siblingEdge;
                        if (workStackCount < workStackCapacity) {
                          stackByteOffset = workStackCount * 4;
                          _memset(stackByteOffset + workStackData,0,4);
                          workStackCount = stackCountBefore + 1;
                          pushSlot = (int *)(stackByteOffset + workStackData);
                        }
                        else {
                          pushSlot = (int *)Vector__elementRefGrow(&workStackCapacity,workStackCount);
                        }
                        *pushSlot = siblingNode;
                      }
                    }
                    else {
                      copyCount = vecCount;
                      if ((int)vecCount < 1) {
                        siblingNode = *siblingEdge;
                      }
                      else {
                        copyScanIndex = (undefined *)0x0;
                        do {
                          if (copyScanIndex < vecCapacity) {
                            if (vecCount <= copyScanIndex) {
                              _memset((int)vecCount * 4 + vecData,0,
                                      ((int)copyScanIndex - (int)vecCount) * 4 + 4);
                              vecCount = copyScanIndex + 1;
                            }
                            copyScanSlot = (int *)((int)copyScanIndex * 4 + vecData);
                          }
                          else {
                            copyScanSlot = (int *)Vector__elementRefGrow(&vecCapacity,copyScanIndex);
                          }
                          sourceDef = IRInst__getOperandSource(*(undefined4 *)(*copyScanSlot + 0x38),1);
                          siblingNode = *siblingEdge;
                          if (sourceDef == *(int *)(siblingNode + 0x38)) {
                            if (copyScanIndex < vecCapacity) {
                              if (vecCount <= copyScanIndex) {
                                _memset((int)vecCount * 4 + vecData,0,
                                        ((int)copyScanIndex - (int)vecCount) * 4 + 4);
                                vecCount = copyScanIndex + 1;
                              }
                              foundCopySlot = (int *)((int)copyScanIndex * 4 + vecData);
                            }
                            else {
                              foundCopySlot = (int *)Vector__elementRefGrow(&vecCapacity,copyScanIndex);
                            }
                            node1 = *foundCopySlot;
                            *(uint *)(*(int *)(node1 + 0x38) + 0xc) =
                                 *(uint *)(*(int *)(node1 + 0x38) + 0xc) | siblingEdge[6];
                            puVar20 = *(uint **)(node1 + 0x60);
                            *puVar20 = *puVar20 | siblingEdge[6];
                            goto LAB_0016fafc;
                          }
                          copyScanIndex = copyScanIndex + 1;
                        } while (copyCount != copyScanIndex);
                      }
                      siblingCycle = *(int *)(siblingNode + 0x2c);
                      arena = *(undefined4 *)(siblingNode + 0x38);
                      node1 = (**(code **)(*(int *)scheduler[2] + 0x78))((int *)scheduler[2]);
                      node1 = Scheduler__createCopyNode(scheduler,arena,0,siblingCycle + node1,*siblingEdge + 0xc);
                      if (vecCount < vecCapacity) {
                        copyAppendOffset = (int)vecCount * 4;
                        vecCount = vecCount + 1;
                        *(undefined4 *)(copyAppendOffset + vecData) = 0;
                        newCopySlot = (int *)(copyAppendOffset + vecData);
                      }
                      else {
                        newCopySlot = (int *)Vector__elementRefGrow(&vecCapacity,vecCount);
                      }
                      *newCopySlot = node1;
                      if (vec2Count < vec2Capacity) {
                        sourceAppendOffset = (int)vec2Count * 4;
                        vec2Count = vec2Count + 1;
                        *(undefined4 *)(sourceAppendOffset + vec2Data) = 0;
                        newSourceSlot = (int *)(sourceAppendOffset + vec2Data);
                      }
                      else {
                        newSourceSlot = (int *)Vector__elementRefGrow(&vec2Capacity,vec2Count);
                      }
                      *newSourceSlot = *siblingEdge;
                      *(int *)(*(int *)(node1 + 0x38) + 0xc) = siblingEdge[6];
                      IRInst__setExtraOperandSource(*(undefined4 *)(node1 + 0x38),*(undefined4 *)(workNode + 0x38),0,
                                   *scheduler);
                      *(undefined4 *)(node1 + 0x60) = *(undefined4 *)(candidate + 0x60);
                      puVar20 = *(uint **)(candidate + 0x60);
                      puVar20[4] = puVar20[4] + 1;
                      **(uint **)(candidate + 0x60) = **(uint **)(candidate + 0x60) | siblingEdge[6];
LAB_0016fafc:
                      if ((siblingEdge[4] < 1) || (siblingEdge[5] != 0)) {
LAB_0016fb44:
                        iVar13 = *siblingEdge;
                      }
                      else {
                        sourceDef2 = IRInst__getOperandSource(*(undefined4 *)(consumer + 0x38),siblingEdge[4]);
                        iVar13 = *siblingEdge;
                        if (sourceDef2 == *(int *)(iVar13 + 0x38)) {
                          IRInst__setOperandSource(*(undefined4 *)(consumer + 0x38),siblingEdge[4],
                                       *(undefined4 *)(node1 + 0x38),0,*scheduler);
                          goto LAB_0016fb44;
                        }
                      }
                      compsLeft = 4;
                      compIndex = 0;
                      edgeCompCursor = siblingEdge;
                      siblingCountCursor = node1;
                      do {
                        if (*(char *)(edgeCompCursor + 6) != '\0') {
                          iVar13 = compIndex * 4 + iVar13;
                          puVar20 = (uint *)(*(int *)(iVar13 + 0x48) + -1);
                          *(uint **)(iVar13 + 0x48) = puVar20;
                          *(int *)(siblingCountCursor + 0x48) = *(int *)(siblingCountCursor + 0x48) + 1;
                          iVar13 = *siblingEdge;
                        }
                        compIndex = compIndex + 1;
                        edgeCompCursor = (int *)((int)edgeCompCursor + 1);
                        siblingCountCursor = siblingCountCursor + 4;
                        compsLeft = compsLeft + -1;
                      } while (compsLeft != 0);
                      Vector__removeValue(*(undefined4 *)(iVar13 + 0x40),siblingEdge);
                      if (-1 < *(int *)(*siblingEdge + 0x2c)) {
                        *(int *)(consumer + 0x34) = *(int *)(consumer + 0x34) + 1;
                      }
                      *siblingEdge = node1;
                      vector1 = *(uint **)(node1 + 0x40);
                      edgeVectorCount = vector1[1];
                      if (edgeVectorCount < *vector1) {
                        _memset(edgeVectorCount * 4 + vector1[2],0,4);
                        copyAppendSlot = (undefined4 *)(edgeVectorCount * 4 + vector1[2]);
                        vector1[1] = edgeVectorCount + 1;
                      }
                      else {
                        copyAppendSlot = (undefined4 *)Vector__elementRefGrow(vector1,edgeVectorCount);
                      }
                      *copyAppendSlot = siblingEdge;
                    }
                  }
                  consumerPredIndex = consumerPredIndex + 1;
                  if (consumerPredCount == consumerPredIndex) break;
                  consumerPredEdges = *(uint **)(consumer + 0x44);
                } while( true );
              }
            }
            workSuccIndex = workSuccIndex + 1;
            if (workSuccCount == workSuccIndex) goto LAB_0016fcc0;
            workSuccEdges = *(uint **)(workNode + 0x40);
          } while( true );
        }
        goto LAB_0016f574;
      }
    }
    candidate = *(int *)(candidate + 8);
  } while( true );
code_r0x0016f044:
  componentCountCursor = componentCountCursor + 4;
  componentCountsLeft = componentCountsLeft + -1;
  if (componentCountsLeft == 0) goto LAB_0016f3cc;
  goto LAB_0016f038;
}
#undef vecCapacity
#undef vecCount
#undef vecData
#undef vecArena
#undef vec2Capacity
#undef vec2Count
#undef vec2Data
#undef vec2Arena

/* Scheduler__scheduleCycle @ 0x170990 (572 bytes) */
int Scheduler__scheduleCycle(scheduler)
  int scheduler;
{
  undefined4 finished;
  int bundleFull;
  int committedLast2;
  int waitingListEmpty;
  int aluListEmpty;
  int bucketByteOffset;
  int committedLast;
  int bucketNumber;
  int cycleLimit;
  bool moreBuckets;
  int isEmptyResult;
  int nextNodeOrCheck;
  int bucketEmpty;
  undefined4 bucketNode;
  
  if (((*(int *)(scheduler + 0x118) == 0) && (isEmptyResult = DList__isEmpty(scheduler + 0x4c), isEmptyResult == 0)) &&
     (*(int *)(scheduler + 0x20) != 0)) {
    cycleLimit = *(int *)(*(int *)(scheduler + 0x54) + 0x10);
    nextNodeOrCheck = (**(code **)(**(int **)(scheduler + 8) + 0x84))(*(int **)(scheduler + 8));
    cycleLimit = cycleLimit + nextNodeOrCheck;
  }
  else {
    cycleLimit = 0x7fffffff;
  }
  while ((nextNodeOrCheck = (**(code **)(**(int **)(scheduler + 8) + 0x20))(*(int **)(scheduler + 8)), nextNodeOrCheck == 0
         && (nextNodeOrCheck = ((int (*)())Scheduler__selectNextNode)(scheduler,cycleLimit), nextNodeOrCheck != 0))) {
    ((int (*)())Scheduler__issueNode)(scheduler,nextNodeOrCheck);
  }
  bucketNumber = 0;
  bucketByteOffset = 0;
  while( true ) {
    while( true ) {
      bucketEmpty = DList__isEmpty(bucketByteOffset + scheduler + 0xac);
      if (bucketEmpty != 0) break;
      bucketNode = *(undefined4 *)(bucketByteOffset + scheduler + 0xb4);
      DList__unlink(bucketNode);
      bundleFull = (**(code **)(**(int **)(scheduler + 8) + 0x20))(*(int **)(scheduler + 8));
      if ((bundleFull == 0) && (bundleFull = Scheduler__transformDotProduct(scheduler,bucketNode), bundleFull != 0)) {
        ((int (*)())Scheduler__issueNode)(scheduler,bundleFull);
      }
      else {
        DList__pushBack(scheduler + 0x7c,bucketNode);
      }
    }
    moreBuckets = bucketNumber == 2;
    bucketNumber = bucketNumber + 1;
    if (moreBuckets) break;
    bucketByteOffset = bucketNumber * 0x18;
  }
  while (((bucketNumber = (**(code **)(**(int **)(scheduler + 8) + 0x20))(*(int **)(scheduler + 8)), bucketNumber == 0
          && (*(int *)(scheduler + 0x118) == 0)) && (bucketNumber = Scheduler__expandPresubToAdd(scheduler), bucketNumber != 0))) {
    ((int (*)())Scheduler__issueNode)(scheduler,bucketNumber);
  }
  committedLast = Scheduler__commitBundle(scheduler);
  if (committedLast == 0) {
    (**(code **)(**(int **)(scheduler + 8) + 0x7c))(*(int **)(scheduler + 8));
  }
  ((int (*)())Scheduler__advanceCycle)(scheduler);
  aluListEmpty = DList__isEmpty(scheduler + 0x4c);
  if ((aluListEmpty == 0) || (aluListEmpty = DList__isEmpty(scheduler + 0x34), aluListEmpty == 0)) {
    finished = 0;
  }
  else {
    waitingListEmpty = DList__isEmpty(scheduler + 100);
    finished = 1;
    if (waitingListEmpty == 0) {
      committedLast2 = Scheduler__commitBundle(scheduler);
      if (committedLast2 == 0) {
        *(uint *)(committedLast + 0x14) = *(uint *)(committedLast + 0x14) | 0x80;
      }
      ((int (*)())Scheduler__advanceCycle)(scheduler);
      finished = 0;
    }
  }
  return finished;
}

/* Scheduler__updateSuccessorsAfterIssue @ 0x170bcc (468 bytes) */
int Scheduler__updateSuccessorsAfterIssue(scheduler, node)
  undefined4 scheduler;
  int node;
{
  int readyCycle;
  uint vectorCount;
  int *edgeSlot;
  uint succEdgeCount;
  uint nextEdgeNumber;
  int edgeByteOffset;
  int issueCycle;
  int successorReadyCycle;
  uint edgeIndex;
  int successorNode;
  uint *successorEdges;
  uint *reloadedSuccEdges;
  
  successorEdges = *(uint **)(node + 0x40);
  succEdgeCount = successorEdges[1];
  if (0 < (int)succEdgeCount) {
    edgeIndex = 0;
    nextEdgeNumber = 1;
    edgeByteOffset = 0;
    while( true ) {
      if (edgeIndex < *successorEdges) {
        vectorCount = successorEdges[1];
        reloadedSuccEdges = successorEdges;
        if (vectorCount <= edgeIndex) {
          _memset(vectorCount * 4 + successorEdges[2],0,(edgeIndex - vectorCount) * 4 + 4);
          successorEdges[1] = nextEdgeNumber;
          reloadedSuccEdges = *(uint **)(node + 0x40);
        }
        edgeSlot = (int *)(edgeByteOffset + successorEdges[2]);
      }
      else {
        edgeSlot = (int *)Vector__elementRefGrow(successorEdges,edgeIndex);
        reloadedSuccEdges = *(uint **)(node + 0x40);
      }
      issueCycle = *(int *)(node + 0x2c);
      successorNode = *(int *)(*edgeSlot + 4);
      successorReadyCycle = *(int *)(successorNode + 0x30);
      *(int *)(successorNode + 0x34) = *(int *)(successorNode + 0x34) + -1;
      if (edgeIndex < *reloadedSuccEdges) {
        vectorCount = reloadedSuccEdges[1];
        if (vectorCount <= edgeIndex) {
          _memset(vectorCount * 4 + reloadedSuccEdges[2],0,(edgeIndex - vectorCount) * 4 + 4);
          reloadedSuccEdges[1] = nextEdgeNumber;
        }
        edgeSlot = (int *)(edgeByteOffset + reloadedSuccEdges[2]);
      }
      else {
        edgeSlot = (int *)Vector__elementRefGrow(reloadedSuccEdges,edgeIndex);
      }
      if (successorReadyCycle < issueCycle + *(int *)(*edgeSlot + 0xc)) {
        successorEdges = *(uint **)(node + 0x40);
        readyCycle = *(int *)(node + 0x2c);
        if (edgeIndex < *successorEdges) {
          vectorCount = successorEdges[1];
          if (vectorCount <= edgeIndex) {
            _memset(vectorCount * 4 + successorEdges[2],0,(edgeIndex - vectorCount) * 4 + 4);
            successorEdges[1] = nextEdgeNumber;
          }
          edgeSlot = (int *)(edgeByteOffset + successorEdges[2]);
        }
        else {
          edgeSlot = (int *)Vector__elementRefGrow(successorEdges,edgeIndex);
        }
        readyCycle = readyCycle + *(int *)(*edgeSlot + 0xc);
      }
      else {
        readyCycle = *(int *)(successorNode + 0x30);
      }
      *(int *)(successorNode + 0x30) = readyCycle;
      if (*(int *)(successorNode + 0x34) == 0) {
        ((int (*)())Scheduler__onNodeReady)(scheduler,successorNode);
      }
      edgeIndex = edgeIndex + 1;
      nextEdgeNumber = nextEdgeNumber + 1;
      edgeByteOffset = edgeByteOffset + 4;
      if (succEdgeCount == edgeIndex) break;
      successorEdges = *(uint **)(node + 0x40);
    }
  }
  return;
}

/* Scheduler__issueDeadNode @ 0x170da0 (204 bytes) */
int Scheduler__issueDeadNode(scheduler, node)
  int scheduler;
  int node;
{
  undefined4 currentCycle;
  int checkResult;
  
  currentCycle = *(undefined4 *)(scheduler + 0x2c);
  *(undefined4 *)(node + 0x2c) = currentCycle;
  *(undefined4 *)(node + 0x30) = currentCycle;
  ((int (*)())SchedModel__uncountNode)(*(undefined4 *)(scheduler + 8),node);
  ((int (*)())Scheduler__releaseOperandsOfIssuedNode)(scheduler,node);
  ((int (*)())Scheduler__updateSuccessorsAfterIssue)(scheduler,node);
  checkResult = (**(code **)(**(int **)(scheduler + 0xc) + 0x20))
                    (*(int **)(scheduler + 0xc),*(undefined4 *)(node + 0x38));
  if (((checkResult != 0) ||
      (checkResult = (**(code **)(**(int **)(scheduler + 0xc) + 0x24))
                         (*(int **)(scheduler + 0xc),*(undefined4 *)(node + 0x38)), checkResult != 0)) &&
     (*(int *)(scheduler + 0x128) <= *(int *)(node + 0xc))) {
    *(int *)(scheduler + 300) = *(int *)(scheduler + 300) + 1;
  }
  *(uint *)(*(int *)(node + 0x38) + 0x14) =
       *(uint *)(*(int *)(node + 0x38) + 0x14) & 0xfffffffe;
  return;
}

/* Scheduler__scheduleBlock @ 0x170e6c (2176 bytes) */
int Scheduler__scheduleBlock(scheduler, block)
  int *scheduler;
  int block;
{
  uint vectorLength3;
  uint successorIndex;
  uint vectorLength2;
  uint vectorLength;
  uint vectorIndex2;
  uint vectorIndex;
  undefined4 *clearCursor5;
  uint *allNodeVector;
  int *aluReadyList;
  int *nextInstNode;
  int *counterCursor;
  int *hwDescription2;
  int *fetchList;
  int *nodeRef2;
  int *loopLoadCursor;
  int *clearCursor3;
  int *hwDescription;
  int *nodeInst;
  int *nodeRef;
  int *clearCursor2;
  int *clearCursor;
  int successorBlock;
  int seedListFirstNode;
  int successorVector;
  int hasBlockFlags;
  int wordsLeft2;
  int wordsLeft;
  int cycleResult;
  int groupNode;
  int groupListEmpty;
  int commitResult;
  int readyListEmpty;
  int needsNoNode;
  int isEntryOrExit;
  int fetchListEmpty;
  int sentinelNode;
  int optionEnabled;
  int loopLoadIndex;
  int componentsLeft2;
  int destRegNumber;
  int fileRegCount;
  int regIndex;
  int hwRegCount;
  int bitSetWordsLeft;
  int byteOffset2;
  int groupNextNode;
  int maxHeight2;
  int maxHeight;
  int isFetchNode;
  int nextListNode;
  int highWaterScalar;
  int highWaterVector;
  int node;
  int componentIndex;
  bool continueLoop;
  int countdown;
  int *liveOutSet;
  undefined4 *clearCursor4;
  int *setCursor;
  int byteOffset3;
  undefined4 *bundleRecord;
  uint regIndexU;
  uint wordByteOffset;
  int byteOffset;
  int *lastScheduledInst;
  uint bitMask;
  int *nextInst;
  uint *externalNodeVector;
  int *inst;
  int componentsLeft;
  int writeMaskBytes;
  int zero;
  /* NOTE (issue #64): declared 8 bytes, but DListNode__init's sentinel-list init writes through +0x14
   * (6 words) - confirmed via stock disasm and by tracing the actual crash: local_38 = auStack_40+0xc
   * computed a pointer past the declared array, into whatever unrelated stack content followed it, so
   * *(local_38+8) read garbage instead of the sentinel's real self-pointer. That garbage happened to
   * read as 0 (list "empty"), so the loop below - which registers this object into a shared pending-list
   * via Scheduler__onNodeReady/Scheduler__enqueueReadyNode - never ran at all, leaving Scheduler__commitBundle's later check permanently
   * empty and crashing much deeper in DList__count (same defect class as the two fixes already landed
   * on this issue for Scheduler__packDotProductCandidates/Inst__distributeResultScale/Scheduler__buildCoScheduleGroups). local_38 only ever stores the *value*
   * auStack_40+0xc (not aliased memory), so simply enlarging the array is sufficient here. */
  undefined1 auStack_40 [0x18];
  int local_38;
  
  Scheduler__buildDependencyGraph(scheduler,block);
  Scheduler__buildCoScheduleGroups(scheduler);
  Scheduler__computeNodePriorities(scheduler);
  liveOutSet = (int *)scheduler[0x4c];
  bitSetWordsLeft = *liveOutSet;
  if (bitSetWordsLeft != 0) {
    if (bitSetWordsLeft == 0) {
      bitSetWordsLeft = 1;
    }
    do {
      liveOutSet[2] = 0;
      liveOutSet = liveOutSet + 1;
      bitSetWordsLeft = bitSetWordsLeft + -1;
    } while (bitSetWordsLeft != 0);
  }
  hwRegCount = scheduler[0x51];
  if (0 < hwRegCount) {
    regIndexU = 0;
    do {
      wordByteOffset = regIndexU >> 3 & 0x1ffffffc;
      bitMask = regIndexU & 0x1f;
      if (((*(uint *)(wordByteOffset + *(int *)(scheduler[1] + 0x430) + 8) >> bitMask & 1) != 0) &&
         ((*(uint *)(wordByteOffset + *(int *)(block + 0x104) + 8) >> bitMask & 1) == 0)) {
        *(uint *)(wordByteOffset + scheduler[0x4c] + 8) = 1 << bitMask | *(uint *)(wordByteOffset + scheduler[0x4c] + 8);
      }
      countdown = 4;
      clearCursor = scheduler;
      do {
        setCursor = clearCursor + 0x4d;
        clearCursor = clearCursor + 1;
        *(undefined4 *)(regIndexU * 4 + *setCursor) = 0;
        countdown = countdown + -1;
      } while (countdown != 0);
      hwRegCount = scheduler[0x51];
      regIndexU = regIndexU + 1;
    } while ((int)regIndexU < hwRegCount);
  }
  if (scheduler[0x58] != 0) {
    clearCursor2 = scheduler;
    while( true ) {
      if (0 < hwRegCount) {
        regIndex = 0;
        do {
          byteOffset = regIndex * 4;
          regIndex = regIndex + 1;
          *(undefined4 *)(byteOffset + clearCursor2[0x54]) = 0;
        } while (regIndex < scheduler[0x51]);
      }
      hwDescription2 = *(int **)(*scheduler + 0x30c);
      fileRegCount = (**(code **)(*hwDescription2 + 0x13c))(hwDescription2,*scheduler);
      if (0 < fileRegCount) {
        componentIndex = 0;
        do {
          byteOffset3 = componentIndex * 4;
          componentIndex = componentIndex + 1;
          *(undefined4 *)(byteOffset3 + clearCursor2[0x58]) = 0;
          fileRegCount = fileRegCount + -1;
        } while (fileRegCount != 0);
      }
      clearCursor2 = clearCursor2 + 1;
      if (scheduler + 4 == clearCursor2) break;
      hwRegCount = scheduler[0x51];
    }
  }
  externalNodeVector = (uint *)scheduler[5];
  vectorLength = externalNodeVector[1];
  if (vectorLength != 0) {
    vectorIndex = 0;
    do {
      if (vectorIndex < *externalNodeVector) {
        if (vectorLength <= vectorIndex) {
          _memset(vectorLength * 4 + externalNodeVector[2],0,(vectorIndex - vectorLength) * 4 + 4);
          externalNodeVector[1] = vectorIndex + 1;
        }
        nodeRef = (int *)(vectorIndex * 4 + externalNodeVector[2]);
      }
      else {
        nodeRef = (int *)Vector__elementRefGrow(externalNodeVector,vectorIndex);
      }
      vectorIndex = vectorIndex + 1;
      node = *nodeRef;
      nodeInst = *(int **)(node + 0x38);
      destRegNumber = nodeInst[0x25];
      if ((((nodeInst[0x20] != 0) && (byteOffset3 = RegKind__flagBit0(nodeInst[0x26]), byteOffset3 != 0)) &&
          ((nodeInst[5] & 2U) == 0)) &&
         ((byteOffset3 = (**(code **)(*nodeInst + 0x50))(nodeInst), byteOffset3 == 0 && ((nodeInst[5] & 0x40U) != 0)))
         ) {
        writeMaskBytes = nodeInst[3];
        if (*(int *)(node + 0x60) != 0) {
          *(int *)(*(int *)(node + 0x60) + 8) = node;
          *(int *)(*(int *)(node + 0x60) + 4) = destRegNumber;
          writeMaskBytes = **(int **)(node + 0x60);
        }
        componentsLeft = 4;
        byteOffset3 = 0;
        counterCursor = scheduler;
        do {
          if (*(char *)((int)&writeMaskBytes + byteOffset3) != '\0') {
            *(int *)(counterCursor[0x4d] + destRegNumber * 4) = node;
            if (counterCursor[0x54] != 0) {
              *(undefined4 *)(counterCursor[0x54] + destRegNumber * 4) = 0x7fffffff;
            }
            if (*(int *)(node + 0x60) != 0) {
              *(int *)(byteOffset3 * 4 + *(int *)(node + 0x60) + 0x18) = node;
              *(undefined4 *)(*(int *)(node + 0x60) + 0x14) = 0;
            }
          }
          byteOffset3 = byteOffset3 + 1;
          counterCursor = counterCursor + 1;
          componentsLeft = componentsLeft + -1;
        } while (componentsLeft != 0);
        if (nodeInst[0x26] == 1) {
          hwDescription = *(int **)(*scheduler + 0x30c);
          byteOffset3 = (**(code **)(*hwDescription + 0x138))(hwDescription,*scheduler);
          highWaterVector = scheduler[0x67];
          if (scheduler[0x67] < destRegNumber - byteOffset3) {
            highWaterVector = destRegNumber - byteOffset3;
          }
          scheduler[0x67] = highWaterVector;
        }
        else {
          highWaterScalar = scheduler[0x66];
          if (scheduler[0x66] < destRegNumber) {
            highWaterScalar = destRegNumber;
          }
          scheduler[0x66] = highWaterScalar;
          if (destRegNumber <= scheduler[0x68]) {
            destRegNumber = scheduler[0x68];
          }
          scheduler[0x68] = destRegNumber;
        }
      }
      externalNodeVector = (uint *)scheduler[5];
      vectorLength = externalNodeVector[1];
    } while (vectorIndex < vectorLength);
  }
  componentsLeft2 = 4;
  clearCursor3 = scheduler;
  do {
    clearCursor3[0x5c] = 0;
    clearCursor3 = clearCursor3 + 1;
    componentsLeft2 = componentsLeft2 + -1;
  } while (componentsLeft2 != 0);
  loopLoadIndex = 0;
  loopLoadCursor = scheduler;
  do {
    continueLoop = loopLoadIndex != 1;
    loopLoadCursor[0x62] = 0;
    loopLoadIndex = loopLoadIndex + 1;
    loopLoadCursor = loopLoadCursor + 1;
  } while (continueLoop);
  optionEnabled = Compiler__isOptionEnabled(*scheduler,0x47);
  if ((optionEnabled != 0) && (optionEnabled = Compiler__isOptionEnabled(*scheduler,0x24), optionEnabled != 0)) {
    Scheduler__packDotProductCandidates(scheduler);
  }
  vectorIndex2 = 0;
  (**(code **)(*(int *)scheduler[2] + 8))((int *)scheduler[2]);
  (**(code **)(*(int *)scheduler[3] + 8))((int *)scheduler[3]);
  scheduler[0x46] = 1;
  scheduler[0x4a] = -1;
  scheduler[0x4b] = 0;
  scheduler[0xb] = 1;
  scheduler[0x47] = -1;
  scheduler[0x48] = -1;
  scheduler[0x49] = 0;
  DListNode__init(auStack_40);
  seedListFirstNode = (int)(auStack_40 + 0xc);
  allNodeVector = (uint *)scheduler[6];
  vectorLength2 = allNodeVector[1];
  if (0 < (int)vectorLength2) {
    while( true ) {
      if (vectorIndex2 < *allNodeVector) {
        vectorLength3 = allNodeVector[1];
        if (vectorLength3 <= vectorIndex2) {
          _memset(vectorLength3 * 4 + allNodeVector[2],0,(vectorIndex2 - vectorLength3) * 4 + 4);
          allNodeVector[1] = vectorIndex2 + 1;
        }
        nodeRef2 = (int *)(vectorIndex2 * 4 + allNodeVector[2]);
      }
      else {
        nodeRef2 = (int *)Vector__elementRefGrow(allNodeVector,vectorIndex2);
      }
      /* issue #76: same shared scheduler[6] array gap as part_044.c's per-format processing -
       * skip a never-populated slot instead of dereferencing it. */
      if ((*nodeRef2 != 0) && (*(int *)(*nodeRef2 + 0x34) == 0)) {
        DList__pushBack(auStack_40,*nodeRef2);
      }
      vectorIndex2 = vectorIndex2 + 1;
      if (vectorLength2 == vectorIndex2) break;
      allNodeVector = (uint *)scheduler[6];
    }
  }
  nextListNode = *(int *)(seedListFirstNode + 8);
  sentinelNode = seedListFirstNode;
  while (byteOffset3 = nextListNode, byteOffset3 != 0) {
    DList__unlink(sentinelNode);
    ((int (*)())Scheduler__onNodeReady)(scheduler,sentinelNode);
    isFetchNode = (**(code **)(*(int *)scheduler[3] + 0x20))
                       ((int *)scheduler[3],*(undefined4 *)(sentinelNode + 0x38));
    if ((isFetchNode == 0) &&
       (isFetchNode = (**(code **)(*(int *)scheduler[3] + 0x24))
                           ((int *)scheduler[3],*(undefined4 *)(sentinelNode + 0x38)), isFetchNode == 0)) {
      maxHeight = *(int *)(sentinelNode + 0xc);
      if (*(int *)(sentinelNode + 0xc) < scheduler[0x47]) {
        maxHeight = scheduler[0x47];
      }
      scheduler[0x47] = maxHeight;
    }
    else {
      maxHeight2 = *(int *)(sentinelNode + 0xc);
      if (*(int *)(sentinelNode + 0xc) < scheduler[0x48]) {
        maxHeight2 = scheduler[0x48];
      }
      scheduler[0x48] = maxHeight2;
    }
    sentinelNode = byteOffset3;
    nextListNode = *(int *)(byteOffset3 + 8);
  }
  fetchList = scheduler + 0xd;
  scheduler[0x46] = 0;
  fetchListEmpty = DList__isEmpty(fetchList);
  if ((fetchListEmpty == 0) && (scheduler[0x47] + -1 <= scheduler[0x48])) {
    scheduler[0x4a] = scheduler[0x48];
    scheduler[0x46] = 1;
  }
  nextInstNode = (int *)(*(int **)(scheduler[4] + 0x98))[2];
  if (nextInstNode != (int *)0x0) {
    lastScheduledInst = (int *)0x0;
    inst = *(int **)(scheduler[4] + 0x98);
    do {
      nextInst = nextInstNode;
      isEntryOrExit = (**(code **)(*inst + 0x34))(inst);
      if ((isEntryOrExit == 0) && (isEntryOrExit = (**(code **)(*inst + 0x38))(inst), isEntryOrExit == 0)) {
        needsNoNode = IRInst__needsNoSchedulerNode(inst);
        if (needsNoNode == 0) {
          DList__unlink(inst);
          inst[0x56] = 0;
        }
        else {
          inst[5] = inst[5] | 4;
          lastScheduledInst = inst;
        }
      }
      else {
        inst[5] = inst[5] & 0xfffffffb;
      }
      nextInstNode = (int *)nextInst[2];
      inst = nextInst;
    } while (nextInstNode != (int *)0x0);
    if (lastScheduledInst != (int *)0x0) {
      lastScheduledInst[5] = lastScheduledInst[5] & 0xfffffffb;
    }
  }
  aluReadyList = scheduler + 0x13;
  readyListEmpty = DList__isEmpty(aluReadyList);
  if ((((readyListEmpty == 0) || (readyListEmpty = DList__isEmpty(fetchList), readyListEmpty == 0)) ||
      (readyListEmpty = DList__isEmpty(scheduler + 0x19), readyListEmpty == 0)) ||
     (readyListEmpty = DList__isEmpty(scheduler + 0x3e), readyListEmpty == 0)) {
    commitResult = Scheduler__commitBundle(scheduler);
    if ((commitResult == 0) && (commitResult = DList__isEmpty(scheduler + 0x25), commitResult != 0)) {
      groupListEmpty = DList__isEmpty(scheduler + 0x3e);
      if (((groupListEmpty == 0) && (groupListEmpty = DList__isEmpty(aluReadyList), groupListEmpty != 0)) &&
         ((groupListEmpty = DList__isEmpty(fetchList), groupListEmpty != 0 &&
          (groupListEmpty = DList__count(scheduler + 0x3e), groupListEmpty == scheduler[0x3d])))) {
        groupNode = scheduler[0x40];
        for (groupNextNode = *(int *)(scheduler[0x40] + 8); groupNextNode != 0; groupNextNode = *(int *)(groupNextNode + 8)) {
          DList__unlink(groupNode);
          *(undefined4 *)(groupNode + 0x68) = 0;
          DList__pushBack(aluReadyList,groupNode);
          groupNode = groupNextNode;
        }
      }
    }
    else {
      ((int (*)())Scheduler__advanceCycle)(scheduler);
    }
    do {
      cycleResult = ((int (*)())Scheduler__scheduleCycle)(scheduler);
    } while (cycleResult == 0);
    Scheduler__commitBundle(scheduler);
    bundleRecord = (undefined4 *)scheduler[0xc];
    wordsLeft = 5;
    clearCursor4 = bundleRecord;
    do {
      *clearCursor4 = 0;
      clearCursor4 = clearCursor4 + 1;
      wordsLeft = wordsLeft + -1;
    } while (wordsLeft != 0);
  }
  else {
    Scheduler__commitBundle(scheduler);
    bundleRecord = (undefined4 *)scheduler[0xc];
    wordsLeft2 = 5;
    clearCursor5 = bundleRecord;
    do {
      *clearCursor5 = 0;
      clearCursor5 = clearCursor5 + 1;
      wordsLeft2 = wordsLeft2 + -1;
    } while (wordsLeft2 != 0);
  }
  DList__initSentinel(bundleRecord + 5);
  hasBlockFlags = (**(code **)(*(int *)scheduler[3] + 0x1c))((int *)scheduler[3]);
  if (hasBlockFlags != 0) {
    successorVector = *(int *)(block + 0xd0);
    byteOffset2 = 0;
    zero = 0;
    for (successorIndex = 1; successorIndex <= *(uint *)(successorVector + 4); successorIndex = successorIndex + 1) {
      successorBlock = *(int *)(*(int *)(successorVector + 8) + byteOffset2);
      if (successorBlock != 0) {
        *(undefined4 *)(successorBlock + 0xdc) = 1;
      }
      byteOffset2 = byteOffset2 + 4;
    }
  }
  return Scheduler__freeNodes(scheduler);
}

/* pass_sched_preprocess_and_schedule_inst @ 0x171714 (408 bytes) */
int pass_sched_preprocess_and_schedule_inst(scheduler, program)
  int *scheduler;
  int program;
{
  undefined4 *allocation;
  undefined4 vectorData;
  undefined4 arena;
  int *nextComponentCursor;
  int *componentCursor;
  int *followingInst;
  int *componentArrayCursor;
  int *liveOutBitSet;
  int fileSize12;
  int regIndex2;
  int nextBlock;
  int poolRoot;
  int fileSize02;
  int regIndex;
  int block;
  int minRegSortEnabled;
  int isUndefined;
  int isExport;
  int exitPredecessorCount;
  int isEntry;
  int programAlias;
  int entrySuccessorCount;
  int compiler;
  int writerArray;
  int externalNodeVector;
  int nodeVector;
  int bundleRecord;
  int liveOutSet;
  int registerCount;
  int fileRegCount;
  int wordsLeft;
  int fileSize0;
  int slotsLeft;
  int threadModel;
  int listCount;
  int *operandVReg;
  int loopIndex;
  bool noSecondFile;
  uint wordCount;
  undefined *deadVtable;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *bundleAlloc;
  int *target;
  int fileSize1;
  int lastUseArray;
  int hwRegister;
  int hwRegister2;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r10;
  undefined4 uVar12;
  int *bitSetCursor;
  int *handledInst;
  int *inst;
  
  scheduler[1] = program;
  iVar4 = *(int *)(program + 8);
  *scheduler = iVar4;
  iVar4 = Compiler__getResourceModel(iVar4);
  scheduler[2] = iVar4;
  threadModel = Compiler__getThreadModel(*scheduler);
  scheduler[3] = threadModel;
  arena = *(undefined4 *)(*scheduler + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[4] = arena;
  allocation[2] = 0;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  scheduler[5] = (int)(allocation + 1);
  arena = *(undefined4 *)(*scheduler + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0x14);
  *allocation = arena;
  allocation[1] = 2;
  allocation[2] = 0;
  allocation[4] = arena;
  vectorData = Arena__alloc(arena,8);
  allocation[3] = vectorData;
  scheduler[6] = (int)(allocation + 1);
  arena = *(undefined4 *)(*scheduler + 0x378);
  bundleAlloc = (undefined4 *)Arena__alloc(arena,0x30);
  *bundleAlloc = arena;
  DListNode__init(bundleAlloc + 6);
  slotsLeft = 5;
  puVar5 = bundleAlloc + 1;
  do {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
    slotsLeft = slotsLeft + -1;
  } while (slotsLeft != 0);
  scheduler[0xc] = (int)(bundleAlloc + 1);
  target = *(int **)(*scheduler + 0x30c);
  fileSize0 = (**(code **)(*target + 0x138))(target,*scheduler);
  target = *(int **)(*scheduler + 0x30c);
  fileSize1 = (**(code **)(*target + 0x140))(target,*scheduler);
  fileSize0 = fileSize0 + fileSize1;
  scheduler[0x51] = fileSize0;
  wordCount = fileSize0 + 0x1fU >> 5;
  arena = *(undefined4 *)(*scheduler + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,wordCount * 4 + 0xc);
  liveOutBitSet = allocation + 1;
  *allocation = arena;
  allocation[1] = wordCount;
  allocation[2] = fileSize0;
  if (wordCount != 0) {
    wordsLeft = *liveOutBitSet;
    bitSetCursor = liveOutBitSet;
    if (wordsLeft == 0) {
      wordsLeft = 1;
    }
    do {
      bitSetCursor[2] = 0;
      bitSetCursor = bitSetCursor + 1;
      wordsLeft = wordsLeft + -1;
    } while (wordsLeft != 0);
  }
  scheduler[0x4c] = (int)liveOutBitSet;
  fileRegCount = (**(code **)(**(int **)(*scheduler + 0x30c) + 0x13c))();
  noSecondFile = fileRegCount < 1;
  componentArrayCursor = scheduler;
  do {
    writerArray = Arena__alloc(*(undefined4 *)(*scheduler + 0x378),scheduler[0x51] << 2);
    componentArrayCursor[0x4d] = writerArray;
    if (noSecondFile) {
      componentArrayCursor[0x54] = 0;
      componentArrayCursor[0x58] = 0;
    }
    else {
      lastUseArray = Arena__alloc(*(undefined4 *)(*scheduler + 0x378),scheduler[0x51] << 2);
      compiler = *scheduler;
      componentArrayCursor[0x54] = lastUseArray;
      compiler = Arena__alloc(*(undefined4 *)(compiler + 0x378),fileRegCount << 2);
      componentArrayCursor[0x58] = compiler;
    }
    componentArrayCursor = componentArrayCursor + 1;
  } while (componentArrayCursor != scheduler + 4);
  registerCount = scheduler[0x51];
  scheduler[0x53] = registerCount;
  scheduler[0x60] = 0;
  scheduler[0x61] = -1;
  scheduler[0x52] = registerCount;
  scheduler[100] = 0;
  scheduler[0x65] = 0;
  scheduler[0x66] = -1;
  scheduler[0x67] = -1;
  scheduler[0x68] = -1;
  scheduler[0x69] = -1;
  scheduler[0x6a] = 0;
  entrySuccessorCount = Block__successorCount(*(undefined4 *)(scheduler[1] + 0x3a0));
  if (entrySuccessorCount == 1) {
    programAlias = scheduler[1];
    puVar5 = (undefined4 *)0x0;
    registerCount = *(int *)(*(int *)(programAlias + 0x3a0) + 0xd0);
    if (*(int *)(registerCount + 4) != 0) {
      puVar5 = *(undefined4 **)(registerCount + 8);
    }
    inst = *(int **)(*(int *)(programAlias + 0x3a0) + 0xa0);
    uVar12 = *puVar5;
    followingInst = (int *)inst[1];
    if (followingInst != (int *)0x0) {
      do {
        handledInst = followingInst;
        isEntry = (**(code **)(*inst + 0x34))(inst);
        if ((isEntry == 0) && (isEntry = (**(code **)(*inst + 0x38))(inst), isEntry == 0)) {
          DList__unlink(inst);
          Block__prependInst(uVar12,inst);
        }
        followingInst = (int *)handledInst[1];
        inst = handledInst;
      } while (followingInst != (int *)0x0);
      programAlias = scheduler[1];
    }
    *(undefined4 *)(programAlias + 0x3a4) = uVar12;
  }
  exitPredecessorCount = Block__predecessorCount(*(undefined4 *)(scheduler[1] + 0x3a8));
  if (exitPredecessorCount == 1) {
    programAlias = scheduler[1];
    puVar5 = (undefined4 *)0x0;
    registerCount = *(int *)(*(int *)(programAlias + 0x3a8) + 0xd4);
    if (*(int *)(registerCount + 4) != 0) {
      puVar5 = *(undefined4 **)(registerCount + 8);
    }
    inst = *(int **)(*(int *)(programAlias + 0x3a8) + 0x98);
    uVar12 = *puVar5;
    followingInst = (int *)inst[2];
    if (followingInst == (int *)0x0) goto code_r0x00171ba0;
    do {
      handledInst = followingInst;
      isEntry = (**(code **)(*inst + 0x34))(inst);
      if ((isEntry == 0) && (isEntry = (**(code **)(*inst + 0x38))(inst), isEntry == 0)) {
        isExport = (**(code **)(*inst + 0x68))(inst);
        if (isExport != 0) {
          operandVReg = (int *)IRInst__getOperandSource(inst,1);
          isUndefined = (**(code **)(*operandVReg + 0x50))();
          if (isUndefined != 0) goto code_r0x00171b84;
        }
        DList__unlink(inst);
        Block__appendInst(uVar12,inst);
      }
code_r0x00171b84:
      followingInst = (int *)handledInst[2];
      inst = handledInst;
    } while (followingInst != (int *)0x0);
  }
  programAlias = scheduler[1];
code_r0x00171ba0:
  (**(code **)(*(int *)scheduler[2] + 0x70))((int *)scheduler[2],programAlias);
  Program__beginPass(scheduler[1],(int)"sched_preprocess");
  minRegSortEnabled = Compiler__isOptionEnabled(*scheduler,0x43);
  if (minRegSortEnabled != 0) {
    pass_minreg_order(scheduler,program);
  }
  Scheduler__markGlobalValues(scheduler);
  Scheduler__computeBlockRegisterSets(scheduler);
  block = *(int *)(scheduler[1] + 900);
  nextBlock = *(int *)(block + 8);
  while (nextBlock != 0) {
    listCount = DList__count(block + 0x90);
    if (2 < listCount) {
      ((int (*)())Scheduler__scheduleBlock)(scheduler,block);
      registerCount = scheduler[1];
      scheduler[100] = scheduler[100] + scheduler[0xb];
      *(undefined4 *)(block + 0x118) = *(undefined4 *)(registerCount + 0x474);
    }
    block = *(int *)(block + 8);
    nextBlock = *(int *)(block + 8);
  }
  if (!noSecondFile) {
    scheduler[0x66] = scheduler[0x68];
  }
  if (-1 < scheduler[0x66]) {
    regIndex = 0;
    do {
      regIndex2 = regIndex + 1;
      Program__markHwRegUsed(scheduler[1],regIndex);
      regIndex = regIndex2;
    } while (regIndex2 <= scheduler[0x66]);
  }
  fileSize02 = (**(code **)(**(int **)(*scheduler + 0x30c) + 0x138))();
  if (-1 < scheduler[0x67]) {
    regIndex2 = 0;
    do {
      hwRegister = fileSize02 + regIndex2;
      regIndex2 = regIndex2 + 1;
      Program__markHwRegUsed(scheduler[1],hwRegister);
    } while (regIndex2 <= scheduler[0x67]);
  }
  fileSize12 = (**(code **)(**(int **)(*scheduler + 0x30c) + 0x140))();
  if (-1 < scheduler[0x69]) {
    loopIndex = 0;
    do {
      hwRegister2 = fileSize02 + fileSize12 + loopIndex;
      loopIndex = loopIndex + 1;
      Program__markHwRegUsed(scheduler[1],hwRegister2);
    } while (loopIndex <= scheduler[0x69]);
  }
  Compiler__logf(*scheduler,"Scheduler : Total cycles %d\n",scheduler[100],in_r6,in_r7,in_r8,registerCount,in_r10)
  ;
  Compiler__logf(*scheduler,"Scheduler : Total dot-product transformed %d\n",scheduler[0x6a],in_r6,in_r7,
               in_r8,registerCount,in_r10);
  Program__beginPass(scheduler[1],(int)"schedule_inst");
  Program__freeBlockBitsets(program);
  liveOutSet = scheduler[0x4c];
  componentCursor = scheduler;
  if (liveOutSet != 0) {
    Arena__free(*(undefined4 *)(liveOutSet + -4),liveOutSet + -4);
  }
  do {
    if (!noSecondFile) {
      Arena__free(*(undefined4 *)(*scheduler + 0x378),componentCursor[0x54]);
      Arena__free(*(undefined4 *)(*scheduler + 0x378),componentCursor[0x58]);
    }
    nextComponentCursor = componentCursor + 1;
    Arena__free(*(undefined4 *)(*scheduler + 0x378),componentCursor[0x4d]);
    componentCursor = nextComponentCursor;
  } while (componentArrayCursor != nextComponentCursor);
  bundleRecord = scheduler[0xc];
  if (bundleRecord != 0) {
    deadVtable = PTR_DAT_001e8b48 + 8;
    *(undefined **)(bundleRecord + 0x14) = deadVtable;
    *(undefined **)(bundleRecord + 0x20) = deadVtable;
    Arena__free(*(undefined4 *)(bundleRecord + -4),bundleRecord + -4);
  }
  nodeVector = scheduler[6];
  if (nodeVector != 0) {
    Arena__free(*(undefined4 *)(nodeVector + 0xc),*(undefined4 *)(nodeVector + 8));
    Arena__free(*(undefined4 *)(nodeVector + -4),nodeVector + -4);
  }
  externalNodeVector = scheduler[5];
  if (externalNodeVector != 0) {
    Arena__free(*(undefined4 *)(externalNodeVector + 0xc),*(undefined4 *)(externalNodeVector + 8));
    poolRoot = *(int *)(externalNodeVector + -4);
    if ((*(int *)(poolRoot + 0x28) != 0) && (fileSize12 = *(int *)(poolRoot + 0x14), fileSize12 == externalNodeVector + -4)) {
      _memset(fileSize12,0,*(int *)(poolRoot + 8) - fileSize12);
      *(undefined4 *)(poolRoot + 8) = *(undefined4 *)(poolRoot + 0x14);
    }
    return;
  }
  return;
}

/* Scheduler__run @ 0x171e68 (200 bytes) */
int Scheduler__run(program)
  int program;
{
  undefined4 *sentinelCursorBack;
  int heightReductionEnabled;
  bool moreSentinels;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 *sentinelCursor;
  int sentinelsLeft;
  /* NOTE (issue #64, ROOT CAUSE of the DList__count crash): these 9 locals were declared as separate
   * adjacent stack scalars/arrays, but this function's own code treats them as ONE contiguous 0x1c0-byte
   * region - confirmed three independent ways: (1) their own names encode consecutive stock frame
   * offsets with no gaps (0x1d8-0x1a4=0x34=auStack_1d8's real size, ... down to local_e0 starting at
   * exactly 0xf8 bytes in); (2) the backward-walking loop a few lines down decrements by exactly 6 words
   * (24 bytes) per step through auStack_144/15c/174/18c/1a4, expecting them contiguous; (3) empirically -
   * this IS the original crash: Scheduler__scheduleBlock reads *(this_object + 0x3e words) = +0xf8 bytes, which lands
   * exactly on local_e0's real position in stock (a real DListNode__init sentinel list), but on -O0-scattered
   * garbage in the rebuild, since nothing guarantees these 9 separate locals land in this order or even
   * adjacently. Traced from the crash back to here across two long sessions (issue #64) - fixing by
   * forcing one real contiguous buffer with aliases at the exact offsets stock's own naming confirms. */
  undefined1 auStack_1e68_combined [0x1c0];
#define auStack_1d8 (auStack_1e68_combined + 0x0)
#define auStack_1a4 (auStack_1e68_combined + 0x34)
#define auStack_18c (auStack_1e68_combined + 0x4c)
#define auStack_174 (auStack_1e68_combined + 0x64)
#define auStack_15c (auStack_1e68_combined + 0x7c)
#define auStack_144 (auStack_1e68_combined + 0x94)
#define auStack_12c ((undefined4 *)(auStack_1e68_combined + 0xac))
#define uStack_e4 (*(undefined4 *)(auStack_1e68_combined + 0xf4))
#define local_e0 (auStack_1e68_combined + 0xf8)
  undefined4 *puVar3;
  
  DListNode__init(auStack_1a4);
  DListNode__init(auStack_18c);
  DListNode__init(auStack_174);
  DListNode__init(auStack_15c);
  DListNode__init(auStack_144);
  sentinelsLeft = 1;
  sentinelCursor = auStack_12c;
  do {
    DListNode__init(sentinelCursor);
    moreSentinels = sentinelsLeft != -1;
    sentinelCursor = sentinelCursor + 6;
    sentinelsLeft = sentinelsLeft + -1;
  } while (moreSentinels);
  DListNode__init(local_e0);
  heightReductionEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x42);
  if (heightReductionEnabled != 0) {
    pass_height_reduction(auStack_1d8,program,in_r5,in_r6,in_r7,in_r8,in_r9);
  }
  ((int (*)())pass_sched_preprocess_and_schedule_inst)(auStack_1d8,program);
  sentinelCursorBack = &uStack_e4;
  do {
    puVar3 = sentinelCursorBack + -6;
    *puVar3 = PTR_DAT_001e8b48 + 8;
    sentinelCursorBack[-3] = PTR_DAT_001e8b48 + 8;
    sentinelCursorBack = puVar3;
  } while (puVar3 != auStack_12c);
  return;
}

/* SchedModel__resetCounters @ 0x172000 (20 bytes) */
int SchedModel__resetCounters(model)
  int model;
{
  *(undefined4 *)(model + 0x14) = 0;
  *(undefined4 *)(model + 0xc) = 0;
  *(undefined4 *)(model + 0x10) = 0;
  return;
}

/* ResourceModel__vslot23 @ 0x172014 (100 bytes) */
int ResourceModel__vslot23(this)
  int this;
{
  uint countSum;
  int class1Count;
  int class2Count;
  
  class1Count = *(int *)(this + 0xc);
  class2Count = *(int *)(this + 0x10);
  if (class1Count <= class2Count) {
    if (*(int *)(this + 0x14) < class2Count - class1Count) {
      return class2Count;
    }
    countSum = *(int *)(this + 0x14) + class1Count + class2Count;
    return ((int)countSum >> 1) + (uint)((int)countSum < 0 && (countSum & 1) != 0);
  }
  if (*(int *)(this + 0x14) < class1Count - class2Count) {
    return class1Count;
  }
  countSum = *(int *)(this + 0x14) + class1Count + class2Count;
  return ((int)countSum >> 1) + (uint)((int)countSum < 0 && (countSum & 1) != 0);
}

/* SchedModel__countIssuedNode @ 0x172078 (180 bytes) */
int SchedModel__countIssuedNode(model, node)
  int *model;
  int node;
{
  int nodeClass;
  
  (**(code **)(*model + 0x4c))(model,*(undefined4 *)(node + 0x38));
  nodeClass = *(int *)(node + 0x58);
  if (nodeClass == 3) {
    model[3] = model[3] + 1;
    model[4] = model[4] + 1;
  }
  else if (*(int *)(node + 0x5c) == 0) {
    if (nodeClass == 1) {
      model[3] = model[3] + 1;
    }
    else if (nodeClass == 2) {
      model[4] = model[4] + 1;
    }
  }
  else {
    model[5] = model[5] + 1;
  }
  return;
}

/* SchedModel__uncountNode @ 0x17212c (216 bytes) */
int SchedModel__uncountNode(model, node)
  int *model;
  int node;
{
  int nodeClass;
  int newClass;
  int oldClass;
  
  oldClass = *(int *)(node + 0x58);
  newClass = (**(code **)(*model + 0x4c))(model,*(undefined4 *)(node + 0x38));
  if (oldClass != newClass) {
    (**(code **)(*model + 0x50))(model);
  }
  nodeClass = *(int *)(node + 0x58);
  if (nodeClass == 3) {
    model[3] = model[3] + -1;
    model[4] = model[4] + -1;
  }
  else if (*(int *)(node + 0x5c) == 0) {
    if (nodeClass == 1) {
      model[3] = model[3] + -1;
    }
    else if (nodeClass == 2) {
      model[4] = model[4] + -1;
    }
  }
  else {
    model[5] = model[5] + -1;
  }
  return;
}

/* FUN_00172204 @ 0x172204 (200 bytes) */
int FUN_00172204(model, node)
  int *model;
  undefined4 node;
{
  int vcall4cResult;
  int vcall30Result;
  
  vcall4cResult = (**(code **)(*model + 0x4c))(model,node);
  vcall30Result = (**(code **)(*model + 0x30))(model,node);
  if (vcall4cResult == 3) {
    model[3] = model[3] + 1;
    model[4] = model[4] + 1;
  }
  else if (vcall30Result == 0) {
    if (vcall4cResult == 1) {
      model[3] = model[3] + 1;
    }
    else if (vcall4cResult == 2) {
      model[4] = model[4] + 1;
    }
  }
  else {
    model[5] = model[5] + 1;
  }
  return;
}

/* ResourceModel__vslot24 @ 0x1722cc (92 bytes) */
int ResourceModel__vslot24(this, node)
  int this;
  int node;
{
  if (*(int *)(this + 0x10) + *(int *)(this + 0x14) < *(int *)(this + 0xc)) {
    return *(int *)(node + 0x20) + *(int *)(node + 0x28);
  }
  if (*(int *)(this + 0xc) + *(int *)(this + 0x14) < *(int *)(this + 0x10)) {
    return *(int *)(node + 0x20) + *(int *)(node + 0x24);
  }
  return *(int *)(node + 0x20) + *(int *)(node + 0x24) + *(int *)(node + 0x28);
}

/* ResourceModel__vslot25 @ 0x172328 (176 bytes) */
int ResourceModel__vslot25(this, node)
  int this;
  int node;
{
  int midCount;
  uint countSum;
  int resourceClass;
  int lowerCount;
  int class1Count;
  int higherCount;
  int class2Count;
  
  class1Count = *(int *)(this + 0xc);
  class2Count = *(int *)(this + 0x10);
  lowerCount = class1Count;
  higherCount = class2Count;
  if (class2Count < class1Count) {
    lowerCount = class2Count;
    higherCount = class1Count;
  }
  if ((higherCount - lowerCount) + 2 <= *(int *)(this + 0x14)) {
    countSum = *(int *)(this + 0x14) + class1Count + class2Count;
    midCount = ((int)countSum >> 1) + (uint)((int)countSum < 0 && (countSum & 1) != 0);
    if ((countSum & 1) != 0) {
      return midCount + 1;
    }
    return midCount;
  }
  resourceClass = *(int *)(node + 0x58);
  if (resourceClass == 3) {
    return higherCount;
  }
  if (*(int *)(node + 0x5c) == 0) {
    if (resourceClass == 1) {
      if (class1Count == higherCount) {
        return class1Count;
      }
    }
    else {
      if (resourceClass != 2) {
        return 0;
      }
      if (class2Count == higherCount) {
        return class2Count;
      }
    }
  }
  return lowerCount;
}

/* ResourceModel__vslot29 @ 0x1723d8 (80 bytes) */
int ResourceModel__vslot29(this, node, bundleRecord)
  undefined4 this;
  int node;
  int *bundleRecord;
{
  int *slotCursor;
  int slotIndex;
  int slotsLeft;
  
  if (*(int *)(node + 0x58) == 0) {
    DList__pushBack(bundleRecord + 5,node);
    return;
  }
  slotsLeft = 5;
  slotIndex = 0;
  slotCursor = bundleRecord;
  do {
    if (*slotCursor == 0) {
      bundleRecord[slotIndex] = node;
      return;
    }
    slotIndex = slotIndex + 1;
    slotCursor = slotCursor + 1;
    slotsLeft = slotsLeft + -1;
  } while (slotsLeft != 0);
  return;
}

/* ResourceModel__vslot22 @ 0x172428 (76 bytes) */
int ResourceModel__vslot22(this, countA, countB, countC)
  int this;
  int countA;
  int countB;
  int countC;
{
  undefined4 tooLargeFlag;
  undefined4 tooLarge;
  
  if (*(int *)(*(int *)(this + 8) + 0x6b8) != 0) {
    return 1;
  }
  if ((countA < 0x10) && ((countB < 0x10 || (countC <= countB << 2)))) {
    tooLargeFlag = 0;
    tooLarge = 0;
  }
  else {
    tooLargeFlag = 1;
    tooLarge = 1;
  }
  *(undefined4 *)(*(int *)(this + 8) + 0x6b8) = tooLargeFlag;
  return tooLarge;
}

/* ResourceModel__vslot32 @ 0x172474 (96 bytes) */
int ResourceModel__vslot32(this, inst, variant)
  int this;
  undefined4 *inst;
  int variant;
{
  undefined4 *allocation;
  undefined4 newOpcode;
  undefined4 arena;
  
  if (inst == (undefined4 *)0x0) {
    newOpcode = 0x2b;
    if (variant == 0) {
      newOpcode = 0xa6;
    }
    arena = *(undefined4 *)(*(int *)(this + 8) + 0x374);
    allocation = (undefined4 *)Arena__alloc(arena,0x168);
    *allocation = arena;
    inst = allocation + 1;
    IRInst__ctor_10502c(inst,newOpcode,*(undefined4 *)(this + 8));
  }
  else {
    IRInst__switchOpcodeVariant(inst,variant);
  }
  return inst;
}

/* ResourceModel__vslot11 @ 0x172514 (176 bytes) */
int ResourceModel__vslot11(this, node)
  int *this;
  int node;
{
  int vcallcResult;
  
  ((int (*)())SchedModel__uncountNode)(this,node);
  (**(code **)(*this + 0x38))(this,node);
  vcallcResult = (**(code **)(*this + 0xc))(this,*(undefined4 *)(node + 0x38));
  if (vcallcResult == 0) {
    (**(code **)(*this + 0x38))(this,node);
    ((int (*)())SchedModel__countIssuedNode)(this,node);
  }
  else {
    ((int (*)())SchedModel__countIssuedNode)(this,node);
  }
  return vcallcResult != 0;
}

/* FUN_001725c4 @ 0x1725c4 (600 bytes) */
int FUN_001725c4(inst, operandIndex2, compiler)
  int *inst;
  int operandIndex2;
  int compiler;
{
  int operandRecord;
  int newInst;
  undefined4 operandVReg;
  int vcall28Result;
  int callResult;
  int block;
  int operandIndex;
  int *afterInst;
  undefined4 readMaskOut;
  undefined4 selectWhereMaskedOut;
  undefined4 maskedUnusedOut [4];
  
  block = inst[0x56];
  operandVReg = IRInst__getOperandSource(inst,operandIndex2);
  newInst = IRInst__create(0x31,compiler);
  *(undefined4 *)(newInst + 0x98) = 0;
  *(undefined4 *)(newInst + 0x94) = *(undefined4 *)(newInst + 0x14c);
  IRInst__setOperandSource(newInst,1,operandVReg,0,compiler);
  operandRecord = IRInst__getOperandRecord(inst,operandIndex2);
  SelectWord__readMask(&readMaskOut,*(undefined4 *)(operandRecord + 0x10));
  IRInst__setOperandSource(inst,operandIndex2,newInst,0,compiler);
  SelectWord__selectWhereMasked(&selectWhereMaskedOut,DAT_001b01b0,readMaskOut);
  *(undefined4 *)(newInst + 0x9c) = selectWhereMaskedOut;
  SelectWord__maskUnused(maskedUnusedOut,DAT_001b01ac,readMaskOut);
  operandRecord = IRInst__getOperandRecord(newInst,1);
  *(undefined4 *)(operandRecord + 0x10) = maskedUnusedOut[0];
  *(undefined4 *)(newInst + 0xc) = readMaskOut;
  if ((inst[operandIndex2 * 6 + 0x28] & 2U) != 0) {
    IROperand__setModifierBits(inst + operandIndex2 * 6 + 0x23,2,0);
    IROperand__setModifierBits(newInst + 0xa4,2,1);
  }
  callResult = FUN_00165604(block,newInst);
  operandIndex = 1;
  if (*(int *)(callResult + 0x158) == 0) {
    *(int *)(*(int *)(compiler + 0x6c4) + 0x238) = *(int *)(*(int *)(compiler + 0x6c4) + 0x238) + 1;
    vcall28Result = (**(code **)(*inst + 0x28))(inst);
    if (vcall28Result == 0) {
      Block__insertInstBefore(block,inst,callResult);
    }
    else {
      for (afterInst = (int *)inst[1]; afterInst != (int *)0x0; afterInst = (int *)afterInst[1]) {
        vcall28Result = (**(code **)(*afterInst + 0x28))(afterInst);
        if (vcall28Result == 0) {
          Block__insertInstAfter(block,afterInst,callResult);
          return callResult;
        }
      }
      Block__prependInst(block,callResult);
    }
  }
  else {
    for (; block = (**(code **)(*inst + 0x14))(inst), operandIndex <= block; operandIndex = operandIndex + 1) {
      block = IRInst__getOperandSource(inst,operandIndex);
      if (newInst == block) {
        IRInst__setOperandSource(inst,operandIndex,callResult,0,compiler);
      }
    }
  }
  return callResult;
}

/* ThreadModel__vslot4 @ 0x17281c (416 bytes) */
int ThreadModel__vslot4(this, node)
  int *this;
  int node;
{
  int edgeByteOffset;
  int isFetch;
  uint vectorCount;
  int *edgeSlot;
  undefined4 *edgeSlot2;
  uint predEdgeCount;
  uint nextCount;
  uint loopIndex;
  uint *predEdges;
  
  isFetch = (**(code **)(**(int **)(node + 0x38) + 0x28))(*(int **)(node + 0x38),node);
  if ((isFetch != 0) &&
     (isFetch = (**(code **)(*this + 0x20))(this,*(undefined4 *)(node + 0x38)), isFetch != 0))
  {
    this[2] = *(int *)(node + 0x2c);
  }
  predEdges = *(uint **)(node + 0x44);
  predEdgeCount = predEdges[1];
  if (0 < (int)predEdgeCount) {
    loopIndex = 0;
    nextCount = 1;
    edgeByteOffset = 0;
    while( true ) {
      if (loopIndex < *predEdges) {
        vectorCount = predEdges[1];
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + predEdges[2],0,(loopIndex - vectorCount) * 4 + 4);
          predEdges[1] = nextCount;
        }
        edgeSlot = (int *)(edgeByteOffset + predEdges[2]);
      }
      else {
        edgeSlot = (int *)Vector__elementRefGrow(predEdges,loopIndex);
      }
      if (*(int *)(*edgeSlot + 0x1c) != 0) {
        predEdges = *(uint **)(node + 0x44);
        if (loopIndex < *predEdges) {
          vectorCount = predEdges[1];
          if (vectorCount <= loopIndex) {
            _memset(vectorCount * 4 + predEdges[2],0,(loopIndex - vectorCount) * 4 + 4);
            predEdges[1] = nextCount;
          }
          edgeSlot2 = (undefined4 *)(edgeByteOffset + predEdges[2]);
        }
        else {
          edgeSlot2 = (undefined4 *)Vector__elementRefGrow(predEdges,loopIndex);
        }
        if (this[1] <= *(int *)(*(int *)*edgeSlot2 + 0x2c)) {
          *(uint *)(*(int *)(node + 0x38) + 0x14) =
               *(uint *)(*(int *)(node + 0x38) + 0x14) | 0x1000;
          this[1] = *(int *)(node + 0x2c);
        }
      }
      loopIndex = loopIndex + 1;
      nextCount = nextCount + 1;
      edgeByteOffset = edgeByteOffset + 4;
      if (predEdgeCount == loopIndex) break;
      predEdges = *(uint **)(node + 0x44);
    }
  }
  return;
}

/* FUN_001729bc @ 0x1729bc (108 bytes) */
int FUN_001729bc(key)
  int key;
{
  int *keyPtr;
  int innerKeyCursor;
  int lanesLeft;
  int loopIndex;
  int outerKeyCursor;
  int innerCountdown;
  
  loopIndex = 1;
  outerKeyCursor = key;
  do {
    innerKeyCursor = key;
    innerCountdown = loopIndex;
    if (*(int *)(key + 0x20) == *(int *)(outerKeyCursor + 0x24)) {
      return 1;
    }
    while (innerCountdown + -1 != 0) {
      keyPtr = (int *)(innerKeyCursor + 0x24);
      innerKeyCursor = innerKeyCursor + 4;
      innerCountdown = innerCountdown + -1;
      if (*(int *)(outerKeyCursor + 0x24) == *keyPtr) {
        return 1;
      }
    }
    lanesLeft = 4 - loopIndex;
    do {
      loopIndex = loopIndex + 1;
      outerKeyCursor = outerKeyCursor + 4;
      lanesLeft = lanesLeft + -1;
      if (lanesLeft == 0) {
        return 0;
      }
    } while (loopIndex < 1);
  } while( true );
}

/* ValueKey__maybeRefineSources @ 0x172a28 (104 bytes) */
int ValueKey__maybeRefineSources(key)
  int key;
{
  int isOptionEnabledResult;
  
  isOptionEnabledResult = Compiler__isOptionEnabled(*(undefined4 *)(key + 0x238),9);
  if ((isOptionEnabledResult != 0) && (isOptionEnabledResult = Compiler__isOptionEnabled(*(undefined4 *)(key + 0x238),0x30), isOptionEnabledResult != 0)) {
    ValueKey__splitDestinationIfEligible(key);
    return;
  }
  return;
}

/* ValueKey__swapSources12 @ 0x172a90 (32 bytes) */
int ValueKey__swapSources12(inst, key, compiler)
  undefined4 inst;
  int key;
  uint compiler;
{
  undefined4 savedSource1;
  
  savedSource1 = *(undefined4 *)(key + 8);
  *(undefined4 *)(key + 8) = *(undefined4 *)(key + 4);
  *(undefined4 *)(key + 4) = savedSource1;
  return IRInst__swapOperands(inst,1,2,compiler);
}

/* ExprRecordTable__hashByValueNumber @ 0x172ab0 (40 bytes) */
int ExprRecordTable__hashByValueNumber(record)
  int record;
{
  return *(int *)(record + 4) % 0x65;
}

/* ExprRecordTable__eqByValueNumber @ 0x172ad8 (28 bytes) */
int ExprRecordTable__eqByValueNumber(recordA, recordB)
  int recordA;
  int recordB;
{
  return -(uint)(*(int *)(recordA + 4) != *(int *)(recordB + 4));
}

/* ExprRecordTable__hashByExpr @ 0x172af4 (56 bytes) */
int ExprRecordTable__hashByExpr(record)
  int *record;
{
  return (*record * 0x25) % 0x65;
}

/* ExprRecordTable__eqByExpr @ 0x172b2c (28 bytes) */
int ExprRecordTable__eqByExpr(recordA, recordB)
  int *recordA;
  int *recordB;
{
  return -(uint)(*recordA != *recordB);
}

/* PtrSet__hashPtr @ 0x172b48 (40 bytes) */
int PtrSet__hashPtr(slot)
  int *slot;
{
  return *slot % 0x65;
}

/* PtrSet__eqNonNullPtr @ 0x172b70 (48 bytes) */
int PtrSet__eqNonNullPtr(slotA, slotB)
  undefined4 *slotA;
  undefined4 *slotB;
{
  int callResult;
  
  callResult = Ptr__equalNonNull(*slotA,*slotB);
  return -(uint)(callResult == 0);
}

/* KeyLaneTable__hashByOpcode @ 0x172ba0 (48 bytes) */
int KeyLaneTable__hashByOpcode(entry)
  int entry;
{
  return *(uint *)(*(int *)(entry + 4) + 0xb4) % 0x65;
}

/* KeyLaneTable__eqKeys @ 0x172bd0 (332 bytes) */
int KeyLaneTable__eqKeys(keyA, keyB)
  int keyA;
  int keyB;
{
  int operandIdx;
  int laneSlotB;
  int cursorA;
  int cursorB;
  int *laneFieldPtrA;
  int *laneFieldPtrB;
  int opcodeCheck;
  undefined4 result;
  int fieldsA;
  int fieldsB;
  int keyOrCountReg;
  int laneB;
  int *keyInst;
  int recordB;
  undefined4 *selectCursorA;
  int recordA;
  undefined4 *selectCursorB;
  
  recordA = *(int *)(keyA + 4);
  recordB = *(int *)(keyB + 4);
  keyInst = *(int **)(recordA + 0xb0);
  keyOrCountReg = *(int *)(keyA + 8);
  laneB = *(int *)(keyB + 8);
  opcodeCheck = OpcodeTraits__flag1WithoutFlag7(*(undefined4 *)(recordA + 0x238),keyInst);
  fieldsA = recordA + 0xb4;
  fieldsB = recordB + 0xb4;
  if ((((opcodeCheck == 0) || (*(int *)(recordA + 0xb4) != *(int *)(recordB + 0xb4))) ||
      (*(int *)(recordA + 0xc0) != *(int *)(recordB + 0xc0))) ||
     (*(int *)(recordA + 0xc4) != *(int *)(recordB + 0xc4))) {
LAB_00172d04:
    result = 0xffffffff;
  }
  else {
    keyOrCountReg = keyOrCountReg * 4 + fieldsA;
    laneSlotB = laneB * 4 + fieldsB;
    cursorA = keyOrCountReg + 0x14;
    cursorB = laneSlotB + 0x14;
    selectCursorA = (undefined4 *)(keyOrCountReg + 0xc4);
    selectCursorB = (undefined4 *)(laneSlotB + 0xc4);
    for (operandIdx = 1; keyOrCountReg = (**(code **)(*keyInst + 0x14))(keyInst), operandIdx <= keyOrCountReg; operandIdx = operandIdx + 1
        ) {
      keyOrCountReg = Ptr__equalNonNull(*selectCursorA,*selectCursorB);
      if (((keyOrCountReg == 0) || (*(int *)(fieldsA + 0x108) != *(int *)(fieldsB + 0x108))) ||
         (*(int *)(cursorA + 0x20) != *(int *)(cursorB + 0x20))) goto LAB_00172d04;
      laneFieldPtrA = (int *)(cursorA + 0x30);
      fieldsA = fieldsA + 4;
      laneFieldPtrB = (int *)(cursorB + 0x30);
      cursorA = cursorA + 0x20;
      cursorB = cursorB + 0x20;
      fieldsB = fieldsB + 4;
      selectCursorA = selectCursorA + 4;
      selectCursorB = selectCursorB + 4;
      if (*laneFieldPtrA != *laneFieldPtrB) goto LAB_00172d04;
    }
    result = 0;
  }
  return result;
}

/* ScopedExprTable__hashKey @ 0x172d1c (168 bytes) */
int ScopedExprTable__hashKey(key)
  int key;
{
  int laneValue;
  int *laneCursor;
  int operandCountOrLanesLeft;
  int operandIndex;
  int hash;
  
  hash = 1;
  for (operandIndex = 0;
      operandCountOrLanesLeft = (**(code **)(**(int **)(key + 0xb0) + 0x14))(*(int **)(key + 0xb0)),
      operandIndex < operandCountOrLanesLeft; operandIndex = operandIndex + 1) {
    operandCountOrLanesLeft = 4;
    laneCursor = (int *)(operandIndex * 0x10 + key + 0x168);
    do {
      laneValue = *laneCursor;
      laneCursor = laneCursor + 1;
      hash = hash * laneValue;
      operandCountOrLanesLeft = operandCountOrLanesLeft + -1;
    } while (operandCountOrLanesLeft != 0);
  }
  return (hash + *(int *)(key + 0xb4)) % 0x65;
}

/* ScopedExprTable__eqKeys @ 0x172dc4 (56 bytes) */
int ScopedExprTable__eqKeys(keyA, keyB)
  int keyA;
  int keyB;
{
  int compareResult;
  
  compareResult = _memcmp(keyA + 0xb4,keyB + 0xb4,0x15c);
  return (compareResult == 0) - 1;
}

/* returnZero_172dfc @ 0x172dfc (8 bytes) */
int returnZero_172dfc()
{
  return 0;
}

/* LaneMatchTable__eqKeys @ 0x172e04 (116 bytes) */
int LaneMatchTable__eqKeys(keyA, keyB)
  int keyA;
  int keyB;
{
  int loopIndex;
  bool moreComponents;
  int keyBCursor;
  int keyACursor;
  int countdown;
  
  countdown = 4;
  keyBCursor = keyB;
  keyACursor = keyA;
  while( true ) {
    if (((*(int *)(keyACursor + 0x20) != *(int *)(keyBCursor + 0x20)) && (*(int *)(keyACursor + 0x20) != 3)) &&
       (*(int *)(keyBCursor + 0x20) != 3)) break;
    keyACursor = keyACursor + 4;
    keyBCursor = keyBCursor + 4;
    countdown = countdown + -1;
    if (countdown == 0) {
      loopIndex = 0;
      do {
        if (*(int *)(keyA + 0xb8) != *(int *)(keyB + 0xb8)) {
          return 0xffffffff;
        }
        moreComponents = loopIndex != 1;
        keyA = keyA + 4;
        keyB = keyB + 4;
        loopIndex = loopIndex + 1;
      } while (moreComponents);
      return 0;
    }
  }
  return 0xffffffff;
}

/* SwizzleTable__hashKey @ 0x172e78 (92 bytes) */
int SwizzleTable__hashKey(key)
  int key;
{
  uint laneWord;
  int laneAbs;
  int laneByteOffset;
  int maxLaneAbs;
  uint laneSignMask;
  int countdown;
  
  countdown = 4;
  maxLaneAbs = 0;
  laneByteOffset = 0;
  do {
    laneWord = *(uint *)(laneByteOffset + key + 0x20);
    laneSignMask = (int)laneWord >> 0x1f;
    laneAbs = (laneSignMask ^ laneWord) - laneSignMask;
    if (maxLaneAbs < laneAbs) {
      maxLaneAbs = laneAbs;
    }
    laneByteOffset = laneByteOffset + 4;
    countdown = countdown + -1;
  } while (countdown != 0);
  return maxLaneAbs % 0x65;
}

/* Compiler__nextValueNumber @ 0x172ed4 (20 bytes) */
int Compiler__nextValueNumber(compiler)
  int compiler;
{
  int valueNumber;
  
  valueNumber = *(int *)(compiler + 0x3c8) + 1;
  *(int *)(compiler + 0x3c8) = valueNumber;
  return valueNumber;
}

/* Compiler__nextNegativeValueNumber @ 0x172ee8 (20 bytes) */
int Compiler__nextNegativeValueNumber(compiler)
  int compiler;
{
  int valueNumber;

  valueNumber = *(int *)(compiler + 0x3cc) + -1;
  *(int *)(compiler + 0x3cc) = valueNumber;
  return valueNumber;
}

/* Compiler__peekValueNumber @ 0x172efc (8 bytes) */
int Compiler__peekValueNumber(compiler)
  int compiler;
{
  return *(undefined4 *)(compiler + 0x3c8);
}

/* Compiler__resetValueNumbers @ 0x172f0c (20 bytes) */
int Compiler__resetValueNumbers(compiler)
  int compiler;
{
  *(undefined4 *)(compiler + 0x3cc) = 0xfffffffe;
  *(undefined4 *)(compiler + 0x3c8) = 4;
  return;
}

/* returnZero_172f24 @ 0x172f24 (8 bytes) */
int returnZero_172f24()
{
  return 0;
}

/* ValueKey__initResultLaneValues @ 0x172f34 (124 bytes) */
int ValueKey__initResultLaneValues(key)
  int key;
{
  bool moreComponents;
  char laneKind;
  int operandRecord;
  int loopIndex;
  int laneCursor;
  
  loopIndex = 0;
  laneCursor = key;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),0);
    laneKind = *(char *)(loopIndex + operandRecord + 0x10);
    if (laneKind == '\0') {
      *(undefined4 *)(laneCursor + 0x20) = *(undefined4 *)(laneCursor + 0x178);
    }
    else if (laneKind == '\x01') {
      *(undefined4 *)(laneCursor + 0x20) = *(undefined4 *)(laneCursor + 0x10);
    }
    moreComponents = loopIndex != 3;
    laneCursor = laneCursor + 4;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  return;
}

/* noop_172fb0 @ 0x172fb0 (4 bytes) */
int noop_172fb0()
{
  return;
}

/* noop_172fb4 @ 0x172fb4 (4 bytes) */
int noop_172fb4()
{
  return;
}

/* FUN_00172fb8 @ 0x172fb8 (96 bytes) */
int FUN_00172fb8(valueKey)
  int valueKey;
{
  int vcall54Result;
  undefined4 result;
  
  vcall54Result = (**(code **)(**(int **)(valueKey + 0xb0) + 0x54))(*(int **)(valueKey + 0xb0));
  if ((vcall54Result == 0) || (result = 1, *(int *)(*(int *)(valueKey + 0xb0) + 0xb0) != 0x2a)) {
    result = 0;
  }
  return result;
}

/* FUN_00173018 @ 0x173018 (332 bytes) */
int FUN_00173018(ctx)
  int ctx;
{
  int operandRecord;
  int *keyPtr;
  undefined4 laneMapValue;
  char firstEqualLane;
  int innerKeyCursor;
  int lanesLeft;
  int producerInst;
  undefined4 inst;
  int loopIndex;
  int programStats;
  int outerKeyCursor;
  int innerCountdown;
  undefined4 laneMapWord;
  
  laneMapWord = DAT_001b01bc;
  loopIndex = 1;
  programStats = *(int *)(*(int *)(ctx + 0x238) + 0x6c4);
  *(int *)(programStats + 0xa8) = *(int *)(programStats + 0xa8) + 1;
  outerKeyCursor = ctx;
  do {
    if (*(int *)(ctx + 0x20) == *(int *)(outerKeyCursor + 0x24)) {
      firstEqualLane = '\0';
    }
    else {
      firstEqualLane = '\0';
      innerKeyCursor = ctx;
      innerCountdown = loopIndex;
      do {
        firstEqualLane = firstEqualLane + '\x01';
        innerCountdown = innerCountdown + -1;
        if (innerCountdown == 0) goto LAB_001730b4;
        keyPtr = (int *)(innerKeyCursor + 0x24);
        innerKeyCursor = innerKeyCursor + 4;
      } while (*keyPtr != *(int *)(outerKeyCursor + 0x24));
    }
    producerInst = *(int *)(ctx + 0xb0);
    *(char *)((int)&laneMapWord + loopIndex) = firstEqualLane;
    *(undefined1 *)(loopIndex + producerInst + 0x9c) = 1;
LAB_001730b4:
    lanesLeft = 4 - loopIndex;
    do {
      loopIndex = loopIndex + 1;
      outerKeyCursor = outerKeyCursor + 4;
      lanesLeft = lanesLeft + -1;
      if (lanesLeft == 0) {
        inst = IRMov__new_1084b8(0x31,*(undefined4 *)(ctx + 0x238));
        IRInst__setOperandRef(inst,0,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
        IRInst__setOperandRef(inst,1,*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x8c));
        laneMapValue = laneMapWord;
        operandRecord = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord + 0x10) = laneMapValue;
        Block__insertInstAfter(*(undefined4 *)(*(int *)(ctx + 0xb0) + 0x158),*(int *)(ctx + 0xb0),
                     inst);
        IRInst__bindOperandRegisters(*(undefined4 *)(*(int *)(ctx + 0x238) + 0x6c4),inst);
        return 1;
      }
    } while (loopIndex < 1);
  } while( true );
}

/* ValueKey__computeSwizzleTo @ 0x173164 (196 bytes) */
int ValueKey__computeSwizzleTo(out, key, otherKey)
  undefined4 *out;
  int key;
  int otherKey;
{
  int operandRecord;
  bool moreComponents;
  int loopIndex;
  int loopIndexB;
  int *laneCursor;
  int countdown;
  undefined4 swizzleWord [6];
  
  loopIndexB = 0;
  laneCursor = (int *)(key + 0x20);
  swizzleWord[0] = DAT_001b01b8;
  do {
    operandRecord = IRInst__getOperandRecord(*(undefined4 *)(key + 0xb0),0);
    if (*(char *)(loopIndexB + operandRecord + 0x10) != '\x01') {
      countdown = 4;
      loopIndex = 0;
      while (*(int *)(otherKey + 0x20 + loopIndex * 4) != *laneCursor) {
        loopIndex = loopIndex + 1;
        countdown = countdown + -1;
        if (countdown == 0) {
          *out = DAT_001b01b8;
          return out;
        }
      }
      *(char *)((int)swizzleWord + loopIndexB) = (char)loopIndex;
    }
    moreComponents = loopIndexB != 3;
    laneCursor = laneCursor + 1;
    loopIndexB = loopIndexB + 1;
  } while (moreComponents);
  *out = swizzleWord[0];
  return out;
}

/* SwizzleTable__eqKeys @ 0x173228 (80 bytes) */
int SwizzleTable__eqKeys(keyA, keyB)
  undefined4 keyA;
  undefined4 keyB;
{
  int swizzleOut [5];
  
  ((int (*)())ValueKey__computeSwizzleTo)(swizzleOut,keyB,keyA);
  return -(uint)(swizzleOut[0] == DAT_001b01b8);
}

/* ValueKey__propagateLaneValues @ 0x173278 (184 bytes) */
int ValueKey__propagateLaneValues(key)
  undefined4 *key;
{
  bool moreComponents;
  char laneKind;
  int operandRecord;
  int loopIndex;
  undefined4 *laneCursor;
  
  loopIndex = 0;
  laneCursor = key;
  do {
    operandRecord = IRInst__getOperandRecord(key[0x2c],0);
    laneKind = *(char *)(loopIndex + operandRecord + 0x10);
    if (laneKind == '\0') {
      laneCursor[8] = *laneCursor;
      laneCursor[0x1c] = laneCursor[0x14];
      laneCursor[0x28] = laneCursor[0x20];
    }
    else if (laneKind == '\x01') {
      if ((*(uint *)(key[0x2c] + 0x14) & 0x200) == 0) {
        laneCursor[8] = 2;
      }
      else {
        laneCursor[8] = laneCursor[4];
        laneCursor[0x1c] = laneCursor[0x18];
        laneCursor[0x28] = laneCursor[0x24];
      }
    }
    moreComponents = loopIndex != 3;
    laneCursor = laneCursor + 1;
    loopIndex = loopIndex + 1;
  } while (moreComponents);
  return;
}

/* Compiler__findInPtrSet @ 0x173330 (48 bytes) */
int Compiler__findInPtrSet(compiler, pointer)
  int compiler;
  undefined4 pointer;
{
  undefined4 callResult;
  
  **(undefined4 **)(compiler + 0x3f4) = pointer;
  callResult = HashTable__find(*(undefined4 *)(compiler + 1000),*(undefined4 *)(compiler + 0x3f4));
  return callResult;
}

/* Compiler__exprRecordForValueNumber @ 0x173360 (64 bytes) */
int Compiler__exprRecordForValueNumber(compiler, valueNumber)
  int compiler;
  undefined4 valueNumber;
{
  undefined4 callResult;
  
  *(undefined4 *)(*(int *)(compiler + 0x3f0) + 4) = valueNumber;
  **(undefined4 **)(compiler + 0x3f0) = 0x7ffffffe;
  callResult = HashTable__find(*(undefined4 *)(compiler + 0x3e0),*(undefined4 *)(compiler + 0x3f0));
  return callResult;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl ResourceModel__vslot23");
asm(".set ResourceModel__vslot23, _ResourceModel__vslot23");
asm(".globl ResourceModel__vslot24");
asm(".set ResourceModel__vslot24, _ResourceModel__vslot24");
asm(".globl ResourceModel__vslot25");
asm(".set ResourceModel__vslot25, _ResourceModel__vslot25");
asm(".globl ResourceModel__vslot29");
asm(".set ResourceModel__vslot29, _ResourceModel__vslot29");
asm(".globl ResourceModel__vslot22");
asm(".set ResourceModel__vslot22, _ResourceModel__vslot22");
asm(".globl ResourceModel__vslot32");
asm(".set ResourceModel__vslot32, _ResourceModel__vslot32");
asm(".globl ResourceModel__vslot11");
asm(".set ResourceModel__vslot11, _ResourceModel__vslot11");
asm(".globl ThreadModel__vslot4");
asm(".set ThreadModel__vslot4, _ThreadModel__vslot4");
asm(".globl ExprRecordTable__hashByValueNumber");
asm(".set ExprRecordTable__hashByValueNumber, _ExprRecordTable__hashByValueNumber");
asm(".globl ExprRecordTable__eqByValueNumber");
asm(".set ExprRecordTable__eqByValueNumber, _ExprRecordTable__eqByValueNumber");
asm(".globl ExprRecordTable__hashByExpr");
asm(".set ExprRecordTable__hashByExpr, _ExprRecordTable__hashByExpr");
asm(".globl ExprRecordTable__eqByExpr");
asm(".set ExprRecordTable__eqByExpr, _ExprRecordTable__eqByExpr");
asm(".globl PtrSet__hashPtr");
asm(".set PtrSet__hashPtr, _PtrSet__hashPtr");
asm(".globl PtrSet__eqNonNullPtr");
asm(".set PtrSet__eqNonNullPtr, _PtrSet__eqNonNullPtr");
asm(".globl KeyLaneTable__hashByOpcode");
asm(".set KeyLaneTable__hashByOpcode, _KeyLaneTable__hashByOpcode");
asm(".globl KeyLaneTable__eqKeys");
asm(".set KeyLaneTable__eqKeys, _KeyLaneTable__eqKeys");
asm(".globl ScopedExprTable__hashKey");
asm(".set ScopedExprTable__hashKey, _ScopedExprTable__hashKey");
asm(".globl ScopedExprTable__eqKeys");
asm(".set ScopedExprTable__eqKeys, _ScopedExprTable__eqKeys");
asm(".globl returnZero_172dfc");
asm(".set returnZero_172dfc, _returnZero_172dfc");
asm(".globl LaneMatchTable__eqKeys");
asm(".set LaneMatchTable__eqKeys, _LaneMatchTable__eqKeys");
asm(".globl SwizzleTable__hashKey");
asm(".set SwizzleTable__hashKey, _SwizzleTable__hashKey");
asm(".globl SwizzleTable__eqKeys");
asm(".set SwizzleTable__eqKeys, _SwizzleTable__eqKeys");
