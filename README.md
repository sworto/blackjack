# blackjack
A game of Blackjack


Library Arrangement: 
├── build
│   ├── CMakeCache.txt
│   ├── cmake_install.cmake
│   ├── compile_commands.json
│   ├── engine
│   ├── libgamelogic.a
│   ├── librenderer.a
│   ├── libtextureloader.a
│   ├── Makefile
│   └── rend
├── CMakeLists.txt
├── include
│   ├── graphics.hpp
│   ├── logic.hpp
│   └── textureloader.hpp
├── libs
│   ├── graphics.cpp
│   ├── logic.cpp
│   └── textureloader.cpp
├── README.md
├── src
│   ├── main.cpp
│   └── rend.cpp
└── textures
    ├── background.bmp
    ├── buttons
    │   ├── gameoptions.bmp
    │   ├── hitbutton.bmp
    │   └── standbutton.bmp
    └── cards
        ├── playing-card-10.bmp
        ├── playing-card-1.bmp
        ├── playing-card-2.bmp
        ├── playing-card-3.bmp
        ├── playing-card-4.bmp
        ├── playing-card-5.bmp
        ├── playing-card-6.bmp
        ├── playing-card-7.bmp
        ├── playing-card-8.bmp
        ├── playing-card-9.bmp
        └── playingcard.bmp

dir/build: contains the built binaries
dir/include: contains the cpp headers
dir/libs: contaisn the libraries for the respective headers
dir/src/* : contains the source main file for the game
dir/textures: contains the bitmap images associated with buttons and cards (so far)
