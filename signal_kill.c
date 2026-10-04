#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>


void handler(int sig)
{
	printf("Parent received signal\n");
}

int main()
{
	pid_t pid;

	signal(SIGINT,handler);

	pid = fork();

	if(pid == 0)
	{
		printf("Child Process \n");
		sleep(2);

		printf("Child sending signal to parent\n");
		kill(getppid(), SIGINT);

	}

	else
	{
		printf("Parent waiting for signal ...\n");
		pause();
		
		wait(NULL);
	}	
	return 0;
}

