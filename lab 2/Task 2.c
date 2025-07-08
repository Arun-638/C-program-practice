#include <stdio.h>
void swap(char *x,char *y){
    char temp = *x;
    *x = *y;
    *y = temp;
}
void permutation(char *str,int left,int right){
    if(left == right){
        printf("%s\n",str);
    }
    else{
        for (int i = left; i <= right; i++)
        {
            swap((str+left),(str+i));
            permutation(str,left+1,right);
            swap((str+left),(str+i)); 
        }
    }
}
void main(){
    int size;
    char str[30];
    printf("Enter the string : ");
    scanf("%s",str);
    for(size = 0;str[size]!='\0';size++);
    permutation(str,0,size-1);
    return;
}
