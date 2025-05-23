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
  game_model->ball.delta_x = 10;
  game_model->ball.delta_y = 5;
  game_model->ball.isActive = 0;
  game_model->ball.size_x = 8;
  game_model->ball.size_y = 8;
  game_model->ball.ball_bitmap = ball_bitmap;
  game_model->ball.clear_ball_bitmap = clear_ball_bitmap;


  /* Initialize paddle */
  game_model->paddle.x = 312;
  game_model->paddle.y = 350;
  game_model->paddle.size_x = 32;
  game_model->paddle.size_y = 5;
  game_model->paddle.p_input = 0;
  game_model->paddle.move_dist = 20;
  game_model->paddle.paddle_bitmap = paddle_bitmap;
  game_model->paddle.clear_paddle = clear_paddle;

  /*Initialize heart*/
  game_model->heart.x = 170;
  game_model->heart.y = 45;
  game_model->heart.heart_map = heart_map;
  game_model->heart.clear_heart = clear_heart;

  /* Initialize walls */
  left_wall->x = 160;
  right_wall->x = 480;

  /* Initialize cailing */
  ceiling->y = 85;
  floor->y = SCREEN_HEIGHT;
}
void initialize_bricks(Brick bricks[], int num_bricks) {
  int brick_length;
  int brick_height;
  int brick_spacing_x;
  int brick_spacing_y;
  int start_x;
  int start_y;
  int bricks_per_row;
  int num_rows;
  int brick_index;
  int row;
  int col;
  int x_pos;
  int y_pos;
  
  brick_length = 28;
  brick_height = 7;
  brick_spacing_x = 4;
  brick_spacing_y = 13;
  start_x = 170;
  start_y = 100;
  bricks_per_row = 9;
  num_rows = 8;
  brick_index = 0;
  
  for (row = 0; row < num_rows; row++) {
    int col;
    for (col = 0; col < bricks_per_row; col++) {
      if (brick_index >= num_bricks) {
        return;
      }
      bricks[brick_index].x = start_x + col * (brick_length + brick_spacing_x);
      bricks[brick_index].y = start_y + row * (brick_height + brick_spacing_y);
      bricks[brick_index].size_x = brick_length;
      bricks[brick_index].size_y = brick_height;
      bricks[brick_index].isBroken = 0;
      bricks[brick_index].base_points = 10;
      bricks[brick_index].health = 5;
      bricks[brick_index].full_brick_map = full_brick_map;
      bricks[brick_index].cracked_brick_map = cracked_brick_map;
      bricks[brick_index].semi_cracked_map = semi_cracked_map;
      bricks[brick_index].almost_broken_map = almost_broken_map;
      bricks[brick_index].broken_brick_map = broken_brick_map;
      bricks[brick_index].clear_brickmap = clear_brickmap;



      brick_index++;
    }
  }
}

void process_input(Paddle *paddle, Ball *ball, Game *game) {
    if (Cconis()) {
        char ch = (char)Cnecin();

        if (ch == 'a') {
            move_paddle(paddle, 0); /* Move left */
        } else if (ch == 'd') {
            move_paddle(paddle, 1); /*Move right */
        } else if (ch == ' ') {
            start_ball(ball); /*Start the ball */
        } else if (ch == 'q') {
          game->game_over = 1;
      }
    }
}

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
  int i;
  int j;
  Model game_model;
  Game game;
  Wall left_wall;
  Wall right_wall;
  Ceiling ceiling;
  Floor floor;
  Paddle paddle;
  Ball ball;
  Brick bricks[72];
  UINT32 timeNow;
  UINT32 timeThen;
  UINT32 timeElapsed;
 

  UINT8 *base = Physbase();
  /* initialize game and bricks here */
  initialize_game(&game, &game_model, &left_wall, &right_wall, &ceiling, &floor);
  initialize_bricks(bricks, 72);

  for (i = 0; i < 72; i++) {
    game_model.bricks[i] = bricks[i];
  }
  
  /* initialize_brick(bricks, 72); */

  clear_screen();
  render(&game_model, base);
  render_heart(&game_model.heart, base);
  for (j = 0; j < 72; j++) {
		render_singlebrick(&game_model.bricks[j], base);
	} 

  timeThen = get_time();

  while (!game.game_over) {
    timeNow = get_time();
    timeElapsed = timeNow - timeThen;

    /* Asynchronous events */
    render_clear_paddle(&game_model.paddle, base);
    process_input(&game_model.paddle, &game_model.ball, &game);
    

    /* Synchronous events */
    if (timeElapsed > 0) {
      if (game_model.ball.isActive) {
        /* Clear ball */
        clear_ball(&game_model.ball, base);
        /* Move ball */
        move_ball(&game_model.ball);
        /*check collisions*/
        ball_collisions(&game_model.ball, &game_model.paddle, &game_model.bricks, 72, 
          &left_wall, &right_wall, &ceiling, &floor, &game, base);
      }
      render(&game_model, base);
    }
    
  
  
  /*
  clear_ball(Ball *ball, UINT8 *base);
  move_ball (Ball *ball);
  ball_collisions(Ball *ball, Paddle *paddle, Brick bricks[], int num_bricks, Wall *left_wall, 
                     Wall *right_wall, Ceiling *ceiling, Floor *floor, Game *game);
  render_ball(Ball *ball, UINT8 *base);
  */
}
}
