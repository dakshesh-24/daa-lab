#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void interchangeSecondBiggestAndSecondSmallest(int arr[], int n) {
    if (n < 4) {
        printf("Array should have at least 4 elements to perform the operation.\n");
        return;
    }

    int *smallest = arr, *secondSmallest = NULL;
    int *biggest = arr, *secondBiggest = NULL;

    // Find second smallest and second biggest elements using pointers
    for (int i = 0; i < n; i++) {
        if (arr[i] < *smallest) {
            secondSmallest = smallest;
            smallest = &arr[i];
        } else if (secondSmallest == NULL || arr[i] < *secondSmallest) {
            secondSmallest = &arr[i];
        }

        if (arr[i] > *biggest) {
            secondBiggest = biggest;
            biggest = &arr[i];
        } else if (secondBiggest == NULL || arr[i] > *secondBiggest) {
            secondBiggest = &arr[i];
        }
    }

    // Swap the second smallest and second biggest
    swap(secondSmallest, secondBiggest);
}

int main() {
    int arr[] = {12, 35, 1, 10, 34, 1, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    interchangeSecondBiggestAndSecondSmallest(arr, n);

    printf("\nArray after interchanging second biggest and second smallest:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
