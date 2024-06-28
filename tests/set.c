#include <stdio.h>
#include <assert.h>
#include <set/set.h>

void test_set_basic_operations() {
    Set set;
    assert(set_create(sizeof(int), &set) == SetSuccess);

    int values[] = {1, 2, 3};
    assert(set_insert(&set, &values[0]) == SetSuccess);
    assert(set_insert(&set, &values[1]) == SetSuccess);
    assert(set_insert(&set, &values[2]) == SetSuccess);

    assert(set_size(&set) == 3);

    int element_to_find = 2;
    assert(set_contains(&set, &element_to_find) == true);

    assert(set_remove(&set, &element_to_find) == SetSuccess);
    assert(set_contains(&set, &element_to_find) == false);

    assert(set_size(&set) == 2);

    assert(set_destroy(&set) == SetSuccess);
}