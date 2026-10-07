#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    pid_t pid;

    pid = fork();

    if(pid < 0)
    {
        printf("Fork failed\n");
    }
    else if(pid == 0)
    {
        printf("\nI am Child Process\n");
        printf("Child Process ID = %d\n",getpid());
        printf("Parent Process ID = %d\n",getppid());
    }
    else
    {
        printf("\nI am Parent Process\n");
        printf("Parent Process ID = %d\n",getpid());
        printf("Child Process ID = %d\n",pid);
	wait(NULL);
    }

    return 0;
}
