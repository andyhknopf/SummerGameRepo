#include "menu.h"
#include "init.h"
#include "collision.h"
#include "blankState.h"
#include "raylib.h"

void menuStateInit(void)
{
  // Initialize menu buttons
  playButton.height = 50;
  playButton.width = SCREEN_WIDTH / 3;
  playButton.x = (SCREEN_WIDTH / 2) - playButton.width;
  playButton.y = SCREEN_HEIGHT / 4;
}

void menuStateUpdate(void)
{
  // Update once every frame
  while (!WindowShouldClose())
  {
    // Game logic
    if (ptRecCheck(GetMouseX(), GetMouseY(), playButton) &&
        IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
      runBlankState('s');
    }

    // Graphics logic

    // Graphics
    fullScreen();


    BeginDrawing();

    DrawRectangleRec(playButton, GREEN);

    ClearBackground(RAYWHITE);


    EndDrawing();
  }

}


void runMenuState(char mode)
{
  switch (mode)
  {
  case 's': // Start mode initializes the scene AND the player.
    menuStateInit();
    //playerInit();
    menuStateUpdate();
   case 'c':
    menuStateUpdate();
   case 'r':
    menuStateInit();
    menuStateUpdate();
  }

}