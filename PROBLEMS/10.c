#include <stdio.h>

void rearrangeMaxMin(int arr[], int n) {
    int temp[n]; // Temporary array to store rearranged elements
    int left = 0, right = n - 1; // Two pointers: left and right
    int index = 0;

    // Use two pointers to place max and min elements alternately
    while (left <= right) {
        if (index % 2 == 0) {
            temp[index++] = arr[right--]; // Place the maximum element
        } else {
            temp[index++] = arr[left++]; // Place the minimum element
        }
    }

    // Copy rearranged elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    rearrangeMaxMin(arr, n);

    printf("\nRearranged array in maximum-minimum form:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
