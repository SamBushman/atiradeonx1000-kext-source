#include <stdio.h>
#include <dlfcn.h>
#include <OpenGL/OpenGL.h>
int main(void){
    void *h = dlopen("/System/Library/Frameworks/OpenGL.framework/OpenGL", RTLD_LAZY);
    printf("dlopen = %p\n", h);
    void *p1 = dlsym(h, "glActiveMatrixARB");
    void *p2 = dlsym(h, "glWeightfARB");
    void *p3 = dlsym(h, "glVertexBlendARB");
    printf("glActiveMatrixARB = %p\n", p1);
    printf("glWeightfARB = %p\n", p2);
    printf("glVertexBlendARB = %p\n", p3);
    return 0;
}
