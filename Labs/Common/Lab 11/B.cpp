#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define INF 1e10

typedef struct Graph
{
    int n;
    ll **edges;
    ll **dist;
    int *visited;
} graph;

graph *graphGen(int n)
{
    graph *newGraph = (graph *)malloc(sizeof(graph));
    newGraph->n = n;
    newGraph->edges = (ll **)malloc(sizeof(ll *) * n);
    for (int i = 0; i < n; i++)
    {
        newGraph->edges[i] = (ll *)malloc(sizeof(ll) * n);
        for (int j = 0; j < n; j++)
        {
            newGraph->edges[i][j] = 0;
        }
    }
    newGraph->dist = (ll **)malloc(sizeof(ll *) * n);
    for (int i = 0; i < n; i++)
    {
        newGraph->dist[i] = (ll *)malloc(sizeof(ll) * 2);
        newGraph->dist[i][0] = INF; // discount not taken
        newGraph->dist[i][1] = INF; // discount taken
    }
    newGraph->visited = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        newGraph->visited[i] = 0;
    }
    return newGraph;
}

void addEdge(graph *g, int src, int dest, ll weight)
{
    g->edges[src][dest] = weight;
}

typedef struct Node
{
    int data;
    struct Node *next;
} node;

typedef struct Queue
{
    node *front;
    node *rear;
    int size;
} queue;

queue *queueGen(ll size)
{
    queue *newQueue = (queue *)malloc(sizeof(queue));
    newQueue->front = NULL;
    newQueue->rear = NULL;
    newQueue->size = size;
    return newQueue;
}

int isEmpty(queue *q)
{
    return q->front == q->rear;
}

void enqueue(queue *q, int ver)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->data = ver;
    newNode->next = NULL;
    if (q->front == NULL)
    {
        q->front = newNode;
    }
    else
    {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return NULL;
    }
    int item = q->front->data;
    node *temp = q->front;
    q->front = q->front->next;
    free(temp);
    return item;
}

void dijkstra(graph *g, int s)
{
    g->dist[s][1] = 0;
    g->dist[s][0] = 0;
    int size = g->n;
    queue *q = queueGen(size);
    for (int i = 0; i < g->n; i++)
    {
        enqueue(q, i);
    }
    while (!isEmpty(q))
    {
        int u = dequeue(q);
        g->visited[u] = 1;
        for (int i = 0; i < g->n; i++)
        {
            if (g->edges[u][i] != 0)
            {
                // case NN
                if (g->dist[u][0] + g->edges[u][i] < g->dist[i][0])
                {
                    g->dist[i][0] = g->dist[u][0] + g->edges[u][i];
                    enqueue(q, i);
                }
                // case DN
                if (g->dist[u][1] + g->edges[u][i] < g->dist[i][1])
                {
                    g->dist[i][1] = g->dist[u][1] + g->edges[u][i];
                    enqueue(q, i);
                }
                // case ND
                if (g->dist[u][0] + (ll)(g->edges[u][i] / 2) < g->dist[i][1])
                {
                    g->dist[i][1] = g->dist[u][0] + (ll)(g->edges[u][i] / 2);
                    enqueue(q, i);
                }
            }
        }
    }
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
    printf("%lld\n", g->dist[n][1]);
    return 0;
}