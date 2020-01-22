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
    printf("test");
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
    List_print(list);
}

void List_find(List *list, char *var) {
    Node *node = list->first;
    while (node->next != NULL) {
   
        if (strlen(var) == strlen(node->var)) {
            int cmp = strcmp(var, node->var);
            if (cmp == 0) {
                printf("%s", node->value);
            }
        }
        node = node->next;
    }
    printf("%s","Not found\n");
}

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