#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-k+1;i++){
        int greatest=a[i];
        for(int j=0;j<k;j++){
            greatest=a[i+j]>greatest?a[i+j]:greatest;
        }
        printf("%d ",greatest);
    }
    return 0;
}
