find the first or last occurrence of a given number in a sorted array



#include <stdio.h>

// Function to find the first occurrence of the target
int findFirstOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int firstIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            firstIndex = mid;
            high = mid - 1;  // Search in the left half for the first occurrence
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return firstIndex;
}

// Function to find the last occurrence of the target
int findLastOccurrence(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int lastIndex = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            lastIndex = mid;
            low = mid + 1;  // Search in the right half for the last occurrence
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return lastIndex;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int firstIndex = findFirstOccurrence(arr, n, target);
    int lastIndex = findLastOccurrence(arr, n, target);

    if (firstIndex != -1) {
        printf("First occurrence of %d is at index %d\n", target, firstIndex);
    } else {
        printf("%d not found in the array\n", target);
    }

    if (lastIndex != -1) {
        printf("Last occurrence of %d is at index %d\n", target, lastIndex);
    } else {
        printf("%d not found in the array\n", target);
    }

    return 0;
}
