typedef struct ball {
  unsigned int x, y; /* Position */
  int delta_x;  /* horizontal displacement per clock tick */
  int delta_y;  /* vertical displacement per clock tick */
  int brick_collide = 0;  /* Boolean for ball collision with brick */
  int wall_collide = 0;  /* Boolean for ball collision with wall */
  int platform_collide = 0;  /* Boolean for ball collision with platform */
  int isActive = 0; /* Boolean for if ball is in play */
}

typedef struct brick {
  unsigned int x, y; /* Position */
  int n_hits; /* Number of times the ball has hit brick */
  int broken; /* 1, or 0 boolean for broken or not broken */
  int base_points; /* Base number of points to award for breaking, can be multiplied by a number on higher levels */
}

typedef struct wall {
  unsigned int x; /* Horizontal position */
}

typedef struct ceiling {
  unsigned int y; /* Vertical position */
}

typedef struct floor {
  unsigned int y; /* Vertical position */
}

typedef struct platform {
  unsigned int x, y; /* Position */
  int p_input = 0; /* 0 for left, 1 for right */
  int move_dist = 0; /* Adjustable move distance of platform per button press, can change in settings */
}

typedef struct game {
  int score;  /* Total score */
  int lives;  /* Lives remaining */
  int level;  /* Keep track of current level */
  int game_over;
  int paused;
