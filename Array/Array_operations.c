#include<stdio.h>
void display(int A[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void insertion(int A[],int n,int key,int element){
    for (int i = n - 1; i >= key; i--)
    {
        A[i+1] = A[i];
    }
    A[key] = element;
    return;
}
void deletion(int A[],int n,int key){
    for (int i = key; i< n-1; i++)
    {
        A[i] = A[i+1];
    }
    return;
}
void binary_search(int A[],int key,int n){ //Must be sorted array
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
    int n,choice;
    int key,element;
    printf("Enter the size: ");
    scanf("%d",&n);
    int A[100];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element: ");
        scanf("%d",&A[i]);
    }
    do
    {
        printf("\nMENU\n----\n1.Insert\n2.Delete\n3.Search\n4.Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the key and element: ");
                scanf("%d %d",&key,&element);
                insertion(A,n,key,element);
                n+=1;
                display(A,n);
                break;
            case 2:
                printf("Enter the key: ");
                scanf("%d",&key);
                deletion(A,n,key);
                n-=1;
                display(A,n);
                break;
            case 3:
                printf("Enter the key to search: ");
                scanf("%d",&key);
                binary_search(A,n,key);
                break;
        }
    } while (choice!=4);  
}