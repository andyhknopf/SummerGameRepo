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
#include "enemies.h"
#include "transform.h"
#include "debug.h"
#include "system.h"
#include <math.h>

float bulletStartX;
float bulletStartY;
float bulletCurrentX;
float bulletCurrentY;
float bulletDeltaX;
float bulletDeltaY;

Timer bulletTimer;

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
  enemyInit();

  bulletTimer.isActive = 0;
  bulletTimer.lifeTime = 1;

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
  int timerFlag;

  /* Will run once every frame */
  while (!WindowShouldClose())
  {
    /* Game logic and variable updates. */
    PlayerUpdate();
    enemyUpdate();

    bulletStartX = player.x;
    bulletStartY = player.y;

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
    {
      bulletCurrentX = bulletStartX;
      bulletCurrentY = bulletStartY;
      bulletDeltaX = mouse.x - player.x;
      bulletDeltaY = mouse.y - player.y;
      StartTimer(&bulletTimer, 1.00);
    }

    timerFlag = UpdateTimer(&bulletTimer);

    if (timerFlag == 1)
    {
      bulletCurrentX += bulletDeltaX * GetFrameTime();
      bulletCurrentY += bulletDeltaY * GetFrameTime();
    }
    

    /* Graphics */
    BeginDrawing();

    ClearBackground(RAYWHITE);
    
    DrawPlayerHitbox();

    DrawEnemyHitbox();

    DrawDebug();

    if (timerFlag == 1)
    {
      DrawCircle(bulletCurrentX, bulletCurrentY, 10, GREEN);
    }

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