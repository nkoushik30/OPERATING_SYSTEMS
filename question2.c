#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024

void simulate_cp(const char *src, const char *dest) {
    FILE *fsrc = fopen(src, "r"), *fdest = fopen(dest, "w");
    if (!fsrc || !fdest) {
        perror("File error");
        if (fsrc) fclose(fsrc);
        return;
    }
    char ch;
    while ((ch = fgetc(fsrc)) != EOF) fputc(ch, fdest);
    printf("Copied from %s to %s\n", src, dest);
    fclose(fsrc); fclose(fdest);
}

void simulate_grep(const char *keyword, const char *file) {
    FILE *f = fopen(file, "r");
    if (!f) { perror("File error"); return; }
    char line[MAX_LINE];
    while (fgets(line, MAX_LINE, f)) if (strstr(line, keyword)) printf("%s", line);
    fclose(f);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage:\n  %s cp <src> <dest>\n  %s grep <word> <file>\n", argv[0], argv[0]);
        return 1;
    }

    if (!strcmp(argv[1], "cp")) simulate_cp(argv[2], argv[3]);
    else if (!strcmp(argv[1], "grep")) simulate_grep(argv[2], argv[3]);
    else printf("Invalid command. Use 'cp' or 'grep'.\n");

    return 0;
}
