#ifndef QUEUE_H
#define QUEUE_H

#include "../result.h"
#include <stddef.h>

#define QueueFailure ContsResultFailure
#define QueueSuccess ContsResultSuccess

typedef struct {
    void *data;
    long long front;       
    long long rear;        
    long long size;        
    long long capacity;    
    long long element_size;
} Queue;

typedef ContsResultType QueueResult;

QueueResult queue_create(size_t element_size, Queue *queue);
QueueResult queue_destroy(Queue *queue);

QueueResult queue_enqueue(Queue *queue, void *element);
QueueResult queue_dequeue(Queue *queue, void *element);
QueueResult queue_peek(Queue *queue, void *element);

#endif // QUEUE_H
