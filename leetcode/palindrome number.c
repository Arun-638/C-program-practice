#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
bool isPalindrome(int x) {
    if(x<0) return false;
    int digit,s=0,l=x;
    while(x!=0){
        digit = x%10;
        if (s > (INT_MAX - digit) / 10){
        return false;
        }
        s=(s*10)+digit;
        x/=10;
    }
    if(s==l){
        return true;
    }
    else{
        return false;
    }
}
void main(){
    int x;
    printf("Enter the number: ");
    scanf("%d",&x);
    bool result = isPalindrome(x);
    printf("Palindrome of %d is %d\n",x,result);
}
