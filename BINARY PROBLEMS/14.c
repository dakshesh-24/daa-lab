find the number of rotaions in a circularly sorted array


#include <stdio.h>

int findRotationCount(int arr[], int n) {
    int low = 0, high = n - 1;

    // Binary search to find the minimum element
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if mid is the minimum element
        if (arr[mid] <= arr[(mid + 1) % n] && arr[mid] <= arr[(mid - 1 + n) % n]) {
            return mid;
        } else if (arr[mid] >= arr[low]) {
            // The minimum element is in the right half
            low = mid + 1;
        } else {
            // The minimum element is in the left half
            high = mid - 1;
        }
    }
    return 0;  // If no rotations (array is not rotated)
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int rotations = findRotationCount(arr, n);
    printf("The array is rotated %d times.\n", rotations);

    return 0;
}
