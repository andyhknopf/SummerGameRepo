#include "raylib.h"

struct PlayerType
{
  /* Positional/Direction information */
  float x;                     // X position of the center of the player
  float y;                     // Y position of the center of the player
  float rotation;              // Rotation angle in degrees
  float rotationSpeed;
  float defaultMovementSpeed;  // Default movement speed of the player
  float movementSpeed;         // Default velocity of the player

  Rectangle Body;
  Rectangle AttackBox;
 
  /* Vector information */
  Vector2 position;
  Vector2 facingDirection;
  float directionVectorLength; // Length of direction vector of the player

  /* Player state */
  int health;
  double attackTimeLength;
  int isAttackingFlag;
  int sameAttack;

  /* Graphics information */
  float headRadius;
};

struct PlayerType player;

Vector2 mouse;



Color playerHeadColor;
Color playerBodyColor;


void PlayerInit(void);

int MovePlayer(void);

void PlayerUpdate(void);

int PlayerIsMoving(void);

void PlayerPositioningUpdate(void);

float CalcAngleToMouse(float xPos, float yPos);

float CalcAngleToPlayer(float xPos, float yPos);

void DrawPlayerHitbox(void);

void PlayerAttackBoxInit(void);

void PlayerAttackBoxUpdate(void);

void PlayerMeleeStart(double attackSpeed);

void PlayerMeleeUpdate(void);

//int EntityCollidingWithPlayer(struct Entity entity);
//
//int ObjectCollidingWithPlayer(struct Static object);