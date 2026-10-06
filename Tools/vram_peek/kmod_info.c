#include <mach/mach_types.h>

extern kern_return_t VRAMPeek_start(kmod_info_t *ki, void *data);
extern kern_return_t VRAMPeek_stop(kmod_info_t *ki, void *data);

KMOD_EXPLICIT_DECL(com.sambushman.VRAMPeek, "1.0.0", VRAMPeek_start, VRAMPeek_stop)
__private_extern__ kmod_start_func_t *_realmain = 0;
__private_extern__ kmod_stop_func_t *_antimain = 0;
__private_extern__ int _kext_apple_cc = __APPLE_CC__;
