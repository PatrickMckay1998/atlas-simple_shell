#include "main.h"


int main(void)
{
    while(1) /* Beging infinite loop for shell*/
    {
        char str[50]; /* Create an array so handle user input */

        printf("Enter command: "); /* Ask for command, scan and assign to str */
        scanf("%s", str);
        /* use getline instead of scanf */
        char* delim = " -"; /* Delimiters set in str tok telling the function when to split */
        char* token = strtok(str, delim) /* Break down the input into tokens*/

        while (token != NULL)
        {
            token = strtok(NULL, delim);
        }

    }
}