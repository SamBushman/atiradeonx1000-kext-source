#include "decls.h"

/* BreakBlock__accept @ 0xe29bc (36 bytes) */
int BreakBlock__accept(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x80))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* ContinueBlock__accept @ 0xe29e0 (36 bytes) */
int ContinueBlock__accept(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x84))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e7650 @ 0xe7650 (8 bytes) */
int orph_e7650(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2[2];
  iVar1 = *param_2;
  *(int *)(iVar2 + 4) = param_2[1];
  *(int *)(param_2[1] + 8) = iVar2;
                    
                    
  (**(code **)(iVar1 + 4))();
  return;
}

/* orph_ec1e4 @ 0xec1e4 (8 bytes) */
int orph_ec1e4()
{
  return 0;
}

/* IRLoadConst__removeFromList @ 0x10451c (32 bytes) */
int IRLoadConst__removeFromList(param_1, param_2)
  int *param_1;
  int param_2;
{
                    
                    
  (**(code **)(*param_1 + 0xc))
            (param_1,*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) >> 7 & 1,param_2);
  return;
}

/* HwLimits__vslot19 @ 0x10dcfc (12 bytes) */
int HwLimits__vslot19(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  Compiler__fail(*(undefined4 *)(param_2 + 8),0xf);
  return;
}

/* KhanVs__vslot16 @ 0x10ddf4 (8 bytes) */
int KhanVs__vslot16()
{
  return 0xb5;
}

/* KhanPs__vslot86 @ 0x12841c (20 bytes) */
int KhanPs__vslot86(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  Emitter__allocateConstantSlot(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3ac),param_3,param_4,param_4,param_5,
               param_6,param_7);
  return;
}

/* KhanVs__vslot78 @ 0x129400 (8 bytes) */
int KhanVs__vslot78()
{
  return 0x20;
}

/* KhanVs__vslot86 @ 0x129ea0 (20 bytes) */
int KhanVs__vslot86(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  Emitter__allocateConstantSlot(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3ac),param_3,param_4,param_4,param_5,
               param_6,param_7);
  return;
}

/* KhanPs__vslot69 @ 0x12ab70 (8 bytes) */
int KhanPs__vslot69(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  IfHeader__armsAreSimple(param_2);
  return;
}

/* KhanVs__vslot69 @ 0x12ab78 (8 bytes) */
int KhanVs__vslot69(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  IfHeader__armsAreSimple(param_2);
  return;
}

/* KhanVs__flattenIfs @ 0x12dd48 (8 bytes) */
int KhanVs__flattenIfs(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  pass_flatten_ifs(param_2);
  return;
}

/* KhanPs__flattenIfs @ 0x12dd50 (8 bytes) */
int KhanPs__flattenIfs(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  pass_flatten_ifs(param_2);
  return;
}

/* orph_176e0c @ 0x176e0c (20 bytes) */
int orph_176e0c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x238);
  if ((((param_2 < 1) || (param_3 < 1)) || (iVar2 = Compiler__findInPtrSet(uVar1,param_2), iVar2 == 0)) ||
     ((iVar3 = Compiler__findInPtrSet(uVar1,param_3), iVar3 == 0 ||
      (((*(int *)(iVar2 + 0x20) == 0 || (param_3 != *(int *)(iVar2 + 0x24))) &&
       ((*(int *)(iVar3 + 0x20) == 0 || (param_2 != *(int *)(iVar3 + 0x24))))))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/* KhanPs__vslot67 @ 0x187588 (32 bytes) */
int KhanPs__vslot67(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  Inst__foldSourceProducerIntoConsumer(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FudoPs__vslot78 @ 0x191708 (8 bytes) */
int FudoPs__vslot78()
{
  return 0x80;
}

/* orph_193bd0 @ 0x193bd0 (24 bytes) */
int orph_193bd0(param_1)
  int *param_1;
{
  int iVar1;
  void *pvVar2;
  
  if ((void *)param_1[5] == (void *)0x0) {
    return;
  }
  iVar1 = *(int *)(*param_1 + 0x370);
  if ((*(int *)(iVar1 + 0x28) != 0) &&
     (pvVar2 = *(void **)(iVar1 + 0x14), pvVar2 == (void *)param_1[5])) {
    _memset(pvVar2,0,*(int *)(iVar1 + 8) - (int)pvVar2);
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0x14);
  }
  return;
}

/* R300MachineAssembler__visitIfHeader @ 0x1961b0 (24 bytes) */
int R300MachineAssembler__visitIfHeader(param_1)
  int param_1;
{
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x6c4) == 0) {
    return;
  }
  Compiler__fail(*(int *)(param_1 + 0xc),0xf);
  return;
}

/* R300VMachineAssembler__visitPostLoopFooter @ 0x19aad8 (28 bytes) */
int R300VMachineAssembler__visitPostLoopFooter(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
                    
                    
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  return;
}

/* MachineAssembler__deleting_dtor @ 0x1cd664 (56 bytes) */
int MachineAssembler__deleting_dtor(param_1)
  undefined4 *param_1;
{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_001e9a40;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  iVar2 = param_1[-1];
  if ((*(int *)(iVar2 + 0x28) != 0) &&
     (puVar1 = *(undefined4 **)(iVar2 + 0x14), puVar1 == param_1 + -1)) {
    _memset(puVar1,0,*(int *)(iVar2 + 8) - (int)puVar1);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0x14);
  }
  return;
}

/* MachineAssembler__visitMemLoad @ 0x1cd69c (4 bytes) */
int MachineAssembler__visitMemLoad()
{
  return;
}

/* MachineAssembler__visitMemStore @ 0x1cd6a0 (4 bytes) */
int MachineAssembler__visitMemStore()
{
  return;
}

/* MachineAssembler__visitGeomExport @ 0x1cd6a4 (4 bytes) */
int MachineAssembler__visitGeomExport()
{
  return;
}

/* IRInst__getNumDests @ 0x1cd6a8 (8 bytes) */
int IRInst__getNumDests(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x80);
}

