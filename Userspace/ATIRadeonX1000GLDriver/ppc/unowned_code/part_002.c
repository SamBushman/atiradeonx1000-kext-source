#include "decls.h"

/* Block__isIfHeader @ 0x1cdc24 (8 bytes) */
int Block__isIfHeader()
{
  return 0;
}

/* Block__isIfFooter @ 0x1cdc2c (8 bytes) */
int Block__isIfFooter()
{
  return 0;
}

/* Block__isLoopHeader @ 0x1cdc34 (8 bytes) */
int Block__isLoopHeader()
{
  return 0;
}

/* Block__isLoopFooter @ 0x1cdc3c (8 bytes) */
int Block__isLoopFooter()
{
  return 0;
}

/* Block__isPostLoopFooter @ 0x1cdc44 (8 bytes) */
int Block__isPostLoopFooter()
{
  return 0;
}

/* Block__isBreak @ 0x1cdc4c (8 bytes) */
int Block__isBreak()
{
  return 0;
}

/* Block__isContinue @ 0x1cdc54 (8 bytes) */
int Block__isContinue()
{
  return 0;
}

/* Block__isStatic @ 0x1cdc5c (8 bytes) */
int Block__isStatic()
{
  return 0;
}

/* EntryBlock__isEntry @ 0x1cdc80 (8 bytes) */
int EntryBlock__isEntry()
{
  return 1;
}

/* AnyBlock__isAny @ 0x1cdca4 (8 bytes) */
int AnyBlock__isAny()
{
  return 1;
}

/* ExitBlock__isExit @ 0x1cdcc8 (8 bytes) */
int ExitBlock__isExit()
{
  return 1;
}

/* LoopHeader__isLoopHeader @ 0x1cdcec (8 bytes) */
int LoopHeader__isLoopHeader()
{
  return 1;
}

/* LoopFooter__isLoopFooter @ 0x1cdcf4 (8 bytes) */
int LoopFooter__isLoopFooter()
{
  return 1;
}

/* PostLoopFooter__isPostLoopFooter @ 0x1cdd18 (8 bytes) */
int PostLoopFooter__isPostLoopFooter()
{
  return 1;
}

/* IfHeader__isIfHeader @ 0x1cdd3c (8 bytes) */
int IfHeader__isIfHeader()
{
  return 1;
}

/* IfHeaderStatic__isStatic @ 0x1cdd7c (8 bytes) */
int IfHeaderStatic__isStatic()
{
  return 1;
}

/* IfFooter__isIfFooter @ 0x1cdda0 (8 bytes) */
int IfFooter__isIfFooter()
{
  return 1;
}

/* IfFooterStatic__isStatic @ 0x1cddc4 (8 bytes) */
int IfFooterStatic__isStatic()
{
  return 1;
}

/* BreakBlock__isBreak @ 0x1cdde8 (8 bytes) */
int BreakBlock__isBreak()
{
  return 1;
}

/* ContinueBlock__isContinue @ 0x1cde0c (8 bytes) */
int ContinueBlock__isContinue()
{
  return 1;
}

/* FuncEndBlock__isFuncEnd @ 0x1cde14 (4 bytes) */
int FuncEndBlock__isFuncEnd()
{
  return;
}

/* IRInst__accept @ 0x1ce61c (116 bytes) */
int IRInst__accept(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 4);
  if (iVar1 == 7) {
                    
                    
    (**(code **)(*param_2 + 0x50))(param_2,param_1);
    return;
  }
  if (iVar1 != 9) {
    if (iVar1 != 6) {
      return;
    }
                    
                    
    (**(code **)(*param_2 + 0x4c))(param_2,param_1);
    return;
  }
                    
                    
  (**(code **)(*param_2 + 0x38))(param_2,param_1);
  return;
}

/* orph_1ce648 @ 0x1ce648 (24 bytes) */
int orph_1ce648(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  undefined4 in_r9;
  
                    
                    
  (**(code **)(*param_2 + 0x38))(param_1,in_r9);
  return;
}

/* orph_1ce660 @ 0x1ce660 (24 bytes) */
int orph_1ce660(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  undefined4 in_r9;
  
                    
                    
  (**(code **)(*param_2 + 0x50))(param_1,in_r9);
  return;
}

/* orph_1ce678 @ 0x1ce678 (24 bytes) */
int orph_1ce678(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  undefined4 in_r9;
  
                    
                    
  (**(code **)(*param_2 + 0x4c))(param_1,in_r9);
  return;
}

/* IRInst__getKindName @ 0x1ce690 (28 bytes) */
int IRInst__getKindName()
{
  return "unknown";
}

/* IREntry__isEntry @ 0x1ce6ac (8 bytes) */
int IREntry__isEntry()
{
  return 1;
}

