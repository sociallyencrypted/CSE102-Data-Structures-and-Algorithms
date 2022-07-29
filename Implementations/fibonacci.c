#include <stdio.h>
#include <time.h>

long long fib_n[1];
long long fib_n1[1];
long long fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// fibonacci_f is optimised
void fibonacci_f(int n, long long fib_n[1], long long fib_n1[1])
{
    if (n == 1)
    {
        fib_n[0] = 1;
        fib_n1[0] = 0;
        return;
    }
    fibonacci_f(n - 1, fib_n, fib_n1);
    long long x = fib_n[0] + fib_n1[0];
    fib_n1[0] = fib_n[0];
    fib_n[0] = x;
}

int main()
{
    // declarations
    int n;
    double time_spent = 0.0;
    double time_spent1 = 0.0;
    // input
    printf("Enter a number:");
    scanf("%d", &n);
    // factorial
    clock_t begin = clock();
    printf("The %d fibonacci number is %lld\n", n, fibonacci(n));
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time in fibonacci is %f seconds\n", time_spent);
    // factorial_f
    clock_t begin1 = clock();
    fibonacci_f(n, fib_n, fib_n1);
    printf("The %d fibonacci number is %lld\n", n, *fib_n);
    clock_t end1 = clock();
    time_spent1 += (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf("The elapsed time in fibonacci_f is %f seconds\n", time_spent1);
}