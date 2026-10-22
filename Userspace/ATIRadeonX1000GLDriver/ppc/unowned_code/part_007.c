#include "decls.h"

/* ThreadModel__vslot3 @ 0x1d87f4 (8 bytes) */
int ThreadModel__vslot3()
{
  return 1;
}

/* ThreadModel__vslot5 @ 0x1d87fc (4 bytes) */
int ThreadModel__vslot5()
{
  return;
}

/* ThreadModel__vslot6 @ 0x1d8800 (8 bytes) */
int ThreadModel__vslot6(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 4);
}

/* ThreadModel__vslot7 @ 0x1d8808 (28 bytes) */
int ThreadModel__vslot7(param_1)
  int param_1;
{
  return *(int *)(param_1 + 4) <= *(int *)(param_1 + 8);
}

/* ThreadModel__vslot8 @ 0x1d8824 (20 bytes) */
int ThreadModel__vslot8(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x28))(param_2);
  return;
}

/* ThreadModel__vslot9 @ 0x1d8838 (8 bytes) */
int ThreadModel__vslot9()
{
  return 0;
}

/* ThreadModel__vslot10 @ 0x1d8840 (8 bytes) */
int ThreadModel__vslot10()
{
  return 0;
}

/* ThreadModel__vslot11 @ 0x1d8848 (8 bytes) */
int ThreadModel__vslot11()
{
  return 0;
}

/* R300SchedModel__vslot5 @ 0x1d8898 (16 bytes) */
int R300SchedModel__vslot5(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 8))();
  return;
}

/* R300SchedModel__vslot8 @ 0x1d88a8 (24 bytes) */
int R300SchedModel__vslot8(param_1)
  int param_1;
{
  return *(int *)(param_1 + 4) - 3U < 2;
}

/* R300SchedModel__vslot18 @ 0x1d88c0 (80 bytes) */
int R300SchedModel__vslot18(param_1, param_2)
  int *param_1;
  int param_2;
{
  if (*(int *)(param_2 + 0x60) != 0) {
    *(undefined4 *)(param_2 + 0x5c) = 0;
  }
  if (*(int *)(param_2 + 0x5c) == 0) {
    return;
  }
  if ((*(int *)(param_2 + 0x58) != 3) && (*(int *)(param_2 + 0x58) != 1)) {
    return;
  }
                    
                    
  (**(code **)(*param_1 + 0x38))();
  return;
}

/* R300SchedModel__dtor_1d8910 @ 0x1d8910 (52 bytes) */
int R300SchedModel__dtor_1d8910(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e90fc + 8;
  *param_1 = &PTR_orph_1d8910_001eb328;
  *param_1 = puVar1;
  return;
}

/* R300VSchedModel__vslot9 @ 0x1d898c (36 bytes) */
int R300VSchedModel__vslot9(param_1)
  int param_1;
{
  if ((*(int *)(param_1 + 0x18) < 0) && (*(int *)(param_1 + 0x1c) < 0)) {
    return 1;
  }
  return 0;
}

/* R300VSchedModel__vslot8 @ 0x1d89b0 (36 bytes) */
int R300VSchedModel__vslot8(param_1)
  int param_1;
{
  if ((-1 < *(int *)(param_1 + 0x18)) && (-1 < *(int *)(param_1 + 0x1c))) {
    return 1;
  }
  return 0;
}

/* R300VSchedModel__vslot10 @ 0x1d89d4 (36 bytes) */
int R300VSchedModel__vslot10(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if ((*(int *)(param_2 + 0x98) == 5) && (*(int *)(param_2 + 0x94) == 0)) {
    return 1;
  }
  return 0;
}

/* R300VSchedModel__vslot20 @ 0x1d89f8 (8 bytes) */
int R300VSchedModel__vslot20()
{
  return 1;
}

/* R300VSchedModel__vslot11 @ 0x1d8a00 (24 bytes) */
int R300VSchedModel__vslot11(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 0x58) == 2) {
    uVar1 = ResourceModel__vslot11(param_1,param_2);
    return uVar1;
  }
  return 0;
}

/* orph_1d8a10 @ 0x1d8a10 (8 bytes) */
int orph_1d8a10()
{
  return 0;
}

/* R300VSchedModel__vslot30 @ 0x1d8a18 (8 bytes) */
int R300VSchedModel__vslot30()
{
  return 2;
}

/* R300VSchedModel__vslot31 @ 0x1d8a20 (8 bytes) */
int R300VSchedModel__vslot31()
{
  return 1;
}

/* FudoPs__vslot66 @ 0x1d8aa4 (8 bytes) */
int FudoPs__vslot66()
{
  return 1;
}

/* FudoPs__vslot64 @ 0x1d8aac (8 bytes) */
int FudoPs__vslot64()
{
  return 1;
}

/* FudoPs__vslot65 @ 0x1d8ab4 (20 bytes) */
int FudoPs__vslot65(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
                    
                    
  (**(code **)(*param_1 + 0x100))(param_1,param_4);
  return;
}

/* FudoPs__vslot55 @ 0x1d8ac8 (8 bytes) */
int FudoPs__vslot55()
{
  return 1;
}

/* FudoPs__vslot88 @ 0x1d8ad0 (4 bytes) */
int FudoPs__vslot88()
{
  return;
}

/* FudoPs__vslot61 @ 0x1d8ad4 (8 bytes) */
int FudoPs__vslot61()
{
  return 1;
}

/* FudoPs__vslot31 @ 0x1d8adc (8 bytes) */
int FudoPs__vslot31()
{
  return 1;
}

/* FudoPs__vslot90 @ 0x1d8ae4 (8 bytes) */
int FudoPs__vslot90()
{
  return 0;
}

