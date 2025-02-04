#ifndef LIST_H
#define LIST_H

#include "door_struct.h"

typedef struct Node {
    door_t *door;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} LinkedList;

Node *init(door_t *door);
Node *add_door(Node *elem, door_t *door);
Node *find_door(int door_id, Node *root);
Node *remove_door(Node *elem, Node *root);
void destroy(Node *root);

#endif