#include "decls.h"

/* TCompiler__getPPStreamString @ 0x97c34c0c (8 bytes) */
int TCompiler__getPPStreamString()
{
  return 0;
}

/* TCompiler__getShaderToProgramString @ 0x97c34c14 (8 bytes) */
int TCompiler__getShaderToProgramString()
{
  return 0;
}

/* TCompiler__getTableString @ 0x97c34c1c (8 bytes) */
int TCompiler__getTableString()
{
  return 0;
}

/* TCompiler__setOpimizationLevel @ 0x97c34c24 (4 bytes) */
int TCompiler__setOpimizationLevel()
{
  return;
}

/* TCompiler__setDebugOptions @ 0x97c34c28 (4 bytes) */
int TCompiler__setDebugOptions()
{
  return;
}

/* TCompiler__getNewCompilationAllocator @ 0x97c34c2c (60 bytes) */
int TCompiler__getNewCompilationAllocator(this)
  unsigned char * this;
{
  TPoolAllocator__pop();
  TPoolAllocator__push();
  return this + 0x10;
}

/* TPPStreamCompiler__setOpimizationLevel @ 0x97c34c68 (8 bytes) */
int TPPStreamCompiler__setOpimizationLevel(this, param_2)
  unsigned char * this;
  undefined4 param_2;
{
  *(undefined4 *)(this + 0xc4) = param_2;
  return;
}

/* TPPStreamCompiler__setDebugOptions @ 0x97c34c70 (8 bytes) */
int TPPStreamCompiler__setDebugOptions(this, param_2)
  unsigned char * this;
  undefined4 param_2;
{
  *(undefined4 *)(this + 0xc0) = param_2;
  return;
}

/* TPPStreamCompiler__getPPStream @ 0x97c34c78 (8 bytes) */
int TPPStreamCompiler__getPPStream(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x74);
}

/* std__domain_error___domain_error @ 0x97c34c80 (64 bytes) */
int std__domain_error___domain_error(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__domain_error_a7b7de00;
  std__logic_error___logic_error((unsigned char *)this);
  return;
}

/* std__invalid_argument___invalid_argument @ 0x97c34cc0 (64 bytes) */
int std__invalid_argument___invalid_argument(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__invalid_argument_a7b7dde8;
  std__logic_error___logic_error((unsigned char *)this);
  return;
}

/* std__length_error___length_error @ 0x97c34d00 (64 bytes) */
int std__length_error___length_error(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__length_error_a7b7ddd0;
  std__logic_error___logic_error((unsigned char *)this);
  return;
}

/* std__out_of_range___out_of_range @ 0x97c34d40 (64 bytes) */
int std__out_of_range___out_of_range(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__out_of_range_a7b7ddb8;
  std__logic_error___logic_error((unsigned char *)this);
  return;
}

/* std__range_error___range_error @ 0x97c34d80 (64 bytes) */
int std__range_error___range_error(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__range_error_a7b7dda0;
  std__runtime_error___runtime_error((unsigned char *)this);
  return;
}

/* std__overflow_error___overflow_error @ 0x97c34dc0 (64 bytes) */
int std__overflow_error___overflow_error(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__overflow_error_a7b7dd88;
  std__runtime_error___runtime_error((unsigned char *)this);
  return;
}

/* std__underflow_error___underflow_error @ 0x97c34e00 (64 bytes) */
int std__underflow_error___underflow_error(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__underflow_error_a7b7dd70;
  std__runtime_error___runtime_error((unsigned char *)this);
  return;
}

