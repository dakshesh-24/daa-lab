#include <stdio.h>

void printDistinctElements(int arr[], int n) {
    int count;
    
    // Traverse the array
    for (int i = 0; i < n; i++) {
        count = 0;
        
        // Check if arr[i] is already checked
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
        
        // If not repeated, print the element
        if (count == 0) {
            printf("%d ", arr[i]);
        }
    }
}

int main() {
    int arr[] = {12, 10, 9, 45, 2, 10, 10, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Distinct elements in the array are:\n");
    printDistinctElements(arr, n);

    return 0;
}
