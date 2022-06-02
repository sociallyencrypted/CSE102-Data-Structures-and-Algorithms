// pr0hum and The Weekend
// Happy Weekend folks

#include <stdio.h>

void merge(int arr[][2], int lf, int md, int rt)
{
    int a1 = md - lf + 1;
    int a2 = rt - md;

    int leftarr[a1][2];
    int rightarr[a2][2];

    for (int i = 0; i < a1; i++)
    {
        leftarr[i][0] = arr[lf + i][0];
        leftarr[i][1] = arr[lf + i][1];
    }

    for (int j = 0; j < a2; j++)
    {
        rightarr[j][0] = arr[md + 1 + j][0];
        rightarr[j][1] = arr[md + 1 + j][1];
    }

    int p = 0;
    int q = 0;
    int r = lf;

    while (p < a1 && q < a2)
    {
        if (leftarr[p][0] <= rightarr[q][0])
        {
            arr[r][0] = leftarr[p][0];
            arr[r][1] = leftarr[p][1];
            p++;
        }
        else
        {
            arr[r][0] = rightarr[q][0];
            arr[r][1] = rightarr[q][1];
            q++;
        }
        r++;
    }

    while (p < a1)
    {
        arr[r][0] = leftarr[p][0];
        arr[r][1] = leftarr[p][1];
        p++;
        r++;
    }
    while (q < a2)
    {
        arr[r][0] = rightarr[q][0];
        arr[r][1] = rightarr[q][1];
        q++;
        r++;
    }
}

void mergesort(int arr[][2], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int arr[m][2];
    for (int x = 0; x < m; x++)
    {
        scanf("%d %d", &arr[x][0], &arr[x][1]);
    }
    mergesort(arr, 0, m - 1);
    int i_old = 1;
    int i_new = 1;
    for (int r = 0; r < m; r++)
    {
        i_new = arr[r][0];
        if (i_new == i_old)
        {
            printf("%d ", arr[r][1]);
        }
        else if (i_new - i_old == 1)
        {
            i_old = i_new;
            printf("\n%d ", arr[r][1]);
        }
        else
        {
            for (int z = 1; z < (i_new - i_old); z++)
            {
                printf("\n-1");
            }
            printf("\n%d ", arr[r][1]);
            i_old = i_new;
        }
    }
    if (i_new < n)
    {
        for (int y = 0; y < (n - i_new); y++)
        {
            printf("\n-1");
        }
    }
}