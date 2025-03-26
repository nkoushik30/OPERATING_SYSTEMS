#include <stdio.h>
#include <string.h>

struct fileTable {
    char name[20];
    int nob, blocks[30];
} ft[30];

int main() {
    int i, j, n;
    char s[20];

    printf("\nEnter the number of files:\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter file name:\n");
        scanf("%s", ft[i].name);

        printf("\nEnter the number of blocks of the file:\n");
        scanf("%d", &ft[i].nob);

        printf("\nEnter the blocks of files:\n");
        for (j = 0; j < ft[i].nob; j++) {
            scanf("%d", &ft[i].blocks[j]);
        }
    }

    printf("\nEnter the file name to search: \n");
    scanf("%s", s);

    for (i = 0; i < n; i++) {
        if (strcmp(s, ft[i].name) == 0) {
            break;
        }
    }

    if (i == n) {
        printf("\nFile not found\n");
    } else {
        printf("\nFile Name: %s", ft[i].name);
        printf("\nNumber of blocks: %d", ft[i].nob);
        printf("\nAllocated blocks:\n");
        for (j = 0; j < ft[i].nob; j++) {
            printf("%d\n", ft[i].blocks[j]);
        }
    }

    return 0;
}
