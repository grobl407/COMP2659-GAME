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
	UINT16 test_bitmap[16] = {
		0x0000,
		0x0000,
		0x0000,
		0x0000,
		0x03C0,
		0x07E0,
		0x0FF0,
		0x0FF0,
		0x0FF0,
		0x0FF0,
		0x07E0,
		0x03C0,
		0x0000,
		0x0000,
		0x0000,	
		0x0000,
	};
	plot_bitmap(base, 400, 200, test_bitmap);
	Cnecin();
}

void test_plot_rectangle () {
	UINT8 *base = Physbase(); /*frame buffer start */
	plot_rectangle(base, 100, 200, 64, 64);
	Cnecin(); /*waits for user input */
}
