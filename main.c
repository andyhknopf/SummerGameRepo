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

//header links
#include "raylib.h"
#include "helper.h"
#include "init.h"
#include "collision.h"

int mouseX;
int mouseY;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
  // Initialization
  //--------------------------------------------------------------------------------------
  struct Rectangle box1;
  Color boxColor = GREEN;
  box1.x = SCREEN_WIDTH / 2;
  box1.y = SCREEN_HEIGHT / 2;
  box1.width = 50;
  box1.height = 50;

  struct Rectangle box2;
  box2.x = 30;
  box2.y = 30;
  box2.width = 30;
  box2.height = 30;
  
  Vector2 size = { (float)30, (float)30 };
  Vector2 ballPosition = { (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2 };
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game window");

  SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------
   
  // Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
      boxColor = GREEN;

    // mouse and box collision check
    if (recRecCheck(box1, box2))
    {
      boxColor = RED;
    }
    

    fullScreen();

    BeginDrawing();


    ClearBackground(RAYWHITE);

    if (IsKeyDown(KEY_RIGHT)) box2.x += 2.0f;
    if (IsKeyDown(KEY_LEFT)) box2.x -= 2.0f;
    if (IsKeyDown(KEY_UP)) box2.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN)) box2.y += 2.0f;

    DrawRectangle(box1.x, box1.y, box1.width, box1.height, boxColor);
    DrawRectangle(box2.x, box2.y, box2.width, box2.height, boxColor);


    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();        // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}