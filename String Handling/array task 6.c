#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
    if (argc <=100)
    {
        int status[argc-1],new_array[argc-1];
        for (int i = 0; i < argc-1; i++)
        {
            status[i]=1;
        }
        
        for (int i = 1; i < argc-1; i++)
        {
            if(status[i] == 1){
                for (int j = i+1; j < argc; j++)
                {
                    if (atoi(argv[i]) == atoi(argv[j]))
                    {
                        status[j] = 0;
                    }
                    
                }
            }
        }
        int times = 0;
        for (int k = 1; k < argc; k++)
        {
            if(status[k] == 1){
                new_array[times++] = atoi(argv[k]);
            }
        }

        for (int i = 0; i < times; i++)
        {
            printf("%d ",new_array[i]);
        }
        
    }
}