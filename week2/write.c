#include <fcntl.h>
#include <unistd.h>

int main(int argv, char** argc[])
{
    int fd;
    ssize_t nwrite;
    char buf[1024];

    fd = open("data", O_WRONLY);

    nwrite = write(fd, buf, 1024);

    close(fd);
}
