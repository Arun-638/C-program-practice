#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int n;

struct graph {
    int data;
    int weight;
    struct graph* next;
};

void readgraph(struct graph* adj[]) {
    int i, j, e, w, data;

    for(i = 0; i < MAX; i++)
        adj[i] = NULL;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        struct graph* temp = NULL;
        printf("Enter the number of edges from vertex v%d: ", i);
        scanf("%d", &e);

        for(j = 0; j < e; j++) {
            printf("Enter the neighbour of v%d: ", i);
            scanf("%d", &data);
            printf("Enter the edge weight: ");
            scanf("%d", &w);

            struct graph* newnode = (struct graph*)malloc(sizeof(struct graph));
            newnode->data = data;
            newnode->weight = w;
            newnode->next = NULL;

            if(adj[i] == NULL)
                adj[i] = newnode;
            else
                temp->next = newnode;

            temp = newnode;
        }
    }
}
void dijkstra(struct graph* adj[], int start) {
    int dist[MAX], visited[MAX], prev[MAX];
    for(int i = 0; i < n; i++) {
        dist[i] = 999;
        visited[i] = 0;
        prev[i] = -1;
    }
    dist[start] = 0;

    for(int count = 0; count < n; count++) {
        int u = -1, min = 999;
        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if(u == -1) break;
        visited[u] = 1;

        struct graph* temp = adj[u];
        while(temp != NULL) {
            int v = temp->data;
            int w = temp->weight;
            if(!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prev[v] = u;
            }
            temp = temp->next;
        }
    }
    printf("\nVertex\tDistance from v%d\tPath\n", start);
    for(int i = 0; i < n; i++) {
        if(dist[i] == 999)
            printf("%d\tINF\t\t-\n", i);
        else {
            printf("%d\t%d\t\t", i, dist[i]);
            int path[100], k = 0, current = i;
            while(current != -1) {
                path[k++] = current;
                current = prev[current];
            }
            for(int j = k-1; j >= 0; j--) {
                if(j != k-1) printf(" -> ");
                printf("%d", path[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    struct graph* adj[MAX];
    readgraph(adj);
    int start;
    printf("\nEnter the source vertex for Dijkstra: ");
    scanf("%d", &start);

    dijkstra(adj, start);

    return 0;
}
