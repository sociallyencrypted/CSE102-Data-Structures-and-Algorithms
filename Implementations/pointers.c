#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n = 5;
    int m = 6;
    int **b = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        b[i] = (int *)malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b[i][j] = i + j;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("b[%d][%d] = %d \n", i, j, b[i][j]);
        }
        printf("\n");
    }
    free(b);
}
