#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int ret;

    /* ret = execl("/bin/ls", "ls", "-l", NULL); */
    
    char *const argv[] = {"ls", "-l", NULL};
    ret = execv("/bin/ls", argv);

    if (ret == -1)
    {
        perror("Error execl():");
        exit(EXIT_FAILURE);
    }

    return 0;
}