#include <stdio.h>
#include <string.h>
#include <ctype.h>
int i=0,top = -1;
char stack[50];
char nexttoken(char e[]){
    return e[i++];
}
int isp(char op){
    switch(op){
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '^':           return 5;
        case '(':           return 0;
        case '#':           return -1;
    }
}
int icp(char op){
    switch(op){
        case '+': case '-': return 1;
        case '*': case '/': return 3;
        case '^':           return 6;           
        case '(':           return 9;           
    }
}
char pop(){
    if(top!=-1){
        return stack[top--];
    }
    return '\0';
}
void push(char val){
    top++;
    stack[top] = val;
}
void Postfix(char e[]){
    push('#');
    char x = nexttoken(e);
    while (x != '#')
    {
        if(isalnum(x)){
            printf("%c",x);
        }
        else if(x == ')'){
            while(stack[top] != '('){
                printf("%c",pop());
            }
            pop();
        }
        else{
        while(isp(stack[top]) >= icp(x)){
                printf("%c",pop());
        }
        push(x);
        }
        x = nexttoken(e);
    }
    while(stack[top]!='#'){
        printf("%c",pop());
    }
}
int main(){
    char expression[50];
    printf("Enter the Expression: ");
    scanf("%s",expression);
    strcat(expression,"#");
    Postfix(expression);
    return 0;
}