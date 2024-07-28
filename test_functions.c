#include "main.h"

int main(void)
{
    while(1) 
    /* Beging infinite loop for shell*/
    {
        char *str = NULL;
        /* store pointer to line */
        size_t len = 0;
        /* size of the line */
        ssize_t num_read; 
        /* Number of characters read by getline */
        printf(" "); 
        /* Print out a space and wait for usedr input, later we will add the path I think */
        str = getline (&str, stdin);
        /* str gets the string taken by getline */

        char* delim = "-"; 
        /* Delimiters set in str tok telling the function when to split */
        char* toke = strtok(str, delim);
        /* Break down the input into token(s)*/
      
        pid_t child = fork();
        /* create child process using fork */
        if(child == 0) 
        /* check to see if we are in the child process */
        {
         printf("%s\n", toke);
        }
        else 
        {
          wait(NULL);
          /* Wait for the child process to terminate */
        }
    }
}

/*
int main()
{
  pid_t child_proc;
  child_proc = fork();

  if(child_proc == 0)
  {
    execve("/usr/bin/ls", NULL, NULL);
    printf("Unknown command\n");
    exit(0);
  }
  else 
  {
    wait(child_proc == NULL);
    printf("child_proc has finished\n")
  }

}
*/