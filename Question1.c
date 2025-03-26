#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main() {
    pid_t pid = fork();  // Create a new process

    if (pid < 0) {
        perror("Fork failed");
    } else if (pid == 0) {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    }
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir failed");
        return 1;
    }
    printf("Contents of current directory:\n");
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
    return 0;
}
