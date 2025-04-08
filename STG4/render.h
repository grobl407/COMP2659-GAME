#ifndef RENDER_H
#define RENDER_H

#include "..\stg3\model.h"
#include "types.h"
#include <stdlib.h> 
#include <stdio.h>



void render(Model *model, UINT8 *base); 
void render_ball(Ball *ball, UINT8 *base);
void render_brick(Brick *brick, UINT8 *base);
void render_heart(Heart *heart, UINT8 *base);
void render_paddle(Paddle *paddle, UINT8 *base);
void render_walls(UINT8 *base);
void render_singlebrick(Brick *brick, UINT8 *base);
/*render clear functions*/
void render_clear_brick(Brick *brick, UINT8 *base);
void render_clear_paddle(Paddle *paddle, UINT8 *base);
void render_clear_heart(Heart *heart, UINT8 *base);
void clear_ball(Ball *ball, UINT8 *base);
#endif