#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

int count = 0;

typedef struct Edge
{
    int src, dest;
    ll weight;
} edge;

typedef struct Graph
{
    int n;
    int m;
    edge *edges;
} graph;

graph *graphGen(int n, int m)
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->n = n;
    g->m = m;

    g->edges = (edge *)malloc(m * sizeof(edge));
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
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int comparator(const void *a, const void *b)
{
    struct Edge *a1 = (struct Edge *)a;
    struct Edge *b1 = (struct Edge *)b;
    return a1->weight > b1->weight;
}

void KruskalMST(struct Graph *graph)
{
    int n = graph->n;
    edge result[n];
    int e = 0;
    int i = 0;

    qsort(graph->edges, graph->m, sizeof(graph->edges[0]), comparator);
    subset *subsets = (subset *)malloc(n * sizeof(subset));
    for (int v = 0; v < n; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    while (e < n - 1 && i < graph->m)
    {
        edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
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
}

int main()
{
    int n1;
    int n2;
    scanf("%d %d", &n1, &n2);
    int m = (4 * n1 * n2 - 2 * n1 - 2 * n2);
    graph *g = graphGen(n1 * n2, m);
    ll arr[n1][n2];
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            scanf("%lld", &arr[i][j]);
        }
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (i == 0 && j == 0)
            {
                addEdge(g, i, j + 1, arr[i][j]);
                addEdge(g, i + 1, j, arr[i][j]);
            }
            else if (i == n1 - 1 && j == n2 - 1)
            {
                addEdge(g, i, j - 1, arr[i][j]);
                addEdge(g, i - 1, j, arr[i][j]);
            }
            else if (i == 0)
            {
                addEdge(g, i, j + 1, arr[i][j]);
                addEdge(g, i + 1, j, arr[i][j]);
                addEdge(g, i, j - 1, arr[i][j]);
            }
            else if (j == 0)
            {
                addEdge(g, i, j + 1, arr[i][j]);
                addEdge(g, i + 1, j, arr[i][j]);
                addEdge(g, i - 1, j, arr[i][j]);
            }
            else if (i == n1 - 1)
            {
                addEdge(g, i, j + 1, arr[i][j]);
                addEdge(g, i - 1, j, arr[i][j]);
                addEdge(g, i, j - 1, arr[i][j]);
            }
            else if (j == n2 - 1)
            {
                addEdge(g, i, j - 1, arr[i][j]);
                addEdge(g, i + 1, j, arr[i][j]);
                addEdge(g, i - 1, j, arr[i][j]);
            }
            else
            {
                addEdge(g, i, j + 1, arr[i][j]);
                addEdge(g, i + 1, j, arr[i][j]);
                addEdge(g, i - 1, j, arr[i][j]);
                addEdge(g, i, j - 1, arr[i][j]);
            }
        }
    }
    KruskalMST(g);
    return 0;
}