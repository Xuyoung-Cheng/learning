#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int fd;
    ssize_t rbytes = 0;
    ssize_t wbytes = 0;
    char buf[64] = {0};
    char wbuf[] = "ABCDE12345";

    if (argc != 2) {
        fprintf(stderr, "Usage: <%s> <pathname>\n", argv[0]);
        return -1;
    }

    fd = open(argv[1], O_RDWR|O_CREAT);
    if (fd == -1) {
        perror("open() ");
        return -1;
    }

    wbytes = write(fd, wbuf, strlen(wbuf));
    if (wbytes == -1) {
        perror("write() ");
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

