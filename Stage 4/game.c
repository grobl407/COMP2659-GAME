#include "TYPES.H"
#include "render.h"
#include "game_objects.h"
#include "bitmap.h"

const int HEART_Y = 45;
const int PLATFORM_Y = 350;

void init_game(Model *model){
    /*initializing ball model*/
    model->ball.x = 260;
    model->ball.y = 342;
    model->ball.ball_bitmap = ball_bitmap;

    /*initializing platform model*/
    model->platform.x = 250;
    model->platform.y = 350;
    model->platform.platform_map = platform_bitmap;

    /*initializing heart model*/
    model->heart.x = 170;
    model->heart.y = 45;


}