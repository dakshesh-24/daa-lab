search an element in a circularly sorted array


#include <stdio.h>

int searchInCircularSortedArray(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the mid element is the target
        if (arr[mid] == target) {
            return mid;
        }

        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            // If the target lies in the left half
            if (target >= arr[low] && target < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else {
            // If the target lies in the right half
            if (target > arr[mid] && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;  // Target not found
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    int result = searchInCircularSortedArray(arr, 0, n - 1, target);
    
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
