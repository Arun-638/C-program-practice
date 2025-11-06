#include <stdio.h>

#define MAX 100

struct SparseMatrix {
    int row;
    int col;
    int value;
};

void displaySparseMatrix(struct SparseMatrix sparse[], int nonZeroCount) {
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < nonZeroCount; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    int matrix[10][10], sparse[MAX][3];
    int nonZeroCount = 0;

    printf("Enter the elements of the matrix (10x10):\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0) {
                sparse[nonZeroCount][0] = i;
                sparse[nonZeroCount][1] = j;
                sparse[nonZeroCount][2] = matrix[i][j];
                nonZeroCount++;
            }
        }
    }

    displaySparseMatrix(sparse, nonZeroCount);
    return 0;
}