#include "raylib.h"
#include "collision.h"
#include "player.h"
#include <math.h>

void PlayerInit(void)
{
  /* Player's starting position in the scene. */
  player.x = GetRenderWidth() / 2;  // Player center's x-coordinate.
  player.y = GetRenderHeight() / 2; // Player center's y-coordinate.
  player.rotation = 0; // Default angle facing north.
 
  Vector2 mousePos = { 0, 0 };


  /* Set the vector's x-y to the player's by default. */
  playerBody.x = player.x - playerBody.width / 2;
  playerBody.y = player.y - playerBody.height / 2;
  player.health = 10; // Default health count.
  
  /* Set boundaries for the player's body & head. */
  playerBody.width = 50.0f;   // 50 pixels wide.
  playerBody.height = 25.0f;  // 25 pixels tall.
  player.headRadius = (playerBody.height / 2) + (playerBody.height / 5);  // 5 pixels bigger than body height.

  /* Set speed variables. */
  player.defaultMovementSpeed = 500.0f;               // Default speed.
  player.movementSpeed = player.defaultMovementSpeed; // Current speed.
 
}

/* Update the player's logic. */
void PlayerUpdate(void)
{
  // Calculate the player's input first
  MovePlayer();
  Vector2 playerOrigin = { player.x, player.y };
  mouse.x = GetMouseX();
  mouse.y = GetMouseY();

  /* Player angle is always facing the mouse position. */
  player.rotation = CalcAngleToMouse(player.x, player.y);

  

  playerBody.x = player.x - playerBody.width / 2;
  playerBody.y = player.y - playerBody.height / 2;

  playerHeadColor = GRAY;
  playerBodyColor = DARKGRAY;
}

int MovePlayer(void)
{
  int playerIsMovingFlag = 0; // Default moving state is FALSE.

  /* Run all as separate if statements to run at the same time. */

  if (IsKeyDown(KEY_A)) // Left
  {
    playerIsMovingFlag = 1; // Set flag to TRUE.
    player.x -= player.movementSpeed * GetFrameTime();
  }

  if (IsKeyDown(KEY_D)) // Right
  {
    playerIsMovingFlag = 1; // Set flag to TRUE.
    player.x += player.movementSpeed * GetFrameTime();
  }

  if (IsKeyDown(KEY_W)) // Up
  {
    playerIsMovingFlag = 1; // Set flag to TRUE.
    player.y -= player.movementSpeed * GetFrameTime();
  }

  if (IsKeyDown(KEY_S)) // Down
  {
    playerIsMovingFlag = 1; // Set flag to TRUE.
    player.y += player.movementSpeed * GetFrameTime();
  }

  /* Return TRUE or FALSE depending on if any keys were pressed. */
  return playerIsMovingFlag; 
}

int PlayerIsMoving(void)
{
  if (MovePlayer() == 1) // If the player is moving, return TRUE.
    return 1;
  else              
    return 0; // If not, return FALSE.
}


void DrawPlayerHitbox(void)
{
  // Draw the player's head as a circle.
  DrawCircle((int)player.x, (int)player.y, player.headRadius, playerHeadColor);

  DrawRectanglePro(playerBody, playerOrigin, player.rotation, playerBodyColor);

  DrawLine(player.x, player.y, mouse.x, mouse.y, BLACK);
}

float CalcAngleToMouse(float xPos, float yPos)
{

  float radians = atan2f((GetMouseY() - yPos),
                         (GetMouseX() - xPos));

  float degrees = radians * (180.0f / PI);
}

//int EntityCollidingWithPlayer(struct Entity entity)
//{
//
//}
//
//int ObjectCollidingWithPlayer(struct Static object)
//{
//
//}