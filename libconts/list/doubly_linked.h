#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include "../result.h"
#include <stddef.h>

#define DoublyLinkedListFailure ContsResultFailure
#define DoublyLinkedListSuccess ContsResultSuccess

typedef struct DoublyLinkedListNode {
    void *data;
    struct DoublyLinkedListNode* next;
    struct DoublyLinkedListNode* prev;
} DoublyLinkedListNode;

typedef struct DoublyLinkedList {
    DoublyLinkedListNode* head;
    size_t element_size;
} DoublyLinkedList;

typedef ContsResultType DoublyLinkedResult;

DoublyLinkedResult doubly_linked_list_create(size_t element_size, DoublyLinkedList* listOutput);
DoublyLinkedResult doubly_linked_list_destroy(DoublyLinkedList *list);

DoublyLinkedResult doubly_linked_list_append(DoublyLinkedList *list, void *element);
DoublyLinkedResult doubly_linked_list_prepend(DoublyLinkedList *list, void *element);
DoublyLinkedResult doubly_linked_list_delete(DoublyLinkedList *list, void *element);
DoublyLinkedResult doubly_linked_list_get(DoublyLinkedList *list, size_t index, void *element);
DoublyLinkedResult doubly_linked_list_display(DoublyLinkedList *list);
DoublyLinkedResult doubly_linked_list_clear(DoublyLinkedList *list);

#endif // DOUBLY_LINKED_LIST_H