/* IRInst__acceptCallPseudo @ 0x1cd6b0 (4 bytes) */
int IRInst__acceptCallPseudo()
{
  return;
}

/* IRInst__isAlu @ 0x1cd6b4 (44 bytes) */
int IRInst__isAlu(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 4);
  if (((iVar1 != 6) && (iVar1 != 7)) && (iVar1 != 8)) {
    return 0;
  }
  return 1;
}

/* IRInst__isFetch @ 0x1cd6e0 (8 bytes) */
int IRInst__isFetch()
{
  return 0;
}

/* IRInst__isVertexFetch @ 0x1cd6e8 (8 bytes) */
int IRInst__isVertexFetch()
{
  return 0;
}

/* IRInst__isTextureFetch @ 0x1cd6f0 (8 bytes) */
int IRInst__isTextureFetch()
{
  return 0;
}

/* IRInst__isEntry @ 0x1cd6f8 (8 bytes) */
int IRInst__isEntry()
{
  return 0;
}

/* IRInst__isExit @ 0x1cd700 (8 bytes) */
int IRInst__isExit()
{
  return 0;
}

/* IRInst__isLoopStart @ 0x1cd708 (24 bytes) */
int IRInst__isLoopStart(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0x88) + 4) == 4;
}

/* IRInst__isLoad @ 0x1cd720 (8 bytes) */
int IRInst__isLoad()
{
  return 0;
}

/* IRInst__isLoadTemp @ 0x1cd728 (8 bytes) */
int IRInst__isLoadTemp()
{
  return 0;
}

/* IRInst__isLoadConst @ 0x1cd730 (8 bytes) */
int IRInst__isLoadConst()
{
  return 0;
}

/* IRInst__isLoadInterp @ 0x1cd738 (8 bytes) */
int IRInst__isLoadInterp()
{
  return 0;
}

/* IRInst__isUndefined @ 0x1cd740 (8 bytes) */
int IRInst__isUndefined()
{
  return 0;
}

/* IRInst__isProjection @ 0x1cd748 (8 bytes) */
int IRInst__isProjection()
{
  return 0;
}

/* IRInst__isMerge @ 0x1cd750 (8 bytes) */
int IRInst__isMerge()
{
  return 0;
}

/* IRInst__isPresub @ 0x1cd758 (8 bytes) */
int IRInst__isPresub()
{
  return 0;
}

/* IRInst__isMix @ 0x1cd760 (8 bytes) */
int IRInst__isMix()
{
  return 0;
}

/* IRInst__isMov @ 0x1cd768 (8 bytes) */
int IRInst__isMov()
{
  return 0;
}

/* IRInst__isExport @ 0x1cd770 (8 bytes) */
int IRInst__isExport()
{
  return 0;
}

/* IRInst__isGeomExport @ 0x1cd778 (8 bytes) */
int IRInst__isGeomExport()
{
  return 0;
}

/* IRInst__isMemLoad @ 0x1cd780 (8 bytes) */
int IRInst__isMemLoad()
{
  return 0;
}

/* IRInst__isMemStore @ 0x1cd788 (8 bytes) */
int IRInst__isMemStore()
{
  return 0;
}

/* IRInst__isPhi @ 0x1cd790 (8 bytes) */
int IRInst__isPhi()
{
  return 0;
}

/* IRInst__vslot32 @ 0x1cd798 (8 bytes) */
int IRInst__vslot32()
{
  return 0;
}

/* IRInst__vslot33_setPredicateKind @ 0x1cd7a0 (8 bytes) */
int IRInst__vslot33_setPredicateKind(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x11c) = param_2;
  return;
}

/* IRInst__vslot35_allowsSourceNegate @ 0x1cd7a8 (8 bytes) */
int IRInst__vslot35_allowsSourceNegate()
{
  return 1;
}

/* IRPseudo__getNumSources @ 0x1cd7b0 (8 bytes) */
int IRPseudo__getNumSources()
{
  return 0;
}

/* IRPseudo__accept @ 0x1cd7b8 (4 bytes) */
int IRPseudo__accept()
{
  return;
}

/* IRInst__vslot34_setSourceSelect @ 0x1cd7d8 (20 bytes) */
int IRInst__vslot34_setSourceSelect(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  *(undefined1 *)(param_2 * 0x18 + param_1 + param_3 + 0x9c) = param_4;
  return;
}

/* Block__insertInstruction @ 0x1cdbf8 (4 bytes) */
int Block__insertInstruction()
{
  return;
}

/* Block__isFuncEnd @ 0x1cdbfc (8 bytes) */
int Block__isFuncEnd()
{
  return 0;
}

/* Block__isAny @ 0x1cdc04 (8 bytes) */
int Block__isAny()
{
  return 0;
}

/* Block__isMirror @ 0x1cdc0c (8 bytes) */
int Block__isMirror()
{
  return 0;
}

/* Block__isEntry @ 0x1cdc14 (8 bytes) */
int Block__isEntry()
{
  return 0;
}

/* Block__isExit @ 0x1cdc1c (8 bytes) */
int Block__isExit()
{
  return 0;
}

