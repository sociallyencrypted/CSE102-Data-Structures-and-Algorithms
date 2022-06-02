#include <stdio.h>
typedef long long ll;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int uncount(ll arr[], int l, int r, ll k)
{
    int counter = 0;
    for (int i = l; i <= r; i++)
    {
        if (arr[i] != k)
        {
            counter++;
        }
    }
    return counter;
}

int recur(ll arr[], int l, int r, ll k)
{
    if (l == r)
    {
        return (arr[l] == k) ? 0 : 1;
    }
    int m = (l + r) / 2;
    int res1 = uncount(arr, l, m, k);
    int res2 = uncount(arr, m + 1, r, k);
    // printf("%d %d %d\n", k, res1, res2);
    return min(res1 + recur(arr, m + 1, r, k + 1), recur(arr, l, m, k + 1) + res2);
}

int main()
{
    int n;
    ll k;
    scanf("%d %lld", &n, &k);
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    int result = recur(arr, 0, n - 1, k);
    printf("%d", result);
}