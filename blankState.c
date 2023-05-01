/******************************************************************************
// Title:       Blank State
// Created:     4/30/23
// Authors:     Andy
REPLACE THIS LINE & ALL INSTANCES OF "blank" OR "Blank" WITH THE PROPER TITLE.
/*****************************************************************************/
#include "raylib.h" // Basic raylib framework functions
#include "init.h"   // SCREEN_WIDTH, SCREEN_HEIGHT, fullscreen()
#include <stdio.h>  // printf()


/**************************************************************************
 blankInit - Standard template for a new scene's initialization function.
             Initialize all variables and
 Returns:
      void - Void function, returns nothing.
**************************************************************************/
void blankInit(void)
{
  // Initialize all assets.
}

/**************************************************************************
 blankUpdate - Standard template for a new scene's update loop. Update all
               variables and graphics. This function is called once each 
               frame.
 Returns:
        void - Void function, returns nothing.
**************************************************************************/
void blankUpdate(void)
{
  /* Will run once every frame */
  while (!WindowShouldClose())
  {
    /* Game logic and variable updates. */

    /* Graphics */
    BeginDrawing();

    ClearBackground(/* REPLACE WITH COLOR NAME */);

    EndDrawing();
  }
}

/******************************************************************************
 runBlankState - Template for a blank scene that contains all 3 initialization,
                 update, and exit functions.
 Arguments:
          mode - Selects the mode of the scene instance. 's' starts the scene
                 for the first time. 'c' continues the scene from the previous
                 instance. 'r' resets all variables in the scene.
 Returns: 
          void - Void function, returns nothing.
******************************************************************************/
void runBlankState(char mode)
{
  // 'mode' variable check
  if (mode != 'c' ||
      mode != 's' ||
      mode != 'r')
  {
    printf("Error: runBlankState - Select 's', 'c', or 'r'. Exiting.\n");

    return;
  }

  switch (mode)
  {
  case 's': // Start mode initializes the scene AND the player.
    blankInit();
    //playerInit(); work in progress
    blankUpdate();
  case 'c': // Continue mode resumes variables from the previous instance.
    blankUpdate();
  case 'r': // Reset mode initializes the level variables, but NOT the player.
    blankInit();
    blankUpdate();
  }
}