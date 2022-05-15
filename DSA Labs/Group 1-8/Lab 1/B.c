#include <stdio.h>
int min(int a, int b)
{
    if (a > b)
    {
        return b;
    }
    return a;
}

long long tr(long long arr[20][20], int x, int y, int n, int m, int right, int down)
{
    if (right > 2 || down > 2 || x >= n || y >= m)
    {
        return 1e14;
    }
    if ((x == n - 1 && y == m - 1))
    {
        return arr[x][y];
    }
    else
    {
        return (min(tr(arr, x + 1, y, n, m, 0, down + 1), tr(arr, x, y + 1, n, m, right + 1, 0)) + arr[x][y]);
    }
}

int main()
{
    int n;
    int m;
    scanf("%d %d", &n, &m);
    long long arr[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%lld", &arr[i][j]);
        }
    }
    long long x = tr(arr, 0, 0, n, m, 0, 0);
    if (x >= (long long)1e11)
    {
        x = (long long)-1;
    }
    printf("%lld", x);
}