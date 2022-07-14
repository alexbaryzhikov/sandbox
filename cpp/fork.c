#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child\n");
        execlp("ps", "ps", "-ef", NULL);
    } else {
        printf("Parent %d\n", pid);
    }
    printf("Parent prints this line \n");

    wait(NULL);
    return 0;
}