#include <SDL3/SDL.h>
#include <iostream>
#include <algorithm>

#define XRES 1920
#define YRES 1080

#define WIDTH 256
#define HEIGHT 144
#define PLAYERORIGIN_X 0
#define PLAYERORIGIN_Y -20
#define DEALERORIGIN_X 0
#define DEALERORIGIN_Y 40

#define PLAYERBUTTON_X 62
#define PLAYERBUTTON_Y -60


//Defines the button structure for the event loops
struct Button{
    int x;
    int y;   
    bool mouseinside(struct texture ButtTex,int mouseX, int mouseY);
};

uint32_t putPixelAt(int x, int y);

void putTextureAt(uint32_t* framebuffer, struct texture, int x, int y);

void paintbuffer(uint32_t* framebuffer,uint32_t color);