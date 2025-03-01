#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#include "model.h"

void move_ball (ball *ball) {
  if (ball->isActive = 1) {
    ball->x += ball->delta_x;
    ball->y += ball->delta_y;
  }
}

void move_paddle (paddle *paddle, int direction) {
  if (direction == 0) { /* moving left */
    if (paddle->x > 0)
      paddle->x -= paddle->move_dist;
  }
  else {
    if (paddle->x + paddle->x < SCREEN_WIDTH)
      paddle->x += paddle->move_dist;
  }
}

void ball_collisions (ball *ball, paddle *paddle, brick bricks[], int num_bricks, wall *left_wall, 
                      wall *right_wall, ceiling *ceiling, floor *floor, game *game) {
  
  /* Ball collides with wall, flip delta_x */
  if (ball->x <= left_wall->x || ball->x + ball->size_x >= right_wall->x) {
    ball->delta_x = -ball->delta_x;
  }

  /* Ball collides with ceiling */
  if (ball->y <= ceiling->y) {
    ball->delta_y = -ball->delta_y;
  }

  /* Ball collides with paddle */
  if (ball->y + ball->size_y >= paddle->y && ball->x + ball->size_x >= paddle->x && 
      ball->x <= paddle->x + paddle->size_x) {
    ball->delta_y = -ball->delta_y;
  }

  /* Ball collides with brick */
  if (ball->y <= brick->y + brick->size_y && ball->x + ball->size_x >= brick->x &&
      ball->x <= brick->x + brick->size_x) {
        ball->delta_y = -ball->delta_y;
      }

  /*Ball collides with left of brick*/
  if (ball->y < brick->y + brick->size_y && ball->y < brick->y && ball->x >= brick->x){
    /*add velocity stuff*/
    ball->delta_x = -ball->delta_x;
  }
  /*Ball collides with right of brick*/
  if(ball->y < brick->y + brick->size_y && ball->y < brick->y && ball->x <= brick->x + brick->size_x){
    /*add velocity stuff*/
    ball->delta_x = -ball->delta_x;
  }

  /* Ball falls to floor */
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

void reset_ball (ball *ball, paddle *paddle) {
  ball->x = paddle->x + paddle->size/2;  // Place ball in middle of paddle
  ball->y = paddle->y - ball->size_y;  // Place ball on top of paddle
  ball->isActive = 0;
}

/* wait for ball input to enable ball start again */
void start_ball (ball *ball) {
  Cnenin();
  ball->isActive = 1;
}

void find_brick (ball *ball, brick bricks[], int num_bricks, game *game, first_brick_y) {
  int brick_length = 32;
  int brick_height = 7;
  int spacing = 7;

  // Find column
  int column = (ball->x - 171) / (brick_width + spacing);

  // Find row
  int row = (ball->y - first_brick_y) / (brick_height + spacing);

  // Find index in array
  int i = row * 8 + column;

  // Check proper indexing, and call check broken on bricksp[i]
  if (i >= 0 && i < num_bricks) {
    check_broken(&bricks[i], game);
  }
}


void check_broken (brick *brick, game *game) { /* Clear brick and award points */
  brick->health -= 1; // decrement brick

  if (brick->health == 0) {  // Check if brick is broken
    brick->isBroken = 1;  // If so, brick isBroken = true;
    game->score += brick->base_points;  // Add to game score
  }
}
