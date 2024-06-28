#include <stdio.h>
#include <assert.h>
#include <queue/queue.h>

void test_queue_basic_operations() {
    Queue queue;
    assert(queue_create(sizeof(int), &queue) == QueueSuccess);

    int values[] = {1, 2, 3};

    assert(queue_enqueue(&queue, &values[0]) == QueueSuccess);
    assert(queue_enqueue(&queue, &values[1]) == QueueSuccess);
    assert(queue_enqueue(&queue, &values[2]) == QueueSuccess);

    int front_element;
    assert(queue_peek(&queue, &front_element) == QueueSuccess);
    assert(front_element == values[0]);

    assert(queue_dequeue(&queue, &front_element) == QueueSuccess);
    assert(front_element == values[0]);
    assert(queue_dequeue(&queue, &front_element) == QueueSuccess);
    assert(front_element == values[1]);
    assert(queue_dequeue(&queue, &front_element) == QueueSuccess);
    assert(front_element == values[2]);

    assert(queue_dequeue(&queue, &front_element) == QueueFailure);

    assert(queue_destroy(&queue) == QueueSuccess);
}