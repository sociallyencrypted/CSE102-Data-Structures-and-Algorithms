#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct node{
    int val;
    struct node* next;
} node;

node* reverse(node* prev, node* curr, node*nxt, node* l, node* r){
    if (curr == r){
        curr->next = prev;
        prev = NULL;
        return curr;
    }
    else if (curr==l){
        if (prev!=NULL)
        prev-> next = r;
        curr-> next = r->next;
        return reverse(curr, nxt, nxt-> next, l, r);
    }
    else{
        curr-> next = prev;
        return reverse(curr, nxt, nxt-> next, l, r);
    }
}

void insertNodeAtPos(node*new, node* curr, int pos){
    if(pos==1){
        new->next = curr-> next-> next;
        curr-> next = new;
        return;
    }
    else{
        insertNodeAtPos(new, curr-> next, pos-1);
    }
}

node* findNodeAt(node* curr, int pos){
    if (curr == NULL){
        return NULL;
    }
    if(pos == 0){
        return curr;
    }
    else{
        return findNodeAt(curr->next, pos-1);
    }
}

void insertNode(node*new, node* curr){
    if(curr-> next == NULL){
        curr-> next = new;
        return;
    }
    else{
        insertNode(new, curr-> next);
    }
}

void printList(node* curr){
    if (curr==NULL){
        printf("\n");
        return;
    }
    printf("%d ", curr-> val);
    printList(curr-> next);
}

int main(){
    int n; int k;
    scanf("%d %d", &n, &k);
    node* head = (node*)malloc(sizeof(node));
    head-> val = 0;
    head-> next = NULL;
    for (int i=0; i<n; i++){
        int x; scanf("%d", &x);
        node* new = (node*)malloc(sizeof(node));
        new-> val = x;
        new-> next = NULL;
        insertNode(new, head);
    }
    node* tmp = head;
    head = head-> next;
    free(tmp);
    // printList(head);
    if (k==1){
        printList(head);
        return 0;
    }
    for (int i=0; i<(n/k); i++){
        int l = i*k;
        int r = (i+1)*k-1;
        node* lef = findNodeAt(head, l);
        node* rit = findNodeAt(head, r);
        node* prev = NULL;
        if (i>0){
            prev = findNodeAt(head, l-1);
        }
        node* curr = lef;
        // printList(head);
        // printf("curr %d\n", curr->val);
        node* nxt = curr-> next;
        node* tmp = reverse(prev, curr, nxt, lef, rit);
        if(i==0){
            head = tmp;
        }
    }
    printList(head);
    return 0;
}