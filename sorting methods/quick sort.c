#include<stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low,j= high;
    while(i<j){
        while (arr[i] <= pivot && i < high) {
            i++;
        }
        while (arr[j] > pivot && j > low) {
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int j = partition(arr,low,high);
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
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
    quicksort(arr,0,n-1);
    for(i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return;
}