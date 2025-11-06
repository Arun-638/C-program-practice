#include<stdio.h>
int polyadd(int poly1[][2],int n,int poly2[][2],int m,int result[][2]){
    int i = 0, j = 0,k = 0;
    while (i<n && j<m){
        if(poly1[i][0]>poly2[j][0]){ //Comparing Exponents
            result[k][0] = poly1[i][0];
            result[k][1] = poly1[i][1];
            i++;
        }
        else if(poly1[i][0]<poly2[j][0]){ //Comparing Exponents
            result[k][0] = poly2[j][0];
            result[k][1] = poly2[j][1];
            j++;
        }
        else{
            int sum = poly1[i][1]+poly2[j][1];
            if(sum != 0){
                result[k][0] = poly1[i][0];
                result[k][1] = sum;
            }
            else{
                k--;
            }
            i++;
            j++;
        }
        k++;
    }
    while(i<n){
        result[k][0] = poly1[i][0];
        result[k][1] = poly1[i][1];
        i++;
        k++;
    }
    while(j<m){
        result[k][0] = poly2[j][0];
        result[k][1] = poly2[j][1];
        j++;
        k++;
    }
    return k; 
}
int insert_term(int poly[][2]){
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the expression: ");
        scanf("%d %d",&poly[i][1],&poly[i][0]);
    }
    return n;
}
void display(int poly[][2],int n){
    for (int i = 0; i < n; i++)
    {
        if(i>0){
            printf(" + ");
        }
        printf("%dx%d",poly[i][1],poly[i][0]);
    }
    printf("\n");
}
void main(){
    int n,m,k,p[10][2],q[10][2],r[20][2];
    n = insert_term(p);
    m = insert_term(q);
    k = polyadd(p,n,q,m,r);
    printf("Poly 1 = ");
    display(p,n);
    printf("Poly 2 = ");
    display(q,m);
    printf("Result = ");
    display(r,k);
}