#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>


void bubbleSort(int a[], int n)
{
	int i,j,temp;

	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

int main()
{
	int i,n,status;
	int a[100];

	printf("Enter no. of integers: \n");
	scanf("%d",&n);

	printf("Enter integers: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}


	pid_t pid;

	pid = fork();

	if(pid<0)
	{
		printf("Fork failed\n");
	}
	else if(pid == 0)
	{
		bubbleSort(a,n);
		printf("\nChild Process\n");
		printf("Sorted Integers: ");
		for(i=0;i<n;i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
		exit(0);
	}
	else
	{
		wait(&status);

		printf("\nParent Process\n");

		if(WIFEXITED(status))
		{
			printf("Child exit status = %d\n",WEXITSTATUS(status));
		}
	}
	return 0;
}

