#ifndef HASHMAP_H
#define HASHMAP_H

#include "../result.h"
#include <stddef.h>

#define HashMapFailure ContsResultFailure
#define HashMapSuccess ContsResultSuccess

typedef struct HashMapEntry {
    char *key;
    void *value;
    struct HashMapEntry *next;
} HashMapEntry;

typedef struct HashMap {
    size_t size;
    HashMapEntry **table;
} HashMap;

typedef ContsResultType HashMapResult;

HashMapResult hashmap_create(size_t size, HashMap* hashMapOutput);
HashMapResult hashmap_free(HashMap *map);
HashMapResult hashmap_put(HashMap *map, const char *key, void *value);
HashMapResult hashmap_get(HashMap *map, const char *key, void **output);
HashMapResult hashmap_remove(HashMap *map, const char *key);

#endif // HASHMAP_H