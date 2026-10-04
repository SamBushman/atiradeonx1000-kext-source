/* vram_peek.c - issue #140 read-back probe: does CGDisplayBaseAddress give a CPU mapping of the video memory aperture that covers offsets like 0x08ed0000?
 * READ-ONLY (no write, no display capture). Run in the console session. Prints base/rowbytes/size and samples; compares the first pixels with what the screen shows. */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
static sigjmp_buf jb;
static void onfault(int sig) { siglongjmp(jb, 1); }
#include <ApplicationServices/ApplicationServices.h>
int main(int argc, char **argv) {
    CGDirectDisplayID d = CGMainDisplayID(); unsigned *p = (unsigned *)CGDisplayBaseAddress(d); unsigned long i, off;
    printf("display=%p base=%p rowbytes=%lu bpp=%lu w=%lu h=%lu visible=%lu bytes\n", d, p, (unsigned long)CGDisplayBytesPerRow(d), (unsigned long)CGDisplayBitsPerPixel(d), (unsigned long)CGDisplayPixelsWide(d), (unsigned long)CGDisplayPixelsHigh(d), (unsigned long)CGDisplayBytesPerRow(d) * CGDisplayPixelsHigh(d));
    if (!p) { printf("NULL base (display not captured?)\n"); return 1; }
    printf("first 8 words: "); for (i = 0; i < 8; i++) printf("%08x ", p[i]); printf("\n");
    signal(SIGSEGV, onfault); signal(SIGBUS, onfault);
    for (i = 1; i < argc; i++) {
        off = strtoul(argv[i], NULL, 0); printf("offset 0x%08lx: ", off); fflush(stdout);
        if (sigsetjmp(jb, 1) == 0) { volatile unsigned *q = (volatile unsigned *)((char *)p + off); int k; for (k = 0; k < 8; k++) printf("%08x ", q[k]); printf("\n"); }
        else printf("FAULT (not mapped)\n");
        fflush(stdout);
    }
    return 0;
}
