#include "raylib.h"

typedef struct
{
  double lifeTime;
  int isActive;
}Timer;

void StartTimer(Timer * timer, double seconds);

int UpdateTimer(Timer * timer);

Timer playerAttackTimer;