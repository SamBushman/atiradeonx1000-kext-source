#include "decls.h"

/* TPoolAllocator___TPoolAllocator @ 0x97ba0054 (8 bytes) */
int TPoolAllocator___TPoolAllocator(this)
  unsigned char *this;
{
  ~TPoolAllocator(this);
  return;
}

/* TPoolAllocator___TPoolAllocator_97ba005c @ 0x97ba005c (8 bytes) */
int TPoolAllocator___TPoolAllocator_97ba005c(this)
  unsigned char *this;
{
  ~TPoolAllocator(this);
  return;
}

/* TPoolAllocator___TPoolAllocator_97ba0064 @ 0x97ba0064 (184 bytes) */
int TPoolAllocator___TPoolAllocator_97ba0064(this)
  unsigned char *this;
{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  
  if (*(int *)this == 0) {
    puVar1 = *(void **)(this + 0x1c);
    while (puVar1 != (void *)0x0) {
      pvVar3 = (void *)*puVar1;
      operator_delete__(puVar1);
      *(void **)(this + 0x1c) = pvVar3;
      puVar1 = pvVar3;
    }
  }
  puVar1 = *(void **)(this + 0x18);
  while (puVar1 != (void *)0x0) {
    pvVar3 = (void *)*puVar1;
    operator_delete__(puVar1);
    *(void **)(this + 0x18) = pvVar3;
    puVar1 = pvVar3;
  }
  for (iVar2 = *(int *)(this + 0x20); iVar2 != *(int *)(this + 0x24); iVar2 = iVar2 + 8) {
  }
  iVar2 = *(int *)(this + 0x28) - (int)*(void **)(this + 0x20) >> 3;
  if (iVar2 != 0) {
    std____default_alloc_template_true_0___deallocate(*(void **)(this + 0x20),iVar2 << 3);
  }
  return;
}

/* TAllocation__checkGuardBlock @ 0x97ba011c (4 bytes) */
int TAllocation__checkGuardBlock(param_1, param_2, param_3)
  uchar *param_1;
  int param_2;
  char *param_3;
{
  return;
}

/* TPoolAllocator__push @ 0x97ba0120 (136 bytes) */
int TPoolAllocator__push(this)
  unsigned char *this;
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_20;
  undefined4 local_1c;
  
  puVar1 = *(undefined4 **)(this + 0x24);
  local_30 = *(undefined4 *)(this + 0x14);
  local_2c = *(undefined4 *)(this + 0x1c);
  if (puVar1 == *(undefined4 **)(this + 0x28)) {
    local_20 = local_30;
    local_1c = local_2c;
    std::vector<TPoolAllocator::tAllocState,std::allocator<TPoolAllocator::tAllocState>>::
    _M_insert_aux(this + 0x20,*(undefined4 *)(this + 0x24),&local_30);
  }
  else {
    iVar2 = 0;
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = local_2c;
      *puVar1 = local_30;
      iVar2 = *(int *)(this + 0x24);
    }
    *(int *)(this + 0x24) = iVar2 + 8;
  }
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
  return;
}

/* TPoolAllocator__pop @ 0x97ba01a8 (160 bytes) */
int TPoolAllocator__pop(this)
  unsigned char *this;
{
  undefined4 *puVar1;
  void *pvVar2;
  void *pvVar3;
  
  if ((uint)(*(int *)(this + 0x24) - *(int *)(this + 0x20)) >> 3 != 0) {
    pvVar2 = *(void **)(*(int *)(this + 0x24) + -4);
    *(undefined4 *)(this + 0x14) = *(undefined4 *)(*(int *)(this + 0x24) + -8);
    puVar1 = *(void **)(this + 0x1c);
    while (puVar1 != pvVar2) {
      pvVar3 = (void *)*puVar1;
      if ((uint)puVar1[1] < 2) {
        *puVar1 = *(undefined4 *)(this + 0x18);
        *(undefined4 *)(this + 0x18) = *(undefined4 *)(this + 0x1c);
      }
      else {
        operator_delete__(puVar1);
      }
      *(void **)(this + 0x1c) = pvVar3;
      puVar1 = pvVar3;
    }
    *(int *)(this + 0x24) = *(int *)(this + 0x24) + -8;
  }
  return;
}

/* TPoolAllocator__popAll @ 0x97ba0248 (76 bytes) */
int TPoolAllocator__popAll(this)
  unsigned char *this;
{
  while ((uint)(*(int *)(this + 0x24) - *(int *)(this + 0x20)) >> 3 != 0) {
    pop(this);
  }
  return;
}

/* TPoolAllocator__allocate @ 0x97ba0294 (328 bytes) */
int TPoolAllocator__allocate(this, param_1)
  unsigned char *this;
  ulong param_1;
{
  float fVar1;
  undefined4 uVar2;
  ulong uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  ulong uVar8;
  
  fVar1 = TAllocation::guardBlockSize;
  iVar6 = *(int *)(this + 0x14);
  iVar7 = param_1 + (int)TAllocation::guardBlockSize * 2;
  uVar3 = *(ulong *)(this + 4);
  uVar5 = iVar6 + iVar7;
  *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + 1;
  *(ulong *)(this + 0x30) = *(int *)(this + 0x30) + param_1;
  if (uVar3 < uVar5) {
    uVar8 = iVar7 + *(int *)(this + 0x10);
    if (uVar3 < uVar8) {
      puVar4 = operator_new__(uVar8);
      iVar6 = 0;
      if (puVar4 != (undefined4 *)0x0) {
        uVar5 = *(uint *)(this + 4);
        *puVar4 = *(undefined4 *)(this + 0x1c);
        puVar4[1] = ((uVar8 + uVar5) - 1) / uVar5;
        iVar6 = (int)puVar4 + *(int *)(this + 0x10);
        *(undefined4 **)(this + 0x1c) = puVar4;
        *(undefined4 *)(this + 0x14) = *(undefined4 *)(this + 4);
      }
    }
    else {
      puVar4 = *(undefined4 **)(this + 0x18);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = operator_new__(uVar3);
        if (puVar4 == (undefined4 *)0x0) {
          return 0;
        }
      }
      else {
        *(undefined4 *)(this + 0x18) = *puVar4;
      }
      uVar2 = *(undefined4 *)(this + 0x1c);
      puVar4[1] = 1;
      *puVar4 = uVar2;
      iVar6 = (int)puVar4 + (int)TAllocation::guardBlockSize + *(int *)(this + 0x10);
      *(uint *)(this + 0x14) =
           *(int *)(this + 0x10) + iVar7 + *(uint *)(this + 0xc) & ~*(uint *)(this + 0xc);
      *(undefined4 **)(this + 0x1c) = puVar4;
    }
  }
  else {
    *(uint *)(this + 0x14) = uVar5 + *(uint *)(this + 0xc) & ~*(uint *)(this + 0xc);
    iVar6 = *(int *)(this + 0x1c) + iVar6 + (int)fVar1;
  }
  return iVar6;
}

