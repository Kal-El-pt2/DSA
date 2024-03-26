#include <stdio.h>
#include <stdlib.h>

struct idxvalMap {
    int val;
    int idx;
};

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    int a[n];
    struct idxvalMap map[n];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        map[i].val = a[i] - x;
        map[i].idx = i;
        if (map[i].val < 0) map[i].val *= -1;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (map[j].val > map[j + 1].val) {
                int t1=map[j].val;
                int t2=map[j].idx;
                map[j].val=map[j+1].val;
                map[j].idx=map[j+1].idx;
                map[j+1].val=t1;
                map[j+1].idx=t2;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(map[i].val==map[i+1].val){
            int left=a[map[i].idx]>a[map[i+1].idx]?a[map[i+1].idx]:a[map[i].idx];
            int leftidx=a[map[i].idx]>a[map[i+1].idx]?map[i+1].idx:map[i].idx;
            int right=a[map[i].idx]<a[map[i+1].idx]?a[map[i+1].idx]:a[map[i].idx];
            int rightidx=a[map[i].idx]<a[map[i+1].idx]?map[i+1].idx:map[i].idx;
            map[i].val=left;
            map[i].idx=leftidx;
            map[i+1].val=right;
            map[i+1].idx=rightidx;
        }
    }
    
    for (int i = 0; i < k; i++) {
        printf("%d ", a[map[i].idx]);
    }

    return 0;
}
