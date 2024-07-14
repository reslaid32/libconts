#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <stdbool.h>
#include "result.h"

#define LinkedStackSuccess ContsResultSuccess
#define LinkedStackFailure ContsResultFailure

typedef struct _s_linked_stack_item {
    struct _s_linked_stack_item*    down;
    void*                           data;
} linked_stack_item_t;

typedef struct {
    linked_stack_item_t* top;
} LinkedStack;

typedef ContsResultType LinkedStackResult;

LinkedStackResult linked_stack_init(LinkedStack* stack);
LinkedStackResult linked_stack_push(LinkedStack* stack, void* data);
LinkedStackResult linked_stack_pop(LinkedStack* stack, void* output);
LinkedStackResult linked_stack_pick(LinkedStack const* stack, void* output);
LinkedStackResult linked_stack_flush(LinkedStack* stack);
LinkedStackResult linked_stack_destroy(LinkedStack* stack);
bool linked_stack_isempty(LinkedStack const* stack);

#endif // LINKED_STACK_H