/*|| https://wake.tools ||                                          | license | Apache License Version 2.0 |
  | --------------------------------------------------------------------------------------------------+-+++|>
  +-  common.h
  |---------------------------------------------------------------------------------------------------+-+++|>
  +-  Common Utilities
  |
  |-----|--------|---------------------|-----------------------------|--------------------------------+-+++|>
*/

#include <Xternal.h>

fn void show_errors();
fn void stop_assert();

#include <assert.h>
#define SOKOL_ASSERT(expr) if(!(expr)){ _assertErr((char*)#expr);};
#define IM_ASSERT(expr) do {if(!(expr)){ _assertErr((char*)#expr);};} while (0)
#define IM_ASSERT_USER_ERROR(_EXP,_MSG) IM_ASSERT((_EXP) && _MSG)   // Recoverable User Error

///////////////////////

//!-- Read note --
// Check user IM_ASSERT macro
// (IF YOU GET A WARNING OR COMPILE ERROR HERE: it means your assert macro is incorrectly defined!
//  If your macro uses multiple statements, it NEEDS to be surrounded by a 'do { ... } while (0)' block.
//  This is a common C/C++ idiom to allow multiple statements macros to be used in control flow blocks.)
// #define IM_ASSERT(EXPR)   if (SomeCode(EXPR)) SomeMoreCode();                    // Wrong!
// #define IM_ASSERT(EXPR)   do { if (SomeCode(EXPR)) SomeMoreCode(); } while (0)   // Correct!
//if (true) IM_ASSERT(1); else IM_ASSERT(0);
//!-----------