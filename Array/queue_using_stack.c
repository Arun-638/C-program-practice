#include <stdio.h>
#define MAX 100

int s1[MAX], s2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) {
    if (top1 == MAX - 1) {
        printf("Stack1 overflow\n");
        return;
    }
    s1[++top1] = x;
}

int pop1() {
    if (top1 == -1) return -1;
    return s1[top1--];
}

void push2(int x) {
    if (top2 == MAX - 1) {
        printf("Stack2 overflow\n");
        return;
    }
    s2[++top2] = x;
}

int pop2() {
    if (top2 == -1) return -1;
    return s2[top2--];
}

int isEmpty1() { return top1 == -1; }
int isEmpty2() { return top2 == -1; }

void enqueue(int x) {
    push1(x);
}

int dequeue() {
    int val;
    if (isEmpty1() && isEmpty2()) {
        printf("Queue Underflow\n");
        return -1;
    }
    if (isEmpty2()) {
        while (!isEmpty1()) {
            push2(pop1());
        }
    }

    val = pop2();
    return val;
}

void display() {
    if (isEmpty1() && isEmpty2()) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    for (int i = 0; i <= top2; i++)
        printf("%d ", s2[i]);
    for (int i = top1; i >= 0; i--)
        printf("%d ", s1[i]);

    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            x = dequeue();
            if (x != -1)
                printf("Dequeued element: %d\n", x);
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
