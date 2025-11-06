#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int i=0,top = -1;
char stack[50],out[50];
// -------- Expression Tree Node --------
struct tree {
    char data;
    struct tree *lc, *rc;
};

struct tree* newNode(char data) {
    struct tree* t = (struct tree*)malloc(sizeof(struct tree));
    t->data = data;
    t->lc = t->rc = NULL;
    return t;
}

// -------- Stack for operators (char) --------
char nexttoken(char e[]){
    return e[i++];
}
// -------- Stack for tree nodes --------
struct TreeStack {
    struct tree* arr[100];
    int top;
};

void pushTree(struct TreeStack* s, struct tree* node) {
    s->arr[++s->top] = node;
}

struct tree* popTree(struct TreeStack* s) {
    if (s->top != -1) return s->arr[s->top--];
    return NULL;
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
void Postfix(char e[],char out[]){
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
}
// -------- Build expression tree from postfix --------
struct tree* expressiontree(char* postfix) {
    struct TreeStack st;
    st.top = -1;

    for (int i=0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            pushTree(&st, newNode(c));
        } 
        else {
            struct tree* t = newNode(c);
            t->rc = popTree(&st);
            t->lc = popTree(&st);
            pushTree(&st, t);
        }
    }
    return popTree(&st); // root
}

// -------- Iterative prefix (preorder) --------
void printPrefix(struct tree* root) {
    if (!root) {
        return;
    }
    struct TreeStack st;
    st.top = -1;
    pushTree(&st, root);

    while (st.top != -1) {
        struct tree* cur = popTree(&st);
        printf("%c", cur->data);

        if (cur->rc) {
            pushTree(&st, cur->rc);
        }
        if (cur->lc) {
            pushTree(&st, cur->lc);
        }
    }
}

// -------- Iterative postfix (postorder) --------
void printPostfix(struct tree* root) {
    if (!root) {
        return;
    }
    struct TreeStack st1, st2;
    st1.top = st2.top = -1;

    pushTree(&st1, root);
    while (st1.top != -1) {
        struct tree* cur = popTree(&st1);
        pushTree(&st2, cur);

        if (cur->lc) {
            pushTree(&st1, cur->lc);
        }
        if (cur->rc) {
            pushTree(&st1, cur->rc);
        }
    }
    while (st2.top != -1) {
        struct tree* cur = popTree(&st2);
        printf("%c", cur->data);
    }
}


int main() {
    char infix[100], out[100];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    strcat(infix,"#");
    Postfix(infix,out);

    struct tree* root = expressiontree(out);

    printf("\nPrefix  : ");
    printPrefix(root);
    printf("\nPostfix : ");
    printPostfix(root);
    printf("\n");

    return 0;
}
