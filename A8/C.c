#include<stdio.h>
#include<stdlib.h>

#define MOD 1000000007

int smallest(int * a,int start,int end){
    int smallest=a[start];
    for(int i=start;i<end;i++){
        smallest=smallest<a[i]?smallest:a[i];
    }
    return smallest;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int sum=0;
    for(int ws=1;ws<=n;ws++){
        for(int i=0;i<=n-ws;i++){
            sum += smallest(a,i,i+ws);
        }
    }
    
    sum%=MOD;
    printf("%d",sum);
    

    return 0;
}
