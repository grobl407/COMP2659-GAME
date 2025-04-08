#include "bitmap.h"
#include "TYPES.H"


UINT32 full_brick_map[7] = {
    0x7FFFFFE0,
    0xFFFFFFF0,
    0xFFFFFFF0,
    0xFFFFFFF0,
    0xFFFFFFF0,
    0xFFFFFFF0,
    0x7FFFFFE0,

}; /*32x7 brick bitmap*/

UINT32 semi_cracked_map[7] = {     /*CHANGE ALL OF THE BRICK MAPS WITH THE GAP*/
    0x7FFFFFFE,
    0xFC7FFDFF,
    0xFF0FE1FF,
    0xFFF00FFF,
    0xFFFC41FF,
    0xFF83FFFF,
    0x7FFFFFFE,

}; /*32x7 brick bitmap*/

UINT32 cracked_brick_map[7] = {
    0x7FFFFFFE,
    0xFC7EFDFF,
    0xFF0DE03F,
    0xE0F00FCF,
    0xCFFC41F3,
    0xDF83FEFF,
    0x7FFFFFFE,

}; /*32x7 brick bitmap*/

UINT32 almost_broken_map[7] = {
    0x07FF7FFE,
    0x007EF1F7,
    0x0F008011,
    0x60F00F84,
    0xCFF801D3,
    0xDF830ECF,
    0x7FFF9F76,

}; /*32x7 brick bitmap*/

UINT32 broken_brick_map[7] = {
    0x07FF7CFE,
    0x0076F1F7,
    0x0F008001,
    0x20C00C84,
    0x43F001D3,
    0x6981088F,
    0x00FF9436,


}; /*32x7 brick bitmap*/

UINT32 clear_brickmap[7] ={
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
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
}; /*8x8 ball bitmap*/

UINT16 clear_ball_bitmap[8] = {
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
    0x00,
};

UINT32 paddle_bitmap[5] = {
    0x7FFFFFFE,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0xFFFFFFFF,
    0x7FFFFFFE,
}; /*32x5 paddle bitmap*/

UINT32 clear_paddle[5] = {
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000,
    0x00000000
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
};/*16x16 heart bitmap*/

UINT16 clear_heart[16] = {
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
    0x0000,
};/*16x16 clear heart bitmap*/