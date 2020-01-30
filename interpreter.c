#include <stdio.h>
#include <stdlib.h>
#include <strings.h> 
#include "shellmemory.h"

int interpret(char** parsedInput, List *l);

char** parse(char userInput[]) {
    char ** parsedUserInput = malloc(100 * sizeof(char*));
    for (int i = 0 ; i < 100; ++i) {
        parsedUserInput[i] = malloc(100 * sizeof(char));
    }
    char tmp[200];
    int a,b;
    int w=0;
    for(a=0; userInput[a]==' ' && a<100; a++);
    while(userInput[a] != '\0' && a<100) {
        for(b=0; userInput[a]!='\0' && userInput[a]!=' ' && a<1000; a++, b++)
            tmp[b] = userInput[a];
        tmp[b] = '\0';
        parsedUserInput[w] = strdup(tmp);
        a++; w++;
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
    if (strcmp(parsedInput[1], "") == 0 || strcmp(parsedInput[2], "") != 0) {
        printf("Please use this format to print a variable: print VAR\n");
    } else {
        printf("%s\n", List_find(l, strdup(parsedInput[1])));
    }
}

char *choppy( char *s ) {
    char *n = malloc(strlen(s ? s : "\n"));
    if(s) {
        strcpy(n, s);
    }
    n[strlen(n)-1]='\0';
    return n;
}

void runFile(char** parsedInput, List *l) {
    if (strcmp(parsedInput[1], "") == 0 || strcmp(parsedInput[2], "") != 0) {
        printf("Please use this format to run a text file: run SCRIPT.txt\n");
    } else {
        int errCode = 0;
        char line[1000];
        FILE *p = fopen(parsedInput[1],"rt");
        if (p==NULL){
            printf("Script not found");
        }
        fgets(line,999,p);
        while(!feof(p)) {
            interpret(parse(choppy(line)), l);
            if (errCode != 0) {
                fclose(p);
            }
            fgets(line,999,p);
            printf("%s", line);
        }
        fclose(p);
    }
}

int interpret(char** parsedInput, List *l) {
    if (strcmp(parsedInput[0], "help") == 0 && strcmp(parsedInput[1], "") == 0) {
        help();
    } else if (strcmp(parsedInput[0], "set") == 0) {
        setVar(parsedInput,l);
    } else if (strcmp(parsedInput[0], "print") == 0) {
        printVar(parsedInput,l);
    } else if (strcmp(parsedInput[0], "run") == 0) {
        runFile(parsedInput, l);
    } else if (strcmp(parsedInput[0], "quit") == 0) {
        return 1;
    } else {
        if (strcmp(parsedInput[0], "") != 0) {
            printf("Unknown command\n");
        }
    }
    return 0;
}
