#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>

typedef struct node{
    int val;
    struct node* next;
} node;

void rsort(node* head){
    node* curr1 = head;
    while (curr1!=NULL){
        node* curr = head;
        while(curr->next!= NULL){
            if ((curr-> val) > (curr->next-> val)){
                int tmp = curr-> val;
                curr-> val = curr-> next-> val;
                curr-> next->val = tmp;
            }
            curr = curr->next;
        }
        curr1 = curr1-> next;
    }
}

// void merge(node* head, int l, int m, int r){
//     node* head1 = (node*)malloc(sizeof(node));
//     node* head2 = (node*)malloc(sizeof(node));
// }

// void mergesort(node* head, int l, int r){
//     int m = (l+r)/2;
//     mergesort(head, l, m);
//     mergesort(head, m+1, r);
//     merge(head, l, m, r);
// }

void insertNodeAtPos(node*new, node* curr, int pos){
    if(pos==1){
        new->next = curr-> next-> next;
        curr-> next = new;
        return;
    }
    else{
        return insertNodeAtPos(new, curr-> next, pos-1);
    }
}

void insertNode(node*new, node* curr){
    if(curr-> next == NULL){
        curr-> next = new;
        return;
    }
    else{
        return insertNode(new, curr-> next);
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
    int n;
    scanf("%d", &n);
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
    rsort(head);
    // mergesort(head, 0, n-1);
    printList(head);
    return 0;
}