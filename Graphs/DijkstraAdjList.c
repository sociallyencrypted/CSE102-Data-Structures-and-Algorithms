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
    ll updDist[n];
    int vset[n];
    for (int i = 0; i < n; i++)
    {
        updDist[i] = __INT_MAX__;
        vset[i] = 0;
    }
    node *temp = g->adjList[src];
    while (temp != NULL)
    {
        updDist[temp->vertex] = temp->weight;
        temp = temp->next;
    }
    updDist[src] = 0;
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
                    if (updDist[u] + a < updDist[v])
                    {
                        updDist[v] = updDist[u] + a;
                    }
                }
            }
        }
    }
    printf("%lld", updDist[g->n - 1]);
}

// void printGraph(graph *g)
// {
//     for (int i = 0; i < g->n; i++)
//     {
//         printf("%d: ", i);
//         for (int j = 0; j < g->n; j++)
//         {
//             if (g->adjMatrix[i][j] == 1)
//             {
//                 printf("%d ", j);
//             }
//         }
//         printf("\n");
//     }
// }

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