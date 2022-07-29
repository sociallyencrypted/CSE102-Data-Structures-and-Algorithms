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

typedef struct Queue
{
    int *arr;
    int front;
    int rear;
    int size;
} queue;

queue *queueGen(int n)
{
    queue *newQueue = malloc(sizeof(queue));
    newQueue->arr = malloc(n * sizeof(int));
    newQueue->front = 0;
    newQueue->rear = 0;
    newQueue->size = n;
}

int isEmpty(queue *q)
{
    return q->front == q->rear;
}

void enqueue(queue *q, int ver)
{
    if (q->rear == q->size)
    {
        printf("Queue is full\n");
        return;
    }
    q->arr[q->rear] = ver;
    q->rear++;
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return NULL;
    }
    int item = q->arr[q->front];
    q->front++;
    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }
    return item;
}

void BFS(graph *g, int vertex)
{
    queue *bfsQueue = queueGen(g->n);
    g->visited[vertex] = 1;
    enqueue(bfsQueue, vertex);
    while (!isEmpty(bfsQueue))
    {
        vertex = dequeue(bfsQueue);
        printf("Visited: %d\n", vertex);
        node *temp = g->adjList[vertex];
        while (temp)
        {
            int adj = temp->vertex;
            if (g->visited[adj] == 0)
            {
                g->visited[adj] = 1;
                enqueue(bfsQueue, adj);
            }
            temp = temp->next;
        }
    }
}

int main()
{
    graph *g = graphGen(5);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 4);
    addEdge(g, 1, 3);
    addEdge(g, 2, 1);
    addEdge(g, 3, 4);
    printGraph(g);
    BFS(g, 0);
    return 0;
}