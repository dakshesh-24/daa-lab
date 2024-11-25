#include <stdio.h>
#include <limits.h>

void findLargestThree(int arr[], int n) {
    if (n < 3) {
        printf("Array must have at least three elements.\n");
        return;
    }

    int first = INT_MIN, second = INT_MIN, third = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] < first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] < second) {
            third = arr[i];
        }
    }

    if (third == INT_MIN) {
        printf("The array does not have three distinct elements.\n");
    } else {
        printf("The largest three distinct elements are: %d, %d, %d\n", first, second, third);
    }
}

int main() {
    int arr[] = {10, 4, 3, 50, 23, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    findLargestThree(arr, n);

    return 0;
}
