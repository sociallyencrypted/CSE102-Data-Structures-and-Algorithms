#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        arr[i] = (arr[i / 2]) + (2 * arr[(2 * i) / 3]) + (3 * arr[(3 * i) / 4]);
    }
    printf("%lld", arr[n]);
}
