/******************************************************************************
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
******************************************************************************/

//header links
#include "raylib.h"
#include "init.h"
#include "menu.h"
#include "collision.h"


int main(void)
{
  /************************* Initialization **********************************/
  
  // Start openGL context
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Game window"); 

  // Set target framerate
  SetTargetFPS(60);                                       

  /* Game main entry point */
  runMenuState('s');

  // Close window and OpenGL context
  CloseWindow();        

  return 0;
}