#include "collatz.h"

int collatz_steps(int num_to_collatz) {
    int steps = 0;
    while (num_to_collatz != 1) {
        if (num_to_collatz % 2 == 0) {
            num_to_collatz /= 2;
        }
        else {
            num_to_collatz = (num_to_collatz * 3) + 1;
        }
        steps++;
    }
    return steps;
}