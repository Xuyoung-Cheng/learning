#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    pid_t cpid;

    cpid = fork();

    if (cpid == -1)
    {
        perror("Error fork(): ");
        exit(EXIT_FAILURE);
    }
    
    if (cpid == 0) 
    {
        sleep(2);
        printf("Child A process < %d >.\n", getpid());
        exit(88);                                                               /* process A exit */
    }
    
    if (cpid > 0) 
    {
        cpid = fork();

        if (cpid == -1) 
        {
            perror("Error fork(): ");
            exit(EXIT_FAILURE);
        }
        
        if (cpid == 0)
        {
            sleep(5);
            printf("Child B process < %d >.\n", getpid());
            exit(EXIT_SUCCESS);                                                 /* process B exit */
        }
        
        if (cpid > 0)
        {
            int status = 0;

            printf("Parent process < %d >\n", getpid());
            pid_t rcpid;
            /*
            while ((rcpid = wait(&status)) != -1)
            {
                if (rcpid == -1)
                {
                    fprintf(stderr, "[ERROR]: wait()");
                    exit(EXIT_FAILURE);
                }

                printf("rcpid = %d, exit code = %d\n", rcpid, WEXITSTATUS(status));
            }
            */
            rcpid = waitpid(-1, &status, WNOHANG);                              /* WNOHANG - non block */
            while ((rcpid = waitpid(-1, &status, WNOHANG)) != -1)
            {
                if (rcpid == 0)
                    continue;

                if (rcpid == -1)
                {
                    fprintf(stderr, "[ERROR]: wait()");
                    exit(EXIT_FAILURE);
                }

                printf("rcpid = %d, exit code = %d\n", rcpid, WEXITSTATUS(status));
            }
        }
    }

    return 0;
}
