#include "decls.h"

/* orph_1d87f4 @ 0x1d87f4 (8 bytes) */
int orph_1d87f4()
{
  return 1;
}

/* orph_1d87fc @ 0x1d87fc (4 bytes) */
int orph_1d87fc()
{
  return;
}

/* orph_1d8800 @ 0x1d8800 (8 bytes) */
int orph_1d8800(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 4);
}

/* orph_1d8808 @ 0x1d8808 (28 bytes) */
int orph_1d8808(param_1)
  int param_1;
{
  return *(int *)(param_1 + 4) <= *(int *)(param_1 + 8);
}

/* orph_1d8824 @ 0x1d8824 (20 bytes) */
int orph_1d8824(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x28))(param_2);
  return;
}

/* orph_1d8838 @ 0x1d8838 (8 bytes) */
int orph_1d8838()
{
  return 0;
}

/* orph_1d8840 @ 0x1d8840 (8 bytes) */
int orph_1d8840()
{
  return 0;
}

/* orph_1d8848 @ 0x1d8848 (8 bytes) */
int orph_1d8848()
{
  return 0;
}

/* orph_1d8898 @ 0x1d8898 (16 bytes) */
int orph_1d8898(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 8))();
  return;
}

/* orph_1d88a8 @ 0x1d88a8 (24 bytes) */
int orph_1d88a8(param_1)
  int param_1;
{
  return *(int *)(param_1 + 4) - 3U < 2;
}

/* orph_1d88c0 @ 0x1d88c0 (80 bytes) */
int orph_1d88c0(param_1, param_2)
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

/* orph_1d8910 @ 0x1d8910 (52 bytes) */
int orph_1d8910(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e90fc + 8;
  *param_1 = &PTR_orph_1d8910_001eb328;
  *param_1 = puVar1;
  return;
}

/* orph_1d898c @ 0x1d898c (36 bytes) */
int orph_1d898c(param_1)
  int param_1;
{
  if ((*(int *)(param_1 + 0x18) < 0) && (*(int *)(param_1 + 0x1c) < 0)) {
    return 1;
  }
  return 0;
}

/* orph_1d89b0 @ 0x1d89b0 (36 bytes) */
int orph_1d89b0(param_1)
  int param_1;
{
  if ((-1 < *(int *)(param_1 + 0x18)) && (-1 < *(int *)(param_1 + 0x1c))) {
    return 1;
  }
  return 0;
}

/* orph_1d89d4 @ 0x1d89d4 (36 bytes) */
int orph_1d89d4(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if ((*(int *)(param_2 + 0x98) == 5) && (*(int *)(param_2 + 0x94) == 0)) {
    return 1;
  }
  return 0;
}

/* orph_1d89f8 @ 0x1d89f8 (8 bytes) */
int orph_1d89f8()
{
  return 1;
}

/* orph_1d8a00 @ 0x1d8a00 (24 bytes) */
int orph_1d8a00(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 0x58) == 2) {
    uVar1 = FUN_00172514(param_1,param_2);
    return uVar1;
  }
  return 0;
}

/* orph_1d8a10 @ 0x1d8a10 (8 bytes) */
int orph_1d8a10()
{
  return 0;
}

/* orph_1d8a18 @ 0x1d8a18 (8 bytes) */
int orph_1d8a18()
{
  return 2;
}

/* orph_1d8a20 @ 0x1d8a20 (8 bytes) */
int orph_1d8a20()
{
  return 1;
}

/* orph_1d8aa4 @ 0x1d8aa4 (8 bytes) */
int orph_1d8aa4()
{
  return 1;
}

/* orph_1d8aac @ 0x1d8aac (8 bytes) */
int orph_1d8aac()
{
  return 1;
}

/* orph_1d8ab4 @ 0x1d8ab4 (20 bytes) */
int orph_1d8ab4(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
                    
                    
  (**(code **)(*param_1 + 0x100))(param_1,param_4);
  return;
}

/* orph_1d8ac8 @ 0x1d8ac8 (8 bytes) */
int orph_1d8ac8()
{
  return 1;
}

/* orph_1d8ad0 @ 0x1d8ad0 (4 bytes) */
int orph_1d8ad0()
{
  return;
}

/* orph_1d8ad4 @ 0x1d8ad4 (8 bytes) */
int orph_1d8ad4()
{
  return 1;
}

/* orph_1d8adc @ 0x1d8adc (8 bytes) */
int orph_1d8adc()
{
  return 1;
}

