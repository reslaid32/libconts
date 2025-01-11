#ifndef MAP_H
#define MAP_H

#include "../result.h"
#include "../vector/vector.h"
#include <stddef.h>

#define MapFailure ContsResultFailure
#define MapSuccess ContsResultSuccess

typedef struct MapPair {
    void *key;
    void *value;
} MapPair;

typedef ContsResultType MapResult;

typedef struct Map {
    Vector pairs;
    size_t key_size;
    size_t value_size;
} Map;

MapResult map_create(size_t key_size, size_t value_size, Map *mapOutput);
MapResult map_destroy(Map *map);
MapResult map_insert(Map *map, void *key, void *value);
MapResult map_get(Map *map, void *key, void *valueOutput);
MapResult map_clear(Map *map);
MapResult map_lookup(Map *map, void *key, void **valueOutput);

#endif // MAP_H