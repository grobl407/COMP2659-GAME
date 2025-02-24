typedef struct ball {
  unsigned int x, y; /* Position */
  int delta_x;  /* horizontal displacement per clock tick */
  int delta_y;  /* vertical displacement per clock tick */
  int isActive = 0; /* Boolean for if ball is in play */
  int size_x = 8;
  int size_y = 7;
}

typedef struct brick {
  unsigned int x, y; /* Position */
  int n_hits; /* Number of times the ball has hit brick */
  int isBroken; /* 1, or 0 boolean for broken or not broken */
  int base_points; /* Base number of points to award for breaking, can be multiplied by a number on higher levels */
  int size_x = 32;
  int size_y = 8;
  int health = 5;
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

typedef struct paddle {
  unsigned int x, y; /* Position */
  int size_x = 40; /* Size of paddle */
  int size_y = 5;
  int p_input = 0; /* 0 for left, 1 for right */
  int move_dist = 0; /* Adjustable move distance of platform per button press, can change in settings */
}

typedef struct game {
  int score;  /* Total score */
  int lives;  /* Lives remaining */
  int level;  /* Keep track of current level */
  int game_over; /* Bool 0 for false, 1 for true */
  int paused; /* Bool 0 for false, 1 for true */
}
