#include<stdio.h>

int main()
{
	int ref[50], frame[10];
	int n,m,i,j,k;
	int pageFault = 0;
	int found;


	printf("Enter number of pages in reference string: ");
	scanf("%d",&n);

	printf("Enter reference string: ");
	for(i=0;i<n;i++)
		scanf("%d",&ref[i]);

	printf("Enter number of frames: ");
	scanf("%d",&m);

	for(i=0;i<n;i++)
	{
		frame[i] = -1;
	}

	printf("\nPage\tFrame\t\tStatus\n");

	for(i=0;i<n;i++)
	{
		found = 0;

		for(j=0;j<m;j++)
		{
			if(frame[j] == ref[i])
			{
				found = 1;
				break;
			}
		}

		//page fault

		if(found == 0)
		{
			frame[k] = ref[i];
			k = (k+1) % m;
			pageFault++;
		}

		printf("%d\t",ref[i]);

		for(j=0;j<m;j++)
		{
			if(frame[j] == -1)
			{
				printf("-");
			}
			else
			{
				printf("%d",frame[j]);
			}
		}

		if(found)
		{
			printf("\tHit");
		}
		else
		{
			printf("\tPagefault");
		}

		printf("\n");
	}
	printf("total no. of page faults = %d\n",pageFault);
	return 0;
}
			

