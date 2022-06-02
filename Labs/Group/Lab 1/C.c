#include <stdio.h>
typedef long long ll;

ll max(ll a, ll b)
{
    return (a > b ? a : b);
}

int recur(ll arr[18], int skip, int notnull, int i, int n, ll k, ll sum)
{
    if (sum % k == 0 && notnull == 1)
    {
        return 1;
    }
    else if (i == n)
    {
        return 0;
    }
    else if (i == skip)
    {
        return recur(arr, skip, notnull, i + 1, n, k, sum);
    }
    return max(recur(arr, skip, 1, i + 1, n, k, sum + arr[i]), recur(arr, skip, notnull, i + 1, n, k, sum));
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        int n;
        ll k;
        scanf("%d %lld", &n, &k);
        ll arr[18];
        ll sum = 0;
        int res;
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &arr[j]);
            sum += arr[j];
        }
        for (int x = 0; x < n; x++)
        {
            res = recur(arr, x, 0, 0, n, k, 0LL);
            if (res == 0)
            {
                printf("NO\n");
                return 0;
            }
        }
        if (res == 0)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
}