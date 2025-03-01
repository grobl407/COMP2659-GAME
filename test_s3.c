#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "model.h"

void print_ball_state (ball *ball) {
  printf("Ball X: %d, Y: %d, delta_x: %d, delta_y: %d,
    ball->x, ball->y, ball->delta_x, ball->delta_y);
}

void print_paddle_state (paddle *paddle) {
  printf("Paddle left: %d, right: %d, Y: %d\n",
    paddle->x, paddle->x + paddle_size_x, paddle->y);
}

void print_brick_state (int index, brick *brick) {
  printf("Brick collision index: %d, x: %d, y: %d, broken: %d\n",
    index, brick->x, brick->y, brick->isBroken);
}

void print_life_lost (game *game) {
  printf("Life lost, %d lives remaining. \n",
    game->lives);
}

int main() {
/* initialize game elements */

  wall left_wall;
  left_wall->x = 160;

  wall right_wall;
  right_wall->x = 480;

  ball ball;
  ball->ball_x = 320;
  ball->ball_y = 307;
  ball->delta_x = 2;
  ball->delta_y = 2;
  ball->isActive = 1;

  paddle paddle;
  paddle->x = 288;
  paddle->y = 300;
  paddle->move_dist = 10;

  brick bricks[40];

  game game;
  game->score = 0;
  game->lives = 3;
  game->level = 1;
  game->game_over = 0;

  int bricks_per_row = 8;
  int num_bricks = 40; // 5 rows 8 bricks

  for (int i = 0; i < num_bricks; i++) {
    brick *brick = &bricks[i];
    brick->x = 171 + (i % bricks_per_row) * 
