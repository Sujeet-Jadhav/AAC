#include <stdio.h>

// Function to check if the matrix is a magic square
int isMagicSquare(int matrix[][10], int n) {
    // Calculate the sum of the first row
    int sum = 0;
    for (int j = 0; j < n; j++) {
        sum += matrix[0][j];
    }
    printf("Sum:%d",sum);

    // Check the sum of the rows
    for (int i = 1; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }

        // If the sum of any row is not equal to the sum of the first row, it's not a magic square
        if (rowSum != sum) {
            return 0;
        }
    }

    // Check the sum of the columns
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += matrix[i][j];
        }

        // If the sum of any column is not equal to the sum of the first row, it's not a magic square
        if (colSum != sum) {
            return 0;
        }
    }

    // Check the sum of the main diagonal
    int diagSum = 0;
    for (int i = 0; i < n; i++) {
        diagSum += matrix[i][i];
    }

    // If the sum of the main diagonal is not equal to the sum of the first row, it's not a magic square
    if (diagSum != sum) {
        return 0;
    }

    // Check the sum of the secondary diagonal
    int revDiagSum = 0;
    for (int i = 0; i < n; i++) {
        revDiagSum += matrix[i][n - i - 1];
    }

    // If the sum of the secondary diagonal is not equal to the sum of the first row, it's not a magic square
    if (revDiagSum != sum) {
        return 0;
    }

    // If all checks pass, it's a magic square
    return 1;
}

// Example usage
int main() {
    int n;

    // Taking user input for the order of the matrix
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    // Taking matrix elements as input
    int matrix[10][10];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);

    // Checking if the matrix is a magic square
    if (isMagicSquare(matrix, n)) {
        printf("The given matrix is a magic square.\n");
    } else {
        printf("The given matrix is not a magic square.\n");
    }

    return 0;
}

