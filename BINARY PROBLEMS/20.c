searching a nearly sorted array in a logarithmic time

#include <stdio.h>

int searchInNearlySortedArray(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the middle element is the target
        if (arr[mid] == target) {
            return mid;
        }
        
        // If the element just before mid is the target
        if (mid - 1 >= low && arr[mid - 1] == target) {
            return mid - 1;
        }
        
        // If the element just after mid is the target
        if (mid + 1 <= high && arr[mid + 1] == target) {
            return mid + 1;
        }

        // Move the search space
        if (arr[mid] > target) {
            high = mid - 2;  // Skip the element just before mid as it is already checked
        } else {
            low = mid + 2;   // Skip the element just after mid as it is already checked
        }
    }

    return -1;  // Target not found
}

int main() {
    int arr[] = {10, 3, 40, 20, 50, 80, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 20;

    int result = searchInNearlySortedArray(arr, n, target);

    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found\n", target);
    }

    return 0;
}

