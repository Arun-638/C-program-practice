#include<stdio.h>
void binary_search(int A[],int key,int n){
    int low = 0,high = n-1,found = 0;
    while(low<=high){
        int mid = (low+high)/2;
        if(A[mid] == key){
            printf("Key Found at %d\n",mid+1);
            found = 1;
            break;
        }
        else if(key > A[mid]){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    if(!found){
        printf("Key Not found!!");
    }
}
void main(){
    int n,key;
    printf("Enter the size: ");
    scanf("%d",&n);
    int A[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }
    printf("Enter the key: ");
    scanf("%d",&key);
    binary_search(A,key,n);
}