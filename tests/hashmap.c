#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <hashmap/hashmap.h>

void test_hashmap_basic_operations() {
    HashMap map;
    HashMapResult result = hashmap_create(10, &map);
    assert(result == HashMapSuccess);

    char *key1 = "key1";
    int value1 = 10;
    result = hashmap_put(&map, key1, &value1);
    assert(result == HashMapSuccess);

    char *key2 = "key2";
    int value2 = 20;
    result = hashmap_put(&map, key2, &value2);
    assert(result == HashMapSuccess);

    int *retrieved_value;
    result = hashmap_get(&map, key1, (void **)&retrieved_value);
    assert(result == HashMapSuccess);
    assert(*retrieved_value == value1);

    result = hashmap_remove(&map, key2);
    assert(result == HashMapSuccess);

    result = hashmap_free(&map);
    assert(result == HashMapSuccess);
}