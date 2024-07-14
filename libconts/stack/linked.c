#include <stdlib.h>
#include "linked.h"

LinkedStackResult linked_stack_init(LinkedStack* stack) {
    if (!stack) return LinkedStackFailure;
    stack->top = NULL;
    return LinkedStackSuccess;
}

LinkedStackResult linked_stack_push(LinkedStack* stack, void* data) {
    if (!stack || !data) return LinkedStackFailure;
    linked_stack_item_t* item = (linked_stack_item_t*)malloc(sizeof(linked_stack_item_t));
    if (!item) return LinkedStackFailure;
    item->data = data;
    item->down = stack->top;
    stack->top = item;
    return LinkedStackSuccess;
}

LinkedStackResult linked_stack_pop(LinkedStack* stack, void* output) {
    if (linked_stack_isempty(stack)) return LinkedStackFailure;
    if (!output) return LinkedStackFailure;
    linked_stack_item_t* item = stack->top;
    stack->top = stack->top->down;
    *(void**)output = item->data;
    free(item);
    return LinkedStackSuccess;
}

LinkedStackResult linked_stack_pick(LinkedStack const* stack, void* output) {
    if (linked_stack_isempty(stack)) return LinkedStackFailure;
    if (!output) return LinkedStackFailure;
    *(void**)output = stack->top->data;
    return LinkedStackSuccess;
}

LinkedStackResult linked_stack_flush(LinkedStack* stack) {
    if (!stack) return LinkedStackFailure;
    while (!linked_stack_isempty(stack)) {
        void* temp;
        linked_stack_pop(stack, &temp);
    }
    return LinkedStackSuccess;
}

LinkedStackResult linked_stack_destroy(LinkedStack* stack) {
    if (!stack) return LinkedStackFailure;
    linked_stack_flush(stack);
    return LinkedStackSuccess;
}

bool linked_stack_isempty(LinkedStack const* stack) {
    return stack->top == NULL;
}
