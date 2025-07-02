#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
    if (argc <=100)
    {
        for (int i = argc-1; i > 0; i--)
        {
            printf("%d ",atoi(argv[i]));
        }
    }   
    return 0;
}