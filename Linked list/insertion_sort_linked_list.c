#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
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
struct node *insertion_ll(struct node *head){
    struct node *sorted = NULL;
    struct node *temp = head;
    while(temp != NULL){
        struct node *next = temp->next;
        if(sorted == NULL || temp->data < sorted->data){
            temp->next = sorted;
            sorted = temp;
        }
        else{
            struct node *temp_sorted = sorted;
            while(temp_sorted->next != NULL && temp_sorted->next->data < temp->data){
                temp_sorted = temp_sorted->next;
            }
            temp->next = temp_sorted->next;
            temp_sorted->next = temp;
        }
        temp = next;
    }
    return sorted;
}
void main(){
    struct node *head = create();
    struct node *sortll = insertion_ll(head);
    printlist(sortll);
}