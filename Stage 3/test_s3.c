#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "model.h"
#include "raster.h"
#include "TYPES.h"

void print_ball_state (Ball *ball) {
  printf("Ball X: %d, Y: %d, delta_x: %d, delta_y: %d\n",
    ball->x, ball->y, ball->delta_x, ball->delta_y);
}

void print_paddle_state (Paddle *paddle) {
  printf("Paddle left: %d, right: %d, Y: %d\n",
    paddle->x, paddle->x + paddle->size_x, paddle->y);
}

void print_brick_state (int index, Brick *brick) {
  printf("Brick collision index: %d, x: %d, y: %d, broken: %d\n",
    index, brick->x, brick->y, brick->isBroken);
}

void print_life_lost (Game *game) {
  printf("Life lost, %d lives remaining. \n",
    game->lives);
}

int main() {
/* initialize game elements */

  Wall left_wall = {160};
  Wall right_wall = {480};
  Ceiling ceiling = {0};
  Floor floor = {400};

  Ball ball = {320, 307, 2, 2, 1, 8, 7};

  Paddle paddle = {280, 300, 64, 8, 0, 10};

  Brick bricks[40];

  Game game = {0, 3, 1, 0, 0};

  int bricks_per_row = 8;
  int num_bricks = 40; // 5 rows 8 bricks
  int brick_width = 32;
  int brick_height = 7;
  int spacing = 7;
  int start_x = 170;
  int start_y = 100;
  
  for (int i = 0; i < num_bricks; i++) {
    int row = i / bricks_per_row;
    int column = i % bricks_per_row;

    bricks[i].x = start_x + column * (brick_width + spacing);
    bricks[i].y = start_y + row * (brick_height + spacing);
    bricks[i].isBroken = 0;
    bricks[i].base_points = 10;
    bricks[i].size_x = brick_width;
    bricks[i].size_y = brick_height;
    bricks[i].health = 5;
  }

  char key;
  while (1) {
	printf("Controls: a - left, d - right, space - tick, q - quit: ");
    	scanf(" %c", &key);

      if (key == 'a') { // Move paddle left
        move_paddle(&paddle, 0);
        print_paddle_state(&paddle);
      }
      else if (key == 'd') { // Move paddle right
        move_paddle(&paddle, 1);
        print_paddle_state(&paddle);
      }
      else if (key == ' ') { // Space simulates one tick
        move_ball(&ball);

        int initial_x = ball.x;
        int initial_y = ball.y;
        ball_collisions(&ball, &paddle, bricks, num_bricks, &left_wall, &right_wall, &ceiling, &floor, &game);

        if (ball.x != initial_x || ball.y != initial_y) { // Print ball state if it has moved
          print_ball_state(&ball);
        }

        // Check which brick was hit
        Brick* hit_brick = find_brick(&ball, bricks, num_bricks, &game);
	if (hit_brick != NULL) {
  		print_brick_state(hit_brick - bricks, hit_brick); // Print the index and state of the hit brick
	}

        if (game.lives == 0) {
          game.game_over = 1;
        }
      }
      else if (key == 'q') {
        return 0;
      }
    }
  }
  return 0;
}

