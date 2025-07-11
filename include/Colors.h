#ifndef COLORS_H
#define COLORS_H
#include <SDL_stdinc.h>

typedef struct Color {//making a struct to hold color values
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
}color;




const color GREEN = {0, 255, 0, 255};//creating some reusable colors
const color RED = {255, 0, 0, 255};
const color BLUE = {0, 0, 255, 255};
const color PURPLE = {255, 0, 255, 255};
const color ORANGE = {255, 155, 155, 255};
const color BLACK = {0, 0, 0, 255};
const color WHITE = {255, 255, 255, 255};
#endif
