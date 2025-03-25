#include "TYPES.H"
#include "..\stg2\raster.h"
#include "..\stg3\model.h"
#include "bitmap.h"
#include "render.h"
#include <osbind.h>


const int HEART_Y = 45;
const int PLATFORM_Y = 350;

void init_game(Model *model){
    /*initializing ball model*/
    model->ball.x = 260;
    model->ball.y = 342;
    model->ball.ball_bitmap = ball_bitmap;

    /*initializing platform model*/
    model->paddle.x = 250;
    model->paddle.y = PLATFORM_Y;
    model->paddle.paddle_bitmap = paddle_bitmap;
    /*initializing heart model*/
    model->heart.x = 170;
    model->heart.y = HEART_Y;
    model->heart.heart_map = heart_map;

    /*initializing brick model*/
    model->brick.x = 170;
    model->brick.y = 100;
    model->brick.full_brick_map = full_brick_map;
    model->brick.semi_cracked_map = semi_cracked_map;
    model->brick.cracked_brick_map = cracked_brick_map;
    model->brick.almost_broken_map = almost_broken_map;
    model->brick.broken_brick_map = broken_brick_map;


}

int main() {
    UINT8 *base = Physbase();
    Model game_model;

    init_game(&game_model);
    

    render(&game_model, base);
    render_singlebrick(&game_model, base);

    return 0;
}