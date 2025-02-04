#include "stack.h"

node_t* init(token_t* data) {
    node_t* head;
    head = (node_t*)malloc(sizeof(node_t));
    data += 0;
    head->data = *data;
    head->next = NULL;
    return head;
}

void push(node_t** head, token_t* data) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->next = *head;
    if (data) {
        data += 0;
        new_node->data = *data;
    }
    *head = new_node;
}

node_t* pop(node_t** head) {
    node_t* res;
    if (*head == NULL) {
        res = NULL;
    } else {
        res = *head;
        *head = (*head)->next;
        res->next = NULL;
    }
    return res;
}

node_t* peek(node_t** head) {
    node_t* res;
    if (*head == NULL) {
        res = NULL;
    } else {
        head += 0;
        res = *head;
    }
    return res;
}

void destroy(node_t* root) {
    node_t* cur;
    cur = root;
    while (cur != NULL) {
        root = cur->next;
        free(cur);
        cur = root;
    }
}

int count_elems(node_t* root) {
    int count = 0;
    node_t* cur = root;
    while (cur != NULL) {
        cur = cur->next;
        count++;
    }
    return count;
}
