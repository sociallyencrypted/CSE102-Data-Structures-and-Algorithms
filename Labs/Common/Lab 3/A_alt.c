// pr0hum and The Weekend
// Happy Weekend folks

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int **arr = malloc(n * sizeof(int *));
    int count[n];
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
        arr[i] = malloc(3 * sizeof(int));
    }
    for (int x = 0; x < m; x++)
    {
        int u;
        int v;
        scanf("%d %d", &u, &v);
        u--;
        if (count[u] != 0)
        {
            realloc(arr[u], (count[u] + 1) * sizeof(int));
        }
        arr[u][count[u]] = v;
        count[u]++;
    }
    for (int y = 0; y < n; y++)
    {
        if (count[y] == 0)
        {
            printf("-1\n");
        }
        else
        {
            for (int z = 0; z < count[y]; z++)
            {
                printf("%d ", arr[y][z]);
            }
            printf("\n");
        }
    }
}