#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

void insertAtBeginning(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int value,int position){
    Node *temp = head,*prev = NULL,*newNode = (Node*)malloc(sizeof(Node));
    int count=1;
    if(temp == NULL){
        printf("Empty list");
        return;
    }
    while(temp!=NULL && count != position){
        prev = temp;
        temp = temp->next; 
        count++;
    }
    newNode->data = value;
    prev->next = newNode;
    newNode->next = temp;
}
void insertAtEnd(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void deleteNode(int value) {
    Node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", value);
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

int countNodes() {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void printList() {
    Node *temp = head;
    printf("List: ");
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
    int choice, value,position;

    while (1) {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Delete a node\n");
        printf("4. Count nodes\n");
        printf("5. Insert Node at any given position\n");
        printf("6. Display list\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 4:
                printf("Total nodes = %d\n", countNodes());
                break;
            case 5:
                printf("Enter the value you want to put in the node: ");
                scanf("%d",&value);
                printf("Enter the position: ");
                scanf("%d",&position);
                insertAtPosition(value,position);
            case 6:
                printList();
                break;
            case 7:
                printf("Exiting ....");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}