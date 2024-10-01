#include <stdio.h>
#include <stdlib.h>

#include "cache.h"
#include "cache.c"

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Incorrect amount of variables.\n");
        return 1;
    }

    int N = atoi(argv[1]); //number of values to test 
    int MIN = atoi(argv[2]); //smallest value to test  
    int MAX = atoi(argv[3]); //largest value to test 

    if (N <= 0 || MIN <= 0 || MAX <= 0 || MIN > MAX) {
        printf("Invalid arguments: N must be positive, and MIN must be <= MAX.\n");
        return 1;
    }

    initialize_cache();

    //header for output 
    printf("Random Number, Steps\n");

    for (int i = 0; i < N; i++) {
        int random_number = MIN + rand() % (MAX - MIN + 1); //generates random number in given range 

        int steps = collatz_steps_cached(random_number);

        printf("%d, %d\n", random_number, steps);
    }

    return 0;
}