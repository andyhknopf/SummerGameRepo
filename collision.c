#include "raylib.h"
#include "player.h"
#include "objects.h"
#include "collision.h"
#include "enemies.h"
#include <math.h>

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

/*************************************************************************
 ptCircleCheck: This function checks to see if a point is colliding with
                a circle.

 Returns - Returns a 1 if the two objects are colliding, a 0 if
           they aren't.
*************************************************************************/
int ptCircleCheck(int pX, int pY, int cX, int cY, float cRadius)
{
  // Distance between the center of the circle and the point
  float distance = sqrtf(
    ((float)(pX - cX)) * (float)(pX - cX) +
    ((float)(pY - cY) * (float)(pY - cY))
  );

  // If the distance is smaller than the circle's radius
  if (distance < cRadius)
  {
    // They are colliding
    return 1;
  }
  else
  {
    return 0;
  }
}

/*********************************************************************************
 circleCircleCheck: This function checks to see if a rectangle is colliding with
                a rectangle.

 Returns - Returns a 1 if the two objects are colliding, a 0 if
           they aren't.
*********************************************************************************/
int recRecCheck(Rectangle rec1, Rectangle rec2) {
  //variable declarations
  float X1max = rec1.x + rec1.width;
  float X2max = rec2.x + rec2.width;
  float Y1max = rec1.y + rec1.height;
  float Y2max = rec2.y + rec2.height;

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

/*****************************************************************************
 circleCircleCheck: This function checks to see if a circle is colliding with
                a circle.

 Returns - Returns a 1 if the two objects are colliding, a 0 if
           they aren't.
*****************************************************************************/
int circleCircleCheck(int circ1X, int circ1Y, float circ1Radius,
  int circ2X, int circ2Y, float circ2Radius)
{
  // Distance between the center of circle 1 and circle 2
  float distance = sqrtf(
    ((float)(circ1X - circ2X)) * (float)(circ1X - circ2X) +
    ((float)(circ1Y - circ2Y) * (float)(circ1Y - circ2Y))
  );

  // If the distance is smaller than the radius of either cirlce...
  if (distance < circ1Radius + circ2Radius)
  {
    // They are colliding
    return 1;
  }
  else
  {
    // They are not colliding.
    return 0;
  }
}


/*****************************************************************************
 circleRecCheck: This function checks to see if a circle is colliding with
                a rectangle.

 Returns - Returns a 1 if the two objects are colliding, a 0 if
           they aren't.
*****************************************************************************/
int circleRecCheck(int circX, int circY, float circRadius, Rectangle rec)
{
  float testX = (float)circX;             // Stores the x value where the circle meets the rectangle.
  float testY = (float)circY;             // Stores the y value where the cirlce meets the rectangle.
  float Xmin = rec.x;              // X-value of the top left corner of the rectangle.
  float Ymin = rec.y;              // Y-value of the top left corner of the rectangle.
  float Xmax = rec.x + rec.width;  // X-value of the rectangle's bottom right.
  float Ymax = rec.y + rec.height; // Y-value of the rectangle's bottom right.
  float distX;                     // Distance of the x values
  float distY;                     // Distance of the y values
  float distance;


  if (circX < Xmin)
    testX = Xmin;
  else if (circX > Xmax)
    testX = Xmax;
  if (circY < Ymin)
    testY = Ymin;
  else if (circY > Ymax)
    testY = Ymax;

  distX = (float)circX - testX;
  distY = (float)circY - testY;

  distance = sqrtf((distX * distX) + (distY * distY));


  if (distance < circRadius)
  {
    // They are colliding
    return 1;
  }
  else
  {
    // They are not colliding.
    return 0;
  }
}

int PlayerCollidingWithEnemy(struct PlayerType* playerPtr, struct EnemyType * enemyPtr)
{
  // status is 1 if they are colliding, 0 if they are not.
  int status = circleCircleCheck(enemyPtr->x, enemyPtr->y, enemyPtr->headRadius,
                               playerPtr->x, playerPtr->y, playerPtr->headRadius);
  
  return status;
}


int PlayerHitEnemy(struct PlayerType* playerPtr, struct EnemyType* enemyPtr)
{
  int status = recRecCheck(playerPtr->AttackBox, enemyPtr->Body);

  return status;
}