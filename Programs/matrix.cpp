#include <stdio.h>
int matrix1[5][5], matrix2[5][5], result[5][5];

// Function to take input for a matrix
void inputMatrix(int rows, int cols, int matrix[5][5]) {
    printf("Enter the elements of the matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element at position [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int rows, int cols, int matrix[5][5]) {
    printf("Matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication
void multiplyMatrices(int row1, int col1, int matrix1[5][5],
                       int row2, int col2, int matrix2[5][5],
                       int result[5][5]) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int row1, col1, row2, col2;

    // Get dimensions for the first matrix
    printf("Enter dimensions for the first matrix (rows columns): ");
    scanf("%d %d", &row1, &col1);

    // Get dimensions for the second matrix
    printf("Enter dimensions for the second matrix (rows columns): ");
    scanf("%d %d", &row2, &col2);

    // Check if matrices can be multiplied
    if (col1 != row2) {
        printf("Matrices cannot be multiplied. Inner dimensions must match.\n");
        return 1; // Return an error code
    }


    // Input elements for the first matrix
    inputMatrix(row1, col1, matrix1);

    // Input elements for the second matrix
    inputMatrix(row2, col2, matrix2);

    // Display the input matrices
    printf("\n");
    displayMatrix(row1, col1, matrix1);
    printf("\n");
    displayMatrix(row2, col2, matrix2);
    printf("\n");

    // Multiply matrices
    multiplyMatrices(row1, col1, matrix1, row2, col2, matrix2, result);

    // Display the result
    displayMatrix(row1, col2, result);

    return 0;
}