/* TAllocation__checkAllocList @ 0x97ba03dc (156 bytes) */
int TAllocation__checkAllocList(this)
  unsigned char *this;
{
  byte bVar1;
  byte bVar2;
  float fVar3;
  undefined4 uVar4;
  
  fVar3 = guardBlockSize;
  bVar2 = guardBlockEndVal;
  bVar1 = guardBlockBeginVal;
  for (; this != (unsigned char *)0x0; this = *(TAllocation **)(this + 8)) {
    uVar4 = *(undefined4 *)(this + 4);
    ((int (*)())TAllocation__checkGuardBlock)((uchar *)this,(uchar)uVar4,(char *)(uint)bVar1);
    ((int (*)())TAllocation__checkGuardBlock)((uchar *)this,(uchar)uVar4 + SUB41(fVar3,0) + (char)*(undefined4 *)this,
                    (char *)(uint)bVar2);
  }
  return;
}

/* QualifierWritten @ 0x97ba0478 (156 bytes) */
int QualifierWritten(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_20 = 0;
  local_50 = DAT_a7b7ba24;
  local_40 = DAT_a7b7ba20;
  local_24 = 1;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 1;
  local_28 = 0;
  if (param_1 != (int *)0x0) {
    local_1c = param_2;
    (**(code **)(*param_1 + 8))(param_1,&local_50);
  }
  return local_20;
}

/* AliveSymbol @ 0x97ba0514 (76 bytes) */
int AliveSymbol(param_1, param_2)
  unsigned char *param_1;
  unsigned char *param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)param_1 + 0x44))();
  if (iVar1 == *(int *)(param_2 + 0x34)) {
    *(undefined4 *)(param_2 + 0x30) = 1;
  }
  return;
}

/* AliveSelection @ 0x97ba0560 (16 bytes) */
int AliveSelection(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  return *(int *)(param_3 + 0x30) == 0;
}

/* RemoveSymbol @ 0x97ba0570 (24 bytes) */
void ParseSymbolTable__RemoveSymbol(unsigned char *param_1,unsigned char *param_2)

{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)param_1 + 0x30))();
  return;
}

/* RemoveBinary @ 0x97ba0588 (56 bytes) */
int RemoveBinary(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  if (param_2 != (unsigned char *)0x0) {
    (**(code **)(*(int *)param_2 + 0x30))();
  }
  return 1;
}

/* RemoveUnary @ 0x97ba05c0 (56 bytes) */
int RemoveUnary(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  if (param_2 != (unsigned char *)0x0) {
    (**(code **)(*(int *)param_2 + 0x30))();
  }
  return 1;
}

/* RemoveAggregate @ 0x97ba05f8 (56 bytes) */
int RemoveAggregate(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  if (param_2 != (unsigned char *)0x0) {
    (**(code **)(*(int *)param_2 + 0x30))();
  }
  return 1;
}

/* RemoveSelection @ 0x97ba0630 (56 bytes) */
int RemoveSelection(param_1, param_2, param_3)
  int param_1;
  unsigned char *param_2;
  unsigned char *param_3;
{
  if (param_2 != (unsigned char *)0x0) {
    (**(code **)(*(int *)param_2 + 0x30))();
  }
  return 1;
}

/* RemoveConstantUnion @ 0x97ba0668 (24 bytes) */
int RemoveConstantUnion(param_1, param_2)
  unsigned char *param_1;
  unsigned char *param_2;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)param_1 + 0x30))();
  return;
}

/* RemoveAllTreeNodes @ 0x97ba0680 (168 bytes) */
int RemoveAllTreeNodes(param_1)
  unsigned char *param_1;
{
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_2c = DAT_a7b7ba3c;
  local_38 = DAT_a7b7ba38;
  local_3c = DAT_a7b7ba34;
  local_30 = DAT_a7b7ba30;
  local_18 = 1;
  local_40 = DAT_a7b7ba2c;
  local_34 = DAT_a7b7ba28;
  local_1c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_14 = 0;
  (**(code **)(*(int *)param_1 + 8))(param_1,&local_40);
  return;
}

/* GetSymbolTable @ 0x97ba0728 (132 bytes) */
int GetSymbolTable(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = &((int (*)())GetSymbolTable)(int)::SymbolTables;
  if (((int (*)())GetSymbolTable)(int)::SymbolTables == 0) {
    do {
      puVar2 = operator_new(0x10);
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[3] = 0;
      *puVar1 = puVar2;
      puVar1 = puVar1 + 1;
    } while ((int)puVar1 < -0x584817f7);
  }
  return (&((int (*)())GetSymbolTable)(int)::SymbolTables)[param_1];
}

/* GetResources @ 0x97ba07ac (108 bytes) */
int GetResources()
{
  DAT_a7b7e838 = 4;
  DAT_a7b7e810 = 6;
  DAT_a7b7e818 = 8;
  DAT_a7b7e824 = 0x20;
  DAT_a7b7e828 = 0;
  DAT_a7b7e830 = 0x10;
  DAT_a7b7e834 = 0x200;
  ((int (*)())GetResources)()::Resources = 8;
  DAT_a7b7e814 = 8;
  DAT_a7b7e81c = 0x10;
  DAT_a7b7e820 = 0x200;
  DAT_a7b7e82c = 0x10;
  return &((int (*)())GetResources)()::Resources;
}

