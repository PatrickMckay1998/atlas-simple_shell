#include "main.h"


int main(void)
{
    while(1) /* Beging infinite loop for shell*/
    {
        char* delim = "-";
        char* toke;
        pid_t child;

        char* argvec[] = {NULL};
        char* envec[] = {NULL};


        char *str = NULL;
        /* store pointer to line */
        size_t len = 0;
        /* size of the line */
        ssize_t num_read;
        /* Number of characters read by getline */
        printf(" ");
        /* Print out a space and wait for usedr input, later we will add the path I think */
        num_read = getline (&str, &len, stdin);
        /* str gets the string taken by getline */

        /* Delimiters set in str tok telling the function when to split */
        toke = strtok(str, delim);
        /* Break down the input into token(s)*/

  child = fork(); /* Create child process using fork*/
        if (child == -1) {
            perror("fork");
            free(str);
            exit(EXIT_FAILURE);
        }
        
        if (child == 0) {
            /* In child process*/
            execve(argvec[0], argvec, NULL);
            perror("execve");
            free(str);
            exit(EXIT_FAILURE);
        } else {
            /* In parent process*/
            wait(NULL); /* Wait for the child process to terminate*/
            printf("child process has terminated\n");
        }
        
        /* Free the input string memory*/
        free(str);
        str = NULL;
        len = 0;
    }

    return 0;
}