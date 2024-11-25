find the missing term in a sequence in a logarithmic time

#include <stdio.h>

// Function to find the missing term in the arithmetic progression
int findMissingTerm(int arr[], int n) {
    int low = 0, high = n - 1;

    // Find the common difference (d) using the first two elements
    int d = arr[1] - arr[0];

    // Perform binary search to find the missing term
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the element at mid follows the arithmetic progression
        if (arr[mid] == arr[0] + mid * d) {
            // No missing term in the left half, search in the right half
            low = mid + 1;
        } else {
            // The missing term is in the left half
            high = mid - 1;
        }
    }

    // The missing term is expected to be at index 'low' in the original array
    return arr[0] + low * d;
}

int main() {
    int arr[] = {1, 3, 5, 7, 11, 13}; // Missing term is 9
    int n = sizeof(arr) / sizeof(arr[0]);

    int missingTerm = findMissingTerm(arr, n);

    printf("The missing term is: %d\n", missingTerm);

    return 0;
}