/* _ShInitialize @ 0x97ba0818 (360 bytes) */
int _ShInitialize()
{
  int iVar1;
  int *piVar2;
  int iVar3;
  TPoolAllocator *pTVar4;
  TPoolAllocator *this;
  undefined4 uVar5;
  undefined4 uVar6;
  char in_RESERVE;
  byte in_cr0;
  undefined *local_40;
  undefined4 local_3c;
  undefined *local_38;
  undefined4 local_34;
  
  local_40 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar2 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar3 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar3;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_40 = local_40 + 0xc;
  local_3c = 4;
  do {
    if (in_RESERVE != '\0') {
      iVar3 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar3;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_34 = 4;
  local_38 = local_40;
  _pthread_mutex_lock((pthread_mutex_t *)&_glsl_allocator_lock);
  iVar3 = InitProcess();
  uVar6 = 1;
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else if (_PerProcessGPA == (unsigned char *)0x0) {
    pTVar4 = (unsigned char *)GetGlobalPoolAllocator();
    this = operator_new(0x34);
    TPoolAllocator__TPoolAllocator(this,true,0x2000,0x10);
    _PerProcessGPA = this;
    ((int (*)())TPoolAllocator__push)();
    SetGlobalPoolAllocatorPtr(_PerProcessGPA);
    uVar5 = ((int (*)())GetResources)();
    ((int (*)())generateBuiltInSymbolTable)(uVar5,&local_40,0,4);
    SetGlobalPoolAllocatorPtr(pTVar4);
  }
  _pthread_mutex_unlock((pthread_mutex_t *)&_glsl_allocator_lock);
  piVar2 = (int *)(local_38 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_38 + -0xc));
  }
  piVar2 = (int *)(local_40 + -4);
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_40 + -0xc));
  }
  return uVar6;
}

/* _ShConstructCompiler @ 0x97ba0980 (32 bytes) */
int _ShConstructCompiler()
{
  ConstructCompiler();
  return;
}

/* _ShDestruct @ 0x97ba09a4 (200 bytes) */
int _ShDestruct(param_1)
  int *param_1;
{
  int iVar1;
  TCompiler *pTVar2;
  TShHandleBase *pTVar3;
  
  if (param_1 != (int *)0x0) {
    _pthread_mutex_lock((pthread_mutex_t *)&_glsl_allocator_lock);
    iVar1 = (**(code **)(*param_1 + 8))(param_1);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1);
      if (iVar1 != 0) {
        pTVar3 = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1);
        DeleteLinker(pTVar3);
      }
    }
    else {
      pTVar2 = (unsigned char *)(**(code **)(*param_1 + 8))(param_1);
      DeleteCompiler(pTVar2);
    }
    _pthread_mutex_unlock((pthread_mutex_t *)&_glsl_allocator_lock);
    return;
  }
  return;
}

/* _ShFinalize @ 0x97ba0a6c (112 bytes) */
int _ShFinalize()
{
  TPoolAllocator *pTVar1;
  
  if (_PerProcessGPA != (unsigned char *)0x0) {
    ((int (*)())TPoolAllocator__popAll)();
    pTVar1 = _PerProcessGPA;
    if (_PerProcessGPA != (unsigned char *)0x0) {
      ((int (*)())TPoolAllocator___TPoolAllocator)(_PerProcessGPA);
      operator_delete(pTVar1);
    }
    _PerProcessGPA = (unsigned char *)0x0;
  }
  DetachProcess();
  return 1;
}

/* generateBuiltInSymbolTable @ 0x97ba0adc (112 bytes) */
int generateBuiltInSymbolTable(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  TBuiltInResource aTStack_30 [28];
  
  TBuiltIns__initialize(aTStack_30);
  ((int (*)())initializeSymbolTable)(aTStack_30,0,param_2,param_1,param_3);
  ((int (*)())initializeSymbolTable)(aTStack_30,1,param_2,param_1,param_3);
  return 1;
}

