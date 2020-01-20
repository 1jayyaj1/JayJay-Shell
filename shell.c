#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "shellmemory.h"

char** parse(char userInput[]) {
    char ** parsedUserInput = malloc(100 * sizeof(char*));
    for (int i = 0 ; i < 100; ++i) {
        parsedUserInput[i] = malloc(100 * sizeof(char));
    }
    int i = 0;
    char* token = strtok(userInput, " ");
    while (token != NULL) {
        parsedUserInput[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    return parsedUserInput;
}

int main() {
    char userInput[50];
    do {
        printf("Welcome to the JayJay shell!\n");
        printf("Version 1.0 Created January 2020\n");
        printf("$ ");
        scanf("%s", userInput);
        interpret(parse(userInput));
	}
	while(strcmp(parse(userInput)[0],"quit")!=0);
	printf("Bye!\n");
}
