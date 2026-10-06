#include<stdio.h>

struct Process
{

	int pid,at,bt,wt,ct,tat,priority,completed;
};

int main()
{
	int i,n;
	int t = 0;
	int highest;
	int completed = 0;
	float wtavg = 0;
	float tatavg = 0;

	struct Process p[20];
	printf("Enter number of processes: ");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
		p[i].pid = i+1;

		printf("Enter arrival time for P%d\n",p[i].pid);
		scanf("%d",&p[i].at);

		printf("Enter CPU Burst Time for P%d\n",p[i].pid);
		scanf("%d",&p[i].bt);

		printf("Enter Priority for P%d\n",p[i].pid);
		scanf("%d",&p[i].priority);

		p[i].completed = 0;
	}

	printf("\nGantt Chart\n");

	while(completed < n)
	{
		highest = -1;

		for(i=0;i<n;i++)
		{
			if(p[i].completed == 0 && p[i].at <= t)
			{
				if(highest == -1 || p[i].priority < p[highest].priority)
				{
					highest = i;
				}
			}
		}


		if(highest == -1)
		{
			t++;
			continue;
		}

		printf("|P%d",p[highest].pid);

		p[highest].wt = t - p[highest].at;

		if(p[highest].wt < 0)
		{
			p[highest].wt = 0;
		}
		
		t = t + p[highest].bt;

		p[highest].tat = p[highest].wt + p[highest].bt;

		p[highest].ct = t;
		
		p[highest].completed = 1;
		completed++;

		wtavg += p[highest].wt;

		tatavg += p[highest].tat;

	}

	printf("|\n");

    	printf("\nProcess\tAT\tBT\tPriority\tWT\tCT\tTAT\n");

    	for(i = 0; i < n; i++)
    	{
        	printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               	p[i].pid,
               	p[i].at,
               	p[i].bt,
               	p[i].priority,
               	p[i].wt,
               	p[i].ct,
               	p[i].tat);
    	}

    	wtavg = wtavg / n;
    	tatavg = tatavg / n;

    	printf("\nAverage waiting time = %.2f", wtavg);
   	printf("\nAverage turnaround time = %.2f\n", tatavg);

   	return 0;
}
