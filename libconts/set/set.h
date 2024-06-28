#ifndef SET_H
#define SET_H

#include "../result.h"
#include <stddef.h>
#include <stdbool.h>

#define SetFailure ContsResultFailure
#define SetSuccess ContsResultSuccess

typedef struct SetNode {
    void *data;
    struct SetNode *next;
} SetNode;

typedef struct Set {
    SetNode *head;
    size_t element_size;
    size_t size;
} Set;

typedef ContsResultType SetResult; 

SetResult set_create(size_t element_size, Set *set);
SetResult set_destroy(Set *set);
SetResult set_insert(Set *set, void *element);
SetResult set_remove(Set *set, void *element);
bool set_contains(Set *set, void *element);
size_t set_size(Set *set);

#endif // SET_H
