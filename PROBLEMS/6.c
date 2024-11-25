#include <stdio.h>

int main() {
    int n, found = 0;
    float searchKey;

    // Input the size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    float arr[n]; // Array to store numbers (real or integer)

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%f", &arr[i]);
    }

    // Input the number to search
    printf("Enter the number to search: ");
    scanf("%f", &searchKey);

    // Perform linear search
    for (int i = 0; i < n; i++) {
        if (arr[i] == searchKey) {
            found = 1;
            printf("Success: %.2f found at position %d (index %d).\n", searchKey, i + 1, i);
            break;
        }
    }

    // If not found
    if (!found) {
        printf("Failure: %.2f not found in the array.\n", searchKey);
    }

    return 0;
}
