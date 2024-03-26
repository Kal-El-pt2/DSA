#include<stdio.h>
#include<stdlib.h>

int check(int *a, int start, int end, int k) {
    int result = 1;
    for(int i = start; i < end; i++) {
        for(int j = i; j < end; j++) {
            if(a[j] - a[i] > k || a[i] - a[j] > k) {
                result = 0;
            }
        }
    }
    return result;
}

void subarr(int *a, int n, int k, int x, int *count) {
    for(int i = 0; i < n - x; i++) {
        if(check(a, i, i + x, k) == 1) {
            (*count)++;
        }
    }
}

int main() { 
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    int count = n;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < n; i++) {
        subarr(a, n, k, i, &count); // Pass count by reference
    }
    printf("%d", count-1);
    return 0;
}
