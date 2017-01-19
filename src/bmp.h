#ifndef BMP_H_
#define BMP_H_

#include <cstdint>
#include <cstdio>
#include "rgb.h"
#pragma pack(2)

namespace bmp{

    using pixel=rgb;

    struct file_header{
        uint16_t type;
        uint32_t size;
        uint32_t reserved;
        uint32_t off_bits;
    };

    struct info_header{
        uint32_t size;
        uint32_t width;
        uint32_t height;
        uint16_t planes;
        uint16_t bit_count;
        uint32_t compression;
        uint32_t size_image;
        uint32_t x_pels_per_meter;
        uint32_t y_pels_per_meter;
        uint32_t clr_used;
        uint32_t clr_important;
    };

    class bmp{
    public:
        bmp(uint32_t h,uint32_t w);
        ~bmp();
        void set_pixel(uint32_t x,uint32_t y,pixel v);
        bool save(const char *path)const;
        uint32_t height()const;
        uint32_t width()const;
    private:
        file_header file;
        info_header info;
        uint32_t len()const;
        pixel **pixels;
    };

}

#endif //BMP_H_