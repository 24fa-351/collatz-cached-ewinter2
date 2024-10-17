#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char *policy = argv[4]; // policy for cache
    int cache_size = atoi(argv[5]); //size of cache

    if (N <= 0 || MIN <= 0 || MAX <= 0 || MIN > MAX || 
            strcmp(policy, "LRU") != 0 && strcmp(policy, "MRU") != 0) {
        printf("Invalid arguments: N must be positive, and MIN must be <= MAX.\n");
        return 1;
    }

    if (strcmp(policy, "LRU") == 0) {
        // Implement logic for LRU (default)
        printf("Using LRU policy\n");
    } else if (strcmp(policy, "MRU") == 0) {
        // Implement logic for MRU 
        printf("Using MRU policy\n");
    }

    initialize_cache(cache_size);

    for (int i = 0; i < N; i++) {
        int number = MIN + rand() % (MAX - MIN + 1); 
        int steps = get_collatz_steps_to_one(number, policy);
        printf("Collatz sequence steps for %d: %d\n", number, steps);
    }

    cleanup_cache();

    return 0;
}