#include "map.h"
#include <stdlib.h>
#include <string.h>

MapResult map_create(size_t key_size, size_t value_size, Map *mapOutput) {
    if (mapOutput == NULL) return MapFailure;

    mapOutput->key_size = key_size;
    mapOutput->value_size = value_size;

    if (vector_create(sizeof(MapPair), &mapOutput->pairs) != VectorSuccess) {
        return MapFailure;
    }

    return MapSuccess;
}

MapResult map_destroy(Map *map) {
    if (map == NULL) return MapFailure;

    for (size_t i = 0; i < map->pairs.size; i++) {
        MapPair pair;
        vector_get(&map->pairs, i, &pair);
        free(pair.key);
        free(pair.value);
    }

    vector_destroy(&map->pairs);
    map->key_size = 0;
    map->value_size = 0;

    return MapSuccess;
}

MapResult map_insert(Map *map, void *key, void *value) {
    if (map == NULL || key == NULL || value == NULL) return MapFailure;

    for (size_t i = 0; i < map->pairs.size; i++) {
        MapPair pair;
        vector_get(&map->pairs, i, &pair);
        if (memcmp(pair.key, key, map->key_size) == 0) {
            memcpy(pair.value, value, map->value_size);
            vector_set(&map->pairs, i, &pair);
            return MapSuccess;
        }
    }

    MapPair new_pair;
    new_pair.key = malloc(map->key_size);
    new_pair.value = malloc(map->value_size);
    if (new_pair.key == NULL || new_pair.value == NULL) {
        free(new_pair.key);
        free(new_pair.value);
        return MapFailure;
    }

    memcpy(new_pair.key, key, map->key_size);
    memcpy(new_pair.value, value, map->value_size);

    return vector_push_back(&map->pairs, &new_pair) == VectorSuccess ? MapSuccess : MapFailure;
}

MapResult map_get(Map *map, void *key, void *valueOutput) {
    if (map == NULL || key == NULL || valueOutput == NULL) return MapFailure;

    for (size_t i = 0; i < map->pairs.size; i++) {
        MapPair pair;
        vector_get(&map->pairs, i, &pair);
        if (memcmp(pair.key, key, map->key_size) == 0) {
            memcpy(valueOutput, pair.value, map->value_size);
            return MapSuccess;
        }
    }

    return MapFailure;
}

MapResult map_clear(Map *map) {
    if (map == NULL) return MapFailure;

    for (size_t i = 0; i < map->pairs.size; i++) {
        MapPair pair;
        vector_get(&map->pairs, i, &pair);
        free(pair.key);
        free(pair.value);
    }

    return vector_clear(&map->pairs) == VectorSuccess ? MapSuccess : MapFailure;
}
