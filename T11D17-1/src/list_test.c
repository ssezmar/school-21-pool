#include "list.h"

#include <stdio.h>

#include "door_struct.h"

int main() {
    int result = 1;
    Node *temp_node;
    Node *list;
    struct Door doors[3];
    for (int ind = 0; ind < 3; ind++) {
        doors[ind].id = ind;
        doors[ind].status = 0;
    }

    list = init(&doors[0]);
    temp_node = list;
    for (int ind = 1; ind < 3; ind++) temp_node = add_door(temp_node, &doors[ind]);

    if (!((find_door(0, list)->door->id == 0) && (find_door(1, list)->door->id == 1) &&
          (find_door(2, list)->door->id == 2)))
        result = 0;

    list = remove_door(find_door(1, list), list);
    if (find_door(1, list)) result = 0;

    if (result)
        printf("SUCCESS");
    else
        printf("FAIL");

    destroy(list);

    return 0;
}
