#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  /* create variable for child process */
  /*int status;*/
  pid_t child_proc = fork();
  /* Actually creating the child prcess using fork */

  if(child_proc == 0) 
  /* checking if we are in the child process by checking the pid which should be 0 */
  {
    execve("/usr/bin/ls", NULL, NULL);
    /* execute our command, not sure if the syntax is correct */
    printf("Unknown command\n"); 
    /* print unknown command if execve doesnt work */
    exit(0);
  }
  else 
  /* if execve works and is successful then we have the parent process wait */
  {
    wait(NULL); 
    /* we use wait to wait for the child process to terminate  */
    printf("child_proc has finished\n");
  }

  return (0);

}