#include <stdio.h>
typedef long long ll;
ll arr[35], n;
ll recur(int i, int j)
{
    if (j < i || i > n || j < 0)
    {
        return 0;
    }
    if (i == j)
    {
        return arr[j];
    }
    else
    {
        ll a = arr[i] + min(recur(i + 2, j), recur(i + 1, j - 1));
        ll b = arr[j] + min(recur(i + 1, j - 1), recur(i, j - 2));

        return max(a, b);
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    ll sum;
    for (int i = 0; i < t; i++)
    {
        scanf("%lld", &arr[i]);
        sum += arr[i];
    }
    ll res = recur(0, n - 1);
    if (res > (sum / 2))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
}