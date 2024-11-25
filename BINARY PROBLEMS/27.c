division of two numbers using  binary search algorithm

#include <stdio.h>
#include <stdlib.h>

int divide(int dividend, int divisor) {
    // Edge case: Division by zero
    if (divisor == 0) {
        printf("Error: Division by zero.\n");
        return -1; // Return an error code
    }

    // Handle negative numbers: We'll work with absolute values
    long long absDividend = abs((long long)dividend);
    long long absDivisor = abs((long long)divisor);

    // Binary search for the quotient
    long long low = 0, high = absDividend, result = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // Check if mid * absDivisor <= absDividend
        if (mid * absDivisor == absDividend) {
            result = mid;
            break;
        }
        else if (mid * absDivisor < absDividend) {
            result = mid; // mid is the largest integer such that mid * divisor <= dividend
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    // If the result should be negative
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        result = -result;
    }

    return (int)result; // Return the quotient
}

int main() {
    int dividend = 10;
    int divisor = 3;

    int quotient = divide(dividend, divisor);

    printf("The quotient of %d / %d is %d\n", dividend, divisor, quotient);

    return 0;
}
