#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
    int pipefd[2];
    int ret;
    pid_t cpid;

    ret = pipe(pipefd);
    if (ret == -1)
    {
        perror("[Error] pipe()");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (cpid == -1)
    {
        perror("[ERROR] fork()");
        exit(EXIT_FAILURE);
    }
    else if (cpid == 0) /* Child process. */
    {
        ssize_t rbytes;
        char buffer[64] = {0};

        close(pipefd[1]); /* Close write end. */

        /* read pipe, if no data, blocked */
        for (;;)
        {
            rbytes = read(pipefd[0], buffer, sizeof(buffer));
            if (rbytes == -1)
            {
                perror("[ERROR] read()");
                close(pipefd[0]);
                exit(EXIT_FAILURE);
            }

            if (strncmp(buffer, "quit", 4) == 0)
                break;

            printf("buffer-> %s\n", buffer);
        }

        close(pipefd[0]);
    }
    else if (cpid > 0) /* Perant process. */
    {
        ssize_t wbytes;
        char buffer[64];
        char *pref = NULL;

        close(pipefd[0]); /* Close read end. */
        for (;;)
        {
            pref = fgets(buffer, sizeof(buffer), stdin);
            if (pref == NULL)
                continue;

            pref[strlen(pref) - 1] = '\0';
            wbytes = write(pipefd[1], pref, sizeof(buffer));
            if (wbytes == -1)
            {
                perror("[ERROR] write()");
                wait(NULL);
                close(pipefd[1]);
                exit(EXIT_FAILURE);
            }

            if (strncmp(pref, "quit", 4) == 0)
            {
                printf("Bye!\n");
                break;
            }
        }

        close(pipefd[1]);
        wait(NULL);
    }

    return 0;
}