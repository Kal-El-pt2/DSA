#include <stdio.h>

long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] > arr[j]) {
            count += mid - i + 1;
            temp[k++] = arr[j++];
        } else {
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int x = left; x <= right; x++) {
        arr[x] = temp[x];
    }

    return count;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long count = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        count += mergeSort(arr, temp, left, mid);
        count += mergeSort(arr, temp, mid + 1, right);

        count += merge(arr, temp, left, mid, right);
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int temp[n];
    long long result = mergeSort(arr, temp, 0, n - 1);

    printf("%lld\n", result);

    return 0;
}
