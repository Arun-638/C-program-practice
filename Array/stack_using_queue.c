#include <stdio.h>
#define MAX 100

int q1[MAX], q2[MAX];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

void enqueue1(int x) {
    if (rear1 == MAX - 1) {
        printf("Queue1 overflow\n");
        return;
    }
    if (front1 == -1)
        front1 = 0;
    q1[++rear1] = x;
}

int dequeue1() {
    if (front1 == -1 || front1 > rear1) {
        return -1;
    }
    return q1[front1++];
}

void enqueue2(int x) {
    if (rear2 == MAX - 1) {
        printf("Queue2 overflow\n");
        return;
    }
    if (front2 == -1)
        front2 = 0;
    q2[++rear2] = x;
}

int dequeue2() {
    if (front2 == -1 || front2 > rear2) {
        return -1;
    }
    return q2[front2++];
}

int isEmpty1() {
    return (front1 == -1 || front1 > rear1);
}

int isEmpty2() {
    return (front2 == -1 || front2 > rear2);
}
void push(int x) {
    enqueue2(x);
    while (!isEmpty1()) {
        enqueue2(dequeue1());
    }

    int temp[MAX], tf, tr;
    int i;

    for (i = 0; i < MAX; i++)
        temp[i] = q1[i];

    tf = front1; tr = rear1;
    front1 = front2; rear1 = rear2;
    for (i = 0; i < MAX; i++)
        q1[i] = q2[i];

    front2 = tf; rear2 = tr;
}

int pop() {
    if (isEmpty1()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return dequeue1();
}

void display() {
    if (isEmpty1()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = front1; i <= rear1; i++)
        printf("%d ", q1[i]);
    printf("\n");
}
int main() {
    int choice, x;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            if (x != -1)
                printf("Popped element: %d\n", x);
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}
