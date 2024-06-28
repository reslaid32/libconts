#include "linked.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

LinkedListResult linked_list_create(size_t element_size, LinkedList* listOutput) {
    if (listOutput == NULL) {
        return LinkedListFailure;
    }
    listOutput->head = NULL;
    listOutput->element_size = element_size;
    return LinkedListSuccess;
}

LinkedListResult linked_list_destroy(LinkedList *list) {
    if (list == NULL) {
        return LinkedListFailure;
    }
    LinkedListNode* current = list->head;
    LinkedListNode* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current->data);
        free(current);
        current = nextNode;
    }
    list->head = NULL;
    return LinkedListSuccess;
}

LinkedListResult linked_list_append(LinkedList *list, void *element) {
    if (list == NULL || element == NULL) {
        return LinkedListFailure;
    }
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (newNode == NULL) {
        return LinkedListFailure;
    }
    newNode->data = malloc(list->element_size);
    if (newNode->data == NULL) {
        free(newNode);
        return LinkedListFailure;
    }
    memcpy(newNode->data, element, list->element_size);
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        LinkedListNode* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    return LinkedListSuccess;
}

LinkedListResult linked_list_prepend(LinkedList *list, void *element) {
    if (list == NULL || element == NULL) {
        return LinkedListFailure;
    }
    LinkedListNode* newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (newNode == NULL) {
        return LinkedListFailure;
    }
    newNode->data = malloc(list->element_size);
    if (newNode->data == NULL) {
        free(newNode);
        return LinkedListFailure;
    }
    memcpy(newNode->data, element, list->element_size);
    newNode->next = list->head;
    list->head = newNode;
    return LinkedListSuccess;
}

LinkedListResult linked_list_delete(LinkedList *list, void *element) {
    if (list == NULL || element == NULL) {
        return LinkedListFailure;
    }
    LinkedListNode* current = list->head;
    LinkedListNode* previous = NULL;
    
    while (current != NULL && memcmp(current->data, element, list->element_size) != 0) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        return LinkedListFailure;
    }
    
    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }
    
    free(current->data);
    free(current);
    return LinkedListSuccess;
}

LinkedListResult linked_list_get(LinkedList *list, size_t index, void *element) {
    if (list == NULL || element == NULL) {
        return LinkedListFailure;
    }
    LinkedListNode* current = list->head;
    size_t i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }
    if (current == NULL) {
        return LinkedListFailure;
    }
    memcpy(element, current->data, list->element_size);
    return LinkedListSuccess;
}

LinkedListResult linked_list_display(LinkedList *list) {
    if (list == NULL) {
        return LinkedListFailure;
    }
    LinkedListNode* current = list->head;
    while (current != NULL) {
        printf("%p -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    return LinkedListSuccess;
}

LinkedListResult linked_list_clear(LinkedList *list) {
    if (list == NULL) {
        return LinkedListFailure;
    }
    LinkedListNode* current = list->head;
    LinkedListNode* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current->data);
        free(current);
        current = nextNode;
    }
    list->head = NULL;
    return LinkedListSuccess;
}
