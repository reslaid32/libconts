#include "set.h"
#include <stdlib.h>
#include <string.h>

SetResult set_create(size_t element_size, Set *set) {
    set->head = NULL;
    set->element_size = element_size;
    set->size = 0;
    return SetSuccess;
}

SetResult set_destroy(Set *set) {
    SetNode *current = set->head;
    while (current != NULL) {
        SetNode *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    set->head = NULL;
    set->size = 0;
    return SetSuccess;
}

static SetNode *set_find_node(Set *set, void *element) {
    SetNode *current = set->head;
    while (current != NULL) {
        if (memcmp(current->data, element, set->element_size) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

SetResult set_insert(Set *set, void *element) {
    SetNode *existing_node = set_find_node(set, element);
    if (existing_node != NULL) {
        return SetFailure;
    }

    SetNode *new_node = malloc(sizeof(SetNode));
    if (new_node == NULL) {
        return SetFailure;
    }

    new_node->data = malloc(set->element_size);
    if (new_node->data == NULL) {
        free(new_node);
        return SetFailure;
    }

    memcpy(new_node->data, element, set->element_size);
    new_node->next = set->head;
    set->head = new_node;
    set->size++;
    return SetSuccess;
}

SetResult set_remove(Set *set, void *element) {
    SetNode *prev = NULL;
    SetNode *current = set->head;

    while (current != NULL) {
        if (memcmp(current->data, element, set->element_size) == 0) {
            if (prev == NULL) {
                // Removing the head
                set->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current->data);
            free(current);
            set->size--;
            return SetSuccess;
        }
        prev = current;
        current = current->next;
    }
    return SetFailure;
}

bool set_contains(Set *set, void *element) {
    return set_find_node(set, element) != NULL;
}

size_t set_size(Set *set) {
    return set->size;
}
