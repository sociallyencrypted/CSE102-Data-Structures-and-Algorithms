#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

#define INF 1e10

typedef struct Graph
{
    int n;
    ll **edges;
    ll *dist;
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
    newGraph->dist = (ll *)malloc(sizeof(ll) * n);
    for (int i = 0; i < n; i++)
    {
        newGraph->dist[i] = INF;
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

typedef struct Queue
{
    int *arr;
    ll front;
    ll rear;
    ll size;
} queue;

queue *queueGen(ll size)
{
    queue *newQueue = (queue *)malloc(sizeof(queue));
    newQueue->arr = (int *)malloc(size * sizeof(int));
    newQueue->front = 0;
    newQueue->rear = 0;
    newQueue->size = size;
    return newQueue
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

void dijkstra(graph *g, int s)
{
    g->dist[s] = 0;
    int size = g->n;
    size = size * 3;
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
                if (g->dist[i] > g->dist[u] + g->edges[u][i])
                {
                    g->dist[i] = g->dist[u] + g->edges[u][i];
                    if (g->visited[i])
                    {
                        enqueue(q, i);
                    }
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
    printf("%lld\n", g->dist[n]);
    return 0;
}