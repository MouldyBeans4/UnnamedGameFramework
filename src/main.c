#include <stdio.h>
#include "FrameWork.h"

struct Player {
    int width, height;
    float x, y;
    float speed;
};

struct Ball {
    float x, y;
    float velX, velY;
    int width, height;
};

int main() {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;

    WindowInit(100, 50, SCREEN_WIDTH, SCREEN_HEIGHT, "Title Test");//initialize the window
    RendererInit();//initialize the renderer

    struct Ball ball;//variables for the ball
    ball.x = SCREEN_WIDTH / 2;
    ball.y = SCREEN_HEIGHT / 2;
    ball.velX = 250.0f;
    ball.velY = 250.0f;
    ball.width = 15;
    ball.height = 15;

    struct Player p1;//variables for player 1
    p1.width = 5;
    p1.height = 200;
    p1.x = 10.0f;
    p1.y = SCREEN_HEIGHT / 2 - p1.height / 2;
    p1.speed = 250.0f;

    struct Player p2;//variables for player 2
    p2.height = 200;
    p2.speed = 250.0f;
    p2.x = SCREEN_WIDTH - 10.0f;
    p2.y = SCREEN_HEIGHT / 2 - p2.height / 2;
    p2.width = 5;

    float dt = DeltaTime();//creating the delta time variable

    bool running = true;
    while (running) {//game loop
        while (CheckEvent(&running)) {//handle events like quitting
            if (ball.x >= SCREEN_WIDTH) {
                running = false;
            }//check for collisions with left/right sides
            if (ball.x < 0) {
                running = false;
            }
        }
        ball.x += ball.velX * dt;//increase the balls x and y position
        ball.y += ball.velY * dt;

        if (ball.y > SCREEN_HEIGHT) {
            ball.velY = -ball.velY;
        }//check for top/bottom collision
        if (ball.y < 0) {
            ball.velY = -ball.velY;
        }


        if (ball.x + ball.width <= p1.x + 20 && ball.y > p1.y && ball.y < p1.y + p1.height) {//ball collision with player 1
            ball.velX = -ball.velX;
        }
        if (ball.x + ball.width >= p2.x && ball.y > p2.y && ball.y < p2.y + p2.height) {//ball collision with player 2
            ball.velX = -ball.velX;
        }


        if (KeyDown(KEY_W)) {//checking for inputs
            p1.y -= p1.speed * dt;
        }
        if (p1.y < 0) {
            p1.y = 0;
        }

        if (KeyDown(KEY_S)) {
            p1.y += p1.speed * dt;
        }
        if (p1.y + p1.height > SCREEN_HEIGHT) {
            p1.y = SCREEN_HEIGHT - p1.height;
        }

        if (KeyDown(KEY_UP)) {
            p2.y -= p2.speed * dt;
        }
        if (p2.y < 0) {
            p2.y = 0;
        }

        if (KeyDown(KEY_DOWN)) {
            p2.y += p2.speed * dt;
        }
        if (p2.y + p2.height > SCREEN_HEIGHT) {
            p2.y = SCREEN_HEIGHT - p2.height;
        }


        ClearWindow(BLACK);//clear the screen and set it to black
        DrawRect(ball.x, ball.y, ball.width, ball.height, WHITE);//draw a circle
        DrawRect(p1.x, p1.y, p1.width, p1.height, WHITE);//draw player 1
        DrawRect(p2.x, p2.y, p2.width, p2.height, WHITE);//draw player 2
        DrawScreen();//draw everything on the screen
        SetFPS(50);//set the fps to 50
    }
    EndProgram();//end the program
    return 0;
}