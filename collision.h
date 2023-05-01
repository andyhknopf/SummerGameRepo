#pragma once

int ptRecCheck(int pX, int pY, Rectangle rec);

int ptCircleCheck(int pX, int pY, int cX, int cY, float cRadius);

int recRecCheck(Rectangle rec1, Rectangle rec2);

int circleCircleCheck(int circ1X, int circ1Y, float circ1Radius,
                      int circ2X, int circ2Y, float circ2Radius);

int circleRecCheck(int circX, int circY, float circRadius, Rectangle rec);














