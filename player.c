#include "raylib.h"
#include "collision.h"
#include "player.h" 
#include "objects.h"
#include "system.h"
#include "enemies.h"
#include <math.h> // atanf2



void PlayerInit(void)
{
  /* Initial position for scene */
  player.x = GetScreenWidth() / 2;  // Player center's x-coordinate.
  player.y = GetScreenHeight() / 2; // Player center's y-coordinate.
  player.position = (Vector2){player.x, player.y};
  player.rotation = 0; // Default angle facing north.
 
  Vector2 mousePos = { 0, 0 }; // Mouse position as Raylib Vector2

  /* Position as Raylib Vector2 */
  player.Body.width = 25.0f;   // 50 pixels wide.
  player.Body.height = 50.0f;  // 25 pixels tall.
  player.Body.x = player.x - player.Body.width / 2;
  player.Body.y = player.y - player.Body.height / 2;
  player.health = 10; // Default health count.
  
  /* Head and body boundaries */
  player.headRadius = (player.Body.width / 2) + (player.Body.width / 5);  // 5 pixels bigger than body width.

  /* Speed variables */
  player.defaultMovementSpeed = 500.0f;               // Default speed.
  player.movementSpeed = player.defaultMovementSpeed; // Current speed.
  player.attackTimeLength = 0.01;

  PlayerAttackBoxInit();

}

/* Update the player's logic. */
void PlayerUpdate(void)
{
  // Calculate the player's input first
  MovePlayer();

  // Update position for player
  PlayerPositioningUpdate();

  // Update position for attack box
  PlayerAttackBoxUpdate();

  // Check for attack start and update logic.
  PlayerMeleeStart(player.attackTimeLength);
  PlayerMeleeUpdate();
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

void PlayerPositioningUpdate(void)
{
  mouse.x = GetMouseX();
  mouse.y = GetMouseY();

  /* Player angle is always facing the mouse position. */
  player.rotation = CalcAngleToMouse(player.x, player.y);

  player.Body.x = player.x;
  player.Body.y = player.y;

  player.position = (Vector2){ player.x, player.y };

  player.facingDirection = (Vector2){ GetMouseX() - player.x, GetMouseY() - player.y };

}

void DrawPlayerHitbox(void)
{
  playerHeadColor = DARKGRAY;
  playerBodyColor = GRAY;

  // Player hitbox dimensions
  DrawCircle(player.x, player.y, player.headRadius, playerHeadColor); // Player head

  // Player body width and height are reversed for some reason?
  DrawRectanglePro(player.Body, (Vector2) { player.Body.width / 2,   
                   player.Body.height / 2}, player.rotation, GRAY);

  // Line indicating player direction
  DrawLine(player.x, player.y, mouse.x, mouse.y, BLACK);

  // Damage box update
  if (player.isAttackingFlag == 1)
  {
    DrawRectanglePro(player.AttackBox, (Vector2) { player.AttackBox.width / 2, player.AttackBox.height }, (player.rotation + 90), RED);
  }
}

float CalcAngleToMouse(float xPos, float yPos)
{

  float radians = atan2f((GetMouseY() - yPos),
                         (GetMouseX() - xPos));

  float degrees = radians * (180.0f / PI);

  return degrees;
}

float CalcAngleToPlayer(float xPos, float yPos)
{
  float radians = atan2f((player.y - yPos),
    (player.x - xPos));

  float degrees = radians * (180.0f / PI);

  return degrees;
}

void PlayerAttackBoxInit(void)
{
  player.AttackBox.height = 50;
  player.AttackBox.width = 80;
}

void PlayerAttackBoxUpdate(void)
{
  player.AttackBox.x += player.facingDirection.x * GetFrameTime();
  player.AttackBox.y += player.facingDirection.y * GetFrameTime();
}

void PlayerMeleeStart(double attackSpeed)
{
  if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) == 1)
  {
    StartTimer(&playerAttackTimer, attackSpeed);
    player.sameAttack = 1;
  }
}

void PlayerMeleeUpdate(void)
{
  player.isAttackingFlag = UpdateTimer(&playerAttackTimer);
  player.AttackBox.x = player.x;
  player.AttackBox.y = player.y;


  if (PlayerHitEnemy(&player, &testEnemy) == 1)
  {
    EnemyTakeDamage(&testEnemy, 1);
    
  }


}
