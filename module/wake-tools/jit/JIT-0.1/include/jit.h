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

#ifdef __TINYC__ 
   #ifndef TCC_NOJIT
   #include <tcclib.h>
   #endif

   #undef export
   #ifdef _WIN32
       #define export __declspec(dllexport)
   #elif defined(__APPLE__) || defined(__ANDROID__)
       #define export __attribute__((visibility("default")))
   #else
       #define export
   #endif
	#define import 
#endif

#ifdef __EMSCRIPTEN__
   #define USE_STD_MAIN
   //#define NO_JIT
   #define HAS_ASYNC_LOOP
#endif

/*
#ifdef USE_STD_MAIN_NO_ARGS
  #define main() main()
#endif
#ifdef USE_STD_MAIN
 #define main(x,y) main(x,y)
#endif
*/

#ifndef D_FILE_ID 
   #define D_FILE_ID jit_main
#endif

//#if !defined(USE_STD_MAIN_NO_ARGS) && !defined(USE_STD_MAIN)
#ifndef USE_STD_MAIN
   #define main(x,y) export jit_main(x,y)
#endif

#define jit_close() export jit_close()
export bool jit_request_close;


#endif
