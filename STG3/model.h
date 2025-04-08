#ifndef MODEL_H
#define MODEL_H

#include "TYPES.H"
#include "..\stg4\bitmap.h"
#define NUM_BRICKS 72

typedef struct {
  unsigned int x, y; /* Position */
  unsigned int delta_x;  /* horizontal displacement per clock tick */
  unsigned int delta_y;  /* vertical displacement per clock tick */
  int isActive; /* Boolean for if ball is in play */
  int size_x;
  int size_y;
  UINT16 *ball_bitmap;
  UINT16 *clear_ball_bitmap;
} Ball;

typedef struct {
  unsigned int x, y; /* Position */
  int isBroken; /* 1, or 0 boolean for broken or not broken */
  int base_points; /* Base number of points to award for breaking, can be multiplied by a number on higher levels */
  int size_x;
  int size_y;
  int health;


  UINT32 *full_brick_map;
  UINT32 *semi_cracked_map;
  UINT32 *cracked_brick_map;
  UINT32 *almost_broken_map;
  UINT32 *broken_brick_map;
  UINT32 *clear_brickmap;
} Brick;

typedef struct {
  unsigned int x; /* Horizontal position */
} Wall;

typedef struct {
  unsigned int y; /* Vertical position */
} Ceiling;

typedef struct {
  unsigned int y; /* Vertical position */
} Floor;

typedef struct {
  unsigned int x, y; /* Position */
  int size_x; /* Size of paddle */
  int size_y;
  int p_input; /* 0 for left, 1 for right */
  int move_dist; /* Adjustable move distance of platform per button press, can change in settings */
  UINT32 *paddle_bitmap;
  UINT32 *clear_paddle;

} Paddle;

typedef struct {
  int x, y;
  UINT16 *heart_map;

}Heart;

typedef struct {
  Brick brick;
  Ball ball;
  Paddle paddle;
  Heart heart;
  Brick bricks[NUM_BRICKS];
} Model;


typedef struct {
  int score;  /* Total score */
  int lives;  /* Lives remaining */
  int level;  /* Keep track of current level */
  int game_over; /* Bool 0 for false, 1 for true */
  int paused; /* Bool 0 for false, 1 for true */
} Game;



void ball_collisions(Ball *ball, Paddle *paddle, Brick bricks[], int num_bricks, 
  Wall *left_wall, Wall *right_wall, Ceiling *ceiling, Floor *floor, Game *game);

Brick *find_brick(Ball *ball, Brick bricks[], int num_bricks);
void reset_ball (Ball *ball, Paddle *paddle);
void move_paddle (Paddle *paddle, int direction);
void move_ball (Ball *ball);
void check_broken (Brick *brick, Game *game);
void start_ball (Ball *ball);

#endif