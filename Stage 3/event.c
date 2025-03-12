#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#include "model.h"

void ball_falls (Ball *ball, Floor * floor) { /* Minus one life, ball restarts at rest */
    if (ball->y >= floor->y) {
    game->lives -= 1;
    if (game->lives == 0) {
      game->game_over = 1; // Game over is true
    }
    else {
      reset_ball(ball, paddle);
    }
  }
}

void reset_bricks (Brick bricks[], int num_bricks, int level) {
void reset_bricks (Brick bricks[], int num_bricks, int level) {
  for (int i = 0; i < num_bricks; i++) {
    bricks[i].isBroken = 0;
    bricks[i].health = 6;
    bricks[i].base_points = bricks[i].base_points*2; // double points awarded for each broken brick at new level
  }
}

/* All bricks cleared, so replace bricks, award points,
increase level and ball velocity, restart the ball */
void level_complete (Game *game, Ball *ball, Brick bricks[], int num_bricks) {
void level_complete (Game *game, Ball *ball, Brick bricks[], int num_bricks) {
  /* First Check if all bricks are cleared */
  int levelClear = 0; // Level clear starts true

  for (int i = 0; i < num_bricks; i++) { // iterate through every brick
    if (bricks[i].isBroken == 0) { // If brick is not broken, set levelClear to false,
      levelClear = 0;
    }
  }

  if (levelClear == 1) { // If level clear is true
    game->level += 1; // Increment level
    reset_bricks(bricks, num_bricks, game->level);
  }
}
