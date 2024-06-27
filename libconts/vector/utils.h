#ifndef VECTOR_UTILS_H
#define VECTOR_UTILS_H

#include "vector.h"

VectorResult vector_sort(Vector *vector, int (*compare)(const void *, const void *));
VectorResult vector_find(Vector *vector, void *element, int (*compare)(const void *, const void *), size_t *index);

#endif // VECTOR_UTILS_H
