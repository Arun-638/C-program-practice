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
void main(){
    header = (Node *)malloc(sizeof(Node));
    header->data = 10;
    header->next->data = 20;
    header->next->next->data = 30;
    header->next->next->next = NULL;
    reverse(header);
}