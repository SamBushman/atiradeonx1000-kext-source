#include <stdint.h>
struct nlist { union { int32_t n_strx; } n_un; uint8_t n_type, n_sect; int16_t n_desc; uint32_t n_value; };
#define N_TYPE 0x0e
#define N_EXT 1
#define N_UNDF 0
#define N_SECT 0xe
