#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef long long ll;

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

int main()
{
    int n;
    scanf("%d", &n);
    node *root = (node *)malloc(sizeof(node));
    ll x;
    printf("Enter the value of the node: ");
    scanf("%lld", &x);
    root->val = x;
    root->left = NULL;
    root->right = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        ll x;
        printf("Enter the value of the node: ");
        scanf("%lld", &x);
        node *new = (node *)malloc(sizeof(node));
        new->val = x;
        new->left = NULL;
        new->right = NULL;
        if (i == 0)
        {
            root->left = new;
        }
        else
        {
            node *temp = root;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            temp->right = new;
        }
    }
    printTree(root);
}