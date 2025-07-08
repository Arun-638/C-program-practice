#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
    if (argc <=100)
    {
        int average = 0,sum=0,max=atoi(argv[1]),min=atoi(argv[1]),second_max=atoi(argv[1]),found_second = 0;
        for (int i = 1; i < argc; i++)
        {
            int num = atoi(argv[i]);
            sum+=num;
            if (num > max) {
                second_max = max;
                max = num;
                found_second = 1;
            } else if (num > second_max && num < max) {
                second_max = num;
                found_second = 1;
            }
            if (num < min)
            {
                min = num;
            }
            
        }
        average = sum/(argc - 1);
        printf("Average = %d\n Max = %d\n Min = %d\n",average,max,min);
        if (!found_second || second_max == max) {
            printf("Second largest = Not found (no distinct second value)\n");
        } else {
            printf("Second largest = %d\n", second_max);
        }
        return 0;
    }   
}