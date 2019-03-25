#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void Export(int gpio)
{
        int fd;
        char buf[1000];
        fd = open("/sys/class/gpio/export", O_WRONLY);
        sprintf(buf, "%d", gpio);
        write(fd, buf, strlen(buf));
        close(fd);
}

void UnExport(int gpio)
{
        int fd;
        char buf[1000];
        fd = open("/sys/class/gpio/unexport", O_WRONLY);
        sprintf(buf, "%d", gpio);
        write(fd, buf, strlen(buf));
        close(fd);
}

void Direction_Out(int gpio)
{
        int fd;
        char buf[1000];
        sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);
        fd = open(buf, O_WRONLY);
        write(fd, "out", 3);
        close(fd);
}

void Value_1(int gpio)
{
        int fd;
        char buf[1000];
        sprintf(buf, "/sys/class/gpio/gpio%d/value",gpio);
        fd = open(buf, O_WRONLY);
        write(fd, "1",1);
        close(fd);
}

void Value_0(int gpio)
{
        int fd;
        char buf[1000];
        sprintf(buf, "/sys/class/gpio/gpio%d/value",gpio);
        fd = open(buf, O_WRONLY);
        write(fd, "0",1);
        close(fd);
}

int main(int argc, char**argv)

{
        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[2]);
        int gpio = num1;
        int tmp = num2;

        Export(gpio);
        Direction_Out(gpio);

        if(tmp == 0)
        {
                Value_0(gpio);
        }
        if(tmp == 1)
        {
                Value_1(gpio);
        }
        if(tmp == 3)
        {
                UnExport(gpio);
        }
}
