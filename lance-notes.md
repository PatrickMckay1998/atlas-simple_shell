plans for simpleshell_01 
{
    -display prompt and wait for user to type a command

    - For now it our message should display " enter command: "

    -user inputs command, command executes

    -go to new line and wait for next input (Loop back over)
}

simpleshell_01 steps
{
    -Just create program waiting for user input
    /*#include <stdio.h>
#include <string.h>

int main(void) {
    char input[50];

    printf("Enter Comand: ");
    scanf("%s", input);

    /* input to refrence the comand.*/ 

    return 0;
    }*/

    -Return (0); 

    -Loop through getting the user input and then displaying a new line waiting for another input

    -Error handling if executable can not be found

    -Handle exiting the program
}

Test_variadic.c Notes 
    Main Function (main()):

The program enters an infinite loop where it continuously prompts the user with "Shell >> ".
It reads the user input using fgets() and removes the newline character at the end if present.

    Parsing Function (parse_command()):

parse_command() uses strtok() to split the input command into tokens (arguments) based on "-" as delimiter.
It stores each token into the args array which will be passed on later.
It terminates the args array with a NULL pointer to indicate the end of arguments.
