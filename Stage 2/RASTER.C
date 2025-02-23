#include "raster.h"
#include "types.h"
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400	

void plot_pixel(UINT8 *base, int x, int y){
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT){
		*(base + y * 80 + (x >> 3)) |= 1 << (7 - (x & 7));   /*x >> 3 = x / 8, x & 7 = x % 8*/ 
	}
}

void plot_vertline(UINT8 *base, int x, int y_start, int y_end) {
	int temp;
	/*checking if x is within the screen dimensions*/
	if (x >= 0 && x < SCREEN_WIDTH){
		if (y_start > y_end){			/*Swapping y_start and y_end if they're in the wrong order*/
			temp = y_start;
			y_start = y_end;
			y_end = temp;
		}
		if (y_start < 0){			/*making sure y doesn't go past the top screen boundary*/
			y_start = 0;
		}
		if (y_end > 399){			/*Making sure y doesn't go past the bottom boundary*/
			y_end = 399;
		}
		for( ; y_start <= y_end; y_start++){		/*go through every y coordinate*/
			plot_pixel(base, x, y_start);			/*plot a pixel at that coordinate*/
		}
		return;
	}
}

void plot_horizline(UINT8 *base, int x_start, int x_end, int y){
	int temp;

	/*checking if y is within the screen*/
	if (y >= 0 && y < SCREEN_HEIGHT){

		/*Swapping x_start and x_end if in wrong order*/
		if (x_start > x_end){
			temp = x_start;
			x_start = x_end;
			x_end = temp;
		}
		/*making sure x_start doesn't go past the left screen boundary*/
		if (x_start < 0){
			x_start = 0;
		}
		/*Making sure x doesn't go past the right screen boundary*/
		if (x_end >= SCREEN_WIDTH){
			x_end = SCREEN_WIDTH - 1;
		}
		/*Loop through the x coordinates from start to end*/
		for (; x_start <= x_end; x_start++){
			plot_pixel(base, x_start, y);     /*plot a pixel at each coordinate*/
		}
	}
}


void clear_screen(){
	printf("\033E\033f\n");
}

void plot_ball(UINT8 *base, int x, int y, UINT16 bitmap[8]) {
	int row;  
    for (row = 0; row < 8; row++) {  /*iterate through rows*/
        unsigned short current_row = bitmap[row];   /*save current row data*/
        UINT8 *pixel_ptr = base + (y + row) * (SCREEN_WIDTH / 8) + (x / 8); /*calculate location*/

	int bit;
        for (bit = 0; bit < 16; bit++) {
            if (current_row & (1 << (7 - bit))) {
                pixel_ptr[bit/8] |= (1 << (7 - (bit % 8)));
            } else {
                pixel_ptr[(bit / 8)] &= ~(1 << (7 - (bit % 8)));  /*Clear the bit if not set*/
            }
        }
    }
}

void plot_brick (UINT8 *base, int x, int y, UINT16 bitmap[8]) {
	int row;
	for (row = 0; row < 8; row++) {  /* iterate through rows */
		UINT32 current_row = bitmap[row];
        	UINT8 *pixel_ptr = base + (y + row) * (SCREEN_WIDTH / 8) + (x / 8);

		int bit;
		for (bit = 0; bit < 24; bit++) {
			if (current_row & (1 << (23 - bit))) {
				pixel_ptr[bit / 8] |= (1 << (7 - (bit % 8 )));
			}
			else {
				pixel_ptr[bit / 8] &= ~(1 << (7 - (bit % 8)));
			}
        	}
    	}
}

void plot_paddle (UINT8 *base, int x, int y, UINT8 bitmap[5]) {
	int row;
	for (row = 0; row < 5; row++) {
		UINT16 current_row = bitmap[row];
		UINT8 *pixel_ptr = base + (y + row) * (SCREEN_WIDTH / 8) + (x / 8);

		int bit;
		for (bit = 0; bit < 40; bit ++) {
			if (current_row & (1 << (39 - bit))) {
				pixel_ptr[bit / 8] |= (1 << (7 - (bit % 8)));
			} else {
				pixel_ptr[bit / 8] &= ~(1 << (7 - (bit % 8)));
			}
		}
	}
}
		
