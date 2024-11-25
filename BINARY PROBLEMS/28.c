find the odd occurring element in an array in logarithmic time

#include <stdio.h>

// Function to find the odd occurring element in a sorted array using binary search
int findOddOccurringElement(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If mid is even, check the next element
        if (mid % 2 == 0) {
            if (arr[mid] == arr[mid + 1]) {
                low = mid + 2; // Odd element is in the right half
            } else {
                high = mid - 1; // Odd element is in the left half
            }
        }
        // If mid is odd, check the previous element
        else {
            if (arr[mid] == arr[mid - 1]) {
                low = mid + 1; // Odd element is in the right half
            } else {
                high = mid - 1; // Odd element is in the left half
            }
        }
    }

    // The element at index 'low' is the odd occurring element
    return arr[low];
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = findOddOccurringElement(arr, n);

    printf("The odd occurring element is: %d\n", result);

    return 0;
}
