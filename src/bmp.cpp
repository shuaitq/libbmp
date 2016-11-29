#include "bmp.h"

namespace bmp{

    rgb::rgb(uint8_t r,uint8_t g,uint8_t b,uint8_t al):red(r),green(g),blue(b),alpha(al){}

    bmp::bmp():height(0),width(0),pixels(nullptr){}
    
    bmp::bmp(int h,int w):height(h),width(w){
        pixels=new pixel*[h];
        for(int i=0;i<h;i++){
            pixels[i]=new pixel[w];
        }
    }

    bmp::~bmp(){
        for(int i=0;i<height;i++){
            delete [] pixels[i];
        }
        delete [] pixels;
    }

    void bmp::set_pixel(int x,int y,pixel v){
        pixels[x][y]=v;
    }

    pixel bmp::get_pixel(int x,int y){
        return pixels[x][y];
    }

    bool bmp::save(const char *path){
        file_header file_header;
        info_header info_header;
        info_header.size=sizeof(info_header);
        info_header.height=height;
        info_header.width=width;
        info_header.planes=1;
        info_header.bit_count=1;
        info_header.compression=0;
        info_header.size_image=((width+31)/32)*4*height;
        info_header.x_pels_per_meter=2835;
        info_header.y_pels_per_meter=2835;
        info_header.clr_used=0;
        info_header.clr_important=0;
        int n_bits_offset=sizeof(file_header)+info_header.size+sizeof(rgb)*2;
        long l_image_size=info_header.size_image;
        long l_file_size=n_bits_offset+l_image_size;
        file_header.type='B'+('M'<<8);
        file_header.off_bits=n_bits_offset;
        file_header.size=l_file_size;
        file_header.reserved=0;
        FILE *fd=nullptr;
        fd=fopen(path,"wb");
        fwrite(&file_header,1,sizeof(file_header),fd);
        fwrite(&info_header,1,sizeof(info_header),fd);
        fwrite(&black,1,sizeof(rgb),fd);
        fwrite(&white,1,sizeof(rgb),fd);
        unsigned char temp;
        for(int i=0;i<height;i++){
            for(int j=0;j<((width+31)/32)*4;j++){
                temp=0;
                for(int k=0;k<8;k++){
                    temp*=2;
                    if(j*8+k<width){
                        if(pixels[i][j*8+k]==true){
                            temp+=1;
                        }
                    }
                }
                fwrite(&temp,sizeof(char),1,fd);
            }
        }
        fclose(fd);
    }

}