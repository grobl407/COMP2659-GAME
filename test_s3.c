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
