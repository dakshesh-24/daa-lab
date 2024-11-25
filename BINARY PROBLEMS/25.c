find the frequency of each element in a sorted array containing duplicates

#include <stdio.h>

void printFrequency(int arr[], int n) {
    int i = 0;

    while (i < n) {
        int count = 1;  // Initialize count for the current element
        
        // Count the occurrences of the current element
        while (i + 1 < n && arr[i] == arr[i + 1]) {
            i++;
            count++;
        }
        
        // Print the element and its count
        printf("Element %d occurs %d times\n", arr[i], count);
        
        // Move to the next different element
        i++;
    }
}

int main() {
    int arr[] = {1, 1, 2, 2, 2, 3, 4, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printFrequency(arr, n);

    return 0;
}
