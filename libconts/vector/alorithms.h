#ifndef VECTOR_ALGORITHMS

#include "utils.h"

int vector_binary_compare(const void *a, const void *b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

VectorResult vector_binary_search(Vector *vector, void *element, int (*compare)(const void *, const void *), size_t *index) {
    if (vector == NULL || element == NULL || compare == NULL || index == NULL) return VectorFailure;

    size_t left = 0;
    size_t right = vector->size;

    while (left < right) {
        size_t mid = left + (right - left) / 2;
        void *midElement = (char *)vector->data + mid * vector->element_size;
        int cmpResult = compare(midElement, element);

        if (cmpResult == 0) {
            *index = mid;
            return VectorSuccess;
        } else if (cmpResult < 0) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return VectorFailure;
}

#endif // VECTOR_ALGORITHMS