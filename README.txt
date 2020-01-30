This assignment was done using Mac OS (Linux). There are no special instructions to run this shell. Simply need to run these commands in the following sequence:

1) gcc -c shell.c interpreter.c shellmemory.c
2) gcc -o mysh shell.o interpreter.o shellmemory.o
3) ./mysh