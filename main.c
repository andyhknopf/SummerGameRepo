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

  Color circle1Color = GREEN;
  int circle1X = SCREEN_WIDTH / 4;
  int circle1Y = SCREEN_HEIGHT / 4;
  float circle1Radius = 50;


  Color circle2Color = GREEN;
  int circle2X = 350;
  int circle2Y = 400;
  float circle2Radius = 50;
  


  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game window");

  SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
  //--------------------------------------------------------------------------------------
   
  // Main game loop
  while (!WindowShouldClose())    // Detect window close button or ESC key
  {
    boxColor = GREEN;
    circle1Color = GREEN;
    circle2Color = GREEN;

    mouseX = GetMouseX();
    mouseY = GetMouseY();

    circle2X = GetMouseX();
    circle2Y = GetMouseY();

    // mouse and box collision check
    if (ptRecCheck(mouseX, mouseY, box))
    {
      boxColor = RED;
    }


    // mouse and circle collision check
    if (ptCircleCheck(mouseX, mouseY, circle1X, circle1Y, circle1Radius))
    {
      circle1Color = RED;
    }


    // circle and circle collision check
    if (circleCircleCheck(circle1X, circle1Y, circle1Radius,
        circle2X, circle2Y, circle2Radius))
    {
      circle2Color = RED;
    }



    // circle and rectangle collision check.
    if (circleRecCheck(circle2X, circle2Y, circle1Radius, box))
    {
      circle2Color = RED;
    }
  



    //Graphics
    fullScreen();

    BeginDrawing();

    ClearBackground(RAYWHITE);

    // Collision check objects 
    DrawRectangle(box.x, box.y, box.width, box.height, boxColor);
    DrawCircle(circle1X, circle1Y, circle1Radius, circle1Color);
    DrawCircle(circle2X, circle2Y, circle2Radius, circle2Color);

    EndDrawing();
    //----------------------------------------------------------------------------------
  }

  // De-Initialization
  //--------------------------------------------------------------------------------------
  CloseWindow();        // Close window and OpenGL context
  //--------------------------------------------------------------------------------------

  return 0;
}