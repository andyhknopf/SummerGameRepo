//
// Title:       Helper Functions 
// Created:     4/26/23
// Authors:     Jason, Andy
//

#include "helper.h"

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
                SetWindowSize(screenWidth, screenHeight);
            }
            else
            {
                // if we are not full screen, set the window size to match the monitor we are on
                SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
            }

            // toggle the state
            ToggleFullscreen();
        }
}

void menu()
{

}
