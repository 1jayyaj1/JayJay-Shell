#include <stdio.h>
#include <stdlib.h>
#include <strings.h> 

void help() {
    printf("COMMANDS:\n");
    printf("help: Displays all the commands\n");
    printf("quit: Exits/terminates the shell with “Bye!”\n");
    printf("set VAR STRING: Assigns a value to shell memory\n");
    printf("print VAR: Displays the STRING assigned to VAR\n");
    printf("run SCRIPT.txt: Executes the file SCRIPT.TXT\n");
}

void setVar(char** parsedInput) {
    if (strcmp(parsedInput[1], "") == 0 || strcmp(parsedInput[2], "") == 0 || strcmp(parsedInput[3], "") != 0) {
        printf("Please use this format to set a variable: set VAR STRING\n");
    } else {
        printf("Success\n");
    }
}

void interpret(char** parsedInput) {
    if (strcmp(parsedInput[0], "help") == 0) {
        help();
    } else if (strcmp(parsedInput[0], "set") == 0) {
        setVar(parsedInput);
    } else {
        if (strcmp(parsedInput[0], "quit") != 0 && strcmp(parsedInput[0], "") != 0) {
            printf("Unknown command\n");
        }
    }
}