/* IRExit__isExit @ 0x1ce6d0 (8 bytes) */
int IRExit__isExit()
{
  return 1;
}

/* IRLoad__isLoad @ 0x1ce6f4 (8 bytes) */
int IRLoad__isLoad()
{
  return 1;
}

/* IRLoadConst__isLoadConst @ 0x1ce76c (8 bytes) */
int IRLoadConst__isLoadConst()
{
  return 1;
}

/* IRLoadTemp__isLoadTemp @ 0x1ce790 (8 bytes) */
int IRLoadTemp__isLoadTemp()
{
  return 1;
}

/* IRLoadInterp__isLoadInterp @ 0x1ce7d0 (8 bytes) */
int IRLoadInterp__isLoadInterp()
{
  return 1;
}

/* IRLoadInterp__vslot32 @ 0x1ce7f4 (4 bytes) */
int IRLoadInterp__vslot32()
{
  return;
}

/* IRUndefined__isUndefined @ 0x1ce7f8 (8 bytes) */
int IRUndefined__isUndefined()
{
  return 1;
}

/* IRMerge__isMerge @ 0x1ce838 (8 bytes) */
int IRMerge__isMerge()
{
  return 1;
}

/* IRMerge__getNumDests @ 0x1ce840 (8 bytes) */
int IRMerge__getNumDests()
{
  return 1;
}

/* IRMerge__getNumSources @ 0x1ce848 (8 bytes) */
int IRMerge__getNumSources(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x84);
}

/* IRProjection__getNumDests @ 0x1ce850 (8 bytes) */
int IRProjection__getNumDests()
{
  return 1;
}

/* IRProjection__getNumSources @ 0x1ce858 (8 bytes) */
int IRProjection__getNumSources()
{
  return 1;
}

/* IRProjection__isProjection @ 0x1ce87c (8 bytes) */
int IRProjection__isProjection()
{
  return 1;
}

/* IRPresub1__getNumDests @ 0x1ce884 (8 bytes) */
int IRPresub1__getNumDests()
{
  return 1;
}

/* IRPresub1__getNumSources @ 0x1ce88c (8 bytes) */
int IRPresub1__getNumSources()
{
  return 1;
}

/* IRPresub1__isPresub @ 0x1ce8b0 (8 bytes) */
int IRPresub1__isPresub()
{
  return 1;
}

/* IRPresub1__vslot33 @ 0x1ce8b8 (4 bytes) */
int IRPresub1__vslot33()
{
  return;
}

/* IRPresub1__appendSource @ 0x1ce8bc (4 bytes) */
int IRPresub1__appendSource()
{
  return;
}

/* IRPresub1__vslot37 @ 0x1ce8c0 (8 bytes) */
int IRPresub1__vslot37()
{
  return 0;
}

/* IRPresub2__getNumDests @ 0x1ce8c8 (8 bytes) */
int IRPresub2__getNumDests()
{
  return 1;
}

/* IRPresub2__getNumSources @ 0x1ce8d0 (8 bytes) */
int IRPresub2__getNumSources()
{
  return 2;
}

/* IRPresub2__isPresub @ 0x1ce8f4 (8 bytes) */
int IRPresub2__isPresub()
{
  return 1;
}

/* IRPresub2__vslot33 @ 0x1ce8fc (4 bytes) */
int IRPresub2__vslot33()
{
  return;
}

/* IRPresub2__appendSource @ 0x1ce900 (4 bytes) */
int IRPresub2__appendSource()
{
  return;
}

/* IRPresub2__vslot37 @ 0x1ce904 (8 bytes) */
int IRPresub2__vslot37()
{
  return 0;
}

/* IRMix__getNumDests @ 0x1ce90c (8 bytes) */
int IRMix__getNumDests()
{
  return 1;
}

/* IRMix__getNumSources @ 0x1ce914 (8 bytes) */
int IRMix__getNumSources(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x84);
}

/* IRMix__isMix @ 0x1ce938 (8 bytes) */
int IRMix__isMix()
{
  return 1;
}

/* IRMix__vslot33 @ 0x1ce940 (4 bytes) */
int IRMix__vslot33()
{
  return;
}

/* IRMix__appendSource @ 0x1ce944 (4 bytes) */
int IRMix__appendSource()
{
  return;
}

/* IRMix__vslot37 @ 0x1ce948 (8 bytes) */
int IRMix__vslot37()
{
  return 0;
}

/* IRMix__vslot35 @ 0x1ce950 (8 bytes) */
int IRMix__vslot35()
{
  return 0;
}

/* IRPhiNode__isPhi @ 0x1ce958 (4 bytes) */
int IRPhiNode__isPhi()
{
  return;
}

