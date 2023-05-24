#include "raylib.h"



struct EnemyType
{
  /* Positional/Direction information */
  float x;                     // X position of the center of the player
  float y;                     // Y position of the center of the player
  float width;
  float height;
  float rotation;              // Rotation angle in degrees

  Vector2 position;

  /* Player state */
  int health;

  /* Graphics information */
  float headRadius;
};

struct EnemyType testEnemy;

Rectangle enemyBody;

Vector2 VecToPlayer;

void enemyInit(void);

void enemyUpdate(void);

void DrawEnemyHitbox(void);