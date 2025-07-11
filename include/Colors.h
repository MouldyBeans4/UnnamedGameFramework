#ifndef COLORS_H
#define COLORS_H
#include <SDL_stdinc.h>

typedef struct Color {//making a struct to hold color values
    Uint8 r;
    Uint8 g;
    Uint8 b;
    Uint8 a;
}color;

const color BLACK = {0, 0, 0, 255};
const color WHITE = {255, 255, 255, 255};
const color RED = {200, 0, 0, 255};
const color YELLOW = {255, 255, 0, 255};
const color GREEN = {0, 200, 0, 255};
const color BLUE = {0, 0, 255, 255};
const color PURPLE = {115, 0, 180, 255};
const color ORANGE = {255, 155, 155, 255};
const color BROWN = {120, 60, 0, 255};
const color AQUA = {0, 255, 247, 255};
const color CYAN = {0, 122, 156, 255};
#endif
