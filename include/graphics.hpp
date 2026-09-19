#include <SDL3/SDL.h>
#include <iostream>
#include <algorithm>

#define WIDTH 256
#define HEIGHT 144
#define PLAYERORIGIN_X 0
#define PLAYERORIGIN_Y HEIGHT-20

uint32_t putPixelAt(int x, int y);

void putTextureAt(uint32_t* framebuffer, struct texture, int x, int y);

void paintbuffer(uint32_t* framebuffer,uint32_t color);