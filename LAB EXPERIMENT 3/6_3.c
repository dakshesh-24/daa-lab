#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack using Dynamic Programming
int knapsackDP(int weight[], int value[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    // Initialize the dp table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 8};
    int n = sizeof(values) / sizeof(values[0]);
    int capacity = 5;

    printf("Maximum value in 0/1 Knapsack (Dynamic Programming): %d\n", knapsackDP(weights, values, n, capacity));
    return 0;
}
