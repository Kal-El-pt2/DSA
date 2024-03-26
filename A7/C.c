#include <stdio.h>
#include <stdlib.h>

struct Map {
    int val;
    int idx;
};

struct Map createMap(int val, int idx) {
    struct Map newMap;
    newMap.val = val;
    newMap.idx = idx;
    return newMap;
}

void CountingSort(int n, struct Map* arr) {
    int maxVal = arr[0].val;
    
    // Find the maximum value in the array
    for (int i = 1; i < n; i++) {
        if (arr[i].val > maxVal) {
            maxVal = arr[i].val;
        }
    }

    int* frequency = (int*)malloc((maxVal + 1) * sizeof(int));
    
    // Initialize the frequency array to 0
    for (int i = 0; i <= maxVal; i++) {
        frequency[i] = 0;
    }

    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        frequency[arr[i].val]++;
    }

    // Calculate the cumulative sum in the frequency array
    for (int i = 1; i <= maxVal; i++) {
        frequency[i] += frequency[i - 1];
    }

    // Create a temporary array to store the sorted result
    struct Map* sortedArr = (struct Map*)malloc(n * sizeof(struct Map));

    // Build the sorted array
    for (int i = n - 1; i >= 0; i--) {
        sortedArr[--frequency[arr[i].val]] = arr[i];
    }

    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", sortedArr[i].val);
    }
    printf("\n");

    // Print the indices of the corresponding elements
    for (int i = 0; i < n; i++) {
        printf("%d ", sortedArr[i].idx);
    }

    free(frequency);
    free(sortedArr);
}

int main() {
    int n;
    scanf("%d", &n);

    struct Map arr[n];
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Map temp = createMap(val, i + 1);
        arr[i] = temp;
    }

    CountingSort(n, arr);
    printf("\n");

    return 0;
}
