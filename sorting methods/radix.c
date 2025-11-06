#include<stdio.h>
#include<math.h>
void radix_sort(int A[], int n) {
    int bucket[10][10];  
    int count[10];  
    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) max = A[i];
    }

    int passes = (int)floor(log10(max)) + 1; //get the size of the integer

    int divisor = 1;

    for (int p = 0; p < passes; p++) {
        for (int i = 0; i < 10; i++) count[i] = 0; //number of elements for each digit
        for (int i = 0; i < n; i++) {
            int digit = (A[i] / divisor) % 10;
            bucket[digit][count[digit]] = A[i];
            count[digit]++;
        }
        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < count[i]; j++) {
                A[index++] = bucket[i][j];
            }
        }
        divisor *= 10;
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
    radix_sort(arr,n);
    for(i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return;
}