//Disk Scheduling Algorithms in C - SSTF, LOOK, CSCAN
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
#define MAX_CYLINDER 4999
// Sorting function
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
// SSTF Algorithm
int sstf(int req[], int head)
{
    int visited[SIZE] = {0};
    int total = 0;

    for (int i = 0; i < SIZE; i++)
    {
        int min = 5000;
        int index = -1;

        for (int j = 0; j < SIZE; j++)
        {
            if (!visited[j])
            {
                int dist = abs(head - req[j]);
                if (dist < min)
                {
                    min = dist;
                    index = j;
                }
            }
        }

        total += abs(head - req[index]);
        head = req[index];
        visited[index] = 1;
    }

    return total;
}
// LOOK Algorithm
int look(int req[], int head)
{
    int temp[SIZE];
    int total = 0;

    for (int i = 0; i < SIZE; i++)
        temp[i] = req[i];

    sort(temp, SIZE);

    int i;
    for (i = 0; i < SIZE; i++)
    {
        if (temp[i] >= head)
            break;
    }

    int current = head;

    for (int j = i; j < SIZE; j++)
    {
        total += abs(current - temp[j]);
        current = temp[j];
    }

    for (int j = i - 1; j >= 0; j--)
    {
        total += abs(current - temp[j]);
        current = temp[j];
    }

    return total;
}
// CSCAN Algorithm
int cscan(int req[], int head)
{
    int temp[SIZE];
    int total = 0;

    for (int i = 0; i < SIZE; i++)
        temp[i] = req[i];

    sort(temp, SIZE);

    int i;
    for (i = 0; i < SIZE; i++)
    {
        if (temp[i] >= head)
            break;
    }

    int current = head;

    for (int j = i; j < SIZE; j++)
    {
        total += abs(current - temp[j]);
        current = temp[j];
    }

    total += abs(current - MAX_CYLINDER);
    current = MAX_CYLINDER;

    total += MAX_CYLINDER;
    current = 0;
    for (int j = 0; j < i; j++)
    {
        total += abs(current - temp[j]);
        current = temp[j];
    }

    return total;
}
int main()
{
    int req[SIZE];
    int head;

    printf("Enter the disk requests (10): ");
    for (int i = 0; i < SIZE; i++)
        scanf("%d", &req[i]);

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    printf("Total head movement using SSTF: %d\n", sstf(req, head));
    printf("Total head movement using LOOK: %d\n", look(req, head));
    printf("Total head movement using CSCAN: %d\n", cscan(req, head));

    return 0;
}