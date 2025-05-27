#include <stdio.h>
#include <unistd.h>

int main() {
//     fork();   // 1st fork
//     fork();   // 2nd fork
//     printf("Hello from process %d\n", getpid());
    pid_t pid = fork();

    if (pid == 0) {
        // This block is run **only by the child**
        printf("Child process: pid = %d\n", getpid());
    } else if (pid > 0) {
        // This block is run **only by the parent**
        printf("Parent process: child pid = %d\n", pid);
    }

        return 0;
}
