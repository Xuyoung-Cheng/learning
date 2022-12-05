#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int fd_src;
    int fd_dst;
    ssize_t rbytes = 0;
    ssize_t wbytes = 0;
    char buf[64] = {0};

    if (argc != 3) {
        fprintf(stderr, "Usage: <%s> <src> <dst>\n", argv[0]);
        return -1;
    }

    fd_src = open(argv[1], O_RDONLY);
    if (fd_src == -1) {
        perror("open() ");
        return -1;
    }

    fd_dst = open(argv[2], O_CREAT|O_WRONLY|O_TRUNC, 0644);
    if (fd_dst == -1) {
        perror("open() ");
        return -1;
    }

    rbytes = read(fd_src, buf, 64);
    while (rbytes != 0) {
        if (rbytes == -1) {
            perror("read() ");
            return -1;
        }

        wbytes = write(fd_dst, buf, strlen(buf));
        if (wbytes == -1) {
            perror("write() ");
            return -1;
        }

        memset(buf, 0, sizeof(buf));
        rbytes = read(fd_src, buf, 64);
    }

    close(fd_src);
    close(fd_dst);

    return 0;
}
