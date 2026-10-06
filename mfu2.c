#include <stdio.h>

int main()
{
    int ref[100], frame[20], count[20];
    int n, m, i, j;
    int pageFault = 0, found;
    int pos, max;

    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
    {
        frame[i] = -1;
        count[i] = 0;
    }

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        /* Check if page is already present */
        for(j = 0; j < m; j++)
        {
            if(frame[j] == ref[i])
            {
                found = 1;
                count[j]++;
                break;
            }
        }

        /* Page Fault */
        if(!found)
        {
            pageFault++;

            /* Find empty frame */
            pos = -1;

            for(j = 0; j < m; j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            /* If all frames are full, find MFU page */
            if(pos == -1)
            {
                max = count[0];
                pos = 0;

                for(j = 1; j < m; j++)
                {
                    if(count[j] > max)
                    {
                        max = count[j];
                        pos = j;
                    }
                }
            }

            /* Insert new page */
            frame[pos] = ref[i];
            count[pos] = 1;
        }

        /* Display */
        printf("%d\t", ref[i]);

        for(j = 0; j < m; j++)
        {
            if(frame[j] == -1)
                printf("- ");
            else
                printf("%d ", frame[j]);
        }

        if(found)
            printf("\tHit");
        else
            printf("\tPage Fault");

        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFault);

    return 0;
}

