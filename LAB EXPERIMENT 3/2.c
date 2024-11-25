#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of scalar multiplications required
void matrixChainMultiplication(int p[], int n) {
    // m[i][j] will store the minimum number of multiplications needed to multiply matrices Ai...Aj
    int m[n][n];

    // Initialize the table
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            m[i][j] = 0;
        }
    }

    // Fill the table for chains of increasing length
    for (int chainLength = 2; chainLength < n; chainLength++) {
        for (int i = 1; i < n - chainLength + 1; i++) {
            int j = i + chainLength - 1;
            m[i][j] = INT_MAX;

            // Find the minimum cost for multiplying Ai...Aj
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    // Print the minimum number of scalar multiplications
    printf("Minimum number of scalar multiplications: %d\n", m[1][n - 1]);
}

// Function to test the algorithm with a given array of dimensions
int main() {
    int arr[] = {1, 2, 3, 4}; // Dimensions: A1 (1x2), A2 (2x3), A3 (3x4)
    int n = sizeof(arr) / sizeof(arr[0]);

    matrixChainMultiplication(arr, n);

    return 0;
}
