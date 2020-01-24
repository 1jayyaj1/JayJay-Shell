#include <stdio.h>
#include <stdlib.h>
#include <strings.h> 
#include "shellmemory.h"

void help() {
    printf("COMMANDS:\n");
    printf("help: Displays all the commands\n");
    printf("quit: Exits/terminates the shell with “Bye!”\n");
    printf("set VAR STRING: Assigns a value to shell memory\n");
    printf("print VAR: Displays the STRING assigned to VAR\n");
    printf("run SCRIPT.txt: Executes the file SCRIPT.TXT\n");
}

void setVar(char** parsedInput, List *l) {
    if (strcmp(parsedInput[1], "") == 0 || strcmp(parsedInput[2], "") == 0 || strcmp(parsedInput[3], "") != 0) {
        printf("Please use this format to set a variable: set VAR STRING\n");
    } else {
        List_append(l, strdup(parsedInput[1]), strdup(parsedInput[2]));
    }   
}

void printVar(char** parsedInput, List *l) {
    if (strcmp(parsedInput[0], "") == 0 || strcmp(parsedInput[1], "") == 0 || strcmp(parsedInput[2], "") != 0) {
        printf("Please use this format to set a variable: set VAR STRING\n");
    } else {
        printf("%s\n", List_find(l, strdup(parsedInput[1])));
    }
}

void interpret(char** parsedInput, List *l) {
    if (strcmp(parsedInput[0], "help") == 0 && strcmp(parsedInput[1], "") == 0) {
        help();
    } else if (strcmp(parsedInput[0], "set") == 0) {
        setVar(parsedInput,l);
    } else if (strcmp(parsedInput[0], "print") == 0) {
        printVar(parsedInput,l);
    } else {
        if (strcmp(parsedInput[0], "quit") != 0 && strcmp(parsedInput[0], "") != 0) {
            printf("Unknown command\n");
        }
    }
}
