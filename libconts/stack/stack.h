#ifndef STACK_H
#define STACK_H

#include "../result.h"
#include <stddef.h>

#define StackFailure ContsResultFailure
#define StackSuccess ContsResultSuccess

typedef struct {
    void *data;
    size_t size;        
    size_t capacity;    
    size_t element_size;
} Stack;

typedef ContsResultType StackResult;

StackResult stack_create(size_t element_size, Stack *stack);
StackResult stack_destroy(Stack *stack);

StackResult stack_push(Stack *stack, void *element);
StackResult stack_pop(Stack *stack, void *element);
StackResult stack_peek(Stack *stack, void *element);

#endif // STACK_H
