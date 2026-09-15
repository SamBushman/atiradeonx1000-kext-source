/*
 * MetaClassRegistration.cpp
 *
 * FIXED (issue #1, first real link attempt): every class in this project
 * that derives from OSObject (directly or transitively) declares its
 * constructor/destructor/metaclass machinery via `OSDeclareDefaultStructors`
 * in its own header, but that macro only DECLARES those members - it does
 * not define them. The real, matching definitions come from a second,
 * separate macro, `OSDefineMetaClassAndStructors(ClassName, SuperclassName)`,
 * which must be invoked exactly once per class, normally at file scope in
 * a .cpp file. This project had never once invoked it anywhere - a real,
 * systemic gap invisible to plain per-file syntax checking (`-fsyntax-only`
 * doesn't need these symbols to exist) and only surfaced by a real link
 * attempt: every one of these ten classes' constructors came back as an
 * undefined symbol the moment anything in the project actually
 * instantiated one (`new ATIR500GLContext()` etc., or IOKit's own
 * OSTypeAlloc machinery for the ones nothing here directly `new`s).
 *
 * This is pure IOKit boilerplate wiring - not "content" this project's
 * own decompilation work is about - so it's centralized here in one file
 * covering the whole class hierarchy, rather than split one-per-file to
 * match this project's usual per-topic convention.
 *
 * Real base classes (IOService/IOUserClient) are Apple's own, already
 * correctly metaclass-registered inside the real Kernel.framework - only
 * this project's OWN ten classes need registering here.
 */

#include "../Headers/ATIRadeonX1000.h"
#include "../Headers/IOATIR500Accelerator.h"
#include "../Headers/IOATIR500GLContext.h"
#include "../Headers/ATIR500GLContext.h"
#include "../Headers/IOATIR5002DContext.h"
#include "../Headers/ATIR5002DContext.h"
#include "../Headers/IOATIR500DVDContext.h"
#include "../Headers/ATIR500DVDContext.h"
#include "../Headers/IOATIR500Surface.h"
#include "../Headers/ATIR500Surface.h"

OSDefineMetaClassAndStructors(IOATIR500Accelerator, IOService)
OSDefineMetaClassAndStructors(ATIRadeonX1000, IOATIR500Accelerator)

OSDefineMetaClassAndStructors(IOATIR500GLContext, IOUserClient)
OSDefineMetaClassAndStructors(ATIR500GLContext, IOATIR500GLContext)

OSDefineMetaClassAndStructors(IOATIR5002DContext, IOUserClient)
OSDefineMetaClassAndStructors(ATIR5002DContext, IOATIR5002DContext)

OSDefineMetaClassAndStructors(IOATIR500DVDContext, IOUserClient)
OSDefineMetaClassAndStructors(ATIR500DVDContext, IOATIR500DVDContext)

OSDefineMetaClassAndStructors(IOATIR500Surface, IOUserClient)
OSDefineMetaClassAndStructors(ATIR500Surface, IOATIR500Surface)
