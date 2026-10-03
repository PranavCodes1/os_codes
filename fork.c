#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	pid_t pid;

	pid = fork();

	if(pid < 0)
	{
		printf("Fork failed \n");
	}
	else if(pid == 0)
	{
		printf("I am a child Process\n");
		printf("Child Process ID: %d\n", getpid());
	}
	else
	{
		printf("I am Parent Process \n");
		printf("Parent Process ID: %d\n", getpid());
	}
	return 0;
}

