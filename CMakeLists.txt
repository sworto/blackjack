cmake_minimum_required(VERSION 3.16)

find_package(SDL3 REQUIRED CONFIG)

project(blackjack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(gamelogic
    libs/logic.cpp
)

add_library(renderer
    libs/graphics.cpp
)

add_library(textureloader
    libs/textureloader.cpp
)

add_executable(engine
    src/main.cpp
)

add_executable(rend
    src/rend.cpp
)

target_include_directories(gamelogic
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(renderer
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(textureloader
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(engine
    PRIVATE
        gamelogic
)

target_link_libraries(rend
    PRIVATE
        renderer
        textureloader
        SDL3::SDL3
)