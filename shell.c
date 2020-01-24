#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "shellmemory.h"

List *l;

int main() {
    char userInput[50];
    l = List_create();
    printf("Welcome to the JayJay shell!\n");
    printf("Version 1.0 Created January 2020\n");
    do {
        int size;
        printf("$ ");
        fgets(userInput,50,stdin);
        size = strlen(userInput);
        userInput[size-1]='\0';
        interpret(parse(userInput),l);
	}
	while(strcmp(parse(userInput)[0],"quit")!=0);
	printf("Bye!\n");
}
