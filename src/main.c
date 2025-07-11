#include <stdio.h>
#include "FrameWork.h"
int main() {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    float x = 100.0f;
    float y = 100.0f;
    float velX = 10.0f;
    float velY = 10.0f;

    WindowInit(100, 50, SCREEN_WIDTH, SCREEN_HEIGHT, "Title Test");//initialize the window
    RendererInit();//initialize the renderer

    bool running = true;

    while (running) {//gane loop
        while (CheckEvent(&running)) {
            //handle events like quitting
        }
        if (KeyDown(KEY_A)) {//check for input
            y += velY;
        }

        ClearWindow(BLACK);//clear the screen and set it to black
        DrawCircle(x, y, 50, RED);//draw a circle
        DrawScreen();//draw everything on the screen
        SDL_Delay(16);
    }
    QuitProgram();//end the program
    return 0;
}