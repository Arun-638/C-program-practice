#include<stdio.h>
void heapsort(int a[], int n) {
     for (int i = n / 2 - 1; i >= 0; i--) {
        int j = i;
        while (1) {
            int largest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < n && a[left] > a[largest])
                largest = left;

            if (right < n && a[right] > a[largest])
                largest = right;

            if (largest == j)
                break;
            int temp = a[j];
            a[j] = a[largest];
            a[largest] = temp;

            j = largest;
        }
    }
    for (int end = n - 1; end > 0; end--) {
        int temp = a[0];
        a[0] = a[end];
        a[end] = temp;
        int j = 0;
        while (1) {
            int largest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < end && a[left] > a[largest])
                largest = left;

            if (right < end && a[right] > a[largest])
                largest = right;

            if (largest == j)
                break;

            temp = a[j];
            a[j] = a[largest];
            a[largest] = temp;

            j = largest;
        }
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
    heapsort(arr,n);
    for(i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return;
}