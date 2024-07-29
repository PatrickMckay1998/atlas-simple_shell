#include "main.h"




 {
    /* Common directories to search for commands*/
    char *directories[] = {"/bin", "/usr/bin", NULL};
    char *path = malloc(256); /* Allocate memory for the path*/

    for (int i = 0; directories[i] != NULL; i++) {
        snprintf(path, 256, "%s/%s", directories[i], command);
        if (access(path, X_OK) == 0) { /* Check if the command exists and is executable*/
            return path; /* Return the full path of the command*/
        }
    }

    free(path); /* Free memory if command is not found*/
    return NULL; /* Command not found*/
}

/*Function to run a command with arguments*/
void run_command(char *command, char *const args[]) {
    char *command_path = search_command(command);

    if (command_path == NULL) {
        fprintf(stderr, "Command not found: %s\n", command);
        exit(EXIT_FAILURE);
    }
   execve(command_path, args, NULL);
    perror("execve"); /* If execve fails, print error*/
    free(command_path);
    exit(EXIT_FAILURE);
}

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