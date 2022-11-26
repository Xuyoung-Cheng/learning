#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void sig_handler(int signum)
{
    printf("recv signal num = %d\n", signum);
}

int main(int argc, char const *argv[])
{
    if (signal(SIGALRM, sig_handler) == SIG_ERR)
    {
        printf("signal call is error!\n");
    }

    // alarm(5);
    struct itimerval val = {{5, 0}, {1, 0}};

    setitimer(ITIMER_REAL, &val, NULL);

    while(1);
    return 0;
}

