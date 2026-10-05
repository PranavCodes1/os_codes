#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

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

void insertionSort(int a[], int n)
{
    int i,j,key;

    for(i=1;i<n;i++)
    {
        key = a[i];
        j = i-1;

        while(j >= 0 && a[j] > key)
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
        printf("%d ",a[i]);
    }

    printf("\n");
}

int main()
{
    int n,i;
    int a[50];

    printf("Enter no. of integers: ");
    scanf("%d", &n);

    printf("Enter integers:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    pid_t pid;
    pid = fork();

    if(pid < 0)
    {
        printf("Fork failed\n");
    }
    else if(pid == 0)
    {
        insertionSort(a,n);

        printf("Child Process\n");
        printf("Sorting method = Insertion Sort\n");
        printf("Sorted elements are: ");
        display(a,n);
    }
    else
    {
        bubbleSort(a,n);

        wait(NULL);

        printf("Parent Process\n");
        printf("Sorting method = Bubble Sort\n");
        printf("Sorted elements are: ");
        display(a,n);
    }

    return 0;
}
