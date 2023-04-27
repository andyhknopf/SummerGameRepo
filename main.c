/****************************************************************************
  This is the basic template for our main game loop, containing one screen.
  
  Make sure there are NO tabs and all lines are 80 characters or under.
****************************************************************************/

/* Header files and global variables. */
#include "raylib.h"

/********************************************************************
  Set starting values for every variable prior to game launch.
  Initialize system settings, i.e. window size, framerate, etc... 
********************************************************************/
void mainGameInit(void)
{

};

/*************************************************************************** 
  This function runs once per frame, contains all frame data and per frame
  game logic. 
***************************************************************************/
void mainGameUpdate(void)
{
  /* Makes the game not exit when you press escape. */
  SetExitKey(KEY_NULL);

  /* Main game loop */
  while (!WindowShouldClose())
  {
    /* Update logic for in game events */

    /* TODO: Update player and world variables */

    /* Graphics and visuals go here, after game logic */
    BeginDrawing();

    /* Always clear the screen & set the background color first. */
    ClearBackground(RAYWHITE);


    EndDrawing();
  }
};

/**************************************************************
  Shut down all proccesses and clean up any remaining memory.
**************************************************************/
void mainGameExit(void)
{
  CloseWindow();
};

int main(void)
{ 
  /* Start the game. */
  mainGameInit();

  /* Run the game each frame. */
  mainGameUpdate();

  /* Exit the game, close the application. */
  mainGameExit();
  
  /* End the program. */
  return 0;
}
