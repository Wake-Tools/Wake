/*|| https://wake.tools ||                                          | license | Apache License Version 2.0 |
  | --------------------------------------------------------------------------------------------------+-+++|>
  +-  jit.h
  |---------------------------------------------------------------------------------------------------+-+++|>
  +-  Jit main header
  |
  |-----|--------|---------------------|-----------------------------|--------------------------------+-+++|>
*/
#ifndef HDEF_JIT
#define HDEF_JIT

#include <stdbool.h>
#include <stdint.h>

#undef export
#ifdef _WIN32
    #define export __declspec(dllexport)
#elif defined(__APPLE__) || defined(__ANDROID__)
    #define export __attribute__((visibility("default")))
#else
    #define export
#endif

#ifndef JIT_API_DECL
#define JIT_API_DECL export
#endif
   

#ifdef __TINYC__ 
   #ifndef TCC_NOJIT
   #include <tcclib.h>
   #endif
   
   #define JIT_API_DECL __declspec(dllimport)
#endif

#ifdef __EMSCRIPTEN__
   #define USE_STD_MAIN
   //#define NO_JIT
   #define HAS_ASYNC_LOOP
#endif

#ifndef D_FILE_ID 
   #define D_FILE_ID jit_main
#endif

#ifndef USE_STD_MAIN
   #define main(x,y) export jit_main(x,y)
#endif

#define jit_close() export jit_close()
export bool jit_request_close;

typedef struct jit_handle { uint32_t id; } jit_handle;

JIT_API_DECL jit_handle jit_get_handle(const char* path);
JIT_API_DECL const char* jit_get_content(jit_handle id);
JIT_API_DECL const char* jit_get_metadata(jit_handle id, const char* type);

#endif
