#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "model.h"
#include "raster.h"
#include "TYPES.h"

void print_ball_state (ball *ball) {
  printf("Ball X: %d, Y: %d, delta_x: %d, delta_y: %d,
    ball->x, ball->y, ball->delta_x, ball->delta_y");
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

void test_plot_pixel () {
	UINT8 *base = Physbase(); /* frame buffer start*/
	plot_pixel(base, 320, 200); /* Plot pixel in the middle */
	Cnecin();
}

void render_walls () {
	UINT8 *base = Physbase();
	plot_vertline(base, 160, 30, 400); /* Plot left wall */
	plot_vertline(base, 480, 30, 400);
	Cnecin();
}

void test_horizline () {
	UINT8 *base = Physbase();
	plot_horizline(base, 160, 480, 30); /* Plot horizontal line */
	Cnecin();
}

void test_clear_screen() {
	clear_screen();
}

void bitmap_test_function() {
	UINT8 *base = Physbase(); /*frame buffer start*/
	UINT32 full_brick_map[7] = {
		0x7FFFFFFE,
		0xFFFFFFFF,
		0xFFFFFFFF,
		0xFFFFFFFF,
		0xFFFFFFFF,
		0xFFFFFFFF,
		0x7FFFFFFE,

	};

	UINT32 semi_cracked_map[7] = {
		0x7FFFFFFE,
		0xFC7FFDFF,
		0xFF0FE1FF,
		0xFFF00FFF,
		0xFFFC41FF,
		0xFF83FFFF,
		0x7FFFFFFE,
	
	};
	UINT32 cracked_brick_map[7] = {
		0x7FFFFFFE,
		0xFC7EFDFF,
		0xFF0DE03F,
		0xE0F00FCF,
		0xCFFC41F3,
		0xDF83FEFF,
		0x7FFFFFFE,

	};
	UINT32 almost_broken_map[7] = {
		0x07FF7FFE,
		0x007EF1F7,
		0x0F008011,
		0x60F00F84,
		0xCFF801D3,
		0xDF830ECF,
		0x7FFF9F76,

	};
	UINT32 broken_brick_map[7] = {
		0x07FF7CFE,
		0x0076F1F7,
		0x0F008001,
		0x20C00C84,
		0x43F001D3,
		0x6981088F,
		0x00FF9436,

	};
	UINT16 ball_bitmap[8] = {
		0x3C,
		0x6E,
		0xDF,
		0xBF,
		0xFF,
		0xFF,
		0x7E,
		0x3C,
	};
	UINT64 platform_map[5] = {
		0xFFFFFFFFFF,
		0xBFFFFFFFFF,
		0xDFFFFFFFFF,
		0xEFFFFFFFFF,
		0xFFFFFFFFFF,
	};

	plot_ball(base, 150, 300, ball_bitmap);
	plot_brick(base, 171, 50, full_brick_map);
	plot_brick(base, 210, 250, semi_cracked_map);
	plot_brick(base, 249, 350, cracked_brick_map);
	plot_brick(base, 288, 130, almost_broken_map);
	plot_brick(base, 327, 200, broken_brick_map);
	plot_paddle(base, 250, 350, platform_map);
	Cnecin();
}

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

  wall left_wall = {160};
  wall right_wall = {480};
  ceiling celing = {0};
  floor floor = {400};

  ball ball = {320, 307, 2, 2, 1);

  paddle paddle = {280, 300, 64, 8, 0, 10};

  brick bricks[40];

  game game = {0, 3, 1, 0, 0};

  int bricks_per_row = 8;
  int num_bricks = 40; // 5 rows 8 bricks
  int brick_width = 32;
  int brick_height = 7;
  int spacing = 7;
  int start_x = 171;
  int start_y;
  
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
        find_brick(&ball, bricks, num_bricks, &game);

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

