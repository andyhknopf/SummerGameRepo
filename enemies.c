#include "enemies.h"
#include "raylib.h"
#include "raymath.h"
#include "player.h"

float xChange = 0;
float yChange = 0;

void enemyInit(void)
{
  testEnemy.x = 20.0f;
  testEnemy.y = 20.0f;
  testEnemy.width = 25.0f;   // 50 pixels wide.
  testEnemy.height = 50.0f;  // 25 pixels tall.
  testEnemy.x = testEnemy.x - testEnemy.width / 2;
  testEnemy.y = testEnemy.y - testEnemy.height / 2;
  testEnemy.health = 10; // Default health count.
  testEnemy.rotation = 0.0f;
  testEnemy.position = (Vector2){ testEnemy.x, testEnemy.y };

  Vector2 VecToPlayer = { 0, 0 };

  /* Head and body boundaries */
  testEnemy.headRadius = (testEnemy.width / 2) + (testEnemy.width / 5);  // 5 pixels bigger than body width.
  enemyBody.width = testEnemy.width;
  enemyBody.height = testEnemy.height;


}

void enemyUpdate(void)
{
  enemyBody.x = testEnemy.x;
  enemyBody.y = testEnemy.y;

  testEnemy.rotation = CalcAngleToPlayer(testEnemy.x, testEnemy.y);

  xChange = (player.x - testEnemy.x) * GetFrameTime();
  yChange = (player.y - testEnemy.y) * GetFrameTime();

  testEnemy.x += xChange;
  testEnemy.y += yChange;

  
}

void DrawEnemyHitbox(void)
{

  DrawRectanglePro(enemyBody, (Vector2) { enemyBody.width / 2,   
                   enemyBody.height / 2}, testEnemy.rotation, GRAY);
  DrawCircle(testEnemy.x, testEnemy.y, testEnemy.headRadius, RED);
}