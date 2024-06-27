#ifndef VECTOR_H
#define VECTOR_H

#include "../result.h"
#include <stddef.h>

#define VectorFailure ContsResultFailure
#define VectorSuccess ContsResultSuccess

typedef struct Vector {
    void *data;
    size_t size;        
    size_t capacity;    
    size_t element_size;
} Vector;

typedef ContsResultType VectorResult;

VectorResult vector_create(size_t element_size, Vector* vectorOutput);
VectorResult vector_destroy(Vector *vector);

VectorResult vector_push_back(Vector *vector, void *element);
VectorResult vector_get(Vector *vector, size_t index, void **element);
VectorResult vector_set(Vector *vector, size_t index, void *element);
VectorResult vector_clear(Vector *vector);

#endif // VECTOR_H