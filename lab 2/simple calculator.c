#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int i=0,top = -1;
char stack[50],out[50];
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
        if(isalnum(x)){
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
}
int eval(char out[]) {
    int val[50];
    int top = -1;
    char temp[2]; 
    temp[1] = '\0';

    for (int i = 0; out[i] != '\0'; i++) {
        char ch = out[i];

        if (isdigit(ch)) {
            temp[0] = ch;
            val[++top] = atoi(temp);  
        } else {
            int result;

            if (ch == '~') {
                int op = val[top--];
                result = ~op;
            } else {
                int op2 = val[top--];
                int op1 = val[top--];

                switch (ch) {
                    case '+': result = op1 + op2; break;
                    case '-': result = op1 - op2; break;
                    case '*': result = op1 * op2; break;
                    case '/': 
                        if (op2 == 0) {
                            printf("Division by zero error.\n");
                            return 0;
                        }
                        result = op1 / op2; 
                        break;
                    case '^': {
                        result = 1;
                        for (int j = 0; j < op2; j++)
                            result *= op1;
                        break;
                    }
                    default:
                        printf("Unsupported operator: %c\n", ch);
                        return 0;
                }
            }

            val[++top] = result;
        }
    }

    return val[top];
}
int main(){
    char expression[50];
    printf("Enter the Expression: ");
    scanf("%s",expression);
    strcat(expression,"#");
    Postfix(expression);
    printf("Result of the given Infix expression is %d",eval(out));
    return 0;
}