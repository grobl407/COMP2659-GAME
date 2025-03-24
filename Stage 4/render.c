
#include "raster.h"
#include "objects.h"
#include "render.h"
#include "TYPES.H"




void render(const Model *model, UINT8 *base){
    render_ball(&model->ball, base);
    render_platform(&model->platform, base);
    render_heart(&model->heart, base);
    render_brick(&model->brick, base);
}

void render_ball(const Ball *ball, UINT8 *base){
    plot_ball(base, ball->x, ball->y, ball->ball_bitmap);
}

void render_brick(const Brick *brick, UINT8 *base){
    for(brick->x; brick->x < 458; brick->x +=32){
        for(brick->y; brick->y < 260; brick->y += 20){
            plot_brick(base, brick->x, brick->y, brick->full_brick_map);
        }
    }
}

void render_heart(const Heart *heart, UINT8 *base){
    for(heart->x; heart->x < 219; heart->x += 24){
        plot_heart(base, heart->x, heart->y, heart->heart_map);
    }
}

void render_platform(const Platform *platform, UINT8 *base){
    plot_paddle(base, platform->x, platform->y, platform->platform_map);
}