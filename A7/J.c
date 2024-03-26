#include<stdio.h>
#include<stdlib.h>

struct pairs{
    int val;
    int idx;
};

int main(){
    int n,x;
    scanf("%d %d",&n,&x);
    struct pairs a[n];
    int b[n];
    int count=0;
    int j=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i].val);
        a[i].idx=i+1;
        if(a[i].val<x){
            count++;
            b[j]=a[i].idx;
            j++;
        }
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%d ",b[i]);
    }
    return 0;
}