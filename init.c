#include "init.h"

void fullScreen()
{
  // check for alt + enter
  if (IsKeyPressed(KEY_F11))
  {
    // see what display we are on right now
    int display = GetCurrentMonitor();


    if (IsWindowFullscreen())
    {
      // if we are full screen, then go back to the windowed size
      SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    }
    else
    {
      // if we are not full screen, set the window size to match the monitor we are on
      SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
    }

    // toggle the state
    ToggleFullscreen();

    //fix screen size if necessary
    if (!IsWindowFullscreen()) {
      SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    }
  }
}
