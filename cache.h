#include <stdbool.h>
#include <stdint.h>

#ifndef CACHE_H
#define CACHE_H

#include "collatz.h"

//Cache Entry DLL Node 
typedef struct CacheEntry {
    int number;        // The number in the Collatz sequence
    int steps_to_one;
    struct CacheEntry *prev, *next;  // Pointers for DLL
} CacheEntry;

void initialize_cache(int max_size);
void cleanup_cache();
CacheEntry* search_cache(int number);
void insert_in_cache(int number, int steps_to_one, char* policy_input);
int get_collatz_steps_to_one(int number, char* policy_input);
void remove_node(CacheEntry* node);
void add_to_front(CacheEntry* node);

#endif