#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef long long ll;

typedef struct QNode
{
    ll val;
    struct QNode *next;
} qnode;

typedef struct Queue
{
    struct QNode *head;
    struct QNode *tail;
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
    qnode *new = (qnode *)malloc(sizeof(qnode));
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
        qnode *temp = Q->head;
        Q->head = Q->head->next;
        free(temp);
    }
}

qnode *first(queue *Q)
{
    return Q->head;
}

typedef struct Node
{
    ll val;
    struct Node *left;
    struct Node *right;
} node;

void printTree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("\n");
    printf("%lld\n", root->val);
    printTree(root->left);
    printTree(root->right);
}

void printArray(ll *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int i = 0;
    ll *arr = (ll *)malloc(sizeof(ll));
    ll sum = 0;
    // node *root = (node *)malloc(sizeof(node));
    // ll x;
    while (1)
    {
        char c;
        scanf("%c", &c);
        if (c == '\n' || c == '\0')
        {
            break;
        }
        else if (c == ' ' || c == 'u' || c == 'l')
        {
            continue;
        }
        else if (c == 'n')
        {
            arr[i] = -1;
            realloc(arr, sizeof(ll) * (i + 1));
            i++;
        }
        else
        {
            while (1)
            {
                if (c == ' ')
                {
                    arr[i] = sum;
                    realloc(arr, sizeof(ll) * (i + 1));
                    i++;
                    sum = 0;
                    break;
                }
                else
                {
                    sum = sum * 10 + (c - '0');
                }
            }
        }

        // printf("Enter the value of the node: ");
        // scanf("%lld", &x);
        // node *new = (node *)malloc(sizeof(node));
        // new->val = x;
        // new->left = NULL;
        // new->right = NULL;
        // if (i == 0)
        // {
        //     root->left = new;
        // }
        // else
        // {
        //     node *temp = root;
        //     while (temp->right != NULL)
        //     {
        //         temp = temp->right;
        //     }
        //     temp->right = new;
        // }
    }
    printArray(arr, i);
    // printTree(root);
}