#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#include "model.h"
#include <stdio.h>

void move_ball(Ball *ball) {
    if (ball->isActive == 1) {  // Fixed assignment operator
        ball->x += ball->delta_x;
        ball->y += ball->delta_y;
    }
}

void move_paddle(Paddle *paddle, int direction) {
    if (direction == 0) { /* moving left */
        if (paddle->x > 0)
            paddle->x -= paddle->move_dist;
    } else { /* moving right */
        if (paddle->x + paddle->size_x < SCREEN_WIDTH)  // Fixed incorrect condition
            paddle->x += paddle->move_dist;
    }
}

void ball_collisions(Ball *ball, Paddle *paddle, Brick bricks[], int num_bricks, Wall *left_wall, 
                      Wall *right_wall, Ceiling *ceiling, Floor *floor, Game *game) {
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

  *Brick brick = find_brick(&ball, &bricks, num_bricks, &game);

  /* Ball collides with brick */
  if (ball->y <= brick.y + brick.size_y && ball->x + ball->size_x >= brick.x &&
      ball->x <= brick.x + brick.size_x) {
        ball->delta_y = -ball->delta_y;
      }

  /*Ball collides with left of brick*/
  if (ball->y < brick.y + brick.size_y && ball->y < brick.y && ball->x >= brick.x){
    /*add velocity stuff*/
    ball->delta_x = -ball->delta_x;
  }
  /*Ball collides with right of brick*/
  if (ball->y < brick.y + brick.size_y && ball->y < brick.y && ball->x <= brick.x + brick.size_x){
    /*add velocity stuff*/
    ball->delta_x = -ball->delta_x;
  }
  /*ball collides with top of brick*/
  if(ball->y >= brick->y + brick->size_y && ball->x + ball->size_x >= brick->x &&
     ball->x <= brick->y + brick->size_x){
    ball->delta_y = -ball->delta_y;
  }

  /* Ball falls to floor */
  if (ball->y >= floor->y) {
    game->lives -= 1;
    if (game->lives == 0) {
      game->game_over = 1; /*Game over is true*/
    }

    if (ball->y + ball->size_y >= paddle->y && ball->x + ball->size_x >= paddle->x && 
        ball->x <= paddle->x + paddle->size_x) {
        ball->delta_y = -ball->delta_y;
    }

    Brick brick = find_brick(ball, bricks, num_bricks, game);

    if (brick.y != -1) { // Ensure brick is valid
        if (ball->y <= brick.y + brick.size_y && ball->x + ball->size_x >= brick.x &&
            ball->x <= brick.x + brick.size_x) {
            ball->delta_y = -ball->delta_y;
        }

        if (ball->y < brick.y + brick.size_y && ball->y < brick.y && ball->x >= brick.x) {
            ball->delta_x = -ball->delta_x;
        }

        if (ball->y < brick.y + brick.size_y && ball->y < brick.y && ball->x <= brick.x + brick.size_x) {
            ball->delta_x = -ball->delta_x;
        }

        if (ball->y >= brick.y + brick.size_y && ball->x + ball->size_x >= brick.x &&
            ball->x <= brick.x + brick.size_x) {
            ball->delta_y = -ball->delta_y;
        }
    }

    if (ball->y >= floor->y) {
        game->lives -= 1;
        if (game->lives == 0) {
            game->game_over = 1;
        } else {
            reset_ball(ball, paddle);
        }
    }
}

void reset_ball(Ball *ball, Paddle *paddle) {
    ball->x = paddle->x + paddle->size_x / 2;
    ball->y = paddle->y - ball->size_y;
    ball->isActive = 0;
}

void start_ball(Ball *ball) {
    /*Placeholder function (Cnenin was undefined)*/
    printf("Press any key to start the ball...\n");
    getchar();
    ball->isActive = 1;
}

Brick find_brick(Ball *ball, Brick bricks[], int num_bricks, Game *game) {
    for (int i = 0; i < num_bricks; i++) {
        if (!bricks[i].isBroken && 
            ball->y <= bricks[i].y + bricks[i].size_y &&
            ball->y + ball->size_y >= bricks[i].y &&
            ball->x + ball->size_x >= bricks[i].x &&
            ball->x <= bricks[i].x + bricks[i].size_x) {
            
            check_broken(&bricks[i], game);
            print_brick_state(i, &bricks[i]);
            return bricks[i];
        }
    }
    Brick empty = {-1, -1, 0, 0, 0, 1};  /*Return invalid brick*/
    return empty;
}

void check_broken(Brick *brick, Game *game) {
    brick->health -= 1;
    if (brick->health == 0) {
        brick->isBroken = 1;
        game->score += brick->base_points;
    }
}
