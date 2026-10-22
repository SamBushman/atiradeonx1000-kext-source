#include "decls.h"

/* IRPhiNode__getNumSources @ 0x1ce978 (8 bytes) */
int IRPhiNode__getNumSources(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x84);
}

/* IRPhiNode__vslot33 @ 0x1ce980 (4 bytes) */
int IRPhiNode__vslot33()
{
  return;
}

/* IRPhiNode__appendSource @ 0x1ce984 (4 bytes) */
int IRPhiNode__appendSource()
{
  return;
}

/* IRPhiNode__vslot37 @ 0x1ce988 (8 bytes) */
int IRPhiNode__vslot37()
{
  return 0;
}

/* IRAlu__accept @ 0x1ce990 (28 bytes) */
int IRAlu__accept(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x38))(param_2,param_1);
  return;
}

/* IRAlu__isAlu @ 0x1ce9ac (8 bytes) */
int IRAlu__isAlu()
{
  return 1;
}

/* IRZeroary__getNumSources @ 0x1ce9d0 (8 bytes) */
int IRZeroary__getNumSources()
{
  return 0;
}

/* IRUnary__getNumSources @ 0x1ce9d8 (8 bytes) */
int IRUnary__getNumSources()
{
  return 1;
}

/* IRMov__accept @ 0x1ce9e0 (28 bytes) */
int IRMov__accept(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x48))(param_2,param_1);
  return;
}

/* IRMov__isMov @ 0x1ce9fc (8 bytes) */
int IRMov__isMov()
{
  return 1;
}

/* IRBinary__getNumSources @ 0x1cea04 (8 bytes) */
int IRBinary__getNumSources()
{
  return 2;
}

/* IRTrinary__getNumSources @ 0x1cea0c (8 bytes) */
int IRTrinary__getNumSources()
{
  return 3;
}

/* IRFetch__isFetch @ 0x1cea14 (8 bytes) */
int IRFetch__isFetch()
{
  return 1;
}

/* IRFetch__getNumSources @ 0x1cea1c (8 bytes) */
int IRFetch__getNumSources()
{
  return 1;
}

/* IRVertexFetch__isVertexFetch @ 0x1cea40 (8 bytes) */
int IRVertexFetch__isVertexFetch()
{
  return 1;
}

/* IRVertexFetch__accept @ 0x1cea48 (28 bytes) */
int IRVertexFetch__accept(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x58))(param_2,param_1);
  return;
}

/* IRTextureFetch__isTextureFetch @ 0x1cea64 (8 bytes) */
int IRTextureFetch__isTextureFetch()
{
  return 1;
}

/* IRTextureFetch__accept @ 0x1cea6c (28 bytes) */
int IRTextureFetch__accept(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x5c))(param_2,param_1);
  return;
}

/* IRTextureFetchGradients__getNumSources @ 0x1cea88 (8 bytes) */
int IRTextureFetchGradients__getNumSources()
{
  return 3;
}

/* IRMemLoad__isMemLoad @ 0x1cea90 (8 bytes) */
int IRMemLoad__isMemLoad()
{
  return 1;
}

/* IRMemLoad__getNumSources @ 0x1cea98 (8 bytes) */
int IRMemLoad__getNumSources()
{
  return 2;
}

/* IRMemLoad__accept @ 0x1ceaa0 (28 bytes) */
int IRMemLoad__accept(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x28))(param_2,param_1);
  return;
}

/* IRMemStore__isMemStore @ 0x1ceabc (8 bytes) */
int IRMemStore__isMemStore()
{
  return 1;
}

/* IRMemStore__getNumSources @ 0x1ceac4 (8 bytes) */
int IRMemStore__getNumSources()
{
  return 2;
}

/* IRMemStore__accept @ 0x1ceacc (28 bytes) */
int IRMemStore__accept(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x2c))(param_2,param_1);
  return;
}

/* IRExport__getNumDests @ 0x1ceae8 (8 bytes) */
int IRExport__getNumDests()
{
  return 0;
}

/* IRExport__getNumSources @ 0x1ceaf0 (8 bytes) */
int IRExport__getNumSources()
{
  return 1;
}

/* IRExport__accept @ 0x1ceaf8 (28 bytes) */
int IRExport__accept(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x3c))(param_2,param_1);
  return;
}

/* IRExport__getKindName @ 0x1ceb14 (28 bytes) */
int IRExport__getKindName()
{
  return "export";
}

/* IRExport__isExport @ 0x1ceb30 (8 bytes) */
int IRExport__isExport()
{
  return 1;
}

