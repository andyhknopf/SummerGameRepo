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
    boxColor = GREEN;
    circle1Color = GREEN;
    circle2Color = GREEN;

    mouseX = GetMouseX();
    mouseY = GetMouseY();

    circle2X = GetMouseX();
    circle2Y = GetMouseY();

    // mouse and box collision check
    if (recRecCheck(box1, box2))
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

    if (IsKeyDown(KEY_RIGHT)) box2.x += 2.0f;
    if (IsKeyDown(KEY_LEFT)) box2.x -= 2.0f;
    if (IsKeyDown(KEY_UP)) box2.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN)) box2.y += 2.0f;

    DrawRectangle(box1.x, box1.y, box1.width, box1.height, boxColor);
    DrawRectangle(box2.x, box2.y, box2.width, box2.height, boxColor);

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