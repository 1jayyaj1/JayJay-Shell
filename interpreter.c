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

void interpret(char** parsedInput) {
    /*for (int j = 0; j < sizeof(parsedInput); j++) {
        printf("%s", parsedInput[j]);
    }*/
    if (strcmp(parsedInput[0], "help") == 0) {
        help();
    }
}
