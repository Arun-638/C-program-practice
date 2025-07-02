#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
    if (argc <=100)
    {
        int average = 0,sum=0,max=atoi(argv[1]),min=atoi(argv[1]);
        for (int i = 1; i < argc; i++)
        {
            int num = atoi(argv[i]);
            sum+=num;
            if(num > max){
                max = num; 
            }
            if (num < min)
            {
                min = num;
            }
            
        }
        average = sum/(argc - 1);
        printf("Average = %d\n Max = %d\n Min = %d\n",average,max,min);
        return 0;
    }   
}