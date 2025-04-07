#include "input.h"
#include "..\stg3\model.h"
#include <osbind.h>

/* Checks if input is available */
int check_input(void) {
    return Cconis();
}

/* Processes input and updates model requests */
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