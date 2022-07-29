#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef long long ll;

typedef struct Node
{
    ll val;
    int degree;
    struct Node **children;
} node;

void printTree(node *root)
{
    printf("\n");
    printf("%lld\n", root->val);
    printf("%d\n", root->degree);
    for (int i = 0; i < root->degree; i++)
    {
        printTree(root->children[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    node *root = (node *)malloc(sizeof(node));
    root->val = 1;
    root->degree = n;
    root->children = (node **)malloc(n * sizeof(node *));
    for (int i = 0; i < n; i++)
    {
        ll x;
        printf("Enter the value of the node: ");
        scanf("%lld", &x);
        root->children[i] = (node *)malloc(sizeof(node));
        root->children[i]->val = x;
        root->children[i]->degree = 0;
        root->children[i]->children = (node **)malloc(sizeof(node *));
    }
    printTree(root);
}