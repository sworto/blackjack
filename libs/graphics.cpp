#include "graphics.hpp"
#include "textureloader.hpp"

uint32_t putPixelAt(int x, int y){
    x+=WIDTH/2;
    y+=HEIGHT/2;

    x%=WIDTH;
    y%=HEIGHT;

    y=HEIGHT-y-1;

    return x+y*WIDTH;
}
/*Paint Render Logic

*/
void paintbuffer(uint32_t* framebuffer,uint32_t color){
    std::fill(framebuffer,framebuffer+WIDTH*HEIGHT,color);
    return;
}


void putTextureAt(uint32_t* framebuffer,struct texture Tex, int x, int y){
    for(int i=0;i<Tex.height;i++){
        for(int j=0;j<Tex.width;j++){
            framebuffer[putPixelAt(x+i-Tex.height/2,y+j-Tex.width/2)] = Tex.buffer[i+j*Tex.width];
        }
    }
    return;
}