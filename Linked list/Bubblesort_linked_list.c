#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
struct node *create(){
    struct node *head = NULL,*temp = NULL;
    int n,item;
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the %d node with data: ",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&item);
        if (head == NULL)
        {
            head = (struct node*) malloc(sizeof(struct node));
            head->data = item;
            head->next = NULL;
        }
        else
        {
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = (struct node*) malloc(sizeof(struct node));
            temp = temp->next;
            temp->data = item;
            temp->next = NULL;
        }
    }
    return head;
}
void printlist(struct node *head){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d",temp->data);
        if(temp->next != NULL){
            printf("->");
        }
        temp = temp->next;
    }
    printf("->NULL");
}
void bubblesort_ll(struct node *head){
    struct node *temp = NULL;
    int swapped;
    do
    {
        swapped = 0;
        temp = head;
        while(temp->next!= NULL){
            if (temp->data > temp->next->data)
            {
                swap(&temp->data,&temp->next->data);
                swapped = 1;
            }
            temp = temp->next;
        }
    } while (swapped);
}
void main(){
    struct node *head = create();
    bubblesort_ll(head);
    printlist(head);
}