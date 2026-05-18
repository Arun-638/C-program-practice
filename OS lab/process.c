//Scheduling Algorithm - FCFS, SJF, non preemptive Priority, Round Robin
#include <stdio.h>
#include <stdlib.h>
#define MAX_PROCESSES 100
#define TIME_QUANTUM 4
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort(int P[],int AT[],int BT[],int PR[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(AT[j] > AT[j+1]){
                swap(&AT[j],&AT[j+1]);
                swap(&BT[j],&BT[j+1]);
                swap(&PR[j],&PR[j+1]);
                swap(&P[j],&P[j+1]);
            }
        }
    }
}
int fcfs(int P[], int AT[], int BT[], int n){
    int ct[MAX_PROCESSES], wt[MAX_PROCESSES], tat[MAX_PROCESSES];
    int time = 0, total = 0;
    for(int i=0;i<n;i++){
        if(time < AT[i]){
            time = AT[i];
        }
        time+= BT[i];
        ct[i] = time;
        tat[i] = ct[i] - AT[i];
        wt[i] = tat[i] - BT[i];
        total+= wt[i];
    }
    return total/n;
}
int srtf(int P[], int AT[], int BT[], int n){
    int rt[MAX_PROCESSES], wt[MAX_PROCESSES], tat[MAX_PROCESSES],ct[MAX_PROCESSES];
    int time = 0, total = 0,completed = 0;
    for(int i=0;i<n;i++){
        rt[i] = BT[i];
    }
    while(completed < n){
        int idx = -1, min = 9999;
        for(int i=0;i<n;i++){
            if(AT[i]<=time && rt[i]>0 && rt[i]<min){
                min = rt[i];
                idx = i;
            }
        }
        if(idx == -1){
            time++;
            continue;
        }
        else{
            rt[idx]--;
            time++;
            if(rt[idx] == 0){
                completed++;
                ct[idx] = time;
                tat[idx] = ct[idx] - AT[idx];
                wt[idx] = tat[idx] - BT[idx];
                total+= wt[idx];
            }
        }
    }
    return total/n;
}

int priority(int P[], int AT[], int BT[], int PR[], int n){
    int rt[MAX_PROCESSES], wt[MAX_PROCESSES], tat[MAX_PROCESSES],ct[MAX_PROCESSES];
    int time = 0, total = 0,completed = 0;
    while(completed < n){
        int idx = -1, min = 9999;
        for(int i=0;i<n;i++){
            if(AT[i]<=time && BT[i]>0 && PR[i]<min){
                min = PR[i];
                idx = i;
            }
        }
        if(idx == -1){
            time++;
            continue;
        }
        else
        {
            time+= BT[idx];
            ct[idx] = time;
            tat[idx] = ct[idx] - AT[idx];
            wt[idx] = tat[idx] - BT[idx];
            total+= wt[idx];
            completed++;
            BT[idx] = 0;
        }
    }
    return total/n;
}
int round_robin(int P[], int AT[], int BT[], int n){
    int rt[MAX_PROCESSES], wt[MAX_PROCESSES], tat[MAX_PROCESSES],ct[MAX_PROCESSES];
    int time = 0, total = 0,completed = 0;
    for(int i=0;i<n;i++){
        rt[i] = BT[i];
    }
    while(completed < n){
        for(int i=0;i<n;i++){
            if(AT[i]<=time && rt[i]>0){
                if(rt[i]>TIME_QUANTUM){
                    time+= TIME_QUANTUM;
                    rt[i]-= TIME_QUANTUM;
                }
                else{
                    time+= rt[i];
                    rt[i] = 0;
                    completed++;
                    ct[i] = time;
                    tat[i] = ct[i] - AT[i];
                    wt[i] = tat[i] - BT[i];
                    total+= wt[i];
                }
            }
        }
    }
    return total/n;
}
int main(){
    int P[MAX_PROCESSES],AT[MAX_PROCESSES],BT[MAX_PROCESSES],PR[MAX_PROCESSES];
    int n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        printf("Enter Process ID, Arrival Time, Burst Time and Priority for Process %d: ", i+1);
        scanf("%d %d %d %d",&P[i],&AT[i],&BT[i],&PR[i]);
    }
    sort(P, AT, BT, PR, n);
    //FCFS
    printf("\nFCFS Scheduling:\n");
    printf("Average Waiting Time: %d\n", fcfs(P, AT, BT, n));
    //SRTF
    printf("\nSRTF Scheduling:\n");
    printf("Average Waiting Time: %d\n", srtf(P, AT, BT, n));
    //Priority
    printf("\nPriority Scheduling:\n");
    printf("Average Waiting Time: %d\n", priority(P, AT, BT, PR, n));
    //Round Robin
    printf("\nRound Robin Scheduling:\n");
    printf("Average Waiting Time: %d\n", round_robin(P, AT, BT, n));
}