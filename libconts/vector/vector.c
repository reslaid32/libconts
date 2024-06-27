#include "vector.h"
#include <stdlib.h>
#include <string.h>

VectorResult vector_create(size_t element_size, Vector* vectorOutput) {
    if (vectorOutput == NULL) return VectorFailure;

    vectorOutput->data = malloc(element_size * 4);
    if (vectorOutput->data == NULL) return VectorFailure;

    vectorOutput->size = 0;
    vectorOutput->capacity = 4;
    vectorOutput->element_size = element_size;

    return VectorSuccess;
}

VectorResult vector_destroy(Vector *vector) {
    if (vector == NULL) return VectorFailure;

    free(vector->data);
    vector->data = NULL;
    vector->size = 0;
    vector->capacity = 0;
    vector->element_size = 0;

    return VectorSuccess;
}

VectorResult vector_push_back(Vector *vector, void *element) {
    if (vector == NULL || element == NULL) return VectorFailure;

    if (vector->size >= vector->capacity) {
        size_t new_capacity = vector->capacity * 2;
        void *new_data = realloc(vector->data, new_capacity * vector->element_size);
        if (new_data == NULL) return VectorFailure;

        vector->data = new_data;
        vector->capacity = new_capacity;
    }

    memcpy((char *)vector->data + vector->size * vector->element_size, element, vector->element_size);
    vector->size += 1;

    return VectorSuccess;
}

VectorResult vector_get(Vector *vector, size_t index, void *element) {
    if (vector == NULL || element == NULL || index >= vector->size) return VectorFailure;

    memcpy(element, (char *)vector->data + index * vector->element_size, vector->element_size);
    return VectorSuccess;
}

VectorResult vector_set(Vector *vector, size_t index, void *element) {
    if (vector == NULL || element == NULL || index >= vector->size) return VectorFailure;

    memcpy((char *)vector->data + index * vector->element_size, element, vector->element_size);
    return VectorSuccess;
}

VectorResult vector_clear(Vector *vector) {
    if (vector == NULL) return VectorFailure;

    vector->size = 0;
    return VectorSuccess;
}
