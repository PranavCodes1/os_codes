#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t pid;

	pid = fork();

	if(pid < 0)
	{
		printf("Fork falied");
		return 1;
	}
	else if(pid == 0)
	{
		sleep(5);
		printf("\n Child Process \n");
		printf("Child PID = %d\n", getpid());
		printf("Parent PID = %d\n", getppid());
		printf("Child has become an orphan process.\n");
	}
	else
	{
		printf("\nParent Process\n");
		printf("Parent PID = %d\n", getpid());
		printf("Parent is terminating.\n");
		exit(0);
	}
	return 0;
}


