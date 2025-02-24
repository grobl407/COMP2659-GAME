#include "raster.h"
#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"

int main() {

	test_clear_screen();
	test_plot_pixel();
	render_walls();
	test_horizline();
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
	UINT32 full_brick_map[8] = {
		0x7FFFFE,
		0xFFFFFF,
		0xFFFFFF,
		0xFFFFFF,
		0xFFFFFF,
		0xFFFFFF,
		0xFFFFFF,
		0x7FFFFE,
	};

	UINT32 semi_cracked_map[8] = {
		0x7FFFFE,
		0xFFFFFF,
		0xF83FFF,
		0xFF9FFF,
		0xFFC3FF,
		0xFFF87F,
		0xFFFF3F,
		0x7FFFFE,
	};
	UINT32 cracked_brick_map[8] = {
		0x7FFFFE,
		0xFFFFCF,
		0xF83F8F,
		0xFF9F3F,
		0xFF807F,
		0xFCB87F,
		0xFE3F3F,
		0x7FFFFE,
	};
	UINT32 almost_broken_map[8] = {
		0x1FFFC0,
		0x5FFFC0,
		0x983F85,
		0x3F9F31,
		0xFF807D,
		0xFCB87F,
		0xFE3F3E,
		0x7FFFFC,
	};
	UINT32 broken_brick_map[8] = {
		0x18FF80,
		0x567F83,
		0x803F09,
		0x0F1E62,
		0xDF00F8,
		0xD90000,
		0xD8600C,
		0x600328,
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
	plot_brick(base, 20, 50, full_brick_map);
	plot_brick(base, 50, 250, semi_cracked_map);
	plot_brick(base, 80, 350, cracked_brick_map);
	plot_brick(base, 110, 130, almost_broken_map);
	plot_brick(base, 140, 200, broken_brick_map);
	plot_paddle(base, 250, 350, platform_map);
	Cnecin();
}

