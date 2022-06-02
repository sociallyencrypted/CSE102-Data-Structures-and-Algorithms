#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef long long ll;

typedef struct node
{
    int val;
    struct node *next;
} node;

node *reverseList(node *head, node *prev, node *curr, node *next)
{
    if (prev == NULL || curr == head)
    {
        node *temp = curr->next;
        curr->next = NULL;
        return reverseList(head, curr, temp, temp->next);
    }
    else if (next == NULL)
    {
        curr->next = prev;
        return curr;
    }
    else
    {
        node *temp = curr->next;
        curr->next = prev;
        return reverseList(head, curr, temp, temp->next);
    }
}

node *insertNodeAtPos(int val, node *curr, node *head, int pos)
{
    node *ins = (node *)malloc(sizeof(node));
    ins->val = val;
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
        return insertNodeAtPos(val, curr->next, head, pos - 1);
    }
}

node *deleteNodeVal(node *head, node *curr, int val)
{
    if (curr == head && val == head->val)
    {
        node *newh = head->next;
        free(head);
        return newh;
    }
    else if (curr->next != NULL && curr->next->val == val)
    {
        node *temp = curr->next->next;
        free(curr->next);
        curr->next = temp;
        return head;
    }
    else if (curr == NULL)
    {
        return head;
    }
    else
    {
        return deleteNodeVal(head, curr->next, val);
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
        printf("%d->", curr->val);
        return printLinkedList(curr->next);
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        head = insertNodeAtPos(i + 3, head, head, i);
    }
    printLinkedList(head);
    // The lines below must throw an error.
    insertNodeAtPos(69420, head, head, 69);
    //////////////////////////////////////
    head = deleteNodeVal(head, head, 0);
    printLinkedList(head);
    head = reverseList(head, NULL, head, head->next);
    printLinkedList(head);
}
