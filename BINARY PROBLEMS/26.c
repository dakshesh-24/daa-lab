fint the square root of a number using a binary search 

#include <stdio.h>

// Function to find the integer square root of a number using binary search
int integerSqrt(int n) {
    if (n < 0) {
        printf("Negative numbers don't have real square roots.\n");
        return -1; // Error for negative numbers
    }

    int low = 0, high = n;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        // Check if mid is the square root
        if (mid * mid == n) {
            return mid;
        }

        // If mid*mid is less than n, search in the right half
        if (mid * mid < n) {
            result = mid; // Mid is the closest integer less than or equal to sqrt(n)
            low = mid + 1;
        }
        // If mid*mid is greater than n, search in the left half
        else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int n = 25;
    int result = integerSqrt(n);

    if (result != -1) {
        printf("The integer square root of %d is %d\n", n, result);
    }

    return 0;
}
