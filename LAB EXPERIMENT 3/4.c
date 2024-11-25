#include <stdio.h>
#include <stdlib.h>

// Structure for an item
typedef struct {
    int weight;
    int value;
    float ratio; // value-to-weight ratio
} Item;

// Comparison function for sorting items by value-to-weight ratio in descending order
int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    return (itemB->ratio > itemA->ratio) - (itemA->ratio > itemB->ratio);
}

void greedyKnapsack(Item items[], int n, int capacity) {
    qsort(items, n, sizeof(Item), compare); // Sort items by ratio
    int totalValue = 0;
    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        }
    }

    printf("Greedy Approach: Total Value = %d, Total Weight = %d\n", totalValue, totalWeight);
}

int main() {
    Item items[] = {
        {2, 3, 3.0/2}, {3, 4, 4.0/3}, {4, 5, 5.0/4}, {5, 8, 8.0/5}, {9, 10, 10.0/9}
    };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 10;
    
    greedyKnapsack(items, n, capacity);
    return 0;
}
