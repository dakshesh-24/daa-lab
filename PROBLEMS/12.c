#include <stdio.h>

int countNonZeroElements(int arr[][3], int rows, int cols) {
    int count = 0;

    // Traverse the array and count non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] != 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    // Define a 2D array (change size as needed)
    int arr[3][3] = {
        {1, 0, 3},
        {0, 2, 0},
        {4, 0, 5}
    };
    
    int rows = 3, cols = 3; // Number of rows and columns

    // Call the function to count non-zero elements
    int nonZeroCount = countNonZeroElements(arr, rows, cols);

    printf("Total number of non-zero elements: %d\n", nonZeroCount);

    return 0;
}
