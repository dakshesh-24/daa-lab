count occurrences of a number in a sorted arrwith duplicates


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

// Function to count occurrences of the target
int countOccurrences(int arr[], int n, int target) {
    int firstIndex = findFirstOccurrence(arr, n, target);
    if (firstIndex == -1) {
        return 0;  // Target not found
    }

    int lastIndex = findLastOccurrence(arr, n, target);
    return lastIndex - firstIndex + 1;  // Count = lastIndex - firstIndex + 1
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 2;

    int count = countOccurrences(arr, n, target);
    printf("The number %d occurs %d times in the array.\n", target, count);

    return 0;
}
