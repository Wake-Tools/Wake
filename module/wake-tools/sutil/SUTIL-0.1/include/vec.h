/*|| https://wake.tools ||                                                           || JIT C | Wake Alpha ||
  | --------------------------------------------------------------------------------------------------+-+++|>
  +-  Vector function utility                                                                    || @ Maeiky  ||
  |---------------------------------------------------------------------------------------------------+-+++|>
*/
#include "vectype.h"

typedef num VEC_TYPE;

num angle2v(vec2 _pt1, vec2 _pt2) {
   return atan2(_pt1.x - _pt2.x,_pt1.y - _pt2.y);
}

