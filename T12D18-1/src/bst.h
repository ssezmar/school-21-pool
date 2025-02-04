#ifndef BST_H
#define BST_H

#include <stdlib.h>

typedef struct s_btree {
    struct s_btree *left;
    struct s_btree *right;
    int item;
} t_btree;

t_btree *bstree_create_node(int item);
void bstree_insert(t_btree **root, int item, int (*cmpf)(int, int));
int cmpf(int a, int b);

void bstree_apply_infix(t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(t_btree *root, void (*applyf)(int));
void applyf(int value);
void bstree_destroy(t_btree *root);

#endif