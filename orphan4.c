#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

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
		sleep(5);
		printf("Child process: \n");
		printf("Child PID = %d\n",getpid());
		printf("Parent PID = %d\n",getppid());
		printf("Child process has become an orphan.\n");
	}

	else
	{
		printf("Parent Process: \n");
		printf("Parent PID : %d\n",getpid());
		printf("Parent process is terminating..\n");
		exit(0);
	}
	return 0;
}


