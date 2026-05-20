#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_COUNT 5

void parentprocess();
void childprocess();

int main()
{
    pid_t pid;

    pid = fork();

    if(pid == 0)
        childprocess();
    else
        parentprocess();

    return 0;
}

void childprocess()
{
    printf("The output for execlp syscall is:\n");

    execlp("/bin/ls", "ls", NULL);
}

void parentprocess()
{
    int i, k;

    k = getpid();

    wait(NULL);

    for(i = 1; i <= MAX_COUNT; i++)
        printf("The line from parent value = %d\n", i);

    printf("The parent process is done\n");

    printf("getpid() value of process id is %d\n", k);

    exit(0);
}