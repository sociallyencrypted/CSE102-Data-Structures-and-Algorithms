#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct Graph
{
    int n;
    int *visited;
    int **adjMatrix;
} graph;

graph *graphGen(int n)
{
    graph *newGraph = (graph *)malloc(sizeof(graph));
    newGraph->n = n;
    newGraph->adjMatrix = malloc(n * sizeof(int *));
    newGraph->visited = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        newGraph->adjMatrix[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
        {
            newGraph->adjMatrix[i][j] = 0;
        }
        newGraph->visited[i] = 0;
    }
    return newGraph;
}

void addEdge(graph *g, int src, int dest)
{
    g->adjMatrix[src][dest] = 1;
    // Comment below for Directed Graph
    g->adjMatrix[dest][src] = 1;
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
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
    printGraph(g);
    return 0;
}