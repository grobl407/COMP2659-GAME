#include "raster.h"
#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"

int main() {

	test_clear_screen();
	test_plot_pixel();
	test_vertline();
	test_horizline();
	bitmap_test_function();
	test_plot_rectangle();
	

	return 0;
}

void test_plot_pixel () {
	UINT8 *base = Physbase(); /* frame buffer start*/
	plot_pixel(base, 320, 200); /* Plot pixel in the middle */
	Cnecin();
}

void test_vertline () {
	UINT8 *base = Physbase();
	plot_vertline(base, 320, 100, 300); /* Plot vertical line in the middle*/
	Cnecin();
}

void test_horizline () {
	UINT8 *base = Physbase();
	plot_horizline(base, 0, 639, 200); /* Plot horizontal line */
	Cnecin();
}

void test_clear_screen() {
	clear_screen();
}

void bitmap_test_function() {
	UINT8 *base = Physbase(); /*frame buffer start*/

	UINT16 full_brick_map[8] = {
		0x7FFFFE,
		0xFFFFFF,
		0xFFFFFF,
		0xFFFFFF,
		0xFFFFFF,
		0xFFFFFF,
		0xFFFFFF,
		0x7FFFFE,
	};

	UINT16 semi_cracked_map[8] = {
		0x7FFFFE,
		0xFFFFFF,
		0xF83FFF,
		0xFF9FFF,
		0xFFC3FF,
		0xFFF87F,
		0xFFFF3F,
		0x7FFFFE,
	};
	UINT16 cracked_brick_map[8] = {
		0x7FFFFE,
		0xFFFFCF,
		0xF83F8F,
		0xFF9F3F,
		0xFF807F,
		0xFCB87F,
		0xFE3F3F,
		0x7FFFFE,
	};
	UINT16 almost_broken_map[8] = {
		0x1FFFC0,
		0x5FFFC0,
		0x983F85,
		0x3F9F31,
		0xFF807D,
		0xFCB87F,
		0xFE3F3E,
		0x7FFFFC,
	};
	UINT16 broken_brick_map[8] = {
		0x18FF80,
		0x567F83,
		0x803F09,
		0x0F1E62,
		0xDF00F8,
		0xD90000,
		0xD8600C,
		0x600328,
	};
	
	plot_brick(base, 20, 200, full_brick_map);
	plot_brick(base, 50, 200, semi_cracked_map);
	plot_brick(base, 80, 200, cracked_brick_map);
	plot_brick(base, 110, 200, almost_broken_map);
	plot_brick(base, 140, 200, broken_brick_map);
	Cnecin();
}

void test_plot_rectangle () {
	UINT8 *base = Physbase(); /*frame buffer start */
	plot_rectangle(base, 100, 200, 64, 64);
	Cnecin(); /*waits for user input */
}
