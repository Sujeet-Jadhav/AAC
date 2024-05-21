#include <stdio.h>

void generateMagicSquare(int n) {
    int magicSquare[n][n];

    // Initialize the matrix with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            magicSquare[i][j] = 0;

    // Set initial position for 1
    int i = n / 2;
    int j = n - 1;

    // Fill the magic square
    for (int num = 1; num <= n * n;) {
        if (i == -1 && j == n) {
            j = n - 2;
            i = 0;
        } else {
            // Wrap around row
            if (i < 0)
                i = n - 1;

            // Wrap around column
            if (j == n)
                j = 0;
        }

        if (magicSquare[i][j] != 0) {
            j -= 2;
            i++;
            continue;
        } else {
            magicSquare[i][j] = num++;
        }

        j++;
        i--;
    }

    // Print the magic square
    printf("Magic Square of order %d:\n", n);
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            printf("%3d ", magicSquare[x][y]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    // Read the order of the magic square
    printf("Enter the order of the magic square (odd number): ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Please enter an odd order for a magic square.\n");
        return 1; // Return an error code
    }

    generateMagicSquare(n);

    return 0;
}

