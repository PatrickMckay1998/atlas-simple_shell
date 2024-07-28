#include "main.h"

int main(void)
{
    while(1) 
    /* Beging infinite loop for shell*/
    {
        char str[50]; 
        /* Create an array so handle user input */

        printf("Enter command: "); 
        /* Ask for command, scan and assign to str */
        scanf("%s", str);

        char* delim = " "; 
        /* Delimiters set in str tok telling the function when to split */
        char* token = strtok(str, delim);
        /* Break down the input into token(s)*/
      
        pid_t child = fork();
        /* create child process using fork */
        if(child == 0) 
        /* check to see if we are in the child process */
        {
          const char* name = token;
          getenv(name);

          execve("token", NULL, NULL);
          /* use execve to run the command which should be whatever token is, I could be wrong */
          perror("Unknown command"); 
          /* Nothing should execute after execve UNLESS there is an error with execve in which perror will say unknown command and we will exit with 0 */
          exit(0);
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