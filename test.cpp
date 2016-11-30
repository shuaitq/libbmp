#include <cstdio>
#include "src/bmp.h"
const int N=10000;
int main(){
    bmp::bmp a(N,N);
    for(int i=0;i<N;i++){
        a.set_pixel(i,i,1);
    }
    a.save("out.bmp");
    /*a.read("out.bmp");
    bmp::bmp b;
    b.read("out.bmp");
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            bmp::pixel c=b.get_pixel(100,100);
            printf("%d",c);
        }
        printf("\n");
    }*/
}