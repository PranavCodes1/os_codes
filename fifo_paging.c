#include <stdio.h>

int main()
{
    int ref[100], frame[20];
    int n, m, i, j, k = 0;
    int pageFault = 0, found;

    printf("Enter number of pages in reference string: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &ref[i]);

    printf("Enter number of frames: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\t\tStatus\n");

    for(i = 0; i < n; i++)
    {
        found = 0;

        for(j = 0; j < m; j++)
        {
            if(frame[j] == ref[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            frame[k] = ref[i];
            k = (k + 1) % m;
            pageFault++;
        }

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

