#include "raylib.h"
#include "collision.h"
#include "player.h" 
#include <math.h> // atanf2

void PlayerInit(void)
{
  /* Initial position for scene */
  player.x = GetScreenWidth() / 2;  // Player center's x-coordinate.
  player.y = GetScreenHeight() / 2; // Player center's y-coordinate.
  player.rotation = 0; // Default angle facing north.
 
  Vector2 mousePos = { 0, 0 }; // Mouse position as Raylib Vector2

  /* Position as Raylib Vector2 */
  playerBody.width = 25.0f;   // 50 pixels wide.
  playerBody.height = 50.0f;  // 25 pixels tall.
  playerBody.x = player.x - playerBody.width / 2;
  playerBody.y = player.y - playerBody.height / 2;
  player.health = 10; // Default health count.
  
  /* Head and body boundaries */
  player.headRadius = (playerBody.width / 2) + (playerBody.width / 5);  // 5 pixels bigger than body width.

  /* Speed variables */
  player.defaultMovementSpeed = 500.0f;               // Default speed.
  player.movementSpeed = player.defaultMovementSpeed; // Current speed.


}

/* Update the player's logic. */
void PlayerUpdate(void)
{
  // Calculate the player's input first
  MovePlayer();

  mouse.x = GetMouseX();
  mouse.y = GetMouseY();

  /* Player angle is always facing the mouse position. */
  player.rotation = CalcAngleToMouse(player.x, player.y);

  playerBody.x = player.x;
  playerBody.y = player.y;

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
  playerHeadColor = DARKGRAY;

  // Player Model
  DrawCircle(player.x, player.y, player.headRadius, playerHeadColor); // Player head
  DrawRectanglePro(playerBody, (Vector2) { playerBody.width / 2,  // Player body
                   playerBody.height / 2}, player.rotation, GRAY);// (height and width are reversed for some reason?)
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