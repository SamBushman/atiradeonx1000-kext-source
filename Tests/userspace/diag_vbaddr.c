/* diag_vbaddr.c - which GL_ARB_vertex_blend entry points does the OpenGL framework export? (#138)
 * glActiveMatrixARB and glWeightfARB are NOT part of the extension (it has only the vector weight forms
 * glWeight{b,s,i,f,d,ub,us,ui}vARB, glWeightPointerARB and glVertexBlendARB; matrices are selected with
 * glMatrixMode(GL_MODELVIEWn_ARB)), so a NULL for those two is expected. The real entry points must all resolve. */
#include <stdio.h>
#include <dlfcn.h>
#include <OpenGL/OpenGL.h>
int main(void){
    static const char *names[] = {
        "glWeightbvARB", "glWeightsvARB", "glWeightivARB", "glWeightfvARB", "glWeightdvARB",
        "glWeightubvARB", "glWeightusvARB", "glWeightuivARB", "glWeightPointerARB", "glVertexBlendARB",
        "glActiveMatrixARB", "glWeightfARB", 0
    };
    int i, missing = 0;
    void *h = dlopen("/System/Library/Frameworks/OpenGL.framework/OpenGL", RTLD_LAZY);
    printf("dlopen = %p\n", h);
    for (i = 0; names[i]; i++) {
        void *p = dlsym(h, names[i]);
        int real = i < 10;
        printf("%-20s = %p  (%s)%s\n", names[i], p, real ? "in ARB_vertex_blend" : "NOT in any spec; NULL expected",
               (real && !p) ? "   <-- MISSING" : "");
        if (real && !p) missing++;
    }
    printf("RESULT: %s (%d of the 10 ARB_vertex_blend entry points missing)\n", missing ? "FAIL" : "PASS", missing);
    return missing != 0;
}
