#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <tree/binary.h>

void test_binary_tree_basic_operations() {
    BinaryTree tree;
    binary_tree_create(&tree);

    assert(binary_tree_insert(&tree, 5) == BinaryTreeSuccess);
    assert(binary_tree_insert(&tree, 3) == BinaryTreeSuccess);
    assert(binary_tree_insert(&tree, 7) == BinaryTreeSuccess);
    assert(binary_tree_insert(&tree, 2) == BinaryTreeSuccess);
    assert(binary_tree_insert(&tree, 4) == BinaryTreeSuccess);
    assert(binary_tree_insert(&tree, 6) == BinaryTreeSuccess);
    assert(binary_tree_insert(&tree, 8) == BinaryTreeSuccess);

    assert(binary_tree_search(&tree, 5) == BinaryTreeSuccess);
    assert(binary_tree_search(&tree, 3) == BinaryTreeSuccess);
    assert(binary_tree_search(&tree, 7) == BinaryTreeSuccess);
    assert(binary_tree_search(&tree, 2) == BinaryTreeSuccess);
    assert(binary_tree_search(&tree, 4) == BinaryTreeSuccess);
    assert(binary_tree_search(&tree, 6) == BinaryTreeSuccess);
    assert(binary_tree_search(&tree, 8) == BinaryTreeSuccess);

    assert(binary_tree_search(&tree, 10) == BinaryTreeFailure);

    assert(binary_tree_delete(&tree, 3) == BinaryTreeSuccess);
    assert(binary_tree_delete(&tree, 6) == BinaryTreeSuccess);

    assert(binary_tree_search(&tree, 3) == BinaryTreeFailure);
    assert(binary_tree_search(&tree, 6) == BinaryTreeFailure);

    assert(binary_tree_destroy(&tree) == BinaryTreeSuccess);
}