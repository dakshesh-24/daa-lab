#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
typedef struct {
    int start;
    int finish;
} Activity;

// Comparator function to sort activities based on finish time
int compare(const void *a, const void *b) {
    Activity *activity1 = (Activity *)a;
    Activity *activity2 = (Activity *)b;
    return activity1->finish - activity2->finish;
}

// Function to select maximum number of activities
void selectActivities(Activity activities[], int n) {
    // Step 1: Sort the activities by finish time
    qsort(activities, n, sizeof(Activity), compare);

    // Step 2: The first activity is always selected
    int lastSelected = 0;
    printf("Selected activities: (%d, %d)\n", activities[lastSelected].start, activities[lastSelected].finish);

    // Step 3: Select all other activities that start after the last selected activity finishes
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= activities[lastSelected].finish) {
            printf("Selected activities: (%d, %d)\n", activities[i].start, activities[i].finish);
            lastSelected = i;
        }
    }
}

int main() {
    // Define activities with start and finish times
    Activity activities[] = {
        {1, 3}, {2, 5}, {4, 6}, {7, 8}, {5, 7}, {8, 9}
    };
    int n = sizeof(activities) / sizeof(activities[0]);

    // Call function to select activities
    selectActivities(activities, n);

    return 0;
}
