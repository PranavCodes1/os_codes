#include<stdio.h>

struct Process
{
	int pid,at,bt,wt,tat,ct,completed;
};

int main()
{
	int i,n;
	int completed = 0;
	int t = 0;
	float wtavg = 0;
	float tatavg = 0;
	int shortest;

	struct Process p[20];

	printf("Enter no.of processes: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		p[i].pid = i + 1;

		printf("Enter arrival time of P%d\n", p[i].pid);
		scanf("%d",&p[i].at);

		printf("Enter CPU Burst time of P%d\n",p[i].pid);
		scanf("%d",&p[i].bt);

		p[i].completed = 0;
	}

	printf("\nGantt Chart\n");

	while(completed<n)
	{
		shortest = -1;

		for(i=0;i<n;i++)
		{
			if(p[i].completed == 0 && p[i].at <= t)
			{
				if(shortest == -1 || p[i].bt < p[shortest].bt)
				{
					shortest = i;
				}
			}
		}

		if(shortest == -1)
		{
			t++;
			continue;
		}
		
		printf("|P%d",p[shortest].pid);

		p[shortest].wt = t - p[shortest].at;


		if(p[shortest].wt < 0)
		{
			p[shortest].wt = 0;
		}

		t = t + p[shortest].bt;

		p[shortest].tat = p[shortest].wt + p[shortest].bt;

		p[shortest].completed = 1;
		completed++;

		p[shortest].ct = t;

		wtavg += p[shortest].wt;
		tatavg+= p[shortest].tat;
	}

	printf("|\n");

	printf("\nProcess\tAT\tBT\tWT\tCT\tTAT\n");

	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].ct,p[i].tat);

	}

	wtavg = wtavg / n;
	tatavg = tatavg / n;

	printf("\n Average waiting time = %.2f",wtavg); 
	printf("\n Average turnaround time = %.2f",tatavg); 
	return 0;
}




