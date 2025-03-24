#ifndef RENDER_H
#define RENDER_H

#include "objects.h"
#include "types.h"
#include <stdlib.h>
#include <stdio.h>

/*const in the functions means it cannot modify the bitmaps (position, bitmap pointer) only draw it*/

void render(const Model *model, UINT8 *base); 
void render_ball(const Ball *ball, UINT8 *base);
void render_brick(const Brick *brick, UINT8 *base);
void render_heart(const Heart *heart, UINT8 *base);
void render_platform(const Platform *platform, UINT8 *base);

#endif