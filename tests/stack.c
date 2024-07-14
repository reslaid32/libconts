#include <stdio.h>
#include <assert.h>
#include <stack/stack.h>
#include <stack/linked.h>

void test_stack_basic_operations() {
    Stack stack;
    assert(stack_create(sizeof(int), &stack) == StackSuccess);

    int values[] = {1, 2, 3};

    assert(stack_push(&stack, &values[0]) == StackSuccess);
    assert(stack_push(&stack, &values[1]) == StackSuccess);
    assert(stack_push(&stack, &values[2]) == StackSuccess);

    int top_element;
    assert(stack_peek(&stack, &top_element) == StackSuccess);
    assert(top_element == values[2]);

    assert(stack_pop(&stack, &top_element) == StackSuccess);
    assert(top_element == values[2]); 
    assert(stack_pop(&stack, &top_element) == StackSuccess);
    assert(top_element == values[1]);
    assert(stack_pop(&stack, &top_element) == StackSuccess);
    assert(top_element == values[0]);

    assert(stack_pop(&stack, &top_element) == StackFailure);

    assert(stack_destroy(&stack) == StackSuccess);
}

void test_linked_stack_basic_operations() {
    LinkedStack stack;
    assert(linked_stack_init(&stack) == LinkedStackSuccess);

    int values[] = {1, 2, 3};

    assert(linked_stack_push(&stack, &values[0]) == LinkedStackSuccess);
    assert(linked_stack_push(&stack, &values[1]) == LinkedStackSuccess);
    assert(linked_stack_push(&stack, &values[2]) == LinkedStackSuccess);

    int top_element;
    assert(linked_stack_pick(&stack, &top_element) == LinkedStackSuccess);
    assert(top_element == values[2]);

    assert(linked_stack_pop(&stack, &top_element) == LinkedStackSuccess);
    assert(top_element == values[2]); 
    assert(linked_stack_pop(&stack, &top_element) == LinkedStackSuccess);
    assert(top_element == values[1]);
    assert(linked_stack_pop(&stack, &top_element) == LinkedStackSuccess);
    assert(top_element == values[0]);

    assert(linked_stack_pop(&stack, &top_element) == LinkedStackFailure);

    assert(linked_stack_destroy(&stack) == LinkedStackSuccess);
}