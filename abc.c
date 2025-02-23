#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    // pid_t pid2 = fork();
    printf("pid : %d\n",pid);
    // printf("pid2 : %d\n",pid2);
    if (pid < 0) {
        // Fork failed
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());

        // Execute a new program
        char *args[] = {"ls", "-l", NULL};
        execvp(args[0], args);

        // If execvp returns, it must have failed
        perror("execvp");
        exit(1);
    } else {
        // Parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);

        // Wait for the child to complete
        int status;
        // waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child exited with status %d\n", WEXITSTATUS(status));
        }
        printf("Done");
    }

    return 0;
}
