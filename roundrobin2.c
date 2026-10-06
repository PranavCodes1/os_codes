#include<stdio.h>

struct Process
{
	int pid,at,bt,wt,ct,tat,rembt;
};

int main()
{
	int n,tq,i;
	int t = 0;
	int completed = 0;
	int found;

	float wtavg = 0;
	float tatavg = 0;

	struct Process p[20];

	printf("Enter no. of processes: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		p[i].pid = i+1;

		printf("Enter arrival time of P%d: ",p[i].pid);
		scanf("%d",&p[i].at);

		printf("Enter CPU burst time of P%d: ",p[i].pid);
		scanf("%d",&p[i].bt);

		p[i].rembt = p[i].bt;
	}

	printf("Enter time quantum: ");
	scanf("%d",&tq);

	printf("\nGantt Chart:\n");

	while(completed < n)
	{
		found = 0;

		for(i=0;i<n;i++)
		{
			if(p[i].at <= t && p[i].rembt > 0)
			{
				found = 1;

				printf("|P%d",p[i].pid);

				if(p[i].rembt > tq)
				{
					t = t + tq;
					p[i].rembt = p[i].rembt - tq;
				}
				else
				{
					t = t + p[i].rembt;
					p[i].rembt = 0;

					p[i].ct = t;
					p[i].tat = p[i].ct - p[i].at;
					p[i].wt = p[i].tat - p[i].bt;

					wtavg += p[i].wt;
					tatavg += p[i].tat;

					completed++;
				}
			}
		}

		if(found == 0)
		{
			t++;
		}
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

	printf("\nAverage waiting time = %.2f\n",wtavg);
	printf("Average turnaround time = %.2f\n",tatavg);

	return 0;
}
