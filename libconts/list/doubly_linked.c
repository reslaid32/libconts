#include "doubly_linked.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

DoublyLinkedResult doubly_linked_list_create(size_t element_size, DoublyLinkedList* listOutput) {
    if (listOutput == NULL) {
        return DoublyLinkedListFailure;
    }
    listOutput->head = NULL;
    listOutput->element_size = element_size;
    return DoublyLinkedListSuccess;
}

DoublyLinkedResult doubly_linked_list_destroy(DoublyLinkedList *list) {
    if (list == NULL) {
        return DoublyLinkedListFailure;
    }
    DoublyLinkedListNode* current = list->head;
    DoublyLinkedListNode* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current->data);
        free(current);
        current = nextNode;
    }
    list->head = NULL;
    return DoublyLinkedListSuccess;
}

DoublyLinkedResult doubly_linked_list_append(DoublyLinkedList *list, void *element) {
    if (list == NULL || element == NULL) {
        return DoublyLinkedListFailure;
    }
    DoublyLinkedListNode* newNode = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    if (newNode == NULL) {
        return DoublyLinkedListFailure;
    }
    newNode->data = malloc(list->element_size);
    if (newNode->data == NULL) {
        free(newNode);
        return DoublyLinkedListFailure;
    }
    memcpy(newNode->data, element, list->element_size);
    newNode->next = NULL;
    newNode->prev = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        DoublyLinkedListNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    return DoublyLinkedListSuccess;
}

DoublyLinkedResult doubly_linked_list_prepend(DoublyLinkedList *list, void *element) {
    if (list == NULL || element == NULL) {
        return DoublyLinkedListFailure;
    }
    DoublyLinkedListNode* newNode = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));
    if (newNode == NULL) {
        return DoublyLinkedListFailure;
    }
    newNode->data = malloc(list->element_size);
    if (newNode->data == NULL) {
        free(newNode);
        return DoublyLinkedListFailure;
    }
    memcpy(newNode->data, element, list->element_size);
    newNode->next = list->head;
    newNode->prev = NULL;
    if (list->head != NULL) {
        list->head->prev = newNode;
    }
    list->head = newNode;
    return DoublyLinkedListSuccess;
}

DoublyLinkedResult doubly_linked_list_delete(DoublyLinkedList *list, void *element) {
    if (list == NULL || element == NULL) {
        return DoublyLinkedListFailure;
    }
    DoublyLinkedListNode* current = list->head;
    while (current != NULL && memcmp(current->data, element, list->element_size) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        return DoublyLinkedListFailure;
    }
    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        list->head = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current->data);
    free(current);
    return DoublyLinkedListSuccess;
}

DoublyLinkedResult doubly_linked_list_get(DoublyLinkedList *list, size_t index, void *element) {
    if (list == NULL || element == NULL) {
        return DoublyLinkedListFailure;
    }
    DoublyLinkedListNode* current = list->head;
    size_t i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        return DoublyLinkedListFailure;
    }
    memcpy(element, current->data, list->element_size);
    return DoublyLinkedListSuccess;
}

DoublyLinkedResult doubly_linked_list_display(DoublyLinkedList *list) {
    if (list == NULL) {
        return DoublyLinkedListFailure;
    }
    DoublyLinkedListNode* current = list->head;
    while (current != NULL) {
        printf("%p -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    return DoublyLinkedListSuccess;
}

DoublyLinkedResult doubly_linked_list_clear(DoublyLinkedList *list) {
    if (list == NULL) {
        return DoublyLinkedListFailure;
    }
    DoublyLinkedListNode* current = list->head;
    DoublyLinkedListNode* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current->data);
        free(current);
        current = nextNode;
    }
    list->head = NULL;
    return DoublyLinkedListSuccess;
}
