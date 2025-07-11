#include <stdio.h>
#include "FrameWork.h"
int main(int argc, char* args[]) {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;


    int x = 100;
    int y = 100;

    WindowInit(100, 50, SCREEN_WIDTH, SCREEN_HEIGHT, "Title Test");
    RendererInit();

    bool running = true;

    while (running) {
        while (CheckEvent(&running)) {
        }
            if (KeyDown(KEY_W)) {
                y -= 10.0f;
            }
            if (KeyDown(KEY_S)) {
                y += 10.0f;
            }
            if (KeyDown(KEY_A)) {
                x -= 10.0f;
            }
            if (KeyDown(KEY_D)) {
                x += 10.0f;
            }

        ClearWindow(BLACK);
        DrawRect(x, y, 50, 50, RED);
        DrawScreen();
        SDL_Delay(16);
    }
    QuitProgram();
    return 0;
}