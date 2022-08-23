#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

typedef long long ll;

typedef struct Graph
{
    int n;
    int **adjMatrix;
} graph;

graph *graphGen(int n)
{
    graph *newGraph = (graph *)malloc(sizeof(graph));
    newGraph->n = n;
    newGraph->adjMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        newGraph->adjMatrix[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            newGraph->adjMatrix[i][j] = __INT_MAX__;
        }
        newGraph->adjMatrix[i][i] = 0;
    }
    return newGraph;
}

void addEdge(graph *g, int src, int dest, ll weight)
{
    g->adjMatrix[src][dest] = weight;
    // Comment below for directed
    g->adjMatrix[dest][src] = weight;
}

int minDist(ll updDist[], int vset[], int v)
{
    int minval = __INT_MAX__;
    static int minInd = -1;
    for (int i = 0; i < v; i++)
    {
        if (vset[i] == 0 && updDist[i] < minval)
        {
            minval = updDist[i];
            minInd = i;
        }
    }
    return minInd;
}

void dijkstra(graph *g, int src)
{
    int n = g->n;
    ll updDist[n];
    int vset[n];
    for (int i = 0; i < n; i++)
    {
        updDist[i] = g->adjMatrix[src][i];
        vset[i] = 0;
    }
    updDist[src] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        int u = minDist(updDist, vset, n);
        vset[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (vset[v] == 0 && g->adjMatrix[u][v] != __INT_MAX__ && updDist[u] + g->adjMatrix[u][v] < updDist[v])
            {
                updDist[v] = updDist[u] + g->adjMatrix[u][v];
            }
        }
    }
    printf("%lld", updDist[g->n - 1]);
}

void printGraph(graph *g)
{
    for (int i = 0; i < g->n; i++)
    {
        printf("%d: ", i);
        for (int j = 0; j < g->n; j++)
        {
            if (g->adjMatrix[i][j] == 1)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main()
{
    graph *g = graphGen(5);
    addEdge(g, 0, 1, 5);
    addEdge(g, 0, 2, 10);
    addEdge(g, 1, 2, 20);
    addEdge(g, 1, 3, 30);
    addEdge(g, 2, 3, 30);
    addEdge(g, 3, 4, 10);
    dijkstra(g, 0);
    return 0;
}