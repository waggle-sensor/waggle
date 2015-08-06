// Produces a 25 Hz square wave on the GPIO pin

#include <stdio.h>
#include <string.h>
#include <unistd.h>
FILE *zero, *one;

int main(int argc, char *argv[]) {
    zero = fopen("/sys/class/gpio/gpio204/value", "w");
    one = fopen("/sys/class/gpio/gpio204/value", "w");
    while(1) {
        fputs("0\n", zero);
        fflush(zero);
        usleep(20*1000);
        fputs("1\n", one);
        fflush(one);
        usleep(20*1000);
    }
}