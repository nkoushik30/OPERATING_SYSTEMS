#include <stdio.h>
#include <string.h>  // Include this for strcmp()

struct fileTable 
{
    char name[20];
    int nob, blocks[30];
} ft[30];

int main() 
{
    int i, j, n;
    char s[20];
    
    printf("Enter no of files :");
    scanf("%d", &n);

    for(i = 0; i < n; i++) 
    {
        printf("\nEnter file name %d: ", i+1);
        scanf("%s", ft[i].name);
        
        printf("Enter no of blocks in file %d: ", i+1);
        scanf("%d", &ft[i].nob);
        
        printf("Enter the blocks of the file: ");
        for(j = 0; j < ft[i].nob; j++)
            scanf("%d", &ft[i].blocks[j]);
    }

    printf("\nEnter the file name to be searched: ");
    scanf("%s", s);

    for(i = 0; i < n; i++) 
    {
        if(strcmp(s, ft[i].name) == 0)
            break;
    }

    if(i == n) //-
        printf("\nFile Not Found\n");
    else 
    {
        printf("\nFILE NAME \n");
        printf("%s", ft[i].name);
        printf("\nNumber of blocks\n");
        printf("%d", ft[i].nob);
        printf("\nallocated blocks\n");
        for(j = 0; j < ft[i].nob; j++) 
            printf("%d, ", ft[i].blocks[j]);

        printf("\n");
    }

    return 0;
}
