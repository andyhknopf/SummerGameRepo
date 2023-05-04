#include "menu.h"
#include "init.h"
#include "collision.h"
#include "blankState.h"
#include "raylib.h"
#include "test.h"

float buttonTextXOffset;
float buttonTextYOffset;

void menuStateInit(void)
{
  // Initialize menu buttons
  playButton.height = 50;
  playButton.width = SCREEN_WIDTH / 3;
  playButton.x = (SCREEN_WIDTH / 2) - (playButton.width / 2);
  playButton.y = SCREEN_HEIGHT / 4;
}

void menuStateUpdate(void)
{
  // Update once every frame
  while (!WindowShouldClose())
  {
    // Game logic

    // If the play button is clicked... 
    if (menuButtonIsClicked(playButton))
    {
      // ...run the test state in start mode. 
      runTestState('s'); 
    }

    // Graphics logic

    // Graphics
    fullScreen();
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Play Button
    DrawRectangleRec(playButton, GREEN);
    DrawText("Play", playButton.x + playButton.width / 2.5,
                     playButton.y, playButton.height, BLACK);

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

int menuButtonIsClicked(Rectangle button)
{
  // If the mouse is inside the bounds of the box when it's clicked
  if (ptRecCheck(GetMouseX(), GetMouseY(), button) &&
      IsMouseButtonDown(MOUSE_LEFT_BUTTON))
  {
    // Return TRUE
    return 1;
  }
  else
  {
    // If the mouse isn't clicked, return FALSE each frame.
    return 0;
  }

}