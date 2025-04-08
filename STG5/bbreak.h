#ifndef B_BREAKER_H
#define B_BREAKER_H

#include "TYPES.H"
#include "..\stg3\model.h"
#include "..\stg4\render.h"
#include <stdlib.h> 
#include <stdio.h>

void initialize_game(Game *game, Model *game_model, Wall *left_wall, Wall *right_wall, Ceiling *ceiling, Floor *floor);
void initialize_bricks(Brick bricks[], int num_bricks);
void process_input(Paddle *paddle, Ball *ball, Game *game);
/*
void render_brick(Brick *brick, UINT8 *base);
void render_all_bricks(Brick bricks[], int num_bricks, UINT8 *base);

UINT32 get_time();
*/
void render_clear_paddle(Paddle *paddle, UINT8 *base);

#endif