#include <stdio.h>

int main() {
    int arr[] = {2, 4, 6, 8, 10};
    int key = 8;
    int low = 0, high = 4, mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("Found at index %d\n", mid);
            return 0;
        }
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Not found\n");
    return 0;
}

