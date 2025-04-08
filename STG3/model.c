#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#include "model.h"
#include <stdio.h>
#include <osbind.h>
#include <linea.h>


void move_ball (Ball *ball) {
  if (ball->isActive == 1) {
    ball->x += ball->delta_x;
    ball->y += ball->delta_y;
  }
}

void move_paddle (Paddle *paddle, int direction) {
  if (direction == 0 && paddle->x > 160) { /* moving left */
    if (paddle->x > 0)
      paddle->x -= paddle->move_dist;
  }
  else if (paddle->x < 448) {
    if (paddle->x + paddle->size_x < SCREEN_WIDTH)
      paddle->x += paddle->move_dist;
  }
}


void ball_collisions(Ball *ball, Paddle *paddle, Brick bricks[], int num_bricks, 
                     Wall *left_wall, Wall *right_wall, Ceiling *ceiling, Floor *floor, Game *game) {

    /* Variable declarations */
    Brick *brick;
    int overlap_x;
    int overlap_y;

    /* Wall collisions */
    if (ball->x <= left_wall->x || ball->x + ball->size_x >= right_wall->x) {
        ball->delta_x = -ball->delta_x;  /*Bounce off left/right wall*/
    }
    if (ball->y <= ceiling->y) {
        ball->delta_y = -ball->delta_y;  /*Bounce off ceiling*/
    }

    /* Paddle collision */
    if (ball->y + ball->size_y >= paddle->y && 
        ball->x + ball->size_x > paddle->x && 
        ball->x < paddle->x + paddle->size_x) {
        
        ball->delta_y = -ball->delta_y;  /*Bounce off paddle*/
    }

    /* Brick collision */
    brick = find_brick(ball, bricks, num_bricks);
    if (brick) {
        brick->health--;
        if (brick->health <= 0) {
            brick->isBroken = 1;
            game->score += brick->base_points;
        }

        /* Simple bounce: Flip whichever direction had the most overlap */
        overlap_x = (ball->x + ball->size_x) - brick->x;
        overlap_y = (ball->y + ball->size_y) - brick->y;
        
        if (overlap_x > overlap_y) {
            ball->delta_y = -ball->delta_y;  /*Bounce vertically*/
        } else {
            ball->delta_x = -ball->delta_x;  /*Bounce horizontally*/
        }
    }

    /* Ball falls below paddle (lose a life) */
    if (ball->y >= floor->y) {
        game->lives--;
        if (game->lives == 0) {
            game->game_over = 1;
        } else {
            reset_ball(ball, paddle);
        }
    }
}

void reset_ball (Ball *ball, Paddle *paddle) {
  ball->x = paddle->x + paddle->size_x/2;  /* Place ball in middle of paddle */
  ball->y = paddle->y - ball->size_y;  /* Place ball on top of paddle */
  ball->isActive = 0;
}

/* wait for ball input to enable ball start again */
void start_ball (Ball *ball) {
        ball->isActive = 1;
}

Brick *find_brick(Ball *ball, Brick bricks[], int num_bricks) {
  int i;
  for (i = 0; i < num_bricks; i++) {
      if (!bricks[i].isBroken &&
          ball->x < bricks[i].x + bricks[i].size_x &&
          ball->x + ball->size_x > bricks[i].x &&
          ball->y < bricks[i].y + bricks[i].size_y &&
          ball->y + ball->size_y > bricks[i].y) {
          
          return &bricks[i];  /*Return pointer to brick*/
      }
  }
  return NULL;  /*No collision*/
}


void check_broken (Brick *brick, Game *game) { /* Clear brick and award points */
  brick->health -= 1; /* decrement brick */

  if (brick->health == 0) {  /* Check if brick is broken */
    brick->isBroken = 1;  /* If so, brick isBroken = true; */
    game->score += brick->base_points;  /* Add to game score */
  }
}
