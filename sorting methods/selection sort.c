#include<stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectionsort(int arr[],int n){
    int smallest;
    for (int i = 0;i < n-1;i++){
        smallest = i;
        for(int j = i+1;j < n;j++){
            if(arr[j] < arr[smallest]){
                smallest = j;
            }
        }
        swap(&arr[i],&arr[smallest]);
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
    selectionsort(arr,n);
    for(i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return;
}