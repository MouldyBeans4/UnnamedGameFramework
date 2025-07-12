
#ifndef FRAMEWORK_H
#define FRAMEWORK_H
#include<SDL.h>
#include<SDL_ttf.h>
#undef main
#include<stdio.h>


#include "Keys.h"
#include "Colors.h"



SDL_Event event;//set event variable
SDL_Window* window;//defining the window variable
SDL_Renderer* renderer;//defining the renderer variable







void WindowInit(int x, int y, int WindowWidth, int WindowHeight, const char *Title) {//window initialization
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Video Initialization Error: %s\n", SDL_GetError());
    }
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

//TODO: add a SetFPS function

void SetFPS(float FPS) {
    float MS = 1000 / FPS;
    SDL_Delay(MS);
}

float DeltaTime() {
    static Uint32 lastTime = 0;
    Uint32 currentTime = SDL_GetTicks();//MS since window init

    if (lastTime == 0) {
        lastTime = currentTime;
        return 0.016f; //return 60 FPS for first frame
    }

    Uint32 deltaMs = currentTime - lastTime;
    lastTime = currentTime;

    return deltaMs / 1000.0f;//convert ms to seconds
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

void DrawCircle(int cx, int cy, int radius, color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        // Draw horizontal lines between symmetric points
        SDL_RenderDrawLine(renderer, cx - x, cy + y, cx + x, cy + y);
        SDL_RenderDrawLine(renderer, cx - y, cy + x, cx + y, cy + x);
        SDL_RenderDrawLine(renderer, cx - x, cy - y, cx + x, cy - y);
        SDL_RenderDrawLine(renderer, cx - y, cy - x, cx + y, cy - x);

        y++;
        if (err <= 0) {
            err += 2 * y + 1;
        } else {
            x--;
            err += 2 * (y - x + 1);
        }
    }
}

void DrawPixel(int x, int y, color rectColor) {//draw rectangle function
    SDL_Rect rect = {x, y, 1, 1};//create the pixel based on the function arguments
    SDL_SetRenderDrawColor(renderer, rectColor.r, rectColor.g, rectColor.b, rectColor.a);//set the colors
    SDL_RenderFillRect(renderer, &rect);//fill the pixel
}

void DestroyText() {

}

void DrawScreen() {
    SDL_RenderPresent(renderer);
}

void EndProgram() {//call this to end the program at the bottom of file
    if (window) SDL_DestroyWindow(window);//destroy the window
    if (renderer) SDL_DestroyRenderer(renderer);//destroy the renderer
    if (TTF_Init)TTF_Quit();
    SDL_Quit();//quit the program
}

#endif
