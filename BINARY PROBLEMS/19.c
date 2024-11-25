find floor and ceil of a number in a sorted integer array

#include <stdio.h>

// Function to find the floor of a number
int findFloor(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int floor = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return arr[mid];  // The number itself is the floor
        }
        else if (arr[mid] < x) {
            floor = arr[mid];  // Update floor to the current mid element
            low = mid + 1;     // Search in the right half for possibly a larger floor
        } else {
            high = mid - 1;    // Search in the left half
        }
    }
    return floor;  // Returns the floor value
}

// Function to find the ceil of a number
int findCeil(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ceil = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            return arr[mid];  // The number itself is the ceil
        }
        else if (arr[mid] < x) {
            low = mid + 1;     // Search in the right half
        } else {
            ceil = arr[mid];   // Update ceil to the current mid element
            high = mid - 1;    // Search in the left half for possibly a smaller ceil
        }
    }
    return ceil;  // Returns the ceil value
}

int main() {
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;

    int floor = findFloor(arr, n, x);
    int ceil = findCeil(arr, n, x);

    if (floor != -1)
        printf("Floor of %d is %d\n", x, floor);
    else
        printf("No floor exists for %d\n", x);

    if (ceil != -1)
        printf("Ceil of %d is %d\n", x, ceil);
    else
        printf("No ceil exists for %d\n", x);

    return 0;
}