/* IRExportColorAndFog__getNumDests @ 0x1ceb38 (8 bytes) */
int IRExportColorAndFog__getNumDests()
{
  return 2;
}

/* IRExportColorAndFog__getNumSources @ 0x1ceb40 (8 bytes) */
int IRExportColorAndFog__getNumSources()
{
  return 2;
}

/* IRExportColorAndFog__accept @ 0x1ceb48 (28 bytes) */
int IRExportColorAndFog__accept(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x40))(param_2,param_1);
  return;
}

/* IRExportColorAndFog__getKindName @ 0x1ceb64 (28 bytes) */
int IRExportColorAndFog__getKindName()
{
  return "export_color_and_fog";
}

/* IRGeomExport__accept @ 0x1ceb80 (28 bytes) */
int IRGeomExport__accept(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x44))(param_2,param_1);
  return;
}

/* IRGeomExport__isGeomExport @ 0x1ceb9c (8 bytes) */
int IRGeomExport__isGeomExport()
{
  return 1;
}

/* IRCmp2__getNumDests @ 0x1ceba4 (8 bytes) */
int IRCmp2__getNumDests()
{
  return 0;
}

/* IRCmp2__getNumSources @ 0x1cebac (8 bytes) */
int IRCmp2__getNumSources()
{
  return 2;
}

/* IRCmp1S__accept @ 0x1cebd0 (4 bytes) */
int IRCmp1S__accept()
{
  return;
}

/* IRCmp1S__getNumDests @ 0x1cebd4 (8 bytes) */
int IRCmp1S__getNumDests()
{
  return 0;
}

/* IRCmp1S__getNumSources @ 0x1cebdc (8 bytes) */
int IRCmp1S__getNumSources()
{
  return 1;
}

/* IRKill2__getNumSources @ 0x1cec00 (8 bytes) */
int IRKill2__getNumSources()
{
  return 2;
}

/* IRKill2__accept @ 0x1cec08 (28 bytes) */
int IRKill2__accept(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x54))(param_2,param_1);
  return;
}

/* IRKill2__getKindName @ 0x1cec24 (28 bytes) */
int IRKill2__getKindName()
{
  return "ir_kill2";
}

/* IRLoopStart__getNumSources @ 0x1cec40 (8 bytes) */
int IRLoopStart__getNumSources()
{
  return 1;
}

/* IRLoopStart__isLoopStart @ 0x1cec48 (8 bytes) */
int IRLoopStart__isLoopStart()
{
  return 1;
}

/* IRAlu__vslot34 @ 0x1cec6c (32 bytes) */
int IRAlu__vslot34(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  if (param_4 - 5U < 2) {
    return;
  }
  *(char *)(param_2 * 0x18 + param_1 + param_3 + 0x9c) = (char)param_4;
  return;
}

/* IRFetch__vslot34 @ 0x1cec8c (32 bytes) */
int IRFetch__vslot34(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  if (param_4 - 5U < 2) {
    return;
  }
  *(char *)(param_2 * 0x18 + param_1 + param_3 + 0x9c) = (char)param_4;
  return;
}

/* IRGeomExport__getNumSources @ 0x1cecac (12 bytes) */
int IRGeomExport__getNumSources(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x84) + -1;
}

/* IRInst__getNumSources @ 0x1cecb8 (8 bytes) */
int IRInst__getNumSources(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x84);
}

/* HwLimits__vslot2 @ 0x1cffec (8 bytes) */
int HwLimits__vslot2()
{
  return 0;
}

/* HwLimits__vslot3 @ 0x1cfff4 (4 bytes) */
int HwLimits__vslot3()
{
  return;
}

/* HwLimits__vslot4 @ 0x1cfff8 (4 bytes) */
int HwLimits__vslot4()
{
  return;
}

/* HwLimits__vslot5 @ 0x1cfffc (4 bytes) */
int HwLimits__vslot5()
{
  return;
}

/* HwLimits__vslot11 @ 0x1d0020 (8 bytes) */
int HwLimits__vslot11()
{
  return 1;
}

/* HwLimits__vslot12 @ 0x1d0028 (8 bytes) */
int HwLimits__vslot12(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  return param_2;
}

/* HwLimits__vslot13 @ 0x1d0030 (8 bytes) */
int HwLimits__vslot13()
{
  return 0;
}

/* HwLimits__vslot14 @ 0x1d0038 (4 bytes) */
int HwLimits__vslot14()
{
  return;
}

/* HwLimits__vslot15 @ 0x1d003c (4 bytes) */
int HwLimits__vslot15()
{
  return;
}

/* HwLimits__vslot18 @ 0x1d0040 (8 bytes) */
int HwLimits__vslot18(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  return param_3;
}

