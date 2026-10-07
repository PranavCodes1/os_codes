#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>


void handler(int sig)
{
	printf("Parent received user defined signal\n");
}

int main()
{
	pid_t pid;
	
	signal(SIGUSR1,handler);

	pid = fork();

	if(pid<0)
	{
		printf("Fork failed");
		return 1;
	}
	else if(pid == 0)
	{
		printf("Child process\n");
		sleep(2);
		printf("Child sending signal to parent\n");
		kill(getppid(),SIGUSR1);
	}
	else
	{
		printf("Parent waiting for signal..\n");
		pause();
		wait(NULL);
		 printf("Parent continues execution\n");
   	 }

    return 0;
}

