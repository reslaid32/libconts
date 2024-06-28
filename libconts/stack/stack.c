#include "stack.h"
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 10

StackResult stack_create(size_t element_size, Stack *stack) {
    stack->data = malloc(element_size * INITIAL_CAPACITY);
    if (stack->data == NULL) {
        return StackFailure;
    }
    stack->size = 0;
    stack->capacity = INITIAL_CAPACITY;
    stack->element_size = element_size;
    return StackSuccess;
}

StackResult stack_destroy(Stack *stack) {
    free(stack->data);
    stack->size = 0;
    stack->capacity = 0;
    stack->element_size = 0;
    return StackSuccess;
}

static StackResult stack_resize(Stack *stack, size_t new_capacity) {
    void *new_data = realloc(stack->data, stack->element_size * new_capacity);
    if (new_data == NULL) {
        return StackFailure;
    }
    stack->data = new_data;
    stack->capacity = new_capacity;
    return StackSuccess;
}

StackResult stack_push(Stack *stack, void *element) {
    if (stack->size >= stack->capacity) {
        if (stack_resize(stack, stack->capacity * 2) != StackSuccess) {
            return StackFailure;
        }
    }
    void *destination = (char *)stack->data + stack->size * stack->element_size;
    memcpy(destination, element, stack->element_size);
    stack->size++;
    return StackSuccess;
}

StackResult stack_pop(Stack *stack, void *element) {
    if (stack->size == 0) {
        return StackFailure;
    }
    stack->size--;
    void *source = (char *)stack->data + stack->size * stack->element_size;
    memcpy(element, source, stack->element_size);
    return StackSuccess;
}

StackResult stack_peek(Stack *stack, void *element) {
    if (stack->size == 0) {
        return StackFailure;
    }
    void *source = (char *)stack->data + (stack->size - 1) * stack->element_size;
    memcpy(element, source, stack->element_size);
    return StackSuccess;
}
