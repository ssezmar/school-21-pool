#include "bst.h"

#include <stdio.h>

t_btree *bstree_create_node(int item) {
    t_btree *first = (t_btree *)malloc(sizeof(t_btree));
    if (first != NULL) {
        first->item = item;
        first->left = NULL;
        first->right = NULL;
    }

    return first;
}

void bstree_insert(t_btree **root, int item, int (*cmpf)(int, int)) {
    if (*root == NULL) {
        *root = bstree_create_node(item);
    } else {
        if (cmpf((*root)->item, item)) {
            bstree_insert(&(*root)->left, item, cmpf);
        } else {
            bstree_insert(&(*root)->right, item, cmpf);
        }
    }
}

int cmpf(int a, int b) {
    if (a > b)
        return 1;
    else
        return 0;
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root) {
        bstree_apply_infix(root->left, applyf);
        applyf(root->item);
        bstree_apply_infix(root->right, applyf);
    }
}

void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root) {
        applyf(root->item);
        bstree_apply_prefix(root->left, applyf);
        bstree_apply_prefix(root->right, applyf);
    }
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root) {
        bstree_apply_postfix(root->left, applyf);
        bstree_apply_postfix(root->right, applyf);
        applyf(root->item);
    }
}

void applyf(int value) { printf("%d ", value); }

void bstree_destroy(t_btree *root) {
    if (root) {
        bstree_destroy(root->left);
        bstree_destroy(root->right);
        free(root);
    }
}