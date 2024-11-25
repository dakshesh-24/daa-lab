find the number of 1 s in a sorted binary array

#include <stdio.h>

// Function to find the first occurrence of 1 in the sorted binary array
int findFirstOne(int arr[], int n) {
    int low = 0, high = n - 1;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == 1) {
            result = mid;  // Found a 1, move left to find the first 1
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

// Function to count the number of 1's in the sorted binary array
int countOnes(int arr[], int n) {
    int firstOneIndex = findFirstOne(arr, n);

    if (firstOneIndex == -1) {
        return 0;  // No 1's in the array
    }

    // The number of 1's is the total length minus the index of the first 1
    return n - firstOneIndex;
}

int main() {
    int arr[] = {0, 0, 1, 1, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countOnes(arr, n);

    printf("The number of 1's in the array is: %d\n", result);

    return 0;
}
