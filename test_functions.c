#include "main.h"

int main()
{
  while(1) /* Begin infinite loop for shell*/
  {
    char str[50]; /* Create an array so handle user input *

    printf("Enter command: "); /* Ask for command, scan and assign to str */
    scanf("%s", str);

    char* delim = " -"; /* Delimiters set in str tok telling the function when to split */
    char* token = strtok(str, delim) /* Break down the input into tokens*/

    /* const char *name = "PATH"; Using getenv we can obtain the enviornment that is needed for execv (DONT QUOTE ME ON THAT)
    const char *env = getenv(name); getenv uses the the name ptr to locate the */

    while (token != NULL)
    {    
      printf("%s", token);
      token = strtok(NULL, delim);
    }
  }
  return (0);
}
