#include <osbind.h>
#include "..\stg3\model.h"
#include "..\stg4\render.h"
#include "..\stg4\bitmap.h"
#include "TYPES.H"
#include "bbreak.h"
#include <stdio.h>
#include <linea.h>


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

void initialize_game(Game *game, Model *game_model, Wall *left_wall, Wall *right_wall, Ceiling *ceiling, Floor *floor) {
  /* Initialize game struct */
  game->score = 0;
  game->lives = 3;
  game->level = 1;
  game->game_over = 0;
  game->paused = 0;

  /* Initialize ball */
  game_model->ball.x = SCREEN_WIDTH / 2;
  game_model->ball.y = 342;
  game_model->ball.delta_x = 1;
  game_model->ball.delta_y = 1;
  game_model->ball.isActive = 0;
  game_model->ball.size_x = 8;
  game_model->ball.size_y = 8;
  game_model->ball.ball_bitmap = ball_bitmap;


  /* Initialize paddle */
  game_model->paddle.x = 250;
  game_model->paddle.y = 350;
  game_model->paddle.size_x = 32;
  game_model->paddle.size_y = 5;
  game_model->paddle.p_input = 0;
  game_model->paddle.move_dist = 20;
  game_model->paddle.paddle_bitmap = paddle_bitmap;

  game_model->heart.x = 170;
  game_model->heart.y = 45;
  game_model->heart.heart_map = heart_map;

  /* Initialize walls */
  left_wall->x = 160;
  right_wall->x = 480;

  /* Initialize cailing */
  ceiling->y = 0;
  floor->y = SCREEN_HEIGHT;
}
/*
void initialize_bricks(Brick *bricks[], int num_bricks, ) {
  int brick_width = 28;
  int brick_height = 7;
  int start_x = 170;
  int start_y = 100;
  int max_y = 260;
  int max_x = 458;

  int i; /* Brick index 
  int y;
  int x;
  for (y = start_y; y < max_y; y += 20) {
    for (x = start_x; x < max_x; x += 32) {
      if (i >= num_bricks) {
        return;
      }

      bricks[i].x = x;
      bricks[i].y = y;
      bricks[i].size_x = brick_width;
      bricks[i].size_y = brick_height;
      bricks[i].isBroken = 0;
      bricks[i].base_points = 10;
      bricks[i].health = 5;

      i++;     
    }
  }
}
*/
void process_input(Paddle *paddle, Ball *ball) {
    if (Cconis()) {
        char ch = (char)Cnecin();

        if (ch == 'a') {
            move_paddle(paddle, 0); /* Move left */
        } else if (ch == 'd') {
            move_paddle(paddle, 1); /*Move right */
        } else if (ch == ' ') {
            start_ball(ball); /*Start the ball */
        }
    }
}

/*
  void render_brick(Brick *brick, UINT8 *base) {
    if (!brick->isBroken) {
        plot_brick(base, brick->x, brick->y, brick->full_brick_map);
    }
  }

  void render_all_bricks(Brick bricks[], int num_bricks, UINT8 *base) {
    int i;
    for (i = 0; i < num_bricks; i++) {
        render_brick(&bricks[i], base);
    }
  }
    */

UINT32 get_time() {
    long old_ssp;
    UINT32 timeNow;

    old_ssp = Super(0); /*Enter privileged mode*/
    timeNow = *(UINT32 *)0x462; /*Read the timer*/
    Super(old_ssp); /*Exit privileged mode*/

    return timeNow;
}

int main() {
  /* initialize structs */
  Model game_model;
  Game game;
  Wall left_wall;
  Wall right_wall;
  Ceiling ceiling;
  Floor floor;
  Paddle paddle;
  Ball ball;
  Brick bricks[27];
 

  UINT8 *base = Physbase();
  /* initialize game and bricks here */
  initialize_game(&game, &game_model, &left_wall, &right_wall, &ceiling, &floor);
  
  /* initialize_brick(bricks, 72); */

  render(&game_model, base);

  /*
  while (!game.game_over) {
    timeNow = get_time();
    timeElapsed = timeNow - timeThen;

    process_input(&paddle, &game_model.ball) {
    if (timeElapsed > 0) {      
  }
  */
  
  /*
  clear_ball(Ball *ball, UINT8 *base);
  move_ball (Ball *ball);
  ball_collisions(Ball *ball, Paddle *paddle, Brick bricks[], int num_bricks, Wall *left_wall, 
                     Wall *right_wall, Ceiling *ceiling, Floor *floor, Game *game);
  render_ball(Ball *ball, UINT8 *base);
  */
}
