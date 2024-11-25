find k closest elements to a given value in an array

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Comparator function for sorting the array
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find k closest elements to x
void findKClosestElements(int arr[], int n, int x, int k) {
    // Step 1: Sort the array
    qsort(arr, n, sizeof(int), compare);

    // Step 2: Use two-pointer approach to find k closest elements
    int left = 0, right = n - 1;
    int closest[k];  // Array to store the k closest elements

    for (int i = 0; i < k; i++) {
        // Compare the absolute differences between arr[left] and arr[right] with respect to x
        if (abs(arr[left] - x) <= abs(arr[right] - x)) {
            closest[i] = arr[left];
            left++;
        } else {
            closest[i] = arr[right];
            right--;
        }
    }

    // Step 3: Print the k closest elements
    printf("The %d closest elements to %d are: ", k, x);
    for (int i = 0; i < k; i++) {
        printf("%d ", closest[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 5, 9, 8, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int k = 3;

    findKClosestElements(arr, n, x, k);

    return 0;
}
