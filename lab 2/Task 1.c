#include <stdio.h>
void first_non_repeating(char str[]){
    int size;
    char c;
    for (size = 0; str[size] !='\0'; size++);
    int status[size-1],flag = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = i; str[j]!='\0'; j++)
        {
            if(i != j){
                if (str[i] == str[j])
                {
                    status[i] = 1;
                    status[j] = 1;
                }
            }
        }
    }
    for (int i = 0; i < size-1; i++)
    {
        if(status[i] != 1){
            printf("%c",str[i]);
            flag=1;
            break;
        }
    }
    if(flag == 0){
        printf("$");
    }
}
void main(){
    char str[50];
    printf("Enter the string: ");
    scanf("%s",str);
    first_non_repeating(str);
}