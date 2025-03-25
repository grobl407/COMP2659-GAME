#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#include "model.h"
#include <stdio.h>


void move_ball (Ball *ball) {
  if (ball->isActive == 1) {
    ball->x += ball->delta_x;
    ball->y += ball->delta_y;
  }
}

void move_paddle (Paddle *paddle, int direction) {
  if (direction == 0) { /* moving left */
    if (paddle->x > 0)
      paddle->x -= paddle->move_dist;
  }
  else {
    if (paddle->x + paddle->size_x < SCREEN_WIDTH)
      paddle->x += paddle->move_dist;
  }
}

/*
void ball_collisions(Ball *ball, Paddle *paddle, Brick bricks[], int num_bricks, Wall *left_wall, 
                     Wall *right_wall, Ceiling *ceiling, Floor *floor, Game *game) {
  
  /* Ball collides with left wall, flip delta_x 
  if (ball->x <= left_wall->x) {
    ball->delta_x = -ball->delta_x;
  }

  /* Ball collides with right wall, flip delta_x 
  if (ball->x + ball->size_x >= right_wall->x) {
    ball->delta_x = -ball->delta_x;
  }

  /* Ball collides with ceiling, flip delta_y 
  if (ball->y <= ceiling->y) {
    ball->delta_y = -ball->delta_y;
  }

  /* Ball collides with paddle, flip delta_y 
  if (ball->y + ball->size_y >= paddle->y && 
      ball->x + ball->size_x >= paddle->x && 
      ball->x <= paddle->x + paddle->size_x) {
    ball->delta_y = -ball->delta_y;
  }

  /* Check for collisions with bricks 
  Brick* brick = find_brick(ball, bricks, num_bricks, game);
  if (brick != NULL) {
    /* Ball collides with brick, flip delta_y 
    if (ball->y <= brick->y + brick->size_y && 
        ball->x + ball->size_x >= brick->x && 
        ball->x <= brick->x + brick->size_x) {
      ball->delta_y = -ball->delta_y;
    }

    /* Ball collides with left side of brick, flip delta_x 
    if (ball->y < brick->y + brick->size_y && 
        ball->y < brick->y && 
        ball->x >= brick->x) {
      ball->delta_x = -ball->delta_x;
    }

    /* Ball collides with right side of brick, flip delta_x 
    if (ball->y < brick->y + brick->size_y && 
        ball->y < brick->y && 
        ball->x <= brick->x + brick->size_x) {
      ball->delta_x = -ball->delta_x;
    }

    /* Ball collides with top of brick, flip delta_y 
    if (ball->y >= brick->y + brick->size_y && 
        ball->x + ball->size_x >= brick->x && 
        ball->x <= brick->x + brick->size_x) {
      ball->delta_y = -ball->delta_y;
    }
  }

  /* Ball falls to floor, lose a life 
  if (ball->y >= floor->y) {
    game->lives -= 1;
    if (game->lives == 0) {
      game->game_over = 1; /* Game over is true 
    } else {
      reset_ball(ball, paddle);
    }
  }
} */

void reset_ball (Ball *ball, Paddle *paddle) {
  ball->x = paddle->x + paddle->size_x/2;  /* Place ball in middle of paddle */
  ball->y = paddle->y - ball->size_y;  /* Place ball on top of paddle */
  ball->isActive = 0;
}

/* wait for ball input to enable ball start again */
void start_ball (Ball *ball) {
  if (Cconis()) {
        char ch = (char)Cnecin();
  ball->isActive = 1;
}

Brick* find_brick(Ball *ball, Brick bricks[], int num_bricks, Game *game) {
  int i;
    for (i = 0; i < num_bricks; i++) {
        if (!bricks[i].isBroken && 
            ball->y <= bricks[i].y + bricks[i].size_y &&
            ball->y + ball->size_y >= bricks[i].y &&
            ball->x + ball->size_x >= bricks[i].x &&
            ball->x <= bricks[i].x + bricks[i].size_x) {
            
            check_broken(&bricks[i], game);
            return &bricks[i];
        }
    }
  return NULL;
}


void check_broken (Brick *brick, Game *game) { /* Clear brick and award points */
  brick->health -= 1; /* decrement brick */

  if (brick->health == 0) {  /* Check if brick is broken */
    brick->isBroken = 1;  /* If so, brick isBroken = true; */
    game->score += brick->base_points;  /* Add to game score */
  }
}
