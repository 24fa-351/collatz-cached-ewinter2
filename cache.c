#include <stdio.h>

#include "cache.h"
#include "collatz.c"

CacheEntry cache[CACHE_SIZE];
int cache_count = 0; //tracking the size of the cache 

void initialize_cache() {
    cache_count = 0;
}

int search_cache(int num) {
    for (int i = 0; i < cache_count; i++) {
        if (cache[i].number == num) {
            return cache[i].steps;
        }
    }
    return -1;
}

int collatz_steps_cached(int num) {
    int cached_steps = search_cache(num);
    if (cached_steps != -1) {
        return cached_steps;
    }

    int steps = collatz_steps(num);

    //add result to cache 
    if (cache_count < CACHE_SIZE) {
        cache[cache_count].number = num; 
        cache[cache_count].steps = steps;
        cache_count++;
    }
    else {
        printf("Cache Full. Could not store new value.\n");
    }

    return steps;
}