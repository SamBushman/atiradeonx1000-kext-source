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

typedef struct { void *replacement; void *replacee; } interpose_t;
__attribute__((used))
static const interpose_t interposers[] __attribute__((section("__DATA,__interpose"))) = {
    { (void*)my_NSCreate, (void*)NSCreateObjectFileImageFromFile },
};
