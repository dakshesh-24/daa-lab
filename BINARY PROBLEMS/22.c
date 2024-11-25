find the peak element in an array

#include <stdio.h>

// Function to find a peak element in the array
int findPeakElement(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is a peak element
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
            return mid;  // mid is a peak element
        }

        // If the left neighbor is greater, move towards the left
        if (mid > 0 && arr[mid - 1] > arr[mid]) {
            high = mid - 1;
        }
        // If the right neighbor is greater, move towards the right
        else {
            low = mid + 1;
        }
    }

    return -1;  // This should never happen if input array has at least one peak
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeakElement(arr, n);
    
    if (peakIndex != -1) {
        printf("Peak element is %d at index %d\n", arr[peakIndex], peakIndex);
    } else {
        printf("No peak element found\n");
    }

    return 0;
}
