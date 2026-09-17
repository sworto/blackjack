#include "graphics.hpp"
#include "textureloader.hpp"
int main()
{
    //SDL initialisation
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cerr << "SDL_Init failed: "
                  << SDL_GetError() << '\n';
        return 1;
    }

    //WindowInitialisation
    SDL_Window* window = SDL_CreateWindow("Blackjack",WIDTH,HEIGHT,SDL_WINDOW_FULLSCREEN);
    if (!window)
    {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << '\n';

        SDL_Quit();
        return 1;
    }

    //Renderer Creation
    SDL_Renderer* renderer = SDL_CreateRenderer(window,nullptr);
    

    //Texture and Framebuffer Creation
    uint32_t framebuffer[WIDTH*HEIGHT];
    SDL_Texture* texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_XRGB8888,SDL_TEXTUREACCESS_STREAMING,WIDTH,HEIGHT);



    //FramebufferResetToBlack
    std::fill(std::begin(framebuffer),std::end(framebuffer),0x000000);
    

    bool running = true;
    int i =0;
    struct texture t1 = readbmp("textures/sampletex3.bmp");

    //Sample Texture Putting
    putTextureAt(framebuffer,t1,0,0);
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
        }

        /*framebuffer[putPixelAt(0,i)]=0x00AA00AA;
        framebuffer[putPixelAt(0,-i)]=0x00AA00AA;
        i++;
        BULLSHIT here and there
        std::fill(std::begin(framebuffer),std::end(framebuffer),t1.buffer[i%t1.buffer.size()]);
        i++;*/

        SDL_UpdateTexture(texture,NULL,framebuffer,WIDTH*sizeof(uint32_t));

        //RendererClearing
        SDL_RenderClear(renderer);

        //TextureRendering
        SDL_RenderTexture(renderer,texture,NULL,NULL);


        //RendererPresentation
        SDL_RenderPresent(renderer);
    }


    //Destruction
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}