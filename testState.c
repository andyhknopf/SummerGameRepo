/******************************************************************************
// Title:       test State
// Created:     4/30/23
// Authors:     Andy
REPLACE THIS LINE & ALL INSTANCES OF "test" OR "test" WITH THE PROPER TITLE.
/*****************************************************************************/
#include "raylib.h" // Basic raylib framework functions
#include "init.h"   // SCREEN_WIDTH, SCREEN_HEIGHT, fullscreen()
#include "player.h"
#include "test.h"
#include <stdio.h>  // printf()+
#include "transform.h"


/**************************************************************************
 testInit - Standard template for a new scene's initialization function.
             Initialize all variables and
 Returns:
      void - Void function, returns nothing.
**************************************************************************/
void testInit(void)
{
  // Initialize all assets.
  PlayerInit();
  Vector2 rotatingPoint = { 300, 300 };
  Vector2 anchorPoint = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
}

/**************************************************************************
 testUpdate - Standard template for a new scene's update loop. Update all
               variables and graphics. This function is called once each
               frame.
 Returns:
        void - Void function, returns nothing.
**************************************************************************/
void testUpdate(void)
{
  /* Will run once every frame */
  while (!WindowShouldClose())
  {
    /* Game logic and variable updates. */
    PlayerUpdate();

    if (IsKeyDown(KEY_R))
    {
      rotatingPoint.x = RotateAroundPointX(player.x, rotatingPoint.x,
        CalcAngleToMouse(player.x, player.y));
      rotatingPoint.y = RotateAroundPointY(player.y, rotatingPoint.y,
        CalcAngleToMouse(player.x, player.y));
    }

    
    /* Graphics */
    BeginDrawing();

    ClearBackground(RAYWHITE);
    
    DrawPlayerHitbox();

    EndDrawing();
  }
}

/******************************************************************************
 runTestState - Template for a test scene that contains all 3 initialization,
                 update, and exit functions.
 Arguments:
          mode - Selects the mode of the scene instance. 's' starts the scene
                 for the first time. 'c' continues the scene from the previous
                 instance. 'r' resets all variables in the scene.
 Returns:
          void - Void function, returns nothing.
******************************************************************************/
void runTestState(char mode)
{
  // 'mode' variable check
  if (mode != 'c' &&
      mode != 's' &&
      mode != 'r')
  {
    printf("Error: runtestState - Select 's', 'c', or 'r'. Exiting.\n");

    return;
  }

  switch (mode)
  {
  case 's': // Start mode initializes the scene AND the player.
    testInit();
    //playerInit(); work in progress
    testUpdate();
  case 'c': // Continue mode resumes variables from the previous instance.
    testUpdate();
  case 'r': // Reset mode initializes the level variables, but NOT the player.
    testInit();
    testUpdate();
  }
}