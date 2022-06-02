#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
int n;
int m;
int recur(int arr[n][m], int a, int b, int c, int d)
{
    if (arr[a][b] != 1)
    {
        return 0;
    }
    else if (a > c && b > d){
        return  0;
    }
    else if (a == c && b == d)
    {
        return 1;
    }
    else
    {
        return recur(arr, a + 1, b, c, d) + recur(arr, a, b + 1, c, d);
    }
}

int main()
{
    int x;
    int y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    x--;
    y--;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int p = recur(arr, 0, 0, x, y) * recur(arr, x, y, n - 1, m - 1);
    printf("%d", p);
    return 0;
}
