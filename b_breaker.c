#include <osbind.h>
#include "model.h"
#include <stdio.h>
#include "render.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400
#define BRICK_WIDTH 32
#define BRICK_HEIGHT 7
#define COLUMNS 9
#define ROWS 8

void initialize_game(Game *game, Ball *ball, Paddle *paddle, Brick bricks[], int num_bricks, Wall *left_wall, Wall *right_wall, Ceiling *ceiling, Floor *floor) {
  /* Initialize game struct */
  game->score = 0;
  game->lives = 3;
  game->level = 1;
  game->game_over = 0;
  game->paused = 0;

  /* Initialize ball */
  ball->x = SCREEN_WIDTH / 2;
  ball->y = 342;
  ball->delta_x = 1;
  ball->delta_y = 1;
  ball->isActive = 0;
  ball->size_x = 8;
  ball->size_y = 8;

  /* Initialize paddle */
  paddle->x = 250;
  paddle->y = 350;
  paddle->size_x = 32;
  paddle->size_y = 5;
  paddle->20;

  /* Initialize walls */
  left_wall->x = 160;
  right_wall->x = 480;

  /* Initialize cailing */
  ceiling->y = 0;
  floor->y = SCREEN_HEIGHT;
}

void initialize_bricks(Brick bricks[], int num_bricks) {
  int brick_width = 28;
  int brick_height = 7;
  int start_x = 170;
  int start_y = 100;

  int i; /* Brick index */
  int y;
  int x;
  for (y = start_y; y < max_y; y += 20) {
    for (x = start_x; x < max_x; x += 32) {
      if (i >= num_bricks) {
        return;
      }

      bricks[i].x = x;
      bricks[i].y = y;
      bricks[i].size_x = brick_width;
      bricks[i].size_y = brick_height;
      bricks[i].isBroken = 0;
      bricks[i].base_points = 10;
      bricks[i].health = 5;

      i++;     
    }
  }
}

void process_input(Paddle *paddle, Ball *ball) {
    if (Cconis()) {
        char ch = (char)Cnecin();

        if (ch == 'a') {
            move_paddle(paddle, 0); // Move left
        } else if (ch == 'd') {
            move_paddle(paddle, 1); // Move right
        } else if (ch == ' ') {
            start_ball(ball); // Start the ball
        }
    }
}

int main() {
  /* initialize structs */
  Game game;
  Ball ball;
  Paddle paddle;
  Brick bricks[72];
  Wall left_wall;
  Wall right_wall;
  Ceiling ceiling;
  Floor floor;

  /* call initialize helper function */
  initialize_game(&game, &ball, &paddle, bricks, 72, &left_wall, &right_wall, &ceiling, &floor);



  /*
  clear_ball(Ball *ball, UINT8 *base);
  move_ball (Ball *ball);
  ball_collisions(Ball *ball, Paddle *paddle, Brick bricks[], int num_bricks, Wall *left_wall, 
                     Wall *right_wall, Ceiling *ceiling, Floor *floor, Game *game);
  render_ball(Ball *ball, UINT8 *base);
  */
}
