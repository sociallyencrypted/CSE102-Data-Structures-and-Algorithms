#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef long long ll;

typedef struct Queue
{
    ll capacity;
    ;
    ll array[100000];
    ll front;
    ll rear;
} queue;

typedef struct realNode
{
    ll data;
    char color;
} node;

typedef struct AdjNode
{
    node *data;
    struct AdjNode *next;
} adjNode;

// ------------DIRECTED GRAPH-----------------

node *createNode(ll val)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = val;
    new->color = 'g';
    return new;
}

adjNode *createAdjNode(node *x)
{
    adjNode *new = (adjNode *)malloc(sizeof(adjNode));
    new->data = x;
    new->next = NULL;
    return new;
}

void appendNode(adjNode *root, adjNode *toAppend)
{
    adjNode *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = toAppend;
}

void enqueue(queue *q, ll x)
{
    if (q->rear == q->capacity)
    {
        printf("Queue is full\n");
        return;
    }
    q->array[q->rear] = x;
    q->rear++;
}

ll dequeue(queue *q)
{
    if (q->front == q->rear)
    {
        printf("Queue is empty\n");
        return NULL;
    }
    ll x = q->array[q->front];
    q->front++;
    return x;
}

int isEmpty(queue *q)
{
    if (q->front == q->rear)
    {
        return 1;
    }
    return 0;
}

void BFS(ll val, adjNode **adjacencyList, ll n)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->capacity = n;
    q->front = 0;
    q->rear = 0;
    adjNode *temp = adjacencyList[val];
    enqueue(q, val);
    temp->data->color = 'b';
    while (!isEmpty(q))
    {
        ll x = dequeue(q);
        printf("Visited %lld ", x);
        temp = adjacencyList[x];
        while (temp != NULL)
        {
            if (temp->data->color == 'g')
            {
                temp->data->color = 'b';
                enqueue(q, temp->data->data);
            }
            temp = temp->next;
        }
    }
}

void DFS(ll val, adjNode **adjacencyList)
{
    adjNode *temp = adjacencyList[val];
    while (temp != NULL)
    {
        if (temp->data->color == 'g')
        {
            temp->data->color = 'b';
            printf("Visited %lld\n", temp->data->data);
            DFS(temp->data->data, adjacencyList);
        }
        temp = temp->next;
    }
}

// ------------UNDIRECTED GRAPH-----------------

int main()
{
    ll n;
    ll e;
    scanf("%lld %lld", &n, &e);
    node **nodeList = (node **)malloc(sizeof(node) * n);
    adjNode **adjacencyList = (adjNode **)malloc(sizeof(adjNode *) * n);
    for (ll i = 0; i < n; i++)
    {
        nodeList[i] = createNode(i);
    }
    for (ll i = 0; i < n; i++)
    {
        adjacencyList[i] = createAdjNode(nodeList[i]);
    }
    for (ll i = 0; i < e; i++)
    {
        ll u, v;
        scanf("%lld %lld", &u, &v);
        adjNode *x = createAdjNode(nodeList[v]);
        appendNode(adjacencyList[u], x);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     printLinkedList(adjacencyList[i]);
    // }
    // DFS(0, adjacencyList);
    BFS(0, adjacencyList, n);
    return 0;
}