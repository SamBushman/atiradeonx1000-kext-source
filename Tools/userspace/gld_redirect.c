/* gld_redirect.c - issue #64: interpose NSCreateObjectFileImageFromFile() so that when the real
 * CGL/OpenGL.framework machinery tries to load the stock ATIRadeonX1000GLDriver.bundle by its real path,
 * it gets our rebuilt copy's file instead - substituted entirely inside our own test process, nothing
 * written to the system. This is how the rebuilt driver's gldXxx entry points get called with genuinely
 * correct arguments: CGL itself makes every call, exactly as it would against the stock bundle, just
 * against different code behind the path.
 *
 * Confirmed live (vmmap of a paused cgl_probe, otool -L / nm -u of OpenGL.framework): the GL driver
 * plugin loader uses the legacy NSModule bundle API (NSCreateObjectFileImageFromFile + NSLinkModule), NOT
 * dlopen() - a dlopen() interpose here sees nothing, confirmed by an empty redirect log while the driver
 * still loaded.
 *
 * GLD_REDIRECT_FROM / GLD_REDIRECT_TO name the two paths (substring match on FROM, so both the bundle's
 * .bundle path and its Contents/MacOS/<name> executable path are covered without listing both).
 *
 * Build: gcc -dynamiclib -o gld_redirect.dylib gld_redirect.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>
#include <mach-o/dyld.h>
#include <mach-o/getsect.h>
#include <mach-o/loader.h>

static NSObjectFileImageReturnCode (*real_NSCreate)(const char *, NSObjectFileImage *) = NULL;
static const char *g_from = NULL, *g_to = NULL;
static FILE *g_log = NULL;

static NSObjectFileImageReturnCode my_NSCreate(const char *pathName, NSObjectFileImage *objectFileImage) {
    if (!real_NSCreate)
        real_NSCreate = (NSObjectFileImageReturnCode (*)(const char *, NSObjectFileImage *))
            dlsym(RTLD_NEXT, "NSCreateObjectFileImageFromFile");
    if (!g_log) {
        const char *lp = getenv("GLD_REDIRECT_LOG");
        g_log = lp ? fopen(lp, "a") : stderr;
        if (!g_log) g_log = stderr;
        setvbuf(g_log, NULL, _IOLBF, 0);
        g_from = getenv("GLD_REDIRECT_FROM");
        g_to = getenv("GLD_REDIRECT_TO");
    }
    const char *use = pathName;
    if (pathName && g_from && g_to && strstr(pathName, g_from)) {
        use = g_to;
        fprintf(g_log, "gld_redirect: NSCreateObjectFileImageFromFile(\"%s\") -> redirected to \"%s\"\n", pathName, use);
    } else if (pathName) {
        fprintf(g_log, "gld_redirect: NSCreateObjectFileImageFromFile(\"%s\") passthrough\n", pathName);
    }
    NSObjectFileImageReturnCode r = real_NSCreate(use, objectFileImage);
    if (use != pathName) fprintf(g_log, "gld_redirect: NSCreateObjectFileImageFromFile result=%d\n", (int)r);
    return r;
}


/* Experiment for issue #209 (hitch frames): GLD_BINDNOW=1 links the driver with NSLINKMODULE_OPTION_BINDNOW (no lazy symbol binding at first call);
 * GLD_PRETOUCH=1 reads every page of the freshly linked ATIRadeonX1000GLDriver image(s) (__TEXT, __DATA) so first-use code paths do not take page faults mid-frame. */
static NSModule (*real_NSLink)(NSObjectFileImage, const char *, unsigned long) = NULL;
static NSModule my_NSLink(NSObjectFileImage img, const char *moduleName, unsigned long options) {
    if (!real_NSLink) real_NSLink = (NSModule (*)(NSObjectFileImage, const char *, unsigned long)) dlsym(RTLD_NEXT, "NSLinkModule");
    if (getenv("GLD_BINDNOW")) options |= NSLINKMODULE_OPTION_BINDNOW;
    NSModule m = real_NSLink(img, moduleName, options);
    if (getenv("GLD_PRETOUCH")) {
        uint32_t i, n = _dyld_image_count(); unsigned long pages = 0; volatile unsigned long sink = 0;
        for (i = 0; i < n; i++) {
            const char *nm = _dyld_get_image_name(i);
            if (!nm || !strstr(nm, "ATIRadeonX1000GLDriver")) continue;
            const struct mach_header *mh = _dyld_get_image_header(i); unsigned long slide = _dyld_get_image_vmaddr_slide(i);
            const struct load_command *lc = (const struct load_command *)((const char *)mh + sizeof(struct mach_header)); uint32_t c;
            for (c = 0; c < mh->ncmds; c++, lc = (const struct load_command *)((const char *)lc + lc->cmdsize)) {
                if (lc->cmd != LC_SEGMENT) continue;
                const struct segment_command *sc = (const struct segment_command *)lc;
                if (strcmp(sc->segname, "__TEXT") && strcmp(sc->segname, "__DATA")) continue;
                unsigned long a; for (a = sc->vmaddr + slide; a < sc->vmaddr + slide + sc->vmsize; a += 4096) { sink += *(volatile unsigned char *)a; pages++; }
            }
        }
        if (g_log) fprintf(g_log, "gld_redirect: pretouched %lu pages\n", pages);
    }
    return m;
}

typedef struct { void *replacement; void *replacee; } interpose_t;
__attribute__((used))
static const interpose_t interposers[] __attribute__((section("__DATA,__interpose"))) = {
    { (void*)my_NSCreate, (void*)NSCreateObjectFileImageFromFile },
    { (void*)my_NSLink, (void*)NSLinkModule },
};
