typedef struct ball {
  unsigned int x, y; /* Position */
  int delta_x;  /* horizontal displacement per clock tick */
  int delta_y;  /* vertical displacement per clock tick */
  int isActive; /* Boolean for if ball is in play */
  int size_x;
  int size_y;
}

typedef struct brick {
  unsigned int x, y; /* Position */
  int isBroken; /* 1, or 0 boolean for broken or not broken */
  int base_points; /* Base number of points to award for breaking, can be multiplied by a number on higher levels */
  int size_x;
  int size_y;
  int health;
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
  int size_x; /* Size of paddle */
  int size_y;
  int p_input; /* 0 for left, 1 for right */
  int move_dist; /* Adjustable move distance of platform per button press, can change in settings */
}

typedef struct game {
  int score;  /* Total score */
  int lives;  /* Lives remaining */
  int level;  /* Keep track of current level */
  int game_over; /* Bool 0 for false, 1 for true */
  int paused; /* Bool 0 for false, 1 for true */
}
