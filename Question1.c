#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // for fork(), getpid()
#include <dirent.h>     // for opendir(), readdir()
#include <sys/types.h>  // for DIR, struct dirent

int main() {
    pid_t pid;

    pid = fork();  // Create a new process

    if (pid < 0) {
        printf("fork failed");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process:\n");
        printf("Child PID: %d\n", getpid());

        DIR *d;
        struct dirent *dir;

        d = opendir(".");  // Open current directory

        if (d) {
            printf("Files in current directory:\n");
            while ((dir = readdir(d)) != NULL) {
                printf("%s\n", dir->d_name);
            }
            closedir(d);
        } else {
            printf("opendir failed");
        }
    }
    else {
        // Parent process
        printf("Parent Process:\n");
        printf("Parent PID: %d\n", getpid());
    }

    return 0;
}
