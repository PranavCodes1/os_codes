#include<stdio.h>

struct Process
{
	int pid,at,bt,wt,ct,tat;
};

int main()
{
	int i,j,n;

	float wtavg = 0;
	float tatavg = 0;

	struct Process p[20],temp;

	printf("Enter no. of processes: \n");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		p[i].pid = i+1;

		printf("Enter arrival time of P%d: ",p[i].pid);
		scanf("%d",&p[i].at);

		printf("Enter CPU Burst time of P%d: ",p[i].pid);
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

	p[0].wt = 0;
	p[0].tat = p[0].wt + p[0].bt;
	p[0].ct = p[0].at + p[0].tat;

	wtavg = p[0].wt;
	tatavg = p[0].tat;

	for(i=1;i<n;i++)
	{
		p[i].wt = p[i-1].wt + p[i-1].bt - p[i].at;

		if(p[i].wt < 0)
		{
			p[i].wt = 0;
		}

		p[i].tat = p[i].wt + p[i].bt;
		p[i].ct = p[i].at + p[i].tat;

		wtavg += p[i].wt;
		tatavg += p[i].tat;
	}

	printf("\nGantt Chart\n");

	for(i=0;i<n;i++)
	{
		printf("|P%d",p[i].pid);
	}

	printf("|\n");

	printf("\nProcess\tAT\tBT\tWT\tCT\tTAT\n");

	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
		p[i].pid,p[i].at,p[i].bt,
		p[i].wt,p[i].ct,p[i].tat);
	}

	wtavg = wtavg / n;
	tatavg = tatavg / n;

	printf("\nAverage turnaround time = %.2f\n",tatavg);
	printf("Average waiting time = %.2f\n",wtavg);

	return 0;
}
