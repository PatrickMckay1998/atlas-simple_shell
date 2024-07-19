#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t current_pid;

    current_pid = getpid();
    printf("%u\n", current_pid);

    
    return (0);
}