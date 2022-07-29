#include <stdio.h>

long long factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    int n;
    printf("Enter a number:");
    scanf("%d", &n);
    printf("The factorial of %d is %llu", n, factorial(n));
}