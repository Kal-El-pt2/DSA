#include <stdio.h>
#include <stdlib.h>

int partition(int *a,int low,int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]>pivot){
            i++;
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    int temp=a[i+1];
    a[i+1]=a[high];
    a[high]=temp;
    return i+1;
}
int select(int * a,int low,int high,int k){
    if(low<=high){
        int idx=partition(a,low,high);
        if(idx==k-1) return a[idx];
        else if(idx > k-1) return select(a,low,idx-1,k);
        else return select(a,idx+1,high,k);
    }
}

int main() {
    int n,k;
    scanf("%d %d", &n,&k);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int result=select(a,0,n-1,k);
    printf("%d",result);
    return 0;
}
