#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *rptr,*lptr;
}Node;

Node *header = NULL,*temp=NULL,*prev=NULL,*new=NULL;

void InsertAtFirst(){
    int item;
    printf("Enter the Data for the beginning: ");
    scanf("%d",&item);
    if(header == NULL){
        header = (Node*)malloc(sizeof(Node));
        header->data = item;
        header->rptr = NULL;
        header->lptr = NULL;
    }
    else{
        new = (Node*)malloc(sizeof(Node));
        new->data = item;
        new->lptr = NULL;
        new->rptr = header;
        header->lptr = new;
        header = new;
    }
}

void InsertAtKey(){
    int item,key,count=1;
    printf("Enter the key and value: ");
    scanf("%d %d",&key,&item);
    temp = header;
    while(temp->rptr!= NULL && count!=key){
        temp=temp->rptr;
        count++;
    }
    if(temp->rptr == NULL){
        printf("Go to Menu choose Insert node at end.\n");
        return;
    }
    new = (Node*)malloc(sizeof(Node));
    new->data = item;
    new->rptr = temp->rptr;
    temp->rptr->lptr = new;
    temp->rptr = new;
    new->lptr = temp;
}

void InsertAtEnd(){
    int item;
    printf("Enter the Data for last node: ");
    scanf("%d",&item);
    temp = header;
    while (temp->rptr != NULL)
    {
        temp = temp->rptr;
    }
    new = (Node*)malloc(sizeof(Node));
    new->data = item;
    temp->rptr = new;
    new->lptr = temp;
    new->rptr = NULL;   
}

// void DeleteAtFirst(){
//     new = 
// }

void PrintList() {
    temp = header;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->rptr;
    }
    printf("NULL\n");
}
void main(){
    int choice;
    printf("\nMenu\n----\n\n1.Insert At Beginnning\n2.Insert at a specific key\n3.Insert at End\n4.Delete at beginning\n5.Delete at any key\n6.Delete at end\n7.Exit\n");
    do
    {
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            InsertAtFirst();
            PrintList();
            break;
        case 2:
            InsertAtKey();
            PrintList();
            break;
        case 3:
            InsertAtEnd();
            PrintList();
            break;
        case 4:
            DeleteAtFirst();
            PrintList();
            break;
        }
    } while (choice!=7);
    
}