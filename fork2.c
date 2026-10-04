#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t pid;

	pid = fork();

	if(pid < 0)
	{
		printf("Fork failed");
	}

	else if(pid == 0)
	{
		printf("I am child process\n");
		printf(" Parent process ID= %d\n",getppid());
	}
	else
	{
		printf(" I am Parent Process\n");
		printf("Parent process ID =  %d\n",getpid());
		wait(NULL);
	}
	return 0;
}

