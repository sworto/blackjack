#include <SDL3/SDL.h>
#include <iostream>
#include <algorithm>

#define WIDTH 1920
#define HEIGHT 1080

uint32_t putPixelAt(int x, int y);

void putTextureAt(uint32_t* framebuffer, struct texture, int x, int y);
