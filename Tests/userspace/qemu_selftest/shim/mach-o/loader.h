#include <stdint.h>
struct mach_header { uint32_t magic, cputype, cpusubtype, filetype, ncmds, sizeofcmds, flags; };
struct load_command { uint32_t cmd, cmdsize; };
#define MH_MAGIC 0xfeedface
#define LC_SEGMENT 1
#define LC_SYMTAB 2
#define LC_DYSYMTAB 0xb
struct segment_command { uint32_t cmd, cmdsize; char segname[16]; uint32_t vmaddr, vmsize, fileoff, filesize, maxprot, initprot, nsects, flags; };
struct section { char sectname[16], segname[16]; uint32_t addr, size, offset, align, reloff, nreloc, flags, reserved1, reserved2; };
struct symtab_command { uint32_t cmd, cmdsize, symoff, nsyms, stroff, strsize; };
struct dysymtab_command { uint32_t cmd, cmdsize, ilocalsym, nlocalsym, iextdefsym, nextdefsym, iundefsym, nundefsym, tocoff, ntoc, modtaboff, nmodtab, extrefsymoff, nextrefsyms, indirectsymoff, nindirectsyms, extreloff, nextrel, locreloff, nlocrel; };
#define S_LAZY_SYMBOL_POINTERS 7
#define S_NON_LAZY_SYMBOL_POINTERS 6
#define SECTION_TYPE 0xff
