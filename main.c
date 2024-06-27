
#include <stdio.h>

void test_hashmap_basic_operations();
void test_vector_basic_operations();

int main(void) {
    printf("HashMap: Run\n");
    test_hashmap_basic_operations();
    printf("HashMap: End\n");    

    printf("Vector: Run\n");
    test_vector_basic_operations();
    printf("Vector: End\n");    

    printf("All tests passed\n");

    return 0;
}