#include <stdio.h>
#include <stdlib.h>
#include <strings.h> 
#include "shellmemory.h"

void interpret(char** parsedInput, List *l);

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
        char *var = List_find(l, strdup(parsedInput[1]));
        if (strcmp(var, "Variable does not exist") == 0) {
            List_append(l, strdup(parsedInput[1]), strdup(parsedInput[2]));
        } else {
            List_update(l, strdup(parsedInput[1]), strdup(parsedInput[2]));
        }
    }   
}

void printVar(char** parsedInput, List *l) {
    if (strcmp(parsedInput[0], "") == 0 || strcmp(parsedInput[1], "") == 0 || strcmp(parsedInput[2], "") != 0) {
        printf("Please use this format to set a variable: set VAR STRING\n");
    } else {
        printf("%s\n", List_find(l, strdup(parsedInput[1])));
    }
}

void runFile(char** parsedInput, List *l) {
    if (strcmp(parsedInput[0], "") == 0 || strcmp(parsedInput[1], "") == 0 || strcmp(parsedInput[2], "") != 0) {
        printf("Please use this format to run a text file: run SCRIPT.txt\n");
    } else {
        FILE* file = fopen(parsedInput[1], "r");
        if (file != NULL) {
            char line[256];
            while (fgets(line, sizeof(line), file)) {
                //printf("%s", line); 
                interpret(parse(strtok(line, "\n")), l);
            }
            fclose(file);
        } else {
            printf("Script not found\n");
        }
    }
}

void interpret(char** parsedInput, List *l) {
    if (strcmp(parsedInput[0], "help") == 0 && strcmp(parsedInput[1], "") == 0) {
        help();
    } else if (strcmp(parsedInput[0], "set") == 0) {
        setVar(parsedInput,l);
    } else if (strcmp(parsedInput[0], "print") == 0) {
        printVar(parsedInput,l);
    } else if (strcmp(parsedInput[0], "run") == 0) {
        runFile(parsedInput, l);
    } else {
        if (strcmp(parsedInput[0], "quit") != 0 && strcmp(parsedInput[0], "") != 0) {
            printf("Unknown command\n");
        }
    }
}
