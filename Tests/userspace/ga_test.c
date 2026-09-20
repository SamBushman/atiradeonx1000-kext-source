/* ga_test.c - load the stock GA plug-in and the rebuilt one side by side, compare exports and the pure function _window_mode_to_ati_format over many inputs,
 * and the exported ati_format_info_table bytes. */
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <stdint.h>
typedef unsigned int (*f_t)(unsigned int);
int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    void *a = dlopen(argv[1], RTLD_NOW | RTLD_LOCAL), *b = dlopen(argv[2], RTLD_NOW | RTLD_LOCAL);
    printf("stock dlopen %s, rebuilt dlopen %s\n", a ? "ok" : dlerror(), b ? "ok" : dlerror());
    if (!a || !b) return 1;
    const char *names[] = {"ATIRadeonX1000GAFactory", "_LockSurface", "_Probe", "_SetDestination", "_SetSurface", "_SwapSurface", "_UnlockSurface", "ati_format_info_table", "window_mode_to_ati_format", 0};
    int ok = 1;
    for (int i = 0; names[i]; i++) {
        void *pa = dlsym(a, names[i]), *pb = dlsym(b, names[i]);
        printf("  %-28s stock=%s rebuilt=%s\n", names[i], pa ? "yes" : "no", pb ? "yes" : "no");
        if ((pa != 0) != (pb != 0)) ok = 0;
    }
    f_t fa = (f_t)dlsym(a, "window_mode_to_ati_format"), fb = (f_t)dlsym(b, "window_mode_to_ati_format");
    unsigned long diff = 0, n = 0;
    for (unsigned int v = 0; v < 0x200000; v++) { unsigned int x = v * 2731u ^ (v << 11); n++; if (fa(x) != fb(x)) { if (diff < 5) printf("  DIFF window_mode_to_ati_format(%08x): stock %08x rebuilt %08x\n", x, fa(x), fb(x)); diff++; } }
    for (unsigned int v = 0; v < 0x10000; v++) { n++; if (fa(v) != fb(v)) { if (diff < 5) printf("  DIFF window_mode_to_ati_format(%08x): stock %08x rebuilt %08x\n", v, fa(v), fb(v)); diff++; } }
    printf("window_mode_to_ati_format: %lu inputs, %lu differences\n", n, diff);
    unsigned int *ta = (unsigned int *)dlsym(a, "ati_format_info_table"), *tb = (unsigned int *)dlsym(b, "ati_format_info_table");
    Dl_info da, db; memset(&da, 0, sizeof da); memset(&db, 0, sizeof db);
    dladdr((void *)fa, &da); dladdr((void *)fb, &db);
    unsigned int ba = (unsigned int)da.dli_fbase, bb = (unsigned int)db.dli_fbase;
    int td = ta && tb ? 0 : -1, nptr = 0;
    for (int i = 0; ta && tb && i < 1344 / 4; i++) {
        if (ta[i] == tb[i]) continue;
        /* a pointer word: both point into their own image (here: at the empty string in __cstring); compare what they point at */
        if (ta[i] >= ba && ta[i] < ba + 0x20000 && tb[i] >= bb && tb[i] < bb + 0x40000 && strcmp((const char *)ta[i], (const char *)tb[i]) == 0) { nptr++; continue; }
        if (td < 5) printf("  table word %d differs: stock %08x rebuilt %08x\n", i, ta[i], tb[i]);
        td++;
    }
    printf("ati_format_info_table (1344 bytes): %s (%d pointer words compared by what they point at)\n", td == 0 ? "identical" : "DIFFERENT", nptr);
    printf("RESULT: %s\n", (ok && diff == 0 && td == 0) ? "PASS" : "FAIL");
    return (ok && diff == 0 && td == 0) ? 0 : 2;
}
