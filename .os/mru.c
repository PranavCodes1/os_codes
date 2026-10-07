#include <stdio.h>

int main()
{
    int ref[50], frame[10], recent[10];
    int n, m;
    int i, j;
    int pageFault = 0;
    int found, pos, max;

    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &m);

    /* Initialize frames */
    for(i = 0; i < m; i++)
    {
        frame[i] = -1;
        recent[i] = -1;
    }

    printf("\nPage\tFrames\t\tStatus\n");

    /* Process each page */
    for(i = 0; i < n; i++)
    {
        found = 0;

        /* Check if page is already present */
        for(j = 0; j < m; j++)
        {
            if(frame[j] == ref[i])
            {
                found = 1;
                recent[j] = i;
                break;
            }
        }

        /* If page is not present */
        if(found == 0)
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

            /* If all frames are full, find MRU page */
            if(pos == -1)
            {
                max = recent[0];
                pos = 0;

                for(j = 1; j < m; j++)
                {
                    if(recent[j] > max)
                    {
                        max = recent[j];
                        pos = j;
                    }
                }
            }

            /* Insert new page */
            frame[pos] = ref[i];
            recent[pos] = i;
        }

        /* Display current page and frames */
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
