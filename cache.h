#include <stdbool.h>
#include <stdint.h>

#ifndef CACHE_H
#define CACHE_H

#include "collatz.h"

#define CACHE_SIZE 1000000 //Define maximum cache size here

//Cache Entry DLL Node 
typedef struct CacheEntry {
    int number;        // The number in the Collatz sequence
    int steps_to_one;
    struct CacheEntry *prev, *next;  // Pointers for DLL
} CacheEntry;

void initialize_cache(int max_size);
void cleanup_cache();
CacheEntry* search_cache(int number);
void insert_in_cache(int number, int steps_to_one);
int get_collatz_steps_to_one(int number);
void remove_node(CacheEntry* node);
void add_to_front(CacheEntry* node);


/*
void initialize_cache();

int search_cache(int num);

int collatz_steps_cached(int num);
*/

#endif