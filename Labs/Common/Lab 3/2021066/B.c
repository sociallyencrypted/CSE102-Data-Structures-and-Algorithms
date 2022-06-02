#include <stdio.h>
typedef long long ll;

ll min(ll a, ll b)
{
    return (a < b) ? a : b;
}

void merge(ll arr[], int lf, int md, int rt)
{
    int a1 = md - lf + 1;
    int a2 = rt - md;

    ll leftarr[a1];
    ll rightarr[a2];

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

void mergesort(ll arr[], int left, int right)
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        ll h;
        ll k;
        scanf("%d %lld", &n, &h);
        ll arr[n];
        ll pref[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
            if (i >= 1)
            {
                pref[i - 1] = arr[i] - arr[i - 1];
            }
        }
        mergesort(arr, 0, n - 1);
        ll ini = 1;
        ll fin = h;
        while (ini < fin + 1)
        {
            ll damage = 0;
            k = (ini + fin) / 2;
            for (ll i = 0; i < n - 1; i++)
            {
                damage += min(pref[i], k);
            }
            damage += k;
            ini = (damage < h) ? k + 1 : ini;
            fin = (damage >= h) ? k - 1 : fin;
        }
        k = fin + 1;
        printf("%lld\n", k);
    }
}