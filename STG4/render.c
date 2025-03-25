
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

void render_singlebrick(Brick *brick, UINT8 *base){
    int x, y;
    brick->x = 50;
    brick->y = 300;
    UINT32 bootymap[7] = {
        0x7FFFFFE0,
        0xFFFFFFF0,
        0xFFFFFFF0,
        0xFFFFFFF0,
        0xFFFFFFF0,
        0xFFFFFFF0,
        0x7FFFFFE0,
    
    };

    plot_brick(base, brick->x, brick->y, bootymap);


}
void render_brick(Brick *brick, UINT8 *base){
    int x, y; /* Local variables for iteration */
    y = brick->y;
    for (x = brick->x; x < 459; x += 32) {
        if(x == 458){
            x = brick->x;
            y += 20;
            if (y == 260){
                break;
            }
        }
        plot_brick(base, x, y, brick->full_brick_map);
        
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