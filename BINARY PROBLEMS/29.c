find pairs with difference k in an array | constant space solution

#include <stdio.h>
#include <stdlib.h>

// Function to find pairs with difference k in an array using two-pointer approach
void findPairsWithDifferenceK(int arr[], int n, int k) {
    // Sort the array first
    qsort(arr, n, sizeof(int), (int (*)(const void*, const void*))strcmp);

    int i = 0, j = 1;

    while (j < n) {
        int diff = arr[j] - arr[i];
        
        // If the difference is equal to k, print the pair
        if (diff == k) {
            printf("Pair: (%d, %d)\n", arr[i], arr[j]);
            i++;
            j++;
        }
        // If the difference is less than k, move the second pointer forward to increase the difference
        else if (diff < k) {
            j++;
        }
        // If the difference is greater than k, move the first pointer forward to decrease the difference
        else {
            i++;
            if (i == j) {
                j++; // Ensure j is always ahead of i
            }
        }
    }
}

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    findPairsWithDifferenceK(arr, n, k);

    return 0;
}
