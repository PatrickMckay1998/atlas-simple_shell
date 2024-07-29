#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARGS 64

/* Function declarations */


void parse_command(char *command, char **args);

/* Function to search for a command in common directories*/
char *search_command(const char *command);