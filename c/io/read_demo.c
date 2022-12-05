#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int fd;
    ssize_t rbytes = 0;
    char buf[64] = {0};

    if (argc != 2) {
        fprintf(stderr, "Usage: <%s> <pathname>\n", argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open() ");
        return -1;
    }

    rbytes = read(fd, buf, 10);
    if (rbytes == -1) {
        perror("read() ");
        return -1;
    }

    printf("buf = %s\n", buf);

    return 0;
}

