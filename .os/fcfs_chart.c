#include<stdio.h>

struct Process
{
	int pid,at,bt;
};

int main()
{
	int n,i,j;
	int t = 0;

	struct Process p[20],temp;

	printf("Enter no.of processes: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		p[i].pid = i + 1;

		printf("Enter arrival time of P%d\n", p[i].pid);
		scanf("%d",&p[i].at);

		printf("Enter CPU burst time of P%d: ",p[i].pid);
        	scanf("%d",&p[i].bt);
    	}

	 /* Sort according to arrival time */
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(p[j].at > p[j+1].at)
			{
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}



	printf("\n Gantt Chart \n");
	for(i=0;i<n;i++)
	{
		if(t < p[i].at)
		{
			t = p[i].at;
		}

		printf("| P%d", p[i].pid);

		t = t + p[i].bt;
	}

	printf("|\n");

	return 0;
}
