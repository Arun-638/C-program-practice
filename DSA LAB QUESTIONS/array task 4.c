#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
    if (argc <=100)
    {
        int max = atoi(argv[1]),times = 0; 
        for (int i = 1; i < argc; i++)
        {
            int num = atoi(argv[i]);
            if (num > max)
            {
                max = num;
            }
        }
        for (int i = 1; i < argc; i++)
        {
            int num = atoi(argv[i]);
            if(num == max){
                times++;
            }
        }
        int freq = 0,temp = 0,value;
        int status[argc-1];
        for (int k = 0; k < argc-1; k++)
        {
            status[k] = 1;
        }
    
        for (int i = 1; i < argc-1; i++)
        {
            temp = 1;
            int num = atoi(argv[i]);
            if(status[i] == 1){
                for (int j = i+1; j < argc; j++)
                {
                    int num2 = atoi(argv[j]);
                    if(num == num2){
                        status[j] = 0;
                        temp++;
                    }
                    if(temp>freq){
                        freq = temp;
                        value = num;
                    }

                }
            }    
        }
        
        printf("The number of times the maximum value %d repeated: %d\n ",max,times);
        printf("The most frequent number is %d which is %d times",value,freq);
    }   
    return 0;
}