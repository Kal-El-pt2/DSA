#include <stdio.h>
#include <stdlib.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

long long max_area_histogram(int heights[], int n) {
    long long max_area = 0;
    int *stack = malloc(sizeof(int) * n);
    int top = -1;

    for (int i = 0; i <= n; i++) {
        while (top >= 0 && (i == n || heights[stack[top]] > heights[i])) {
            int height = heights[stack[top--]];
            long long width = top >= 0 ? i - stack[top] - 1 : i;
            max_area = max(max_area, (long long) height * width);
        }
        stack[++top] = i;
    }

    free(stack);
    return max_area;
}

int main() {
    int n;
    scanf("%d", &n);
    int heights[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &heights[i]);
    }

    long long max_area = max_area_histogram(heights, n);
    printf("%lld\n", max_area);

    return 0;
}