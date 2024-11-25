#include <stdio.h>
#include <stdbool.h>

// Function to check if there is a subset with the given sum
bool isSubsetSum(int set[], int n, int sum) {
    if (sum == 0) return true;  // A sum of 0 can always be achieved by an empty subset
    if (n == 0 && sum != 0) return false; // No items left but sum is not 0

    // If the last element is greater than the sum, we ignore it
    if (set[n-1] > sum)
        return isSubsetSum(set, n-1, sum);

    // Check if sum can be obtained by including or excluding the last element
    return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    
    if (isSubsetSum(set, n, sum))
        printf("Found a subset with given sum\n");
    else
        printf("No subset with given sum\n");

    return 0;
}
