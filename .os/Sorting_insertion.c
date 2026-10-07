#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void insertionSort(int a[], int n)
{
	int i,j,key;

	for(i=1;i<n;i++)
	{
		key = a[i];
		j = i-1;

		while(j >= 0 && a[j]>key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

void display(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

int main()
{
	int n,i;
	int a[50];
	pid_t pid;


	printf("Enter no of integers: ");
	scanf("%d",&n);

	printf("Enter integers: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}


	pid = fork();

	if(pid < 0)
	{
		printf("Fork failed");

	}
	else if(pid == 0)
	{
		insertionSort(a,n);
		printf("\n Child Process \n");
		printf("Sorted elements: \n");
		display(a,n);
	}

	else
	{
		wait(NULL);
		printf("\nParent Process\n");
		printf("Child process completed\n");
	}
	return 0;
}
