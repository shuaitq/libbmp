#include <cstdio>
#include "src/bmp.h"
const int N=1000;
int main(){
    bmp::bmp a(N,N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            a.set_pixel(i,j,bmp::rgb(i*255.0/N,j*255.0/N,0));
        }
    }
    a.save("out.bmp");
}