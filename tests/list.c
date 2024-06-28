#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <list/linked.h>
#include <list/doubly_linked.h>

void test_linked_list_basic_operations() {
    LinkedList linked_list;
    assert(linked_list_create(sizeof(int), &linked_list) == LinkedListSuccess);

    int values[] = {1, 2, 3};
    assert(linked_list_append(&linked_list, &values[0]) == LinkedListSuccess);
    assert(linked_list_append(&linked_list, &values[1]) == LinkedListSuccess);
    assert(linked_list_prepend(&linked_list, &values[2]) == LinkedListSuccess);

    int result;
    assert(linked_list_get(&linked_list, 0, &result) == LinkedListSuccess);
    assert(result == 3);
    assert(linked_list_get(&linked_list, 1, &result) == LinkedListSuccess);
    assert(result == 1);
    assert(linked_list_get(&linked_list, 2, &result) == LinkedListSuccess);
    assert(result == 2);

    assert(linked_list_clear(&linked_list) == LinkedListSuccess);
    assert(linked_list_destroy(&linked_list) == LinkedListSuccess);
}

void test_doubly_linked_list_basic_operations() {
    DoublyLinkedList doubly_linked_list;
    assert(doubly_linked_list_create(sizeof(int), &doubly_linked_list) == DoublyLinkedListSuccess);

    int values[] = {1, 2, 3};
    assert(doubly_linked_list_append(&doubly_linked_list, &values[0]) == DoublyLinkedListSuccess);
    assert(doubly_linked_list_append(&doubly_linked_list, &values[1]) == DoublyLinkedListSuccess);
    assert(doubly_linked_list_prepend(&doubly_linked_list, &values[2]) == DoublyLinkedListSuccess);

    int result;
    assert(doubly_linked_list_get(&doubly_linked_list, 0, &result) == DoublyLinkedListSuccess);
    assert(result == 3);
    assert(doubly_linked_list_get(&doubly_linked_list, 1, &result) == DoublyLinkedListSuccess);
    assert(result == 1);
    assert(doubly_linked_list_get(&doubly_linked_list, 2, &result) == DoublyLinkedListSuccess);
    assert(result == 2);

    assert(doubly_linked_list_delete(&doubly_linked_list, &values[1]) == DoublyLinkedListSuccess);

    assert(doubly_linked_list_clear(&doubly_linked_list) == DoublyLinkedListSuccess);
    assert(doubly_linked_list_destroy(&doubly_linked_list) == DoublyLinkedListSuccess);
}