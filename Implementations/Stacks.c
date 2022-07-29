#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef long long ll;

typedef struct Node
{
    ll val;
    struct Node *next;
} node;

typedef struct Stack
{
    struct Node *head;
} stack;

int isEmpty(stack *S)
{
    if (S->head == NULL)
    {
        return 1;
    }
    return 0;
}

void *push(stack *S, ll val)
{
    node *new = (node *)malloc(sizeof(node));
    new->val = val;
    new->next = NULL;
    new->next = S->head;
    S->head = new;
}

void *pop(stack *S)
{
    if (isEmpty(S))
    {
        printf("Error: Stack Empty\n");
    }
    else
    {
        node *temp = S->head;
        S->head = S->head->next;
        free(temp);
    }
}

node *peep(stack *S)
{
    if (isEmpty(S))
    {
        return NULL;
    }
    else
    {
        return S->head;
    }
}

int main()
{
    stack *S = (stack *)malloc(sizeof(stack));
    S->head = NULL;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char c;
        scanf(" %c", &c);
        if (c == 'P')
        {
            ll val;
            scanf("%lld", &val);
            push(S, val);
        }
        else if (c == 'O')
        {
            pop(S);
        }
        else
        {
            node *x = peep(S);
            printf("%lld", x->val);
        }
    }
}