#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../result.h"
#include <stddef.h>

#define LinkedListFailure ContsResultFailure
#define LinkedListSuccess ContsResultSuccess

typedef struct LinkedListNode {
    void *data;
    struct LinkedListNode* next;
} LinkedListNode;

typedef struct LinkedList {
    LinkedListNode* head;
    size_t element_size;
} LinkedList;

typedef ContsResultType LinkedListResult;

LinkedListResult linked_list_create(size_t element_size, LinkedList* listOutput);
LinkedListResult linked_list_destroy(LinkedList *list);

LinkedListResult linked_list_append(LinkedList *list, void *element);
LinkedListResult linked_list_prepend(LinkedList *list, void *element);
LinkedListResult linked_list_delete(LinkedList *list, void *element);
LinkedListResult linked_list_get(LinkedList *list, size_t index, void *element);
LinkedListResult linked_list_display(LinkedList *list);
LinkedListResult linked_list_clear(LinkedList *list);

#endif // LINKED_LIST_H
