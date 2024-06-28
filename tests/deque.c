#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <deque/deque.h>

void test_deque_basic_operations() {
    Deque deque;
    assert(deque_create(sizeof(int), &deque) == DequeSuccess);

    int values[] = {1, 2, 3};
    int result;

    assert(deque_push_front(&deque, &values[0]) == DequeSuccess);
    assert(deque_push_back(&deque, &values[1]) == DequeSuccess);
    assert(deque_push_front(&deque, &values[2]) == DequeSuccess);

    assert(deque_front(&deque, &result) == DequeSuccess);
    assert(result == values[2]);
    assert(deque_back(&deque, &result) == DequeSuccess);
    assert(result == values[1]);

    assert(deque_pop_front(&deque, &result) == DequeSuccess);
    assert(result == values[2]);
    assert(deque_pop_back(&deque, &result) == DequeSuccess);
    assert(result == values[1]);

    assert(deque_clear(&deque) == DequeSuccess);
    assert(deque_destroy(&deque) == DequeSuccess);
}