
#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include<SDL.h>
#include<stdio.h>

#include "Keys.h"
#include "Colors.h"



SDL_Event event;//set event variable
SDL_Window* window;//defining the window variable
SDL_Renderer* renderer;//defining the renderer variable

void WindowInit(int x, int y, int WindowWidth, int WindowHeight, const char *Title) {//window initilazation
    SDL_Init(SDL_INIT_VIDEO);//initialize video
    window = SDL_CreateWindow(Title, x, y, WindowWidth, WindowHeight, SDL_WINDOW_SHOWN);//create the window

    //TODO: fix white strip on window when initialized past the screen

    if (!window) {//check if window was initialized
        printf("Window Initialization Failed, Error: %s\n", SDL_GetError());
    }
}

void RendererInit() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);//create renderer
    if (!renderer) {//check if renderer was initialized
        printf("Renderer Creation Failed, Error: %s\n", SDL_GetError());
    }
}

void ClearWindow(color Color) {
    SDL_SetRenderDrawColor(renderer, Color.r, Color.g, Color.b, Color.a);//set the background color
    SDL_RenderClear(renderer);//clear the screen
}

bool KeyiDown(SDL_Keycode KEY) {//check for input
    if (event.type == SDL_KEYDOWN) {
        if (event.key.keysym.sym == KEY) {
            return true;
        }
    }
    return false;
}

bool KeyDown(KEYS key) {//check for input
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    return keystates[key];
}

bool CheckEvent(bool *Running) {
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            *Running = false;//close program
        }
        return true;  // Event was processed
    }
    return false;  // No event available
}

void DrawRect(int x, int y, int width, int height, color rectColor) {//draw rectangle function
    SDL_Rect rect = {x, y, width, height};//create the rectangle based on the function arguments
    SDL_SetRenderDrawColor(renderer, rectColor.r, rectColor.g, rectColor.b, rectColor.a);//set the colors
    SDL_RenderFillRect(renderer, &rect);//fill the rectangle
}

void DrawPixel(int x, int y, color rectColor) {//draw rectangle function
    SDL_Rect rect = {x, y, 1, 1};//create the pixel based on the function arguments
    SDL_SetRenderDrawColor(renderer, rectColor.r, rectColor.g, rectColor.b, rectColor.a);//set the colors
    SDL_RenderFillRect(renderer, &rect);//fill the pixel
}

void DrawScreen() {
    SDL_RenderPresent(renderer);
}

void QuitProgram() {//call this to end the program at the bottom of file
    if (window) SDL_DestroyWindow(window);//destroy the window
    if (renderer) SDL_DestroyRenderer(renderer);//destroy the renderer
    SDL_Quit();//quit the program
}

#endif
