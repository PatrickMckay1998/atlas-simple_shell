/*
Char str[] = our input 
char* toke = strtok(str , "-")
while(toke != null)
printf("%s \n ; tike);
toke = strtok(null ,"-")*/
#include <test-main.h>

int main() {
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_ARGS];    
    
    while (1) {
        /* Print prompt and read input*/
        printf("Shell >> ");
        if (!fgets(input, sizeof(input), stdin)) {
            break; /* Exit if there's an error*/
        }

        /* Remove trailing newline character, if any*/
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        /* Parse the command into arguments*/
        parse_command(input, args);

        
    }

    return 0;
}

/* Function to parse the command into arguments*/
void parse_command(char *command, char **args) {
    char *toke
    int i = 0;

    /*Using strtok to split the command into tokens (arguments)*/
    token = strtok(command, "-");
    while (token != NULL && i < MAX_ARGS - 1) {
        args[i++] = token;
        token = strtok(NULL, "-");
    }
    args[i] = NULL; /* Set the last argument to NULL to indicate end of args*/

switch (token)
 
 case "ls"/* constant-expression */:
    execve(usr/bin/ls)/* code */
    break;

 case "echo"/* constant-expression */:
   execve(usr/bin/echo) /* code */
    break;

    case "less"/* constant-expression */:
   execve(usr/bin/less) /* code */
 default: printf("Unknown Comand ")
    break; 
}
