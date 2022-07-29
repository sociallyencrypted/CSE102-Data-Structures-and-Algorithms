#include <stdio.h>
#include <time.h>

int lsearch(int arr[], int val, int len)
{
    int i;
    for (i = len - 1; i > 0; i--)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}

int lsearch_r(int arr[], int val, int len)
{
    if (len == 0)
    {
        return -1;
    }
    if (arr[len - 1] == val)
    {
        return len - 1;
    }
    else
    {
        return lsearch_r(arr, val, len - 1);
    }
    return -1;
}

int main()
{
    // declarations
    int n;
    int len = 5;
    int arr[5] = {1, 2, 3, 4, 5};
    double time_spent = 0.0;
    double time_spent1 = 0.0;
    // input
    printf("Enter a number:");
    scanf("%d", &n);
    // factorial
    clock_t begin = clock();
    printf("Number found at array position %d\n", lsearch(arr, n, len));
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time in lsearch is %f seconds\n", time_spent);
    // factorial_f
    clock_t begin1 = clock();
    printf("Number found at array position %d\n", lsearch_r(arr, n, len));
    clock_t end1 = clock();
    time_spent1 += (double)(end1 - begin1) / CLOCKS_PER_SEC;
    printf("The elapsed time in lsearch_r is %f seconds\n", time_spent1);
}