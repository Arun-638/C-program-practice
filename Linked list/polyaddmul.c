/*
Author: Arun A Raj
Roll no.421
Addition and multiplication of polynomial
*/

#include<stdio.h>
#include<stdlib.h>

//Polynomial Structure
struct Poly
{
    int coeff;
    int degree;
    struct Poly *next;
};

struct Poly *poly1 = NULL,*poly2 = NULL,*poly3 = NULL,*main_poly1 = NULL,*main_poly2 = NULL,*temp = NULL;
int sum;
void add_append(int coeff, int degree){ //Addition Append
    struct Poly *new = (struct Poly*)malloc(sizeof(struct Poly));
    if(new == NULL){
        printf("No space");
        return;
    }
    new->coeff = coeff;
    new->degree = degree;
    new->next = NULL;
    if(poly3 == NULL){
        poly3 = new;
        return;
    }
    temp = poly3;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new;
}
void add(){ //Addition Function
    poly1 = main_poly1;
    poly2 = main_poly2;
    while (poly1!=NULL && poly2!=NULL)
    {
        if(poly1->degree > poly2->degree){
            add_append(poly1->coeff,poly1->degree);
            poly1 = poly1->next;
        }
        else if(poly2->degree > poly1->degree){
            add_append(poly2->coeff,poly2->degree);
            poly2 = poly2->next;
        }
        else{
            sum = poly1->coeff+poly2->coeff;
            add_append(sum,poly1->degree);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while(poly1!=NULL){
        add_append(poly1->coeff,poly1->degree);
        poly1 = poly1->next;
    }
    while(poly2!=NULL){
        add_append(poly2->coeff,poly2->degree);
        poly2 = poly2->next;
    }
}
void multi_append(int coeff,int degree){ //Multiplication append
    temp = poly3;
    while (temp!=NULL)
    {
        if(degree == temp->degree){
            temp->coeff = temp->coeff+coeff;
            return;
        }
        temp = temp->next;
    }
    struct Poly *new = (struct Poly*)malloc(sizeof(struct Poly));
    if(new == NULL){
        printf("No space");
        return;
    }
    new->coeff = coeff;
    new->degree = degree;
    new->next = NULL;
    if(poly3 == NULL){
        poly3 = new;
        return;
    }
    temp = poly3;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new;
}
void multi(){   //Muliplication
    poly1 = main_poly1;
    poly2 = main_poly2;
    while(poly1 != NULL){
        poly2 = main_poly2;
        while(poly2 != NULL){
            int coeff = (poly1->coeff)*(poly2->coeff);
            int degree = (poly1->degree)+(poly2->degree);
            multi_append(coeff,degree);
            poly2 = poly2->next;
        }
        poly1 = poly1->next;
    }
}

struct Poly *insert(){ //Inserting Terms in Polynomial
    int n,degree,coeff;
    struct Poly* head = NULL;
    struct Poly* temp = NULL;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Coefficient and Degree: ");
        scanf("%d %d",&coeff,&degree);
        if(head == NULL){
            head = (struct Poly*)malloc(sizeof(struct Poly));
            head->coeff = coeff;
            head->degree = degree;
            head->next = NULL;
        }
        else{
            temp = head;
            while(temp->next !=NULL){
                temp = temp->next;
            }
            struct Poly* new = (struct Poly*)malloc(sizeof(struct Poly));
            new->coeff = coeff;
            new->degree = degree;
            new->next = NULL;
            temp->next = new;
        }
    }
    return head;
}

void display(struct Poly *poly){
    temp = poly;
    while(temp != NULL){
        printf("%dx^%d",temp->coeff,temp->degree);
        if(temp->next!=NULL){
            printf("+");
        }
        temp = temp->next;
    }
    printf("\0");
}

void main(){
    int choice;
    main_poly1 = insert();
    display(main_poly1);
    main_poly2 = insert();
    display(main_poly2);
    do
    {
        printf("\n1.sum\n2.Multiplication\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            poly3 = NULL;
            add();
            display(poly3);
            break;
        case 2:
            poly3 = NULL;
            multi();
            display(poly3);
            break;
        }
    } while (choice!=3);
}