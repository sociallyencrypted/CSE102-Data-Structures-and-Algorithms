#include <stdio.h>

// find min num operations needed to maek the array k-smooth
int rec(int arr[], int k, int l, int r)
{
    if (l == r)
    {
        if (arr[l] == k)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        int m = (l + r) / 2;
        int count1 = 0;
        int count2 = 0;
        for (int i = l; i <= m; i++)
        {
            if (arr[i] != k)
            {
                count1++;
            }
        }
        for (int i = m + 1; i <= r; i++)
        {
            if (arr[i] != k)
            {
                count2++;
            }
        }
        int r1 = count2 + rec(arr, k + 1, l, m);
        int r2 = count1 + rec(arr, k + 1, m + 1, r);
        if (r1 < r2)
        {
            return r1;
        }
        else
        {
            return r2;
        }
    }
}

int main()
{
    int N, k;
    scanf("%d %d", &N, &k);
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &arr[i]);
    }
    int wheeee = rec(arr, k, 0, N - 1);
    printf("%d", wheeee);
    return 0;
}