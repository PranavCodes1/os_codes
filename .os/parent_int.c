#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	int n;
	pid_t pid;

	printf("Enter a integer: ");
	scanf("%d",&n);

	pid = fork();

	if(pid < 0)
	{
		printf("Fork Failed\n");
	}
	else if(pid == 0)
	{
		char num[20];

		sprintf(num,"%d",n);

		execl("./child_int", "child",num,NULL);

		printf("execl failed\n");
	}
	else
	{
		wait(NULL);
		printf("Parent Process completed.\n");
	}
	return 0;
}
