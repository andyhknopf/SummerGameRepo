#pragma once
#include "raylib.h"

/**************************************************************************
 testInit - Standard template for a new scene's initialization function.
             Initialize all variables and
 Returns:
      void - Void function, returns nothing.
**************************************************************************/
void testInit(void);

/**************************************************************************
 testUpdate - Standard template for a new scene's update loop. Update all
               variables and graphics. This function is called once each
               frame.
 Returns:
        void - Void function, returns nothing.
**************************************************************************/
void testUpdate(void);

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
void runTestState(char mode);

Vector2 rotatingPoint;
Vector2 anchorPoint;