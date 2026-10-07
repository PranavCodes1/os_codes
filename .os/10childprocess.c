#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{

	int i;
	pid_t pid;

	for(i=0;i<10;i++)
	{
		pid = fork();

		if(pid == 0)
		{
			printf("Child %d: PID = %d\n",i+1, getpid());
			return 0;
		}
	}

	for(i=0;i<10;i++)
	{
		wait(NULL);
	}

	printf("All child processes terminated:\n");
	printf("Parent PID = %d\n",getpid());

	return 0;
}
