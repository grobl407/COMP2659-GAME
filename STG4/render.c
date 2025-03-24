
#include "..\stg2\raster.h"
#include "objects.h"
#include "TYPES.H"


void render(Model *model, UINT8 *base){
    clear_screen();
    render_walls(base);
    render_ball(&model->ball, base);
    render_platform(&model->platform, base);
    render_heart(&model->heart, base);
    render_brick(&model->brick, base);
}

void render_ball(Ball *ball, UINT8 *base){
    plot_ball(base, ball->x, ball->y, ball->ball_bitmap);
}

void render_brick(Brick *brick, UINT8 *base){
    for(brick->x; brick->x < 458; brick->x += 32){
        for(brick->y; brick->y < 260; brick->y += 20){
            plot_brick(base, brick->x, brick->y, brick->full_brick_map);
        }
    }
}

void render_heart(Heart *heart, UINT8 *base){
    for(heart->x; heart->x < 219; heart->x += 24){
        plot_heart(base, heart->x, heart->y, heart->heart_map);
    }
}

void render_platform(Platform *platform, UINT8 *base){
    plot_paddle(base, platform->x, platform->y, platform->platform_map);
}

void render_walls (UINT8 *base) {
	plot_vertline(base, 160, 30, 400); /* Plot left wall */
	plot_vertline(base, 480, 30, 400);
	plot_horizline(base, 160, 480, 85);
	plot_horizline(base, 160, 480, 30);
	plot_horizline(base, 160, 480, 85);
	plot_horizline(base, 160, 480, 30);

}