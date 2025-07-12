cmake_minimum_required(VERSION 3.10)
project(GameFramework C)

set(CMAKE_C_STANDARD 23)

add_executable(GameFramework
        src/main.c
)

#include files
target_include_directories(GameFramework PRIVATE
        "C:/CLibrarys/SDL/SDL2/x86_64-w64-mingw32/include/SDL2"
        "C:/CLibrarys/SDL/SDL2_image/x86_64-w64-mingw32/include/SDL2"
        "C:/CLibrarys/SDL/SDL2_mixer/x86_64-w64-mingw32/include/SDL2"
        "C:/CLibrarys/SDL/SDL2_ttf/x86_64-w64-mingw32/include/SDL2"
        "include"
        "${SOURCE_DIR}"
)

#linker files
target_link_directories(GameFramework PRIVATE
        "C:/CLibrarys/SDL/SDL2/x86_64-w64-mingw32/lib"
        "C:/CLibrarys/SDL/SDL2_Image/x86_64-w64-mingw32/lib"
        "C:/CLibrarys/SDL/SDL2_mixer/x86_64-w64-mingw32/lib"
        "C:/CLibrarys/SDL/SDL2_ttf/x86_64-w64-mingw32/lib"
)

target_link_libraries(GameFramework PRIVATE
        mingw32
        SDL2main
        SDL2
        SDL2_image
        SDL2_mixer
        SDL2_ttf
)

