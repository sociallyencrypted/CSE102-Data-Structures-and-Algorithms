#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

int recur(int arr[][3], int i, int n, char flag)
{
    if (i == n)
    {
        return 0;
    }
    else
    {
        int a = arr[i][0];
        int b = arr[i][1];
        int c = arr[i][2];
        if (flag == 'a')
        {
            return max(b + recur(arr, i + 1, n, 'b'), c + recur(arr, i + 1, n, 'c'));
        }
        if (flag == 'b')
        {
            return max(a + recur(arr, i + 1, n, 'a'), c + recur(arr, i + 1, n, 'c'));
        }
        if (flag == 'c')
        {
            return max(b + recur(arr, i + 1, n, 'b'), a + recur(arr, i + 1, n, 'a'));
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int m = max(max(recur(arr, 0, n, 'a'), recur(arr, 0, n, 'b')), recur(arr, 0, n, 'c'));
    printf("%d", m);
    return 0;
}
