#ifndef RGB_H_
#define RGB_H_

#include <cstdint>

namespace bmp{

    
    class rgba{
    public:
        rgba(uint8_t r,uint8_t g,uint8_t b,uint8_t al);
    private:
        uint8_t blue;
        uint8_t green;
        uint8_t red;
        uint8_t alpha;
    };

    const rgba black(0,0,0,0);
    const rgba white(255,255,255,0);

    class rgb{
    public:
        rgb(uint8_t r,uint8_t g,uint8_t b);
    private:
        uint8_t blue;
        uint8_t green;
        uint8_t red;
    };

}

#endif //RGB_H_