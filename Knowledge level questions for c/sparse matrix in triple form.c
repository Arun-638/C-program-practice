#include<stdio.h>
#define MAX 10
void main(){
    int a[5][5],b[MAX+1][3],t[MAX+1][3],i,j,k,r,c;
    printf("Entwe the order of matrix: ");
    scanf("%d %d",&r,&c);
    printf("Enter the matrix: ");
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    b[0][0]=r;
    b[0][1]=c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if(a[i][j]!=0){
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }
    b[0][2]=k-1;
    t[0][0] = b[0][1]; // new rows = old cols
    t[0][1] = b[0][0]; // new cols = old rows
    t[0][2] = b[0][2]; // number of non-zero elements

    int n = b[0][2];
    int q = 1;

    for (j = 0; j < b[0][1]; j++) {       // for each column
        for (i = 1; i <= n; i++) {        // check all elements
            if (b[i][1] == j) {           // if column matches
                t[q][0] = b[i][1];        // swap row <-> col
                t[q][1] = b[i][0];
                t[q][2] = b[i][2];
                q++;
            }
        }
    }

    // Step 4: Display sparse matrix
    printf("\nSparse Matrix (Triple Form):\n");
    printf("Row\tCol\tVal\n");
    for (i = 0; i <= n; i++)
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);

    // Step 5: Display Transpose
    printf("\nTranspose Matrix (Triple Form):\n");
    printf("Row\tCol\tVal\n");
    for (i = 0; i <= n; i++)
        printf("%d\t%d\t%d\n", t[i][0], t[i][1], t[i][2]);

    return 0;
}