cmake_minimum_required(VERSION 3.16)

project(blackjack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(gamelogic

    libs/logic.cpp
)

add_executable(engine
    src/main.cpp
)

target_include_directories(gamelogic
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(engine
    PRIVATE
        gamelogic
)