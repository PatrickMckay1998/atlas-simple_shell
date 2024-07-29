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
        if (num_read == -1)
        {
                perror("getline");
                exit (0);
        }

        i = 0;
        toke = strtok(str, delim);
        /* Break down the input into token(s)*/
        while (toke != NULL)
        {
                argvec[i++] = toke;
                toke = strtok(NULL, delim);
        }
        argvec[i] = NULL;

        child = fork();
        /* create child process using fork*/
        if (child == 0)
        {
            if (execve(argvec[0], argvec, envec) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(NULL);
            printf("Child process has terminated\n");
        }
    }
}