#include<stdio.h>
#include<stdlib.h>
int *two_sum(int *nums,int target,int n){
    for(int i=0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            if((nums[i]+nums[j]) == target){
                int *result = (int*)malloc(2*sizeof(int));
                result[0]=i;
                result[1]=j;
                return result;
            }
        }
    }
}
int main(){
    int n,target;
    printf("Enter the size of the array: ");
    scanf("%d",&n);int *nums = (int*) malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter the element: ");
        scanf("%d",&nums[i]);
    }
    printf("Enter the target: ");
    scanf("%d",&target);
    int* result = two_sum(nums,target,n);
    if (result != NULL) {
        printf("[%d,%d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No pair found that adds up to %d.\n", target);
    }
    free(nums);
    return 0;
}