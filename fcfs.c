#include<stdio.h>

struct Process
{
int pid,at,bt,wt,tat;
};

int main()
{
int n,i,j;

float wtavg = 0;
float tatavg = 0;

struct Process p[20],temp;

printf("Enter no. of processes: ");
scanf("%d",&n);

for(int i=0;i<n;i++)
{
p[i].pid = i+1;

printf("Enter arrival time of P%d: ",p[i].pid);
scanf("%d",&p[i].at);

printf("\n Enter CPU burst time of P%d: ",p[i].pid);
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
p[0].tat = p[0].bt;

wtavg = p[0].wt;
tatavg = p[0].tat;

for(i=1;i<n;i++)
{
p[i].wt = p[i-1].wt + p[i-1].bt - p[i].at;
if(p[i].wt<0)
	p[i].wt = 0;
	
p[i].tat = p[i].wt + p[i].bt;

wtavg += p[i].wt;
tatavg += p[i].tat;
}

printf("Gantt Chart: \n");

for(i=0;i<n;i++)
{
	printf("| P%d",p[i].pid);
}
printf("|\n");

printf("\nProcess\tAT\tBT\tWT\tTAT\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].wt,p[i].tat);

wtavg = wtavg / n;
tatavg = tatavg / n;
}

printf("\n Average waiting time = %.2f",wtavg);

printf("\n Average turnaround time = %.2f",tatavg);

return 0;
}



