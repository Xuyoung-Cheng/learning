#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>


int main(int argc, char const *argv[])
{
    pid_t cpid;

    write(1, "Hello", 5);
    fputs("Hello", stdout);
    cpid = fork();

    if (cpid == -1) {
        perror("Error fork(): ");
    }

    /* 
    printf("pid: %d\n", getpid());
    printf("Hello world\n");
    */
    
    return 0;
}
