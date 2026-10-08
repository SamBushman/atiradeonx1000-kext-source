/*
 * Tools/request_probe.c - issue #154 fix: a hot-swapped ATIRadeonX1000 instance never receives the
 * framebuffer-discovery kick a boot-time-loaded accelerator gets automatically from the graphics
 * subsystem (IOATIR500Accelerator::start()'s own synchronous findFramebuffers() call is gated off on
 * this OS's real IOKitBuildVersion string - see issue #154's resolution comment). Without it,
 * self+0xcc (head count) stays 0 forever and IOATIR500Accelerator::getVRAMDescriptors() - which every
 * client type's start() calls - fails immediately, so NO client (GL/2D/Surface/DVD) can ever open.
 *
 * Call this once, right after kextload'ing a rebuilt kext under the real bundle id, before running
 * any client-open test. Uses the standard public userspace IOKit API (IOServiceRequestProbe), not a
 * custom diagnostic kext - this is the same real mechanism a normal display-reconfiguration event
 * uses in production, exercised directly instead of waiting for one to happen to occur.
 *
 * Usage: ./request_probe [bundle-match-name]   (default: "ATIRadeonX1000")
 * Exit 0 on success, 1 if the service wasn't found or the probe call failed.
 */
#include <stdio.h>
#include <IOKit/IOKitLib.h>
#include <CoreFoundation/CoreFoundation.h>

int main(int argc, char **argv) {
    const char *name = (argc > 1) ? argv[1] : "ATIRadeonX1000";
    CFMutableDictionaryRef match = IOServiceMatching(name);
    if (!match) { fprintf(stderr, "request_probe: IOServiceMatching(%s) failed\n", name); return 1; }

    io_service_t service = IOServiceGetMatchingService(kIOMasterPortDefault, match);
    if (!service) { fprintf(stderr, "request_probe: no matching service for '%s'\n", name); return 1; }

    /* kIOFBUserRequestProbe = 1 (IOKit/graphics/IOGraphicsTypes.h) - the real option bit
     * IOATIR500Accelerator::requestProbe() itself gates on (options & 1). */
    kern_return_t kr = IOServiceRequestProbe(service, 1);
    IOObjectRelease(service);

    printf("request_probe: IOServiceRequestProbe(%s, 1) -> 0x%x\n", name, kr);
    return (kr == KERN_SUCCESS) ? 0 : 1;
}
