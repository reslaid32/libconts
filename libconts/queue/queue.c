#include "queue.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

QueueResult queue_create(size_t element_size, Queue *queue) {
    queue->data = malloc(element_size * INITIAL_CAPACITY);
    if (queue->data == NULL) {
        return QueueFailure;
    }
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = INITIAL_CAPACITY;
    queue->element_size = element_size;
    return QueueSuccess;
}

QueueResult queue_destroy(Queue *queue) {
    free(queue->data);
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = 0;
    queue->element_size = 0;
    return QueueSuccess;
}

static QueueResult queue_resize(Queue *queue, size_t new_capacity) {
    void *new_data = realloc(queue->data, queue->element_size * new_capacity);
    if (new_data == NULL) {
        return QueueFailure;
    }
    queue->data = new_data;
    queue->capacity = new_capacity;
    return QueueSuccess;
}

QueueResult queue_enqueue(Queue *queue, void *element) {
    if (queue->size >= queue->capacity) {
        if (queue_resize(queue, queue->capacity * 2) != QueueSuccess) {
            return QueueFailure;
        }
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    void *destination = (char *)queue->data + queue->rear * queue->element_size;
    memcpy(destination, element, queue->element_size);
    queue->size++;
    return QueueSuccess;
}

QueueResult queue_dequeue(Queue *queue, void *element) {
    if (queue->size == 0) {
        return QueueFailure;
    }
    void *source = (char *)queue->data + queue->front * queue->element_size;
    memcpy(element, source, queue->element_size);
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return QueueSuccess;
}

QueueResult queue_peek(Queue *queue, void *element) {
    if (queue->size == 0) {
        return QueueFailure;
    }
    void *source = (char *)queue->data + queue->front * queue->element_size;
    memcpy(element, source, queue->element_size);
    return QueueSuccess;
}
