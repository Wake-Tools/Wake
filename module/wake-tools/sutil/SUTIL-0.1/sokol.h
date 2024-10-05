#define SOKOL_GLUE_IMPL
#include "sokol_gfx.h"
#include "sokol_app.h"
#include "sokol_glue.h"

#ifdef USE_DBG_UI
#include "sokol_imgui.h" 
#include "cdbgui.h"
#else
#define __cdbgui_setup(x)
#define __cdbgui_draw()
#define __cdbgui_shutdown()
#define __cdbgui_event 0
#endif
