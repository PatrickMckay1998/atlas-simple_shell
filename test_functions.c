#include <stdio.h>
#include <string.h>

int main()
{
  int indefinite = 1;

  while (indefinite != 0)/* Starts infinite loop so user can input command over and over again */
  {
      char string[50]; /* Set an array of fifty characters for the user input */

      printf("Enter command: "); /* User inputs commands for the shell */
      scanf("%s", string); /* Scan for input and assign to string */

      char* delimiter = " -"; /* Set our delimiters for the string */
      char* token = strtok(string, delimiter); /* Taking our string and tokenize it */

    while (token != NULL) /* go through the string and print each token until we reach the end */
    {
      
      /*printf("%s\n", token);*/
      token = strtok(NULL, delimiter); /* Move on to next token*/
    }  
    
    /*token = strtok(NULL, " ");*/
  }

  return (0);
}

/*
int main() 
{
    int a, b;
   
      printf("Enter first number: ");
      scanf("%d", &a);
   
      printf("Enter second number: ");
      scanf("%d", &b);
   
      printf("A : %d \t B : %d" , 
            a , b);
   
    return 0;
}
*/