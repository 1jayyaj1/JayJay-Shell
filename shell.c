#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "shellmemory.h"

char** parse(char userin[]) {
    char ** parsedUserInput = malloc(100 * sizeof(char*));
    for (int i = 0 ; i < 100; ++i) {
        parsedUserInput[i] = malloc(100 * sizeof(char));
    }
    int i = 0;
    char* token = strtok(userin, " ");
    while (token != NULL) {
        parsedUserInput[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    return parsedUserInput;
}

int main(int argc, char * argv[]) {
    char userinput[50];
    printf("Welcome to the JayJay shell!\n");
    printf("Version 1.0 Created January 2020\n");
    printf("$ ");
    scanf("%[^\n]s", userinput);
    char** okok = parse(userinput);
    interpret(okok);
}
