#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void bubbleSort(int a[],int n)
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


void insertionSort(int a[],int n)
{
	int i,j,key;

	for(i=1;i<n;i++)
	{
		key = a[i];
		j = i-1;

		while(j>= 0 && a[j] > key)
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}

void display(int a[], int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		
		printf("\n");
	}
}

int main()
{
	int n,i;

	int a[100];

	printf("Enter number of elements: ");
	scanf("%d", &n);

	printf("Enter elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}

	pid_t pid = fork();

		if(pid == 0)
		{
			insertionSort(a,n);
			printf("\n Child process \n");
			printf("Sorting method= Insertion sort\n");
			printf("Sorted elements: ");
			display(a,n);

		}
		else
		{
			bubbleSort(a,n);
			wait(NULL);

			printf("\n Parent Process \n");
			printf("Sorting method = Bubble sort\n");
			printf("Sorted elements: ");
			display(a,n);
		}
		return 0;
}

