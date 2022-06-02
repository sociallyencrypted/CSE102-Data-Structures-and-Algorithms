void merge(int arr[], int lf, int md, int rt)
{
    int a1 = md - lf + 1;
    int a2 = rt - md;

    int leftarr[a1];
    int rightarr[a2];

    for (int i = 0; i < a1; i++)
    {
        leftarr[i] = arr[lf + i];
    }

    for (int j = 0; j < a2; j++)
    {
        rightarr[j] = arr[md + 1 + j];
    }

    int p = 0;
    int q = 0;
    int r = lf;

    while (p < a1 && q < a2)
    {
        if (leftarr[p] <= rightarr[q])
        {
            arr[r] = leftarr[p];
            p++;
        }
        else
        {
            arr[r] = rightarr[q];
            q++;
        }
        r++;
    }

    while (p < a1)
    {
        arr[r] = leftarr[p];
        p++;
        r++;
    }
    while (q < a2)
    {
        arr[r] = rightarr[q];
        q++;
        r++;
    }
}

void mergesort(int arr[], int left, int right)
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
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, n - 1);
}