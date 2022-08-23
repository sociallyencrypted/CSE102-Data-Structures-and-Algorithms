#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;

int count = 0;

typedef struct Edge
{
    int src;
    int dest;
    ll weight;
} edge;

typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct Graph
{
    int n;
    int m;
    edge *edges;
    node **adjList;
    int *visited;
} graph;

graph *graphGen(int n, int m)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->n = n;
    g->m = m;

    g->edges = (edge *)malloc(m * sizeof(edge));
    g->adjList = (node **)malloc(n * sizeof(node *));
    for (int i = 0; i < n; i++)
    {
        g->adjList[i] = (node *)malloc(sizeof(node));
        g->adjList[i]->data = i;
        g->adjList[i]->next = NULL;
    }
    g->visited = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        g->visited[i] = 0;
    }
    return g;
}

typedef struct Subset
{
    int parent;
    int rank;
} subset;

int find(subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }

    return subsets[i].parent;
}

void Union(subset subsets[], int x, int y)
{
    int xpar = find(subsets, x);
    int ypar = find(subsets, y);
    if (subsets[xpar].rank < subsets[ypar].rank)
    {
        subsets[xpar].parent = ypar;
        subsets[ypar].rank++;
    }
    if (subsets[xpar].rank > subsets[ypar].rank)
    {
        subsets[ypar].parent = xpar;
        subsets[xpar].rank++;
    }
    else
    {
        subsets[xpar].parent = ypar;
        subsets[ypar].rank++;
    }
}

int comparator(const void *a, const void *b)
{
    edge *a1 = (edge *)a;
    edge *b1 = (edge *)b;
    return a1->weight < b1->weight;
}

void merge(edge arr[], int lf, int md, int rt)
{
    int a1 = md - lf + 1;
    int a2 = rt - md;

    edge leftarr[a1];
    edge rightarr[a2];

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
        if (comparator(&leftarr[p], &rightarr[q]))
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

void MergeSort(edge edges[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        MergeSort(edges, l, m);
        MergeSort(edges, m + 1, r);
        merge(edges, l, m, r);
    }
}

void KruskalMST(graph *g)
{
    int n = g->n;
    edge result[n];
    MergeSort(g->edges, 0, g->m);
    // mergesort(g->edges, g->m, sizeof(edge), comparator);

    subset *subsets = (subset *)malloc(n * sizeof(subset));
    for (int v = 0; v < n; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    int e = 0;
    int i = 0;
    while (e < n - 1 && i < g->m)
    {
        edge ce = g->edges[i++];

        int a = find(subsets, ce.src);
        int b = find(subsets, ce.dest);
        if (a != b)
        {
            result[e++] = ce;
            Union(subsets, a, b);
        }
    }
    // print the MST
    // printf("%d", e);
    // for (int i = 0; i < e; i++)
    // {
    //     printf("%d %d\n", result[i].src, result[i].dest);
    // }
    ll sum = 0;
    for (i = 0; i < e; ++i)
    {
        sum += result[i].weight;
    }
    printf("%lld\n", sum);
    return;
}

void addEdge(graph *g, int src, int dest, ll weight)
{
    g->edges[count].src = src;
    g->edges[count].dest = dest;
    g->edges[count].weight = weight;
    count++;
    node *temp = g->adjList[src];
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = dest;
    newNode->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    temp = g->adjList[dest];
    node *newNode2 = (node *)malloc(sizeof(node));
    newNode2->data = src;
    newNode2->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode2;
}

void DFS(graph *g, int src)
{
    g->visited[src] = 1;
    node *temp = g->adjList[src];
    while (temp != NULL)
    {
        if (g->visited[temp->data] == 0)
        {
            DFS(g, temp->data);
        }
        temp = temp->next;
    }
}

int main()
{
    int n;
    int m;
    scanf("%d %d", &n, &m);
    n++; // if vertices are from 1 to n
    graph *g = graphGen(n, m);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        ll w;
        scanf("%d %d %lld", &a, &b, &w);
        addEdge(g, a, b, w);
    }

    DFS(g, 1);
    for (int i = 1; i < n; ++i)
    {
        if (g->visited[i] == 0)
        {
            printf("IMPOSSIBLE");
            return 0;
        }
    }
    KruskalMST(g);
    return 0;
}