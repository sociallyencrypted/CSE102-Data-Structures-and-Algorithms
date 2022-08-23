#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct Node
{
    int vertex;
    struct Node *next;
} node;

node *nodeGen(int vertex)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

typedef struct Graph
{
    int n;
    int *visited;
    node **adjList;
} graph;

graph *graphGen(int n)
{
    graph *newGraph = (graph *)malloc(sizeof(graph));
    newGraph->n = n;
    newGraph->adjList = malloc(n * sizeof(node *));
    newGraph->visited = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        newGraph->adjList[i] = NULL;
        newGraph->visited[i] = 0;
    }
    return newGraph;
}

// There are two addEdge() functions, one leads to newest edge being searched first, other leads to oldest, comment accordingly

// // Newer first
// void addEdge(graph *g, int src, int dest)
// {
//     node *newNode = nodeGen(dest);
//     newNode->next = g->adjList[src];
//     g->adjList[src] = newNode;

//     // Comment below for Directed Graph

//     newNode = nodeGen(src);
//     newNode->next = g->adjList[dest];
//     g->adjList[dest] = newNode;
// }

// Older first
void addEdge(graph *g, int src, int dest)
{
    node *newNode = nodeGen(dest);
    node *temp = g->adjList[src];

    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Comment below for Directed Graph

    newNode = nodeGen(src);
    temp = g->adjList[dest];
    if (temp == NULL)
    {
        g->adjList[dest] = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void DFS(graph *g, int vertex)
{
    node *adjNode = g->adjList[vertex];
    node *temp = adjNode;

    g->visited[vertex] = 1;
    printf("Visited: % d\n", vertex);
    while (temp != NULL)
    {
        int currVertex = temp->vertex;
        if (g->visited[currVertex] == 0)
        {
            DFS(g, currVertex);
        }
        temp = temp->next;
    }
}

void printGraph(graph *graph)
{
    for (int i = 0; i < graph->n; i++)
    {
        node *temp = graph->adjList[i];
        printf("%d", i);
        while (temp)
        {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
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
    addEdge(g, 2, 3);
    addEdge(g, 3, 0);
    DFS(g, 0);
    return 0;
}