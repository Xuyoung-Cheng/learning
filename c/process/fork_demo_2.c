#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int global = 0;

int main(int argc, char const *argv[])
{
    pid_t cpid;
    cpid = fork();

    if (cpid == -1) {
        perror("Error fork(): ");
    } else if (cpid == 0) {
        global = 100;
        printf("pid: %d - global = %d\n", getpid() ,global);
    } else {
        printf("pid: %d - global = %d\n", getpid() ,global);
    }

    printf("pid: %d - global = %d\n", getpid() ,global);

    return 0;
}
