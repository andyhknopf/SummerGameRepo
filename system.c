#include "raylib.h"
#include "system.h"

void StartTimer(Timer * timer, double seconds)
{
  if (timer != NULL)
  {
    timer->isActive = 1;
    timer->lifeTime = seconds;
  }
}

int UpdateTimer(Timer* timer)
{
  if (timer != NULL) // Check if the timer is active or not.
  {
    if (timer->lifeTime > 0) // If the timer's current time is above 0...
    {
      timer->lifeTime -= GetFrameTime(); // subtract the current time.

      return 1;
    }
    
    timer->isActive = 0;

    return 0;
  }

  return 0;
}