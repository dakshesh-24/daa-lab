//find the floor and ceil of a number in a sorted array (recursive solution)

#include <stdio.h>

// Function to find the floor and ceil of a number in a sorted array (recursive)
void findFloorAndCeil(int arr[], int low, int high, int target, int *floor, int *ceil) {
    if (low > high) {
        return;
    }

    int mid = low + (high - low) / 2;

    // Check if the middle element is the target
    if (arr[mid] == target) {
        *floor = target;
        *ceil = target;
        return;
    }

    // If the middle element is less than the target, it could be the floor
    if (arr[mid] < target) {
        *floor = arr[mid];  // Update floor
        findFloorAndCeil(arr, mid + 1, high, target, floor, ceil);  // Search in the right half
    } 
    // If the middle element is greater than the target, it could be the ceil
    else {
        *ceil = arr[mid];   // Update ceil
        findFloorAndCeil(arr, low, mid - 1, target, floor, ceil);  // Search in the left half
    }
}

int main() {
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
