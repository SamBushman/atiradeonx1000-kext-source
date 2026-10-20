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
#include "../Headers/IOATIR500Shared.h"
#include "../Headers/ATIR500Memory.h"

/*
 * IOATIR500Accelerator and IOATIR500Surface use the "AndAbstractStructors"
 * variant (issue #1, get-it-linking pass): both now declare real pure
 * virtuals (confirmed genuine base-class placeholder slots - no real
 * base body exists, only the concrete subclass overrides), which makes
 * them genuinely abstract - the plain `OSDefineMetaClassAndStructors`
 * macro generates a real `MetaClass::alloc()` that calls `new
 * ClassName()`, which cannot compile against an abstract class. This is
 * Apple's own real, standard IOKit macro for exactly this situation.
 */
/*
 * OSDefineMetaClassAndStructors, except that MetaClass::alloc() tests the allocation before running the constructor, as the shipped code does
 * (`OSObject::operator new; if (p) construct`). The stock macro's `return new className;` compiles under gcc 4.0.1 -fapple-kext to an unconditional
 * constructor call, which writes through a null `this` when OSObject::operator new fails (the #187 bug class; difftest: MetaClass::alloc cases).
 */
inline void *operator new(size_t, void *where) { return where; }
#define ATI_DefineMetaClassAndStructors(className, superClassName)		\
    OSDefineMetaClass(className, superClassName)				\
    OSObject * className ::MetaClass::alloc() const				\
	{ void *mem = OSObject::operator new(sizeof(className));		\
	  return mem ? ::new (mem) className() : 0; }				\
    className :: className () : superClassName (&gMetaClass)			\
	{ gMetaClass.instanceConstructed(); }

OSDefineMetaClassAndAbstractStructors(IOATIR500Accelerator, IOAccelerator)
ATI_DefineMetaClassAndStructors(ATIRadeonX1000, IOATIR500Accelerator)

OSDefineMetaClassAndAbstractStructors(IOATIR500GLContext, IOUserClient)
ATI_DefineMetaClassAndStructors(ATIR500GLContext, IOATIR500GLContext)

OSDefineMetaClassAndAbstractStructors(IOATIR5002DContext, IOUserClient)
ATI_DefineMetaClassAndStructors(ATIR5002DContext, IOATIR5002DContext)

OSDefineMetaClassAndAbstractStructors(IOATIR500DVDContext, IOUserClient)
ATI_DefineMetaClassAndStructors(ATIR500DVDContext, IOATIR500DVDContext)

OSDefineMetaClassAndAbstractStructors(IOATIR500Surface, IOUserClient)
ATI_DefineMetaClassAndStructors(ATIR500Surface, IOATIR500Surface)

/*
 * IOATIR500Shared and ATIR500Memory are plain OSObject subclasses (issue #58
 * follow-up: previously modelled as non-OSObject classes, which left their
 * metaclass globals and OSObject constructor/init calls unresolved).
 */
ATI_DefineMetaClassAndStructors(IOATIR500Shared, OSObject)
ATI_DefineMetaClassAndStructors(ATIR500Memory, OSObject)
