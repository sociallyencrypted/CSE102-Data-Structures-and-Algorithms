#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef long long ll;

typedef struct node
{
    int exp;
    int coeff;
    struct node *next;
} node;

node *reverseList(node *head, node *prev, node *cur, node *next)
{
    while (cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev; // returns the new head
}

node *insertNodeAtPos(int exp, int coeff, node *curr, node *head, int pos)
{
    node *ins = (node *)malloc(sizeof(node));
    ins->exp = exp;
    ins->coeff = coeff;
    if (pos == 0)
    {
        ins->next = head;
        return ins;
    }
    if (pos == 1)
    {
        ins->next = curr->next;
        curr->next = ins;
        return head;
    }
    else if (curr == NULL)
    {
        printf("Error: End of list reached.\n");
        return head;
    }
    else
    {
        return insertNodeAtPos(exp, coeff, curr->next, head, pos - 1);
    }
}

node *deleteNodeAtPos(node *head, node *curr, int pos)
{
    if (pos == 0)
    {
        node *newh = head->next;
        free(head);
        return newh;
    }
    if (pos == 1)
    {
        if (curr->next != NULL)
        {
            node *temp = curr->next->next;
            free(curr->next);
            curr->next = temp;
            return head;
        }
        else
        {
            return head;
        }
    }
    else if (curr == NULL)
    {
        return head;
    }
    else
    {
        return deleteNodeAtPos(head, curr->next, pos - 1);
    }
}

void printLinkedList(node *curr)
{
    if (curr == NULL)
    {
        printf("END\n");
        return;
    }
    else
    {
        printf("%d %d->", curr->coeff, curr->exp);
        return printLinkedList(curr->next);
    }
}

int main()
{
    int n1;
    int n2;
    scanf("%d %d", &n1, &n2);
    node *head1 = NULL;
    head1 = (node *)malloc(sizeof(node));
    head1->next = NULL;
    node *head2 = NULL;
    head2 = (node *)malloc(sizeof(node));
    head2->next = NULL;
    for (int i = 0; i < n1; i++)
    {
        int c;
        int x;
        scanf("%d %d", &c, &x);
        if (i == 0)
        {
            head1->exp = x;
            head1->coeff = c;
        }
        else
        {
            head1 = insertNodeAtPos(x, c, head1, head1, i);
        }
    }
    for (int i = 0; i < n2; i++)
    {
        int c;
        int x;
        scanf("%d %d", &c, &x);
        if (i == 0)
        {
            head2->exp = x;
            head2->coeff = c;
        }
        else
        {
            head2 = insertNodeAtPos(x, c, head2, head2, i);
        }
    }
    printLinkedList(head1);
    printLinkedList(head2);
    node *headsum = (node *)malloc(sizeof(node));
    headsum->next = NULL;
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *curr = headsum;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == head1 && ptr2 == head2)
        {
            if (ptr1->exp > ptr2->exp)
            {
                headsum->coeff = ptr1->coeff;
                headsum->exp = ptr1->exp;
                ptr1 = ptr1->next;
            }
            else if (ptr1->exp < ptr2->exp)
            {
                headsum->coeff = ptr2->coeff;
                headsum->exp = ptr2->exp;
                ptr2 = ptr2->next;
            }
            else
            {
                headsum->coeff = ptr1->coeff + ptr2->coeff;
                headsum->exp = ptr2->exp;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        else if (ptr1 == NULL)
        {
            curr->next = ptr2;
            break;
        }
        else if (ptr2 == NULL)
        {
            curr->next = ptr1;
            break;
        }
        else
        {
            curr->next = (node *)malloc(sizeof(node));
            curr = curr->next;
            if (ptr1->exp > ptr2->exp)
            {
                curr->coeff = ptr1->coeff;
                curr->exp = ptr1->exp;
                ptr1 = ptr1->next;
            }
            else if (ptr1->exp < ptr2->exp)
            {
                curr->coeff = ptr2->coeff;
                curr->exp = ptr2->exp;
                ptr2 = ptr2->next;
            }
            else
            {
                curr->coeff = ptr1->coeff + ptr2->coeff;
                curr->exp = ptr2->exp;
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
    }
    printLinkedList(headsum);
}
