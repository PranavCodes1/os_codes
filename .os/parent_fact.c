#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{

	int n;

	printf("Enter a number: ");
	scanf("%d",&n);

	pid_t pid;
	pid = fork();

	if(pid < 0)
	{
		printf("Fork failed\n");
	}
	else if (pid == 0)
	{
		printf("Child process\n");

		char num[20];

		sprintf(num,"%d",n);

		execl("./child_fact","child",num,NULL);

		printf("execl failed \n");
	}
	else
	{
		wait(NULL);
		printf("Parent process completed.\n");
	}
	return 0;
}


