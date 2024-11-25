#include <stdio.h>

void multiplyMatrices(int *mat1, int *mat2, int *result, int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            *(result + i * c2 + j) = 0; // Initialize result cell
            for (int k = 0; k < c1; k++) {
                *(result + i * c2 + j) += *(mat1 + i * c1 + k) * *(mat2 + k * c2 + j);
            }
        }
    }
}

int main() {
    int r1, c1, r2, c2;

    // Input dimensions of the matrices
    printf("Enter rows and columns of the first matrix: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of the second matrix: ");
    scanf("%d %d", &r2, &c2);

    // Check if matrices can be multiplied
    if (c1 != r2) {
        printf("Matrix multiplication is not possible. Columns of the first matrix must match rows of the second matrix.\n");
        return 1;
    }

    int mat1[r1][c1], mat2[r2][c2], result[r1][c2];

    // Input the elements of the first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            printf("mat1[%d][%d]: ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }

    // Input the elements of the second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            printf("mat2[%d][%d]: ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    // Multiply matrices using the function
    multiplyMatrices((int *)mat1, (int *)mat2, (int *)result, r1, c1, c2);

    // Print the resulting matrix
    printf("Product of the matrices:\n");
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
