#ifndef SHELLMEMORY_H
#define SHELLMEMORY_H
typedef struct NodeTag {
    char *var;
    char *value;
    struct NodeTag *next;
} Node;

Node *Node_create();

typedef struct ListTag {
    struct NodeTag *first;
} List;

List *List_create();

void List_append(List *list, char *var, char *value);

char *List_find(List *list, char *var);

char *List_update(List *list, char *var, char *value);

void List_print(List *list);
#endif
