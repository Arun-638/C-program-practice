#include<stdio.h>
#include<ctype.h>
#include<string.h>
char stack[20],out[20];
int top = -1,i=0;
char nexttoken(char e[]){
    return e[i++];
}
int isp(char op){
    switch(op){
        case '~': return 7;
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '^':           return 5;
        case '(':           return 0;
        case '#':           return -1;         
    }
}
int icp(char op){
    switch(op){
        case '~': return 8;
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
    int j=0;
    char x = nexttoken(e);
    while (x != '#')
    {
        if(isalpha(x)){
            out[j++] = x;
        }
        else if(x == ')'){
            while(stack[top] != '('){
                out[j++] = pop();
            }
            pop();
        }
        else{
        while(isp(stack[top]) >= icp(x)){
                out[j++] = pop();
            }
            push(x);
        }
        x = nexttoken(e);
    }
    while(stack[top]!='#'){
        out[j++] = pop();
    }
    out[j] = '\0';
    printf("Postfix Expression: %s\n", out);
}
void infix(char e[]){
    char istack[20][20],itop=-1;
    i = 0;
    char val1[20],val2[20];
    char x = nexttoken(e);
    while(x != '\0'){
        if(isalnum(x)){
            char str[2];
            str[0] = x;
            str[1] = '\0';
            strcpy(istack[++itop],str);
        }
        else{
            char temp[20];
            strcpy(val2,istack[itop--]);
            strcpy(val1,istack[itop--]);
            sprintf(temp,"(%s%c%s)",val1,x,val2);
            strcpy(istack[++itop],temp);
        }
        x = nexttoken(e);
    }
    printf("The infix Expression is %s\n",istack[itop--]);
}
int main() {
    char expr[50];
    printf("Enter infix expression (end with #): ");
    scanf("%s", expr);

    i = 0;
    Postfix(expr);

    printf("\nConverting back to infix...\n");
    infix(out);
    return 0;
}