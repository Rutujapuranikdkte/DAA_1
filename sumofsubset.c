#include <stdio.h>

void generateSubsets(int arr[], int n, int index, int subset[], int subsetSize) {
    
    if (index == n) {
        printf("[");
        int i;
        for (i = 0; i < subsetSize; i++) {
            printf("%d", subset[i]);
            if (i < subsetSize - 1)
                printf(", ");
        }
        printf("]\n");
        return;
    }

    // Include the current element
    subset[subsetSize] = arr[index];
    generateSubsets(arr, n, index + 1, subset, subsetSize + 1);

    // Exclude the current element
    generateSubsets(arr, n, index + 1, subset, subsetSize);
}

int main() {
    int arr[] = {1, 2, 3};
    int n = 3;

    int subset[n]; // To store current subset

    printf("All possible subsets:\n");
    generateSubsets(arr, n, 0, subset, 0);

    return 0;
}
