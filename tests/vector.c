#include <stdio.h>
#include <assert.h>
#include <vector.h>

void test_vector_basic_operations() {
    Vector vector;
    VectorResult result = vector_create(sizeof(int), &vector);
    assert(result == VectorSuccess);

    int element1 = 10;
    result = vector_push_back(&vector, &element1);
    assert(result == VectorSuccess);

    int element2 = 20;
    result = vector_push_back(&vector, &element2);
    assert(result == VectorSuccess);

    int retrieved_element;
    result = vector_get(&vector, 0, (void *)&retrieved_element);
    assert(result == VectorSuccess);
    assert(retrieved_element == element1);

    result = vector_set(&vector, 1, &element2);
    assert(result == VectorSuccess);

    result = vector_clear(&vector);
    assert(result == VectorSuccess);

    result = vector_destroy(&vector);
    assert(result == VectorSuccess);
}