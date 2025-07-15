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
        case '#':            return -1;         
    }
}
int icp(char op){
    switch(op){
        case '+': case '-': return 1;
        case '*': case '/': return 3;
        case '^':           return 6;           
        case '(':           return 9;           
        case '#':            return -1;
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
void Postfix(char e[],char out[]){
    int j=0;
    push('#');
    char x = nexttoken(e);
    while (x != '#')
    {
        if(isalnum(x)){
            out[j++] = x;
        }
        else if(x == ')'){
            while(stack[top] != '('){
                out[j++]=pop();
            }
            pop();
        }
        else{
        while(isp(stack[top]) > icp(x)){
                out[j++]=pop();
            }
            push(x);
        }
        x = nexttoken(e);
    }
    while(stack[top]!='#'){
        out[j++]=pop();
    }
    out[j] = '\0';
}
void reverse(char *e){
    int len = strlen(e);
    for (int i = 0; i < len/2; i++)
    {
        if (e[i] == '(')
        {
            e[i] = ')';
        }
        else if(e[i] == ')'){
            e[i] = '(';
        }
        if(e[(len-1)-i]== ')'){
            e[(len-1)-i] = '(';
        }
        else if(e[(len-1)-i]== '('){
            e[(len-1)-i] = ')';
        }
        char temp = e[i];
        e[i] = e[(len-1)-i];
        e[(len-1)-i] = temp;
    }
    
}
int main(){
    char expression[50],out[50];
    printf("Enter the Expression: ");
    scanf("%s",expression);
    reverse(expression);
    //printf("%s",expression);
    strcat(expression,"#");
    Postfix(expression,out);
    reverse(out);
    printf("%s",out);
    return 0;
}