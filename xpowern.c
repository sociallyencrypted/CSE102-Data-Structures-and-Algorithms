#include <stdio.h>
#include <time.h>

long long xpowern(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return x * xpowern(x, n - 1);
}

// xpowern_f is optimised
long long xpowern_f(int x, int n)
{
    long long xpowerm;
    if (n == 0)
    {
        return 1;
    }
    if ((n % 2) == 0)
    {
        xpowerm = xpowern_f(x, n / 2);
        return xpowerm * xpowerm;
    }
    else
    {
        xpowerm = xpowern_f(x, (n - 1) / 2);
        return x * xpowerm * xpowerm;
    }
}
int main()
{
    int n;
    int x;
    double time_spent = 0.0;
    double time_spent1 = 0.0;
    printf("Enter a number:");
    scanf("%d", &x);
    printf("Enter the power it has to be raised to:");
    scanf("%d", &n);
    clock_t begin = clock();
    printf("The %d power of %d is %llu\n", n, x, xpowern(x, n));
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time in xpowern is %f seconds\n", time_spent);
    clock_t begin1 = clock();
    printf("The %d power of %d is %llu\n", n, x, xpowern_f(x, n));
    clock_t end1 = clock();
    time_spent1 += (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf("The elapsed time in xpowern_f is %f seconds\n", time_spent1);
}