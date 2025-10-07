#include <stdio.h>

typedef struct node 
{
    int data;
    struct node *next;
}Node;

Node *header = NULL;

Node* reverse(Node* head) {
    Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next; 
        curr->next = prev;  
        prev = curr;         
        curr = next;         
    }

    return prev;  // prev is the new head
}

Node* add(Node* first,Node* second){
    first = reverse(first);
    second = reverse(second);
    int carry = 0;
    Node *head = NULL,*prev = NULL,*sum = NULL;
    while(first!=NULL || second!=NULL || carry == 1){
        int total = carry+first->data+second->data;
        carry = total/10;
        total = total%10;
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->data = total;
        newnode->next = sum; // for reversing last 
        sum = newnode;
        if(first){
            first = first->next;
        }
        if(second){
            second = second->next;
        }
    }
    return sum;
}