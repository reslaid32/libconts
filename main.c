
#include <stdio.h>

void test_hashmap_basic_operations(); // tests/hashmap.c
void test_vector_basic_operations(); // tests/vector.c
void test_linked_list_basic_operations(); // tests/list.c
void test_doubly_linked_list_basic_operations(); // tests/list.c
void test_stack_basic_operations(); // tests/stack.c
void test_linked_stack_basic_operations(); // tests/stack.c
void test_queue_basic_operations(); // tests/queue.c
void test_deque_basic_operations(); // tests/deque.c
void test_set_basic_operations(); // tests/set.c
void test_binary_tree_basic_operations(); // tests/tree.c

int main(void) {
    test_hashmap_basic_operations();
    printf("HashMap: Passed\n");    

    test_vector_basic_operations();
    printf("Vector: Passed\n");    

    test_linked_list_basic_operations();
    test_doubly_linked_list_basic_operations();
    printf("List: Passed\n");

    test_stack_basic_operations();
    printf("Stack: Passed\n");

    test_linked_stack_basic_operations();
    printf("LinkedStack: Passed\n");

    test_queue_basic_operations();
    printf("Queue: Passed\n");

    test_deque_basic_operations();
    printf("Deque: Passed\n");

    test_set_basic_operations();
    printf("Set: Passed\n");

    test_binary_tree_basic_operations();
    printf("BinaryTree: Passed\n");

    printf("$ All tests passed\n");

    return 0;
}