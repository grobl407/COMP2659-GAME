#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "model.h"
#include "raster.h"
#include "TYPES.h"

void print_ball_state(Ball *ball) {
    printf("Ball: x=%u, y=%u, delta_x=%d, delta_y=%d, isActive=%d\n",
           ball->x, ball->y, ball->delta_x, ball->delta_y, ball->isActive);
}

void print_paddle_state(Paddle *paddle) {
    printf("Paddle: x=%u, y=%u, size_x=%d, size_y=%d\n",
           paddle->x, paddle->y, paddle->size_x, paddle->size_y);
}

void print_game_state(Game *game) {
    printf("Game: score=%d, lives=%d, level=%d, game_over=%d, paused=%d\n",
           game->score, game->lives, game->level, game->game_over, game->paused);
}

int main() {
    // Initialize game objects
    Ball ball = {320, 200, 2, -2, 1, 10, 10};
    Paddle paddle = {300, 390, 100, 10, 0, 10};
    Brick bricks[10];
    Wall left_wall = {0};
    Wall right_wall = {640};
    Ceiling ceiling = {0};
    Floor floor = {400};
    Game game = {0, 3, 1, 0, 0};

    // Initialize some bricks
    for (int i = 0; i < 10; i++) {
        bricks[i] = (Brick){i * 60, 50, 0, 10, 60, 20, 1};
    }

    // Print initial state
    printf("Initial State:\n");
    print_ball_state(&ball);
    print_paddle_state(&paddle);
    print_game_state(&game);
    printf("\n");

    // Simulate a few clock ticks
    for (int i = 0; i < 5; i++) {
        move_ball(&ball);
        ball_collisions(&ball, &paddle, bricks, 10, &left_wall, &right_wall, &ceiling, &floor, &game);
        printf("After clock tick %d:\n", i + 1);
        print_ball_state(&ball);
        print_paddle_state(&paddle);
        print_game_state(&game);
        printf("\n");
    }

    // Simulate paddle movement
    move_paddle(&paddle, 0); // Move left
    printf("After moving paddle left:\n");
    print_ball_state(&ball);
    print_paddle_state(&paddle);
    print_game_state(&game);
    printf("\n");

    move_paddle(&paddle, 1); // Move right
    printf("After moving paddle right:\n");
    print_ball_state(&ball);
    print_paddle_state(&paddle);
    print_game_state(&game);
    printf("\n");

    // Simulate ball reset
    reset_ball(&ball, &paddle);
    printf("After resetting ball:\n");
    print_ball_state(&ball);
    print_paddle_state(&paddle);
    print_game_state(&game);
    printf("\n");

    return 0;
}

