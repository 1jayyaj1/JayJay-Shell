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

void List_append(List *list, char *str, char *str2);

char *List_find(List *list, char *str);

