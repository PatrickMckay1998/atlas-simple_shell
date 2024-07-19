#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int main(void) {
    int input;
    int i; 
    i = 1;
while (i < 0 )
    printf("Enter Comand: ");
    scanf("%s", input);

    /* input to refrence the comand.*/ 
    printf("you entered %s" , input);
    i++;
    return (0);
    }