#ifndef RENDER_H
#define RENDER_H

#include "objects.h"
#include "types.h"
#include <stdlib.h> 
#include <stdio.h>



void render(Model *model, UINT8 *base); 
void render_ball(Ball *ball, UINT8 *base);
void render_brick(Brick *brick, UINT8 *base);
void render_heart(Heart *heart, UINT8 *base);
void render_platform(Platform *platform, UINT8 *base);
void render_walls(UINT8 *base);
void render_singlebrick(Brick *brick, UINT8 *base);
#endif