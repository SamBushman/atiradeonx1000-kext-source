#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
typedef void *(*create_t)(unsigned);
typedef void (*attach_t)(void *, const char *, int);
typedef int (*f1_t)(void *);
typedef void *(*mk_t)(void);
typedef void (*ast_t)(void *, void *);
int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IONBF, 0);
    void *h[2] = { dlopen(argv[1], RTLD_NOW), dlopen(argv[2], RTLD_NOW) };
    unsigned vlim[15] = { 0x100, 0x100, 8, 0x8000, 0x100, 0x100, 0x20, 2, 8, 0x10, 4, 1, 6, 8, 0x10 };
    const char *progs[] = {
      "!!ARBvp1.0\nTEMP t;\nEND\n",
      "!!ARBvp1.0\nATTRIB p = vertex.position;\nEND\n",
      "!!ARBvp1.0\nPARAM c = {1, 2, 3, 4};\nEND\n",
      "!!ARBvp1.0\nOUTPUT o = result.position;\nEND\n",
      "!!ARBvp1.0\nMOV result.position, vertex.position;\nEND\n",
      "!!ARBvp1.0\nMOV result.color, vertex.color;\nEND\n",
      "!!ARBvp1.0\nTEMP t;\nMOV t, vertex.position;\nEND\n",
      0 };
    for (int pi = 0; progs[pi]; pi++) { const char *prog = progs[pi]; printf("== %s", prog);
    for (int k = 0; k < 2; k++) {
        create_t cr = dlsym(h[k], "PPParserCreate"); attach_t at = dlsym(h[k], "PPParserAttachString");
        f1_t ver = dlsym(h[k], "PPParserParseVersion"), opt = dlsym(h[k], "PPParserParseOption"), gc = dlsym(h[k], "PPParserGetCharacter");
        mk_t mk = dlsym(h[k], "PPStreamCreate"); ast_t ast = dlsym(h[k], "PPParserAttachStream");
        void *p = cr(0); void *st = mk(); ast(p, st); memcpy((char *)p + 0x450, vlim, 0x3c);
        at(p, prog, 1);
        unsigned *w = (unsigned *)p;
        if(0)printf("[%s] after attach: text=%.24s len=%u lines=%u\n", k ? "rebuilt" : "stock", *(char **)p ? *(char **)p : "(null)", w[1], w[2]);
        ver(p);
        f1_t stmt = dlsym(h[k], "PPParserParseStatement");
        int r = 0, cnt = 0; while ((r = opt(p)) == 0 && cnt++ < 20) (void)0;
        
        cnt = 0; while ((r = stmt(p)) == 0 && cnt++ < 20) (void)0;
        printf("   [%s] ParseStatement -> %d\n", k ? "rebuilt" : "stock  ", r);
    }}
    return 0;
}
