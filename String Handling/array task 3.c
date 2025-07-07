#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
    if (argc <=100)
    {
        int *status;
        status = (int*)calloc(10,sizeof(int));
        for (int i = 1; i < argc; i++) {
            int val = atoi(argv[i]);
            if (val >= 1 && val <= 100) {
                int bucket = (val - 1) / 10; 
                status[bucket]++;
            }
        }
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < status[i]; j++)
            {
                printf("#");
            }
            printf("\n");
        }
        free(status);
    }   
    return 0;
}