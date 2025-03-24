
#include "../Stage 2/raster.h"
#include "game_objects.h"
#include "render.h"
#include "TYPES.H"

const int HEART_Y = 45;



void render(const Model *model, UINT8 *base){

}
void render_ball(const Ball *ball, UINT8 *base){
    plot_ball(base, ball->x, ball->y, ball->ball_bitmap);
}
void render_brick(const Brick *brick, UINT8 *base){

}
void render_heart(const Heart *heart, UINT8 *base){
    for(heart->x; heart->x < 219; heart->x += 24){
        plot_heart(base, heart->x, HEART_Y, heart->heart_map);
    }
}
void render_platform(const Platform *platform, UINT8 *base){

}