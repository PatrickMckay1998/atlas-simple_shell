#include "main.h"


int main(void)
{
    while(1)
    /* Beging infinite loop for shell*/
    {
        char* delim = "-"; 
        /* Delimiters set in str tok telling the function when to split */
        char* toke;
        /* Token is a pointer to the first token */
        pid_t child;
        /* create variable for child process */
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

        child = fork();
        /* create child process using fork */
        if(child == 0)
        /* check to see if we are in the child process */
        {
         printf("%s\n", toke);
         printf("num_read = %ld\n", num_read);
        }
        else
        {
          wait(NULL);
          /* Wait for the child process to terminate */
        }
    }
}