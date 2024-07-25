#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

/* Function declarations */


void parse_command(char *command, char **args);