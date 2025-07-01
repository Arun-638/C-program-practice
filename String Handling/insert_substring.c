#include <stdio.h>
void put_string(char str[],char substr[],int pos){
    int pos1,flag=1,k=0,p=0,j;
    char temp[100];
    for (int i = pos+1; flag!=0; i++)
    {
        if(substr[k] == '\0'){
            flag = 0;
        }
        temp[k] = str[i];
        if (flag == 1)
        {
            str[i] = substr[k];
            pos1 = i;
        }
        k++;
    }
    for (j = (pos1+1); j < (pos1+1+k); j++)
    {
        str[j] = temp[p];
        p++;
    }
    str[j] = '\0';
}
void main(){
    char str[100],substr[100];
    int pos;
    printf("Enter the string: ");
    scanf("%s",str);
    printf("Enter the substring: ");
    scanf("%s",substr);
    printf("Enter the position: ");
    scanf("%d",&pos);
    put_string(str,substr,pos);
    printf("%s\n",str);
}