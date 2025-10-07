#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc <= 100) {
        int n = argc - 1;
        int nums[n];

        for (int i = 1; i < argc; i++) {
            nums[i - 1] = atoi(argv[i]);
        }

        sort(nums, n);

        for (int i = 0; i < n; i++) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
    return 0;
}