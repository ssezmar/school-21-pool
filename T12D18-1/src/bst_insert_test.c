#include <stdio.h>

#include "bst.h"

int main() {
    printf("Test 1:\ninput: 10\noutput: ");
    t_btree* bst = bstree_create_node(10);
    printf("%d\n", bst->item);
    if (bst->item == 10)
        printf("result: SUCCESS\n\n");
    else
        printf("result: FAIL\n\n");

    printf("Test 2:\ninput: 123123\noutput: ");
    bstree_insert(&bst, 123123, &cmpf);
    printf("%d\n", bst->right->item);
    if (bst->right->item == 123123)
        printf("result: SUCCESS\n\n");
    else
        printf("result: FAIL\n\n");

    printf("Test 3:\ninput: 1\noutput: ");
    bstree_insert(&bst, 1, &cmpf);
    printf("%d\n", bst->left->item);
    if (bst->left->item == 1)
        printf("result: SUCCESS");
    else
        printf("result: FAIL");

    free(bst->left);
    free(bst->right);
    free(bst);
    return 0;
}
