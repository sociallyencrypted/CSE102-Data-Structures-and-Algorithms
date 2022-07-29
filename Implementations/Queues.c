#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef long long ll;

typedef struct Node
{
    ll val;
    struct Node *next;
} node;

typedef struct Queue
{
    struct Node *head;
    struct Node *tail;
} queue;

int isEmpty(queue *Q)
{
    if (Q->head == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(queue *Q, ll val)
{
    node *new = (node *)malloc(sizeof(node));
    new->val = val;
    new->next = NULL;
    if (isEmpty(Q))
    {
        Q->head = new;
        Q->tail = new;
    }
    else
    {
        Q->tail = new;
    }
}

void dequeue(queue *Q)
{
    if (isEmpty(Q))
    {
        printf("Error: Queue Empty!");
    }
    else
    {
        node *temp = Q->head;
        Q->head = Q->head->next;
        free(temp);
    }
}

node *first(queue *Q)
{
    return Q->head;
}

int main()
{
    queue *Q = (queue *)malloc(sizeof(queue));
    Q->head = NULL;
    Q->tail = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf(" %c", &c);
        if (c == 'E')
        {
            ll val;
            scanf("%lld", &val);
            enqueue(Q, val);
        }
        else if (c == 'D')
        {
            dequeue(Q);
        }
        else
        {
            node *x = first(Q);
            printf("%lld", x->val);
        }
    }
}

