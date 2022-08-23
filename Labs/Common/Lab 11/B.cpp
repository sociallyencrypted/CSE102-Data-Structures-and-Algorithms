#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>

typedef long long ll;

typedef struct Node
{
    int vertex;
    ll weight;
    struct Node *next;
} node;

node *nodeGen(int vertex, ll weight)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    newNode->weight = weight;
    return newNode;
}

typedef struct Graph
{
    int n;
    node **adjList;
} graph;

graph *graphGen(int n)
{
    graph *newGraph = (graph *)malloc(sizeof(graph));
    newGraph->n = n;
    newGraph->adjList = (node **)malloc(n * sizeof(node *));
    for (int i = 0; i < n; i++)
    {
        newGraph->adjList[i] = NULL;
    }
    return newGraph;
}

void addEdge(graph *g, int src, int dest, ll weight)
{
    node *newNode = nodeGen(dest, weight);
    node *temp = g->adjList[src];
    if (temp == NULL)
    {
        g->adjList[src] = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Comment below for Directed Graph

    // newNode = nodeGen(src);
    // temp = g->adjList[dest];
    // if (temp == NULL)
    // {
    //     g->adjList[dest] = newNode;
    // }
    // else
    // {
    //     while (temp->next != NULL)
    //     {
    //         temp = temp->next;
    //     }
    //     temp->next = newNode;
    // }
}

int minDist(ll updDist[][2], int vset[], int v)
{
    int minval = __INT_MAX__;
    static int minInd = -1;
    for (int i = 0; i < v; i++)
    {
        if (vset[i] == 0 && updDist[i][1] < minval)
        {
            minval = updDist[i][1];
            minInd = i;
        }
    }
    return minInd;
}

ll connected(graph *g, int u, int v)
{
    node *temp = g->adjList[u];
    while (temp)
    {
        if (temp->vertex == v)
            return temp->weight;
        temp = temp->next;
    }
    return 0;
}

void dijkstra(graph *g, int src)
{
    int n = g->n;
    ll updDist[n][2];
    int vset[n];
    for (int i = 0; i < n; i++)
    {
        updDist[i][0] = INT_MAX;
        updDist[i][1] = INT_MAX;
        vset[i] = 0;
    }
    node *temp = g->adjList[src];
    while (temp != NULL)
    {
        updDist[temp->vertex][0] = temp->weight;
        updDist[temp->vertex][1] = (ll)(temp->weight / 2);
        temp = temp->next;
    }
    updDist[src][0] = 0;
    updDist[src][1] = 0;
    for (int count = 0; count < n - 1; count++)
    {
        int u = minDist(updDist, vset, n);
        vset[u] = 1;
        for (int v = 0; v < n; v++)
        {
            if (vset[v] == 0)
            {
                ll a = connected(g, u, v);
                if (a != 0)
                {
                    if (updDist[u][0] + a < updDist[v][0])
                    {
                        updDist[v][0] = updDist[u][0] + a;
                    }
                    if (updDist[u][1] + a < updDist[v][1])
                    {
                        updDist[v][1] = updDist[u][1] + a;
                    }
                    if (updDist[u][0] + (ll)(a / 2) < updDist[v][1])
                    {
                        updDist[v][1] = updDist[u][0] + (ll)(a / 2);
                    }
                }
            }
        }
    }
    printf("%lld", updDist[g->n - 1][1]);
}

int main()
{
    int n;
    int m;
    scanf("%d %d", &n, &m);
    graph *g = graphGen(n + 1);
    for (int i = 0; i < m; i++)
    {
        int src, dest;
        ll weight;
        scanf("%d %d %lld", &src, &dest, &weight);
        addEdge(g, src, dest, weight);
    }
    dijkstra(g, 1);
    return 0;
}