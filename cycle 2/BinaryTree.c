#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

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
struct CharStack {
    char arr[100];
    int top;
};

void pushChar(struct CharStack* s, char val) {
    s->arr[++s->top] = val;
}

char popChar(struct CharStack* s) {
    if (s->top != -1) return s->arr[s->top--];
    return '\0';
}

char peekChar(struct CharStack* s) {
    if (s->top != -1){
        return s->arr[s->top];
    } 
    return '\0';
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
    Postfix(infix, out);

    struct tree* root = expressiontree(out);

    printf("\nPrefix  : ");
    printPrefix(root);
    printf("\nPostfix : ");
    printPostfix(root);
    printf("\n");

    return 0;
}
