#include <fcntl.h>
#include <unistd.h>

int main(int argv, char** agrc[])
{
    int fd;
    ssize_t nread;
    char buf[1024];

    fd = open("data", O_RDONLY);

    nread = read(fd, buf, 1024);

    close(fd);
}
