#include "bmp.h"

namespace bmp{

    bmp::bmp(uint32_t h,uint32_t w){
        info.size=sizeof(info_header);
        info.height=h;
        info.width=w;
        info.planes=1;
        info.bit_count=sizeof(pixel)*8;
        info.compression=0;
        info.size_image=((w*sizeof(pixel)*8+31)/32)*4*h;
        info.x_pels_per_meter=2835;
        info.y_pels_per_meter=2835;
        info.clr_used=0;
        info.clr_important=0;
        file.type='B'+('M'<<8);
        file.off_bits=sizeof(file_header)+info.size;
        file.size=file.off_bits+info.size_image;
        file.reserved=0;
        pixels=new pixel*[h];
        for(int i=0;i<h;i++){
            pixels[i]=new pixel[(len()/sizeof(pixel))+1];
        }
    }

    bmp::~bmp(){
        for(int i=0;i<height();i++){
            delete [] pixels[i];
        }
        delete [] pixels;
    }

    void bmp::set_pixel(uint32_t x,uint32_t y,pixel v){
        pixels[x][y]=v;
    }

    bool bmp::save(const char *path)const{
        FILE *fp=fopen(path,"wb");
        if(fp==nullptr){
            return false;
        }
        fwrite(&file,sizeof(file_header),1,fp);
        fwrite(&info,sizeof(info_header),1,fp);
        for(int i=0;i<height();i++){
            fwrite(pixels[i],len(),1,fp);
        }
        fclose(fp);
        return true;
    }

    uint32_t bmp::height()const{
        return info.height;
    }

    uint32_t bmp::width()const{
        return info.width;
    }

    uint32_t bmp::len()const{
        return info.size_image/info.height;
    }
}