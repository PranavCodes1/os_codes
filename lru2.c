#include<stdio.h>

int main()
{
	int ref[50],frame[10],recent[10];
	int n,m,i,j;
	int pageFault = 0;
	int found,pos,min;

	printf("Enter number of pages in reference string: ");
	scanf("%d",&n);

	printf("Enter reference string: ");
	for(i=0;i<n;i++)
		scanf("%d",&ref[i]);

	printf("Enter number of frames: ");
	scanf("%d",&m);

	for(i=0;i<m;i++)
	{
		frame[i] = -1;
		recent[i] = -1;
	}

	printf("\nPage\tFrames\t\tStatus\n");

	for(i=0;i<n;i++)
	{
		found = 0;

		/* Check whether page is already present */
		for(j=0;j<m;j++)
		{
			if(frame[j] == ref[i])
			{
				found = 1;
				recent[j] = i;
				break;
			}
		}

		/* Page fault */
		if(found == 0)
		{
			pageFault++;
			pos = -1;

			/* Find empty frame */
			for(j=0;j<m;j++)
			{
				if(frame[j] == -1)
				{
					pos = j;
					break;
				}
			}

			/* If no empty frame, replace least recently used page */
			if(pos == -1)
			{
				min = recent[0];
				pos = 0;

				for(j=1;j<m;j++)
				{
					if(recent[j] < min)
					{
						min = recent[j];
						pos = j;
					}
				}
			}

			frame[pos] = ref[i];
			recent[pos] = i;
		}

		printf("%d\t",ref[i]);

		for(j=0;j<m;j++)
		{
			if(frame[j] == -1)
				printf("- ");
			else
				printf("%d ",frame[j]);
		}

		if(found)
			printf("\tHit");
		else
			printf("\tPage Fault");

		printf("\n");
	}

	printf("\nTotal number of page faults = %d\n",pageFault);

	return 0;
}
