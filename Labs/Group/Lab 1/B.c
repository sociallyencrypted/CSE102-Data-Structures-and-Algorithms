#include <stdio.h>
typedef long long ll;

int max(int a, int b)
{
    return (a > b ? a : b);
}
int flag = 0;
int recur(ll arr[20], int i, int num, int n, int k, int x, int sum)
{
    if (flag == 1)
    {
        return 1;
    }
    if (sum == x && num == k)
    {
        return 1;
        flag = 1;
    }
    else if (num == k || i == n)
    {
        return 0;
    }
    return max(max(recur(arr, i + 1, num + 1, n, k, x, sum + arr[i]), recur(arr, i + 1, num + 1, n, k, x, sum - arr[i])), recur(arr, i + 1, num, n, k, x, sum));
}
int main()
{
    int n;
    int k;
    int x;
    scanf("%d %d %d", &n, &k, &x);
    ll arr[20];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int res = recur(arr, 0, 0, n, k, x, 0);
    if (res == 1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }
}
