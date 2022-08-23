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

heap *createMaxHeap(int s)
{
    heap *h = (heap *)malloc(sizeof(heap));
    assert(h);
    h->arr = (int *)malloc((MAX + 1) * sizeof(int));
    assert(h->arr);
    h->size = s;
    h->arr[0] = INT_MIN;
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
    int largest = i;
    int n = h->size;
    if (left <= n && h->arr[left] > h->arr[i])
    {
        largest = left;
    }
    if (right <= n && h->arr[right] > h->arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(&h->arr[i], &h->arr[largest]);
        heapify_at(h, largest);
    }
}

void maxHeapify(heap *h, int i)
{
    heapify_at(h, i);
}

void buildMaxHeap(heap *h)
{
    for (int i = h->size / 2; i > 0; i--)
    {
        maxHeapify(h, i);
    }
}

int heapExtractMax(heap *h)
{
    swap(&h->arr[1], &h->arr[h->size]);
    h->size--;
    maxHeapify(h, 1);
    return h->arr[h->size + 1];
}

void heapSort(heap *h)
{
    for (int i = h->size; i > 0; i--)
    {
        int l = heapExtractMax(h);
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
    if (h->arr[parent] < h->arr[idx])
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

void increaseKey(int i, int val, heap *h)
{
    if (h->arr[i] > val)
    {
        return;
    }
    h->arr[i] = val;
    int parent = i / 2;
    while (parent > 0 && h->arr[parent] < h->arr[i])
    {
        swap(&h->arr[parent], &h->arr[i]);
        i = parent;
        parent = i / 2;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    heap *h = createMaxHeap(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &h->arr[i + 1]);
    }
    printArr(h);
    increaseKey(2, 100, h);
    printArr(h);
    return 0;
}