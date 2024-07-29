#include "main.h"

#define PATH_MAX 4096

const char *search_directory[] = {"/bin", "/usr/bin", "/usr/local/bin", NULL};
/* Predefined directories to search for commands */

int main(void)
{

    while(1) /* Beging infinite loop for shell*/
    {
        char* delim = "-"; 
        /* We have our delimiters set for strtok*/
        char* toke;
        /* Variable used for strtok, it will store each token */
        pid_t child;
        /* Child process identifier */

        char* argvec[] = {NULL};
        /* This is the array of character pointers for the command and each argument, argvec[0] is a pointer to the path name of the command */
        char* envec[] = {NULL};
        /* This sets the environment for execve? still not sure */
        char command_path[PATH_MAX];
        /* This is what we will use for the command path to give to execve */

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
                /* We work our way through each token and add it to the array */
                toke = strtok(NULL, delim);
        }
        argvec[i] = NULL;
        /* NULL terminate list */


  child = fork(); /* Create child process using fork*/
        if (child == -1) 
        {
            perror("fork");
            free(str);
            exit(EXIT_FAILURE);
        }
        
        if (child == 0) 
        {
            j = 0;

            while (search_directory[j] != NULL)
            {
                strcpy(cmd_path, search_dirs[j]);
                /* copy the string to the comma*/
                strcat(cmd_path, "/");
                strcat(cmd_path, argvec[0]);

                if (access(command_path, X_OK) == 0)
                {
                    execve(command_path, argvec, NULL);
                    perror("execve");
                    exit(EXIT_FAILURE);
                }

                j++;
                /* Increment the counter */
            }
            
        } 
        
        else 
        {
            /* In parent process*/
            wait(NULL); /* Wait for the child process to terminate*/
            printf("child process has terminated\n");
        }
        
        /* Free the input string memory*/
        free(str);
        str = NULL;
    }

    return 0;
}