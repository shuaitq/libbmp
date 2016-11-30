#include "rgb.h"

namespace bmp{

    rgba::rgba(uint8_t r,uint8_t g,uint8_t b,uint8_t al):red(r),green(g),blue(b),alpha(al){}

    rgb::rgb(uint8_t r,uint8_t g,uint8_t b):red(r),green(g),blue(b){}

}