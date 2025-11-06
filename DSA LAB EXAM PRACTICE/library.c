#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<string.h>
#define MAX 100
struct library{
    char title[25];
    char author[25];
    struct library *lc;
    struct library *rc;
};
struct library *newnode(char title[],char author[]){
    struct library *new = (struct library*) malloc(sizeof(struct library));
    strcpy(new->title,title);
    strcpy(new->author,author);
    new->lc = new->rc = NULL;
    return new;
}
struct library *insert(struct library *root, char *title, char *author) {
    if (root == NULL)
        return newnode(title, author);
    if (strcmp(title, root->title) < 0)
        root->lc = insert(root->lc, title, author);
    else
        root->rc = insert(root->rc, title, author);
    return root;
}
struct library *search_book(struct library *root,char title[]){
    if(root == NULL || strcmp(root->title, title) == 0){
        return root;
    }
    if (strcmp(title, root->title) < 0)
        return search_book(root->lc, title);
    else
        return search_book(root->rc, title);
}
void suggest(struct library *root,char search[]) {
    printf("Titles starting with '%s':\n", search);
    if(root == NULL) return ;
    if(strncmp(root->title,search,2) == 0){
        printf("%s\n",root->title);
        return;
    }
    suggest(root->lc,search);
    suggest(root->rc,search);
}
void main(){
    int n;
    struct library *root = NULL;
    printf("Enter the Number of books: ");
    scanf("%d",&n);
    char title[25];
    char author[25];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the book Title and Author Name: ");
        scanf("%s %s",title,author);
        insert(root,title,author);
    }
}