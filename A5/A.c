#include<stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n], b[m];

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < m; i++){
        scanf("%d", &b[i]);
    }
    int n1=0;
    int n2=0;
    int factor=1;
    for(int i=0;i<n;i++){
        n1+=(factor*a[i]);
        factor*=10;
    }
    factor=1;
    for(int i=0;i<m;i++){
        n2+=(factor*b[i]);
        factor*=10;
    }
    
    int answer=n1+n2;

    while(answer!=0){
        printf("%d ",answer%10);
        answer/=10;
    }
    return 0;
}
