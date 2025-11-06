#include <stdio.h>
#include <stdlib.h>

int number_of_vertices;

struct node {
    int data;
    struct node *next;
};

void readgraph(struct node *adj[]) {
    struct node *newnode;
    int i, j, k, data;
    for (i = 0; i < 100; i++) {
        adj[i] = NULL;
    }
    for (i = 0; i < number_of_vertices; i++) {
        struct node *temp = NULL;
        printf("\nEnter the number of neighbours of %d: ", i);
        scanf("%d", &k);
        for (j = 0; j < k; j++) {
            printf("Enter the value of %d neighbour of %d: ", j, i);
            scanf("%d", &data);
            newnode = (struct node*)malloc(sizeof(struct node));
            newnode->data = data;
            newnode->next = NULL;
            if (adj[i] == NULL) {
                adj[i] = newnode;
            } else {
                temp->next = newnode;
            }
            temp = newnode;
        }
    }
}

void bfs(struct node *adj[]) {
    int visited[100], i;
    for (i = 0; i < 100; i++) {
        visited[i] = 0;
    }
    printf("\nBFS Traversal: ");
    for (i = 0; i < number_of_vertices; i++) {
        if (visited[i] == 0) {
            int queue[100], front = 0, rear = -1;
            queue[++rear] = i;
            visited[i] = 1;
            while (front <= rear) {
                int u = queue[front++];
                printf("%d ", u);
                struct node *ptr = adj[u];
                while (ptr != NULL) {
                    if (visited[ptr->data] == 0) {
                        queue[++rear] = ptr->data;
                        visited[ptr->data] = 1;
                    }
                    ptr = ptr->next;
                }
            }
        }
    }
    printf("\n");
}

void dfs(struct node *adj[]) {
    int visited[100], i;
    for (i = 0; i < 100; i++) {
        visited[i] = 0;
    }

    printf("\nDFS Traversal: ");
    for (i = 0; i < number_of_vertices; i++) {
        if (!visited[i]) {
            int stack[100], top = -1;
            stack[++top] = i;
            visited[i]=1;
            while (top != -1) {
                int u = stack[top--];
                printf("%d ", u);
                struct node *ptr = adj[u];
                while (ptr != NULL) {
                    if (!visited[ptr->data]) {
                        stack[++top] = ptr->data;
                        visited[ptr->data]=1;
                    }
                    ptr = ptr->next;
                }
            }
        }
    }
    printf("\n");
}
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &number_of_vertices);
    struct node *adj[100];
    readgraph(adj);
    bfs(adj);
    dfs(adj);
    return 0;
}
