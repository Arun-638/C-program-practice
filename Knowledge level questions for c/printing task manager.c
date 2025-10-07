#include <stdio.h>
#include <string.h>
typedef struct{
    char tasks[5][25];
    int front,rear;
}queue;
void Add_task(queue *q){
    char task[25];
    if((q->rear + 1) % 5 == q->front){
        printf("Queue is Full.");
        return;
    }
    else{
        printf("Enter the task: ");
        scanf("%s", task);
        if (q->front == -1) {
            q->front = q->rear = 0;
        } else {
            q->rear = (q->rear + 1) % 5;
        }
        strcpy(q->tasks[q->rear], task);
    }
}
void Add_emergency(queue *q){
    char task[25];
    if((q->rear + 1) % 5 == q->front){
        printf("Queue is Full");
        return;
    }
    
    printf("Enter the Emergency Task: ");
    scanf("%s", task);

    if (q->front == -1) {
        q->front = q->rear = 0;
    } else {
        q->front = (q->front - 1 + 5) % 5;
    }
    strcpy(q->tasks[q->front], task);
}
char Dequeue(queue *q){
    char item[25];
    if(q->front == -1){
        printf("Queue is Empty.");
        item[0] = '\0';
        return item;
    }
    else{
        strcpy(item,q->tasks[q->front]);
        if(q->front == q->rear){
            q->rear = -1;
            q->front = -1;
        }
        else{
            q->front = (q->front + 1) % 5;
        }
    }
    return item;
}
void Cancel_last_task(queue *q){
    if(q->front == -1){
        printf("Queue is Empty");
    }
    else{
        printf("Cancelled task: %s\n", q->tasks[q->rear]);
        if (q->front == q->rear) {
            q->front = q->rear = -1;
        } 
        else {
            q->rear = (q->rear - 1 + 5) % 5;
        }
    }
}
void view_tasks(queue *q){
    if(q->front == -1){
        printf("Queue is Empty");
    }
    else{
        printf("Current Print Tasks in Queue:\n");
        int i = q->front;
        while (1) {
            printf("- %s\n", q->tasks[i]);
            if (i == q->rear) break;
            i = (i + 1) % 5;
        }
    }
}
int main(){
    int choice;
    queue q;
    q.front = -1;
    q.rear = -1;
    do{
        printf("\nMenu\n----\n\n1.Add Task\n2.Add emergency\n3.Process Next Task\n4.Cancel Task\n5. View Task Queue\n6.Exit\n\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: Add_task(&q); break;
        case 2: Add_emergency(&q); break;
        case 3: 
            char item[25];
            strcpy(item,Dequeue(&q)); 
            printf("%s Task completed!!",item);
            break;
        case 4: Cancel_last_task(&q); break;
        case 5: view_tasks(&q); break;
        case 6: printf("Exiting!");
        default:
            printf("Invalid Choice!!\n");
            break;
        }
    }
    while(choice != 6);
}