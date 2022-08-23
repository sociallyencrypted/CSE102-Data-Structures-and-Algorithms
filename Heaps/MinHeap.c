#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#define MAX 400

typedef struct MaxHeap
{
    int *arr;
    int size;
    int capacity;
} heap;

heap *createMinHeap(int s)
{
    heap *h = (heap *)malloc(sizeof(heap));
    assert(h);
    h->arr = (int *)malloc((MAX + 1) * sizeof(int));
    assert(h->arr);
    h->size = s;
    h->arr[0] = INT_MAX;
    h->capacity = MAX;
    printf("Heap made!\n");
    return h;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify_at(heap *h, int i)
{
    int left = 2 * i;
    int right = 2 * i + 1;
    int smallest = i;
    int n = h->size;
    if (left <= n && h->arr[left] < h->arr[i])
    {
        smallest = left;
    }
    if (right <= n && h->arr[right] < h->arr[smallest])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(&h->arr[i], &h->arr[smallest]);
        heapify_at(h, smallest);
    }
}

void minHeapify(heap *h, int i)
{
    heapify_at(h, i);
}

void buildMinHeap(heap *h)
{
    for (int i = h->size / 2; i > 0; i--)
    {
        minHeapify(h, i);
    }
}

int heapExtractMin(heap *h)
{
    swap(&h->arr[1], &h->arr[h->size]);
    h->size--;
    minHeapify(h, 1);
    return h->arr[h->size + 1];
}

void heapSort(heap *h)
{
    for (int i = h->size; i > 0; i--)
    {
        int l = heapExtractMin(h);
        printf("%d ", l);
    }
}

void insert_at(heap *h, int idx)
{
    if (idx == 1)
    {
        return;
    }
    int parent = idx / 2;
    if (h->arr[parent] > h->arr[idx])
    {
        swap(&h->arr[parent], &h->arr[idx]);
        insert_at(h, parent);
    }
}

void insert(heap *h, int val)
{
    int n = h->size;
    h->arr[n + 1] = val;
    insert_at(h, n + 1);
    h->size++;
}

void printArr(heap *h)
{
    for (int i = 1; i <= h->size; ++i)
    {
        printf("%d ", h->arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    heap *h = createMinHeap(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h->arr[i + 1]);
    }
    buildMinHeap(h);
    heapSort(h);
    return 0;
}