/* initializeSymbolTable @ 0x97ba0b4c (936 bytes) */
int initializeSymbolTable(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  ulong uVar5;
  ulong *puVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint uVar9;
  char **ppcVar10;
  uint uVar11;
  char in_RESERVE;
  byte in_cr0;
  byte bVar12;
  undefined4 *local_130;
  int *local_12c;
  undefined4 local_128;
  uint local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  ulong local_100;
  undefined4 *local_fc;
  int local_f8;
  undefined4 local_f0;
  undefined4 local_ec;
  ulong local_e8;
  undefined4 *local_e4;
  int local_e0;
  undefined4 local_d8;
  int local_d4;
  ulong local_c0;
  ulong local_b0;
  undefined4 local_a0;
  ulong local_90;
  ulong *local_80 [4];
  undefined4 local_70;
  undefined4 local_40 [7];
  
  local_40[0] = param_3;
  piVar4 = (int *)((int (*)())GetSymbolTable)(param_2);
  local_130 = local_40;
  local_120 = 0;
  local_11c = 0;
  local_118 = 0;
  local_114 = 0;
  local_110 = 0;
  local_10c = 0;
  local_12c = piVar4;
  local_128 = param_3;
  local_124 = param_2;
  local_100 = GetGlobalPoolAllocator();
  local_fc = (undefined4 *)0x0;
  local_c0 = local_100;
  local_fc = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_100);
  local_f8 = 0;
  *local_fc = 0;
  local_fc[1] = 0;
  local_fc[2] = local_fc;
  local_fc[3] = local_fc;
  local_f0 = 1;
  local_ec = 0;
  local_e8 = GetGlobalPoolAllocator();
  local_e4 = (undefined4 *)0x0;
  local_b0 = local_e8;
  local_e4 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_e8);
  local_e0 = 0;
  *local_e4 = 0;
  local_e4[1] = 0;
  local_d4 = DAT_a7b7ba70;
  local_e4[2] = local_e4;
  piVar2 = (int *)(local_d4 + 8);
  local_e4[3] = local_e4;
  do {
    if (in_RESERVE != '\0') {
      iVar3 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar3;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  local_d8 = GetGlobalPoolAllocator();
  local_d4 = local_d4 + 0xc;
  local_a0 = local_d8;
  setInitialState();
  iVar3 = piVar4[1] - *piVar4 >> 2;
  bVar12 = (iVar3 != 0) << 1;
  if ((iVar3 != 0) && (iVar3 != 1)) {
    ___eprintf("%s:%u: failed assertion `%s\'\n",
               "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/ShaderLang.cpp"
               ,0x110,"symbolTable->isEmpty() || symbolTable->atSharedBuiltInLevel()");
  }
  uVar5 = GetGlobalPoolAllocator();
  puVar6 = (ulong *)((int (*)())TPoolAllocator__allocate)(uVar5);
  local_90 = GetGlobalPoolAllocator();
  *puVar6 = local_90;
  puVar6[1] = 0;
  puVar7 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_90);
  puVar6[2] = 0;
  puVar6[1] = (ulong)puVar7;
  *puVar7 = 0;
  *(undefined4 *)(puVar6[1] + 4) = 0;
  *(ulong *)(puVar6[1] + 8) = puVar6[1];
  *(ulong *)(puVar6[1] + 0xc) = puVar6[1];
  piVar2 = (int *)piVar4[1];
  local_80[0] = puVar6;
  if (piVar2 == (int *)piVar4[2]) {
    std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
              (piVar4,piVar2,local_80);
  }
  else {
    iVar3 = 0;
    if (piVar2 != (int *)0x0) {
      *piVar2 = (int)puVar6;
      iVar3 = piVar4[1];
    }
    piVar4[1] = iVar3 + 4;
  }
  iVar3 = _InitPreprocessor();
  if (iVar3 != 0) {
                    
                    
    uVar8 = (*(code *)(((unsigned char *)0x97ba0d70) + (*(unsigned char *)0x97ba0d7c)))();
    return uVar8;
  }
  uVar9 = TBuiltIns__getNumStringArrays(param_1);
  uVar11 = 0;
  if (uVar9 != 0) {
    do {
      ppcVar10 = (char **)TBuiltIns__getStringArray(param_1,local_124);
      piVar2 = (int *)TBuiltIns__getStringSizeArray(param_1,local_124);
      iVar3 = TBuiltIns__getNumStrings(param_1,local_124);
      iVar3 = PaParseStrings(ppcVar10,piVar2,iVar3,0,(unsigned char *)&local_130);
      if (iVar3 != 0) {
                    
                    
        uVar8 = (*(code *)(((unsigned char *)0x97ba0eac) + (*(unsigned char *)0x97ba0eb8)))();
        return uVar8;
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 < uVar9);
  }
  IdentifyBuiltIns_97b8c5c0(local_124,piVar4,param_4);
  IdentifyBuiltIns_97b8c5c0(local_124,piVar4);
  _FinalizePreprocessor();
  piVar2 = (int *)(local_d4 + -4);
  local_70 = local_d8;
  do {
    iVar3 = *piVar2;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
      *piVar2 = iVar1;
      bVar12 = 2;
    }
  } while (!(bool)(bVar12 >> 1 & 1));
  if (iVar3 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(local_d4 + -0xc));
  }
  if (local_e0 != 0) {
    std::
    _Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
    ::_M_erase((unsigned char *)&local_e8);
    local_e4[2] = local_e4;
    local_e4[1] = 0;
    local_e4[3] = local_e4;
    local_e0 = 0;
  }
  if (local_f8 != 0) {
    std::
    _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
    ::_M_erase((unsigned char *)&local_100);
    local_fc[2] = local_fc;
    local_fc[1] = 0;
    local_fc[3] = local_fc;
  }
  return 1;
}

