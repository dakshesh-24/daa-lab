#include <stdio.h>

int main() {
    char uppercaseString[] = "HELLO WORLD";
    char lowercaseString[sizeof(uppercaseString)];
    int i;

    // Iterate through each character in the string
    for (i = 0; uppercaseString[i] != '\0'; i++) {
        // Check if the character is uppercase
        if (uppercaseString[i] >= 'A' && uppercaseString[i] <= 'Z') {
            // Convert to lowercase by adding 32
            lowercaseString[i] = uppercaseString[i] + 32;
        } else {
            // Keep the character as is
            lowercaseString[i] = uppercaseString[i];
        }
    }

    // Null-terminate the lowercase string
    lowercaseString[i] = '\0';

    // Print the result
    printf("Lowercase string: %s\n", lowercaseString);

    return 0;
}



#include <stdio.h>

int main() {
    int rows, cols;

    // Input the order of the matrix
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int matrix[rows][cols];
    int rowSum[rows], colSum[cols];

    // Initialize rowSum and colSum to 0
    for (int i = 0; i < rows; i++)
        rowSum[i] = 0;
    for (int j = 0; j < cols; j++)
        colSum[j] = 0;

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate row sums and column sums
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    // Print the matrix
    printf("\nMatrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Print row sums
    printf("\nSum of each row:\n");
    for (int i = 0; i < rows; i++) {
        printf("Row %d: %d\n", i + 1, rowSum[i]);
    }

    // Print column sums
    printf("\nSum of each column:\n");
    for (int j = 0; j < cols; j++) {
        printf("Column %d: %d\n", j + 1, colSum[j]);
    }

    return 0;
}
