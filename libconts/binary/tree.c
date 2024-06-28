#include "tree.h"
#include <stdlib.h>

static BinaryTreeNode *create_node(int value) {
    BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
    if (node != NULL) {
        node->data = value;
        node->left = NULL;
        node->right = NULL;
    }
    return node;
}

BinaryTreeResult binary_tree_create(BinaryTree *tree) {
    tree->root = NULL;
    return BinaryTreeSuccess;
}

static BinaryTreeNode *insert_recursive(BinaryTreeNode *node, int value) {
    if (node == NULL) {
        return create_node(value);
    }

    if (value < node->data) {
        node->left = insert_recursive(node->left, value);
    } else if (value > node->data) {
        node->right = insert_recursive(node->right, value);
    }

    return node;
}

BinaryTreeResult binary_tree_insert(BinaryTree *tree, int value) {
    if (tree == NULL) return BinaryTreeFailure;
    tree->root = insert_recursive(tree->root, value);
    if (tree->root == NULL) {
        return BinaryTreeFailure;
    }
    return BinaryTreeSuccess;
}

static BinaryTreeNode *search_recursive(BinaryTreeNode *node, int value) {
    if (node == NULL || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return search_recursive(node->left, value);
    } else {
        return search_recursive(node->right, value);
    }
}

BinaryTreeResult binary_tree_search(BinaryTree *tree, int value) {
    if (tree == NULL) return BinaryTreeFailure;
    BinaryTreeNode *result = search_recursive(tree->root, value);
    if (result == NULL) {
        return BinaryTreeFailure;
    }
    return BinaryTreeSuccess;
}

static BinaryTreeNode *find_minimum(BinaryTreeNode *node) {
    BinaryTreeNode *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

static BinaryTreeNode *delete_recursive(BinaryTreeNode *root, int value) {
    if (root == NULL) return root;

    if (value < root->data) {
        root->left = delete_recursive(root->left, value);
    } else if (value > root->data) {
        root->right = delete_recursive(root->right, value);
    } else {
        if (root->left == NULL) {
            BinaryTreeNode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BinaryTreeNode *temp = root->left;
            free(root);
            return temp;
        }

        BinaryTreeNode *temp = find_minimum(root->right);
        root->data = temp->data;
        root->right = delete_recursive(root->right, temp->data);
    }
    return root;
}

BinaryTreeResult binary_tree_delete(BinaryTree *tree, int value) {
    if (tree == NULL) return BinaryTreeFailure;
    tree->root = delete_recursive(tree->root, value);
    if (tree->root == NULL) {
        return BinaryTreeFailure;
    }
    return BinaryTreeSuccess;
}

static void destroy_recursive(BinaryTreeNode *node) {
    if (node != NULL) {
        destroy_recursive(node->left);
        destroy_recursive(node->right);
        free(node);
    }
}

BinaryTreeResult binary_tree_destroy(BinaryTree *tree) {
    if (tree == NULL) return BinaryTreeFailure;
    destroy_recursive(tree->root);
    tree->root = NULL;
    return BinaryTreeSuccess;
}
