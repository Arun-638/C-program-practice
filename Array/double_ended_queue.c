#include <stdio.h>
#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}
void insertRear(int x) {
    if (rear == MAX - 1) {
        printf("\nDeque is full!");
        return;
    }
    if (front == -1){
        front = 0;
    }
    deque[++rear] = x;
    printf("\nInserted %d at rear", x);
}
void insertFront(int x) {
    if (front == 0 && rear != -1) {
        printf("\nNo space at front to insert!");
        return;
    }
    if (front == -1) {
        rear=front = 0;
    } else {
        front--;
    }
    deque[front] = x;
    printf("\nInserted %d at front", x);
}

void deleteFront() {
    if (isEmpty()) {
        printf("\nDeque is empty!");
        return;
    }
    printf("\nDeleted %d from front", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void deleteRear() {
    if (isEmpty()) {
        printf("\nDeque is empty!");
        return;
    }
    printf("\nDeleted %d from rear", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else {
        rear--;
    }
}

void display() {
    if (isEmpty()) {
        printf("\nDeque is empty!");
        return;
    }
    printf("\nDeque elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", deque[i]);
    }
    printf("\nFront: %d, Rear: %d", front, rear);
}

int main() {
    int choice, x;
    while (1) {
        printf("\n\n--- DOUBLE ENDED QUEUE (LINEAR) ---");
        printf("\n1. Insert Front");
        printf("\n2. Insert Rear");
        printf("\n3. Delete Front");
        printf("\n4. Delete Rear");
        printf("\n5. Display");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                insertFront(x);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &x);
                insertRear(x);
                break;
            case 3:
                deleteFront();
                break;
            case 4:
                deleteRear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("\nInvalid choice!");
        }
    }
}
