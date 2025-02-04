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

    free(bst);

    printf("Test 2:\ninput: 123123\noutput: ");
    bst = bstree_create_node(123123);
    printf("%d\n", bst->item);
    if (bst->item == 123123)
        printf("result: SUCCESS");
    else
        printf("result: FAIL");

    free(bst);

    return 0;
}