/* _ShCompile @ 0x97ba10c8 (1888 bytes) */
int _ShCompile(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  char **param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  ulong *puVar9;
  TSymbolTableLevel *pTVar10;
  ulong uVar11;
  void *pvVar12;
  uint uVar13;
  char in_RESERVE;
  byte bVar14;
  void *local_180;
  int *local_17c;
  int *local_178;
  undefined4 local_174;
  ulong local_160;
  ulong *local_150 [4];
  int *local_140;
  void **local_13c;
  char *local_138;
  int local_134;
  int local_130;
  int local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  ulong local_110;
  undefined4 *local_10c;
  int local_108;
  undefined4 local_100;
  undefined4 local_fc;
  ulong local_f8;
  undefined4 *local_f4;
  int local_f0;
  undefined4 local_e8;
  int local_e4;
  ulong local_d0;
  ulong local_c0;
  undefined4 local_b0;
  ulong local_a0;
  undefined4 local_50;
  int local_40;
  char *local_3c [3];
  
  local_3c[0] = (char *)GetPreprocessorBuiltinString();
  uVar6 = 0;
  if (param_1 != (int *)0x0) {
    piVar7 = (int *)(**(code **)(*param_1 + 8))(param_1);
    bVar14 = (piVar7 == (int *)0x0) << 1;
    uVar6 = 0;
    if (piVar7 != (int *)0x0) {
      _pthread_mutex_lock((pthread_mutex_t *)&_glsl_allocator_lock);
      GetGlobalPoolAllocator();
      ((int (*)())TPoolAllocator__push)();
      (**(code **)(*piVar7 + 0x18))(piVar7);
      uVar13 = *(uint *)piVar7[1];
      iVar4 = *(int *)(uVar13 - 0xc);
      uVar6 = *(uint *)piVar7[1];
      if (((*(int *)(uVar6 - 4) < 1) && (uVar6 <= uVar13)) && (uVar13 <= uVar6 + iVar4)) {
        std__string___M_replace_char_const__(0,uVar6,uVar6 + iVar4,uVar13,uVar13,0);
      }
      else {
        std__string___M_replace_safe_char_const__(0,uVar6,uVar6 + iVar4,uVar13,uVar13);
      }
      uVar11 = *(ulong *)(piVar7[1] + 8);
      std__string__replace(piVar7[1] + 8,0,*(char **)(uVar11 - 0xc),uVar11);
      if (param_3 == 0) {
        _pthread_mutex_unlock((pthread_mutex_t *)&_glsl_allocator_lock);
        uVar6 = 1;
      }
      else {
        local_40 = piVar7[1];
        puVar8 = (undefined4 *)((int (*)())GetSymbolTable)(piVar7[2]);
        local_180 = (void *)0x0;
        local_17c = (int *)0x0;
        local_178 = (int *)0x0;
        std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                  (&local_180,0,*puVar8);
        local_174 = puVar8[3];
        uVar11 = GetGlobalPoolAllocator();
        puVar9 = (ulong *)((int (*)())TPoolAllocator__allocate)(uVar11);
        local_160 = GetGlobalPoolAllocator();
        *puVar9 = local_160;
        puVar9[1] = 0;
        puVar8 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_160);
        puVar9[2] = 0;
        puVar9[1] = (ulong)puVar8;
        *puVar8 = 0;
        *(undefined4 *)(puVar9[1] + 4) = 0;
        *(ulong *)(puVar9[1] + 8) = puVar9[1];
        *(ulong *)(puVar9[1] + 0xc) = puVar9[1];
        local_150[0] = puVar9;
        if (local_17c == local_178) {
          std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                    (&local_180,local_17c,local_150);
        }
        else {
          if (local_17c != (int *)0x0) {
            *local_17c = (int)puVar9;
          }
          local_17c = local_17c + 1;
        }
        local_138 = (char *)piVar7[1];
        local_134 = piVar7[2];
        local_140 = &local_40;
        local_130 = 0;
        local_12c = 0;
        local_128 = 0;
        local_124 = 0;
        local_120 = 0;
        local_11c = 0;
        local_13c = &local_180;
        local_110 = GetGlobalPoolAllocator();
        local_10c = (undefined4 *)0x0;
        local_d0 = local_110;
        local_10c = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_110);
        local_108 = 0;
        *local_10c = 0;
        local_10c[1] = 0;
        local_10c[2] = local_10c;
        local_10c[3] = local_10c;
        local_100 = 1;
        local_fc = 0;
        local_f8 = GetGlobalPoolAllocator();
        local_f4 = (undefined4 *)0x0;
        local_c0 = local_f8;
        local_f4 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_f8);
        local_f0 = 0;
        *local_f4 = 0;
        local_e4 = DAT_a7b7ba70;
        local_f4[1] = 0;
        piVar5 = (int *)(local_e4 + 8);
        local_f4[2] = local_f4;
        local_f4[3] = local_f4;
        do {
          if (in_RESERVE != '\0') {
            iVar4 = storeWordConditionalIndexed(*piVar5 + 1,0,piVar5);
            *piVar5 = iVar4;
            bVar14 = 2;
          }
        } while (!(bool)(bVar14 >> 1 & 1));
        local_e8 = GetGlobalPoolAllocator();
        local_e4 = local_e4 + 0xc;
        local_b0 = local_e8;
        TParseContext__initializeExtensionBehavior();
        setInitialState();
        _InitPreprocessor();
        uVar11 = GetGlobalPoolAllocator();
        puVar9 = (ulong *)((int (*)())TPoolAllocator__allocate)(uVar11);
        local_a0 = GetGlobalPoolAllocator();
        *puVar9 = local_a0;
        puVar9[1] = 0;
        puVar8 = (undefined4 *)((int (*)())TPoolAllocator__allocate)(local_a0);
        puVar9[2] = 0;
        puVar9[1] = (ulong)puVar8;
        *puVar8 = 0;
        *(undefined4 *)(puVar9[1] + 4) = 0;
        *(ulong *)(puVar9[1] + 8) = puVar9[1];
        *(ulong *)(puVar9[1] + 0xc) = puVar9[1];
        local_150[0] = puVar9;
        if (local_17c == local_178) {
          std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                    (&local_180,local_17c,local_150);
        }
        else {
          if (local_17c != (int *)0x0) {
            *local_17c = (int)puVar9;
          }
          local_17c = local_17c + 1;
        }
        if (3 < (uint)((int)local_17c - (int)local_180 >> 2)) {
                    
                    
          uVar6 = (*(code *)(((unsigned char *)0x97ba14c0) + (*(unsigned char *)0x97ba14cc)))();
          return uVar6;
        }
        iVar4 = TParseContext__insertBuiltInArrayAtGlobalLevel();
        uVar6 = (uint)(iVar4 == 0);
        if ((iVar4 == 0) &&
           (iVar4 = PaParseStrings(local_3c,(int *)0x0,1,0,(unsigned char *)&local_140), iVar4 != 0)
           ) {
          uVar6 = 0;
        }
        iVar4 = PaParseStrings(param_2,(int *)0x0,param_3,0,(unsigned char *)&local_140);
        if (iVar4 != 0) {
          uVar6 = 0;
        }
        if ((uVar6 == 1) && (local_130 != 0)) {
          if (local_12c != 0) {
                    
                    
            uVar6 = (*(code *)(((unsigned char *)0x97ba15e4) + (*(unsigned char *)0x97ba15ec)))(local_138);
            return uVar6;
          }
          iVar4 = TIntermediate__postProcess(&local_40,local_130,local_134);
          pcVar3 = local_138;
          if (iVar4 != 1) {
                    
                    
            uVar6 = (*(code *)(((unsigned char *)0x97ba17b0) + (*(unsigned char *)0x97ba17bc)))();
            return uVar6;
          }
          uVar6 = 1;
          if (param_4 == 0) {
            TInfoSinkBase__append(local_138);
            TInfoSinkBase__append(pcVar3);
            bVar1 = (param_5 & 1) == 0;
            bVar14 = bVar1 << 1;
            if (!bVar1) {
              TIntermediate__outputTree((unsigned char *)&local_40);
            }
          }
          else {
            bVar1 = (param_5 & 1) == 0;
            bVar14 = bVar1 << 1;
            if (!bVar1) {
              TIntermediate__outputTree((unsigned char *)&local_40);
            }
            (**(code **)(*piVar7 + 0x34))(piVar7,param_4);
            (**(code **)(*piVar7 + 0x38))(piVar7,param_5);
            iVar4 = (**(code **)(*piVar7 + 0x14))(piVar7,local_130);
            if (iVar4 == 0) {
              uVar6 = 0;
            }
          }
        }
        else if (local_130 == 0) {
                    
                    
          uVar6 = (*(code *)(((unsigned char *)0x97ba1858) + (*(unsigned char *)0x97ba1860)))();
          return uVar6;
        }
        TIntermediate__remove((unsigned char *)&local_40);
        pvVar12 = local_180;
        for (; iVar4 = (int)local_17c - (int)pvVar12 >> 2, iVar4 != 1; local_17c = local_17c + -1) {
          pTVar10 = *(TSymbolTableLevel **)((int)pvVar12 + (iVar4 + -1) * 4);
          if (pTVar10 != (unsigned char *)0x0) {
            TSymbolTableLevel___TSymbolTableLevel(pTVar10);
            pvVar12 = local_180;
          }
        }
        _FinalizePreprocessor();
        GetGlobalPoolAllocator();
        ((int (*)())TPoolAllocator__pop)();
        _pthread_mutex_unlock((pthread_mutex_t *)&_glsl_allocator_lock);
        piVar7 = (int *)(local_e4 + -4);
        local_50 = local_e8;
        do {
          iVar4 = *piVar7;
          if (in_RESERVE != '\0') {
            iVar2 = storeWordConditionalIndexed(iVar4 + -1,0,piVar7);
            *piVar7 = iVar2;
            bVar14 = 2;
          }
        } while (!(bool)(bVar14 >> 1 & 1));
        if (iVar4 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_e4 + -0xc));
        }
        if (local_f0 != 0) {
          std::
          _Rb_tree<std::string,std::pair<std::string_const,std::string>,std::_Select1st<std::pair<std::string_const,std::string>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,std::string>>>
          ::_M_erase((unsigned char *)&local_f8);
          local_f4[2] = local_f4;
          local_f4[1] = 0;
          local_f4[3] = local_f4;
          local_f0 = 0;
        }
        pvVar12 = local_180;
        if (local_108 != 0) {
          std::
          _Rb_tree<std::string,std::pair<std::string_const,TBehavior>,std::_Select1st<std::pair<std::string_const,TBehavior>>,std::less<std::string>,pool_allocator<std::pair<std::string_const,TBehavior>>>
          ::_M_erase((unsigned char *)&local_110);
          local_10c[2] = local_10c;
          local_10c[1] = 0;
          local_10c[3] = local_10c;
          local_108 = 0;
          pvVar12 = local_180;
        }
        for (; uVar13 = (int)local_17c - (int)pvVar12 >> 2, 1 < uVar13; local_17c = local_17c + -1)
        {
          pTVar10 = *(TSymbolTableLevel **)((int)pvVar12 + (uVar13 - 1) * 4);
          if (pTVar10 != (unsigned char *)0x0) {
            TSymbolTableLevel___TSymbolTableLevel(pTVar10);
            pvVar12 = local_180;
          }
        }
        iVar4 = (int)local_178 - (int)pvVar12 >> 2;
        if (iVar4 != 0) {
          std____default_alloc_template_true_0___deallocate(pvVar12,iVar4 << 2);
        }
      }
    }
  }
  return uVar6;
}

