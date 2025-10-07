#include<stdio.h>
void insertionsort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        int j = i-1;
        int x = arr[i];
        while(j>-1 && arr[j]>x){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}

void main(){
    int n,i;
    printf("Enter the size: ");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        printf("Enter the elements : ");
        scanf("%d",&arr[i]);
    }
    insertionsort(arr,n);
    for(i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return;
}