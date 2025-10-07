#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial
struct poly {
    int coeff;
    int exp;
    struct poly *next;
};

// Function to create a polynomial linked list
struct poly* create() {
    struct poly *head = NULL, *temp, *newnode;
    int n, coeff, exp, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter coeff and exp for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);

        newnode = (struct poly*)malloc(sizeof(struct poly));
        newnode->coeff = coeff;
        newnode->exp = exp;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    return head;
}

// Function to display polynomial
void display(struct poly *p) {
    if (p == NULL) {
        printf("0\n");
        return;
    }

    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->exp);
        p = p->next;
        if (p != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to multiply two polynomials
struct poly* multiply(struct poly* p1, struct poly* p2) {
    struct poly *result = NULL, *temp, *newnode;
    int coeff, exp;

    if (p1 == NULL || p2 == NULL) {
        printf("Multiplication is not possible\n");
        return NULL;
    }

    struct poly *t1 = p1;
    while (t1 != NULL) {
        struct poly *t2 = p2;
        while (t2 != NULL) {
            coeff = t1->coeff * t2->coeff;
            exp = t1->exp + t2->exp;
            temp = result;
            int found = 0;
            while (temp != NULL) {
                if (temp->exp == exp) {
                    temp->coeff += coeff;  
                    found = 1;
                    break;
                }
                temp = temp->next;
            }
            if (!found) {
                newnode = (struct poly*)malloc(sizeof(struct poly));
                newnode->coeff = coeff;
                newnode->exp = exp;
                newnode->next = NULL;

                if (result == NULL) {
                    result = newnode;
                } else {
                    temp = result;
                    while (temp->next != NULL){
                        temp = temp->next;
                    }
                    temp->next = newnode;
                }
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }

    return result;
}

// Main function
int main() {
    struct poly *poly1 = NULL, *poly2 = NULL, *product = NULL;

    printf("Enter first polynomial:\n");
    poly1 = create();
    printf("First polynomial: ");
    display(poly1);

    printf("Enter second polynomial:\n");
    poly2 = create();
    printf("Second polynomial: ");
    display(poly2);

    product = multiply(poly1, poly2);
    printf("Product of polynomials: ");
    display(product);

    return 0;
}
