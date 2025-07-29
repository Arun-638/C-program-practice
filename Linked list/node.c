#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}Node;
void printnodes(Node *head){
    Node *temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void main(){
    Node *head = (Node*)malloc(sizeof(Node));
    Node *first = (Node*)malloc(sizeof(Node));
    Node *second = (Node*)malloc(sizeof(Node));
    head->data = 10;
    head->next = first;
    first->data = 20;
    first->next = second;
    second->data = 30;
    second->next = NULL;
    printnodes(head);
}