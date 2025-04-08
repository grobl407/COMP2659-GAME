#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#include "model.h"
#include <stdio.h>
#include <osbind.h>
#include <linea.h>
#include "..\STG4\render.h"
#include "TYPES.H"

UINT8 *base = Physbase();

void move_ball (Ball *ball) {
  if (ball->isActive == 1) {
    if (ball->x > 480) {
      ball->x = 472;
    } else if (ball->x < 160) {
      ball->x = 160;
    } else {
    ball->x += ball->delta_x;
    ball->y -= ball->delta_y;
    }
  }
}

void move_paddle (Paddle *paddle, int direction) {
  if (direction == 0 && paddle->x > 169) { /* moving left */
    if (paddle->x > 0)
      paddle->x -= paddle->move_dist;
  }
  else if (paddle->x < 448) {
    if (paddle->x + paddle->size_x < SCREEN_WIDTH)
      paddle->x += paddle->move_dist;
  }
}


void ball_collisions(Ball *ball, Paddle *paddle, Brick bricks[], int num_bricks, 
                     Wall *left_wall, Wall *right_wall, Ceiling *ceiling, Floor *floor, Game *game, UINT8 *base) {

    /* Variable declarations */
    Brick *brick;
    int overlap_x;
    int overlap_y;
    int overlap_left;
    int overlap_right;
    int overlap_top;
    int overlap_bottom;

    int min_overlap;
    int collision_side;

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

    /* Calculate overlap from all sides */
    overlap_left = (ball->x + ball->size_x) - brick->x;
    overlap_right = (brick->x + brick->size_x) - ball->x;
    overlap_top = (ball->y + ball->size_y) - brick->y;
    overlap_bottom = (brick->y + brick->size_y + 5) - ball->y;  /* Added +5 here */

    /* Find the smallest overlap */
    min_overlap = overlap_left;
    collision_side = 0; /* 0=left, 1=right, 2=top, 3=bottom */

    if (overlap_right < min_overlap) {
        min_overlap = overlap_right;
        collision_side = 1;
    }
    if (overlap_top < min_overlap) {
        min_overlap = overlap_top;
        collision_side = 2;
    }
    if (overlap_bottom < min_overlap) {
        min_overlap = overlap_bottom;
        collision_side = 3;
    }

    /* Bounce based on collision side */
    if (collision_side < 2) {
        ball->delta_x = -ball->delta_x;
    } else {
        ball->delta_y = -ball->delta_y;
    }
}
render_clear_brick(brick, base);

    /* Ball falls below paddle (lose a life) */
    if (ball->y >= floor->y) {
        game->lives--;
        ball->y = -ball->y;
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
          ball->y < bricks[i].y + bricks[i].size_y + 5 &&  /* Added +5 to bottom collision */
          ball->y + ball->size_y > bricks[i].y) {          /* Top collision remains normal */
          
          return &bricks[i];
      }
  }
  return NULL;
}

/*
void check_broken (Brick *brick, Game *game, UINT8 *base) { /* Clear brick and award points 
  brick->health -= 1; /* decrement brick 
  render_clear_brick(brick, base);
  if (brick->health == 0) {  /* Check if brick is broken 
    brick->isBroken = 1;  /* If so, brick isBroken = true; 
    game->score += brick->base_points;  /* Add to game score 
  }
}
*/
