#include<stdio.h>
#include<stdlib.h>
void main(int argc, char *argv[]){
    if(argc != 3){
        printf("Usage: %s <num1> <num2>\n", argv[0]);
        exit(1);
    }
    else{
        int num1 = atoi(argv[1]);
        int num2 = atoi(argv[2]);
        printf("Sum: %d\n", num1 + num2);
        return;
    }
}