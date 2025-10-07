#include<stdio.h>
int top1 = -1,top2 = -1;
int stack1[20],stack2[20];

void push1(int value){
    stack1[++top1] = value;
} 

void push2(int value){
    stack2[++top2] = value;
}

int pop1(){
    return stack1[top1--];
}

int pop2(){
    return stack2[top2--];
}

void enqueue(){
    int value;
    printf("Enter the value: ");
    scanf("%d",&value);
    while (top1 != -1)
    {
        push2(pop1());
    }
    push1(value);
    while (top2 != -1)
    {
        push1(pop2());
    }
}

void dequeue(){
    if (top1 == -1) {
        printf("Queue Underflow\n");
        return;
    }
    int value = pop1();
    printf("%d dequeued\n", value);
}

void main(){
    int choice;
    do
    {
        printf("Menu\n----\n1.Enqueue\n2.Dequeue\n3.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        }
    } while (choice!=3);
    
}