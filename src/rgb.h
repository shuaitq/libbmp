#ifndef RGB_H_
#define RGB_H_

#include <cstdint>

namespace bmp{

    class rgba{
    public:
        rgba(uint8_t r,uint8_t g,uint8_t b,uint8_t al);
    private:
        uint8_t blue,green,red,alpha;
    };

    class rgb{
    public:
        rgb();
        rgb(uint8_t r,uint8_t g,uint8_t b);
    private:
        uint8_t blue,green,red;
    };

}

#endif //RGB_H_