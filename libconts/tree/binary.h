#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "../result.h"
#include <stdbool.h>

#define BinaryTreeFailure ContsResultFailure
#define BinaryTreeSuccess ContsResultSuccess

typedef struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} BinaryTreeNode;

typedef struct BinaryTree {
    BinaryTreeNode *root;
} BinaryTree;

typedef ContsResultType BinaryTreeResult;

BinaryTreeResult binary_tree_create(BinaryTree *tree);
BinaryTreeResult binary_tree_insert(BinaryTree *tree, int value);
BinaryTreeResult binary_tree_search(BinaryTree *tree, int value);
BinaryTreeResult binary_tree_delete(BinaryTree *tree, int value);
BinaryTreeResult binary_tree_destroy(BinaryTree *tree);

#endif // BINARY_TREE_H
