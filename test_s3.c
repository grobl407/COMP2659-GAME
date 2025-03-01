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
  ball ball =
