#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid < 0)
    {
        printf("Fork failed\n");
    }
    else if(pid == 0)
    {
        printf("Child Process\n");
        printf("Child PID = %d\n", getpid());

        execl("./another", "another", NULL);

        printf("execl failed\n");
    }
    else
    {
        wait(NULL);

        printf("Child process terminated\n");
        printf("Terminated Child PID = %d\n", pid);
    }

    return 0;
}
