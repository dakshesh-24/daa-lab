#include <stdio.h>

void moveZeroesToEnd(int arr[], int n) {
    int index = 0; // Index to place the next non-zero element

    // Traverse the array and place non-zero elements in their correct position
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            arr[index++] = arr[i];
        }
    }

    // Fill the remaining positions with zeroes
    while (index < n) {
        arr[index++] = 0;
    }
}

int main() {
    int arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    moveZeroesToEnd(arr, n);

    printf("\nArray after moving zeroes to the end:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
