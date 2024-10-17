#include <stdio.h>
#include <stdlib.h>

#include "cache.h"
#include "cache.c"

int main(int argc, char *argv[]) {

    if (argc != 6) {
        printf("Incorrect amount of variables.\n");
        return 1;
    }

    int N = atoi(argv[1]); //number of values to test 
    int MIN = atoi(argv[2]); //smallest value to test  
    int MAX = atoi(argv[3]); //largest value to test 
    char *policy = argv[4]; //policy for cache
    int cache_size = atoi(argv[5]); //size of cache
    
    //initialize_cache_size(cache_size); //size of cache 

    if (N <= 0 || MIN <= 0 || MAX <= 0 || MIN > MAX) {
        printf("Invalid arguments: N must be positive, and MIN must be <= MAX.\n");
        return 1;
    }

    initialize_cache(cache_size);

    //header for output 
    printf("Random Number, Steps\n");

    for (int i = 0; i < N; i++) {
        int random_number = MIN + rand() % (MAX - MIN + 1); //generates random number in given range 

        int steps_to_one = get_collatz_steps(random_number);

        printf("%d, %d\n", random_number, steps_to_one);
    }

    printf("Policy: %s\n", policy);

    printf("Cache Size: %d\n", cache_size);

    cleanup_cache();

    return 0;
}