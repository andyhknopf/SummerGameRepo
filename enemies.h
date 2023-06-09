#include "raylib.h"



struct EnemyType
{
  /* Positional/Direction information */
  float x;                     // X position of the center of the player
  float y;                     // Y position of the center of the player
  float width;
  float height;
  float rotation;              // Rotation angle in degrees
  Rectangle Body;

  Vector2 position;

  /* Player state */
  int health;
  double timeSinceHit;

  /* Graphics information */
  float headRadius;
  Color color;
};

struct EnemyType testEnemy;



Vector2 VecToPlayer;

void enemyInit(void);

void enemyUpdate(void);

void DrawEnemyHitbox(void);