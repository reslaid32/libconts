#ifndef DEQUE_H
#define DEQUE_H

#include "../result.h"
#include <stdlib.h>

#define DequeFailure ContsResultFailure
#define DequeSuccess ContsResultSuccess

typedef struct Deque {
    void *data;
    size_t front;
    size_t rear;
    size_t size;
    size_t capacity;
    size_t element_size;
} Deque;

typedef ContsResultType DequeResult;

DequeResult deque_create(size_t element_size, Deque *deque);
DequeResult deque_destroy(Deque *deque);
DequeResult deque_push_front(Deque *deque, void *element);
DequeResult deque_push_back(Deque *deque, void *element);
DequeResult deque_pop_front(Deque *deque, void *element);
DequeResult deque_pop_back(Deque *deque, void *element);
DequeResult deque_front(Deque *deque, void *element);
DequeResult deque_back(Deque *deque, void *element);
DequeResult deque_clear(Deque *deque);

#endif // DEQUE_H
