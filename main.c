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
  struct Rectangle box;
  Color boxColor = GREEN;
  box.x = SCREEN_WIDTH / 2;
  box.y = SCREEN_HEIGHT / 2;
  box.width = 50;
  box.height = 50;
  


  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game window");

  SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------
   
  // Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
    mouseX = GetMouseX();
    mouseY = GetMouseY();

    // mouse and box collision check
    if (ptRecCheck(mouseX, mouseY, box))
    {
      boxColor = RED;
    }
    else
    {
      boxColor = GREEN;
    }

    fullScreen();

    BeginDrawing();


    ClearBackground(RAYWHITE);

    DrawRectangle(box.x, box.y, box.width, box.height, boxColor);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();        // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}