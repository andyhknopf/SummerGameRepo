#pragma once
#include "raylib.h"

/***********************************************************************
 ptRecCheck: This function checks to see if a point is colliding with
             a rectangle. 

 Returns - Returns a 1 if the two objects are colliding, a 0 if
           they aren't.
***********************************************************************/
int ptRecCheck(int pX, int pY, Rectangle rec)
{
  // if the point is within the bounds of the rectangle
  if (
      (pX > rec.x) && (pX < rec.x + rec.width) &&
      (pY > rec.y) && (pY < rec.y + rec.height)
     )
  {
    // they are colliding
    return 1;
  }
  else
  {
    // they are not colliding
    return 0;
  }

}

