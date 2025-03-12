#include "raster.h"
#include <stdio.h>
#include <osbind.h>
#include <linea.h>
#include "TYPES.H"
#define HEART_COUNT 3
#define HEART_WIDTH 16
#define HEART_SPACING 4
#define HEART_COUNT 3
#define HEART_WIDTH 16
#define HEART_SPACING 4

int main() {

	test_clear_screen();
	test_plot_pixel();
	render_walls();
	/*test_horizline();*/
	/*test_horizline();*/
	bitmap_test_function();


	return 0;
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
	plot_horizline(base, 160, 480, 85);
	plot_horizline(base, 160, 480, 30);
	plot_horizline(base, 160, 480, 85);
	plot_horizline(base, 160, 480, 30);
	Cnecin();
}
/*
/*
void test_horizline () {
	UINT8 *base = Physbase();
	plot_horizline(base, 160, 480, 30); /* Plot horizontal line 
	plot_horizline(base, 160, 480, 30); /* Plot horizontal line 
	Cnecin();
}*/
}*/

void test_clear_screen() {
	clear_screen();
}

void bitmap_test_function() {
	UINT8 *base = Physbase(); /*frame buffer start*/
	UINT32 full_brick_map[7] = {
		0x7FFFFFE0,
		0xFFFFFFF0,
		0xFFFFFFF0,
		0xFFFFFFF0,
		0xFFFFFFF0,
		0xFFFFFFF0,
		0x7FFFFFE0,

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
	UINT32 platform_map[5] = {
		0x7FFFFFFE,
		0xFFFFFFFF,
		0xFFFFFFFF,
		0xFFFFFFFF,
		0x7FFFFFFE,
	};

	UINT16 heart_map[16] = {
		0x3E7C,
		0x77FE,
		0xEFFF,
		0xDFFF,
		0xBFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0xFFFF,
		0x7FFE,
		0x3FFC,
		0x1FF8,
		0x0FF0,
		0x07E0,
		0x03C0,
	};

	int x;	
	
	for(x = 170; x < 458; x += 32){
		plot_brick(base, x, 100, full_brick_map);
	}
	for(x = 170; x < 219; x += 24 ){
		plot_heart(base, x, 45, heart_map);
	}

	plot_ball(base, 150, 150, ball_bitmap);
	/*
	plot_heart(base, 175, 150, heart_map);
	plot_heart(base, 195, 150, heart_map);
	plot_heart(base, 210, 150, heart_map);
	*/


	/*
	plot_brick(base, 205, 170, full_brick_map);
	plot_brick(base, 210, 250, semi_cracked_map);
	plot_brick(base, 249, 350, cracked_brick_map);
	plot_brick(base, 288, 130, almost_broken_map);
	plot_brick(base, 327, 200, broken_brick_map);
	*/
	*/
	plot_paddle(base, 250, 350, platform_map);
	Cnecin();
}

