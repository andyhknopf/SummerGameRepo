#include "enemies.h"
#include "raylib.h"
#include "raymath.h"
#include "collision.h"
#include "player.h"
float xChange;
float yChange;

Vector2 posChange;

void enemyInit(void)
{
  /* Initialize struct variables */
  testEnemy.x = 20.0f;
  testEnemy.y = 20.0f;
  testEnemy.width = 25.0f;   // 50 pixels wide.
  testEnemy.height = 50.0f;  // 25 pixels tall.
  testEnemy.health = 10; // Default health count.
  testEnemy.rotation = 0.0f;

  testEnemy.x = testEnemy.x - testEnemy.width / 2;
  testEnemy.y = testEnemy.y - testEnemy.height / 2;

  /* Initialize vectors */
  testEnemy.position = (Vector2){ testEnemy.x, testEnemy.y };
  posChange = (Vector2){ 0,0 };
  VecToPlayer = (Vector2){0,0};

  /* Head and body boundaries */
  testEnemy.headRadius = (testEnemy.width / 2) + (testEnemy.width / 5);  // 5 pixels bigger than body width.
  testEnemy.Body.width = testEnemy.width;
  testEnemy.Body.height = testEnemy.height;

  /* Gameplay information */
  testEnemy.health = 10;

  /* Initialize graphics information */

}

void enemyUpdate(void)
{
  testEnemy.color = GRAY;
  testEnemy.Body.x = testEnemy.x;
  testEnemy.Body.y = testEnemy.y;

  testEnemy.rotation = CalcAngleToPlayer(testEnemy.x, testEnemy.y);

  xChange = (player.x - testEnemy.x) * 3 * GetFrameTime();
  yChange = (player.y - testEnemy.y) * 3 * GetFrameTime();
  
  posChange = (Vector2){ xChange, yChange };
  Vector2Normalize(posChange);

  testEnemy.x += posChange.x;
  testEnemy.y += posChange.y;

  if (PlayerCollidingWithEnemy(&player, &testEnemy))
  {
    testEnemy.x -= posChange.x;
    testEnemy.y -= posChange.y;
    testEnemy.color = RED;
  
  }
}

void DrawEnemyHitbox(void)
{
  // Enemy body hitbox
  DrawRectanglePro(testEnemy.Body, (Vector2) { testEnemy.Body.width / 2,   
                   testEnemy.Body.height / 2}, testEnemy.rotation, testEnemy.color);

  // Enemy head hitbox
  DrawCircle(testEnemy.x, testEnemy.y, testEnemy.headRadius, testEnemy.color);
}

void EnemyTakeDamage(struct EnemyType* enemy, int damage)
{
  enemy->health -= damage;
  enemy->color = RED;

  return;
}

