#include "deque.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

DequeResult deque_create(size_t element_size, Deque *deque) {
    deque->data = malloc(element_size * INITIAL_CAPACITY);
    if (deque->data == NULL) {
        return DequeFailure;
    }
    deque->front = 0;
    deque->rear = 0;
    deque->size = 0;
    deque->capacity = INITIAL_CAPACITY;
    deque->element_size = element_size;
    return DequeSuccess;
}

DequeResult deque_destroy(Deque *deque) {
    free(deque->data);
    deque->front = 0;
    deque->rear = 0;
    deque->size = 0;
    deque->capacity = 0;
    deque->element_size = 0;
    return DequeSuccess;
}

static DequeResult deque_resize(Deque *deque, size_t new_capacity) {
    void *new_data = realloc(deque->data, deque->element_size * new_capacity);
    if (new_data == NULL) {
        return DequeFailure;
    }
    deque->data = new_data;
    deque->capacity = new_capacity;
    return DequeSuccess;
}

DequeResult deque_push_front(Deque *deque, void *element) {
    if (deque->size >= deque->capacity) {
        if (deque_resize(deque, deque->capacity * 2) != DequeSuccess) {
            return DequeFailure;
        }
    }
    deque->front = (deque->front - 1 + deque->capacity) % deque->capacity;
    void *destination = (char *)deque->data + deque->front * deque->element_size;
    memcpy(destination, element, deque->element_size);
    deque->size++;
    return DequeSuccess;
}

DequeResult deque_push_back(Deque *deque, void *element) {
    if (deque->size >= deque->capacity) {
        if (deque_resize(deque, deque->capacity * 2) != DequeSuccess) {
            return DequeFailure;
        }
    }
    void *destination = (char *)deque->data + deque->rear * deque->element_size;
    memcpy(destination, element, deque->element_size);
    deque->rear = (deque->rear + 1) % deque->capacity;
    deque->size++;
    return DequeSuccess;
}

DequeResult deque_pop_front(Deque *deque, void *element) {
    if (deque->size == 0) {
        return DequeFailure;
    }
    void *source = (char *)deque->data + deque->front * deque->element_size;
    memcpy(element, source, deque->element_size);
    deque->front = (deque->front + 1) % deque->capacity;
    deque->size--;
    return DequeSuccess;
}

DequeResult deque_pop_back(Deque *deque, void *element) {
    if (deque->size == 0) {
        return DequeFailure;
    }
    deque->rear = (deque->rear - 1 + deque->capacity) % deque->capacity;
    void *source = (char *)deque->data + deque->rear * deque->element_size;
    memcpy(element, source, deque->element_size);
    deque->size--;
    return DequeSuccess;
}

DequeResult deque_front(Deque *deque, void *element) {
    if (deque->size == 0) {
        return DequeFailure;
    }
    void *source = (char *)deque->data + deque->front * deque->element_size;
    memcpy(element, source, deque->element_size);
    return DequeSuccess;
}

DequeResult deque_back(Deque *deque, void *element) {
    if (deque->size == 0) {
        return DequeFailure;
    }
    size_t last_index = (deque->rear == 0) ? deque->capacity - 1 : deque->rear - 1;
    void *source = (char *)deque->data + last_index * deque->element_size;
    memcpy(element, source, deque->element_size);
    return DequeSuccess;
}

DequeResult deque_clear(Deque *deque) {
    deque->front = 0;
    deque->rear = 0;
    deque->size = 0;
    return DequeSuccess;
}
