#include <stdio.h>

struct job {
    int id;
    int profit;
    int dead_line;
};

struct job j[50];

int main() {
    int size, i, k, temp_profit, temp_deadline, temp_id;
    int max_deadline, total_profit = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &size);

    for (i = 0; i < size; i++) {
        printf("\nJob %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &j[i].id);
        printf("Profit: ");
        scanf("%d", &j[i].profit);
        printf("Deadline: ");
        scanf("%d", &j[i].dead_line);
    }

    // Sort jobs by profit (descending) - simple bubble sort
    for (i = 0; i < size - 1; i++) {
        for (k = 0; k < size - i - 1; k++) {
            if (j[k].profit < j[k + 1].profit) {
                struct job temp = j[k];
                j[k] = j[k + 1];
                j[k + 1] = temp;
            }
        }
    }

    // Find max deadline
    max_deadline = j[0].dead_line;
    for (i = 1; i < size; i++) {
        if (j[i].dead_line > max_deadline)
            max_deadline = j[i].dead_line;
    }

    // Mark slots as free
    int slot[50] = {0};  // 0 means free, slot[i] = job id

    printf("\nSelected Jobs:\n");
    for (i = 0; i < size; i++) {
        for (k = j[i].dead_line - 1; k >= 0; k--) {
            if (slot[k] == 0) {
                slot[k] = j[i].id;  // assign job ID
                total_profit += j[i].profit;
                printf("Job ID: %d (Profit: %d, Deadline: %d) -> Time Slot %d\n", j[i].id, j[i].profit, j[i].dead_line, k + 1);
                break;
            }
        }
    }

    printf("\nTotal Profit: %d\n", total_profit);
    return 0;
}

