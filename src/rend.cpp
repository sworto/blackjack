#include "graphics.hpp"
#include "textureloader.hpp"
#include "logic.hpp"
void ShowCardList(uint32_t* framebuffer,std::vector<card> &cards,std::vector<texture> &texturelist,int  x, int y){
    int increment = texturelist[1].width/2;
    int totalcount = cards.size();
    int start = x-totalcount/2*increment;
    for(int i=0;i<totalcount;i++){
        putTextureAt(framebuffer,texturelist[cards[i].weight],start+i*increment,y);
    }
    return;
}
int main()
{
    //Texture Loading
    std::vector<texture> texturelist;
    texturelist.push_back(readbmp("textures/background.bmp"));
    texturelist.push_back(readbmp("textures/cards/playing-card-1.bmp"));
    texturelist.push_back(readbmp("textures/cards/playing-card-2.bmp"));
    texturelist.push_back(readbmp("textures/cards/playing-card-3.bmp"));
    texturelist.push_back(readbmp("textures/cards/playing-card-4.bmp"));
    texturelist.push_back(readbmp("textures/cards/playing-card-5.bmp"));
    texturelist.push_back(readbmp("textures/cards/playing-card-6.bmp"));
    texturelist.push_back(readbmp("textures/cards/playing-card-7.bmp"));
    texturelist.push_back(readbmp("textures/cards/playing-card-8.bmp"));
    texturelist.push_back(readbmp("textures/cards/playing-card-9.bmp"));
    texturelist.push_back(readbmp("textures/cards/playing-card-10.bmp"));
    texturelist.push_back(readbmp("textures/cards/playingcard.bmp"));
    texturelist.push_back(readbmp("textures/cards/playingcard.bmp"));
    texturelist.push_back(readbmp("textures/cards/playingcard.bmp"));
    texturelist.push_back(readbmp("textures/buttons/gameoptions.bmp"));

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
    //Texture Scaling
    SDL_SetTextureScaleMode(texture,SDL_SCALEMODE_NEAREST);

    //FramebufferBackgroundSetup
    paintbuffer(framebuffer,0xFFFFFF);
    putTextureAt(framebuffer,texturelist[0],0,0);
    Button b1;
    b1.x=0;
    b1.y=0;
    putTextureAt(framebuffer,texturelist[14],b1.x,b1.y);
    //Game Logic Initialisation
    std::vector<struct card> dealer;
    std::vector<struct card> player;

    //Player Choice: 
    std::string choice;
    bool running = true;

    ShowCardList(framebuffer,dealer,texturelist,DEALERORIGIN_X,DEALERORIGIN_Y);
    while(running&&choice!="stand"){
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT)
            {
                running = false;
            }
            if(event.type == SDL_EVENT_MOUSE_BUTTON_DOWN){
                if(event.button.button == SDL_BUTTON_LEFT){
                    std::cout << "Lclick" << std::endl;
                    if(b1.mouseinside(texturelist[14],event.button.x,event.button.y)){
                        std::cout << "X: " << event.button.x << "Y: " << event.button.y << std::endl;
                        player.push_back(generatelog());
                    }
                }
            }
        }

        //Render Area
        ShowCardList(framebuffer,player,texturelist,PLAYERORIGIN_X,PLAYERORIGIN_Y);

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