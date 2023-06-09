#include "raylib.h"

typedef struct Object
{
  Rectangle bounds;
  int collisionFlag;
}StaticObject;

/* Walls */
StaticObject leftWall;
StaticObject rightWall;
StaticObject topWall;
StaticObject bottomWall;