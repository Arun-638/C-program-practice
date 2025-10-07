#include <stdio.h>
int front1 = -1,front2 = -1;
int rear1 = -1,rear2 = -1;
int queue1[20],queue2[20];

void enqueue1(int value) {
    if (rear1 == 19) {
        printf("Queue1 is Full\n");
        return;
    }
    if (front1 == -1){
        front1 = 0;
    }
    queue1[++rear1] = value;
}

void enqueue2(int value){
    if(rear2 == 19){
        printf("Queue is Full");
        return;
    }
    else{
        if(front2 == -1){
            front2 = 0;
        }
        queue2[++rear2] = value;
    }
}

int dequeue1(){
    if (front1 == -1) {
        printf("Queue1 is Empty\n");
        return -1;
    }
    int val = queue1[front1++];
    if (front1 > rear1) {
        front1 = rear1 = -1;
    }
    return val;
}

int dequeue2() {
    if (front2 == -1) {
        printf("Queue2 is Empty\n");
        return -1;
    }
    int val = queue2[front2++];
    if (front2 > rear2) {
        front2 = rear2 = -1;
    }
    return val;
}

void push(){
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    enqueue2(value);
    while (front1 != -1)
    {
        enqueue2(dequeue1());
    }

    while (front2 != -1) {
        enqueue1(dequeue2());
    }
}

void pop(){
    if(front1 == -1){
        printf("Queue is empty\n");
        return;
    }
    else{
        printf("Popped : %d\n",dequeue1());
    }
}
void main(){
    int choice;
    do
    {
        printf("Menu\n----\n1.Push\n2.Pop\n3.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        }
    } while (choice!=3);
}