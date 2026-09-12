#include <stdio.h>
void main()
{
    int a[2][2], b[2][2], c[2][2];
    printf("=====================================Matrix-A==================================================\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter Element of index [%d][%d]: ", (i + 1), (j + 1));
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n=====================================Matrix-B==================================================\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Enter Element of index [%d][%d]: ", (i + 1), (j + 1));
            scanf("%d", &b[i][j]);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("\n\n=====================================Matrix-C==================================================\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}