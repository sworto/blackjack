#include "graphics.hpp"
#include "textureloader.hpp"

uint32_t putPixelAt(int x, int y){
    uint32_t zerX = WIDTH/2;
    uint32_t zerY = HEIGHT/2;

    x%=WIDTH/2;
    y%=HEIGHT/2;

    x+=zerX;
    y+=zerY;

    return (HEIGHT-1-y)*WIDTH+x;
}


void putTextureAt(uint32_t* framebuffer,struct texture Tex, int x, int y){
    for(int i=0;i<Tex.height;i++){
        for(int j=0;j<Tex.width;j++){
            framebuffer[putPixelAt(x+i,y+j)] = Tex.buffer[i+j*Tex.width];
        }
    }
    return;
}