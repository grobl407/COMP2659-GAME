#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 400

void move_ball (Ball *ball) {
  ball->x += ball->delta_x;
  ball->y += ball->delta_y;
}

void move_paddle (Paddle *paddle, int direction) {
  if (direction == 0) { /* moving left */
    if (paddle->x > 0)
      paddle->x -= paddle->move_dist;
  }
  else {
    if (paddle->x + paddle->x < SCREEN_WIDTH)
      paddle->x += paddle->move_dist;
  }
}
