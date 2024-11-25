find the smallest missing element from a sorted array

#include <stdio.h>

// Function to find the smallest missing element in a sorted array
int findSmallestMissingElement(int arr[], int n) {
    int low = 0, high = n - 1;

    // If the first element is greater than 0, then the smallest missing element is 0
    if (arr[0] > 0) {
        return 0;
    }

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the element at mid is not equal to its index + arr[0], then it's the missing number
        if (arr[mid] != mid + arr[0]) {
            // The missing element is before mid
            if (mid == 0 || arr[mid - 1] == (mid - 1 + arr[0])) {
                return mid + arr[0];
            } else {
                high = mid - 1;
            }
        } else {
            // Element at mid is correct, move to the right half
            low = mid + 1;
        }
    }

    // If no missing element is found, the missing element is the next integer after the last element
    return arr[n - 1] + 1;
}

int main() {
    int arr[] = {0, 1, 2, 3, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    int smallestMissing = findSmallestMissingElement(arr, n);
    printf("The smallest missing element is %d.\n", smallestMissing);

    return 0;
}
