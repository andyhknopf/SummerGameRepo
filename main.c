/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

float xPos = 0.0f;
float yPos = 0.0f;
float radius = 50.0f;
float velocity = 1000.0f;


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
  // Initialization
  //--------------------------------------------------------------------------------------
  const int screenWidth = 1280;
  const int screenHeight = 720;

  InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

  SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------

  // Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
    /* Update */ 
    if (IsKeyDown(KEY_A))
      xPos -= velocity * GetFrameTime();
    if (IsKeyDown(KEY_D))
      xPos += velocity * GetFrameTime();
    if (IsKeyDown(KEY_W))
      yPos -= velocity * GetFrameTime();
    if (IsKeyDown(KEY_S))
      yPos += velocity * GetFrameTime();

    // TODO: Update your variables here

    /* Graphics and visuals go here */
    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawCircle(xPos, yPos, radius, RED);

    EndDrawing();
  }

  /* De - Initialization */
  CloseWindow();        // Close window and OpenGL context

  return 0;
}