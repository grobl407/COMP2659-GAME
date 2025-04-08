
#include "..\stg2\raster.h"
#include "..\stg3\model.h"
#include "TYPES.H"


void render(Model *model, UINT8 *base) {
    int i;
    render_walls(base);
    render_ball(&model->ball, base);
    render_paddle(&model->paddle, base);

	for (i = 0; i < 72; i++) {
		render_singlebrick(&model->bricks[i], base);
	} 
}

void render_ball(Ball *ball, UINT8 *base){
    plot_ball(base, ball->x, ball->y, ball->ball_bitmap);
}

void render_singlebrick(Brick *brick, UINT8 *base) {  /*Change parameter to Brick*/
    if(brick->health == 5){
        plot_brick(base, brick->x, brick->y, brick->full_brick_map);
    }
    if(brick->health == 4){
        plot_brick(base, brick->x, brick->y, brick->semi_cracked_map);
    }
    if(brick->health == 3 ){
        plot_brick(base, brick->x, brick->y, brick->cracked_map);
    }
    
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

void render_paddle(Paddle *paddle, UINT8 *base){
    plot_paddle(base, paddle->x, paddle->y, paddle->paddle_bitmap);
}
/*Render clear stuff*/
void render_clear_heart(Heart *heart, UINT8 *base){
    plot_heart(base, heart->x, heart->y, heart->clear_heart);
}

void clear_ball(Ball *ball, UINT8 *base){
    plot_ball(base, ball->x, ball->y, ball->clear_ball_bitmap);
}

void render_clear_paddle(Paddle *paddle, UINT8 *base){
    plot_paddle(base, paddle->x, paddle->y, paddle->clear_paddle);
}

void render_clear_brick(Brick *brick, UINT8 *base){
    plot_brick(base, brick->x, brick->y, brick->clear_brickmap);
}

/*render walls*/
void render_walls (UINT8 *base) {
	plot_vertline(base, 160, 30, 400); /* Plot left wall */
	plot_vertline(base, 480, 30, 400); /*Plot right wall*/
	plot_horizline(base, 160, 480, 85);
	plot_horizline(base, 160, 480, 30);

}

