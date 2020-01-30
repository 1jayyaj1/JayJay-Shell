#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shellmemory.h"

Node *Node_create() {
    Node *node = malloc(sizeof(Node));
    node->var = "";
    node->value = "";
    node->next = NULL;
    return node;
}

List *List_create() {
    List *list = malloc(sizeof(List));
    Node *node = Node_create();
    list->first = node;
    return list;
}

void List_append(List *list, char *var, char *value) {
    Node *node = list->first;
    while (node->next != NULL) {
        node = node->next;
    }
    node->var = var;
    node->value = value;
    node->next = Node_create();
}

char* List_find(List *list, char *var) {
    Node *node = list->first;
    while (node->next != NULL) {
        if (strlen(var) == strlen(node->var)) {
            int cmp = strcmp(var, node->var);
            if (cmp == 0) {
                return node->value;
            }
        }
        node = node->next;
    }
    return "Variable does not exist";
}

char* List_update(List *list, char *var, char *value) {
    Node *current = list->first;
    Node *previous = NULL;
    if(list->first == NULL) {
        return NULL;
    }
    while(strcmp(var, current->var) != 0) {
        if(current->next == NULL) {
            break;
        } else {
            previous = current;
            current = current->next;
        }
    }
    if(current == list->first) {
        list->first = list->first->next;
    } else {
        previous->next = current->next;
    }
    List_append(list, strdup(var), strdup(value));
    return "Success";
}

// This function was used for debugging purposes. Feel free to ignore it when grading!
void List_print(List *list) {
    printf("[");
    Node *node = list->first;
    while (node->next != NULL) {
        printf("(Var: ");
        printf("%s", node->var);
        printf(", Value: ");
        printf("%s", node->value);
         printf(")");
        node = node->next;
        if (node->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}
