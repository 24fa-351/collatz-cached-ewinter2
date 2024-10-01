#include <stdbool.h>
#include <stdint.h>

#ifndef CACHE_H
#define CACHE_H

#include "collatz.h"

#define CACHE_SIZE 1000000 //Define maximum cache size here

//Cache structure 
typedef struct {
    int number;
    int steps;
} CacheEntry;

void initialize_cache();

int search_cache(int num);

int collatz_steps_cached(int num);


#endif