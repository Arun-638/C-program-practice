#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
    if (argc <=100)
    {
        int flag = 1;
        if(flag == 1){
            for (int i = 1; i < argc-1; i++)
            {
                flag = 0;
                for (int j = i+1; j < argc; j++)
                {
                    if(atoi(argv[i]) > atoi(argv[j])){
                        char *temp = argv[i];
                        argv[i] = argv[j];
                        argv[j] = temp;
                        flag = 1;
                    }
                }
                
            }
            for (int i = 1; i < argc; i++)
            {
                printf("%d ",atoi(argv[i]));
            }
        }
    }   
    return 0;
}