/* FudoChip__vslot3 @ 0x1d8aec (4 bytes) */
int FudoChip__vslot3()
{
  return;
}

/* FudoChip__vslot4 @ 0x1d8af0 (4 bytes) */
int FudoChip__vslot4()
{
  return;
}

/* R520SchedModel__vslot34 @ 0x1d8c04 (8 bytes) */
int R520SchedModel__vslot34()
{
  return 1;
}

/* R520SchedModel__vslot26 @ 0x1d8c0c (4 bytes) */
int R520SchedModel__vslot26()
{
  return;
}

/* R520SchedModel__vslot31 @ 0x1d8c10 (8 bytes) */
int R520SchedModel__vslot31()
{
  return 1;
}

/* R300MachineAssembler__visitLoopHeader @ 0x1d8cb4 (4 bytes) */
int R300MachineAssembler__visitLoopHeader()
{
  return;
}

/* R300MachineAssembler__vslot27 @ 0x1d8cb8 (4 bytes) */
int R300MachineAssembler__vslot27()
{
  return;
}

/* R300MachineAssembler__visitIfFooter @ 0x1d8cbc (4 bytes) */
int R300MachineAssembler__visitIfFooter()
{
  return;
}

/* R300MachineAssembler__visitLoopFooter @ 0x1d8cc0 (4 bytes) */
int R300MachineAssembler__visitLoopFooter()
{
  return;
}

/* R300MachineAssembler__visitPostLoopFooter @ 0x1d8cc4 (4 bytes) */
int R300MachineAssembler__visitPostLoopFooter()
{
  return;
}

/* R300MachineAssembler__visitBreak @ 0x1d8cc8 (4 bytes) */
int R300MachineAssembler__visitBreak()
{
  return;
}

/* R300MachineAssembler__visitContinue @ 0x1d8ccc (4 bytes) */
int R300MachineAssembler__visitContinue()
{
  return;
}

/* R300MachineAssembler__vslot37 @ 0x1d8cd0 (4 bytes) */
int R300MachineAssembler__vslot37()
{
  return;
}

/* R300MachineAssembler__vslot47 @ 0x1d8cd4 (4 bytes) */
int R300MachineAssembler__vslot47()
{
  return;
}

/* R300MachineAssembler__vslot51 @ 0x1d8cd8 (20 bytes) */
int R300MachineAssembler__vslot51(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(param_2 * 0x48 + *(int *)(param_1 + 0x58) + 0xe) = param_3;
  return;
}

/* R300MachineAssembler__vslot52 @ 0x1d8cec (20 bytes) */
int R300MachineAssembler__vslot52(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(param_2 * 0x48 + *(int *)(param_1 + 0x58) + 0xf) = param_3;
  return;
}

/* R300MachineAssembler__vslot55 @ 0x1d8d00 (8 bytes) */
int R300MachineAssembler__vslot55()
{
  return 0;
}

/* R300MachineAssembler__vslot56 @ 0x1d8d08 (12 bytes) */
int R300MachineAssembler__vslot56(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return param_2 + 0x8000;
}

/* R300MachineAssembler__vslot57 @ 0x1d8d14 (24 bytes) */
int R300MachineAssembler__vslot57(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x30) = param_2;
  return;
}

/* R300MachineAssembler__vslot58 @ 0x1d8d2c (24 bytes) */
int R300MachineAssembler__vslot58(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3f) = param_2;
  return;
}

/* R300MachineAssembler__vslot66 @ 0x1d8d44 (4 bytes) */
int R300MachineAssembler__vslot66()
{
  return;
}

/* R300MachineAssembler__vslot67 @ 0x1d8d48 (4 bytes) */
int R300MachineAssembler__vslot67()
{
  return;
}

/* R300MachineAssembler__vslot68 @ 0x1d8d4c (60 bytes) */
int R300MachineAssembler__vslot68(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
  if (*(char *)(iVar1 + -0x14) == '\x01') {
    return 0;
  }
  *(undefined1 *)(iVar1 + -0x14) = 1;
  return 1;
}

/* R300MachineAssembler__vslot69 @ 0x1d8d88 (56 bytes) */
int R300MachineAssembler__vslot69(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
  if (*(char *)(iVar1 + 0x34) == '\x01') {
    return 0;
  }
  *(undefined1 *)(iVar1 + 0x34) = 1;
  return 1;
}

/* R300MachineAssembler__vslot74 @ 0x1d8dc0 (4 bytes) */
int R300MachineAssembler__vslot74()
{
  return;
}

/* R300MachineAssembler__vslot79 @ 0x1d8dc4 (4 bytes) */
int R300MachineAssembler__vslot79()
{
  return;
}

/* R300MachineAssembler__vslot80 @ 0x1d8dc8 (4 bytes) */
int R300MachineAssembler__vslot80()
{
  return;
}

/* R300MachineAssembler__vslot82 @ 0x1d8dcc (4 bytes) */
int R300MachineAssembler__vslot82()
{
  return;
}

/* R300MachineAssembler__vslot83 @ 0x1d8dd0 (4 bytes) */
int R300MachineAssembler__vslot83()
{
  return;
}

/* R300MachineAssembler__vslot84 @ 0x1d8dd4 (24 bytes) */
int R300MachineAssembler__vslot84(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x31) = param_2;
  return;
}

/* R300VMachineAssembler__vslot8 @ 0x1d8dec (12 bytes) */
int R300VMachineAssembler__vslot8(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x58) << 4;
}

/* R300VMachineAssembler__vslot3 @ 0x1d8df8 (24 bytes) */
int R300VMachineAssembler__vslot3()
{
  return;
}