/* _ShLink @ 0x97ba1a6c (364 bytes) */
int _ShLink(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  void *param_4;
  void *param_5;
{
  void **ppvVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  ulong uVar5;
  int iVar6;
  
  if ((param_1 != (int *)0x0) &&
     (ppvVar1 = (void **)(**(code **)(*param_1 + 0xc))(), ppvVar1 != (void **)0x0)) {
    uVar5 = *(ulong *)ppvVar1[0x21];
    std__string__replace((ulong)ppvVar1[0x21],0,*(char **)(uVar5 - 0xc),uVar5);
    uVar5 = *(ulong *)((int)ppvVar1[0x21] + 8);
    std__string__replace((int)ppvVar1[0x21] + 8,0,*(char **)(uVar5 - 0xc),uVar5);
    iVar6 = 0;
    TGenericLinker__reset();
    if (0 < param_3) {
      do {
        piVar2 = *(int **)(param_2 + iVar6 * 4);
        if (piVar2 == (int *)0x0) {
                    
                    
          uVar3 = (*(code *)(((unsigned char *)0x97ba1b34) + (*(unsigned char *)0x97ba1b40)))();
          return uVar3;
        }
        piVar2 = (int *)(**(code **)(*piVar2 + 8))();
        if ((piVar2 != (int *)0x0) && (iVar4 = (**(code **)(*piVar2 + 0x20))(), iVar4 == 0)) {
                    
                    
          uVar3 = (*(code *)(((unsigned char *)0x97ba1ba0) + (*(unsigned char *)0x97ba1ba8)))();
          return uVar3;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_3);
    }
    ppvVar1[0x20] = param_4;
    ppvVar1[0x1f] = param_5;
    iVar6 = TGenericLinker__link(ppvVar1,param_2);
    if (iVar6 != 0) {
      return 1;
    }
  }
  return 0;
}

/* ShSetEncryptionMethod @ 0x97ba1c68 (4 bytes) */
int ShSetEncryptionMethod(param_1)
  void *param_1;
{
  return;
}

/* _ShGetInfoLog @ 0x97ba1c6c (244 bytes) */
int _ShGetInfoLog(param_1)
  int *param_1;
{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = (**(code **)(*param_1 + 8))();
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*param_1 + 0xc))(param_1);
      if (iVar2 == 0) {
        return 0;
      }
      iVar2 = (**(code **)(*param_1 + 0xc))(param_1);
      piVar3 = *(int **)(iVar2 + 0x84);
    }
    else {
      piVar3 = (int *)(**(code **)(*param_1 + 8))(param_1);
      piVar3 = (int *)(**(code **)(*piVar3 + 0x10))();
    }
    puVar1 = PTR__S_terminal_a7b7c0b8;
    if (piVar3 != (int *)0x0) {
      *(undefined *)(piVar3[2] + *(int *)(piVar3[2] + -0xc)) = *PTR__S_terminal_a7b7c0b8;
      TInfoSinkBase__append((char *)piVar3);
      *(undefined *)(*piVar3 + *(int *)(*piVar3 + -0xc)) = *puVar1;
      iVar4 = *piVar3;
    }
  }
  return iVar4;
}

/* _ShGetPPStream @ 0x97ba1d60 (96 bytes) */
int _ShGetPPStream(param_1)
  int *param_1;
{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 8))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x1c))();
  }
  return uVar2;
}

/* _ShGetShaderLocalParamRemapTable @ 0x97ba1dc0 (92 bytes) */
int _ShGetShaderLocalParamRemapTable(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getShaderLocalParamRemapTable(iVar1,param_2);
  }
  return uVar2;
}

/* _ShGetNumShaderLocalParams @ 0x97ba1e1c (92 bytes) */
int _ShGetNumShaderLocalParams(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getNumShaderLocalParams(iVar1,param_2);
  }
  return uVar2;
}

/* _ShAttributeBindingRequest @ 0x97ba1e78 (104 bytes) */
int _ShAttributeBindingRequest(param_1, param_2)
  int *param_1;
  char *param_2;
{
  ulong uVar1;
  
  if ((param_1 != (int *)0x0) && (uVar1 = (**(code **)(*param_1 + 0xc))(), uVar1 != 0)) {
    TGenericLinker__attributeBindingRequest(uVar1,param_2);
    return;
  }
  return;
}

