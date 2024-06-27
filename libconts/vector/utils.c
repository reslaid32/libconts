#include "vector_utils.h"
#include <stdlib.h>

VectorResult vector_sort(Vector *vector, int (*compare)(const void *, const void *)) {
    if (vector == NULL || compare == NULL) return VectorFailure;

    qsort(vector->data, vector->size, vector->element_size, compare);
    return VectorSuccess;
}

VectorResult vector_find(Vector *vector, void *element, int (*compare)(const void *, const void *), size_t *index) {
    if (vector == NULL || element == NULL || compare == NULL || index == NULL) return VectorFailure;

    for (size_t i = 0; i < vector->size; i++) {
        void *currentElement = (char *)vector->data + i * vector->element_size;
        if (compare(currentElement, element) == 0) {
            *index = i;
            return VectorSuccess;
        }
    }
    return VectorFailure;
}