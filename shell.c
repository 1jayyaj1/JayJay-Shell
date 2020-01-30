#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "shellmemory.h"

List *l;

int main() {
    char userInput[1000];
    char prompt[100] = {'$', '\0'};
    l = List_create();
    printf("Welcome to the JayJay shell!\n");
    printf("Version 1.0 Created January 2020\n");
    int leaveStatus = 0;
    do {
        int size;
        printf("%s ", prompt);
        fgets(userInput,999,stdin);
        size = strlen(userInput);
        userInput[size-1]='\0';
        leaveStatus = interpret(parse(userInput),l);
	}
	while(leaveStatus == 0);
	printf("Bye!\n");
}