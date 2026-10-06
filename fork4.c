#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	pid = fork();

	if(pid<0)
	{
		printf("Fork failed\n");

	}

	else if(pid == 0)
	{
		printf("I am Child Process\n");
		printf("Child PID = %d\n",getpid());
		printf("Parent PID = %d\n",getppid());
	}
	else
	{
		printf("I am parent process\n");
		printf("Parent PID = %d\n",getpid());
			wait(NULL);

	}
	return 0;
}
