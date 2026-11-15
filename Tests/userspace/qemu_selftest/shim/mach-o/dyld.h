#include <stdint.h>
struct mach_header;
static unsigned _dyld_image_count(void){return 0;}
static const struct mach_header *_dyld_get_image_header(unsigned i){return 0;}
static intptr_t _dyld_get_image_vmaddr_slide(unsigned i){return 0;}
