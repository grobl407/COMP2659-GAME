#ifndef GAME_OBJECTS_H
#define GAME_OBJECTS_H

#include "TYPES.H"
#include "bitmap.h"


typedef struct {
    int x, y;
    UINT32 *full_brick_map;
    UINT32 *semi_cracked_map;
    UINT32 *cracked_brick_map;
    UINT32 *almost_broken_map;
    UINT32 *broken_brick_map;

}Brick;

typedef struct {
    int x, y;
    UINT16 *ball_bitmap;

}Ball;

typedef struct {
    int x, y;
    UINT32 *platform_map;

}Platform;

typedef struct {
    int x, y;
    UINT16 *heart_map;

}Heart;

typedef struct {
    Brick brick;
    Ball ball;
    Platform platform;
    Heart heart;
} Model;

#endif