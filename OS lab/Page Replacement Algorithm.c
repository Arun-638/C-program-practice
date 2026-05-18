#include<stdio.h>
#define MAX 50
int ispresent(int frame[],int n,int page){
    for(int i=0;i<n;i++){
        if(frame[i] == page){
            return 1;
        }
    }
    return 0;
}
int fifo(int pages[],int n,int framecount){
    int frame[MAX];
    int faults = 0;
    for (int i = 0; i < framecount; i++)
        frame[i] = -1;
    for(int i = 0;i<n;i++){
        if(!ispresent(frame,framecount,pages[i])){
            frame[i] = pages[i];
            faults++;
            i = (i+1)%framecount;
        }
    }
    return faults;
}

int lru(int pages[],int n,int framecount){
    int frame[MAX];
    int recent[MAX];
    int faults = 0;
    for(int i=0;i<framecount;i++){
        frame[i] = -1;
        recent[i] = -1;
    }
    for(int i=0;i<n;i++){
        int found = 0;
        for(int j=0;j<framecount;j++){
            if(frame[j] == pages[i]){
                recent[j] = i;
                found = 1;
                break;
            }
        }
        if(!found){
            int min = recent[0];
            int index = 0;
            for(int j=1;j<framecount;j++){
                if(recent[j] < min){
                    min = recent[j];
                    index = j;
                }
            }
            frame[index] = pages[i];
            recent[index] = i;
            faults++;
        }
    }
    return faults;
}

int optimal(int pages[],int n,int framecount){
    int frame[MAX];
    int faults = 0;
    for(int i=0;i<framecount;i++){
        frame[i] = -1;
    }
    for(int i=0;i<n;i++){
        if(ispresent(frame,framecount,pages[i])){
            continue;
        }
        int index = -1;
        for(int j=0;j<framecount;j++){
            if(frame[j] == -1){
                index = j;
                break;
            }
        }
        if(index == -1){
            int max = -1;
            for(int j=0;j<framecount;j++){
                int k;
                for(k=i+1;k<n;k++){
                    if(frame[j] == pages[k]){
                        break;
                    }
                }
                if(k == n){
                    index = j;
                    break;
                }
                if(k > max){
                    max = k;
                    index = j;
                }
            }
        }
        frame[index] = pages[i];
        faults++;
    }
    return faults;
}
int main(){
    int n,framecount;
    printf("Enter number of pages: ");
    scanf("%d",&n);
    int pages[n];
    printf("Enter page reference string: ");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d",&framecount);
    printf("FIFO Page Faults: %d\n",fifo(pages,n,framecount));
    printf("LRU Page Faults: %d\n",lru(pages,n,framecount));
    printf("Optimal Page Faults: %d\n",optimal(pages,n,framecount));
}