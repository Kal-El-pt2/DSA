#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[16] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 16]++;

    for (int i = 1; i < 16; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 16] - 1] = arr[i];
        count[(arr[i] / exp) % 16]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n, int k) {
    for (int exp = 1; exp < (1 << (4 * k)); exp *= 16)
        countingSort(arr, n, exp);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        char hex[101];
        scanf("%s", hex);
        arr[i] = (int)strtol(hex, NULL, 16);
    }

    radixSort(arr, n, k);

    for (int i = 0; i < n; i++)
        printf("%X ", arr[i]);

    return 0;
}
