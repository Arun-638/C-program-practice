#include<stdio.h>
void merge(int a[], int m1, int m2, int n1, int n2) {
    int s = n2 - m1 + 1;
    int temp[s];
    int i = m1, j = n1, k = 0;

    while (i <= m2 && j <= n2) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m2)
        temp[k++] = a[i++];

    while (j <= n2)
        temp[k++] = a[j++];

    for (i = m1, j = 0; i <= n2; i++, j++)
        a[i] = temp[j];
}
void mergesort(int a[], int i, int j) {
    if (i < j) {
        int mid = (i + j) / 2;
        mergesort(a, i, mid);
        mergesort(a, mid + 1, j);
        merge(a, i, mid, mid + 1, j);
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
    mergesort(arr,0,n-1);
    for(i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return;
}