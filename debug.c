#include "raylib.h"
#include "player.h"
#include "system.h"
#include "enemies.h"
#include <math.h>
#include "debug.h"
#include "raymath.h"


void VectorDebug(void)
{
  float lineLength = sqrtf(((mouse.x - player.x) * (mouse.x - player.x)) +
    ((mouse.y - player.y) * (mouse.y - player.y)));

  vecTextX = player.x + ((GetMouseX() - player.x) / 2);
  vecTextY = player.y + ((GetMouseY() - player.y) / 2);
  vecX = mouse.x - player.x;
  vecY = mouse.y - player.y;


  DrawText(TextFormat("VecX: %08f", vecX), vecTextX, player.y, 20, BLACK);
  DrawText(TextFormat("VecY: %08f", vecY), GetMouseX(), vecTextY, 20, BLACK);
  DrawText(TextFormat("Vec Length: %08f", lineLength), player.x + ((mouse.x - player.x) / 2),
    player.y + ((mouse.y - player.y) / 2), 20, BLACK);

  DrawLine(player.x, player.y, GetMouseX(), player.y, RED);
  DrawLine(GetMouseX(), player.y, GetMouseX(), GetMouseY(), YELLOW);

  return;
}



void TimerDebug(Timer * timer)
{
  DrawText(TextFormat("Timer: %d", timer->lifeTime), 20, 20, 20, BLACK);
}

void EnemyDamageDebug(struct EnemyType* enemy)
{
  DrawText(TextFormat("Enemy Health: %i", enemy->health), GetScreenWidth() - 200.0f, 200.0f, 20, BLACK);
}

void DrawDebug(void)
{
  VectorDebug();
  //TimerDebug(&playerAttackTimer);
  EnemyDamageDebug(&testEnemy);

  return;
}