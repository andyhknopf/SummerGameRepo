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

int recRecCheck(Rectangle rec1, Rectangle rec2) {
    //variable declarations
    int X1max = rec1.x + rec1.width;
    int X2max = rec2.x + rec2.width;
    int Y1max = rec1.y + rec1.height;
    int Y2max = rec2.y + rec2.height;

    //if rectangle 1 is in the bounds of rectangle 2
    if (
        rec1.x < X2max &&
        X1max > rec2.x &&
        rec1.y < Y2max &&
        Y1max > rec2.y
       )
    {
        //they are colliding
        return 1;
    }
    else {
        //they are not colliding
        return 0;
    }
}

