#ifndef B_BREAKER_H
#define B_BREAKER_H

void initialize_game(Game *game, Ball *ball, Paddle *paddle, Brick bricks[], int num_bricks, Wall *left_wall, Wall *right_wall, Ceiling *ceiling, Floor *floor);
void initialize_bricks(Brick *bricks[], int num_bricks);
void process_input(Paddle *paddle, Ball *ball);
void int main();
void void render_brick(Brick *brick, UINT8 *base);
void render_all_bricks(Brick bricks[], int num_bricks, UINT8 *base);

#endif B_BREAKER_H
