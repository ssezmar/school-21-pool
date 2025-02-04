#include "list.h"

#include <stdlib.h>

#include "door_struct.h"

Node *init(door_t *door) {
    Node *root = (Node *)(malloc(sizeof(Node)));
    if (root) {
        root->door = door;
        root->next = NULL;
    }
    return root;
}

Node *add_door(Node *elem, door_t *door) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node) {
        new_node->door = door;
        new_node->next = NULL;
        if (elem) {
            new_node->next = elem->next;
            elem->next = new_node;
        }
    }

    return new_node;
}

Node *find_door(int door_id, Node *root) {
    Node *item = root;
    while ((item) && (item->door->id != door_id)) item = item->next;
    return item;
}

Node *remove_door(Node *elem, Node *root) {
    Node *ans = NULL;
    if (!elem) ans = root;

    if (!ans) {
        if (elem == root) {
            ans = elem->next;
            free(elem);
        } else {
            Node *item = root;
            while ((item) && (item->next != elem)) item = item->next;

            if (item) {
                item->next = item->next->next;
                free(elem);
            }

            ans = root;
        }
    }

    return ans;
}

void destroy(Node *root) {
    if (!root) return;
    destroy(root->next);
    free(root);
}
