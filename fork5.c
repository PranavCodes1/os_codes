#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	pid = fork();

	if(pid<0)
	{
		printf("Fork Failed\n");

	}
	else if(pid == 0)
	{
		printf("I am child Process\n");
		printf("Parent PID = %d\n", getppid());
	}

	else
	{
		printf("I am parent process\n");
		printf("Child PID = %d\n",pid);
		wait(NULL);
	}
	return 0;
}
