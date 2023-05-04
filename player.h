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
  float directionVectorLength; // Length of direction vector of the player

  /* Player state */
  int health;

  /* Graphics information */
  float headRadius;
};

struct PlayerType player;

Vector2 playerOrigin;
Vector2 mouse;

Rectangle playerBody;

Color playerHeadColor;
Color playerBodyColor;

void PlayerInit(void);

int MovePlayer(void);

void PlayerUpdate(void);

int PlayerIsMoving(void);

float CalcAngleToMouse(float xPos, float yPos);

void DrawPlayerHitbox(void);

//int EntityCollidingWithPlayer(struct Entity entity);
//
//int ObjectCollidingWithPlayer(struct Static object);