/* std__domain_error___domain_error_97c34e40 @ 0x97c34e40 (76 bytes) */
int std__domain_error___domain_error_97c34e40(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__domain_error_a7b7de00;
  std__logic_error___logic_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__invalid_argument___invalid_argument_97c34e8c @ 0x97c34e8c (76 bytes) */
int std__invalid_argument___invalid_argument_97c34e8c(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__invalid_argument_a7b7dde8;
  std__logic_error___logic_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__length_error___length_error_97c34ed8 @ 0x97c34ed8 (76 bytes) */
int std__length_error___length_error_97c34ed8(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__length_error_a7b7ddd0;
  std__logic_error___logic_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__out_of_range___out_of_range_97c34f24 @ 0x97c34f24 (76 bytes) */
int std__out_of_range___out_of_range_97c34f24(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__out_of_range_a7b7ddb8;
  std__logic_error___logic_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__range_error___range_error_97c34f70 @ 0x97c34f70 (76 bytes) */
int std__range_error___range_error_97c34f70(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__range_error_a7b7dda0;
  std__runtime_error___runtime_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__overflow_error___overflow_error_97c34fbc @ 0x97c34fbc (76 bytes) */
int std__overflow_error___overflow_error_97c34fbc(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__overflow_error_a7b7dd88;
  std__runtime_error___runtime_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__underflow_error___underflow_error_97c35008 @ 0x97c35008 (76 bytes) */
int std__underflow_error___underflow_error_97c35008(this)
  unsigned char * this;
{
  *(undefined ***)this = &PTR__underflow_error_a7b7dd70;
  std__runtime_error___runtime_error((unsigned char *)this);
  operator_delete(this);
  return;
}

/* std__domain_error___domain_error_97c3aff8 @ 0x97c3aff8 (1 bytes) */
int std__domain_error___domain_error_97c3aff8(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__invalid_argument___invalid_argument_97c3b020 @ 0x97c3b020 (1 bytes) */
int std__invalid_argument___invalid_argument_97c3b020(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__length_error___length_error_97c3b048 @ 0x97c3b048 (1 bytes) */
int std__length_error___length_error_97c3b048(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__out_of_range___out_of_range_97c3b070 @ 0x97c3b070 (1 bytes) */
int std__out_of_range___out_of_range_97c3b070(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__range_error___range_error_97c3b098 @ 0x97c3b098 (1 bytes) */
int std__range_error___range_error_97c3b098(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__overflow_error___overflow_error_97c3b0c0 @ 0x97c3b0c0 (1 bytes) */
int std__overflow_error___overflow_error_97c3b0c0(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__underflow_error___underflow_error_97c3b0e8 @ 0x97c3b0e8 (1 bytes) */
int std__underflow_error___underflow_error_97c3b0e8(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__domain_error___domain_error_97c3b110 @ 0x97c3b110 (1 bytes) */
int std__domain_error___domain_error_97c3b110(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__invalid_argument___invalid_argument_97c3b13c @ 0x97c3b13c (1 bytes) */
int std__invalid_argument___invalid_argument_97c3b13c(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__length_error___length_error_97c3b168 @ 0x97c3b168 (1 bytes) */
int std__length_error___length_error_97c3b168(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__out_of_range___out_of_range_97c3b194 @ 0x97c3b194 (1 bytes) */
int std__out_of_range___out_of_range_97c3b194(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__range_error___range_error_97c3b1c0 @ 0x97c3b1c0 (1 bytes) */
int std__range_error___range_error_97c3b1c0(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__overflow_error___overflow_error_97c3b1ec @ 0x97c3b1ec (1 bytes) */
int std__overflow_error___overflow_error_97c3b1ec(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* std__underflow_error___underflow_error_97c3b218 @ 0x97c3b218 (1 bytes) */
int std__underflow_error___underflow_error_97c3b218(this)
  unsigned char * this;
{
                    
  halt_baddata();
}

/* __gnu_cxx__operator___a7b7f000 @ 0xa7b7f000 (1 bytes) */
int __gnu_cxx__operator___a7b7f000(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
                    
  halt_baddata();
}

/* __gnu_cxx__operator___a7b7f004 @ 0xa7b7f004 (1 bytes) */
int __gnu_cxx__operator___a7b7f004(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
                    
  halt_baddata();
}

/* std__string__find_last_of_a7b7f008 @ 0xa7b7f008 (1 bytes) */
int std__string__find_last_of_a7b7f008(param_1, param_2)
  char *param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__find_last_of_a7b7f00c @ 0xa7b7f00c (1 bytes) */
int std__string__find_last_of_a7b7f00c(param_1, param_2, param_3)
  char *param_1;
  ulong param_2;
  ulong param_3;
{
                    
  halt_baddata();
}

/* std__string__find_last_of_a7b7f010 @ 0xa7b7f010 (1 bytes) */
int std__string__find_last_of_a7b7f010(param_1, param_2)
  unsigned char * param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__find_last_of_a7b7f014 @ 0xa7b7f014 (1 bytes) */
int std__string__find_last_of_a7b7f014(param_1, param_2)
  int param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__find_first_of_a7b7f018 @ 0xa7b7f018 (1 bytes) */
int std__string__find_first_of_a7b7f018(param_1, param_2)
  char *param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__find_first_of_a7b7f01c @ 0xa7b7f01c (1 bytes) */
int std__string__find_first_of_a7b7f01c(param_1, param_2, param_3)
  char *param_1;
  ulong param_2;
  ulong param_3;
{
                    
  halt_baddata();
}

/* std__string__find_first_of_a7b7f020 @ 0xa7b7f020 (1 bytes) */
int std__string__find_first_of_a7b7f020(param_1, param_2)
  unsigned char * param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__find_first_of_a7b7f024 @ 0xa7b7f024 (1 bytes) */
int std__string__find_first_of_a7b7f024(param_1, param_2)
  int param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__get_allocator_a7b7f028 @ 0xa7b7f028 (1 bytes) */
int std__string__get_allocator_a7b7f028()
{
                    
  halt_baddata();
}

/* std__string__find_last_not_of_a7b7f02c @ 0xa7b7f02c (1 bytes) */
int std__string__find_last_not_of_a7b7f02c(param_1, param_2)
  char *param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__find_last_not_of_a7b7f030 @ 0xa7b7f030 (1 bytes) */
int std__string__find_last_not_of_a7b7f030(param_1, param_2, param_3)
  char *param_1;
  ulong param_2;
  ulong param_3;
{
                    
  halt_baddata();
}

/* std__string__find_last_not_of_a7b7f034 @ 0xa7b7f034 (1 bytes) */
int std__string__find_last_not_of_a7b7f034(param_1, param_2)
  unsigned char * param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__find_last_not_of_a7b7f038 @ 0xa7b7f038 (1 bytes) */
int std__string__find_last_not_of_a7b7f038(param_1, param_2)
  int param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__find_first_not_of_a7b7f03c @ 0xa7b7f03c (1 bytes) */
int std__string__find_first_not_of_a7b7f03c(param_1, param_2)
  char *param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__find_first_not_of_a7b7f040 @ 0xa7b7f040 (1 bytes) */
int std__string__find_first_not_of_a7b7f040(param_1, param_2, param_3)
  char *param_1;
  ulong param_2;
  ulong param_3;
{
                    
  halt_baddata();
}

/* std__string__find_first_not_of_a7b7f044 @ 0xa7b7f044 (1 bytes) */
int std__string__find_first_not_of_a7b7f044(param_1, param_2)
  unsigned char * param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__find_first_not_of_a7b7f048 @ 0xa7b7f048 (1 bytes) */
int std__string__find_first_not_of_a7b7f048(param_1, param_2)
  int param_1;
  ulong param_2;
{
                    
  halt_baddata();
}

/* std__string__end_a7b7f04c @ 0xa7b7f04c (1 bytes) */
int std__string__end_a7b7f04c()
{
                    
  halt_baddata();
}

/* std__string___Rep___M_is_leaked_a7b7f050 @ 0xa7b7f050 (1 bytes) */
int std__string___Rep___M_is_leaked_a7b7f050()
{
                    
  halt_baddata();
}

/* std__string___Rep___M_is_shared_a7b7f054 @ 0xa7b7f054 (1 bytes) */
int std__string___Rep___M_is_shared_a7b7f054()
{
                    
  halt_baddata();
}

/* std__string__data_a7b7f058 @ 0xa7b7f058 (1 bytes) */
int std__string__data_a7b7f058()
{
                    
  halt_baddata();
}