/* _ShGetNumActiveAttributes @ 0x97ba1ee0 (104 bytes) */
int _ShGetNumActiveAttributes(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) &&
     (uVar2 = 0, *(int *)(iVar1 + 4) != 0)) {
    uVar2 = BindingTable__GetNumActiveAttributeBindings();
  }
  return uVar2;
}

/* _ShGetNumActiveUniforms @ 0x97ba1f48 (104 bytes) */
int _ShGetNumActiveUniforms(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) &&
     (uVar2 = 0, *(int *)(iVar1 + 4) != 0)) {
    uVar2 = BindingTable__GetNumActiveUniformBindings();
  }
  return uVar2;
}

/* _ShGetActiveUserUniformsSize @ 0x97ba1fb0 (104 bytes) */
int _ShGetActiveUserUniformsSize(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) &&
     (uVar2 = 0, *(int *)(iVar1 + 4) != 0)) {
    uVar2 = BindingTable__GetSizeActiveUserUniforms();
  }
  return uVar2;
}

/* _ShGetMaxAttributeLength @ 0x97ba2018 (104 bytes) */
int _ShGetMaxAttributeLength(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) &&
     (uVar2 = 0, *(int *)(iVar1 + 4) != 0)) {
    uVar2 = BindingTable__GetMaxAttributeLength();
  }
  return uVar2;
}

/* _ShGetMaxUniformLength @ 0x97ba2080 (104 bytes) */
int _ShGetMaxUniformLength(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) &&
     (uVar2 = 0, *(int *)(iVar1 + 4) != 0)) {
    uVar2 = BindingTable__GetMaxUniformLength();
  }
  return uVar2;
}

/* _ShGetActiveUniform @ 0x97ba20e8 (132 bytes) */
int _ShGetActiveUniform(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  long param_2;
  long *param_3;
  long *param_4;
  ulong *param_5;
  char *param_6;
{
  ulong uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (uVar1 = (**(code **)(*param_1 + 0xc))(), uVar1 != 0)) {
    uVar2 = TGenericLinker__getActiveUniform(uVar1,param_2,param_3,param_4,param_5,param_6);
  }
  return uVar2;
}

/* _ShGetUniformTypeInfo @ 0x97ba216c (116 bytes) */
int _ShGetUniformTypeInfo(param_1, param_2, param_3, param_4)
  int *param_1;
  long *param_2;
  ulong *param_3;
  uchar *param_4;
{
  long lVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (lVar1 = (**(code **)(*param_1 + 0xc))(), lVar1 != 0)) {
    uVar2 = TGenericLinker__getUniformTypeInfo(lVar1,param_2,param_3,param_4);
  }
  return uVar2;
}

/* _ShGetActiveAttrib @ 0x97ba21e0 (132 bytes) */
int _ShGetActiveAttrib(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  long param_2;
  long *param_3;
  long *param_4;
  ulong *param_5;
  char *param_6;
{
  ulong uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (uVar1 = (**(code **)(*param_1 + 0xc))(), uVar1 != 0)) {
    uVar2 = TGenericLinker__getActiveAttrib(uVar1,param_2,param_3,param_4,param_5,param_6);
  }
  return uVar2;
}

/* _ShGetAttribLocation @ 0x97ba2264 (112 bytes) */
int _ShGetAttribLocation(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = 0xffffffff;
    if (*(char **)(iVar1 + 4) != (char *)0x0) {
      uVar2 = BindingTable__FindAttribBindingLocationByName(*(char **)(iVar1 + 4));
    }
  }
  return uVar2;
}

/* _ShGetUniformLocation @ 0x97ba22d4 (112 bytes) */
int _ShGetUniformLocation(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = 0xffffffff;
    if (*(char **)(iVar1 + 4) != (char *)0x0) {
      uVar2 = BindingTable__FindClientUniformBindingLocationByName(*(char **)(iVar1 + 4));
    }
  }
  return uVar2;
}

/* _ShGetPPStreamManager @ 0x97ba2344 (92 bytes) */
int _ShGetPPStreamManager(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getPPStreamManager(iVar1,param_2);
  }
  return uVar2;
}

/* _ShGetLinkerStats @ 0x97ba23a0 (84 bytes) */
int _ShGetLinkerStats(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getStatsString();
  }
  return uVar2;
}

/* _ShGetCompilerStats @ 0x97ba23f4 (96 bytes) */
int _ShGetCompilerStats(param_1)
  int *param_1;
{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 8))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x24))();
  }
  return uVar2;
}

/* _ShGetLinkerPPStream @ 0x97ba2454 (84 bytes) */
int _ShGetLinkerPPStream(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getPPStreamString();
  }
  return uVar2;
}

/* _ShGetCompilerPPStream @ 0x97ba24a8 (96 bytes) */
int _ShGetCompilerPPStream(param_1)
  int *param_1;
{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 8))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x28))();
  }
  return uVar2;
}

/* _ShGetLinkerShaderToProgramString @ 0x97ba2508 (84 bytes) */
int _ShGetLinkerShaderToProgramString(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getShaderToProgramString();
  }
  return uVar2;
}

/* _ShGetCompilerShaderToProgramString @ 0x97ba255c (96 bytes) */
int _ShGetCompilerShaderToProgramString(param_1)
  int *param_1;
{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 8))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x2c))();
  }
  return uVar2;
}

/* _ShGetLinkerBindingTable @ 0x97ba25bc (84 bytes) */
int _ShGetLinkerBindingTable(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getTableString();
  }
  return uVar2;
}

/* _ShGetCompilerSymbolTable @ 0x97ba2610 (96 bytes) */
int _ShGetCompilerSymbolTable(param_1)
  int *param_1;
{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 8))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
  }
  return uVar2;
}

