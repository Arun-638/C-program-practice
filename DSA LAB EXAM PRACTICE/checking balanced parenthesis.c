#include<stdio.h>
#define MAX 100
typedef struct {
    char stack[MAX];
    int top;
}stack;

int isempty(stack *s){
    if(s->top == -1){
        return 1;
    }
    return 0;
}

int isfull(stack *s){
    if(s->top == (MAX -1)){
        return 1;
    }
    return 0;
}

void push(stack *s,int c){
    if(isfull(s) == 0){
        s->stack[++s->top] = c;

    }
}

char pop(stack *s){
    if(isempty(s) == 0){
        return s->stack[s->top--];
    }
    return '\0';
}

int isbalanced(char str[]){
    stack s;
    s.top = -1;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '('){
            push(&s,'(');
        }
        else if(str[i] == ')'){
            if (isempty(&s) == 1)
            {
                return 0;
            }
            pop(&s);
        }
    }
    return isempty(&s);
}

void test(char str[]){
    printf("String %s is %s\n",str,isbalanced(str) == 1? "Balanced" : "Not Balanced");
}

void main(){
    test("()()");
    test("(((");
}