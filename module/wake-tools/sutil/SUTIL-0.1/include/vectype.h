/*|| https://wake.tools ||                                                             || C99 | Wake Alpha ||
  | --------------------------------------------------------------------------------------------------+-+++|>
  +-  The vec.h header file defines C structures that mimic GLSL vector types, such as vec2, vec3, vec4 
      for floating-point vectors and ivec2, ivec3, ivec4 for integer vectors
      
      Define your own vector datatype using: typedef_vector(name, type);
      
      This header provides 2 built-in vectors of type int and float. You may change the type by defining 
      VEC_TYPE or IVEC_TYPE before including this header.
  |---------------------------------------------------------------------------------------------------+-+++|>
*/

#define typedef_vector(name, type)        \
typedef struct {                          \
    union {                               \
        struct {type x, y;};              \
        struct {type r, g;};              \
        struct {type s, t;};              \
    };                                    \
} name##2;                                \
typedef struct {                          \
    union {                               \
        struct {type x, y, z;};           \
        struct {type r, g, b;};           \
        struct {type s, t, p;};           \
    };                                    \
} name##3;                                \
typedef struct {                          \
    union {                               \
        struct {type x, y, z, w;};        \
        struct {type r, g, b, a;};        \
        struct {type s, t, p, q;};        \
    };                                    \
} name##4;                                    

// Default type
#ifndef VEC_TYPE
   #define VEC_TYPE float
#endif
#ifndef IVEC_TYPE
   #define IVEC_TYPE int
#endif

// Reinclude with different types guard
#define VEC_STATIC_ASSERT(cond, msg) typedef char static_assert_##msg[(cond) ? 1 : -1]

#ifdef VECTYPE_VEC_DEFINED
   VEC_STATIC_ASSERT(sizeof(VECTYPE_VEC_DEFINED)  == sizeof(VEC_TYPE), vec_size_reassign_with_different_size);
#endif
#ifdef VECTYPE_IVEC_DEFINED
   VEC_STATIC_ASSERT(sizeof(VECTYPE_IVEC_DEFINED) == sizeof(IVEC_TYPE), ivec_size_reassign_with_different_size);
#endif

#ifndef VECTYPE_VEC_DEFINED
#define VECTYPE_VEC_DEFINED float          
typedef_vector(vec, VEC_TYPE);
#endif
#ifndef VECTYPE_IVEC_DEFINED
#define VECTYPE_IVEC_DEFINED int          
typedef_vector(ivec, IVEC_TYPE);
#endif