/* orph_1d8ae4 @ 0x1d8ae4 (8 bytes) */
int orph_1d8ae4()
{
  return 0;
}

/* orph_1d8aec @ 0x1d8aec (4 bytes) */
int orph_1d8aec()
{
  return;
}

/* orph_1d8af0 @ 0x1d8af0 (4 bytes) */
int orph_1d8af0()
{
  return;
}

/* orph_1d8c04 @ 0x1d8c04 (8 bytes) */
int orph_1d8c04()
{
  return 1;
}

/* orph_1d8c0c @ 0x1d8c0c (4 bytes) */
int orph_1d8c0c()
{
  return;
}

/* orph_1d8c10 @ 0x1d8c10 (8 bytes) */
int orph_1d8c10()
{
  return 1;
}

/* orph_1d8cb4 @ 0x1d8cb4 (4 bytes) */
int orph_1d8cb4()
{
  return;
}

/* orph_1d8cb8 @ 0x1d8cb8 (4 bytes) */
int orph_1d8cb8()
{
  return;
}

/* orph_1d8cbc @ 0x1d8cbc (4 bytes) */
int orph_1d8cbc()
{
  return;
}

/* orph_1d8cc0 @ 0x1d8cc0 (4 bytes) */
int orph_1d8cc0()
{
  return;
}

/* orph_1d8cc4 @ 0x1d8cc4 (4 bytes) */
int orph_1d8cc4()
{
  return;
}

/* orph_1d8cc8 @ 0x1d8cc8 (4 bytes) */
int orph_1d8cc8()
{
  return;
}

/* orph_1d8ccc @ 0x1d8ccc (4 bytes) */
int orph_1d8ccc()
{
  return;
}

/* orph_1d8cd0 @ 0x1d8cd0 (4 bytes) */
int orph_1d8cd0()
{
  return;
}

/* orph_1d8cd4 @ 0x1d8cd4 (4 bytes) */
int orph_1d8cd4()
{
  return;
}

/* orph_1d8cd8 @ 0x1d8cd8 (20 bytes) */
int orph_1d8cd8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(param_2 * 0x48 + *(int *)(param_1 + 0x58) + 0xe) = param_3;
  return;
}

/* orph_1d8cec @ 0x1d8cec (20 bytes) */
int orph_1d8cec(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined1 *)(param_2 * 0x48 + *(int *)(param_1 + 0x58) + 0xf) = param_3;
  return;
}

/* orph_1d8d00 @ 0x1d8d00 (8 bytes) */
int orph_1d8d00()
{
  return 0;
}

/* orph_1d8d08 @ 0x1d8d08 (12 bytes) */
int orph_1d8d08(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  return param_2 + 0x8000;
}

/* orph_1d8d14 @ 0x1d8d14 (24 bytes) */
int orph_1d8d14(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x30) = param_2;
  return;
}

/* orph_1d8d2c @ 0x1d8d2c (24 bytes) */
int orph_1d8d2c(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3f) = param_2;
  return;
}

/* orph_1d8d44 @ 0x1d8d44 (4 bytes) */
int orph_1d8d44()
{
  return;
}

/* orph_1d8d48 @ 0x1d8d48 (4 bytes) */
int orph_1d8d48()
{
  return;
}

/* orph_1d8d4c @ 0x1d8d4c (60 bytes) */
int orph_1d8d4c(param_1)
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

/* orph_1d8d88 @ 0x1d8d88 (56 bytes) */
int orph_1d8d88(param_1)
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

/* orph_1d8dc0 @ 0x1d8dc0 (4 bytes) */
int orph_1d8dc0()
{
  return;
}

/* orph_1d8dc4 @ 0x1d8dc4 (4 bytes) */
int orph_1d8dc4()
{
  return;
}

/* orph_1d8dc8 @ 0x1d8dc8 (4 bytes) */
int orph_1d8dc8()
{
  return;
}

/* orph_1d8dcc @ 0x1d8dcc (4 bytes) */
int orph_1d8dcc()
{
  return;
}

/* orph_1d8dd0 @ 0x1d8dd0 (4 bytes) */
int orph_1d8dd0()
{
  return;
}

/* orph_1d8dd4 @ 0x1d8dd4 (24 bytes) */
int orph_1d8dd4(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x31) = param_2;
  return;
}

/* orph_1d8dec @ 0x1d8dec (12 bytes) */
int orph_1d8dec(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x58) << 4;
}

/* orph_1d8df8 @ 0x1d8df8 (24 bytes) */
int orph_1d8df8()
{
  return;
}

