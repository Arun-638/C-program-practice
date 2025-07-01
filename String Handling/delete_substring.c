#include <stdio.h>
void delete_string(char str[],char str1[],int n, int pos){
    int k=0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if(i>=pos && n!=0){
            n--;
            continue;
        }
        str1[k] = str[i];
        k++;
    }
    str1[k] = '\0';
}
void main(){
    char str[100],str1[100];
    int pos,n;
    printf("Enter the string: ");
    scanf("%s",str);
    printf("Enter the position: ");
    scanf("%d",&pos);
    printf("Enter the number of characters: ");
    scanf("%d",&n);
    delete_string(str,str1,n,pos);
    printf("%s\n",str1);
}