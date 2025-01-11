#include <stdio.h>
#include <assert.h>
#include <map/map.h>

void test_map_basic_operations() {
    Map map;
    MapResult result = map_create(sizeof(int), sizeof(char), &map);
    assert(result == MapSuccess);

    int key1 = 1;
    char value1 = 'A';
    result = map_insert(&map, &key1, &value1);
    assert(result == MapSuccess);

    int key2 = 2;
    char value2 = 'B';
    result = map_insert(&map, &key2, &value2);
    assert(result == MapSuccess);

    char retrieved_value;
    result = map_get(&map, &key1, &retrieved_value);
    assert(result == MapSuccess);
    assert(retrieved_value == value1);

    char updated_value = 'C';
    result = map_insert(&map, &key1, &updated_value);
    assert(result == MapSuccess);

    result = map_get(&map, &key1, &retrieved_value);
    assert(result == MapSuccess);
    assert(retrieved_value == updated_value);

    result = map_clear(&map);
    assert(result == MapSuccess);

    result = map_destroy(&map);
    assert(result == MapSuccess);
}