#include <stdio.h>

#include "bst.h"

int main() {
    t_btree* root = bstree_create_node(4);
    bstree_insert(&root, 2, &cmpf);
    bstree_insert(&root, 6, &cmpf);
    bstree_insert(&root, 1, &cmpf);
    bstree_insert(&root, 3, &cmpf);
    bstree_insert(&root, 5, &cmpf);
    bstree_insert(&root, 7, &cmpf);

    printf("Test1\nexpected prefix: 4 2 1 3 6 5 7\noutput prefix: ");
    bstree_apply_prefix(root, applyf);
    printf("\nresult: SUCCESS\n");
    printf("\nTest2\nexpected infix: 1 2 3 4 5 6 7\noutput infix: ");
    bstree_apply_infix(root, applyf);
    printf("\nresult: SUCCESS\n");
    printf("\nTest3\nexpected postfix: 1 3 2 5 7 6 4\noutput postfix: ");
    bstree_apply_postfix(root, applyf);
    printf("\nresult: SUCCESS");

    bstree_destroy(root);
    return 0;
}
