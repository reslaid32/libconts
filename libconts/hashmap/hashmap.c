
#include "hashmap.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static char* m_strdup(const char* src) {
    if (!src) return NULL;
    size_t len = strlen(src) + 1;
    char *dest = malloc(len);
    if (dest) {
        memcpy(dest, src, len);
    }
    return dest;
}

static unsigned long m_hash_function(const char *str) {
    unsigned long hash = 0x1505; // 5381
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

HashMapResult hashmap_create(size_t size, HashMap *hashMapOutput) {
    if (!hashMapOutput) return HashMapFailure;
    
    HashMap *map = malloc(sizeof(HashMap));
    if (!map) return HashMapFailure;

    map->size = size;
    map->table = calloc(size, sizeof(HashMapEntry*));
    if (!map->table) {
        free(map);
        return HashMapFailure;
    }

    *hashMapOutput = *map;
    free(map);
    return HashMapSuccess;
}

HashMapResult hashmap_free(HashMap *map) {
    if (!map) return HashMapFailure;

    for (size_t i = 0; i < map->size; i++) {
        HashMapEntry *entry = map->table[i];
        while (entry) {
            HashMapEntry *next = entry->next;
            free(entry->key);
            free(entry);
            entry = next;
        }
    }
    free(map->table);
    return HashMapSuccess;
}

HashMapResult hashmap_put(HashMap *map, const char *key, void *value) {
    if (!map || !key) return HashMapFailure;

    unsigned long hash = m_hash_function(key) % map->size;
    HashMapEntry *entry = map->table[hash];

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            entry->value = value;
            return HashMapSuccess;
        }
        entry = entry->next;
    }

    entry = malloc(sizeof(HashMapEntry));
    if (!entry) return HashMapFailure;

    entry->key = m_strdup(key);
    if (!entry->key) {
        free(entry);
        return HashMapFailure;
    }

    entry->value = value;
    entry->next = map->table[hash];
    map->table[hash] = entry;

    return HashMapSuccess;
}

HashMapResult hashmap_get(HashMap *map, const char *key, void **output) {
    if (!map || !key || !output) return HashMapFailure;

    unsigned long hash = m_hash_function(key) % map->size;
    HashMapEntry *entry = map->table[hash];

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            *output = entry->value;
            return HashMapSuccess;
        }
        entry = entry->next;
    }

    return HashMapFailure;
}

HashMapResult hashmap_remove(HashMap *map, const char *key) {
    if (!map || !key) return HashMapFailure;

    unsigned long hash = m_hash_function(key) % map->size;
    HashMapEntry *entry = map->table[hash];
    HashMapEntry *prev = NULL;

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            if (prev) {
                prev->next = entry->next;
            } else {
                map->table[hash] = entry->next;
            }
            free(entry->key);
            free(entry);
            return HashMapSuccess;
        }
        prev = entry;
        entry = entry->next;
    }

    return HashMapFailure;
}
