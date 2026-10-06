#include<stdio.h>

int main()
{
	int ref[100],frame[20],count[20];
	int i,j,m,n;
	int pageFault = 0;
	int found,pos,min;

	printf("Enter no. of pages in reference string: \n");
	scanf("%d",&n);

	printf("Enter reference string: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&ref[i]);
	}

	printf("Enter no. of frames: \n");
	scanf("%d",&m);

	for(i=0;i<n;i++)
	{
		frame[i] = -1;
		count[i] = 0;
	}

	printf("\nPage\tFrames\t\tStatus\n");
	
	for(i=0;i<n;i++)
	{
		found = 0;
		
		//check if page is already present
		for(j=0;j<m;j++)
		{
			if(frame[j] == ref[i])
			{
				found = 1;
				count[j]++;
				break;
			}
		}



		//page fault

		if(!found)
		{
			pageFault++;


			//find empty frame
			
			pos = -1;

			for(j=0;j<m;j++)
			{
				if(frame[j] == -1)
				{
					pos = j;
					break;
				}
			}
			//if all frames are full,find lfu
			
			if(pos == -1)
			{
				min = count[0];
				pos = 0;

				for(j=1;j<m;j++)
				{
					if(count[j] < min)
					{
						min = count[j];
						pos = j;
					}
				}
			}

			//insert a new page
			
			frame[pos] = ref[i];
			count[pos] = 1;

		}

		//display

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
			printf("\tpageFault");
		}

		printf("\n");
	}

	printf("Total number of page fault:%d\n", pageFault);

	return 0;
}