/* TType__buildMangledName @ 0x97ba2670 (688 bytes) */
int TType__buildMangledName(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  char acStack_20 [16];
  
  iVar1 = (**(code **)(*(int *)this + 0x34))();
  if ((iVar1 != 0) || (iVar1 = (**(code **)(*(int *)this + 0x3c))(this), iVar1 != 0)) {
    std__string__append((ulong)param_1,'\x01');
  }
  switch(*(uint *)(this + 0x24) >> 0x13 & 0x3f) {
  default:
    goto switchD_97ba270c_caseD_0;
  case 1:
    goto LAB_97ba2778;
  case 2:
    goto LAB_97ba2778;
  case 3:
LAB_97ba2778:
    std__string__append((ulong)param_1,'\x01');
    goto switchD_97ba270c_caseD_0;
  case 5:
    pcVar2 = "s1";
    _strlen("s1");
    break;
  case 6:
    pcVar2 = "s2";
    _strlen("s2");
    break;
  case 7:
    pcVar2 = "s3";
    _strlen("s3");
    break;
  case 8:
    pcVar2 = "sC";
    _strlen("sC");
    break;
  case 9:
    pcVar2 = "sS1";
    _strlen("sS1");
    break;
  case 10:
    pcVar2 = "sS2";
    _strlen("sS2");
    break;
  case 0xb:
    pcVar2 = "sR2";
    _strlen("sR2");
    break;
  case 0xc:
    pcVar2 = "sSR2";
    _strlen("sSR2");
    break;
  case 0xe:
    _strlen("struct-");
    std__string__append((char *)param_1,0x97c29ef8);
    if (*(int *)(this + 0x10) != 0) {
      std__string__append(param_1);
    }
    for (uVar3 = 0;
        uVar3 < (uint)(*(int *)(*(int *)(this + 8) + 8) - *(int *)(*(int *)(this + 8) + 4) >> 3);
        uVar3 = uVar3 + 1) {
      std__string__append((ulong)param_1,'\x01');
      ((int (*)())TType__buildMangledName)(*(TType **)(*(int *)(*(int *)(this + 8) + 4) + uVar3 * 8),param_1);
    }
    goto switchD_97ba270c_caseD_0;
  }
  std__string__append((char *)param_1,(ulong)pcVar2);
switchD_97ba270c_caseD_0:
  (**(code **)(*(int *)this + 0x2c))(this);
  std__string__append((ulong)param_1,'\x01');
  iVar1 = (**(code **)(*(int *)this + 0x38))(this);
  if (iVar1 != 0) {
    _sprintf(acStack_20,"%d",*(undefined4 *)(this + 4));
    std__string__append((ulong)param_1,'\x01');
    _strlen(acStack_20);
    std__string__append((char *)param_1,(ulong)acStack_20);
    std__string__append((ulong)param_1,'\x01');
  }
  return;
}

/* TVariable__dump @ 0x97ba295c (220 bytes) */
int TVariable__dump(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  TInfoSink *pTVar1;
  
  pTVar1 = param_1 + 8;
  *(undefined1 *)
   (*(int *)(*(int *)(this + 4) + 4) + *(int *)(*(int *)(*(int *)(this + 4) + 4) + -0xc)) =
       *DAT_a7b7ba80;
  TInfoSinkBase__append((char *)pTVar1);
  TInfoSinkBase__append((char *)pTVar1);
  getQualifierString(*(uint *)(this + 0x30) >> 0x19);
  TInfoSinkBase__append((char *)pTVar1);
  TInfoSinkBase__append((char *)pTVar1);
  TType__getBasicString(*(uint *)(this + 0x30) >> 0x13 & 0x3f);
  TInfoSinkBase__append((char *)pTVar1);
  if ((*(uint *)(this + 0x30) & 0x200) != 0) {
    TInfoSinkBase__append((char *)pTVar1);
  }
  TInfoSinkBase__append((char *)pTVar1);
  return;
}

/* TFunction__dump @ 0x97ba2a38 (216 bytes) */
int TFunction__dump(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  undefined1 *puVar1;
  int iVar2;
  TInfoSink *pTVar3;
  
  puVar1 = DAT_a7b7ba80;
  pTVar3 = param_1 + 8;
  *(undefined1 *)
   (*(int *)(*(int *)(this + 4) + 4) + *(int *)(*(int *)(*(int *)(this + 4) + 4) + -0xc)) =
       *DAT_a7b7ba80;
  TInfoSinkBase__append((char *)pTVar3);
  TInfoSinkBase__append((char *)pTVar3);
  TType__getBasicString(*(uint *)(this + 0x40) >> 0x13 & 0x3f);
  TInfoSinkBase__append((char *)pTVar3);
  TInfoSinkBase__append((char *)pTVar3);
  iVar2 = (**(code **)(*(int *)this + 8))(this);
  *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *puVar1;
  TInfoSinkBase__append((char *)pTVar3);
  TInfoSinkBase__append((char *)pTVar3);
  return;
}

/* TSymbolTableLevel__dump @ 0x97ba2b10 (112 bytes) */
int TSymbolTableLevel__dump(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 4);
  iVar1 = *(int *)(iVar3 + 8);
  while (iVar1 != iVar3) {
    piVar2 = *(int **)(iVar1 + 0x18);
    (**(code **)(*piVar2 + 0x14))(piVar2,param_1);
    std___Rb_tree_base_iterator___M_increment();
    iVar3 = *(int *)(this + 4);
  }
  return;
}

/* TSymbolTable__dump @ 0x97ba2b80 (268 bytes) */
int TSymbolTable__dump(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  string *psVar4;
  int iVar5;
  char in_RESERVE;
  byte bVar6;
  undefined4 local_70;
  int local_6c;
  char acStack_60 [16];
  undefined4 local_50 [4];
  undefined4 local_40;
  
  iVar5 = (*(int *)(this + 4) - *(int *)this >> 2) + -1;
  if (-1 < iVar5) {
    psVar4 = (unsigned char *)(param_1 + 8);
    do {
      bVar6 = (iVar5 == 0) << 1;
      TInfoSinkBase__append((char *)psVar4);
      _sprintf(acStack_60,"%d",iVar5);
      local_50[0] = GetGlobalPoolAllocator();
      std__string__string((unsigned char *)&local_70,acStack_60,(unsigned char *)local_50);
      TInfoSinkBase__append(psVar4);
      piVar2 = (int *)(local_6c + -4);
      local_40 = local_70;
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar6 = 2;
        }
      } while (!(bool)(bVar6 >> 1 & 1));
      if (iVar3 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_6c + -0xc));
      }
      TInfoSinkBase__append((char *)psVar4);
      ((int (*)())TSymbolTableLevel__dump)(*(TSymbolTableLevel **)(*(int *)this + iVar5 * 4),param_1);
      iVar5 = iVar5 + -1;
    } while (-1 < iVar5);
  }
  return;
}

/* TFunction___TFunction @ 0x97ba2c8c (8 bytes) */
int TFunction___TFunction(this)
  unsigned char *this;
{
  ~TFunction(this);
  return;
}

