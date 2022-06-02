#include <stdio.h>
typedef long long ll;

int main()
{
    ll n;
    ll dp[20];
    scanf("%lld", &n);
    for (ll i = 0; i < 5; i++)
    {
        dp[i] = 0;
    }
    dp[5] = 1;
    for (ll i = 6; i < n + 1; i++)
    {
        if (i % 2)
        {
            dp[i] = i + dp[i - 1] + dp[i - 3] + dp[i - 5];
        }
        else
        {
            dp[i] = (i / 2) + dp[i - 2] + dp[i - 4];
        }
    }
    printf("%lld", dp[n]);
}