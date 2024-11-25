#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack using Backtracking
int knapsackBacktracking(int weight[], int value[], int n, int capacity) {
    // Base case: no items or no capacity
    if (n == 0 || capacity == 0)
        return 0;

    // If the weight of the nth item is more than the capacity, it can't be included
    if (weight[n - 1] > capacity)
        return knapsackBacktracking(weight, value, n - 1, capacity);

    // Consider both including or excluding the nth item
    int include = value[n - 1] + knapsackBacktracking(weight, value, n - 1, capacity - weight[n - 1]);
    int exclude = knapsackBacktracking(weight, value, n - 1, capacity);

    return max(include, exclude);
}

int main() {
    int weights[] = {2, 3, 4, 5};
    int values[] = {3, 4, 5, 8};
    int n = sizeof(values) / sizeof(values[0]);
    int capacity = 5;
    
    printf("Maximum value in 0/1 Knapsack (Backtracking): %d\n", knapsackBacktracking(weights, values, n, capacity));
    return 0;
}
