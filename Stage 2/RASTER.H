#ifndef RASTER_H
#define RASTER_H

#include "types.h"
#include <stdlib.h>
#include <stdio.h>
/* [TO DO] the functions below are examples. Replace them! */

#define WIDTH 640
#define HEIGHT 400


void plot_pixel(UINT8 *base, int x, int y);
void plot_vertline(UINT8 *base, int x, int y_start, int y_end);
void plot_horizline(UINT8 *base, int x_start, int x_end, int y);
void clear_screen();
void plot_ball(UINT8 *base, int x, int y, UINT16 bitmap[8]);
void plot_brick (UINT8 *base, int x, int y, UINT32 bitmap[8]);
void plot_paddle (UINT8 *base, int x, int y, UINT64 bitmap[5]);

#endif
