#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *model1[1000];

char *model2[1000][2];

struct MODEL3 {
        char *var;
        char *value;
        struct MODEL3 *next;
} head;

int match(char *model, char *var) {
    int i, len=strlen(var), matchCount=0;
    for(i=0;i<len;i++) {
        if (*(model+i) == *(var+i)) {
            matchCount++;
        }
    }
    if (matchCount == len) {
        return 1;
    }
    else {
        return 0;
    }
}

char *extract(char *model) {
    char token='=';
    char value[1000];
    int i,j, len=strlen(model);
    for(i=0;i<len && *(model+i)!=token;i++);
    for(i=i+1,j=0;i<len;i++,j++) value[j]=*(model+i);
    value[j]='\0';
    return strdup(value);
}

void m1Set(char *string) {
    int i=0;
    for(i=0;i<1000;i++) {
        if (model1[i]==NULL) {
            model1[i] = strdup(string);
            break;
        }
    }
}

char *m1Get(char *var) {
    int i=0;
    for(i=0;i<1000;i++) {
        if (match(model1[i],var)) {
            return extract(model1[i]);
        }
    }
    return "Not found";
}
