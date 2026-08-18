#include "raylib.h"
//#include <iostream>

int main()
{

    const int screenWidth = 1200;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "My first Pong Game");
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
      // Drawing
      BeginDrawing();
      DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, GREEN);
      DrawCircle(600, 400, 20, WHITE);
      DrawRectangle(10, screenHeight/2 - 60, 30, 120, WHITE);
      DrawRectangle(1160, screenHeight/2 - 60, 30, 120, WHITE);
      EndDrawing();
    }

    CloseWindow();
}
