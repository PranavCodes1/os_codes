#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

void handler(int sig)
{
	printf("Parent received interrupt signal\n");
}

int main()
{
	pid_t pid;

	signal(SIGINT,handler);

	pid=fork();

	if(pid == 0)
	{
		printf("Child Process\n");
		printf("Child sending signal to Parent\n");
		kill(getppid(),SIGINT);
	}
	else
	{
		printf("Parent waiting for signal\n");
		
		pause();
		wait(NULL);

	}
	return 0;
}
