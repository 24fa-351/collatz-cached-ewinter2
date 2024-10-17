#include <stdio.h>
#include <stdlib.h>

#include "cache.h"
#include "collatz.c"

static CacheEntry* head = NULL;  // MRU (most recently used) cache entry
static CacheEntry* tail = NULL;  // LRU (least recently used) cache entry
static int cache_size = 0;       // Current cache size
static int max_cache_size = 0;   // Maximum cache size

void initialize_cache(int max_size) {
    max_cache_size = max_size;
}

void cleanup_cache() {
    CacheEntry* current = head;
    while (current != NULL) {
        CacheEntry* next = current->next;
        free(current);
        current = next;
    }
    head = tail = NULL;
    cache_size = 0;
}

//search for a number in the cache (linear search)
CacheEntry* search_cache(int num) {
    CacheEntry* current = head;
    while (current != NULL) {
        if (current->number == num) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

//Add to the front (MRU) of the cache 
void add_to_front(CacheEntry* node) {
    node->next = head;
    node->prev = NULL;
    if (head != NULL) {
        head->prev = node;
    }
    head = node;
    if (tail == NULL) {
        tail = node;
    }
    cache_size++;
}

//Remove from the cache (LRU)
void remove_node(CacheEntry* node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    }
    else {
        head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    }
    else {
        tail = node->prev;
    }
    free(node);
    cache_size--;
}

void insert_in_cache(int num, int steps_to_one) {
    CacheEntry* new_entry = (CacheEntry*)malloc(sizeof(CacheEntry));
    new_entry->number = num;
    new_entry->steps_to_one = steps_to_one;
    add_to_front(new_entry);

    if(cache_size > max_cache_size) {
        remove_node(tail);
    }
}

int get_collatz_steps(int num) {
    CacheEntry *entry = search_cache(num);
    if (entry != NULL) {
        remove_node(entry);
        add_to_front(entry);
        return entry->steps_to_one;
    }

    int steps_calculated = collatz_steps(num);

    insert_in_cache(num, steps_calculated);

    return steps_calculated;
}