#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Another program is executing\n");
    printf("Process PID = %d\n", getpid());

    return 0;
}
