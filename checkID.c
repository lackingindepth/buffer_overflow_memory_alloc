#include <unistd.h>
#include <stdio.h>

int main() {
    printf("Real UID: %d\n", getuid());
    printf("Effective UID: %d\n", geteuid());
    printf("Process PID: %d\n", getpid());
    return 0;
}