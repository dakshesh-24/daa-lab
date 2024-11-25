#include <stdio.h>

int main() {
    int n, i, j, insertElement;

    // Input the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a1[n + 1]; // Allocate space for the array (extra space for insertion)

    // Input the elements of the array
    printf("Enter the elements of the array:\n");
    for (int k = 0; k < n; k++) {
        printf("Element [%d]: ", k);
        scanf("%d", &a1[k]);
    }

    // Input position and element to insert
    printf("\nEnter the position to insert (0 to %d): ", n);
    scanf("%d", &i);
    printf("Enter the element to insert: ");
    scanf("%d", &insertElement);

    // Insert the element at the ith position
    if (i >= 0 && i <= n) {
        for (int k = n; k > i; k--) {
            a1[k] = a1[k - 1];
        }
        a1[i] = insertElement;
        n++; // Increment size of array
    } else {
        printf("Invalid position for insertion!\n");
        return 1;
    }

    // Input position to delete
    printf("\nEnter the position to delete (0 to %d): ", n - 1);
    scanf("%d", &j);

    // Delete the element at the jth position
    if (j >= 0 && j < n) {
        for (int k = j; k < n - 1; k++) {
            a1[k] = a1[k + 1];
        }
        n--; // Decrement size of array
    } else {
        printf("Invalid position for deletion!\n");
        return 1;
    }

    // Print the final array
    printf("\nFinal array after insertion and deletion:\n");
    for (int k = 0; k < n; k++) {
        printf("%d ", a1[k]);
    }
    printf("\n");

    return 0;
}
