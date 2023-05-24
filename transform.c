#include "raylib.h"
#include "math.h"

float RotateAroundPointX(float anchorPointX, float inputPointX, float angle)
{
  float coordinate = inputPointX;

  coordinate = (cosf(angle) - sinf(angle)) * (inputPointX - anchorPointX) + anchorPointX;

  return coordinate;
}

float RotateAroundPointY(float anchorPointY, float inputPointY, float angle)
{
  float coordinate = inputPointY;

  coordinate = (sinf(angle) + cosf(angle)) * (inputPointY - anchorPointY) - anchorPointY;

  return coordinate;
}