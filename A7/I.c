#include<stdio.h>
#include<stdlib.h>

int sqr(int n) {
    return n * n;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char s[n];
    int a[n];
    int sum = 0;
    int freq[27] = {0}; 

    for (int i = 0; i < n; i++) {
        scanf(" %c", &s[i]);  
        a[i] = s[i] - 'a' + 1;
        freq[a[i] - 1]++;
        sum += sqr(a[i]);
    }
    int flag=0;
    int check = n;
    for (int x = 0; x < n - k + 1; x++) {
    for (int i = 0; i < 27; i++) {
        if (check == k) {
            flag = 1;
            break;
        }
        if (freq[i] > 1) {
            sum -= sqr(i + 1);
            freq[i]--;
            check--;
            continue;
        }
    }
    if (flag == 1) break;
}

    printf("%d", sum);
    return 0;
}
